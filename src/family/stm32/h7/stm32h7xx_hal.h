#ifndef STM32H7xx_H
#define STM32H7xx_H

#include <stdint.h>

#if !defined __IO
#define __IO volatile
#endif

#define __NVIC_PRIO_BITS 4
typedef int IRQn_Type;

#include "cmsis/core_cm7.h"

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

typedef struct {
  __IO uint32_t
    IDCODE; /*!< MCU device ID code,                     Address offset: 0x00 */
  __IO uint32_t
    CR; /*!< Debug MCU configuration register,       Address offset: 0x04 */
  uint32_t RESERVED4[11]; /*!< Reserved,                             Address
                             offset: 0x08 */
  __IO uint32_t
    APB3FZ1; /*!< Debug MCU APB3FZ1 freeze register,    Address offset: 0x34 */
  uint32_t RESERVED5; /*!< Reserved,                             Address offset:
                         0x38 */
  __IO uint32_t
    APB1LFZ1; /*!< Debug MCU APB1LFZ1 freeze register,   Address offset: 0x3C */
  uint32_t RESERVED6; /*!< Reserved,                             Address offset:
                         0x40 */
  __IO uint32_t
    APB1HFZ1; /*!< Debug MCU APB1LFZ1 freeze register,   Address offset: 0x44 */
  uint32_t RESERVED7; /*!< Reserved,                             Address offset:
                         0x48 */
  __IO uint32_t
    APB2FZ1; /*!< Debug MCU APB2FZ1 freeze register,    Address offset: 0x4C */
  uint32_t RESERVED8; /*!< Reserved,                             Address offset:
                         0x50 */
  __IO uint32_t
    APB4FZ1; /*!< Debug MCU APB4FZ1 freeze register,    Address offset: 0x54 */
} DBGMCU_TypeDef;

#define DBGMCU_BASE (0x5C001000UL)
#define DBGMCU ((DBGMCU_TypeDef *)DBGMCU_BASE)

typedef struct {
  __IO uint32_t ACR;             /*!< FLASH access control register,                            Address offset: 0x00  */
  __IO uint32_t KEYR1;           /*!< Flash Key Register for bank1,                             Address offset: 0x04  */
  __IO uint32_t OPTKEYR;         /*!< Flash Option Key Register,                                Address offset: 0x08  */
  __IO uint32_t CR1;             /*!< Flash Control Register for bank1,                         Address offset: 0x0C  */
  __IO uint32_t SR1;             /*!< Flash Status Register for bank1,                          Address offset: 0x10  */
  __IO uint32_t CCR1;            /*!< Flash Control Register for bank1,                         Address offset: 0x14  */
  __IO uint32_t OPTCR;           /*!< Flash Option Control Register,                            Address offset: 0x18  */
  __IO uint32_t OPTSR_CUR;       /*!< Flash Option Status Current Register,                     Address offset: 0x1C  */
  __IO uint32_t OPTSR_PRG;       /*!< Flash Option Status to Program Register,                  Address offset: 0x20  */
  __IO uint32_t OPTCCR;          /*!< Flash Option Clear Control Register,                      Address offset: 0x24  */
  __IO uint32_t PRAR_CUR1;       /*!< Flash Current Protection Address Register for bank1,      Address offset: 0x28  */
  __IO uint32_t PRAR_PRG1;       /*!< Flash Protection Address to Program Register for bank1,   Address offset: 0x2C  */
  __IO uint32_t SCAR_CUR1;       /*!< Flash Current Secure Address Register for bank1,          Address offset: 0x30  */
  __IO uint32_t SCAR_PRG1;       /*!< Flash Secure Address to Program Register for bank1,       Address offset: 0x34  */
  __IO uint32_t WPSN_CUR1;       /*!< Flash Current Write Protection Register on bank1,         Address offset: 0x38  */
  __IO uint32_t WPSN_PRG1;       /*!< Flash Write Protection to Program Register on bank1,      Address offset: 0x3C  */
  __IO uint32_t BOOT_CUR;        /*!< Flash Current Boot Address for Pelican Core Register,     Address offset: 0x40  */
  __IO uint32_t BOOT_PRG;        /*!< Flash Boot Address to Program for Pelican Core Register,  Address offset: 0x44  */
  uint32_t      RESERVED0[2];    /*!< Reserved, 0x48 to 0x4C                                                          */
  __IO uint32_t CRCCR1;          /*!< Flash CRC Control register For Bank1 Register ,           Address offset: 0x50  */
  __IO uint32_t CRCSADD1;        /*!< Flash CRC Start Address Register for Bank1 ,              Address offset: 0x54  */
  __IO uint32_t CRCEADD1;        /*!< Flash CRC End Address Register for Bank1 ,                Address offset: 0x58  */
  __IO uint32_t CRCDATA;         /*!< Flash CRC Data Register for Bank1 ,                       Address offset: 0x5C  */
  __IO uint32_t ECC_FA1;         /*!< Flash ECC Fail Address For Bank1 Register ,               Address offset: 0x60  */
  uint32_t      RESERVED1[40];   /*!< Reserved, 0x64 to 0x100                                                         */
  __IO uint32_t KEYR2;           /*!< Flash Key Register for bank2,                             Address offset: 0x104 */
  uint32_t      RESERVED2;       /*!< Reserved, 0x108                                                                 */
  __IO uint32_t CR2;             /*!< Flash Control Register for bank2,                         Address offset: 0x10C */
  __IO uint32_t SR2;             /*!< Flash Status Register for bank2,                          Address offset: 0x110 */
  __IO uint32_t CCR2;            /*!< Flash Status Register for bank2,                          Address offset: 0x114 */
  uint32_t      RESERVED3[4];    /*!< Reserved, 0x118 to 0x124                                                        */
  __IO uint32_t PRAR_CUR2;       /*!< Flash Current Protection Address Register for bank2,      Address offset: 0x128 */
  __IO uint32_t PRAR_PRG2;       /*!< Flash Protection Address to Program Register for bank2,   Address offset: 0x12C */
  __IO uint32_t SCAR_CUR2;       /*!< Flash Current Secure Address Register for bank2,          Address offset: 0x130 */
  __IO uint32_t SCAR_PRG2;       /*!< Flash Secure Address Register for bank2,                  Address offset: 0x134 */
  __IO uint32_t WPSN_CUR2;       /*!< Flash Current Write Protection Register on bank2,         Address offset: 0x138 */
  __IO uint32_t WPSN_PRG2;       /*!< Flash Write Protection to Program Register on bank2,      Address offset: 0x13C */
  uint32_t      RESERVED4[4];    /*!< Reserved, 0x140 to 0x14C                                                        */
  __IO uint32_t CRCCR2;          /*!< Flash CRC Control register For Bank2 Register ,           Address offset: 0x150 */
  __IO uint32_t CRCSADD2;        /*!< Flash CRC Start Address Register for Bank2 ,              Address offset: 0x154 */
  __IO uint32_t CRCEADD2;        /*!< Flash CRC End Address Register for Bank2 ,                Address offset: 0x158 */
  __IO uint32_t CRCDATA2;        /*!< Flash CRC Data Register for Bank2 ,                       Address offset: 0x15C */
  __IO uint32_t ECC_FA2;         /*!< Flash ECC Fail Address For Bank2 Register ,               Address offset: 0x160 */
} FLASH_TypeDef;

