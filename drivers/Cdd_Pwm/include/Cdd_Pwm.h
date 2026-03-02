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
 *  Description:  This file contains CDD PWM driver public API function declarations.
 *********************************************************************************************************************/
#ifndef CDD_PWM_H
#define CDD_PWM_H

/**
 * \defgroup CDD_PWM Cdd_Pwm API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Pwm_Cfg.h"
#include "hw_epwm.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

#define CDD_PWM_SYNC_OUT_SOURCE_M                                                                       \
    ((uint16)EPWM_SYNCOUTEN_SWEN | (uint16)EPWM_SYNCOUTEN_ZEROEN | (uint16)EPWM_SYNCOUTEN_CMPBEN |      \
     (uint16)EPWM_SYNCOUTEN_CMPCEN | (uint16)EPWM_SYNCOUTEN_CMPDEN | (uint16)EPWM_SYNCOUTEN_DCAEVT1EN | \
     (uint16)EPWM_SYNCOUTEN_DCBEVT1EN)

#define CDD_PWM_TZINT_SRC_MAX                                                              \
    (uint16)((uint16)CDD_PWM_TZ_INTERRUPT_CBC | (uint16)CDD_PWM_TZ_INTERRUPT_OST |         \
             (uint16)CDD_PWM_TZ_INTERRUPT_DCAEVT1 | (uint16)CDD_PWM_TZ_INTERRUPT_DCAEVT2 | \
             (uint16)CDD_PWM_TZ_INTERRUPT_DCBEVT1 | (uint16)CDD_PWM_TZ_INTERRUPT_DCBEVT2 | \
             (uint16)CDD_PWM_TZ_INTERRUPT_CAPEVT)

#define CDD_PWM_TZFLAG_MAX                                                                                          \
    ((uint16)((uint16)CDD_PWM_TZ_INTERRUPT | (uint16)CDD_PWM_TZ_FLAG_CBC | (uint16)CDD_PWM_TZ_FLAG_OST |            \
              (uint16)CDD_PWM_TZ_FLAG_DCAEVT1 | (uint16)CDD_PWM_TZ_FLAG_DCAEVT2 | (uint16)CDD_PWM_TZ_FLAG_DCBEVT1 | \
              (uint16)CDD_PWM_TZ_FLAG_DCBEVT2 | (uint16)CDD_PWM_TZ_FLAG_CAPEVT))

#define CDD_PWM_TZCBC_INTFLAGS_MAX                                                                           \
    (uint16)((uint16)CDD_PWM_TZ_CBC_FLAG_1 | (uint16)CDD_PWM_TZ_CBC_FLAG_2 | (uint16)CDD_PWM_TZ_CBC_FLAG_3 | \
             (uint16)CDD_PWM_TZ_CBC_FLAG_4 | (uint16)CDD_PWM_TZ_CBC_FLAG_5 | (uint16)CDD_PWM_TZ_CBC_FLAG_6 | \
             (uint16)CDD_PWM_TZ_CBC_FLAG_DCAEVT2 | (uint16)CDD_PWM_TZ_CBC_FLAG_DCBEVT2 |                     \
             (uint16)CDD_PWM_TZ_CBC_FLAG_CAPEVT)

#define CDD_PWM_TZOST_INTFLAGS_MAX                                                                                    \
    (uint16)((uint16)CDD_PWM_TZ_OST_FLAG_OST1 | (uint16)CDD_PWM_TZ_OST_FLAG_OST2 | (uint16)CDD_PWM_TZ_OST_FLAG_OST3 | \
             (uint16)CDD_PWM_TZ_OST_FLAG_OST4 | (uint16)CDD_PWM_TZ_OST_FLAG_OST5 | (uint16)CDD_PWM_TZ_OST_FLAG_OST6 | \
             (uint16)CDD_PWM_TZ_OST_FLAG_DCAEVT1 | (uint16)CDD_PWM_TZ_OST_FLAG_DCBEVT1 |                              \
             (uint16)CDD_PWM_TZ_OST_FLAG_CAPEVT)

#define CDD_PWM_TZFRC_FLAGS_MAX                                                                \
    (uint16)((uint16)CDD_PWM_TZ_FORCE_EVENT_CBC | (uint16)CDD_PWM_TZ_FORCE_EVENT_OST |         \
             (uint16)CDD_PWM_TZ_FORCE_EVENT_DCAEVT1 | (uint16)CDD_PWM_TZ_FORCE_EVENT_DCAEVT2 | \
             (uint16)CDD_PWM_TZ_FORCE_EVENT_DCBEVT1 | (uint16)CDD_PWM_TZ_FORCE_EVENT_DCBEVT2 | \
             (uint16)CDD_PWM_TZ_FORCE_EVENT_CAPEVT)

#define CDD_PWM_TZCAPEVTSIG_MAX (uint16)((uint16)CDD_PWM_TZ_SIGNAL_CAPEVT_CBC | (uint16)CDD_PWM_TZ_SIGNAL_CAPEVT_OST)

#define CDD_PWM_AQEVT_ACTION_MAX                                                                     \
    (uint16)((uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_ZERO | (uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_PERIOD |       \
             (uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_UP_CMPA | (uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_CMPA | \
             (uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_UP_CMPB | (uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_CMPB)

#define CDD_PWM_ADDITIONAL_AQEVT_ACTION_MAX                                                      \
    (uint16)((uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_UP_T1 | (uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_T1 | \
             (uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_UP_T2 | (uint16)CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_T2)

#define CDD_PWM_GLB_LOAD_MAX                                                                           \
    (uint16)((uint16)CDD_PWM_GL_REGISTER_TBPRD_TBPRDHR | (uint16)CDD_PWM_GL_REGISTER_CMPA_CMPAHR |     \
             (uint16)CDD_PWM_GL_REGISTER_CMPB_CMPBHR | (uint16)CDD_PWM_GL_REGISTER_CMPC |              \
             (uint16)CDD_PWM_GL_REGISTER_CMPD | (uint16)CDD_PWM_GL_REGISTER_DBRED_DBREDHR |            \
             (uint16)CDD_PWM_GL_REGISTER_DBFED_DBFEDHR | (uint16)CDD_PWM_GL_REGISTER_DBCTL |           \
             (uint16)CDD_PWM_GL_REGISTER_AQCTLA_AQCTLA2 | (uint16)CDD_PWM_GL_REGISTER_AQCTLB_AQCTLB2 | \
             (uint16)CDD_PWM_GL_REGISTER_AQCSFRC)

#define CDD_PWM_DC_TRIPINPUT_COMBO_MAX                                                               \
    (uint16)((uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN1 | (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN2 |   \
             (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN3 | (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN4 |   \
             (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN5 | (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN6 |   \
             (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN7 | (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN8 |   \
             (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN9 | (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN10 |  \
             (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN11 | (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN12 | \
             (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN14 | (uint16)CDD_PWM_DC_COMBINATIONAL_TRIPIN15)

#if (STD_ON == CDD_PWM_HRPWM_SUPPORTED)
#define CDD_PWM_MAX_PHASESHIFT (0x1000000U)

#define CDD_PWM_HRPWM_MAX_PHASESHIFT (256U)

#define CDD_PWM_MAX_PERIOD (0x1000000U)

#define CDD_PWM_HRPWM_MAX_PERIOD (256U)

#define CDD_PWM_EDGECOUNT (0x200000U)

#define CDD_PWM_HRPWM_EDGECOUNT (128U)

#define CDD_PWM_MEPCOUNT (256U)
#endif

#endif

/* Defines for CDD_PWM Driver version used for compatibility checks.*/
/** \brief Driver Implementation Major Version */
#define CDD_PWM_SW_MAJOR_VERSION (3U)
/** \brief Driver Implementation Minor Version */
#define CDD_PWM_SW_MINOR_VERSION (1U)
/** \brief Driver Implementation Patch Version */
#define CDD_PWM_SW_PATCH_VERSION (0U)

/*  Defines for CDD_PWM Driver AUTOSAR version used for compatibility checks. */
/** \brief AUTOSAR Major version specification implemented by CDD_PWM Driver*/
#define CDD_PWM_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor version specification implemented by CDD_PWM Driver*/
#define CDD_PWM_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_PWM Driver*/
#define CDD_PWM_AR_RELEASE_REVISION_VERSION (1U)

/* CDD PWM Driver ID Info. */
/** \brief Texas Instruments Vendor ID */
#define CDD_PWM_VENDOR_ID ((uint16)44U)
/** \brief CDD PWM Driver Module ID */
#define CDD_PWM_MODULE_ID ((uint16)255U)
/** \brief CDD PWM Instance ID */
#define CDD_PWM_INSTANCE_ID ((uint8)0U)

/** \brief Cdd_Pwm_Init() API Service ID */
#define CDD_PWM_SID_INIT ((uint8)0x00U)
/** \brief Cdd_Pwm_EnableNotification() API Service ID */
#define CDD_PWM_SID_ENABLE_NOTIFICATION ((uint8)0xDDU)
/** \brief Cdd_Pwm_DisableNotification() API Service ID */
#define CDD_PWM_SID_DISABLE_NOTIFICATION ((uint8)0xDEU)
/** \brief Cdd_Pwm_SetInterruptEventCount API Service ID */
#define CDD_PWM_SID_SET_INTEVTCOUNT ((uint8)0xDCU)
/** \brief Cdd_Pwm_GetVersionInfo() API Service ID */
#define CDD_PWM_SID_GET_VERSION_INFO ((uint8)0x07U)

/* Error codes returned by Cdd Pwm functions. */
#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)

/* The Service Id is one of the argument to Det_ReportError function and is used to identify the
 * source of the error */
/** \brief Cdd_Pwm_DeInit() API Service ID */
#define CDD_PWM_SID_DEINIT ((uint8)0x01U)
/** \brief Cdd_Pwm_SetDutyCycle() API Service ID */
#define CDD_PWM_SID_SET_DUTY_CYCLE ((uint8)0x02U)
/** \brief Cdd_Pwm_SetPeriod() API Service ID */
#define CDD_PWM_SID_SET_PERIOD ((uint8)0x03U)
/** \brief Cdd_Pwm_SetOutputToIdle() API Service ID */
#define CDD_PWM_SID_SET_OUTPUT_TO_IDLE ((uint8)0x04U)

#else

/** \brief Cdd_Pwm_SetEmulationMode() API Service ID */
#define CDD_PWM_SID_SET_EMULATION_MODE               ((uint8)0xE2U)

/** \brief Cdd_Pwm_ConfigureTripZoneNotification() API Service ID */
#define CDD_PWM_SID_CONFIGURE_TRIPZONE_NOTIFICATION  ((uint8)0xE3U)

/** \brief Cdd_Pwm_SetTimeBaseCounter() API Service ID */
#define CDD_PWM_SID_SET_TB_COUNTER                   ((uint8)0xE4U)

/** \brief Cdd_Pwm_SetCountModeAfterSync() API Service ID */
#define CDD_PWM_SID_SET_COUNTMODE_AFTERSYNC          ((uint8)0xE5U)

/** \brief Cdd_Pwm_SetClockPrescaler() API Service ID */
#define CDD_PWM_SID_SET_CLOCKPRESCALE                ((uint8)0x05U)

/** \brief Cdd_Pwm_ForceSyncPulse() API Service ID */
#define CDD_PWM_SID_FORCE_SYNC_PULSE                 ((uint8)0x06U)

/** \brief Cdd_Pwm_SetSyncInPulseSource() API Service ID */
#define CDD_PWM_SID_SET_SYNC_INPULSE_SOURCE          ((uint8)0xE1U)

/** \brief Cdd_Pwm_ConfigureSyncOutPulseSource() API Service ID */
#define CDD_PWM_SID_CONFIGURE_SYNCOUT_PULSE          ((uint8)0x08U)

/** \brief Cdd_Pwm_SetOneShotSyncOutTrigger() API Service ID */
#define CDD_PWM_SID_SET_ONESHOT_SYNCOUT_TRIGGER      ((uint8)0x09U)

/** \brief Cdd_Pwm_SetPeriodLoadMode API Service ID */
#define CDD_PWM_SID_SET_PRDLOADMODE                  ((uint8)0x4FU)

/** \brief Cdd_Pwm_ConfigurePhaseShiftLoad() API Service ID */
#define CDD_PWM_SID_CONFIGURE_PHSSHIFTLOAD           ((uint8)0x0AU)

/** \brief Cdd_Pwm_SetTimeBaseCounterMode() API Service ID */
#define CDD_PWM_SID_SET_TBCOUNTERMODE                ((uint8)0x0BU)

/** \brief Cdd_Pwm_SelectPeriodLoadEvent() API Service ID */
#define CDD_PWM_SID_SELECT_PERIODLOADEVT             ((uint8)0x0CU)

/** \brief Cdd_Pwm_ConfigureOneShotSync() API Service ID */
#define CDD_PWM_SID_CONFIGURE_ONESHTSYNC             ((uint8)0x0DU)

/** \brief Cdd_Pwm_StartOneShotSync() API Service ID */
#define CDD_PWM_SID_SET_START_ONESHTSYNC             ((uint8)0x0EU)

/** \brief Cdd_Pwm_GetTimeBaseCounterValue() API Service ID */
#define CDD_PWM_SID_GET_TBCOUNTERVAL                 ((uint8)0x0FU)

/** \brief Cdd_Pwm_GetTimeBaseCounterOverflowStatus() API Service ID */
#define CDD_PWM_SID_GET_TBCOUNTER_OVFSTATUS          ((uint8)0x10U)

/** \brief Cdd_Pwm_ClearTimeBaseCounterOverflowEvent() API Service ID */
#define CDD_PWM_SID_CLEAR_TBOVFEVT                   ((uint8)0x11U)

/** \brief  Cdd_Pwm_GetSyncStatus API Service ID */
#define CDD_PWM_SID_GETSYNCSTATUS                    ((uint8)0x12U)

/** \brief Cdd_Pwm_ClearSyncEvent API Service ID */
#define CDD_PWM_SID_SET_CLEARSYNCEVT                 ((uint8)0x13U)

/** \brief Cdd_Pwm_GetTimeBaseCounterDirection API Service ID */
#define CDD_PWM_SID_GET_TBCNTRDIRECTION              ((uint8)0x14U)

/** \brief Cdd_Pwm_SetPhaseShift API Service ID */
#define CDD_PWM_SID_SET_PHASESHIFT                   ((uint8)0x15U)

/** \brief Cdd_Pwm_SetTimeBasePeriod API Service ID */
#define CDD_PWM_SID_SET_TB_PERIOD                    ((uint8)0x16U)

/** \brief Cdd_Pwm_GetTimeBasePeriod API Service ID */
#define CDD_PWM_SID_GET_TB_PERIOD                    ((uint8)0x17U)

// /** \brief Cdd_Pwm_ConfigureEpwmXLink API Service ID */
// #define CDD_PWM_SID_CONFIG_XLINK       ((uint8) 0x18U)

/** \brief Cdd_Pwm_SetCounterCompareShadowLoadMode API Service ID */
#define CDD_PWM_SID_SET_CTRCMP_SHADOWLOADMODE        ((uint8)0x19U)

/** \brief Cdd_Pwm_DisableCounterCompareShadowLoadMode API Service ID */
#define CDD_PWM_SID_DISABLE_CTRCMP_SHADOWLOADMODE    ((uint8)0x1AU)

/** \brief Cdd_Pwm_SetCounterCompareValue API Service ID */
#define CDD_PWM_SID_SET_CTRCMPVAL                    ((uint8)0x1BU)

/** \brief Cdd_Pwm_GetCounterCompareValue API Service ID */
#define CDD_PWM_SID_GET_CTRCMPVAL                    ((uint8)0x1CU)

/** \brief Cdd_Pwm_GetCounterCompareShadowStatus API Service ID */
#define CDD_PWM_SID_GET_CTRCMP_SHDSTATUS             ((uint8)0x1DU)

/** \brief Cdd_Pwm_ConfigureLinkDutyHR API Service ID */
#define CDD_PWM_SID_CONFIGURE_LINKDUTYHR             ((uint8)0x1EU)

/** \brief Cdd_Pwm_SetActionQualifierShadowLoadMode API Service ID */
#define CDD_PWM_SID_SET_AQSHDLOADMODE                ((uint8)0x1FU)

/** \brief Cdd_Pwm_DisableActionQualifierShadowLoadMode API Service ID */
#define CDD_PWM_SID_DISABLE_AQSHDLOADMODE            ((uint8)0x20U)

/** \brief Cdd_Pwm_SetActionQualifierT1TriggerSource API Service ID */
#define CDD_PWM_SID_SET_AQT1TRIGSRC                  ((uint8)0x21U)

/** \brief Cdd_Pwm_SetActionQualifierT2TriggerSource API Service ID */
#define CDD_PWM_SID_SET_AQT2TRIGSRC                  ((uint8)0x22U)

/** \brief Cdd_Pwm_SetActionQualifierAction API Service ID */
#define CDD_PWM_SID_SET_AQACTION                     ((uint8)0x23U)

/** \brief Cdd_Pwm_SetActionQualifierActionComplete API Service ID */
#define CDD_PWM_SID_SET_AQACTION_COMPLETE            ((uint8)0x24U)

/** \brief Cdd_Pwm_SetAdditionalActionQualifierActionComplete API Service ID */
#define CDD_PWM_SID_SET_ADDITIONALAQACTION_COMPLETE  ((uint8)0x25U)

/** \brief Cdd_Pwm_SetActionQualifierContSwForceShadowMode API Service ID */
#define CDD_PWM_SID_SET_AQCNTSWFRC_SHDMODE           ((uint8)0x26U)

/** \brief Cdd_Pwm_SetActionQualifierContSwForceAction API Service ID */
#define CDD_PWM_SID_SET_AQCNTSWFRC_ACTION            ((uint8)0x27U)

/** \brief Cdd_Pwm_SetActionQualifierSwAction API Service ID */
#define CDD_PWM_SID_SET_AQSWACTION                   ((uint8)0x28U)

/** \brief Cdd_Pwm_ForceActionQualifierSwAction API Service ID */
#define CDD_PWM_SID_FRC_AQSWACTION                   ((uint8)0x29U)

/** \brief Cdd_Pwm_SetDeadBandOutputSwapMode API Service ID */
#define CDD_PWM_SID_SET_DBOUTPUTSWAPMODE             ((uint8)0x2AU)

/** \brief Cdd_Pwm_SetDeadBandDelayMode API Service ID */
#define CDD_PWM_SID_SET_DBODELAYMODE                 ((uint8)0x2BU)

/** \brief Cdd_Pwm_SetDeadBandDelayPolarity API Service ID */
#define CDD_PWM_SID_SET_DBODELAY_POLARITY            ((uint8)0x2CU)

/** \brief Cdd_Pwm_SetRisingEdgeDeadBandDelayInput API Service ID */
#define CDD_PWM_SID_SET_REDB_DELAYINPUT              ((uint8)0x2DU)

/** \brief Cdd_Pwm_SetFallingEdgeDeadBandDelayInput API Service ID */
#define CDD_PWM_SID_SET_FEDB_DELAYINPUT              ((uint8)0x2EU)

/** \brief Cdd_Pwm_SetDeadBandControlShadowLoadMode API Service ID */
#define CDD_PWM_SID_SET_DBCTL_SHDLOADMODE            ((uint8)0x2FU)

/** \brief Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode API Service ID */
#define CDD_PWM_SID_SET_RED_COUNTSHDLOADMODE         ((uint8)0x30U)

/** \brief Cdd_Pwm_DisableRisingEdgeDelayCountShadowLoadMode API Service ID */
#define CDD_PWM_SID_DISABLE_RED_COUNTSHDLOADMODE     ((uint8)0x31U)

/** \brief Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadMode API Service ID */
#define CDD_PWM_SID_SET_FED_COUNTSHDLOADMODE         ((uint8)0x32U)

/** \brief Cdd_Pwm_DisableFallingEdgeDelayCountShadowLoadMode API Service ID */
#define CDD_PWM_SID_DISABLE_FED_COUNTSHDLOADMODE     ((uint8)0x33U)

/** \brief Cdd_Pwm_SetDeadBandCounterClock API Service ID */
#define CDD_PWM_SID_SET_DBCTRCLK                     ((uint8)0x34U)

/** \brief Cdd_Pwm_SetRisingEdgeDelayCount API Service ID */
#define CDD_PWM_SID_SET_REDCOUNT                     ((uint8)0x35U)

/** \brief Cdd_Pwm_SetFallingEdgeDelayCount API Service ID */
#define CDD_PWM_SID_SET_FEDCOUNT                     ((uint8)0x36U)

/** \brief Cdd_Pwm_ConfigureChopper API Service ID */
#define CDD_PWM_SID_CONFIGURE_CHOPPER                ((uint8)0x37U)

/** \brief Cdd_Pwm_SetChopperDutyCycle API Service ID */
#define CDD_PWM_SID_SET_CHOPPER_DC                   ((uint8)0x38U)

/** \brief Cdd_Pwm_SetChopperFreq API Service ID */
#define CDD_PWM_SID_SET_CHOPPER_FREQ                 ((uint8)0x39U)

/** \brief Cdd_Pwm_SetChopperFirstPulseWidth API Service ID */
#define CDD_PWM_SID_SET_CHOPPER_FIRSTPULWIDTH        ((uint8)0x3AU)

/** \brief Cdd_Pwm_ConfigureTripZoneSignals API Service ID */
#define CDD_PWM_SID_CONFIGURE_TZSIGNALS              ((uint8)0x3BU)

/** \brief Cdd_Pwm_SetTripZoneDigitalCompareEventCondition API Service ID */
#define CDD_PWM_SID_SET_TZDC_EVTCONDITION            ((uint8)0x3CU)

/** \brief Cdd_Pwm_ConfigureTripZoneAdvAction API Service ID */
#define CDD_PWM_SID_CONFIGURE_TZADVACTION            ((uint8)0x3DU)

/** \brief Cdd_Pwm_SetTripZoneAction API Service ID */
#define CDD_PWM_SID_SET_TZACTION                     ((uint8)0x3EU)

/** \brief Cdd_Pwm_SetTripZoneAdvAction API Service ID */
#define CDD_PWM_SID_SET_TZADVACTION                  ((uint8)0x3FU)

/** \brief Cdd_Pwm_SetTripZoneAdvDigitalCompareAction API Service ID */
#define CDD_PWM_SID_SET_TZADV_DCACTION               ((uint8)0x40U)

/** \brief gCdd_Pwm_ConfigureTripZoneInterrupt API Service ID */
#define CDD_PWM_SID_CONFIGURE_TZINT                  ((uint8)0x41U)

/** \brief Cdd_Pwm_GetTripZoneFlagStatus  API Service ID */
#define CDD_PWM_SID_GET_TZFLAGSTATUS                 ((uint8)0x42U)

/** \brief Cdd_Pwm_GetCycleByCycleTripZoneFlagStatus API Service ID */
#define CDD_PWM_SID_GET_CBCTZ_FLAGSTATUS             ((uint8)0x43U)

/** \brief Cdd_Pwm_GetOneShotTripZoneFlagStatus API Service ID */
#define CDD_PWM_SID_GET_OSTZ_FLAGSTATUS              ((uint8)0x44U)

/** \brief Cdd_Pwm_SelectCycleByCycleTripZoneClearEvent API Service ID */
#define CDD_PWM_SID_SELECT_CBCTZCLREVT               ((uint8)0x45U)

/** \brief Cdd_Pwm_ClearTripZoneFlag API Service ID */
#define CDD_PWM_SID_CLEAR_TZFLAG                     ((uint8)0x46U)

/** \brief Cdd_Pwm_ClearCycleByCycleTripZoneFlag API Service ID */
#define CDD_PWM_SID_CLEAR_CBCTZFLAG                  ((uint8)0x47U)

/** \brief Cdd_Pwm_ClearOneShotTripZoneFlag API Service ID */
#define CDD_PWM_SID_CLEAR_OSTZFLAG                   ((uint8)0x48U)

/** \brief Cdd_Pwm_ForceTripZoneEvent API Service ID */
#define CDD_PWM_SID_FORCE_TZEVT                      ((uint8)0x49U)

/** \brief Cdd_Pwm_ConfigureTripOutSource API Service ID */
#define CDD_PWM_SID_CONFIGURE_TRIPOUTSRC             ((uint8)0x4AU)

/** \brief Cdd_Pwm_ConfigureInterrupt API Service ID */
#define CDD_PWM_SID_CONFIGURE_INTERRUPT              ((uint8)0x4BU)

/** \brief Cdd_Pwm_SetInterruptSource API Service ID */
#define CDD_PWM_SID_SET_INTSRC                       ((uint8)0x4CU)

/** \brief Cdd_Pwm_GetEventTriggerInterruptStatus API Service ID */
#define CDD_PWM_SID_GET_EVTTRIGINTSTATUS             ((uint8)0x4DU)

/** \brief Cdd_Pwm_ClearEventTriggerInterruptFlag API Service ID */
#define CDD_PWM_SID_CLEAR_EVTTRIGINTFLAG             ((uint8)0x4EU)

/** \brief Cdd_Pwm_ConfigureInterruptEventCountInit API Service ID */
#define CDD_PWM_SID_CONFIGURE_INTEVTCOUNTINIT        ((uint8)0x50U)

/** \brief Cdd_Pwm_ForceInterruptEventCountInit API Service ID */
#define CDD_PWM_SID_FORCE_INTEVTCOUNTINIT            ((uint8)0x51U)

/** \brief Cdd_Pwm_SetInterruptEventCountInitValue API Service ID */
#define CDD_PWM_SID_SET_INTEVTCOUNTINITVAL           ((uint8)0x52U)

/** \brief Cdd_Pwm_GetInterruptEventCount API Service ID */
#define CDD_PWM_SID_GET_INTEVTCNT                    ((uint8)0x53U)

/** \brief Cdd_Pwm_ForceEventTriggerInterrupt API Service ID */
#define CDD_PWM_SID_FORCE_EVTTRIGINT                 ((uint8)0x54U)

