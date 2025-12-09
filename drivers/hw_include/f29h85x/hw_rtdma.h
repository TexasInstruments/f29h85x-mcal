//###########################################################################
//
// FILE:    hw_rtdma.h
//
// TITLE:   Definitions for the RTDMA registers.
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

#ifndef HW_RTDMA_H
#define HW_RTDMA_H

//*************************************************************************************************
//
// The following are defines for the RTDMA register offsets
//
//*************************************************************************************************
#define RTDMA_O_DMACTRL         0x0U    // DMA Control Register
#define RTDMA_O_DEBUGCTRL       0x4U    // Debug Control Register
#define RTDMA_O_REVISION        0x8U    // RTDMA Revision Control Register
#define RTDMA_O_SWPRI1          0x14U   // Software Priority Configuration Register 1
#define RTDMA_O_SWPRI2          0x18U   // Software Priority Configuration Register 2
#define RTDMA_O_PRIORITYSTAT    0x1CU   // Priority Status Register
#define RTDMA_O_DMACFG_LOCK     0x40U   // Channel Configuration Temporary Lock
#define RTDMA_O_DMACFG_COMMIT   0x44U   // Channel Configuration Permanent Commit

#define RTDMA_O_MPUR_CHMASK(i)   (0x0U + ((i) * 32U))    // (0 <= i < 16) MPU Region Configuration
#define RTDMA_O_MPUR_START(i)    (0x4U + ((i) * 32U))    // (0 <= i < 16) MPU Region Start Address
#define RTDMA_O_MPUR_END(i)      (0x8U + ((i) * 32U))    // (0 <= i < 16) MPU Region End Address
#define RTDMA_O_MPUR_LOCK(i)     (0xCU + ((i) * 32U))    // (0 <= i < 16) MPU Temporary Lock
#define RTDMA_O_MPUR_COMMIT(i)   (0x10U + ((i) * 32U))   // (0 <= i < 16) MPU Permanent Commit
#define RTDMA_O_MPUR_ACCESS(i)   (0x14U + ((i) * 32U))   // (0 <= i < 16) MPU Region R/W Access
                                                         // Permissions
#define RTDMA_O_MPUCTRL          0x800U                  // MPU Control Register
#define RTDMA_O_MPUCFG_LOCK      0x820U                  // Channel Configuration Temporary Lock
#define RTDMA_O_MPUCFG_COMMIT    0x824U                  // Channel Configuration Permanent Commit

#define RTDMA_O_MODE                  0x0U     // Mode Register
#define RTDMA_O_CONTROL               0x4U     // Control Register
#define RTDMA_O_BURST_SIZE            0x8U     // Burst Size Register
#define RTDMA_O_BURST_COUNT           0xCU     // Burst Count Register
#define RTDMA_O_SRC_BURST_STEP        0x10U    // Source Burst Step Register
#define RTDMA_O_DST_BURST_STEP        0x14U    // Destination Burst Step Register
#define RTDMA_O_TRANSFER_SIZE         0x18U    // Transfer Size Register
#define RTDMA_O_TRANSFER_COUNT        0x1CU    // Transfer Count Register
#define RTDMA_O_SRC_TRANSFER_STEP     0x20U    // Source Transfer Step Register
#define RTDMA_O_DST_TRANSFER_STEP     0x24U    // Destination Transfer Step Register
#define RTDMA_O_SRC_WRAP_SIZE         0x28U    // Source Wrap Size Register
#define RTDMA_O_SRC_WRAP_COUNT        0x2CU    // Source Wrap Count Register
#define RTDMA_O_SRC_WRAP_STEP         0x30U    // Source Wrap Step Register
#define RTDMA_O_DST_WRAP_SIZE         0x34U    // Destination Wrap Size Register
#define RTDMA_O_DST_WRAP_COUNT        0x38U    // Destination Wrap Count Register
#define RTDMA_O_DST_WRAP_STEP         0x3CU    // Destination Wrap Step Register
#define RTDMA_O_SRC_BEG_ADDR_SHADOW   0x40U    // Source Begin Address Shadow Register
#define RTDMA_O_SRC_ADDR_SHADOW       0x44U    // Source Address Shadow Register
#define RTDMA_O_SRC_BEG_ADDR_ACTIVE   0x48U    // Source Begin Address Active Register
#define RTDMA_O_SRC_ADDR_ACTIVE       0x4CU    // Source Address Active Register
#define RTDMA_O_DST_BEG_ADDR_SHADOW   0x50U    // Destination Begin Address Shadow Register
#define RTDMA_O_DST_ADDR_SHADOW       0x54U    // Destination Address Shadow Register
#define RTDMA_O_DST_BEG_ADDR_ACTIVE   0x58U    // Destination Begin Address Active Register
#define RTDMA_O_DST_ADDR_ACTIVE       0x5CU    // Destination Address Active Register
#define RTDMA_O_CHSECLAT1             0x80U    // Channel Security Details Latch Register
#define RTDMA_O_CHSECLAT2             0x84U    // Channel Security Details Latch Register
#define RTDMA_O_BURST_INTF_CTRL       0xA0U    // Burst Interface Control Register
#define RTDMA_O_CHCFG_LOCK            0x100U   // Channel Configuration Temporary Lock
#define RTDMA_O_CHCFG_COMMIT          0x104U   // Channel Configuration Permanent Commit

