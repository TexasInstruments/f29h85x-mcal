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
 *  File:         FlashTech_F29H85x_C29x.h
 *  Generator:    None
 *
 *  Description:  Header for the F29H85x C29x Flash API v21.00
 *********************************************************************************************************************/
#ifndef F65_F29H85x_C29X_H_
#define F65_F29H85x_C29X_H_

/*
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include <stdint.h>

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/* Architecture Defines */
#if !defined(_F29H85x)
#define _F29H85x
#endif

#if !defined(_LITTLE_ENDIAN)
#define _LITTLE_ENDIAN
#endif

#if !defined(_C29)
#define _C29
#endif

#if !defined(F65)
#define F65
#endif

/* The following are defines for the FLASH_NOWRAPPER register offsets */
#ifndef FLASH_NOWRAPPER_O_CMDWEPROTA
#define FLASH_NOWRAPPER_O_CMDWEPROTA 0x1D0U /* Command Write Erase Protect A Register */
#endif

#ifndef FLASH_NOWRAPPER_O_CMDWEPROTB
#define FLASH_NOWRAPPER_O_CMDWEPROTB 0x1D4U /* Command Write Erase Protect B Register */
#endif

#ifndef FLASH_NOWRAPPER_O_CMDWEPROTNM
#define FLASH_NOWRAPPER_O_CMDWEPROTNM 0x210U /* Command Write Erase Protect Non-Main */
#endif

#ifndef HIGH_BYTE_FIRST
#define HIGH_BYTE_FIRST 0U
#endif

#ifndef LOW_BYTE_FIRST
#define LOW_BYTE_FIRST 1U
#endif

#ifndef TRUE
#define TRUE 1U
#endif

#ifndef FALSE
#define FALSE 0U
#endif

#ifndef CPU_BYTE_ORDER
#if defined(_LITTLE_ENDIAN)
#define CPU_BYTE_ORDER LOW_BYTE_FIRST
#else
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST
#endif
#endif

/*!
 *  FMC memory map defines
 */
#if defined(_F29H85x)

/*--------------------------------------------------------------------------------------
 *  C29 banks : Main Array
 *--------------------------------------------------------------------------------------*/
#define C29FLASH_MAP_BEGIN     (uint32_t)(0x10000000)
#define C29FLASH_MAP_END_PLUS1 (uint32_t)(0x10800000)
/* FR-1 RP0 */
#define C29FLASHBANKFR1RP0STARTADDRESS    (uint32_t)(0x10000000)
#define C29FLASHBANKFR1RP0ENDADDRESS      (uint32_t)(0x100FFFFF)
#define C29FLASHBANKFR1RP0ENDADDRESSPLUS1 (uint32_t)(0x10100000)

/* FR-1 RP1 */
#define C29FLASHBANKFR1RP1STARTADDRESS    (uint32_t)(0x10100000)
#define C29FLASHBANKFR1RP1ENDADDRESS      (uint32_t)(0x101FFFFF)
#define C29FLASHBANKFR1RP1ENDADDRESSPLUS1 (uint32_t)(0x10200000)

/* FR-1 RP2 */
#define C29FLASHBANKFR1RP2STARTADDRESS    (uint32_t)(0x10200000)
#define C29FLASHBANKFR1RP2ENDADDRESS      (uint32_t)(0x102FFFFF)
#define C29FLASHBANKFR1RP2ENDADDRESSPLUS1 (uint32_t)(0x10300000)

/* FR-1 RP3 */
#define C29FLASHBANKFR1RP3STARTADDRESS    (uint32_t)(0x10300000)
#define C29FLASHBANKFR1RP3ENDADDRESS      (uint32_t)(0x103FFFFF)
#define C29FLASHBANKFR1RP3ENDADDRESSPLUS1 (uint32_t)(0x10400000)

/* FR-2 RP0 */
#define C29FLASHBANKFR2RP0STARTADDRESS    (uint32_t)(0x10400000)
#define C29FLASHBANKFR2RP0ENDADDRESS      (uint32_t)(0x104FFFFF)
#define C29FLASHBANKFR2RP0ENDADDRESSPLUS1 (uint32_t)(0x10500000)

/* FR-2 RP1 */
#define C29FLASHBANKFR2RP1STARTADDRESS    (uint32_t)(0x10500000)
#define C29FLASHBANKFR2RP1ENDADDRESS      (uint32_t)(0x105FFFFF)
#define C29FLASHBANKFR2RP1ENDADDRESSPLUS1 (uint32_t)(0x10600000)

/* FR-3 RP0 */
#define C29FLASHBANKFR3RP0STARTADDRESS    (uint32_t)(0x10600000)
#define C29FLASHBANKFR3RP0ENDADDRESS      (uint32_t)(0x106FFFFF)
#define C29FLASHBANKFR3RP0ENDADDRESSPLUS1 (uint32_t)(0x10700000)

