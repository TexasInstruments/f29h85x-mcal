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

#define INLINE                      inline        /* Abstraction of the keyword inline */
#define LOCAL_INLINE                static inline /* Abstraction of keyword inline with static scope. */

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
#define CONSTP2FUNC(rettype, ptrclass, fctname)         rettype (* const fctname)

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
