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
 *  File:       Cdd_Pwm_Priv.h
 *  Generator:  None
 *
 *  Description:   This file contains data structures and function declarations of the private APIs.
 *********************************************************************************************************************/
#ifndef CDD_PWM_PRIV_H
#define CDD_PWM_PRIV_H

/** \addtogroup CDD_PWM
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm.h"
#include "hw_epwm.h"
#include "hw_asysctl.h"
#include "Mcal_Lib.h"
#include "Os.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_PWM_MAX_DUTY_CYCLE (0x8000U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
typedef enum
{
    CDD_PWM_AQ_OUTPUT_NO_CHANGE = 0U, /** \brief No change in the output pins */
    CDD_PWM_AQ_OUTPUT_LOW       = 1U, /** \brief Set output pins to low */
    CDD_PWM_AQ_OUTPUT_HIGH      = 2U, /** \brief Set output pins to High */
    CDD_PWM_AQ_OUTPUT_TOGGLE    = 3U  /** \brief Toggle the output pins */
} Cdd_Pwm_AQOutputType;

/** \brief Cdd_Pwm_AQOutputEvtType output defines the action qualifier event type */
typedef enum
{
    /** \brief Time base counter equals zero */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO = 0U,
    /** \brief T1 event on count up */
    CDD_PWM_AQ_OUTPUT_ON_T1_COUNT_UP = 1U,
    /** \brief Time base counter equals period */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD = 2U,
    /** \brief T1 event on count down */
    CDD_PWM_AQ_OUTPUT_ON_T1_COUNT_DOWN = 3U,
    /** \brief Time base counter up equals COMPA */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA = 4U,
    /** \brief T2 event on count up */
    CDD_PWM_AQ_OUTPUT_ON_T2_COUNT_UP = 5U,
    /** \brief Time base counter down equals COMPA */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA = 6U,
    /** \brief T2 event on count down */
    CDD_PWM_AQ_OUTPUT_ON_T2_COUNT_DOWN = 7U,
    /** \brief Time base counter up equals COMPB */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB = 8U,
    /** \brief Time base counter down equals COMPB */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB = 10U
} Cdd_Pwm_AQOutputEvtType;

/** \brief Action qualifier continuous force type */
typedef enum
{
    /** \brief Shadow mode load when counter equals zero */
    CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO = 0U,
    /** \brief Shadow mode load when counter equals period */
    CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_PERIOD = 1U,
    /** \brief Shadow mode load when counter equals zero or period */
    CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO_PERIOD = 2U,
    /** \brief No shadow load mode. Immediate mode only */
    CDD_PWM_AQ_SW_IMMEDIATE_LOAD = 3U
} Cdd_Pwm_ActionQualifierContForceType;

/** \brief Action qualifier Shadow mode load mode */
typedef enum
{
    /* Load when counter equals zero */
    CDD_PWM_AQ_LOAD_ON_CNTR_ZERO = 0U,
    /* Load when counter equals period */
    CDD_PWM_AQ_LOAD_ON_CNTR_PERIOD = 1U,
    /* Load when counter equals zero or period */
    CDD_PWM_AQ_LOAD_ON_CNTR_ZERO_PERIOD = 2U,
    /* Freeze shadow to active load */
    CDD_PWM_AQ_LOAD_FREEZE = 3U,
    /* Load on sync or when counter equals zero */
    CDD_PWM_AQ_LOAD_ON_SYNC_CNTR_ZERO = 4U,
    /* Load on sync or when counter equals period */
    CDD_PWM_AQ_LOAD_ON_SYNC_CNTR_PERIOD = 5U,
    /* Load on sync or when counter equals zero or period */
    CDD_PWM_AQ_LOAD_ON_SYNC_CNTR_ZERO_PERIOD = 6U,
    /* Load on sync only */
    CDD_PWM_AQ_LOAD_ON_SYNC_ONLY = 8U
} Cdd_Pwm_ActionQualifierLoadModeType;

/** \brief Action qualifier Shadow mode load mode */
typedef enum
{
    /* Load when counter equals zero */
    CDD_PWM_COMP_LOAD_ON_CNTR_ZERO = 0U,
    /* Load when counter equals period */
    CDD_PWM_COMP_LOAD_ON_CNTR_PERIOD = 1U,
    /* Load when counter equals zero or period */
    CDD_PWM_COMP_LOAD_ON_CNTR_ZERO_PERIOD = 2U,
    /* Freeze shadow to active load */
    CDD_PWM_COMP_LOAD_FREEZE = 3U,
    /* Load on sync or when counter equals zero */
    CDD_PWM_COMP_LOAD_ON_SYNC_CNTR_ZERO = 4U,
    /* Load on sync or when counter equals period */
    CDD_PWM_COMP_LOAD_ON_SYNC_CNTR_PERIOD = 5U,
    /* Load on sync or when counter equals zero or period */
    CDD_PWM_COMP_LOAD_ON_SYNC_CNTR_ZERO_PERIOD = 6U,
    /* Load on sync only */
    CDD_PWM_COMP_LOAD_ON_SYNC_ONLY = 8U
} Cdd_Pwm_CounterCompareLoadModeType;

