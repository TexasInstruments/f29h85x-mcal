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
 *  File:       Spi.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Spi Driver functions
 *
 *********************************************************************************************************************/
#ifndef SPI_H
#define SPI_H
/**
 * \defgroup SPI Spi API GUIDE Header file
 * @{
 */
/*********************************************************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 *********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Spi_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/* Defines for SPI Driver version used for compatibility checks. */
/** \brief Driver Implementation Major Version. */
#define SPI_SW_MAJOR_VERSION (1U)
/** \brief Driver Implementation Minor Version. */
#define SPI_SW_MINOR_VERSION (1U)
/** \brief Driver Implementation Patch Version. */
#define SPI_SW_PATCH_VERSION (1U)

/* Defines for SPI Driver AUTOSAR version used for compatibility checks. */
/** \brief AUTOSAR major version specification implemented by SPI Driver. */
#define SPI_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR minor version specification implemented by SPI Driver. */
#define SPI_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR patch version specification implemented by SPI Driver. */
#define SPI_AR_RELEASE_PATCH_VERSION (1U)

/* SPI Driver ID Info. */
/** \brief Texas Instruments Vendor ID. */
#define SPI_VENDOR_ID ((uint16)44U)
/** \brief SPI Driver Module ID. */
#define SPI_MODULE_ID ((uint16)83U)
/** \brief SPI Driver Instance ID */
#define SPI_INSTANCE_ID ((uint8)0U)

/* SPI Buffer Definition */
/**  \brief Buffer definitions IB - internal buffers */
#define SPI_IB (0U)
/**  \brief Buffer definitions EB - external buffers. Only this is supported */
#define SPI_EB (1U)
/**  \brief Buffer definitions IB/EB - internal/external buffers */
#define SPI_IB_EB (2U)

/** \brief SPI Error Codes. Error codes returned by SPI functions */
#ifndef SPI_E_PARAM_CHANNEL
/*
 * Design : MCAL-24924, MCAL-24937
 */
/** \brief API service called with wrong parameter */
#define SPI_E_PARAM_CHANNEL ((uint8)0x0AU)
#endif

#ifndef SPI_E_PARAM_JOB
/*
 * Design : MCAL-24925
 */
/** \brief API service called with wrong parameter */
#define SPI_E_PARAM_JOB ((uint8)0x0BU)
#endif

#ifndef SPI_E_PARAM_SEQ
/*
 * Design : MCAL-24926
 */
/** \brief API service called with wrong parameter */
#define SPI_E_PARAM_SEQ ((uint8)0x0CU)
#endif

#ifndef SPI_E_PARAM_LENGTH
/*
 * Design : MCAL-24927
 */
/** \brief API service called with wrong parameter */
#define SPI_E_PARAM_LENGTH ((uint8)0x0DU)
#endif

#ifndef SPI_E_PARAM_UNIT
/*
 * Design :  MCAL-24928
 */
/** \brief API service called with wrong parameter */
#define SPI_E_PARAM_UNIT ((uint8)0x0EU)
#endif

#ifndef SPI_E_PARAM_POINTER
/** \brief APIs called with a Null Pointer */
#define SPI_E_PARAM_POINTER ((uint8)0x10U)
#endif

#ifndef SPI_E_UNINIT
/*
 * Design : MCAL-24929
 */
/** \brief API service used without module initialization */
#define SPI_E_UNINIT ((uint8)0x1AU)
#endif

#ifndef SPI_E_SEQ_PENDING
/*
 * Design : MCAL-24930
 */
/** \brief Services called in a wrong sequence */
#define SPI_E_SEQ_PENDING ((uint8)0x2AU)
#endif

#ifndef SPI_E_SEQ_IN_PROCESS
/*
 * Design : MCAL-24931
 */
/** \brief Synchronous transmission service called at wrong time */
#define SPI_E_SEQ_IN_PROCESS ((uint8)0x3AU)
#endif

#ifndef SPI_E_ALREADY_INITIALIZED
/*
 * Design : MCAL-24932
 */
/**
 *  \brief API Spi_Init service called while the SPI driver has
 *   already been initialized
 */
#define SPI_E_ALREADY_INITIALIZED ((uint8)0x4AU)
#endif

