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

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm.h"
#include "hw_epwm.h"
#include "Os.h"
#include "hw_sysctl.h"
#include "hw_types.h"
#include "hw_memmap.h"

#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)

#define CDD_PWM_MAX_DUTY_CYCLE (0x8000U)

#else

#define EPWM_O_XCMP  0x0400U
#define EPWM_O_DE    0x0800U
#define EPWM_O_MINDB 0x0C00U

#endif

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)

/* Enumeration for interrupt sources*/
typedef enum
{
    /** \brief No event selected*/
    CDD_PWM_ETMIX_TBCTR_NONE = 0x0U,
    /** \brief Time-base counter equal to zero*/
    CDD_PWM_ETMIX_TBCTR_ZERO = 0x1U,
    /** \brief Time-base counter equal to period*/
    CDD_PWM_ETMIX_TBCTR_PERIOD = 0x2U,
    /** \brief Time-base counter equal to CMPA when the timer is incrementing*/
    CDD_PWM_ETMIX_TBCTR_U_CMPA = 0x4U,
    /** \brief Time-base counter equal to CMPA when the timer is decrementing*/
    CDD_PWM_ETMIX_TBCTR_D_CMPA = 0x8U,
    /** \brief Time-base counter equal to CMPB when the timer is incrementing*/
    CDD_PWM_ETMIX_TBCTR_U_CMPB = 0x10U,
    /** \brief Time-base counter equal to CMPB when the timer is decrementing*/
    CDD_PWM_ETMIX_TBCTR_D_CMPB = 0x20U,
    /** \brief Time-base counter equal to CMPC when the timer is incrementing*/
    CDD_PWM_ETMIX_TBCTR_U_CMPC = 0x40U,
    /** \brief Time-base counter equal to CMPC when the timer is decrementing*/
    CDD_PWM_ETMIX_TBCTR_D_CMPC = 0x80U,
    /** \brief Time-base counter equal to CMPD when the timer is incrementing*/
    CDD_PWM_ETMIX_TBCTR_U_CMPD = 0x100U,
    /** \brief Time-base counter equal to CMPD when the timer is decrementing*/
    CDD_PWM_ETMIX_TBCTR_D_CMPD = 0x200U,
    /** \brief Event is based on DCAEVT1*/
    CDD_PWM_ETMIX_DCAEVT1 = 0x400U
} Cdd_Pwm_EvtMixTriggerSourceType;

/* Design: MCAL-33885 */
/** \brief Channel object structure*/
typedef struct Cdd_Pwm_ChannelObjTag
{
    /* Duty cycle of the PWM channel*/
    Cdd_Pwm_DutyCycleType                  dutycycle;
    /* Determines whether any edges are present on the channel output waveform (Duty cycle other than 0% or 100%) */
    boolean                                channel_active;
    /* Defines the notification status of the channel */
    boolean                                channelnotif_enable;
    /* Action qualifier output actions */
    Cdd_Pwm_ActionQualifierOutputType      level1;
    Cdd_Pwm_ActionQualifierOutputType      level2;
    /* Action qualifier output events */
    Cdd_Pwm_ActionQualifierOutputEventType outputevt1;
    Cdd_Pwm_ActionQualifierOutputEventType outputevt2;

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /* Event configured for rising event*/
    Cdd_Pwm_EvtMixTriggerSourceType rising_event;
    /* Event configured for falling event*/
    Cdd_Pwm_EvtMixTriggerSourceType falling_event;
    /** \brief Edge notification type*/
    Cdd_Pwm_EdgeNotificationType    edgenotifytype;
#endif
} Cdd_Pwm_ChannelObjType;

/** \brief Hardware object structure*/
typedef struct Cdd_Pwm_HwUnitObjTag
{
    /** \brief Waveform period of the PWM instance */
    Cdd_Pwm_PeriodType period;
    /* Interrupt event count of the PWM instance */
    uint16             inteventcount;
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /* Trip-zone interrupt notification enable */
    uint8 tripzone_notification;
    /* Interrupt notification enable */
    uint8 notification_enable;
#endif
    /* Active channels with TBCTR=ZERO as the interrupt source*/
    uint8 zero_active;
} Cdd_Pwm_HwUnitObjType;

/** \brief Driver object structure*/
typedef struct Cdd_Pwm_DriverObjTag
{
    /** \brief PWM channel object*/
    Cdd_Pwm_ChannelObjType channelobj[CDD_PWM_CHANNEL_COUNT];
    /** \brief PWM channel object*/
    Cdd_Pwm_HwUnitObjType  hwunitobj[CDD_PWM_COUNT];
    /** \brief Array to store the index of the hardware unit*/
    uint8                  instanceindex[(CDD_PWM_INSTANCE_COUNT + 1U)];
} Cdd_Pwm_DriverObjType;

#endif

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

/* Design: MCAL-33886 */
/** \brief Hardware object structure*/
typedef struct Cdd_Pwm_HwUnitObjTag
{
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    boolean notification_enable;
    boolean tripzone_notification;
#endif
} Cdd_Pwm_HwUnitObjType;

/* Design: MCAL-33884 */
/** \brief Driver object structure*/
typedef struct Cdd_Pwm_DriverObjTag
{
    /* Hardware unit object to store the notification status*/
    Cdd_Pwm_HwUnitObjType hwunitobj[CDD_PWM_COUNT];
    /** \brief Array to store the index of the hardware unit*/
    uint8                 instanceindex[(CDD_PWM_INSTANCE_COUNT + 1U)];
} Cdd_Pwm_DriverObjType;
#endif

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
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetDrvObj(Cdd_Pwm_DriverObjType* DrvObj, const Cdd_Pwm_ConfigType* CfgPtr);

/** \brief Initializes the driver object
 *
 * This private function initializes the driver object parameters
 *
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
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HwUnitInit(void);

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)
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
/** \brief Service to set the Output of the PWM channel to the configured idle state
 *
 * This service sets the Output of the PWM channel to the configured idle state
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
 * This service enables notifications for the requested PWM Channel.
 *
 * \param[in] Channel          Numeric ID of the PWM channel
 * \param[in] EdgeNotification Edge notification type for the channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_NotificationEnable(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) Channel,
                           VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification);

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
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HwUnitDeinit(void);
#endif
#endif

/** \brief Sets up the Counter Compare shadow load mode
 *
 * This function enables and sets up the counter compare shadow load mode.
 * Valid values for the variables are:
 *  - CompModule
 *      - CDD_PWM_COUNTER_COMPARE_A - counter compare A.
 *      - CDD_PWM_COUNTER_COMPARE_B - counter compare B.
 *      - CDD_PWM_COUNTER_COMPARE_C - counter compare C.
 *      - CDD_PWM_COUNTER_COMPARE_D - counter compare D.
 *  - LoadMode
 *      - CDD_PWM_COMP_LOAD_ON_CNTR_ZERO - load when counter equals zero
 *      - CDD_PWM_COMP_LOAD_ON_CNTR_PERIOD - load when counter equals period
 *      - CDD_PWM_COMP_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals
 *                                             zero or period
 *      - CDD_PWM_COMP_LOAD_FREEZE  - Freeze shadow to active load
 *      - CDD_PWM_COMP_LOAD_ON_SYNC_CNTR_ZERO - load when counter equals zero
 *      - CDD_PWM_COMP_LOAD_ON_SYNC_CNTR_PERIOD -load when counter equals period
 *      - CDD_PWM_COMP_LOAD_ON_SYNC_CNTR_ZERO_PERIOD - load when counter equals
 *                                                  zero or period
 *      - CDD_PWM_COMP_LOAD_ON_SYNC_ONLY - load on sync only
 *
 * \param[in] Base              Base address of the PWM instance.
 * \param[in] CompModule     Counter compare module.
 * \param[in] LoadMode       Shadow to active load mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetCounterCompareShadowLoadMode(VAR(uint32, AUTOMATIC) Base,
                                            VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                                            VAR(Cdd_Pwm_CounterCompareLoadModeType, AUTOMATIC) LoadMode);

/** \brief Set the time base count
 *
 * This function sets the 16 bit counter value of the time base counter.
 *
 * \param[in] Base              Base address of the PWM instance
 * \param[in] Count          Time base count value.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivSetTimeBaseCounter(VAR(uint32, AUTOMATIC) Base, VAR(uint16, AUTOMATIC) Count);

/** \brief Service to set emulation mode
 *
 * This function sets the emulation behaviours of the time base counter. Valid
 * values for emulationMode are:
 *  - CDD_PWM_EMULATION_STOP_AFTER_NEXT_TB    - Stop after next Time Base counter
 *                                           increment or decrement.
 *  - CDD_PWM_EMULATION_STOP_AFTER_FULL_CYCLE - Stop when counter completes whole
 *                                           cycle.
 *  - CDD_PWM_EMULATION_FREE_RUN               - Free run.
 *
 * \param[in] Base              Base address of the PWM instance
 * \param[in] EmulationMode   Emulation Mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetEmulationMode(VAR(uint32, AUTOMATIC) Base, VAR(Cdd_Pwm_EmulationModeType, AUTOMATIC) EmulationMode);

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

/** \brief Sets the PWM period count
 *
 * This function sets the period of the PWM count. The value of PeriodCount is
 * the value written to the register. User should map the desired period or
 * frequency of the waveform into the correct PeriodCount.
 * Invoke the function Cdd_Pwm_SelectPeriodLoadEvent() with the appropriate
 * parameter to set the load mode of the Period count. PeriodCount has a
 * maximum valid value of 0xFFFF
 *
 * \param[in] Base              Base address of the PWM instance
 * \param[in] PeriodCount    Period count value.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivSetTimeBasePeriod(VAR(uint32, AUTOMATIC) Base, VAR(uint16, AUTOMATIC) PeriodCount);

/** \brief Set time base counter mode
 *
 * This function sets up the time base counter mode.
 * Valid values for CounterMode are:
 *  - CDD_PWM_COUNTER_MODE_UP          - Up - count mode.
 *  - CDD_PWM_COUNTER_MODE_DOWN        - Down - count mode.
 *  - CDD_PWM_COUNTER_MODE_UP_DOWN     - Up - down - count mode.
 *  - CDD_PWM_COUNTER_MODE_STOP_FREEZE - Stop - Freeze counter.
 *
 * \param[in] Base              Base address of the PWM instance
 * \param[in] CounterMode    Time base counter mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTimeBaseCounterMode(VAR(uint32, AUTOMATIC) Base,
                                   VAR(Cdd_Pwm_TimeBaseCountModeType, AUTOMATIC) CounterMode);

/** \brief Sets the Action Qualifier shadow load mode
 *
 * This function enables and sets the Action Qualifier shadow load mode.
 * Valid values for the variables are:
 *  - OutputChannel
 *      - CDD_PWM_ACTION_QUALIFIER_A - Action Qualifier A.
 *      - CDD_PWM_ACTION_QUALIFIER_B - Action Qualifier B.
 *  - LoadMode
 *      - CDD_PWM_AQ_LOAD_ON_CNTR_ZERO - load when counter equals zero
 *      - CDD_PWM_AQ_LOAD_ON_CNTR_PERIOD - load when counter equals period
 *      - CDD_PWM_AQ_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals
 *                                               zero or period
 *      - CDD_PWM_AQ_LOAD_FREEZE  - Freeze shadow to active load
 *      - CDD_PWM_AQ_LOAD_ON_SYNC_CNTR_ZERO - load on sync or when counter
 *                                          equals zero
 *      - CDD_PWM_AQ_LOAD_ON_SYNC_CNTR_PERIOD - load on sync or when counter
 *                                           equals period
 *      - CDD_PWM_AQ_LOAD_ON_SYNC_CNTR_ZERO_PERIOD - load on sync or when
 *                                               counter equals zero or period
 *      - CDD_PWM_AQ_LOAD_ON_SYNC_ONLY - load on sync only
 *
 * \param[in] Base              Base address of the PWM instance
 * \param[in] OutputChannel  Action Qualifier module value.
 * \param[in] LoadMode       Shadow to active load mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierShadowLoadMode(VAR(uint32, AUTOMATIC) Base,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(Cdd_Pwm_ActionQualifierLoadModeType, AUTOMATIC) LoadMode);

/** \brief Sets the ePWM interrupt event count.
 *
 * Set interrupt count.
 *
 * \param[in] Base is the base address of the EPWM module.
 * \param[in] EventCount is the ePWM interrupt count value.
 *
 * This function sets the interrupt event count that determines the number of
 * events that have to occur before an interrupt is issued.
 * Maximum value for eventCount is 15.
 *
 * \return None.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetInterruptEventCount(VAR(uint32, AUTOMATIC) Base, VAR(uint16, AUTOMATIC) EventCount);

/** \brief Enable/disable ePWM interrupt
 *
 * This function enables//disables the ePWM interrupt.
 *
 * \param[in] Base              Base address of the PWM instance
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivConfigureInterrupt(VAR(uint32, AUTOMATIC) Base, VAR(boolean, AUTOMATIC) Select);

/** \brief Sets the ePWM interrupt source
 *
 * This function sets the ePWM interrupt source.
 *
 * \param[in] Base              Base address of the PWM instance
 * \param[in] InterruptSource  ePWM interrupt source with valid values:
 *                             - CDD_PWM_INT_TBCTR_DISABLED       - Time-base counter is disabled
 *                             - CDD_PWM_INT_TBCTR_ZERO           - Time-base counter equal to zero
 *                             - CDD_PWM_INT_TBCTR_PERIOD         - Time-base counter equal to period
 *                             - CDD_PWM_INT_TBCTR_ZERO_OR_PERIOD - Time-base counter equal to zero or period
 *                             - CDD_PWM_INT_TBCTR_ETINTMIX       - Time-base counter based on mixed events (ETINTMIX)
 *                             - CDD_PWM_INT_TBCTR_U_CMP         - Where x is AU,BU,C or D
 *                                                               Time-base counter equal to CMPAU, CMPBU,
 *                                                               CMPC or CMPD (depending the value of x)
 *                                                               when the timer is incrementing
 *                             - CDD_PWM_INT_TBCTR_D_CMP         - Where x is AU,BU,C or D
 *                                                               Time-base counter equal to CMPAU, CMPBU,
 *                                                               CMPC or CMPD (depending the value of x)
 *                                                               when the timer is decrementing
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetInterruptSource(uint32 Base, VAR(Cdd_Pwm_InterruptSourceType, AUTOMATIC) InterruptSource);

/** \brief Clear interrupt flag
 *
 * This function clears the ePWM interrupt flag.
 *
 * \param[in] Base              Base address of the PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivClearEventTriggerInterruptFlag(VAR(uint32, AUTOMATIC) Base);

/** \brief Set the time base clock and the high speed time base clock count pre-scaler
 *
 * This function sets the pre scaler(divider)value for the time base clock
 * counter and the high speed time base clock counter.
 * Valid values for pre-scaler and highSpeedPrescaler are CDD_PWM_CLOCK_DIVIDER_X,
 * where X is 1,2,4,8,16,32,64 or 128.
 * The actual numerical values for these macros represent values 0U,1...7.
 * The equation for the output clock is:
 *   TBCLK = EPWMCLK/(highSpeedPrescaler* pre-scaler)
 *
 * \b Note: EPWMCLK is a scaled version of SYSCLK. At reset EPWMCLK is half
 *          SYSCLK.
 *
 * \param[in] Base              Base address of the PWM instance
 * \param[in] Prescaler           Time base count pre scale value.
 * \param[in] HighSpeedPrescaler  High speed time base count pre scale value.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetClockPrescaler(VAR(uint32, AUTOMATIC) Base, VAR(Cdd_Pwm_ClockDividerType, AUTOMATIC) Prescaler,
                              VAR(Cdd_Pwm_HighSpeedClkDivType, AUTOMATIC) HighSpeedPrescaler);

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

/** \brief Trip-zone Interrupt service routine
 *
 * This function is called inside the trip-zone ISR to clear the trip-zone interrupt flags
 *
 * \param[in]  InstanceId
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ProcessTripZoneIsr(Cdd_Pwm_InstanceType InstanceId);

/** \brief Set interrupt count
 *
 * This function sets the ePWM interrupt count. eventCount is the value of the
 * pre-interrupt value that is to be loaded. The maximum value of eventCount
 * is 15.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] EventCount    The ePWM interrupt count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetInterruptEventCountInitValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(uint16, AUTOMATIC) EventCount);

/** \brief Set count mode after phase shift sync
 *
 * This function sets the time base count to count up or down after a new
 * phase value set by the Cdd_Pwm_SetPhaseShift(). The count direction is
 * determined by the variable mode. Valid inputs for mode are:
 *  - CDD_PWM_COUNT_MODE_UP_AFTER_SYNC      - Count up after sync
 *  - CDD_PWM_COUNT_MODE_DOWN_AFTER_SYNC    - Count down after sync
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Mode           Count mode after sync.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetCountModeAfterSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_SyncCountModeType, AUTOMATIC) Mode);

/** \brief Force a software sync pulse
 *
 * This function causes a single software initiated sync pulse. Make sure the
 * appropriate mode is selected using Cdd_Pwm_SetupSyncOutputMode() before using
 * this function.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceSyncPulse(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set up the source for sync-in pulse
 *
 * This function set the sync out pulse mode.
 * Valid values for mode are:
 *  - CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1-16 - sync-in pulse source can be
 *                                              any of the EPWM1-16 sync-out
 *                                              signal
 *  - CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1-7 - sync-in pulse source can be
 *                                             selected as any of the ECAP1-16
 *                                             sync-out signal
 *  - CDD_PWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5-6 - sync-in pulse source can be
 *                                              selected as any of the Input
 *                                              xbar out5-6 signal
 *  - CDD_PWM_SYNC_IN_PULSE_SRC_ETHERCAT_SYNC0-1 - sync-in pulse source can be
 *                                              selected as any of the Ethercat
 *                                              sync0-1 signal
 *  - CDD_PWM_SYNC_IN_PULSE_SRC_DISABLE - sync-in pulse is disabled for the
 *                                     CDD_PWM module
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Source         Sync-in pulse source.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetSyncInPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_SyncInPulseSourceType, AUTOMATIC) Source);

/** \brief Enables sync-out pulse source
 *
 * This function enables the sync-out pulse source.
 * Below valid values for param \b Source can be OR'd together to enable
 * multiple sync-out sources:
 * - CDD_PWM_SYNC_OUT_PULSE_ON_SOFTWARE - sync-out pulse is generated by
 *                                     software when Cdd_Pwm_ForceSyncPulse()
 *                                     function is called or by EPWMxSYNCI
 *                                     signal.
 * - CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_ZERO - sync-out pulse is generated when
 *                                      time base counter equals zero.
 * - CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_B - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           B value.
 * - CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_C - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           C value.
 * - CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_D - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           D value.
 * - CDD_PWM_SYNC_OUT_PULSE_ON_DCA_EVT1_SYNC - sync-out pulse is generated by DCA
 *                                          event1 sync signal
 * - CDD_PWM_SYNC_OUT_PULSE_ON_DCB_EVT1_SYNC - sync-out pulse is generated by DCB
 *                                          event1 sync signal
 * - CDD_PWM_SYNC_OUT_PULSE_ON_ALL  - sync-out pulse is generated by all
 *                                 the above sources
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Source         Sync-out pulse source.
 * \param[in] Select         Boolean to enable/disable the source.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureSyncOutPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_SyncOutPulseSourceType, AUTOMATIC) Source,
                                        VAR(boolean, AUTOMATIC) Select);

/** \brief Set up the one-shot sync-out trigger source
 *
 * This function sets the one-shot sync-out trigger source.
 * Valid values for param \b Trigger are:
 *  - CDD_PWM_OSHT_SYNC_OUT_TRIG_SYNC - Trigger for one-shot sync-out signal is
 *                                    one-shot sync event.
 *  - CDD_PWM_OSHT_SYNC_OUT_TRIG_RELOAD - Trigger for one-shot sync-out signal is
 *                                     one-shot reload event.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Trigger        One-shot sync-out signal trigger source.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetOneShotSyncOutTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OneShotSyncOutTriggerType, AUTOMATIC) Trigger);

/** \brief Set PWM period load mode
 *
 * This function sets the load mode for the PWM period. If LoadMode is set to
 * EPWM_PERIOD_SHADOW_LOAD, a write or read to the TBPRD (PWM Period count
 * register) accesses the shadow register. If LoadMode is set to
 * EPWM_PERIOD_DIRECT_LOAD, a write or read to the TBPRD register accesses the
 * register directly.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] LoadMode       PWM period load mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetPeriodLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_PeriodLoadModeType, AUTOMATIC) LoadMode);

/** \brief Enable phase shift load
 *
 * This function enables loading of phase shift when the appropriate sync event occurs.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Select         Boolean to enable/disable phase shift load.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set shadow to active period load on sync mode
 *
 * This function sets up the shadow to active Period register load mode with
 * respect to a sync event. Valid values for ShadowLoadMode are:
 *  - CDD_PWM_SHADOW_LOAD_MODE_COUNTER_ZERO - shadow to active load occurs when
 *                                         time base counter reaches 0.
 *  - CDD_PWM_SHADOW_LOAD_MODE_COUNTER_SYNC - shadow to active load occurs when
 *                                         time base counter reaches 0 and a
 *                                         SYNC occurs.
 *  - CDD_PWM_SHADOW_LOAD_MODE_SYNC         - shadow to active load occurs only
 *                                         when a SYNC occurs.
 *
 * \param[in] InstanceId          Numeric ID of the requested PWM instance
 * \param[in] ShadowLoadMode    Shadow to active load mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectPeriodLoadEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_PeriodShadowLoadModeType, AUTOMATIC) ShadowLoadMode);

/** \brief Enable one shot sync mode
 *
 * This function enables one shot sync mode.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Select         Boolean to enable/disable one shot sync mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureOneShotSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Start one shot sync mode
 *
 * This function propagates a one shot sync pulse.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivStartOneShotSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Returns time base counter value
 *
 * This function returns the current value of the time base counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return Time base counter value
 * \retval uint16 Current value of the time base counter
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetTimeBaseCounterValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return time base counter maximum status
 *
 * This function returns the status of the time base max counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return Status of time base counter overflow
 * \retval boolean True if the counter has reached 0xFFFF, false otherwise
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetTimeBaseCounterOverflowStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable/Disable EPWM XLINK
 *
 * This function enables/disables EPWM XLINK for the specified EPWM instance
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select        Enable/Disable select
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureEpwmXLink(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Clear max time base counter event
 *
 * This function clears the max time base counter latch event. The latch event
 * occurs when the time base counter reaches its maximum value of 0xFFFF.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivClearTimeBaseCounterOverflowEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return external sync signal status
 *
 * This function returns the external sync signal status.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return Status of external sync signal
 * \retval boolean True if an external sync signal event occurred, false otherwise
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_PrivGetSyncStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Clear external sync signal event
 *
 * This function clears the external sync signal latch event.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivClearSyncEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return time base counter direction
 *
 * This function returns the direction of the time base counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return Counter direction status
 * \retval uint16 CDD_PWM_TIME_BASE_STATUS_COUNT_UP if counting up or
 *                CDD_PWM_TIME_BASE_STATUS_COUNT_DOWN if counting down
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetTimeBaseCounterDirection(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Sets the phase shift offset counter value
 *
 * This function sets the 16 bit time-base counter phase of the ePWM relative
 * to the time-base that is supplying the synchronization input signal. Call
 * the EPWM_enablePhaseShiftLoad() function to enable loading of the
 * PhaseCount phase shift value when a sync event occurs.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] PhaseCount     Phase shift count value.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) PhaseCount);

/** \brief Gets the PWM period count
 *
 * This function gets the period of the PWM count.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return The period count value
 * \retval uint16 Current period count value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Disables counter compare shadow load mode
 *
 * This function disables counter compare shadow load mode.
 * Valid values for the variables are:
 *  - CompModule
 *      - CDD_PWM_COUNTER_COMPARE_A - counter compare A.
 *      - CDD_PWM_COUNTER_COMPARE_B - counter compare B.
 *      - CDD_PWM_COUNTER_COMPARE_C - counter compare C.
 *      - CDD_PWM_COUNTER_COMPARE_D - counter compare D.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] CompModule     Counter compare module.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableCounterCompareShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule);

/** \brief Sets counter compare values
 *
 * This function sets the counter compare value for counter compare registers.
 * The maximum value for CompCount is 0xFUFFF.
 * Valid values for CompModule are:
 *   - CDD_PWM_COUNTER_COMPARE_A - counter compare A.
 *   - CDD_PWM_COUNTER_COMPARE_B - counter compare B.
 *   - CDD_PWM_COUNTER_COMPARE_C - counter compare C.
 *   - CDD_PWM_COUNTER_COMPARE_D - counter compare D.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] CompModule     Counter Compare value module.
 * \param[in] CompCount      Counter compare count value.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                                   VAR(uint16, AUTOMATIC) CompCount);

/** \brief Gets counter compare values
 *
 * This function gets the counter compare value for counter compare registers.
 * Valid values for CompModule are:
 *   - CDD_PWM_COUNTER_COMPARE_A - counter compare A.
 *   - CDD_PWM_COUNTER_COMPARE_B - counter compare B.
 *   - CDD_PWM_COUNTER_COMPARE_C - counter compare C.
 *   - CDD_PWM_COUNTER_COMPARE_D - counter compare D.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] CompModule     Counter Compare value module.
 * \pre None
 * \post None
 * \return The counter compare count value.
 * \retval uint16 Counter compare value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule);

/** \brief Returns the counter compare shadow register full status
 *
 * This function returns the counter Compare shadow register full status flag.
 * Valid values for OuputChannel are:
 *   - CDD_PWM_COUNTER_COMPARE_A - counter compare A.
 *   - CDD_PWM_COUNTER_COMPARE_B - counter compare B.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] OuputChannel   Counter Compare value module.
 * \pre None
 * \post None
 * \return Shadow register full status
 * \retval TRUE  If the shadow register is full.
 * \retval FALSE If the shadow register is not full.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetCounterCompareShadowStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OuputChannel);

/** \brief Enables CMPAHR, CMPBHR register linking
 *
 * This function enables CMPAHR and CMPBHR register linking. CMPBHR assumes
 * the same value as CMPAHR.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Select         Enable/disable selection.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureLinkDutyHR(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/**
 * Action Qualifier module related APIs
 */

