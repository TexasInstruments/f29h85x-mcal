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
 *  File:       Mcu_priv.c
 *  Generator:  None
 *
 *  Description:  This file contains controller dependent local functions and private functions
 *                to be used in Mcu.c
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcu_Priv.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* Macro used to add wait cycles to allow load capacitors to charge */
#define MCU_XTAL_CHARGE_DELAY __asm(" NOP #5");

/* SIMRESET Key */
#define SYSCTL_SIMRESET_KEY ((uint16)0xA5A5U)

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief Configures the MCan clock source & divider values.
 *
 * \param[in] MCanClkCfg Pointer to MCan Clock config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SetMCanClock(const Mcu_MCanClkConfigType* MCanClkCfg);

/** \brief Configures the Lin clock divider value.
 *
 * \param[in] LinClkCfg Pointer to Lin Clock config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SetLinClock(const Mcu_LinClkConfigType* LinClkCfg);

/** \brief Configures the Cpu timer2 clock source & divider values.
 *
 * \param[in] CpuTimerClkCfg Pointer to Cpu Timer Clock config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SetCpuTimerClock(const Mcu_CpuTimerClkConfigType* CpuTimerClkCfg);

/** \brief Configures the XCLKOUT source & divider values.
 *
 * \param[in] ExternalClkOutCfg Pointer to XCLKOUT config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SetExternalClockOutput(const Mcu_ExternalClkOutConfigType* ExternalClkOutCfg);

/** \brief Configures the Ethercat clock divider values.
 *
 * \param[in] EthercatClkCfg Pointer to Ethercat config parameters.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SetEthercatClock(const Mcu_EthercatClkConfigType* EthercatClkCfg);

/** \brief Configures the HSM clock divider values.
 *
 * \param[in] HsmClkDiv HSM clock divider.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SetHsmClock(Mcu_HsmClockDiv HsmClkDiv);

/** \brief Configures the EPWM clock divider values.
 *
 * \param[in] EpwmClkDiv EPWM clock divider.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SetEpwmClock(Mcu_EPWMClkDivider EpwmClkDiv);

/** \brief Configures the EMIF clock divider values.
 *
 * \param[in] EmifClkDiv EMIF clock divider.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SetEmifClock(Mcu_EMIFClkDivider EmifClkDiv);

/** \brief Enables a peripheral clock gating
 *
 * Peripherals are enabled with this function.  At power-up, all peripherals
 * are disabled; they must be enabled in order to operate or respond to
 * register reads/writes.
 *
 * Note that there should be atleast 5 cycles delay between enabling the
 * peripheral clock and accessing the peripheral registers. The delay should be
 * added by the user if the peripheral is accessed immediately after this
 * function call.
 *
 * Use asm(" RPT #5 || NOP"); to add 5 cycle delay post this function call.
 *
 * \param[in] PeripheralClkConfigPtr points to config of which peripherals to enable.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_DeviceEnablePeripherals(Mcu_PeripheralClkRegConfigPtrType PeripheralClkConfigPtr);

/** \brief Resets a peripheral
 *
 * This function uses the SOFTPRESx registers to reset a specified peripheral
 *
 * \param[in] PeripheralResetConfigPtr points to config of which peripherals to reset.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_DeviceResetPeripherals(Mcu_PeripheralResetRegConfigPtrType PeripheralResetConfigPtr);

/** \brief Resets all peripherals
 *
 * This function uses the SOFTPRESx registers to reset all peripherals
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_DeviceResetAllPeripherals(void);

/** \brief Selects the oscillator to be used for the clocking of the device.
 *
 * This function configures the oscillator to be used in the clocking of the
 * device. The OscSource parameter may take a value of
 * MCU_CLKSRC_OSC2, MCU_CLKSRC_OSC1, MCU_CLKSRC_XTAL, MCU_CLKSRC_XTAL_SE.
 *
 * \param[in] OscSource is the oscillator source to be configured.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SelectOscSource(Mcu_ClkSourceIdType OscSource);

/** \brief Configures the external oscillator for the clocking of the device.
 *
 * This function configures the external oscillator (XTAL) to be used for the
 * clocking of the device in crystal mode. It follows the procedure to turn on
 * the oscillator, wait for it to power up, and select it as the source of the
 * system clock.
 *
 * Please note that this function blocks while it waits for the XTAL to power
 * up. If the XTAL does not manage to power up properly, the function will
 * loop for a long time. It is recommended that modify this function to
 * add an appropriate timeout and error-handling procedure.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SelectXTAL(void);

/** \brief Configures the external oscillator for the clocking of the device in single-ended mode.
 *
 * This function configures the external oscillator (XTAL) to be used for the
 * clocking of the device in single-ended mode. It follows the procedure to
 * turn on the oscillator, wait for it to power up, and select it as the
 * source of the system clock.
 *
 * Please note that this function blocks while it waits for the XTAL to power
 * up. If the XTAL does not manage to power up properly, the function will
 * loop for a long time. It is recommended that modify this function to
 * add an appropriate timeout and error-handling procedure.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_SelectXTALSingleEnded(void);

/** \brief Wait for the X1 counter value in the X1CNT register to reach 2047 (0x7ff) atleast 4 times
 *
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if a failure is detected
 *         FALSE if a failure isn't detected
 *
 *********************************************************************************************************************/
static FUNC(boolean, MCU_CODE) Mcu_PollX1Counter(void);

#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
/** \brief Checks the Xtal frequency range
 *
 * \param[in] ClockConfigPtr Points to clock configuration settings
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if a failure is detected
 *         FALSE if a failure isn't detected
 *
 *********************************************************************************************************************/
static FUNC(boolean, MCU_CODE) Mcu_XtalFreqRangeCheck(Mcu_ClockConfigPtrType ClockConfigPtr);

/** \brief Checks the Pll settings ranges
 *
 * \param[in] ClockConfigPtr Points to clock configuration settings
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if a failure is detected
 *         FALSE if a failure isn't detected
 *
 *********************************************************************************************************************/
static FUNC(boolean, MCU_CODE) Mcu_PllSettingsRangeCheck(Mcu_ClockConfigPtrType ClockConfigPtr);

/** \brief Checks the Derived clock frequency ranges
 *
 * \param[in] oscClk Oscillator clock source frequency
 * \param[in] ClockConfigPtr Points to clock configuration settings
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if a failure is detected
 *         FALSE if a failure isn't detected
 *
 *********************************************************************************************************************/
static FUNC(boolean, MCU_CODE) Mcu_DerivedClockFreqRangeCheck(uint32 oscClk, Mcu_ClockConfigPtrType ClockConfigPtr);
#endif /*MCU_CFG_DEV_ERROR_DETECT*/

/** \brief Converts the controller specific reset reason to AUTOSAR format.
 *
 * \param[in] RawResetType Reset Reason
 * \pre None
 * \post None
 * \return Mcu_ResetType
 * \retval Returns Reset reason defined.
 *
 *********************************************************************************************************************/
static FUNC(Mcu_ResetType, MCU_CODE) Mcu_ConvertFirstGroup(Mcu_RawResetType RawResetType);

/** \brief Converts the controller specific reset reason to AUTOSAR format.
 *
 * \param[in] RawResetType Reset Reason
 * \pre None
 * \post None
 * \return Mcu_ResetType
 * \retval Returns Reset reason defined.
 *
 *********************************************************************************************************************/
static FUNC(Mcu_ResetType, MCU_CODE) Mcu_ConvertSecondGroup(Mcu_RawResetType RawResetType);

/** \brief Keep clearing the counter until it is no longer saturated
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_ClearX1Counter(void);

/** \brief Wait for the X1 clock to saturate
 *
 * \param[in] loop_count Loop count value
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if X1 clock saturation is successful
 * \retval FALSE if X1 clock saturation fails
 *
 *********************************************************************************************************************/
