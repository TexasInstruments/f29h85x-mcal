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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Sent_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *********************************************************************************************************************/
#ifndef CDD_SENT_CFG_H
#define CDD_SENT_CFG_H
/** \addtogroup CDD_SENT
 *  @{
 */
#ifdef __cplusplus
extern "C" {
#endif
[!SELECT "as:modconf('Cdd_Sent/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Sent/Cdd']"!]
#ifndef DOXYGEN_SHOULD_SKIP_THIS 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-28681
 */
 #include "Cdd_Sent_Cbk.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief CDDSENT Driver Configuration SW Version Info.*/
#define CDD_SENT_CFG_MAJOR_VERSION    ([!"substring-before($moduleSoftwareVer,'.')"!]U) //!< CDDSENT configuration Major Version.
#define CDD_SENT_CFG_MINOR_VERSION    ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U) //!< CDDSENT configuration Minor Version.
#define CDD_SENT_CFG_PATCH_VERSION    ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U) //!< CDDSENT configuration Patch Version.

/*
 *Design: MCAL-28714
 */
/** \brief CDDSENT Build Variant. Build Variants.(i.e Pre-compile,Post-Build or Link time)*/
#define CDD_SENT_CFG_PRE_COMPILE_VARIANT          [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define CDD_SENT_CFG_DEM_ENABLE    [!IF "node:refexists(CddSentDemEventParameterRefs/CDD_SENT_E_HARDWARE_ERROR)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/*
 *Design: MCAL-28684
 */
[!IF "node:refexists(CddSentDemEventParameterRefs/CDD_SENT_E_HARDWARE_ERROR)"!]
#define CDD_SENT_E_HARDWARE_ERROR  (DemConf_DemEventParameter_[!"node:name(node:ref(CddSentDemEventParameterRefs/CDD_SENT_E_HARDWARE_ERROR))"!])
[!ENDIF!]


/** \brief Enable/Disable DEV error detection.*/
/*
 *Design: MCAL-28662,MCAL-28661
 */
#define CDD_SENT_CFG_DEV_ERROR_DETECT             [!IF "CddSentGeneral/CddSentDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/** \brief Enable/Disable CddSent_GetVersionInfo().*/

/*
 *Design: MCAL-28663
 */
#define CDD_SENT_CFG_GET_VERSION_INFO_API         [!IF "CddSentGeneral/CddSentVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** \brief Enable/Disable Enable Pdu().*/

/*
 *Design: MCAL-28717
 */
#define CDD_SENT_INTEGRATION_WITH_ASR_COMSTACK_ENABLE      [!IF "CddSentGeneral/CddSentIntegrationWithAsrComStackEnable = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!VAR "Enable_MTP_Mode" = "0"!][!//
[!LOOP "CddSentConfig/CddSentController/*"!][!//
[!IF "CddSentMTP ='true'"!][!//
        [!VAR "Enable_MTP_Mode" = "1"!][!//
[!ENDIF!]
[!ENDLOOP!][!//

/** \brief Enable/Disable MTP Mode.*/
#define CDD_SENT_ENABLE_MTP_MODE [!IF "$Enable_MTP_Mode  ='1.0'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*
 *Design: MCAL-28685
 */
/** \brief Defines for symbolic names for the CddSent HW uint ID's (CddSentHWUnitId) */
[!LOOP "CddSentConfig/CddSentController/*"!][!//
#define Cdd_SentConf_CddSentController_[!"@name"!] ([!"CddSentHWUnitId"!]U) /*~ASR~*/
[!ENDLOOP!][!//

/*
 *Design: MCAL-28731
 */
[!IF "CddSentGeneral/CddSentIntegrationWithAsrComStackEnable = 'true'"!]
/** \brief Defines for symbolic names for the CddSentPduR Lower layer Rx PdU's */
[!LOOP "CddComStackContribution/CddPduRLowerLayerContribution/CddPduRLowerLayerRxPdu/*"!][!//
#define Cdd_SentConf_CddPduRLowerLayerRxPdu_[!"@name"!] [!"@index"!]U			/*~ASR~*/
[!ENDLOOP!][!//
[!ELSE!][!//
/** \brief Defines for symbolic names for the channelobjectid's */
[!LOOP "CddSentConfig/CddSentController/*/CddSentChannelObject/*"!][!//
#define Cdd_SentConf_CddSentChannelObject_[!"@name"!] [!"CddSentChannelObjectID"!]U			/*~ASR~*/
[!ENDLOOP!][!//
[!ENDIF!][!//
[!IF "CddSentGeneral/CddSentIntegrationWithAsrComStackEnable = 'true'"!]
/*
 *Design: MCAL-28733,MCAL-28687, MCAL-28686
 */
/** \brief Defines for symbolic names for the CddSentPduR Lower layer Tx PdU's */
[!LOOP "CddComStackContribution/CddPduRLowerLayerContribution/CddPduRLowerLayerTxPdu/*"!][!//
#define Cdd_SentConf_CddPduRLowerLayerTxPdu_[!"@name"!] [!"@index"!]U			/*~ASR~*/
[!ENDLOOP!][!//
[!ELSE!][!//
[!IF "$Enable_MTP_Mode  ='1.0'"!]
/*
*Design: MCAL-28733,MCAL-28687, MCAL-28686
*/
/** \brief Defines for symbolic names for the CddSentExternalDeviceID's */
[!LOOP "CddSentConfig/CddSentController/*/CddSentExternalDeviceConfig/*"!][!//
#define Cdd_SentConf_CddSentExternalDeviceConfig_[!"@name"!] [!"@index"!]U			/*~ASR~*/
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//

/*
 *Design: MCAL-28671
 */
/** \brief CddSent Controller Instance interrupt definition */
[!LOOP "CddSentConfig/CddSentController/*"!][!//
#define CDD_[!"node:value(node:ref(CddSentInstanceRef)/InstanceName)"!]_ENABLE
[!IF "CddSentInterruptType = 'CDD_SENT_ISR_CAT1_RTINT'"!][!//
#define CDD_[!"node:value(node:ref(CddSentInstanceRef)/InstanceName)"!]_ISR_CAT1_RTINT
[!ELSEIF "CddSentInterruptType = 'CDD_SENT_ISR_CAT1_INT'"!][!//
#define CDD_[!"node:value(node:ref(CddSentInstanceRef)/InstanceName)"!]_ISR_CAT1_INT
[!ELSE!][!//
#define CDD_[!"node:value(node:ref(CddSentInstanceRef)/InstanceName)"!]_ISR_CAT2
[!ENDIF!][!//
[!ENDLOOP!][!//

/*
 *Design: MCAL-28666
 */   
/** \brief Max number of HW units defined defined */
#define SENT_MAX_HW_UNITS                      (6U)

/*
 *Design: MCAL-28669
 */ 
/** \brief No. of HW units defined in CddSent Driver */
#define SENT_CFG_NO_OF_HW_UNITS            ([!"num:i(count(CddSentConfig/CddSentController/*))"!]U)

/** \brief Type for Hardware trigger Source */
/*
 *Design: MCAL-28649
 */
typedef enum
{
    /** \brief Disable trigger*/
    CDD_SENT_TRIGGER_DISABLE = 0U,
    /** \brief Broadcast done is the trigger source*/
    CDD_SENT_TRIGGER_BROADCAST_DONE = 1U,
    /** \brief sensor 1 done is the trigger source*/
    CDD_SENT_TRIGGER_SENSOR_1_DONE = 2U,
    /** \brief sensor 2 done is the trigger source*/
    CDD_SENT_TRIGGER_SENSOR_2_DONE = 3U,
    /** \brief sensor 3 done is the trigger source*/
    CDD_SENT_TRIGGER_SENSOR_3_DONE = 4U,
    /** \brief sensor 4 done is the trigger source*/
    CDD_SENT_TRIGGER_SENSOR_4_DONE = 5U,
    /** \brief CPU1_TINT0 is the trigger source*/
    CDD_SENT_TRIGGER_CPU1_TINT0 = 6U,
    /** \brief CPU1_TINT1 is the trigger source*/
    CDD_SENT_TRIGGER_CPU1_TINT1 = 7U,
    /** \brief CPU1_TINT2 is the trigger source*/
    CDD_SENT_TRIGGER_CPU1_TINT2 = 8U,
    /** \brief CPU2_TINT0 is the trigger source*/
    CDD_SENT_TRIGGER_CPU2_TINT0 = 9U,
    /** \brief CPU2_TINT1 is the trigger source*/
    CDD_SENT_TRIGGER_CPU2_TINT1 = 10U,
    /** \brief CPU2_TINT2 is the trigger source*/
    CDD_SENT_TRIGGER_CPU2_TINT2 = 11U,
    /** \brief CPU3_TINT0 is the trigger source*/
    CDD_SENT_TRIGGER_CPU3_TINT0 = 12U,
    /** \brief CPU3_TINT1 is the trigger source*/
    CDD_SENT_TRIGGER_CPU3_TINT1 = 13U,
    /** \brief CPU3_TINT2 is the trigger source*/
    CDD_SENT_TRIGGER_CPU3_TINT2 = 14U,
    /** \brief INPUTXBAR5 is the trigger source*/
    CDD_SENT_TRIGGER_INPUTXBAR5 = 24U,
    /** \brief INPUTXBAR11 is the trigger source*/
    CDD_SENT_TRIGGER_INPUTXBAR11 = 25U,
    /** \brief INPUTXBAR12 is the trigger source*/
    CDD_SENT_TRIGGER_INPUTXBAR12 = 26U,
    /** \brief INPUTXBAR13 is the trigger source*/
    CDD_SENT_TRIGGER_INPUTXBAR13 = 27U,
    /** \brief INPUTXBAR14 is the trigger source*/
    CDD_SENT_TRIGGER_INPUTXBAR14 = 28U,
    /** \brief INPUTXBAR15 is the trigger source*/
    CDD_SENT_TRIGGER_INPUTXBAR15 = 29U,
    /** \brief INPUTXBAR16 is the trigger source*/
    CDD_SENT_TRIGGER_INPUTXBAR16 = 30U,
    /** \brief EPWM1_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM1_ADCSOCA = 31U,
    /** \brief EPWM1_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM1_ADCSOCB = 32U,
    /** \brief EPWM2_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM2_ADCSOCA = 33U,
    /** \brief EPWM2_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM2_ADCSOCB = 34U,
    /** \brief EPWM3_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM3_ADCSOCA = 35U,
    /** \brief EPWM3_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM3_ADCSOCB = 36U,
    /** \brief EPWM4_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM4_ADCSOCA = 37U,
    /** \brief EPWM4_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM4_ADCSOCB = 38U,
    /** \brief EPWM5_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM5_ADCSOCA = 39U,
    /** \brief EPWM5_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM5_ADCSOCB = 40U,
    /** \brief EPWM6_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM6_ADCSOCA = 41U,
    /** \brief EPWM6_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM6_ADCSOCB = 42U,
    /** \brief EPWM7_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM7_ADCSOCA = 43U,
    /** \brief EPWM7_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM7_ADCSOCB = 44U,
    /** \brief EPWM8_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM8_ADCSOCA = 45U,
    /** \brief EPWM8_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM8_ADCSOCB = 46U,
    /** \brief EPWM9_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM9_ADCSOCA = 47U,
    /** \brief EPWM1_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM9_ADCSOCB = 48U,
    /** \brief EPWM10_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM10_ADCSOCA = 49U,
    /** \brief EPWM10_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM10_ADCSOCB = 50U,
    /** \brief EPWM11_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM11_ADCSOCA = 51U,
    /** \brief EPWM11_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM11_ADCSOCB = 52U,
    /** \brief EPWM12_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM12_ADCSOCA = 53U,
    /** \brief EPWM12_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM12_ADCSOCB = 54U,
    /** \brief EPWM13_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM13_ADCSOCA = 55U,
    /** \brief EPWM13_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM13_ADCSOCB = 56U,
    /** \brief EPWM14_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM14_ADCSOCA = 57U,
    /** \brief EPWM14_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM14_ADCSOCB = 58U,
    /** \brief EPWM15_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM15_ADCSOCA = 59U,
    /** \brief EPWM15_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM15_ADCSOCB = 60U,
    /** \brief EPWM16_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM16_ADCSOCA = 61U,
    /** \brief EPWM16_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM16_ADCSOCB = 62U,
    /** \brief EPWM17_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM17_ADCSOCA = 63U,
    /** \brief EPWM17_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM17_ADCSOCB = 64U,
    /** \brief EPWM18_ADCSOCA is the trigger source*/
    CDD_SENT_TRIGGER_EPWM18_ADCSOCA = 65U,
    /** \brief EPWM18_ADCSOCB is the trigger source*/
    CDD_SENT_TRIGGER_EPWM18_ADCSOCB = 66U,
    /** \brief ECAP1_SOC is the trigger source*/
    CDD_SENT_TRIGGER_ECAP1_SOC = 95U,
    /** \brief ECAP2_SOC is the trigger source*/
    CDD_SENT_TRIGGER_ECAP2_SOC = 96U,
    /** \brief ECAP3_SOC is the trigger source*/
    CDD_SENT_TRIGGER_ECAP3_SOC = 97U,
    /** \brief ECAP4_SOC is the trigger source*/
    CDD_SENT_TRIGGER_ECAP4_SOC = 98U,
    /** \brief ECAP5_SOC is the trigger source*/
    CDD_SENT_TRIGGER_ECAP5_SOC = 99U,
    /** \brief ECAP6_SOC is the trigger source*/
    CDD_SENT_TRIGGER_ECAP6_SOC = 100U
} Cdd_SentTriggerSource;

/** \brief Type for Hardware trigger Source */
/*
 *Design: MCAL-28670
 */
[!LOOP "CddSentConfig/CddSentController/*"!][!//
#define SENT_ENABLE_INTERRUPT_SOURCES    (uint32)((0x00000000U)\
                                    |(0UL<<1U)\
                                    |(0UL<<2U)\
                                    |(0UL<<3U)\
                                    |(0UL<<4U)\
                                    |([!IF "CddSentSlowChannelInterrupts/Slow_Channel='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)\
                                    |([!IF "CddSentSlowChannelInterrupts/Slow_Channel_With_CRC_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<6U)\
                                    |([!IF "CddSentSlowChannelInterrupts/Slow_Channel_With_Format_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<7U)\
                                    |([!IF "CddSentFastChannelCRCErrorInterrupts/Sensor_1_Fast_Channel_With_CRC_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<8U)\
                                    |([!IF "CddSentFastChannelCRCErrorInterrupts/Sensor_2_Fast_Channel_With_CRC_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<9U)\
                                    |([!IF "CddSentFastChannelCRCErrorInterrupts/Sensor_3_Fast_Channel_With_CRC_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<10U)\
                                    |([!IF "CddSentFastChannelCRCErrorInterrupts/Sensor_4_Fast_Channel_With_CRC_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<11U)\
                                    |([!IF "CddSentFastChannelFrameErrorInterrupts/Sensor_1_Fast_Channel_With_Frame_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<12U)\
                                    |([!IF "CddSentFastChannelFrameErrorInterrupts/Sensor_2_Fast_Channel_With_Frame_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<13U)\
                                    |([!IF "CddSentFastChannelFrameErrorInterrupts/Sensor_3_Fast_Channel_With_Frame_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<14U)\
                                    |([!IF "CddSentFastChannelFrameErrorInterrupts/Sensor_4_Fast_Channel_With_Frame_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<15U)\
                                    |([!IF "CddSentTimeoutErrorInterrupts/Sensor_1_Timeout_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<16U)\
                                    |([!IF "CddSentTimeoutErrorInterrupts/Sensor_2_Timeout_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<17U)\
                                    |([!IF "CddSentTimeoutErrorInterrupts/Sensor_3_Timeout_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<18U)\
                                    |([!IF "CddSentTimeoutErrorInterrupts/Sensor_4_Timeout_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<19U)\
                                    |([!IF "CddSentSyncErrorInterrupts/Fast_Channel_Sync_Pulse_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<20U)\
                                    |([!IF "CddSentSyncErrorInterrupts/Successive_Calibration_Pulse_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<21U)\
                                    |([!IF "CddSentSyncErrorInterrupts/Frequency_Drift_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<22U)\
                                    |([!IF "CddSentFIFOInterrupts/FIFO_Trigger_Event='true'"!]1[!ELSE!]0[!ENDIF!]UL<<23U)\
                                    |([!IF "CddSentFIFOInterrupts/FIFO_Overflow_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<24U)\
                                    |([!IF "CddSentFIFOInterrupts/FIFO_Underflow_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<25U)\
                                    |([!IF "CddSentOverflowErrorInterrupts/Broadcast_Overflow_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<26U)\
                                    |([!IF "CddSentOverflowErrorInterrupts/Sensor_1_Overflow_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<27U)\
                                    |([!IF "CddSentOverflowErrorInterrupts/Sensor_2_Overflow_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<28U)\
                                    |([!IF "CddSentOverflowErrorInterrupts/Sensor_3_Overflow_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<29U)\
                                    |([!IF "CddSentOverflowErrorInterrupts/Sensor_4_Overflow_Error='true'"!]1[!ELSE!]0[!ENDIF!]UL<<30U)\
                                    )
[!ENDLOOP!][!//

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/** \brief Pre-compile instance of Cdd sent config pointer */
/*
 *Design: MCAL-28667
 */
 extern CONST(struct Cdd_Sent_ConfigType_s, CDD_SENT_CONFIG_DATA) CddSentConfig_Cdd_SentController_List;
/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
 [!ENDSELECT!]
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_SENT_CFG_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Cfg.h
 *********************************************************************************************************************/
