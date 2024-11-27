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
 *  File:       Compiler_Cfg.h
 *  Generator:  Code generation tool (if any)
 *
 *  Description:  It contains module specific parameters (ptrclass and memclass) that are passed to 
 *                the macros defined in Compiler.h                                                           
 *********************************************************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
* This is an empty header file which should be replaced by the end user.
* 
* According to the AUTOSAR document "Specification of Compiler Abstraction"
* final version, as part of AUTOSAR release 4.2.2, SWS_COMPILER_00055:
*  The file Compiler_Cfg.h shall contain the module specific parameters
*  (ptrclass and memclass) that are passed to the macros defined in 
*  Compiler.h.
* 
* The following is the form of these macro definitions.  MSN stands for     
* "Module Short Name of BSW module list"
* 
* #define <MSN>_CODE
* #define <MSN>_CONST  
* #define <MSN>_APPL_DATA
* #define <MSN>_APPL_CONST  
* #define <MSN>_APPL_CODE  
* #define <MSN>_VAR_NOINIT   
* #define <MSN>_VAR_POWER_ON_INIT  
* #define <MSN>_VAR_FAST
* #define <MSN>_VAR
* 
* NOTE: On 32 bit architectures these definitions are required to be empty                                                   
*********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

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
 
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* COMPILER_CFG_H */
/*********************************************************************************************************************
 *  End of File: Compiler_Cfg.h
 *********************************************************************************************************************/