/* FR-3 RP1 */
#define C29FLASHBANKFR3RP1STARTADDRESS    (uint32_t)(0x10700000)
#define C29FLASHBANKFR3RP1ENDADDRESS      (uint32_t)(0x107FFFFF)
#define C29FLASHBANKFR3RP1ENDADDRESSPLUS1 (uint32_t)(0x10800000)

/* FR-4 RP0 data flash */
#define C29FLASHBANKFR4RP0STARTADDRESS    (uint32_t)(0x10C00000)
#define C29FLASHBANKFR4RP0ENDADDRESS      (uint32_t)(0x10C3FFFF)
#define C29FLASHBANKFR4RP0ENDADDRESSPLUS1 (uint32_t)(0x10C40000)

/*--------------------------------------------------------------------------------------
 *  C29 banks : Main Array ECC
 *--------------------------------------------------------------------------------------*/
#define C29FLASHECC_MAP_BEGIN     (uint32_t)(0x10E00000)
#define C29FLASHECC_MAP_END_PLUS1 (uint32_t)(0x10F00000)
/* FR-1 RP0 ECC */
#define C29FLASHBANKFR1RP0ECCSTARTADDRESS    (uint32_t)(0x10E00000)
#define C29FLASHBANKFR1RP0ECCENDADDRESS      (uint32_t)(0x10E1FFFF)
#define C29FLASHBANKFR1RP0ECCENDADDRESSPLUS1 (uint32_t)(0x10E20000)

/* FR-1 RP1 ECC */
#define C29FLASHBANKFR1RP1ECCSTARTADDRESS    (uint32_t)(0x10E20000)
#define C29FLASHBANKFR1RP1ECCENDADDRESS      (uint32_t)(0x10E3FFFF)
#define C29FLASHBANKFR1RP1ECCENDADDRESSPLUS1 (uint32_t)(0x10E40000)

/* FR-1 RP2 ECC */
#define C29FLASHBANKFR1RP2ECCSTARTADDRESS    (uint32_t)(0x10E40000)
#define C29FLASHBANKFR1RP2ECCENDADDRESS      (uint32_t)(0x10E5FFFF)
#define C29FLASHBANKFR1RP2ECCENDADDRESSPLUS1 (uint32_t)(0x10E60000)

/* FR-1 RP3 ECC */
#define C29FLASHBANKFR1RP3ECCSTARTADDRESS    (uint32_t)(0x10E60000)
#define C29FLASHBANKFR1RP3ECCENDADDRESS      (uint32_t)(0x10E7FFFF)
#define C29FLASHBANKFR1RP3ECCENDADDRESSPLUS1 (uint32_t)(0x10E80000)

/* FR-2 RP0 ECC */
#define C29FLASHBANKFR2RP0ECCSTARTADDRESS    (uint32_t)(0x10E80000)
#define C29FLASHBANKFR2RP0ECCENDADDRESS      (uint32_t)(0x10E9FFFF)
#define C29FLASHBANKFR2RP0ECCENDADDRESSPLUS1 (uint32_t)(0x10EA0000)

/* FR-2 RP1 ECC */
#define C29FLASHBANKFR2RP1ECCSTARTADDRESS    (uint32_t)(0x10EA0000)
#define C29FLASHBANKFR2RP1ECCENDADDRESS      (uint32_t)(0x10EBFFFF)
#define C29FLASHBANKFR2RP1ECCENDADDRESSPLUS1 (uint32_t)(0x10EC0000)

/* FR-3 RP0 ECC */
#define C29FLASHBANKFR3RP0ECCSTARTADDRESS    (uint32_t)(0x10EC0000)
#define C29FLASHBANKFR3RP0ECCENDADDRESS      (uint32_t)(0x10EDFFFF)
#define C29FLASHBANKFR3RP0ECCENDADDRESSPLUS1 (uint32_t)(0x10EE0000)

/* FR-3 RP1 ECC */
#define C29FLASHBANKFR3RP1ECCSTARTADDRESS    (uint32_t)(0x10EE0000)
#define C29FLASHBANKFR3RP1ECCENDADDRESS      (uint32_t)(0x10EFFFFF)
#define C29FLASHBANKFR3RP1ECCENDADDRESSPLUS1 (uint32_t)(0x10F00000)

/* FR-4 RP0 ECC data flash */
#define C29FLASHBANKFR4RP0ECCSTARTADDRESS    (uint32_t)(0x10F80000)
#define C29FLASHBANKFR4RP0ECCENDADDRESS      (uint32_t)(0x10F87FFF)
#define C29FLASHBANKFR4RP0ECCENDADDRESSPLUS1 (uint32_t)(0x10F88000)

/*--------------------------------------------------------------------------------------
 *  C29 banks : Non-Main Array
 *--------------------------------------------------------------------------------------*/
