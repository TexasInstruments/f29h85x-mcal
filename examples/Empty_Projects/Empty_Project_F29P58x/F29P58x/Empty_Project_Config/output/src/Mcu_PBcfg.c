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
 *  File:       Mcu_PBcfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated post build configuration data                                          
 *********************************************************************************************************************/

 /*
 * Design: MCAL-21787
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcu.h"
#include "hw_memmap.h"
#include "hw_sysctl.h"

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * AUTOSAR version information check.
 *********************************************************************************************************************/
#if ((MCU_SW_MAJOR_VERSION != (2U)) || (MCU_SW_MINOR_VERSION != (1U)))
    #error "Version numbers of Mcu_PBcfg.c and Mcu.h are inconsistent!"
#endif

#if ((MCU_CFG_MAJOR_VERSION != (2U)) || (MCU_CFG_MINOR_VERSION != (1U)))
    #error "Version numbers of Mcu_PBcfg.c and Mcu_Cfg.h are inconsistent!"
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
 
 /*
 * Design: MCAL-21901
 */

static CONST(Mcu_PeripheralClkRegConfigType, MCU_CONFIG_DATA) Mcu_PerClkCfgSet0[3] =
{
    {
    /* Peripheral Clock Gating Register0 (PCLKCR0) */
    (uint32)((0x00000000U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<19U)
    |(1UL<<20U)
    |(1UL<<24U)
    |(1UL<<25U)),

    /* Peripheral Clock Gating Register1 (PCLKCR1) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register2 (PCLKCR2) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<10U)
    |(1UL<<11U)
    |(1UL<<12U)
    |(1UL<<13U)
    |(1UL<<14U)
    |(1UL<<15U)
    |(1UL<<16U)
    |(1UL<<17U)),

    /* Peripheral Clock Gating Register3 (PCLKCR3) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register4 (PCLKCR4) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register6 (PCLKCR6) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)),

    /* Peripheral Clock Gating Register7 (PCLKCR7) */
    (uint32)((0x00000000U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)
    |(1UL<<19U)
    |(1UL<<20U)
    |(1UL<<21U)),

    /* Peripheral Clock Gating Register8 (PCLKCR8) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)),

    /* Peripheral Clock Gating Register9 (PCLKCR9) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),

    /* Peripheral Clock Gating Register10 (PCLKCR10) */
    (uint32)((0x00000000U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)),

    /* Peripheral Clock Gating Register13 (PCLKCR13) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)),

    /* Peripheral Clock Gating Register14 (PCLKCR14) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<10U)
    |(1UL<<11U)),

    /* Peripheral Clock Gating Register16 (PCLKCR16) */
    (uint32)((0x00000000U)
    |(1UL<<16U)
    |(1UL<<17U)),

    /* Peripheral Clock Gating Register17 (PCLKCR17) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register18 (PCLKCR18) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)
    |(1UL<<19U)),

    /* Peripheral Clock Gating Register19 (PCLKCR19) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),

    /* Peripheral Clock Gating Register20 (PCLKCR20) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register21 (PCLKCR21) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)),

    /* Peripheral Clock Gating Register23 (PCLKCR23) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register25 (PCLKCR25) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)),

    /* Peripheral Clock Gating Register27 (PCLKCR27) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register28 (PCLKCR28) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)),

    /* Peripheral Clock Gating Register30 (PCLKCR30) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register32 (PCLKCR32) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),
    },
    {
    /* Peripheral Clock Gating Register0 (PCLKCR0) */
    (uint32)((0x00000000U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<19U)
    |(1UL<<20U)
    |(1UL<<24U)
    |(1UL<<25U)),

    /* Peripheral Clock Gating Register1 (PCLKCR1) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register2 (PCLKCR2) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<10U)
    |(1UL<<11U)
    |(1UL<<12U)
    |(1UL<<13U)
    |(1UL<<14U)
    |(1UL<<15U)
    |(1UL<<16U)
    |(1UL<<17U)),

    /* Peripheral Clock Gating Register3 (PCLKCR3) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register4 (PCLKCR4) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register6 (PCLKCR6) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)),

    /* Peripheral Clock Gating Register7 (PCLKCR7) */
    (uint32)((0x00000000U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)
    |(1UL<<19U)
    |(1UL<<20U)
    |(1UL<<21U)),

    /* Peripheral Clock Gating Register8 (PCLKCR8) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)),

    /* Peripheral Clock Gating Register9 (PCLKCR9) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),

    /* Peripheral Clock Gating Register10 (PCLKCR10) */
    (uint32)((0x00000000U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)),

    /* Peripheral Clock Gating Register13 (PCLKCR13) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)),

    /* Peripheral Clock Gating Register14 (PCLKCR14) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<10U)
    |(1UL<<11U)),

    /* Peripheral Clock Gating Register16 (PCLKCR16) */
    (uint32)((0x00000000U)
    |(1UL<<16U)
    |(1UL<<17U)),

    /* Peripheral Clock Gating Register17 (PCLKCR17) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register18 (PCLKCR18) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)
    |(1UL<<19U)),

    /* Peripheral Clock Gating Register19 (PCLKCR19) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),

    /* Peripheral Clock Gating Register20 (PCLKCR20) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register21 (PCLKCR21) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)),

    /* Peripheral Clock Gating Register23 (PCLKCR23) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register25 (PCLKCR25) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)),

    /* Peripheral Clock Gating Register27 (PCLKCR27) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register28 (PCLKCR28) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)),

    /* Peripheral Clock Gating Register30 (PCLKCR30) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register32 (PCLKCR32) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),
    },
    {
    /* Peripheral Clock Gating Register0 (PCLKCR0) */
    (uint32)((0x00000000U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<19U)
    |(1UL<<20U)
    |(1UL<<24U)
    |(1UL<<25U)),

    /* Peripheral Clock Gating Register1 (PCLKCR1) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register2 (PCLKCR2) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<10U)
    |(1UL<<11U)
    |(1UL<<12U)
    |(1UL<<13U)
    |(1UL<<14U)
    |(1UL<<15U)
    |(1UL<<16U)
    |(1UL<<17U)),

    /* Peripheral Clock Gating Register3 (PCLKCR3) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register4 (PCLKCR4) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register6 (PCLKCR6) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)),

    /* Peripheral Clock Gating Register7 (PCLKCR7) */
    (uint32)((0x00000000U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)
    |(1UL<<19U)
    |(1UL<<20U)
    |(1UL<<21U)),

    /* Peripheral Clock Gating Register8 (PCLKCR8) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)),

    /* Peripheral Clock Gating Register9 (PCLKCR9) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),

    /* Peripheral Clock Gating Register10 (PCLKCR10) */
    (uint32)((0x00000000U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)),

    /* Peripheral Clock Gating Register13 (PCLKCR13) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)),

    /* Peripheral Clock Gating Register14 (PCLKCR14) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<10U)
    |(1UL<<11U)),

    /* Peripheral Clock Gating Register16 (PCLKCR16) */
    (uint32)((0x00000000U)
    |(1UL<<16U)
    |(1UL<<17U)),

    /* Peripheral Clock Gating Register17 (PCLKCR17) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register18 (PCLKCR18) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)
    |(1UL<<19U)),

    /* Peripheral Clock Gating Register19 (PCLKCR19) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),

    /* Peripheral Clock Gating Register20 (PCLKCR20) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register21 (PCLKCR21) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)),

    /* Peripheral Clock Gating Register23 (PCLKCR23) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register25 (PCLKCR25) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)),

    /* Peripheral Clock Gating Register27 (PCLKCR27) */
    (uint32)((0x00000000U)
    |(1UL<<0U)),

    /* Peripheral Clock Gating Register28 (PCLKCR28) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)
    |(1UL<<6U)
    |(1UL<<7U)
    |(1UL<<8U)
    |(1UL<<9U)
    |(1UL<<16U)
    |(1UL<<17U)
    |(1UL<<18U)),

    /* Peripheral Clock Gating Register30 (PCLKCR30) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)
    |(1UL<<2U)
    |(1UL<<3U)
    |(1UL<<4U)
    |(1UL<<5U)),

    /* Peripheral Clock Gating Register32 (PCLKCR32) */
    (uint32)((0x00000000U)
    |(1UL<<0U)
    |(1UL<<1U)),
    }   
};




