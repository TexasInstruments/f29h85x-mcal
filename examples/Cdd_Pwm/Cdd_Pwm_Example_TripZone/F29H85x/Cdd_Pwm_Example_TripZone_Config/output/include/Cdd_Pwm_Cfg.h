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
#define CDD_PWM_ADVANCED_MODE_API    (STD_ON)


/* Macro to define the number of PWM channels supported by the driver */
#define CDD_PWM_INSTANCE_COUNT    ((Cdd_Pwm_InstanceType)18U)

/* Macro to define the number of Pwm instances configured */
#define CDD_PWM_COUNT       ((Cdd_Pwm_InstanceType)3U)

/* Macro to define the maximum number of events supported for an interrupt */
#define CDD_PWM_INTEVT_COUNT        ((uint8)15U)

/* Development error detection macro */
#define CDD_PWM_DEV_ERROR_DETECT            (STD_ON)

/* Macro to define the number of instance id symbolic names */
#define CDD_PWM_HW_AND_XLINK_COUNT       ((Cdd_Pwm_InstanceType)3U)

/* Macro to define the number of Xlink groups configured */
#define CDD_PWM_XLINK_GRP_COUNT     (uint8)(0U)

/* Macro to define the number of HRPWMCAL */
#define CDD_PWM_HRPWM_CAL_COUNT     (uint8)(3U)

/* Macro to define the number of HRPWMCAL */
#define CDD_PWM_CONFIG_HRPWMCAL_COUNT     (uint8)(0U)

/* Macro to define HRPWM capability */
#define CDD_PWM_HRPWM_SUPPORTED    (STD_ON)

/* Version info Api macro */
#define CDD_PWM_VERSION_INFO_API    (STD_ON)

/* Notification API macro */
#define CDD_PWM_NOTIFICATION_SUPPORTED    (STD_ON)


/* Symbolic name for the PWM instance EPWM1 */
#define CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_0   ((Cdd_Pwm_InstanceType)0U)  /*~ASR~*/

/* Symbolic name for the PWM instance EPWM2 */
#define CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_1   ((Cdd_Pwm_InstanceType)1U)  /*~ASR~*/

/* Symbolic name for the PWM instance EPWM3 */
#define CddPwmConf_CddPwmHwUnitConfig_CddPwmHwUnitConfig_2   ((Cdd_Pwm_InstanceType)2U)  /*~ASR~*/



/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/


#define CDD_PWM1_TZINT_ENABLE
#define CDD_PWM1_ISR_CAT1_RTINT

#define CDD_PWM2_TZINT_ENABLE
#define CDD_PWM2_ISR_CAT2_INT

#define CDD_PWM3_TZINT_ENABLE
#define CDD_PWM3_ISR_CAT1_INT

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/


/** \brief SYNC INPUT pulse source enumeration */
typedef enum
{
    /* Disable Sync-in */
    CDD_PWM_SYNC_IN_PULSE_SRC_DISABLE         = 0x0U,
    /* Sync-in source is EPWM1 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM1   = 0x1U,
    /* Sync-in source is EPWM2 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM2   = 0x2U,
    /* Sync-in source is EPWM3 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM3   = 0x3U,
    /* Sync-in source is EPWM4 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM4   = 0x4U,
    /* Sync-in source is EPWM5 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM5   = 0x5U,
    /* Sync-in source is EPWM6 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM6   = 0x6U,
    /* Sync-in source is EPWM7 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM7   = 0x7U,
    /* Sync-in source is EPWM8 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM8   = 0x8U,
    /* Sync-in source is EPWM9 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM9   = 0x9U,
    /* Sync-in source is EPWM10 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM10  = 0xAU,
    /* Sync-in source is EPWM11 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM11  = 0xBU,
    /* Sync-in source is EPWM12 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM12  = 0xCU,
    /* Sync-in source is EPWM13 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM13  = 0xDU,
    /* Sync-in source is EPWM14 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM14  = 0xEU,
    /* Sync-in source is EPWM15 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM15  = 0xFU,
    /* Sync-in source is EPWM16 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM16  = 0x10U,
    /* Sync-in source is ECAP1 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP1   = 0x11U,
    /* Sync-in source is ECAP2 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP2   = 0x12U,
    /* Sync-in source is ECAP3 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP3   = 0x13U,
    /* Sync-in source is ECAP4 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP4   = 0x14U,
    /* Sync-in source is ECAP5 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP5   = 0x15U,
    /* Sync-in source is ECAP6 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP6   = 0x16U,
    /* Sync-in source is ECAP7 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_ECAP7  = 0x17U,
    /* Sync-in source is Input XBAR out5 signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT5 = 0x18U,
    /* Sync-in source is Input XBAR out6 signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_INPUTXBAR_OUT6 = 0x19U,
    /* Sync-in source is Ethercat sync0 signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_ETHERCAT_SYNC0 = 0x1AU,
    /* Sync-in source is Ethercat sync1 signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_ETHERCAT_SYNC1 = 0x1BU,
    /* Sync-in source is EPWM15 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM17  = 0x1CU,
    /* Sync-in source is EPWM16 sync-out signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_SYNCOUT_EPWM18  = 0x1DU,
    /* Sync-in source is FSI RXA trigger1 signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_FSIRXA_TRIG1   = 0x1E,
    /* Sync-in source is FSI RXB trigger1 signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_FSIRXB_TRIG1   = 0x1FU,
    /* Sync-in source is FSI RXC trigger1 signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_FSIRXC_TRIG1   = 0x20U,
    /* Sync-in source is FSI RXD trigger1 signal */
    CDD_PWM_SYNC_IN_PULSE_SRC_FSIRXD_TRIG1   = 0x21U
} Cdd_Pwm_SyncInPulseSourceType;

