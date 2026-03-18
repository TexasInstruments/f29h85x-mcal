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
 *  File:       Cdd_I2c_Priv.c
 *  Generator:  None
 *
 *  Description:  This file contains the private implementation of I2C MCAL
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_I2c_Priv.h"
#include "Cdd_I2c_Hw.h"

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

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
static void           Cdd_I2c_CheckAndScheduleHw(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitObjType *hwUnitObj);
static Std_ReturnType Cdd_I2c_QueueCh(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_SeqObjType *seqObj);
static Std_ReturnType Cdd_I2c_StartSeqCheck(Cdd_I2c_DriverObjType *drvObj, const Cdd_I2c_SeqObjType *seqObj);
static Std_ReturnType Cdd_I2c_StartChCheck(const Cdd_I2c_ChObjType *chObj);
static void           Cdd_I2c_ScheduleCh(Cdd_I2c_ChObjType *chObj);
static void           Cdd_I2c_SetSeqErrorCode(Cdd_I2c_SeqObjType *seqObj, Cdd_I2c_ChannelResultType chResult);
static void           Cdd_I2c_SetSeqResult(Cdd_I2c_SeqObjType *seqObj);
static void           Cdd_I2c_ProcessChCompletion(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_ChObjType *chObj,
                                                  Cdd_I2c_HwUnitObjType *hwUnitObj, Cdd_I2c_ChannelResultType chResult,
                                                  boolean doSchedule);
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_I2c_CheckSeqConfig(const Cdd_I2c_SequenceConfigType *seqCfg);
#endif
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

static void Cdd_I2c_CheckAndSetDrvState(Cdd_I2c_DriverObjType *drvObj);
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_I2c_CheckHwConfig(const Cdd_I2c_ConfigType *configPtr);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

#define CDD_I2C_START_SEC_CODE
#include "Cdd_I2c_MemMap.h"

void Cdd_I2c_InitDrvObj(Cdd_I2c_DriverObjType *drvObj)
{
    for (uint32 hwIdx = 0U; hwIdx < CDD_I2C_MAX_HW_UNIT; hwIdx++)
    {
        Cdd_I2c_HwUnitObjType *hwUnitObj = &drvObj->hwUnitObj[hwIdx];

        hwUnitObj->hwUnitCfg    = (const Cdd_I2c_HwUnitConfigType *)NULL_PTR;
        hwUnitObj->baseAddr     = 0U;
        hwUnitObj->curChObj     = (Cdd_I2c_ChObjType *)NULL_PTR;
        hwUnitObj->hwUnitStatus = CDD_I2C_HW_UNIT_FREE;
        /* Target mode variables */
        hwUnitObj->targetState  = CDD_I2C_TARGET_STATE_IDLE;
        hwUnitObj->pRxBuffer    = NULL_PTR;
        hwUnitObj->rxBufferSize = 0U;
        hwUnitObj->rxCount      = 0U;
        hwUnitObj->rxOverflow   = FALSE;
        hwUnitObj->pTxBuffer    = NULL_PTR;
        hwUnitObj->txBufferSize = 0U;
        hwUnitObj->txCount      = 0U;
        hwUnitObj->txUnderflow  = FALSE;
        Cdd_I2c_UtilsInitLinkList(&hwUnitObj->llobj);
    }

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
    for (uint32 seqIdx = 0U; seqIdx < CDD_I2C_MAX_SEQ; seqIdx++)
    {
        Cdd_I2c_SeqObjType *seqObj = &drvObj->seqObj[seqIdx];

        seqObj->seqCfg             = (const Cdd_I2c_SequenceConfigType *)NULL_PTR;
        seqObj->sequenceId         = (Cdd_I2c_SequenceType)seqIdx;
        seqObj->hwUnitObj          = (Cdd_I2c_HwUnitObjType *)NULL_PTR;
        seqObj->seqResult          = CDD_I2C_SEQ_OK;
        seqObj->seqErrorCode       = CDD_I2C_E_NO_ERROR;
        seqObj->numChsPending      = 0U;
        seqObj->isCancelInProgress = FALSE;
    }

    for (uint32 chIdx = 0U; chIdx < CDD_I2C_MAX_CH; chIdx++)
    {
        Cdd_I2c_ChObjType *chObj = &drvObj->chObj[chIdx];

        chObj->chCfg              = (const Cdd_I2c_ChConfigType *)NULL_PTR;
        chObj->chId               = (Cdd_I2c_ChannelType)chIdx;
        chObj->seqObj             = (Cdd_I2c_SeqObjType *)NULL_PTR;
        chObj->hwUnitObj          = (Cdd_I2c_HwUnitObjType *)NULL_PTR;
        chObj->txBufPtr           = (Cdd_I2c_DataConstPtrType)NULL_PTR;
        chObj->rxBufPtr           = (Cdd_I2c_DataPtrType)NULL_PTR;
        chObj->length             = 0U;
        chObj->deviceAddress      = 0x00U;
        chObj->addressScheme      = CDD_I2C_ADDRESS_7_BIT;
        chObj->chResult           = CDD_I2C_CH_RESULT_OK;
        chObj->chErrorCode        = CDD_I2C_CH_RESULT_OK;
        chObj->curTxBufPtr        = (Cdd_I2c_DataConstPtrType)NULL_PTR;
        chObj->curRxBufPtr        = (Cdd_I2c_DataPtrType)NULL_PTR;
        chObj->curLength          = 0U;
        chObj->isStopRequired     = TRUE;
        chObj->doBusyCheck        = TRUE;
        chObj->state              = CDD_I2C_STATE_INIT;
        chObj->isCancelInProgress = FALSE;
        Cdd_I2c_UtilsInitNodeObject(&chObj->nodeObj);
    }
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

    return;
}

