//###########################################################################
//
// FILE:    hw_erad.h
//
// TITLE:   Definitions for the ERAD registers.
//
//###########################################################################
// //
//	Copyright: Copyright (C) Texas Instruments Incorporated
//	All rights reserved not granted herein.
//
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//  Redistributions of source code must retain the above copyright 
//  notice, this list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the 
//  documentation and/or other materials provided with the   
//  distribution.
//
//  Neither the name of Texas Instruments Incorporated nor the names of
//  its contributors may be used to endorse or promote products derived
//  from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

//###########################################################################

#ifndef HW_ERAD_H
#define HW_ERAD_H

//*************************************************************************************************
//
// The following are defines for the ERAD register offsets
//
//*************************************************************************************************
#define ERAD_O_GLBL_ERAD_ID                0x0U                       // Debug Peripheral ID
#define ERAD_O_GLBL_EVENT_STAT             0x4U                       // Global Event Status
                                                                      // Register
#define ERAD_O_EBC_OWNER(i)                (0x40U + ((i) * 64U))      // (0 <= i < 8) EBC Owner
                                                                      // Register
#define ERAD_O_EBC_CNTL(i)                 (0x44U + ((i) * 64U))      // (0 <= i < 8) EBC Control
                                                                      // Register
#define ERAD_O_EBC_STATUS(i)               (0x48U + ((i) * 64U))      // (0 <= i < 8) EBC Status
                                                                      // Register
#define ERAD_O_EBC_STATUSCLEAR(i)          (0x4CU + ((i) * 64U))      // (0 <= i < 8) EBC Clear
                                                                      // Register
#define ERAD_O_EBC_REFL(i)                 (0x50U + ((i) * 64U))      // (0 <= i < 8) EBC Reference
                                                                      // Low Register
#define ERAD_O_EBC_REFH(i)                 (0x54U + ((i) * 64U))      // (0 <= i < 8) EBC Reference
                                                                      // High Register
#define ERAD_O_EBC_MASKL(i)                (0x58U + ((i) * 64U))      // (0 <= i < 8) EBC Mask Low
                                                                      // Register
#define ERAD_O_EBC_MASKH(i)                (0x5CU + ((i) * 64U))      // (0 <= i < 8) EBC Mask High
                                                                      // Register
#define ERAD_O_EBC_WP_PC(i)                (0x60U + ((i) * 64U))      // (0 <= i < 8) EBC
                                                                      // Watchpoint PC Register
#define ERAD_O_SEC_OWNER(i)                (0x440U + ((i) * 64U))     // (0 <= i < 4) SEC Owner
                                                                      // Register
#define ERAD_O_SEC_CNTL(i)                 (0x444U + ((i) * 64U))     // (0 <= i < 4) SEC Control
                                                                      // Register
#define ERAD_O_SEC_STATUS(i)               (0x448U + ((i) * 64U))     // (0 <= i < 4) SEC Status
                                                                      // Register
#define ERAD_O_SEC_STATUSCLEAR(i)          (0x44CU + ((i) * 64U))     // (0 <= i < 4) SEC Clear
                                                                      // Register
#define ERAD_O_SEC_REF(i)                  (0x450U + ((i) * 64U))     // (0 <= i < 4) SEC Reference
                                                                      // Register
#define ERAD_O_SEC_INPUT_SEL1(i)           (0x454U + ((i) * 64U))     // (0 <= i < 4) SEC Input
                                                                      // Select Register1
#define ERAD_O_SEC_INPUT_SEL2(i)           (0x458U + ((i) * 64U))     // (0 <= i < 4) SEC Input
                                                                      // Select Register2
#define ERAD_O_SEC_INPUT_COND(i)           (0x45CU + ((i) * 64U))     // (0 <= i < 4) SEC Input
                                                                      // Conditioning Register
#define ERAD_O_SEC_COUNT(i)                (0x460U + ((i) * 64U))     // (0 <= i < 4) SEC Counter
                                                                      // Register
#define ERAD_O_SEC_MAX_COUNT(i)            (0x464U + ((i) * 64U))     // (0 <= i < 4) SEC Max Count
                                                                      // Register
