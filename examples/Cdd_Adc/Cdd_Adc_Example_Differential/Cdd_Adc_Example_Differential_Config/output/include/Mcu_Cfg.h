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
 *  File:       Mcu_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data                                                     
 *********************************************************************************************************************/
#ifndef MCU_CFG_H
#define MCU_CFG_H

/**
 * \addtogroup MCU Mcu API GUIDE configurator header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * \brief Mcu Driver Configuration SW Version Info.
 *********************************************************************************************************************/
#define MCU_CFG_MAJOR_VERSION               (1U)
#define MCU_CFG_MINOR_VERSION               (1U)
#define MCU_CFG_PATCH_VERSION               (0U)


/*********************************************************************************************************************
 * \brief MCU Build Variant.
 * Build variants.(i.e Precompile, postbuild or linktime)
 *********************************************************************************************************************/
/*
 * Design: MCAL-21858
 */

/*
 * Design: MCAL-21784, MCAL-21857
 */
#define MCU_CFG_PRE_COMPILE_VARIANT   (STD_ON)



/* Pre Compile config macro name. */

#define MCU_INIT_CONFIG_PC        Mcu_ModuleConfiguration_0




/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define MCU_CFG_DEM_ENABLE    (STD_ON)

/*
 * Design: MCAL-21874, MCAL-21875
 */

/** \brief MCU DEM Event Configuration: MCU Clock failed - AUTOSAR ECUC Driver SWS Item - ECUC_Mcu_00188*/
#define MCU_E_CLOCK_FAILURE  (DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE)


/*********************************************************************************************************************
 * \brief Enable/Disable Lock registers mechanism for clock configuration registers.
 *********************************************************************************************************************/
#define MCU_CLOCK_CONFIG_LOCK_CRITICAL_REGISTERS    (STD_OFF)

/*********************************************************************************************************************
 * \brief Enable/Disable Lock registers mechanism for cpu peripheral configuration registers.
 *********************************************************************************************************************/
#define MCU_CPU_PERIPHERAL_CONFIG_LOCK_CRITICAL_REGISTERS    (STD_OFF)

/*********************************************************************************************************************
 * \brief Enable/Disable Lock registers mechanism for cpu system registers.
 *********************************************************************************************************************/
#define MCU_CPU_SYSTEM_LOCK_CRITICAL_REGISTERS    (STD_OFF)


/*********************************************************************************************************************
 * \brief Enable/Disable Development Error Detection.
 *********************************************************************************************************************/
/*
 * Design: MCAL-21859
 */
#define MCU_CFG_DEV_ERROR_DETECT    (STD_ON)

/*********************************************************************************************************************
 * \brief Enable/Disable Mcu_CheckRamState().
 *********************************************************************************************************************/
 /*
 * Design: MCAL-21860
 */
#define MCU_CFG_GET_RAM_STATE_API    (STD_ON)

/*********************************************************************************************************************
 * \brief Enable/Disable Mcu_InitClock().
 *********************************************************************************************************************/
/*
 * Design: MCAL-21861
 */
#define MCU_CFG_INIT_CLOCK_API    (STD_ON)

/*********************************************************************************************************************
 * \brief Enable/Disable PLL support
 *********************************************************************************************************************/
/*
 * Design: MCAL-21862
 */
#define MCU_CFG_NO_PLL    (STD_OFF)

/*********************************************************************************************************************
 * \brief Enable/Disable Mcu_PerformReset().
 *********************************************************************************************************************/
/*
 * Design: MCAL-21863
 */
#define MCU_CFG_PERFORM_RESET_API    (STD_ON)

/*********************************************************************************************************************
 * \brief Enable/Disable Mcu_GetVersionInfo().
 *********************************************************************************************************************/
/*
 * Design: MCAL-21864
 */
#define MCU_CFG_GET_VERSION_INFO_API    (STD_ON)

/**************************************************************************************************************************
 * \brief The following defines shall be used as input parameter for: Mcu_InitClock(), Mcu_InitRamSection(), Mcu_SetMode() .
 **************************************************************************************************************************/

