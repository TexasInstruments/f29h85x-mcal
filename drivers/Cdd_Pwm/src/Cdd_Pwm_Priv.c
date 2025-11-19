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
 *  File:       Cdd_Pwm_Priv.c
 *  Generator:  None
 *
 *  Description: This file contains private function definitions that are defined in Cdd_Pwm_Priv.h
 *file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm_Priv.h"
#include "hw_hrpwmcal.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

#define CDD_PWM_MEP1   80U
#define CDD_PWM_MEP2   200U
#define CDD_PWM_PRDVAL 65535U /* for all elements in testmode */

#define CDD_PWM_HRCAL_BASESTEP (HRPWMCAL2_BASE - HRPWMCAL1_BASE)

#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/* Cdd_Pwm driver object to store status of PWM instances and channels */
#define CDD_PWM_START_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"
P2VAR(Cdd_Pwm_DriverObjType, AUTOMATIC, CDD_PWM_VAR_INIT) Cdd_Pwm_DrvObjPtr = NULL_PTR;
#define CDD_PWM_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"

/* Cdd_Pwm configuration pointer to access driver configuration. */
#define CDD_PWM_START_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"
P2CONST(Cdd_Pwm_ConfigType, AUTOMATIC, CDD_PWM_CONST) Cdd_Pwm_ConfigPtr = NULL_PTR;
#define CDD_PWM_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)
/** \brief Set time Base counter compare value
 *
 * This function sets the time Base counter compare value
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  OutputChannel   Output channel of the PWM instance
 * \param[in]  CompareCount   Compare value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_SetCounterCompareValue(uint32 Base, Cdd_Pwm_OutputChannelType OutputChannel, uint16 CompareCount);

/** \brief Set up Action qualifier outputs
 *
 * This function sets the clock prescaler function for the PWM hardware unit
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  ChannelType   Output Channel Type
 * \param[in]  Output   Action qualifier output type
 * \param[in]  Event   Event that causes a change in the output
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_SetActionQualifierAction(uint32 Base, Cdd_Pwm_OutputChannelType ChannelType,
                                     Cdd_Pwm_ActionQualifierOutputType      Output,
                                     Cdd_Pwm_ActionQualifierOutputEventType Event);

/** \brief Clear Action qualifier outputs
 *
 * This function clears all action qualifier actions for the specified PWM output channel
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  ChannelType   Output Channel Type
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_ClearActionQualifierAction(uint32 Base, Cdd_Pwm_OutputChannelType ChannelType);

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
#if (STD_ON == CDD_PWM_DEINIT_API)

/** \brief Clear the interrupt prescale for the PWM instance
 *
 * This function lear the interrupt prescale for the PWM instance
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearInterruptPrescale(uint32 Base);

#endif /* CDD_PWM_DEINIT_API */
#endif /* CDD_PWM_NOTIFICATION_SUPPORTED */

/** \brief Set up Action qualifier output
 *
 * This function sets the action qualifier action for the PWM channel and it clears the previous AQ
 *configuration
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  ChannelType   Output Channel Type
 * \param[in]  Output   Action qualifier output type
 * \param[in]  Event   Event that causes a change in the output
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_SingleActionQualifierAction(uint32 Base, Cdd_Pwm_OutputChannelType ChannelType,
                                        Cdd_Pwm_ActionQualifierOutputType      Output,
                                        Cdd_Pwm_ActionQualifierOutputEventType Event);

/** \brief Configure the event trigger sources for the specified PWM interrupt
 *
 * This function configures the event trigger sources for the specified PWM interrupt
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  Event  Event type which trigger the interrupt
 * \param[in]  Mode     Enable/Disable
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ConfigureMixEvtTriggerSource(uint32 Base, uint16 Event, boolean Mode);

/** \brief Returns the action qualifier action for the channel
 *
 * This function returns the action qualifier action for the channel
 *
 * \param[in]  ChannelId   numeric ID of the PWM channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_PrivGetChannelActionQualifierAction(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId);

/** \brief Initialize duty cycle for the specified PWM channel with the specified duty cycle
 *
 * This function sets the specified duty cycle for the PWM channel
 *
 * \param[in]  ChannelId   numeric ID of the PWM channel
 * \param[in]  DutyCycle       Duty cycle for the PWM channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_PWM_CODE) Cdd_Pwm_InitDutyCycle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                                      VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle);

/** \brief Get the compare value of the channel
 *
 * This function calculates the compare value for the specified duty cycle for the channel
 *
 * \param[in]  ChannelId   numeric ID of the PWM channel
 * \param[in]  DutyCycle        Duty cycle of the PWM channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetCompareValue(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                                              VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle);

#endif

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)
/** \brief Clear trip-zone flag register
 *
 * This function clears trip-zone flag register
 *
 * \param[in]  InstanceId   numeric ID of the PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_PrivClearTripZoneFlagRegister(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);
#endif

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED) && (STD_OFF == CDD_PWM_ADVANCED_MODE_API)

/** \brief Update notification action for the channel
 *
 * This function updates notification actions for a PWM channel. It handles special cases
 * for asymmetric waveforms and shared interrupt sources between channels.
 * For asymmetric waveforms where both channels use the same zero event as interrupt source,
 * special handling is performed to avoid disabling the shared event.
 *
 * \param[in]  ChannelId        numeric ID of the PWM channel
 * \param[in]  NotificationMode indicates if notification was already enabled (TRUE) or not (FALSE)
 * \param[in]  Mode             Enable (TRUE) or disable (FALSE) notification
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_UpdateNotificationAction(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                     VAR(boolean, AUTOMATIC) NotificationMode, VAR(boolean, AUTOMATIC) Mode);

/** \brief Configure notification sources
 *
 * This function configures the notification sources
 *
 * \param[in]  ChannelId         numeric ID of the channel
 * \param[in]  EdgeNotification  Edge notification type
 * \param[in]  Mode              Enable/Disable notification
 * \pre None
 * \post None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_UpdateNotification(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                               VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification,
                               VAR(boolean, AUTOMATIC) Mode);

/** \brief Get event source for either rising edge or falling edge
 *
 * This function returns the event source for the rising edge or falling edge. This function doesn't
 *work for both edges notification option. In that case the function should be called separately for
 *rising and falling edge.
 *
 * \param[in]  ChannelId   numeric ID of the channel
 * \param[in]  EdgeNotification Edge Notification type of the channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Cdd_Pwm_EvtMixTriggerSourceType, CDD_PWM_CODE)
    Cdd_Pwm_PrivGetEventSource(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                               VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define CDD_PWM_START_SEC_CODE
#include "Cdd_Pwm_MemMap.h"

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)
LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_PrivClearTripZoneFlagRegister(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Clear Trip zone Event fag */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TZCLR) = ((uint16)CDD_PWM_TZFLAG_MAX);
}
#endif

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)
LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_SetCounterCompareValue(uint32 Base, Cdd_Pwm_OutputChannelType OutputChannel, uint16 CompareCount)
{
    /* Set the counter compare value */
    uint32 offset         = Base + EPWM_O_CMPA + ((uint32)OutputChannel * 4U);
    HWREGH(offset + 0x2U) = CompareCount;
}

LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_SetActionQualifierAction(uint32 Base, Cdd_Pwm_OutputChannelType ChannelType,
                                     Cdd_Pwm_ActionQualifierOutputType      Output,
                                     Cdd_Pwm_ActionQualifierOutputEventType Event)
{
    /* Set the AQ action for the channel */
    uint32 offset  = Base + EPWM_O_AQCTLA + ((uint32)ChannelType * 4U);
    HWREGH(offset) = ((HWREGH(offset) & ~(3U << (uint16)Event)) | ((uint16)Output << (uint16)Event));
}

LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_ClearActionQualifierAction(uint32 Base, Cdd_Pwm_OutputChannelType ChannelType)
{
    /* Set the AQ action for the channel */
    uint32 offset  = Base + EPWM_O_AQCTLA + ((uint32)ChannelType * 4U);
    HWREGH(offset) = ((uint16)0U);
}

LOCAL_INLINE FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_SingleActionQualifierAction(uint32 Base, Cdd_Pwm_OutputChannelType ChannelType,
                                        Cdd_Pwm_ActionQualifierOutputType      Output,
                                        Cdd_Pwm_ActionQualifierOutputEventType Event)
{
    /* Set the AQ action for the channel */
    uint32 offset  = Base + EPWM_O_AQCTLA + ((uint32)ChannelType * 4U);
    HWREGH(offset) = ((uint16)Output << (uint16)Event);
}

LOCAL_INLINE FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ConfigureMixEvtTriggerSource(uint32 Base, uint16 Event, boolean Mode)
{
    /* Configure the interrupt event sources */
    HWREGH(Base + EPWM_O_ETINTMIXEN) = (HWREGH(Base + EPWM_O_ETINTMIXEN) & ~(Event)) | (Event * Mode);
}

#if (STD_ON == CDD_PWM_DEINIT_API) && (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
LOCAL_INLINE FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearInterruptPrescale(uint32 Base)
{
    HWREGH(Base + EPWM_O_ETPS) = (uint16)0U;
}
#endif

#endif

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivSetTimeBasePeriod(VAR(uint32, AUTOMATIC) Base, VAR(uint16, AUTOMATIC) PeriodCount)
{
    /* Write to TBPRD bit */
    HWREGH(Base + EPWM_O_TBPRD) = PeriodCount;
}
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTimeBaseCounterMode(VAR(uint32, AUTOMATIC) Base,
                                   VAR(Cdd_Pwm_TimeBaseCountModeType, AUTOMATIC) CounterMode)
{
    /* Write to CTRMODE bit */
    HWREGH(Base + EPWM_O_TBCTL) = ((HWREGH(Base + EPWM_O_TBCTL) & ~(EPWM_TBCTL_CTRMODE_M)) | ((uint8)CounterMode));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierShadowLoadMode(uint32 Base, VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(Cdd_Pwm_ActionQualifierLoadModeType, AUTOMATIC) LoadMode)
{
    uint16 syncoffset   = 8U + ((uint16)OutputChannel * 2U);
    uint16 shadowoffset = 4U + ((uint16)OutputChannel * 2U);

    uint16 output_channel = ((uint16)OutputChannel * 2U);

    /* Set the appropriate sync and load Mode bits and also enable shadow load Mode.
     * Shadow to active load can also be frozen.
     */
    HWREGH(Base + EPWM_O_AQCTL) =
        (((HWREGH(Base + EPWM_O_AQCTL) & (~((0x3U << output_channel) | (0x3U << syncoffset)))) |
          (0x1U << shadowoffset)) |
         ((((uint16)LoadMode >> 2U) << syncoffset) | (((uint16)LoadMode & 0x3U) << output_channel)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetInterruptEventCount(VAR(uint32, AUTOMATIC) Base, VAR(uint16, AUTOMATIC) EventCount)
{
    /* Enable advanced feature of interrupt every up to 15 events */
    HWREGH(Base + EPWM_O_ETPS)    |= EPWM_ETPS_INTPSSEL;
    HWREGH(Base + EPWM_O_ETINTPS)  = ((HWREGH(Base + EPWM_O_ETINTPS) & ~EPWM_ETINTPS_INTPRD2_M) | EventCount);
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivConfigureInterrupt(VAR(uint32, AUTOMATIC) Base, VAR(boolean, AUTOMATIC) Select)
{
    /* Enable/Disable the interrupt */
    if (TRUE == Select)
    {
        HWREGH(Base + EPWM_O_ETSEL) |= EPWM_ETSEL_INTEN;
    }
    else
    {
        HWREGH(Base + EPWM_O_ETSEL) &= ~EPWM_ETSEL_INTEN;
    }

    // HWREGH(Base + EPWM_O_ETSEL) =
    //     (HWREGH(Base + EPWM_O_ETSEL) & (~EPWM_ETSEL_INTEN)) | ((uint16)Select * EPWM_ETSEL_INTEN);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetInterruptSource(uint32 Base, VAR(Cdd_Pwm_InterruptSourceType, AUTOMATIC) InterruptSource)
{
    uint16 interrupt_source;
    uint16 int_source = (uint16)InterruptSource;

#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT) && (STD_ON == CDD_PWM_ADVANCED_MODE_API)
    /* Report DET error if the input is not valid */
    if (!(((int_source > 0U) && (int_source < 9U)) || (int_source == 10U) || (int_source == 12U) ||
          (int_source == 14U)))
    {
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTSRC, CDD_PWM_E_UNINIT);
    }
#endif

    if ((InterruptSource == CDD_PWM_INT_TBCTR_U_CMPC) || (InterruptSource == CDD_PWM_INT_TBCTR_U_CMPD) ||
        (InterruptSource == CDD_PWM_INT_TBCTR_D_CMPC) || (InterruptSource == CDD_PWM_INT_TBCTR_D_CMPD))
    {
        /* Shift the interrupt source by 1 */
        interrupt_source = ((uint16)int_source) >> 1U;

        /* Enable events based on comp C or comp D */
        HWREGH(Base + EPWM_O_ETSEL) |= EPWM_ETSEL_INTSELCMP;
    }
    else if ((InterruptSource == CDD_PWM_INT_TBCTR_U_CMPA) || (InterruptSource == CDD_PWM_INT_TBCTR_U_CMPB) ||
             (InterruptSource == CDD_PWM_INT_TBCTR_D_CMPA) || (InterruptSource == CDD_PWM_INT_TBCTR_D_CMPB))
    {
        interrupt_source = (uint16)int_source;

        /* Enable events based on comp A or comp B */
        HWREGH(Base + EPWM_O_ETSEL) &= ~EPWM_ETSEL_INTSELCMP;
    }
    else
    {
        interrupt_source = (uint16)int_source;
    }

    /* Set the interrupt source */
    HWREGH(Base + EPWM_O_ETSEL) = ((HWREGH(Base + EPWM_O_ETSEL) & ~EPWM_ETSEL_INTSEL_M) | interrupt_source);
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivClearEventTriggerInterruptFlag(uint32 Base)
{
    /*  Clear INT bit of ETCLR register */
    HWREGH(Base + EPWM_O_ETCLR) = EPWM_ETCLR_INT;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetCounterCompareShadowLoadMode(uint32 Base, VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                                            VAR(Cdd_Pwm_CounterCompareLoadModeType, AUTOMATIC) LoadMode)
{
    uint16 syncoffset, loadoffset, shadowoffset;
    uint32 offset;

    if ((CompModule == CDD_PWM_COUNTER_COMPARE_A) || (CompModule == CDD_PWM_COUNTER_COMPARE_C))
    {
        syncoffset   = 10U;
        loadoffset   = 0U;
        shadowoffset = 4U;
    }
    else
    {
        syncoffset   = 12U;
        loadoffset   = 2U;
        shadowoffset = 6U;
    }

    /* Get the register offset.  EPWM_O_CMPCTL for A&B or EPWM_O_CMPCTL2 for C&D */
    offset = Base + EPWM_O_CMPCTL + (((uint8)CompModule & 0x1U) * 2U);

    /* Set the appropriate sync and load Mode bits and also enable shadow
    load Mode. Shadow to active load can also be frozen */
    HWREGH(offset) = ((HWREGH(offset) & ~((0x3U << syncoffset) |      // Clear sync Mode
                                          (0x3U << loadoffset) |      // Clear load Mode
                                          (0x1U << shadowoffset))) |  // shadow Mode
                      ((((uint16)LoadMode >> 2U) << syncoffset) | (((uint16)LoadMode & 0x3U) << loadoffset)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetClockPrescaler(uint32 Base, Cdd_Pwm_ClockDividerType Prescale,
                              Cdd_Pwm_HighSpeedClkDivType HighSpeedPrescaler)
{
    uint32 offset = Base + EPWM_O_TBCTL;
    /* Set the time Base clock divider and high speed clock divider for the PWM instance */
    HWREGH(offset) = ((HWREGH(offset) & ~(EPWM_TBCTL_CLKDIV_M | EPWM_TBCTL_HSPCLKDIV_M)) |
                      (((uint8)Prescale << (uint8)EPWM_TBCTL_CLKDIV_S) |
                       ((uint8)HighSpeedPrescaler << (uint8)EPWM_TBCTL_HSPCLKDIV_S)));
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivSetTimeBaseCounter(uint32 Base, uint16 Count)
{
    /* Write to TBCTR register */
    HWREGH(Base + EPWM_O_TBCTR) = Count;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetEmulationMode(VAR(uint32, AUTOMATIC) Base, VAR(Cdd_Pwm_EmulationModeType, AUTOMATIC) EmulationMode)
{
    /* Write to FREE_SOFT bits */
    HWREGH(Base + EPWM_O_TBCTL) =
        ((HWREGH(Base + EPWM_O_TBCTL) & (~EPWM_TBCTL_FREE_SOFT_M)) | ((uint16)EmulationMode << EPWM_TBCTL_FREE_SOFT_S));
}

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetDrvObj(Cdd_Pwm_DriverObjType *DrvObj, const Cdd_Pwm_ConfigType *CfgPtr)
{
    /* Set the global driver object pointer */
    Cdd_Pwm_DrvObjPtr = DrvObj;
    /* Initialize Ppb config array */
    Cdd_Pwm_ConfigPtr = CfgPtr;
}

/* Reset the driver object parameters */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DrvObjInit(void)
{
    for (Cdd_Pwm_InstanceType hwunit_id = 0U; hwunit_id < CDD_PWM_COUNT; hwunit_id++)
    {
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].notification_enable   = FALSE;
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].tripzone_notification = FALSE;
#endif
        /* Set the index of the PWM instance */
        Cdd_Pwm_DrvObjPtr->instanceindex[(Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].instance_id)] = hwunit_id;
    }
}

/* PWM driver initialization */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HwUnitInit(void)
{
    uint32 mask  = 0U;
    uint8  hw_id = 0U;

    if (CDD_PWM_XLINK_GRP_COUNT != 0U)
    {
        for (uint8 xlink_id = 0U; xlink_id < CDD_PWM_XLINK_GRP_COUNT; xlink_id++)
        {
            for (mask = Cdd_Pwm_ConfigPtr->xlink_hwmask[xlink_id]; mask > 0U; (mask = mask >> 1U))
            {
                /* mask has 1 set at bits whose xlink is enabled, hw_id determines which hwunit's xlink is enabled.
                 * hw_id is the same as the symoblic name ID of the instance in Cfg,h file */
                if ((mask & 1U) == 1U)
                {
                    /* Enable Xlink for the respective hardware unit */
                    Cdd_Pwm_PrivConfigureEpwmXLink(hw_id, TRUE);
                }
                hw_id++;
            }
        }
    }
}

#endif

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetDrvObj(Cdd_Pwm_DriverObjType *DrvObj, const Cdd_Pwm_ConfigType *CfgPtr)
{
    /* Set the global driver object pointer */
    Cdd_Pwm_DrvObjPtr = DrvObj;
    /* Initialize Ppb config array */
    Cdd_Pwm_ConfigPtr = CfgPtr;
}

/* Reset the driver object parameters */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DrvObjInit(void)
{
    uint32 base_addr;
    for (Cdd_Pwm_ChannelType channel_id = 0U; channel_id < CDD_PWM_CHANNEL_COUNT; channel_id++)
    {
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[(Cdd_Pwm_ConfigPtr->channelcfg[channel_id].hw_index)].base_addr;

        Cdd_Pwm_ClearActionQualifierAction(base_addr, Cdd_Pwm_ConfigPtr->channelcfg[channel_id].outputchannel);

        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].channel_active = FALSE;
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].dutycycle      = Cdd_Pwm_ConfigPtr->channelcfg[channel_id].dutycycle;

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        /* Set the notification enable to FALSE by default */
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].channelnotif_enable = (boolean)FALSE;

        /* Set the edge notification type */
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].edgenotifytype = CDD_PWM_EDGE_NONE;

        /* Set the rising and falling edge events for the channel */
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].rising_event =
            Cdd_Pwm_PrivGetEventSource(channel_id, CDD_PWM_RISING_EDGE);
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].falling_event =
            Cdd_Pwm_PrivGetEventSource(channel_id, CDD_PWM_FALLING_EDGE);
#endif
    }

    for (Cdd_Pwm_InstanceType hwunit_id = 0U; hwunit_id < CDD_PWM_COUNT; hwunit_id++)
    {
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].base_addr;

        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].period = Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].period;

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].zero_active         = (uint8)0U;
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].notification_enable = (uint8)0U;
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].inteventcount       = 0U;
#endif
        /* Set the index of the PWM instance */
        Cdd_Pwm_DrvObjPtr->instanceindex[(Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].instance_id)] = hwunit_id;
    }
}

