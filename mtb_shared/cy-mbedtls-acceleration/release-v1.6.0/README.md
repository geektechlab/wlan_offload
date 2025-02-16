# mbedTLS Crypto acceleration for CAT1A, CAT1B and CAT1C MCUs

This repository contains mbedTLS hardware accelerated basic cryptography implemented for CAT1A, CAT1B and CAT1C MCUs.

It provides an easy to use mbedTLS library for CAT1A, CAT1B and CAT1C MCUs with crypto accelerated hardware. The goal is to make the cryptography features of CAT1A, CAT1B and CAT1C MCUs available to the developer using a simple configuration flow.

### mbedTLS library
The [mbedTLS][mbedTLS-lib] library makes it easy for developers to include cryptographic and SSL/TLS capabilities in their products, facilitating this functionality with a minimal coding footprint.

mbedTLS provides a software-only implementation of basic crypto algorithms. The API is defined by ARM and widely utilized in embedded devices for crypto services. The available modules are:

- Encryption/decryption
- Hashing
- Random number generator (RNG)
- SSL/TLS communication
- TCP/IP communication
- X.509
- Asn1

### cy-mbedtls-acceleration
This repo is implemented as an extension of mbedTLS to add CAT1A, CAT1B and CAT1C MCUs hardware acceleration for the basic crypto algorithms.
It requires :

- [mtb-pdl-cat1][mtb-pdl-cat1] - PDL driver library

mbedTLS library provides a standardized method to extend the implementation by defining special macros.

### How to use mbedTLS library with accelerated ALT implementations without using ModusToolbox
To use the mbedTLS library with CAT1A, CAT1B and CAT1C hardware acceleration, perform these steps
(you can skip steps 1-2 if mbedTLS library is already present in the project).