/** \brief Cdd_Pwm_SetMixEvtTriggerSource API Service ID */
#define CDD_PWM_SID_SET_MIXEVTTRIGSRC                ((uint8)0x55U)

/** \brief Cdd_Pwm_ConfigureAdcTrigger API Service ID */
#define CDD_PWM_SID_CONFIGURE_ADCTRIG                ((uint8)0x56U)

/** \brief Cdd_Pwm_SetAdcTriggerSource API Service ID */
#define CDD_PWM_SID_SET_ADCTRIGSRC                   ((uint8)0x57U)

/** \brief Cdd_Pwm_SetAdcTriggerEventPrescale API Service ID */
#define CDD_PWM_SID_SET_ADCTRIGEVTPRESCALE           ((uint8)0x58U)

/** \brief Cdd_Pwm_GetAdcTriggerFlagStatus API Service ID */
#define CDD_PWM_SID_GET_ADCTRIGFLAGSTATUS            ((uint8)0x59U)

/** \brief Cdd_Pwm_ClearAdcTriggerFlag API Service ID */
#define CDD_PWM_SID_CLEAR_ADCTRIGFLAG                ((uint8)0x5AU)

/** \brief Cdd_Pwm_ConfigureAdcTriggerEventCountInit API Service ID */
#define CDD_PWM_SID_CONFIGURE_ADCTRIGEVTCNTINIT      ((uint8)0x5BU)

/** \brief Cdd_Pwm_ForceAdcTriggerEventCountInit API Service ID */
#define CDD_PWM_SID_FORCE_ADCTRIGEVTCNTINIT          ((uint8)0x5CU)

/** \brief Cdd_Pwm_SetAdcTriggerEventCountInitValue API Service ID */
#define CDD_PWM_SID_SET_ADCTRIGEVTCNTINITVAL         ((uint8)0x5DU)

/** \brief Cdd_Pwm_GetAdcTriggerEventCount API Service ID */
#define CDD_PWM_SID_GET_ADCTRIGEVTCNT                ((uint8)0x5EU)

/** \brief Cdd_Pwm_ForceAdcTrigger API Service ID */
#define CDD_PWM_SID_FORCE_ADCTRIGGER                 ((uint8)0x5FU)

/** \brief Cdd_Pwm_ConfigureDigitalCompareBlankingWindow API Service ID */
#define CDD_PWM_SID_CONFIGURE_DC_BLANKWINDOW         ((uint8)0x60U)

/** \brief Cdd_Pwm_ConfigureDigitalCompareWindowInverseMode API Service ID */
#define CDD_PWM_SID_CONFIGURE_DC_WINDOWINVMODE       ((uint8)0x61U)

/** \brief Cdd_Pwm_SetDigitalCompareBlankingEvent API Service ID */
#define CDD_PWM_SID_SET_DC_BLANKEVT                  ((uint8)0x62U)

/** \brief Cdd_Pwm_SetDigitalCompareFilterInput API Service ID */
#define CDD_PWM_SID_SET_DC_FILTERINPUT               ((uint8)0x63U)

/** \brief Cdd_Pwm_ConfigureDigitalCompareEdgeFilter API Service ID */
#define CDD_PWM_SID_CONFIGURE_DC_EDGEFILTER          ((uint8)0x64U)

/** \brief Cdd_Pwm_SetDigitalCompareEdgeFilterMode API Service ID */
#define CDD_PWM_SID_SET_DC_EDGEFILMODE               ((uint8)0x65U)

/** \brief Cdd_Pwm_SetDigitalCompareEdgeFilterEdgeCount API Service ID */
#define CDD_PWM_SID_SET_DC_EDGEFILEDGECNT            ((uint8)0x66U)

/** \brief Cdd_Pwm_GetDigitalCompareEdgeFilterEdgeCount API Service ID */
#define CDD_PWM_SID_GET_DC_EDGEFILEDGECNT            ((uint8)0x67U)

/** \brief Cdd_Pwm_GetDigitalCompareEdgeFilterEdgeStatus API Service ID */
#define CDD_PWM_SID_GET_DC_EDGEFILEDGESTATUS         ((uint8)0x68U)

/** \brief Cdd_Pwm_SetDigitalCompareWindowOffset API Service ID */
#define CDD_PWM_SID_SET_DC_WINOFFSET                 ((uint8)0x69U)

/** \brief Cdd_Pwm_SetDigitalCompareWindowLength API Service ID */
#define CDD_PWM_SID_SET_DC_WINLENGTH                 ((uint8)0x6AU)

/** \brief Cdd_Pwm_GetDigitalCompareBlankingWindowOffsetCount API Service ID */
#define CDD_PWM_SID_GET_DC_BLANKWINOFFSETCNT         ((uint8)0x6BU)

/** \brief Cdd_Pwm_GetDigitalCompareBlankingWindowLengthCount API Service ID */
#define CDD_PWM_SID_GET_DC_BLANKWINLENGTH            ((uint8)0x6CU)

/** \brief Cdd_Pwm_SetDigitalCompareEventSource API Service ID */
#define CDD_PWM_SID_SET_DC_EVTSOURCE                 ((uint8)0x6DU)

/** \brief Cdd_Pwm_SetDigitalCompareEventSyncMode API Service ID */
#define CDD_PWM_SID_SET_DC_EVTSYNCMODE               ((uint8)0x6EU)

/** \brief Cdd_Pwm_ConfigureDigitalCompareAdcTrigger API Service ID */
#define CDD_PWM_SID_CONFIGURE_DC_ADCTRIG             ((uint8)0x6FU)

/** \brief Cdd_Pwm_ConfigureDigitalCompareSyncEvent API Service ID */
#define CDD_PWM_SID_CONFIGURE_DC_SYNCEVENT           ((uint8)0x70U)

/** \brief Cdd_Pwm_SetDigitalCompareCBCLatchMode API Service ID */
#define CDD_PWM_SID_SET_DCCBC_LATCHMODE              ((uint8)0x71U)

/** \brief Cdd_Pwm_SelectDigitalCompareCBCLatchClearEvent API Service ID */
#define CDD_PWM_SID_SET_DCCBC_LATCHCLREVT            ((uint8)0x72U)

/** \brief Cdd_Pwm_GetDigitalCompareCBCLatchStatus API Service ID */
#define CDD_PWM_SID_GET_DCCBC_LATCHSTATUS            ((uint8)0x73U)

/** \brief Cdd_Pwm_ConfigureDigitalCompareCounterCapture API Service ID */
#define CDD_PWM_SID_CONFIGURE_DCCTRCAP               ((uint8)0x74U)

/** \brief Cdd_Pwm_SetDigitalCompareCounterShadowMode API Service ID */
#define CDD_PWM_SID_SET_DCCTRSHDMODE                 ((uint8)0x75U)

/** \brief Cdd_Pwm_GetDigitalCompareCaptureStatus API Service ID */
#define CDD_PWM_SID_GET_DCCAPSTATUS                  ((uint8)0x76U)

/** \brief Cdd_Pwm_ConfigureDigitalCompareCounterCaptureMode API Service ID */
#define CDD_PWM_SID_CONFIGURE_DCCTRCAPMODE           ((uint8)0x77U)

/** \brief Cdd_Pwm_ClearDigitalCompareCaptureStatusFlag API Service ID */
#define CDD_PWM_SID_CLEAR_DCCAPSTATUSFLAG            ((uint8)0x78U)

/** \brief Cdd_Pwm_GetDigitalCompareCaptureCount API Service ID */
#define CDD_PWM_SID_GET_DCCAPCNT                     ((uint8)0x79U)

/** \brief Cdd_Pwm_ConfigureDigitalCompareTripCombinationInput API Service ID */
#define CDD_PWM_SID_CONFIGURE_DCTRIPCOMBINPUT        ((uint8)0x7AU)

/** \brief Cdd_Pwm_ConfigureCaptureInEvent API Service ID */
#define CDD_PWM_SID_CONFIGURE_CAPINEVT               ((uint8)0x7BU)

/** \brief Cdd_Pwm_ConfigCaptureGateInputPolarity API Service ID */
#define CDD_PWM_SID_CONFIGURE_CAPGATEINPUTPOL        ((uint8)0x7CU)

/** \brief Cdd_Pwm_InvertCaptureInputPolarity API Service ID */
#define CDD_PWM_SID_INVERT_CAPGINPUTPOLARITY         ((uint8)0x7DU)

/** \brief Cdd_Pwm_ConfigureIndependentPulseLogic API Service ID */
#define CDD_PWM_SID_CONFIGURE_INDPULSELOGIC          ((uint8)0x7EU)

/** \brief Cdd_Pwm_ForceCaptureEventLoad API Service ID */
#define CDD_PWM_SID_FRC_CAPEVTLOAD                   ((uint8)0x7FU)

/** \brief Cdd_Pwm_SelectCaptureTripInput API Service ID */
#define CDD_PWM_SID_SEL_CAPTRIPINPUT                 ((uint8)0x80U)

/** \brief Cdd_Pwm_ConfigureCaptureTripCombinationInput API Service ID */
#define CDD_PWM_SID_CONFIGURE_CAPTRIPCOMBINPUT       ((uint8)0x81U)

/** \brief Cdd_Pwm_ConfigureValleyCapture API Service ID */
#define CDD_PWM_SID_CONFIGURE_VALLEYCAPTURE          ((uint8)0x82U)

/** \brief Cdd_Pwm_StartValleyCapture API Service ID */
#define CDD_PWM_SID_START_VALLEYCAPTURE              ((uint8)0x83U)

/** \brief Cdd_Pwm_SetValleyTriggerSource API Service ID */
#define CDD_PWM_SID_SET_VALLEYTRIGSRC                ((uint8)0x84U)

/** \brief Cdd_Pwm_SetValleyTriggerEdgeCounts API Service ID */
#define CDD_PWM_SID_SET_VALLEYTRIGEDGECNT            ((uint8)0x85U)

/** \brief Cdd_Pwm_ConfigureValleyHwDelay API Service ID */
#define CDD_PWM_SID_CONFIGURE_VALLEYHWDELAY          ((uint8)0x86U)

/** \brief Cdd_Pwm_SetValleySwDelayValue API Service ID */
#define CDD_PWM_SID_SET_VALLEYSWDELAYVAL             ((uint8)0x87U)

/** \brief Cdd_Pwm_SetValleyDelayDivider API Service ID */
#define CDD_PWM_SID_SET_VALLEYDELAYDIVIDER           ((uint8)0x88U)

/** \brief Cdd_Pwm_GetValleyEdgeStatus API Service ID */
#define CDD_PWM_SID_GET_VALLEYEDGESTATUS             ((uint8)0x89U)

/** \brief Cdd_Pwm_GetValleyCount API Service ID */
#define CDD_PWM_SID_GET_VALLEYCOUNT                  ((uint8)0x8AU)

/** \brief Cdd_Pwm_GetValleyHwDelay API Service ID */
#define CDD_PWM_SID_GET_VALLEYHWDELAY                ((uint8)0x8BU)

/** \brief Cdd_Pwm_ConfigureGlobalLoad API Service ID */
#define CDD_PWM_SID_CONFIGURE_GLBLOAD                ((uint8)0x8CU)

/** \brief Cdd_Pwm_SetGlobalLoadTrigger API Service ID */
#define CDD_PWM_SID_SET_GLBLOADTRIG                  ((uint8)0x8DU)

/** \brief Cdd_Pwm_SetGlobalLoadEventPrescale API Service ID */
#define CDD_PWM_SID_SET_GLBLOADEVTPRESCALE           ((uint8)0x8EU)

/** \brief Cdd_Pwm_GetGlobalLoadEventCount API Service ID */
#define CDD_PWM_SID_GET_GLBLOADEVTCNT                ((uint8)0x8FU)

/** \brief Cdd_Pwm_SetGlobalLoadOneShotLatch API Service ID */
#define CDD_PWM_SID_SET_GLBLOADOSLATCH               ((uint8)0x90U)

/** \brief Cdd_Pwm_ConfigureGlobalLoadOneShotMode API Service ID */
#define CDD_PWM_SID_CONFIGURE_GLBLOADOSMODE          ((uint8)0x91U)

/** \brief Cdd_Pwm_ForceGlobalLoadOneShotEvent API Service ID */
#define CDD_PWM_SID_FRC_GLBLOADOSEVT                 ((uint8)0x92U)

/** \brief Cdd_Pwm_ConfigureGlobalLoadRegisters API Service ID */
#define CDD_PWM_SID_CONFIGURE_GLBLOADREG             ((uint8)0x93U)

/** \brief Cdd_Pwm_LockRegisters API Service ID */
#define CDD_PWM_SID_LOCKREGISTER                     ((uint8)0x94U)

/** \brief Cdd_Pwm_ConfigureXCmpMode API Service ID */
#define CDD_PWM_SID_CONFIGURE_XCMPMODE               ((uint8)0x95U)

/** \brief Cdd_Pwm_ConfigureSplitXCmp API Service ID */
#define CDD_PWM_SID_CONFIGURE_SPLICTXCMP             ((uint8)0x96U)

/** \brief Cdd_Pwm_AllocAXCmp API Service ID */
#define CDD_PWM_SID_ALLOC_AXCMP                      ((uint8)0x97U)

/** \brief Cdd_Pwm_AllocBXCmp API Service ID */
#define CDD_PWM_SID_ALLOC_BXCMP                      ((uint8)0x98U)

/** \brief Cdd_Pwm_SetXCmpRegValue API Service ID */
#define CDD_PWM_SID_SET_XCMPREGVAL                   ((uint8)0x99U)

/** \brief Cdd_Pwm_SetCmpShadowRegValue API Service ID */
#define CDD_PWM_SID_SET_CMPSHDREGVAL                 ((uint8)0x9AU)

/** \brief Cdd_Pwm_SetXMinMaxRegValue API Service ID */
#define CDD_PWM_SID_SET_XMINMAXREGVAL                ((uint8)0x9BU)

/** \brief Cdd_Pwm_SetXCmpActionQualifierAction API Service ID */
#define CDD_PWM_SID_SET_XCMPAQACTION                 ((uint8)0x9CU)

/** \brief Cdd_Pwm_EnableXLoad API Service ID */
#define CDD_PWM_SID_ENABLE_XLOAD                     ((uint8)0x9DU)

/** \brief Cdd_Pwm_ForceXLoad API Service ID */
#define CDD_PWM_SID_FRC_XLOAD                        ((uint8)0x9EU)

/** \brief Cdd_Pwm_SetXCmpLoadMode API Service ID */
#define CDD_PWM_SID_SET_XCMPLOADMODE                 ((uint8)0x9FU)

/** \brief Cdd_Pwm_SetXCmpShadowLevel API Service ID */
#define CDD_PWM_SID_SET_XCMPSHDMODE                  ((uint8)0xA0U)

/** \brief Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce API Service ID */
#define CDD_PWM_SID_SET_XCMPSHDBUFPTR_LOADONCE       ((uint8)0xA1U)

/** \brief Cdd_Pwm_SetXCmpShadowRepeatBufxCount API Service ID */
#define CDD_PWM_SID_SET_XCMPSHD_REPBUFCOUNT          ((uint8)0xA2U)

/** \brief Cdd_Pwm_ConfigureMinimumDeadBand API Service ID */
#define CDD_PWM_SID_CONFIGURE_MINDB                  ((uint8)0xA3U)

/** \brief Cdd_Pwm_InvertMinimumDeadBandSignal API Service ID */
#define CDD_PWM_SID_INVERT_MINDB                     ((uint8)0xA4U)

/** \brief Cdd_Pwm_SelectMinimumDeadBandAndOrLogic API Service ID */
#define CDD_PWM_SID_SELECT_MINDB_ANDOR_LOGIC         ((uint8)0xA5U)

/** \brief Cdd_Pwm_SelectMinimumDeadBandBlockingSignal API Service ID */
#define CDD_PWM_SID_SELECT_MINDB_BLOCKSIGNAL         ((uint8)0xA6U)

/** \brief Cdd_Pwm_SelectMinimumDeadBandReferenceSignal API Service ID */
#define CDD_PWM_SID_SET_MINDB_BANDREFSIGNAL          ((uint8)0xA7U)

/** \brief Cdd_Pwm_DisableDeadBandControlShadowLoadMode API Service ID */
#define CDD_PWM_SID_DISABLE_DBCTL_SHDLOADMODE        ((uint8)0xA8U)

/** \brief Cdd_Pwm_GetMinDeadBandDelay API Service ID */
#define CDD_PWM_SID_GET_MINDB_DELAY                  ((uint8)0xA9U)

/** \brief Cdd_Pwm_SetMinimumDeadBandDelay API Service ID */
#define CDD_PWM_SID_SET_MINDB_DELAY                  ((uint8)0xAAU)

/** \brief Cdd_Pwm_SelectDigitalCompareTripInput API Service ID */
#define CDD_PWM_SID_SEL_DCTRIPINPUT                  ((uint8)0xABU)

/** \brief Cdd_Pwm_ConfigureIllegalComboLogic API Service ID */
#define CDD_PWM_SID_CONFIGURE_ICL                    ((uint8)0xACU)

/** \brief Cdd_Pwm_SelectXbarInput API Service ID */
#define CDD_PWM_SID_SELECT_XBARINPUT                 ((uint8)0xADU)

/** \brief Cdd_Pwm_SetLutDecX API Service ID */
#define CDD_PWM_SID_SET_LUTDECX                      ((uint8)0xAEU)

/** \brief Cdd_Pwm_ConfigureDiodeEmulationMode API Service ID */
#define CDD_PWM_SID_CONFIGURE_DEMODE                 ((uint8)0xAFU)

/** \brief Cdd_Pwm_SetDiodeEmulationMode API Service ID */
#define CDD_PWM_SID_SET_DEMODE                       ((uint8)0xB0U)

/** \brief Cdd_Pwm_SetDiodeEmulationReentryDelay API Service ID */
#define CDD_PWM_SID_SET_DE_REENTRYDELAY              ((uint8)0xB1U)

/** \brief Cdd_Pwm_ConfigureDiodeEmulationTripLowSources API Service ID */
#define CDD_PWM_SID_CONFIGURE_DE_TRIPLOWSRC          ((uint8)0xB2U)

/** \brief Cdd_Pwm_ConfigureDiodeEmulationTripHighSources API Service ID */
#define CDD_PWM_SID_CONFIGURE_DE_TRIPHIGHSRC         ((uint8)0xB3U)

/** \brief Cdd_Pwm_SelectDiodeEmulationPwmSignal API Service ID */
#define CDD_PWM_SID_SET_DEPWMSIGNAL                  ((uint8)0xB4U)

/** \brief Cdd_Pwm_SelectDiodeEmulationTripSignal API Service ID */
#define CDD_PWM_SID_SET_DETRIPSIG                    ((uint8)0xB5U)

/** \brief Cdd_Pwm_NoBypassDiodeEmulationLogic API Service ID */
#define CDD_PWM_SID_NBPDELOGIC                       ((uint8)0xB6U)

/** \brief Cdd_Pwm_ByPassDiodeEmulationLogic API Service ID */
#define CDD_PWM_SID_BPDELOGIC                        ((uint8)0xB7U)

/** \brief Cdd_Pwm_ForceDiodeEmulationActive API Service ID */
#define CDD_PWM_SID_FORCE_DE_ACTIVE                  ((uint8)0xB8U)

/** \brief Cdd_Pwm_ConfigureDiodeEmulationMonitorModeControl API Service ID */
#define CDD_PWM_SID_CONFIGURE_DEMONITORMODECTRL      ((uint8)0xB9U)

/** \brief Cdd_Pwm_SetDiodeEmulationMonitorModeStep API Service ID */
#define CDD_PWM_SID_SET_DEMONITORMODESTEP            ((uint8)0xBAU)

/** \brief Cdd_Pwm_SetDiodeEmulationMonitorCounterThreshold API Service ID */
#define CDD_PWM_SID_SET_DE_MONITORCNTRTHRESHOLD      ((uint8)0xBBU)

/** \brief Cdd_Pwm_ClearDiodeEmulationActiveFlag API Service ID */
#define CDD_PWM_SID_CLEARDEACTIVEFLAG                ((uint8)0xBCU)

/** \brief Cdd_Pwm_HrpwmSetPhaseShift API Service ID */
#define CDD_PWM_SID_SET_HRPWM_PHASESHIFT             ((uint8)0xBDU)

/** \brief Cdd_Pwm_HrpwmSetHiResPhaseShiftOnly API Service ID */
#define CDD_PWM_SID_SET_HRPWM_HIRESSHIFT             ((uint8)0xBEU)

/** \brief Cdd_Pwm_HrpwmSetTimeBasePeriod API Service ID */
#define CDD_PWM_SID_SET_HRPWM_TBPRD                  ((uint8)0xBFU)

/** \brief Cdd_Pwm_HrpwmSetHiResTimeBasePeriodOnly API Service ID */
#define CDD_PWM_SID_SET_HRPWM_HIRESTBPRD             ((uint8)0xC0U)

/** \brief Cdd_Pwm_HrpwmGetTimeBasePeriod API Service ID */
#define CDD_PWM_GET_HRPWM_TBPRD                      ((uint8)0xC1U)

/** \brief Cdd_Pwm_HrpwmGetHiResTimeBasePeriodOnly API Service ID */
#define CDD_PWM_GET_HRPWM_HIRESTBPRD                 ((uint8)0xC2U)

/** \brief Cdd_Pwm_HrpwmSetMepEdgeSelect API Service ID */
#define CDD_PWM_SET_HRPWM_MEPEDGESELECT              ((uint8)0xC3U)

/** \brief Cdd_Pwm_HrpwmSetMepControlMode API Service ID */
#define CDD_PWM_SID_SET_HRPWM_MEPCTLMODE             ((uint8)0xC4U)

/** \brief Cdd_Pwm_HrpwmSetCounterCompareShadowLoadEvent API Service ID */
#define CDD_PWM_SID_SET_HRPWM_SETCTRCMPSHDLOADEVT    ((uint8)0xC5U)

/** \brief Cdd_Pwm_HrpwmSetOutputSwapMode API Service ID */
#define CDD_PWM_SID_SET_HRPWM_SETOUTPUTSWAPMODE      ((uint8)0xC6U)

/** \brief Cdd_Pwm_HrpwmSetChannelBOutputPath API Service ID */
#define CDD_PWM_SID_SET_HRPWM_SETCHANNELBOUTPATH     ((uint8)0xC7U)

/** \brief Cdd_Pwm_HrpwmConfigureAutoConversion API Service ID */
#define CDD_PWM_SID_CONFIGURE_HRPWM_AUTOCONVERSION   ((uint8)0xC8U)

/** \brief Cdd_Pwm_HrpwmConfigurePeriodControl API Service ID */
#define CDD_PWM_SID_SET_CONFIGURE_HRPWMPRDCONTROL    ((uint8)0xC9U)

/** \brief Cdd_Pwm_PrivHrpwmConfigurePhaseShiftLoad API Service ID */
#define CDD_PWM_SID_SET_CONFIGURE_HRPWM_PHSSHIFTLOAD ((uint8)0xCAU)

/** \brief Cdd_Pwm_HrpwmSetSyncPulseSource API Service ID */
#define CDD_PWM_SID_SET_HRPWM_SYNCPULSESRC           ((uint8)0xCBU)

/** \brief Cdd_Pwm_HrpwmSetTranslatorRemainder API Service ID */
#define CDD_PWM_SID_SET_HRPWM_TRANSREM               ((uint8)0xCCU)

/** \brief Cdd_Pwm_HrpwmSetCounterCompareValue API Service ID */
#define CDD_PWM_SID_SET_HRPWMCTRCMP                  ((uint8)0xCDU)

/** \brief Cdd_Pwm_HrpwmSetHiResCounterCompareValueOnly API Service ID */
#define CDD_PWM_SID_SET_HRPWM_HIRESCTRCMP            ((uint8)0xCEU)

/** \brief Cdd_Pwm_HrpwmGetCounterCompareValue API Service ID */
#define CDD_PWM_SID_GET_HRPWM_CTRCMPVAL              ((uint8)0xCFU)

/** \brief Cdd_Pwm_GetHiResCounterCompareValueOnly API Service ID */
#define CDD_PWM_SID_GET_HRPWM_HIRESCTRCMPVAL         ((uint8)0xD0U)

/** \brief Cdd_Pwm_HrpwmSetRisingEdgeDelay API Service ID */
#define CDD_PWM_SID_SET_HRPWM_RED                    ((uint8)0xD1U)

/** \brief Cdd_Pwm_HrpwmSetHiResRisingEdgeDelayOnly API Service ID */
#define CDD_PWM_SID_SET_HRPWM_HIRESRED               ((uint8)0xD2U)

/** \brief Cdd_Pwm_HrpwmSetFallingEdgeDelay API Service ID */
#define CDD_PWM_SID_SET_HRPWM_FED                    ((uint8)0xD3U)

/** \brief Cdd_Pwm_HrpwmSetHiResFallingEdgeDelayOnly API Service ID */
#define CDD_PWM_SID_SET_HRPWM_HIRESFED               ((uint8)0xD4U)

/** \brief Cdd_Pwm_HrpwmSetMepStep API Service ID */
#define CDD_PWM_SID_SET_HRPWM_MEPSTEP                ((uint8)0xD5U)

/** \brief Cdd_Pwm_HrpwmSetDeadbandMepEdgeSelect API Service ID */
#define CDD_PWM_SID_SET_HRPWM_DBMEPEDGESEL           ((uint8)0xD6U)

/** \brief Cdd_Pwm_HrpwmSetRisingEdgeDelayLoadMode API Service ID */
#define CDD_PWM_SID_SET_HRPWM_REDLOADMODE            ((uint8)0xD7U)

/** \brief Cdd_Pwm_HrpwmSetFallingEdgeDelayLoadMode API Service ID */
#define CDD_PWM_SID_SET_HRPWM_FEDLOADMODE            ((uint8)0xD8U)

