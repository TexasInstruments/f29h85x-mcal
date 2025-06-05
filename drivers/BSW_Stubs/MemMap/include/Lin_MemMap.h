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
 *  File:       Lin_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     LIN
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Lin module.
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

     
#if defined LIN_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using LIN_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define LIN_CODE_OPEN
#pragma clang section text = ".LIN_CODE"
#undef LIN_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined LIN_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using LIN_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef LIN_CODE_OPEN
    #error "Using LIN_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef LIN_CODE_OPEN
#pragma clang section text = ""
#undef LIN_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined LIN_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           LIN_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define LIN_CONFIG_DATA_OPEN
#pragma clang section rodata = ".LIN_CONFIG_DATA"
#undef LIN_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined LIN_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         LIN_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef LIN_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           LIN_STOP_SEC_CONFIG_DATA."
#endif
#undef LIN_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef LIN_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#elif defined LIN_START_SEC_ISR_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section ISR_CODE is already opened, Cannot reopen section using \
           LIN_START_SEC_ISR_CODE ."
#endif
#define MEMMAP_SECTION_OPEN
#define LIN_ISR_CODE_OPEN
#pragma clang section text = ".LIN_ISR_CODE"
#undef LIN_START_SEC_ISR_CODE
#undef MEMMAP_ERROR

#elif defined LIN_STOP_SEC_ISR_CODE
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section ISR_CODE is not open, Cannot close section using \
         LIN_STOP_SEC_ISR_CODE."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef LIN_ISR_CODE_OPEN
    #error "Memory section ISR_CODE is not open ,Cannot close section using \
           LIN_STOP_SEC_ISR_CODE."
#endif
#undef LIN_ISR_CODE_OPEN
#pragma clang section text = ""
#undef LIN_STOP_SEC_ISR_CODE
#undef MEMMAP_ERROR
            
#elif defined LIN_START_SEC_VAR_INIT_8
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_8 is already opened, Cannot reopen section using \
           LIN_START_SEC_VAR_INIT_8 ."
#endif
#define MEMMAP_SECTION_OPEN
#define LIN_VAR_INIT_8_OPEN
#pragma clang section data = ".LIN_VAR_INIT_8"
#undef LIN_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR

#elif defined LIN_STOP_SEC_VAR_INIT_8
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_8 is not open, Cannot close section using \
         LIN_STOP_SEC_VAR_INIT_8."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef LIN_VAR_INIT_8_OPEN
    #error "Memory section VAR_INIT_8 is not open ,Cannot close section using \
           LIN_STOP_SEC_VAR_INIT_8."
#endif
#undef LIN_VAR_INIT_8_OPEN
#pragma clang section data = ""
#undef LIN_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
            
#elif defined LIN_START_SEC_VAR_INIT_PTR
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_PTR is already opened, Cannot reopen section using \
           LIN_START_SEC_VAR_INIT_PTR ."
#endif
#define MEMMAP_SECTION_OPEN
#define LIN_VAR_INIT_PTR_OPEN
#pragma clang section data = ".LIN_VAR_INIT_PTR"
#undef LIN_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR

#elif defined LIN_STOP_SEC_VAR_INIT_PTR
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_PTR is not open, Cannot close section using \
         LIN_STOP_SEC_VAR_INIT_PTR."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef LIN_VAR_INIT_PTR_OPEN
    #error "Memory section VAR_INIT_PTR is not open ,Cannot close section using \
           LIN_STOP_SEC_VAR_INIT_PTR."
#endif
#undef LIN_VAR_INIT_PTR_OPEN
#pragma clang section data = ""
#undef LIN_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
            
#elif defined LIN_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           LIN_START_SEC_VAR_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define LIN_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ".LIN_VAR_INIT_UNSPECIFIED"
#undef LIN_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_UNSPECIFIED is not open, Cannot close section using \
         LIN_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef LIN_VAR_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is not open ,Cannot close section using \
           LIN_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef LIN_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ""
#undef LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef LIN_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_START_SEC_CODE."
#endif
#ifdef LIN_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_STOP_SEC_CODE."
#endif

#ifdef LIN_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_START_SEC_CONFIG_DATA."
#endif
#ifdef LIN_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_STOP_SEC_CONFIG_DATA."
#endif

#ifdef LIN_START_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_START_SEC_ISR_CODE."
#endif
#ifdef LIN_STOP_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_STOP_SEC_ISR_CODE."
#endif

#ifdef LIN_START_SEC_VAR_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_START_SEC_VAR_INIT_8."
#endif
#ifdef LIN_STOP_SEC_VAR_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_STOP_SEC_VAR_INIT_8."
#endif

#ifdef LIN_START_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_START_SEC_VAR_INIT_PTR."
#endif
#ifdef LIN_STOP_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_STOP_SEC_VAR_INIT_PTR."
#endif

#ifdef LIN_START_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_START_SEC_VAR_INIT_UNSPECIFIED."
#endif
#ifdef LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           LIN_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif

/*********************************************************************************************************************
 *  End of File: Lin_MemMap.h
 *********************************************************************************************************************/
    