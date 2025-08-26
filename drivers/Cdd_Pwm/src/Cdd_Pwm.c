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
 *  File:       Cdd_Pwm
 *  Generator:  None
 *
 *  Description: This file contains CDD PWM driver public API function definitions .
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm_Priv.h"
#include "SchM_Cdd_Pwm.h"
#include "Det.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_PWM_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_PWM_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_PWM_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "AUTOSAR Version of CDD_PWM is incorrect"
#endif

/* vendor specific version information check */
#if ((CDD_PWM_SW_MAJOR_VERSION != (2U)) || (CDD_PWM_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Pwm.c and Cdd_Pwm.h are not matching!"
#endif

#if ((CDD_PWM_CFG_MAJOR_VERSION != (2U)) || (CDD_PWM_CFG_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Pwm.c and Cdd_Pwm_Cfg.h are not matching!"
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
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/* Cdd_Pwm Driver initialization variable */
#define CDD_PWM_START_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Pwm_MemMap.h"
static VAR(boolean, CDD_PWM_VAR_INIT) Cdd_Pwm_IsInitialized = FALSE;
#define CDD_PWM_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Pwm_MemMap.h"

/* Cdd_Pwm driver object to store status of PWM instances and channels */
#define CDD_PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Pwm_MemMap.h"
static VAR(Cdd_Pwm_DriverObjType, CDD_PWM_VAR_FAST_INIT) Cdd_Pwm_DrvObj;
#define CDD_PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Pwm_MemMap.h"

/* Cdd_Pwm configuration pointer to access driver configuration. */
#define CDD_PWM_START_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"
P2CONST(Cdd_Pwm_ConfigType, AUTOMATIC, CDD_PWM_CONST) Cdd_Pwm_CfgPtr = NULL_PTR;
#define CDD_PWM_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Pwm_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)

#if(STD_OFF == CDD_PWM_ADVANCED_MODE_API) && (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)

/** \brief This API performs DET error checking for setting interrupt event count
 * 
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] EventCount     Event count for interrupt scale.
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetInterruptEventCountDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                            VAR(uint16,AUTOMATIC) EventCount);

/** \brief Cdd_Pwm_EnableNotification_DetChecks - This API will report DET error for the
 *notification related APIs
 *
 * \param[in] ChannelId  PWM channel identifier
 * \param[in] EdgeNotification Edge Notification type of the channel
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_PWM_CODE)
        Cdd_Pwm_EnableNotification_DetCheck(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                        VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification);

#elif(STD_ON == CDD_PWM_ADVANCED_MODE_API)

/** \brief This API performs DET error checking for setting interrupt event count
 * 
 * \param[in] InstanceId     Numeric ID of the requested PWM instance.
 * \param[in] EventCount     Event count for interrupt scale.
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetInterruptEventCountDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                            VAR(uint16,AUTOMATIC) EventCount);

/** \brief This API performs DET error checking for setting counter compare shadow load mode
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] CompModule Counter compare module type
 * \param[in] LoadMode Counter compare load mode type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetCounterCompareShadowLoadModeDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_CounterCompareModuleType,AUTOMATIC) CompModule,
                                                    VAR(Cdd_Pwm_CounterCompareLoadModeType,AUTOMATIC) LoadMode);

/** \brief This API performs DET error checking for setting action qualifier actions
 *
 * \param[in] EpwmOutput PWM output channel
 * \param[in] Output Action qualifier output type
 * \param[in] Event Action qualifier output event type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetActionQualifierActionDetCheck(VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) EpwmOutput,
                                            VAR(Cdd_Pwm_ActionQualifierOutputType,AUTOMATIC) Output,
                                            VAR(Cdd_Pwm_ActionQualifierOutputEventType,AUTOMATIC) Event);

/** \brief This API performs DET error checking for setting dead band delay polarity
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] DelayMode Dead band delay mode type
 * \param[in] Polarity Dead band polarity type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetDeadBandDelayPolarityDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_DeadBandDelayModeType,AUTOMATIC) DelayMode,
                                            VAR(Cdd_Pwm_DeadBandPolarityType,AUTOMATIC) Polarity);


/** \brief This API performs DET error checking for setting trip zone digital compare event conditions
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] DcType Trip zone digital compare output type
 * \param[in] DcEvent Trip zone digital compare output event type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneDigitalCompareEventConditionDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType,AUTOMATIC) DcType,
                                                VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType,AUTOMATIC) DcEvent);

/** \brief This API performs DET error checking for setting trip zone actions
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] TzEvent Trip zone action event type
 * \param[in] TzAction Trip zone action type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneActionDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_TripZoneActionEventType,AUTOMATIC) TzEvent,
                                    VAR(Cdd_Pwm_TripZoneActionType,AUTOMATIC) TzAction);


/** \brief This API performs DET error checking for setting advanced trip zone actions
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] TzAdvEvent Trip zone advanced event type
 * \param[in] TzAdvAction Trip zone advanced action type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneAdvActionDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_TripZoneAdvancedEventType,AUTOMATIC) TzAdvEvent,
                                        VAR(Cdd_Pwm_TripZoneAdvancedActionType,AUTOMATIC) TzAdvAction);


/** \brief This API performs DET error checking for setting advanced trip zone digital compare actions
 *
 * \param[in] OutputChannel PWM output channel
 * \param[in] TzAdvDCEvent Trip zone advanced digital compare event type
 * \param[in] TzAdvDCAction Trip zone advanced action type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneAdvDigitalCompareActionDetCheck(VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType,AUTOMATIC) TzAdvDCEvent,
                                                VAR(Cdd_Pwm_TripZoneAdvancedActionType,AUTOMATIC) TzAdvDCAction);


/** \brief This API performs DET error checking for setting ADC trigger source
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] AdcSocType ADC start of conversion type
 * \param[in] SocSource ADC start of conversion source type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetAdcTriggerSourceDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                                    VAR(Cdd_Pwm_AdcStartOfConversionSourceType,AUTOMATIC) SocSource);

/** \brief This API performs DET error checking for setting ADC trigger event prescale
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] AdcSocType ADC start of conversion type
 * \param[in] PreScaleCount Prescale count value
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetAdcTriggerEventPrescaleDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                                            VAR(uint16,AUTOMATIC) PreScaleCount);


/** \brief This API performs DET error checking for selecting digital compare trip input
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] TripInput Digital compare trip input type
 * \param[in] DcType Digital compare type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_DigitalCompareTripInputDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_DigitalCompareTripInputType,AUTOMATIC) TripInput,
                                        VAR(uint8,AUTOMATIC) ApiId);

/** \brief This API performs DET error checking for setting digital compare event sync mode
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] OutputChannel PWM output channel
 * \param[in] DcEvent Digital compare event type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                VAR(Cdd_Pwm_DigitalCompareEventType,AUTOMATIC) DcEvent);

/** \brief This API performs DET error checking for setting valley trigger edge counts
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] StartCount Start count value for valley triggering
 * \param[in] StopCount Stop count value for valley triggering
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetValleyTriggerEdgeCountsDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(uint16,AUTOMATIC) StartCount,VAR(uint16,AUTOMATIC) StopCount);

/** \brief This API performs DET error checking for setting XCMP action qualifier actions
 *
 * \param[in] ShadowSet XCMP shadow set type
 * \param[in] Output Action qualifier output type
 * \param[in] Event XCMP AQ output event type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetXCmpActionQualifierActionDetCheck(VAR(Cdd_Pwm_XCmpShadowSetType,AUTOMATIC) ShadowSet,
                                            VAR(Cdd_Pwm_ActionQualifierOutputType,AUTOMATIC) Output,
                                            VAR(Cdd_Pwm_XCmpAqOutputEventType,AUTOMATIC) Event);

/** \brief This API performs DET error checking for setting XCMP shadow repeat buffer count
 * 
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] Bufferset XCMP shadow set type
 * \param[in] Count Number of times Shadow Buffer 2 or 3 is applied (max value is 7)
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetXCmpShadowRepeatBufxCountDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_XCmpShadowSetType,AUTOMATIC) Bufferset,
                                                VAR(uint32,AUTOMATIC) Count);

/** \brief This API performs DET error checking for setting HRPWM counter compare value
 * 
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] OutputChannel Output channel
 * \param[in] ApiId         Service ID
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) Cdd_Pwm_ChannelDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                            VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                                    VAR(uint8, AUTOMATIC) ApiId);

/** \brief This API performs DET error checking for setting HRPWM counter compare value
 * 
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \param[in] EventCount    The ePWM interrupt count value (maximum value is 15)
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetAdcTriggerEventCountInitValueDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                                                VAR(uint16,AUTOMATIC) EventCount);

/** \brief This API performs DET error checking for setting HRPWM counter compare value
 * 
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TripInput     Trip number
 * \param[in] DcType        Digital Compare module
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_TripCombinationInputDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_DcTripInputType,AUTOMATIC) TripInput,
                                                        VAR(uint8,AUTOMATIC) ApiId);

/** \brief This API performs DET error checking for setting mixed event trigger source
 * 
 * \param[in] InstanceId          Numeric ID of the requested PWM instance
 * \param[in] EtMixSignal       The module for which trigger needs to be enabled
 * \param[in] InterruptSource   The Mixed ET interrupt source
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetMixEvtTriggerSourceDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_EtMixSignalSelectType,AUTOMATIC) EtMixSignal,
                                        VAR(Cdd_Pwm_EvtMixTriggerSourceType,AUTOMATIC) InterruptSource);

/** \brief This API performs DET error checking for setting prescaler for the PWM instance
 * 
 * \param[in] InstanceId          Numeric ID of the requested PWM instance
 * \param[in] Prescaler           Time base count pre scale value.
 * \param[in] HighSpeedPrescaler  High speed time base count pre scale value.
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType,CDD_PWM_CODE) Cdd_Pwm_SetClockPrescalerDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_ClockDividerType,AUTOMATIC) Prescaler,
                                                    VAR(Cdd_Pwm_HighSpeedClkDivType,AUTOMATIC) HighSpeedPrescaler);

#endif
#endif

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT) && (STD_OFF == CDD_PWM_ADVANCED_MODE_API) && \
    (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)

/* Function to check for the development errors in the notification APIs */
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_EnableNotification_DetCheck(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                        VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification)
{
    Std_ReturnType return_value = E_NOT_OK;
    
   if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_CHANNEL_COUNT <= ChannelId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_EDGE_NONE <= EdgeNotification)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                                                                            CDD_PWM_E_INVALID_EDGENOTIFICATION);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetInterruptEventCountDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                            VAR(uint16,AUTOMATIC) EventCount)
{
    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNT,CDD_PWM_E_INVALID_ID);
    }
    else if (15U < EventCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNT,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

#endif
 
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT) && (STD_ON == CDD_PWM_ADVANCED_MODE_API)

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetCounterCompareShadowLoadModeDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_CounterCompareModuleType,AUTOMATIC) CompModule,
                                                    VAR(Cdd_Pwm_CounterCompareLoadModeType,AUTOMATIC) LoadMode)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_COMPARE_D < CompModule)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE,CDD_PWM_E_INVALID_CTRCOMPARE);
    }
    else if (CDD_PWM_COMP_LOAD_ON_SYNC_ONLY < LoadMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetActionQualifierActionDetCheck(VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) EpwmOutput,
                                            VAR(Cdd_Pwm_ActionQualifierOutputType,AUTOMATIC) Output,
                                            VAR(Cdd_Pwm_ActionQualifierOutputEventType,AUTOMATIC) Event)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_OUTPUT_B < EpwmOutput)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQACTION,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else if (CDD_PWM_AQ_OUTPUT_TOGGLE < Output)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQACTION,CDD_PWM_E_INVALID_VALUE);
    }
    else if (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB < Event)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQACTION,CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetDeadBandDelayPolarityDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
        VAR(Cdd_Pwm_DeadBandDelayModeType,AUTOMATIC) DelayMode,VAR(Cdd_Pwm_DeadBandPolarityType,AUTOMATIC) Polarity)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBODELAY_POLARITY,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_RED < DelayMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBODELAY_POLARITY,CDD_PWM_E_INVALID_VALUE);
    }
    else if (CDD_PWM_DB_POLARITY_ACTIVE_LOW < Polarity)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBODELAY_POLARITY,CDD_PWM_E_INVALID_POLARITY);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneDigitalCompareEventConditionDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType,AUTOMATIC) DcType,
                                 VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType,AUTOMATIC) DcEvent)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZDC_EVTCONDITION,CDD_PWM_E_INVALID_ID);
    }
    else if ((uint8)CDD_PWM_TZ_DC_OUTPUT_B2 < (uint8)DcType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZDC_EVTCONDITION,CDD_PWM_E_INVALID_VALUE);
    }
    else if ((uint8)CDD_PWM_TZ_EVENT_DCXL_HIGH_DCXH_LOW < (uint8)DcEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZDC_EVTCONDITION,CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneActionDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_TripZoneActionEventType,AUTOMATIC) TzEvent,
                                    VAR(Cdd_Pwm_TripZoneActionType,AUTOMATIC) TzAction)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId) 
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZACTION,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_ACTION_EVENT_DCBEVT2 < TzEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZACTION,CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_TZ_ACTION_DISABLE < TzAction)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZACTION,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneAdvActionDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_TripZoneAdvancedEventType,AUTOMATIC) TzAdvEvent,
                                    VAR(Cdd_Pwm_TripZoneAdvancedActionType,AUTOMATIC) TzAdvAction)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADVACTION,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_ADV_ACTION_EVENT_TZB_D < TzAdvEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADVACTION,CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_TZ_ADV_ACTION_DISABLE < TzAdvAction)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADVACTION,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneAdvDigitalCompareActionDetCheck(VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType,AUTOMATIC) TzAdvDCEvent,
                                                VAR(Cdd_Pwm_TripZoneAdvancedActionType,AUTOMATIC) TzAdvDCAction)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADV_DCACTION,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else if (CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT2_D < TzAdvDCEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADV_DCACTION,CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_TZ_ADV_ACTION_DISABLE < TzAdvDCAction)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADV_DCACTION,CDD_PWM_E_INVALID_VALUE);
    }
    else 
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetAdcTriggerSourceDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                         VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                         VAR(Cdd_Pwm_AdcStartOfConversionSourceType,AUTOMATIC) SocSource)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGSRC,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else if (CDD_PWM_SOC_TBCTR_D_CMPD < SocSource)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGSRC,CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetAdcTriggerEventPrescaleDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                                VAR(uint16,AUTOMATIC) PreScaleCount)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else if (15U < PreScaleCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_DigitalCompareTripInputDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_DigitalCompareTripInputType,AUTOMATIC) TripInput,
                                        VAR(uint8,AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DC_TRIP_COMBINATION < TripInput)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                VAR(Cdd_Pwm_DigitalCompareEventType,AUTOMATIC) DcEvent)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EVTSYNCMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EVTSYNCMODE,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else if (CDD_PWM_DC_EVENT_2 < DcEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EVTSYNCMODE,CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetValleyTriggerEdgeCountsDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(uint16,AUTOMATIC) StartCount,VAR(uint16,AUTOMATIC) StopCount)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYTRIGEDGECNT,CDD_PWM_E_INVALID_ID);
    }
    else if (15U < StartCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYTRIGEDGECNT,CDD_PWM_E_INVALID_VALUE);
    }
    else if (15U < StopCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYTRIGEDGECNT,CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetXCmpActionQualifierActionDetCheck(VAR(Cdd_Pwm_XCmpShadowSetType,AUTOMATIC) ShadowSet,
                              VAR(Cdd_Pwm_ActionQualifierOutputType,AUTOMATIC) Output,
                              VAR(Cdd_Pwm_XCmpAqOutputEventType,AUTOMATIC) Event)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_XCMP_SHADOW3 < ShadowSet)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPAQACTION,CDD_PWM_E_INVALID_SHDSET);
    }
    else if (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8 < Event)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPAQACTION,CDD_PWM_E_INVALID_EVENT);
    }    
    else if (CDD_PWM_AQ_OUTPUT_TOGGLE < Output)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPAQACTION,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetXCmpShadowRepeatBufxCountDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_XCmpShadowSetType,AUTOMATIC) Bufferset,
                                                VAR(uint32,AUTOMATIC) Count)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_XCMP_SHADOW3 < Bufferset) || (Bufferset < CDD_PWM_XCMP_SHADOW2))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT,CDD_PWM_E_INVALID_EVENT);
    }
    else if (7U < Count)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_ChannelDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                            VAR(uint8,AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the output channel doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
                Cdd_Pwm_TripCombinationInputDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_DcTripInputType,AUTOMATIC) TripInput,
                                                        VAR(uint8,AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_DC_TRIPINPUT_COMBO_MAX < (uint16)TripInput) || (TripInput < CDD_PWM_DC_COMBINATIONAL_TRIPIN1))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,ApiId,CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetAdcTriggerEventCountInitValueDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                                                VAR(uint16,AUTOMATIC) EventCount)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else if (15U < EventCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL,CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetMixEvtTriggerSourceDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_EtMixSignalSelectType,AUTOMATIC) EtMixSignal,
                                        VAR(Cdd_Pwm_EvtMixTriggerSourceType,AUTOMATIC) InterruptSource)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_MIXEVTTRIGSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_ETMIX_SOCB < EtMixSignal)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_MIXEVTTRIGSRC,CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_ETMIX_DCAEVT1 < InterruptSource)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_MIXEVTTRIGSRC,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) Cdd_Pwm_SetClockPrescalerDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_ClockDividerType,AUTOMATIC) Prescaler,
                                                    VAR(Cdd_Pwm_HighSpeedClkDivType,AUTOMATIC) HighSpeedPrescaler)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CLOCKPRESCALE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_CLOCK_DIVIDER_128 < Prescaler)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CLOCKPRESCALE,CDD_PWM_E_INVALID_VALUE);
    }
    else if (CDD_PWM_HSCLOCK_DIVIDER_14 < HighSpeedPrescaler)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CLOCKPRESCALE,CDD_PWM_E_INVALID_PRESCALE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType,CDD_PWM_CODE) 
