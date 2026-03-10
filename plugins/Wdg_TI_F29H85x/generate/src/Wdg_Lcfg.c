[!SKIPFILE "node:value(as:modconf('Wdg')[as:path(node:dtos(.))='/TI_F29H85x/Wdg']/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantLinkTime'"!]
/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
    .Wdg_InstanceId     = ((uint8) [!"num:i(WdgGeneral/WdgIndex)"!]U),
    .Wdg_InitialTimeOut = ((uint16) [!"num:i(WdgGeneral/WdgInitialTimeout * 1000)"!]U),
    .Wdg_MaxTimeOut     = ((uint16) [!"num:i(WdgGeneral/WdgMaxTimeout * 1000)"!]U),
    .Wdg_FastModeCfg    =
   {
      .Reaction   = ((Wdg_Reaction) [!"WdgSettingsConfig/WdgSettingsFast/WdgReaction "!]),
      .Threshold  = ((uint16) [!"WdgSettingsConfig/WdgSettingsFast/WdgThresholdValue"!]U), 
      .PreDivider = ((Wdg_PreDivider) [!"WdgSettingsConfig/WdgSettingsFast/WdgPredivider"!]),
      .PreScaler  = ((Wdg_PreScaler) [!"WdgSettingsConfig/WdgSettingsFast/WdgPrescaler"!]),
      .Timeout    = ((uint16) [!"num:i(WdgSettingsConfig/WdgSettingsFast/WdgTimeout)"!]U),
   },
   .Wdg_SlowModeCfg    =
   {
      .Reaction   = ((Wdg_Reaction) [!"WdgSettingsConfig/WdgSettingsSlow/WdgReaction"!]),
      .Threshold  = ((uint16) [!"WdgSettingsConfig/WdgSettingsSlow/WdgThresholdValue"!]U),
      .PreDivider = ((Wdg_PreDivider) [!"WdgSettingsConfig/WdgSettingsSlow/WdgPredivider"!]),
      .PreScaler  = ((Wdg_PreScaler) [!"WdgSettingsConfig/WdgSettingsSlow/WdgPrescaler"!]),
      .Timeout    = ((uint16) [!"num:i(WdgSettingsConfig/WdgSettingsSlow/WdgTimeout)"!]U),	   
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