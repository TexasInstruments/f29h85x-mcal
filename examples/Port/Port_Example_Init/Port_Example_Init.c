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
 *  File:       Port_Example_Init.c
 *  Project:    C29x MCAL
 *  Module:     Port Driver
 *  Generator:  None
 *
 *  Description:  This file contains Port Driver Demo implementation which will initialize the Port
 *pins as per the provided config file. After initialization, will change the direction of one of
 *the pins from OUT to IN. Then will change the Mode of the pin from GPIO to some other available
 *MUX mode. Post mode change, will refresh the pin direction of the pins where direction changeable
 *is not allowed.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcu.h"
#include "Port.h"
#include "Platform_Types.h"
#include "Port_Pin_Map.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"

/*********************************************************************************************************************
 * Other Header Files
 *********************************************************************************************************************/

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

#if (STD_ON == PORT_CFG_GET_VERSION_INFO_API)
Std_VersionInfoType Port_VersionInfo;
#endif

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* main function */
int main(void)
{
    volatile static boolean flipDirection = TRUE;
    volatile static boolean changeMode    = TRUE;
    Std_ReturnType          returnValue   = E_OK;

    DeviceSupport_Init();
    /* EcuM_Init() will Initialize Port with the provided configuration. Below API will call
    Port_Init(&Port_PortConfigSet) and will Initialize the Port and Mcu Driver */
    EcuM_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("PORT Driver Sample Application - Starts!!!\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");
    AppUtils_Printf("Test 1: Initialize Port Driver\n\r");
    AppUtils_Printf("Initializing Port Driver...\n\r");
    AppUtils_Printf("API Port_Init executed successfully\n\n\r");

/* Change Port Pin Direction */
#if (STD_ON == PORT_CFG_SET_PIN_DIRECTION_API)
    if (TRUE == flipDirection)
    {
        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("Test 2: Change direction for PortPin_0\n\r");
        Port_SetPinDirection(PortConf_PortPin_PortPin_0, PORT_PIN_IN);
        AppUtils_Printf("Direction changed to INPUT for PortPin_0\n\r");
        AppUtils_Printf("API Port_SetPinDirection executed successfully\n\n\r");
        flipDirection = FALSE;
    }
#endif

/* Change Port Pin Mode */
#if (STD_ON == PORT_CFG_SET_PIN_MODE_API)
    if (TRUE == changeMode)
    {
        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("Test 3: Change Mode for PortPin_0\n\r");
        Port_SetPinMode(PortConf_PortPin_PortPin_0, PORT_PIN_0_MCAND_TX);
        AppUtils_Printf("Mode changed to MCAND_TX for PortPin_0\n\r");
        AppUtils_Printf("API Port_SetPinMode executed successfully\n\n\r");
        changeMode = FALSE;
    }
#endif

    /* Refresh Port Pin Direction for the Direction unchangeable pins */
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");
    AppUtils_Printf("Test 4: Refresh Pin direction for direction unchangeable pins\n\r");
    Port_RefreshPortDirection();
    AppUtils_Printf("API Port_RefreshPortDirection executed successfully\n\n\r");

#if (STD_ON == PORT_CFG_GET_VERSION_INFO_API)
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");
    AppUtils_Printf("Test 5: Get Version info for Port\n\r");
    Port_GetVersionInfo(&Port_VersionInfo);
    AppUtils_Printf(" \n\r");
    AppUtils_Printf("API Port_GetVersionInfo executed successfully\n\r");
    AppUtils_Printf(" PORT MCAL Version Info\n\r");
    AppUtils_Printf(" ---------------------\n\r");
    AppUtils_Printf(" Vendor ID           : %d\n\r", Port_VersionInfo.vendorID);
    AppUtils_Printf(" Module ID           : %d\n\r", Port_VersionInfo.moduleID);
    AppUtils_Printf(" SW Major Version    : %d\n\r", Port_VersionInfo.sw_major_version);
    AppUtils_Printf(" SW Minor Version    : %d\n\r", Port_VersionInfo.sw_minor_version);
    AppUtils_Printf(" SW Patch Version    : %d\n\r", Port_VersionInfo.sw_patch_version);
    AppUtils_Printf(" \n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");
#endif

    AppUtils_Printf("Port Example App run is Completed\n\r");
    AppUtils_Printf("Result - PASS!!");

    return returnValue;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Port_Example_Init.c
 *********************************************************************************************************************/
