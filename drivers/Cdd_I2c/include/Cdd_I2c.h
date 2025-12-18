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
 *  File:       Cdd_I2c.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for CDD I2C MCAL
 *********************************************************************************************************************/
#ifndef CDD_I2C_H_
#define CDD_I2C_H_

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Cdd_I2c_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/**
 * \name CDD_I2C Driver Module SW Version Info
 *
 *  Defines for CDD_I2C Driver version used for compatibility checks
 *  @{
 */
/** \brief Driver Implementation Major Version */
#define CDD_I2C_SW_MAJOR_VERSION (1U)
/** \brief Driver Implementation Minor Version */
#define CDD_I2C_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version */
#define CDD_I2C_SW_PATCH_VERSION (0U)
/** @} */

/**
 * \name CDD_I2C Driver Module AUTOSAR Version Info
 *
 *  Defines for CDD_I2C Driver AUTOSAR version used for compatibility checks
 *  @{
 */
/** \brief AUTOSAR Major version specification implemented by CDD_I2C Driver*/
#define CDD_I2C_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor version specification implemented by CDD_I2C Driver*/
#define CDD_I2C_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_I2C Driver*/
#define CDD_I2C_AR_RELEASE_REVISION_VERSION (1U)
/** @} */

/**
 * \name CDD_I2C Driver ID Info
 *  @{
 */
/** \brief Texas Instruments Vendor ID */
#define CDD_I2C_VENDOR_ID ((uint16)44U)
/** \brief CDD_I2C Driver Module ID */
#define CDD_I2C_MODULE_ID ((uint16)255U)
/** \brief CDD_I2C Instance ID */
#define CDD_I2C_INSTANCE_ID ((uint8)0U)
/** @} */

/**
 * \name CDD_I2C Service Id
 *
 *  The Service Id is one of the argument to Det_ReportError function and is
 *  used to identify the source of the error
 *  @{
 */
/** \brief Service ID Cdd_I2c_Init() */
#define CDD_I2C_SID_INIT (0x00U)
/** \brief  Service ID Cdd_I2c_DeInit() */
#define CDD_I2C_SID_DEINIT (0x01U)
/** \brief Service ID Cdd_I2c_GetVersionInfo() */
#define CDD_I2C_SID_GET_VERSION_INFO (0x02U)
/** \brief Service ID Cdd_I2c_SetupEB() */
#define CDD_I2C_SID_SETUP_EB (0x03U)
/** \brief Service ID Cdd_I2c_SetupDynamicEB() */
#define CDD_I2C_SID_SETUP_EB_DYNAMIC (0x04U)
/** \brief Service ID Cdd_I2c_AsyncTransmit() */
#define CDD_I2C_SID_ASYNC_TRANSMIT (0x05U)
/** \brief Service ID Cdd_I2c_Cancel() */
#define CDD_I2C_SID_CANCEL (0x06U)
/** \brief Service ID Cdd_I2c_GetResult() */
#define CDD_I2C_SID_GET_RESULT (0x07U)
/** \brief Service ID Cdd_I2c_GetSequenceResult() */
#define CDD_I2C_SID_GET_SEQUENCE_RESULT (0x08U)
/** \brief Service ID Cdd_I2c_MainFunction() */
#define CDD_I2C_SID_MAIN_FUNCTION (0x09U)
/** \brief Service ID Cdd_I2c_PollingModeProcessing() */
#define CDD_I2C_SID_POLLING_MODE_PROCESSING (0x0AU)
/** \brief Service ID Cdd_I2c_GetStatus() */
#define CDD_I2C_SID_GET_STATUS (0x0BU)
/** @} */

/**
 * \name CDD_I2C Error Codes
 *
 *  Error codes returned by CDD_I2C functions
 *  @{
 */
