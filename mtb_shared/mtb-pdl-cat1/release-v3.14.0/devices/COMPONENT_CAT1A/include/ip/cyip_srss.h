/***************************************************************************//**
* \file cyip_srss.h
*
* \brief
* SRSS IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#ifndef _CYIP_SRSS_H_
#define _CYIP_SRSS_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                     SRSS
*******************************************************************************/

#define MCWDT_STRUCT_SECTION_SIZE               0x00000040UL
#define SRSS_SECTION_SIZE                       0x00010000UL

/**
  * \brief Multi-Counter Watchdog Timer (MCWDT_STRUCT)
  */
typedef struct {
   __IM uint32_t RESERVED;
  __IOM uint32_t MCWDT_CNTLOW;                  /*!< 0x00000004 Multi-Counter Watchdog Sub-counters 0/1 */
  __IOM uint32_t MCWDT_CNTHIGH;                 /*!< 0x00000008 Multi-Counter Watchdog Sub-counter 2 */
  __IOM uint32_t MCWDT_MATCH;                   /*!< 0x0000000C Multi-Counter Watchdog Counter Match Register */
  __IOM uint32_t MCWDT_CONFIG;                  /*!< 0x00000010 Multi-Counter Watchdog Counter Configuration */
  __IOM uint32_t MCWDT_CTL;                     /*!< 0x00000014 Multi-Counter Watchdog Counter Control */
  __IOM uint32_t MCWDT_INTR;                    /*!< 0x00000018 Multi-Counter Watchdog Counter Interrupt Register */
  __IOM uint32_t MCWDT_INTR_SET;                /*!< 0x0000001C Multi-Counter Watchdog Counter Interrupt Set Register */
  __IOM uint32_t MCWDT_INTR_MASK;               /*!< 0x00000020 Multi-Counter Watchdog Counter Interrupt Mask Register */
   __IM uint32_t MCWDT_INTR_MASKED;             /*!< 0x00000024 Multi-Counter Watchdog Counter Interrupt Masked Register */
  __IOM uint32_t MCWDT_LOCK;                    /*!< 0x00000028 Multi-Counter Watchdog Counter Lock Register */
   __IM uint32_t RESERVED1[5];
} MCWDT_STRUCT_V1_Type;                         /*!< Size = 64 (0x40) */

/**
  * \brief SRSS Core Registers (SRSS)
  */
typedef struct {
  __IOM uint32_t PWR_CTL;                       /*!< 0x00000000 Power Mode Control */
  __IOM uint32_t PWR_HIBERNATE;                 /*!< 0x00000004 HIBERNATE Mode Register */
  __IOM uint32_t PWR_LVD_CTL;                   /*!< 0x00000008 Low Voltage Detector (LVD) Configuration Register */
   __IM uint32_t RESERVED[2];
  __IOM uint32_t PWR_BUCK_CTL;                  /*!< 0x00000014 Buck Control Register */
  __IOM uint32_t PWR_BUCK_CTL2;                 /*!< 0x00000018 Buck Control Register 2 */
   __IM uint32_t PWR_LVD_STATUS;                /*!< 0x0000001C Low Voltage Detector (LVD) Status Register */
   __IM uint32_t RESERVED1[24];
  __IOM uint32_t PWR_HIB_DATA[16];              /*!< 0x00000080 HIBERNATE Data Register */
   __IM uint32_t RESERVED2[48];
  __IOM uint32_t WDT_CTL;                       /*!< 0x00000180 Watchdog Counter Control Register */
  __IOM uint32_t WDT_CNT;                       /*!< 0x00000184 Watchdog Counter Count Register */
  __IOM uint32_t WDT_MATCH;                     /*!< 0x00000188 Watchdog Counter Match Register */
   __IM uint32_t RESERVED3[29];
        MCWDT_STRUCT_V1_Type MCWDT_STRUCT[4];   /*!< 0x00000200 Multi-Counter Watchdog Timer */
  __IOM uint32_t CLK_DSI_SELECT[16];            /*!< 0x00000300 Clock DSI Select Register */
  __IOM uint32_t CLK_PATH_SELECT[16];           /*!< 0x00000340 Clock Path Select Register */
  __IOM uint32_t CLK_ROOT_SELECT[16];           /*!< 0x00000380 Clock Root Select Register */
   __IM uint32_t RESERVED4[80];
  __IOM uint32_t CLK_SELECT;                    /*!< 0x00000500 Clock selection register */
  __IOM uint32_t CLK_TIMER_CTL;                 /*!< 0x00000504 Timer Clock Control Register */
   __IM uint32_t RESERVED5;
  __IOM uint32_t CLK_ILO_CONFIG;                /*!< 0x0000050C ILO Configuration */
  __IOM uint32_t CLK_IMO_CONFIG;                /*!< 0x00000510 IMO Configuration */
  __IOM uint32_t CLK_OUTPUT_FAST;               /*!< 0x00000514 Fast Clock Output Select Register */
  __IOM uint32_t CLK_OUTPUT_SLOW;               /*!< 0x00000518 Slow Clock Output Select Register */
  __IOM uint32_t CLK_CAL_CNT1;                  /*!< 0x0000051C Clock Calibration Counter 1 */
   __IM uint32_t CLK_CAL_CNT2;                  /*!< 0x00000520 Clock Calibration Counter 2 */
   __IM uint32_t RESERVED6[2];
  __IOM uint32_t CLK_ECO_CONFIG;                /*!< 0x0000052C ECO Configuration Register */
   __IM uint32_t CLK_ECO_STATUS;                /*!< 0x00000530 ECO Status Register */
   __IM uint32_t RESERVED7[2];
  __IOM uint32_t CLK_PILO_CONFIG;               /*!< 0x0000053C Precision ILO Configuration Register */
   __IM uint32_t RESERVED8;
  __IOM uint32_t CLK_MF_SELECT;                 /*!< 0x00000544 Medium Frequency Clock Select Register */
  __IOM uint32_t CLK_MFO_CONFIG;                /*!< 0x00000548 MFO Configuration Register */
   __IM uint32_t RESERVED9[13];
  __IOM uint32_t CLK_FLL_CONFIG;                /*!< 0x00000580 FLL Configuration Register */
  __IOM uint32_t CLK_FLL_CONFIG2;               /*!< 0x00000584 FLL Configuration Register 2 */
  __IOM uint32_t CLK_FLL_CONFIG3;               /*!< 0x00000588 FLL Configuration Register 3 */
  __IOM uint32_t CLK_FLL_CONFIG4;               /*!< 0x0000058C FLL Configuration Register 4 */
  __IOM uint32_t CLK_FLL_STATUS;                /*!< 0x00000590 FLL Status Register */
   __IM uint32_t RESERVED10[27];
  __IOM uint32_t CLK_PLL_CONFIG[15];            /*!< 0x00000600 PLL Configuration Register */
   __IM uint32_t RESERVED11;
  __IOM uint32_t CLK_PLL_STATUS[15];            /*!< 0x00000640 PLL Status Register */
   __IM uint32_t RESERVED12[33];
  __IOM uint32_t SRSS_INTR;                     /*!< 0x00000700 SRSS Interrupt Register */
  __IOM uint32_t SRSS_INTR_SET;                 /*!< 0x00000704 SRSS Interrupt Set Register */
  __IOM uint32_t SRSS_INTR_MASK;                /*!< 0x00000708 SRSS Interrupt Mask Register */
   __IM uint32_t SRSS_INTR_MASKED;              /*!< 0x0000070C SRSS Interrupt Masked Register */
  __IOM uint32_t SRSS_INTR_CFG;                 /*!< 0x00000710 SRSS Interrupt Configuration Register */
   __IM uint32_t RESERVED13[59];
  __IOM uint32_t RES_CAUSE;                     /*!< 0x00000800 Reset Cause Observation Register */
  __IOM uint32_t RES_CAUSE2;                    /*!< 0x00000804 Reset Cause Observation Register 2 */
   __IM uint32_t RESERVED14[7614];
  __IOM uint32_t PWR_TRIM_REF_CTL;              /*!< 0x00007F00 Reference Trim Register */
  __IOM uint32_t PWR_TRIM_BODOVP_CTL;           /*!< 0x00007F04 BOD/OVP Trim Register */
  __IOM uint32_t CLK_TRIM_CCO_CTL;              /*!< 0x00007F08 CCO Trim Register */
  __IOM uint32_t CLK_TRIM_CCO_CTL2;             /*!< 0x00007F0C CCO Trim Register 2 */
   __IM uint32_t RESERVED15[8];
  __IOM uint32_t PWR_TRIM_WAKE_CTL;             /*!< 0x00007F30 Wakeup Trim Register */
   __IM uint32_t RESERVED16[8183];
  __IOM uint32_t PWR_TRIM_LVD_CTL;              /*!< 0x0000FF10 LVD Trim Register */
   __IM uint32_t RESERVED17;
  __IOM uint32_t CLK_TRIM_ILO_CTL;              /*!< 0x0000FF18 ILO Trim Register */
  __IOM uint32_t PWR_TRIM_PWRSYS_CTL;           /*!< 0x0000FF1C Power System Trim Register */
  __IOM uint32_t CLK_TRIM_ECO_CTL;              /*!< 0x0000FF20 ECO Trim Register */
  __IOM uint32_t CLK_TRIM_PILO_CTL;             /*!< 0x0000FF24 PILO Trim Register */
  __IOM uint32_t CLK_TRIM_PILO_CTL2;            /*!< 0x0000FF28 PILO Trim Register 2 */
  __IOM uint32_t CLK_TRIM_PILO_CTL3;            /*!< 0x0000FF2C PILO Trim Register 3 */
} SRSS_V1_Type;                                 /*!< Size = 65328 (0xFF30) */


