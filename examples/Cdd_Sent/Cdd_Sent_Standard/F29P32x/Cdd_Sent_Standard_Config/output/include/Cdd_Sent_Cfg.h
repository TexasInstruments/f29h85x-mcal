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
#define CDD_SENT_CFG_MAJOR_VERSION    (3U) //!< CDDSENT configuration Major Version.
#define CDD_SENT_CFG_MINOR_VERSION    (1U) //!< CDDSENT configuration Minor Version.
#define CDD_SENT_CFG_PATCH_VERSION    (0U) //!< CDDSENT configuration Patch Version.

/*
 *Design: MCAL-28714
 */
/** \brief CDDSENT Build Variant. Build Variants.(i.e Pre-compile,Post-Build or Link time)*/
#define CDD_SENT_CFG_PRE_COMPILE_VARIANT          (STD_ON)

/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define CDD_SENT_CFG_DEM_ENABLE    (STD_ON)
/*
 *Design: MCAL-28684
 */

#define CDD_SENT_E_HARDWARE_ERROR  (DemConf_DemEventParameter_CDD_SENT_E_HARDWARE_ERROR)



/** \brief Enable/Disable DEV error detection.*/
/*
 *Design: MCAL-28662,MCAL-28661
 */
#define CDD_SENT_CFG_DEV_ERROR_DETECT             (STD_ON)


/** \brief Enable/Disable CddSent_GetVersionInfo().*/

/*
 *Design: MCAL-28663
 */
#define CDD_SENT_CFG_GET_VERSION_INFO_API         (STD_ON)

/** \brief Enable/Disable Enable Pdu().*/

/*
 *Design: MCAL-28717
 */
#define CDD_SENT_INTEGRATION_WITH_ASR_COMSTACK_ENABLE      (STD_OFF)



/** \brief Enable/Disable MTP Mode.*/
#define CDD_SENT_ENABLE_MTP_MODE (STD_OFF)

/*
 *Design: MCAL-28685
 */
/** \brief Defines for symbolic names for the CddSent HW uint ID's (CddSentHWUnitId) */
#define Cdd_SentConf_CddSentController_CddSentController_0 (0U) /*~ASR~*/

/*
 *Design: MCAL-28731
 */
/** \brief Defines for symbolic names for the channelobjectid's */
#define Cdd_SentConf_CddSentChannelObject_CddSentChannelObject_0 1U			/*~ASR~*/
#define Cdd_SentConf_CddSentChannelObject_CddSentChannelObject_1 2U			/*~ASR~*/

/*
 *Design: MCAL-28671
 */
/** \brief CddSent Controller Instance interrupt definition */
#define CDD_SENT4_ENABLE
#define CDD_SENT4_ISR_CAT1_INT

/*
 *Design: MCAL-28666
 */   
/** \brief Max number of HW units defined defined */
#define SENT_MAX_HW_UNITS                      (6U)

/*
 *Design: MCAL-28669
 */ 
/** \brief No. of HW units defined in CddSent Driver */
#define SENT_CFG_NO_OF_HW_UNITS            (1U)

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
#define SENT_ENABLE_INTERRUPT_SOURCES    (uint32)((0x00000000U)\
                                    |(0UL<<1U)\
                                    |(0UL<<2U)\
                                    |(0UL<<3U)\
                                    |(0UL<<4U)\
                                    |(1UL<<5U)\
                                    |(0UL<<6U)\
                                    |(0UL<<7U)\
                                    |(0UL<<8U)\
                                    |(0UL<<9U)\
                                    |(0UL<<10U)\
                                    |(0UL<<11U)\
                                    |(0UL<<12U)\
                                    |(0UL<<13U)\
                                    |(0UL<<14U)\
                                    |(0UL<<15U)\
                                    |(0UL<<16U)\
                                    |(0UL<<17U)\
                                    |(0UL<<18U)\
                                    |(0UL<<19U)\
                                    |(0UL<<20U)\
                                    |(0UL<<21U)\
                                    |(0UL<<22U)\
                                    |(1UL<<23U)\
                                    |(0UL<<24U)\
                                    |(0UL<<25U)\
                                    |(0UL<<26U)\
                                    |(0UL<<27U)\
                                    |(0UL<<28U)\
                                    |(0UL<<29U)\
                                    |(0UL<<30U)\
                                    )

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/* Forward declaration of Cdd_Sent configuration structure */
struct Cdd_Sent_ConfigType_s;

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
