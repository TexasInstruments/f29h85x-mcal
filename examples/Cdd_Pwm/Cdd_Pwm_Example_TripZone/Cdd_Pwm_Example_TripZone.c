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
 *  File:       Cdd_Pwm_Example_TripZone.c
 *  Generator:  None
 *
 *  Description:  Cdd_Pwm example source file.This example demonstrates trip zone functionality.
 *                  The GPIO input which is used to trip the EPWM is controlled with Dio APIs.
 *
 * Setup required for the example:
 * Connect the GPIO pins configured for EPWM to the logic analyzer to observe the PWM channel output waveforms.
 *
 * Steps followed in the example:
 * DeviceSupport_Init()
 * - Initialize FLASH if the example is run in FLASH mode
 * EcuM_Init()
 * - Initialize clock to 100 MHz using Mcu_Init()
 * - Initialize pins in EPWM mode with Port_Init()
 * - Initialize Cdd_Pwm driver using Cdd_Pwm_Init()
 * Configure Cdd_Pwm hardware using Cdd_Pwm_ConfigureHw() to configure EPWM1 as follows
 *  - EPWM1 with no trip zone configuration (reference)
 *  - EPWM2 with trip zone enabled in one-shot mode
 *  - EPWM3 with trip zone enabled in CBC(cycle-by-cycle) mode
 *  - EPWM2 is configured in one-shot mode so the flags must be cleared using APIs but for EPWM3 which is in CBC
 *    the flags are automatically cleared at the end of the cycle if the trip condition doesn't apply anymore.
 * Pull Dio channel(GPIO 12) to LOW to trip EPWM2 & EPWM3 channels
 * EPWM2A & EPWM3B output's should be forced to HIGH when the trip is active.
 * Disable trip interrupt & notification after the notification count reaches 3.
 * Observe the trip for 1msec and pull back the Dio channel(GPIO 12) to HIGH to resume the normal operation
 * The change in the output waveforms can be tracked with a logic analyzer
 *
 *  \b External \b Connections \n
 *  - EPWM1A is on GPIO0
 *  - EPWM2A is on GPIO2
 *  - EPWM3B is on GPIO5
 *  - TZ1 is on GPIO12 and is linked to Dio Channel 0
 *
 * This example also makes use of the Input X-BAR. GPIO12 (the external trigger) is routed to the input X-BAR,
 * from which it is routed to TZ1.
 *
 * The TZ-Event is defined such that EPWM1 will undergo a One-Shot Trip
 *  and EPWM2 will undergo a Cycle-By-Cycle Trip.
 *
 *              _____________             __________________
 *              |           |             |                |
 *  GPIO12 -----| I/P X-BAR |-----TZ1-----| EPWM TZ Module |-----TZ-Event
 *              |___________|             |________________|
 *
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm_Cfg.h"
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Os.h"
#include "Cdd_Pwm.h"
#include "Port.h"
#include "Mcu.h"
#include "Dio.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define OS_COUNTER_ID       ((Os_CounterIdType)0U)
#define CDD_PWM_EVENT_COUNT ((uint8)1U)

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

void Cdd_Pwm_Hw0TzNotification(uint16 TripZoneFlag)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;
}

void Cdd_Pwm_Hw1TzNotification(uint16 TripZoneFlag)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]++;

    if (3U == Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1])
    {
        Cdd_Pwm_ConfigureTripZoneInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_TZ_INTERRUPT_OST,
                                           FALSE);
        Cdd_Pwm_ConfigureTripZoneNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, FALSE);
    }
}

void Cdd_Pwm_Hw2TzNotification(uint16 TripZoneFlag)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2]++;

    if (3U == Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2])
    {
        Cdd_Pwm_ConfigureTripZoneInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_TZ_INTERRUPT_CBC,
                                           FALSE);
        Cdd_Pwm_ConfigureTripZoneNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, FALSE);
    }
}

void Cdd_Pwm_ConfigureHw()
{
    /* Configure EPWM1 instance */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_4,
                              CDD_PWM_HSCLOCK_DIVIDER_4);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 12000U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A,
                                   6000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);

    /* Configure EPWM2 instance */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_CLOCK_DIVIDER_4,
                              CDD_PWM_HSCLOCK_DIVIDER_4);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 6000U);
    Cdd_Pwm_SelectPeriodLoadEvent(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_SHADOW_LOAD_MODE_SYNC);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 0U);
    Cdd_Pwm_ConfigurePhaseShiftLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);
    Cdd_Pwm_SetPhaseShift(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 300U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_A,
                                   3000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetTripZoneAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_TZ_ACTION_EVENT_TZA,
                              CDD_PWM_TZ_ACTION_HIGH);
    Cdd_Pwm_ConfigureTripZoneSignals(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_TZ_SIGNAL_OSHT1, TRUE);
    Cdd_Pwm_ConfigureTripZoneInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_TZ_INTERRUPT_OST,
                                       TRUE);
    Cdd_Pwm_ConfigureTripZoneNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);

    /* Configure EPWM2 instance */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_CLOCK_DIVIDER_4,
                              CDD_PWM_HSCLOCK_DIVIDER_4);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 6000U);
    Cdd_Pwm_SelectPeriodLoadEvent(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_SHADOW_LOAD_MODE_SYNC);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 0U);
    Cdd_Pwm_ConfigurePhaseShiftLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, TRUE);
    Cdd_Pwm_SetPhaseShift(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, 600U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_COUNTER_COMPARE_B,
                                   3000U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    Cdd_Pwm_SetTripZoneAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_TZ_ACTION_EVENT_TZB,
                              CDD_PWM_TZ_ACTION_HIGH);
    Cdd_Pwm_ConfigureTripZoneSignals(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_TZ_SIGNAL_CBC1, TRUE);
}

int main()
{
    DeviceSupport_Init();
    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_TripZone example\r\n");

    Cdd_Pwm_ConfigureHw();

    McalLib_Delay(5000000U); /* After 1sec write LOW value to the PIN */

    AppUtils_Printf("Number of trip zone interrupts detected for EPWM2 before trip are %d\r\n",
                    (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]));

    /* Pull the channel to LOW */
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_LOW);

    while (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] == 0U)
    {
        McalLib_Delay(10U);
    }

    /* To check the output after trip is cleared */
    McalLib_Delay(500000U); /* After 10millisec write LOW value to the PIN */

    /* Pull the channel to HIGH */
    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, STD_HIGH);

    /* To clear the excessive flags */
    Cdd_Pwm_ClearTripZoneFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_TZ_FLAG_OST);

    McalLib_Delay(50000000U); /* After 1sec write LOW value to the PIN */

    /* Put all the EPWM outputs in IDLE state */
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_NO_CHANGE, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_NO_CHANGE, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_NO_CHANGE, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_NO_CHANGE, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_NO_CHANGE, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_NO_CHANGE, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);

    AppUtils_Printf("Number of trip zone interrupts detected for EPWM2 are %d\r\n",
                    (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]));

    AppUtils_Printf("Waveforms can be observed on the configured EPWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_TripZone example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_TripZone.c
 *********************************************************************************************************************/
