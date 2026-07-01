/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2026 Texas Instruments Incorporated
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
 *  File:       Cdd_Dma_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration header file                                              
 *********************************************************************************************************************/
#ifndef CDD_DMA_CFG_H
#define CDD_DMA_CFG_H
/** \addtogroup CDD_DMA
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif


/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Dma_Cbk.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS 
/* CDD DMA Driver Configuration SW Version Info */

#define CDD_DMA_CFG_MAJOR_VERSION           (1U)
#define CDD_DMA_CFG_MINOR_VERSION           (1U)
#define CDD_DMA_CFG_PATCH_VERSION           (0U)

/* CDD DMA Build Variant. Pre-compile build Variant */
#define CDD_DMA_PRE_COMPILE_VARIANT              STD_ON

/** \brief Pre compile variant configuration */
#define CDD_DMA_PRE_COMPILE_VARIANT_CONFIG       Cdd_Dma_Config

/** \brief CDD DMA developement error detection */
#define CDD_DMA_DEV_ERROR_DETECT                 STD_ON
/** \brief Switches the Cdd_Dma_GetVersionInfo function ON or OFF */
#define CDD_DMA_GET_VERSION_INFO_API             STD_ON
/** \brief Enables locking of DMA configuration registers to prevent accidental modification during runtime */
#define CDD_DMA_LOCK_CONFIGURATION               STD_OFF
/** \brief Macro to define the number of DMA instances configured */
#define CDD_DMA_HW_INSTANCE_MAX             ((uint8)2U)

/** \brief Macro to define the number of DMA channels configured */
#define CDD_DMA_CHANNEL_MAX                 ((uint8)10U)

/** \brief Macro to define the number of DMA instances configured */
#define CDD_DMA_HW_INSTANCE_COUNT             ((uint8)1U)

/** \brief Macro to define the number of DMA channels configured */
#define CDD_DMA_CHANNEL_COUNT                 ((uint8)1U)

 /** \brief Macro to define the number of MPU regions configured */
#define CDD_DMA_MPU_REGION_COUNT         0U

/** \brief Maximum value for DMA burst size */
#define CDD_DMA_MAX_BURST_SIZE (256U)

/** \brief Maximum value for DMA transfer size and wrap size */
#define CDD_DMA_MAX_TRANSFER_SIZE (65536U)

/* Design: MCAL-39315 */
/*****************************************************************************
 * \brief Symbolic names of the DMA instances
 *****************************************************************************/
#define Cdd_DmaConf_CddDmaHwInstance_CddDmaHwInstance_0          0U	         /*~ASR~*/

/* Design: MCAL-39313 */
/*****************************************************************************
 * \brief Symbolic names of the DMA channels
 *****************************************************************************/ 
#define Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0          0U	         /*~ASR~*/

/* Design: MCAL-39314 */
/*****************************************************************************
 * \brief Symbolic names of the DMA MPU regions
 *****************************************************************************/

/** \brief Cdd Dma Channel interrupt definition */
#define CDD_DMA_RTDMA1_CH1_ENABLE
#define CDD_DMA_RTDMA1_CH1_ISR_CAT1_INT
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/* Forward declaration of Cdd_Dma configuration structure */
struct Cdd_Dma_ConfigTag;

