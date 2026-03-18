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
#define GPT_CFG_PATCH_VERSION               (2U)

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
#define GPT_CFG_NO_OF_CHANNELS              (2U)


/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/** \brief GPT channels IRQ Enable/Disable */
/*
 *Design: MCAL-23355
 */
#define GPT_CHANNEL1_ENABLE
#define GPT_CHANNEL2_ENABLE

/** \brief GPT channels IRQ interrupt level */
/*
 *Design: MCAL-23355
 */
#define GPT_ISR_CAT1_RTINT_CHANNEL1
#define GPT_ISR_CAT1_RTINT_CHANNEL2

/** \brief Symbolic names for gpt timer channels. */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_0 (1U)  /*~ASR~*/
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_1 (2U)  /*~ASR~*/

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Forward declaration of Gpt_ConfigType_s struct to avoid MISRA.INCOMPLETE.STRUCT warning. */
struct Gpt_ConfigType_s;

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