static FUNC(boolean, MCU_CODE) Mcu_WaitX1Saturate(uint16 loop_count);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
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
LOCAL_INLINE FUNC(boolean, MCU_CODE) Mcu_IsMCDClockFailureDetected(void);

/** \brief Reset the missing clock detection logic after clock failure
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_ResetMCD(void);

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
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_SetPLLSysClk(uint16 divider);

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
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_EnterIdleMode(void);

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
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_EnterStandbyMode(void);

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
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_SetStandbyQualificationPeriod(uint16 cycles);

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
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_EnableWatchdogStandbyWakeup(void);

/** \brief Disable the device from waking from STANDBY mode upon a watchdog interrupt.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_DisableWatchdogStandbyWakeup(void);

/** \brief Poll the Registers for Sync Busy
 *
 * \param[in] mask the register value that needs to be polled
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_PollSyncBusy(uint32 mask);

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*
 * Design: MCAL-21921
 */
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClockParamCheck(Mcu_ClockConfigPtrType ClockConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) osc_clk              = (uint32)0U;

    /* Check the External Clock Frequency Range,PLL settings and System Clock divider  */
    if ((TRUE == Mcu_XtalFreqRangeCheck(ClockConfigPtr)) || (TRUE == Mcu_PllSettingsRangeCheck(ClockConfigPtr)) ||
        (MCU_SYSCLKDIV_MAX < ClockConfigPtr->Mcu_SysClkDiv)) /* System clock Divider Max Range: 126U */
    {
        /* Invalid Parameters */
    }
    else
    {
        /* Get Clock Source Frequency from Internal Osciallator */
        if ((MCU_CLKSRC_OSC2 == ClockConfigPtr->Mcu_ClockSourceId) ||
            (MCU_CLKSRC_OSC1 == ClockConfigPtr->Mcu_ClockSourceId))
        {
            osc_clk = MCU_OSC_CLK_FREQ; /* 10 MHz */
        }
        else
        {
            /* Get Clock Source Frequency from External Oscillator 20 or 25 MHz */
            osc_clk = ClockConfigPtr->Mcu_ExternalClkFreq;
        }

        /* Derived clocks and range checks */
        if ((TRUE == Mcu_DerivedClockFreqRangeCheck(osc_clk, ClockConfigPtr)))
        {
            /* Invalid Parameters */
        }
        else
        {
            return_value = (Std_ReturnType)E_OK;
        }
    }

    return (return_value);
}
#endif /*MCU_CFG_DEV_ERROR_DETECT*/

/*
 * Design: MCAL-21920
 */
FUNC(Std_ReturnType, MCU_CODE) Mcu_SetClock(Mcu_ClockConfigPtrType ClockConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;
    VAR(uint16, AUTOMATIC) osc_clksrc_sel       = (uint16)0U;
    VAR(uint32, AUTOMATIC) pll_mult             = (uint32)0U;
    VAR(uint32, AUTOMATIC) mult                 = (uint32)0U;
    VAR(uint16, AUTOMATIC) pll_en               = (uint16)0U;
    VAR(uint16, AUTOMATIC) sys_clk_div          = (uint16)0U;

    /* Don't proceed to the PLL initialization if an MCD failure is detected. */
    if ((boolean)TRUE == (boolean)Mcu_IsMCDClockFailureDetected())
    {
        /* MCD failure detected. Returning FALSE. Need to clear the MCD error. */
        Mcu_ResetMCD();
    }
    else
    {
        /* Bypass PLL */
        HWREGH(DEVCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= (uint16)~SYSCTL_SYSPLLCTL1_PLLCLKEN;

        /* Delay of at least 120 OSCCLK cycles required post PLL bypass */
        McalLib_Delay((uint32)28U);

        Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSPLLCTL1);

        /* Derive the current and previous oscillator clock source values */
        osc_clksrc_sel = (uint16)(HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) & (uint16)SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M);

        if ((osc_clksrc_sel == (uint16)MCU_CLKSRC_XTAL) &&
            ((HWREGH(DEVCFG_BASE + SYSCTL_O_XTALCR) & (uint16)SYSCTL_XTALCR_SE) != 0U))
        {
            osc_clksrc_sel = (uint16)MCU_CLKSRC_XTAL_SE;
        }

        /* Check if the oscillator clock source has changed */
        if (osc_clksrc_sel != (uint16)ClockConfigPtr->Mcu_ClockSourceId)
        {
            /* Turn off PLL */
            HWREGH(DEVCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= (uint16)~SYSCTL_SYSPLLCTL1_PLLEN;

            /* Delay of at least 60 OSCCLK cycles required between powerdown to powerup of PLL */
            McalLib_Delay((uint32)14U);

            Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSPLLCTL1);

            /* Configure oscillator source */
            Mcu_SelectOscSource(ClockConfigPtr->Mcu_ClockSourceId);

            /* Delay of at least 300 OSCCLK cycles */
            McalLib_Delay((uint32)73U);
        }
        else
        {
            /* Do Nothing */
        }

        /* Set dividers to /1 to ensure the fastest PLL configuration */
        Mcu_SetPLLSysClk((uint16)0U);

        Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSCLKDIVSEL);

#if (STD_OFF == MCU_CFG_NO_PLL)
        /* Get the PLL multiplier settings from config */
        pll_mult = (((uint32)ClockConfigPtr->Mcu_PllIntMult) << (uint8)SYSCTL_SYSPLLMULT_IMULT_S);

        pll_mult |= (((uint32)ClockConfigPtr->Mcu_PllRefDiv - (uint32)1U) << (uint8)SYSCTL_SYSPLLMULT_REFDIV_S);

        pll_mult |= (((uint32)ClockConfigPtr->Mcu_PllOutDiv - (uint32)1U) << (uint8)SYSCTL_SYSPLLMULT_ODIV_S);

        /* Get the PLL multipliers currently programmed */
        mult = ((HWREG(DEVCFG_BASE + SYSCTL_O_SYSPLLMULT) & (uint32)SYSCTL_SYSPLLMULT_IMULT_M) >>
                (uint32)SYSCTL_SYSPLLMULT_IMULT_S);

        mult |= (HWREG(DEVCFG_BASE + SYSCTL_O_SYSPLLMULT) & (uint32)SYSCTL_SYSPLLMULT_REFDIV_M);

        mult |= (HWREG(DEVCFG_BASE + SYSCTL_O_SYSPLLMULT) & (uint32)SYSCTL_SYSPLLMULT_ODIV_M);

        pll_en = (HWREGH(DEVCFG_BASE + SYSCTL_O_SYSPLLCTL1) & (uint16)SYSCTL_SYSPLLCTL1_PLLEN);

        /* Lock PLL only if the multipliers need an update or PLL needs to be powered on / enabled
         */
        if ((mult != pll_mult) || (pll_en != (uint16)1U))
        {
            /* Turn off PLL */
            HWREGH(DEVCFG_BASE + SYSCTL_O_SYSPLLCTL1) &= (uint16)~SYSCTL_SYSPLLCTL1_PLLEN;

            /* Delay of at least 60 OSCCLK cycles required between powerdown to powerup of PLL */
            McalLib_Delay((uint32)14U);

            Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSPLLCTL1);

            /* Write multiplier, which automatically turns on the PLL */
            HWREG(DEVCFG_BASE + SYSCTL_O_SYSPLLMULT) = pll_mult;

            Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSPLLMULT);

            /* Enable/ turn on PLL */
            HWREGH(DEVCFG_BASE + SYSCTL_O_SYSPLLCTL1) |= ((uint16)SYSCTL_SYSPLLCTL1_PLLEN);

            Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSPLLCTL1);

            return_value = (Std_ReturnType)E_OK;
        }
        else
        {
            /* Re-Lock of PLL not needed since the multipliers are not updated */
            return_value = (Std_ReturnType)E_OK;
        }

