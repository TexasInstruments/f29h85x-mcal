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
#include "Fls_Cfg.h"
#include "Os.h"
#include "Fls_Ac.h"
#include "Fls_Cbk.h"

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
#define FLS_SW_MAJOR_VERSION            (1U)
/** \brief Driver Implementation Minor Version */
#define FLS_SW_MINOR_VERSION            (0U)
/** \brief Driver Implementation Patch Version */
#define FLS_SW_PATCH_VERSION            (0U)

/**
 * \brief Defines for FLS Driver AUTOSAR version used for compatibility checks.
 */
/** \brief AUTOSAR Major version specification implemented by FLS Driver */
#define FLS_AR_RELEASE_MAJOR_VERSION    (4U)
/** \brief AUTOSAR Minor  version specification implemented by FLS Driver */
#define FLS_AR_RELEASE_MINOR_VERSION    (3U)
/** \brief AUTOSAR Patch version specification implemented by FLS Driver */
#define FLS_AR_RELEASE_REVISION_VERSION (1U)

/**
 * \brief FLS Driver ID Info.
 */
/** \brief Texas Instruments Vendor ID */
#define FLS_VENDOR_ID                   ((uint16) 44U)
/** \brief FLS Driver Module ID */
#define FLS_MODULE_ID                   ((uint16) 92U)
/** \brief FLS Driver Instance ID */
#define FLS_INSTANCE_ID                 ((uint8) 0U)

/** \brief Type of address type */
typedef uint32  Fls_AddressType;
typedef uint32  Fls_LengthType;

/** the address in Fls_xx API is offset. The absolute addr
 *  = offset + FLS_BASE_ADDRESS & FLS_BASE_ADDRESS_REQ 
 * The SectorStartAddress of sectorList in Fls_Cfg.c is absolute address
 */
#define FLS_BASE_ADDRESS_REQ            ((uint32) 0x1FFFFFFFU)  /*or 0x0*/
                                                                                 
#define FLS_WRITE_ADDRESS_ALIGNMENT     ((uint8) 8U)

/**
 * \brief FLS Error Codes returned by FLS functions.
 */
 /** Development errors*/
#ifndef FLS_E_PARAM_CONFIG
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_CONFIG                      ((uint8) 0x01U)
#endif
#ifndef FLS_E_PARAM_ADDRESS
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_ADDRESS                     ((uint8) 0x02U)
#endif
#ifndef FLS_E_PARAM_LENGTH
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_LENGTH                      ((uint8) 0x03U)
#endif
#ifndef FLS_E_PARAM_DATA
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_DATA                        ((uint8) 0x04U)
#endif
#ifndef FLS_E_UNINIT
/** \brief API service used without module initiali-zation */
#define FLS_E_UNINIT                            ((uint8) 0x05U)
#endif
#ifndef FLS_E_BUSY
/** \brief APIs called when module is busy */
#define FLS_E_BUSY                              ((uint8) 0x06U)
#endif
#ifndef FLS_E_PARAM_POINTER
/** \brief APIs called with a Null Pointer */
#define FLS_E_PARAM_POINTER                     ((uint8) 0x0AU)
#endif

#ifndef FLS_E_PARAM_ALIGNMENT
/** \brief API service called with wrong parameter */
#define FLS_E_PARAM_ALIGNMENT                   ((uint8) 0x0CU)
#endif

/** \brief Runtime Errors WITH HW*/
#ifndef FLS_E_VERIFY_ERASE_FAILED
/** \brief APIs service Erase Verification (BlankCheck) failed */
#define FLS_E_VERIFY_ERASE_FAILED               ((uint8) 0x07U)
#endif
#ifndef FLS_E_VERIFY_WRITE_FAILED
/** \brief APIs serice Write Verification (Compare) failed */
#define FLS_E_VERIFY_WRITE_FAILED               ((uint8) 0x08U)
#endif
#ifndef FLS_E_TIMEOUT
/** \brief APIs Timeout Exceeded*/
#define FLS_E_TIMEOUT                           ((uint8) 0x09U)
#endif

/** \brief TRANSIENT FAULTS WITH HW*/
#ifndef FLS_E_ERASE_FAILED
/** \brief Flash Erase Failed in HW*/
#define FLS_E_ERASE_FAILED                      ((uint8) 0x01U)
#endif
#ifndef FLS_E_WRITE_FAILED
/** \brief Flash Write Failed in HW*/
#define FLS_E_WRITE_FAILED                      ((uint8) 0x02U)
#endif
#ifndef FLS_E_READ_FAILED
/** \brief Flash Read Failed in HW */
#define FLS_E_READ_FAILED                       ((uint8) 0x03U)
#endif
#ifndef FLS_E_COMPARE_FAILED
/** \brief Flash Compare Failediin HW */
#define FLS_E_COMPARE_FAILED                    ((uint8) 0x04U)
#endif
#ifndef FLS_E_UNEXPECTED_FLASH_ID
/** \brief Expected HW ID not matched */
#define FLS_E_UNEXPECTED_FLASH_ID               ((uint8) 0x05U)
#endif

