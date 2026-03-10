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
 *  File:       Mcal_Lib.h
 *  Generator:  None
 *
 *  Description:  Interface header file for library functions used by MCALs / CDDs
 *********************************************************************************************************************/
#ifndef MCAL_LIB_H
#define MCAL_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcal_Lib_Cpu.h"
#include "hw_ipc.h"
#include "hw_memmap.h"
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

#define MCAL_LIB_SW_MAJOR_VERSION (1U) /* Driver Implementation Major Version. */
#define MCAL_LIB_SW_MINOR_VERSION (0U) /* Driver Implementation Minor Version. */
#define MCAL_LIB_SW_PATCH_VERSION (0U) /* Driver Implementation Patch Version. */

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

#define MCAL_LIB_MAX_TICK_VALUE (0x4189374BC6A7EFU) /* Uint64_MAX/1000 */
/* Default Sysclock value is set to a higher frequency to ensure that the no under-delay occurs if Mcu is not
 * initialized */
#define MCAL_LIB_DEFAULT_SYSCLK_HZ (200000000U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Type definition for timer tick values
 *
 * This type represents the tick count value used for timing and counter operations using the counter in IPC.
 * It is defined as a 64-bit unsigned integer as IPC counter is 64 bit.
 */
typedef uint64 McalLib_TickType;
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Delays for a fixed number of cycles.
 *
 * This function generates a constant length delay using assembly code. The loop takes 4 cycles per
 * iteration plus 11 cycles of overhead.
 *
 * \param[in] count The number of delay loop iterations to perform.
 *                  If count is equal to zero, the loop will underflow and run for a very long time.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
extern FUNC(void, MCAL_LIB_CODE) McalLib_Delay(VAR(uint32, MCAL_LIB_DATA) count);

/** \brief Delay function in microseconds.
 *
 * \param[in] delayUsec Number of microseconds of delay
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
extern FUNC(void, MCAL_LIB_CODE) McalLib_DelayUsec(VAR(McalLib_TickType, MCAL_LIB_DATA) delayUsec);

/** \brief Delay function in milliseconds.
 *
 * \param[in] delayMsec Number of milliseconds of delay
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
extern FUNC(void, MCAL_LIB_CODE) McalLib_DelayMsec(VAR(McalLib_TickType, MCAL_LIB_DATA) delayMsec);

/** \brief This function reads IPC free run timer (64-bit value) and update startTime param
 *
 * \param[out] startTime pointer to store IPC timer value
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
extern FUNC(void, MCAL_LIB_CODE) McalLib_GetCounterValue(P2VAR(McalLib_TickType, AUTOMATIC, MCAL_LIB_DATA) startTime);

/** \brief This function reads the elapsed value in timer ticks of IPC free run counter(running at
 *sysclock frequency) with respect startTime param.
 *
 * \param[in] startTime pointer which has timer reference value
 * \param[out] elapsedTime pointer in which elapsed value in number of timer ticks is updated
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
extern FUNC(void, MCAL_LIB_CODE)
    McalLib_GetElapsedValue(CONSTP2VAR(McalLib_TickType, AUTOMATIC, MCAL_LIB_DATA) startTime,
                            P2VAR(McalLib_TickType, AUTOMATIC, MCAL_LIB_DATA) elapsedTime);

/** \brief This function provide the number of timer ticks (running at sysclock frequency)
 * with respect to the timeout required.
 *
 * \param[in] timeOutInUs Number of microseconds of timeout
 * \param[out] tickCounter pointer in which the number of timer ticks is updated
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK : Tickvalue calculation successful
 * \retval E_NOT_OK : Tickvalue calculation failed
 ******************************************************************************/
extern FUNC(Std_ReturnType, MCAL_LIB_CODE)
    McalLib_GetTimerTickFromUs(McalLib_TickType timeOutInUs,
                               P2VAR(McalLib_TickType, AUTOMATIC, MCAL_LIB_DATA) tickCounter);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MCAL_LIB_H */
/*********************************************************************************************************************
 *  End of File: Mcal_Lib.h
 *********************************************************************************************************************/