#define PERIPH_BASE                                                            \
  (0x40000000UL) /*!< Base address of : AHB/APB Peripherals                    \
                  */
#define D1_AHB1PERIPH_BASE       (PERIPH_BASE + 0x12000000UL)
#define FLASH_R_BASE          (D1_AHB1PERIPH_BASE + 0x2000UL)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)

#define FLASH_BANK1_BASE                                                       \
  (0x08000000UL) /*!< Base address of : (up to 128 KB) Flash Bank1 accessible  \
                    over AXI                        */
#define FLASH_BANK2_BASE                                                       \
  (0x08100000UL) /*!< For legacy only , Flash bank 2 not available on          \
                    STM32H750xx value line          */
#define FLASH_END                                                              \
  (0x0801FFFFUL) /*!< FLASH end address */

/* Legacy define */
#define FLASH_BASE FLASH_BANK1_BASE

/*!< Device electronic signature memory map */
#define UID_BASE (0x1FF1E800UL) /*!< Unique device ID register base address */
#define FLASHSIZE_BASE (0x1FF1E880UL) /*!< FLASH Size register base address */

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*
 * @brief FLASH Global Defines
 */
#define FLASH_SECTOR_TOTAL 1U          /* 1 sector */
#define FLASH_SECTOR_SIZE 0x00020000UL /* 128 KB */
#define FLASH_SIZE FLASH_SECTOR_SIZE   /* 128 KB */
#define FLASH_BANK_SIZE FLASH_SIZE     /* 128 KB */
#define FLASH_LATENCY_DEFAULT                                                  \
  FLASH_ACR_LATENCY_7WS                    /* FLASH Seven Latency cycles */
#define FLASH_NB_32BITWORD_IN_FLASHWORD 8U /* 256 bits */

/*******************  Bits definition for FLASH_ACR register
 * **********************/
#define FLASH_ACR_LATENCY_Pos (0U)
#define FLASH_ACR_LATENCY_Msk                                                  \
  (0xFUL << FLASH_ACR_LATENCY_Pos)              /*!< 0x0000000F */
#define FLASH_ACR_LATENCY FLASH_ACR_LATENCY_Msk /*!< Read Latency */
#define FLASH_ACR_LATENCY_0WS (0x00000000UL)
#define FLASH_ACR_LATENCY_1WS (0x00000001UL)
#define FLASH_ACR_LATENCY_2WS (0x00000002UL)
#define FLASH_ACR_LATENCY_3WS (0x00000003UL)
#define FLASH_ACR_LATENCY_4WS (0x00000004UL)
#define FLASH_ACR_LATENCY_5WS (0x00000005UL)
#define FLASH_ACR_LATENCY_6WS (0x00000006UL)
#define FLASH_ACR_LATENCY_7WS (0x00000007UL)
#define FLASH_ACR_LATENCY_8WS (0x00000008UL)
#define FLASH_ACR_LATENCY_9WS (0x00000009UL)
#define FLASH_ACR_LATENCY_10WS (0x0000000AUL)
#define FLASH_ACR_LATENCY_11WS (0x0000000BUL)
#define FLASH_ACR_LATENCY_12WS (0x0000000CUL)
#define FLASH_ACR_LATENCY_13WS (0x0000000DUL)
#define FLASH_ACR_LATENCY_14WS (0x0000000EUL)
#define FLASH_ACR_LATENCY_15WS (0x0000000FUL)
#define FLASH_ACR_WRHIGHFREQ_Pos (4U)
#define FLASH_ACR_WRHIGHFREQ_Msk                                               \
  (0x3UL << FLASH_ACR_WRHIGHFREQ_Pos) /*!< 0x00000030 */
#define FLASH_ACR_WRHIGHFREQ                                                   \
  FLASH_ACR_WRHIGHFREQ_Msk /*!< Flash signal delay                             \
                            */
#define FLASH_ACR_WRHIGHFREQ_0                                                 \
  (0x1UL << FLASH_ACR_WRHIGHFREQ_Pos) /*!< 0x00000010 */
#define FLASH_ACR_WRHIGHFREQ_1                                                 \
  (0x2UL << FLASH_ACR_WRHIGHFREQ_Pos) /*!< 0x00000020 */

/*******************  Bits definition for FLASH_CR register
 * ***********************/