/** \brief No errors */
#define CDD_I2C_E_NO_ERROR (0x00U)
/** \brief Error code for not initialized module */
#define CDD_I2C_E_UNINIT (0x01U)
/** \brief Init service called twice without deinit */
#define CDD_I2C_E_ALREADY_INITIALIZED (0x02U)
/** \brief Channel out of bounds, exceeds the maximum number of configured channels */
#define CDD_I2C_E_PARAM_CHANNEL (0x04U)
/** \brief Sequence out of bounds, exceeds the maximum number of configured sequences */
#define CDD_I2C_E_PARAM_SEQUENCE (0x05U)
/** \brief Length out of bounds – a zero length is not accepted */
#define CDD_I2C_E_PARAM_LENGTH (0x06U)
/** \brief An invalid version info pointer has been passed (a NULL_PTR) */
#define CDD_I2C_E_PARAM_VINFO_PTR (0x07U)
/** \brief An invalid configuration has been passed (a non NULL_PTR) */
#define CDD_I2C_E_PARAM_CONFIG (0x08U)
/** \brief Two in-valid transmission buffers have been passed (no NULL_PTR/ or both NULL_PTR) */
#define CDD_I2C_E_PARAM_TRANS_BUFFER (0x09U)
/** \brief Address out of bounds, exceeds the limit of the configured address range */
#define CDD_I2C_E_PARAM_ADDRESS (0x0AU)
/** \brief Buffer direction conflicts with channel direction set via EB */
#define CDD_I2C_E_PARAM_DIRECTION (0x0BU)
/** \brief API service called with invalid HW unit ID */
#define CDD_I2C_E_PARAM_HWUNIT (0x16U)
/** \brief API service called with sequence is busy */
#define CDD_I2C_E_SEQ_BUSY (0x17U)
/** @} */

/**
 * \name CDD_I2C Runtime Error Codes
 *
 *  Error codes returned by CDD_I2C functions at runtime via error callback
 *  Cdd_I2c_SequenceErrorNotification
 *  @{
 */
/** \brief Error is reported if NACK was received */
#define CDD_I2C_E_NACK_RECEIVED ((uint8)0x01U)
/** \brief Error is reported if the master loses arbitration.
 *  This usually happens if the SDA is stuck low or another master has won
 *  the arbitration procedure */
#define CDD_I2C_E_ARBITRATION_FAILURE ((uint8)0x02U)
/** \brief Error is reported if the SCL line is stuck low */
#define CDD_I2C_E_BUS_FAILURE ((uint8)0x03U)
/** @} */

/**
 *  \name CDD_I2C direction macros
 *
 *  @{
 */
/** \brief CDD_I2C direction - write */
#define CDD_I2C_WRITE ((Cdd_I2c_DirectionType)0U)
/** \brief CDD_I2C direction - read */
#define CDD_I2C_READ ((Cdd_I2c_DirectionType)1U)
/** @} */

/**
 *  \name I2C Address scheme macros
 *
 *  @{
 */
/** \brief 7 bit address */
#define CDD_I2C_ADDRESS_7_BIT (0x00U)
/** \brief 10 bit address */
#define CDD_I2C_ADDRESS_10_BIT (0x01U)
/** @} */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief This type defines the addresss size */
typedef uint16 Cdd_I2c_AddressType;

/** \brief This type defines the direction of operation - write or read */
typedef uint8 Cdd_I2c_DirectionType;

/** \brief This type defines the data to be transmitted using the CDD_I2C Driver */
typedef uint8 Cdd_I2c_DataType;

/** \brief Definition for the pointer type for general buffer handling */
typedef uint8* Cdd_I2c_DataPtrType;

/** \brief Definition for the pointer type for TX buffer handling */
typedef const uint8* Cdd_I2c_DataConstPtrType;

/** \brief Specifies the identification (ID) for a CDD_I2C Hardware unit */
typedef uint8 Cdd_I2c_HwUnitType;

/** \brief This is the type for a sequence identifier */
typedef uint8 Cdd_I2c_SequenceType;

/** \brief This is the type for a Ch identifier */
typedef uint8 Cdd_I2c_ChannelType;

/** \brief Type to define the number of data elements to be sent and/or received
 *  during a transmission */
typedef uint16 Cdd_I2c_DataLengthType;

/**
 * \brief This is an enum containing the possible HW unit states states.
 * The default HW unit state is CDD_I2C_HW_UNIT_FREE
 */
typedef enum
{
    /** \brief CDD_I2C Hardware unit not in use by a sequence */
    CDD_I2C_HW_UNIT_FREE,
    /** \brief CDD_I2C Hardware unit in use by a sequence */
    CDD_I2C_HW_UNIT_BUSY
} Cdd_I2c_HwUnitStatusType;

/**
 * \brief This is an enum containing the possible driver states.
 * The default driver state is CDD_I2C_UNINIT
 */
typedef enum
{
    /** \brief I2C driver is uninitialized */
    CDD_I2C_UNINIT,
    /** \brief I2C driver is idle */
    CDD_I2C_IDLE,
    /** \brief I2C driver is busy */
    CDD_I2C_BUSY
} Cdd_I2c_ComponentStatusType;