/** \brief Disables Action Qualifier shadow load mode
 *
 * This function disables the Action Qualifier shadow load mode.
 * Valid values for the variables are:
 *  - OutputChannel
 *      - CDD_PWM_ACTION_QUALIFIER_A - Action Qualifier A.
 *      - CDD_PWM_ACTION_QUALIFIER_B - Action Qualifier B.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] OutputChannel  Action Qualifier module value.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableActionQualifierShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/** \brief Sets up Action qualifier trigger source for event T1
 *
 * This function sets up the sources for Action Qualifier event T1.
 * Valid values for Trigger are:
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCA_1       - Digital compare event A 1
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCA_2       - Digital compare event A 2
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCB_1       - Digital compare event B 1
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCB_2       - Digital compare event B 2
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_1        - Trip zone 1
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_2        - Trip zone 2
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_3U        - Trip zone 3U
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_CDD_PWM_SYNCIN - CDD_PWM sync
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT  - Digital compare filter event
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Trigger        Sources for Action Qualifier triggers.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierT1TriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_ActionQualifierTriggerSourceType, AUTOMATIC) Trigger);

/** \brief Sets up Action qualifier trigger source for event T2
 *
 * This function sets up the sources for Action Qualifier event T2.
 * Valid values for Trigger are:
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCA_1       - Digital compare event A 1
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCA_2       - Digital compare event A 2
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCB_1       - Digital compare event B 1
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCB_2       - Digital compare event B 2
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_1        - Trip zone 1
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_2        - Trip zone 2
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_3U        - Trip zone 3U
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_CDD_PWM_SYNCIN - CDD_PWM sync
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT  - Digital compare filter event
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Trigger        Sources for Action Qualifier triggers.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierT2TriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_ActionQualifierTriggerSourceType, AUTOMATIC) Trigger);

/** \brief Sets up Action qualifier outputs
 *
 * This function sets up the Action Qualifier output on ePWM A or ePWMB,
 * depending on the value of EpwmOutput, to a value specified by Output based
 * on the input events - specified by Event.
 * The following are valid values for the parameters.
 *   - CDD_pwmOutput
 *       - CDD_PWM_AQ_OUTPUT_A          - CDD_PWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - CDD_PWMxB output
 *   - Output
 *       - CDD_PWM_AQ_OUTPUT_NO_CHANGE  - No change in the output pins
 *       - CDD_PWM_AQ_OUTPUT_LOW        - Set output pins to low
 *       - CDD_PWM_AQ_OUTPUT_HIGH       - Set output pins to High
 *       - CDD_PWM_AQ_OUTPUT_TOGGLE     - Toggle the output pins
 *   - Event
 *       - CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO       - Time base counter equals
 *                                                 zero
 *       - CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD     - Time base counter equals
 *                                                 period
 *       - CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA    - Time base counter up equals
 *                                                 COMPA
 *       - CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA  - Time base counter down
 *                                                 equals COMPA
 *       - CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB    - Time base counter up equals
 *                                                 COMPB
 *       - CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB  - Time base counter down
 *                                                 equals COMPB
 *       - CDD_PWM_AQ_OUTPUT_ON_T1_COUNT_UP         - T1 event on count up
 *       - CDD_PWM_AQ_OUTPUT_ON_T1_COUNT_DOWN       - T1 event on count down
 *       - CDD_PWM_AQ_OUTPUT_ON_T2_COUNT_UP         - T2 event on count up
 *       - CDD_PWM_AQ_OUTPUT_ON_T2_COUNT_DOWN       - T2 event on count down
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] EpwmOutput     The ePWM pin type.
 * \param[in] Output         The Action Qualifier output.
 * \param[in] Event          The event that causes a change in output.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) EpwmOutput,
                                     VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                     VAR(Cdd_Pwm_ActionQualifierOutputEventType, AUTOMATIC) Event);

/** \brief Sets up Action qualifier outputs
*

* This function sets up the Action Qualifier output on ePWMA or ePWMB, depending on the value of EpwmOutput, to a
* value specified by action.
* Valid action param values from different time base counter scenarios should be OR'd together to configure complete
* action for a pwm output.
* The following are valid values for the parameters.
*   - CDD_pwmOutput
*       - CDD_PWM_AQ_OUTPUT_A          - CDD_PWMxA output
*       - CDD_PWM_AQ_OUTPUT_B          - CDD_PWMxB output
*
*   - action
*       - When time base counter equals zero
*         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_ZERO   - Time base counter equals zero
*                                             and no change in output pins
*         - CDD_PWM_AQ_OUTPUT_LOW_ZERO         - Time base counter equals zero
*                                             and set output pins to low
*         - CDD_PWM_AQ_OUTPUT_HIGH_ZERO        - Time base counter equals zero
*                                             and set output pins to high
*         - CDD_PWM_AQ_OUTPUT_TOGGLE_ZERO      - Time base counter equals zero
*                                             and toggle the output pins
*       - When time base counter equals period
*         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_PERIOD - Time base counter equals period
*                                             and no change in output pins
*         - CDD_PWM_AQ_OUTPUT_LOW_PERIOD       - Time base counter equals period
*                                             and set output pins to low
*         - CDD_PWM_AQ_OUTPUT_HIGH_PERIOD      - Time base counter equals period
*                                             and set output pins to high
*         - CDD_PWM_AQ_OUTPUT_TOGGLE_PERIOD    - Time base counter equals period
*                                             and toggle the output pins
*       - When time base counter equals CMPA during up-count
*         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_UP_CMPA  - Time base counter up equals
*                                               COMPA and no change in the
*                                               output pins
*         - CDD_PWM_AQ_OUTPUT_LOW_UP_CMPA        - Time base counter up equals
*                                               COMPA and set output pins low
*         - CDD_PWM_AQ_OUTPUT_HIGH_UP_CMPA       - Time base counter up equals
*                                               COMPA and set output pins high
*         - CDD_PWM_AQ_OUTPUT_TOGGLE_UP_CMPA     - Time base counter up equals
*                                               COMPA and toggle output pins
*       - When time base counter equals CMPA during down-count
*         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPA - Time base counter down equals
*                                                COMPA and no change in the
*                                                output pins
*         - CDD_PWM_AQ_OUTPUT_LOW_DOWN_CMPA      - Time base counter down equals
*                                               COMPA and set output pins low
*         - CDD_PWM_AQ_OUTPUT_HIGH_DOWN_CMPA     - Time base counter down equals
*                                               COMPA and set output pins high
*         - CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_CMPA   - Time base counter down equals
*                                               COMPA and toggle output pins
*       - When time base counter equals CMPB during up-count
*         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_UP_CMPB  - Time base counter up equals
*                                               COMPB and no change in the
*                                               output pins
*         - CDD_PWM_AQ_OUTPUT_LOW_UP_CMPB        - Time base counter up equals
*                                               COMPB and set output pins low
*         - CDD_PWM_AQ_OUTPUT_HIGH_UP_CMPB       - Time base counter up equals
*                                               COMPB and set output pins high
*         - CDD_PWM_AQ_OUTPUT_TOGGLE_UP_CMPB     - Time base counter up equals
*                                               COMPB and toggle output pins
*       - When time base counter equals CMPB during down-count
*         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPB- Time base counter down equals
*                                               COMPB and no change in the
*                                               output pins
*         - CDD_PWM_AQ_OUTPUT_LOW_DOWN_CMPB      - Time base counter down equals
*                                               COMPB and set output pins low
*         - CDD_PWM_AQ_OUTPUT_HIGH_DOWN_CMPB     - Time base counter down equals
*                                               COMPB and set output pins high
*         - CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_CMPB   - Time base counter down equals
*                                               COMPB and toggle output pins
*
* \param[in] InstanceId     Numeric ID of the requested PWM instance.
* \param[in] OutputChannel  EPWM output channel (OUTPUT A or OUTPUT B).
* \param[in] Action          AQ action
* \pre None
* \post None
* \return None
* \retval None
*
*********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(uint16, AUTOMATIC) Action);

/** \brief Sets up Additional action qualifier event outputs
 *
 * This function sets up the Additional Action Qualifier output on ePWMA or
 * ePWMB depending on the value of OutputChannel, to a value specified by Action.
 * Valid Action param values from different event scenarios should be OR'd
 * together to configure complete action for a pwm output.
 * The following are valid values for the parameters.
 *   - OutputChannel
 *       - CDD_PWM_AQ_OUTPUT_A          - CDD_PWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - CDD_PWMxB output
 *   - Action
 *       - When T1 event occurs during up-count
 *         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_UP_T1  - T1 event on count up
 *                                             and no change in output pins
 *         - CDD_PWM_AQ_OUTPUT_LOW_UP_T1        - T1 event on count up
 *                                           and set output pins to low
 *         - CDD_PWM_AQ_OUTPUT_HIGH_UP_T1       - T1 event on count up
 *                                           and set output pins to high
 *         - CDD_PWM_AQ_OUTPUT_TOGGLE_UP_T1     - T1 event on count up
 *                                           and toggle the output pins
 *       - When T1 event occurs during down-count
 *         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_DOWN_T1- T1 event on count down
 *                                           and no change in output pins
 *         - CDD_PWM_AQ_OUTPUT_LOW_DOWN_T1      - T1 event on count down
 *                                           and set output pins to low
 *         - CDD_PWM_AQ_OUTPUT_HIGH_DOWN_T1     - T1 event on count down
 *                                           and set output pins to high
 *         - CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_T1   - T1 event on count down
 *                                           and toggle the output pins
 *       - When T2 event occurs during up-count
 *         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_UP_T2  - T2 event on count up
 *                                             and no change in output pins
 *         - CDD_PWM_AQ_OUTPUT_LOW_UP_T2        - T2 event on count up
 *                                             and set output pins to low
 *         - CDD_PWM_AQ_OUTPUT_HIGH_UP_T2       - T2 event on count up
 *                                             and set output pins to high
 *         - CDD_PWM_AQ_OUTPUT_TOGGLE_UP_T2     - T2 event on count up
 *                                             and toggle the output pins
 *       - When T2 event occurs during down-count
 *         - CDD_PWM_AQ_OUTPUT_NO_CHANGE_DOWN_T2 - T2 event on count down
 *                                              and no change in output pins
 *         - CDD_PWM_AQ_OUTPUT_LOW_DOWN_T2       - T2 event on count down
 *                                              and set output pins to low
 *         - CDD_PWM_AQ_OUTPUT_HIGH_DOWN_T2      - T2 event on count down
 *                                              and set output pins to high
 *         - CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_T2    - T2 event on count down
 *                                              and toggle the output pins
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] OutputChannel  EPWM output channel (OUTPUT A or OUTPUT B).
 * \param[in] Action         The desired action when the specified event occurs.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 * \note A logical OR of the valid values should be passed as the Action
 *       parameter. Single action should be configured for each event
 *       scenario.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetAdditionalActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                       VAR(uint16, AUTOMATIC) Action);

/** \brief Sets up Action qualifier continuous software load mode
 *
 * This function sets up the AQCFRSC register load mode for continuous
 * software force reload mode. The software force actions are determined by
 * the Cdd_Pwm_SetActionQualifierContSwForceAction() function.
 * Valid values for Mode are:
 *   - CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO        - shadow mode load when counter
 *                                               equals zero
 *   - CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_PERIOD      - shadow mode load when counter
 *                                               equals period
 *   - CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO_PERIOD - shadow mode load when counter
 *                                               equals zero or period
 *   - CDD_PWM_AQ_SW_IMMEDIATE_LOAD               - immediate mode load only
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Mode           Mode for shadow to active load mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierContSwForceShadowMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_ActionQualifierContForceType, AUTOMATIC) Mode);

/** \brief Triggers a continuous software forced event
 *
 * This function triggers a continuous software forced Action Qualifier output
 * on ePWM A or B based on the value of OutputChannel.
 * Valid values for the parameters are:
 *   - OutputChannel
 *       - CDD_PWM_AQ_OUTPUT_A          - CDD_PWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - CDD_PWMxB output
 *   - Output
 *       - CDD_PWM_AQ_SW_DISABLED       - Software forcing disabled.
 *       - CDD_PWM_AQ_SW_OUTPUT_LOW     - Set output pins to low
 *       - CDD_PWM_AQ_SW_OUTPUT_HIGH    - Set output pins to High
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] OutputChannel  EPWM output channel (OUTPUT A or OUTPUT B).
 * \param[in] Output         The Action Qualifier output.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierContSwForceAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                VAR(Cdd_Pwm_ActionQualifierSwOutputType, AUTOMATIC) Output);

/** \brief Sets up one time software forced Action qualifier outputs
 *
 * This function sets up the one time software forced Action Qualifier output
 * on ePWM A or ePWMB, depending on the value of OutputChannel to a value
 * specified by Output.
 * The following are valid values for the parameters.
 *   - OutputChannel
 *       - CDD_PWM_AQ_OUTPUT_A          - CDD_PWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - CDD_PWMxB output
 *   - Output
 *       - CDD_PWM_AQ_OUTPUT_NO_CHANGE  - No change in the output pins
 *       - CDD_PWM_AQ_OUTPUT_LOW        - Set output pins to low
 *       - CDD_PWM_AQ_OUTPUT_HIGH       - Set output pins to High
 *       - CDD_PWM_AQ_OUTPUT_TOGGLE     - Toggle the output pins
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] OutputChannel  EPWM output channel (OUTPUT A or OUTPUT B).
 * \param[in] Output         The Action Qualifier output.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                       VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output);

/** \brief Triggers a one time software forced event on Action qualifier
 *
 * This function triggers a one time software forced Action Qualifier event
 * on ePWM A or B based on the value of OutputChannel.
 * Valid values for OutputChannel are:
 *   - CDD_PWM_AQ_OUTPUT_A          - CDD_PWMxA output
 *   - CDD_PWM_AQ_OUTPUT_B          - CDD_PWMxB output
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] OutputChannel  EPWM output channel (OUTPUT A or OUTPUT B).
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivForceActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/*
 * Dead Band Module related APIs
 */