#define ERAD_O_SEC_MIN_COUNT(i)            (0x468U + ((i) * 64U))     // (0 <= i < 4) SEC Min Count
                                                                      // Register
#define ERAD_O_AND_MASK_OWNER(i)           (0x640U + ((i) * 32U))     // (0 <= i < 4) AND Owner
                                                                      // Register
#define ERAD_O_AND_MASK_CTL(i)             (0x644U + ((i) * 32U))     // (0 <= i < 4) AND Control
                                                                      // Register
#define ERAD_O_EVENT_AND_MASK(i)           (0x648U + ((i) * 32U))     // (0 <= i < 4) AND Event
                                                                      // Selection Register
#define ERAD_O_OR_MASK_OWNER(i)            (0x740U + ((i) * 32U))     // (0 <= i < 4) OR Owner
                                                                      // Register
#define ERAD_O_OR_MASK_CTL(i)              (0x744U + ((i) * 32U))     // (0 <= i < 4) OR Control
                                                                      // Register
#define ERAD_O_EVENT_OR_MASK(i)            (0x748U + ((i) * 32U))     // (0 <= i < 4) OR Event
                                                                      // Selection Register
#define ERAD_O_PCTRACE_OWNER               0x840U                     // Owner Register
#define ERAD_O_PCTRACE_GLOBAL              0x844U                     // Global Control Register
#define ERAD_O_PCTRACE_BUFFER              0x848U                     // Trace Buffer pointer
                                                                      // register
#define ERAD_O_PCTRACE_QUAL1               0x84CU                     // Trace Qualifier register 1
#define ERAD_O_PCTRACE_QUAL2               0x850U                     // Trace Qualifier register 2
#define ERAD_O_PCTRACE_LOGPC_SOFTENABLE    0x854U                     // PC when PC Trace was last
                                                                      // enabled by software
#define ERAD_O_PCTRACE_LOGPC_SOFTDISABLE   0x858U                     // PC when PC Trace was last
                                                                      // disabled by software
#define ERAD_O_PCTRACE_BUFFER_BASE(i)      (0x1000U + ((i) * 0x4U))   // (0 <= i < 256) Trace
                                                                      // Buffer Base address


//*************************************************************************************************
//
// The following are defines for the bit fields in the GLBL_ERAD_ID register
//
//*************************************************************************************************
#define ERAD_GLBL_ERAD_ID_MINOR_S    0U
#define ERAD_GLBL_ERAD_ID_MINOR_M    0x3FU        // Minor
#define ERAD_GLBL_ERAD_ID_CUSTOM_S   6U
#define ERAD_GLBL_ERAD_ID_CUSTOM_M   0xC0U        // Custom
#define ERAD_GLBL_ERAD_ID_MAJOR_S    8U
#define ERAD_GLBL_ERAD_ID_MAJOR_M    0x700U       // Major
#define ERAD_GLBL_ERAD_ID_FUNC_S     16U
#define ERAD_GLBL_ERAD_ID_FUNC_M     0xFFF0000U   // Func

