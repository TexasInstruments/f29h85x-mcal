//###########################################################################
//
// FILE:    hw_tmu.h
//
// TITLE:   Definitions for the TMU registers.
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

#ifndef HW_TMU_H
#define HW_TMU_H

//*************************************************************************************************
//
// The following are defines for the TMU register offsets
//
//*************************************************************************************************
#define TMU_O_REVISION             0x0U     // IP revision id register
#define TMU_O_SINPUF32_R0          0x20U    // Updates operand 1 for SINPUF32 operation
#define TMU_O_SINPUF32_R1          0x24U    // Updates operand 1 for SINPUF32 operation
#define TMU_O_SINPUF32_R2          0x28U    // Updates operand 1 for SINPUF32 operation
#define TMU_O_SINPUF32_R3          0x2CU    // Updates operand 1 for SINPUF32 operation
#define TMU_O_SINPUF32_R4          0x30U    // Updates operand 1 for SINPUF32 operation
#define TMU_O_SINPUF32_R5          0x34U    // Updates operand 1 for SINPUF32 operation
#define TMU_O_SINPUF32_R6          0x38U    // Updates operand 1 for SINPUF32 operation
#define TMU_O_SINPUF32_R7          0x3CU    // Updates operand 1 for SINPUF32 operation
#define TMU_O_COSPUF32_R0          0x40U    // Updates operand 1 for COSPUF32 operation
#define TMU_O_COSPUF32_R1          0x44U    // Updates operand 1 for COSPUF32 operation
#define TMU_O_COSPUF32_R2          0x48U    // Updates operand 1 for COSPUF32 operation
#define TMU_O_COSPUF32_R3          0x4CU    // Updates operand 1 for COSPUF32 operation
#define TMU_O_COSPUF32_R4          0x50U    // Updates operand 1 for COSPUF32 operation
#define TMU_O_COSPUF32_R5          0x54U    // Updates operand 1 for COSPUF32 operation
#define TMU_O_COSPUF32_R6          0x58U    // Updates operand 1 for COSPUF32 operation
#define TMU_O_COSPUF32_R7          0x5CU    // Updates operand 1 for COSPUF32 operation
#define TMU_O_ATANPUF32_R0         0x60U    // Updates operand 1 for ATANPUF32 operation
#define TMU_O_ATANPUF32_R1         0x64U    // Updates operand 1 for ATANPUF32 operation
#define TMU_O_ATANPUF32_R2         0x68U    // Updates operand 1 for ATANPUF32 operation
#define TMU_O_ATANPUF32_R3         0x6CU    // Updates operand 1 for ATANPUF32 operation
#define TMU_O_ATANPUF32_R4         0x70U    // Updates operand 1 for ATANPUF32 operation
#define TMU_O_ATANPUF32_R5         0x74U    // Updates operand 1 for ATANPUF32 operation
#define TMU_O_ATANPUF32_R6         0x78U    // Updates operand 1 for ATANPUF32 operation
#define TMU_O_ATANPUF32_R7         0x7CU    // Updates operand 1 for ATANPUF32 operation
#define TMU_O_SQRTF32_R0           0x80U    // Updates operand 1 for SQRTF32 operation
#define TMU_O_SQRTF32_R1           0x84U    // Updates operand 1 for SQRTF32 operation
#define TMU_O_SQRTF32_R2           0x88U    // Updates operand 1 for SQRTF32 operation
#define TMU_O_SQRTF32_R3           0x8CU    // Updates operand 1 for SQRTF32 operation
#define TMU_O_SQRTF32_R4           0x90U    // Updates operand 1 for SQRTF32 operation
#define TMU_O_SQRTF32_R5           0x94U    // Updates operand 1 for SQRTF32 operation
#define TMU_O_SQRTF32_R6           0x98U    // Updates operand 1 for SQRTF32 operation
#define TMU_O_SQRTF32_R7           0x9CU    // Updates operand 1 for SQRTF32 operation
#define TMU_O_IEXP2F32_R0          0xA0U    // Updates operand 1 for IEXP2F32 operation
#define TMU_O_IEXP2F32_R1          0xA4U    // Updates operand 1 for IEXP2F32 operation
#define TMU_O_IEXP2F32_R2          0xA8U    // Updates operand 1 for IEXP2F32 operation
#define TMU_O_IEXP2F32_R3          0xACU    // Updates operand 1 for IEXP2F32 operation
#define TMU_O_IEXP2F32_R4          0xB0U    // Updates operand 1 for IEXP2F32 operation
#define TMU_O_IEXP2F32_R5          0xB4U    // Updates operand 1 for IEXP2F32 operation
#define TMU_O_IEXP2F32_R6          0xB8U    // Updates operand 1 for IEXP2F32 operation
#define TMU_O_IEXP2F32_R7          0xBCU    // Updates operand 1 for IEXP2F32 operation
#define TMU_O_LOG2F32_R0           0xC0U    // Updates operand 1 for LOG2F32 operation
#define TMU_O_LOG2F32_R1           0xC4U    // Updates operand 1 for LOG2F32 operation
#define TMU_O_LOG2F32_R2           0xC8U    // Updates operand 1 for LOG2F32 operation
#define TMU_O_LOG2F32_R3           0xCCU    // Updates operand 1 for LOG2F32 operation
#define TMU_O_LOG2F32_R4           0xD0U    // Updates operand 1 for LOG2F32 operation
#define TMU_O_LOG2F32_R5           0xD4U    // Updates operand 1 for LOG2F32 operation
#define TMU_O_LOG2F32_R6           0xD8U    // Updates operand 1 for LOG2F32 operation
#define TMU_O_LOG2F32_R7           0xDCU    // Updates operand 1 for LOG2F32 operation
#define TMU_O_QUADF32_X_R0_R1      0xE0U    // Updates operand 1 for QUADF32 operation
#define TMU_O_QUADF32_X_R1_R2      0xE4U    // Updates operand 1 for QUADF32 operation
#define TMU_O_QUADF32_X_R2_R3      0xE8U    // Updates operand 1 for QUADF32 operation
#define TMU_O_QUADF32_X_R3_R4      0xECU    // Updates operand 1 for QUADF32 operation
#define TMU_O_QUADF32_X_R4_R5      0xF0U    // Updates operand 1 for QUADF32 operation
#define TMU_O_QUADF32_X_R5_R6      0xF4U    // Updates operand 1 for QUADF32 operation
#define TMU_O_QUADF32_X_R6_R7      0xF8U    // Updates operand 1 for QUADF32 operation
#define TMU_O_DIVF32_N_R0          0x100U   // Updates operand 1 for DIVF32 operation
#define TMU_O_DIVF32_N_R1          0x104U   // Updates operand 1 for DIVF32 operation
#define TMU_O_DIVF32_N_R2          0x108U   // Updates operand 1 for DIVF32 operation
#define TMU_O_DIVF32_N_R3          0x10CU   // Updates operand 1 for DIVF32 operation
#define TMU_O_DIVF32_N_R4          0x110U   // Updates operand 1 for DIVF32 operation
#define TMU_O_DIVF32_N_R5          0x114U   // Updates operand 1 for DIVF32 operation
#define TMU_O_DIVF32_N_R6          0x118U   // Updates operand 1 for DIVF32 operation
#define TMU_O_DIVF32_N_R7          0x11CU   // Updates operand 1 for DIVF32 operation
#define TMU_O_QUADF32_DIVF32_OP2   0x120U   // Updates operand 2 for QUADF32 and DIVF32 operation
#define TMU_O_RESULT_R0            0x140U   // R0 result register
#define TMU_O_RESULT_R1            0x144U   // R1 result register
#define TMU_O_RESULT_R2            0x148U   // R2 result register
#define TMU_O_RESULT_R3            0x14CU   // R3 result register
#define TMU_O_RESULT_R4            0x150U   // R4 result register
#define TMU_O_RESULT_R5            0x154U   // R5 result register
#define TMU_O_RESULT_R6            0x158U   // R6 result register
#define TMU_O_RESULT_R7            0x15CU   // R7 result register
#define TMU_O_CSAVE_R0             0x160U   // Context save of R0 result register
#define TMU_O_CSAVE_R1             0x164U   // Context save of R1 result register
#define TMU_O_CSAVE_R2             0x168U   // Context save of R2 result register
#define TMU_O_CSAVE_R3             0x16CU   // Context save of R3 result register
#define TMU_O_CSAVE_R4             0x170U   // Context save of R4 result register
#define TMU_O_CSAVE_R5             0x174U   // Context save of R5 result register
#define TMU_O_CSAVE_R6             0x178U   // Context save of R6 result register
#define TMU_O_CSAVE_R7             0x17CU   // Context save of R7 result register
#define TMU_O_CSAVE_OP2            0x180U   // Context save of Operarand2 result register
#define TMU_O_CONTEXT_SAVE         0x184U   // Register to initiate context save of result
                                            // registers