#define FLASH_CR_LOCK_Pos (0U)
#define FLASH_CR_LOCK_Msk (0x1UL << FLASH_CR_LOCK_Pos) /*!< 0x00000001 */
#define FLASH_CR_LOCK FLASH_CR_LOCK_Msk /*!< Configuration lock bit */
#define FLASH_CR_PG_Pos (1U)
#define FLASH_CR_PG_Msk (0x1UL << FLASH_CR_PG_Pos) /*!< 0x00000002 */
#define FLASH_CR_PG FLASH_CR_PG_Msk /*!< Internal buffer control bit */
#define FLASH_CR_SER_Pos (2U)
#define FLASH_CR_SER_Msk (0x1UL << FLASH_CR_SER_Pos) /*!< 0x00000004 */
#define FLASH_CR_SER FLASH_CR_SER_Msk /*!< Sector erase request */
#define FLASH_CR_BER_Pos (3U)
#define FLASH_CR_BER_Msk (0x1UL << FLASH_CR_BER_Pos) /*!< 0x00000008 */
#define FLASH_CR_BER FLASH_CR_BER_Msk                /*!< Bank erase request */
#define FLASH_CR_PSIZE_Pos (4U)
#define FLASH_CR_PSIZE_Msk (0x3UL << FLASH_CR_PSIZE_Pos) /*!< 0x00000030 */
#define FLASH_CR_PSIZE FLASH_CR_PSIZE_Msk                /*!< Program size */
#define FLASH_CR_PSIZE_0 (0x1UL << FLASH_CR_PSIZE_Pos)   /*!< 0x00000010 */
#define FLASH_CR_PSIZE_1 (0x2UL << FLASH_CR_PSIZE_Pos)   /*!< 0x00000020 */
#define FLASH_CR_FW_Pos (6U)
#define FLASH_CR_FW_Msk (0x1UL << FLASH_CR_FW_Pos) /*!< 0x00000040 */
#define FLASH_CR_FW FLASH_CR_FW_Msk /*!< Write forcing control bit */
#define FLASH_CR_START_Pos (7U)
#define FLASH_CR_START_Msk (0x1UL << FLASH_CR_START_Pos) /*!< 0x00000080 */
#define FLASH_CR_START FLASH_CR_START_Msk /*!< Erase start control bit */
#define FLASH_CR_SNB_Pos (8U)
#define FLASH_CR_SNB_Msk (0x7UL << FLASH_CR_SNB_Pos) /*!< 0x00000700 */
#define FLASH_CR_SNB FLASH_CR_SNB_Msk /*!< Sector erase selection number */
#define FLASH_CR_SNB_0 (0x1UL << FLASH_CR_SNB_Pos) /*!< 0x00000100 */
#define FLASH_CR_SNB_1 (0x2UL << FLASH_CR_SNB_Pos) /*!< 0x00000200 */
#define FLASH_CR_SNB_2 (0x4UL << FLASH_CR_SNB_Pos) /*!< 0x00000400 */
#define FLASH_CR_CRC_EN_Pos (15U)
#define FLASH_CR_CRC_EN_Msk (0x1UL << FLASH_CR_CRC_EN_Pos) /*!< 0x00008000 */
#define FLASH_CR_CRC_EN FLASH_CR_CRC_EN_Msk /*!< CRC control bit */
#define FLASH_CR_EOPIE_Pos (16U)
#define FLASH_CR_EOPIE_Msk (0x1UL << FLASH_CR_EOPIE_Pos) /*!< 0x00010000 */
#define FLASH_CR_EOPIE                                                         \
  FLASH_CR_EOPIE_Msk /*!< End-of-program interrupt control bit */
#define FLASH_CR_WRPERRIE_Pos (17U)
#define FLASH_CR_WRPERRIE_Msk                                                  \
  (0x1UL << FLASH_CR_WRPERRIE_Pos) /*!< 0x00020000 */
#define FLASH_CR_WRPERRIE                                                      \
  FLASH_CR_WRPERRIE_Msk /*!< Write protection error interrupt enable bit */
#define FLASH_CR_PGSERRIE_Pos (18U)
#define FLASH_CR_PGSERRIE_Msk                                                  \
  (0x1UL << FLASH_CR_PGSERRIE_Pos) /*!< 0x00040000 */
#define FLASH_CR_PGSERRIE                                                      \
  FLASH_CR_PGSERRIE_Msk /*!< Programming sequence error interrupt enable bit   \
                         */
#define FLASH_CR_STRBERRIE_Pos (19U)
#define FLASH_CR_STRBERRIE_Msk                                                 \
  (0x1UL << FLASH_CR_STRBERRIE_Pos) /*!< 0x00080000 */
#define FLASH_CR_STRBERRIE                                                     \
  FLASH_CR_STRBERRIE_Msk /*!< Strobe error interrupt enable bit */
#define FLASH_CR_INCERRIE_Pos (21U)
#define FLASH_CR_INCERRIE_Msk                                                  \
  (0x1UL << FLASH_CR_INCERRIE_Pos) /*!< 0x00200000 */
#define FLASH_CR_INCERRIE                                                      \
  FLASH_CR_INCERRIE_Msk /*!< Inconsistency error interrupt enable bit */
#define FLASH_CR_OPERRIE_Pos (22U)
#define FLASH_CR_OPERRIE_Msk                                                   \
  (0x1UL << FLASH_CR_OPERRIE_Pos) /*!< 0x00400000                              \
                                   */
#define FLASH_CR_OPERRIE                                                       \
  FLASH_CR_OPERRIE_Msk /*!< Write/erase error interrupt enable bit */
#define FLASH_CR_RDPERRIE_Pos (23U)
#define FLASH_CR_RDPERRIE_Msk                                                  \
  (0x1UL << FLASH_CR_RDPERRIE_Pos) /*!< 0x00800000 */
#define FLASH_CR_RDPERRIE                                                      \
  FLASH_CR_RDPERRIE_Msk /*!< Read protection error interrupt enable bit */
#define FLASH_CR_RDSERRIE_Pos (24U)
#define FLASH_CR_RDSERRIE_Msk                                                  \
  (0x1UL << FLASH_CR_RDSERRIE_Pos) /*!< 0x01000000 */
#define FLASH_CR_RDSERRIE                                                      \
  FLASH_CR_RDSERRIE_Msk /*!< Secure error interrupt enable bit */
#define FLASH_CR_SNECCERRIE_Pos (25U)
#define FLASH_CR_SNECCERRIE_Msk                                                \
  (0x1UL << FLASH_CR_SNECCERRIE_Pos) /*!< 0x02000000 */
#define FLASH_CR_SNECCERRIE                                                    \
  FLASH_CR_SNECCERRIE_Msk /*!< ECC single correction error interrupt enable    \
                             bit */
#define FLASH_CR_DBECCERRIE_Pos (26U)
#define FLASH_CR_DBECCERRIE_Msk                                                \
  (0x1UL << FLASH_CR_DBECCERRIE_Pos) /*!< 0x04000000 */
