[!SKIPFILE "as:modconf('Cdd_Xbar/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Xbar/Cdd']/IMPLEMENTATION_CONFIG_VARIANT != 'VariantPreCompile'"!]
/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited. This product is protected under copyright law and
 *                 trade secret law as an unpublished work.
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Xbar_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 
#include "Cdd_Xbar.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_XBAR_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_XBAR_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Cdd_Xbar.c and Cdd_Xbar.h are inconsistent!"
#endif

#if ((CDD_XBAR_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_XBAR_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Cdd_Xbar_Cfg.c and Cdd_Xbar_Cfg.h are inconsistent!"
#endif


/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* None */

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

[!AUTOSPACING!][!//

#define CDD_XBAR_START_SEC_CONFIG_DATA
#include "Cdd_Xbar_MemMap.h"

[!SELECT "as:modconf('Cdd_Xbar/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Xbar/Cdd']/CddXbarConfiguration"!]
/** \brief CDD Crossbar Configuration */
VAR(Cdd_Xbar_ConfigType, CDD_XBAR_CONFIG_DATA) Cdd_Xbar_Config = 
{
[!IF "num:i(count(CddXbarInputXbarConfig/CddXbarInputXbarInstanceConfig/*))>0"!]
  /* Design: MCAL-25701 */
    .Cdd_Xbar_InputCfg = 
    {
[!LOOP "CddXbarInputXbarConfig/CddXbarInputXbarInstanceConfig/*"!]
        {
            .inputSelect = [!"node:value(CddXbarInputXbarInput)"!],   /* Design: MCAL-25720 */
[!IF "CddXbarInputXbarInputSourceSelection = 'CDD_XBAR_GPIO_AIO'"!]
            .inputLine = [!"node:value(node:ref(text:concat(node:path(node:ref(CddXbarInputXbarInputSource)),'/PortPinId')))"!]U,    /* [!"node:value(node:ref(text:concat(node:path(node:ref(CddXbarInputXbarInputSource)),'/PortPinPeripheralInstance')))"!] */  /* Design: MCAL-25721 */
[!ELSEIF "CddXbarInputXbarInputSourceSelection = 'CDD_XBAR_LOGIC_HIGH'"!][!//
            .inputLine = 0xFFFEU,   /* LOGIC HIGH */
[!ELSEIF "CddXbarInputXbarInputSourceSelection = 'CDD_XBAR_LOGIC_LOW'"!][!//
            .inputLine = 0xFFFFU,  /* LOGIC LOW  */  /* Design: MCAL-25721 */
[!ENDIF!]
            .selectConfigLock = [!"text:toupper(CddXbarInputXbarInputSelectConfigurationLock)"!],   /* Design: MCAL-25707 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
  /* Design: MCAL-25708 */
    .outConfigLock = [!"text:toupper(CddXbarOutputXbarConfig/CddXbarOutputXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarOutputXbarConfig/CddXbarOutputXbarInstanceConfig/*))>0"!]
  /* Design: MCAL-25702 */
    .Cdd_Xbar_OutputCfg =
    {
[!LOOP "CddXbarOutputXbarConfig/CddXbarOutputXbarInstanceConfig/*/CddXbarOutputXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarOutputXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarOutputXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarOutputXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputStretchPulse = [!"../CddXbarOutputXbarOutputPulseStretch"!],    /* Design: MCAL-25719 */
            .outputInversion = [!"text:toupper(../CddXbarOutputXbarOutputInversion)"!],    /* Design: MCAL-25713 */
            .outputLatch = [!"text:toupper(../CddXbarOutputXbarOutputLatch)"!],    /* Design: MCAL-25718 */
            .outputInversionBeforeLatch = [!"text:toupper(../CddXbarOutputXbarOutputFlagConfig/CddXbarOutputXbarInversionBeforeLatch)"!],    /* Design: MCAL-25814 */
            .outputFlag = [!"../CddXbarOutputXbarOutputFlagConfig/CddXbarOutputXbarOutputLatchInitSts"!],    /* Design: MCAL-25813 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
  /* Design: MCAL-25709 */
    .epwmConfigLock = [!"text:toupper(CddXbarEpwmXbarConfig/CddXbarEpwmXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarEpwmXbarConfig/CddXbarEpwmXbarInstanceConfig/*))>0"!]
  /* Design: MCAL-25702 */
    .Cdd_Xbar_EpwmCfg =
    {
[!LOOP "CddXbarEpwmXbarConfig/CddXbarEpwmXbarInstanceConfig/*/CddXbarEpwmXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarEpwmXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarEpwmXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarEpwmXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputInversion = [!"text:toupper(../CddXbarEpwmXbarOutputInversion)"!],    /* Design: MCAL-25713 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
    /* Design: MCAL-25710 */
    .clbConfigLock = [!"text:toupper(CddXbarClbXbarConfig/CddXbarClbXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarClbXbarConfig/CddXbarClbXbarInstanceConfig/*))>0"!]
    /* Design: MCAL-25702 */
    .Cdd_Xbar_ClbCfg =
    {
[!LOOP "CddXbarClbXbarConfig/CddXbarClbXbarInstanceConfig/*/CddXbarClbXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarClbXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarClbXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarClbXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputInversion = [!"text:toupper(../CddXbarClbXbarOutputInversion)"!],    /* Design: MCAL-25713 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
    /* Design: MCAL-25711 */
    .mindbConfigLock = [!"text:toupper(CddXbarMindbXbarConfig/CddXbarMindbXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarMindbXbarConfig/CddXbarMindbXbarInstanceConfig/*))>0"!]
    /* Design: MCAL-25702 */
    .Cdd_Xbar_MindbCfg =
    {
[!LOOP "CddXbarMindbXbarConfig/CddXbarMindbXbarInstanceConfig/*/CddXbarMindbXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarMindbXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarMindbXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarMindbXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputInversion = [!"text:toupper(../CddXbarMindbXbarOutputInversion)"!],    /* Design: MCAL-25713 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
  /* Design: MCAL-25712 */
    .iclConfigLock = [!"text:toupper(CddXbarIclXbarConfig/CddXbarIclXbarConfigurationLock)"!],
[!IF "num:i(count(CddXbarIclXbarConfig/CddXbarIclXbarInstanceConfig/*))>0"!]
  /* Design: MCAL-25702 */
    .Cdd_Xbar_IclCfg =
    {
[!LOOP "CddXbarIclXbarConfig/CddXbarIclXbarInstanceConfig/*/CddXbarIclXbarInput"!] 
        {
            .input_count = (uint32)[!"num:i(count(*/CddXbarIclXbarInputLine/*))"!]U,
[!VAR "var1" = "0"!][!LOOP "*/CddXbarIclXbarInputLine/*"!]
            .inputLine[[!"num:i($var1)"!]] =  [!"node:value(.)"!],
[!VAR "var1" = "$var1+1"!]
[!ENDLOOP!]
            .outputLine = [!"../CddXbarIclXbarOutputLine"!],   /* Design: MCAL-25722 */
            .outputInversion = [!"text:toupper(../CddXbarIclXbarOutputInversion)"!],    /* Design: MCAL-25713 */
        },
[!ENDLOOP!]
    },
[!ENDIF!]
};
[!ENDSELECT!]

#define CDD_XBAR_STOP_SEC_CONFIG_DATA
#include "Cdd_Xbar_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/* None */

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Cfg.c
 *********************************************************************************************************************/