static CONST(Mcu_PeripheralResetRegConfigType, MCU_CONFIG_DATA) Mcu_PerResetCfgSet0[3] =
{
    {
    /* Peripheral Reset Register0 (SOFTPRES0) */
    (uint32)((0x00000000U)
    |(0UL<<4U)
    |(0UL<<24U)
    |(0UL<<25U)),

    /* Peripheral Reset Register1 (SOFTPRES1) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register2 (SOFTPRES2) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<10U)
    |(0UL<<11U)
    |(0UL<<12U)
    |(0UL<<13U)
    |(0UL<<14U)
    |(0UL<<15U)
    |(0UL<<16U)
    |(0UL<<17U)),

    /* Peripheral Reset Register3 (SOFTPRES3) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register4 (SOFTPRES4) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register6 (SOFTPRES6) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)),

    /* Peripheral Reset Register7 (SOFTPRES7) */
    (uint32)((0x00000000U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)
    |(0UL<<19U)
    |(0UL<<20U)
    |(0UL<<21U)),

    /* Peripheral Reset Register8 (SOFTPRES8) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)),

    /* Peripheral Reset Register9 (SOFTPRES9) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),

    /* Peripheral Reset Register10 (SOFTPRES10) */
    (uint32)((0x00000000U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)),

    /* Peripheral Reset Register13 (SOFTPRES13) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)),

    /* Peripheral Reset Register14 (SOFTPRES14) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<10U)
    |(0UL<<11U)),

    /* Peripheral Reset Register16 (SOFTPRES16) */
    (uint32)((0x00000000U)
    |(0UL<<16U)
    |(0UL<<17U)),

    /* Peripheral Reset Register17 (SOFTPRES17) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register18 (SOFTPRES18) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)
    |(0UL<<19U)),

    /* Peripheral Reset Register19 (SOFTPRES19) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),

    /* Peripheral Reset Register20 (SOFTPRES20) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register21 (SOFTPRES21) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)),

    /* Peripheral Reset Register23 (SOFTPRES23) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register25 (SOFTPRES25) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)),

    /* Peripheral Reset Register27 (SOFTPRES27) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register28 (SOFTPRES28) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)),

    /* Peripheral Reset Register30 (SOFTPRES30) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register32 (SOFTPRES32) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),
    },
    {
    /* Peripheral Reset Register0 (SOFTPRES0) */
    (uint32)((0x00000000U)
    |(0UL<<4U)
    |(0UL<<24U)
    |(0UL<<25U)),

    /* Peripheral Reset Register1 (SOFTPRES1) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register2 (SOFTPRES2) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<10U)
    |(0UL<<11U)
    |(0UL<<12U)
    |(0UL<<13U)
    |(0UL<<14U)
    |(0UL<<15U)
    |(0UL<<16U)
    |(0UL<<17U)),

    /* Peripheral Reset Register3 (SOFTPRES3) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register4 (SOFTPRES4) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register6 (SOFTPRES6) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)),

    /* Peripheral Reset Register7 (SOFTPRES7) */
    (uint32)((0x00000000U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)
    |(0UL<<19U)
    |(0UL<<20U)
    |(0UL<<21U)),

    /* Peripheral Reset Register8 (SOFTPRES8) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)),

    /* Peripheral Reset Register9 (SOFTPRES9) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),

    /* Peripheral Reset Register10 (SOFTPRES10) */
    (uint32)((0x00000000U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)),

    /* Peripheral Reset Register13 (SOFTPRES13) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)),

    /* Peripheral Reset Register14 (SOFTPRES14) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<10U)
    |(0UL<<11U)),

    /* Peripheral Reset Register16 (SOFTPRES16) */
    (uint32)((0x00000000U)
    |(0UL<<16U)
    |(0UL<<17U)),

    /* Peripheral Reset Register17 (SOFTPRES17) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register18 (SOFTPRES18) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)
    |(0UL<<19U)),

    /* Peripheral Reset Register19 (SOFTPRES19) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),

    /* Peripheral Reset Register20 (SOFTPRES20) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register21 (SOFTPRES21) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)),

    /* Peripheral Reset Register23 (SOFTPRES23) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register25 (SOFTPRES25) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)),

    /* Peripheral Reset Register27 (SOFTPRES27) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register28 (SOFTPRES28) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)),

    /* Peripheral Reset Register30 (SOFTPRES30) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register32 (SOFTPRES32) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),
    },
    {
    /* Peripheral Reset Register0 (SOFTPRES0) */
    (uint32)((0x00000000U)
    |(0UL<<4U)
    |(0UL<<24U)
    |(0UL<<25U)),

    /* Peripheral Reset Register1 (SOFTPRES1) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register2 (SOFTPRES2) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<10U)
    |(0UL<<11U)
    |(0UL<<12U)
    |(0UL<<13U)
    |(0UL<<14U)
    |(0UL<<15U)
    |(0UL<<16U)
    |(0UL<<17U)),

    /* Peripheral Reset Register3 (SOFTPRES3) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register4 (SOFTPRES4) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register6 (SOFTPRES6) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)),

    /* Peripheral Reset Register7 (SOFTPRES7) */
    (uint32)((0x00000000U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)
    |(0UL<<19U)
    |(0UL<<20U)
    |(0UL<<21U)),

    /* Peripheral Reset Register8 (SOFTPRES8) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)),

    /* Peripheral Reset Register9 (SOFTPRES9) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),

    /* Peripheral Reset Register10 (SOFTPRES10) */
    (uint32)((0x00000000U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)),

    /* Peripheral Reset Register13 (SOFTPRES13) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)),

    /* Peripheral Reset Register14 (SOFTPRES14) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<10U)
    |(0UL<<11U)),

    /* Peripheral Reset Register16 (SOFTPRES16) */
    (uint32)((0x00000000U)
    |(0UL<<16U)
    |(0UL<<17U)),

    /* Peripheral Reset Register17 (SOFTPRES17) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register18 (SOFTPRES18) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)
    |(0UL<<19U)),

    /* Peripheral Reset Register19 (SOFTPRES19) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),

    /* Peripheral Reset Register20 (SOFTPRES20) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register21 (SOFTPRES21) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)),

    /* Peripheral Reset Register23 (SOFTPRES23) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register25 (SOFTPRES25) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)),

    /* Peripheral Reset Register27 (SOFTPRES27) */
    (uint32)((0x00000000U)
    |(0UL<<0U)),

    /* Peripheral Reset Register28 (SOFTPRES28) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)
    |(0UL<<6U)
    |(0UL<<7U)
    |(0UL<<8U)
    |(0UL<<9U)
    |(0UL<<16U)
    |(0UL<<17U)
    |(0UL<<18U)),

    /* Peripheral Reset Register30 (SOFTPRES30) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)
    |(0UL<<2U)
    |(0UL<<3U)
    |(0UL<<4U)
    |(0UL<<5U)),

    /* Peripheral Reset Register32 (SOFTPRES32) */
    (uint32)((0x00000000U)
    |(0UL<<0U)
    |(0UL<<1U)),
    }   
};






