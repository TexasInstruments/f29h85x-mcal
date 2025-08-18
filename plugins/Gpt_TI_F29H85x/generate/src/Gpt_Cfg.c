[!SKIPFILE "as:modconf('Gpt')[as:path(node:dtos(.))='/TI_F29H85x/Gpt']/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!][!//
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
CONST(Gpt_ConfigType, GPT_CONST) Gpt_ConfigSetptr =
{
    .ChannelCfgPtr = ((Gpt_ChannelConfigType *) &Gpt_ChannelConfiguration[0]), /* Pointer to Channel Configuration. */
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