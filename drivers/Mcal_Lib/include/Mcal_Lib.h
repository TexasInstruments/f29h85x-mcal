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
/* TODO: replace with actual value from Mcu based on MCAL-30739 */
#define MCAL_LIB_TICK_VALUE 5 /* 5ns for 200MHz SYS_CLK*/

#define MCAL_LIB_MAX_TICK_VALUE 0x4189374BC6A7EF /* Uint64_MAX/1000 */

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
 * \param[in] sysclkHz CPU SYSCLK in Hz
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
extern FUNC(void, MCAL_LIB_CODE)
    McalLib_DelayUsec(VAR(McalLib_TickType, MCAL_LIB_DATA) delayUsec, VAR(uint32, MCAL_LIB_DATA) sysclkHz);

/** \brief Delay function in milliseconds.
 *
 * \param[in] delayMsec Number of microseconds of delay
 * \param[in] sysclkHz CPU SYSCLK in Hz
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
extern FUNC(void, MCAL_LIB_CODE)
    McalLib_DelayMsec(VAR(McalLib_TickType, MCAL_LIB_DATA) delayMsec, VAR(uint32, MCAL_LIB_DATA) sysclkHz);

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
