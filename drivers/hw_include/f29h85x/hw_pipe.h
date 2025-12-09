//###########################################################################
//
// FILE:    hw_pipe.h
//
// TITLE:   Definitions for the PIPE registers.
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

#ifndef HW_PIPE_H
#define HW_PIPE_H

//*************************************************************************************************
//
// The following are defines for the PIPE register offsets
//
//*************************************************************************************************
#define PIPE_O_RTINT_THRESHOLD            0x0U                       // Interrupt threshold
                                                                     // register
#define PIPE_O_INT_GRP_MASK               0x4U                       // Interrupt group mask
                                                                     // register
#define PIPE_O_GLOBAL_EN                  0x8U                       // Global enable for INT and
                                                                     // RTINT
#define PIPE_O_REVISION                   0xCU                       // Reserved
#define PIPE_O_CPU_INT_STS                0x20U                      // CPU interrupt status
#define PIPE_O_RST_VECT                   0x24U                      // Reset vector register
#define PIPE_O_RST_LINK_OWNER             0x28U                      // Reset link owner register
#define PIPE_O_NMI_STS                    0x2CU                      // Non Maskable Interrupt
                                                                     // status register
#define PIPE_O_NMI_VECT                   0x30U                      // Non Maskable Interrupt
                                                                     // vector register
#define PIPE_O_NMI_LINK_OWNER             0x34U                      // Non Maskable Interrupt link
                                                                     // owner register
#define PIPE_O_MEM_ECC_DIAG               0x40U                      // ECC diagnostics register
#define PIPE_O_MEM_INIT                   0x44U                      // PIPE vector memory
                                                                     // initialization register
#define PIPE_O_MEM_INIT_STS               0x48U                      // PIPE memory initialization
                                                                     // status register
#define PIPE_O_INT_SEC_STS                0x4CU                      // Interrupt security status
                                                                     // register
#define PIPE_O_INT_SEC_CLR                0x50U                      // Interrupt security clear
                                                                     // register
#define PIPE_O_RTINT_SP_L                 0x60U                      // RTINT stack limit register
#define PIPE_O_RTINT_SP_H                 0x64U                      // RTINT stack limit register
#define PIPE_O_RTISP_STS                  0x68U                      // RTINT Stack pointer
                                                                     // violation status register
#define PIPE_O_INTSP                      0x6CU                      // INT stack pointer
#define PIPE_O_LOCK                       0x80U                      // PIPE lock register
#define PIPE_O_COMMIT                     0x84U                      // PIPE commit register
#define PIPE_O_TASK_CTRL                  0x90U                      // Task control register
#define PIPE_O_BOOT_LINK_CTRL             0x94U                      // Boot Link control to lock
                                                                     // out BOOT_LINK
#define PIPE_O_INT_VECT_MAPPING           0x98U                      // Interrupt vector mapping
                                                                     // for LFU, FOTA, and INT vector
                                                                     // swapping support
#define PIPE_O_MMR_CLR                    0xA0U                      // PIPE MMR clear register
#define PIPE_O_ALL_FLAG_CLR               0xA4U                      // PIPE flag clear register
#define PIPE_O_REG_PARITY_DIAG_DATA       0xB0U                      // Register parity Diagnostic
                                                                     // data
#define PIPE_O_REG_PARITY_DIAG_PARITY     0xB8U                      // Register parity Diagnostic
                                                                     // Parity
#define PIPE_O_REG_PARITY_DIAG_ASSERT     0xC0U                      // Register parity Assert
                                                                     // diagnostic
#define PIPE_O_REG_PARITY_CHECK           0xC8U                      // Enabling the Parity check
#define PIPE_O_REG_PARITY_READ            0xCCU                      // Enabling the Parity read
#define PIPE_O_INT_CTL_L(i)               (0x1000U + ((i) * 0x4U))   // (0 <= i < 256) Interrupt
                                                                     // low flag and status control register
#define PIPE_O_INT_CTL_H(i)               (0x2000U + ((i) * 0x4U))   // (0 <= i < 256) Interrupt
                                                                     // high flag and status control
                                                                     // register
