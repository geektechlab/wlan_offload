/***************************************************************************//**
* \file cyip_cpuss_v2_1.h
*
* \brief
* CPUSS IP definitions
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

#ifndef _CYIP_CPUSS_V2_1_H_
#define _CYIP_CPUSS_V2_1_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    CPUSS
*******************************************************************************/

#define CPUSS_SECTION_SIZE                      0x00004000UL

/**
  * \brief SYSCPUSS registers (CPUSS)
  */
typedef struct {
   __IM uint32_t IDENTITY;                      /*!< 0x00000000 Identity */
   __IM uint32_t RESERVED[3];
   __IM uint32_t PRODUCT_ID;                    /*!< 0x00000010 Product identifier and version (same as CoreSight RomTables) */
   __IM uint32_t RESERVED1[3];
   __IM uint32_t DP_STATUS;                     /*!< 0x00000020 Debug port status */
   __IM uint32_t RESERVED2[3];
  __IOM uint32_t BUFF_CTL;                      /*!< 0x00000030 Buffer control */
   __IM uint32_t RESERVED3[3];
  __IOM uint32_t CAL_SUP_SET;                   /*!< 0x00000040 Calibration support set and read */
  __IOM uint32_t CAL_SUP_CLR;                   /*!< 0x00000044 Calibration support clear and reset */
   __IM uint32_t RESERVED4[2];
  __IOM uint32_t INFRA_CTL;                     /*!< 0x00000050 Infrastructure Control */
   __IM uint32_t RESERVED5[43];
  __IOM uint32_t SYSTICK_S_CTL;                 /*!< 0x00000100 Secure SysTick timer control */
   __IM uint32_t RESERVED6[7];
  __IOM uint32_t SYSTICK_NS_CTL;                /*!< 0x00000120 Non Secure SysTick timer control */
   __IM uint32_t RESERVED7[55];
  __IOM uint32_t INTR_MSC;                      /*!< 0x00000200 Master security controller Interrupt */
   __IM uint32_t RESERVED8;
  __IOM uint32_t INTR_MASK_MSC;                 /*!< 0x00000208 Master security controller Interrupt mask */
   __IM uint32_t INTR_MASKED_MSC;               /*!< 0x0000020C Master security controller Interrupt masked */
   __IM uint32_t RESERVED9[892];
  __IOM uint32_t AP_CTL;                        /*!< 0x00001000 Access port control */
   __IM uint32_t RESERVED10[1024];
  __IOM uint32_t PROTECTION;                    /*!< 0x00002004 Protection status */
} CPUSS_Type;                                   /*!< Size = 8200 (0x2008) */