void Cdd_I2c_DeInitDrvObj(Cdd_I2c_DriverObjType *drvObj)
{
    for (uint32 hwIdx = 0U; hwIdx < CDD_I2C_MAX_HW_UNIT; hwIdx++)
    {
        Cdd_I2c_HwUnitObjType *hwUnitObj = &drvObj->hwUnitObj[hwIdx];
        Cdd_I2c_UtilsDeInitLinkList(&hwUnitObj->llobj);
    }

    return;
}

void Cdd_I2c_CopyConfig(Cdd_I2c_DriverObjType *drvObj, const Cdd_I2c_ConfigType *configPtr)
{
    drvObj->maxHwUnit = CDD_I2C_MAX_HW_UNIT;
    for (uint32 hwIdx = 0U; hwIdx < drvObj->maxHwUnit; hwIdx++)
    {
        Cdd_I2c_HwUnitObjType *hwUnitObj = &drvObj->hwUnitObj[hwIdx];

        hwUnitObj->hwUnitCfg = &configPtr->hwUnitCfg[hwIdx];
        hwUnitObj->baseAddr  = Cdd_I2c_GetHwUnitBaseAddr(hwUnitObj->hwUnitCfg->hwUnitId);
    }

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
    drvObj->maxSeq = CDD_I2C_MAX_SEQ;
    for (uint32 seqIdx = 0U; seqIdx < drvObj->maxSeq; seqIdx++)
    {
        Cdd_I2c_SeqObjType *seqObj = &drvObj->seqObj[seqIdx];

        seqObj->seqCfg    = &configPtr->seqCfg[seqIdx];
        seqObj->hwUnitObj = Cdd_I2c_GetHwUnitObj(drvObj, seqObj->seqCfg->hwUnitId);
#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
        if ((Cdd_I2c_HwUnitObjType *)NULL_PTR == seqObj->hwUnitObj)
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_INIT, CDD_I2C_E_PARAM_HWUNIT);
        }
