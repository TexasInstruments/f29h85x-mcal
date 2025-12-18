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
 *  File:       Cdd_Ipc
 *  Generator:  None
 *
 *  Description:  This file contains CDD IPC driver public API function declarations .
 *********************************************************************************************************************/
#ifndef CDD_IPC_H
#define CDD_IPC_H

/**
 * \defgroup CDD_IPC Cdd Ipc
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ipc_Cfg.h"
#include "ComStack_Types.h"
#include "Std_Types.h"
#if (STD_ON == CDD_IPC_INTEGRATION_WITH_ASR_COM_STACK_ENABLE)
#include "PduR.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/* Defines for CDD_IPC Driver version used for compatibility checks.*/
/** \brief Driver Implementation Major Version */
#define CDD_IPC_SW_MAJOR_VERSION (2U)
/** \brief Driver Implementation Minor Version */
#define CDD_IPC_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version */
#define CDD_IPC_SW_PATCH_VERSION (0U)

/*  Defines for CDD_IPC Driver AUTOSAR version used for compatibility checks. */
/** \brief AUTOSAR Major version specification implemented by CDD_IPC Driver*/
#define CDD_IPC_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor version specification implemented by CDD_IPC Driver*/
#define CDD_IPC_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_IPC Driver*/
#define CDD_IPC_AR_RELEASE_REVISION_VERSION (1U)

/* CDD IPC Driver ID Info. */
/** \brief Texas Instruments Vendor ID */
#define CDD_IPC_VENDOR_ID ((uint16)44U)
/** \brief CDD IPC Driver Module ID */
#define CDD_IPC_MODULE_ID ((uint16)255U)
/** \brief CDD IPC Instance ID */
#define CDD_IPC_INSTANCE_ID ((uint8)0U)

/* Error codes returned by Cdd Ipc functions. */
/* Design: MCAL-30518 */
#ifndef CDD_IPC_E_UNINIT
/** \brief API service used without module initialization */
#define CDD_IPC_E_UNINIT ((uint8)0x01U)
#endif

/* Design: MCAL-30519 */
#ifndef CDD_IPC_E_ALREADY_INITIALIZED
/** \brief API Cdd_Ipc_Init service called while the IPC driver has already been initialized */
#define CDD_IPC_E_ALREADY_INITIALIZED ((uint8)0x02U)
#endif

/* Design: MCAL-30520 */
#ifndef CDD_IPC_E_PARAM_VALUE
/** \brief  API service called with invalid parameter value */
#define CDD_IPC_E_PARAM_VALUE ((uint8)0x03U)
#endif

/* Design: MCAL-30521 */
#ifndef CDD_IPC_E_PARAM_POINTER
/** \brief  API service called with invalid data buffer pointer */
#define CDD_IPC_E_PARAM_POINTER ((uint8)0x04U)
#endif

/* Design: MCAL-30522 */
#ifndef CDD_IPC_E_INVALID_LENGTH
/** \brief  API service called with invalid data length */
#define CDD_IPC_E_INVALID_LENGTH ((uint8)0x05U)
#endif

/* The Service Id is one of the argument to Det_ReportError function and is used to identify the
 * source of the error. */
/** \brief Cdd_Ipc_GetVersionInfo() API Service ID */
#define CDD_IPC_SID_GET_VERSION_INFO ((uint8)0x00U)
/** \brief Cdd_Ipc_Init() API Service ID */
#define CDD_IPC_SID_INIT ((uint8)0x01U)
/** \brief Cdd_Ipc_Sync() API Service ID */
#define CDD_IPC_SID_SYNC ((uint8)0x02U)
/** \brief Cdd_Ipc_Transmit() API Service ID */
#define CDD_IPC_SID_TRANSMIT ((uint8)0x03U)
/** \brief Cdd_Ipc_MainFunction_Read() API Service ID */
#define CDD_IPC_SID_MAIN_FUNCTION_READ ((uint8)0x04U)
/** \brief Cdd_Ipc_IsTxInstanceFree() API Service ID */
#define CDD_IPC_IS_TX_INSTANCE_FREE ((uint8)0x05U)
/** \brief Cdd_Ipc_GetCounter() API Service ID */
#define CDD_IPC_SID_GET_COUNTER ((uint8)0x06U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/** \brief Bit mask for last 8 bits */
#define BIT_MASK_EIGHT 0xFFU
/** \brief Bit mask for last 4 bits */
#define BIT_MASK_FOUR 0x0FU
/** \brief Shift bits by 8 bits */
#define BIT_SHIFT_BY_8 8U
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/* Design: MCAL-30523 */
/** \brief  Notification callback function pointer. */
typedef void (*Cdd_Ipc_NotifyType)(const PduInfoType *PduInfoPtr);

/* Design: MCAL-30531 */
/** \brief IPC Tx channel config type */
typedef struct Cdd_Ipc_TxChannelConfigTag
{
    /** \brief  Tx channel ID specific to the instance */
    uint8                    Cdd_Ipc_ChannelID;
    /** \brief  Tx processing */
    Cdd_Ipc_TxProcessingType Cdd_Ipc_TxProcessing;
    /** \brief Cdd Ipc Handle ID */
    uint16                   Cdd_Ipc_HandleID;
} Cdd_Ipc_TxChannelConfigType;