#else
        /* No PLL configuration required */
        return_value = (Std_ReturnType)E_OK;
#endif /*MCU_CFG_NO_PLL*/

        /* Set the divider to user value */
        if ((uint16)ClockConfigPtr->Mcu_SysClkDiv > (uint16)0U)
        {
            sys_clk_div = ((uint16)ClockConfigPtr->Mcu_SysClkDiv - (uint16)1U);
        }

        /* Set the PLL Sys Clock divider */
        Mcu_SetPLLSysClk(sys_clk_div);

        Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSCLKDIVSEL);

        for (uint32 i = 0; i < ClockConfigPtr->Mcu_MCanInstancesCount; i++)
        {
            /* Configure the clocks needed for MCan. */
            Mcu_SetMCanClock(&(ClockConfigPtr->Mcu_MCanClkConfig[i]));
        }

        for (uint32 i = 0; i < ClockConfigPtr->Mcu_LinInstancesCount; i++)
        {
            /* Configure the clocks needed for Lin. */
            Mcu_SetLinClock(&(ClockConfigPtr->Mcu_LinClkConfig[i]));
        }

        /* Configure the clocks needed for Cpu Timers. */
        Mcu_SetCpuTimerClock(&(ClockConfigPtr->Mcu_CpuTimerClkConfig));

        /* Configure the XCLKOUT feature */
        Mcu_SetExternalClockOutput(&(ClockConfigPtr->Mcu_ExternalClkOutConfig));

        /* Configure the Ethercat clock feature */
        Mcu_SetEthercatClock(&(ClockConfigPtr->Mcu_EthercatClkConfig));

        /* Configure the HSM clock divider */
        Mcu_SetHsmClock(ClockConfigPtr->Mcu_HsmClkDiv);

        /* Configure the EPWM clock divider */
        Mcu_SetEpwmClock(ClockConfigPtr->Mcu_EpwmClkDiv);

        /* Configure the EMIF clock divider */
        Mcu_SetEmifClock(ClockConfigPtr->Mcu_EmifClkDiv);

        /* Reset the all peripherals */
        Mcu_DeviceResetAllPeripherals();

        /* Enable clocks to peripherals */
        Mcu_DeviceEnablePeripherals(ClockConfigPtr->Mcu_PeripheralClkConfigPtr);

        /* Sets the appropriate reset bit for unused peripherals and clears the reset bits for the
         * remaining peripherals. */
        Mcu_DeviceResetPeripherals(ClockConfigPtr->Mcu_PeripheralResetConfigPtr);
    }
    return (return_value);
}

/*
 * Design: MCAL-21922
 */
FUNC(void, MCU_CODE) Mcu_EnablePll(void)
{
    VAR(uint16, AUTOMATIC) sys_clk_div = (uint16)0U;

    /* Read configured divider */
    sys_clk_div = (HWREGH(DEVCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) & (uint16)(SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M));

    /* Set divider to produce slower output frequency to limit current increase */
    if (sys_clk_div > (uint16)(MCU_SYSCLKDIV_MAX - 4U))
    {
        Mcu_SetPLLSysClk(sys_clk_div);
    }
    else
    {
        Mcu_SetPLLSysClk(sys_clk_div + 4U);
    }

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSCLKDIVSEL);

    /* Enable PLLSYSCLK is fed from system PLL clock */
    HWREGH(DEVCFG_BASE + SYSCTL_O_SYSPLLCTL1) |= ((uint16)SYSCTL_SYSPLLCTL1_PLLCLKEN);

    /* ~200 PLLSYSCLK delay to allow voltage regulator to stabilize
        prior to increasing entire system clock frequency. */
    McalLib_Delay((uint32)48U);

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSPLLCTL1);

    /* Set the PLL Sys Clock divider */
    Mcu_SetPLLSysClk(sys_clk_div);

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_SYSCLKDIVSEL);
}

/*
 * Design: MCAL-21923
 */
FUNC(uint16, MCU_CODE) Mcu_IsPllLocked(void)
{
    return (HWREGH(DEVCFG_BASE + SYSCTL_O_SYSPLLSTS) & (uint16)SYSCTL_SYSPLLSTS_LOCKS);
}

/*
 * Design: MCAL-21924
 */
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetCause(void)
{
    VAR(Mcu_RawResetType, AUTOMATIC) reset_causes = (uint32)0U;

    McalLib_BromStatus* bootrom_status;
    McalLib_BootRomStructure(&bootrom_status);

    reset_causes =
        bootrom_status->ResetCause & (SYSCTL_RESC_POR | SYSCTL_RESC_XRSN | SYSCTL_RESC_WDRSN | SYSCTL_RESC_NMIWDRSN |
                                      SYSCTL_RESC_ECAT_RESET_OUT | SYSCTL_RESC_SIMRESET_XRSN | SYSCTL_RESC_ESMRESET);

    /* Return the reset reasons. */
    return (reset_causes);
}

/*
 * Design: MCAL-21925
 */
FUNC(Mcu_ResetType, MCU_CODE) Mcu_ConvertResetReason(Mcu_RawResetType RawResetType)
{
    VAR(Mcu_ResetType, AUTOMATIC) reset_reason = MCU_RESET_UNDEFINED;

    reset_reason = Mcu_ConvertFirstGroup(RawResetType);

    /* if reset reason is not validated and converted from first group POR, WDRS and SIMRESET */
    if (reset_reason == MCU_RESET_UNDEFINED)
    {
        /* cehck if reset reason is validated and converted from second group XRS, NMIWDRS and ESM
         * resets */
        reset_reason = Mcu_ConvertSecondGroup(RawResetType);
    }

    return reset_reason;
}

/*
 * Design: MCAL-21926
 */
FUNC(void, MCU_CODE) Mcu_ClearReset(Mcu_RawResetType RawResetType)
{
    HWREG(CPUSYS_BASE + SYSCTL_O_RESCCLR) = RawResetType;
}

/*
 * Design: MCAL-21927
 */
FUNC(void, MCU_CODE) Mcu_PerformControllerReset(void)
{
    /* Perform Simulated External Reset */
    HWREG(CPUSYS_BASE + SYSCTL_O_SIMRESET) = (SYSCTL_SIMRESET_KEY << SYSCTL_SIMRESET_KEY_S) | SYSCTL_SIMRESET_XRSN;
}

/*
 * Design: MCAL-21929
 */
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
FUNC(Std_ReturnType, MCU_CODE) Mcu_SetModeParamCheck(Mcu_ModeConfigPtrType ModeConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

    if (((uint8)MCU_MODE_MAX <= (uint8)ModeConfigPtr->Mcu_LowPowerMode) ||
        (((uint8)MCU_STANDBY_MODE == (uint8)ModeConfigPtr->Mcu_LowPowerMode) &&
         ((MCU_STANDBY_QUALPERIOD_MIN > ModeConfigPtr->Mcu_QualPeriod) ||
          (MCU_STANDBY_QUALPERIOD_MAX < ModeConfigPtr->Mcu_QualPeriod))))
    {
        /* Invalid Parameters */
    }
    else
    {
        return_value = (Std_ReturnType)E_OK;
    }

    return (return_value);
}
#endif /*MCU_CFG_DEV_ERROR_DETECT*/

/*
 * Design: MCAL-21928
 */
FUNC(void, MCU_CODE) Mcu_EnterLowPowerMode(Mcu_ModeConfigPtrType ModeConfigPtr)
{
    switch (ModeConfigPtr->Mcu_LowPowerMode)
    {
        case MCU_IDLE_MODE:
            /* Enter Low Power Mode */
            Mcu_EnterIdleMode();
            break;

        case MCU_STANDBY_MODE:
            /* Configure the Qualification Period for GPIO wakeup */
            Mcu_SetStandbyQualificationPeriod(ModeConfigPtr->Mcu_QualPeriod);

            /* Enable Watchdog Wakeup if needed */
            if (TRUE == ModeConfigPtr->Mcu_EnableWDWakeup)
            {
                Mcu_EnableWatchdogStandbyWakeup();
            }
            else
            {
                Mcu_DisableWatchdogStandbyWakeup();
            }

            /* Enter Low Power Mode */
            Mcu_EnterStandbyMode();
            break;

        default:
            /* Do Nothing */
            break;
    }
}