static CONST(Mcu_MCanClkConfigType, MCU_CONFIG_DATA) Mcu_MCanClkCfgSet0[1] =
{
    {
    /* MCan clock configuration settings */
    .Mcu_MCanInstance    = ((Mcu_MCANInstance) MCU_MCAN_A),
    .Mcu_MCanClkSource   = ((Mcu_MCanClkSrc) MCU_MCANCLKSRC_PERxSYSCLK),
    .Mcu_MCanClkDiv      = ((Mcu_MCANClkDivider) MCU_MCANCLK_DIV_20),
    }   
};


static CONST(Mcu_MCanClkConfigType, MCU_CONFIG_DATA) Mcu_MCanClkCfgSet1[1] =
{
    {
    /* MCan clock configuration settings */
    .Mcu_MCanInstance    = ((Mcu_MCANInstance) MCU_MCAN_A),
    .Mcu_MCanClkSource   = ((Mcu_MCanClkSrc) MCU_MCANCLKSRC_PERxSYSCLK),
    .Mcu_MCanClkDiv      = ((Mcu_MCANClkDivider) MCU_MCANCLK_DIV_20),
    }   
};


static CONST(Mcu_MCanClkConfigType, MCU_CONFIG_DATA) Mcu_MCanClkCfgSet2[1] =
{
    {
    /* MCan clock configuration settings */
    .Mcu_MCanInstance    = ((Mcu_MCANInstance) MCU_MCAN_A),
    .Mcu_MCanClkSource   = ((Mcu_MCanClkSrc) MCU_MCANCLKSRC_PERxSYSCLK),
    .Mcu_MCanClkDiv      = ((Mcu_MCANClkDivider) MCU_MCANCLK_DIV_20),
    }   
};






