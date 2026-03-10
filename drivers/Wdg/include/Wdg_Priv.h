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
