[!SKIPFILE "as:modconf('Gpt')[as:path(node:dtos(.))='/TI_F29H85x/Gpt']/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!][!//
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
 *  File:         Gpt_Cfg.c
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated pre compile configuration data for GPT MCAL driver
 *********************************************************************************************************************/
/*
 *Design: MCAL-22043
 */
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-22063
 */
#include "Gpt.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/** \brief Check module software version information */
#if ((GPT_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || \
     (GPT_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Module software version numbers of Gpt_Cfg.c and Gpt.h are inconsistent!"
#endif

#if ((GPT_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || \
    (GPT_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Gpt_Cfg.c and Gpt_Cfg.h are inconsistent!"
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
[!SELECT "as:modconf('Gpt')[as:path(node:dtos(.))='/TI_F29H85x/Gpt']"!][!//
/*
 *Design: MCAL-22036, MCAL-22037, MCAL-22056
 */
#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
[!LOOP "GptChannelConfigSet[1]/GptChannelConfiguration/*"!][!//
[!IF "not(node:empty(GptNotification)) and not(text:match(GptNotification,'NULL_PTR'))"!][!//
[!"concat('extern void ',GptNotification,'(void);')"!]
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "Index" = "0"!][!VAR "NumChannels" = "num:i(count(GptChannelConfigSet[1]/GptChannelConfiguration/*))"!]
/*********************************************************************************************************************
 * Object Definitions
 *********************************************************************************************************************/
/** \brief Gpt Channels Configuration parameters. */
/*
 *Design: MCAL-22085, MCAL-22086, MCAL-22050, MCAL-22051, MCAL-22052, MCAL-22053, MCAL-22054, 
 *Design: MCAL-22055, MCAL-22056, MCAL-22036, MCAL-22037, MCAL-22041
 */
static CONST(Gpt_ChannelConfigType, GPT_CONFIG_DATA) Gpt_ChannelConfiguration[[!"$NumChannels"!]] =
{[!VAR "Index" = "0"!][!// 
[!LOOP "GptChannelConfigSet[1]/GptChannelConfiguration/*"!][!//
[!WS "4"!][[!"num:i($Index)"!]] =
[!WS "4"!]{
[!WS "8"!].Gpt_ChannelId         = ((Gpt_ChannelType) [!"GptChannelId"!]U),  /* Gpt Channel ID. */
[!WS "8"!].Gpt_ChannelMode       = ((Gpt_ChannelModeType) [!"GptChannelMode"!]),  /* Gpt Channel Mode. */
[!WS "8"!].Gpt_ChannelBaseAddr   = ((Gpt_ChannelBaseAddrType) CPUTIMER[!"GptChannelId"!]_BASE),  /* Gpt Channel Base Address. */
[!WS "8"!].Gpt_PrescaleValue     = ((Gpt_PrescaleValueType) [!"GptChannelPrescaleValue"!]U),  /* Gpt Channel Prescale Value. */
[!WS "8"!].Gpt_PtrNotifyFunction = ((Gpt_NotifyType) [!IF "node:exists(GptNotification)"!][!"GptNotification"!][!ELSE!][!WS "1"!]NULL_PTR[!ENDIF!]),  /* Notification Call Back function. */
[!WS "8"!].Gpt_SimStatus         = ((Gpt_SimStatusType) [!"GptSimulationStatus"!]),  /* Gpt Channel Simulation State */
[!WS "8"!].Gpt_SimMode           = ((Gpt_SimModeType) [!"GptSimulationMode"!]),  /* Gpt Channel Simulation Mode */
[!WS "4"!]}[!IF "not(node:islast())"!],[!ENDIF!]
[!VAR "Index" = "$Index+1"!][!ENDLOOP!]
};

/** \brief Config variable to be passed to Gpt_Init API. */
/*
 *Design: MCAL-22049
 */
CONST(Gpt_ConfigType, GPT_CONST) Gpt_Config =
{
    .ChannelCfgPtr = ((const Gpt_ChannelConfigType *) &Gpt_ChannelConfiguration[0]), /* Pointer to Channel Configuration. */
};
[!ENDSELECT!]
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

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#define GPT_STOP_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Cpt_Cfg.c
 *********************************************************************************************************************/