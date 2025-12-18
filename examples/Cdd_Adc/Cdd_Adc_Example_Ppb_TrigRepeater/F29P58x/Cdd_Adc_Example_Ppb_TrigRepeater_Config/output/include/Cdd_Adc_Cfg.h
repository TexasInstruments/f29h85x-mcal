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
 *  File:       Cdd_Adc_Cfg.h
 *  Generator:  None
 *
 *  Description:  Cdd_Adc configuration header file                                                      
 *********************************************************************************************************************/
#ifndef CDD_ADC_CFG_H
#define CDD_ADC_CFG_H
/** \addtogroup CDD_ADC
 *  @{
 */
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/* CDD ADC Driver Configuration SW Version Info */

#define CDD_ADC_CFG_MAJOR_VERSION           (3U)
#define CDD_ADC_CFG_MINOR_VERSION           (0U)
#define CDD_ADC_CFG_PATCH_VERSION           (0U)

/* CDD ADC Build Variant. Pre-compile build Variants */

#define CDD_ADC_PRE_COMPILE_VARIANT         (STD_ON)

#define CDD_ADC_CONFIG_PC       Cdd_Adc_Config


/* Macro to define the number of channels configured */
#define CDD_ADC_CHN_COUNT                   ((uint8)9U)

/* Macro to define the total number of ADC instances supported */
#define CDD_ADC_MAX_HW_UNIT_COUNT           ((uint8)5U)

/* Macro to define the total number of interrupts supported */
#define CDD_ADC_MAX_INT_COUNT               ((uint8)4U)

/* Development error detection macro */
#define CDD_ADC_DEV_ERROR_DETECT            (STD_ON)

/* Deinitialization Api macro */
#define CDD_ADC_DEINIT_API                  (STD_ON)

/* Software group conversion Api macro */
#define CDD_ADC_ENABLE_START_STOP_GROUP_API (STD_ON)

/* Hardware trigger Api macro */
#define CDD_ADC_GLBSW_TRIG_API             (STD_OFF)

#if(CDD_ADC_GLBSW_TRIG_API == STD_ON)
/* Macro to define the number of global software triggers configured */
#define CDD_ADC_GLBSW_TRIG_CNT              ((uint8)0U)
#endif

/* Macro to define the number of groups configured */
#define CDD_ADC_GROUP_CNT                   ((Cdd_Adc_GroupType)6U)

/* Notification Api macro */
#define CDD_ADC_GRP_NOTIF_CAPABILITY_API    (STD_ON)

/* Macro to define the number of hardware units configured */
#define CDD_ADC_HW_CNT                      ((uint8)2U)

/* Hardware trigger Api macro */
#define CDD_ADC_HW_TRIGGER_API              (STD_ON)

/* Limit check enable Api macro */
#define CDD_ADC_ENABLE_PPB_API             (STD_ON)

/* Temperature Sesnor enable/disable macro */
#define CDD_ADC_LOCK_TEMPERATURE_SENSOR     (STD_OFF)


/* Macro to enable open/shorts detection */
#define CDD_ADC_OPEN_SHORT_DETECTION        (STD_OFF)

#if(STD_ON == CDD_ADC_ENABLE_PPB_API)
/* Macro to define the number of safety checker units configured */
#define CDD_ADC_PPB_CNT                     ((Cdd_Adc_PpbType)3U)
#endif

/* Read group Api macro */
#define CDD_ADC_READ_GROUP_API              (STD_ON)

/* Safety checker enabling Api macro */
#define CDD_ADC_SAFETY_CHECK_API            (STD_OFF)

#if(CDD_ADC_SAFETY_CHECK_API == STD_ON)
/* Macro to define the number of safety checker units configured */
#define CDD_ADC_CHECKER_CNT                 (Cdd_Adc_CheckerType)(0U)

/* Number of checker events for all the safety checker events. */
#define CDD_ADC_CHECKER_EVT_CNT             ((uint8)4U)