#define PIPE_O_INT_CONFIG(i)              (0x3000U + ((i) * 0x4U))   // (0 <= i < 256) Interrupt
                                                                     // configuration register
#define PIPE_O_INT_LINK_OWNER(i)          (0x4000U + ((i) * 0x4U))   // (0 <= i < 256) Interrupt
                                                                     // link ownership config register
#define PIPE_O_INT_VECT_ADDR(i)           (0x5000U + ((i) * 0x4U))   // (0 <= i < 256) Interrupt
                                                                     // vector address
#define PIPE_O_INT_LINK_OWNER_LFU(i)      (0x6000U + ((i) * 0x4U))   // (0 <= i < 256) Interrupt
                                                                     // link ownership config register
#define PIPE_O_INT_VECT_ADDR_LFU(i)       (0x7000U + ((i) * 0x4U))   // (0 <= i < 256) Interrupt
                                                                     // vector address
#define PIPE_O_SELFTEST_DIAG_DATA0        0x8000U                    // Diagnostics data register 0
#define PIPE_O_SELFTEST_DIAG_DATA1        0x8004U                    // Diagnostics data register 1
#define PIPE_O_SELFTEST_DIAG_ECC          0x8020U                    // Diagnostics ECC
#define PIPE_O_SELFTEST_DIAG_CONTROL      0x8028U                    // Diagnostic test enable.
#define PIPE_O_SELFTEST_DIAG_STATUS       0x802CU                    // Diagnostic status register
#define PIPE_O_SELFTEST_DIAG_STATUS_CLR   0x8030U                    // Diagnostic status clear
                                                                     // register


//*************************************************************************************************
//
// The following are defines for the bit fields in the RTINT_THRESHOLD register
//
//*************************************************************************************************
#define PIPE_RTINT_THRESHOLD_INT_RTINT_THRESHOLD_S   0U
#define PIPE_RTINT_THRESHOLD_INT_RTINT_THRESHOLD_M   0xFFU   // Interrupt threshold value

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_GRP_MASK register
//
//*************************************************************************************************
#define PIPE_INT_GRP_MASK_INT_GRP_MASK_S   0U
#define PIPE_INT_GRP_MASK_INT_GRP_MASK_M   0xFFU   // Interrupt group mask

//*************************************************************************************************
//
// The following are defines for the bit fields in the GLOBAL_EN register
//
//*************************************************************************************************
#define PIPE_GLOBAL_EN_ENABLE_S   0U
#define PIPE_GLOBAL_EN_ENABLE_M   0x3U          // Global enable
#define PIPE_GLOBAL_EN_KEY_S      16U
#define PIPE_GLOBAL_EN_KEY_M      0xFFFF0000U   // Key to enable write to lower [15:0] bit fields
#define PIPE_GLOBAL_EN_KEY        0xFACE0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define PIPE_REVISION_MINREV_S   0U
#define PIPE_REVISION_MINREV_M   0xFFU     // Minor Revision Number
#define PIPE_REVISION_MAJREV_S   8U
#define PIPE_REVISION_MAJREV_M   0xFF00U   // Major Revision Number

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU_INT_STS register
//
//*************************************************************************************************
#define PIPE_CPU_INT_STS_LAST_INTSTS_S          0U
#define PIPE_CPU_INT_STS_LAST_INTSTS_M          0x3U        // Type of last interrupt in-service
                                                            // between INT and  RTINT
#define PIPE_CPU_INT_STS_LAST_INT_PRIOLVL_S     8U
#define PIPE_CPU_INT_STS_LAST_INT_PRIOLVL_M     0xFF00U     // Priority level of last INT interrupt
                                                            //  in-service
#define PIPE_CPU_INT_STS_LAST_RTINT_PRIOLVL_S   16U
#define PIPE_CPU_INT_STS_LAST_RTINT_PRIOLVL_M   0xFF0000U   // Priority level of last RTINT
                                                            // interrupt  in-service