/* MCWDT_STRUCT.MCWDT_CNTLOW */
#define MCWDT_STRUCT_MCWDT_CNTLOW_WDT_CTR0_Pos  0UL
#define MCWDT_STRUCT_MCWDT_CNTLOW_WDT_CTR0_Msk  0xFFFFUL
#define MCWDT_STRUCT_MCWDT_CNTLOW_WDT_CTR1_Pos  16UL
#define MCWDT_STRUCT_MCWDT_CNTLOW_WDT_CTR1_Msk  0xFFFF0000UL
/* MCWDT_STRUCT.MCWDT_CNTHIGH */
#define MCWDT_STRUCT_MCWDT_CNTHIGH_WDT_CTR2_Pos 0UL
#define MCWDT_STRUCT_MCWDT_CNTHIGH_WDT_CTR2_Msk 0xFFFFFFFFUL
/* MCWDT_STRUCT.MCWDT_MATCH */
#define MCWDT_STRUCT_MCWDT_MATCH_WDT_MATCH0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_MATCH_WDT_MATCH0_Msk 0xFFFFUL
#define MCWDT_STRUCT_MCWDT_MATCH_WDT_MATCH1_Pos 16UL
#define MCWDT_STRUCT_MCWDT_MATCH_WDT_MATCH1_Msk 0xFFFF0000UL
/* MCWDT_STRUCT.MCWDT_CONFIG */
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE0_Msk 0x3UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CLEAR0_Pos 2UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CLEAR0_Msk 0x4UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CASCADE0_1_Pos 3UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CASCADE0_1_Msk 0x8UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE1_Pos 8UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE1_Msk 0x300UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CLEAR1_Pos 10UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CLEAR1_Msk 0x400UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CASCADE1_2_Pos 11UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_CASCADE1_2_Msk 0x800UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE2_Pos 16UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_MODE2_Msk 0x10000UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_BITS2_Pos 24UL
#define MCWDT_STRUCT_MCWDT_CONFIG_WDT_BITS2_Msk 0x1F000000UL
/* MCWDT_STRUCT.MCWDT_CTL */
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE0_Pos  0UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE0_Msk  0x1UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED0_Pos 1UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED0_Msk 0x2UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET0_Pos   3UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET0_Msk   0x8UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE1_Pos  8UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE1_Msk  0x100UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED1_Pos 9UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED1_Msk 0x200UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET1_Pos   11UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET1_Msk   0x800UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE2_Pos  16UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLE2_Msk  0x10000UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED2_Pos 17UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_ENABLED2_Msk 0x20000UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET2_Pos   19UL
#define MCWDT_STRUCT_MCWDT_CTL_WDT_RESET2_Msk   0x80000UL
/* MCWDT_STRUCT.MCWDT_INTR */
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT0_Pos  0UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT0_Msk  0x1UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT1_Pos  1UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT1_Msk  0x2UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT2_Pos  2UL
#define MCWDT_STRUCT_MCWDT_INTR_MCWDT_INT2_Msk  0x4UL
/* MCWDT_STRUCT.MCWDT_INTR_SET */
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT0_Msk 0x1UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT1_Pos 1UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT1_Msk 0x2UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT2_Pos 2UL
#define MCWDT_STRUCT_MCWDT_INTR_SET_MCWDT_INT2_Msk 0x4UL
/* MCWDT_STRUCT.MCWDT_INTR_MASK */
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT0_Msk 0x1UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT1_Pos 1UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT1_Msk 0x2UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT2_Pos 2UL
#define MCWDT_STRUCT_MCWDT_INTR_MASK_MCWDT_INT2_Msk 0x4UL
/* MCWDT_STRUCT.MCWDT_INTR_MASKED */
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT0_Pos 0UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT0_Msk 0x1UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT1_Pos 1UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT1_Msk 0x2UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT2_Pos 2UL
#define MCWDT_STRUCT_MCWDT_INTR_MASKED_MCWDT_INT2_Msk 0x4UL
/* MCWDT_STRUCT.MCWDT_LOCK */
#define MCWDT_STRUCT_MCWDT_LOCK_MCWDT_LOCK_Pos  30UL
#define MCWDT_STRUCT_MCWDT_LOCK_MCWDT_LOCK_Msk  0xC0000000UL


