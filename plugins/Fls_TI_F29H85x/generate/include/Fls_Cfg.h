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
/*
 * Design: MCAL-31080, MCAL-31081, MCAL-31082, MCAL-31083, MCAL-31084, MCAL-31085
 */
[!LOOP "FlsConfigSet"!][!//
[!VAR "NumOfSectorCfg" = "0"!]
[!WS "4"!][!LOOP "FlsSectorList/FlsSector/*"!]
[!VAR "NumOfSectorCfg" = "$NumOfSectorCfg + 1"!]
[!WS "4"!][!ENDLOOP!]
[!ENDLOOP!][!//

#define FLS_NUMBER_OF_SECTOR_CFG             ([!"num:i($NumOfSectorCfg)"!]U)

/** \brief Enable/disable FLS load ram on job start functionality */
/*
 * Design: MCAL-31050
 */
#define FLS_LOAD_RAM_ON_JOB_START    ([!IF "FlsGeneral/FlsAcLoadOnJobStart = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Flash Base Address */
/*
 * Design: MCAL-31051
 */
#define FLS_BASE_ADDRESS                ([!"FlsGeneral/FlsBaseAddress "!]UL)

/** \brief Total amount of flash memory in bytes */
/*
 * Design: MCAL-31062
 */
#define FLS_TOTAL_SIZE                ([!"FlsGeneral/FlsTotalSize"!]U)

/** \brief Number of banks in the device variant */
#define FLS_NUM_BANKS                 ([!"FlsGeneral/FlsNumBanks"!]U)

/** \brief Sector size in bytes */
#define FLS_SECTOR_SIZE               ([!"FlsGeneral/FlsSectorSizeInBytes"!]U)

/** \brief Enable/disable FLS Blank Check API */
/*
 * Design: MCAL-31052
 */
#define FLS_BLANK_CHECK_API          ([!IF "FlsGeneral/FlsBlankCheckApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS cancel API */
/*
 * Design: MCAL-31053
 */
#define FLS_CANCEL_API              ([!IF "FlsGeneral/FlsCancelApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS compare API */
/*
 * Design: MCAL-31054
 */
#define FLS_COMPARE_API              ([!IF "FlsGeneral/FlsCompareApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS dev detect error */
/*
 * Design: MCAL-31055
 */
#define FLS_DEV_ERROR_DETECT         ([!IF "FlsGeneral/FlsDevErrorDetect = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Index of driver, used by FEE */
/*
 * Design: MCAL-31056
 */
#define FLS_DRIVER_INDEX             ([!"FlsGeneral/FlsDriverIndex"!]U)

/** \brief Enable/disable FlsEraseVerificationEnabled */
/*
 * Design: MCAL-31057
 */
#define FLS_ERASE_VERIFICATION_ENABLED    ([!IF "FlsGeneral/FlsEraseVerificationEnabled = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS  Fls_GetJobResult function API */
/*
 * Design: MCAL-31058
 */
#define FLS_GET_JOB_RESULT_API        ([!IF "FlsGeneral/FlsGetJobResultApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS  Fls_GetStatus function API */
/*
 * Design: MCAL-31059
 */
#define FLS_GET_STATUS_API            ([!IF "FlsGeneral/FlsGetStatusApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS set mode API*/
/*
 * Design: MCAL-31060
 */
#define FLS_SETMODE_API                 ([!IF "FlsGeneral/FlsSetModeApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FlsTimeoutSupervisionEnabled */
/*
 * Design: MCAL-31061
 */
#define FLS_TIMEOUT_SUPERVISION_ENABLED   ([!IF "FlsGeneral/FlsTimeoutSupervisionEnabled = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FLS get version info API */
/*
 * Design: MCAL-31064
 */
#define FLS_VERSION_INFO_API           ([!IF "FlsGeneral/FlsVersionInfoApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief Enable/disable FlsWriteVerificationEnabled */
/*
 * Design: MCAL-31065
 */
#define FLS_WRITE_VERIFICATION_ENABLED    ([!IF "FlsGeneral/FlsWriteVerificationEnabled = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** \brief CPU clock reference in Hz */
#define FLS_CPU_CLOCK_FREQ               ([!"num:i(node:value(node:ref(FlsGeneral/FlsCpuClockRef)/McuClockReferencePointFrequency))"!]U)

/** \brief Flash wait states */
#define FLS_WAIT_STATES         ([!"FlsGeneral/FlsWaitStates"!]U)

/** \brief Max Erase time in microsec*/
/*
 * Design: MCAL-31086, MCAL-31087, MCAL-31088, MCAL-31089, MCAL-31090, MCAL-31091,MCAL-31092
 * Design: MCAL-31093, MCAL-31094, MCAL-31095
 */
#define FLS_MAX_ERASE_TIME                ([!"num:i(FlsPublishedInformation/FlsEraseTime)"!]U)

/** \brief Max Write time in microsec*/
/*
 * Design: MCAL-31086, MCAL-31087, MCAL-31088, MCAL-31089, MCAL-31090, MCAL-31091,MCAL-31092
 * Design: MCAL-31093, MCAL-31094, MCAL-31095
 */
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
/* Forward declaration of Fls configuration structure */
struct Fls_ConfigType_s;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/*
 * Design: MCAL-31045, MCAL-31047
 */
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