#ifndef SPI_E_SEQ_TIMEOUT
/*
 * Design : MCAL-28864
 */
/** \brief sequence transmission failed with a timeout  */

#define SPI_E_SEQ_TIMEOUT ((uint8)0x5AU)
#endif

/**
 *  \name SPI Service Ids
 *
 *  The Service Id is one of the argument to Det_ReportError function
 and is used to identify the source of the error
 */
/** \brief Spi_Init() API Service ID */
#define SPI_SID_INIT ((uint8)0x00U)
/** \brief Spi_DeInit() API Service ID */
#define SPI_SID_DEINIT ((uint8)0x01U)
/** \brief Spi_WriteIB() API Service ID */
#define SPI_SID_WRITE_IB ((uint8)0x02U)
/** \brief Spi_AsyncTransmit() API Service ID */
#define SPI_SID_ASYNC_TRANSMIT ((uint8)0x03U)
/** \brief Spi_ReadIB() API Service ID */
#define SPI_SID_READ_IB ((uint8)0x04U)
/** \brief Spi_SetupEB() API Service ID */
#define SPI_SID_SETUP_EB ((uint8)0x05U)
/** \brief Spi_GetStatus() API Service ID */
#define SPI_SID_GET_STATUS ((uint8)0x06U)
/** \brief Spi_GetJobResult() API Service ID */
#define SPI_SID_GET_JOB_RESULT ((uint8)0x07U)
/** \brief Spi_GetSequenceResult() API Service ID */
#define SPI_SID_GET_SEQ_RESULT ((uint8)0x08U)
/** \brief Spi_GetVersionInfo() API Service ID */
#define SPI_SID_GET_VERSION_INFO ((uint8)0x09U)
/** \brief Spi_SyncTransmit() API Service ID */
#define SPI_SID_SYNC_TRANSMIT ((uint8)0x0AU)
/** \brief Spi_GetHWUnitStatus() API Service ID */
#define SPI_SID_GET_HW_UNIT_STATUS ((uint8)0x0BU)
/** \brief Spi_Cancel() API Service ID */
#define SPI_SID_CANCEL ((uint8)0x0CU)
/** \brief Spi_SetAsyncMode() API Service ID */
#define SPI_SID_SET_ASYNC_MODE ((uint8)0x0DU)
/** \brief Spi_MainFunction_Handling() API Service ID */
#define SPI_SID_MAINFUNCTION_HANDLING ((uint8)0x10U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Spi_Init : Service for SPI initialization.
 *
 * This service initializes all the configured Spi channels, jobs, sequences and SPI instances This
 *will set the state of SPI driver to Initialized.
 *
 * \param[in] CfgPtr - Pointer to configuration set
 * \pre CfgPtr shall be null in Pre-Compile variant, Link-Time variant and shall not be NULL in
 *Post-Build variant
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_CONFIG_DATA) CfgPtr);

/** \brief Spi_DeInit : Service for SPI de-initialization.
 *
 * This service de-initializes all the configured Spi channels, jobs, sequences and SPI instances
 *This will set the state of SPI driver to Un-Initialized.
 *
 * \pre None
 * \post None
 * \return returns whether the de-init command is accepted or not.
 * \retval E_OK:     de-initialisation command has been accepted
 * \retval E_NOT_OK: de-initialisation command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void);

/** \brief Spi_GetStatus: Service returns the SPI Handler/Driver software module status.
 *
 * Service returns the SPI Handler/Driver software module status.
 *
 * \pre None
 * \post None
 * \return returns SPI driver status
 * \retval SPI_UNINIT: The SPI Handler/Driver is not initialized or not usable
 * \retval SPI_IDLE  : The SPI Handler/Driver is not currently transmitting any Job
 * \retval SPI_BUSY  : The SPI Handler/Driver is performing a SPI Job (transmit)
 *
 *********************************************************************************************************************/
FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void);
/** \brief Spi_GetStatus: Service is to get the result of a specified job
 *
 * Service is to get the result of a specified job(queued, pending, failed, success)
 *
 * \param[in] Job: job Id
 * \pre None
 * \post None
 * \return returns the status of a job
 * \retval SPI_JOB_OK: The last transmission of the Job has been finished successfully
 * \retval SPI_JOB_PENDING: The SPI Handler/Driver is performing a SPI Job.
 * \retval SPI_JOB_FAILED: The last transmission of the Job has failed
 * \retval SPI_JOB_QUEUED: An asynchronous transmit Job has been accepted, while
 *                         actual transmission for this Job has not started yet
 *
 *********************************************************************************************************************/
FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult(VAR(Spi_JobType, AUTOMATIC) Job);

/** \brief Spi_GetSequenceResult: Service
 *
 * Service is to return the status of a specified sequence
 *
 * \param[in] Sequence: sequence ID
 * \pre None
 * \post None
 * \return returns the status of a sequence
 * \retval SPI_SEQ_OK: The last transmission of the Sequence has been finished
 *                     successfully
 * \retval SPI_SEQ_PENDING: The SPI Handler/Driver is performing a SPI Sequence.
 *                          The meaning of this status is equal to SPI_BUSY
 * \retval SPI_SEQ_FAILED: The last transmission of the Sequence has failed
 * \retval SPI_SEQ_CANCELLED: The last transmission of the Sequence has been canceled by user
 *
 *********************************************************************************************************************/
FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(VAR(Spi_SequenceType, AUTOMATIC) Sequence);

#if (STD_ON == SPI_VERSION_INFO_API)
/** \brief Service to get the version information of the module.
 *
 * This service writes the version information of this module into the data
 * structure referenced by the parameter. If this parameter references
 * NULL_PTR, a development error is reported to Det. This service is only
 * available if the pre-compile configuration parameter SPI_VERSION_INFO_API
 * is enabled.
 *
 * \param[out] Versioninfo structure that contains the version information parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, SPI_CODE)
Spi_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo);
#endif /* #if (STD_ON == SPI_VERSION_INFO_API) */

#if (STD_ON == SPI_HW_STATUS_API)
/** \brief Spi_GetHWUnitStatus: Service to get the status of the SPI hardware unit
 *
 * This service returns the status of the specified SPI Hardware micro-controller peripheral.
 *
 * \param[in] HWUnit: SPI Hardware micro-controller peripheral (unit) ID.
 * \pre None
 * \post None
 * \return returns the status of the specified SPI HW unit
 * \retval SPI_UNINIT: The SPI HW unit is not initialized or not usable
 * \retval SPI_IDLE  : The SPI HW unit is not currently transmitting any Job
 * \retval SPI_BUSY  : The SPI HW unit is performing a SPI Job (transmit)
 *
 *********************************************************************************************************************/
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(VAR(Spi_HWUnitType, AUTOMATIC) HWUnit);
#endif /* #if (STD_ON == SPI_HW_STATUS_API) */

#if ((SPI_CHANNEL_BUFFERS == SPI_IB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))

/** \brief Spi_WriteIB: Service for writing one or more data to an IB SPI Handler/Driver
 * Channel specified by parameter.
 *
 * Service for writing one or more data to an IB SPI Handler/Driver Channel specified
 * by parameter.
 *
 * \param[in] Channel: Channel ID.
 * \param[in] DataBufferPtr: Pointer to source data buffer. If this pointer is null, it is assumed
 *                           that the data to be transmitted is not relevant and the default
 *                           transmit value of this channel will be used instead
 * \pre None
 * \post None
 * \return returns whether command has been accepted or rejected
 * \retval E_OK: write command has been accepted
 * \retval E_NOT_OK: write command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE)
Spi_WriteIB(VAR(Spi_ChannelType, AUTOMATIC) Channel,
            P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr);

/** \brief Service for reading data from internal buffers
 *
 * Service for reading synchronously one or more data from an IB SPI Handler/Driver
 *         Channel specified by parameter.
 *
 * \param[in] Channel: Channel ID
 * \param[out] DataBufferPointer: Pointer to destination data buffer in RAM
 * \pre None
 * \post None
 * \return returns whether command has been accepted or rejected
 * \retval E_OK: read command has been accepted
 * \retval E_NOT_OK: read command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE)
Spi_ReadIB(VAR(Spi_ChannelType, AUTOMATIC) Channel,
           P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPointer);
#endif /* #if SPI_IB || SPI_IB_EB */

