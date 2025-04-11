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
 *  Description: This file contains private function definitions that are defined in Cdd_Pwm_Priv.h file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm_Priv.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

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

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/* Cdd_Pwm driver object to store status of PWM instances and channels */
#define CDD_PWM_START_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"
P2VAR(Cdd_Pwm_DriverObjType,AUTOMATIC,CDD_PWM_VAR_INIT) Cdd_Pwm_DrvObjPtr = NULL_PTR;
#define CDD_PWM_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"

/* Cdd_Pwm configuration pointer to access driver configuration. */
#define CDD_PWM_START_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"
P2CONST(Cdd_Pwm_ConfigType,AUTOMATIC,CDD_PWM_CONST) Cdd_Pwm_ConfigPtr = NULL_PTR;
#define CDD_PWM_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief Set PWM clock prescale function
 *
 * This function sets the clock prescale/divider function for the PWM hardware unit
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  Prescale   Prescale value for the PWM hardware instance. Prescale value is time Base clock divider
 *                          multiplied with high speed clock divider
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetClockPrescale(uint32 Base, uint8 Prescale);

/** \brief Set time Base period value
 *
 * This function sets the time Base period value
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  PeriodCount   Period count value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBasePeriod(uint32 Base, uint16 PeriodCount);

/** \brief Set time Base counter initial value
 *
 * This function sets time Base initial counter value
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  Count  Initial count value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBaseCounter(uint32 Base, uint16 Count);

/** \brief Set time Base counter compare value
 *
 * This function sets the time Base counter compare value
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  CompareModule   Counter type
 * \param[in]  CompareCount   Compare value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetCounterCompareValue(uint32 Base,\
                                                        Cdd_Pwm_OuputChannelType OutputChannel,uint16 CompareCount);

/** \brief Enable the shadow mode & set the shadow load mode
 *
 * This function enables the shadow mode & sets the shadow load mode
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  Channel   Output channel of the PWM instance
 * \param[in]  LoadMode   AQ load mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/                                        
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierShadowLoadMode(uint32 Base,\
                                    Cdd_Pwm_OuputChannelType Channel,Cdd_Pwm_ActionQualifierLoadModeType LoadMode);

/** \brief Set time Base counter mode for the PWM instance
 *
 * This function sets time Base counter mode for the PWM instance
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  CounterMode   Counter mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBaseCounterMode(uint32 Base,\
                                                                        Cdd_Pwm_TimeBaseCountModeType CounterMode);

/** \brief Clear interrupt flag for the specified interrupt/instance
 *
 * This function clears interrupt flag for the specified interrupt/instance
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearEventTriggerInterruptFlag(uint32 Base);

/** \brief Set the counter compare shadow load mode
 *
 * This function sets the counter compare shadow load mode
 *
 * \param[in]  Base   Base address of the PWM hardware
 * \param[in]  LoadMode   Period load mode of the PWM hardware instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetCompareShadowMode(uint32 Base,\
                            Cdd_Pwm_OuputChannelType OutputChannel, Cdd_Pwm_CounterCompareLoadModeType LoadMode);

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
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierAction(uint32 Base,\
                Cdd_Pwm_OuputChannelType ChannelType,Cdd_Pwm_AQOutputType Output, Cdd_Pwm_AQOutputEvtType Event);

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
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearActionQualifierAction(uint32 Base,\
                                                            Cdd_Pwm_OuputChannelType ChannelType);

#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/** \brief Configures(enables/disables) the interrupt
 *
 * This function enables/disables the interrupt of the PWM instance
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  Mode   Enable/Disable mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureInterrupt(uint32 Base, boolean Mode);

/** \brief Configure the interrupt event count for the PWM instance
 *
 * This function configures the interrupt event count for the PWM instance
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  EventCount  Interrupt event count
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetInterruptEventCount(uint32 Base, uint8 EventCount);

#endif

#if (STD_ON == CDD_PWM_DEINIT_API) && (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)

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
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearInterruptPrescale(uint32 Base);
#endif

/** \brief Configure the interrupt source for the PWM instance
 *
 * This function configures the interrupt source for the PWM instance
 *
 * \param[in]  Base   Base address of the PWM hardware instance
 * \param[in]  InterruptSource   Interrupt source
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetInterruptSource(uint32 Base,\
                                                                        Cdd_Pwm_InterruptSourceType InterruptSource);

/** \brief Set up Action qualifier output
 *
 * This function sets the action qualifier action for the PWM channel and it clears the previous AQ configuration
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
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SingleActionQualifierAction(uint32 Base,\
                    Cdd_Pwm_OuputChannelType ChannelType, Cdd_Pwm_AQOutputType Output, Cdd_Pwm_AQOutputEvtType Event);


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
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureMixEvtTriggerSource(uint32 Base, uint16 Event, boolean Mode);

/** \brief Returns the action qualifier action for the channel
 *
 * This function returns the action qualifier action for the channel
 *
 * \param[in]  ChannelNumber   Numeric ID of the PWM channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void,CDD_PWM_CODE) \
                        Cdd_Pwm_GetChannelActionQualifierAction(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber);

/** \brief Initialize duty cycle for the specified PWM channel with the specified duty cycle
 *
 * This function sets the specified duty cycle for the PWM channel
 *
 * \param[in]  ChannelNumber   Numeric ID of the PWM channel
 * \param[in]  DutyCycle       Duty cycle for the PWM channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void,CDD_PWM_CODE) Cdd_Pwm_InitDutyCycle(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                                                VAR(Cdd_Pwm_DutyCycleType,AUTOMATIC) DutyCycle);

#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/** \brief Set the action qualifier action for the channel
 *
 * This function sets the action qualifier action for the channel
 *
 * \param[in]  ChannelNumber        Numeric ID of the PWM channel
 * \param[in]  NotificationMode     Determine whether the notification function should be called
 * \param[in]  Mode                 Determine whether notification should be enabled or disabled
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void,CDD_PWM_CODE) Cdd_Pwm_UpdateNotificationAction(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                            VAR(boolean,AUTOMATIC) NotificationMode,VAR(boolean,AUTOMATIC) Mode);
#endif

/** \brief Get the compare value of the channel
 *
 * This function calculates the compare value for the specified duty cycle for the channel
 *
 * \param[in]  ChannelNumber   Numeric ID of the PWM channel
 * \param[in]  DutyCycle        Duty cycle of the PWM channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetCompareValue(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                                    VAR(Cdd_Pwm_DutyCycleType,AUTOMATIC) DutyCycle);

#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/** \brief Configure notification sources
 *
 * This function configures the notification sources
 *
 * \param[in]  ChannelNumber   Numeric ID of the channel
 * \param[in]  EdgeNotification   Edge notification type
 * \param[in]  Mode         Count Mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void,CDD_PWM_CODE) Cdd_Pwm_UpdateNotification(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber, \
                        VAR(Cdd_Pwm_EdgeNotificationType,AUTOMATIC) EdgeNotification, VAR(boolean,AUTOMATIC) Mode);

/** \brief Get event source for either rising edge or falling edge
 *
 * This function returns the event source for the rising edge or falling edge. This function doesn't work for
 * both edges notification option. In that case the function should be called separately for rising and falling edge.
 *
 * \param[in]  ChannelNumber   Numeric ID of the channel
 * \param[in]  EdgeNotification Edge Notification type of the channel
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Cdd_Pwm_EvtMixTriggerSourceType,CDD_PWM_CODE) \
                         Cdd_Pwm_GetEventSource(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                                        VAR(Cdd_Pwm_EdgeNotificationType,AUTOMATIC) EdgeNotification);
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define CDD_PWM_START_SEC_CODE
#include "Cdd_Pwm_MemMap.h"

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetClockPrescale(uint32 Base, uint8 Prescale)
{
    /* Set the time Base clock divider and high speed clock divider for the PWM instance */
    HWREGH(Base + EPWM_O_TBCTL) = ((HWREGH(Base + EPWM_O_TBCTL) & ~(EPWM_TBCTL_CLKDIV_M | EPWM_TBCTL_HSPCLKDIV_M)) | \
                                    (Prescale << EPWM_TBCTL_HSPCLKDIV_S));
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBasePeriod(uint32 Base, uint16 PeriodCount)
{
    /* Set the time Base period value */
    HWREGH(Base + EPWM_O_TBPRD) = PeriodCount;
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBaseCounter(uint32 Base, uint16 Count)
{
    /* Write to TBCTR register */
    HWREGH(Base + EPWM_O_TBCTR) = Count;
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBaseCounterMode(uint32 Base,\
                                                Cdd_Pwm_TimeBaseCountModeType CounterMode)
{
    /* Write to CTRMODE bit */
    HWREGH(Base + EPWM_O_TBCTL) = ((HWREGH(Base + EPWM_O_TBCTL) & ~(EPWM_TBCTL_CTRMODE_M)) |((uint16)CounterMode));
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetCounterCompareValue(uint32 Base,\
                                                        Cdd_Pwm_OuputChannelType OutputChannel, uint16 CompareCount)
{
    /* Set the counter compare value */
    uint32 offset = Base + EPWM_O_CMPA + ((uint32)OutputChannel * 4U);
    HWREGH(offset + 0x2U) = CompareCount;
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierShadowLoadMode(uint32 Base,\
                                    Cdd_Pwm_OuputChannelType Channel,Cdd_Pwm_ActionQualifierLoadModeType LoadMode)
{
    uint16 loadoffset = 0U,shadowoffset = 4U;
    if(CDD_PWM_OUTPUT_B == Channel)
    {
        loadoffset = 2U;
        shadowoffset += 2U;
    }

    /* Set the appropriate shadow load mode and enable shadow load mode. */
    HWREGH(Base + EPWM_O_AQCTL) = ((HWREGH(Base + EPWM_O_AQCTL) & ~ (0x3U << loadoffset)) | \
                                                            ((1U << shadowoffset) | ((uint16)LoadMode << loadoffset)));
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierAction(uint32 Base,\
                Cdd_Pwm_OuputChannelType ChannelType, Cdd_Pwm_AQOutputType Output, Cdd_Pwm_AQOutputEvtType Event)
{
    /* Set the AQ action for the channel */
    uint32 offset = Base + EPWM_O_AQCTLA + ((uint32)ChannelType * 4U);
    HWREGH(offset) = ((HWREGH(offset) & ~(3U << (uint16)Event)) |((uint16)Output << (uint16)Event));
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearActionQualifierAction(uint32 Base,\
                                                            Cdd_Pwm_OuputChannelType ChannelType)
{
    /* Set the AQ action for the channel */
    uint32 offset = Base + EPWM_O_AQCTLA + ((uint32)ChannelType * 4U);
    HWREGH(offset) = ((uint16)0U);
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SingleActionQualifierAction(uint32 Base,\
                    Cdd_Pwm_OuputChannelType ChannelType, Cdd_Pwm_AQOutputType Output, Cdd_Pwm_AQOutputEvtType Event)
{
    /* Set the AQ action for the channel */
    uint32 offset = Base + EPWM_O_AQCTLA + ((uint32)ChannelType * 4U);
    HWREGH(offset) = ((uint16)Output << (uint16)Event);
}

#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureInterrupt(uint32 Base, boolean Mode)
{
    /* Enable/Disable the interrupt */
    HWREGH(Base + EPWM_O_ETSEL) =  (HWREGH(Base + EPWM_O_ETSEL) &(~EPWM_ETSEL_INTEN))|((uint16)Mode*EPWM_ETSEL_INTEN);
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetInterruptEventCount(uint32 Base, uint8 EventCount)
{
    /* Set the interrupt count */
    HWREGH(Base + EPWM_O_ETPS) |= EPWM_ETPS_INTPSSEL;
    HWREGH(Base + EPWM_O_ETINTPS) = ((HWREGH(Base + EPWM_O_ETINTPS) & ~EPWM_ETINTPS_INTPRD2_M) | EventCount);
}

#endif

#if (STD_ON == CDD_PWM_DEINIT_API) && (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearInterruptPrescale(uint32 Base)
{
    HWREGH(Base + EPWM_O_ETPS) = (uint16)0U;
}
#endif

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetInterruptSource(uint32 Base,\
                                                                    Cdd_Pwm_InterruptSourceType InterruptSource)
{
    /* Enable events Based on compare A or compare B */
    HWREGH(Base + EPWM_O_ETSEL) &= ~EPWM_ETSEL_INTSELCMP;
    /* Set the interrupt source */
    HWREGH(Base + EPWM_O_ETSEL) = ((HWREGH(Base + EPWM_O_ETSEL) & ~EPWM_ETSEL_INTSEL_M) | (uint16)InterruptSource);
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureMixEvtTriggerSource(uint32 Base, uint16 Event, boolean Mode)
{
    /* Configure the interrupt event sources */
    HWREGH(Base + EPWM_O_ETINTMIXEN) = (HWREGH(Base + EPWM_O_ETINTMIXEN) & ~(Event)) | (Event*Mode);
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearEventTriggerInterruptFlag(uint32 Base)
{
    /*  Clear INT bit of ETCLR register */
    HWREGH(Base + EPWM_O_ETCLR) = EPWM_ETCLR_INT;
}

LOCAL_INLINE FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetCompareShadowMode(uint32 Base,\
                            Cdd_Pwm_OuputChannelType OutputChannel, Cdd_Pwm_CounterCompareLoadModeType LoadMode)
{
    /* Get the register offset,EPWM_O_CMPCTL for A&B or EPWM_O_CMPCTL2 for C&D */
    uint32 offset = (uint32)(Base + (uint32)EPWM_O_CMPCTL);
    uint16 loadoffset = 0U;
    if(CDD_PWM_OUTPUT_B == OutputChannel)
    {
        /* Considering only comapre B */
        loadoffset = 2U;
    }
    /* Disable shadow load mode */
    HWREGH(offset) = ((HWREGH(offset) & ~(0x3U << loadoffset)) | (((uint16)LoadMode & 0x3U) << loadoffset));
}

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDrvObj(Cdd_Pwm_DriverObjType *DrvObj, const Cdd_Pwm_ConfigType *CfgPtr)
{
    /* Set the global driver object pointer */
    Cdd_Pwm_DrvObjPtr = DrvObj;
    /* Initialize Ppb config array */
    Cdd_Pwm_ConfigPtr = CfgPtr;
}

/* Reset the driver object parameters */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_DrvObjInit(void)
{
    uint32 base_addr;
    for (Cdd_Pwm_ChannelType channel_id = 0U; channel_id < CDD_PWM_CHANNEL_COUNT; channel_id++)
    {
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[(Cdd_Pwm_ConfigPtr->channelcfg[channel_id].hw_index)].base_addr;
        Cdd_Pwm_ClearActionQualifierAction(base_addr,Cdd_Pwm_ConfigPtr->channelcfg[channel_id].outputchannel);
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].channel_status = FALSE;
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].channel_update = FALSE;
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].dutycycle = Cdd_Pwm_ConfigPtr->channelcfg[channel_id].dutycycle;
#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].notification_status = (boolean)FALSE;
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].notification_enable = (boolean)FALSE;
        /* Set the rsigin and falling edge events for the channel */
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].rising_event = \
                                                            Cdd_Pwm_GetEventSource(channel_id,CDD_PWM_RISING_EDGE);
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].falling_event = \
                                                            Cdd_Pwm_GetEventSource(channel_id,CDD_PWM_FALLING_EDGE);
#endif
    }

    for(Cdd_Pwm_InstanceType hwunit_id = 0U; hwunit_id < CDD_PWM_COUNT; hwunit_id++)
    {
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].base_addr;
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].period = Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].period;
#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].channel_notification = CDD_PWM_NONE;
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].edgenotifytype = CDD_PWM_EDGE_NONE;
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].notification_active = (uint8)0U;
#endif
        Cdd_Pwm_DrvObjPtr->hwunitobj[hwunit_id].eventcount = 0U;
        /* Set the index of the PWM instance */
        Cdd_Pwm_DrvObjPtr->instanceindex[(Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].instance_id)] = hwunit_id;
        
        HWREGH(base_addr + EPWM_O_AQSFRC) = (uint16)(0x0U);
        HWREGH(base_addr + EPWM_O_AQCSFRC) = (uint16)(0x0U);
    }
}