#ifndef FLS_E_BLANK_CHECK_FAILED
/** \brief Flash Blank Check Failediin HW */
#define FLS_E_BLANK_CHECK_FAILED                ((uint8) 0x0BU)
#endif

/**
 * FLS Service Ids.
 *
 * \brief The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 */
/** \brief FLS_Init() API Service ID */
#define FLS_SID_INIT                            ((uint8) 0x00U)
/** \brief FLS_Erase() API Service ID */
#define FLS_SID_ERASE                           ((uint8) 0x01U)
/** \brief FLS_Write() API Service ID */
#define FLS_SID_WRITE                           ((uint8) 0x02U)
/** \brief FLS_Cancel() API Service ID */
#define FLS_SID_CANCEL                          ((uint8) 0x03U)
/** \brief FLS_GetStatus() API Service ID */
#define FLS_SID_GET_STATUS                      ((uint8) 0x04U)
/** \brief Fls_GetJobResult() API Service ID */
#define FLS_SID_GET_JOB_RESULT                  ((uint8) 0x05U)
/** \brief FLS_Read() API Service ID */
#define FLS_SID_READ                            ((uint8) 0x07U)
/** \brief FLS_Compare() API Service ID */
#define FLS_SID_COMPARE                         ((uint8) 0x08U)
/** \brief FLS_SetMode() API Service ID */
#define FLS_SID_SET_MODE                        ((uint8) 0x09U)
/** \brief Fls_GetVersionInfo() API Service ID */
#define FLS_SID_GET_VERSION_INFO                ((uint8) 0x10U)
/** \brief FLS_BlankCheck() API Service ID */
#define FLS_SID_BLANK_CHECK                     ((uint8) 0x0AU)
/** \brief FLS_MainFunction() API Service ID */
#define FLS_SID_MAIN_FUNCTION                   ((uint8) 0x06U)


/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/ 

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/**
 *  \brief FLS Module Flashable Sectors and pages
 */
typedef struct {
        Fls_LengthType        numberOfSectors;
        /**  Number of total Sectors in the Flash Device */
        Fls_LengthType        sectorPageSize;
        /**  Page size of the Flash Device */
        Fls_LengthType        sectorSize;
        /**  Size of each sector in the Flash Device */
        Fls_AddressType       sectorStartAddress;
        /**  Start address of first sector of the Flash Device */
} Fls_SectorType;

typedef struct Fls_ConfigType_s
{
        Fls_JobEndNotifyType            Fls_JobEndNotification;
        /**     Mapped to the job end notification routine provided by some upper layer
         *      module, typically the Fee module. */
        Fls_JobErrorNotifyType          Fls_JobErrorNotification;
        /**     Mapped to the job error notification routine provided by some upper layer
         *      module, typically the Fee module. */
        uint32                          FlsMaxReadNormalMode;
        /**     The maximum number of bytes to read or compare in one cycle of the
         *      flash driver's job processing function in normal mode. */
        uint32                          FlsMaxWriteNormalMode;
        /**     The maximum number of bytes to write in one cycle of the
         *      flash driver's job processing function in normal mode. */
	    Fls_SectorType                  sectorList[FLS_NUMBER_OF_SECTOR_CFG];

} Fls_ConfigType;

/**  ENUM for erase type names */
typedef enum {
	FLS_SECTOR_ERASE = 0U,
	FLS_BANK_ERASE
} Fls_EraseType;


/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/**
 *  \brief Initializes the Flash Driver.
 *
 *  \verbatim
 *  Service name        : Fls_Init
 *  Syntax              : void Fls_Init( const Fls_ConfigType* ConfigPtr )
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : 0x00
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : ConfigPtr - Pointer to flash driver configuration set
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : None
 *  Description         : Initializes the Flash Driver
 *  \endverbatim
 */
FUNC(void, FLS_CODE) Fls_Init(
    P2CONST(Fls_ConfigType, AUTOMATIC, FLS_CONFIG_DATA) ConfigPtr);

