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

#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT) || (STD_OFF == CDD_PWM_ADVANCED_MODE_API)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_PWM_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_PWM_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_PWM_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "AUTOSAR Version of CDD_PWM is incorrect"
#endif

/* vendor specific version information check */
#if ((CDD_PWM_SW_MAJOR_VERSION != (3U)) || (CDD_PWM_SW_MINOR_VERSION != (1U)))
#error "Version numbers of Cdd_Pwm.c and Cdd_Pwm.h are not matching!"
#endif

#if ((CDD_PWM_CFG_MAJOR_VERSION != (3U)) || (CDD_PWM_CFG_MINOR_VERSION != (1U)))
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

#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API) && (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)

/** \brief This API performs DET error check for setting interrupt event count
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetInterruptEventCountDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(uint16, AUTOMATIC) EventCount);

/** \brief Cdd_Pwm_EnableNotification_DetChecks - This API will report DET error for the
 * notification related APIs
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

#elif (STD_ON == CDD_PWM_ADVANCED_MODE_API)

/** \brief This API performs DET error check for setting interrupt event count
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetInterruptEventCountDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(uint16, AUTOMATIC) EventCount);

/** \brief This API performs DET error check for setting counter compare shadow load mode
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetCounterCompareShadowLoadModeDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                                                    VAR(Cdd_Pwm_CounterCompareLoadModeType, AUTOMATIC) LoadMode);

/** \brief This API performs DET error check for setting action qualifier actions
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetActionQualifierActionDetCheck(VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) EpwmOutput,
                                             VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                             VAR(Cdd_Pwm_ActionQualifierOutputEventType, AUTOMATIC) Event);

/** \brief This API performs DET error check for setting dead band delay polarity
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetDeadBandDelayPolarityDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                                             VAR(Cdd_Pwm_DeadBandPolarityType, AUTOMATIC) Polarity);

/** \brief This API performs DET error check for setting trip zone digital compare event conditions
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
static FUNC(Std_ReturnType, CDD_PWM_CODE) Cdd_Pwm_SetTripZoneDigitalCompareEventConditionDetCheck(
    VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType, AUTOMATIC) DcType,
    VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType, AUTOMATIC) DcEvent);

/** \brief This API performs DET error check for setting trip zone actions
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetTripZoneActionDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_TripZoneActionEventType, AUTOMATIC) TzEvent,
                                      VAR(Cdd_Pwm_TripZoneActionType, AUTOMATIC) TzAction);

/** \brief This API performs DET error check for setting advanced trip zone actions
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetTripZoneAdvActionDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_TripZoneAdvancedEventType, AUTOMATIC) TzAdvEvent,
                                         VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvAction);

/** \brief This API performs DET error check for setting advanced trip zone digital compare actions
 *
 * \param[in] TzAdvDCEvent Trip zone advanced digital compare event type
 * \param[in] TzAdvDCAction Trip zone advanced action type
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetTripZoneAdvDigitalCompareActionDetCheck(VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType, AUTOMATIC)
                                                           TzAdvDCEvent,
                                                       VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC)
                                                           TzAdvDCAction);

/** \brief This API performs DET error check for setting ADC trigger source
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetAdcTriggerSourceDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                        VAR(Cdd_Pwm_AdcStartOfConversionSourceType, AUTOMATIC) SocSource);

/** \brief This API performs DET error check for setting ADC trigger event prescale
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetAdcTriggerEventPrescaleDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                               VAR(uint16, AUTOMATIC) PreScaleCount);

/** \brief This API performs DET error check for selecting digital compare trip input
 *
 * \param[in] InstanceId Numeric ID of the PWM instance
 * \param[in] TripInput Digital compare trip input type
 * \param[in] ApiId Api ID
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_DigitalCompareTripInputDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_DigitalCompareTripInputType, AUTOMATIC) TripInput,
                                            VAR(uint8, AUTOMATIC) ApiId);

/** \brief This API performs DET error check for setting digital compare event sync mode
 *
 * \param[in] ApiId Api ID of the API which calls this Det check function
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(VAR(uint8, DET_DATA) ApiId,
                                                   VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                   VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent);

/** \brief This API performs DET error check for setting valley trigger edge counts
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetValleyTriggerEdgeCountsDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(uint16, AUTOMATIC) StartCount, VAR(uint16, AUTOMATIC) StopCount);

/** \brief This API performs DET error check for setting XCMP action qualifier actions
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetXCmpActionQualifierActionDetCheck(VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) ShadowSet,
                                                 VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                                 VAR(Cdd_Pwm_XCmpAqOutputEventType, AUTOMATIC) Event);

/** \brief This API performs DET error check for setting XCMP shadow repeat buffer count
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetXCmpShadowRepeatBufxCountDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) Bufferset,
                                                 VAR(uint32, AUTOMATIC) Count);

/** \brief This API performs DET error to check driver init status, instane id and output channel
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_ChannelDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel, VAR(uint8, AUTOMATIC) ApiId);

/** \brief This API performs DET error check to set ADC trigger event count
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetAdcTriggerEventCountInitValueDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                     VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                                     VAR(uint16, AUTOMATIC) EventCount);

/** \brief This API performs DET error check for trip input type
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TripInput     Trip number
 * \param[in] ApiId         API ID
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: No error detected
 * \retval E_NOT_OK: Error detected
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_TripCombinationInputDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DcTripInputType, AUTOMATIC) TripInput,
                                         VAR(uint8, AUTOMATIC) ApiId);

/** \brief This API performs DET error check for setting mixed event trigger source
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetMixEvtTriggerSourceDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_EtMixSignalSelectType, AUTOMATIC) EtMixSignal,
                                           VAR(Cdd_Pwm_EvtMixTriggerSourceType, AUTOMATIC) InterruptSource);

/** \brief This API performs DET error check for setting prescaler for the PWM instance
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
static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetClockPrescalerDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_ClockDividerType, AUTOMATIC) Prescaler,
                                      VAR(Cdd_Pwm_HighSpeedClkDivType, AUTOMATIC) HighSpeedPrescaler);

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
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_CHANNEL_COUNT <= ChannelId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_EDGE_NONE <= EdgeNotification)
    {
        /* Design: MCAL-33949 */
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

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetInterruptEventCountDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(uint16, AUTOMATIC) EventCount)
{
    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (15U < EventCount)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

#endif

#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT) && (STD_ON == CDD_PWM_ADVANCED_MODE_API)

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetCounterCompareShadowLoadModeDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                                                    VAR(Cdd_Pwm_CounterCompareLoadModeType, AUTOMATIC) LoadMode)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_COMPARE_D < CompModule)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE,
                              CDD_PWM_E_INVALID_CTRCOMPARE);
    }
    else if (CDD_PWM_COMP_LOAD_ON_SYNC_ONLY < LoadMode)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetActionQualifierActionDetCheck(VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) EpwmOutput,
                                             VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                             VAR(Cdd_Pwm_ActionQualifierOutputEventType, AUTOMATIC) Event)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_OUTPUT_B < EpwmOutput)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQACTION,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else if (CDD_PWM_AQ_OUTPUT_TOGGLE < Output)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQACTION,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else if (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB < Event)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQACTION,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetDeadBandDelayPolarityDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                                             VAR(Cdd_Pwm_DeadBandPolarityType, AUTOMATIC) Polarity)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBODELAY_POLARITY,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_RED < DelayMode)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBODELAY_POLARITY,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else if (CDD_PWM_DB_POLARITY_ACTIVE_LOW < Polarity)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBODELAY_POLARITY,
                              CDD_PWM_E_INVALID_POLARITY);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE) Cdd_Pwm_SetTripZoneDigitalCompareEventConditionDetCheck(
    VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType, AUTOMATIC) DcType,
    VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType, AUTOMATIC) DcEvent)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZDC_EVTCONDITION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((uint8)CDD_PWM_TZ_DC_OUTPUT_B2 < (uint8)DcType)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZDC_EVTCONDITION,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else if ((uint8)CDD_PWM_TZ_EVENT_DCXL_HIGH_DCXH_LOW < (uint8)DcEvent)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZDC_EVTCONDITION,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetTripZoneActionDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_TripZoneActionEventType, AUTOMATIC) TzEvent,
                                      VAR(Cdd_Pwm_TripZoneActionType, AUTOMATIC) TzAction)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZACTION, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_ACTION_EVENT_DCBEVT2 < TzEvent)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZACTION,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_TZ_ACTION_DISABLE < TzAction)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZACTION,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetTripZoneAdvActionDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_TripZoneAdvancedEventType, AUTOMATIC) TzAdvEvent,
                                         VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvAction)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADVACTION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_ADV_ACTION_EVENT_TZB_D < TzAdvEvent)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADVACTION,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_TZ_ADV_ACTION_DISABLE < TzAdvAction)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADVACTION,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetTripZoneAdvDigitalCompareActionDetCheck(VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType, AUTOMATIC)
                                                           TzAdvDCEvent,
                                                       VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvDCAction)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT2_D < TzAdvDCEvent)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADV_DCACTION,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_TZ_ADV_ACTION_DISABLE < TzAdvDCAction)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADV_DCACTION,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetAdcTriggerSourceDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                        VAR(Cdd_Pwm_AdcStartOfConversionSourceType, AUTOMATIC) SocSource)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGSRC, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGSRC,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else if (CDD_PWM_SOC_TBCTR_D_CMPD < SocSource)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGSRC,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetAdcTriggerEventPrescaleDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                               VAR(uint16, AUTOMATIC) PreScaleCount)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else if (15U < PreScaleCount)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_DigitalCompareTripInputDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_DigitalCompareTripInputType, AUTOMATIC) TripInput,
                                            VAR(uint8, AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33949,MCAL-34747,MCAL-34748 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DC_TRIP_COMBINATION < TripInput)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(VAR(uint8, DET_DATA) ApiId,
                                                   VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                   VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else if (CDD_PWM_DC_EVENT_2 < DcEvent)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetValleyTriggerEdgeCountsDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(uint16, AUTOMATIC) StartCount, VAR(uint16, AUTOMATIC) StopCount)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYTRIGEDGECNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (15U < StartCount)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYTRIGEDGECNT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else if (15U < StopCount)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYTRIGEDGECNT,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }
    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetXCmpActionQualifierActionDetCheck(VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) ShadowSet,
                                                 VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                                 VAR(Cdd_Pwm_XCmpAqOutputEventType, AUTOMATIC) Event)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_XCMP_SHADOW3 < ShadowSet)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPAQACTION,
                              CDD_PWM_E_INVALID_SHDSET);
    }
    else if (CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8 < Event)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPAQACTION,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_AQ_OUTPUT_TOGGLE < Output)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPAQACTION,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetXCmpShadowRepeatBufxCountDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) Bufferset,
                                                 VAR(uint32, AUTOMATIC) Count)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_XCMP_SHADOW3 < Bufferset) || (Bufferset < CDD_PWM_XCMP_SHADOW2))
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else if (7U < Count)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_ChannelDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel, VAR(uint8, AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the output channel doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_TripCombinationInputDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DcTripInputType, AUTOMATIC) TripInput, VAR(uint8, AUTOMATIC) ApiId)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_DC_TRIPINPUT_COMBO_MAX < (uint16)TripInput) || (TripInput < CDD_PWM_DC_COMBINATIONAL_TRIPIN1))
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, ApiId, CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetAdcTriggerEventCountInitValueDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                     VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                                     VAR(uint16, AUTOMATIC) EventCount)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else if (15U < EventCount)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetMixEvtTriggerSourceDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_EtMixSignalSelectType, AUTOMATIC) EtMixSignal,
                                           VAR(Cdd_Pwm_EvtMixTriggerSourceType, AUTOMATIC) InterruptSource)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_MIXEVTTRIGSRC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_ETMIX_SOCB < EtMixSignal)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_MIXEVTTRIGSRC,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else if (CDD_PWM_ETMIX_DCAEVT1 < InterruptSource)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_MIXEVTTRIGSRC,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetClockPrescalerDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_ClockDividerType, AUTOMATIC) Prescaler,
                                      VAR(Cdd_Pwm_HighSpeedClkDivType, AUTOMATIC) HighSpeedPrescaler)
{
    Std_ReturnType return_value = E_NOT_OK;
    if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CLOCKPRESCALE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_CLOCK_DIVIDER_128 < Prescaler)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CLOCKPRESCALE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else if (CDD_PWM_HSCLOCK_DIVIDER_14 < HighSpeedPrescaler)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CLOCKPRESCALE,
                              CDD_PWM_E_INVALID_PRESCALE);
    }
    else
    {
        return_value = E_OK;
    }

    return return_value;
}

static FUNC(Std_ReturnType, CDD_PWM_CODE)
    Cdd_Pwm_SetInterruptEventCountDetCheck(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(uint16, AUTOMATIC) EventCount)
{
    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (15U < EventCount)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNT,
                              CDD_PWM_E_INVALID_VALUE);
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

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)

