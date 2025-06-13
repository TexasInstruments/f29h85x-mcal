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
 *  File:       Cdd_Ipc_Priv.h
 *  Generator:  None
 *
 *  Description:   This file contains data structures and private function declarations of private
 *API's.
 *********************************************************************************************************************/
#ifndef CDD_IPC_PRIV_H
#define CDD_IPC_PRIV_H

/** \addtogroup CDD_IPC
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_ipc.h"
#include "hw_memmap.h"
#include "hw_types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** \brief Send to receive registers step */
#define CDD_IPC_SEND_TO_RCV_STEP (CPU1IPCRCV_BASE - CPU1IPCSEND_BASE)
/** \brief Set register address */
#define CDD_IPC_REG_SET(x) ((uint32)(x))
/** \brief Clear register address */
#define CDD_IPC_REG_CLR(x) ((uint32)(x) + 0x4U)
/** \brief Flag register address */
#define CDD_IPC_REG_FLG(x) ((uint32)(x) + 0x8U)
/** \brief Send command register address */
#define CDD_IPC_REG_SENDCOM(x) ((uint32)(x) + 0x10U)
/** \brief Send address register address */
#define CDD_IPC_REG_SENDADDR(x) ((uint32)(x) + 0x14U)
/** \brief Send data register address */
#define CDD_IPC_REG_SENDDATA(x) ((uint32)(x) + 0x18U)
/** \brief Status register address */
#define CDD_IPC_REG_STS(x) ((uint32)(x) + CDD_IPC_SEND_TO_RCV_STEP + 0U)
/** \brief Acknowledgement register address */
#define CDD_IPC_REG_ACK(x) ((uint32)(x) + CDD_IPC_SEND_TO_RCV_STEP + 0x4U)
/** \brief Receive command register address */
#define CDD_IPC_REG_RECVCOM(x) ((uint32)(x) + CDD_IPC_SEND_TO_RCV_STEP + 0x10U)
/** \brief Receive address register address */
#define CDD_IPC_REG_RECVADDR(x) ((uint32)(x) + CDD_IPC_SEND_TO_RCV_STEP + 0x14U)
/** \brief Receive data register address */
#define CDD_IPC_REG_RECVDATA(x) ((uint32)(x) + CDD_IPC_SEND_TO_RCV_STEP + 0x18U)

#define CDD_IPC_FLAG0 0x00000001U /*!< \brief   IPC FLAG 0 - Triggers interrupt */
#define CDD_IPC_FLAG1 0x00000002U /*!< \brief   IPC FLAG 1 - Indicates polling mode */
#define CDD_IPC_FLAG2                                                            \
    0x00000004U /*!< \brief   IPC FLAG 2 - Reserved for syncronization of CPUs \ \
                 */

/** \brief Macro to define the upper byte index that can be transmitted/received in command register
 */
#define CDD_IPC_COMMBYTE (4U)

/** \brief Macro to define the upper byte index that can be transmitted/received in address register
 */
#define CDD_IPC_ADDRBYTE (8U)

/** \brief Macro to define the upper byte index that can be transmitted/received in address register
 */
#define CDD_IPC_DATABYTE (12U)

/** \brief Macro to define the no of bytes that can be written to a command register */
#define CDD_IPC_COMMANDSIZE (4U)

/** \brief Macro to define the index of channel ID in flag register */
#define CDD_IPC_CHANNELINDEX (16U)

