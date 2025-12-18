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
 *  File:       Cdd_Sent_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/
 /*
 * Design: MCAL-28610
 */
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Sent.h"
#include "hw_sent.h"
#include "hw_memmap.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_SENT_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_SENT_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Cdd_Sent_cfg.c and Cdd_Sent.h are inconsistent!"
#endif

#if ((CDD_SENT_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_SENT_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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
[!SELECT "as:modconf('Cdd_Sent/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Sent/Cdd']"!]
/*
 * Design: MCAL-28716, MCAL-28717, MCAL-28718, MCAL-28719, MCAL-28720, MCAL-28721,
 * Design: MCAL-28722, MCAL-28723, MCAL-28724, MCAL-28725, MCAL-28726, MCAL-28727,
 * Design: MCAL-28728, MCAL-28729, MCAL-28730, MCAL-28709,
 */
/* MTP Config structures*/
[!LOOP "CddSentConfig"!][!LOOP "CddSentController/*"!][!//
[!LOOP "CddSentExternalDeviceConfig/*"!][!//

CONST(Cdd_Sent_MTPConfigType, CDD_SENT_CONFIG_DATA) [!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!] =
{
    .CddSentMTPSensorType  = (Cdd_SentSensorType )[!"CddSentMTPSensorType"!],
    .CddSentTriggerSource = (Cdd_SentTriggerSource )CDD_SENT_TRIGGER_[!"CddSentSensorTriggerSource"!],
    .CddSentMTPSensorEnable = (boolean )[!IF "CddSentMTPSensorEnable  ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],[!//
[!IF "CddSentMTPSensorType !='CDD_SENT_CHANNEL_BROADCAST'"!]
    .CddSentMTPSensorTimeout  = (uint32 )[!"CddSentMTPSensorTimeout"!]U,[!//
[!ENDIF!]  
	.CddSentMTPSensorPeriod = (uint16 )[!"CddSentMTPSensorPeriod"!]U,
    .CddSentMTPSensorCompare1 = (uint16 )[!"CddSentMTPSensorCompare1"!]U,
    .CddSentMTPSensorCompare2 = (uint16 )[!"CddSentMTPSensorCompare2"!]U,
    .CddSentMTPSensorCompare3 = (uint16 )[!"CddSentMTPSensorCompare3"!]U,
    .CddSentMTPSensorCompare4 = (uint16 )[!"CddSentMTPSensorCompare4"!]U,
    .CddSentMTPSensorCompare5 = (uint16 )[!"CddSentMTPSensorCompare5"!]U,
    .CddSentMTPSensorCompare6 = (uint16 )[!"CddSentMTPSensorCompare6"!]U,
    .CddSentMTPSensorCompare7 = (uint16 )[!"CddSentMTPSensorCompare7"!]U,
    .CddSentMTPSensorCompare8 = (uint16 )[!"CddSentMTPSensorCompare8"!]U,
    .CddSentMTPSensorCompare9 = (uint16 )[!"CddSentMTPSensorCompare9"!]U,[!//
[!IF "CddSentMTPSensorType !='CDD_SENT_CHANNEL_BROADCAST'"!]  
    .CddSentMTPSensorCompare10 = (uint16 )[!"CddSentMTPSensorCompare10"!]U,[!//
[!ENDIF!][!//  
[!IF "CddSentMTPSensorType  !='CDD_SENT_CHANNEL_BROADCAST'"!][!//
[!IF "contains(node:value(../../../../../CddSentGeneral/CddSentIntegrationWithAsrComStackEnable), 'true')"!][!//
[!VAR "PduID"="substring-after(node:value(CddSentMTPSensorPduID), '/CddPduRLowerLayerContribution/')"!][!//
    .CddSentMTPSensorPduID = Cdd_SentConf_CddPduRLowerLayerTxPdu_[!"$PduID"!],[!//
[!ELSE!][!//
    .CddSentMTPSensorPduID = Cdd_SentConf_CddSentExternalDeviceConfig_[!"@name"!],[!//
[!ENDIF!]
[!ENDIF!]
};
[!ENDLOOP!][!ENDLOOP!][!ENDLOOP!][!//

[!VAR "NumChannels" = "num:i(count(CddSentConfig/CddSentController/*/CddSentExternalDeviceConfig/*))"!][!//
/* List of MTP Config structures per instance */
[!LOOP "CddSentConfig"!][!LOOP "CddSentController/*"!][!//

CONST(Cdd_Sent_MTPConfigType*, CDD_SENT_CONFIG_DATA) [!"../../@name"!]_CddSentController_List[[!"$NumChannels"!]] =
{
[!LOOP "CddSentExternalDeviceConfig/*"!][!//
    [[!"@index"!]] = &[!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!],
[!ENDLOOP!]
};
[!ENDLOOP!][!ENDLOOP!][!//

/*
 * Design: MCAL-28708, MCAL-28710, MCAL-28712, MCAL-28713,MCAL-28734,MCAL-28732
 */
/* Channel Config structures*/
[!LOOP "CddSentConfig"!][!LOOP "CddSentController/*"!][!//
[!LOOP "CddSentChannelObject/*"!][!//

CONST(Cdd_Sent_ChannelConfigType, CDD_SENT_CONFIG_DATA) [!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!] =
{
    .CddSentSensorType = (Cdd_SentSensorType )[!"CddSentSensorType"!],
    .CddSentChannelType = (Cdd_SentChannelType )[!"CddSentChannelType"!],
[!IF "contains(node:value(../../../../../CddSentGeneral/CddSentIntegrationWithAsrComStackEnable), 'true')"!][!//
[!VAR "PduID"="node:value(node:ref(CddSentPduID)/CddSentPduRHandle)"!][!//
    .CddSentPduID = [!"$PduID"!],[!//
[!ELSE!][!//
    .CddSentPduID = Cdd_SentConf_CddSentChannelObject_[!"@name"!],[!//
[!ENDIF!]
[!IF "not(contains(node:value(CddSentChannelType), 'FAST_CHANNEL'))"!][!//
    .CddSentMessageID = (uint32 )[!"CddSentMessageID"!]U[!//
[!ENDIF!]
};
[!ENDLOOP!][!ENDLOOP!][!ENDLOOP!][!//

[!VAR "Index" = "0"!][!VAR "NumChannels" = "num:i(count(CddSentConfig/CddSentController/*/CddSentChannelObject/*))"!]

/* Cdd_Sent HW unit structure defined here for all config sets */
[!LOOP "CddSentConfig"!][!LOOP "CddSentController/*"!][!//

CONST(Cdd_Sent_ChannelConfigType*, CDD_SENT_CONFIG_DATA) [!"../../@name"!]_CddSentChannelObject_List[[!"$NumChannels"!]] =
{
[!LOOP "CddSentChannelObject/*"!][!//
    [[!"@index"!]] = &[!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!],
[!ENDLOOP!]
};
[!ENDLOOP!][!ENDLOOP!][!//
/* CddSent HW unit structure defined here for all config sets */

/*
 * Design: MCAL-28688, MCAL-28689, MCAL-28690, MCAL-28691, MCAL-28692, MCAL-28693,
 * Design: MCAL-28694, MCAL-28695, MCAL-28696, MCAL-28697, MCAL-28698, MCAL-28699,
 * Design: MCAL-28700, MCAL-28701, MCAL-28704, MCAL-28705, MCAL-28706, MCAL-28707,
 * Design: MCAL-28715, MCAL-28711
 */
[!LOOP "CddSentConfig/CddSentController/*"!][!//

/* CddSent HW unit structure for [!"../../@name"!]_[!"@name"!]*/
CONST(Cdd_Sent_HWUnitType, CDD_SENT_CONFIG_DATA) [!"../../@name"!]_[!"@name"!] =
{
    .CddSentHWUnitId = (uint8 )[!"CddSentHWUnitId"!]U,
    .CddSentInstance = (Cdd_SentInstance )CDD_SENT_INSTANCE_[!"node:value(node:ref(CddSentInstanceRef)/InstanceName)"!],
    .CddSentBaseAddress = [!"node:value(node:ref(CddSentInstanceRef)/BaseAddr)"!],
    .CddSentClockTick  = (uint32 )[!"CddSentClockTick"!]U,
    .CddSentCRCType  = (Cdd_SentCRCType )[!"CddSentCRCType"!],
    .CddSentCRCWidth   = (Cdd_SentCRCWidth  )[!"CddSentCRCWidth "!],
    .CddSentCRCWithStatus  = (Cdd_SentCRCWithStatus )[!"CddSentCRCWithStatus"!],
    .CddSentDataNibblesCount  = (Cdd_SentDataNibblesCount )[!"CddSentDataNibblesCount"!],
[!IF "CddSentMTP !='true'"!][!//
    .CddSentFIFOTriggerLevel  = (Cdd_SentTriggerLevel )[!"CddSentFIFOTriggerLevel"!],
[!ENDIF!][!//
    .CddSentSyncTimeout   = (uint32 )[!"CddSentSyncTimeout"!]U,
    .CddSentAcceptErrorData    = (boolean )[!IF "CddSentAcceptErrorData  ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CddSentEnableTimeStamp  = (boolean )[!IF "CddSentEnableTimeStamp ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CddSentGlitchFilter   = (uint8 )[!"CddSentGlitchFilter"!]U,
    .CddSentMTP  = (boolean )[!IF "CddSentMTP  ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CddSentMTPChannelCount = (uint8 )[!"num:i(count(CddSentExternalDeviceConfig/*))"!],
    .CddSentMTPConfigList = (Cdd_Sent_MTPConfigType** )[!"../../@name"!]_CddSentController_List,[!//
    [!IF "CddSentMTP !='false'"!]
    .CddSentGlobalWaitTime   = (uint16 )[!"CddSentGlobalWaitTime"!]U,[!//
    [!ENDIF!]
    .CddSentChannelCount = (uint8 )[!"num:i(count(CddSentChannelObject/*))"!],
    .CddSentChannelConfigList = (Cdd_Sent_ChannelConfigType** )[!"../../@name"!]_CddSentChannelObject_List,
    .CddSentUserCallbackFunction  = (Cdd_Sent_NotifyType) [!IF "(node:empty(CddSentUserCallbackFunction))"!]NULL_PTR[!ELSE!][!"(node:value(CddSentUserCallbackFunction))"!][!ENDIF!],
    .CddSentUserErrorCallbackFunction   = (Cdd_Sent_ErrorNotifyType) [!IF "(node:empty(CddSentUserErrorCallbackFunction))"!]NULL_PTR[!ELSE!][!"(node:value(CddSentUserErrorCallbackFunction))"!][!ENDIF!]
};
[!ENDLOOP!][!//

/*List of the CddSent HW unit structures */
[!LOOP "CddSentConfig"!][!//

CONST(Cdd_Sent_ConfigType, CDD_SENT_CONFIG_DATA) [!"@name"!]_Cdd_SentController_List=
{
[!LOOP "CddSentController/*"!][!//
	.Cdd_Sent_HWUnit[[!"@index"!]] = (Cdd_Sent_HWUnitType* )&[!"../../@name"!]_[!"@name"!][!IF "not(node:islast())"!],[!CR!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!][!//

[!ENDSELECT!]
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