Cdd_Pwm_SetInterruptEventCountDetCheck(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                            VAR(uint16,AUTOMATIC) EventCount)
{
    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNT,CDD_PWM_E_INVALID_ID);
    }
    else if (15U < EventCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNT,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

#endif


/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_PWM_START_SEC_CODE
#include "Cdd_Pwm_MemMap.h"


#if(STD_OFF == CDD_PWM_ADVANCED_MODE_API)

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_Init(P2CONST(Cdd_Pwm_ConfigType, AUTOMATIC, CDD_PWM_CFG) CfgPtr)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized != FALSE)
    {
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_ALREADY_INITIALIZED);
    }
#if (STD_ON == CDD_PWM_PRE_COMPILE_VARIANT)
    else if (CfgPtr != NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is not NULL_PTR for pre-compile
         * build variant */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_PARAM_POINTER);
    }
#else
    else if (CfgPtr == NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is NULL_PTR for non pre-compile
         * build variant*/
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_PARAM_POINTER);
    }
#endif
    else
#endif
    {
        #if (STD_ON == CDD_PWM_PRE_COMPILE_VARIANT)
            /* For pre-compile variant */
            Cdd_Pwm_CfgPtr = &CDD_PWM_CONFIG_PC;
        #else   
            /* For post-build variant */
            Cdd_Pwm_CfgPtr = CfgPtr;
        #endif
        Cdd_Pwm_SetDrvObj(&Cdd_Pwm_DrvObj, Cdd_Pwm_CfgPtr);
        /* Initialize the driver object */
        Cdd_Pwm_DrvObjInit();
        /* Initialize the PWM HW Unit */
        Cdd_Pwm_HwUnitInit();
        /* Update the initialized flag to true */
        Cdd_Pwm_IsInitialized = TRUE;
    }
}

#if (STD_ON == CDD_PWM_DEINIT_API)
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DeInit(void)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DEINIT,CDD_PWM_E_UNINIT);
    }
    else
#endif
    {
        /* Deinitialize the PWM HW Unit */
        Cdd_Pwm_HwUnitDeinit();
        Cdd_Pwm_IsInitialized = FALSE;
    }
    return;
}
#endif

#if (STD_ON == CDD_PWM_SET_DUTY_CYCLE_API)
/* Service to set the duty cycle of the PWM channel */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDutyCycle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId, VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DUTY_CYCLE,CDD_PWM_E_UNINIT);
    }
    else if (ChannelId >= CDD_PWM_CHANNEL_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DUTY_CYCLE,
                                                                    CDD_PWM_E_INVALID_ID); 
    }
    else if (DutyCycle > CDD_PWM_MAX_DUTY_CYCLE)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DUTY_CYCLE,
                                                                            CDD_PWM_E_INVALID_DUTY_CYCLE); 
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_UpdateDutyCycle(ChannelId,DutyCycle);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (CDD_PWM_SET_PERIOD_API == STD_ON)
/* Service to set the period of the PWM hardware unit/instance */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetPeriod(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_PeriodType,AUTOMATIC) Period)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PERIOD,CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PERIOD, CDD_PWM_E_INVALID_ID);
    }
    else if (Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].channelclass != CDD_PWM_VARIABLE_PERIOD)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PERIOD, CDD_PWM_E_CHANNEL_CLASS);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        /* Update the period of the PWM instance */
        Cdd_Pwm_UpdatePeriod(InstanceId, Period);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (CDD_PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/* Service to get the set the PWM channel output to IDLE */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetOutputToIdle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_OUTPUT_TO_IDLE,CDD_PWM_E_UNINIT);
    }
    else if (ChannelId >= CDD_PWM_CHANNEL_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,
                                                        CDD_PWM_SID_SET_OUTPUT_TO_IDLE,CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_SetIdleOutput(ChannelId);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)

/* This function is available in both Advanced and Simple mode */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetInterruptEventCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                            VAR(uint16,AUTOMATIC) EventCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_SetInterruptEventCountDetCheck(InstanceId,EventCount);

    if(E_OK == return_value) 
#endif
    {
        /* Check if interrupt event count can be updated. For that check if the notification is enabled for both the 
         * channels. If atleast one of them is already enabled then report a runtime error 
         */
        /* In simple mode */
        if(TRUE == Cdd_Pwm_DrvObj.hwunitobj[InstanceId].notification_enable)
        {
            /* Report DET error if the channel ID doesn't exist */
            (void)Det_ReportRuntimeError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNT,CDD_PWM_E_BUSY);
        }
        else
        {
            SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
            /* If no channel notification is active then the interrupt event count can be enabled */
            Cdd_Pwm_PrivSetInterruptEventCount(Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr,EventCount);
            /* Update interrupt event count */
            Cdd_Pwm_DrvObj.hwunitobj[InstanceId].inteventcount = EventCount;
            SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        }
    }
}

/* Service to enable the notification of the channel */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_EnableNotification(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                                    VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_EnableNotification_DetCheck(ChannelId, EdgeNotification);
    
    if (E_OK == return_value)
    {
        if ((Cdd_Pwm_NotificationType)NULL_PTR == 
                            Cdd_Pwm_CfgPtr->hwunitcfg[(Cdd_Pwm_CfgPtr->channelcfg[ChannelId].hw_index)].notification)
        {
            /* Report DET error if the notification function doesn't exist */
            (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION,
                                                    CDD_PWM_E_NOTIF_CAPABILITY);
            return_value = E_NOT_OK;
        }
        else if(0U == Cdd_Pwm_DrvObj.hwunitobj[(Cdd_Pwm_CfgPtr->channelcfg[ChannelId].hw_index)].inteventcount)
        {
            /* Report DET error if the notification function doesn't exist */
            (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION,
                                                    CDD_PWM_E_INVALID_VALUE);
            return_value = E_NOT_OK;
        }
        else
        {
            /* No action needed */
        }
    }


    if(E_OK == return_value)
#endif
    {
        if (Cdd_Pwm_DrvObj.channelobj[ChannelId].edgenotifytype == CDD_PWM_EDGE_NONE)
        {
            SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
            /* Enable notification for the channel output */
            Cdd_Pwm_NotificationEnable(ChannelId, EdgeNotification);
            SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* Notification is already enabled disable it first before requesting it again for
             * another channel */
            Det_ReportRuntimeError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                                                                            CDD_PWM_E_NOTIF_ALREADY_ENABLED);
        }
    }
}

