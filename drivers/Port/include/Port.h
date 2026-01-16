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
 *  File:       Port.h
 *  Project:    C29x MCAL
 *  Module:     Port Driver
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Port Driver functions
 *********************************************************************************************************************/
/*
 *Design: MCAL-22325
 */
#ifndef PORT_H
#define PORT_H
/**
 * \defgroup PORT Port API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-22330, MCAL-22307, MCAL-22308, MCAL-22310
 */
#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Port_Pin_Map.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/*
 *Design: MCAL-23518
 */
/*****************************************************************************
 *
 * Defines for PORT Driver version used for compatibility checks.
 *
 *****************************************************************************/
/** \brief Driver Implementation Major Version. */
#define PORT_SW_MAJOR_VERSION (3U)
/** \brief Driver Implementation Minor Version. */
#define PORT_SW_MINOR_VERSION (0U)
/**  \brief Driver Implementation Patch Version. */
#define PORT_SW_PATCH_VERSION (1U)

/*****************************************************************************
 *
 * Defines for PORT Driver AUTOSAR version used for compatibility checks.
 *
 *****************************************************************************/
/** \brief AUTOSAR Major version specification implemented by PORT Driver. */
#define PORT_AR_RELEASE_MAJOR_VERSION (4U)

/** \brief AUTOSAR Minor version specification implemented by PORT Driver. */
#define PORT_AR_RELEASE_MINOR_VERSION (3U)

/** \brief AUTOSAR Patch version specification implemented by PORT Driver. */
#define PORT_AR_RELEASE_REVISION_VERSION (1U)

/*****************************************************************************
 *
 * PORT Driver ID Info.
 *
 *****************************************************************************/
/** \brief Texas Instruments Vendor ID. */
#define PORT_VENDOR_ID ((uint16)44U)
/** \brief PORT Driver Module ID. */
#define PORT_MODULE_ID ((uint16)124U)
/** \brief PORT Driver Instance ID. */
#define PORT_INSTANCE_ID ((uint8)0U)
/*****************************************************************************
 * PORT Error Codes returned by Driver functions.
 *****************************************************************************/
/*
 *Design: MCAL-22327
 */

/** \brief Invalid Port Pin ID requested. */
#ifndef PORT_E_PARAM_PIN
#define PORT_E_PARAM_PIN ((uint8)0x0AU)
#endif

/** \brief Port Pin not configured as changeable. */
#ifndef PORT_E_DIRECTION_UNCHANGEABLE
#define PORT_E_DIRECTION_UNCHANGEABLE ((uint8)0x0BU)
#endif

/** \brief API Port_Init service called with wrong parameter. */
#ifndef PORT_E_INIT_FAILED
#define PORT_E_INIT_FAILED ((uint8)0x0CU)
#endif

/** \brief API Port_SetPinMode service called when mode is unchangeable */
#ifndef PORT_E_PARAM_INVALID_MODE
#define PORT_E_PARAM_INVALID_MODE ((uint8)0x0DU)
#endif

/** \brief API Port_SetPinMode service called when mode is unchangeable */
#ifndef PORT_E_MODE_UNCHANGEABLE
#define PORT_E_MODE_UNCHANGEABLE ((uint8)0x0EU)
#endif

/** \brief API service called without module initialization. */
#ifndef PORT_E_UNINIT
#define PORT_E_UNINIT ((uint8)0x0FU)
#endif

/** \brief APIs called with a Null pointer.*/
#ifndef PORT_E_PARAM_POINTER
#define PORT_E_PARAM_POINTER ((uint8)0x10U)
#endif

/*****************************************************************************
 * PORT Service Ids.
 *
 * The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 *
 *****************************************************************************/
/*
 *Design: MCAL-23517
 */
/** \brief Service ID - Port_Init(). */
#define PORT_SID_INIT ((uint8)0x0U)
/** \brief Service ID - Port_SetPinDirection(). */
#define PORT_SID_SET_PIN_DIR ((uint8)0x1U)
/** \brief Service ID - Port_RefreshPortDirection() */
#define PORT_SID_REFRESH_PORT_DIR ((uint8)0x2U)
/** \brief Service ID - Port_GetVersionInfo(). */
#define PORT_SID_GET_VERSION_INFO ((uint8)0x3U)
/** \brief Service ID - Port_SetPinMode(). */
#define PORT_SID_SET_PIN_MODE ((uint8)0x4U)
/** \brief Service ID - Port_CommitConfiguration(). */
#define PORT_SID_COMMIT_CONFIGURATION ((uint8)0x5U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*
 *Design: MCAL-22335,MCAL-22336
 */
/** \brief Enum of Port Direction */
typedef enum
{
    /** \brief Direction IN. */
    PORT_PIN_IN,
    /** \brief Direction OUT. */
    PORT_PIN_OUT,
    /** \brief NA Direction */
    PORT_PIN_NA
} Port_PinDirectionType;