/* PWM driver initialization */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HwUnitInit(void)
{
    /* Initialize each HW instance */
    Cdd_Pwm_ChannelType              channel_id;
    const Cdd_Pwm_ChannelCfgType    *channelcfg;
    const Cdd_Pwm_HwUnitCfgType     *hwunit_cfg;
    uint32                           base_addr;
    Cdd_Pwm_TimeBaseCountModeType    countmode;
    Cdd_Pwm_CounterCompareModuleType counter_compare;

    /* Iterate through each PWM HW Instances */
    for (Cdd_Pwm_InstanceType hwunit_id = 0U; hwunit_id < CDD_PWM_COUNT; hwunit_id++)
    {
        base_addr  = Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].base_addr;
        hwunit_cfg = &(Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id]);
        /* Time Base counter mode Based on the symmetry of the waveform */
        countmode = (CDD_PWM_ASYMMETRIC_WAVEFORM == hwunit_cfg->symmetry) ? (CDD_PWM_COUNTER_MODE_UP)
                                                                          : (CDD_PWM_COUNTER_MODE_UP_DOWN);

        /* Set emulation for the PWM instance */
        Cdd_Pwm_PrivSetEmulationMode(base_addr, hwunit_cfg->emulation_mode);
        /* Configure the clock divider */
        Cdd_Pwm_PrivSetClockPrescaler(base_addr, hwunit_cfg->clockdivider, hwunit_cfg->highspeed_clkdiv);
        /* Set time Base period value for the PWM instance */
        Cdd_Pwm_PrivSetTimeBasePeriod(base_addr, hwunit_cfg->period);
        /* Set the counter mode based on configured symmetry */
        Cdd_Pwm_PrivSetTimeBaseCounterMode(base_addr, countmode);
        /* Set the time Base initial count value */
        Cdd_Pwm_PrivSetTimeBaseCounter(base_addr, 0U);
        /* Clear zero & PRD match event as the interrupt trigger source since they are enabled by default after reset*/
        Cdd_Pwm_ConfigureMixEvtTriggerSource(
            base_addr, ((uint16)CDD_PWM_ETMIX_TBCTR_ZERO | (uint16)CDD_PWM_ETMIX_TBCTR_PERIOD), FALSE);
        /* Set the interrupt trigger source */
        Cdd_Pwm_PrivSetInterruptSource(base_addr, CDD_PWM_INT_TBCTR_ETINTMIX);
    }

    for (channel_id = 0U; channel_id < CDD_PWM_CHANNEL_COUNT; channel_id++)
    {
        channelcfg = &(Cdd_Pwm_ConfigPtr->channelcfg[channel_id]);
        base_addr  = Cdd_Pwm_ConfigPtr->hwunitcfg[channelcfg->hw_index].base_addr;
        counter_compare =
            (CDD_PWM_OUTPUT_A == channelcfg->outputchannel) ? (CDD_PWM_COUNTER_COMPARE_A) : (CDD_PWM_COUNTER_COMPARE_B);
        /* Set the compare counter shadow load mode */
        Cdd_Pwm_PrivSetCounterCompareShadowLoadMode(base_addr, counter_compare, CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
        /* Enable shadow mode for the AQ actions */
        Cdd_Pwm_PrivSetActionQualifierShadowLoadMode(base_addr, channelcfg->outputchannel,
                                                     CDD_PWM_AQ_LOAD_ON_CNTR_ZERO);
        /* Get the action qualifier action */
        Cdd_Pwm_PrivGetChannelActionQualifierAction(channel_id);
        /* Set the duty cycle and the compare values based on the specified duty cycle */
        Cdd_Pwm_InitDutyCycle(channel_id, channelcfg->dutycycle);
    }
}

#if (STD_ON == CDD_PWM_DEINIT_API)
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HwUnitDeinit(void)
{
    uint32 base_addr;
    uint8  hw_index;
    /* Set all the channels output to a IDLE state */
    for (Cdd_Pwm_ChannelType channel_id = 0U; channel_id < CDD_PWM_CHANNEL_COUNT; channel_id++)
    {
        hw_index  = Cdd_Pwm_ConfigPtr->channelcfg[channel_id].hw_index;
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;

        /* Set the output to IDLE if the channel is active */
        Cdd_Pwm_SetIdleOutput(channel_id);
        /* Reset the counter compare values to Zero */
        Cdd_Pwm_SetCounterCompareValue(base_addr, Cdd_Pwm_ConfigPtr->channelcfg[channel_id].outputchannel, (uint16)0U);

        /* Disable notification for the channel */
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].channelnotif_enable = FALSE;

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        /* De-initialize the rising & falling events */
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].rising_event  = CDD_PWM_ETMIX_TBCTR_NONE;
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].falling_event = CDD_PWM_ETMIX_TBCTR_NONE;
#endif
    }

    for (Cdd_Pwm_InstanceType instance = 0U; instance < CDD_PWM_COUNT; instance++)
    {
        /* Clear all the registers and bring them to the POR(Power-on-reset) state */
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[instance].base_addr;
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        /* Disable all interrupt */
        Cdd_Pwm_PrivConfigureInterrupt(base_addr, FALSE);
        /* Reset the interrupt event count */
        Cdd_Pwm_PrivSetInterruptEventCount(base_addr, 0U);
        /* Reset the interrupt pre-scale selectiont */
        Cdd_Pwm_ClearInterruptPrescale(base_addr);
        /* Reset the interrupt trigger sources */
        Cdd_Pwm_ConfigureMixEvtTriggerSource(
            base_addr, ((uint16)CDD_PWM_ETMIX_TBCTR_ZERO | (uint16)CDD_PWM_ETMIX_TBCTR_PERIOD), TRUE);
#endif
        /* Clear the interrupt flag */
        Cdd_Pwm_PrivClearEventTriggerInterruptFlag(base_addr);
    }
}
#endif

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_NotificationEnable(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) Channel,
                           VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification)
{
    uint8  hwunit_index = Cdd_Pwm_ConfigPtr->channelcfg[Channel].hw_index;
    uint32 base_addr    = Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_index].base_addr;

    /* Update the notification type */
    Cdd_Pwm_DrvObjPtr->channelobj[Channel].edgenotifytype = EdgeNotification;

    /* If notification is not already enabled for the instance through channels then configure the notification for
     * the hardware instance and channel
     */
    if (0U == Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_index].notification_enable)
    {
        /* Clear the interrupt flag */
        Cdd_Pwm_PrivClearEventTriggerInterruptFlag(Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_index].base_addr);

        /* Enable the interrupt */
        Cdd_Pwm_PrivConfigureInterrupt(base_addr, Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_index].enable_interrupt);
    }

    /* Notification is enabled when the waveforn has neither 0 percent duty cycle nor 100 percent duty cycle */
    if (TRUE == Cdd_Pwm_DrvObjPtr->channelobj[Channel].channel_active)
    {
        /* Enable notification only if the channel output waveform has edges */
        Cdd_Pwm_UpdateNotification(Channel, EdgeNotification, TRUE);
    }

    /* Set the notification enable to TRUE to enable notification if the duty cycle changes */
    Cdd_Pwm_DrvObjPtr->channelobj[Channel].channelnotif_enable = TRUE;
}

/* Disable notification for the channel */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_NotificationDisable(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) Channel)
{
    uint8 hwunit_index = Cdd_Pwm_ConfigPtr->channelcfg[Channel].hw_index;

    /* Check if notiifcation is already enabled for the instance, take action only if notification is already enabled */
    // if(Cdd_Pwm_DrvObjPtr->channelobj[Channel].channelnotif_enable == TRUE)
    // {

    if (TRUE == Cdd_Pwm_DrvObjPtr->channelobj[Channel].channel_active)
    {
        /* Disable notification if it is already enabled */
        Cdd_Pwm_UpdateNotificationAction(Channel, Cdd_Pwm_DrvObjPtr->channelobj[Channel].channelnotif_enable, FALSE);
    }

    /* This indicates which channel of the instance has notification enabled.
     * Clear the correspoding bit of the output channel
     */
    // Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_index].notification_enable &=
    //                                     ~(1U << ((uint8)Cdd_Pwm_ConfigPtr->channelcfg[Channel].outputchannel));

    if (0U == Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_index].notification_enable)
    {
        /* Disable the interrupt if no channel notification is enabled */
        Cdd_Pwm_PrivConfigureInterrupt(Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_index].base_addr, FALSE);
        /* Clear the interrupt flag */
        Cdd_Pwm_PrivClearEventTriggerInterruptFlag(Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_index].base_addr);
    }

    /* Update the notification type */
    Cdd_Pwm_DrvObjPtr->channelobj[Channel].edgenotifytype = CDD_PWM_EDGE_NONE;

    /* Update the notification enable status of the channel */
    Cdd_Pwm_DrvObjPtr->channelobj[Channel].channelnotif_enable = FALSE;

    // }
}
#endif

#if (CDD_PWM_SET_PERIOD_API == STD_ON)
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_UpdatePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_PeriodType, AUTOMATIC) Period)
{
    uint32 base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Update period of the PWM instance */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].period = Period;

    /* Set the time Base counter period */
    Cdd_Pwm_PrivSetTimeBasePeriod(base_addr, Period);

    /* Update the duty cycle of the respective channels */
    for (uint8 channelnumber = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].startchannel;
         ((channelnumber <= Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].lastchannel) &&
          (channelnumber < CDD_PWM_CHANNEL_COUNT));
         channelnumber++)
    {
        /* Update the duty cycle of the channel when the counter becomes Zero */
        Cdd_Pwm_UpdateDutyCycle(channelnumber, Cdd_Pwm_DrvObjPtr->channelobj[channelnumber].dutycycle);
    }
}
#endif

