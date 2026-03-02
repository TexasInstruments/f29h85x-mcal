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
 *  \file       Fls.h
 *  Generator:  None
 *
 *  \brief Description:  This file contains interface header for Fls MCAL driver
 *********************************************************************************************************************/

#ifndef FLS_H_
#define FLS_H_

/**
 * \defgroup FLS Fls API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Fls_Cbk.h"
#include "Fls_Cfg.h"

/*
 *  Design: MCAL-30889, MCAL-30898
 */
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/**
 * \brief Defines for FLS Driver version used for compatibility checks.
 */
/** \brief Driver Implementation Major Version */
#define FLS_SW_MAJOR_VERSION (3U)
/** \brief Driver Implementation Minor Version */
#define FLS_SW_MINOR_VERSION (1U)
/** \brief Driver Implementation Patch Version */
#define FLS_SW_PATCH_VERSION (0U)

/**
 * \brief Defines for FLS Driver AUTOSAR version used for compatibility checks.
 */
/** \brief AUTOSAR Major version specification implemented by FLS Driver */
#define FLS_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor  version specification implemented by FLS Driver */
#define FLS_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by FLS Driver */
#define FLS_AR_RELEASE_REVISION_VERSION (1U)

/**
 * \brief FLS Driver ID Info.
 */
/** \brief Texas Instruments Vendor ID */
#define FLS_VENDOR_ID ((uint16)44U)
/** \brief FLS Driver Module ID */
#define FLS_MODULE_ID ((uint16)92U)
/** \brief FLS Driver Instance ID */
#define FLS_INSTANCE_ID ((uint8)0U)

/** \brief Type of address type */
typedef uint32 Fls_AddressType;
/** \brief Type of length type */
typedef uint32 Fls_LengthType;

/** the address in Fls_xx API is offset. The absolute addr
 *  = offset + FLS_BASE_ADDRESS & FLS_BASE_ADDRESS_REQ
 * The SectorStartAddress of sectorList in Fls_Cfg.c is absolute address
 */
#define FLS_BASE_ADDRESS_REQ ((uint32)0x1FFFFFFFU) /*or 0x0*/
/** \brief Flash base address requirement */
#define FLS_WRITE_ADDRESS_ALIGNMENT ((uint8)8U)
/** \brief Flash write address alignment */

/**
 * \brief FLS Error Codes returned by FLS functions.
 */
/** Development errors*/
#ifndef FLS_E_PARAM_CONFIG
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_CONFIG ((uint8)0x01U)
#endif
#ifndef FLS_E_PARAM_ADDRESS
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_ADDRESS ((uint8)0x02U)
#endif
#ifndef FLS_E_PARAM_LENGTH
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_LENGTH ((uint8)0x03U)
#endif
#ifndef FLS_E_PARAM_DATA
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_DATA ((uint8)0x04U)
#endif
#ifndef FLS_E_UNINIT
/** \brief API service used without module initialization */
#define FLS_E_UNINIT ((uint8)0x05U)
#endif
#ifndef FLS_E_BUSY
/** \brief APIs called when module is busy */
#define FLS_E_BUSY ((uint8)0x06U)
#endif
#ifndef FLS_E_PARAM_POINTER
/** \brief APIs called with a Null Pointer */
#define FLS_E_PARAM_POINTER ((uint8)0x0AU)
#endif

#ifndef FLS_E_PARAM_ALIGNMENT
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_ALIGNMENT ((uint8)0x0CU)
#endif

/** \brief Runtime Errors WITH HW*/
#ifndef FLS_E_VERIFY_ERASE_FAILED
/** \brief APIs service Erase Verification (BlankCheck) failed */
#define FLS_E_VERIFY_ERASE_FAILED ((uint8)0x07U)
#endif
#ifndef FLS_E_VERIFY_WRITE_FAILED
/** \brief APIs serice Write Verification (Compare) failed */
#define FLS_E_VERIFY_WRITE_FAILED ((uint8)0x08U)
#endif
#ifndef FLS_E_TIMEOUT
/** \brief APIs Timeout Exceeded*/
#define FLS_E_TIMEOUT ((uint8)0x09U)
#endif

/** \brief TRANSIENT FAULTS WITH HW*/
#ifndef FLS_E_ERASE_FAILED
/** \brief Flash Erase Failed in HW*/
#define FLS_E_ERASE_FAILED ((uint8)0x01U)
#endif
#ifndef FLS_E_WRITE_FAILED
/** \brief Flash Write Failed in HW*/
#define FLS_E_WRITE_FAILED ((uint8)0x02U)
#endif
#ifndef FLS_E_READ_FAILED
/** \brief Flash Read Failed in HW */
#define FLS_E_READ_FAILED ((uint8)0x03U)
#endif
#ifndef FLS_E_COMPARE_FAILED
/** \brief Flash Compare Failediin HW */
#define FLS_E_COMPARE_FAILED ((uint8)0x04U)
#endif