/* Service to disable the notification of the channel */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableNotification(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_NOTIFICATION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_CHANNEL_COUNT <= ChannelId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION, CDD_PWM_E_INVALID_ID);
    }
    else if ((Cdd_Pwm_NotificationType)NULL_PTR == 
                            Cdd_Pwm_CfgPtr->hwunitcfg[(Cdd_Pwm_CfgPtr->channelcfg[ChannelId].hw_index)].notification)
    {
        /* Report DET error if the notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_NOTIFICATION,
                                            CDD_PWM_E_NOTIF_CAPABILITY);
    }
    else
#endif
    {
        /* Notification should be disabled for the instance before enabling again for another channel type */
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_NotificationDisable(ChannelId);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}
#endif

#endif

#if (STD_ON == CDD_PWM_VERSION_INFO_API)
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_PWM_DATA) VersionInfo)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* If VersionInfo is NULL */
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VERSION_INFO,
                                CDD_PWM_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfo->vendorID         = CDD_PWM_VENDOR_ID;
        VersionInfo->moduleID         = CDD_PWM_MODULE_ID ;
        VersionInfo->instanceID       = CDD_PWM_INSTANCE_ID ;
        VersionInfo->sw_major_version = (uint8)CDD_PWM_SW_MAJOR_VERSION ;
        VersionInfo->sw_minor_version = (uint8)CDD_PWM_SW_MINOR_VERSION ;
        VersionInfo->sw_patch_version = (uint8)CDD_PWM_SW_PATCH_VERSION ;
    }
}
#endif

#if(STD_ON == CDD_PWM_ADVANCED_MODE_API)

/* This function is available in both Advanced and Simple mode */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetInterruptEventCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                            VAR(uint16,AUTOMATIC) EventCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_SetInterruptEventCountDetCheck(InstanceId,EventCount);

    if(E_OK == return_value) 
#endif
    {
        /* In Advanced mode */
        Cdd_Pwm_PrivSetInterruptEventCount(Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr,EventCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_Init(P2CONST(Cdd_Pwm_ConfigType, AUTOMATIC, CDD_PWM_CFG) CfgPtr)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized != FALSE)
    {
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_ALREADY_INITIALIZED);
    }
#if (STD_ON == CDD_PWM_PRE_COMPILE_VARIANT)
    else if (CfgPtr != NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is not NULL_PTR for pre-compile
         * build variant */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_PARAM_POINTER);
    }
#else
    else if (CfgPtr == NULL_PTR)
    {
        /* Report Det error if the passed configuration pointer is NULL_PTR for non pre-compile
         * build variant*/
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_PARAM_POINTER);
    }
#endif
    else
#endif
    {
        #if (STD_ON == CDD_PWM_PRE_COMPILE_VARIANT)
            /* For pre-compile variant */
            Cdd_Pwm_CfgPtr = &CDD_PWM_CONFIG_PC;
        #else   
            /* For post-build variant */
            Cdd_Pwm_CfgPtr = CfgPtr;
        #endif
        Cdd_Pwm_SetDrvObj(&Cdd_Pwm_DrvObj, Cdd_Pwm_CfgPtr);
        /* Initialize the driver object */
        Cdd_Pwm_DrvObjInit();
        /* Initialize the PWM HW Unit */
        Cdd_Pwm_HwUnitInit();
        /* Update the initialized flag to true */
        Cdd_Pwm_IsInitialized = TRUE;
    }
}

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)

/* Service to enable the notification of the channel */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_EnableNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Pwm_EnableNotification
         */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_NOTIFICATION, CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,
                                                    CDD_PWM_SID_ENABLE_NOTIFICATION,CDD_PWM_E_INVALID_ID);
    }
    else if ((Cdd_Pwm_NotificationType)NULL_PTR == Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].notification)
    {
        /* Report DET error if the group notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                                                                    CDD_PWM_E_NOTIF_CAPABILITY);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_DrvObj.hwunitobj[InstanceId].notification_enable = TRUE;
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}

/* Service to disable the notification of the channel */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DisableNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Pwm_EnableNotification
         */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION, CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION, CDD_PWM_E_INVALID_ID);
    }
    else if ((Cdd_Pwm_NotificationType)NULL_PTR == Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].notification)
    {
        /* Report DET error if the group notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION,
                              CDD_PWM_E_NOTIF_CAPABILITY);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_DrvObj.hwunitobj[InstanceId].notification_enable = FALSE;
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZoneNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised before calling Cdd_Pwm_EnableNotification
         */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TRIPZONE_NOTIFICATION,
                                                                                                CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TRIPZONE_NOTIFICATION,
                                                                                            CDD_PWM_E_INVALID_ID);
    }
    else if ((Cdd_Pwm_TripZoneNotificationType)NULL_PTR == Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].tripzone_notification)
    {
        /* Report DET error if the group notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TRIPZONE_NOTIFICATION,
                                                                                        CDD_PWM_E_NOTIF_CAPABILITY);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_DrvObj.hwunitobj[InstanceId].tripzone_notification = Select;
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}

#endif 


FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetEmulationMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId, 
                                VAR(Cdd_Pwm_EmulationModeType,AUTOMATIC) EmulationMode)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_EMULATION_MODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_EMULATION_MODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        /* Set emulation mode */
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetEmulationMode(base,EmulationMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBaseCounter(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                    VAR(uint16,AUTOMATIC) Count)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TB_COUNTER,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TB_COUNTER,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        /* Write to TBCTR register */
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetTimeBaseCounter(base,Count);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetCountModeAfterSync(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                            VAR(Cdd_Pwm_SyncCountModeType,AUTOMATIC) Mode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_COUNTMODE_AFTERSYNC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_COUNTMODE_AFTERSYNC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNT_MODE_UP_AFTER_SYNC < Mode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_COUNTMODE_AFTERSYNC,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetCountModeAfterSync(InstanceId, Mode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetClockPrescaler(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_ClockDividerType,AUTOMATIC) Prescaler,
                                                    VAR(Cdd_Pwm_HighSpeedClkDivType,AUTOMATIC) HighSpeedPrescaler)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CLOCKPRESCALE,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetClockPrescalerDetCheck(InstanceId,Prescaler,HighSpeedPrescaler);
    }

    if(E_OK == return_value) 
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetClockPrescaler(base,Prescaler,HighSpeedPrescaler);
    }                                    
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceSyncPulse(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_SYNC_PULSE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_SYNC_PULSE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceSyncPulse(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetSyncInPulseSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_SyncInPulseSourceType,AUTOMATIC) Source)
{
    /* Set EPWM Sync-In Source Mode. */
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_SYNC_INPULSE_SOURCE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_SYNC_INPULSE_SOURCE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SYNC_IN_PULSE_SRC_FSIRXD_TRIG1 < Source)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_SYNC_INPULSE_SOURCE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetSyncInPulseSource(InstanceId,Source);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureSyncOutPulseSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                            VAR(Cdd_Pwm_SyncOutPulseSourceType,AUTOMATIC) Source,\
                                                            VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_SYNCOUT_PULSE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_SYNCOUT_PULSE,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_SYNC_OUT_PULSE_ON_SOFTWARE > Source) || (Source > CDD_PWM_SYNC_OUT_PULSE_ON_ALL))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_SYNCOUT_PULSE,CDD_PWM_E_INVALID_EVENT_SRC);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureSyncOutPulseSource(InstanceId,(uint32)Source,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetOneShotSyncOutTrigger(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_OneShotSyncOutTriggerType,AUTOMATIC) Trigger)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ONESHOT_SYNCOUT_TRIGGER,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ONESHOT_SYNCOUT_TRIGGER,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OSHT_SYNC_OUT_TRIG_RELOAD < Trigger)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ONESHOT_SYNCOUT_TRIGGER,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetOneShotSyncOutTrigger(InstanceId,Trigger);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetPeriodLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_PeriodLoadModeType,AUTOMATIC) LoadMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PRDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PRDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_PERIOD_DIRECT_LOAD < LoadMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PRDLOADMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetPeriodLoadMode(InstanceId,LoadMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_PHSSHIFTLOAD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_PHSSHIFTLOAD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigurePhaseShiftLoad(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBaseCounterMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_TimeBaseCountModeType,AUTOMATIC) CounterMode)
{
    uint32 base;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TBCOUNTERMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TBCOUNTERMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_MODE_STOP_FREEZE < CounterMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TBCOUNTERMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetTimeBaseCounterMode(base,CounterMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectPeriodLoadEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_PeriodShadowLoadModeType,AUTOMATIC) ShadowLoadMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_PERIODLOADEVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_PERIODLOADEVT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SHADOW_LOAD_MODE_SYNC < ShadowLoadMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_PERIODLOADEVT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSelectPeriodLoadEvent(InstanceId,ShadowLoadMode);
    }                
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureOneShotSync(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ONESHTSYNC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ONESHTSYNC,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureOneShotSync(InstanceId,Select);
    }    
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_StartOneShotSync(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_START_ONESHTSYNC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_START_ONESHTSYNC,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivStartOneShotSync(InstanceId);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TBCOUNTERVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TBCOUNTERVAL,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetTimeBaseCounterValue(InstanceId);
    }
    return return_value;
}

FUNC(boolean,CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterOverflowStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    boolean return_value = FALSE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TBCOUNTER_OVFSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TBCOUNTER_OVFSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetTimeBaseCounterOverflowStatus(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearTimeBaseCounterOverflowEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_TBOVFEVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_TBOVFEVT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivClearTimeBaseCounterOverflowEvent(InstanceId);
    }
}

FUNC(boolean,CDD_PWM_CODE) Cdd_Pwm_GetSyncStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    boolean return_value = FALSE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GETSYNCSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GETSYNCSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetSyncStatus(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearSyncEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CLEARSYNCEVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CLEARSYNCEVT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivClearSyncEvent(InstanceId);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterDirection(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TBCNTRDIRECTION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TBCNTRDIRECTION,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetTimeBaseCounterDirection(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetPhaseShift(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                        VAR(uint16,AUTOMATIC) PhaseCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PHASESHIFT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_PHASESHIFT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetPhaseShift(InstanceId,PhaseCount);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(uint16,AUTOMATIC) PeriodCount)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TB_PERIOD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TB_PERIOD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetTimeBasePeriod(base,PeriodCount);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TB_PERIOD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TB_PERIOD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetTimeBasePeriod(InstanceId);
    }
    return return_value;
}


FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetCounterCompareShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_CounterCompareModuleType,AUTOMATIC) CompModule, \
                                                    VAR(Cdd_Pwm_CounterCompareLoadModeType,AUTOMATIC) LoadMode)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    
    Std_ReturnType return_value = E_NOT_OK;
    
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetCounterCompareShadowLoadModeDetCheck(InstanceId,CompModule,LoadMode);
    }

    if(E_OK == return_value)
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetCounterCompareShadowLoadMode(base,CompModule,LoadMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_DisableCounterCompareShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_CounterCompareModuleType,AUTOMATIC) CompModule)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_CTRCMP_SHADOWLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_CTRCMP_SHADOWLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_COMPARE_D < CompModule)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_CTRCMP_SHADOWLOADMODE,CDD_PWM_E_INVALID_CTRCOMPARE);
    }
    else 
#endif
    {     
        Cdd_Pwm_PrivDisableCounterCompareShadowLoadMode(InstanceId,CompModule);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetCounterCompareValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                VAR(Cdd_Pwm_CounterCompareModuleType,AUTOMATIC) CompModule,VAR(uint16,AUTOMATIC) CompCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CTRCMPVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CTRCMPVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_COMPARE_D < CompModule)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CTRCMPVAL,CDD_PWM_E_INVALID_CTRCOMPARE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetCounterCompareValue(InstanceId,CompModule,CompCount);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetCounterCompareValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_CounterCompareModuleType,AUTOMATIC) CompModule)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_CTRCMPVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_CTRCMPVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_COMPARE_D < CompModule)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_CTRCMPVAL,CDD_PWM_E_INVALID_CTRCOMPARE);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetCounterCompareValue(InstanceId,CompModule);
    }
    return return_value;
}

