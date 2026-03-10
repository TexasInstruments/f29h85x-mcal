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
 *  File:       Mcu_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Mcu private functions
 *********************************************************************************************************************/
#ifndef MCU_PRIV_H
#define MCU_PRIV_H

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
 * Design: MCAL-21904, MCAL-21905, MCAL-21906, MCAL-21907, MCAL-21910, MCAL-21911, MCAL-21912,
 * MCAL-21913, Design: MCAL-21914, MCAL-21915, MCAL-21916, MCAL-21917, MCAL-21918
 */

/** \brief Keys for the System control registers write protection */
#define MCU_REG_KEY (0xA5A50000U)

/** \brief Maximum System Clock Divider supported */
#define MCU_SYSCLKDIV_MAX ((uint8)64U)

/** \brief Maximum PLL Reference Clock Divider supported */
#define MCU_PLLREFDIV_MAX ((uint8)32U)

/** \brief Maximum PLL Integer Multiplier supported */
#define MCU_PLLINTMULT_MAX ((uint8)255U)

/** \brief Maximum PLL Output Clock Divider supported */
#define MCU_PLLOUTDIV_MAX ((uint8)32U)

/** \brief Minimum XTAL frequency supported */
#define MCU_EXTCLKFREQ_XTAL_MIN ((uint32)10000000U)

/** \brief Maximum XTAL frequency supported */
#define MCU_EXTCLKFREQ_XTAL_MAX ((uint32)20000000U)

/** \brief Minimum XTAL frequency supported in Single Ended mode */
#define MCU_EXTCLKFREQ_XTAL_SE_MIN ((uint32)10000000U)

/** \brief Maximum XTAL frequency supported in Single Ended mode */
#define MCU_EXTCLKFREQ_XTAL_SE_MAX ((uint32)25000000U)

/** \brief Internal Oscillator Frequency */
#define MCU_OSC_CLK_FREQ ((uint32)10000000U)

/** \brief Minimum Frequency of PLL RAW clock  (before SYSCLK divider) */
#define MCU_PLLRAWCLK_MIN ((uint32)6000000U)

/** \brief Maximum Frequency of PLL RAW clock (before SYSCLK divider) */
#define MCU_PLLRAWCLK_MAX ((uint32)400000000U)

/** \brief Minimum Frequency of Internal clock  (before SYSCLK divider) */
#define MCU_PLLINTCLK_MIN ((uint32)10000000U)

/** \brief Maximum Frequency of Internal clock  (before SYSCLK divider) */
#define MCU_PLLINTCLK_MAX ((uint32)25000000U)

/** \brief Minimum Frequency of VCO clock (before SYSCLK divider) */
#define MCU_PLLVCOCLK_MIN ((uint32)220000000U)

/** \brief Maximum Frequency of VCO clock (before SYSCLK divider) */
#define MCU_PLLVCOCLK_MAX ((uint32)600000000U)

/** \brief Minimum Frequency of device (system) clock */
#define MCU_SYSCLK_MIN ((uint32)2000000U)

/** \brief Maximum Frequency of device (system) clock */
#define MCU_SYSCLK_MAX ((uint32)200000000U)

/** \brief LPM defines for LPMCR.LPM IDLE*/
#define MCU_LPM_IDLE ((uint32)0x0000U)
/** \brief LPM defines for LPMCR.LPM STANDBY*/
#define MCU_LPM_STANDBY ((uint32)0x0001U)

/** \brief Maximum Standby Qualification period supported */
#define MCU_STANDBY_QUALPERIOD_MAX ((uint16)65U)

/** \brief Minimum Standby Qualification period supported */
#define MCU_STANDBY_QUALPERIOD_MIN ((uint16)2U)

