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
static void Cdd_I2c_HwSetupClk(uint32 baseAddr, uint32 baudRate, uint32 hwUnitFrequency, uint32 sysClk);

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

static void Cdd_I2c_HwSetMode(uint32 baseAddr, uint16 ctrlMask, uint16 ctrlCmds);
static void Cdd_I2c_HwReset(uint32 baseAddr);
static void Cdd_I2c_HwEnableModule(uint32 baseAddr);
static void Cdd_I2c_HwStop(uint32 baseAddr);

static void   Cdd_I2c_HwEnableIntr(uint32 baseAddr, uint16 mask);
static void   Cdd_I2c_HwDisableIntr(uint32 baseAddr, uint16 mask);
static void   Cdd_I2c_HwClearIntr(uint32 baseAddr, uint16 mask);
static uint16 Cdd_I2c_HwGetIntrStatus(uint32 baseAddr);

static void  Cdd_I2c_HwSetOwnAddress(uint32 baseAddr, uint16 ownAddress);
static void  Cdd_I2c_HwSetSlaveAddress(uint32 baseAddr, Cdd_I2c_AddressType deviceAddress);
static void  Cdd_I2c_HwSetDataCount(uint32 baseAddr, uint16 length);
static void  Cdd_I2c_HwWriteData(uint32 baseAddr, uint8 data);
static uint8 Cdd_I2c_HwReadData(uint32 baseAddr);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

#define CDD_I2C_START_SEC_CODE
#include "Cdd_I2c_MemMap.h"

void Cdd_I2c_HwInit(uint32 baseAddr, uint32 baudRate, uint32 hwUnitFrequency, uint32 sysClk,
                    Cdd_I2c_AddressType ownAddress)
{
    Cdd_I2c_HwReset(baseAddr);

    /* Initialises I2C hardware unit for required baudrate */
    Cdd_I2c_HwSetupClk(baseAddr, baudRate, hwUnitFrequency, sysClk);

    /* Disable/clear all interrupts and enable the module */
    Cdd_I2c_HwDisableAllIntr(baseAddr);
    Cdd_I2c_HwClearAllStatus(baseAddr);
    Cdd_I2c_HwEnableModule(baseAddr);
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
        chResult = Cdd_I2c_HwStateDoTransferTxPolling(chObj);
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
        /* Read the remaining bytes */
        chResult = Cdd_I2c_HwStateDoTransferRxPolling(chObj);
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
        if (CDD_I2C_WRITE == chObj->chCfg->direction)
        {
            chResult = Cdd_I2c_HwStateDoTransferTxIntr(chObj, intrStatus);
        }
        else
        {
            chResult = Cdd_I2c_HwStateDoTransferRxIntr(chObj, intrStatus);
        }
    }

    return chResult;
}

void Cdd_I2c_HwCancelPolling(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult;

    /* Force stop only if the channel is started */
    if (chObj->state > CDD_I2C_STATE_SETUP)
    {
        // TODO: Implement timeout
        Cdd_I2c_HwStop(baseAddr);
        do
        {
            chResult = Cdd_I2c_HwStateDoWaitForStop(chObj);
        } while (chResult != CDD_I2C_CH_RESULT_OK);
    }

    return;
}

void Cdd_I2c_HwCancelIntr(Cdd_I2c_ChObjType *chObj)
{
    Cdd_I2c_HwUnitObjType    *hwUnitObj = chObj->hwUnitObj;
    uint32                    baseAddr  = hwUnitObj->baseAddr;
    Cdd_I2c_ChannelResultType chResult;

    /* Force stop only if the channel is started */
    if (chObj->state > CDD_I2C_STATE_SETUP)
    {
        /* Disable and clear all interrupts and perform stop from same context */
        Cdd_I2c_HwDisableAllIntr(baseAddr);
        Cdd_I2c_HwClearAllStatus(baseAddr);

        // TODO: Implement timeout
        Cdd_I2c_HwStop(baseAddr);
        do
        {
            chResult = Cdd_I2c_HwStateDoWaitForStop(chObj);
        } while (chResult != CDD_I2C_CH_RESULT_OK);
    }

    return;
}

void Cdd_I2c_HwDisableAllIntr(uint32 baseAddr)
{
    Cdd_I2c_HwDisableIntr(baseAddr, CDD_I2C_HW_INTR_ENABLE_MASK_ALL);
}