/*
 * Design: MCAL-28522
 */
FUNC(void, MCU_CODE) Mcu_FillRamSection(Mcu_RamConfigPtrType RamSectionConfigPtr)
{
    /* RAM destination pointer */
    P2VAR(uint8, AUTOMATIC, MCU_APPL_DATA) ram_destination = NULL_PTR;

    /* Local word counter */
    VAR(uint32, MCU_VAR) section_size        = 0U;
    VAR(uint8, MCU_VAR) section_writeSize    = 0U;
    VAR(uint8, MCU_VAR) section_defaultValue = 0U;
    VAR(uint32, MCU_VAR) num_iterations      = 0U;

    /* Load the RAM Section Base address from the configuration */
    ram_destination = RamSectionConfigPtr->Mcu_RamSectionBaseAddress;

    /* Load the Section Size & Section Write size & Default value from configuration*/
    section_size         = RamSectionConfigPtr->Mcu_RamSectionBytes;
    section_writeSize    = RamSectionConfigPtr->Mcu_RamSectionWriteSize;
    section_defaultValue = RamSectionConfigPtr->Mcu_RamDefaultValue;

    /*  Calculate the number of iterations required to fill the entire RAM section */
    num_iterations = (section_size / section_writeSize);

    switch (section_writeSize)
    {
        case 1U:
        {
            /* section_writeSize == 1U */
            uint8* write_buffer = ram_destination;
            for (uint32 i = 0; i < num_iterations; i++)
            {
                write_buffer[i] = section_defaultValue;
            }
            break;
        }

        case 2U:
        {
            /* section_writeSize == 2U */
            uint16* write_buffer = (uint16*)ram_destination;
            for (uint32 i = 0; i < num_iterations; i++)
            {
                write_buffer[i] = section_defaultValue;
            }
            break;
        }

        case 4U:
        {
            /* section_writeSize == 4U */
            uint32* write_buffer = (uint32*)ram_destination;
            for (uint32 i = 0; i < num_iterations; i++)
            {
                write_buffer[i] = section_defaultValue;
            }
            break;
        }

        case 8U:
        {
            /* section_writeSize == 8U */
            uint64* write_buffer = (uint64*)ram_destination;
            for (uint32 i = 0; i < num_iterations; i++)
            {
                write_buffer[i] = section_defaultValue;
            }
            break;
        }

        default:
        {
            /* Do Nothing */
            break;
        }
    }
}

#if (STD_ON == MCU_CLOCK_CONFIG_LOCK_CRITICAL_REGISTERS)
FUNC(void, MCU_CODE) Mcu_UnlockClockConfigRegisters(void)
{
    HWREG(DEVCFG_BASE + SYSCTL_O_CLKCFGLOCK1) = 0U;
}

FUNC(void, MCU_CODE) Mcu_LockClockConfigRegisters(void)
{
    HWREG(DEVCFG_BASE + SYSCTL_O_CLKCFGLOCK1) = 0xFFFFFFFFU;
}
#endif /*MCU_CLOCK_CONFIG_LOCK_CRITICAL_REGISTERS*/

#if (STD_ON == MCU_CPU_PERIPHERAL_CONFIG_LOCK_CRITICAL_REGISTERS)
FUNC(void, MCU_CODE) Mcu_UnlockCpuPeripheralConfigRegisters(void)
{
    HWREG(CPUPERCFG_BASE + SYSCTL_O_CPUPERCFGLOCK1) = 0U;
}

FUNC(void, MCU_CODE) Mcu_LockCpuPeripheralConfigRegisters(void)
{
    HWREG(CPUPERCFG_BASE + SYSCTL_O_CPUPERCFGLOCK1) = 0xFFFFFFFFU;
}
#endif /*MCU_CPU_PERIPHERAL_CONFIG_LOCK_CRITICAL_REGISTERS*/

#if (STD_ON == MCU_CPU_SYSTEM_LOCK_CRITICAL_REGISTERS)
FUNC(void, MCU_CODE) Mcu_UnlockCpuSysRegisters(void)
{
    /* LPMCR Register */
    VAR(uint32, AUTOMATIC) reg = ((uint32)(CPUSYS_BASE + SYSCTL_O_CPUSYSLOCK1) | 0x2U);
    HWREG((uint32)reg)         = (uint32)reg & 0U;
}

FUNC(void, MCU_CODE) Mcu_LockCpuSysRegisters(void)
{
    /* LOCK LPMCR Register */
    VAR(uint32, AUTOMATIC) reg = ((uint32)(CPUSYS_BASE + SYSCTL_O_CPUSYSLOCK1) | 0x2U);
    HWREG((uint32)reg)         = (uint32)reg & 0xFFFFFFFFU;
}
#endif /*MCU_CPU_SYSTEM_LOCK_CRITICAL_REGISTERS*/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
/*
 * Design: MCAL-28523
 */
static FUNC(Mcu_ResetType, MCU_CODE) Mcu_ConvertFirstGroup(Mcu_RawResetType RawResetType)
{
    VAR(Mcu_ResetType, AUTOMATIC) reset_reason = MCU_RESET_UNDEFINED;

    /* Power On Reset */
    if ((uint32)SYSCTL_RESC_POR == ((uint32)SYSCTL_RESC_POR & RawResetType))
    {
        reset_reason = MCU_POWER_ON_RESET;
    }
    /* Watchdog reset */
    else if ((uint32)SYSCTL_RESC_WDRSN == ((uint32)SYSCTL_RESC_WDRSN & RawResetType))
    {
        reset_reason = MCU_WATCHDOG_RESET;
    }
    /* Simulation of External Reset */
    else if (((uint32)SYSCTL_RESC_SIMRESET_XRSN == ((uint32)SYSCTL_RESC_SIMRESET_XRSN & RawResetType)))
    {
        reset_reason = MCU_SW_RESET;
    }
    else
    {
        /* Do Nothing*/
    }

    return reset_reason;
}

/*
 * Design: MCAL-28524
 */
static FUNC(Mcu_ResetType, MCU_CODE) Mcu_ConvertSecondGroup(Mcu_RawResetType RawResetType)
{
    VAR(Mcu_ResetType, AUTOMATIC) reset_reason = MCU_RESET_UNDEFINED;

    /* External Reset */
    if ((uint32)SYSCTL_RESC_XRSN == ((uint32)SYSCTL_RESC_XRSN & RawResetType))
    {
        reset_reason = MCU_EXTERNAL_RESET;
    }
    /* TI_COVERAGE_GAP_START [Branch Gap] ESM_NMI_WATCHDOG_RESET reason is not supported. Unable to
     * reproduce condition */
    /* NMI Watchdog reset */
    else if ((uint32)SYSCTL_RESC_NMIWDRSN == ((uint32)SYSCTL_RESC_NMIWDRSN & RawResetType))
    {
        reset_reason = MCU_ESM_NMI_WATCHDOG_RESET;
    }
    /* TI_COVERAGE_GAP_STOP*/
    /* TI_COVERAGE_GAP_START [Branch Gap] ESM_RESET reason is not supported. Unable to reproduce
     * condition */
    /* ESM reset */
    else if ((uint32)SYSCTL_RESC_ESMRESET == ((uint32)SYSCTL_RESC_ESMRESET & RawResetType))
    {
        reset_reason = MCU_ESM_RESET;
    }
    /* TI_COVERAGE_GAP_STOP*/
    else
    {
        /* Do Nothing*/
    }

    return reset_reason;
}

