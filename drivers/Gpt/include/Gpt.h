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
 *  File:         Gpt.h
 *  Generator:    None
 *
 *  Description:  This file contains interface header for Gpt driver functions
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H
/**
 * \defgroup GPT Gpt API GUIDE Header file
 * @{
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/* Design: MCAL-22065, MCAL-21953 */
#include "Std_Types.h"
#include "Gpt_Cfg.h"
#include "SchM_Gpt.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief Driver Implementation Major Version. */
#define GPT_SW_MAJOR_VERSION (1U)
/** \brief Driver Implementation Minor Version. */
#define GPT_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version. */
#define GPT_SW_PATCH_VERSION (2U)

/** \brief AUTOSAR major version specification implemented by GPT Driver. */
#define GPT_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR minor version specification implemented by GPT Driver. */
#define GPT_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR patch version specification implemented by GPT Driver */
#define GPT_AR_RELEASE_PATCH_VERSION (1U)

/** \brief Texas Instruments Vendor ID. */
#define GPT_VENDOR_ID ((uint16)44U)
/** \brief GPT Driver Module ID. */
#define GPT_MODULE_ID ((uint16)100U)

/** \brief  API service called without module initialization. */
/*
 * Design: MCAL-22042, MCAL-21969, MCAL-21968, MCAL-21961, MCAL-21966, MCAL-21963,
 * Design: MCAL-21962, MCAL-21965, MCAL-21970, MCAL-21967, MCAL-21964
 */
#ifndef GPT_E_UNINIT
#define GPT_E_UNINIT ((uint8)0x0AU)
#endif

/** \brief  API service called when timer channel is still busy (running). */
#ifndef GPT_E_BUSY
#define GPT_E_BUSY ((uint8)0x0BU)
#endif

/** \brief API service called when driver is in wrong mode. */
#ifndef GPT_E_MODE
#define GPT_E_MODE ((uint8)0x0CU)
#endif

/** \brief API service for initialization called when already  initialized. */
#ifndef GPT_E_ALREADY_INITIALIZED
#define GPT_E_ALREADY_INITIALIZED ((uint8)0x0DU)
#endif

/** \brief API error return code: Init function failed. */
#ifndef GPT_E_INIT_FAILED
#define GPT_E_INIT_FAILED ((uint8)0x0EU)
#endif

/** \brief API parameter checking: invalid channel. */
#ifndef GPT_E_PARAM_CHANNEL
#define GPT_E_PARAM_CHANNEL ((uint8)0x14U)
#endif

/** \brief API parameter checking: invalid value. */
#ifndef GPT_E_PARAM_VALUE
#define GPT_E_PARAM_VALUE ((uint8)0x15U)
#endif

/** \brief API parameter checking: invalid pointer. */
#ifndef GPT_E_PARAM_POINTER
#define GPT_E_PARAM_POINTER ((uint8)0x16U)
#endif

/** \brief API parameter checking: invalid pointer. */
#ifndef GPT_E_PARAM_PREDEF_TIMER
#define GPT_E_PARAM_PREDEF_TIMER ((uint8)0x17U)
#endif

/** \brief API parameter checking: invalid mode. */
#ifndef GPT_E_PARAM_MODE
#define GPT_E_PARAM_MODE ((uint8)0x1FU)
#endif

/*
 *Design: MCAL-22034, MCAL-22035
 */