/** \brief Sets Dead Band signal output swap mode
 *
 * This function sets up the output signal swap mode. For example if the
 * output variable is set to CDD_PWM_DB_OUTPUT_A and enableSwapMode is true, then
 * the ePWM A output gets its signal from the ePWM B signal path.
 *
 * \param[in] InstanceId       Numeric ID of the requested PWM instance.
 * \param[in] OutputChannel    The ePWM Dead Band output.
 * \param[in] EnableSwapMode   The output swap mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                      VAR(boolean, AUTOMATIC) EnableSwapMode);

/** \brief Sets Dead Band signal output mode
 *
 * This function sets up the dead band delay mode. The delayMode variable
 * determines if the applied delay is Rising Edge or Falling Edge. The
 * enableDelayMode determines if a dead band delay should be applied.
 * Valid values for the variables are:
 *  - delayMode
 *      - CDD_PWM_DB_RED   - Rising Edge delay
 *      - CDD_PWM_DB_FED   - Falling Edge delay
 *  - enableDelayMode
 *      - true     - Falling edge or Rising edge delay is applied.
 *      - false    - Dead Band delay is bypassed.
 *
 * \param[in] InstanceId       Numeric ID of the requested PWM instance.
 * \param[in] DelayMode        The Dead Band delay type.
 * \param[in] EnableDelayMode  The dead band delay mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandDelayMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                                 VAR(boolean, AUTOMATIC) EnableDelayMode);

/** \brief Sets Dead Band delay polarity
 *
 * This function sets up the polarity as determined by the variable polarity
 * of the Falling Edge or Rising Edge delay depending on the value of
 * delayMode. Valid values for the variables are:
 *   - delayMode
 *       - CDD_PWM_DB_RED   - Rising Edge delay
 *       - CDD_PWM_DB_FED   - Falling Edge delay
 *   - polarity
 *       - CDD_PWM_DB_POLARITY_ACTIVE_HIGH   - polarity is not inverted.
 *       - CDD_PWM_DB_POLARITY_ACTIVE_LOW    - polarity is inverted.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] DelayMode      The Dead Band delay type.
 * \param[in] Polarity       The polarity of the delayed signal.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandDelayPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                                     VAR(Cdd_Pwm_DeadBandPolarityType, AUTOMATIC) Polarity);

/** \brief Sets Rising Edge Dead Band delay input
 *
 * This function sets up the rising Edge delay input signal.
 * Valid values for input are:
 *     - CDD_PWM_DB_INPUT_EPWMA   - Input signal is ePWMA( Valid for both Falling
 *                                  Edge and Rising Edge)
 *     - CDD_PWM_DB_INPUT_EPWMB   - Input signal is ePWMB( Valid for both Falling
 *                                  Edge and Rising Edge)
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] OutputChannel  The input signal to the dead band.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetRisingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/** \brief Sets Dead Band delay input
 *
 * This function sets up the rising Edge delay input signal.
 * Valid values for input are:
 *   - CDD_PWM_DB_INPUT_EPWMA   - Input signal is ePWMA(Valid for both Falling
 *                                Edge and Rising Edge)
 *   - CDD_PWM_DB_INPUT_EPWMB   - Input signal is ePWMB(Valid for both Falling
 *                                Edge and Rising Edge)
 *   - CDD_PWM_DB_INPUT_DB_RED  - Input signal is the output of Rising
 *                                Edge delay.
 *                               (Valid only for Falling Edge delay)
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Input          The input signal to the dead band.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetFallingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DeadBandDelayInputType, AUTOMATIC) Input);

/** \brief Set the Dead Band control shadow load mode
 *
 * This function enables and sets the Dead Band control register shadow
 * load mode.
 * Valid values for the \e loadMode parameter are:
 *     - CDD_PWM_DB_LOAD_ON_CNTR_ZERO         - load when counter equals zero.
 *     - CDD_PWM_DB_LOAD_ON_CNTR_PERIOD       - load when counter equals period.
 *     - CDD_PWM_DB_LOAD_ON_CNTR_ZERO_PERIOD  - load when counter equals zero or
 *                                            period.
 *     - CDD_PWM_DB_LOAD_FREEZE                - Freeze shadow to active load.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] LoadMode       The shadow to active load mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DeadBandControlLoadModeType, AUTOMATIC) LoadMode);

/** \brief Disable Dead Band control shadow load mode
 *
 * This function disables the Dead Band control register shadow
 * load mode.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set the RED (Rising Edge Delay) shadow load mode
 *
 * This function sets the Rising Edge Delay register shadow load mode.
 * Valid values for the \e loadMode parameter are:
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO        - load when counter equals zero.
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_PERIOD      - load when counter equals period.
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero or
 *                                           period.
 *     - CDD_PWM_DELAY_LOAD_FREEZE               - Freeze shadow to active load.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] LoadMode       The shadow to active load event.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(Cdd_Pwm_DeadBandDelayLoadModeType, AUTOMATIC) LoadMode);

/** \brief Disable the RED (Rising Edge Delay) shadow load mode.
 *
 * This function disables the Rising Edge Delay register shadow load mode.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Disable the RED (Rising Edge Delay) shadow load mode
 *
 * This function disables the Rising Edge Delay register shadow load mode.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set the FED (Falling Edge Delay) shadow load mode
 *
 * This function enables and sets the Falling Edge Delay register shadow load
 * mode. Valid values for the \e loadMode parameters are:
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO        - load when counter equals zero.
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_PERIOD      - load when counter equals period.
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero or
 *                                            period.
 *     - CDD_PWM_DELAY_LOAD_FREEZE               - Freeze shadow to active load.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] LoadMode       The shadow to active load event.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_DeadBandDelayLoadModeType, AUTOMATIC) LoadMode);

/** \brief Disables the FED (Falling Edge Delay) shadow load mode
 *
 * This function disables the Falling Edge Delay register shadow load mode.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Sets Dead Band Counter clock rate
 *
 * This function sets up the Dead Band counter clock rate with respect to
 * TBCLK (ePWM time base counter).
 * Valid values for clockMode are:
 *   - CDD_PWM_DB_COUNTER_CLOCK_FULL_CYCLE  -Dead band counter runs at TBCLK
 *                                           (ePWM Time Base Counter) rate.
 *   - CDD_PWM_DB_COUNTER_CLOCK_HALF_CYCLE  -Dead band counter runs at 2*TBCLK
 *                                         (twice ePWM Time Base Counter)rate.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] ClockMode      The Dead Band counter clock mode.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandCounterClock(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_DeadBandClockModeType, AUTOMATIC) ClockMode);

/** \brief Set ePWM RED count
 *
 * This function sets the RED (Rising Edge Delay) count value.
 * The value of redCount should be less than 0x4000U.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] RedCount       The RED(Rising Edge Delay) count.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetRisingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) RedCount);

/** \brief Set ePWM FED count
 *
 * This function sets the FED (Falling Edge Delay) count value.
 * The value of fedCount should be less than 0x4000U.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] FedCount       The FED(Falling Edge Delay) count.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetFallingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) FedCount);

/*
 * Chopper module related APIs
 */

/** \brief Enable chopper mode
 *
 * This function enables ePWM chopper module.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Select         Enable/disable selection for chopper.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureChopper(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set chopper duty cycle
 *
 * This function sets the chopping clock duty cycle. The value of
 * dutyCycleCount should be less than 7. The dutyCycleCount value is converted
 * to the actual chopper duty cycle value base on the following equation:
 *   chopper duty cycle = (dutyCycleCount + 1) / 8
 *
 * \param[in] InstanceId       Numeric ID of the requested PWM instance.
 * \param[in] DutyCycleCount   The chopping clock duty cycle count.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetChopperDutyCycle(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) DutyCycleCount);

/** \brief Set chopper clock frequency scaler
 *
 * This function sets the scaler for the chopping clock frequency. The value
 * of freqDiv should be less than 8. The chopping clock frequency is altered
 * based on the following equation.
 *   chopper clock frequency = SYSCLKOUT / ( 1 + freqDiv)
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] FreqDiv        The chopping clock frequency divider.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetChopperFreq(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) FreqDiv);

/** \brief Set chopper first pulse width
 *
 * This function sets the first pulse width of chopper output waveform. The
 * value of firstPulseWidth should be less than 0x10U. The value of the first
 * pulse width in seconds is given using the following equation:
 *     first pulse width = 1 / (((firstPulseWidth + 1)* SYSCLKOUT)/8)
 *
 * \param[in] InstanceId        Numeric ID of the requested PWM instance.
 * \param[in] FirstPulseWidth   The width of the first pulse.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetChopperFirstPulseWidth(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(uint16, AUTOMATIC) FirstPulseWidth);

/*
 * Trip Zone module related APIs
 */