/* Design: MCAL-33887 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_Init(P2CONST(Cdd_Pwm_ConfigType, AUTOMATIC, CDD_PWM_CFG) CfgPtr)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-33888 */
    if (Cdd_Pwm_IsInitialized != FALSE)
    {
        /* Design: MCAL-33949 */
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_ALREADY_INITIALIZED);
    }
#if (STD_ON == CDD_PWM_PRE_COMPILE_VARIANT)
    /* Design: MCAL-33889 */
    else if (CfgPtr != NULL_PTR)
    {
        /* Design: MCAL-33949 */
        /* Report Det error if the passed configuration pointer is not NULL_PTR for pre-compile
         * build variant */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_PARAM_POINTER);
    }
#else
    else if (CfgPtr == NULL_PTR)
    {
        /* Design: MCAL-33949 */
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

/* Design: MCAL-33897 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DeInit(void)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-33900 */
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DEINIT, CDD_PWM_E_UNINIT);
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

/* Design: MCAL-33905 */
/* Service to set the duty cycle of the PWM channel */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDutyCycle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId, VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-33901 */
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DUTY_CYCLE, CDD_PWM_E_UNINIT);
    }
    else if (ChannelId >= CDD_PWM_CHANNEL_COUNT)
    {
        /* Design: MCAL-33902 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DUTY_CYCLE, CDD_PWM_E_INVALID_ID);
    }
    else if (DutyCycle > CDD_PWM_MAX_DUTY_CYCLE)
    {
        /* Design: MCAL-33903 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DUTY_CYCLE,
                              CDD_PWM_E_INVALID_DUTY_CYCLE);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        Cdd_Pwm_UpdateDutyCycle(ChannelId, DutyCycle);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}
#endif

#if (CDD_PWM_SET_PERIOD_API == STD_ON)

/* Design: MCAL-33913 */
/* Service to set the period of the PWM hardware unit/instance */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetPeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_PeriodType, AUTOMATIC) Period)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Design: MCAL-33910 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PERIOD, CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Design: MCAL-33911 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PERIOD, CDD_PWM_E_INVALID_ID);
    }
    else if (Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].channelclass != CDD_PWM_VARIABLE_PERIOD)
    {
        /* Design: MCAL-33912,MCAL-33920 */
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

/* Design: MCAL-33918 */
/* Service to get the set the PWM channel output to IDLE */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetOutputToIdle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Design: MCAL-33916 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_OUTPUT_TO_IDLE, CDD_PWM_E_UNINIT);
    }
    else if (ChannelId >= CDD_PWM_CHANNEL_COUNT)
    {
        /* Design: MCAL-33917 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_OUTPUT_TO_IDLE,
                              CDD_PWM_E_INVALID_ID);
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

/* Design: MCAL-33935 */
/* This function is available in both Advanced and Simple mode */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetInterruptEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) EventCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-33937,MCAL-33938,MCAL-33939 */
    Std_ReturnType return_value = Cdd_Pwm_SetInterruptEventCountDetCheck(InstanceId, EventCount);

    if (E_OK == return_value)
#endif
    {
        /* Check if interrupt event count can be updated. For that check if the notification is enabled for both the
         * channels. If atleast one of them is already enabled then report a runtime error
         */
        /* In simple mode */
        if ((uint8)0U != Cdd_Pwm_DrvObj.hwunitobj[InstanceId].notification_enable)
        {
            /* Design: MCAL-33940 */
            /* Report DET error if the channel ID doesn't exist */
            (void)Det_ReportRuntimeError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNT,
                                         CDD_PWM_E_BUSY);
        }
        else
        {
            SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
            /* If no channel notification is active then the interrupt event count can be enabled */
            Cdd_Pwm_PrivSetInterruptEventCount(Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr, EventCount);
            /* Update interrupt event count */
            Cdd_Pwm_DrvObj.hwunitobj[InstanceId].inteventcount = EventCount;
            SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        }
    }
}

/* Design: MCAL-33926 */
/* Service to enable the notification of the channel */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_EnableNotification(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                           VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-33921,MCAL-33922,MCAL-33924 */
    Std_ReturnType return_value = Cdd_Pwm_EnableNotification_DetCheck(ChannelId, EdgeNotification);

    if ((E_OK == return_value) &&
        ((Cdd_Pwm_NotificationType)NULL_PTR ==
         Cdd_Pwm_CfgPtr->hwunitcfg[(Cdd_Pwm_CfgPtr->channelcfg[ChannelId].hw_index)].notification))

    {
        /* Design: MCAL-33923 */
        /* Report DET error if the notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                              CDD_PWM_E_NOTIF_CAPABILITY);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        if (0U == Cdd_Pwm_DrvObj.hwunitobj[(Cdd_Pwm_CfgPtr->channelcfg[ChannelId].hw_index)].inteventcount)
        {
            /* Design: MCAL-33925 */
            /* Report DET error if the notification function doesn't exist */
            (void)Det_ReportRuntimeError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                                         CDD_PWM_E_INVALID_INTEVTCOUNT);
        }
        else if (Cdd_Pwm_DrvObj.channelobj[ChannelId].edgenotifytype == CDD_PWM_EDGE_NONE)
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
            (void)Det_ReportRuntimeError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                                         CDD_PWM_E_NOTIF_ALREADY_ENABLED);
        }
    }
}

/* Design: MCAL-33933 */
/* Service to disable the notification of the channel */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableNotification(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized == FALSE)
    {
        /* Design: MCAL-33930 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_CHANNEL_COUNT <= ChannelId)
    {
        /* Design: MCAL-33931 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((Cdd_Pwm_NotificationType)NULL_PTR ==
             Cdd_Pwm_CfgPtr->hwunitcfg[(Cdd_Pwm_CfgPtr->channelcfg[ChannelId].hw_index)].notification)
    {
        /* Design: MCAL-33932 */
        /* Report DET error if the notification function doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION,
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

/* Design: MCAL-33895 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_PWM_DATA) VersionInfo)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-33896 */
    /* If VersionInfo is NULL */
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_VERSION_INFO,
                              CDD_PWM_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfo->vendorID         = CDD_PWM_VENDOR_ID;
        VersionInfo->moduleID         = CDD_PWM_MODULE_ID;
        VersionInfo->instanceID       = CDD_PWM_INSTANCE_ID;
        VersionInfo->sw_major_version = (uint8)CDD_PWM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)CDD_PWM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)CDD_PWM_SW_PATCH_VERSION;
    }
}
#endif

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

/* This function is available in both Advanced and Simple mode */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetInterruptEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) EventCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = Cdd_Pwm_SetInterruptEventCountDetCheck(InstanceId, EventCount);

    if (E_OK == return_value)
#endif
    {
        /* In Advanced mode */
        Cdd_Pwm_PrivSetInterruptEventCount(Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr, EventCount);
    }
}

FUNC(void, CDD_PWM_CODE) Cdd_Pwm_Init(P2CONST(Cdd_Pwm_ConfigType, AUTOMATIC, CDD_PWM_CFG) CfgPtr)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (Cdd_Pwm_IsInitialized != FALSE)
    {
        /* Design: MCAL-33949 */
        /* Report Det error if the driver is already initialized */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_ALREADY_INITIALIZED);
    }
#if (STD_ON == CDD_PWM_PRE_COMPILE_VARIANT)
    else if (CfgPtr != NULL_PTR)
    {
        /* Design: MCAL-33949 */
        /* Report Det error if the passed configuration pointer is not NULL_PTR for pre-compile
         * build variant */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INIT, CDD_PWM_E_PARAM_POINTER);
    }
#else
    else if (CfgPtr == NULL_PTR)
    {
        /* Design: MCAL-33949 */
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
        /* Design: MCAL-33949 */
        /* Report DET error if the driver not initialised before calling Cdd_Pwm_EnableNotification
         */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                              CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_NOTIFICATION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((Cdd_Pwm_NotificationType)NULL_PTR == Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].notification)
    {
        /* Design: MCAL-33949 */
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
        /* Design: MCAL-33949 */
        /* Report DET error if the driver not initialised before calling Cdd_Pwm_EnableNotification
         */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION,
                              CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_NOTIFICATION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((Cdd_Pwm_NotificationType)NULL_PTR == Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].notification)
    {
        /* Design: MCAL-33949 */
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

/* Design: MCAL-33941 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZoneNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33942 */
        /* Report DET error if the driver not initialised before calling Cdd_Pwm_ConfigureTripZoneNotification
         */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TRIPZONE_NOTIFICATION,
                              CDD_PWM_E_UNINIT);
    }
    else if (InstanceId >= CDD_PWM_COUNT)
    {
        /* Design: MCAL-33943 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TRIPZONE_NOTIFICATION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((Cdd_Pwm_TripZoneNotificationType)NULL_PTR == Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].tripzone_notification)
    {
        /* Design: MCAL-33944 */
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

/* Design: MCAL-33945 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                         VAR(Cdd_Pwm_EmulationModeType, AUTOMATIC) EmulationMode)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33946 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_EMULATION_MODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33947 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_EMULATION_MODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        /* Set emulation mode */
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetEmulationMode(base, EmulationMode);
    }
}

/* Design: MCAL-33948 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTimeBaseCounter(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) Count)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33949 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TB_COUNTER, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33950 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TB_COUNTER, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        /* Write to TBCTR register */
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetTimeBaseCounter(base, Count);
    }
}

/* Design: MCAL-33951 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetCountModeAfterSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_SyncCountModeType, AUTOMATIC) Mode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33952 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_COUNTMODE_AFTERSYNC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33953 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_COUNTMODE_AFTERSYNC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNT_MODE_UP_AFTER_SYNC < Mode)
    {
        /* Design: MCAL-33954 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_COUNTMODE_AFTERSYNC,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetCountModeAfterSync(InstanceId, Mode);
    }
}

/* Design: MCAL-33955 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetClockPrescaler(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_ClockDividerType, AUTOMATIC) Prescaler,
                          VAR(Cdd_Pwm_HighSpeedClkDivType, AUTOMATIC) HighSpeedPrescaler)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33956 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CLOCKPRESCALE, CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-33957,MCAL-33958,MCAL-33959 */
        return_value = Cdd_Pwm_SetClockPrescalerDetCheck(InstanceId, Prescaler, HighSpeedPrescaler);
    }

    if (E_OK == return_value)
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetClockPrescaler(base, Prescaler, HighSpeedPrescaler);
    }
}

/* Design: MCAL-33960 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceSyncPulse(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33961 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_SYNC_PULSE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33962 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_SYNC_PULSE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceSyncPulse(InstanceId);
    }
}

/* Design: MCAL-33963 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetSyncInPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_SyncInPulseSourceType, AUTOMATIC) Source)
{
/* Set EPWM Sync-In Source Mode. */
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33964 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_SYNC_INPULSE_SOURCE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33965 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_SYNC_INPULSE_SOURCE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SYNC_IN_PULSE_SRC_FSIRXD_TRIG1 < Source)
    {
        /* Design: MCAL-33966 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_SYNC_INPULSE_SOURCE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetSyncInPulseSource(InstanceId, Source);
    }
}

/* Design: MCAL-33967 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureSyncOutPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_SyncOutPulseSourceType, AUTOMATIC) Source,
                                    VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33968 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_SYNCOUT_PULSE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33969 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_SYNCOUT_PULSE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_SYNC_OUT_PULSE_ON_SOFTWARE > Source) || (Source > CDD_PWM_SYNC_OUT_PULSE_ON_ALL))
    {
        /* Design: MCAL-33970 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_SYNCOUT_PULSE,
                              CDD_PWM_E_INVALID_EVENT_SRC);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureSyncOutPulseSource(InstanceId, Source, Select);
    }
}

/* Design: MCAL-33971 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetOneShotSyncOutTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_OneShotSyncOutTriggerType, AUTOMATIC) Trigger)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33972 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ONESHOT_SYNCOUT_TRIGGER,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33973 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ONESHOT_SYNCOUT_TRIGGER,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OSHT_SYNC_OUT_TRIG_RELOAD < Trigger)
    {
        /* Design: MCAL-33974 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ONESHOT_SYNCOUT_TRIGGER,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetOneShotSyncOutTrigger(InstanceId, Trigger);
    }
}

/* Design: MCAL-33975 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetPeriodLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_PeriodLoadModeType, AUTOMATIC) LoadMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33976 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PRDLOADMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33977 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PRDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_PERIOD_DIRECT_LOAD < LoadMode)
    {
        /* Design: MCAL-33978 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PRDLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetPeriodLoadMode(InstanceId, LoadMode);
    }
}

/* Design: MCAL-33979 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33980 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_PHSSHIFTLOAD,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33981 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_PHSSHIFTLOAD,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigurePhaseShiftLoad(InstanceId, Select);
    }
}

/* Design: MCAL-33982 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTimeBaseCounterMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_TimeBaseCountModeType, AUTOMATIC) CounterMode)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33983 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TBCOUNTERMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33984 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TBCOUNTERMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_MODE_STOP_FREEZE < CounterMode)
    {
        /* Design: MCAL-33985 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TBCOUNTERMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetTimeBaseCounterMode(base, CounterMode);
    }
}

/* Design: MCAL-33986 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectPeriodLoadEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_PeriodShadowLoadModeType, AUTOMATIC) ShadowLoadMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33987 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_PERIODLOADEVT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33988 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_PERIODLOADEVT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SHADOW_LOAD_MODE_SYNC < ShadowLoadMode)
    {
        /* Design: MCAL-33989 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_PERIODLOADEVT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSelectPeriodLoadEvent(InstanceId, ShadowLoadMode);
    }
}

/* Design: MCAL-33990 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureOneShotSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33991 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ONESHTSYNC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33992 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ONESHTSYNC,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureOneShotSync(InstanceId, Select);
    }
}

/* Design: MCAL-33993 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_StartOneShotSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33994 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_START_ONESHTSYNC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33995 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_START_ONESHTSYNC,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivStartOneShotSync(InstanceId);
    }
}

/* Design: MCAL-33996 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-33997 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TBCOUNTERVAL, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-33998 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TBCOUNTERVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetTimeBaseCounterValue(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-33999 */
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterOverflowStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    boolean return_value = FALSE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34000 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TBCOUNTER_OVFSTATUS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34001 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TBCOUNTER_OVFSTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetTimeBaseCounterOverflowStatus(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34002 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearTimeBaseCounterOverflowEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34003 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_TBOVFEVT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34004 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_TBOVFEVT, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivClearTimeBaseCounterOverflowEvent(InstanceId);
    }
}