/** \brief Gpt_GetVersionInfo(). */
#define GPT_SID_GET_VERSION_INFO ((uint8)0x00U)
/** \brief Gpt_Init(). */
#define GPT_SID_INIT ((uint8)0x01U)
/** \brief Gpt_DeInit(). */
#define GPT_SID_DEINIT ((uint8)0x02U)
/** \brief Gpt_GetTimeElapsed(). */
#define GPT_SID_GET_TIME_ELAPSED ((uint8)0x03U)
/** \brief Gpt_GetTimeRemaining(). */
#define GPT_SID_GET_TIME_REMAINING ((uint8)0x04U)
/** \brief Gpt_StartTimer(). */
#define GPT_SID_START_TIMER ((uint8)0x05U)
/** \brief Gpt_StopTimer(). */
#define GPT_SID_STOP_TIMER ((uint8)0x06U)
/** \brief Gpt_EnableNotification(). */
#define GPT_SID_ENABLE_NOTIFY ((uint8)0x07U)
/** \brief Gpt_DisableNotification(). */
#define GPT_SID_DISABLE_NOTIFY ((uint8)0x08U)
/** \brief Gpt_SetMode(). */
#define GPT_SID_SET_MODE ((uint8)0x09U)
/** \brief Gpt_DisableWakeup(). */
#define GPT_SID_DISABLE_WAKEUP ((uint8)0x0AU)
/** \brief Gpt_EnableWakeup(). */
#define GPT_SID_ENABLE_WAKEUP ((uint8)0x0BU)
/** \brief Gpt_CheckWakeup(). */
#define GPT_SID_CHECK_WAKEUP ((uint8)0x0CU)
/** \brief Gpt_GetPredefTimerValue(). */
#define GPT_SID_GET_TIME_PREDEF ((uint8)0x0DU)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Numeric ID of a GPT channel. */
/*
 *Design: MCAL-21769
 */
typedef uint8 Gpt_ChannelType;

/** \brief Base address of a GPT channel. */
/*
 *Design: MCAL-22074
 */
typedef uint32 Gpt_ChannelBaseAddrType;

/** \brief Type for reading and setting the timer values(in number of ticks). */
/*
 *Design: MCAL-21770
 */
typedef uint32 Gpt_ValueType;

/** \brief Prescale value for General purpose timer channels. */
/*
 *Design: MCAL-21959
 */
typedef uint16 Gpt_PrescaleValueType;

/** \brief Type for GPT Predef Timers */
typedef enum
{
    /** \brief GPT Predef Timer with tick duration 1µs and range 16bit*/
    GPT_PREDEF_TIMER_1US_16BIT = 0U,
    /** \brief GPT Predef Timer with tick duration 1µs and range 24bit*/
    GPT_PREDEF_TIMER_1US_24BIT = 1U,
    /** \brief GPT Predef Timer with tick duration 1µs and range 32bit*/
    GPT_PREDEF_TIMER_1US_32BIT = 2U,
    /** \brief GPT Predef Timer with tick duration 100µs and range 32bit*/
    GPT_PREDEF_TIMER_100US_32BIT = 3U
} Gpt_PredefTimerType;

/** \brief  GPT channel mode macro. */
/*
 * Design: MCAL-22066
 */
typedef enum
{
    /** \brief Timer will continue to running with the specified time period when target
     * time reached.*/
    GPT_CH_MODE_CONTINUOUS,
    /** \brief Timer will stop after running once when target time reached. */
    GPT_CH_MODE_ONESHOT
} Gpt_ChannelModeType;

/** \brief  GPT Simulation enabled/disabled. */
/*
 *Design: MCAL-22069
 */
typedef enum
{
    /** \brief Timer is free-running */
    GPT_SIM_DISABLE,
    /** \brief Timer is not free-running. Gpt_SimMode decides mode of operation */
    GPT_SIM_ENABLE
} Gpt_SimStatusType;

/** \brief  GPT Simulation Behaviour Hard/Soft stop upon GPT simulation enabled. */
/*
 *Design: MCAL-22070
 */
typedef enum
{
    /** \brief Timer stops at next decrement (HARD STOP) */
    GPT_SIM_STOP_TIMER_AT_NEXT_COUNTER_DEC,
    /** \brief Timer stops at the next timer elapsed (SOFT STOP) */
    GPT_SIM_STOP_TIMER_AT_NEXT_TIMER_ELAPSE
} Gpt_SimModeType;