//*************************************************************************************************
//
// The following are defines for the bit fields in the GLBL_EVENT_STAT register
//
//*************************************************************************************************
#define ERAD_GLBL_EVENT_STAT_EBC_S   0U
#define ERAD_GLBL_EVENT_STAT_EBC_M   0xFFFFU       // EBC Module Event Status
#define ERAD_GLBL_EVENT_STAT_SEC_S   16U
#define ERAD_GLBL_EVENT_STAT_SEC_M   0xFFFF0000U   // SEC Module Event Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the EBC_OWNER register
//
//*************************************************************************************************
#define ERAD_EBC_OWNER_OWNER_S    0U
#define ERAD_EBC_OWNER_OWNER_M    0x3U       // Ownership ID
#define ERAD_EBC_OWNER_ZONE_S     8U
#define ERAD_EBC_OWNER_ZONE_M     0xF00U     // Zone ID
#define ERAD_EBC_OWNER_SROOT      0x1000U    // SROOT LINK ownership
#define ERAD_EBC_OWNER_SEM        0x10000U   // Semaphore
#define ERAD_EBC_OWNER_CONFIG_S   17U
#define ERAD_EBC_OWNER_CONFIG_M   0x60000U   // Configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the EBC_CNTL register
//
//*************************************************************************************************
#define ERAD_EBC_CNTL_EN               0x1U       // Enable
#define ERAD_EBC_CNTL_BUS_SEL_S        1U
#define ERAD_EBC_CNTL_BUS_SEL_M        0x3EU      // Bus select bits
#define ERAD_EBC_CNTL_HALT             0x40U      // CPU Halt
#define ERAD_EBC_CNTL_INTERRUPT        0x80U      // Interrupt enable
#define ERAD_EBC_CNTL_NMI_EN           0x100U     // NMI enable
#define ERAD_EBC_CNTL_COMP_MODE_S      9U
#define ERAD_EBC_CNTL_COMP_MODE_M      0xE00U     // Compare mode
#define ERAD_EBC_CNTL_STACK_QUAL       0x1000U    // Stack access qualifier
#define ERAD_EBC_CNTL_SPSEL_MATCH_EN   0x2000U    // SPSEL match enable
#define ERAD_EBC_CNTL_SPSEL_S          14U
#define ERAD_EBC_CNTL_SPSEL_M          0x3C000U   // SPSEL

//*************************************************************************************************
//
// The following are defines for the bit fields in the EBC_STATUS register
//
//*************************************************************************************************
#define ERAD_EBC_STATUS_EVENT_FIRED   0x1U     // EBC Event Fired bits
#define ERAD_EBC_STATUS_STATUS_S      8U
#define ERAD_EBC_STATUS_STATUS_M      0x300U   // Status bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the EBC_STATUSCLEAR register
//
//*************************************************************************************************
#define ERAD_EBC_STATUSCLEAR_EVENT_FIRED   0x1U   // Event Clear register

//*************************************************************************************************
//
// The following are defines for the bit fields in the SEC_OWNER register
//
//*************************************************************************************************
#define ERAD_SEC_OWNER_OWNER_S    0U
#define ERAD_SEC_OWNER_OWNER_M    0x3U       // Ownership ID
#define ERAD_SEC_OWNER_ZONE_S     8U
#define ERAD_SEC_OWNER_ZONE_M     0xF00U     // Zone ID
#define ERAD_SEC_OWNER_SROOT      0x1000U    // SROOT LINK ownership
#define ERAD_SEC_OWNER_SEM        0x10000U   // Semaphore
#define ERAD_SEC_OWNER_CONFIG_S   17U
#define ERAD_SEC_OWNER_CONFIG_M   0x60000U   // Configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SEC_CNTL register
//
//*************************************************************************************************
#define ERAD_SEC_CNTL_EN                      0x1U     // Enable
#define ERAD_SEC_CNTL_EDGE_LEVEL              0x2U     // Event mode bit
#define ERAD_SEC_CNTL_START_STOP_MODE         0x4U     // Start_stop mode bit
#define ERAD_SEC_CNTL_START_STOP_CUMULATIVE   0x8U     // Start stop cumulative bit
#define ERAD_SEC_CNTL_RST_ON_MATCH            0x10U    // Reset_on_match bit
#define ERAD_SEC_CNTL_HALT                    0x20U    // CPU Halt
#define ERAD_SEC_CNTL_INTERRUPT               0x40U    // Interrupt enable
#define ERAD_SEC_CNTL_NMI_EN                  0x80U    // NMI enable
#define ERAD_SEC_CNTL_CNT_INP_SEL_EN          0x100U   // Counter input select enable
#define ERAD_SEC_CNTL_RST_INP_SEL_EN          0x200U   // Counter reset input select enable
#define ERAD_SEC_CNTL_FREE_RUN                0x400U   // counter behaviour on CPU Halt