/* PWM driver initialization */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_HwUnitInit(void)
{
    /* Initialize each HW instance */
    Cdd_Pwm_ChannelType channel_id;
    const Cdd_Pwm_ChannelCfgType* channelcfg;
    uint32 base_addr;
    Cdd_Pwm_TimeBaseCountModeType countmode;

    /* Iterate through each PWM HW Instances */
    for(Cdd_Pwm_InstanceType hwunit_id=0;hwunit_id<CDD_PWM_COUNT;hwunit_id++)
    {
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].base_addr;
        /* Time Base counter mode Based on the symmetry of the waveform */
        countmode = (CDD_PWM_ASYMMETRIC_WAVEFORM == Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].symmetry)?\
                                                        (CDD_PWM_COUNTER_MODE_UP):(CDD_PWM_COUNTER_MODE_UP_DOWN);
        /* Configure the clock divider */
        Cdd_Pwm_SetClockPrescale(base_addr,Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].clockdivider);
        /* Set time Base period value for the PWM hardware unit */
        Cdd_Pwm_SetTimeBasePeriod(base_addr,Cdd_Pwm_ConfigPtr->hwunitcfg[hwunit_id].period);
        /* Set the counter mode Based on the symmetry */
        Cdd_Pwm_SetTimeBaseCounterMode(base_addr,countmode);
        /* Set the time Base initial count value */
        Cdd_Pwm_SetTimeBaseCounter(base_addr,0U);
        /* Clear zero & PRD match event as the interrupt trigger source since they are enabled by default after reset*/
        Cdd_Pwm_ConfigureMixEvtTriggerSource(base_addr,\
                                    ((uint16)CDD_PWM_ETMIX_TBCTR_ZERO | (uint16)CDD_PWM_ETMIX_TBCTR_PERIOD),FALSE);
        /* Set the interrupt trigger source */
        Cdd_Pwm_SetInterruptSource(base_addr,CDD_PWM_INT_TBCTR_ETINTMIX);
    }

    for(channel_id = 0U;channel_id < CDD_PWM_CHANNEL_COUNT;channel_id++)
    {
        channelcfg = &(Cdd_Pwm_ConfigPtr->channelcfg[channel_id]);
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[channelcfg->hw_index].base_addr;
        /* Set the compare counter shadow load mode */
        Cdd_Pwm_SetCompareShadowMode(base_addr,channelcfg->outputchannel,CDD_PWM_COMP_LOAD_ON_CNTR_ZERO);
        /* Enable shadow mode for the AQ actions */
        Cdd_Pwm_SetActionQualifierShadowLoadMode(base_addr,channelcfg->outputchannel,CDD_PWM_AQ_LOAD_ON_CNTR_ZERO);
        /* Get the action qualifier action */
        Cdd_Pwm_GetChannelActionQualifierAction(channel_id);
        /* Set the duty cycle and the compare values based on the specified duty cycle */
        Cdd_Pwm_InitDutyCycle(channel_id,channelcfg->dutycycle);
    }
}

