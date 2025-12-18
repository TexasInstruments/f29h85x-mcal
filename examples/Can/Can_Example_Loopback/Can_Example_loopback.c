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
 *  File:         Can_Example_loopback.c
 *  Generator:    None
 *
 *  Description:  This file contains examples for CAN loopback, enable one controller in loopback
 *mode and validate the receive data with respect to the transmit data, below are sets on this
 *example code.
 *                1. Initialize the Can module.
 *                2. Set controller state to STARTED.
 *                3. Send the data using can_write() with pre-defined data.
 *                4. Read Tx confirmation and rx indication.
 *                5. Validate the received data with pre-defined transmit data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Can_Example_loopback.h"
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
Can_PduType Pdu;

uint8 Can_Data[64U] = {0xA1, 0x1A, 0xFF, 0xFF, 0xC1, 0x1C, 0xB1, 0x1B, 0xA2, 0x2A, 0xFF, 0xFF, 0xC2, 0x2C, 0xB2, 0x2B,
                       0xA3, 0x3A, 0xFF, 0xFF, 0xC3, 0x3C, 0xB3, 0x3B, 0xA4, 0x4A, 0xFF, 0xFF, 0xC4, 0x4C, 0xB4, 0x4B,
                       0xA5, 0x5A, 0xFF, 0xFF, 0xC5, 0x5C, 0xB5, 0x5B, 0xA6, 0x6A, 0xFF, 0xFF, 0xC6, 0x6C, 0xB6, 0x6B,
                       0xA7, 0x7A, 0xFF, 0xFF, 0xC7, 0x7C, 0xB7, 0x7B, 0xA8, 0x8A, 0xFF, 0xFF, 0xC8, 0x8C, 0xB8, 0x8B};

extern uint8     CanIf_Rx_Data[64U];
extern uint8     CanIf_Dlc;
extern uint8     CanIf_RxConfirmationCount;
extern uint8     CanIf_TxConfirmationCount;
extern uint32    CanIf_Mainfuc_Bussoff_Cnt;
extern uint32    CanIf_Mainfunc_Mode;
extern uint32    CanIf_Idval;
extern PduIdType CanIf_CanTxPduId;

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
#define READ_WRITE_WAIT_TIME 100000U

/* main function */
int main(void)
{
    Std_ReturnType gTestPassed = E_OK, status = E_NOT_OK;

    uint32       loopCnt;
    Can_PduType *PduInfo;
    uint8        hth          = 0U;
    Os_TickType  elapsedCount = (Os_TickType)0U;

    Pdu.length      = 8;
    Pdu.id          = 100U;
    Pdu.sdu         = Can_Data;
    Pdu.swPduHandle = 1;
    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Can_Example_loopback : Sample Application - STARTS !!!\n");

    /* Flush RxData */
    for (loopCnt = 0U; loopCnt < Pdu.length; loopCnt++)
    {
        CanIf_Rx_Data[loopCnt] = 0U;
    }

    AppUtils_Printf("Can_Example_loopback : Can Controller: MCAN A\n\r");
    PduInfo = &Pdu;
    hth     = 0U;

    /* Set Controller Mode for controller 0U */
    status = Can_SetControllerMode(0U, CAN_CS_STARTED);
    if (status != E_OK)
    {
        gTestPassed = E_NOT_OK;
    }

    /* Do Can Write to send the data on CAN bus */
    AppUtils_Printf("Can_Example_loopback : Can Transmission Started \n\r");
    status = Can_Write(hth, PduInfo);
    if (status != E_OK)
    {
        AppUtils_Printf("Can_Example_loopback : Error In Can_Write.\n\r");
        gTestPassed = E_NOT_OK;
    }

    /* Wait for CAN write and read done. */
    do
    {
        McalLib_Delay(1U);
        elapsedCount += (Os_TickType)15U;
        Can_MainFunction_Write_CanMainFunctionRWPeriods_0();
        Can_MainFunction_Read_CanMainFunctionRWPeriods_0();
        Can_MainFunction_Write_CanMainFunctionRWPeriods_1();
        Can_MainFunction_Read_CanMainFunctionRWPeriods_1();
        Can_MainFunction_Write_CanMainFunctionRWPeriods_2();
        Can_MainFunction_Read_CanMainFunctionRWPeriods_2();
        if (READ_WRITE_WAIT_TIME <= elapsedCount)
        {
            gTestPassed = E_NOT_OK;
            break;
        }
        else
        {
            /*  Do Nothing */
        }
    } while ((CanIf_TxConfirmationCount == 0U) || (CanIf_RxConfirmationCount == 0U));

    if (E_OK == gTestPassed)
    {
        /* Set Controller Mode for controller 0U */
        status = Can_SetControllerMode(0U, CAN_CS_STOPPED);
        if (status != E_OK)
        {
            gTestPassed = E_NOT_OK;
        }

        if ((PduInfo->length == CanIf_Dlc) && (PduInfo->id == CanIf_Idval))
        {
            AppUtils_Printf("Can_Example_loopback : Transmitted and Received Message Id is 0x%X\n\r", PduInfo->id);
            for (loopCnt = 0U; loopCnt < PduInfo->length; loopCnt++)
            {
                if (CanIf_Rx_Data[loopCnt] != Can_Data[loopCnt])
                {
                    gTestPassed = E_NOT_OK;
                    AppUtils_Printf("Can_Example_loopback : Transmitted and Received data mismatched.\n\r");
                }
            }
        }
        else
        {
            gTestPassed = E_NOT_OK;
        }
        if (CanIf_CanTxPduId != PduInfo->swPduHandle)
        {
            gTestPassed = E_NOT_OK;
        }
    }
    if (gTestPassed == E_OK)
    {
        AppUtils_Printf("Can_Example_loopback : Sample Application success\n\r");
    }
    else
    {
        AppUtils_Printf("Can_Example_loopback : Sample Application Failed\n\r");
    }
    return status;
}
