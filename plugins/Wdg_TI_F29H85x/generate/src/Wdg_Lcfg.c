[!SKIPFILE "node:value(as:modconf('Wdg')[as:path(node:dtos(.))='/TI_F29H85x/Wdg']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantLinkTime'"!]
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
 *  File:       Wdg_Lcfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated Link Time configuration data                                          
 *********************************************************************************************************************/

 /*
 * Design: MCAL-25216
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25218
 */
#include "Wdg.h"

#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * AUTOSAR version information check.
 *********************************************************************************************************************/
#if ((WDG_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (WDG_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Wdg_Lcfg.c and Wdg.h are inconsistent!"
#endif

#if ((WDG_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (WDG_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Wdg_Lcfg.c and Wdg_Cfg.h are inconsistent!"
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
 /*
 * Design: MCAL-25278, MCAL-25279, MCAL-25280, MCAL-25284, MCAL-25285, MCAL-25286, MCAL-25287
 * Design: MCAL-25297, MCAL-25298, MCAL-25299, MCAL-25300
 */
[!SELECT "as:modconf('Wdg')[as:path(node:dtos(.))='/TI_F29H85x/Wdg']"!]
CONST(Wdg_ConfigType, WDG_CONFIG_DATA) Wdg_Config =
{
    .Wdg_DefaultMode    = ((WdgIf_ModeType) [!"WdgSettingsConfig/WdgDefaultMode"!]),
    .Wdg_InstanceId     = ((uint16) [!"num:i(WdgGeneral/WdgIndex)"!]U),
    .Wdg_InitialTimeOut = ((uint16) [!"num:i(WdgGeneral/WdgInitialTimeout * 1000)"!]U),
    .Wdg_MaxTimeOut     = ((uint16) [!"num:i(WdgGeneral/WdgMaxTimeout * 1000)"!]U),
    .Wdg_FastModeCfg    =
   {
      .Reaction   = ((Wdg_Reaction) [!"WdgSettingsConfig/WdgSettingsFast/WdgReaction "!]),
      .Threshold  = ((uint16) [!"WdgSettingsConfig/WdgSettingsFast/WdgThresholdValue"!]U), 
      .PreDivider = ((Wdg_PreDivider) [!"WdgSettingsConfig/WdgSettingsFast/WdgPredivider"!]),
      .PreScaler  = ((Wdg_PreScaler) [!"WdgSettingsConfig/WdgSettingsFast/WdgPrescaler"!]),
      .Timeout  = ((uint16) [!"num:i(WdgSettingsConfig/WdgSettingsFast/WdgTimeout)"!]U),
   },
   .Wdg_SlowModeCfg    =
   {
      .Reaction   = ((Wdg_Reaction) [!"WdgSettingsConfig/WdgSettingsSlow/WdgReaction"!]),
      .Threshold  = ((uint16) [!"WdgSettingsConfig/WdgSettingsSlow/WdgThresholdValue"!]U),
      .PreDivider = ((Wdg_PreDivider) [!"WdgSettingsConfig/WdgSettingsSlow/WdgPredivider"!]),
      .PreScaler  = ((Wdg_PreScaler) [!"WdgSettingsConfig/WdgSettingsSlow/WdgPrescaler"!]),
      .Timeout  = ((uint16) [!"num:i(WdgSettingsConfig/WdgSettingsSlow/WdgTimeout)"!]U),	   
   },
};
[!ENDSELECT!]

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
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Wdg_Lcfg.c
 *********************************************************************************************************************/