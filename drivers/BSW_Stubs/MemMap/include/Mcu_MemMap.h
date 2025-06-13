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
 *  File:       Mcu_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     MCU
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Mcu module.
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

     
#if defined MCU_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using MCU_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define MCU_CODE_OPEN
#pragma clang section text = ".MCU_CODE"
#undef MCU_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined MCU_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using MCU_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef MCU_CODE_OPEN
    #error "Using MCU_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef MCU_CODE_OPEN
#pragma clang section text = ""
#undef MCU_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined MCU_START_SEC_VAR_INIT_PTR
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_PTR is already opened, Cannot reopen section using \
           MCU_START_SEC_VAR_INIT_PTR ."
#endif
#define MEMMAP_SECTION_OPEN
#define MCU_VAR_INIT_PTR_OPEN
#pragma clang section data = ".MCU_VAR_INIT_PTR"
#undef MCU_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR

#elif defined MCU_STOP_SEC_VAR_INIT_PTR
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_PTR is not open, Cannot close section using \
         MCU_STOP_SEC_VAR_INIT_PTR."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef MCU_VAR_INIT_PTR_OPEN
    #error "Memory section VAR_INIT_PTR is not open ,Cannot close section using \
           MCU_STOP_SEC_VAR_INIT_PTR."
#endif
#undef MCU_VAR_INIT_PTR_OPEN
#pragma clang section data = ""
#undef MCU_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
            
#elif defined MCU_START_SEC_VAR_INIT_BOOLEAN
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_BOOLEAN is already opened, Cannot reopen section using \
           MCU_START_SEC_VAR_INIT_BOOLEAN ."
#endif
#define MEMMAP_SECTION_OPEN
#define MCU_VAR_INIT_BOOLEAN_OPEN
#pragma clang section data = ".MCU_VAR_INIT_BOOLEAN"
#undef MCU_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR

#elif defined MCU_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_BOOLEAN is not open, Cannot close section using \
         MCU_STOP_SEC_VAR_INIT_BOOLEAN."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef MCU_VAR_INIT_BOOLEAN_OPEN
    #error "Memory section VAR_INIT_BOOLEAN is not open ,Cannot close section using \
           MCU_STOP_SEC_VAR_INIT_BOOLEAN."
#endif
#undef MCU_VAR_INIT_BOOLEAN_OPEN
#pragma clang section data = ""
#undef MCU_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
            
#elif defined MCU_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           MCU_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define MCU_CONFIG_DATA_OPEN
#pragma clang section rodata = ".MCU_CONFIG_DATA"
#undef MCU_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined MCU_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         MCU_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef MCU_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           MCU_STOP_SEC_CONFIG_DATA."
#endif
#undef MCU_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef MCU_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef MCU_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCU_START_SEC_CODE."
#endif
#ifdef MCU_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCU_STOP_SEC_CODE."
#endif

#ifdef MCU_START_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCU_START_SEC_VAR_INIT_PTR."
#endif
#ifdef MCU_STOP_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCU_STOP_SEC_VAR_INIT_PTR."
#endif

#ifdef MCU_START_SEC_VAR_INIT_BOOLEAN
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCU_START_SEC_VAR_INIT_BOOLEAN."
#endif
#ifdef MCU_STOP_SEC_VAR_INIT_BOOLEAN
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCU_STOP_SEC_VAR_INIT_BOOLEAN."
#endif

#ifdef MCU_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCU_START_SEC_CONFIG_DATA."
#endif
#ifdef MCU_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           MCU_STOP_SEC_CONFIG_DATA."
#endif

/*********************************************************************************************************************
 *  End of File: Mcu_MemMap.h
 *********************************************************************************************************************/
    