/*
 *  Design: MCAL-30910, MCAL-30911,
 */
#ifndef FLS_E_UNEXPECTED_FLASH_ID
/** \brief Expected HW ID not matched */
#define FLS_E_UNEXPECTED_FLASH_ID ((uint8)0x05U)
#endif

#ifndef FLS_E_BLANK_CHECK_FAILED
/** \brief Flash Blank Check Failediin HW */
#define FLS_E_BLANK_CHECK_FAILED ((uint8)0x0BU)
#endif

/**
 * FLS Service Ids.
 *
 * \brief The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 */
/** \brief FLS_Init() API Service ID */
#define FLS_SID_INIT ((uint8)0x00U)
/** \brief FLS_Erase() API Service ID */
#define FLS_SID_ERASE ((uint8)0x01U)
/** \brief FLS_Write() API Service ID */
#define FLS_SID_WRITE ((uint8)0x02U)
/** \brief FLS_Cancel() API Service ID */
#define FLS_SID_CANCEL ((uint8)0x03U)
/** \brief FLS_GetStatus() API Service ID */
#define FLS_SID_GET_STATUS ((uint8)0x04U)
/** \brief Fls_GetJobResult() API Service ID */
#define FLS_SID_GET_JOB_RESULT ((uint8)0x05U)
/** \brief FLS_Read() API Service ID */
#define FLS_SID_READ ((uint8)0x07U)
/** \brief FLS_Compare() API Service ID */
#define FLS_SID_COMPARE ((uint8)0x08U)
/** \brief FLS_SetMode() API Service ID */
#define FLS_SID_SET_MODE ((uint8)0x09U)
/** \brief Fls_GetVersionInfo() API Service ID */
#define FLS_SID_GET_VERSION_INFO ((uint8)0x10U)
/** \brief FLS_BlankCheck() API Service ID */
#define FLS_SID_BLANK_CHECK ((uint8)0x0AU)
/** \brief FLS_MainFunction() API Service ID */
#define FLS_SID_MAIN_FUNCTION ((uint8)0x06U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/**
 *  \brief FLS Module Flashable Sectors and pages
 */
typedef struct
{
    Fls_LengthType  numberOfSectors;
    /** \brief Number of total Sectors in the Flash Device */
    Fls_LengthType  sectorPageSize;
    /** \brief Page size of the Flash Device */
    Fls_LengthType  sectorSize;
    /** \brief Size of each sector in the Flash Device */
    Fls_AddressType sectorStartAddress;
    /** \brief Start address of first sector of the Flash Device */
} Fls_SectorType;

/*
 *  Design: MCAL-31038
 */
typedef struct Fls_ConfigType_s
{
    Fls_JobEndNotifyType   Fls_JobEndNotification;
    /** \brief Mapped to the job end notification routine provided by some upper layer
     *      module, typically the Fee module. */
    Fls_JobErrorNotifyType Fls_JobErrorNotification;
    /** \brief Mapped to the job error notification routine provided by some upper layer
     *      module, typically the Fee module. */
    uint32                 FlsMaxReadNormalMode;
    /** \brief The maximum number of bytes to read or compare in one cycle of the
     *      flash driver's job processing function in normal mode. */
    uint32                 FlsMaxWriteNormalMode;
    /** \brief The maximum number of bytes to write in one cycle of the
     *      flash driver's job processing function in normal mode. */
    Fls_SectorType         sectorList[FLS_NUMBER_OF_SECTOR_CFG];

} Fls_ConfigType;

/** \brief ENUM for erase type names */
typedef enum
{
    FLS_SECTOR_ERASE = 0U, /*!< \brief  Erase sector */
    FLS_BANK_ERASE   = 1U  /*!< \brief  Erase bank */
} Fls_EraseType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Initializes the Flash Driver.
 *
 * \param[in] ConfigPtr : Pointer to flash driver configuration set
 * \pre None
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, FLS_CODE) Fls_Init(P2CONST(Fls_ConfigType, AUTOMATIC, FLS_CONFIG_DATA) ConfigPtr);