/*
 * Design: MCAL-28525
 */
static FUNC(void, MCU_CODE) Mcu_SetMCanClock(const Mcu_MCanClkConfigType* MCanClkCfg)
{
    VAR(uint8, AUTOMATIC) bitpos               = (uint8)0U;
    VAR(Mcu_MCANInstance, AUTOMATIC) mcan_inst = MCanClkCfg->Mcu_MCanInstance;
    VAR(Mcu_MCanClkSrc, AUTOMATIC) clksrc      = MCanClkCfg->Mcu_MCanClkSource;
    VAR(Mcu_MCANClkDivider, AUTOMATIC) divider = MCanClkCfg->Mcu_MCanClkDiv;

    /* Configure the clock divider */
    bitpos = 5U * (uint8)mcan_inst;
    HWREG(DEVCFG_BASE + SYSCTL_O_MCANCLKDIVSEL) =
        (HWREG(DEVCFG_BASE + SYSCTL_O_MCANCLKDIVSEL) & ~(SYSCTL_MCANCLKDIVSEL_MCANACLKDIV_M << bitpos)) |
        ((uint16)divider << bitpos);

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_MCANCLKDIVSEL);

    /* Configure the clock source */
    bitpos = (uint8)((SYSCTL_CLKSRCCTL2_MCANABCLKSEL_S) + (2U * (uint8)mcan_inst));
    HWREG(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL2) =
        (HWREG(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL2) & ~(0x3U << bitpos)) | ((uint16)clksrc << bitpos);

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_CLKSRCCTL2);
}

/*
 * Design: MCAL-28526
 */
static FUNC(void, MCU_CODE) Mcu_SetLinClock(const Mcu_LinClkConfigType* LinClkCfg)
{
    VAR(Mcu_LINInstance, AUTOMATIC) lin_inst  = LinClkCfg->Mcu_LinInstance;
    VAR(Mcu_LINClkDivider, AUTOMATIC) divider = LinClkCfg->Mcu_LinClkDiv;

    if (lin_inst == (Mcu_LINInstance)MCU_LIN_A)
    {
        /* Configure the LinA clock divider */
        HWREG(DEVCFG_BASE + SYSCTL_O_PERCLKDIVSEL) =
            (HWREG(DEVCFG_BASE + SYSCTL_O_PERCLKDIVSEL) & ~SYSCTL_PERCLKDIVSEL_LINACLKDIV_M) |
            ((uint32)divider << SYSCTL_PERCLKDIVSEL_LINACLKDIV_S);

        Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_PERCLKDIVSEL);
    }

    if (lin_inst == (Mcu_LINInstance)MCU_LIN_B)
    {
        /* Configure the LinB clock divider */
        HWREG(DEVCFG_BASE + SYSCTL_O_PERCLKDIVSEL) =
            (HWREG(DEVCFG_BASE + SYSCTL_O_PERCLKDIVSEL) & ~SYSCTL_PERCLKDIVSEL_LINBCLKDIV_M) |
            ((uint32)divider << SYSCTL_PERCLKDIVSEL_LINBCLKDIV_S);

        Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_PERCLKDIVSEL);
    }
}

/*
 * Design: MCAL-28527
 */
static FUNC(void, MCU_CODE) Mcu_SetCpuTimerClock(const Mcu_CpuTimerClkConfigType* CpuTimerClkCfg)
{
    /* Select Cpu Timer 2 Clock Source */
    HWREGH(CPUSYS_BASE + SYSCTL_O_TMR2CLKCTL) =
        (HWREGH(CPUSYS_BASE + SYSCTL_O_TMR2CLKCTL) & (uint16) ~(SYSCTL_TMR2CLKCTL_TMR2CLKSRCSEL_M)) |
        ((uint16)(CpuTimerClkCfg->Mcu_CpuTimer2ClkSource) << (uint16)SYSCTL_TMR2CLKCTL_TMR2CLKSRCSEL_S);

    /* Set Cpu Timer 2 Clock Divider */
    HWREGH(CPUSYS_BASE + SYSCTL_O_TMR2CLKCTL) =
        (HWREGH(CPUSYS_BASE + SYSCTL_O_TMR2CLKCTL) & (uint16) ~(SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_M)) |
        (((uint16)CpuTimerClkCfg->Mcu_CpuTimer2ClkDiv - (uint16)1U) << (uint16)SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_S);
}

/*
 * Design: MCAL-28528
 */
static FUNC(void, MCU_CODE) Mcu_SetExternalClockOutput(const Mcu_ExternalClkOutConfigType* ExternalClkOutCfg)
{
    if ((boolean)TRUE == ExternalClkOutCfg->Mcu_ExternalClockOut)
    {
        /* Select External Clock Output Source */
        HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL3) =
            (HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL3) & (uint16) ~(SYSCTL_CLKSRCCTL3_XCLKOUTSEL_M)) |
            ((uint16)(ExternalClkOutCfg->Mcu_ExternalClockOutSource) << (uint16)SYSCTL_CLKSRCCTL3_XCLKOUTSEL_S);

        Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_CLKSRCCTL3);

        /* Set External Clock Output Divider */
        HWREG(DEVCFG_BASE + SYSCTL_O_XCLKOUTDIVSEL) = ExternalClkOutCfg->Mcu_ExternalClkOutDiv;

        Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_XCLKOUTDIVSEL);
    }
}

/*
 * Design: MCAL-28529
 */
static FUNC(void, MCU_CODE) Mcu_SetEthercatClock(const Mcu_EthercatClkConfigType* EthercatClkCfg)
{
    /* Select Ethercat Clock divder and enable/disable flag */
    HWREGH(DEVCFG_BASE + SYSCTL_O_ETHERCATCLKCTL) =
        (uint16)((uint16)((uint16)(HWREGH(DEVCFG_BASE + SYSCTL_O_ETHERCATCLKCTL) &
                                   (uint16) ~(SYSCTL_ETHERCATCLKCTL_PHYCLKEN)) |
                          (uint16)SYSCTL_ETHERCATCLKCTL_ECATDIV_M) |
                 (uint16)((uint16)EthercatClkCfg->Mcu_EthercatClkDiv << (uint16)SYSCTL_ETHERCATCLKCTL_ECATDIV_S)) |
        (uint16)EthercatClkCfg->Mcu_EthercatPhyClkEnable;

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_ETHERCATCLKCTL);
}

/*
 * Design: MCAL-28530
 */
static FUNC(void, MCU_CODE) Mcu_SetHsmClock(Mcu_HsmClockDiv HsmClkDiv)
{
    /* Select Hsm Clock divder */
    HWREG(DEVCFG_BASE + SYSCTL_O_HSMCLKDIVSEL) =
        (HWREG(DEVCFG_BASE + SYSCTL_O_HSMCLKDIVSEL) & (uint32)~SYSCTL_HSMCLKDIVSEL_HSMCLKDIV_M) |
        ((uint32)HsmClkDiv << (uint32)SYSCTL_HSMCLKDIVSEL_HSMCLKDIV_S);
}

/*
 * Design: MCAL-28531
 */
static FUNC(void, MCU_CODE) Mcu_SetEpwmClock(Mcu_EPWMClkDivider EpwmClkDiv)
{
    /* Select Epwm Clock divder  */
    HWREGH(DEVCFG_BASE + SYSCTL_O_PERCLKDIVSEL) =
        (HWREGH(DEVCFG_BASE + SYSCTL_O_PERCLKDIVSEL) & ~SYSCTL_PERCLKDIVSEL_EPWMCLKDIV_M) | (uint16)EpwmClkDiv;

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_PERCLKDIVSEL);
}

/*
 * Design: MCAL-28532
 */