#if (CDD_PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (CDD_PWM_DEINIT_API == STD_ON)
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetIdleOutput(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId)
{
    const Cdd_Pwm_ChannelCfgType     *channel_cfg = &(Cdd_Pwm_ConfigPtr->channelcfg[ChannelId]);
    uint8                             hw_index    = channel_cfg->hw_index;
    uint32                            base_addr   = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;
    /* Set the AQ action Based on the channel IDLE state */
    Cdd_Pwm_ActionQualifierOutputType output =
        (channel_cfg->idlestate == CDD_PWM_HIGH) ? (CDD_PWM_AQ_OUTPUT_HIGH) : (CDD_PWM_AQ_OUTPUT_LOW);
    /* Set the AQ action to set the IDLE state */
    Cdd_Pwm_SingleActionQualifierAction(base_addr, channel_cfg->outputchannel, output,
                                        CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    if (TRUE == Cdd_Pwm_DrvObjPtr->channelobj[ChannelId].channel_active)
    {
        /* Disable the notification if the notification is already enabled for the channel */
        Cdd_Pwm_UpdateNotificationAction(ChannelId, Cdd_Pwm_DrvObjPtr->channelobj[ChannelId].channelnotif_enable,
                                         FALSE);
    }
#endif

    /* Set channel update state to FALSE */
    Cdd_Pwm_DrvObjPtr->channelobj[ChannelId].channel_active = FALSE;
}
#endif

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_UpdateDutyCycle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId, VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle)
{
    const Cdd_Pwm_ChannelCfgType     *channel_cfg = &(Cdd_Pwm_ConfigPtr->channelcfg[ChannelId]);
    Cdd_Pwm_ChannelObjType           *channelobj  = &(Cdd_Pwm_DrvObjPtr->channelobj[ChannelId]);
    Cdd_Pwm_InstanceType              hw_index    = channel_cfg->hw_index;
    uint32                            base_addr   = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;
    Cdd_Pwm_ActionQualifierOutputType output;

    uint16 compare_value = Cdd_Pwm_PrivGetCompareValue(ChannelId, DutyCycle);

    /* Set the duty cycle if the channel is active before this API call */
    if ((CDD_PWM_MAX_DUTY_CYCLE == DutyCycle) && (0U != Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period))
    {
        /* Get the AQ state based on the polarity of the PWM insance */
        output = (CDD_PWM_LOW == channel_cfg->polarity) ? (CDD_PWM_AQ_OUTPUT_LOW) : (CDD_PWM_AQ_OUTPUT_HIGH);

        if (channelobj->channel_active == TRUE)
        {
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            /* Disable notification if enabled previously */
            Cdd_Pwm_UpdateNotificationAction(ChannelId, channelobj->channelnotif_enable, FALSE);
#endif

            /* Update the channel output edge state -
             * If set to FALSE the output is FLAT,
             * else edges can be observed in the output
             */
            channelobj->channel_active = FALSE;
        }
        /* Set the AQ event to set the 100% duty cycle - This is effective when counter becomes equal to Zero */
        Cdd_Pwm_SingleActionQualifierAction(base_addr, channel_cfg->outputchannel, output,
                                            CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    }
    else if ((0U == DutyCycle) || (0U == Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period) || (0U == compare_value))
    {
        /* Get the AQ state based on the polarity of the PWM insance */
        output = (CDD_PWM_LOW == channel_cfg->polarity) ? (CDD_PWM_AQ_OUTPUT_HIGH) : (CDD_PWM_AQ_OUTPUT_LOW);

        if (channelobj->channel_active == TRUE)
        {
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            /* Disable notification if enabled previously */
            Cdd_Pwm_UpdateNotificationAction(ChannelId, channelobj->channelnotif_enable, FALSE);
#endif

            /* Update the channel output edge state -
             * If set to FALSE the output is FLAT,
             * else edges can be observed in the output
             */
            channelobj->channel_active = FALSE;
        }
        /* Set the AQ event to set the 0% duty cycle - This is effective when counter becomes equal to Zero */
        Cdd_Pwm_SingleActionQualifierAction(base_addr, channel_cfg->outputchannel, output,
                                            CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
    }
    else
    {
        /* If channel is already active with a certain dutycycle(neither 0% nor 100%) then AQ
         * settings need not to be configured again
         */
        if (FALSE == channelobj->channel_active)
        {
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            /* Update the action qualifier action */
            Cdd_Pwm_UpdateNotificationAction(ChannelId, channelobj->channelnotif_enable, TRUE);
#endif

            /* This setting is required for Symmetric waveform, when TBCTR = Zero then state should be configured
             * since the other two events are Compare Up & compare Down
             */
            Cdd_Pwm_SetActionQualifierAction(base_addr, channel_cfg->outputchannel, channelobj->level1,
                                             CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            /* Set the action qualifier action to get the desired duty cycle */
            Cdd_Pwm_SetActionQualifierAction(base_addr, channel_cfg->outputchannel, channelobj->level1,
                                             channelobj->outputevt2);
            Cdd_Pwm_SetActionQualifierAction(base_addr, channel_cfg->outputchannel, channelobj->level2,
                                             channelobj->outputevt1);
            /* Update the channel output edge state -
             * If set to FALSE the output is FLAT,
             * else edges can be observed in the output
             */
            channelobj->channel_active = TRUE;
        }
        /* Set output and duty cycle when the channel is in IDLE state before this API call */
        Cdd_Pwm_SetCounterCompareValue(base_addr, channel_cfg->outputchannel, compare_value);
    }

    /* Update duty cycle of the channel */
    channelobj->dutycycle = DutyCycle;
}

#endif

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ProcessIsr(Cdd_Pwm_InstanceType InstanceId)
{
    uint8 hw_index;

    /* Check if the PWM instance ID is within the valid range */
    if ((InstanceId <= CDD_PWM_INSTANCE_COUNT) && (InstanceId >= 1U))
    {
        /* Get the PWM hardware index */
        hw_index = Cdd_Pwm_DrvObjPtr->instanceindex[InstanceId];

        /* Check if the hardware index is within the valid range */
        if (hw_index < CDD_PWM_COUNT)
        {
            /* Clear the interrupt flag */
            Cdd_Pwm_PrivClearEventTriggerInterruptFlag(Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr);

/* Call the notification if enabled */
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            if (0U != Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_enable)
            {
                /* Call the notification function if notification is enabled for the instance */
                Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].notification();
            }
#endif
        }
    }
}

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

/* Trip zone interrupt service routine */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ProcessTripZoneIsr(Cdd_Pwm_InstanceType InstanceId)
{
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    uint16 tripzone_flag;
#endif

    uint8 hw_index;
    /* Check if the PWM instance ID is within the valid range */
    if ((InstanceId <= CDD_PWM_INSTANCE_COUNT) && (InstanceId >= 1U))
    {
        hw_index = Cdd_Pwm_DrvObjPtr->instanceindex[InstanceId];

        /* Check if the hardware index is within the valid range */
        if (hw_index < CDD_PWM_COUNT)
        {
            /* Get the trip zone interrupt flag */
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            tripzone_flag = Cdd_Pwm_PrivGetTripZoneFlagStatus(hw_index);
#endif

            /* Clear the interrupt flag */
            Cdd_Pwm_PrivClearTripZoneFlagRegister(hw_index);
            /* Call the notifications if enabled */
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            /* Trip zone notification is set to TRUE only if the notification is enabled for the instance,
             * else will be always to FALSE
             */
            if (TRUE == Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].tripzone_notification)
            {
                /* Call the notification function if notification is enabled for the channel */
                Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].tripzone_notification(tripzone_flag);
            }
#endif
        }
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetCountModeAfterSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, Cdd_Pwm_SyncCountModeType Mode)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (Mode == CDD_PWM_COUNT_MODE_UP_AFTER_SYNC)
    {
        /* Set PHSDIR bit */
        HWREGH(base + EPWM_O_TBCTL) |= EPWM_TBCTL_PHSDIR;
    }
    else
    {
        /* Clear PHSDIR bit */
        HWREGH(base + EPWM_O_TBCTL) &= ~EPWM_TBCTL_PHSDIR;
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceSyncPulse(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Set SwFSYNC bit */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TBCTL) |= EPWM_TBCTL_SWFSYNC;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetSyncInPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_SyncInPulseSourceType, AUTOMATIC) Source)
{
    uint32 base = (Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr);

    HWREGH(base + EPWM_O_SYNCINSEL) =
        (HWREGH(base + EPWM_O_SYNCINSEL) & ~((uint16)EPWM_SYNCINSEL_SEL_M)) | ((uint16)Source & EPWM_SYNCINSEL_SEL_M);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureSyncOutPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_SyncOutPulseSourceType, AUTOMATIC) Source,
                                        VAR(boolean, AUTOMATIC) Mode)
{
    /* Enable selected EPWM Sync-Out Sources. */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Mode)
    {
        HWREGH(base + EPWM_O_SYNCOUTEN) |= ((uint16)Source);
    }
    else
    {
        HWREGH(base + EPWM_O_SYNCOUTEN) &= ~((uint16)Source);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetOneShotSyncOutTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     Cdd_Pwm_OneShotSyncOutTriggerType Trigger)
{
    /* Set Source for One-Shot Sync-Out Pulse. */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TBCTL3) = (HWREGH(base + EPWM_O_TBCTL3) & ~((uint16)EPWM_TBCTL3_OSSFRCEN)) | (uint16)Trigger;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetPeriodLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_PeriodLoadModeType, AUTOMATIC) LoadMode)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (LoadMode == CDD_PWM_PERIOD_SHADOW_LOAD)
    {
        /* Clear PRDLD */
        HWREGH(base + EPWM_O_TBCTL) &= ~((uint16)EPWM_TBCTL_PRDLD);
    }
    else
    {
        /* Set PRDLD */
        HWREGH(base + EPWM_O_TBCTL) |= ((uint16)EPWM_TBCTL_PRDLD);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Mode)
{
    /* Set PHSEN bit */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Mode)
    {
        HWREGH(base + EPWM_O_TBCTL) |= ((uint16)EPWM_TBCTL_PHSEN);
    }
    else
    {
        HWREGH(base + EPWM_O_TBCTL) &= ~((uint16)EPWM_TBCTL_PHSEN);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectPeriodLoadEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_PeriodShadowLoadModeType, AUTOMATIC) ShadowLoadMode)
{
    /* Write to PRDLDSYNC bit */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TBCTL2) = ((HWREGH(base + EPWM_O_TBCTL2) & ~(EPWM_TBCTL2_PRDLDSYNC_M)) |
                                    ((uint16)ShadowLoadMode << EPWM_TBCTL2_PRDLDSYNC_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureOneShotSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Mode)
{
    /* Set OSHTSYNCMODE bit */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Mode)
    {
        HWREGH(base + EPWM_O_TBCTL2) |= ((uint16)EPWM_TBCTL2_OSHTSYNCMODE);
    }
    else
    {
        HWREGH(base + EPWM_O_TBCTL2) &= ~((uint16)EPWM_TBCTL2_OSHTSYNCMODE);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivStartOneShotSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Set OSHTSYNC bit */
    uint32 base                   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TBCTL2) |= ((uint16)EPWM_TBCTL2_OSHTSYNC);
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetTimeBaseCounterValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Returns TBCTR value */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_TBCTR));
}

FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetTimeBaseCounterOverflowStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return true if CTRMAX bit is set, false otherwise */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    boolean status = (boolean)((HWREGH(base + EPWM_O_TBSTS) & EPWM_TBSTS_CTRMAX) == EPWM_TBSTS_CTRMAX);
    return status;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivClearTimeBaseCounterOverflowEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Set CTRMAX bit */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TBSTS) = EPWM_TBSTS_CTRMAX;
}

FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_PrivGetSyncStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return true if SYNCI bit is set, false otherwise */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    boolean status = (boolean)((HWREGH(base + EPWM_O_TBSTS) & EPWM_TBSTS_SYNCI) == EPWM_TBSTS_SYNCI);
    return status;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivClearSyncEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Set SYNCI bit */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TBSTS) = EPWM_TBSTS_SYNCI;
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetTimeBaseCounterDirection(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return CTRDIR bit */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_TBSTS) & EPWM_TBSTS_CTRDIR);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) PhaseCount)
{
    /* Write to TBPHS bit */
    uint32 base                        = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TBPHS + 0x2U) = PhaseCount;
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Read from TBPRD bit */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_TBPRD));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableCounterCompareShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule)
{
    uint16 shadowoffset;
    uint32 offset, base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if ((CompModule == CDD_PWM_COUNTER_COMPARE_A) || (CompModule == CDD_PWM_COUNTER_COMPARE_C))
    {
        shadowoffset = 4U;
    }
    else
    {
        shadowoffset = 6U;
    }

    /* Get the register offset.  EPWM_O_CMPCTL for A&B or EPWM_O_CMPCTL2 for C&D */
    offset = base + EPWM_O_CMPCTL + (((uint8)CompModule & 0x1U) * 2U);

    /* Disable shadow load Mode */
    HWREGH(offset) |= ((uint16)0x1U << shadowoffset);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                                   VAR(uint16, AUTOMATIC) CompCount)
{
    /* Get the register offset for the Counter compare */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr + EPWM_O_CMPA + ((uint8)CompModule * 2U);

    /* Write to the Counter compare registers. */
    if ((CompModule == CDD_PWM_COUNTER_COMPARE_A) || (CompModule == CDD_PWM_COUNTER_COMPARE_B))
    {
        /* Write to COMPA or COMPB bits */
        HWREGH(base + 0x2U) = CompCount;
    }
    else
    {
        /* Write to COMPC or COMPD bits */
        HWREGH(base) = CompCount;
    }
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule)
{
    uint32 base;
    uint16 compare_count;

    /* Write to COMPC or COMPD bits */
    base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr + EPWM_O_CMPA + ((uint8)CompModule * 2U);

    /* Write to the Counter compare registers. */
    if ((CompModule == CDD_PWM_COUNTER_COMPARE_A) || (CompModule == CDD_PWM_COUNTER_COMPARE_B))
    {
        /* Write to COMPA or COMPB bits */
        compare_count = (uint16)((HWREG(base) & 0xFFFF0000UL) >> 16U);
    }
    else
    {
        compare_count = HWREGH(base);
    }
    return compare_count;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureEpwmXLink(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    uint8 hw_id = (Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].instance_id - 1U);

    if (TRUE == Select)
    {
        HWREG(DEVCFG_BASE + SYSCTL_O_EPWMXLINKCFG) |= (1U << hw_id);
    }
    else
    {
        HWREG(DEVCFG_BASE + SYSCTL_O_EPWMXLINKCFG) &= ~(1U << hw_id);
    }
}

FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetCounterCompareShadowStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    /* Read the value of SHDWAFULL or SHDWBFULL bit */
    uint32  base         = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint8   shift_val    = (uint8)(((uint8)OutputChannel & 0x1U) + 8U);
    boolean return_value = (boolean)(((HWREGH(base + EPWM_O_CMPCTL) >> shift_val) & (uint16)0x1U) == (uint16)0x1U);
    return return_value;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureLinkDutyHR(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Mode)
{
    /* Clear LINKDUTYHR bit in CMPCTL register */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Mode)
    {
        HWREGH(base + EPWM_O_CMPCTL) |= EPWM_CMPCTL_LINKDUTYHR;
    }
    else
    {
        HWREGH(base + EPWM_O_CMPCTL) &= ~EPWM_CMPCTL_LINKDUTYHR;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableActionQualifierShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint16 shadowoffset = 4U + (((uint16)OutputChannel) * 2U);

    /* Disable shadow load Mode. Action qualifier is loaded on immediate Mode only.*/
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_AQCTL) &= ~(1U << shadowoffset);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierT1TriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_ActionQualifierTriggerSourceType, AUTOMATIC) Trigger)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Set T1 Trigger Source */
    HWREGH(base + EPWM_O_AQTSRCSEL) =
        ((HWREGH(base + EPWM_O_AQTSRCSEL) & ~((uint16)EPWM_AQTSRCSEL_T1SEL_M)) | ((uint16)Trigger));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierT2TriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_ActionQualifierTriggerSourceType, AUTOMATIC) Trigger)
{
    /* Set T2 Trigger Source */
    uint32 base                     = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_AQTSRCSEL) = ((HWREGH(base + EPWM_O_AQTSRCSEL) & ~((uint16)EPWM_AQTSRCSEL_T2SEL_M)) |
                                       (uint16)((uint16)Trigger << EPWM_AQTSRCSEL_T2SEL_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) EpwmOutput,
                                     VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                     VAR(Cdd_Pwm_ActionQualifierOutputEventType, AUTOMATIC) Event)
{
    uint32 base, offset, register_offset;

    /* Get the register offset */
    offset          = EPWM_O_AQCTLA + ((uint32)EpwmOutput * 4U);
    register_offset = EPWM_O_AQCTLA2 + ((uint32)EpwmOutput * 4U);

    /* If the Event occurs on T1 or T2 events */
    if (((uint16)Event & 0x1U) == 1U)
    {
        /* Write to T1U,T1D,T2U or T2D of AQCTLA2 register */
        base                           = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
        HWREGH(base + register_offset) = ((HWREGH(base + register_offset) & ~(3U << ((uint16)Event - 1U))) |
                                          ((uint16)Output << ((uint16)Event - 1U)));
    }
    else
    {
        /* Write to ZRO,PRD,CAU,CAD,CBU or CBD bits of AQCTLA register */
        base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~(3U << (uint16)Event)) | ((uint16)Output << (uint16)Event));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(uint16, AUTOMATIC) Action)
{
    uint32 base, offset;
    /* Get the register offset */
    offset = EPWM_O_AQCTLA + ((uint32)(OutputChannel) * 4U);

    /* Write to ZRO, PRD, CAU, CAD, CBU or CBD bits of AQCTLA register */
    base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + offset) = (uint16)Action;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetAdditionalActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                       VAR(uint16, AUTOMATIC) Action)
{
    uint32 base, offset;

    /* Get the register offset */
    offset = EPWM_O_AQCTLA2 + ((uint32)(OutputChannel) * 4U);

    /* Write to ZRO, PRD, CAU, CAD, CBU or CBD bits of AQCTLA register */
    base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + offset) = (uint16)Action;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierContSwForceShadowMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_ActionQualifierContForceType, AUTOMATIC) Mode)
{
    /* Set the Action qualifier software Action reload Mode. Write to RLDCSF bit*/
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_AQSFRC) = ((HWREGH(base + EPWM_O_AQSFRC) & ~((uint16)EPWM_AQSFRC_RLDCSF_M)) |
                                    (uint16)((uint16)Mode << EPWM_AQSFRC_RLDCSF_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierContSwForceAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                VAR(Cdd_Pwm_ActionQualifierSwOutputType, AUTOMATIC) Output)

{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Initiate a continuous software Forced Output */
    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        HWREGH(base + EPWM_O_AQCSFRC) = ((HWREGH(base + EPWM_O_AQCSFRC) & ~EPWM_AQCSFRC_CSFA_M) | ((uint16)Output));
    }
    else
    {
        HWREGH(base + EPWM_O_AQCSFRC) =
            ((HWREGH(base + EPWM_O_AQCSFRC) & ~EPWM_AQCSFRC_CSFB_M) | ((uint16)Output << EPWM_AQCSFRC_CSFB_S));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                       VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Set the one time software Forced Action */
    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        HWREGH(base + EPWM_O_AQSFRC) = ((HWREGH(base + EPWM_O_AQSFRC) & ~EPWM_AQSFRC_ACTSFA_M) | ((uint16)Output));
    }
    else
    {
        HWREGH(base + EPWM_O_AQSFRC) =
            ((HWREGH(base + EPWM_O_AQSFRC) & ~EPWM_AQSFRC_ACTSFB_M) | ((uint16)Output << EPWM_AQSFRC_ACTSFB_S));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivForceActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        HWREGH(base + EPWM_O_AQSFRC) |= EPWM_AQSFRC_OTSFA;
    }
    else
    {
        HWREGH(base + EPWM_O_AQSFRC) |= EPWM_AQSFRC_OTSFB;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                      VAR(boolean, AUTOMATIC) EnableSwapMode)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint16 mask, output;
    output = (uint16)((CDD_PWM_OUTPUT_A == OutputChannel) ? (1U) : (0U));
    mask   = (uint16)((uint16)1U << (output + EPWM_DBCTL_OUTSWAP_S));

    if (TRUE == EnableSwapMode)
    {
        /* Set the appropriate outswap bit to swap Output */
        HWREGH(base + EPWM_O_DBCTL) = (HWREGH(base + EPWM_O_DBCTL) | mask);
    }
    else
    {
        /* Clear the appropriate outswap bit to disable Output swap */
        HWREGH(base + EPWM_O_DBCTL) = (HWREGH(base + EPWM_O_DBCTL) & ~mask);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandDelayMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                                 VAR(boolean, AUTOMATIC) EnableDelayMode)
{
    uint32 base;
    uint16 mask;
    base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    mask = ((uint16)1U << ((uint16)DelayMode + (uint16)EPWM_DBCTL_OUT_MODE_S));

    if (TRUE == EnableDelayMode)
    {
        /* Set the appropriate outMode bit to enable Dead Band Delay */
        HWREGH(base + EPWM_O_DBCTL) = (HWREGH(base + EPWM_O_DBCTL) | mask);
    }
    else
    {
        /* Clear the appropriate outswap bit to disable Output swap */
        HWREGH(base + EPWM_O_DBCTL) = (HWREGH(base + EPWM_O_DBCTL) & ~mask);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandDelayPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                                     VAR(Cdd_Pwm_DeadBandPolarityType, AUTOMATIC) Polarity)
{
    uint32 base  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint16 shift = (((uint16)DelayMode ^ 0x1U) + EPWM_DBCTL_POLSEL_S);

    /* Set the appropriate polsel bits for dead band Polarity */
    HWREGH(base + EPWM_O_DBCTL) = ((HWREGH(base + EPWM_O_DBCTL) & ~(1U << shift)) | ((uint16)Polarity << shift));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetRisingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint16 output_channel = ((uint16)OutputChannel);

    /* Set the Rising Edge Delay Input */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBCTL) =
        ((HWREGH(base + EPWM_O_DBCTL) & ~(1U << (EPWM_DBCTL_IN_MODE_S))) | (output_channel << EPWM_DBCTL_IN_MODE_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetFallingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DeadBandDelayInputType, AUTOMATIC) Input)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (Input == CDD_PWM_DB_INPUT_DB_RED)
    {
        /* Set the Falling Edge Delay Input */
        HWREGH(base + EPWM_O_DBCTL) |= EPWM_DBCTL_DEDB_MODE;
    }
    else
    {
        /* Set the Falling Edge Delay Input */
        HWREGH(base + EPWM_O_DBCTL) &= ~EPWM_DBCTL_DEDB_MODE;

        /* Set the Rising Edge Delay Input */
        HWREGH(base + EPWM_O_DBCTL) = ((HWREGH(base + EPWM_O_DBCTL) & ~(1U << (EPWM_DBCTL_IN_MODE_S + 1U))) |
                                       ((uint16)Input << (EPWM_DBCTL_IN_MODE_S + 1U)));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DeadBandControlLoadModeType, AUTOMATIC) LoadMode)
{
    /* Enable the shadow Mode and setup the load Event */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBCTL2) = ((HWREGH(base + EPWM_O_DBCTL2) & ~EPWM_DBCTL2_LOADDBCTLMODE_M) |
                                    (EPWM_DBCTL2_SHDWDBCTLMODE | (uint16)LoadMode));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Disable the shadow load Mode. Only immediate load Mode only. */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBCTL2) = (HWREGH(base + EPWM_O_DBCTL2) & ~EPWM_DBCTL2_SHDWDBCTLMODE);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(Cdd_Pwm_DeadBandDelayLoadModeType, AUTOMATIC) LoadMode)
{
    /* Enable the shadow Mode. Set-up the load Mode */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBCTL) = ((HWREGH(base + EPWM_O_DBCTL) & ~EPWM_DBCTL_LOADREDMODE_M) |
                                   ((uint16)EPWM_DBCTL_SHDWDBREDMODE | ((uint16)LoadMode << EPWM_DBCTL_LOADREDMODE_S)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Disable the shadow Mode. */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBCTL) = (HWREGH(base + EPWM_O_DBCTL) & ~EPWM_DBCTL_SHDWDBREDMODE);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_DeadBandDelayLoadModeType, AUTOMATIC) LoadMode)
{
    /* Enable the shadow Mode. Setup the load Mode. */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBCTL) = ((HWREGH(base + EPWM_O_DBCTL) & ~EPWM_DBCTL_LOADFEDMODE_M) |
                                   (EPWM_DBCTL_SHDWDBFEDMODE | ((uint16)LoadMode << EPWM_DBCTL_LOADFEDMODE_S)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivDisableFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Disable the shadow Mode. */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBCTL) = (HWREGH(base + EPWM_O_DBCTL) & ~EPWM_DBCTL_SHDWDBFEDMODE);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDeadBandCounterClock(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_DeadBandClockModeType, AUTOMATIC) ClockMode)
{
    /* Set the DB clock Mode */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBCTL) = ((HWREGH(base + EPWM_O_DBCTL) & ~EPWM_DBCTL_HALFCYCLE) | ((uint16)ClockMode << 15U));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetRisingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) RedCount)
{
    /* Set the RED (Rising Edge Delay) Count */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBRED) = RedCount;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetFallingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) FedCount)
{
    /* Set the RED (Rising Edge Delay) Count */
    uint32 base                 = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DBFED) = FedCount;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureChopper(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Mode)
{
    /* Set CHPEN bit. Enable Chopper */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Mode)
    {
        HWREGH(base + EPWM_O_PCCTL) |= EPWM_PCCTL_CHPEN;
    }
    else
    {
        HWREGH(base + EPWM_O_PCCTL) &= ~EPWM_PCCTL_CHPEN;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetChopperDutyCycle(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) DutyCycleCount)
{
    /* Set the chopper duty cycle */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_PCCTL) =
        ((HWREGH(base + EPWM_O_PCCTL) & ~EPWM_PCCTL_CHPDUTY_M) | (DutyCycleCount << EPWM_PCCTL_CHPDUTY_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetChopperFreq(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) FreqDiv)
{
    /* Set the chopper clock */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_PCCTL) =
        ((HWREGH(base + EPWM_O_PCCTL) & ~(uint16)EPWM_PCCTL_CHPFREQ_M) | (FreqDiv << EPWM_PCCTL_CHPFREQ_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetChopperFirstPulseWidth(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(uint16, AUTOMATIC) FirstPulseWidth)
{
    /* Set the chopper clock */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_PCCTL) =
        ((HWREGH(base + EPWM_O_PCCTL) & ~(uint16)EPWM_PCCTL_OSHTWTH_M) | (FirstPulseWidth << EPWM_PCCTL_OSHTWTH_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripZoneSignals(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzSignal,
                                     VAR(boolean, AUTOMATIC) Select)
{
    /* Set the trip zone bits */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_TZSEL) |= ((uint16)TzSignal);
    }
    else
    {
        HWREGH(base + EPWM_O_TZSEL) &= ~((uint16)TzSignal);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripZone2Signals(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzSignal,
                                      VAR(boolean, AUTOMATIC) Select)
{
    /* Set the trip zone bits */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_TZSEL2) |= ((uint16)TzSignal);
    }
    else
    {
        HWREGH(base + EPWM_O_TZSEL2) &= ~((uint16)TzSignal);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTripZoneDigitalCompareEventCondition(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType, AUTOMATIC) DcType,
                                                    VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType, AUTOMATIC)
                                                        DcEvent)
{
    uint16 dc_type = ((uint16)DcType * 3U);
    /* Set Digital Compare Events conditions that cause a Digital Compare trip */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TZDCSEL) =
        ((HWREGH(base + EPWM_O_TZDCSEL) & ~(0x7U << (uint16)dc_type)) | ((uint16)DcEvent << (uint16)dc_type));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    /* Enable Advanced feature. Set ETZE bit */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_TZCTL2) |= EPWM_TZCTL2_ETZE;
    }
    else
    {
        HWREGH(base + EPWM_O_TZCTL2) &= ~EPWM_TZCTL2_ETZE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTripZoneAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_TripZoneActionEventType, AUTOMATIC) TzEvent,
                              VAR(Cdd_Pwm_TripZoneActionType, AUTOMATIC) TzAction)
{
    /* Disable Advanced feature. clear ETZE bit */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    uint16 tzevent = (((uint16)TzEvent) * 2U);

    HWREGH(base + EPWM_O_TZCTL) = ((HWREGH(base + EPWM_O_TZCTL) & ~(0x3U << tzevent)) | ((uint16)TzAction << tzevent));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_TripZoneAdvancedEventType, AUTOMATIC) TzAdvEvent,
                                 VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvAction)
{
    /* Set the Advanced Action for Trip Zone events */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    uint16 tzadv_event = ((uint16)TzAdvEvent * 3U);

    HWREGH(base + EPWM_O_TZCTL2) =
        ((HWREGH(base + EPWM_O_TZCTL2) & ~(0x7U << tzadv_event)) | ((uint16)TzAdvAction << tzadv_event));

    HWREGH(base + EPWM_O_TZCTL2) |= EPWM_TZCTL2_ETZE;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetTripZoneAdvDigitalCompareAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                               VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType, AUTOMATIC) TzAdvDcEvent,
                                               VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvDcAction)
{
    /* Set the Advanced Action for Trip Zone events */
    uint32 base           = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint16 tzadv_dcevent  = ((uint16)TzAdvDcEvent * 3U);
    uint16 tripzoneaction = (CDD_PWM_OUTPUT_A == OutputChannel) ? (EPWM_O_TZCTLDCA) : (EPWM_O_TZCTLDCB);

    HWREGH(base + tripzoneaction) =
        ((HWREGH(base + tripzoneaction) & ~(0x7U << tzadv_dcevent)) | ((uint16)TzAdvDcAction << tzadv_dcevent));

    HWREGH(base + EPWM_O_TZCTL2) |= EPWM_TZCTL2_ETZE;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripZoneInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(uint16, AUTOMATIC) TzInterrupt, VAR(boolean, AUTOMATIC) Select)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        /* Enable Trip zone interrupts */
        HWREGH(base + EPWM_O_TZEINT) |= ((uint16)TzInterrupt);
    }
    else
    {
        /* Disable Trip zone interrupts */
        HWREGH(base + EPWM_O_TZEINT) &= ~((uint16)TzInterrupt);
    }
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_TZFLG) & 0xFFU);
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetCycleByCycleTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return the Cycle By Cycle Trip zone flag status */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_TZCBCFLG) & 0x1FFU);
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetOneShotTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return the One Shot Trip zone flag status */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_TZOSTFLG) & 0x1FFU);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectCycleByCycleTripZoneClearEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_CbcTripZoneClearModeType, AUTOMATIC) ClearEvent)
{
    /* Set the Cycle by Cycle Trip Latch Mode */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TZCLR) =
        ((HWREGH(base + EPWM_O_TZCLR) & ~EPWM_TZCLR_CBCPULSE_M) | ((uint16)ClearEvent << EPWM_TZCLR_CBCPULSE_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzFlags)
{
    /* Clear Trip zone Event fag */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TZCLR) |= ((uint16)TzFlags);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearCycleByCycleTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) TzCbcFlags)
{
    /* Clear the Cycle By Cycle Trip zone flag */
    uint32 base                     = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TZCBCCLR) |= (uint16)TzCbcFlags;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearOneShotTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzOstFlags)
{
    /* Clear the Cycle By Cycle Trip zone flag */
    uint32 base                     = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TZOSTCLR) |= ((uint16)TzOstFlags);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivForceTripZoneEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TzForceEvent)
{
    /* Force a Trip Zone Event */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_TZFRC) |= ((uint16)TzForceEvent);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureTripOutSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_SelectTripOutSourceType, AUTOMATIC) TzTripOut,
                                   VAR(boolean, AUTOMATIC) Select)
{
    /* Configures the TRIPOUT Source */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_TZTRIPOUTSEL) |= 1U << (uint32)TzTripOut;
    }
    else
    {
        HWREGH(base + EPWM_O_TZTRIPOUTSEL) &= ~(1U << (uint32)TzTripOut);
    }
}

FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_PrivGetEventTriggerInterruptStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return INT bit of ETFLG register */
    uint32  base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    boolean status = (boolean)(((HWREGH(base + EPWM_O_ETFLG) & 0x1U) == 0x1U));
    return status;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(boolean, AUTOMATIC) Select)
{
    /* Enable interrupt Event Count initializing/loading */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_ETCNTINITCTL) |= EPWM_ETCNTINITCTL_INTINITEN;
    }
    else
    {
        HWREGH(base + EPWM_O_ETCNTINITCTL) &= ~EPWM_ETCNTINITCTL_INTINITEN;
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Load the Interrupt Event Counter value */
    uint32 base                         = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_ETCNTINITCTL) |= EPWM_ETCNTINITCTL_INTINITFRC;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetInterruptEventCountInitValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(uint16, AUTOMATIC) EventCount)
{
    /* Set the Pre-interrupt Event Count */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_ETCNTINIT) =
        ((HWREGH(base + EPWM_O_ETCNTINIT) & ~EPWM_ETCNTINIT_INTINIT_M) | (uint16)(EventCount & 0xFU));
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetInterruptEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return the interrupt Event Count */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (((HWREGH(base + EPWM_O_ETINTPS) & EPWM_ETINTPS_INTCNT2_M) >> EPWM_ETINTPS_INTCNT2_S));
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceEventTriggerInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Set INT bit of ETFRC register */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_ETFRC) |= EPWM_ETFRC_INT;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetMixEvtTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_EtMixSignalSelectType, AUTOMATIC) EtMixSignal,
                                   VAR(Cdd_Pwm_EvtMixTriggerSourceType, AUTOMATIC) InterruptSource)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_ETINTMIXEN + ((uint32)EtMixSignal * 4U);

    /* Set the ETMIX Source */
    HWREGH(offset) |= (1U << (uint32)InterruptSource);
}

/*
 * Adc SOC configuration related APIs
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                VAR(boolean, AUTOMATIC) Select)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint16 adcsoc = (AdcSocType == CDD_PWM_SOC_A) ? (EPWM_ETSEL_SOCAEN) : (EPWM_ETSEL_SOCBEN);

    /* Enable/Disable an SOC */
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_ETSEL) |= adcsoc;
    }
    else
    {
        HWREGH(base + EPWM_O_ETSEL) &= ~adcsoc;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetAdcTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                VAR(Cdd_Pwm_AdcStartOfConversionSourceType, AUTOMATIC) SocSource)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint16 source;

    if ((SocSource == CDD_PWM_SOC_TBCTR_U_CMPC) || (SocSource == CDD_PWM_SOC_TBCTR_U_CMPD) ||
        (SocSource == CDD_PWM_SOC_TBCTR_D_CMPC) || (SocSource == CDD_PWM_SOC_TBCTR_D_CMPD))
    {
        source = ((uint16)SocSource >> 1U);
    }
    else
    {
        source = (uint16)SocSource;
    }

    if (AdcSocType == CDD_PWM_SOC_A)
    {
        /* Set the SOC Source */
        HWREGH(base + EPWM_O_ETSEL) =
            ((HWREGH(base + EPWM_O_ETSEL) & ~EPWM_ETSEL_SOCASEL_M) | (source << EPWM_ETSEL_SOCASEL_S));

        /* Enable the comparator selection */
        if ((SocSource == CDD_PWM_SOC_TBCTR_U_CMPA) || (SocSource == CDD_PWM_SOC_TBCTR_U_CMPB) ||
            (SocSource == CDD_PWM_SOC_TBCTR_D_CMPA) || (SocSource == CDD_PWM_SOC_TBCTR_D_CMPB))
        {
            /* Enable events based on comp A or comp B */
            HWREGH(base + EPWM_O_ETSEL) &= ~EPWM_ETSEL_SOCASELCMP;
        }
        else if ((SocSource == CDD_PWM_SOC_TBCTR_U_CMPC) || (SocSource == CDD_PWM_SOC_TBCTR_U_CMPD) ||
                 (SocSource == CDD_PWM_SOC_TBCTR_D_CMPC) || (SocSource == CDD_PWM_SOC_TBCTR_D_CMPD))
        {
            /* Enable events based on comp C or comp D */
            HWREGH(base + EPWM_O_ETSEL) |= EPWM_ETSEL_SOCASELCMP;
        }
        else
        {
            /* No Action required for the other SocSource options */
        }
    }
    else
    {
        /* Enable the comparator selection */
        HWREGH(base + EPWM_O_ETSEL) =
            ((HWREGH(base + EPWM_O_ETSEL) & ~EPWM_ETSEL_SOCBSEL_M) | (source << EPWM_ETSEL_SOCBSEL_S));

        /* Enable the comparator selection */
        if ((SocSource == CDD_PWM_SOC_TBCTR_U_CMPA) || (SocSource == CDD_PWM_SOC_TBCTR_U_CMPB) ||
            (SocSource == CDD_PWM_SOC_TBCTR_D_CMPA) || (SocSource == CDD_PWM_SOC_TBCTR_D_CMPB))
        {
            /* Enable events based on comp A or comp B */
            HWREGH(base + EPWM_O_ETSEL) &= ~EPWM_ETSEL_SOCBSELCMP;
        }
        else if ((SocSource == CDD_PWM_SOC_TBCTR_U_CMPC) || (SocSource == CDD_PWM_SOC_TBCTR_U_CMPD) ||
                 (SocSource == CDD_PWM_SOC_TBCTR_D_CMPC) || (SocSource == CDD_PWM_SOC_TBCTR_D_CMPD))
        {
            /* Enable events based on comp C or comp D */
            HWREGH(base + EPWM_O_ETSEL) |= EPWM_ETSEL_SOCBSELCMP;
        }
        else
        {
            /* No Action required for the other SocSource options */
        }
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetAdcTriggerEventPrescale(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                       uint16 PreScaleCount)
{
    /* Enable advanced feature of SOC every up to 15 events */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    HWREGH(base + EPWM_O_ETPS) |= EPWM_ETPS_SOCPSSEL;
    if (AdcSocType == CDD_PWM_SOC_A)
    {
        /* Set the Count for SOC A */
        HWREGH(base + EPWM_O_ETSOCPS) = ((HWREGH(base + EPWM_O_ETSOCPS) & ~EPWM_ETSOCPS_SOCAPRD2_M) | PreScaleCount);
    }
    else
    {
        /* Set the Count for SOC B */
        HWREGH(base + EPWM_O_ETSOCPS) =
            ((HWREGH(base + EPWM_O_ETSOCPS) & ~EPWM_ETSOCPS_SOCBPRD2_M) | (PreScaleCount << EPWM_ETSOCPS_SOCBPRD2_S));
    }
}

FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetAdcTriggerFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
    /* Return the SOC A/ B status */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    boolean status = (boolean)(((HWREGH(base + EPWM_O_ETFLG) >> ((uint16)AdcSocType + 2U)) & 0x1U) == 0x1U);
    return status;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearAdcTriggerFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
    /* Clear SOC A/B bit of ETCLR register */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_ETCLR) |= (1U << ((uint16)AdcSocType + 2U));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                              VAR(boolean, AUTOMATIC) Select)
{
    /* Enable SOC Event Count initializing/loading */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_ETCNTINITCTL) |= 1U << ((uint16)AdcSocType + 14U);
    }
    else
    {
        HWREGH(base + EPWM_O_ETCNTINITCTL) &= ~(1U << ((uint16)AdcSocType + 14U));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivForceAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
    /* Load the Interrupt Event Counter value */
    uint32 base                         = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_ETCNTINITCTL) |= 1U << ((uint16)AdcSocType + 11U);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetAdcTriggerEventCountInitValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                             uint16 EventCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Set the Adc Trigger Event Count */
    if (AdcSocType == CDD_PWM_SOC_A)
    {
        HWREGH(base + EPWM_O_ETCNTINIT) = ((HWREGH(base + EPWM_O_ETCNTINIT) & ~EPWM_ETCNTINIT_SOCAINIT_M) |
                                           (uint16)(EventCount << EPWM_ETCNTINIT_SOCAINIT_S));
    }
    else
    {
        HWREGH(base + EPWM_O_ETCNTINIT) = ((HWREGH(base + EPWM_O_ETCNTINIT) & ~EPWM_ETCNTINIT_SOCBINIT_M) |
                                           (EventCount << EPWM_ETCNTINIT_SOCBINIT_S));
    }
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetAdcTriggerEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
    uint16 eventCount;
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Return the SOC Event Count */
    if (AdcSocType == CDD_PWM_SOC_A)
    {
        eventCount = (HWREGH(base + EPWM_O_ETSOCPS) >> EPWM_ETSOCPS_SOCACNT2_S) & 0xFU;
    }
    else
    {
        eventCount = (HWREGH(base + EPWM_O_ETSOCPS) >> EPWM_ETSOCPS_SOCBCNT2_S) & 0xFU;
    }

    return eventCount;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivForceAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
    /* Set SOC A/B bit of ETFRC register */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_ETFRC) |= 1U << ((uint16)AdcSocType + 2U);
}