static CONST(Mcu_LinClkConfigType, MCU_CONFIG_DATA) Mcu_LinClkCfgSet0[1] =
{
    {
    /* Lin clock configuration settings */
    .Mcu_LinInstance    = ((Mcu_LINInstance) MCU_LIN_A),
    .Mcu_LinClkDiv      = ((Mcu_LINClkDivider) MCU_LINCLK_DIV_2),
    }   
};


static CONST(Mcu_LinClkConfigType, MCU_CONFIG_DATA) Mcu_LinClkCfgSet1[1] =
{
    {
    /* Lin clock configuration settings */
    .Mcu_LinInstance    = ((Mcu_LINInstance) MCU_LIN_A),
    .Mcu_LinClkDiv      = ((Mcu_LINClkDivider) MCU_LINCLK_DIV_2),
    }   
};


static CONST(Mcu_LinClkConfigType, MCU_CONFIG_DATA) Mcu_LinClkCfgSet2[1] =
{
    {
    /* Lin clock configuration settings */
    .Mcu_LinInstance    = ((Mcu_LINInstance) MCU_LIN_A),
    .Mcu_LinClkDiv      = ((Mcu_LINClkDivider) MCU_LINCLK_DIV_2),
    }   
};



/*
 * Design: MCAL-21870, MCAL-21871, MCAL-21886, MCAL-21887, MCAL-21888, MCAL-21889,
 * Design: MCAL-21891, MCAL-21892, MCAL-21893, MCAL-21894, MCAL-21895, MCAL-21896,
 * Design: MCAL-21897, MCAL-21898, MCAL-21899, MCAL-21900, MCAL-21901, MCAL-21872, MCAL-21873
 */

