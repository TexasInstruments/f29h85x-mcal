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
 *  File:       sdk_mcal_integration.h
 *  Generator:  None
 *
 *  Description:  This file contains stub interface header for using F29x-SDK rtdma in F29X-MCAL.
 *********************************************************************************************************************/

#ifndef SDK_MCAL_INTEGRATION_H
#define SDK_MCAL_INTEGRATION_H

/*********************************************************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 *********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcal_Lib.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
/* Define for no operation*/
#ifndef NOP
#define NOP MCAL_LIB_NOP;
#endif

/*****************************************************************************
 *
 * The ASSERT macro, which does the actual assertion checking.  Typically, this
 * will be for procedure arguments.
 *
 ******************************************************************************/
#ifdef DEBUG
#define ASSERT(expr)           \
    do                         \
    {                          \
        if (!(expr))           \
        {                      \
            MCAL_LIB_EMUSTOP0; \
        }                      \
    } while ((_Bool)0)
#else
#define ASSERT(expr)
#endif

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
typedef uint8  uint8_t;  /* This standard AUTOSAR type shall be of 8 bit unsigned. */
typedef uint16 uint16_t; /* This standard AUTOSAR type shall be of 16 bit unsigned. */
typedef uint32 uint32_t; /* This standard AUTOSAR type shall be of 32 bit unsigned. */
typedef uint64 uint64_t; /* This standard AUTOSAR type shall be of 64 bit unsigned. */
typedef sint8  int8_t;   /* This standard AUTOSAR type shall be of 8 bit signed. */
typedef sint16 int16_t;  /* This standard AUTOSAR type shall be of 16 bit signed. */
typedef sint32 int32_t;  /* This standard AUTOSAR type shall be of 32 bit signed. */
typedef sint64 int64_t;  /* This standard AUTOSAR type shall be of 64 bit signed. */
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *
 *  Mark the end of the C bindings section for C++ compilers.
 *
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif  // SDK_MCAL_INTEGRATION_H
