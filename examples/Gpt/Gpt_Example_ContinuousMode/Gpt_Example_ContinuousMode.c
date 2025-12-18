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
 *  File:         Gpt_Example_ContinuousMode.c
 *  Generator:    None
 *
 *  Description:  This file contains the configuration and usage of Gpt module operating in continuous mode.
 *  This example demonstrates:
 *  - Gpt initialization and de-initialization
 *  - Starting and stopping of timer channels 0, 1 and 2 for 10ms, 100ms and 1s
 *  - Reading time elapsed and time remaining values for running timer
 *  - Enabling interrupt for Notification function and verifying if interrupt occurred in the expected time.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Gpt_Example_ContinuousMode.h"
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
        "\nSimultaneous Timers Test In Continuous mode"
        "for 10ms Timeout - Started !!!\r\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\n\n\r");
    AppUtils_Printf("Start timer for all Channels with 10ms Timeout\n\r");
    /* Start GPT channel 0 in one shot mode */
    Gpt_StartTimer(GPT_CHANNEL_0, GPT_COUNT_VALUE_10MS);
    /* Start GPT channel 1 in continuous mode */
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_10MS);
    /* Start GPT channel 1 in continuous mode */
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_10MS);
    AppUtils_Printf("Timer started for all channels with 10ms Timeout\n\r");
    AppUtils_Printf("API Gpt_StartTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("Wait until all the timers get notified atleast 3 times.\r\n\n");

    /* Wait for 33 milliseconds to complete three iterations*/
    Time_Delay(0.033);

    if ((Gpt_InterruptCnt[GPT_CHANNEL_0] = 3) && (Gpt_InterruptCnt[GPT_CHANNEL_1] = 3) &&
        (Gpt_InterruptCnt[GPT_CHANNEL_2] = 3))
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\nSimultaneous Timers Test In Continuous mode"
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
            "\nSimultaneous Timers Test In Continuous mode"
            "for 10ms Timeout - Failed !!!\r\n");
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\n\n\r");
    }

    AppUtils_Printf("Reset all counters.\r\n");

    AppUtils_Printf("Stop timer for all Channels\r\n");
    /* Stop the timers */
    Gpt_StopTimer(GPT_CHANNEL_0);
    Gpt_StopTimer(GPT_CHANNEL_1);
    Gpt_StopTimer(GPT_CHANNEL_2);

    /* Reset Counters */
    Gpt_InterruptCnt[GPT_CHANNEL_0] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_1] = 0;
    Gpt_InterruptCnt[GPT_CHANNEL_2] = 0;

    AppUtils_Printf("Timer stopped for all channels\n\r");
    AppUtils_Printf("API Gpt_StopTimer executed successfully for all channels\n\n\r");

    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\r");
    AppUtils_Printf(
        "\nSimultaneous Timers Test In Continuous mode"
        "for 100ms Timeout - Started !!!\r\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\n\n\r");

    AppUtils_Printf("Start timer for all Channels with 100ms Timeout\n\r");

    /* Start all GPT channels in continuos mode with 100 ms timeout*/
    Gpt_StartTimer(GPT_CHANNEL_0, GPT_COUNT_VALUE_100MS);
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_100MS);
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_100MS);
    AppUtils_Printf("Timer started for all channels with 100ms Timeout\n\r");
    AppUtils_Printf("API Gpt_StartTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("Wait until all the timers get notified atleast 3 times.\r\n\n");
    /* Wait for 303 milliseconds to complete three iterations*/
    Time_Delay(0.303);

    if ((Gpt_InterruptCnt[GPT_CHANNEL_0] == 3) && (Gpt_InterruptCnt[GPT_CHANNEL_1] == 3) &&
        (Gpt_InterruptCnt[GPT_CHANNEL_2] == 3))
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\nSimultaneous Timers Test In Continuous mode"
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
            "\nSimultaneous Timers Test In Continuous mode"
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
    AppUtils_Printf(
        "\nSimultaneous Timers Test In Continuous mode"
        "for 1s Timeout - Started !!!\r\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\n\n\r");
    AppUtils_Printf("Start timer for all Channels with 1s Timeout\n\r");
    /* Start all GPT channels in continuos mode with 1 s timeout*/
    Gpt_StartTimer(GPT_CHANNEL_0, GPT_COUNT_VALUE_1S);
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_1S);
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_1S);
    AppUtils_Printf("Timer started for all channels with 1s Timeout\n\r");
    AppUtils_Printf("API Gpt_StartTimer executed successfully for all channels\n\n\r");
    AppUtils_Printf("Wait until all the timers get notified atleast 3 times.\r\n\n");

    /* Wait for 3.3 seconds to complete three iterations*/
    Time_Delay(3.30);

    if ((Gpt_InterruptCnt[GPT_CHANNEL_0] == 3) && (Gpt_InterruptCnt[GPT_CHANNEL_1] == 3) &&
        (Gpt_InterruptCnt[GPT_CHANNEL_2] == 3))
    {
        AppUtils_Printf(
            "--------------------------------------------------------------------------------------"
            "-\r");
        AppUtils_Printf(
            "\nSimultaneous Timers Test In Continuous mode"
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
            "\nSimultaneous Timers Test In Continuous mode"
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
        "\nSimultaneous Timers Test In Continuous mode"
        "for Max Tick Timeout - Started !!!\r\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------------"
        "\n\n\r");

    AppUtils_Printf("Start timer for all Channels with Max Tick Timeout\n\r");
    /* Start all GPT channels in continuos mode with max tick count timeout*/
    Gpt_StartTimer(GPT_CHANNEL_0, GPT_COUNT_VALUE_MAX_TICK);
    Gpt_StartTimer(GPT_CHANNEL_1, GPT_COUNT_VALUE_MAX_TICK);
    Gpt_StartTimer(GPT_CHANNEL_2, GPT_COUNT_VALUE_MAX_TICK);
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
            "\nSimultaneous Timers Test In Continuous mode"
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
            "\nSimultaneous Timers Test In Continuous mode"
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
    Gpt_InterruptCnt[GPT_CHANNEL_0]++;
}

/* GPT timer channel 1 notification function */
void Gpt_Notify_Func_1(void)
{
    Gpt_InterruptCnt[GPT_CHANNEL_1]++;
}

/* GPT timer channel 2 notification function */
void Gpt_Notify_Func_2(void)
{
    Gpt_InterruptCnt[GPT_CHANNEL_2]++;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Gpt_Example_ContinuousMode.c
 *********************************************************************************************************************/