/* Design: MCAL-39291 */
/** \brief Peripheral event trigger source select type */
typedef enum
{
    CDD_DMA_TRIGGER_SOFTWARE                   = 0,   /*!< \brief  TRIGGER SOFTWARE */
    CDD_DMA_TRIGGER_ADCA1                      = 1,   /*!< \brief  TRIGGER ADCA1 */
    CDD_DMA_TRIGGER_ADCA2                      = 2,   /*!< \brief  TRIGGER ADCA2 */
    CDD_DMA_TRIGGER_ADCA3                      = 3,   /*!< \brief  TRIGGER ADCA3 */
    CDD_DMA_TRIGGER_ADCA4                      = 4,   /*!< \brief  TRIGGER ADCA4 */
    CDD_DMA_TRIGGER_ADCAEVT                    = 5,   /*!< \brief  TRIGGER ADCAEVT */
    CDD_DMA_TRIGGER_ADCB1                      = 6,   /*!< \brief  TRIGGER ADCB1 */
    CDD_DMA_TRIGGER_ADCB2                      = 7,   /*!< \brief  TRIGGER ADCB2 */
    CDD_DMA_TRIGGER_ADCB3                      = 8,   /*!< \brief  TRIGGER ADCB3 */
    CDD_DMA_TRIGGER_ADCB4                      = 9,   /*!< \brief  TRIGGER ADCB4 */
    CDD_DMA_TRIGGER_ADCBEVT                    = 10,  /*!< \brief  TRIGGER ADCBEVT */
    CDD_DMA_TRIGGER_ADCC1                      = 11,  /*!< \brief  TRIGGER ADCC1 */
    CDD_DMA_TRIGGER_ADCC2                      = 12,  /*!< \brief  TRIGGER ADCC2 */
    CDD_DMA_TRIGGER_ADCC3                      = 13,  /*!< \brief  TRIGGER ADCC3 */
    CDD_DMA_TRIGGER_ADCC4                      = 14,  /*!< \brief  TRIGGER ADCC4 */
    CDD_DMA_TRIGGER_ADCCEVT                    = 15,  /*!< \brief  TRIGGER ADCCEVT */
    CDD_DMA_TRIGGER_ADCD1                      = 16,  /*!< \brief  TRIGGER ADCD1 */
    CDD_DMA_TRIGGER_ADCD2                      = 17,  /*!< \brief  TRIGGER ADCD2 */
    CDD_DMA_TRIGGER_ADCD3                      = 18,  /*!< \brief  TRIGGER ADCD3 */
    CDD_DMA_TRIGGER_ADCD4                      = 19,  /*!< \brief  TRIGGER ADCD4 */
    CDD_DMA_TRIGGER_ADCDEVT                    = 20,  /*!< \brief  TRIGGER ADCDEVT */
    CDD_DMA_TRIGGER_ADCE1                      = 21,  /*!< \brief  TRIGGER ADCE1 */
    CDD_DMA_TRIGGER_ADCE2                      = 22,  /*!< \brief  TRIGGER ADCE2 */
    CDD_DMA_TRIGGER_ADCE3                      = 23,  /*!< \brief  TRIGGER ADCE3 */
    CDD_DMA_TRIGGER_ADCE4                      = 24,  /*!< \brief  TRIGGER ADCE4 */
    CDD_DMA_TRIGGER_ADCEEVT                    = 25,  /*!< \brief  TRIGGER ADCEEVT */
    CDD_DMA_TRIGGER_CPU1_XINT1                 = 31,  /*!< \brief  TRIGGER CPU1 XINT1 */
    CDD_DMA_TRIGGER_CPU1_XINT2                 = 32,  /*!< \brief  TRIGGER CPU1 XINT2 */
    CDD_DMA_TRIGGER_CPU1_XINT3                 = 33,  /*!< \brief  TRIGGER CPU1 XINT3 */
    CDD_DMA_TRIGGER_CPU1_XINT4                 = 34,  /*!< \brief  TRIGGER CPU1 XINT4 */
    CDD_DMA_TRIGGER_CPU1_XINT5                 = 35,  /*!< \brief  TRIGGER CPU1 XINT5 */
    CDD_DMA_TRIGGER_CPU2_XINT1                 = 36,  /*!< \brief  TRIGGER CPU2 XINT1 */
    CDD_DMA_TRIGGER_CPU2_XINT2                 = 37,  /*!< \brief  TRIGGER CPU2 XINT2 */
    CDD_DMA_TRIGGER_CPU2_XINT3                 = 38,  /*!< \brief  TRIGGER CPU2 XINT3 */
    CDD_DMA_TRIGGER_CPU2_XINT4                 = 39,  /*!< \brief  TRIGGER CPU2 XINT4 */
    CDD_DMA_TRIGGER_CPU2_XINT5                 = 40,  /*!< \brief  TRIGGER CPU2 XINT5 */
    CDD_DMA_TRIGGER_CPU3_XINT1                 = 41,  /*!< \brief  TRIGGER CPU3 XINT1 */
    CDD_DMA_TRIGGER_CPU3_XINT2                 = 42,  /*!< \brief  TRIGGER CPU3 XINT2 */
    CDD_DMA_TRIGGER_CPU3_XINT3                 = 43,  /*!< \brief  TRIGGER CPU3 XINT3 */
    CDD_DMA_TRIGGER_CPU3_XINT4                 = 44,  /*!< \brief  TRIGGER CPU3 XINT4 */
    CDD_DMA_TRIGGER_CPU3_XINT5                 = 45,  /*!< \brief  TRIGGER CPU3 XINT5 */
    CDD_DMA_TRIGGER_EPWM1SOCA                  = 46,  /*!< \brief  TRIGGER EPWM1SOCA */
    CDD_DMA_TRIGGER_EPWM1SOCB                  = 47,  /*!< \brief  TRIGGER EPWM1SOCB */
    CDD_DMA_TRIGGER_EPWM2SOCA                  = 48,  /*!< \brief  TRIGGER EPWM2SOCA */
    CDD_DMA_TRIGGER_EPWM2SOCB                  = 49,  /*!< \brief  TRIGGER EPWM2SOCB */
    CDD_DMA_TRIGGER_EPWM3SOCA                  = 50,  /*!< \brief  TRIGGER EPWM3SOCA */
    CDD_DMA_TRIGGER_EPWM3SOCB                  = 51,  /*!< \brief  TRIGGER EPWM3SOCB */
    CDD_DMA_TRIGGER_EPWM4SOCA                  = 52,  /*!< \brief  TRIGGER EPWM4SOCA */
    CDD_DMA_TRIGGER_EPWM4SOCB                  = 53,  /*!< \brief  TRIGGER EPWM4SOCB */
    CDD_DMA_TRIGGER_EPWM5SOCA                  = 54,  /*!< \brief  TRIGGER EPWM5SOCA */
    CDD_DMA_TRIGGER_EPWM5SOCB                  = 55,  /*!< \brief  TRIGGER EPWM5SOCB */
    CDD_DMA_TRIGGER_EPWM6SOCA                  = 56,  /*!< \brief  TRIGGER EPWM6SOCA */
    CDD_DMA_TRIGGER_EPWM6SOCB                  = 57,  /*!< \brief  TRIGGER EPWM6SOCB */
    CDD_DMA_TRIGGER_EPWM7SOCA                  = 58,  /*!< \brief  TRIGGER EPWM7SOCA */
    CDD_DMA_TRIGGER_EPWM7SOCB                  = 59,  /*!< \brief  TRIGGER EPWM7SOCB */
    CDD_DMA_TRIGGER_EPWM8SOCA                  = 60,  /*!< \brief  TRIGGER EPWM8SOCA */
    CDD_DMA_TRIGGER_EPWM8SOCB                  = 61,  /*!< \brief  TRIGGER EPWM8SOCB */
    CDD_DMA_TRIGGER_EPWM9SOCA                  = 62,  /*!< \brief  TRIGGER EPWM9SOCA */
    CDD_DMA_TRIGGER_EPWM9SOCB                  = 63,  /*!< \brief  TRIGGER EPWM9SOCB */
    CDD_DMA_TRIGGER_EPWM10SOCA                 = 64,  /*!< \brief  TRIGGER EPWM10SOCA */
    CDD_DMA_TRIGGER_EPWM10SOCB                 = 65,  /*!< \brief  TRIGGER EPWM10SOCB */
    CDD_DMA_TRIGGER_EPWM11SOCA                 = 66,  /*!< \brief  TRIGGER EPWM11SOCA */
    CDD_DMA_TRIGGER_EPWM11SOCB                 = 67,  /*!< \brief  TRIGGER EPWM11SOCB */
    CDD_DMA_TRIGGER_EPWM12SOCA                 = 68,  /*!< \brief  TRIGGER EPWM12SOCA */
    CDD_DMA_TRIGGER_EPWM12SOCB                 = 69,  /*!< \brief  TRIGGER EPWM12SOCB */
    CDD_DMA_TRIGGER_EPWM13SOCA                 = 70,  /*!< \brief  TRIGGER EPWM13SOCA */
    CDD_DMA_TRIGGER_EPWM13SOCB                 = 71,  /*!< \brief  TRIGGER EPWM13SOCB */
    CDD_DMA_TRIGGER_EPWM14SOCA                 = 72,  /*!< \brief  TRIGGER EPWM14SOCA */
    CDD_DMA_TRIGGER_EPWM14SOCB                 = 73,  /*!< \brief  TRIGGER EPWM14SOCB */
    CDD_DMA_TRIGGER_EPWM15SOCA                 = 74,  /*!< \brief  TRIGGER EPWM15SOCA */
    CDD_DMA_TRIGGER_EPWM15SOCB                 = 75,  /*!< \brief  TRIGGER EPWM15SOCB */
    CDD_DMA_TRIGGER_EPWM16SOCA                 = 76,  /*!< \brief  TRIGGER EPWM16SOCA */
    CDD_DMA_TRIGGER_EPWM16SOCB                 = 77,  /*!< \brief  TRIGGER EPWM16SOCB */
    CDD_DMA_TRIGGER_EPWM17SOCA                 = 78,  /*!< \brief  TRIGGER EPWM17SOCA */
    CDD_DMA_TRIGGER_EPWM17SOCB                 = 79,  /*!< \brief  TRIGGER EPWM17SOCB */
    CDD_DMA_TRIGGER_EPWM18SOCA                 = 80,  /*!< \brief  TRIGGER EPWM18SOCA */
    CDD_DMA_TRIGGER_EPWM18SOCB                 = 81,  /*!< \brief  TRIGGER EPWM18SOCB */
    CDD_DMA_TRIGGER_TINT0                      = 94,  /*!< \brief  TRIGGER CPU1 TINT0 */
    CDD_DMA_TRIGGER_TINT1                      = 95,  /*!< \brief  TRIGGER CPU1 TINT1 */
    CDD_DMA_TRIGGER_TINT2                      = 96,  /*!< \brief  TRIGGER CPU1 TINT2 */
    CDD_DMA_TRIGGER_CPU2_TINT0                 = 97,  /*!< \brief  TRIGGER CPU2 TINT0 */
    CDD_DMA_TRIGGER_CPU2_TINT1                 = 98,  /*!< \brief  TRIGGER CPU2 TINT1 */
    CDD_DMA_TRIGGER_CPU2_TINT2                 = 99,  /*!< \brief  TRIGGER CPU2 TINT2 */
    CDD_DMA_TRIGGER_CPU3_TINT0                 = 100, /*!< \brief  TRIGGER CPU3 TINT0 */
    CDD_DMA_TRIGGER_CPU3_TINT1                 = 101, /*!< \brief  TRIGGER CPU3 TINT1 */
    CDD_DMA_TRIGGER_CPU3_TINT2                 = 102, /*!< \brief  TRIGGER CPU3 TINT2 */
    CDD_DMA_TRIGGER_ECAP1                      = 112, /*!< \brief  TRIGGER ECAP1 */
    CDD_DMA_TRIGGER_ECAP2                      = 113, /*!< \brief  TRIGGER ECAP2 */
    CDD_DMA_TRIGGER_ECAP3                      = 114, /*!< \brief  TRIGGER ECAP3 */
    CDD_DMA_TRIGGER_ECAP4                      = 115, /*!< \brief  TRIGGER ECAP4 */
    CDD_DMA_TRIGGER_ECAP5                      = 116, /*!< \brief  TRIGGER ECAP5 */
    CDD_DMA_TRIGGER_ECAP6                      = 117, /*!< \brief  TRIGGER ECAP6 */
    CDD_DMA_TRIGGER_LINATX                     = 120, /*!< \brief  TRIGGER LINATX */
    CDD_DMA_TRIGGER_LINARX                     = 121, /*!< \brief  TRIGGER LINARX */
    CDD_DMA_TRIGGER_LINBTX                     = 122, /*!< \brief  TRIGGER LINBTX */
    CDD_DMA_TRIGGER_LINBRX                     = 123, /*!< \brief  TRIGGER LINBRX */
    CDD_DMA_TRIGGER_SYNC                       = 124, /*!< \brief  TRIGGER SYNC */
    CDD_DMA_TRIGGER_SPIATX                     = 125, /*!< \brief  TRIGGER SPIATX */
    CDD_DMA_TRIGGER_SPIARX                     = 126, /*!< \brief  TRIGGER SPIARX */
    CDD_DMA_TRIGGER_SPIBTX                     = 127, /*!< \brief  TRIGGER SPIBTX */
    CDD_DMA_TRIGGER_SPIBRX                     = 128, /*!< \brief  TRIGGER SPIBRX */
    CDD_DMA_TRIGGER_SPICTX                     = 129, /*!< \brief  TRIGGER SPICTX */
    CDD_DMA_TRIGGER_SPICRX                     = 130, /*!< \brief  TRIGGER SPICRX */
    CDD_DMA_TRIGGER_SPIDTX                     = 131, /*!< \brief  TRIGGER SPIDTX */
    CDD_DMA_TRIGGER_SPIDRX                     = 132, /*!< \brief  TRIGGER SPIDRX */
    CDD_DMA_TRIGGER_SPIETX                     = 133, /*!< \brief  TRIGGER SPIETX */
    CDD_DMA_TRIGGER_SPIERX                     = 134, /*!< \brief  TRIGGER SPIERX */
    CDD_DMA_TRIGGER_CLB1INT                    = 135, /*!< \brief  TRIGGER CLB1INT */
    CDD_DMA_TRIGGER_CLB2INT                    = 136, /*!< \brief  TRIGGER CLB2INT */
    CDD_DMA_TRIGGER_CLB3INT                    = 137, /*!< \brief  TRIGGER CLB3INT */
    CDD_DMA_TRIGGER_CLB4INT                    = 138, /*!< \brief  TRIGGER CLB4INT */
    CDD_DMA_TRIGGER_CLB5INT                    = 139, /*!< \brief  TRIGGER CLB5INT */
    CDD_DMA_TRIGGER_CLB6INT                    = 140, /*!< \brief  TRIGGER CLB6INT */
    CDD_DMA_TRIGGER_FSITXA                     = 143, /*!< \brief  TRIGGER FSITXA */
    CDD_DMA_TRIGGER_FSIRXA                     = 144, /*!< \brief  TRIGGER FSIRXA */
    CDD_DMA_TRIGGER_FSIA_DATA_TAG_MATCH        = 145, /*!< \brief  TRIGGER FSIA DATA TAG MATCH */
    CDD_DMA_TRIGGER_FSIA_PING_TAG_MATCH        = 146, /*!< \brief  TRIGGER FSIA PING TAG MATCH */
    CDD_DMA_TRIGGER_FSIRXB                     = 148, /*!< \brief  TRIGGER FSIRXB */
    CDD_DMA_TRIGGER_FSITXB                     = 147, /*!< \brief  TRIGGER FSITXB */
    CDD_DMA_TRIGGER_FSIB_DATA_TAG_MATCH        = 149, /*!< \brief  TRIGGER FSIB DATA TAG MATCH */
    CDD_DMA_TRIGGER_FSIB_PING_TAG_MATCH        = 150, /*!< \brief  TRIGGER FSIB PING TAG MATCH */
    CDD_DMA_TRIGGER_FSIRXC                     = 152, /*!< \brief  TRIGGER FSIRXC */
    CDD_DMA_TRIGGER_FSITXC                     = 151, /*!< \brief  TRIGGER FSITXC */
    CDD_DMA_TRIGGER_FSIC_DATA_TAG_MATCH        = 153, /*!< \brief  TRIGGER FSIC DATA TAG MATCH */
    CDD_DMA_TRIGGER_FSIC_PING_TAG_MATCH        = 154, /*!< \brief  TRIGGER FSIC PING TAG MATCH */
    CDD_DMA_TRIGGER_FSITXD                     = 155, /*!< \brief  TRIGGER FSITXD */
    CDD_DMA_TRIGGER_FSIRXD                     = 156, /*!< \brief  TRIGGER FSIRXD */
    CDD_DMA_TRIGGER_FSID_DATA_TAG_MATCH        = 157, /*!< \brief  TRIGGER FSID DATA TAG MATCH */
    CDD_DMA_TRIGGER_FSID_PING_TAG_MATCH        = 158, /*!< \brief  TRIGGER FSID PING TAG MATCH */
    CDD_DMA_TRIGGER_CPU1_DLT                   = 161, /*!< \brief  TRIGGER CPU1 DLT */
    CDD_DMA_TRIGGER_CPU3_DLT                   = 163, /*!< \brief  TRIGGER CPU3 DLT */
    CDD_DMA_TRIGGER_CPU2_DLT                   = 162, /*!< \brief  TRIGGER CPU2 DLT */
    CDD_DMA_TRIGGER_UARTARX                    = 167, /*!< \brief  TRIGGER UARTARX */
    CDD_DMA_TRIGGER_UARTATX                    = 168, /*!< \brief  TRIGGER UARTATX */
    CDD_DMA_TRIGGER_UARTBTX                    = 169, /*!< \brief  TRIGGER UARTBTX */
    CDD_DMA_TRIGGER_UARTBRX                    = 170, /*!< \brief  TRIGGER UARTBRX */
    CDD_DMA_TRIGGER_UARTCTX                    = 171, /*!< \brief  TRIGGER UARTCTX */
    CDD_DMA_TRIGGER_UARTCRX                    = 172, /*!< \brief  TRIGGER UARTCRX */
    CDD_DMA_TRIGGER_UARTDTX                    = 173, /*!< \brief  TRIGGER UARTDTX */
    CDD_DMA_TRIGGER_UARTDRX                    = 174, /*!< \brief  TRIGGER UARTDRX */
    CDD_DMA_TRIGGER_UARTETX                    = 175, /*!< \brief  TRIGGER UARTETX */
    CDD_DMA_TRIGGER_UARTERX                    = 176, /*!< \brief  TRIGGER UARTERX */
    CDD_DMA_TRIGGER_UARTFTX                    = 177, /*!< \brief  TRIGGER UARTFTX */
    CDD_DMA_TRIGGER_UARTFRX                    = 178, /*!< \brief  TRIGGER UARTFRX */
    CDD_DMA_TRIGGER_DTHE_SHA_DMA_S_CTXIN_REQ   = 179, /*!< \brief  TRIGGER DTHE SHA DMA S CTXIN REQ */
    CDD_DMA_TRIGGER_DTHE_SHA_DMA_S_DATAIN_REQ  = 180, /*!< \brief  TRIGGER DTHE SHA DMA S DATAIN REQ */
    CDD_DMA_TRIGGER_DTHE_SHA_DMA_S_CTXOUT_REQ  = 181, /*!< \brief  TRIGGER DTHE SHA DMA S CTXOUT REQ */
    CDD_DMA_TRIGGER_DTHE_SHA_DMA_P_CTXIN_REQ   = 182, /*!< \brief  TRIGGER DTHE SHA DMA P CTXIN REQ */
    CDD_DMA_TRIGGER_DTHE_SHA_DMA_P_DATAIN_REQ  = 183, /*!< \brief  TRIGGER DTHE SHA DMA P DATAIN REQ */
    CDD_DMA_TRIGGER_DTHE_SHA_DMA_P_CTXOUT_REQ  = 184, /*!< \brief  TRIGGER DTHE SHA DMA P CTXOUT REQ */
    CDD_DMA_TRIGGER_DTHE_AES_DMA_S_CTXIN_REQ   = 185, /*!< \brief  TRIGGER DTHE AES DMA S CTXIN REQ */
    CDD_DMA_TRIGGER_DTHE_AES_DMA_S_DATAIN_REQ  = 186, /*!< \brief  TRIGGER DTHE AES DMA S DATAIN REQ */
    CDD_DMA_TRIGGER_DTHE_AES_DMA_S_DATAOUT_REQ = 187, /*!< \brief  TRIGGER DTHE AES DMA S DATAOUT REQ */
    CDD_DMA_TRIGGER_DTHE_AES_DMA_S_CTXOUT_REQ  = 188, /*!< \brief  TRIGGER DTHE AES DMA S CTXOUT REQ */
    CDD_DMA_TRIGGER_DTHE_AES_DMA_P_CTXIN_REQ   = 189, /*!< \brief  TRIGGER DTHE AES DMA P CTXIN REQ */
    CDD_DMA_TRIGGER_DTHE_AES_DMA_P_DATAIN_REQ  = 190, /*!< \brief  TRIGGER DTHE AES DMA P DATAIN REQ */
    CDD_DMA_TRIGGER_DTHE_AES_DMA_P_DATAOUT_REQ = 191, /*!< \brief  TRIGGER DTHE AES DMA P DATAOUT REQ */
    CDD_DMA_TRIGGER_DTHE_AES_DMA_P_CTXOUT_REQ  = 192, /*!< \brief  TRIGGER DTHE AES DMA P CTXOUT REQ */
    CDD_DMA_TRIGGER_DTHE_SM3_CTXIN_REQ         = 193, /*!< \brief  TRIGGER DTHE SM3 CTXIN REQ */
    CDD_DMA_TRIGGER_DTHE_SM3_DATAIN_REQ        = 194, /*!< \brief  TRIGGER DTHE SM3 DATAIN REQ */
    CDD_DMA_TRIGGER_DTHE_SM3_CTXOUT_REQ        = 195, /*!< \brief  TRIGGER DTHE SM3 CTXOUT REQ */
    CDD_DMA_TRIGGER_DTHE_SM4_CTXIN_REQ         = 196, /*!< \brief  TRIGGER DTHE SM4 CTXIN REQ */
    CDD_DMA_TRIGGER_DTHE_SM4_DATAIN_REQ        = 197, /*!< \brief  TRIGGER DTHE SM4 DATAIN REQ */
    CDD_DMA_TRIGGER_DTHE_SM4_DATAOUT_REQ       = 198, /*!< \brief  TRIGGER DTHE SM4 DATAOUT REQ */
    CDD_DMA_TRIGGER_DTHE_SM4_CTXOUT_REQ        = 199, /*!< \brief  TRIGGER DTHE SM4 CTXOUT REQ */
    CDD_DMA_TRIGGER_EPG                        = 200, /*!< \brief  TRIGGER EPG */
    CDD_DMA_TRIGGER_SDFM1FLT1                  = 201, /*!< \brief  TRIGGER SDFM1FLT1 */
    CDD_DMA_TRIGGER_SDFM1FLT2                  = 202, /*!< \brief  TRIGGER SDFM1FLT2 */
    CDD_DMA_TRIGGER_SDFM1FLT3                  = 203, /*!< \brief  TRIGGER SDFM1FLT3 */
    CDD_DMA_TRIGGER_SDFM1FLT4                  = 204, /*!< \brief  TRIGGER SDFM1FLT4 */
    CDD_DMA_TRIGGER_SDFM2FLT1                  = 205, /*!< \brief  TRIGGER SDFM2FLT1 */
    CDD_DMA_TRIGGER_SDFM2FLT2                  = 206, /*!< \brief  TRIGGER SDFM2FLT2 */
    CDD_DMA_TRIGGER_SDFM2FLT3                  = 207, /*!< \brief  TRIGGER SDFM2FLT3 */
    CDD_DMA_TRIGGER_SDFM2FLT4                  = 208, /*!< \brief  TRIGGER SDFM2FLT4 */
    CDD_DMA_TRIGGER_SDFM3FLT1                  = 209, /*!< \brief  TRIGGER SDFM3FLT1 */
    CDD_DMA_TRIGGER_SDFM3FLT2                  = 210, /*!< \brief  TRIGGER SDFM3FLT2 */
    CDD_DMA_TRIGGER_SDFM3FLT3                  = 211, /*!< \brief  TRIGGER SDFM3FLT3 */
    CDD_DMA_TRIGGER_SDFM3FLT4                  = 212, /*!< \brief  TRIGGER SDFM3FLT4 */
    CDD_DMA_TRIGGER_SDFM4FLT1                  = 213, /*!< \brief  TRIGGER SDFM4FLT1 */
    CDD_DMA_TRIGGER_SDFM4FLT2                  = 214, /*!< \brief  TRIGGER SDFM4FLT2 */
    CDD_DMA_TRIGGER_SDFM4FLT3                  = 215, /*!< \brief  TRIGGER SDFM4FLT3 */
    CDD_DMA_TRIGGER_SDFM4FLT4                  = 216, /*!< \brief  TRIGGER SDFM4FLT4 */
    CDD_DMA_TRIGGER_SENT1                      = 217, /*!< \brief  TRIGGER SENT1 */
    CDD_DMA_TRIGGER_SENT2                      = 218, /*!< \brief  TRIGGER SENT2 */
    CDD_DMA_TRIGGER_SENT3                      = 219, /*!< \brief  TRIGGER SENT3 */
    CDD_DMA_TRIGGER_SENT4                      = 220, /*!< \brief  TRIGGER SENT4 */
    CDD_DMA_TRIGGER_SENT5                      = 221, /*!< \brief  TRIGGER SENT5 */
    CDD_DMA_TRIGGER_SENT6                      = 222, /*!< \brief  TRIGGER SENT6 */
    CDD_DMA_TRIGGER_WADI1                      = 223, /*!< \brief  TRIGGER WADI1 */
    CDD_DMA_TRIGGER_WADI2                      = 224, /*!< \brief  TRIGGER WADI2 */
    CDD_DMA_TRIGGER_RTDMA_CH1INT               = 240, /*!< \brief  TRIGGER RTDMA CH1INT */
    CDD_DMA_TRIGGER_RTDMA_CH2INT               = 241, /*!< \brief  TRIGGER RTDMA CH2INT */
    CDD_DMA_TRIGGER_RTDMA_CH3INT               = 242, /*!< \brief  TRIGGER RTDMA CH3INT */
    CDD_DMA_TRIGGER_RTDMA_CH4INT               = 243, /*!< \brief  TRIGGER RTDMA CH4INT */
    CDD_DMA_TRIGGER_RTDMA_CH5INT               = 244, /*!< \brief  TRIGGER RTDMA CH5INT */
    CDD_DMA_TRIGGER_RTDMA_CH6INT               = 245, /*!< \brief  TRIGGER RTDMA CH6INT */
    CDD_DMA_TRIGGER_RTDMA_CH7INT               = 246, /*!< \brief  TRIGGER RTDMA CH7INT */
    CDD_DMA_TRIGGER_RTDMA_CH8INT               = 247, /*!< \brief  TRIGGER RTDMA CH8INT */
    CDD_DMA_TRIGGER_RTDMA_CH9INT               = 248, /*!< \brief  TRIGGER RTDMA CH9INT */
    CDD_DMA_TRIGGER_RTDMA_CH10INT              = 249  /*!< \brief  TRIGGER RTDMA CH10INT */
} Cdd_Dma_PeriEvtTriggerSrcType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/** \brief  Cdd_Dma configuration structure extern declaration */
extern CONST(struct Cdd_Dma_ConfigTag, CDD_DMA_CONFIG_DATA) Cdd_Dma_Config;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_DMA_CFG_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Dma_Cfg.h
 *********************************************************************************************************************/
