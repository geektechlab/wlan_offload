/* threading_alt.h  for MBEDTLS_THREADING_ALT */
/*
 *  Copyright The Mbed TLS Contributors
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

#ifndef THREADING_ALT_H
#define THREADING_ALT_H

#include "cyabs_rtos.h"

typedef struct mbedtls_threading_mutex_t {
    /** mutex to protect mbedTLS buffer access */
    cy_mutex_t tls_buf_mutex;
} mbedtls_threading_mutex_t;

#endif /* threading_alt.h */