/* CPUSS.IDENTITY */
#define CPUSS_IDENTITY_P_Pos                    0UL
#define CPUSS_IDENTITY_P_Msk                    0x1UL
#define CPUSS_IDENTITY_NS_Pos                   1UL
#define CPUSS_IDENTITY_NS_Msk                   0x2UL
#define CPUSS_IDENTITY_PC_Pos                   4UL
#define CPUSS_IDENTITY_PC_Msk                   0xF0UL
#define CPUSS_IDENTITY_MS_Pos                   8UL
#define CPUSS_IDENTITY_MS_Msk                   0xFF00UL
/* CPUSS.PRODUCT_ID */
#define CPUSS_PRODUCT_ID_FAMILY_ID_Pos          0UL
#define CPUSS_PRODUCT_ID_FAMILY_ID_Msk          0xFFFUL
#define CPUSS_PRODUCT_ID_MAJOR_REV_Pos          16UL
#define CPUSS_PRODUCT_ID_MAJOR_REV_Msk          0xF0000UL
#define CPUSS_PRODUCT_ID_MINOR_REV_Pos          20UL
#define CPUSS_PRODUCT_ID_MINOR_REV_Msk          0xF00000UL
/* CPUSS.DP_STATUS */
#define CPUSS_DP_STATUS_SWJ_CONNECTED_Pos       0UL
#define CPUSS_DP_STATUS_SWJ_CONNECTED_Msk       0x1UL
#define CPUSS_DP_STATUS_SWJ_DEBUG_EN_Pos        1UL
#define CPUSS_DP_STATUS_SWJ_DEBUG_EN_Msk        0x2UL
#define CPUSS_DP_STATUS_SWJ_JTAG_SEL_Pos        2UL
#define CPUSS_DP_STATUS_SWJ_JTAG_SEL_Msk        0x4UL
#define CPUSS_DP_STATUS_SWJ_SWD_SEL_Pos         3UL
#define CPUSS_DP_STATUS_SWJ_SWD_SEL_Msk         0x8UL
/* CPUSS.BUFF_CTL */
#define CPUSS_BUFF_CTL_WRITE_BUFF_Pos           0UL
#define CPUSS_BUFF_CTL_WRITE_BUFF_Msk           0x1UL
/* CPUSS.CAL_SUP_SET */
#define CPUSS_CAL_SUP_SET_DATA_Pos              0UL
#define CPUSS_CAL_SUP_SET_DATA_Msk              0xFFFFFFFFUL
/* CPUSS.CAL_SUP_CLR */
#define CPUSS_CAL_SUP_CLR_DATA_Pos              0UL
#define CPUSS_CAL_SUP_CLR_DATA_Msk              0xFFFFFFFFUL
/* CPUSS.INFRA_CTL */
#define CPUSS_INFRA_CTL_CLOCK_FORCE_Pos         0UL
#define CPUSS_INFRA_CTL_CLOCK_FORCE_Msk         0x1UL
/* CPUSS.SYSTICK_S_CTL */
#define CPUSS_SYSTICK_S_CTL_TENMS_Pos           0UL
#define CPUSS_SYSTICK_S_CTL_TENMS_Msk           0xFFFFFFUL
#define CPUSS_SYSTICK_S_CTL_CLOCK_SOURCE_Pos    24UL
#define CPUSS_SYSTICK_S_CTL_CLOCK_SOURCE_Msk    0x3000000UL
#define CPUSS_SYSTICK_S_CTL_SKEW_Pos            30UL
#define CPUSS_SYSTICK_S_CTL_SKEW_Msk            0x40000000UL
#define CPUSS_SYSTICK_S_CTL_NOREF_Pos           31UL
#define CPUSS_SYSTICK_S_CTL_NOREF_Msk           0x80000000UL
/* CPUSS.SYSTICK_NS_CTL */
#define CPUSS_SYSTICK_NS_CTL_TENMS_Pos          0UL
#define CPUSS_SYSTICK_NS_CTL_TENMS_Msk          0xFFFFFFUL
#define CPUSS_SYSTICK_NS_CTL_CLOCK_SOURCE_Pos   24UL
#define CPUSS_SYSTICK_NS_CTL_CLOCK_SOURCE_Msk   0x3000000UL
#define CPUSS_SYSTICK_NS_CTL_SKEW_Pos           30UL
#define CPUSS_SYSTICK_NS_CTL_SKEW_Msk           0x40000000UL
#define CPUSS_SYSTICK_NS_CTL_NOREF_Pos          31UL
#define CPUSS_SYSTICK_NS_CTL_NOREF_Msk          0x80000000UL
/* CPUSS.INTR_MSC */
#define CPUSS_INTR_MSC_CODE_MS0_MSC_Pos         0UL
#define CPUSS_INTR_MSC_CODE_MS0_MSC_Msk         0x1UL
#define CPUSS_INTR_MSC_SYS_MS0_MSC_Pos          1UL
#define CPUSS_INTR_MSC_SYS_MS0_MSC_Msk          0x2UL
#define CPUSS_INTR_MSC_SYS_MS1_MSC_Pos          2UL
#define CPUSS_INTR_MSC_SYS_MS1_MSC_Msk          0x4UL
#define CPUSS_INTR_MSC_EXP_MS_MSC_Pos           3UL
#define CPUSS_INTR_MSC_EXP_MS_MSC_Msk           0x8UL
#define CPUSS_INTR_MSC_DMAC0_MSC_Pos            4UL
#define CPUSS_INTR_MSC_DMAC0_MSC_Msk            0x10UL
#define CPUSS_INTR_MSC_DMAC1_MSC_Pos            5UL
#define CPUSS_INTR_MSC_DMAC1_MSC_Msk            0x20UL
/* CPUSS.INTR_MASK_MSC */
#define CPUSS_INTR_MASK_MSC_CODE_MS0_MSC_Pos    0UL
#define CPUSS_INTR_MASK_MSC_CODE_MS0_MSC_Msk    0x1UL
#define CPUSS_INTR_MASK_MSC_SYS_MS0_MSC_Pos     1UL
#define CPUSS_INTR_MASK_MSC_SYS_MS0_MSC_Msk     0x2UL
#define CPUSS_INTR_MASK_MSC_SYS_MS1_MSC_Pos     2UL
#define CPUSS_INTR_MASK_MSC_SYS_MS1_MSC_Msk     0x4UL
#define CPUSS_INTR_MASK_MSC_EXP_MS_MSC_Pos      3UL
#define CPUSS_INTR_MASK_MSC_EXP_MS_MSC_Msk      0x8UL
#define CPUSS_INTR_MASK_MSC_DMAC0_MSC_Pos       4UL
#define CPUSS_INTR_MASK_MSC_DMAC0_MSC_Msk       0x10UL
#define CPUSS_INTR_MASK_MSC_DMAC1_MSC_Pos       5UL
#define CPUSS_INTR_MASK_MSC_DMAC1_MSC_Msk       0x20UL
/* CPUSS.INTR_MASKED_MSC */
#define CPUSS_INTR_MASKED_MSC_CODE_MS0_MSC_Pos  0UL
#define CPUSS_INTR_MASKED_MSC_CODE_MS0_MSC_Msk  0x1UL
#define CPUSS_INTR_MASKED_MSC_SYS_MS0_MSC_Pos   1UL
#define CPUSS_INTR_MASKED_MSC_SYS_MS0_MSC_Msk   0x2UL
#define CPUSS_INTR_MASKED_MSC_SYS_MS1_MSC_Pos   2UL
#define CPUSS_INTR_MASKED_MSC_SYS_MS1_MSC_Msk   0x4UL
#define CPUSS_INTR_MASKED_MSC_EXP_MS_MSC_Pos    3UL
#define CPUSS_INTR_MASKED_MSC_EXP_MS_MSC_Msk    0x8UL
#define CPUSS_INTR_MASKED_MSC_DMAC0_MSC_Pos     4UL
#define CPUSS_INTR_MASKED_MSC_DMAC0_MSC_Msk     0x10UL
#define CPUSS_INTR_MASKED_MSC_DMAC1_MSC_Pos     5UL
#define CPUSS_INTR_MASKED_MSC_DMAC1_MSC_Msk     0x20UL
/* CPUSS.AP_CTL */
#define CPUSS_AP_CTL_CM33_0_ENABLE_Pos          0UL
#define CPUSS_AP_CTL_CM33_0_ENABLE_Msk          0x1UL
#define CPUSS_AP_CTL_CM33_1_ENABLE_Pos          1UL
#define CPUSS_AP_CTL_CM33_1_ENABLE_Msk          0x2UL
#define CPUSS_AP_CTL_SYS_ENABLE_Pos             2UL
#define CPUSS_AP_CTL_SYS_ENABLE_Msk             0x4UL
#define CPUSS_AP_CTL_CM33_0_DBG_ENABLE_Pos      4UL
#define CPUSS_AP_CTL_CM33_0_DBG_ENABLE_Msk      0x10UL
#define CPUSS_AP_CTL_CM33_0_NID_ENABLE_Pos      5UL
#define CPUSS_AP_CTL_CM33_0_NID_ENABLE_Msk      0x20UL
#define CPUSS_AP_CTL_CM33_0_SPID_ENABLE_Pos     6UL
#define CPUSS_AP_CTL_CM33_0_SPID_ENABLE_Msk     0x40UL
#define CPUSS_AP_CTL_CM33_0_SPNID_ENABLE_Pos    7UL
#define CPUSS_AP_CTL_CM33_0_SPNID_ENABLE_Msk    0x80UL
#define CPUSS_AP_CTL_CM33_1_DBG_ENABLE_Pos      8UL
#define CPUSS_AP_CTL_CM33_1_DBG_ENABLE_Msk      0x100UL
#define CPUSS_AP_CTL_CM33_1_NID_ENABLE_Pos      9UL
#define CPUSS_AP_CTL_CM33_1_NID_ENABLE_Msk      0x200UL
#define CPUSS_AP_CTL_CM33_1_SPID_ENABLE_Pos     10UL
#define CPUSS_AP_CTL_CM33_1_SPID_ENABLE_Msk     0x400UL
#define CPUSS_AP_CTL_CM33_1_SPNID_ENABLE_Pos    11UL
#define CPUSS_AP_CTL_CM33_1_SPNID_ENABLE_Msk    0x800UL
#define CPUSS_AP_CTL_CM33_0_SECURE_ENABLE_Pos   12UL
#define CPUSS_AP_CTL_CM33_0_SECURE_ENABLE_Msk   0x1000UL
#define CPUSS_AP_CTL_CM33_1_SECURE_ENABLE_Pos   13UL
#define CPUSS_AP_CTL_CM33_1_SECURE_ENABLE_Msk   0x2000UL
#define CPUSS_AP_CTL_SYS_SECURE_ENABLE_Pos      14UL
#define CPUSS_AP_CTL_SYS_SECURE_ENABLE_Msk      0x4000UL
#define CPUSS_AP_CTL_CM33_0_DISABLE_Pos         16UL
#define CPUSS_AP_CTL_CM33_0_DISABLE_Msk         0x10000UL
#define CPUSS_AP_CTL_CM33_1_DISABLE_Pos         17UL
#define CPUSS_AP_CTL_CM33_1_DISABLE_Msk         0x20000UL
#define CPUSS_AP_CTL_SYS_DISABLE_Pos            18UL
#define CPUSS_AP_CTL_SYS_DISABLE_Msk            0x40000UL
#define CPUSS_AP_CTL_CM33_0_DBG_DISABLE_Pos     20UL
#define CPUSS_AP_CTL_CM33_0_DBG_DISABLE_Msk     0x100000UL
#define CPUSS_AP_CTL_CM33_0_NID_DISABLE_Pos     21UL
#define CPUSS_AP_CTL_CM33_0_NID_DISABLE_Msk     0x200000UL
#define CPUSS_AP_CTL_CM33_0_SPID_DISABLE_Pos    22UL
#define CPUSS_AP_CTL_CM33_0_SPID_DISABLE_Msk    0x400000UL
#define CPUSS_AP_CTL_CM33_0_SPNID_DISABLE_Pos   23UL
#define CPUSS_AP_CTL_CM33_0_SPNID_DISABLE_Msk   0x800000UL
#define CPUSS_AP_CTL_CM33_1_DBG_DISABLE_Pos     24UL
#define CPUSS_AP_CTL_CM33_1_DBG_DISABLE_Msk     0x1000000UL
#define CPUSS_AP_CTL_CM33_1_NID_DISABLE_Pos     25UL
#define CPUSS_AP_CTL_CM33_1_NID_DISABLE_Msk     0x2000000UL
#define CPUSS_AP_CTL_CM33_1_SPID_DISABLE_Pos    26UL
#define CPUSS_AP_CTL_CM33_1_SPID_DISABLE_Msk    0x4000000UL
#define CPUSS_AP_CTL_CM33_1_SPNID_DISABLE_Pos   27UL
#define CPUSS_AP_CTL_CM33_1_SPNID_DISABLE_Msk   0x8000000UL
#define CPUSS_AP_CTL_CM33_0_SECURE_DISABLE_Pos  28UL
#define CPUSS_AP_CTL_CM33_0_SECURE_DISABLE_Msk  0x10000000UL
#define CPUSS_AP_CTL_CM33_1_SECURE_DISABLE_Pos  29UL
#define CPUSS_AP_CTL_CM33_1_SECURE_DISABLE_Msk  0x20000000UL
#define CPUSS_AP_CTL_SYS_SECURE_DISABLE_Pos     30UL
#define CPUSS_AP_CTL_SYS_SECURE_DISABLE_Msk     0x40000000UL
/* CPUSS.PROTECTION */
#define CPUSS_PROTECTION_STATE_Pos              0UL
#define CPUSS_PROTECTION_STATE_Msk              0xFFFFFFFFUL


#endif /* _CYIP_CPUSS_V2_1_H_ */


/* [] END OF FILE */
