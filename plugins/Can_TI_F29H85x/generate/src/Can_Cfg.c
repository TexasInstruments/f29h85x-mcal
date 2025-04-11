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
#if ((CAN_SW_MAJOR_VERSION != (1U)) || (CAN_SW_MINOR_VERSION != (1U)))
    #error "Version numbers of Can_cfg.c and Can.h are inconsistent!"
#endif

#if ((CAN_CFG_MAJOR_VERSION != (1U)) || (CAN_CFG_MINOR_VERSION != (1U)))
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

[!IF "as:modconf('Can')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/* Baud Rate Structure for all configsets */

/*
 * Design: MCAL-22772,MCAL-22773,MCAL-22774,MCAL-22775,MCAL-22776,MCAL-22777,MCAL-22778,MCAL-22779,
 * Design: MCAL-22780,MCAL-22781,MCAL-22782,MCAL-22783,MCAL-22784,MCAL-22785,MCAL-22786,MCAL-22770
 */
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!LOOP "CanController/*"!][!//
[!VAR "CanClock"="num:i(node:ref(CanCpuClockRef)/McuClockReferencePointFrequency)"!][!//
[!VAR "CanClock" = "num:i(num:div($CanClock, 1000))"!][!//
[!LOOP "CanControllerBaudrateConfig/*"!][!//

CONST(Can_BaudConfigType, CAN_CONFIG_DATA) [!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!] =
{
    .CanControllerBaudRateConfigID = (uint8 )[!"CanControllerBaudRateConfigID"!]U,
    .CanControllerBaudRate = (uint16 )[!"CanControllerBaudRate"!]U,   /* In kbps */
    .CanControllerPropSeg = (uint8 )[!"CanControllerPropSeg"!]U,
    .CanControllerSeg1 = (uint8 )[!"CanControllerSeg1"!]U,
[!VAR "ntseg1" = "CanControllerPropSeg + CanControllerSeg1"!][!//
[!ASSERT "num:i($ntseg1) <= 256","STOP: sum of CanControllerPropSeg and CanControllerSeg1 more than 256 for a controller is not allowed"!][!//
[!ASSERT "num:i($ntseg1) >= 2","STOP: sum of CanControllerPropSeg and CanControllerSeg1 less than 2 for a controller is not allowed"!][!//
    .CanControllerSeg2 = (uint8 )[!"CanControllerSeg2"!]U,
    .CanControllerSyncJumpWidth = (uint8 )[!"CanControllerSyncJumpWidth"!]U,
[!VAR "TimingValues" = "1 + CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2"!][!//
[!VAR "brp" = "num:i(num:add((num:div($CanClock, num:mul(CanControllerBaudRate, $TimingValues))), 0.5))"!][!//
[!ASSERT "num:i($brp) <= 512","STOP: BRP more than 512 for a controller is not allowed"!][!//
[!ASSERT "num:i($brp) >= 1","STOP: BRP less than 1 for a controller is not allowed"!][!//
    .BrpValue = (uint16 )[!"$brp"!]U,
    /* Data Phase Baud Rate */
[!VAR "BaudFD" = "0"!][!//
[!IF "node:exists(CanControllerFdBaudrateConfig)"!][!//
[!VAR "BaudFD" = "1"!][!//
[!ENDIF!][!//
[!IF "num:i($BaudFD) ='0'"!][!//
    .BaudFdEnable = FALSE,
[!ELSE!][!//
    .BaudFdEnable = TRUE,
[!ENDIF!][!//
[!IF "node:exists(CanControllerFdBaudrateConfig)"!][!//
    .BaudFdRateConfig = {
        .CanControllerFdBaudRate = (uint16 )[!"CanControllerFdBaudrateConfig/CanControllerFdBaudRate"!]U, /* In kbps */
        .CanControllerPropSeg = (uint8 )[!"CanControllerFdBaudrateConfig/CanControllerPropSeg"!]U,
        .CanControllerSeg1 = (uint8 )[!"CanControllerFdBaudrateConfig/CanControllerSeg1"!]U,
[!VAR "dtseg1" = "CanControllerFdBaudrateConfig/CanControllerPropSeg + CanControllerFdBaudrateConfig/CanControllerSeg1"!][!//
[!ASSERT "num:i($dtseg1) <= 32","STOP: sum of CanControllerPropSeg and CanControllerSeg1 more than 32 for a controller is not allowed"!][!//
[!ASSERT "num:i($dtseg1) >= 1","STOP: sum of CanControllerPropSeg and CanControllerSeg1 less than 1 for a controller is not allowed"!][!//

        .CanControllerSeg2 = (uint8 )[!"CanControllerFdBaudrateConfig/CanControllerSeg2"!]U,
        .CanControllerSyncJumpWidth = (uint8 )[!"CanControllerFdBaudrateConfig/CanControllerSyncJumpWidth"!]U,
[!VAR "TimingValues" = "1 + CanControllerFdBaudrateConfig/CanControllerPropSeg + CanControllerFdBaudrateConfig/CanControllerSeg1 + CanControllerFdBaudrateConfig/CanControllerSeg2"!][!//
[!VAR "brp" = "num:i(num:add((num:div($CanClock, num:mul(CanControllerFdBaudrateConfig/CanControllerFdBaudRate, $TimingValues))), 0.5))"!][!//
[!ASSERT "num:i($brp) <= 32","STOP: BRP more than 32 for a controller is not allowed"!][!//
[!ASSERT "num:i($brp) >= 1","STOP: BRP less than 1 for a controller is not allowed"!][!//
        .BrpValue = (uint16 )[!"$brp"!]U,
        .CanControllerTxBitRateSwitch = (boolean )[!IF "CanControllerFdBaudrateConfig/CanControllerTxBitRateSwitch='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!VAR "TxDelayComp" = "0"!][!//
[!VAR "TxDelayComp" = "1"!][!//
[!IF "node:exists(CanControllerFdBaudrateConfig/CanControllerTrcvDelayCompensationOffset)"!][!//
        .TxDelayCompEnable = (boolean )TRUE,
        .TxDelayCompFilter = (uint8 )[!"CanControllerFdBaudrateConfig/CanControllerTrcvDelayCompensationFilter"!]U,
        .CanControllerTrcvDelayCompensationOffset = (uint16 )[!"CanControllerFdBaudrateConfig/CanControllerTrcvDelayCompensationOffset"!]U,
[!ELSE!][!//
        .TxDelayCompEnable = (boolean )FALSE,
[!ENDIF!][!//
    }
[!ENDIF!][!//
};
[!ENDLOOP!][!ENDLOOP!][!ENDLOOP!][!//

/*List of the Baudrate structures */
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!LOOP "CanController/*"!][!//

CONST(Can_BaudConfigType*, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!]_BaudRateConfigList[[!"num:i(count(CanControllerBaudrateConfig/*))"!]]=
{
(Can_BaudConfigType* )[!LOOP "CanControllerBaudrateConfig/*"!][!WS "3"!]&[!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!][!IF "not(node:islast())"!],[!CR!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!][!ENDLOOP!][!//

[!ENDIF!][!//
/* Controller structure defined here for all config sets */

/*
 * Design: MCAL-22759,MCAL-22760,MCAL-22761,MCAL-22762,MCAL-22763,MCAL-22764,MCAL-22765,
 * Design: MCAL-22766,MCAL-22767,MCAL-22768,MCAL-22769,MCAL-22801,MCAL-24210,MCAL-24209,MCAL-24208,
 * Design: MCAL-24207,MCAL-24206
 */
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!LOOP "CanController/*"!][!//
/* Controller structure for [!"../../@name"!]_[!"@name"!]*/
CONST(Can_ControllerType, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!] =
{
    .CanControllerId = (uint8 )[!"CanControllerId"!]U,
    .CanControllerActivation = (boolean )[!IF "CanControllerActivation ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CanControllerInstance = (Can_ControllerInstance )CAN_CONTROLLER_INSTANCE_[!"CanControllerInstance"!],
    .CanControllerBaseAddress = (uint32 )[!"num:inttohex(CanControllerBaseAddress)"!]U,
    .CanBusoffProcessing = (Can_ProcessingType )[!IF "CanBusoffProcessing ='INTERRUPT'"!]INTERRUPT[!ELSE!]POLLING[!ENDIF!],
    .CanRxProcessing = (Can_ProcessingType )[!IF "CanRxProcessing ='INTERRUPT'"!]INTERRUPT[!ELSEIF "CanRxProcessing ='MIXED'"!]MIXED[!ELSE!]POLLING[!ENDIF!],
    .CanTxProcessing = (Can_ProcessingType )[!IF "CanTxProcessing ='INTERRUPT'"!]INTERRUPT[!ELSEIF "CanTxProcessing ='MIXED'"!]MIXED[!ELSE!]POLLING[!ENDIF!],
    .CanWakeupFunctionalityAPI = (boolean )[!IF "CanWakeupFunctionalityAPI ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CanWakeupProcessing = (Can_ProcessingType )[!IF "CanWakeupProcessing ='INTERRUPT'"!]INTERRUPT[!ELSE!]POLLING[!ENDIF!],
    .CanWakeupSupport = (boolean )[!IF "CanWakeupSupport ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CanWakeupSourceRef = (EcuM_WakeupSourceType )([!IF "not(node:empty(CanWakeupSourceRef))"!][!"num:inttohex(bit:bitset(0, node:value(node:ref(CanWakeupSourceRef)/EcuMWakeupSourceId)), 8)"!][!ELSE!]0[!ENDIF!]U),
    .CanControllerDefaultBaudrate = (const Can_BaudConfigType* )&[!"../../@name"!]_[!"@name"!]_[!"node:name(node:ref(node:current()/CanControllerDefaultBaudrate))"!],
    .BaudRateConfigList = (const Can_BaudConfigType** )[!"../../@name"!]_[!"@name"!]_BaudRateConfigList,
    .CanConfigParam = {
        .CanFDMode = (boolean )[!IF "CanControllerConfig/CanFDMode ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .CanLoopbackMode = (boolean )[!IF "CanControllerConfig/CanLoopbackMode ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .CanTransmitPause = (boolean )[!IF "CanControllerConfig/CanTransmitPause ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .CanDisableAutomaticRetransmission = (boolean )[!IF "CanControllerConfig/CanDisableAutomaticRetransmission  ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    }
};
[!ENDLOOP!][!ENDLOOP!][!//


/* List of Icom configuration */

/*
 * Design: MCAL-22804,MCAL-22805,MCAL-22806,MCAL-22807,MCAL-22808,MCAL-22811,MCAL-22812,MCAL-22813,MCAL-22814,
 * Design: MCAL-22815,MCAL-22816,MCAL-22817,MCAL-22818,MCAL-22819,MCAL-22820,MCAL-22801,MCAL-22822
 */
[!LOOP "as:modconf('Can')[1]/CanConfigSet/CanIcom/CanIcomConfig/*"!][!//
/* Icom configuration for  [!"@name"!] */
CONST(Can_IcomConfigType, CAN_CONFIG_DATA) Can_[!"@name"!] =
{
    .CanIcomConfigId = (IcomConfigIdType )[!"CanIcomConfigId"!]U,
    .CanIcomWakeOnBusOff = (boolean )[!IF "CanIcomWakeOnBusOff= 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .RxMessageCount = (uint16 )[!"num:i(count(CanIcomWakeupCauses/CanIcomRxMessage/*))"!]U,
[!LOOP "CanIcomWakeupCauses/CanIcomRxMessage/*"!][!//
    .CanIcomRxMessage[[!"@index"!]] = {
        .CanIcomMessageId = (uint32 )[!"num:inttohex(CanIcomMessageId)"!]U,
        .CanIcomPayloadLengthError = (boolean )[!IF "CanIcomPayloadLengthError= 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .CanIcomCounterValue = (uint16 )[!"CanIcomCounterValue"!]U,
        .CanIcomMessageIdMask = (uint32 )[!"num:inttohex(CanIcomMessageIdMask)"!]U,
        .SignalCount = (uint16 )[!"num:i(count(CanIcomRxMessageSignalConfig/*))"!]U,
[!LOOP "CanIcomRxMessageSignalConfig/*"!][!//        
        .CanIcomRxMessageSignalConfig[[!"@index"!]] = { 
            .CanIcomSignalMask = (uint64 )[!"CanIcomSignalMask"!]U,
            .CanIcomSignalOperation = (Can_Icom_signal_operation_type )[!"CanIcomSignalOperation"!],
            .CanIcomSignalValue = (uint64 )[!"CanIcomSignalValue"!]U,
        },
[!ENDLOOP!][!//	
   },
[!ENDLOOP!][!//
};
[!ENDLOOP!][!//

/* Overall list of Icom configurations */
CONST(Can_IcomConfigType*, CAN_CONFIG_DATA) Can_IcomConfigurationList[] =
{
[!LOOP "as:modconf('Can')[1]/CanConfigSet/CanIcom/CanIcomConfig/*"!][!//
    (Can_IcomConfigType* )&Can_[!"@name"!],
[!ENDLOOP!][!//
};


[!IF "as:modconf('Can')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/*List of the Controller structures */
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!//

CONST(Can_ControllerType*, CAN_CONFIG_DATA) [!"@name"!]_CanController_List[]=
{
[!LOOP "CanController/*"!][!//
    (Can_ControllerType* )&[!"../../@name"!]_[!"@name"!][!IF "not(node:islast())"!],[!CR!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!][!//

/* All the Mailbox objects(MB's) will be defined here for all config sets */

/*
 * Design: MCAL-22787,MCAL-22788,MCAL-22789,MCAL-22790,MCAL-22791,MCAL-22792,MCAL-22793,MCAL-22794,
 * Design: MCAL-22795,MCAL-22796,MCAL-22797,MCAL-22798,MCAL-22799,MCAL-22800,MCAL-22801,MCAL-24251
 */
[!VAR "RWFunctionList" = "0"!][!//
[!LOOP "as:modconf('Can')[1]/CanGeneral"!][!LOOP "CanMainFunctionRWPeriods/*"!][!//
[!VAR "RWFunctionList" = "$RWFunctionList+1"!][!//
[!ENDLOOP!][!ENDLOOP!][!//
[!VAR "TxCnt0" = "0"!] [!VAR "RxCnt0" = "0"!] [!VAR "TxFIFOCnt0" = "0"!][!//
[!VAR "TxCnt1" = "0"!] [!VAR "RxCnt1" = "0"!] [!VAR "TxFIFOCnt1" = "0"!][!//
[!VAR "TxCnt2" = "0"!] [!VAR "RxCnt2" = "0"!] [!VAR "TxFIFOCnt2" = "0"!][!//
[!VAR "TxCnt3" = "0"!] [!VAR "RxCnt3" = "0"!] [!VAR "TxFIFOCnt3" = "0"!][!//
[!VAR "TxCnt4" = "0"!] [!VAR "RxCnt4" = "0"!] [!VAR "TxFIFOCnt4" = "0"!][!//
[!VAR "TxCnt5" = "0"!] [!VAR "RxCnt5" = "0"!] [!VAR "TxFIFOCnt5" = "0"!][!//
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!//
[!VAR "CanObjectIdIndx" = "0"!][!//
[!LOOP "CanHardwareObject/*"!][!//

CONST(Can_MailboxType, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!] =
{
[!IF "CanHandleType ='FULL'"!][!//
    .CanHandleType = (uint8 )FULL,
[!ELSEIF "CanHwObjectCount = '1'"!][!//
[!ERROR "Basic Mode for MCAN is supported only if CanHwObjectCount > 1"!][!//
[!ELSE!][!//
    .CanHandleType = (uint8 )BASIC,
[!ENDIF!][!//
    .CanIdType = (Can_IdType )[!IF "CanIdType = 'EXTENDED'"!]EXTENDED_ID[!ELSEIF "CanIdType = 'STANDARD'"!]STANDARD_ID[!ELSE!]MIXED_ID[!ENDIF!],
[!IF "CanIdType = 'MIXED' and CanObjectType = 'RECEIVE'"!][!ERROR "CAN: Mixed mode is not supported for Receive"!][!ENDIF!][!//
    .CanObjectId = (uint16 )[!"CanObjectId"!]U,
[!IF "(num:i($CanObjectIdIndx)) != CanObjectId"!][!ERROR "Can Object Id should start with 0, increment by 1 and continue without any gaps"!][!ENDIF!][!//
[!IF "'MCAN1' = node:value(node:ref(node:current()/CanControllerRef)/CanControllerInstance)"!][!//
[!IF "CanHwObjectCount = '1'"!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($TxCnt0)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "TxCnt0" = "$TxCnt0+1"!][!//
[!IF "(num:i($TxCnt0) + num:i($TxFIFOCnt0)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ELSE!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($RxCnt0)"!]U,  /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "RxCnt0" = "$RxCnt0+1"!][!//
[!IF "(num:i($RxCnt0)) > '64'"!][!ERROR "Number of Receive mailboxes supported is 64 only"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!VAR "TxFIFOCnt0" = "$TxFIFOCnt0+node:value(CanHwObjectCount)"!][!//
[!IF "(num:i($TxCnt0) + num:i($TxFIFOCnt0)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ENDIF!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i(0)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "'MCAN2' = node:value(node:ref(node:current()/CanControllerRef)/CanControllerInstance)"!][!//
[!IF "CanHwObjectCount = '1'"!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($TxCnt1)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "TxCnt1" = "$TxCnt1+1"!][!//
[!IF "(num:i($TxCnt1) + num:i($TxFIFOCnt1)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ELSE!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($RxCnt1)"!]U,  /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "RxCnt1" = "$RxCnt1+1"!][!//
[!IF "(num:i($RxCnt1)) > '64'"!][!ERROR "Number of Receive mailboxes supported is 64 only"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!VAR "TxFIFOCnt1" = "$TxFIFOCnt1+node:value(CanHwObjectCount)"!][!//
[!IF "(num:i($TxCnt1) + num:i($TxFIFOCnt1)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ENDIF!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i(0)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "'MCAN3' = node:value(node:ref(node:current()/CanControllerRef)/CanControllerInstance)"!][!//
[!IF "CanHwObjectCount = '1'"!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($TxCnt2)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "TxCnt2" = "$TxCnt2+1"!][!//
[!IF "(num:i($TxCnt2) + num:i($TxFIFOCnt2)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ELSE!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($RxCnt2)"!]U,  /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "RxCnt2" = "$RxCnt2+1"!][!//
[!IF "(num:i($RxCnt2)) > '64'"!][!ERROR "Number of Receive mailboxes supported is 64 only"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!VAR "TxFIFOCnt2" = "$TxFIFOCnt2+node:value(CanHwObjectCount)"!][!//
[!IF "(num:i($TxCnt2) + num:i($TxFIFOCnt2)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ENDIF!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i(0)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "'MCAN4' = node:value(node:ref(node:current()/CanControllerRef)/CanControllerInstance)"!][!//
[!IF "CanHwObjectCount = '1'"!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($TxCnt3)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "TxCnt3" = "$TxCnt3+1"!][!//
[!IF "(num:i($TxCnt3) + num:i($TxFIFOCnt3)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ELSE!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($RxCnt3)"!]U,  /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "RxCnt3" = "$RxCnt3+1"!][!//
[!IF "(num:i($RxCnt3)) > '64'"!][!ERROR "Number of Receive mailboxes supported is 64 only"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!VAR "TxFIFOCnt3" = "$TxFIFOCnt3+node:value(CanHwObjectCount)"!][!//
[!IF "(num:i($TxCnt3) + num:i($TxFIFOCnt3)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ENDIF!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i(0)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "'MCAN5' = node:value(node:ref(node:current()/CanControllerRef)/CanControllerInstance)"!][!//
[!IF "CanHwObjectCount = '1'"!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($TxCnt4)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "TxCnt4" = "$TxCnt4+1"!][!//
[!IF "(num:i($TxCnt4) + num:i($TxFIFOCnt4)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ELSE!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($RxCnt4)"!]U,  /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "RxCnt4" = "$RxCnt4+1"!][!//
[!IF "(num:i($RxCnt4)) > '64'"!][!ERROR "Number of Receive mailboxes supported is 64 only"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!VAR "TxFIFOCnt4" = "$TxFIFOCnt4+node:value(CanHwObjectCount)"!][!//
[!IF "(num:i($TxCnt4) + num:i($TxFIFOCnt4)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ENDIF!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i(0)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "'MCAN6' = node:value(node:ref(node:current()/CanControllerRef)/CanControllerInstance)"!][!//
[!IF "CanHwObjectCount = '1'"!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($TxCnt5)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "TxCnt5" = "$TxCnt5+1"!][!//
[!IF "(num:i($TxCnt5) + num:i($TxFIFOCnt5)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ELSE!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i($RxCnt5)"!]U,  /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!VAR "RxCnt5" = "$RxCnt5+1"!][!//
[!IF "(num:i($RxCnt5)) > '64'"!][!ERROR "Number of Receive mailboxes supported is 64 only"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!VAR "TxFIFOCnt5" = "$TxFIFOCnt5+node:value(CanHwObjectCount)"!][!//
[!IF "(num:i($TxCnt5) + num:i($TxFIFOCnt5)) > '32'"!][!ERROR "Number of Transmit mailboxes supported is 32 only"!][!ENDIF!][!//
[!ENDIF!][!//
    .HwHandle = (Can_HwHandleType )[!"num:i(0)"!]U, /* HwHandle */ /* Mailbox - Hw object in the controller*/
[!ENDIF!][!//
[!ENDIF!][!//
    .CanHwObjectCount = (uint16 )[!"CanHwObjectCount"!]U,
    .CanObjectType = (Can_MailboxDirectionType )[!IF "CanObjectType = 'TRANSMIT'"!]TRANSMIT[!ELSE!]RECEIVE[!ENDIF!],
    .CanControllerRef = (const Can_ControllerType* )&[!"../../@name"!]_[!"node:name(node:ref(CanControllerRef))"!],
    .CanFdPaddingValue = (uint8 )[!"CanFdPaddingValue"!]U,
    .CanHardwareObjectUsesPolling = (boolean )[!IF "CanHardwareObjectUsesPolling = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CanTriggerTransmitEnable = (boolean )[!IF "CanTriggerTransmitEnable = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!IF "CanObjectType = 'RECEIVE'"!][!//
[!IF "node:empty(CanHwFilter/*/CanHwFilterCode) = 'TRUE'"!][!//
[!ERROR "Please configure HW filter code as this mailbox object is HRH "!][!//
[!ELSE!][!//
    .CanHwFilterCode = (uint32 )[!"CanHwFilter/*/CanHwFilterCode"!]U,   /*CanHwFilterCode*/
[!ENDIF!][!//
[!IF "node:empty(CanHwFilter/*/CanHwFilterMask) = 'TRUE'"!][!//
[!ERROR "Please configure Filter Mask as this mailbox object is HRH "!][!//
[!ELSEIF "CanHandleType ='FULL'"!][!//
[!IF "CanHwFilter/*/CanHwFilterMask != '4294967295'"!][!//
[!ERROR "CanHandleType must be BASIC for this value of FilterMask"!][!//
[!ELSE!][!//
    .CanHwFilterMask = {(uint32 )[!"CanHwFilter/*/CanHwFilterMask"!]U},
[!ENDIF!][!//
[!ELSE!][!//
    .CanHwFilterMask = {(uint32 )[!"CanHwFilter/*/CanHwFilterMask"!]U},
[!ENDIF!][!//
    .CanStandardFilterType = [!"CanHwFilter/*/CanStandardFilterType"!],
    .CanEventPin = [!"CanHwFilter/*/CanEventPin"!],
[!ELSE!][!//
    .CanHwFilterCode = (uint32 )0U, /* Only valid if CAN object type is RECEIVE */
    .CanHwFilterMask = {(uint32 )0U},
[!ENDIF!][!//

[!IF "$RWFunctionList = '0.0'"!][!//
    .CanMainFunctionRWPeriodRef = {(uint16 )0U},
[!ELSE!][!//
    .CanMainFunctionRWPeriodRef = {(uint16 )[!"node:name(node:ref(CanMainFunctionRWPeriodRef))"!]},
[!ENDIF!][!//
};
[!VAR "CanObjectIdIndx" = "$CanObjectIdIndx+1"!][!//
[!ENDLOOP!][!ENDLOOP!][!//

/* List of the Mailboxes */
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!//

CONST(Can_MailboxType*, CAN_CONFIG_DATA) [!"@name"!]_CanHardwareObject_List[] =
{
(Can_MailboxType* )[!LOOP "CanHardwareObject/*"!][!WS "3"!]&[!"../../@name"!]_[!"@name"!][!IF "not(node:islast())"!],[!CR!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!][!//
[!ENDIF!][!//


/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

[!IF "as:modconf('Can')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/*Can Config struct */
[!LOOP "as:modconf('Can')[1]/CanConfigSet"!][!//
CONST(Can_ConfigType, CAN_CONFIG_DATA) Can_[!"@name"!] =
{
    .CanControllerList = (const Can_ControllerType** )[!"@name"!]_CanController_List,
    .MailBoxList = (const Can_MailboxType** )[!"@name"!]_CanHardwareObject_List,
    .MaxMbCnt = (uint8 )[!"num:i(count(CanHardwareObject/*))"!]U,
    .CanMaxControllerCount = (uint8 )[!"num:i(count(CanController/*))"!]U,
    .MaxBaudConfigID = {
[!LOOP "./CanController/*"!][!//
        [[!"@index"!]] = (uint32 )[!"num:i(num:sub(num:i(count(CanControllerBaudrateConfig/*)),1))"!]U[!IF "not(node:islast())"!],[!ENDIF!][!CR!][!//
[!ENDLOOP!][!//
	},
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
	.IcomConfigurationList = (const Can_IcomConfigType** )Can_IcomConfigurationList,
#endif
   
};
[!ENDLOOP!][!//


[!ENDIF!][!//
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
