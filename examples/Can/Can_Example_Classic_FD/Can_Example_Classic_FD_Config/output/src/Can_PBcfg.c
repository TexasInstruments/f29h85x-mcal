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
 *  File:       Can_PBcfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated post build configuration data
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Standard Header Files
 *********************************************************************************************************************/
#include "Can.h"

/*********************************************************************************************************************
 * Other Header Files
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 ****************************************************************************/
#if ((CAN_SW_MAJOR_VERSION != (2U)) || (CAN_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Can_PBcfg.c and Can.h are inconsistent!"
#endif

#if ((CAN_CFG_MAJOR_VERSION != (2U)) || (CAN_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Can_PBcfg.c and Can_Cfg.h are inconsistent!"
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
#define CAN_START_SEC_CONFIG_DATA
#include "Can_MemMap.h"

/* Baud Rate Structure for all configsets */

/*
 * Design: MCAL-22772,MCAL-22773,MCAL-22774,MCAL-22775,MCAL-22776,MCAL-22777,MCAL-22778,MCAL-22779,
 * Design: MCAL-22780,MCAL-22781,MCAL-22782,MCAL-22783,MCAL-22784,MCAL-22785,MCAL-22786,MCAL-22770
 */

CONST(Can_BaudConfigType, CAN_CONFIG_DATA) CanConfigSet_CanController_0_CanControllerBaudrateConfig_0 =
{
    .CanControllerBaudRateConfigID = (uint8 )0U,
    .CanControllerBaudRate = (uint16 )1000U,   /* In kbps */
    .CanControllerPropSeg = (uint8 )2U,
    .CanControllerSeg1 = (uint8 )3U,
    .CanControllerSeg2 = (uint8 )4U,
    .CanControllerSyncJumpWidth = (uint8 )4U,
    .BrpValue = (uint16 )20U,
    /* Data Phase Baud Rate */
    .BaudFdEnable = TRUE,
    .BaudFdRateConfig = {
        .CanControllerFdBaudRate = (uint16 )5000U, /* In kbps */
        .CanControllerPropSeg = (uint8 )3U,
        .CanControllerSeg1 = (uint8 )5U,

        .CanControllerSeg2 = (uint8 )7U,
        .CanControllerSyncJumpWidth = (uint8 )7U,
        .BrpValue = (uint16 )3U,
        .CanControllerTxBitRateSwitch = (boolean )FALSE,
        .TxDelayCompEnable = (boolean )FALSE,
    }
};

/*List of the Baudrate structures */

CONST(Can_BaudConfigType*, CAN_CONFIG_DATA) CanConfigSet_CanController_0_BaudRateConfigList[1]=
{
(Can_BaudConfigType* )   &CanConfigSet_CanController_0_CanControllerBaudrateConfig_0};


/*List of the Controller structures */

CONST(Can_ControllerType*, CAN_CONFIG_DATA) CanConfigSet_CanController_List[]=
{
    (Can_ControllerType* )&CanConfigSet_CanController_0};

/* List of all standard and extended filter elements for all hardware objects */
CONST(Can_HwFilterType, CAN_CONFIG_DATA) CanHardwareObject_1_CanHwFilter_0 =
{
    .CanHwFilterCode       = (uint32)0,
    .CanHwFilterMask       = {(uint32)0},
    .CanEventPin           = (Can_EventPin)CAN_EVENT_PIN_NONE,
    .CanStandardFilterType = (Can_StandardFilterType)CAN_CLASSIC_FILTER,
};


/* List of all standard and extended filter elements per hardware objects */
CONST(Can_HwFilterType*, CAN_CONFIG_DATA) CanHardwareObject_1_CanHwFilter_List[] =
{
    (Can_HwFilterType*) &CanHardwareObject_1_CanHwFilter_0,
};


/* All the Mailbox objects(MB's) will be defined here for all config sets */

/*
 * Design: MCAL-22787,MCAL-22788,MCAL-22789,MCAL-22790,MCAL-22791,MCAL-22792,MCAL-22793,MCAL-22794,
 * Design: MCAL-22795,MCAL-22796,MCAL-22797,MCAL-22798,MCAL-22799,MCAL-22800,MCAL-22801,MCAL-24209
 */

CONST(Can_MailboxType, CAN_CONFIG_DATA) CanConfigSet_CanHardwareObject_0 =
{
    .CanHandleType = (uint8 )CAN_FULL,
    .CanIdType = (Can_IdType )CAN_MIXED_ID,
    .CanObjectId = (uint16 )0U,
    .HwHandle = (Can_HwHandleType )0U, /* HwHandle */ /* Tx Message buffer number*/
    .CanHwObjectCount = (uint16 )1U,
    .CanObjectType = (Can_MailboxDirectionType )CAN_TRANSMIT,
    .CanControllerRef = (const Can_ControllerType* )&CanConfigSet_CanController_0,
    .CanHwFilterList = NULL_PTR,
    .CanFilterListCount = (uint8)0,
    .CanFdPaddingValue = (uint8 )0U,
    .CanHardwareObjectUsesPolling = (boolean )FALSE,
    .CanTriggerTransmitEnable = (boolean )FALSE,
    .CanMainFunctionRWPeriodRef = {(uint16 )CanMainFunctionRWPeriods_0},
};

CONST(Can_MailboxType, CAN_CONFIG_DATA) CanConfigSet_CanHardwareObject_1 =
{
    .CanHandleType = (uint8 )CAN_BASIC,
    .CanIdType = (Can_IdType )CAN_STANDARD_ID,
    .CanObjectId = (uint16 )1U,
    .HwHandle = (Can_HwHandleType )0U, /* HwHandle */ /* Rx FIFO number*/
    .CanHwObjectCount = (uint16 )2U,
    .CanObjectType = (Can_MailboxDirectionType )CAN_RECEIVE,
    .CanControllerRef = (const Can_ControllerType* )&CanConfigSet_CanController_0,
    .CanHwFilterList = (const Can_HwFilterType** )&CanHardwareObject_1_CanHwFilter_List,
    .CanFilterListCount = (uint8)1,
    .CanFdPaddingValue = (uint8 )0U,
    .CanHardwareObjectUsesPolling = (boolean )FALSE,
    .CanTriggerTransmitEnable = (boolean )FALSE,
    .CanMainFunctionRWPeriodRef = {(uint16 )CanMainFunctionRWPeriods_2},
};

/* List of the Mailboxes */

CONST(Can_MailboxType*, CAN_CONFIG_DATA) CanConfigSet_CanHardwareObject_List[] =
{
(Can_MailboxType* )   &CanConfigSet_CanHardwareObject_0,
   &CanConfigSet_CanHardwareObject_1};



/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*Can Config struct */
CONST(Can_ConfigType, CAN_CONFIG_DATA) Can_CanConfigSet =
{
    .CanControllerList = (const Can_ControllerType** )CanConfigSet_CanController_List,
    .MailBoxList = (const Can_MailboxType** )CanConfigSet_CanHardwareObject_List,
    .MaxMbCnt = (uint16)2U,
    .CanMaxControllerCount = (uint8 )1U,
    .MaxBaudConfigID = {
        [0] = (uint32 )0U
	},
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
	.IcomConfigurationList = (const Can_IcomConfigType** )Can_IcomConfigurationList,
#endif
   
};

#define CAN_STOP_SEC_CONFIG_DATA
#include "Can_MemMap.h"

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
 *  End of File: Can_PBcfg.c
 *********************************************************************************************************************/
