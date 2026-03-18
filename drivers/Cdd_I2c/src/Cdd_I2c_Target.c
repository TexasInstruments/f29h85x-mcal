/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2026 Texas Instruments Incorporated
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
 *  File:       Cdd_I2c_Target.c
 *  Generator:  None
 *
 *  Description:  I2C Target (Slave) mode implementation
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_I2c.h"
#include "Cdd_I2c_Priv.h"
#include "Cdd_I2c_Hw.h"
#include "hw_i2c.h"

#if (CDD_I2C_TARGET_ACTIVE == STD_ON)

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* Interrupt enable mask for target mode */
#define CDD_I2C_HW_INTR_ENABLE_MASK_TARGET                                                    \
    ((uint16)I2C_IER_NACK | /* NACK - controller NACKs target's TX data (end of read)     */  \
     (uint16)I2C_IER_RRDY | /* RRDY - receive data ready (controller writing to target)  */   \
     (uint16)I2C_IER_XRDY | /* XRDY - transmit data ready (controller reading from target) */ \
     (uint16)I2C_IER_SCD)   /* SCD  - stop condition detected (end of transfer)          */

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

static void Cdd_I2c_ProcessTargetEvents(Cdd_I2c_HwUnitObjType *hwUnitObj);
static void Cdd_I2c_TargetSetState(Cdd_I2c_HwUnitObjType *hwUnitObj, Cdd_I2c_TargetStateType targetState);
static Cdd_I2c_TargetStateType Cdd_I2c_TargetGetState(const Cdd_I2c_HwUnitObjType *hwUnitObj);
static void                    Cdd_I2c_TargetRxStart(Cdd_I2c_HwUnitObjType *hwUnitObj);
static void                    Cdd_I2c_TargetRxStop(Cdd_I2c_HwUnitObjType *hwUnitObj);
static void                    Cdd_I2c_TargetRxData(Cdd_I2c_HwUnitObjType *hwUnitObj);
static void                    Cdd_I2c_TargetTxStart(Cdd_I2c_HwUnitObjType *hwUnitObj);
static void                    Cdd_I2c_TargetTxStop(Cdd_I2c_HwUnitObjType *hwUnitObj);
static void                    Cdd_I2c_TargetTxData(Cdd_I2c_HwUnitObjType *hwUnitObj);

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_I2c_TargetHwUnitIdCheck(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitType hwUnitId,
                                                  uint8 apiId);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

#define CDD_I2C_START_SEC_CODE
#include "Cdd_I2c_MemMap.h"

FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_TargetStart(Cdd_I2c_HwUnitType hwUnitId)
{
    Std_ReturnType         retVal = E_OK;
    Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    retVal = Cdd_I2c_TargetHwUnitIdCheck(drvObj, hwUnitId, CDD_I2C_SID_TARGET_START);
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        Cdd_I2c_HwUnitObjType *hwUnitObj;

        hwUnitObj = Cdd_I2c_GetHwUnitObj(drvObj, hwUnitId);
        if ((Cdd_I2c_HwUnitObjType *)NULL_PTR != hwUnitObj)
        {
            Cdd_I2c_TargetSetState(hwUnitObj, CDD_I2C_TARGET_STATE_IDLE);

            /* Set 10-bit mode */
            if (CDD_I2C_ADDRESS_10_BIT == hwUnitObj->hwUnitCfg->addressScheme)
            {
                Cdd_I2c_HwSetMode(hwUnitObj->baseAddr, I2C_MDR_XA, I2C_MDR_XA);
            }
            else
            {
                Cdd_I2c_HwSetMode(hwUnitObj->baseAddr, I2C_MDR_XA, 0U);
            }
            Cdd_I2c_DisableFifo(hwUnitObj->baseAddr);
            Cdd_I2c_HwSetDataCount(hwUnitObj->baseAddr, 0U); /* Not used in target mode */

            /*
             * From F29xx TRM, Basic I2C Interrupt Requests
             *
             * The normal transmit interrupt timing makes it possible for stale data to remain in
             * the transmit buffer if a transaction is aborted in the middle of a byte. To avoid this,
             * set the FCM bit in the I2CEMDR register. When this bit is set, the transmit data ready
             * interrupt is generated only when data is required for a bus transaction.
             *
             * In master mode, the interrupt is first generated when the ACK of the address byte is received.
             * In slave mode, the interrupt is first generated when the address is matched. Further interrupts
             * are generated when the data is ACKed. In this mode, XRDY is asserted at the same time as
             * the transmit ready interrupt.
             */
            Cdd_I2c_SetExtCompatibilityMode(hwUnitObj->baseAddr, I2C_EMDR_FCM);

            /* Clear any stale status flags before enabling interrupts */
            Cdd_I2c_HwClearAllStatus(hwUnitObj->baseAddr);
            Cdd_I2c_HwEnableIntr(hwUnitObj->baseAddr, CDD_I2C_HW_INTR_ENABLE_MASK_TARGET);
        }
        else
        {
            /* With DET this should never happen - this helps in non DET mode */
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_TargetStop(Cdd_I2c_HwUnitType hwUnitId)
{
    Std_ReturnType         retVal = E_OK;
    Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    retVal = Cdd_I2c_TargetHwUnitIdCheck(drvObj, hwUnitId, CDD_I2C_SID_TARGET_STOP);
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        Cdd_I2c_HwUnitObjType *hwUnitObj;

        hwUnitObj = Cdd_I2c_GetHwUnitObj(drvObj, hwUnitId);
        if ((Cdd_I2c_HwUnitObjType *)NULL_PTR != hwUnitObj)
        {
            /* Disable and clear target interrupts */
            Cdd_I2c_HwDisableIntr(hwUnitObj->baseAddr, CDD_I2C_HW_INTR_ENABLE_MASK_TARGET);
            Cdd_I2c_HwClearAllStatus(hwUnitObj->baseAddr);
            Cdd_I2c_SetExtCompatibilityMode(hwUnitObj->baseAddr, I2C_EMDR_BC);
            Cdd_I2c_HwSetMode(hwUnitObj->baseAddr, I2C_MDR_XA, 0U);

            Cdd_I2c_TargetSetState(hwUnitObj, CDD_I2C_TARGET_STATE_IDLE);
        }
        else
        {
            /* With DET this should never happen - this helps in non DET mode */
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_TargetSubmitTxBuffer(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_DataConstPtrType pTxBuffer,
                             Cdd_I2c_DataLengthType txBufferSize)
{
    Std_ReturnType         retVal = E_OK;
    Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    retVal = Cdd_I2c_TargetHwUnitIdCheck(drvObj, hwUnitId, CDD_I2C_SID_TARGET_SUBMIT_TX_BUF);
    if ((retVal == (Std_ReturnType)E_OK) && (pTxBuffer == NULL_PTR))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_TARGET_SUBMIT_TX_BUF,
                              CDD_I2C_E_PARAM_ADDRESS);
        retVal = E_NOT_OK;
    }
    if ((retVal == (Std_ReturnType)E_OK) && (txBufferSize == 0U))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_TARGET_SUBMIT_TX_BUF,
                              CDD_I2C_E_PARAM_LENGTH);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        Cdd_I2c_HwUnitObjType *hwUnitObj;

        hwUnitObj = Cdd_I2c_GetHwUnitObj(drvObj, hwUnitId);
        if ((Cdd_I2c_HwUnitObjType *)NULL_PTR != hwUnitObj)
        {
            SchM_Enter_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
            hwUnitObj->pTxBuffer    = pTxBuffer;
            hwUnitObj->txBufferSize = txBufferSize;
            hwUnitObj->txCount      = 0U;
            hwUnitObj->txUnderflow  = FALSE;
            SchM_Exit_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* With DET this should never happen - this helps in non DET mode */
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_TargetSubmitRxBuffer(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_DataPtrType pRxBuffer,
                             Cdd_I2c_DataLengthType rxBufferSize)
{
    Std_ReturnType         retVal = E_OK;
    Cdd_I2c_DriverObjType *drvObj = &Cdd_I2c_DrvObj;

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
    retVal = Cdd_I2c_TargetHwUnitIdCheck(drvObj, hwUnitId, CDD_I2C_SID_TARGET_SUBMIT_RX_BUF);
    if ((retVal == (Std_ReturnType)E_OK) && (pRxBuffer == NULL_PTR))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_TARGET_SUBMIT_RX_BUF,
                              CDD_I2C_E_PARAM_ADDRESS);
        retVal = E_NOT_OK;
    }
    if ((retVal == (Std_ReturnType)E_OK) && (rxBufferSize == 0U))
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, CDD_I2C_SID_TARGET_SUBMIT_RX_BUF,
                              CDD_I2C_E_PARAM_LENGTH);
        retVal = E_NOT_OK;
    }
    if (retVal == (Std_ReturnType)E_OK)
