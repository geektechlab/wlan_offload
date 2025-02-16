/***********************************************************************************************//**
 * \file cyabs_freertos_helpers.c
 *
 * \brief
 * Provides implementations for functions required to enable static allocation and
 * tickless mode in FreeRTOS.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
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
 **************************************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "cyabs_rtos.h"
#include "cy_utils.h"
#if defined(CY_USING_HAL)
#include "cyhal.h"
#elif defined(COMPONENT_MTB_HAL)
#include "mtb_hal.h"
#endif

// This is included to allow the user to control the idle task behavior via the configurator
// System->Power->RTOS->System Idle Power Mode setting.
#include "cybsp.h"

#if defined(COMPONENT_MTB_HAL) && (configUSE_TICKLESS_IDLE != 0)
// By default, the device will deep-sleep in the idle task unless if the device
// configurator overrides the behaviour to sleep in the System->Power->RTOS->System
// Idle Power Mode setting.
    #if defined(CY_CFG_PWR_MODE_DEEPSLEEP) && \
    (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP)
        #define _ABS_RTOS_DEEPSLEEP_ENABLED
    #elif defined(CY_CFG_PWR_MODE_DEEPSLEEP_RAM) && \
    (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP_RAM)
// We don't care here about the difference between deep-sleep and deep-sleep RAM
        #define _ABS_RTOS_DEEPSLEEP_ENABLED
    #elif (defined(CY_CFG_PWR_MODE_SLEEP) && (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_SLEEP))
        #define _ABS_RTOS_SLEEP_ENABLED
    #endif
// We can support sleep in a non-tickless fashion if there is no LPTimer.
// But we must have it for DeepSleep because the overhead of entering and
// exiting DeepSleep is too high to do so in a tickful fashion.
    #if defined(_ABS_RTOS_DEEPSLEEP_ENABLED)
// Deliberately not defined(); the HAL driver available macros are boolean values
        #if !(MTB_HAL_DRIVER_AVAILABLE_SYSPM)
            #error "Tickless idle depends on the SysPm HAL driver, but it is not available"
        #endif
        #if !(MTB_HAL_DRIVER_AVAILABLE_LPTIMER)
            #error "Tickless idle depends on the LPTimer HAL driver, but it is not available"
        #endif
    #endif // defined(_ABS_RTOS_DEEPSLEEP_ENABLED)

    #if defined(_ABS_RTOS_DEEPSLEEP_ENABLED) || defined(_ABS_RTOS_SLEEP_ENABLED)
        #if (MTB_HAL_DRIVER_AVAILABLE_LPTIMER) && (MTB_HAL_DRIVER_AVAILABLE_SYSPM)
        #define _ABS_RTOS_TICKLESS_ENABLED
        #endif // (MTB_HAL_DRIVER_AVAILABLE_LPTIMER) && (MTB_HAL_DRIVER_AVAILABLE_SYSPM)
    #endif
#endif // if defined(COMPONENT_MTB_HAL) && (configUSE_TICKLESS_IDLE != 0)

#define pdTICKS_TO_MS(xTicks)    ( ( ( TickType_t ) ( xTicks ) * 1000u ) / configTICK_RATE_HZ )

#if defined(CY_USING_HAL)
static cyhal_lptimer_t* _lptimer = NULL;

//--------------------------------------------------------------------------------------------------
// cyabs_rtos_set_lptimer
//--------------------------------------------------------------------------------------------------
void cyabs_rtos_set_lptimer(cyhal_lptimer_t* timer)
{
    _lptimer = timer;
}


//--------------------------------------------------------------------------------------------------
// cyabs_rtos_get_lptimer
//--------------------------------------------------------------------------------------------------
cyhal_lptimer_t* cyabs_rtos_get_lptimer(void)
{
    return _lptimer;
}


#if (configUSE_TICKLESS_IDLE != 0)
//--------------------------------------------------------------------------------------------------
// cyabs_rtos_get_deepsleep_latency
//--------------------------------------------------------------------------------------------------
uint32_t cyabs_rtos_get_deepsleep_latency(void)
{
    uint32_t latency = 0;

    #if defined(CY_CFG_PWR_DEEPSLEEP_LATENCY)
    latency = CY_CFG_PWR_DEEPSLEEP_LATENCY;
    #endif //defined(CY_CFG_PWR_DEEPSLEEP_LATENCY)

    #if defined (CYHAL_API_AVAILABLE_SYSPM_GET_DEEPSLEEP_MODE)
    cyhal_syspm_system_deep_sleep_mode_t deep_sleep_mode = cyhal_syspm_get_deepsleep_mode();

    switch (deep_sleep_mode)
    {
        case CYHAL_SYSPM_SYSTEM_DEEPSLEEP:
        case CYHAL_SYSPM_SYSTEM_DEEPSLEEP_OFF:
        case CYHAL_SYSPM_SYSTEM_DEEPSLEEP_NONE:
            #if defined(CY_CFG_PWR_DEEPSLEEP_LATENCY)
            latency = CY_CFG_PWR_DEEPSLEEP_LATENCY;
            #endif //defined(CY_CFG_PWR_DEEPSLEEP_LATENCY)
            break;

        case CYHAL_SYSPM_SYSTEM_DEEPSLEEP_RAM:
            #if defined(CY_CFG_PWR_DEEPSLEEP_RAM_LATENCY)
            latency = CY_CFG_PWR_DEEPSLEEP_RAM_LATENCY;
            #endif //defined(CY_CFG_PWR_DEEPSLEEP_RAM_LATENCY)
            break;

        default:
            #if defined(CY_CFG_PWR_DEEPSLEEP_LATENCY)
            latency = CY_CFG_PWR_DEEPSLEEP_LATENCY;
            #endif //defined(CY_CFG_PWR_DEEPSLEEP_LATENCY)
            break;
    }
    #endif // if defined (CYHAL_API_AVAILABLE_SYSPM_GET_DEEPSLEEP_MODE)
    return latency;
}


#endif //(configUSE_TICKLESS_IDLE != 0)

#endif //defined(CY_USING_HAL)


// The following implementations were sourced from https://www.freertos.org/a00110.html

//--------------------------------------------------------------------------------------------------
// vApplicationGetIdleTaskMemory
//
// configSUPPORT_STATIC_ALLOCATION is set to 1, so the application must provide an implementation of
// vApplicationGetIdleTaskMemory() to provide the memory that is used by the Idle task.
//--------------------------------------------------------------------------------------------------
__WEAK void vApplicationGetIdleTaskMemory(StaticTask_t** ppxIdleTaskTCBBuffer,
                                          StackType_t** ppxIdleTaskStackBuffer,
                                          uint32_t* pulIdleTaskStackSize)
{
    // If the buffers to be provided to the Idle task are declared inside this function then they
    // must be declared static – otherwise they will be allocated on the stack and so not exists
    // after this function exits.
    static StaticTask_t xIdleTaskTCB;
    static StackType_t  uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    // Pass out a pointer to the StaticTask_t structure in which the Idle task’s state will be
    // stored.
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    // Pass out the array that will be used as the Idle task’s stack.
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    // Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.  Note that, as the
    // array is necessarily of type StackType_t, configMINIMAL_STACK_SIZE is specified in words, not
    // bytes.
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}


/*———————————————————–*/

