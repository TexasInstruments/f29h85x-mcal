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
 *  File:       Cdd_Ipc_Example_Interrupt_C29x1.c
 *  Generator:  None
 *
 *  Description:  Cdd_Ipc example source file. This example demonstrates how to configure IPC and pass information between
 *  C29x1 running MCAL to C29x3 running SDK core using interrupts. C29x1 running MCAL transmits a message "hello" and 
 *  C29x3 running SDK receives the message, appends the string " CPU1" to it, and send it back the C29x1.
 *  This example should be ran on C29x1 with SDK example: Ipc_Hal_Example_Interrupt_C29x3 running on C29x3.
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
Std_VersionInfoType       Cdd_Ipc_VersionInfo;
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
    PduInfoType PduInfo;
    uint8 hello[] = "hello";
    PduInfo.SduDataPtr = hello;
    PduInfo.SduLength = strlen((char*)hello);

    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(200000000U); // Init App utils to enable prints

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
    if(E_OK == Cdd_Ipc_Sync(CddIpcConf_CddIpcRemoteCoreConfig_CddIpcRemoteCoreConfig_0))
    {
        AppUtils_Printf("Synchronized with remote core CPU3\n");
        AppUtils_Printf("Transmitting message to remote core CPU3\n");
        if(E_OK == Cdd_Ipc_Transmit(Cdd_IpcConf_CddIpcTxChannelConfig_CddIpcTxChannelConfig_0, &PduInfo))
        {
            MCAL_LIB_DINT;
            AppUtils_Printf("Data transmitted to remote core CPU3:\n");
            AppUtils_Printf("%s\n", (char *)PduInfo.SduDataPtr);
            MCAL_LIB_EINT;
        }
    }
    else
    {
        AppUtils_Printf("Synchronization with remote core CPU3 failed\n");
        AppUtils_Printf("=================================================================================\n");
        AppUtils_Printf("FAIL: IPC example execution between CPU1 and CPU3 failed \n");
    }

  while(TRUE)
  {
      /* Wait here */
  }

  return 0;

}

void CddIpcRxChannelConfig_2_Rxindication(const PduInfoType *PduInfoPtr)
{
    VAR(uint8, AUTOMATIC) expected_data[] = "hello CPU1";

    AppUtils_Printf("Data received from remote core CPU3:\n");
    AppUtils_Printf("%s\n", (char *)PduInfoPtr->SduDataPtr);

    if (memcmp(PduInfoPtr->SduDataPtr, expected_data, sizeof(expected_data)) == 0)
    {
        AppUtils_Printf("=================================================================================\n");
        AppUtils_Printf("PASS: IPC example between CPU1 and CPU3 executed successfully\n");
    } 
    else
    {
        AppUtils_Printf("=================================================================================\n");
        AppUtils_Printf("FAIL: IPC example execution between CPU1 and CPU3 failed \n");
    }
  

}


/*********************************************************************************************************************
 *  End of File: Cdd_Ipc_Example_Interrupt_C29x1.c
 *********************************************************************************************************************/