/* SRSS.PWR_CTL */
#define SRSS_PWR_CTL_POWER_MODE_Pos             0UL
#define SRSS_PWR_CTL_POWER_MODE_Msk             0x3UL
#define SRSS_PWR_CTL_DEBUG_SESSION_Pos          4UL
#define SRSS_PWR_CTL_DEBUG_SESSION_Msk          0x10UL
#define SRSS_PWR_CTL_LPM_READY_Pos              5UL
#define SRSS_PWR_CTL_LPM_READY_Msk              0x20UL
#define SRSS_PWR_CTL_IREF_LPMODE_Pos            18UL
#define SRSS_PWR_CTL_IREF_LPMODE_Msk            0x40000UL
#define SRSS_PWR_CTL_VREFBUF_OK_Pos             19UL
#define SRSS_PWR_CTL_VREFBUF_OK_Msk             0x80000UL
#define SRSS_PWR_CTL_DPSLP_REG_DIS_Pos          20UL
#define SRSS_PWR_CTL_DPSLP_REG_DIS_Msk          0x100000UL
#define SRSS_PWR_CTL_RET_REG_DIS_Pos            21UL
#define SRSS_PWR_CTL_RET_REG_DIS_Msk            0x200000UL
#define SRSS_PWR_CTL_NWELL_REG_DIS_Pos          22UL
#define SRSS_PWR_CTL_NWELL_REG_DIS_Msk          0x400000UL
#define SRSS_PWR_CTL_LINREG_DIS_Pos             23UL
#define SRSS_PWR_CTL_LINREG_DIS_Msk             0x800000UL
#define SRSS_PWR_CTL_LINREG_LPMODE_Pos          24UL
#define SRSS_PWR_CTL_LINREG_LPMODE_Msk          0x1000000UL
#define SRSS_PWR_CTL_PORBOD_LPMODE_Pos          25UL
#define SRSS_PWR_CTL_PORBOD_LPMODE_Msk          0x2000000UL
#define SRSS_PWR_CTL_BGREF_LPMODE_Pos           26UL
#define SRSS_PWR_CTL_BGREF_LPMODE_Msk           0x4000000UL
#define SRSS_PWR_CTL_PLL_LS_BYPASS_Pos          27UL
#define SRSS_PWR_CTL_PLL_LS_BYPASS_Msk          0x8000000UL
#define SRSS_PWR_CTL_VREFBUF_LPMODE_Pos         28UL
#define SRSS_PWR_CTL_VREFBUF_LPMODE_Msk         0x10000000UL
#define SRSS_PWR_CTL_VREFBUF_DIS_Pos            29UL
#define SRSS_PWR_CTL_VREFBUF_DIS_Msk            0x20000000UL
#define SRSS_PWR_CTL_ACT_REF_DIS_Pos            30UL
#define SRSS_PWR_CTL_ACT_REF_DIS_Msk            0x40000000UL
#define SRSS_PWR_CTL_ACT_REF_OK_Pos             31UL
#define SRSS_PWR_CTL_ACT_REF_OK_Msk             0x80000000UL
/* SRSS.PWR_HIBERNATE */
#define SRSS_PWR_HIBERNATE_TOKEN_Pos            0UL
#define SRSS_PWR_HIBERNATE_TOKEN_Msk            0xFFUL
#define SRSS_PWR_HIBERNATE_UNLOCK_Pos           8UL
#define SRSS_PWR_HIBERNATE_UNLOCK_Msk           0xFF00UL
#define SRSS_PWR_HIBERNATE_FREEZE_Pos           17UL
#define SRSS_PWR_HIBERNATE_FREEZE_Msk           0x20000UL
#define SRSS_PWR_HIBERNATE_MASK_HIBALARM_Pos    18UL
#define SRSS_PWR_HIBERNATE_MASK_HIBALARM_Msk    0x40000UL
#define SRSS_PWR_HIBERNATE_MASK_HIBWDT_Pos      19UL
#define SRSS_PWR_HIBERNATE_MASK_HIBWDT_Msk      0x80000UL
#define SRSS_PWR_HIBERNATE_POLARITY_HIBPIN_Pos  20UL
#define SRSS_PWR_HIBERNATE_POLARITY_HIBPIN_Msk  0xF00000UL
#define SRSS_PWR_HIBERNATE_MASK_HIBPIN_Pos      24UL
#define SRSS_PWR_HIBERNATE_MASK_HIBPIN_Msk      0xF000000UL
#define SRSS_PWR_HIBERNATE_HIBERNATE_DISABLE_Pos 30UL
#define SRSS_PWR_HIBERNATE_HIBERNATE_DISABLE_Msk 0x40000000UL
#define SRSS_PWR_HIBERNATE_HIBERNATE_Pos        31UL
#define SRSS_PWR_HIBERNATE_HIBERNATE_Msk        0x80000000UL
/* SRSS.PWR_LVD_CTL */
#define SRSS_PWR_LVD_CTL_HVLVD1_TRIPSEL_Pos     0UL
#define SRSS_PWR_LVD_CTL_HVLVD1_TRIPSEL_Msk     0xFUL
#define SRSS_PWR_LVD_CTL_HVLVD1_SRCSEL_Pos      4UL
#define SRSS_PWR_LVD_CTL_HVLVD1_SRCSEL_Msk      0x70UL
#define SRSS_PWR_LVD_CTL_HVLVD1_EN_Pos          7UL
#define SRSS_PWR_LVD_CTL_HVLVD1_EN_Msk          0x80UL
/* SRSS.PWR_BUCK_CTL */
#define SRSS_PWR_BUCK_CTL_BUCK_OUT1_SEL_Pos     0UL
#define SRSS_PWR_BUCK_CTL_BUCK_OUT1_SEL_Msk     0x7UL
#define SRSS_PWR_BUCK_CTL_BUCK_EN_Pos           30UL
#define SRSS_PWR_BUCK_CTL_BUCK_EN_Msk           0x40000000UL
#define SRSS_PWR_BUCK_CTL_BUCK_OUT1_EN_Pos      31UL
#define SRSS_PWR_BUCK_CTL_BUCK_OUT1_EN_Msk      0x80000000UL
/* SRSS.PWR_BUCK_CTL2 */
#define SRSS_PWR_BUCK_CTL2_BUCK_OUT2_SEL_Pos    0UL
#define SRSS_PWR_BUCK_CTL2_BUCK_OUT2_SEL_Msk    0x7UL
#define SRSS_PWR_BUCK_CTL2_BUCK_OUT2_HW_SEL_Pos 30UL
#define SRSS_PWR_BUCK_CTL2_BUCK_OUT2_HW_SEL_Msk 0x40000000UL
#define SRSS_PWR_BUCK_CTL2_BUCK_OUT2_EN_Pos     31UL
#define SRSS_PWR_BUCK_CTL2_BUCK_OUT2_EN_Msk     0x80000000UL
/* SRSS.PWR_LVD_STATUS */
#define SRSS_PWR_LVD_STATUS_HVLVD1_OK_Pos       0UL
#define SRSS_PWR_LVD_STATUS_HVLVD1_OK_Msk       0x1UL
/* SRSS.PWR_HIB_DATA */
#define SRSS_PWR_HIB_DATA_HIB_DATA_Pos          0UL
#define SRSS_PWR_HIB_DATA_HIB_DATA_Msk          0xFFFFFFFFUL
/* SRSS.WDT_CTL */
#define SRSS_WDT_CTL_WDT_EN_Pos                 0UL
#define SRSS_WDT_CTL_WDT_EN_Msk                 0x1UL
#define SRSS_WDT_CTL_WDT_LOCK_Pos               30UL
#define SRSS_WDT_CTL_WDT_LOCK_Msk               0xC0000000UL
/* SRSS.WDT_CNT */
#define SRSS_WDT_CNT_COUNTER_Pos                0UL
#define SRSS_WDT_CNT_COUNTER_Msk                0xFFFFUL
/* SRSS.WDT_MATCH */
#define SRSS_WDT_MATCH_MATCH_Pos                0UL
#define SRSS_WDT_MATCH_MATCH_Msk                0xFFFFUL
#define SRSS_WDT_MATCH_IGNORE_BITS_Pos          16UL
#define SRSS_WDT_MATCH_IGNORE_BITS_Msk          0xF0000UL
/* SRSS.CLK_DSI_SELECT */
#define SRSS_CLK_DSI_SELECT_DSI_MUX_Pos         0UL
#define SRSS_CLK_DSI_SELECT_DSI_MUX_Msk         0x1FUL
/* SRSS.CLK_PATH_SELECT */
#define SRSS_CLK_PATH_SELECT_PATH_MUX_Pos       0UL
#define SRSS_CLK_PATH_SELECT_PATH_MUX_Msk       0x7UL
/* SRSS.CLK_ROOT_SELECT */
#define SRSS_CLK_ROOT_SELECT_ROOT_MUX_Pos       0UL
#define SRSS_CLK_ROOT_SELECT_ROOT_MUX_Msk       0xFUL
#define SRSS_CLK_ROOT_SELECT_ROOT_DIV_Pos       4UL
#define SRSS_CLK_ROOT_SELECT_ROOT_DIV_Msk       0x30UL
#define SRSS_CLK_ROOT_SELECT_ENABLE_Pos         31UL
#define SRSS_CLK_ROOT_SELECT_ENABLE_Msk         0x80000000UL
/* SRSS.CLK_SELECT */
#define SRSS_CLK_SELECT_LFCLK_SEL_Pos           0UL
#define SRSS_CLK_SELECT_LFCLK_SEL_Msk           0x3UL
#define SRSS_CLK_SELECT_PUMP_SEL_Pos            8UL
#define SRSS_CLK_SELECT_PUMP_SEL_Msk            0xF00UL
#define SRSS_CLK_SELECT_PUMP_DIV_Pos            12UL
#define SRSS_CLK_SELECT_PUMP_DIV_Msk            0x7000UL
#define SRSS_CLK_SELECT_PUMP_ENABLE_Pos         15UL
#define SRSS_CLK_SELECT_PUMP_ENABLE_Msk         0x8000UL
/* SRSS.CLK_TIMER_CTL */
#define SRSS_CLK_TIMER_CTL_TIMER_SEL_Pos        0UL
#define SRSS_CLK_TIMER_CTL_TIMER_SEL_Msk        0x1UL
#define SRSS_CLK_TIMER_CTL_TIMER_HF0_DIV_Pos    8UL
#define SRSS_CLK_TIMER_CTL_TIMER_HF0_DIV_Msk    0x300UL
#define SRSS_CLK_TIMER_CTL_TIMER_DIV_Pos        16UL
#define SRSS_CLK_TIMER_CTL_TIMER_DIV_Msk        0xFF0000UL
#define SRSS_CLK_TIMER_CTL_ENABLE_Pos           31UL
#define SRSS_CLK_TIMER_CTL_ENABLE_Msk           0x80000000UL
/* SRSS.CLK_ILO_CONFIG */
#define SRSS_CLK_ILO_CONFIG_ILO_BACKUP_Pos      0UL
#define SRSS_CLK_ILO_CONFIG_ILO_BACKUP_Msk      0x1UL
#define SRSS_CLK_ILO_CONFIG_ENABLE_Pos          31UL
#define SRSS_CLK_ILO_CONFIG_ENABLE_Msk          0x80000000UL
/* SRSS.CLK_IMO_CONFIG */
#define SRSS_CLK_IMO_CONFIG_ENABLE_Pos          31UL
#define SRSS_CLK_IMO_CONFIG_ENABLE_Msk          0x80000000UL
/* SRSS.CLK_OUTPUT_FAST */
#define SRSS_CLK_OUTPUT_FAST_FAST_SEL0_Pos      0UL
#define SRSS_CLK_OUTPUT_FAST_FAST_SEL0_Msk      0xFUL
#define SRSS_CLK_OUTPUT_FAST_PATH_SEL0_Pos      4UL
#define SRSS_CLK_OUTPUT_FAST_PATH_SEL0_Msk      0xF0UL
#define SRSS_CLK_OUTPUT_FAST_HFCLK_SEL0_Pos     8UL
#define SRSS_CLK_OUTPUT_FAST_HFCLK_SEL0_Msk     0xF00UL
#define SRSS_CLK_OUTPUT_FAST_FAST_SEL1_Pos      16UL
#define SRSS_CLK_OUTPUT_FAST_FAST_SEL1_Msk      0xF0000UL
#define SRSS_CLK_OUTPUT_FAST_PATH_SEL1_Pos      20UL
#define SRSS_CLK_OUTPUT_FAST_PATH_SEL1_Msk      0xF00000UL
#define SRSS_CLK_OUTPUT_FAST_HFCLK_SEL1_Pos     24UL
#define SRSS_CLK_OUTPUT_FAST_HFCLK_SEL1_Msk     0xF000000UL
/* SRSS.CLK_OUTPUT_SLOW */
#define SRSS_CLK_OUTPUT_SLOW_SLOW_SEL0_Pos      0UL
#define SRSS_CLK_OUTPUT_SLOW_SLOW_SEL0_Msk      0xFUL
#define SRSS_CLK_OUTPUT_SLOW_SLOW_SEL1_Pos      4UL
#define SRSS_CLK_OUTPUT_SLOW_SLOW_SEL1_Msk      0xF0UL
/* SRSS.CLK_CAL_CNT1 */
#define SRSS_CLK_CAL_CNT1_CAL_COUNTER1_Pos      0UL
#define SRSS_CLK_CAL_CNT1_CAL_COUNTER1_Msk      0xFFFFFFUL
#define SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE_Pos  31UL
#define SRSS_CLK_CAL_CNT1_CAL_COUNTER_DONE_Msk  0x80000000UL
/* SRSS.CLK_CAL_CNT2 */
#define SRSS_CLK_CAL_CNT2_CAL_COUNTER2_Pos      0UL
#define SRSS_CLK_CAL_CNT2_CAL_COUNTER2_Msk      0xFFFFFFUL
/* SRSS.CLK_ECO_CONFIG */
#define SRSS_CLK_ECO_CONFIG_AGC_EN_Pos          1UL
#define SRSS_CLK_ECO_CONFIG_AGC_EN_Msk          0x2UL
#define SRSS_CLK_ECO_CONFIG_ECO_EN_Pos          31UL
#define SRSS_CLK_ECO_CONFIG_ECO_EN_Msk          0x80000000UL
/* SRSS.CLK_ECO_STATUS */
#define SRSS_CLK_ECO_STATUS_ECO_OK_Pos          0UL
#define SRSS_CLK_ECO_STATUS_ECO_OK_Msk          0x1UL
#define SRSS_CLK_ECO_STATUS_ECO_READY_Pos       1UL
#define SRSS_CLK_ECO_STATUS_ECO_READY_Msk       0x2UL
/* SRSS.CLK_PILO_CONFIG */
#define SRSS_CLK_PILO_CONFIG_PILO_FFREQ_Pos     0UL
#define SRSS_CLK_PILO_CONFIG_PILO_FFREQ_Msk     0x3FFUL
#define SRSS_CLK_PILO_CONFIG_PILO_CLK_EN_Pos    29UL
#define SRSS_CLK_PILO_CONFIG_PILO_CLK_EN_Msk    0x20000000UL
#define SRSS_CLK_PILO_CONFIG_PILO_RESET_N_Pos   30UL
#define SRSS_CLK_PILO_CONFIG_PILO_RESET_N_Msk   0x40000000UL
#define SRSS_CLK_PILO_CONFIG_PILO_EN_Pos        31UL
#define SRSS_CLK_PILO_CONFIG_PILO_EN_Msk        0x80000000UL
/* SRSS.CLK_MF_SELECT */
#define SRSS_CLK_MF_SELECT_MFCLK_SEL_Pos        0UL
#define SRSS_CLK_MF_SELECT_MFCLK_SEL_Msk        0x7UL
#define SRSS_CLK_MF_SELECT_MFCLK_DIV_Pos        8UL
#define SRSS_CLK_MF_SELECT_MFCLK_DIV_Msk        0xFF00UL
#define SRSS_CLK_MF_SELECT_ENABLE_Pos           31UL
#define SRSS_CLK_MF_SELECT_ENABLE_Msk           0x80000000UL
/* SRSS.CLK_MFO_CONFIG */
#define SRSS_CLK_MFO_CONFIG_DPSLP_ENABLE_Pos    30UL
#define SRSS_CLK_MFO_CONFIG_DPSLP_ENABLE_Msk    0x40000000UL
#define SRSS_CLK_MFO_CONFIG_ENABLE_Pos          31UL
#define SRSS_CLK_MFO_CONFIG_ENABLE_Msk          0x80000000UL
/* SRSS.CLK_FLL_CONFIG */
#define SRSS_CLK_FLL_CONFIG_FLL_MULT_Pos        0UL
#define SRSS_CLK_FLL_CONFIG_FLL_MULT_Msk        0x3FFFFUL
#define SRSS_CLK_FLL_CONFIG_FLL_OUTPUT_DIV_Pos  24UL
#define SRSS_CLK_FLL_CONFIG_FLL_OUTPUT_DIV_Msk  0x1000000UL
#define SRSS_CLK_FLL_CONFIG_FLL_ENABLE_Pos      31UL
#define SRSS_CLK_FLL_CONFIG_FLL_ENABLE_Msk      0x80000000UL
/* SRSS.CLK_FLL_CONFIG2 */
#define SRSS_CLK_FLL_CONFIG2_FLL_REF_DIV_Pos    0UL
#define SRSS_CLK_FLL_CONFIG2_FLL_REF_DIV_Msk    0x1FFFUL
#define SRSS_CLK_FLL_CONFIG2_LOCK_TOL_Pos       16UL
#define SRSS_CLK_FLL_CONFIG2_LOCK_TOL_Msk       0x1FF0000UL
/* SRSS.CLK_FLL_CONFIG3 */
#define SRSS_CLK_FLL_CONFIG3_FLL_LF_IGAIN_Pos   0UL
#define SRSS_CLK_FLL_CONFIG3_FLL_LF_IGAIN_Msk   0xFUL
#define SRSS_CLK_FLL_CONFIG3_FLL_LF_PGAIN_Pos   4UL
#define SRSS_CLK_FLL_CONFIG3_FLL_LF_PGAIN_Msk   0xF0UL
#define SRSS_CLK_FLL_CONFIG3_SETTLING_COUNT_Pos 8UL
#define SRSS_CLK_FLL_CONFIG3_SETTLING_COUNT_Msk 0x1FFF00UL
#define SRSS_CLK_FLL_CONFIG3_BYPASS_SEL_Pos     28UL
#define SRSS_CLK_FLL_CONFIG3_BYPASS_SEL_Msk     0x30000000UL
/* SRSS.CLK_FLL_CONFIG4 */
#define SRSS_CLK_FLL_CONFIG4_CCO_LIMIT_Pos      0UL
#define SRSS_CLK_FLL_CONFIG4_CCO_LIMIT_Msk      0xFFUL
#define SRSS_CLK_FLL_CONFIG4_CCO_RANGE_Pos      8UL
#define SRSS_CLK_FLL_CONFIG4_CCO_RANGE_Msk      0x700UL
#define SRSS_CLK_FLL_CONFIG4_CCO_FREQ_Pos       16UL
#define SRSS_CLK_FLL_CONFIG4_CCO_FREQ_Msk       0x1FF0000UL
#define SRSS_CLK_FLL_CONFIG4_CCO_HW_UPDATE_DIS_Pos 30UL
#define SRSS_CLK_FLL_CONFIG4_CCO_HW_UPDATE_DIS_Msk 0x40000000UL
#define SRSS_CLK_FLL_CONFIG4_CCO_ENABLE_Pos     31UL
#define SRSS_CLK_FLL_CONFIG4_CCO_ENABLE_Msk     0x80000000UL
/* SRSS.CLK_FLL_STATUS */
#define SRSS_CLK_FLL_STATUS_LOCKED_Pos          0UL
#define SRSS_CLK_FLL_STATUS_LOCKED_Msk          0x1UL
#define SRSS_CLK_FLL_STATUS_UNLOCK_OCCURRED_Pos 1UL
#define SRSS_CLK_FLL_STATUS_UNLOCK_OCCURRED_Msk 0x2UL
#define SRSS_CLK_FLL_STATUS_CCO_READY_Pos       2UL
#define SRSS_CLK_FLL_STATUS_CCO_READY_Msk       0x4UL
/* SRSS.CLK_PLL_CONFIG */
#define SRSS_CLK_PLL_CONFIG_FEEDBACK_DIV_Pos    0UL
#define SRSS_CLK_PLL_CONFIG_FEEDBACK_DIV_Msk    0x7FUL
#define SRSS_CLK_PLL_CONFIG_REFERENCE_DIV_Pos   8UL
#define SRSS_CLK_PLL_CONFIG_REFERENCE_DIV_Msk   0x1F00UL
#define SRSS_CLK_PLL_CONFIG_OUTPUT_DIV_Pos      16UL
#define SRSS_CLK_PLL_CONFIG_OUTPUT_DIV_Msk      0x1F0000UL
#define SRSS_CLK_PLL_CONFIG_PLL_LF_MODE_Pos     27UL
#define SRSS_CLK_PLL_CONFIG_PLL_LF_MODE_Msk     0x8000000UL
#define SRSS_CLK_PLL_CONFIG_BYPASS_SEL_Pos      28UL
#define SRSS_CLK_PLL_CONFIG_BYPASS_SEL_Msk      0x30000000UL
#define SRSS_CLK_PLL_CONFIG_ENABLE_Pos          31UL
#define SRSS_CLK_PLL_CONFIG_ENABLE_Msk          0x80000000UL
/* SRSS.CLK_PLL_STATUS */
#define SRSS_CLK_PLL_STATUS_LOCKED_Pos          0UL
#define SRSS_CLK_PLL_STATUS_LOCKED_Msk          0x1UL
#define SRSS_CLK_PLL_STATUS_UNLOCK_OCCURRED_Pos 1UL
#define SRSS_CLK_PLL_STATUS_UNLOCK_OCCURRED_Msk 0x2UL
/* SRSS.SRSS_INTR */
#define SRSS_SRSS_INTR_WDT_MATCH_Pos            0UL
#define SRSS_SRSS_INTR_WDT_MATCH_Msk            0x1UL
#define SRSS_SRSS_INTR_HVLVD1_Pos               1UL
#define SRSS_SRSS_INTR_HVLVD1_Msk               0x2UL
#define SRSS_SRSS_INTR_CLK_CAL_Pos              5UL
#define SRSS_SRSS_INTR_CLK_CAL_Msk              0x20UL
/* SRSS.SRSS_INTR_SET */
#define SRSS_SRSS_INTR_SET_WDT_MATCH_Pos        0UL
#define SRSS_SRSS_INTR_SET_WDT_MATCH_Msk        0x1UL
#define SRSS_SRSS_INTR_SET_HVLVD1_Pos           1UL
#define SRSS_SRSS_INTR_SET_HVLVD1_Msk           0x2UL
#define SRSS_SRSS_INTR_SET_CLK_CAL_Pos          5UL
#define SRSS_SRSS_INTR_SET_CLK_CAL_Msk          0x20UL
/* SRSS.SRSS_INTR_MASK */
#define SRSS_SRSS_INTR_MASK_WDT_MATCH_Pos       0UL
#define SRSS_SRSS_INTR_MASK_WDT_MATCH_Msk       0x1UL
#define SRSS_SRSS_INTR_MASK_HVLVD1_Pos          1UL
#define SRSS_SRSS_INTR_MASK_HVLVD1_Msk          0x2UL
#define SRSS_SRSS_INTR_MASK_CLK_CAL_Pos         5UL
#define SRSS_SRSS_INTR_MASK_CLK_CAL_Msk         0x20UL
/* SRSS.SRSS_INTR_MASKED */
#define SRSS_SRSS_INTR_MASKED_WDT_MATCH_Pos     0UL
#define SRSS_SRSS_INTR_MASKED_WDT_MATCH_Msk     0x1UL
#define SRSS_SRSS_INTR_MASKED_HVLVD1_Pos        1UL
#define SRSS_SRSS_INTR_MASKED_HVLVD1_Msk        0x2UL
#define SRSS_SRSS_INTR_MASKED_CLK_CAL_Pos       5UL
#define SRSS_SRSS_INTR_MASKED_CLK_CAL_Msk       0x20UL
/* SRSS.SRSS_INTR_CFG */
#define SRSS_SRSS_INTR_CFG_HVLVD1_EDGE_SEL_Pos  0UL
#define SRSS_SRSS_INTR_CFG_HVLVD1_EDGE_SEL_Msk  0x3UL
/* SRSS.RES_CAUSE */
#define SRSS_RES_CAUSE_RESET_WDT_Pos            0UL
#define SRSS_RES_CAUSE_RESET_WDT_Msk            0x1UL
#define SRSS_RES_CAUSE_RESET_ACT_FAULT_Pos      1UL
#define SRSS_RES_CAUSE_RESET_ACT_FAULT_Msk      0x2UL
#define SRSS_RES_CAUSE_RESET_DPSLP_FAULT_Pos    2UL
#define SRSS_RES_CAUSE_RESET_DPSLP_FAULT_Msk    0x4UL
#define SRSS_RES_CAUSE_RESET_CSV_WCO_LOSS_Pos   3UL
#define SRSS_RES_CAUSE_RESET_CSV_WCO_LOSS_Msk   0x8UL
#define SRSS_RES_CAUSE_RESET_SOFT_Pos           4UL
#define SRSS_RES_CAUSE_RESET_SOFT_Msk           0x10UL
#define SRSS_RES_CAUSE_RESET_MCWDT0_Pos         5UL
#define SRSS_RES_CAUSE_RESET_MCWDT0_Msk         0x20UL
#define SRSS_RES_CAUSE_RESET_MCWDT1_Pos         6UL
#define SRSS_RES_CAUSE_RESET_MCWDT1_Msk         0x40UL
#define SRSS_RES_CAUSE_RESET_MCWDT2_Pos         7UL
#define SRSS_RES_CAUSE_RESET_MCWDT2_Msk         0x80UL
#define SRSS_RES_CAUSE_RESET_MCWDT3_Pos         8UL
#define SRSS_RES_CAUSE_RESET_MCWDT3_Msk         0x100UL
/* SRSS.RES_CAUSE2 */
#define SRSS_RES_CAUSE2_RESET_CSV_HF_LOSS_Pos   0UL
#define SRSS_RES_CAUSE2_RESET_CSV_HF_LOSS_Msk   0xFFFFUL
#define SRSS_RES_CAUSE2_RESET_CSV_HF_FREQ_Pos   16UL
#define SRSS_RES_CAUSE2_RESET_CSV_HF_FREQ_Msk   0xFFFF0000UL
/* SRSS.PWR_TRIM_REF_CTL */
#define SRSS_PWR_TRIM_REF_CTL_ACT_REF_TCTRIM_Pos 0UL
#define SRSS_PWR_TRIM_REF_CTL_ACT_REF_TCTRIM_Msk 0xFUL
#define SRSS_PWR_TRIM_REF_CTL_ACT_REF_ITRIM_Pos 4UL
#define SRSS_PWR_TRIM_REF_CTL_ACT_REF_ITRIM_Msk 0xF0UL
#define SRSS_PWR_TRIM_REF_CTL_ACT_REF_ABSTRIM_Pos 8UL
#define SRSS_PWR_TRIM_REF_CTL_ACT_REF_ABSTRIM_Msk 0x1F00UL
#define SRSS_PWR_TRIM_REF_CTL_ACT_REF_IBOOST_Pos 14UL
#define SRSS_PWR_TRIM_REF_CTL_ACT_REF_IBOOST_Msk 0x4000UL
#define SRSS_PWR_TRIM_REF_CTL_DPSLP_REF_TCTRIM_Pos 16UL
#define SRSS_PWR_TRIM_REF_CTL_DPSLP_REF_TCTRIM_Msk 0xF0000UL
#define SRSS_PWR_TRIM_REF_CTL_DPSLP_REF_ABSTRIM_Pos 20UL
#define SRSS_PWR_TRIM_REF_CTL_DPSLP_REF_ABSTRIM_Msk 0x1F00000UL
#define SRSS_PWR_TRIM_REF_CTL_DPSLP_REF_ITRIM_Pos 28UL
#define SRSS_PWR_TRIM_REF_CTL_DPSLP_REF_ITRIM_Msk 0xF0000000UL
/* SRSS.PWR_TRIM_BODOVP_CTL */
#define SRSS_PWR_TRIM_BODOVP_CTL_HVPORBOD_TRIPSEL_Pos 0UL
#define SRSS_PWR_TRIM_BODOVP_CTL_HVPORBOD_TRIPSEL_Msk 0x7UL
#define SRSS_PWR_TRIM_BODOVP_CTL_HVPORBOD_OFSTRIM_Pos 4UL
#define SRSS_PWR_TRIM_BODOVP_CTL_HVPORBOD_OFSTRIM_Msk 0x70UL
#define SRSS_PWR_TRIM_BODOVP_CTL_HVPORBOD_ITRIM_Pos 7UL
#define SRSS_PWR_TRIM_BODOVP_CTL_HVPORBOD_ITRIM_Msk 0x380UL
#define SRSS_PWR_TRIM_BODOVP_CTL_LVPORBOD_TRIPSEL_Pos 10UL
#define SRSS_PWR_TRIM_BODOVP_CTL_LVPORBOD_TRIPSEL_Msk 0x1C00UL
#define SRSS_PWR_TRIM_BODOVP_CTL_LVPORBOD_OFSTRIM_Pos 14UL
#define SRSS_PWR_TRIM_BODOVP_CTL_LVPORBOD_OFSTRIM_Msk 0x1C000UL
#define SRSS_PWR_TRIM_BODOVP_CTL_LVPORBOD_ITRIM_Pos 17UL
#define SRSS_PWR_TRIM_BODOVP_CTL_LVPORBOD_ITRIM_Msk 0xE0000UL
/* SRSS.CLK_TRIM_CCO_CTL */
#define SRSS_CLK_TRIM_CCO_CTL_CCO_RCSTRIM_Pos   0UL
#define SRSS_CLK_TRIM_CCO_CTL_CCO_RCSTRIM_Msk   0x3FUL
#define SRSS_CLK_TRIM_CCO_CTL_CCO_STABLE_CNT_Pos 24UL
#define SRSS_CLK_TRIM_CCO_CTL_CCO_STABLE_CNT_Msk 0x3F000000UL
#define SRSS_CLK_TRIM_CCO_CTL_ENABLE_CNT_Pos    31UL
#define SRSS_CLK_TRIM_CCO_CTL_ENABLE_CNT_Msk    0x80000000UL
/* SRSS.CLK_TRIM_CCO_CTL2 */
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM1_Pos  0UL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM1_Msk  0x1FUL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM2_Pos  5UL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM2_Msk  0x3E0UL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM3_Pos  10UL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM3_Msk  0x7C00UL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM4_Pos  15UL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM4_Msk  0xF8000UL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM5_Pos  20UL
#define SRSS_CLK_TRIM_CCO_CTL2_CCO_FCTRIM5_Msk  0x1F00000UL
/* SRSS.PWR_TRIM_WAKE_CTL */
#define SRSS_PWR_TRIM_WAKE_CTL_WAKE_DELAY_Pos   0UL
#define SRSS_PWR_TRIM_WAKE_CTL_WAKE_DELAY_Msk   0xFFUL
/* SRSS.PWR_TRIM_LVD_CTL */
#define SRSS_PWR_TRIM_LVD_CTL_HVLVD1_OFSTRIM_Pos 0UL
#define SRSS_PWR_TRIM_LVD_CTL_HVLVD1_OFSTRIM_Msk 0x7UL
#define SRSS_PWR_TRIM_LVD_CTL_HVLVD1_ITRIM_Pos  4UL
#define SRSS_PWR_TRIM_LVD_CTL_HVLVD1_ITRIM_Msk  0x70UL
/* SRSS.CLK_TRIM_ILO_CTL */
#define SRSS_CLK_TRIM_ILO_CTL_ILO_FTRIM_Pos     0UL
#define SRSS_CLK_TRIM_ILO_CTL_ILO_FTRIM_Msk     0x3FUL
/* SRSS.PWR_TRIM_PWRSYS_CTL */
#define SRSS_PWR_TRIM_PWRSYS_CTL_ACT_REG_TRIM_Pos 0UL
#define SRSS_PWR_TRIM_PWRSYS_CTL_ACT_REG_TRIM_Msk 0x1FUL
#define SRSS_PWR_TRIM_PWRSYS_CTL_ACT_REG_BOOST_Pos 30UL
#define SRSS_PWR_TRIM_PWRSYS_CTL_ACT_REG_BOOST_Msk 0xC0000000UL
/* SRSS.CLK_TRIM_ECO_CTL */
#define SRSS_CLK_TRIM_ECO_CTL_WDTRIM_Pos        0UL
#define SRSS_CLK_TRIM_ECO_CTL_WDTRIM_Msk        0x7UL
#define SRSS_CLK_TRIM_ECO_CTL_ATRIM_Pos         4UL
#define SRSS_CLK_TRIM_ECO_CTL_ATRIM_Msk         0xF0UL
#define SRSS_CLK_TRIM_ECO_CTL_FTRIM_Pos         8UL
#define SRSS_CLK_TRIM_ECO_CTL_FTRIM_Msk         0x300UL
#define SRSS_CLK_TRIM_ECO_CTL_RTRIM_Pos         10UL
#define SRSS_CLK_TRIM_ECO_CTL_RTRIM_Msk         0xC00UL
#define SRSS_CLK_TRIM_ECO_CTL_GTRIM_Pos         12UL
#define SRSS_CLK_TRIM_ECO_CTL_GTRIM_Msk         0x3000UL
#define SRSS_CLK_TRIM_ECO_CTL_ITRIM_Pos         16UL
#define SRSS_CLK_TRIM_ECO_CTL_ITRIM_Msk         0x3F0000UL
/* SRSS.CLK_TRIM_PILO_CTL */
#define SRSS_CLK_TRIM_PILO_CTL_PILO_CFREQ_Pos   0UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_CFREQ_Msk   0x3FUL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_OSC_TRIM_Pos 12UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_OSC_TRIM_Msk 0x7000UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_COMP_TRIM_Pos 16UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_COMP_TRIM_Msk 0x30000UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_NBIAS_TRIM_Pos 18UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_NBIAS_TRIM_Msk 0xC0000UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_RES_TRIM_Pos 20UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_RES_TRIM_Msk 0x1F00000UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_ISLOPE_TRIM_Pos 26UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_ISLOPE_TRIM_Msk 0xC000000UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_VTDIFF_TRIM_Pos 28UL
#define SRSS_CLK_TRIM_PILO_CTL_PILO_VTDIFF_TRIM_Msk 0x70000000UL
/* SRSS.CLK_TRIM_PILO_CTL2 */
#define SRSS_CLK_TRIM_PILO_CTL2_PILO_VREF_TRIM_Pos 0UL
#define SRSS_CLK_TRIM_PILO_CTL2_PILO_VREF_TRIM_Msk 0xFFUL
#define SRSS_CLK_TRIM_PILO_CTL2_PILO_IREFBM_TRIM_Pos 8UL
#define SRSS_CLK_TRIM_PILO_CTL2_PILO_IREFBM_TRIM_Msk 0x1F00UL
#define SRSS_CLK_TRIM_PILO_CTL2_PILO_IREF_TRIM_Pos 16UL
#define SRSS_CLK_TRIM_PILO_CTL2_PILO_IREF_TRIM_Msk 0xFF0000UL
/* SRSS.CLK_TRIM_PILO_CTL3 */
#define SRSS_CLK_TRIM_PILO_CTL3_PILO_ENGOPT_Pos 0UL
#define SRSS_CLK_TRIM_PILO_CTL3_PILO_ENGOPT_Msk 0xFFFFUL


#endif /* _CYIP_SRSS_H_ */


/* [] END OF FILE */