/** \brief Timeout cycles */
#define SYSCTL_SYNCBUSY_TIMEOUT_CYCLES ((uint32)10000U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Mcu frequency Structure */
typedef struct
{
    /** \brief Reference Clock : INTOSC1/INTOSC2/XTAL  */
    uint32 input_clock;
    /** \brief REFDIV + 1  */
    uint32 pll_int_clk;
    /** \brief VCO output clock  */
    uint32 pll_vco_clk;
    /** \brief Pll RawClk  */
    uint32 pll_raw_clk;
    /** \brief Pll SysClk  */
    uint32 sys_clk;
} Mcu_CalClkValueType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
/** \brief Parameter validity check for Mcu_InitClock API.
 *
 * \param[in] ClockConfigPtr Pointer to Clock configuration set. (Mcu_ClockConfigPtrType) configured
 *in EB Tresos.
 * \param[in] CalClockPtr Pointer to calculated output frequency
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK - If all parameters are in range & no error is present in configuration.
 * \retval E_NOT_OK - If there are no errors.
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MCU_CODE)
Mcu_InitClockParamCheck(Mcu_ClockConfigPtrType ClockConfigPtr, const Mcu_CalClkValueType *CalClockPtr);
#endif

/** \brief Set the Oscillator source, Multiplier and divider to derive the clock.
 *
 * This function sets the clocks to Cputimer2 module, XCLKOUT, Ethercat and enables peripheral
 *module clock gatings
 *
 * \param[in] ClockConfigPtr Pointer to Clock configuration set. (Mcu_ClockConfigPtrType) configured
 *in EB Tresos.
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

/** \brief Calculates the output frequency
 *
 * \param[in] ClockConfigPtr Points to clock configuration settings
 * \param[out] CalClockValue Points to the calculated clock values
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_CalculateClocks(Mcu_ClockConfigPtrType ClockConfigPtr, Mcu_CalClkValueType *CalClockValue);

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
 * \param[in] ModeConfigPtr Pointer to Power mode configuration set. (Mcu_ModeConfigPtrType)
 *configured in EB Tresos.
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
 * \param[in] ModeConfigPtr Pointer to Power mode configuration set. (Mcu_ModeConfigPtrType)
 *configured in EB Tresos.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_EnterLowPowerMode(Mcu_ModeConfigPtrType ModeConfigPtr);

/** \brief Mcu_FillRamSection - This API will fill the ram sections with configured data
 *
 * \param[in] RamSectionConfigPtr Pointer to Ram section configuration set.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_FillRamSection(Mcu_RamConfigPtrType RamSectionConfigPtr);

#if (STD_ON == MCU_CLOCK_CONFIG_LOCK_CRITICAL_REGISTERS)

/** \brief Locks all Clock configuration registers
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_LockClockConfigRegisters(void);
#endif /*MCU_CLOCK_CONFIG_LOCK_CRITICAL_REGISTERS*/

#if (STD_ON == MCU_CPU_PERIPHERAL_CONFIG_LOCK_CRITICAL_REGISTERS)
/** \brief Locks all Cpu Peripheral configuration registers
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_LockCpuPeripheralConfigRegisters(void);
#endif /*MCU_CPU_PERIPHERAL_CONFIG_LOCK_CRITICAL_REGISTERS*/

#if (STD_ON == MCU_CPU_SYSTEM_LOCK_CRITICAL_REGISTERS)
/** \brief Locks Cpu system registers
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_LockCpuSysRegisters(void);

#endif /*MCU_CPU_SYSTEM_LOCK_CRITICAL_REGISTERS*/

/** \brief Configures peripheral registers based on ResourceAllocator configuration
 *
 * \param[in] PeripheralConfig Pointer to peripheral configuration structure
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE)
Mcu_Priv_ConfigurePeripherals(P2CONST(Mcu_PeripheralConfigType, AUTOMATIC, MCU_APPL_CONST) PeripheralConfig);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
extern "C"
}
#endif

#endif /* MCU_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Mcu_Priv.h
 *********************************************************************************************************************/
