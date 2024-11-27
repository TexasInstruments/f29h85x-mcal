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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Mcu_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Mcu private functions
 *********************************************************************************************************************/
#ifndef MCU_PRIV_H
#define MCU_PRIV_H

/**
 * \addtogroup MCU Mcu API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_sysctl.h"
#include "Mcal_Lib_Cpu.h"
#include "Mcal_Lib.h"
#include "Mcal_Lib_BootRom.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/*
 * Design: MCAL-21904, MCAL-21905, MCAL-21906, MCAL-21907, MCAL-21910, MCAL-21911, MCAL-21912, MCAL-21913,
 * Design: MCAL-21914, MCAL-21915, MCAL-21916, MCAL-21917, MCAL-21918
 */

/** \brief Keys for the System control registers write protection */
#define MCU_REG_KEY                 (0xA5A50000U)

/** \brief Maximum System Clock Divider supported */
#define MCU_SYSCLKDIV_MAX           ((uint8)64U)

/** \brief Maximum PLL Reference Clock Divider supported */
#define MCU_PLLREFDIV_MAX           ((uint8)32U)

/** \brief Maximum PLL Integer Multiplier supported */
#define MCU_PLLINTMULT_MAX          ((uint8)127U)

/** \brief Maximum PLL Output Clock Divider supported */
#define MCU_PLLOUTDIV_MAX           ((uint8)32U)

/** \brief Maximum XTAL frequency supported */
#define MCU_EXTCLKFREQ_XTAL_MAX     ((uint32)20000000U)

/** \brief Maximum XTAL frequency supported in Single Ended mode */
#define MCU_EXTCLKFREQ_XTAL_SE_MAX  ((uint32)25000000U)

/** \brief Internal Oscillator Frequency */
#define MCU_OSC_CLK_FREQ            ((uint32)10000000U)

/** \brief Minimum Frequency of PLL RAW clock  (before SYSCLK divider) */
#define MCU_PLLRAWCLK_MIN           ((uint32)6000000U)

/** \brief Maximum Frequency of PLL RAW clock (before SYSCLK divider) */
#define MCU_PLLRAWCLK_MAX	         ((uint32)400000000U)

/** \brief Minimum Frequency of Internal clock  (before SYSCLK divider) */
#define MCU_PLLINTCLK_MIN	         ((uint32)2000000U)

/** \brief Maximum Frequency of Internal clock  (before SYSCLK divider) */
#define MCU_PLLINTCLK_MAX	         ((uint32)20000000U)

/** \brief Minimum Frequency of VCO clock (before SYSCLK divider) */
#define MCU_PLLVCOCLK_MIN	         ((uint32)220000000U)

/** \brief Maximum Frequency of VCO clock (before SYSCLK divider) */
#define MCU_PLLVCOCLK_MAX	         ((uint32)600000000U)

/** \brief Minimum Frequency of device (system) clock */
#define MCU_SYSCLK_MIN	            ((uint32)2000000U)

/** \brief Maximum Frequency of device (system) clock */
#define MCU_SYSCLK_MAX	            ((uint32)200000000U)

/** \brief LPM defines for LPMCR.LPM IDLE*/
#define MCU_LPM_IDLE         ((uint32)0x0000U)
/** \brief LPM defines for LPMCR.LPM STANDBY*/
#define MCU_LPM_STANDBY      ((uint32)0x0001U)

/** \brief Maximum Standby Qualification period supported */
#define MCU_STANDBY_QUALPERIOD_MAX	((uint16)65U)

/** \brief Minimum Standby Qualification period supported */
#define MCU_STANDBY_QUALPERIOD_MIN	((uint16)2U)