void Cdd_I2c_HwClearAllStatus(uint32 baseAddr)
{
    Cdd_I2c_HwClearIntr(baseAddr, CDD_I2C_HW_INTR_STATUS_MASK_ALL);
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

static void Cdd_I2c_HwSetupClk(uint32 baseAddr, uint32 baudRate, uint32 hwUnitFrequency, uint32 sysClk)
{
    uint16 preScaler;
    uint16 diff;
    uint16 divisor, clkh, clkl;
    uint32 hwUnitFrequencyActual;

    /* Calculate prescaler */
    preScaler                    = (uint16)((sysClk / hwUnitFrequency) - 1U);
    HWREGH(baseAddr + I2C_O_PSC) = preScaler;

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
        /* Generate stop if required or in case of error */
        if ((TRUE == chObj->isStopRequired) || (chObj->chErrorCode != CDD_I2C_CH_RESULT_OK))
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

    if ((intrStatus & I2C_STR_ARBL) != 0U)
    {
        chErrorCode = CDD_I2C_CH_RESULT_ARBFAIL;
    }
    if ((intrStatus & I2C_STR_NACK) != 0U)
    {
        chErrorCode = CDD_I2C_CH_RESULT_NACKFAIL;
    }
    if ((intrStatus & I2C_STR_AD0) != 0U)
    {
        chErrorCode = CDD_I2C_CH_RESULT_NOT_OK;
    }
    /* Check this only for polled mode as in intr mode
     * we use stop intr status for getting interrupt and handle
     * the transfer end */
    if (TRUE == checkStopStatus)
    {
        if ((intrStatus & I2C_STR_SCD) != 0U)
        {
            chErrorCode = CDD_I2C_CH_RESULT_BUSFAIL;
        }
    }

    return chErrorCode;
}

static void Cdd_I2c_HwSetMode(uint32 baseAddr, uint16 ctrlMask, uint16 ctrlCmds)
{
    uint16 regVal;

    regVal                        = HWREGH(baseAddr + I2C_O_MDR);
    regVal                       &= ~ctrlMask;
    regVal                       |= ctrlCmds;
    HWREGH(baseAddr + I2C_O_MDR)  = regVal;
}

static void Cdd_I2c_HwReset(uint32 baseAddr)
{
    Cdd_I2c_HwSetMode(baseAddr, I2C_MDR_IRS, 0U);
}

static void Cdd_I2c_HwEnableModule(uint32 baseAddr)
{
    uint16 regVal;

    regVal                       = I2C_MDR_CNT | I2C_MDR_FREE | I2C_MDR_IRS;
    HWREGH(baseAddr + I2C_O_MDR) = regVal;
}

static void Cdd_I2c_HwStop(uint32 baseAddr)
{
    Cdd_I2c_HwSetMode(baseAddr, I2C_MDR_STP, I2C_MDR_STP);
}

static void Cdd_I2c_HwEnableIntr(uint32 baseAddr, uint16 mask)
{
    uint16 regVal;

    regVal                        = HWREGH(baseAddr + I2C_O_IER);
    regVal                       |= mask;
    HWREGH(baseAddr + I2C_O_IER)  = regVal;
}

static void Cdd_I2c_HwDisableIntr(uint32 baseAddr, uint16 mask)
{
    uint16 regVal;

    regVal                        = HWREGH(baseAddr + I2C_O_IER);
    regVal                       &= (uint16)~mask;
    HWREGH(baseAddr + I2C_O_IER)  = regVal;
}

static void Cdd_I2c_HwClearIntr(uint32 baseAddr, uint16 mask)
{
    /* TODO: STR needs to read before clearing without this restart is not working */
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

static void Cdd_I2c_HwSetDataCount(uint32 baseAddr, uint16 length)
{
    HWREGH(baseAddr + I2C_O_CNT) = length;
}

static void Cdd_I2c_HwWriteData(uint32 baseAddr, uint8 data)
{
    HWREGH(baseAddr + I2C_O_DXR) = (uint8)data;
}

static uint8 Cdd_I2c_HwReadData(uint32 baseAddr)
{
    return (uint8)HWREGH(baseAddr + I2C_O_DRR);
}

#define CDD_I2C_STOP_SEC_CODE
#include "Cdd_I2c_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_Hw.c
 *********************************************************************************************************************/