#define FLASH_CR_DBECCERRIE                                                    \
  FLASH_CR_DBECCERRIE_Msk /*!< ECC double detection error interrupt enable bit \
                           */
#define FLASH_CR_CRCENDIE_Pos (27U)
#define FLASH_CR_CRCENDIE_Msk                                                  \
  (0x1UL << FLASH_CR_CRCENDIE_Pos) /*!< 0x08000000 */
#define FLASH_CR_CRCENDIE                                                      \
  FLASH_CR_CRCENDIE_Msk /*!< CRC end of calculation interrupt enable bit */
#define FLASH_CR_CRCRDERRIE_Pos (28U)
#define FLASH_CR_CRCRDERRIE_Msk                                                \
  (0x1UL << FLASH_CR_CRCRDERRIE_Pos) /*!< 0x10000000 */
#define FLASH_CR_CRCRDERRIE                                                    \
  FLASH_CR_CRCRDERRIE_Msk /*!< CRC read error interrupt enable bit */

/*******************  Bits definition for FLASH_SR register
 * ***********************/
#define FLASH_SR_BSY_Pos (0U)
#define FLASH_SR_BSY_Msk (0x1UL << FLASH_SR_BSY_Pos) /*!< 0x00000001 */
#define FLASH_SR_BSY FLASH_SR_BSY_Msk                /*!< Busy flag */
#define FLASH_SR_WBNE_Pos (1U)
#define FLASH_SR_WBNE_Msk (0x1UL << FLASH_SR_WBNE_Pos) /*!< 0x00000002 */
#define FLASH_SR_WBNE FLASH_SR_WBNE_Msk /*!< Write buffer not empty flag */
#define FLASH_SR_QW_Pos (2U)
#define FLASH_SR_QW_Msk (0x1UL << FLASH_SR_QW_Pos) /*!< 0x00000004 */
#define FLASH_SR_QW FLASH_SR_QW_Msk                /*!< Wait queue flag */
#define FLASH_SR_CRC_BUSY_Pos (3U)
#define FLASH_SR_CRC_BUSY_Msk                                                  \
  (0x1UL << FLASH_SR_CRC_BUSY_Pos)              /*!< 0x00000008 */
#define FLASH_SR_CRC_BUSY FLASH_SR_CRC_BUSY_Msk /*!< CRC busy flag */
#define FLASH_SR_EOP_Pos (16U)
#define FLASH_SR_EOP_Msk (0x1UL << FLASH_SR_EOP_Pos) /*!< 0x00010000 */
#define FLASH_SR_EOP FLASH_SR_EOP_Msk                /*!< End-of-program flag */
#define FLASH_SR_WRPERR_Pos (17U)
#define FLASH_SR_WRPERR_Msk (0x1UL << FLASH_SR_WRPERR_Pos) /*!< 0x00020000 */
#define FLASH_SR_WRPERR                                                        \
  FLASH_SR_WRPERR_Msk /*!< Write protection error flag                         \
                       */
#define FLASH_SR_PGSERR_Pos (18U)
#define FLASH_SR_PGSERR_Msk (0x1UL << FLASH_SR_PGSERR_Pos) /*!< 0x00040000 */
#define FLASH_SR_PGSERR                                                        \
  FLASH_SR_PGSERR_Msk /*!< Programming sequence error flag */
#define FLASH_SR_STRBERR_Pos (19U)
#define FLASH_SR_STRBERR_Msk                                                   \
  (0x1UL << FLASH_SR_STRBERR_Pos)             /*!< 0x00080000                  \
                                               */
#define FLASH_SR_STRBERR FLASH_SR_STRBERR_Msk /*!< Strobe error flag */
#define FLASH_SR_INCERR_Pos (21U)
#define FLASH_SR_INCERR_Msk (0x1UL << FLASH_SR_INCERR_Pos) /*!< 0x00200000 */
#define FLASH_SR_INCERR FLASH_SR_INCERR_Msk /*!< Inconsistency error flag */
#define FLASH_SR_OPERR_Pos (22U)
#define FLASH_SR_OPERR_Msk (0x1UL << FLASH_SR_OPERR_Pos) /*!< 0x00400000 */
#define FLASH_SR_OPERR FLASH_SR_OPERR_Msk /*!< Write/erase error flag */
#define FLASH_SR_RDPERR_Pos (23U)
#define FLASH_SR_RDPERR_Msk (0x1UL << FLASH_SR_RDPERR_Pos) /*!< 0x00800000 */
#define FLASH_SR_RDPERR FLASH_SR_RDPERR_Msk /*!< Read protection error flag */
#define FLASH_SR_RDSERR_Pos (24U)
#define FLASH_SR_RDSERR_Msk (0x1UL << FLASH_SR_RDSERR_Pos) /*!< 0x01000000 */
#define FLASH_SR_RDSERR FLASH_SR_RDSERR_Msk /*!< Secure error flag */
#define FLASH_SR_SNECCERR_Pos (25U)
#define FLASH_SR_SNECCERR_Msk                                                  \
  (0x1UL << FLASH_SR_SNECCERR_Pos) /*!< 0x02000000 */
#define FLASH_SR_SNECCERR                                                      \
  FLASH_SR_SNECCERR_Msk /*!< Single correction error flag */
#define FLASH_SR_DBECCERR_Pos (26U)
#define FLASH_SR_DBECCERR_Msk                                                  \
  (0x1UL << FLASH_SR_DBECCERR_Pos) /*!< 0x04000000 */
#define FLASH_SR_DBECCERR                                                      \
  FLASH_SR_DBECCERR_Msk /*!< ECC double detection error flag */
#define FLASH_SR_CRCEND_Pos (27U)
#define FLASH_SR_CRCEND_Msk (0x1UL << FLASH_SR_CRCEND_Pos) /*!< 0x08000000 */
#define FLASH_SR_CRCEND                                                        \
  FLASH_SR_CRCEND_Msk /*!< CRC end of calculation flag                         \
                       */
#define FLASH_SR_CRCRDERR_Pos (28U)
#define FLASH_SR_CRCRDERR_Msk                                                  \
  (0x1UL << FLASH_SR_CRCRDERR_Pos)              /*!< 0x10000000 */
