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
 *  File:       Fls_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     FLS
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Fls module.
 *
 *********************************************************************************************************************/

 
 /*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#ifndef FLS_MEMMAP_H
#define FLS_MEMMAP_H

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

     
#if defined FLS_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using FLS_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define FLS_CODE_OPEN
#pragma clang section text = ".FLS_CODE"
#undef FLS_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined FLS_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using FLS_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef FLS_CODE_OPEN
    #error "Using FLS_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef FLS_CODE_OPEN
#pragma clang section text = ""
#undef FLS_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined FLS_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           FLS_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define FLS_CONFIG_DATA_OPEN
#pragma clang section rodata = ".FLS_CONFIG_DATA"
#undef FLS_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined FLS_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         FLS_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef FLS_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           FLS_STOP_SEC_CONFIG_DATA."
#endif
#undef FLS_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef FLS_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#elif defined FLS_START_SEC_VAR_INIT_32
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_32 is already opened, Cannot reopen section using \
           FLS_START_SEC_VAR_INIT_32 ."
#endif
#define MEMMAP_SECTION_OPEN
#define FLS_VAR_INIT_32_OPEN
#pragma clang section data = ".FLS_VAR_INIT_32"
#undef FLS_START_SEC_VAR_INIT_32
#undef MEMMAP_ERROR

#elif defined FLS_STOP_SEC_VAR_INIT_32
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_32 is not open, Cannot close section using \
         FLS_STOP_SEC_VAR_INIT_32."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef FLS_VAR_INIT_32_OPEN
    #error "Memory section VAR_INIT_32 is not open ,Cannot close section using \
           FLS_STOP_SEC_VAR_INIT_32."
#endif
#undef FLS_VAR_INIT_32_OPEN
#pragma clang section data = ""
#undef FLS_STOP_SEC_VAR_INIT_32
#undef MEMMAP_ERROR
            
#elif defined FLS_START_SEC_VAR_INIT_8
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_8 is already opened, Cannot reopen section using \
           FLS_START_SEC_VAR_INIT_8 ."
#endif
#define MEMMAP_SECTION_OPEN
#define FLS_VAR_INIT_8_OPEN
#pragma clang section data = ".FLS_VAR_INIT_8"
#undef FLS_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR

#elif defined FLS_STOP_SEC_VAR_INIT_8
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_8 is not open, Cannot close section using \
         FLS_STOP_SEC_VAR_INIT_8."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef FLS_VAR_INIT_8_OPEN
    #error "Memory section VAR_INIT_8 is not open ,Cannot close section using \
           FLS_STOP_SEC_VAR_INIT_8."
#endif
#undef FLS_VAR_INIT_8_OPEN
#pragma clang section data = ""
#undef FLS_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
            
#elif defined FLS_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           FLS_START_SEC_VAR_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define FLS_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ".FLS_VAR_INIT_UNSPECIFIED"
#undef FLS_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_UNSPECIFIED is not open, Cannot close section using \
         FLS_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef FLS_VAR_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is not open ,Cannot close section using \
           FLS_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef FLS_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ""
#undef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#elif defined FLS_START_SEC_VAR_NO_INIT_32
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_NO_INIT_32 is already opened, Cannot reopen section using \
           FLS_START_SEC_VAR_NO_INIT_32 ."
#endif
#define MEMMAP_SECTION_OPEN
#define FLS_VAR_NO_INIT_32_OPEN
#pragma clang section bss = ".FLS_VAR_NO_INIT_32"
#undef FLS_START_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR

#elif defined FLS_STOP_SEC_VAR_NO_INIT_32
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_NO_INIT_32 is not open, Cannot close section using \
         FLS_STOP_SEC_VAR_NO_INIT_32."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef FLS_VAR_NO_INIT_32_OPEN
    #error "Memory section VAR_NO_INIT_32 is not open ,Cannot close section using \
           FLS_STOP_SEC_VAR_NO_INIT_32."
#endif
#undef FLS_VAR_NO_INIT_32_OPEN
#pragma clang section bss = ""
#undef FLS_STOP_SEC_VAR_NO_INIT_32
#undef MEMMAP_ERROR
            
#elif defined FLS_START_SEC_VAR_NO_INIT_8
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_NO_INIT_8 is already opened, Cannot reopen section using \
           FLS_START_SEC_VAR_NO_INIT_8 ."
#endif
#define MEMMAP_SECTION_OPEN
#define FLS_VAR_NO_INIT_8_OPEN
#pragma clang section bss = ".FLS_VAR_NO_INIT_8"
#undef FLS_START_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR

#elif defined FLS_STOP_SEC_VAR_NO_INIT_8
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_NO_INIT_8 is not open, Cannot close section using \
         FLS_STOP_SEC_VAR_NO_INIT_8."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef FLS_VAR_NO_INIT_8_OPEN
    #error "Memory section VAR_NO_INIT_8 is not open ,Cannot close section using \
           FLS_STOP_SEC_VAR_NO_INIT_8."
#endif
#undef FLS_VAR_NO_INIT_8_OPEN
#pragma clang section bss = ""
#undef FLS_STOP_SEC_VAR_NO_INIT_8
#undef MEMMAP_ERROR
            
#elif defined FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define FLS_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ".FLS_VAR_NO_INIT_UNSPECIFIED"
#undef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_NO_INIT_UNSPECIFIED is not open, Cannot close section using \
         FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef FLS_VAR_NO_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is not open ,Cannot close section using \
           FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef FLS_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ""
#undef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef FLS_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_START_SEC_CODE."
#endif
#ifdef FLS_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_STOP_SEC_CODE."
#endif

#ifdef FLS_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_START_SEC_CONFIG_DATA."
#endif
#ifdef FLS_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_STOP_SEC_CONFIG_DATA."
#endif

#ifdef FLS_START_SEC_VAR_INIT_32
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_START_SEC_VAR_INIT_32."
#endif
#ifdef FLS_STOP_SEC_VAR_INIT_32
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_STOP_SEC_VAR_INIT_32."
#endif

#ifdef FLS_START_SEC_VAR_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_START_SEC_VAR_INIT_8."
#endif
#ifdef FLS_STOP_SEC_VAR_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_STOP_SEC_VAR_INIT_8."
#endif

#ifdef FLS_START_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_START_SEC_VAR_INIT_UNSPECIFIED."
#endif
#ifdef FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_32
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_START_SEC_VAR_NO_INIT_32."
#endif
#ifdef FLS_STOP_SEC_VAR_NO_INIT_32
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_STOP_SEC_VAR_NO_INIT_32."
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_START_SEC_VAR_NO_INIT_8."
#endif
#ifdef FLS_STOP_SEC_VAR_NO_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_STOP_SEC_VAR_NO_INIT_8."
#endif

#ifdef FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#ifdef FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif

 #endif /* FLS_MEMMAP_H */
/*********************************************************************************************************************
 *  End of File: Fls_MemMap.h
 *********************************************************************************************************************/
    