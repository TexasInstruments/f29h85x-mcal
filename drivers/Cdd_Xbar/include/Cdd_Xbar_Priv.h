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
 *  File:        Cdd_Xbar_Priv.h
 *  Generator:   None
 *
 *  Description: Private header file for CDD XBar IP related source
 *********************************************************************************************************************/

#ifndef CDD_XBAR_PRIV_H
#define CDD_XBAR_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_input_xbar.h"
#include "hw_output_xbar.h"
#include "hw_epwm_xbar.h"
#include "hw_clb_xbar.h"
#include "hw_mdl_xbar.h"
#include "hw_icl_xbar.h"
#include "hw_xbar.h"
#include "hw_xint.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** \brief Bit corresponding to the locking in the lock register */
#define CDD_XBAR_LOCK_BIT 1U
/** \brief Shift value for lock key */
#define CDD_XBAR_LOCK_KEY_SHIFT 16U
/** \brief Key for locking */
#define CDD_XBAR_LOCK_KEY 0x5A5A
/** \brief Offset value for output Xbar flag registers  */
#define XBAR_OUTPUTXBAR_FLAGS_OFFSET 0x1000U

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/** \brief CDD XBAR initialization status */
typedef enum
{
    /** \brief Driver in uninitialized state */
    CDD_XBAR_UNINIT = 0U,
    /** \brief Driver in init state */
    CDD_XBAR_INIT = 1U,
    /** \brief Complete driver instances in lock state */
    CDD_XBAR_LOCK = 2U,
} Cdd_Xbar_StatusType;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-25761 */
/** \brief Selects input crossbar input
 *
 * Function to select a GPIO or Logic High (1) / Low (0) as input to input crossbar.
 *
 * \param[in] InputSelect is the pointer to INPUT XBAR input select.
 * \param[in] InputLine is the pointer to INPUT XBAR input line.
 * \param[in] Selection is the selection updation for the identified inputs.
 * \pre Input crossbar select line should not be in locked state.
 * \post None
 * \return Status of selection.
 * \retval E_OK if input selected successfully.
 * \retval E_NOT_OK if input selection failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_InSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) InputSelect,
                  P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-25767 */
/** \brief Locks input crossbar select line.
 *
 * Function to lock an unlocked input crossbar select. Locking prevents further input selection
 *updation. Once locked, will remain locked unless system reset.
 *
 * \param[in] InputSelect is the pointer to INPUT XBAR input select.
 * \pre Input crossbar select line should not be in locked state.
 * \post None
 * \return Status of locking input select line.
 * \retval E_OK if locked successfully.
 * \retval E_NOT_OK if locking failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_InSelectLock(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) InputSelect);

/* Design: MCAL-25768 */
/** \brief Returns input crossbar select line lock status.
 *
 * Function to get the lock status of an input select line.
 *
 * \param[in] InputSelect is the pointer to INPUT XBAR input select.
 * \pre None
 * \post None
 * \return Current input select lock enablement status.
 * \retval TRUE if locked.
 * \retval FALSE if not locked.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_InSelectLockStatus(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) InputSelect);

/** \brief Sets external interrupt type
 *
 * Function to set the interrupt type (edge polarity) for an external interrupt.
 *
 * \param[in] ExtIntNum is the the external interrupt number.
 * \param[in] IntType is the the interrupt type (edge polarity).
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_SetIntrType(VAR(Cdd_Xbar_ExternalIntNum, AUTOMATIC) ExtIntNum, VAR(Cdd_Xbar_IntType, AUTOMATIC) IntType);

/** \brief Enables or disables external interrupt
 *
 * Function to enable or disable an external interrupt.
 *
 * \param[in] ExtIntNum is the external interrupt number.
 * \param[in] Enable enables or disables the external interrupt.
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_EnableIntr(VAR(Cdd_Xbar_ExternalIntNum, AUTOMATIC) ExtIntNum, VAR(boolean, AUTOMATIC) Enable);

/** \brief Gets external interrupt counter value
 *
 * Function to read the counter value for an external interrupt.
 * Only XINT1, XINT2, and XINT3 have counter registers.
 *
 * \param[in] ExtIntNum is the external interrupt number (XINT1, XINT2, or
 *XINT3).
 * \pre None
 * \post None
 * \return Counter value for the specified external interrupt.
 *
 *********************************************************************************************************************/