/* FR-1 RP0 BANKMGMT */
#define C29FLASHBANKFR1RP0BANKMGMTSTARTADDRESS    (uint32_t)(0x10D80000)
#define C29FLASHBANKFR1RP0BANKMGMTENDADDRESS      (uint32_t)(0x10D80FFF)
#define C29FLASHBANKFR1RP0BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D81000)

/* FR-1 RP0 SECCFG */
#define C29FLASHBANKFR1RP0SECCFGSTARTADDRESS    (uint32_t)(0x10D81000)
#define C29FLASHBANKFR1RP0SECCFGENDADDRESS      (uint32_t)(0x10D81FFF)
#define C29FLASHBANKFR1RP0SECCFGENDADDRESSPLUS1 (uint32_t)(0x10D82000)

/* FR-1 RP1 BANKMGMT */
#define C29FLASHBANKFR1RP1BANKMGMTSTARTADDRESS    (uint32_t)(0x10D84000)
#define C29FLASHBANKFR1RP1BANKMGMTENDADDRESS      (uint32_t)(0x10D84FFF)
#define C29FLASHBANKFR1RP1BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D85000)

/* FR-1 RP1 SECCFG */
#define C29FLASHBANKFR1RP1SECCFGSTARTADDRESS    (uint32_t)(0x10D85000)
#define C29FLASHBANKFR1RP1SECCFGENDADDRESS      (uint32_t)(0x10D85FFF)
#define C29FLASHBANKFR1RP1SECCFGENDADDRESSPLUS1 (uint32_t)(0x10D86000)

/* FR-1 RP2 BANKMGMT */
#define C29FLASHBANKFR1RP2BANKMGMTSTARTADDRESS    (uint32_t)(0x10D88000)
#define C29FLASHBANKFR1RP2BANKMGMTENDADDRESS      (uint32_t)(0x10D88FFF)
#define C29FLASHBANKFR1RP2BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D89000)

/* FR-1 RP2 SECCFG */
#define C29FLASHBANKFR1RP2SECCFGSTARTADDRESS    (uint32_t)(0x10D89000)
#define C29FLASHBANKFR1RP2SECCFGENDADDRESS      (uint32_t)(0x10D89FFF)
#define C29FLASHBANKFR1RP2SECCFGENDADDRESSPLUS1 (uint32_t)(0x10D8A000)

/* FR-1 RP3 BANKMGMT */
#define C29FLASHBANKFR1RP3BANKMGMTSTARTADDRESS    (uint32_t)(0x10D8C000)
#define C29FLASHBANKFR1RP3BANKMGMTENDADDRESS      (uint32_t)(0x10D8CFFF)
#define C29FLASHBANKFR1RP3BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D8D000)

/* FR-1 RP3 SECCFG */
#define C29FLASHBANKFR1RP3SECCFGSTARTADDRESS    (uint32_t)(0x10D8D000)
#define C29FLASHBANKFR1RP3SECCFGENDADDRESS      (uint32_t)(0x10D8DFFF)
#define C29FLASHBANKFR1RP3SECCFGENDADDRESSPLUS1 (uint32_t)(0x10D8E000)

/* FR-2 RP0 BANKMGMT */
#define C29FLASHBANKFR2RP0BANKMGMTSTARTADDRESS    (uint32_t)(0x10D90000)
#define C29FLASHBANKFR2RP0BANKMGMTENDADDRESS      (uint32_t)(0x10D90FFF)
#define C29FLASHBANKFR2RP0BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D91000)

/* FR-2 RP0 SECCFG */
#define C29FLASHBANKFR2RP0SECCFGSTARTADDRESS    (uint32_t)(0x10D91000)
#define C29FLASHBANKFR2RP0SECCFGENDADDRESS      (uint32_t)(0x10D91FFF)
#define C29FLASHBANKFR2RP0SECCFGENDADDRESSPLUS1 (uint32_t)(0x10D92000)

/* FR-2 RP1 BANKMGMT */
#define C29FLASHBANKFR2RP1BANKMGMTSTARTADDRESS    (uint32_t)(0x10D94000)
#define C29FLASHBANKFR2RP1BANKMGMTENDADDRESS      (uint32_t)(0x10D94FFF)
#define C29FLASHBANKFR2RP1BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D95000)

/* FR-2 RP1 SECCFG */
#define C29FLASHBANKFR2RP1SECCFGSTARTADDRESS    (uint32_t)(0x10D95000)
#define C29FLASHBANKFR2RP1SECCFGENDADDRESS      (uint32_t)(0x10D95FFF)
#define C29FLASHBANKFR2RP1SECCFGENDADDRESSPLUS1 (uint32_t)(0x10D96000)

/* FR-3 RP0 BANKMGMT */
#define C29FLASHBANKFR3RP0BANKMGMTSTARTADDRESS    (uint32_t)(0x10D98000)
#define C29FLASHBANKFR3RP0BANKMGMTENDADDRESS      (uint32_t)(0x10D98FFF)
#define C29FLASHBANKFR3RP0BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D99000)

