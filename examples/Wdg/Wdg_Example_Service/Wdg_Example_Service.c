/*********************************************************************************************************************
 *  COPYRIGHT
 *
 ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited.  This product  is  protected  under  copyright  law
 *                 and  trade  secret law as an  unpublished work.
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *
 ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *
 ------------------------------------------------------------------------------------------------------------------
 *  File:       Wdg_Example_Service.c
 *  Generator:  None
 *
 *  Description:  This file contains application for Servicing Watchdog Example
 *
 * This example shows how to service the watchdog.
 * If the function Wdg_SetTriggerCondition is called, wdg servicing happens in loop and never expires
 *
 * Wdg_IsrCount  - The number of times entered into the watchdog ISR
 *

 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Wdg.h"
#include "EcuM.h"
#include "Platform_Types.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Mcal_Lib.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* Mcal Lib delay value of 1 second */
#define WDG_1S_DELAY (50000000)

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
/* Globals */
volatile uint32 Wdg_IsrCount;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/* watchdogISR ISR - The interrupt service routine called when the watchdog triggers the wake interrupt signal */
MCAL_LIB_RTINT_ISR(Wdg_ApplWdgIsr)
{
    Wdg_IsrCount++;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

int main(void)
{
    Std_ReturnType return_value = E_NOT_OK;
    uint16         Wdg_Timeout  = 0U;
    DeviceSupport_Init();

    EcuM_Init(); /* PORT & MCU Initialization to get configuration settings */

    AppUtils_Init(200000000U); /* 200 MHZ system clock*/
    AppUtils_Printf("App_Utils Initialization is completed !!!\n");

    AppUtils_Printf("Sample Application to test Wdg Interrupt & Servicing - STARTS !!!\n");

    /* Clear the counters */
    Wdg_IsrCount = 0U;

    /*  get version Info */
#if (STD_ON == WDG_GET_VERSION_INFO_API)
    Std_VersionInfoType Wdg_VersionInfo;

    AppUtils_Printf("Wdg GetVersionInfo API - STARTS !!!\n");
    Wdg_GetVersionInfo(&Wdg_VersionInfo);
    AppUtils_Printf("WDG MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Wdg_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Wdg_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Wdg_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Wdg_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Wdg_VersionInfo.sw_patch_version);
    AppUtils_Printf("Wdg GetVersionInfo API - ENDS !!!\n");
#endif

    /* Test Wdg Servicing functionality*/
    /*  Default Mode: Slow mode configuration - Timeout : 3342 milli-seconds */

    AppUtils_Printf("Wdg Initialization - STARTS !!!\n");
    Wdg_Init(&Wdg_Config);
    AppUtils_Printf("Wdg Initialization - ENDS !!!\n");

    if (Wdg_Config.Wdg_DefaultMode == WDGIF_SLOW_MODE)
    {
        Wdg_Timeout = Wdg_Config.Wdg_SlowModeCfg.Timeout;
    }
    else if (Wdg_Config.Wdg_DefaultMode == WDGIF_FAST_MODE)
    {
        Wdg_Timeout = Wdg_Config.Wdg_FastModeCfg.Timeout;
    }

    /* print timeout duration */
    AppUtils_Printf("Wdg Max timeout duration in milliseconds is : %d !!!\n", Wdg_Timeout);

    AppUtils_Printf("Wdg servicing is called in loop, So interrupts will not be generated !!!\n");

    /* Service the watchdog for 10 seconds */
    for (uint8 count = 0U; count < 5U; count++)
    {
        /* call Wdg_SetTriggerCondition (servicing watchdog) to just loop here */
        Wdg_SetTriggerCondition(1U);

        /* Wait for 2000 milliseconds - to service the watchdog before timeout */
        McalLib_Delay(2U * WDG_1S_DELAY);
    }

    /* Check if the interrupt count is zero,it means that the watch dog is serviced */
    if (Wdg_IsrCount == 0U)
    {
        return_value = E_OK;
        AppUtils_Printf("Wdg Example Service: Sample Application - Completes successfully !!!\n");
    }
    else
    {
        /* Print fail statement incase an interrupt is generated */
        AppUtils_Printf("Wdg Interrupt is generated after timeout!!!\n");
        AppUtils_Printf("Wdg Example Service: Sample Application - Failed !!!\n");
    }

    return return_value;
}

/*********************************************************************************************************************
 *  End of File: Wdg_Example_Service.c
 *********************************************************************************************************************/