/** \brief GPT Operation Mode. */
typedef enum
{
    /** \brief Normal Mode. */
    GPT_MODE_NORMAL = 0x0U,
    /** \brief Sleep Mode. */
    GPT_MODE_SLEEP = 0x1U,
} Gpt_ModeType;

/** \brief  Notification callback function pointer. */
/*
 *Design: MCAL-23170
 */
typedef void (*Gpt_NotifyType)(void);

/** \brief  Configuration per channel */
/*
 *Design: MCAL-22071
 */
typedef struct Gpt_ChannelConfigType_s
{
    /** \brief Function pointer to callback function (for non-wakeup notification). */
    Gpt_NotifyType          Gpt_PtrNotifyFunction;
    /** \brief Channel Base Address */
    Gpt_ChannelBaseAddrType Gpt_ChannelBaseAddr;
    /** \brief Emulation debug enabled/disabled */
    Gpt_SimStatusType       Gpt_SimStatus;
    /** \brief Behaviour of timer channel, if emulation debug enabled (Hard stop/soft stop) */
    Gpt_SimModeType         Gpt_SimMode;
    /** \brief Channel mode. */
    Gpt_ChannelModeType     Gpt_ChannelMode;
    /** \brief Channel Pre-scale Value. */
    Gpt_PrescaleValueType   Gpt_PrescaleValue;
    /** \brief Channel Id. */
    Gpt_ChannelType         Gpt_ChannelId;
} Gpt_ChannelConfigType;

/** \brief  global configuration of the driver. */
/*
 *Design: MCAL-22072
 */
typedef struct Gpt_ConfigType_s
{
    /** \brief Pointer to Channel list. */
    P2CONST(Gpt_ChannelConfigType, AUTOMATIC, GPT_CONST) ChannelCfgPtr;
} Gpt_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Gpt_GetVersionInfo : Returns the Gpt Version Info.
 *
 * This service returns the version information of this module.
 *
 * \param[in] VersionInfoPtr
 * \param[out] VersionInfoPtr Pointer to where to store the version information of this module.
 * \pre VersionInfoPtr should not be NULL
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
#if (STD_ON == GPT_CFG_VERSION_INFO_API)
FUNC(void, GPT_CODE)
Gpt_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) VersionInfoPtr);
#endif

/** \brief Gpt_Init : Initializes the Gpt module.
 *
 * This service initializes all the configured Gpt channels. This will set the
 * state of the each channel to "Initialized".
 *
 * \param[in] ConfigPtr
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_CONST) ConfigPtr);

/** \brief Gpt_DeInit : De-initializes the GPT module.
 *
 * This service deinitializes the Gpt driver to the power on reset state.
 * The Gpt driver state is changed to "Uninitialized" state".
 * All the configuration registers are cleared to stop the timer channels.
 * API will disable all interrupts.
 *
 * \pre Gpt_Init should be called first before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
#if (STD_ON == GPT_CFG_DEINIT_API)
FUNC(void, GPT_CODE) Gpt_DeInit(void);
#endif

/** \brief Gpt_GetTimeElapsed : Returns the time elapsed for a given channel.
 *
 * This service will return the time elapsed for the referenced
 * channel. The user can configure the channel in two modes, One-shot
 * and Continuous mode. In one shot mode, if the timer is in stopped
 * state, the function will return time value at the moment of stopping.
 * If the timer is expired, the function will return the target time
 * configured for the channel. If the timer has not expired/stopped in one shot
 * mode, it will return the value of time elapsed, relative to the time of
 * starting. In Continuous Mode - The elapsed time value will be the value
 * relative to last occurrence of start/restart, that is for current
 * iteration only.
 *
 * \param[in] Channel Numeric identifier of the GPT channel.
 * \pre Gpt Driver must be initialized.
 * \post None
 * \return Returns the time already elapsed.
 * \retval Value of the type Gpt_ValueType
 *
 *********************************************************************************************************************/
#if (STD_ON == GPT_CFG_TIME_ELAPSED_API)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
#endif

