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
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
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
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_SENT_SW_MAJOR_VERSION != (2U)) || (CDD_SENT_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Sent_cfg.c and Cdd_Sent.h are inconsistent!"
#endif

#if ((CDD_SENT_CFG_MAJOR_VERSION != (2U)) || (CDD_SENT_CFG_MINOR_VERSION != (0U)))
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

/*
 * Design: MCAL-28716, MCAL-28717, MCAL-28718, MCAL-28719, MCAL-28720, MCAL-28721,
 * Design: MCAL-28722, MCAL-28723, MCAL-28724, MCAL-28725, MCAL-28726, MCAL-28727,
 * Design: MCAL-28728, MCAL-28729, MCAL-28730, MCAL-28709,
 */
/* MTP Config structures*/

/* List of MTP Config structures per instance */

CONST(Cdd_Sent_MTPConfigType*, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentController_List[0] =
{

};

/*
 * Design: MCAL-28708, MCAL-28710, MCAL-28712, MCAL-28713,MCAL-28734,MCAL-28732
 */
/* Channel Config structures*/

CONST(Cdd_Sent_ChannelConfigType, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentController_0_CddSentChannelObject_0 =
{
    .CddSentSensorType = (Cdd_SentSensorType )CDD_SENT_CHANNEL_STANDARD_SENSOR,
    .CddSentChannelType = (Cdd_SentChannelType )CDD_SENT_CHANNEL_STANDARD_SENSOR_FAST_CHANNEL,
    .CddSentPduID = Cdd_SentConf_CddSentChannelObject_CddSentChannelObject_0,

};

CONST(Cdd_Sent_ChannelConfigType, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentController_0_CddSentChannelObject_1 =
{
    .CddSentSensorType = (Cdd_SentSensorType )CDD_SENT_CHANNEL_STANDARD_SENSOR,
    .CddSentChannelType = (Cdd_SentChannelType )SHORT_SERIAL_ENHANCED_SERIAL_12BIT_SLOW_CHANNEL,
    .CddSentPduID = Cdd_SentConf_CddSentChannelObject_CddSentChannelObject_1,
    .CddSentMessageID = (uint32 )1U
};



/* Cdd_Sent HW unit structure defined here for all config sets */

CONST(Cdd_Sent_ChannelConfigType*, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentChannelObject_List[2] =
{
    [0] = &CddSentConfig_CddSentController_0_CddSentChannelObject_0,
    [1] = &CddSentConfig_CddSentController_0_CddSentChannelObject_1,

};
/* CddSent HW unit structure defined here for all config sets */

/*
 * Design: MCAL-28688, MCAL-28689, MCAL-28690, MCAL-28691, MCAL-28692, MCAL-28693,
 * Design: MCAL-28694, MCAL-28695, MCAL-28696, MCAL-28697, MCAL-28698, MCAL-28699,
 * Design: MCAL-28700, MCAL-28701, MCAL-28704, MCAL-28705, MCAL-28706, MCAL-28707,
 * Design: MCAL-28715, MCAL-28711
 */

/* CddSent HW unit structure for CddSentConfig_CddSentController_0*/
CONST(Cdd_Sent_HWUnitType, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentController_0 =
{
    .CddSentHWUnitId = (uint8 )0U,
    .CddSentInstance = (Cdd_SentInstance )CDD_SENT_INSTANCE_SENT4,
    .CddSentBaseAddress = (uint32 )0x6006b000U,
    .CddSentClockTick  = (uint32 )600U,
    .CddSentCRCType  = (Cdd_SentCRCType )CDD_SENT_CRC_RECOMENDED_2010,
    .CddSentCRCWidth   = (Cdd_SentCRCWidth  )CDD_SENT_CRC_4_BIT,
    .CddSentCRCWithStatus  = (Cdd_SentCRCWithStatus )CDD_SENT_CRC_WITH_STATUS,
    .CddSentDataNibblesCount  = (Cdd_SentDataNibblesCount )CDD_SENT_6_DATA_NIBBLES,
    .CddSentFIFOTriggerLevel  = (Cdd_SentTriggerLevel )CDD_SENT_TRIGLEV6,
    .CddSentSyncTimeout   = (uint32 )0U,
    .CddSentAcceptErrorData    = (boolean )FALSE,
    .CddSentEnableTimeStamp  = (boolean )TRUE,
    .CddSentGlitchFilter   = (uint8 )5U,
    .CddSentMTP  = (boolean )FALSE,
    .CddSentMTPChannelCount = (uint8 )0,
    .CddSentMTPConfigList = (Cdd_Sent_MTPConfigType** )CddSentConfig_CddSentController_List,    
    .CddSentChannelCount = (uint8 )2,
    .CddSentChannelConfigList = (Cdd_Sent_ChannelConfigType** )CddSentConfig_CddSentChannelObject_List,
    .CddSentUserCallbackFunction  = (Cdd_Sent_NotifyType) CddSent_Callback,
    .CddSentUserErrorCallbackFunction   = (Cdd_Sent_ErrorNotifyType) CddSent_Error_Callback
};

/*List of the CddSent HW unit structures */

CONST(Cdd_Sent_ConfigType, CDD_SENT_CONFIG_DATA) CddSentConfig_Cdd_SentController_List=
{
	.Cdd_Sent_HWUnit[0] = (Cdd_Sent_HWUnitType* )&CddSentConfig_CddSentController_0
};


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
