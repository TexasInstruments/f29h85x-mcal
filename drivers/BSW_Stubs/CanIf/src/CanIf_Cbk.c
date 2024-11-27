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
 *  File:       CanIf_Cbk.c
 *  Generator:  None
 *
 *  Description:  Functionality related to can interface module
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "CanIf_Cbk.h"
#include "Std_Types.h"


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
uint8  CanIf_Rx_Data[64U];
uint8  CanIf_Dlc;
uint8  CanIf_RxConfirmationCount;
uint8  CanIf_TxConfirmationCount;
uint32 CanIf_Mainfuc_Bussoff_Cnt = 0;
uint32 CanIf_Mainfunc_Mode = 0;
uint32 CanIf_Idval;
uint8 CanIf_Controller;
Can_ControllerStateType CanIf_ControllerMode1;
uint8 CanIf_Hoh;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/


void CanIf_ControllerModeIndication(uint8 ControllerId,Can_ControllerStateType ControllerMode)
{
    CanIf_Controller         = ControllerId;
    CanIf_ControllerMode1    = ControllerMode;
    CanIf_Mainfunc_Mode++;
}


void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    CanIf_TxConfirmationCount++;
}
void CanIf_RxIndication(const Can_HwType *Mailbox, const PduInfoType *PduInfoPtr)
{
    uint8          LoopCnt;
    CanIf_Hoh = Mailbox->Hoh;
    CanIf_RxConfirmationCount++;

    if (PduInfoPtr->SduLength > 64U)
    {
        return;
    }
    /* Copy data */
    CanIf_Idval = Mailbox->CanId;
    CanIf_Dlc = PduInfoPtr->SduLength;
    for (LoopCnt = 0U; LoopCnt < PduInfoPtr->SduLength; LoopCnt++)
    {
        CanIf_Rx_Data[LoopCnt] = PduInfoPtr->SduDataPtr[LoopCnt];
    }

}
void CanIf_ControllerBusOff(uint8 ControllerId)
{
    CanIf_Mainfuc_Bussoff_Cnt++;
}
Std_ReturnType CanIf_TriggerTransmit (PduIdType TxPduId, PduInfoType* PduInfoPtr)
{
    return E_OK;
}

void CanIf_CurrentIcomConfiguration(uint8 ControllerId,IcomConfigIdType ConfigurationId,IcomSwitch_ErrorType Error)
{
	/* Do Nothing */
}


/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: CanIf_Cbk.c
 *********************************************************************************************************************/