/** \brief Enables Trip Zone signal
 *
 * This function enables the Trip Zone signals specified by tzSignal as a
 * source for the Trip Zone module.
 * Valid values for tzSignal are:
 *   - CDD_PWM_TZ_SIGNAL_CBC1       - TZ1 Cycle By Cycle
 *   - CDD_PWM_TZ_SIGNAL_CBC2       - TZ2 Cycle By Cycle
 *   - CDD_PWM_TZ_SIGNAL_CBC3U       - TZ3U Cycle By Cycle
 *   - CDD_PWM_TZ_SIGNAL_CBC4       - TZ4 Cycle By Cycle
 *   - CDD_PWM_TZ_SIGNAL_CBC5       - TZ5 Cycle By Cycle
 *   - CDD_PWM_TZ_SIGNAL_CBC6       - TZ6 Cycle By Cycle
 *   - CDD_PWM_TZ_SIGNAL_DCAEVT2    - DCAEVT2 Cycle By Cycle
 *   - CDD_PWM_TZ_SIGNAL_DCBEVT2    - DCBEVT2 Cycle By Cycle
 *   - CDD_PWM_TZ_SIGNAL_OSHT1      - One-shot TZ1
 *   - CDD_PWM_TZ_SIGNAL_OSHT2      - One-shot TZ2
 *   - CDD_PWM_TZ_SIGNAL_OSHT3U      - One-shot TZ3U
 *   - CDD_PWM_TZ_SIGNAL_OSHT4      - One-shot TZ4
 *   - CDD_PWM_TZ_SIGNAL_OSHT5      - One-shot TZ5
 *   - CDD_PWM_TZ_SIGNAL_OSHT6      - One-shot TZ6
 *   - CDD_PWM_TZ_SIGNAL_DCAEVT1    - One-shot DCAEVT1
 *   - CDD_PWM_TZ_SIGNAL_DCBEVT1    - One-shot DCBEVT1
 *
 * \note A logical OR of the valid values can be passed as the tzSignal parameter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] TzSignal       The Trip Zone signal.
 * \param[in] Select         Enable/disable selection for the signal.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripZoneSignals(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzSignal,
                                     VAR(boolean, AUTOMATIC) Select);

/** \brief Enables Trip Zone 2 signal (TZSEL2)
 *
 * This function enables the Trip Zone signals specified by tzSignal as a source for the Trip Zone module.
 * Valid values for tzSignal are:
 *   - CDD_PWM_TZ_SIGNAL_CAPEVT_CBC       - One-shot CAPEVT
 *   - CDD_PWM_TZ_SIGNAL_CAPEVT_OST       - Cycle By Cycle CAPEVT
 *
 * \note A logical OR of the valid values can be passed as the tzSignal parameter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] TzSignal       The Trip Zone signal.
 * \param[in] Select         Enable/disable selection for the signal.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripZone2Signals(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzSignal,
                                      VAR(boolean, AUTOMATIC) Select);

/** \brief Set Digital compare conditions that cause Trip Zone event
 *
 * This function sets up the Digital Compare output Trip Zone event sources.
 * The dcType variable specifies the event source to be whether Digital
 * Compare output A or Digital Compare output B. The dcEvent parameter
 * specifies the event that causes Trip Zone.
 * Valid values for the parameters are:
 *  - dcType
 *      - CDD_PWM_TZ_DC_OUTPUT_A1     - Digital Compare output 1 A
 *      - CDD_PWM_TZ_DC_OUTPUT_A2     - Digital Compare output 2 A
 *      - CDD_PWM_TZ_DC_OUTPUT_B1     - Digital Compare output 1 B
 *      - CDD_PWM_TZ_DC_OUTPUT_B2     - Digital Compare output 2 B
 *  - dcEvent
 *      - CDD_PWM_TZ_EVENT_DC_DISABLED         - Event Trigger is disabled
 *      - CDD_PWM_TZ_EVENT_DCXH_LOW            - Trigger event when DCxH low
 *      - CDD_PWM_TZ_EVENT_DCXH_HIGH           - Trigger event when DCxH high
 *      - CDD_PWM_TZ_EVENT_DCXL_LOW            - Trigger event when DCxL low
 *      - CDD_PWM_TZ_EVENT_DCXL_HIGH           - Trigger event when DCxL high
 *      - CDD_PWM_TZ_EVENT_DCXL_HIGH_DCXH_LOW  - Trigger event when DCxL high
 *                                            DCxH low
 *
 * \note x in DCxH/DCxL represents DCAH/DCAL or DCBH/DCBL
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] DcType         Digital compare output type.
 * \param[in] DcEvent        Digital Compare output event.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTripZoneDigitalCompareEventCondition(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType, AUTOMATIC) DcType,
                                                    VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType, AUTOMATIC)
                                                        DcEvent);

/** \brief Enable advanced Trip Zone event Action
 *
 * This function enables the advanced actions of the Trip Zone events. The
 * advanced features combine the trip zone events with the direction of the
 * counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] Select         Enable/disable selection for advanced trip zone action.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set Trip Zone Action
 *
 * This function sets the Trip Zone Action to be taken when a Trip Zone event
 * occurs.
 * Valid values for the parameters are:
 *  - tzEvent
 *      - CDD_PWM_TZ_ACTION_EVENT_DCBEVT2  - DCBEVT2 (Digital Compare B event 2)
 *      - CDD_PWM_TZ_ACTION_EVENT_DCBEVT1  - DCBEVT1 (Digital Compare B event 1)
 *      - CDD_PWM_TZ_ACTION_EVENT_DCAEVT2  - DCAEVT2 (Digital Compare A event 2)
 *      - CDD_PWM_TZ_ACTION_EVENT_DCAEVT1  - DCAEVT1 (Digital Compare A event 1)
 *      - CDD_PWM_TZ_ACTION_EVENT_TZB      - TZ1 - TZ6U, DCBEVT2U, DCBEVT1
 *      - CDD_PWM_TZ_ACTION_EVENT_TZA      - TZ1 - TZ6U, DCAEVT2U, DCAEVT1
 *  - tzAction
 *      - CDD_PWM_TZ_ACTION_HIGH_Z         - high impedance output
 *      - CDD_PWM_TZ_ACTION_HIGH           - high output
 *      - CDD_PWM_TZ_ACTION_LOW            - low low
 *      - CDD_PWM_TZ_ACTION_DISABLE        - disable action
 *
 * \note Disable the advanced Trip Zone event using
 *       Cdd_Pwm_DisableTripZoneAdvAction() before calling this function.
 * \note This function operates on both ePWMA and ePWMB depending on the
 *       tzEvent parameter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] TzEvent        The Trip Zone event type.
 * \param[in] TzAction       The Trip zone Action.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTripZoneAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_TripZoneActionEventType, AUTOMATIC) TzEvent,
                              VAR(Cdd_Pwm_TripZoneActionType, AUTOMATIC) TzAction);

/** \brief Set Advanced Trip Zone Action
 *
 * This function sets the Advanced Trip Zone Action to be taken when an
 * advanced Trip Zone event occurs.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TzAdvEvent    Trip Zone event type with valid values:
 *                          - CDD_PWM_TZ_ADV_ACTION_EVENT_TZB_D  - TZ1 - TZ6U, DCBEVT2U, DCBEVT1 while counting down
 *                          - CDD_PWM_TZ_ADV_ACTION_EVENT_TZB_U  - TZ1 - TZ6U, DCBEVT2U, DCBEVT1 while counting up
 *                          - CDD_PWM_TZ_ADV_ACTION_EVENT_TZA_D  - TZ1 - TZ6U, DCAEVT2U, DCAEVT1 while counting down
 *                          - CDD_PWM_TZ_ADV_ACTION_EVENT_TZA_U  - TZ1 - TZ6U, DCAEVT2U, DCAEVT1 while counting up
 * \param[in] TzAdvAction   Trip zone Action with valid values:
 *                          - CDD_PWM_TZ_ADV_ACTION_HIGH_Z    - high impedance output
 *                          - CDD_PWM_TZ_ADV_ACTION_HIGH      - high voltage state
 *                          - CDD_PWM_TZ_ADV_ACTION_LOW       - low voltage state
 *                          - CDD_PWM_TZ_ADV_ACTION_TOGGLE    - Toggle output
 *                          - CDD_PWM_TZ_ADV_ACTION_DISABLE   - disable action
 * \pre None
 * \post None
 * \note This function enables the advanced Trip Zone event.
 * \note This function operates on both ePWMA and ePWMB depending on the TzAdvEvent parameter.
 * \note Advanced Trip Zone events take into consideration the direction of the counter in addition to Trip Zone events.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_TripZoneAdvancedEventType, AUTOMATIC) TzAdvEvent,
                                 VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvAction);

/** \brief Set Advanced Digital Compare Trip Zone Action on ePWMA
*
* This function sets the Digital Compare (DC) Advanced Trip Zone Action to be
* taken on ePWMA when an advanced Digital Compare Trip Zone A event occurs.
*
* \param[in] InstanceId    Numeric ID of the requested PWM instance
* \param[in] OutputChannel  The ePWM output channel
* \param[in] TzAdvDCEvent   Digital Compare Trip Zone event type with valid values:
*                           - CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT2_D  - Digital Compare event A2 while counting down
*                           - CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT2_U  - Digital Compare event A2 while counting up
*                           - CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT1_D  - Digital Compare event A1 while counting down
*                           - CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT1_U  - Digital Compare event A1 while counting up
* \param[in] TzAdvDCAction  Digital Compare Trip zone Action with valid values:
*                           - CDD_PWM_TZ_ADV_ACTION_HIGH_Z    - high impedance output
*                           - CDD_PWM_TZ_ADV_ACTION_HIGH      - high voltage state
*                           - CDD_PWM_TZ_ADV_ACTION_LOW       - low voltage state
*                           - CDD_PWM_TZ_ADV_ACTION_TOGGLE    - Toggle output
*                           - CDD_PWM_TZ_ADV_ACTION_DISABLE   - disable action
* \pre None
* \post None
* \note This function enables the advanced Trip Zone event.
* \note Advanced Trip Zone events take into consideration the direction of the counter in addition
        to Digital Compare Trip Zone events.
* \return None
*
*********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTripZoneAdvDigitalCompareAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                               VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType, AUTOMATIC) TzAdvDCEvent,
                                               VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvDCAction);

/** \brief Enable Trip Zone interrupts
 *
 * This function enables the Trip Zone interrupts.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TzInterrupt   Trip Zone interrupt with valid values:
 *                          - CDD_PWM_TZ_INTERRUPT_CBC     - Trip Zones Cycle By Cycle interrupt
 *                          - CDD_PWM_TZ_INTERRUPT_OST     - Trip Zones One Shot interrupt
 *                          - CDD_PWM_TZ_INTERRUPT_DCAEVT1 - Digital Compare A Event 1 interrupt
 *                          - CDD_PWM_TZ_INTERRUPT_DCAEVT2 - Digital Compare A Event 2 interrupt
 *                          - CDD_PWM_TZ_INTERRUPT_DCBEVT1 - Digital Compare B Event 1 interrupt
 *                          - CDD_PWM_TZ_INTERRUPT_DCBEVT2 - Digital Compare B Event 2 interrupt
 *                          - CDD_PWM_TZ_INTERRUPT_CAPEVT  - Trip Zones Capture Event interrupt
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \note A logical OR of the valid values can be passed as the TzInterrupt parameter.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripZoneInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(uint16, AUTOMATIC) TzInterrupt, VAR(boolean, AUTOMATIC) Select);

/** \brief Gets the Trip Zone status flag
 *
 * This function returns the Trip Zone status flag.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The function returns the following or the bitwise OR value of the following values:
 *         - CDD_PWM_TZ_INTERRUPT    - Trip Zone interrupt was generated due to the following TZ events
 *         - CDD_PWM_TZ_FLAG_CBC     - Trip Zones Cycle By Cycle event status flag
 *         - CDD_PWM_TZ_FLAG_OST     - Trip Zones One Shot event status flag
 *         - CDD_PWM_TZ_FLAG_DCAEVT1 - Digital Compare A Event 1 status flag
 *         - CDD_PWM_TZ_FLAG_DCAEVT2 - Digital Compare A Event 2 status flag
 *         - CDD_PWM_TZ_FLAG_DCBEVT1 - Digital Compare B Event 1 status flag
 *         - CDD_PWM_TZ_FLAG_DCBEVT2 - Digital Compare B Event 2 status flag
 *         - CDD_PWM_TZ_FLAG_CAPEVT  - Trip Zones Capture Event flag
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Gets the Trip Zone Cycle by Cycle flag status
 *
 * This function returns the specific Cycle by Cycle Trip Zone flag status.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The function returns the following values:
 *         - CDD_PWM_TZ_CBC_FLAG_1       - CBC 1 status flag
 *         - CDD_PWM_TZ_CBC_FLAG_2       - CBC 2 status flag
 *         - CDD_PWM_TZ_CBC_FLAG_3U      - CBC 3U status flag
 *         - CDD_PWM_TZ_CBC_FLAG_4       - CBC 4 status flag
 *         - CDD_PWM_TZ_CBC_FLAG_5       - CBC 5 status flag
 *         - CDD_PWM_TZ_CBC_FLAG_6       - CBC 6 status flag
 *         - CDD_PWM_TZ_CBC_FLAG_DCAEVT2 - CBC status flag for Digital compare event A2
 *         - CDD_PWM_TZ_CBC_FLAG_DCBEVT2 - CBC status flag for Digital compare event B2
 *         - CDD_PWM_TZ_CBC_FLAG_CAPEVT  - CBC status flag for capture event
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetCycleByCycleTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Gets the Trip Zone One Shot flag status
 *
 * This function returns the specific One Shot Trip Zone flag status.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The function returns the bitwise OR of the following flags:
 *         - CDD_PWM_TZ_OST_FLAG_OST1     - OST status flag for OST1
 *         - CDD_PWM_TZ_OST_FLAG_OST2     - OST status flag for OST2
 *         - CDD_PWM_TZ_OST_FLAG_OST3U    - OST status flag for OST3U
 *         - CDD_PWM_TZ_OST_FLAG_OST4     - OST status flag for OST4
 *         - CDD_PWM_TZ_OST_FLAG_OST5     - OST status flag for OST5
 *         - CDD_PWM_TZ_OST_FLAG_OST6     - OST status flag for OST6
 *         - CDD_PWM_TZ_OST_FLAG_DCAEVT1  - OST status flag for Digital compare event A1
 *         - CDD_PWM_TZ_OST_FLAG_DCBEVT1  - OST status flag for Digital compare event B1
 *         - CDD_PWM_TZ_OST_FLAG_CAPEVT   - OST status flag for capture event
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetOneShotTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set the Trip Zone CBC pulse clear event
*
* This function set the event which automatically clears the CBC (Cycle by Cycle) latch.
*
* \param[in] InstanceId    Numeric ID of the requested PWM instance
* \param[in] ClearEvent    CBC trip zone clear event with valid values:
*                          - CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_ZERO         - Clear CBC pulse when counter equals zero
*                          - CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_PERIOD       - Clear CBC pulse when counter equals period
*                          - CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_ZERO_PERIOD  -
                                                                    Clear CBC pulse when counter equals zero or period
* \pre None
* \post None
* \return None
*
*********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectCycleByCycleTripZoneClearEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_CbcTripZoneClearModeType, AUTOMATIC) ClearEvent);

/** \brief Clear Trip Zone flag
 *
 * This function clears the Trip Zone flags.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TzFlags       Trip Zone flags with valid values:
 *                          - CDD_PWM_TZ_INTERRUPT    - Global Trip Zone interrupt flag
 *                          - CDD_PWM_TZ_FLAG_CBC     - Trip Zones Cycle By Cycle flag
 *                          - CDD_PWM_TZ_FLAG_OST     - Trip Zones One Shot flag
 *                          - CDD_PWM_TZ_FLAG_DCAEVT1 - Digital Compare A Event 1 flag
 *                          - CDD_PWM_TZ_FLAG_DCAEVT2 - Digital Compare A Event 2 flag
 *                          - CDD_PWM_TZ_FLAG_DCBEVT1 - Digital Compare B Event 1 flag
 *                          - CDD_PWM_TZ_FLAG_DCBEVT2 - Digital Compare B Event 2 flag
 *                          - CDD_PWM_TZ_FLAG_CAPEVT  - Trip Zones Capture Event flag
 * \pre None
 * \post None
 * \note A bitwise OR of the valid values can be passed as the TzFlags parameter.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzFlags);

/** \brief Clear the Trip Zone Cycle by Cycle flag
 *
 * This function clears the specific Cycle by Cycle Trip Zone flag.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TzCbcFlags    CBC flag to be cleared with valid values:
 *                          - CDD_PWM_TZ_CBC_FLAG_1       - CBC 1 flag
 *                          - CDD_PWM_TZ_CBC_FLAG_2       - CBC 2 flag
 *                          - CDD_PWM_TZ_CBC_FLAG_3U      - CBC 3U flag
 *                          - CDD_PWM_TZ_CBC_FLAG_4       - CBC 4 flag
 *                          - CDD_PWM_TZ_CBC_FLAG_5       - CBC 5 flag
 *                          - CDD_PWM_TZ_CBC_FLAG_6       - CBC 6 flag
 *                          - CDD_PWM_TZ_CBC_FLAG_DCAEVT2 - CBC flag Digital compare event A2
 *                          - CDD_PWM_TZ_CBC_FLAG_DCBEVT2 - CBC flag Digital compare event B2
 *                          - CDD_PWM_TZ_CBC_FLAG_CAPEVT  - CBC flag capture event
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearCycleByCycleTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) TzCbcFlags);

/** \brief Clear the Trip Zone One Shot flag
 *
 * This function clears the specific One Shot (OST) Trip Zone flag.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TzOSTFlags    OST flags to be cleared with valid values:
 *                          - CDD_PWM_TZ_OST_FLAG_OST1     - OST flag for OST1
 *                          - CDD_PWM_TZ_OST_FLAG_OST2     - OST flag for OST2
 *                          - CDD_PWM_TZ_OST_FLAG_OST3U    - OST flag for OST3U
 *                          - CDD_PWM_TZ_OST_FLAG_OST4     - OST flag for OST4
 *                          - CDD_PWM_TZ_OST_FLAG_OST5     - OST flag for OST5
 *                          - CDD_PWM_TZ_OST_FLAG_OST6     - OST flag for OST6
 *                          - CDD_PWM_TZ_OST_FLAG_DCAEVT1  - OST flag for Digital compare event A1
 *                          - CDD_PWM_TZ_OST_FLAG_DCBEVT1  - OST flag for Digital compare event B1
 *                          - CDD_PWM_TZ_OST_FLAG_CAPEVT   - OST flag capture event
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearOneShotTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(uint16, AUTOMATIC) TzOSTFlags);

/** \brief Force Trip Zone events
 *
 * This function forces a Trip Zone event.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TzForceEvent   Forced Trip Zone event with valid values:
 *                           - CDD_PWM_TZ_FORCE_EVENT_CBC     - Force Trip Zones Cycle By Cycle event
 *                           - CDD_PWM_TZ_FORCE_EVENT_OST     - Force Trip Zones One Shot Event
 *                           - CDD_PWM_TZ_FORCE_EVENT_DCAEVT1 - Force Digital Compare A Event 1
 *                           - CDD_PWM_TZ_FORCE_EVENT_DCAEVT2 - Force Digital Compare A Event 2
 *                           - CDD_PWM_TZ_FORCE_EVENT_DCBEVT1 - Force Digital Compare B Event 1
 *                           - CDD_PWM_TZ_FORCE_EVENT_DCBEVT2 - Force Digital Compare B Event 2
 *                           - CDD_PWM_TZ_FORCE_EVENT_CAPEVT  - Force Capture Event
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivForceTripZoneEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzForceEvent);

/** \brief Select TRIPOUT signals for the ePWM module
 *
 * This function selects the TRIPOUT signals for the ePWM module.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TzTripOut     Trip zone event to be selected with valid values:
 *                          - CDD_PWM_TZ_TRIPOUT_CBC     - CBC as TRIPOUT source
 *                          - CDD_PWM_TZ_TRIPOUT_OST     - OST as TRIPOUT source
 *                          - CDD_PWM_TZ_TRIPOUT_TZ[1-6] - TZx as TRIPOUT source
 *                          - CDD_PWM_TZ_TRIPOUT_DCAEVT1 - DCAEVT1 as TRIPOUT source
 *                          - CDD_PWM_TZ_TRIPOUT_DCAEVT2 - DCAEVT2 as TRIPOUT source
 *                          - CDD_PWM_TZ_TRIPOUT_DCBEVT1 - DCBEVT1 as TRIPOUT source
 *                          - CDD_PWM_TZ_TRIPOUT_DCBEVT2 - DCBEVT2 as TRIPOUT source
 *                          - CDD_PWM_TZ_TRIPOUT_CAPEVT  - Capture Event as TRIPOUT source
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripOutSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_SelectTripOutSourceType, AUTOMATIC) TzTripOut,
                                   VAR(boolean, AUTOMATIC) Select);

/*
 * Event Trigger related APIs
 */