#endif

        /* Store the references for the applicable channels to this sequence */
        for (uint32 chIdx = 0U; chIdx < seqObj->seqCfg->chPerSeq; chIdx++)
        {
            Cdd_I2c_ChannelType chId  = seqObj->seqCfg->chList[chIdx];
            Cdd_I2c_ChObjType  *chObj = &drvObj->chObj[chId];

            chObj->seqObj    = seqObj;
            chObj->hwUnitObj = seqObj->hwUnitObj;

            /* Force stop between channels in STOP mode or for the last channel in the sequence */
            chObj->isStopRequired = FALSE;
            if ((CDD_I2C_RESTART_MODE_STOP == seqObj->seqCfg->restartMode) ||
                (chIdx == (seqObj->seqCfg->chPerSeq - 1U)))
            {
                chObj->isStopRequired = TRUE;
            }

            /* Don't do bus busy check in restart mode and for non-first channel */
            chObj->doBusyCheck = TRUE;
            if ((CDD_I2C_RESTART_MODE_NOSTOP == seqObj->seqCfg->restartMode) && (chIdx != 0U))
            {
                chObj->doBusyCheck = FALSE;
            }
        }
    }

    drvObj->maxCh = CDD_I2C_MAX_CH;
    for (uint32 chIdx = 0U; chIdx < drvObj->maxCh; chIdx++)
    {
        Cdd_I2c_ChObjType *chObj = &drvObj->chObj[chIdx];

        chObj->chCfg         = &configPtr->chCfg[chIdx];
        chObj->deviceAddress = chObj->chCfg->deviceAddress;
        chObj->addressScheme = chObj->chCfg->addressScheme;
    }
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

    return;
}

Std_ReturnType Cdd_I2c_ResetHwUnitPriv(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    Std_ReturnType                  retVal = E_OK;
    const Cdd_I2c_HwUnitConfigType *hwUnitCfg;
    uint32                          baseAddr;
#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
    Cdd_I2c_ChObjType *chObj;
    Cdd_I2c_UtilsNode *headNode;
#endif

    hwUnitCfg = hwUnitObj->hwUnitCfg;
    baseAddr  = hwUnitObj->baseAddr;

    /* Disable all interrupts to avoid any interrupts during reset */
    Cdd_I2c_HwDisableAllIntr(baseAddr);

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
    /* Check and disable any active channels in process */
    if (NULL_PTR != hwUnitObj->curChObj)
    {
        chObj        = hwUnitObj->curChObj;
        chObj->state = CDD_I2C_STATE_COMPLETE;
        Cdd_I2c_ProcessChCompletion(drvObj, chObj, hwUnitObj, CDD_I2C_CH_RESULT_HW_UNIT_RESET, FALSE);
    }

    /* Clear all queued channels and notify their sequences */
    while ((headNode = Cdd_I2c_UtilsGetHeadNode(&hwUnitObj->llobj)) != NULL_PTR)
    {
        chObj = (Cdd_I2c_ChObjType *)headNode->params.data;
        Cdd_I2c_UtilsUnLinkNodePri(&hwUnitObj->llobj, headNode);
        chObj->state = CDD_I2C_STATE_COMPLETE;
        Cdd_I2c_ProcessChCompletion(drvObj, chObj, hwUnitObj, CDD_I2C_CH_RESULT_HW_UNIT_RESET, FALSE);
    }
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

    /* Re-init HW so that we can continue with a fresh transaction */
    Cdd_I2c_HwInit(baseAddr, hwUnitCfg->baudRate, hwUnitCfg->hwUnitFrequency, hwUnitCfg->sysClk, hwUnitCfg->ownAddress,
                   hwUnitCfg->mode);

    /* No new channel scheduled, hardware is free!! */
    hwUnitObj->hwUnitStatus = CDD_I2C_HW_UNIT_FREE;
    /*
     * Check if all hardware is free so that driver can be
     * put in idle state
     */
    Cdd_I2c_CheckAndSetDrvState(drvObj);

    return retVal;
}

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
Std_ReturnType Cdd_I2c_CheckConfig(const Cdd_I2c_ConfigType *configPtr)
{
    Std_ReturnType retVal = E_OK;

    retVal = Cdd_I2c_CheckHwConfig(configPtr);
#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
    if (retVal == (Std_ReturnType)E_OK)
    {
        for (uint32 seqIdx = 0U; seqIdx < CDD_I2C_MAX_SEQ; seqIdx++)
        {
            const Cdd_I2c_SequenceConfigType *seqCfg = &configPtr->seqCfg[seqIdx];

            retVal = Cdd_I2c_CheckSeqConfig(seqCfg);
            if (retVal != E_OK)
            {
                break;
            }
        }
    }
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

    return retVal;
}
#endif

