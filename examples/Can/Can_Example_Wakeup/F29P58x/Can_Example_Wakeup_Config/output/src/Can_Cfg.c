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
#if ((CAN_SW_MAJOR_VERSION != (3U)) || (CAN_SW_MINOR_VERSION != (1U)))
    #error "Version numbers of Can_cfg.c and Can.h are inconsistent!"
#endif

#if ((CAN_CFG_MAJOR_VERSION != (3U)) || (CAN_CFG_MINOR_VERSION != (1U)))
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
    .CanControllerInstance = (Can_ControllerInstance )CAN_CONTROLLER_INSTANCE_MCANA,
    .CanControllerBaseAddress = (uint32)MCANA_DRIVER_BASE_FRAME(0U),
    .CanBusoffProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanRxProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanTxProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanWakeupFunctionalityAPI = (boolean )FALSE,
    .CanWakeupProcessing = (Can_ProcessingType )CAN_POLLING,
    .CanWakeupSupport = (boolean )TRUE,
    .CanWakeupSourceRef = (EcuM_WakeupSourceType )(0x00000001U),
    .CanControllerDefaultBaudrate = (const Can_BaudConfigType* )&CanConfigSet_CanController_0_CanControllerBaudrateConfig_0,
    .BaudRateConfigList = &CanConfigSet_CanController_0_BaudRateConfigList[0],
    .CanConfigParam = {
        .CanFDMode = (boolean )FALSE,
        .CanLoopbackMode = (boolean )FALSE,
        .CanTransmitPause = (boolean )FALSE,
        .CanDisableAutomaticRetransmission = (boolean )FALSE,
        .CanExtendedIDMask = 536870911U,
    }
};


/* List of Icom configuration */

/*
 * Design: MCAL-22804,MCAL-22805,MCAL-22806,MCAL-22807,MCAL-22808,MCAL-22811,MCAL-22812,MCAL-22813,MCAL-22814,
 * Design: MCAL-22815,MCAL-22816,MCAL-22817,MCAL-22818,MCAL-22819,MCAL-22820,MCAL-22801,MCAL-22822
 */

/* Overall list of Icom configurations */
CONST(Can_IcomConfigType*, CAN_CONFIG_DATA) Can_IcomConfigurationList[] =
{
};




/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

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
