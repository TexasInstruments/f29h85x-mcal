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
 *  File:       Cdd_Adc_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     CDD_ADC
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Cdd_Adc module.
 *
 *********************************************************************************************************************/

 
 /*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#ifndef CDD_ADC_MEMMAP_H
#define CDD_ADC_MEMMAP_H

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

     
#if defined CDD_ADC_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using CDD_ADC_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_ADC_CODE_OPEN
#pragma clang section text = ".CDD_ADC_CODE"
#undef CDD_ADC_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined CDD_ADC_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using CDD_ADC_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_ADC_CODE_OPEN
    #error "Using CDD_ADC_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef CDD_ADC_CODE_OPEN
#pragma clang section text = ""
#undef CDD_ADC_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined CDD_ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA_UNSPECIFIED is already opened, Cannot reopen section using \
           CDD_ADC_START_SEC_CONFIG_DATA_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_ADC_CONFIG_DATA_UNSPECIFIED_OPEN
#pragma clang section rodata = ".CDD_ADC_CONFIG_DATA_UNSPECIFIED"
#undef CDD_ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined CDD_ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA_UNSPECIFIED is not open, Cannot close section using \
         CDD_ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_ADC_CONFIG_DATA_UNSPECIFIED_OPEN
    #error "Memory section CONFIG_DATA_UNSPECIFIED is not open ,Cannot close section using \
           CDD_ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED."
#endif
#undef CDD_ADC_CONFIG_DATA_UNSPECIFIED_OPEN
#pragma clang section rodata = ""
#undef CDD_ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#undef MEMMAP_ERROR
            
#elif defined CDD_ADC_START_SEC_VAR_INIT_PTR
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_PTR is already opened, Cannot reopen section using \
           CDD_ADC_START_SEC_VAR_INIT_PTR ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_ADC_VAR_INIT_PTR_OPEN
#pragma clang section data = ".CDD_ADC_VAR_INIT_PTR"
#undef CDD_ADC_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR

#elif defined CDD_ADC_STOP_SEC_VAR_INIT_PTR
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_PTR is not open, Cannot close section using \
         CDD_ADC_STOP_SEC_VAR_INIT_PTR."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_ADC_VAR_INIT_PTR_OPEN
    #error "Memory section VAR_INIT_PTR is not open ,Cannot close section using \
           CDD_ADC_STOP_SEC_VAR_INIT_PTR."
#endif
#undef CDD_ADC_VAR_INIT_PTR_OPEN
#pragma clang section data = ""
#undef CDD_ADC_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
            
#elif defined CDD_ADC_START_SEC_ISR_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section ISR_CODE is already opened, Cannot reopen section using \
           CDD_ADC_START_SEC_ISR_CODE ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_ADC_ISR_CODE_OPEN
#pragma clang section text = ".CDD_ADC_ISR_CODE"
#undef CDD_ADC_START_SEC_ISR_CODE
#undef MEMMAP_ERROR

#elif defined CDD_ADC_STOP_SEC_ISR_CODE
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section ISR_CODE is not open, Cannot close section using \
         CDD_ADC_STOP_SEC_ISR_CODE."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_ADC_ISR_CODE_OPEN
    #error "Memory section ISR_CODE is not open ,Cannot close section using \
           CDD_ADC_STOP_SEC_ISR_CODE."
#endif
#undef CDD_ADC_ISR_CODE_OPEN
#pragma clang section text = ""
#undef CDD_ADC_STOP_SEC_ISR_CODE
#undef MEMMAP_ERROR
            
#elif defined CDD_ADC_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_FAST_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           CDD_ADC_START_SEC_VAR_FAST_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_ADC_VAR_FAST_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ".CDD_ADC_VAR_FAST_INIT_UNSPECIFIED"
#undef CDD_ADC_START_SEC_VAR_FAST_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined CDD_ADC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_FAST_INIT_UNSPECIFIED is not open, Cannot close section using \
         CDD_ADC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_ADC_VAR_FAST_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_FAST_INIT_UNSPECIFIED is not open ,Cannot close section using \
           CDD_ADC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED."
#endif
#undef CDD_ADC_VAR_FAST_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ""
#undef CDD_ADC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#elif defined CDD_ADC_START_SEC_VAR_INIT_BOOLEAN
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_BOOLEAN is already opened, Cannot reopen section using \
           CDD_ADC_START_SEC_VAR_INIT_BOOLEAN ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_ADC_VAR_INIT_BOOLEAN_OPEN
#pragma clang section data = ".CDD_ADC_VAR_INIT_BOOLEAN"
#undef CDD_ADC_START_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR

#elif defined CDD_ADC_STOP_SEC_VAR_INIT_BOOLEAN
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_BOOLEAN is not open, Cannot close section using \
         CDD_ADC_STOP_SEC_VAR_INIT_BOOLEAN."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_ADC_VAR_INIT_BOOLEAN_OPEN
    #error "Memory section VAR_INIT_BOOLEAN is not open ,Cannot close section using \
           CDD_ADC_STOP_SEC_VAR_INIT_BOOLEAN."
#endif
#undef CDD_ADC_VAR_INIT_BOOLEAN_OPEN
#pragma clang section data = ""
#undef CDD_ADC_STOP_SEC_VAR_INIT_BOOLEAN
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef CDD_ADC_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_START_SEC_CODE."
#endif
#ifdef CDD_ADC_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_STOP_SEC_CODE."
#endif

#ifdef CDD_ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_START_SEC_CONFIG_DATA_UNSPECIFIED."
#endif
#ifdef CDD_ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED."
#endif

#ifdef CDD_ADC_START_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_START_SEC_VAR_INIT_PTR."
#endif
#ifdef CDD_ADC_STOP_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_STOP_SEC_VAR_INIT_PTR."
#endif

#ifdef CDD_ADC_START_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_START_SEC_ISR_CODE."
#endif
#ifdef CDD_ADC_STOP_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_STOP_SEC_ISR_CODE."
#endif

#ifdef CDD_ADC_START_SEC_VAR_FAST_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_START_SEC_VAR_FAST_INIT_UNSPECIFIED."
#endif
#ifdef CDD_ADC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED."
#endif

#ifdef CDD_ADC_START_SEC_VAR_INIT_BOOLEAN
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_START_SEC_VAR_INIT_BOOLEAN."
#endif
#ifdef CDD_ADC_STOP_SEC_VAR_INIT_BOOLEAN
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_ADC_STOP_SEC_VAR_INIT_BOOLEAN."
#endif

 #endif /* CDD_ADC_MEMMAP_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Adc_MemMap.h
 *********************************************************************************************************************/
    