#define FLASH_SR_CRCRDERR FLASH_SR_CRCRDERR_Msk /*!< CRC read error flag */

/*******************  Bits definition for FLASH_CCR register
 * *******************/
#define FLASH_CCR_CLR_EOP_Pos (16U)
#define FLASH_CCR_CLR_EOP_Msk                                                  \
  (0x1UL << FLASH_CCR_CLR_EOP_Pos)              /*!< 0x00010000 */
#define FLASH_CCR_CLR_EOP FLASH_CCR_CLR_EOP_Msk /*!< EOP flag clear bit */
#define FLASH_CCR_CLR_WRPERR_Pos (17U)
#define FLASH_CCR_CLR_WRPERR_Msk                                               \
  (0x1UL << FLASH_CCR_CLR_WRPERR_Pos) /*!< 0x00020000 */
#define FLASH_CCR_CLR_WRPERR                                                   \
  FLASH_CCR_CLR_WRPERR_Msk /*!< WRPERR flag clear bit */
#define FLASH_CCR_CLR_PGSERR_Pos (18U)
#define FLASH_CCR_CLR_PGSERR_Msk                                               \
  (0x1UL << FLASH_CCR_CLR_PGSERR_Pos) /*!< 0x00040000 */
#define FLASH_CCR_CLR_PGSERR                                                   \
  FLASH_CCR_CLR_PGSERR_Msk /*!< PGSERR flag clear bit */
#define FLASH_CCR_CLR_STRBERR_Pos (19U)
#define FLASH_CCR_CLR_STRBERR_Msk                                              \
  (0x1UL << FLASH_CCR_CLR_STRBERR_Pos) /*!< 0x00080000 */
#define FLASH_CCR_CLR_STRBERR                                                  \
  FLASH_CCR_CLR_STRBERR_Msk /*!< STRBERR flag clear bit */
#define FLASH_CCR_CLR_INCERR_Pos (21U)
#define FLASH_CCR_CLR_INCERR_Msk                                               \
  (0x1UL << FLASH_CCR_CLR_INCERR_Pos) /*!< 0x00200000 */
#define FLASH_CCR_CLR_INCERR                                                   \
  FLASH_CCR_CLR_INCERR_Msk /*!< INCERR flag clear bit */
#define FLASH_CCR_CLR_OPERR_Pos (22U)
#define FLASH_CCR_CLR_OPERR_Msk                                                \
  (0x1UL << FLASH_CCR_CLR_OPERR_Pos) /*!< 0x00400000 */
#define FLASH_CCR_CLR_OPERR                                                    \
  FLASH_CCR_CLR_OPERR_Msk /*!< OPERR flag clear bit                            \
                           */
#define FLASH_CCR_CLR_RDPERR_Pos (23U)
#define FLASH_CCR_CLR_RDPERR_Msk                                               \
  (0x1UL << FLASH_CCR_CLR_RDPERR_Pos) /*!< 0x00800000 */
#define FLASH_CCR_CLR_RDPERR                                                   \
  FLASH_CCR_CLR_RDPERR_Msk /*!< RDPERR flag clear bit */
#define FLASH_CCR_CLR_RDSERR_Pos (24U)
#define FLASH_CCR_CLR_RDSERR_Msk                                               \
  (0x1UL << FLASH_CCR_CLR_RDSERR_Pos) /*!< 0x01000000 */
#define FLASH_CCR_CLR_RDSERR                                                   \
  FLASH_CCR_CLR_RDSERR_Msk /*!< RDSERR flag clear bit */
#define FLASH_CCR_CLR_SNECCERR_Pos (25U)
#define FLASH_CCR_CLR_SNECCERR_Msk                                             \
  (0x1UL << FLASH_CCR_CLR_SNECCERR_Pos) /*!< 0x02000000 */
#define FLASH_CCR_CLR_SNECCERR                                                 \
  FLASH_CCR_CLR_SNECCERR_Msk /*!< SNECCERR flag clear bit */
#define FLASH_CCR_CLR_DBECCERR_Pos (26U)
#define FLASH_CCR_CLR_DBECCERR_Msk                                             \
  (0x1UL << FLASH_CCR_CLR_DBECCERR_Pos) /*!< 0x04000000 */
#define FLASH_CCR_CLR_DBECCERR                                                 \
  FLASH_CCR_CLR_DBECCERR_Msk /*!< DBECCERR flag clear bit */
#define FLASH_CCR_CLR_CRCEND_Pos (27U)
#define FLASH_CCR_CLR_CRCEND_Msk                                               \
  (0x1UL << FLASH_CCR_CLR_CRCEND_Pos) /*!< 0x08000000 */
#define FLASH_CCR_CLR_CRCEND                                                   \
  FLASH_CCR_CLR_CRCEND_Msk /*!< CRCEND flag clear bit */
#define FLASH_CCR_CLR_CRCRDERR_Pos (28U)
#define FLASH_CCR_CLR_CRCRDERR_Msk                                             \
  (0x1UL << FLASH_CCR_CLR_CRCRDERR_Pos) /*!< 0x10000000 */
#define FLASH_CCR_CLR_CRCRDERR                                                 \
  FLASH_CCR_CLR_CRCRDERR_Msk /*!< CRCRDERR flag clear bit */

/*******************  Bits definition for FLASH_OPTCR register
 * *******************/
#define FLASH_OPTCR_OPTLOCK_Pos (0U)
#define FLASH_OPTCR_OPTLOCK_Msk                                                \
  (0x1UL << FLASH_OPTCR_OPTLOCK_Pos) /*!< 0x00000001 */
#define FLASH_OPTCR_OPTLOCK                                                    \
  FLASH_OPTCR_OPTLOCK_Msk /*!< FLASH_OPTCR lock option configuration bit */
#define FLASH_OPTCR_OPTSTART_Pos (1U)
#define FLASH_OPTCR_OPTSTART_Msk                                               \
  (0x1UL << FLASH_OPTCR_OPTSTART_Pos) /*!< 0x00000002 */