/*
 *Design: MCAL-22396
 */
/** \brief Enum of Port Pin Level. */
typedef enum
{
    /** \brief Pin Level HIGH */
    PORT_PIN_LEVEL_HIGH,
    /** \brief Pin Level LOW. */
    PORT_PIN_LEVEL_LOW,
    /** \brief Pin Level NA. */
    PORT_PIN_LEVEL_NA
} Port_PinLevelValueType;

/*
 *Design: MCAL-22333,MCAL-22334
 */
/** \brief Type for symbolic name of Port pins. */
typedef uint32 Port_PinType;

/*
 *Design:   MCAL-22337,MCAL-22338,MCAL-22339
 */
/** \brief Pin Mode type structure */
typedef uint32 Port_PinModeType;

/*
 *Design: MCAL-22705
 */
/** \brief Pin Mux Mode Config type structure */
typedef struct
{
    /** \brief Pin Mode Type */
    Port_PinModeType Port_PinMuxMode;

} Port_PinModeConfigType;

/*
 *Design:  MCAL-22403
 */
/** \brief Pin Configuration structure */

typedef struct
{
    /** \brief Identifying number of the pin */
    Port_PinType Port_PinId;

    /** \brief Pin direction. */
    Port_PinDirectionType Port_PinDirection;

    /** \brief Flag indicating if pin direction is changeable. */
    boolean Port_DirectionChangeable;

    /** \brief Flag indicating if pin Mode is changeable. */
    boolean Port_ModeChangeable;

    /** \brief Pin level value. */
    Port_PinLevelValueType Port_PinLevelValue;

    /** \brief Controller Specific Port Config */
    Port_ControllerSpecificType Port_ControllerSpecific;

    /** \brief Num of Mux Modes Selected */
    uint32 Port_NumPortMuxModes;

    /** \brief Mux configuration of pin to be used in Port_SetPinMode()  */
    Port_PinModeConfigType Port_PinMode[PORT_MAX_MUXMODE];

} Port_PinConfigType;

/** \brief PORT Module ROOT configuration */
/*
 * Design:   MCAL-22331, MCAL-22332, MCAL-22397
 */
typedef struct Port_ConfigType_s
{
    /** \brief Pointer to pin configuration structure */
    P2CONST(Port_PinConfigType, AUTOMATIC, PORT_CONFIG_DATA) Port_PinConfig;
    /** \brief Number of port pins individually configured. */
    Port_PinType Port_NumberOfPortPins;

} Port_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief  Initializes the Port Driver module
 *
 * This function is called by user to initialize the Port pins of
 * the microcontroller
 *
 * \param[in] CfgPtr is the configuration pointer for Port module.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, PORT_CODE) Port_Init(P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_DATA) CfgPtr);

#if (STD_ON == PORT_CFG_SET_PIN_DIRECTION_API)
/** \brief  Sets the port pin direction.
 *
 * This function is used to change the direction of the pin during runtime.
 *
 * \param[in] Pin is the symbolic name of the pin.
 * \param[in] Direction is the direction to which pin is to be set.
 * \pre Port_Init should be called before calling this function
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, PORT_CODE) Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/** \brief  Refreshes port direction
 *
 * This function refreshes the Port pins to their initial direction. Pins whose
 * direction can be changed during runtime are excluded from this action.
 *
 * \pre Port_Init should be called before calling this function
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, PORT_CODE) Port_RefreshPortDirection(void);

#if (STD_ON == PORT_CFG_GET_VERSION_INFO_API)
/** \brief Service to get the version information of the module.
 *
 * This service writes the version information of this module into the data
 * structure referenced by the parameter. If this parameter references
 * NULL_PTR, a development error is reported to Det. This service is only
 * available if the pre-compile configuration parameter PORT_CFG_GET_VERSION_INFO_API
 * is enabled.
 *
 * \param[out] versioninfo structure that contains the version information parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, PORT_CODE) Port_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

#if (STD_ON == PORT_CFG_SET_PIN_MODE_API)
/** \brief  Sets the port pin mode.
 *
 * This function is used to change the Mode of the pin during runtime.
 *
 * \param[in] Pin is the symbolic name of the pin.
 * \param[in] Mode is desired functionality of the Pin e.g. PORT_PIN_MODE_ADC,
 * PORT_PIN_MODE_DIO etc.
 * \pre Port_Init should be called before calling this function
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, PORT_CODE) Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);
#endif

/** \brief Commits the locked Critical Configuration registers for the current Configuration.
 *
 * This function Commits the locked Critical Configuration registers for the current Configuration
 *
 * \pre Port_Init should be called before calling this function
 * \post None
 * \return None
 * \retval None
 *
 ****************************************************************************/
FUNC(void, PORT_CODE) Port_CommitConfiguration(void);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* PORT_H */
/*********************************************************************************************************************
 *  End of File: Port.h
 *********************************************************************************************************************/