/** \brief Enum that defines the diode emulation trip low sources for an EPWM instance */
typedef enum{
    /* Trip source is CMPSSTRIPL1 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL1 = 0x00U,
    /* Trip source is CMPSSTRIPL2 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL2 = 0x01U,
    /* Trip source is CMPSSTRIPL3 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL3 = 0x02U,
    /* Trip source is CMPSSTRIPL4 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL4 = 0x03U,
    /* Trip source is CMPSSTRIPL5 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL5 = 0x04U,
    /* Trip source is CMPSSTRIPL6 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL6 = 0x05U,
    /* Trip source is CMPSSTRIPL7 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL7 = 0x06U,
    /* Trip source is CMPSSTRIPL8 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL8 = 0x07U,
    /* Trip source is CMPSSTRIPL9 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL9 = 0x08U,
    /* Trip source is CMPSSTRIPL10 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL10 = 0x09U,
    /* Trip source is CMPSSTRIPL11 signal */
    CDD_PWM_DE_TRIPL_SRC_CMPSSTRIPL11 = 0x0AU,
    /* Trip source is INPUTXBAR out1 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT1 = 0x10U,
    /* Trip source is INPUTXBAR out2 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT2 = 0x11U,
    /* Trip source is INPUTXBAR out3 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT3 = 0x12U,
    /* Trip source is INPUTXBAR out4 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT4 = 0x13U,
    /* Trip source is INPUTXBAR out5 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT5 = 0x14U,
    /* Trip source is INPUTXBAR out6 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT6 = 0x15U,
    /* Trip source is INPUTXBAR out7 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT7 = 0x16U,
    /* Trip source is INPUTXBAR out8 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT8 = 0x17U,
    /* Trip source is INPUTXBAR out9 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT9 = 0x18U,
    /* Trip source is INPUTXBAR out10 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT10 = 0x19U,
    /* Trip source is INPUTXBAR out11 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT11 = 0x1AU,
    /* Trip source is INPUTXBAR out12 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT12 = 0x1BU,
    /* Trip source is INPUTXBAR out13 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT13 = 0x1CU,
    /* Trip source is INPUTXBAR out14 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT14 = 0x1DU,
    /* Trip source is INPUTXBAR out15 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT15 = 0x1EU,
    /* Trip source is INPUTXBAR out16 signal */
    CDD_PWM_DE_TRIPL_SRC_INPUTXBAR_OUT16 = 0x1FU,
    /* Trip source is CLBINPUTXBAR out1 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT1 = 0x20U,
    /* Trip source is CLBINPUTXBAR out2 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT2 = 0x21U,
    /* Trip source is CLBINPUTXBAR out3 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT3 = 0x22U,
    /* Trip source is CLBINPUTXBAR out4 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT4 = 0x23U,
    /* Trip source is CLBINPUTXBAR out5 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT5 = 0x24U,
    /* Trip source is CLBINPUTXBAR out6 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT6 = 0x25U,
    /* Trip source is CLBINPUTXBAR out7 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT7 = 0x26U,
    /* Trip source is CLBINPUTXBAR out8 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT8 = 0x27U,
    /* Trip source is CLBINPUTXBAR out9 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT9 = 0x28U,
    /* Trip source is CLBINPUTXBAR out10 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT10 = 0x29U,
    /* Trip source is CLBINPUTXBAR out11 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT11 = 0x2AU,
    /* Trip source is CLBINPUTXBAR out12 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT12 = 0x2BU,
    /* Trip source is CLBINPUTXBAR out13 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT13 = 0x2CU,
    /* Trip source is CLBINPUTXBAR out14 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT14 = 0x2DU,
    /* Trip source is CLBINPUTXBAR out15 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT15 = 0x2EU,
    /* Trip source is CLBINPUTXBAR out16 signal */
    CDD_PWM_DE_TRIPL_SRC_CLBINPUTXBAR_OUT16 = 0x2FU,
    /* INVALID INPUT */
    CDD_PWM_DE_TRIPL_SRC_NONE = 0x30U
}Cdd_Pwm_DETripLowSourceType;

