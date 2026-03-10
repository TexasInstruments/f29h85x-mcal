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
 *  File:       Wdg_Priv.c
 *  Generator:  None
 *
 *  Description:  This file contains controller dependent local functions and private functions
 *                to be used in Wdg.c
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Wdg_Priv.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

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

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/** \brief Sets up watchdog clock (WDCLK) pre-divider.
 *
 * This function sets up the watchdog clock (WDCLK) pre-divider. There are two
 * dividers that scale INTOSC1 to WDCLK. The predivider parameter divides
 * INTOSC1 down to PREDIVCLK and the prescaler divides PREDIVCLK down to WDCLK.
 *
 * \param[in] predivider is the value that configures the pre-divider.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogPredivider(VAR(Wdg_PreDivider, AUTOMATIC) predivider);

/** \brief Sets up watchdog clock (WDCLK) prescaler.
 *
 * This function sets up the watchdog clock (WDCLK) prescaler. There are two
 * dividers that scale INTOSC1 to WDCLK. The predivider divides INTOSC1 down to PREDIVCLK
 * and the prescaler parameter divides PREDIVCLK down to WDCLK.
 *
 * \param[in] prescaler is the value that configures the watchdog clock relative
 *                      to the value from the pre-divider.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogPrescaler(VAR(Wdg_PreScaler, AUTOMATIC) prescaler);

/** \brief Set the minimum threshold value for windowed watchdog
 *
 * This function sets the minimum threshold value used to define the lower
 * limit of the windowed watchdog functionality.
 *
 * \param[in] value is the value to set the window threshold
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogWindowValue(VAR(uint16, AUTOMATIC) value);

/** \brief Configures whether the watchdog generates a reset or an interrupt signal.
 *
 * This function configures the action taken when the watchdog counter reaches
 * its maximum value. When the mode parameter is
 * WDG_GENERATE_INTERRUPT, the watchdog is enabled to generate a watchdog
 * interrupt signal and disables the generation of a reset signal. This will
 * allow the watchdog module to wake up the device from IDLE or STANDBY if desired
 *
 * When the mode parameter is WDG_GENERATE_RESET, the watchdog will
 * be put into reset mode and generation of a watchdog interrupt signal will
 * be disabled. This is how the watchdog is configured by default.
 *
 * Check the status of the watchdog interrupt using
 * Wdg_IsWatchdogInterruptActive() before calling this function. If the
 * interrupt is still active, switching from interrupt mode to reset mode will
 * immediately reset the device.
 *
 *
 * \param[in] reaction is a flag to select the WDG_GENERATE_INTERRUPT or WDG_GENERATE_RESET.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogReaction(VAR(Wdg_Reaction, AUTOMATIC) reaction);

/** \brief Gets the status of the watchdog interrupt signal.
 *
 * This function returns the status of the watchdog interrupt signal. If the
 * interrupt is active, this function will return true. If the
 * interrupt is not active, this function will return false
 *
 * Make sure to call this function to ensure that the interrupt is not
 * active before making any changes to the configuration of the watchdog to
 * prevent any unexpected behavior. For instance, switching from interrupt
 * mode to reset mode while the interrupt is active will immediately reset the device
 *
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if the interrupt is active
 * \retval FALSE if the interrupt is not active
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_IsWatchdogInterruptActive(void);

/** \brief Checks the reaction parameter range
 *
 * \param[in] reaction Reaction type i.e reset or interrupt
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if it is valid param
 *         FALSE if it is invalid param
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_CheckReactionParam(VAR(Wdg_Reaction, AUTOMATIC) reaction);

/** \brief Checks the Prescaler parameter range
 *
 * \param[in] prescaler Prescaler value
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if it is valid param
 *         FALSE if it is invalid param
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_CheckPrescalerParam(VAR(Wdg_PreScaler, AUTOMATIC) prescaler);

/** \brief Checks the Predivider parameter range
 *
 * \param[in] predivider Predivider value
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if it is valid param
 *         FALSE if it is invalid param
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_CheckPredividerParam(VAR(Wdg_PreDivider, AUTOMATIC) predivider);

/** \brief Checks the Threshold parameter range
 *
 * \param[in] threshold Threshold value
 * \pre None
 * \post None
 * \return boolean type
 * \retval TRUE if it is valid param
 *         FALSE if it is invalid param
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_CheckThresholdParam(VAR(uint16, AUTOMATIC) threshold);

/** \brief Check the Mode configuration parameters range
 *
 * \param[in] ModeCfg pointer to the Watchdog Mode settings
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE)
    Wdg_CheckConfigParameterRange(P2CONST(Wdg_ModeInfoType, AUTOMATIC, WDG_APPL_DATA) ModeCfg);

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
/*
 * Design: MCAL-25294
 */