static CONST(Mcu_ClockConfigType, MCU_CONFIG_DATA) Mcu_ClkCfgSet0[3] =
{
    {
    .Mcu_ClockSourceId = ((Mcu_ClkSourceIdType) MCU_CLKSRC_OSC2),
    .Mcu_PeripheralClkConfigPtr = ((Mcu_PeripheralClkRegConfigPtrType) &Mcu_PerClkCfgSet0[0]),
    .Mcu_PeripheralResetConfigPtr = ((Mcu_PeripheralResetRegConfigPtrType) &Mcu_PerResetCfgSet0[0]),
    .Mcu_MCanInstancesCount     = ((uint32) 1U),
    .Mcu_LinInstancesCount      = ((uint32) 1U),
    .Mcu_MCanClkConfig          = ((Mcu_MCanClkConfigPtrType) Mcu_MCanClkCfgSet0),
    .Mcu_LinClkConfig           = ((Mcu_LinClkConfigPtrType) Mcu_LinClkCfgSet0),
    .Mcu_CpuTimerClkConfig = {
        .Mcu_CpuTimer2ClkSource = ((Mcu_CpuTimerClkSrc) MCU_CPUTIMERCLKSRC_SYSCLK),
        .Mcu_CpuTimer2ClkDiv    = ((uint8) 1U)
    },
    .Mcu_ExternalClkOutConfig = {
        .Mcu_ExternalClockOutSource = ((Mcu_ExternalClockOutClkSrc) MCU_XCLKOUTSRC_PLLSYS),
        .Mcu_ExternalClkOutDiv      = ((Mcu_ExternalClockOutDiv) MCU_XCLKOUT_DIV_8),
        .Mcu_ExternalClockOut       = ((boolean) FALSE)
    },
    .Mcu_EthercatClkConfig = {
        .Mcu_EthercatClkDiv       = ((Mcu_EthercatClockDiv) MCU_ECATCLKOUT_DIV_8),
        .Mcu_EthercatPhyClkEnable = ((Mcu_EthercatPhyClk)   MCU_ECAT_PHYCLK_ENABLE)
    },
    .Mcu_ExternalClkFreq = ((uint32) 20000000U),
    .Mcu_SysClkDiv       = ((uint8) 1U),
    .Mcu_HsmClkDiv       = ((Mcu_HsmClockDiv) MCU_HSMCLK_DIV_16),
    .Mcu_EpwmClkDiv      = ((Mcu_EPWMClkDivider) MCU_EPWMCLK_DIV_2),
    .Mcu_EmifClkDiv      = ((Mcu_EMIFClkDivider) MCU_EMIFCLK_DIV_2),
    
    .Mcu_PllRefDiv       = ((uint8) 1U),
    .Mcu_PllIntMult      = ((uint8) 40U),
    .Mcu_PllOutDiv       = ((uint8) 2U),
    },
    {
    .Mcu_ClockSourceId = ((Mcu_ClkSourceIdType) MCU_CLKSRC_XTAL),
    .Mcu_PeripheralClkConfigPtr = ((Mcu_PeripheralClkRegConfigPtrType) &Mcu_PerClkCfgSet0[1]),
    .Mcu_PeripheralResetConfigPtr = ((Mcu_PeripheralResetRegConfigPtrType) &Mcu_PerResetCfgSet0[1]),
    .Mcu_MCanInstancesCount     = ((uint32) 1U),
    .Mcu_LinInstancesCount      = ((uint32) 1U),
    .Mcu_MCanClkConfig          = ((Mcu_MCanClkConfigPtrType) Mcu_MCanClkCfgSet1),
    .Mcu_LinClkConfig           = ((Mcu_LinClkConfigPtrType) Mcu_LinClkCfgSet1),
    .Mcu_CpuTimerClkConfig = {
        .Mcu_CpuTimer2ClkSource = ((Mcu_CpuTimerClkSrc) MCU_CPUTIMERCLKSRC_SYSCLK),
        .Mcu_CpuTimer2ClkDiv    = ((uint8) 1U)
    },
    .Mcu_ExternalClkOutConfig = {
        .Mcu_ExternalClockOutSource = ((Mcu_ExternalClockOutClkSrc) MCU_XCLKOUTSRC_PLLSYS),
        .Mcu_ExternalClkOutDiv      = ((Mcu_ExternalClockOutDiv) MCU_XCLKOUT_DIV_8),
        .Mcu_ExternalClockOut       = ((boolean) FALSE)
    },
    .Mcu_EthercatClkConfig = {
        .Mcu_EthercatClkDiv       = ((Mcu_EthercatClockDiv) MCU_ECATCLKOUT_DIV_8),
        .Mcu_EthercatPhyClkEnable = ((Mcu_EthercatPhyClk)   MCU_ECAT_PHYCLK_ENABLE)
    },
    .Mcu_ExternalClkFreq = ((uint32) 20000000U),
    .Mcu_SysClkDiv       = ((uint8) 1U),
    .Mcu_HsmClkDiv       = ((Mcu_HsmClockDiv) MCU_HSMCLK_DIV_16),
    .Mcu_EpwmClkDiv      = ((Mcu_EPWMClkDivider) MCU_EPWMCLK_DIV_2),
    .Mcu_EmifClkDiv      = ((Mcu_EMIFClkDivider) MCU_EMIFCLK_DIV_2),
    
    .Mcu_PllRefDiv       = ((uint8) 1U),
    .Mcu_PllIntMult      = ((uint8) 30U),
    .Mcu_PllOutDiv       = ((uint8) 3U),
    },
    {
    .Mcu_ClockSourceId = ((Mcu_ClkSourceIdType) MCU_CLKSRC_XTAL_SE),
    .Mcu_PeripheralClkConfigPtr = ((Mcu_PeripheralClkRegConfigPtrType) &Mcu_PerClkCfgSet0[2]),
    .Mcu_PeripheralResetConfigPtr = ((Mcu_PeripheralResetRegConfigPtrType) &Mcu_PerResetCfgSet0[2]),
    .Mcu_MCanInstancesCount     = ((uint32) 1U),
    .Mcu_LinInstancesCount      = ((uint32) 1U),
    .Mcu_MCanClkConfig          = ((Mcu_MCanClkConfigPtrType) Mcu_MCanClkCfgSet2),
    .Mcu_LinClkConfig           = ((Mcu_LinClkConfigPtrType) Mcu_LinClkCfgSet2),
    .Mcu_CpuTimerClkConfig = {
        .Mcu_CpuTimer2ClkSource = ((Mcu_CpuTimerClkSrc) MCU_CPUTIMERCLKSRC_SYSCLK),
        .Mcu_CpuTimer2ClkDiv    = ((uint8) 1U)
    },
    .Mcu_ExternalClkOutConfig = {
        .Mcu_ExternalClockOutSource = ((Mcu_ExternalClockOutClkSrc) MCU_XCLKOUTSRC_PLLSYS),
        .Mcu_ExternalClkOutDiv      = ((Mcu_ExternalClockOutDiv) MCU_XCLKOUT_DIV_8),
        .Mcu_ExternalClockOut       = ((boolean) FALSE)
    },
    .Mcu_EthercatClkConfig = {
        .Mcu_EthercatClkDiv       = ((Mcu_EthercatClockDiv) MCU_ECATCLKOUT_DIV_8),
        .Mcu_EthercatPhyClkEnable = ((Mcu_EthercatPhyClk)   MCU_ECAT_PHYCLK_ENABLE)
    },
    .Mcu_ExternalClkFreq = ((uint32) 25000000U),
    .Mcu_SysClkDiv       = ((uint8) 1U),
    .Mcu_HsmClkDiv       = ((Mcu_HsmClockDiv) MCU_HSMCLK_DIV_16),
    .Mcu_EpwmClkDiv      = ((Mcu_EPWMClkDivider) MCU_EPWMCLK_DIV_2),
    .Mcu_EmifClkDiv      = ((Mcu_EMIFClkDivider) MCU_EMIFCLK_DIV_2),
    
    .Mcu_PllRefDiv       = ((uint8) 2U),
    .Mcu_PllIntMult      = ((uint8) 32U),
    .Mcu_PllOutDiv       = ((uint8) 2U),
    }
};


