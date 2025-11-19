[!SKIPFILE "as:modconf('Lin')[as:path(node:dtos(.))='/TI_F29H85x/Lin']/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
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
 *  File:       Lin_PBcfg.c
 *  Project:    C29x MCAL
 *  Module:     Lin Driver
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated post build configuration data
 *
 *********************************************************************************************************************/
/* ECUCs and Private Configuration JIRA IDs */
/*
 *Design: MCAL-25649,MCAL-25650,MCAL-25651,MCAL-25652,MCAL-25653,MCAL-25654,MCAL-25655,MCAL-25656,MCAL-25657,
          MCAL-25658,MCAL-25659,MCAL-25660,MCAL-25661,MCAL-25662,MCAL-25663,MCAL-25664,MCAL-25665,MCAL-25666,
          MCAL-25667,MCAL-25668,MCAL-25544,MCAL-25545,MCAL-25546
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Lin.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((LIN_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (LIN_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Lin_PBcfg.c and Lin.h are inconsistent!"
#endif

#if ((LIN_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (LIN_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
  #error "Version numbers of Lin_PBcfg.c and Lin_Cfg.h are inconsistent!"
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
#define LIN_START_SEC_CONFIG_DATA
#include "Lin_MemMap.h"

[!SELECT "as:modconf('Lin')[as:path(node:dtos(.))='/TI_F29H85x/Lin']"!]
[!AUTOSPACING!]
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!VAR "LinChannelIdIndx" = "0"!]
CONST(Lin_ConfigType, LIN_CFG) Lin_Config =
{
    [!LOOP "LinGlobalConfig/LinChannel/*"!][!IF "(num:i($LinChannelIdIndx)) != LinChannelId"!][!ERROR "Lin Channel Id should start with 0, increment by 1 and continue without any gaps"!][!ENDIF!]
    .linChannelCfg[[!"@index"!]] =
    {
	    .linControllerConfig =
	    {
		    .CntrAddr = (uint32)[!"node:value(node:ref(LinInstance)/BaseAddr)"!],
		    .IntrLineNum = [!"LinInterruptLineSelect"!],
		    .LoopbackMode = [!"LinLoopbackMode"!]
	    },
	    .linBaudConfig = 
	    {
		    .BaudRate = (uint32)[!"LinChannelBaudRate"!],
			.Prescalar = (uint32)[!"num:i(LinBaudrateConfig/LinChannelPrescalar)"!],
		    .FractionalDivider = (uint32)[!"num:i(LinBaudrateConfig/LinChannelFractionalDivider)"!]
	    },
	    .linChannelWakeupSupport = [!IF "LinChannelWakeupSupport='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .linWakeupSource = (EcuM_WakeupSourceType )([!IF "not(node:empty(LinChannelEcuMWakeupSource))"!][!"num:inttohex(bit:bitset(0, node:value(node:ref(LinChannelEcuMWakeupSource)/EcuMWakeupSourceId)), 8)"!][!ELSE!]0[!ENDIF!]U)
		
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!VAR "LinChannelIdIndx" = "$LinChannelIdIndx+1"!][!ENDLOOP!]
   
};
[!ENDIF!][!ENDSELECT!][!//
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
#define LIN_STOP_SEC_CONFIG_DATA
#include "Lin_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Lin_PBcfg.c
 *********************************************************************************************************************/