/**
 *  \brief Erases flash sector(s).
 *
 *  \verbatim
 *  Service name        : Fls_Erase
 *  Syntax              : Std_ReturnType Fls_Erase(Fls_AddressType TargetAddress
 *                        ,Fls_LengthType Length)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : 0x01
 *  Sync/Async          : Asynchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : TargetAddress - Target address in flash memory.
 *                        This address offset will be added to the flash memory
 *                        base address.
 *                        Length - Number of bytes to erase
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType -
 *                        E_OK: erase command has been accepted
 *                        E_NOT_OK: erase command has not been accepted
 *  Description         : Erases flash sector(s).
 *  \endverbatim
 */
FUNC(Std_ReturnType, FLS_CODE) Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length);

/**
 *  \brief  Writes one or more complete flash pages.
 *
 *  \verbatim
 *  Service name        : Fls_Write
 *  Syntax              : Std_ReturnType Fls_Write(Fls_AddressType TargetAddress
 *                        ,const uint8* SourceAddressPtr,
 *                        Fls_LengthType Length)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : 0x02
 *  Sync/Async          : Asynchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : TargetAddress - Target address in flash memory.
 *                        This address offset will be added to the flash memory
 *                        base address.
 *                        SourceAddressPtr - Pointer to source data buffer
 *                        Length - Number of bytes to erase
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType -
 *                        E_OK: write command has been accepted
 *                        E_NOT_OK: write command has not been accepted
 *  Description         : Writes one or more complete flash pages.
 *  \endverbatim
 */
FUNC(Std_ReturnType, FLS_CODE) Fls_Write(Fls_AddressType TargetAddress,
    const uint8 *SourceAddressPtr, Fls_LengthType Length);

/**
 *  \brief Reads from flash memory..
 *
 *  \verbatim
 *  Service name        : Fls_Read
 *  Syntax              : Std_ReturnType Fls_Read((Fls_AddressType SourceAddress
 *                        ,const uint8* TargetAddressPtr,
 *                        Fls_LengthType Length)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : 0x07
 *  Sync/Async          : Asynchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : SourceAddress - source address in flash memory.
 *                        This address offset will be added to the flash memory
 *                        base address.
 *                        TargetAddressPtr - Pointer to source data buffer
 *                        Length - Number of bytes to erase
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType -
 *                        E_OK: read command has been accepted
 *                        E_NOT_OK: read command has not been accepted
 *  Description         : Reads from flash memory.
 *  \endverbatim
 */
FUNC(Std_ReturnType, FLS_CODE) Fls_Read(Fls_AddressType SourceAddress,
                    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr,
                    Fls_LengthType Length);

/**
 *  \brief Compares the contents of an area of flash memory with
 *  that of an application data buffer.
 *
 *  \verbatim
 *  Service name        : Fls_Compare
 *  Syntax              : Std_ReturnType Fls_Compare
 *                        (Fls_AddressType SourceAddress,
 *                        const uint8* TargetAddressPtr,
 *                        Fls_LengthType Length)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : 0x08
 *  Sync/Async          : Asynchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : SourceAddress - Target address in flash memory.
 *                        This address offset will be added to the flash memory
 *                        base address.
 *                        TargetAddressPtr - Pointer to source data buffer
 *                        Length - Number of bytes to erase
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType -
 *                        E_OK: compare command has been accepted
 *                        E_NOT_OK: compare command has not been accepted
 *  Description         : Compares the contents of an area of flash memory
 *                        with that of an application data buffer.
 *  \endverbatim
 */
#if (STD_ON == FLS_COMPARE_API)
FUNC(Std_ReturnType, FLS_CODE) Fls_Compare(Fls_AddressType SourceAddress, 
                               const uint8 *TargetAddressPtr, Fls_LengthType Length);
#endif

/**
 *  \brief The function Fls_BlankCheck shall verify,
 *         whether a given memory area has been
 *         erased but not (yet) programmed.
 *
 *  \verbatim
 *  Service name        : Fls_BlankCheck
 *  Syntax              : Std_ReturnType Fls_Compare
 *                        (Fls_AddressType TargetAddress,,
 *                        Fls_LengthType Length)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : 0x0a
 *  Sync/Async          : Asynchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : TargetAddress - Target address in flash memory.
 *                        This address offset will be added to the flash memory
 *                        base address.
 *                        SourceAddressPtr - Pointer to source data buffer
 *                        Length - Number of bytes to erase
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : Std_ReturnType -
 *                        E_OK: BlankCheck command has been accepted
 *                        E_NOT_OK: BlankCheck command has not been accepted
 *  Description         : The function Fls_BlankCheck shall verify,
 *                        whether a given memory area has been
 *                        erased but not (yet) programmed.
 *  \endverbatim
 */
