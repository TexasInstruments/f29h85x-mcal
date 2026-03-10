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
    Port_Init(&Port_Config) and will Initialize the Port and Mcu Driver */
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
