# CLib Support Library Release Notes
The CLib Support Library provides the necessary hooks to make C library functions such as malloc and free thread safe for FreeRTOS and ThreadX.

### What's Included?
* Thread safety hooks for GCC Newlib
* Thread safety hooks for ARM C library
* Thread safety hooks for IAR C library
* Thread safety hooks for C++
* Hook for the system time() function

### What Changed?
#### v1.6.0
* Add support for HAL API version 3
#### v1.5.0
* Fix _sbrk() in decrement memory allocated
* Add support for ThreadX (ARM Compiler)
* CAT5 support
#### v1.4.2
* Fix MISRA violations
* Fix runtime errors with IAR toolchain
#### v1.4.0
* Add support for ThreadX with IAR Toolchain
#### v1.3.0
* Improve type consistency to fix compilation warnings
#### v1.2.0
* Add support for ThreadX (GCC Compiler only)
* Add support for Cortex-R devices (GCC Compiler only)
#### v1.1.0
* Add support for using RTC to support time()
#### v1.0.2
* Minor update to work with a wider range of MCUs
#### v1.0.1
* Minor update for documentation & branding
#### v1.0.0
* Initial release

### Supported Software and Tools
This version of the CLib FreeRTOS Support Library was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.0.0   |
| GCC Compiler                              | 10.3.1  |
| IAR Compiler                              | 9.40.2  |
| ARM Compiler                              | 6.16    |

Minimum required ModusToolbox™ Software Environment: v2.0

### More information
Use the following links for more information, as needed:
* [Reference Guide](https://infineon.github.io/clib-support/html/index.html)
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2020-2023.