FUNC(boolean,CDD_PWM_CODE) Cdd_Pwm_GetCounterCompareShadowStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel)
{
    boolean return_value = FALSE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_CTRCMP_SHDSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_CTRCMP_SHDSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the compare module are not CMPA & CMPB */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_CTRCMP_SHDSTATUS,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetCounterCompareShadowStatus(InstanceId,OutputChannel);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureLinkDutyHR(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_LINKDUTYHR,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_LINKDUTYHR,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureLinkDutyHR(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(Cdd_Pwm_ActionQualifierLoadModeType,AUTOMATIC) LoadMode)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_AQSHDLOADMODE);

    if ((E_OK == return_value) && (CDD_PWM_AQ_LOAD_ON_SYNC_ONLY < LoadMode))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQSHDLOADMODE,
                                                                             CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        base  = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetActionQualifierShadowLoadMode(base,OutputChannel,LoadMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_DisableActionQualifierShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_AQSHDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_AQSHDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_AQSHDLOADMODE,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivDisableActionQualifierShadowLoadMode(InstanceId,OutputChannel);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierT1TriggerSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_ActionQualifierTriggerSourceType,AUTOMATIC) Trigger)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQT1TRIGSRC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQT1TRIGSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT < Trigger)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQT1TRIGSRC,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierT1TriggerSource(InstanceId,Trigger);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierT2TriggerSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_ActionQualifierTriggerSourceType,AUTOMATIC) Trigger)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQT2TRIGSRC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQT2TRIGSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT < Trigger)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQT2TRIGSRC,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierT2TriggerSource(InstanceId,Trigger);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) EpwmOutput,
                            VAR(Cdd_Pwm_ActionQualifierOutputType,AUTOMATIC) Output,
                            VAR(Cdd_Pwm_ActionQualifierOutputEventType,AUTOMATIC) Event)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQACTION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQACTION,CDD_PWM_E_INVALID_ID);
    }
    else
    {
        return_value = Cdd_Pwm_SetActionQualifierActionDetCheck(EpwmOutput,Output,Event);
    }

    if(E_OK == return_value)
#endif
    {
       Cdd_Pwm_PrivSetActionQualifierAction(InstanceId,EpwmOutput,Output,Event); 
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(Cdd_Pwm_ActionQualifierEventActionType,AUTOMATIC) Action)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)

   Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_AQACTION_COMPLETE);

    if ((E_OK == return_value) && (CDD_PWM_AQEVT_ACTION_MAX < (uint16)Action))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQACTION_COMPLETE,CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierActionComplete(InstanceId,OutputChannel,(uint16)Action);
    }
}

FUNC(void,CDD_PWM_CODE) 
    Cdd_Pwm_SetAdditionalActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                            VAR(Cdd_Pwm_AdditionalActionQualifierEventActionType,AUTOMATIC) Action)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)

   Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_AQACTION_COMPLETE);

    if ((E_OK == return_value) && (CDD_PWM_ADDITIONAL_AQEVT_ACTION_MAX < (uint16)Action))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADDITIONALAQACTION_COMPLETE,CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetAdditionalActionQualifierActionComplete(InstanceId,OutputChannel,(uint16)Action);
    }
}

FUNC(void,CDD_PWM_CODE) 
Cdd_Pwm_SetActionQualifierContSwForceShadowMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_ActionQualifierContForceType,AUTOMATIC) Mode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQCNTSWFRC_SHDMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQCNTSWFRC_SHDMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_AQ_SW_IMMEDIATE_LOAD < Mode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQCNTSWFRC_SHDMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierContSwForceShadowMode(InstanceId,Mode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierContSwForceAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(Cdd_Pwm_ActionQualifierSwOutputType,AUTOMATIC) Output)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
   Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_AQCNTSWFRC_ACTION);

    if ((E_OK == return_value) && (CDD_PWM_AQ_SW_OUTPUT_HIGH < Output))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQCNTSWFRC_ACTION,
                                                                            CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierContSwForceAction(InstanceId,OutputChannel,Output);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                    VAR(Cdd_Pwm_ActionQualifierOutputType,AUTOMATIC) Output)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_AQSWACTION);

    if ((E_OK == return_value) && (CDD_PWM_AQ_OUTPUT_TOGGLE < Output))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_AQSWACTION,
                                                                             CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierSwAction(InstanceId,OutputChannel,Output);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_AQSWACTION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_AQSWACTION,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_AQSWACTION,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceActionQualifierSwAction(InstanceId,OutputChannel);
    }
}

/* Dead Band Module related APIs */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDeadBandOutputSwapMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                                        VAR(boolean,AUTOMATIC) EnableSwapMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBOUTPUTSWAPMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBOUTPUTSWAPMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBOUTPUTSWAPMODE,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDeadBandOutputSwapMode(InstanceId,OutputChannel,EnableSwapMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDeadBandDelayMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                VAR(Cdd_Pwm_DeadBandDelayModeType,AUTOMATIC) DelayMode, VAR(boolean,AUTOMATIC) EnableDelayMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBODELAYMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBODELAYMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_RED < DelayMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBODELAYMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDeadBandDelayMode(InstanceId,DelayMode,EnableDelayMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDeadBandDelayPolarity(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
        VAR(Cdd_Pwm_DeadBandDelayModeType,AUTOMATIC) DelayMode,VAR(Cdd_Pwm_DeadBandPolarityType,AUTOMATIC) Polarity)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBODELAY_POLARITY,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetDeadBandDelayPolarityDetCheck(InstanceId,DelayMode,Polarity);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetDeadBandDelayPolarity(InstanceId,DelayMode,Polarity);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetRisingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_REDB_DELAYINPUT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_REDB_DELAYINPUT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_REDB_DELAYINPUT,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetRisingEdgeDeadBandDelayInput(InstanceId,OutputChannel);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetFallingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                     VAR(Cdd_Pwm_DeadBandDelayInputType,AUTOMATIC) Input)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FEDB_DELAYINPUT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FEDB_DELAYINPUT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_INPUT_DB_RED < Input)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FEDB_DELAYINPUT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {   
        Cdd_Pwm_PrivSetFallingEdgeDeadBandDelayInput(InstanceId,Input);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_DeadBandControlLoadModeType,AUTOMATIC) LoadMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBCTL_SHDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBCTL_SHDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_LOAD_FREEZE < LoadMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBCTL_SHDLOADMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDeadBandControlShadowLoadMode(InstanceId,LoadMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_DisableDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_DBCTL_SHDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_DBCTL_SHDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivDisableDeadBandControlShadowLoadMode(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DeadBandDelayLoadModeType,AUTOMATIC) LoadMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_RED_COUNTSHDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_RED_COUNTSHDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DELAY_LOAD_FREEZE < LoadMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_RED_COUNTSHDLOADMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetRisingEdgeDelayCountShadowLoadMode(InstanceId,LoadMode);
    }
}

FUNC(void,CDD_PWM_CODE) 
        Cdd_Pwm_DisableRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_RED_COUNTSHDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_RED_COUNTSHDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivDisableRisingEdgeDelayCountShadowLoadMode(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_DeadBandDelayLoadModeType,AUTOMATIC) LoadMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FED_COUNTSHDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FED_COUNTSHDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DELAY_LOAD_FREEZE < LoadMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FED_COUNTSHDLOADMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetFallingEdgeDelayCountShadowLoadMode(InstanceId,LoadMode);
    }
}

FUNC(void,CDD_PWM_CODE) 
                Cdd_Pwm_DisableFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_FED_COUNTSHDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_DISABLE_FED_COUNTSHDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivDisableFallingEdgeDelayCountShadowLoadMode(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDeadBandCounterClock(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_DeadBandClockModeType,AUTOMATIC) ClockMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBCTRCLK,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBCTRCLK,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_COUNTER_CLOCK_HALF_CYCLE < ClockMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DBCTRCLK,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDeadBandCounterClock(InstanceId,ClockMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetRisingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                    VAR(uint16,AUTOMATIC) RedCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_REDCOUNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_REDCOUNT,CDD_PWM_E_INVALID_ID);
    }
    else if (0x4000U <= RedCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_REDCOUNT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetRisingEdgeDelayCount(InstanceId,RedCount);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetFallingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(uint16,AUTOMATIC) FedCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FEDCOUNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FEDCOUNT,CDD_PWM_E_INVALID_ID);
    }
    else if (0x4000U <= FedCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_FEDCOUNT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetFallingEdgeDelayCount(InstanceId,FedCount);
    }
}

/* Chopper module related APIs */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureChopper(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_CHOPPER,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_CHOPPER,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureChopper(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetChopperDutyCycle(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(uint16,AUTOMATIC) DutyCycleCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_DC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_DC,CDD_PWM_E_INVALID_ID);
    }
    else if (7U <= DutyCycleCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_DC,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetChopperDutyCycle(InstanceId,DutyCycleCount);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetChopperFreq(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                            VAR(uint16,AUTOMATIC) FreqDiv)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_FREQ,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_FREQ,CDD_PWM_E_INVALID_ID);
    }
    else if (7U < FreqDiv)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_FREQ,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetChopperFreq(InstanceId,FreqDiv);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetChopperFirstPulseWidth(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                    VAR(uint16,AUTOMATIC) FirstPulseWidth)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_FIRSTPULWIDTH,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_FIRSTPULWIDTH,CDD_PWM_E_INVALID_ID);
    }
    else if (15U < FirstPulseWidth)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CHOPPER_FIRSTPULWIDTH,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetChopperFirstPulseWidth(InstanceId,FirstPulseWidth);
    }
}

/*  Trip Zone module related APIs */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureTripZoneSignals(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(Cdd_Pwm_TzSignalType,AUTOMATIC) TzSignal, VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZSIGNALS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZSIGNALS,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZSIGNAL_MAX < (uint16)TzSignal) || (CDD_PWM_TZ_SIGNAL_CBC1 > TzSignal))
    {
        /* Report DET error if the signal is not valid (ideally signal value is a power of 2) */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZSIGNALS,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureTripZoneSignals(InstanceId,(uint16)TzSignal,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureTripZone2Signals(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(Cdd_Pwm_TzCapEvtType,AUTOMATIC) TzSignal, VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZ2SIGNALS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZ2SIGNALS,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZCAPEVTSIG_MAX < (uint16)TzSignal) || (CDD_PWM_TZ_SIGNAL_CAPEVT_CBC > TzSignal))
    {
        /* Report DET error if the signal is not valid (ideally signal value is a power of 2) */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZ2SIGNALS,CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureTripZone2Signals(InstanceId,(uint16)TzSignal,Select);
    }
}

FUNC(void,CDD_PWM_CODE) 
Cdd_Pwm_SetTripZoneDigitalCompareEventCondition(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType,AUTOMATIC) DcType,
                                 VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType,AUTOMATIC) DcEvent)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZDC_EVTCONDITION,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetTripZoneDigitalCompareEventConditionDetCheck(InstanceId,DcType,DcEvent);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetTripZoneDigitalCompareEventCondition(InstanceId,DcType,DcEvent);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZADVACTION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZADVACTION,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureTripZoneAdvAction(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTripZoneAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_TripZoneActionEventType,AUTOMATIC) TzEvent,
                                                VAR(Cdd_Pwm_TripZoneActionType,AUTOMATIC) TzAction)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZACTION,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetTripZoneActionDetCheck(InstanceId,TzEvent,TzAction);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetTripZoneAction(InstanceId,TzEvent,TzAction);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_TripZoneAdvancedEventType,AUTOMATIC) TzAdvEvent,
                                                VAR(Cdd_Pwm_TripZoneAdvancedActionType,AUTOMATIC) TzAdvAction)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADVACTION,CDD_PWM_E_UNINIT);
        return_value = E_NOT_OK;
    }
    else
    {
        return_value = Cdd_Pwm_SetTripZoneAdvActionDetCheck(InstanceId,TzAdvEvent,TzAdvAction);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetTripZoneAdvAction(InstanceId,TzAdvEvent,TzAdvAction);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetTripZoneAdvDigitalCompareAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                            VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType,AUTOMATIC) TzAdvDCEvent,
                                                    VAR(Cdd_Pwm_TripZoneAdvancedActionType,AUTOMATIC) TzAdvDCAction)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADV_DCACTION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADV_DCACTION,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_TZADV_DCACTION,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
    {
        return_value = 
            Cdd_Pwm_SetTripZoneAdvDigitalCompareActionDetCheck(OutputChannel,TzAdvDCEvent,TzAdvDCAction);
    }

    if(E_OK == return_value) 