/** \brief Cdd_Pwm_HrpwmLockRegisters API Service ID */
#define CDD_PWM_SID_SET_HRPWM_LOCKREGISTER           ((uint8)0xD9U)

/** \brief Cdd_Pwm_HrpwmSetXCmpRegValue API Service ID */
#define CDD_PWM_SID_SET_HRPWM_XCMPREGVAL             ((uint8)0xDAU)

/** \brief Cdd_Pwm_HrpwmSetHiResXCmpRegValueOnly API Service ID */
#define CDD_PWM_SID_SET_HRPWM_HIRESXCMPREGVAL        ((uint8)0xDBU)

/** \brief Cdd_Pwm_ConfigureTripZone2Signals API Service ID */
#define CDD_PWM_SID_CONFIGURE_TZ2SIGNALS             ((uint8)0xDFU)

/** \brief Cdd_Pwm_Sfo API Service ID */
#define CDD_PWM_SID_SFO                              ((uint8)0xE0)

#endif

/* Design: MCAL-33831 */
/** \brief API service used without module initialization */
#define CDD_PWM_E_UNINIT ((uint8)0x0AU)

/* Design: MCAL-33832 */
/** \brief API Cdd_Pwm_Init service called while the PWM driver has already been initialized */
#define CDD_PWM_E_ALREADY_INITIALIZED ((uint8)0x0BU)

/* Design: MCAL-33833 */
/** \brief  API service called with invalid parameter ID */
#define CDD_PWM_E_INVALID_ID ((uint8)0x0DU)

/* Design: MCAL-33834 */
/** \brief Enable/disable notification function for a PWM instance whose configuration set has no
 * notification available */
#define CDD_PWM_E_NOTIF_CAPABILITY ((uint8)0x0EU)

/* Design: MCAL-33835 */
/** \brief  API service called with invalid pointer */
#define CDD_PWM_E_PARAM_POINTER ((uint8)0x0CU)

/* Design: MCAL-33836 */
/** \brief API service called when the event count is invalid/out-of-range */
#define CDD_PWM_E_INVALID_VALUE ((uint8)0x13U)

/* Design: MCAL-33837 */
/** \brief  API service called with invalid parameter ID */
#define CDD_PWM_E_INVALID_OUTPUT_CHANNEL ((uint8)0x0FU)

/* Design: MCAL-33828 */

/* Errors specific to ADVANCED MODE APIs */
#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

/* Design: MCAL-33838 */
/** \brief API service called with invalid value */
#define CDD_PWM_E_INVALID_PRESCALE ((uint8)0x14U)

/* Design: MCAL-33839 */
/** \brief API service called with invalid value */
#define CDD_PWM_E_INVALID_CTRCOMPARE ((uint8)0x15U)

/* Design: MCAL-33840 */
/** \brief API service called with invalid value */
#define CDD_PWM_E_INVALID_EVENT ((uint8)0x16U)

/* Design: MCAL-33841 */
/** \brief API service called with invalid value */
#define CDD_PWM_E_INVALID_POLARITY ((uint8)0x17U)

/* Design: MCAL-33842 */
/** \brief API service called with invalid value */
#define CDD_PWM_E_INVALID_ADCSOC_TYPE ((uint8)0x18U)

/* Design: MCAL-33843 */
/** \brief API service called with invalid value */
#define CDD_PWM_E_INVALID_EVENT_SRC ((uint8)0x19U)

/* Design: MCAL-33844 */
/** \brief API service called with invalid value */
#define CDD_PWM_E_INVALID_SHDSET ((uint8)0x1AU)

#else

/* Design: MCAL-33845 */
/** \brief  API service called for the instance whose channel class is not variable period */
#define CDD_PWM_E_CHANNEL_CLASS            ((uint8)0x0FU)

/* Design: MCAL-33846 */
/** \brief API service called when the notification is already enabled */
#define CDD_PWM_E_NOTIF_ALREADY_ENABLED    ((uint8)0x10U)

/* Design: MCAL-33847 */
/** \brief API service called when the channel configured for the notification is invalid */
#define CDD_PWM_E_INVALID_EDGENOTIFICATION ((uint8)0x11U)

/* Design: MCAL-33848 */
/** \brief API service called with the invalid duty cycle value */
#define CDD_PWM_E_INVALID_DUTY_CYCLE       ((uint8)0x14U)

/* Design: MCAL-33849 */
/** \brief Cdd_Pwm_SetInterruptEventCount API service called when the PWM channel is active */
#define CDD_PWM_E_BUSY                     ((uint8)0x15U)

/* Design: MCAL-33850 */
/** \brief API service called with invalid value */
#define CDD_PWM_E_INVALID_INTEVTCOUNT      ((uint8)0x16U)

#endif

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Numeric Identifier of a PWM channel */
typedef uint8 Cdd_Pwm_ChannelType;

/** \brief Numeric Identifier of a PWM instance */
typedef uint8 Cdd_Pwm_InstanceType;

/** \brief Numeric Identifier of a HRPWMCAL instance */
typedef uint8 Cdd_Pwm_HrpwmCalInstanceType;

/** \brief Period of the PWM instance */
typedef uint16 Cdd_Pwm_PeriodType;

/** \brief Duty cycle of the PWM channel */
typedef uint16 Cdd_Pwm_DutyCycleType;

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/* DESIGN: MCAL-33829 */
/** \brief Notification function pointer */
typedef P2FUNC(void, CDD_PWM_CODE, Cdd_Pwm_NotificationType)(void);

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)
/* DESIGN: MCAL-33830 */
/** \brief Trip zone notification function pointer */
typedef P2FUNC(void, CDD_PWM_CODE, Cdd_Pwm_TripZoneNotificationType)(uint16 TripZoneFlag);
#endif

#endif

/** \brief Cdd_Pwm_OutputChannelType determines the channel output */
typedef enum
{
    /** \brief Ouput channel A */
    CDD_PWM_OUTPUT_A = 0U,
    /** \brief Ouput channel B */
    CDD_PWM_OUTPUT_B = 1U
} Cdd_Pwm_OutputChannelType;

/** \brief Enumeration to define the time base counter mode */
typedef enum
{
    CDD_PWM_COUNTER_MODE_UP          = 0U, /** \brief Up - count mode */
    CDD_PWM_COUNTER_MODE_DOWN        = 1U, /** \brief Down - count mode */
    CDD_PWM_COUNTER_MODE_UP_DOWN     = 2U, /** \brief Up - down - count mode */
    CDD_PWM_COUNTER_MODE_STOP_FREEZE = 3U  /** \brief Stop - Freeze counter */
} Cdd_Pwm_TimeBaseCountModeType;

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)

/* Design: MCAL-33853 */
/** \brief Output Status type */
typedef enum
{
    CDD_PWM_HIGH, /*!< \brief  The PWM channel is in high state */
    CDD_PWM_LOW   /*!< \brief  The PWM channel is in low state */
} Cdd_Pwm_OutputStateType;

/** \brief Edge notification type */
typedef enum
{
    CDD_PWM_RISING_EDGE,  /*!< \brief Notification will be called when a rising edge occurs on the
                             PWM output signal */
    CDD_PWM_FALLING_EDGE, /*!< \brief Notification will be called when a falling edge occurs on the
                             PWM output signal*/
    /*!< \brief Notification will be called when either a rising edge or falling edge occur on the
       PWM output signal */
    CDD_PWM_BOTH_EDGES,
    CDD_PWM_EDGE_NONE /*!< \brief No notification will be called */
} Cdd_Pwm_EdgeNotificationType;

/* Design: MCAL-33851 */
/** \brief Channel class type */
typedef enum
{
    /** \brief The PWM channel has a variable period. The duty cycle and the period can be changed.
     */
    CDD_PWM_VARIABLE_PERIOD,
    /** \brief The PWM channel has a fixed period. Only the duty cycle can be changed */
    CDD_PWM_FIXED_PERIOD
} Cdd_Pwm_ChannelClassType;
#endif

/** \brief Cdd_Pwm_ActionQualifierOutputEventType output defines the action qualifier event type */
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
} Cdd_Pwm_ActionQualifierOutputEventType;

/*****************************************************************************
 *
 * Values that can be passed to Cdd_Pwm_SetActionQualifierSWAction(),
 * Cdd_Pwm_SetActionQualifierAction() as the \e outPut parameter.
 *
 *****************************************************************************/
typedef enum
{
    CDD_PWM_AQ_OUTPUT_NO_CHANGE = 0U, /** \brief No change in the output pins */
    CDD_PWM_AQ_OUTPUT_LOW       = 1U, /** \brief Set output pins to low */
    CDD_PWM_AQ_OUTPUT_HIGH      = 2U, /** \brief Set output pins to High */
    CDD_PWM_AQ_OUTPUT_TOGGLE    = 3U  /** \brief Toggle the output pins */
} Cdd_Pwm_ActionQualifierOutputType;

/*****************************************************************************
 *
 * Values that can be passed to Cdd_Pwm_SetClockPrescaler() as the
 * \e prescaler parameter.
 *
 *****************************************************************************/
typedef enum
{
    CDD_PWM_CLOCK_DIVIDER_1   = 0U, /* Divide clock by 1 */
    CDD_PWM_CLOCK_DIVIDER_2   = 1U, /* Divide clock by 2 */
    CDD_PWM_CLOCK_DIVIDER_4   = 2U, /* Divide clock by 4 */
    CDD_PWM_CLOCK_DIVIDER_8   = 3U, /* Divide clock by 8 */
    CDD_PWM_CLOCK_DIVIDER_16  = 4U, /* Divide clock by 16 */
    CDD_PWM_CLOCK_DIVIDER_32  = 5U, /* Divide clock by 32 */
    CDD_PWM_CLOCK_DIVIDER_64  = 6U, /* Divide clock by 64 */
    CDD_PWM_CLOCK_DIVIDER_128 = 7U  /* Divide clock by 128 */
} Cdd_Pwm_ClockDividerType;

/*****************************************************************************
 *
 * Values that can be passed to Cdd_Pwm_SetClockPrescaler() as the
 * \e highSpeedPrescaler parameter.
 *
 *****************************************************************************/
typedef enum
{
    CDD_PWM_HSCLOCK_DIVIDER_1  = 0U, /* Divide clock by 1 */
    CDD_PWM_HSCLOCK_DIVIDER_2  = 1U, /* Divide clock by 2 */
    CDD_PWM_HSCLOCK_DIVIDER_4  = 2U, /* Divide clock by 4 */
    CDD_PWM_HSCLOCK_DIVIDER_6  = 3U, /* Divide clock by 6 */
    CDD_PWM_HSCLOCK_DIVIDER_8  = 4U, /* Divide clock by 8 */
    CDD_PWM_HSCLOCK_DIVIDER_10 = 5U, /* Divide clock by 10 */
    CDD_PWM_HSCLOCK_DIVIDER_12 = 6U, /* Divide clock by 12 */
    CDD_PWM_HSCLOCK_DIVIDER_14 = 7U  /* Divide clock by 14 */
} Cdd_Pwm_HighSpeedClkDivType;

/* Counter Compare Module type */
typedef enum
{
    CDD_PWM_COUNTER_COMPARE_A = 0U, /* Counter compare A */
    CDD_PWM_COUNTER_COMPARE_B = 2U, /* Counter compare B */
    CDD_PWM_COUNTER_COMPARE_C = 5U, /* Counter compare C */
    CDD_PWM_COUNTER_COMPARE_D = 7U  /* Counter compare D */
} Cdd_Pwm_CounterCompareModuleType;

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

/** \brief Enumeration for interrupt source */
typedef enum
{
    /** \brief Time-base counter equal to zero */
    CDD_PWM_NT_TBCTR_DISABLED = 0U,
    /** \brief Time-base counter equal to zero */
    CDD_PWM_INT_TBCTR_ZERO = 1U,
    /** \brief Time-base counter equal to period */
    CDD_PWM_INT_TBCTR_PERIOD = 2U,
    /** \brief Time-base counter based on mixed events (ETINTMIX) */
    CDD_PWM_INT_TBCTR_ETINTMIX = 3U,
    /** \brief Time-base counter equal to CMPA when the timer is incrementing */
    CDD_PWM_INT_TBCTR_U_CMPA = 4U,
    /** \brief Time-base counter equal to CMPAwhen the timer is decrementing */
    CDD_PWM_INT_TBCTR_D_CMPA = 5U,
    /** \brief Time-base counter equal to CMPB when the timer is incrementing */
    CDD_PWM_INT_TBCTR_U_CMPB = 6U,
    /** \brief Time-base counter equal to CMPB when the timer is decrementing */
    CDD_PWM_INT_TBCTR_D_CMPB = 7U,
    /** \brief Time-base counter equal to CMPC when the timer is incrementing */
    CDD_PWM_INT_TBCTR_U_CMPC = 8U,
    /** \brief Time-base counter equal to CMPC when the timer is decrementing */
    CDD_PWM_INT_TBCTR_D_CMPC = 10U,
    /** \brief Time-base counter equal to CMPD when the timer is incrementing */
    CDD_PWM_INT_TBCTR_U_CMPD = 12U,
    /** \brief Time-base counter equal to CMPD when the timer is decrementing */
    CDD_PWM_INT_TBCTR_D_CMPD = 14U
} Cdd_Pwm_InterruptSourceType;

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

typedef enum
{
    /* Stop after next Time Base counter increment or decrement */
    CDD_PWM_EMULATION_STOP_AFTER_NEXT_TB = 0U,
    /* Stop when counter completes whole cycle */
    CDD_PWM_EMULATION_STOP_AFTER_FULL_CYCLE = 1U,
    /* Free run */
    CDD_PWM_EMULATION_FREE_RUN = 2U
} Cdd_Pwm_EmulationModeType;

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

/** \brief Enumeration for SFO status */
typedef enum
{
    CDD_PWM_SFO_INCOMPLETE = 0U,
    CDD_PWM_SFO_COMPLETE   = 1U,
    CDD_PWM_SFO_ERROR      = 2U
} Cdd_Pwm_SfoStatusType;

/** \brief Time Base counter synchronization mode */
typedef enum
{
    CDD_PWM_COUNT_MODE_DOWN_AFTER_SYNC = 0U, /* Count down after sync event */
    CDD_PWM_COUNT_MODE_UP_AFTER_SYNC   = 1U  /* Count up after sync event */
} Cdd_Pwm_SyncCountModeType;

typedef enum
{
    /* Software force generated EPWM sync-out pulse */
    CDD_PWM_SYNC_OUT_PULSE_ON_SOFTWARE = EPWM_SYNCOUTEN_SWEN,
    /* Counter zero event generates EPWM sync-out pulse */
    CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_ZERO = EPWM_SYNCOUTEN_ZEROEN,
    /* Counter equal to CMPB event generates EPWM sync-out pulse */
    CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_B = EPWM_SYNCOUTEN_CMPBEN,
    /* Counter equal to CMPC event generates EPWM sync-out pulse */
    CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_C = EPWM_SYNCOUTEN_CMPCEN,
    /* Counter equal to CMPD event generates EPWM sync-out pulse */
    CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_D = EPWM_SYNCOUTEN_CMPDEN,
    /* DCA Event 1 Sync signal generates EPWM sync-out pulse */
    CDD_PWM_SYNC_OUT_PULSE_ON_DCA_EVT1_SYNC = EPWM_SYNCOUTEN_DCAEVT1EN,
    /* DCB Event 1 Sync signal generates EPWM sync-out pulse */
    CDD_PWM_SYNC_OUT_PULSE_ON_DCB_EVT1_SYNC = EPWM_SYNCOUTEN_DCBEVT1EN,
    /* All the above sources */
    CDD_PWM_SYNC_OUT_PULSE_ON_ALL = CDD_PWM_SYNC_OUT_SOURCE_M
} Cdd_Pwm_SyncOutPulseSourceType;

/** \brief Values that can be passed to Cdd_Pwm_SetOneShotSyncOutTrigger() as the trigger parameter. */
typedef enum
{
    CDD_PWM_OSHT_SYNC_OUT_TRIG_SYNC   = 0x0U, /* Trigger is OSHT sync */
    CDD_PWM_OSHT_SYNC_OUT_TRIG_RELOAD = 0x1U  /* Trigger is OSHT reload */
} Cdd_Pwm_OneShotSyncOutTriggerType;

/** \brief Values that can be passed to Cdd_Pwm_SetPeriodLoadMode() as the loadMode parameter. */
typedef enum
{
    /* PWM Period register access is through shadow register */
    CDD_PWM_PERIOD_SHADOW_LOAD = 0U,
    /* PWM Period register access is directly */
    CDD_PWM_PERIOD_DIRECT_LOAD = 1U
} Cdd_Pwm_PeriodLoadModeType;

/** \brief Values that can be passed to Cdd_Pwm_SelectPeriodLoadEvent() as the shadowLoadMode parameter. */
typedef enum
{
    /* Shadow to active load occurs when time base counter reaches 0 */
    CDD_PWM_SHADOW_LOAD_MODE_COUNTER_ZERO = 0U,
    /* Shadow to active load occurs when time base counter reaches 0 and a SYNC occurs */
    CDD_PWM_SHADOW_LOAD_MODE_COUNTER_SYNC = 1U,
    /* Shadow to active load occurs only when a SYNC occurs */
    CDD_PWM_SHADOW_LOAD_MODE_SYNC = 2U
} Cdd_Pwm_PeriodShadowLoadModeType;

/** \brief Global load register types. */
typedef enum
{
    /* Global load TBPRD:TBPRDHR */
    CDD_PWM_GL_REGISTER_TBPRD_TBPRDHR = 0x1U,
    /* Global load CMPA:CMPAHR */
    CDD_PWM_GL_REGISTER_CMPA_CMPAHR = 0x2U,
    /* Global load CMPB:CMPBHR */
    CDD_PWM_GL_REGISTER_CMPB_CMPBHR = 0x4U,
    /* Global load CMPC */
    CDD_PWM_GL_REGISTER_CMPC = 0x8U,
    /* Global load CMPD */
    CDD_PWM_GL_REGISTER_CMPD = 0x10U,
    /* Global load DBRED:DBREDHR */
    CDD_PWM_GL_REGISTER_DBRED_DBREDHR = 0x20U,
    /* Global load DBFED:DBFEDHR */
    CDD_PWM_GL_REGISTER_DBFED_DBFEDHR = 0x40U,
    /* Global load DBCTL */
    CDD_PWM_GL_REGISTER_DBCTL = 0x80U,
    /* Global load AQCTLA/A2 */
    CDD_PWM_GL_REGISTER_AQCTLA_AQCTLA2 = 0x100U,
    /* Global load AQCTLB/B2 */
    CDD_PWM_GL_REGISTER_AQCTLB_AQCTLB2 = 0x200U,
    /* Global load AQCSFRC */
    CDD_PWM_GL_REGISTER_AQCSFRC = 0x400U
} Cdd_Pwm_GlobalLoadType;

/** \brief Digital compare trip input types. */
typedef enum
{
    /* Combinational Trip 1 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN1 = 0x1U,
    /* Combinational Trip 2 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN2 = 0x2U,
    /* Combinational Trip 3 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN3 = 0x4U,
    /* Combinational Trip 4 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN4 = 0x8U,
    /* Combinational Trip 5 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN5 = 0x10U,
    /* Combinational Trip 6 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN6 = 0x20U,
    /* Combinational Trip 7 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN7 = 0x40U,
    /* Combinational Trip 8 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN8 = 0x80U,
    /* Combinational Trip 9 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN9 = 0x100U,
    /* Combinational Trip 10 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN10 = 0x200U,
    /* Combinational Trip 11 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN11 = 0x400U,
    /* Combinational Trip 12 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN12 = 0x800U,
    /* Combinational Trip 14 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN14 = 0x2000U,
    /* Combinational Trip 15 input */
    CDD_PWM_DC_COMBINATIONAL_TRIPIN15 = 0x4000U
} Cdd_Pwm_DcTripInputType;

/* Action Qualifier Module
 *
 */

/** \brief Values that can be passed to Cdd_Pwm_SetActionQualifierT1TriggerSource() and
 * Cdd_Pwm_SetActionQualifierT2TriggerSource() as the trigger parameter. */
typedef enum
{
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCA_1          = 0U, /* Digital compare event A 1 */
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCA_2          = 1U, /* Digital compare event A 2 */
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCB_1          = 2U, /* Digital compare event B 1 */
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DCB_2          = 3U, /* Digital compare event B 2 */
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_1           = 4U, /* Trip zone 1 */
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_2           = 5U, /* Trip zone 2 */
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_TZ_3           = 6U, /* Trip zone 3 */
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_CDD_PWM_SYNCIN = 7U, /* CDD_PWM sync */
    CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT     = 8U  /* Digital compare filter event */
} Cdd_Pwm_ActionQualifierTriggerSourceType;

/** \brief Values that can be passed to Cdd_Pwm_SetActionQualifierContSWForceAction() as the outPut parameter. */
typedef enum
{
    CDD_PWM_AQ_SW_DISABLED    = 0U, /* Software forcing disabled */
    CDD_PWM_AQ_SW_OUTPUT_LOW  = 1U, /* Set output pins to low */
    CDD_PWM_AQ_SW_OUTPUT_HIGH = 2U  /* Set output pins to High */
} Cdd_Pwm_ActionQualifierSwOutputType;