FUNC(uint16, CDD_XBAR_CODE)
Cdd_Xbar_GetIntrCounter(VAR(Cdd_Xbar_ExternalIntNum, AUTOMATIC) ExtIntNum);
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

/* Design: MCAL-25769 */
/** \brief Returns output crossbar lock status.
 *
 * Function to check lock status of output crossbar.
 *
 * \pre None
 * \post None
 * \return Current lock status of output crossbar.
 * \retval TRUE if locked.
 * \retval FALSE if not locked.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLockStatus(void);

/* Design: MCAL-25770 */
/** \brief Locks output crossbar.
 *
 * Function to entirely Lock all output crossbar units. Locking impacts input
 * line selection updation and output inversion. Once locked, it cannot be
 * unlocked unless system reset.
 *
 * \pre Output crossbar should not be in locked state.
 * \post None
 * \return Status of locking.
 * \retval E_OK if locked successfully.
 * \retval E_NOT_OK if locking failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_OutLock(void);

/* Design: MCAL-25762 */
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/** \brief Selects output crossbar input.
 *
 * Function to select or deselect a chosen input of the output crossbar according to the Selection.
 *
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \param[in] InputLine is the pointer to OUTPUT XBAR input line.
 * \param[in] Selection TRUE : select an input, FALSE : deselect an input.
 * \pre Output crossbar should not be in locked state.
 * \post None
 * \return Status of selection.
 * \retval E_OK if selected successfully.
 * \retval E_NOT_OK if selection failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                   P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-25772 */
/** \brief Invert/Uninvert the output crossbar output.
 *
 * Function to invert or uninvert a chosen output of the output crossbar according to the Selection.
 *
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \param[in] Selection TRUE : Inverts the output, FALSE : Uninvert the output.
 * \pre Output crossbar should not be in locked state.
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                         P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection);

/* Design: MCAL-25771 */
/** \brief Returns output crossbar output inversion status.
 *
 * Function to check inversion for an output of the given output crossbar.
 *
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \pre None
 * \post None
 * \return Status of Inversion.
 * \retval TRUE if inverted.
 * \retval FALSE if uninverted.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);

/* Design: MCAL-25773 */
/** \brief Returns status of output crossbar output inversion before latch.
 *
 * Function to check inversion before latching for an output of the given output crossbar.
 *
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \pre None
 * \post None
 * \return Status of inversion set before latch.
 * \retval TRUE if inverted.
 * \retval FALSE if uninverted.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutputInvLatchSts(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);

/* Design: MCAL-25775 */
/** \brief Selects/deselects the latch as the output crossbar output.
 *
 * Function to select or deselect the output latch to drive an output of the Output Crossbar unit.
 *
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \param[in] Selection TRUE : Latched event selected as output, FALSE : Latched event not selected
 *as output.
 * \pre Driver should be in initialized state.
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                           P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection);

/* Design: MCAL-25774*/
/** \brief Returns the status of selecting latch as output of output crossbar .
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \pre None
 * \post None
 * \return Enablement status of setting latched event as output.
 * \retval TRUE if latched event selected as output.
 * \retval FALSE if latch event not selected as output.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchSelectSts(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);

/* Design: MCAL-28156 */
/** \brief Returns the status of output latch of the given output of Output Crossbar.
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \param[in] OutputXbarFlagBaseAddress is the pointer to the OUTPUT XBAR flag base address.
 * \pre None
 * \post None
 * \return Output latch status.
 * \retval TRUE if latched output.
 * \retval FALSE if no input latched output.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchFlagStatus(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                               P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) OutputXbarFlagBaseAddress);

/* Design: MCAL-28157 */
/** \brief Forces the output latch of the given output of Output Crossbar.
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \param[in] OutputXbarFlagBaseAddress is the pointer to the OUTPUT XBAR flag base address.
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchFlagForce(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                              P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) OutputXbarFlagBaseAddress);

/* Design: MCAL-28158 */
/** \brief Clears the output latch of the given output of Output Crossbar.
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \param[in] OutputXbarFlagBaseAddress is the pointer to the OUTPUT XBAR flag base address.
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputLatchFlagClear(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                              P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) OutputXbarFlagBaseAddress);

/* Design: MCAL-28155 */
/** \brief Inverts and restores output inversion before latch for a chosen output XBAR output.
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line to be inverted before latch.
 * \param[in] Selection TRUE : invert, FALSE : uninvert.
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputInvLatch(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                        P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection);

/* Design: MCAL-25776 */
/** \brief Stretch or unstretch an output of output crossbar.
 *
 * Function to stretch or unstretch a chosen output line of the output crossbar unit.
 * Ticks for unstretching = CDD_XBAR_SYSTICKS_STRETCH_OFF.
 *
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \param[in] Ticks Ticks to stretch.
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_OutputStretchPulse(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                            P2CONST(Cdd_Xbar_TickStretchType, AUTOMATIC, CDD_XBAR_CONST) Ticks);

/* Design: MCAL-25777 */
/** \brief Returns the status of output stretch on an output of the output crossbar.
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \pre None
 * \post None
 * \return Output Stretch or Unstretch.
 * \retval TRUE if stretch is enabled.
 * \retval FALSE if stretch is not enabled.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_OutputStretchOrNot(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);

/* Design: MCAL-25778 */
/** \brief Returns the output stretch on an output of an output crossbar.
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \pre None
 * \post None
 * \return Output stretch in system clock ticks.
 * \retval CDD_XBAR_SYSTICKS_16 or CDD_XBAR_SYSTICKS_32  if stretch selected.
 * \retval CDD_XBAR_SYSTICKS_STRETCH_OFF if stretch not selected.
 *
 *********************************************************************************************************************/
