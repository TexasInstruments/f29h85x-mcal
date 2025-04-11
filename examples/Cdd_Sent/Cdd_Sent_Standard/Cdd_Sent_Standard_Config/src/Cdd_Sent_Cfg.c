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

CONST(Cdd_Sent_ChannelConfigType, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentController_0_CddSentChannelObject_0 =
{
    .Cdd_SentSensorType = (Cdd_SentSensorType )CDD_SENT_CHANNEL_SENSOR_1,
    .Cdd_SentChannelType = (Cdd_SentChannelType )FAST_CHANNEL,
    .EnableTimeStamp  = (boolean )TRUE,
    .Cdd_Sent_channelID = (uint32 )5U,
    

};

CONST(Cdd_Sent_ChannelConfigType, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentController_0_CddSentChannelObject_1 =
{
    .Cdd_SentSensorType = (Cdd_SentSensorType )CDD_SENT_CHANNEL_SENSOR_1,
    .Cdd_SentChannelType = (Cdd_SentChannelType )SHORT_SERIAL_SLOW_CHANNEL,
    .EnableTimeStamp  = (boolean )FALSE,
    .Cdd_Sent_channelID = (uint32 )10U,
    
    .Cdd_Sent_MessageID = (uint32 )1U
    

};



/* List of Channel Config structures per instance */

CONST(Cdd_Sent_ChannelConfigType*, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentController_0_List[2] =
{
    [0] = &CddSentConfig_CddSentController_0_CddSentChannelObject_0,
    [1] = &CddSentConfig_CddSentController_0_CddSentChannelObject_1,

};
/* CddSent HW unit structure defined here for all config sets */

/*
 * Design: MCAL-xxxxx
 */

/* CddSent HW unit structure for CddSentConfig_CddSentController_0*/
CONST(Cdd_Sent_HWUnitType, CDD_SENT_CONFIG_DATA) CddSentConfig_CddSentController_0 =
{
    .Cdd_SentHWUnitId = (uint8 )0U,
    .Cdd_SentInstance = (Cdd_SentInstance )CDD_SENT_INSTANCE_SENT1,
    .Enable_Fast_Interrupt = (uint32)SENT_REINT_RFAST_S1DV_E,
    .Enable_Slow_Interrupt = (uint32 )SENT_REINT_RSLOW_DV_E,
    .Cdd_SentBaseAddress = (uint32 )0x60068000U,
    .Cdd_SentClockTick  = (uint32 )600U,
    .Cdd_SentCRCType  = (Cdd_SentCRCType )CDD_SENT_CRC_RECOMENDED_2010,
    .Cdd_SentCRCWidth   = (Cdd_SentCRCWidth  )CDD_SENT_CRC_4_BIT,
    .Cdd_SentCRCWithStatus  = (Cdd_SentCRCWithStatus )CDD_SENT_CRC_WITH_STATUS,
    .Cdd_SentDataNibblesCount  = (Cdd_SentDataNibblesCount )CDD_SENT_6_DATA_NIBBLES,
    .FIFOTriggerLevel  = (Cdd_SentTriggerLevel )CDD_SENT_TRIGLEV6,
    .Cdd_SentPausePulse  = (boolean )TRUE,
    .SyncTimeout  = (uint32 )0U,
    .AcceptErrorData  = (boolean )FALSE,
    .GlitchFilter  = (uint8 )5U,
    .Cdd_SentChannelCount = (uint8 )2,
    .Cdd_SentChannelConfigList = (Cdd_Sent_ChannelConfigType** )CddSentConfig_CddSentController_0_List,
    .Cdd_SentUserCallbackFunction  = (Cdd_Sent_NotifyType) CddSent_Callback
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
