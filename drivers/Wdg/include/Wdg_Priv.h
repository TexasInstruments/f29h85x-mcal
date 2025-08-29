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
 *  File:       Wdg_Priv.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Wdg private functions
 *********************************************************************************************************************/
#ifndef WDG_PRIV_H
#define WDG_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Wdg.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_sysctl.h"
#include "Mcal_Lib_Cpu.h"
#include "Mcal_Lib.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/*
 * Design: MCAL-25306, MCAL-25307, MCAL-25311
 */
/** \brief Shifted pattern for WDCR register's WDCHK field. */
#define WDG_CHKBITS (0x0028U)
/** \brief Keys for WDKEY field. This key is to enable reset. */
#define WDG_ENRSTKEY (0x0055U) /* */
/** \brief Keys for WDKEY field. This key is to reset . */
#define WDG_RSTKEY (0x00AAU) /* */
/** \brief Reset pattern for WDCR register's WDCHK field. */
#define WDG_CHKBITS_RESET (0x0038U)
/** \brief Maximum 8 bit counter value. */
#define WDG_MAX_8BIT_CNTR_VALUE (255U)

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

/** \brief Initialize the configuration settings
 *
 * \param[in] ConfigPtr pointer to the Watchdog configuration
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, WDG_CODE)
Wdg_PlatformInit(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_DATA) ConfigPtr);

/** \brief Sets the requested Mode configuration settings into Watchdog registers
 *
 * \param[in] ModeCfg pointer to the Watchdog Mode settings
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, WDG_CODE)
Wdg_SetModeConfig(P2CONST(Wdg_ModeInfoType, AUTOMATIC, WDG_APPL_DATA) ModeCfg);

/** \brief Enables the watchdog.
 *
 * This function enables the watchdog timer.
 *
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, WDG_CODE) Wdg_EnableWatchdog(void);

/** \brief Disables the watchdog.
 *
 * This function disables the watchdog timer.
 *
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, WDG_CODE) Wdg_DisableWatchdog(void);

/** \brief Services the watchdog.
 *
 * This function resets the watchdog counter
 *
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, WDG_CODE) Wdg_ServiceWatchdog(void);

/** \brief Generates the immediate watchdog reset/interrupt
 *
 * This function generates the immediate watchdog event
 *
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, WDG_CODE) Wdg_GenerateImmediateEvent(void);

/** \brief Gets the watchdog counter value.
 *
 *  \post None
 * \return Returns the current value of the 8-bit watchdog counter.
 * \retval Wdg counter value
 *
 *********************************************************************************************************************/
FUNC(uint16, WDG_CODE) Wdg_GetWatchdogCounterValue(void);

/** \brief Gets the watchdog Maximum Timeout value.
 *
 * \param[in] Wdg_DrvObjPtr pointer to the Watchdog Driver Object which is initialised in Wdg.c
 *  \post None
 * \return Returns the Watchdog Maximum Timeout Value.
 * \retval Wdg Maximum Timeout value
 *
 *********************************************************************************************************************/
FUNC(uint16, WDG_CODE)
Wdg_GetMaxTimeout(P2CONST(Wdg_DriverObjType, AUTOMATIC, WDG_APPL_DATA) Wdg_DrvObjPtr);

/** \brief Sets the timeout value for the trigger counter
 *
 * \param[in] Time_out Time_out value (milliseconds) for setting the trigger counter
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, WDG_CODE) Wdg_SetTriggerConditionPriv(VAR(uint16, AUTOMATIC) Time_out);
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
extern "C"
}
#endif
#endif /* WDG_PRIV_H */
/*********************************************************************************************************************
 *  End of File: Wdg_Priv.h
 *********************************************************************************************************************/
