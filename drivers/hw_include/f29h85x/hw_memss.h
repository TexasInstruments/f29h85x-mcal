//###########################################################################
//
// FILE:    hw_memss.h
//
// TITLE:   Definitions for the MEMSS registers.
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

#ifndef HW_MEMSS_H
#define HW_MEMSS_H

//*************************************************************************************************
//
// The following are defines for the MEMSS register offsets
//
//*************************************************************************************************
#define MEMSS_O_LPA0_MEM_CONFIG          0x0U    // LPA0 Memory Configuration Register
#define MEMSS_O_LPA0_MEM_CONFIG_LOCK     0x4U    // Temporary Lock for LPA0 Memory Configuration
                                                 // Register
#define MEMSS_O_LPA0_MEM_CONFIG_COMMIT   0x8U    // Permament Lock for LPA0 Memory Configuration
                                                 // Register
#define MEMSS_O_LPA1_MEM_CONFIG          0x10U   // LPA1 Memory Configuration Register
#define MEMSS_O_LPA1_MEM_CONFIG_LOCK     0x14U   // Temporary Lock for LPA1 Memory Configuration
                                                 // Register
#define MEMSS_O_LPA1_MEM_CONFIG_COMMIT   0x18U   // Permament Lock for LPA1 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA0_MEM_CONFIG          0x20U   // LDA0 Memory Configuration Register
#define MEMSS_O_LDA0_MEM_CONFIG_LOCK     0x24U   // Temporary Lock for LDA0 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA0_MEM_CONFIG_COMMIT   0x28U   // Permament Lock for LDA0 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA1_MEM_CONFIG          0x30U   // LDA1 Memory Configuration Register
#define MEMSS_O_LDA1_MEM_CONFIG_LOCK     0x34U   // Temporary Lock for LDA1 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA1_MEM_CONFIG_COMMIT   0x38U   // Permament Lock for LDA1 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA2_MEM_CONFIG          0x40U   // LDA2 Memory Configuration Register
#define MEMSS_O_LDA2_MEM_CONFIG_LOCK     0x44U   // Temporary Lock for LDA2 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA2_MEM_CONFIG_COMMIT   0x48U   // Permament Lock for LDA2 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA3_MEM_CONFIG          0x50U   // LDA3 Memory Configuration Register
#define MEMSS_O_LDA3_MEM_CONFIG_LOCK     0x54U   // Temporary Lock for LDA3 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA3_MEM_CONFIG_COMMIT   0x58U   // Permament Lock for LDA3 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA4_MEM_CONFIG          0x60U   // LDA4 Memory Configuration Register
#define MEMSS_O_LDA4_MEM_CONFIG_LOCK     0x64U   // Temporary Lock for LDA4 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA4_MEM_CONFIG_COMMIT   0x68U   // Permament Lock for LDA4 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA5_MEM_CONFIG          0x70U   // LDA5 Memory Configuration Register
#define MEMSS_O_LDA5_MEM_CONFIG_LOCK     0x74U   // Temporary Lock for LDA5 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA5_MEM_CONFIG_COMMIT   0x78U   // Permament Lock for LDA5 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA6_MEM_CONFIG          0x80U   // LDA6 Memory Configuration Register
#define MEMSS_O_LDA6_MEM_CONFIG_LOCK     0x84U   // Temporary Lock for LDA6 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA6_MEM_CONFIG_COMMIT   0x88U   // Permament Lock for LDA6 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA7_MEM_CONFIG          0x90U   // LDA7 Memory Configuration Register
#define MEMSS_O_LDA7_MEM_CONFIG_LOCK     0x94U   // Temporary Lock for LDA7 Memory Configuration
                                                 // Register
#define MEMSS_O_LDA7_MEM_CONFIG_COMMIT   0x98U   // Permament Lock for LDA7 Memory Configuration
                                                 // Register

#define MEMSS_O_CPA0_MEM_CONFIG           0x0U    // CPA0 Memory Configuration Register
#define MEMSS_O_CPA0_MEM_CONFIG_LOCK      0x4U    // Temporary Lock for CPA0 Memory Configuration
                                                  // Register
#define MEMSS_O_CPA0_MEM_CONFIG_COMMIT    0x8U    // Permament Lock for CPA0 Memory Configuration
                                                  // Register
