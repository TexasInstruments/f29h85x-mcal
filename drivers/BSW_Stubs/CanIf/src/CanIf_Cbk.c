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
PduIdType CanIf_CanTxPduId;

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
    CanIf_CanTxPduId = CanTxPduId;
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
