#ifndef STM32H7xx_H
#define STM32H7xx_H

#include <stdint.h>

#include "../stm32_common.h"

#include "cmsis/core_cm4.h"

typedef struct {
  __IO uint32_t
    IDCODE; /*!< MCU device ID code,               Address offset: 0x00 */
  __IO uint32_t
    CR; /*!< Debug MCU configuration register, Address offset: 0x04 */
  __IO uint32_t
    APB1FZ; /*!< Debug MCU APB1 freeze register,   Address offset: 0x08 */
  __IO uint32_t
    APB2FZ; /*!< Debug MCU APB2 freeze register,   Address offset: 0x0C */
} DBGMCU_TypeDef;

#define DBGMCU_BASE 0xE0042000UL
#define DBGMCU ((DBGMCU_TypeDef *)DBGMCU_BASE)

typedef struct {
  __IO uint32_t
    ACR; /*!< FLASH access control register,   Address offset: 0x00 */
  __IO uint32_t
    KEYR; /*!< FLASH key register,              Address offset: 0x04 */
  __IO uint32_t
    OPTKEYR; /*!< FLASH option key register,       Address offset: 0x08 */
  __IO uint32_t
    SR; /*!< FLASH status register,           Address offset: 0x0C */
  __IO uint32_t
    CR; /*!< FLASH control register,          Address offset: 0x10 */
  __IO uint32_t
    OPTCR; /*!< FLASH option control register ,  Address offset: 0x14 */
  __IO uint32_t
    OPTCR1; /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;

#define PERIPH_BASE                                                            \
  0x40000000UL /*!< Peripheral base address in the alias region */

#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)
#define FLASH_R_BASE (AHB1PERIPH_BASE + 0x3C00UL)
#define FLASH ((FLASH_TypeDef *)FLASH_R_BASE)

#define UID_BASE 0x1FFF7A10UL /*!< Unique device ID register base address */
#define FLASHSIZE_BASE                                                         \
  0x1FFF7A22UL /*!< FLASH Size register base address       */
#define PACKAGE_BASE 0x1FFF7BF0UL

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos (0U)
#define FLASH_ACR_LATENCY_Msk                                                  \
  (0xFUL << FLASH_ACR_LATENCY_Pos) /*!< 0x0000000F */
#define FLASH_ACR_LATENCY FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS 0x00000000U
#define FLASH_ACR_LATENCY_1WS 0x00000001U
#define FLASH_ACR_LATENCY_2WS 0x00000002U
#define FLASH_ACR_LATENCY_3WS 0x00000003U
#define FLASH_ACR_LATENCY_4WS 0x00000004U
#define FLASH_ACR_LATENCY_5WS 0x00000005U
#define FLASH_ACR_LATENCY_6WS 0x00000006U
#define FLASH_ACR_LATENCY_7WS 0x00000007U

#define FLASH_ACR_PRFTEN_Pos (8U)
#define FLASH_ACR_PRFTEN_Msk                                                   \
  (0x1UL << FLASH_ACR_PRFTEN_Pos) /*!< 0x00000100                              \
                                   */
#define FLASH_ACR_PRFTEN FLASH_ACR_PRFTEN_Msk
#define FLASH_ACR_ICEN_Pos (9U)
#define FLASH_ACR_ICEN_Msk (0x1UL << FLASH_ACR_ICEN_Pos) /*!< 0x00000200 */
#define FLASH_ACR_ICEN FLASH_ACR_ICEN_Msk
#define FLASH_ACR_DCEN_Pos (10U)
#define FLASH_ACR_DCEN_Msk (0x1UL << FLASH_ACR_DCEN_Pos) /*!< 0x00000400 */
#define FLASH_ACR_DCEN FLASH_ACR_DCEN_Msk
#define FLASH_ACR_ICRST_Pos (11U)
#define FLASH_ACR_ICRST_Msk (0x1UL << FLASH_ACR_ICRST_Pos) /*!< 0x00000800 */
#define FLASH_ACR_ICRST FLASH_ACR_ICRST_Msk
#define FLASH_ACR_DCRST_Pos (12U)
#define FLASH_ACR_DCRST_Msk (0x1UL << FLASH_ACR_DCRST_Pos) /*!< 0x00001000 */
#define FLASH_ACR_DCRST FLASH_ACR_DCRST_Msk
#define FLASH_ACR_BYTE0_ADDRESS_Pos (10U)
#define FLASH_ACR_BYTE0_ADDRESS_Msk                                            \
  (0x10008FUL << FLASH_ACR_BYTE0_ADDRESS_Pos) /*!< 0x40023C00 */
#define FLASH_ACR_BYTE0_ADDRESS FLASH_ACR_BYTE0_ADDRESS_Msk
#define FLASH_ACR_BYTE2_ADDRESS_Pos (0U)
#define FLASH_ACR_BYTE2_ADDRESS_Msk                                            \
  (0x40023C03UL << FLASH_ACR_BYTE2_ADDRESS_Pos) /*!< 0x40023C03 */
#define FLASH_ACR_BYTE2_ADDRESS FLASH_ACR_BYTE2_ADDRESS_Msk

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_Pos (0U)
#define FLASH_SR_EOP_Msk (0x1UL << FLASH_SR_EOP_Pos) /*!< 0x00000001 */
#define FLASH_SR_EOP FLASH_SR_EOP_Msk
#define FLASH_SR_SOP_Pos (1U)
#define FLASH_SR_SOP_Msk (0x1UL << FLASH_SR_SOP_Pos) /*!< 0x00000002 */
#define FLASH_SR_SOP FLASH_SR_SOP_Msk
#define FLASH_SR_WRPERR_Pos (4U)
#define FLASH_SR_WRPERR_Msk (0x1UL << FLASH_SR_WRPERR_Pos) /*!< 0x00000010 */
#define FLASH_SR_WRPERR FLASH_SR_WRPERR_Msk
#define FLASH_SR_PGAERR_Pos (5U)
#define FLASH_SR_PGAERR_Msk (0x1UL << FLASH_SR_PGAERR_Pos) /*!< 0x00000020 */
#define FLASH_SR_PGAERR FLASH_SR_PGAERR_Msk
#define FLASH_SR_PGPERR_Pos (6U)
#define FLASH_SR_PGPERR_Msk (0x1UL << FLASH_SR_PGPERR_Pos) /*!< 0x00000040 */
#define FLASH_SR_PGPERR FLASH_SR_PGPERR_Msk
#define FLASH_SR_PGSERR_Pos (7U)
#define FLASH_SR_PGSERR_Msk (0x1UL << FLASH_SR_PGSERR_Pos) /*!< 0x00000080 */
#define FLASH_SR_PGSERR FLASH_SR_PGSERR_Msk
#define FLASH_SR_RDERR_Pos (8U)
#define FLASH_SR_RDERR_Msk (0x1UL << FLASH_SR_RDERR_Pos) /*!< 0x00000100 */
#define FLASH_SR_RDERR FLASH_SR_RDERR_Msk
#define FLASH_SR_BSY_Pos (16U)
#define FLASH_SR_BSY_Msk (0x1UL << FLASH_SR_BSY_Pos) /*!< 0x00010000 */
#define FLASH_SR_BSY FLASH_SR_BSY_Msk

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG_Pos (0U)
#define FLASH_CR_PG_Msk (0x1UL << FLASH_CR_PG_Pos) /*!< 0x00000001 */
#define FLASH_CR_PG FLASH_CR_PG_Msk
#define FLASH_CR_SER_Pos (1U)
#define FLASH_CR_SER_Msk (0x1UL << FLASH_CR_SER_Pos) /*!< 0x00000002 */
#define FLASH_CR_SER FLASH_CR_SER_Msk
#define FLASH_CR_MER_Pos (2U)
#define FLASH_CR_MER_Msk (0x1UL << FLASH_CR_MER_Pos) /*!< 0x00000004 */
#define FLASH_CR_MER FLASH_CR_MER_Msk
#define FLASH_CR_SNB_Pos (3U)
#define FLASH_CR_SNB_Msk (0x0FUL << FLASH_CR_SNB_Pos) /*!< 0x00000078 */
#define FLASH_CR_SNB FLASH_CR_SNB_Msk
#define FLASH_CR_SNB_0 (0x01UL << FLASH_CR_SNB_Pos) /*!< 0x00000008 */
#define FLASH_CR_SNB_1 (0x02UL << FLASH_CR_SNB_Pos) /*!< 0x00000010 */
#define FLASH_CR_SNB_2 (0x04UL << FLASH_CR_SNB_Pos) /*!< 0x00000020 */
#define FLASH_CR_SNB_3 (0x08UL << FLASH_CR_SNB_Pos) /*!< 0x00000040 */
#define FLASH_CR_PSIZE_Pos (8U)
#define FLASH_CR_PSIZE_Msk (0x3UL << FLASH_CR_PSIZE_Pos) /*!< 0x00000300 */
#define FLASH_CR_PSIZE FLASH_CR_PSIZE_Msk
#define FLASH_CR_PSIZE_0 (0x1UL << FLASH_CR_PSIZE_Pos) /*!< 0x00000100 */
#define FLASH_CR_PSIZE_1 (0x2UL << FLASH_CR_PSIZE_Pos) /*!< 0x00000200 */
#define FLASH_CR_STRT_Pos (16U)
#define FLASH_CR_STRT_Msk (0x1UL << FLASH_CR_STRT_Pos) /*!< 0x00010000 */
#define FLASH_CR_STRT FLASH_CR_STRT_Msk
#define FLASH_CR_EOPIE_Pos (24U)
#define FLASH_CR_EOPIE_Msk (0x1UL << FLASH_CR_EOPIE_Pos) /*!< 0x01000000 */
#define FLASH_CR_EOPIE FLASH_CR_EOPIE_Msk
#define FLASH_CR_LOCK_Pos (31U)
#define FLASH_CR_LOCK_Msk (0x1UL << FLASH_CR_LOCK_Pos) /*!< 0x80000000 */
#define FLASH_CR_LOCK FLASH_CR_LOCK_Msk

/*******************  Bits definition for FLASH_OPTCR register  ***************/
#define FLASH_OPTCR_OPTLOCK_Pos (0U)
#define FLASH_OPTCR_OPTLOCK_Msk                                                \
  (0x1UL << FLASH_OPTCR_OPTLOCK_Pos) /*!< 0x00000001 */
#define FLASH_OPTCR_OPTLOCK FLASH_OPTCR_OPTLOCK_Msk
#define FLASH_OPTCR_OPTSTRT_Pos (1U)
#define FLASH_OPTCR_OPTSTRT_Msk                                                \
  (0x1UL << FLASH_OPTCR_OPTSTRT_Pos) /*!< 0x00000002 */
#define FLASH_OPTCR_OPTSTRT FLASH_OPTCR_OPTSTRT_Msk

#define FLASH_OPTCR_BOR_LEV_0 0x00000004U
#define FLASH_OPTCR_BOR_LEV_1 0x00000008U
#define FLASH_OPTCR_BOR_LEV_Pos (2U)
#define FLASH_OPTCR_BOR_LEV_Msk                                                \
  (0x3UL << FLASH_OPTCR_BOR_LEV_Pos) /*!< 0x0000000C */
#define FLASH_OPTCR_BOR_LEV FLASH_OPTCR_BOR_LEV_Msk
#define FLASH_OPTCR_WDG_SW_Pos (5U)
#define FLASH_OPTCR_WDG_SW_Msk                                                 \
  (0x1UL << FLASH_OPTCR_WDG_SW_Pos) /*!< 0x00000020 */
#define FLASH_OPTCR_WDG_SW FLASH_OPTCR_WDG_SW_Msk
#define FLASH_OPTCR_nRST_STOP_Pos (6U)
#define FLASH_OPTCR_nRST_STOP_Msk                                              \
  (0x1UL << FLASH_OPTCR_nRST_STOP_Pos) /*!< 0x00000040 */
#define FLASH_OPTCR_nRST_STOP FLASH_OPTCR_nRST_STOP_Msk
#define FLASH_OPTCR_nRST_STDBY_Pos (7U)
#define FLASH_OPTCR_nRST_STDBY_Msk                                             \
  (0x1UL << FLASH_OPTCR_nRST_STDBY_Pos) /*!< 0x00000080 */
#define FLASH_OPTCR_nRST_STDBY FLASH_OPTCR_nRST_STDBY_Msk
#define FLASH_OPTCR_RDP_Pos (8U)
#define FLASH_OPTCR_RDP_Msk (0xFFUL << FLASH_OPTCR_RDP_Pos) /*!< 0x0000FF00 */
#define FLASH_OPTCR_RDP FLASH_OPTCR_RDP_Msk
#define FLASH_OPTCR_RDP_0 (0x01UL << FLASH_OPTCR_RDP_Pos) /*!< 0x00000100 */
#define FLASH_OPTCR_RDP_1 (0x02UL << FLASH_OPTCR_RDP_Pos) /*!< 0x00000200 */
#define FLASH_OPTCR_RDP_2 (0x04UL << FLASH_OPTCR_RDP_Pos) /*!< 0x00000400 */
#define FLASH_OPTCR_RDP_3 (0x08UL << FLASH_OPTCR_RDP_Pos) /*!< 0x00000800 */
#define FLASH_OPTCR_RDP_4 (0x10UL << FLASH_OPTCR_RDP_Pos) /*!< 0x00001000 */
#define FLASH_OPTCR_RDP_5 (0x20UL << FLASH_OPTCR_RDP_Pos) /*!< 0x00002000 */
#define FLASH_OPTCR_RDP_6 (0x40UL << FLASH_OPTCR_RDP_Pos) /*!< 0x00004000 */
#define FLASH_OPTCR_RDP_7 (0x80UL << FLASH_OPTCR_RDP_Pos) /*!< 0x00008000 */
#define FLASH_OPTCR_nWRP_Pos (16U)
#define FLASH_OPTCR_nWRP_Msk                                                   \
  (0x7FFFUL << FLASH_OPTCR_nWRP_Pos) /*!< 0x7FFF0000 */
#define FLASH_OPTCR_nWRP FLASH_OPTCR_nWRP_Msk
#define FLASH_OPTCR_nWRP_0 0x00010000U
#define FLASH_OPTCR_nWRP_1 0x00020000U
#define FLASH_OPTCR_nWRP_2 0x00040000U
#define FLASH_OPTCR_nWRP_3 0x00080000U
#define FLASH_OPTCR_nWRP_4 0x00100000U
#define FLASH_OPTCR_nWRP_5 0x00200000U
#define FLASH_OPTCR_nWRP_6 0x00400000U
#define FLASH_OPTCR_nWRP_7 0x00800000U
#define FLASH_OPTCR_nWRP_8 0x01000000U
#define FLASH_OPTCR_nWRP_9 0x02000000U
#define FLASH_OPTCR_nWRP_10 0x04000000U
#define FLASH_OPTCR_nWRP_11 0x08000000U
#define FLASH_OPTCR_nWRP_12 0x10000000U
#define FLASH_OPTCR_nWRP_13 0x20000000U
#define FLASH_OPTCR_nWRP_14 0x40000000U
#define FLASH_OPTCR_nWRP_15 0x40000000U

/******************  Bits definition for FLASH_OPTCR1 register  ***************/
#define FLASH_OPTCR1_nWRP_Pos (16U)
#define FLASH_OPTCR1_nWRP_Msk                                                  \
  (0xFFFUL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x0FFF0000 */
#define FLASH_OPTCR1_nWRP FLASH_OPTCR1_nWRP_Msk
#define FLASH_OPTCR1_nWRP_0                                                    \
  (0x001UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x00010000 */
#define FLASH_OPTCR1_nWRP_1                                                    \
  (0x002UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x00020000 */
#define FLASH_OPTCR1_nWRP_2                                                    \
  (0x004UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x00040000 */
#define FLASH_OPTCR1_nWRP_3                                                    \
  (0x008UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x00080000 */
#define FLASH_OPTCR1_nWRP_4                                                    \
  (0x010UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x00100000 */
#define FLASH_OPTCR1_nWRP_5                                                    \
  (0x020UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x00200000 */
#define FLASH_OPTCR1_nWRP_6                                                    \
  (0x040UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x00400000 */
#define FLASH_OPTCR1_nWRP_7                                                    \
  (0x080UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x00800000 */
#define FLASH_OPTCR1_nWRP_8                                                    \
  (0x100UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x01000000 */
#define FLASH_OPTCR1_nWRP_9                                                    \
  (0x200UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x02000000 */
#define FLASH_OPTCR1_nWRP_10                                                   \
  (0x400UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x04000000 */
#define FLASH_OPTCR1_nWRP_11                                                   \
  (0x800UL << FLASH_OPTCR1_nWRP_Pos) /*!< 0x08000000 */

#define HAL_FLASH_MODULE_ENABLED 1
#define STM32F413xx

extern uint32_t m_flash_mer_bit;

//#define FLASH_MER_BIT m_flash_mer_bit

#endif
