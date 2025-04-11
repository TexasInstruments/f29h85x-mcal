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
 *  File:       Cdd_Sent_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Sent.h"
#include "hw_sent.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_SENT_SW_MAJOR_VERSION != (1U)) || (CDD_SENT_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Sent_cfg.c and Cdd_Sent.h are inconsistent!"
#endif

#if ((CDD_SENT_CFG_MAJOR_VERSION != (1U)) || (CDD_SENT_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Sent_cfg.c and Cdd_Sent_Cfg.h are inconsistent!"
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
 * Local Object Definitions
 *********************************************************************************************************************/
#define CDD_SENT_START_SEC_CONFIG_DATA
#include "Cdd_Sent_MemMap.h"

/* Channel Config structures*/
[!LOOP "as:modconf('Cdd_Sent')[1]/CddSentConfig"!][!LOOP "CddSentController/*"!][!//
[!LOOP "CddSentChannelObject/*"!][!//

CONST(Cdd_Sent_ChannelConfigType, CDD_SENT_CONFIG_DATA) [!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!] =
{
    .Cdd_SentSensorType = (Cdd_SentSensorType )[!"CddSentSensorType"!],
    .Cdd_SentChannelType = (Cdd_SentChannelType )[!"CddSentChannelType"!],
    .EnableTimeStamp  = (boolean )[!IF "CddSentChannelType  ='FAST_CHANNEL'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .Cdd_Sent_channelID = (uint32 )[!"CddSentChannelID"!]U,
    [!IF "CddSentChannelType !='FAST_CHANNEL'"!]
    .Cdd_Sent_MessageID = (uint32 )[!"CddSentMessageID"!]U
    [!ENDIF!]

};
[!ENDLOOP!][!ENDLOOP!][!ENDLOOP!][!//

[!VAR "Index" = "0"!][!VAR "NumChannels" = "num:i(count(as:modconf('Cdd_Sent')[1]/CddSentConfig/CddSentController/*/CddSentChannelObject/*))"!]

/* List of Channel Config structures per instance */
[!LOOP "as:modconf('Cdd_Sent')[1]/CddSentConfig"!][!LOOP "CddSentController/*"!][!//

CONST(Cdd_Sent_ChannelConfigType*, CDD_SENT_CONFIG_DATA) [!"../../@name"!]_[!"@name"!]_List[[!"$NumChannels"!]] =
{
[!LOOP "CddSentChannelObject/*"!][!//
    [[!"@index"!]] = &[!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!],
[!ENDLOOP!]
};
[!ENDLOOP!][!ENDLOOP!][!//
/* CddSent HW unit structure defined here for all config sets */

/*
 * Design: MCAL-xxxxx
 */
[!LOOP "as:modconf('Cdd_Sent')[1]/CddSentConfig/CddSentController/*"!][!//

/* CddSent HW unit structure for [!"../../@name"!]_[!"@name"!]*/
CONST(Cdd_Sent_HWUnitType, CDD_SENT_CONFIG_DATA) [!"../../@name"!]_[!"@name"!] =
{
    .Cdd_SentHWUnitId = (uint8 )[!"CddSentHWUnitId"!]U,
    .Cdd_SentInstance = (Cdd_SentInstance )CDD_SENT_INSTANCE_[!"CddSentInstance"!],[!//
[!VAR "Fast_Enabled" = "0"!][!//
[!LOOP "CddSentChannelObject/*"!][!//
[!IF "CddSentChannelType ='FAST_CHANNEL'"!][!//
[!IF "CddSentSensorType ='CDD_SENT_CHANNEL_SENSOR_1'"!][!//
[!VAR "Fast_Enabled" = "1"!][!//
[!ELSEIF "CddSentSensorType ='CDD_SENT_CHANNEL_SENSOR_2'"!][!//
[!VAR "Fast_Enabled" = "2"!][!//
[!ELSEIF "CddSentSensorType ='CDD_SENT_CHANNEL_SENSOR_3'"!][!//
[!VAR "Fast_Enabled" = "3"!][!//
[!ELSEIF "CddSentSensorType ='CDD_SENT_CHANNEL_SENSOR_4'"!][!//
[!VAR "Fast_Enabled" = "4"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!]
    .Enable_Fast_Interrupt = (uint32)[!IF "$Fast_Enabled  ='1.0'"!]SENT_REINT_RFAST_S1DV_E,
[!ELSEIF "$Fast_Enabled  ='2.0'"!]SENT_REINT_RFAST_S2DV_E,
[!ELSEIF "$Fast_Enabled  ='3.0'"!]SENT_REINT_RFAST_S3DV_E,
[!ELSEIF "$Fast_Enabled  ='4.0'"!]SENT_REINT_RFAST_S4DV_E,
[!ELSE!]0,[!ENDIF!][!//
[!VAR "Slow_Enabled" = "0"!][!//
[!LOOP "CddSentChannelObject/*"!][!//
[!IF "CddSentChannelType ='SHORT_SERIAL_SLOW_CHANNEL'"!][!//
[!VAR "Slow_Enabled" = "1"!][!//
[!ELSEIF "CddSentChannelType = 'ENHANCED_SERIAL_12BIT_SLOW_CHANNEL'"!][!//
[!VAR "Slow_Enabled" = "1"!][!//
[!ELSEIF "CddSentChannelType = 'ENHANCED_SERIAL_16BIT_SLOW_CHANNEL'"!][!//
[!VAR "Slow_Enabled" = "1"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
    .Enable_Slow_Interrupt = (uint32 )[!IF "$Slow_Enabled  ='1.0'"!]SENT_REINT_RSLOW_DV_E[!ELSE!]0[!ENDIF!],
    .Cdd_SentBaseAddress = (uint32 )[!"num:inttohex(CddSentBaseAddress)"!]U,
    .Cdd_SentClockTick  = (uint32 )[!"CddSentClockTick"!]U,
    .Cdd_SentCRCType  = (Cdd_SentCRCType )[!"CddSentCRCType"!],
    .Cdd_SentCRCWidth   = (Cdd_SentCRCWidth  )[!"CddSentCRCWidth "!],
    .Cdd_SentCRCWithStatus  = (Cdd_SentCRCWithStatus )[!"CddSentCRCWithStatus"!],
    .Cdd_SentDataNibblesCount  = (Cdd_SentDataNibblesCount )[!"CddSentDataNibblesCount"!],
    .FIFOTriggerLevel  = (Cdd_SentTriggerLevel )[!"CddSentFIFOTriggerLevel"!],
    .Cdd_SentPausePulse  = (boolean )[!IF "CddSentPausePulse  ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .SyncTimeout  = (uint32 )[!"CddSentSyncTimeout"!]U,
    .AcceptErrorData  = (boolean )[!IF "CddSentAcceptErrorData  ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .GlitchFilter  = (uint8 )[!"CddSentGlitchFilter"!]U,
    .Cdd_SentChannelCount = (uint8 )[!"num:i(count(CddSentChannelObject/*))"!],
    .Cdd_SentChannelConfigList = (Cdd_Sent_ChannelConfigType** )[!"../../@name"!]_[!"@name"!]_List,
    .Cdd_SentUserCallbackFunction  = (Cdd_Sent_NotifyType) [!IF "(node:empty(CddSentUserCallbackFunction))"!]NULL_PTR[!ELSE!][!"(node:value(CddSentUserCallbackFunction))"!][!ENDIF!]
};
[!ENDLOOP!][!//

/*List of the CddSent HW unit structures */
[!LOOP "as:modconf('Cdd_Sent')[1]/CddSentConfig"!][!//

CONST(Cdd_Sent_ConfigType, CDD_SENT_CONFIG_DATA) [!"@name"!]_Cdd_SentController_List=
{
[!LOOP "CddSentController/*"!][!//
	.Cdd_Sent_HWUnit[[!"@index"!]] = (Cdd_Sent_HWUnitType* )&[!"../../@name"!]_[!"@name"!][!IF "not(node:islast())"!],[!CR!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!][!//


#define CDD_SENT_STOP_SEC_CONFIG_DATA
#include "Cdd_Sent_MemMap.h"

/*********************************************************************************************************************
 * Exported Object Definitions
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
 
/*********************************************************************************************************************
 *  End of File: Cdd_Sent_cfg.c
 *********************************************************************************************************************/