#if (STD_ON == FLS_BLANK_CHECK_API)
FUNC(Std_ReturnType, FLS_CODE) Fls_BlankCheck(Fls_AddressType Address, Fls_LengthType Length);
#endif

/**
 *  \brief Returns the driver state.
 *
 *  \verbatim
 *  Service name        : Fls_GetStatus
 *  Syntax              : MemIf_StatusType Fls_GetStatus( void )
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : 0x04
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Reentrant
 *  Parameters (in)     : None
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : MemIf_StatusType
 *  Description         : Returns the driver state.
 *  \endverbatim
 */
#if (STD_ON == FLS_GET_STATUS_API)
FUNC(MemIf_StatusType, FLS_CODE) Fls_GetStatus( void );
#endif

/**
 *  \brief This service returns the version information of this module.
 *
 *  \verbatim
 *  Service name        : Fls_GetVersionInfo
 *  Syntax              : void Fls_GetVersionInfo( Std_VersionInfoType*
 *                                                                 versioninfo )
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : 0x10
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Reentrant
 *  Parameters (in)     : None
 *  Parameters (inout)  : versioninfo - Pointer to where to store the version
 *                        information of this module
 *  Parameters (out)    : None
 *  Return value        : None
 *  Description         : This service returns the version information of this
 *                        module
 *  \endverbatim
 */
#if (STD_ON == FLS_VERSION_INFO_API)
FUNC(Std_ReturnType, FLS_CODE) Fls_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/**
 *  \brief Returns the result of the last job.
 *
 *  \verbatim
 *  Service name        : Fls_GetJobResult
 *  Syntax              : MemIf_JobResultType Fls_GetJobResult(void)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : 0x05
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Reentrant
 *  Parameters (in)     : None
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : MemIf_JobResultType
 *  Description         : Returns the result of the last job.
 *  \endverbatim
 */
#if (STD_ON == FLS_GET_JOB_RESULT_API)
FUNC(MemIf_JobResultType, FLS_CODE) Fls_GetJobResult( void );
#endif

/**
 *  \brief Performs the processing of jobs.
 *
 *  \verbatim
 *  Service name        : Fls_MainFunction
 *  Syntax              : void Fls_MainFunction(void)
 *  Mode                : Supervisor Mode (Privileged Mode)
 *  Service ID[hex]     : 0x06
 *  Description         : Performs the processing of jobs.
 *  \endverbatim
 */
FUNC(void, FLS_CODE) Fls_MainFunction(void);

/**
 *  \brief Cancels an ongoing job.
 *
 *  \verbatim
 *  Service name        : Fls_Cancel
 *  Syntax              : void Fls_Cancel(void)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : 0x03
 *  Description         : Cancels an ongoing job.
 *  \endverbatim
 */
#if ( FLS_CANCEL_API == STD_ON )
FUNC(void, FLS_CODE) Fls_Cancel(void);
#endif


/**
 *  \brief Sets the flash driver's operation mode
 *
 *  \verbatim
 *  Service name        : Fls_SetMode
 *  Syntax              : void Fls_SetMode(MemIf_ModeType Mode)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : 0x09
 *  Sync/Async          : Synchronous
 *  Reentrancy          : Non Reentrant
 *  Parameters (in)     : Mode
 *                        MEMIF_MODE_SLOW: Slow read access / normal SPI access.
 *                        MEMIF_MODE_FAST: Fast read access / SPI burst access.
 *  Parameters (inout)  : None
 *  Parameters (out)    : None
 *  Return value        : None
 *  Description         : Sets the flash driver's operation mode
 *                        This is a dummy API which is not supported and 
 *                        Added for integration purposes 
 *  \endverbatim
 */
#if (STD_ON == FLS_SETMODE_API)
FUNC(void, FLS_CODE) Fls_SetMode( MemIf_ModeType Mode);
#endif

/**
 *  \brief Sets the parameters for required erase type.
 *
 *  \verbatim
 *  Service name        : Fls_SetEraseType
 *  Syntax              : uint32  Fls_SetEraseType(Fls_EraseType erasetype)
 *  Mode                : User Mode (Non-Privileged Mode)
 *  Service ID[hex]     : NA
 *  Description         : Sets the parameters required in application, based on the erase type parameter 
 *                        passed to this function while calling from Application.
 *  \endverbatim
 */
FUNC(uint32, FLS_CODE) Fls_SetEraseType(Fls_EraseType erasetype);	

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /** #ifndef FLS_H_ */

/*********************************************************************************************************************
 *  End of File: Fls.h
 *********************************************************************************************************************/