/** \brief Return the interrupt status
 *
 * This function returns the ePWM interrupt status.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \note This function doesn't return the Trip Zone status.
 * \return Returns true if ePWM interrupt was generated, false if no interrupt was generated
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_PrivGetEventTriggerInterruptStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable Pre-interrupt count load
 *
 * This function enables the ePWM interrupt counter to be pre-interrupt loaded with a count value.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \note This is valid only for advanced/expanded interrupt mode
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(boolean, AUTOMATIC) Select);

/** \brief Force a software pre interrupt event counter load
 *
 * This function forces the ePWM interrupt counter to be loaded with the
 * contents set by Cdd_Pwm_SetPreInterruptEventCount().
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \note Make sure the EPWM_enablePreInterruptEventCountLoad() function is called before invoking this function.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Get the interrupt count
 *
 * This function returns the ePWM interrupt event count.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The interrupt event counts that have occurred
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetInterruptEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Force ePWM interrupt
 *
 * This function forces an ePWM interrupt.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceEventTriggerInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Sets the mixed event trigger interrupt source
 *
 * This function sets the ePWM interrupt source.
 *
 * \param[in] InstanceId          Numeric ID of the requested PWM instance
 * \param[in] EtMixSignal       The module for which trigger needs to be enabled
 *                              - CDD_PWM_ETMIX_INTERRUPT - Mixed ET Interrupt signal
 *                              - CDD_PWM_ETMIX_SOCA - Mixed ET SOCA signal
 *                              - CDD_PWM_ETMIX_SOCB - Mixed ET SOCB signal
 * \param[in] InterruptSource   The Mixed ET interrupt source
 *                              - CDD_PWM_ETMIX_TBCTR_ZERO - Time-base counter equal to zero
 *                              - CDD_PWM_ETMIX_TBCTR_PERIOD - Time-base counter equal to period
 *                              - CDD_PWM_ETMIX_TBCTR_U_CMPx - Where x is AU,BU,C or D
 *                                Time-base counter equal to CMPAU, CMPBU, CMPC or CMPD
 *                                (depending the value of x) when the timer is incrementing
 *                              - CDD_PWM_ETMIX_TBCTR_D_CMPx - Where x is AU,BU,C or D
 *                                Time-base counter equal to CMPAU, CMPBU, CMPC or CMPD
 *                                (depending the value of x) when the timer is decrementing
 *                              - CDD_PWM_ETMIX_DCAEVT1 - DCAEVT1 interrupt signal to trigger
 *                                mixed ET interrupt
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetMixEvtTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_EtMixSignalSelectType, AUTOMATIC) EtMixSignal,
                                   VAR(Cdd_Pwm_EvtMixTriggerSourceType, AUTOMATIC) InterruptSource);

/*
 * Adc SOC configuration related APIs
 */

/** \brief Enable Adc SOC event
 *
 * This function enables the ePWM module to trigger an Adc SOC event.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                VAR(boolean, AUTOMATIC) Select);

/** \brief Sets the ePWM SOC source
 *
 * This function sets the ePWM Adc SOC source.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \param[in] SocSource     The SOC source
 *                          - CDD_PWM_SOC_DCXEVT1 - Event is based on DCxEVT1
 *                          - CDD_PWM_SOC_TBCTR_ZERO - Time-base counter equal to zero
 *                          - CDD_PWM_SOC_TBCTR_PERIOD - Time-base counter equal to period
 *                          - CDD_PWM_SOC_TBCTR_ETSOCAMIX - Time-base counter based on mixed events (ETSOCAMIX)
 *                          - CDD_PWM_SOC_TBCTR_U_CMPx - Where x is AU,BU,C or D
 *                            Time-base counter equal to CMPAU, CMPBU, CMPC or CMPD
 *                            (depending the value of x) when the timer is incrementing
 *                          - CDD_PWM_SOC_TBCTR_D_CMPx - Where x is AU,BU,C or D
 *                            Time-base counter equal to CMPAU, CMPBU, CMPC or CMPD
 *                            (depending the value of x) when the timer is decrementing
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetAdcTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                VAR(Cdd_Pwm_AdcStartOfConversionSourceType, AUTOMATIC) SocSource);

/** \brief Sets the ePWM SOC event counts
 *
 * This function sets the SOC event count that determines the number of
 * events that have to occur before an SOC is issued.
 *
 * \param[in] InstanceId        Numeric ID of the requested PWM instance
 * \param[in] AdcSocType        The Adc SOC type
 *                              - CDD_PWM_SOC_A - SOC A
 *                              - CDD_PWM_SOC_B - SOC B
 * \param[in] PreScaleCount     The event count number
 *                              - [1 - 15] - Generate SOC pulse every preScaleCount up to 15 events
 * \pre None
 * \post None
 * \note A PreScaleCount value of 0 disables the prescale
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetAdcTriggerEventPrescale(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                       VAR(uint16, AUTOMATIC) PreScaleCount);

/** \brief Return the SOC event status
 *
 * This function returns the ePWM SOC status.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \pre None
 * \post None
 * \return Returns true if the selected AdcSocType SOC was generated.
 *         Returns false if the selected AdcSocType SOC was not generated.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetAdcTriggerFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/** \brief Clear SOC flag
 *
 * This function clears the ePWM SOC flag.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearAdcTriggerFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/** \brief Enable Pre-SOC event count load
 *
 * This function enables the ePWM SOC event counter which is set by the
 * Cdd_Pwm_SetAdcTriggerEventCountInitValue() function to be loaded before
 * an SOC event.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \note This is valid only for advanced/expanded SOC mode
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                              VAR(boolean, AUTOMATIC) Select);

/** \brief Force a software pre SOC event counter load
 *
 * This function forces the ePWM SOC counter to be loaded with the
 * contents set by Cdd_Pwm_SetPreAdcStartOfConversionEventCount().
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 * \pre None
 * \post None
 * \note Make sure the EPWM_enableAdcTriggerEventCountInit() function is called before invoking this function.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivForceAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/** \brief Set Adc Trigger count values
 *
 * This function sets the ePWM Adc Trigger count values.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \param[in] EventCount    The ePWM interrupt count value (maximum value is 15)
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetAdcTriggerEventCountInitValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                             VAR(uint16, AUTOMATIC) EventCount);

/** \brief Get the SOC event count
 *
 * This function returns the ePWM SOC event count.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \pre None
 * \post None
 * \return The SOC event counts that have occurred
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetAdcTriggerEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/** \brief Force SOC event
 *
 * This function forces an ePWM SOC event.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivForceAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/*
 * Digital Compare module related APIs
 */

/** \brief Set the DC trip input
 *
 * This function sets the trip input to the Digital Compare (DC). For a given
 * dcType The function sets the tripSource to be the input to the DC.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TripInput     The trip source
 *                          - CDD_PWM_DC_TRIP_TRIPINx - Trip x, where x ranges from 1 to 15 excluding 13U
 *                          - CDD_PWM_DC_TRIP_COMBINATION - selects all the Trip signals whose input
 *                            is enabled by the Cdd_Pwm_EnableDigitalCompareTripCombinationInput() function
 * \param[in] DcType        The Digital Compare type
 *                          - CDD_PWM_DC_TYPE_DCAH - Digital Compare A High
 *                          - CDD_PWM_DC_TYPE_DCAL - Digital Compare A Low
 *                          - CDD_PWM_DC_TYPE_DCBH - Digital Compare B High
 *                          - CDD_PWM_DC_TYPE_DCBL - Digital Compare B Low
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectDigitalCompareTripInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) TripInput,
                                          VAR(Cdd_Pwm_DigitalCompareType, AUTOMATIC) DcType);

/** \brief Enable DC filter blanking window
 *
 * This function enables the DC filter blanking window.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareBlankingWindow(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(boolean, AUTOMATIC) Select);

/** \brief Enable Digital Compare Window inverse mode
 *
 * This function enables the Digital Compare Window inverse mode. This will
 * invert the blanking window.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareWindowInverseMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                     VAR(boolean, AUTOMATIC) Select);

/** \brief Set the Digital Compare filter blanking pulse
 *
 * This function sets the input pulse that starts the Digital Compare blanking
 * window.
 *
 * \param[in] InstanceId          Numeric ID of the requested PWM instance
 * \param[in] BlankingPulse     Pulse that starts blanking window
 *                              - CDD_PWM_DC_WINDOW_START_TBCTR_PERIOD - Time base counter equals period
 *                              - CDD_PWM_DC_WINDOW_START_TBCTR_ZERO - Time base counter equals zero
 *                              - CDD_PWM_DC_WINDOW_START_TBCTR_ZERO_PERIOD - Time base counter equals zero or period
 *                              - CDD_PWM_DC_WINDOW_START_BLANK_PULSE_MIX - Blanking pulse mix
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareBlankingEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           Cdd_Pwm_DigitalCompareBlankingPulseType BlankingPulse);

/** \brief Set up the Digital Compare filter input
 *
 * This function sets the signal input source that will be filtered by the
 * Digital Compare module.
 *
 * \param[in] InstanceId          Numeric ID of the requested PWM instance
 * \param[in] FilterInput       Digital Compare signal source
 *                              - CDD_PWM_DC_WINDOW_SOURCE_DCAEVT1 - DC filter signal source is DCAEVT1
 *                              - CDD_PWM_DC_WINDOW_SOURCE_DCAEVT2 - DC filter signal source is DCAEVT2
 *                              - CDD_PWM_DC_WINDOW_SOURCE_DCBEVT1 - DC filter signal source is DCBEVT1
 *                              - CDD_PWM_DC_WINDOW_SOURCE_DCBEVT2 - DC filter signal source is DCBEVT2
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareFilterInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DigitalCompareFilterInputType, AUTOMATIC) FilterInput);

/*
 * DC Edge Filter
 */
/** \brief Enable Digital Compare Edge Filter
 *
 * This function enables the Digital Compare Edge filter to generate event
 * after configured number of edges.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareEdgeFilter(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(boolean, AUTOMATIC) Select);

/** \brief Set the Digital Compare Edge Filter Mode
 *
 * This function sets the Digital Compare Event filter mode.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] EdgeMode      Digital Compare Edge filter mode
 *                          - CDD_PWM_DC_EDGEFILT_MODE_RISING - DC edge filter mode is rising edge
 *                          - CDD_PWM_DC_EDGEFILT_MODE_FALLING - DC edge filter mode is falling edge
 *                          - CDD_PWM_DC_EDGEFILT_MODE_BOTH - DC edge filter mode is both edges
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareEdgeFilterMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_DigitalCompareEdgeFilterModeType, AUTOMATIC) EdgeMode);

/** \brief Set the Digital Compare Edge Filter Edge Count
 *
 * This function sets the Digital Compare Event filter Edge Count to generate events.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] EdgeCount     Digital Compare event filter count
 *                          - CDD_PWM_DC_EDGEFILT_EDGECNT_0 - No edge is required to generate event
 *                          - CDD_PWM_DC_EDGEFILT_EDGECNT_1 - 1 edge is required for event generation
 *                          - CDD_PWM_DC_EDGEFILT_EDGECNT_2 - 2 edges are required for event generation
 *                          - CDD_PWM_DC_EDGEFILT_EDGECNT_3U - 3U edges are required for event generation
 *                          - CDD_PWM_DC_EDGEFILT_EDGECNT_4 - 4 edges are required for event generation
 *                          - CDD_PWM_DC_EDGEFILT_EDGECNT_5 - 5 edges are required for event generation
 *                          - CDD_PWM_DC_EDGEFILT_EDGECNT_6 - 6 edges are required for event generation
 *                          - CDD_PWM_DC_EDGEFILT_EDGECNT_7 - 7 edges are required for event generation
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(uint16, AUTOMATIC) EdgeCount);

/** \brief Returns the Digital Compare Edge Filter Edge Count
 *
 * This function returns the configured Digital Compare Edge filter edge
 * count required to generate events. It can return values from 0-7.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Returns the configured DigitalCompare Edge filter edge count
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Returns the Digital Compare Edge filter captured edge count status
 *
 * This function returns the count of edges captured by Digital Compare Edge
 * filter. It can return values from 0-7.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Returns the count of captured edges
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareEdgeFilterEdgeStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set up the Digital Compare filter window offset
 *
 * This function sets the offset between window start pulse and blanking
 * window in TBCLK count. The function takes a 16bit count value for the offset value.
 *
 * \param[in] InstanceId            Numeric ID of the requested PWM instance
 * \param[in] WindowOffsetCount     Blanking window offset length
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareWindowOffset(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) WindowOffsetCount);

/** \brief Set up the Digital Compare filter window length
 *
 * This function sets up the Digital Compare filter blanking window length in
 * TBCLK count. The function takes a 16bit count value for the window length.
 *
 * \param[in] InstanceId            Numeric ID of the requested PWM instance
 * \param[in] WindowLengthCount     Blanking window length
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareWindowLength(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) WindowLengthCount);

/** \brief Return DC filter blanking window offset count
 *
 * This function returns DC filter blanking window offset count.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareBlankingWindowOffsetCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return DC filter blanking window length count
 *
 * This function returns DC filter blanking window length count.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareBlankingWindowLengthCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set up the Digital Compare Event source
 *
 * This function sets up the Digital Compare module Event sources.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Digital Compare module
 *                         - CDD_PWM_DC_MODULE_A: Digital Compare Module A
 *                         - CDD_PWM_DC_MODULE_B: Digital Compare Module B
 * \param[in] DcEvent Digital Compare Event number
 *                    - CDD_PWM_DC_EVENT_1: Digital Compare Event number 1
 *                    - CDD_PWM_DC_EVENT_2: Digital Compare Event number 2
 * \param[in] DcEventSource Digital Compare Event source
 *                         - CDD_PWM_DC_EVENT_SOURCE_FILT_SIGNAL: signal source is filtered
 *                           \note The signal source for this option is DCxEVTy, where the
 *                                 value of x is dependent on OutputChannel and the value of y is
 *                                 dependent on DcEvent. Possible signal sources are DCAEVT1U,
 *                                 DCBEVT1U, DCAEVT2 or DCBEVT2 depending on the value of both
 *                                 OutputChannel and DcEvent.
 *                         - CDD_PWM_DC_EVENT_SOURCE_ORIG_SIGNAL: signal source is unfiltered
 *                           The signal source for this option is DCxEVTy.
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareEventSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                         VAR(Cdd_Pwm_DigitalCompareEventSourceType, AUTOMATIC) DcEventSource);

/** \brief Set up the Digital Compare input sync mode
 *
 * This function sets up the Digital Compare module Event sources.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Digital Compare module
 *                         - CDD_PWM_DC_MODULE_A: Digital Compare Module A
 *                         - CDD_PWM_DC_MODULE_B: Digital Compare Module B
 * \param[in] DcEvent Digital Compare Event number
 *                    - CDD_PWM_DC_EVENT_1: Digital Compare Event number 1
 *                    - CDD_PWM_DC_EVENT_2: Digital Compare Event number 2
 * \param[in] SyncMode Digital Compare Event sync mode
 *                     - CDD_PWM_DC_EVENT_INPUT_SYNCED: DC input signal is synced with TBCLK
 *                     - CDD_PWM_DC_EVENT_INPUT_NOT SYNCED: DC input signal is not synced with TBCLK
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareEventSyncMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                           VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                           VAR(Cdd_Pwm_DigitalCompareSyncModeType, AUTOMATIC) SyncMode);

/** \brief Enable Digital Compare to generate Start of Conversion
 *
 * This function enables the Digital Compare Event 1 to generate Start of Conversion.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Digital Compare module
 *                         - CDD_PWM_DC_MODULE_A: Digital Compare Module A
 *                         - CDD_PWM_DC_MODULE_B: Digital Compare Module B
 * \param[in] Select Enable/disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                              VAR(boolean, AUTOMATIC) Select);

/** \brief Enable Digital Compare to generate sync out pulse
 *
 * This function enables the Digital Compare Event 1 to generate sync out pulse.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Digital Compare module
 *                         - CDD_PWM_DC_MODULE_A: Digital Compare Module A
 *                         - CDD_PWM_DC_MODULE_B: Digital Compare Module B
 * \param[in] Select Enable/disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareSyncEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(boolean, AUTOMATIC) Select);

/** \brief Set up the Digital Compare CBC latch mode
 *
 * This function sets up the Digital Compare CBC latch mode.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Digital Compare module
 *                         - CDD_PWM_DC_MODULE_A: Digital Compare Module A
 *                         - CDD_PWM_DC_MODULE_B: Digital Compare Module B
 * \param[in] DcEvent Digital Compare Event number
 *                    - CDD_PWM_DC_EVENT_1: Digital Compare Event number 1
 *                    - CDD_PWM_DC_EVENT_2: Digital Compare Event number 2
 * \param[in] LatchMode Digital Compare CBC latch mode
 *                      - CDD_PWM_DC_CBC_LATCH_DISABLED: DC cycle-by-cycle(CBC) latch is disabled
 *                      - CDD_PWM_DC_CBC_LATCH_ENABLED: DC cycle-by-cycle(CBC) latch is enabled
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareCBCLatchMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                          VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                          VAR(Cdd_Pwm_DigitalCompareCbcLatchModeType, AUTOMATIC) LatchMode);

/** \brief Sets the Digital Compare CBC latch clear event
*
* This function sets the Digital Compare CBC latch clear event.
*
* \param[in] InstanceId    Numeric ID of the requested PWM instance
* \param[in] OutputChannel Digital Compare module
*                         - CDD_PWM_DC_MODULE_A: Digital Compare Module A
*                         - CDD_PWM_DC_MODULE_B: Digital Compare Module B
* \param[in] DcEvent Digital Compare Event number
*                    - CDD_PWM_DC_EVENT_1: Digital Compare Event number 1
*                    - CDD_PWM_DC_EVENT_2: Digital Compare Event number 2
* \param[in] ClearEvent Digital Compare CBC latch clear event
*                       - CDD_PWM_DC_CBC_LATCH_CLR_CNTR_ZERO: DC CBC latch is cleared when counter is zero
*                       - CDD_PWM_DC_CBC_LATCH_CLR_ON_CNTR_PERIOD:
                                            DC CBC latch is cleared when counter is equal to period
*                       - CDD_PWM_DC_CBC_LATCH_CLR_ON_CNTR_ZERO_PERIOD:
                                            DC CBC latch is cleared when either counter is zero or equal to period
* \pre None
* \post None
* \return None
*
*********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectDigitalCompareCBCLatchClearEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                   VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                                   VAR(Cdd_Pwm_DigitalCompareCBCLatchClearEventType, AUTOMATIC)
                                                       ClearEvent);

/** \brief Gets the Digital Compare CBC latch status
 *
 * This function returns the Digital Compare module cycle-by-cycle(CBC) latch status.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Digital Compare module
 *                         - CDD_PWM_DC_MODULE_A: Digital Compare Module A
 *                         - CDD_PWM_DC_MODULE_B: Digital Compare Module B
 * \param[in] DcEvent Digital Compare Event number
 *                    - CDD_PWM_DC_EVENT_1: Digital Compare Event number 1
 *                    - CDD_PWM_DC_EVENT_2: Digital Compare Event number 2
 * \pre None
 * \post None
 * \return Digital Compare CBC latch status
 *         - true: CBC latch is enabled
 *         - false: CBC latch is disabled
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareCBCLatchStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                            VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent);

/*
 * DC capture mode
 */
