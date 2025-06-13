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
#define WDG_SW_MAJOR_VERSION (1U)
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
#define WDG_INSTANCE_ID ((uint16)0U)

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
 * \param[in] versioninfo - Pointer to store the WDG driver version information.
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