/*********************************************************************************************************************
 * \brief Clock configuration.
 *********************************************************************************************************************/

/*<MCU_CFG_CLOCKUSERCONFIG_LIST>*/

#define McuConf_McuClockSettingConfig_McuClockSettingConfig_Osc2 (0u) /*~ASR~*/


#define McuConf_McuClockSettingConfig_McuClockSettingConfig_Xtal (1u) /*~ASR~*/


#define McuConf_McuClockSettingConfig_McuClockSettingConfig_XtalSE (2u) /*~ASR~*/


/*</MCU_CFG_CLOCKUSERCONFIG_LIST>*/

/*********************************************************************************************************************
 * \brief RAM Section configuration
 *********************************************************************************************************************/
/*<MCU_CFG_RAMSECTIONUSERCONFIG_LIST>*/

/*</MCU_CFG_RAMSECTIONUSERCONFIG_LIST>*/

/*********************************************************************************************************************
 * \brief POWERMODE Section configuration
 *********************************************************************************************************************/
/*<MCU_CFG_POWERMODEUSERCONFIG_LIST>*/

#define McuConf_McuModeSettingConf_McuModeSettingConf_0 (0u) /*~ASR~*/


#define McuConf_McuModeSettingConf_McuModeSettingConf_1 (1u) /*~ASR~*/


/*</MCU_CFG_POWERMODEUSERCONFIG_LIST>*/

/*********************************************************************************************************************
 * \brief Published information Reset reasons configuration
 *********************************************************************************************************************/
/*<MCU_CFG_RESETREASONUSERCONFIG_LIST>*/

/*
 * Design: MCAL-21883, MCAL-21884, MCAL-21885
 */

#define McuConf_McuResetReasonConf_MCU_POWER_ON_RESET (0u) /*~ASR~*/


#define McuConf_McuResetReasonConf_MCU_EXTERNAL_RESET (1u) /*~ASR~*/


#define McuConf_McuResetReasonConf_MCU_ESM_NMI_WATCHDOG_RESET (2u) /*~ASR~*/


#define McuConf_McuResetReasonConf_MCU_WATCHDOG_RESET (3u) /*~ASR~*/


#define McuConf_McuResetReasonConf_MCU_SW_RESET (4u) /*~ASR~*/


#define McuConf_McuResetReasonConf_MCU_ESM_RESET (5u) /*~ASR~*/


#define McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED (6u) /*~ASR~*/



#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/


 /** \brief Structure for data pre-setting to be initialized */
typedef struct
{
    /** \brief Section Size */
    uint32                                Mcu_RamSectionBytes;  
    /** \brief RAM section base address */      
    P2VAR(uint8, AUTOMATIC, MCU_APPL_DATA) Mcu_RamSectionBaseAddress; 
    /** \brief RAM Default Value */
    uint8                                 Mcu_RamDefaultValue; 
    /** \brief RAM Section Write Size */      
    uint8                                 Mcu_RamSectionWriteSize;    

} Mcu_RamSectionConfigType;

/*********************************************************************************************************************
 *  \brief Pointer to RamConfig structure
 *********************************************************************************************************************/
/*
 * Design: MCAL-21931
 */
typedef P2CONST (Mcu_RamSectionConfigType, AUTOMATIC, MCU_CONFIG_DATA) Mcu_RamConfigPtrType;


/** \brief Type of the clock sources */
 /*
 * Design: MCAL-21933
 */
typedef enum
{
    /** \brief Internal Oscillator 2  */ 
    MCU_CLKSRC_OSC2      = 0x00,
    /** \brief External XTAL   */ 
    MCU_CLKSRC_XTAL      = 0x01,
    /** \brief External XTAL Single-ended mode  */ 
    MCU_CLKSRC_XTAL_SE   = 0x11,
    /** \brief Internal Oscillator 1  */ 
    MCU_CLKSRC_OSC1      = 0x02,
} Mcu_ClkSourceIdType;


/** \brief The following are clock sources available for Cpu Timer module */
/*
 * Design: MCAL-21940
 */