/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
 
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
/** \brief Parameter validity check for Mcu_InitClock API.
 * 
 * \param[in] ClockConfigPtr Pointer to Clock configuration set. (Mcu_ClockConfigPtrType) configured in EB Tresos.
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK - If all parameters are in range & no error is present in configuration.
 * \retval E_NOT_OK - If there are no errors.
 * 
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClockParamCheck(Mcu_ClockConfigPtrType ClockConfigPtr);
#endif


/** \brief Set the Oscillator source, Multiplier and divider to derive the clock.
 * 
 * This function sets the clocks to Cputimer2 module, XCLKOUT, Ethercat and enables peripheral module clock gatings
 * 
 * \param[in] ClockConfigPtr Pointer to Clock configuration set. (Mcu_ClockConfigPtrType) configured in EB Tresos.
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK - If all parameters are in range & no error is present in configuration.
 * \retval E_NOT_OK - If there are no errors.
 * 
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_SetClock(Mcu_ClockConfigPtrType ClockConfigPtr);


/** \brief Sets up the SysPLL divider & enables the PLL.
 * 
 * \pre None
 * \post None
 * \return None
 * \retval None
 * 
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_EnablePll(void);


/** \brief Checks if the PLL is locked successfully.
 * 
 * \pre None
 * \post None
 * \return returns the pll lock status
 * \retval 0 - If PLL is not locked yet.
 * \retval 1 - If PLL is locked.
 * 
 *********************************************************************************************************************/
FUNC(uint16, MCU_CODE) Mcu_IsPllLocked(void);


/** \brief Gets the reason for a reset.
 * 
 * This function will return the reason(s) for a reset.  Since the reset
 * reasons are sticky until either cleared by software or an external reset,
 * multiple reset reasons may be returned if multiple resets have occurred.
 * 
 * \pre None
 * \post None
 * \return returns the raw reset value
 * \retval Reason(s) for a reset.     
 * 
 *********************************************************************************************************************/
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetCause(void);


/** \brief Converts the controller specific reset reason to AUTOSAR format.
 * 
 * \param[in] RawResetType Reset Reason
 * \pre None
 * \post None
 * \return Mcu_ResetType
 * \retval Returns Reset reason defined. 
 * 
 *********************************************************************************************************************/
FUNC(Mcu_ResetType, MCU_CODE) Mcu_ConvertResetReason(Mcu_RawResetType RawResetType);


/** \brief Clears the Reset Cause register.
 * 
 * \param[in] RawResetType Reset Reason
 * \pre None
 * \post None
 * \return None
 * \retval None
 * 
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_ClearReset(Mcu_RawResetType RawResetType);


/** \brief Perform simulation of external reset.
 * 
 * \pre None
 * \post None
 * \return None
 * \retval None
 * 
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_PerformControllerReset(void);


#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
/** \brief Parameter validity check for Mcu_SetMode API.
 * 
 * \param[in] ModeConfigPtr Pointer to Power mode configuration set. (Mcu_ModeConfigPtrType) configured in EB Tresos.
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK - If all parameters are in range & no error is present in configuration.
 * \retval E_NOT_OK - If there are no errors.
 * 
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_SetModeParamCheck(Mcu_ModeConfigPtrType ModeConfigPtr);
#endif


/** \brief Set & enter the Low Power Mode.
 * 
 * \param[in] ModeConfigPtr Pointer to Power mode configuration set. (Mcu_ModeConfigPtrType) configured in EB Tresos.
 * \pre None
 * \post None
 * \return None
 * \retval None
 * 
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_EnterLowPowerMode(Mcu_ModeConfigPtrType ModeConfigPtr);


/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/** \brief Get the missing clock detection Failure Status
 * 
 * A failure means the oscillator clock is missing
 * 
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if a failure is detected 
 * \retval FALSE if a failure isn't detected
 * 
 *********************************************************************************************************************/
static inline FUNC(boolean, MCU_CODE) Mcu_IsMCDClockFailureDetected(void)
{ 
    /* Check the status bit to determine failure */ 
    return ((HWREGH(DEVCFG_BASE + SYSCTL_O_MCDCR) & (uint16)SYSCTL_MCDCR_MCLKSTS) != (uint16)0U);
}


/** \brief Reset the missing clock detection logic after clock failure
 * 
 * \pre None
 * \post None
 * \return None
 * \retval None 
 * 
 *********************************************************************************************************************/
static inline FUNC(void, MCU_CODE) Mcu_ResetMCD(void)
{
    /* reset missing clock detection control register */ 
    HWREGH(DEVCFG_BASE + SYSCTL_O_MCDCR) |= (uint16)SYSCTL_MCDCR_MCLKCLR;
}