/** \brief Enum that defines the diode emulation trip high sources for an EPWM instance */
typedef enum{
    /* Trip source is CMPSSTRIPH1 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH1 = 0x00U,
    /* Trip source is CMPSSTRIPH2 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH2 = 0x01U,
    /* Trip source is CMPSSTRIPH3 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH3 = 0x02U,
    /* Trip source is CMPSSTRIPH4 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH4 = 0x03U,
    /* Trip source is CMPSSTRIPH5 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH5 = 0x04U,
    /* Trip source is CMPSSTRIPH6 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH6 = 0x05U,
    /* Trip source is CMPSSTRIPH7 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH7 = 0x06U,
    /* Trip source is CMPSSTRIPH8 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH8 = 0x07U,
    /* Trip source is CMPSSTRIPH9 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH9 = 0x08U,
    /* Trip source is CMPSSTRIPH10 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH10 = 0x09U,
    /* Trip source is CMPSSTRIPH11 signal */
    CDD_PWM_DE_TRIPH_SRC_CMPSSTRIPH11 = 0x0AU,
    /* Trip source is INPUTXBAR out1 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT1 = 0x10U,
    /* Trip source is INPUTXBAR out2 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT2 = 0x11U,
    /* Trip source is INPUTXBAR out3 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT3 = 0x12U,
    /* Trip source is INPUTXBAR out4 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT4 = 0x13U,
    /* Trip source is INPUTXBAR out5 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT5 = 0x14U,
    /* Trip source is INPUTXBAR out6 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT6 = 0x15U,
    /* Trip source is INPUTXBAR out7 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT7 = 0x16U,
    /* Trip source is INPUTXBAR out8 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT8 = 0x17U,
    /* Trip source is INPUTXBAR out9 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT9 = 0x18U,
    /* Trip source is INPUTXBAR out10 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT10 = 0x19U,
    /* Trip source is INPUTXBAR out11 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT11 = 0x1AU,
    /* Trip source is INPUTXBAR out12 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT12 = 0x1BU,
    /* Trip source is INPUTXBAR out13 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT13 = 0x1CU,
    /* Trip source is INPUTXBAR out14 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT14 = 0x1DU,
    /* Trip source is INPUTXBAR out15 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT15 = 0x1EU,
    /* Trip source is INPUTXBAR out16 signal */
    CDD_PWM_DE_TRIPH_SRC_INPUTXBAR_OUT16 = 0x1FU,
    /* Trip source is CLBINPUTXBAR out1 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT1 = 0x20U,
    /* Trip source is CLBINPUTXBAR out2 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT2 = 0x21U,
    /* Trip source is CLBINPUTXBAR out3 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT3 = 0x22U,
    /* Trip source is CLBINPUTXBAR out4 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT4 = 0x23U,
    /* Trip source is CLBINPUTXBAR out5 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT5 = 0x24U,
    /* Trip source is CLBINPUTXBAR out6 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT6 = 0x25U,
    /* Trip source is CLBINPUTXBAR out7 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT7 = 0x26U,
    /* Trip source is CLBINPUTXBAR out8 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT8 = 0x27U,
    /* Trip source is CLBINPUTXBAR out9 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT9 = 0x28U,
    /* Trip source is CLBINPUTXBAR out10 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT10 = 0x29U,
    /* Trip source is CLBINPUTXBAR out11 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT11 = 0x2AU,
    /* Trip source is CLBINPUTXBAR out12 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT12 = 0x2BU,
    /* Trip source is CLBINPUTXBAR out13 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT13 = 0x2CU,
    /* Trip source is CLBINPUTXBAR out14 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT14 = 0x2DU,
    /* Trip source is CLBINPUTXBAR out15 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT15 = 0x2EU,
    /* Trip source is CLBINPUTXBAR out16 signal */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_OUT16 = 0x2FU,
    /* INVALID INPUT */
    CDD_PWM_DE_TRIPH_SRC_CLBINPUTXBAR_NONE = 0x30U
}Cdd_Pwm_DETripHighSourceType;