#define MEMSS_O_CPA1_MEM_CONFIG           0x10U   // CPA1 Memory Configuration Register
#define MEMSS_O_CPA1_MEM_CONFIG_LOCK      0x14U   // Temporary Lock for CPA1 Memory Configuration
                                                  // Register
#define MEMSS_O_CPA1_MEM_CONFIG_COMMIT    0x18U   // Permament Lock for CPA1 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA0_MEM_CONFIG           0x20U   // CDA0 Memory Configuration Register
#define MEMSS_O_CDA0_MEM_CONFIG_LOCK      0x24U   // Temporary Lock for CDA0 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA0_MEM_CONFIG_COMMIT    0x28U   // Permament Lock for CDA0 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA1_MEM_CONFIG           0x30U   // CDA1 Memory Configuration Register
#define MEMSS_O_CDA1_MEM_CONFIG_LOCK      0x34U   // Temporary Lock for CDA1 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA1_MEM_CONFIG_COMMIT    0x38U   // Permament Lock for CDA1 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA2_MEM_CONFIG           0x40U   // CDA2 Memory Configuration Register
#define MEMSS_O_CDA2_MEM_CONFIG_LOCK      0x44U   // Temporary Lock for CDA2 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA2_MEM_CONFIG_COMMIT    0x48U   // Permament Lock for CDA2 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA3_MEM_CONFIG           0x50U   // CDA3 Memory Configuration Register
#define MEMSS_O_CDA3_MEM_CONFIG_LOCK      0x54U   // Temporary Lock for CDA3 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA3_MEM_CONFIG_COMMIT    0x58U   // Permament Lock for CDA3 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA4_MEM_CONFIG           0x60U   // CDA4 Memory Configuration Register
#define MEMSS_O_CDA4_MEM_CONFIG_LOCK      0x64U   // Temporary Lock for CDA4 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA4_MEM_CONFIG_COMMIT    0x68U   // Permament Lock for CDA4 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA5_MEM_CONFIG           0x70U   // CDA5 Memory Configuration Register
#define MEMSS_O_CDA5_MEM_CONFIG_LOCK      0x74U   // Temporary Lock for CDA5 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA5_MEM_CONFIG_COMMIT    0x78U   // Permament Lock for CDA5 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA6_MEM_CONFIG           0x80U   // CDA6 Memory Configuration Register
#define MEMSS_O_CDA6_MEM_CONFIG_LOCK      0x84U   // Temporary Lock for CDA6 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA6_MEM_CONFIG_COMMIT    0x88U   // Permament Lock for CDA6 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA7_MEM_CONFIG           0x90U   // CDA7 Memory Configuration Register
#define MEMSS_O_CDA7_MEM_CONFIG_LOCK      0x94U   // Temporary Lock for CDA7 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA7_MEM_CONFIG_COMMIT    0x98U   // Permament Lock for CDA7 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA8_MEM_CONFIG           0xA0U   // CDA8 Memory Configuration Register
#define MEMSS_O_CDA8_MEM_CONFIG_LOCK      0xA4U   // Temporary Lock for CDA8 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA8_MEM_CONFIG_COMMIT    0xA8U   // Permament Lock for CDA8 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA9_MEM_CONFIG           0xB0U   // CDA9 Memory Configuration Register
#define MEMSS_O_CDA9_MEM_CONFIG_LOCK      0xB4U   // Temporary Lock for CDA9 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA9_MEM_CONFIG_COMMIT    0xB8U   // Permament Lock for CDA9 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA10_MEM_CONFIG          0xC0U   // CDA10 Memory Configuration Register
#define MEMSS_O_CDA10_MEM_CONFIG_LOCK     0xC4U   // Temporary Lock for CDA10 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA10_MEM_CONFIG_COMMIT   0xC8U   // Permament Lock for CDA10 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA11_MEM_CONFIG          0xD0U   // CDA11 Memory Configuration Register
#define MEMSS_O_CDA11_MEM_CONFIG_LOCK     0xD4U   // Temporary Lock for CDA11 Memory Configuration
                                                  // Register
#define MEMSS_O_CDA11_MEM_CONFIG_COMMIT   0xD8U   // Permament Lock for CDA11 Memory Configuration
                                                  // Register

#define MEMSS_O_M0_MEM_CONFIG          0x0U   // M0 Memory Configuration Register
#define MEMSS_O_M0_MEM_CONFIG_LOCK     0x4U   // Temporary Lock for M0 Memory Configuration
                                              // Register