/* Design: MCAL-34005 */
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_GetSyncStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    boolean return_value = FALSE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34006 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GETSYNCSTATUS, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34007 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GETSYNCSTATUS, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetSyncStatus(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34008 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearSyncEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34009 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CLEARSYNCEVT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34010 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CLEARSYNCEVT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivClearSyncEvent(InstanceId);
    }
}

/* Design: MCAL-34011 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterDirection(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34012 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TBCNTRDIRECTION,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34013 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TBCNTRDIRECTION,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetTimeBaseCounterDirection(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34014 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) PhaseCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34015 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PHASESHIFT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34016 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_PHASESHIFT, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetPhaseShift(InstanceId, PhaseCount);
    }
}

/* Design: MCAL-34017 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) PeriodCount)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34018 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TB_PERIOD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34019 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TB_PERIOD, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetTimeBasePeriod(base, PeriodCount);
    }
}

/* Design: MCAL-34020 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34021 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TB_PERIOD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34022 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TB_PERIOD, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetTimeBasePeriod(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34023 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetCounterCompareShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                                        VAR(Cdd_Pwm_CounterCompareLoadModeType, AUTOMATIC) LoadMode)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)

    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34024 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34719,MCAL-34720,MCAL-34721 */
        return_value = Cdd_Pwm_SetCounterCompareShadowLoadModeDetCheck(InstanceId, CompModule, LoadMode);
    }

    if (E_OK == return_value)
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetCounterCompareShadowLoadMode(base, CompModule, LoadMode);
    }
}

/* Design: MCAL-34025 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableCounterCompareShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34026 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_CTRCMP_SHADOWLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34027 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_CTRCMP_SHADOWLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_COMPARE_D < CompModule)
    {
        /* Design: MCAL-34028 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_CTRCMP_SHADOWLOADMODE,
                              CDD_PWM_E_INVALID_CTRCOMPARE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivDisableCounterCompareShadowLoadMode(InstanceId, CompModule);
    }
}

/* Design: MCAL-34029 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                               VAR(uint16, AUTOMATIC) CompCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34030 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CTRCMPVAL, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34031 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CTRCMPVAL, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_COMPARE_D < CompModule)
    {
        /* Design: MCAL-34032 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CTRCMPVAL,
                              CDD_PWM_E_INVALID_CTRCOMPARE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetCounterCompareValue(InstanceId, CompModule, CompCount);
    }
}

/* Design: MCAL-34033 */
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34034 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_CTRCMPVAL, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34035 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_CTRCMPVAL, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_COUNTER_COMPARE_D < CompModule)
    {
        /* Design: MCAL-34036 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_CTRCMPVAL,
                              CDD_PWM_E_INVALID_CTRCOMPARE);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetCounterCompareValue(InstanceId, CompModule);
    }
    return return_value;
}

/* Design: MCAL-34037 */
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_GetCounterCompareShadowStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    boolean return_value = FALSE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34038 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_CTRCMP_SHDSTATUS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34039 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_CTRCMP_SHDSTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34040 */
        /* Report DET error if the compare module are not CMPA & CMPB */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_CTRCMP_SHDSTATUS,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetCounterCompareShadowStatus(InstanceId, OutputChannel);
    }
    return return_value;
}

/* Design: MCAL-34041 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureLinkDutyHR(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34042 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_LINKDUTYHR,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34043 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_LINKDUTYHR,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureLinkDutyHR(InstanceId, Select);
    }
}

/* Design: MCAL-34044 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(Cdd_Pwm_ActionQualifierLoadModeType, AUTOMATIC) LoadMode)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34045,MCAL-34768,MCAL-34769 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_AQSHDLOADMODE);

    if ((E_OK == return_value) && (CDD_PWM_AQ_LOAD_ON_SYNC_ONLY < LoadMode))
    {
        /* Design: MCAL-34036 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQSHDLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetActionQualifierShadowLoadMode(base, OutputChannel, LoadMode);
    }
}

/* Design: MCAL-34046 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableActionQualifierShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34047 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_AQSHDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34048 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_AQSHDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34049 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_AQSHDLOADMODE,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivDisableActionQualifierShadowLoadMode(InstanceId, OutputChannel);
    }
}

/* Design: MCAL-34050 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierT1TriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_ActionQualifierTriggerSourceType, AUTOMATIC) Trigger)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34051 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQT1TRIGSRC, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34052 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQT1TRIGSRC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT < Trigger)
    {
        /* Design: MCAL-34053 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQT1TRIGSRC,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierT1TriggerSource(InstanceId, Trigger);
    }
}

/* Design: MCAL-34054 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierT2TriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_ActionQualifierTriggerSourceType, AUTOMATIC) Trigger)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34055 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQT2TRIGSRC, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34056 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQT2TRIGSRC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT < Trigger)
    {
        /* Design: MCAL-34057 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQT2TRIGSRC,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierT2TriggerSource(InstanceId, Trigger);
    }
}

/* Design: MCAL-34058 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) EpwmOutput,
                                 VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                 VAR(Cdd_Pwm_ActionQualifierOutputEventType, AUTOMATIC) Event)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34059 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQACTION, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34060 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQACTION, CDD_PWM_E_INVALID_ID);
    }
    else
    {
        /* Design: MCAL-34722,MCAL-34723,MCAL-34724 */
        return_value = Cdd_Pwm_SetActionQualifierActionDetCheck(EpwmOutput, Output, Event);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierAction(InstanceId, EpwmOutput, Output, Event);
    }
}

/* Design: MCAL-34061 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(Cdd_Pwm_ActionQualifierEventActionType, AUTOMATIC) Action)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34062,MCAL-34063,MCAL-34770 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_AQACTION_COMPLETE);

    if ((E_OK == return_value) && (CDD_PWM_AQEVT_ACTION_MAX < (uint16)Action))
    {
        /* Design: MCAL-34064 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQACTION_COMPLETE,
                              CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierActionComplete(InstanceId, OutputChannel, (uint16)Action);
    }
}

/* Design: MCAL-34065 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetAdditionalActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                   VAR(Cdd_Pwm_AdditionalActionQualifierEventActionType, AUTOMATIC)
                                                       Action)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34066,MCAL-34067,MCAL-34771 */
    Std_ReturnType return_value =
        Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_ADDITIONALAQACTION_COMPLETE);

    if ((E_OK == return_value) && (CDD_PWM_ADDITIONAL_AQEVT_ACTION_MAX < (uint16)Action))
    {
        /* Design: MCAL-34068 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADDITIONALAQACTION_COMPLETE,
                              CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetAdditionalActionQualifierActionComplete(InstanceId, OutputChannel, (uint16)Action);
    }
}

/* Design: MCAL-34069 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierContSwForceShadowMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_ActionQualifierContForceType, AUTOMATIC) Mode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34070 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQCNTSWFRC_SHDMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34071 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQCNTSWFRC_SHDMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_AQ_SW_IMMEDIATE_LOAD < Mode)
    {
        /* Design: MCAL-34072 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQCNTSWFRC_SHDMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierContSwForceShadowMode(InstanceId, Mode);
    }
}

/* Design: MCAL-34073 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierContSwForceAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                            VAR(Cdd_Pwm_ActionQualifierSwOutputType, AUTOMATIC) Output)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34074,MCAL-34075,MCAL-34772 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_AQCNTSWFRC_ACTION);

    if ((E_OK == return_value) && (CDD_PWM_AQ_SW_OUTPUT_HIGH < Output))
    {
        /* Design: MCAL-34076 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQCNTSWFRC_ACTION,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierContSwForceAction(InstanceId, OutputChannel, Output);
    }
}

/* Design: MCAL-34077 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                   VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34078,MCAL-34079,MCAL-34773 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_AQSWACTION);

    if ((E_OK == return_value) && (CDD_PWM_AQ_OUTPUT_TOGGLE < Output))
    {
        /* Design: MCAL-34080 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_AQSWACTION,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetActionQualifierSwAction(InstanceId, OutputChannel, Output);
    }
}

/* Design: MCAL-34081 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ForceActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34082 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_AQSWACTION, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34083 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_AQSWACTION, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34084 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_AQSWACTION,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceActionQualifierSwAction(InstanceId, OutputChannel);
    }
}

/* Dead Band Module related APIs */
/* Design: MCAL-34085 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                  VAR(boolean, AUTOMATIC) EnableSwapMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34086 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBOUTPUTSWAPMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34087 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBOUTPUTSWAPMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34088 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBOUTPUTSWAPMODE,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDeadBandOutputSwapMode(InstanceId, OutputChannel, EnableSwapMode);
    }
}

/* Design: MCAL-34089 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandDelayMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                             VAR(boolean, AUTOMATIC) EnableDelayMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34090 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBODELAYMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34091 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBODELAYMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_RED < DelayMode)
    {
        /* Design: MCAL-34092 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBODELAYMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDeadBandDelayMode(InstanceId, DelayMode, EnableDelayMode);
    }
}

/* Design: MCAL-34093 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandDelayPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                                 VAR(Cdd_Pwm_DeadBandPolarityType, AUTOMATIC) Polarity)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34094 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBODELAY_POLARITY,
                              CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34725,MCAL-34726,MCAL-34727 */
        return_value = Cdd_Pwm_SetDeadBandDelayPolarityDetCheck(InstanceId, DelayMode, Polarity);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetDeadBandDelayPolarity(InstanceId, DelayMode, Polarity);
    }
}

/* Design: MCAL-34095 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetRisingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34096 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_REDB_DELAYINPUT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34097 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_REDB_DELAYINPUT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34098 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_REDB_DELAYINPUT,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetRisingEdgeDeadBandDelayInput(InstanceId, OutputChannel);
    }
}

/* Design: MCAL-34099 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetFallingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DeadBandDelayInputType, AUTOMATIC) Input)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34100 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FEDB_DELAYINPUT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34101 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FEDB_DELAYINPUT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_INPUT_DB_RED < Input)
    {
        /* Design: MCAL-34102 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FEDB_DELAYINPUT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetFallingEdgeDeadBandDelayInput(InstanceId, Input);
    }
}

/* Design: MCAL-34103 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DeadBandControlLoadModeType, AUTOMATIC) LoadMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34104 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBCTL_SHDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34105 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBCTL_SHDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_LOAD_FREEZE < LoadMode)
    {
        /* Design: MCAL-34106 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBCTL_SHDLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDeadBandControlShadowLoadMode(InstanceId, LoadMode);
    }
}

/* Design: MCAL-34107 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DisableDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34108 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_DBCTL_SHDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34109 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_DBCTL_SHDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivDisableDeadBandControlShadowLoadMode(InstanceId);
    }
}

/* Design: MCAL-34110 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_DeadBandDelayLoadModeType, AUTOMATIC) LoadMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34111 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_RED_COUNTSHDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34112 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_RED_COUNTSHDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DELAY_LOAD_FREEZE < LoadMode)
    {
        /* Design: MCAL-34113 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_RED_COUNTSHDLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetRisingEdgeDelayCountShadowLoadMode(InstanceId, LoadMode);
    }
}

/* Design: MCAL-34114 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34115 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_RED_COUNTSHDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34116 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_RED_COUNTSHDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivDisableRisingEdgeDelayCountShadowLoadMode(InstanceId);
    }
}

/* Design: MCAL-34117 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_DeadBandDelayLoadModeType, AUTOMATIC) LoadMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34118 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FED_COUNTSHDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34119 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FED_COUNTSHDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DELAY_LOAD_FREEZE < LoadMode)
    {
        /* Design: MCAL-34120 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FED_COUNTSHDLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetFallingEdgeDelayCountShadowLoadMode(InstanceId, LoadMode);
    }
}

/* Design: MCAL-34121 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34122 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_FED_COUNTSHDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34123 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_DISABLE_FED_COUNTSHDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivDisableFallingEdgeDelayCountShadowLoadMode(InstanceId);
    }
}

/* Design: MCAL-34124 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandCounterClock(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_DeadBandClockModeType, AUTOMATIC) ClockMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34125 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBCTRCLK, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34126 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBCTRCLK, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DB_COUNTER_CLOCK_HALF_CYCLE < ClockMode)
    {
        /* Design: MCAL-34127 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DBCTRCLK,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDeadBandCounterClock(InstanceId, ClockMode);
    }
}

/* Design: MCAL-34128 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetRisingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) RedCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34129 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_REDCOUNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34130 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_REDCOUNT, CDD_PWM_E_INVALID_ID);
    }
    else if (0x4000U <= RedCount)
    {
        /* Design: MCAL-34131 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_REDCOUNT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetRisingEdgeDelayCount(InstanceId, RedCount);
    }
}

/* Design: MCAL-34132 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetFallingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) FedCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34133 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FEDCOUNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34134 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FEDCOUNT, CDD_PWM_E_INVALID_ID);
    }
    else if (0x4000U <= FedCount)
    {
        /* Design: MCAL-34135 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_FEDCOUNT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetFallingEdgeDelayCount(InstanceId, FedCount);
    }
}

/* Chopper module related APIs */

