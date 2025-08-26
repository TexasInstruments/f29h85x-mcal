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
 
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Det.h"
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
#define FLS_CFG_MAJOR_VERSION           (2U)
/** \brief Fls configuration Minor Version */
#define FLS_CFG_MINOR_VERSION           (0U)
/** \brief Fls configuration Patch Version */
#define FLS_CFG_PATCH_VERSION           (0U)
/* @} */

/**
*  \brief FLS Build Variant.
*   Build variants.(i.e Pre Compile,Post Build or Link time)
*/

#define FLS_PRE_COMPILE_VARIANT    (STD_ON)

#define FLS_POST_BUILD_VARIANT     (STD_OFF)

/**  \brief Pre Compile config macro name. */
#define FLS_INIT_CONFIG_PC       Fls_Config

/** \brief Flash Sectors (0~31) protection */
#define FLS_CMDWEPROTA                 (0U)

/** \brief Flash Sectors (32~255) protection */
#define FLS_CMDWEPROTB                (0U)

/** \brief Number of Sectorlist configured */
                        
#define FLS_NUMBER_OF_SECTOR_CFG             (5U)

/** \brief Enable/disable FLS load ram on job start functionality */
#define FLS_LOAD_RAM_ON_JOB_START    (STD_OFF)

/** \brief Flash Base Address */
#define FLS_BASE_ADDRESS                (281018368UL)

/** \brief Total amount of flash memory in bytes */
#define FLS_TOTAL_SIZE                (262144U)

/** \brief Number of banks in the device variant */
#define FLS_NUM_BANKS                 (1U)

/** \brief Sector size in bytes */
#define FLS_SECTOR_SIZE               (2048U)

/** \brief Enable/disable FLS Blank Check API */
#define FLS_BLANK_CHECK_API          (STD_ON)

/** \brief Enable/disable FLS cancel API */
#define FLS_CANCEL_API              (STD_ON)

/** \brief Enable/disable FLS compare API */
#define FLS_COMPARE_API              (STD_ON)

/** \brief Enable/disable FLS dev detect error */
#define FLS_DEV_ERROR_DETECT         (STD_ON)

/** \brief Index of driver, used by FEE */
#define FLS_DRIVER_INDEX             (0U)

/** \brief Enable/disable FlsEraseVerificationEnabled */
#define FLS_ERASE_VERIFICATION_ENABLED    (STD_ON)

/** \brief Enable/disable FLS  Fls_GetJobResult function API */
#define FLS_GET_JOB_RESULT_API        (STD_ON)

/** \brief Enable/disable FLS  Fls_GetStatus function API */
#define FLS_GET_STATUS_API            (STD_ON)

/** \brief Enable/disable FLS set mode API*/
#define FLS_SETMODE_API                 (STD_OFF)

/** \brief Enable/disable FlsTimeoutSupervisionEnabled */
#define FLS_TIMEOUT_SUPERVISION_ENABLED   (STD_ON)

/** \brief Enable/disable FLS get version info API */
#define FLS_VERSION_INFO_API           (STD_ON)

/** \brief Enable/disable FlsWriteVerificationEnabled */
#define FLS_WRITE_VERIFICATION_ENABLED    (STD_ON)

/** \brief CPU clock reference in Hz */
#define FLS_CPU_CLOCK_FREQ               (200000000U)

/** \brief Flash wait states */
#define FLS_WAIT_STATES         (3U)

/** \brief Max Erase time in microsec*/
#define FLS_MAX_ERASE_TIME                (1003000U)

/** \brief Max Write time in microsec*/
#define FLS_MAX_WRITE_TIME                (635U)


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
/** \brief FLS Configuration struct declaration */
extern const struct Fls_ConfigType_s Fls_Config;

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