/** \brief Enables the Time Base Counter Capture controller
 *
 * This function enables the time Base Counter Capture.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareCounterCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(boolean, AUTOMATIC) Select);

/** \brief Set the Time Base Counter Capture mode
 *
 * This function sets the mode the Time Base Counter value is read from. If
 * EnableShadowMode is true, CPU reads of the DCCAP register will return the
 * shadow register contents. If EnableShadowMode is false, CPU reads of the
 * DCCAP register will return the active register contents.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] EnableShadowMode Shadow read mode flag
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareCounterShadowMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(boolean, AUTOMATIC) EnableShadowMode);

/** \brief Return the DC Capture event status
 *
 * This function returns the DC capture event status.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return DC capture event status
 *         - true: A DC capture event has occurred
 *         - false: No DC Capture event has occurred
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_PrivGetDigitalCompareCaptureStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Configures DC capture operating mode
 *
 * This function is used to configure the DC capture operating mode. If
 * DisableClearMode is false, the TBCNT value is captured in active register
 * on occurrence of DCEVTFILT event. The trip events are ignored until next
 * PRD or ZRO event re-triggers the capture mechanism.
 * If DisableClearMode is true, the TBCNT value is captured, CAPSTS flag is
 * set and further trips are ignored until CAPSTS bit is cleared.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] DisableClearMode Clear mode bit
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareCounterCaptureMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                      VAR(boolean, AUTOMATIC) DisableClearMode);

/** \brief Clears DC capture latched status flag
 *
 * This function is used to clear the CAPSTS (set) condition.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearDigitalCompareCaptureStatusFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return the DC Time Base Counter capture value
 *
 * This function returns the DC Time Base Counter capture value. The value
 * read is determined by the mode as set in the
 * Cdd_Pwm_SetTimeBaseCounterReadMode() function.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return DC Time Base Counter Capture count value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetDigitalCompareCaptureCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable DC TRIP combinational input
 *
 * This function enables the specified Trip input.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TripInput Trip number
 *                     - CDD_PWM_DC_COMBINATIONAL_TRIPINx, where x is 1U,2U,...12U,14U,15
 * \param[in] DcType Digital Compare module
 *                  - CDD_PWM_DC_TYPE_DCAH: Digital Compare A High
 *                  - CDD_PWM_DC_TYPE_DCAL: Digital Compare A Low
 *                  - CDD_PWM_DC_TYPE_DCBH: Digital Compare B High
 *                  - CDD_PWM_DC_TYPE_DCBL: Digital Compare B Low
 * \param[in] Select Enable/disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareTripCombinationInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                        VAR(uint16, AUTOMATIC) TripInput,
                                                        VAR(Cdd_Pwm_DigitalCompareType, AUTOMATIC) DcType,
                                                        VAR(boolean, AUTOMATIC) Select);
/*
 * Event capture mode
 */

/** \brief Enables the Capture event
 *
 * This function enables the CAPIN.sync on which the edge detection logic
 * is performed.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureCaptureInEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Polarity selection for capture gate input
 *
 * This function selects the input polarity for capture gate.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] PolaritySelect Polarity to be selected for CAPGATE
 *                          - CDD_PWM_CAPGATE_INPUT_ALWAYS_ON: always on
 *                          - CDD_PWM_CAPGATE_INPUT_ALWAYS_OFF: always off
 *                          - CDD_PWM_CAPGATE_INPUT_SYNC: CAPGATE.sync
 *                          - CDD_PWM_CAPGATE_INPUT_SYNC_INVERT: CAPGATE.sync inverted
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigCaptureGateInputPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_SelectCaptureGateInputPolarityType, AUTOMATIC) PolaritySelect);

/** \brief Polarity selection for capture input
 *
 * This function selects the input polarity for capture.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] PolaritySelect Polarity to be selected for CAPIN
 *                          - CDD_PWM_CAPTURE_INPUT_CAPIN_SYNC: not inverted
 *                          - CDD_PWM_CAPTURE_INPUT_CAPIN_SYNC_INVERT: inverted
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivInvertCaptureInputPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_SelectCaptureInputPolarityType, AUTOMATIC) PolaritySelect);

/** \brief Enables independent pulse selection for Blanking and Capture Logic
 *
 * This function enables pulse selection determined by the CAPMIXSEL register.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureIndependentPulseLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(boolean, AUTOMATIC) Select);

/** \brief Capture event force load
 *
 * This function forces a load to occur on DCCAP.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceCaptureEventLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set the capture trip input
 *
 * This function sets the trip input to the Digital Compare (DC). For a given
 * dcType The function sets the tripSource to be the input to the DC.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TripInput Trip source
 *                     - CDD_PWM_DC_TRIP_TRIPINx: Trip x, where x ranges from 1 to 15 excluding 13U
 *                     - CDD_PWM_DC_TRIP_COMBINATION: selects all the Trip signals whose input
 *                                               is enabled by the Cdd_Pwm_EnableCaptureTripCombinationInput() function
 * \param[in] DcType Digital Compare type
 *                  - CDD_PWM_CAPTURE_GATE
 *                  - CDD_PWM_CAPTURE_INPUT
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectCaptureTripInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TripInput,
                                   VAR(Cdd_Pwm_CaptureInputType, AUTOMATIC) DcType);

/** \brief Enable Capture TRIP combinational input
 *
 * This function enables the specified Trip input.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TripInput Trip number. Valid values:
 *                     - CDD_PWM_DC_COMBINATIONAL_TRIPINx, where x is 1U,2U,...12U,14U,15
 * \param[in] DcType Digital Compare module. Valid values:
 *                  - CDD_PWM_CAPTURE_GATE
 *                  - CDD_PWM_CAPTURE_INPUT
 * \param[in] Select Boolean to enable/disable the trip input
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureCaptureTripCombinationInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(uint16, AUTOMATIC) TripInput,
                                                 VAR(Cdd_Pwm_CaptureInputType, AUTOMATIC) DcType,
                                                 VAR(boolean, AUTOMATIC) Select);
/** \brief Valley switching
*********************************************************************************************************************/

/** \brief Enable valley capture mode
 *
 * This function enables Valley Capture mode.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable valley capture mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureValleyCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Start valley capture mode
 *
 * This function starts Valley Capture sequence.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre Make sure you invoke Cdd_Pwm_SetValleyTriggerSource with the trigger
 *      variable set to CDD_PWM_VALLEY_TRIGGER_EVENT_SOFTWARE before calling this
 *      function.
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivStartValleyCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set valley capture trigger
 *
 * This function sets the trigger value that initiates Valley Capture sequence.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Trigger Valley counter trigger
 * \pre None
 * \post Set the number of Trigger source events for starting and stopping the
 *       valley capture using Cdd_Pwm_SetValleyTriggerEdgeCounts().
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetValleyTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_ValleyTriggerSourceType, AUTOMATIC) Trigger);

/** \brief Set valley capture trigger source count
 *
 * This function sets the number of trigger events required to start and stop
 * the valley capture count.
 * Maximum values for both startCount and stopCount is 15 corresponding to the
 * 15th edge of the trigger event.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] StartCount Number of events to start the valley capture
 * \param[in] StopCount Number of events to stop the valley capture
 * \pre None
 * \post None
 * \note A startCount value of 0 prevents starting the valley counter.
 *       A stopCount value of 0 prevents the valley counter from stopping.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetValleyTriggerEdgeCounts(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(uint16, AUTOMATIC) StartCount, VAR(uint16, AUTOMATIC) StopCount);

/** \brief Enable valley switching delay
 *
 * This function enables Valley switching delay.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable valley switching delay
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureValleyHwDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set Valley delay values
 *
 * This function sets the Valley delay value.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] DelayOffsetValue Software defined delay offset value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetValleySwDelayValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(uint16, AUTOMATIC) DelayOffsetValue);

/** \brief Set Valley delay mode
 *
 * This function sets the Valley delay mode values.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] DelayMode Valley delay mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetValleyDelayDivider(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_ValleyDelayModeType, AUTOMATIC) DelayMode);

/** \brief Get the valley edge status bit
 *
 * This function returns the status of the start or stop valley status
 * depending on the value of edge.
 * If a start or stop edge has occurred, the function returns true, if not it
 * returns false.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Edge Start or stop edge
 * \pre None
 * \post None
 * \return Returns true if the specified edge has occurred,
 *         Returns false if the specified edge has not occurred
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetValleyEdgeStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_ValleyCounterEdgeType, AUTOMATIC) Edge);

/** \brief Get the Valley Counter value
 *
 * This function returns the valley time base count value which is captured
 * upon occurrence of the stop edge condition selected by
 * Cdd_Pwm_SetValleyTriggerSource() and by the stopCount variable of the
 * Cdd_Pwm_SetValleyTriggerEdgeCounts() function.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Returns the valley base time count
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetValleyCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Get the Valley delay value
 *
 * This function returns the hardware valley delay count.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Returns the valley delay count
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetValleyHwDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable Global shadow load mode
 *
 * This function enables Global shadow to active load mode of registers.
 * The trigger source for loading shadow to active is determined by
 * Cdd_Pwm_SetGlobalLoadTrigger() function.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable global shadow load mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureGlobalLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set the Global shadow load trigger.
 *
 *   This function sets the global shadow load trigger
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] LoadTrigger is the pulse that causes global shadow load.
 *
 * This function sets the pulse that causes Global shadow to active load.
 * Valid values for the loadTrigger parameter are:
 *
 *   - CDD_PWM_GL_LOAD_PULSE_CNTR_ZERO              - load when counter is equal
 *                                                 to zero
 *   - CDD_PWM_GL_LOAD_PULSE_CNTR_PERIOD            - load when counter is equal
 *                                                 to period
 *   - CDD_PWM_GL_LOAD_PULSE_CNTR_ZERO_PERIOD       - load when counter is equal
 *                                                 to zero or period
 *   - CDD_PWM_GL_LOAD_PULSE_SYNC                    - load on sync event
 *   - CDD_PWM_GL_LOAD_PULSE_SYNC_OR_CNTR_ZERO      - load on sync event or when
 *                                                 counter is equal to zero
 *   - CDD_PWM_GL_LOAD_PULSE_SYNC_OR_CNTR_PERIOD    - load on sync event or when
 *                                                 counter is equal to period
 *   - CDD_PWM_GL_LOAD_PULSE_SYNC_CNTR_ZERO_PERIOD  - load on sync event or when
 *                                                 counter is equal to period
 *                                                 or zero
 *   - CDD_PWM_GL_LOAD_PULSE_CNTR_U_CMPC            - load when counter is equal
 *                                                 to CMPC while incrementing
 *   - CDD_PWM_GL_LOAD_PULSE_CNTR_D_CMPC            - load when counter is equal
 *                                                 to CMPC while decrementing
 *   - CDD_PWM_GL_LOAD_PULSE_CNTR_U_CMPD            - load when counter is equal
 *                                                 to CMPD while incrementing
 *   - CDD_PWM_GL_LOAD_PULSE_CNTR_D_CMPD            - load when counter is equal
 *                                                 to CMPD while decrementing
 *   - CDD_PWM_GL_LOAD_PULSE_GLOBAL_FORCE            - load on global force
 *
 * \pre None
 * \post None
 * \return None
 *
 ******************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetGlobalLoadTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_GlobalLoadTriggerType, AUTOMATIC) LoadTrigger);

/** \brief Set the number of Global load pulse event counts
 *
 * This function sets the number of Global Load pulse events that have to
 * occurred before a global load pulse is issued. Valid values for
 * prescaleCount range from 0 to 7. 0 being no event (disables counter),
 * and 7 representing 7 events.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] PrescalePulseCount Pulse event counts
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetGlobalLoadEventPrescale(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(uint16, AUTOMATIC) PrescalePulseCount);

/** \brief Return the number of Global load pulse event counts
 *
 * This function returns the number of Global Load pulse events that have
 * occurred. These pulse events are set by the Cdd_Pwm_SetGlobalLoadTrigger()
 * function.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Number of Global Load pulse events that have occurred
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetGlobalLoadEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable One shot global shadow to active load
 *
 * This function enables a one time global shadow to active load. Register
 * load happens every time the event set by the
 * Cdd_Pwm_SetGlobalLoadTrigger() occurs.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable one shot global shadow to active load
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureGlobalLoadOneShotMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(boolean, AUTOMATIC) Select);

/** \brief Enable One shot global shadow to active load
 *
 * This function enables a one time global shadow to active load. Register
 * load happens every time the event set by the
 * Cdd_Pwm_SetGlobalLoadTrigger() occurs.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivSetGlobalLoadOneShotLatch(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Force a software One shot global shadow to active load pulse
 *
 * This function forces a software a one time global shadow to active load
 * pulse.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceGlobalLoadOneShotEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable a register to be loaded Globally
 *
 * This function enables the register specified by loadRegister to be globally
 * loaded.
 * Valid values for loadRegister are:
 *  - CDD_PWM_GL_REGISTER_TBPRD_TBPRDHR  - Register TBPRD:TBPRDHR
 *  - CDD_PWM_GL_REGISTER_CMPA_CMPAHR    - Register CMPA:CMPAHR
 *  - CDD_PWM_GL_REGISTER_CMPB_CMPBHR    - Register CMPB:CMPBHR
 *  - CDD_PWM_GL_REGISTER_CMPC           - Register CMPC
 *  - CDD_PWM_GL_REGISTER_CMPD           - Register CMPD
 *  - CDD_PWM_GL_REGISTER_DBRED_DBREDHR  - Register DBRED:DBREDHR
 *  - CDD_PWM_GL_REGISTER_DBFED_DBFEDHR  - Register DBFED:DBFEDHR
 *  - CDD_PWM_GL_REGISTER_DBCTL          - Register DBCTL
 *  - CDD_PWM_GL_REGISTER_AQCTLA_AQCTLA2 - Register AQCTLA/A2
 *  - CDD_PWM_GL_REGISTER_AQCTLB_AQCTLB2 - Register AQCTLB/B2
 *  - CDD_PWM_GL_REGISTER_AQCSFRC        - Register AQCSFRC
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] LoadRegister Register to be globally loaded
 * \param[in] Select Boolean to enable/disable global loading for the register
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureGlobalLoadRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(uint16, AUTOMATIC) LoadRegister, VAR(boolean, AUTOMATIC) Select);

/** \brief Lock registers
 *
 * This function locks the specified register group.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] RegisterGroup Register group to lock
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivLockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_LockRegisterGroupType, AUTOMATIC) RegisterGroup);

/** \brief XCMP related APIs
 */

