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
 *  File:       Cdd_Pwm_Example_Cmpss_Trip.c
 *  Generator:  None
 *
 *  Description:  This example enables the CMPSS1 COMPH comparator and feeds the asynchronous signal CTRIPH to GPIO1/
 * CDD_PWM1B. Here CMPSS is configured to trip the PWM signals. The positive pin of the CMPSS is used to give positive
 * input and internal DAC in CMPSS(refer to the TRM section on CMPSS for more details) is configured to feed the
 * negative pin. The DAC is configured to provide a signal at VDD/2.
 *
 * When a low signal(VSS) is provided to positive pin of CMPSS1, PWM signal comes out on GPIO1.
 * When a high signal(greater than VDD/2) is provided to positive pin of CMPSS1, the PWM signal at GPIO1 trips and goes
 * high.
 * Example is configured in such a way that PWM coming at GPIO0 will remain unaffected.
 *
 * Setup required for the example:
 * Connect the GPIO pins configured for CDD_PWM to the logic analyzer to observe the PWM channel output waveforms.
 *
 * Steps followed in the example:
 * DeviceSupport_Init()
 * - Initialize FLASH if the example is run in FLASH mode
 * EcuM_Init()
 * - Initialize clock to 100 MHz using Mcu_Init()
 * - Initialize pins in CDD_PWM mode with Port_Init()
 * - Initialize Cdd_Pwm driver using Cdd_Pwm_Init()
 * - Configure Cdd_Pwm hardware using Cdd_Pwm_ConfigureHw()
 * - Feed pin B0(pin 12 on HSEC) to VSS or to a signal greater than VDD/2 to observe the behaviour
 *
 *  CDD_PWM waveform can be observed on the respective pins configured in CDD_PWM mode
 * \b External \b Connections \n
 * - GPIO0 CDD_PWM1A
 * - GPIO1 CDD_PWM1B
 * - Positive pin of CMPSS is at B0 pin(Pin 12 of HSEC board)
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
#include "Cdd_Xbar.h"
#include "cmpss.h"
#include "asysctl.h"
#include "Port.h"
#include "Mcu.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_EVENT_COUNT ((uint8)1U)
#define VDD                 ((uint8)4096U)
#define CDD_PWM_PERIOD      ((uint8)500U)
#define CDD_PWM_CMPA        ((uint8)125U)
#define CDD_PWM_CMPB        ((uint8)375U)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* Array to store the notification of the PWM instances */
uint32 Cdd_Pwm_NotificationCount[CDD_PWM_COUNT]     = {0};
uint32 Cdd_Pwm_TripNotificationCount[CDD_PWM_COUNT] = {0};

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
void Cmpss_Init();
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Pwm_Hw0Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;
}

void Cdd_Pwm_TripNotification(uint16 TripZoneFlag)
{
    Cdd_Pwm_TripNotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;

    if (10 == Cdd_Pwm_TripNotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0])
    {
        Cdd_Pwm_ConfigureTripZoneInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_INTERRUPT_OST,
                                           FALSE);
        Cdd_Pwm_ConfigureTripZoneNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, FALSE);
    }
}

void Cmpss_Init()
{
    /*
     * Select the value for CMP1HPMXSEL.
     */
    ASysCtl_configCMPMux(ASYSCTL_CMP1_HP_6);
    /*
     * Select the value for CMP1LPMXSEL.
     */
    ASysCtl_configCMPMux(ASYSCTL_CMP1_LP_0);

    /*
     * Sets the configuration for the high comparator.
     */
    CMPSS_configHighComparator(CMPSS1_BASE, (CMPSS_INSRC_DAC));

    /*
     * Sets the configuration for the internal comparator DACs.
     */

    CMPSS_configDACHigh(CMPSS1_BASE, (CMPSS_DACVAL_SYSCLK | CMPSS_DACREF_VDDA | CMPSS_DACSRC_SHDW));

    /*
     * Sets the value of the internal DAC of the high comparator.
     */
    CMPSS_setDACValueHigh(CMPSS1_BASE, VDD / 2);

    /*
     * Sets the output signal configuration for the high comparator.
     */
    CMPSS_configOutputsHigh(CMPSS1_BASE, (CMPSS_TRIPOUT_ASYNC_COMP | CMPSS_TRIP_ASYNC_COMP));

    /*
     * Enables the CMPSS module.
     */
    CMPSS_enableModule(CMPSS1_BASE);
    /*
     * Delay for CMPSS DAC to power up.
     */
    McalLib_Delay(50000000); /* Approx. 1second */
    ;
}