FUNC(Std_ReturnType, WDG_CODE)
Wdg_PlatformInit(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_DATA) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val                        = (Std_ReturnType)E_NOT_OK;
    P2CONST(Wdg_ModeInfoType, AUTOMATIC, WDG_APPL_CONST) mode_cfg = NULL_PTR;

    /* Assign the Default mode configuration settings */
    if (ConfigPtr->Wdg_DefaultMode == WDGIF_FAST_MODE)
    {
        mode_cfg = &ConfigPtr->Wdg_FastModeCfg;
    }
    else
    {
        mode_cfg = &ConfigPtr->Wdg_SlowModeCfg;
    }

    /* Set the configuration values into registers*/
    ret_val = Wdg_SetModeConfig(mode_cfg);

    return ret_val;
}

/*
 * Design: MCAL-25295
 */
FUNC(Std_ReturnType, WDG_CODE)
Wdg_SetModeConfig(P2CONST(Wdg_ModeInfoType, AUTOMATIC, WDG_APPL_DATA) ModeCfg)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = (Std_ReturnType)E_NOT_OK;

    /* Check the Mode configuration parameters range */
    ret_val = Wdg_CheckConfigParameterRange(ModeCfg);

    /* if all parameters validation is correct, then set mode configuration*/
    if (ret_val == (Std_ReturnType)E_OK)
    {
        /* Write the Pre-divider value into register */
        Wdg_SetWatchdogPredivider(ModeCfg->PreDivider);

        /* Write the Pre-scaler value into register */
        Wdg_SetWatchdogPrescaler(ModeCfg->PreScaler);

        if ((boolean)Wdg_IsWatchdogInterruptActive() == (boolean)FALSE)
        {
            /* Write the Reaction type into register */
            Wdg_SetWatchdogReaction(ModeCfg->Reaction);
        }

        /* Write the Windowed Minimum Threshold value into register */
        Wdg_SetWatchdogWindowValue(ModeCfg->Threshold);

        /* Delay of at least 69 OSCCLK cycles required */
        McalLib_Delay((uint32)14U);
    }
    else
    {
        /* Do nothing*/
    }

    return ret_val;
}

/*
 * Design: MCAL-28557
 */
FUNC(void, WDG_CODE) Wdg_EnableWatchdog(void)
{
    /* Clear the disable bit */
    HWREGH((WD_BASE + SYSCTL_O_WDCR)) =
        (uint16)((HWREGH((WD_BASE + SYSCTL_O_WDCR)) & (uint16)~SYSCTL_WDCR_WDDIS) | WDG_CHKBITS);
}

/*
 * Design: MCAL-28558
 */
FUNC(void, WDG_CODE) Wdg_DisableWatchdog(void)
{
    /* Set the disable bit */
    HWREGH((WD_BASE + SYSCTL_O_WDCR)) |= (uint16)(WDG_CHKBITS | SYSCTL_WDCR_WDDIS);
}

/*
 * Design: MCAL-28559
 */
FUNC(void, WDG_CODE) Wdg_ServiceWatchdog(void)
{
    /* Enable the counter to be reset and then reset it */
    HWREGH((WD_BASE + SYSCTL_O_WDKEY)) = (uint16)WDG_ENRSTKEY;
    HWREGH((WD_BASE + SYSCTL_O_WDKEY)) = (uint16)WDG_RSTKEY;
}

/*
 * Design: MCAL-28560
 */
FUNC(void, WDG_CODE) Wdg_GenerateImmediateEvent(void)
{
    /* Write the WDCHK(3 bit field) value other than "1 0 1" in to WDCR register */
    /* By Default WDG_CHKBITS the 3 bit value it is set to 0x28 : 0010 1000 : Where 3 bit pattern is
     * 1 0 1*/
    /* Update with different value 0x38 : 0011 1000 : Where 3 bit pattern is 1 1 1 */
    HWREGH((WD_BASE + SYSCTL_O_WDCR)) |= (uint16)WDG_CHKBITS_RESET;
}

