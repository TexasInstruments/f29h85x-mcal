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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Platform_Types.h
 *  Generator:  None
 *
 *  Description:  Template file to define Platform Types used in AUTOSAR.                                                           
 *********************************************************************************************************************/
#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#define CPU_TYPE_8              8               /* Indicating a 8 bit processor */
#define CPU_TYPE_16             16              /* Indicating a 16 bit processor */
#define CPU_TYPE_32             32              /* Indicating a 32 bit processor */
#define CPU_TYPE_64             64              /* Indicating a 64 bit processor */

#define MSB_FIRST               0               /* The most significant bit is the first bit of the bit sequence. */
#define LSB_FIRST               1               /* The least significant bit is the first bit of the bit sequence. */

#define HIGH_BYTE_FIRST         0               /* Within uint16, the high byte is located before the low byte. */
#define LOW_BYTE_FIRST          1               /* Within uint16, the low byte is located before the high byte. */

#ifndef TRUE
    #define TRUE                ((boolean)1)
#endif

#ifndef FALSE
    #define FALSE               ((boolean)0)
#endif

#define CPU_TYPE                CPU_TYPE_32     /* Register width of the CPU used */

#define CPU_BIT_ORDER           LSB_FIRST       /* Bit order on register level */

#if __little_endian__
    #define CPU_BYTE_ORDER      LOW_BYTE_FIRST  /* Byte order on memory level */
#else
    #define CPU_BYTE_ORDER      HIGH_BYTE_FIRST /* Byte order on memory level */ 
#endif

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
#if !defined(__TI_COMPILER_VERSION__) ||  !defined(__TMS320C2000__)

/* This standard AUTOSAR type shall only be used together with the definitions TRUE and FALSE. */
typedef unsigned char       boolean;            

typedef unsigned char       uint8;              /* This standard AUTOSAR type shall be of 8 bit unsigned. */
typedef unsigned short      uint16;             /* This standard AUTOSAR type shall be of 16 bit unsigned. */
typedef unsigned int        uint32;             /* This standard AUTOSAR type shall be of 32 bit unsigned. */
typedef unsigned long long  uint64;             /* This standard AUTOSAR type shall be of 64 bit unsigned. */

typedef signed char         sint8;              /* This standard AUTOSAR type shall be of 8 bit signed. */
typedef short               sint16;             /* This standard AUTOSAR type shall be of 16 bit signed. */
typedef int                 sint32;             /* This standard AUTOSAR type shall be of 32 bit signed. */
typedef long long           sint64;             /* This standard AUTOSAR type shall be of 64 bit signed. */

typedef unsigned int        uint8_least;        /* This optimized AUTOSAR type shall be at least 8 bit unsigned. */
typedef unsigned int        uint16_least;       /* This optimized AUTOSAR type shall be at least 16 bit unsigned. */
typedef unsigned int        uint32_least;       /* This optimized AUTOSAR type shall be at least 32 bit unsigned. */

typedef signed int          sint8_least;        /* This optimized AUTOSAR type shall be at least 8 bit signed. */
typedef signed int          sint16_least;       /* This optimized AUTOSAR type shall be at least 16 bit signed. */
typedef signed int          sint32_least;       /* This optimized AUTOSAR type shall be at least 32 bit signed. */

/* This standard AUTOSAR type shall follow the 32-bit binary interchange format according to IEEE 754-2008 */
/* with encoding parameters specified in chapter 3.6, table 3.5, column "binary32".*/
typedef float               float32;
/* This standard AUTOSAR type shall follow the 32-bit binary interchange format according to IEEE 754-2008 */
/* with encoding parameters specified in chapter 3.6, table 3.5, column "binary64".*/    
typedef double              float64;

#endif

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_TYPES_H */
/*********************************************************************************************************************
 *  End of File: Platform_Types.h
 *********************************************************************************************************************/
