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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:         Fls_Cfg.h
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/

#ifndef FLS_CFG_H_
#define FLS_CFG_H_

/**
 *  \addtogroup FLS
 *
 *  This files defines FLS MCAL configuration structures
 *  @{
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
[!AUTOSPACING!] [!/* Do not delete this line, spacing would be lost */!]
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
[!IF "as:modconf('Fls')[as:path(node:dtos(.))='/TI_F29H85x/Fls']/FlsGeneral/FlsDevErrorDetect = 'true'"!]#include "Det.h"[!ENDIF!]

#include "Std_Types.h"
#include "Os.h"
#include "Fee_Cbk.h"
#include "MemIf_Types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/**
 *  \name Fls Driver Configuration SW Version Info
 *  Defines for Fls Driver configuration version
 *  @{
 */
/** \brief Fls configuration Major Version */
#define FLS_CFG_MAJOR_VERSION           ([!"substring-before($moduleSoftwareVer,'.')"!]U)
/** \brief Fls configuration Minor Version */
#define FLS_CFG_MINOR_VERSION           ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
/** \brief Fls configuration Patch Version */
#define FLS_CFG_PATCH_VERSION           ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
/* @} */

/**
*  \brief FLS Build Variant.
*   Build variants.(i.e Pre Compile,Post Build or Link time)
*/

[!SELECT "as:modconf('Fls')[as:path(node:dtos(.))='/TI_F29H85x/Fls']"!]
#define FLS_PRE_COMPILE_VARIANT    ([!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define FLS_POST_BUILD_VARIANT     ([!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**  \brief Pre Compile config macro name. */
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
[!LOOP "FlsConfigSet"!]
#define FLS_INIT_CONFIG_PC       Fls_Config
[!ENDLOOP!]
[!ENDIF!]

/** \brief Flash Sectors (0~31) protection */
#define FLS_CMDWEPROTA                 ([!"FlsConfigSet/Fls_CMDWEPROTA"!]U)

/** \brief Flash Sectors (32~255) protection */
#define FLS_CMDWEPROTB                ([!"FlsConfigSet/Fls_CMDWEPROTB"!]U)

/** \brief Number of Sectorlist configured */
[!LOOP "FlsConfigSet"!][!//
[!VAR "NumOfSectorCfg" = "0"!]
[!WS "4"!][!LOOP "FlsSectorList/FlsSector/*"!]
[!VAR "NumOfSectorCfg" = "$NumOfSectorCfg + 1"!]
[!WS "4"!][!ENDLOOP!]
[!ENDLOOP!][!//

#define FLS_NUMBER_OF_SECTOR_CFG             ([!"num:i($NumOfSectorCfg)"!]U)

/** \brief Enable/disable FLS load ram on job start functionality */
#define FLS_LOAD_RAM_ON_JOB_START    ([!IF "FlsGeneral/FlsAcLoadOnJobStart = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Flash Base Address */
#define FLS_BASE_ADDRESS                ([!"FlsGeneral/FlsBaseAddress "!]UL)

/** \brief Total amount of flash memory in bytes */
#define FLS_TOTAL_SIZE                ([!"FlsGeneral/FlsTotalSize"!]U)

/** \brief Number of banks in the device variant */
#define FLS_NUM_BANKS                 ([!"FlsGeneral/FlsNumBanks"!]U)

/** \brief Sector size in bytes */
#define FLS_SECTOR_SIZE               ([!"FlsGeneral/FlsSectorSizeInBytes"!]U)

/** \brief Enable/disable FLS Blank Check API */
#define FLS_BLANK_CHECK_API          ([!IF "FlsGeneral/FlsBlankCheckApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS cancel API */
#define FLS_CANCEL_API              ([!IF "FlsGeneral/FlsCancelApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS compare API */
#define FLS_COMPARE_API              ([!IF "FlsGeneral/FlsCompareApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS dev detect error */
#define FLS_DEV_ERROR_DETECT         ([!IF "FlsGeneral/FlsDevErrorDetect = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Index of driver, used by FEE */
#define FLS_DRIVER_INDEX             ([!"FlsGeneral/FlsDriverIndex"!]U)

/** \brief Enable/disable FlsEraseVerificationEnabled */
#define FLS_ERASE_VERIFICATION_ENABLED    ([!IF "FlsGeneral/FlsEraseVerificationEnabled = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS  Fls_GetJobResult function API */
#define FLS_GET_JOB_RESULT_API        ([!IF "FlsGeneral/FlsGetJobResultApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS  Fls_GetStatus function API */
#define FLS_GET_STATUS_API            ([!IF "FlsGeneral/FlsGetStatusApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS set mode API*/
#define FLS_SETMODE_API                 ([!IF "FlsGeneral/FlsSetModeApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FlsTimeoutSupervisionEnabled */
#define FLS_TIMEOUT_SUPERVISION_ENABLED   ([!IF "FlsGeneral/FlsTimeoutSupervisionEnabled = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS get version info API */
#define FLS_VERSION_INFO_API           ([!IF "FlsGeneral/FlsVersionInfoApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FlsWriteVerificationEnabled */
#define FLS_WRITE_VERIFICATION_ENABLED    ([!IF "FlsGeneral/FlsWriteVerificationEnabled = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief CPU clock reference in Hz */
#define FLS_CPU_CLOCK_FREQ               ([!"num:i(node:value(node:ref(FlsGeneral/FlsCpuClockRef)/McuClockReferencePointFrequency))"!]U)

/** \brief Flash wait states */
#define FLS_WAIT_STATES         ([!"FlsGeneral/FlsWaitStates"!]U)

/** \brief Max Erase time in microsec*/
#define FLS_MAX_ERASE_TIME                ([!"num:i(FlsPublishedInformation/FlsEraseTime)"!]U)

/** \brief Max Write time in microsec*/
#define FLS_MAX_WRITE_TIME                ([!"num:i(FlsPublishedInformation/FlsWriteTime)"!]U)


/* @} */

/**
 * FLS interrupt configuration
 * @{
 */
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
[!LOOP "FlsConfigSet"!]
/** \brief FLS Configuration struct declaration */
extern const struct Fls_ConfigType_s Fls_Config;
[!ENDLOOP!]
[!ENDSELECT!]

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#endif /*#ifndef DOXYGEN_SHOULD_SKIP_THIS*/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* FLS_CFG_H_ */
/*********************************************************************************************************************
 *  End of File: Fls_Cfg.h
 *********************************************************************************************************************/

