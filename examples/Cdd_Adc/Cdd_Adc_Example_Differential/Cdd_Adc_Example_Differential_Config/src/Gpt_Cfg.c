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
 *  File:         Gpt_Cfg.c
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated pre compile configuration data for GPT MCAL driver
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
#if ((GPT_SW_MAJOR_VERSION != (1U)) ||\
     (GPT_SW_MINOR_VERSION != (0U)))
    #error "Module software version numbers of Gpt_Cfg.c and Gpt.h are inconsistent!"
#endif

/** \brief Check AUTOSAR version information */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != (4U)) ||\
     (GPT_AR_RELEASE_MINOR_VERSION != (3U)) ||\
     (GPT_AR_RELEASE_PATCH_VERSION != (1U)))
    #error "AUTOSAR version numbers of Gpt_Cfg.c and Gpt.h are inconsistent!"
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
 *Design: MCAL-22036, MCAL-22037, MCAL-22056
 */
#define GPT_START_SEC_CONFIG_DATA
#include "Gpt_MemMap.h"
extern void Gpt_Notify_Func_0(void);


/*********************************************************************************************************************
 * Object Definitions
 *********************************************************************************************************************/
/** \brief Gpt Channels Configuration parameters. */
/*
 *Design: MCAL-22085, MCAL-22086, MCAL-22050, MCAL-22051, MCAL-22052, MCAL-22053, MCAL-22054, 
 *Design: MCAL-22055, MCAL-22056, MCAL-22036, MCAL-22037, MCAL-22041
 */
static CONST(Gpt_ChannelConfigType, GPT_CONFIG_DATA) Gpt_ChannelConfiguration[1] =
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
    }

};

/** \brief Config variable to be passed to Gpt_Init API. */
/*
 *Design: MCAL-22049
 */
CONST(Gpt_ConfigType, GPT_CONST) Gpt_ConfigSetptr =
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
 *  End of File: Cpt_Cfg.c
 *********************************************************************************************************************/
