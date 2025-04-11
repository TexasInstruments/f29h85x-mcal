[!IF "as:modconf('Wdg')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantLinkTime'"!]
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
#if ((WDG_SW_MAJOR_VERSION != (1U)) || (WDG_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Wdg_Lcfg.c and Wdg.h are inconsistent!"
#endif

#if ((WDG_CFG_MAJOR_VERSION != (1U)) || (WDG_CFG_MINOR_VERSION != (0U)))
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
[!LOOP "as:modconf('Wdg')[1]/WdgSettingsConfig"!]
CONST(Wdg_ConfigType, WDG_CONFIG_DATA) Wdg_ConfigSetptr =
{
    .Wdg_DefaultMode    = ((WdgIf_ModeType) [!"WdgDefaultMode"!]),
    .Wdg_InstanceId     = ((uint16) [!"num:i(as:modconf('Wdg')[1]/WdgGeneral/WdgIndex)"!]U),
    .Wdg_InitialTimeOut = ((uint16) [!"num:i(as:modconf('Wdg')[1]/WdgGeneral/WdgInitialTimeout * 1000)"!]U),
    .Wdg_MaxTimeOut     = ((uint16) [!"num:i(as:modconf('Wdg')[1]/WdgGeneral/WdgMaxTimeout * 1000)"!]U),
    .Wdg_FastModeCfg    =
   {
      .Reaction   = ((Wdg_Reaction) [!"as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsFast/WdgReaction "!]),
      .Threshold  = ((uint16) [!"as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsFast/WdgThresholdValue"!]U), 
      .PreDivider = ((Wdg_PreDivider) [!"as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsFast/WdgPredivider"!]),
      .PreScaler  = ((Wdg_PreScaler) [!"as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsFast/WdgPrescaler"!]),
      .Timeout  = ((uint16) [!"num:i(as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsFast/WdgTimeout)"!]U),
   },
   .Wdg_SlowModeCfg    =
   {
      .Reaction   = ((Wdg_Reaction) [!"as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsSlow/WdgReaction"!]),
      .Threshold  = ((uint16) [!"as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsSlow/WdgThresholdValue"!]U),
      .PreDivider = ((Wdg_PreDivider) [!"as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsSlow/WdgPredivider"!]),
      .PreScaler  = ((Wdg_PreScaler) [!"as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsSlow/WdgPrescaler"!]),
      .Timeout  = ((uint16) [!"num:i(as:modconf('Wdg')[1]/WdgSettingsConfig[1]/WdgSettingsSlow/WdgTimeout)"!]U),	   
   },
};
[!ENDLOOP!]

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
 [!ELSE!]
/*
Refer Pre-Compile Variant or Post-Build Variant. */
[!ENDIF!]