/** \brief Period load mode type */
typedef enum
{
    /** \brief PWM Period register access is through shadow register */
    CDD_PWM_PERIOD_SHADOW_LOAD = 0U,
    /** \brief PWM Period register access is directly */
    CDD_PWM_PERIOD_DIRECT_LOAD = 1U
} Cdd_Pwm_PeriodLoadType;

/* Enumeration for action qualifier output type */
typedef enum
{
    CDD_PWM_AQ_SW_DISABLED    = 0U, /** \brief Software forcing disabled */
    CDD_PWM_AQ_SW_OUTPUT_LOW  = 1U, /** \brief Set output pins to low*/
    CDD_PWM_AQ_SW_OUTPUT_HIGH = 2U  /** \brief Set output pins to High*/
} Cdd_Pwm_ActionQualifierSwOutputType;

/** \brief Enumeration to define the time base counter mode */
typedef enum
{
    CDD_PWM_COUNTER_MODE_UP          = 0U, /** \brief Up - count mode */
    CDD_PWM_COUNTER_MODE_DOWN        = 1U, /** \brief Down - count mode */
    CDD_PWM_COUNTER_MODE_UP_DOWN     = 2U, /** \brief Up - down - count mode */
    CDD_PWM_COUNTER_MODE_STOP_FREEZE = 3U  /** \brief Stop - Freeze counter */
} Cdd_Pwm_TimeBaseCountModeType;

/* Enumeration for interrupt sources */
typedef enum
{
    /** \brief No event selected */
    CDD_PWM_ETMIX_TBCTR_NONE = 0x0U,
    /** \brief Time-base counter equal to zero */
    CDD_PWM_ETMIX_TBCTR_ZERO = 0x1U,
    /** \brief Time-base counter equal to period */
    CDD_PWM_ETMIX_TBCTR_PERIOD = 0x2U,
    /** \brief Time-base counter equal to CMPA when the timer is incrementing */
    CDD_PWM_ETMIX_TBCTR_U_CMPA = 0x4U,
    /** \brief Time-base counter equal to CMPA when the timer is decrementing */
    CDD_PWM_ETMIX_TBCTR_D_CMPA = 0x8U,
    /** \brief Time-base counter equal to CMPB when the timer is incrementing */
    CDD_PWM_ETMIX_TBCTR_U_CMPB = 0x10U,
    /** \brief Time-base counter equal to CMPB when the timer is decrementing */
    CDD_PWM_ETMIX_TBCTR_D_CMPB = 0x20U,
    /** \brief Time-base counter equal to CMPC when the timer is incrementing */
    CDD_PWM_ETMIX_TBCTR_U_CMPC = 0x40U,
    /** \brief Time-base counter equal to CMPC when the timer is decrementing */
    CDD_PWM_ETMIX_TBCTR_D_CMPC = 0x80U,
    /** \brief Time-base counter equal to CMPD when the timer is incrementing */
    CDD_PWM_ETMIX_TBCTR_U_CMPD = 0x100U,
    /** \brief Time-base counter equal to CMPD when the timer is decrementing */
    CDD_PWM_ETMIX_TBCTR_D_CMPD = 0x200U,
    /** \brief Event is based on DCAEVT1 */
    CDD_PWM_ETMIX_DCAEVT1 = 0x400U
} Cdd_Pwm_EvtMixTriggerSourceType;

/** \brief Enumeration for interrupt source */
typedef enum
{
    /** \brief Time-base counter equal to zero */
    CDD_PWM_INT_TBCTR_ZERO = 1U,
    /** \brief Time-base counter equal to period */
    CDD_PWM_INT_TBCTR_PERIOD = 2U,
    /** \brief Time-base counter based on mixed events (ETINTMIX) */
    CDD_PWM_INT_TBCTR_ETINTMIX = 3U,
    /** \brief Time-base counter equal to CMPA or CMPC when the timer is incrementing */
    CDD_PWM_INT_TBCTR_U_CMP_A_OR_C = 4U,
    /** \brief Time-base counter equal to CMPA or CMPC when the timer is decrementing */
    CDD_PWM_INT_TBCTR_D_CMP_A_OR_C = 5U,
    /** \brief Time-base counter equal to CMPB or CMPD when the timer is incrementing */
    CDD_PWM_INT_TBCTR_U_CMP_B_OR_D = 6U,
    /** \brief Time-base counter equal to CMPB or CMPD when the timer is decrementing */
    CDD_PWM_INT_TBCTR_D_CMP_B_OR_D = 7U
} Cdd_Pwm_InterruptSourceType;