//*************************************************************************************************
//
// The following are defines for the bit fields in the RST_LINK_OWNER register
//
//*************************************************************************************************
#define PIPE_RST_LINK_OWNER_LINK_OWNER_S   0U
#define PIPE_RST_LINK_OWNER_LINK_OWNER_M   0xFU   // Reset vector link owner

//*************************************************************************************************
//
// The following are defines for the bit fields in the NMI_STS register
//
//*************************************************************************************************
#define PIPE_NMI_STS_NMI_FLAG   0x1U   // Interrupt active
#define PIPE_NMI_STS_NMI_CLR    0x2U   // NMI SW clear bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the NMI_LINK_OWNER register
//
//*************************************************************************************************
#define PIPE_NMI_LINK_OWNER_LINK_OWNER_S   0U
#define PIPE_NMI_LINK_OWNER_LINK_OWNER_M   0xFU   // NMI vector link owner

//*************************************************************************************************
//
// The following are defines for the bit fields in the MEM_ECC_DIAG register
//
//*************************************************************************************************
#define PIPE_MEM_ECC_DIAG_ECC_VIEW          0x1U          // ECC memory map enable register
#define PIPE_MEM_ECC_DIAG_MEM_SIC_DIAG_EN   0x2U          // Memory safe interconnect diagnostics
                                                          // enable
#define PIPE_MEM_ECC_DIAG_KEY_S             16U
#define PIPE_MEM_ECC_DIAG_KEY_M             0xFFFF0000U   // Key to enable write to lower [15:0]
                                                          // bit fields
#define PIPE_MEM_ECC_DIAG_KEY               0x5A5A0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the MEM_INIT register
//
//*************************************************************************************************
#define PIPE_MEM_INIT_INIT_S   0U
#define PIPE_MEM_INIT_INIT_M   0x3U          // Memory initialization start
#define PIPE_MEM_INIT_KEY_S    16U
#define PIPE_MEM_INIT_KEY_M    0xFFFF0000U   // Key to enable write to lower [15:0] bit fields
#define PIPE_MEM_INIT_KEY      0x5A5A0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the MEM_INIT_STS register
//
//*************************************************************************************************
#define PIPE_MEM_INIT_STS_INIT_STS_S   0U
#define PIPE_MEM_INIT_STS_INIT_STS_M   0x3U   // Memory initialization status

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_SEC_STS register
//
//*************************************************************************************************
#define PIPE_INT_SEC_STS_SEC_FAIL_FLAG   0x1U   // VBUSP access security error

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_SEC_CLR register
//
//*************************************************************************************************
#define PIPE_INT_SEC_CLR_SEC_FAIL_FLAG_CLR   0x1U   // SEC_FAIL_FLAG bit clear field

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTINT_SP_L register
//
//*************************************************************************************************
#define PIPE_RTINT_SP_L_RTISP_S      0U
#define PIPE_RTINT_SP_L_RTISP_M      0x1FU     // Real Time Interrupt Stack Pointer
#define PIPE_RTINT_SP_L_MAXRTISP_S   8U
#define PIPE_RTINT_SP_L_MAXRTISP_M   0x1F00U   // Maximum Real Time Interrupt Stack Pointer

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTINT_SP_H register
//
//*************************************************************************************************
#define PIPE_RTINT_SP_H_WARNRTISP_S              0U
#define PIPE_RTINT_SP_H_WARNRTISP_M              0x1FU     // Warning Real Time Interrupt Stack
                                                           // Pointer
#define PIPE_RTINT_SP_H_WARNRTISP_PRIO_LEVEL_S   8U
#define PIPE_RTINT_SP_H_WARNRTISP_PRIO_LEVEL_M   0xFF00U   // RTINT Stack Pointer warning priority
                                                           // level

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTISP_STS register
//
//*************************************************************************************************
#define PIPE_RTISP_STS_WARNRTISP_STS   0x1U   // RTINT Stack Pointer warning status
#define PIPE_RTISP_STS_MAXRTISP_STS    0x2U   // RTINT Stack Pointer max breach status

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTSP register
//
//*************************************************************************************************
#define PIPE_INTSP_INTSP_S   0U
#define PIPE_INTSP_INTSP_M   0xFU   // Interrupt Stack Pointer