#define MEMSS_O_M0_MEM_CONFIG_COMMIT   0x8U   // Permament Lock for M0 Memory Configuration
                                              // Register

#define MEMSS_O_CPU1_ROM_CONFIG          0x0U    // CPU1 ROM Configuration Register
#define MEMSS_O_CPU1_ROM_CONFIG_LOCK     0x4U    // Temporary Lock for CPU1 ROM Memory
                                                 // Configuration Register
#define MEMSS_O_CPU1_ROM_CONFIG_COMMIT   0x8U    // Permament Lock for CPU1 ROM Memory
                                                 // Configuration Register
#define MEMSS_O_CPU2_ROM_CONFIG          0x10U   // CPU2 ROM Configuration Register
#define MEMSS_O_CPU2_ROM_CONFIG_LOCK     0x14U   // Temporary Lock for CPU2 ROM Memory
                                                 // Configuration Register
#define MEMSS_O_CPU2_ROM_CONFIG_COMMIT   0x18U   // Permament Lock for CPU2 ROM Memory
                                                 // Configuration Register
#define MEMSS_O_CPU3_ROM_CONFIG          0x20U   // CPU3 ROM Configuration Register
#define MEMSS_O_CPU3_ROM_CONFIG_LOCK     0x24U   // Temporary Lock for CPU3 ROM Memory
                                                 // Configuration Register
#define MEMSS_O_CPU3_ROM_CONFIG_COMMIT   0x28U   // Permament Lock for CPU3 ROM Memory
                                                 // Configuration Register

#define MEMSS_O_MEM_DLB_CONFIG          0x0U     // Dataline buffer enable
#define MEMSS_O_MEM_DLB_CONFIG_LOCK     0x4U     // Temporary Lock for DLB Configuration Register
#define MEMSS_O_MEM_DLB_CONFIG_COMMIT   0x8U     // Permament Lock for DLB Configuration Register
#define MEMSS_O_PERI_MEM_TEST_LOCK      0x10U    // Peripheral Memory Test Lock Register
#define MEMSS_O_PERI_MEM_TEST_CONTROL   0x14U    // Peripheral Memory Test control Register
#define MEMSS_O_PARITY_TEST             0x1FCU   // Enabling the parity test feature

#define MEMSS_O_CPU1_ROM_PATCH_REG_LOCK     0x0U     // Temporary Lock for CPU1 ROM PATCH ADDR, ECC
                                                     // and DATA registers
#define MEMSS_O_CPU1_ROM_PATCH_REG_COMMIT   0x4U     // Permament  Lock for CPU1 ROM PATCH ADDR,
                                                     // ECC and DATA registers
