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
 *  File:       Port.c
 *
 *  Description:  This file contains Interface and services for Port Driver
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 * Design: MCAL-22309
 */
#include "Port.h"
#include "Port_Priv.h"
#include "SchM_Port.h"

#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Other Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*
 *  AUTOSAR version information check has to match definition in header file
 */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (PORT_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (PORT_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "PORT: AUTOSAR Version Numbers of PORT are different"
#endif

/* vendor specific version information is BCD coded */
#if ((PORT_SW_MAJOR_VERSION != (1U)) || (PORT_SW_MINOR_VERSION != (1U)))
#error "Version numbers of Port.c and Port.h are inconsistent!"
#endif

#if ((PORT_CFG_MAJOR_VERSION != (1U)) || (PORT_CFG_MINOR_VERSION != (1U)))
#error "Version numbers of Port.c and Port_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
#define PORT_START_SEC_VAR_INIT_PTR
#include "Port_MemMap.h"
/* Global configuration structure object */
static P2CONST(Port_ConfigType, PORT_CONFIG_DATA, PORT_CONFIG_DATA) Port_ConfigObj = NULL_PTR;
#define PORT_STOP_SEC_VAR_INIT_PTR
#include "Port_MemMap.h"

#define PORT_START_SEC_VAR_INIT_BOOLEAN
#include "Port_MemMap.h"
#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
/* Global Init Done flag  */
static VAR(boolean, PORT_VAR_INIT) Port_InitDone = (boolean)FALSE;

/* Global Commit Done flag  */
static VAR(boolean, PORT_VAR_INIT) Port_CommitDone = (boolean)FALSE;
#endif

#define PORT_STOP_SEC_VAR_INIT_BOOLEAN
#include "Port_MemMap.h"
/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/** \brief Initialzes all the pins passed in pin configuration.
 *
 * This function initialzes all the pins passed in pin configuration
 *
 * \param[in] Port_ConfigObject is the pointer to the pin config structure.
 * \param[out] returnvalue
 * \pre None
 * \post None
 * \return returnValue
 * \retval E_OK if Init success
 * \retval E_NOT_OK if Init Fails
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, PORT_CODE)
    Port_InitInternal(P2CONST(Port_ConfigType, AUTOMATIC, PORT_CONFIG_DATA) Port_ConfigObject);

#if (STD_ON == PORT_CFG_SET_PIN_DIRECTION_API)
/** \brief Port_SetPinDirectionDetCheck - This API will check for DET errors in
 *Port_SetPinDirection() API.
 *
 * \param[in] Pin Pin ID whose direction needs to be changed.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, PORT_CODE) Port_SetPinDirectionDetCheck(VAR(Port_PinType, AUTOMATIC) Pin);
#endif

#if (STD_ON == PORT_CFG_SET_PIN_MODE_API)
/** \brief Port_SetPinModeInitAndCommitCheck - This API will check for Port Init Done and Commit
 *Done for Port_SetPinMode() API.
 *
 * \param[in] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, PORT_CODE) Port_SetPinModeInitAndCommitCheck(void);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*
 * Design:
 * MCAL-22340,MCAL-22341,MCAL-22342,MCAL-22343,MCAL-22344,MCAL-22345,MCAL-22349,MCAL-22350,MCAL-22351,
 * Design:
 * MCAL-22352,MCAL-22353,MCAL-22354,MCAL-22364,MCAL-22329,MCAL-22328,MCAL-22313,MCAL-22314,MCAL-22315,
 * Design: MCAL-22317,MCAL-22321,MCAL-22322,MCAL-22323,MCAL-22326,MCAL-22346,MCAL-22347,MCAL-22348
 */
FUNC(void, PORT_CODE) Port_Init(P2CONST(Port_ConfigType, AUTOMATIC, PORT_CONFIG_DATA) CfgPtr)
{
    /* Local Config pointer initialised with NULL_PTR */
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_CONFIG_DATA) config_ptr = NULL_PTR;
    VAR(Std_ReturnType, AUTOMATIC) returnValue                       = (Std_ReturnType)E_OK;

#if (STD_ON == PORT_CFG_PRE_COMPILE_VARIANT)
    if (NULL_PTR == CfgPtr)
    {
        config_ptr = &Port_PortConfigSet;
    }
#else
    if (NULL_PTR != CfgPtr)
    {
        /* Assigning passed module configuration to Config pointer incase of Post Build variant */
        config_ptr = CfgPtr;
    }
#endif /*PORT_CFG_PRE_COMPILE_VARIANT*/

    if (NULL_PTR == config_ptr)
    {
#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
        /*
         * Call of Error hook if parameter refers to NULL.
         */
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_INIT, PORT_E_INIT_FAILED);
#endif /*(STD_ON == PORT_CFG_DEV_ERROR_DETECT)*/
    }
    else
    {
        /* Save the pointer to configuration */
        Port_ConfigObj = config_ptr;

        /*
         * Initialize all ports and port pins
         */
        returnValue = Port_InitInternal(Port_ConfigObj);

        if (returnValue == (Std_ReturnType)E_OK)
        {
#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
            Port_InitDone = TRUE;
#endif /*PORT_CFG_DEV_ERROR_DETECT*/
        }
        else
        {
#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
            (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_INIT, PORT_E_INIT_FAILED);
#endif /*PORT_CFG_DEV_ERROR_DETECT*/
        }
    }
}

