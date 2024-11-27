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
 *  File:         Gpt_Example_MixedMode.c
 *  Generator:    None
 *
 *  Description:  This file contains Gpt examples with Init & DeInit sequence, timers in one shot and continuous mode,
 *                start & stop timers, enable & disable interrupts and time remaining & time elapsed features.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Gpt_Example_MixedMode.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

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
uint32 Gpt_InterruptCnt[GPT_CFG_MAX_CHANNELS] = {0U};

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/* main function */
int main(void)
{
    Std_ReturnType return_value = E_NOT_OK;
    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(20000000U);

    /* GPT driver Init, Deinit and Init sequence */
    Gpt_DeInit();
    AppUtils_Printf("Initialize Gpt Driver\n\r");
    AppUtils_Printf("Initializing Gpt Driver...\n\r");
    Gpt_Init(&Gpt_ConfigSetptr);
    AppUtils_Printf("API Gpt_Init executed successfully\n\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");
    AppUtils_Printf("Enable notifications for all Channels\n\r");
    /* Enable notifications for GPT channel 1. */
    Gpt_EnableNotification(GPT_CHANNEL_1);
    /* Enable notifications for GPT channel 1. */
    Gpt_EnableNotification(GPT_CHANNEL_2);
    AppUtils_Printf("Notifications enabled for all channels\n\r");
    AppUtils_Printf("API Gpt_EnableNotification executed successfully for all channels\n\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");

    AppUtils_Printf("---------------------------------------------------------------------------------------\r");
    AppUtils_Printf("\nMixed modes and Simultaneous Timers Test1"
                    "for 1s timeout - Started !!!\r\n");
    AppUtils_Printf("---------------------------------------------------------------------------------------\n\n\r");
    AppUtils_Printf(" Start timer for all Channels with 1s Timeout\n\r");
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_1S);
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_1S);
    AppUtils_Printf("Timer started for all channels with 1s Timeout\n\r");
    AppUtils_Printf("API Gpt_StartTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("Wait until all the timers get notified atleast 1 time.\r\n\n");

    /* Wait for 11 second to complete one iteration*/
    Time_Delay(1.10);
    if ((Gpt_InterruptCnt[GPT_CHANNEL_1] == 1) && \
        (Gpt_InterruptCnt[GPT_CHANNEL_2] == 1))
    {
        return_value = E_OK;
    }
    else
    {
        return_value = E_NOT_OK;
    }
    AppUtils_Printf("Stop timer for all Channels\r\n");
    /* Stop all timers */
    Gpt_StopTimer(GPT_CHANNEL_1);
    Gpt_StopTimer(GPT_CHANNEL_2);
        AppUtils_Printf("Timer stopped for all channels\n\r");
    AppUtils_Printf("API Gpt_StopTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("---------------------------------------------------------------------------------------\n\r");

    AppUtils_Printf("Deinitialize Gpt Driver\n\r");
    AppUtils_Printf("DeInitializing Gpt Driver...\n\r");
    /* DeInit the driver */
    Gpt_DeInit();
    AppUtils_Printf("API Gpt_DeInit executed successfully\n\n\r");
    AppUtils_Printf("------------------------------------------\r\n");
    
    if (E_OK == return_value)
    {
        AppUtils_Printf("---------------------------------------------------------------------------------------\n\n\r");
        AppUtils_Printf("\nMixed modes and Simultaneous Timers Test1"
                    "for 1s timeout - Passed !!!\r\n");
        AppUtils_Printf("---------------------------------------------------------------------------------------\n\n\r");
    }
    else
    {
        AppUtils_Printf("---------------------------------------------------------------------------------------\n\n\r");
        AppUtils_Printf("\nMixed modes and Simultaneous Timers Test1"
                    "for 1s timeout - Failed !!!\r\n");
        AppUtils_Printf("---------------------------------------------------------------------------------------\n\n\r");

    }
    while(TRUE)
    {
        /* Wait here */
    }

    return return_value;
}

/* Time delay*/
int Time_Delay(float64 seconds){
     McalLib_Delay(GPT_TIME_DELAY_PER_SECOND*seconds);
     return 0;
}

/* GPT timer channel 1 notification function */
void Gpt_Notify_Func_1(void)
{
    Gpt_ValueType time_elapsed = 0;
    Gpt_ValueType time_remaining = 0;

    /* Increment the counter */
    Gpt_InterruptCnt[GPT_CHANNEL_1]++;


    /* Timer 1 is configured as continuous mode, so restart is not required */

    /* Time Elapsed */
    time_elapsed = Gpt_GetTimeElapsed(GPT_CHANNEL_1);

    /* Time Remaining */
    time_remaining = Gpt_GetTimeRemaining(GPT_CHANNEL_1);

    AppUtils_Printf("CHANNEL-1:Time_elapsed and Time_remaining values in continuous mode"
                    "When the timer is in Running state are"
                    "(Time_elapsed = %d Time_remaining = %d)\r\n",
                    time_elapsed, time_remaining);
}

/* GPT timer channel 2 notification function */
void Gpt_Notify_Func_2(void)
{
    Gpt_ValueType time_elapsed = 0;
    Gpt_ValueType time_remaining = 0;

    /* Increment the counter */
    Gpt_InterruptCnt[GPT_CHANNEL_2]++;


    /* Timer 2 is configured as ONE_SHOT, so restarted */
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_1S);

    /* Time Elapsed */
    time_elapsed = Gpt_GetTimeElapsed(GPT_CHANNEL_2);

    /* Time Remaining */
    time_remaining = Gpt_GetTimeRemaining(GPT_CHANNEL_2);

    AppUtils_Printf("CHANNEL-2:Time_elapsed and Time_remaining values in continuous mode"
                    "When the timer is in Running state are"
                    "(Time_elapsed = %d Time_remaining = %d)\r\n",
                    time_elapsed, time_remaining);
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Gpt_Example_MixedMode.c
 *********************************************************************************************************************/