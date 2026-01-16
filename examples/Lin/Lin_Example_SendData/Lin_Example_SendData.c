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
 *  File:       Lin_Example_SendData.c
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  None
 *
 *  Description:  This file contains Lin Driver Demo implementation which will Send the data on Lin
 *Bus based on three Different types of Sending data from master.
 *                   1. Master sending Message ID and data on the bus to Slave
 *                   2. Master sending Message ID and expecting response from Slave
 *                   3. Master sending Message ID for communication between two slaves
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "string.h"
#include "Det.h"
#include "Std_Types.h"
#include "Mcal_Lib_Cpu.h"
#include "Os.h"
#include "EcuM.h"
#include "Port_Cfg.h"
#include "hw_types.h"
#include "Mcu.h"
#include "EcuM_Cbk.h"
#include "Lin.h"
#include "Port.h"
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

/* Parity ID Masks for LIN */
#define LIN_ID0 (0x1U)
#define LIN_ID1 (0x2U)
#define LIN_ID2 (0x4U)
#define LIN_ID3 (0x8U)
#define LIN_ID4 (0x10U)
#define LIN_ID5 (0x20U)

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * ExLined Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
Std_ReturnType LinSendFrame_Master_Response();
Std_ReturnType LinSendFrame_Slave_Response();
Std_ReturnType LinSendFrame_Slave_To_Slave();

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
static inline Lin_FramePidType Lin_GenerateParityID(Lin_FramePidType identifier)
{
    Lin_FramePidType p0, p1, parityIdentifier;

    /* Calculate parity bits and generate updated identifier */
    p0 = ((identifier & LIN_ID0) ^ ((identifier & LIN_ID1) >> 1U) ^ ((identifier & LIN_ID2) >> 2U) ^
          ((identifier & LIN_ID4) >> 4U));
    p1 = !(((identifier & LIN_ID1) >> 1U) ^ ((identifier & LIN_ID3) >> 3U) ^ ((identifier & LIN_ID4) >> 4U) ^
           ((identifier & LIN_ID5) >> 5U));
    parityIdentifier = identifier | ((p0 << 6U) | (p1 << 7U));

    return (parityIdentifier);
}
/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

Std_ReturnType returnValue = E_OK;
uint8          txData[8]   = {0x11, 0x34, 0x56, 0x78, 0x9A, 0xAB, 0xCD, 0xEF};
uint8*         rxBuff;
uint8**        rxData = &rxBuff;
Lin_PduType    LinPduInfoPtr;
uint8          loop;

int main(void)
{
    /* INITIALIZATIONS*/
    DeviceSupport_Init();
    /* EcuM_Init() will Initialize Port with the provided configuration. Below API will call
    Port_Init(&Port_Config) and will Initialize the Port and Mcu Driver */
    EcuM_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("LIN Driver Sample Application: Lin Send Data - Starts!!!\n\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\n\r");

    /* Lin_Init */
#if (STD_ON == LIN_PRE_COMPILE_VARIANT)
    Lin_Init(NULL_PTR);
#else
    const Lin_ConfigType* pCfgPtr = &Lin_Config;
    Lin_Init(pCfgPtr);
#endif
    AppUtils_Printf("Initialization of LIN Module is Success !!!\n\r");

    /* Lin_WakeUpInternal */
    returnValue = Lin_WakeupInternal(LinConf_LinChannel_LinChannel_0);

    if (E_NOT_OK == returnValue)
    {
        AppUtils_Printf("LIN Lin_WakeupInternal Failed !!!\n\r");
    }
    else
    {
        AppUtils_Printf("LIN Module Wake Up Internal. Ready to Send data on Lin Bus !!!\n\n\r");

        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("Test 1: Lin Send data : LIN Master Response !!!\n\r");
        AppUtils_Printf("\n\r");
        returnValue |= LinSendFrame_Master_Response();

        if (returnValue == E_OK)
        {
            AppUtils_Printf("Lin Send data : LIN Master Response PASSED!!\n\r");
            AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        }
        else
        {
            AppUtils_Printf("Lin Send data : LIN Master Response FAILED!!\n\r");
            AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        }

        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("Test 2: Lin Send data : LIN Slave Response !!!\n\r");
        AppUtils_Printf("\n\r");
        returnValue |= LinSendFrame_Slave_Response();

        if (returnValue == E_OK)
        {
            AppUtils_Printf("Lin Send data : LIN Slave Response PASSED!!\n\r");
            AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        }
        else
        {
            AppUtils_Printf("Lin Send data : LIN Slave Response FAILED!!\n\r");
            AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        }

        AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        AppUtils_Printf("Test 3: Lin Send data : LIN Slave To Slave !!!\n\r");
        AppUtils_Printf("\n\r");
        returnValue |= LinSendFrame_Slave_To_Slave();

        if (returnValue == E_OK)
        {
            AppUtils_Printf("Lin Send data : LIN Slave To Slave PASSED!!\n\r");
            AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        }
        else
        {
            AppUtils_Printf("Lin Send data : LIN Slave To Slave FAILED!!\n\r");
            AppUtils_Printf("---------------------------------------------------------------\n\n\r");
        }

        if (E_NOT_OK == returnValue)
        {
            AppUtils_Printf("---------------------------------------------------------------\n\r");
            AppUtils_Printf(
                "LIN Send Data Application - Master_Response, Slave_Response, Slave_To_Slave "
                "FAILED\n");

            AppUtils_Printf("---------------------------------------------------------------\n\r");
        }
        else
        {
            AppUtils_Printf("---------------------------------------------------------------\n\r");
            AppUtils_Printf(
                "LIN Send Data Application - Master_Response, Slave_Response, Slave_To_Slave "
                "PASSED\n");
            AppUtils_Printf("---------------------------------------------------------------\n\r");
        }
    }
}

