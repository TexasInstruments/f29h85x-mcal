/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
