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
