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
 *  File:       Cdd_Adc_Example_Ppb_TrigRepeater.c
 *  Generator:  None
 *
 *  Description:  Cdd_Adc example source file. This example tests the hardware group conversions
 *  whose trigger source is trigger repeater. Also an interrupt can trigger other group conversions
 *  which is tested in this example.
 *
 * Steps followed in the example:
 * EcuM_Init()
 * - Initialize clock to 200 MHz using Mcu_Init()
 * - Initialize pins in analog mode with Port_Init()
 * - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 * - Initialize Gpt driver using Gpt_Init() to use start timer API.
 *      Timer interrupt acts as a hardware trigger source for ADC sample conversion in this example.
 * Verification of Cdd_Adc PPB and trigger repeater features functionalities together
 * Verify group conversions with trigger repeater as the trigger source. CPU1 timer interrupt as the
 * trigger source for the trigger repeater.
 * Connect voltage greater than 0.7V to ADCAIN0 pins to observe PPB trip interrupts respectively.
 * Connect a non-zero voltage to ADCAIN28 & ADCAIN6 pins to observe PPB trip interrupts respectively.
 * Group0 & Group3 are triggered by trigger repeater configured in over-sampling mode
 * Group1 is triggered by trigger repeater configured in under-sampling mode
 * Group2 is triggered by timer interrupt
 * Group4 is a configured for continuous conversions triggered by software
 * Group5 is triggered by the ADC interrupt generated by group4 after a round of channel conversions.
 * Number of timer interrupts required to complete the group conversions in over-sampling & under-sampling modes
 * are printed.
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
#include "hw_memmap.h"
#include "hw_epwm.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define DEV_TIMER_CLK_FREQ_HZ (200000000U) /* Timer clock frequency in Hz */

#define GPT_TIME_MS_1 (1000U) /* 1 ms */

#define GPT_COUNT_VALUE_1MS (DEV_TIMER_CLK_FREQ_HZ / 1000000U) * GPT_TIME_MS_1

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

uint8  Cdd_Adc_PpbEvtInt[CDD_ADC_PPB_CNT]         = {0U};
uint16 Cdd_Adc_GroupNotifCount[CDD_ADC_GROUP_CNT] = {0U};

uint16 Cdd_Adc_DelayStamp = 0U, Gpt_IntCount = 0U;

Cdd_Adc_PpbValType Cdd_Adc_PpbValue[CDD_ADC_PPB_CNT];

Cdd_Adc_ValueGroupType Cdd_Adc_Buffer[CDD_ADC_GROUP_CNT][100U];

Cdd_Adc_ValueGroupType Cdd_Adc_ResultBuffer[CDD_ADC_GROUP_CNT][100U];

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

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Adc_Grp0Notification(void)
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_0]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1);
    }
    else
    {
        /* Do nothing */
    }

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_0] == 4U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    }
    else if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_0,
                          &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);
        Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    }
}

void Cdd_Adc_Grp1Notification(void)
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_1]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2);
    }
    else
    {
        /* Do nothing */
    }

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_1] == 4U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    }
    else if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_1,
                          &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);
        Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    }
}

void Cdd_Adc_Grp2Notification(void)
{
    /* Read the group conversion results and increment the group notification count */
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_2) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_2]++;
    }
    else
    {
        /* Do nothing */
    }

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_2] == 4U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    }
    else if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_2) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_2,
                          &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_2][0]);
        Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    }
}

void Cdd_Adc_Grp3Notification(void)
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_3) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_3]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0);
    }
    else
    {
        /* Do nothing */
    }

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_3] == 4U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_3);
    }
    else if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_3) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_3,
                          &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_3][0]);
        Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_3);
    }
}

void Cdd_Adc_Hw1Grp0Notification(void)
{
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_4]++;
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_4, &Cdd_Adc_Buffer[CddAdcConf_CddAdcGroup_CddAdcGroup_4][0]);
}

void Cdd_Adc_Hw1Grp1Notification(void)
{
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_5]++;
    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_5] == 3U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_5);
    }
}

void Cdd_Adc_Ppb0Notification(void)
{
    /* Increment every time the notification function is called */
    Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0]++;
}

void Cdd_Adc_Ppb1Notification(void)
{
    /* Increment every time the notification function is called */
    Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1]++;
}

void Cdd_Adc_Ppb2Notification(void)
{
    /* Increment every time the notification function is called */
    Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2]++;
}

/* GPT timer channel 0 notification function */
void Gpt_Notify_Func_0(void)
{
    Gpt_IntCount++;
}

int main()
{
    Gpt_IntCount = 0U;
    DeviceSupport_Init();
    EcuM_Init();

    AppUtils_Init(200000000U); /* Init App utils to enable prints */
    AppUtils_Printf("Executing Cdd_Adc_Example_Ppb_TrigRepeater example\n");

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

    for (uint8 group = 0U; group < CDD_ADC_GROUP_CNT; group++)
    {
        Cdd_Adc_GroupNotifCount[group] = 0U;
    }

    /* Set group result buffer */
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_0,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_1,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_2,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_2][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_3,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_3][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_4,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_4][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcGroup_CddAdcGroup_5,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_5][0]);

    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0, TRUE);
    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1, TRUE);
    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2, TRUE);

    /* Enable group notification */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_3);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_4);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_5);

    /* Enable Gpt timer interrupts to PIPE */
    Gpt_EnableNotification(0U);
    /* Start GPT timer */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Configure group with trigger repeater in oversampling mode */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    /* Configure group with trigger repeater in undersampling mode */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    /* Timer interrupt as the group trigger */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    /* Configure group with trigger repeater in oversampling mode */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_3);

    /* Start the hardware group conversion first so that no software interrupt trigger is missed */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_5);
    /* Start the software group conversion whose interrupt triggers the above hardware group
     * conversion */
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_4);

    /* Wait until all group conversions are done */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_5) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_4) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_2) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_3) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    /* Stop timer */
    Gpt_StopTimer(0U);
    Gpt_IntCount                                                  = 0U;
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_1] = 0U;

    /* Re-running the trigger repeater group */
    /* Enable the group conversion again because the notification is disabled with
     * Cdd_Adc_DisableHardwareTrigger API*/
    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2, TRUE);

    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_1);

    /* Start GPT timer */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Wait until the group conversion is done */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    AppUtils_Printf("Gpt Interrupt Count in undersampling mode is %d\n", Gpt_IntCount);

    /* Stop timer */
    Gpt_StopTimer(0U);
    Gpt_IntCount                                                  = 0U;
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcGroup_CddAdcGroup_0] = 0U;

    /* Re-running the trigger repeater group */
    /* Enable the group conversion again because the notification is disabled with
     * Cdd_Adc_DisableHardwareTrigger APIs*/
    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1, TRUE);

    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcGroup_CddAdcGroup_0);

    /* Start GPT timer */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Wait until the group conversion is done */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_0) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    AppUtils_Printf("Gpt Interrupt Count in oversampling mode is %d\n", Gpt_IntCount);

    /* Stop timer */
    Gpt_StopTimer(0U);

    /* Deinitialize Gpt driver */
    Gpt_DeInit();

    AppUtils_Printf("PPB1 notification count is %d\n", Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0]);
    AppUtils_Printf("PPB2 notification count is %d\n", Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1]);
    AppUtils_Printf("PPB3 notification count is %d\n", Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2]);

    /* Deinitialize Adc driver */
    Cdd_Adc_DeInit();

    AppUtils_Printf("Cdd_Adc_Example_Ppb_TrigRepeater executed successfully\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Example_Ppb_TrigRepeater.c
 *********************************************************************************************************************/