FUNC(Cdd_Xbar_TickStretchType, CDD_XBAR_CODE)
Cdd_Xbar_OutputStretchGet(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);

/* Design: MCAL-25779 */
/** \brief Returns the output signal state on output crossbar output.
 *
 * Function to check output signal state as either Low (0) or High (1) status on
 * an output of the Output Crossbar.
 *
 * \param[in] OutputLine is the pointer to the OUTPUT XBAR output line.
 * \param[in] OutputXbarFlagBaseAddress is the pointer to the OUTPUT XBAR flag base address.
 * \pre None
 * \post None
 * \return Output polarity.
 * \retval STD_HIGH if Logic High (1).
 * \retval STD_LOW if Logic Low (0).
 *
 *********************************************************************************************************************/
FUNC(Cdd_Xbar_OutputlevelType, CDD_XBAR_CODE)
Cdd_Xbar_OutOutputState(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                        P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) OutputXbarFlagBaseAddress);
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/

/* Design: MCAL-25784 */
/** \brief Returns CLB crossbar lock status.
 * \pre None
 * \post None
 * \return CLB Crossbar Lock status.
 * \retval TRUE if locked.
 * \retval FALSE if not locked.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_ClbLockStatus(void);

/* Design: MCAL-25785 */
/** \brief Locks CLB crossbar.
 *
 * Function to entirely Lock all CLB Crossbar units. Locking prevents input
 * line selection updation and output inversion. Once locked, it cannot be
 * unlocked unless system reset.
 *
 * \pre CLB crossbar should not be in locked state.
 * \post None
 * \return CLB crossbar locking status.
 * \retval E_OK if locked successfully.
 * \retval E_NOT_OK if locking failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_ClbLock(void);

/* Design: MCAL-25764 */
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/** \brief Selects CLB crossbar input.
 *
 * Function to select or deselect an input of the CLB crossbar unit according to the Selection.
 *
 * \param[in] OutputLine is the pointer to the CLB XBAR output line.
 * \param[in] InputLine is the pointer to the CLB XBAR input line.
 * \param[in] Selection TRUE : Select an input, FALSE : Deselect an input.
 * \pre CLB Crossbar should not be in locked state.
 * \post None
 * \return Status of input selection.
 * \retval E_OK if selection is successful.
 * \retval E_NOT_OK if selection failed.
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_ClbSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                   P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-25787 */
/** \brief Invert/Uninvert the CLB crossbar output.
 *
 * Function to invert or uninvert an output of the CLB crossbar according to the Selection.
 *
 * \param[in] OutputLine is the pointer to the CLB XBAR output line.
 * \param[in] Selection TRUE : Invert an output, FALSE : Uninverts an output.
 * \pre CLB Crossbar should not be in locked state.
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_ClbOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                         P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection);

/* Design: MCAL-25786 */
/** \brief Returns inversion status of CLB crossbar output .
 *
 * Function to check inversion status of an output of the CLB Crossbar.
 *
 * \param[in] OutputLine is the pointer to the CLB XBAR output line.
 * \pre None
 * \post None
 * \return Output Inversion.
 * \retval TRUE if inverted.
 * \retval FALSE if not inverted.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_ClbOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/

/* Design: MCAL-25780 */
/** \brief Returns EPWM crossbar lock status.
 * \pre None
 * \post None
 * \return EPWM crossbar lock status.
 * \retval TRUE if locked.
 * \retval FALSE if not locked.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_EpwmLockStatus(void);

/* Design: MCAL-25781 */
/** \brief Locks EPWM crossbar.
 *
 * Function to entirely Lock all EPWM Crossbar units. Locking prevents input
 * line selection updation and output inversion. Once locked, it cannot be
 * unlocked unless system reset.
 *
 * \pre EPWM crossbar should not be in locked state.
 * \post None
 * \return EPWM crossbar locking status.
 * \retval E_OK if locked succesfully.
 * \retval E_NOT_OK if locking failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_EpwmLock(void);

/* Design: MCAL-25763 */
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/** \brief Selects EPWM crossbar input.
 *
 * Function to select or deselect an input of the EPWM crossbar unit according to the Selection.
 *
 * \param[in] OutputLine is the pointer to the EPWM XBAR output line.
 * \param[in] InputLine is the pointer to the EPWM XBAR input line.
 * \param[in] Selection TRUE : Select an input, FALSE : Deselect an input.
 * \pre EPWM crossbar should not be in locked state.
 * \post None
 * \return Input selection status.
 * \retval E_OK if selection is successful.
 * \retval E_NOT_OK if selection failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_EpwmSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                    P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-25783 */
