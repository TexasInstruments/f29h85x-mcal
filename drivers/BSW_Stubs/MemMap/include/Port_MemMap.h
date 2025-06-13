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
 *  File:       Port_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     PORT
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Port module.
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

     
#if defined PORT_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using PORT_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define PORT_CODE_OPEN
#pragma clang section text = ".PORT_CODE"
#undef PORT_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined PORT_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using PORT_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef PORT_CODE_OPEN
    #error "Using PORT_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef PORT_CODE_OPEN
#pragma clang section text = ""
#undef PORT_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined PORT_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           PORT_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define PORT_CONFIG_DATA_OPEN
#pragma clang section rodata = ".PORT_CONFIG_DATA"
#undef PORT_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined PORT_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         PORT_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef PORT_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           PORT_STOP_SEC_CONFIG_DATA."
#endif
#undef PORT_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef PORT_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#elif defined PORT_START_SEC_VAR_INIT_PTR
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_PTR is already opened, Cannot reopen section using \
           PORT_START_SEC_VAR_INIT_PTR ."
#endif
#define MEMMAP_SECTION_OPEN
#define PORT_VAR_INIT_PTR_OPEN
#pragma clang section data = ".PORT_VAR_INIT_PTR"
#undef PORT_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR

#elif defined PORT_STOP_SEC_VAR_INIT_PTR
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_PTR is not open, Cannot close section using \
         PORT_STOP_SEC_VAR_INIT_PTR."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef PORT_VAR_INIT_PTR_OPEN
    #error "Memory section VAR_INIT_PTR is not open ,Cannot close section using \
           PORT_STOP_SEC_VAR_INIT_PTR."
#endif
#undef PORT_VAR_INIT_PTR_OPEN
#pragma clang section data = ""
#undef PORT_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
            
#elif defined PORT_START_SEC_VAR_INIT_BOOLEAN
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_BOOLEAN is already opened, Cannot reopen section using \
           PORT_START_SEC_VAR_INIT_BOOLEAN ."
#endif
#define MEMMAP_SECTION_OPEN
#define PORT_VAR_INIT_BOOLEAN_OPEN
#pragma clang section data = ".PORT_VAR_INIT_BOOLEAN"
#undef PORT_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR

#elif defined PORT_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_BOOLEAN is not open, Cannot close section using \
         PORT_STOP_SEC_VAR_INIT_BOOLEAN."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef PORT_VAR_INIT_BOOLEAN_OPEN
    #error "Memory section VAR_INIT_BOOLEAN is not open ,Cannot close section using \
           PORT_STOP_SEC_VAR_INIT_BOOLEAN."
#endif
#undef PORT_VAR_INIT_BOOLEAN_OPEN
#pragma clang section data = ""
#undef PORT_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef PORT_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           PORT_START_SEC_CODE."
#endif
#ifdef PORT_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           PORT_STOP_SEC_CODE."
#endif

#ifdef PORT_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           PORT_START_SEC_CONFIG_DATA."
#endif
#ifdef PORT_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           PORT_STOP_SEC_CONFIG_DATA."
#endif

#ifdef PORT_START_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           PORT_START_SEC_VAR_INIT_PTR."
#endif
#ifdef PORT_STOP_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           PORT_STOP_SEC_VAR_INIT_PTR."
#endif

#ifdef PORT_START_SEC_VAR_INIT_BOOLEAN
    #error "multiple memory allocation keywords are defined, Cannot use \
           PORT_START_SEC_VAR_INIT_BOOLEAN."
#endif
#ifdef PORT_STOP_SEC_VAR_INIT_BOOLEAN
    #error "multiple memory allocation keywords are defined, Cannot use \
           PORT_STOP_SEC_VAR_INIT_BOOLEAN."
#endif

/*********************************************************************************************************************
 *  End of File: Port_MemMap.h
 *********************************************************************************************************************/
    