#if(STD_ON == CDD_PWM_DEINIT_API)
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_HwUnitDeinit(void)
{
    uint32 base_addr;
    uint8 hw_index;
    /* Set all the channels output to a IDLE state */
    for(Cdd_Pwm_ChannelType channel_id=0U; channel_id < CDD_PWM_CHANNEL_COUNT; channel_id++)
    {
        hw_index = Cdd_Pwm_ConfigPtr->channelcfg[channel_id].hw_index;
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;
        if(TRUE == Cdd_Pwm_DrvObjPtr->channelobj[channel_id].channel_status)
        {
            /* Set the output to IDLE if the channel is active */
            Cdd_Pwm_SetIdleOutput(channel_id);
            /* Reset the counter compare values to Zero */
            Cdd_Pwm_SetCounterCompareValue(base_addr,Cdd_Pwm_ConfigPtr->channelcfg[channel_id].outputchannel,\
                                                                                                    (uint16)0U);
        }
        #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        /* De-initialize the rising & falling events */
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].rising_event = CDD_PWM_ETMIX_TBCTR_NONE;
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].falling_event = CDD_PWM_ETMIX_TBCTR_NONE;
        #endif
    }

    for(Cdd_Pwm_InstanceType instance=0U; instance < CDD_PWM_COUNT; instance++)
    {
        /* Clear all the registers and bring them to the POR(Power-on-reset) state */
        base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[instance].base_addr;
#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        /* Disable all interrupt */
        Cdd_Pwm_ConfigureInterrupt(base_addr,FALSE);
        /* Reset the interrupt event count */
        Cdd_Pwm_SetInterruptEventCount(base_addr,0U);
        /* Reset the interrupt pre-scale selectiont */
        Cdd_Pwm_ClearInterruptPrescale(base_addr);
        /* Reset the interrupt trigger sources */
        Cdd_Pwm_ConfigureMixEvtTriggerSource(base_addr,\
                                 ((uint16)CDD_PWM_ETMIX_TBCTR_ZERO | (uint16)CDD_PWM_ETMIX_TBCTR_PERIOD),TRUE);
#endif
        /* Clear the interrupt flag */
        Cdd_Pwm_ClearEventTriggerInterruptFlag(base_addr);
    }
}
#endif

