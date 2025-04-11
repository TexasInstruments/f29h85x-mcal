[!SKIPFILE "as:modconf('Port')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!]
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
 *  File:       Port_Cfg.c
 *  Project:    C29x MCAL
 *  Module:     Port Driver
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre compile configuration data
 *
 *********************************************************************************************************************/
/* ECUCs and Private Configuration JIRA IDs */
/*
 *Design: MCAL-22366,MCAL-22367,MCAL-22368,MCAL-22373,MCAL-22374,MCAL-22375,MCAL-22376,MCAL-22377,
 *Design: MCAL-22378,MCAL-22379,MCAL-22380,MCAL-22381,MCAL-22406,MCAL-22407,MCAL-22410,MCAL-23153,
 *Design: MCAL-23154,MCAL-23155,MCAL-23156,MCAL-23157,MCAL-23158,MCAL-23159,MCAL-23160
 */

 /*
 *Design: MCAL-22408
 */
 /* PIN PACKAGE SELECTED = [!"as:modconf('Port')[1]/PortGeneral/PortDeviceVariant"!] */
 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Port.h"
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((PORT_SW_MAJOR_VERSION != (1U)) || (PORT_SW_MINOR_VERSION != (1U)))
   #error "Version numbers of Port_Cfg.c and Port.h are inconsistent!"
#endif

#if ((PORT_CFG_MAJOR_VERSION != (1U)) || (PORT_CFG_MINOR_VERSION != (1U)))
   #error "Version numbers of Port_Cfg.c and Port_Cfg.h are inconsistent!"
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
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"

[!LOOP "as:modconf('Port')[1]/PortConfigSet"!][!VAR "NumOfPortPin" = "0"!]
static CONST( Port_PinConfigType, PORT_CONFIG_DATA) Port_[!"@name"!]_PinConfig[[!"num:i(sum(PortContainer/*/PortNumberOfPortPins))"!]] =
{
[!LOOP "PortContainer/*/PortPin/*"!] 
   {
    /* .Port_PhysicalPinId = [!"PortPhysicalPinId"!]U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)[!IF "PortPinId='NA'"!]PORT_PIN_NUM_INVALID[!ELSE!][!"PortPinId"!]U[!ENDIF!],
    .Port_PinDirection = (Port_PinDirectionType)[!"PortPinDirection"!],
    .Port_DirectionChangeable = (boolean) [!"text:toupper(PortPinDirectionChangeable)"!],
    .Port_ModeChangeable = (boolean) [!"text:toupper(PortPinModeChangeable)"!],
    .Port_PinLevelValue = (Port_PinLevelValueType)[!"PortPinLevelValue"!],
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)[!"PortAnalogMode"!],
        .Port_InitialMuxMode = (Port_PinType)[!IF "PortPinId='NA' or PortPinInitialMode='PORT_MUXMODE_NA'"!]PORT_PIN_MUXMODE_NA[!ELSE!]PORT_PIN_[!"PortPinId"!]_[!"text:toupper(PortPinInitialMode)"!][!ENDIF!],
        .Port_PinPadConfig = (Port_PinPadConfigType)[!"PortPinPadConfig"!][!IF "PortPinPadConfig!= 'PORT_PIN_TYPE_NA' and PortPinPullUpConfig='true'"!]_PULLUP[!ELSE!][!ENDIF!],
        .Port_PinQualification = (Port_PinQualificationMode)[!"PortPinQualificationMode"!],
        .Port_PinQualificationPeriod = (uint32)[!"PortPinQualificationPeriod"!]U,
        .Port_CoreSelect = (Port_PinCoreSelect)[!"PortPinCoreSelect"!],
        .Port_PinConfigFlags = (Port_PinConfigFlagType)(([!IF "PortIsPinConfigurable='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
                            |([!IF "PortIsAnalogModeSupported='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
                            |([!IF "PortIsAGPIO='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
                            |([!IF "PortIsAIO='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
                            |([!IF "PortIsGPIO='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) [!"text:toupper(PortEnableWakeUpPinLPM)"!]
    },
    .Port_NumPortMuxModes = (uint32)[!"num:i(count(PortPinMode/*))"!][!VAR "PIN"= "PortPinId"!]U,
    .Port_PinMode =
    {
        [!LOOP "PortPinMode/*"!]
        [!VAR "INDEX"= "@index"!]
        [[!"$INDEX"!]] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)[!IF "node:value(.)='PORT_MUXMODE_NA'"!]PORT_PIN_MUXMODE_NA[!ELSE!]PORT_PIN_[!"$PIN"!]_[!"text:toupper(node:value(.))"!][!ENDIF!]
        },[!ENDLOOP!]
    }

   },
[!VAR "NumOfPortPin" = "$NumOfPortPin + 1"!][!ENDLOOP!]
};[!LOOP "as:modconf('Port')[1]/PortConfigSet/PortContainer/*"!][!VAR "Test1" = "PortNumberOfPortPins"!][!IF "PortNumberOfPortPins != 0"!][!VAR "Test2" = "num:i(count(PortPin/*))"!][!IF "num:i($Test2) != num:i($Test1)"!][!ERROR "Number of configured pins doesn't match the value configured in PortNumberOfPortPins; make sure to recalculate derivable values before code generation."!][!ENDIF!][!ELSE!][!ENDIF!][!ENDLOOP!]
[!ENDLOOP!]

[!LOOP "as:modconf('Port')[1]/PortConfigSet"!]
const struct Port_ConfigType_s Port_[!"@name"!] = 
{
    .Port_PinConfig = (const Port_PinConfigType *)&Port_[!"@name"!]_PinConfig[0],
    .Port_NumberOfPortPins = (Port_PinType)[!"num:i($NumOfPortPin)"!]U
};
[!ENDLOOP!]

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Port_Cfg.c
 *********************************************************************************************************************/