#define RTDMA_O_FLTEMU_CONFIG      0x0U   // Fault emulation configuration registerr
#define RTDMA_O_FLTEMU_ACCGRPSEL   0x4U   // Fault emulation access information group selection
                                          // register
#define RTDMA_O_FLTEMU_BITSEL      0x8U   // Fault emulation bitsel
#define RTDMA_O_FLTEMU_ADDR        0xCU   // Fault emulation access address register

#define RTDMA_O_SELFTEST_DIAG_DATA0        0x0U    // Diagnostics data register 0
#define RTDMA_O_SELFTEST_DIAG_DATA1        0x4U    // Diagnostics data register 1
#define RTDMA_O_SELFTEST_DIAG_DATA2        0x8U    // Diagnostics data register 2
#define RTDMA_O_SELFTEST_DIAG_ECC          0x20U   // Diagnostics ECC
#define RTDMA_O_SELFTEST_DIAG_CONTROL      0x28U   // Diagnostic test enable
#define RTDMA_O_SELFTEST_DIAG_STATUS       0x2CU   // Diagnostic status register
#define RTDMA_O_SELFTEST_DIAG_STATUS_CLR   0x30U   // Diagnostic status clear register


//*************************************************************************************************
//
// The following are defines for the bit fields in the DMACTRL register
//
//*************************************************************************************************
#define RTDMA_DMACTRL_HARDRESET       0x1U       // Hard Reset Bit
#define RTDMA_DMACTRL_PRIORITYRESET   0x2U       // Priority Reset Bit
#define RTDMA_DMACTRL_PRIORITYSEL     0x10000U   // The priority select bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEBUGCTRL register
//
//*************************************************************************************************
#define RTDMA_DEBUGCTRL_FREE   0x8000U   // Debug Mode Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define RTDMA_REVISION_TYPE_S   0U
#define RTDMA_REVISION_TYPE_M   0xFFU     // RTDMA Type
#define RTDMA_REVISION_REV_S    8U
#define RTDMA_REVISION_REV_M    0xFF00U   // RTDMA Revision