//*************************************************************************************************
//
// The following are defines for the bit fields in the LOCK register
//
//*************************************************************************************************
#define PIPE_LOCK_LINK_LOCK     0x1U          // Lock bit for link owner field
#define PIPE_LOCK_CONFIG_LOCK   0x2U          // Lock bit for interrupt priority field
#define PIPE_LOCK_GLOBAL_LOCK   0x4U          // Lock bit for common config regs
#define PIPE_LOCK_VECT_LOCK     0x8U          // Lock bit for Vector memory
#define PIPE_LOCK_KEY_S         16U
#define PIPE_LOCK_KEY_M         0xFFFF0000U   // Key to enable write to lower [15:0] bit fields
#define PIPE_LOCK_KEY           0x5A5A0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMMIT register
//
//*************************************************************************************************
#define PIPE_COMMIT_LINK_COMMIT     0x1U          // Commit bit for link fields
#define PIPE_COMMIT_CONFIG_COMMIT   0x2U          // Commit bit for interrupt priority field
#define PIPE_COMMIT_GLOBAL_COMMIT   0x4U          // Commit bit for common config regs
#define PIPE_COMMIT_VECT_COMMIT     0x8U          // Commit bit for vector memory
#define PIPE_COMMIT_KEY_S           16U
#define PIPE_COMMIT_KEY_M           0xFFFF0000U   // Key to enable write to lower [15:0] bit fields
#define PIPE_COMMIT_KEY             0x5A5A0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the TASK_CTRL register
//
//*************************************************************************************************
#define PIPE_TASK_CTRL_ACTIVE_CONTEXT_ID_S   0U
#define PIPE_TASK_CTRL_ACTIVE_CONTEXT_ID_M   0x3U          // Active context ID for PIPE
                                                           // arbitration.
#define PIPE_TASK_CTRL_SUP_IGN_INTE_EN       0x100U        // Supervisor Interrupt Enable
#define PIPE_TASK_CTRL_KEY_S                 16U
#define PIPE_TASK_CTRL_KEY_M                 0xFFFF0000U   // Key to enable write to lower [15:0]
                                                           // bit fields
#define PIPE_TASK_CTRL_KEY                   0xCAFE0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the BOOT_LINK_CTRL register
//
//*************************************************************************************************
#define PIPE_BOOT_LINK_CTRL_BOOT_LINK_LOCK   0x1U          // Locks the Boot Link updates to
                                                           // configuration registers.
#define PIPE_BOOT_LINK_CTRL_KEY_S            16U
#define PIPE_BOOT_LINK_CTRL_KEY_M            0xFFFF0000U   // Key to enable write to lower [15:0]
                                                           // bit fields
#define PIPE_BOOT_LINK_CTRL_KEY              0xFACE0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_VECT_MAPPING register
//
//*************************************************************************************************
#define PIPE_INT_VECT_MAPPING_LFU_INT_VECT_MAPPING_S   0U
#define PIPE_INT_VECT_MAPPING_LFU_INT_VECT_MAPPING_M   0x3U          // Interrupt vector mapping to
                                                                     // PPB for LFU support
#define PIPE_INT_VECT_MAPPING_KEY_S                    16U
#define PIPE_INT_VECT_MAPPING_KEY_M                    0xFFFF0000U   // Key to enable write to
                                                                     // lower [15:0] bit fields
#define PIPE_INT_VECT_MAPPING_KEY                      0xCAFE0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the MMR_CLR register
//
//*************************************************************************************************
#define PIPE_MMR_CLR_MMR_CLR_S   0U
#define PIPE_MMR_CLR_MMR_CLR_M   0x3U   // PIPE MMR clear control