#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_NotificationEnable(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,\
                                VAR(Cdd_Pwm_NotificationChannelType,AUTOMATIC) Channel,\
                            VAR(Cdd_Pwm_EdgeNotificationType,AUTOMATIC) Notification,VAR(uint8,AUTOMATIC) IntEvtCount)
{
    uint32 base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    Cdd_Pwm_OuputChannelType outputchannel;

    /* Update notification status of the channels */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].channel_notification =  Channel;
    /* Update the notification type */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].edgenotifytype =  Notification;

    /* Clear the interrupt flag */
    Cdd_Pwm_ClearEventTriggerInterruptFlag(Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr);

    for(Cdd_Pwm_ChannelType channel_id = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].startchannel; \
        ((channel_id <= Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].lastchannel)&&(channel_id < CDD_PWM_CHANNEL_COUNT));\
                    channel_id++)
    {
        outputchannel = Cdd_Pwm_ConfigPtr->channelcfg[channel_id].outputchannel;
        /* Check if the notification is enabled for the specified PWM channel */
        if((Channel == CDD_PWM_BOTH_A_AND_B) || \
            ((Channel == CDD_PWM_CHANNEL_A) && (outputchannel == CDD_PWM_OUTPUT_A)) || \
            ((Channel == CDD_PWM_CHANNEL_B) && (outputchannel == CDD_PWM_OUTPUT_B)))
        {
            /* Notification is enabled when the waveforn has neither 0 percent duty cycle nor 100 percent duty cycle */
            if(TRUE == Cdd_Pwm_DrvObjPtr->channelobj[channel_id].channel_update)
            {
                /* Enable notification only if the channel output waveform has edges */
                Cdd_Pwm_UpdateNotification(channel_id,Notification,TRUE);
                Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].notification_active |= \
                                        (1U << (uint8)(Cdd_Pwm_ConfigPtr->channelcfg[channel_id].outputchannel));
            }
            /* Set the notification enable to TRUE to enable notification if the duty cycle changes */
            Cdd_Pwm_DrvObjPtr->channelobj[channel_id].notification_enable = TRUE;
        }
    }

    /* Set the interrupt count */
    Cdd_Pwm_SetInterruptEventCount(base_addr,IntEvtCount);
    /* Enable the interrupt */
    Cdd_Pwm_ConfigureInterrupt(base_addr,Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].enable_interrupt);
    /* Update the event ocunt for the interruot */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].eventcount = IntEvtCount;
}