typedef enum
{
    /** \brief SYSCLK (default on reset)  */ 
    MCU_CPUTIMERCLKSRC_SYSCLK  = 0U,
    /** \brief Internal Oscillator 1  */ 
    MCU_CPUTIMERCLKSRC_INTOSC1 = 1U,
    /** \brief Internal Oscillator 2   */ 
    MCU_CPUTIMERCLKSRC_INTOSC2 = 2U,
    /** \brief External Oscillator (XTAL) */ 
    MCU_CPUTIMERCLKSRC_XTAL    = 3U,
    MCU_CPUTIMERCLKSRC_MAX
} Mcu_CpuTimerClkSrc;


/** \brief The following are clock sources available for MCAN module. */
 /*
 * Design: MCAL-21939
 */
typedef enum
{
    /** \brief SYSCLK (default on reset)  */
    MCU_MCANCLKSRC_PERxSYSCLK = 0U,
    /** \brief SYSCLK (default on reset)  */
    MCU_MCANCLKSRC_AUXCLKIN   = 2U,
    /** \brief Raw PLL Clock  */
    MCU_MCANCLKSRC_PLLRAWCLK  = 3U,
    MCU_MCANCLKSRC_MAX
} Mcu_MCanClkSrc;


/** \brief The following are dividers available for MCAN module. */
typedef enum
{
    /** \brief MCAN clock =  MCAN clock source / 1 */ 
    MCU_MCANCLK_DIV_1  = 0x0,
    /** \brief MCAN clock =  MCAN clock source / 2 */     
    MCU_MCANCLK_DIV_2  = 0x1,
    /** \brief MCAN clock =  MCAN clock source / 3 */      
    MCU_MCANCLK_DIV_3  = 0x2, 
    /** \brief MCAN clock =  MCAN clock source / 4 */    
    MCU_MCANCLK_DIV_4  = 0x3, 
    /** \brief MCAN clock =  MCAN clock source / 5 */    
    MCU_MCANCLK_DIV_5  = 0x4,  
    /** \brief MCAN clock =  MCAN clock source / 6 */   
    MCU_MCANCLK_DIV_6  = 0x5,  
    /** \brief MCAN clock =  MCAN clock source / 7 */  
    MCU_MCANCLK_DIV_7  = 0x6,
    /** \brief MCAN clock =  MCAN clock source / 8 */   
    MCU_MCANCLK_DIV_8  = 0x7, 
    /** \brief MCAN clock =  MCAN clock source / 9 */   
    MCU_MCANCLK_DIV_9  = 0x8,  
    /** \brief MCAN clock =  MCAN clock source / 10 */  
    MCU_MCANCLK_DIV_10 = 0x9,
    /** \brief MCAN clock =  MCAN clock source / 11 */    
    MCU_MCANCLK_DIV_11 = 0xA,   
    /** \brief MCAN clock =  MCAN clock source / 12 */ 
    MCU_MCANCLK_DIV_12 = 0xB,  
    /** \brief MCAN clock =  MCAN clock source / 13 */    
    MCU_MCANCLK_DIV_13 = 0xC, 
    /** \brief MCAN clock =  MCAN clock source / 14 */   
    MCU_MCANCLK_DIV_14 = 0xD,  
    /** \brief MCAN clock =  MCAN clock source / 15 */ 
    MCU_MCANCLK_DIV_15 = 0xE,   
    /** \brief MCAN clock =  MCAN clock source / 16 */  
    MCU_MCANCLK_DIV_16 = 0xF,     
    /** \brief MCAN clock =  MCAN clock source / 17 */  
    MCU_MCANCLK_DIV_17 = 0x10,  
    /** \brief MCAN clock =  MCAN clock source / 18 */
    MCU_MCANCLK_DIV_18 = 0x11,    
    /** \brief MCAN clock =  MCAN clock source / 19 */  
    MCU_MCANCLK_DIV_19 = 0x12,  
    /** \brief MCAN clock =  MCAN clock source / 20 */  
    MCU_MCANCLK_DIV_20 = 0x13   
} Mcu_MCANClkDivider;