#endif
    {
        Cdd_Pwm_PrivSetTripZoneAdvDigitalCompareAction(InstanceId,OutputChannel,TzAdvDCEvent,TzAdvDCAction);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureTripZoneInterrupt(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(Cdd_Pwm_TzInterruptSourceType,AUTOMATIC) TzInterrupt,VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZINT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZINT,CDD_PWM_E_INVALID_ID);
    }
    else if ((TzInterrupt < CDD_PWM_TZ_INTERRUPT_CBC) || ((uint16)TzInterrupt > CDD_PWM_TZINT_SRC_MAX) )
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TZINT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureTripZoneInterrupt(InstanceId,(uint16)TzInterrupt,Select);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TZFLAGSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_TZFLAGSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        return_value = Cdd_Pwm_PrivGetTripZoneFlagStatus(InstanceId);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
    return return_value;
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetCycleByCycleTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_CBCTZ_FLAGSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_CBCTZ_FLAGSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetCycleByCycleTripZoneFlagStatus(InstanceId);
    }
    return return_value;
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetOneShotTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_OSTZ_FLAGSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_OSTZ_FLAGSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetOneShotTripZoneFlagStatus(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectCycleByCycleTripZoneClearEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_CbcTripZoneClearModeType,AUTOMATIC) ClearEvent)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_CBCTZCLREVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_CBCTZCLREVT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_ZERO_PERIOD < ClearEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_CBCTZCLREVT,CDD_PWM_E_INVALID_EVENT);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSelectCycleByCycleTripZoneClearEvent(InstanceId,ClearEvent);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearTripZoneFlag(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_TripZoneFlagType,AUTOMATIC) TzFlags)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_TZFLAG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_TZFLAG,CDD_PWM_E_INVALID_ID);
    }
    else if(((uint16)TzFlags > CDD_PWM_TZFLAG_MAX) || (TzFlags < CDD_PWM_TZ_INTERRUPT))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_TZFLAG,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivClearTripZoneFlag(InstanceId,(uint16)TzFlags);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearCycleByCycleTripZoneFlag(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(Cdd_Pwm_CbcTzFlagType,AUTOMATIC) TzCbcFlags)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_CBCTZFLAG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_CBCTZFLAG,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZCBC_INTFLAGS_MAX < (uint16)TzCbcFlags) || (TzCbcFlags < CDD_PWM_TZ_CBC_FLAG_1))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_CBCTZFLAG,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivClearCycleByCycleTripZoneFlag(InstanceId,(uint16)TzCbcFlags);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearOneShotTripZoneFlag(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(Cdd_Pwm_OneshotTzFlagType,AUTOMATIC) TzOstFlags)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_OSTZFLAG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_OSTZFLAG,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZOST_INTFLAGS_MAX < (uint16)TzOstFlags) || (TzOstFlags < CDD_PWM_TZ_OST_FLAG_OST1))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_OSTZFLAG,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivClearOneShotTripZoneFlag(InstanceId,(uint16)TzOstFlags);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceTripZoneEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(Cdd_Pwm_TripZoneForceEventType,AUTOMATIC) TzForceEvent)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_TZEVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_TZEVT,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZFRC_FLAGS_MAX < ((uint16)TzForceEvent)) || 
                                                (TzForceEvent < CDD_PWM_TZ_FORCE_EVENT_CBC))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_TZEVT,CDD_PWM_E_INVALID_EVENT);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceTripZoneEvent(InstanceId,(uint16)TzForceEvent);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureTripOutSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                        VAR(Cdd_Pwm_SelectTripOutSourceType,AUTOMATIC) TzTripOut,VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TRIPOUTSRC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TRIPOUTSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_TRIPOUT_CAPEVT < TzTripOut)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_TRIPOUTSRC,CDD_PWM_E_INVALID_EVENT);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureTripOutSource(InstanceId,TzTripOut,Select);
    }
}

/* Event Trigger related APIs */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureInterrupt(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_INTERRUPT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_INTERRUPT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivConfigureInterrupt(base,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetInterruptSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_InterruptSourceType,AUTOMATIC) InterruptSource)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTSRC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_INT_TBCTR_D_CMPD < InterruptSource)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTSRC,CDD_PWM_E_INVALID_EVENT);
    }
    else 
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetInterruptSource(base,InterruptSource);
    }
}

FUNC(boolean,CDD_PWM_CODE) Cdd_Pwm_GetEventTriggerInterruptStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    boolean return_value = FALSE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_EVTTRIGINTSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_EVTTRIGINTSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetEventTriggerInterruptStatus(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearEventTriggerInterruptFlag(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint32 base;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_EVTTRIGINTFLAG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_EVTTRIGINTFLAG,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        base  = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivClearEventTriggerInterruptFlag(base);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_INTEVTCOUNTINIT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_INTEVTCOUNTINIT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureInterruptEventCountInit(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_INTEVTCOUNTINIT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_INTEVTCOUNTINIT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceInterruptEventCountInit(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetInterruptEventCountInitValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(uint16,AUTOMATIC) EventCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNTINITVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNTINITVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (15U < EventCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_INTEVTCOUNTINITVAL,CDD_PWM_E_INVALID_EVENT);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetInterruptEventCountInitValue(InstanceId,EventCount);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetInterruptEventCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_INTEVTCNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_INTEVTCNT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetInterruptEventCount(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceEventTriggerInterrupt(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_EVTTRIGINT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_EVTTRIGINT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceEventTriggerInterrupt(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetMixEvtTriggerSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_EtMixSignalSelectType,AUTOMATIC) EtMixSignal,
                                                    VAR(Cdd_Pwm_EvtMixTriggerSourceType,AUTOMATIC) InterruptSource)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_MIXEVTTRIGSRC,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetMixEvtTriggerSourceDetCheck(InstanceId,EtMixSignal,InterruptSource);
    }
    
    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetMixEvtTriggerSource(InstanceId,EtMixSignal,InterruptSource);
    }
}

/* Adc SOC configuration related APIs */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureAdcTrigger(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
        VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ADCTRIG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ADCTRIG,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ADCTRIG,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureAdcTrigger(InstanceId,AdcSocType,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetAdcTriggerSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                         VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                         VAR(Cdd_Pwm_AdcStartOfConversionSourceType,AUTOMATIC) SocSource)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGSRC,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetAdcTriggerSourceDetCheck(InstanceId,AdcSocType,SocSource);
    } 

    if(E_OK == return_value) 
#endif
    {
        Cdd_Pwm_PrivSetAdcTriggerSource(InstanceId,AdcSocType,SocSource);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetAdcTriggerEventPrescale(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                                VAR(uint16,AUTOMATIC) PreScaleCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetAdcTriggerEventPrescaleDetCheck(InstanceId,AdcSocType,PreScaleCount);
    }

    if(E_OK == return_value) 
#endif
    {
        Cdd_Pwm_PrivSetAdcTriggerEventPrescale(InstanceId,AdcSocType,PreScaleCount);
    }
}

FUNC(boolean,CDD_PWM_CODE) Cdd_Pwm_GetAdcTriggerFlagStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType)
{
    boolean return_value = FALSE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_ADCTRIGFLAGSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_ADCTRIGFLAGSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_ADCTRIGFLAGSTATUS,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetAdcTriggerFlagStatus(InstanceId,AdcSocType);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearAdcTriggerFlag(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                         VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_ADCTRIGFLAG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_ADCTRIGFLAG,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_ADCTRIGFLAG,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivClearAdcTriggerFlag(InstanceId,AdcSocType);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ADCTRIGEVTCNTINIT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ADCTRIGEVTCNTINIT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ADCTRIGEVTCNTINIT,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureAdcTriggerEventCountInit(InstanceId,AdcSocType,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_ADCTRIGEVTCNTINIT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_ADCTRIGEVTCNTINIT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_ADCTRIGEVTCNTINIT,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceAdcTriggerEventCountInit(InstanceId,AdcSocType);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetAdcTriggerEventCountInitValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType,
                                      VAR(uint16,AUTOMATIC) EventCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL,
                                    CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetAdcTriggerEventCountInitValueDetCheck(InstanceId,AdcSocType,EventCount);
    }
    
    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetAdcTriggerEventCountInitValue(InstanceId,AdcSocType,EventCount);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetAdcTriggerEventCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType)
{
    uint16 eventcount = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_ADCTRIGEVTCNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_ADCTRIGEVTCNT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_ADCTRIGEVTCNT,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else 
#endif
    {
        eventcount = Cdd_Pwm_PrivGetAdcTriggerEventCount(InstanceId,AdcSocType);
    }
    return eventcount;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceAdcTrigger(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_AdcStartOfConversionType,AUTOMATIC) AdcSocType)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_ADCTRIGGER,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_ADCTRIGGER,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_ADCTRIGGER,CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceAdcTrigger(InstanceId,AdcSocType);
    }
}

/* Digital Compare module related APIs */

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectDigitalCompareTripInput(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_DigitalCompareTripInputType,AUTOMATIC) TripInput,
                                   VAR(Cdd_Pwm_DigitalCompareType,AUTOMATIC) DcType)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_DigitalCompareTripInputDetCheck(InstanceId,TripInput,CDD_PWM_SID_SEL_DCTRIPINPUT);
    
    if ((E_OK == return_value) && (CDD_PWM_DC_TYPE_DCBL < DcType))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SEL_DCTRIPINPUT,CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectDigitalCompareTripInput(InstanceId,(uint16)TripInput,DcType);
    }
}

/* DCFILT */
FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDigitalCompareBlankingWindow(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_BLANKWINDOW,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_BLANKWINDOW,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareBlankingWindow(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDigitalCompareWindowInverseMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_WINDOWINVMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_WINDOWINVMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareWindowInverseMode(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareBlankingEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_DigitalCompareBlankingPulseType,AUTOMATIC) BlankingPulse)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_BLANKEVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_BLANKEVT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DC_WINDOW_START_BLANK_PULSE_MIX < BlankingPulse)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_BLANKEVT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareBlankingEvent(InstanceId,BlankingPulse);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareFilterInput(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_DigitalCompareFilterInputType,AUTOMATIC) FilterInput)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_FILTERINPUT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_FILTERINPUT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DC_WINDOW_SOURCE_DCBEVT2 < FilterInput)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_FILTERINPUT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareFilterInput(InstanceId,FilterInput);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDigitalCompareEdgeFilter(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_EDGEFILTER,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_EDGEFILTER,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareEdgeFilter(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareEdgeFilterMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_DigitalCompareEdgeFilterModeType,AUTOMATIC) EdgeMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EDGEFILMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EDGEFILMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DC_EDGEFILT_MODE_BOTH < EdgeMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EDGEFILMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareEdgeFilterMode(InstanceId,EdgeMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(uint16,AUTOMATIC) EdgeCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EDGEFILEDGECNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EDGEFILEDGECNT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareEdgeFilterEdgeCount(InstanceId,EdgeCount);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DC_EDGEFILEDGECNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DC_EDGEFILEDGECNT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareEdgeFilterEdgeCount(InstanceId);
    }
    return return_value;
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareEdgeFilterEdgeStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DC_EDGEFILEDGESTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DC_EDGEFILEDGESTATUS,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareEdgeFilterEdgeStatus(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareWindowOffset(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(uint16,AUTOMATIC) WindowOffsetCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_WINOFFSET,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_WINOFFSET,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareWindowOffset(InstanceId,WindowOffsetCount);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareWindowLength(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(uint16,AUTOMATIC) WindowLengthCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_WINLENGTH,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_WINLENGTH,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareWindowLength(InstanceId,WindowLengthCount);
    }
}

FUNC(uint16,CDD_PWM_CODE) 
        Cdd_Pwm_GetDigitalCompareBlankingWindowOffsetCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DC_BLANKWINOFFSETCNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DC_BLANKWINOFFSETCNT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareBlankingWindowOffsetCount(InstanceId);
    }
    return return_value;
}