/** \brief Erases flash sector(s).
 *
 * \param[in] TargetAddress Target address in flash memory.
 *                          This address offset will be added to the flash memory
 *                          base address.
 * \param[in] Length - Number of bytes to erase
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return return_value
 * \retval E_OK: erase command has been accepted
 * \retval E_NOT_OK: erase command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FLS_CODE) Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length);

/** \brief Writes one or more complete flash pages.
 *
 * \param[in] TargetAddress Target address in flash memory.
 *                          This address offset will be added to the flash memory
 *                          base address.
 * \param[in] SourceAddressPtr Pointer to source address
 * \param[in] Length - Number of bytes to write
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return Std_ReturnType
 * \retval E_OK: write command has been accepted
 * \retval E_NOT_OK: write command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FLS_CODE)
Fls_Write(Fls_AddressType TargetAddress, const uint8 *SourceAddressPtr, Fls_LengthType Length);

/** \brief Reads from flash memory
 *
 * \param[in] SourceAddress Source address
 * \param[in] Length - Number of bytes to read
 * \param[in] TargetAddressPtr Pointer to target data buffer
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return Std_ReturnType
 * \retval E_OK: read command has been accepted
 * \retval E_NOT_OK: read command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FLS_CODE)
Fls_Read(Fls_AddressType SourceAddress, P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr, Fls_LengthType Length);

#if (STD_ON == FLS_COMPARE_API)
/** \brief Compares the contents of an area of flash memory
 *         with that of an application data buffer.
 * \param[in] SourceAddress Target address in flash memory.
 *                          This address offset will be added to the flash memory
 *                          base address.
 * \param[in] TargetAddressPtr Pointer to target data buffer
 * \param[in] Length - Number of bytes to compare
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return Std_ReturnType
 * \retval E_OK: compare command has been accepted
 * \retval E_NOT_OK: compare command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FLS_CODE)
Fls_Compare(Fls_AddressType SourceAddress, const uint8 *TargetAddressPtr, Fls_LengthType Length);
#endif

#if (STD_ON == FLS_BLANK_CHECK_API)
/** \brief The function Fls_BlankCheck shall verify, whether a given memory area has been erased but
 *not (yet) programmed.
 * \param[in] Address Address in flash memory from which the blank check should be started.
 * \param[in] Length - Number of bytes to be checked for erase pattern
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return Std_ReturnType
 * \retval E_OK: request for blank checking has been accepted by the module
 * \retval E_NOT_OK: request for blank checking has not been accepted by the module
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FLS_CODE) Fls_BlankCheck(Fls_AddressType Address, Fls_LengthType Length);
#endif

#if (STD_ON == FLS_GET_STATUS_API)
/** \brief Returns the driver state.
 * \pre Preconditions - Driver not already initialized
 * \post Postconditions - Driver in initialized state
 * \return MemIf_StatusType
 *
 *********************************************************************************************************************/
FUNC(MemIf_StatusType, FLS_CODE) Fls_GetStatus(void);
#endif

#if (STD_ON == FLS_VERSION_INFO_API)
/** \brief Returns the version information of this module.
 * \param[out] versioninfo Pointer to where to store the version information of this module.
 * \pre Preconditions - None
 * \post Postconditions - None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FLS_CODE) Fls_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

#if (STD_ON == FLS_GET_JOB_RESULT_API)
/** \brief Returns the result of the last job.
 * \pre Preconditions - None
 * \post Postconditions - None
 * \return MemIf_JobResultType
 *
 *********************************************************************************************************************/
FUNC(MemIf_JobResultType, FLS_CODE) Fls_GetJobResult(void);
#endif

/** \brief Performs the processing of jobs.
 * \pre Preconditions - None
 * \post Postconditions - None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, FLS_CODE) Fls_MainFunction(void);

#if (FLS_CANCEL_API == STD_ON)
/** \brief Cancels an ongoing job.
 * \pre Preconditions - None
 * \post Postconditions - None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, FLS_CODE) Fls_Cancel(void);
#endif

#if (STD_ON == FLS_SETMODE_API)
/** \brief Sets the flash driver's operation mode. This is a dummy API which is not supported and
 *         added for integration purposes
 * \pre Preconditions - None
 * \post Postconditions - None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, FLS_CODE) Fls_SetMode(MemIf_ModeType Mode);
#endif

/** \brief Sets the parameters required in application, based on the erase type parameter
 *         passed to this function while calling from Application.
 * \param[in] erasetype
 * \pre Preconditions - None
 * \post Postconditions - None
 * \return Sector or bank size
 *
 *********************************************************************************************************************/
FUNC(uint32, FLS_CODE) Fls_SetEraseType(Fls_EraseType erasetype);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /** #ifndef FLS_H_ */

/*********************************************************************************************************************
 *  End of File: Fls.h
 *********************************************************************************************************************/
