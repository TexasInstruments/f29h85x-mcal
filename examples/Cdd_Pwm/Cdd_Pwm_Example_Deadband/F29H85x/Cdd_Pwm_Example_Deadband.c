/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Pwm_Example_Deadband.c
 *  Generator:  None
 *
 *  Description:  Cdd_Pwm example source file.This example demonstrates independent waveform
 *  generation on two output channels of a PWM instance using Cdd_Pwm driver.50Hz PWM waveforms
 *  with different duty cycles can be observed on the PWM1 channel output waveforms. 1KHz
 *  waveforms can be observed with the PWM2 channel output waveforms.
 *
 * Setup required for the example:
 * Connect the GPIO0 & GPIO1 pins to the logic analyzer to observe the PWM1 channel A & channel B
 * waveforms Connect the GPIO2 & GPIO3 pins to the logic analyzer to observe the PWM2 channel A &
 * channel B waveforms
 *
 * Steps followed in the example:
 * DeviceSupport_Init()
 * - Initialize FLASH if the example is run in FLASH mode
 * EcuM_Init()
 * - Initialize clock to 100 MHz using Mcu_Init()
 * - Initialize pins in EPWM mode with Port_Init()
 * - Initialize Cdd_Pwm driver using Cdd_Pwm_Init()
 * - Initialize EPWM instances using Cdd_Pwm_ConfigureHw()
 *
 *  - EPWM1 with Deadband disabled (Reference)
 *  - EPWM2 with Deadband Active High
 *  - EPWM3 with Deadband Active Low
 *  - EPWM4 with Deadband Active Low Complementary
 *  - EPWM7 with Deadband Active High Complementary
 *
 * Track the output waveforms for 1 second and disable all notifications and interrupts.
 * Print the notification counts to track the notification count for each EPWM instance.
 *
 *  EPWM waveform can be observed on the respective pins configured in EPWM mode
 * \b External \b Connections \n
 * - GPIO0 EPWM1A
 * - GPIO1 EPWM1B
 * - GPIO2 EPWM2A
 * - GPIO3 EPWM2B
 * - GPIO4 EPWM3A
 * - GPIO5 EPWM3B
 * - GPIO27 EPWM4A
 * - GPIO28 EPWM4B
 * - GPIO12 EPWM7A
 * - GPIO13 EPWM7B
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Os.h"
#include "Cdd_Pwm.h"
#include "Port.h"
#include "Mcu.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_EVENT_COUNT ((uint8)10U)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* Array to store the notification of the PWM instances */
uint32 Cdd_Pwm_NotificationCount[CDD_PWM_COUNT] = {0};

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
/*  version info variable */
Std_VersionInfoType Cdd_Adc_VersionInfo;
#endif

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

void Cdd_Pwm_ConfigureHw(void);

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Pwm_HwUnit0Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;
}

void Cdd_Pwm_HwUnit1Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]++;
}

void Cdd_Pwm_HwUnit2Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2]++;
}

void Cdd_Pwm_HwUnit3Notification(void)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3]++;
}

void Cdd_Pwm_HwUnit4Notification(void)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4]++;
}