/* Disable notification for the channel */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_NotificationDisable(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    for(Cdd_Pwm_ChannelType channel_id = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].startchannel; \
        ((channel_id <= Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].lastchannel)&&(channel_id < CDD_PWM_CHANNEL_COUNT));\
                    channel_id++)
    {
        if(TRUE == Cdd_Pwm_DrvObjPtr->channelobj[channel_id].notification_status)
        {
            /* Disable notification only if the channel notification is enabled */
            Cdd_Pwm_UpdateNotification(channel_id,Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].edgenotifytype,FALSE);
        }
        /* Update the notification enable status of the channel */
        Cdd_Pwm_DrvObjPtr->channelobj[channel_id].notification_enable = FALSE;
    }

    /* Disable the interrupt */
    Cdd_Pwm_ConfigureInterrupt(Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr,FALSE);
    /* Set the interrupt count */
    Cdd_Pwm_SetInterruptEventCount(Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr,0U);
    /* Update the event ocunt for the interruot */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].eventcount = 0U;
    /* Update notification status of the channels */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].channel_notification = CDD_PWM_NONE;
    /* Update the notification type */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].edgenotifytype =  CDD_PWM_EDGE_NONE;
    /* Notification active status is set to zero - no channel with active notification */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].notification_active = 0U;
}

#endif

#if (CDD_PWM_SET_PERIOD_API == STD_ON)
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_UpdatePeriod(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,\
                                            VAR(Cdd_Pwm_PeriodType,AUTOMATIC) Period)
{
    uint32 base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].base_addr;
    /* Update period of the PWM instance */
    Cdd_Pwm_DrvObjPtr->hwunitobj[InstanceId].period = Period;

    /* Set the time Base counter period */
    Cdd_Pwm_SetTimeBasePeriod(base_addr,Period);

    /* Update the duty cycle of the respective channels */
    for (uint8 channelnumber = Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].startchannel;\
    ((channelnumber <= Cdd_Pwm_ConfigPtr->hwunitcfg[InstanceId].lastchannel)&&(channelnumber<CDD_PWM_CHANNEL_COUNT));\
                        channelnumber++)
    {
        /* Update the duty cycle of the channel when the counter becomes Zero */
        Cdd_Pwm_UpdateDutyCycle(channelnumber,Cdd_Pwm_DrvObjPtr->channelobj[channelnumber].dutycycle);
    }
}
#endif

#if (CDD_PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (CDD_PWM_DEINIT_API == STD_ON)
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetIdleOutput(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber)
{
    const Cdd_Pwm_ChannelCfgType *channel_cfg = &(Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber]);
    uint8 hw_index = channel_cfg->hw_index;
    uint32 base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;
    /* Set the AQ action Based on the channel IDLE state */
    Cdd_Pwm_AQOutputType output = (channel_cfg->idlestate == CDD_PWM_HIGH)?\
                                                            (CDD_PWM_AQ_OUTPUT_HIGH):(CDD_PWM_AQ_OUTPUT_LOW);
#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /* Get the notification active status */
    uint8 active = Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_active;
