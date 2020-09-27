
#include "stm32h7xx_hal.h"

#include "target.h"

void populate_mcu_details(mcu_details_t *details) {
  uint16_t mcu_id = target_startup.info.device_id & 0xffff;
  details->name = 0;
  switch (mcu_id) {
  case 0x450:
    details->name = "h750/742/743/753";
    break;
  case 0x480:
    details->name = "h7a3/7b3/7b0";
    break;
  }
}
