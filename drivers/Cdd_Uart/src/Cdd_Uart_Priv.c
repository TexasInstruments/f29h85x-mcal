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
 *  File:         Cdd_Uart_Priv.c
 *  Generator:    None
 *
 *  Description:  This file contains the UART MCAL driver private API's definitions specific to
 *device
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "hw_types.h"
#include "hw_uart.h"
#include "Cdd_Uart.h"
#include "Cdd_Uart_Priv.h"

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
 * Local Object Definitions
 *********************************************************************************************************************/

#define CDD_UART_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Uart_MemMap.h"
/* UART driver object */
P2VAR(Cdd_Uart_ObjectType, CDD_UART_VAR_INIT, CDD_UART_VAR_INIT) Cdd_Uart_ObjPtr = NULL_PTR;
#define CDD_UART_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Uart_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief This function will configure the UART control register.
 *
 * \param[in] UartHwUnitObj Pointer to UART HW unit object.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CDD_UART_CODE)
    Cdd_Uart_CfgCtl(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief This function will configure the UART buad rate divisors.
 *
 * \param[in] UartHwUnitObj Pointer to UART HW unit object.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CDD_UART_CODE)
    Cdd_Uart_CfgBrd(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief This function will configure the UART Line control register.
 *
 * \param[in] UartHwUnitObj Pointer to UART HW unit object.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CDD_UART_CODE)
    Cdd_Uart_CfgLineCtl(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief This function maps the Uart instance Id to HW unit Id.
 *
 * \param[in] UartInstId Uart Instance Id.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(uint8, CDD_UART_CODE) Cdd_Uart_GetHwUnitId(Cdd_Uart_Instance UartInstId);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

#define CDD_UART_START_SEC_CODE
#include "Cdd_Uart_MemMap.h"

FUNC(void, CDD_UART_CODE)
Cdd_Uart_SetObj(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    Cdd_Uart_ObjPtr = UartHwUnitObj;
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_HwUnitInit(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;

    /* Stop UART, disable Write and Read */
    HWREG(uartBaseAddr + UART_O_CTL) &= ~(UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE);

    /* Configure UART control */
    Cdd_Uart_CfgCtl(UartHwUnitObj);

    /* Configure UART baudrate */
    Cdd_Uart_CfgBrd(UartHwUnitObj);

    /*
     *  IMP - Make sure Line Control configuration is done after Baudrate configuration
     */
    /* Configure UART Line Control */
    Cdd_Uart_CfgLineCtl(UartHwUnitObj);

    /* Enable UART */
    HWREG(uartBaseAddr + UART_O_CTL) |= UART_CTL_UARTEN;
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_IsWriteBusy(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32         uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;
    uint32         fifoStatus   = HWREG(uartBaseAddr + UART_O_FR);
    Std_ReturnType rev_val      = E_OK;

    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_WriteEnable)
    {
        if ((NULL_PTR != UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_WriteBuf) ||
            (UART_FR_TXFE != (fifoStatus & UART_FR_TXFE)))
        {
            rev_val = E_NOT_OK;
        }
    }

    return rev_val;
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_IsReadBusy(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32         uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;
    uint32         fifoStatus   = HWREG(uartBaseAddr + UART_O_FR);
    Std_ReturnType rev_val      = E_OK;

    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ReadEnable)
    {
        if ((NULL_PTR != UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_ReadBuf) ||
            (UART_FR_RXFE != (fifoStatus & UART_FR_RXFE)))
        {
            rev_val = E_NOT_OK;
        }
    }

    return rev_val;
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_PrivFlushReadFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint8  depth        = 0U;
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;

    /* Flush the RX fifo */
    for (depth = 0U; depth < CDD_UART_FIFO_DEPTH; depth++)
    {
        (void)HWREGB(uartBaseAddr + UART_O_DR);
    }
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_HwUnitDeinit(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;

    /* Stop UART, disable Write and Read */
    HWREG(uartBaseAddr + UART_O_CTL) &= ~(UART_CTL_UARTEN | UART_CTL_TXE | UART_CTL_RXE);
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_ConfigWriteTrans(P2VAR(Cdd_Uart_WriteTransactionType, AUTOMATIC, CDD_UART_APPL_DATA) UartWriteTrans,
                          P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) SrcBufferPtr, uint32 Count)
{
    UartWriteTrans->Cdd_Uart_WriteBuf       = SrcBufferPtr;
    UartWriteTrans->Cdd_Uart_WriteCount     = Count;
    UartWriteTrans->Cdd_Uart_CurrWriteCount = 0U;
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_ConfigReadTrans(P2VAR(Cdd_Uart_ReadTransactionType, AUTOMATIC, CDD_UART_APPL_DATA) UartReadTrans,
                         P2VAR(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) DestBufferPtr, uint32 Count)
{
    UartReadTrans->Cdd_Uart_ReadBuf       = DestBufferPtr;
    UartReadTrans->Cdd_Uart_ReadCount     = Count;
    UartReadTrans->Cdd_Uart_CurrReadCount = 0U;
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_PushWriteFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint8                          depth        = 0U;
    uint32                         uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;
    const Cdd_Uart_DataBufferType *srcAddr      = UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_WriteBuf;

    /* Write bytes until Write fifo is FULL or write count is over */
    for (depth = 0U; depth < CDD_UART_FIFO_DEPTH; depth++)
    {
        if ((UART_FR_TXFF != (HWREG(uartBaseAddr + UART_O_FR) & UART_FR_TXFF)) &&
            (UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_CurrWriteCount <
             UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_WriteCount))
        {
            HWREGB(uartBaseAddr + UART_O_DR) =
                *(srcAddr + UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_CurrWriteCount);
            UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_CurrWriteCount++;
        }
        else
        {
            break;
        }
    }

    /* Check if all bytes written */
    if (UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_CurrWriteCount ==
        UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_WriteCount)
    {
        Cdd_Uart_ConfigWriteTrans(&UartHwUnitObj->Cdd_Uart_WriteTransaction, NULL_PTR, 0U);

        if (NULL_PTR != UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_WriteCompleteCb)
        {
            UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_WriteCompleteCb();
        }
    }
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_PullReadFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint8                    depth        = 0U;
    uint32                   uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;
    Cdd_Uart_DataBufferType *dstAddr      = UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_ReadBuf;

    /* Read bytes until Read fifo is EMPTY or read count is over */
    for (depth = 0U; depth < CDD_UART_FIFO_DEPTH; depth++)
    {
        if ((UART_FR_RXFE != (HWREG(uartBaseAddr + UART_O_FR) & UART_FR_RXFE)) &&
            (UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_CurrReadCount <
             UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_ReadCount))
        {
            *(dstAddr + UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_CurrReadCount) =
                HWREGB(uartBaseAddr + UART_O_DR);
            UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_CurrReadCount++;
        }
        else
        {
            break;
        }
    }

    /* Check if all bytes read */
    if (UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_CurrReadCount ==
        UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_ReadCount)
    {
        Cdd_Uart_ConfigReadTrans(&UartHwUnitObj->Cdd_Uart_ReadTransaction, NULL_PTR, 0U);

        if (NULL_PTR != UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ReadCompleteCb)
        {
            UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ReadCompleteCb();
        }
    }
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_CheckParam(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj,
                    P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) BufferPtr, uint32 Count)
{
    Std_ReturnType ret_value = E_OK;

    if ((NULL_PTR == UartHwUnitObj) || (NULL_PTR == BufferPtr) || (0U == Count))
    {
        ret_value = E_NOT_OK;
    }
    else if (NULL_PTR == UartHwUnitObj->Cdd_Uart_HwUnitCfg)
    {
        ret_value = E_NOT_OK;
    }
    else
    {
        /* Do nothing */
    }

    return ret_value;
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_EnableWriteIntr(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj, boolean Enable)
{
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;

    if (TRUE == Enable)
    {
        HWREG(uartBaseAddr + UART_O_IM) |= UART_IM_TXIM;
    }
    else
    {
        HWREG(uartBaseAddr + UART_O_IM) &= ~(UART_IM_TXIM);
    }
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_EnableReadIntr(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj, boolean Enable)
{
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;

    if (TRUE == Enable)
    {
        HWREG(uartBaseAddr + UART_O_IM) |=
            (UART_IM_RXIM | UART_IM_BEIM | UART_IM_FEIM | UART_IM_OEIM | UART_IM_PEIM | UART_IM_RTIM);
    }
    else
    {
        HWREG(uartBaseAddr + UART_O_IM) &=
            ~(UART_IM_RXIM | UART_IM_BEIM | UART_IM_FEIM | UART_IM_OEIM | UART_IM_PEIM | UART_IM_RTIM);
    }
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_CheckReadErrors(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32         uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;
    Std_ReturnType ret_value    = E_OK;
    uint8          errBits      = CDD_UART_NO_ERROR;
    uint32         readStatusReg;

    readStatusReg = HWREG(uartBaseAddr + UART_O_RSR);
    errBits       = (uint8)(readStatusReg & (UART_RSR_BE | UART_RSR_FE | UART_RSR_OE | UART_RSR_PE));

    if (0U != errBits)
    {
        /* Store the detected errors*/
        UartHwUnitObj->Cdd_Uart_Error = errBits;
        /*Return NOT OK if any error occurred*/
        ret_value = E_NOT_OK;
    }

    return ret_value;
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_WriteInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    if (NULL_PTR != UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_WriteBuf)
    {
        /* Push to Write fifo */
        Cdd_Uart_PushWriteFifo(UartHwUnitObj);
    }

    if (NULL_PTR == UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_WriteBuf)
    {
        /* Disable Write interrupt */
        Cdd_Uart_EnableWriteIntr(UartHwUnitObj, FALSE);
    }
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_ReadInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    if (NULL_PTR != UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_ReadBuf)
    {
        /* Pull from Read fifo */
        Cdd_Uart_PullReadFifo(UartHwUnitObj);
    }

    if (NULL_PTR == UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_ReadBuf)
    {
        /* Disable Read interrupt */
        Cdd_Uart_EnableReadIntr(UartHwUnitObj, FALSE);
    }
}

FUNC(void, CDD_UART_CODE)
Cdd_Uart_ErrorInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;

    /* Clear error status */
    HWREG(uartBaseAddr + UART_O_ECR) = 0xFFU;

    /* Cancel current read transaction  */
    Cdd_Uart_ConfigReadTrans(&UartHwUnitObj->Cdd_Uart_ReadTransaction, NULL_PTR, 0U);

    /* Disable Read interrupt */
    Cdd_Uart_EnableReadIntr(UartHwUnitObj, FALSE);

    /* Flush read fifo */
    Cdd_Uart_PrivFlushReadFifo(UartHwUnitObj);

    /* Error callback */
    if (NULL_PTR != UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ErrorCb)
    {
        UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ErrorCb();
    }
}

FUNC(void, CDD_UART_CODE) Cdd_Uart_ProcessISR(Cdd_Uart_Instance UartInstId)
{
    uint8                HwUnitId      = Cdd_Uart_GetHwUnitId(UartInstId);
    Cdd_Uart_ObjectType *UartHwUnitObj = &Cdd_Uart_ObjPtr[HwUnitId];
    uint32               uartBaseAddr  = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;
    uint32               uartIntStatus = HWREG(uartBaseAddr + UART_O_MIS);

    /* Clear interrupts */
    HWREG(uartBaseAddr + UART_O_ICR)         = uartIntStatus;
    HWREG(uartBaseAddr + UART_O_GLB_INT_CLR) = UART_GLB_INT_CLR_INT_FLG_CLR;

    /* Error interrupt */
    if (0U != (uartIntStatus & (UART_IM_FEIM | UART_IM_PEIM | UART_IM_BEIM | UART_IM_OEIM)))
    {
        /* Read the error to update the Errorstatus pointer */
        Cdd_Uart_CheckReadErrors(UartHwUnitObj);
        /* Error Handler */
        Cdd_Uart_ErrorInterruptHandler(UartHwUnitObj);
    }
    else if (0U != (uartIntStatus & (UART_MIS_RXMIS | UART_MIS_RTMIS)))
    {
        /* RX interrupt or read timeout */
        Cdd_Uart_ReadInterruptHandler(UartHwUnitObj);
    }
    else
    {
        /* Do nothing */
    }

    /* TX interrupt */
    if (UART_MIS_TXMIS == (uartIntStatus & UART_MIS_TXMIS))
    {
        Cdd_Uart_WriteInterruptHandler(UartHwUnitObj);
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static FUNC(void, CDD_UART_CODE)
    Cdd_Uart_CfgCtl(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;

    /* Enable Write */
    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_WriteEnable)
    {
        HWREG(uartBaseAddr + UART_O_CTL) |= UART_CTL_TXE;
    }

    /* Enable Read */
    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ReadEnable)
    {
        HWREG(uartBaseAddr + UART_O_CTL) |= UART_CTL_RXE;
    }

    /* Loopback Enable */
    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_LoopbackEnable)
    {
        HWREG(uartBaseAddr + UART_O_CTL) |= UART_CTL_LBE;
    }
    else
    {
        HWREG(uartBaseAddr + UART_O_CTL) &= ~(UART_CTL_LBE);
    }
}

static FUNC(void, CDD_UART_CODE)
    Cdd_Uart_CfgBrd(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;
    uint32 uartFbrDiv   = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaudRateCfg;

    /* Baudrate configuration */
    if (UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_HighSpeedEnable == TRUE)
    {
        /* Enable high speed mode */
        HWREG(uartBaseAddr + UART_O_CTL) |= UART_CTL_HSE;
    }
    else
    {
        /* Disable high speed mode */
        HWREG(uartBaseAddr + UART_O_CTL) &= ~(UART_CTL_HSE);
    }
    /*
     *  BRD = (IBRD + FBRD) = UartSysClk/(ClkDiv * BaudRate), ClkDiv = 16 if HSE = 0, ClkDiv = 8 if
     * HSE = 1 IBRD is 16 bits and FBRD is 6 bits 'uartFbrDiv' is fixed point with 6 binary points
     * hence it is multiplied by 64
     */

    HWREG(uartBaseAddr + UART_O_IBRD) = ((uartFbrDiv / 64U) << UART_IBRD_DIVINT_S) & UART_IBRD_DIVINT_M;
    HWREG(uartBaseAddr + UART_O_FBRD) = ((uartFbrDiv % 64U) << UART_FBRD_DIVFRAC_S) & UART_FBRD_DIVFRAC_M;
}

static FUNC(void, CDD_UART_CODE)
    Cdd_Uart_CfgLineCtl(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    uint32 uartBaseAddr = UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_BaseAddr;

    /* Fifo enable */
    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_FifoEnable)
    {
        /* Enable fifo */
        HWREG(uartBaseAddr + UART_O_LCRH) |= UART_LCRH_FEN;

        /* Write and Read fifo level */
        HWREG(uartBaseAddr + UART_O_IFLS) =
            ((((uint32)UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_WriteFifoLvl << UART_IFLS_TXIFLSEL_S) &
              UART_IFLS_TXIFLSEL_M) |
             (((uint32)UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ReadFifoLvl << UART_IFLS_RXIFLSEL_S) &
              UART_IFLS_RXIFLSEL_M));
    }
    else
    {
        /* Disable fifo */
        HWREG(uartBaseAddr + UART_O_LCRH) &= ~(UART_LCRH_FEN);
    }

    /* Configure parity */
    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ParityEnable)
    {
        HWREG(uartBaseAddr + UART_O_LCRH) |= UART_LCRH_PEN;
    }
    else
    {
        HWREG(uartBaseAddr + UART_O_LCRH) &= ~(UART_LCRH_PEN);
    }

    /* Word length */
    HWREG(uartBaseAddr + UART_O_LCRH) &= ~(UART_LCRH_WLEN_M);
    HWREG(uartBaseAddr + UART_O_LCRH) |=
        (((uint32)UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_WordLength << UART_LCRH_WLEN_S) & UART_LCRH_WLEN_M);

    /* Stop bits */
    if (CDD_UART_STOP_BITS_1 == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_StopBits)
    {
        HWREG(uartBaseAddr + UART_O_LCRH) &= ~(UART_LCRH_STP2);
    }
    else
    {
        HWREG(uartBaseAddr + UART_O_LCRH) |= UART_LCRH_STP2;
    }
}

static FUNC(uint8, CDD_UART_CODE) Cdd_Uart_GetHwUnitId(Cdd_Uart_Instance UartInstId)
{
    uint8                HwUnitId      = 0U;
    uint8                hwUnit        = 0U;
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;

    for (hwUnit = 0U; hwUnit < CDD_UART_MAX_NUM_HWUNIT; hwUnit++)
    {
        UartHwUnitObj = &Cdd_Uart_ObjPtr[hwUnit];

        if (UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_Instance == UartInstId)
        {
            HwUnitId = hwUnit;
            break;
        }
    }

    return HwUnitId;
}

#define CDD_UART_STOP_SEC_CODE
#include "Cdd_Uart_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Priv.c
 *********************************************************************************************************************/