FUNC(uint16,CDD_PWM_CODE) 
    Cdd_Pwm_GetDigitalCompareBlankingWindowLengthCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DC_BLANKWINLENGTH,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DC_BLANKWINLENGTH,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareBlankingWindowLengthCount(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareEventSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                  VAR(Cdd_Pwm_DigitalCompareEventType,AUTOMATIC) DcEvent,
                                  VAR(Cdd_Pwm_DigitalCompareEventSourceType,AUTOMATIC) DcEventSource)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_DC_EVTSOURCE);

    if(E_OK == return_value)
    {
        if (CDD_PWM_DC_EVENT_2 < DcEvent)
        {
            /* Report DET error if the channel ID doesn't exist */
            (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EVTSOURCE,
                                    CDD_PWM_E_INVALID_EVENT);
            return_value = E_NOT_OK;
        }
        else if (CDD_PWM_DC_EVENT_SOURCE_FILT_SIGNAL < DcEventSource)
        {
            /* Report DET error if the channel ID doesn't exist */
            (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EVTSOURCE,
                                                                    CDD_PWM_E_INVALID_VALUE);
            return_value = E_NOT_OK;
        }
        else
        {
            return_value = E_OK;
        }
    }
    
    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareEventSource(InstanceId,OutputChannel,DcEvent,DcEventSource);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareEventSyncMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                    VAR(Cdd_Pwm_DigitalCompareEventType,AUTOMATIC) DcEvent,
                                    VAR(Cdd_Pwm_DigitalCompareSyncModeType,AUTOMATIC) SyncMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EVTSYNCMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_DC_EVENT_INPUT_NOT_SYNCED < SyncMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DC_EVTSYNCMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(InstanceId,OutputChannel,DcEvent);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareEventSyncMode(InstanceId,OutputChannel,DcEvent,SyncMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDigitalCompareAdcTrigger(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_ADCTRIG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_ADCTRIG,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_ADCTRIG,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareAdcTrigger(InstanceId,OutputChannel,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDigitalCompareSyncEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_SYNCEVENT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_SYNCEVENT,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DC_SYNCEVENT,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareSyncEvent(InstanceId,OutputChannel,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareCBCLatchMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                   VAR(Cdd_Pwm_DigitalCompareEventType,AUTOMATIC) DcEvent,
                                   VAR(Cdd_Pwm_DigitalCompareCbcLatchModeType,AUTOMATIC) LatchMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DCCBC_LATCHMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_DC_CBC_LATCH_ENABLED < LatchMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DCCBC_LATCHMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(InstanceId,OutputChannel,DcEvent);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareCBCLatchMode(InstanceId,OutputChannel,DcEvent,LatchMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectDigitalCompareCBCLatchClearEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                              VAR(Cdd_Pwm_DigitalCompareEventType,AUTOMATIC) DcEvent,
                              VAR(Cdd_Pwm_DigitalCompareCBCLatchClearEventType,AUTOMATIC) ClearEvent)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DCCBC_LATCHCLREVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_DC_CBC_LATCH_CLR_ON_CNTR_ZERO_PERIOD < ClearEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DCCBC_LATCHCLREVT,CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(InstanceId,OutputChannel,DcEvent);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectDigitalCompareCBCLatchClearEvent(InstanceId,OutputChannel,DcEvent,ClearEvent);
    }
}

FUNC(boolean,CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareCBCLatchStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                     VAR(Cdd_Pwm_DigitalCompareEventType,AUTOMATIC) DcEvent)
{
    boolean status = FALSE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_GET_DCCBC_LATCHSTATUS);

    if ((E_OK == return_value) && (CDD_PWM_DC_EVENT_2 < DcEvent))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DCCBC_LATCHSTATUS,
                                                                             CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        status = Cdd_Pwm_PrivGetDigitalCompareCBCLatchStatus(InstanceId,OutputChannel,DcEvent);
    }
    return status;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDigitalCompareCounterCapture(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DCCTRCAP,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DCCTRCAP,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareCounterCapture(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDigitalCompareCounterShadowMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(boolean,AUTOMATIC) EnableShadowMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DCCTRSHDMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DCCTRSHDMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareCounterShadowMode(InstanceId,EnableShadowMode);
    }
}

FUNC(boolean,CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareCaptureStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    boolean return_value = FALSE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DCCAPSTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DCCAPSTATUS,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareCaptureStatus(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) 
        Cdd_Pwm_ConfigureDigitalCompareCounterCaptureMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(boolean,AUTOMATIC) DisableClearMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DCCTRCAPMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DCCTRCAPMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareCounterCaptureMode(InstanceId,DisableClearMode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearDigitalCompareCaptureStatusFlag(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_DCCAPSTATUSFLAG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEAR_DCCAPSTATUSFLAG,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivClearDigitalCompareCaptureStatusFlag(InstanceId);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareCaptureCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DCCAPCNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_DCCAPCNT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareCaptureCount(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) 
    Cdd_Pwm_ConfigureDigitalCompareTripCombinationInput(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_DcTripInputType,AUTOMATIC) TripInput,
                                                        VAR(Cdd_Pwm_DigitalCompareType,AUTOMATIC) DcType,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_TripCombinationInputDetCheck(InstanceId,TripInput,\
                                                                            CDD_PWM_SID_CONFIGURE_DCTRIPCOMBINPUT);

    if ((E_OK == return_value) && (CDD_PWM_DC_TYPE_DCBL < DcType))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DCTRIPCOMBINPUT,\
                                                                             CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value) 
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareTripCombinationInput(InstanceId,(uint16)TripInput,DcType,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureCaptureInEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_CAPINEVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_CAPINEVT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureCaptureInEvent(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigCaptureGateInputPolarity(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_SelectCaptureGateInputPolarityType,AUTOMATIC) PolaritySelect)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_CAPGATEINPUTPOL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_CAPGATEINPUTPOL,CDD_PWM_E_INVALID_ID);
    }
    else if (PolaritySelect < CDD_PWM_CAPGATE_INPUT_SYNC_INVERT)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_CAPGATEINPUTPOL,CDD_PWM_E_INVALID_POLARITY);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigCaptureGateInputPolarity(InstanceId,PolaritySelect);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_InvertCaptureInputPolarity(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_SelectCaptureInputPolarityType,AUTOMATIC) PolaritySelect)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INVERT_CAPGINPUTPOLARITY,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INVERT_CAPGINPUTPOLARITY,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_CAPTURE_INPUT_CAPIN_SYNC_INVERT < PolaritySelect)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INVERT_CAPGINPUTPOLARITY,CDD_PWM_E_INVALID_POLARITY);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivInvertCaptureInputPolarity(InstanceId,PolaritySelect);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureIndependentPulseLogic(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_INDPULSELOGIC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_INDPULSELOGIC,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureIndependentPulseLogic(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceCaptureEventLoad(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_CAPEVTLOAD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_CAPEVTLOAD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceCaptureEventLoad(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectCaptureTripInput(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_DigitalCompareTripInputType,AUTOMATIC) TripInput,
                            VAR(Cdd_Pwm_CaptureInputType,AUTOMATIC) DcType)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_DigitalCompareTripInputDetCheck(InstanceId,TripInput,CDD_PWM_SID_SEL_CAPTRIPINPUT);
    
    if ((E_OK == return_value) && (CDD_PWM_CAPTURE_GATE < DcType))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SEL_CAPTRIPINPUT,CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectCaptureTripInput(InstanceId,(uint16)TripInput,DcType);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureCaptureTripCombinationInput(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_DcTripInputType,AUTOMATIC) TripInput,
                                                        VAR(Cdd_Pwm_CaptureInputType,AUTOMATIC) DcType,
                                                                    VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_TripCombinationInputDetCheck(InstanceId,TripInput,\
                                                                            CDD_PWM_SID_CONFIGURE_CAPTRIPCOMBINPUT);

    if ((E_OK == return_value) && (CDD_PWM_CAPTURE_GATE < DcType))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_CAPTRIPCOMBINPUT,\
                                                                             CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivConfigureCaptureTripCombinationInput(InstanceId,(uint16)TripInput,DcType,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureValleyCapture(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_VALLEYCAPTURE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_VALLEYCAPTURE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureValleyCapture(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_StartValleyCapture(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_START_VALLEYCAPTURE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_START_VALLEYCAPTURE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivStartValleyCapture(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetValleyTriggerSource(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_ValleyTriggerSourceType,AUTOMATIC) Trigger)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYTRIGSRC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYTRIGSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_VALLEY_TRIGGER_EVENT_DCBEVT2 < Trigger)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYTRIGSRC,CDD_PWM_E_INVALID_EVENT);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetValleyTriggerSource(InstanceId,Trigger);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetValleyTriggerEdgeCounts(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(uint16,AUTOMATIC) StartCount,VAR(uint16,AUTOMATIC) StopCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYTRIGEDGECNT,CDD_PWM_E_UNINIT);
    }
    else
    {
        return_value = Cdd_Pwm_SetValleyTriggerEdgeCountsDetCheck(InstanceId,StartCount,StopCount);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetValleyTriggerEdgeCounts(InstanceId,StartCount,StopCount);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureValleyHwDelay(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{    
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_VALLEYHWDELAY,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_VALLEYHWDELAY,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureValleyHwDelay(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetValleySwDelayValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                            VAR(uint16,AUTOMATIC) DelayOffsetValue)
{ 
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYSWDELAYVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYSWDELAYVAL,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetValleySwDelayValue(InstanceId,DelayOffsetValue);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetValleyDelayDivider(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_ValleyDelayModeType,AUTOMATIC) DelayMode)
{ 
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYDELAYDIVIDER,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYDELAYDIVIDER,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_4_SW_DELAY < DelayMode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_VALLEYDELAYDIVIDER,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetValleyDelayDivider(InstanceId,DelayMode);
    }
}

FUNC(boolean,CDD_PWM_CODE) Cdd_Pwm_GetValleyEdgeStatus(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                VAR(Cdd_Pwm_ValleyCounterEdgeType,AUTOMATIC) Edge)
{
    boolean return_value = FALSE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VALLEYEDGESTATUS,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VALLEYEDGESTATUS,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_VALLEY_COUNT_STOP_EDGE < Edge)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VALLEYEDGESTATUS,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetValleyEdgeStatus(InstanceId,Edge);
    }
    return return_value;
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetValleyCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VALLEYCOUNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VALLEYCOUNT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetValleyCount(InstanceId);
    }
    return return_value;
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetValleyHwDelay(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VALLEYHWDELAY,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_VALLEYHWDELAY,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetValleyHwDelay(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureGlobalLoad(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{ 
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_GLBLOAD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_GLBLOAD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureGlobalLoad(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetGlobalLoadTrigger(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_GlobalLoadTriggerType,AUTOMATIC) LoadTrigger)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_GLBLOADTRIG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_GLBLOADTRIG,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_GL_LOAD_PULSE_GLOBAL_FORCE < LoadTrigger)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_GLBLOADTRIG,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetGlobalLoadTrigger(InstanceId,LoadTrigger);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetGlobalLoadEventPrescale(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                    VAR(uint16,AUTOMATIC) PrescalePulseCount)
{

    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_GLBLOADEVTPRESCALE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_GLBLOADEVTPRESCALE,CDD_PWM_E_INVALID_ID);
    }
    else if (8U <= PrescalePulseCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_GLBLOADEVTPRESCALE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetGlobalLoadEventPrescale(InstanceId,PrescalePulseCount);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetGlobalLoadEventCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_GLBLOADEVTCNT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_GLBLOADEVTCNT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetGlobalLoadEventCount(InstanceId);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureGlobalLoadOneShotMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_GLBLOADOSMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_GLBLOADOSMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureGlobalLoadOneShotMode(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetGlobalLoadOneShotLatch(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_GLBLOADOSLATCH,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_GLBLOADOSLATCH,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetGlobalLoadOneShotLatch(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceGlobalLoadOneShotEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_GLBLOADOSEVT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_GLBLOADOSEVT,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceGlobalLoadOneShotEvent(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureGlobalLoadRegisters(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                            VAR(Cdd_Pwm_GlobalLoadType,AUTOMATIC) LoadRegister,
                                                            VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_GLBLOADREG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_GLBLOADREG,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_GLB_LOAD_MAX < (uint16)LoadRegister) || (LoadRegister < CDD_PWM_GL_REGISTER_TBPRD_TBPRDHR))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_GLBLOADREG,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureGlobalLoadRegisters(InstanceId,(uint16)LoadRegister,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_LockRegisters(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                        VAR(Cdd_Pwm_LockRegisterGroupType,AUTOMATIC) RegisterGroup)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_LOCKREGISTER,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_LOCKREGISTER,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_REGISTER_GROUP_DIGITAL_COMPARE < RegisterGroup)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_LOCKREGISTER,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivLockRegisters(InstanceId,RegisterGroup);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureXCmpMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_XCMPMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_XCMPMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureXCmpMode(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureSplitXCmp(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_SPLICTXCMP,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_SPLICTXCMP,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureSplitXCmp(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_AllocAXCmp(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_XCmp_AllocCmpAType,AUTOMATIC) Alloctype)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ALLOC_AXCMP,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ALLOC_AXCMP,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XCMP_8_CMPA < Alloctype)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ALLOC_AXCMP,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivAllocAXCmp(InstanceId,Alloctype);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_AllocBXCmp(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_XCmp_AllocCmpBType,AUTOMATIC) Alloctype)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ALLOC_BXCMP,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ALLOC_BXCMP,CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_XCMP_8_CMPB < Alloctype) || (CDD_PWM_XCMP_5_CMPB > Alloctype ))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ALLOC_BXCMP,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivAllocBXCmp(InstanceId,Alloctype);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetXCmpRegValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_XCmpRegType,AUTOMATIC) XcmpReg,VAR(uint16,AUTOMATIC) XCmpValue)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPREGVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPREGVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XTBPRD_SHADOW3 < XcmpReg)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPREGVAL,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetXCmpRegValue(InstanceId,XcmpReg,XCmpValue);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetCmpShadowRegValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                        VAR(Cdd_Pwm_XCompareRegType,AUTOMATIC) XCmpReg,VAR(uint32,AUTOMATIC) XCmpValue)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CMPSHDREGVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CMPSHDREGVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_CMPD_SHADOW3 < XCmpReg)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CMPSHDREGVAL,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetXCmpShadowRegValue(InstanceId,XCmpReg,XCmpValue);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetXMinMaxRegValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
            VAR(Cdd_Pwm_XMinMaxRegType,AUTOMATIC) XMinMaxReg,VAR(uint16,AUTOMATIC) XCmpValue)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XMINMAXREGVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XMINMAXREGVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XMIN_SHADOW3 < XMinMaxReg)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XMINMAXREGVAL,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetXMinMaxRegValue(InstanceId,XMinMaxReg,XCmpValue);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetXCmpActionQualifierAction(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_XCmpShadowSetType,AUTOMATIC) ShadowSet,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(Cdd_Pwm_ActionQualifierOutputType,AUTOMATIC) Output,
                                                        VAR(Cdd_Pwm_XCmpAqOutputEventType,AUTOMATIC) Event)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPAQACTION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPAQACTION,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPAQACTION,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
    {
        return_value = Cdd_Pwm_SetXCmpActionQualifierActionDetCheck(ShadowSet,Output,Event);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetXCmpActionQualifierAction(InstanceId,ShadowSet,OutputChannel,Output,Event);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_EnableXLoad(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_XLOAD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_ENABLE_XLOAD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivEnableXLoad(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceXLoad(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_XLOAD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FRC_XLOAD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceXLoad(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetXCmpLoadMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_XCmpLoadModeType,AUTOMATIC) Mode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XCMP_LOADMULTIPLE < Mode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPLOADMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetXCmpLoadMode(InstanceId,Mode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetXCmpShadowLevel(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,\
                                                VAR(Cdd_Pwm_XCmpShadowLevelType,AUTOMATIC) Level)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHDMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHDMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XCMP_SHADOWLEVEL_3 < Level)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHDMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetXCmpShadowLevel(InstanceId,Level);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_XCmpShadowBufPtrType,AUTOMATIC) Ptr)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHDBUFPTR_LOADONCE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHDBUFPTR_LOADONCE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_THREE < Ptr)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHDBUFPTR_LOADONCE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetXCmpShadowBufPtrLoadOnce(InstanceId,Ptr);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetXCmpShadowRepeatBufxCount(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_XCmpShadowSetType,AUTOMATIC) Bufferset,
                                                    VAR(uint32,AUTOMATIC) Count)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT,CDD_PWM_E_UNINIT);
        return_value = E_NOT_OK;
    }
    else
    {
        return_value = Cdd_Pwm_SetXCmpShadowRepeatBufxCountDetCheck(InstanceId,Bufferset,Count);
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetXCmpShadowRepeatBufxCount(InstanceId,Bufferset,Count);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureMinimumDeadBand(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_MINDB,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_MINDB,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_MINDB,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureMinimumDeadBand(InstanceId,OutputChannel,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_InvertMinimumDeadBandSignal(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(boolean,AUTOMATIC) Invert)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INVERT_MINDB,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INVERT_MINDB,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_INVERT_MINDB,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivInvertMinimumDeadBandSignal(InstanceId,OutputChannel,Invert);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectMinimumDeadBandAndOrLogic(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(boolean,AUTOMATIC) Logic)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_MINDB_ANDOR_LOGIC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_MINDB_ANDOR_LOGIC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_MINDB_ANDOR_LOGIC,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSelectMinimumDeadBandAndOrLogic(InstanceId,OutputChannel,Logic);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectMinimumDeadBandBlockingSignal(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                                VAR(boolean,AUTOMATIC) BlockingSignal)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_MINDB_BLOCKSIGNAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_MINDB_BLOCKSIGNAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_MINDB_BLOCKSIGNAL,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSelectMinimumDeadBandBlockingSignal(InstanceId,OutputChannel,BlockingSignal);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectMinimumDeadBandReferenceSignal(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                          VAR(Cdd_Pwm_MindbReferenceSignalType,AUTOMATIC) ReferenceSignal)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_MINDB_BANDREFSIGNAL);

    if ((E_OK == return_value) && (CDD_PWM_MINDB_SEL_OUTXBAR_NONE <= ReferenceSignal))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_MINDB_BANDREFSIGNAL,
                                                                             CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    } 

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectMinimumDeadBandReferenceSignal(InstanceId,OutputChannel,ReferenceSignal);
    }
}

