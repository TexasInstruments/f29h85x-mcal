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
 *  File:       Cdd_Uart_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains data structures and function declarations private to Cdd_Uart
 *
 *********************************************************************************************************************/
#ifndef CDD_UART_PRIV_H
#define CDD_UART_PRIV_H

/** \addtogroup CDD_UART
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "hw_uart.h"
#include "hw_memmap.h"
#include "hw_types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/** \brief UART fifo depth */
#define CDD_UART_FIFO_DEPTH             (16U)
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/** \brief Typedef for the Write Transaction */
typedef struct Cdd_Uart_WriteTransactionTag
{
    /**< Write Buffer data pointer */
    const Cdd_Uart_DataBufferType *Cdd_Uart_WriteBuf;
    /**< Number of Words to write */
    uint32                      Cdd_Uart_WriteCount;
    /**< Words written till now */
    uint32                      Cdd_Uart_CurrWriteCount;
} Cdd_Uart_WriteTransactionType;

/** \brief Typedef for the Read Transaction */
typedef struct Cdd_Uart_ReadTransactionTag
{
    /**< Read Buffer data pointer */
    Cdd_Uart_DataBufferType   *Cdd_Uart_ReadBuf;
    /**< Number of Words to read */
    uint32                  Cdd_Uart_ReadCount;
    /**< Words read till now */
    uint32                  Cdd_Uart_CurrReadCount;
} Cdd_Uart_ReadTransactionType;

/**
 *  \brief UART driver object
 */
typedef struct Cdd_Uart_ObjectTag
{
    /**< UART HW unit configuration */
    const Cdd_Uart_CfgType          *Cdd_Uart_HwUnitCfg;
    /**< Write status object */
    Cdd_Uart_WriteTransactionType   Cdd_Uart_WriteTransaction;
    /**< Read status object */
    Cdd_Uart_ReadTransactionType    Cdd_Uart_ReadTransaction;
} Cdd_Uart_ObjectType;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Cdd_Uart_SetObj : Initializes the UART Hardware Unit.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_SetObj(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_HwUnitInit : Initializes the UART Hardware Unit.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_HwUnitInit(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_HwUnitDeinit : DeInitializes the UART Hardware Unit.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_HwUnitDeinit(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_IsWriteBusy : checks the status of the UART Hardware TX Unit.
 *
 * This service checks status of the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE) Cdd_Uart_IsWriteBusy(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_IsReadBusy : checks the status of the UART Hardware RX Unit.
 *
 * This service checks status of the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE) Cdd_Uart_IsReadBusy(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_FlushReadFifo : Flush the read fifo.
 *
 * This service checks status of the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_FlushReadFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_ConfigWriteTrans : Reset the Write transaction structure.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_ConfigWriteTrans(
                                P2VAR(Cdd_Uart_WriteTransactionType, AUTOMATIC, CDD_UART_APPL_DATA) UartWriteTrans,
                                P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) SrcBufferPtr,
                                uint32 Count);

/** \brief Cdd_Uart_ConfigReadTrans : Reset the Read transaction structure.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_ConfigReadTrans(
                                P2VAR(Cdd_Uart_ReadTransactionType, AUTOMATIC, CDD_UART_APPL_DATA) UartReadTrans,
                                P2VAR(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) DestBufferPtr,
                                uint32 Count);

/** \brief Cdd_Uart_PushWriteFifo : Pushes the data into FIFO until it is full or data count exhausts.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_PushWriteFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_PullReadFifo : Pushes the data into FIFO until it is full or data count exhausts.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_PullReadFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_CheckParam : Check the UART write parameters.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE) Cdd_Uart_CheckParam(
                                            P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj,
                                            P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) BufferPtr,
                                            uint32 Count);

/** \brief Cdd_Uart_EnableWriteIntr : Enable or Disable UART Write interrupt.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_EnableWriteIntr(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj, boolean Enable);

/** \brief Cdd_Uart_EnableReadIntr : Enable or Disable UART Read interrupt.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_EnableReadIntr(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj, boolean Enable);

/** \brief Cdd_Uart_CheckReadErrors : Check for read errors.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE) Cdd_Uart_CheckReadErrors(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_WriteInterruptHandler : UART Write interrupt handler.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_WriteInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_ReadInterruptHandler : UART Read interrupt handler.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_ReadInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_ErrorInterruptHandler : UART Error interrupt handler.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_ErrorInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_ProcessISR : UART Interrupt handler.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_ProcessISR(Cdd_Uart_Instance UartInstId);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *
 *  Mark the end of the C bindings section for C++ compilers.
 *
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_UART_PRIV_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Priv.h
 *********************************************************************************************************************/