/*
 * Design: MCAL-22355,MCAL-22356,MCAL-22357,MCAL-22318,MCAL-22319,MCAL-22364,MCAL-22329
 */
#if (STD_ON == PORT_CFG_SET_PIN_DIRECTION_API)
FUNC(void, PORT_CODE) Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue                         = (Std_ReturnType)E_NOT_OK;
    P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig = NULL_PTR;
    VAR(Std_ReturnType, AUTOMATIC) det_return_value                    = (Std_ReturnType)E_NOT_OK;

    det_return_value = Port_SetPinDirectionDetCheck(Pin);

    if (((Std_ReturnType)E_OK) == det_return_value)
    {
        /* Map Pin Index to the Pin Configuration Port_MapPinIdToCfg(Pin) */
        pinConfig = &Port_ConfigObj->Port_PinConfig[Pin];

        SchM_Enter_Port_PORT_EXCLUSIVE_AREA_0();
        returnValue = Port_SetDirectionMode(pinConfig, Direction);
        SchM_Exit_Port_PORT_EXCLUSIVE_AREA_0();

        if (E_NOT_OK == returnValue)
        {
#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
            /*
             * Report a Det error if Pin direction is unchangeable.
             */
            (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_SET_PIN_DIR,
                                  PORT_E_DIRECTION_UNCHANGEABLE);
#endif /*PORT_CFG_DEV_ERROR_DETECT*/
        }
    }
}
#endif

/*
 * Design: MCAL-22359,MCAL-22358,MCAL-22320,MCAL-22364,MCAL-22329
 */
FUNC(void, PORT_CODE) Port_RefreshPortDirection(void)
{
    VAR(Port_PinType, AUTOMATIC) loop                                  = (Port_PinType)0;
    P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig = NULL_PTR;

#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
    /*
     * Check if module has been initialized.
     */
    if ((boolean)FALSE == Port_InitDone)
    {
        /*
         * Report a Det error if Port as not been initialized.
         */
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_REFRESH_PORT_DIR, PORT_E_UNINIT);
    }
    else
#endif /*PORT_CFG_DEV_ERROR_DETECT*/
    {
        for (loop = ((Port_PinType)0U); loop < Port_ConfigObj->Port_NumberOfPortPins; loop++)
        {
            pinConfig = &Port_ConfigObj->Port_PinConfig[loop];

            if ((boolean)FALSE == pinConfig->Port_DirectionChangeable)
            {
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_0();
                (void)Port_SetDirectionMode(pinConfig, pinConfig->Port_PinDirection);
                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_0();
            }
        }
    }
}