//*************************************************************************************************
//
// The following are defines for the bit fields in the ALL_FLAG_CLR register
//
//*************************************************************************************************
#define PIPE_ALL_FLAG_CLR_ALL_FLAG_CLR_S   0U
#define PIPE_ALL_FLAG_CLR_ALL_FLAG_CLR_M   0x3U          // Clears the Flags for all the interrupt
                                                         // lines.
#define PIPE_ALL_FLAG_CLR_KEY_S            16U
#define PIPE_ALL_FLAG_CLR_KEY_M            0xFFFF0000U   // Key to enable write to lower [15:0] bit
                                                         // fields
#define PIPE_ALL_FLAG_CLR_KEY              0xFEED0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the REG_PARITY_DIAG_PARITY register
//
//*************************************************************************************************
#define PIPE_REG_PARITY_DIAG_PARITY_DIAG_PARITY_DATA_S   0U
#define PIPE_REG_PARITY_DIAG_PARITY_DIAG_PARITY_DATA_M   0xFU   // Diagnostics parity data

//*************************************************************************************************
//
// The following are defines for the bit fields in the REG_PARITY_DIAG_ASSERT register
//
//*************************************************************************************************
#define PIPE_REG_PARITY_DIAG_ASSERT_DIAG_ASSERT   0x1U          // Diagnostics assert
#define PIPE_REG_PARITY_DIAG_ASSERT_KEY_S         16U
#define PIPE_REG_PARITY_DIAG_ASSERT_KEY_M         0xFFFF0000U   // Key to enable write to lower
                                                                // [15:0] bit fields

//*************************************************************************************************
//
// The following are defines for the bit fields in the REG_PARITY_CHECK register
//
//*************************************************************************************************
#define PIPE_REG_PARITY_CHECK_MODE_S   0U
#define PIPE_REG_PARITY_CHECK_MODE_M   0xFU          // Parity check mode
#define PIPE_REG_PARITY_CHECK_KEY_S    16U
#define PIPE_REG_PARITY_CHECK_KEY_M    0xFFFF0000U   // Key to enable write to lower [15:0] bit
                                                     // fields

//*************************************************************************************************
//
// The following are defines for the bit fields in the REG_PARITY_READ register
//
//*************************************************************************************************
#define PIPE_REG_PARITY_READ_PARITY_READ_EN_S   0U
#define PIPE_REG_PARITY_READ_PARITY_READ_EN_M   0xFU          // Parity read enable
#define PIPE_REG_PARITY_READ_KEY_S              16U
#define PIPE_REG_PARITY_READ_KEY_M              0xFFFF0000U   // Key to enable write to lower
                                                              // [15:0] bit fields

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_CTL_L register
//
//*************************************************************************************************
#define PIPE_INT_CTL_L_EN              0x1U   // INT enable
#define PIPE_INT_CTL_L_FLAG            0x2U   // INT FLAG status
#define PIPE_INT_CTL_L_OVERFLOW_FLAG   0x4U   // INT_OVERFLOW_FLAG status

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_CTL_H register
//
//*************************************************************************************************
#define PIPE_INT_CTL_H_FLAG_FRC            0x1U   // INT SW set bit
#define PIPE_INT_CTL_H_FLAG_CLR            0x2U   // INT_FLAG clear bit
#define PIPE_INT_CTL_H_OVERFLOW_FLAG_CLR   0x4U   // INT_OVERFLOW_FLAG clear bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_CONFIG register
//
//*************************************************************************************************
#define PIPE_INT_CONFIG_PRI_LEVEL_S    0U
#define PIPE_INT_CONFIG_PRI_LEVEL_M    0xFFU      // Priority level
#define PIPE_INT_CONFIG_CONTEXT_ID_S   16U
#define PIPE_INT_CONFIG_CONTEXT_ID_M   0x30000U   // Interrupt Context-ID

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_LINK_OWNER register
//
//*************************************************************************************************
#define PIPE_INT_LINK_OWNER_OWNER_LINK_S   0U
#define PIPE_INT_LINK_OWNER_OWNER_LINK_M   0xFU     // Link owner for INT
#define PIPE_INT_LINK_OWNER_API_LINK_S     4U
#define PIPE_INT_LINK_OWNER_API_LINK_M     0xF0U    // Access protection inheritance link for INT
#define PIPE_INT_LINK_OWNER_API_LINK_EN    0x100U   // Access protection inheritance link enable
                                                    // for INT

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_LINK_OWNER_LFU register
//
//*************************************************************************************************
#define PIPE_INT_LINK_OWNER_LFU_OWNER_LINK_S   0U
#define PIPE_INT_LINK_OWNER_LFU_OWNER_LINK_M   0xFU     // Link owner for INT for LFU
#define PIPE_INT_LINK_OWNER_LFU_API_LINK_S     4U
#define PIPE_INT_LINK_OWNER_LFU_API_LINK_M     0xF0U    // Access protection inheritance link for
                                                        // INT for LFU