static FUNC(void, MCU_CODE) Mcu_SetEmifClock(Mcu_EMIFClkDivider EmifClkDiv)
{
    /* Select Emif Clock divder  */
    HWREG(DEVCFG_BASE + SYSCTL_O_PERCLKDIVSEL) =
        (HWREG(DEVCFG_BASE + SYSCTL_O_PERCLKDIVSEL) & ~SYSCTL_PERCLKDIVSEL_EMIF1CLKDIV_M) |
        ((uint32)EmifClkDiv << SYSCTL_PERCLKDIVSEL_EMIF1CLKDIV_S);

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_PERCLKDIVSEL);
}

/*
 * Design: MCAL-28533
 */
static FUNC(void, MCU_CODE) Mcu_SelectOscSource(Mcu_ClkSourceIdType OscSource)
{
    /* Select the specified source. */
    switch (OscSource)
    {
        case MCU_CLKSRC_OSC2:
            /* Clk Src = INTOSC2 */
            HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) &= (uint16)~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M;

            Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_CLKSRCCTL1);
            break;

        case MCU_CLKSRC_OSC1:
            /* Clk Src = INTOSC1 */
            HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
                (uint16)(HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) & (uint16)~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M) |
                (uint16)MCU_CLKSRC_OSC1;

            Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_CLKSRCCTL1);
            break;

        case MCU_CLKSRC_XTAL:
            /* Select XTAL in crystal mode and wait for it to power up */
            Mcu_SelectXTAL();
            break;

        case MCU_CLKSRC_XTAL_SE:
            /* Select XTAL in single-ended mode and wait for it to power up */
            Mcu_SelectXTALSingleEnded();
            break;
        /* TI_COVERAGE_GAP_START [Branch Gap] Default check added as MISRA required */
        default:
            /* Do nothing. Not a valid oscSource value. */
            break;
            /* TI_COVERAGE_GAP_STOP*/
    }
}

/*
 * Design: MCAL-28534
 */
static FUNC(void, MCU_CODE) Mcu_SelectXTAL(void)
{
    VAR(boolean, AUTOMATIC) status    = FALSE;
    VAR(uint16, AUTOMATIC) loop_count = (uint16)0U;

    /* Enable XOSC pads initialization and set X1, X2 high */
    HWREGH(DEVCFG_BASE + SYSCTL_O_XTALCR2) |= (uint16)(SYSCTL_XTALCR2_FEN | SYSCTL_XTALCR2_XIF | SYSCTL_XTALCR2_XOF);

    /* Wait for few cycles to allow load capacitors to charge */
    MCU_XTAL_CHARGE_DELAY;

    /* Turn on XTAL and select crystal mode */
    HWREGH(DEVCFG_BASE + SYSCTL_O_XTALCR) &= (uint16)~SYSCTL_XTALCR_OSCOFF;
    HWREGH(DEVCFG_BASE + SYSCTL_O_XTALCR) &= (uint16)~SYSCTL_XTALCR_SE;

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_XTALCR);

    /*  Wait for the X1 clock to saturate */
    status = Mcu_PollX1Counter();

    /* Select XTAL as the oscillator source */
    HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
        ((uint16)(HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) & ((uint16)~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M)) |
         ((uint16)MCU_CLKSRC_XTAL));

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_CLKSRCCTL1);

    /* If a missing clock failure was detected, try waiting for the X1 counter
    to saturate again. Consider modifying this code to add a 10ms timeout */
    /* TI_COVERAGE_GAP_START [Branch Gap] unable to simulate mcddetect in test */
    while (((boolean)TRUE == (boolean)Mcu_IsMCDClockFailureDetected()) && ((boolean)status == (boolean)FALSE) &&
           (loop_count < (uint16)4U))
    /* TI_COVERAGE_GAP_STOP*/
    {
        /* Clear the MCD failure */
        Mcu_ResetMCD();

        /* Wait for the X1 clock to saturate */
        status = Mcu_PollX1Counter();

        /*  Select XTAL as the oscillator source */
        HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
            ((uint16)(HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) & ((uint16)~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M)) |
             ((uint16)MCU_CLKSRC_XTAL));

        Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_CLKSRCCTL1);

        loop_count++;
    }

    /* TI_COVERAGE_GAP_START [Branch Gap] unable to simulate mcddetect in test */
    if (status == FALSE)
    {
        /* If code is stuck here, it means crystal has not started.
        Replace crystal or update code below to take necessary actions if crystal is bad
        Replace the EMUSTOP0 with an appropriate error-handling routine. */
        MCAL_LIB_EMUSTOP0;
    }
    /* TI_COVERAGE_GAP_STOP*/
}

/*
 * Design: MCAL-28535
 */
static FUNC(void, MCU_CODE) Mcu_SelectXTALSingleEnded(void)
{
    VAR(boolean, AUTOMATIC) status    = FALSE;
    VAR(uint16, AUTOMATIC) loop_count = (uint16)0U;

    /* Enable XOSC pads initialization and set X1, X2 high */
    HWREGH(DEVCFG_BASE + SYSCTL_O_XTALCR2) |= (uint16)(SYSCTL_XTALCR2_FEN | SYSCTL_XTALCR2_XIF | SYSCTL_XTALCR2_XOF);

    /* Wait for few cycles to allow load capacitors to charge */
    MCU_XTAL_CHARGE_DELAY;

    /* Turn on XTAL and select single ended mode */
    HWREGH(DEVCFG_BASE + SYSCTL_O_XTALCR) &= ((uint16)~SYSCTL_XTALCR_OSCOFF);
    HWREGH(DEVCFG_BASE + SYSCTL_O_XTALCR) |= ((uint16)SYSCTL_XTALCR_SE);

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_XTALCR);

    /*  Wait for the X1 clock to saturate */
    status = Mcu_PollX1Counter();

    /* Select XTAL SE as the oscillator source */
    HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
        ((uint16)(HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) & ((uint16)~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M)) |
         ((uint16)MCU_CLKSRC_XTAL));

    Mcu_PollSyncBusy(SYSCTL_SYNCBUSY_CLKSRCCTL1);

    /* If a missing clock failure was detected, try waiting for the X1 counter
    to saturate again. Consider modifying this code to add a 10ms timeout */
    /* TI_COVERAGE_GAP_START [Branch Gap] unable to simulate mcddetect in test */
    while (((boolean)TRUE == (boolean)Mcu_IsMCDClockFailureDetected()) && ((boolean)status == (boolean)FALSE) &&
           (loop_count < (uint16)4U))
    /* TI_COVERAGE_GAP_STOP*/
    {
        /* Clear the MCD failure */
        Mcu_ResetMCD();

        /* Wait for the X1 clock to saturate */
        status = Mcu_PollX1Counter();

        /*  Select XTAL SE as the oscillator source */
        HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) =
            ((uint16)(HWREGH(DEVCFG_BASE + SYSCTL_O_CLKSRCCTL1) & ((uint16)~SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M)) |
             ((uint16)MCU_CLKSRC_XTAL_SE));

        loop_count++;
    }

    /* TI_COVERAGE_GAP_START [Branch Gap] unable to simulate mcddetect in test */
    if (status == FALSE)
    {
        /* If code is stuck here, it means crystal has not started.
        Replace crystal or update code below to take necessary actions if crystal is bad
        Replace the EMUSTOP0 with an appropriate error-handling routine. */
        MCAL_LIB_EMUSTOP0;
    }
    /* TI_COVERAGE_GAP_STOP*/
}

/*
 * Design: MCAL-28536
 */
static FUNC(void, MCU_CODE) Mcu_ClearX1Counter(void)
{
    /* Keep clearing the counter until it is no longer saturated */
    while (HWREG(DEVCFG_BASE + SYSCTL_O_X1CNT) > (uint32)SYSCTL_X1CNT_X1CNT_M) /* 0x7FFU*/
    {
        HWREG(DEVCFG_BASE + SYSCTL_O_X1CNT) |= ((uint32)SYSCTL_X1CNT_CLR);
    }
}