/* FR-3 RP0 SECCFG */
#define C29FLASHBANKFR3RP0SECCFGSTARTADDRESS    (uint32_t)(0x10D99000)
#define C29FLASHBANKFR3RP0SECCFGENDADDRESS      (uint32_t)(0x10D99FFF)
#define C29FLASHBANKFR3RP0SECCFGENDADDRESSPLUS1 (uint32_t)(0x10D9A000)

/* FR-3 RP1 BANKMGMT */
#define C29FLASHBANKFR3RP1BANKMGMTSTARTADDRESS    (uint32_t)(0x10D9C000)
#define C29FLASHBANKFR3RP1BANKMGMTENDADDRESS      (uint32_t)(0x10D9CFFF)
#define C29FLASHBANKFR3RP1BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D9D000)

/* FR-3 RP1 SECCFG */
#define C29FLASHBANKFR3RP1SECCFGSTARTADDRESS    (uint32_t)(0x10D9D000)
#define C29FLASHBANKFR3RP1SECCFGENDADDRESS      (uint32_t)(0x10D9DFFF)
#define C29FLASHBANKFR3RP1SECCFGENDADDRESSPLUS1 (uint32_t)(0x10D9E000)

/* FR-4 RP0 Data Flash */
#define C29FLASHBANKFR4RP0BANKMGMTSTARTADDRESS    (uint32_t)(0x10D9E000)
#define C29FLASHBANKFR4RP0BANKMGMTENDADDRESS      (uint32_t)(0x10D9EFFF)
#define C29FLASHBANKFR4RP0BANKMGMTENDADDRESSPLUS1 (uint32_t)(0x10D9F000)

/*--------------------------------------------------------------------------------------
 *  HSM C29 banks : Non-Main Array ECC
 *--------------------------------------------------------------------------------------*/
/* FR-1 RP0 BANKMGMT ECC */
#define C29FLASHBANKFR1RP0BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB0000)
#define C29FLASHBANKFR1RP0BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB01FF)
#define C29FLASHBANKFR1RP0BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB0200)

/* FR-1 RP0 SECCFG ECC */
#define C29FLASHBANKFR1RP0SECCFGECCSTARTADDRESS    (uint32_t)(0x10FB0200)
#define C29FLASHBANKFR1RP0SECCFGECCENDADDRESS      (uint32_t)(0x10FB03FF)
#define C29FLASHBANKFR1RP0SECCFGECCENDADDRESSPLUS1 (uint32_t)(0x10FB0400)

/* FR-1 RP1 BANKMGMT ECC */
#define C29FLASHBANKFR1RP1BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB0800)
#define C29FLASHBANKFR1RP1BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB09FF)
#define C29FLASHBANKFR1RP1BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB0A00)

/* FR-1 RP1 SECCFG ECC */
#define C29FLASHBANKFR1RP1SECCFGECCSTARTADDRESS    (uint32_t)(0x10FB0A00)
#define C29FLASHBANKFR1RP1SECCFGECCENDADDRESS      (uint32_t)(0x10FB0BFF)
#define C29FLASHBANKFR1RP1SECCFGECCENDADDRESSPLUS1 (uint32_t)(0x10FB0C00)

/* FR-1 RP2 BANKMGMT ECC */
#define C29FLASHBANKFR1RP2BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB1000)
#define C29FLASHBANKFR1RP2BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB11FF)
#define C29FLASHBANKFR1RP2BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB1200)

/* FR-1 RP2 SECCFG ECC */
#define C29FLASHBANKFR1RP2SECCFGECCSTARTADDRESS    (uint32_t)(0x10FB1200)
#define C29FLASHBANKFR1RP2SECCFGECCENDADDRESS      (uint32_t)(0x10FB13FF)
#define C29FLASHBANKFR1RP2SECCFGECCENDADDRESSPLUS1 (uint32_t)(0x10FB1400)

/* FR-1 RP3 BANKMGMT ECC */
#define C29FLASHBANKFR1RP3BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB1800)
#define C29FLASHBANKFR1RP3BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB19FF)
#define C29FLASHBANKFR1RP3BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB1A00)

/* FR-1 RP3 SECCFG ECC */
#define C29FLASHBANKFR1RP3SECCFGECCSTARTADDRESS    (uint32_t)(0x10FB1A00)
#define C29FLASHBANKFR1RP3SECCFGECCENDADDRESS      (uint32_t)(0x10FB1BFF)
#define C29FLASHBANKFR1RP3SECCFGECCENDADDRESSPLUS1 (uint32_t)(0x10FB1C00)

/* FR-2 RP0 BANKMGMT ECC */
#define C29FLASHBANKFR2RP0BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB2000)
#define C29FLASHBANKFR2RP0BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB21FF)
#define C29FLASHBANKFR2RP0BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB2200)