/* Design: MCAL-34136 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureChopper(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34137 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_CHOPPER, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34138 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_CHOPPER,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureChopper(InstanceId, Select);
    }
}

/* Design: MCAL-34139 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetChopperDutyCycle(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) DutyCycleCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34140 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_DC, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34141 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_DC, CDD_PWM_E_INVALID_ID);
    }
    else if (7U <= DutyCycleCount)
    {
        /* Design: MCAL-34142 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_DC,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetChopperDutyCycle(InstanceId, DutyCycleCount);
    }
}

/* Design: MCAL-34143 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetChopperFreq(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) FreqDiv)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34144 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_FREQ, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34145 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_FREQ,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (7U < FreqDiv)
    {
        /* Design: MCAL-34146 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_FREQ,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetChopperFreq(InstanceId, FreqDiv);
    }
}

/* Design: MCAL-34147 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetChopperFirstPulseWidth(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(uint16, AUTOMATIC) FirstPulseWidth)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34148 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_FIRSTPULWIDTH,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34149 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_FIRSTPULWIDTH,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (15U < FirstPulseWidth)
    {
        /* Design: MCAL-34150 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CHOPPER_FIRSTPULWIDTH,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetChopperFirstPulseWidth(InstanceId, FirstPulseWidth);
    }
}

/*  Trip Zone module related APIs */

/* Design: MCAL-34151 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZoneSignals(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_TzSignalType, AUTOMATIC) TzSignal, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34152 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZSIGNALS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34153 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZSIGNALS,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_SIGNAL_CBC1 > TzSignal)
    {
        /* Design: MCAL-34154 */
        /* Report DET error if the signal is not valid (ideally signal value is a power of 2) */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZSIGNALS,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureTripZoneSignals(InstanceId, (uint16)TzSignal, Select);
    }
}

/* Design: MCAL-34155 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZone2Signals(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_TzCapEvtType, AUTOMATIC) TzSignal, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34156 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZ2SIGNALS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34157 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZ2SIGNALS,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZCAPEVTSIG_MAX < (uint16)TzSignal) || (CDD_PWM_TZ_SIGNAL_CAPEVT_CBC > TzSignal))
    {
        /* Design: MCAL-34158 */
        /* Report DET error if the signal is not valid (ideally signal value is a power of 2) */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZ2SIGNALS,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureTripZone2Signals(InstanceId, (uint16)TzSignal, Select);
    }
}

/* Design: MCAL-34159 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTripZoneDigitalCompareEventCondition(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType, AUTOMATIC) DcType,
                                                VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType, AUTOMATIC) DcEvent)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34160 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZDC_EVTCONDITION,
                              CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34728,MCAL-34729,MCAL-34730 */
        return_value = Cdd_Pwm_SetTripZoneDigitalCompareEventConditionDetCheck(InstanceId, DcType, DcEvent);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetTripZoneDigitalCompareEventCondition(InstanceId, DcType, DcEvent);
    }
}

/* Design: MCAL-34161 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34162 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZADVACTION,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34163 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZADVACTION,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureTripZoneAdvAction(InstanceId, Select);
    }
}

/* Design: MCAL-34164 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTripZoneAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_TripZoneActionEventType, AUTOMATIC) TzEvent,
                          VAR(Cdd_Pwm_TripZoneActionType, AUTOMATIC) TzAction)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34165 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZACTION, CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34731,MCAL-34732,MCAL-34733 */
        return_value = Cdd_Pwm_SetTripZoneActionDetCheck(InstanceId, TzEvent, TzAction);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetTripZoneAction(InstanceId, TzEvent, TzAction);
    }
}

/* Design: MCAL-34166 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_TripZoneAdvancedEventType, AUTOMATIC) TzAdvEvent,
                             VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvAction)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34167 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADVACTION, CDD_PWM_E_UNINIT);
        return_value = E_NOT_OK;
    }
    else
    {
        /* Design: MCAL-34734,MCAL-34735,MCAL-34736 */
        return_value = Cdd_Pwm_SetTripZoneAdvActionDetCheck(InstanceId, TzAdvEvent, TzAdvAction);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetTripZoneAdvAction(InstanceId, TzAdvEvent, TzAdvAction);
    }
}

/* Design: MCAL-34168 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTripZoneAdvDigitalCompareAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                           VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType, AUTOMATIC) TzAdvDCEvent,
                                           VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvDCAction)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;

    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34169 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADV_DCACTION, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34170 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADV_DCACTION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34171 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_TZADV_DCACTION,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
    {
        /* Design: MCAL-34737,MCAL-34738 */
        return_value = Cdd_Pwm_SetTripZoneAdvDigitalCompareActionDetCheck(TzAdvDCEvent, TzAdvDCAction);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetTripZoneAdvDigitalCompareAction(InstanceId, OutputChannel, TzAdvDCEvent, TzAdvDCAction);
    }
}

/* Design: MCAL-34172 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZoneInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_TzInterruptSourceType, AUTOMATIC) TzInterrupt,
                                   VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34173 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZINT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34174 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZINT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((TzInterrupt < CDD_PWM_TZ_INTERRUPT_CBC) || ((uint16)TzInterrupt > CDD_PWM_TZINT_SRC_MAX))
    {
        /* Design: MCAL-34175 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TZINT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureTripZoneInterrupt(InstanceId, (uint16)TzInterrupt, Select);
    }
}

/* Design: MCAL-34176 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34177 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TZFLAGSTATUS, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34178 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_TZFLAGSTATUS,
                              CDD_PWM_E_INVALID_ID);
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

/* Design: MCAL-34179 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetCycleByCycleTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34180 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_CBCTZ_FLAGSTATUS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34181 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_CBCTZ_FLAGSTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetCycleByCycleTripZoneFlagStatus(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34182 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetOneShotTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34183 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_OSTZ_FLAGSTATUS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34184 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_OSTZ_FLAGSTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetOneShotTripZoneFlagStatus(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34185 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectCycleByCycleTripZoneClearEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_CbcTripZoneClearModeType, AUTOMATIC) ClearEvent)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34186 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_CBCTZCLREVT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34187 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_CBCTZCLREVT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_ZERO_PERIOD < ClearEvent)
    {
        /* Design: MCAL-34188 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_CBCTZCLREVT,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSelectCycleByCycleTripZoneClearEvent(InstanceId, ClearEvent);
    }
}

/* Design: MCAL-34189 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ClearTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_TripZoneFlagType, AUTOMATIC) TzFlags)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34190 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_TZFLAG, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34191 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_TZFLAG, CDD_PWM_E_INVALID_ID);
    }
    else if (((uint16)TzFlags > CDD_PWM_TZFLAG_MAX) || (TzFlags < CDD_PWM_TZ_INTERRUPT))
    {
        /* Design: MCAL-34192 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_TZFLAG,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivClearTripZoneFlag(InstanceId, (uint16)TzFlags);
    }
}

/* Design: MCAL-34193 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ClearCycleByCycleTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_CbcTzFlagType, AUTOMATIC) TzCbcFlags)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34194 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_CBCTZFLAG, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34195 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_CBCTZFLAG,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZCBC_INTFLAGS_MAX < (uint16)TzCbcFlags) || (TzCbcFlags < CDD_PWM_TZ_CBC_FLAG_1))
    {
        /* Design: MCAL-34196 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_CBCTZFLAG,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivClearCycleByCycleTripZoneFlag(InstanceId, (uint16)TzCbcFlags);
    }
}

/* Design: MCAL-34197 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ClearOneShotTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_OneshotTzFlagType, AUTOMATIC) TzOstFlags)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34198 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_OSTZFLAG, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34199 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_OSTZFLAG, CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZOST_INTFLAGS_MAX < (uint16)TzOstFlags) || (TzOstFlags < CDD_PWM_TZ_OST_FLAG_OST1))
    {
        /* Design: MCAL-34200 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_OSTZFLAG,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivClearOneShotTripZoneFlag(InstanceId, (uint16)TzOstFlags);
    }
}

/* Design: MCAL-34201 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ForceTripZoneEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_TripZoneForceEventType, AUTOMATIC) TzForceEvent)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34202 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_TZEVT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34203 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_TZEVT, CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_TZFRC_FLAGS_MAX < ((uint16)TzForceEvent)) || (TzForceEvent < CDD_PWM_TZ_FORCE_EVENT_CBC))
    {
        /* Design: MCAL-34204 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_TZEVT, CDD_PWM_E_INVALID_EVENT);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceTripZoneEvent(InstanceId, (uint16)TzForceEvent);
    }
}

/* Design: MCAL-34205 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripOutSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_SelectTripOutSourceType, AUTOMATIC) TzTripOut,
                               VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34206 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TRIPOUTSRC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34207 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TRIPOUTSRC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_TZ_TRIPOUT_CAPEVT < TzTripOut)
    {
        /* Design: MCAL-34208 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_TRIPOUTSRC,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureTripOutSource(InstanceId, TzTripOut, Select);
    }
}

/* Event Trigger related APIs */

/* Design: MCAL-34209 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34210 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_INTERRUPT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34211 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_INTERRUPT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivConfigureInterrupt(base, Select);
    }
}

/* Design: MCAL-34212 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetInterruptSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_InterruptSourceType, AUTOMATIC) InterruptSource)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34213 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTSRC, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34214 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTSRC, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivSetInterruptSource(base, InterruptSource);
    }
}

/* Design: MCAL-34216 */
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_GetEventTriggerInterruptStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    boolean return_value = FALSE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34217 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_EVTTRIGINTSTATUS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34218 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_EVTTRIGINTSTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetEventTriggerInterruptStatus(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34219 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearEventTriggerInterruptFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 base;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34220 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_EVTTRIGINTFLAG,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34221 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_EVTTRIGINTFLAG,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
        base = Cdd_Pwm_CfgPtr->hwunitcfg[InstanceId].base_addr;
        Cdd_Pwm_PrivClearEventTriggerInterruptFlag(base);
        SchM_Exit_Cdd_Pwm_CDD_PWM_EXCLUSIVE_AREA_0();
    }
}

/* Design: MCAL-34222 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34223 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_INTEVTCOUNTINIT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34224 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_INTEVTCOUNTINIT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureInterruptEventCountInit(InstanceId, Select);
    }
}

/* Design: MCAL-34225 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34226 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_INTEVTCOUNTINIT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34227 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_INTEVTCOUNTINIT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceInterruptEventCountInit(InstanceId);
    }
}

/* Design: MCAL-34228 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetInterruptEventCountInitValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(uint16, AUTOMATIC) EventCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34229 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNTINITVAL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34230 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNTINITVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (15U < EventCount)
    {
        /* Design: MCAL-34231 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_INTEVTCOUNTINITVAL,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetInterruptEventCountInitValue(InstanceId, EventCount);
    }
}

/* Design: MCAL-34232 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetInterruptEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34233 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_INTEVTCNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34234 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_INTEVTCNT, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetInterruptEventCount(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34235 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceEventTriggerInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34236 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_EVTTRIGINT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34237 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_EVTTRIGINT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceEventTriggerInterrupt(InstanceId);
    }
}

/* Design: MCAL-34238 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetMixEvtTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_EtMixSignalSelectType, AUTOMATIC) EtMixSignal,
                               VAR(Cdd_Pwm_EvtMixTriggerSourceType, AUTOMATIC) InterruptSource)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34239 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_MIXEVTTRIGSRC, CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34791,MCAL-34792,MCAL-34793 */
        return_value = Cdd_Pwm_SetMixEvtTriggerSourceDetCheck(InstanceId, EtMixSignal, InterruptSource);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetMixEvtTriggerSource(InstanceId, EtMixSignal, InterruptSource);
    }
}