//--------------------------------------------------------------------------------------------------
// vApplicationGetTimerTaskMemory
//
// configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the application must
// provide an implementation of vApplicationGetTimerTaskMemory() to provide the memory that is used
// by the Timer service task.
//--------------------------------------------------------------------------------------------------
__WEAK void vApplicationGetTimerTaskMemory(StaticTask_t** ppxTimerTaskTCBBuffer,
                                           StackType_t** ppxTimerTaskStackBuffer,
                                           uint32_t* pulTimerTaskStackSize)
{
    // If the buffers to be provided to the Timer task are declared inside this function then they
    // must be declared static – otherwise they will be allocated on the stack and so not exists
    // after this function exits.
    static StaticTask_t xTimerTaskTCB;
    static StackType_t  uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    // Pass out a pointer to the StaticTask_t structure in which the Timer task’s state will be
    // stored.
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    // Pass out the array that will be used as the Timer task’s stack.
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    // Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.  Note that, as the
    // array is necessarily of type StackType_t, configTIMER_TASK_STACK_DEPTH is specified in words,
    // not bytes.
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}


#if (defined(CY_USING_HAL) || defined(COMPONENT_MTB_HAL)) && (configUSE_TICKLESS_IDLE != 0)
//--------------------------------------------------------------------------------------------------
// vApplicationSleep
//
/** User defined tickless idle sleep function.
 *
 * Provides a implementation for portSUPPRESS_TICKS_AND_SLEEP macro that allows
 * the device to attempt to deep-sleep for the idle time the kernel expects before
 * the next task is ready. This function disables the system timer and enables low power
 * timer that can operate in deep-sleep mode to wake the device from deep-sleep after
 * expected idle time has elapsed.
 *
 * @param[in] xExpectedIdleTime     Total number of tick periods before
 *                                  a task is due to be moved into the Ready state.
 */
