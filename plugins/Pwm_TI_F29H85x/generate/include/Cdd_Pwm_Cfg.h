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

#define CDD_PWM_CFG_MAJOR_VERSION           ([!"substring-before($moduleSoftwareVer,'.')"!]U)
#define CDD_PWM_CFG_MINOR_VERSION           ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
#define CDD_PWM_CFG_PATCH_VERSION           ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)

[!SELECT "as:modconf('Cdd_Pwm/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Pwm/Cdd']"!]
/* CDD_PWM Build Variant. Pre-compile build Variants */
[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!]
#define CDD_PWM_PRE_COMPILE_VARIANT         (STD_ON)

#define CDD_PWM_CONFIG_PC       Cdd_Pwm_ConfigSet

[!ENDIF!][!//

/* Macro to define the number of PWM channels supported by the driver */
#define CDD_PWM_INSTANCE_COUNT    ((Cdd_Pwm_InstanceType)[!"num:i(ecu:get('Cdd_Pwm_InstanceCount'))"!]U)

/* Macro to define the number of Pwm instances configured */
#define CDD_PWM_COUNT       ((Cdd_Pwm_InstanceType)[!"num:i(count(CddPwmConfigSet/CddPwmHwUnitConfig/*))"!]U)

/* Macro to define the number of Pwm channels configured */
#define CDD_PWM_CHANNEL_COUNT       ((Cdd_Pwm_ChannelType)[!"num:i(count(CddPwmConfigSet/CddPwmHwUnitConfig/*/CddPwmOutputChannel/*))"!]U)

/* Macro to define the maximum number of events supported for an interrupt */
#define CDD_PWM_INTEVT_COUNT        ((uint8)15U)

/* Development error detection macro */
#define CDD_PWM_DEV_ERROR_DETECT            [!IF "CddPwmGeneral/CddPwmDevErrorDetect  = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Set output to IDLE macro */
#define CDD_PWM_SET_OUTPUT_TO_IDLE_API      [!IF "CddPwmGeneral/CddPwmSetOutputToIdle = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* SetPeriodAndDuty API macro */
#define CDD_PWM_SET_PERIOD_API    [!IF "CddPwmGeneral/CddPwmSetPeriod = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Set duty cycle API macro */
#define CDD_PWM_SET_DUTY_CYCLE_API    [!IF "CddPwmGeneral/CddPwmSetDutyCycle = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Deinitialization Api macro */
#define CDD_PWM_DEINIT_API      [!IF "CddPwmGeneral/CddPwmDeInitApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Version info Api macro */
#define CDD_PWM_VERSION_INFO_API    [!IF "CddPwmGeneral/CddPwmVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Notification API macro */
#define CDD_PWM_NOTIFICATION_SUPPORTED    [!IF "CddPwmGeneral/CddPwmNotificationSupported = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!VAR "CddPwmChannelId" = "num:i(0)"!][!//
[!LOOP "CddPwmConfigSet/CddPwmHwUnitConfig/*"!][!//
/* Symbolic name for the PWM instance  [!"CddPwmInstanceId"!] */
#define CddPwmConf_CddPwmUnit_[!"@name"!]   ((Cdd_Pwm_InstanceType)[!"num:i(node:pos(.))"!]U)  /*~ASR~*/

[!LOOP "CddPwmOutputChannel/*"!][!//
[!IF "text:contains(node:value(CddPwmChannel),'A')"!]
/* Symbolic name of the EPWM[!"../../CddPwmInstanceId"!] output channel A */
#define CddPwmConf_CddPwmUnit_[!"node:name(../../.)"!]_[!"substring-after(@name,'CddPwmOutput')"!]   ((Cdd_Pwm_ChannelType)[!"num:i($CddPwmChannelId)"!]U)  /*~ASR~*/[!//
[!VAR "CddPwmChannelId" = "num:i($CddPwmChannelId+1)"!][!//
[!ENDIF!][!//

[!IF "text:contains(node:value(CddPwmChannel),'B')"!]
/* Symbolic name of the EPWM[!"../../CddPwmInstanceId"!] output channel B */
#define CddPwmConf_CddPwmUnit_[!"node:name(../../.)"!]_[!"substring-after(@name,'CddPwmOutput')"!]   ((Cdd_Pwm_ChannelType)[!"num:i($CddPwmChannelId)"!]U)  /*~ASR~*/
[!VAR "CddPwmChannelId" = "num:i($CddPwmChannelId+1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!ENDLOOP!][!//

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
[!//
[!LOOP "CddPwmConfigSet/CddPwmHwUnitConfig/*"!][!//
[!IF "(node:value(CddPwmInterruptEnable) = 'true')"!]
#define CDD_PWM[!"CddPwmInstanceId"!]_INT_ENABLE
#define CDD_PWM[!"CddPwmInstanceId"!]_[!"CddPwmInterruptCategory"!]
[!ENDIF!][!//
[!ENDLOOP!]

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Cdd_Pwm_OuputChannelType determines the channel output */
typedef enum
{
    /** \brief Ouput channel A */
    CDD_PWM_OUTPUT_A,
    /** \brief Ouput channel B */
    CDD_PWM_OUTPUT_B
}Cdd_Pwm_OuputChannelType;

/** \brief Cdd_Pwm_OuputSymmetryType determines the symmetry of the output waveform of a PWM instance */
typedef enum
{
    /** \brief Asymmetric waveform */
    CDD_PWM_ASYMMETRIC_WAVEFORM,
    /** \brief Symmetric waveform */
    CDD_PWM_SYMMETRIC_WAVEFORM,
}Cdd_Pwm_OuputSymmetryType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
[!//
extern const struct Cdd_Pwm_ConfigTag Cdd_Pwm_ConfigSet;[!//

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

[!IF "(num:i(count(util:distinct(node:foreach(CddPwmConfigSet/CddPwmHwUnitConfig/*/CddPwmNotification,'val','$val')))) > num:i(0))"!][!//
#ifndef DOXYGEN_SHOULD_SKIP_THIS[!//

[!IF "CddPwmGeneral/CddPwmNotificationSupported = 'true'"!]
#define CDD_PWM_START_SEC_CODE
#include "Cdd_Pwm_MemMap.h"

/* Declaration of the notification functions */
[!LOOP "(util:distinct(node:foreach(CddPwmConfigSet/CddPwmHwUnitConfig/*/CddPwmNotification,'val','$val')))"!]
extern void [!"."!](void);
[!ENDLOOP!][!//

#define CDD_PWM_STOP_SEC_CODE
#include "Cdd_Pwm_MemMap.h"
[!ENDIF!][!//

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
[!ENDIF!][!//
[!ENDSELECT!][!//

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
