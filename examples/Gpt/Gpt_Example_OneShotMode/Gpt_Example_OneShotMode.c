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
 *  File:         Gpt_Example_OneShotMode.c
 *  Generator:    None
 *
 *  Description:  This file contains Gpt examples with Init & DeInit sequence, timers in one shot,
 *                start & stop timers, enable & disable interrupt features.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Gpt_Example_OneShotMode.h"
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
uint32 GPT_COUNT_VALUE_TIMEOUT                = {0U};

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

    /* Reset Counters */
    Gpt_InterruptCnt[GPT_CHANNEL_0] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_1] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_2] = 0;
    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(20000000U);

    /* GPT driver Init, Deinit and Init sequence */
    Gpt_DeInit();
    AppUtils_Printf("Initialize Gpt Driver\n\r");
    AppUtils_Printf("Initializing Gpt Driver...\n\r");
    Gpt_Init(&Gpt_Config);
    AppUtils_Printf("API Gpt_Init executed successfully\n\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");

    AppUtils_Printf("Enable notifications for all Channels\n\r");
    /* Enable notifications for GPT channel 0. */
    Gpt_EnableNotification(GPT_CHANNEL_0);
    /* Enable notifications for GPT channel 1. */
    Gpt_EnableNotification(GPT_CHANNEL_1);
    /* Enable notifications for GPT channel 2. */
    Gpt_EnableNotification(GPT_CHANNEL_2);
    AppUtils_Printf("Notifications enabled for all channels\n\r");
    AppUtils_Printf("API Gpt_EnableNotification executed successfully for all channels\n\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");

    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\r");
    AppUtils_Printf(
        "\nSimultaneous Timers Test In one shot mode"
        "for 10ms Timeout - Started !!!\r\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\n\n\r");
    GPT_COUNT_VALUE_TIMEOUT = (DEV_TIMER_CLK_FREQ_HZ / 1000000U) * GPT_TIME_US_1; /* 10 ms */
    AppUtils_Printf("Start timer for all Channels with 10ms Timeout\n\r");
    /* Start GPT channel 0 in one shot mode */
    Gpt_StartTimer(GPT_CHANNEL_0, GPT_COUNT_VALUE_TIMEOUT);
    /* Start GPT channel 1 in one shot mode */
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_TIMEOUT);
    /* Start GPT channel 1 in one shot mode */
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_TIMEOUT);
    AppUtils_Printf("Timer started for all channels with 10ms Timeout\n\r");
    AppUtils_Printf("API Gpt_StartTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("Wait until all the timers get notified atleast 1 time.\r\n\n");

    /* Wait for 11 milliseconds to complete one iteration*/
    Time_Delay(0.011);

    if ((Gpt_InterruptCnt[GPT_CHANNEL_0] >= 1) && (Gpt_InterruptCnt[GPT_CHANNEL_1] >= 1) &&
        (Gpt_InterruptCnt[GPT_CHANNEL_2] >= 1))
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\nSimultaneous Timers Test In one shot mode"
            "for 10ms Timeout - Passed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }
    else
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\nSimultaneous Timers Test In one shot mode"
            "for 10ms Timeout - Failed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }
    AppUtils_Printf("Reset all counters.\r\n");

    /* Reset Counters */
    Gpt_InterruptCnt[GPT_CHANNEL_0] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_1] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_2] = 0;

    AppUtils_Printf("Stop timer for all Channels\r\n");
    /* Stop the timers */
    Gpt_StopTimer(GPT_CHANNEL_0);
    Gpt_StopTimer(GPT_CHANNEL_1);
    Gpt_StopTimer(GPT_CHANNEL_2);
    AppUtils_Printf("Timer stopped for all channels\n\r");
    AppUtils_Printf("API Gpt_StopTimer executed successfully for all channels\n\n\r");

    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\r");
    AppUtils_Printf(
        "\nSimultaneous Timers Test In one shot mode for 100ms"
        "Timeout - Started !!!\r\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\n\n\r");

    GPT_COUNT_VALUE_TIMEOUT = (DEV_TIMER_CLK_FREQ_HZ / 1000000U) * GPT_TIME_US_2; /* 100 ms */
    AppUtils_Printf("Start timer for all Channels with 100ms Timeout\n\r");
    /* Start all GPT channels in continuos mode with 100 ms timeout*/
    Gpt_StartTimer(GPT_CHANNEL_0, GPT_COUNT_VALUE_TIMEOUT);
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_TIMEOUT);
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_TIMEOUT);
    AppUtils_Printf("Timer started for all channels with 100ms Timeout\n\r");
    AppUtils_Printf("API Gpt_StartTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("Wait until all the timers get notified atleast 1 time.\r\n\n");

    /* Wait for 101 milliseconds to complete one iteration*/
    Time_Delay(0.101);

    if ((Gpt_InterruptCnt[GPT_CHANNEL_0] == 1) && (Gpt_InterruptCnt[GPT_CHANNEL_1] == 1) &&
        (Gpt_InterruptCnt[GPT_CHANNEL_2] == 1))
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\n Simultaneous Timers Test In one shot mode"
            "for 100ms Timeout - Passed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }
    else
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\nSimultaneous Timers Test In one shot mode"
            "for 100ms Timeout - Failed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }

    AppUtils_Printf("Reset all counters.\r\n");

    /* Reset Counters */
    Gpt_InterruptCnt[GPT_CHANNEL_0] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_1] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_2] = 0;
    AppUtils_Printf("Stop timer for all Channels\r\n");
    /* Stop all timers */
    Gpt_StopTimer(GPT_CHANNEL_0);
    Gpt_StopTimer(GPT_CHANNEL_1);
    Gpt_StopTimer(GPT_CHANNEL_2);
    AppUtils_Printf("Timer stopped for all channels\n\r");
    AppUtils_Printf("API Gpt_StopTimer executed successfully for all channels\n\n\r");

    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\r");
    AppUtils_Printf("\nSimultaneous Timers Test In one shot mode for 1s Timeout - Started !!!\r\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\n\n\r");
    GPT_COUNT_VALUE_TIMEOUT = (DEV_TIMER_CLK_FREQ_HZ / 1000000U) * GPT_TIME_US_3; /* 1 sec */
    AppUtils_Printf("Start timer for all Channels with 1ms Timeout\n\r");
    /* Start all GPT channels in continuos mode with 1 s timeout*/
    Gpt_StartTimer(GPT_CHANNEL_0, GPT_COUNT_VALUE_TIMEOUT);
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_TIMEOUT);
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_TIMEOUT);
    AppUtils_Printf("Timer started for all channels with 1s Timeout\n\r");
    AppUtils_Printf("API Gpt_StartTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("Wait until all the timers get notified atleast 1 time.\r\n\n");

    /* Wait for 1.1 seconds to complete one iteration*/
    Time_Delay(1.10);

    if ((Gpt_InterruptCnt[GPT_CHANNEL_0] == 1) && (Gpt_InterruptCnt[GPT_CHANNEL_1] == 1) &&
        (Gpt_InterruptCnt[GPT_CHANNEL_2] == 1))
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\n Simultaneous Timers Test In one shot mode"
            "for 1s Timeout - Passed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }
    else
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\n Simultaneous Timers Test In one shot mode"
            "for 1s Timeout - Failed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }
    AppUtils_Printf("Reset all counters.\r\n");

    /* Reset Counters */
    Gpt_InterruptCnt[GPT_CHANNEL_0] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_1] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_2] = 0;
    AppUtils_Printf("Stop timer for all Channels\r\n");
    /* Stop all timers */
    Gpt_StopTimer(GPT_CHANNEL_0);
    Gpt_StopTimer(GPT_CHANNEL_1);
    Gpt_StopTimer(GPT_CHANNEL_2);
    AppUtils_Printf("Timer stopped for all channels\n\r");
    AppUtils_Printf("API Gpt_StopTimer executed successfully for all channels\n\n\r");

    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\r");
    AppUtils_Printf(
        "\nSimultaneous Timers Test In one shot mode"
        "for Max Tick Timeout - Started !!!\r\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\n\n\r");

    GPT_COUNT_VALUE_TIMEOUT = (DEV_TIMER_CLK_FREQ_HZ / 1000000U) * GPT_TIME_US_MAX_TICK_COUNT; /* Max tick count */
    AppUtils_Printf("Start timer for all Channels with Max Tick Timeout\n\r");
    /* Start all GPT channels in continuos mode with max tick count timeout*/
    Gpt_StartTimer(GPT_CHANNEL_0, GPT_COUNT_VALUE_TIMEOUT);
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_TIMEOUT);
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_TIMEOUT);
    AppUtils_Printf("Timer started for all channels with Max Tick Timeout\n\r");
    AppUtils_Printf("API Gpt_StartTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("Wait until all the timers get notified atleast 1 time.\r\n\n");
    /* Wait for max tick timeout to complete one iteration*/
    Time_Delay(220.0);

    if ((Gpt_InterruptCnt[GPT_CHANNEL_0] == 1) && (Gpt_InterruptCnt[GPT_CHANNEL_1] == 1) &&
        (Gpt_InterruptCnt[GPT_CHANNEL_2] == 1))
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\nSimultaneous Timers Test In one shot mode"
            "for Max tick Timeout - Passed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }
    else
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\nSimultaneous Timers Test In one shot mode"
            "for Max tick Timeout - Failed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }
    AppUtils_Printf("Stop timer for all Channels\r\n");
    /* Stop all timers */
    Gpt_StopTimer(GPT_CHANNEL_0);
    Gpt_StopTimer(GPT_CHANNEL_1);
    Gpt_StopTimer(GPT_CHANNEL_2);
    AppUtils_Printf("Timer stopped for all channels\n\r");
    AppUtils_Printf("API Gpt_StopTimer executed successfully for all channels\n\n\r");

    AppUtils_Printf("Deinitialize Gpt Driver\n\r");
    AppUtils_Printf("DeInitializing Gpt Driver...\n\r");
    /* DeInit the driver */
    Gpt_DeInit();
    AppUtils_Printf("API Gpt_DeInit executed successfully\n\n\r");
    AppUtils_Printf("------------------------------------------\r\n");

    return return_value;
}

/* Time delay*/
int Time_Delay(float64 seconds)
{
    McalLib_Delay(GPT_TIME_DELAY_PER_SECOND * seconds);
    return 0;
}

/* GPT timer channel 0 notification function */
void Gpt_Notify_Func_0(void)
{
    /* Increment the counter */
    Gpt_InterruptCnt[GPT_CHANNEL_0]++;
}

/* GPT timer channel 1 notification function */
void Gpt_Notify_Func_1(void)
{
    /* Increment the counter */
    Gpt_InterruptCnt[GPT_CHANNEL_1]++;
}

/* GPT timer channel 2 notification function */
void Gpt_Notify_Func_2(void)
{
    /* Increment the counter */
    Gpt_InterruptCnt[GPT_CHANNEL_2]++;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Gpt_Example_OneShotMode.c
 *********************************************************************************************************************/