/* FR-2 RP0 SECCFG ECC */
#define C29FLASHBANKFR2RP0SECCFGECCSTARTADDRESS    (uint32_t)(0x10FB2200)
#define C29FLASHBANKFR2RP0SECCFGECCENDADDRESS      (uint32_t)(0x10FB23FF)
#define C29FLASHBANKFR2RP0SECCFGECCENDADDRESSPLUS1 (uint32_t)(0x10FB2400)

/* FR-2 RP1 BANKMGMT ECC */
#define C29FLASHBANKFR2RP1BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB2800)
#define C29FLASHBANKFR2RP1BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB29FF)
#define C29FLASHBANKFR2RP1BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB2A00)

/* FR-2 RP1 SECCFG ECC */
#define C29FLASHBANKFR2RP1SECCFGECCSTARTADDRESS    (uint32_t)(0x10FB2A00)
#define C29FLASHBANKFR2RP1SECCFGECCENDADDRESS      (uint32_t)(0x10FB2BFF)
#define C29FLASHBANKFR2RP1SECCFGECCENDADDRESSPLUS1 (uint32_t)(0x10FB2C00)

/* FR-3 RP0 BANKMGMT ECC */
#define C29FLASHBANKFR3RP0BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB3000)
#define C29FLASHBANKFR3RP0BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB31FF)
#define C29FLASHBANKFR3RP0BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB3200)

/* FR-3 RP0 SECCFG ECC */
#define C29FLASHBANKFR3RP0SECCFGECCSTARTADDRESS    (uint32_t)(0x10FB3200)
#define C29FLASHBANKFR3RP0SECCFGECCENDADDRESS      (uint32_t)(0x10FB33FF)
#define C29FLASHBANKFR3RP0SECCFGECCENDADDRESSPLUS1 (uint32_t)(0x10FB3400)

/* FR-3 RP1 BANKMGMT ECC */
#define C29FLASHBANKFR3RP1BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB3800)
#define C29FLASHBANKFR3RP1BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB39FF)
#define C29FLASHBANKFR3RP1BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB3A00)

/* FR-3 RP1 SECCFG ECC */
#define C29FLASHBANKFR3RP1SECCFGECCSTARTADDRESS    (uint32_t)(0x10FB3A00)
#define C29FLASHBANKFR3RP1SECCFGECCENDADDRESS      (uint32_t)(0x10FB3BFF)
#define C29FLASHBANKFR3RP1SECCFGECCENDADDRESSPLUS1 (uint32_t)(0x10FB3C00)

/* FR-4 RP0 Data flash */
#define C29FLASHBANKFR4RP0BANKMGMTECCSTARTADDRESS    (uint32_t)(0x10FB4000)
#define C29FLASHBANKFR4RP0BANKMGMTECCENDADDRESS      (uint32_t)(0x10FB41FF)
#define C29FLASHBANKFR4RP0BANKMGMTECCENDADDRESSPLUS1 (uint32_t)(0x10FB4200)

/* Mode 0 main and non-main address translation offsets */
#define Mode0_FR1_FOTAMainArrayOffset    (uint32_t)(0x00600000)
#define Mode0_FR1_FOTANonMainArrayOffset (uint32_t)(0x00004000)

/* Mode 1 main and non-main address translation offsets */
#define Mode1_FR1_FOTAMainArrayOffset    (uint32_t)(0x00600000)
#define Mode1_FR1_FOTANonMainArrayOffset (uint32_t)(0x00018000)

/* Mode 1  main and non-main ECC address translation offsets */
#define Mode1_FR1_FOTAMainArrayEccOffset    (uint32_t)(0x000C0000)
#define Mode1_FR1_FOTANonMainArrayEccOffset (uint32_t)(0x00003000)

/* Mode 3 FR1 main and non-main address translation offsets */
#define Mode3_FR1_FOTAMainArrayOffset    (uint32_t)(0x00600000)
#define Mode3_FR1_FOTANonMainArrayOffset (uint32_t)(0x00018000)

/* Mode 3 FR2 main and non-main address translation offsets */
#define Mode3_FR2_FOTAMainArrayOffset    (uint32_t)(0x00300000)
#define Mode3_FR2_FOTANonMainArrayOffset (uint32_t)(0x0000C000)

/* Mode 3 FR1 main and non-main ECC address translation offsets */
#define Mode3_FR1_FOTAMainArrayEccOffset    (uint32_t)(0x000C0000)
#define Mode3_FR1_FOTANonMainArrayEccOffset (uint32_t)(0x00003000)

/* Mode 3 FR2 main and non-main ECC address translation offsets */
#define Mode3_FR2_FOTAMainArrayEccOffset    (uint32_t)(0x00060000)
#define Mode3_FR2_FOTANonMainArrayEccOffset (uint32_t)(0x00001800)

#define SECVALID_CPU1_2_MASK (uint32_t)(0x000000FF)
#define SECVALID_CPU3_4_MASK (uint32_t)(0x00FF0000)

#define SECCFG_UPDATE_CTR_OFFSET (uint32_t)(0x00000FF0)

