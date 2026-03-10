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
 *  File:       Cdd_Pwm_Example_UpCountMode.c
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
 * - In simple mode, on calling Cdd_Pwm_Init API all the PWM channels will be started with the
 *   configured default values.
 * Enable channel A rising edge notifications for both the PWM instances
 * Set the all the outputs to IDLE with Cdd_Pwm_SetOutputToIdle API
 * Activate the channels and change the duty cycle of the waveform with Cdd_Pwm_SetDutyCycle() API
 * and observe the change in the generated PWM output waveform.
 * Set PWM1 outputs to IDLE with Cdd_Pwm_SetOutputToIdle API Activate the channels & period of the channels
 * associated to EPWM1 instance with Cdd_Pwm_SetPeriod() API and observe the change in the frequency of the generated
 * output waveforms
 *
 * EPWM waveform can be observed on the respective pins configured in EPWM mode
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

#define OS_COUNTER_ID       ((Os_CounterIdType)0U)
#define CDD_PWM_EVENT_COUNT ((uint8)1U)

#define CDD_PWM_100HZ_PERIOD          (31249U)
#define CDD_PWM_DUTY_CYCLE_25_PERCENT (0x2000U)
#define CDD_PWM_DUTY_CYCLE_50_PERCENT (0x4000U)
#define CDD_PWM_DUTY_CYCLE_75_PERCENT (0x6000U)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* Array to store the notification of the PWM instances */
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

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Pwm_AsymmetricNotification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]++;
}

void Cdd_Pwm_SymmetricNotification()
{
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]++;
}

int main()
{
    /* Set the notification count to zero */
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] = 0U;
    Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] = 0U;
    Os_TickType start_time, elapsed_time;

    DeviceSupport_Init();
    /* Initilaize all modules */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Initialize AppUtils to enable prints
    AppUtils_Printf("Executing Cdd_Pwm_Example_UpCountMode example\r\n");

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

    GetCounterValue((Os_CounterIdType)OS_COUNTER_ID, &start_time);

    McalLib_Delay(50000000U);

    /* Set all channels in the IDLE state */
    Cdd_Pwm_SetOutputToIdle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_0);
    Cdd_Pwm_SetOutputToIdle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_1);
    Cdd_Pwm_SetOutputToIdle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_2);
    Cdd_Pwm_SetOutputToIdle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_3);

    /* Enable channel notification */
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_EVENT_COUNT);
    Cdd_Pwm_SetInterruptEventCount(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1, CDD_PWM_EVENT_COUNT);

    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_0, CDD_PWM_RISING_EDGE);
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_1, CDD_PWM_RISING_EDGE);

    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_2, CDD_PWM_RISING_EDGE);
    Cdd_Pwm_EnableNotification(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_3, CDD_PWM_RISING_EDGE);

    McalLib_Delay(5000000U);

    /* Set Duty cycle */
    Cdd_Pwm_SetDutyCycle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_0, CDD_PWM_DUTY_CYCLE_25_PERCENT);
    Cdd_Pwm_SetDutyCycle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_1, CDD_PWM_DUTY_CYCLE_75_PERCENT);
    Cdd_Pwm_SetDutyCycle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_2, CDD_PWM_DUTY_CYCLE_50_PERCENT);
    Cdd_Pwm_SetDutyCycle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_3, CDD_PWM_DUTY_CYCLE_25_PERCENT);

    AppUtils_Printf("The duty cycles of the EPWM1 & EPWM2 channels have been modified\r\n");

    McalLib_Delay(60000000U);

    AppUtils_Printf(
        "The notification count for EPWM1 instance after calling Cdd_Pwm_SetDutyCycle API is "
        "%d\r\n",
        Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]);
    AppUtils_Printf(
        "The notification count for EPWM2 instance after calling Cdd_Pwm_SetDutyCycle API is "
        "%d\r\n",
        Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]);

    /* Set the output to IDLE */
    Cdd_Pwm_SetOutputToIdle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_0);
    Cdd_Pwm_SetOutputToIdle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_1);
    Cdd_Pwm_SetOutputToIdle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_2);
    Cdd_Pwm_SetOutputToIdle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_3);

    AppUtils_Printf("All the EPWM1 & EPWM2 channels in IDLE state\r\n");

    AppUtils_Printf(
        "The notification count for EPWM1 instance after calling Cdd_Pwm_SetDutyCycle API is "
        "%d\r\n",
        Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0]);
    AppUtils_Printf(
        "The notification count for EPWM2 instance after calling Cdd_Pwm_SetDutyCycle API is "
        "%d\r\n",
        Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1]);

    McalLib_Delay(5000000U);

    /* Change the period of EPWM1 channels */
    Cdd_Pwm_SetPeriod(CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0, CDD_PWM_100HZ_PERIOD);

    /* Change the duty cycle of EPWM2 channels */
    Cdd_Pwm_SetDutyCycle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_2, CDD_PWM_DUTY_CYCLE_25_PERCENT);
    Cdd_Pwm_SetDutyCycle(CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_3, CDD_PWM_DUTY_CYCLE_50_PERCENT);

    AppUtils_Printf("The frequency of EPWM1 has been doubled(period halved)\r\n");
    AppUtils_Printf("The duty cycle of the EPWM2 channels have been modified\r\n");

    McalLib_Delay(50000000U);

    GetElapsedValue((Os_CounterIdType)OS_COUNTER_ID, &start_time, &elapsed_time);

    /* DeInitialize PWM */
    Cdd_Pwm_DeInit();

    AppUtils_Printf(
        "Time elapsed in US(microsecond) from when the notification is enabled until Deinit is "
        "%d\r\n",
        elapsed_time);

    AppUtils_Printf(
        "Number of rising edges detected for EPWM1 are %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0] * CDD_PWM_EVENT_COUNT));
    AppUtils_Printf(
        "Number of edges detected for EPWM2 are %d\r\n",
        (Cdd_Pwm_NotificationCount[CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1] * CDD_PWM_EVENT_COUNT));

    AppUtils_Printf("Waveforms can be observed on the configured EPWM pins\r\n");
    AppUtils_Printf("Cdd_Pwm_Example_UpCountMode executed successfully\r\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Example_UpCountMode.c
 *********************************************************************************************************************/