#define MEMSS_O_CPU1_0_ADDR                 0x10U    // Address-0 of ROM to be patched
#define MEMSS_O_CPU1_0_ECC                  0x14U    // ECC bits for Address-0 of ROM
#define MEMSS_O_CPU1_0_DATA64_L             0x18U    // Data[31:0] for Address-0
#define MEMSS_O_CPU1_0_DATA64_H             0x1CU    // Data[63:32] for Address-0
#define MEMSS_O_CPU1_1_ADDR                 0x20U    // Address-1 of ROM to be patched
#define MEMSS_O_CPU1_1_ECC                  0x24U    // ECC bits for Address-1 of ROM
#define MEMSS_O_CPU1_1_DATA64_L             0x28U    // Data[31:0] for Address-1
#define MEMSS_O_CPU1_1_DATA64_H             0x2CU    // Data[63:32] for Address-1
#define MEMSS_O_CPU1_2_ADDR                 0x30U    // Address-2 of ROM to be patched
#define MEMSS_O_CPU1_2_ECC                  0x34U    // ECC bits for Address-2 of ROM
#define MEMSS_O_CPU1_2_DATA64_L             0x38U    // Data[31:0] for Address-2
#define MEMSS_O_CPU1_2_DATA64_H             0x3CU    // Data[63:32] for Address-2
#define MEMSS_O_CPU1_3_ADDR                 0x40U    // Address-3 of ROM to be patched
#define MEMSS_O_CPU1_3_ECC                  0x44U    // ECC bits for Address-3 of ROM
#define MEMSS_O_CPU1_3_DATA64_L             0x48U    // Data[31:0] for Address-3
#define MEMSS_O_CPU1_3_DATA64_H             0x4CU    // Data[63:32] for Address-3
#define MEMSS_O_CPU1_4_ADDR                 0x50U    // Address-4 of ROM to be patched
#define MEMSS_O_CPU1_4_ECC                  0x54U    // ECC bits for Address-4 of ROM
#define MEMSS_O_CPU1_4_DATA64_L             0x58U    // Data[31:0] for Address-4
#define MEMSS_O_CPU1_4_DATA64_H             0x5CU    // Data[63:32] for Address-4
#define MEMSS_O_CPU1_5_ADDR                 0x60U    // Address-5 of ROM to be patched
#define MEMSS_O_CPU1_5_ECC                  0x64U    // ECC bits for Address-5 of ROM
#define MEMSS_O_CPU1_5_DATA64_L             0x68U    // Data[31:0] for Address-5
#define MEMSS_O_CPU1_5_DATA64_H             0x6CU    // Data[63:32] for Address-5
#define MEMSS_O_CPU1_6_ADDR                 0x70U    // Address-6 of ROM to be patched
#define MEMSS_O_CPU1_6_ECC                  0x74U    // ECC bits for Address-6 of ROM
#define MEMSS_O_CPU1_6_DATA64_L             0x78U    // Data[31:0] for Address-6
#define MEMSS_O_CPU1_6_DATA64_H             0x7CU    // Data[63:32] for Address-6
#define MEMSS_O_CPU1_7_ADDR                 0x80U    // Address-7 of ROM to be patched
#define MEMSS_O_CPU1_7_ECC                  0x84U    // ECC bits for Address-7 of ROM
#define MEMSS_O_CPU1_7_DATA64_L             0x88U    // Data[31:0] for Address-7
#define MEMSS_O_CPU1_7_DATA64_H             0x8CU    // Data[63:32] for Address-7
#define MEMSS_O_CPU1_8_ADDR                 0x90U    // Address-8 of ROM to be patched
#define MEMSS_O_CPU1_8_ECC                  0x94U    // ECC bits for Address-8 of ROM
#define MEMSS_O_CPU1_8_DATA64_L             0x98U    // Data[31:0] for Address-8
#define MEMSS_O_CPU1_8_DATA64_H             0x9CU    // Data[63:32] for Address-8
#define MEMSS_O_CPU1_9_ADDR                 0xA0U    // Address-9 of ROM to be patched
#define MEMSS_O_CPU1_9_ECC                  0xA4U    // ECC bits for Address-9 of ROM
#define MEMSS_O_CPU1_9_DATA64_L             0xA8U    // Data[31:0] for Address-9
#define MEMSS_O_CPU1_9_DATA64_H             0xACU    // Data[63:32] for Address-9
#define MEMSS_O_CPU1_10_ADDR                0xB0U    // Address-10 of ROM to be patched
#define MEMSS_O_CPU1_10_ECC                 0xB4U    // ECC bits for Address-10 of ROM
#define MEMSS_O_CPU1_10_DATA64_L            0xB8U    // Data[31:0] for Address-10
#define MEMSS_O_CPU1_10_DATA64_H            0xBCU    // Data[63:32] for Address-10
#define MEMSS_O_CPU1_11_ADDR                0xC0U    // Address-11 of ROM to be patched
#define MEMSS_O_CPU1_11_ECC                 0xC4U    // ECC bits for Address-11 of ROM
#define MEMSS_O_CPU1_11_DATA64_L            0xC8U    // Data[31:0] for Address-11
#define MEMSS_O_CPU1_11_DATA64_H            0xCCU    // Data[63:32] for Address-11
#define MEMSS_O_CPU1_12_ADDR                0xD0U    // Address-12 of ROM to be patched
#define MEMSS_O_CPU1_12_ECC                 0xD4U    // ECC bits for Address-12 of ROM
#define MEMSS_O_CPU1_12_DATA64_L            0xD8U    // Data[31:0] for Address-12
#define MEMSS_O_CPU1_12_DATA64_H            0xDCU    // Data[63:32] for Address-12
#define MEMSS_O_CPU1_13_ADDR                0xE0U    // Address-13 of ROM to be patched
#define MEMSS_O_CPU1_13_ECC                 0xE4U    // ECC bits for Address-13 of ROM
#define MEMSS_O_CPU1_13_DATA64_L            0xE8U    // Data[31:0] for Address-13
#define MEMSS_O_CPU1_13_DATA64_H            0xECU    // Data[63:32] for Address-13
#define MEMSS_O_CPU1_14_ADDR                0xF0U    // Address-14 of ROM to be patched
#define MEMSS_O_CPU1_14_ECC                 0xF4U    // ECC bits for Address-14 of ROM
#define MEMSS_O_CPU1_14_DATA64_L            0xF8U    // Data[31:0] for Address-14
#define MEMSS_O_CPU1_14_DATA64_H            0xFCU    // Data[63:32] for Address-14
#define MEMSS_O_CPU1_15_ADDR                0x100U   // Address-15 of ROM to be patched
#define MEMSS_O_CPU1_15_ECC                 0x104U   // ECC bits for Address-15 of ROM
#define MEMSS_O_CPU1_15_DATA64_L            0x108U   // Data[31:0] for Address-15
#define MEMSS_O_CPU1_15_DATA64_H            0x10CU   // Data[63:32] for Address-15


