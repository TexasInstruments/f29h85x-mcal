/*********************************************************************************************************************
 *  COPYRIGHT
 *
 ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
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
 *
 ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *
 ------------------------------------------------------------------------------------------------------------------
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
    uint16         Wdg_Timeout  = 0U;
    DeviceSupport_Init();

    EcuM_Init(); /* PORT & MCU Initialization to get configuration settings */

    AppUtils_Init(200000000U); /* 200 MHZ system clock*/
    AppUtils_Printf("App_Utils Initialization is completed !!!\n");

    AppUtils_Printf("Sample Application to test Wdg Interrupt & Servicing - STARTS !!!\n");

    /* Clear the counters */
    Wdg_IsrCount = 0;

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

    /* Test Wdg Interrupt functionality*/
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

    AppUtils_Printf("Wdg Max timeout duration in milliseconds is : %d !!!\n", Wdg_Timeout);

    for (;;)
    {
        /* As servicing watchdog is not being called,  watchdog timeout is happened and triggered
           an interrupt signal to execute the wakeupISR */
        if (Wdg_IsrCount >= 1)
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