//*************************************************************************************************
//
// The following are defines for the bit fields in the SWPRI1 register
//
//*************************************************************************************************
#define RTDMA_SWPRI1_CH1PRIORITY_S   0U
#define RTDMA_SWPRI1_CH1PRIORITY_M   0xFU          // Ch1 Priority Configuration
#define RTDMA_SWPRI1_CH2PRIORITY_S   4U
#define RTDMA_SWPRI1_CH2PRIORITY_M   0xF0U         // Ch2 Priority Configuration
#define RTDMA_SWPRI1_CH3PRIORITY_S   8U
#define RTDMA_SWPRI1_CH3PRIORITY_M   0xF00U        // Ch3 Priority Configuration
#define RTDMA_SWPRI1_CH4PRIORITY_S   12U
#define RTDMA_SWPRI1_CH4PRIORITY_M   0xF000U       // Ch4 Priority Configuration
#define RTDMA_SWPRI1_CH5PRIORITY_S   16U
#define RTDMA_SWPRI1_CH5PRIORITY_M   0xF0000U      // Ch5 Priority Configuration
#define RTDMA_SWPRI1_CH6PRIORITY_S   20U
#define RTDMA_SWPRI1_CH6PRIORITY_M   0xF00000U     // Ch6 Priority Configuration
#define RTDMA_SWPRI1_CH7PRIORITY_S   24U
#define RTDMA_SWPRI1_CH7PRIORITY_M   0xF000000U    // Ch7 Priority Configuration
#define RTDMA_SWPRI1_CH8PRIORITY_S   28U
#define RTDMA_SWPRI1_CH8PRIORITY_M   0xF0000000U   // Ch8 Priority Configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SWPRI2 register
//
//*************************************************************************************************
#define RTDMA_SWPRI2_CH9PRIORITY_S    0U
#define RTDMA_SWPRI2_CH9PRIORITY_M    0xFU    // Ch9 Priority Configuration
#define RTDMA_SWPRI2_CH10PRIORITY_S   4U
#define RTDMA_SWPRI2_CH10PRIORITY_M   0xF0U   // Ch10 Priority Configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the PRIORITYSTAT register
//
//*************************************************************************************************
#define RTDMA_PRIORITYSTAT_ACTIVESTS_S          0U
#define RTDMA_PRIORITYSTAT_ACTIVESTS_M          0x1FU     // Active Channel Status Bits
#define RTDMA_PRIORITYSTAT_ACTIVESTS_SHADOW_S   8U
#define RTDMA_PRIORITYSTAT_ACTIVESTS_SHADOW_M   0x1F00U   // Active Channel Status Shadow Bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMACFG_LOCK register
//
//*************************************************************************************************
#define RTDMA_DMACFG_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMACFG_COMMIT register
//
//*************************************************************************************************
#define RTDMA_DMACFG_COMMIT_COMMIT   0x1U   // Permanent Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR_CHMASK register
//
//*************************************************************************************************
#define RTDMA_MPUR_CHMASK_CH1MASK    0x1U     // MPU region channel mask Channel 1
#define RTDMA_MPUR_CHMASK_CH2MASK    0x2U     // MPU region channel mask Channel 2
#define RTDMA_MPUR_CHMASK_CH3MASK    0x4U     // MPU region channel mask Channel 3
#define RTDMA_MPUR_CHMASK_CH4MASK    0x8U     // MPU region channel mask Channel 4
#define RTDMA_MPUR_CHMASK_CH5MASK    0x10U    // MPU region channel mask Channel 5
#define RTDMA_MPUR_CHMASK_CH6MASK    0x20U    // MPU region channel mask Channel 6
#define RTDMA_MPUR_CHMASK_CH7MASK    0x40U    // MPU region channel mask Channel 7
#define RTDMA_MPUR_CHMASK_CH8MASK    0x80U    // MPU region channel mask Channel 8
#define RTDMA_MPUR_CHMASK_CH9MASK    0x100U   // MPU region channel mask Channel 9
#define RTDMA_MPUR_CHMASK_CH10MASK   0x200U   // MPU region channel mask Channel 10

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR_START register
//
//*************************************************************************************************
#define RTDMA_MPUR_START_ADDRL_S   12U
#define RTDMA_MPUR_START_ADDRL_M   0xF000U       // Lower Start Address
#define RTDMA_MPUR_START_ADDRH_S   16U
#define RTDMA_MPUR_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR_END register
//
//*************************************************************************************************
#define RTDMA_MPUR_END_ADDRL_S   12U
#define RTDMA_MPUR_END_ADDRL_M   0xF000U       // Lower End Address
#define RTDMA_MPUR_END_ADDRH_S   16U
#define RTDMA_MPUR_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR_LOCK register
//
//*************************************************************************************************
#define RTDMA_MPUR_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR_COMMIT register
//
//*************************************************************************************************
#define RTDMA_MPUR_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR_ACCESS register
//
//*************************************************************************************************
#define RTDMA_MPUR_ACCESS_ACCESS_S   0U
#define RTDMA_MPUR_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUCTRL register
//
//*************************************************************************************************
#define RTDMA_MPUCTRL_MPUEN   0x1U   // Enable MPU function

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUCFG_LOCK register
//
//*************************************************************************************************
#define RTDMA_MPUCFG_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUCFG_COMMIT register
//
//*************************************************************************************************
#define RTDMA_MPUCFG_COMMIT_COMMIT   0x1U   // Permanent Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the MODE register
//
//*************************************************************************************************
#define RTDMA_MODE_PERINTSEL_S      0U
#define RTDMA_MODE_PERINTSEL_M      0xFFU       // Peripheral Interrupt and Sync Select
#define RTDMA_MODE_OVRINTE          0x400U      // Overflow Interrupt Enable
#define RTDMA_MODE_PERINTE          0x800U      // Peripheral Interrupt Enable
#define RTDMA_MODE_CHINTMODE        0x1000U     // Channel Interrupt Mode
#define RTDMA_MODE_ONESHOT          0x2000U     // One Shot Mode Bit
#define RTDMA_MODE_CONTINUOUS       0x4000U     // Continuous Mode Bit
#define RTDMA_MODE_DATASIZE_S       17U
#define RTDMA_MODE_DATASIZE_M       0x60000U    // Data Size Mode Bit
#define RTDMA_MODE_CHINTE           0x80000U    // Channel Interrupt Enable Bit
#define RTDMA_MODE_WRT_DATASIZE_S   20U
#define RTDMA_MODE_WRT_DATASIZE_M   0x300000U   // Write Data Size Mode Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONTROL register
//
//*************************************************************************************************
#define RTDMA_CONTROL_RUN           0x1U      // Run Bit
#define RTDMA_CONTROL_HALT          0x2U      // Halt Bit
#define RTDMA_CONTROL_SOFTRESET     0x4U      // Soft Reset Bit
#define RTDMA_CONTROL_PERINTFRC     0x8U      // Interrupt Force Bit
#define RTDMA_CONTROL_PERINTCLR     0x10U     // Interrupt Clear Bit
#define RTDMA_CONTROL_ERRCLR        0x80U     // Error Clear Bit
#define RTDMA_CONTROL_PERINTFLG     0x100U    // Interrupt Flag Bit
#define RTDMA_CONTROL_TRANSFERSTS   0x800U    // Transfer Status Bit
#define RTDMA_CONTROL_BURSTSTS      0x1000U   // Burst Status Bit
#define RTDMA_CONTROL_RUNSTS        0x2000U   // Run Status Bit
#define RTDMA_CONTROL_OVRFLG        0x4000U   // Overflow Flag Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the BURST_SIZE register
//
//*************************************************************************************************
#define RTDMA_BURST_SIZE_BURSTSIZE_S   0U
#define RTDMA_BURST_SIZE_BURSTSIZE_M   0xFFU   // Burst Transfer Size

