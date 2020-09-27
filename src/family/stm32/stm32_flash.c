#include "stm32_flash.h"
#include "target.h"

#if defined STM32F4
uint32_t m_flash_mer_bit;
#endif

// must be provided by family
extern void populate_mcu_details(mcu_details_t *details);

void target_family_populate_info() {
  // interrogate the device to see which in the family it is
  target_startup.info.device_id = DBGMCU->IDCODE;

  target_startup.info.flash_size = *((uint32_t *)(FLASHSIZE_BASE));

  mcu_details_t details;
  populate_mcu_details(&details);
  // populate the flash page table
  switch (details.flash_layout) {}
}

uint32_t target_family_erase_sector(uint32_t bank, uint32_t sector) {
  FLASH_EraseInitTypeDef hal_erase_attr;
  int err;
  uint32_t erase_error;

#if defined FLASH_TYPEERASE_PAGES
  hal_erase_attr.TypeErase = FLASH_TYPEERASE_PAGES;
  hal_erase_attr.Banks = FLASH_BANK_1;
  hal_erase_attr.Page = sector;
  hal_erase_attr.NbPages = 1;
#else
  hal_erase_attr.TypeErase = FLASH_TYPEERASE_SECTORS;

#if defined STM32H7
  if (bank) {
    hal_erase_attr.Banks = FLASH_BANK_1;
  } else {
    hal_erase_attr.Banks = FLASH_BANK_2;
  }
  hal_erase_attr.Sector = sector;
#else

#if defined FLASH_BANK_1
  hal_erase_attr.Banks = FLASH_BANK_1;
#endif
  hal_erase_attr.Sector = sector;
#endif

  hal_erase_attr.NbSectors = 1;
  hal_erase_attr.VoltageRange = FLASH_VOLTAGE_RANGE_1;
  if (target_startup.external.voltage_millivolts > 5000) {
    hal_erase_attr.VoltageRange = FLASH_VOLTAGE_RANGE_4;
  } else if (target_startup.external.voltage_millivolts > 2700) {
    hal_erase_attr.VoltageRange = FLASH_VOLTAGE_RANGE_3;
  } else if (target_startup.external.voltage_millivolts > 2100) {
    hal_erase_attr.VoltageRange = FLASH_VOLTAGE_RANGE_2;
  }

#endif

  HAL_FLASH_Unlock();
  err = HAL_FLASHEx_Erase(&hal_erase_attr, &erase_error);
  HAL_FLASH_Lock();

  if (err != HAL_OK) {
    return -1;
  }

  return 0;
}

uint32_t target_family_copy_ram_to_flash(
  uint32_t source_address,
  uint32_t flash_address,
  uint32_t nbyte) {

  uint32_t i;
  int err;

  if (HAL_FLASH_Unlock() != HAL_OK) {
    return -1;
  }

#if defined STM32L4
  const u64 *pbuf = buf;
  u8 empty[8];
  memset(empty, 0xff, 8);

  for (i = 0; i < nbyte; i += 8) {
    if (memcmp(pbuf, empty, 8)) { // don't touch unless it is non 0xFF
      err = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, addr + i, *pbuf);
    } else {
      err = HAL_OK;
    }
    pbuf++;
    if (err != HAL_OK) {
      break;
    }
  }
#elif defined STM32H7
  const uint8_t *pbuf = (const uint8_t *)source_address;
  uint8_t empty[32]; // flash word is 256-bit or 32 bytes
  memset(empty, 0xff, 8);

  for (i = 0; i < nbyte; i += 32) {
    if (memcmp(pbuf + i, empty, 32)) { // don't touch unless it is non
                                       // 0xFF
      err = HAL_FLASH_Program(
        FLASH_TYPEPROGRAM_FLASHWORD,
        flash_address + i,
        (uint32_t)(pbuf + i));
    } else {
      err = HAL_OK;
    }
    if (err != HAL_OK) {
      break;
    }
  }

#else
  const uint32_t *pbuf = (const uint32_t *)source_address;
  ;
  for (i = 0; i < nbyte; i += 4) {
    err = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, flash_address + i, *pbuf++);
    if (err != HAL_OK) {
      break;
    }
  }
#endif

  HAL_FLASH_Lock();

  if (err != HAL_OK) {
    err = -1;
  } else {
    err = 0;
  }
  return err;
}
