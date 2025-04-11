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
 *  File:       Cdd_Adc_Example_Differential.c
 *  Generator:  None
 *
 *  Description:  Cdd_Adc example source file.This example demonstrates 16-bit differential mode for ADC instance A.
 *                  Delay stamp is also printed which the number of system clock cycles delay between the group trigger 
 *                  and the actual start of the group conversion.
 * 
 * Setup required for the example:
 * Connect external voltage to VREFHIAB pin and VREFLOAB to GND.
 * Connect the external voltage to ADCAIN2,ADCAIN3 pins whose difference is considered as the input for the conversion.
 * Similarly, connect the external voltage to ADCAIN4 and ADCAIN5 pins and observe the ADC conversion results from the 
 * buffer.
 * Connect the external available voltage to ADCBIN4,ADCBIN5 pins whose difference is considered as the input for the 
 * conversion.
 * Similarly, connect the external voltage to ADCBIN6 and ADCBIN7 pins and observe the ADC conversion results from the 
 * buffer.
 * 
 * Steps followed in the example:
 * EcuM_Init()
 * - Initialize clock to 200 MHz using Mcu_Init()
 * - Initialize pins in analog mode with Port_Init()
 * - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 * Delay stamp is captured for the hardware triggered group
 * ADC conversion results can be observed before and after the resolution change by checking the result buffer
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
#define TIMER_CLK_FREQ_HZ      (20000000U) /* Timer clock frequency in Hz */
#define GPT_TIME_US_1 (10000U)                  /* 10 ms */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

#define GPT_COUNT_VALUE_1MS     (TIMER_CLK_FREQ_HZ / 100000U) * GPT_TIME_US_1

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

uint8 Cdd_Adc_GroupNotifCount[CDD_ADC_GROUP_CNT] = {0U},count = 0U;

uint16 Cdd_Adc_DelayStamp = 0U,Gpt_IntCount = 0U;

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

void Cdd_Adc_Grp0Notification()
{
    /* Read the group conversion results and get PPB values when the stream is complete */
    if(Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0]++;
        /* Read PPB final register values */
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_0] = \
                                    Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_0);
    }

    /* Read PPB result */
    Cdd_Adc_PpbResult[CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_0] = \
                                            Cdd_Adc_ReadPpb(CddAdcConf_CddAdcHwUnit_0_CddAdcPpbConfig_0);
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0,\
                                &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0][0]);

    if(Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0] == 3U)
    {
        /* After the streaming buffer is filled completely for the group */
        Cdd_Adc_StopGroupConversion(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    }
}

void Cdd_Adc_Grp1Notification()
{
    if(Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcHwUnit_1_CddAdcPpbConfig_0] = \
                            Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcHwUnit_1_CddAdcPpbConfig_0);
    }

    /* Read PPB result */
    Cdd_Adc_PpbResult[CddAdcConf_CddAdcHwUnit_1_CddAdcPpbConfig_0] = \
                                                Cdd_Adc_ReadPpb(CddAdcConf_CddAdcHwUnit_1_CddAdcPpbConfig_0);
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0,\
                                        &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0][0]);
    if(Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0] == 3U)
    {
        /* After the streaming buffer is filled completely for the group */
        Cdd_Adc_StopGroupConversion(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);
    }
}

void Cdd_Adc_Grp2Notification()
{
    if(Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_DelayStamp = Cdd_Adc_GetDelayStamp(CddAdcConf_CddAdcHwUnit_2_CddAdcPpbConfig_0);
        AppUtils_Printf("Delaystamp for PPB%d is %d\n",CddAdcConf_CddAdcHwUnit_2_CddAdcPpbConfig_0,Cdd_Adc_DelayStamp);
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0]++;
        Cdd_Adc_PpbValue[CddAdcConf_CddAdcHwUnit_2_CddAdcPpbConfig_0] = \
                                        Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcHwUnit_2_CddAdcPpbConfig_0);
    }

    /* Read PPB result */
    Cdd_Adc_PpbResult[CddAdcConf_CddAdcHwUnit_2_CddAdcPpbConfig_0] = \
                                        Cdd_Adc_ReadPpb(CddAdcConf_CddAdcHwUnit_2_CddAdcPpbConfig_0);
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0,\
                                            &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0][0]);
    if(Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0] == 3U)
    {
        /* After the streaming buffer is filled completely for the group */
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0);
    }
}

void Cdd_Adc_Grp3Notification()
{
    if(Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1) == CDD_ADC_STREAM_COMPLETED)
    {
        Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1]++;
    }
    /* Read group conversion results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1,\
                                            &Cdd_Adc_Buffer[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1][0]);
    if(Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1] == 3U)
    {
        /* After the streaming buffer is filled completely for the group */
        Cdd_Adc_DisableHardwareTrigger(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1);
    }
}

int main()
{
    DeviceSupport_Init();
    EcuM_Init();    
    
    AppUtils_Init(200000000U); // Init App utils to enable prints
    AppUtils_Printf(" Executing Cdd_Adc_Example_Differential example\n");

    /* Set group result buffer */
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0,\
                                            &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0,\
                                        &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0,\
                                    &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0][0]);
    Cdd_Adc_SetupResultBuffer(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1,\
                                    &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1][0]);
    /* Enable group notification */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1);

    /* Enable timer interrupt which is the trigger source for the hardware trigger group conversion */
    Gpt_EnableNotification(0U);
    /* Configure the timer in the continuous mode with 1millisecond as the time period */
    Gpt_StartTimer(0U,GPT_COUNT_VALUE_1MS);

    /* Configure all the groups in streaming circular buffer modes */
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1);

    /* Wait here until all group conversions are stopped */
    while((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) != CDD_ADC_IDLE) ||\
    (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0)!=CDD_ADC_IDLE) || \
    (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0)!=CDD_ADC_IDLE) || \
    (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1)!=CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    /* Reset the group notification count values */
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0] = 0U;
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0] = 0U;
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0] = 0U;
    Cdd_Adc_GroupNotifCount[CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1] = 0U;
    
    /* Change the ADC hardware unit 1 resolution to 12-bit */
    Cdd_Adc_SetResolution(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0,CDD_ADC_RESOLUTION_12BIT);
    /* Change the ADC hardware unit 2 resolution to 16-bit */
    Cdd_Adc_SetResolution(CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1,CDD_ADC_RESOLUTION_16BIT);

    AppUtils_Printf("Change the ADCA resolution to 12-bit\n");
    AppUtils_Printf("Change the ADCB resolution to 12-bit\n");

    /* Group notification will be enabled after StopGroupConversion API, 
    to enable again EnableGroupNotification API should be called  */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1);

    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0);
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0);
    Cdd_Adc_EnableHardwareTrigger(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1);

    while((Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_0_CddAdcGroup_0) != CDD_ADC_IDLE) ||\
    (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_1_CddAdcGroup_0)!=CDD_ADC_IDLE) || \
    (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_0)!=CDD_ADC_IDLE) || \
    (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcHwUnit_2_CddAdcGroup_1)!=CDD_ADC_IDLE))
    {
        McalLib_Delay(100);
    }

    /* Stop the timer */
    Gpt_StopTimer(0U);
    /* Deinitialize GPT */
    Gpt_DeInit();

    /* DeInitialize ADC */
    Cdd_Adc_DeInit();

    AppUtils_Printf("Cdd_Adc_Example_Differential executed successfully\n");

    while(1){}

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Example_Differential.c
 *********************************************************************************************************************/