/*
 * Design: MCAL-21878, MCAL-21879, MCAL-21880, MCAL-21881, MCAL-21882
 */

static CONST(Mcu_RamSectionConfigType, MCU_CONFIG_DATA) Mcu_RamSectionCfgSet0[0] =
{

};


/*
 * Design: MCAL-21876, MCAL-21877, MCAL-21902, MCAL-21903
 */

static CONST(Mcu_ModeConfigType, MCU_CONFIG_DATA) Mcu_ModeConfigurationSet0[2] =
{
    {
    .Mcu_LowPowerMode   = ((Mcu_LowPowerModeType) MCU_IDLE_MODE),
    .Mcu_QualPeriod     = ((uint16) 0U),
    .Mcu_EnableWDWakeup = ((boolean) FALSE),
    },
    {
    .Mcu_LowPowerMode   = ((Mcu_LowPowerModeType) MCU_STANDBY_MODE),
    .Mcu_QualPeriod     = ((uint16) 2U),
    .Mcu_EnableWDWakeup = ((boolean) FALSE),
    }
};


/*<MCU_CFG_CONFIG>*/
/*
 * Design: MCAL-21865, MCAL-21866, MCAL-21867, MCAL-21868, MCAL-21869, MCAL-21866
 */
/* Forward declaration of peripheral configuration structure */
static CONST(Mcu_PeripheralConfigType, MCU_CONFIG_DATA) Mcu_PeripheralConfig;