void Cdd_Pwm_ConfigureHw()
{
    /* Configure CDD_PWM1 instance */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_1,
                              CDD_PWM_HSCLOCK_DIVIDER_1);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP_DOWN);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_PERIOD);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A,
                                   CDD_PWM_CMPA);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B,
                                   CDD_PWM_CMPB);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);

    /*
     * Configure CDD_PWM1B to output high on TZB TRIP
     */
    Cdd_Pwm_SetTripZoneAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_ACTION_EVENT_TZB,
                              CDD_PWM_TZ_ACTION_HIGH);

    /*
     * Configure CDD_PWM1A to remain un-changed on TZA TRIP
     */
    Cdd_Pwm_SetTripZoneAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_ACTION_EVENT_TZA,
                              CDD_PWM_TZ_ACTION_DISABLE);

    /*
     * Trigger event when DCBH is high
     */
    Cdd_Pwm_SetTripZoneDigitalCompareEventCondition(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                                    CDD_PWM_TZ_DC_OUTPUT_B1, CDD_PWM_TZ_EVENT_DCXH_HIGH);

    /*
     * Configure DCBH to use TRIP4 as an input
     */
    Cdd_Pwm_ConfigureDigitalCompareTripCombinationInput(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                                        CDD_PWM_DC_COMBINATIONAL_TRIPIN4, CDD_PWM_DC_TYPE_DCBH, 1U);

    /*
     * Enable DCB as OST
     */
    Cdd_Pwm_ConfigureTripZoneSignals(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_SIGNAL_DCBEVT1, 1U);

    /*
     * Configure the DCB path to be unfiltered and asynchronous
     */
    Cdd_Pwm_SetDigitalCompareEventSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                         CDD_PWM_DC_EVENT_1, CDD_PWM_DC_EVENT_SOURCE_ORIG_SIGNAL);

    /*
     * Clear trip flags
     */
    Cdd_Pwm_ClearTripZoneFlag(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                              CDD_PWM_TZ_INTERRUPT | CDD_PWM_TZ_FLAG_OST);

    Cdd_Pwm_ConfigureTripZoneInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_TZ_INTERRUPT_OST,
                                       TRUE);
    Cdd_Pwm_ConfigureTripZoneNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);

    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_EVENT_COUNT);
    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_INT_TBCTR_U_CMPA);
    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);
}

int main()
{
    DeviceSupport_Init();
    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U); /* Initialize AppUtils to enable prints */
    AppUtils_Printf("Executing Cdd_Pwm_Example_Cmpss_Trip example\r\n");

    /*Configure CMPSS Module*/
    Cmpss_Init();

    /* Configure CDD_PWM hardware instance */
    Cdd_Pwm_ConfigureHw();

    McalLib_Delay(50000000); /* Approx. 1second */

    while (1)
    {
        McalLib_Delay(50000000); /* Approx 1 sec*/

        /*We are checking the number of trip interrupts here, this will verify whether trip has occured*/
        if (Cdd_Pwm_TripNotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] == 10)
        {
            break;
        }
    }

    AppUtils_Printf(
        "Number of notifications detected for CDD_PWM1 are %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] * CDD_PWM_EVENT_COUNT));
    AppUtils_Printf(
        "Number of trip zone interrupts detected for CDD_PWM1 are %d\r\n",
        (Cdd_Pwm_TripNotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] * CDD_PWM_EVENT_COUNT));

    AppUtils_Printf("Generated waveforms can be observed on the configured CDD_PWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_Cmpss_Trip example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_Cmpss_Trip.c
 *********************************************************************************************************************/
