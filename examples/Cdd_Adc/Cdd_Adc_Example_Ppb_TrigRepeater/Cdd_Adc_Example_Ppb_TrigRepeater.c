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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
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
 * Verification of Cdd_Adc PPB and trigger repeater features functionalities together
 * Verify group conversions with trigger repeater as the trigger source. CPU1 timer interrupt as the
 * trigger source for the trigger repeater. Verification of group conversions in oversampling and
 * under sampling trigger repeater mode. Verification of trigger repeater groups with normal
 * hardware and software triggered groups.
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
#define TIMER_CLK_FREQ_HZ (20000000U) /* Timer clock frequency in Hz */
#define GPT_TIME_US_1     (10000U)    /* 10 ms */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

#define GPT_COUNT_VALUE_1MS (TIMER_CLK_FREQ_HZ / 100000U) * GPT_TIME_US_1

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

void Cdd_Adc_Grp0Notification()
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_1] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_1);
    }
    else
    {
        /* Do nothing */
    }

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0] == 4U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    }
    else if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0,
                          &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0][0]);
        Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    }
}

void Cdd_Adc_Grp1Notification()
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_2] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_2);
    }
    else
    {
        /* Do nothing */
    }

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1] == 4U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1);
    }
    else if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1,
                          &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1][0]);
        Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1);
    }
}

void Cdd_Adc_Grp2Notification()
{
    /* Read the group conversion results and increment the group notification count */
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2]++;
    }
    else
    {
        /* Do nothing */
    }

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2] == 4U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2);
    }
    else if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2,
                          &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2][0]);
        Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2);
    }
}

void Cdd_Adc_Grp3Notification()
{
    if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_0] =
            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_0);
    }
    else
    {
        /* Do nothing */
    }

    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3] == 4U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3);
    }
    else if (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3,
                          &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3][0]);
        Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3);
    }
}

void Cdd_Adc_Hw1Grp0Notification()
{
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0]++;
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0,
                      &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0][0]);
}

void Cdd_Adc_Hw1Grp1Notification()
{
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_1]++;
    if (Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_1] == 3U)
    {
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_1);
    }
}

void Cdd_Adc_Ppb0Notification()
{
    /* Increment every time the notification function is called */
    Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_0]++;
}

void Cdd_Adc_Ppb1Notification()
{
    /* Increment every time the notification function is called */
    Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_1]++;
}

void Cdd_Adc_Ppb2Notification()
{
    /* Increment every time the notification function is called */
    Cdd_Adc_PpbEvtInt[CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_2]++;
}

/* GPT timer channel 0 notification function */
void Gpt_Notify_Func_0(void)
{
    Gpt_IntCount++;
}

int main()
{
    DeviceSupport_Init();
    EcuM_Init();

    AppUtils_Init(200000000U); /* Init App utils to enable prints */
    AppUtils_Printf(" Executing Cdd_Adc_Example_Ppb_TrigRepeater example\n");

    /* Set group result buffer */
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_1,
                              &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_1][0]);

    /* Enable group notification */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_1);

    /* Enable Gpt timer interrupts to PIPE */
    Gpt_EnableNotification(0U);
    /* Start GPT timer */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Configure group with trigger repeater in oversampling mode */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    /* Configure group with trigger repeater in undersampling mode */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1);
    /* Timer interrupt as the group trigger */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2);
    /* Configure group with trigger repeater in oversampling mode */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3);

    /* Start the hardware group conversion first so that no software interrupt trigger is missed */
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_1);
    /* Start the software group conversion whose interrupt triggers the above hardware group
     * conversion */
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);

    /* Wait until all group conversions are done */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_1) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_2) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_3) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1) != CDD_ADC_IDLE) ||
           (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    /* Stop timer */
    Gpt_StopTimer(0U);
    Gpt_IntCount = 0U;

    /* Re-running the trigger repeater group */
    /* Enable the group conversion again because the notification is disabled with
     * Cdd_Adc_DisableHardwareTrigger API*/
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1);

    /* Start GPT timer */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Wait until the group conversion is done */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_1) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    AppUtils_Printf("Gpt Interrupt Count in undersampling mode is %d\n", Gpt_IntCount);

    /* Stop timer */
    Gpt_StopTimer(0U);
    Gpt_IntCount = 0U;

    /* Re-running the trigger repeater group */
    /* Enable the group conversion again because the notification is disabled with
     * Cdd_Adc_DisableHardwareTrigger APIs*/
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);

    /* Start GPT timer */
    Gpt_StartTimer(0U, GPT_COUNT_VALUE_1MS);

    /* Wait until the group conversion is done */
    while ((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) != CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    AppUtils_Printf("Gpt Interrupt Count in oversampling mode is %d\n", Gpt_IntCount);

    /* Stop timer */
    Gpt_StopTimer(0U);

    /* Deinitialize Gpt driver */
    Gpt_DeInit();

    /* Deinitialize Adc driver */
    Cdd_Adc_DeInit();

    AppUtils_Printf("Cdd_Adc_Example_Ppb_TrigRepeater executed successfully\n");

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Example_Ppb_TrigRepeater.c
 *********************************************************************************************************************/