/* Macro to define the number of interrupt event instances configured */
#define CDD_ADC_CHECKER_INTEVT_CNT          ((uint8)0U)
#endif

/* Hardware trigger Api macro */
#define CDD_ADC_SET_RESOLUTION_API          (STD_OFF)

/* Temperature Sensor enable/disable macro */
#define CDD_ADC_TEMPERATURE_SENSOR_ENABLE   (STD_OFF)

/* Macro to enable/disable the trigger repeater */
#define CDD_ADC_TRIG_REP_ENABLE             (STD_ON)


/* Macro to define the number of trigger repeaters per ADC HW unit */
#define CDD_ADC_TRIG_REP_CNT    ((uint8)2U)

/* Notification Api macro */
#define CDD_ADC_PPB_NOTIF_CAPABILITY_API    (STD_ON)

/* Version info Api macro */
#define CDD_ADC_VERSION_INFO_API    (STD_OFF)


/* CDD_ADCA hardware unit symbolic name */
#define CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_0         ((uint8)0U) /*~ASR~*/

/* ADC:CDD_ADCA Group0 symbolic name */
#define CddAdcConf_CddAdcGroup_CddAdcGroup_0    ((Cdd_Adc_GroupType)0U)  /*~ASR~*/

/* ADC:CDD_ADCA Group1 symbolic name */
#define CddAdcConf_CddAdcGroup_CddAdcGroup_1    ((Cdd_Adc_GroupType)1U)  /*~ASR~*/

/* ADC:CDD_ADCA Group2 symbolic name */
#define CddAdcConf_CddAdcGroup_CddAdcGroup_2    ((Cdd_Adc_GroupType)2U)  /*~ASR~*/

/* ADC:CDD_ADCA Group3 symbolic name */
#define CddAdcConf_CddAdcGroup_CddAdcGroup_3    ((Cdd_Adc_GroupType)3U)  /*~ASR~*/



/* ADC:CDD_ADCA PPB0 symbolic name */
#define CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0        ((Cdd_Adc_PpbType)0U) /*~ASR~*/

/* ADC:CDD_ADCA PPB1 symbolic name */
#define CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1        ((Cdd_Adc_PpbType)1U) /*~ASR~*/

/* ADC:CDD_ADCA PPB2 symbolic name */
#define CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_2        ((Cdd_Adc_PpbType)2U) /*~ASR~*/


/* CDD_ADCD hardware unit symbolic name */
#define CddAdcConf_CddAdcHwUnit_CddAdcHwUnit_1         ((uint8)1U) /*~ASR~*/

/* ADC:CDD_ADCD Group0 symbolic name */
#define CddAdcConf_CddAdcGroup_CddAdcGroup_4    ((Cdd_Adc_GroupType)4U)  /*~ASR~*/

/* ADC:CDD_ADCD Group1 symbolic name */
#define CddAdcConf_CddAdcGroup_CddAdcGroup_5    ((Cdd_Adc_GroupType)5U)  /*~ASR~*/







/* External Channel selection capability macro */
#define CDD_ADC_EXTCHSEL_CAPABILITY      (STD_OFF)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

#define CDD_ADCA_INT1_ENABLE

#define CDD_ADCA_INT1_ISR_CAT1_RTINT

#define CDD_ADCA_INT2_ENABLE

#define CDD_ADCA_INT2_ISR_CAT1_INT

#define CDD_ADCA_INT3_ENABLE

#define CDD_ADCA_INT3_ISR_CAT2_INT

#define CDD_ADCA_INT4_ENABLE

#define CDD_ADCA_INT4_ISR_CAT1_INT

#define CDD_ADCA_EVTINT_ENABLE

#define CDD_ADCA_EVTINT_ISR_CAT1_INT

#define CDD_ADCD_INT1_ENABLE

#define CDD_ADCD_INT1_ISR_CAT1_INT

#define CDD_ADCD_INT2_ENABLE

