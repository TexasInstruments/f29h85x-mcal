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
 *  File:       Cdd_I2c.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for CDD I2C MCAL
 *********************************************************************************************************************/
#ifndef CDD_I2C_H_
#define CDD_I2C_H_

/**
 * \defgroup CDD_I2C Cdd I2c
 * @{
 */

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

/* Defines for CDD_I2C Driver version used for compatibility checks. */
/** \brief Driver Implementation Major Version */
#define CDD_I2C_SW_MAJOR_VERSION (1U)
/** \brief Driver Implementation Minor Version */
#define CDD_I2C_SW_MINOR_VERSION (2U)
/** \brief Driver Implementation Patch Version */
#define CDD_I2C_SW_PATCH_VERSION (0U)

/* Defines for CDD_I2C Driver AUTOSAR version used for compatibility checks. */
/** \brief AUTOSAR Major version specification implemented by CDD_I2C Driver*/
#define CDD_I2C_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor version specification implemented by CDD_I2C Driver*/
#define CDD_I2C_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_I2C Driver*/
#define CDD_I2C_AR_RELEASE_REVISION_VERSION (1U)

/* CDD_I2C Driver ID Info. */
/** \brief Texas Instruments Vendor ID */
#define CDD_I2C_VENDOR_ID ((uint16)44U)
/** \brief CDD_I2C Driver Module ID */
#define CDD_I2C_MODULE_ID ((uint16)255U)
/** \brief CDD_I2C Instance ID */
#define CDD_I2C_INSTANCE_ID ((uint8)0U)

/* The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error. */
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
/** \brief Service ID Cdd_I2c_TargetStart() */
#define CDD_I2C_SID_TARGET_START (0x0CU)
/** \brief Service ID Cdd_I2c_TargetStop() */
#define CDD_I2C_SID_TARGET_STOP (0x0DU)
/** \brief Service ID Cdd_I2c_TargetSubmitTxBuffer() */
#define CDD_I2C_SID_TARGET_SUBMIT_TX_BUF (0x0EU)
/** \brief Service ID Cdd_I2c_TargetSubmitRxBuffer() */
#define CDD_I2C_SID_TARGET_SUBMIT_RX_BUF (0x0FU)

/* Error codes returned by CDD_I2C functions. */
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
/** \brief API service called with invalid mode - controller or target */
#define CDD_I2C_E_PARAM_MODE (0x18U)

/* Error codes returned by CDD_I2C functions at runtime via error callback
 * Cdd_I2c_SequenceErrorNotification. */
/** \brief Error is reported if NACK was received */
#define CDD_I2C_E_NACK_RECEIVED ((uint8)0x01U)
/** \brief Error is reported if the master loses arbitration.
 *  This usually happens if the SDA is stuck low or another master has won
 *  the arbitration procedure */
#define CDD_I2C_E_ARBITRATION_FAILURE ((uint8)0x02U)
/** \brief Error is reported if the SCL line is stuck low */
#define CDD_I2C_E_BUS_FAILURE ((uint8)0x03U)
/** \brief Sequence cancelled */
#define CDD_I2C_E_CANCELLED ((uint8)0x04U)
/** \brief RX buffer overflow - applicable only in target mode */
#define CDD_I2C_E_RX_OVERFLOW ((uint8)0x05U)
/** \brief TX buffer underflow - applicable only in target mode */
#define CDD_I2C_E_TX_UNDERFLOW ((uint8)0x06U)
/** \brief No buffer submitted - applicable only in target mode */
#define CDD_I2C_E_NO_BUFFER ((uint8)0x07U)

/* CDD_I2C direction macros. */
/** \brief CDD_I2C direction - write */
#define CDD_I2C_WRITE ((Cdd_I2c_DirectionType)0U)
/** \brief CDD_I2C direction - read */
#define CDD_I2C_READ ((Cdd_I2c_DirectionType)1U)

/* I2C Address scheme macros. */
/** \brief 7 bit address */
#define CDD_I2C_ADDRESS_7_BIT (0x00U)
/** \brief 10 bit address */
#define CDD_I2C_ADDRESS_10_BIT (0x01U)

/* HW unit mode */
/** \brief HW unit operates as I2C controller (master) */
#define CDD_I2C_MODE_CONTROLLER (0U)
/** \brief HW unit operates as I2C target (slave) */
#define CDD_I2C_MODE_TARGET (1U)

/*
 * Target Rx/Tx notification status
 */