#if (STD_ON == PORT_CFG_GET_VERSION_INFO_API)
/*
 * Design: MCAL-22360,MCAL-22405,MCAL-22364,MCAL-22329
 */
FUNC(void, PORT_CODE) Port_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_GET_VERSION_INFO, PORT_E_PARAM_POINTER);
    }
    else
#endif
    {
        versioninfo->vendorID         = (PORT_VENDOR_ID);
        versioninfo->moduleID         = (PORT_MODULE_ID);
        versioninfo->sw_major_version = (uint8)(PORT_SW_MAJOR_VERSION);
        versioninfo->sw_minor_version = (uint8)(PORT_SW_MINOR_VERSION);
        versioninfo->sw_patch_version = (uint8)(PORT_SW_PATCH_VERSION);
    }
}
#endif

/*
 *Design: MCAL-22361,MCAL-22362,MCAL-22363,MCAL-22364,MCAL-22329,MCAL-22364,MCAL-22329
 */
#if (STD_ON == PORT_CFG_SET_PIN_MODE_API)
FUNC(void, PORT_CODE) Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
    P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig;
    VAR(Port_PinType, AUTOMATIC) NumberOfPortPins = Port_ConfigObj->Port_NumberOfPortPins;
    VAR(Std_ReturnType, AUTOMATIC) validConfig    = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) errId                   = 0U;

    /*
     * Check if module has been initialized and configurations as not committed.
     */
    if (((Std_ReturnType)E_OK) == Port_SetPinModeInitAndCommitCheck())
    {
        /* Map the Pin Index to Pin configuration Port_MapPinIdToCfg(Pin) */
        if (Pin < NumberOfPortPins)
        {
            pinConfig = &Port_ConfigObj->Port_PinConfig[Pin];
        }
        else
        {
            pinConfig = NULL_PTR;
        }

        if (pinConfig == NULL_PTR)
        {
#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
            /* Report DET error if pin config is NULL */
            (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_SET_PIN_MODE, PORT_E_PARAM_PIN);
#endif
        }
        else
        {
            validConfig = Port_ValidateSetPinMode(Mode, pinConfig, &errId);
            if (((Std_ReturnType)E_NOT_OK) == validConfig)
            {
#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
                (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_SET_PIN_MODE, errId);
#endif
            }
            else
            {
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_0();

#if (STD_ON == PORT_CONFIGURATION_LOCK_CRITICAL_REGISTERS)
                Port_UnlockConfiguration(pinConfig);
#endif

                Port_SetPinModeConfig(Mode);

#if (STD_ON == PORT_CONFIGURATION_LOCK_CRITICAL_REGISTERS)
                Port_LockConfiguration(pinConfig);
#endif

                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_0();
            }
        }
    }
}
#endif

/*
 *Design: MCAL-29442
 */
FUNC(void, PORT_CODE) Port_CommitConfiguration(void)
{
    P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig = NULL_PTR;
    VAR(Port_PinType, AUTOMATIC) pinNumber                             = 0U;
    VAR(Port_PinType, AUTOMATIC) loop                                  = (Port_PinType)0U;

#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
    /*
     * Check if module has been initialized.
     */
    if ((boolean)FALSE == Port_InitDone)
    {
        /*
         *Report error to an Error hook function.
         */
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_COMMIT_CONFIGURATION, PORT_E_UNINIT);
    }
    else