#endif
    /* Set the AQ action to set the IDLE state */
    Cdd_Pwm_SingleActionQualifierAction(base_addr,channel_cfg->outputchannel,output,\
                                                                            CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    if(TRUE == Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber].notification_status)
    {
        /* Disable the notification if the notification is already enabled for the channel */
        Cdd_Pwm_UpdateNotificationAction(ChannelNumber,TRUE,FALSE);
        /* Update the notification active status */
        Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_active = (active & \
                                ~(1U << (uint8)(Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].outputchannel)));
    }
#endif

    /* Set channel update state to FALSE */
    Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber].channel_update = FALSE;
    /* Update the status of the channel -> INACTIVE */
    Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber].channel_status = FALSE;
}
#endif

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_UpdateDutyCycle(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                                                VAR(Cdd_Pwm_DutyCycleType,AUTOMATIC) DutyCycle)
{
    const Cdd_Pwm_ChannelCfgType *channel_cfg = &(Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber]);
    Cdd_Pwm_ChannelObjType *channelobj = &(Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber]);
    Cdd_Pwm_InstanceType hw_index = channel_cfg->hw_index;
    uint32 base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;
    Cdd_Pwm_AQOutputType output;

    #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /* Initialize the notification mode */
    boolean notification_mode = FALSE;
    /* Get the notification active status */
    uint8 active = Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_active;
    #endif

    uint16 compare_value = Cdd_Pwm_GetCompareValue(ChannelNumber,DutyCycle);

    /* Set the duty cycle if the channel is active before this API call */
    if((0U == DutyCycle) || (0U == Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period) || (0U == compare_value))
    {
        /* Get the AQ state based on the polarity of the PWM insance */
        output = (CDD_PWM_LOW == channel_cfg->polarity)?(CDD_PWM_AQ_OUTPUT_HIGH):(CDD_PWM_AQ_OUTPUT_LOW);
        #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        /* Get the current notification status */
        notification_mode = channelobj->notification_status;
        /* Disable notification if enabled previously */
        Cdd_Pwm_UpdateNotificationAction(ChannelNumber,notification_mode,FALSE);
        /* Update the notification active state */
        Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_active = (active & \
                                ~(1U << (uint8)(Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].outputchannel)));
        #endif
        /* Set the AQ event to set the 0% duty cycle - This is effective when counter becomes equal to Zero */
        Cdd_Pwm_SingleActionQualifierAction(base_addr,channel_cfg->outputchannel,output,\
                                                                            CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        /* Update the channel output edge state -  
         * If set to FALSE the output is FLAT, 
         * else edges can be observed in the output 
         */
        channelobj->channel_update = FALSE;
    }
    else if(CDD_PWM_MAX_DUTY_CYCLE == DutyCycle)
    {
        /* Get the AQ state based on the polarity of the PWM insance */
        output = (CDD_PWM_LOW == channel_cfg->polarity)?(CDD_PWM_AQ_OUTPUT_LOW):(CDD_PWM_AQ_OUTPUT_HIGH);
        #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
        /* Get the current notification status */
        notification_mode = channelobj->notification_status;
        /* Disable notification if enabled previously */
        Cdd_Pwm_UpdateNotificationAction(ChannelNumber,notification_mode,FALSE);
        /* Update the notification active state */
        Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_active = (active & \
                                ~(1U << (uint8)(Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].outputchannel)));
        #endif
        /* Set the AQ event to set the 100% duty cycle - This is effective when counter becomes equal to Zero */
        Cdd_Pwm_SingleActionQualifierAction(base_addr,channel_cfg->outputchannel,output,\
                                                                                CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        /* Update the channel output edge state -  
         * If set to FALSE the output is FLAT, 
         * else edges can be observed in the output 
         */
        channelobj->channel_update = FALSE;
    }
    else
    {
        /* If channel is already active with a certain dutycycle(neither 0% nor 100%) then AQ settings need not 
         * to be configured again 
         */
       if(FALSE == channelobj->channel_update)
        {
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            notification_mode = ((TRUE == channelobj->notification_enable) && \
                                                                    (FALSE == channelobj->notification_status));
            /* Update the action qualifier action */
            Cdd_Pwm_UpdateNotificationAction(ChannelNumber,notification_mode,TRUE);
            Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_active |= (1U << (uint8)(channel_cfg->outputchannel));
            #endif
            /* This setting is required for Symmetric waveform, when TBCTR = Zero then state should be configured 
             * since the other two events are Compare Up & compare Down
             */
            Cdd_Pwm_SetActionQualifierAction(base_addr,channel_cfg->outputchannel,channelobj->level1,\
                                                                    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
            /* Set the action qualifier action to get the desired duty cycle */
            Cdd_Pwm_SetActionQualifierAction(base_addr,channel_cfg->outputchannel,channelobj->level1,\
                                                                                            channelobj->outputevt2);
            Cdd_Pwm_SetActionQualifierAction(base_addr,channel_cfg->outputchannel,channelobj->level2,\
                                                                                    channelobj->outputevt1);
            /* Update the channel output edge state -  
            * If set to FALSE the output is FLAT, 
            * else edges can be observed in the output 
            */
            channelobj->channel_update = TRUE;
        }
        /* Set output and duty cycle when the channel is in IDLE state before this API call */
        Cdd_Pwm_SetCounterCompareValue(base_addr,channel_cfg->outputchannel,compare_value);
    }

    /* Update the status of the channel -> ACTIVE */
    channelobj->channel_status = TRUE;
    /* Update duty cycle of the channel */
    channelobj->dutycycle = DutyCycle;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ProcessIsr(Cdd_Pwm_InstanceType InstanceId)
{
     uint8 hw_index;
     /* Check if the PWM instance ID is within the valid range */
    if((InstanceId <= CDD_PWM_INSTANCE_COUNT) && (InstanceId >= 1U))
    {
        hw_index = Cdd_Pwm_DrvObjPtr->instanceindex[InstanceId];
        /* Check if the hardware index is within the valid range */
        if(hw_index < CDD_PWM_COUNT)
        {
            /* Clear the interrupt flag */
            Cdd_Pwm_ClearEventTriggerInterruptFlag(Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr);
            /* Call the notifications if enabled */
            #if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
            if(CDD_PWM_NONE != Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].channel_notification)
            {
                /* Call the notification function if notification is enabled for the channel */
                Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].notification();
            }
            #endif
        }
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
static FUNC(void,CDD_PWM_CODE) Cdd_Pwm_UpdateNotificationAction(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                    VAR(boolean,AUTOMATIC) NotificationMode,VAR(boolean,AUTOMATIC) Mode)
{
    uint8 hw_index = Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].hw_index;
    // uint32 base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;
    Cdd_Pwm_EdgeNotificationType edgenotification = Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].edgenotifytype;
    if(TRUE == NotificationMode)
    {
        if((CDD_PWM_ASYMMETRIC_WAVEFORM == Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].symmetry) && \
                   (FALSE == Mode)  &&  (3U ==  Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].notification_active))
        {
            edgenotification = (CDD_PWM_HIGH == Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].polarity)?\
                                                                    (CDD_PWM_FALLING_EDGE):(CDD_PWM_RISING_EDGE);
            /* If both edges of both channels notification is configured for an Asymmetric waveform then
             * TBPRD event shouldn't be disabled  as the interrupt source since it is shared by with channel */
        }
        Cdd_Pwm_UpdateNotification(ChannelNumber,edgenotification,Mode);
    }
}
#endif

