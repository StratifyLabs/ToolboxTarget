
#include "target.h"

#define __ASM __asm
#define __BKPT(value) __ASM volatile("bkpt " #value)

target_info_t m_target_info;

static void startup();
static uint32_t erase_sector_group(uint32_t sector_group);
static uint32_t copy_ram_to_flash(uint32_t flash_address, uint32_t nbyte);

// from the linker
extern uint32_t _stack_pointer;
extern uint32_t _text;

uint8_t m_ram_work_area[_TARGET_RAM_WORKAREA_SIZE];

// this will be the first thing to show up in RAM (and the binary image)
target_startup_t target_startup __attribute__((section(".startup"))) = {
  .api_version = TARGET_API_VERSION,
  .start_address = (uint32_t)&_text,
  .startup_function = (uint32_t)startup,
  .stack_pointer = (uint32_t)&_stack_pointer,
  .erase_sector_group_function = (uint32_t)erase_sector_group,
  .copy_ram_to_flash_function = (uint32_t)copy_ram_to_flash,
  .wait_function = (uint32_t)target_wait,
  .ram_work_address = (uint32_t)m_ram_work_area,
  .ram_work_size = _TARGET_RAM_WORKAREA_SIZE};

void target_populate_info(target_info_t *info);

void startup() {
  // interrogate the device to see which in the family it is
  target_family_populate_info();

  // update the buffers according to the info provided by the target family
  target_startup.copy_ram_to_flash_buffer[0].address
    = target_startup.ram_work_address;
  target_startup.copy_ram_to_flash_buffer[0].size
    = target_startup.ram_work_size / 2;
  target_startup.copy_ram_to_flash_buffer[0].ready
    = 0; // Toolbox will mark as ready

  target_startup.copy_ram_to_flash_buffer[1].address
    = target_startup.ram_work_address + target_startup.ram_work_size / 2;
  target_startup.copy_ram_to_flash_buffer[1].size
    = target_startup.ram_work_size / 2;
  target_startup.copy_ram_to_flash_buffer[1].ready
    = 0; // Toolbox will mark as ready
}

// Toolbox will use this as the LR value when returning from statup() and
// copy_ram_to_flash()
void target_wait(void) {
  // execute a software breakpoint to halt the processor
  // Toolbox will take over now that the operation is complete
  __BKPT(0);
}

uint32_t erase_sector_group(uint32_t sector_group) {
  // bottom 16 bits is a mask of sectors to erase
  // top 16 bits is the multiplier
  uint16_t multiplier = (sector_group >> 16) & 0xff;
  uint16_t bank = (sector_group >> 24) & 0xff;

  for (int i = 0; i < 16; i++) {
    if (sector_group & (1 << i)) {
      target_family_erase_sector(bank, i * multiplier);
    }
  }
  return 0;
}

uint32_t copy_ram_to_flash(uint32_t flash_address, uint32_t nbyte) {
  uint32_t bytes_copied = 0;
  uint32_t buffer_index = 0;
  uint32_t page_size;

  for (bytes_copied = 0; bytes_copied < nbyte; bytes_copied++) {
    target_buffer_t *buffer
      = target_startup.copy_ram_to_flash_buffer + (buffer_index & 0x01);

    // wait until the toolbox has the buffer ready for writing to flash
    while (buffer->ready == 0) {
      ;
    }

    // Toolbox has updated the status -- data is ready to write
    page_size = nbyte - bytes_copied;
    if (page_size > buffer->size) {
      page_size = buffer->size;
    }

    uint32_t result = target_family_copy_ram_to_flash(
      flash_address + bytes_copied,
      buffer->address,
      page_size);
    if (result != 0) {
      return result;
    }

    // Tells the toolbox this buffer is ready to reload
    buffer->ready = 0;
    buffer_index++;
  }

  // no errors
  return 0;
}

// don't use memcpy
void *memcpy(void *dest, const void *src, __SIZE_TYPE__ nbyte) {
  uint8_t *cdest = dest;
  const uint8_t *csrc = src;
  for (int i = 0; i < nbyte; i++) {
    *cdest++ = *csrc++;
  }
  return dest;
}

void *memset(void *dest, int value, __SIZE_TYPE__ nbyte) {
  uint8_t *cdest = dest;
  for (int i = 0; i < nbyte; i++) {
    *cdest++ = value;
  }
  return dest;
}

int memcmp(const void *dest, const void *src, int nbyte) {
  const uint8_t *cdest = dest;
  const uint8_t *csrc = src;
  for (int i = 0; i < nbyte; i++) {
    if (*cdest != *csrc) {
      if (*cdest > *csrc) {
        return 1;
      } else {
        return -1;
      }
    }
  }
  return 0;
}