/** \brief Channel object structure */
typedef struct Cdd_Pwm_ChannelObjTag
{
    /** \brief Duty cycle of the PWM channel */
    Cdd_Pwm_DutyCycleType   dutycycle;
    /** \brief PWM channel status */
    boolean                 channel_status;
    /** \brief PWM channel update */
    boolean                 channel_update;
    /* Notification status */
    boolean                 notification_enable;
    /* Action qualifier action */
    Cdd_Pwm_AQOutputType    level1;
    Cdd_Pwm_AQOutputType    level2;
    Cdd_Pwm_AQOutputEvtType outputevt1;
    Cdd_Pwm_AQOutputEvtType outputevt2;
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /* Mixed event sources */
    boolean                         notification_status;
    Cdd_Pwm_EvtMixTriggerSourceType rising_event;
    Cdd_Pwm_EvtMixTriggerSourceType falling_event;
#endif
} Cdd_Pwm_ChannelObjType;

/** \brief Hardware object structure */
typedef struct Cdd_Pwm_HwUnitObjTag
{
    /** \brief Waveform period of the PWM channel */
    Cdd_Pwm_PeriodType period;
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /** \brief Notification channel type */
    Cdd_Pwm_NotificationChannelType channel_notification;
    /** \brief Edge notification type */
    Cdd_Pwm_EdgeNotificationType    edgenotifytype;
    /* Active channels */
    uint8                           notification_active;
#endif
    /** \brief Interrupt source of the PWM channel */
    uint8 eventcount;
} Cdd_Pwm_HwUnitObjType;

/** \brief Driver object structure */
typedef struct Cdd_Pwm_DriverObjTag
{
    /** \brief PWM channel object */
    Cdd_Pwm_ChannelObjType channelobj[CDD_PWM_CHANNEL_COUNT];
    /** \brief PWM channel object */
    Cdd_Pwm_HwUnitObjType  hwunitobj[CDD_PWM_COUNT];
    /** \brief Array to store the index of the hardware unit */
    uint8                  instanceindex[(CDD_PWM_INSTANCE_COUNT + 1U)];
} Cdd_Pwm_DriverObjType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Sets the driver object
 *
 * This private function sets the driver object
 *
 * \param[in]  DrvObj Driver object
 * \param[in]  CfgPtr Configuration pointer
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDrvObj(Cdd_Pwm_DriverObjType *DrvObj, const Cdd_Pwm_ConfigType *CfgPtr);

/** \brief Initializes the driver object
 *
 * This private function initializes the driver object parameters
 *
 * \param[in]  None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DrvObjInit(void);

/** \brief Initializes the Cdd Pwm driver
 *
 * This private function initializes the Cdd Pwm driver.
 *
 * \param[in]  None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HwUnitInit(void);

#if (CDD_PWM_SET_PERIOD_API == STD_ON)
/** \brief Service to set the period of the PWM hardware unit
 *
 * This service sets period for the requested PWM instance.
 *
 * \param[in] InstanceId     Numeric ID of the PWM hardware unit
 * \param[in] Period         Period for the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_UpdatePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_PeriodType, AUTOMATIC) Period);
#endif

/** \brief Service to set the duty cycle of the PWM channel
 *
 * This service sets duty cycle of the PWM channel
 *
 * \param[in] ChannelNumber     Numeric ID of the PWM channel
 * \param[in] DutyCycle         Requested duty cycle for the PWM Channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_UpdateDutyCycle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelNumber,
                        VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle);

#if (CDD_PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (CDD_PWM_DEINIT_API == STD_ON)
/** \brief Service to set the output of the PWM channel to the configured idle state
 *
 * This service sets the output of the PWM channel to the configured idle state
 *
 * \param[in] ChannelNumber     Numeric ID of the PWM channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetIdleOutput(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelNumber);
#endif

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/** \brief Service to enable the notification for the channel
 *
 * This service sets period and duty cycle for the requested PWM Channel.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Channel        Channel type for notification
 * \param[in] Notification   Notification type for the channel
 * \param[in] IntEvtCount    Number of configured events to be occurred to generate an interrupt
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_NotificationEnable(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_NotificationChannelType, AUTOMATIC) Channel,
                           VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) Notification,
                           VAR(uint8, AUTOMATIC) IntEvtCount);

/** \brief Service to disable the notification for the channel
 *
 * This service disables notification for the requested PWM Channel.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_NotificationDisable(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);
#endif

#if (STD_ON == CDD_PWM_DEINIT_API)
/** \brief De-initializes the Pwm driver
 *
 * This private function de-initializes the Pwm driver.
 *
 * \param[in]  None
 * \param[out] None
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HwUnitDeinit(void);
#endif

/** \brief Interrupt service routine
 *
 * This function is called inside the ISR to clear the interrupt flags
 *
 * \param[in]  InstanceId
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ProcessIsr(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* CDD_PWM_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Priv.h
 *********************************************************************************************************************/