/*
 * Design: MCAL-28561
 */
FUNC(uint16, WDG_CODE) Wdg_GetWatchdogCounterValue(void)
{
    /* Read and return the value of the watchdog counter. */
    return (HWREGH((WD_BASE + SYSCTL_O_WDCNTR)));
}

/*
 * Design: MCAL-28876
 */
FUNC(uint16, WDG_CODE)
Wdg_GetMaxTimeout(P2CONST(Wdg_DriverObjType, AUTOMATIC, WDG_APPL_DATA) Wdg_DrvObjPtr)
{
    VAR(uint16, AUTOMATIC) return_val = 0U;
    if (WDGIF_FAST_MODE == Wdg_DrvObjPtr->Wdg_PreviousMode)
    {
        return_val = Wdg_DrvObjPtr->Wdg_FastModeCfg.Timeout;
    }
    else if (WDGIF_SLOW_MODE == Wdg_DrvObjPtr->Wdg_PreviousMode)
    {
        return_val = Wdg_DrvObjPtr->Wdg_SlowModeCfg.Timeout;
    }
    else
    {
        /* Do nothing */
    }
    return return_val;
}

/*
 * Design: MCAL-28878
 */
FUNC(void, WDG_CODE) Wdg_SetTriggerConditionPriv(VAR(uint16, AUTOMATIC) Time_out)
{
    if (0U == Time_out)
    {
        uint16 current_wdg_cntr_value = Wdg_GetWatchdogCounterValue();

        /* In case the counter value stored inside watchdog has the value "255",
           the service Wdg_SetTriggerCondition shall do nothing */
        /* TI_COVERAGE_GAP_START [Branch Coverage] The false branch (counter == 255) cannot be covered
           by software testing. The watchdog counter (WDCNTR) is a hardware register that increments
           automatically based on the watchdog clock. To cover this branch, the test would need to call
           Wdg_SetTriggerCondition(0U) at the exact moment when the counter equals 255, which is
           infeasible to synchronize in software due to timing constraints and hardware behavior. */
        if (current_wdg_cntr_value != WDG_MAX_8BIT_CNTR_VALUE)
        /* TI_COVERAGE_GAP_STOP */
        {
            /* Write Bad key to generate immediate watchdog event */
            Wdg_GenerateImmediateEvent();
        }
    }
    else
    {
        /* Service Watchdog: Write Good Key */
        Wdg_ServiceWatchdog();
    }
}
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*
 * Design: MCAL-28562
 */
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogPredivider(VAR(Wdg_PreDivider, AUTOMATIC) predivider)
{
    VAR(uint16, AUTOMATIC) reg_val = (uint16)0U;

    reg_val = (uint16)predivider | (uint16)WDG_CHKBITS;

    /* Write the predivider to the appropriate register. */
    HWREGH((WD_BASE + SYSCTL_O_WDCR)) =
        (uint16)((uint16)(HWREGH((WD_BASE + SYSCTL_O_WDCR)) & (uint16)~SYSCTL_WDCR_WDPRECLKDIV_M) | reg_val);
}

/*
 * Design: MCAL-28563
 */
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogPrescaler(VAR(Wdg_PreScaler, AUTOMATIC) prescaler)
{
    VAR(uint16, AUTOMATIC) reg_val = (uint16)0U;

    reg_val = (uint16)prescaler | (uint16)WDG_CHKBITS;

    /* Write the prescaler to the appropriate register */
    HWREGH((WD_BASE + SYSCTL_O_WDCR)) =
        (uint16)((uint16)(HWREGH((WD_BASE + SYSCTL_O_WDCR)) & (uint16)~SYSCTL_WDCR_WDPS_M) | reg_val);
}

/*
 * Design: MCAL-28564
 */
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogWindowValue(VAR(uint16, AUTOMATIC) value)
{
    /* Clear the windowed value */
    HWREGH((WD_BASE + SYSCTL_O_WDWCR)) &= (uint16)~SYSCTL_WDWCR_MIN_M;

    /* Set the windowed value */
    HWREGH((WD_BASE + SYSCTL_O_WDWCR)) |= (uint16)(value & (uint16)SYSCTL_WDWCR_MIN_M);
}

