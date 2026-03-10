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
 *  File:       Cdd_I2c_Hw.c
 *  Generator:  None
 *
 *  Description:  This file contains the private implementation of I2C HW functions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_I2c_Hw.h"
#include "hw_types.h"
#include "hw_i2c.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* Interrupt enable masks */
#define CDD_I2C_HW_INTR_ENABLE_MASK_ALL                                                          \
    ((uint16)I2C_IER_ARBL | (uint16)I2C_IER_NACK | (uint16)I2C_IER_ARDY | (uint16)I2C_IER_RRDY | \
     (uint16)I2C_IER_XRDY | (uint16)I2C_IER_SCD | (uint16)I2C_IER_AAT)
#define CDD_I2C_HW_INTR_ENABLE_MASK_TX \
    ((uint16)I2C_IER_ARBL | (uint16)I2C_IER_NACK | (uint16)I2C_IER_ARDY | (uint16)I2C_IER_XRDY | (uint16)I2C_IER_SCD)
#define CDD_I2C_HW_INTR_ENABLE_MASK_RX \
    ((uint16)I2C_IER_ARBL | (uint16)I2C_IER_NACK | (uint16)I2C_IER_RRDY | (uint16)I2C_IER_SCD)
/* Interrupt status masks */
#define CDD_I2C_HW_INTR_STATUS_MASK_ALL                                                                              \
    ((uint16)I2C_STR_ARBL | (uint16)I2C_STR_NACK | (uint16)I2C_STR_ARDY | (uint16)I2C_STR_RRDY |                     \
     (uint16)I2C_STR_XRDY | (uint16)I2C_STR_SCD | (uint16)I2C_STR_AD0 | (uint16)I2C_STR_AAT | (uint16)I2C_STR_XSMT | \
     (uint16)I2C_STR_RSFULL | (uint16)I2C_STR_BB | (uint16)I2C_STR_NACKSNT | (uint16)I2C_STR_TDIR)
#define CDD_I2C_HW_INTR_STATUS_MASK_ERR ((uint16)I2C_STR_ARBL | (uint16)I2C_STR_NACK | (uint16)I2C_STR_AD0)

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

static void Cdd_I2c_HwSetup(Cdd_I2c_ChObjType *chObj, boolean isIntrMode);
static void Cdd_I2c_HwSetupClk(uint32 baseAddr, uint32 baudRate, uint32 hwUnitFrequency, uint32 sysClk, uint8 mode);

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoWaitForBusFree(Cdd_I2c_ChObjType *chObj);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoWaitForBusBusy(Cdd_I2c_ChObjType *chObj);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoTransferTxPolling(Cdd_I2c_ChObjType *chObj);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoTransferTxIntr(Cdd_I2c_ChObjType *chObj, uint16 intrStatus);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoTransferRxPolling(Cdd_I2c_ChObjType *chObj);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoTransferRxIntr(Cdd_I2c_ChObjType *chObj, uint16 intrStatus);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoWaitForAccessReady(Cdd_I2c_ChObjType *chObj);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoWaitForStop(Cdd_I2c_ChObjType *chObj);

static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForBusFree(uint32 baseAddr);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForBusBusy(uint32 baseAddr);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForTxReady(uint32 baseAddr);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForRxReady(uint32 baseAddr);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForAccessReady(uint32 baseAddr);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForStop(uint32 baseAddr);
static Cdd_I2c_ChannelResultType Cdd_I2c_HwGetErrorCode(uint16 intrStatus, boolean checkStopStatus);

static void Cdd_I2c_HwReset(uint32 baseAddr);
static void Cdd_I2c_HwEnableModule(uint32 baseAddr, uint8 mode);
static void Cdd_I2c_HwStop(uint32 baseAddr);

static void   Cdd_I2c_HwClearIntr(uint32 baseAddr, uint16 mask);
static uint16 Cdd_I2c_HwGetIntrStatus(uint32 baseAddr);

static void Cdd_I2c_HwSetOwnAddress(uint32 baseAddr, uint16 ownAddress);
static void Cdd_I2c_HwSetSlaveAddress(uint32 baseAddr, Cdd_I2c_AddressType deviceAddress);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

#define CDD_I2C_START_SEC_CODE
#include "Cdd_I2c_MemMap.h"

