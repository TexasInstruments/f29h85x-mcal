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
 *  File:         Can_Example_Classic_FD.c
 *  Generator:    None
 *
 *  Description:  This file contains examples for CAN Classic and FD, enable one controller with 2
 *  hardware objects for Tx and 2 hardware objects in Rx. validate the receive data with respect to
 *  the transmit data, below are sets on this example code.
 *                1. Initialize the Can module.
 *                2. Set controller state to STARTED.
 *                3. Set PCAN with the below setting.
 *                      Mode: CAN, Clock Freq: 80 MHz, DataBase Entry: 1 Mbits/s,
 *                      BitRate[kbit\s]: 1000, SamplePoint: 60%, Pre-scaler:8,
 *                      TSEG1:5, TSEG2:4, tq: 100 ns, Nq: 10 Sync Jump Width: 4,
 *                      Pre-scaler: 10
 *                4. Start sending predefined data from PCAN
 *                      CAN-ID: 64h, Can Mode: Classic Length: 8,
 *                      Data(in Hex): D1 1D FF FF F1 1F E1 1E
 *                5. Send the data using can_write() with pre-defined data.
 *                6. Read Tx confirmation and rx indication.
 *                7. Validate the received data with pre-defined receive data.
 *                8. Set PCAN with the below setting.
 *                      Mode: CAN, Clock Freq: 80 MHz, DataBase Entry: 5 Mbits/s,
 *                      BitRate[kbit\s]: 5000, SamplePoint: 56.3%, Pre-scaler:1,
 *                      TSEG1:8, TSEG2:7, tq: 12.5 ns, Nq: 16 Sync Jump Width: 7,
 *                      Pre-scaler: 1
 *                9. Start sending predefined data from PCAN
 *                      CAN-ID: 101h, Can Mode: Can FD Length: 64, Data(in Hex):
 *                           0xD1, 0x1D, 0xFF, 0xFF, 0xF1, 0x1F, 0xE1, 0x1E,
 *                           0xD2, 0x2D, 0xFF, 0xFF, 0xF2, 0x2F, 0xE2, 0x2E,
 *                           0xD3, 0x3D, 0xFF, 0xFF, 0xF3, 0x3F, 0xE3, 0x3E,
 *                           0xD4, 0x4D, 0xFF, 0xFF, 0xF4, 0x4F, 0xE4, 0x4E,
 *                           0xD5, 0x5D, 0xFF, 0xFF, 0xF5, 0x5F, 0xE5, 0x5E,
 *                           0xD6, 0x6D, 0xFF, 0xFF, 0xF6, 0x6F, 0xE6, 0x6E,
 *                           0xD7, 0x7D, 0xFF, 0xFF, 0xF7, 0x7F, 0xE7, 0x7E,
 *                           0xD8, 0x8D, 0xFF, 0xFF, 0xF8, 0x8F, 0xE8, 0x8E
 *                10. Send the data using can_write() with pre-defined data.
 *                11. Read Tx confirmation and rx indication.
 *                12. Validate the received data with pre-defined receive data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Can_Example_Classic_FD.h"
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

uint8 Can_DataRx[64U] = {0xD1, 0x1D, 0xFF, 0xFF, 0xF1, 0x1F, 0xE1, 0x1E, 0xD2, 0x2D, 0xFF, 0xFF, 0xF2,
                         0x2F, 0xE2, 0x2E, 0xD3, 0x3D, 0xFF, 0xFF, 0xF3, 0x3F, 0xE3, 0x3E, 0xD4, 0x4D,
                         0xFF, 0xFF, 0xF4, 0x4F, 0xE4, 0x4E, 0xD5, 0x5D, 0xFF, 0xFF, 0xF5, 0x5F, 0xE5,
                         0x5E, 0xD6, 0x6D, 0xFF, 0xFF, 0xF6, 0x6F, 0xE6, 0x6E, 0xD7, 0x7D, 0xFF, 0xFF,
                         0xF7, 0x7F, 0xE7, 0x7E, 0xD8, 0x8D, 0xFF, 0xFF, 0xF8, 0x8F, 0xE8, 0x8E};