/** \brief Sets up PLLSYSCLK divider
 * 
 * This function sets up the PLLSYSCLK divider. There is only one
 * divider that scales PLLSYSCLK to generate the system clock.
 * 
 * The divider parameter can have one value from the set below:
 *     0x0 = /1
 *     0x1 = /2
 *     0x2 = /4 (default on reset)
 *     0x3 = /6
 *     0x4 = /8
 *    ......
 *     0x3F =/126
 * 
 * \param[in] divider is the value that configures the divider.
 * \pre None
 * \post None
 * \return None
 * \retval None 
 * 
 *********************************************************************************************************************/
static inline FUNC(void, MCU_CODE) Mcu_SetPLLSysClk(uint16 divider)
{
    HWREGH(DEVCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) = divider;
}


/** \brief Enters IDLE mode.
 * 
 * This function puts the device into IDLE mode. 
 * The CPU clock is gated while all peripheral clocks are left running.
 * Any enabled interrupt will wake the CPU up from IDLE mode.
 * 
 * \pre None
 * \post None
 * \return None
 * \retval None 
 * 
 *********************************************************************************************************************/
static inline FUNC(void, MCU_CODE) Mcu_EnterIdleMode(void)
{
    /* Configure the device to go into IDLE mode when IDLE is executed. */
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
    (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) &
    ~(uint32)SYSCTL_LPMCR_LPM_M) |
    MCU_LPM_IDLE;

    /* IDLE Instruction for putting processor into a low-power mode */
    MCAL_LIB_IDLE;
}


/** \brief Enters STANDBY mode.
 * 
 * This function puts the device into STANDBY mode. This will gate both the
 * CPU clock and any peripheral clocks derived from SYSCLK. The watchdog is
 * left active, and an NMI or an optional watchdog interrupt will wake the
 * CPU subsystem from STANDBY mode.
 * 
 * GPIOs may be configured to wake the CPU subsystem.
 * 
 * The CPU will receive an interrupt (WAKEINT) on wakeup.
 * 
 * \pre None
 * \post None
 * \return None
 * \retval None 
 * 
 *********************************************************************************************************************/
static inline FUNC(void, MCU_CODE) Mcu_EnterStandbyMode(void)
{
    /* Configure the device to go into STANDBY mode when IDLE is executed. */
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
    (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) &
    ~(uint32)SYSCTL_LPMCR_LPM_M) |
    MCU_LPM_STANDBY;

    /* IDLE Instruction for putting processor into a low-power mode */
    MCAL_LIB_IDLE;
}


/** \brief Sets the number of cycles to qualify an input on waking from STANDBY mode.
 * 
 * This function sets the number of OSCCLK clock cycles used to qualify the
 * selected inputs when waking from STANDBY mode. The cycles parameter
 * should be between 2 and 65 cycles inclusive.
 * 
 * \param[in] cycles is the number of OSCCLK cycles.
 * \pre None
 * \post None
 * \return None
 * \retval None 
 * 
 *********************************************************************************************************************/
static inline FUNC(void, MCU_CODE) Mcu_SetStandbyQualificationPeriod(uint16 cycles)
{
    /* Set the standby qualification period */
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) =
    (HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) &
    ~(uint16)SYSCTL_LPMCR_QUALSTDBY_M) |
    ((cycles - (uint16)2U) << (uint16)SYSCTL_LPMCR_QUALSTDBY_S);
}


/** \brief Enable the device to wake from STANDBY mode upon a watchdog interrupt.
 * 
 * In order to use this option, Need to configure the watchdog to generate an interrupt.
 * 
 * \pre None
 * \post None
 * \return None
 * \retval None 
 * 
 *********************************************************************************************************************/
static inline FUNC(void, MCU_CODE) Mcu_EnableWatchdogStandbyWakeup(void)
{
    /* Set the bit enables the watchdog to wake up the device from STANDBY. */
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) |= (uint16)SYSCTL_LPMCR_WDINTE;
}


/** \brief Disable the device from waking from STANDBY mode upon a watchdog interrupt.
 * 
 * \pre None
 * \post None
 * \return None
 * \retval None 
 * 
 *********************************************************************************************************************/
static inline FUNC(void, MCU_CODE) Mcu_DisableWatchdogStandbyWakeup(void)
{
    /* Clear the bit enables the watchdog to wake up the device from STANDBY.*/
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) &= (uint16)~SYSCTL_LPMCR_WDINTE;
}


#ifdef __cplusplus
extern "C" }
#endif

/**
* @}
*/

#endif /* MCU_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Mcu_Priv.h
 *********************************************************************************************************************/