void Cdd_I2c_HwInit(uint32 baseAddr, uint32 baudRate, uint32 hwUnitFrequency, uint32 sysClk,
                    Cdd_I2c_AddressType ownAddress, uint8 mode)
{
    Cdd_I2c_HwReset(baseAddr);

    /* Setup prescaler (both modes) and baud rate (controller only) */
    Cdd_I2c_HwSetupClk(baseAddr, baudRate, hwUnitFrequency, sysClk, mode);

    /* Disable/clear all interrupts and enable the module */
    Cdd_I2c_HwDisableAllIntr(baseAddr);
    Cdd_I2c_HwClearAllStatus(baseAddr);
    Cdd_I2c_HwEnableModule(baseAddr, mode);
    Cdd_I2c_HwSetOwnAddress(baseAddr, ownAddress);

    return;
}

void Cdd_I2c_HwDeInit(uint32 baseAddr)
{
    Cdd_I2c_HwDisableAllIntr(baseAddr);
    Cdd_I2c_HwClearAllStatus(baseAddr);
    Cdd_I2c_HwReset(baseAddr);

    return;
}

Cdd_I2c_ChannelResultType Cdd_I2c_HwTxPolling(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_ChannelResultType chResult;

    /* Init variables */
    chObj->chResult = CDD_I2C_CH_RESULT_PENDING;
    if (TRUE == chObj->doBusyCheck)
    {
        /* Wait for bus to get free */
        chObj->state = CDD_I2C_STATE_WAIT_FOR_BUS_FREE;
    }
    else
    {
        /* Start with setup state directly */
        chObj->state = CDD_I2C_STATE_SETUP;
    }
    chResult = Cdd_I2c_HwTxPollingContinue(chObj);

    return chResult;
}

Cdd_I2c_ChannelResultType Cdd_I2c_HwTxPollingContinue(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_ChannelResultType chResult = chObj->chResult;

    /*
     * If not started yet and is cancelled, just return
     */
    if (TRUE == chObj->isCancelInProgress)
    {
        if (chObj->state <= CDD_I2C_STATE_SETUP)
        {
            chResult     = CDD_I2C_CH_RESULT_OK;
            chObj->state = CDD_I2C_STATE_COMPLETE;
        }
    }

    if (CDD_I2C_STATE_WAIT_FOR_BUS_FREE == chObj->state)
    {
        chResult = Cdd_I2c_HwStateDoWaitForBusFree(chObj);
    }

    if (CDD_I2C_STATE_SETUP == chObj->state)
    {
        Cdd_I2c_HwSetup(chObj, FALSE);
        chObj->state = CDD_I2C_STATE_WAIT_FOR_BUS_BUSY;
    }

    if (CDD_I2C_STATE_WAIT_FOR_BUS_BUSY == chObj->state)
    {
        chResult = Cdd_I2c_HwStateDoWaitForBusBusy(chObj);
    }

    if (CDD_I2C_STATE_DATA_TRANSFER == chObj->state)
    {
        if (TRUE == chObj->isCancelInProgress)
        {
            /* Skip further transfers in data transfer state - the main difference in
             * cancel compared to regular transfer */
            chObj->state = CDD_I2C_STATE_WAIT_FOR_ACCESS_READY;
        }
        else
        {
            chResult = Cdd_I2c_HwStateDoTransferTxPolling(chObj);
        }
    }

    if (CDD_I2C_STATE_WAIT_FOR_ACCESS_READY == chObj->state)
    {
        chResult = Cdd_I2c_HwStateDoWaitForAccessReady(chObj);
    }

    if (CDD_I2C_STATE_WAIT_FOR_STOP == chObj->state)
    {
        chResult = Cdd_I2c_HwStateDoWaitForStop(chObj);
    }

    return chResult;
}

Cdd_I2c_ChannelResultType Cdd_I2c_HwRxPolling(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_ChannelResultType chResult;

    /* Init variables */
    chObj->chResult = CDD_I2C_CH_RESULT_PENDING;
    if (TRUE == chObj->doBusyCheck)
    {
        /* Wait for bus to get free */
        chObj->state = CDD_I2C_STATE_WAIT_FOR_BUS_FREE;
    }
    else
    {
        /* Start with setup state directly */
        chObj->state = CDD_I2C_STATE_SETUP;
    }
    chResult = Cdd_I2c_HwRxPollingContinue(chObj);

    return chResult;
}