//*************************************************************************************************
//
// The following are defines for the bit fields in the LPA0_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LPA0_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LPA0_MEM_CONFIG_TESTMODE_M   0x3U         // LPA0 Test Mode
#define MEMSS_LPA0_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LPA0_MEM_CONFIG_INIT_STS     0x1000000U   // LPA0 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPA0_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LPA0_MEM_CONFIG_LOCK_LPA0_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPA0_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LPA0_MEM_CONFIG_COMMIT_LPA0_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPA1_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LPA1_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LPA1_MEM_CONFIG_TESTMODE_M   0x3U         // LPA1 Test Mode
#define MEMSS_LPA1_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LPA1_MEM_CONFIG_INIT_STS     0x1000000U   // LPA1 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPA1_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LPA1_MEM_CONFIG_LOCK_LPA1_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPA1_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LPA1_MEM_CONFIG_COMMIT_LPA1_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA0_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LDA0_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LDA0_MEM_CONFIG_TESTMODE_M   0x3U         // LDA0 Test Mode
#define MEMSS_LDA0_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LDA0_MEM_CONFIG_INIT_STS     0x1000000U   // LDA0 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA0_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LDA0_MEM_CONFIG_LOCK_LDA0_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA0_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LDA0_MEM_CONFIG_COMMIT_LDA0_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA1_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LDA1_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LDA1_MEM_CONFIG_TESTMODE_M   0x3U         // LDA1 Test Mode
#define MEMSS_LDA1_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LDA1_MEM_CONFIG_INIT_STS     0x1000000U   // LDA1 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA1_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LDA1_MEM_CONFIG_LOCK_LDA1_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA1_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LDA1_MEM_CONFIG_COMMIT_LDA1_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA2_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LDA2_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LDA2_MEM_CONFIG_TESTMODE_M   0x3U         // LDA2 Test Mode
#define MEMSS_LDA2_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LDA2_MEM_CONFIG_INIT_STS     0x1000000U   // LDA2 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA2_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LDA2_MEM_CONFIG_LOCK_LDA2_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA2_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LDA2_MEM_CONFIG_COMMIT_LDA2_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA3_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LDA3_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LDA3_MEM_CONFIG_TESTMODE_M   0x3U         // LDA3 Test Mode
#define MEMSS_LDA3_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LDA3_MEM_CONFIG_INIT_STS     0x1000000U   // LDA3 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA3_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LDA3_MEM_CONFIG_LOCK_LDA3_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA3_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LDA3_MEM_CONFIG_COMMIT_LDA3_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA4_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LDA4_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LDA4_MEM_CONFIG_TESTMODE_M   0x3U         // LDA4 Test Mode
#define MEMSS_LDA4_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LDA4_MEM_CONFIG_INIT_STS     0x1000000U   // LDA4 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA4_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LDA4_MEM_CONFIG_LOCK_LDA4_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA4_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LDA4_MEM_CONFIG_COMMIT_LDA4_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA5_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LDA5_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LDA5_MEM_CONFIG_TESTMODE_M   0x3U         // LDA5 Test Mode
#define MEMSS_LDA5_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LDA5_MEM_CONFIG_INIT_STS     0x1000000U   // LDA5 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA5_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LDA5_MEM_CONFIG_LOCK_LDA5_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA5_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LDA5_MEM_CONFIG_COMMIT_LDA5_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA6_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LDA6_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LDA6_MEM_CONFIG_TESTMODE_M   0x3U         // LDA6 Test Mode
#define MEMSS_LDA6_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LDA6_MEM_CONFIG_INIT_STS     0x1000000U   // LDA6 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA6_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LDA6_MEM_CONFIG_LOCK_LDA6_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA6_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LDA6_MEM_CONFIG_COMMIT_LDA6_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA7_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_LDA7_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_LDA7_MEM_CONFIG_TESTMODE_M   0x3U         // LDA7 Test Mode
#define MEMSS_LDA7_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_LDA7_MEM_CONFIG_INIT_STS     0x1000000U   // LDA7 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA7_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_LDA7_MEM_CONFIG_LOCK_LDA7_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the LDA7_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_LDA7_MEM_CONFIG_COMMIT_LDA7_MEM_CONFIG_LOCK   0x1U   // Permanent Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPA0_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CPA0_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CPA0_MEM_CONFIG_TESTMODE_M   0x3U         // LPA0 Test Mode
#define MEMSS_CPA0_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CPA0_MEM_CONFIG_INIT_STS     0x1000000U   // CPA0 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPA0_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CPA0_MEM_CONFIG_LOCK_CPA0_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPA0_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CPA0_MEM_CONFIG_COMMIT_CPA0_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPA1_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CPA1_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CPA1_MEM_CONFIG_TESTMODE_M   0x3U         // LPA1 Test Mode
#define MEMSS_CPA1_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CPA1_MEM_CONFIG_INIT_STS     0x1000000U   // CPA1 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPA1_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CPA1_MEM_CONFIG_LOCK_CPA1_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPA1_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CPA1_MEM_CONFIG_COMMIT_CPA1_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA0_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA0_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA0_MEM_CONFIG_TESTMODE_M   0x3U         // LDA0 Test Mode
#define MEMSS_CDA0_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA0_MEM_CONFIG_INIT_STS     0x1000000U   // CDA0 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA0_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA0_MEM_CONFIG_LOCK_CDA0_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA0_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA0_MEM_CONFIG_COMMIT_CDA0_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA1_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA1_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA1_MEM_CONFIG_TESTMODE_M   0x3U         // LDA1 Test Mode
#define MEMSS_CDA1_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA1_MEM_CONFIG_INIT_STS     0x1000000U   // CDA1 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA1_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA1_MEM_CONFIG_LOCK_CDA1_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA1_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA1_MEM_CONFIG_COMMIT_CDA1_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA2_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA2_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA2_MEM_CONFIG_TESTMODE_M   0x3U         // LDA2 Test Mode
#define MEMSS_CDA2_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA2_MEM_CONFIG_INIT_STS     0x1000000U   // CDA2 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA2_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA2_MEM_CONFIG_LOCK_CDA2_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA2_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA2_MEM_CONFIG_COMMIT_CDA2_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA3_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA3_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA3_MEM_CONFIG_TESTMODE_M   0x3U         // LDA3 Test Mode
#define MEMSS_CDA3_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA3_MEM_CONFIG_INIT_STS     0x1000000U   // CDA3 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA3_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA3_MEM_CONFIG_LOCK_CDA3_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA3_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA3_MEM_CONFIG_COMMIT_CDA3_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA4_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA4_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA4_MEM_CONFIG_TESTMODE_M   0x3U         // LDA4 Test Mode
#define MEMSS_CDA4_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA4_MEM_CONFIG_INIT_STS     0x1000000U   // CDA4 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA4_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA4_MEM_CONFIG_LOCK_CDA4_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA4_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA4_MEM_CONFIG_COMMIT_CDA4_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA5_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA5_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA5_MEM_CONFIG_TESTMODE_M   0x3U         // LDA5 Test Mode
#define MEMSS_CDA5_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA5_MEM_CONFIG_INIT_STS     0x1000000U   // CDA5 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA5_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA5_MEM_CONFIG_LOCK_CDA5_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA5_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA5_MEM_CONFIG_COMMIT_CDA5_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA6_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA6_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA6_MEM_CONFIG_TESTMODE_M   0x3U         // LDA6 Test Mode
#define MEMSS_CDA6_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA6_MEM_CONFIG_INIT_STS     0x1000000U   // CDA6 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA6_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA6_MEM_CONFIG_LOCK_CDA6_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA6_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA6_MEM_CONFIG_COMMIT_CDA6_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA7_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA7_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA7_MEM_CONFIG_TESTMODE_M   0x3U         // LDA7 Test Mode
#define MEMSS_CDA7_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA7_MEM_CONFIG_INIT_STS     0x1000000U   // CDA7 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA7_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA7_MEM_CONFIG_LOCK_CDA7_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA7_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA7_MEM_CONFIG_COMMIT_CDA7_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA8_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA8_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA8_MEM_CONFIG_TESTMODE_M   0x3U         // LDA8 Test Mode
#define MEMSS_CDA8_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA8_MEM_CONFIG_INIT_STS     0x1000000U   // CDA8 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA8_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA8_MEM_CONFIG_LOCK_CDA8_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA8_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA8_MEM_CONFIG_COMMIT_CDA8_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA9_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA9_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA9_MEM_CONFIG_TESTMODE_M   0x3U         // LDA9 Test Mode
#define MEMSS_CDA9_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA9_MEM_CONFIG_INIT_STS     0x1000000U   // CDA9 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA9_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA9_MEM_CONFIG_LOCK_CDA9_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA9_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA9_MEM_CONFIG_COMMIT_CDA9_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA10_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA10_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA10_MEM_CONFIG_TESTMODE_M   0x3U         // LDA10 Test Mode
#define MEMSS_CDA10_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA10_MEM_CONFIG_INIT_STS     0x1000000U   // CDA10 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA10_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA10_MEM_CONFIG_LOCK_CDA10_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA10_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA10_MEM_CONFIG_COMMIT_CDA10_MEM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA11_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CDA11_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_CDA11_MEM_CONFIG_TESTMODE_M   0x3U         // LDA11 Test Mode
#define MEMSS_CDA11_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_CDA11_MEM_CONFIG_INIT_STS     0x1000000U   // CDA11 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA11_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CDA11_MEM_CONFIG_LOCK_CDA11_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CDA11_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CDA11_MEM_CONFIG_COMMIT_CDA11_MEM_CONFIG_LOCK   0x1U   // Permanent Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the M0_MEM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_M0_MEM_CONFIG_TESTMODE_S   0U
#define MEMSS_M0_MEM_CONFIG_TESTMODE_M   0x3U         // M0 Test Mode
#define MEMSS_M0_MEM_CONFIG_INIT         0x10000U     // Triggers memory Initilization
#define MEMSS_M0_MEM_CONFIG_INIT_STS     0x1000000U   // M0 INIT status