1. Download mbedTLS library into your project's root directory
    ```shell
    git clone -b mbedtls-2.26.0 --recursive https://github.com/ARMmbed/mbedtls.git
    ```
    _**Note:** Above command will check out mbedtls-2.26.0 tag. To get the list of compatible mbedTLS tags with cy-mbedtls-acceleration package, refer to [dependencies to mbedTLS versions](./RELEASE.md/#dependencies-to-mbedtls-versions)._
2. Add its files to INCLUDES and SOURCES directory search in makefile. For more details about mbedTLS, refer to [mbedTLS Knowledge Base](https://tls.mbed.org/kb).
3. Download cy-mbedtls-acceleration package into your project root directory.
    ```shell
    git clone https://github.com/Infineon/cy-mbedtls-acceleration.git
    ```
    _**Note:** Use appropriate version of cy-mbedtls-acceleration, as listed in [dependencies to mbedTLS versions](./RELEASE.md/#dependencies-to-mbedtls-versions)._
4. To enable hardware acceleration for your platform, use following files.
      ```make
      INCLUDES += -ICOMPONENT_CAT1/include -ICOMPONENT_CAT1/mbedtls_MXCRYPTO -ICOMPONENT_CAT1/mbedtls_MXCRYPTOLITE
      SOURCES += $(wildcard COMPONENT_CAT1/mbedtls_MXCRYPTO/*.c) $(wildcard COMPONENT_CAT1/mbedtls_MXCRYPTOLITE/*.c)
      ```
5. To enable any accelerated feature, add the appropriate define to the mbedtls configuration file. The list of supported features for your platform is available at [features section](#features).

	For example, to use the accelerated implementation for AES algorithm, add the **MBEDTLS_AES_ALT** macro definition to the configuration file (***mbedtls-config.h***):
	```c++
	#define MBEDTLS_AES_ALT
	```

	After that the mbedTLS library uses the implementation of this function from the acceleration library instead of the internal software implementation.
	```c++
	/* These defines can be added to the project's MBEDTLS_CONFIG_FILE */

	/* Currently this target supports SHA1 & SHA256 */
	#define MBEDTLS_SHA1_C
    #define MBEDTLS_SHA224_C
    #define MBEDTLS_SHA256_C

	#define MBEDTLS_SHA1_ALT
	#define MBEDTLS_SHA256_ALT
	#define MBEDTLS_SHA512_ALT

	/* Currently this target supports CBC, CFB, OFB, CTR, XTS and GCM cipher modes */
	#define MBEDTLS_AES_ALT
	#define MBEDTLS_CIPHER_MODE_CBC
	#define MBEDTLS_CIPHER_MODE_CFB
	#define MBEDTLS_CIPHER_MODE_OFB
	#define MBEDTLS_CIPHER_MODE_CTR
	#define MBEDTLS_CIPHER_MODE_XTS
    #define MBEDTLS_GCM_ALT

	/* Only NIST-P curves are currently supported */
	#define MBEDTLS_ECP_ALT
	#define MBEDTLS_ECP_DP_SECP192R1_ENABLED
	#define MBEDTLS_ECP_DP_SECP224R1_ENABLED
	#define MBEDTLS_ECP_DP_SECP256R1_ENABLED
	#define MBEDTLS_ECP_DP_SECP384R1_ENABLED
	#define MBEDTLS_ECP_DP_SECP521R1_ENABLED

	#define MBEDTLS_ECDSA_SIGN_ALT
	#define MBEDTLS_ECDSA_VERIFY_ALT

	#define MBEDTLS_ECDH_GEN_PUBLIC_ALT

    #define MBEDTLS_NO_PLATFORM_ENTROPY
	```

    _**Note:** [mbedtls_alt_config.h](./mbedtls_alt_config.h) automatically enables all accelerated features supported by hardware. You can include it in your MBEDTLS_CONFIG_FILE._

6. Define a macro MBEDTLS_CONFIG_FILE with configuration file name and add to project environment a define:
    ```make
    DEFINES += MBEDTLS_CONFIG_FILE="<mbedtls-config.h>"
    ```
7. Create your application source file and add to those SOURCES directory search in makefile. [Sample application source file](#hardware-accelerated-mbedtls-code-example) can be used for the reference.
8. Make the project.

### How to use mbedTLS library with accelerated ALT implementations in ModusToolbox 2.3+

To use the mbedTLS library using ModusToolbox, perform following steps:

1. Create `Empty_App` project using ModusToolbox.
   
   _**Note:** If you want to enable the standard input output over UART, on CAT1A and CAT1C devices create Hello_World project from ModusToolbox instead of Empty_App project. For CAT1B devices Empty_App supports standard input output over UART._
2. To add mbedTLS and cy-mbedtls-acceleration libraries to project, use the Library Manager. Use appropriate version of cy-mbedtls-acceleration, as listed in [dependencies to mbedTLS versions](./RELEASE.md/#dependencies-to-mbedtls-versions). For more details about Library Manager, refer to [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos][modustoolbox-software-environment].
3. To ignore MbedTLS sample programs and 3rdparty files, create .cyignore file in root directory of project and add following lines:
    ```make
    $(SEARCH_mbedtls)/3rdparty
    $(SEARCH_mbedtls)/programs
    $(SEARCH_mbedtls)/tests
    ```
4. To configure mbedTLS and to use alt implementation, follow instructions provided from section 5 of **[How to use mbedTLS library with accelerated ALT implementations without using ModusToolbox](#how-to-use-mbedtls-library-with-accelerated-alt-implementations-without-using-modustoolbox)**.


### How to use hardware entropy in CAT1A, CAT1B & CAT1C MCUs
To enable hardware entropy perform these steps:

  Add the **MBEDTLS_ENTROPY_HARDWARE_ALT** macro definition to the configuration file (***mbedtls-config.h***):
    ```#define MBEDTLS_ENTROPY_HARDWARE_ALT```

### Hardware accelerated MbedTLS code example

This code example demonstrates MbedTLS hardware acceleration capabilities using the cryptographic hardware block of CAT1A, CAT1B and CAT1C MCUs. It uses SHA - 256 algorithm.

_**Note:** To enable the standard input output over UART communication, you can create `Hello_World` project from ModusToolbox or clone from [mtb-example-psoc6-hello-world](https://github.com/Infineon/mtb-example-psoc6-hello-world)_

```c++
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include "mbedtls/sha256.h" /* SHA-256 only */
#include "mbedtls/platform.h"

int sha256(void)
{
    printf("\r\nSHA-256 Test Application...\r\n");

    /* Run hardware accelerated SHA-256 test */
#if defined(MBEDTLS_SHA256_C)
        const int IS_SHA_224 = 0;
        mbedtls_sha256_context pCtx;
        unsigned char sha256sum[32];
        memset(sha256sum, 0, sizeof(sha256sum));

        /* https://csrc.nist.gov/CSRC/media/Projects/Cryptographic-Standards-and-Guidelines/documents/examples/SHA256.pdf */
        /* Input message */
        static const char* INPUT_MESSAGE = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
        static const uint8_t DIGEST[] = { 0x24, 0x8D, 0x6A, 0x61, 0xD2, 0x06, 0x38, 0xB8, 0xE5, 0xC0, 0x26, 0x93, 0x0C, 0x3E, 0x60, 0x39, 0xA3, 0x3C, 0xE4, 0x59, 0x64, 0xFF, 0x21, 0x67, 0xF6, 0xEC, 0xED, 0xD4, 0x19, 0xDB, 0x06, 0xC1 };

        /* Initialize sha engine */
        mbedtls_sha256_init(&pCtx);

        /* Compute the hash */
        mbedtls_sha256((const unsigned char*)INPUT_MESSAGE, strlen(INPUT_MESSAGE), sha256sum, IS_SHA_224);

        /* Compare result */
        if(memcmp(sha256sum, DIGEST, 32) == 0)
        {
            printf("\r\nTest Case passed.\r\n");
        }
        else
        {
            printf("\r\nTest Case failed.\r\n");
        }
#endif /* MBEDTLS_SHA256_C */

    return 0;
}

int main(void)
{
    sha256();

    return 0;
}
```

### Features

+ **Supported algorithms in CAT1A and CAT1C MCUs:**

  - AES:
      * ECB,
      * CBC,
      * CFB,
      * CTR,
      * XTS.
      * GCM.
  - SHA:
      * SHA1,
      * SHA2 - 256,
      * SHA2 - 512.
  - ECP support for NIST P curves:
      * SECP192R1,
      * SECP224R1,
      * SECP256R1,
      * SECP384R1,
      * SECP521R1.
  - ECDH support for NIST P curves:
      * key generation
  - ECDSA support for NIST P curves:
      * sign,
      * verify

+ **Supported algorithms in CAT1B MCUs:**

  - SHA:
      * SHA2 - 256
  - ECDSA support for NIST P curves :
      * verify for Curve SECP256R1 & SECP384R1
    - AES:
      * ECB: 128 bit Encryption,
      * CBC: 128 bit Encryption,
      * CFB: 128 bit Encryption & Decryption,
      * CTR: 128 bit Encryption & Decryption.
  
### License
This project is licensed under the [Apache 2.0 License][apache-licenses] - see the [LICENSE][LICENSE] file for details

### More information
* [CAT1A, CAT1B and CAT1C MCUs acceleration for mbedTLS library RELEASE information][RELEASE]
* [Peripheral Driver Library API Reference Manual][mtb-pdl-cat1-api]
* [PSoC 6 Technical Reference Manuals][psoc6-trm]
* [PSoC 6 MCU Datasheets][psoc6-ds]
* [mbedtls repository][mbedTLS-lib]
* [Alternative cryptography engines implementation][mbedTLS-alts]
* [mbedTLS supported features][mbedTLS-features]
* [Cypress Semiconductor][cypress]

---
© Cypress Semiconductor Corporation (an Infineon company), 2019-2023.

[cypress]: http://www.cypress.com
[mbedTLS-lib]: https://github.com/ARMmbed/mbedtls
[mbedTLS-alts]: https://tls.mbed.org/kb/development/hw_acc_guidelines
[mbedTLS-features]: https://tls.mbed.org/core-features
[mtb-pdl-cat1]: https://github.com/Infineon/mtb-pdl-cat1
[mtb-hal-cat1]: https://github.com/Infineon/mtb-hal-cat1
[psoc6-ds]: https://www.cypress.com/search/all?f%5b0%5d=meta_type%3Atechnical_documents&f%5b1%5d=resource_meta_type%3A575&f%5b2%5d=field_related_products%3A114026
[psoc6-trm]: https://www.cypress.com/search/all/PSoC%206%20Technical%20Reference%20Manual?f%5b0%5d=meta_type%3Atechnical_documents&f%5b1%5d=resource_meta_type%3A583
[mtb-pdl-cat1-api]: https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html
[cy-mbedtls-acceleration]: https://github.com/Infineon/cy-mbedtls-acceleration
[apache-licenses]: http://www.apache.org/licenses/
[modustoolbox-software-environment]: https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/
[LICENSE]: LICENSE
[RELEASE]: RELEASE.md