/*
 * Design: MCAL-28537
 */
static FUNC(boolean, MCU_CODE) Mcu_WaitX1Saturate(uint16 loop_count)
{
    VAR(boolean, AUTOMATIC) status       = FALSE;
    VAR(uint32, AUTOMATIC) local_counter = (uint32)0U;

    /* Wait for the X1 clock to saturate */
    /* TI_COVERAGE_GAP_START [Branch Gap] unable to reproduce the scenario using S/W */
    while (HWREG(DEVCFG_BASE + SYSCTL_O_X1CNT) != (uint32)SYSCTL_X1CNT_X1CNT_M) /* 0x7FFU*/
    {
        /* If your application is stuck in this loop, please check if the
        input clock source is valid */

        local_counter++;
        if (local_counter > (uint32)2500000U)
        {
            if (loop_count == (uint16)3U)
            {
                status = FALSE;
            }
            break;
        }
    }
    /* TI_COVERAGE_GAP_STOP*/

    if ((loop_count == (uint16)3U) && (HWREG(DEVCFG_BASE + SYSCTL_O_X1CNT) == (uint32)SYSCTL_X1CNT_X1CNT_M))
    {
        status = TRUE;
    }

    local_counter = ((uint32)0U);

    return status;
}

/*
 * Design: MCAL-28538
 */
static FUNC(boolean, MCU_CODE) Mcu_PollX1Counter(void)
{
    VAR(uint16, AUTOMATIC) loop_count = (uint16)0U;
    VAR(boolean, AUTOMATIC) status    = FALSE;

    /* Delay for 1 ms while the XTAL powers up
    2500 loops, 4 cycles per loop + 11 cycles overhead = 10011 cycles */
    McalLib_Delay((uint32)2500U);

    /* Clear and saturate X1CNT 4 times to guarantee operation */
    do
    {
        /* Keep clearing the counter until it is no longer saturated */
        Mcu_ClearX1Counter();

        /* Wait for the X1 clock to saturate */
        status = Mcu_WaitX1Saturate(loop_count);

        /* Increment the counter */
        loop_count++;
    } while (loop_count < (uint16)4U);

    return status;
}

/*
 * Design: MCAL-28539
 */
static FUNC(void, MCU_CODE) Mcu_DeviceEnablePeripherals(Mcu_PeripheralClkRegConfigPtrType PeripheralClkConfigPtr)
{
    /* Turn on the module clock. */
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR0)  = PeripheralClkConfigPtr->Mcu_PeripheralClk0Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR1)  = PeripheralClkConfigPtr->Mcu_PeripheralClk1Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR2)  = PeripheralClkConfigPtr->Mcu_PeripheralClk2Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR3)  = PeripheralClkConfigPtr->Mcu_PeripheralClk3Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR4)  = PeripheralClkConfigPtr->Mcu_PeripheralClk4Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR6)  = PeripheralClkConfigPtr->Mcu_PeripheralClk6Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR7)  = PeripheralClkConfigPtr->Mcu_PeripheralClk7Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR8)  = PeripheralClkConfigPtr->Mcu_PeripheralClk8Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR9)  = PeripheralClkConfigPtr->Mcu_PeripheralClk9Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR10) = PeripheralClkConfigPtr->Mcu_PeripheralClk10Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR13) = PeripheralClkConfigPtr->Mcu_PeripheralClk13Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR14) = PeripheralClkConfigPtr->Mcu_PeripheralClk14Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR16) = PeripheralClkConfigPtr->Mcu_PeripheralClk16Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR17) = PeripheralClkConfigPtr->Mcu_PeripheralClk17Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR18) = PeripheralClkConfigPtr->Mcu_PeripheralClk18Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR19) = PeripheralClkConfigPtr->Mcu_PeripheralClk19Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR20) = PeripheralClkConfigPtr->Mcu_PeripheralClk20Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR21) = PeripheralClkConfigPtr->Mcu_PeripheralClk21Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR23) = PeripheralClkConfigPtr->Mcu_PeripheralClk23Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR25) = PeripheralClkConfigPtr->Mcu_PeripheralClk25Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR27) = PeripheralClkConfigPtr->Mcu_PeripheralClk27Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR28) = PeripheralClkConfigPtr->Mcu_PeripheralClk28Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR30) = PeripheralClkConfigPtr->Mcu_PeripheralClk30Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_PCLKCR32) = PeripheralClkConfigPtr->Mcu_PeripheralClk32Reg;
}

static FUNC(void, MCU_CODE) Mcu_DeviceResetPeripherals(Mcu_PeripheralResetRegConfigPtrType PeripheralResetConfigPtr)
{
    /* Reset the peripheral. */
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES0)  = PeripheralResetConfigPtr->Mcu_PeripheralReset0Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES1)  = PeripheralResetConfigPtr->Mcu_PeripheralReset1Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES2)  = PeripheralResetConfigPtr->Mcu_PeripheralReset2Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES3)  = PeripheralResetConfigPtr->Mcu_PeripheralReset3Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES4)  = PeripheralResetConfigPtr->Mcu_PeripheralReset4Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES6)  = PeripheralResetConfigPtr->Mcu_PeripheralReset6Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES7)  = PeripheralResetConfigPtr->Mcu_PeripheralReset7Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES8)  = PeripheralResetConfigPtr->Mcu_PeripheralReset8Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES9)  = PeripheralResetConfigPtr->Mcu_PeripheralReset9Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES10) = PeripheralResetConfigPtr->Mcu_PeripheralReset10Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES13) = PeripheralResetConfigPtr->Mcu_PeripheralReset13Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES14) = PeripheralResetConfigPtr->Mcu_PeripheralReset14Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES16) = PeripheralResetConfigPtr->Mcu_PeripheralReset16Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES17) = PeripheralResetConfigPtr->Mcu_PeripheralReset17Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES18) = PeripheralResetConfigPtr->Mcu_PeripheralReset18Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES19) = PeripheralResetConfigPtr->Mcu_PeripheralReset19Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES20) = PeripheralResetConfigPtr->Mcu_PeripheralReset20Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES21) = PeripheralResetConfigPtr->Mcu_PeripheralReset21Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES23) = PeripheralResetConfigPtr->Mcu_PeripheralReset23Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES25) = PeripheralResetConfigPtr->Mcu_PeripheralReset25Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES27) = PeripheralResetConfigPtr->Mcu_PeripheralReset27Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES28) = PeripheralResetConfigPtr->Mcu_PeripheralReset28Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES30) = PeripheralResetConfigPtr->Mcu_PeripheralReset30Reg;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES32) = PeripheralResetConfigPtr->Mcu_PeripheralReset32Reg;
}

static FUNC(void, MCU_CODE) Mcu_DeviceResetAllPeripherals(void)
{
    /* Reset all peripherals. */
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES0)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES1)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES2)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES3)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES4)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES6)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES7)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES8)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES9)  = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES10) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES13) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES14) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES16) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES17) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES18) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES19) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES20) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES21) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES23) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES25) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES27) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES28) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES30) = (uint32)0xFFFFFFFFU;
    HWREG(CPUPERCFG_BASE + SYSCTL_O_SOFTPRES32) = (uint32)0xFFFFFFFFU;
}

#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
/*
 * Design: MCAL-28540
 */
