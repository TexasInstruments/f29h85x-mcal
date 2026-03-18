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
 *  File:       Cdd_Pwm_Example_GlobalLoad_And_Link.c
 *  Generator:  None
 *
 *  Description:  Cdd_Pwm example source file.This example demonstrates global load and linking features.
 *                When global load mode is selected the transfer of contents from shadow register to active register,
 *                for all registers that have this mode enabled, occurs at the same configured event.
 *                Linking allows simultaneous writes of registers between EPWM instances. All EPWM individual
 *                module instances are mirrored to the XLINK region. If multiple EPWM instances have this feature
 *                enabled, then any writes in the XLINK region of an EPWM instance reflects to all other instances
 *                that have the linking enabled. If the write occurs in the individual register memory space,
 *                then the update only reflects on that individual EPWM.
 *
 * Setup required for the example:
 * Connect the GPIO pins configured for EPWM to the logic analyzer to observe the PWM channel output waveforms.
 *
 * Steps followed in the example:
 * DeviceSupport_Init()
 *  - Initialize FLASH if the example is run in FLASH mode
 * EcuM_Init()
 *  - Initialize clock to 100 MHz using Mcu_Init()
 *  - Initialize pins in EPWM mode with Port_Init()
 *  - Initialize Cdd_Pwm driver using Cdd_Pwm_Init() to enable XLINK for the EPWM instances
 *  - Cdd_Pwm_ConfigureHw() as follows
 *      - For EPWM1 enable notification and linking
 *      - For EPWM2 enable global load and linking. TBCTR = Period is the configured global load trigger and the event
 *          prescale is configured to 7.
 *      - For EPWM3 enable linking
 *      - For EPWM7 enable linking
 *      - Configure prescaler, compare values and action qualifier actions using linking
 *
 * Load a period value to all EPWM instances using XLINK. This period value results in 50% duty cycle for all the
 * EPWM OUTPUT A channels.
 *
 * Counter compare A values are updated at 3rd period event for EPWM1 & EPWM2A channels. The configured
 * global load event prescale is 7 which is enabled only for EPWM2 instance. So, the update in the
 * compare compare values(shadow to active at 3rd period event) can be observed in only EPWM1A's output.
 *
 * Update in the compare compare B value(shadow to active at 7rd period event) can be observed in both
 * EPWM1A & EPWM2A channels.
 *
 * As a result, the duty cycle of the EPWM1A will jump from 50% to 25% and then to 20%.
 * But EPWM2A's duty cycle will jump from 50% to 20% while EPWM3 & EPWM7 instances maintain their duty cycles at 50%.
 *
 * Wait for 1 second and update the compare B value for all the EPWM instances using linking.
 *
 * With the latest compare B value, the duty cycle of EPWM3 & EPWM7's OUTPUT A will jump to 75%.
 * Duty cycle of EPWM1 & EPWM2's channel A will jump to 50%.
 *
 * Print the notification count to of all EPWM instances.
 *
 *  EPWM waveform can be observed on the respective pins configured in EPWM mode
 * \b External \b Connections \n
 * - GPIO0 EPWM1A
 * - GPIO2 EPWM2A
 * - GPIO4 EPWM3A
 * - GPIO27 EPWM4A
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

#define CDD_PWM_EVENT_COUNT ((uint8)1U)

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

void Cdd_Pwm_ConfigureHw(void);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Pwm_HwUnit0Notification(void)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;

    if (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] == 3U)
    {
        /* New compare values for only EPWM1 & EPWM2 */
        Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_A,
                                       15825U);
        Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_A,
                                       15825U);
        AppUtils_Printf("Load new compare A value to the both EPWM1 & EPWM2 instances \r\n");
    }

    if (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] == 7U)
    {
        /* New compare values for only EPWM1 & EPWM2 */
        Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_COUNTER_COMPARE_B,
                                       28325U);
        Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_COUNTER_COMPARE_B,
                                       28325U);
        AppUtils_Printf("Load new compare B value to the both EPWM1 & EPWM2 instances \r\n");
    }
}

void Cdd_Pwm_HwUnit1Notification(void)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]++;
}

void Cdd_Pwm_HwUnit2Notification(void)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2]++;
}

void Cdd_Pwm_HwUnit3Notification(void)
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_3]++;
}

void Cdd_Pwm_ConfigureHw(void)
{
    /* Configure EPWM1 instance */
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0);

    /* Configure for EPWM2 instance */
    Cdd_Pwm_ConfigureGlobalLoad(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, TRUE);
    Cdd_Pwm_SetGlobalLoadTrigger(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_GL_LOAD_PULSE_CNTR_PERIOD);
    Cdd_Pwm_SetGlobalLoadEventPrescale(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, 7U);
    Cdd_Pwm_ConfigureGlobalLoadRegisters(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                         CDD_PWM_GL_REGISTER_CMPA_CMPAHR, TRUE);
    Cdd_Pwm_ConfigureGlobalLoadRegisters(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1,
                                         CDD_PWM_GL_REGISTER_CMPB_CMPBHR, TRUE);

    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, TRUE);

    Cdd_Pwm_SetInterruptSource(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_INT_TBCTR_ZERO);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_EVENT_COUNT);

    /* Configure the XLINK memory region to write into EPWM 1,2,3 & 7 instances at the same time */
    Cdd_Pwm_SetClockPrescaler(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_CLOCK_DIVIDER_4,
                              CDD_PWM_HSCLOCK_DIVIDER_8);
    Cdd_Pwm_SetTimeBaseCounterMode(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_COUNTER_MODE_UP);
    Cdd_Pwm_SetTimeBaseCounter(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, 0U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_COUNTER_COMPARE_A, 200U);
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_COUNTER_COMPARE_B, 31450U);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_HIGH, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);
    Cdd_Pwm_SetActionQualifierAction(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_OUTPUT_A,
                                     CDD_PWM_AQ_OUTPUT_LOW, CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
}

int main()
{
    DeviceSupport_Init();
    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_GlobalLoad_And_Link example\r\n");

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

    /* Configure EPWM hardware instances */
    Cdd_Pwm_ConfigureHw();

    AppUtils_Printf("Load period to the xlink region \r\n");
    Cdd_Pwm_SetTimeBasePeriod(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, 62499U);

    /* Wait for 1 second */
    McalLib_Delay(50000000U);

    AppUtils_Printf("Load new compare B value to the xlink region \r\n");
    /* Update the counter compare value for all EPWM instances */
    Cdd_Pwm_SetCounterCompareValue(CddPwmConf_CddPwmXlinkConfig_CddPwmXlinkConfig_0, CDD_PWM_COUNTER_COMPARE_B, 47075U);

    /* Approximately 1second */
    McalLib_Delay(50000000U);

    Cdd_Pwm_ConfigureInterrupt(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, FALSE);

    AppUtils_Printf(
        "Notification count for the EPWM1 instance is %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] * CDD_PWM_EVENT_COUNT));

    AppUtils_Printf("Generated waveforms can be observed on the configured EPWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_GlobalLoad_And_Link example executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_GlobalLoad_And_Link.c
 *********************************************************************************************************************/
