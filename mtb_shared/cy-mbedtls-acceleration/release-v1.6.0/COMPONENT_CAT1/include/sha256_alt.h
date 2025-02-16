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
 * \file    sha256_alt.h
 * \version 1.6
 *
 * \brief   header file - wrapper for mbedtls SHA256 HW acceleration
 *
 */

#include "cy_device.h"

#if defined (CY_IP_MXCRYPTO)
    #include "sha256_alt_mxcrypto.h"
#elif defined (CY_IP_MXCRYPTOLITE)
    #include "sha256_alt_mxcryptolite.h"
#else
    #error mbedTLS ALT for SHA256 is not supported
#endif /* CY_IP_MXCRYPTO */
