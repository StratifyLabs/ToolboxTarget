#ifndef STM32_FLASH_H_
#define STM32_FLASH_H_

#if defined STM32H7
#include "h7/stm32h7xx_hal_flash.h"
#include "h7/stm32h7xx_hal_flash_ex.h"
#endif

#if defined STM32F4
#include "f4/stm32f4xx_hal_flash.h"
#include "f4/stm32f4xx_hal_flash_ex.h"
#endif

#endif