/**
 * \brief This is an enum containing the possible variants
 * of arbitration loss timeout handling
 */
typedef enum
{
    /** \brief In case bus is busy detach from I2C bus */
    CDD_I2C_BURST_MODE,
    /** \brief In case bus is busy try to recover I2C bus */
    CDD_I2C_RECURRENT_MODE
} Cdd_I2c_HandlingType;

/**
 * \brief  This is an enum containing all the possible channel results
 * The default channel state is CDD_I2C_CH_RESULT_OK.
 */
typedef enum
{
    /** \brief I2C channel transmission not in progress */
    CDD_I2C_CH_RESULT_OK,
    /** \brief I2C channel transmission is not OK */
    CDD_I2C_CH_RESULT_NOT_OK,
    /** \brief I2C channel transmission is in progress */
    CDD_I2C_CH_RESULT_PENDING,
    /** \brief I2C channel transmission failed due to bus unavailability */
    CDD_I2C_CH_RESULT_BUSFAIL,
    /** \brief I2C channel transmission failed due to arbitration loss */
    CDD_I2C_CH_RESULT_ARBFAIL,
    /** \brief I2C channel transmission failed due to bus NACK */
    CDD_I2C_CH_RESULT_NACKFAIL
} Cdd_I2c_ChannelResultType;

/**
 * \name I2C Sequence Status
 *
 *  This type defines a range of specific sequences status for the I2C Driver
 */
typedef enum
{
    /** \brief The last transmission of the Sequence has been finished successfully */
    CDD_I2C_SEQ_OK = 0x00U,
    /** \brief The I2C Driver is performing an I2C Sequence.
     *  The meaning of this status is equal to I2C_BUSY. */
    CDD_I2C_SEQ_PENDING = 0x01U,
    /** \brief An I2C Sequence is queued and waiting to be transmitted */
    CDD_I2C_SEQ_QUEUED = 0x02U,
    /** \brief An I2C Sequence encountered a NACK signal */
    CDD_I2C_SEQ_NACK = 0x03U,
    /** \brief The last transmission of the Sequence has failed */
    CDD_I2C_SEQ_FAILED = 0x04U,
    /** \brief I2C sequence transmission cancelled from queue */
    CDD_I2C_SEQ_CANCELLED = 0x05U,
    /** \brief I2C sequence transmission is not OK */
    CDD_I2C_SEQ_NOT_OK = 0x06U,
    /** \brief An I2C Sequence encountered a arbitration loss */
    CDD_I2C_SEQ_ARB = 0x07U
} Cdd_I2c_SequenceResultType;

/**
 * \brief This is an enum containing the possible restart modes.
 * The default mode is CDD_I2C_RESTART_MODE_NOSTOP
 */
typedef enum
{
    /** \brief CDD_I2C restart mode with stop at end of each transaction/channel write/read */
    CDD_I2C_RESTART_MODE_STOP,
    /** \brief CDD_I2C restart mode with no stop at end of each transaction/channel write/read,
     * by default there is start at begining of each transaction */
    CDD_I2C_RESTART_MODE_NOSTOP
} Cdd_I2c_RestartModeType;

/**
 * \brief Callback routine provided by the user for each Sequence to notify the
 * caller that a Sequence has been finished.
 */
typedef void (*Cdd_I2c_SequenceEndNotification)(void);

/**
 * \brief Callback routine provided by the user for each Sequence to notify the
 * caller that a Sequence has been finished with an error.
 *
 * \param[out] errorCode Sequence error code
 */
typedef void (*Cdd_I2c_SequenceErrorNotification)(uint8 errorCode);

/**
 * \brief CDD_I2C Hardware unit configuration structure
 */
typedef struct
{
    /** \brief CDD_I2C HW unit to use */
    Cdd_I2c_HwUnitType  hwUnitId;
    /** \brief The baud rate of the bus in bit/s */
    uint32              baudRate;
    /** \brief This unit is used set the I2c HW module frequency */
    uint32              hwUnitFrequency;
    /** \brief This element contains the system clock frequency being used by the I2c instance */
    uint32              sysClk;
    /** \brief Own address. Used in both 7 and 10-bit address mode.
     *  Note that the user can program the I2C own address to any value as long as it
     *  does not conflict with other components in the system */
    Cdd_I2c_AddressType ownAddress;
} Cdd_I2c_HwUnitConfigType;