#define CDD_ADCD_INT2_ISR_CAT1_INT

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Specifies the identification (ID) for ADC Hardware instances */
typedef enum
{
    CDD_ADCA = 0U,                        /* Select ADCA instance */
    CDD_ADCB = 1U,                        /* Select ADCB instance */
    CDD_ADCC = 2U,                        /* Select ADCC instance */
    CDD_ADCD = 3U,                        /* Select ADCD instance */
    CDD_ADCE = 4U                         /* Select ADCE instance */
}Cdd_Adc_HwUnitType;

/** \brief Defines supported prescaler values */
typedef enum
{
    CDD_ADC_CLK_DIV_1_0 = 0U,            /* ADCCLK = (input clock) / 1.0 */
    CDD_ADC_CLK_DIV_2_0 = 2U,            /* ADCCLK = (input clock) / 2.0 */   
    CDD_ADC_CLK_DIV_2_5 = 3U,            /* ADCCLK = (input clock) / 2.5 */
    CDD_ADC_CLK_DIV_3_0 = 4U,            /* ADCCLK = (input clock) / 3.0 */
    CDD_ADC_CLK_DIV_3_5 = 5U,            /* ADCCLK = (input clock) / 3.5 */
    CDD_ADC_CLK_DIV_4_0 = 6U,            /* ADCCLK = (input clock) / 4.0 */
    CDD_ADC_CLK_DIV_4_5 = 7U,            /* ADCCLK = (input clock) / 4.5 */
    CDD_ADC_CLK_DIV_5_0 = 8U,            /* ADCCLK = (input clock) / 5.0 */
    CDD_ADC_CLK_DIV_5_5 = 9U,            /* ADCCLK = (input clock) / 5.5 */
    CDD_ADC_CLK_DIV_6_0 = 10U,           /* ADCCLK = (input clock) / 6.0 */
    CDD_ADC_CLK_DIV_6_5 = 11U,           /* ADCCLK = (input clock) / 6.5 */
    CDD_ADC_CLK_DIV_7_0 = 12U,           /* ADCCLK = (input clock) / 7.0 */
    CDD_ADC_CLK_DIV_7_5 = 13U,           /* ADCCLK = (input clock) / 7.5 */
    CDD_ADC_CLK_DIV_8_0 = 14U,           /* ADCCLK = (input clock) / 8.0 */
    CDD_ADC_CLK_DIV_8_5 = 15U            /* ADCCLK = (input clock) / 8.5 */
}Cdd_Adc_PrescaleType;

/** \brief Defines supported reference voltage modes */
typedef enum
{
    CDD_ADC_REFERENCE_INTERNAL = 0U,
    CDD_ADC_REFERENCE_EXTERNAL = 1U
}Cdd_Adc_RefModeType;

/** \brief Defines supported reference voltage types */
typedef enum
{
    CDD_ADC_REFERENCE_3_3V = 0U,
    CDD_ADC_REFERENCE_2_5V = 1U
}Cdd_Adc_RefVoltType;

/** \brief Defines supported signal modes types */
typedef enum
{
    CDD_ADC_MODE_SINGLE_ENDED = 0x00U,   /* Sample on single pin with VREFLO */
    CDD_ADC_MODE_DIFFERENTIAL = 0x80U    /* Sample on pair of pins */
}Cdd_Adc_SignalModeType;