uint32 Cdd_I2c_GetHwUnitBaseAddr(Cdd_I2c_HwUnitType hwUnitId)
{
    return (Cdd_I2c_HwUnitBaseAddr[hwUnitId]);
}

Cdd_I2c_HwUnitObjType *Cdd_I2c_GetHwUnitObj(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitType hwUnitId)
{
    Cdd_I2c_HwUnitObjType *hwUnitObj = (Cdd_I2c_HwUnitObjType *)NULL_PTR;

    /* HW unit ID may not be the index, so search for matching HW unit */
    for (uint32 hwUnitIdx = 0U; hwUnitIdx < drvObj->maxHwUnit; hwUnitIdx++)
    {
        if (hwUnitId == drvObj->hwUnitObj[hwUnitIdx].hwUnitCfg->hwUnitId)
        {
            hwUnitObj = &drvObj->hwUnitObj[hwUnitIdx];
            break; /* Match found */
        }
    }

    return (hwUnitObj);
}

/*
 * Controller only APIs
 */
#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
Std_ReturnType Cdd_I2c_StartSeqAsync(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_SeqObjType *seqObj)
{
    Std_ReturnType retVal = E_OK;

    /* Queue the chs in this sequence */
    retVal = Cdd_I2c_QueueCh(drvObj, seqObj);
    if (retVal == (Std_ReturnType)E_OK)
    {
        /* Check all the hardware queue and consume any pending channels if
         * the hardware is free */
        for (uint32 hwIdx = 0U; hwIdx < drvObj->maxHwUnit; hwIdx++)
        {
            Cdd_I2c_HwUnitObjType *hwUnitObj;

            hwUnitObj = &drvObj->hwUnitObj[hwIdx];
            if (CDD_I2C_HW_UNIT_FREE == hwUnitObj->hwUnitStatus)
            {
                Cdd_I2c_CheckAndScheduleHw(drvObj, hwUnitObj);
            }
        }
    }

    return retVal;
}

Std_ReturnType Cdd_I2c_CancelSeq(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_SeqObjType *seqObj)
{
    Std_ReturnType     retVal      = E_OK;
    Cdd_I2c_ChObjType *activeChObj = (Cdd_I2c_ChObjType *)NULL_PTR;

    /* Check all channels in the sequence and cancel them */
    for (uint32 chIdx = 0U; chIdx < seqObj->seqCfg->chPerSeq; chIdx++)
    {
        Cdd_I2c_ChannelType    chId;
        Cdd_I2c_ChObjType     *chObj;
        Cdd_I2c_HwUnitObjType *hwUnitObj;

        chId      = seqObj->seqCfg->chList[chIdx];
        chObj     = &drvObj->chObj[chId];
        hwUnitObj = chObj->hwUnitObj;

        /* Check if the channel is in progress */
        if (chObj == hwUnitObj->curChObj)
        {
            /* Stop the on going transfer */
            seqObj->numChsPending      = 1U; /* Only one channel to transfer now */
            seqObj->isCancelInProgress = TRUE;
            chObj->isCancelInProgress  = TRUE;
            activeChObj                = chObj;
        }
        else
        {
            /* Channel is not active. Just remove from queue */
            Cdd_I2c_UtilsUnLinkNodePri(&hwUnitObj->llobj, &chObj->nodeObj);
            /* Set channel results */
            chObj->chResult = CDD_I2C_CH_RESULT_OK;
            chObj->state    = CDD_I2C_STATE_COMPLETE;
        }
    }

    /*
     * Check if any active channel was cancelled and if not the sequence was never started!!
     */
    if (activeChObj == NULL_PTR)
    {
        Cdd_I2c_SequenceErrorNotification errorNotify = (Cdd_I2c_SequenceErrorNotification)NULL_PTR;

        /* Set sequence status */
        seqObj->seqResult     = CDD_I2C_SEQ_CANCELLED;
        seqObj->seqErrorCode  = CDD_I2C_E_CANCELLED;
        seqObj->numChsPending = 0U;

        /* Notify Sequence end */
        errorNotify = seqObj->seqCfg->errorNotify;
        if (NULL_PTR != errorNotify)
        {
            errorNotify(seqObj->seqErrorCode);
        }
    }

    return retVal;
}