/** \brief The following are instances available for MCAN module. */
typedef enum
{
    /** \brief MCAN Instance A */
    MCU_MCAN_A = 0U,
    /** \brief MCAN Instance B */
    MCU_MCAN_B = 1U,
    /** \brief MCAN Instance C */
    MCU_MCAN_C = 2U,
    /** \brief MCAN Instance D */
    MCU_MCAN_D = 3U,
    /** \brief MCAN Instance E */
    MCU_MCAN_E = 4U,
    /** \brief MCAN Instance F */
    MCU_MCAN_F = 5U
} Mcu_MCANInstance;


/** \brief The following are clock sources available for XCLKOUT module. */
typedef enum
{
    /** \brief PLL System Clock post SYSCLKDIV  */
    MCU_XCLKOUTSRC_PLLSYS     = 0U,
    /** \brief CPU1.CLOCK                       */     
    MCU_XCLKOUTSRC_CPU1CLK    = 1U,  
    /** \brief CPU2.CLOCK                       */  
    MCU_XCLKOUTSRC_CPU2CLK    = 2U,   
    /** \brief CPU3.CLOCK                       */ 
    MCU_XCLKOUTSRC_CPU3CLK    = 3U, 
    /** \brief Internal Oscillator 1            */  
    MCU_XCLKOUTSRC_INTOSC1    = 5U,   
    /** \brief Internal Oscillator 2            */ 
    MCU_XCLKOUTSRC_INTOSC2    = 6U, 
    /** \brief External Oscillator              */   
    MCU_XCLKOUTSRC_XTALOSC    = 7U,   
} Mcu_ExternalClockOutClkSrc;


/** \brief The following are dividers available for XCLKOUT. */
typedef enum
{
    /** \brief divided by 1 */
    MCU_XCLKOUT_DIV_1 = 0U, 
    /** \brief divided by 2 */      
    MCU_XCLKOUT_DIV_2 = 1U,
    /** \brief divided by 4 */       
    MCU_XCLKOUT_DIV_4 = 2U,  
    /** \brief divided by 8 */     
    MCU_XCLKOUT_DIV_8 = 3U,       
} Mcu_ExternalClockOutDiv;


/** \brief The following are dividers available for Ethercat clock. */
typedef enum
{
    /** \brief divided by 1 */
    MCU_ECATCLKOUT_DIV_1 = 0U,   
    /** \brief divided by 2 */    
    MCU_ECATCLKOUT_DIV_2 = 1U, 
    /** \brief divided by 3 */      
    MCU_ECATCLKOUT_DIV_3 = 2U,   
    /** \brief divided by 4 */    
    MCU_ECATCLKOUT_DIV_4 = 3U,    
    /** \brief divided by 5 */   
    MCU_ECATCLKOUT_DIV_5 = 4U,       
    /** \brief divided by 6 */
    MCU_ECATCLKOUT_DIV_6 = 5U,   
    /** \brief divided by 7 */    
    MCU_ECATCLKOUT_DIV_7 = 6U,      
    /** \brief divided by 8 */ 
    MCU_ECATCLKOUT_DIV_8 = 7U,       
} Mcu_EthercatClockDiv;


/** \brief The following are values available to set enable/disable for EthcatPhyClock */
typedef enum
{
    /** \brief Enable value 0x100 */
    MCU_ECAT_PHYCLK_ENABLE  = 0x100U, 
    /** \brief Disable value 0 */
    MCU_ECAT_PHYCLK_DISABLE = 0U,
} Mcu_EthercatPhyClk;


/** \brief The following are dividers available for HSM clock. */
typedef enum
{
    /** \brief divided by 1 */
    MCU_HSMCLK_DIV_1  = 0U, 
    /** \brief divided by 2 */      
    MCU_HSMCLK_DIV_2  = 1U,
    /** \brief divided by 4 */       
    MCU_HSMCLK_DIV_4  = 2U,
    /** \brief divided by 8 */       
    MCU_HSMCLK_DIV_8  = 3U, 
    /** \brief divided by 16 */      
    MCU_HSMCLK_DIV_16 = 4U,       
} Mcu_HsmClockDiv;