/*
 * Design: MCAL-28565
 */
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogReaction(VAR(Wdg_Reaction, AUTOMATIC) reaction)
{
    /*  Either set or clear the WDENINT bit to that will determine whether the
        watchdog will generate a reset signal or an interrupt signal. Take care
        not to write a 1 to WDOVERRIDE. */

    if (reaction == WDG_GENERATE_INTERRUPT)
    {
        HWREGH((WD_BASE + SYSCTL_O_SCSR)) =
            (uint16)((HWREGH((WD_BASE + SYSCTL_O_SCSR)) & (uint16)~SYSCTL_SCSR_WDOVERRIDE) | SYSCTL_SCSR_WDENINT);
    }
    else
    {
        HWREGH((WD_BASE + SYSCTL_O_SCSR)) &= (uint16) ~(SYSCTL_SCSR_WDENINT | SYSCTL_SCSR_WDOVERRIDE);
    }
}

/*
 * Design: MCAL-28566
 */
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_IsWatchdogInterruptActive(void)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

    /* If the status bit is cleared, the WDINTn signal is active.*/
    if ((HWREGH((WD_BASE + SYSCTL_O_SCSR)) & SYSCTL_SCSR_WDINTS) == 0U)
    {
        status = TRUE;
    }

    return status;
}

/*
 * Design: MCAL-28567
 */
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_CheckReactionParam(VAR(Wdg_Reaction, AUTOMATIC) reaction)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

    /* reset or Interrupt reaction*/
    if ((reaction == WDG_GENERATE_RESET) || (reaction == WDG_GENERATE_INTERRUPT))
    {
        /* Valid Parameters */
        status = TRUE;
    }
    return status;
}

/*
 * Design: MCAL-28568
 */
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_CheckPrescalerParam(VAR(Wdg_PreScaler, AUTOMATIC) prescaler)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

    /* range within PRESCALE_1 and PRESCALE_64 */
    if ((prescaler >= WDG_PRESCALE_1) && (prescaler <= WDG_PRESCALE_64))
    {
        /* Valid Parameters */
        status = TRUE;
    }
    return status;
}

/*
 * Design: MCAL-28569
 */
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_CheckPredividerParam(VAR(Wdg_PreDivider, AUTOMATIC) predivider)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

    if ((predivider == WDG_PREDIV_2) || (predivider == WDG_PREDIV_4) || (predivider == WDG_PREDIV_8) ||
        (predivider == WDG_PREDIV_16) || (predivider == WDG_PREDIV_32) || (predivider == WDG_PREDIV_64) ||
        (predivider == WDG_PREDIV_128) || (predivider == WDG_PREDIV_256) || (predivider == WDG_PREDIV_512) ||
        (predivider == WDG_PREDIV_1024) || (predivider == WDG_PREDIV_2048) || (predivider == WDG_PREDIV_4096))
    {
        /* Valid Parameters */
        status = TRUE;
    }
    return status;
}

/*
 * Design: MCAL-28570
 */
LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_CheckThresholdParam(VAR(uint16, AUTOMATIC) threshold)
{
    VAR(boolean, AUTOMATIC) status = FALSE;

    /* 0-255 range */
    if (threshold <= WDG_MAX_THRESHOLD_VALUE)
    {
        /* Valid Parameters */
        status = TRUE;
    }
    return status;
}

/*
 * Design: MCAL-28571
 */
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE)
    Wdg_CheckConfigParameterRange(P2CONST(Wdg_ModeInfoType, AUTOMATIC, WDG_APPL_DATA) ModeCfg)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = (Std_ReturnType)E_NOT_OK;

    /* check if reaction type, Prescaler, Predivider and threshold values are valid or not */
    if (((boolean)TRUE == (boolean)Wdg_CheckReactionParam(ModeCfg->Reaction)) &&
        ((boolean)TRUE == (boolean)Wdg_CheckPrescalerParam(ModeCfg->PreScaler)) &&
        ((boolean)TRUE == (boolean)Wdg_CheckPredividerParam(ModeCfg->PreDivider)) &&
        ((boolean)TRUE == (boolean)Wdg_CheckThresholdParam(ModeCfg->Threshold)))
    {
        ret_val = (Std_ReturnType)E_OK;
    }

    return ret_val;
}

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Wdg_Priv.c
 *********************************************************************************************************************/