/* Banksize corresponds to superset variant, others may have smaller banksizes */
#define FlashC29BankSize            0x100000U
#define FlashC29SECCFGBNKMGMTOffset 0x4000U

/* Sector length in number of 32bits */
#define DataBankSector2KB_u32length 0x200U
#define MainBankSector4KB_u32length 0x400U

#endif

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#define ATTRIBUTE_PACKED __attribute__((packed))

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

#ifndef BOOLEAN_DEFINED
#define BOOLEAN_DEFINED
typedef unsigned char boolean;
#endif

typedef struct
{
    uint32_t au32StatusWord[4];
} ATTRIBUTE_PACKED Fapi_FlashStatusWordType;

/*!
    \brief This contains all the possible modes used in the Fapi_IssueAsyncProgrammingCommand().
*/
typedef enum
{
    Fapi_AutoEccGeneration, /* This is the default mode for the command and will auto generate the ecc for the provided
                               data buffer */
    Fapi_DataOnly,          /* Command will only process the data buffer */
    Fapi_EccOnly,           /* Command will only process the ecc buffer */
    Fapi_DataAndEcc         /* Command will process data and ecc buffers */
} ATTRIBUTE_PACKED Fapi_FlashProgrammingCommandsType;

/*!
    \brief This is used to indicate which Flash bank is being used.
*/
typedef enum
{
    C29Bank /* C29 CPU 1 */
} ATTRIBUTE_PACKED Fapi_FlashBankType;

/*!
    \brief This contains all the possible Flash State Machine commands.
*/
typedef enum
{
    Fapi_ProgramData = 0x0002U,
    Fapi_EraseSector = 0x0006U,
    Fapi_EraseBank   = 0x0008U,
    Fapi_ClearStatus = 0x0010U
} ATTRIBUTE_PACKED Fapi_FlashStateCommandsType;

typedef uint32_t Fapi_FlashStatusType;

/*!
    \brief This is the master type containing all possible returned status codes.
*/
typedef enum
{
    Fapi_Status_Success = 0,        /* Function completed successfully */
    Fapi_Status_FsmBusy,            /* FSM is Busy */
    Fapi_Status_FsmReady,           /* FSM is Ready */
    Fapi_Status_AsyncBusy,          /* Async function operation is Busy */
    Fapi_Status_AsyncComplete,      /* Async function operation is Complete */
    Fapi_Error_Fail = 500,          /* Generic Function Fail code */
    Fapi_Error_StateMachineTimeout, /* State machine polling never returned ready and timed out */
    Fapi_Error_OtpChecksumMismatch, /* Returned if OTP checksum does not match expected value */
    Fapi_Error_InvalidDelayValue,   /* Returned if the Calculated RWAIT value exceeds 15  - Legacy Error */
    Fapi_Error_InvalidHclkValue,    /* Returned if FClk is above max FClk value - FClk is a calculated from HClk and
                                       RWAIT/EWAIT */
    Fapi_Error_InvalidCpu,          /* Returned if the specified Cpu does not exist */
    Fapi_Error_InvalidBank,         /* Returned if the specified bank does not exist */
    Fapi_Error_InvalidAddress,      /* Returned if the specified Address does not exist in Flash or OTP */
    Fapi_Error_InvalidReadMode,     /* Returned if the specified read mode does not exist */
    Fapi_Error_AsyncIncorrectDataBufferLength,
    Fapi_Error_AsyncIncorrectEccBufferLength,
    Fapi_Error_AsyncDataEccBufferLengthMismatch,
    Fapi_Error_FeatureNotAvailable,  /* FMC feature is not available on this device */
    Fapi_Error_FlashRegsNotWritable, /* Returned if Flash registers are not writable due to security */
    Fapi_Error_InvalidCPUID,         /* Returned if OTP has an invalid CPUID */
    Fapi_Error_InvalidBankMode       /* Returned if BankMode provided is invalid */
} ATTRIBUTE_PACKED Fapi_StatusType;

/*!
    \brief
*/
typedef enum
{
    Alpha_Internal, /* For internal TI use only.  Not intended to be used by customers */
    Alpha,          /* Early Engineering release.  May not be functionally complete */
    Beta_Internal,  /* For internal TI use only.  Not intended to be used by customers */
    Beta,           /* Functionally complete, to be used for testing and validation */
    Production      /* Fully validated, functionally complete, ready for production use */
} ATTRIBUTE_PACKED Fapi_ApiProductionStatusType;

/*!
    \brief
*/
typedef struct
{
    uint8_t                      u8ApiMajorVersion;
    uint8_t                      u8ApiMinorVersion;
    uint8_t                      u8ApiRevision;
    Fapi_ApiProductionStatusType oApiProductionStatus;
    uint32_t                     u32ApiBuildNumber;
    uint8_t                      u8ApiTechnologyType;
    uint8_t                      u8ApiTechnologyRevision;
    uint8_t                      u8ApiEndianness;
    uint32_t                     u32ApiCompilerVersion;
} Fapi_LibraryInfoType;