#endif
    {
        for (loop = ((Port_PinType)0U); loop < Port_ConfigObj->Port_NumberOfPortPins; loop++)
        {
            pinConfig = &Port_ConfigObj->Port_PinConfig[loop];
            pinNumber = pinConfig->Port_PinId;
            Port_CommitConfigurationProcess(pinNumber);
        }

#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
        /* Update Commit Flag to TRUE */
        Port_CommitDone = TRUE;
#endif
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, PORT_CODE)
    Port_InitInternal(P2CONST(Port_ConfigType, AUTOMATIC, PORT_CONFIG_DATA) Port_ConfigObject)
{
    VAR(Port_PinType, AUTOMATIC) loop                                  = (Port_PinType)0U;
    P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pinConfig = NULL_PTR;
    VAR(Std_ReturnType, AUTOMATIC) returnValue                         = (Std_ReturnType)E_OK;

#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
    /*
     * Check if module has been initialized.
     */
    if ((boolean)TRUE == Port_CommitDone)
    {
        returnValue = E_NOT_OK;
    }
    else
#endif
    {
        for (loop = ((Port_PinType)0U); loop < Port_ConfigObject->Port_NumberOfPortPins; loop++)
        {
            pinConfig = &Port_ConfigObject->Port_PinConfig[loop];

            if ((boolean)TRUE == PORT_IS_PIN_CONFIGURABLE(pinConfig))
            {
#if (STD_ON == PORT_CONFIGURATION_LOCK_CRITICAL_REGISTERS)
                Port_UnlockConfiguration(pinConfig);
#endif

                returnValue |= Port_SetCntSpConfig(pinConfig);

#if (STD_ON == PORT_CONFIGURATION_LOCK_CRITICAL_REGISTERS)
                Port_LockConfiguration(pinConfig);
#endif

                returnValue |= Port_SetPinLevel(pinConfig, pinConfig->Port_PinLevelValue);

                returnValue |= Port_SetDirectionMode(pinConfig, pinConfig->Port_PinDirection);

                returnValue |= Port_EnableLPMWakeUpPin(pinConfig);
            }
            else
            {
                /* Do Nothing */
            }
        }
    }

    return returnValue;
}

#if (STD_ON == PORT_CFG_SET_PIN_DIRECTION_API)
static FUNC(Std_ReturnType, PORT_CODE) Port_SetPinDirectionDetCheck(VAR(Port_PinType, AUTOMATIC) Pin)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_OK;

#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
    P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) pin_config = NULL_PTR;
    /*
     * Check if module has been initialized.
     */
    if ((boolean)FALSE == Port_InitDone)
    {
        /*
         * Report a Det error if Port as not been initialized.
         */
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_SET_PIN_DIR, PORT_E_UNINIT);
        return_value = E_NOT_OK;
    }

    else if (Pin >= Port_ConfigObj->Port_NumberOfPortPins)
    {
        /*
         * Report a Det error if Pin is invalid.
         */
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_SET_PIN_DIR, PORT_E_PARAM_PIN);
        return_value = E_NOT_OK;
    }
    else
    {
        /* Map Pin Index to the Pin Configuration Port_MapPinIdToCfg(Pin) for DET Check*/
        pin_config = &Port_ConfigObj->Port_PinConfig[Pin];

        if (FALSE == pin_config->Port_DirectionChangeable)
        {
            /*
             * Report a Det error if Pin direction is unchangeable.
             */
            (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_SET_PIN_DIR,
                                  PORT_E_DIRECTION_UNCHANGEABLE);
            return_value = E_NOT_OK;
        }
        else
        {
            /* Do Nothing */
        }
    }

#endif

    return return_value;
}
#endif

#if (STD_ON == PORT_CFG_SET_PIN_MODE_API)
static FUNC(Std_ReturnType, PORT_CODE) Port_SetPinModeInitAndCommitCheck(void)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_OK;

#if (STD_ON == PORT_CFG_DEV_ERROR_DETECT)
    /*
     * Check if module has been initialized.
     */
    if ((boolean)FALSE == Port_InitDone)
    {
        /*
         *Report error to an Error hook function.
         */
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_SET_PIN_MODE, PORT_E_UNINIT);

        return_value = E_NOT_OK;
    }

    /*
     * Check if configurations has been committed.
     */
    else if ((boolean)TRUE == Port_CommitDone)
    {
        /*
         *Report error to an Error hook function.
         */
        (void)Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SID_COMMIT_CONFIGURATION,
                              PORT_E_MODE_UNCHANGEABLE);
        return_value = E_NOT_OK;
    }
    else
    {
        /* Do Nothing */
    }
#endif
    return return_value;
}
#endif

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Port.c
 *********************************************************************************************************************/