/** \brief Defines supported SOC priority types */
typedef enum
{
    CDD_ADC_PRI_ALL_ROUND_ROBIN   = 0U,   /* Round robin mode is used for all        */
    CDD_ADC_PRI_SOC0_HIPRI        = 1U,   /*  SOC 0 hi pri, others in round robin     */
    CDD_ADC_PRIHRU_SOC1_HIPRI     = 2U,   /*  SOC 0-1 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC2_HIPRI     = 3U,   /*  SOC 0-2 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC3_HIPRI     = 4U,   /*  SOC 0-3 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC4_HIPRI     = 5U,   /*  SOC 0-4 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC5_HIPRI     = 6U,   /*  SOC 0-5 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC6_HIPRI     = 7U,   /*  SOC 0-6 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC7_HIPRI     = 8U,   /*  SOC 0-7 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC8_HIPRI     = 9U,   /*  SOC 0-8 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC9_HIPRI     = 10U,  /*  SOC 0-9 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC10_HIPRI    = 11U,  /*  SOC 0-10 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC11_HIPRI    = 12U,  /*  SOC 0-11 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC12_HIPRI    = 13U,  /*  SOC 0-12 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC13_HIPRI    = 14U,  /*  SOC 0-13 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC14_HIPRI    = 15U,  /*  SOC 0-14 hi pri, SOC15 in round robin   */
    CDD_ADC_PRIHRU_SOC15_HIPRI    = 16U,  /*  SOC 0-15 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC16_HIPRI    = 17U,  /*  SOC 0-16 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC17_HIPRI    = 18U,  /*  SOC 0-17 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC18_HIPRI    = 19U,  /*  SOC 0-18 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC19_HIPRI    = 20U,  /*  SOC 0-19 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC20_HIPRI    = 21U,  /*  SOC 0-20 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC21_HIPRI    = 22U,  /*  SOC 0-21 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC22_HIPRI    = 23U,  /*  SOC 0-22 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC23_HIPRI    = 24U,  /*  SOC 0-23 hi pri, others in round robin   */
    CDD_ADC_PRIHRU_SOC24_HIPRI    = 25U,  /*  SOC 0-24 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC25_HIPRI    = 26U,  /*  SOC 0-25 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC26_HIPRI    = 27U,  /*  SOC 0-26 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC27_HIPRI    = 28U,  /*  SOC 0-27 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC28_HIPRI    = 29U,  /*  SOC 0-28 hi pri, SOC15 in round robin   */
    CDD_ADC_PRIHRU_SOC29_HIPRI    = 30U,  /*  SOC 0-29 hi pri, others in round robin  */
    CDD_ADC_PRIHRU_SOC30_HIPRI    = 31U,  /*  SOC 0-30 hi pri, SOC15 in round robin   */
    CDD_ADC_PRI_ALL_HIPRI         = 32U   /* All priorities based on SOC number      */
}Cdd_Adc_SocPriorityType;

/** \brief Defines supported resolution modes */
typedef enum
{
    CDD_ADC_RESOLUTION_12BIT = 0x00U,    /* 12-bit conversion resolution */
    CDD_ADC_RESOLUTION_16BIT = 0x01U,     /* 16-bit conversion resolution */
    CDD_ADC_RESOLUTION_NONE
}Cdd_Adc_ResolutionType;

/** \brief Defines interrupts supported per ADC instance */
typedef enum
{
    CDD_ADC_INT1 = 0U,        /* ADCINT1 Interrupt */ 
    CDD_ADC_INT2 = 1U,        /* ADCINT2 Interrupt */ 
    CDD_ADC_INT3 = 2U,        /* ADCINT3 Interrupt */ 
    CDD_ADC_INT4 = 3U        /* ADCINT4 Interrupt */
}Cdd_Adc_IntNumType;

/** \brief Defines possible input types to a safety checker unit */
typedef enum
{
    CDD_ADC_SAFETY_CHECKER_INPUT_DISABLE  = 0x0U, /* Safety checker i/p disabled    */
    CDD_ADC_SAFETY_CHECKER_INPUT_SOC      = 0x1U, /* Safety checker i/p is SOC     */
    CDD_ADC_SAFETY_CHECKER_INPUT_PPB      = 0x2U, /* Safety checker i/p is PPB     */
    CDD_ADC_SAFETY_CHECKER_INPUT_PPBSUM   = 0x3U  /* Safety checker i/p is PPBSUM  */
} Cdd_Adc_CheckerInputType;

