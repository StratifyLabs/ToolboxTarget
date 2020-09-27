#ifndef STM32_COMMON_H
#define STM32_COMMON_H

#include <stdint.h>

#if !defined __IO
#define __IO volatile
#endif
typedef int IRQn_Type;
#define __NVIC_PRIO_BITS 4

#define assert_param(x)
#define __HAL_LOCK(x)
#define __HAL_UNLOCK(x)
#define HAL_GetTick() 0
#define UNUSED(x) (void)x

#define __weak
#define HAL_MAX_DELAY 100

/** @addtogroup Exported_types
 * @{
 */
typedef enum { RESET = 0, SET = !RESET } FlagStatus, ITStatus;

typedef enum { DISABLE = 0, ENABLE = !DISABLE } FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum { SUCCESS = 0, ERROR = !SUCCESS } ErrorStatus;

/**
 * @}
 */

/** @addtogroup Exported_macros
 * @{
 */
#define SET_BIT(REG, BIT) ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT) ((REG) & (BIT))

#define CLEAR_REG(REG) ((REG) = (0x0))

#define WRITE_REG(REG, VAL) ((REG) = (VAL))

#define READ_REG(REG) ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)                                    \
  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL) (__CLZ(__RBIT(VAL)))

typedef enum {
  HAL_OK = 0x00,
  HAL_ERROR = 0x01,
  HAL_BUSY = 0x02,
  HAL_TIMEOUT = 0x03
} HAL_StatusTypeDef;

/**
 * @brief  HAL Lock structures definition
 */
typedef enum { HAL_UNLOCKED = 0x00, HAL_LOCKED = 0x01 } HAL_LockTypeDef;

#if 0
static const u16 stm32_flash_layout[]
  = {32, 32, 32, 32, 128, 256, 256, 256, 256, 256, 256, 256};

const u16 stm32_flash_layout[]
  = {16, 16, 16, 16, 64, 128, 128, 128, 128, 128, 128, 128,
     16, 16, 16, 16, 64, 128, 128, 128, 128, 128, 128, 128};

const u16 stm32_flash_layout[]
  = {16, 16, 16, 16, 64, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
#endif

enum {
  FLASH_LAYOUT_NONE = 0,
  FLASH_LAYOUT_2K_PAGES = 2,
  FLASH_LAYOUT_32_32_32_32_128_256_256_256 = 32 * 4 + 128 + 256 * 3 + 3,
  FLASH_LAYOUT_16_16_16_16_64_128_128_128 = 16 * 4 + 64 + 128 * 3 + 4,
  FLASH_LAYOUT_16_16_16_16_64_128x11 = 16 * 4 + 64 + 128 * 11 + 5,
  FLASH_LAYOUT_128K_PAGES = 128 + 6
};

#define FLASH_LAYOUT_KB(x) (x & ~0x0f)

typedef struct {
  const char *name;
  uint32_t flash_layout;
} mcu_details_t;

#endif // STM32_COMMON_H
