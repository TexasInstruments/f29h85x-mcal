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
 *  File:         Gpt_Cfg.h
 *  Generator:    Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/
#ifndef GPT_CFG_H
#define GPT_CFG_H
/** \addtogroup GPT
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/** \brief Gpt driver configuration versions */
#define GPT_CFG_MAJOR_VERSION               (2U)
#define GPT_CFG_MINOR_VERSION               (0U)
#define GPT_CFG_PATCH_VERSION               (0U)

/** \brief GPT instance Id. */
/*
 *Design: MCAL-23348
 */
#define GPT_INSTANCE_ID                     ((uint8)0U)

/** \brief GPT build variants. */
/*
 *Design: MCAL-23349
 */
#define GPT_PRE_COMPILE_VARIANT             (STD_OFF)

/** \brief Enable/Disable development error detection. */
/*
 * Design: MCAL-22044, MCAL-22045, MCAL-22048, MCAL-22047, MCAL-22046
 */
#define GPT_CFG_DEV_ERROR_DETECT            (STD_ON)

/** \brief Enable/Disable Gpt_GetVersionInfo(). */
/*
 *Design: MCAL-22062, MCAL-22057
 */
#define GPT_CFG_VERSION_INFO_API            (STD_ON)

/** \brief Enable/Disable Gpt_SetMode(), Gpt_EnableWakeup(), Gpt_DisableWakeup() and Gpt_CheckWakeup(). */
#define GPT_CFG_WAKEUP_FUNCTIONALITY_API    (STD_OFF)

/** \brief Enable/Disable Gpt_DeInit(). */
/*
 *Design: MCAL-22058, MCAL-22057
 */
#define GPT_CFG_DEINIT_API                  (STD_ON)

/** \brief Enable/Disable Gpt_GetTimeElapsed(). */
/*
 *Design: MCAL-22060, MCAL-22057
 */
#define GPT_CFG_TIME_ELAPSED_API            (STD_ON)

/** \brief Enable/Disable Gpt_GetTimeRemaining(). */
/*
 *Design: MCAL-22061, MCAL-22057
 */
#define GPT_CFG_TIME_REMAINING_API          (STD_ON)

/** \brief Enable/Disable GptEnableDisableNotification(). */
/*
 *Design: MCAL-22059, MCAL-22057
 */
#define GPT_CFG_NOTIFICATION_API            (STD_ON)

/** \brief Period register reset value. */
/*
 *Design: MCAL-23350
 */
#define GPT_CFG_PERIOD_RESET_VAL            (0x0000FFFFU)

/** \brief Prescale register reset value */
/*
 *Design: MCAL-23351
 */
#define GPT_CFG_PRESCALE_RESET_VAL          (0x0000U)

/** \brief Max tick value */
/*
 *Design: MCAL-23352
 */
#define GPT_CFG_MAX_TICK_VALUE              (0xFFFFFFFFU)

/** \brief Max no. of channels supported in GPT driver. */
/*
 *Design: MCAL-23353
 */
#define GPT_CFG_MAX_CHANNELS                (3U)

/** \brief No. of channels configured for GPT driver. */
/*
 *Design: MCAL-23354
 */
#define GPT_CFG_NO_OF_CHANNELS              (3U)


/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/** \brief GPT channels IRQ Enable/Disable */
/*
 *Design: MCAL-23355
 */
#define GPT_CHANNEL0_ENABLE
#define GPT_CHANNEL1_ENABLE
#define GPT_CHANNEL2_ENABLE

/** \brief GPT channels IRQ interrupt level */
/*
 *Design: MCAL-23355
 */
#define GPT_ISR_CAT1_RTINT_CHANNEL0
#define GPT_ISR_CAT1_RTINT_CHANNEL1
#define GPT_ISR_CAT1_RTINT_CHANNEL2

/** \brief Symbolic names for gpt timer channels. */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_0 (0U)  /*~ASR~*/
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_1 (1U)  /*~ASR~*/
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_2 (2U)  /*~ASR~*/

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/** \brief Gpt config pointer. */
/*
 *Design: MCAL-22072
 */
extern CONST(struct Gpt_ConfigType_s, GPT_CONST) Gpt_Config;


/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif    //GPT_CFG_H
/*********************************************************************************************************************
 *  End of File: Gpt_Cfg.h
 *********************************************************************************************************************/