/** \brief Defines supported ADC triggers */
typedef enum{
  /* Trigger Name           TRIGSEL/ BURSTTRIGSEL   Connects to, Trigger
  *                             CONFIGURATION 
  */
	CDD_ADC_TRIGGER_SW_ONLY		     = 0x00U,	    /* Software only */
	CDD_ADC_TRIGGER_CPU1INT0		 = 0x01U,	    /* CPU1 Timer 0, TINT0 */
	CDD_ADC_TRIGGER_CPU1INT1		 = 0x02U,	    /* CPU1 Timer 1, TINT1 */
	CDD_ADC_TRIGGER_CPU1INT2		 = 0x03U,	    /* CPU1 Timer 2, TINT2 */
	CDD_ADC_TRIGGER_GPIO		     = 0x04U,	    /* GPIO, ADCEXTSOC (INPUT XABR1 INPUT5) */
	CDD_ADC_TRIGGER_EPWM1_SOCA		 = 0x05U,	    /* ePWM1, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM1_SOCB		 = 0x06U,	    /* ePWM1, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM2_SOCA		 = 0x07U,	    /* ePWM2, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM2_SOCB		 = 0x08U,	    /* ePWM2, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM3_SOCA		 = 0x09U,	    /* ePWM3, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM3_SOCB		 = 0x0AU,	    /* ePWM3, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM4_SOCA		 = 0x0BU,	    /* ePWM4, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM4_SOCB		 = 0x0CU,	    /* ePWM4, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM5_SOCA		 = 0x0DU,	    /* ePWM5, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM5_SOCB		 = 0x0EU,	    /* ePWM5, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM6_SOCA		 = 0x0FU,	    /* ePWM6, ADCSOCA*/
	CDD_ADC_TRIGGER_EPWM6_SOCB		 = 0x10U,	    /* ePWM6, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM7_SOCA		 = 0x11U,	    /* ePWM7, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM7_SOCB		 = 0x12U,	    /* ePWM7, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM8_SOCA		 = 0x13U,	    /* ePWM8, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM8_SOCB		 = 0x14U,	    /* ePWM8, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM9_SOCA		 = 0x15U,	    /* ePWM9, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM9_SOCB		 = 0x16U,	    /* ePWM9, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM10_SOCA		 = 0x17U,	    /* ePWM10, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM10_SOCB		 = 0x18U,	    /* ePWM10, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM11_SOCA		 = 0x19U,	    /* ePWM11, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM11_SOCB		 = 0x1AU,	    /* ePWM11, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM12_SOCA		 = 0x1BU,	    /* ePWM12, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM12_SOCB		 = 0x1CU,	    /* ePWM12, ADCSOCB */
	CDD_ADC_TRIGGER_REPEATER1		 = 0x28U,	    /* Repeater 1 */
	CDD_ADC_TRIGGER_REPEATER2		 = 0x29U,	    /* Repeater 2 */
	CDD_ADC_TRIGGER_CLB1_OUT27		 = 0x48U,       /* CLB1 OUT27*/
	CDD_ADC_TRIGGER_CLB2_OUT27		 = 0x49U,       /* CLB1 OUT27*/
	CDD_ADC_TRIGGER_CLB3_OUT27		 = 0x4AU,       /* CLB1 OUT27*/
	CDD_ADC_TRIGGER_CLB4_OUT27		 = 0x4BU,       /* CLB1 OUT27*/
	CDD_ADC_TRIGGER_CLB5_OUT27		 = 0x4CU,       /* CLB1 OUT27*/
	CDD_ADC_TRIGGER_CLB6_OUT27		 = 0x4DU,       /* CLB1 OUT27*/
	CDD_ADC_TRIGGER_ECAP1		     = 0x50U,	    /* eCAP1 */
	CDD_ADC_TRIGGER_ECAP2		     = 0x51U,	    /* eCAP2 */
	CDD_ADC_TRIGGER_ECAP3		     = 0x52U,	    /* eCAP3 */
	CDD_ADC_TRIGGER_ECAP4		     = 0x53U,	    /* eCAP4 */
	CDD_ADC_TRIGGER_ECAP5		     = 0x54U,	    /* eCAP5 */
	CDD_ADC_TRIGGER_ECAP6		     = 0x55U,	    /* eCAP6 */
	CDD_ADC_TRIGGER_EPWM13_SOCA		 = 0x58U,	    /* ePWM13,  ADCSOCA */
	CDD_ADC_TRIGGER_EPWM13_SOCB		 = 0x59U,	    /* ePWM13, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM14_SOCA		 = 0x5AU,	    /* ePWM14, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM14_SOCB		 = 0x5BU,	    /* ePWM14, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM15_SOCA		 = 0x5CU,	    /* ePWM15, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM15_SOCB		 = 0x5DU,	    /* ePWM15, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM16_SOCA		 = 0x5EU,	    /* ePWM16, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM16_SOCB		 = 0x5FU,	    /* ePWM16, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM17_SOCA		 = 0x60U,	    /* ePWM17, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM17_SOCB		 = 0x61U,	    /* ePWM17, ADCSOCB */
	CDD_ADC_TRIGGER_EPWM18_SOCA		 = 0x62U,	    /* ePWM18, ADCSOCA */
	CDD_ADC_TRIGGER_EPWM18_SOCB		 = 0x63U,	    /* ePWM18, ADCSOCB */
	CDD_ADC_TRIGGER_CPU2INT0		 = 0x64U,	    /* CPU2 Timer 0, TINT0 */
	CDD_ADC_TRIGGER_CPU2INT1		 = 0x65U,	    /* CPU2 Timer 1, TINT1 */
	CDD_ADC_TRIGGER_CPU2INT2		 = 0x66U,	    /* CPU2 Timer 2, TINT2 */
	CDD_ADC_TRIGGER_CPU3INT0		 = 0x67U,        /* CPU3 Timer 0, TINT0 */
	CDD_ADC_TRIGGER_CPU3INT1		 = 0x68U,        /* CPU3 Timer 0, TINT1 */
	CDD_ADC_TRIGGER_CPU3INT2		 = 0x69U         /* CPU3 Timer 0, TINT2 */
}Cdd_Adc_TriggerType;