/* Adc SOC configuration related APIs */

/* Design: MCAL-34240 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34241 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ADCTRIG, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34242 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ADCTRIG,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-34243 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ADCTRIG,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureAdcTrigger(InstanceId, AdcSocType, Select);
    }
}

/* Design: MCAL-34244 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetAdcTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                            VAR(Cdd_Pwm_AdcStartOfConversionSourceType, AUTOMATIC) SocSource)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34245 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGSRC, CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34739,MCAL-34740,MCAL-34741 */
        return_value = Cdd_Pwm_SetAdcTriggerSourceDetCheck(InstanceId, AdcSocType, SocSource);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetAdcTriggerSource(InstanceId, AdcSocType, SocSource);
    }
}

/* Design: MCAL-34246 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetAdcTriggerEventPrescale(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                   VAR(uint16, AUTOMATIC) PreScaleCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34247 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE,
                              CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34742,MCAL-34743,MCAL-34744 */
        return_value = Cdd_Pwm_SetAdcTriggerEventPrescaleDetCheck(InstanceId, AdcSocType, PreScaleCount);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetAdcTriggerEventPrescale(InstanceId, AdcSocType, PreScaleCount);
    }
}

/* Design: MCAL-34248 */
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_GetAdcTriggerFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
    boolean return_value = FALSE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34249 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_ADCTRIGFLAGSTATUS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34250 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_ADCTRIGFLAGSTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-34251 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_ADCTRIGFLAGSTATUS,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetAdcTriggerFlagStatus(InstanceId, AdcSocType);
    }
    return return_value;
}

/* Design: MCAL-34252 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ClearAdcTriggerFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34253 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_ADCTRIGFLAG, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34254 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_ADCTRIGFLAG,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-34255 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_ADCTRIGFLAG,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivClearAdcTriggerFlag(InstanceId, AdcSocType);
    }
}

/* Design: MCAL-34256 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                          VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34257 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ADCTRIGEVTCNTINIT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34258 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ADCTRIGEVTCNTINIT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-34259 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ADCTRIGEVTCNTINIT,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureAdcTriggerEventCountInit(InstanceId, AdcSocType, Select);
    }
}

/* Design: MCAL-34260 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ForceAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34261 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_ADCTRIGEVTCNTINIT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34262 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_ADCTRIGEVTCNTINIT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-34263 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_ADCTRIGEVTCNTINIT,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceAdcTriggerEventCountInit(InstanceId, AdcSocType);
    }
}

/* Design: MCAL-34264 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetAdcTriggerEventCountInitValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                         VAR(uint16, AUTOMATIC) EventCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34265 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL,
                              CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34786,MCAL-34787,MCAL-34788 */
        return_value = Cdd_Pwm_SetAdcTriggerEventCountInitValueDetCheck(InstanceId, AdcSocType, EventCount);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetAdcTriggerEventCountInitValue(InstanceId, AdcSocType, EventCount);
    }
}

/* Design: MCAL-34266 */
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetAdcTriggerEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
    uint16 eventcount = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34267 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_ADCTRIGEVTCNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34268 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_ADCTRIGEVTCNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-34269 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_ADCTRIGEVTCNT,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else
#endif
    {
        eventcount = Cdd_Pwm_PrivGetAdcTriggerEventCount(InstanceId, AdcSocType);
    }
    return eventcount;
}

/* Design: MCAL-34270 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ForceAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                        VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34271 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_ADCTRIGGER, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34272 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_ADCTRIGGER,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_SOC_B < AdcSocType)
    {
        /* Design: MCAL-34273 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_ADCTRIGGER,
                              CDD_PWM_E_INVALID_ADCSOC_TYPE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceAdcTrigger(InstanceId, AdcSocType);
    }
}

/* Digital Compare module related APIs */
/* Design: MCAL-34274 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectDigitalCompareTripInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_DigitalCompareTripInputType, AUTOMATIC) TripInput,
                                      VAR(Cdd_Pwm_DigitalCompareType, AUTOMATIC) DcType)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34275,MCAL-34745,MCAL-34746 */
    Std_ReturnType return_value =
        Cdd_Pwm_DigitalCompareTripInputDetCheck(InstanceId, TripInput, CDD_PWM_SID_SEL_DCTRIPINPUT);

    if ((E_OK == return_value) && (CDD_PWM_DC_TYPE_DCBL < DcType))
    {
        /* Design: MCAL-34276 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SEL_DCTRIPINPUT,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectDigitalCompareTripInput(InstanceId, (uint16)TripInput, DcType);
    }
}

/* DCFILT */
/* Design: MCAL-34277 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareBlankingWindow(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34278 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_BLANKWINDOW,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34279 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_BLANKWINDOW,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareBlankingWindow(InstanceId, Select);
    }
}

/* Design: MCAL-34280 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareWindowInverseMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34281 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_WINDOWINVMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34282 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_WINDOWINVMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareWindowInverseMode(InstanceId, Select);
    }
}

/* Design: MCAL-34283 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareBlankingEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_DigitalCompareBlankingPulseType, AUTOMATIC) BlankingPulse)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34284 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_BLANKEVT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34285 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_BLANKEVT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DC_WINDOW_START_BLANK_PULSE_MIX < BlankingPulse)
    {
        /* Design: MCAL-34286 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_BLANKEVT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareBlankingEvent(InstanceId, BlankingPulse);
    }
}

/* Design: MCAL-34287 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareFilterInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_DigitalCompareFilterInputType, AUTOMATIC) FilterInput)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34288 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_FILTERINPUT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34289 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_FILTERINPUT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DC_WINDOW_SOURCE_DCBEVT2 < FilterInput)
    {
        /* Design: MCAL-34290 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_FILTERINPUT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareFilterInput(InstanceId, FilterInput);
    }
}

/* Design: MCAL-34291 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareEdgeFilter(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34292 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_EDGEFILTER,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34293 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_EDGEFILTER,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareEdgeFilter(InstanceId, Select);
    }
}

/* Design: MCAL-34294 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareEdgeFilterMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_DigitalCompareEdgeFilterModeType, AUTOMATIC) EdgeMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34295 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EDGEFILMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34296 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EDGEFILMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DC_EDGEFILT_MODE_BOTH < EdgeMode)
    {
        /* Design: MCAL-34297 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EDGEFILMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareEdgeFilterMode(InstanceId, EdgeMode);
    }
}

/* Design: MCAL-34298 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(uint16, AUTOMATIC) EdgeCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34299 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EDGEFILEDGECNT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34300 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EDGEFILEDGECNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareEdgeFilterEdgeCount(InstanceId, EdgeCount);
    }
}

/* Design: MCAL-34301 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34302 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DC_EDGEFILEDGECNT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34303 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DC_EDGEFILEDGECNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareEdgeFilterEdgeCount(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34304 */
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetDigitalCompareEdgeFilterEdgeStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34305 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DC_EDGEFILEDGESTATUS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34306 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DC_EDGEFILEDGESTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareEdgeFilterEdgeStatus(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34307 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareWindowOffset(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(uint16, AUTOMATIC) WindowOffsetCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34308 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_WINOFFSET, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34309 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_WINOFFSET,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareWindowOffset(InstanceId, WindowOffsetCount);
    }
}

/* Design: MCAL-34310 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareWindowLength(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(uint16, AUTOMATIC) WindowLengthCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34311 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_WINLENGTH, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34312 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_WINLENGTH,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareWindowLength(InstanceId, WindowLengthCount);
    }
}

/* Design: MCAL-34313 */
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetDigitalCompareBlankingWindowOffsetCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34314 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DC_BLANKWINOFFSETCNT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34315 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DC_BLANKWINOFFSETCNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareBlankingWindowOffsetCount(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34316 */
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetDigitalCompareBlankingWindowLengthCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34317 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DC_BLANKWINLENGTH,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34318 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DC_BLANKWINLENGTH,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareBlankingWindowLengthCount(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34319 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareEventSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                     VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                     VAR(Cdd_Pwm_DigitalCompareEventSourceType, AUTOMATIC) DcEventSource)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34320,MCAL-34321,MCAL-34774 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_DC_EVTSOURCE);

    if (E_OK == return_value)
    {
        if (CDD_PWM_DC_EVENT_2 < DcEvent)
        {
            /* Design: MCAL-34322 */
            /* Report DET error if the channel ID doesn't exist */
            (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EVTSOURCE,
                                  CDD_PWM_E_INVALID_EVENT);
            return_value = E_NOT_OK;
        }
        else if (CDD_PWM_DC_EVENT_SOURCE_FILT_SIGNAL < DcEventSource)
        {
            /* Design: MCAL-34323 */
            /* Report DET error if the channel ID doesn't exist */
            (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EVTSOURCE,
                                  CDD_PWM_E_INVALID_VALUE);
            return_value = E_NOT_OK;
        }
        else
        {
            return_value = E_OK;
        }
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareEventSource(InstanceId, OutputChannel, DcEvent, DcEventSource);
    }
}

/* Design: MCAL-34324 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareEventSyncMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                       VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                       VAR(Cdd_Pwm_DigitalCompareSyncModeType, AUTOMATIC) SyncMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34325 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EVTSYNCMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_DC_EVENT_INPUT_NOT_SYNCED < SyncMode)
    {
        /* Design: MCAL-34326 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DC_EVTSYNCMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        /* Design: MCAL-34749,MCAL-34750,MCAL-34751 */
        return_value = Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(CDD_PWM_SID_SET_DC_EVTSYNCMODE, InstanceId,
                                                                      OutputChannel, DcEvent);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareEventSyncMode(InstanceId, OutputChannel, DcEvent, SyncMode);
    }
}

/* Design: MCAL-34327 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                          VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34328 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_ADCTRIG,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34329 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_ADCTRIG,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34330 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_ADCTRIG,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareAdcTrigger(InstanceId, OutputChannel, Select);
    }
}

/* Design: MCAL-34331 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareSyncEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34332 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_SYNCEVENT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34333 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_SYNCEVENT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34334 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DC_SYNCEVENT,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareSyncEvent(InstanceId, OutputChannel, Select);
    }
}

/* Design: MCAL-34335 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareCBCLatchMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                      VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                      VAR(Cdd_Pwm_DigitalCompareCbcLatchModeType, AUTOMATIC) LatchMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34336 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DCCBC_LATCHMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_DC_CBC_LATCH_ENABLED < LatchMode)
    {
        /* Design: MCAL-34337 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DCCBC_LATCHMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        /* Design: MCAL-34752,MCAL-34753,MCAL-34754 */
        return_value = Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(CDD_PWM_SID_SET_DCCBC_LATCHMODE, InstanceId,
                                                                      OutputChannel, DcEvent);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareCBCLatchMode(InstanceId, OutputChannel, DcEvent, LatchMode);
    }
}

/* Design: MCAL-34338 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectDigitalCompareCBCLatchClearEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                               VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                               VAR(Cdd_Pwm_DigitalCompareCBCLatchClearEventType, AUTOMATIC) ClearEvent)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34339 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DCCBC_LATCHCLREVT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_DC_CBC_LATCH_CLR_ON_CNTR_ZERO_PERIOD < ClearEvent)
    {
        /* Design: MCAL-34340 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DCCBC_LATCHCLREVT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
    {
        /* Design: MCAL-34755,MCAL-34756,MCAL-34757 */
        return_value = Cdd_Pwm_SetDigitalCompareEventSyncModeDetCheck(CDD_PWM_SID_SET_DCCBC_LATCHCLREVT, InstanceId,
                                                                      OutputChannel, DcEvent);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectDigitalCompareCBCLatchClearEvent(InstanceId, OutputChannel, DcEvent, ClearEvent);
    }
}

/* Design: MCAL-34341 */
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_GetDigitalCompareCBCLatchStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                        VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent)
{
    boolean status = FALSE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34342,MCAL-34343,MCAL-34775 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_GET_DCCBC_LATCHSTATUS);

    if ((E_OK == return_value) && (CDD_PWM_DC_EVENT_2 < DcEvent))
    {
        /* Design: MCAL-34344 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DCCBC_LATCHSTATUS,
                              CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        status = Cdd_Pwm_PrivGetDigitalCompareCBCLatchStatus(InstanceId, OutputChannel, DcEvent);
    }
    return status;
}

/* Design: MCAL-34345 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareCounterCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34346 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DCCTRCAP, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34347 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DCCTRCAP,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareCounterCapture(InstanceId, Select);
    }
}

/* Design: MCAL-34348 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareCounterShadowMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(boolean, AUTOMATIC) EnableShadowMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34349 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DCCTRSHDMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34350 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DCCTRSHDMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDigitalCompareCounterShadowMode(InstanceId, EnableShadowMode);
    }
}

/* Design: MCAL-34351 */
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareCaptureStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    boolean return_value = FALSE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34352 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DCCAPSTATUS, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34353 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DCCAPSTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareCaptureStatus(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34354 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareCounterCaptureMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(boolean, AUTOMATIC) DisableClearMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34355 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DCCTRCAPMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34356 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DCCTRCAPMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareCounterCaptureMode(InstanceId, DisableClearMode);
    }
}