void Cdd_Pwm_ConfigureHw()
{
    /* Configure EPWM1 instance in up-count mode */
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_2,
                              CDD_PWM_HSCLOCK_DIVIDER_2);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 12500U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A,
                                   3125U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B,
                                   9375U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_INT_TBCTR_ZERO);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_EVENT_COUNT);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);

    /* Configure EPWM2 instance in up-down count mode */
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_CLOCK_DIVIDER_2,
                              CDD_PWM_HSCLOCK_DIVIDER_2);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 12500U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 0U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_A,
                                   3125U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_B,
                                   9375U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    /* By default the deadband input is set to EPWMA */
    Cdd_Pwm_SetDeadBandDelayMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_DB_RED, TRUE);
    Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                                  CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetRisingEdgeDelayCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 1250U);
    Cdd_Pwm_SetDeadBandDelayMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_DB_FED, TRUE);
    Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                                   CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetFallingEdgeDelayCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 1250U);

    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_INT_TBCTR_ETINTMIX);
    Cdd_Pwm_SetMixEvtTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_ETMIX_INTERRUPT,
                                   CDD_PWM_ETMIX_TBCTR_U_CMPA);
    Cdd_Pwm_SetMixEvtTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_ETMIX_INTERRUPT,
                                   CDD_PWM_ETMIX_TBCTR_U_CMPB);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_EVENT_COUNT);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);

    /* Configure EPWM3 instanced with DB enabled */
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2);
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_CLOCK_DIVIDER_2,
                              CDD_PWM_HSCLOCK_DIVIDER_2);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 12500U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 0U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_COMPARE_A,
                                   3125U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_COMPARE_B,
                                   9375U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);

    Cdd_Pwm_SetDeadBandDelayPolarity(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_DB_RED,
                                     CDD_PWM_DB_POLARITY_ACTIVE_LOW);
    Cdd_Pwm_SetDeadBandDelayPolarity(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_DB_FED,
                                     CDD_PWM_DB_POLARITY_ACTIVE_LOW);
    Cdd_Pwm_SetDeadBandDelayMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_DB_RED, TRUE);
    Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                                  CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetRisingEdgeDelayCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 1250U);
    Cdd_Pwm_SetDeadBandDelayMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_DB_FED, TRUE);
    Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                                   CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetFallingEdgeDelayCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 1250U);

    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_INT_TBCTR_ETINTMIX);
    Cdd_Pwm_SetMixEvtTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_ETMIX_INTERRUPT,
                                   CDD_PWM_ETMIX_TBCTR_U_CMPA);
    Cdd_Pwm_SetMixEvtTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_ETMIX_INTERRUPT,
                                   CDD_PWM_ETMIX_TBCTR_U_CMPB);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_EVENT_COUNT);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, TRUE);

    /* Configure EPWM4 instanced with DB enabled */
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3);
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_CLOCK_DIVIDER_2,
                              CDD_PWM_HSCLOCK_DIVIDER_2);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, 12500U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, 0U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_COUNTER_COMPARE_A,
                                   3125U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_COUNTER_COMPARE_B,
                                   9375U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_INT_TBCTR_ETINTMIX);
    Cdd_Pwm_SetMixEvtTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_ETMIX_INTERRUPT,
                                   CDD_PWM_ETMIX_TBCTR_U_CMPA);
    Cdd_Pwm_SetMixEvtTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_ETMIX_INTERRUPT,
                                   CDD_PWM_ETMIX_TBCTR_U_CMPB);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_EVENT_COUNT);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, TRUE);

    Cdd_Pwm_SetDeadBandDelayPolarity(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_DB_RED,
                                     CDD_PWM_DB_POLARITY_ACTIVE_LOW);
    Cdd_Pwm_SetDeadBandDelayMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_DB_RED, TRUE);
    Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3,
                                                  CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetRisingEdgeDelayCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, 1250U);
    Cdd_Pwm_SetDeadBandDelayMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, CDD_PWM_DB_FED, TRUE);
    Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3,
                                                   CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetFallingEdgeDelayCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, 1250U);

    /* Configure EPWM4 instanced with DB enabled */
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4);
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_CLOCK_DIVIDER_2,
                              CDD_PWM_HSCLOCK_DIVIDER_2);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, 12500U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, 0U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_COUNTER_COMPARE_A,
                                   3125U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_COUNTER_COMPARE_B,
                                   9375U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_INT_TBCTR_ETINTMIX);
    Cdd_Pwm_SetMixEvtTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_ETMIX_INTERRUPT,
                                   CDD_PWM_ETMIX_TBCTR_U_CMPA);
    Cdd_Pwm_SetMixEvtTriggerSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_ETMIX_INTERRUPT,
                                   CDD_PWM_ETMIX_TBCTR_U_CMPB);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_EVENT_COUNT);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, TRUE);

    Cdd_Pwm_SetDeadBandDelayPolarity(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_DB_FED,
                                     CDD_PWM_DB_POLARITY_ACTIVE_LOW);
    Cdd_Pwm_SetDeadBandDelayMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_DB_RED, TRUE);
    Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4,
                                                  CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetRisingEdgeDelayCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, 1250U);
    Cdd_Pwm_SetDeadBandDelayMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, CDD_PWM_DB_FED, TRUE);
    Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4,
                                                   CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetFallingEdgeDelayCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, 1250U);
}

int main()
{
    DeviceSupport_Init();
    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_Deadband example\r\n");

    /* Get version Info */
#if (STD_ON == CDD_ADC_VERSION_INFO_API)
    Cdd_Adc_GetVersionInfo(&Cdd_Adc_VersionInfo);
    AppUtils_Printf("CDD_ADC MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Adc_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Adc_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Adc_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Adc_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Adc_VersionInfo.sw_patch_version);
#endif

    Cdd_Pwm_ConfigureHw();

    McalLib_Delay(50000000U); /* 1second */

    /* Disable all interrupts */
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, FALSE);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, FALSE);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, FALSE);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3, FALSE);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4, FALSE);

    /* Disable all notifications */
    Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);
    Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
    Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2);
    Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3);
    Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4);

    AppUtils_Printf(
        "Number of interrupts detected for EPWM1 are %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] * CDD_PWM_EVENT_COUNT));
    AppUtils_Printf(
        "Number of interrupts detected for EPWM2 are %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] * CDD_PWM_EVENT_COUNT));
    AppUtils_Printf(
        "Number of interrupts detected for EPWM3 are %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2] * CDD_PWM_EVENT_COUNT));
    AppUtils_Printf(
        "Number of interrupts detected for EPWM4 are %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3] * CDD_PWM_EVENT_COUNT));
    AppUtils_Printf(
        "Number of interrupts detected for EPWM7 are %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_4] * CDD_PWM_EVENT_COUNT));

    AppUtils_Printf("Generated waveforms can be observed on the configured EPWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_Deadband example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_Deadband.c
 *********************************************************************************************************************/