/** \brief Enable ePWM XCMP mode
 *
 * This function enables the ePWM XCMP mode.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable XCMP mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureXCmpMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Enable ePWM XCMP Split
 *
 * This function splits 8 XCMP registers between CMPA and CMPB equally.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable XCMP split
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureSplitXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Allocates XCMP registers to CMPA
 *
 * This function gives us choice to allocate range of XCMP registers to CMPA
 * Valid values for alloctype are:
 *    CDD_PWM_XCMP_NONE_CMPA      - Allocate 0 XCMP registers to CMPA
 *    CDD_PWM_XCMP_1_CMPA         - Allocate XCMP1 register to CMPA
 *    CDD_PWM_XCMP_2_CMPA         - Allocate XCMP1- XCMP2 registers to CMPA
 *    CDD_PWM_XCMP_3U_CMPA         - Allocate XCMP1- XCMP3U register to CMPA
 *    CDD_PWM_XCMP_4_CMPA         - Allocate XCMP1- XCMP4 registers to CMPA
 *    CDD_PWM_XCMP_5_CMPA         - Allocate XCMP1- XCMP5 register to CMPA
 *    CDD_PWM_XCMP_6_CMPA         - Allocate XCMP1- XCMP6 registers to CMPA
 *    CDD_PWM_XCMP_7_CMPA         - Allocate XCMP1- XCMP7 register to CMPA
 *    CDD_PWM_XCMP_8_CMPA         - Allocate XCMP1- XCMP8 register to CMPA
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Alloctype Range of XCMP registers to be allocated to CMPA
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivAllocAXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                       VAR(Cdd_Pwm_XCmp_AllocCmpAType, AUTOMATIC) Alloctype);

/** \brief Allocates XCMP registers to CMPB
 *
 * This function gives us choice to allocate range of XCMP registers to CMPB
 * Valid values for alloctype are:
 *    CDD_PWM_XCMP_1_CMPB         - Allocate XCMP5 register to CMPB
 *    CDD_PWM_XCMP_2_CMPB         - Allocate XCMP5- XCMP6 registers to CMPB
 *    CDD_PWM_XCMP_3U_CMPB         - Allocate XCMP5- XCMP7 register to CMPB
 *    CDD_PWM_XCMP_4_CMPB         - Allocate XCMP5- XCMP8 registers to CMPB
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Alloctype Range of XCMP registers to be allocated to CMPB
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivAllocBXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                       VAR(Cdd_Pwm_XCmp_AllocCmpBType, AUTOMATIC) Alloctype);

/** \brief Writes values to XCMP registers
 *
 * This function writes xcmpvalue to XCMP registers.
 * Valid values for XCmpReg are:
 *    CDD_PWM_XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *                          -XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *    CDD_PWM_XTBPRD_ACTIVE                               -XTBPRD_ACTIVE
 *    CDD_PWM_XTBPRD_SHADOW1                              -XTBPRD_SHADOW1
 *    CDD_PWM_XTBPRD_SHADOW2                              -XTBPRD_SHADOW2
 *    CDD_PWM_XTBPRD_SHADOW3                              -XTBPRD_SHADOW3
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] XCmpReg XCMP register offset
 * \param[in] XCmpValue Value to be written to XCMP registers
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg, VAR(uint16, AUTOMATIC) XCmpValue);

/** \brief Writes values to CMPx Shadow registers
 *
 * This function writes cmpvalue to CMPC/D shadow registers.
 * Valid values for cmpReg are:
 *    CDD_PWM_CMPC_SHADOW1                             -CMPC_SHADOW1
 *    CDD_PWM_CMPD_SHADOW1                             -CMPD_SHADOW1
 *    CDD_PWM_CMPC_SHADOW2                             -CMPC_SHADOW2
 *    CDD_PWM_CMPD_SHADOW2                             -CMPD_SHADOW2
 *    CDD_PWM_CMPC_SHADOW3                             -CMPC_SHADOW3
 *    CDD_PWM_CMPD_SHADOW3                             -CMPD_SHADOW3
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] XCmpReg CMP register offset
 * \param[in] XCmpValue Value to be written to CMPC/D shadow registers
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpShadowRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_XCompareRegType, AUTOMATIC) XCmpReg, VAR(uint16, AUTOMATIC) XCmpValue);

/** \brief Writes values to XMINMAX registers
 *
 * This function writes xcmpvalue to XCMP registers.
 * Valid values for xminmaxReg are:
 *    CDD_PWM_XMIN_ACTIVE                              -XMIN_ACTIVE
 *    CDD_PWM_XMAX_ACTIVE                              -XMAX_ACTIVE
 *    CDD_PWM_XMIN_SHADOW1                             -XMIN_SHADOW1
 *    CDD_PWM_XMAX_SHADOW1                             -XMAX_SHADOW1
 *    CDD_PWM_XMIN_SHADOW2                             -XMIN_SHADOW2
 *    CDD_PWM_XMAX_SHADOW2                             -XMAX_SHADOW2
 *    CDD_PWM_XMIN_SHADOW3                             -XMIN_SHADOW3
 *    CDD_PWM_XMAX_SHADOW3                             -XMAX_SHADOW3
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] XMinMaxReg XCMP register offset
 * \param[in] XCmpValue Value to be written to XCMP registers
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXMinMaxRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_XMinMaxRegType, AUTOMATIC) XMinMaxReg, VAR(uint16, AUTOMATIC) XCmpValue);

/** \brief Set up Action qualifier outputs based on XAQ registers
 *
 * This function sets up the Action Qualifier output on ePWM A or ePWMBU,
 * depending on the value of EpwmOutput, to a value specified by outPut based
 * on the input events - specified by event.
 * The following are valid values for the parameters.
 *   - CDD_pwmOutput
 *       - CDD_PWM_AQ_OUTPUT_A          - CDD_PWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - CDD_PWMxB output
 *   -shadowset
 *       - CDD_PWM_XCMP_ACTIVE          - XCMP set is Active
 *       - CDD_PWM_XCMP_SHADOW1         - XCMP set is Shadow 1
 *       - CDD_PWM_XCMP_SHADOW2         - XCMP set is Shadow 2
 *       - CDD_PWM_XCMP_SHADOW3         - XCMP set is Shadow 3U
 *   - output
 *       - CDD_PWM_AQ_OUTPUT_NO_CHANGE  - No change in the output pins
 *       - CDD_PWM_AQ_OUTPUT_LOW        - Set output pins to low
 *       - CDD_PWM_AQ_OUTPUT_HIGH       - Set output pins to High
 *       - CDD_PWM_AQ_OUTPUT_TOGGLE     - Toggle the output pins
 *   - event
 *    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1        -Time base counter equals XCMP1
 *    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2        -Time base counter equals XCMP2
 *    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3U        -Time base counter equals XCMP3U
 *    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4        -Time base counter equals XCMP4
 *    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5        -Time base counter equals XCMP5
 *    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6        -Time base counter equals XCMP6
 *    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7        -Time base counter equals XCMP7
 *    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8        -Time base counter equals XCMP8
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel ePWM pin type
 * \param[in] ShadowSet Shadow set number or active set
 * \param[in] Output Action Qualifier output
 * \param[in] Event Event that causes a change in output
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpActionQualifierAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) ShadowSet,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                         VAR(Cdd_Pwm_XCmpAqOutputEventType, AUTOMATIC) Event);

/** \brief Enables ePWM XCMP reload event
 *
 * This function enables the ePWM XCMP reload event.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivEnableXLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Forces register loading from shadow buffers
 *
 * This function is used for software force loading of the events in
 * global load mode.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceXLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Selects the mode for the XCMP Shadow registers
 *
 * This function gives us choice to select the mode for XCMP shadow registers
 * Valid values for mode are:
 *    CDD_PWM_XCMP_LOADONCE         - Load mode is LOADONCE
 *    CDD_PWM_XCMP_LOADMULTIPLE     - Load mode is LOADMULTIPLE
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Mode Load mode selection for XCMP Shadow registers
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_XCmpLoadModeType, AUTOMATIC) Mode);

/** \brief Selects the shadow register level allocation
 *
 * This function gives us choice to select the XCMP shadow registers level
 * Valid values for alloctype are:
 *    CDD_PWM_XCMP_SHADOWLEVEL_0 - Only Active reg is available
 *    CDD_PWM_XCMP_SHADOWLEVEL_1 - SHDW1 and Active regs
 *    CDD_PWM_XCMP_SHADOWLEVEL_2 - SHDW2U, SHDW1 and Active regs
 *    CDD_PWM_XCMP_SHADOWLEVEL_3U - SHDW3U, SHDW2U, SHDW1 and Active regs
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Level Shadow register level allocation options
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpShadowLevel(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_XCmpShadowLevelType, AUTOMATIC) Level);

/** \brief Selects which shadow register set is in use
 *
 * This function gives us choice to select the shadow buffer to use currently.
 * Valid values for alloctype are:
 *    CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_NULL         - No Shadow buffer is in use
 *    CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_ONE          - Shadow buffer 1 is in use
 *    CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_TWO          - Shadow buffer 2 is in use
 *    CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_THREE        - Shadow buffer 3U is in use
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Ptr Current shadow buffer in use
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpShadowBufPtrLoadOnce(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_XCmpShadowBufPtrType, AUTOMATIC) Ptr);

/** \brief Chooses how many times Shadow buffer 2 or 3U is applied
 *
 * This function gives us choice to select how many times shadow buffer
 * 2 or 3U is applied. Max value is 7.
 * count = 0   - 1 time
 * count = 1   - 2 times .....
 * count = 7U    - 8 times
 * Valid values for bufferset are:
 *    CDD_PWM_XCMP_SHADOW2         - XCMP set is Shadow 2
 *    CDD_PWM_XCMP_SHADOW3         - XCMP set is Shadow 3U
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Bufferset Shadow set number
 * \param[in] Count Number of times Shadow Buffer 2 or 3U is applied
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpShadowRepeatBufxCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) Bufferset,
                                         VAR(uint32, AUTOMATIC) Count);

/** \brief Minimum Dead Band Module related APIs
 */

/** \brief Enable Minimum DeadBand module
 *
 * This function enables the Minimum DeadBand module.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDBCFG_ENABLEA   - CDD_PWM output A
 *      - CDD_PWM_MINDBCFG_ENABLEB   - CDD_PWM output B
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Minimum DeadBand Block to be enabled
 * \param[in] Select Boolean to enable/disable Minimum DeadBand module
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureMinimumDeadBand(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                     VAR(boolean, AUTOMATIC) Select);

/** \brief Invert the Minimum DeadBand Reference Signal
 *
 * This function configures the Minimum DeadBand module to invert reference
 * signal which is used in the Minimum DeadBand module.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *  - invert
 *      - CDD_PWM_MINDB_REF_SIG            - No inversion
 *      - CDD_PWM_MINDB_REF_SIG_INVERT     - Invert the signal
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Minimum DeadBand block to be configured
 * \param[in] Invert Specifies whether reference signal is to be inverted or not
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivInvertMinimumDeadBandSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                        VAR(boolean, AUTOMATIC) Invert);

/** \brief Select signal for AND OR logic of Minimum DeadBand Module
 *
 * This function configures how the signal will be combined with the
 * PWM output. The signal can be inverted and ANDed with PWM output or it can
 * be ORed with the PWM output.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *  - logic
 *      - TRUE - CDD_PWM_MINDB_POLSEL_INVERT_LOGICAL_AND   - Invert and Logical AND
 *      - FALSE - CDD_PWM_MINDB_POLSEL_LOGICAL_OR           - Logical OR
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Minimum DeadBand block to be configured
 * \param[in] Logic Specifies how the signal will be combined
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectMinimumDeadBandAndOrLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                            VAR(boolean, AUTOMATIC) Logic);

/** \brief Select Minimum DeadBand Blocking Signal
 *
 * This function configures the blocking signal for Minimum DeadBand module.
 * Either of the Block A or Block B signal can be selected as blocking signal.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *  - blockSrc
 *      - CDD_PWM_MINDB_BLOCKING_SIGNAL_BYPASS    - Block Source same
 *      - CDD_PWM_MINDB_BLOCKING_SIGNAL_SWAPBLOCK - Block Source different
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Minimum DeadBand block to be configured
 * \param[in] BlockingSignal Blocking signal to be used for a block
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectMinimumDeadBandBlockingSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                VAR(boolean, AUTOMATIC) BlockingSignal);

/** \brief Select Minimum DeadBand Reference Signal
 *
 * This function selects the reference signal for Minimum DeadBand module.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *  - reference
 *      - CDD_PWM_MINDB_DEPWM             - Minimum Dead Band DE reference
 *      - CDD_PWM_MINDB_SEL_OUTXBAR_OUTy  - Output y from PWM Output XBAR
 *                                       ('y' can be from 1 to 15)
 *                                       ex. \b EPWM_MINDB_SEL_OUTXBAR_OUT1
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Minimum DeadBand block to be configured
 * \param[in] ReferenceSignal Reference signal to be selected
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectMinimumDeadBandReferenceSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                 VAR(Cdd_Pwm_MindbReferenceSignalType, AUTOMATIC) ReferenceSignal);

/** \brief Get Minimum DeadBand Delay Value
 *
 * This function returns the delay value for the Minimum DeadBand module.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Minimum DeadBand block whose value is needed
 * \pre None
 * \post None
 * \return Delay value of the Minimum DeadBand module
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetMinDeadBandDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/** \brief Set the Minimum DeadBand Delay Value
 *
 * This function configures the Minimum DeadBand delay value for the
 * specified block.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *  - delay: Minimum dead band delay on ePWM in terms of SYSCLK cycles
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Minimum DeadBand block to be configured
 * \param[in] Delay Delay value to be programmed for the Minimum DeadBand
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetMinDeadBandDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel, VAR(uint16, AUTOMATIC) Delay);

/** \brief Illegal Combo Logic
 *
 *********************************************************************************************************************/

/** \brief Enable Illegal Combo Logic
 *
 * This function enables the Illegal Combo Logic block.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Illegal Combo Logic block to be enabled
 * \param[in] Select Enable/disable selection for Illegal Combo Logic
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureIllegalComboLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                       VAR(boolean, AUTOMATIC) Select);

/** \brief Select XBAR input for Illegal Combo Logic
 *
 * This function selects which Xbar signal feeds into the Illegal Combo Logic.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *  - xbarInput
 *      - CDD_PWM_MINDB_ICL_XBAR_OUTy - Output y from ICL XBAR
 *                                    ('y' can be from 0 to 15)
 *                                    ex. \b EPWM_MINDB_ICL_XBAR_OUT1
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Illegal Combo Logic block to be configured
 * \param[in] XbarInput Xbar signal to feed into the Illegal Combo Logic
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectXbarInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                            VAR(Cdd_Pwm_XbarInputType, AUTOMATIC) XbarInput);

/** \brief Force Decx values
 *
 * This function programs value in the Decx register fields of the Illegal
 * Combo Logic module.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - CDD_PWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - CDD_PWM output B
 *  - decx
 *      - CDD_PWM_MINDB_ICL_LUT_DECx - 'x' can be from 0 to 7
 *  - force
 *      - value that can be forced can be either 0 or 1
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Illegal Combo Logic block to be configured
 * \param[in] Decx Register to be programmed
 * \param[in] Force Value to be programmed in the register
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetLutDecX(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                       VAR(Cdd_Pwm_LutDecXType, AUTOMATIC) Decx, VAR(uint16, AUTOMATIC) Force);

/** \brief Diode Emulation logic related APIs
 *
 *********************************************************************************************************************/

/** \brief Enable ePWM diode emulation mode
 *
 * This function enables the ePWM diode emulation mode.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection for diode emulation mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(boolean, AUTOMATIC) Select);

/** \brief Selects the mode for the Diode emulation mode
 *
 * This function gives us choice to select the mode for Diode emulation mode
 * Valid values for input variables are:
 * - mode
 *    CDD_PWM_DIODE_EMULATION_CBC         - Diode Emulation mode is Cycle by Cycle
 *    CDD_PWM_DIODE_EMULATION_OST         - Diode Emulation mode is One Shot
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Mode Load mode selection for Diode emulation mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_DiodeEmulationModeType, AUTOMATIC) Mode);

/** \brief Set ePWM diode emulation re-entry delay
 *
 * This function determines the blocking window after DEACTIVE flag is cleared
 * in which setting of DEACTIVE flag is prevented from being set.
 *
 * Valid values for input variables are:
 * - delay: Max value of delay is 256.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Delay Re-entry delay in terms of number of PWMSYNCOUT events
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDiodeEmulationReentryDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) Delay);

/** \brief Set ePWM diode emulation trip source for TripL
 *
 * This function is used to configure the comparator whose
 * trip sources will be used.
 * Valid values for \e source are:
 *    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT[0-16]     - INPUTXBAR out[0-16] signal
 *    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT[0-16]  - CLBINPUTXBAR out[0-16] signal
 *    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL[1-11]        - CMPSSTRIPL[1-11] signal
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Source Trip source
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDiodeEmulationTripLowSources(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(Cdd_Pwm_DETripLowSourceType, AUTOMATIC) Source);

/** \brief Set ePWM diode emulation trip source for TripH
 *
 * This function is used to configure the comparator whose
 * trip sources will be used.
 * Valid values for \e source are:
 *    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT[0-16]     - INPUTXBAR out[0-16] signal
 *    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT[0-16]  - CLBINPUTXBAR out[0-16] signal
 *    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH[1-11]        - CMPSSTRIPH[1-11] signal
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Source Trip source
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDiodeEmulationTripHighSources(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_DETripHighSourceType, AUTOMATIC) Source);

/** \brief Selects ePWM diode emulation pwm signal
 *
 * This function is used to select the pwm signal in DE mode.
 * Valid values for channel are:
 *    CDD_PWM_DE_CHANNEL_A     - Diode emulation channel A
 *    CDD_PWM_DE_CHANNEL_B     - Diode emulation channel B
 *
 * Valid values for signal are:
 *    CDD_PWM_DE_SYNC_TRIPH_OR_TRIPL     - synchronized version of
 *                                TRIPH or TRIPL signal
 *    CDD_PWM_DE_SYNC_INV_TRIPH_OR_TRIPL - synchronized and inverted version
 *                                of TRIPH or TRIPL signal
 *    CDD_PWM_DE_LOW               - a constant low signal
 *    CDD_PWM_DE_HIGH              - a constant high signal
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel EPWM output channel
 * \param[in] DiodeEmuationsignal Signal selected by the TRIPSEL[A/B]
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectDiodeEmulationPwmSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                          VAR(Cdd_Pwm_DiodeEmulationSignalType, AUTOMATIC) DiodeEmuationsignal);

/** \brief Selects between TRIPH and TRIPL for an epwm channel in DE mode
 *
 * This function is used to select between TRIPH and TRIPL
 * for a channel in DE mode.
 * Valid values for channel are:
 *    CDD_PWM_DE_CHANNEL_A     - Diode emulation channel A
 *    CDD_PWM_DE_CHANNEL_B     - Diode emulation channel B
 *
 * Valid values for signal are:
 *     0 for TRIPH
 *     1 for TRIPL
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel EPWM output channel
 * \param[in] TripSrc Diode Emulation trip sources signal
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectDiodeEmulationTripSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                           VAR(Cdd_Pwm_DiodeEmulationTripSrcType, AUTOMATIC) TripSrc);

/** \brief PWMTRIP does not bypass the diode emulation logic
 *
 * This function is used to go through DEL.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivNoBypassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief PWMTRIP bypasses the diode emulation PWM generation logic
 *
 * This function is used to bypass DEL.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivbypassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Forces DEACTIVE flag to 1
 *
 * This function is used to force DEACTIVE flag to 1.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceDiodeEmulationActive(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enables DE monitor control mode
 *
 * This function is used to enable the DE monitor counter function.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection for DE monitor mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDiodeEmulationMonitorModeControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                      VAR(boolean, AUTOMATIC) Select);

/** \brief Sets the DE monitor counter step size
 *
 * This function is used to set the DE monitor counter step size.
 * Valid values for \e direction are:
 *    CDD_PWM_DE_COUNT_UP     - Diode emulation count up step size
 *    CDD_PWM_DE_COUNT_DOWN   - Diode emulation count down step size.
 *
 *    Max value of stepsize is 256.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Direction Direction of the monitor counter counting either UP or DOWN
 * \param[in] StepSize Amount by which the counter increments or decrements at each step
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDiodeEmulationMonitorModeStep(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DiodeEmulationDirectionType, AUTOMATIC) Direction,
                                             VAR(uint8, AUTOMATIC) StepSize);

/** \brief Sets the DE monitor counter threshold value
 *
 * This function is used to set the DE monitor counter threshold.
 *
 * Max value of threshold is 2^16.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Threshold Max value till which the monitor counter can count
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDiodeEmulationMonitorCounterThreshold(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                     VAR(uint16, AUTOMATIC) Threshold);

/** \brief Clears DE mode active flag
 *
 * This function is used to clear the DE mode active flag
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivClearDiodeEmulationActiveFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief HRPWM related APIs
 *
 *********************************************************************************************************************/