/* Design: MCAL-34357 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearDigitalCompareCaptureStatusFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34358 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_DCCAPSTATUSFLAG,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34359 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEAR_DCCAPSTATUSFLAG,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivClearDigitalCompareCaptureStatusFlag(InstanceId);
    }
}

/* Design: MCAL-34360 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareCaptureCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34361 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DCCAPCNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34362 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_DCCAPCNT, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetDigitalCompareCaptureCount(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34363 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareTripCombinationInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_DcTripInputType, AUTOMATIC) TripInput,
                                                    VAR(Cdd_Pwm_DigitalCompareType, AUTOMATIC) DcType,
                                                    VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34364,MCAL-34789,MCAL-34790 */
    Std_ReturnType return_value =
        Cdd_Pwm_TripCombinationInputDetCheck(InstanceId, TripInput, CDD_PWM_SID_CONFIGURE_DCTRIPCOMBINPUT);

    if ((E_OK == return_value) && (CDD_PWM_DC_TYPE_DCBL < DcType))
    {
        /* Design: MCAL-34365 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DCTRIPCOMBINPUT,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivConfigureDigitalCompareTripCombinationInput(InstanceId, (uint16)TripInput, DcType, Select);
    }
}

/* Design: MCAL-34366 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureCaptureInEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34367 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_CAPINEVT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34368 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_CAPINEVT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureCaptureInEvent(InstanceId, Select);
    }
}

/* Design: MCAL-34369 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigCaptureGateInputPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_SelectCaptureGateInputPolarityType, AUTOMATIC) PolaritySelect)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34370 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_CAPGATEINPUTPOL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34371 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_CAPGATEINPUTPOL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (PolaritySelect > CDD_PWM_CAPGATE_INPUT_SYNC_INVERT)
    {
        /* Design: MCAL-34372 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_CAPGATEINPUTPOL,
                              CDD_PWM_E_INVALID_POLARITY);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigCaptureGateInputPolarity(InstanceId, PolaritySelect);
    }
}

/* Design: MCAL-34373 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_InvertCaptureInputPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_SelectCaptureInputPolarityType, AUTOMATIC) PolaritySelect)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34374 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INVERT_CAPGINPUTPOLARITY,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34375 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INVERT_CAPGINPUTPOLARITY,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_CAPTURE_INPUT_CAPIN_SYNC_INVERT < PolaritySelect)
    {
        /* Design: MCAL-34376 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INVERT_CAPGINPUTPOLARITY,
                              CDD_PWM_E_INVALID_POLARITY);
    }
    else
#endif
    {
        Cdd_Pwm_PrivInvertCaptureInputPolarity(InstanceId, PolaritySelect);
    }
}

/* Design: MCAL-34377 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureIndependentPulseLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34378 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_INDPULSELOGIC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34379 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_INDPULSELOGIC,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureIndependentPulseLogic(InstanceId, Select);
    }
}

/* Design: MCAL-34380 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceCaptureEventLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34381 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_CAPEVTLOAD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34382 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_CAPEVTLOAD, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceCaptureEventLoad(InstanceId);
    }
}

/* Design: MCAL-34383 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectCaptureTripInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_DigitalCompareTripInputType, AUTOMATIC) TripInput,
                               VAR(Cdd_Pwm_CaptureInputType, AUTOMATIC) DcType)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34384, */
    Std_ReturnType return_value =
        Cdd_Pwm_DigitalCompareTripInputDetCheck(InstanceId, TripInput, CDD_PWM_SID_SEL_CAPTRIPINPUT);

    if ((E_OK == return_value) && (CDD_PWM_CAPTURE_GATE < DcType))
    {
        /* Design: MCAL-34385 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SEL_CAPTRIPINPUT,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectCaptureTripInput(InstanceId, (uint16)TripInput, DcType);
    }
}

/* Design: MCAL-34386 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureCaptureTripCombinationInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DcTripInputType, AUTOMATIC) TripInput,
                                             VAR(Cdd_Pwm_CaptureInputType, AUTOMATIC) DcType,
                                             VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34387 */
    Std_ReturnType return_value =
        Cdd_Pwm_TripCombinationInputDetCheck(InstanceId, TripInput, CDD_PWM_SID_CONFIGURE_CAPTRIPCOMBINPUT);

    if ((E_OK == return_value) && (CDD_PWM_CAPTURE_GATE < DcType))
    {
        /* Design: MCAL-34388 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_CAPTRIPCOMBINPUT,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivConfigureCaptureTripCombinationInput(InstanceId, (uint16)TripInput, DcType, Select);
    }
}

/* Design: MCAL-34389 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureValleyCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34390 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_VALLEYCAPTURE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34391 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_VALLEYCAPTURE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureValleyCapture(InstanceId, Select);
    }
}

/* Design: MCAL-34392 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_StartValleyCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34393 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_START_VALLEYCAPTURE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34394 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_START_VALLEYCAPTURE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivStartValleyCapture(InstanceId);
    }
}

/* Design: MCAL-34395 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetValleyTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_ValleyTriggerSourceType, AUTOMATIC) Trigger)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34396 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYTRIGSRC, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34397 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYTRIGSRC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_VALLEY_TRIGGER_EVENT_DCBEVT2 < Trigger)
    {
        /* Design: MCAL-34398 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYTRIGSRC,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetValleyTriggerSource(InstanceId, Trigger);
    }
}

/* Design: MCAL-34399 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetValleyTriggerEdgeCounts(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) StartCount,
                                   VAR(uint16, AUTOMATIC) StopCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34400 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYTRIGEDGECNT,
                              CDD_PWM_E_UNINIT);
    }
    else
    {
        /* Design: MCAL-34401,MCAL-34758,MCAL-34759 */
        return_value = Cdd_Pwm_SetValleyTriggerEdgeCountsDetCheck(InstanceId, StartCount, StopCount);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetValleyTriggerEdgeCounts(InstanceId, StartCount, StopCount);
    }
}

/* Design: MCAL-34402 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureValleyHwDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34403 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_VALLEYHWDELAY,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34404 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_VALLEYHWDELAY,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureValleyHwDelay(InstanceId, Select);
    }
}

/* Design: MCAL-34405 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetValleySwDelayValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) DelayOffsetValue)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34406 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYSWDELAYVAL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34407 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYSWDELAYVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetValleySwDelayValue(InstanceId, DelayOffsetValue);
    }
}

/* Design: MCAL-34408 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetValleyDelayDivider(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_ValleyDelayModeType, AUTOMATIC) DelayMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34409 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYDELAYDIVIDER,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34410 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYDELAYDIVIDER,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_4_SW_DELAY < DelayMode)
    {
        /* Design: MCAL-34411 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_VALLEYDELAYDIVIDER,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetValleyDelayDivider(InstanceId, DelayMode);
    }
}

/* Design: MCAL-34412 */
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_GetValleyEdgeStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_ValleyCounterEdgeType, AUTOMATIC) Edge)
{
    boolean return_value = FALSE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34413 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_VALLEYEDGESTATUS,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34414 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_VALLEYEDGESTATUS,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_VALLEY_COUNT_STOP_EDGE < Edge)
    {
        /* Design: MCAL-34415 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_VALLEYEDGESTATUS,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetValleyEdgeStatus(InstanceId, Edge);
    }
    return return_value;
}

/* Design: MCAL-34416 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetValleyCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34417 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_VALLEYCOUNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34418 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_VALLEYCOUNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetValleyCount(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34419 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetValleyHwDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34420 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_VALLEYHWDELAY, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34421 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_VALLEYHWDELAY,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetValleyHwDelay(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34422 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureGlobalLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34423 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_GLBLOAD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34424 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_GLBLOAD,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureGlobalLoad(InstanceId, Select);
    }
}

/* Design: MCAL-34425 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetGlobalLoadTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_GlobalLoadTriggerType, AUTOMATIC) LoadTrigger)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34426 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_GLBLOADTRIG, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34427 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_GLBLOADTRIG,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_GL_LOAD_PULSE_GLOBAL_FORCE < LoadTrigger)
    {
        /* Design: MCAL-34428 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_GLBLOADTRIG,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetGlobalLoadTrigger(InstanceId, LoadTrigger);
    }
}

/* Design: MCAL-34429 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetGlobalLoadEventPrescale(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(uint16, AUTOMATIC) PrescalePulseCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34430 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_GLBLOADEVTPRESCALE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34431 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_GLBLOADEVTPRESCALE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (8U <= PrescalePulseCount)
    {
        /* Design: MCAL-34432 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_GLBLOADEVTPRESCALE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetGlobalLoadEventPrescale(InstanceId, PrescalePulseCount);
    }
}

/* Design: MCAL-34433 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetGlobalLoadEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34434 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_GLBLOADEVTCNT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34435 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_GLBLOADEVTCNT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetGlobalLoadEventCount(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34436 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureGlobalLoadOneShotMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34437 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_GLBLOADOSMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34438 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_GLBLOADOSMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureGlobalLoadOneShotMode(InstanceId, Select);
    }
}

/* Design: MCAL-34439 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetGlobalLoadOneShotLatch(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34440 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_GLBLOADOSLATCH, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34441 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_GLBLOADOSLATCH,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetGlobalLoadOneShotLatch(InstanceId);
    }
}

/* Design: MCAL-34442 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceGlobalLoadOneShotEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34443 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_GLBLOADOSEVT, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34444 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_GLBLOADOSEVT,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceGlobalLoadOneShotEvent(InstanceId);
    }
}

/* Design: MCAL-34445 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureGlobalLoadRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_GlobalLoadType, AUTOMATIC) LoadRegister,
                                     VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34446 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_GLBLOADREG,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34447 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_GLBLOADREG,
                              CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_GLB_LOAD_MAX < (uint16)LoadRegister) || (LoadRegister < CDD_PWM_GL_REGISTER_TBPRD_TBPRDHR))
    {
        /* Design: MCAL-34448 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_GLBLOADREG,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureGlobalLoadRegisters(InstanceId, (uint16)LoadRegister, Select);
    }
}

/* Design: MCAL-34449 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_LockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                      VAR(Cdd_Pwm_LockRegisterGroupType, AUTOMATIC) RegisterGroup)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34450 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_LOCKREGISTER, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34451 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_LOCKREGISTER, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_REGISTER_GROUP_DIGITAL_COMPARE < RegisterGroup)
    {
        /* Design: MCAL-34452 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_LOCKREGISTER,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivLockRegisters(InstanceId, RegisterGroup);
    }
}

/* Design: MCAL-34453 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureXCmpMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34454 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_XCMPMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34455 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_XCMPMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureXCmpMode(InstanceId, Select);
    }
}

/* Design: MCAL-34456 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureSplitXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34457 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_SPLICTXCMP,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34458 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_SPLICTXCMP,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureSplitXCmp(InstanceId, Select);
    }
}

/* Design: MCAL-34459 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_AllocAXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                   VAR(Cdd_Pwm_XCmp_AllocCmpAType, AUTOMATIC) Alloctype)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34460 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ALLOC_AXCMP, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34461 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ALLOC_AXCMP, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XCMP_8_CMPA < Alloctype)
    {
        /* Design: MCAL-34462 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ALLOC_AXCMP, CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivAllocAXCmp(InstanceId, Alloctype);
    }
}

/* Design: MCAL-34463 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_AllocBXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                   VAR(Cdd_Pwm_XCmp_AllocCmpBType, AUTOMATIC) Alloctype)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34464 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ALLOC_BXCMP, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34465 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ALLOC_BXCMP, CDD_PWM_E_INVALID_ID);
    }
    else if ((CDD_PWM_XCMP_8_CMPB < Alloctype) || (CDD_PWM_XCMP_5_CMPB > Alloctype))
    {
        /* Design: MCAL-34466 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ALLOC_BXCMP, CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivAllocBXCmp(InstanceId, Alloctype);
    }
}

/* Design: MCAL-34467 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg,
                        VAR(uint16, AUTOMATIC) XCmpValue)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34468 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPREGVAL, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34469 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPREGVAL, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XTBPRD_SHADOW3 < XCmpReg)
    {
        /* Design: MCAL-34470 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPREGVAL,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetXCmpRegValue(InstanceId, XCmpReg, XCmpValue);
    }
}

/* Design: MCAL-34471 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetCmpShadowRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_XCompareRegType, AUTOMATIC) XCmpReg, VAR(uint16, AUTOMATIC) XCmpValue)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34472 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CMPSHDREGVAL, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34473 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CMPSHDREGVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_CMPD_SHADOW3 < XCmpReg)
    {
        /* Design: MCAL-34474 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CMPSHDREGVAL,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetXCmpShadowRegValue(InstanceId, XCmpReg, XCmpValue);
    }
}

/* Design: MCAL-34475 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetXMinMaxRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_XMinMaxRegType, AUTOMATIC) XMinMaxReg, VAR(uint16, AUTOMATIC) XCmpValue)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34476 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XMINMAXREGVAL, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34477 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XMINMAXREGVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XMIN_SHADOW3 < XMinMaxReg)
    {
        /* Design: MCAL-34478 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XMINMAXREGVAL,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetXMinMaxRegValue(InstanceId, XMinMaxReg, XCmpValue);
    }
}

/* Design: MCAL-34479 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetXCmpActionQualifierAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) ShadowSet,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                     VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                     VAR(Cdd_Pwm_XCmpAqOutputEventType, AUTOMATIC) Event)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34480 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPAQACTION, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34481 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPAQACTION,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34482 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPAQACTION,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
    {
        /* Design: MCAL-34762,MCAL-34763,MCAL-34764 */
        return_value = Cdd_Pwm_SetXCmpActionQualifierActionDetCheck(ShadowSet, Output, Event);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetXCmpActionQualifierAction(InstanceId, ShadowSet, OutputChannel, Output, Event);
    }
}

