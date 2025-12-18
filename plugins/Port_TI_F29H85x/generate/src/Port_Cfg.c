[!SKIPFILE "as:modconf('Port')[as:path(node:dtos(.))='/TI_F29H85x/Port']/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!]
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
#if ((PORT_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (PORT_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
   #error "Version numbers of Port_Cfg.c and Port.h are inconsistent!"
#endif

#if ((PORT_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (PORT_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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
[!SELECT "as:modconf('Port')[as:path(node:dtos(.))='/TI_F29H85x/Port']"!]
[!LOOP "PortConfigSet"!][!VAR "NumOfPortPin" = "0"!]
static CONST( Port_PinConfigType, PORT_CONFIG_DATA) Port_[!"@name"!]_PinConfig[[!"num:i(sum(PortContainer/*/PortNumberOfPortPins))"!]] =
{
[!LOOP "PortContainer/*/PortPin/*"!] 
   {
    /* .Port_PhysicalPinId = [!"PortPhysicalPinId"!]U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)[!IF "PortPinId='NA'"!][!ERROR "PortPinId cannot be 'NA'.This pin is not configurable"!][!ELSE!][!"PortPinId"!]U[!ENDIF!],
    .Port_PinDirection = (Port_PinDirectionType)[!"PortPinDirection"!],
    .Port_DirectionChangeable = (boolean) [!"text:toupper(PortPinDirectionChangeable)"!],
    .Port_ModeChangeable = (boolean) [!"text:toupper(PortPinModeChangeable)"!],
    .Port_PinLevelValue = (Port_PinLevelValueType)[!"PortPinLevelValue"!],
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)[!"PortAnalogMode"!],
        .Port_InitialMuxMode = (Port_PinType)[!IF "PortAnalogMode='PORT_ANALOG_DISABLED' and PortPinInitialMode='PORT_MUXMODE_NA'"!][!ERROR "PortPinInitialMode cannot be 'PORT_MUXMODE_NA' when analog mode is disabled"!]
                                             [!ELSEIF "PortAnalogMode='PORT_ANALOG_ENABLED' and PortPinInitialMode!='PORT_MUXMODE_NA'"!][!ERROR "PortPinInitialMode should be 'PORT_MUXMODE_NA' when analog mode is enabled"!]
                                             [!ELSEIF "PortAnalogMode='PORT_ANALOG_ENABLED' and PortPinInitialMode='PORT_MUXMODE_NA'"!]PORT_PIN_MUXMODE_NA[!ELSE!]PORT_PIN_[!"PortPinId"!]_[!"text:toupper(PortPinInitialMode)"!][!ENDIF!],
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
};[!LOOP "PortContainer/*"!][!VAR "Test1" = "PortNumberOfPortPins"!][!IF "PortNumberOfPortPins != 0"!][!VAR "Test2" = "num:i(count(PortPin/*))"!][!IF "num:i($Test2) != num:i($Test1)"!][!ERROR "Number of configured pins doesn't match the value configured in PortNumberOfPortPins; make sure to recalculate derivable values before code generation."!][!ENDIF!][!ELSE!][!ENDIF!][!ENDLOOP!]
[!ENDLOOP!]

[!LOOP "PortConfigSet"!]
const struct Port_ConfigType_s Port_Config = 
{
    .Port_PinConfig = (const Port_PinConfigType *)&Port_[!"@name"!]_PinConfig[0],
    .Port_NumberOfPortPins = (Port_PinType)[!"num:i($NumOfPortPin)"!]U
};
[!ENDLOOP!]
[!/* Check each group (0-7, 8-15, 16-23, etc.) for qualification period*/!][!//
[!FOR "GroupIndex" = "0" TO "31"!][!//
[!VAR "GroupStartPinId" = "$GroupIndex * 8"!][!//
[!VAR "GroupEndPinId" = "$GroupIndex * 8 + 7"!][!//
[!VAR "FirstQualPeriod" = "0"!][!//
[!VAR "IsFirstPinFound" = "0"!][!//
[!/* First pass: find the first configured pin in this group */!][!//
[!LOOP "PortConfigSet/PortContainer/*/PortPin/*"!][!//
[!IF "PortPinId != 'NA' and number(PortPinId) >= $GroupStartPinId and number(PortPinId) <= $GroupEndPinId"!][!//
[!IF "$IsFirstPinFound = 0"!][!//
[!VAR "FirstQualPeriod" = "number(PortPinQualificationPeriod)"!][!//
[!VAR "IsFirstPinFound" = "1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!/* Second pass: check all pins in this group against the first one */!][!//
[!IF "$IsFirstPinFound = 1"!][!//
[!LOOP "PortConfigSet/PortContainer/*/PortPin/*"!][!//
[!IF "PortPinId != 'NA' and number(PortPinId) >= $GroupStartPinId and number(PortPinId) <= $GroupEndPinId"!][!//
[!VAR "CurrentQualPeriod" = "number(PortPinQualificationPeriod)"!][!//
[!IF "$CurrentQualPeriod != $FirstQualPeriod"!][!//
[!ERROR "Please ensure that the PortPinQualificationPeriod is set correctly for all PortPinIds within a group. Each group of PortPinIds consists of 8 consecutive PortPinIds, starting from 0 and ending at 255."!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDFOR!]
[!ENDSELECT!][!//
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