/* \brief This event is set in TX/RX completion when buffer is returned to user after it is full (RX) or empty (TX) */
#define CDD_I2C_TARGET_EVENT_TRANSFER_COMPLETE (0U)
/* \brief This event is set in TX/RX completion when STOP is detected */
#define CDD_I2C_TARGET_EVENT_STOP (1U)
/* \brief This event is set in error callback in TX/RX mode when driver doesn't have any buffer */
#define CDD_I2C_TARGET_EVENT_NO_BUFFER (2U)
/* \brief This event is set in error callback when TX underflows */
#define CDD_I2C_TARGET_EVENT_TX_UNDERFLOW (3U)
/* \brief This event is set in error callback when RX overflows */
#define CDD_I2C_TARGET_EVENT_RX_OVERFLOW (4U)
/* \brief This event is set in error callback when target received NACK from controller - typically in TX mode */
#define CDD_I2C_TARGET_EVENT_NACK (5U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

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
 * \brief This type defines a range of specific sequences status for the I2C Driver
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

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Service for CDD_I2C initialization.
 *
 * Initialize the CDD_I2C hardware for each Cdd_I2cChannel using the Cdd_I2cHwUnitBaseAddress
 * and configure the Cdd_I2cBaudRate accordingly.
 *
 * Note: This API is applicable for both controller and target mode.
 *
 * Service ID[hex] - CDD_I2C_SID_INIT
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \param[in] configPtr Pointer to CDD_I2C Driver configuration set
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_I2C_CODE) Cdd_I2c_Init(const Cdd_I2c_ConfigType* configPtr);

/** \brief Service for CDD_I2C driver de-initialization.
 *
 * CDD_I2C_DeInit de-initializes the CDD_I2C peripheral(s) into a Power On Reset state.
 *
 * Note: This API is applicable for both controller and target mode.
 *
 * Service ID[hex] - CDD_I2C_SID_DEINIT
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: Success
 * \retval E_NOT_OK: Request rejected
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_DeInit(void);

#if (STD_ON == CDD_I2C_VERSION_INFO_API)
/** \brief Service that returns the version information of the module.
 *
 * Note: This API is applicable for both controller and target mode.
 *
 * Service ID[hex] - CDD_I2C_SID_GET_VERSION_INFO
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \param[in] versionInfo Pointer to where to store the version information of this module
 * \pre This API is available only if CDD_I2C_VERSION_INFO_API is STD_ON
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_I2C_CODE) Cdd_I2c_GetVersionInfo(Std_VersionInfoType* versionInfo);
#endif

/** \brief Service to setup the buffers and the length of data for the Ch specified.
 *
 * Note: This API is applicable only for controller mode.
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
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: Success
 * \retval E_NOT_OK: Request rejected
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_SetupEB(Cdd_I2c_ChannelType chId, Cdd_I2c_DataConstPtrType txDataBufferPtr, Cdd_I2c_DataPtrType rxDataBufferPtr,
                Cdd_I2c_DataLengthType length);

/** \brief Service to setup the buffers and the length of data for the Ch specified.
 *
 * Note: This API is applicable only for controller mode.
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
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: Success
 * \retval E_NOT_OK: Request rejected
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_SetupEBDynamic(Cdd_I2c_ChannelType chId, Cdd_I2c_AddressType deviceAddress,
                       Cdd_I2c_DataConstPtrType txDataBufferPtr, Cdd_I2c_DataPtrType rxDataBufferPtr,
                       Cdd_I2c_DataLengthType length);

/** \brief The service conducts an asynchronous data transmission according to the parameters
 * provided to the Cdd_I2c_SetupEB() service. The callback Cdd_I2c_SequenceErrorNotification()
 * is called, when the asynchronous operation has finished.
 *
 * Note: This API is applicable only for controller mode.
 *
 * Service ID[hex] - CDD_I2C_SID_ASYNC_TRANSMIT
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \param[in] sequenceId Sequence used for data exchange
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: Success
 * \retval E_NOT_OK: Request rejected
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_AsyncTransmit(Cdd_I2c_SequenceType sequenceId);

#if (STD_ON == CDD_I2C_CANCEL_API)
/** \brief Cancel a transmission
 *
 * A request that is already in transmission progress, is cancelled
 * by finishing the current sequence. This is done to achieve a stable
 * state with no undefined data. A queued transmission request is cancelled
 * at once.
 *
 * Note: This API is applicable only for controller mode.
 *
 * Service ID[hex] - CDD_I2C_SID_CANCEL
 * Sync/Async - Synchronous
 * Reentrancy - Non Reentrant
 *
 * \param[in] sequenceId Sequence to cancel
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: Success
 * \retval E_NOT_OK: Request rejected
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_Cancel(Cdd_I2c_SequenceType sequenceId);
#endif

/** \brief Makes a target channel available for processing requests (addressing).
 * When called, the target channel becomes available for starting incoming or
 * outgoing transfers.
 *
 * Note: This API is applicable only for controller mode.
 *
 * Service ID[hex] - CDD_I2C_SID_MAIN_FUNCTION
 * Sync/Async - Asynchronous
 * Reentrancy - Reentrant
 *
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_I2C_CODE) Cdd_I2c_MainFunction(void);

/** \brief Ensures proper processing of I2c communication in the case of
 * disabled interrupts.
 *
 * Note: This API is applicable only for controller mode.
 *
 * Service ID[hex] - CDD_I2C_SID_POLLING_MODE_PROCESSING
 * Sync/Async - Asynchronous
 * Reentrancy - Reentrant
 *
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_I2C_CODE) Cdd_I2c_PollingModeProcessing(void);

/** \brief This service returns the current status of the given SequenceId.
 *
 * Note: This API is applicable only for controller mode.
 *
 * Service ID[hex] - CDD_I2C_SID_GET_SEQUENCE_RESULT
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \param[in] sequenceId Sequence to query
 * \pre None
 * \post None
 * \return CDD_I2C_SequenceResultType - Return the current status
 *********************************************************************************************************************/