//*************************************************************************************************
//
// The following are defines for the bit fields in the BURST_COUNT register
//
//*************************************************************************************************
#define RTDMA_BURST_COUNT_BURSTCOUNT_S   0U
#define RTDMA_BURST_COUNT_BURSTCOUNT_M   0xFFU   // Burst Transfer Size

//*************************************************************************************************
//
// The following are defines for the bit fields in the SRC_BURST_STEP register
//
//*************************************************************************************************
#define RTDMA_SRC_BURST_STEP_SRCBURSTSTEP_S   0U
#define RTDMA_SRC_BURST_STEP_SRCBURSTSTEP_M   0xFFFFU   // Source post-increment/decrement step
                                                        // size of a burst

//*************************************************************************************************
//
// The following are defines for the bit fields in the DST_BURST_STEP register
//
//*************************************************************************************************
#define RTDMA_DST_BURST_STEP_DSTBURSTSTEP_S   0U
#define RTDMA_DST_BURST_STEP_DSTBURSTSTEP_M   0xFFFFU   // Destination post-increment/decrement
                                                        // step size of a burst

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRANSFER_SIZE register
//
//*************************************************************************************************
#define RTDMA_TRANSFER_SIZE_TRANSFERSIZE_S   0U
#define RTDMA_TRANSFER_SIZE_TRANSFERSIZE_M   0xFFFFU   // These bits specify the number of bursts
                                                       // to transfer:

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRANSFER_COUNT register
//
//*************************************************************************************************
#define RTDMA_TRANSFER_COUNT_TRANSFERCOUNT_S   0U
#define RTDMA_TRANSFER_COUNT_TRANSFERCOUNT_M   0xFFFFU   // These bits specify the current transfer
                                                         // counter value:

//*************************************************************************************************
//
// The following are defines for the bit fields in the SRC_TRANSFER_STEP register
//
//*************************************************************************************************
#define RTDMA_SRC_TRANSFER_STEP_SRCTRANSFERSTEP_S   0U
#define RTDMA_SRC_TRANSFER_STEP_SRCTRANSFERSTEP_M   0xFFFFU   // Source post-increment/decrement
                                                              // step size of a transfer

//*************************************************************************************************
//
// The following are defines for the bit fields in the DST_TRANSFER_STEP register
//
//*************************************************************************************************
#define RTDMA_DST_TRANSFER_STEP_DSTTRANSFERSTEP_S   0U
#define RTDMA_DST_TRANSFER_STEP_DSTTRANSFERSTEP_M   0xFFFFU   // Destination
                                                              // post-increment/decrement step size
                                                              // of a transfer