CONST(Mcu_ConfigType, MCU_CONFIG_DATA) Mcu_Config_Mcu_ModuleConfiguration_0 =
{
    /* Mcu_ClockConfig */
    .Mcu_ClockConfig               = ((Mcu_ClockConfigPtrType) Mcu_ClkCfgSet0),
    /* Mcu_ConfigRamSection */
    .Mcu_ConfigRamSection          = ((Mcu_RamConfigPtrType) Mcu_RamSectionCfgSet0),
    /* Mcu_ModeConfig */
    .Mcu_ModeConfig                = ((Mcu_ModeConfigPtrType) Mcu_ModeConfigurationSet0),
    /* Mcu_ClockSetting */
    .Mcu_ClockSetting              = ((uint8) 3U),
    /* Mcu_NumberOfRamSectors */
    .Mcu_NumberOfRamSectors        = ((uint8) 0U),
    /* Mcu_ModesNumber */
    .Mcu_NumberOfLowPowerModes     = ((uint8) 2U),
    /* Mcu_ResetSetting */
    .Mcu_ResetSetting              = ((Mcu_ResetType) MCU_EXTERNAL_RESET),
    /* Mcu_EnableClkFailNotification */
    .Mcu_EnableClkFailNotification = ((boolean) TRUE),
    /* Peripheral Configuration */
    .PeripheralConfig              = &Mcu_PeripheralConfig,
    /* CPU1 Lockstep Enable Configuration */
    .Mcu_LockstepEnable            = ((boolean) TRUE)
};



/*********************************************************************************************************************
 *  Peripheral Configuration Register Array Generation
 *
 *  This section generates peripheral configuration arrays from ResourceAllocator XDM configuration.
 *  Each peripheral configuration register has the following bit layout:
 *    - Bits 31-8: Reserved (0)
 *    - Bit 7: DBGHALTEN - Debug halt enable (1=enabled, 0=disabled)
 *    - Bit 6: STANDBYEN - Standby mode enable (1=enabled, 0=disabled)
 *    - Bits 5-3: CPUSEL - CPU selection (000=CPU1, 001=CPU2, 010=CPU3)
 *    - Bits 2-0: FRAMESEL - Frame selection (000=FRAME0, 001=FRAME1, 010=FRAME2, 011=FRAME3)
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  Peripheral Configuration Array
 *
 *  Contains configuration entries for all peripherals with Frame configuration from ResourceAllocator.
 *  Each entry specifies the register address and the configuration value to write.
 *********************************************************************************************************************/
