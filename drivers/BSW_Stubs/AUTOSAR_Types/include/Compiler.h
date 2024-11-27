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
 *  File:       Compiler.h
 *  Generator:  None
 *
 *  Description:  Compiler Specific Language Extension Header                                                           
 *********************************************************************************************************************/
#ifndef COMPILER_H
#define COMPILER_H

#ifdef __cplusplus
extern "C" {
#endif
 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Compiler_Cfg.h" 

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#define COMPILER_MAJOR_VERSION      __TI_COMPILER_MAJOR_VERSION__
#define COMPILER_MINOR_VERSION      __TI_COMPILER_MINOR_VERSION__
#define COMPILER_PATCH_VERSION      __TI_COMPILER_PATCH_VERSION__

#define AUTOMATIC                                   /* Used for the declaration of local pointers */

#define TYPEDEF                     typedef         /* The memory class shall be used within type definitions */ 

#define NULL_PTR                    ((void *)0x0)   /* Void pointer to zero definition */

#define INLINE                      __inline        /* Abstraction of the keyword inline */
#define LOCAL_INLINE                static __inline /* Abstraction of keyword inline with static scope. */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/** \brief FUNC identification information
 *
 * The compiler abstraction shall define the FUNC macro for the declaration and definition of functions 
 * that ensures correct syntax of function declarations as required by a specific compiler.
 *
 * \param[in] rettype   return type of the function
 * \param[in] memclass  classification of the function itself
 *
 *********************************************************************************************************************/
#define FUNC(rettype, memclass)                         rettype

/** \brief FUNC_P2CONST identification information
 *
 * The compiler abstraction shall define the FUNC_P2CONST macro for the declaration and definition of functions 
 * returning a pointer to a constant. This shall ensure the correct syntax of function declarations as required 
 * by a specific compiler.
 *
 * \param[in] rettype   return type of the function
 * \param[in] ptrclass  defines the classification of the pointer’s distance
 * \param[in] memclass  classification of the function itself
 *
 *********************************************************************************************************************/
#define FUNC_P2CONST(rettype, ptrclass, memclass)       const ptrclass rettype *   

/** \brief FUNC_P2VAR identification information
 *
 * The compiler abstraction shall define the FUNC_P2VAR macro for the declaration and definition of 
 * functions returning a pointer to a variable. This shall ensure the correct syntax of function declarations 
 * as required by a specific compiler.
 *
 * \param[in] rettype   return type of the function
 * \param[in] ptrclass  defines the classification of the pointer’s distance
 * \param[in] memclass  classification of the function itself
 *
 *********************************************************************************************************************/
#define FUNC_P2VAR(rettype, ptrclass, memclass)         ptrclass rettype *   

/** \brief P2VAR identification information
 *
 * The compiler abstraction shall define the P2VAR macro for the declaration and definition of pointers in RAM,
 * pointing to variables.
 * The pointer itself is modifiable (e.g. ExamplePtr++).
 * The pointer’s target is modifiable (e.g. *ExamplePtr = 5).
 *
 * \param[in] ptrtype   type of the referenced variable
 * \param[in] memclass  classification of the pointer’s variable itself
 * \param[in] ptrclass  defines the classification of the pointer’s distance
 *
 *********************************************************************************************************************/
#define P2VAR(ptrtype, memclass, ptrclass)              ptrtype *

/** \brief P2CONST identification information
 *
 * The compiler abstraction shall define the P2CONST macro for the declaration and definition of pointers in
 * RAM pointing to constants.
 * The pointer itself is modifiable (e.g. ExamplePtr++).
 * The pointer’s target is not modifiable (read only).
 *
 * \param[in] ptrtype   type of the referenced variable
 * \param[in] memclass  classification of the pointer’s variable itself
 * \param[in] ptrclass  defines the classification of the pointer’s distance
 *
 *********************************************************************************************************************/
#define P2CONST(ptrtype, memclass, ptrclass)           const ptrtype *

/** \brief CONSTP2VAR identification information
 *
 * The compiler abstraction shall define the CONSTP2VAR macro for the declaration and definition of constant
 * pointers accessing variables.
 * The pointer itself is not modifiable (fix address).
 * The pointer’s target is modifiable (e.g. *ExamplePtr = 18).
 *
 * \param[in] ptrtype   type of the referenced variable
 * \param[in] memclass  classification of the pointer’s variable itself
 * \param[in] ptrclass  defines the classification of the pointer’s distance
 *
 *********************************************************************************************************************/
#define CONSTP2VAR(ptrtype, memclass, ptrclass)         ptrtype * const

/** \brief CONSTP2CONST identification information
 *
 * The compiler abstraction shall define the CONSTP2CONST macro for the declaration and definition of constant
 * pointers accessing constants.
 * The pointer itself is not modifiable (fix address).
 * The pointer’s target is not modifiable (read only).
 *
 * \param[in] ptrtype   type of the referenced variable
 * \param[in] memclass  classification of the pointer’s variable itself
 * \param[in] ptrclass  defines the classification of the pointer’s distance
 *
 *********************************************************************************************************************/
#define CONSTP2CONST(ptrtype, memclass, ptrclass)       const ptrtype * const

/** \brief P2FUNC identification information
 *
 * The compiler abstraction shall define the P2FUNC macro for the type definition of pointers to functions.
 *
 * \param[in] rettype   return type of the function
 * \param[in] ptrclass  defines the classification of the pointer’s distance
 * \param[in] fctname   function name respectively name of the defined type
 *
 *********************************************************************************************************************/
#define P2FUNC(rettype, ptrclass, fctname)              rettype (* fctname)

/** \brief CONSTP2FUNC identification information
 *
 * The compiler abstraction shall define the CONSTP2FUNC macro for the type definition of constant 
 * pointers to functions.
 *
 * \param[in] rettype   return type of the function
 * \param[in] ptrclass  defines the classification of the pointer’s distance
 * \param[in] fctname   function name respectively name of the defined type
 *
 *********************************************************************************************************************/
#define CONSTP2FUNC(rettype, ptrclass, fctname)         rettype (* cpnst fctname)

/** \brief CONST identification information
 *
 * The compiler abstraction shall define the CONST macro for the declaration and definition of constants.
 *
 * \param[in] consttype return type of the function
 * \param[in] memclass  defines the classification of the pointer’s distance
 *
 *********************************************************************************************************************/
#define CONST(consttype, memclass)                      const consttype

/** \brief VAR identification information
 *
 * The compiler abstraction shall define the VAR macro for the declaration and definition of variables.
 *
 * \param[in] vartype   return type of the function
 * \param[in] memclass  defines the classification of the pointer’s distance
 *
 *********************************************************************************************************************/
#define VAR(vartype, memclass)                          vartype

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* COMPILER_H */
/*********************************************************************************************************************
 *  End of File: Compiler.h
 *********************************************************************************************************************/
