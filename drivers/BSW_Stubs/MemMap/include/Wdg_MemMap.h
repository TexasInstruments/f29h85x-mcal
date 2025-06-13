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
 *  File:       Wdg_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     WDG
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Wdg module.
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

     
#if defined WDG_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using WDG_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define WDG_CODE_OPEN
#pragma clang section text = ".WDG_CODE"
#undef WDG_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined WDG_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using WDG_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef WDG_CODE_OPEN
    #error "Using WDG_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef WDG_CODE_OPEN
#pragma clang section text = ""
#undef WDG_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define WDG_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ".WDG_VAR_NO_INIT_UNSPECIFIED"
#undef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_NO_INIT_UNSPECIFIED is not open, Cannot close section using \
         WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef WDG_VAR_NO_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is not open ,Cannot close section using \
           WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef WDG_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ""
#undef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#elif defined WDG_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           WDG_START_SEC_VAR_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define WDG_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ".WDG_VAR_INIT_UNSPECIFIED"
#undef WDG_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_UNSPECIFIED is not open, Cannot close section using \
         WDG_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef WDG_VAR_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is not open ,Cannot close section using \
           WDG_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef WDG_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ""
#undef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#elif defined WDG_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           WDG_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define WDG_CONFIG_DATA_OPEN
#pragma clang section rodata = ".WDG_CONFIG_DATA"
#undef WDG_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined WDG_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         WDG_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef WDG_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           WDG_STOP_SEC_CONFIG_DATA."
#endif
#undef WDG_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef WDG_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef WDG_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           WDG_START_SEC_CODE."
#endif
#ifdef WDG_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           WDG_STOP_SEC_CODE."
#endif

#ifdef WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#ifdef WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif

#ifdef WDG_START_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           WDG_START_SEC_VAR_INIT_UNSPECIFIED."
#endif
#ifdef WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           WDG_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif

#ifdef WDG_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           WDG_START_SEC_CONFIG_DATA."
#endif
#ifdef WDG_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           WDG_STOP_SEC_CONFIG_DATA."
#endif

/*********************************************************************************************************************
 *  End of File: Wdg_MemMap.h
 *********************************************************************************************************************/
    