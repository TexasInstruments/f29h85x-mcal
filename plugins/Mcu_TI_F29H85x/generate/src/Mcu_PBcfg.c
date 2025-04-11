[!SKIPFILE "as:modconf('Mcu')[1]/IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!][!//
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

#define MCU_START_SEC_CONFIG_DATA
#include "Mcu_MemMap.h"
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * AUTOSAR version information check.
 *********************************************************************************************************************/
#if ((MCU_SW_MAJOR_VERSION != (1U)) || (MCU_SW_MINOR_VERSION != (1U)))
    #error "Version numbers of Mcu_PBcfg.c and Mcu.h are inconsistent!"
#endif

#if ((MCU_CFG_MAJOR_VERSION != (1U)) || (MCU_CFG_MINOR_VERSION != (1U)))
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
[!LOOP "as:modconf('Mcu')[1]/McuModuleConfiguration/*"!][!VAR "ClkCfgSetNo" = "@index"!]
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


[!LOOP "as:modconf('Mcu')[1]/McuModuleConfiguration/*"!][!VAR "ClkCfgSetNo" = "@index"!]
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


[!LOOP "as:modconf('Mcu')[1]/McuModuleConfiguration/*"!]
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

[!LOOP "as:modconf('Mcu')[1]/McuModuleConfiguration/*"!]
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
[!LOOP "as:modconf('Mcu')[1]/McuModuleConfiguration/*"!][!VAR "McuModuleCfgSetNo" = "@index"!]
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
    [!IF "as:modconf('Mcu')[1]/McuGeneralConfiguration/McuNoPll = 'false'"!]
    .Mcu_PllRefDiv       = ((uint8) [!"McuPllConfig/McuPLLRefDiv"!]U),
    .Mcu_PllIntMult      = ((uint8) [!"McuPllConfig/McuPLLIntMult"!]U),
    .Mcu_PllOutDiv       = ((uint8) [!"McuPllConfig/McuPLLOutDiv"!]U),[!ENDIF!]
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
};
[!ENDLOOP!]

/*
 * Design: MCAL-21878, MCAL-21879, MCAL-21880, MCAL-21881, MCAL-21882
 */
[!LOOP "as:modconf('Mcu')[1]/McuModuleConfiguration/*"!][!VAR "RamCfgSetNo" = "@index"!]
static CONST(Mcu_RamSectionConfigType, MCU_CONFIG_DATA) Mcu_RamSectionCfgSet[!"num:i($RamCfgSetNo)"!][[!"num:i(count(McuRamSectorSettingConf/*))"!]] =
{
[!LOOP "McuRamSectorSettingConf/*"!]    {
    .Mcu_RamSectionBytes       = ((uint32) [!"McuRamSectionSize"!]U),
    .Mcu_RamSectionBaseAddress = ((uint8*) [!"num:inttohex(McuRamSectionBaseAddress,8)"!]),
    .Mcu_RamDefaultValue       = ((uint8) [!"num:inttohex(McuRamDefaultValue,2)"!]U),
    .Mcu_RamSectionWriteSize   = ((uint8) [!"McuRamSectionWriteSize"!]U)
    }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!VAR "McuRamSectors" = "@index"!][!ENDIF!][!ENDLOOP!]
};[!VAR "Test1" = "McuRamSectors"!][!IF "McuRamSectors != 0"!][!VAR "Test2" = "$McuRamSectors + 1"!][!IF "num:i($Test2) != num:i($Test1)"!][!ERROR "McuRamSectors doesn't correspond to the number of Ram Sectors entered in McuRamSectorSettingConf"!][!ENDIF!][!ELSE!][!ENDIF!]
[!ENDLOOP!]

/*
 * Design: MCAL-21876, MCAL-21877, MCAL-21902, MCAL-21903
 */
[!LOOP "as:modconf('Mcu')[1]/McuModuleConfiguration/*"!][!VAR "ModeCfgSetNo" = "@index"!]
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
[!LOOP "as:modconf('Mcu')[1]/McuModuleConfiguration/*"!]CONST(Mcu_ConfigType, MCU_CONFIG_DATA) [!"@name"!] =
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
    .Mcu_EnableClkFailNotification = ((boolean) [!IF "McuClockSrcFailureNotification='ENABLED'"!]TRUE[!ELSE!]FALSE[!ENDIF!])
};
[!ENDLOOP!]


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
