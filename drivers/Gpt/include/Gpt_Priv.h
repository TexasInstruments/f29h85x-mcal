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
 *  File:         Gpt_Priv.h
 *  Generator:    None
 *
 *  Description:  This file contains data structures and function declaration of private API's.
 *********************************************************************************************************************/
#ifndef GPT_PRIV_H
#define GPT_PRIV_H
/** \addtogroup GPT
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-22063
 */
#include "Gpt.h"
#include "hw_cputimer.h"
#include "hw_types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** \brief Max. 32bit value */
/*
 *Design: MCAL-23356
 */
#define GPT_MAX_32BIT_VAL (0xFFFFFFFFU) /* Max 32 bit value. */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief  GPT channel notification enable/disable status.
 * This indicates if the notification of GPT channel is enabled or disabled. */
/*
 *Design: MCAL-22067
 */
typedef enum
{
    /** \brief GPT notification is enabled. */
    GPT_NOTIF_ENABLED,
    /** \brief GPT notification is disabled. */
    GPT_NOTIF_DISABLED
} Gpt_NotificationStateType;

/** \brief  GPT channel state. GPT will be in one of this state during its lifetime. */
/*
 *Design: MCAL-22068
 */
typedef enum
{
    /** \brief GPT channel is uninitialized. */
    GPT_CH_UNINITIALIZED,
    /** \brief GPT channel is initialized. */
    GPT_CH_INITIALIZED,
    /** \brief GPT channel is running. */
    GPT_CH_RUNNING,
    /** \brief GPT channel is stopped. */
    GPT_CH_STOPPED,
    /** \brief GPT channel is expired. */
    GPT_CH_EXPIRED
} Gpt_ChannelStateType;

/** \brief GPT driver object structure. */
/*
 *Design: MCAL-22073
 */
typedef struct Gpt_DriverObjType_s
{
    /* Gpt driver configuration pointer.*/
    const Gpt_ConfigType     *Gpt_CfgPtr;
    /* Channel state. */
    Gpt_ChannelStateType      Gpt_ChannelState[GPT_CFG_NO_OF_CHANNELS];
    /* Notification state. */
    Gpt_NotificationStateType Gpt_NotificationState[GPT_CFG_NO_OF_CHANNELS];
    /* Counter period when the timer is  stopped. */
    Gpt_ValueType             Gpt_StopStatePrdCounter[GPT_CFG_NO_OF_CHANNELS];
    /* Timer current count when the timer is stopped. */
    Gpt_ValueType             Gpt_StopStateCurCounter[GPT_CFG_NO_OF_CHANNELS];
    /* Lookup Table for Channel-Index  Ex:Gpt_Lut_Channel_Index[Ch] = index */
    Gpt_ValueType             Gpt_Lut_Channel_Index[GPT_CFG_MAX_CHANNELS];
} Gpt_DriverObjType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Set the Gpt driver object into global pointer.
 *
 * This function Set the Gpt driver object into global pointer which can be used in ISR notification
 *API.
 *
 * \param[in] Set_DrvObj Gpt driver object defined in Gpt.c
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE) Gpt_SetDriverObjPtr(Gpt_DriverObjType *Set_DrvObj);

/** \brief Deinitializes the timer hardware to reset state.
 *
 * This function deintializes the timer module to its reset state. All the
 * registers are set to their initial values by calling the static inline APIs.
 *
 * \param[in] ChannelObj ChannelObj contains the channel configuration
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE) Gpt_DeInitPriv(const Gpt_ChannelConfigType *ChannelObj);

/** \brief Initialize the timer instance.
 *
 * This function initializes the CPU timer using the configuration parameters.
 *
 * \param[in] ChannelObj is the structure containing timer configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE) Gpt_InitPriv(const Gpt_ChannelConfigType *ChannelObj);

/** \brief Get the current timer count.
 *
 * This function queries the current (instantaneous) timer count of the TIM reg.
 *
 * \param[in] ChannelObj is the structure containing timer configuration.
 * \pre None
 * \post None
 * \return This function returns the current (instantaneous) timer count.
 * \retval Value of Type uint32
 *
 *********************************************************************************************************************/
FUNC(uint32, GPT_PRIV_CODE) Gpt_GetCurCountPriv(const Gpt_ChannelConfigType *ChannelObj);

/** \brief Get the timer period count.
 *
 * This function queries the period count from the PRD reg. that is programmed.
 *
 * \param[in] ChannelObj is the structure containing timer configuration.
 * \pre None
 * \post None
 * \return Returns the period count of the PRD regsiter.
 * \retval Value of Type uint32
 *
 *********************************************************************************************************************/
FUNC(uint32, GPT_PRIV_CODE) Gpt_GetPrdCountPriv(const Gpt_ChannelConfigType *ChannelObj);

/** \brief Start the timer.
 *
 *  This function starts the timer with the tick count argument.
 *
 * \param[in] ChannelObj is the structure containing timer configuration.
 * \param[in] count is timer tick count.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE) Gpt_StartTimerPriv(const Gpt_ChannelConfigType *ChannelObj, uint32 count);

/** \brief Stop the timer.
 *
 *  This function stops the running timer.
 *
 * \param[in] ChannelObj is the structure containing timer configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE) Gpt_StopTimerPriv(const Gpt_ChannelConfigType *ChannelObj);

/** \brief Clear the Timer Overflow flag
 *
 *  This function clears the timer overflow flag, which is set on timer expiry
 *
 * \param[in] ChannelObj is the structure containing timer configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE) Gpt_ClrOvfFlagPriv(const Gpt_ChannelConfigType *ChannelObj);

/** \brief Enable the timer interrupt.
 *
 *  This function enables the timer interrupt.
 *
 * \param[in] ChannelObj is the structure containing timer configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE) Gpt_EnableIntPriv(const Gpt_ChannelConfigType *ChannelObj);

/** \brief Disable the timer interrupt.
 *
 *  This function disables the timer interrupt.
 *
 * \param[in] ChannelObj is the structure containing timer configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE) Gpt_DisableIntPriv(const Gpt_ChannelConfigType *ChannelObj);

/** \brief Get the array index of a channel from configuration array/vector
 *
 *  This function populates the 'ChannelIndex' pointer with the array index of the
 *  'Channel' present in configuration array
 *
 * \param[in] GptDrvObj is a structure containing multiple timer configurations.
 * \param[in] Channel Numeric identifier of the GPT channel.
 * \param[out] ChannelIndex Pointer to populate the index of channel present in config
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_PRIV_CODE)
Gpt_GetChIdxPriv(const Gpt_DriverObjType *GptDrvObj, Gpt_ChannelType Channel, uint32 *ChannelIndex);

/** \brief Gpt_GetPredefTimerValue : Delivers the current value of the desired GPT Predef Timer. */
FUNC(Std_ReturnType, GPT_CODE)
Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr);

/** \brief Gpt_IsrNotifyFunction: Invoked by the respective timer channel ISR.
 *
 * This Interrupt notification call function is called when interrupt
 * notification is enabled for the channel in Gpt_StartTimer.
 * Once the timer channel is expired/reached zero, interrupt is triggered which calls the
 * Gpt_IsrNotifyFunction call back function inside the timer Isr.
 *
 * \param[in] Channel Numeric identifier of the GPT channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_CODE) Gpt_IsrNotifyFunction(Gpt_ChannelType Channel);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* GPT_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Gpt_Priv.h
 *********************************************************************************************************************/
