
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
 *  File:       Port_PBcfg.c
 *  Project:    C29x MCAL
 *  Module:     Port Driver
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated post build configuration data
 *
 *********************************************************************************************************************/
/* ECUCs and Private Configuration JIRA IDs */
/*
 *Design: MCAL-22366,MCAL-22367,MCAL-22368,MCAL-22373,MCAL-22374,MCAL-22375,MCAL-22376,MCAL-22377,
 *Design: MCAL-22378,MCAL-22379,MCAL-22380,MCAL-22381,MCAL-22406,MCAL-22410,MCAL-22407,MCAL-23153,
 *Design: MCAL-23154,MCAL-23155,MCAL-23156,MCAL-23157,MCAL-23158,MCAL-23159,MCAL-23160,MCAL-22312
 */

 /*
 *Design: MCAL-22408
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Port.h"
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((PORT_SW_MAJOR_VERSION != (3U)) || (PORT_SW_MINOR_VERSION != (0U)))
   #error "Version numbers of Port_PBcfg.c and Port.h are inconsistent!"
#endif

#if ((PORT_CFG_MAJOR_VERSION != (3U)) || (PORT_CFG_MINOR_VERSION != (0U)))
   #error "Version numbers of Port_PBcfg.c and Port_Cfg.h are inconsistent!"
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
 * Exported Object Definitions
 *********************************************************************************************************************/
#define PORT_START_SEC_CONFIG_DATA
#include "Port_MemMap.h"


static CONST( Port_PinConfigType, PORT_CONFIG_DATA) Port_PortConfigSet_PinConfig[4] =
{
   
   {
    /* .Port_PhysicalPinId = 107U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)42U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_NA,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_42_UARTA_TX,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_ASYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(0UL<<2U)
                            |(0UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_42_UARTA_TX
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = 108U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)43U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_NA,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_43_UARTA_RX,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD_PULLUP,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_ASYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(0UL<<2U)
                            |(0UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_43_UARTA_RX
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = 11U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)22U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_NA,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_22_UARTB_TX,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_ASYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(0UL<<2U)
                            |(0UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_22_UARTB_TX
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = 127U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)23U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_NA,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_23_UARTB_RX,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_ASYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(0UL<<2U)
                            |(0UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_23_UARTB_RX
        },
    }

   },

};



const struct Port_ConfigType_s Port_Config = 
{
    .Port_PinConfig = (const Port_PinConfigType *)&Port_PortConfigSet_PinConfig[0],
    .Port_NumberOfPortPins = (Port_PinType)4U
};


/*********************************************************************************************************************
 * Local Object Definitions
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
#define PORT_STOP_SEC_CONFIG_DATA
#include "Port_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Port_PBcfg.c
 *********************************************************************************************************************/