/** \brief Defines modes supported by a trigger repeater */
typedef enum
{
    CDD_ADC_REPMODE_OVERSAMPLING   = 0x0U,  /* ADC repeater mode is oversampling */
    CDD_ADC_REPMODE_UNDERSAMPLING  = 0x1U   /* ADC repeater mode is undersampling */
}Cdd_Adc_RepeaterModeType;

/** \brief Defines repeater instances supported per ADC instance */
typedef enum
{
    CDD_ADC_REPINST1 = 0x0U,                /* Select ADC repeater instance 1 */
    CDD_ADC_REPINST2 = 0x1U                /* Select ADC repeater instance 2 */  
}Cdd_Adc_RepeaterType;

/** \brief Defines PPB instances supported per ADC instance */
typedef enum
{
    CDD_ADC_PPB_NUMBER1 = 0,  /* Post-processing block 1*/
    CDD_ADC_PPB_NUMBER2 = 1,  /* Post-processing block 2*/
    CDD_ADC_PPB_NUMBER3 = 2,  /* Post-processing block 3*/
    CDD_ADC_PPB_NUMBER4 = 3   /* Post-processing block 4*/
}Cdd_Adc_PpbIdType;

/** \brief Defines PPB result compare types */
typedef enum
{
    CDD_ADC_COMPARE_PPBRESULT = 0x0U,   /* PPB compare source is ADCRESULT */ 
    CDD_ADC_COMPARE_PPBPSUM   = 0x1U,   /* PPB compare source is PSUM */ 
    CDD_ADC_COMPARE_PPBSUM    = 0x2U    /* PPB compare source is SUM */ 
}Cdd_Adc_CompSelType;

