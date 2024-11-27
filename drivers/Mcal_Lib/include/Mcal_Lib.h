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

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

#define MCAL_LIB_SW_MAJOR_VERSION            (1U) /* Driver Implementation Major Version. */
#define MCAL_LIB_SW_MINOR_VERSION            (0U) /* Driver Implementation Minor Version. */
#define MCAL_LIB_SW_PATCH_VERSION            (0U) /* Driver Implementation Patch Version. */

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

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
