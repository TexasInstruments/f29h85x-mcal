[!SKIPFILE "node:value(as:modconf('EcuM')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/EcuM']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPreCompile'"!]
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
 *  File:       EcuM_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data of the EcuM module.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "EcuM.h"
[!SELECT "as:modconf('EcuM')[as:path(node:dtos(.))='/AUTOSAR/EcucDefs/EcuM']"!][!//
[!LOOP "EcuMConfiguration/EcuMCommonConfiguration/EcuMDriverInitList/*"!][!//
[!IF "not(node:empty(ModuleHeaderFileName))"!][!//
#include [!"concat('&quot;',node:value(ModuleHeaderFileName),'.h&quot;')"!]
[!ENDIF!][!//
[!ENDLOOP!][!//

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
#if ((ECUM_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (ECUM_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of EcuM_Cfg.c and EcuM.h are inconsistent!"
#endif

#if ( (ECUM_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) \
    ||(ECUM_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of EcuM_Cfg.c and EcuM_Cfg.h are inconsistent!"
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

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"

[!VAR "bitset" = "0"!][!//

volatile EcuM_WakeupEventSourceType EcuM_EventRecord[ECUM_CFG_WAKEUP_EVENT_COUNT]=
{[!LOOP "EcuMConfiguration/EcuMCommonConfiguration/EcuMWakeupSource/*"!]
    [!VAR "bitset" = "bit:or(num:i($bitset),bit:bitset(0,num:i(node:value(EcuMWakeupSourceId))))"!][!//
  [[!"@index"!]] =
      {
          .source_id                  = [!"bit:bitset(0,num:i(node:value(EcuMWakeupSourceId)))"!]U,
          .wakeup_funcptr             = (EcuM_WakeupFuncPtrType)[!"EcuMWakeupSourceModuleName"!]_CheckWakeup,
      }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
};

volatile uint32 EcuM_WakeupBitSet = [!"num:i($bitset)"!];

FUNC(void, ECUM_CODE) EcuM_InitList(void)
{
[!LOOP "EcuMConfiguration/EcuMCommonConfiguration/EcuMDriverInitList/*"!][!//
    [!"ModuleFunction"!]

[!ENDLOOP!][!//
}
[!ENDSELECT!][!//

#define ECUM_STOP_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: EcuM_Cfg.c
 *********************************************************************************************************************/