/** \brief Inverts EPWM crossbar output.
 *
 * Function to invert or uninvert an output of the EPWM crossbar according to the Selection.
 *
 * \param[in] OutputLine is the pointer to the EPWM XBAR output line.
 * \param[in] Selection TRUE : Invert an output, FALSE : Uninvert an output.
 * \pre EPWM crossbar should not be in locked state.
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_EpwmOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                          P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection);

/* Design: MCAL-25782 */
/** \brief Returns EPWM crossbar output inversion status.
 *
 * Function to check inversion on an output of the EPWM crossbar.
 *
 * \param[in] OutputLine is the pointer to the EPWM XBAR output line.
 * \pre None
 * \post None
 * \return Output inversion status.
 * \retval TRUE if inverted successfully.
 * \retval FALSE if invertion failed.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_EpwmOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/

/* Design: MCAL-25788 */
/** \brief Returns lock status of MINDB crossbar.
 * \pre None
 * \post None
 * \return MINDB Crossbar lock status.
 * \retval TRUE if locked.
 * \retval FALSE if not locked.
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_MdlLockStatus(void);

/* Design: MCAL-25789 */
/** \brief Locks MINDB Crossbar
 *
 * Function to entirely Lock all MINDB Crossbar units. Locking prevents input
 * line selection updation and output inversion. Once locked, it cannot be
 * unlocked unless system reset.
 *
 * \pre MINDB crossbar should not be in locked state.
 * \post None
 * \return MINDB crossbar locking status.
 * \retval E_OK if locked succesfully.
 * \retval E_NOT_OK if locking failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_MdlLock(void);

/* Design: MCAL-25765 */
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/** \brief Selects MINDB Crossbar Input.
 *
 * Function to select or deselect an input line of the MINDB Crossbar.
 *
 * \param[in] OutputLine is the pointer to the MINDB XBAR output line.
 * \param[in] InputLine is the pointer to the MINDB XBAR input line.
 * \param[in] Selection  TRUE : Select an input, FALSE : Deselect an input.
 * \pre MINDB crossbar should not be in locked state.
 * \post None
 * \return Input selection status.
 * \retval E_OK if selection is successful.
 * \retval E_NOT_OK if selection failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_MdlSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                   P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-25791 */