/** \brief Values that can be passed to Cdd_Pwm_SetActionQualifierActionComplete() as the action parameter. */
typedef enum
{
    /* Time base counter equals zero and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_ZERO = 0x0U,
    /* Time base counter equals zero and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_ZERO = 0x1U,
    /* Time base counter equals zero and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_ZERO = 0x2U,
    /* Time base counter equals zero and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_ZERO = 0x3U,
    /* Time base counter equals period and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_PERIOD = 0x0U,
    /* Time base counter equals period and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_PERIOD = 0x4U,
    /* Time base counter equals period and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_PERIOD = 0x8U,
    /* Time base counter equals period and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_PERIOD = 0xCU,
    /* Time base counter up equals COMPA and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_UP_CMPA = 0x00U,
    /* Time base counter up equals COMPA and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_UP_CMPA = 0x10U,
    /* Time base counter up equals COMPA and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_UP_CMPA = 0x20U,
    /* Time base counter up equals COMPA and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_UP_CMPA = 0x30U,
    /* Time base counter down equals COMPA and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPA = 0x00U,
    /* Time base counter down equals COMPA and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_DOWN_CMPA = 0x40U,
    /* Time base counter down equals COMPA and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_DOWN_CMPA = 0x80U,
    /* Time base counter down equals COMPA and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_CMPA = 0xC0U,
    /* Time base counter up equals COMPB and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_UP_CMPB = 0x000U,
    /* Time base counter up equals COMPB and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_UP_CMPB = 0x100U,
    /* Time base counter up equals COMPB and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_UP_CMPB = 0x200U,
    /* Time base counter up equals COMPB and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_UP_CMPB = 0x300U,
    /* Time base counter down equals COMPB and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_DOWN_CMPB = 0x000U,
    /* Time base counter down equals COMPB and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_DOWN_CMPB = 0x400U,
    /* Time base counter down equals COMPB and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_DOWN_CMPB = 0x800U,
    /* Time base counter down equals COMPB and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_CMPB = 0xC00U
} Cdd_Pwm_ActionQualifierEventActionType;

/** \brief Values that can be passed to Cdd_Pwm_SetAdditionalActionQualifierActionComplete() as the action parameter */
typedef enum
{
    /* T1 event on count up and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_UP_T1 = 0x0U,
    /* T1 event on count up and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_UP_T1 = 0x1U,
    /* T1 event on count up and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_UP_T1 = 0x2U,
    /* T1 event on count up and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_UP_T1 = 0x3U,
    /* T1 event on count down and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_DOWN_T1 = 0x0U,
    /* T1 event on count down and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_DOWN_T1 = 0x4U,
    /* T1 event on count down and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_DOWN_T1 = 0x8U,
    /* T1 event on count down and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_T1 = 0xCU,
    /* T2 event on count up and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_UP_T2 = 0x00U,
    /* T2 event on count up and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_UP_T2 = 0x10U,
    /* T2 event on count up and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_UP_T2 = 0x20U,
    /* T2 event on count up and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_UP_T2 = 0x30U,
    /* T2 event on count down and no change in the output pins */
    CDD_PWM_AQ_OUTPUT_NO_CHANGE_DOWN_T2 = 0x00U,
    /* T2 event on count down and set output pins to low */
    CDD_PWM_AQ_OUTPUT_LOW_DOWN_T2 = 0x40U,
    /* T2 event on count down and set output pins to high */
    CDD_PWM_AQ_OUTPUT_HIGH_DOWN_T2 = 0x80U,
    /* T2 event on count down and toggle the output pins */
    CDD_PWM_AQ_OUTPUT_TOGGLE_DOWN_T2 = 0xC0U
} Cdd_Pwm_AdditionalActionQualifierEventActionType;

/** \brief Action qualifier continuous force type */
typedef enum
{
    /** \brief Shadow mode load when counter equals zero */
    CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO = 0U,
    /** \brief Shadow mode load when counter equals period */
    CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_PERIOD = 1U,
    /** \brief Shadow mode load when counter equals zero or period */
    CDD_PWM_AQ_SW_SH_LOAD_ON_CNTR_ZERO_PERIOD = 2U,
    /** \brief No shadow load mode Immediate mode only */
    CDD_PWM_AQ_SW_IMMEDIATE_LOAD = 3U
} Cdd_Pwm_ActionQualifierContForceType;

/** \brief Values that can be passed to Cdd_Pwm_SetDeadBandDelayPolarity(),
 * Cdd_Pwm_SetDeadBandDelayMode() as the delayMode parameter. */
typedef enum
{
    CDD_PWM_DB_FED = 0U, /* DB FED (Falling Edge Delay) mode  */
    CDD_PWM_DB_RED = 1U  /* DB RED (Rising Edge Delay) mode */
} Cdd_Pwm_DeadBandDelayModeType;

/** \brief Dead band delay input types. */
typedef enum
{
    CDD_PWM_DB_INPUT_EPWMA  = 0U, /* Input signal is EPWMA */
    CDD_PWM_DB_INPUT_EPWMB  = 1U, /* Input signal is EPWMB */
    CDD_PWM_DB_INPUT_DB_RED = 2U  /* Input signal is output of rising edge delay */
} Cdd_Pwm_DeadBandDelayInputType;

/** \brief Values that can be passed to Cdd_Pwm_SetDeadBandDelayPolarity as the polarity parameter. */
typedef enum
{
    CDD_PWM_DB_POLARITY_ACTIVE_HIGH = 0U, /* DB polarity is not inverted */
    CDD_PWM_DB_POLARITY_ACTIVE_LOW  = 1U  /* DB polarity is inverted */
} Cdd_Pwm_DeadBandPolarityType;

/** \brief Values that can be passed to Cdd_Pwm_SetDeadBandControlShadowLoadMode() as the loadMode parameter. */
typedef enum
{
    /* Load when counter equals zero */
    CDD_PWM_DB_LOAD_ON_CNTR_ZERO = 0U,
    /* Load when counter equals period */
    CDD_PWM_DB_LOAD_ON_CNTR_PERIOD = 1U,
    /* Load when counter equals zero or period */
    CDD_PWM_DB_LOAD_ON_CNTR_ZERO_PERIOD = 2U,
    /* Freeze shadow to active load */
    CDD_PWM_DB_LOAD_FREEZE = 3U
} Cdd_Pwm_DeadBandControlLoadModeType;

/** \brief Values that can be passed to Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode() and
 * Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadModeas the loadMode parameter.
 */
typedef enum
{
    /* Load when counter equals zero */
    CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO = 0U,
    /* Load when counter equals period */
    CDD_PWM_DELAY_LOAD_ON_CNTR_PERIOD = 1U,
    /* Load when counter equals zero or period */
    CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO_PERIOD = 2U,
    /* Freeze shadow to active load */
    CDD_PWM_DELAY_LOAD_FREEZE = 3U
} Cdd_Pwm_DeadBandDelayLoadModeType;

/** \brief Values that can be passed to Cdd_Pwm_SetDeadBandCounterClock() as the clockMode parameter. */
typedef enum
{
    /* Dead band counter runs at TBCLK rate */
    CDD_PWM_DB_COUNTER_CLOCK_FULL_CYCLE = 0U,
    /* Dead band counter runs at 2*TBCLK rate */
    CDD_PWM_DB_COUNTER_CLOCK_HALF_CYCLE = 1U
} Cdd_Pwm_DeadBandClockModeType;

/** \brief Trip Zone */

/** \brief Values that can be passed to Cdd_Pwm_SetTripZoneDigitalCompareEventCondition() as the dcType parameter. */
typedef enum
{
    CDD_PWM_TZ_DC_OUTPUT_A1 = 0U, /* Digital Compare output 1 A */
    CDD_PWM_TZ_DC_OUTPUT_A2 = 1U, /* Digital Compare output 2 A */
    CDD_PWM_TZ_DC_OUTPUT_B1 = 2U, /* Digital Compare output 1 B */
    CDD_PWM_TZ_DC_OUTPUT_B2 = 3U  /* Digital Compare output 2 B */
} Cdd_Pwm_TripZoneDigitalCompareOutputType;

/** \brief Cycle By Cycle Trip Zone Flag types */
typedef enum
{
    /* Trip Zone interrupt */
    CDD_PWM_TZ_INTERRUPT = 0x1U,
    /* Trip Zones Cycle By Cycle flag */
    CDD_PWM_TZ_FLAG_CBC = 0x2U,
    /* Trip Zones One Shot flag */
    CDD_PWM_TZ_FLAG_OST = 0x4U,
    /* Digital Compare A Event 1 flag */
    CDD_PWM_TZ_FLAG_DCAEVT1 = 0x8U,
    /* Digital Compare A Event 2 flag */
    CDD_PWM_TZ_FLAG_DCAEVT2 = 0x10U,
    /* Digital Compare B Event 1 flag */
    CDD_PWM_TZ_FLAG_DCBEVT1 = 0x20U,
    /* Digital Compare B Event 2 flag */
    CDD_PWM_TZ_FLAG_DCBEVT2 = 0x40U,
    /* Trip Zones Capture Event flag */
    CDD_PWM_TZ_FLAG_CAPEVT = 0x80U
} Cdd_Pwm_TripZoneFlagType;

/** \brief Cycle By Cycle Trip Zone Flag types */
typedef enum
{
    /* CBC flag 1 */
    CDD_PWM_TZ_CBC_FLAG_1 = 0x1U,
    /* CBC flag 2 */
    CDD_PWM_TZ_CBC_FLAG_2 = 0x2U,
    /* CBC flag 3 */
    CDD_PWM_TZ_CBC_FLAG_3 = 0x4U,
    /* CBC flag 4 */
    CDD_PWM_TZ_CBC_FLAG_4 = 0x8U,
    /* CBC flag 5 */
    CDD_PWM_TZ_CBC_FLAG_5 = 0x10U,
    /* CBC flag 6 */
    CDD_PWM_TZ_CBC_FLAG_6 = 0x20U,
    /* CBC flag Digital compare event A2 */
    CDD_PWM_TZ_CBC_FLAG_DCAEVT2 = 0x40U,
    /* CBC flag Digital compare event B2 */
    CDD_PWM_TZ_CBC_FLAG_DCBEVT2 = 0x80U,
    /* CBC flag capture event */
    CDD_PWM_TZ_CBC_FLAG_CAPEVT = 0x100U
} Cdd_Pwm_CbcTzFlagType;

/** \brief One-shot Trip Zone Flag types */
typedef enum
{
    /* OST flag OST1 */
    CDD_PWM_TZ_OST_FLAG_OST1 = 0x1U,
    /* OST flag OST2 */
    CDD_PWM_TZ_OST_FLAG_OST2 = 0x2U,
    /* OST flag OST3 */
    CDD_PWM_TZ_OST_FLAG_OST3 = 0x4U,
    /* OST flag OST4 */
    CDD_PWM_TZ_OST_FLAG_OST4 = 0x8U,
    /* OST flag OST5 */
    CDD_PWM_TZ_OST_FLAG_OST5 = 0x10U,
    /* OST flag OST6 */
    CDD_PWM_TZ_OST_FLAG_OST6 = 0x20U,
    /* OST flag Digital compare event A1 */
    CDD_PWM_TZ_OST_FLAG_DCAEVT1 = 0x40U,
    /* OST flag Digital compare event B1 */
    CDD_PWM_TZ_OST_FLAG_DCBEVT1 = 0x80U,
    /* OST flag capture event */
    CDD_PWM_TZ_OST_FLAG_CAPEVT = 0x100U
} Cdd_Pwm_OneshotTzFlagType;

/** \brief Trip Zone Force Event types */
typedef enum
{
    /* Force Cycle By Cycle trip event */
    CDD_PWM_TZ_FORCE_EVENT_CBC = 0x2U,
    /* Force a One-Shot Trip Event */
    CDD_PWM_TZ_FORCE_EVENT_OST = 0x4U,
    /* Force Digital Compare Output A Event 1 */
    CDD_PWM_TZ_FORCE_EVENT_DCAEVT1 = 0x8U,
    /* Force Digital Compare Output A Event 2 */
    CDD_PWM_TZ_FORCE_EVENT_DCAEVT2 = 0x10U,
    /* Force Digital Compare Output B Event 1 */
    CDD_PWM_TZ_FORCE_EVENT_DCBEVT1 = 0x20U,
    /* Force Digital Compare Output B Event 2 */
    CDD_PWM_TZ_FORCE_EVENT_DCBEVT2 = 0x40U,
    /* Force a Capture Event */
    CDD_PWM_TZ_FORCE_EVENT_CAPEVT = 0x80U
} Cdd_Pwm_TripZoneForceEventType;

/** \brief Values that can be passed to Cdd_Pwm_SetTripZoneAction() as the TzEvent parameter. */
typedef enum
{
    CDD_PWM_TZ_ACTION_EVENT_TZA     = 0U, /* TZ1 - TZ6U, DCAEVT2U, DCAEVT1 */
    CDD_PWM_TZ_ACTION_EVENT_TZB     = 1U, /* TZ1 - TZ6U, DCBEVT2U, DCBEVT1 */
    CDD_PWM_TZ_ACTION_EVENT_DCAEVT1 = 2U, /* DCAEVT1 (Digital Compare A event 1) */
    CDD_PWM_TZ_ACTION_EVENT_DCAEVT2 = 3U, /* DCAEVT2 (Digital Compare A event 2) */
    CDD_PWM_TZ_ACTION_EVENT_DCBEVT1 = 4U, /* DCBEVT1 (Digital Compare B event 1) */
    CDD_PWM_TZ_ACTION_EVENT_DCBEVT2 = 5U  /* DCBEVT2 (Digital Compare B event 2) */
} Cdd_Pwm_TripZoneActionEventType;

/** \brief Values that can be passed to Cdd_Pwm_EnableTripZoneSignals() and
 * Cdd_Pwm_DisableTripZoneSignals() as the TzSignal parameter. */
typedef enum
{
    /* TZ1 Cycle By Cycle */
    CDD_PWM_TZ_SIGNAL_CBC1 = 0x1U,
    /* TZ2 Cycle By Cycle */
    CDD_PWM_TZ_SIGNAL_CBC2 = 0x2U,
    /* TZ3 Cycle By Cycle */
    CDD_PWM_TZ_SIGNAL_CBC3 = 0x4U,
    /* TZ4 Cycle By Cycle */
    CDD_PWM_TZ_SIGNAL_CBC4 = 0x8U,
    /* TZ5 Cycle By Cycle */
    CDD_PWM_TZ_SIGNAL_CBC5 = 0x10U,
    /* TZ6 Cycle By Cycle */
    CDD_PWM_TZ_SIGNAL_CBC6 = 0x20U,
    /* DCAEVT2 Cycle By Cycle */
    CDD_PWM_TZ_SIGNAL_DCAEVT2 = 0x40U,
    /* DCBEVT2 Cycle By Cycle */
    CDD_PWM_TZ_SIGNAL_DCBEVT2 = 0x80U,
    /* One-shot TZ1 */
    CDD_PWM_TZ_SIGNAL_OSHT1 = 0x100U,
    /* One-shot TZ2 */
    CDD_PWM_TZ_SIGNAL_OSHT2 = 0x200U,
    /* One-shot TZ3 */
    CDD_PWM_TZ_SIGNAL_OSHT3 = 0x400U,
    /* One-shot TZ4 */
    CDD_PWM_TZ_SIGNAL_OSHT4 = 0x800U,
    /* One-shot TZ5 */
    CDD_PWM_TZ_SIGNAL_OSHT5 = 0x1000U,
    /* One-shot TZ6 */
    CDD_PWM_TZ_SIGNAL_OSHT6 = 0x2000U,
    /* One-shot DCAEVT1 */
    CDD_PWM_TZ_SIGNAL_DCAEVT1 = 0x4000U,
    /* One-shot DCBEVT1 */
    CDD_PWM_TZ_SIGNAL_DCBEVT1 = 0x8000U
} Cdd_Pwm_TzSignalType;

/** \brief Enumeration to configure tripzone CAPEVT signal */
typedef enum
{
    /* Cycle by cycle capture event */
    CDD_PWM_TZ_SIGNAL_CAPEVT_CBC = 0x1U,
    /* One-shot Capture event */
    CDD_PWM_TZ_SIGNAL_CAPEVT_OST = 0x100U
} Cdd_Pwm_TzCapEvtType;

/** \brief Values that can be passed to Cdd_Pwm_ConfigureTripZoneInterrupt() and
 *  Cdd_Pwm_DisableTripZoneInterrupt() as the TzInterrupt parameter. */
typedef enum
{
    CDD_PWM_TZ_INTERRUPT_CBC     = 0x2U,  /* Trip Zones One Shot interrupt */
    CDD_PWM_TZ_INTERRUPT_OST     = 0x4U,  /* Digital Compare A Event 1 interrupt */
    CDD_PWM_TZ_INTERRUPT_DCAEVT1 = 0x8U,  /* Digital Compare A Event 2 interrupt */
    CDD_PWM_TZ_INTERRUPT_DCAEVT2 = 0x10U, /* Digital Compare B Event 1 interrupt */
    CDD_PWM_TZ_INTERRUPT_DCBEVT1 = 0x20U, /* Digital Compare B Event 2 interrupt */
    CDD_PWM_TZ_INTERRUPT_DCBEVT2 = 0x40U, /* Trip Zones Capture Event interrupt */
    CDD_PWM_TZ_INTERRUPT_CAPEVT  = 0x80U
} Cdd_Pwm_TzInterruptSourceType;

/** \brief Values that can be passed to Cdd_Pwm_SetTripZoneDigitalCompareEventCondition() as the dcEvent parameter. */
typedef enum
{
    CDD_PWM_TZ_EVENT_DC_DISABLED        = 0U, /* Event is disabled */
    CDD_PWM_TZ_EVENT_DCXH_LOW           = 1U, /* Event when DCxH low */
    CDD_PWM_TZ_EVENT_DCXH_HIGH          = 2U, /* Event when DCxH high */
    CDD_PWM_TZ_EVENT_DCXL_LOW           = 3U, /* Event when DCxL low */
    CDD_PWM_TZ_EVENT_DCXL_HIGH          = 4U, /* Event when DCxL high */
    CDD_PWM_TZ_EVENT_DCXL_HIGH_DCXH_LOW = 5U  /* Event when DCxL high DCxH low */
} Cdd_Pwm_TripZoneDigitalCompareOutputEventType;

/** \brief Values that can be passed to Cdd_Pwm_SetTripZoneAction() as the TzAction parameter. */
typedef enum
{
    CDD_PWM_TZ_ACTION_HIGH_Z  = 0U, /* High impedance output */
    CDD_PWM_TZ_ACTION_HIGH    = 1U, /* High voltage state */
    CDD_PWM_TZ_ACTION_LOW     = 2U, /* Low voltage state */
    CDD_PWM_TZ_ACTION_DISABLE = 3U  /* Disable action */
} Cdd_Pwm_TripZoneActionType;

/** \brief Values that can be passed to Cdd_Pwm_SetTripZoneAdvAction() as the TzAdvEvent parameter. */
/** \brief Trip zone advanced event type */
typedef enum
{
    /* TZ1 - TZ6U, DCAEVT2U, DCAEVT1 while counting up */
    CDD_PWM_TZ_ADV_ACTION_EVENT_TZA_U = 0U,
    /* TZ1 - TZ6U, DCAEVT2U, DCAEVT1 while counting down */
    CDD_PWM_TZ_ADV_ACTION_EVENT_TZA_D = 1U,
    /* TZ1 - TZ6U, DCBEVT2U, DCBEVT1 while counting up */
    CDD_PWM_TZ_ADV_ACTION_EVENT_TZB_U = 2U,
    /* TZ1 - TZ6U, DCBEVT2U, DCBEVT1 while counting down */
    CDD_PWM_TZ_ADV_ACTION_EVENT_TZB_D = 3U
} Cdd_Pwm_TripZoneAdvancedEventType;

/** \brief Values that can be passed to Cdd_Pwm_SetTripZoneAdvDigitalCompareActionA(),
 * Cdd_Pwm_SetTripZoneAdvDigitalCompareActionB(), Cdd_Pwm_SetTripZoneAdvAction() as the TzAdvDCAction parameter. */
typedef enum
{
    CDD_PWM_TZ_ADV_ACTION_HIGH_Z  = 0U, /* High impedance output */
    CDD_PWM_TZ_ADV_ACTION_HIGH    = 1U, /* High voltage state */
    CDD_PWM_TZ_ADV_ACTION_LOW     = 2U, /* Low voltage state */
    CDD_PWM_TZ_ADV_ACTION_TOGGLE  = 3U, /* Toggle the output */
    CDD_PWM_TZ_ADV_ACTION_DISABLE = 7U  /* Disable action */
} Cdd_Pwm_TripZoneAdvancedActionType;

/** \brief Values that can be passed to Cdd_Pwm_SetTripZoneAdvDigitalCompareActionA() and
 * Cdd_Pwm_SetTripZoneAdvDigitalCompareActionB() as the TzAdvDCEvent parameter. */
typedef enum
{
    /* Digital Compare event A/B 1 while counting up */
    CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT1_U = 0U,
    /* Digital Compare event A/B 1 while counting down */
    CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT1_D = 1U,
    /* Digital Compare event A/B 2 while counting up */
    CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT2_U = 2U,
    /* Digital Compare event A/B 2 while counting down */
    CDD_PWM_TZ_ADV_ACTION_EVENT_DCXEVT2_D = 3U
} Cdd_Pwm_TripZoneAdvDigitalCompareEventType;

/** \brief XCMP */

/** \brief Values that can be passed to Cdd_Pwm_SetXCmpRegValue() as the xcmpReg parameter. */
typedef enum
{
    /* XCMP1_ACTIVE */
    CDD_PWM_XCMP1_ACTIVE = 0x0U,
    /* XCMP2_ACTIVE */
    CDD_PWM_XCMP2_ACTIVE = 0x2U,
    /* XCMP3_ACTIVE */
    CDD_PWM_XCMP3_ACTIVE = 0x4U,
    /* XCMP4_ACTIVE */
    CDD_PWM_XCMP4_ACTIVE = 0x6U,
    /* XCMP5_ACTIVE */
    CDD_PWM_XCMP5_ACTIVE = 0x8U,
    /* XCMP6_ACTIVE */
    CDD_PWM_XCMP6_ACTIVE = 0xAU,
    /* XCMP7_ACTIVE */
    CDD_PWM_XCMP7_ACTIVE = 0xCU,
    /* XCMP8_ACTIVE */
    CDD_PWM_XCMP8_ACTIVE = 0xEU,
    /* XTBPRD_ACTIVE */
    CDD_PWM_XTBPRD_ACTIVE = 0x10U,

    /* XCMP1_SHADOW1 */
    CDD_PWM_XCMP1_SHADOW1 = 0x40U,
    /* XCMP2_SHADOW1 */
    CDD_PWM_XCMP2_SHADOW1 = 0x42U,
    /* XCMP3_SHADOW1 */
    CDD_PWM_XCMP3_SHADOW1 = 0x44U,
    /* XCMP4_SHADOW1 */
    CDD_PWM_XCMP4_SHADOW1 = 0x46U,
    /* XCMP5_SHADOW1 */
    CDD_PWM_XCMP5_SHADOW1 = 0x48U,
    /* XCMP6_SHADOW1 */
    CDD_PWM_XCMP6_SHADOW1 = 0x4AU,
    /* XCMP7_SHADOW1 */
    CDD_PWM_XCMP7_SHADOW1 = 0x4CU,
    /* XCMP8_SHADOW1 */
    CDD_PWM_XCMP8_SHADOW1 = 0x4EU,
    /* XTBPRD_SHADOW1 */
    CDD_PWM_XTBPRD_SHADOW1 = 0x50U,

    /* XCMP1_SHADOW2 */
    CDD_PWM_XCMP1_SHADOW2 = 0x80U,
    /* XCMP2_SHADOW2 */
    CDD_PWM_XCMP2_SHADOW2 = 0x82U,
    /* XCMP3_SHADOW2 */
    CDD_PWM_XCMP3_SHADOW2 = 0x84U,
    /* XCMP4_SHADOW2 */
    CDD_PWM_XCMP4_SHADOW2 = 0x86U,
    /* XCMP5_SHADOW2 */
    CDD_PWM_XCMP5_SHADOW2 = 0x88U,
    /* XCMP6_SHADOW2 */
    CDD_PWM_XCMP6_SHADOW2 = 0x8AU,
    /* XCMP7_SHADOW2 */
    CDD_PWM_XCMP7_SHADOW2 = 0x8CU,
    /* XCMP8_SHADOW2 */
    CDD_PWM_XCMP8_SHADOW2 = 0x8EU,
    /* XTBPRD_SHADOW2 */
    CDD_PWM_XTBPRD_SHADOW2 = 0x90U,

    /* XCMP1_SHADOW3 */
    CDD_PWM_XCMP1_SHADOW3 = 0xC0U,
    /* XCMP2_SHADOW3 */
    CDD_PWM_XCMP2_SHADOW3 = 0xC2U,
    /* XCMP3_SHADOW3 */
    CDD_PWM_XCMP3_SHADOW3 = 0xC4U,
    /* XCMP4_SHADOW3 */
    CDD_PWM_XCMP4_SHADOW3 = 0xC6U,
    /* XCMP5_SHADOW3 */
    CDD_PWM_XCMP5_SHADOW3 = 0xC8U,
    /* XCMP6_SHADOW3 */
    CDD_PWM_XCMP6_SHADOW3 = 0xCAU,
    /* XCMP7_SHADOW3 */
    CDD_PWM_XCMP7_SHADOW3 = 0xCCU,
    /* XCMP8_SHADOW3 */
    CDD_PWM_XCMP8_SHADOW3 = 0xCEU,
    /* XTBPRD_SHADOW3 */
    CDD_PWM_XTBPRD_SHADOW3 = 0xD0U
} Cdd_Pwm_XCmpRegType;

/** \brief XCMP shadow set types */
typedef enum
{
    /* XCMP set = Active */
    CDD_PWM_XCMP_ACTIVE = 0x0U,
    /* XCMP set = Shadow 1 */
    CDD_PWM_XCMP_SHADOW1 = 0x1U,
    /* XCMP set = Shadow 2 */
    CDD_PWM_XCMP_SHADOW2 = 0x2U,
    /* XCMP set = Shadow 3 */
    CDD_PWM_XCMP_SHADOW3 = 0x3U
} Cdd_Pwm_XCmpShadowSetType;

/** \brief Values that can be passed to Cdd_Pwm_SetCmpShadowRegValue() as the cmpReg parameter. */
typedef enum
{
    /* CMPC_SHADOW1 */
    CDD_PWM_CMPC_SHADOW1 = 0x0U,
    /* CMPD_SHADOW1 */
    CDD_PWM_CMPD_SHADOW1 = 0x2U,
    /* CMPC_SHADOW2 */
    CDD_PWM_CMPC_SHADOW2 = 0x40U,
    /* CMPD_SHADOW2 */
    CDD_PWM_CMPD_SHADOW2 = 0x42U,
    /* CMPC_SHADOW3 */
    CDD_PWM_CMPC_SHADOW3 = 0x80U,
    /* CMPD_SHADOW3 */
    CDD_PWM_CMPD_SHADOW3 = 0x82U

} Cdd_Pwm_XCompareRegType;

/** \brief Values that can be passed to Cdd_Pwm_SetXMINMAXRegValue() as the xminmaxReg parameter. */
typedef enum
{
    /* XMAX_ACTIVE */
    CDD_PWM_XMAX_ACTIVE = 0x0U,
    /* XMIN_ACTIVE */
    CDD_PWM_XMIN_ACTIVE = 0x1U,
    /* XMAX_SHADOW1 */
    CDD_PWM_XMAX_SHADOW1 = 0x40U,
    /* XMIN_SHADOW1 */
    CDD_PWM_XMIN_SHADOW1 = 0x41U,
    /* XMAX_SHADOW2 */
    CDD_PWM_XMAX_SHADOW2 = 0x80U,
    /* XMIN_SHADOW2 */
    CDD_PWM_XMIN_SHADOW2 = 0x81U,
    /* XMAX_SHADOW3 */
    CDD_PWM_XMAX_SHADOW3 = 0xC0U,
    /* XMIN_SHADOW3 */
    CDD_PWM_XMIN_SHADOW3 = 0xC1U
} Cdd_Pwm_XMinMaxRegType;

/** \brief Values that can be passed to Cdd_Pwm_SetXCmpActionQualifierAction() as the event parameter. */
typedef enum
{
    /* Time base counter equals XCMP1 */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP1 = 0U,
    /* Time base counter equals XCMP2 */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP2 = 1U,
    /* Time base counter equals XCMP3 */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP3 = 2U,
    /* Time base counter equals XCMP4  */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP4 = 3U,
    /* Time base counter equals XCMP5  */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP5 = 4U,
    /* Time base counter equals XCMP6  */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP6 = 5U,
    /* Time base counter equals XCMP7  */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP7 = 6U,
    /* Time base counter equals XCMP8  */
    CDD_PWM_AQ_OUTPUT_ON_TIMEBASE_XCMP8 = 7U
} Cdd_Pwm_XCmpAqOutputEventType;

/** \brief Values that can be passed to Cdd_Pwm_AllocAXCMP() as the alloctype parameter. */
typedef enum
{
    /* Allocate 0 XCMP registers to CMPA */
    CDD_PWM_XCMP_NONE_CMPA = 0U,
    /* Allocate XCMP1 register to CMPA */
    CDD_PWM_XCMP_1_CMPA = 1U,
    /* Allocate XCMP1 - XCMP2 registers to CMPA */
    CDD_PWM_XCMP_2_CMPA = 2U,
    /* Allocate XCMP1 - XCMP3 registers to CMPA */
    CDD_PWM_XCMP_3_CMPA = 3U,
    /* Allocate XCMP1 - XCMP4 registers to CMPA */
    CDD_PWM_XCMP_4_CMPA = 4U,
    /* Allocate XCMP1 - XCMP5 registers to CMPA */
    CDD_PWM_XCMP_5_CMPA = 5U,
    /* Allocate XCMP1 - XCMP6 registers to CMPA */
    CDD_PWM_XCMP_6_CMPA = 6U,
    /* Allocate XCMP1 - XCMP7 registers to CMPA */
    CDD_PWM_XCMP_7_CMPA = 7U,
    /* Allocate XCMP1 - XCMP8 registers to CMPA */
    CDD_PWM_XCMP_8_CMPA = 8U
} Cdd_Pwm_XCmp_AllocCmpAType;

/** \brief Values that can be passed to Cdd_Pwm_AllocBXCMP() as the alloctype parameter. */
typedef enum
{
    /* Allocate XCMP5 register to CMPB */
    CDD_PWM_XCMP_5_CMPB = 5U,
    /* Allocate XCMP5 - XCMP6 registers to CMPB */
    CDD_PWM_XCMP_6_CMPB = 6U,
    /* Allocate XCMP5 - XCMP7 registers to CMPB */
    CDD_PWM_XCMP_7_CMPB = 7U,
    /* Allocate XCMP5 - XCMP8 registers to CMPB */
    CDD_PWM_XCMP_8_CMPB = 8U
} Cdd_Pwm_XCmp_AllocCmpBType;

/** \brief Values that can be passed to Cdd_Pwm_SetXCmpLoadMode() as the mode parameter. */
typedef enum
{
    /* Load mode is LOADONCE */
    CDD_PWM_XCMP_LOADONCE = 0U,
    /* Load mode is LOADMULTIPLE */
    CDD_PWM_XCMP_LOADMULTIPLE = 1U
} Cdd_Pwm_XCmpLoadModeType;

/** \brief Values that can be passed to Cdd_Pwm_SetXCmpShadowLevel() as the level parameter. */
typedef enum
{
    /*  Only Active register is available */
    CDD_PWM_XCMP_SHADOWLEVEL_0 = 0U,
    /* SHDW1 and Active registers are available */
    CDD_PWM_XCMP_SHADOWLEVEL_1 = 1U,
    /* SHDW2U, SHDW1 and Active registers are available */
    CDD_PWM_XCMP_SHADOWLEVEL_2 = 2U,
    /* SHDW3U, SHDW2U, SHDW1 and Active registers are available */
    CDD_PWM_XCMP_SHADOWLEVEL_3 = 3U
} Cdd_Pwm_XCmpShadowLevelType;

/** \brief Values that can be passed to Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce() as the ptr parameter. */
typedef enum
{
    /* No Shadow buffer is in use */
    CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_NULL = 0U,
    /* Shadow buffer 1 is in use */
    CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_ONE = 1U,
    /* Shadow buffer 2 is in use */
    CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_TWO = 2U,
    /* Shadow buffer 3 is in use */
    CDD_PWM_XCMP_XLOADCTL_SHDWBUFPTR_THREE = 3U
} Cdd_Pwm_XCmpShadowBufPtrType;

/** \brief Diode Emulation Enumerations */

/** \brief Diode Emulation trip sources */
typedef enum
{
    /* Diode emulation Trip H */
    CDD_PWM_DE_SRC_TRIPH = 0x0U,
    /* Diode emulation Trip L */
    CDD_PWM_DE_SRC_TRIPL = 0x1U
} Cdd_Pwm_DiodeEmulationTripSrcType;

/** \brief Values that can be passed to Cdd_Pwm_SetDiodeEmulationMode() as the mode parameter. */
typedef enum
{
    /* Diode Emulation mode is Cycle by Cycle */
    CDD_PWM_DIODE_EMULATION_CBC = 0U,
    /* Diode Emulation mode is One Shot */
    CDD_PWM_DIODE_EMULATION_OST = 1U
} Cdd_Pwm_DiodeEmulationModeType;

/** \brief Diode emulation direction types */
typedef enum
{
    /* Diode emulation count up step size */
    CDD_PWM_DE_COUNT_UP = 0x0U,
    /* Diode emulation count down step size */
    CDD_PWM_DE_COUNT_DOWN = 0x1U
} Cdd_Pwm_DiodeEmulationDirectionType;

/** \brief Values that can be passed to Cdd_Pwm_SelectDiodeEmulationPwmSignal() as the signal parameter. */
typedef enum
{
    /* Synchronized version of TRIPH or TRIPL signal */
    CDD_PWM_DE_SYNC_TRIPH_OR_TRIPL = 0U,
    /* Synchronized and inverted version of TRIPH or TRIPL signal */
    CDD_PWM_DE_SYNC_INV_TRIPH_OR_TRIPL = 1U,
    /* A constant low signal */
    CDD_PWM_DE_LOW = 2U,
    /* A constant high signal */
    CDD_PWM_DE_HIGH = 3U
} Cdd_Pwm_DiodeEmulationSignalType;

/** \brief Values that can be passed to Cdd_Pwm_SelectCycleByCycleTripZoneClearEvent() as the clearMode parameter. */
typedef enum
{
    /* Clear CBC pulse when counter equals zero */
    CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_ZERO = 0U,
    /* Clear CBC pulse when counter equals period */
    CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_PERIOD = 1U,
    /* Clear CBC pulse when counter equals zero or period */
    CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_ZERO_PERIOD = 2U
} Cdd_Pwm_CbcTripZoneClearModeType;

/** \brief Values that can be passed to Cdd_Pwm_EnableTripOutSource() and
 * Cdd_Pwm_DisableTripOutSource() as the TzTripOut parameter. */
typedef enum
{
    CDD_PWM_TZ_TRIPOUT_OST     = 0U,  /* OST as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_CBC     = 1U,  /* CBC as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_TZ1     = 2U,  /* TZ1 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_TZ2     = 3U,  /* TZ2 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_TZ3     = 4U,  /* TZ3 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_TZ4     = 5U,  /* TZ4 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_TZ5     = 6U,  /* TZ5 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_TZ6     = 7U,  /* TZ6 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_DCAEVT1 = 8U,  /* DCAEVT1 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_DCAEVT2 = 9U,  /* DCAEVT2 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_DCBEVT1 = 10U, /* DCBEVT1 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_DCBEVT2 = 11U, /* DCBEVT2 as TRIPOUT source */
    CDD_PWM_TZ_TRIPOUT_CAPEVT  = 12U  /* Capture Event as TRIPOUT source */
} Cdd_Pwm_SelectTripOutSourceType;

/** \brief ADC Start of Conversion type for PWM module */
typedef enum
{
    CDD_PWM_SOC_A = 0U, /* SOC A */
    CDD_PWM_SOC_B = 1U  /* SOC B */
} Cdd_Pwm_AdcStartOfConversionType;

/** \brief ADC Start of Conversion source types */
typedef enum
{
    /* Event is based on DCxEVT1 */
    CDD_PWM_SOC_DCXEVT1 = 0U,
    /* Time-base counter equal to zero */
    CDD_PWM_SOC_TBCTR_ZERO = 1U,
    /* Time-base counter equal to period */
    CDD_PWM_SOC_TBCTR_PERIOD = 2U,
    /* Time-base counter based on mixed events (ETSOCAMIX) */
    CDD_PWM_SOC_TBCTR_ETSOCAMIX = 3U,
    /* Time-base counter equal to CMPA when the timer is incrementing */
    CDD_PWM_SOC_TBCTR_U_CMPA = 4U,
    /* Time-base counter equal to CMPC when the timer is incrementing */
    CDD_PWM_SOC_TBCTR_U_CMPC = 8U,
    /* Time-base counter equal to CMPA when the timer is decrementing  */
    CDD_PWM_SOC_TBCTR_D_CMPA = 5U,
    /* Time-base counter equal to CMPC when the timer is decrementing  */
    CDD_PWM_SOC_TBCTR_D_CMPC = 10U,
    /* Time-base counter equal to CMPB when the timer is incrementing */
    CDD_PWM_SOC_TBCTR_U_CMPB = 6U,
    /* Time-base counter equal to CMPD when the timer is incrementing */
    CDD_PWM_SOC_TBCTR_U_CMPD = 12U,
    /* Time-base counter equal to CMPB when the timer is decrementing  */
    CDD_PWM_SOC_TBCTR_D_CMPB = 7U,
    /* Time-base counter equal to CMPD when the timer is decrementing  */
    CDD_PWM_SOC_TBCTR_D_CMPD = 14U
} Cdd_Pwm_AdcStartOfConversionSourceType;

/** \brief Digital Compare types for PWM module */
typedef enum
{
    CDD_PWM_DC_TYPE_DCAH = 0U, /* Digital Compare A High */
    CDD_PWM_DC_TYPE_DCAL = 1U, /* Digital Compare A Low */
    CDD_PWM_DC_TYPE_DCBH = 2U, /* Digital Compare B High */
    CDD_PWM_DC_TYPE_DCBL = 3U  /* Digital Compare B Low */
} Cdd_Pwm_DigitalCompareType;

/** \brief Digital Compare Trip Input types */
typedef enum
{
    CDD_PWM_DC_TRIP_TRIPIN1     = 0U,  /* Trip 1 */
    CDD_PWM_DC_TRIP_TRIPIN2     = 1U,  /* Trip 2 */
    CDD_PWM_DC_TRIP_TRIPIN3     = 2U,  /* Trip 3 */
    CDD_PWM_DC_TRIP_TRIPIN4     = 3U,  /* Trip 4  */
    CDD_PWM_DC_TRIP_TRIPIN5     = 4U,  /* Trip 5  */
    CDD_PWM_DC_TRIP_TRIPIN6     = 5U,  /* Trip 6  */
    CDD_PWM_DC_TRIP_TRIPIN7     = 6U,  /* Trip 7  */
    CDD_PWM_DC_TRIP_TRIPIN8     = 7U,  /* Trip 8  */
    CDD_PWM_DC_TRIP_TRIPIN9     = 8U,  /* Trip 9  */
    CDD_PWM_DC_TRIP_TRIPIN10    = 9U,  /* Trip 10 */
    CDD_PWM_DC_TRIP_TRIPIN11    = 10U, /* Trip 11 */
    CDD_PWM_DC_TRIP_TRIPIN12    = 11U, /* Trip 12 */
    CDD_PWM_DC_TRIP_TRIPIN14    = 13U, /* Trip 14  */
    CDD_PWM_DC_TRIP_TRIPIN15    = 14U, /* Trip 15  */
    CDD_PWM_DC_TRIP_COMBINATION = 15U  /* All Trips (Trip1 - Trip 15) are selected */
} Cdd_Pwm_DigitalCompareTripInputType;

/** \brief Digital Compare Blanking Pulse types */
typedef enum
{
    /* Time base counter equals period */
    CDD_PWM_DC_WINDOW_START_TBCTR_PERIOD = 0U,
    /* Time base counter equals zero */
    CDD_PWM_DC_WINDOW_START_TBCTR_ZERO = 1U,
    /* Time base counter equals zero or period */
    CDD_PWM_DC_WINDOW_START_TBCTR_ZERO_PERIOD = 2U,
    /* Blank pulse mix */
    CDD_PWM_DC_WINDOW_START_BLANK_PULSE_MIX = 3U
} Cdd_Pwm_DigitalCompareBlankingPulseType;

/** \brief Digital Compare Filter Input types */
typedef enum
{
    CDD_PWM_DC_WINDOW_SOURCE_DCAEVT1 = 0U, /* DC filter signal source is DCAEVT1 */
    CDD_PWM_DC_WINDOW_SOURCE_DCAEVT2 = 1U, /* DC filter signal source is DCAEVT2 */
    CDD_PWM_DC_WINDOW_SOURCE_DCBEVT1 = 2U, /* DC filter signal source is DCBEVT1 */
    CDD_PWM_DC_WINDOW_SOURCE_DCBEVT2 = 3U  /* DC filter signal source is DCBEVT2 */
} Cdd_Pwm_DigitalCompareFilterInputType;

/** \brief Digital Compare Event types */
typedef enum
{
    CDD_PWM_DC_EVENT_1 = 0U, /* Digital Compare Event number 1 */
    CDD_PWM_DC_EVENT_2 = 1U  /* Digital Compare Event number 2 */
} Cdd_Pwm_DigitalCompareEventType;

/** \brief Digital Compare Event Source types */
typedef enum
{
    /* Signal source is unfiltered (DCAEVT1/2) */
    CDD_PWM_DC_EVENT_SOURCE_ORIG_SIGNAL = 0U,
    /* Signal source is filtered (DCEVTFILT) */
    CDD_PWM_DC_EVENT_SOURCE_FILT_SIGNAL = 1U
} Cdd_Pwm_DigitalCompareEventSourceType;

/** \brief Digital Compare Event Sync Mode types */
typedef enum
{
    /* DC input signal is synced with TBCLK */
    CDD_PWM_DC_EVENT_INPUT_SYNCED = 0U,
    /* DC input signal is not synced with TBCLK */
    CDD_PWM_DC_EVENT_INPUT_NOT_SYNCED = 1U
} Cdd_Pwm_DigitalCompareSyncModeType;

/** \brief Digital Compare CBC Latch Mode types */
typedef enum
{
    /* DC cycle-by-cycle(CBC) latch is disabled */
    CDD_PWM_DC_CBC_LATCH_DISABLED = 0x0U,
    /* DC cycle-by-cycle(CBC) latch is enabled */
    CDD_PWM_DC_CBC_LATCH_ENABLED = 0x1U
} Cdd_Pwm_DigitalCompareCbcLatchModeType;

/** \brief Digital Compare CBC Latch Clear Event types */
typedef enum
{
    /* Clear CBC latch when counter equals zero */
    CDD_PWM_DC_CBC_LATCH_CLR_CNTR_ZERO = 0x0U,
    /* Clear CBC latch when counter equals period */
    CDD_PWM_DC_CBC_LATCH_CLR_ON_CNTR_PERIOD = 0x1U,
    /* Clear CBC latch when counter equals zero or period */
    CDD_PWM_DC_CBC_LATCH_CLR_ON_CNTR_ZERO_PERIOD = 0x2U
} Cdd_Pwm_DigitalCompareCBCLatchClearEventType;

/** \brief Capture Gate Input Polarity types */
typedef enum
{
    /* Capture gate is always on */
    CDD_PWM_CAPGATE_INPUT_ALWAYS_ON = 0U,
    /* Capture gate is always off */
    CDD_PWM_CAPGATE_INPUT_ALWAYS_OFF = 1U,
    /* Capture gate input is CAPGATE.sync */
    CDD_PWM_CAPGATE_INPUT_SYNC = 2U,
    /* Capture gate input is CAPGATE.sync inverted */
    CDD_PWM_CAPGATE_INPUT_SYNC_INVERT = 3U
} Cdd_Pwm_SelectCaptureGateInputPolarityType;

/** \brief Capture Input Polarity types */
typedef enum
{
    /* Capture input is not inverted */
    CDD_PWM_CAPTURE_INPUT_CAPIN_SYNC = 0U,
    /* Capture input is inverted */
    CDD_PWM_CAPTURE_INPUT_CAPIN_SYNC_INVERT = 1U
} Cdd_Pwm_SelectCaptureInputPolarityType;

/** \brief Capture Input types */
typedef enum
{
    /* Capture Input */
    CDD_PWM_CAPTURE_INPUT = 0U,
    /* Capture Gate */
    CDD_PWM_CAPTURE_GATE = 1U
} Cdd_Pwm_CaptureInputType;

/** \brief Global Load Trigger types */
typedef enum
{
    /* Load when counter is equal to zero */
    CDD_PWM_GL_LOAD_PULSE_CNTR_ZERO = 0x0U,
    /* Load when counter is equal to period */
    CDD_PWM_GL_LOAD_PULSE_CNTR_PERIOD = 0x1U,
    /* Load when counter is equal to zero or period */
    CDD_PWM_GL_LOAD_PULSE_CNTR_ZERO_PERIOD = 0x2U,
    /* Load on sync event */
    CDD_PWM_GL_LOAD_PULSE_SYNC = 0x3U,
    /* Load on sync event or when counter  is equal to zero */
    CDD_PWM_GL_LOAD_PULSE_SYNC_OR_CNTR_ZERO = 0x4U,
    /* Load on sync event or when counter  is equal to period */
    CDD_PWM_GL_LOAD_PULSE_SYNC_OR_CNTR_PERIOD = 0x5U,
    /* Load on sync event or when counter is equal to period or zero */
    CDD_PWM_GL_LOAD_PULSE_SYNC_CNTR_ZERO_PERIOD = 0x6U,
    /* Load when counter is equal to CMPC while incrementing */
    CDD_PWM_GL_LOAD_PULSE_CNTR_U_CMPC = 0x8U,
    /* Load when counter is equal to CMPC while decrementing  */
    CDD_PWM_GL_LOAD_PULSE_CNTR_D_CMPC = 0x9U,
    /* Load when counter is equal to CMPD while incrementing */
    CDD_PWM_GL_LOAD_PULSE_CNTR_U_CMPD = 0xAU,
    /* Load when counter is equal to CMPD while decrementing  */
    CDD_PWM_GL_LOAD_PULSE_CNTR_D_CMPD = 0xBU,
    /* Load on global force */
    CDD_PWM_GL_LOAD_PULSE_GLOBAL_FORCE = 0xFU
} Cdd_Pwm_GlobalLoadTriggerType;

/** \brief Valley Trigger Source types */
typedef enum
{
    /* Valley capture trigged by software */
    CDD_PWM_VALLEY_TRIGGER_EVENT_SOFTWARE = 0U,
    /* Valley capture trigged by when counter is equal to zero */
    CDD_PWM_VALLEY_TRIGGER_EVENT_CNTR_ZERO = 1U,
    /* Valley capture trigged by when counter is equal period */
    CDD_PWM_VALLEY_TRIGGER_EVENT_CNTR_PERIOD = 2U,
    /* Valley capture trigged when counter is equal to zero or period */
    CDD_PWM_VALLEY_TRIGGER_EVENT_CNTR_ZERO_PERIOD = 3U,
    /* Valley capture trigged by DCAEVT1 (Digital Compare A event 1) */
    CDD_PWM_VALLEY_TRIGGER_EVENT_DCAEVT1 = 4U,
    /* Valley capture trigged by DCAEVT2 (Digital Compare A event 2) */
    CDD_PWM_VALLEY_TRIGGER_EVENT_DCAEVT2 = 5U,
    /* Valley capture trigged by DCBEVT1 (Digital Compare B event 1) */
    CDD_PWM_VALLEY_TRIGGER_EVENT_DCBEVT1 = 6U,
    /* Valley capture trigged by DCBEVT2 (Digital Compare B event 2) */
    CDD_PWM_VALLEY_TRIGGER_EVENT_DCBEVT2 = 7U
} Cdd_Pwm_ValleyTriggerSourceType;

/** \brief Valley Counter Edge types */
typedef enum
{
    CDD_PWM_VALLEY_COUNT_START_EDGE = 0U, /* Valley count start edge */
    CDD_PWM_VALLEY_COUNT_STOP_EDGE  = 1U  /* Valley count stop edge  */
} Cdd_Pwm_ValleyCounterEdgeType;

/** \brief Valley Delay Mode types */
typedef enum
{
    /* Delay value equals the offset value defines by software */
    CDD_PWM_VALLEY_DELAY_MODE_SW_DELAY = 0U,
    /* Delay value equals the sum of the Hardware counter value and the offset value defines by software */
    CDD_PWM_VALLEY_DELAY_MODE_VCNT_DELAY_SW_DELAY = 1U,
    /* Delay value equals the the Hardware counter shifted by (1 + the offset value defines by software) */
    CDD_PWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_1_SW_DELAY = 2U,
    /* Delay value equals the the Hardware counter shifted by (2 + the offset value defines by software) */
    CDD_PWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_2_SW_DELAY = 3U,
    /* Delay value equals the the Hardware counter shifted by (4 + the offset value defines by software) */
    CDD_PWM_VALLEY_DELAY_MODE_VCNT_DELAY_SHIFT_4_SW_DELAY = 4U
} Cdd_Pwm_ValleyDelayModeType;

/** \brief Digital Compare Edge Filter Mode types */
typedef enum
{
    CDD_PWM_DC_EDGEFILT_MODE_RISING  = 0U, /* Digital Compare Edge filter low to high edge mode */
    CDD_PWM_DC_EDGEFILT_MODE_FALLING = 1U, /* Digital Compare Edge filter high to low edge mode */
    CDD_PWM_DC_EDGEFILT_MODE_BOTH    = 2U  /* Digital Compare Edge filter both edges mode  */
} Cdd_Pwm_DigitalCompareEdgeFilterModeType;

/** \brief Digital Compare Edge Filter Edge Count types */
typedef enum
{
    CDD_PWM_DC_EDGEFILT_EDGECNT_0 = 0U, /* Digital Compare Edge filter edge count = 0 */
    CDD_PWM_DC_EDGEFILT_EDGECNT_1 = 1U, /* Digital Compare Edge filter edge count = 1 */
    CDD_PWM_DC_EDGEFILT_EDGECNT_2 = 2U, /* Digital Compare Edge filter edge count = 2 */
    CDD_PWM_DC_EDGEFILT_EDGECNT_3 = 3U, /* Digital Compare Edge filter edge count = 3 */
    CDD_PWM_DC_EDGEFILT_EDGECNT_4 = 4U, /* Digital Compare Edge filter edge count = 4  */
    CDD_PWM_DC_EDGEFILT_EDGECNT_5 = 5U, /* Digital Compare Edge filter edge count = 5  */
    CDD_PWM_DC_EDGEFILT_EDGECNT_6 = 6U, /* Digital Compare Edge filter edge count = 6  */
    CDD_PWM_DC_EDGEFILT_EDGECNT_7 = 7U  /* Digital Compare Edge filter edge count = 7U  */
} Cdd_Pwm_DigitalCompareEdgeFilterEdgeCountType;

/** \brief Mixed Event Interrupt Source types */
typedef enum
{
    /* Time-base counter equal to zero */
    CDD_PWM_ETMIX_TBCTR_ZERO = 0U,
    /* Time-base counter equal to period */
    CDD_PWM_ETMIX_TBCTR_PERIOD = 1U,
    /* Time-base counter equal to CMPA when the timer is incrementing */
    CDD_PWM_ETMIX_TBCTR_U_CMPA = 2U,
    /* Time-base counter equal to CMPA when the timer is decrementing  */
    CDD_PWM_ETMIX_TBCTR_D_CMPA = 3U,
    /* Time-base counter equal to CMPB when the timer is incrementing */
    CDD_PWM_ETMIX_TBCTR_U_CMPB = 4U,
    /* Time-base counter equal to CMPB when the timer is decrementing  */
    CDD_PWM_ETMIX_TBCTR_D_CMPB = 5U,
    /* Time-base counter equal to CMPC when the timer is incrementing */
    CDD_PWM_ETMIX_TBCTR_U_CMPC = 6U,
    /* Time-base counter equal to CMPC when the timer is decrementing  */
    CDD_PWM_ETMIX_TBCTR_D_CMPC = 7U,
    /* Time-base counter equal to CMPD when the timer is incrementing */
    CDD_PWM_ETMIX_TBCTR_U_CMPD = 8U,
    /* Time-base counter equal to CMPD when the timer is decrementing  */
    CDD_PWM_ETMIX_TBCTR_D_CMPD = 9U,
    /* Event is based on DCAEVT1 */
    CDD_PWM_ETMIX_DCAEVT1 = 10U
} Cdd_Pwm_EvtMixTriggerSourceType;

/** \brief ET Mix Signal Select types */
typedef enum
{
    /* Mixed ET Interrupt signal */
    CDD_PWM_ETMIX_INTERRUPT = 0x0U,
    /* Mixed ET SOCA signal */
    CDD_PWM_ETMIX_SOCA = 0x1U,
    /* Mixed ET SOCB signal */
    CDD_PWM_ETMIX_SOCB = 0x2U
} Cdd_Pwm_EtMixSignalSelectType;

/** \brief Lock Register Group types */
typedef enum
{
    CDD_PWM_REGISTER_GROUP_GLOBAL_LOAD     = 0x2U, /* Global load register group */
    CDD_PWM_REGISTER_GROUP_TRIP_ZONE       = 0x4U, /* Trip zone register group */
    CDD_PWM_REGISTER_GROUP_TRIP_ZONE_CLEAR = 0x8U, /* Trip zone clear group */
    CDD_PWM_REGISTER_GROUP_DIGITAL_COMPARE = 0x10U /* Digital compare group */
} Cdd_Pwm_LockRegisterGroupType;

/** \brief HRPWM MEP Edge Mode types */
typedef enum
{
    /* HRPWM is disabled */
    CDD_PWM_HRPWM_MEP_CTRL_DISABLE = 0U,
    /* MEP controls rising edge */
    CDD_PWM_HRPWM_MEP_CTRL_RISING_EDGE = 1U,
    /* MEP controls falling edge */
    CDD_PWM_HRPWM_MEP_CTRL_FALLING_EDGE = 2U,
    /* MEP controls both rising and falling edge */
    CDD_PWM_HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE = 3U
} Cdd_Pwm_HrpwmMepEdgeModeType;

/** \brief HRPWM MEP Control Mode types */
typedef enum
{
    /* CMPAHR/CMPBHR or TBPRDHR controls MEP edge */
    CDD_PWM_HRPWM_MEP_DUTY_PERIOD_CTRL = 0U,
    /* TBPHSHR controls MEP edge */
    CDD_PWM_HRPWM_MEP_PHASE_CTRL = 1U
} Cdd_Pwm_HrpwmMepCtrlModeType;

/** \brief HRPWM Load Mode types */
typedef enum
{
    /* load when counter equals zero */
    CDD_PWM_HRPWM_LOAD_ON_CNTR_ZERO = 0U,
    /* load when counter equals period */
    CDD_PWM_HRPWM_LOAD_ON_CNTR_PERIOD = 1U,
    /* load when counter equals zero or period */
    CDD_PWM_HRPWM_LOAD_ON_CNTR_ZERO_PERIOD = 2U,
    /* load on translator event CMPA/B-3 */
    CDD_PWM_HRPWM_LOAD_ON_CMP_EQ = 3U
} Cdd_Pwm_HrpwmLoadModeType;

/** \brief HRPWM Channel B Output types */
typedef enum
{
    /* CDD_PWMxB output is normal */
    CDD_PWM_HRPWM_OUTPUT_ON_B_NORMAL = 0U,
    /* CDD_PWMxB output is inverted version of EPWMxA signal */
    CDD_PWM_HRPWM_OUTPUT_ON_B_INV_A = 1U
} Cdd_Pwm_HrpwmChannelBOutputType;

/** \brief HRPWM Sync Pulse Source types */
typedef enum
{
    /* Counter equals Period */
    CDD_PWM_HRPWM_PWMSYNC_SOURCE_PERIOD = 0U,
    /* Counter equals zero */
    CDD_PWM_HRPWM_PWMSYNC_SOURCE_ZERO = 1U,
    /* Counter equals COMPC when counting up */
    CDD_PWM_HRPWM_PWMSYNC_SOURCE_COMPC_UP = 4U,
    /* Counter equals COMPC when counting down */
    CDD_PWM_HRPWM_PWMSYNC_SOURCE_COMPC_DOWN = 5U,
    /* Counter equals COMPD when counting up */
    CDD_PWM_HRPWM_PWMSYNC_SOURCE_COMPD_UP = 6U,
    /* Counter equals COMPD when counting down */
    CDD_PWM_HRPWM_PWMSYNC_SOURCE_COMPD_DOWN = 7U
} Cdd_Pwm_HrpwmSyncPulseSourceType;

/** \brief HRPWM MEP Dead Band Edge Mode types */
typedef enum
{
    /* HRPWM is disabled */
    CDD_PWM_HRPWM_DB_MEP_CTRL_DISABLE = 0U,
    /* MEP controls Rising Edge Delay */
    CDD_PWM_HRPWM_DB_MEP_CTRL_RED = 1U,
    /* MEP controls Falling Edge Delay */
    CDD_PWM_HRPWM_DB_MEP_CTRL_FED = 2U,
    /* MEP controls both Falling and Rising edge delay */
    CDD_PWM_HRPWM_DB_MEP_CTRL_RED_FED = 3U
} Cdd_Pwm_HrpwmMepDeadBandEdgeModeType;

/** \brief HRPWM Lock Register Group types */
typedef enum
{
    CDD_PWM_HRPWM_REGISTER_GROUP_HRPWM           = 0x1U, /* HRPWM register group */
    CDD_PWM_HRPWM_REGISTER_GROUP_GLOBAL_LOAD     = 0x2U, /* Global load register group */
    CDD_PWM_HRPWM_REGISTER_GROUP_TRIP_ZONE       = 0x4U, /* Trip zone register group */
    CDD_PWM_HRPWM_REGISTER_GROUP_TRIP_ZONE_CLEAR = 0x8U, /* Trip zone clear group */
    CDD_PWM_HRPWM_REGISTER_GROUP_DIGITAL_COMPARE = 0x10U /* Digital compare group */
} Cdd_Pwm_HrpwmLockRegisterGroupType;

#endif

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)