void Cdd_I2c_ProcessIsr(Cdd_I2c_HwUnitType hwUnitId)
{
    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        uint32 baseAddr;

        /* Should not come here. Only possible case is MCU registers
         * ISR and stray/old interrupts are pending for instance */
        baseAddr = Cdd_I2c_GetHwUnitBaseAddr(hwUnitId);
        Cdd_I2c_HwDisableAllIntr(baseAddr);
        Cdd_I2c_HwClearAllStatus(baseAddr);
    }
    else
    {
        Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;
        Cdd_I2c_HwUnitObjType *hwUnitObj;

        hwUnitObj = Cdd_I2c_GetHwUnitObj(drvObj, hwUnitId);
        if (NULL_PTR != hwUnitObj)
        {
            Cdd_I2c_ProcessEvents(drvObj, hwUnitObj);
        }
    }

    return;
}

void Cdd_I2c_ProcessEvents(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    Cdd_I2c_ChannelResultType chResult;
    Cdd_I2c_ChObjType        *chObj;

    /* Get the current ch/sequence */
    chObj = hwUnitObj->curChObj;
    if (NULL_PTR != chObj)
    {
        if (TRUE == hwUnitObj->hwUnitCfg->isIntrMode)
        {
            /* Continue the transfer in interrupt mode */
            chResult = Cdd_I2c_HwTxRxIntrContinue(chObj);
        }
        else
        {
            if (CDD_I2C_WRITE == chObj->chCfg->direction)
            {
                chResult = Cdd_I2c_HwTxPollingContinue(chObj);
            }
            else
            {
                chResult = Cdd_I2c_HwRxPollingContinue(chObj);
            }
        }

        /* Channel completed or failed!! */
        if (CDD_I2C_CH_RESULT_PENDING != chResult)
        {
            Cdd_I2c_ProcessChCompletion(drvObj, chObj, hwUnitObj, chResult, TRUE);
        }
    }

    return;
}
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static void Cdd_I2c_CheckAndSetDrvState(Cdd_I2c_DriverObjType *drvObj)
{
    uint32 isSomeHwBusy = (uint32)FALSE;

    for (uint32 hwUnitIdx = 0U; hwUnitIdx < drvObj->maxHwUnit; hwUnitIdx++)
    {
        Cdd_I2c_HwUnitObjType *hwUnitObj = &drvObj->hwUnitObj[hwUnitIdx];
        if (CDD_I2C_HW_UNIT_BUSY == hwUnitObj->hwUnitStatus)
        {
            isSomeHwBusy = (uint32)TRUE;
            break;
        }
    }

    if ((((uint32)FALSE)) == isSomeHwBusy)
    {
        Cdd_I2c_DrvState = CDD_I2C_IDLE;
    }

    return;
}

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_I2c_CheckHwConfig(const Cdd_I2c_ConfigType *configPtr)
{
    Std_ReturnType retVal = E_OK;

    for (uint32 hwIdx = 0U; hwIdx < CDD_I2C_MAX_HW_UNIT; hwIdx++)
    {
        const Cdd_I2c_HwUnitConfigType *hwUnitCfg = &configPtr->hwUnitCfg[hwIdx];

        /* ID is used as index, can't exceed array size */
        if (hwUnitCfg->hwUnitId >= CDD_I2C_HW_UNIT_MAX)
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_INIT, CDD_I2C_E_PARAM_HWUNIT);
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return retVal;
}
#endif