#define FLASH_OPTCR_OPTSTART                                                   \
  FLASH_OPTCR_OPTSTART_Msk /*!< Option byte start change option configuration  \
                              bit */
#define FLASH_OPTCR_MER_Pos (4U)
#define FLASH_OPTCR_MER_Msk (0x1UL << FLASH_OPTCR_MER_Pos) /*!< 0x00000010 */
#define FLASH_OPTCR_MER FLASH_OPTCR_MER_Msk /*!< Mass erase request */
#define FLASH_OPTCR_OPTCHANGEERRIE_Pos (30U)
#define FLASH_OPTCR_OPTCHANGEERRIE_Msk                                         \
  (0x1UL << FLASH_OPTCR_OPTCHANGEERRIE_Pos) /*!< 0x40000000 */
#define FLASH_OPTCR_OPTCHANGEERRIE                                             \
  FLASH_OPTCR_OPTCHANGEERRIE_Msk /*!< Option byte change error interrupt       \
                                    enable bit */
#define FLASH_OPTCR_SWAP_BANK_Pos (31U)
#define FLASH_OPTCR_SWAP_BANK_Msk                                              \
  (0x1UL << FLASH_OPTCR_SWAP_BANK_Pos) /*!< 0x80000000 */
#define FLASH_OPTCR_SWAP_BANK                                                  \
  FLASH_OPTCR_SWAP_BANK_Msk /*!< Bank swapping option configuration bit */

/*******************  Bits definition for FLASH_OPTSR register  ***************/
#define FLASH_OPTSR_OPT_BUSY_Pos (0U)
#define FLASH_OPTSR_OPT_BUSY_Msk                                               \
  (0x1UL << FLASH_OPTSR_OPT_BUSY_Pos) /*!< 0x00000001 */
#define FLASH_OPTSR_OPT_BUSY                                                   \
  FLASH_OPTSR_OPT_BUSY_Msk /*!< Option byte change ongoing flag */
#define FLASH_OPTSR_BOR_LEV_Pos (2U)
#define FLASH_OPTSR_BOR_LEV_Msk                                                \
  (0x3UL << FLASH_OPTSR_BOR_LEV_Pos) /*!< 0x0000000C */
#define FLASH_OPTSR_BOR_LEV                                                    \
  FLASH_OPTSR_BOR_LEV_Msk /*!< Brownout level option status bit */
#define FLASH_OPTSR_BOR_LEV_0                                                  \
  (0x1UL << FLASH_OPTSR_BOR_LEV_Pos) /*!< 0x00000004 */
#define FLASH_OPTSR_BOR_LEV_1                                                  \
  (0x2UL << FLASH_OPTSR_BOR_LEV_Pos) /*!< 0x00000008 */
#define FLASH_OPTSR_IWDG1_SW_Pos (4U)
#define FLASH_OPTSR_IWDG1_SW_Msk                                               \
  (0x1UL << FLASH_OPTSR_IWDG1_SW_Pos) /*!< 0x00000010 */
#define FLASH_OPTSR_IWDG1_SW                                                   \
  FLASH_OPTSR_IWDG1_SW_Msk /*!< IWDG1 control mode option status bit */
#define FLASH_OPTSR_NRST_STOP_D1_Pos (6U)
#define FLASH_OPTSR_NRST_STOP_D1_Msk                                           \
  (0x1UL << FLASH_OPTSR_NRST_STOP_D1_Pos) /*!< 0x00000040 */
#define FLASH_OPTSR_NRST_STOP_D1                                               \
  FLASH_OPTSR_NRST_STOP_D1_Msk /*!< D1 domain DStop entry reset option status  \
                                  bit */
#define FLASH_OPTSR_NRST_STBY_D1_Pos (7U)
#define FLASH_OPTSR_NRST_STBY_D1_Msk                                           \
  (0x1UL << FLASH_OPTSR_NRST_STBY_D1_Pos) /*!< 0x00000080 */
#define FLASH_OPTSR_NRST_STBY_D1                                               \
  FLASH_OPTSR_NRST_STBY_D1_Msk /*!< D1 domain DStandby entry reset option      \
                                  status bit */
#define FLASH_OPTSR_RDP_Pos (8U)
#define FLASH_OPTSR_RDP_Msk (0xFFUL << FLASH_OPTSR_RDP_Pos) /*!< 0x0000FF00 */
#define FLASH_OPTSR_RDP                                                        \
  FLASH_OPTSR_RDP_Msk /*!< Readout protection level option status byte */
#define FLASH_OPTSR_FZ_IWDG_STOP_Pos (17U)
#define FLASH_OPTSR_FZ_IWDG_STOP_Msk                                           \
  (0x1UL << FLASH_OPTSR_FZ_IWDG_STOP_Pos) /*!< 0x00020000 */
#define FLASH_OPTSR_FZ_IWDG_STOP                                               \
  FLASH_OPTSR_FZ_IWDG_STOP_Msk /*!< IWDG Stop mode freeze option status bit */
#define FLASH_OPTSR_FZ_IWDG_SDBY_Pos (18U)
#define FLASH_OPTSR_FZ_IWDG_SDBY_Msk                                           \
  (0x1UL << FLASH_OPTSR_FZ_IWDG_SDBY_Pos) /*!< 0x00040000 */
#define FLASH_OPTSR_FZ_IWDG_SDBY                                               \
  FLASH_OPTSR_FZ_IWDG_SDBY_Msk /*!< IWDG Standby mode freeze option status bit \
                                */
#define FLASH_OPTSR_ST_RAM_SIZE_Pos (19U)
#define FLASH_OPTSR_ST_RAM_SIZE_Msk                                            \
  (0x3UL << FLASH_OPTSR_ST_RAM_SIZE_Pos) /*!< 0x00180000 */
#define FLASH_OPTSR_ST_RAM_SIZE                                                \
  FLASH_OPTSR_ST_RAM_SIZE_Msk /*!< ST RAM size option status */
#define FLASH_OPTSR_ST_RAM_SIZE_0                                              \
  (0x1UL << FLASH_OPTSR_ST_RAM_SIZE_Pos) /*!< 0x00080000 */
#define FLASH_OPTSR_ST_RAM_SIZE_1                                              \
  (0x2UL << FLASH_OPTSR_ST_RAM_SIZE_Pos) /*!< 0x00100000 */
