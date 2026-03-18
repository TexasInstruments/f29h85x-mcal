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
 *  File:       Cdd_Adc_Example_Differential.c
 *  Generator:  None
 *
 *  Description:  Cdd_Adc example source file.This example demonstrates 16-bit differential mode for
 *  ADC instance A. Delay stamp is also printed which is the number of system clock cycles delay
 *  between the group trigger and the actual start of the group conversion. Delay stamp API can only be called for
 *  PPBs which are linked to the groups that are configured for hardware triggers.
 *  ADC support two signal modes:
 *  In single-ended mode, the input voltage to the converter is sampled through a single pin (ADCINx), referenced to
 *  VREFLO.
 *  In differential signaling mode, the input voltage to the converter is sampled through a pair of input pins, one of
 *  which is the positive input (ADCINxP) and the other is the negative input (ADCINxN). The actual input voltage is
 *  the difference between the two (ADCINxP – ADCINxN).
 *
 * \note Only 16-bit ADC instances support both modes. 12-bit only ADC instances support only single-ended mode.
 *
 * In this example ADCA & ADCB(16-bit ADCs) instances are configured for differential mode.
 * ADCD(12-bit only ADC) is configured for single-ended mode.
 *
 * Setup required for the example:
 * Since ADCA & ADCB are configured for external voltage reference mode, connect external voltage to VREFHIAB pin and
 * VREFLOAB to GND (Put Switch S3 & S4 as per external voltage reference mode).
 * Connect the external voltage to ADCAIN0,ADCAIN1 pins whose difference is considered as the input for the
 * conversion. Similarly, connect the external voltage to ADCAIN6 and ADCAIN7 pins and observe the ADC conversion
 * results from the buffer.
 * Connect the external available voltage to ADCBIN0,ADCBIN1 pins whose difference is considered as input to ADC
 * for the conversion. Likewise, connect the external voltage to ADCBIN2 and ADCBIN3 pins and observe the ADC
 * conversion results from the buffer.
 * ADCDIN0,ADCDIN2,ADCDIN3 & ADCDIN10 should be connected with desired voltage and the conversion results
 * can be observed in the configured result buffer (ADCD is configured for internal voltage reference mode).
 *
 * Steps followed in the example:
 * EcuM_Init()
 * - Initialize clock to 200 MHz using Mcu_Init()
 * - Initialize pins in analog mode with Port_Init()
 * - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 * - Initialize Gpt driver using Gpt_Init() to use start timer API.
 *      Timer interrupt acts as a hardware trigger source for ADC sample conversion in this example.
 * Cdd_Adc_SetupResultBuffer API sets up the result buffer for the specified group. Channel conversion results
 * that are linked to the group will be copied to this buffer.
 * Cdd_Adc_EnableGroupNotification API enables notification for the specified group
 * Wait until all group conversions are done.
 * Print Group0 & Group1 channel conversion results
 * Change the resolution of the ADCA instance to 12-bit & ADCB instance to 16-bit.
 * Start the group conversions again and observe conversions results in result buffer.
 * Wait until all group conversions are done.
 * Delay stamp is captured for the hardware triggered group
 * Print Group0 & Group1 channel conversion results
 * ADC conversion results can be observed before and after the resolution change by checking the
 * result buffer
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

uint8 Cdd_Adc_GroupNotifCount[CDD_ADC_GROUP_CNT] = {0U}, count = 0U;

uint16 Cdd_Adc_DelayStamp = 0U, Gpt_IntCount = 0U;

sint16 Cdd_Adc_PpbResult[CDD_ADC_PPB_CNT];

Cdd_Adc_PpbValType Cdd_Adc_PpbValue[CDD_ADC_PPB_CNT];

Cdd_Adc_ValueGroupType Cdd_Adc_Buffer[CDD_ADC_GROUP_CNT][10U];

Cdd_Adc_ValueGroupType Cdd_Adc_ResultBuffer[CDD_ADC_GROUP_CNT][10U];

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

void Cdd_Adc_Grp0Notification(void)
{
    /* Read the group conversion results and get PPB values when the stream is complete */
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_0]++;
        /* Read PPB final register values */
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0);
    }

    /* Read PPB result */
    Cdd_Adc_PpbResult[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0] =
        Cdd_Adc_ReadPpb(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0);
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_0, &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_0] == 3U)
    {
        /* After the streaming buffer is filled completely for the group */
        Cdd_Adc_StopGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    }
}