#if (CDD_I2C_CONTROLLER_ACTIVE == STD_ON)
static void Cdd_I2c_CheckAndScheduleHw(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    Cdd_I2c_UtilsNode *headNodeObj;

    /* Check if we have any channel pending in the queue */
    headNodeObj = Cdd_I2c_UtilsGetHeadNode(&hwUnitObj->llobj);
    if (NULL_PTR != headNodeObj)
    {
        Cdd_I2c_ChObjType *nextChObj;

        /* Some channel pending - schedule it */
        nextChObj = (Cdd_I2c_ChObjType *)headNodeObj->params.data;
        Cdd_I2c_UtilsUnLinkNodePri(&hwUnitObj->llobj, headNodeObj);

        hwUnitObj->curChObj     = nextChObj;
        hwUnitObj->hwUnitStatus = CDD_I2C_HW_UNIT_BUSY;
        Cdd_I2c_ScheduleCh(nextChObj);
    }
    else
    {
        /* No new channel scheduled, hardware is free!! */
        hwUnitObj->hwUnitStatus = CDD_I2C_HW_UNIT_FREE;
        /*
         * Check if all hardware is free so that driver can be
         * put in idle state
         */
        Cdd_I2c_CheckAndSetDrvState(drvObj);
    }

    return;
}

static Std_ReturnType Cdd_I2c_QueueCh(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_SeqObjType *seqObj)
{
    Std_ReturnType retVal;

    /* Check for start sequence error */
    retVal = Cdd_I2c_StartSeqCheck(drvObj, seqObj);
    if (((Std_ReturnType)E_OK) == retVal)
    {
        /* Queue all the channels to the respective hardware queue */
        for (uint32 chIdx = 0U; chIdx < seqObj->seqCfg->chPerSeq; chIdx++)
        {
            uint8                  currSeqId;
            Cdd_I2c_ChannelType    chId;
            Cdd_I2c_ChObjType     *chObj;
            Cdd_I2c_HwUnitObjType *hwUnitObj;
            Cdd_I2c_UtilsParams    utilsParams;

            chId      = seqObj->seqCfg->chList[chIdx];
            chObj     = &drvObj->chObj[chId];
            hwUnitObj = chObj->hwUnitObj;

            /* Get current sequence ID which is in progress for this
             * HW unit */
            if (NULL_PTR == hwUnitObj->curChObj)
            {
                /* No sequence in progress. Give invalid ID */
                currSeqId = CDD_I2C_MAX_SEQ;
            }
            else
            {
                currSeqId = hwUnitObj->curChObj->seqObj->sequenceId;
            }

            /* Queue the ch to the hardware queue */
            chObj->seqObj                = seqObj;
            chObj->chResult              = CDD_I2C_CH_RESULT_PENDING;
            chObj->chErrorCode           = CDD_I2C_CH_RESULT_OK;
            chObj->isCancelInProgress    = FALSE;
            utilsParams.data             = chObj;
            utilsParams.priority         = 0U; /* Not used in current implementation */
            utilsParams.seqId            = seqObj->sequenceId;
            utilsParams.seqInterruptible = FALSE; /* Can't split the channels within a seq for I2C */
            Cdd_I2c_UtilsLinkNodePri(&hwUnitObj->llobj, &chObj->nodeObj, &utilsParams, currSeqId);
        }

        /* Set the states */
        seqObj->seqResult          = CDD_I2C_SEQ_PENDING;
        seqObj->seqErrorCode       = CDD_I2C_E_NO_ERROR;
        seqObj->isCancelInProgress = FALSE;
        seqObj->numChsPending      = seqObj->seqCfg->chPerSeq;
        Cdd_I2c_DrvState           = CDD_I2C_BUSY;
    }

    return retVal;
}

static Std_ReturnType Cdd_I2c_StartSeqCheck(Cdd_I2c_DriverObjType *drvObj, const Cdd_I2c_SeqObjType *seqObj)
{
    Std_ReturnType      retVal = (Std_ReturnType)E_OK;
    Cdd_I2c_ChObjType  *chObj;
    Cdd_I2c_ChannelType chId;

    /* check all channels if they are allowed to be queued */
    for (uint32 chIdx = 0U; chIdx < seqObj->seqCfg->chPerSeq; chIdx++)
    {
        chId   = seqObj->seqCfg->chList[chIdx];
        chObj  = &drvObj->chObj[chId];
        retVal = Cdd_I2c_StartChCheck(chObj);
        if (retVal != (Std_ReturnType)E_OK)
        {
            break;
        }
    }

    return retVal;
}