/** \brief Inverts MINDB crossbar output.
 *
 * Function to invert or uninvert an output of the MINDB Crossbar according to the Selection.
 *
 * \param[in] OutputLine is the pointer to the MINDB XBAR output line.
 * \param[in] Selection TRUE : Invert an input, FALSE : Uninvert an input.
 * \pre MINDB crossbar should not be in locked state.
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_MdlOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                         P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection);

/* Design: MCAL-25790 */
/** \brief Returns MINDB crossbar output inversion status.
 *
 * Function to check inversion on an output of the MINDB Crossbar.
 *
 * \param[in] OutputLine is the pointer to the MINDB XBAR output line.
 * \return Output inversion status.
 * \retval TRUE if inverted.
 * \retval FALSE if not inverted.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_MdlOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/

/* Design: MCAL-25792 */
/** \brief Returns lock status of ICL crossbar.
 * \pre None
 * \post None
 * \return ICL crossbar lock status.
 * \retval TRUE if locked.
 * \retval FALSE if not locked.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_IclLockStatus(void);

/* Design: MCAL-25793 */
/** \brief Locks ICL crossbar.
 *
 * Function to entirely Lock all ICL Crossbar units. Locking prevents input
 * line selection updation and output inversion. Once locked, it cannot be
 * unlocked unless system reset.
 *
 * \pre ICL crossbar should not be in locked state.
 * \post None
 * \return ICL crossbar locking status.
 * \retval E_OK if locked succesfully.
 * \retval E_NOT_OK if locking failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_IclLock(void);

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
/* Design: MCAL-25766 */
/** \brief Selects ICL crossbar input
 *
 * Function to select or deselect an input line of the ICL Crossbar unit.
 *
 * \param[in] OutputLine is the pointer to the ICL XBAR output line.
 * \param[in] InputLine is the pointer to the ICL XBAR input line.
 * \param[in] Selection  TRUE : Select an input, FALSE : Deselect an input.
 * \pre ICL crossbar should not be in locked state.
 * \post None
 * \return Input selection status.
 * \retval E_OK if selection is successful.
 * \retval E_NOT_OK if selection failed.
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_IclSelect(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                   P2CONST(uint16, AUTOMATIC, CDD_XBAR_CONST) InputLine, VAR(boolean, AUTOMATIC) Selection);

/* Design: MCAL-25795 */
/** \brief Inverts ICL Crossbar Output.
 *
 * Function to invert or uninvert an output of the ICL Crossbar.
 *
 * \param[in] OutputLine is the pointer to the ICL XBAR output line.
 * \param[in] Selection TRUE : Invert an input, FALSE : Uninvert an input.
 * \pre ICL Crossbar should not be in locked state.
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_IclOutputInvert(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine,
                         P2CONST(boolean, AUTOMATIC, CDD_XBAR_CONST) Selection);

/* Design: MCAL-25794 */
/** \brief Returns ICL Crossbar Output Inversion status.
 * Function to check inversion on an output line of the ICL Crossbar.
 *
 * \param[in] OutputLine is the pointer to the ICL XBAR output line.
 * \pre None
 * \post None
 * \return Output inversion status.
 * \retval TRUE if inverted.
 * \retval FALSE if not inverted.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_IclOutputInvertCheck(P2CONST(uint8, AUTOMATIC, CDD_XBAR_CONST) OutputLine);
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/

#if (STD_ON == CDD_XBAR_INPUT_FLAG_API)
/* Design: MCAL-28160 */
/** \brief Clears a crossbar input flag.
 * \param[in] InputFlag is a crossbar input flag.
 * \param[in] InputFlagBaseAddress is the pointer to the XBAR input flag base address.
 * \pre none
 * \post None
 * \return None
 *********************************************************************************************************************/
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_InFlagClear(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag,
                     P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) InputFlagBaseAddress);

/* Design: MCAL-28159 */
/** \brief Returns the status of a crossbar input flag.
 * \param[in] InputFlag is a crossbar input flag.
 * \param[in] InputFlagBaseAddress is the pointer to the XBAR input flag base address.
 * \pre None
 * \post None
 * \return Status of the crossbar input flag.
 * \retval TRUE if input was triggered.
 * \retval FALSE if input was not triggered.
 *
 *********************************************************************************************************************/
FUNC(boolean, CDD_XBAR_CODE)
Cdd_Xbar_InFlagStatus(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag,
                      P2CONST(uint32, AUTOMATIC, CDD_XBAR_CONST) InputFlagBaseAddress);
#endif /* STD_ON == CDD_XBAR_INPUT_FLAG_API */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

#ifdef __cplusplus
}
#endif
#endif /* CDD_XBAR_PRIV_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Priv.h
 *********************************************************************************************************************/