/** \brief The following are dividers available for EPWM clock. */
typedef enum
{
    /** \brief EPWMCLK = PLLSYSCLK / 1 */
    MCU_EPWMCLK_DIV_1 = 0U, 
    /** \brief EPWMCLK = PLLSYSCLK / 2 */      
    MCU_EPWMCLK_DIV_2 = 1U,       
} Mcu_EPWMClkDivider;


/** \brief The following are dividers available for EMIF clock. */
typedef enum
{
    /** \brief EMIF1CLK = PLLSYSCLK / 1 */
    MCU_EMIFCLK_DIV_1 = 0U,
    /** \brief EMIF1CLK = PLLSYSCLK / 2 */       
    MCU_EMIFCLK_DIV_2 = 1U,
    /** \brief EMIF1CLK = PLLSYSCLK / 4 */       
    MCU_EMIFCLK_DIV_4 = 2U,       
} Mcu_EMIFClkDivider;


/** \brief The following are dividers available for LIN clock. */
typedef enum
{
    /** \brief LINCLK = PLLSYSCLK / 1 */
    MCU_LINCLK_DIV_1 = 0U, 
    /** \brief LINCLK = PLLSYSCLK / 2 */      
    MCU_LINCLK_DIV_2 = 1U,  
    /** \brief LINCLK = PLLSYSCLK / 4 */    
    MCU_LINCLK_DIV_4 = 2U,       
} Mcu_LINClkDivider;


/** \brief The following are instances available for LIN module. */
typedef enum
{
    /** \brief LIN Instance A */
    MCU_LIN_A = 0U,
    /** \brief LIN Instance B */
    MCU_LIN_B = 1U,
} Mcu_LINInstance;


/** \brief Structure for LIN clock register setting */
typedef struct
{
    /** \brief Lin Instance */
    Mcu_LINInstance    Mcu_LinInstance;
    /** \brief Lin Clock divider */
    Mcu_LINClkDivider  Mcu_LinClkDiv;
} Mcu_LinClkConfigType;


/** \brief Structure for EtherCat clock setting */
/*
 * Design: MCAL-23092, MCAL-23093
 */
typedef struct
{
    /** \brief Ethercat clock  divider */
    Mcu_EthercatClockDiv Mcu_EthercatClkDiv; 
    /** \brief Ethercat clock enable/disable */     
    Mcu_EthercatPhyClk   Mcu_EthercatPhyClkEnable; 
} Mcu_EthercatClkConfigType;


/** \brief Structure for MCAN clock register setting */
/*
* Design: MCAL-21936
*/
typedef struct
{
    /** \brief Mcan Instance ID */
    Mcu_MCANInstance    Mcu_MCanInstance;
    /** \brief Mcan Clock Source */
    Mcu_MCanClkSrc      Mcu_MCanClkSource;
    /** \brief Mcan Clock Divider */
    Mcu_MCANClkDivider  Mcu_MCanClkDiv;
} Mcu_MCanClkConfigType;


/** \brief Structure for Cpu Timer clock register setting */
/*
 * Design: MCAL-21937
 */
typedef struct
{
    /** \brief Cputimer2 clock source */
    Mcu_CpuTimerClkSrc Mcu_CpuTimer2ClkSource;
    /** \brief Cputimer2 clock divider */
    uint8              Mcu_CpuTimer2ClkDiv;
} Mcu_CpuTimerClkConfigType;


/** \brief Structure for External Clock Output setting */
/*
 * Design: MCAL-23088, MCAL-23089, MCAL-23090
 */
typedef struct
{
    /** \brief External clock output source */
    Mcu_ExternalClockOutClkSrc Mcu_ExternalClockOutSource;
    /** \brief External clock output divider */ 
    Mcu_ExternalClockOutDiv    Mcu_ExternalClkOutDiv; 
    /** \brief External clock output enable/disable flag */     
    boolean                    Mcu_ExternalClockOut;      
} Mcu_ExternalClkOutConfigType;


