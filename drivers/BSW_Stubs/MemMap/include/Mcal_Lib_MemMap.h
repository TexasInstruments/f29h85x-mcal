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
 *  File:       Mcal_Lib_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     MCAL_LIB
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Mcal_Lib module.
 *
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
 * Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

     
#if defined MCAL_LIB_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using MCAL_LIB_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define MCAL_LIB_CODE_OPEN
#pragma clang section text = ".MCAL_LIB_CODE"
#undef MCAL_LIB_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined MCAL_LIB_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using MCAL_LIB_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef MCAL_LIB_CODE_OPEN
    #error "Using MCAL_LIB_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef MCAL_LIB_CODE_OPEN
#pragma clang section text = ""
#undef MCAL_LIB_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef MCAL_LIB_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCAL_LIB_START_SEC_CODE."
#endif
#ifdef MCAL_LIB_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCAL_LIB_STOP_SEC_CODE."
#endif

/*********************************************************************************************************************
 *  End of File: Mcal_Lib_MemMap.h
 *********************************************************************************************************************/