FUNC(uint16,CDD_PWM_CODE) Cdd_Pwm_GetMinDeadBandDelay(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel)
{
    uint16 return_value = 0U;
    #if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_MINDB_DELAY,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_MINDB_DELAY,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_MINDB_DELAY,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetMinDeadBandDelay(InstanceId,OutputChannel);
    }
    return return_value;
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetMinimumDeadBandDelay(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                             VAR(uint16,AUTOMATIC) Delay)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_MINDB_DELAY,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_MINDB_DELAY,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_MINDB_DELAY,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetMinDeadBandDelay(InstanceId,OutputChannel,Delay);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureIllegalComboLogic(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ICL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ICL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_ICL,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureIllegalComboLogic(InstanceId,OutputChannel,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectXbarInput(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                                    VAR(Cdd_Pwm_XbarInputType,AUTOMATIC) XbarInput)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SELECT_XBARINPUT);

    if ((E_OK == return_value) && (CDD_PWM_MINDB_ICL_XBAR_NONE < XbarInput))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SELECT_XBARINPUT,
                                                                        CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    } 

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectXbarInput(InstanceId,OutputChannel,XbarInput);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetLutDecX(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                VAR(Cdd_Pwm_LutDecXType,AUTOMATIC) Decx,VAR(uint32,AUTOMATIC) Force)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_LUTDECX);

    if ((E_OK == return_value) && (CDD_PWM_MINDB_ICL_LUT_NONE <= Decx))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_LUTDECX,
                                                                        CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    } 

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetLutDecX(InstanceId,OutputChannel,Decx,Force);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DEMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DEMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDiodeEmulationMode(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_DiodeEmulationModeType,AUTOMATIC) Mode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DEMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DEMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DIODE_EMULATION_OST < Mode)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DEMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDiodeEmulationMode(InstanceId,Mode);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDiodeEmulationReentryDelay(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                VAR(uint16,AUTOMATIC) Delay)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DE_REENTRYDELAY,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DE_REENTRYDELAY,CDD_PWM_E_INVALID_ID);
    }
    else if (255U < Delay)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DE_REENTRYDELAY,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDiodeEmulationReentryDelay(InstanceId,Delay);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDiodeEmulationTripLowSources(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                     VAR(Cdd_Pwm_DETripLowSourceType,AUTOMATIC) Source)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DE_TRIPLOWSRC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DE_TRIPLOWSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DE_TRIPL_SRC_NONE <= Source)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DE_TRIPLOWSRC,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDiodeEmulationTripLowSources(InstanceId,Source);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ConfigureDiodeEmulationTripHighSources(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                                    VAR(Cdd_Pwm_DETripHighSourceType,AUTOMATIC) Source)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DE_TRIPHIGHSRC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DE_TRIPHIGHSRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_NONE <= Source)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DE_TRIPHIGHSRC,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDiodeEmulationTripHighSources(InstanceId,Source);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectDiodeEmulationPwmSignal(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                VAR(Cdd_Pwm_DiodeEmulationSignalType,AUTOMATIC) DiodeEmuationsignal)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_DEPWMSIGNAL);

    if ((E_OK == return_value) && (CDD_PWM_DE_HIGH < DiodeEmuationsignal))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DEPWMSIGNAL,
                                                                        CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    } 

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectDiodeEmulationPwmSignal(InstanceId,OutputChannel,DiodeEmuationsignal);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SelectDiodeEmulationTripSignal(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(Cdd_Pwm_DiodeEmulationTripSrcType,AUTOMATIC) TripSrc)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_DETRIPSIG);
    if ((E_OK == return_value) && (CDD_PWM_DE_SRC_TRIPL < TripSrc))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DETRIPSIG,CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectDiodeEmulationTripSignal(InstanceId,OutputChannel,TripSrc);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_NoBypassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_NBPDELOGIC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_NBPDELOGIC,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivNoBypassDiodeEmulationLogic(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ByPassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_BPDELOGIC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_BPDELOGIC,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivbypassDiodeEmulationLogic(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ForceDiodeEmulationActive(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_DE_ACTIVE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_FORCE_DE_ACTIVE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivForceDiodeEmulationActive(InstanceId);
    }
}

FUNC(void,CDD_PWM_CODE) 
Cdd_Pwm_ConfigureDiodeEmulationMonitorModeControl(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                        VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DEMONITORMODECTRL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_DEMONITORMODECTRL,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivConfigureDiodeEmulationMonitorModeControl(InstanceId,Select);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDiodeEmulationMonitorModeStep(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                    VAR(Cdd_Pwm_DiodeEmulationDirectionType,AUTOMATIC) Direction, VAR(uint8,AUTOMATIC) StepSize)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DEMONITORMODESTEP,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DEMONITORMODESTEP,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DE_COUNT_DOWN < Direction)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DEMONITORMODESTEP,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDiodeEmulationMonitorModeStep(InstanceId,Direction,StepSize);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_SetDiodeEmulationMonitorCounterThreshold(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                VAR(uint16,AUTOMATIC) Threshold)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DE_MONITORCNTRTHRESHOLD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_DE_MONITORCNTRTHRESHOLD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivSetDiodeEmulationMonitorCounterThreshold(InstanceId,Threshold);
    }
}

