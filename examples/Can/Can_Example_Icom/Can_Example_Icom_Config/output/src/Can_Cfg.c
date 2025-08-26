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
 *  File:       Can_cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
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
 *****************************************************************************/
#if ((CAN_SW_MAJOR_VERSION != (2U)) || (CAN_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Can_cfg.c and Can.h are inconsistent!"
#endif

#if ((CAN_CFG_MAJOR_VERSION != (2U)) || (CAN_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Can_cfg.c and Can_Cfg.h are inconsistent!"
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
    .BaudFdEnable = FALSE,
};

/*List of the Baudrate structures */

CONST(Can_BaudConfigType*, CAN_CONFIG_DATA) CanConfigSet_CanController_0_BaudRateConfigList[1]=
{
(Can_BaudConfigType* )   &CanConfigSet_CanController_0_CanControllerBaudrateConfig_0};

/* Controller structure defined here for all config sets */

/*
 * Design: MCAL-22759,MCAL-22760,MCAL-22761,MCAL-22762,MCAL-22763,MCAL-22764,MCAL-22765,
 * Design: MCAL-22766,MCAL-22767,MCAL-22768,MCAL-22769,MCAL-22801,MCAL-24210,MCAL-24209,MCAL-24208,
 * Design: MCAL-24207,MCAL-24206
 */
/* Controller structure for CanConfigSet_CanController_0*/
CONST(Can_ControllerType, CAN_CONFIG_DATA) CanConfigSet_CanController_0 =
{
    .CanControllerId = (uint8 )0U,
    .CanControllerActivation = (boolean )TRUE,
    .CanControllerInstance = (Can_ControllerInstance )CAN_CONTROLLER_INSTANCE_MCAN1,
    .CanControllerBaseAddress = (uint32 )0x60020000U,
    .CanBusoffProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanRxProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanTxProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanWakeupFunctionalityAPI = (boolean )FALSE,
    .CanWakeupProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanWakeupSupport = (boolean )FALSE,
    .CanWakeupSourceRef = (EcuM_WakeupSourceType )(0U),
    .CanControllerDefaultBaudrate = (const Can_BaudConfigType* )&CanConfigSet_CanController_0_CanControllerBaudrateConfig_0,
    .BaudRateConfigList = (const Can_BaudConfigType** )CanConfigSet_CanController_0_BaudRateConfigList,
    .CanConfigParam = {
        .CanFDMode = (boolean )FALSE,
        .CanLoopbackMode = (boolean )FALSE,
        .CanTransmitPause = (boolean )FALSE,
        .CanDisableAutomaticRetransmission = (boolean )FALSE,
    }
};


/* List of Icom configuration */

/*
 * Design: MCAL-22804,MCAL-22805,MCAL-22806,MCAL-22807,MCAL-22808,MCAL-22811,MCAL-22812,MCAL-22813,MCAL-22814,
 * Design: MCAL-22815,MCAL-22816,MCAL-22817,MCAL-22818,MCAL-22819,MCAL-22820,MCAL-22801,MCAL-22822
 */
/* Icom configuration for  CanIcomConfig_0 */
CONST(Can_IcomConfigType, CAN_CONFIG_DATA) Can_CanIcomConfig_0 =
{
    .CanIcomConfigId = (IcomConfigIdType )1U,
    .CanIcomWakeOnBusOff = (boolean )TRUE,
    .RxMessageCount = (uint16 )1U,
    .CanIcomRxMessage[0] = {
        .CanIcomMessageId = (uint32 )0x100U,
        .CanIcomPayloadLengthError = (boolean )FALSE,
        .CanIcomCounterValue = (uint16 )5U,
        .CanIcomMessageIdMask = (uint32 )0xfffU,
        .SignalCount = (uint16 )5U,
        .CanIcomRxMessageSignalConfig[0] = { 
            .CanIcomSignalMask = (uint64 )18446744073709551615U,
            .CanIcomSignalOperation = (Can_Icom_signal_operation_type )EQUAL,
            .CanIcomSignalValue = (uint64 )1311768467302729063U,
        },
        .CanIcomRxMessageSignalConfig[1] = { 
            .CanIcomSignalMask = (uint64 )18446744073709551615U,
            .CanIcomSignalOperation = (Can_Icom_signal_operation_type )AND,
            .CanIcomSignalValue = (uint64 )12302652059516914909U,
        },
        .CanIcomRxMessageSignalConfig[2] = { 
            .CanIcomSignalMask = (uint64 )18446744073709551615U,
            .CanIcomSignalOperation = (Can_Icom_signal_operation_type )GREATER,
            .CanIcomSignalValue = (uint64 )18446744073709551360U,
        },
        .CanIcomRxMessageSignalConfig[3] = { 
            .CanIcomSignalMask = (uint64 )18446744073709551615U,
            .CanIcomSignalOperation = (Can_Icom_signal_operation_type )SMALLER,
            .CanIcomSignalValue = (uint64 )2U,
        },
        .CanIcomRxMessageSignalConfig[4] = { 
            .CanIcomSignalMask = (uint64 )18446744073709551615U,
            .CanIcomSignalOperation = (Can_Icom_signal_operation_type )XOR,
            .CanIcomSignalValue = (uint64 )1311768467302729063U,
        },
   },
};
/* Icom configuration for  CanIcomConfig_1 */
CONST(Can_IcomConfigType, CAN_CONFIG_DATA) Can_CanIcomConfig_1 =
{
    .CanIcomConfigId = (IcomConfigIdType )2U,
    .CanIcomWakeOnBusOff = (boolean )FALSE,
    .RxMessageCount = (uint16 )1U,
    .CanIcomRxMessage[0] = {
        .CanIcomMessageId = (uint32 )0x100U,
        .CanIcomPayloadLengthError = (boolean )FALSE,
        .CanIcomCounterValue = (uint16 )1U,
        .CanIcomMessageIdMask = (uint32 )0xfffU,
        .SignalCount = (uint16 )0U,
   },
};

/* Overall list of Icom configurations */
CONST(Can_IcomConfigType*, CAN_CONFIG_DATA) Can_IcomConfigurationList[] =
{
    (Can_IcomConfigType* )&Can_CanIcomConfig_0,
    (Can_IcomConfigType* )&Can_CanIcomConfig_1,
};


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
 * Design: MCAL-22795,MCAL-22796,MCAL-22797,MCAL-22798,MCAL-22799,MCAL-22800,MCAL-22801,MCAL-24251
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
CONST(Can_ConfigType, CAN_CONFIG_DATA) Can_Config =
{
    .CanControllerList = (const Can_ControllerType** )CanConfigSet_CanController_List,
    .MailBoxList = (const Can_MailboxType** )CanConfigSet_CanHardwareObject_List,
    .MaxMbCnt = (uint16 )2U,
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
 *  End of File: Can_cfg.c
 *********************************************************************************************************************/
