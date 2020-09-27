
#include "../stm32_common.h"

#include "target.h"

void populate_mcu_details(mcu_details_t *details) {
  uint16_t mcu_id = target_startup.info.device_id & 0xffff;

  details->name = 0;
  details->flash_layout = 0;
  switch (mcu_id) {
  case 0x463:
    details->name = "f413xx";
    details->flash_layout = FLASH_LAYOUT_16_16_16_16_64_128x11;
    break;
  case 0x423:
    details->name = "f401xb";
    details->flash_layout = FLASH_LAYOUT_16_16_16_16_64_128_128_128;
    break;
  case 0x433:
    details->name = "f401xd";
    details->flash_layout = FLASH_LAYOUT_16_16_16_16_64_128_128_128;
    break;
  }
}
