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
#define CDD_PWM_CFG_MINOR_VERSION           (1U)
#define CDD_PWM_CFG_PATCH_VERSION           (0U)

/* CDD_PWM Build Variant. Pre-compile build Variants */

#define CDD_PWM_PRE_COMPILE_VARIANT         (STD_ON)

#define CDD_PWM_CONFIG_PC       Cdd_Pwm_Config

/* Macro to define which mode of the driver is enabled */
#define CDD_PWM_ADVANCED_MODE_API    (STD_OFF)


/* Macro to define the number of PWM channels supported by the driver */
#define CDD_PWM_INSTANCE_COUNT    ((Cdd_Pwm_InstanceType)12U)

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