/* Design: MCAL-34483 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_EnableXLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34484 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_XLOAD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34485 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_ENABLE_XLOAD, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivEnableXLoad(InstanceId);
    }
}

/* Design: MCAL-34486 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceXLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34487 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_XLOAD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34488 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FRC_XLOAD, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceXLoad(InstanceId);
    }
}

/* Design: MCAL-34489 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetXCmpLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_XCmpLoadModeType, AUTOMATIC) Mode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34490 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPLOADMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34491 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XCMP_LOADMULTIPLE < Mode)
    {
        /* Design: MCAL-34492 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetXCmpLoadMode(InstanceId, Mode);
    }
}

/* Design: MCAL-34493 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetXCmpShadowLevel(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_XCmpShadowLevelType, AUTOMATIC) Level)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34494 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHDMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34495 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHDMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XCMP_SHADOWLEVEL_3 < Level)
    {
        /* Design: MCAL-34496 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHDMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetXCmpShadowLevel(InstanceId, Level);
    }
}

/* Design: MCAL-34497 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_XCmpShadowBufPtrType, AUTOMATIC) Ptr)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34498 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHDBUFPTR_LOADONCE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34499 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHDBUFPTR_LOADONCE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_THREE < Ptr)
    {
        /* Design: MCAL-34500 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHDBUFPTR_LOADONCE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetXCmpShadowBufPtrLoadOnce(InstanceId, Ptr);
    }
}

/* Design: MCAL-34501 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetXCmpShadowRepeatBufxCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) Bufferset, VAR(uint32, AUTOMATIC) Count)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    Std_ReturnType return_value = E_NOT_OK;
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34502 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT,
                              CDD_PWM_E_UNINIT);
        return_value = E_NOT_OK;
    }
    else
    {
        /* Design: MCAL-34503,MCAL-34765,MCAL-34766 */
        return_value = Cdd_Pwm_SetXCmpShadowRepeatBufxCountDetCheck(InstanceId, Bufferset, Count);
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetXCmpShadowRepeatBufxCount(InstanceId, Bufferset, Count);
    }
}

/* Design: MCAL-34504 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureMinimumDeadBand(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                 VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34505 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_MINDB, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34506 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_MINDB,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34507 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_MINDB,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureMinimumDeadBand(InstanceId, OutputChannel, Select);
    }
}

/* Design: MCAL-34508 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_InvertMinimumDeadBandSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                    VAR(boolean, AUTOMATIC) Invert)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34509 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INVERT_MINDB, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34510 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INVERT_MINDB, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34511 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_INVERT_MINDB,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivInvertMinimumDeadBandSignal(InstanceId, OutputChannel, Invert);
    }
}

/* Design: MCAL-34512 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectMinimumDeadBandAndOrLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                        VAR(boolean, AUTOMATIC) Logic)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34513 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_MINDB_ANDOR_LOGIC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34514 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_MINDB_ANDOR_LOGIC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34515 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_MINDB_ANDOR_LOGIC,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSelectMinimumDeadBandAndOrLogic(InstanceId, OutputChannel, Logic);
    }
}

/* Design: MCAL-34516 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectMinimumDeadBandBlockingSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                            VAR(boolean, AUTOMATIC) BlockingSignal)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34517 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_MINDB_BLOCKSIGNAL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34518 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_MINDB_BLOCKSIGNAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34519 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_MINDB_BLOCKSIGNAL,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSelectMinimumDeadBandBlockingSignal(InstanceId, OutputChannel, BlockingSignal);
    }
}

/* Design: MCAL-34520 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectMinimumDeadBandReferenceSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(Cdd_Pwm_MindbReferenceSignalType, AUTOMATIC) ReferenceSignal)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34521,MCAL-34522,MCAL-34776 */
    Std_ReturnType return_value =
        Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_MINDB_BANDREFSIGNAL);

    if ((E_OK == return_value) && (CDD_PWM_MINDB_SEL_OUTXBAR_NONE <= ReferenceSignal))
    {
        /* Design: MCAL-34523 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_MINDB_BANDREFSIGNAL,
                              CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectMinimumDeadBandReferenceSignal(InstanceId, OutputChannel, ReferenceSignal);
    }
}

/* Design: MCAL-34524 */
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetMinDeadBandDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34525 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_MINDB_DELAY, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34526 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_MINDB_DELAY,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34527 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_MINDB_DELAY,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetMinDeadBandDelay(InstanceId, OutputChannel);
    }
    return return_value;
}

/* Design: MCAL-34528 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetMinimumDeadBandDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel, VAR(uint16, AUTOMATIC) Delay)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34529 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_MINDB_DELAY, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34530 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_MINDB_DELAY,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34531 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_MINDB_DELAY,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetMinDeadBandDelay(InstanceId, OutputChannel, Delay);
    }
}

/* Design: MCAL-34532 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureIllegalComboLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                   VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34533 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ICL, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34534 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ICL, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34535 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_ICL,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureIllegalComboLogic(InstanceId, OutputChannel, Select);
    }
}

/* Design: MCAL-34536 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectXbarInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                        VAR(Cdd_Pwm_XbarInputType, AUTOMATIC) XbarInput)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34537,MCAL-34538,MCAL-34777 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SELECT_XBARINPUT);

    if ((E_OK == return_value) && (CDD_PWM_MINDB_ICL_XBAR_NONE <= XbarInput))
    {
        /* Design: MCAL-34539 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SELECT_XBARINPUT,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectXbarInput(InstanceId, OutputChannel, XbarInput);
    }
}

/* Design: MCAL-34540 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetLutDecX(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel, VAR(Cdd_Pwm_LutDecXType, AUTOMATIC) Decx,
                   VAR(boolean, AUTOMATIC) Force)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34541,MCAL-34542,MCAL-34778 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_LUTDECX);

    if ((E_OK == return_value) && (CDD_PWM_MINDB_ICL_LUT_NONE <= Decx))
    {
        /* Design: MCAL-34543 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_LUTDECX, CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSetLutDecX(InstanceId, OutputChannel, Decx, Force);
    }
}

/* Design: MCAL-34544 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34545 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DEMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34546 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DEMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDiodeEmulationMode(InstanceId, Select);
    }
}

/* Design: MCAL-34547 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_DiodeEmulationModeType, AUTOMATIC) Mode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34548 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DEMODE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34549 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DEMODE, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DIODE_EMULATION_OST < Mode)
    {
        /* Design: MCAL-34550 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DEMODE, CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDiodeEmulationMode(InstanceId, Mode);
    }
}

/* Design: MCAL-34551 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDiodeEmulationReentryDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) Delay)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34552 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DE_REENTRYDELAY,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34553 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DE_REENTRYDELAY,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDiodeEmulationReentryDelay(InstanceId, Delay);
    }
}

/* Design: MCAL-34555 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDiodeEmulationTripLowSources(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_DETripLowSourceType, AUTOMATIC) Source)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34556 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DE_TRIPLOWSRC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34557 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DE_TRIPLOWSRC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DE_TRIPL_SRC_NONE <= Source)
    {
        /* Design: MCAL-34558 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DE_TRIPLOWSRC,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDiodeEmulationTripLowSources(InstanceId, Source);
    }
}

/* Design: MCAL-34559 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDiodeEmulationTripHighSources(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_DETripHighSourceType, AUTOMATIC) Source)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34560 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DE_TRIPHIGHSRC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34561 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DE_TRIPHIGHSRC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_NONE <= Source)
    {
        /* Design: MCAL-34562 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DE_TRIPHIGHSRC,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDiodeEmulationTripHighSources(InstanceId, Source);
    }
}

/* Design: MCAL-34563 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectDiodeEmulationPwmSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                      VAR(Cdd_Pwm_DiodeEmulationSignalType, AUTOMATIC) DiodeEmuationsignal)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34564,MCAL-34565,MCAL-34779 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_DEPWMSIGNAL);

    if ((E_OK == return_value) && (CDD_PWM_DE_HIGH < DiodeEmuationsignal))
    {
        /* Design: MCAL-34566 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DEPWMSIGNAL,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectDiodeEmulationPwmSignal(InstanceId, OutputChannel, DiodeEmuationsignal);
    }
}

/* Design: MCAL-34567 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectDiodeEmulationTripSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                       VAR(Cdd_Pwm_DiodeEmulationTripSrcType, AUTOMATIC) TripSrc)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34568,MCAL-34569,MCAL-34780 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_DETRIPSIG);
    if ((E_OK == return_value) && (CDD_PWM_DE_SRC_TRIPL < TripSrc))
    {
        /* Design: MCAL-34570 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DETRIPSIG,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivSelectDiodeEmulationTripSignal(InstanceId, OutputChannel, TripSrc);
    }
}

/* Design: MCAL-34571 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_NoBypassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34572 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_NBPDELOGIC, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34573 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_NBPDELOGIC, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivNoBypassDiodeEmulationLogic(InstanceId);
    }
}

/* Design: MCAL-34574 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ByPassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34575 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_BPDELOGIC, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34576 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_BPDELOGIC, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivbypassDiodeEmulationLogic(InstanceId);
    }
}

/* Design: MCAL-34577 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceDiodeEmulationActive(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34578 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_DE_ACTIVE, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34579 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_FORCE_DE_ACTIVE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivForceDiodeEmulationActive(InstanceId);
    }
}

/* Design: MCAL-34580 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDiodeEmulationMonitorModeControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34581 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DEMONITORMODECTRL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34582 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_DEMONITORMODECTRL,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivConfigureDiodeEmulationMonitorModeControl(InstanceId, Select);
    }
}

/* Design: MCAL-34583 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDiodeEmulationMonitorModeStep(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DiodeEmulationDirectionType, AUTOMATIC) Direction,
                                         VAR(uint8, AUTOMATIC) StepSize)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34584 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DEMONITORMODESTEP,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34585 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DEMONITORMODESTEP,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_DE_COUNT_DOWN < Direction)
    {
        /* Design: MCAL-34586 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DEMONITORMODESTEP,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDiodeEmulationMonitorModeStep(InstanceId, Direction, StepSize);
    }
}

/* Design: MCAL-34587 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDiodeEmulationMonitorCounterThreshold(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                 VAR(uint16, AUTOMATIC) Threshold)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34588 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DE_MONITORCNTRTHRESHOLD,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34589 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_DE_MONITORCNTRTHRESHOLD,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivSetDiodeEmulationMonitorCounterThreshold(InstanceId, Threshold);
    }
}

/* Design: MCAL-34590 */
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearDiodeEmulationActiveFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34591 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEARDEACTIVEFLAG, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34592 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CLEARDEACTIVEFLAG,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivClearDiodeEmulationActiveFlag(InstanceId);
    }
}

#if (STD_ON == CDD_PWM_HRPWM_SUPPORTED)
/* Design: MCAL-34593 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) PhaseCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34594 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_PHASESHIFT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34595 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_PHASESHIFT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_MAX_PHASESHIFT <= PhaseCount)
    {
        /* Design: MCAL-34596 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_PHASESHIFT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetPhaseShift(InstanceId, PhaseCount);
    }
}

/* Design: MCAL-34597 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResPhaseShiftOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(uint16, AUTOMATIC) HrPhaseCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34598 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESSHIFT,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34599 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESSHIFT,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_MAX_PHASESHIFT <= HrPhaseCount)
    {
        /* Design: MCAL-34600 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESSHIFT,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResPhaseShiftOnly(InstanceId, HrPhaseCount);
    }
}

/* Design: MCAL-34601 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) PeriodCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34602 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_TBPRD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34603 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_TBPRD,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_MAX_PERIOD <= PeriodCount)
    {
        /* Design: MCAL-34604 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_TBPRD,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetTimeBasePeriod(InstanceId, PeriodCount);
    }
}

/* Design: MCAL-34605 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(uint16, AUTOMATIC) HrPeriodCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34606 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESTBPRD,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34607 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESTBPRD,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_MAX_PERIOD <= HrPeriodCount)
    {
        /* Design: MCAL-34608 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESTBPRD,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResTimeBasePeriodOnly(InstanceId, HrPeriodCount);
    }
}

/* Design: MCAL-34609 */
FUNC(uint32, CDD_PWM_CODE) Cdd_Pwm_HrpwmGetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint32 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34610 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_GET_HRPWM_TBPRD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34611 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_GET_HRPWM_TBPRD, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivHrpwmGetTimeBasePeriod(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34612 */
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_HrpwmGetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34613 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_GET_HRPWM_HIRESTBPRD, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34614 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_GET_HRPWM_HIRESTBPRD,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivHrpwmGetHiResTimeBasePeriodOnly(InstanceId);
    }
    return return_value;
}