/** \brief Sets the consolidated phase shift value in high resolution mode
 *
 * This function sets the consolidated phase shift value, that is, both TBPHS
 * and TBPHSHR values are configured together.
 *
 * Call EPWM_enablePhaseShiftLoad & HRPWM_enableHRPhaseShiftLoad() functions
 * to enable loading of the phaseCount in high resolution mode.
 *
 * \b Note: phaseCount is a 24-bit value.
 * \b Note: For configuring TBPHS = 0x3C, TBPHSHR = 0x2;
 *          phaseCount = 0x3C02
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] PhaseCount Consolidated phase shift count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
#if (STD_ON == CDD_PWM_HRPWM_SUPPORTED)
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) PhaseCount);

/** \brief Sets only the high resolution phase shift value
 *
 * This function sets only the high resolution phase shift(TBPHSHR) value.
 * Call the HRPWM_enableHRPhaseShiftLoad() function to enable loading of
 * the hrPhaseCount.
 *
 * \b Note: hrPhaseCount is an 8-bit value.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] HrPhaseCount High resolution phase shift count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResPhaseShiftOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(uint16, AUTOMATIC) HrPhaseCount);

/** \brief Sets the consolidated period of time base counter used in HR mode
 *
 * This function sets the consolidated period of time base counter value
 * (TBPRD:TBPRDHR) required in high resolution mode.
 *
 * User should map the desired period or frequency of the waveform into
 * the correct periodCount.
 *
 * \b Note: periodCount is a 24 bit value.
 * \b Note: For configuring TBPRD = 0x3C, TBPRDHR = 0xA;
 *          periodCount = 0x3C0A
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] PeriodCount Consolidated period count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) PeriodCount);

/** \brief Sets only the high resolution time base counter
 *
 * This function sets only the high resolution time base counter(TBPRDHR)
 * value.
 *
 * User should map the desired period or frequency of the waveform into
 * the correct hrPeriodCount.
 *
 * \b Note: hrPeriodCount is an 8-bit value.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] HrPeriodCount High resolution period count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(uint16, AUTOMATIC) HrPeriodCount);

/** \brief Gets the consolidated time base period count used in HR mode
 *
 * This function gets the consolidated time base period(TBPRD:TBPRDHR) value
 * used in high resolution mode.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The consolidated time base period count value
 *
 *********************************************************************************************************************/
FUNC(uint32, CDD_PWM_CODE) Cdd_Pwm_PrivHrpwmGetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Gets only the high resolution time base period count
 *
 * This function gets only the high resolution time base period(TBPRDHR) value.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The high resolution time base period count value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmGetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Sets the high resolution edge controlled by MEP (Micro Edge Positioner)
 *
 * This function sets the edge of the PWM that is controlled by MEP (Micro
 * Edge Positioner). Valid values for the parameters are:
 *  - OutputChannel
 *      - HRPWM_CHANNEL_A  - HRPWM A
 *      - HRPWM_CHANNEL_B  - HRPWM B
 *  - MepEdgeMode
 *      - HRPWM_MEP_CTRL_DISABLE                 - HRPWM is disabled
 *      - HRPWM_MEP_CTRL_RISING_EDGE             - MEP (Micro Edge Positioner)
 *                                                 controls rising edge.
 *      - HRPWM_MEP_CTRL_FALLING_EDGE            - MEP (Micro Edge Positioner)
 *                                                 controls falling edge.
 *      - HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE - MEP (Micro Edge Positioner)
 *                                                 controls both edges.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel High resolution period module
 * \param[in] MepEdgeMode Edge of the PWM that is controlled by MEP
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetMepEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                  VAR(Cdd_Pwm_HrpwmMepEdgeModeType, AUTOMATIC) MepEdgeMode);

/** \brief Sets the MEP (Micro Edge Positioner) control mode
 *
 * This function sets the mode (register type) the MEP (Micro Edge Positioner)
 * will control. Valid values for the parameters are:
 *  - OutputChannel
 *      - HRPWM_CHANNEL_A  - HRPWM A
 *      - HRPWM_CHANNEL_B  - HRPWM B
 *  - MepCtrlMode
 *      - HRPWM_MEP_DUTY_PERIOD_CTRL      - MEP (Micro Edge Positioner) is
 *                                          controlled by value of CMPAHR/
 *                                          CMPBHR(depending on the value of
 *                                          channel) or TBPRDHR.
 *      - HRPWM_MEP_PHASE_CTRL            - MEP (Micro Edge Positioner) is
 *                                          controlled by TBPHSHR.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel High resolution period module
 * \param[in] MepCtrlMode The MEP (Micro Edge Positioner) control mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetMepControlMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                   VAR(Cdd_Pwm_HrpwmMepCtrlModeType, AUTOMATIC) MepCtrlMode);

/** \brief Sets the high resolution comparator load mode
 *
 * This function sets the shadow load mode of the high resolution comparator.
 * The function sets the COMPA or COMPB register depending on the OutputChannel
 * variable.
 * Valid values for the parameters are:
 *  - OutputChannel
 *      - HRPWM_CHANNEL_A  - HRPWM A
 *      - HRPWM_CHANNEL_B  - HRPWM B
 *  - LoadEvent
 *      - HRPWM_LOAD_ON_CNTR_ZERO         - load when counter equals zero
 *      - HRPWM_LOAD_ON_CNTR_PERIOD       - load when counter equals period
 *      - HRPWM_LOAD_ON_CNTR_ZERO_PERIOD  - load when counter equals zero or
 *                                          period
 *      - HRPWM_LOAD_ON_CMPx_EQ           - load on translator event CMPA/B-3
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel High resolution period module
 * \param[in] LoadEvent The MEP (Micro Edge Positioner) control mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetCounterCompareShadowLoadEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                  VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent);

/** \brief Sets the high resolution output swap mode
 *
 * This function sets the HRPWM output swap mode. If EnableOutputSwap is true,
 * ePWMxA signal appears on ePWMxB output and ePWMxB signal appears on ePWMxA
 * output. If it is false ePWMxA and ePWMxB outputs are unchanged.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] EnableOutputSwap The output swap flag
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(boolean, AUTOMATIC) EnableOutputSwap);

/** \brief Sets the high resolution output on ePWMxB
 *
 * This function sets the HRPWM output signal on ePWMxB. If OutputOnB is
 * HRPWM_OUTPUT_ON_B_INV_A, ePWMxB output is an inverted version of
 * ePWMxA. If OutputOnB is HRPWM_OUTPUT_ON_B_NORMAL, ePWMxB output is
 * ePWMxB.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputOnB The output signal on ePWMxB
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetChannelBOutputPath(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_HrpwmChannelBOutputType, AUTOMATIC) OutputOnB);

/** \brief Enables MEP (Micro Edge Positioner) automatic scale mode
 *
 * This function enables the MEP (Micro Edge Positioner) to automatically
 * scale HRMSTEP.
 *
 * The SFO library will calculate required MEP steps per coarse steps and
 * feed it to HRMSTEP register. The MEP calibration module will use the value
 * in HRMSTEP to determine appropriate number of MEP steps represented by
 * fractional duty cycle.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable automatic conversion
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmConfigureAutoConversion(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(boolean, AUTOMATIC) Select);

/** \brief Enable high resolution period feature
 *
 * This function enables the high resolution period feature.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable period control
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmConfigurePeriodControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(boolean, AUTOMATIC) Select);

/** \brief Enable high resolution phase load
 *
 * This function enables loading of high resolution phase shift value which is
 * set by the function HRPWM_setPhaseShift().
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable phase shift load
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(boolean, AUTOMATIC) Select);

/** \brief Set high resolution PWMSYNC source
 *
 * This function sets the high resolution PWMSYNC pulse source.
 * Valid values for SyncPulseSource are:
 *  - HRPWM_PWMSYNC_SOURCE_PERIOD      - Counter equals Period.
 *  - HRPWM_PWMSYNC_SOURCE_ZERO        - Counter equals zero.
 *  - HRPWM_PWMSYNC_SOURCE_COMPC_UP    - Counter equals COMPC when
 *                                       counting up.
 *  - HRPWM_PWMSYNC_SOURCE_COMPC_DOWN  - Counter equals COMPC when
 *                                       counting down.
 *  - HRPWM_PWMSYNC_SOURCE_COMPD_UP    - Counter equals COMPD when
 *                                       counting up.
 *  - HRPWM_PWMSYNC_SOURCE_COMPD_DOWN  - Counter equals COMPD when
 *                                       counting down.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] SyncPulseSource The PWMSYNC source
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetSyncPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_HrpwmSyncPulseSourceType, AUTOMATIC) SyncPulseSource);

/** \brief Sets the Translator Remainder value
 *
 * This function sets the Translator Remainder value.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TrRemVal The translator remainder value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetTranslatorRemainder(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(uint16, AUTOMATIC) TrRemVal);

/** \brief Sets the consolidated counter compare values in HR mode
 *
 * This function sets the consolidated counter compare(CMPx:CMPxHR) value
 * required in high resolution mode for counter compare registers.
 * Valid values for OutputChannel are:
 *  - HRPWM_COUNTER_COMPARE_A - counter compare A.
 *  - HRPWM_COUNTER_COMPARE_B - counter compare B.
 *
 * \b Note: CompareCount is a 24 bit value.
 * \b Note: For configuring CMPA = 0xB4U, CMPAHR = 0x64; value of
 *          CompareCount = 0xB464
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel The Counter Compare module
 * \param[in] CompareCount The consolidated counter compare count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                        VAR(uint32, AUTOMATIC) CompareCount);

/** \brief Sets only the high resolution counter compare value
 *
 * This function sets the high resolution counter compare value(CMPxHR) for
 * counter compare registers.
 * Valid values for OutputChannel are:
 *  - HRPWM_COUNTER_COMPARE_A - counter compare A.
 *  - HRPWM_COUNTER_COMPARE_B - counter compare B.
 *
 * \b Note: HrCompCount is an 8-bit value.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel The Counter Compare module
 * \param[in] HrCompCount The high resolution counter compare count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                 VAR(uint16, AUTOMATIC) HrCompCount);

/** \brief Gets the consolidated counter compare values
 *
 * This function gets the consolidated counter compare(CMPx:CMPxHR) value
 * used in high resolution for the counter compare module specified.
 * Valid values for OutputChannel are:
 *  - HRPWM_COUNTER_COMPARE_A - counter compare A.
 *  - HRPWM_COUNTER_COMPARE_B - counter compare B.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel The Counter Compare module value
 * \pre None
 * \post None
 * \return The consolidated counter compare value
 *
 *********************************************************************************************************************/
FUNC(uint32, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmGetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/** \brief Gets only the high resolution counter compare values
 *
 * This function gets only the high resolution counter compare(CMPxHR) value
 * for the counter compare module specified.
 * Valid values for OutputChannel are:
 *  - HRPWM_COUNTER_COMPARE_A - counter compare A.
 *  - HRPWM_COUNTER_COMPARE_B - counter compare B.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel The Counter Compare module value
 * \pre None
 * \post None
 * \return The high resolution counter compare value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/** \brief Sets the consolidated RED count in high resolution mode
 *
 * This function sets the consolidated RED (Rising Edge Delay) count
 * (DBRED:DBREDHR) value used in high resolution mode. The value of
 * RedCount should be less than 0x200000.
 *
 * \b Note: RedCount is a 21 bit value.
 * \b Note: For configuring DBRED = 0x4U, DBREDHR = 0x1; value of
 *          RedCount = ((0x4 << 7) | 0x1) = 0x201
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] RedCount The high resolution RED count
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetRisingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) RedCount);

/** \brief Sets the high resolution RED count only
 *
 * This function sets only the high resolution RED (Rising Edge Delay)
 * count(DBREDHR) value.
 * The value of HrRedCount should be less than 128.
 *
 * \b Note: HrRedCount is a 7-bit value.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] HrRedCount The high resolution RED count
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResRisingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(uint16, AUTOMATIC) HrRedCount);

/** \brief Sets the consolidated FED value in high resolution mode
 *
 * This function sets the consolidated FED (Falling Edge Delay) count
 * (DBFED: DBFEDHR) value used in high resolution mode. The value of FedCount
 * should be less than 0x200000.
 *
 * \b Note: FedCount is a 21 bit value.
 * \b Note: For configuring DBFED = 0x4U, DBFEDHR = 0x1; value of
 *          FedCount = ((0x4 << 7) | 0x1) = 0x201
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] FedCount The high resolution FED count
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetFallingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) FedCount);

/** \brief Sets high resolution FED count only.
 *
 * This function sets only the high resolution FED (Falling Edge Delay) count (DBFEDHR)value. The value of hrFedCount
 * should be less than 128.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] HrFedCount     The high resolution FED count. 7-bit value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResFallingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(uint16, AUTOMATIC) HrFedCount);

/** \brief Set high resolution MEP (Micro Edge Positioner) step
 *
 * This function sets the high resolution MEP (Micro Edge Positioner) step
 * count. The maximum value for the MEP count step is 255.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] MepCount The high resolution MEP (Micro Edge Positioner) step count
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetMepStep(VAR(Cdd_Pwm_HrpwmCalInstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) MepCount);

/** \brief Set high resolution Dead Band MEP (Micro Edge Positioner) control
 *
 * This function sets the high resolution Dead Band edge that the MEP (Micro
 * Edge Positioner) controls. Valid values for MepDbEdge are:
 *   - HRPWM_DB_MEP_CTRL_DISABLE  - HRPWM is disabled
 *   - HRPWM_DB_MEP_CTRL_RED      - MEP (Micro Edge Positioner) controls
 *                                  Rising Edge Delay
 *   - HRPWM_DB_MEP_CTRL_FED      - MEP (Micro Edge Positioner) controls
 *                                  Falling Edge Delay
 *   - HRPWM_DB_MEP_CTRL_RED_FED  - MEP (Micro Edge Positioner) controls both
 *                                  Falling and Rising edge delays
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] MepDbEdge The high resolution MEP (Micro Edge Positioner) control edge
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetDeadbandMEPEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_HrpwmMepDeadBandEdgeModeType, AUTOMATIC) MepDbEdge);

/** \brief Set the high resolution Dead Band RED load mode
 *
 * This function sets the high resolution Rising Edge Delay(RED)Dead Band
 * count load mode.
 * Valid values for LoadEvent are:
 *   - HRPWM_LOAD_ON_CNTR_ZERO        - load when counter equals zero
 *   - HRPWM_LOAD_ON_CNTR_PERIOD      - load when counter equals period
 *   - HRPWM_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero
 *                                       or period
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] LoadEvent The shadow to active load event
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetRisingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent);

/** \brief Set the high resolution Dead Band FED load mode
 *
 * This function sets the high resolution Falling Edge Delay(FED) Dead Band
 * count load mode.
 * Valid values for LoadEvent are:
 *   - HRPWM_LOAD_ON_CNTR_ZERO        - load when counter equals zero
 *   - HRPWM_LOAD_ON_CNTR_PERIOD      - load when counter equals period
 *   - HRPWM_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero
 *                                       or period
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] LoadEvent The shadow to active load event
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetFallingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent);

/** \brief Lock HRPWM registers
 *
 * This function locks the specified HRPWM register group.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] RegisterGroup The register group to lock
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmLockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_HrpwmLockRegisterGroupType, AUTOMATIC) RegisterGroup);

/** \brief Sets the consolidated XCMP values in HR mode
 *
 * This function sets the consolidated counter compare(XCMPx:XCMPxHR) value
 * required in high resolution mode for XCMP registers.
 * Valid values for XCmpReg are:
 *    EPWM_XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *                          -XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *    EPWM_XTBPRD_ACTIVE                               -XTBPRD_ACTIVE
 *    EPWM_XTBPRD_SHADOW1                              -XTBPRD_SHADOW1
 *    EPWM_XTBPRD_SHADOW2                              -XTBPRD_SHADOW2
 *    EPWM_XTBPRD_SHADOW3                              -XTBPRD_SHADOW3
 *
 * \b Note: For configuring XCMPx = 0x3E8, XCMPxHR = 0x64; value of
 *          XCmpValue = 0x03E80064
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] XCmpReg The XCMP register offset
 * \param[in] XCmpValue The consolidated value to be written to XCMP registers
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg, VAR(uint32, AUTOMATIC) XCmpValue);

/** \brief Sets only the high resolution XCMP value
 *
 * This function sets the high resolution counter compare value(XCMPx_HR) for
 * XCMP registers.
 * Valid values for XCmpReg are:
 *    EPWM_XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *                          -XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *    EPWM_XTBPRD_ACTIVE                               -XTBPRD_ACTIVE
 *    EPWM_XTBPRD_SHADOW1                              -XTBPRD_SHADOW1
 *    EPWM_XTBPRD_SHADOW2                              -XTBPRD_SHADOW2
 *    EPWM_XTBPRD_SHADOW3                              -XTBPRD_SHADOW3
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] XCmpReg The XCMP register offset
 * \param[in] HrXCmpValue The HR value to be written to XCMP registers
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResXCmpRegValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg,
                                          VAR(uint16, AUTOMATIC) HrXCmpValue);

/** \brief SFO V8 Calibration Function
 *
 * This function performs calibration for the SFO.
 *
 * \param[in] Cdd_Pwm_HrpwmCalId    Numeric ID of the requested HRPWM CAL instance
 * \pre None
 * \post None
 * \return Calibration status
 *
 *********************************************************************************************************************/
FUNC(Cdd_Pwm_SfoStatusType, CDD_PWM_CODE) Cdd_Pwm_PrivSfo(Cdd_Pwm_HrpwmCalInstanceType Cdd_Pwm_HrpwmCalId);

#endif
#endif

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CDD_PWM_PRIV_H*/
/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Priv.h
 *********************************************************************************************************************/
