/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
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
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Ipc_Example_Polling_C29x1.c
 *  Generator:  None
 *
 *  Description:  Cdd_Ipc example source file. This example demonstrates how to configure IPC and
 *  pass information between C29x1 running MCAL to C29x3 running SDK core using polling. C29x1
 *  running MCAL transmits a message "hello" and C29x3 running SDK receives the message, appends
 *  the string "CPU1" to it, and send it back the C29x1. This example will be ran on C29x1 with
 *  SDK example: Ipc_Hal_Example_Polling_C29x3 running on C29x3.
 *
 *  When using CCS for debugging this Multi-core example, after launching the
 *  debug session,
 *      - Connect to CPU1 and load only the C29x1_merged.out.
 *      - After the program is loaded, run CPU1.
 *      - C29x1 configures and releases CPU3 out of reset
 *      - Connect to CPU3 target now. C29x3.out would have started execution
 *        as soon as it is released from reset.
 *
 *   For FLASH configuration, this example is run in FLASH BANKMODE2,
 *   where CPU3 has access to FLASH (FRI-2). Refer to the Flash Plugin
 *   documentation to know about changing FLASH BANKMODEs and more.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ipc.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include <string.h>

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
#if (STD_ON == CDD_IPC_GET_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Ipc_VersionInfo;
#endif
PduInfoType PduInfo;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
/* Example Application */
int main(void)
{
    VAR(PduInfoType, AUTOMATIC) PduInfo;
    VAR(uint8, AUTOMATIC) hello[] = "hello";
    PduInfo.SduDataPtr            = hello;
    PduInfo.SduLength             = strlen((char *)hello);

    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(200000000U);  // Init App utils to enable prints

    AppUtils_Printf("Sample Application - STARTS !!!\n");

/*  Get version Info */
#if (STD_ON == CDD_IPC_GET_VERSION_INFO_API)
    Cdd_Ipc_GetVersionInfo(&Cdd_Ipc_VersionInfo);
    AppUtils_Printf("CDD IPC MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Ipc_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Ipc_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Ipc_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Ipc_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Ipc_VersionInfo.sw_patch_version);
#endif

    AppUtils_Printf("Synchronizing with remote core CPU3\n");
    if (E_OK == Cdd_Ipc_Sync(CddIpcConf_CddIpcRemoteCoreConfig_CddIpcRemoteCoreConfig_0))
    {
        AppUtils_Printf("Synchronized with remote core CPU3\n");
        AppUtils_Printf("Transmitting message to remote core CPU3\n");
        if (E_OK == Cdd_Ipc_Transmit(Cdd_IpcConf_CddIpcTxChannelConfig_CddIpcTxChannelConfig_0, &PduInfo))
        {
            AppUtils_Printf("Data transmitted to remote core CPU3:\n");
            AppUtils_Printf("%s\n", (char *)PduInfo.SduDataPtr);
        }
    }
    else
    {
        AppUtils_Printf("Synchronization with remote core CPU3 failed\n");
        AppUtils_Printf("=================================================================================\n");
        AppUtils_Printf("FAIL: IPC example execution between CPU1 and CPU3 failed \n");
    }

    while (TRUE)
    {
        Cdd_Ipc_MainFunction_Read();
        /* Wait here */
    }

    return 0;
}

void CddIpcRxChannelConfig_1_Rxindication(const PduInfoType *PduInfoPtr)
{
    VAR(uint8, AUTOMATIC) expected_data[] = "hello CPU1";

    AppUtils_Printf("Data received from remote core CPU3:\n");
    AppUtils_Printf("%s\n", (char *)PduInfoPtr->SduDataPtr);

    if (memcmp(PduInfoPtr->SduDataPtr, expected_data, sizeof(expected_data)) == 0)
    {
        AppUtils_Printf("=================================================================================\n");
        AppUtils_Printf("PASS: IPC example between CPU1 and CPU3 executed successfully \n");
    }
    else
    {
        AppUtils_Printf("=================================================================================\n");
        AppUtils_Printf("FAIL: IPC example execution between CPU1 and CPU3 failed \n");
    }
}

/*********************************************************************************************************************
 *  End of File: Cdd_Ipc_Example_Polling_C29x1.c
 *********************************************************************************************************************/