/*!
    \brief This contains all the possible Flash Bank ID's.
*/
typedef enum
{
    Bank0,
    Bank1,
    Bank2,
    Bank3,
    Bank4

} ATTRIBUTE_PACKED Fapi_BankID;

/*!
    \brief This contains a NW flash controller address
*/
typedef enum
{
    FAPI_FLASHNW_FC1_BASE = (uint32_t)0x30100000U,
    FAPI_FLASHNW_FC2_BASE = (uint32_t)0x30110000U

} ATTRIBUTE_PACKED Fapi_FLCID;

/*!
    \brief This contains a NW flash controller address
*/
typedef enum
{
    Fapi_BankMgmtFLC1Address = (uint32_t)0x10d80000U,
    Fapi_BankMgmtFLC2Address = (uint32_t)0x10d90000U

} ATTRIBUTE_PACKED Fapi_BankMgmtAddress;

/*!
    \brief
*/
typedef enum
{
    Mode0 = 0x3U, /* Mode 0: CPU1 4MB, No FOTA, CPU1SWAP X CPU3SWAP X */
    Mode1 = 0x6U, /* Mode 1: CPU1 4MB, FOTA Enabled, CPU1SWAP 0/1 CPU3SWAP X*/
    Mode2 = 0x9U, /* Mode 2: CPU1 2MB CPU3 2MB, No FOTA, CPU1SWAP X CPU3SWAP X*/
    Mode3 = 0xCU  /* Mode 3: CPU1 2MB CPU3 2MB, FOTA Enabled, (CPU1SWAP 1 CPU3SWAP 1) or (CPU1SWAP 0 CPU3SWAP 0)*/
} ATTRIBUTE_PACKED Fapi_BankMode;

/*!
    \brief
*/
typedef enum
{
    CPU1Swap0 = 0xC9U, /* default mapping of CPU1 Banks */
    CPU1Swap1 = 0x36U, /* Alternate Mapping of CPU1 Banks */
} ATTRIBUTE_PACKED Fapi_CPU1BankSwap;

/*!
    \brief
*/
typedef enum
{
    CPU3Swap0 = 0xC9U, /* default mapping of CPU3 Banks */
    CPU3Swap1 = 0x36U, /* Alternate Mapping of CPU3 Banks */
} ATTRIBUTE_PACKED Fapi_CPU3BankSwap;

typedef enum
{
    FOTA_Image, /* FOTA is enabled */
    Active_Bank /* FOTA is disabled */
} ATTRIBUTE_PACKED Fapi_FOTAStatus;

/*!
    \brief
*/
typedef enum
{
    BankSize256KB,
    BankSize512KB,
    BankSize1MB
} ATTRIBUTE_PACKED Fapi_ECCAddressBits;

/*!
    \brief
    \\
*/
typedef enum
{
    Base = 0xC9U, /* BASE addresses are valid */
    Alt  = 0x36U  /* ALT addresses are valid */
} ATTRIBUTE_PACKED Fapi_SECVALID;

/*typedef union Fapi_Register*/
/*!
    Structure describing the Flash Wrapper registers allowing register and bit
    level accesses.
*/
typedef volatile struct NW_BASE_REGISTERS
{
    uint32_t u32Register; /* Correctable Error Address Register, bits 31:0 */
} Fapi_FmcRegistersType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Function Prototypes
 *********************************************************************************************************************/

/* Flash State Machine commands */
extern Fapi_FlashStatusType Fapi_getFsmStatus(uint32_t u32StartAddress, uint32_t u32UserFlashConfig);

extern Fapi_StatusType Fapi_checkFsmForReady(uint32_t u32StartAddress, uint32_t u32UserFlashConfig);

extern Fapi_StatusType Fapi_setActiveFlashBank(Fapi_FlashBankType oNewFlashBank);

extern void Fapi_flushPipeline(uint32_t u32UserFlashConfig);

extern Fapi_StatusType Fapi_setupBankSectorEnable(uint32_t *pu32StartAddress, uint32_t u32UserFlashConfig,
                                                  uint32_t reg_address, uint32_t value);

extern Fapi_StatusType Fapi_issueProgBankMode(Fapi_BankMgmtAddress u32StartAddress, Fapi_BankMode u32BankMode,
                                              Fapi_FlashStatusWordType *poFlashStatusWord, uint32_t u32UserFlashConfig);

/* Device Family Dependent FSM commands */
extern uint32_t *Fapi_remapEccAddress(uint32_t u32EccAddress);

extern boolean Fapi_isAddressEcc(uint32_t u32Address);

/* Async Commands */
extern Fapi_StatusType Fapi_issueAsyncCommandWithAddress(Fapi_FlashStateCommandsType oCommand,
                                                         uint32_t *pu32StartAddress, uint8_t u8Iterator,
                                                         uint32_t u32UserFlashConfig);