Cdd_I2c_ChannelResultType Cdd_I2c_HwRxPollingContinue(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_ChannelResultType chResult = chObj->chResult;

    /*
     * If not started yet and is cancelled, just return
     */
    if (TRUE == chObj->isCancelInProgress)
    {
        if (chObj->state <= CDD_I2C_STATE_SETUP)
        {
            chResult     = CDD_I2C_CH_RESULT_OK;
            chObj->state = CDD_I2C_STATE_COMPLETE;
        }
    }

    if (CDD_I2C_STATE_WAIT_FOR_BUS_FREE == chObj->state)
    {
        chResult = Cdd_I2c_HwStateDoWaitForBusFree(chObj);
    }

    if (CDD_I2C_STATE_SETUP == chObj->state)
    {
        Cdd_I2c_HwSetup(chObj, FALSE);
        chObj->state = CDD_I2C_STATE_WAIT_FOR_BUS_BUSY;
    }

    if (CDD_I2C_STATE_WAIT_FOR_BUS_BUSY == chObj->state)
    {
        chResult = Cdd_I2c_HwStateDoWaitForBusBusy(chObj);
    }

    if (CDD_I2C_STATE_DATA_TRANSFER == chObj->state)
    {
        /* Incase of cancel, wait for a RX event to exit the transfer gracefully */
        if (TRUE == chObj->isCancelInProgress)
        {
            Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
            uint32                    baseAddr  = hwUnitObj->baseAddr;
            Cdd_I2c_ChannelResultType chResultTemp;

            chResultTemp = Cdd_I2c_HwCheckForRxReady(baseAddr);
            if (CDD_I2C_CH_RESULT_OK == chResultTemp)
            {
                chObj->state = CDD_I2C_STATE_WAIT_FOR_STOP;
                Cdd_I2c_HwStop(baseAddr);
            }
        }
        else
        {
            /* Read the remaining bytes */
            chResult = Cdd_I2c_HwStateDoTransferRxPolling(chObj);
        }
    }

    if (CDD_I2C_STATE_WAIT_FOR_STOP == chObj->state)
    {
        chResult = Cdd_I2c_HwStateDoWaitForStop(chObj);
    }

    return chResult;
}

Cdd_I2c_ChannelResultType Cdd_I2c_HwTxIntr(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_OK;

    Cdd_I2c_HwSetup(chObj, TRUE);
    chObj->state = CDD_I2C_STATE_DATA_TRANSFER;

    return chResult;
}

Cdd_I2c_ChannelResultType Cdd_I2c_HwRxIntr(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_OK;

    Cdd_I2c_HwSetup(chObj, TRUE);
    chObj->state = CDD_I2C_STATE_DATA_TRANSFER;

    return chResult;
}

Cdd_I2c_ChannelResultType Cdd_I2c_HwTxRxIntrContinue(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult  = CDD_I2C_CH_RESULT_PENDING;
    Cdd_I2c_ChannelResultType chErrorCode;
    uint16                    intrStatus;

    /* Get status */
    intrStatus = Cdd_I2c_HwGetIntrStatus(baseAddr);

    /* Check for errors */
    chErrorCode = Cdd_I2c_HwGetErrorCode(intrStatus, FALSE);
    if (chErrorCode != CDD_I2C_CH_RESULT_OK)
    {
        chObj->chErrorCode = chErrorCode;
        Cdd_I2c_HwDisableIntr(baseAddr, CDD_I2C_HW_INTR_STATUS_MASK_ERR);
        Cdd_I2c_HwClearIntr(baseAddr, CDD_I2C_HW_INTR_STATUS_MASK_ERR);

        /* NACK or AL Errors - force stop */
        chObj->state = CDD_I2C_STATE_WAIT_FOR_STOP;
        Cdd_I2c_HwStop(baseAddr);
    }
    /* Check for stop condition */
    else if ((intrStatus & I2C_STR_SCD) != 0U)
    {
        /* End of transfer - disable and clear all status */
        Cdd_I2c_HwDisableAllIntr(baseAddr);
        Cdd_I2c_HwClearAllStatus(baseAddr);
        chResult     = chObj->chErrorCode;
        chObj->state = CDD_I2C_STATE_COMPLETE;
    }
    else
    {
        if (TRUE == chObj->isCancelInProgress)
        {
            Cdd_I2c_HwDisableIntr(baseAddr, I2C_IER_ARDY | I2C_IER_XRDY | I2C_IER_RRDY);
            Cdd_I2c_HwClearIntr(baseAddr, I2C_STR_ARDY | I2C_IER_XRDY | I2C_IER_RRDY);

            chObj->state = CDD_I2C_STATE_WAIT_FOR_STOP;
            Cdd_I2c_HwStop(baseAddr);
        }
        else
        {
            if (CDD_I2C_WRITE == chObj->chCfg->direction)
            {
                chResult = Cdd_I2c_HwStateDoTransferTxIntr(chObj, intrStatus);
            }
            else
            {
                chResult = Cdd_I2c_HwStateDoTransferRxIntr(chObj, intrStatus);
            }
        }
    }

    return chResult;
}