static FUNC(void,CDD_PWM_CODE) Cdd_Pwm_InitDutyCycle(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                                                VAR(Cdd_Pwm_DutyCycleType,AUTOMATIC) DutyCycle)
{
    const Cdd_Pwm_ChannelCfgType *channel_cfg = &(Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber]);
    Cdd_Pwm_ChannelObjType *channelobj = &(Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber]);
    Cdd_Pwm_InstanceType hw_index = channel_cfg->hw_index;
    uint32 base_addr = Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr;
    Cdd_Pwm_AQOutputType output;
    uint16 compare_value = Cdd_Pwm_GetCompareValue(ChannelNumber,DutyCycle);

    /* Set the duty cycle if the channel is active before this API call */
    if((0U == DutyCycle) || (0U == Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period) || (0U == compare_value))
    {
        output = (channel_cfg->polarity == CDD_PWM_LOW)?(CDD_PWM_AQ_OUTPUT_HIGH):(CDD_PWM_AQ_OUTPUT_LOW);
        Cdd_Pwm_SingleActionQualifierAction(base_addr,channel_cfg->outputchannel,output,\
                                                                            CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        /* Update the channel output edge state -  
         * If set to FALSE the output is FLAT, 
         * else edges can be observed in the output 
         */
        channelobj->channel_update = FALSE;
    }
    else if(CDD_PWM_MAX_DUTY_CYCLE == DutyCycle)
    {
        output = (channel_cfg->polarity == CDD_PWM_LOW)?(CDD_PWM_AQ_OUTPUT_LOW):(CDD_PWM_AQ_OUTPUT_HIGH);
        /* Clear all action qualifier action and set only TBPRD action */
        Cdd_Pwm_SingleActionQualifierAction(base_addr,channel_cfg->outputchannel,output,\
                                                                            CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        /* Update the channel output edge state -  
         * If set to FALSE the output is FLAT, 
         * else edges can be observed in the output 
         */
        channelobj->channel_update = FALSE;
    }
    else
    {
        /* Set output and duty cycle when the channel is in IDLE state before this API call */
        Cdd_Pwm_SetCounterCompareValue(base_addr,channel_cfg->outputchannel,compare_value);
        /* This setting is required for Symmetric waveform, when TBCTR = Zero then state should be configured 
        * since the other two events are Compare Up & compare Down
        */
        Cdd_Pwm_SetActionQualifierAction(base_addr,channel_cfg->outputchannel,channelobj->level1,\
                                                                CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);
        /* Set the action qualifier action */
        Cdd_Pwm_SetActionQualifierAction(base_addr,channel_cfg->outputchannel,channelobj->level1,\
                                                                                    channelobj->outputevt2);
        Cdd_Pwm_SetActionQualifierAction(base_addr,channel_cfg->outputchannel,channelobj->level2,\
                                                                                    channelobj->outputevt1);
        /* Update the channel output edge state -  
         * If set to FALSE the output is FLAT, 
         * else edges can be observed in the output 
         */
        channelobj->channel_update = TRUE;
    }
    /* Update the status of the channel -> ACTIVE */
    channelobj->channel_status = TRUE;
    /* Update duty cycle of the channel */
    channelobj->dutycycle = DutyCycle;
}

static FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetCompareValue(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                                    VAR(Cdd_Pwm_DutyCycleType,AUTOMATIC) DutyCycle)
{
    uint16 compare_value = 0U;
    uint32 period;
    uint8 hw_index = Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].hw_index;
    if(CDD_PWM_ASYMMETRIC_WAVEFORM == Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].symmetry)
    {
        /* For an asymmetric waveform: CMP = ((DutyCycle*(TBPRD+1U))/CDD_PWM_MAX_DUTY_CYCLE) */
        period = (uint32)(Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period + 1U);
        /* Update the duty cycle of the channel when the counter is Zero */
        compare_value = (uint16)((period * DutyCycle)/CDD_PWM_MAX_DUTY_CYCLE);
    }
    else
    {
        /* For a symmetric waveform: CMP = (((DutyCycle*TBPRD)/CDD_PWM_MAX_DUTY_CYCLE)) */
        /* Update the duty cycle of the channel when the counter is Zero */
        compare_value = (uint16)((Cdd_Pwm_DrvObjPtr->hwunitobj[hw_index].period*DutyCycle)/CDD_PWM_MAX_DUTY_CYCLE);
    }
    return compare_value;
}

