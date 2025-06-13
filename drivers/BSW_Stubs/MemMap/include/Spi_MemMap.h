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
 *  File:       Spi_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     SPI
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Spi module.
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

     
#if defined SPI_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using SPI_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define SPI_CODE_OPEN
#pragma clang section text = ".SPI_CODE"
#undef SPI_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined SPI_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using SPI_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef SPI_CODE_OPEN
    #error "Using SPI_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef SPI_CODE_OPEN
#pragma clang section text = ""
#undef SPI_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined SPI_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           SPI_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define SPI_CONFIG_DATA_OPEN
#pragma clang section rodata = ".SPI_CONFIG_DATA"
#undef SPI_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined SPI_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         SPI_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef SPI_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           SPI_STOP_SEC_CONFIG_DATA."
#endif
#undef SPI_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef SPI_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#elif defined SPI_START_SEC_ISR_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section ISR_CODE is already opened, Cannot reopen section using \
           SPI_START_SEC_ISR_CODE ."
#endif
#define MEMMAP_SECTION_OPEN
#define SPI_ISR_CODE_OPEN
#pragma clang section text = ".SPI_ISR_CODE"
#undef SPI_START_SEC_ISR_CODE
#undef MEMMAP_ERROR

#elif defined SPI_STOP_SEC_ISR_CODE
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section ISR_CODE is not open, Cannot close section using \
         SPI_STOP_SEC_ISR_CODE."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef SPI_ISR_CODE_OPEN
    #error "Memory section ISR_CODE is not open ,Cannot close section using \
           SPI_STOP_SEC_ISR_CODE."
#endif
#undef SPI_ISR_CODE_OPEN
#pragma clang section text = ""
#undef SPI_STOP_SEC_ISR_CODE
#undef MEMMAP_ERROR
            
#elif defined SPI_START_SEC_VAR_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           SPI_START_SEC_VAR_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define SPI_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ".SPI_VAR_INIT_UNSPECIFIED"
#undef SPI_START_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_UNSPECIFIED is not open, Cannot close section using \
         SPI_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef SPI_VAR_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_INIT_UNSPECIFIED is not open ,Cannot close section using \
           SPI_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif
#undef SPI_VAR_INIT_UNSPECIFIED_OPEN
#pragma clang section data = ""
#undef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#elif defined SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is already opened, Cannot reopen section using \
           SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED ."
#endif
#define MEMMAP_SECTION_OPEN
#define SPI_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ".SPI_VAR_NO_INIT_UNSPECIFIED"
#undef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_NO_INIT_UNSPECIFIED is not open, Cannot close section using \
         SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef SPI_VAR_NO_INIT_UNSPECIFIED_OPEN
    #error "Memory section VAR_NO_INIT_UNSPECIFIED is not open ,Cannot close section using \
           SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#undef SPI_VAR_NO_INIT_UNSPECIFIED_OPEN
#pragma clang section bss = ""
#undef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef SPI_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_START_SEC_CODE."
#endif
#ifdef SPI_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_STOP_SEC_CODE."
#endif

#ifdef SPI_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_START_SEC_CONFIG_DATA."
#endif
#ifdef SPI_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_STOP_SEC_CONFIG_DATA."
#endif

#ifdef SPI_START_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_START_SEC_ISR_CODE."
#endif
#ifdef SPI_STOP_SEC_ISR_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_STOP_SEC_ISR_CODE."
#endif

#ifdef SPI_START_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_START_SEC_VAR_INIT_UNSPECIFIED."
#endif
#ifdef SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_STOP_SEC_VAR_INIT_UNSPECIFIED."
#endif

#ifdef SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif
#ifdef SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #error "multiple memory allocation keywords are defined, Cannot use \
           SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED."
#endif

/*********************************************************************************************************************
 *  End of File: Spi_MemMap.h
 *********************************************************************************************************************/
    