//*************************************************************************************************
//
// The following are defines for the bit fields in the SEC_STATUS register
//
//*************************************************************************************************
#define ERAD_SEC_STATUS_EVENT_FIRED   0x1U     // Counter Event Fired bits
#define ERAD_SEC_STATUS_OVERFLOW      0x2U     // Counter Overflowed
#define ERAD_SEC_STATUS_STATUS_S      8U
#define ERAD_SEC_STATUS_STATUS_M      0x300U   // Status bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the SEC_STATUSCLEAR register
//
//*************************************************************************************************
#define ERAD_SEC_STATUSCLEAR_EVENT_FIRED   0x1U   // Clear EVENT_FIRED
#define ERAD_SEC_STATUSCLEAR_OVERFLOW      0x2U   // Clear OVERFLOW

//*************************************************************************************************
//
// The following are defines for the bit fields in the SEC_INPUT_SEL1 register
//
//*************************************************************************************************
#define ERAD_SEC_INPUT_SEL1_CNT_INP_SEL_S   0U
#define ERAD_SEC_INPUT_SEL1_CNT_INP_SEL_M   0xFFU       // Counter Input Select
#define ERAD_SEC_INPUT_SEL1_RST_INP_SEL_S   16U
#define ERAD_SEC_INPUT_SEL1_RST_INP_SEL_M   0xFF0000U   // Counter Reset input Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the SEC_INPUT_SEL2 register
//
//*************************************************************************************************
#define ERAD_SEC_INPUT_SEL2_STA_INP_SEL_S   0U
#define ERAD_SEC_INPUT_SEL2_STA_INP_SEL_M   0xFFU       // Counter Sart Input Select
#define ERAD_SEC_INPUT_SEL2_STO_INP_SEL_S   16U
#define ERAD_SEC_INPUT_SEL2_STO_INP_SEL_M   0xFF0000U   // Counter Stop Input Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the SEC_INPUT_COND register
//
//*************************************************************************************************
#define ERAD_SEC_INPUT_COND_SEC_INP_INV   0x1U      // Counter Input Invert
#define ERAD_SEC_INPUT_COND_STA_INP_INV   0x10U     // Start input Invert
#define ERAD_SEC_INPUT_COND_STO_INP_INV   0x100U    // Stop input Invert
#define ERAD_SEC_INPUT_COND_RST_INP_INV   0x1000U   // Reset input Invert

//*************************************************************************************************
//
// The following are defines for the bit fields in the AND_MASK_OWNER register
//
//*************************************************************************************************
#define ERAD_AND_MASK_OWNER_OWNER_S   0U
#define ERAD_AND_MASK_OWNER_OWNER_M   0x3U       // Ownership ID
#define ERAD_AND_MASK_OWNER_ZONE_S    8U
#define ERAD_AND_MASK_OWNER_ZONE_M    0xF00U     // Zone ID
#define ERAD_AND_MASK_OWNER_SROOT     0x1000U    // SROOT LINK ownership
#define ERAD_AND_MASK_OWNER_SEM       0x10000U   // Semaphore

//*************************************************************************************************
//
// The following are defines for the bit fields in the AND_MASK_CTL register
//
//*************************************************************************************************
#define ERAD_AND_MASK_CTL_HALT        0x1U   // CPU Halt
#define ERAD_AND_MASK_CTL_INTERRUPT   0x2U   // Interrupt enable
#define ERAD_AND_MASK_CTL_NMI_EN      0x4U   // NMI enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the EVENT_AND_MASK register
//
//*************************************************************************************************
#define ERAD_EVENT_AND_MASK_MASK_EBC_S   0U
#define ERAD_EVENT_AND_MASK_MASK_EBC_M   0xFFFFFFU   // EBC, SEC AND Event Mask

//*************************************************************************************************
//
// The following are defines for the bit fields in the OR_MASK_OWNER register
//
//*************************************************************************************************
#define ERAD_OR_MASK_OWNER_OWNER_S   0U
#define ERAD_OR_MASK_OWNER_OWNER_M   0x3U       // Ownership ID
#define ERAD_OR_MASK_OWNER_ZONE_S    8U
#define ERAD_OR_MASK_OWNER_ZONE_M    0xF00U     // Zone ID
#define ERAD_OR_MASK_OWNER_SROOT     0x1000U    // SROOT LINK ownership
#define ERAD_OR_MASK_OWNER_SEM       0x10000U   // Semaphore