/**
 * \brief CDD_I2C Channel configuration structure
 */
typedef struct
{
    /** \brief CDD_I2C Direction - write or read */
    Cdd_I2c_DirectionType direction;
    /** \brief The address of a target device which is accessed by the Controller */
    Cdd_I2c_AddressType   deviceAddress;
    /** \brief 7-bit or 10-bit addressing */
    uint8                 addressScheme;
} Cdd_I2c_ChConfigType;

/**
 * \brief CDD_I2C Sequence configuration structure
 */
typedef struct
{
    /** \brief This element points to which CDD_I2C hardware instance to use */
    Cdd_I2c_HwUnitType                hwUnitId;
    /** \brief The transmission end notification to inform the user that a
     * transmission request has been serviced */
    Cdd_I2c_SequenceEndNotification   completeNotify;
    /** \brief The transmission end notification to inform the user that a
     * transmission request has been serviced but with error */
    Cdd_I2c_SequenceErrorNotification errorNotify;
    /** \brief This element indicates the restart mode */
    Cdd_I2c_RestartModeType           restartMode;
    /** \brief Number of chs for this sequence.
     *   Should not be more than CDD_I2C_MAX_CH_PER_SEQ */
    uint32                            chPerSeq;
    /** \brief Channel index list */
    Cdd_I2c_ChannelType               chList[CDD_I2C_MAX_CH_PER_SEQ];
} Cdd_I2c_SequenceConfigType;

/**
 * \brief CDD_I2C config structure
 */
typedef struct Cdd_I2c_ConfigTag
{
    /** \brief HW Unit configurations */
    Cdd_I2c_HwUnitConfigType   hwUnitCfg[CDD_I2C_MAX_HW_UNIT];
    /** \brief Sequence configurations */
    Cdd_I2c_SequenceConfigType seqCfg[CDD_I2C_MAX_SEQ];
    /** \brief Ch configurations */
    Cdd_I2c_ChConfigType       chCfg[CDD_I2C_MAX_CH];
} Cdd_I2c_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/**
 * \brief Service for CDD_I2C initialization.
 *
 * Initialize the CDD_I2C hardware for each Cdd_I2cChannel using the Cdd_I2cHwUnitBaseAddress
 * and configure the Cdd_I2cBaudRate accordingly.
 *
 * Service ID[hex] - CDD_I2C_SID_INIT
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \param[in] configPtr Pointer to CDD_I2C Driver configuration set
 */
FUNC(void, CDD_I2C_CODE) Cdd_I2c_Init(const Cdd_I2c_ConfigType* configPtr);

/**
 * \brief Service for CDD_I2C driver de-initialization.
 *
 * CDD_I2C_DeInit de-initializes the CDD_I2C peripheral(s) into a Power On Reset state.
 *
 * Service ID[hex] - CDD_I2C_SID_DEINIT
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \return Std_ReturnType - E_OK: Success, E_NOT_OK: Request rejected
 */
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_DeInit(void);

#if (STD_ON == CDD_I2C_VERSION_INFO_API)
/**
 * \brief Service that returns the version information of the module.
 *
 * Service ID[hex] - CDD_I2C_SID_GET_VERSION_INFO
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \param[in] versionInfo Pointer to where to store the version information of this module
 */
FUNC(void, CDD_I2C_CODE) Cdd_I2c_GetVersionInfo(Std_VersionInfoType* versionInfo);
#endif

/**
 * \brief Service to setup the buffers and the length of data for the Ch specified.
 *
 * Service ID[hex] - CDD_I2C_SID_SETUP_EB
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \param[in] chId Channel to be used in the transmission
 * \param[in] txDataBufferPtr Pointer to the TX transmission data location
 * \param[in] rxDataBufferPtr Pointer to the RX transmission data location
 * \param[in] length Length (number of data elements) of the data to be transmitted
 *                   from TxDataBufferPtr and/or received from RxDataBufferPtr.
 *
 * \return Std_ReturnType - E_OK: Success, E_NOT_OK: Request rejected
 */
FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_SetupEB(Cdd_I2c_ChannelType chId, Cdd_I2c_DataConstPtrType txDataBufferPtr, Cdd_I2c_DataPtrType rxDataBufferPtr,
                Cdd_I2c_DataLengthType length);