/** \brief Structure for peripheral clock register setting */
typedef struct
{
    /** \brief Peripheral Clock Gating Registers */
    uint32 Mcu_PeripheralClk0Reg; 
    /** \brief Peripheral Clock Gating Register - EMIF */  
    uint32 Mcu_PeripheralClk1Reg; 
    /** \brief Peripheral Clock Gating Register - ETPWM */  
    uint32 Mcu_PeripheralClk2Reg;  
    /** \brief Peripheral Clock Gating Register - ECAP */ 
    uint32 Mcu_PeripheralClk3Reg;  
    /** \brief Peripheral Clock Gating Register - EQEP */ 
    uint32 Mcu_PeripheralClk4Reg;   
    /* Reserved */
    /** \brief Peripheral Clock Gating Register - SDFM  */
    uint32 Mcu_PeripheralClk6Reg;  
    /** \brief Peripheral Clock Gating Register - SCI, UART  */ 
    uint32 Mcu_PeripheralClk7Reg; 
    /** \brief Peripheral Clock Gating Register - SPI  */  
    uint32 Mcu_PeripheralClk8Reg; 
    /** \brief Peripheral Clock Gating Register - I2C  */  
    uint32 Mcu_PeripheralClk9Reg;  
    /** \brief Peripheral Clock Gating Register - CAN  */ 
    uint32 Mcu_PeripheralClk10Reg;  
    /* Reserved */
    /* Reserved */
    /** \brief Peripheral Clock Gating Register - ADC  */
    uint32 Mcu_PeripheralClk13Reg;  
    /** \brief Peripheral Clock Gating Register -  CMPSS  */ 
    uint32 Mcu_PeripheralClk14Reg;   
    /* Reserved */
    /** \brief Peripheral Clock Gating Register - Buf_DAC */
    uint32 Mcu_PeripheralClk16Reg;  
    /** \brief Peripheral Clock Gating Register - CLB */ 
    uint32 Mcu_PeripheralClk17Reg;
    /** \brief Peripheral Clock Gating Register - FSI */  
    uint32 Mcu_PeripheralClk18Reg; 
    /** \brief Peripheral Clock Gating Register - LIN */  
    uint32 Mcu_PeripheralClk19Reg;
    /** \brief Peripheral Clock Gating Register - PMBUS */   
    uint32 Mcu_PeripheralClk20Reg;
    /** \brief Peripheral Clock Gating Register - DCC */   
    uint32 Mcu_PeripheralClk21Reg;   
    /* Reserved */
    /** \brief Peripheral Clock Gating Register - EtherCAT */
    uint32 Mcu_PeripheralClk23Reg;   
    /* Reserved */
    /** \brief Peripheral Clock Gating Register -  HRCAL0,1,2 */
    uint32 Mcu_PeripheralClk25Reg;   
    /* Reserved */
    /** \brief Peripheral Clock Gating Register - EPG */
    uint32 Mcu_PeripheralClk27Reg; 
    /** \brief Peripheral Clock Gating Register - ADCCHECKER */  
    uint32 Mcu_PeripheralClk28Reg;  
    /* Reserved */
    /** \brief Peripheral Clock Gating Register - SENT */
    uint32 Mcu_PeripheralClk30Reg;   
    /* Reserved */
    /** \brief Peripheral Clock Gating Register - WADI */
    uint32 Mcu_PeripheralClk32Reg;   
} Mcu_PeripheralClkRegConfigType;

/*********************************************************************************************************************
 *  \brief Pointer to Mcu_PeripheralClkRegConfigType structure
 *********************************************************************************************************************/
 /*
 * Design: MCAL-21935
 */
typedef P2CONST(Mcu_PeripheralClkRegConfigType, AUTOMATIC, MCU_CONFIG_DATA) Mcu_PeripheralClkRegConfigPtrType;