static CONST(Mcu_PeripheralRegEntryType, MCU_CONFIG_DATA) Mcu_PeripheralConfigSet[] =
{
                            
    /* MCANA Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_MCANA),
        .RegValue = (uint32)0x000000C0U
    },

    /* MCANB Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_MCANB),
        .RegValue = (uint32)0x000000C0U
    },

    /* MCANC Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_MCANC),
        .RegValue = (uint32)0x000000C0U
    },

    /* MCAND Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_MCAND),
        .RegValue = (uint32)0x000000C0U
    },

    /* SPIA Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SPIA),
        .RegValue = (uint32)0x000000C0U
    },

    /* SPIB Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SPIB),
        .RegValue = (uint32)0x000000C0U
    },

    /* SPIC Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SPIC),
        .RegValue = (uint32)0x000000C0U
    },

    /* SPID Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SPID),
        .RegValue = (uint32)0x000000C0U
    },

    /* SPIE Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SPIE),
        .RegValue = (uint32)0x000000C0U
    },

    /* LINA Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_LINA),
        .RegValue = (uint32)0x000000C0U
    },

    /* LINB Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_LINB),
        .RegValue = (uint32)0x000000C0U
    },

    /* CDD_ADCA Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCA),
        .RegValue = (uint32)0x000000C0U
    },

    /* CDD_ADCB Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCB),
        .RegValue = (uint32)0x000000C0U
    },

    /* CDD_ADCC Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCC),
        .RegValue = (uint32)0x000000C0U
    },

    /* CDD_ADCD Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCD),
        .RegValue = (uint32)0x000000C0U
    },

    /* CDD_ADCE Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCE),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK1 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER1),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK2 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER2),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK3 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER3),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK4 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER4),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK5 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER5),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK6 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER6),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK7 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER7),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK8 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER8),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK9 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER9),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECK10 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCCHECKER10),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADCSAFETYCHECKINTEVT1 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADCSEAGGRCPU1),
        .RegValue = (uint32)0x000000C0U
    },

    /* ADC_GLOBAL_REGS Configuration - FRAME0 */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ADC_GLOBAL_REGS),
        .RegValue = (uint32)0x00000000U
    },

    /* ECAP1 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ECAP1),
        .RegValue = (uint32)0x000000C0U
    },

    /* ECAP2 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ECAP2),
        .RegValue = (uint32)0x000000C0U
    },

    /* ECAP3 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ECAP3),
        .RegValue = (uint32)0x000000C0U
    },

    /* ECAP4 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ECAP4),
        .RegValue = (uint32)0x000000C0U
    },

    /* ECAP5 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ECAP5),
        .RegValue = (uint32)0x000000C0U
    },

    /* ECAP6 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_ECAP6),
        .RegValue = (uint32)0x000000C0U
    },

    /* I2CA Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_I2CA),
        .RegValue = (uint32)0x000000C0U
    },

    /* I2CB Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_I2CB),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM1 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM1),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM2 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM2),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM3 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM3),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM4 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM4),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM5 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM5),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM6 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM6),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM7 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM7),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM8 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM8),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM9 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM9),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM10 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM10),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM11 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM11),
        .RegValue = (uint32)0x000000C0U
    },

    /* EPWM12 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_EPWM12),
        .RegValue = (uint32)0x000000C0U
    },

    /* HRPWMCAL1 Configuration - FRAME0 */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_HRCAL1),
        .RegValue = (uint32)0x00000000U
    },

    /* SENT1 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SENT1),
        .RegValue = (uint32)0x000000C0U
    },

    /* SENT2 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SENT2),
        .RegValue = (uint32)0x000000C0U
    },

    /* SENT3 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SENT3),
        .RegValue = (uint32)0x000000C0U
    },

    /* SENT4 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SENT4),
        .RegValue = (uint32)0x000000C0U
    },

    /* SENT5 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SENT5),
        .RegValue = (uint32)0x000000C0U
    },

    /* SENT6 Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_SENT6),
        .RegValue = (uint32)0x000000C0U
    },

    /* UARTA Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_UARTA),
        .RegValue = (uint32)0x000000C0U
    },

    /* UARTB Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_UARTB),
        .RegValue = (uint32)0x000000C0U
    },

    /* UARTC Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_UARTC),
        .RegValue = (uint32)0x000000C0U
    },

    /* UARTD Configuration - CPU1, FRAME0, DbgHalt=true, Standby=true */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_UARTD),
        .RegValue = (uint32)0x000000C0U
    }
};

/*********************************************************************************************************************
 *  Peripheral Configuration Structure
 *
 *  This structure wraps the peripheral configuration array and count for use by Mcu_Init.
 *  The PeripheralConfigEntries pointer references the Mcu_PeripheralConfigSet array, which
 *  contains struct entries with RegAddr and RegValue fields.
 *********************************************************************************************************************/
static CONST(Mcu_PeripheralConfigType, MCU_CONFIG_DATA) Mcu_PeripheralConfig =
{
    .PeripheralConfigEntries = Mcu_PeripheralConfigSet,
    .PeripheralConfigCount   = 59U
};




/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define MCU_STOP_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Mcu_PBcfg.c
 *********************************************************************************************************************/
