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
 *  File:       Cdd_Uart_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains data structures and function declarations private to Cdd_Uart
 *
 *********************************************************************************************************************/
#ifndef CDD_UART_PRIV_H
#define CDD_UART_PRIV_H

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
#define CDD_UART_FIFO_DEPTH (16U)
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
    uint32                         Cdd_Uart_WriteCount;
    /**< Words written till now */
    uint32                         Cdd_Uart_CurrWriteCount;
} Cdd_Uart_WriteTransactionType;

/** \brief Typedef for the Read Transaction */
typedef struct Cdd_Uart_ReadTransactionTag
{
    /**< Read Buffer data pointer */
    Cdd_Uart_DataBufferType *Cdd_Uart_ReadBuf;
    /**< Number of Words to read */
    uint32                   Cdd_Uart_ReadCount;
    /**< Words read till now */
    uint32                   Cdd_Uart_CurrReadCount;
} Cdd_Uart_ReadTransactionType;

/**
 *  \brief UART driver object
 */
typedef struct Cdd_Uart_ObjectTag
{
    /**< UART HW unit configuration */
    const Cdd_Uart_CfgType       *Cdd_Uart_HwUnitCfg;
    /**< Write status object */
    Cdd_Uart_WriteTransactionType Cdd_Uart_WriteTransaction;
    /**< Read status object */
    Cdd_Uart_ReadTransactionType  Cdd_Uart_ReadTransaction;
    /**<Uart Error */
    /* RSR Register bit details
     * Bit 0 - FE: Frame Error
     * Bit 1 - PE: Parity Error
     * Bit 2 - BE: Break Error
     * Bit 3 - OE: OverRun Error
     */
    uint8                         Cdd_Uart_Error;
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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_SetObj(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_HwUnitInit(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_HwUnitDeinit(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_IsWriteBusy(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_IsReadBusy(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_PrivFlushReadFifo : Flush the read fifo.
 *
 * This service checks status of the CDD_UART driver
 *
 * \pre None.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE)
Cdd_Uart_PrivFlushReadFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_ConfigWriteTrans(P2VAR(Cdd_Uart_WriteTransactionType, AUTOMATIC, CDD_UART_APPL_DATA) UartWriteTrans,
                          P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) SrcBufferPtr, uint32 Count);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_ConfigReadTrans(P2VAR(Cdd_Uart_ReadTransactionType, AUTOMATIC, CDD_UART_APPL_DATA) UartReadTrans,
                         P2VAR(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) DestBufferPtr, uint32 Count);

/** \brief Cdd_Uart_PushWriteFifo : Pushes the data into FIFO until it is full or data count
 *exhausts.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE)
Cdd_Uart_PushWriteFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/** \brief Cdd_Uart_PullReadFifo : Pushes the data into FIFO until it is full or data count
 *exhausts.
 *
 * This service initialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE)
Cdd_Uart_PullReadFifo(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_CheckParam(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj,
                    P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) BufferPtr, uint32 Count);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_EnableWriteIntr(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj, boolean Enable);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_EnableReadIntr(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj, boolean Enable);

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
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_CheckReadErrors(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_WriteInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_ReadInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
FUNC(void, CDD_UART_CODE)
Cdd_Uart_ErrorInterruptHandler(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

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
#endif /* CDD_UART_PRIV_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Priv.h
 *********************************************************************************************************************/