//*************************************************************************************************
//
// The following are defines for the bit fields in the SRC_WRAP_SIZE register
//
//*************************************************************************************************
#define RTDMA_SRC_WRAP_SIZE_WRAPSIZE_S   0U
#define RTDMA_SRC_WRAP_SIZE_WRAPSIZE_M   0xFFFFU   // Number of bursts to transfer before wrapping

//*************************************************************************************************
//
// The following are defines for the bit fields in the SRC_WRAP_COUNT register
//
//*************************************************************************************************
#define RTDMA_SRC_WRAP_COUNT_WRAPSIZE_S   0U
#define RTDMA_SRC_WRAP_COUNT_WRAPSIZE_M   0xFFFFU   // These bits indicate the current wrap counter
                                                    // value:

//*************************************************************************************************
//
// The following are defines for the bit fields in the SRC_WRAP_STEP register
//
//*************************************************************************************************
#define RTDMA_SRC_WRAP_STEP_WRAPSTEP_S   0U
#define RTDMA_SRC_WRAP_STEP_WRAPSTEP_M   0xFFFFU   // Source post-increment/decrement step size for
                                                   // a wrap

//*************************************************************************************************
//
// The following are defines for the bit fields in the DST_WRAP_SIZE register
//
//*************************************************************************************************
#define RTDMA_DST_WRAP_SIZE_WRAPSIZE_S   0U
#define RTDMA_DST_WRAP_SIZE_WRAPSIZE_M   0xFFFFU   // Number of bursts to transfer before wrapping

//*************************************************************************************************
//
// The following are defines for the bit fields in the DST_WRAP_COUNT register
//
//*************************************************************************************************
#define RTDMA_DST_WRAP_COUNT_WRAPSIZE_S   0U
#define RTDMA_DST_WRAP_COUNT_WRAPSIZE_M   0xFFFFU   // These bits indicate the current wrap counter
                                                    // value:

//*************************************************************************************************
//
// The following are defines for the bit fields in the DST_WRAP_STEP register
//
//*************************************************************************************************
#define RTDMA_DST_WRAP_STEP_WRAPSTEP_S   0U
#define RTDMA_DST_WRAP_STEP_WRAPSTEP_M   0xFFFFU   // Destination post-increment/decrement step
                                                   // size for a wrap

//*************************************************************************************************
//
// The following are defines for the bit fields in the CHSECLAT1 register
//
//*************************************************************************************************
#define RTDMA_CHSECLAT1_ZONE_S      0U
#define RTDMA_CHSECLAT1_ZONE_M      0xFU         // Channel owner zone
#define RTDMA_CHSECLAT1_LINK_S      8U
#define RTDMA_CHSECLAT1_LINK_M      0xF00U       // Channel owner Link
#define RTDMA_CHSECLAT1_APILINK_S   16U
#define RTDMA_CHSECLAT1_APILINK_M   0xF0000U     // Channel owner Clink
#define RTDMA_CHSECLAT1_STACK_S     24U
#define RTDMA_CHSECLAT1_STACK_M     0xF000000U   // Channel owner Stack

//*************************************************************************************************
//
// The following are defines for the bit fields in the CHSECLAT2 register
//
//*************************************************************************************************
#define RTDMA_CHSECLAT2_SECURE     0x1U        // Channel SECURE Information
#define RTDMA_CHSECLAT2_PRIV_S     8U
#define RTDMA_CHSECLAT2_PRIV_M     0x300U      // Channel PRIV information
#define RTDMA_CHSECLAT2_PRIVID_S   16U
#define RTDMA_CHSECLAT2_PRIVID_M   0xFF0000U   // Channel PRIVID information

//*************************************************************************************************
//
// The following are defines for the bit fields in the BURST_INTF_CTRL register
//
//*************************************************************************************************
#define RTDMA_BURST_INTF_CTRL_BURSTCTRL_S   0U
#define RTDMA_BURST_INTF_CTRL_BURSTCTRL_M   0x3U   // Control Burst Interface operation