#endif
    {
        Cdd_I2c_HwUnitObjType *hwUnitObj;

        hwUnitObj = Cdd_I2c_GetHwUnitObj(drvObj, hwUnitId);
        if ((Cdd_I2c_HwUnitObjType *)NULL_PTR != hwUnitObj)
        {
            SchM_Enter_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
            hwUnitObj->pRxBuffer    = pRxBuffer;
            hwUnitObj->rxBufferSize = rxBufferSize;
            hwUnitObj->rxCount      = 0U;
            hwUnitObj->rxOverflow   = FALSE;
            SchM_Exit_Cdd_I2c_CDD_I2C_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* With DET this should never happen - this helps in non DET mode */
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}

void Cdd_I2c_TargetIsr(Cdd_I2c_HwUnitType hwUnitId)
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
        if ((Cdd_I2c_HwUnitObjType *)NULL_PTR != hwUnitObj)
        {
            Cdd_I2c_ProcessTargetEvents(hwUnitObj);
        }
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static void Cdd_I2c_ProcessTargetEvents(Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    uint16 intCode;

    intCode = Cdd_I2c_HwGetIntCode(hwUnitObj->baseAddr);
    switch (intCode)
    {
        case CDD_I2C_ISRC_INTCODE_SCD:
            Cdd_I2c_TargetRxStop(hwUnitObj);
            Cdd_I2c_TargetTxStop(hwUnitObj);
            break;

        case CDD_I2C_ISRC_INTCODE_RRDY:
            Cdd_I2c_TargetTxStop(hwUnitObj);
            Cdd_I2c_TargetRxStart(hwUnitObj);
            Cdd_I2c_TargetRxData(hwUnitObj);
            break;

        case CDD_I2C_ISRC_INTCODE_XRDY:
            Cdd_I2c_TargetRxStop(hwUnitObj);
            Cdd_I2c_TargetTxStart(hwUnitObj);
            Cdd_I2c_TargetTxData(hwUnitObj);
            break;

        case CDD_I2C_ISRC_INTCODE_NACK:
            if (hwUnitObj->hwUnitCfg->targetErrorNotification != NULL_PTR)
            {
                hwUnitObj->hwUnitCfg->targetErrorNotification(hwUnitObj->hwUnitCfg->hwUnitId,
                                                              CDD_I2C_TARGET_EVENT_NACK);
            }
            break;

        default:
            /* No action for unexpected/unhandled INTCODE */
            break;
    }
}

static void Cdd_I2c_TargetSetState(Cdd_I2c_HwUnitObjType *hwUnitObj, Cdd_I2c_TargetStateType targetState)
{
    hwUnitObj->targetState = targetState;
    if (targetState == CDD_I2C_TARGET_STATE_RX)
    {
        Cdd_I2c_HwSetMode(hwUnitObj->baseAddr, I2C_MDR_TRX, 0U);
        hwUnitObj->rxCount = 0U;
    }
    else if (targetState == CDD_I2C_TARGET_STATE_TX)
    {
        Cdd_I2c_HwSetMode(hwUnitObj->baseAddr, I2C_MDR_TRX, I2C_MDR_TRX);
        hwUnitObj->txCount = 0U;
    }
    else
    {
        /* IDLE - no HW config change needed */
    }
}

static Cdd_I2c_TargetStateType Cdd_I2c_TargetGetState(const Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    return hwUnitObj->targetState;
}

static void Cdd_I2c_TargetRxStart(Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    if (Cdd_I2c_TargetGetState(hwUnitObj) == CDD_I2C_TARGET_STATE_IDLE)
    {
        Cdd_I2c_TargetSetState(hwUnitObj, CDD_I2C_TARGET_STATE_RX);
        hwUnitObj->rxOverflow = FALSE; /* Fresh start - reset overflow flag */
        if (hwUnitObj->hwUnitCfg->targetRxStartNotification != NULL_PTR)
        {
            hwUnitObj->hwUnitCfg->targetRxStartNotification(hwUnitObj->hwUnitCfg->hwUnitId);
        }
    }
}

static void Cdd_I2c_TargetRxStop(Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    if (Cdd_I2c_TargetGetState(hwUnitObj) == CDD_I2C_TARGET_STATE_RX)
    {
        if (hwUnitObj->hwUnitCfg->targetRxCompleteNotification != NULL_PTR)
        {
            Cdd_I2c_DataPtrType    pRxBuffer;
            Cdd_I2c_DataLengthType rxCount;

            /* Remove all reference to user provided buffer as we are relinquishing this to user */
            pRxBuffer               = hwUnitObj->pRxBuffer;
            rxCount                 = hwUnitObj->rxCount;
            hwUnitObj->pRxBuffer    = NULL_PTR;
            hwUnitObj->rxBufferSize = 0U;
            hwUnitObj->rxCount      = 0U;
            hwUnitObj->hwUnitCfg->targetRxCompleteNotification(hwUnitObj->hwUnitCfg->hwUnitId, pRxBuffer, rxCount,
                                                               CDD_I2C_TARGET_EVENT_STOP);
        }

        Cdd_I2c_TargetSetState(hwUnitObj, CDD_I2C_TARGET_STATE_IDLE);
    }
}

static void Cdd_I2c_TargetRxData(Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    uint8 rxByte;

    rxByte = Cdd_I2c_HwReadData(hwUnitObj->baseAddr);

    /* If we have valid buffer and empty space, fill the buffer with RX data */
    if ((hwUnitObj->pRxBuffer != NULL_PTR) && (hwUnitObj->rxCount < hwUnitObj->rxBufferSize))
    {
        hwUnitObj->pRxBuffer[hwUnitObj->rxCount] = rxByte;
        hwUnitObj->rxCount++;

        /* Check if buffer is full - if so notify */
        if (hwUnitObj->rxCount == hwUnitObj->rxBufferSize)
        {
            if (hwUnitObj->hwUnitCfg->targetRxCompleteNotification != NULL_PTR)
            {
                Cdd_I2c_DataPtrType    pRxBuffer;
                Cdd_I2c_DataLengthType rxCount;

                /* Remove all reference to user provided buffer as we are relinquishing this to user */
                pRxBuffer               = hwUnitObj->pRxBuffer;
                rxCount                 = hwUnitObj->rxCount;
                hwUnitObj->pRxBuffer    = NULL_PTR;
                hwUnitObj->rxBufferSize = 0U;
                hwUnitObj->rxCount      = 0U;
                hwUnitObj->hwUnitCfg->targetRxCompleteNotification(hwUnitObj->hwUnitCfg->hwUnitId, pRxBuffer, rxCount,
                                                                   CDD_I2C_TARGET_EVENT_TRANSFER_COMPLETE);
            }
        }
    }
    /* No buffer or no empty space in buffer - data is discarded */
    else
    {
        /* Call error notification only once (first time) - no need to notify for every overflow!! */
        if ((hwUnitObj->rxOverflow == FALSE) && (hwUnitObj->hwUnitCfg->targetErrorNotification != NULL_PTR))
        {
            uint8 errorEvent;

            /* Call error notification only once */
            hwUnitObj->rxOverflow = TRUE;

            /* RX overflow - default */
            errorEvent = CDD_I2C_TARGET_EVENT_RX_OVERFLOW;
            if (hwUnitObj->pRxBuffer == NULL_PTR)
            {
                /* No buffer provided */
                errorEvent = CDD_I2C_TARGET_EVENT_NO_BUFFER;
            }
            hwUnitObj->hwUnitCfg->targetErrorNotification(hwUnitObj->hwUnitCfg->hwUnitId, errorEvent);
        }
    }
}

static void Cdd_I2c_TargetTxStart(Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    if (Cdd_I2c_TargetGetState(hwUnitObj) == CDD_I2C_TARGET_STATE_IDLE)
    {
        Cdd_I2c_TargetSetState(hwUnitObj, CDD_I2C_TARGET_STATE_TX);
        hwUnitObj->txUnderflow = FALSE; /* Fresh start - reset overflow flag */
        if (hwUnitObj->hwUnitCfg->targetTxStartNotification != NULL_PTR)
        {
            hwUnitObj->hwUnitCfg->targetTxStartNotification(hwUnitObj->hwUnitCfg->hwUnitId);
        }
    }
}

static void Cdd_I2c_TargetTxStop(Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    if (Cdd_I2c_TargetGetState(hwUnitObj) == CDD_I2C_TARGET_STATE_TX)
    {
        if (hwUnitObj->hwUnitCfg->targetTxCompleteNotification != NULL_PTR)
        {
            Cdd_I2c_DataConstPtrType pTxBuffer;
            Cdd_I2c_DataLengthType   txCount;

            /* Remove all reference to user provided buffer as we are relinquishing this to user */
            pTxBuffer               = hwUnitObj->pTxBuffer;
            txCount                 = hwUnitObj->txCount;
            hwUnitObj->pTxBuffer    = NULL_PTR;
            hwUnitObj->txBufferSize = 0U;
            hwUnitObj->txCount      = 0U;
            hwUnitObj->hwUnitCfg->targetTxCompleteNotification(hwUnitObj->hwUnitCfg->hwUnitId, pTxBuffer, txCount,
                                                               CDD_I2C_TARGET_EVENT_STOP);
        }

        Cdd_I2c_TargetSetState(hwUnitObj, CDD_I2C_TARGET_STATE_IDLE);
    }
}

static void Cdd_I2c_TargetTxData(Cdd_I2c_HwUnitObjType *hwUnitObj)
{
    uint8   txByte;
    boolean errNotify = FALSE;

    /* If we have valid buffer and some data, get the TX data from the buffer */
    if ((hwUnitObj->pTxBuffer != NULL_PTR) && (hwUnitObj->txCount < hwUnitObj->txBufferSize))
    {
        txByte = hwUnitObj->pTxBuffer[hwUnitObj->txCount];
        hwUnitObj->txCount++;

        /* Write immediate before any callback */
        Cdd_I2c_HwWriteData(hwUnitObj->baseAddr, txByte);

        /* Check if buffer is empty - if so notify */
        if (hwUnitObj->txCount == hwUnitObj->txBufferSize)
        {
            if (hwUnitObj->hwUnitCfg->targetTxCompleteNotification != NULL_PTR)
            {
                Cdd_I2c_DataConstPtrType pTxBuffer;
                Cdd_I2c_DataLengthType   txCount;

                /* Remove all reference to user provided buffer as we are relinquishing this to user */
                pTxBuffer               = hwUnitObj->pTxBuffer;
                txCount                 = hwUnitObj->txCount;
                hwUnitObj->pTxBuffer    = NULL_PTR;
                hwUnitObj->txBufferSize = 0U;
                hwUnitObj->txCount      = 0U;
                hwUnitObj->hwUnitCfg->targetTxCompleteNotification(hwUnitObj->hwUnitCfg->hwUnitId, pTxBuffer, txCount,
                                                                   CDD_I2C_TARGET_EVENT_TRANSFER_COMPLETE);
            }
        }
    }
    else
    {
        /* Write immediate before any callback */
        txByte = 0x00U; /* write 0x00 to not hold the bus if we don't have data */
        Cdd_I2c_HwWriteData(hwUnitObj->baseAddr, txByte);
        errNotify = TRUE;
    }

    /* No buffer or no data in buffer */
    if (errNotify == TRUE)
    {
        /* Call error notification only once (first time) - no need to notify for every overflow!! */
        if ((hwUnitObj->txUnderflow == FALSE) && (hwUnitObj->hwUnitCfg->targetErrorNotification != NULL_PTR))
        {
            uint8 errorEvent;

            /* Call error notification only once */
            hwUnitObj->txUnderflow = TRUE;

            /* TX overflow - default */
            errorEvent = CDD_I2C_TARGET_EVENT_TX_UNDERFLOW;
            if (hwUnitObj->pTxBuffer == NULL_PTR)
            {
                /* No buffer provided */
                errorEvent = CDD_I2C_TARGET_EVENT_NO_BUFFER;
            }
            hwUnitObj->hwUnitCfg->targetErrorNotification(hwUnitObj->hwUnitCfg->hwUnitId, errorEvent);
        }
    }
}

#if (STD_ON == CDD_I2C_DEV_ERROR_DETECT)
static Std_ReturnType Cdd_I2c_TargetHwUnitIdCheck(Cdd_I2c_DriverObjType *drvObj, Cdd_I2c_HwUnitType hwUnitId,
                                                  uint8 apiId)
{
    Std_ReturnType         retVal = E_OK;
    Cdd_I2c_HwUnitObjType *hwUnitObj;

    if (CDD_I2C_UNINIT == Cdd_I2c_DrvState)
    {
        (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, apiId, CDD_I2C_E_UNINIT);
        retVal = E_NOT_OK;
    }

    if (retVal == (Std_ReturnType)E_OK)
    {
        hwUnitObj = Cdd_I2c_GetHwUnitObj(drvObj, hwUnitId);
        if ((Cdd_I2c_HwUnitObjType *)NULL_PTR == hwUnitObj)
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, apiId, CDD_I2C_E_PARAM_HWUNIT);
            retVal = E_NOT_OK;
        }
    }

    if (retVal == (Std_ReturnType)E_OK)
    {
        if (hwUnitObj->hwUnitCfg->mode != CDD_I2C_MODE_TARGET)
        {
            (void)Det_ReportError(CDD_I2C_MODULE_ID, CDD_I2C_INSTANCE_ID, apiId, CDD_I2C_E_PARAM_MODE);
            retVal = E_NOT_OK;
        }
    }

    return retVal;
}
#endif

#define CDD_I2C_STOP_SEC_CODE
#include "Cdd_I2c_MemMap.h"

#endif /* CDD_I2C_TARGET_ACTIVE */

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Target.c
 *********************************************************************************************************************/