//*************************************************************************************************
//
// The following are defines for the bit fields in the OR_MASK_CTL register
//
//*************************************************************************************************
#define ERAD_OR_MASK_CTL_HALT        0x1U   // CPU Halt
#define ERAD_OR_MASK_CTL_INTERRUPT   0x2U   // Interrupt enable
#define ERAD_OR_MASK_CTL_NMI_EN      0x4U   // NMI enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the EVENT_OR_MASK register
//
//*************************************************************************************************
#define ERAD_EVENT_OR_MASK_MASK_EBC_S   0U
#define ERAD_EVENT_OR_MASK_MASK_EBC_M   0xFFFFFFU   // EBC, SEC OR Event Mask

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCTRACE_OWNER register
//
//*************************************************************************************************
#define ERAD_PCTRACE_OWNER_OWNER_S   0U
#define ERAD_PCTRACE_OWNER_OWNER_M   0x3U       // Ownership ID
#define ERAD_PCTRACE_OWNER_ZONE_S    8U
#define ERAD_PCTRACE_OWNER_ZONE_M    0xF00U     // Zone ID
#define ERAD_PCTRACE_OWNER_SROOT     0x1000U    // SROOT LINK ownership
#define ERAD_PCTRACE_OWNER_SEM       0x10000U   // Semaphore

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCTRACE_GLOBAL register
//
//*************************************************************************************************
#define ERAD_PCTRACE_GLOBAL_EN              0x1U       // Enable PC  trace
#define ERAD_PCTRACE_GLOBAL_INIT            0x100U     // Initialize the PC Trace and buffer
                                                       // pointer
#define ERAD_PCTRACE_GLOBAL_BUFFER_SIZE_S   16U
#define ERAD_PCTRACE_GLOBAL_BUFFER_SIZE_M   0x30000U   // Trace buffer size

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCTRACE_BUFFER register
//
//*************************************************************************************************
#define ERAD_PCTRACE_BUFFER_PTR_S         0U
#define ERAD_PCTRACE_BUFFER_PTR_M         0xFFFFU    // Trace Buffer Pointer
#define ERAD_PCTRACE_BUFFER_BUFFER_FULL   0x10000U   // Trace Buffer Full

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCTRACE_QUAL1 register
//
//*************************************************************************************************
#define ERAD_PCTRACE_QUAL1_WINDOWED_INP_SEL_S   0U
#define ERAD_PCTRACE_QUAL1_WINDOWED_INP_SEL_M   0xFFU       // Windowed trace qualifier
#define ERAD_PCTRACE_QUAL1_TRACE_MODE_S         16U
#define ERAD_PCTRACE_QUAL1_TRACE_MODE_M         0x30000U    // Trace qualifier mode
#define ERAD_PCTRACE_QUAL1_WINDOWED_INP_INV     0x40000U    // Windowed trace Input Invert
#define ERAD_PCTRACE_QUAL1_START_INP_INV        0x100000U   // Start input Invert
#define ERAD_PCTRACE_QUAL1_STOP_INP_INV         0x400000U   // Stop input Invert

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCTRACE_QUAL2 register
//
//*************************************************************************************************
#define ERAD_PCTRACE_QUAL2_START_INP_SEL_S   0U
#define ERAD_PCTRACE_QUAL2_START_INP_SEL_M   0xFFU       // Trace Start event select
#define ERAD_PCTRACE_QUAL2_STOP_INP_SEL_S    16U
#define ERAD_PCTRACE_QUAL2_STOP_INP_SEL_M    0xFF0000U   // Trace Stop event select

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCTRACE_BUFFER_BASE register
//
//*************************************************************************************************
#define ERAD_PCTRACE_BUFFER_BASE_BLOCKED             0x1U          // Access blocked due to
                                                                   // security
#define ERAD_PCTRACE_BUFFER_BASE_PROGRAM_COUNTER_S   1U
#define ERAD_PCTRACE_BUFFER_BASE_PROGRAM_COUNTER_M   0xFFFFFFFEU   // Program Counter



#endif