/* Design: MCAL-34615 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetMepEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                              VAR(Cdd_Pwm_HrpwmMepEdgeModeType, AUTOMATIC) MepEdgeMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34616,MCAL-34617,MCAL-34781 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SET_HRPWM_MEPEDGESELECT);

    if ((E_OK == return_value) && (CDD_PWM_HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE < MepEdgeMode))
    {
        /* Design: MCAL-34618 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SET_HRPWM_MEPEDGESELECT,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetMepEdgeSelect(InstanceId, OutputChannel, MepEdgeMode);
    }
}

/* Design: MCAL-34619 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetMepControlMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                               VAR(Cdd_Pwm_HrpwmMepCtrlModeType, AUTOMATIC) MepCtrlMode)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34620,MCAL-34621,MCAL-34782 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_HRPWM_MEPCTLMODE);

    if ((E_OK == return_value) && (CDD_PWM_HRPWM_MEP_PHASE_CTRL < MepCtrlMode))
    {
        /* Design: MCAL-34622 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_MEPCTLMODE,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetMepControlMode(InstanceId, OutputChannel, MepCtrlMode);
    }
}

/* Design: MCAL-34623 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetCounterCompareShadowLoadEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                              VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34624,MCAL-34625,MCAL-34783 */
    Std_ReturnType return_value =
        Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_HRPWM_SETCTRCMPSHDLOADEVT);

    if ((E_OK == return_value) && (CDD_PWM_HRPWM_LOAD_ON_CMP_EQ < LoadEvent))
    {
        /* Design: MCAL-34626 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SETCTRCMPSHDLOADEVT,
                              CDD_PWM_E_INVALID_EVENT);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetCounterCompareShadowLoadEvent(InstanceId, OutputChannel, LoadEvent);
    }
}

/* Design: MCAL-34627 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(boolean, AUTOMATIC) EnableOutputSwap)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34628 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SETOUTPUTSWAPMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34629 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SETOUTPUTSWAPMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetOutputSwapMode(InstanceId, EnableOutputSwap);
    }
}

/* Design: MCAL-34630 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetChannelBOutputPath(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_HrpwmChannelBOutputType, AUTOMATIC) OutputOnB)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34631 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SETCHANNELBOUTPATH,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34632 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SETCHANNELBOUTPATH,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_OUTPUT_ON_B_INV_A < OutputOnB)
    {
        /* Design: MCAL-34633 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SETCHANNELBOUTPATH,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetChannelBOutputPath(InstanceId, OutputOnB);
    }
}

/* Design: MCAL-34634 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmConfigureAutoConversion(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34635 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_HRPWM_AUTOCONVERSION,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34636 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_CONFIGURE_HRPWM_AUTOCONVERSION,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmConfigureAutoConversion(InstanceId, Select);
    }
}

/* Design: MCAL-34637 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmConfigurePeriodControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34638 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CONFIGURE_HRPWMPRDCONTROL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34639 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CONFIGURE_HRPWMPRDCONTROL,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmConfigurePeriodControl(InstanceId, Select);
    }
}

/* Design: MCAL-34640 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34641 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CONFIGURE_HRPWM_PHSSHIFTLOAD,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34642 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_CONFIGURE_HRPWM_PHSSHIFTLOAD,
                              CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmConfigurePhaseShiftLoad(InstanceId, Select);
    }
}

/* Design: MCAL-34643 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetSyncPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_HrpwmSyncPulseSourceType, AUTOMATIC) SyncPulseSource)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34644 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SYNCPULSESRC,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34645 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SYNCPULSESRC,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_PWMSYNC_SOURCE_COMPD_DOWN < SyncPulseSource)
    {
        /* Design: MCAL-34646 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_SYNCPULSESRC,
                              CDD_PWM_E_INVALID_EVENT);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetSyncPulseSource(InstanceId, SyncPulseSource);
    }
}

/* Design: MCAL-34647 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetTranslatorRemainder(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TrRemVal)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34648 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_TRANSREM, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34649 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_TRANSREM,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (2048U <= TrRemVal)
    {
        /* Design: MCAL-34650 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_TRANSREM,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetTranslatorRemainder(InstanceId, TrRemVal);
    }
}

/* Design: MCAL-34651 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                    VAR(uint32, AUTOMATIC) CompareCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34652,MCAL-34653,MCAL-34784 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_HRPWMCTRCMP);

    if ((E_OK == return_value) && (0x1000000U <= CompareCount))
    {
        /* Design: MCAL-34654 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWMCTRCMP,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetCounterCompareValue(InstanceId, OutputChannel, CompareCount);
    }
}

/* Design: MCAL-34655 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(uint16, AUTOMATIC) HrCompCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    /* Design: MCAL-34656,MCAL-34657,MCAL-34785 */
    Std_ReturnType return_value = Cdd_Pwm_ChannelDetCheck(InstanceId, OutputChannel, CDD_PWM_SID_SET_HRPWM_HIRESCTRCMP);

    if ((E_OK == return_value) && (256U <= HrCompCount))
    {
        /* Design: MCAL-34658 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESCTRCMP,
                              CDD_PWM_E_INVALID_VALUE);
        return_value = E_NOT_OK;
    }

    if (E_OK == return_value)
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResCounterCompareValueOnly(InstanceId, OutputChannel, HrCompCount);
    }
}

/* Design: MCAL-34659 */
FUNC(uint32, CDD_PWM_CODE)
Cdd_Pwm_HrpwmGetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint32 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34660 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_HRPWM_CTRCMPVAL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34661 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_HRPWM_CTRCMPVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34662 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_HRPWM_CTRCMPVAL,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivHrpwmGetCounterCompareValue(InstanceId, OutputChannel);
    }
    return return_value;
}

/* Design: MCAL-34663 */
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel)
{
    uint16 return_value = 0U;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34664 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_HRPWM_HIRESCTRCMPVAL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34665 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_HRPWM_HIRESCTRCMPVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_OUTPUT_B < OutputChannel)
    {
        /* Design: MCAL-34666 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_GET_HRPWM_HIRESCTRCMPVAL,
                              CDD_PWM_E_INVALID_OUTPUT_CHANNEL);
    }
    else
#endif
    {
        return_value = Cdd_Pwm_PrivGetHiResCounterCompareValueOnly(InstanceId, OutputChannel);
    }
    return return_value;
}

/* Design: MCAL-34667 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetRisingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) RedCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34668 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_RED, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34669 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_RED, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_EDGECOUNT <= RedCount)
    {
        /* Design: MCAL-34670 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_RED,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetRisingEdgeDelay(InstanceId, RedCount);
    }
}

/* Design: MCAL-34671 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResRisingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(uint16, AUTOMATIC) HrRedCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34672 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESRED, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34673 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESRED,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_EDGECOUNT <= HrRedCount)
    {
        /* Design: MCAL-34674 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESRED,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResRisingEdgeDelayOnly(InstanceId, HrRedCount);
    }
}

/* Design: MCAL-34675 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetFallingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) FedCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34676 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_FED, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34677 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_FED, CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_EDGECOUNT <= FedCount)
    {
        /* Design: MCAL-34678 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_FED,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetFallingEdgeDelay(InstanceId, FedCount);
    }
}

/* Design: MCAL-34679 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResFallingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(uint16, AUTOMATIC) HrFedCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34680 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESFED, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34681 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESFED,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_EDGECOUNT <= HrFedCount)
    {
        /* Design: MCAL-34682 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESFED,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResFallingEdgeDelayOnly(InstanceId, HrFedCount);
    }
}

/* Design: MCAL-34683 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetMepStep(VAR(Cdd_Pwm_HrpwmCalInstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) MepCount)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34684 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_MEPSTEP, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HRPWM_CAL_COUNT <= InstanceId)
    {
        /* Design: MCAL-34685 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_MEPSTEP,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_MEPCOUNT <= MepCount)
    {
        /* Design: MCAL-34686 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_MEPSTEP,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetMepStep(InstanceId, MepCount);
    }
}

/* Design: MCAL-34687 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetDeadbandMepEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_HrpwmMepDeadBandEdgeModeType, AUTOMATIC) MepDbEdge)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34688 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_DBMEPEDGESEL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34689 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_DBMEPEDGESEL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_DB_MEP_CTRL_RED_FED < MepDbEdge)
    {
        /* Design: MCAL-34690 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_DBMEPEDGESEL,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetDeadbandMEPEdgeSelect(InstanceId, MepDbEdge);
    }
}

/* Design: MCAL-34691 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetRisingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34692 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_REDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34693 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_REDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_LOAD_ON_CMP_EQ < LoadEvent)
    {
        /* Design: MCAL-34694 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_REDLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetRisingEdgeDelayLoadMode(InstanceId, LoadEvent);
    }
}

/* Design: MCAL-34695 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetFallingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34696 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_FEDLOADMODE,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34697 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_FEDLOADMODE,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_LOAD_ON_CMP_EQ < LoadEvent)
    {
        /* Design: MCAL-34698 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_FEDLOADMODE,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetFallingEdgeDelayLoadMode(InstanceId, LoadEvent);
    }
}

/* Design: MCAL-34699 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmLockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_HrpwmLockRegisterGroupType, AUTOMATIC) RegisterGroup)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34700 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_LOCKREGISTER,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34701 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_LOCKREGISTER,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_HRPWM_REGISTER_GROUP_DIGITAL_COMPARE < RegisterGroup)
    {
        /* Design: MCAL-34702 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_LOCKREGISTER,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmLockRegisters(InstanceId, RegisterGroup);
    }
}

/* Design: MCAL-34703 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg, VAR(uint32, AUTOMATIC) XCmpValue)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34704 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_XCMPREGVAL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34705 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_XCMPREGVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XTBPRD_SHADOW3 < XCmpReg)
    {
        /* Design: MCAL-34706 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_XCMPREGVAL,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetXCmpRegValue(InstanceId, XCmpReg, XCmpValue);
    }
}

/* Design: MCAL-34707 */
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResXCmpRegValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg, VAR(uint16, AUTOMATIC) HrXCmpValue)
{
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34708 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESXCMPREGVAL,
                              CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HW_AND_XLINK_COUNT <= InstanceId)
    {
        /* Design: MCAL-34709 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESXCMPREGVAL,
                              CDD_PWM_E_INVALID_ID);
    }
    else if (CDD_PWM_XTBPRD_SHADOW3 < XCmpReg)
    {
        /* Design: MCAL-34710 */
        /* Report DET error if the channel ID doesn't exist */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SET_HRPWM_HIRESXCMPREGVAL,
                              CDD_PWM_E_INVALID_VALUE);
    }
    else
#endif
    {
        Cdd_Pwm_PrivHrpwmSetHiResXCmpRegValueOnly(InstanceId, XCmpReg, HrXCmpValue);
    }
}

/* Design: MCAL-34711 */
FUNC(Cdd_Pwm_SfoStatusType, CDD_PWM_CODE) Cdd_Pwm_Sfo(VAR(Cdd_Pwm_HrpwmCalInstanceType, AUTOMATIC) Cdd_Pwm_HrpwmCalId)
{
    Cdd_Pwm_SfoStatusType sfo_status = CDD_PWM_SFO_INCOMPLETE;
#if (STD_ON == CDD_PWM_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Pwm_IsInitialized)
    {
        /* Design: MCAL-34712 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SFO, CDD_PWM_E_UNINIT);
    }
    else if (CDD_PWM_HRPWM_CAL_COUNT <= Cdd_Pwm_HrpwmCalId)
    {
        /* Design: MCAL-34821 */
        /* Report DET error if the driver not initialised */
        (void)Det_ReportError(CDD_PWM_MODULE_ID, CDD_PWM_INSTANCE_ID, CDD_PWM_SID_SFO, CDD_PWM_E_INVALID_ID);
    }
    else
#endif
    {
        sfo_status = Cdd_Pwm_PrivSfo(Cdd_Pwm_HrpwmCalId);
    }
    return sfo_status;
}
#endif
#endif

#define CDD_PWM_STOP_SEC_CODE
#include "Cdd_Pwm_MemMap.h"
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Cdd_Pwm.c
 *********************************************************************************************************************/