/** \brief Structure for peripheral Reset register setting */
typedef struct
{
    /** \brief Peripheral Reset Registers */
    uint32 Mcu_PeripheralReset0Reg; 
    /** \brief Peripheral Reset Register - EMIF */  
    uint32 Mcu_PeripheralReset1Reg; 
    /** \brief Peripheral Reset Register - ETPWM */  
    uint32 Mcu_PeripheralReset2Reg;  
    /** \brief Peripheral Reset Register - ECAP */ 
    uint32 Mcu_PeripheralReset3Reg;  
    /** \brief Peripheral Reset Register - EQEP */ 
    uint32 Mcu_PeripheralReset4Reg;   
    /* Reserved */
    /** \brief Peripheral Reset Register - SDFM  */
    uint32 Mcu_PeripheralReset6Reg;  
    /** \brief Peripheral Reset Register - SCI, UART  */ 
    uint32 Mcu_PeripheralReset7Reg; 
    /** \brief Peripheral Reset Register - SPI  */  
    uint32 Mcu_PeripheralReset8Reg; 
    /** \brief Peripheral Reset Register - I2C  */  
    uint32 Mcu_PeripheralReset9Reg;  
    /** \brief Peripheral Reset Register - CAN  */ 
    uint32 Mcu_PeripheralReset10Reg;  
    /* Reserved */
    /* Reserved */
    /** \brief Peripheral Reset Register - ADC  */
    uint32 Mcu_PeripheralReset13Reg;  
    /** \brief Peripheral Reset Register -  CMPSS  */ 
    uint32 Mcu_PeripheralReset14Reg;   
    /* Reserved */
    /** \brief Peripheral Reset Register - Buf_DAC */
    uint32 Mcu_PeripheralReset16Reg;  
    /** \brief Peripheral Reset Register - CLB */ 
    uint32 Mcu_PeripheralReset17Reg;
    /** \brief Peripheral Reset Register - FSI */  
    uint32 Mcu_PeripheralReset18Reg; 
    /** \brief Peripheral Reset Register - LIN */  
    uint32 Mcu_PeripheralReset19Reg;
    /** \brief Peripheral Reset Register - PMBUS */   
    uint32 Mcu_PeripheralReset20Reg;
    /** \brief Peripheral Reset Register - DCC */   
    uint32 Mcu_PeripheralReset21Reg;   
    /* Reserved */
    /** \brief Peripheral Reset Register - EtherCAT */
    uint32 Mcu_PeripheralReset23Reg;   
    /* Reserved */
    /** \brief Peripheral Reset Register -  HRCAL0,1,2 */
    uint32 Mcu_PeripheralReset25Reg;   
    /* Reserved */
    /** \brief Peripheral Reset Register - EPG */
    uint32 Mcu_PeripheralReset27Reg; 
    /** \brief Peripheral Reset Register - ADCCHECKER */  
    uint32 Mcu_PeripheralReset28Reg;  
    /* Reserved */
    /** \brief Peripheral Reset Register - SENT */
    uint32 Mcu_PeripheralReset30Reg;   
    /* Reserved */
    /** \brief Peripheral Reset Register - WADI */
    uint32 Mcu_PeripheralReset32Reg;   
} Mcu_PeripheralResetRegConfigType;

/*********************************************************************************************************************
 *  \brief Pointer to Mcu_PeripheralResetRegConfigType structure
 *********************************************************************************************************************/
typedef P2CONST(Mcu_PeripheralResetRegConfigType, AUTOMATIC, MCU_CONFIG_DATA) Mcu_PeripheralResetRegConfigPtrType;


/*********************************************************************************************************************
 *  \brief Pointer to Mcu_MCanClkConfigType structure
 *********************************************************************************************************************/
typedef P2CONST(Mcu_MCanClkConfigType, AUTOMATIC, MCU_CONFIG_DATA) Mcu_MCanClkConfigPtrType;

/*********************************************************************************************************************
 *  \brief Pointer to Mcu_LinClkConfigType structure
 *********************************************************************************************************************/
typedef P2CONST(Mcu_LinClkConfigType, AUTOMATIC, MCU_CONFIG_DATA) Mcu_LinClkConfigPtrType;


/** \brief Structure for device clock setting */
/*
 * Design: MCAL-23087,MCAL-23091,MCAL-23094
 */