void Cdd_I2c_HwDisableAllIntr(uint32 baseAddr)
{
    Cdd_I2c_HwDisableIntr(baseAddr, CDD_I2C_HW_INTR_ENABLE_MASK_ALL);
}

void Cdd_I2c_HwClearAllStatus(uint32 baseAddr)
{
    Cdd_I2c_HwClearIntr(baseAddr, CDD_I2C_HW_INTR_STATUS_MASK_ALL);
}

void Cdd_I2c_HwSetMode(uint32 baseAddr, uint16 ctrlMask, uint16 ctrlCmds)
{
    uint16 regVal;

    regVal                        = HWREGH(baseAddr + I2C_O_MDR);
    regVal                       &= (uint16)~ctrlMask;
    regVal                       |= ctrlCmds;
    HWREGH(baseAddr + I2C_O_MDR)  = regVal;
}

void Cdd_I2c_HwSetDataCount(uint32 baseAddr, uint16 length)
{
    HWREGH(baseAddr + I2C_O_CNT) = length;
}

void Cdd_I2c_DisableFifo(uint32 baseAddr)
{
    uint16 regVal;

    /* Disable both TX and RX FIFOs */
    regVal                         = HWREGH(baseAddr + I2C_O_FFTX);
    regVal                        &= (uint16)~I2C_FFTX_I2CFFEN;
    HWREGH(baseAddr + I2C_O_FFTX)  = regVal;
    regVal                         = HWREGH(baseAddr + I2C_O_FFRX);
    regVal                        &= (uint16)~I2C_FFRX_RXFFRST;
    HWREGH(baseAddr + I2C_O_FFRX)  = regVal;
}

void Cdd_I2c_SetExtCompatibilityMode(uint32 baseAddr, uint8 extCompMode)
{
    uint16 regVal;

    regVal                         = HWREGH(baseAddr + I2C_O_EMDR);
    regVal                        &= (uint16)(~(I2C_EMDR_BC | I2C_EMDR_FCM));
    regVal                        |= (uint16)extCompMode;
    HWREGH(baseAddr + I2C_O_EMDR)  = regVal;
}

uint16 Cdd_I2c_HwGetIntCode(uint32 baseAddr)
{
    return HWREGH(baseAddr + I2C_O_ISRC) & I2C_ISRC_INTCODE_M;
}

void Cdd_I2c_HwWriteData(uint32 baseAddr, uint8 data)
{
    HWREGH(baseAddr + I2C_O_DXR) = (uint8)data;
}