#define PIPE_INT_LINK_OWNER_LFU_API_LINK_EN    0x100U   // Access protection inheritance link
                                                        // enable for INT for LFU

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_DATA1 register
//
//*************************************************************************************************
#define PIPE_SELFTEST_DIAG_DATA1_SELFTEST_DIAG_DATA1_S   0U
#define PIPE_SELFTEST_DIAG_DATA1_SELFTEST_DIAG_DATA1_M   0xFFFFFU   // Self test Diagnostics data 1

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_ECC register
//
//*************************************************************************************************
#define PIPE_SELFTEST_DIAG_ECC_SELFTEST_DIAG_ECC_S   0U
#define PIPE_SELFTEST_DIAG_ECC_SELFTEST_DIAG_ECC_M   0x7FU   // Self test Diagnostics ECC

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_CONTROL register
//
//*************************************************************************************************
#define PIPE_SELFTEST_DIAG_CONTROL_DIAG_TEST_EN_S      0U
#define PIPE_SELFTEST_DIAG_CONTROL_DIAG_TEST_EN_M      0xFU          // Diagnostic test enable
#define PIPE_SELFTEST_DIAG_CONTROL_DIAG_ECC_WIDTH_S    16U
#define PIPE_SELFTEST_DIAG_CONTROL_DIAG_ECC_WIDTH_M    0xF0000U      // Diagnostic ECC width
#define PIPE_SELFTEST_DIAG_CONTROL_DIAG_DATA_WIDTH_S   24U
#define PIPE_SELFTEST_DIAG_CONTROL_DIAG_DATA_WIDTH_M   0xFF000000U   // Diagnostic Data width

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_STATUS register
//
//*************************************************************************************************
#define PIPE_SELFTEST_DIAG_STATUS_DIAG_TEST_DONE           0x2U      // Done self test
#define PIPE_SELFTEST_DIAG_STATUS_DIAG_TEST_FAIL           0x4U      // Test failed
#define PIPE_SELFTEST_DIAG_STATUS_DIAG_FAIL_C_ERROR        0x8U      // Diagnostic correctable
                                                                     // error
#define PIPE_SELFTEST_DIAG_STATUS_DIAG_FAIL_UC_ERROR       0x10U     // Diagnostic uncorrectable
                                                                     // error
#define PIPE_SELFTEST_DIAG_STATUS_DIAG_FAIL_CHECK_TYPE_S   5U
#define PIPE_SELFTEST_DIAG_STATUS_DIAG_FAIL_CHECK_TYPE_M   0x60U     // Failed diagnostic check
                                                                     // type
#define PIPE_SELFTEST_DIAG_STATUS_DIAG_FAIL_BIT_INDEX_S    8U
#define PIPE_SELFTEST_DIAG_STATUS_DIAG_FAIL_BIT_INDEX_M    0xFF00U   // Error bit position

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_STATUS_CLR register
//
//*************************************************************************************************
#define PIPE_SELFTEST_DIAG_STATUS_CLR_DIAG_TEST_DONE   0x2U   // Clear self test done status flag
#define PIPE_SELFTEST_DIAG_STATUS_CLR_DIAG_TEST_FAIL   0x4U   // Clear test failed status flags



#endif
