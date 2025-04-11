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


/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25294
 */
FUNC(Std_ReturnType, WDG_CODE) Wdg_PlatformInit(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_DATA) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = (Std_ReturnType) E_OK;
    P2CONST(Wdg_ModeInfoType, AUTOMATIC, WDG_APPL_CONST) mode_cfg = NULL_PTR;

    /* Assign the Default mode configuration settings */
    if(ConfigPtr->Wdg_DefaultMode == WDGIF_FAST_MODE)
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
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetModeConfig(P2CONST(Wdg_ModeInfoType, AUTOMATIC, WDG_APPL_DATA) ModeCfg)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = (Std_ReturnType) E_OK;

    /* Write the Pre-divider value into register */
    Wdg_SetWatchdogPredivider(ModeCfg->PreDivider);

    /* Write the Pre-scaler value into register */
    Wdg_SetWatchdogPrescaler(ModeCfg->PreScaler);

    if ((boolean) Wdg_IsWatchdogInterruptActive() == (boolean) FALSE)
    {
        /* Write the Reaction type into register */
        Wdg_SetWatchdogReaction(ModeCfg->Reaction);
    }

    /* Check the threshold limit ranges */
    if (ModeCfg->Threshold  > WDG_MAX_THRESHOLD_VALUE)
    {
        /* If value is not within range, return the error*/
        ret_val = (Std_ReturnType) E_NOT_OK;
    }
    else
    {       
        /* Write the Windowed Minimum Threshold value into register */
        Wdg_SetWatchdogWindowValue(ModeCfg->Threshold);
    }

    /* Delay of at least 69 OSCCLK cycles required */
    McalLib_Delay((uint32)14U);

    return ret_val;
}


FUNC(void, WDG_CODE) Wdg_EnableWatchdog(void)
{
    /* Clear the disable bit */
    HWREGH(WD_BASE + SYSCTL_O_WDCR) = (uint16)((HWREGH(WD_BASE + SYSCTL_O_WDCR) &
                                       ~(uint16)SYSCTL_WDCR_WDDIS) | WDG_CHKBITS);
}


FUNC(void, WDG_CODE) Wdg_DisableWatchdog(void)
{
     /* Set the disable bit */
    HWREGH(WD_BASE + SYSCTL_O_WDCR) |= (uint16)(WDG_CHKBITS | SYSCTL_WDCR_WDDIS);
}


FUNC(void, WDG_CODE) Wdg_ServiceWatchdog(void)
{
    /* Enable the counter to be reset and then reset it */
    HWREGH(WD_BASE + SYSCTL_O_WDKEY) = (uint16)WDG_ENRSTKEY;
    HWREGH(WD_BASE + SYSCTL_O_WDKEY) = (uint16)WDG_RSTKEY;
}


FUNC(void, WDG_CODE) Wdg_GenerateImmediateEvent(void)
{
    /* Write the WDCHK(3 bit field) value other than "1 0 1" in to WDCR register */
    /* By Default WDG_CHKBITS the 3 bit value it is set to 0x28 : 0010 1000 : Where 3 bit pattern is 1 0 1*/
    /* Update with different value 0x38 : 0011 1000 : Where 3 bit pattern is 1 1 1 */
    HWREGH(WD_BASE + SYSCTL_O_WDCR) |= (uint16)WDG_CHKBITS_RESET ;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogPredivider(VAR(Wdg_PreDivider, AUTOMATIC) predivider)
{
    VAR(uint16, AUTOMATIC) reg_val = (uint16) 0U;

    reg_val = (uint16)predivider | (uint16)WDG_CHKBITS;

    /* Write the predivider to the appropriate register. */
    HWREGH(WD_BASE + SYSCTL_O_WDCR) = (uint16)((uint16)(HWREGH(WD_BASE + SYSCTL_O_WDCR) & \
                                       ~(uint16)(SYSCTL_WDCR_WDPRECLKDIV_M)) | reg_val);
}


LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogPrescaler(VAR(Wdg_PreScaler, AUTOMATIC) prescaler)
{
    VAR(uint16, AUTOMATIC) reg_val = (uint16) 0U;

    reg_val = (uint16)prescaler | (uint16)WDG_CHKBITS;

    /* Write the prescaler to the appropriate register */
    HWREGH(WD_BASE + SYSCTL_O_WDCR) = (uint16)((uint16)(HWREGH(WD_BASE + SYSCTL_O_WDCR) & \
                                       ~(uint16)(SYSCTL_WDCR_WDPS_M)) | reg_val);
}


LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogWindowValue(VAR(uint16, AUTOMATIC) value)
{
    /* Clear the windowed value */
    HWREGH(WD_BASE + SYSCTL_O_WDWCR) &= ~(uint16)SYSCTL_WDWCR_MIN_M;

    /* Set the windowed value */
    HWREGH(WD_BASE + SYSCTL_O_WDWCR) |= (uint16)(value & (uint16)SYSCTL_WDWCR_MIN_M);
}


LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_SetWatchdogReaction(VAR(Wdg_Reaction, AUTOMATIC) reaction)
{
    /*  Either set or clear the WDENINT bit to that will determine whether the
        watchdog will generate a reset signal or an interrupt signal. Take care
        not to write a 1 to WDOVERRIDE. */

    if(reaction == WDG_GENERATE_INTERRUPT)
    {
        HWREGH(WD_BASE + SYSCTL_O_SCSR) = \
                (uint16)((HWREGH(WD_BASE + SYSCTL_O_SCSR) & ~(uint16)SYSCTL_SCSR_WDOVERRIDE) | \
                SYSCTL_SCSR_WDENINT);
    }
    else
    {
        HWREGH(WD_BASE + SYSCTL_O_SCSR) &= ~(uint16)(SYSCTL_SCSR_WDENINT | \
                                            SYSCTL_SCSR_WDOVERRIDE);
    }

}


LOCAL_INLINE FUNC(boolean, WDG_CODE) Wdg_IsWatchdogInterruptActive(void)
{
    /* If the status bit is cleared, the WDINTn signal is active.*/
    return ((HWREGH(WD_BASE + SYSCTL_O_SCSR) & SYSCTL_SCSR_WDINTS) == 0U);
}


#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"
 
/*********************************************************************************************************************
 *  End of File: Wdg_Priv.c
 *********************************************************************************************************************/
