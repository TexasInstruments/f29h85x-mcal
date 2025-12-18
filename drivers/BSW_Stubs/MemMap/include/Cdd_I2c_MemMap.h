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
 *  File:       Cdd_I2c_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     CDD_I2C
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Cdd_I2c module.
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

#if defined CDD_I2C_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using CDD_I2C_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_I2C_CODE_OPEN
#pragma clang section text = ".CDD_I2C_CODE"
#undef CDD_I2C_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined CDD_I2C_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using CDD_I2C_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_I2C_CODE_OPEN
    #error "Using CDD_I2C_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef CDD_I2C_CODE_OPEN
#pragma clang section text = ""
#undef CDD_I2C_STOP_SEC_CODE
#undef MEMMAP_ERROR

#elif defined CDD_I2C_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           CDD_I2C_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_I2C_CONFIG_DATA_OPEN
#pragma clang section rodata = ".CDD_I2C_CONFIG_DATA"
#undef CDD_I2C_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined CDD_I2C_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         CDD_I2C_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_I2C_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           CDD_I2C_STOP_SEC_CONFIG_DATA."
#endif
#undef CDD_I2C_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef CDD_I2C_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined CDD_I2C_START_SEC_CONFIG_CONST_32
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONST_32 is already opened, Cannot reopen section using \
           CDD_I2C_START_SEC_CONFIG_CONST_32 ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_I2C_CONFIG_CONST_32_OPEN
#pragma clang section rodata = ".CDD_I2C_CONFIG_CONST_32"
#undef CDD_I2C_START_SEC_CONFIG_CONST_32
#undef MEMMAP_ERROR

#elif defined CDD_I2C_STOP_SEC_CONFIG_CONST_32
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONST_32 is not open, Cannot close section using \
         CDD_I2C_STOP_SEC_CONFIG_CONST_32."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_I2C_CONFIG_CONST_32_OPEN
    #error "Memory section CONST_32 is not open ,Cannot close section using \
           CDD_I2C_STOP_SEC_CONFIG_CONST_32."
#endif
#undef CDD_I2C_CONFIG_CONST_32_OPEN
#pragma clang section rodata = ""
#undef CDD_I2C_STOP_SEC_CONFIG_CONST_32
#undef MEMMAP_ERROR

#elif defined CDD_I2C_START_SEC_ISR_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section ISR_CODE is already opened, Cannot reopen section using \
           CDD_I2C_START_SEC_ISR_CODE ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_I2C_ISR_CODE_OPEN
#pragma clang section text = ".CDD_I2C_ISR_CODE"
#undef CDD_I2C_START_SEC_ISR_CODE
#undef MEMMAP_ERROR

#elif defined CDD_I2C_STOP_SEC_ISR_CODE
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section ISR_CODE is not open, Cannot close section using \
         CDD_I2C_STOP_SEC_ISR_CODE."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_I2C_ISR_CODE_OPEN
    #error "Memory section ISR_CODE is not open ,Cannot close section using \
           CDD_I2C_STOP_SEC_ISR_CODE."
#endif
#undef CDD_I2C_ISR_CODE_OPEN
#pragma clang section text = ""
#undef CDD_I2C_STOP_SEC_ISR_CODE
#undef MEMMAP_ERROR

#elif defined CDD_I2C_START_SEC_VAR_INIT_8
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_8 is already opened, Cannot reopen section using \
           CDD_I2C_START_SEC_VAR_INIT_8 ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_I2C_VAR_INIT_8_OPEN
#pragma clang section data = ".CDD_I2C_VAR_INIT_8"
#undef CDD_I2C_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR

#elif defined CDD_I2C_STOP_SEC_VAR_INIT_8
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_8 is not open, Cannot close section using \
         CDD_I2C_STOP_SEC_VAR_INIT_8."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_I2C_VAR_INIT_8_OPEN
    #error "Memory section VAR_INIT_8 is not open ,Cannot close section using \
           CDD_I2C_STOP_SEC_VAR_INIT_8."
#endif
#undef CDD_I2C_VAR_INIT_8_OPEN
#pragma clang section data = ""
#undef CDD_I2C_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR

#elif defined CDD_I2C_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           CDD_I2C_START_SEC_VAR_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_I2C_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ".CDD_I2C_VAR_INIT_UNSPECIFIED"
#undef CDD_I2C_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined CDD_I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_UNSPECIFIED is not open, Cannot close section using \
         CDD_I2C_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_I2C_VAR_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is not open ,Cannot close section using \
           CDD_I2C_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef CDD_I2C_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ""
#undef CDD_I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined CDD_I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           CDD_I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_I2C_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ".CDD_I2C_VAR_NO_INIT_UNSPECIFIED"
#undef CDD_I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined CDD_I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_NO_INIT_UNSPECIFIED is not open, Cannot close section using \
         CDD_I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_I2C_VAR_NO_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is not open ,Cannot close section using \
           CDD_I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef CDD_I2C_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ""
#undef CDD_I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef CDD_I2C_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_START_SEC_CODE."
#endif
#ifdef CDD_I2C_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_STOP_SEC_CODE."
#endif

#ifdef CDD_I2C_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_START_SEC_CONFIG_DATA."
#endif
#ifdef CDD_I2C_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_STOP_SEC_CONFIG_DATA."
#endif

#ifdef CDD_I2C_START_SEC_CONFIG_CONST_32
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_START_SEC_CONFIG_CONST_32."
#endif
#ifdef CDD_I2C_STOP_SEC_CONFIG_CONST_32
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_STOP_SEC_CONFIG_CONST_32."
#endif

#ifdef CDD_I2C_START_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_START_SEC_ISR_CODE."
#endif
#ifdef CDD_I2C_STOP_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_STOP_SEC_ISR_CODE."
#endif

#ifdef CDD_I2C_START_SEC_VAR_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_START_SEC_VAR_INIT_8."
#endif
#ifdef CDD_I2C_STOP_SEC_VAR_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_STOP_SEC_VAR_INIT_8."
#endif

#ifdef CDD_I2C_START_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_START_SEC_VAR_INIT_UNSPECIFIED."
#endif
#ifdef CDD_I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif

#ifdef CDD_I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#ifdef CDD_I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif

/*********************************************************************************************************************
 *  End of File: Cdd_I2c_MemMap.h
 *********************************************************************************************************************/
