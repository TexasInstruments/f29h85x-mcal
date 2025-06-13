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
 *  File:       Dio_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     DIO
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Dio module.
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

     
#if defined DIO_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using DIO_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define DIO_CODE_OPEN
#pragma clang section text = ".DIO_CODE"
#undef DIO_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined DIO_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using DIO_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef DIO_CODE_OPEN
    #error "Using DIO_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef DIO_CODE_OPEN
#pragma clang section text = ""
#undef DIO_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined DIO_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           DIO_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define DIO_CONFIG_DATA_OPEN
#pragma clang section rodata = ".DIO_CONFIG_DATA"
#undef DIO_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined DIO_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         DIO_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef DIO_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           DIO_STOP_SEC_CONFIG_DATA."
#endif
#undef DIO_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef DIO_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef DIO_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           DIO_START_SEC_CODE."
#endif
#ifdef DIO_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           DIO_STOP_SEC_CODE."
#endif

#ifdef DIO_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           DIO_START_SEC_CONFIG_DATA."
#endif
#ifdef DIO_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           DIO_STOP_SEC_CONFIG_DATA."
#endif

/*********************************************************************************************************************
 *  End of File: Dio_MemMap.h
 *********************************************************************************************************************/
    