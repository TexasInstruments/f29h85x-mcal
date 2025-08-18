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
 *  File:       Os_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  Os configuration header file.
 *********************************************************************************************************************/
#ifndef OS_CFG_H
#define OS_CFG_H

#include "Std_Types.h"
#include "Mcal_Lib_Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#define OS_CFG_MAJOR_VERSION                 ([!"substring-before($moduleSoftwareVer,'.')"!]U)
#define OS_CFG_MINOR_VERSION                 ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
#define OS_CFG_PATCH_VERSION                 ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)

[!SELECT "as:modconf('Os')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/Os']"!][!//
#define OS_PRE_COMPILE_VARIANT   [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define OS_POST_BUILD_VARIANT    [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define OS_CFG_MAX_ISR          ([!"num:i(count(OsIsr/*))"!]U)

#define OS_CFG_MAX_COUNTER      [!IF "OsCounter/*[1]/OsCounterEnable = 'true'"!]([!"num:i(count(OsCounter/*))"!]U)[!ELSE!](0U)[!ENDIF!]

#define OS_COUNTER_ENABLE       [!IF "OsCounter/*[1]/OsCounterEnable = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#define RTINT_THRESHOLD          ([!"num:i(Os_ConfigSet/OsRtIntThreshold)"!]U)

[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!][!//
[!LOOP "Os_ConfigSet"!][!//
#define OS_INIT_CONFIG_PC       [!"@name"!]
[!ENDLOOP!][!//
[!ENDIF!][!//

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
[!LOOP "OsIsr/*"!][!//
[!IF "OsIsrCategory = 'CATEGORY_1'"!][!//
[!IF "node:value(InteruptPriority) < as:modconf('Os')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/Os']/Os_ConfigSet/OsRtIntThreshold"!][!//
/* Category 1 INT ISR function prototype. */
MCAL_LIB_RTINT_ISR([!"ISRFunc"!]);

[!ELSE!][!//
/* Category 1 RTINT ISR function prototype. */
MCAL_LIB_INT_ISR([!"ISRFunc"!]); 

[!ENDIF!][!//
[!ELSE!][!//v
/* Category 2 ISR function prototype. */
void ISR_[!"ISRFunc"!](void); 
MCAL_LIB_INT_ISR(Os_Isr[!"InterruptId"!]);

[!ENDIF!][!//
[!ENDLOOP!][!//

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

[!LOOP "Os_ConfigSet"!][!//
extern const struct Os_ConfigType_s [!"@name"!];
[!ENDLOOP!][!//
[!ENDSELECT!][!//

#ifdef __cplusplus
}
#endif

#endif /* OS_CFG_H */
/*********************************************************************************************************************
 *  End of File: Os_Cfg.h
 *********************************************************************************************************************/
