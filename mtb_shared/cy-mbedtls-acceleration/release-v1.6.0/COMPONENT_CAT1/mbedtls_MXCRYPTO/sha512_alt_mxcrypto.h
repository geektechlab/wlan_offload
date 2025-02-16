/*
 *  mbed Microcontroller Library
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  Copyright (c) (2019-2024), Cypress Semiconductor Corporation (an Infineon company) or
 *  an affiliate of Cypress Semiconductor Corporation.
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/**
 * \file    sha512_alt_mxcrypto.h
 * \version 1.6
 *
 * \brief   header file - wrapper for mbedtls SHA512 HW acceleration
 *
 */

#include "cy_device.h"

#if defined (CY_IP_MXCRYPTO)

#if !defined(SHA512_ALT_H)
#define SHA512_ALT_H

#include "crypto_common.h"

#if defined(MBEDTLS_SHA512_ALT)

typedef struct mbedtls_sha512_context {
    cy_cmgr_crypto_hw_t obj;
    cy_stc_crypto_sha_state_t hashState;           /* Structure used by CY Crypto Driver   */
    #if (CY_IP_MXCRYPTO_VERSION == 1u)
    cy_stc_crypto_v1_sha512_buffers_t shaBuffers;  /* Structure used by CY Crypto Driver   */
    #else
    cy_stc_crypto_v2_sha512_buffers_t shaBuffers;  /* Structure used by CY Crypto Driver   */
    #endif
}
mbedtls_sha512_context;

#endif /* MBEDTLS_SHA512_ALT */

#endif /* (SHA512_ALT_H) */

#endif /* CY_IP_MXCRYPTO */
