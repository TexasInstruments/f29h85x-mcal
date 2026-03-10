/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
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
 *  File:       Cdd_Xbar_MemMap.h
 *  Project:    C29x MCAL
 *  Module:     CDD_XBAR
 *  Generator:  None
 *
 *  Description:  Memory Map template file for Cdd_Xbar module.
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

     
#if defined CDD_XBAR_START_SEC_CODE
#ifdef MEMMAP_SECTION_OPEN
    #error "Using CDD_XBAR_START_SEC_CODE is not possible as a memory section \
            has already been opened. Nesting is not supported."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_XBAR_CODE_OPEN
#pragma clang section text = ".CDD_XBAR_CODE"
#undef CDD_XBAR_START_SEC_CODE
#undef MEMMAP_ERROR

#elif defined CDD_XBAR_STOP_SEC_CODE
#ifndef MEMMAP_SECTION_OPEN
    #error "Using CDD_XBAR_STOP_SEC_CODE is not possible as no memory section \
            has been opened."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_XBAR_CODE_OPEN
    #error "Using CDD_XBAR_STOP_SEC_CODE is not possible as the corresponding \
            memory section has not been opened."
#endif
#undef CDD_XBAR_CODE_OPEN
#pragma clang section text = ""
#undef CDD_XBAR_STOP_SEC_CODE
#undef MEMMAP_ERROR
            
#elif defined CDD_XBAR_START_SEC_CONFIG_DATA
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section CONFIG_DATA is already opened, Cannot reopen section using \
           CDD_XBAR_START_SEC_CONFIG_DATA ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_XBAR_CONFIG_DATA_OPEN
#pragma clang section rodata = ".CDD_XBAR_CONFIG_DATA"
#undef CDD_XBAR_START_SEC_CONFIG_DATA
#undef MEMMAP_ERROR

#elif defined CDD_XBAR_STOP_SEC_CONFIG_DATA
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section CONFIG_DATA is not open, Cannot close section using \
         CDD_XBAR_STOP_SEC_CONFIG_DATA."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_XBAR_CONFIG_DATA_OPEN
    #error "Memory section CONFIG_DATA is not open ,Cannot close section using \
           CDD_XBAR_STOP_SEC_CONFIG_DATA."
#endif
#undef CDD_XBAR_CONFIG_DATA_OPEN
#pragma clang section rodata = ""
#undef CDD_XBAR_STOP_SEC_CONFIG_DATA
#undef MEMMAP_ERROR
            
#elif defined CDD_XBAR_START_SEC_VAR_INIT_8
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_8 is already opened, Cannot reopen section using \
           CDD_XBAR_START_SEC_VAR_INIT_8 ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_XBAR_VAR_INIT_8_OPEN
#pragma clang section data = ".CDD_XBAR_VAR_INIT_8"
#undef CDD_XBAR_START_SEC_VAR_INIT_8
#undef MEMMAP_ERROR

#elif defined CDD_XBAR_STOP_SEC_VAR_INIT_8
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_8 is not open, Cannot close section using \
         CDD_XBAR_STOP_SEC_VAR_INIT_8."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_XBAR_VAR_INIT_8_OPEN
    #error "Memory section VAR_INIT_8 is not open ,Cannot close section using \
           CDD_XBAR_STOP_SEC_VAR_INIT_8."
#endif
#undef CDD_XBAR_VAR_INIT_8_OPEN
#pragma clang section data = ""
#undef CDD_XBAR_STOP_SEC_VAR_INIT_8
#undef MEMMAP_ERROR
            
#elif defined CDD_XBAR_START_SEC_VAR_INIT_PTR
#ifdef MEMMAP_SECTION_OPEN
    #error "Memory section VAR_INIT_PTR is already opened, Cannot reopen section using \
           CDD_XBAR_START_SEC_VAR_INIT_PTR ."
#endif
#define MEMMAP_SECTION_OPEN
#define CDD_XBAR_VAR_INIT_PTR_OPEN
#pragma clang section data = ".CDD_XBAR_VAR_INIT_PTR"
#undef CDD_XBAR_START_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR

#elif defined CDD_XBAR_STOP_SEC_VAR_INIT_PTR
#ifndef MEMMAP_SECTION_OPEN
#error "Memory section VAR_INIT_PTR is not open, Cannot close section using \
         CDD_XBAR_STOP_SEC_VAR_INIT_PTR."
#endif
#undef MEMMAP_SECTION_OPEN
#ifndef CDD_XBAR_VAR_INIT_PTR_OPEN
    #error "Memory section VAR_INIT_PTR is not open ,Cannot close section using \
           CDD_XBAR_STOP_SEC_VAR_INIT_PTR."
#endif
#undef CDD_XBAR_VAR_INIT_PTR_OPEN
#pragma clang section data = ""
#undef CDD_XBAR_STOP_SEC_VAR_INIT_PTR
#undef MEMMAP_ERROR
            
#endif


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/
    
#ifdef CDD_XBAR_START_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_XBAR_START_SEC_CODE."
#endif
#ifdef CDD_XBAR_STOP_SEC_CODE
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_XBAR_STOP_SEC_CODE."
#endif

#ifdef CDD_XBAR_START_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_XBAR_START_SEC_CONFIG_DATA."
#endif
#ifdef CDD_XBAR_STOP_SEC_CONFIG_DATA
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_XBAR_STOP_SEC_CONFIG_DATA."
#endif

#ifdef CDD_XBAR_START_SEC_VAR_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_XBAR_START_SEC_VAR_INIT_8."
#endif
#ifdef CDD_XBAR_STOP_SEC_VAR_INIT_8
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_XBAR_STOP_SEC_VAR_INIT_8."
#endif

#ifdef CDD_XBAR_START_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_XBAR_START_SEC_VAR_INIT_PTR."
#endif
#ifdef CDD_XBAR_STOP_SEC_VAR_INIT_PTR
    #error "multiple memory allocation keywords are defined, Cannot use \
           CDD_XBAR_STOP_SEC_VAR_INIT_PTR."
#endif

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_MemMap.h
 *********************************************************************************************************************/
    