/** \brief Gpt_GetTimeRemaining : Returns the time remaining for a given channel.
 *
 * Gpt_GetTimeRemaining will return the timer value remaining until the
 * target time will be reached next time. The remaining time is the absolute
 * difference of the target time and time already elapsed.
 * In one shot mode, if the timer is in stopped state, the function will return
 * remaining time value at the moment of stopping. If the timer is expired,
 * the function will return 0.
 * In continuous mode, the return value will be the time remaining in the
 * current iteration only.
 *
 * \param[in] Channel Numeric identifier of the GPT channel.
 * \pre Gpt Driver must be initialized.
 * \post None
 * \return Returns the time remaining until the target time is reached.
 * \retval Value of the type Gpt_ValueType
 *
 *********************************************************************************************************************/
#if (STD_ON == GPT_CFG_TIME_REMAINING_API)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
#endif

/** \brief Gpt_StartTimer : Starts a timer channel
 *
 * Gpt_StartTimer will start the selected timer channel with defined target
 * time. If the timer channel is enabled for interrupt notification, then
 * interrupt notification will be triggered after expiration of the selected
 * timer channel. In one shot mode, if the timer is expired then the channel
 * will be stopped in interrupt subroutine. The selected channel will be moved
 * to "Running" state after calling this function.
 *
 * \param[in] Channel Numeric identifier of the GPT channel.
 * \param[in] Value Target time in number of ticks.
 * \pre Gpt Driver must be initialized.
 * \post Postconditions
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_CODE) Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/** \brief Gpt_StopTimer : Stops a timer channel.
 *
 * Gpt_StopTimer will stop the selected timer channel.This will clear all the
 * registers corresponding to the selected channel. The state of the timer
 * channel will be changed to "Stopped".If the channel is in state
 * "Initialized","Expired","Stopped" before calling this function,the function
 * will be left without any action.
 *
 * \param[in] Channel Numeric identifier of the GPT channel.
 * \pre Gpt Driver must be initialized.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel);

#if (STD_ON == GPT_CFG_NOTIFICATION_API)
/** \brief Gpt_EnableNotification : Enables the interrupt notification for a channel (relevant in
 *normal mode).
 *
 * This service will enable the interrupt notification for the
 * selected channel. The TIE bit in TCR register will be Set to enable the
 * interrupt. The interrupt is triggered when counter value decrements to zero.
 *
 * \param[in] Channel Numeric identifier of the GPT channel.
 * \pre Gpt Driver must be initialized.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_CODE) Gpt_EnableNotification(Gpt_ChannelType Channel);

/** \brief Gpt_DisableNotification : Disables the interrupt notification for a channel (relevant in
 *normal mode).
 *
 * Gpt_DisableNotification will disable the compare interrupt notification for
 * the selected channel. The TIE bit in TCR register will be cleared to
 * disable the interrupt.
 *
 * \param[in] Channel Numeric identifier of the GPT channel.
 * \pre Gpt Driver must be initialized.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, GPT_CODE) Gpt_DisableNotification(Gpt_ChannelType Channel);

#endif

#if (STD_ON == GPT_CFG_WAKEUP_FUNCTIONALITY_API)
/** \brief Gpt_SetMode : Sets the operation mode of the GPT. */
FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode);

/** \brief Gpt_DisableWakeup : Disables the wakeup interrupt of a channel (relevant in sleep mode).
 */
FUNC(void, GPT_CODE) Gpt_DisableWakeup(Gpt_ChannelType Channel);

/** \brief Gpt_EnableWakeup : Enables the wakeup interrupt of a channel (relevant in sleep mode). */
FUNC(void, GPT_CODE) Gpt_EnableWakeup(Gpt_ChannelType Channel);

/** \brief Gpt_CheckWakeup : Checks if a wakeup capable GPT channel is the source for a wakeup event
 * and calls the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup
 * event. */
FUNC(void, GPT_CODE) Gpt_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* GPT_H */
/*********************************************************************************************************************
 *  End of File: Gpt.h
 *********************************************************************************************************************/
