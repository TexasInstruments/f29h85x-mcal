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
 *  File:       Mcu_Example_PowerMode.c
 *  Generator:  None
 *
 *  Description:  This file contains example application for Mcu Driver module
 *
 *  This example demonstrates Standby entry and Exit example.
 *
 *
 *  Low Power Modes: Device Standby Mode and Wakeup using GPIO</h1>
 *
 *  This example puts the device into STANDBY mode. If the lowest possible
 *  current consumption in STANDBY mode is desired, the JTAG connector must
 *  be removed from the device board while the device is in STANDBY mode.
 *
 *  This example puts the device into STANDBY mode and then wakes up the device
 *  from STANDBY using an LPM wakeup pin.
 *
 *  The pin GPIO0 is configured as the LPM wakeup pin to trigger a WAKEINT
 *  interrupt upon detection of a low pulse. Initially, pull GPIO0 high
 *  externally. To wake device from STANDBY mode, pull GPIO0 low for at least
 *  (2+QUALSTDBY), OSCLKS
 *
 *  The example then wakes up the device from STANDBY using GPIO0.
 *  GPIO0 wakes the device from STANDBY mode when a low pulse
 *  (signal goes high->low)is detected on the pin.
 *  This pin must be pulsed by an external agent for wakeup.
 *
 * GPIO1 is pulled high before entering the STANDBY mode from tresos
 *
 * External Connections:
 * Short the GPIO1-GPIO0 to make GPIO0 High before standby
 * Make GPIO0 low to wakeup from standby
 *
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcu.h"
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

volatile boolean Mcu_ActivatePowerMode = TRUE;

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
    Std_ReturnType return_value = E_OK;

    DeviceSupport_Init();
    EcuM_Init(); /* PORT & MCU Initilization to get configuration settings */
    AppUtils_Init(200000000U);
    AppUtils_Printf("Sample Application - STARTS !!!\r\n");

    /*  get version Info */
#if (STD_ON == MCU_CFG_GET_VERSION_INFO_API)
    Std_VersionInfoType Mcu_VersionInfo;

    Mcu_GetVersionInfo(&Mcu_VersionInfo);
    AppUtils_Printf("MCU MCAL Version Info\r\n");
    AppUtils_Printf("---------------------\r\n");
    AppUtils_Printf("Vendor ID           : %d\r\n", Mcu_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\r\n", Mcu_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\r\n", Mcu_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\r\n", Mcu_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\r\n", Mcu_VersionInfo.sw_patch_version);
#endif

    /* It Sets the STANBY mode from mode configuration structure*/
    if (TRUE == Mcu_ActivatePowerMode)
    {
        Mcu_SetMode(McuConf_McuModeSettingConf_McuModeSettingConf_1); /* Activate low power modes */
    }

    AppUtils_Printf("Woken up from stand by mode usign GPIO wakeup pins  \r\n");
    AppUtils_Printf("Mcu_Example_PowerMode: Sample Application - Completes successfully !!!\r\n");

    return return_value;
}

void Mcu_ApplWakeupIsr(void)
{
    /* Wakeup ISR function*/
    AppUtils_Printf("Wakeup ISR function is triggered  \r\n");
}
/*********************************************************************************************************************
 *  End of File: Mcu_Example_PowerMode.c
 *********************************************************************************************************************/
