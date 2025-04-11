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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       EcuM_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data of the EcuM module.
 *********************************************************************************************************************/
#ifndef ECUM_CFG_H
#define ECUM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
[!LOOP "as:modconf('EcuM')[1]/EcuMConfiguration/EcuMCommonConfiguration/EcuMWakeupSource/*"!][!//
[!IF "not(node:empty(EcuMWakeupSourceModuleFileName))"!][!//
#include [!"concat('&quot;',node:value(EcuMWakeupSourceModuleFileName),'.h&quot;')"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
#include "Std_Types.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#define ECUM_CFG_MAJOR_VERSION                 ([!"substring-before($moduleSoftwareVer,'.')"!]U)
#define ECUM_CFG_MINOR_VERSION                 ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
#define ECUM_CFG_PATCH_VERSION                 ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)

/* Number of wakeup events configured in EcuM wakeup source .*/
#define ECUM_CFG_WAKEUP_EVENT_COUNT     ([!"num:i(count(as:modconf('EcuM')[1]/EcuMConfiguration/EcuMCommonConfiguration/EcuMWakeupSource/*))"!]U) 

#define ECUM_PRE_COMPILE_VARIANT   [!IF "as:modconf('EcuM')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Symbolic Names for EcuM wakeup event source type Id*/
[!LOOP "as:modconf('EcuM')[1]/EcuMConfiguration/EcuMCommonConfiguration/EcuMWakeupSource/*"!][!//
#define EcuMConf_EcuMWakeupSource_[!"@name"!]       [!"EcuMWakeupSourceId"!]  /*~ASR~*/
[!ENDLOOP!][!//

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
typedef uint32 EcuM_WakeupSourceType;
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
[!LOOP "as:modconf('EcuM')[1]/EcuMConfiguration/EcuMCommonConfiguration/EcuMWakeupSource/*"!]void [!"EcuMWakeupSourceModuleName"!]_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
[!ENDLOOP!]
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* ECUM_CFG_H */
/*********************************************************************************************************************
 *  End of File: EcuM_Cfg.h
 *********************************************************************************************************************/