/*
 * Digital Compare module related APIs
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectDigitalCompareTripInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) TripInput,
                                          VAR(Cdd_Pwm_DigitalCompareType, AUTOMATIC) DcType)
{
    /* Set SOC A/B bit of ETFRC register */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    HWREGH(base + EPWM_O_DCTRIPSEL) = ((HWREGH(base + EPWM_O_DCTRIPSEL) & ~(0xFU << ((uint16)DcType << 2U))) |
                                       ((uint16)TripInput << ((uint16)DcType << 2U)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareBlankingWindow(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(boolean, AUTOMATIC) Select)
{
    /* Enable DC filter blanking window */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_DCFCTL) |= EPWM_DCFCTL_BLANKE;
    }
    else
    {
        HWREGH(base + EPWM_O_DCFCTL) &= ~EPWM_DCFCTL_BLANKE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareWindowInverseMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                     VAR(boolean, AUTOMATIC) Select)
{
    /* Enable DC window inverse Mode. */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_DCFCTL) |= EPWM_DCFCTL_BLANKINV;
    }
    else
    {
        HWREGH(base + EPWM_O_DCFCTL) &= ~EPWM_DCFCTL_BLANKINV;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareBlankingEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_DigitalCompareBlankingPulseType, AUTOMATIC) BlankingPulse)
{
    /* Set DC blanking Event */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DCFCTL) = ((HWREGH(base + EPWM_O_DCFCTL) & ~EPWM_DCFCTL_PULSESEL_M) |
                                    ((uint16)((uint32)BlankingPulse << EPWM_DCFCTL_PULSESEL_S)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareFilterInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DigitalCompareFilterInputType, AUTOMATIC) FilterInput)
{
    /* Set the signal Source that will be filtered */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DCFCTL) = ((HWREGH(base + EPWM_O_DCFCTL) & ~EPWM_DCFCTL_SRCSEL_M) | ((uint16)FilterInput));
}

/*
 * DC Edge Filter
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareEdgeFilter(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(boolean, AUTOMATIC) Select)
{
    /*  Enable DC Edge Filter */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_DCFCTL) |= EPWM_DCFCTL_EDGEFILTSEL;
    }
    else
    {
        HWREGH(base + EPWM_O_DCFCTL) &= ~EPWM_DCFCTL_EDGEFILTSEL;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareEdgeFilterMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_DigitalCompareEdgeFilterModeType, AUTOMATIC) EdgeMode)
{
    /* Set DC Edge filter Mode */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DCFCTL) =
        (HWREGH(base + EPWM_O_DCFCTL) & ~EPWM_DCFCTL_EDGEMODE_M) | ((uint16)EdgeMode << EPWM_DCFCTL_EDGEMODE_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(uint16, AUTOMATIC) EdgeCount)
{
    /* Set DC Edge filter Edge Count */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DCFCTL) =
        (HWREGH(base + EPWM_O_DCFCTL) & ~EPWM_DCFCTL_EDGECOUNT_M) | (EdgeCount << EPWM_DCFCTL_EDGECOUNT_S);
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return configured DC Edge filter Edge Count */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return ((HWREGH(base + EPWM_O_DCFCTL) & EPWM_DCFCTL_EDGECOUNT_M) >> EPWM_DCFCTL_EDGECOUNT_S);
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareEdgeFilterEdgeStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return captured Edge Count by DC Edge filter */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return ((HWREGH(base + EPWM_O_DCFCTL) & EPWM_DCFCTL_EDGESTATUS_M) >> EPWM_DCFCTL_EDGESTATUS_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareWindowOffset(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) WindowOffsetCount)
{
    /* Set the blanking window offset in TBCLK Counts */
    uint32 base                     = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DCFOFFSET) = WindowOffsetCount;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareWindowLength(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) WindowLengthCount)
{
    /* Set the blanking window length in TBCLK Counts */
    uint32 base                     = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DCFWINDOW) = WindowLengthCount;
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareBlankingWindowOffsetCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return the Blanking Window Offset Count */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_DCFOFFSETCNT));
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareBlankingWindowLengthCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return the Blanking Window Length Count */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_DCFWINDOWCNT));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareEventSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                         VAR(Cdd_Pwm_DigitalCompareEventSourceType, AUTOMATIC) DcEventSource)
{
    uint32 offset = EPWM_O_DCACTL + ((uint32)OutputChannel * 2U);

    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Set the DC Event 1 Source Source */
    if (DcEvent == CDD_PWM_DC_EVENT_1)
    {
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~EPWM_DCACTL_EVT1SRCSEL) | (uint16)DcEventSource);
    }
    else
    {
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~EPWM_DCACTL_EVT2SRCSEL) | ((uint16)DcEventSource << 8U));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareEventSyncMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                           VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                           VAR(Cdd_Pwm_DigitalCompareSyncModeType, AUTOMATIC) SyncMode)
{
    uint32 offset = EPWM_O_DCACTL + ((uint32)OutputChannel * 2U);
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /*Set the DC Event sync Mode */
    if (DcEvent == CDD_PWM_DC_EVENT_1)
    {
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~EPWM_DCACTL_EVT1FRCSYNCSEL) | ((uint16)SyncMode << 1U));
    }
    else
    {
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~EPWM_DCACTL_EVT2FRCSYNCSEL) | ((uint16)SyncMode << 9U));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                              VAR(boolean, AUTOMATIC) Select)
{
    uint32 offset = EPWM_O_DCACTL + ((uint32)OutputChannel * 2U);

    /* Enable Digital Compare start of conversion generation */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + offset) = (HWREGH(base + offset) | EPWM_DCACTL_EVT1SOCE);
    }
    else
    {
        HWREGH(base + offset) = (HWREGH(base + offset) & ~EPWM_DCACTL_EVT1SOCE);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareSyncEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(boolean, AUTOMATIC) Select)
{
    uint32 offset = EPWM_O_DCACTL + ((uint32)OutputChannel * 2U);

    /* Enable Digital Compare sync out pulse generation */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + offset) = (HWREGH(base + offset) | EPWM_DCACTL_EVT1SYNCE);
    }
    else
    {
        HWREGH(base + offset) = (HWREGH(base + offset) & ~EPWM_DCACTL_EVT1SYNCE);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareCBCLatchMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                          VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                          VAR(Cdd_Pwm_DigitalCompareCbcLatchModeType, AUTOMATIC) LatchMode)
{
    uint32 offset = EPWM_O_DCACTL + ((uint32)OutputChannel * 2U);
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Set the DC CBC Latch Mode */
    if (DcEvent == CDD_PWM_DC_EVENT_1)
    {
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~EPWM_DCACTL_EVT1LATSEL) | ((uint16)LatchMode << 4U));
    }
    else
    {
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~EPWM_DCACTL_EVT2LATSEL) | ((uint16)LatchMode << 12U));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectDigitalCompareCBCLatchClearEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                   VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                                   VAR(Cdd_Pwm_DigitalCompareCBCLatchClearEventType, AUTOMATIC)
                                                       ClearEvent)
{
    uint32 offset = EPWM_O_DCACTL + ((uint32)OutputChannel * 2U);
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Set the DC CBC Latch Clear Event */
    if (DcEvent == CDD_PWM_DC_EVENT_1)
    {
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~EPWM_DCACTL_EVT1LATCLRSEL_M) |
                                 ((uint16)ClearEvent << EPWM_DCACTL_EVT1LATCLRSEL_S));
    }
    else
    {
        HWREGH(base + offset) = ((HWREGH(base + offset) & ~EPWM_DCACTL_EVT2LATCLRSEL_M) |
                                 ((uint16)ClearEvent << EPWM_DCACTL_EVT2LATCLRSEL_S));
    }
}

FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetDigitalCompareCBCLatchStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                            VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent)
{
    uint32  base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr + EPWM_O_DCACTL + ((uint8)OutputChannel * 2U);
    uint16  status;
    boolean return_value;

    /* Get DC CBC Latch Clear Event */
    if (DcEvent == CDD_PWM_DC_EVENT_1)
    {
        status = HWREGH(base) & EPWM_DCACTL_EVT1LAT;
    }
    else
    {
        status = HWREGH(base) & EPWM_DCACTL_EVT2LAT;
    }

    return_value = (boolean)(status != 0U);
    return return_value;
}

/*
 * DC capture Mode
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareCounterCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(boolean, AUTOMATIC) Select)
{
    /* Enable Time base Counter capture */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_DCCAPCTL) |= EPWM_DCCAPCTL_CAPE;
    }
    else
    {
        HWREGH(base + EPWM_O_DCCAPCTL) &= ~EPWM_DCCAPCTL_CAPE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDigitalCompareCounterShadowMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(boolean, AUTOMATIC) EnableShadowMode)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == EnableShadowMode)
    {
        /* Enable DC Counter shadow Mode */
        HWREGH(base + EPWM_O_DCCAPCTL) &= ~EPWM_DCCAPCTL_SHDWMODE;
    }
    else
    {
        /* Disable DC Counter shadow Mode */
        HWREGH(base + EPWM_O_DCCAPCTL) |= EPWM_DCCAPCTL_SHDWMODE;
    }
}

FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_PrivGetDigitalCompareCaptureStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32  base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Return the DC compare status */
    boolean status = (boolean)((HWREGH(base + EPWM_O_DCCAPCTL) & EPWM_DCCAPCTL_CAPSTS) == EPWM_DCCAPCTL_CAPSTS);
    return status;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareCounterCaptureMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                      VAR(boolean, AUTOMATIC) DisableClearMode)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == DisableClearMode)
    {
        /* Disable DC Counter auto-clear on PULSESEL Event */
        HWREGH(base + EPWM_O_DCCAPCTL) |= EPWM_DCCAPCTL_CAPMODE;
    }
    else
    {
        /* Enable DC Counter clear on PULSESEL events */
        HWREGH(base + EPWM_O_DCCAPCTL) &= ~EPWM_DCCAPCTL_CAPMODE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivClearDigitalCompareCaptureStatusFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Clear digital compare capture status flag */
    uint32 base                     = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_DCCAPCTL) |= EPWM_DCCAPCTL_CAPCLR;
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetDigitalCompareCaptureCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return the DC Time Base Counter Capture Count value */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_DCCAP));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDigitalCompareTripCombinationInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                        VAR(uint16, AUTOMATIC) TripInput,
                                                        VAR(Cdd_Pwm_DigitalCompareType, AUTOMATIC) DcType,
                                                        VAR(boolean, AUTOMATIC) Select)
{
    /* Get the DCAHTRIPSEL, DCALTRIPSEL, DCBHTRIPSEL, DCBLTRIPSEL register */
    uint32 offset = EPWM_O_DCAHTRIPSEL + ((uint32)DcType * 2U);
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        /* Set the DC trip Input */
        HWREGH(base + offset) = (HWREGH(base + offset) | ((uint16)TripInput));

        /* Enable the combination Input */
        HWREGH(base + EPWM_O_DCTRIPSEL) =
            (HWREGH(base + EPWM_O_DCTRIPSEL) | (0xFU << ((uint16)DcType << 2U)));  // gives 0,4,8 and 12
    }
    else
    {
        HWREGH(base + offset) = (HWREGH(base + offset) & ~((uint16)TripInput));
    }
}

/*
 * Event capture Mode
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureCaptureInEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    /* Enables CAPIN.sync signal */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_CAPCTL) |= EPWM_CAPCTL_SRCSEL;
    }
    else
    {
        HWREGH(base + EPWM_O_CAPCTL) &= ~EPWM_CAPCTL_SRCSEL;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigCaptureGateInputPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_SelectCaptureGateInputPolarityType, AUTOMATIC) PolaritySelect)
{
    /* Configures Polarity for CAPGATE */
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_CAPCTL) = ((HWREGH(base + EPWM_O_CAPCTL) & ~EPWM_CAPCTL_CAPGATEPOL_M) |
                                    ((uint32)PolaritySelect << EPWM_CAPCTL_CAPGATEPOL_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivInvertCaptureInputPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_SelectCaptureInputPolarityType, AUTOMATIC) PolaritySelect)
{
    /* Configures Polarity for Capture Input */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_CAPCTL) =
        ((HWREGH(base + EPWM_O_CAPCTL) & ~EPWM_CAPCTL_CAPINPOL) | ((uint32)PolaritySelect << 3U));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureIndependentPulseLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(boolean, AUTOMATIC) Select)
{
    /* Configures Polarity for Capture Input */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_CAPCTL) |= EPWM_CAPCTL_PULSECTL;
    }
    else
    {
        HWREGH(base + EPWM_O_CAPCTL) &= ~EPWM_CAPCTL_PULSECTL;
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceCaptureEventLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Force a Capture Event Load */
    uint32 base                   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_CAPCTL) |= EPWM_CAPCTL_FRCLOAD;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectCaptureTripInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TripInput,
                                   VAR(Cdd_Pwm_CaptureInputType, AUTOMATIC) DcType)
{
    /* Set the Capture trip Input */
    uint32 base                      = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_CAPTRIPSEL) = ((HWREGH(base + EPWM_O_CAPTRIPSEL) & ~(0xFU << ((uint16)DcType << 2U))) |
                                        ((uint16)TripInput << ((uint16)DcType << 2U)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureCaptureTripCombinationInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(uint16, AUTOMATIC) TripInput,
                                                 VAR(Cdd_Pwm_CaptureInputType, AUTOMATIC) DcType,
                                                 VAR(boolean, AUTOMATIC) Select)
{
    uint32 offset = EPWM_O_CAPGATETRIPSEL + ((1U - (uint32)DcType) * 2U);

    /* Set the capture trip Input */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + offset) = (HWREGH(base + offset) | ((uint16)TripInput));
        /* Enable the combination Input */
        HWREGH(base + EPWM_O_CAPTRIPSEL) = (HWREGH(base + EPWM_O_CAPTRIPSEL) | (0xFU << ((uint16)DcType << 2U)));
    }
    else
    {
        /* Set the capture trip Input */
        HWREGH(base + offset) = (HWREGH(base + offset) & ~((uint16)TripInput));
    }
}

/*
 * Valley switching
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureValleyCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        /* Set VCAPE bit */
        HWREGH(base + EPWM_O_VCAPCTL) |= EPWM_VCAPCTL_VCAPE;
    }
    else
    {
        /* Clear VCAPE bit */
        HWREGH(base + EPWM_O_VCAPCTL) &= ~EPWM_VCAPCTL_VCAPE;
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivStartValleyCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /*  Set VCAPSTART bit */
    HWREGH(base + EPWM_O_VCAPCTL) |= EPWM_VCAPCTL_VCAPSTART;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetValleyTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_ValleyTriggerSourceType, AUTOMATIC) Trigger)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to TRIGSEL bits */
    HWREGH(base + EPWM_O_VCAPCTL) =
        ((HWREGH(base + EPWM_O_VCAPCTL) & ~EPWM_VCAPCTL_TRIGSEL_M) | ((uint16)Trigger << 2U));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetValleyTriggerEdgeCounts(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(uint16, AUTOMATIC) StartCount, VAR(uint16, AUTOMATIC) StopCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to STARTEDGE and STOPEDGE bits */
    HWREGH(base + EPWM_O_VCNTCFG) =
        ((HWREGH(base + EPWM_O_VCNTCFG) & ~(EPWM_VCNTCFG_STARTEDGE_M | EPWM_VCNTCFG_STOPEDGE_M)) |
         (StartCount | (StopCount << 8U)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureValleyHwDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        /* Set EDGEFILTDLYSEL bit */
        HWREGH(base + EPWM_O_VCAPCTL) |= EPWM_VCAPCTL_EDGEFILTDLYSEL;
    }
    else
    {
        /* Clear EDGEFILTDLYSEL bit */
        HWREGH(base + EPWM_O_VCAPCTL) &= ~EPWM_VCAPCTL_EDGEFILTDLYSEL;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetValleySwDelayValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(uint16, AUTOMATIC) DelayOffsetValue)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to SwVDELVAL bits */
    HWREGH(base + EPWM_O_SWVDELVAL) = DelayOffsetValue;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetValleyDelayDivider(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_ValleyDelayModeType, AUTOMATIC) DelayMode)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to VDELAYDIV bits */
    HWREGH(base + EPWM_O_VCAPCTL) =
        ((HWREGH(base + EPWM_O_VCAPCTL) & ~EPWM_VCAPCTL_VDELAYDIV_M) | ((uint16)DelayMode << 7U));
}

FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_PrivGetValleyEdgeStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_ValleyCounterEdgeType, AUTOMATIC) Edge)
{
    uint32  base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    boolean return_value;
    if (Edge == CDD_PWM_VALLEY_COUNT_START_EDGE)
    {
        /* Returns STARTEDGESTS status */
        return_value =
            (boolean)(((HWREGH(base + EPWM_O_VCNTCFG) & EPWM_VCNTCFG_STARTEDGESTS) == EPWM_VCNTCFG_STARTEDGESTS));
    }
    else
    {
        /* Returns STOPEDGESTS status */
        return_value =
            (boolean)(((HWREGH(base + EPWM_O_VCNTCFG) & EPWM_VCNTCFG_STOPEDGESTS) == EPWM_VCNTCFG_STOPEDGESTS));
    }
    return return_value;
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetValleyCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Read VCNTVAL register */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_VCNTVAL));
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetValleyHwDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Read HWVDELVAL  register */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return (HWREGH(base + EPWM_O_HWVDELVAL));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureGlobalLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    /* Shadow to active load is controlled globally */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_GLDCTL) |= EPWM_GLDCTL_GLD;
    }
    else
    {
        HWREGH(base + EPWM_O_GLDCTL) &= ~EPWM_GLDCTL_GLD;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetGlobalLoadTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_GlobalLoadTriggerType, AUTOMATIC) LoadTrigger)
{
    /* Set the Global shadow to active load pulse */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_GLDCTL) =
        ((HWREGH(base + EPWM_O_GLDCTL) & ~EPWM_GLDCTL_GLDMODE_M) | ((uint16)LoadTrigger << EPWM_GLDCTL_GLDMODE_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetGlobalLoadEventPrescale(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(uint16, AUTOMATIC) PrescalePulseCount)
{
    /* Set the number of Counts that have to occur before a load strobe is issued */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_GLDCTL) =
        ((HWREGH(base + EPWM_O_GLDCTL) & ~EPWM_GLDCTL_GLDPRD_M) | (PrescalePulseCount << EPWM_GLDCTL_GLDPRD_S));
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetGlobalLoadEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Return the number of events that have occurred */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    return ((HWREGH(base + EPWM_O_GLDCTL) >> EPWM_GLDCTL_GLDCNT_S) & 0x7U);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureGlobalLoadOneShotMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(boolean, AUTOMATIC) Select)
{
    /* Enable global continuous shadow to active load */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_GLDCTL) |= EPWM_GLDCTL_OSHTMODE;
    }
    else
    {
        HWREGH(base + EPWM_O_GLDCTL) &= ~EPWM_GLDCTL_OSHTMODE;
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivSetGlobalLoadOneShotLatch(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Set a one shot Global shadow load pulse. */
    uint32 base                    = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_GLDCTL2) |= EPWM_GLDCTL2_OSHTLD;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceGlobalLoadOneShotEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    /* Force a Software Global shadow load pulse */
    uint32 base                    = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    HWREGH(base + EPWM_O_GLDCTL2) |= EPWM_GLDCTL2_GFRCLD;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureGlobalLoadRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(uint16, AUTOMATIC) LoadRegister, VAR(boolean, AUTOMATIC) Select)
{
    /* The register specified by LoadRegister is loaded globally */
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    if (TRUE == Select)
    {
        HWREGH(base + EPWM_O_GLDCFG) |= (LoadRegister);
    }
    else
    {
        HWREGH(base + EPWM_O_GLDCFG) &= ~(LoadRegister);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivLockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_LockRegisterGroupType, AUTOMATIC) RegisterGroup)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write the Key to EPWMLOCK register */
    HWREG(base + EPWM_O_LOCK) = (0xA5A50000UL | (uint32)RegisterGroup);
}

/*
 * XCMP related APIs
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureXCmpMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP;

    if (TRUE == Select)
    {
        /* Enable XCMP compare register operation */
        HWREGH(offset + EPWM_O_XCMPCTL1) |= EPWM_XCMPCTL1_XCMPEN;
    }
    else
    {
        /* Disable XCMP compare register operation */
        HWREGH(offset + EPWM_O_XCMPCTL1) &= ~EPWM_XCMPCTL1_XCMPEN;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureSplitXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP;

    if (TRUE == Select)
    {
        HWREGH(offset + EPWM_O_XCMPCTL1) |= EPWM_XCMPCTL1_XCMPSPLIT;
    }
    else
    {
        HWREGH(offset + EPWM_O_XCMPCTL1) &= ~EPWM_XCMPCTL1_XCMPSPLIT;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivAllocAXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                       VAR(Cdd_Pwm_XCmp_AllocCmpAType, AUTOMATIC) Alloctype)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XCMPCTL1;

    HWREGH(offset) =
        (HWREGH(offset) & ~EPWM_XCMPCTL1_XCMPA_ALLOC_M) | ((uint32)Alloctype << EPWM_XCMPCTL1_XCMPA_ALLOC_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivAllocBXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                       VAR(Cdd_Pwm_XCmp_AllocCmpBType, AUTOMATIC) Alloctype)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XCMPCTL1;

    HWREGH(offset) =
        (HWREGH(offset) & ~EPWM_XCMPCTL1_XCMPB_ALLOC_M) | ((uint32)Alloctype << EPWM_XCMPCTL1_XCMPB_ALLOC_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg, VAR(uint16, AUTOMATIC) XCmpValue)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XCMP1_ACTIVE + ((uint32)XCmpReg * 2U);
    /* Write to the XCMP registers. */
    HWREGH(offset + 2U) = XCmpValue;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpShadowRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_XCompareRegType, AUTOMATIC) XCmpReg, VAR(uint16, AUTOMATIC) XCmpValue)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_CMPC_SHDW1 + ((uint32)XCmpReg * 2U);

    /* Write to the CMPC/D Shadow registers. */
    HWREGH(offset) = XCmpValue;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXMinMaxRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_XMinMaxRegType, AUTOMATIC) XMinMaxReg, VAR(uint16, AUTOMATIC) XCmpValue)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XMINMAX_ACTIVE + ((uint32)XMinMaxReg * 2U);
    /* Write to the XMINMAX register. */
    HWREGH(offset) = XCmpValue;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpActionQualifierAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) ShadowSet,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                         VAR(Cdd_Pwm_XCmpAqOutputEventType, AUTOMATIC) Event)
{
    uint32 output_channel = ((uint32)(OutputChannel) * 2U);
    uint32 base           = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset;
    uint16 event = ((uint16)Event * 2U);

    /* Get the register offset */
    if (ShadowSet == CDD_PWM_XCMP_ACTIVE)
    {
        offset                = EPWM_O_XCMP + EPWM_O_XAQCTLA_ACTIVE + output_channel;
        HWREGH(base + offset) = (HWREGH(base + offset) & ~(3UL << event)) | ((uint32)Output << event);
    }
    else if (ShadowSet == CDD_PWM_XCMP_SHADOW1)
    {
        offset                = EPWM_O_XCMP + EPWM_O_XAQCTLA_SHDW1 + output_channel;
        HWREGH(base + offset) = (HWREGH(base + offset) & ~(3UL << event)) | ((uint32)Output << event);
    }
    else if (ShadowSet == CDD_PWM_XCMP_SHADOW2)
    {
        offset                = EPWM_O_XCMP + EPWM_O_XAQCTLA_SHDW2 + output_channel;
        HWREGH(base + offset) = (HWREGH(base + offset) & ~(3UL << event)) | ((uint32)Output << event);
    }
    else
    {
        offset                = EPWM_O_XCMP + EPWM_O_XAQCTLA_SHDW3 + output_channel;
        HWREGH(base + offset) = (HWREGH(base + offset) & ~(3UL << event)) | ((uint32)Output << event);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivEnableXLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset                = base + EPWM_O_XCMP;
    HWREG(offset + EPWM_O_XLOAD) = EPWM_XLOAD_STARTLD;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceXLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base                  = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset                = base + EPWM_O_XCMP;
    HWREG(offset + EPWM_O_XLOAD) = EPWM_XLOAD_FRCLD;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_XCmpLoadModeType, AUTOMATIC) Mode)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP;
    if (Mode == CDD_PWM_XCMP_LOADONCE)
    {
        HWREG(offset + EPWM_O_XLOADCTL) &= ~EPWM_XLOADCTL_LOADMODE;
    }
    else
    {
        HWREG(offset + EPWM_O_XLOADCTL) |= EPWM_XLOADCTL_LOADMODE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpShadowLevel(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_XCmpShadowLevelType, AUTOMATIC) Level)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XLOADCTL;
    HWREG(offset) = (HWREG(offset) & ~EPWM_XLOADCTL_SHDWLEVEL_M) | ((uint32)Level << EPWM_XLOADCTL_SHDWLEVEL_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpShadowBufPtrLoadOnce(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_XCmpShadowBufPtrType, AUTOMATIC) Ptr)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XLOADCTL;
    HWREG(offset) =
        (HWREG(offset) & ~EPWM_XLOADCTL_SHDWBUFPTR_LOADONCE_M) | ((uint32)Ptr << EPWM_XLOADCTL_SHDWBUFPTR_LOADONCE_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetXCmpShadowRepeatBufxCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) BufferSet,
                                         VAR(uint32, AUTOMATIC) Count)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XLOADCTL;

    if (BufferSet == CDD_PWM_XCMP_SHADOW2)
    {
        HWREG(offset) = (HWREG(offset) & ~EPWM_XLOADCTL_RPTBUF2PRD_M) | ((uint32)Count << EPWM_XLOADCTL_RPTBUF2PRD_S);
    }
    else if (BufferSet == CDD_PWM_XCMP_SHADOW3)
    {
        HWREG(offset) = (HWREG(offset) & ~EPWM_XLOADCTL_RPTBUF3PRD_M) | ((uint32)Count << EPWM_XLOADCTL_RPTBUF3PRD_S);
    }
    else
    {
        /* Do nothing. Not a valid case. */
    }
}

/*
 * Minimum Dead Band Module related APIs
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureMinimumDeadBand(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                     VAR(boolean, AUTOMATIC) Select)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB + EPWM_O_MINDBCFG;

    /* Set the appropriate Block to enable minimum dead band logic */
    uint32 deadbandcfg = (CDD_PWM_OUTPUT_A == OutputChannel) ? (EPWM_MINDBCFG_ENABLEA) : (EPWM_MINDBCFG_ENABLEB);

    if (TRUE == Select)
    {
        HWREG(offset) |= deadbandcfg;
    }
    else
    {
        HWREG(offset) &= ~deadbandcfg;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivInvertMinimumDeadBandSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                        VAR(boolean, AUTOMATIC) Invert)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB + EPWM_O_MINDBCFG;

    /* Set the appropriate Output bit to enable minimum dead band Logic */
    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        HWREGH(offset) = (HWREGH(offset) & ~EPWM_MINDBCFG_INVERTA) | (Invert << 2U);
    }
    else
    {
        HWREG(offset) = (HWREG(offset) & ~EPWM_MINDBCFG_INVERTB) | (Invert << 18U);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectMinimumDeadBandAndOrLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                            VAR(boolean, AUTOMATIC) Logic)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB + EPWM_O_MINDBCFG;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        /* Configure Logic operation on EPWMA */
        HWREGH(offset) = (HWREGH(offset) & ~EPWM_MINDBCFG_POLSELA) | ((uint32)Logic << 8U);
    }
    else
    {
        /* Configure Logic operation on EPWMB */
        HWREG(offset) = (HWREG(offset) & ~EPWM_MINDBCFG_POLSELB) | ((uint32)Logic << 24U);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectMinimumDeadBandBlockingSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                VAR(boolean, AUTOMATIC) BlockingSignal)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB + EPWM_O_MINDBCFG;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        /* Configure Block signal Source on EPWMA */
        HWREGH(offset) = (HWREGH(offset) & ~EPWM_MINDBCFG_SELBLOCKA) | ((uint32)BlockingSignal << 3U);
    }
    else
    {
        /* Configure Block signal Source on EPWMB */
        HWREG(offset) = (HWREG(offset) & ~EPWM_MINDBCFG_SELBLOCKB) | ((uint32)BlockingSignal << 19U);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectMinimumDeadBandReferenceSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                 VAR(Cdd_Pwm_MindbReferenceSignalType, AUTOMATIC) ReferenceSignal)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    uint32 offset = base + EPWM_O_MINDB + EPWM_O_MINDBCFG;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        /* Select reference Source for minimum dead band on EPWMA */
        HWREGH(offset) = (HWREGH(offset) & ~EPWM_MINDBCFG_SELA_M) | ((uint32)ReferenceSignal << EPWM_MINDBCFG_SELA_S);
    }
    else
    {
        /* Select reference Source for minimum dead band on EPWMB */
        HWREG(offset) = (HWREG(offset) & ~EPWM_MINDBCFG_SELB_M) | ((uint32)ReferenceSignal << EPWM_MINDBCFG_SELB_S);
    }
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetMinDeadBandDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB + EPWM_O_MINDBDLY;
    uint16 retval;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        /* Return dead band Delay value of EPWMA */
        retval = (uint16)(HWREGH(offset) & EPWM_MINDBDLY_DELAYA_M);
    }
    else
    {
        /* Return dead band Delay value of EPWMB */
        retval = (uint16)((HWREG(offset) & EPWM_MINDBDLY_DELAYB_M) >> EPWM_MINDBDLY_DELAYB_S);
    }

    return ((uint16)retval);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetMinDeadBandDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel, VAR(uint16, AUTOMATIC) Delay)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB + EPWM_O_MINDBDLY;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        /* Dead band Delay for EPWMA */
        HWREGH(offset) = (uint16)Delay;
    }
    else
    {
        /* Dead band Delay for EPWMB */
        HWREGH(offset + 2U) = (uint16)Delay;
    }
}

/*
 * Illegal Combo Logic
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureIllegalComboLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                       VAR(boolean, AUTOMATIC) Select)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB;

    uint16 lut_bypass = (CDD_PWM_OUTPUT_A == OutputChannel) ? (EPWM_LUTCTLA_BYPASS) : (EPWM_LUTCTLB_BYPASS);

    uint32 output_offset = (CDD_PWM_OUTPUT_A == OutputChannel) ? (EPWM_O_LUTCTLA) : (EPWM_O_LUTCTLB);

    if (TRUE == Select)
    {
        /* Enable LUTA */
        HWREGH(offset + output_offset) = (HWREGH(offset + output_offset) & ~lut_bypass);
    }
    else
    {
        /* Bypass LUTA */
        HWREGH(offset + output_offset) = (HWREGH(offset + output_offset) | lut_bypass);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectXbarInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                            VAR(Cdd_Pwm_XbarInputType, AUTOMATIC) XbarInput)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        /* Select one of the 16 outputs of ICL XBAR for EPWMA */
        HWREGH(offset + EPWM_O_LUTCTLA) =
            (HWREGH(offset + EPWM_O_LUTCTLA) & ~EPWM_LUTCTLA_SELXBAR_M) | ((uint32)XbarInput << EPWM_LUTCTLA_SELXBAR_S);
    }
    else
    {
        /* Select one of the 16 outputs of ICL XBAR for EPWMB */
        HWREGH(offset + EPWM_O_LUTCTLB) =
            (HWREGH(offset + EPWM_O_LUTCTLB) & ~EPWM_LUTCTLB_SELXBAR_M) | ((uint16)XbarInput << EPWM_LUTCTLB_SELXBAR_S);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetLutDecX(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                       VAR(Cdd_Pwm_LutDecXType, AUTOMATIC) Decx, VAR(uint32, AUTOMATIC) Force)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_MINDB;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        /* Forces either 0 or 1 in the LUTDECx bit of LUTCTLA register */
        HWREGH(offset + EPWM_O_LUTCTLA + 2U) =
            ((HWREGH(offset + EPWM_O_LUTCTLA + 2U) & ~(1U << (uint16)Decx)) | (Force << (uint16)Decx));
    }
    else
    {
        /* Forces either 0 or 1 in the LUTDECx bit of LUTCTLB register */
        HWREGH(offset + EPWM_O_LUTCTLB + 2U) =
            ((HWREGH(offset + EPWM_O_LUTCTLB + 2U) & ~(1U << (uint16)Decx)) | (Force << (uint16)Decx));
    }
}