/**
 * \brief Service to setup the buffers and the length of data for the Ch specified.
 *
 * Service ID[hex] - CDD_I2C_SID_SETUP_EB_DYNAMIC
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \param[in] chId Channel to be used in the transmission
 * \param[in] deviceAddress Any other value then zero will override the statically
 * configured device address.
 * \param[in] txDataBufferPtr Pointer to the TX transmission data location
 * \param[in] rxDataBufferPtr Pointer to the RX transmission data location
 * \param[in] length Length (number of data elements) of the data to be transmitted
 *                   from TxDataBufferPtr and/or received from RxDataBufferPtr.
 *
 * \return Std_ReturnType - E_OK: Success, E_NOT_OK: Request rejected
 */
FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_SetupEBDynamic(Cdd_I2c_ChannelType chId, Cdd_I2c_AddressType deviceAddress,
                       Cdd_I2c_DataConstPtrType txDataBufferPtr, Cdd_I2c_DataPtrType rxDataBufferPtr,
                       Cdd_I2c_DataLengthType length);

/**
 * \brief The service conducts an asynchronous data transmission according to the parameters
 * provided to the Cdd_I2c_SetupEB() service. The callback Cdd_I2c_SequenceErrorNotification()
 * is called, when the asynchronous operation has finished.
 *
 * Service ID[hex] - CDD_I2C_SID_ASYNC_TRANSMIT
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \param[in] sequenceId Sequence used for data exchange
 *
 * \return Std_ReturnType - E_OK: Success, E_NOT_OK: Request rejected
 */
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_AsyncTransmit(Cdd_I2c_SequenceType sequenceId);

#if (STD_ON == CDD_I2C_CANCEL_API)
/**
 * \brief Cancel a transmission
 *
 * A request that is already in transmission progress, is cancelled
 * by finishing the current sequence. This is done to achieve a stable
 * state with no undefined data. A queued transmission request is cancelled
 * at once.
 *
 * Service ID[hex] - CDD_I2C_SID_CANCEL
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \param[in] sequenceId Sequence to cancel
 *
 * \return Std_ReturnType - E_OK: Success, E_NOT_OK: Request rejected
 */
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_Cancel(Cdd_I2c_SequenceType sequenceId);
#endif

/**
 * \brief Makes a target channel available for processing requests (addressing).
 * When called, the target channel becomes available for starting incoming or
 * outgoing transfers.
 *
 * Service ID[hex] - CDD_I2C_SID_MAIN_FUNCTION
 * Sync/Async - Asynchronous
 * Reentrancy - Reentrant
 */
FUNC(void, CDD_I2C_CODE) Cdd_I2c_MainFunction(void);

/**
 * \brief Ensures proper processing of I2c communication in the case of
 * disabled interrupts.
 *
 * Service ID[hex] - CDD_I2C_SID_POLLING_MODE_PROCESSING
 * Sync/Async - Asynchronous
 * Reentrancy - Reentrant
 */
#if (STD_ON == CDD_I2C_POLLING_MODE)
FUNC(void, CDD_I2C_CODE) Cdd_I2c_PollingModeProcessing(void);
#endif

/**
 * \brief This service returns the current status of the given SequenceId.
 *
 * Service ID[hex] - CDD_I2C_SID_GET_SEQUENCE_RESULT
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \param[in] sequenceId Sequence to query
 *
 * \return CDD_I2C_SequenceResultType - Return the current status
 */
FUNC(Cdd_I2c_SequenceResultType, CDD_I2C_CODE) Cdd_I2c_GetSequenceResult(Cdd_I2c_SequenceType sequenceId);

/**
 * \brief This service returns the current status of the given channel.
 *
 * Service ID[hex] - CDD_I2C_SID_GET_RESULT
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \param[in] chId Channel to query
 *
 * \return Cdd_I2c_ChannelResultType - Return the current status
 */
FUNC(Cdd_I2c_ChannelResultType, CDD_I2C_CODE) Cdd_I2c_GetResult(Cdd_I2c_ChannelType chId);

#if (STD_ON == CDD_I2C_GET_STATUS_API)
/**
 * \brief This service returns the module's status
 *
 * Service ID[hex] - CDD_I2C_SID_GET_STATUS
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \return Cdd_I2c_ComponentStatusType - Return the current status
 */
FUNC(Cdd_I2c_ComponentStatusType, CDD_I2C_CODE) Cdd_I2c_GetStatus(void);
#endif

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CDD_I2C_H_ */
/*********************************************************************************************************************
 *  End of File: Cdd_I2c.h
 *********************************************************************************************************************/
