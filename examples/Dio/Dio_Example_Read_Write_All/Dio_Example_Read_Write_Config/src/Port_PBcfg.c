
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
 /* PIN PACKAGE SELECTED = F29H85x_256ZEX */

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
#if ((PORT_SW_MAJOR_VERSION != (1U)) || (PORT_SW_MINOR_VERSION != (1U)))
   #error "Version numbers of Port_PBcfg.c and Port.h are inconsistent!"
#endif

#if ((PORT_CFG_MAJOR_VERSION != (1U)) || (PORT_CFG_MINOR_VERSION != (1U)))
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


static CONST( Port_PinConfigType, PORT_CONFIG_DATA) Port_PortConfigSet_PinConfig[20] =
{
   
   {
    /* .Port_PhysicalPinId = A8U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)0U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_0_GPIO0,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_0_GPIO0
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = A7U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)1U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_1_GPIO1,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_1_GPIO1
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = C16U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)42U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
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
                            |(1UL<<2U)
                            |(1UL<<3U)
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
    /* .Port_PhysicalPinId = C15U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)43U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
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
                            |(1UL<<2U)
                            |(1UL<<3U)
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
    /* .Port_PhysicalPinId = D7U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)4U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_IN,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_4_GPIO4,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_4_GPIO4
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = A6U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)5U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_IN,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_5_GPIO5,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_5_GPIO5
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = B6U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)6U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_IN,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_6_GPIO6,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_6_GPIO6
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = C6U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)7U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_IN,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_7_GPIO7,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_7_GPIO7
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = D6U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)8U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_8_GPIO8,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_8_GPIO8
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = A5U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)9U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_9_GPIO9,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_9_GPIO9
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = C5U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)10U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_10_GPIO10,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_10_GPIO10
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = A4U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)11U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_11_GPIO11,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_11_GPIO11
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = A3U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)12U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_IN,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_12_GPIO12,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_12_GPIO12
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = A2U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)13U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_IN,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_13_GPIO13,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_13_GPIO13
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = B3U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)14U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_IN,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_14_GPIO14,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_14_GPIO14
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = C4U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)15U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_IN,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_NA,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_15_GPIO15,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_15_GPIO15
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = D5U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)16U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_16_GPIO16,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_16_GPIO16
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = B2U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)17U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_17_GPIO17,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_17_GPIO17
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = F2U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)18U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_18_GPIO18,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_18_GPIO18
        },
    }

   },
   
   {
    /* .Port_PhysicalPinId = B1U,    Physical Pin Number*/
	.Port_PinId = (Port_PinType)19U,
    .Port_PinDirection = (Port_PinDirectionType)PORT_PIN_OUT,
    .Port_DirectionChangeable = (boolean) FALSE,
    .Port_ModeChangeable = (boolean) FALSE,
    .Port_PinLevelValue = (Port_PinLevelValueType)PORT_PIN_LEVEL_LOW,
    .Port_ControllerSpecific =
    {
        .Port_AnalogMode = (Port_AnalogModeType)PORT_ANALOG_DISABLED,
        .Port_InitialMuxMode = (Port_PinType)PORT_PIN_19_GPIO19,
        .Port_PinPadConfig = (Port_PinPadConfigType)PORT_PIN_TYPE_STD,
        .Port_PinQualification = (Port_PinQualificationMode)PORT_QUAL_SYNC,
        .Port_PinQualificationPeriod = (uint32)1U,
        .Port_CoreSelect = (Port_PinCoreSelect)PORT_CORE_CPU1,
        .Port_PinConfigFlags = (Port_PinConfigFlagType)((1UL<<0U)
                            |(0UL<<1U)
                            |(1UL<<2U)
                            |(1UL<<3U)
                            |(1UL<<4U)),
        .Port_EnableWakeupPinLPM = (boolean) FALSE
    },
    .Port_NumPortMuxModes = (uint32)1U,
    .Port_PinMode =
    {
        
        
        [0] = 
        {
        .Port_PinMuxMode = (Port_PinModeType)PORT_PIN_19_GPIO19
        },
    }

   },

};



const struct Port_ConfigType_s Port_PortConfigSet = 
{
    .Port_PinConfig = (const Port_PinConfigType *)&Port_PortConfigSet_PinConfig[0],
    .Port_NumberOfPortPins = (Port_PinType)20U
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