/** \brief Macro to define the index of length in flag register */
#define CDD_IPC_LENGTHINDEX (24U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
extern CONST(Cdd_Ipc_InstanceType, CDD_IPC__CONST) Cdd_Ipc_Sync_Instances[CDD_IPC_CORE_COUNT][CDD_IPC_CORE_COUNT];
/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/* Design: MCAL-30577 */
/** \brief Sets the configuration pointer
 *
 * \param[in]  ConfigPtr Configuration pointer
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_SetCfgObj(P2CONST(Cdd_Ipc_ConfigType, AUTOMATIC, CDD_IPC_CONST) ConfigPtr);

/* Design: MCAL-30578 */
/** \brief Synchronises two cores for inter process communication
 *
 * \param[in]  RemoteCore is the numeric ID of the remote core that needs to be synchronized
 * \pre None
 * \post None
 * \return Status of synchronization
 * \retval E_OK: Synchronization is successfull
 * \retval E_NOT_OK: Synchronization failed
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_Sync_Process(VAR(Cdd_Ipc_RemoteCoreType, AUTOMATIC) RemoteCore);

/* Design: MCAL-30579 */
/** \brief Requests the transmission of a PDU
 *
 * \param[in] ChannelId : When Cdd Ipc is integrated with Autosar Com stack, this parameter is a Pdu
 *identifier used to address the respective channel. When Cdd Ipc is not integrated with Autosar Com
 *stack, this parameter is a channel identifier used to address the respective channel.
 * \param[in] PduInfoPtr is the pointer to a struct of type PduInfoType containing the complete data
 *to be transmitted.
 * \pre None
 * \post None
 * \return Cdd_Ipc_Transmit request is accepted or not
 * \retval E_OK: Transmit request has been accepted.
 * \retval E_NOT_OK: Transmit request has not been accepted.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_Transmit_Priv(VAR(PduIdType, AUTOMATIC) ChannelId,
                      P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr);

/* Design: MCAL-30580 */
/** \brief Indicates a successful reception of a received Cdd Ipc Rx LPDU to the upper layer
 *
 * \param[in] Instance_Index is the index of the Rx instance in Cdd_Ipc_CfgPtr
 * \param[in] Channel_Index is the index of the Rx channel in Cdd_Ipc_CfgPtr
 * \param[in] PduInfoPtr Pointer to the received data and it's length
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_RxIndication(VAR(uint8, AUTOMATIC) Instance_Index, VAR(uint8, AUTOMATIC) Channel_Index,
                     P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr);

/* Design: MCAL-30581 */
/** \brief Returns the Rx polling status of the instance
 *
 * \param[in] Instance_Index is the index of the Rx instance in Cdd_Ipc_CfgPtr
 * \param[out] ChannelIndex is pointer to the channel index
 * \pre None
 * \post None
 * \return Rx status of the channel
 * \retval TRUE: Message is received in the instance
 * \retval FALSE: Message is not received in the instance
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_IPC_CODE)
Cdd_Ipc_GetChannelPollingStatus(VAR(uint8, AUTOMATIC) Instance_Index,
                                P2VAR(uint8, AUTOMATIC, CDD_IPC_APPL_DATA) ChannelIndex);

/* Design: MCAL-30582 */
/** \brief Copies the received data to the PduInfoPtr
 *
 * \param[in] Instance_Index is the index of the Rx instance in Cdd_Ipc_CfgPtr
 * \param[in] PduInfoPtr is the pointer to a struct of type PduInfoType where received data needs to
 *be copied
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_ReadChannelPriv(VAR(uint8, AUTOMATIC) Instance_Index,
                        P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr);

/* Design: MCAL-30583 */
/** \brief Copies the data to be transmitted from PduInfoPtr to command registers
 *
 * \param[in] Instance_Index is the index of the Rx instance in Cdd_Ipc_CfgPtr
 * \param[in] Channel_Index is the index of the Rx channel in Cdd_Ipc_CfgPtr
 * \param[in] PduInfoPtr is the pointer to a struct of type PduInfoType where received data needs to
 *be copied
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_WriteChannelPriv(VAR(uint8, AUTOMATIC) Instance_Index, VAR(uint8, AUTOMATIC) Channel_Index,
                         P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr);

/* Design: MCAL-30584 */
/** \brief Acknowledges the reception of a PDU
 *
 * \param[in] Instance is the Cdd Ipc Instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE) Cdd_Ipc_Acknowledge(VAR(Cdd_Ipc_InstanceType, AUTOMATIC) Instance);

/* Design: MCAL-30585 */
/** \brief Finds the Rx instance index and Rx channel index for the given instance
 *
 * \param[in] Instance is the Cdd Ipc Instance
 * \param[out] ChannelIndex is pointer the channel index
 * \param[out] InstanceIndex is pointer the instance index
 * \pre None
 * \post None
 * \return Rx channel is configured or not for the given instance and channel
 * \retval TRUE: Rx instance and channel are configured
 * \retval FALSE: Rx instance and channel are not configured
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_GetRxIdxPriv(VAR(Cdd_Ipc_InstanceType, AUTOMATIC) Instance, uint8* InstanceIndex, uint8* ChannelIndex);

/* Design: MCAL-30586 */
/** \brief Finds the Rx channel index for the given instance
 *
 * \param[in] Instance is the Cdd Ipc Instance
 * \param[out] ChannelIndex is pointer the channel index
 * \param[out] InstanceIndex is instance index
 * \pre None
 * \post None
 * \return Rx channel is configured or not for the given instance and channel
 * \retval TRUE: Rx channel is configured
 * \retval FALSE: Rx channel is not configured
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_GetRxChIdx(VAR(Cdd_Ipc_InstanceType, AUTOMATIC) Instance, uint8 InstanceIndex, uint8* ChannelIndex);

/* Design: MCAL-30587 */
/** \brief Finds the Tx instance index and Tx channel index for the given Pdu
 *
 * \param[in] ChannelId : Symbolic name of the Tx Pdu to be transmitted when Cdd_Ipc is integrated
 *with Com Stack. Symbolic name Tx channel when Cdd_Ipc is not integrated with Com Stack.
 * \param[out] ChannelIndex is pointer the channel index
 * \param[out] InstanceIndex is pointer the instance index
 * \pre None
 * \post None
 * \return Tx channel is configured or not for the given instance and channel
 * \retval TRUE: Tx instance and channel are configured for the Pdu
 * \retval FALSE: Tx instance and channel are not configured for the Pdu
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_GetTxIdxPriv(VAR(PduIdType, AUTOMATIC) ChannelId, uint8* InstanceIndex, uint8* ChannelIndex);

/* Design: MCAL-30588 */
/** \brief Invoked by the respective IPC instance ISR.
 *
 * This Interrupt function is invoked when a reception happens in an IPC instance in any of the
 *channel
 *
 * \param[in] Instance is the IPC instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE) Cdd_Ipc_ProcessIsr(VAR(Cdd_Ipc_InstanceType, AUTOMATIC) Instance);

/* Design: MCAL-30590 */
/** \brief Checks whether the TxPdu is valid or not
 *
 * \param[in] ChannelId : When Cdd Ipc is integrated with Autosar Com stack, this parameter is a Pdu
 *identifier used to address the respective channel. When Cdd Ipc is not integrated with Autosar Com
 *stack, this parameter is a channel identifier used to address the respective channel.
 * \pre None
 * \post None
 * \return Returns whether PDU is valid or not
 * \retval TRUE: PDU is valid
 * \retval FALSE: PDU is not valid
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_IPC_CODE) Cdd_Ipc_IsChannelIdValid(VAR(PduIdType, AUTOMATIC) ChannelId);

/* Design: MCAL-30589 */
/** \brief Returns the status of the instance that is configured for transmitting the PDU
 *
 * \param[in] ChannelId : When Cdd Ipc is integrated with Autosar Com stack, this parameter is a Pdu
 *identifier used to address the respective channel. When Cdd Ipc is not integrated with Autosar Com
 *stack, this parameter is a channel identifier used to address the respective channel.
 * \pre None
 * \post None
 * \return Status of the instance that is configured for transmitting the PDU
 * \retval TRUE: Tx channel is free
 * \retval FALSE: Tx channel is busy
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_IPC_CODE) Cdd_Ipc_InstanceStatus(VAR(PduIdType, AUTOMATIC) ChannelId);

/* Design: MCAL-30591 */
/** \brief Returns the timestamp counter value
 *
 * \param[in] None
 * \pre None
 * \post None
 * \return 64-bit timestamp counter value
 *
 *********************************************************************************************************************/
FUNC(uint64, CDD_IPC_CODE) Cdd_Ipc_ReadCounter(void);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* CDD_IPC_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Ipc_Priv.h
 *********************************************************************************************************************/
