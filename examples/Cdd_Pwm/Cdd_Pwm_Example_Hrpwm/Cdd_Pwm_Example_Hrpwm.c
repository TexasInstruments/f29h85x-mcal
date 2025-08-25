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
 *  File:       Cdd_Pwm_Example_Hrpwm.c
 *  Generator:  None
 *
 *  Description:  Cdd_Pwm example source file.This example demonstrates how HRPWM can be used to arrive at the duty 
 *                cycles which can't be done with the normal operation.
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
 * Configure Cdd_Pwm hardware using Cdd_Pwm_ConfigureHw() as follows
 *      - EPWM1 with HRPWM disabled(for reference)
 *      - EPWM2 with HRPWM enabled
 * Print the notification count of all EPWM instances.
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

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_TBPRD           (80UL)
#define CDD_PWM_HRPWM_DUTY              ((float32)51)

uint32 Cdd_Pwm_NotificationCount[CDD_PWM_COUNT] = {0U};

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

void error(void);

void Cdd_Pwm_ConfigureHw(void);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

void Cdd_Pwm_HwUnit1Notification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]++;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void error (void)
{
    while(1){}        /* Stop here and handle error */
}

void Cdd_Pwm_ConfigureHw()
{
    /* Configure EPWM2 instance without HRPWM */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_4, CDD_PWM_HSCLOCK_DIVIDER_4);	
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP);	
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 79U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);	

    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A, 40U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);	
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B, 40U);	
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    /* Configure EPWM1 instance with HRPWM enabled */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_CLOCK_DIVIDER_4,CDD_PWM_HSCLOCK_DIVIDER_4);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 79U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 0U);
    Cdd_Pwm_HrpwmConfigurePhaseShiftLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,FALSE);
    Cdd_Pwm_HrpwmSetPhaseShift(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 0U);

    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_A, 40U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_B, 40U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B, CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    Cdd_Pwm_HrpwmConfigureAutoConversion(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,TRUE);
    Cdd_Pwm_HrpwmSetMepEdgeSelect(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A, CDD_PWM_HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE);
    Cdd_Pwm_HrpwmSetHiResCounterCompareValueOnly(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A, 40U);
    Cdd_Pwm_HrpwmSetMepEdgeSelect(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B, CDD_PWM_HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE);
    Cdd_Pwm_HrpwmSetHiResCounterCompareValueOnly(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B, 40U);

    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,TRUE);
    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_INT_TBCTR_U_CMPA);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 10U);
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
}

int main()
{
    float32 count;
    uint32 compcount;
    Cdd_Pwm_HrpwmCalInstanceType Cdd_Pwm_HrpwmCalId; 
    Cdd_Pwm_SfoStatus CddPwmHrcalStatus;
    float32 CddPwmDutyFine = CDD_PWM_HRPWM_DUTY;

    DeviceSupport_Init();

    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_Hrpwm example\r\n");

    /* Trying to configure 40.5% duty cycle of PWM frequency = 1.25MHz and frequency of TBCLK is 100MHz  */

    /* SFO function updates the HRMSTEP register with calibrated Cdd_Pwm_MEP_ScaleFactor.
     * HRMSTEP must be populated with a scale factor prior to enabling high resolution period control 
     */

    for(Cdd_Pwm_HrpwmCalInstanceType hrpwm_idx = 0U;hrpwm_idx < CDD_PWM_HRPWM_CAL_COUNT;hrpwm_idx++)
    {
            Cdd_Pwm_HrpwmCalId = hrpwm_idx;
        do
        {
            CddPwmHrcalStatus = Cdd_Pwm_Sfo(hrpwm_idx);
            if(CddPwmHrcalStatus == CDD_PWM_SFO_ERROR)
            {
                error();   // SFO function returns 2 if an error occurs & # of MEP
            }              // steps/coarse step exceeds maximum of 255.
        } while(CddPwmHrcalStatus == CDD_PWM_SFO_INCOMPLETE);
    }

    Cdd_Pwm_HrpwmCalId = CddPwmConf_CddPwmHrpwmCalConfig_CddPwmHrpwmCal0;

    /* Configure PWM hardware instances */
    Cdd_Pwm_ConfigureHw();

    for(CddPwmDutyFine = 50U; CddPwmDutyFine <= 52.3; CddPwmDutyFine += 0.01)
    {
        count = (CddPwmDutyFine * (float32)(CDD_PWM_TBPRD << 8U))/100U;
        compcount = (uint32)count;
        Cdd_Pwm_HrpwmSetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A, compcount);
        Cdd_Pwm_HrpwmSetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B, compcount);

        /*
         * Call the scale factor optimizer lib function SFO() periodically to track for any change due to 
         * temp/voltage. This function generates Cdd_Pwm_MEP_ScaleFactor by running the MEP calibration module in the 
         * HRPWM logic. This scale factor can be used for all HRPWM channels. The SFO() function also updates the 
         * HRMSTEP register with the scale factor value.
         */
        CddPwmHrcalStatus = Cdd_Pwm_Sfo(Cdd_Pwm_HrpwmCalId);  /* In background, MEP calibration module continuously updates Cdd_Pwm_MEP_ScaleFactor */

        if (CddPwmHrcalStatus == CDD_PWM_SFO_ERROR)
        {
            /* SFO function returns 2 if an error occurs & # of MEP steps/coarse step exceeds maximum of 255. */
            error();
        }

        /* If calibration is completed for the current HRPWM CAL module, switch to next module */
        if(CddPwmHrcalStatus == CDD_PWM_SFO_COMPLETE)
        {
            Cdd_Pwm_HrpwmCalId = ((Cdd_Pwm_HrpwmCalId + 1U)%CDD_PWM_HRPWM_CAL_COUNT);
        }
        McalLib_Delay(50000U); /* 1ms delay */
    }
    
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A, 41U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B, 41U);

    McalLib_Delay(50000000); /* 1second */

    Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);

    AppUtils_Printf("Number of rising edges detected for EPWM1 are %d\r\n",
                (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]));

    AppUtils_Printf("Cdd_Pwm_Example_Hrpwm example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_Hrpwm.c
 *********************************************************************************************************************/
