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
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Wdg_Example_Interrupt.c
 *  Generator:  None
 *
 *  Description:  This file contains application for Generate Wdg interrupts
 *
 * This example shows how to generate a watchdog interrupt. 
 * By default the example will generate a watchdog interrupt after timeout. 
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

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

int main(void)
{ 
    Std_ReturnType return_value = E_NOT_OK;
    uint16 Wdg_Timeout = 0U;
    DeviceSupport_Init();

    EcuM_Init(); /* PORT & MCU Initialization to get configuration settings */

    AppUtils_Init(200000000U); /* 200 MHZ system clock*/
    AppUtils_Printf("App_Utils Initialization is completed !!!\n");

    AppUtils_Printf("Sample Application to test Wdg Interrupt & Servicing - STARTS !!!\n");

    /* Clear the counters */ 
    Wdg_IsrCount = 0;

    /*  get version Info */
#if (STD_ON == WDG_GET_VERSION_INFO_API)
    Std_VersionInfoType       Wdg_VersionInfo;

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


    /* Test Wdg Interrupt functionality*/
    /*  Default Mode: Slow mode configuration - Timeout : 3342 milli-seconds */

    AppUtils_Printf("Wdg Initialization - STARTS !!!\n");
    Wdg_Init(&Wdg_ConfigSetptr);
    AppUtils_Printf("Wdg Initialization - ENDS !!!\n");

    if(Wdg_ConfigSetptr.Wdg_DefaultMode == WDGIF_SLOW_MODE)
    {
        Wdg_Timeout = Wdg_ConfigSetptr.Wdg_SlowModeCfg.Timeout;
    }
    else if(Wdg_ConfigSetptr.Wdg_DefaultMode == WDGIF_FAST_MODE)
    {
        Wdg_Timeout = Wdg_ConfigSetptr.Wdg_FastModeCfg.Timeout;
    }

    AppUtils_Printf("Wdg Max timeout duration in milliseconds is : %d !!!\n", Wdg_Timeout);

    for(;;)
    {
        /* As servicing watchdog is not being called,  watchdog timeout is happened and triggered
           an interrupt signal to execute the wakeupISR */
        if(Wdg_IsrCount >= 1) 
        {
            return_value = E_OK;
            AppUtils_Printf("Wdg Interrupt is generated after timeout!!!\n");
            AppUtils_Printf("Wdg Example Interrupt: Sample Application - Completes successfully !!!\n");
            break;
        }

    }

    return return_value;
}


/* watchdogISR ISR - The interrupt service routine called when the watchdog
                  triggers the wake interrupt signal */
void Wdg_ApplWdgIsr(void)
{
    Wdg_IsrCount++;
}

/*********************************************************************************************************************
 *  End of File: Wdg_Example_Interrupt.c
 *********************************************************************************************************************/