uint8 Cdd_I2c_HwReadData(uint32 baseAddr)
{
    return (uint8)HWREGH(baseAddr + I2C_O_DRR);
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static void Cdd_I2c_HwSetup(Cdd_I2c_ChObjType *chObj, boolean isIntrMode)
{
    Cdd_I2c_HwUnitObjType *hwUnitObj = chObj->hwUnitObj;
    uint32                 baseAddr  = hwUnitObj->baseAddr;
    uint16                 ctrlMask, ctrlCmds;

    Cdd_I2c_HwClearAllStatus(baseAddr);
    Cdd_I2c_HwSetSlaveAddress(baseAddr, chObj->deviceAddress);
    Cdd_I2c_HwSetDataCount(baseAddr, chObj->length);
    if (isIntrMode == TRUE)
    {
        if (CDD_I2C_WRITE == chObj->chCfg->direction)
        {
            Cdd_I2c_HwEnableIntr(baseAddr, CDD_I2C_HW_INTR_ENABLE_MASK_TX);
        }
        else
        {
            Cdd_I2c_HwEnableIntr(baseAddr, CDD_I2C_HW_INTR_ENABLE_MASK_RX);
        }
    }

    /* Master mode bit is auto cleared for every transaction - set this everytime */
    ctrlMask = I2C_MDR_CNT | I2C_MDR_TRX | I2C_MDR_RM | I2C_MDR_XA | I2C_MDR_STP;
    ctrlCmds = I2C_MDR_CNT;
    if (CDD_I2C_WRITE == chObj->chCfg->direction)
    {
        ctrlCmds |= I2C_MDR_TRX;
    }
    if (CDD_I2C_ADDRESS_10_BIT == chObj->addressScheme)
    {
        ctrlCmds |= I2C_MDR_XA;
    }
    /* Start along with setting other bits */
    ctrlMask |= I2C_MDR_STT;
    ctrlCmds |= I2C_MDR_STT;

    if (CDD_I2C_WRITE == chObj->chCfg->direction)
    {
        /* Write the first data */
        Cdd_I2c_HwWriteData(baseAddr, *chObj->curTxBufPtr);
        chObj->curTxBufPtr++;
        chObj->curLength++;
    }

    /* Start */
    Cdd_I2c_HwSetMode(baseAddr, ctrlMask, ctrlCmds);

    return;
}

static void Cdd_I2c_HwSetupClk(uint32 baseAddr, uint32 baudRate, uint32 hwUnitFrequency, uint32 sysClk, uint8 mode)
{
    uint16 preScaler;

    /* Calculate and set prescaler to derive module clock from system clock */
    preScaler                    = (uint16)((sysClk / hwUnitFrequency) - 1U);
    HWREGH(baseAddr + I2C_O_PSC) = preScaler;

    /* Baud rate (CLKH/CLKL) only applies to controller mode; target does not drive SCL */
    if (CDD_I2C_MODE_CONTROLLER == mode)
    {
        uint16 diff;
        uint16 divisor, clkh, clkl;
        uint32 hwUnitFrequencyActual;

        /* Determine diff based on prescaler */
        if (preScaler == 0U)
        {
            diff = 7U;
        }
        else if (preScaler == 1U)
        {
            diff = 6U;
        }
        else
        {
            diff = 5U;
        }

        /* Calculate divisor - use actual module frequency after prescaler */
        hwUnitFrequencyActual          = sysClk / ((uint32)preScaler + 1U);
        divisor                        = (uint16)(hwUnitFrequencyActual / baudRate);
        divisor                       -= (2U * diff);
        clkh                           = divisor >> 1U;
        clkl                           = divisor - clkh;
        HWREGH(baseAddr + I2C_O_CLKH)  = clkh;
        HWREGH(baseAddr + I2C_O_CLKL)  = clkl;
    }

    return;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoWaitForBusFree(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult;

    chResult = Cdd_I2c_HwCheckForBusFree(baseAddr);
    if (CDD_I2C_CH_RESULT_OK == chResult)
    {
        chResult     = CDD_I2C_CH_RESULT_PENDING;
        chObj->state = CDD_I2C_STATE_SETUP;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoWaitForBusBusy(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult;

    chResult = Cdd_I2c_HwCheckForBusBusy(baseAddr);
    if (CDD_I2C_CH_RESULT_OK == chResult)
    {
        chResult     = CDD_I2C_CH_RESULT_PENDING;
        chObj->state = CDD_I2C_STATE_DATA_TRANSFER;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoTransferTxPolling(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult;

    chResult = Cdd_I2c_HwCheckForTxReady(baseAddr);
    if (CDD_I2C_CH_RESULT_OK == chResult)
    {
        chResult = CDD_I2C_CH_RESULT_PENDING;
        if (chObj->curLength < chObj->length)
        {
            /* Write the remaining data */
            Cdd_I2c_HwWriteData(baseAddr, *chObj->curTxBufPtr);
            chObj->curTxBufPtr++;
            chObj->curLength++;
        }
        else
        {
            chObj->state = CDD_I2C_STATE_WAIT_FOR_ACCESS_READY;
        }
    }
    else
    {
        if (CDD_I2C_CH_RESULT_PENDING != chResult)
        {
            /* NACK or AL Errors - force stop */
            chObj->chErrorCode = chResult;
            chResult           = CDD_I2C_CH_RESULT_PENDING;
            chObj->state       = CDD_I2C_STATE_WAIT_FOR_ACCESS_READY;
        }
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoTransferTxIntr(Cdd_I2c_ChObjType *chObj, uint16 intrStatus)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult  = CDD_I2C_CH_RESULT_PENDING;

    /* Check for access ready condition */
    if ((intrStatus & I2C_IER_ARDY) != 0U)
    {
        if (chObj->curLength == chObj->length)
        {
            Cdd_I2c_HwDisableIntr(baseAddr, I2C_IER_ARDY);
            Cdd_I2c_HwClearIntr(baseAddr, I2C_STR_ARDY);
            if (TRUE == chObj->isStopRequired)
            {
                chObj->state = CDD_I2C_STATE_WAIT_FOR_STOP;
                Cdd_I2c_HwStop(baseAddr);
            }
            else
            {
                /* End of transfer - disable and clear all status */
                Cdd_I2c_HwDisableAllIntr(baseAddr);
                Cdd_I2c_HwClearAllStatus(baseAddr);
                chResult     = CDD_I2C_CH_RESULT_OK;
                chObj->state = CDD_I2C_STATE_COMPLETE;
            }
        }
    }

    /* Check for transmit ready */
    if ((intrStatus & I2C_STR_XRDY) != 0U)
    {
        if (chObj->curLength < chObj->length)
        {
            /* Write the remaining data */
            Cdd_I2c_HwWriteData(baseAddr, *chObj->curTxBufPtr);
            chObj->curTxBufPtr++;
            chObj->curLength++;
        }

        if (chObj->curLength == chObj->length)
        {
            Cdd_I2c_HwDisableIntr(baseAddr, I2C_IER_XRDY);
        }
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoTransferRxPolling(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult  = CDD_I2C_CH_RESULT_PENDING;

    /* Read as long we have data */
    while (chObj->curLength < chObj->length)
    {
        chResult = Cdd_I2c_HwCheckForRxReady(baseAddr);
        if (CDD_I2C_CH_RESULT_OK == chResult)
        {
            chResult = CDD_I2C_CH_RESULT_PENDING;

            /* Read the data */
            *chObj->curRxBufPtr = Cdd_I2c_HwReadData(baseAddr);
            chObj->curRxBufPtr++;
            chObj->curLength++;
        }
        else
        {
            if (CDD_I2C_CH_RESULT_PENDING != chResult)
            {
                /* NACK or AL Errors - force stop */
                chObj->chErrorCode = chResult;
                chResult           = CDD_I2C_CH_RESULT_PENDING;
                chObj->state       = CDD_I2C_STATE_WAIT_FOR_STOP;
                Cdd_I2c_HwStop(baseAddr);
            }
            break;
        }
    }

    if ((chObj->chErrorCode == CDD_I2C_CH_RESULT_OK) && (chObj->curLength == chObj->length))
    {
        /* Generate stop if required */
        if (TRUE == chObj->isStopRequired)
        {
            chObj->state = CDD_I2C_STATE_WAIT_FOR_STOP;
            Cdd_I2c_HwStop(baseAddr);
        }
        else
        {
            Cdd_I2c_HwClearAllStatus(baseAddr);
            /* Use any error code that is already detected */
            chResult     = chObj->chErrorCode;
            chObj->state = CDD_I2C_STATE_COMPLETE;
        }
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoTransferRxIntr(Cdd_I2c_ChObjType *chObj, uint16 intrStatus)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult  = CDD_I2C_CH_RESULT_PENDING;

    if ((intrStatus & I2C_STR_RRDY) != 0U)
    {
        if (chObj->curLength < chObj->length)
        {
            /* Read the data */
            *chObj->curRxBufPtr = Cdd_I2c_HwReadData(baseAddr);
            chObj->curRxBufPtr++;
            chObj->curLength++;
        }

        if (chObj->curLength == chObj->length)
        {
            Cdd_I2c_HwDisableIntr(baseAddr, I2C_IER_RRDY);
            if (TRUE == chObj->isStopRequired)
            {
                chObj->state = CDD_I2C_STATE_WAIT_FOR_STOP;
                Cdd_I2c_HwStop(baseAddr);
            }
            else
            {
                /* End of transfer - disable and clear all status */
                Cdd_I2c_HwDisableAllIntr(baseAddr);
                Cdd_I2c_HwClearAllStatus(baseAddr);
                chResult     = CDD_I2C_CH_RESULT_OK;
                chObj->state = CDD_I2C_STATE_COMPLETE;
            }
        }
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoWaitForAccessReady(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult;

    chResult = Cdd_I2c_HwCheckForAccessReady(baseAddr);
    if (CDD_I2C_CH_RESULT_OK == chResult)
    {
        /* Generate stop if required or in case of error or if cancelled */
        if ((TRUE == chObj->isStopRequired) || (chObj->chErrorCode != CDD_I2C_CH_RESULT_OK) ||
            (TRUE == chObj->isCancelInProgress))
        {
            chResult     = CDD_I2C_CH_RESULT_PENDING;
            chObj->state = CDD_I2C_STATE_WAIT_FOR_STOP;
            Cdd_I2c_HwStop(baseAddr);
        }
        else
        {
            Cdd_I2c_HwClearAllStatus(baseAddr);
            /* Use any error code that is already detected */
            chResult     = chObj->chErrorCode;
            chObj->state = CDD_I2C_STATE_COMPLETE;
        }
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwStateDoWaitForStop(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult;

    chResult = Cdd_I2c_HwCheckForStop(baseAddr);
    if (CDD_I2C_CH_RESULT_OK == chResult)
    {
        Cdd_I2c_HwClearAllStatus(baseAddr);
        /* Use any error code that is already detected */
        chResult     = chObj->chErrorCode;
        chObj->state = CDD_I2C_STATE_COMPLETE;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForBusFree(uint32 baseAddr)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_PENDING;
    uint16                    intrStatus;

    intrStatus = Cdd_I2c_HwGetIntrStatus(baseAddr);
    if ((intrStatus & I2C_STR_BB) != I2C_STR_BB)
    {
        chResult = CDD_I2C_CH_RESULT_OK;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForBusBusy(uint32 baseAddr)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_PENDING;
    uint16                    intrStatus;

    intrStatus = Cdd_I2c_HwGetIntrStatus(baseAddr);
    if ((intrStatus & I2C_STR_BB) == I2C_STR_BB)
    {
        chResult = CDD_I2C_CH_RESULT_OK;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForTxReady(uint32 baseAddr)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_PENDING;
    Cdd_I2c_ChannelResultType chErrorCode;
    uint16                    intrStatus;

    intrStatus = Cdd_I2c_HwGetIntrStatus(baseAddr);
    if ((intrStatus & I2C_STR_XRDY) == I2C_STR_XRDY)
    {
        chResult = CDD_I2C_CH_RESULT_OK;
    }
    chErrorCode = Cdd_I2c_HwGetErrorCode(intrStatus, TRUE);
    if (chErrorCode != CDD_I2C_CH_RESULT_OK)
    {
        chResult = chErrorCode;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForRxReady(uint32 baseAddr)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_PENDING;
    Cdd_I2c_ChannelResultType chErrorCode;
    uint16                    intrStatus;

    intrStatus = Cdd_I2c_HwGetIntrStatus(baseAddr);
    if ((intrStatus & I2C_STR_RRDY) == I2C_STR_RRDY)
    {
        chResult = CDD_I2C_CH_RESULT_OK;
    }
    chErrorCode = Cdd_I2c_HwGetErrorCode(intrStatus, TRUE);
    if (chErrorCode != CDD_I2C_CH_RESULT_OK)
    {
        chResult = chErrorCode;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForAccessReady(uint32 baseAddr)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_PENDING;
    uint16                    intrStatus;

    intrStatus = Cdd_I2c_HwGetIntrStatus(baseAddr);
    if ((intrStatus & I2C_STR_ARDY) == I2C_STR_ARDY)
    {
        chResult = CDD_I2C_CH_RESULT_OK;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwCheckForStop(uint32 baseAddr)
{
    Cdd_I2c_ChannelResultType chResult = CDD_I2C_CH_RESULT_PENDING;
    uint16                    intrStatus;

    intrStatus = Cdd_I2c_HwGetIntrStatus(baseAddr);
    /* Wait for both stop to complete and bus to become free */
    if (((intrStatus & I2C_STR_SCD) == I2C_STR_SCD) && ((intrStatus & I2C_STR_BB) != I2C_STR_BB))
    {
        chResult = CDD_I2C_CH_RESULT_OK;
    }

    return chResult;
}

static Cdd_I2c_ChannelResultType Cdd_I2c_HwGetErrorCode(uint16 intrStatus, boolean checkStopStatus)
{
    Cdd_I2c_ChannelResultType chErrorCode = CDD_I2C_CH_RESULT_OK;

    /* TI_COVERAGE_GAP_START Arbitration loss error cannot be recreated in test environment */
    if ((intrStatus & I2C_STR_ARBL) != 0U)
    {
        chErrorCode = CDD_I2C_CH_RESULT_ARBFAIL;
    }
    /* TI_COVERAGE_GAP_STOP */
    if ((intrStatus & I2C_STR_NACK) != 0U)
    {
        chErrorCode = CDD_I2C_CH_RESULT_NACKFAIL;
    }
    /* TI_COVERAGE_GAP_START Address zero error cannot be recreated in test environment */
    if ((intrStatus & I2C_STR_AD0) != 0U)
    {
        chErrorCode = CDD_I2C_CH_RESULT_NOT_OK;
    }
    /* TI_COVERAGE_GAP_STOP */
    /* Check this only for polled mode as in intr mode
     * we use stop intr status for getting interrupt and handle
     * the transfer end */
    if (TRUE == checkStopStatus)
    {
        /* TI_COVERAGE_GAP_START Bus fail error cannot be recreated in test environment */
        if ((intrStatus & I2C_STR_SCD) != 0U)
        {
            chErrorCode = CDD_I2C_CH_RESULT_BUSFAIL;
        }
        /* TI_COVERAGE_GAP_STOP */
    }

    return chErrorCode;
}

static void Cdd_I2c_HwReset(uint32 baseAddr)
{
    Cdd_I2c_HwSetMode(baseAddr, I2C_MDR_IRS, 0U);
}

static void Cdd_I2c_HwEnableModule(uint32 baseAddr, uint8 mode)
{
    uint16 regVal;

    regVal = 0U;
    if (CDD_I2C_MODE_CONTROLLER == mode)
    {
        regVal |= I2C_MDR_CNT;
    }
    regVal                       |= I2C_MDR_FREE | I2C_MDR_IRS;
    HWREGH(baseAddr + I2C_O_MDR)  = regVal;
}

static void Cdd_I2c_HwStop(uint32 baseAddr)
{
    Cdd_I2c_HwSetMode(baseAddr, I2C_MDR_STP, I2C_MDR_STP);
}

void Cdd_I2c_HwEnableIntr(uint32 baseAddr, uint16 mask)
{
    uint16 regVal;

    regVal                        = HWREGH(baseAddr + I2C_O_IER);
    regVal                       |= mask;
    HWREGH(baseAddr + I2C_O_IER)  = regVal;
}

void Cdd_I2c_HwDisableIntr(uint32 baseAddr, uint16 mask)
{
    uint16 regVal;

    regVal                        = HWREGH(baseAddr + I2C_O_IER);
    regVal                       &= (uint16)~mask;
    HWREGH(baseAddr + I2C_O_IER)  = regVal;
}

static void Cdd_I2c_HwClearIntr(uint32 baseAddr, uint16 mask)
{
    /* STR needs to read before clearing without this restart is not working */
    volatile uint16 regVal;
    regVal = HWREGH(baseAddr + I2C_O_STR);
    (void)regVal;

    HWREGH(baseAddr + I2C_O_STR) = mask;
}

static uint16 Cdd_I2c_HwGetIntrStatus(uint32 baseAddr)
{
    return HWREGH(baseAddr + I2C_O_STR);
}

static void Cdd_I2c_HwSetOwnAddress(uint32 baseAddr, uint16 ownAddress)
{
    HWREGH(baseAddr + I2C_O_OAR) = ownAddress;
}

static void Cdd_I2c_HwSetSlaveAddress(uint32 baseAddr, Cdd_I2c_AddressType deviceAddress)
{
    HWREGH(baseAddr + I2C_O_TAR) = deviceAddress;
}

#define CDD_I2C_STOP_SEC_CODE
#include "Cdd_I2c_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Hw.c
 *********************************************************************************************************************/