extern uint8  CanIf_Rx_Data[64U];
extern uint8  CanIf_Dlc;
extern uint8  CanIf_RxConfirmationCount;
extern uint8  CanIf_TxConfirmationCount;
extern uint32 CanIf_Mainfuc_Bussoff_Cnt;
extern uint32 CanIf_Mainfunc_Mode;
extern uint32 CanIf_Idval;

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
    char           option;

    uint32       loopCnt;
    Can_PduType *PduInfo;
    uint8        hth = 0U;

    Pdu.length      = 8;
    Pdu.id          = 100U;
    Pdu.sdu         = Can_Data;
    Pdu.swPduHandle = 1;
    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Can_Example_Classic_FD : Sample Application - STARTS !!!\n");

    /* Flush RxData */
    for (loopCnt = 0U; loopCnt < Pdu.length; loopCnt++)
    {
        CanIf_Rx_Data[loopCnt] = 0U;
    }

    AppUtils_Printf("Can_Example_Classic_FD : Can Controller: MCAN A\n\r");
    PduInfo = &Pdu;
    hth     = 0U;

    /* Set Controller Mode for controller 0U */
    status = Can_SetControllerMode(0U, CAN_CS_STARTED);
    if (status != E_OK)
    {
        gTestPassed = E_NOT_OK;
    }

    AppUtils_Printf(
        "Can_Example_Classic_FD : Mode: Can classic, Transmitted ID value: 0x%x, \
    and length : %d \n\r",
        PduInfo->id, PduInfo->length);
    AppUtils_Printf("Can_Example_Classic_FD : Transmission data: ");
    for (loopCnt = 0U; loopCnt < Pdu.length; loopCnt++)
    {
        AppUtils_Printf("0x%x ", Can_Data[loopCnt]);
    }
    AppUtils_Printf("\n\r");
    /* Do Can Write to send the data on CAN bus */
    AppUtils_Printf("Can_Example_Classic_FD : Can Transmission Started \n\r");

    status = Can_Write(hth, PduInfo);
    if (status != E_OK)
    {
        AppUtils_Printf("Can_Example_Classic_FD : Error In Can_Write.\n\r");
        gTestPassed = E_NOT_OK;
    }

    AppUtils_Printf("Can_Example_Classic_FD : please press 1 if transmitted data matched \n\r");
    option = AppUtils_GetChar();
    if (option != '1')
    {
        gTestPassed = E_NOT_OK;
    }

    if (gTestPassed == E_OK)
    {
        AppUtils_Printf("Can_Example_Classic_FD : Send the data from PCAN as below \n\r");
        AppUtils_Printf(
            "Can_Example_Classic_FD : Mode: Can Classic, ID value: 0x%x,\
         and length : %d \n\r",
            PduInfo->id, PduInfo->length);
        AppUtils_Printf("Can_Example_Classic_FD : data: ");
        for (loopCnt = 0U; loopCnt < Pdu.length; loopCnt++)
        {
            AppUtils_Printf("0x%x ", Can_DataRx[loopCnt]);
        }
        AppUtils_Printf("\n\r");
        AppUtils_Printf("Can_Example_Classic_FD : please press any key after transmitted data \n\r");
        option = AppUtils_GetChar();
        Can_MainFunction_Write_CanMainFunctionRWPeriods_0();
        Can_MainFunction_Read_CanMainFunctionRWPeriods_2();
        if ((PduInfo->length == CanIf_Dlc) && (PduInfo->id == CanIf_Idval))
        {
            AppUtils_Printf("Can_Example_Classic_FD : Received Message Id is 0x%X\n\r", CanIf_Idval);
            for (loopCnt = 0U; loopCnt < PduInfo->length; loopCnt++)
            {
                if (CanIf_Rx_Data[loopCnt] != Can_DataRx[loopCnt])
                {
                    gTestPassed = E_NOT_OK;
                    AppUtils_Printf("Can_Example_Classic_FD : Received data mismatched.\n\r");
                    break;
                }
            }
        }
        else
        {
            AppUtils_Printf("Can_Example_Classic_FD : Received Message Id is 0x%X, length :%d\n\r", CanIf_Idval,
                            CanIf_Dlc);
            gTestPassed = E_NOT_OK;
        }
    }

    if (gTestPassed == E_OK)
    {
        PduInfo->id     = 0x40000101U;
        PduInfo->length = 64;
        AppUtils_Printf(
            "Can_Example_Classic_FD : Mode: Can FD, Transmitted ID value: 0x%x, \
        and length : %d \n\r",
            PduInfo->id, PduInfo->length);
        AppUtils_Printf("Can_Example_Classic_FD : Transmission data: ");
        for (loopCnt = 0U; loopCnt < Pdu.length; loopCnt++)
        {
            AppUtils_Printf("0x%x ", Can_Data[loopCnt]);
        }
        AppUtils_Printf("\n\r");
        /* Do Can Write to send the data on CAN bus */
        AppUtils_Printf("Can_Example_Classic_FD : Can Transmission Started \n\r");
        status = Can_Write(hth, PduInfo);
        if (status != E_OK)
        {
            AppUtils_Printf("Can_Example_Classic_FD : Error In Can_Write.\n\r");
            gTestPassed = E_NOT_OK;
        }

        AppUtils_Printf("Can_Example_Classic_FD : please press 1 if transmitted data matched \n\r");
        option = AppUtils_GetChar();
        if (option != '1')
        {
            gTestPassed = E_NOT_OK;
        }

        if (gTestPassed == E_OK)
        {
            AppUtils_Printf("Can_Example_Classic_FD : Send the data from PCAN as below \n\r");
            AppUtils_Printf(
                "Can_Example_Classic_FD : Mode: Can FD, ID value:\
             0x%x, and length : %d \n\r",
                PduInfo->id, PduInfo->length);
            AppUtils_Printf("Can_Example_Classic_FD : data: ");
            for (loopCnt = 0U; loopCnt < Pdu.length; loopCnt++)
            {
                AppUtils_Printf("0x%x ", Can_DataRx[loopCnt]);
            }
            AppUtils_Printf("\n\r");
            AppUtils_Printf("Can_Example_Classic_FD : please press any key after transmitted data \n\r");
            option = AppUtils_GetChar();
            Can_MainFunction_Read_CanMainFunctionRWPeriods_2();
            if ((PduInfo->length == CanIf_Dlc) && (PduInfo->id == CanIf_Idval))
            {
                AppUtils_Printf("Can_Example_Classic_FD : Received Message Id is 0x%X\n\r", CanIf_Idval);
                for (loopCnt = 0U; loopCnt < PduInfo->length; loopCnt++)
                {
                    if (CanIf_Rx_Data[loopCnt] != Can_DataRx[loopCnt])
                    {
                        gTestPassed = E_NOT_OK;
                        AppUtils_Printf("Can_Example_Classic_FD : Received data mismatched.\n\r");
                        break;
                    }
                }
            }
            else
            {
                gTestPassed = E_NOT_OK;
            }
        }
    }
    if (gTestPassed == E_OK)
    {
        AppUtils_Printf("Can_Example_Classic_FD : Sample Application success\n\r");
    }
    else
    {
        AppUtils_Printf("Can_Example_Classic_FD : Sample Application Failed\n\r");
    }
    return status;
}