Std_ReturnType LinSendFrame_Master_Response()
{
    Std_ReturnType return_val = E_NOT_OK;

    for (loop = 0; loop < 8; loop++)
    {
        LinPduInfoPtr.Pid    = Lin_GenerateParityID(7 + loop);
        LinPduInfoPtr.Cs     = (Lin_FrameCsModelType)(loop % 2);
        LinPduInfoPtr.Drc    = LIN_MASTER_RESPONSE;
        LinPduInfoPtr.Dl     = 8;
        LinPduInfoPtr.SduPtr = txData;

        return_val = Lin_SendFrame(LinConf_LinChannel_LinChannel_0, &LinPduInfoPtr);
        AppUtils_Printf("Started Sending Data on Lin Bus For ID : 0x%x\n\r", LinPduInfoPtr.Pid);

        while (LIN_TX_OK != Lin_GetStatus(LinConf_LinChannel_LinChannel_0, rxData))
            ;
        AppUtils_Printf("Data Sent : 0x%x\n\r", txData[loop]);
    }
    AppUtils_Printf("Finished Sending Data on Lin Bus\n\r");

    return return_val;
}

Std_ReturnType LinSendFrame_Slave_Response()
{
    Std_ReturnType return_val = E_NOT_OK;

    LinPduInfoPtr.Pid    = Lin_GenerateParityID(0x20);
    LinPduInfoPtr.Cs     = LIN_ENHANCED_CS;
    LinPduInfoPtr.Drc    = LIN_SLAVE_RESPONSE;
    LinPduInfoPtr.Dl     = 8;
    LinPduInfoPtr.SduPtr = txData;

    return_val = Lin_SendFrame(LinConf_LinChannel_LinChannel_0, &LinPduInfoPtr);
    AppUtils_Printf("Started Sending Header on Lin Bus For ID : 0x%x\n\r", LinPduInfoPtr.Pid);
    AppUtils_Printf("Waiting For Slave to send the data...\n\r");

    while (LIN_RX_OK != Lin_GetStatus(LinConf_LinChannel_LinChannel_0, rxData))
        ;
    AppUtils_Printf("Started receiving Data from Slave...\n\r");
    for (loop = 0; loop < 8; loop++)
    {
        AppUtils_Printf("Data Received : 0x%x\n\r", rxBuff[loop]);
    }
    AppUtils_Printf("Finished Receiving Data\n\r");

    return_val = E_OK; /* LIN_RX_OK Status has been received */

    return return_val;
}

Std_ReturnType LinSendFrame_Slave_To_Slave()
{
    Std_ReturnType return_val = E_NOT_OK;

    LinPduInfoPtr.Pid    = Lin_GenerateParityID(0x30);
    LinPduInfoPtr.Cs     = LIN_ENHANCED_CS;
    LinPduInfoPtr.Drc    = LIN_SLAVE_TO_SLAVE;
    LinPduInfoPtr.Dl     = 4;
    LinPduInfoPtr.SduPtr = txData;

    AppUtils_Printf("Started Sending Header on Lin Bus For ID : 0x%x\n\r", LinPduInfoPtr.Pid);
    return_val = Lin_SendFrame(LinConf_LinChannel_LinChannel_0, &LinPduInfoPtr);
    AppUtils_Printf("Sent Header on Bus for Slave 1 to send data to Slave 2\n\r");

    return return_val;
}

/*********************************************************************************************************************
 *  End of File: Lin_Example_SendData.c
 *********************************************************************************************************************/
