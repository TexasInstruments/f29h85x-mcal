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
#if ((CAN_SW_MAJOR_VERSION != (3U)) || (CAN_SW_MINOR_VERSION != (1U)))
    #error "Version numbers of Can_PBcfg.c and Can.h are inconsistent!"
#endif

#if ((CAN_CFG_MAJOR_VERSION != (3U)) || (CAN_CFG_MINOR_VERSION != (1U)))
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
    .BrpValue = (uint16 )1U,
    /* Data Phase Baud Rate */
    .BaudFdEnable = FALSE,
};

/*List of the Baudrate structures */

CONST(Can_BaudConfigType*, CAN_CONFIG_DATA) CanConfigSet_CanController_0_BaudRateConfigList[1]=
{
   &CanConfigSet_CanController_0_CanControllerBaudrateConfig_0};


/*List of the Controller structures */

CONST(Can_ControllerType*, CAN_CONFIG_DATA) CanConfigSet_CanController_List[]=
{
    &CanConfigSet_CanController_0};

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
     &CanHardwareObject_1_CanHwFilter_0,
};


/* All the Mailbox objects(MB's) will be defined here for all config sets */

/*
 * Design: MCAL-22787,MCAL-22788,MCAL-22789,MCAL-22790,MCAL-22791,MCAL-22792,MCAL-22793,MCAL-22794,
 * Design: MCAL-22795,MCAL-22796,MCAL-22797,MCAL-22798,MCAL-22799,MCAL-22800,MCAL-22801,MCAL-24209
 */

CONST(Can_MailboxType, CAN_CONFIG_DATA) CanConfigSet_CanHardwareObject_0 =
{
    .CanHandleType = CAN_FULL,
    .CanIdType = (Can_IdType )CAN_MIXED_ID,
    .CanObjectId = (uint16 )0U,
    .HwHandle = 0U, /* HwHandle */ /* Tx Message buffer number*/
    .CanHwObjectCount = 1U,
    .CanObjectType = (Can_MailboxDirectionType )CAN_TRANSMIT,
    .CanControllerRef = &CanConfigSet_CanController_0,
    .CanHwFilterList = NULL_PTR,
    .CanFilterListCount = (uint8)0,
    .CanFdPaddingValue = (uint8 )0U,
    .CanHardwareObjectUsesPolling = (boolean )FALSE,
    .CanTriggerTransmitEnable = (boolean )FALSE,
    .CanMainFunctionRWPeriodRef = {(uint16 )CanMainFunctionRWPeriods_0},
};

CONST(Can_MailboxType, CAN_CONFIG_DATA) CanConfigSet_CanHardwareObject_1 =
{
    .CanHandleType = CAN_BASIC,
    .CanIdType = (Can_IdType )CAN_STANDARD_ID,
    .CanObjectId = (uint16 )1U,
    .HwHandle = 0U, /* HwHandle */ /* Rx FIFO number*/
    .CanHwObjectCount = 2U,
    .CanObjectType = (Can_MailboxDirectionType )CAN_RECEIVE,
    .CanControllerRef = &CanConfigSet_CanController_0,
    .CanHwFilterList = &CanHardwareObject_1_CanHwFilter_List[0],
    .CanFilterListCount = (uint8)1,
    .CanFdPaddingValue = (uint8 )0U,
    .CanHardwareObjectUsesPolling = (boolean )FALSE,
    .CanTriggerTransmitEnable = (boolean )FALSE,
    .CanMainFunctionRWPeriodRef = {(uint16 )CanMainFunctionRWPeriods_2},
};

/* List of the Mailboxes */

CONST(Can_MailboxType*, CAN_CONFIG_DATA) CanConfigSet_CanHardwareObject_List[] =
{
   &CanConfigSet_CanHardwareObject_0,
   &CanConfigSet_CanHardwareObject_1};



/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*Can Config struct */
CONST(Can_ConfigType, CAN_CONFIG_DATA) Can_Config =
{
    .CanControllerList = &CanConfigSet_CanController_List[0],
    .MailBoxList = &CanConfigSet_CanHardwareObject_List[0],
    .MaxMbCnt = (uint16)2U,
    .CanMaxControllerCount = (uint8 )1U,
    .MaxBaudConfigID = {
        [0] = 0U
	},
#if (CAN_CFG_ICOM_SUPPORT == STD_ON)
	.IcomConfigurationList = &Can_IcomConfigurationList[0],
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