static FUNC(void,CDD_PWM_CODE) \
            Cdd_Pwm_GetChannelActionQualifierAction(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber)
{
    const Cdd_Pwm_ChannelCfgType* channelcfg = &(Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber]);
    Cdd_Pwm_ChannelObjType* channelobj = &(Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber]);

    channelobj->level1 = (CDD_PWM_HIGH == channelcfg->polarity)?(CDD_PWM_AQ_OUTPUT_HIGH):(CDD_PWM_AQ_OUTPUT_LOW);
    channelobj->level2 = (CDD_PWM_HIGH == channelcfg->polarity)?(CDD_PWM_AQ_OUTPUT_LOW):(CDD_PWM_AQ_OUTPUT_HIGH);

    /* Set the action qualifier Based on the count zero */
    channelobj->outputevt1 = (CDD_PWM_OUTPUT_A == channelcfg->outputchannel)?(CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA):\
                                                                (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);
    /* Check the symmetry of the waveform */
    if(CDD_PWM_SYMMETRIC_WAVEFORM == Cdd_Pwm_ConfigPtr->hwunitcfg[(channelcfg->hw_index)].symmetry)
    {
        /* Action qualifier event on the output channel when the waveform is symmetric */
        channelobj->outputevt2 = (CDD_PWM_OUTPUT_A == channelcfg->outputchannel)?\
                                (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA):(CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);
    }
    else
    {
        /* Set the action qualifier based on the count zero if the waveform is asymmetric */
        channelobj->outputevt2 = CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_ZERO;
    }
}

#if(STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
static FUNC(Cdd_Pwm_EvtMixTriggerSourceType,CDD_PWM_CODE) \
                         Cdd_Pwm_GetEventSource(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber,\
                                                        VAR(Cdd_Pwm_EdgeNotificationType,AUTOMATIC) EdgeNotification)
{
    uint8 hw_index = Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].hw_index;
    Cdd_Pwm_OuputChannelType channel = Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].outputchannel;
    Cdd_Pwm_OutputStateType polarity = Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].polarity;
    Cdd_Pwm_EvtMixTriggerSourceType eventsource = CDD_PWM_ETMIX_TBCTR_NONE;

    if(CDD_PWM_BOTH_EDGES != EdgeNotification)
    {
        /* Based on the polairy and symmetry configure the action qualifier events */
        if( ((polarity == CDD_PWM_LOW) && (CDD_PWM_RISING_EDGE == EdgeNotification)) || \
                ((polarity == CDD_PWM_HIGH) && (CDD_PWM_FALLING_EDGE == EdgeNotification)))
        {
            eventsource = (channel == CDD_PWM_OUTPUT_A)?(CDD_PWM_ETMIX_TBCTR_U_CMPA):(CDD_PWM_ETMIX_TBCTR_U_CMPB);
        }
        else if(Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].symmetry == CDD_PWM_SYMMETRIC_WAVEFORM)
        {
            eventsource = (channel == CDD_PWM_OUTPUT_A)?(CDD_PWM_ETMIX_TBCTR_D_CMPA):(CDD_PWM_ETMIX_TBCTR_D_CMPB);
        }
        else
        {
            eventsource = CDD_PWM_ETMIX_TBCTR_ZERO;
        }
    }
    return eventsource;
}

static FUNC(void,CDD_PWM_CODE) Cdd_Pwm_UpdateNotification(VAR(Cdd_Pwm_ChannelType,AUTOMATIC) ChannelNumber, \
                        VAR(Cdd_Pwm_EdgeNotificationType,AUTOMATIC) EdgeNotification, VAR(boolean,AUTOMATIC) Mode)
{
    uint8 hw_index = Cdd_Pwm_ConfigPtr->channelcfg[ChannelNumber].hw_index;
    uint16 event_source;
    /* Configure the interrupt source based on the notification edge type */
    if(CDD_PWM_RISING_EDGE == EdgeNotification)
    {
        event_source =  (uint16)(Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber].rising_event);
    }
    else if(CDD_PWM_FALLING_EDGE == EdgeNotification)
    {
        event_source =  (uint16)(Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber].falling_event);
    }
    else
    {
        event_source =  (((uint16)Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber].rising_event) | \
                                            ((uint16)Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber].falling_event));
    }

    /* Enable/Disable the interrupt events */
    Cdd_Pwm_ConfigureMixEvtTriggerSource(Cdd_Pwm_ConfigPtr->hwunitcfg[hw_index].base_addr,event_source,Mode);
    /* Update the notification status of the channel */
    Cdd_Pwm_DrvObjPtr->channelobj[ChannelNumber].notification_status = Mode;
}
#endif

#define CDD_PWM_STOP_SEC_CODE
#include "Cdd_Pwm_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Priv.c
 *********************************************************************************************************************/