/* Design: MCAL-33882 */
/* PWM Hardware unit configuration */
typedef struct Cdd_Pwm_HwUnitCfgTag
{
    /* PWM instance ID */
    uint8                       instance_id;
    /* Class type of the PWM channel */
    Cdd_Pwm_ChannelClassType    channelclass;
    /* Clock divider */
    Cdd_Pwm_ClockDividerType    clockdivider;
    /* High speed clock divider */
    Cdd_Pwm_HighSpeedClkDivType highspeed_clkdiv;
    /* Default period */
    Cdd_Pwm_PeriodType          period;
    /* Base address of the PWM channel */
    uint32                      base_addr;
    /* Symmetry of the waveform */
    Cdd_Pwm_OutputSymmetryType  symmetry; /* Design: MCAL-33852 */
    /* Interrupt enable/disable */
    boolean                     enable_interrupt;
    /* Starting channel ID  */
    uint8                       startchannel;
    /* Last channel ID */
    uint8                       lastchannel;
    /* Emulation mode */
    Cdd_Pwm_EmulationModeType   emulation_mode;
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /* Idle state of the PWM channel */
    Cdd_Pwm_NotificationType notification;
#endif
} Cdd_Pwm_HwUnitCfgType;

/* Design: MCAL-33883 */
/* Pwm channel configation */
typedef struct Cdd_Pwm_ChannelCfgTag
{
    /* PMW instance index*/
    uint8                     hw_index;
    /* Output type of the channel */
    Cdd_Pwm_OutputChannelType outputchannel;
    /* Default duty cycle */
    Cdd_Pwm_DutyCycleType     dutycycle;
    /* Idle state of the PWM channel */
    Cdd_Pwm_OutputStateType   idlestate;
    /* Polarity of the PWM channel (Active Low or Active High) */
    Cdd_Pwm_OutputStateType   polarity;
} Cdd_Pwm_ChannelCfgType;