extern Fapi_StatusType Fapi_issueAsyncCommand(uint32_t u32StartAddress, uint32_t u32UserFlashConfig,
                                              Fapi_FlashStateCommandsType oCommand);

extern Fapi_StatusType Fapi_issueBankEraseCommand(uint32_t *pu32StartAddress, uint8_t u8Iterator,
                                                  uint32_t u32UserFlashConfig);

/* Info Commands */
extern Fapi_LibraryInfoType Fapi_getLibraryInfo(void);

/* Init */
extern Fapi_StatusType Fapi_initializeAPI(Fapi_FmcRegistersType *poFlashControlRegister, uint32_t u32HclkFrequency);

/* Read commands */
extern Fapi_StatusType Fapi_doBlankCheck(uint32_t *pu32StartAddress, uint32_t u32Length,
                                         Fapi_FlashStatusWordType *poFlashStatusWord, uint8_t u8Iterator,
                                         uint32_t u32UserFlashConfig);

extern Fapi_StatusType Fapi_doVerify(uint32_t *pu32StartAddress, uint32_t u32Length, uint32_t *pu32CheckValueBuffer,
                                     Fapi_FlashStatusWordType *poFlashStatusWord, uint8_t u8Iterator,
                                     uint32_t u32UserFlashConfig);

extern Fapi_StatusType Fapi_doVerifyByByte(uint8_t *pu8StartAddress, uint32_t u32Length, uint8_t *pu8CheckValueBuffer,
                                           Fapi_FlashStatusWordType *poFlashStatusWord, uint8_t u8Iterator,
                                           uint32_t u32UserFlashConfig);

/* Programming Commands */
extern Fapi_StatusType Fapi_issueProgrammingCommand(uint32_t *pu32StartAddress, uint8_t *pu8DataBuffer,
                                                    uint8_t u8DataBufferSizeInBytes, uint8_t *pu8EccBuffer,
                                                    uint8_t                           u8EccBufferSizeInBytes,
                                                    Fapi_FlashProgrammingCommandsType oMode,
                                                    uint32_t                          u32UserFlashConfig);

extern Fapi_StatusType Fapi_issueDataOnly512ProgrammingCommand(uint32_t *pu32StartAddress, uint8_t *pu8DataBuffer,
                                                               uint8_t  u8DataBufferSizeInBytes,
                                                               uint32_t u32UserFlashConfig, uint8_t u8Iterator);

extern Fapi_StatusType Fapi_issueAutoEcc512ProgrammingCommand(uint32_t *pu32StartAddress, uint8_t *pu8DataBuffer,
                                                              uint8_t  u8DataBufferSizeInWords,
                                                              uint32_t u32UserFlashConfig, uint8_t u8Iterator);

extern Fapi_StatusType Fapi_issueDataAndEcc512ProgrammingCommand(uint32_t *pu32StartAddress, uint8_t *pu8DataBuffer,
                                                                 uint8_t u8DataBufferSizeInWords, uint8_t *pu8EccBuffer,
                                                                 uint8_t  u8EccBufferSizeInBytes,
                                                                 uint32_t u32UserFlashConfig, uint8_t u8Iterator);

extern Fapi_StatusType Fapi_issueEccOnly64ProgrammingCommand(uint32_t *pu32StartAddress, uint8_t *pu8EccBuffer,
                                                             uint8_t  u8EccBufferSizeInBytes,
                                                             uint32_t u32UserFlashConfig, uint8_t u8Iterator);

extern Fapi_StatusType Fapi_issueProgrammingCommandForEccAddresses(uint32_t *pu32StartAddress, uint8_t *pu8EccBuffer,
                                                                   uint8_t u8EccBufferSizeInBytes);

/* Utility Commands */
extern uint8_t Fapi_calculateEcc(uint32_t *pu32Address, uint64_t *pu64Data, uint8_t u8Iterator);

extern Fapi_StatusType Write_32bp(uint32_t reg_offset, uint32_t mask, uint32_t shift, uint32_t value);

extern Fapi_StatusType Write_32(uint32_t ctrlBase, uint32_t reg_offset, uint32_t mask, uint32_t shift, uint32_t value);

extern Fapi_StatusType Fapi_regReadback(uint32_t u32FLCid, uint32_t reg_offset, uint32_t readback_value);

extern uint32_t Fapi_getUserConfiguration(Fapi_FlashBankType BankType, Fapi_FOTAStatus FOTAStatus);

extern Fapi_StatusType Fapi_SetFlashCPUConfiguration(Fapi_BankMode u32BankModeValue);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*
 * Mark the end of the C bindings section for C++ compilers.
 */
#ifdef __cplusplus
}
#endif

#endif /* F65_F29H85x_C29X_H_ */
/*********************************************************************************************************************
 *  End of File: FlashTech_F29H85x_C29x.h
 *********************************************************************************************************************/