/** \brief Defines safety checker flag types */
typedef enum
{
    CDD_ADC_SAFETY_CHECK_OOT_FLG     = 0U,   /* Safety Check Out-of-Tolerance Flag */
    CDD_ADC_SAFETY_CHECK_RES1OVF_FLG = 8U,   /* Safety Check Result1 Overflow Flag */
    CDD_ADC_SAFETY_CHECK_RES2OVF_FLG = 16U   /* Safety Check Result2 Overflow Flag */
}Cdd_Adc_SafetyCheckFlagType;

/** \brief Defines safety checker event sources for interrupt or event generation */
typedef enum
{
    CDD_ADC_SAFETY_CHECK_RES1OVF = 0U,      /* Safety Check Result1 Overflow */ 
    CDD_ADC_SAFETY_CHECK_RES2OVF = 4U,      /* Safety Check Result2 Overflow */ 
    CDD_ADC_SAFETY_CHECK_OOT     = 8U       /* Safety Check OOT */ 
}Cdd_Adc_SafetyCheckEvtSrcType;

/** \brief Defines possible states of a flag of an event generated from a safety checker */
typedef enum
{
    CDD_ADC_SAFETY_CHECKER_FLG_NONE,       /* No safety checker flag has been set */
    CDD_ADC_SAFETY_CHECKER_RES1OVF_FLG,   /* Safety Check Result1 Overflow Flag */
    CDD_ADC_SAFETY_CHECKER_RES2OVF_FLG,   /* Safety Check Result2 Overflow Flag */
    CDD_ADC_SAFETY_CHECKER_OOT_FLG,       /* Safety Check Out-of-Tolerance Flag */
}Cdd_Adc_CheckFlagStatusType;

/** \brief Defines supported events that can be generated from an interrupt event instance */
typedef enum
{
    CDD_ADC_CHECKER_EVT_1,          /* Interrupt event instance event 1 */
    CDD_ADC_CHECKER_EVT_2,          /* Interrupt event instance event 2 */
    CDD_ADC_CHECKER_EVT_3,          /* Interrupt event instance event 3 */
    CDD_ADC_CHECKER_EVT_4           /* Interrupt event instance event 4 */
}Cdd_Adc_CheckerEventType;

/** \brief Defines interrupt trigger sources to SOCs */
typedef enum
{
    CDD_ADC_INT_SOC_TRIGGER_NONE    = 0U,   /* No ADCINT will trigger the SOC */ 
    CDD_ADC_INT_SOC_TRIGGER_ADCINT1 = 1U,   /* ADCINT1 will trigger the SOC   */ 
    CDD_ADC_INT_SOC_TRIGGER_ADCINT2 = 2U    /* ADCINT2 will trigger the SOC   */
}Cdd_Adc_IntSocTriggerType;

/** \brief Defines End-Of-Conversion interrupt pulse modes */
typedef enum
{
    /* Occurs at the end of the acquisition window */ 
    CDD_ADC_PULSE_END_OF_ACQ_WIN = 0x00U,
    /* Occurs at the end of the voltage conversion */
    CDD_ADC_PULSE_END_OF_CONV    = 0x04U
}Cdd_Adc_EocPulseType;

