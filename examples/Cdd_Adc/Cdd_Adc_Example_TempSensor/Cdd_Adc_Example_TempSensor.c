/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
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
 *  File:       Cdd_Adc_Example_TempSensor.c
 *  Generator:  None
 *
 *  Description:  Cdd_Adc example source file. Channel ID 20 on ADCA and ADCC are both connected to
 *  the temperature sensor internally. The ADC conversion results can be passed to GetTemperatureC
 *  & GetTemperatureC APIs to get the temperature value in Celsius and Kelvin respectively.
 *
 * Steps followed in the example:
 * EcuM_Init()
 * - Initialize clock to 200 MHz using Mcu_Init()
 * - Initialize pins using Port_Init() to see the print statements on the console
 * - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 * - Initialize Gpt driver using Gpt_Init() to use start timer API.
 *      Timer interrupt acts as a hardware trigger source for ADC sample conversion in this example.
 * Verification of Cdd_Adc temperature sensor values
 * Channel ID 20 on ADCA and ADCC are both connected to the temperature sensor internally.
 * The ADC conversion results can be passed to GetTemperatureC & GetTemperatureC APIs to get the
 * temperature value in Celsius and Kelvin respectively.
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
#include "Cdd_Adc.h"
#include "Port.h"
#include "Mcu.h"
#include "Gpt.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define TIMER_CLK_FREQ_HZ (20000000U) /* Timer clock frequency in Hz */
#define GPT_TIME_US_1     (10000U)    /* 10 ms */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

#define GPT_COUNT_VALUE_1MS (TIMER_CLK_FREQ_HZ / 100000U) * GPT_TIME_US_1

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

uint16                 Gpt_IntCount = 0U;
Cdd_Adc_ValueGroupType Cdd_Adc_Buffer[CDD_ADC_GROUP_CNT][10U], Cdd_Adc_ResultBuffer[CDD_ADC_GROUP_CNT][10U];
sint16                 Cdd_Adc_ADCA_TempC, Cdd_Adc_ADCC_TempC, Cdd_Adc_ADCA_TempK, Cdd_Adc_ADCC_TempK;

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Adc_VersionInfo;
#endif

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* GPT timer channel 0 notification function */
void Gpt_Notify_Func_0(void)
{
    Gpt_IntCount++;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Adc_Group1Notification(void)
{
    /* When the group status is IDLE the read the temperature sensor value in temperature */
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        /* Read group results */
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0,
                          &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);
        Cdd_Adc_ADCA_TempC = Cdd_Adc_GetTemperatureC(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0,
                                                     Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);
        Cdd_Adc_ADCA_TempK = Cdd_Adc_GetTemperatureK(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0,
                                                     Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);
    }
}

void Cdd_Adc_Group2Notification(void)
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) == CDD_ADC_STREAM_COMPLETED)
    {
        /* Read group results */
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1,
                          &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);
        Cdd_Adc_ADCC_TempC = Cdd_Adc_GetTemperatureC(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1,
                                                     Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);
        Cdd_Adc_ADCC_TempK = Cdd_Adc_GetTemperatureK(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1,
                                                     Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);
    }
}

int main()
{
    DeviceSupport_Init();
    EcuM_Init();
    /* To print the statements */
    AppUtils_Init(200000000U);
    AppUtils_Printf("Executing Cdd_Adc_Example_TempSensor example\n");

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
    Cdd_Adc_GetVersionInfo(&Cdd_Adc_VersionInfo);
    AppUtils_Printf("CDD ADC MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Adc_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Adc_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Adc_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Adc_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Adc_VersionInfo.sw_patch_version);
#endif

    /* Set group result buffer */
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_0,
                              &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_1,
                              &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);

    /* Enable group notification */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_1);

    /* Enable timer interrupt which is the trigger source for the hardware trigger group conversion
     */
    Gpt_EnableNotification(0U);
    /* Configure the timer in the continuous mode with 1millisecond as the time period */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Start the software group conversion */
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    /* Start the hardware group conversion */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_1);

    /* Wait until both the group conversions are done */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    /* Print the temperature values that were calculated in the notification function */
    AppUtils_Printf("Temperature in Celsius converted by ADCA is %d\n", Cdd_Adc_ADCA_TempC);
    AppUtils_Printf("Temperature in Kelvin converted by ADCA is %d\n", Cdd_Adc_ADCA_TempK);
    AppUtils_Printf("Temperature in Celsius converted by ADCC is %d\n", Cdd_Adc_ADCC_TempC);
    AppUtils_Printf("Temperature in Kelvin converted by ADCC is %d\n", Cdd_Adc_ADCC_TempK);

    /* Stop the timer */
    Gpt_StopTimer(0U);
    /* Deinitialize GPT */
    Gpt_DeInit();

    /* DeInitialize ADC */
    Cdd_Adc_DeInit();

    AppUtils_Printf("Cdd_Adc_Example_TempSensor Example executed successfully\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Example_TempSensor.c
 *********************************************************************************************************************/