/** \brief PWM driver configuration */
typedef struct Cdd_Pwm_ConfigTag
{
    /** \brief  PWM hardware instance configurations */
    Cdd_Pwm_HwUnitCfgType  hwunitcfg[CDD_PWM_COUNT];
    /** \brief  Channel configurations */
    Cdd_Pwm_ChannelCfgType channelcfg[CDD_PWM_CHANNEL_COUNT];
} Cdd_Pwm_ConfigType;

#else

typedef struct Cdd_Pwm_HwUnitCfgTag
{
    /* PWM instance ID */
    uint8  instance_id;
    /* Base address of the PWM channel */
    uint32 base_addr;
#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
    /* PWM interrupt notification */
    Cdd_Pwm_NotificationType         notification;
    /* Trip zone interrupt notification */
    Cdd_Pwm_TripZoneNotificationType tripzone_notification;
#endif
} Cdd_Pwm_HwUnitCfgType;

/** \brief PWM driver configuration */
typedef struct Cdd_Pwm_ConfigTag
{
    /** \brief  PWM hardware instance configurations */
    Cdd_Pwm_HwUnitCfgType hwunitcfg[CDD_PWM_HW_AND_XLINK_COUNT];
    /** \brief EPWM XLINK configuration */
    uint32                xlink_hwmask[CDD_PWM_XLINK_GRP_COUNT];
    /** \brief HRPWM Calibration configuration */
    uint32                hrpwmcal_baseaddr[CDD_PWM_CONFIG_HRPWMCAL_COUNT];
} Cdd_Pwm_ConfigType;
#endif

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief Service to initialize Cdd Pwm driver.
 *
 * This service initializes all the PWM channels with the configured values.
 *
 * \param[in] CfgPtr Pointer to configuration set (Variant PC requires a NULL_PTR)
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_Init(P2CONST(Cdd_Pwm_ConfigType, AUTOMATIC, CDD_PWM_CFG) CfgPtr);

#if (STD_ON == CDD_PWM_VERSION_INFO_API)
/** \brief service that returns the version information of the module
 *
 * This service returns the version information of the Pwm module
 *
 * \param[in] VersionInfo    Pointer to where to store the version information of this module
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATICU, CDD_PWM_DATA) VersionInfo);
#endif

#if (STD_OFF == CDD_PWM_ADVANCED_MODE_API)

#if (STD_ON == CDD_PWM_DEINIT_API)
/** \brief Service to deinitialize Cdd Pwm driver.
 *
 * This service de-initializes the PWM driver.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DeInit(void);
#endif

#if (STD_ON == CDD_PWM_SET_DUTY_CYCLE_API)
/** \brief Service to set the duty cycle
 *
 * This service sets the duty cycle for the requested PWM Channel.
 *
 * \param[in] ChannelId     Numeric ID of the requested PWM Channel.
 * \param[in] DutyCycle         Duty cycles for the requested PWM Channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDutyCycle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId, VAR(Cdd_Pwm_DutyCycleType, AUTOMATIC) DutyCycle);
#endif

#if (STD_ON == CDD_PWM_SET_PERIOD_API)
/** \brief Service to set the period and duty cycle for a PWM channel
 *
 * This service sets period and duty cycle for the requested PWM Channel.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Period            Period for the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetPeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_PeriodType, AUTOMATIC) Period);
#endif

#if (STD_ON == CDD_PWM_SET_OUTPUT_TO_IDLE_API)
/** \brief Service to set the output to IDLE for a PWM channel
 *
 * This service sets the output to IDLE for the requested PWM Channel.
 *
 * \param[in] ChannelId     Numeric ID of the requested PWM Channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetOutputToIdle(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId);
#endif

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/** \brief Sets the EPWM interrupt event counts
 *
 * This function sets the interrupt event count that determines the number of
 * events that have to occur before an interrupt is issued.
 * Maximum value for EventCount is 15.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] EventCount     Event count for interrupt scale
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetInterruptEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) EventCount);

/** \brief Service to enable the PWM signal edge notification according to notification parameter
 *
 * This service enables the PWM signal edge notification according to notification parameter
 *
 * \param[in] ChannelId         Numeric ID of the requested PWM Channel.
 * \param[in] EdgeNotification  Type of notification for edge detection.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_EnableNotification(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId,
                           VAR(Cdd_Pwm_EdgeNotificationType, AUTOMATIC) EdgeNotification);

/** \brief Service to disable the PWM signal edge notification
 *
 * This service disables signal edge notification for the requested PWM Channels.
 *
 * \param[in] ChannelId     Numeric ID of the requested PWM Channel.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DisableNotification(VAR(Cdd_Pwm_ChannelType, AUTOMATIC) ChannelId);

#endif

#endif

#if (STD_ON == CDD_PWM_ADVANCED_MODE_API)

#if (STD_ON == CDD_PWM_NOTIFICATION_SUPPORTED)
/** \brief Service to enable the PWM signal edge notification according to notification parameter
 *
 * This service enables the PWM signal edge notification according to notification parameter
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_EnableNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Service to disable the PWM signal edge notification
 *
 * This service disables signal edge notification for the requested PWM Channels.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DisableNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Service to configure trip zone notification
 *
 * This service configures trip zone notification.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Select         Boolean to enable/disable the notification.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZoneNotification(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

#endif

/** \brief Sets the EPWM interrupt event counts
 *
 * This function sets the interrupt event count that determines the number of
 * events that have to occur before an interrupt is issued.
 * Maximum value for EventCount is 15.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] EventCount     Event count for interrupt scale
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetInterruptEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) EventCount);

/** \brief Service to set emulation mode
 *
 * This function sets the emulation behaviours of the time base counter. Valid
 * values for emulationMode are:
 *  - CDD_PWM_EMULATION_STOP_AFTER_NEXT_TB    - Stop after next Time Base counter
 *                                           increment or decrement.
 *  - CDD_PWM_EMULATION_STOP_AFTER_FULL_CYCLE - Stop when counter completes whole
 *                                           cycle
 *  - CDD_PWM_EMULATION_FREE_RUN               - Free run.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] EmulationMode   Emulation Mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                         VAR(Cdd_Pwm_EmulationModeType, AUTOMATIC) EmulationMode);

/** \brief Set the time base count
 *
 * This function sets the 16 bit counter value of the time base counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Count          Time base count value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTimeBaseCounter(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) Count);

/** \brief Set count mode after phase shift sync
 *
 * This function sets the time base count to count up or down after a new
 * phase value set by the Cdd_Pwm_SetPhaseShift(). The count direction is
 * determined by the variable mode Valid inputs for mode are:
 *  - CDD_PWM_COUNT_MODE_UP_AFTER_SYNC      - Count up after sync
 *  - CDD_PWM_COUNT_MODE_DOWN_AFTER_SYNC    - Count down after sync
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Mode           Count mode after sync.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetCountModeAfterSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_SyncCountModeType, AUTOMATIC) Mode);

/** \brief Set the time base clock and the high speed time base clock count pre-scaler
 *
 * This function sets the pre scaler(divider)value for the time base clock
 * counter and the high speed time base clock counter.
 * Valid values for pre-scaler and highSpeedPrescaler are CDD_PWM_CLOCK_DIVIDER_X,
 * where X is 1U,2U,4U,8U,16U,32U,64 or 128.
 * The actual numerical values for these macros represent values 0U,1...7.
 * The equation for the output clock is:
 *   TBCLK = EPWMCLK/(highSpeedPrescaler * pre-scaler)
 *
 * \b Note: EPWMCLK is a scaled version of SYSCLK. At reset EPWMCLK is half
 *          SYSCLK.
 *
 * \param[in] InstanceId          Numeric ID of the requested PWM instance
 * \param[in] Prescaler           Time base count pre scale value
 * \param[in] HighSpeedPrescaler  High speed time base count pre scale value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetClockPrescaler(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_ClockDividerType, AUTOMATIC) Prescaler,
                          VAR(Cdd_Pwm_HighSpeedClkDivType, AUTOMATIC) HighSpeedPrescaler);

/** \brief Force a software sync pulse
 *
 * This function causes a single software initiated sync pulse Make sure the
 * appropriate mode is selected using Cdd_Pwm_SetupSyncOutputMode() before using
 * this function.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceSyncPulse(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set up the source for sync-in pulse
 *
 * This function set the sync out pulse mode
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Source         Sync-in pulse source
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetSyncInPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_SyncInPulseSourceType, AUTOMATIC) Source);

/** \brief Enables sync-out pulse source
 *
 * This function enables the sync-out pulse source
 * Below valid values for param \b Source can be OR'd together to enable
 * multiple sync-out sources:
 * - CDD_PWM_SYNC_OUT_PULSE_ON_SOFTWARE - sync-out pulse is generated by
 *                                     software when CDD_PWM_forceSyncPulse()
 *                                     function is called or by EPWMxSYNCI
 *                                     signal.
 * - CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_ZERO - sync-out pulse is generated when
 *                                      time base counter equals zero.
 * - CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_B - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           B value
 * - CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_C - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           C value
 * - CDD_PWM_SYNC_OUT_PULSE_ON_CNTR_COMPARE_D - sync-out pulse is generated when
 *                                           time base counter equals compare
 *                                           D value
 * - CDD_PWM_SYNC_OUT_PULSE_ON_DCA_EVT1_SYNC - sync-out pulse is generated by DCA
 *                                          event1 sync signal
 * - CDD_PWM_SYNC_OUT_PULSE_ON_DCB_EVT1_SYNC - sync-out pulse is generated by DCB
 *                                          event1 sync signal
 * - CDD_PWM_SYNC_OUT_PULSE_ON_ALL  - sync-out pulse is generated by all
 *                                 the above sources
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Source         Sync-out pulse source
 * \param[in] Select         Boolean to enable/disable the source
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureSyncOutPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_SyncOutPulseSourceType, AUTOMATIC) Source,
                                    VAR(boolean, AUTOMATIC) Select);

/** \brief Set up the one-shot sync-out trigger source
 *
 * This function sets the one-shot sync-out trigger source
 * Valid values for param \b Trigger are:
 *  - CDD_PWM_OSHT_SYNC_OUT_TRIG_SYNC - Trigger for one-shot sync-out signal is
 *                                    one-shot sync event.
 *  - CDD_PWM_OSHT_SYNC_OUT_TRIG_RELOAD - Trigger for one-shot sync-out signal is
 *                                     one-shot reload event.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Trigger        One-shot sync-out signal trigger source
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetOneShotSyncOutTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_OneShotSyncOutTriggerType, AUTOMATIC) Trigger);

/** \brief Set PWM period load mode
 *
 * This function sets the load mode for the PWM period. If LoadMode is set to
 * CDD_PWM_PERIOD_SHADOW_LOAD, a write or read to the TBPRD (PWM Period count
 * register) accesses the shadow register. If LoadMode is set to
 * CDD_PWM_PERIOD_DIRECT_LOAD, a write or read to the TBPRD register accesses the
 * register directly.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] LoadMode       PWM period load mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetPeriodLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_PeriodLoadModeType, AUTOMATIC) LoadMode);

/** \brief Enable phase shift load
 *
 * This function enables loading of phase shift when the appropriate sync event occurs.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Select         Boolean to enable/disable phase shift load.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set time base counter mode
 *
 * This function sets up the time base counter mode
 * Valid values for CounterMode are:
 *  - CDD_PWM_COUNTER_MODE_UP          - Up - count mode
 *  - CDD_PWM_COUNTER_MODE_DOWN        - Down - count mode
 *  - CDD_PWM_COUNTER_MODE_UP_DOWN     - Up - down - count mode
 *  - CDD_PWM_COUNTER_MODE_STOP_FREEZE - Stop - Freeze counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] CounterMode    Time base counter mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTimeBaseCounterMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_TimeBaseCountModeType, AUTOMATIC) CounterMode);

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
 * \param[in] ShadowLoadMode    Shadow to active load mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectPeriodLoadEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_PeriodShadowLoadModeType, AUTOMATIC) ShadowLoadMode);

/** \brief Enable/disable one shot sync mode
 *
 * This function Enable/disables one shot sync mode
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Select         Boolean to enable/disable one shot sync mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureOneShotSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Start one shot sync mode
 *
 * This function propagates a one shot sync pulse
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_StartOneShotSync(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Returns time base counter value
 *
 * This function returns the current value of the time base counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Time base counter value
 * \retval uint16 Current value of the time base counter
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return time base counter maximum status
 *
 * This function returns the status of the time base max counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Status of time base counter overflow
 * \retval boolean True if the counter has reached 0xFFFF, false otherwise
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterOverflowStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Clear max time base counter event
 *
 * This function clears the max time base counter latch event. The latch event
 * occurs when the time base counter reaches its maximum value of 0xFFFF.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearTimeBaseCounterOverflowEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return external sync signal status
 *
 * This function returns the external sync signal status.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Status of external sync signal
 * \retval boolean True if an external sync signal event occurred, false otherwise
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_GetSyncStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Clear external sync signal event
 *
 * This function clears the external sync signal latch event.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearSyncEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return time base counter direction
 *
 * This function returns the direction of the time base counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return Counter direction status
 * \retval uint16 CDD_PWM_TIME_BASE_STATUS_COUNT_UP if counting up or
 *                CDD_PWM_TIME_BASE_STATUS_COUNT_DOWN if counting down
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetTimeBaseCounterDirection(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Sets the phase shift offset counter value
 *
 * This function sets the 16 bit time-base counter phase of the EPWM relative
 * to the time-base that is supplying the synchronization input signal. Call
 * the Cdd_Pwm_EnablePhaseShiftLoad() function to enable loading of the
 * PhaseCount phase shift value when a sync event occurs.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] PhaseCount     Phase shift count value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) PhaseCount);

/** \brief Sets the PWM period count
 *
 * This function sets the period of the PWM count. The value of PeriodCount is
 * the value written to the register. User should map the desired period or
 * frequency of the waveform into the correct PeriodCount.
 * Invoke the function Cdd_Pwm_SelectPeriodLoadEvent() with the appropriate
 * parameter to set the load mode of the Period count. PeriodCount has a
 * maximum valid value of 0xFFFF
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] PeriodCount    Period count value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) PeriodCount);

/** \brief Gets the PWM period count
 *
 * This function gets the period of the PWM count.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The period count value
 * \retval uint16 Current period count value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Sets up the Counter Compare shadow load mode
 *
 * This function enables and sets up the counter compare shadow load mode
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] CompModule     Counter compare module
 * \param[in] LoadMode       Shadow to active load mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetCounterCompareShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule,
                                        VAR(Cdd_Pwm_CounterCompareLoadModeType, AUTOMATIC) LoadMode);

/** \brief Disables counter compare shadow load mode
 *
 * This function disables counter compare shadow load mode
 * Valid values for the variables are:
 *  - CompModule
 *      - CDD_PWM_COUNTER_COMPARE_A - counter compare A.
 *      - CDD_PWM_COUNTER_COMPARE_B - counter compare B.
 *      - CDD_PWM_COUNTER_COMPARE_C - counter compare C.
 *      - CDD_PWM_COUNTER_COMPARE_D - counter compare D.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] CompModule     Counter compare module
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableCounterCompareShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] CompModule     Counter Compare value module
 * \param[in] CompCount      Counter compare count value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] CompModule     Counter Compare value module
 * \pre None
 * \post None
 * \return The counter compare count value
 * \retval uint16 Counter compare value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_CounterCompareModuleType, AUTOMATIC) CompModule);

/** \brief Returns the counter compare shadow register full status
 *
 * This function returns the counter Compare shadow register full status flag.
 * Valid values for OuputChannel are:
 *   - CDD_PWM_COUNTER_COMPARE_A - counter compare A.
 *   - CDD_PWM_COUNTER_COMPARE_B - counter compare B.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OuputChannel   Counter Compare value module
 * \pre None
 * \post None
 * \return Shadow register full status
 * \retval TRUE  If the shadow register is full.
 * \retval FALSE If the shadow register is not full.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE)
Cdd_Pwm_GetCounterCompareShadowStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OuputChannel);

/** \brief Enable/disables CMPAHR, CMPBHR register linking
 *
 * This function Enable/disables CMPAHR and CMPBHR register linking. CMPBHR assumes
 * the same value as CMPAHR.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Select         Enable/disable selection.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureLinkDutyHR(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/**
 * Action Qualifier module related APIs
 */

/** \brief Sets the Action Qualifier shadow load mode
 *
 * This function enables and sets the Action Qualifier shadow load mode
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  Action Qualifier module value
 * \param[in] LoadMode       Shadow to active load mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(Cdd_Pwm_ActionQualifierLoadModeType, AUTOMATIC) LoadMode);

/** \brief Disables Action Qualifier shadow load mode
 *
 * This function disables the Action Qualifier shadow load mode
 * Valid values for the variables are:
 *  - OutputChannel
 *      - CDD_PWM_ACTION_QUALIFIER_A - Action Qualifier A.
 *      - CDD_PWM_ACTION_QUALIFIER_B - Action Qualifier B.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  Action Qualifier module value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableActionQualifierShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_CDD_PWM_SYNCIN - EPWM sync
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT  - Digital compare filter event
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Trigger        Sources for Action Qualifier triggers.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierT1TriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_CDD_PWM_SYNCIN - EPWM sync
 *   - CDD_PWM_AQ_TRIGGER_EVENT_TRIG_DC_EVTFILT  - Digital compare filter event
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Trigger        Sources for Action Qualifier triggers.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierT2TriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_ActionQualifierTriggerSourceType, AUTOMATIC) Trigger);

/** \brief Sets up Action qualifier outputs
 *
 * This function sets up the Action Qualifier output on EPWM A or EPWMB,
 * depending on the value of EpwmOutput, to a value specified by Output based
 * on the input events - specified by Event.
 * The following are valid values for the parameters.
 *   - EpwmOutput
 *       - CDD_PWM_AQ_OUTPUT_A          - EPWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - EPWMxB output
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] EpwmOutput     The EPWM output type
 * \param[in] Output         The Action Qualifier output.
 * \param[in] Event          The event that causes a change in output.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) EpwmOutput,
                                 VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                 VAR(Cdd_Pwm_ActionQualifierOutputEventType, AUTOMATIC) Event);

/**********************************************************************************************************************
 *
 * Set up Action qualifier event outputs
 *
 * This function sets up the Action Qualifier output on EPWMA or EPWMB,
 * depending on the value of EpwmOutput, to a value specified by action.
 * Valid action param values from different time base counter scenarios
 * should be OR'd together to configure complete action for a pwm output.
 * The following are valid values for the parameters.
 *   - EpwmOutput
 *       - CDD_PWM_AQ_OUTPUT_A          - EPWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - EPWMxB output
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
 * \b note:  A logical OR of the valid values should be passed as the action
 *           parameter. Single action should be configured for each time base
 *           counter scenario.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  EPWM output type
 * \param[in] Action         Desired action when the specified event occurs
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 **********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(Cdd_Pwm_ActionQualifierEventActionType, AUTOMATIC) Action);

/** \brief Sets up Additional action qualifier event outputs
 *
 * This function sets up the Additional Action Qualifier output on EPWMA or
 * EPWMB depending on the value of OutputChannel, to a value specified by Action.
 * Valid Action param values from different event scenarios should be OR'd
 * together to configure complete action for a pwm output.
 * The following are valid values for the parameters.
 *   - OutputChannel
 *       - CDD_PWM_AQ_OUTPUT_A          - EPWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - EPWMxB output
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  The EPWM output type
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
Cdd_Pwm_SetAdditionalActionQualifierActionComplete(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                                   VAR(Cdd_Pwm_AdditionalActionQualifierEventActionType, AUTOMATIC)
                                                       Action);

/** \brief Sets up Action qualifier continuous software load mode
 *
 * This function sets up the AQCFRSC register load mode for continuous
 * software force reload mode The software force actions are determined by
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Mode           Mode for shadow to active load mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierContSwForceShadowMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_ActionQualifierContForceType, AUTOMATIC) Mode);

/** \brief Triggers a continuous software forced event
 *
 * This function triggers a continuous software forced Action Qualifier output
 * on EPWM A or B based on the value of OutputChannel.
 * Valid values for the parameters are:
 *   - OutputChannel
 *       - CDD_PWM_AQ_OUTPUT_A          - EPWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - EPWMxB output
 *   - Output
 *       - CDD_PWM_AQ_SW_DISABLED       - Software forcing disabled.
 *       - CDD_PWM_AQ_SW_OUTPUT_LOW     - Set output pins to low
 *       - CDD_PWM_AQ_SW_OUTPUT_HIGH    - Set output pins to High
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  The EPWM output type
 * \param[in] Output         The Action Qualifier output.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierContSwForceAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                            VAR(Cdd_Pwm_ActionQualifierSwOutputType, AUTOMATIC) Output);

/** \brief Sets up one time software forced Action qualifier outputs
 *
 * This function sets up the one time software forced Action Qualifier output
 * on EPWM A or EPWMB, depending on the value of OutputChannel to a value
 * specified by Output.
 * The following are valid values for the parameters.
 *   - OutputChannel
 *       - CDD_PWM_AQ_OUTPUT_A          - EPWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - EPWMxB output
 *   - Output
 *       - CDD_PWM_AQ_OUTPUT_NO_CHANGE  - No change in the output pins
 *       - CDD_PWM_AQ_OUTPUT_LOW        - Set output pins to low
 *       - CDD_PWM_AQ_OUTPUT_HIGH       - Set output pins to High
 *       - CDD_PWM_AQ_OUTPUT_TOGGLE     - Toggle the output pins
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  The EPWM output type
 * \param[in] Output         The Action Qualifier output.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                   VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output);

/** \brief Triggers a one time software forced event on Action qualifier
 *
 * This function triggers a one time software forced Action Qualifier event
 * on EPWM A or B based on the value of OutputChannel.
 * Valid values for OutputChannel are:
 *   - CDD_PWM_AQ_OUTPUT_A          - EPWMxA output
 *   - CDD_PWM_AQ_OUTPUT_B          - EPWMxB output
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  The EPWM output type
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ForceActionQualifierSwAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/*
 * Dead Band Module related APIs
 */

