[!SKIPFILE "as:modconf('Mcu')[as:path(node:dtos(.))='/TI_F29H85x/Mcu']/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!][!//
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
#if ((MCU_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (MCU_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Mcu_PBcfg.c and Mcu.h are inconsistent!"
#endif

#if ((MCU_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (MCU_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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
[!SELECT "as:modconf('Mcu')[as:path(node:dtos(.))='/TI_F29H85x/Mcu']"!] 
 /*
 * Design: MCAL-21901
 */
[!LOOP "McuModuleConfiguration/*"!][!VAR "ClkCfgSetNo" = "@index"!]
static CONST(Mcu_PeripheralClkRegConfigType, MCU_CONFIG_DATA) Mcu_PerClkCfgSet[!"num:i($ClkCfgSetNo)"!][[!"num:i(count(McuClockSettingConfig/*))"!]] =
{
[!LOOP "McuClockSettingConfig/*"!]    {
    /* Peripheral Clock Gating Register0 (PCLKCR0) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_RTDMA1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_RTDMA2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_CPUTIMER0='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_CPUTIMER1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_CPUTIMER2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_TBCLKSYNC='true'"!]1[!ELSE!]0[!ENDIF!]UL<<19U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_GTBCLKSYNC='true'"!]1[!ELSE!]0[!ENDIF!]UL<<20U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_CPUXERAD='true'"!]1[!ELSE!]0[!ENDIF!]UL<<24U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_CPUXDLT='true'"!]1[!ELSE!]0[!ENDIF!]UL<<25U)),

    /* Peripheral Clock Gating Register1 (PCLKCR1) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock1/MCU_PERIPH_CLK_EMIF1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)),

    /* Peripheral Clock Gating Register2 (PCLKCR2) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM4='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM5='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM6='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM7='true'"!]1[!ELSE!]0[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM8='true'"!]1[!ELSE!]0[!ENDIF!]UL<<7U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM9='true'"!]1[!ELSE!]0[!ENDIF!]UL<<8U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM10='true'"!]1[!ELSE!]0[!ENDIF!]UL<<9U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM11='true'"!]1[!ELSE!]0[!ENDIF!]UL<<10U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM12='true'"!]1[!ELSE!]0[!ENDIF!]UL<<11U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM13='true'"!]1[!ELSE!]0[!ENDIF!]UL<<12U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM14='true'"!]1[!ELSE!]0[!ENDIF!]UL<<13U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM15='true'"!]1[!ELSE!]0[!ENDIF!]UL<<14U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM16='true'"!]1[!ELSE!]0[!ENDIF!]UL<<15U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM17='true'"!]1[!ELSE!]0[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM18='true'"!]1[!ELSE!]0[!ENDIF!]UL<<17U)),

    /* Peripheral Clock Gating Register3 (PCLKCR3) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP4='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP5='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP6='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)),

    /* Peripheral Clock Gating Register4 (PCLKCR4) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP4='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP5='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP6='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)),

    /* Peripheral Clock Gating Register6 (PCLKCR6) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock6/MCU_PERIPH_CLK_SD1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock6/MCU_PERIPH_CLK_SD2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock6/MCU_PERIPH_CLK_SD3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock6/MCU_PERIPH_CLK_SD4='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)),

    /* Peripheral Clock Gating Register7 (PCLKCR7) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<17U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTC='true'"!]1[!ELSE!]0[!ENDIF!]UL<<18U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTD='true'"!]1[!ELSE!]0[!ENDIF!]UL<<19U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTE='true'"!]1[!ELSE!]0[!ENDIF!]UL<<20U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTF='true'"!]1[!ELSE!]0[!ENDIF!]UL<<21U)),

    /* Peripheral Clock Gating Register8 (PCLKCR8) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPIA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPIB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPIC='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPID='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPIE='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)),

    /* Peripheral Clock Gating Register9 (PCLKCR9) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock9/MCU_PERIPH_CLK_I2CA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock9/MCU_PERIPH_CLK_I2CB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)),

    /* Peripheral Clock Gating Register10 (PCLKCR10) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANC='true'"!]1[!ELSE!]0[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCAND='true'"!]1[!ELSE!]0[!ENDIF!]UL<<7U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANE='true'"!]1[!ELSE!]0[!ENDIF!]UL<<8U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANF='true'"!]1[!ELSE!]0[!ENDIF!]UL<<9U)),

    /* Peripheral Clock Gating Register13 (PCLKCR13) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCC='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCD='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCE='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)),

    /* Peripheral Clock Gating Register14 (PCLKCR14) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS4='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS5='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS6='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS7='true'"!]1[!ELSE!]0[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS8='true'"!]1[!ELSE!]0[!ENDIF!]UL<<7U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS9='true'"!]1[!ELSE!]0[!ENDIF!]UL<<8U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS10='true'"!]1[!ELSE!]0[!ENDIF!]UL<<9U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS11='true'"!]1[!ELSE!]0[!ENDIF!]UL<<10U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS12='true'"!]1[!ELSE!]0[!ENDIF!]UL<<11U)),

    /* Peripheral Clock Gating Register16 (PCLKCR16) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock16/MCU_PERIPH_CLK_DACA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock16/MCU_PERIPH_CLK_DACB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<17U)),

    /* Peripheral Clock Gating Register17 (PCLKCR17) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB4='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB5='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB6='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)),

    /* Peripheral Clock Gating Register18 (PCLKCR18) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSITXA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSITXB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSITXC='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSITXD='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSIRXA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSIRXB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<17U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSIRXC='true'"!]1[!ELSE!]0[!ENDIF!]UL<<18U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSIRXD='true'"!]1[!ELSE!]0[!ENDIF!]UL<<19U)),

    /* Peripheral Clock Gating Register19 (PCLKCR19) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock19/MCU_PERIPH_CLK_LINA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock19/MCU_PERIPH_CLK_LINB='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)),

    /* Peripheral Clock Gating Register20 (PCLKCR20) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock20/MCU_PERIPH_CLK_PMBUSA='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)),

    /* Peripheral Clock Gating Register21 (PCLKCR21) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock21/MCU_PERIPH_CLK_DCC1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock21/MCU_PERIPH_CLK_DCC2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock21/MCU_PERIPH_CLK_DCC3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)),

    /* Peripheral Clock Gating Register23 (PCLKCR23) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock23/MCU_PERIPH_CLK_ETHERCAT='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)),

    /* Peripheral Clock Gating Register25 (PCLKCR25) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock25/MCU_PERIPH_CLK_HRCAL0='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock25/MCU_PERIPH_CLK_HRCAL1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock25/MCU_PERIPH_CLK_HRCAL2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)),

    /* Peripheral Clock Gating Register27 (PCLKCR27) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock27/MCU_PERIPH_CLK_EPG1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)),

    /* Peripheral Clock Gating Register28 (PCLKCR28) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER4='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER5='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER6='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER7='true'"!]1[!ELSE!]0[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER8='true'"!]1[!ELSE!]0[!ENDIF!]UL<<7U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER9='true'"!]1[!ELSE!]0[!ENDIF!]UL<<8U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER10='true'"!]1[!ELSE!]0[!ENDIF!]UL<<9U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCSEAGGRCPU1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCSEAGGRCPU2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<17U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCSEAGGRCPU3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<18U)),

    /* Peripheral Clock Gating Register30 (PCLKCR30) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT3='true'"!]1[!ELSE!]0[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT4='true'"!]1[!ELSE!]0[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT5='true'"!]1[!ELSE!]0[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT6='true'"!]1[!ELSE!]0[!ENDIF!]UL<<5U)),

    /* Peripheral Clock Gating Register32 (PCLKCR32) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock32/MCU_PERIPH_CLK_WADI1='true'"!]1[!ELSE!]0[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock32/MCU_PERIPH_CLK_WADI2='true'"!]1[!ELSE!]0[!ENDIF!]UL<<1U)),
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]   
};
[!ENDLOOP!]


[!LOOP "McuModuleConfiguration/*"!][!VAR "ClkCfgSetNo" = "@index"!]
static CONST(Mcu_PeripheralResetRegConfigType, MCU_CONFIG_DATA) Mcu_PerResetCfgSet[!"num:i($ClkCfgSetNo)"!][[!"num:i(count(McuClockSettingConfig/*))"!]] =
{
[!LOOP "McuClockSettingConfig/*"!]    {
    /* Peripheral Reset Register0 (SOFTPRES0) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_CPUTIMER0='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_CPUXERAD='true'"!]0[!ELSE!]1[!ENDIF!]UL<<24U)
    |([!IF "McuPeripheralClock0/MCU_PERIPH_CLK_CPUXDLT='true'"!]0[!ELSE!]1[!ENDIF!]UL<<25U)),

    /* Peripheral Reset Register1 (SOFTPRES1) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock1/MCU_PERIPH_CLK_EMIF1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)),

    /* Peripheral Reset Register2 (SOFTPRES2) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM4='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM5='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM6='true'"!]0[!ELSE!]1[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM7='true'"!]0[!ELSE!]1[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM8='true'"!]0[!ELSE!]1[!ENDIF!]UL<<7U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM9='true'"!]0[!ELSE!]1[!ENDIF!]UL<<8U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM10='true'"!]0[!ELSE!]1[!ENDIF!]UL<<9U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM11='true'"!]0[!ELSE!]1[!ENDIF!]UL<<10U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM12='true'"!]0[!ELSE!]1[!ENDIF!]UL<<11U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM13='true'"!]0[!ELSE!]1[!ENDIF!]UL<<12U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM14='true'"!]0[!ELSE!]1[!ENDIF!]UL<<13U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM15='true'"!]0[!ELSE!]1[!ENDIF!]UL<<14U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM16='true'"!]0[!ELSE!]1[!ENDIF!]UL<<15U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM17='true'"!]0[!ELSE!]1[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock2/MCU_PERIPH_CLK_EPWM18='true'"!]0[!ELSE!]1[!ENDIF!]UL<<17U)),

    /* Peripheral Reset Register3 (SOFTPRES3) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP4='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP5='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock3/MCU_PERIPH_CLK_ECAP6='true'"!]0[!ELSE!]1[!ENDIF!]UL<<5U)),

    /* Peripheral Reset Register4 (SOFTPRES4) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP4='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP5='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock4/MCU_PERIPH_CLK_EQEP6='true'"!]0[!ELSE!]1[!ENDIF!]UL<<5U)),

    /* Peripheral Reset Register6 (SOFTPRES6) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock6/MCU_PERIPH_CLK_SD1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock6/MCU_PERIPH_CLK_SD2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock6/MCU_PERIPH_CLK_SD3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock6/MCU_PERIPH_CLK_SD4='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)),

    /* Peripheral Reset Register7 (SOFTPRES7) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<17U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTC='true'"!]0[!ELSE!]1[!ENDIF!]UL<<18U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTD='true'"!]0[!ELSE!]1[!ENDIF!]UL<<19U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTE='true'"!]0[!ELSE!]1[!ENDIF!]UL<<20U)
    |([!IF "McuPeripheralClock7/MCU_PERIPH_CLK_UARTF='true'"!]0[!ELSE!]1[!ENDIF!]UL<<21U)),

    /* Peripheral Reset Register8 (SOFTPRES8) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPIA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPIB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPIC='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPID='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock8/MCU_PERIPH_CLK_SPIE='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)),

    /* Peripheral Reset Register9 (SOFTPRES9) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock9/MCU_PERIPH_CLK_I2CA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock9/MCU_PERIPH_CLK_I2CB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)),

    /* Peripheral Reset Register10 (SOFTPRES10) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANC='true'"!]0[!ELSE!]1[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCAND='true'"!]0[!ELSE!]1[!ENDIF!]UL<<7U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANE='true'"!]0[!ELSE!]1[!ENDIF!]UL<<8U)
    |([!IF "McuPeripheralClock10/MCU_PERIPH_CLK_MCANF='true'"!]0[!ELSE!]1[!ENDIF!]UL<<9U)),

    /* Peripheral Reset Register13 (SOFTPRES13) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCC='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCD='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock13/MCU_PERIPH_CLK_ADCE='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)),

    /* Peripheral Reset Register14 (SOFTPRES14) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS4='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS5='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS6='true'"!]0[!ELSE!]1[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS7='true'"!]0[!ELSE!]1[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS8='true'"!]0[!ELSE!]1[!ENDIF!]UL<<7U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS9='true'"!]0[!ELSE!]1[!ENDIF!]UL<<8U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS10='true'"!]0[!ELSE!]1[!ENDIF!]UL<<9U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS11='true'"!]0[!ELSE!]1[!ENDIF!]UL<<10U)
    |([!IF "McuPeripheralClock14/MCU_PERIPH_CLK_CMPSS12='true'"!]0[!ELSE!]1[!ENDIF!]UL<<11U)),

    /* Peripheral Reset Register16 (SOFTPRES16) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock16/MCU_PERIPH_CLK_DACA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock16/MCU_PERIPH_CLK_DACB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<17U)),

    /* Peripheral Reset Register17 (SOFTPRES17) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB4='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB5='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock17/MCU_PERIPH_CLK_CLB6='true'"!]0[!ELSE!]1[!ENDIF!]UL<<5U)),

    /* Peripheral Reset Register18 (SOFTPRES18) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSITXA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSITXB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSITXC='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSITXD='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSIRXA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSIRXB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<17U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSIRXC='true'"!]0[!ELSE!]1[!ENDIF!]UL<<18U)
    |([!IF "McuPeripheralClock18/MCU_PERIPH_CLK_FSIRXD='true'"!]0[!ELSE!]1[!ENDIF!]UL<<19U)),

    /* Peripheral Reset Register19 (SOFTPRES19) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock19/MCU_PERIPH_CLK_LINA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock19/MCU_PERIPH_CLK_LINB='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)),

    /* Peripheral Reset Register20 (SOFTPRES20) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock20/MCU_PERIPH_CLK_PMBUSA='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)),

    /* Peripheral Reset Register21 (SOFTPRES21) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock21/MCU_PERIPH_CLK_DCC1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock21/MCU_PERIPH_CLK_DCC2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock21/MCU_PERIPH_CLK_DCC3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)),

    /* Peripheral Reset Register23 (SOFTPRES23) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock23/MCU_PERIPH_CLK_ETHERCAT='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)),

    /* Peripheral Reset Register25 (SOFTPRES25) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock25/MCU_PERIPH_CLK_HRCAL0='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock25/MCU_PERIPH_CLK_HRCAL1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock25/MCU_PERIPH_CLK_HRCAL2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)),

    /* Peripheral Reset Register27 (SOFTPRES27) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock27/MCU_PERIPH_CLK_EPG1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)),

    /* Peripheral Reset Register28 (SOFTPRES28) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER4='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER5='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER6='true'"!]0[!ELSE!]1[!ENDIF!]UL<<5U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER7='true'"!]0[!ELSE!]1[!ENDIF!]UL<<6U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER8='true'"!]0[!ELSE!]1[!ENDIF!]UL<<7U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER9='true'"!]0[!ELSE!]1[!ENDIF!]UL<<8U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCCHECKER10='true'"!]0[!ELSE!]1[!ENDIF!]UL<<9U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCSEAGGRCPU1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<16U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCSEAGGRCPU2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<17U)
    |([!IF "McuPeripheralClock28/MCU_PERIPH_CLK_ADCSEAGGRCPU3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<18U)),

    /* Peripheral Reset Register30 (SOFTPRES30) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT3='true'"!]0[!ELSE!]1[!ENDIF!]UL<<2U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT4='true'"!]0[!ELSE!]1[!ENDIF!]UL<<3U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT5='true'"!]0[!ELSE!]1[!ENDIF!]UL<<4U)
    |([!IF "McuPeripheralClock30/MCU_PERIPH_CLK_SENT6='true'"!]0[!ELSE!]1[!ENDIF!]UL<<5U)),

    /* Peripheral Reset Register32 (SOFTPRES32) */
    (uint32)((0x00000000U)
    |([!IF "McuPeripheralClock32/MCU_PERIPH_CLK_WADI1='true'"!]0[!ELSE!]1[!ENDIF!]UL<<0U)
    |([!IF "McuPeripheralClock32/MCU_PERIPH_CLK_WADI2='true'"!]0[!ELSE!]1[!ENDIF!]UL<<1U)),
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]   
};
[!ENDLOOP!]


[!LOOP "McuModuleConfiguration/*"!]
[!LOOP "McuClockSettingConfig/*"!]
[!VAR "ClkCfgSetNo" = "@index"!]
static CONST(Mcu_MCanClkConfigType, MCU_CONFIG_DATA) Mcu_MCanClkCfgSet[!"num:i($ClkCfgSetNo)"!][[!"num:i(count(McuMCanClkConfig/*))"!]] =
{
[!LOOP "McuMCanClkConfig/*"!]    {
    /* MCan clock configuration settings */
    .Mcu_MCanInstance    = ((Mcu_MCANInstance) [!"McuMCanInstance"!]),
    .Mcu_MCanClkSource   = ((Mcu_MCanClkSrc) [!"McuMCanClockSource"!]),
    .Mcu_MCanClkDiv      = ((Mcu_MCANClkDivider) [!"McuMCanClkDiv"!]),
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]   
};
[!ENDLOOP!]
[!ENDLOOP!]

[!LOOP "McuModuleConfiguration/*"!]
[!LOOP "McuClockSettingConfig/*"!]
[!VAR "ClkCfgSetNo" = "@index"!]
static CONST(Mcu_LinClkConfigType, MCU_CONFIG_DATA) Mcu_LinClkCfgSet[!"num:i($ClkCfgSetNo)"!][[!"num:i(count(McuLinClkConfig/*))"!]] =
{
[!LOOP "McuLinClkConfig/*"!]    {
    /* Lin clock configuration settings */
    .Mcu_LinInstance    = ((Mcu_LINInstance) [!"McuLinInstance"!]),
    .Mcu_LinClkDiv      = ((Mcu_LINClkDivider) [!"McuLinClkDiv"!]),
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]   
};
[!ENDLOOP!]
[!ENDLOOP!]

/*
 * Design: MCAL-21870, MCAL-21871, MCAL-21886, MCAL-21887, MCAL-21888, MCAL-21889,
 * Design: MCAL-21891, MCAL-21892, MCAL-21893, MCAL-21894, MCAL-21895, MCAL-21896,
 * Design: MCAL-21897, MCAL-21898, MCAL-21899, MCAL-21900, MCAL-21901, MCAL-21872, MCAL-21873
 */
[!LOOP "McuModuleConfiguration/*"!][!VAR "McuModuleCfgSetNo" = "@index"!]
static CONST(Mcu_ClockConfigType, MCU_CONFIG_DATA) Mcu_ClkCfgSet[!"num:i($McuModuleCfgSetNo)"!][[!"num:i(count(McuClockSettingConfig/*))"!]] =
{
[!LOOP "McuClockSettingConfig/*"!][!VAR "ClkCfgSetNo" = "@index"!]    {
    .Mcu_ClockSourceId = ((Mcu_ClkSourceIdType) [!"McuClkConfig/McuClockSource"!]),
    .Mcu_PeripheralClkConfigPtr = ((Mcu_PeripheralClkRegConfigPtrType) &Mcu_PerClkCfgSet[!"num:i($McuModuleCfgSetNo)"!][[!"@index"!]]),
    .Mcu_PeripheralResetConfigPtr = ((Mcu_PeripheralResetRegConfigPtrType) &Mcu_PerResetCfgSet[!"num:i($McuModuleCfgSetNo)"!][[!"@index"!]]),
    .Mcu_MCanInstancesCount     = ((uint32) [!"num:i(count(McuMCanClkConfig/*))"!]U),
    .Mcu_LinInstancesCount      = ((uint32) [!"num:i(count(McuLinClkConfig/*))"!]U),
    .Mcu_MCanClkConfig          = ((Mcu_MCanClkConfigPtrType) Mcu_MCanClkCfgSet[!"num:i($ClkCfgSetNo)"!]),
    .Mcu_LinClkConfig           = ((Mcu_LinClkConfigPtrType) Mcu_LinClkCfgSet[!"num:i($ClkCfgSetNo)"!]),
    .Mcu_CpuTimerClkConfig = {
        .Mcu_CpuTimer2ClkSource = ((Mcu_CpuTimerClkSrc) [!"McuCpuTimerClkConfig/McuCpuTimer2ClockSource"!]),
        .Mcu_CpuTimer2ClkDiv    = ((uint8) [!"McuCpuTimerClkConfig/McuCpuTimer2ClkDiv"!]U)
    },
    .Mcu_ExternalClkOutConfig = {
        .Mcu_ExternalClockOutSource = ((Mcu_ExternalClockOutClkSrc) [!IF "McuExternalClkOutConfig/McuExternalClockOut='true'"!][!"McuExternalClkOutConfig/McuExternalClockOutSource"!][!ELSE!]MCU_XCLKOUTSRC_PLLSYS[!ENDIF!]),
        .Mcu_ExternalClkOutDiv      = ((Mcu_ExternalClockOutDiv) [!IF "McuExternalClkOutConfig/McuExternalClockOut='true'"!][!"McuExternalClkOutConfig/McuExternalClkOutDiv"!][!ELSE!]MCU_XCLKOUT_DIV_8[!ENDIF!]),
        .Mcu_ExternalClockOut       = ((boolean) [!IF "McuExternalClkOutConfig/McuExternalClockOut='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!])
    },
    .Mcu_EthercatClkConfig = {
        .Mcu_EthercatClkDiv       = ((Mcu_EthercatClockDiv) [!"McuEthercatClkConfig/McuEthercatClkDiv"!]),
        .Mcu_EthercatPhyClkEnable = ((Mcu_EthercatPhyClk)   [!"McuEthercatClkConfig/McuEthercatPhyClkEnable"!])
    },
    .Mcu_ExternalClkFreq = ((uint32) [!IF "McuClkConfig/McuClockSource != 'MCU_CLKSRC_OSC2' or McuClkConfig/McuClockSource != 'MCU_CLKSRC_OSC1'"!][!"McuClkConfig/McuExternalClkFreq"!][!ELSE!]0[!ENDIF!]U),
    .Mcu_SysClkDiv       = ((uint8) [!"McuClkConfig/McuSysClkDiv"!]U),
    .Mcu_HsmClkDiv       = ((Mcu_HsmClockDiv) [!"McuClkConfig/McuHsmClkDiv"!]),
    .Mcu_EpwmClkDiv      = ((Mcu_EPWMClkDivider) [!"McuClkConfig/McuEpwmClkDiv"!]),
    .Mcu_EmifClkDiv      = ((Mcu_EMIFClkDivider) [!"McuClkConfig/McuEmifClkDiv"!]),
    [!IF "as:modconf('Mcu')[as:path(node:dtos(.))='/TI_F29H85x/Mcu']/McuGeneralConfiguration/McuNoPll = 'false'"!]
    .Mcu_PllRefDiv       = ((uint8) [!"McuPllConfig/McuPLLRefDiv"!]U),
    .Mcu_PllIntMult      = ((uint8) [!"McuPllConfig/McuPLLIntMult"!]U),
    .Mcu_PllOutDiv       = ((uint8) [!"McuPllConfig/McuPLLOutDiv"!]U),[!ENDIF!]
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!]

/*
 * Design: MCAL-21878, MCAL-21879, MCAL-21880, MCAL-21881, MCAL-21882
 */
[!LOOP "McuModuleConfiguration/*"!][!VAR "RamCfgSetNo" = "@index"!]
static CONST(Mcu_RamSectionConfigType, MCU_CONFIG_DATA) Mcu_RamSectionCfgSet[!"num:i($RamCfgSetNo)"!][[!"num:i(count(McuRamSectorSettingConf/*))"!]] =
{
[!LOOP "McuRamSectorSettingConf/*"!]    {
    .Mcu_RamSectionBytes       = ((uint32) [!"McuRamSectionSize"!]U),
    .Mcu_RamSectionBaseAddress = ((uint8*) [!"num:inttohex(McuRamSectionBaseAddress,8)"!]U),
    .Mcu_RamDefaultValue       = ((uint8) [!"num:inttohex(McuRamDefaultValue,2)"!]U),
    .Mcu_RamSectionWriteSize   = ((uint8) [!"McuRamSectionWriteSize"!]U)
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!VAR "McuRamSectors" = "@index"!][!ENDIF!][!ENDLOOP!]
};[!VAR "Test1" = "McuRamSectors"!][!IF "McuRamSectors != 0"!][!VAR "Test2" = "$McuRamSectors + 1"!][!IF "num:i($Test2) != num:i($Test1)"!][!ERROR "McuRamSectors doesn't correspond to the number of Ram Sectors entered in McuRamSectorSettingConf"!][!ENDIF!][!ELSE!][!ENDIF!]
[!ENDLOOP!]

/*
 * Design: MCAL-21876, MCAL-21877, MCAL-21902, MCAL-21903
 */
[!LOOP "McuModuleConfiguration/*"!][!VAR "ModeCfgSetNo" = "@index"!]
static CONST(Mcu_ModeConfigType, MCU_CONFIG_DATA) Mcu_ModeConfigurationSet[!"num:i($ModeCfgSetNo)"!][[!"num:i(count(McuModeSettingConf/*))"!]] =
{
[!LOOP "McuModeSettingConf/*"!]    {
    .Mcu_LowPowerMode   = ((Mcu_LowPowerModeType) [!IF "McuMode = 0"!]MCU_IDLE_MODE[!ELSE!]MCU_STANDBY_MODE[!ENDIF!]),
    .Mcu_QualPeriod     = ((uint16) [!IF "McuMode = '1'"!][!"McuQualPeriod"!][!ELSE!]0[!ENDIF!]U),
    .Mcu_EnableWDWakeup = ((boolean) [!IF "McuEnableWDWakeup='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!]),
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!VAR "McuModes" = "@index"!][!ENDIF!][!ENDLOOP!]
};[!VAR "Test1" = "McuNumberOfMcuModes"!][!VAR "Test2" = "$McuModes + 1"!][!IF "num:i($Test2) != num:i($Test1)"!][!ERROR "McuNumberOfMcuModes doesn't correspond to the number of modes entered in McuModeSettingConf"!][!ENDIF!]
[!ENDLOOP!]

/*<MCU_CFG_CONFIG>*/
/*
 * Design: MCAL-21865, MCAL-21866, MCAL-21867, MCAL-21868, MCAL-21869, MCAL-21866
 */
/* Forward declaration of peripheral configuration structure */
static CONST(Mcu_PeripheralConfigType, MCU_CONFIG_DATA) Mcu_PeripheralConfig;

[!LOOP "McuModuleConfiguration/*"!]CONST(Mcu_ConfigType, MCU_CONFIG_DATA) Mcu_Config_[!"@name"!] =
{
    /* Mcu_ClockConfig */
    .Mcu_ClockConfig               = ((Mcu_ClockConfigPtrType) Mcu_ClkCfgSet[!"@index"!]),
    /* Mcu_ConfigRamSection */
    .Mcu_ConfigRamSection          = ((Mcu_RamConfigPtrType) Mcu_RamSectionCfgSet[!"@index"!]),
    /* Mcu_ModeConfig */
    .Mcu_ModeConfig                = ((Mcu_ModeConfigPtrType) Mcu_ModeConfigurationSet[!"@index"!]),
    /* Mcu_ClockSetting */
    .Mcu_ClockSetting              = ((uint8) [!"num:i(count(McuClockSettingConfig/*))"!]U),
    /* Mcu_NumberOfRamSectors */
    .Mcu_NumberOfRamSectors        = ((uint8) [!"McuRamSectors"!]U),
    /* Mcu_ModesNumber */
    .Mcu_NumberOfLowPowerModes     = ((uint8) [!"McuNumberOfMcuModes"!]U),
    /* Mcu_ResetSetting */
    .Mcu_ResetSetting              = ((Mcu_ResetType) [!IF "McuResetSetting = 1"!]MCU_EXTERNAL_RESET[!ELSE!][!"McuResetSetting"!]U[!ENDIF!]),
    /* Mcu_EnableClkFailNotification */
    .Mcu_EnableClkFailNotification = ((boolean) [!IF "McuClockSrcFailureNotification='ENABLED'"!]TRUE[!ELSE!]FALSE[!ENDIF!]),
    /* Peripheral Configuration */
    .PeripheralConfig              = &Mcu_PeripheralConfig
};
[!ENDLOOP!]
[!ENDSELECT!]

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
[!IF "node:exists(as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator'])"!][!//
[!SELECT "as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']"!][!//
[!/* Initialize peripheral configuration count */!][!//
[!VAR "McuPeripheralConfigCount" = "0"!][!//
[!/*
 * Macro to calculate register value from configuration parameters
 * RegValue = (FRAMESEL << 0) | (CPUSEL << 3) | (STANDBYEN << 6) | (DBGHALTEN << 7)
 */!][!//
/*********************************************************************************************************************
 *  Peripheral Configuration Array
 *
 *  Contains configuration entries for all peripherals with Frame configuration from ResourceAllocator.
 *  Each entry specifies the register address and the configuration value to write.
 *********************************************************************************************************************/
static CONST(Mcu_PeripheralRegEntryType, MCU_CONFIG_DATA) Mcu_PeripheralConfigSet[] =
{
[!VAR "firstEntry" = "'true'"!][!//
[!LOOP "ResourceAllocatorGeneral/Context/*"!][!//
    [!VAR "contextName" = "node:name(.)"!][!//
    [!VAR "coreName" = "node:value(./Core)"!][!//
    [!/* Determine CPUSEL value from context name */!][!//
    [!IF "node:value(./Core) = 'CPU1'"!][!//
        [!VAR "cpusel" = "0"!][!//
    [!ELSEIF "node:value(./Core) = 'CPU2'"!][!//
        [!VAR "cpusel" = "1"!][!//
    [!ELSEIF "node:value(./Core) = 'CPU3'"!][!//
        [!VAR "cpusel" = "2"!][!//
    [!ELSE!][!//
        [!VAR "cpusel" = "0"!][!//
    [!ENDIF!][!//
[!/* CAN Peripheral Instances */!][!//
[!IF "node:exists(./Can/*/CanAllocatedInstance)"!][!//
[!LOOP "./Can/*/CanAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!/* Calculate FRAMESEL value */!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!/* Calculate register value */!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* SPI Peripheral Instances */!][!//
[!IF "node:exists(./Spi/*/SpiAllocatedInstance)"!][!//
[!LOOP "./Spi/*/SpiAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* LIN Peripheral Instances */!][!//
[!IF "node:exists(./Lin/*/LinAllocatedInstance)"!][!//
[!LOOP "./Lin/*/LinAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Adc Peripheral Instances */!][!//
[!IF "node:exists(./Cdd_Adc/*/Cdd_AdcAllocatedInstance)"!][!//
[!LOOP "./Cdd_Adc/*/Cdd_AdcAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "regName" = "substring-after($instanceName, 'CDD_')"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$regName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Adc Safety Checker Instances */!][!//
[!IF "node:exists(./Cdd_Adc/*/CddAdcSafetyCheckerInstance)"!][!//
[!LOOP "./Cdd_Adc/*/CddAdcSafetyCheckerInstance/*"!][!//
[!VAR "instanceName" = "node:value(./SafetyCheckerInstance)"!][!//
[!VAR "regName" = "concat('ADCCHECKER', substring-after($instanceName, 'ADCSAFETYCHECK'))"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$regName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Adc Checker Interrupt Event Instances */!][!//
[!IF "node:exists(./Cdd_Adc/*/CddAdcCheckerInterruptEvtInstance)"!][!//
[!LOOP "./Cdd_Adc/*/CddAdcCheckerInterruptEvtInstance/*"!][!//
[!VAR "instanceName" = "node:value(./SafetyCheckerIntEvtInstance)"!][!//
[!VAR "regName" = "concat('ADCSEAGGRCPU', substring-after($instanceName, 'ADCSAFETYCHECKINTEVT'))"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$regName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Adc Global Software Force - FRAMESEL only (no CPUSEL, STANDBYEN, DBGHALTEN) */!][!//
[!IF "node:exists(./Cdd_Adc/*/CddAdcGlobalSoftwareForce)"!][!//
[!LOOP "./Cdd_Adc/*/CddAdcGlobalSoftwareForce/*"!][!//
[!VAR "instanceName" = "'ADC_GLOBAL_REGS'"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"node:value(./Frame)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Ecap Peripheral Instances */!][!//
[!IF "node:exists(./Cdd_Ecap/*/Cdd_EcapAllocatedInstance)"!][!//
[!LOOP "./Cdd_Ecap/*/Cdd_EcapAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_I2c Peripheral Instances */!][!//
[!IF "node:exists(./Cdd_I2c/*/Cdd_I2cAllocatedInstance)"!][!//
[!LOOP "./Cdd_I2c/*/Cdd_I2cAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Pwm Peripheral Instances */!][!//
[!IF "node:exists(./Cdd_Pwm/*/Cdd_PwmAllocatedInstance)"!][!//
[!LOOP "./Cdd_Pwm/*/Cdd_PwmAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Pwm HRPWM Cal Instances - FRAMESEL only (no CPUSEL, STANDBYEN, DBGHALTEN) */!][!//
[!IF "node:exists(./Cdd_Pwm/*/CddPwmHrpwmCalInstance)"!][!//
[!LOOP "./Cdd_Pwm/*/CddPwmHrpwmCalInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "regName" = "concat('HRCAL', substring-after($instanceName, 'HRPWMCAL'))"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"node:value(./Frame)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$regName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Sent Peripheral Instances */!][!//
[!IF "node:exists(./Cdd_Sent/*/Cdd_SentAllocatedInstance)"!][!//
[!LOOP "./Cdd_Sent/*/Cdd_SentAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Uart Peripheral Instances */!][!//
[!IF "node:exists(./Cdd_Uart/*/Cdd_UartAllocatedInstance)"!][!//
[!LOOP "./Cdd_Uart/*/Cdd_UartAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Cdd_Cmpss Peripheral Instances */!][!//
[!IF "node:exists(./Cdd_Cmpss/*/Cdd_CmpssAllocatedInstance)"!][!//
[!LOOP "./Cdd_Cmpss/*/Cdd_CmpssAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Eqep Peripheral Instances */!][!//
[!IF "node:exists(./Eqep/*/EqepAllocatedInstance)"!][!//
[!LOOP "./Eqep/*/EqepAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//

[!/* Sdfm Peripheral Instances */!][!//
[!IF "node:exists(./Sdfm/*/SdfmAllocatedInstance)"!][!//
[!LOOP "./Sdfm/*/SdfmAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Pmbus Peripheral Instances */!][!//
[!IF "node:exists(./Pmbus/*/PmbusAllocatedInstance)"!][!//
[!LOOP "./Pmbus/*/PmbusAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Dac Peripheral Instances */!][!//
[!IF "node:exists(./Dac/*/DacAllocatedInstance)"!][!//
[!LOOP "./Dac/*/DacAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Clb Peripheral Instances */!][!//
[!IF "node:exists(./Clb/*/ClbAllocatedInstance)"!][!//
[!LOOP "./Clb/*/ClbAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* FsiTx Peripheral Instances */!][!//
[!IF "node:exists(./FsiTx/*/FsiTxAllocatedInstance)"!][!//
[!LOOP "./FsiTx/*/FsiTxAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* FsiRx Peripheral Instances */!][!//
[!IF "node:exists(./FsiRx/*/FsiRxAllocatedInstance)"!][!//
[!LOOP "./FsiRx/*/FsiRxAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Dcc Peripheral Instances */!][!//
[!IF "node:exists(./Dcc/*/DccAllocatedInstance)"!][!//
[!LOOP "./Dcc/*/DccAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Epg Peripheral Instances */!][!//
[!IF "node:exists(./Epg/*/EpgAllocatedInstance)"!][!//
[!LOOP "./Epg/*/EpgAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* Wadi Peripheral Instances */!][!//
[!IF "node:exists(./Wadi/*/WadiAllocatedInstance)"!][!//
[!LOOP "./Wadi/*/WadiAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!VAR "regValue" = "num:i($regValue) + num:i($cpusel * 8)"!][!//
[!IF "node:value(./StandbyModeEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 64"!][!//
[!ENDIF!][!//
[!IF "node:value(./DebugHaltEnabled) = 'true'"!][!//
[!VAR "regValue" = "num:i($regValue) + 128"!][!//
[!ENDIF!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"$coreName"!], [!"node:value(./Frame)"!], DbgHalt=[!"node:value(./DebugHaltEnabled)"!], Standby=[!"node:value(./StandbyModeEnabled)"!] */
    {
        .RegAddr = (uint32)(DEVCFG_BASE + SYSCTL_O_[!"$instanceName"!]),
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* End of Context loop */!][!//
[!/* ===== Cdd_Xbar OUTPUT_XBAR_FLAG - FRAMESEL only ===== */!][!//
[!IF "node:exists(as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/Cdd_Xbar/*/CddXbarOutputXbarFlag/*)"!][!//
[!LOOP "as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/Cdd_Xbar/*/CddXbarOutputXbarFlag/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regAddr" = "node:value(./BaseAddr)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"node:value(./Frame)"!] */
    {
        .RegAddr = (uint32)[!"$regAddr"!],
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* ===== Cdd_Xbar INPUT_XBAR_FLAG - FRAMESEL only ===== */!][!//
[!IF "node:exists(as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/Cdd_Xbar/*/CddXbarInputFlag/*)"!][!//
[!LOOP "as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/Cdd_Xbar/*/CddXbarInputFlag/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regAddr" = "node:value(./BaseAddr)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"node:value(./Frame)"!] */
    {
        .RegAddr = (uint32)[!"$regAddr"!],
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* ===== DLTFifoRegs (DLT) - FRAMESEL only ===== */!][!//
[!IF "node:exists(as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/DLTFifoRegs/*/DLTFifoRegsAllocatedInstance/*)"!][!//
[!LOOP "as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/DLTFifoRegs/*/DLTFifoRegsAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regAddr" = "node:value(./BaseAddr)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"node:value(./Frame)"!] */
    {
        .RegAddr = (uint32)[!"$regAddr"!],
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* ===== Error_Aggregator (ERROR_AGGREGATOR) - FRAMESEL only ===== */!][!//
[!IF "node:exists(as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/Error_Aggregator/*/Error_AggregatorAllocatedInstance/*)"!][!//
[!LOOP "as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/Error_Aggregator/*/Error_AggregatorAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regAddr" = "node:value(./BaseAddr)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"node:value(./Frame)"!] */
    {
        .RegAddr = (uint32)[!"$regAddr"!],
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!/* ===== ESM - FRAMESEL only ===== */!][!//
[!IF "node:exists(as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/ESM/*/ESMAllocatedInstance/*)"!][!//
[!LOOP "as:modconf('ResourceAllocator')[as:path(node:dtos(.))='/TI_F29H85x/ResourceAllocator']/ResourceAllocatorGeneral/ESM/*/ESMAllocatedInstance/*"!][!//
[!VAR "instanceName" = "node:value(./InstanceName)"!][!//
[!VAR "framesel" = "substring(node:value(./Frame), 6)"!][!//
[!VAR "regAddr" = "node:value(./BaseAddr)"!][!//
[!VAR "regValue" = "num:i($framesel)"!][!//
[!IF "$firstEntry = 'false'"!],
[!ENDIF!]
    /* [!"$instanceName"!] Configuration - [!"node:value(./Frame)"!] */
    {
        .RegAddr = (uint32)[!"$regAddr"!],
        .RegValue = (uint32)[!"translate(text:toupper(num:inttohex($regValue, 8)), 'X', 'x')"!]U
    }[!VAR "firstEntry" = "'false'"!][!VAR "McuPeripheralConfigCount" = "$McuPeripheralConfigCount + 1"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
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
    .PeripheralConfigCount   = [!"num:i($McuPeripheralConfigCount)"!]U
};

[!ENDSELECT!]
[!ELSE!]
/*********************************************************************************************************************
 *  ResourceAllocator module not present - No peripheral configuration generated
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  Peripheral Configuration Structure (Empty - No ResourceAllocator)
 *********************************************************************************************************************/
static CONST(Mcu_PeripheralConfigType, MCU_CONFIG_DATA) Mcu_PeripheralConfig =
{
    .PeripheralConfigEntries = NULL_PTR,
    .PeripheralConfigCount   = 0U
};
[!ENDIF!]

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