//*************************************************************************************************
//
// The following are defines for the bit fields in the CHCFG_LOCK register
//
//*************************************************************************************************
#define RTDMA_CHCFG_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CHCFG_COMMIT register
//
//*************************************************************************************************
#define RTDMA_CHCFG_COMMIT_COMMIT   0x1U   // Permanent Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the FLTEMU_CONFIG register
//
//*************************************************************************************************
#define RTDMA_FLTEMU_CONFIG_ENABLE           0x1U      // Fault emulation enable
#define RTDMA_FLTEMU_CONFIG_DBL_BIT_INJ_EN   0x2U      // Double bit injection enable
#define RTDMA_FLTEMU_CONFIG_KEY_S            8U
#define RTDMA_FLTEMU_CONFIG_KEY_M            0xFF00U   // Write Key
#define RTDMA_FLTEMU_CONFIG_KEY              0xA500U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the FLTEMU_ACCGRPSEL register
//
//*************************************************************************************************
#define RTDMA_FLTEMU_ACCGRPSEL_CTRL_GROUP_SEL_S   0U
#define RTDMA_FLTEMU_ACCGRPSEL_CTRL_GROUP_SEL_M   0xFFU     // CTRL group selection
#define RTDMA_FLTEMU_ACCGRPSEL_DATA_GROUP_SEL_S   8U
#define RTDMA_FLTEMU_ACCGRPSEL_DATA_GROUP_SEL_M   0xFF00U   // DATA READ1 control information bus
                                                            // selection

//*************************************************************************************************
//
// The following are defines for the bit fields in the FLTEMU_BITSEL register
//
//*************************************************************************************************
#define RTDMA_FLTEMU_BITSEL_BITSEL_S   0U
#define RTDMA_FLTEMU_BITSEL_BITSEL_M   0x7FU   // Fault emulation bit selection


//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_DATA2 register
//
//*************************************************************************************************
#define RTDMA_SELFTEST_DIAG_DATA2_SELFTEST_DIAG_DATA2_S   0U
#define RTDMA_SELFTEST_DIAG_DATA2_SELFTEST_DIAG_DATA2_M   0x1FFFFU   // Self test Diagnostics data
                                                                     // 2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_ECC register
//
//*************************************************************************************************
#define RTDMA_SELFTEST_DIAG_ECC_SELFTEST_DIAG_ECC_S   0U
#define RTDMA_SELFTEST_DIAG_ECC_SELFTEST_DIAG_ECC_M   0xFFU   // Self test Diagnostics ECC

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_CONTROL register
//
//*************************************************************************************************
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_TEST_EN_S       0U
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_TEST_EN_M       0xFU          // Diagnostic test enable
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_SAFETY_SEL      0x40U         // Diagnostic safety
                                                                       // selection
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_CHECKER_SEL_S   8U
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_CHECKER_SEL_M   0x300U        // ECC checker selection
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_ECC_WIDTH_S     16U
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_ECC_WIDTH_M     0xF0000U      // Diagnostic ECC width
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_DATA_WIDTH_S    24U
#define RTDMA_SELFTEST_DIAG_CONTROL_DIAG_DATA_WIDTH_M    0xFF000000U   // Diagnostic Data width

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_STATUS register
//
//*************************************************************************************************
#define RTDMA_SELFTEST_DIAG_STATUS_DIAG_TEST_DONE           0x2U      // Done self test
#define RTDMA_SELFTEST_DIAG_STATUS_DIAG_TEST_FAIL           0x4U      // Test failed
#define RTDMA_SELFTEST_DIAG_STATUS_DIAG_FAIL_C_ERROR        0x8U      // Diagnostic correctable
                                                                      // error
#define RTDMA_SELFTEST_DIAG_STATUS_DIAG_FAIL_UC_ERROR       0x10U     // Diagnostic uncorrectable
                                                                      // error
#define RTDMA_SELFTEST_DIAG_STATUS_DIAG_FAIL_CHECK_TYPE_S   5U
#define RTDMA_SELFTEST_DIAG_STATUS_DIAG_FAIL_CHECK_TYPE_M   0x60U     // Failed diagnostic check
                                                                      // type
#define RTDMA_SELFTEST_DIAG_STATUS_DIAG_FAIL_BIT_INDEX_S    8U
#define RTDMA_SELFTEST_DIAG_STATUS_DIAG_FAIL_BIT_INDEX_M    0xFF00U   // Error bit position

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_STATUS_CLR register
//
//*************************************************************************************************
#define RTDMA_SELFTEST_DIAG_STATUS_CLR_DIAG_TEST_DONE   0x2U   // Clear self test done status flag
#define RTDMA_SELFTEST_DIAG_STATUS_CLR_DIAG_TEST_FAIL   0x4U   // Clear test failed status flags



#endif