#define TMU_O_CONTEXT_RESTORE      0x188U   // Register to initiate context restore of result
                                            // registers
#define TMU_O_STF                  0x1A4U   // TMU status Register
#define TMU_O_PARITY_TEST          0x1C0U   // Enabling the parity test feature
#define TMU_O_LCM_LOCK             0x1C8U   // LCM lock configuration
#define TMU_O_LCM_COMMIT           0x1D0U   // LCM commit configuration


//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define TMU_REVISION_MINOR_S    0U
#define TMU_REVISION_MINOR_M    0x3FU         // Minor Revision Number
#define TMU_REVISION_CUSTOM_S   6U
#define TMU_REVISION_CUSTOM_M   0xC0U         // Custom Module Number
#define TMU_REVISION_MAJOR_S    8U
#define TMU_REVISION_MAJOR_M    0x700U        // Major Revision Number
#define TMU_REVISION_FUNC_S     16U
#define TMU_REVISION_FUNC_M     0xFFF0000U    // Functional Release Number
#define TMU_REVISION_SCHEME_S   30U
#define TMU_REVISION_SCHEME_M   0xC0000000U   // Defines Scheme for Module

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONTEXT_SAVE register
//
//*************************************************************************************************
#define TMU_CONTEXT_SAVE_SAVE   0x1U   // Initiates context save of result registers

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONTEXT_RESTORE register
//
//*************************************************************************************************
#define TMU_CONTEXT_RESTORE_RESTORE   0x1U   // Initiates context restore of result registers

//*************************************************************************************************
//
// The following are defines for the bit fields in the STF register
//
//*************************************************************************************************
#define TMU_STF_LVF         0x1U     // LVF  Status
#define TMU_STF_LUF         0x2U     // LUF Status
#define TMU_STF_LVF_WR_EN   0x100U   // LVF  write enable
#define TMU_STF_LUF_WR_EN   0x200U   // LVF  write enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST register
//
//*************************************************************************************************
#define TMU_PARITY_TEST_TESTEN_S   0U
#define TMU_PARITY_TEST_TESTEN_M   0xFU   // Parity test enable configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the LCM_LOCK register
//
//*************************************************************************************************
#define TMU_LCM_LOCK_PARITY_TEST   0x1U   // Register lock configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the LCM_COMMIT register
//
//*************************************************************************************************
#define TMU_LCM_COMMIT_PARITY_TEST   0x1U   // Register commit configuration



#endif