#define FLASH_OPTSR_SECURITY_Pos (21U)
#define FLASH_OPTSR_SECURITY_Msk                                               \
  (0x1UL << FLASH_OPTSR_SECURITY_Pos) /*!< 0x00200000 */
#define FLASH_OPTSR_SECURITY                                                   \
  FLASH_OPTSR_SECURITY_Msk /*!< Security enable option status bit */
#define FLASH_OPTSR_IO_HSLV_Pos (29U)
#define FLASH_OPTSR_IO_HSLV_Msk                                                \
  (0x1UL << FLASH_OPTSR_IO_HSLV_Pos) /*!< 0x20000000 */
#define FLASH_OPTSR_IO_HSLV                                                    \
  FLASH_OPTSR_IO_HSLV_Msk /*!< I/O high-speed at low-voltage status bit */
#define FLASH_OPTSR_OPTCHANGEERR_Pos (30U)
#define FLASH_OPTSR_OPTCHANGEERR_Msk                                           \
  (0x1UL << FLASH_OPTSR_OPTCHANGEERR_Pos) /*!< 0x40000000 */
#define FLASH_OPTSR_OPTCHANGEERR                                               \
  FLASH_OPTSR_OPTCHANGEERR_Msk /*!< Option byte change error flag */
#define FLASH_OPTSR_SWAP_BANK_OPT_Pos (31U)
#define FLASH_OPTSR_SWAP_BANK_OPT_Msk                                          \
  (0x1UL << FLASH_OPTSR_SWAP_BANK_OPT_Pos) /*!< 0x80000000 */
#define FLASH_OPTSR_SWAP_BANK_OPT                                              \
  FLASH_OPTSR_SWAP_BANK_OPT_Msk /*!< Bank swapping option status bit */

/*******************  Bits definition for FLASH_OPTCCR register
 * *******************/
#define FLASH_OPTCCR_CLR_OPTCHANGEERR_Pos (30U)
#define FLASH_OPTCCR_CLR_OPTCHANGEERR_Msk                                      \
  (0x1UL << FLASH_OPTCCR_CLR_OPTCHANGEERR_Pos) /*!< 0x40000000 */
#define FLASH_OPTCCR_CLR_OPTCHANGEERR                                          \
  FLASH_OPTCCR_CLR_OPTCHANGEERR_Msk /*!< OPTCHANGEERR reset bit */

/*******************  Bits definition for FLASH_PRAR register
 * *********************/
#define FLASH_PRAR_PROT_AREA_START_Pos (0U)
#define FLASH_PRAR_PROT_AREA_START_Msk                                         \
  (0xFFFUL << FLASH_PRAR_PROT_AREA_START_Pos) /*!< 0x00000FFF */
#define FLASH_PRAR_PROT_AREA_START                                             \
  FLASH_PRAR_PROT_AREA_START_Msk /*!< PCROP area start status bits */
#define FLASH_PRAR_PROT_AREA_END_Pos (16U)
#define FLASH_PRAR_PROT_AREA_END_Msk                                           \
  (0xFFFUL << FLASH_PRAR_PROT_AREA_END_Pos) /*!< 0x0FFF0000 */
#define FLASH_PRAR_PROT_AREA_END                                               \
  FLASH_PRAR_PROT_AREA_END_Msk /*!< PCROP area end status bits */
#define FLASH_PRAR_DMEP_Pos (31U)
#define FLASH_PRAR_DMEP_Msk (0x1UL << FLASH_PRAR_DMEP_Pos) /*!< 0x80000000 */
#define FLASH_PRAR_DMEP                                                        \
  FLASH_PRAR_DMEP_Msk /*!< PCROP protected erase enable option status bit */

/*******************  Bits definition for FLASH_SCAR register
 * *********************/
#define FLASH_SCAR_SEC_AREA_START_Pos (0U)
#define FLASH_SCAR_SEC_AREA_START_Msk                                          \
  (0xFFFUL << FLASH_SCAR_SEC_AREA_START_Pos) /*!< 0x00000FFF */
#define FLASH_SCAR_SEC_AREA_START                                              \
  FLASH_SCAR_SEC_AREA_START_Msk /*!< Secure-only area start status bits */
#define FLASH_SCAR_SEC_AREA_END_Pos (16U)
#define FLASH_SCAR_SEC_AREA_END_Msk                                            \
  (0xFFFUL << FLASH_SCAR_SEC_AREA_END_Pos) /*!< 0x0FFF0000 */
#define FLASH_SCAR_SEC_AREA_END                                                \
  FLASH_SCAR_SEC_AREA_END_Msk /*!< Secure-only area end status bits */
#define FLASH_SCAR_DMES_Pos (31U)
#define FLASH_SCAR_DMES_Msk (0x1UL << FLASH_SCAR_DMES_Pos) /*!< 0x80000000 */
#define FLASH_SCAR_DMES                                                        \
  FLASH_SCAR_DMES_Msk /*!< Secure access protected erase enable option status  \
                         bit */

/*******************  Bits definition for FLASH_WPSN register
 * *********************/
#define FLASH_WPSN_WRPSN_Pos (0U)
#define FLASH_WPSN_WRPSN_Msk                                                   \
  (0xFFUL << FLASH_WPSN_WRPSN_Pos) /*!< 0x000000FF                             \
                                    */
#define FLASH_WPSN_WRPSN                                                       \
  FLASH_WPSN_WRPSN_Msk /*!< Sector write protection option status byte */

/*******************  Bits definition for FLASH_BOOT_CUR register
 * ****************/
#define FLASH_BOOT_ADD0_Pos (0U)
#define FLASH_BOOT_ADD0_Msk                                                    \
  (0xFFFFUL << FLASH_BOOT_ADD0_Pos) /*!< 0x0000FFFF                            \
                                     */
#define FLASH_BOOT_ADD0                                                        \
  FLASH_BOOT_ADD0_Msk /*!< Arm Cortex-M7 boot address 0                        \
                       */
#define FLASH_BOOT_ADD1_Pos (16U)
#define FLASH_BOOT_ADD1_Msk                                                    \
  (0xFFFFUL << FLASH_BOOT_ADD1_Pos) /*!< 0xFFFF0000                            \
                                     */