/*
 * Diode Emulation Logic related APIs
 */

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE;

    if (TRUE == Select)
    {
        /* Enable DE function */
        HWREGH(offset + EPWM_O_DECTL) = EPWM_DECTL_ENABLE;
    }
    else
    {
        /* Disable DE function */
        HWREGH(offset + EPWM_O_DECTL) &= ~EPWM_DECTL_ENABLE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_DiodeEmulationModeType, AUTOMATIC) Mode)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE;

    if (Mode == CDD_PWM_DIODE_EMULATION_CBC)
    {
        /* Enable DE CBC Mode */
        HWREGH(offset + EPWM_O_DECTL) &= ~EPWM_DECTL_MODE;
    }
    else
    {
        /* Enable DE OST Mode */
        HWREGH(offset + EPWM_O_DECTL) |= EPWM_DECTL_MODE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDiodeEmulationReentryDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) Delay)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE;
    HWREGH(offset + EPWM_O_DECTL) =
        (HWREGH(offset + EPWM_O_DECTL) & ~EPWM_DECTL_REENTRYDLY_M) | (Delay << EPWM_DECTL_REENTRYDLY_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDiodeEmulationTripLowSources(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  Cdd_Pwm_DETripLowSourceType Source)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE + EPWM_O_DECOMPSEL;
    HWREG(offset) = (HWREG(offset) & ~EPWM_DECOMPSEL_TRIPL_M) | ((uint16)Source << EPWM_DECOMPSEL_TRIPL_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDiodeEmulationTripHighSources(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   Cdd_Pwm_DETripHighSourceType Source)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE + EPWM_O_DECOMPSEL;
    HWREG(offset) = (HWREG(offset) & ~EPWM_DECOMPSEL_TRIPH_M) | ((uint32)Source << EPWM_DECOMPSEL_TRIPH_S);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectDiodeEmulationPwmSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                          VAR(Cdd_Pwm_DiodeEmulationSignalType, AUTOMATIC) DiodeEmuationsignal)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE + EPWM_O_DEACTCTL;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        HWREGH(offset) =
            (HWREGH(offset) & ~EPWM_DEACTCTL_PWMA_M) | ((uint16)DiodeEmuationsignal << EPWM_DEACTCTL_PWMA_S);
    }
    else
    {
        HWREGH(offset) =
            (HWREGH(offset) & ~EPWM_DEACTCTL_PWMB_M) | ((uint16)DiodeEmuationsignal << EPWM_DEACTCTL_PWMB_S);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSelectDiodeEmulationTripSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                           VAR(Cdd_Pwm_DiodeEmulationTripSrcType, AUTOMATIC) TripSrc)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE + EPWM_O_DEACTCTL;

    if (CDD_PWM_OUTPUT_A == OutputChannel)
    {
        HWREGH(offset) = (HWREGH(offset) & ~EPWM_DEACTCTL_TRIPSELA) | ((uint16)TripSrc << 2U);
    }
    else
    {
        HWREGH(offset) = (HWREGH(offset) & ~EPWM_DEACTCTL_TRIPSELB) | ((uint16)TripSrc << 6U);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivNoBypassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base                      = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset                    = base + EPWM_O_DE;
    HWREG(offset + EPWM_O_DEACTCTL) &= ~EPWM_DEACTCTL_TRIPENABLE;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivbypassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base                      = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset                    = base + EPWM_O_DE;
    HWREG(offset + EPWM_O_DEACTCTL) |= EPWM_DEACTCTL_TRIPENABLE;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivForceDiodeEmulationActive(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base                    = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset                  = base + EPWM_O_DE;
    HWREGH(offset + EPWM_O_DEFRC) |= EPWM_DEFRC_DEACTIVE;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivConfigureDiodeEmulationMonitorModeControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                      VAR(boolean, AUTOMATIC) Select)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE;

    if (TRUE == Select)
    {
        HWREGH(offset + EPWM_O_DEMONCTL) |= EPWM_DEMONCTL_ENABLE;
    }
    else
    {
        HWREGH(offset + EPWM_O_DEMONCTL) &= ~EPWM_DEMONCTL_ENABLE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDiodeEmulationMonitorModeStep(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DiodeEmulationDirectionType, AUTOMATIC) Direction,
                                             VAR(uint8, AUTOMATIC) StepSize)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE + EPWM_O_DEMONSTEP;

    if (CDD_PWM_DE_COUNT_UP == Direction)
    {
        HWREGH(offset) = (HWREGH(offset) & ~EPWM_DEMONSTEP_INCSTEP_M) | (StepSize << EPWM_DEMONSTEP_INCSTEP_S);
    }
    else
    {
        HWREG(offset) = (HWREG(offset) & ~EPWM_DEMONSTEP_DECSTEP_M) | (StepSize << EPWM_DEMONSTEP_DECSTEP_S);
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivSetDiodeEmulationMonitorCounterThreshold(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                     VAR(uint16, AUTOMATIC) Threshold)
{
    uint32 base    = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset  = base + EPWM_O_DE + EPWM_O_DEMONTHRES;
    HWREGH(offset) = Threshold;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_PrivClearDiodeEmulationActiveFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_DE;

    HWREGH(offset + EPWM_O_DECLR) |= EPWM_DECLR_DEACTIVE;
}
#endif

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)
static FUNC(void, CDD_PWM_CODE) Cdd_Pwm_InitDutyCycle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                                      VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle)
{
    const Cdd_Pwm_ChannelCfgType     *channel_cfg = &(Cdd_Pwm_ConfigPtr->channelcfg[ChannelId]);
    Cdd_Pwm_ChannelObjType           *channelobj  = &(Cdd_Pwm_DrvObjPtr->channelobj[ChannelId]);
    Cdd_Pwm_InstanceType              hw_index    = channel_cfg->hw_index;
    uint32                            base_addr   = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;
    Cdd_Pwm_ActionQualifierOutputType output;
    uint16                            compare_value = Cdd_Pwm_PrivGetCompareValue(ChannelId, DutyCycle);

    /* Set the duty cycle if the channel is active before this API call */
    if ((CDD_PWM_MAX_DUTY_CYCLE == DutyCycle) && (0U != Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period))
    {
        output = (channel_cfg->polarity == CDD_PWM_LOW) ? (CDD_PWM_AQ_OUTPUT_LOW) : (CDD_PWM_AQ_OUTPUT_HIGH);

        /* Clear all action qualifier action and set only TBCTR = Zero action */
        Cdd_Pwm_SingleActionQualifierAction(base_addr, channel_cfg->outputchannel, output,
                                            CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        /* Update the channel output edge state -
         * If set to FALSE the output is FLAT,
         * else edges can be observed in the output
         */
        channelobj->channel_active = FALSE;
    }
    else if ((0U == DutyCycle) || (0U == Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period) || (0U == compare_value))
    {
        output = (channel_cfg->polarity == CDD_PWM_LOW) ? (CDD_PWM_AQ_OUTPUT_HIGH) : (CDD_PWM_AQ_OUTPUT_LOW);

        /* Set AQ actions based on the polarity for 0% duty cycle */
        Cdd_Pwm_SingleActionQualifierAction(base_addr, channel_cfg->outputchannel, output,
                                            CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        /* Update the channel output edge state -
         * If set to FALSE the output is FLAT,
         * else edges can be observed in the output
         */
        channelobj->channel_active = FALSE;
    }
    else
    {
        /* Set output and duty cycle when the channel is in IDLE state before this API call */
        Cdd_Pwm_SetCounterCompareValue(base_addr, channel_cfg->outputchannel, compare_value);

        /* This setting is required for Symmetric waveform, when TBCTR = Zero then state should be
         * configured since the other two events are Compare Up & compare Down
         */
        Cdd_Pwm_SetActionQualifierAction(base_addr, channel_cfg->outputchannel, channelobj->level1,
                                         CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        /* Set the action qualifier action */
        Cdd_Pwm_SetActionQualifierAction(base_addr, channel_cfg->outputchannel, channelobj->level1,
                                         channelobj->outputevt2);
        Cdd_Pwm_SetActionQualifierAction(base_addr, channel_cfg->outputchannel, channelobj->level2,
                                         channelobj->outputevt1);
        /* Update the channel output edge state -
         * If set to FALSE the output is FLAT,
         * else edges can be observed in the output
         */
        channelobj->channel_active = TRUE;
    }

    /* Update duty cycle of the channel */
    channelobj->dutycycle = DutyCycle;
}

static FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivGetCompareValue(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                                              VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle)
{
    uint16 compare_value = 0U;
    uint32 period;
    uint8  hw_index = Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].hw_index;
    if (CDD_PWM_ASYMMETRIC_WAVEFORM == Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].symmetry)
    {
        /* For an asymmetric waveform: CMP = ((DutyCycle*(TBPRD+1U))/CDD_PWM_MAX_DUTY_CYCLE) */
        period = (uint32)(Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period + ((uint32)1U));

        /* Update the duty cycle of the channel when the counter is Zero */
        compare_value = (uint16)((period * DutyCycle) / CDD_PWM_MAX_DUTY_CYCLE);
    }
    else
    {
        /* For a symmetric waveform: CMP = (((DutyCycle*TBPRD)/CDD_PWM_MAX_DUTY_CYCLE)) */
        /* Update the duty cycle of the channel when the counter is Zero */
        compare_value = (uint16)((Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period * DutyCycle) / CDD_PWM_MAX_DUTY_CYCLE);
    }
    return compare_value;
}

static FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_PrivGetChannelActionQualifierAction(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId)
{
    const Cdd_Pwm_ChannelCfgType *channelcfg = &(Cdd_Pwm_ConfigPtr->channelcfg[ChannelId]);
    Cdd_Pwm_ChannelObjType       *channelobj = &(Cdd_Pwm_DrvObjPtr->channelobj[ChannelId]);

    channelobj->level1 = (CDD_PWM_HIGH == channelcfg->polarity) ? (CDD_PWM_AQ_OUTPUT_HIGH) : (CDD_PWM_AQ_OUTPUT_LOW);
    channelobj->level2 = (CDD_PWM_HIGH == channelcfg->polarity) ? (CDD_PWM_AQ_OUTPUT_LOW) : (CDD_PWM_AQ_OUTPUT_HIGH);

    /* Set the action qualifier Based on the count zero */
    channelobj->outputevt1 = (CDD_PWM_OUTPUT_A == channelcfg->outputchannel) ? (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA)
                                                                             : (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    /* Check the symmetry of the waveform */
    if (CDD_PWM_SYMMETRIC_WAVEFORM == Cdd_Pwm_ConfigPtr->hwunitcfg[(channelcfg->hw_index)].symmetry)
    {
        /* Action qualifier event on the output channel when the waveform is symmetric */
        channelobj->outputevt2 = (CDD_PWM_OUTPUT_A == channelcfg->outputchannel)
                                     ? (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA)
                                     : (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    }
    else
    {
        /* Set the action qualifier based on the count zero if the waveform is asymmetric */
        channelobj->outputevt2 = CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO;
    }
}

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
static FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_UpdateNotificationAction(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                     VAR(boolean, AUTOMATIC) NotificationMode, VAR(boolean, AUTOMATIC) Mode)
{
    uint8                        hw_index         = Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].hw_index;
    Cdd_Pwm_EdgeNotificationType edgenotification = Cdd_Pwm_DrvObjPtr->channelobj[ChannelId].edgenotifytype;
    /* NotificationMode will be true only when the notification is to be disabled which it is already enabled or
     *  vice-versa
     */
    if (TRUE == NotificationMode)
    {
        if ((CDD_PWM_ASYMMETRIC_WAVEFORM == Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].symmetry) && (FALSE == Mode) &&
            (3U == Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].zero_active))
        {
            /* If both edges of both channels notification is configured for an Asymmetric waveform
             * then TBPRD event shouldn't be disabled as the interrupt source because it is shared bychannel
             * For example: If notification for both CHANNEL A & CHANNEL B of a PWM instance is enabled and zero is
             * configured as the interrupt source for both the channels then it should not be disabled as the
             * interrupt source until notification is disabled for both the channels of the PWM instance.
             *
             * In case, both the channels have TBCTR=ZERO as their interrupt source then the zero_active
             * value becomes three. When the zero_active value becomes three we exclude ZERO for disabling
             * the interrupt source because it is also being used by another channel.
             * If only one channel has TBCTR=ZERO as the interrupt source then zero_active is not (3U) and in
             * that case we can disable ZERO as the interrupt source.
             */

            /* Now clear only the interrupt flag which is not shared by both the output channel of a PWM instance */
            edgenotification = (CDD_PWM_HIGH == Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].polarity)
                                   ? (CDD_PWM_FALLING_EDGE)
                                   : (CDD_PWM_RISING_EDGE);
        }

        /* Update notification for the channel */
        Cdd_Pwm_UpdateNotification(ChannelId, edgenotification, Mode);
    }
}

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
static FUNC(Cdd_Pwm_EvtMixTriggerSourceType, CDD_PWM_CODE)
    Cdd_Pwm_PrivGetEventSource(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                               VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification)
{
    uint8                           hw_index    = Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].hw_index;
    Cdd_Pwm_OutputChannelType       channel     = Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].outputchannel;
    Cdd_Pwm_OutputStateType         polarity    = Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].polarity;
    Cdd_Pwm_EvtMixTriggerSourceType eventsource = CDD_PWM_ETMIX_TBCTR_NONE;

    if (CDD_PWM_BOTH_EDGES != EdgeNotification)
    {
        /* Based on the polairy and symmetry configure the action qualifier events */
        if (((polarity == CDD_PWM_LOW) && (CDD_PWM_RISING_EDGE == EdgeNotification)) ||
            ((polarity == CDD_PWM_HIGH) && (CDD_PWM_FALLING_EDGE == EdgeNotification)))
        {
            eventsource = (channel == CDD_PWM_OUTPUT_A) ? (CDD_PWM_ETMIX_TBCTR_U_CMPA) : (CDD_PWM_ETMIX_TBCTR_U_CMPB);
        }
        else if (Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].symmetry == CDD_PWM_SYMMETRIC_WAVEFORM)
        {
            /* If the waveform is configured as SYMMETRIC then the notifications occur at CMPA/B events */
            eventsource = (channel == CDD_PWM_OUTPUT_A) ? (CDD_PWM_ETMIX_TBCTR_D_CMPA) : (CDD_PWM_ETMIX_TBCTR_D_CMPB);
        }
        else
        {
            /* If the waveform is configured as ASYMMETRIC then the notifications occur at TBCTR=Zero events */
            eventsource = CDD_PWM_ETMIX_TBCTR_ZERO;
        }
    }
    return eventsource;
}

static FUNC(void, CDD_PWM_CODE)
    Cdd_Pwm_UpdateNotification(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                               VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification,
                               VAR(boolean, AUTOMATIC) Mode)
{
    uint8                     hw_index      = Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].hw_index;
    Cdd_Pwm_OutputChannelType outputchannel = Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].outputchannel;
    uint16                    event_source;
    /* Configure the interrupt source based on the notification edge type */
    if (CDD_PWM_RISING_EDGE == EdgeNotification)
    {
        event_source = (uint16)(Cdd_Pwm_DrvObjPtr->channelobj[ChannelId].rising_event);
    }
    else if (CDD_PWM_FALLING_EDGE == EdgeNotification)
    {
        event_source = (uint16)(Cdd_Pwm_DrvObjPtr->channelobj[ChannelId].falling_event);
    }
    else
    {
        event_source = (((uint16)Cdd_Pwm_DrvObjPtr->channelobj[ChannelId].rising_event) |
                        ((uint16)Cdd_Pwm_DrvObjPtr->channelobj[ChannelId].falling_event));
    }

    /* Enable/Disable the interrupt events */
    Cdd_Pwm_ConfigureMixEvtTriggerSource(Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr, event_source, Mode);

    /* Update notification active for the hardwrae unit based on the output channel */
    if (FALSE == Mode)
    {
        /* Clear notification active for the output channel(irrespective of whether it is already set or not) */
        Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].zero_active &= ~(1U << ((uint8)outputchannel));

        /* Update the notification status of the instance */
        Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_enable &=
            ~(1U << ((uint8)Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].outputchannel));
    }
    else if ((event_source & ((uint16)CDD_PWM_ETMIX_TBCTR_ZERO)) == ((uint16)CDD_PWM_ETMIX_TBCTR_ZERO))
    {
        /* Set notification active for the output channel only if TBCTR=ZERO is configured as the interrupt source. */
        Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].zero_active |= (1U << ((uint8)outputchannel));

        /* Update the notification status of the instance */
        /* This indicates which channel of the instance has notification enabled.
         * If both the channels has notification disabled then the hardware notification will be disabled automatically.
         * If atleast one channel of the instance has notification enabled then the notification for the instance is
         * also enabled automatically
         */
        Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_enable |=
            (1U << ((uint8)Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].outputchannel));
    }
    else
    {
        /* Update the notification status of the instance */
        /* This indicates which channel of the instance has notification enabled.
         * If both the channels has notification disabled then the hardware notification will be disabled automatically
         * If atleast one channel of the instance has notification enabled then the notification for the instance is
         * also enabled automatically
         */
        Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_enable |=
            (1U << ((uint8)Cdd_Pwm_ConfigPtr->channelcfg[ChannelId].outputchannel));
    }
}
#endif
#endif

#endif

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) PhaseCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to TBPHS:TBPHSHR bits */
    HWREG(base + EPWM_O_TBPHS) = (PhaseCount << 8U);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResPhaseShiftOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(uint16, AUTOMATIC) HrPhaseCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to TBPHSHR bits */
    HWREGH(base + EPWM_O_TBPHS) = (HrPhaseCount << 8U);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) PeriodCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to TBPRD:TBPRDHR bits */
    HWREG(base + EPWM_O_TBPRDHR) = (PeriodCount << 8U);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(uint16, AUTOMATIC) HrPeriodCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to TBPRDHR bits */
    HWREGH(base + EPWM_O_TBPRDHR) = (HrPeriodCount << 8U);
}

