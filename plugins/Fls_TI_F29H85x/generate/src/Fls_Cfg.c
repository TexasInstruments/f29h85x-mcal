[!SKIPFILE "node:value(as:modconf('Fls')[1]/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPreCompile'"!]
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
 *  File:         Fls_Cfg.c
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated pre compile configuration file for FLS MCAL driver
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Fls.h"
#include "Fls_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 * AUTOSAR version information check has to match definition in header file.
 *********************************************************************************************************************/
#if ((FLS_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) ||\
    (FLS_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Fls_Cfg.c and Fls.h are inconsistent!"
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
 * Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Object Definitions
 *********************************************************************************************************************/
#define  FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
/* generation of runtime configuration */

#ifdef __cplusplus
extern "C" {
#endif
[!AUTOSPACING!]
/* generation of configuration data */
[!LOOP "as:modconf('Fls')[1]/FlsConfigSet"!][!//
CONST(struct Fls_ConfigType_s, FLS_CONFIG_DATA) Fls_[!"@name"!] =
{
[!WS "4"!].Fls_JobEndNotification = [!IF "(node:exists(FlsJobEndNotification))"!][!IF "node:value(FlsJobEndNotification) = 'NULL_PTR' or node:empty(FlsJobEndNotification)"!] NULL_PTR[!ELSE!](Fls_JobEndNotifyType)[!"(node:value(FlsJobEndNotification))"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!],
[!WS "4"!].Fls_JobErrorNotification = [!IF "(node:exists(FlsJobErrorNotification))"!][!IF "node:value(FlsJobErrorNotification) = 'NULL_PTR' or node:empty(FlsJobErrorNotification)"!] NULL_PTR[!ELSE!](Fls_JobErrorNotifyType)[!"(node:value(FlsJobErrorNotification))"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!],
[!WS "4"!].FlsMaxReadNormalMode = [!"FlsMaxReadNormalMode"!]U,
[!WS "4"!].FlsMaxWriteNormalMode = [!"FlsMaxWriteNormalMode"!]U, /* 8 byts or 16 bytes */
[!WS "4"!].sectorList =
[!WS "4"!]{
[!WS "4"!][!LOOP "FlsSectorList/FlsSector/*"!]
[!WS "4"!][!WS "4"!][[!"@index"!]] =
[!WS "4"!][!WS "4"!][!WS "4"!]{
[!WS "4"!][!WS "4"!][!WS "4"!][!WS "4"!].numberOfSectors = [!"FlsNumberOfSectors"!]U,
[!WS "4"!][!WS "4"!][!WS "4"!][!WS "4"!].sectorSize = [!"FlsSectorSize"!]U,
[!WS "4"!][!WS "4"!][!WS "4"!][!WS "4"!].sectorStartAddress = [!"num:i(num:i(as:modconf('Fls')[1]/FlsGeneral/FlsBaseAddress) + num:i(FlsSectorStartaddress))"!]U,
[!WS "4"!][!WS "4"!][!WS "4"!]},
[!WS "4"!][!ENDLOOP!]},
};
[!ENDLOOP!][!//

#ifdef __cplusplus
}
#endif

#define  FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * END OF FILE: Fls_Cfg.c
 *********************************************************************************************************************/
