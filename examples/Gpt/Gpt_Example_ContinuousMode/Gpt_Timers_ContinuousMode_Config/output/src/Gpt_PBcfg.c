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
 *  File:         Gpt_PBcfg.c
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated post build configuration data for GPT MCAL driver
 *********************************************************************************************************************/
/*
 *Design: MCAL-22043
 */
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-22063
 */
#include "Gpt.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/** \brief Check module software version information */
#if ((GPT_SW_MAJOR_VERSION != (2U)) ||\
     (GPT_SW_MINOR_VERSION != (0U)))
    #error "Module software version numbers of Gpt_PBcfg.c and Gpt.h are inconsistent!"
#endif

#if ((GPT_CFG_MAJOR_VERSION != (2U)) || \
    (GPT_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Gpt_PBcfg.c and Gpt_Cfg.h are inconsistent!"
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
 * Exported Function Prototypes
 *********************************************************************************************************************/
/*
 *Design: MCAL-22036, MCAL-22037
 */
#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
extern void Gpt_Notify_Func_0(void);
extern void Gpt_Notify_Func_1(void);
extern void Gpt_Notify_Func_2(void);


/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
/*
 *Design: MCAL-22085, MCAL-22086, MCAL-22050, MCAL-22051, MCAL-22052, MCAL-22053, MCAL-22054, 
 * MCAL-22055, MCAL-22056, MCAL-22036, MCAL-22037, MCAL-22041
 */
/** \brief Gpt Channels Configuration parameters. */
static CONST(Gpt_ChannelConfigType, GPT_CONFIG_DATA) Gpt_ChannelConfiguration[3] =
{
    [0] =
    {
        .Gpt_ChannelId         = ((Gpt_ChannelType) 0U),  /* Gpt Channel ID. */
        .Gpt_ChannelMode       = ((Gpt_ChannelModeType) GPT_CH_MODE_CONTINUOUS),  /* Gpt Channel Mode. */
        .Gpt_ChannelBaseAddr   = ((Gpt_ChannelBaseAddrType) CPUTIMER0_BASE),  /* Gpt Channel Base Address. */
        .Gpt_PrescaleValue     = ((Gpt_PrescaleValueType) 0U),  /* Gpt Channel Prescale Value. */
        .Gpt_PtrNotifyFunction = ((Gpt_NotifyType) Gpt_Notify_Func_0),  /* Notification Call Back function. */
        .Gpt_SimStatus         = ((Gpt_SimStatusType) GPT_SIM_DISABLE),  /* Gpt Channel Simulation State */
        .Gpt_SimMode           = ((Gpt_SimModeType) GPT_SIM_STOP_TIMER_AT_NEXT_COUNTER_DEC),  /* Gpt Channel Simulation Mode */
    },
    [1] =
    {
        .Gpt_ChannelId         = ((Gpt_ChannelType) 1U),  /* Gpt Channel ID. */
        .Gpt_ChannelMode       = ((Gpt_ChannelModeType) GPT_CH_MODE_CONTINUOUS),  /* Gpt Channel Mode. */
        .Gpt_ChannelBaseAddr   = ((Gpt_ChannelBaseAddrType) CPUTIMER1_BASE),  /* Gpt Channel Base Address. */
        .Gpt_PrescaleValue     = ((Gpt_PrescaleValueType) 0U),  /* Gpt Channel Prescale Value. */
        .Gpt_PtrNotifyFunction = ((Gpt_NotifyType) Gpt_Notify_Func_1),  /* Notification Call Back function. */
        .Gpt_SimStatus         = ((Gpt_SimStatusType) GPT_SIM_DISABLE),  /* Gpt Channel Simulation State */
        .Gpt_SimMode           = ((Gpt_SimModeType) GPT_SIM_STOP_TIMER_AT_NEXT_COUNTER_DEC),  /* Gpt Channel Simulation Mode */
    },
    [2] =
    {
        .Gpt_ChannelId         = ((Gpt_ChannelType) 2U),  /* Gpt Channel ID. */
        .Gpt_ChannelMode       = ((Gpt_ChannelModeType) GPT_CH_MODE_CONTINUOUS),  /* Gpt Channel Mode. */
        .Gpt_ChannelBaseAddr   = ((Gpt_ChannelBaseAddrType) CPUTIMER2_BASE),  /* Gpt Channel Base Address. */
        .Gpt_PrescaleValue     = ((Gpt_PrescaleValueType) 0U),  /* Gpt Channel Prescale Value. */
        .Gpt_PtrNotifyFunction = ((Gpt_NotifyType) Gpt_Notify_Func_2),  /* Notification Call Back function. */
        .Gpt_SimStatus         = ((Gpt_SimStatusType) GPT_SIM_DISABLE),  /* Gpt Channel Simulation State */
        .Gpt_SimMode           = ((Gpt_SimModeType) GPT_SIM_STOP_TIMER_AT_NEXT_COUNTER_DEC),  /* Gpt Channel Simulation Mode */
    }

};

/** \brief Config variable to be passed to Gpt_Init API. */
/*
 *Design: MCAL-22049
 */
CONST(Gpt_ConfigType, GPT_CONST) Gpt_Config =
{
    .ChannelCfgPtr = ((Gpt_ChannelConfigType *) &Gpt_ChannelConfiguration[0]), /* Pointer to Channel Configuration. */
};

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
 
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

#define GPT_STOP_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Gpt_PBcfg.c
 *********************************************************************************************************************/