FUNC(void,CDD_PWM_CODE) Cdd_Pwm_ClearDiodeEmulationActiveFlag(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEARDEACTIVEFLAG,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CLEARDEACTIVEFLAG,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivClearDiodeEmulationActiveFlag(InstanceId);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                    VAR(uint32,AUTOMATIC) PhaseCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_PHASESHIFT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_PHASESHIFT,CDD_PWM_E_INVALID_ID);
    }
    else if (0x1000000U <= PhaseCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_PHASESHIFT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetPhaseShift(InstanceId,PhaseCount);
    }
}


FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetHiResPhaseShiftOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                        VAR(uint16, AUTOMATIC) HrPhaseCount)
{

#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESSHIFT,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESSHIFT,CDD_PWM_E_INVALID_ID);
    }
    else if (256U <= HrPhaseCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESSHIFT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResPhaseShiftOnly(InstanceId,HrPhaseCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                        VAR(uint32,AUTOMATIC) PeriodCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_TBPRD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_TBPRD,CDD_PWM_E_INVALID_ID);
    }
    else if (0x1000000U <= PeriodCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_TBPRD,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetTimeBasePeriod(InstanceId,PeriodCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                            VAR(uint16, AUTOMATIC) HrPeriodCount)
{

#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESTBPRD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESTBPRD,CDD_PWM_E_INVALID_ID);
    }
    else if (256U <= HrPeriodCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESTBPRD,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResTimeBasePeriodOnly(InstanceId,HrPeriodCount);
    }

}

FUNC(uint32, CDD_PWM_CODE) Cdd_Pwm_HrpwmGetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 return_value = 0U;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_GET_HRPWM_TBPRD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_GET_HRPWM_TBPRD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivHrpwmGetTimeBasePeriod(InstanceId);
    }
    return return_value;
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_HrpwmGetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_GET_HRPWM_HIRESTBPRD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_GET_HRPWM_HIRESTBPRD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivHrpwmGetHiResTimeBasePeriodOnly(InstanceId);
    }
    return return_value;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetMepEdgeSelect(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(Cdd_Pwm_HrpwmMepEdgeModeType, AUTOMATIC) MepEdgeMode)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,
                                                                CDD_PWM_SET_HRPWM_MEPEDGESELECT);

    if ((E_OK == return_value) && (CDD_PWM_HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE < MepEdgeMode))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SET_HRPWM_MEPEDGESELECT,
                                                                        CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;                                               
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetMepEdgeSelect(InstanceId,OutputChannel,MepEdgeMode);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetMepControlMode(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(Cdd_Pwm_HrpwmMepCtrlModeType, AUTOMATIC) MepCtrlMode)
{

#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,
                                                                CDD_PWM_SID_SET_HRPWM_MEPCTLMODE);

    if ((E_OK == return_value) && (CDD_PWM_HRPWM_MEP_PHASE_CTRL < MepCtrlMode))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_MEPCTLMODE,
                                                                        CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;                                               
    }

    if(E_OK == return_value)
#endif
    {
         Cdd_Pwm_PrivHrpwmSetMepControlMode(InstanceId,OutputChannel,MepCtrlMode);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetCounterCompareShadowLoadEvent(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,
                                                            CDD_PWM_SID_SET_HRPWM_SETCTRCMPSHDLOADEVT);

    if ((E_OK == return_value) && (CDD_PWM_HRPWM_LOAD_ON_CMP_EQ < LoadEvent))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_MEPCTLMODE,
                                CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;                                               
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetCounterCompareShadowLoadEvent(InstanceId,OutputChannel,LoadEvent);
    }   
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, 
                                                VAR(boolean, AUTOMATIC) EnableOutputSwap)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_SETOUTPUTSWAPMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_SETOUTPUTSWAPMODE,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetOutputSwapMode(InstanceId,EnableOutputSwap);
    }
    
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetChannelBOutputPath(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, 
                                                        VAR(Cdd_Pwm_HrpwmChannelBOutputType, AUTOMATIC) OutputOnB)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_SETCHANNELBOUTPATH,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_SETCHANNELBOUTPATH,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_OUTPUT_ON_B_INV_A < OutputOnB)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_SETCHANNELBOUTPATH,CDD_PWM_E_INVALID_EVENT);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetChannelBOutputPath(InstanceId,OutputOnB);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmConfigureAutoConversion(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{

#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_HRPWM_AUTOCONVERSION,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_CONFIGURE_HRPWM_AUTOCONVERSION,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmConfigureAutoConversion(InstanceId,Select);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmConfigurePeriodControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CONFIGURE_HRPWMPRDCONTROL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CONFIGURE_HRPWMPRDCONTROL,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmConfigurePeriodControl(InstanceId,Select);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                                VAR(boolean,AUTOMATIC) Select)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CONFIGURE_HRPWM_PHSSHIFTLOAD,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_CONFIGURE_HRPWM_PHSSHIFTLOAD,CDD_PWM_E_INVALID_ID);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmConfigurePhaseShiftLoad(InstanceId,Select);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetSyncPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_HrpwmSyncPulseSourceType, AUTOMATIC) SyncPulseSource)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_SYNCPULSESRC,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_SYNCPULSESRC,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_PWMSYNC_SOURCE_COMPD_DOWN < SyncPulseSource)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_SYNCPULSESRC,CDD_PWM_E_INVALID_EVENT);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetSyncPulseSource(InstanceId,SyncPulseSource);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetTranslatorRemainder(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                        VAR(uint16, AUTOMATIC) TrRemVal)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_TRANSREM,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_TRANSREM,CDD_PWM_E_INVALID_ID);
    }
    else if (2048U <= TrRemVal)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_TRANSREM,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetTranslatorRemainder(InstanceId,TrRemVal);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetCounterCompareValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                        VAR(uint32, AUTOMATIC) CompareCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,CDD_PWM_SID_SET_HRPWMCTRCMP);

    if ((E_OK == return_value) && (0x1000000U <= CompareCount))
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWMCTRCMP,
                                                        CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;                                               
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetCounterCompareValue(InstanceId,OutputChannel,CompareCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel,
                                                    VAR(uint16, AUTOMATIC) HrCompCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId,OutputChannel,
                                                            CDD_PWM_SID_SET_HRPWM_HIRESCTRCMP);

    if ((E_OK == return_value) && (256U <= HrCompCount))
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESCTRCMP,
                                                                    CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if(E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResCounterCompareValueOnly(InstanceId,OutputChannel,HrCompCount);
    }

}

FUNC(uint32, CDD_PWM_CODE) Cdd_Pwm_HrpwmGetCounterCompareValue(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel)
{
    uint32 return_value = 0U;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_HRPWM_CTRCMPVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_HRPWM_CTRCMPVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SET_HRPWM_MEPEDGESELECT,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivHrpwmGetCounterCompareValue(InstanceId,OutputChannel);
    }
    return return_value;
}

FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType,AUTOMATIC) InstanceId,
                                                        VAR(Cdd_Pwm_OutputChannelType,AUTOMATIC) OutputChannel)
{
    uint16 return_value = 0U;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_HRPWM_HIRESCTRCMPVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_GET_HRPWM_HIRESCTRCMPVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SET_HRPWM_MEPEDGESELECT,CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else 
#endif
    {
        return_value = Cdd_Pwm_PrivGetHiResCounterCompareValueOnly(InstanceId,OutputChannel);
    }
    return return_value;
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetRisingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                            VAR(uint32,AUTOMATIC) RedCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_RED,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_RED,CDD_PWM_E_INVALID_ID);
    }
    else if (0x200000U <= RedCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_RED,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetRisingEdgeDelay(InstanceId,RedCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetHiResRisingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                                VAR(uint16, AUTOMATIC) HrRedCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESRED,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESRED,CDD_PWM_E_INVALID_ID);
    }
    else if (128U <= HrRedCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESRED,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResRisingEdgeDelayOnly(InstanceId,HrRedCount);
    }

}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetFallingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                        VAR(uint32,AUTOMATIC) FedCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_FED,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_FED,CDD_PWM_E_INVALID_ID);
    }
    else if (0x200000U <= FedCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_FED,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetFallingEdgeDelay(InstanceId,FedCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetHiResFallingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                                    VAR(uint16, AUTOMATIC) HrFedCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESFED,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESFED,CDD_PWM_E_INVALID_ID);
    }
    else if (128U <= HrFedCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESFED,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResFallingEdgeDelayOnly(InstanceId,HrFedCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetMepStep(VAR(Cdd_Pwm_HrpwmCalInstanceType, AUTOMATIC) InstanceId,
                                                                                VAR(uint16, AUTOMATIC) MepCount)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_MEPSTEP,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HRPWM_CAL_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_MEPSTEP,CDD_PWM_E_INVALID_ID);
    }
    else if (256U <= MepCount)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_MEPSTEP,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetMepStep(InstanceId,MepCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetDeadbandMepEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_HrpwmMepDeadBandEdgeModeType, AUTOMATIC) MepDbEdge)
{

#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_DBMEPEDGESEL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_DBMEPEDGESEL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_DB_MEP_CTRL_RED_FED < MepDbEdge)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SET_HRPWM_MEPEDGESELECT,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetDeadbandMEPEdgeSelect(InstanceId,MepDbEdge);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetRisingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{

#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_REDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_REDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_LOAD_ON_CMP_EQ < LoadEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_REDLOADMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetRisingEdgeDelayLoadMode(InstanceId,LoadEvent);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetFallingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                            VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_FEDLOADMODE,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_FEDLOADMODE,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_LOAD_ON_CMP_EQ < LoadEvent)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_REDLOADMODE,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetFallingEdgeDelayLoadMode(InstanceId,LoadEvent);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmLockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_HrpwmLockRegisterGroupType, AUTOMATIC) RegisterGroup)
{

#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_LOCKREGISTER,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_LOCKREGISTER,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_REGISTER_GROUP_DIGITAL_COMPARE < RegisterGroup)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_LOCKREGISTER,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmLockRegisters(InstanceId,RegisterGroup);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                   VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg,VAR(uint32, AUTOMATIC) XCmpValue)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_XCMPREGVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_XCMPREGVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XTBPRD_SHADOW3 < XCmpReg)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_XCMPREGVAL,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetXCmpRegValue(InstanceId,XCmpReg,XCmpValue);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_HrpwmSetHiResXCmpRegValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg,VAR(uint32, AUTOMATIC) HrXCmpValue)
{
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESXCMPREGVAL,CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_HIRESXCMPREGVAL,CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XTBPRD_SHADOW3 < XCmpReg)
    {
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SET_HRPWM_XCMPREGVAL,CDD_PWM_E_INVALID_VALUE);
    }
    else 
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResXCmpRegValueOnly(InstanceId,XCmpReg,HrXCmpValue);
    }
}

FUNC(Cdd_Pwm_SfoStatus, CDD_PWM_CODE) Cdd_Pwm_Sfo(Cdd_Pwm_HrpwmCalInstanceType Cdd_Pwm_HrpwmCalId)
{
    Cdd_Pwm_SfoStatus sfo_status = CDD_PWM_SFO_INCOMPLETE;
#if(STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID,CDD_PWM_INSTANCE_ID,CDD_PWM_SID_SFO,CDD_PWM_E_UNINIT);
    }
    else 
#endif
    {
        sfo_status = Cdd_Pwm_PrivSfo(Cdd_Pwm_HrpwmCalId);
    }
    return sfo_status;
}

#endif


#define CDD_PWM_STOP_SEC_CODE
#include "Cdd_Pwm_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm.c
 *********************************************************************************************************************/