static FUNC(boolean, MCU_CODE) Mcu_XtalFreqRangeCheck(Mcu_ClockConfigPtrType ClockConfigPtr)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

    /* CLK SRC = XTAL    and XTAL    MAX Freq Range : 20 MHz  */
    /* CLK SRC = XTAL_SE and XTAL_SE MAX Freq Range : 25 MHz  */
    if ((((MCU_CLKSRC_XTAL == ClockConfigPtr->Mcu_ClockSourceId) &&
          ((MCU_EXTCLKFREQ_XTAL_MIN > ClockConfigPtr->Mcu_ExternalClkFreq) ||
           (MCU_EXTCLKFREQ_XTAL_MAX < ClockConfigPtr->Mcu_ExternalClkFreq))) ||
         ((MCU_CLKSRC_XTAL_SE == ClockConfigPtr->Mcu_ClockSourceId) &&
          ((MCU_EXTCLKFREQ_XTAL_SE_MIN > ClockConfigPtr->Mcu_ExternalClkFreq) ||
           (MCU_EXTCLKFREQ_XTAL_SE_MAX < ClockConfigPtr->Mcu_ExternalClkFreq)))))
    {
        /* Invalid Parameters */
        status = TRUE;
    }
    return status;
}

/*
 * Design: MCAL-28541
 */
static FUNC(boolean, MCU_CODE) Mcu_PllSettingsRangeCheck(Mcu_ClockConfigPtrType ClockConfigPtr)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

#if (STD_OFF == MCU_CFG_NO_PLL)
    /* Check the PLL settings */
    if ((MCU_PLLREFDIV_MAX < ClockConfigPtr->Mcu_PllRefDiv) ||   /* Reference Divider Max Range: 32U */
        (MCU_PLLINTMULT_MAX < ClockConfigPtr->Mcu_PllIntMult) || /* Integer Multiplier Max Range: 255U */
        (MCU_PLLOUTDIV_MAX < ClockConfigPtr->Mcu_PllOutDiv))     /* Output Divider Max Range: 32U */
    {
        /* Invalid Parameters */
        status = TRUE;
    }
#endif /*MCU_CFG_NO_PLL*/

    return status;
}

/*
 * Design: MCAL-28542
 */
static FUNC(boolean, MCU_CODE) Mcu_DerivedClockFreqRangeCheck(uint32 oscClk, Mcu_ClockConfigPtrType ClockConfigPtr)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

    VAR(uint32, AUTOMATIC) pll_raw_clk = (uint32)0U;
    VAR(uint32, AUTOMATIC) pll_int_clk = (uint32)0U;
    VAR(uint32, AUTOMATIC) pll_vco_clk = (uint32)0U;
    VAR(uint32, AUTOMATIC) sys_clk     = (uint32)0U;

#if (STD_OFF == MCU_CFG_NO_PLL)
    /* Get Internal Clock = (Osc clock / Reference Divider) */
    pll_int_clk = (oscClk / (uint32)(ClockConfigPtr->Mcu_PllRefDiv)); /* ex: Internal Clock = (10MHz / 1) */

    /* Get Vco Clock = (Internal clock / Integer Multipler) */
    pll_vco_clk = (pll_int_clk * (uint32)(ClockConfigPtr->Mcu_PllIntMult)); /* ex: Vco Clock  = (10MHz * 40) */

    /* Get Pll RAW Clock = (Vco clock / Output Divider) */
    pll_raw_clk = (pll_vco_clk / (uint32)(ClockConfigPtr->Mcu_PllOutDiv)); /* ex: Pll Raw Clock  = (400 MHz / 2) */
#else
    pll_raw_clk = oscClk;
#endif /*MCU_CFG_NO_PLL*/

#if (STD_OFF == MCU_CFG_NO_PLL)
    if (((MCU_PLLINTCLK_MIN > pll_int_clk) || (MCU_PLLINTCLK_MAX < pll_int_clk)) || /* Internal clock range: 2-25 MHz */
        ((MCU_PLLVCOCLK_MIN > pll_vco_clk) || (MCU_PLLVCOCLK_MAX < pll_vco_clk)) || /* Vco clock range: 220-600 MHz */
        ((MCU_PLLRAWCLK_MIN > pll_raw_clk) || (MCU_PLLRAWCLK_MAX < pll_raw_clk)))   /* PLL Raw clock range: 6-400 MHz */
    {
        /* Invalid Parameters */
        status = TRUE;
    }
#endif /*MCU_CFG_NO_PLL*/

    /* System clock = (Pll Raw clock / Sys clock divider )*/
    sys_clk = (pll_raw_clk / (uint32)(ClockConfigPtr->Mcu_SysClkDiv)); /* ex: System Clock  = (200 MHz / 1) */

    /* Check Freq ranges */
    if (((MCU_SYSCLK_MIN > sys_clk) || (MCU_SYSCLK_MAX < sys_clk))) /* System clock range: 2-200 MHz */
    {
        /* Invalid Parameters */
        status = TRUE;
    }

    return status;
}
#endif /*MCU_CFG_DEV_ERROR_DETECT*/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
/*
 * Design: MCAL-28543
 */
LOCAL_INLINE FUNC(boolean, MCU_CODE) Mcu_IsMCDClockFailureDetected(void)
{
    /* Check the status bit to determine failure */
    return ((HWREGH(DEVCFG_BASE + SYSCTL_O_MCDCR) & (uint16)SYSCTL_MCDCR_MCLKSTS) != (uint16)0U);
}

/*
 * Design: MCAL-28544
 */
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_ResetMCD(void)
{
    /* reset missing clock detection control register */
    HWREGH(DEVCFG_BASE + SYSCTL_O_MCDCR) |= (uint16)SYSCTL_MCDCR_MCLKCLR;
}

/*
 * Design: MCAL-28545
 */
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_SetPLLSysClk(uint16 divider)
{
    HWREGH(DEVCFG_BASE + SYSCTL_O_SYSCLKDIVSEL) = divider;
}

/*
 * Design: MCAL-28546
 */
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_EnterIdleMode(void)
{
    /* Configure the device to go into IDLE mode when IDLE is executed. */
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
        (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) & ~(uint32)SYSCTL_LPMCR_LPM_M) | MCU_LPM_IDLE;

    /* IDLE Instruction for putting processor into a low-power mode */
    MCAL_LIB_IDLE;
}

/*
 * Design: MCAL-28547
 */
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_EnterStandbyMode(void)
{
    /* Configure the device to go into STANDBY mode when IDLE is executed. */
    HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) =
        (HWREG(CPUSYS_BASE + SYSCTL_O_LPMCR) & ~(uint32)SYSCTL_LPMCR_LPM_M) | MCU_LPM_STANDBY;

    /* IDLE Instruction for putting processor into a low-power mode */
    MCAL_LIB_IDLE;
}

/*
 * Design: MCAL-28548
 */
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_SetStandbyQualificationPeriod(uint16 cycles)
{
    /* Set the standby qualification period */
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) = (HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) & ~(uint16)SYSCTL_LPMCR_QUALSTDBY_M) |
                                           ((cycles - (uint16)2U) << (uint16)SYSCTL_LPMCR_QUALSTDBY_S);
}

/*
 * Design: MCAL-28549
 */
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_EnableWatchdogStandbyWakeup(void)
{
    /* Set the bit enables the watchdog to wake up the device from STANDBY. */
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) |= (uint16)SYSCTL_LPMCR_WDINTE;
}

/*
 * Design: MCAL-28550
 */
LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_DisableWatchdogStandbyWakeup(void)
{
    /* Clear the bit enables the watchdog to wake up the device from STANDBY.*/
    HWREGH(CPUSYS_BASE + SYSCTL_O_LPMCR) &= (uint16)~SYSCTL_LPMCR_WDINTE;
}

LOCAL_INLINE FUNC(void, MCU_CODE) Mcu_PollSyncBusy(uint32 mask)
{
    VAR(uint32, AUTOMATIC) timeoutCnt = (uint32)0U;

    /* Wait for BUSY bit to clear */
    while ((HWREG(DEVCFG_BASE + SYSCTL_O_SYNCBUSY) & mask) == mask)
    {
        if (timeoutCnt >= SYSCTL_SYNCBUSY_TIMEOUT_CYCLES)
        {
            break;
        }

        timeoutCnt++;
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  End of File: Mcu_Priv.c
 *********************************************************************************************************************/