#define FLASH_BOOT_ADD1                                                        \
  FLASH_BOOT_ADD1_Msk /*!< Arm Cortex-M7 boot address 1                        \
                       */

/*******************  Bits definition for FLASH_CRCCR register
 * ********************/
#define FLASH_CRCCR_CRC_SECT_Pos (0U)
#define FLASH_CRCCR_CRC_SECT_Msk                                               \
  (0x7UL << FLASH_CRCCR_CRC_SECT_Pos) /*!< 0x00000007 */
#define FLASH_CRCCR_CRC_SECT                                                   \
  FLASH_CRCCR_CRC_SECT_Msk /*!< CRC sector number                              \
                            */
#define FLASH_CRCCR_CRC_BY_SECT_Pos (8U)
#define FLASH_CRCCR_CRC_BY_SECT_Msk                                            \
  (0x1UL << FLASH_CRCCR_CRC_BY_SECT_Pos) /*!< 0x00000100 */
#define FLASH_CRCCR_CRC_BY_SECT                                                \
  FLASH_CRCCR_CRC_BY_SECT_Msk /*!< CRC sector mode select bit */
#define FLASH_CRCCR_ADD_SECT_Pos (9U)
#define FLASH_CRCCR_ADD_SECT_Msk                                               \
  (0x1UL << FLASH_CRCCR_ADD_SECT_Pos) /*!< 0x00000200 */
#define FLASH_CRCCR_ADD_SECT                                                   \
  FLASH_CRCCR_ADD_SECT_Msk /*!< CRC sector select bit */
#define FLASH_CRCCR_CLEAN_SECT_Pos (10U)
#define FLASH_CRCCR_CLEAN_SECT_Msk                                             \
  (0x1UL << FLASH_CRCCR_CLEAN_SECT_Pos) /*!< 0x00000400 */
#define FLASH_CRCCR_CLEAN_SECT                                                 \
  FLASH_CRCCR_CLEAN_SECT_Msk /*!< CRC sector list clear bit */
#define FLASH_CRCCR_START_CRC_Pos (16U)
#define FLASH_CRCCR_START_CRC_Msk                                              \
  (0x1UL << FLASH_CRCCR_START_CRC_Pos)                  /*!< 0x00010000 */
#define FLASH_CRCCR_START_CRC FLASH_CRCCR_START_CRC_Msk /*!< CRC start bit */
#define FLASH_CRCCR_CLEAN_CRC_Pos (17U)
#define FLASH_CRCCR_CLEAN_CRC_Msk                                              \
  (0x1UL << FLASH_CRCCR_CLEAN_CRC_Pos)                  /*!< 0x00020000 */
#define FLASH_CRCCR_CLEAN_CRC FLASH_CRCCR_CLEAN_CRC_Msk /*!< CRC clear bit */
#define FLASH_CRCCR_CRC_BURST_Pos (20U)
#define FLASH_CRCCR_CRC_BURST_Msk                                              \
  (0x3UL << FLASH_CRCCR_CRC_BURST_Pos)                  /*!< 0x00300000 */
#define FLASH_CRCCR_CRC_BURST FLASH_CRCCR_CRC_BURST_Msk /*!< CRC burst size */
#define FLASH_CRCCR_CRC_BURST_0                                                \
  (0x1UL << FLASH_CRCCR_CRC_BURST_Pos) /*!< 0x00100000 */
#define FLASH_CRCCR_CRC_BURST_1                                                \
  (0x2UL << FLASH_CRCCR_CRC_BURST_Pos) /*!< 0x00200000 */
#define FLASH_CRCCR_ALL_BANK_Pos (22U)
#define FLASH_CRCCR_ALL_BANK_Msk                                               \
  (0x1UL << FLASH_CRCCR_ALL_BANK_Pos)                 /*!< 0x00400000 */
#define FLASH_CRCCR_ALL_BANK FLASH_CRCCR_ALL_BANK_Msk /*!< CRC select bit */

/*******************  Bits definition for FLASH_CRCSADD register
 * ****************/
#define FLASH_CRCSADD_CRC_START_ADDR_Pos (0U)
#define FLASH_CRCSADD_CRC_START_ADDR_Msk                                       \
  (0xFFFFFFFFUL << FLASH_CRCSADD_CRC_START_ADDR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_CRCSADD_CRC_START_ADDR                                           \
  FLASH_CRCSADD_CRC_START_ADDR_Msk /*!< CRC start address */

/*******************  Bits definition for FLASH_CRCEADD register
 * ****************/
#define FLASH_CRCEADD_CRC_END_ADDR_Pos (0U)
#define FLASH_CRCEADD_CRC_END_ADDR_Msk                                         \
  (0xFFFFFFFFUL << FLASH_CRCEADD_CRC_END_ADDR_Pos) /*!< 0xFFFFFFFF */
#define FLASH_CRCEADD_CRC_END_ADDR                                             \
  FLASH_CRCEADD_CRC_END_ADDR_Msk /*!< CRC end address */

/*******************  Bits definition for FLASH_CRCDATA register
 * ***************/
#define FLASH_CRCDATA_CRC_DATA_Pos (0U)
#define FLASH_CRCDATA_CRC_DATA_Msk                                             \
  (0xFFFFFFFFUL << FLASH_CRCDATA_CRC_DATA_Pos)            /*!< 0xFFFFFFFF */
#define FLASH_CRCDATA_CRC_DATA FLASH_CRCDATA_CRC_DATA_Msk /*!< CRC result */

/*******************  Bits definition for FLASH_ECC_FA register
 * *******************/
#define FLASH_ECC_FA_FAIL_ECC_ADDR_Pos (0U)
#define FLASH_ECC_FA_FAIL_ECC_ADDR_Msk                                         \
  (0x7FFFUL << FLASH_ECC_FA_FAIL_ECC_ADDR_Pos) /*!< 0x00007FFF */
#define FLASH_ECC_FA_FAIL_ECC_ADDR                                             \
  FLASH_ECC_FA_FAIL_ECC_ADDR_Msk /*!< ECC error address */

#define HAL_FLASH_MODULE_ENABLED 1

#endif