//*************************************************************************************************
//
// The following are defines for the bit fields in the M0_MEM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_M0_MEM_CONFIG_LOCK_M0_MEM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the M0_MEM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_M0_MEM_CONFIG_COMMIT_M0_MEM_CONFIG_LOCK   0x1U   // Permanent Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_ROM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CPU1_ROM_CONFIG_TESTMODE_S   0U
#define MEMSS_CPU1_ROM_CONFIG_TESTMODE_M   0x3U   // CPU1_ROM Test Mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_ROM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CPU1_ROM_CONFIG_LOCK_CPU1_ROM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_ROM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CPU1_ROM_CONFIG_COMMIT_CPU1_ROM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_ROM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CPU2_ROM_CONFIG_TESTMODE_S   0U
#define MEMSS_CPU2_ROM_CONFIG_TESTMODE_M   0x3U   // CPU1_ROM Test Mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_ROM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CPU2_ROM_CONFIG_LOCK_CPU2_ROM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_ROM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CPU2_ROM_CONFIG_COMMIT_CPU2_ROM_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_ROM_CONFIG register
//
//*************************************************************************************************
#define MEMSS_CPU3_ROM_CONFIG_TESTMODE_S   0U
#define MEMSS_CPU3_ROM_CONFIG_TESTMODE_M   0x3U   // CPU1_ROM Test Mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_ROM_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CPU3_ROM_CONFIG_LOCK_CPU3_ROM_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_ROM_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CPU3_ROM_CONFIG_COMMIT_CPU3_ROM_CONFIG_LOCK   0x1U   // Permanent Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the MEM_DLB_CONFIG register
//
//*************************************************************************************************
#define MEMSS_MEM_DLB_CONFIG_CPU1_DLB_EN         0x1U    // CPU1 Data line buffer Enable
#define MEMSS_MEM_DLB_CONFIG_CPU2_DLB_EN         0x2U    // CPU2 Data line buffer Enable
#define MEMSS_MEM_DLB_CONFIG_CPU3_DLB_EN         0x4U    // CPU3 Data line buffer Enable
#define MEMSS_MEM_DLB_CONFIG_SYNCBRIDGE_DLB_EN   0x40U   // Sync Bridge Dataline buffer Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the MEM_DLB_CONFIG_LOCK register
//
//*************************************************************************************************
#define MEMSS_MEM_DLB_CONFIG_LOCK_MEM_DLB_CONFIG   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MEM_DLB_CONFIG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_MEM_DLB_CONFIG_COMMIT_MEM_DLB_CONFIG_LOCK   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PERI_MEM_TEST_LOCK register
//
//*************************************************************************************************
#define MEMSS_PERI_MEM_TEST_LOCK_PERI_MEM_TEST_CONTROL   0x1U   // PERI_MEM_TEST_CONTROL Lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PERI_MEM_TEST_CONTROL register
//
//*************************************************************************************************
#define MEMSS_PERI_MEM_TEST_CONTROL_ETHERCAT_MEM_FORCE_ERROR   0x20U   // Force Parity Error on
                                                                       // EtherCAT RAM

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST register
//
//*************************************************************************************************
#define MEMSS_PARITY_TEST_TESTEN_S   0U
#define MEMSS_PARITY_TEST_TESTEN_M   0xFU   // Parity test enable


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_ROM_PATCH_REG_LOCK register
//
//*************************************************************************************************
#define MEMSS_CPU1_ROM_PATCH_REG_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_ROM_PATCH_REG_COMMIT register
//
//*************************************************************************************************
#define MEMSS_CPU1_ROM_PATCH_REG_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_0_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_0_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_0_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_0_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_0_ECC_ECC_S   0U
#define MEMSS_CPU1_0_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_1_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_1_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_1_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_1_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_1_ECC_ECC_S   0U
#define MEMSS_CPU1_1_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_2_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_2_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_2_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_2_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_2_ECC_ECC_S   0U
#define MEMSS_CPU1_2_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_3_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_3_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_3_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_3_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_3_ECC_ECC_S   0U
#define MEMSS_CPU1_3_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_4_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_4_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_4_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_4_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_4_ECC_ECC_S   0U
#define MEMSS_CPU1_4_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_5_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_5_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_5_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_5_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_5_ECC_ECC_S   0U
#define MEMSS_CPU1_5_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_6_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_6_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_6_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_6_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_6_ECC_ECC_S   0U
#define MEMSS_CPU1_6_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_7_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_7_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_7_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_7_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_7_ECC_ECC_S   0U
#define MEMSS_CPU1_7_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_8_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_8_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_8_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_8_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_8_ECC_ECC_S   0U
#define MEMSS_CPU1_8_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_9_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_9_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_9_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_9_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_9_ECC_ECC_S   0U
#define MEMSS_CPU1_9_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_10_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_10_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_10_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_10_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_10_ECC_ECC_S   0U
#define MEMSS_CPU1_10_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_11_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_11_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_11_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_11_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_11_ECC_ECC_S   0U
#define MEMSS_CPU1_11_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_12_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_12_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_12_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_12_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_12_ECC_ECC_S   0U
#define MEMSS_CPU1_12_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_13_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_13_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_13_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_13_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_13_ECC_ECC_S   0U
#define MEMSS_CPU1_13_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_14_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_14_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_14_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_14_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_14_ECC_ECC_S   0U
#define MEMSS_CPU1_14_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_15_ADDR register
//
//*************************************************************************************************
#define MEMSS_CPU1_15_ADDR_ADDR_64B_ALIGNED_S   3U
#define MEMSS_CPU1_15_ADDR_ADDR_64B_ALIGNED_M   0xFFFFFFF8U   // Address to be patched

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_15_ECC register
//
//*************************************************************************************************
#define MEMSS_CPU1_15_ECC_ECC_S   0U
#define MEMSS_CPU1_15_ECC_ECC_M   0xFFU   // ECC of 64 bits to be patched



#endif
