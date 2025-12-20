/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited.  This product  is  protected  under  copyright  law
 *                 and  trade  secret law as an  unpublished work.
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
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