/** \brief Sets Dead Band signal output swap mode
 *
 * This function sets up the output signal swap mode For example if the
 * output variable is set to CDD_PWM_DB_OUTPUT_A and enableSwapMode is true, then
 * the EPWM A output gets its signal from the EPWM B signal path.
 *
 * \param[in] InstanceId       Numeric ID of the requested PWM instance
 * \param[in] OutputChannel    The EPWM Dead Band output.
 * \param[in] EnableSwapMode   The output swap mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                  VAR(boolean, AUTOMATIC) EnableSwapMode);

/** \brief Sets Dead Band signal output mode
 *
 * This function sets up the dead band delay mode The delayMode variable
 * determines if the applied delay is Rising Edge or Falling Edge The
 * enableDelayMode determines if a dead band delay should be applied.
 * Valid values for the variables are:
 *  - delayMode
 *      - CDD_PWM_DB_RED   - Rising Edge delay
 *      - CDD_PWM_DB_FED   - Falling Edge delay
 *  - enableDelayMode
 *      - true     - Falling edge or Rising edge delay is applied.
 *      - false    - Dead Band delay is bypassed.
 *
 * \param[in] InstanceId       Numeric ID of the requested PWM instance
 * \param[in] DelayMode        The Dead Band delay type
 * \param[in] EnableDelayMode  The dead band delay mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandDelayMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                             VAR(boolean, AUTOMATIC) EnableDelayMode);

/** \brief Sets Dead Band delay polarity
 *
 * This function sets up the polarity as determined by the variable polarity
 * of the Falling Edge or Rising Edge delay depending on the value of
 * delayMode Valid values for the variables are:
 *   - delayMode
 *       - CDD_PWM_DB_RED   - Rising Edge delay
 *       - CDD_PWM_DB_FED   - Falling Edge delay
 *   - polarity
 *       - CDD_PWM_DB_POLARITY_ACTIVE_HIGH   - polarity is not inverted.
 *       - CDD_PWM_DB_POLARITY_ACTIVE_LOW    - polarity is inverted.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] DelayMode      The Dead Band delay type
 * \param[in] Polarity       The polarity of the delayed signal.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandDelayPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_DeadBandDelayModeType, AUTOMATIC) DelayMode,
                                 VAR(Cdd_Pwm_DeadBandPolarityType, AUTOMATIC) Polarity);

/** \brief Sets Rising Edge Dead Band delay input
 *
 * This function sets up the rising Edge delay input signal.
 * Valid values for input are:
 *     - CDD_PWM_DB_INPUT_EPWMA   - Input signal is EPWMA( Valid for both Falling
 *                                  Edge and Rising Edge)
 *     - CDD_PWM_DB_INPUT_EPWMB   - Input signal is EPWMB( Valid for both Falling
 *                                  Edge and Rising Edge)
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  The input signal to the dead band.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetRisingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/** \brief Sets Dead Band delay input
 *
 * This function sets up the rising Edge delay input signal.
 * Valid values for input are:
 *   - CDD_PWM_DB_INPUT_EPWMA   - Input signal is EPWMA(Valid for both Falling
 *                                Edge and Rising Edge)
 *   - CDD_PWM_DB_INPUT_EPWMB   - Input signal is EPWMB(Valid for both Falling
 *                                Edge and Rising Edge)
 *   - CDD_PWM_DB_INPUT_DB_RED  - Input signal is the output of Rising
 *                                Edge delay.
 *                               (Valid only for Falling Edge delay)
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Input          The input signal to the dead band.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetFallingEdgeDeadBandDelayInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DeadBandDelayInputType, AUTOMATIC) Input);

/** \brief Set the Dead Band control shadow load mode
 *
 * This function enables and sets the Dead Band control register shadow
 * load mode
 * Valid values for the \e loadMode parameter are:
 *     - CDD_PWM_DB_LOAD_ON_CNTR_ZERO         - load when counter equals zero.
 *     - CDD_PWM_DB_LOAD_ON_CNTR_PERIOD       - load when counter equals period.
 *     - CDD_PWM_DB_LOAD_ON_CNTR_ZERO_PERIOD  - load when counter equals zero or
 *                                            period.
 *     - CDD_PWM_DB_LOAD_FREEZE                - Freeze shadow to active load.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] LoadMode       The shadow to active load mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_DeadBandControlLoadModeType, AUTOMATIC) LoadMode);

/** \brief Disable Dead Band control shadow load mode
 *
 * This function disables the Dead Band control register shadow
 * load mode
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_DisableDeadBandControlShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set the RED (Rising Edge Delay) shadow load mode
 *
 * This function sets the Rising Edge Delay register shadow load mode
 * Valid values for the \e loadMode parameter are:
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO        - load when counter equals zero.
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_PERIOD      - load when counter equals period.
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero or
 *                                           period.
 *     - CDD_PWM_DELAY_LOAD_FREEZE               - Freeze shadow to active load.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] LoadMode       The shadow to active load event.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetRisingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_DeadBandDelayLoadModeType, AUTOMATIC) LoadMode);

/** \brief Disable the RED (Rising Edge Delay) shadow load mode
 *
 * This function disables the Rising Edge Delay register shadow load mode
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
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
 * mode Valid values for the \e loadMode parameters are:
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO        - load when counter equals zero.
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_PERIOD      - load when counter equals period.
 *     - CDD_PWM_DELAY_LOAD_ON_CNTR_ZERO_PERIOD - load when counter equals zero or
 *                                            period.
 *     - CDD_PWM_DELAY_LOAD_FREEZE               - Freeze shadow to active load.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] LoadMode       The shadow to active load event.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_DeadBandDelayLoadModeType, AUTOMATIC) LoadMode);

/** \brief Disables the FED (Falling Edge Delay) shadow load mode
 *
 * This function disables the Falling Edge Delay register shadow load mode
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_DisableFallingEdgeDelayCountShadowLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Sets Dead Band Counter clock rate
 *
 * This function sets up the Dead Band counter clock rate with respect to
 * TBCLK (EPWM time base counter).
 * Valid values for clockMode are:
 *   - CDD_PWM_DB_COUNTER_CLOCK_FULL_CYCLE  -Dead band counter runs at TBCLK
 *                                           (EPWM Time Base Counter) rate
 *   - CDD_PWM_DB_COUNTER_CLOCK_HALF_CYCLE  -Dead band counter runs at 2*TBCLK
 *                                         (twice EPWM Time Base Counter)rate
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] ClockMode      The Dead Band counter clock mode
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDeadBandCounterClock(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_DeadBandClockModeType, AUTOMATIC) ClockMode);

/** \brief Set EPWM RED count
 *
 * This function sets the RED (Rising Edge Delay) count value
 * The value of redCount should be less than 0x4000U.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] RedCount       The RED(Rising Edge Delay) count.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetRisingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) RedCount);

/** \brief Set EPWM FED count
 *
 * This function sets the FED (Falling Edge Delay) count value
 * The value of fedCount should be less than 0x4000U.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] FedCount       The FED(Falling Edge Delay) count.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetFallingEdgeDelayCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) FedCount);

/*
 * Chopper module related APIs
 */

/** \brief Enable/disable chopper mode
 *
 * This function Enable/disables EPWM chopper module
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Select         Enable/disable selection for chopper.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureChopper(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set chopper duty cycle
 *
 * This function sets the chopping clock duty cycle The value of
 * dutyCycleCount should be less than 7. The dutyCycleCount value is converted
 * to the actual chopper duty cycle value base on the following equation:
 *   chopper duty cycle = (dutyCycleCount + 1) / 8
 *
 * \param[in] InstanceId       Numeric ID of the requested PWM instance
 * \param[in] DutyCycleCount   The chopping clock duty cycle count.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetChopperDutyCycle(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) DutyCycleCount);

/** \brief Set chopper clock frequency scaler
 *
 * This function sets the scaler for the chopping clock frequency. The value
 * of freqDiv should be less than 8. The chopping clock frequency is altered
 * based on the following equation.
 *   chopper clock frequency = SYSCLKOUT / ( 1 + freqDiv)
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] FreqDiv        The chopping clock frequency divider.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetChopperFreq(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) FreqDiv);

/** \brief Set chopper first pulse width
 *
 * This function sets the first pulse width of chopper output waveform. The
 * value of firstPulseWidth should be less than 0x10U. The value of the first
 * pulse width in seconds is given using the following equation:
 *     first pulse width = 1 / (((firstPulseWidth + 1) * SYSCLKOUT)/8)
 *
 * \param[in] InstanceId        Numeric ID of the requested PWM instance
 * \param[in] FirstPulseWidth   The width of the first pulse
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetChopperFirstPulseWidth(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(uint16, AUTOMATIC) FirstPulseWidth);

/*
 * Trip Zone module related APIs
 */

/** \brief Enable/disables Trip Zone signal
 *
 * This function Enable/disables the Trip Zone signals specified by TzSignal as a
 * source for the Trip Zone module
 * Valid values for TzSignal are:
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
 * \note A logical OR of the valid values can be passed as the TzSignal parameter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] TzSignal       The Trip Zone signal.
 * \param[in] Select         Enable/disable selection for the signal.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZoneSignals(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_TzSignalType, AUTOMATIC) TzSignal, VAR(boolean, AUTOMATIC) Select);

FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZone2Signals(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                  VAR(Cdd_Pwm_TzCapEvtType, AUTOMATIC) TzSignal, VAR(boolean, AUTOMATIC) Select);

/** \brief Set Digital compare conditions that cause Trip Zone event
 *
 * This function sets up the Digital Compare output Trip Zone event sources.
 * The dcType variable specifies the event source to be whether Digital
 * Compare output A or Digital Compare output B. The dcEvent parameter
 * specifies the event that causes Trip Zone
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
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] DcType         Digital compare output type
 * \param[in] DcEvent        Digital Compare output event.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTripZoneDigitalCompareEventCondition(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                VAR(Cdd_Pwm_TripZoneDigitalCompareOutputType, AUTOMATIC) DcType,
                                                VAR(Cdd_Pwm_TripZoneDigitalCompareOutputEventType, AUTOMATIC) DcEvent);

/** \brief Enable/disable advanced Trip Zone event Action
 *
 * This function Enable/disables the advanced actions of the Trip Zone events. The
 * advanced features combine the trip zone events with the direction of the
 * counter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] Select         Enable/disable selection for advanced trip zone action.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set Trip Zone Action
 *
 * This function sets the Trip Zone Action to be taken when a Trip Zone event
 * occurs.
 * Valid values for the parameters are:
 *  - TzEvent
 *      - CDD_PWM_TZ_ACTION_EVENT_DCBEVT2  - DCBEVT2 (Digital Compare B event 2)
 *      - CDD_PWM_TZ_ACTION_EVENT_DCBEVT1  - DCBEVT1 (Digital Compare B event 1)
 *      - CDD_PWM_TZ_ACTION_EVENT_DCAEVT2  - DCAEVT2 (Digital Compare A event 2)
 *      - CDD_PWM_TZ_ACTION_EVENT_DCAEVT1  - DCAEVT1 (Digital Compare A event 1)
 *      - CDD_PWM_TZ_ACTION_EVENT_TZB      - TZ1 - TZ6U, DCBEVT2U, DCBEVT1
 *      - CDD_PWM_TZ_ACTION_EVENT_TZA      - TZ1 - TZ6U, DCAEVT2U, DCAEVT1
 *  - TzAction
 *      - CDD_PWM_TZ_ACTION_HIGH_Z         - high impedance output
 *      - CDD_PWM_TZ_ACTION_HIGH           - high output
 *      - CDD_PWM_TZ_ACTION_LOW            - low low
 *      - CDD_PWM_TZ_ACTION_DISABLE        - disable action
 *
 * \note Disable the advanced Trip Zone event using
 *       Cdd_Pwm_DisableTripZoneAdvAction() before calling this function.
 * \note This function operates on both EPWMA and EPWMB depending on the
 *       TzEvent parameter.
 *
 * \param[in] InstanceId     Numeric ID of the requested PWM instance
 * \param[in] TzEvent        The Trip Zone event type
 * \param[in] TzAction       The Trip zone Action.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTripZoneAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 * \note This function operates on both EPWMA and EPWMB depending on the TzAdvEvent parameter.
 * \note Advanced Trip Zone events take into consideration the direction of the counter in addition to Trip Zone events.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTripZoneAdvAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_TripZoneAdvancedEventType, AUTOMATIC) TzAdvEvent,
                             VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvAction);

/** \brief Set Advanced Digital Compare Trip Zone Action on EPWMA
 *
 * This function sets the Digital Compare (DC) Advanced Trip Zone Action to be
 * taken on EPWMA when an advanced Digital Compare Trip Zone A event occurs.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel  The EPWM output channel
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
 * \note Advanced Trip Zone events take into consideration the direction of the counter in addition to
 *          Digital Compare Trip Zone events.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetTripZoneAdvDigitalCompareAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                           VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                           VAR(Cdd_Pwm_TripZoneAdvDigitalCompareEventType, AUTOMATIC) TzAdvDCEvent,
                                           VAR(Cdd_Pwm_TripZoneAdvancedActionType, AUTOMATIC) TzAdvDCAction);

/** \brief Enable/disable Trip Zone interrupts
 *
 * This function Enable/disables the Trip Zone interrupts.
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
Cdd_Pwm_ConfigureTripZoneInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_TzInterruptSourceType, AUTOMATIC) TzInterrupt,
                                   VAR(boolean, AUTOMATIC) Select);

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
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetCycleByCycleTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetOneShotTripZoneFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set the Trip Zone CBC pulse clear event
 *
 * This function set the event which automatically clears the CBC (Cycle by Cycle) latch.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] ClearEvent    CBC trip zone clear event with valid values:
 *                          - CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_ZERO         - Clear CBC pulse when counter equals zero
 *                          - CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_PERIOD       - Clear CBC pulse when counter equals period
 *                          - CDD_PWM_TZ_CBC_PULSE_CLR_CNTR_ZERO_PERIOD  - Clear CBC pulse when counter equals zero or
 *period
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectCycleByCycleTripZoneClearEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_ClearTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                          VAR(Cdd_Pwm_TripZoneFlagType, AUTOMATIC) TzFlags);

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
Cdd_Pwm_ClearCycleByCycleTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_CbcTzFlagType, AUTOMATIC) TzCbcFlags);

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
Cdd_Pwm_ClearOneShotTripZoneFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_OneshotTzFlagType, AUTOMATIC) TzOSTFlags);

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
Cdd_Pwm_ForceTripZoneEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_TripZoneForceEventType, AUTOMATIC) TzForceEvent);

/** \brief Select TRIPOUT signals for the EPWM module
 *
 * This function selects the TRIPOUT signals for the EPWM module
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
Cdd_Pwm_ConfigureTripOutSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_SelectTripOutSourceType, AUTOMATIC) TzTripOut,
                               VAR(boolean, AUTOMATIC) Select);

/*
 * Event Trigger related APIs
 */

/** \brief Enable/disable EPWM interrupt
 *
 * This function Enable/disables the EPWM interrupt.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Sets the EPWM interrupt source
 *
 * This function sets the EPWM interrupt source
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] InterruptSource  EPWM interrupt source with valid values:
 *                             - CDD_PWM_INT_TBCTR_DISABLED       - Time-base counter is disabled
 *                             - CDD_PWM_INT_TBCTR_ZERO           - Time-base counter equal to zero
 *                             - CDD_PWM_INT_TBCTR_PERIOD         - Time-base counter equal to period
 *                             - CDD_PWM_INT_TBCTR_ZERO_OR_PERIOD - Time-base counter equal to zero or period
 *                             - CDD_PWM_INT_TBCTR_ETINTMIX       - Time-base counter based on mixed events (ETINTMIX)
 *                             - CDD_PWM_INT_TBCTR_U_CMPx         - Where x is AU,BU,C or D
 *                                                               Time-base counter equal to CMPAU, CMPBU,
 *                                                               CMPC or CMPD (depending the value of x)
 *                                                               when the timer is incrementing
 *                             - CDD_PWM_INT_TBCTR_D_CMPx         - Where x is AU,BU,C or D
 *                                                               Time-base counter equal to CMPAU, CMPBU,
 *                                                               CMPC or CMPD (depending the value of x)
 *                                                               when the timer is decrementing
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetInterruptSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_InterruptSourceType, AUTOMATIC) InterruptSource);

/** \brief Return the interrupt status
 *
 * This function returns the EPWM interrupt status.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \note This function doesn't return the Trip Zone status.
 * \return Returns true if EPWM interrupt was generated, false if no interrupt was generated
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_GetEventTriggerInterruptStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Clear interrupt flag
 *
 * This function clears the EPWM interrupt flag.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearEventTriggerInterruptFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable/disable Pre-interrupt count load
 *
 * This function Enable/disables the EPWM interrupt counter to be pre-interrupt loaded with a count value
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
Cdd_Pwm_ConfigureInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(boolean, AUTOMATIC) Select);

/** \brief Force a software pre interrupt event counter load
 *
 * This function forces the EPWM interrupt counter to be loaded with the
 * contents set by Cdd_Pwm_SetPreInterruptEventCount().
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \note Make sure the Cdd_Pwm_EnablePreInterruptEventCountLoad() function is called before invoking this function.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceInterruptEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set interrupt count
 *
 * This function sets the EPWM interrupt count. eventCount is the value of the
 * pre-interrupt value that is to be loaded. The maximum value of eventCount
 * is 15.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] EventCount    The EPWM interrupt count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetInterruptEventCountInitValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(uint16, AUTOMATIC) EventCount);

/** \brief Get the interrupt count
 *
 * This function returns the EPWM interrupt event count.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The interrupt event counts that have occurred
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetInterruptEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Force EPWM interrupt
 *
 * This function forces an EPWM interrupt.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceEventTriggerInterrupt(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Sets the mixed event trigger interrupt source
 *
 * This function sets the EPWM interrupt source
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
Cdd_Pwm_SetMixEvtTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_EtMixSignalSelectType, AUTOMATIC) EtMixSignal,
                               VAR(Cdd_Pwm_EvtMixTriggerSourceType, AUTOMATIC) InterruptSource);

/*
 * Adc SOC configuration related APIs
 */

/** \brief Enable/disable Adc SOC event
 *
 * This function Enable/disables the EPWM module to trigger an Adc SOC event.
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
Cdd_Pwm_ConfigureAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                            VAR(boolean, AUTOMATIC) Select);

/** \brief Sets the EPWM SOC source
 *
 * This function sets the EPWM Adc SOC source
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
Cdd_Pwm_SetAdcTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                            VAR(Cdd_Pwm_AdcStartOfConversionSourceType, AUTOMATIC) SocSource);

/** \brief Sets the EPWM SOC event counts
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
Cdd_Pwm_SetAdcTriggerEventPrescale(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                   VAR(uint16, AUTOMATIC) PreScaleCount);

/** \brief Return the SOC event status
 *
 * This function returns the EPWM SOC status.
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
Cdd_Pwm_GetAdcTriggerFlagStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/** \brief Clear SOC flag
 *
 * This function clears the EPWM SOC flag.
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
Cdd_Pwm_ClearAdcTriggerFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/** \brief Enable/disable Pre-SOC event count load
 *
 * This function Enable/disables the EPWM SOC event counter which is set by the
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
Cdd_Pwm_ConfigureAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                          VAR(boolean, AUTOMATIC) Select);

/** \brief Force a software pre SOC event counter load
 *
 * This function forces the EPWM SOC counter to be loaded with the
 * contents set by Cdd_Pwm_SetPreAdcStartOfConversionEventCount().
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 * \pre None
 * \post None
 * \note Make sure the Cdd_Pwm_EnableAdcTriggerEventCountInit() function is called before invoking this function.
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ForceAdcTriggerEventCountInit(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/** \brief Set Adc Trigger count values
 *
 * This function sets the EPWM Adc Trigger count values.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] AdcSocType    The Adc SOC type
 *                          - CDD_PWM_SOC_A - SOC A
 *                          - CDD_PWM_SOC_B - SOC B
 * \param[in] EventCount    The EPWM interrupt count value (maximum value is 15)
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetAdcTriggerEventCountInitValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType,
                                         VAR(uint16, AUTOMATIC) EventCount);

/** \brief Get the SOC event count
 *
 * This function returns the EPWM SOC event count.
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
Cdd_Pwm_GetAdcTriggerEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_AdcStartOfConversionType, AUTOMATIC) AdcSocType);

/** \brief Force SOC event
 *
 * This function forces an EPWM SOC event.
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
Cdd_Pwm_ForceAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 *                            is enabled by the CDD_PWM_enableDigitalCompareTripCombinationInput() function
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
Cdd_Pwm_SelectDigitalCompareTripInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_DigitalCompareTripInputType, AUTOMATIC) TripInput,
                                      VAR(Cdd_Pwm_DigitalCompareType, AUTOMATIC) DcType);

/** \brief Enable/disable DC filter blanking window
 *
 * This function Enable/disables the DC filter blanking window.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select        Enable/Disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareBlankingWindow(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(boolean, AUTOMATIC) Select);

/** \brief Enable/disable Digital Compare Window inverse mode
 *
 * This function Enable/disables the Digital Compare Window inverse mode This will
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
Cdd_Pwm_ConfigureDigitalCompareWindowInverseMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetDigitalCompareBlankingEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       Cdd_Pwm_DigitalCompareBlankingPulseType BlankingPulse);

/** \brief Set up the Digital Compare filter input
 *
 * This function sets the signal input source that will be filtered by the
 * Digital Compare module
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
Cdd_Pwm_SetDigitalCompareFilterInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_DigitalCompareFilterInputType, AUTOMATIC) FilterInput);

/*
 * DC Edge Filter
 */
/** \brief Enable/disable Digital Compare Edge Filter
 *
 * This function Enable/disables the Digital Compare Edge filter to generate event
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
Cdd_Pwm_ConfigureDigitalCompareEdgeFilter(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(boolean, AUTOMATIC) Select);

/** \brief Set the Digital Compare Edge Filter Mode
 *
 * This function sets the Digital Compare Event filter mode
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
Cdd_Pwm_SetDigitalCompareEdgeFilterMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_GetDigitalCompareEdgeFilterEdgeCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
Cdd_Pwm_GetDigitalCompareEdgeFilterEdgeStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set up the Digital Compare filter window offset
 *
 * This function sets the offset between window start pulse and blanking
 * window in TBCLK count. The function takes a 16bit count value for the offset value
 *
 * \param[in] InstanceId            Numeric ID of the requested PWM instance
 * \param[in] WindowOffsetCount     Blanking window offset length
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetDigitalCompareWindowOffset(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetDigitalCompareWindowLength(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_GetDigitalCompareBlankingWindowOffsetCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
Cdd_Pwm_GetDigitalCompareBlankingWindowLengthCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
Cdd_Pwm_SetDigitalCompareEventSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetDigitalCompareEventSyncMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                       VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                       VAR(Cdd_Pwm_DigitalCompareSyncModeType, AUTOMATIC) SyncMode);

/** \brief Enable/disable Digital Compare to generate Start of Conversion
 *
 * This function Enable/disables the Digital Compare Event 1 to generate Start of Conversion.
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
Cdd_Pwm_ConfigureDigitalCompareAdcTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                          VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                          VAR(boolean, AUTOMATIC) Select);

/** \brief Enable/disable Digital Compare to generate sync out pulse
 *
 * This function Enable/disables the Digital Compare Event 1 to generate sync out pulse
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
Cdd_Pwm_ConfigureDigitalCompareSyncEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                         VAR(boolean, AUTOMATIC) Select);

/** \brief Set up the Digital Compare CBC latch mode
 *
 * This function sets up the Digital Compare CBC latch mode
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
Cdd_Pwm_SetDigitalCompareCBCLatchMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 *                                                          DC CBC latch is cleared when counter is equal to period
 *                       - CDD_PWM_DC_CBC_LATCH_CLR_ON_CNTR_ZERO_PERIOD:
 *                                              DC CBC latch is cleared when either counter is zero or equal to period
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectDigitalCompareCBCLatchClearEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                               VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent,
                                               VAR(Cdd_Pwm_DigitalCompareCBCLatchClearEventType, AUTOMATIC) ClearEvent);

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
Cdd_Pwm_GetDigitalCompareCBCLatchStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                        VAR(Cdd_Pwm_DigitalCompareEventType, AUTOMATIC) DcEvent);

/*
 * DC capture mode
 */
/** \brief Enable/disables the Time Base Counter Capture controller
 *
 * This function Enable/disables the time Base Counter Capture
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDigitalCompareCounterCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetDigitalCompareCounterShadowMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
FUNC(boolean, CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareCaptureStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Configures DC capture operating mode
 *
 * This function is used to configure the DC capture operating mode If
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
Cdd_Pwm_ConfigureDigitalCompareCounterCaptureMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearDigitalCompareCaptureStatusFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Return the DC Time Base Counter capture value
 *
 * This function returns the DC Time Base Counter capture value The value
 * read is determined by the mode as set in the
 * Cdd_Pwm_SetTimeBaseCounterReadMode() function.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return DC Time Base Counter Capture count value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetDigitalCompareCaptureCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable/disable DC TRIP combinational input
 *
 * This function Enable/disables the specified Trip input.
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
Cdd_Pwm_ConfigureDigitalCompareTripCombinationInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                    VAR(Cdd_Pwm_DcTripInputType, AUTOMATIC) TripInput,
                                                    VAR(Cdd_Pwm_DigitalCompareType, AUTOMATIC) DcType,
                                                    VAR(boolean, AUTOMATIC) Select);
/*
 * Event capture mode
 */

