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
 *  File:       Gpt_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     GPT
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Gpt module.
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

     
#if defined GPT_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using GPT_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define GPT_CODE_OPEN
#pragma clang section text = ".GPT_CODE"
#undef GPT_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined GPT_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using GPT_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef GPT_CODE_OPEN
    #error "Using GPT_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef GPT_CODE_OPEN
#pragma clang section text = ""
#undef GPT_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined GPT_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           GPT_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define GPT_CONFIG_DATA_OPEN
#pragma clang section rodata = ".GPT_CONFIG_DATA"
#undef GPT_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined GPT_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         GPT_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef GPT_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           GPT_STOP_SEC_CONFIG_DATA."
#endif
#undef GPT_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef GPT_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#elif defined GPT_START_SEC_ISR_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section ISR_CODE is already opened, Cannot reopen section using \
           GPT_START_SEC_ISR_CODE ."
#endif
#define MEMMAP_SECTION_OPEN
#define GPT_ISR_CODE_OPEN
#pragma clang section text = ".GPT_ISR_CODE"
#undef GPT_START_SEC_ISR_CODE
#undef MEMMAP_ERROR

#elif defined GPT_STOP_SEC_ISR_CODE
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section ISR_CODE is not open, Cannot close section using \
         GPT_STOP_SEC_ISR_CODE."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef GPT_ISR_CODE_OPEN
    #error "Memory section ISR_CODE is not open ,Cannot close section using \
           GPT_STOP_SEC_ISR_CODE."
#endif
#undef GPT_ISR_CODE_OPEN
#pragma clang section text = ""
#undef GPT_STOP_SEC_ISR_CODE
#undef MEMMAP_ERROR
            
#elif defined GPT_START_SEC_VAR_INIT_BOOLEAN
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_BOOLEAN is already opened, Cannot reopen section using \
           GPT_START_SEC_VAR_INIT_BOOLEAN ."
#endif
#define MEMMAP_SECTION_OPEN
#define GPT_VAR_INIT_BOOLEAN_OPEN
#pragma clang section data = ".GPT_VAR_INIT_BOOLEAN"
#undef GPT_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR

#elif defined GPT_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_BOOLEAN is not open, Cannot close section using \
         GPT_STOP_SEC_VAR_INIT_BOOLEAN."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef GPT_VAR_INIT_BOOLEAN_OPEN
    #error "Memory section VAR_INIT_BOOLEAN is not open ,Cannot close section using \
           GPT_STOP_SEC_VAR_INIT_BOOLEAN."
#endif
#undef GPT_VAR_INIT_BOOLEAN_OPEN
#pragma clang section data = ""
#undef GPT_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
            
#elif defined GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define GPT_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ".GPT_VAR_NO_INIT_UNSPECIFIED"
#undef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_NO_INIT_UNSPECIFIED is not open, Cannot close section using \
         GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef GPT_VAR_NO_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is not open ,Cannot close section using \
           GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef GPT_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ""
#undef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#elif defined GPT_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           GPT_START_SEC_VAR_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define GPT_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ".GPT_VAR_INIT_UNSPECIFIED"
#undef GPT_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_UNSPECIFIED is not open, Cannot close section using \
         GPT_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef GPT_VAR_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is not open ,Cannot close section using \
           GPT_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef GPT_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ""
#undef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef GPT_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_START_SEC_CODE."
#endif
#ifdef GPT_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_STOP_SEC_CODE."
#endif

#ifdef GPT_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_START_SEC_CONFIG_DATA."
#endif
#ifdef GPT_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_STOP_SEC_CONFIG_DATA."
#endif

#ifdef GPT_START_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_START_SEC_ISR_CODE."
#endif
#ifdef GPT_STOP_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_STOP_SEC_ISR_CODE."
#endif

#ifdef GPT_START_SEC_VAR_INIT_BOOLEAN
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_START_SEC_VAR_INIT_BOOLEAN."
#endif
#ifdef GPT_STOP_SEC_VAR_INIT_BOOLEAN
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_STOP_SEC_VAR_INIT_BOOLEAN."
#endif

#ifdef GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#ifdef GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif

#ifdef GPT_START_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_START_SEC_VAR_INIT_UNSPECIFIED."
#endif
#ifdef GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           GPT_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif

/*********************************************************************************************************************
 *  End of File: Gpt_MemMap.h
 *********************************************************************************************************************/
    