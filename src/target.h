#if !defined TOOLBOXTARGET_TARGET_H
#define TOOLBOXTARGET_TARGET_H

#include <stdint.h>

#define TARGET_API_VERSION 0x00000001

//Toolbox will provide this info to the family loader
typedef struct {
  uint32_t voltage_millivolts; //source voltage in millivolts
} target_external_t;

typedef struct {
  uint32_t address;
  uint32_t size;
  uint32_t ready;
} target_buffer_t;

//dynamic information that is populated by the startup function
typedef struct {
  uint32_t device_id;
  uint8_t device_name[32]; //name of the device
  uint32_t unique_id[8];
  uint32_t flash_size;            // total flash size in KB
  uint32_t flash_page_table[256]; //flash page sizes in KB
  uint32_t ram_work_address;
  uint32_t ram_work_size;
} target_info_t;

//the following is auto populated by target.c
typedef struct {
  uint32_t api_version;
  uint32_t start_address;
  uint32_t startup_function;
  uint32_t stack_pointer;
  uint32_t erase_sector_group_function;
  uint32_t copy_ram_to_flash_function;
  uint32_t wait_function;
  target_info_t info; //populated by the family
  target_buffer_t copy_ram_to_flash_buffer[2];
  target_external_t external;
} target_startup_t;

void target_wait();

extern target_startup_t target_startup;


//provided by target family
extern void target_family_populate_info();
extern uint32_t target_family_erase_sector(uint32_t bank, uint32_t sector);
extern uint32_t target_family_copy_ram_to_flash(uint32_t source_address, uint32_t flash_address, uint32_t nbyte);

extern void *memcpy(void *dest, const void *src, __SIZE_TYPE__ nbyte);
extern void *memset(void *dest, int value, __SIZE_TYPE__ nbyte);
extern int memcmp(const void *dest, const void *src, int nbyte);
#endif // TOOLBOXTARGET_TARGET_H