static Std_ReturnType Cdd_I2c_StartChCheck(const Cdd_I2c_ChObjType *chObj)
{
    Std_ReturnType retVal = (Std_ReturnType)E_OK;

    if ((CDD_I2C_WRITE == chObj->chCfg->direction) && (NULL_PTR == chObj->txBufPtr))
    {
        /* Invalid write buffer pointer */
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    if ((CDD_I2C_READ == chObj->chCfg->direction) && (NULL_PTR == chObj->rxBufPtr))
    {
        /* Invalid read buffer pointer */
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    if (0U == chObj->length)
    {
        /* Invalid length to transfer */
        retVal = (Std_ReturnType)E_NOT_OK;
    }

    return retVal;
}

static void Cdd_I2c_ScheduleCh(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_ChannelResultType chResult;

    /* Set the states */
    chObj->chResult    = CDD_I2C_CH_RESULT_PENDING;
    chObj->chErrorCode = CDD_I2C_CH_RESULT_OK;
    chObj->curTxBufPtr = chObj->txBufPtr;
    chObj->curRxBufPtr = chObj->rxBufPtr;
    chObj->curLength   = 0U;

    if (TRUE == chObj->hwUnitObj->hwUnitCfg->isIntrMode)
    {
        /* Start the channel in interrupt mode */
        if (CDD_I2C_WRITE == chObj->chCfg->direction)
        {
            chResult = Cdd_I2c_HwTxIntr(chObj);
        }
        else
        {
            chResult = Cdd_I2c_HwRxIntr(chObj);
        }
    }
    else
    {
        /* Start the channel in polled mode */
        if (CDD_I2C_WRITE == chObj->chCfg->direction)
        {
            chResult = Cdd_I2c_HwTxPolling(chObj);
        }
        else
        {
            chResult = Cdd_I2c_HwRxPolling(chObj);
        }
    }

    /* Store result only if not pending - happens only for error case.
     * This is because the ISR could get triggered immediately and the channel
     * status could be set in the ISR. If so the next statement could overwrite the
     * result set in the ISR */
    if (chResult != CDD_I2C_CH_RESULT_PENDING)
    {
        chObj->chResult = chResult;
    }

    return;
}

static void Cdd_I2c_SetSeqErrorCode(Cdd_I2c_SeqObjType *seqObj, Cdd_I2c_ChannelResultType chResult)
{
    /* Fail the sequence if channel fails */
    if (CDD_I2C_CH_RESULT_OK != chResult)
    {
        seqObj->seqErrorCode = CDD_I2C_E_BUS_FAILURE;
    }

    /*
     * Override with specific error code
     */
    if (CDD_I2C_CH_RESULT_NACKFAIL == chResult)
    {
        seqObj->seqErrorCode = CDD_I2C_E_NACK_RECEIVED;
    }
    /* TI_COVERAGE_GAP_START Arbitration loss error cannot be recreated in test environment */
    if (CDD_I2C_CH_RESULT_ARBFAIL == chResult)
    {
        seqObj->seqErrorCode = CDD_I2C_E_ARBITRATION_FAILURE;
    }
    /* TI_COVERAGE_GAP_STOP */
    if (CDD_I2C_CH_RESULT_HW_UNIT_RESET == chResult)
    {
        seqObj->seqErrorCode = CDD_I2C_E_HW_UNIT_RESET;
    }

    return;
}

static void Cdd_I2c_SetSeqResult(Cdd_I2c_SeqObjType *seqObj)
{
    seqObj->seqResult = CDD_I2C_SEQ_OK;
    /* check if any channel has previously failed or cancelled */
    if (CDD_I2C_E_NO_ERROR != seqObj->seqErrorCode)
    {
        seqObj->seqResult = CDD_I2C_SEQ_FAILED;
    }

    /*
     * Override with specific error code
     */
    if (CDD_I2C_E_NACK_RECEIVED == seqObj->seqErrorCode)
    {
        seqObj->seqResult = CDD_I2C_SEQ_NACK;
    }
    /* TI_COVERAGE_GAP_START Arbitration loss error cannot be recreated in test environment */
    if (CDD_I2C_E_ARBITRATION_FAILURE == seqObj->seqErrorCode)
    {
        seqObj->seqResult = CDD_I2C_SEQ_ARB;
    }
    /* TI_COVERAGE_GAP_STOP */
    if (TRUE == seqObj->isCancelInProgress)
    {
        seqObj->seqResult          = CDD_I2C_SEQ_CANCELLED;
        seqObj->seqErrorCode       = CDD_I2C_E_CANCELLED;
        seqObj->isCancelInProgress = FALSE;
    }
    if (CDD_I2C_E_HW_UNIT_RESET == seqObj->seqErrorCode)
    {
        seqObj->seqResult = CDD_I2C_SEQ_HW_UNIT_RESET;
    }

    return;
}

static void Cdd_I2c_ProcessChCompletion(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_ChObjType *chObj,
                                        Cdd_I2c_HwUnitObjType *hwUnitObj, Cdd_I2c_ChannelResultType chResult,
                                        boolean doSchedule)
{
    Cdd_I2c_SeqObjType               *seqObj;
    Cdd_I2c_SequenceEndNotification   completeNotify = (Cdd_I2c_SequenceEndNotification)NULL_PTR;
    Cdd_I2c_SequenceErrorNotification errorNotify    = (Cdd_I2c_SequenceErrorNotification)NULL_PTR;

    seqObj = chObj->seqObj;
    seqObj->numChsPending--;
    hwUnitObj->curChObj       = (Cdd_I2c_ChObjType *)NULL_PTR;
    chObj->chResult           = chResult;
    chObj->isCancelInProgress = FALSE;
    Cdd_I2c_SetSeqErrorCode(seqObj, chResult);

    /* Check if sequence is complete */
    if (0U == seqObj->numChsPending)
    {
        /* Set sequence result based on already set error code */
        Cdd_I2c_SetSeqResult(seqObj);

        /* Call the corresponding callback based on error or not */
        if (CDD_I2C_SEQ_OK == seqObj->seqResult)
        {
            completeNotify = seqObj->seqCfg->completeNotify;
        }
        else
        {
            errorNotify = seqObj->seqCfg->errorNotify;
        }
    }

    if (TRUE == doSchedule)
    {
        /* Check if HW is free and can be scheduled */
        Cdd_I2c_CheckAndScheduleHw(drvObj, hwUnitObj);
    }

    /* Notify Sequence end - should be done after scheduling */
    if (NULL_PTR != completeNotify)
    {
        completeNotify();
    }
    if (NULL_PTR != errorNotify)
    {
        errorNotify(seqObj->seqErrorCode);
    }

    return;
}

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_I2c_CheckSeqConfig(const Cdd_I2c_SequenceConfigType *seqCfg)
{
    Std_ReturnType retVal = E_OK;

    /* ID is used as index, can't exceed array size */
    if (seqCfg->chPerSeq > CDD_I2C_MAX_CH_PER_SEQ)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_INIT, CDD_I2C_E_PARAM_SEQUENCE);
        retVal = (Std_ReturnType)E_NOT_OK;
    }

    if (retVal == (Std_ReturnType)E_OK)
    {
        for (uint32 chIdx = 0U; chIdx < seqCfg->chPerSeq; chIdx++)
        {
            /* ID is used as index, can't exceed array size */
            if (seqCfg->chList[chIdx] >= CDD_I2C_MAX_CH)
            {
                (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_INIT,
                                      CDD_I2C_E_PARAM_SEQUENCE);
                retVal = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }

    return retVal;
}
#endif
#endif /* CDD_I2C_CONTROLLER_ACTIVE */

#define CDD_I2C_STOP_SEC_CODE
#include "Cdd_I2c_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Priv.c
 *********************************************************************************************************************/