void Cdd_Adc_Grp1Notification(void)
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_1]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1);
    }

    /* Read PPB result */
    Cdd_Adc_PpbResult[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1] =
        Cdd_Adc_ReadPpb(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1);
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_1, &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);
    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_1] == 3U)
    {
        /* After the streaming buffer is filled completely for the group */
        Cdd_Adc_StopGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    }
}

void Cdd_Adc_Grp2Notification(void)
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_2) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_DelayStamp = Cdd_Adc_GetDelayStamp(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2);
        AppUtils_Printf("Delaystamp for PPB%d is %d\n", CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2,
                        Cdd_Adc_DelayStamp);
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_2]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2);
    }

    /* Read PPB result */
    Cdd_Adc_PpbResult[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2] =
        Cdd_Adc_ReadPpb(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2);
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_2, &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_2][0]);
    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_2] == 3U)
    {
        /* After the streaming buffer is filled completely for the group */
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    }
}

void Cdd_Adc_Grp3Notification(void)
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_3) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_3]++;
    }
    /* Read group conversion results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_3, &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_3][0]);
    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_3] == 3U)
    {
        /* After the streaming buffer is filled completely for the group */
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_3);
    }
}

int main()
{
    DeviceSupport_Init();
    EcuM_Init();

    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Executing Cdd_Adc_Example_Differential example\n");

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
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_1,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_2,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_2][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_3,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_3][0]);

    /* Enable group notification */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_3);

    /* Enable timer interrupt which is the trigger source for the hardware trigger group conversion
     */
    Gpt_EnableNotification(0U);
    /* Configure the timer in the continuous mode with 1millisecond as the time period */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Configure all the groups in streaming circular buffer modes */
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_3);

    /* Wait here until all group conversions are stopped */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_2) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_3) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    AppUtils_Printf("ADCA Group0 conversion results in 16bit mode are:\n\r");
    for (uint8 channel = 0U; channel < 2U; channel++)
    {
        AppUtils_Printf("Channel%d result is %d\n", channel,
                        Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][channel]);
    }

    AppUtils_Printf("ADCB Group1 conversion results in 12bit mode are:\n\r");
    for (uint8 channel = 0U; channel < 2U; channel++)
    {
        AppUtils_Printf("Channel%d result is %d\n", channel,
                        Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][channel]);
    }

    /* Reset the group notification count values */
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_0] = 0U;
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_1] = 0U;
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_2] = 0U;
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_3] = 0U;

    /* Change the ADC hardware unit 0 resolution to 12-bit */
    Cdd_Adc_SetResolution(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0, CDD_ADC_RESOLUTION_12BIT);

    AppUtils_Printf("Change the ADCA resolution to 12-bit\n");

    /* Change the ADC hardware unit 1 resolution to 12-bit */
    Cdd_Adc_SetResolution(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1, CDD_ADC_RESOLUTION_16BIT);

    AppUtils_Printf("Change the ADCB resolution to 16-bit\n");

    /* Group notification will be enabled after StopGroupConversion API,
    to enable again EnableGroupNotification API should be called  */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_3);

    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_3);

    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_2) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_3) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    AppUtils_Printf("ADCA Group0 conversion results in 12bit mode are:\n\r");
    for (uint8 channel = 0U; channel < 2U; channel++)
    {
        AppUtils_Printf("Channel%d result is %d\n", channel,
                        Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][channel]);
    }

    AppUtils_Printf("ADCB Group1 conversion results in 16bit mode are:\n\r");
    for (uint8 channel = 0U; channel < 2U; channel++)
    {
        AppUtils_Printf("Channel%d result is %d\n", channel,
                        Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][channel]);
    }

    /* Stop the timer */
    Gpt_StopTimer(0U);
    /* Deinitialize GPT */
    Gpt_DeInit();

    /* DeInitialize ADC */
    Cdd_Adc_DeInit();

    AppUtils_Printf("Cdd_Adc_Example_Differential executed successfully\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Example_Differential.c
 *********************************************************************************************************************/