FUNC(Cdd_I2c_SequenceResultType, CDD_I2C_CODE) Cdd_I2c_GetSequenceResult(Cdd_I2c_SequenceType sequenceId);

/** \brief This service returns the current status of the given channel.
 *
 * Note: This API is applicable only for controller mode.
 *
 * Service ID[hex] - CDD_I2C_SID_GET_RESULT
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \param[in] chId Channel to query
 * \pre None
 * \post None
 * \return Cdd_I2c_ChannelResultType - Return the current status
 *********************************************************************************************************************/
FUNC(Cdd_I2c_ChannelResultType, CDD_I2C_CODE) Cdd_I2c_GetResult(Cdd_I2c_ChannelType chId);

#if (STD_ON == CDD_I2C_GET_STATUS_API)
/** \brief This service returns the module's status
 *
 * Note: This API is applicable only for controller mode.
 *
 * Service ID[hex] - CDD_I2C_SID_GET_STATUS
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \pre None
 * \post None
 * \return Cdd_I2c_ComponentStatusType - Return the current status
 *********************************************************************************************************************/
FUNC(Cdd_I2c_ComponentStatusType, CDD_I2C_CODE) Cdd_I2c_GetStatus(void);
#endif

/*
 * Below APIs are applicable only for target mode
 */
/** \brief This service starts the target-mode for the provided HW unit ID
 *  This enables interrupts and targets will start responding to I2C events after this.
 *
 * Note: This API is applicable only for target mode.
 *
 * Service ID[hex] - CDD_I2C_SID_TARGET_START
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \param[in] hwUnitId I2C HW unit ID
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: Success
 * \retval E_NOT_OK: Request rejected
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_TargetStart(Cdd_I2c_HwUnitType hwUnitId);

/** \brief This service stops the target-mode for the provided HW unit ID.
 *  This disables interrupts and targets will not respond to I2C events after this.
 *
 * Note: This API is applicable only for target mode.
 *
 * Service ID[hex] - CDD_I2C_SID_TARGET_STOP
 * Sync/Async - Synchronous
 * Reentrancy - Reentrant
 *
 * \param[in] hwUnitId I2C HW unit ID
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: Success
 * \retval E_NOT_OK: Request rejected
 *********************************************************************************************************************/
/** \brief Stop all target-mode HW units -
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE) Cdd_I2c_TargetStop(Cdd_I2c_HwUnitType hwUnitId);

/** \brief Submit TX buffer - call before Start or in TX Notification callback to provide a new buffer to work with
 *
 * \param[in] hwUnitId I2C HW unit ID
 * \param[in] pTxBuffer Pointer to TX data buffer
 * \param[in] txBufferSize Size of TX data buffer in bytes
 *
 * \pre None
 * \post None
 * \return E_OK on success, E_NOT_OK on failure
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_TargetSubmitTxBuffer(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_DataConstPtrType pTxBuffer,
                             Cdd_I2c_DataLengthType txBufferSize);

/** \brief Submit RX buffer - call before Start or in RX Notification callback to provide a new buffer to work with
 *
 * \param[in] hwUnitId I2C HW unit ID
 * \param[in] pRxBuffer Pointer to RX data buffer
 * \param[in] rxBufferSize Size of RX data buffer in bytes
 *
 * \pre None
 * \post None
 * \return E_OK on success, E_NOT_OK on failure
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDD_I2C_CODE)
Cdd_I2c_TargetSubmitRxBuffer(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_DataPtrType pRxBuffer,
                             Cdd_I2c_DataLengthType rxBufferSize);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_I2C_H_ */
/*********************************************************************************************************************
 *  End of File: Cdd_I2c.h
 *********************************************************************************************************************/
