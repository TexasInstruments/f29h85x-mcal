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
 *      - EPWM2 with HRPWM enabled (for both A & B channels MEP edge is configured as FALLING EDGE)
 * Print the notification count of all EPWM instances.
 *
 * *  EPWM waveform can be observed on the respective pins configured in EPWM mode
 * \b External \b Connections \n
 * - GPIO0 EPWM1A
 * - GPIO1 EPWM1B
 * - GPIO2 EPWM2A
 * - GPIO3 EPWM2B
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

#define CDD_PWM_TBPRD      (100UL)
#define CDD_PWM_HRPWM_DUTY (4.0 / ((float32)CDD_PWM_TBPRD) * 100.0)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

uint32 Cdd_Pwm_NotificationCount[CDD_PWM_COUNT] = {0U};

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

void error(void);

void Cdd_Pwm_ConfigureHw();

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

void error(void)
{
    while (1)
    {
    } /* Stop here and handle error */
}

void Cdd_Pwm_ConfigureHw()
{
    /* Configure EPWM2 instance without HRPWM */
    Cdd_Pwm_SetEmulationMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_EMULATION_FREE_RUN);
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_CLOCK_DIVIDER_1,
                              CDD_PWM_HSCLOCK_DIVIDER_1);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 99U);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, 0U);

    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A, 0U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B, 0U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    /* Configure EPWM1 instance with HRPWM enabled */
    Cdd_Pwm_SetEmulationMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_EMULATION_FREE_RUN);
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_CLOCK_DIVIDER_1,
                              CDD_PWM_HSCLOCK_DIVIDER_1);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 0U);
    Cdd_Pwm_HrpwmConfigurePhaseShiftLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, FALSE);
    Cdd_Pwm_HrpwmSetPhaseShift(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 0U);

    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_A, 0U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_A, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_B, 0U);
    Cdd_Pwm_SetCounterCompareShadowLoadMode(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                            CDD_PWM_COUNTER_COMPARE_B, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);

    Cdd_Pwm_HrpwmConfigureAutoConversion(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);
    Cdd_Pwm_HrpwmSetMepEdgeSelect(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                  CDD_PWM_HRPWM_MEP_CTRL_FALLING_EDGE);
    Cdd_Pwm_HrpwmSetHiResCounterCompareValueOnly(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                                 50U);
    Cdd_Pwm_HrpwmSetMepEdgeSelect(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                  CDD_PWM_HRPWM_MEP_CTRL_FALLING_EDGE);
    Cdd_Pwm_HrpwmSetHiResCounterCompareValueOnly(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                                 50U);

    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 99U);

    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);
    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_INT_TBCTR_U_CMPA);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 10U);
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);
}

int main()
{
    float32                      count;
    uint32                       compcount;
    Cdd_Pwm_HrpwmCalInstanceType Cdd_Pwm_HrpwmCalId;
    Cdd_Pwm_SfoStatusType        CddPwmHrcalStatus;
    float32                      GCddPwmDutyFine;

    DeviceSupport_Init();

    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_Hrpwm example\r\n");

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

    /* SFO function updates the HRMSTEP register with calibrated Cdd_Pwm_MEP_ScaleFactor.
     * HRMSTEP must be populated with a scale factor prior to enabling high resolution period control
     */
    Cdd_Pwm_HrpwmCalId = CddPwmConf_CddPwmHrpwmCalConfig_CddPwmHrpwmCalConfig_0;
    do
    {
        CddPwmHrcalStatus = Cdd_Pwm_Sfo(Cdd_Pwm_HrpwmCalId);
        if (CddPwmHrcalStatus == CDD_PWM_SFO_ERROR)
        {
            /* SFO function returns 2 if an error occurs & # of MEP steps/coarse step exceeds maximum of 255. */
            error();
        }
    } while (CddPwmHrcalStatus == CDD_PWM_SFO_INCOMPLETE);

    /* Configure PWM hardware instances */
    Cdd_Pwm_ConfigureHw();

    AppUtils_Printf("EPWM1 instance is operating in normal PWM mode\r\n");
    AppUtils_Printf("EPWM2 instance is operating in high-resolution mode\r\n");
    AppUtils_Printf("Increment the duty cycle by 0.01%% percent for every iteration from 4%% to 99.99%%\r\n");

    /* Increase duty cycle by 0.01 for every iteration */
    for (GCddPwmDutyFine = CDD_PWM_HRPWM_DUTY; GCddPwmDutyFine < 99.9; GCddPwmDutyFine += 0.01)
    {
        count     = (GCddPwmDutyFine * (float32)(CDD_PWM_TBPRD << 8)) / 100;
        compcount = (uint32)count;

        /* Load new compare values to normal compare value field */
        Cdd_Pwm_HrpwmSetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_A,
                                            (compcount & 0xFFFFFF00U));
        Cdd_Pwm_HrpwmSetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_OUTPUT_B,
                                            (compcount & 0xFFFFFF00U));

        /* Load new compare values to both normal & HR compare value fields */
        Cdd_Pwm_HrpwmSetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_A,
                                            compcount);
        Cdd_Pwm_HrpwmSetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_OUTPUT_B,
                                            compcount);

        /*
         * Call the scale factor optimizer lib function SFO() periodically to track for any change due to
         * temp/voltage. This function generates Cdd_Pwm_MEP_ScaleFactor by running the MEP calibration module in the
         * HRPWM logic. This scale factor can be used for all HRPWM channels. The SFO() function also updates the
         * HRMSTEP register with the scale factor value.
         */
        /* In background, MEP calibration module continuously updates Cdd_Pwm_MEP_ScaleFactor */
        CddPwmHrcalStatus = Cdd_Pwm_Sfo(Cdd_Pwm_HrpwmCalId);

        if (CddPwmHrcalStatus == CDD_PWM_SFO_ERROR)
        {
            /* SFO function returns 2 if an error occurs & # of MEP steps/coarse step exceeds maximum of 255. */
            error();
        }
        McalLib_Delay(50000U); /* 1ms delay */
    }

    McalLib_Delay(50000000U); /* 1second */

    Cdd_Pwm_DisableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1);

    AppUtils_Printf("Number of rising edges detected for EPWM2 are %d\r\n",
                    (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]));

    AppUtils_Printf("Waveforms can be observed on the configured EPWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_Hrpwm example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_Hrpwm.c
 *********************************************************************************************************************/