#if ((SPI_CHANNEL_BUFFERS == SPI_EB) || (SPI_CHANNEL_BUFFERS == SPI_IB_EB))
/** \brief Spi_SetupEB: service to setup external buffer channels
 *
 * Service to setup the buffers and the length of data for the EB SPI Handler/Driver
 * Channel specified.
 *
 * \param[in] Channel: Channel Id
 * \param[in] SrcDataBufferPtr: Pointer to source data buffer
 * \param[in] Length: Length (number of data elements) of the data to be transmitted
 *                    from SrcDataBufferPtr and/or received from DesDataBufferPtr
 *                    Min.: 1 Max.: Max of data specified at configuration for this channel
 * \param[inout] DesDataBufferPtr: Pointer to destination data buffer in RAM.
 * \pre None
 * \post None
 * \return returns whether command has been accepted or rejected
 * \retval E_OK: read command has been accepted
 * \retval E_NOT_OK: read command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE)
Spi_SetupEB(VAR(Spi_ChannelType, AUTOMATIC) Channel,
            P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
            P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
            VAR(Spi_NumberOfDataType, AUTOMATIC) Length);
#endif /* #if ((SPI_CHANNEL_BUFFERS == SPI_EB) || \ \
        * (SPI_CHANNEL_BUFFERS == SPI_IB_EB)) */

#if ((SPI_SCALABILITY == SPI_LEVEL_1) || (SPI_SCALABILITY == SPI_LEVEL_2))
/** \brief Spi_AsyncTransmit: Service to transmit data on the SPI bus.
 *
 * Service is to transmit data on SPI bus if the sequence is valid and not pending
 *
 * \param[in] Sequence: Sequence ID
 * \pre None
 * \post None
 * \return returns whether command has been accepted or rejected
 * \retval E_OK: read command has been accepted
 * \retval E_NOT_OK: read command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence);

#endif /* #if ((SPI_SCALABILITY == SPI_LEVEL_1) || \ \
        *(SPI_SCALABILITY == SPI_LEVEL_2)) */

#if (STD_ON == SPI_CANCEL_API)
/** \brief Spi_Cancel: this service is to cancel on going sequence
 *
 * Service cancels the specified on-going sequence transmission.
 *
 * \param[in] Sequence: Sequence ID
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_Cancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif /* #if (STD_ON == SPI_CANCEL_API) */

#if ((SPI_SCALABILITY == SPI_LEVEL_0) || (SPI_SCALABILITY == SPI_LEVEL_2))
/** \brief Spi_SyncTransmit: Service to transmit data on the SPI bu
 *
 * Service is to transmit data on SPI bus synchronously
 *
 * \param[in] Sequence: Sequence ID
 * \pre None
 * \post None
 * \return returns whether command has been accepted or rejected
 * \retval E_OK: read command has been accepted
 * \retval E_NOT_OK: read command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif /* #if ((SPI_SCALABILITY == SPI_LEVEL_0) || \ \
        *(SPI_SCALABILITY == SPI_LEVEL_2)) */
#if (SPI_SCALABILITY == SPI_LEVEL_2)
/** \brief Service to set the asynchronous mechanism mode for SPI busses handled asynchronously.
 *
 * Service to set the asynchronous mechanism mode for SPI busses handled asynchronously.
 *
 * \param[in] Mode: New mode required
 * \pre None
 * \post None
 * \return returns whether command has been accepted or rejected
 * \retval E_OK: read command has been accepted
 * \retval E_NOT_OK: read command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(VAR(Spi_AsyncModeType, AUTOMATIC) Mode);
#endif /* #if (SPI_SCALABILITY == SPI_LEVEL_2) */
/** \brief Spi_MainFunction_Handling: This function shall polls the SPI interrupts linked to HW
 *Units
 *
 * This function shall polls the SPI interrupts linked to HW Units allocated
 * to the transmission of SPI sequences to enable the evolution of transmission state machine
 *
 * \pre None
 * \post None
 * \return returns whether command has been accepted or rejected
 * \retval E_OK: read command has been accepted
 * \retval E_NOT_OK: read command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* Mark the end of the C bindings section for C++ compilers. */
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* SPI_H */
/*********************************************************************************************************************
 *  End of File: Spi.h
 *********************************************************************************************************************/
