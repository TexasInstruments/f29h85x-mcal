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
 *  File:       Wdg.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Wdg Drv functions
 *********************************************************************************************************************/
#ifndef WDG_H
#define WDG_H

/**
 * \defgroup WDG Wdg API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "WdgIf_Types.h"
#include "Wdg_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Defines for WDG Driver version used for compatibility checks.
 *********************************************************************************************************************/
/** \brief Driver Implementation Major Version. */
#define WDG_SW_MAJOR_VERSION (2U)
/** \brief Driver Implementation Minor Version. */
#define WDG_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version. */
#define WDG_SW_PATCH_VERSION (1U)

/*********************************************************************************************************************
 * Defines for WDG Driver AUTOSAR version used for compatibility checks.
 *********************************************************************************************************************/
/** \brief AUTOSAR Major version specification implemented by WDG Driver.*/
#define WDG_AR_RELEASE_MAJOR_VERSION (4U)

/** \brief AUTOSAR Minor version specification implemented by WDG Driver.*/
#define WDG_AR_RELEASE_MINOR_VERSION (3U)

/** \brief AUTOSAR Patch version specification implemented by WDG Driver.*/
#define WDG_AR_RELEASE_REVISION_VERSION (1U)

/*********************************************************************************************************************
 * WDG Driver ID Info.
 *********************************************************************************************************************/
/** \brief Texas Instruments Vendor ID. */
#define WDG_VENDOR_ID ((uint16)44U)
/** \brief WDG Driver Module ID. */
#define WDG_MODULE_ID ((uint16)102U)
/** \brief WDG Instance ID. */
#define WDG_INSTANCE_ID ((uint8)0U)

/*********************************************************************************************************************
 * WDG Service Ids.
 *
 * The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 *********************************************************************************************************************/
/** \brief Service ID for Wdg_Init.*/
#define WDG_SID_INIT ((uint8)0x00U)
/** \brief Service ID for Wdg_SetMode.*/
#define WDG_SID_SET_MODE ((uint8)0x01U)
/** \brief Service ID for Wdg_SetTriggerCondition.*/
#define WDG_SID_SET_TRIGGER_CONDITION ((uint8)0x03U)
/** \brief Service ID for Wdg_GetVersionInfo.*/
#define WDG_SID_GET_VERSION_INFO ((uint8)0x04U)

/*********************************************************************************************************************
 * WDG Error Codes returned by Driver functions.
 *********************************************************************************************************************/
/*
 * Design: MCAL-25225
 */
/** \brief Invalid driver state.*/
#define WDG_E_DRIVER_STATE ((uint8)0x10U)
/** \brief Invalid mode param.*/
#define WDG_E_PARAM_MODE ((uint8)0x11U)
/** \brief Invalid config param.*/
#define WDG_E_PARAM_CONFIG ((uint8)0x12U)
/** \brief Invalid timeout value.*/
#define WDG_E_PARAM_TIMEOUT ((uint8)0x13U)
/** \brief Invalid NULL ptr param.*/
#define WDG_E_PARAM_POINTER ((uint8)0x14U)
/** \brief Invalid Configuration set selection.*/
#define WDG_E_INIT_FAILED ((uint8)0x15U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief WDG driver object structure */
typedef struct
{
    /** \brief Fast Mode settings */
    Wdg_ModeInfoType Wdg_FastModeCfg;
    /** \brief Slow mode config */
    Wdg_ModeInfoType Wdg_SlowModeCfg;
    /** \brief Mode type value : Fast, slow or Off mode */
    WdgIf_ModeType   Wdg_PreviousMode;
} Wdg_DriverObjType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

#if (STD_ON == WDG_GET_VERSION_INFO_API)
/** \brief This service returns the version information of WDG module
 *
 * \param[in] Versioninfo - Pointer to store the WDG driver version information.
 * \pre This API is available only if WDG_GET_VERSION_INFO_API is STD_ON
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, WDG_CODE)
Wdg_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) Versioninfo);
#endif /* WDG_GET_VERSION_INFO_API */

/** \brief This service initializes the WDG driver
 *
 * This API is used to configure WDG Mode settings Pre-divider and Pre-scalers etc.
 *
 * \param[in] CfgPtr - Pointer to WDG driver configuration set.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, WDG_CODE) Wdg_Init(P2CONST(Wdg_ConfigType, WDG_CONFIG_DATA, WDG_CONFIG_DATA) CfgPtr);

/** \brief Switches the watchdog into Mode type off mode, slow mode, fast mode
 *
 * \param[in] Mode One of the following statically configured modes OFF_MODE, SLOW_MODE, FAST_MODE
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted.
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) Mode);

/** \brief Sets the timeout value for the trigger counter
 *
 * \param[in] Timeout Timeout value (milliseconds) for setting the trigger counter
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, WDG_CODE) Wdg_SetTriggerCondition(VAR(uint16, AUTOMATIC) Timeout);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* WDG_H */
/*********************************************************************************************************************
 *  End of File: Wdg.h
 *********************************************************************************************************************/
