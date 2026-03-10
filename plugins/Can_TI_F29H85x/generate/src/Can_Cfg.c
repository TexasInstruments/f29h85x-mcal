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
#if ((CAN_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CAN_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Can_cfg.c and Can.h are inconsistent!"
#endif

#if ((CAN_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CAN_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Can_cfg.c and Can_Cfg.h are inconsistent!"
#endif

[!AUTOSPACING!]
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
[!SELECT "as:modconf('Can')[as:path(node:dtos(.))='/TI_F29H85x/Can']"!]
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/* Baud Rate Structure for all configsets */

/*
 * Design: MCAL-22772,MCAL-22773,MCAL-22774,MCAL-22775,MCAL-22776,MCAL-22777,MCAL-22778,MCAL-22779,
 * Design: MCAL-22780,MCAL-22781,MCAL-22782,MCAL-22783,MCAL-22784,MCAL-22785,MCAL-22786,MCAL-22770
 */
[!LOOP "CanConfigSet/CanController/*"!][!//
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
[!ENDLOOP!][!ENDLOOP!][!//

/*List of the Baudrate structures */
[!LOOP "CanConfigSet/CanController/*"!][!//

CONST(Can_BaudConfigType*, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!]_BaudRateConfigList[[!"num:i(count(CanControllerBaudrateConfig/*))"!]]=
{
[!LOOP "CanControllerBaudrateConfig/*"!][!WS "3"!]&[!"../../../../@name"!]_[!"../../@name"!]_[!"@name"!][!IF "not(node:islast())"!],[!CR!][!ENDIF!][!ENDLOOP!][!//
};
[!ENDLOOP!][!//

[!ENDIF!][!//
/* Controller structure defined here for all config sets */

/*
 * Design: MCAL-22759,MCAL-22760,MCAL-22761,MCAL-22762,MCAL-22763,MCAL-22764,MCAL-22765,
 * Design: MCAL-22766,MCAL-22767,MCAL-22768,MCAL-22769,MCAL-22801,MCAL-24210,MCAL-24209,MCAL-24208,
 * Design: MCAL-24207,MCAL-24206
 */
[!VAR "CanControllerIdIndx" = "0"!][!//
[!LOOP "CanConfigSet/CanController/*"!][!//
/* Controller structure for [!"../../@name"!]_[!"@name"!]*/
CONST(Can_ControllerType, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!] =
{
    .CanControllerId = (uint8 )[!"CanControllerId"!]U,
[!IF "(num:i($CanControllerIdIndx)) != CanControllerId"!][!//
[!ERROR "Can Controller Id should start with 0, increment by 1 and continue without any gaps"!][!//
[!ENDIF!][!//
    .CanControllerActivation = (boolean )[!IF "CanControllerActivation ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CanControllerInstance = (Can_ControllerInstance )CAN_CONTROLLER_INSTANCE_[!"(node:ref(CanControllerInstance)/InstanceName)"!],
    .CanControllerBaseAddress = (uint32)[!"node:value(node:ref(CanControllerInstance)/BaseAddr)"!],
    .CanBusoffProcessing = (Can_ProcessingType )[!IF "CanBusoffProcessing ='INTERRUPT'"!]CAN_INTERRUPT[!ELSE!]CAN_POLLING[!ENDIF!],
    .CanRxProcessing = (Can_ProcessingType )[!IF "CanRxProcessing ='INTERRUPT'"!]CAN_INTERRUPT[!ELSEIF "CanRxProcessing ='MIXED'"!]CAN_MIXED[!ELSE!]CAN_POLLING[!ENDIF!],
    .CanTxProcessing = (Can_ProcessingType )[!IF "CanTxProcessing ='INTERRUPT'"!]CAN_INTERRUPT[!ELSEIF "CanTxProcessing ='MIXED'"!]CAN_MIXED[!ELSE!]CAN_POLLING[!ENDIF!],
    .CanWakeupFunctionalityAPI = (boolean )[!IF "CanWakeupFunctionalityAPI ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CanWakeupProcessing = (Can_ProcessingType )[!IF "CanWakeupProcessing ='INTERRUPT'"!]CAN_INTERRUPT[!ELSE!]CAN_POLLING[!ENDIF!],
    .CanWakeupSupport = (boolean )[!IF "CanWakeupSupport ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CanWakeupSourceRef = (EcuM_WakeupSourceType )([!IF "not(node:empty(CanWakeupSourceRef))"!][!"num:inttohex(bit:bitset(0, node:value(node:ref(CanWakeupSourceRef)/EcuMWakeupSourceId)), 8)"!][!ELSE!]0[!ENDIF!]U),
    .CanControllerDefaultBaudrate = (const Can_BaudConfigType* )&[!"../../@name"!]_[!"@name"!]_[!"node:name(node:ref(node:current()/CanControllerDefaultBaudrate))"!],
    .BaudRateConfigList = &[!"../../@name"!]_[!"@name"!]_BaudRateConfigList[0],
    .CanConfigParam = {
        .CanFDMode = (boolean )[!IF "CanControllerConfig/CanFDMode ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .CanLoopbackMode = (boolean )[!IF "CanControllerConfig/CanLoopbackMode ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .CanTransmitPause = (boolean )[!IF "CanControllerConfig/CanTransmitPause ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .CanDisableAutomaticRetransmission = (boolean )[!IF "CanControllerConfig/CanDisableAutomaticRetransmission  ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        .CanExtendedIDMask =[!"' '"!][!IF "node:exists(CanControllerConfig/CanExtendedIDMask)"!][!"CanControllerConfig/CanExtendedIDMask"!]U[!ELSE!]536870911U[!ENDIF!],
    }
};
[!VAR "CanControllerIdIndx" = "$CanControllerIdIndx+1"!][!//
[!ENDLOOP!][!//


/* List of Icom configuration */

/*
 * Design: MCAL-22804,MCAL-22805,MCAL-22806,MCAL-22807,MCAL-22808,MCAL-22811,MCAL-22812,MCAL-22813,MCAL-22814,
 * Design: MCAL-22815,MCAL-22816,MCAL-22817,MCAL-22818,MCAL-22819,MCAL-22820,MCAL-22801,MCAL-22822
 */
[!LOOP "CanConfigSet/CanIcom/CanIcomConfig/*"!][!//
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
[!LOOP "CanConfigSet/CanIcom/CanIcomConfig/*"!][!//
    &Can_[!"@name"!],
[!ENDLOOP!][!//
};


[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/*List of the Controller structures */
[!LOOP "CanConfigSet"!][!//

CONST(Can_ControllerType*, CAN_CONFIG_DATA) [!"@name"!]_CanController_List[]=
{
[!LOOP "CanController/*"!][!//
    &[!"../../@name"!]_[!"@name"!][!IF "not(node:islast())"!],[!CR!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!][!//

/* List of all standard and extended filter elements for all hardware objects */
[!LOOP "CanConfigSet"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!LOOP "CanHwFilter/*"!][!//
CONST(Can_HwFilterType, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!] =
{
    .CanHwFilterCode       = (uint32)[!"CanHwFilterCode"!],
    .CanHwFilterMask       = {(uint32)[!"CanHwFilterMask"!]},
    .CanEventPin           = (Can_EventPin)[!"CanEventPin"!],
    .CanStandardFilterType = (Can_StandardFilterType)[!"CanStandardFilterType"!],
};

[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//

/* List of all standard and extended filter elements per hardware objects */
[!LOOP "CanConfigSet"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!IF "num:i(count(CanHwFilter/*)) > 0"!][!//
CONST(Can_HwFilterType*, CAN_CONFIG_DATA) [!"@name"!]_CanHwFilter_List[] =
{
[!LOOP "CanHwFilter/*"!][!//   
     &[!"../../@name"!]_[!"@name"!],
[!ENDLOOP!][!//
};

[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//

/* All the Mailbox objects(MB's) will be defined here for all config sets */

/*
 * Design: MCAL-22787,MCAL-22788,MCAL-22789,MCAL-22790,MCAL-22791,MCAL-22792,MCAL-22793,MCAL-22794,
 * Design: MCAL-22795,MCAL-22796,MCAL-22797,MCAL-22798,MCAL-22799,MCAL-22800,MCAL-22801,MCAL-24251
 */
[!VAR "RWFunctionList" = "0"!][!//
[!LOOP "CanGeneral"!][!LOOP "CanMainFunctionRWPeriods/*"!][!//
[!VAR "RWFunctionList" = "$RWFunctionList+1"!][!//
[!ENDLOOP!][!ENDLOOP!][!//
[!VAR "TxCnt0" = "0"!][!VAR "RxCnt0" = "0"!][!VAR "TxFIFOCnt0" = "0"!][!VAR "RxFIFO0Cnt0" = "0"!][!VAR "RxFIFO1Cnt0" = "0"!][!//[!//
[!VAR "TxCnt1" = "0"!][!VAR "RxCnt1" = "0"!][!VAR "TxFIFOCnt1" = "0"!][!VAR "RxFIFO0Cnt1" = "0"!][!VAR "RxFIFO1Cnt1" = "0"!][!//[!//
[!VAR "TxCnt2" = "0"!][!VAR "RxCnt2" = "0"!][!VAR "TxFIFOCnt2" = "0"!][!VAR "RxFIFO0Cnt2" = "0"!][!VAR "RxFIFO1Cnt2" = "0"!][!//[!//
[!VAR "TxCnt3" = "0"!][!VAR "RxCnt3" = "0"!][!VAR "TxFIFOCnt3" = "0"!][!VAR "RxFIFO0Cnt3" = "0"!][!VAR "RxFIFO1Cnt3" = "0"!][!//[!//
[!VAR "TxCnt4" = "0"!][!VAR "RxCnt4" = "0"!][!VAR "TxFIFOCnt4" = "0"!][!VAR "RxFIFO0Cnt4" = "0"!][!VAR "RxFIFO1Cnt4" = "0"!][!//[!//
[!VAR "TxCnt5" = "0"!][!VAR "RxCnt5" = "0"!][!VAR "TxFIFOCnt5" = "0"!][!VAR "RxFIFO0Cnt5" = "0"!][!VAR "RxFIFO1Cnt5" = "0"!][!//[!//
[!VAR "NoOfStdFilter0" = "0"!][!VAR "NoOfStdFilter1" = "0"!][!VAR "NoOfStdFilter2" = "0"!][!VAR "NoOfStdFilter3" = "0"!][!VAR "NoOfStdFilter4" = "0"!][!VAR "NoOfStdFilter5" = "0"!][!//
[!VAR "NoOfExtdFilter0" = "0"!][!VAR "NoOfExtdFilter1" = "0"!][!VAR "NoOfExtdFilter2" = "0"!][!VAR "NoOfExtdFilter3" = "0"!][!VAR "NoOfExtdFilter4" = "0"!][!VAR "NoOfExtdFilter5" = "0"!][!//
[!LOOP "CanConfigSet"!][!//
[!VAR "CanObjectIdIndx" = "0"!][!//
[!LOOP "CanHardwareObject/*"!][!//

CONST(Can_MailboxType, CAN_CONFIG_DATA) [!"../../@name"!]_[!"@name"!] =
{
[!IF "CanHandleType ='FULL'"!][!//
[!IF "CanHwObjectCount = '1'"!][!//
    .CanHandleType = CAN_FULL,
[!ELSE!][!//
[!ERROR "FULL Hardware Object i.e. dedicated message buffer can't have CanHwObjectCount greater than one"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "CanHwObjectCount > '1'"!][!//
    .CanHandleType = CAN_BASIC,
[!ELSE!][!//
    .CanHandleType = CAN_BASIC,
[!WARNING "BASIC Hardware Object i.e. FIFO message buffer is recommended to have CanHwObjectCount greater than one"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
    .CanIdType = (Can_IdType )[!IF "CanIdType = 'EXTENDED'"!]CAN_EXTENDED_ID[!ELSEIF "CanIdType = 'STANDARD'"!]CAN_STANDARD_ID[!ELSE!]CAN_MIXED_ID[!ENDIF!],
[!IF "CanIdType = 'MIXED' and CanObjectType = 'RECEIVE'"!][!//
[!INFO "Receive Hardware Object with MIXED mode will add the configured filters to both standard filter list and extended filter list in hardware message RAM"!][!//
[!ENDIF!][!//
    .CanObjectId = (uint16 )[!"CanObjectId"!]U,
[!IF "(num:i($CanObjectIdIndx)) != CanObjectId"!][!//
[!ERROR "Can Object Id should start with 0, increment by 1 and continue without any gaps"!][!//
[!ENDIF!][!//
[!IF "CanHandleType = 'FULL'"!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!IF "'MCANA' =  node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($TxCnt0)"!]U, /* HwHandle */ /* Tx Message buffer number*/
[!VAR "TxCnt0" = "$TxCnt0+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCANB' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($TxCnt1)"!]U, /* HwHandle */ /* Tx Message buffer number*/
[!VAR "TxCnt1" = "$TxCnt1+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCANC' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($TxCnt2)"!]U, /* HwHandle */ /* Tx Message buffer number*/
[!VAR "TxCnt2" = "$TxCnt2+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCAND' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($TxCnt3)"!]U, /* HwHandle */ /* Tx Message buffer number*/
[!VAR "TxCnt3" = "$TxCnt3+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCANE' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($TxCnt4)"!]U, /* HwHandle */ /* Tx Message buffer number*/
[!VAR "TxCnt4" = "$TxCnt4+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCANF' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($TxCnt5)"!]U, /* HwHandle */ /* Tx Message buffer number*/
[!VAR "TxCnt5" = "$TxCnt5+node:value(CanHwObjectCount)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "'MCANA' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($RxCnt0)"!]U, /* HwHandle */ /* Rx Message buffer number*/
[!VAR "RxCnt0" = "$RxCnt0+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCANB' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($RxCnt1)"!]U, /* HwHandle */ /* Rx Message buffer number*/
[!VAR "RxCnt1" = "$RxCnt1+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCANC' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($RxCnt2)"!]U, /* HwHandle */ /* Rx Message buffer number*/
[!VAR "RxCnt2" = "$RxCnt2+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCAND' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($RxCnt3)"!]U, /* HwHandle */ /* Rx Message buffer number*/
[!VAR "RxCnt3" = "$RxCnt3+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCANE' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($RxCnt4)"!]U, /* HwHandle */ /* Rx Message buffer number*/
[!VAR "RxCnt4" = "$RxCnt4+node:value(CanHwObjectCount)"!][!//
[!ELSEIF "'MCANF' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
    .HwHandle = [!"num:i($RxCnt5)"!]U, /* HwHandle */ /* Rx Message buffer number*/
[!VAR "RxCnt5" = "$RxCnt5+node:value(CanHwObjectCount)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "CanObjectType = 'TRANSMIT'"!][!//
[!IF "'MCANA' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($TxFIFOCnt0) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Tx FIFO number*/
[!VAR "TxFIFOCnt0" = "$TxFIFOCnt0 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 1 transmit FIFO, hence there can be maximum 1 transmit BASIC Hardware Object"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANB' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($TxFIFOCnt1) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Tx FIFO number*/
[!VAR "TxFIFOCnt1" = "$TxFIFOCnt1 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 1 transmit FIFO, hence there can be maximum 1 transmit BASIC Hardware Object"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANC' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($TxFIFOCnt2) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Tx FIFO number*/
[!VAR "TxFIFOCnt2" = "$TxFIFOCnt2 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 1 transmit FIFO, hence there can be maximum 1 transmit BASIC Hardware Object"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCAND' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($TxFIFOCnt3) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Tx FIFO number*/
[!VAR "TxFIFOCnt3" = "$TxFIFOCnt3 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 1 transmit FIFO, hence there can be maximum 1 transmit BASIC Hardware Object"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANE' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($TxFIFOCnt4) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Tx FIFO number*/
[!VAR "TxFIFOCnt4" = "$TxFIFOCnt4 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 1 transmit FIFO, hence there can be maximum 1 transmit BASIC Hardware Object"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANF' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($TxFIFOCnt5) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Tx FIFO number*/
[!VAR "TxFIFOCnt5" = "$TxFIFOCnt5 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 1 transmit FIFO, hence there can be maximum 1 transmit BASIC Hardware Object"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "'MCANA' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($RxFIFO0Cnt0) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO0Cnt0" = "$RxFIFO0Cnt0 + node:value(CanHwObjectCount)"!][!//
[!ELSEIF "num:i($RxFIFO1Cnt0) = 0"!][!//
    .HwHandle = [!"num:i(1)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO1Cnt0" = "$RxFIFO1Cnt0 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 2 receive FIFOs, hence there can be maximum 2 receive BASIC Hardware Objects"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANB' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($RxFIFO0Cnt1) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO0Cnt1" = "$RxFIFO0Cnt1 + node:value(CanHwObjectCount)"!][!//
[!ELSEIF "num:i($RxFIFO1Cnt1) = 0"!][!//
    .HwHandle = [!"num:i(1)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO1Cnt1" = "$RxFIFO1Cnt1 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 2 receive FIFOs, hence there can be maximum 2 receive BASIC Hardware Objects"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANC' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($RxFIFO0Cnt2) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO0Cnt2" = "$RxFIFO0Cnt2 + node:value(CanHwObjectCount)"!][!//
[!ELSEIF "num:i($RxFIFO1Cnt2) = 0"!][!//
    .HwHandle = [!"num:i(1)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO1Cnt2" = "$RxFIFO1Cnt2 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 2 receive FIFOs, hence there can be maximum 2 receive BASIC Hardware Objects"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCAND' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($RxFIFO0Cnt3) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO0Cnt3" = "$RxFIFO0Cnt3 + node:value(CanHwObjectCount)"!][!//
[!ELSEIF "num:i($RxFIFO1Cnt3) = 0"!][!//
    .HwHandle = [!"num:i(1)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO1Cnt3" = "$RxFIFO1Cnt3 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 2 receive FIFOs, hence there can be maximum 2 receive BASIC Hardware Objects"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANE' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($RxFIFO0Cnt4) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO0Cnt4" = "$RxFIFO0Cnt4 + node:value(CanHwObjectCount)"!][!//
[!ELSEIF "num:i($RxFIFO1Cnt4) = 0"!][!//
    .HwHandle = [!"num:i(1)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO1Cnt4" = "$RxFIFO1Cnt4 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 2 receive FIFOs, hence there can be maximum 2 receive BASIC Hardware Objects"!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANF' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "num:i($RxFIFO0Cnt5) = 0"!][!//
    .HwHandle = [!"num:i(0)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO0Cnt5" = "$RxFIFO0Cnt5 + node:value(CanHwObjectCount)"!][!//
[!ELSEIF "num:i($RxFIFO1Cnt5) = 0"!][!//
    .HwHandle = [!"num:i(1)"!]U, /* HwHandle */ /* Rx FIFO number*/
[!VAR "RxFIFO1Cnt5" = "$RxFIFO1Cnt5 + node:value(CanHwObjectCount)"!][!//
[!ELSE!][!//
[!ERROR "Hardware supports maximum 2 receive FIFOs, hence there can be maximum 2 receive BASIC Hardware Objects"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
    .CanHwObjectCount = [!"CanHwObjectCount"!]U,
    .CanObjectType = (Can_MailboxDirectionType )[!IF "CanObjectType = 'TRANSMIT'"!]CAN_TRANSMIT[!ELSE!]CAN_RECEIVE[!ENDIF!],
    .CanControllerRef = &[!"../../@name"!]_[!"node:name(node:ref(CanControllerRef))"!],
[!IF "CanObjectType = 'TRANSMIT'"!][!//
    .CanHwFilterList = NULL_PTR,
[!ELSE!][!//
    .CanHwFilterList = &[!"@name"!]_CanHwFilter_List[0],
[!ENDIF!][!//
    .CanFilterListCount = (uint8)[!"num:i(count(CanHwFilter/*))"!],
    .CanFdPaddingValue = (uint8 )[!"CanFdPaddingValue"!]U,
    .CanHardwareObjectUsesPolling = (boolean )[!IF "CanHardwareObjectUsesPolling = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
    .CanTriggerTransmitEnable = (boolean )[!IF "CanTriggerTransmitEnable = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!IF "$RWFunctionList = '0.0'"!][!//
    .CanMainFunctionRWPeriodRef = {(uint16 )0U},
[!ELSE!][!//
    .CanMainFunctionRWPeriodRef = {(uint16 )[!"node:name(node:ref(CanMainFunctionRWPeriodRef))"!]},
[!ENDIF!][!//
[!IF "'MCANA' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "CanObjectType = 'RECEIVE'"!][!//
[!IF "num:i(count(CanHwFilter/*)) = 0"!][!//
[!ERROR "Receive Hardware Object must have filter configured"!][!ENDIF!][!//
[!IF "CanIdType = 'STANDARD'"!][!//
[!VAR "NoOfStdFilter0" = "$NoOfStdFilter0 + count(CanHwFilter/*)"!][!//
[!ELSEIF "CanIdType = 'EXTENDED'"!][!//
[!VAR "NoOfExtdFilter0" = "$NoOfExtdFilter0 + count(CanHwFilter/*)"!][!//
[!ELSE!][!//
[!VAR "NoOfStdFilter0" = "$NoOfStdFilter0 + count(CanHwFilter/*)"!][!//
[!VAR "NoOfExtdFilter0" = "$NoOfExtdFilter0 + count(CanHwFilter/*)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "num:i(count(CanHwFilter/*)) > 0"!][!//
[!ERROR "Transmit Hardware Object should not have filter configured"!][!ENDIF!][!//
[!ENDIF!][!//
[!IF "(num:i($TxCnt0)) > 32"!][!ERROR "Hardware supports maximum 32 transmit dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($TxFIFOCnt0)) > 32"!][!ERROR "Hardware supports maximum 32 depth for TX FIFO"!][!ENDIF!][!//
[!IF "((num:i($TxCnt0)) + (num:i($TxFIFOCnt0))) > 32 "!][!ERROR "Hardware supports maximum 32 TX dedicated buffers and FIFO together."!][!ENDIF!][!//
[!IF "(num:i($RxCnt0)) > 64"!][!ERROR "Hardware supports maximum 64 RX dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO0Cnt0)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO0"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO1Cnt0)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO1"!][!ENDIF!][!//
[!IF "(num:i($NoOfStdFilter0)) > 128"!][!ERROR "Hardware supports maximum 128 standard filters"!][!ENDIF!][!//
[!IF "(num:i($NoOfExtdFilter0)) > 64"!][!ERROR "Hardware supports maximum 64 extended filters"!][!ENDIF!][!//
[!IF "'true' = node:ref(node:current()/CanControllerRef)/CanControllerConfig/CanFDMode"!][!//
[!IF "( ((num:i($TxCnt0) + num:i($TxFIFOCnt0) + num:i($RxCnt0) + num:i($RxFIFO0Cnt0) + num:i($RxFIFO1Cnt0)) * 18) + num:i($NoOfStdFilter0) + (num:i($NoOfExtdFilter0) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANA"!][!ENDIF!][!//
[!ELSE!][!//
[!IF "( ((num:i($TxCnt0) + num:i($TxFIFOCnt0) + num:i($RxCnt0) + num:i($RxFIFO0Cnt0) + num:i($RxFIFO1Cnt0)) * 4) + num:i($NoOfStdFilter0) + (num:i($NoOfExtdFilter0) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANA"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANB' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "CanObjectType = 'RECEIVE'"!][!//
[!IF "num:i(count(CanHwFilter/*)) = 0"!][!//
[!ERROR "Receive Hardware Object must have filter configured"!][!ENDIF!][!//
[!IF "CanIdType = 'STANDARD'"!][!//
[!VAR "NoOfStdFilter1" = "$NoOfStdFilter1 + count(CanHwFilter/*)"!][!//
[!ELSEIF "CanIdType = 'EXTENDED'"!][!//
[!VAR "NoOfExtdFilter1" = "$NoOfExtdFilter1 + count(CanHwFilter/*)"!][!//
[!ELSE!][!//
[!VAR "NoOfStdFilter1" = "$NoOfStdFilter1 + count(CanHwFilter/*)"!][!//
[!VAR "NoOfExtdFilter1" = "$NoOfExtdFilter1 + count(CanHwFilter/*)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "num:i(count(CanHwFilter/*)) > 0"!][!//
[!ERROR "Transmit Hardware Object should not have filter configured"!][!ENDIF!][!//
[!ENDIF!][!//
[!IF "(num:i($TxCnt1)) > 32"!][!ERROR "Hardware supports maximum 32 transmit dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($TxFIFOCnt1)) > 32"!][!ERROR "Hardware supports maximum 32 depth for TX FIFO"!][!ENDIF!][!//
[!IF "((num:i($TxCnt1)) + (num:i($TxFIFOCnt1))) > 32 "!][!ERROR "Hardware supports maximum 32 TX dedicated buffers and FIFO together."!][!ENDIF!][!//
[!IF "(num:i($RxCnt1)) > 64"!][!ERROR "Hardware supports maximum 64 RX dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO0Cnt1)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO0"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO1Cnt1)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO1"!][!ENDIF!][!//
[!IF "(num:i($NoOfStdFilter1)) > 128"!][!ERROR "Hardware supports maximum 128 standard filters"!][!ENDIF!][!//
[!IF "(num:i($NoOfExtdFilter1)) > 64"!][!ERROR "Hardware supports maximum 64 extended filters"!][!ENDIF!][!//
[!IF "'true' = node:ref(node:current()/CanControllerRef)/CanControllerConfig/CanFDMode"!][!//
[!IF "( ((num:i($TxCnt1) + num:i($TxFIFOCnt1) + num:i($RxCnt1) + num:i($RxFIFO0Cnt1) + num:i($RxFIFO1Cnt1)) * 18) + num:i($NoOfStdFilter1) + (num:i($NoOfExtdFilter1) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANB"!][!ENDIF!][!//
[!ELSE!][!//
[!IF "( ((num:i($TxCnt1) + num:i($TxFIFOCnt1) + num:i($RxCnt1) + num:i($RxFIFO0Cnt1) + num:i($RxFIFO1Cnt1)) * 4) + num:i($NoOfStdFilter1) + (num:i($NoOfExtdFilter1) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANB"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANC' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "CanObjectType = 'RECEIVE'"!][!//
[!IF "num:i(count(CanHwFilter/*)) = 0"!][!//
[!ERROR "Receive Hardware Object must have filter configured"!][!ENDIF!][!//
[!IF "CanIdType = 'STANDARD'"!][!//
[!VAR "NoOfStdFilter2" = "$NoOfStdFilter2 + count(CanHwFilter/*)"!][!//
[!ELSEIF "CanIdType = 'EXTENDED'"!][!//
[!VAR "NoOfExtdFilter2" = "$NoOfExtdFilter2 + count(CanHwFilter/*)"!][!//
[!ELSE!][!//
[!VAR "NoOfStdFilter2" = "$NoOfStdFilter2 + count(CanHwFilter/*)"!][!//
[!VAR "NoOfExtdFilter2" = "$NoOfExtdFilter2 + count(CanHwFilter/*)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "num:i(count(CanHwFilter/*)) > 0"!][!//
[!ERROR "Transmit Hardware Object should not have filter configured"!][!ENDIF!][!//
[!ENDIF!][!//
[!IF "(num:i($TxCnt2)) > 32"!][!ERROR "Hardware supports maximum 32 transmit dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($TxFIFOCnt2)) > 32"!][!ERROR "Hardware supports maximum 32 depth for TX FIFO"!][!ENDIF!][!//
[!IF "((num:i($TxCnt2)) + (num:i($TxFIFOCnt2))) > 32 "!][!ERROR "Hardware supports maximum 32 TX dedicated buffers and FIFO together."!][!ENDIF!][!//
[!IF "(num:i($RxCnt2)) > 64"!][!ERROR "Hardware supports maximum 64 RX dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO0Cnt2)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO0"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO1Cnt2)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO1"!][!ENDIF!][!//
[!IF "(num:i($NoOfStdFilter2)) > 128"!][!ERROR "Hardware supports maximum 128 standard filters"!][!ENDIF!][!//
[!IF "(num:i($NoOfExtdFilter2)) > 64"!][!ERROR "Hardware supports maximum 64 extended filters"!][!ENDIF!][!//
[!IF "'true' = node:ref(node:current()/CanControllerRef)/CanControllerConfig/CanFDMode"!][!//
[!IF "( ((num:i($TxCnt2) + num:i($TxFIFOCnt2) + num:i($RxCnt2) + num:i($RxFIFO0Cnt2) + num:i($RxFIFO1Cnt2)) * 18) + num:i($NoOfStdFilter2) + (num:i($NoOfExtdFilter2) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANC"!][!ENDIF!][!//
[!ELSE!][!//
[!IF "( ((num:i($TxCnt2) + num:i($TxFIFOCnt2) + num:i($RxCnt2) + num:i($RxFIFO0Cnt2) + num:i($RxFIFO1Cnt2)) * 4) + num:i($NoOfStdFilter2) + (num:i($NoOfExtdFilter2) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANC"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSEIF "'MCAND' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "CanObjectType = 'RECEIVE'"!][!//
[!IF "num:i(count(CanHwFilter/*)) = 0"!][!//
[!ERROR "Receive Hardware Object must have filter configured"!][!ENDIF!][!//
[!IF "CanIdType = 'STANDARD'"!][!//
[!VAR "NoOfStdFilter3" = "$NoOfStdFilter3 + count(CanHwFilter/*)"!][!//
[!ELSEIF "CanIdType = 'EXTENDED'"!][!//
[!VAR "NoOfExtdFilter3" = "$NoOfExtdFilter3 + count(CanHwFilter/*)"!][!//
[!ELSE!][!//
[!VAR "NoOfStdFilter3" = "$NoOfStdFilter3 + count(CanHwFilter/*)"!][!//
[!VAR "NoOfExtdFilter3" = "$NoOfExtdFilter3 + count(CanHwFilter/*)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "num:i(count(CanHwFilter/*)) > 0"!][!//
[!ERROR "Transmit Hardware Object should not have filter configured"!][!ENDIF!][!//
[!ENDIF!][!//
[!IF "(num:i($TxCnt3)) > 32"!][!ERROR "Hardware supports maximum 32 transmit dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($TxFIFOCnt3)) > 32"!][!ERROR "Hardware supports maximum 32 depth for TX FIFO"!][!ENDIF!][!//
[!IF "((num:i($TxCnt3)) + (num:i($TxFIFOCnt3))) > 32 "!][!ERROR "Hardware supports maximum 32 TX dedicated buffers and FIFO together."!][!ENDIF!][!//
[!IF "(num:i($RxCnt3)) > 64"!][!ERROR "Hardware supports maximum 64 RX dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO0Cnt3)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO0"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO1Cnt3)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO1"!][!ENDIF!][!//
[!IF "(num:i($NoOfStdFilter3)) > 128"!][!ERROR "Hardware supports maximum 128 standard filters"!][!ENDIF!][!//
[!IF "(num:i($NoOfExtdFilter3)) > 64"!][!ERROR "Hardware supports maximum 64 extended filters"!][!ENDIF!][!//
[!IF "'true' = node:ref(node:current()/CanControllerRef)/CanControllerConfig/CanFDMode"!][!//
[!IF "( ((num:i($TxCnt3) + num:i($TxFIFOCnt3) + num:i($RxCnt3) + num:i($RxFIFO0Cnt3) + num:i($RxFIFO1Cnt3)) * 18) + num:i($NoOfStdFilter3) + (num:i($NoOfExtdFilter3) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCAND"!][!ENDIF!][!//
[!ELSE!][!//
[!IF "( ((num:i($TxCnt3) + num:i($TxFIFOCnt3) + num:i($RxCnt3) + num:i($RxFIFO0Cnt3) + num:i($RxFIFO1Cnt3)) * 4) + num:i($NoOfStdFilter3) + (num:i($NoOfExtdFilter3) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCAND"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANE' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "CanObjectType = 'RECEIVE'"!][!//
[!IF "num:i(count(CanHwFilter/*)) = 0"!][!//
[!ERROR "Receive Hardware Object must have filter configured"!][!ENDIF!][!//
[!IF "CanIdType = 'STANDARD'"!][!//
[!VAR "NoOfStdFilter4" = "$NoOfStdFilter4 + count(CanHwFilter/*)"!][!//
[!ELSEIF "CanIdType = 'EXTENDED'"!][!//
[!VAR "NoOfExtdFilter4" = "$NoOfExtdFilter4 + count(CanHwFilter/*)"!][!//
[!ELSE!][!//
[!VAR "NoOfStdFilter4" = "$NoOfStdFilter4 + count(CanHwFilter/*)"!][!//
[!VAR "NoOfExtdFilter4" = "$NoOfExtdFilter4 + count(CanHwFilter/*)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "num:i(count(CanHwFilter/*)) > 0"!][!//
[!ERROR "Transmit Hardware Object should not have filter configured"!][!ENDIF!][!//
[!ENDIF!][!//
[!IF "(num:i($TxCnt4)) > 32"!][!ERROR "Hardware supports maximum 32 transmit dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($TxFIFOCnt4)) > 32"!][!ERROR "Hardware supports maximum 32 depth for TX FIFO"!][!ENDIF!][!//
[!IF "((num:i($TxCnt4)) + (num:i($TxFIFOCnt4))) > 32 "!][!ERROR "Hardware supports maximum 32 TX dedicated buffers and FIFO together."!][!ENDIF!][!//
[!IF "(num:i($RxCnt4)) > 64"!][!ERROR "Hardware supports maximum 64 RX dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO0Cnt4)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO0"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO1Cnt4)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO1"!][!ENDIF!][!//
[!IF "(num:i($NoOfStdFilter4)) > 128"!][!ERROR "Hardware supports maximum 128 standard filters"!][!ENDIF!][!//
[!IF "(num:i($NoOfExtdFilter4)) > 64"!][!ERROR "Hardware supports maximum 64 extended filters"!][!ENDIF!][!//
[!IF "'true' = node:ref(node:current()/CanControllerRef)/CanControllerConfig/CanFDMode"!][!//
[!IF "( ((num:i($TxCnt4) + num:i($TxFIFOCnt4) + num:i($RxCnt4) + num:i($RxFIFO0Cnt4) + num:i($RxFIFO1Cnt4)) * 18) + num:i($NoOfStdFilter4) + (num:i($NoOfExtdFilter4) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANE"!][!ENDIF!][!//
[!ELSE!][!//
[!IF "( ((num:i($TxCnt4) + num:i($TxFIFOCnt4) + num:i($RxCnt4) + num:i($RxFIFO0Cnt4) + num:i($RxFIFO1Cnt4)) * 4) + num:i($NoOfStdFilter4) + (num:i($NoOfExtdFilter4) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANE"!][!ENDIF!][!//
[!ENDIF!][!//
[!ELSEIF "'MCANF' = node:value(node:ref(node:ref(node:current()/CanControllerRef)/CanControllerInstance)/InstanceName)"!][!//
[!IF "CanObjectType = 'RECEIVE'"!][!//
[!IF "num:i(count(CanHwFilter/*)) = 0"!][!//
[!ERROR "Receive Hardware Object must have filter configured"!][!ENDIF!][!//
[!IF "CanIdType = 'STANDARD'"!][!//
[!VAR "NoOfStdFilter5" = "$NoOfStdFilter5 + count(CanHwFilter/*)"!][!//
[!ELSEIF "CanIdType = 'EXTENDED'"!][!//
[!VAR "NoOfExtdFilter5" = "$NoOfExtdFilter5 + count(CanHwFilter/*)"!][!//
[!ELSE!][!//
[!VAR "NoOfStdFilter5" = "$NoOfStdFilter5 + count(CanHwFilter/*)"!][!//
[!VAR "NoOfExtdFilter5" = "$NoOfExtdFilter5 + count(CanHwFilter/*)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "num:i(count(CanHwFilter/*)) > 0"!][!//
[!ERROR "Transmit Hardware Object should not have filter configured"!][!ENDIF!][!//
[!ENDIF!][!//
[!IF "(num:i($TxCnt5)) > 32"!][!ERROR "Hardware supports maximum 32 transmit dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($TxFIFOCnt5)) > 32"!][!ERROR "Hardware supports maximum 32 depth for TX FIFO"!][!ENDIF!][!//
[!IF "((num:i($TxCnt5)) + (num:i($TxFIFOCnt5))) > 32 "!][!ERROR "Hardware supports maximum 32 TX dedicated buffers and FIFO together."!][!ENDIF!][!//
[!IF "(num:i($RxCnt5)) > 64"!][!ERROR "Hardware supports maximum 64 RX dedicated buffers"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO0Cnt5)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO0"!][!ENDIF!][!//
[!IF "(num:i($RxFIFO1Cnt5)) > 64"!][!ERROR "Hardware supports maximum 64 depth for RX FIFO1"!][!ENDIF!][!//
[!IF "(num:i($NoOfStdFilter5)) > 128"!][!ERROR "Hardware supports maximum 128 standard filters"!][!ENDIF!][!//
[!IF "(num:i($NoOfExtdFilter5)) > 64"!][!ERROR "Hardware supports maximum 64 extended filters"!][!ENDIF!][!//
[!IF "'true' = node:ref(node:current()/CanControllerRef)/CanControllerConfig/CanFDMode"!][!//
[!IF "( ((num:i($TxCnt5) + num:i($TxFIFOCnt5) + num:i($RxCnt5) + num:i($RxFIFO0Cnt5) + num:i($RxFIFO1Cnt5)) * 18) + num:i($NoOfStdFilter5) + (num:i($NoOfExtdFilter5) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANF"!][!ENDIF!][!//
[!ELSE!][!//
[!IF "( ((num:i($TxCnt5) + num:i($TxFIFOCnt5) + num:i($RxCnt5) + num:i($RxFIFO0Cnt5) + num:i($RxFIFO1Cnt5)) * 4) + num:i($NoOfStdFilter5) + (num:i($NoOfExtdFilter5) * 2) ) > 1024"!][!ERROR "Message RAM area overflow for MCANF"!][!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
};
[!VAR "CanObjectIdIndx" = "$CanObjectIdIndx+1"!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//

/* List of the Mailboxes */
[!LOOP "CanConfigSet"!][!//

CONST(Can_MailboxType*, CAN_CONFIG_DATA) [!"@name"!]_CanHardwareObject_List[] =
{
[!LOOP "CanHardwareObject/*"!][!WS "3"!]&[!"../../@name"!]_[!"@name"!][!IF "not(node:islast())"!],[!CR!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!][!//
[!ENDIF!][!//


/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
/*Can Config struct */
[!LOOP "CanConfigSet"!][!//
CONST(Can_ConfigType, CAN_CONFIG_DATA) Can_Config =
{
    .CanControllerList = &[!"@name"!]_CanController_List[0],
    .MailBoxList = &[!"@name"!]_CanHardwareObject_List[0],
    .MaxMbCnt = (uint16 )[!"num:i(count(CanHardwareObject/*))"!]U,
    .CanMaxControllerCount = (uint8 )[!"num:i(count(CanController/*))"!]U,
    .MaxBaudConfigID = {
[!LOOP "./CanController/*"!][!//
        [[!"@index"!]] = [!"num:i(num:sub(num:i(count(CanControllerBaudrateConfig/*)),1))"!]U[!IF "not(node:islast())"!],[!ENDIF!][!CR!][!//
[!ENDLOOP!][!//
	},
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
	.IcomConfigurationList = &Can_IcomConfigurationList[0],
#endif
   
};
[!ENDLOOP!][!//


[!ENDIF!][!ENDSELECT!][!//
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