/** \brief MINDB reference signal enumeration */
typedef enum{
    /* Minimum Dead Band Reference signal */
    CDD_PWM_MINDB_SEL_DEPWM =   0x0U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 1 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT1  =   0x1U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 2 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT2  =   0x2U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 3 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT3  =   0x3U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 4 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT4  =   0x4U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 5 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT5  =   0x5U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 6 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT6  =   0x6U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 7 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT7  =   0x7U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 8 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT8  =   0x8U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 9 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT9  =   0x9U,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 10 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT10 =   0xAU,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 11 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT11 =   0xBU,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 12 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT12 =   0xCU,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 13 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT13 =   0xDU,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 14 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT14 =   0xEU,
    /* Minimum Dead Band Reference Signal PWM Output Xbar 15 */
    CDD_PWM_MINDB_SEL_OUTXBAR_OUT15 =   0xFU,
    /* INVALID INPUT */
    CDD_PWM_MINDB_SEL_OUTXBAR_NONE = 0x10U
}Cdd_Pwm_MindbReferenceSignalType;

/** \brief EPWM xbar input enumeration */
typedef enum{
    /* ICL Xbar Out 1 */
    CDD_PWM_MINDB_ICL_XBAR_OUT1 = 0x0U,
    /* ICL Xbar Out 2 */
    CDD_PWM_MINDB_ICL_XBAR_OUT2 = 0x1U,
    /* ICL Xbar Out 3 */
    CDD_PWM_MINDB_ICL_XBAR_OUT3 = 0x2U,
    /* ICL Xbar Out 4 */
    CDD_PWM_MINDB_ICL_XBAR_OUT4 = 0x3U,
    /* ICL Xbar Out 5 */
    CDD_PWM_MINDB_ICL_XBAR_OUT5 = 0x4U,
    /* ICL Xbar Out 6 */
    CDD_PWM_MINDB_ICL_XBAR_OUT6 = 0x5U,
    /* ICL Xbar Out 7 */
    CDD_PWM_MINDB_ICL_XBAR_OUT7 = 0x6U,
    /* ICL Xbar Out 8 */
    CDD_PWM_MINDB_ICL_XBAR_OUT8 = 0x7U,
    /* ICL Xbar Out 9 */
    CDD_PWM_MINDB_ICL_XBAR_OUT9 = 0x8U,
    /* ICL Xbar Out 10 */
    CDD_PWM_MINDB_ICL_XBAR_OUT10 = 0x9U,
    /* ICL Xbar Out 11 */
    CDD_PWM_MINDB_ICL_XBAR_OUT11 = 0xAU,
    /* ICL Xbar Out 12 */
    CDD_PWM_MINDB_ICL_XBAR_OUT12 = 0xBU,
    /* ICL Xbar Out 13 */
    CDD_PWM_MINDB_ICL_XBAR_OUT13 = 0xCU,
    /* ICL Xbar Out 14 */
    CDD_PWM_MINDB_ICL_XBAR_OUT14 = 0xDU,
    /* ICL Xbar Out 15 */
    CDD_PWM_MINDB_ICL_XBAR_OUT15 = 0xEU,
    /* ICL Xbar Out 16 */
    CDD_PWM_MINDB_ICL_XBAR_OUT16 = 0xFU,
    /* None */
    CDD_PWM_MINDB_ICL_XBAR_NONE = 0x10U
}Cdd_Pwm_XbarInputType;

/** \brief LUT Decx enumeration */
typedef enum{
    /* LUT output PWMA/B value on decoding 0 */
    CDD_PWM_MINDB_ICL_LUT_DEC0 = 0U,
    /* LUT output PWMA/B value on decoding 1 */
    CDD_PWM_MINDB_ICL_LUT_DEC1 = 1U,
    /* LUT output PWMA/B value on decoding 2 */
    CDD_PWM_MINDB_ICL_LUT_DEC2 = 2U,
    /* LUT output PWMA/B value on decoding 3 */
    CDD_PWM_MINDB_ICL_LUT_DEC3 = 3U,
    /* LUT output PWMA/B value on decoding 4 */
    CDD_PWM_MINDB_ICL_LUT_DEC4 = 4U,
    /* LUT output PWMA/B value on decoding 5 */
    CDD_PWM_MINDB_ICL_LUT_DEC5 = 5U,
    /* LUT output PWMA/B value on decoding 6 */
    CDD_PWM_MINDB_ICL_LUT_DEC6 = 6U,
    /* LUT output PWMA/B value on decoding 7 */
    CDD_PWM_MINDB_ICL_LUT_DEC7 = 7U,
    /* Invalid Input */
    CDD_PWM_MINDB_ICL_LUT_NONE = 8U
}Cdd_Pwm_LutDecXType;

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



/* Declaration of the trip-zone notification function */
extern void Cdd_Pwm_Hw0TzNotification(uint16 TripZoneFlag);

extern void Cdd_Pwm_Hw1TzNotification(uint16 TripZoneFlag);

extern void Cdd_Pwm_Hw2TzNotification(uint16 TripZoneFlag);

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