typedef struct
{
    /** \brief Clock source Id for the module */
    Mcu_ClkSourceIdType               Mcu_ClockSourceId; 
    /** \brief Peripheral clock configuration pointer */          
    Mcu_PeripheralClkRegConfigPtrType Mcu_PeripheralClkConfigPtr;  
    /** \brief Peripheral reset configuration pointer */          
    Mcu_PeripheralResetRegConfigPtrType Mcu_PeripheralResetConfigPtr; 
    /** \brief MCan instances count */
    uint32                            Mcu_MCanInstancesCount; 
    /** \brief Lin instances count */     
    uint32                            Mcu_LinInstancesCount; 
    /** \brief MCan Clock configuration pointer */      
    Mcu_MCanClkConfigPtrType          Mcu_MCanClkConfig;
    /** \brief Lin Clock configuration pointer */           
    Mcu_LinClkConfigPtrType           Mcu_LinClkConfig;
    /** \brief Cpu Timer Clock config */            
    Mcu_CpuTimerClkConfigType         Mcu_CpuTimerClkConfig;
    /** \brief External Clock Output config */       
    Mcu_ExternalClkOutConfigType      Mcu_ExternalClkOutConfig;
    /** \brief Ethercat clock config */    
    Mcu_EthercatClkConfigType         Mcu_EthercatClkConfig;
    /** \brief Frequency of the external clock source (XTAL) in Hz */       
    uint32                            Mcu_ExternalClkFreq;
    /** \brief System Clock divider. Range is from 1 to 126. */         
    uint8                             Mcu_SysClkDiv; 
    /** \brief HSM Clock divider. Range is from 1 to 16. */              
    Mcu_HsmClockDiv                   Mcu_HsmClkDiv; 
    /** \brief EPWM Clock divider. Range is from 1 to 2 */              
    Mcu_EPWMClkDivider                Mcu_EpwmClkDiv; 
    /** \brief EMIF Clock divider. Range is from 1 to 4 */             
    Mcu_EMIFClkDivider                Mcu_EmifClkDiv;              
    #if(STD_OFF == MCU_CFG_NO_PLL)
    /** \brief Reference Clock Divider value. Range is from 1 to 32. */
    uint8                             Mcu_PllRefDiv; 
    /** \brief Integer multiplier value. Range is from 1 to 127. */              
    uint8                             Mcu_PllIntMult;
    /** \brief Output Clock Divider value. Range is from 1 to 32. */              
    uint8                             Mcu_PllOutDiv;               
    #endif /*MCU_CFG_NO_PLL*/
} Mcu_ClockConfigType;

/*********************************************************************************************************************
 *  \brief Pointer to Clock Config structure
 *********************************************************************************************************************/
/*
 * Design: MCAL-21930
 */
typedef P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_CONFIG_DATA) Mcu_ClockConfigPtrType;


/** \brief List of low power modes */
typedef enum
{
    /** \brief MCU Idle mode */
    MCU_IDLE_MODE       =  0U,
    /** \brief MCU Standby mode */          
    MCU_STANDBY_MODE    =  1U,          
    MCU_MODE_MAX
}Mcu_LowPowerModeType;


/** \brief Structure for Mcu low power mode configuration type */
 /*
 * Design: MCAL-21941
 */
typedef struct
{
    /** \brief Low power mode type */
    Mcu_LowPowerModeType Mcu_LowPowerMode;
    /** \brief The number of cycles to qualify an input on waking from STANDBY mode. Range is from 2 to 65. */
    uint16               Mcu_QualPeriod;
    /** \brief Enable/Disable WD to wakeup the device from STANDBY */
    boolean              Mcu_EnableWDWakeup;

} Mcu_ModeConfigType;

/*********************************************************************************************************************
 *  \brief Pointer to ModeConfig structure
 *********************************************************************************************************************/
 /*
 * Design: MCAL-21932
 */
typedef P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_CONFIG_DATA) Mcu_ModeConfigPtrType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/


/* MCU Configuration struct declaration */
extern const struct Mcu_ConfigType_s Mcu_ModuleConfiguration_0;


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

#endif /* MCU_CFG_H */
/*********************************************************************************************************************
 *  End of File: Mcu_Cfg.h
 *********************************************************************************************************************/