//--------------------------------------------------------------------------------------------------
__WEAK void vApplicationSleep(TickType_t xExpectedIdleTime)
{
    #if defined(CY_USING_HAL)
    #if (defined(CY_CFG_PWR_MODE_DEEPSLEEP) && \
    (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP)) || \
    (defined(CY_CFG_PWR_MODE_DEEPSLEEP_RAM) && \
    (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP_RAM))
    #define DEEPSLEEP_ENABLE
    #endif
    static cyhal_lptimer_t timer;
    uint32_t               actual_sleep_ms = 0;
    cy_rslt_t result = CY_RSLT_SUCCESS;

    if (NULL == _lptimer)
    {
        result = cyhal_lptimer_init(&timer);
        if (result == CY_RSLT_SUCCESS)
        {
            _lptimer = &timer;
        }
        else
        {
            CY_ASSERT(false);
        }
    }

    if (NULL != _lptimer)
    {
        /* Disable interrupts so that nothing can change the status of the RTOS while
         * we try to go to sleep or deep-sleep.
         */
        uint32_t         status       = cyhal_system_critical_section_enter();
        eSleepModeStatus sleep_status = eTaskConfirmSleepModeStatus();

        if (sleep_status != eAbortSleep)
        {
            // By default, the device will deep-sleep in the idle task unless if the device
            // configurator overrides the behaviour to sleep in the System->Power->RTOS->System
            // Idle Power Mode setting.
            #if defined (CY_CFG_PWR_SYS_IDLE_MODE)
            uint32_t sleep_ms = pdTICKS_TO_MS(xExpectedIdleTime);
            #if defined DEEPSLEEP_ENABLE
            bool deep_sleep = true;
            // If the system needs to operate in active mode the tickless mode should not be used in
            // FreeRTOS
            CY_ASSERT(CY_CFG_PWR_SYS_IDLE_MODE != CY_CFG_PWR_MODE_ACTIVE);
            deep_sleep =
                #if defined(CY_CFG_PWR_MODE_DEEPSLEEP_RAM)
                (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP_RAM) ||
                #endif
                (CY_CFG_PWR_SYS_IDLE_MODE == CY_CFG_PWR_MODE_DEEPSLEEP);
            if (deep_sleep)
            {
                // Adjust the deep-sleep time by the sleep/wake latency if set.
                #if defined(CY_CFG_PWR_DEEPSLEEP_LATENCY) || \
                defined(CY_CFG_PWR_DEEPSLEEP_RAM_LATENCY)
                uint32_t deep_sleep_latency = cyabs_rtos_get_deepsleep_latency();
                if (sleep_ms > deep_sleep_latency)
                {
                    result = cyhal_syspm_tickless_deepsleep(_lptimer,
                                                            (sleep_ms - deep_sleep_latency),
                                                            &actual_sleep_ms);
                }
                else
                {
                    result = CY_RTOS_TIMEOUT;
                }
                #else \
                // defined(CY_CFG_PWR_DEEPSLEEP_LATENCY) ||
                // defined(CY_CFG_PWR_DEEPSLEEP_RAM_LATENCY)
                result = cyhal_syspm_tickless_deepsleep(_lptimer, sleep_ms, &actual_sleep_ms);
                #endif \
                // defined(CY_CFG_PWR_DEEPSLEEP_LATENCY) ||
                // defined(CY_CFG_PWR_DEEPSLEEP_RAM_LATENCY)
                //maintain compatibility with older HAL versions that didn't define this error
                #ifdef CYHAL_SYSPM_RSLT_DEEPSLEEP_LOCKED
                //Deepsleep has been locked, continuing into normal sleep
                if (result == CYHAL_SYSPM_RSLT_DEEPSLEEP_LOCKED)
                {
                    deep_sleep = false;
                }
                #endif
            }
            if (!deep_sleep)
            {
            #endif // if defined DEEPSLEEP_ENABLE
            uint32_t sleep_latency =
                #if defined (CY_CFG_PWR_SLEEP_LATENCY)
                CY_CFG_PWR_SLEEP_LATENCY +
                #endif
                0;
            if (sleep_ms > sleep_latency)
            {
                result = cyhal_syspm_tickless_sleep(_lptimer, (sleep_ms - sleep_latency),
                                                    &actual_sleep_ms);
            }
            else
            {
                result = CY_RTOS_TIMEOUT;
            }
            #if defined DEEPSLEEP_ENABLE
        }
            #endif
            #else // if defined (CY_CFG_PWR_SYS_IDLE_MODE)
            CY_UNUSED_PARAMETER(xExpectedIdleTime);
            #endif // if defined (CY_CFG_PWR_SYS_IDLE_MODE)
            if (result == CY_RSLT_SUCCESS)
            {
                // If you hit this assert, the latency time (CY_CFG_PWR_DEEPSLEEP_LATENCY) should
                // be increased. This can be set though the Device Configurator, or by manually
                // defining the variable in cybsp.h for the TARGET platform.
                CY_ASSERT(actual_sleep_ms <= pdTICKS_TO_MS(xExpectedIdleTime));
                vTaskStepTick(convert_ms_to_ticks(actual_sleep_ms));
            }
        }

        cyhal_system_critical_section_exit(status);
    }
    #elif defined(COMPONENT_MTB_HAL)
    // This release does not yet support the LPTimer functionality from HAL 3.0, so we cannot
    // disable SysTick or enter DeepSleep, and instead we simply put the CPU to sleep until the
    // next SysTick.
    // There is a #error earlier in this file that will flag if the application attempts to
    // configure tickless DeepSleep while it is not supported.
    CY_UNUSED_PARAMETER(xExpectedIdleTime);
    __WFI();
    #endif // defined(CY_USING_HAL)
}


#endif // (defined(CY_USING_HAL) || defined(COMPONENT_MTB_HAL)) && (configUSE_TICKLESS_IDLE != 0)