FUNC(uint32, CDD_PWM_CODE) Cdd_Pwm_PrivHrpwmGetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Read from TBPRD:TBPRDHR bit */
    return (HWREG(base + EPWM_O_TBPRDHR) >> 8U);
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_PrivHrpwmGetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Read from TBPRDHR bit */
    return (HWREGH(base + EPWM_O_TBPRDHR) >> 8U);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetMepEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                  VAR(Cdd_Pwm_HrpwmMepEdgeModeType, AUTOMATIC) MepEdgeMode)
{
    uint32 base    = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint16 channel = ((uint16)OutputChannel) * 8U;
    /* Set the edge mode */
    HWREGH(base + EPWM_O_HRCNFG) =
        ((HWREGH(base + EPWM_O_HRCNFG) & ~(0x3U << (uint16)channel)) | ((uint16)MepEdgeMode << (uint16)channel));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetMepControlMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                   VAR(Cdd_Pwm_HrpwmMepCtrlModeType, AUTOMATIC) MepCtrlMode)
{
    uint32 base    = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint16 channel = ((uint16)OutputChannel) * 8U;
    /* Set the MEP control */
    HWREGH(base + EPWM_O_HRCNFG) = ((HWREGH(base + EPWM_O_HRCNFG) & ~(0x1U << ((uint16)channel + 2U))) |
                                    ((uint16)MepCtrlMode << ((uint16)channel + 2U)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetCounterCompareShadowLoadEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                  VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{
    uint32 base    = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint16 channel = ((uint16)OutputChannel) * 8U;
    /* Set the CMPAHR or CMPBHR load mode */
    HWREGH(base + EPWM_O_HRCNFG) = ((HWREGH(base + EPWM_O_HRCNFG) & ~(0x3U << ((uint16)channel + 3U))) |
                                    ((uint16)LoadEvent << ((uint16)channel + 3U)));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(boolean, AUTOMATIC) EnableOutputSwap)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Set output swap mode */
    if (TRUE == EnableOutputSwap)
    {
        HWREGH(base + EPWM_O_HRCNFG) |= EPWM_HRCNFG_SWAPAB;
    }
    else
    {
        HWREGH(base + EPWM_O_HRCNFG) &= ~EPWM_HRCNFG_SWAPAB;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetChannelBOutputPath(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_HrpwmChannelBOutputType, AUTOMATIC) OutputOnB)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Set the output on EPWM B */
    HWREGH(base + EPWM_O_HRCNFG) =
        ((HWREGH(base + EPWM_O_HRCNFG) & ~(EPWM_HRCNFG_SELOUTB)) | ((uint16)OutputOnB << 5U));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmConfigureAutoConversion(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(boolean, AUTOMATIC) Select)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        /* Enable MEP automatic scale */
        HWREGH(base + EPWM_O_HRCNFG) |= EPWM_HRCNFG_AUTOCONV;
    }
    else
    {
        /* Disable MEP automatic scale */
        HWREGH(base + EPWM_O_HRCNFG) &= ~EPWM_HRCNFG_AUTOCONV;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmConfigurePeriodControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        /* Set HRPE bit */
        HWREGH(base + EPWM_O_HRPCTL) |= EPWM_HRPCTL_HRPE;
    }
    else
    {
        /* Clear HRPE bit */
        HWREGH(base + EPWM_O_HRPCTL) &= ~EPWM_HRPCTL_HRPE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(boolean, AUTOMATIC) Select)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    if (TRUE == Select)
    {
        /* Set TBPHSHRLOADE bit */
        HWREGH(base + EPWM_O_HRPCTL) |= EPWM_HRPCTL_TBPHSHRLOADE;
    }
    else
    {
        /* Clear TBPHSHRLOADE bit */
        HWREGH(base + EPWM_O_HRPCTL) &= ~EPWM_HRPCTL_TBPHSHRLOADE;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetSyncPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_HrpwmSyncPulseSourceType, AUTOMATIC) SyncPulseSource)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Set the PWMSYNC source */
    /*
     * Configuration for sync pulse source equal to HRPWM_PWMSYNC_SOURCE_PERIOD
     * or HRPWM_PWMSYNC_SOURCE_ZERO
     */
    if (SyncPulseSource < CDD_PWM_HRPWM_PWMSYNC_SOURCE_COMPC_UP)
    {
        HWREGH(base + EPWM_O_HRPCTL) =
            ((HWREGH(base + EPWM_O_HRPCTL) & ~(EPWM_HRPCTL_PWMSYNCSELX_M | EPWM_HRPCTL_PWMSYNCSEL)) |
             ((uint16)SyncPulseSource << 1U));
    }
    else
    {
        HWREGH(base + EPWM_O_HRPCTL) = ((HWREGH(base + EPWM_O_HRPCTL) & ~EPWM_HRPCTL_PWMSYNCSELX_M) |
                                        ((uint16)SyncPulseSource << EPWM_HRPCTL_PWMSYNCSELX_S));
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetTranslatorRemainder(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(uint16, AUTOMATIC) TrRemVal)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Set Translator Remainder value */
    HWREGH(base + EPWM_O_TRREM) = (TrRemVal & EPWM_TRREM_TRREM_M);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                        VAR(uint32, AUTOMATIC) CompCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to counter compare registers */
    if (OutputChannel == CDD_PWM_OUTPUT_A)
    {
        /* Write to CMPA:CMPAHR */
        HWREG(base + EPWM_O_CMPA) = CompCount << 8U;
    }
    else
    {
        /* Write to CMPB:CMPBHR */
        HWREG(base + EPWM_O_CMPB) = CompCount << 8U;
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                 VAR(uint16, AUTOMATIC) HrCompCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Write to the high resolution counter compare registers */
    if (OutputChannel == CDD_PWM_OUTPUT_A)
    {
        /* Write to CMPAHR */
        HWREGH(base + EPWM_O_CMPA) = (HrCompCount << 8U);
    }
    else
    {
        /* Write to CMPBHR */
        HWREGH(base + EPWM_O_CMPB) = (HrCompCount << 8U);
    }
}

FUNC(uint32, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmGetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint32 compare_count, compare_module;
    uint32 base    = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    compare_module = (CDD_PWM_OUTPUT_A == OutputChannel) ? (EPWM_O_CMPA) : (EPWM_O_CMPB);

    /* Get counter compare value for selected module */
    if (OutputChannel == CDD_PWM_OUTPUT_A)
    {
        /* Read from CMPAHR */
        compare_count = HWREG(base + compare_module) >> 8U;
    }
    else
    {
        /* Read from CMPBHR */
        compare_count = HWREG(base + compare_module) >> 8U;
    }

    return (compare_count);
}

FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_PrivGetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint16 HrCompCount, compare_module;
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    compare_module = (CDD_PWM_OUTPUT_A == OutputChannel) ? (EPWM_O_CMPA) : (EPWM_O_CMPB);

    HrCompCount = (HWREGH(base + compare_module) >> 8U);

    return (HrCompCount);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetRisingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) RedCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Set the consolidated RED (Rising Edge Delay) count */
    HWREG(base + EPWM_O_DBREDHR) = RedCount << 9U;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResRisingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(uint16, AUTOMATIC) HrRedCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Set the High Resolution RED (Rising Edge Delay) count only */
    HWREGH(base + EPWM_O_DBREDHR) = HrRedCount << 9U;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetFallingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) FedCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Set the High Resolution FED (Falling Edge Delay) count */
    HWREG(base + EPWM_O_DBFEDHR) = FedCount << 9U;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResFallingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(uint16, AUTOMATIC) HrFedCount)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;

    /* Set the high resolution FED (Falling Edge Delay) count */
    HWREGH(base + EPWM_O_DBFEDHR) = HrFedCount << 9U;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetMepStep(VAR(Cdd_Pwm_HrpwmCalInstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) MepCount)
{
    uint32 base = HRPWMCAL1_BASE + ((HRPWMCAL2_BASE - HRPWMCAL1_BASE) * InstanceId);

    /* Set HRPWM MEP count */
    HWREGH(base + HRPWMCAL_O_HRMSTEP) = ((HWREGH(base + HRPWMCAL_O_HRMSTEP) & ~HRPWMCAL_HRMSTEP_HRMSTEP_M) | MepCount);
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetDeadbandMEPEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_HrpwmMepDeadBandEdgeModeType, AUTOMATIC) MepDbEdge)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    // Set the HRPWM DB edge mode
    HWREGH(base + EPWM_O_HRCNFG2) = ((HWREGH(base + EPWM_O_HRCNFG2) & ~EPWM_HRCNFG2_EDGMODEDB_M) | ((uint16)MepDbEdge));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetRisingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    // Set the HRPWM RED load mode
    HWREGH(base + EPWM_O_HRCNFG2) = ((HWREGH(base + EPWM_O_HRCNFG2) & ~EPWM_HRCNFG2_CTLMODEDBRED_M) |
                                     ((uint16)LoadEvent << EPWM_HRCNFG2_CTLMODEDBRED_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetFallingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    // Set the HRPWM FED load mode

    HWREGH(base + EPWM_O_HRCNFG2) = ((HWREGH(base + EPWM_O_HRCNFG2) & ~EPWM_HRCNFG2_CTLMODEDBFED_M) |
                                     ((uint16)LoadEvent << EPWM_HRCNFG2_CTLMODEDBFED_S));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmLockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_HrpwmLockRegisterGroupType, AUTOMATIC) RegisterGroup)
{
    uint32 base = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    // Write the Key to EPWMLOCK register
    HWREG(base + EPWM_O_LOCK) = (0xA5A50000UL | ((uint32)RegisterGroup));
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg, VAR(uint32, AUTOMATIC) XCmpValue)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XCMP1_ACTIVE + ((uint32)XCmpReg * 2U);

    /* Write to the XCMP registers. */
    HWREG(offset) = XCmpValue;
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_PrivHrpwmSetHiResXCmpRegValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg,
                                          VAR(uint32, AUTOMATIC) HrXCmpValue)
{
    uint32 base   = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    uint32 offset = base + EPWM_O_XCMP + EPWM_O_XCMP1_ACTIVE + ((uint32)XCmpReg * 2U);

    /* Write to the XCMP registers. */
    HWREGH(offset) = HrXCmpValue;
}

/*****************************************************************************
 *
 * FUNCTION:    SFO(void)
 * DESCRIPTION: MEP calibration module (DCAL) result + channel calibration
 *              result(channel delay lines) -
 *              Updates Cdd_Pwm_MEP_ScaleFactor value
 *              for selected ePWM channel calibration if user wants to compare
 *              with "MEP calibration module" (DCAL) result for proper
 *              operation.  Only DCAL (n=0) can be run while HRPWM is enabled
 *              Individual channel calibration can only be run on a
 *              channel with HRPWM capabilities disabled-one channel at a time.
 *
 * PARAMETERS:  Cdd_Pwm_Sfo_Cal - ePWM channel # on which Cdd_Pwm_MEP_ScaleFactor will
 *                        be calculated (0 = DCAL channel)
 * RETURN:      1 - SFO calibration complete on selected channel.
 *              0 - SFO calibration incomplete on selected channel.
 *
 ******************************************************************************/
FUNC(Cdd_Pwm_SfoStatus, CDD_PWM_CODE) Cdd_Pwm_PrivSfo(Cdd_Pwm_HrpwmCalInstanceType Cdd_Pwm_HrpwmCalId)
{
    static uint16 hrc1, hrc2; /* holds HRCNT0 count in 65535 HRCNT1 counts */
    static uint16 taskptr = 0U;
    uint16        Cdd_Pwm_MEP_SF;
    uint16        status, numer;
    float         denom;

    /* Initialize the MEP scale factor */
    uint16 Cdd_Pwm_MEP_ScaleFactor = 0U;

    /* Hrpwm Cal base address */
    uint32 Cdd_Pwm_HrCalBase = HRPWMCAL1_BASE + (Cdd_Pwm_HrpwmCalId * CDD_PWM_HRCAL_BASESTEP);

    status = CDD_PWM_SFO_INCOMPLETE; /* status remains 0 until SFO completes */

    /* SFO MEP Calibration State Machine */
    switch (taskptr)
    {
        case 0: /* General Initialization */

            /* Clear all bits */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) = 0x0U;

            /* Set the counter period */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPRD) = CDD_PWM_PRDVAL;

            /* Eliminate delay in counter start(CNTSEL = 1), enable lump delay
                (TESTSEL = 1) & turn on the calibration logic(CALPWRON = 1) */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= (HRPWMCAL_HRPWR_CNTSEL | HRPWMCAL_HRPWR_TESTSEL);
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= HRPWMCAL_HRPWR_CALPWRON;

            hrc1    = 0U;
            hrc2    = 0U;
            taskptr = 1U;
            break;

        case 1: /* Initialization for 1st run */

            /* The logic should be reinitialized before every calibration run. Clear all bits in HRPWR */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) = 0x0U;

            /* Configure # MEP steps A(1st point) in DCAL mode. This should be done before powering the CAL logic on */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRCAL) = CDD_PWM_MEP1;

            /* Eliminate delay in counter start(CNTSEL = 1), enable lump delay
                (TESTSEL = 1) & turn on the calibration logic(CALPWRON = 1) */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= (HRPWMCAL_HRPWR_CNTSEL | HRPWMCAL_HRPWR_TESTSEL);
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= HRPWMCAL_HRPWR_CALPWRON;

            /* Manually clear HRCNT0 & HRCNT1 to be safe */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRCNT0) = 0x0U;
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRCNT1) = 0x0U;

            /* Start calibration */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= HRPWMCAL_HRPWR_CALSTART;

            /* Update task pointer to next case for next SFO call. */
            taskptr = 2U;

            break;

        case 2: /*  Wait for 1st run to complete */

            /* If calibration is not complete, exit SFO() and check again
                in next function call. CALSTS becomes zero when HRCNT1 value
                equals HRPRD value or 0xFFFFU. */
            if ((HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) & HRPWMCAL_HRPWR_CALSTS) == 0x0U)
            {
                /* Stop calibration. This bit is NOT automatically cleared. */
                HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) &= ~HRPWMCAL_HRPWR_CALSTART;

                /* Get 1st count in HRCNT0 (# of ring osc oscillations) */
                hrc1 = HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRCNT0);

                /* Update task pointer to next case for next SFO call. */
                taskptr = 3U;

                /* Power down the calibration logic */
                HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) &= ~HRPWMCAL_HRPWR_CALPWRON;
            }

            break;

        case 3: /*  Initialization for 2nd run */

            /* Clear all bits in HRPWR */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) = 0x0U;

            /* Configure # MEP steps B(2nd point) in DCAL mode. This should be done before powering the CAL logic on*/
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRCAL) = CDD_PWM_MEP2;

            /* Eliminate delay in counter start(CNTSEL = 1), enable lump delay
                (TESTSEL = 1) & turn on the calibration logic(CALPWRON = 1) */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= (HRPWMCAL_HRPWR_CNTSEL | HRPWMCAL_HRPWR_TESTSEL);
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= HRPWMCAL_HRPWR_CALPWRON;

            /* Manually clear HRCNT0 & HRCNT1 to be safe */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRCNT0) = 0x0U;
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRCNT1) = 0x0U;

            /* Start calibration */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= HRPWMCAL_HRPWR_CALSTART;

            /* Move to next case when SFO() is called the next time */
            taskptr = 4U;
            break;

        case 4: /* Wait for 2nd run to complete */

            /* If calibration is not complete, exit SFO() and check again next function call */
            if ((HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) & HRPWMCAL_HRPWR_CALSTS) == 0x0U)
            {
                /* Stop calibration. This bit is NOT automatically cleared */
                HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) &= ~HRPWMCAL_HRPWR_CALSTART;

                /* Get the count from HRCNT0 (# of ring osc oscillations) */
                hrc2 = HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRCNT0);

                /* Move to next case when SFO() is called the next time */
                taskptr = 5U;

                /* Power down the calibration logic */
                HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) &= ~HRPWMCAL_HRPWR_CALPWRON;
            }

            break;

        case 5: /* Process diagnostics data */

            /* Calculate MEP delay time in 1 SYSCLK cycle */
            denom = ((1 / (float)hrc2) - (1 / (float)hrc1)) * (float)0xFFFF;

            /* Calculate # of MEP steps */
            numer = (CDD_PWM_MEP2 - CDD_PWM_MEP1) * 2U;

            /* Calculate MEP scale factor */
            Cdd_Pwm_MEP_SF          = (((float)numer / denom) + 0.5);
            Cdd_Pwm_MEP_ScaleFactor = Cdd_Pwm_MEP_SF;

            /* Update the task pointer to CDD_PWM_MEP1 calibration initialization task for next call. */
            taskptr = 1U;

            /* Update status & assign scale factor value to HRMSTEP register */
            if (Cdd_Pwm_MEP_ScaleFactor > 255U)
            {
                status = CDD_PWM_SFO_ERROR;
            }
            else
            {
                /* Update HRMSTEP register only with DCAL result */
                HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRMSTEP) = Cdd_Pwm_MEP_ScaleFactor;
                taskptr                                        = 0U;
                status                                         = CDD_PWM_SFO_COMPLETE;
            }

            break;

        default: /* default */

            /* Clear all bits */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) = 0x0U;

            /* Set the counter period */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPRD) = CDD_PWM_PRDVAL;

            /* Eliminate delay in counter start(CNTSEL = 1), enable lump delay
                (TESTSEL = 1) & turn on the calibration logic(CALPWRON = 1) */
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= (HRPWMCAL_HRPWR_CNTSEL | HRPWMCAL_HRPWR_TESTSEL);
            HWREGH(Cdd_Pwm_HrCalBase + HRPWMCAL_O_HRPWR) |= HRPWMCAL_HRPWR_CALPWRON;

            hrc1    = 0U;
            hrc2    = 0U;
            taskptr = 1U;
            break;
    }
    return status;
}

#endif

#define CDD_PWM_STOP_SEC_CODE
#include "Cdd_Pwm_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Priv.c
 *********************************************************************************************************************/
