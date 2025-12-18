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
 *  File:       Cdd_Pwm_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  Cdd_Pwm configuration header file                                                      
 *********************************************************************************************************************/
#ifndef CDD_PWM_CFG_H
#define CDD_PWM_CFG_H

/** \addtogroup CDD_PWM
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

/* CDD CDD_PWM Driver Configuration SW Version Info */

#define CDD_PWM_CFG_MAJOR_VERSION           (3U)
#define CDD_PWM_CFG_MINOR_VERSION           (0U)
#define CDD_PWM_CFG_PATCH_VERSION           (0U)

/* CDD_PWM Build Variant. Pre-compile build Variants */

#define CDD_PWM_PRE_COMPILE_VARIANT         (STD_ON)

#define CDD_PWM_CONFIG_PC       Cdd_Pwm_Config

/* Macro to define which mode of the driver is enabled */
#define CDD_PWM_ADVANCED_MODE_API    (STD_OFF)


/* Macro to define the number of PWM channels supported by the driver */
#define CDD_PWM_INSTANCE_COUNT    ((Cdd_Pwm_InstanceType)18U)

/* Macro to define the number of Pwm instances configured */
#define CDD_PWM_COUNT       ((Cdd_Pwm_InstanceType)2U)

/* Macro to define the maximum number of events supported for an interrupt */
#define CDD_PWM_INTEVT_COUNT        ((uint8)15U)

/* Development error detection macro */
#define CDD_PWM_DEV_ERROR_DETECT            (STD_ON)

/* Macro to define the number of Pwm channels configured */
#define CDD_PWM_CHANNEL_COUNT       ((Cdd_Pwm_ChannelType)4U)

/* Set output to IDLE macro */
#define CDD_PWM_SET_OUTPUT_TO_IDLE_API      (STD_ON)

/* SetPeriodAndDuty API macro */
#define CDD_PWM_SET_PERIOD_API    (STD_ON)

/* Set duty cycle API macro */
#define CDD_PWM_SET_DUTY_CYCLE_API    (STD_ON)

/* Deinitialization Api macro */
#define CDD_PWM_DEINIT_API      (STD_ON)

/* Version info Api macro */
#define CDD_PWM_VERSION_INFO_API    (STD_ON)

/* Notification API macro */
#define CDD_PWM_NOTIFICATION_SUPPORTED    (STD_ON)


/* Symbolic name for the PWM instance EPWM1 */
#define CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0   ((Cdd_Pwm_InstanceType)0U)  /*~ASR~*/

/* Symbolic name of the EPWM1 output channel A */
#define CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_0   ((Cdd_Pwm_ChannelType)0U)  /*~ASR~*/

/* Symbolic name of the EPWM1 output channel B */
#define CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_1   ((Cdd_Pwm_ChannelType)1U)  /*~ASR~*/

/* Symbolic name for the PWM instance EPWM2 */
#define CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1   ((Cdd_Pwm_InstanceType)1U)  /*~ASR~*/

/* Symbolic name of the EPWM2 output channel A */
#define CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_2   ((Cdd_Pwm_ChannelType)2U)  /*~ASR~*/

/* Symbolic name of the EPWM2 output channel B */
#define CddPwmConf_CddPwmOutputChannel_CddPwmOutputChannel_3   ((Cdd_Pwm_ChannelType)3U)  /*~ASR~*/


/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

#define CDD_PWM1_INT_ENABLE
#define CDD_PWM1_ISR_CAT1_RTINT

#define CDD_PWM2_INT_ENABLE
#define CDD_PWM2_ISR_CAT1_RTINT


/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/


/** \brief Cdd_Pwm_OutputSymmetryType determines the symmetry of the output waveform of a PWM instance */
typedef enum
{
    /** \brief Asymmetric waveform */
    CDD_PWM_ASYMMETRIC_WAVEFORM,
    /** \brief Symmetric waveform */
    CDD_PWM_SYMMETRIC_WAVEFORM
}Cdd_Pwm_OutputSymmetryType;


/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern const struct Cdd_Pwm_ConfigTag Cdd_Pwm_Config;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#define CDD_PWM_START_SEC_CODE
#include "Cdd_Pwm_MemMap.h"


/* Declaration of the notification functions */
extern void Cdd_Pwm_AsymmetricNotification(void);

extern void Cdd_Pwm_SymmetricNotification(void);


#define CDD_PWM_STOP_SEC_CODE
#include "Cdd_Pwm_MemMap.h"

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_PWM_CFG_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Pwm_Cfg.h
 *********************************************************************************************************************/