/** \brief Enable/disables the Capture event
 *
 * This function Enable/disables the CAPIN.sync on which the edge detection logic
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
Cdd_Pwm_ConfigureCaptureInEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Polarity selection for capture gate input
 *
 * This function selects the input polarity for capture gate
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
Cdd_Pwm_ConfigCaptureGateInputPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                       VAR(Cdd_Pwm_SelectCaptureGateInputPolarityType, AUTOMATIC) PolaritySelect);

/** \brief Polarity selection for capture input
 *
 * This function selects the input polarity for capture
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
Cdd_Pwm_InvertCaptureInputPolarity(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_SelectCaptureInputPolarityType, AUTOMATIC) PolaritySelect);

/** \brief Enable/disables independent pulse selection for Blanking and Capture Logic
 *
 * This function Enable/disables pulse selection determined by the CAPMIXSEL register.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureIndependentPulseLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

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
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceCaptureEventLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set the capture trip input
 *
 * This function sets the trip input to the Digital Compare (DC). For a given
 * dcType The function sets the tripSource to be the input to the DC.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TripInput Trip source
 *                     - CDD_PWM_DC_TRIP_TRIPINx: Trip x, where x ranges from 1 to 15 excluding 13U
 *                     - CDD_PWM_DC_TRIP_COMBINATION: selects all the Trip signals whose input
 *                                                  is enabled by the CDD_PWM_enableCaptureTripCombinationInput()
 *function
 * \param[in] DcType Digital Compare type
 *                  - CDD_PWM_CAPTURE_GATE
 *                  - CDD_PWM_CAPTURE_INPUT
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SelectCaptureTripInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_DigitalCompareTripInputType, AUTOMATIC) TripInput,
                               VAR(Cdd_Pwm_CaptureInputType, AUTOMATIC) DcType);

/** \brief Enable/disable Capture TRIP combinational input
 *
 * This function Enable/disables the specified Trip input.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TripInput Trip number. Valid values:
 *                     - CDD_PWM_DC_COMBINATIONAL_TRIPINx, where x is 1U,2U,...12U,14U,15
 * \param[in] DcType Digital Compare module Valid values:
 *                  - CDD_PWM_CAPTURE_GATE
 *                  - CDD_PWM_CAPTURE_INPUT
 * \param[in] Select Boolean to enable/disable the trip input
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureCaptureTripCombinationInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_DcTripInputType, AUTOMATIC) TripInput,
                                             VAR(Cdd_Pwm_CaptureInputType, AUTOMATIC) DcType,
                                             VAR(boolean, AUTOMATIC) Select);
/** \brief Valley switching
 *********************************************************************************************************************/

/** \brief Enable/disable valley capture mode
 *
 * This function Enable/disables Valley Capture mode
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable valley capture mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureValleyCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Start valley capture mode
 *
 * This function starts Valley Capture sequence
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre Make sure you invoke Cdd_Pwm_SetValleyTriggerSource with the trigger
 *      variable set to CDD_PWM_VALLEY_TRIGGER_EVENT_SOFTWARE before calling this
 *      function.
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_StartValleyCapture(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Set valley capture trigger
 *
 * This function sets the trigger value that initiates Valley Capture sequence
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
Cdd_Pwm_SetValleyTriggerSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetValleyTriggerEdgeCounts(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) StartCount,
                                   VAR(uint16, AUTOMATIC) StopCount);

/** \brief Enable/disable valley switching delay
 *
 * This function Enable/disables Valley switching delay.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable valley switching delay
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureValleyHwDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set Valley delay values
 *
 * This function sets the Valley delay value
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] DelayOffsetValue Software defined delay offset value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetValleySwDelayValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) DelayOffsetValue);

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
Cdd_Pwm_SetValleyDelayDivider(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_ValleyDelayModeType, AUTOMATIC) DelayMode);

/** \brief Get the valley edge status bit
 *
 * This function returns the status of the start or stop valley status
 * depending on the value of edge
 * If a start or stop edge has occurred, the function returns true, if not it
 * returns false
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
Cdd_Pwm_GetValleyEdgeStatus(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetValleyCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetValleyHwDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable/disable Global shadow load mode
 *
 * This function Enable/disables Global shadow to active load mode of registers.
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
Cdd_Pwm_ConfigureGlobalLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set Global load trigger
 *
 * This function configures the global load trigger for the specified PWM instance
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] LoadTrigger   Global load trigger source
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetGlobalLoadTrigger(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetGlobalLoadEventPrescale(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_GetGlobalLoadEventCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable/disable One shot global shadow to active load
 *
 * This function Enable/disables a one time global shadow to active load. Register
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
Cdd_Pwm_ConfigureGlobalLoadOneShotMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

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
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_SetGlobalLoadOneShotLatch(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Force a software One shot global shadow to active load pulse
 *
 * This function forces a software a one time global shadow to active load
 * pulse
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceGlobalLoadOneShotEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable/disable a register to be loaded Globally
 *
 * This function Enable/disables the register specified by loadRegister to be globally
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
Cdd_Pwm_ConfigureGlobalLoadRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_GlobalLoadType, AUTOMATIC) LoadRegister,
                                     VAR(boolean, AUTOMATIC) Select);

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
Cdd_Pwm_LockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                      VAR(Cdd_Pwm_LockRegisterGroupType, AUTOMATIC) RegisterGroup);

/** \brief XCMP related APIs
 */

/** \brief Enable/disable EPWM XCMP mode
 *
 * This function Enable/disables the EPWM XCMP mode
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable XCMP mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureXCmpMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Enable/disable EPWM XCMP Split
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
Cdd_Pwm_ConfigureSplitXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

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
Cdd_Pwm_AllocAXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_AllocBXCmp(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                   VAR(Cdd_Pwm_XCmp_AllocCmpBType, AUTOMATIC) Alloctype);

/** \brief Writes values to XCMP registers
 *
 * This function writes xcmpvalue to XCMP registers.
 * Valid values for xcmpReg are:
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
Cdd_Pwm_SetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg,
                        VAR(uint16, AUTOMATIC) XCmpValue);

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
Cdd_Pwm_SetCmpShadowRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetXMinMaxRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_XMinMaxRegType, AUTOMATIC) XMinMaxReg, VAR(uint16, AUTOMATIC) XCmpValue);

/** \brief Set up Action qualifier outputs based on XAQ registers
 *
 * This function sets up the Action Qualifier output on EPWM A or EPWMBU,
 * depending on the value of EpwmOutput, to a value specified by outPut based
 * on the input events - specified by event.
 * The following are valid values for the parameters.
 *   - EpwmOutput
 *       - CDD_PWM_AQ_OUTPUT_A          - EPWMxA output
 *       - CDD_PWM_AQ_OUTPUT_B          - EPWMxB output
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
 * \param[in] OutputChannel EPWM pin type
 * \param[in] ShadowSet Shadow set number or active set
 * \param[in] Output Action Qualifier output
 * \param[in] Event Event that causes a change in output
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_SetXCmpActionQualifierAction(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) ShadowSet,
                                     VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                     VAR(Cdd_Pwm_ActionQualifierOutputType, AUTOMATIC) Output,
                                     VAR(Cdd_Pwm_XCmpAqOutputEventType, AUTOMATIC) Event);

/** \brief Enables EPWM XCMP reload event
 *
 * This function enables the EPWM XCMP reload event.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_EnableXLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Forces register loading from shadow buffers
 *
 * This function is used for software force loading of the events in
 * global load mode
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceXLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
Cdd_Pwm_SetXCmpLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(Cdd_Pwm_XCmpLoadModeType, AUTOMATIC) Mode);

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
Cdd_Pwm_SetXCmpShadowLevel(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetXCmpShadowBufPtrLoadOnce(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetXCmpShadowRepeatBufxCount(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                     VAR(Cdd_Pwm_XCmpShadowSetType, AUTOMATIC) Bufferset, VAR(uint32, AUTOMATIC) Count);

/** \brief Minimum Dead Band Module related APIs
 */

/** \brief Enable/disable Minimum DeadBand module
 *
 * This function Enable/disables the Minimum DeadBand module
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDBCFG_ENABLEA   - EPWM output A
 *      - CDD_PWM_MINDBCFG_ENABLEB   - EPWM output B
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
Cdd_Pwm_ConfigureMinimumDeadBand(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                 VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                 VAR(boolean, AUTOMATIC) Select);

/** \brief Invert the Minimum DeadBand Reference Signal
 *
 * This function configures the Minimum DeadBand module to invert reference
 * signal which is used in the Minimum DeadBand module
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
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
Cdd_Pwm_InvertMinimumDeadBandSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                    VAR(boolean, AUTOMATIC) Invert);

/** \brief Select signal for AND OR logic of Minimum DeadBand Module
 *
 * This function configures how the signal will be combined with the
 * PWM output. The signal can be inverted and ANDed with PWM output or it can
 * be ORed with the PWM output.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
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
Cdd_Pwm_SelectMinimumDeadBandAndOrLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                        VAR(boolean, AUTOMATIC) Logic);

/** \brief Select Minimum DeadBand Blocking Signal
 *
 * This function configures the blocking signal for Minimum DeadBand module
 * Either of the Block A or Block B signal can be selected as blocking signal.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
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
Cdd_Pwm_SelectMinimumDeadBandBlockingSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                            VAR(boolean, AUTOMATIC) BlockingSignal);

/** \brief Select Minimum DeadBand Reference Signal
 *
 * This function selects the reference signal for Minimum DeadBand module
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
 *  - reference
 *      - CDD_PWM_MINDB_DEPWM             - Minimum Dead Band DE reference
 *      - CDD_PWM_MINDB_SEL_OUTXBAR_OUTy  - Output y from PWM Output XBAR
 *                                       ('y' can be from 1 to 15)
 *                                       ex. \b CDD_PWM_MINDB_SEL_OUTXBAR_OUT1
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
Cdd_Pwm_SelectMinimumDeadBandReferenceSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                             VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                             VAR(Cdd_Pwm_MindbReferenceSignalType, AUTOMATIC) ReferenceSignal);

/** \brief Get Minimum DeadBand Delay Value
 *
 * This function returns the delay value for the Minimum DeadBand module
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputChannel Minimum DeadBand block whose value is needed
 * \pre None
 * \post None
 * \return Delay value of the Minimum DeadBand module
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE)
Cdd_Pwm_GetMinDeadBandDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                            VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/** \brief Set the Minimum DeadBand Delay Value
 *
 * This function configures the Minimum DeadBand delay value for the
 * specified block.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
 *  - delay: Minimum dead band delay on EPWM in terms of SYSCLK cycles
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
Cdd_Pwm_SetMinimumDeadBandDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel, VAR(uint16, AUTOMATIC) Delay);

/** \brief Illegal Combo Logic
 *
 *********************************************************************************************************************/

/** \brief Enable/disable Illegal Combo Logic
 *
 * This function Enable/disables the Illegal Combo Logic block.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
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
Cdd_Pwm_ConfigureIllegalComboLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                   VAR(boolean, AUTOMATIC) Select);

/** \brief Select XBAR input for Illegal Combo Logic
 *
 * This function selects which Xbar signal feeds into the Illegal Combo Logic.
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
 *  - xbarInput
 *      - CDD_PWM_MINDB_ICL_XBAR_OUTy - Output y from ICL XBAR
 *                                    ('y' can be from 0 to 15)
 *                                    ex. \b CDD_PWM_MINDB_ICL_XBAR_OUT1
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
Cdd_Pwm_SelectXbarInput(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                        VAR(Cdd_Pwm_XbarInputType, AUTOMATIC) XbarInput);

/** \brief Force Decx values
 *
 * This function programs value in the Decx register fields of the Illegal
 * Combo Logic module
 * Valid values for the input variables are:
 *  - block
 *      - CDD_PWM_MINDB_BLOCK_A    - EPWM output A
 *      - CDD_PWM_MINDB_BLOCK_B    - EPWM output B
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
Cdd_Pwm_SetLutDecX(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                   VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel, VAR(Cdd_Pwm_LutDecXType, AUTOMATIC) Decx,
                   VAR(boolean, AUTOMATIC) Force);

/** \brief Diode Emulation logic related APIs
 *
 *********************************************************************************************************************/

/** \brief Enable/disable EPWM diode emulation mode
 *
 * This function Enable/disables the EPWM diode emulation mode
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection for diode emulation mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

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
Cdd_Pwm_SetDiodeEmulationMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                              VAR(Cdd_Pwm_DiodeEmulationModeType, AUTOMATIC) Mode);

/** \brief Set EPWM diode emulation re-entry delay
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
Cdd_Pwm_SetDiodeEmulationReentryDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint8, AUTOMATIC) Delay);

/** \brief Set EPWM diode emulation trip source for TripL
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
Cdd_Pwm_ConfigureDiodeEmulationTripLowSources(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_DETripLowSourceType, AUTOMATIC) Source);

/** \brief Set EPWM diode emulation trip source for TripH
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
Cdd_Pwm_ConfigureDiodeEmulationTripHighSources(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                               VAR(Cdd_Pwm_DETripHighSourceType, AUTOMATIC) Source);

/** \brief Selects EPWM diode emulation pwm signal
 *
 * This function is used to select the pwm signal in DE mode
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
Cdd_Pwm_SelectDiodeEmulationPwmSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                      VAR(Cdd_Pwm_DiodeEmulationSignalType, AUTOMATIC) DiodeEmuationsignal);

/** \brief Selects between TRIPH and TRIPL for an epwm channel in DE mode
 *
 * This function is used to select between TRIPH and TRIPL
 * for a channel in DE mode
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
Cdd_Pwm_SelectDiodeEmulationTripSignal(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_NoBypassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ByPassDiodeEmulationLogic(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ForceDiodeEmulationActive(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Enable/disables DE monitor control mode
 *
 * This function is used to Enable/disable the DE monitor counter function.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Enable/disable selection for DE monitor mode
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_ConfigureDiodeEmulationMonitorModeControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                                  VAR(boolean, AUTOMATIC) Select);

/** \brief Sets the DE monitor counter step size
 *
 * This function is used to set the DE monitor counter step size
 * Valid values for \e direction are:
 *    CDD_PWM_DE_COUNT_UP     - Diode emulation count up step size
 *    CDD_PWM_DE_COUNT_DOWN   - Diode emulation count down step size
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
Cdd_Pwm_SetDiodeEmulationMonitorModeStep(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_SetDiodeEmulationMonitorCounterThreshold(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
FUNC(void, CDD_PWM_CODE) Cdd_Pwm_ClearDiodeEmulationActiveFlag(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/*
 * HRPWM related APIs
 */

/** \brief Sets the consolidated phase shift value in high resolution mode
 *
 * This function sets the consolidated phase shift value, that is, both TBPHS
 * and TBPHSHR values are configured together.
 *
 * Call Cdd_Pwm_EnablePhaseShiftLoad & HRPWM_enableHRPhaseShiftLoad() functions
 * to enable loading of the phaseCount in high resolution mode
 *
 * \b Note: phaseCount is a 24-bit value
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
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetPhaseShift(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) PhaseCount);

/** \brief Sets only the high resolution phase shift value
 *
 * This function sets only the high resolution phase shift(TBPHSHR) value
 * Call the HRPWM_enableHRPhaseShiftLoad() function to enable loading of
 * the hrPhaseCount.
 *
 * \b Note: hrPhaseCount is an 8-bit value
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] HrPhaseCount High resolution phase shift count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResPhaseShiftOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                    VAR(uint16, AUTOMATIC) HrPhaseCount);

/** \brief Sets the consolidated period of time base counter used in HR mode
 *
 * This function sets the consolidated period of time base counter value
 * (TBPRD:TBPRDHR) required in high resolution mode
 *
 * User should map the desired period or frequency of the waveform into
 * the correct periodCount.
 *
 * \b Note: periodCount is a 24 bit value
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
Cdd_Pwm_HrpwmSetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) PeriodCount);

/** \brief Sets only the high resolution time base counter
 *
 * This function sets only the high resolution time base counter(TBPRDHR)
 * value
 *
 * User should map the desired period or frequency of the waveform into
 * the correct hrPeriodCount.
 *
 * \b Note: hrPeriodCount is an 8-bit value
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] HrPeriodCount High resolution period count value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(uint16, AUTOMATIC) HrPeriodCount);

/** \brief Gets the consolidated time base period count used in HR mode
 *
 * This function gets the consolidated time base period(TBPRD:TBPRDHR) value
 * used in high resolution mode
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The consolidated time base period count value
 *
 *********************************************************************************************************************/
FUNC(uint32, CDD_PWM_CODE) Cdd_Pwm_HrpwmGetTimeBasePeriod(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

/** \brief Gets only the high resolution time base period count
 *
 * This function gets only the high resolution time base period(TBPRDHR) value
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \pre None
 * \post None
 * \return The high resolution time base period count value
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_PWM_CODE) Cdd_Pwm_HrpwmGetHiResTimeBasePeriodOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId);

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
 *                                                 controls rising edge
 *      - HRPWM_MEP_CTRL_FALLING_EDGE            - MEP (Micro Edge Positioner)
 *                                                 controls falling edge
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
Cdd_Pwm_HrpwmSetMepEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_HrpwmSetMepControlMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                               VAR(Cdd_Pwm_HrpwmMepCtrlModeType, AUTOMATIC) MepCtrlMode);

/** \brief Sets the high resolution comparator load mode
 *
 * This function sets the shadow load mode of the high resolution comparator.
 * The function sets the COMPA or COMPB register depending on the OutputChannel
 * variable
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
Cdd_Pwm_HrpwmSetCounterCompareShadowLoadEvent(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                              VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel,
                                              VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent);

/** \brief Sets the high resolution output swap mode
 *
 * This function sets the HRPWM output swap mode If EnableOutputSwap is true,
 * EPWMxA signal appears on EPWMxB output and EPWMxB signal appears on EPWMxA
 * output. If it is false EPWMxA and EPWMxB outputs are unchanged.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] EnableOutputSwap The output swap flag
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetOutputSwapMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                               VAR(boolean, AUTOMATIC) EnableOutputSwap);

/** \brief Sets the high resolution output on EPWMxB
 *
 * This function sets the HRPWM output signal on EPWMxB. If OutputOnB is
 * HRPWM_OUTPUT_ON_B_INV_A, EPWMxB output is an inverted version of
 * EPWMxA. If OutputOnB is HRPWM_OUTPUT_ON_B_NORMAL, EPWMxB output is
 * EPWMxB.
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] OutputOnB The output signal on EPWMxB
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetChannelBOutputPath(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                   VAR(Cdd_Pwm_HrpwmChannelBOutputType, AUTOMATIC) OutputOnB);

/** \brief Enables MEP (Micro Edge Positioner) automatic scale mode
 *
 * This function enables the MEP (Micro Edge Positioner) to automatically
 * scale HRMSTEP.
 *
 * The SFO library will calculate required MEP steps per coarse steps and
 * feed it to HRMSTEP register. The MEP calibration module will use the value
 * in HRMSTEP to determine appropriate number of MEP steps represented by
 * fractional duty cycle
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable automatic conversion
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmConfigureAutoConversion(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Enable high resolution period feature
 *
 * This function enables the high resolution period feature
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] Select Boolean to enable/disable period control
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmConfigurePeriodControl(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

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
Cdd_Pwm_HrpwmConfigurePhaseShiftLoad(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(boolean, AUTOMATIC) Select);

/** \brief Set high resolution PWMSYNC source
 *
 * This function sets the high resolution PWMSYNC pulse source
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
Cdd_Pwm_HrpwmSetSyncPulseSource(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                VAR(Cdd_Pwm_HrpwmSyncPulseSourceType, AUTOMATIC) SyncPulseSource);

/** \brief Sets the Translator Remainder value
 *
 * This function sets the Translator Remainder value
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] TrRemVal The translator remainder value
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetTranslatorRemainder(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) TrRemVal);

/** \brief Sets the consolidated counter compare values in HR mode
 *
 * This function sets the consolidated counter compare(CMPx:CMPxHR) value
 * required in high resolution mode for counter compare registers.
 * Valid values for OutputChannel are:
 *  - HRPWM_COUNTER_COMPARE_A - counter compare A.
 *  - HRPWM_COUNTER_COMPARE_B - counter compare B.
 *
 * \b Note: CompareCount is a 24 bit value
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
Cdd_Pwm_HrpwmSetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 * \b Note: HrCompCount is an 8-bit value
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
Cdd_Pwm_HrpwmSetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
 * \param[in] OutputChannel EPWM output channel
 * \pre None
 * \post None
 * \return The consolidated counter compare value
 *
 *********************************************************************************************************************/
FUNC(uint32, CDD_PWM_CODE)
Cdd_Pwm_HrpwmGetCounterCompareValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_GetHiResCounterCompareValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_OutputChannelType, AUTOMATIC) OutputChannel);

/** \brief Sets the consolidated RED count in high resolution mode
 *
 * This function sets the consolidated RED (Rising Edge Delay) count
 * (DBRED:DBREDHR) value used in high resolution mode The value of
 * RedCount should be less than 0x200000.
 *
 * \b Note: RedCount is a 21 bit value
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
Cdd_Pwm_HrpwmSetRisingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) RedCount);

/** \brief Sets the high resolution RED count only
 *
 * This function sets only the high resolution RED (Rising Edge Delay)
 * count(DBREDHR) value
 * The value of HrRedCount should be less than 128.
 *
 * \b Note: HrRedCount is a 7-bit value
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] HrRedCount The high resolution RED count
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResRisingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                         VAR(uint16, AUTOMATIC) HrRedCount);

/** \brief Sets the consolidated FED value in high resolution mode
 *
 * This function sets the consolidated FED (Falling Edge Delay) count
 * (DBFED: DBFEDHR) value used in high resolution mode The value of FedCount
 * should be less than 0x200000.
 *
 * \b Note: FedCount is a 21 bit value
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
Cdd_Pwm_HrpwmSetFallingEdgeDelay(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId, VAR(uint32, AUTOMATIC) FedCount);

/** \brief Sets the high resolution FED count only
 *
 * This function sets only the high resolution FED (Falling Edge Delay)
 * count(DBREDHR) value
 * The value of HrRedCount should be less than 128.
 *
 * \b Note: HrRedCount is a 7-bit value
 *
 * \param[in] InstanceId    Numeric ID of the requested PWM instance
 * \param[in] HrFedCount The high resolution RED count
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_PWM_CODE)
Cdd_Pwm_HrpwmSetHiResFallingEdgeDelayOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_HrpwmSetMepStep(VAR(Cdd_Pwm_HrpwmCalInstanceType, AUTOMATIC) InstanceId, VAR(uint16, AUTOMATIC) MepCount);

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
Cdd_Pwm_HrpwmSetDeadbandMepEdgeSelect(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_HrpwmMepDeadBandEdgeModeType, AUTOMATIC) MepDbEdge);

/** \brief Set the high resolution Dead Band RED load mode
 *
 * This function sets the high resolution Rising Edge Delay(RED)Dead Band
 * count load mode
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
Cdd_Pwm_HrpwmSetRisingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                        VAR(Cdd_Pwm_HrpwmLoadModeType, AUTOMATIC) LoadEvent);

/** \brief Set the high resolution Dead Band FED load mode
 *
 * This function sets the high resolution Falling Edge Delay(FED) Dead Band
 * count load mode
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
Cdd_Pwm_HrpwmSetFallingEdgeDelayLoadMode(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
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
Cdd_Pwm_HrpwmLockRegisters(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                           VAR(Cdd_Pwm_HrpwmLockRegisterGroupType, AUTOMATIC) RegisterGroup);

/** \brief Sets the consolidated XCMP values in HR mode
 *
 * This function sets the consolidated counter compare(XCMPx:XCMPxHR) value
 * required in high resolution mode for XCMP registers.
 * Valid values for XCmpReg are:
 *    CDD_PWM_XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *                          -XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *    CDD_PWM_XTBPRD_ACTIVE                               -XTBPRD_ACTIVE
 *    CDD_PWM_XTBPRD_SHADOW1                              -XTBPRD_SHADOW1
 *    CDD_PWM_XTBPRD_SHADOW2                              -XTBPRD_SHADOW2
 *    CDD_PWM_XTBPRD_SHADOW3                              -XTBPRD_SHADOW3
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
Cdd_Pwm_HrpwmSetXCmpRegValue(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                             VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg, VAR(uint32, AUTOMATIC) XCmpValue);

/** \brief Sets only the high resolution XCMP value
 *
 * This function sets the high resolution counter compare value(XCMPx_HR) for
 * XCMP registers.
 * Valid values for XCmpReg are:
 *    CDD_PWM_XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *                          -XCMP[1-8]_[ACTIVE/SHADOW1/SHADOW2/SHADOW3]
 *    CDD_PWM_XTBPRD_ACTIVE                               -XTBPRD_ACTIVE
 *    CDD_PWM_XTBPRD_SHADOW1                              -XTBPRD_SHADOW1
 *    CDD_PWM_XTBPRD_SHADOW2                              -XTBPRD_SHADOW2
 *    CDD_PWM_XTBPRD_SHADOW3                              -XTBPRD_SHADOW3
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
Cdd_Pwm_HrpwmSetHiResXCmpRegValueOnly(VAR(Cdd_Pwm_InstanceType, AUTOMATIC) InstanceId,
                                      VAR(Cdd_Pwm_XCmpRegType, AUTOMATIC) XCmpReg, VAR(uint16, AUTOMATIC) HrXCmpValue);

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
FUNC(Cdd_Pwm_SfoStatusType, CDD_PWM_CODE) Cdd_Pwm_Sfo(VAR(Cdd_Pwm_HrpwmCalInstanceType, AUTOMATIC) Cdd_Pwm_HrpwmCalId);

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
#endif /* CDD_PWM_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Pwm.h
 *********************************************************************************************************************/