/* Design: MCAL-30529 */
/** \brief IPC Tx instance config type */
typedef struct Cdd_Ipc_TxInstanceConfigTag
{
    /** \brief  Tx instance */
    Cdd_Ipc_InstanceType        Cdd_Ipc_TxInstance;
    /** \brief  No. of channels configured in the instance */
    uint8                       Cdd_Ipc_TxChannelCount;
    /** \brief IPC Tx channel configurations */
    Cdd_Ipc_TxChannelConfigType Cdd_Ipc_TxChannelConfig[CDD_IPC_TX_CHANNEL_COUNT];
} Cdd_Ipc_TxInstanceConfigType;

/* Design: MCAL-30532 */
/** \brief IPC Rx channel config type */
typedef struct Cdd_Ipc_RxChannelConfigTag
{
    /** \brief  Rx channel ID specific to the instance */
    uint8              Cdd_Ipc_ChannelID;
    /** \brief User call back function */
    Cdd_Ipc_NotifyType Cdd_Ipc_UserCallbackFunction;
    /** \brief Cdd Ipc Handle ID */
    uint16             Cdd_Ipc_HandleID;
#if (STD_ON == CDD_IPC_INTEGRATION_WITH_ASR_COM_STACK_ENABLE)
    /** \brief PduR PDU ID */
    uint16 Cdd_Ipc_PduID;
#endif
} Cdd_Ipc_RxChannelConfigType;

/* Design: MCAL-30530 */
/** \brief IPC Rx instance config type */
typedef struct Cdd_Ipc_RxInstanceConfigTag
{
    /** \brief  Rx instance */
    Cdd_Ipc_InstanceType        Cdd_Ipc_RxInstance;
    /** \brief  No. of channels configured in the instance */
    uint8                       Cdd_Ipc_RxChannelCount;
    /** \brief IPC Rx channel configurations */
    Cdd_Ipc_RxChannelConfigType Cdd_Ipc_RxChannelConfig[CDD_IPC_RX_CHANNEL_COUNT];
} Cdd_Ipc_RxInstanceConfigType;

/* Design: MCAL-30528 */
/** \brief IPC config type */
typedef struct Cdd_Ipc_ConfigTag
{
    /** \brief  Local core in the IPC communication */
    Cdd_Ipc_CoreType             Cdd_Ipc_LocalCore;
    /** \brief  Tx instance configurations */
    Cdd_Ipc_TxInstanceConfigType Cdd_Ipc_TxInstanceConfig[CDD_IPC_TX_INSTANCE_COUNT];
    /** \brief  Rx instance configurations */
    Cdd_Ipc_RxInstanceConfigType Cdd_Ipc_RxInstanceConfig[CDD_IPC_RX_INSTANCE_COUNT];
} Cdd_Ipc_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

#if (STD_ON == CDD_IPC_GET_VERSION_INFO_API)
/* Design: MCAL-30500, MCAL-30501 */
/** \brief Service to provide the version information of Cdd Ipc module
 *
 * \param[out] VersionInfoPtr is the pointer to CDD IPC driver version information.
 * \pre This API is available only if CDD_IPC_GET_VERSION_INFO_API is STD_ON
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_IPC_APPL_DATA) VersionInfoPtr);
#endif /* CDD_IPC_GET_VERSION_INFO_API */

/* Design: MCAL-30502, MCAL-30503, MCAL-30504, MCAL-30505 */
/** \brief Service to initialize CDD IPC driver.
 *
 * \param[in] ConfigPtr is the configuration pointer pointing to a generated configuration variant
 *from plugin
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_Init(P2CONST(Cdd_Ipc_ConfigType, AUTOMATIC, CDD_IPC_CONFIG_DATA) ConfigPtr);

/* Design: MCAL-30506, MCAL-30507, MCAL-30508 */
/** \brief Service to synchronise two cores communicating in IPC communication within a
 *preconfigured timeout.
 *
 * \param[in] RemoteCore is the symbolic name of the remote core that needs to be synchronized with.
 * \pre None
 * \post None
 * \return Status of synchronization.
 * \retval E_OK: Synchronization is successful.
 * \retval E_NOT_OK: Synchronization failed.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_Sync(VAR(Cdd_Ipc_CoreType, AUTOMATIC) RemoteCore);

/* Design: MCAL-30509, MCAL-30510, MCAL-30511, MCAL-30512 */
/** \brief Service to request transmission
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
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_Transmit(VAR(PduIdType, AUTOMATIC) ChannelId, P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr);

/* Design: MCAL-30513 */
/** \brief Service to perform the polling of confgured IPC Rx instances
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_IPC_CODE) Cdd_Ipc_MainFunction_Read(void);

/* Design: MCAL-30514, MCAL-30515, MCAL-30516 */
/** \brief Service to check the status of the instance that is configured for
 *         transmitting the message in the respective channel
 *
 * \param[in] ChannelId : When Cdd Ipc is integrated with Autosar Com stack, this parameter is a Pdu
 *identifier used to address the respective channel. When Cdd Ipc is not integrated with Autosar Com
 *stack, this parameter is a channel identifier used to address the respective channel.
 * \pre None
 * \post None
 * \return IPC instance configured for transmitting the PDU is busy or not
 * \retval TRUE: Instance is free
 * \retval FALSE: Instance is busy
 *****************************************************************************/
FUNC(boolean, CDD_IPC_CODE) Cdd_Ipc_IsTxInstanceFree(VAR(PduIdType, AUTOMATIC) ChannelId);

/* Design: MCAL-30517 */
/** \brief Service to read the timestamp counter value.
 *
 * \pre None
 * \post None
 * \return 64-bit timestamp counter value
 *********************************************************************************************************************/
FUNC(uint64, CDD_IPC_CODE) Cdd_Ipc_GetCounter(void);
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*None*/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_IPC_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Ipc.h
 *********************************************************************************************************************/