/** \brief Defines supported internal nodes that can be connected to ADC */
typedef enum
{
    CDD_ADC_TEST_NODE_NO_CONN            = 0U,
    CDD_ADC_TEST_NODE_VDDCORE            = 1U,
    CDD_ADC_TEST_NODE_VDDA               = 2U,
    CDD_ADC_TEST_NODE_VSSA               = 3U,
    CDD_ADC_TEST_NODE_VREFLOA            = 4U,
    CDD_ADC_TEST_NODE_VREFLOB            = 5U,
    CDD_ADC_TEST_NODE_CDAC1H             = 7U,
    CDD_ADC_TEST_NODE_CDAC1L             = 8U,
    CDD_ADC_TEST_NODE_CDAC2H             = 9U,
    CDD_ADC_TEST_NODE_CDAC2L             = 10U,
    CDD_ADC_TEST_NODE_CDAC3H             = 11U,
    CDD_ADC_TEST_NODE_CDAC3L             = 12U,
    CDD_ADC_TEST_NODE_CDAC4H             = 13U,
    CDD_ADC_TEST_NODE_CDAC4L             = 14U,
    CDD_ADC_TEST_NODE_CDAC5H             = 15U,
    CDD_ADC_TEST_NODE_CDAC5L             = 16U,
    CDD_ADC_TEST_NODE_CDAC6H             = 17U,
    CDD_ADC_TEST_NODE_CDAC6L             = 18U,
    CDD_ADC_TEST_NODE_CDAC7H             = 19U,
    CDD_ADC_TEST_NODE_CDAC7L             = 20U,
    CDD_ADC_TEST_NODE_CDAC8H             = 21U,
    CDD_ADC_TEST_NODE_CDAC8L             = 22U,
    CDD_ADC_TEST_NODE_CDAC9H             = 23U,
    CDD_ADC_TEST_NODE_CDAC9L             = 24U,
    CDD_ADC_TEST_NODE_CDAC10H            = 25U,
    CDD_ADC_TEST_NODE_CDAC10L            = 26U,
    CDD_ADC_TEST_NODE_CDAC11H            = 27U,
    CDD_ADC_TEST_NODE_CDAC11L            = 28U,
    CDD_ADC_TEST_NODE_ENZ_CALIB_GAIN_3P3 = 29U,
    CDD_ADC_TEST_NODE_MAX           /* Added to check the valid input to the Cdd_Adc_SetInternalTestNode API */
}Cdd_Adc_InternalTestNodeType;

#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)
/** \brief Specifies open/short circuit modes */
typedef enum
{
    CDD_ADC_OSDETECT_MODE_DISABLED            = 0x0U,/* Open/Shorts detection circuit(O/S DC) is disabled */
    CDD_ADC_OSDETECT_MODE_VSSA                = 0x1U,/* O/S DC is enabled at zero scale */ 
    CDD_ADC_OSDETECT_MODE_VDDA                = 0x2U,/* O/S DC is enabled at full scale */ 
    CDD_ADC_OSDETECT_MODE_5BY12_VDDA          = 0x3U,/* O/S DC is enabled at 5/12 scale */ 
    CDD_ADC_OSDETECT_MODE_7BY12_VDDA          = 0x4U,/* O/S DC is enabled at 7/12 scale */ 
    CDD_ADC_OSDETECT_MODE_5K_PULLDOWN_TO_VSSA = 0x5U,/* O/S DC is enabled at 5K pulldown to VSSA */ 
    CDD_ADC_OSDETECT_MODE_5K_PULLUP_TO_VDDA   = 0x6U,/*  O/S DC is enabled at 5K pullup to VDDA */
    CDD_ADC_OSDETECT_MODE_7K_PULLDOWN_TO_VSSA = 0x7U /* O/S DC is enabled at 7K pulldown to VSSA */
}Cdd_Adc_OsDetectModeType;
#endif

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern const struct Cdd_Adc_ConfigTag Cdd_Adc_Config;


/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define CDD_ADC_START_SEC_CODE
#include "Cdd_Adc_MemMap.h"

/* Declaration of the group notification functions */
extern void Cdd_Adc_Grp0Notification(void);

extern void Cdd_Adc_Grp1Notification(void);

extern void Cdd_Adc_Grp2Notification(void);

extern void Cdd_Adc_Grp3Notification(void);

extern void Cdd_Adc_Hw1Grp0Notification(void);

extern void Cdd_Adc_Hw1Grp1Notification(void);

/* Declaration of the PPB notification functions */
extern void Cdd_Adc_Ppb0Notification(void);

extern void Cdd_Adc_Ppb1Notification(void);

extern void Cdd_Adc_Ppb2Notification(void);

#define CDD_ADC_STOP_SEC_CODE
#include "Cdd_Adc_MemMap.h"
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
#endif /* CDD_ADC_CFG_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Cfg.h
 *********************************************************************************************************************/
