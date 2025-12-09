//###########################################################################
//
// FILE:    hw_error_aggregator.h
//
// TITLE:   Definitions for the ERROR_AGGREGATOR registers.
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

#ifndef HW_ERROR_AGGREGATOR_H
#define HW_ERROR_AGGREGATOR_H

//*************************************************************************************************
//
// The following are defines for the ERROR_AGGREGATOR register offsets
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_O_HSM_HIGHPRIO_ERROR_ADDRESS   0x0U    // High Priority Error address
                                                                // register
#define ERROR_AGGREGATOR_O_HSM_LOWPRIO_ERROR_ADDRESS    0x4U    // Low Priority Error address
                                                                // register
#define ERROR_AGGREGATOR_O_HSM_ERROR_TYPE               0x8U    // Error Type Register
#define ERROR_AGGREGATOR_O_HSM_ERROR_TYPE_FRC           0xCU    // Error Type Force Register
#define ERROR_AGGREGATOR_O_HSM_ERROR_TYPE_CLR           0x10U   // Error Type Clear Register

#define ERROR_AGGREGATOR_O_CPU1_PR_HIGHPRIO_ERROR_ADDRESS     0x0U     // CPU1 PR Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_PR_LOWPRIO_ERROR_ADDRESS      0x4U     // CPU1 PR Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_PR_ERROR_TYPE                 0x8U     // CPU1 PR Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU1_PR_ERROR_TYPE_FRC             0xCU     // CPU1 PR Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU1_PR_ERROR_TYPE_CLR             0x10U    // CPU1 PR Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU1_PR_PC                         0x14U    // CPU1 PR Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU1_DR1_HIGHPRIO_ERROR_ADDRESS    0x40U    // CPU1 DR1 Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_DR1_LOWPRIO_ERROR_ADDRESS     0x44U    // CPU1 DR1 Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_DR1_ERROR_TYPE                0x48U    // CPU1 DR1 Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU1_DR1_ERROR_TYPE_FRC            0x4CU    // CPU1 DR1 Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU1_DR1_ERROR_TYPE_CLR            0x50U    // CPU1 DR1 Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU1_DR1_PC                        0x54U    // CPU1 DR1 Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU1_DR2_HIGHPRIO_ERROR_ADDRESS    0x80U    // CPU1 DR2 Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_DR2_LOWPRIO_ERROR_ADDRESS     0x84U    // CPU1 DR2 Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_DR2_ERROR_TYPE                0x88U    // CPU1 DR2 Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU1_DR2_ERROR_TYPE_FRC            0x8CU    // CPU1 DR2 Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU1_DR2_ERROR_TYPE_CLR            0x90U    // CPU1 DR2 Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU1_DR2_PC                        0x94U    // CPU1 DR2 Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU1_DW_HIGHPRIO_ERROR_ADDRESS     0xC0U    // CPU1 DW Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_DW_LOWPRIO_ERROR_ADDRESS      0xC4U    // CPU1 DW Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_DW_ERROR_TYPE                 0xC8U    // CPU1 DW Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU1_DW_ERROR_TYPE_FRC             0xCCU    // CPU1 DW Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU1_DW_ERROR_TYPE_CLR             0xD0U    // CPU1 DW Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU1_DW_PC                         0xD4U    // CPU1 DW Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU1_INT_HIGHPRIO_ERROR_ADDRESS    0x100U   // CPU1 INT Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_INT_LOWPRIO_ERROR_ADDRESS     0x104U   // CPU1 INT Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU1_INT_ERROR_TYPE                0x108U   // CPU1 INT Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU1_INT_ERROR_TYPE_FRC            0x10CU   // CPU1 INT Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU1_INT_ERROR_TYPE_CLR            0x110U   // CPU1 INT Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU1_INT_PC                        0x114U   // CPU1 INT Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU2_PR_HIGHPRIO_ERROR_ADDRESS     0x140U   // CPU2 PR Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_PR_LOWPRIO_ERROR_ADDRESS      0x144U   // CPU2 PR Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_PR_ERROR_TYPE                 0x148U   // CPU2 PR Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU2_PR_ERROR_TYPE_FRC             0x14CU   // CPU2 PR Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU2_PR_ERROR_TYPE_CLR             0x150U   // CPU2 PR Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU2_PR_PC                         0x154U   // CPU2 PR Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU2_DR1_HIGHPRIO_ERROR_ADDRESS    0x180U   // CPU2 DR1 Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_DR1_LOWPRIO_ERROR_ADDRESS     0x184U   // CPU2 DR1 Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_DR1_ERROR_TYPE                0x188U   // CPU2 DR1 Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU2_DR1_ERROR_TYPE_FRC            0x18CU   // CPU2 DR1 Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU2_DR1_ERROR_TYPE_CLR            0x190U   // CPU2 DR1 Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU2_DR1_PC                        0x194U   // CPU2 DR1 Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU2_DR2_HIGHPRIO_ERROR_ADDRESS    0x1C0U   // CPU2 DR2 Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_DR2_LOWPRIO_ERROR_ADDRESS     0x1C4U   // CPU2 DR2 Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_DR2_ERROR_TYPE                0x1C8U   // CPU2 DR2 Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU2_DR2_ERROR_TYPE_FRC            0x1CCU   // CPU2 DR2 Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU2_DR2_ERROR_TYPE_CLR            0x1D0U   // CPU2 DR2 Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU2_DR2_PC                        0x1D4U   // CPU2 DR2 Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU2_DW_HIGHPRIO_ERROR_ADDRESS     0x200U   // CPU2 DW Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_DW_LOWPRIO_ERROR_ADDRESS      0x204U   // CPU2 DW Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_DW_ERROR_TYPE                 0x208U   // CPU2 DW Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU2_DW_ERROR_TYPE_FRC             0x20CU   // CPU2 DW Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU2_DW_ERROR_TYPE_CLR             0x210U   // CPU2 DW Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU2_DW_PC                         0x214U   // CPU2 DW Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU2_INT_HIGHPRIO_ERROR_ADDRESS    0x240U   // CPU2 INT Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_INT_LOWPRIO_ERROR_ADDRESS     0x244U   // CPU2 INT Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU2_INT_ERROR_TYPE                0x248U   // CPU2 INT Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU2_INT_ERROR_TYPE_FRC            0x24CU   // CPU2 INT Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU2_INT_ERROR_TYPE_CLR            0x250U   // CPU2 INT Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU2_INT_PC                        0x254U   // CPU2 INT Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU3_PR_HIGHPRIO_ERROR_ADDRESS     0x280U   // CPU3 PR Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_PR_LOWPRIO_ERROR_ADDRESS      0x284U   // CPU3 PR Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_PR_ERROR_TYPE                 0x288U   // CPU3 PR Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU3_PR_ERROR_TYPE_FRC             0x28CU   // CPU3 PR Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU3_PR_ERROR_TYPE_CLR             0x290U   // CPU3 PR Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU3_PR_PC                         0x294U   // CPU3 PR Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU3_DR1_HIGHPRIO_ERROR_ADDRESS    0x2C0U   // CPU3 DR1 Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_DR1_LOWPRIO_ERROR_ADDRESS     0x2C4U   // CPU3 DR1 Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_DR1_ERROR_TYPE                0x2C8U   // CPU3 DR1 Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU3_DR1_ERROR_TYPE_FRC            0x2CCU   // CPU3 DR1 Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU3_DR1_ERROR_TYPE_CLR            0x2D0U   // CPU3 DR1 Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU3_DR1_PC                        0x2D4U   // CPU3 DR1 Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU3_DR2_HIGHPRIO_ERROR_ADDRESS    0x300U   // CPU3 DR2 Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_DR2_LOWPRIO_ERROR_ADDRESS     0x304U   // CPU3 DR2 Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_DR2_ERROR_TYPE                0x308U   // CPU3 DR2 Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU3_DR2_ERROR_TYPE_FRC            0x30CU   // CPU3 DR2 Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU3_DR2_ERROR_TYPE_CLR            0x310U   // CPU3 DR2 Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU3_DR2_PC                        0x314U   // CPU3 DR2 Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU3_DW_HIGHPRIO_ERROR_ADDRESS     0x340U   // CPU3 DW Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_DW_LOWPRIO_ERROR_ADDRESS      0x344U   // CPU3 DW Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_DW_ERROR_TYPE                 0x348U   // CPU3 DW Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU3_DW_ERROR_TYPE_FRC             0x34CU   // CPU3 DW Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU3_DW_ERROR_TYPE_CLR             0x350U   // CPU3 DW Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU3_DW_PC                         0x354U   // CPU3 DW Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_CPU3_INT_HIGHPRIO_ERROR_ADDRESS    0x380U   // CPU3 INT Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_INT_LOWPRIO_ERROR_ADDRESS     0x384U   // CPU3 INT Error aggregator
                                                                       // Low Priority Error address register
#define ERROR_AGGREGATOR_O_CPU3_INT_ERROR_TYPE                0x388U   // CPU3 INT Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_CPU3_INT_ERROR_TYPE_FRC            0x38CU   // CPU3 INT Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_CPU3_INT_ERROR_TYPE_CLR            0x390U   // CPU3 INT Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_CPU3_INT_PC                        0x394U   // CPU3 INT Error aggregator
                                                                       // Register to store PC value at the
                                                                       // first High priority error event
#define ERROR_AGGREGATOR_O_RTDMA1_DR_HIGHPRIO_ERROR_ADDRESS   0x780U   // RTDMA1 DR Error
                                                                       // aggregator High Priority Error
                                                                       // address register
#define ERROR_AGGREGATOR_O_RTDMA1_DR_LOWPRIO_ERROR_ADDRESS    0x784U   // RTDMA1 DR Error
                                                                       // aggregator Low Priority Error
                                                                       // address register
#define ERROR_AGGREGATOR_O_RTDMA1_DR_ERROR_TYPE               0x788U   // RTDMA1 DR Error
                                                                       // aggregator Error Type Register
#define ERROR_AGGREGATOR_O_RTDMA1_DR_ERROR_TYPE_FRC           0x78CU   // RTDMA1 DR Error
                                                                       // aggregator Error Type Force Register
#define ERROR_AGGREGATOR_O_RTDMA1_DR_ERROR_TYPE_CLR           0x790U   // RTDMA1 DR Error
                                                                       // aggregator Error Type Clear Register
#define ERROR_AGGREGATOR_O_RTDMA1_DW_HIGHPRIO_ERROR_ADDRESS   0x7C0U   // RTDMA1 DW Error
                                                                       // aggregator High Priority Error
                                                                       // address register
#define ERROR_AGGREGATOR_O_RTDMA1_DW_LOWPRIO_ERROR_ADDRESS    0x7C4U   // RTDMA1 DW Error
                                                                       // aggregator Low Priority Error
                                                                       // address register
#define ERROR_AGGREGATOR_O_RTDMA1_DW_ERROR_TYPE               0x7C8U   // RTDMA1 DW Error
                                                                       // aggregator Error Type Register
#define ERROR_AGGREGATOR_O_RTDMA1_DW_ERROR_TYPE_FRC           0x7CCU   // RTDMA1 DW Error
                                                                       // aggregator Error Type Force Register
#define ERROR_AGGREGATOR_O_RTDMA1_DW_ERROR_TYPE_CLR           0x7D0U   // RTDMA1 DW Error
                                                                       // aggregator Error Type Clear Register
#define ERROR_AGGREGATOR_O_RTDMA2_DR_HIGHPRIO_ERROR_ADDRESS   0x800U   // RTDMA2 DR Error
                                                                       // aggregator High Priority Error
                                                                       // address register
#define ERROR_AGGREGATOR_O_RTDMA2_DR_LOWPRIO_ERROR_ADDRESS    0x804U   // RTDMA2 DR Error
                                                                       // aggregator Low Priority Error
                                                                       // address register
#define ERROR_AGGREGATOR_O_RTDMA2_DR_ERROR_TYPE               0x808U   // RTDMA2 DR Error
                                                                       // aggregator Error Type Register
#define ERROR_AGGREGATOR_O_RTDMA2_DR_ERROR_TYPE_FRC           0x80CU   // RTDMA2 DR Error
                                                                       // aggregator Error Type Force Register
#define ERROR_AGGREGATOR_O_RTDMA2_DR_ERROR_TYPE_CLR           0x810U   // RTDMA2 DR Error
                                                                       // aggregator Error Type Clear Register
#define ERROR_AGGREGATOR_O_RTDMA2_DW_HIGHPRIO_ERROR_ADDRESS   0x840U   // RTDMA2 DW Error
                                                                       // aggregator High Priority Error
                                                                       // address register
#define ERROR_AGGREGATOR_O_RTDMA2_DW_LOWPRIO_ERROR_ADDRESS    0x844U   // RTDMA2 DW Error
                                                                       // aggregator Low Priority Error
                                                                       // address register
#define ERROR_AGGREGATOR_O_RTDMA2_DW_ERROR_TYPE               0x848U   // RTDMA2 DW Error
                                                                       // aggregator Error Type Register
#define ERROR_AGGREGATOR_O_RTDMA2_DW_ERROR_TYPE_FRC           0x84CU   // RTDMA2 DW Error
                                                                       // aggregator Error Type Force Register
#define ERROR_AGGREGATOR_O_RTDMA2_DW_ERROR_TYPE_CLR           0x850U   // RTDMA2 DW Error
                                                                       // aggregator Error Type Clear Register
#define ERROR_AGGREGATOR_O_SSU_HIGHPRIO_ERROR_ADDRESS         0x880U   // SSU Error aggregator High
                                                                       // Priority Error address register
#define ERROR_AGGREGATOR_O_SSU_ERROR_TYPE                     0x888U   // SSU Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_SSU_ERROR_TYPE_FRC                 0x88CU   // SSU Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_SSU_ERROR_TYPE_CLR                 0x890U   // SSU Error aggregator
                                                                       // Error Type Clear Register
#define ERROR_AGGREGATOR_O_ETHERCAT_HIGHPRIO_ERROR_ADDRESS    0x8C0U   // ETHERCAT Error aggregator
                                                                       // High Priority Error address register
#define ERROR_AGGREGATOR_O_ETHERCAT_ERROR_TYPE                0x8C8U   // ETHERCAT Error aggregator
                                                                       // Error Type Register
#define ERROR_AGGREGATOR_O_ETHERCAT_ERROR_TYPE_FRC            0x8CCU   // ETHERCAT Error aggregator
                                                                       // Error Type Force Register
#define ERROR_AGGREGATOR_O_ETHERCAT_ERROR_TYPE_CLR            0x8D0U   // ETHERCAT Error aggregator
                                                                       // Error Type Clear Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the HSM_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_SECURITY_VIO      0x1U          // Security violation
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_ACC_TIMEOUT_ERR   0x10U         // Access timeout error
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_ACC_ACK_ERR       0x20U         // Access ACK error
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_UNCERR            0x40U         // Uncorrectable error
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CERR              0x80U         // Correctable error
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_ACC_TYPE_READ     0x4000U       // Access type Read
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_ACC_TYPE_WRITE    0x8000U       // Access type write
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_LP_SOFTWARE_ERR   0x40000000U   // Low Priority error set
                                                                        // by software
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_HP_SOFTWARE_ERR   0x80000000U   // High Priority error set
                                                                        // by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the HSM_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_SECURITY_VIO      0x1U          // Security violation
                                                                            // force
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR   0x10U         // Access timeout error
                                                                            // force
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_ACC_ACK_ERR       0x20U         // Access ACK error
                                                                            // force
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_UNCERR            0x40U         // Uncorrectable error
                                                                            // force
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_CERR              0x80U         // Correctable error
                                                                            // force
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_ACC_TYPE_READ     0x4000U       // Access type Read
                                                                            // force
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_ACC_TYPE_WRITE    0x8000U       // Access type write
                                                                            // force
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_LP_SOFTWARE_ERR   0x40000000U   // Force low priority
                                                                            // software error
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_FRC_HP_SOFTWARE_ERR   0x80000000U   // Force high priority
                                                                            // software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the HSM_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_SECURITY_VIO      0x1U          // Security violation
                                                                            // clear
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR   0x10U         // Access timeout error
                                                                            // clear
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_ACC_ACK_ERR       0x20U         // Access ACK error
                                                                            // clear
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_UNCERR            0x40U         // Uncorrectable error
                                                                            // clear
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_CERR              0x80U         // Correctable error
                                                                            // clear
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_ACC_TYPE_READ     0x4000U       // Access type Read
                                                                            // clear
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_ACC_TYPE_WRITE    0x8000U       // Access type write
                                                                            // clear
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_LP_SOFTWARE_ERR   0x40000000U   // clear low priority
                                                                            // software error
#define ERROR_AGGREGATOR_HSM_ERROR_TYPE_CLR_HP_SOFTWARE_ERR   0x80000000U   // clear high priority
                                                                            // software error


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_PR_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                // packet security violation.
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_SEC_ENTRY_VIO         0x2U          // Secure entry and
                                                                                // linear code crossing error.
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_MAX_PSP_ERR           0x8U          //  MAX PSP error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_ACC_TIMEOUT_ERR       0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_ACC_ACK_ERR           0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_UNCERR                0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CERR                  0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_WARN_PSP_ERR          0x100U        // Warn PSP error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                // brakepoint error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                // instruction error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                // timeout error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_LP_SOFTWARE_ERR       0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_HP_SOFTWARE_ERR       0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_PR_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                    // packet security violation force.
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_SEC_ENTRY_VIO         0x2U          // Secure entry
                                                                                    // and linear code crossing error
                                                                                    // force.
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_MAX_PSP_ERR           0x8U          // MAX PSP
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR       0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_ACC_ACK_ERR           0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_UNCERR                0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_CERR                  0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_WARN_PSP_ERR          0x100U        // Warn PSP
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                    // brakepoint error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                    // instruction error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_LP_SOFTWARE_ERR       0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_FRC_HP_SOFTWARE_ERR       0x80000000U   // Force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_PR_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                    // packet security violation clear.
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_SEC_ENTRY_VIO         0x2U          // Secure entry
                                                                                    // and linear code crossing error
                                                                                    // clear.
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_MAX_PSP_ERR           0x8U          // MAX PSP
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR       0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_ACC_ACK_ERR           0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_UNCERR                0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_CERR                  0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_WARN_PSP_ERR          0x100U        // Warn PSP
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                    // brakepoint error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                    // instruction error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_LP_SOFTWARE_ERR       0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU1_PR_ERROR_TYPE_CLR_HP_SOFTWARE_ERR       0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DR1_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                                // violation
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CERR                 0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                // address error
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DR1_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                    // violation force
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_FRC_UNCERR               0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error force
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DR1_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                    // violation clear
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CLR_UNCERR               0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error clear
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU1_DR1_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DR2_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                                // violation
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CERR                 0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                // address error
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DR2_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                    // violation force
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_FRC_UNCERR               0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error force
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DR2_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                    // violation clear
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CLR_UNCERR               0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error clear
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU1_DR2_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DW_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                               // violation
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                               // error
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                               // error
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CERR                 0x80U         // Correctable error
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned address
                                                                               // error
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                               // error set by software
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                               // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DW_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                   // violation force
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                   // timeout error force
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_FRC_UNCERR               0x40U         // Uncorrectable
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                   // address error force
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                   // priority software error
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                   // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_DW_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                   // violation clear
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                   // timeout error clear
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CLR_UNCERR               0x40U         // Uncorrectable
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                   // address error clear
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                   // priority software error
#define ERROR_AGGREGATOR_CPU1_DW_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                   // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_INT_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                               // Main ISR entry error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_MAIN_VECT_CERR                      0x2U          //
                                                                                               // Main Correctable vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_MAIN_VECT_UNCERR                    0x4U          //
                                                                                               // Main Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                               // Main Interrupt return error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                               // INT ISR entry error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_INT_VECT_CERR                       0x20U         //
                                                                                               // INT Correctable vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_INT_VECT_UNCERR                     0x40U         //
                                                                                               // INT Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                               // INT INTerrupt return error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                               // RTINT ISR entry error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_RTINT_VECT_CERR                     0x200U        //
                                                                                               // RTINT Correctable vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_RTINT_VECT_UNCERR                   0x400U        //
                                                                                               // RTINT Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                               // RTINT Interrupt return error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                               // RTINT Context restore Correctable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                               // RTINT Context restore Uncorrectable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_NMI_MAXISP_ERR                      0x8000U       //
                                                                                               // NMI MAXISP error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                               // NMI ISR entry error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_NMI_VECT_CERR                       0x20000U      //
                                                                                               // NMI Correctable vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_NMI_VECT_UNCERR                     0x40000U      //
                                                                                               // NMI Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                               // NMI Interrupt return error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                               // NMI Context restore Correctable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                               // NMI Context restore Uncorrectable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_VECT_CERR                           0x400000U     //
                                                                                               // Vector Correctable error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_VECT_UNCERR                         0x800000U     //
                                                                                               // Vector Uncorrectable error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_WARNISP                             0x1000000U    //
                                                                                               // warnisp
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_MAXISP                              0x2000000U    //
                                                                                               // maxisp
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                               // PIPE security violation
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_REG_PARITY_ERR                      0x8000000U    //
                                                                                               // PIPE Reg parity error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                               // PIPE Register parity diag error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                               // PIPE Lock/key error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                               // Low Priority error set by software
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                               // high priority error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_INT_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                                   // Main ISR entry error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_MAIN_VECT_CERR                      0x2U          //
                                                                                                   // Main Correctable vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_MAIN_VECT_UNCERR                    0x4U          //
                                                                                                   // Main Uncorrectable vector error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                                   // Main Interrupt return error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                                   // INT ISR entry error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_INT_VECT_CERR                       0x20U         //
                                                                                                   // INT Correctable vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_INT_VECT_UNCERR                     0x40U         //
                                                                                                   // INT Uncorrectable vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                                   // INT INTerrupt return error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                                   // RTINT ISR entry error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_RTINT_VECT_CERR                     0x200U        //
                                                                                                   // RTINT Correctable vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_RTINT_VECT_UNCERR                   0x400U        //
                                                                                                   // RTINT Uncorrectable vector error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                                   // RTINT Interrupt return error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                                   // RTINT Context restore Correctable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                                   // RTINT Context restore Uncorrectable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_NMI_MAXISP_ERR                      0x8000U       //
                                                                                                   // NMI MAXISP error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                                   // NMI ISR entry error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_NMI_VECT_CERR                       0x20000U      //
                                                                                                   // NMI Correctable vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_NMI_VECT_UNCERR                     0x40000U      //
                                                                                                   // NMI Uncorrectable vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                                   // NMI Interrupt return error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                                   // NMI Context restore Correctable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                                   // NMI Context restore Uncorrectable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_VECT_CERR                           0x400000U     //
                                                                                                   // Vector Correctable error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_VECT_UNCERR                         0x800000U     //
                                                                                                   // Vector Uncorrectable error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_WARNISP                             0x1000000U    //
                                                                                                   // warnisp force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_MAXISP                              0x2000000U    //
                                                                                                   // maxisp force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                                   // PIPE security violation force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_REG_PARITY_ERR                      0x8000000U    //
                                                                                                   // PIPE Reg parity error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                                   // PIPE Register parity diag error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                                   // PIPE Lock key error force
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                                   // Force low priority software error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_FRC_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                                   // force high priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1_INT_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                                   // Main ISR entry error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_MAIN_VECT_CERR                      0x2U          //
                                                                                                   // Main Correctable vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_MAIN_VECT_UNCERR                    0x4U          //
                                                                                                   // Main Uncorrectable vector error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                                   // Main Interrupt return error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                                   // INT ISR entry error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_INT_VECT_CERR                       0x20U         //
                                                                                                   // INT Correctable vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_INT_VECT_UNCERR                     0x40U         //
                                                                                                   // INT Uncorrectable vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                                   // INT INTerrupt return error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                                   // RTINT ISR entry error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_RTINT_VECT_CERR                     0x200U        //
                                                                                                   // RTINT Correctable vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_RTINT_VECT_UNCERR                   0x400U        //
                                                                                                   // RTINT Uncorrectable vector error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                                   // RTINT Interrupt return error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                                   // RTINT Context restore Correctable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                                   // RTINT Context restore Uncorrectable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_NMI_MAXISP_ERR                      0x8000U       //
                                                                                                   // NMI MAXISP error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                                   // NMI ISR entry error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_NMI_VECT_CERR                       0x20000U      //
                                                                                                   // NMI Correctable vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_NMI_VECT_UNCERR                     0x40000U      //
                                                                                                   // NMI Uncorrectable vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                                   // NMI Interrupt return error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                                   // NMI Context restore Correctable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                                   // NMI Context restore Uncorrectable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_VECT_CERR                           0x400000U     //
                                                                                                   // Vector Correctable error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_VECT_UNCERR                         0x800000U     //
                                                                                                   // Vector Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_WARNISP                             0x1000000U    //
                                                                                                   // warnisp clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_MAXISP                              0x2000000U    //
                                                                                                   // maxisp clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                                   // PIPE security violation clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_REG_PARITY_ERR                      0x8000000U    //
                                                                                                   // PIPE Reg parity error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                                   // PIPE Register parity diag error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                                   // PIPE Lock key error clear
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                                   // clear low priority software error
#define ERROR_AGGREGATOR_CPU1_INT_ERROR_TYPE_CLR_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                                   // clear high priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_PR_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                // packet security violation.
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_SEC_ENTRY_VIO         0x2U          // Secure entry and
                                                                                // linear code crossing error.
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_MAX_PSP_ERR           0x8U          //  MAX PSP error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_ACC_TIMEOUT_ERR       0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_ACC_ACK_ERR           0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_UNCERR                0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CERR                  0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_WARN_PSP_ERR          0x100U        // Warn PSP error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                // brakepoint error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                // instruction error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                // timeout error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_LP_SOFTWARE_ERR       0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_HP_SOFTWARE_ERR       0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_PR_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                    // packet security violation force.
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_SEC_ENTRY_VIO         0x2U          // Secure entry
                                                                                    // and linear code crossing error
                                                                                    // force.
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_MAX_PSP_ERR           0x8U          // MAX PSP
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR       0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_ACC_ACK_ERR           0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_UNCERR                0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_CERR                  0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_WARN_PSP_ERR          0x100U        // Warn PSP
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                    // brakepoint error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                    // instruction error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_LP_SOFTWARE_ERR       0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_FRC_HP_SOFTWARE_ERR       0x80000000U   // Force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_PR_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                    // packet security violation clear.
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_SEC_ENTRY_VIO         0x2U          // Secure entry
                                                                                    // and linear code crossing error
                                                                                    // clear.
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_MAX_PSP_ERR           0x8U          // MAX PSP
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR       0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_ACC_ACK_ERR           0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_UNCERR                0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_CERR                  0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_WARN_PSP_ERR          0x100U        // Warn PSP
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                    // brakepoint error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                    // instruction error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_LP_SOFTWARE_ERR       0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU2_PR_ERROR_TYPE_CLR_HP_SOFTWARE_ERR       0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DR1_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                                // violation
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CERR                 0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                // address error
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DR1_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                    // violation force
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_FRC_UNCERR               0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error force
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DR1_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                    // violation clear
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CLR_UNCERR               0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error clear
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU2_DR1_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DR2_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                                // violation
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CERR                 0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                // address error
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DR2_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                    // violation force
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_FRC_UNCERR               0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error force
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DR2_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                    // violation clear
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CLR_UNCERR               0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error clear
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU2_DR2_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DW_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                               // violation
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                               // error
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                               // error
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CERR                 0x80U         // Correctable error
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned address
                                                                               // error
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                               // error set by software
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                               // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DW_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                   // violation force
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                   // timeout error force
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_FRC_UNCERR               0x40U         // Uncorrectable
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                   // address error force
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                   // priority software error
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                   // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_DW_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                   // violation clear
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                   // timeout error clear
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CLR_UNCERR               0x40U         // Uncorrectable
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                   // address error clear
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                   // priority software error
#define ERROR_AGGREGATOR_CPU2_DW_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                   // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_INT_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                               // Main ISR entry error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_MAIN_VECT_CERR                      0x2U          //
                                                                                               // Main Correctable vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_MAIN_VECT_UNCERR                    0x4U          //
                                                                                               // Main Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                               // Main Interrupt return error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                               // INT ISR entry error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_INT_VECT_CERR                       0x20U         //
                                                                                               // INT Correctable vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_INT_VECT_UNCERR                     0x40U         //
                                                                                               // INT Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                               // INT INTerrupt return error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                               // RTINT ISR entry error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_RTINT_VECT_CERR                     0x200U        //
                                                                                               // RTINT Correctable vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_RTINT_VECT_UNCERR                   0x400U        //
                                                                                               // RTINT Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                               // RTINT Interrupt return error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                               // RTINT Context restore Correctable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                               // RTINT Context restore Uncorrectable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_NMI_MAXISP_ERR                      0x8000U       //
                                                                                               // NMI MAXISP error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                               // NMI ISR entry error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_NMI_VECT_CERR                       0x20000U      //
                                                                                               // NMI Correctable vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_NMI_VECT_UNCERR                     0x40000U      //
                                                                                               // NMI Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                               // NMI Interrupt return error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                               // NMI Context restore Correctable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                               // NMI Context restore Uncorrectable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_VECT_CERR                           0x400000U     //
                                                                                               // Vector Correctable error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_VECT_UNCERR                         0x800000U     //
                                                                                               // Vector Uncorrectable error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_WARNISP                             0x1000000U    //
                                                                                               // warnisp
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_MAXISP                              0x2000000U    //
                                                                                               // maxisp
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                               // PIPE security violation
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_REG_PARITY_ERR                      0x8000000U    //
                                                                                               // PIPE Reg parity error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                               // PIPE Register parity diag error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                               // PIPE Lock/key error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                               // Low Priority error set by software
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                               // high priority error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_INT_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                                   // Main ISR entry error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_MAIN_VECT_CERR                      0x2U          //
                                                                                                   // Main Correctable vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_MAIN_VECT_UNCERR                    0x4U          //
                                                                                                   // Main Uncorrectable vector error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                                   // Main Interrupt return error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                                   // INT ISR entry error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_INT_VECT_CERR                       0x20U         //
                                                                                                   // INT Correctable vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_INT_VECT_UNCERR                     0x40U         //
                                                                                                   // INT Uncorrectable vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                                   // INT INTerrupt return error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                                   // RTINT ISR entry error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_RTINT_VECT_CERR                     0x200U        //
                                                                                                   // RTINT Correctable vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_RTINT_VECT_UNCERR                   0x400U        //
                                                                                                   // RTINT Uncorrectable vector error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                                   // RTINT Interrupt return error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                                   // RTINT Context restore Correctable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                                   // RTINT Context restore Uncorrectable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_NMI_MAXISP_ERR                      0x8000U       //
                                                                                                   // NMI MAXISP error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                                   // NMI ISR entry error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_NMI_VECT_CERR                       0x20000U      //
                                                                                                   // NMI Correctable vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_NMI_VECT_UNCERR                     0x40000U      //
                                                                                                   // NMI Uncorrectable vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                                   // NMI Interrupt return error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                                   // NMI Context restore Correctable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                                   // NMI Context restore Uncorrectable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_VECT_CERR                           0x400000U     //
                                                                                                   // Vector Correctable error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_VECT_UNCERR                         0x800000U     //
                                                                                                   // Vector Uncorrectable error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_WARNISP                             0x1000000U    //
                                                                                                   // warnisp force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_MAXISP                              0x2000000U    //
                                                                                                   // maxisp force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                                   // PIPE security violation force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_REG_PARITY_ERR                      0x8000000U    //
                                                                                                   // PIPE Reg parity error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                                   // PIPE Register parity diag error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                                   // PIPE Lock key error force
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                                   // Force low priority software error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_FRC_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                                   // force high priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2_INT_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                                   // Main ISR entry error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_MAIN_VECT_CERR                      0x2U          //
                                                                                                   // Main Correctable vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_MAIN_VECT_UNCERR                    0x4U          //
                                                                                                   // Main Uncorrectable vector error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                                   // Main Interrupt return error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                                   // INT ISR entry error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_INT_VECT_CERR                       0x20U         //
                                                                                                   // INT Correctable vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_INT_VECT_UNCERR                     0x40U         //
                                                                                                   // INT Uncorrectable vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                                   // INT INTerrupt return error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                                   // RTINT ISR entry error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_RTINT_VECT_CERR                     0x200U        //
                                                                                                   // RTINT Correctable vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_RTINT_VECT_UNCERR                   0x400U        //
                                                                                                   // RTINT Uncorrectable vector error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                                   // RTINT Interrupt return error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                                   // RTINT Context restore Correctable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                                   // RTINT Context restore Uncorrectable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_NMI_MAXISP_ERR                      0x8000U       //
                                                                                                   // NMI MAXISP error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                                   // NMI ISR entry error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_NMI_VECT_CERR                       0x20000U      //
                                                                                                   // NMI Correctable vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_NMI_VECT_UNCERR                     0x40000U      //
                                                                                                   // NMI Uncorrectable vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                                   // NMI Interrupt return error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                                   // NMI Context restore Correctable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                                   // NMI Context restore Uncorrectable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_VECT_CERR                           0x400000U     //
                                                                                                   // Vector Correctable error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_VECT_UNCERR                         0x800000U     //
                                                                                                   // Vector Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_WARNISP                             0x1000000U    //
                                                                                                   // warnisp clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_MAXISP                              0x2000000U    //
                                                                                                   // maxisp clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                                   // PIPE security violation clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_REG_PARITY_ERR                      0x8000000U    //
                                                                                                   // PIPE Reg parity error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                                   // PIPE Register parity diag error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                                   // PIPE Lock key error clear
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                                   // clear low priority software error
#define ERROR_AGGREGATOR_CPU2_INT_ERROR_TYPE_CLR_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                                   // clear high priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_PR_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                // packet security violation.
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_SEC_ENTRY_VIO         0x2U          // Secure entry and
                                                                                // linear code crossing error.
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_MAX_PSP_ERR           0x8U          //  MAX PSP error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_ACC_TIMEOUT_ERR       0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_ACC_ACK_ERR           0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_UNCERR                0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CERR                  0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_WARN_PSP_ERR          0x100U        // Warn PSP error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                // brakepoint error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                // instruction error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                // timeout error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_LP_SOFTWARE_ERR       0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_HP_SOFTWARE_ERR       0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_PR_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                    // packet security violation force.
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_SEC_ENTRY_VIO         0x2U          // Secure entry
                                                                                    // and linear code crossing error
                                                                                    // force.
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_MAX_PSP_ERR           0x8U          // MAX PSP
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR       0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_ACC_ACK_ERR           0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_UNCERR                0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_CERR                  0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_WARN_PSP_ERR          0x100U        // Warn PSP
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                    // brakepoint error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                    // instruction error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_LP_SOFTWARE_ERR       0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_FRC_HP_SOFTWARE_ERR       0x80000000U   // Force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_PR_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_INSTR_SECURITY_VIO    0x1U          // Instruction
                                                                                    // packet security violation clear.
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_SEC_ENTRY_VIO         0x2U          // Secure entry
                                                                                    // and linear code crossing error
                                                                                    // clear.
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_SEC_EXIT_VIO          0x4U          // Secure exit
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_MAX_PSP_ERR           0x8U          // MAX PSP
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR       0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_ACC_ACK_ERR           0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_UNCERR                0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_CERR                  0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_WARN_PSP_ERR          0x100U        // Warn PSP
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_SW_BREAKPOINT_ERR     0x200U        // Software
                                                                                    // brakepoint error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_ILLEGAL_INSTRUCTION   0x400U        // Illegal
                                                                                    // instruction error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_INSTRUCTION_TIMEOUT   0x800U        // Instruction
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_LP_SOFTWARE_ERR       0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU3_PR_ERROR_TYPE_CLR_HP_SOFTWARE_ERR       0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DR1_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                                // violation
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CERR                 0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                // address error
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DR1_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                    // violation force
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_FRC_UNCERR               0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error force
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DR1_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                    // violation clear
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CLR_UNCERR               0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error clear
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU3_DR1_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DR2_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                                // violation
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CERR                 0x80U         // Correctable
                                                                                // error
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                // address error
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                                // error set by software
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                                // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DR2_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                    // violation force
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error force
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_FRC_UNCERR               0x40U         //
                                                                                    // Uncorrectable error force
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                    // error force
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error force
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DR2_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                    // violation clear
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                    // timeout error clear
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CLR_UNCERR               0x40U         //
                                                                                    // Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                    // error clear
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                    // address error clear
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                    // priority software error
#define ERROR_AGGREGATOR_CPU3_DR2_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                    // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DW_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_SECURITY_VIO         0x1U          // Security
                                                                               // violation
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_ACC_TIMEOUT_ERR      0x10U         // Access timeout
                                                                               // error
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_ACC_ACK_ERR          0x20U         // Access ACK error
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_UNCERR               0x40U         // Uncorrectable
                                                                               // error
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CERR                 0x80U         // Correctable error
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_UNALIGNED_ADDR_ERR   0x100U        // Unaligned address
                                                                               // error
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_LP_SOFTWARE_ERR      0x40000000U   // Low Priority
                                                                               // error set by software
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_HP_SOFTWARE_ERR      0x80000000U   // high priority
                                                                               // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DW_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_FRC_SECURITY_VIO         0x1U          // Security
                                                                                   // violation force
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                   // timeout error force
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_FRC_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_FRC_UNCERR               0x40U         // Uncorrectable
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_FRC_CERR                 0x80U         // Correctable
                                                                                   // error force
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_FRC_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                   // address error force
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_FRC_LP_SOFTWARE_ERR      0x40000000U   // Force low
                                                                                   // priority software error
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_FRC_HP_SOFTWARE_ERR      0x80000000U   // force high
                                                                                   // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_DW_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CLR_SECURITY_VIO         0x1U          // Security
                                                                                   // violation clear
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR      0x10U         // Access
                                                                                   // timeout error clear
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CLR_ACC_ACK_ERR          0x20U         // Access ACK
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CLR_UNCERR               0x40U         // Uncorrectable
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CLR_CERR                 0x80U         // Correctable
                                                                                   // error clear
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CLR_UNALIGNED_ADDR_ERR   0x100U        // Unaligned
                                                                                   // address error clear
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CLR_LP_SOFTWARE_ERR      0x40000000U   // clear low
                                                                                   // priority software error
#define ERROR_AGGREGATOR_CPU3_DW_ERROR_TYPE_CLR_HP_SOFTWARE_ERR      0x80000000U   // clear high
                                                                                   // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_INT_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                               // Main ISR entry error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_MAIN_VECT_CERR                      0x2U          //
                                                                                               // Main Correctable vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_MAIN_VECT_UNCERR                    0x4U          //
                                                                                               // Main Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                               // Main Interrupt return error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                               // INT ISR entry error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_INT_VECT_CERR                       0x20U         //
                                                                                               // INT Correctable vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_INT_VECT_UNCERR                     0x40U         //
                                                                                               // INT Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                               // INT INTerrupt return error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                               // RTINT ISR entry error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_RTINT_VECT_CERR                     0x200U        //
                                                                                               // RTINT Correctable vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_RTINT_VECT_UNCERR                   0x400U        //
                                                                                               // RTINT Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                               // RTINT Interrupt return error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                               // RTINT Context restore Correctable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                               // RTINT Context restore Uncorrectable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_NMI_MAXISP_ERR                      0x8000U       //
                                                                                               // NMI MAXISP error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                               // NMI ISR entry error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_NMI_VECT_CERR                       0x20000U      //
                                                                                               // NMI Correctable vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_NMI_VECT_UNCERR                     0x40000U      //
                                                                                               // NMI Uncorrectable vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                               // NMI Interrupt return error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                               // NMI Context restore Correctable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                               // NMI Context restore Uncorrectable
                                                                                               // vector error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_VECT_CERR                           0x400000U     //
                                                                                               // Vector Correctable error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_VECT_UNCERR                         0x800000U     //
                                                                                               // Vector Uncorrectable error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_WARNISP                             0x1000000U    //
                                                                                               // warnisp
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_MAXISP                              0x2000000U    //
                                                                                               // maxisp
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                               // PIPE security violation
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_REG_PARITY_ERR                      0x8000000U    //
                                                                                               // PIPE Reg parity error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                               // PIPE Register parity diag error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                               // PIPE Lock/key error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                               // Low Priority error set by software
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                               // high priority error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_INT_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                                   // Main ISR entry error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_MAIN_VECT_CERR                      0x2U          //
                                                                                                   // Main Correctable vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_MAIN_VECT_UNCERR                    0x4U          //
                                                                                                   // Main Uncorrectable vector error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                                   // Main Interrupt return error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                                   // INT ISR entry error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_INT_VECT_CERR                       0x20U         //
                                                                                                   // INT Correctable vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_INT_VECT_UNCERR                     0x40U         //
                                                                                                   // INT Uncorrectable vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                                   // INT INTerrupt return error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                                   // RTINT ISR entry error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_RTINT_VECT_CERR                     0x200U        //
                                                                                                   // RTINT Correctable vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_RTINT_VECT_UNCERR                   0x400U        //
                                                                                                   // RTINT Uncorrectable vector error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                                   // RTINT Interrupt return error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                                   // RTINT Context restore Correctable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                                   // RTINT Context restore Uncorrectable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_NMI_MAXISP_ERR                      0x8000U       //
                                                                                                   // NMI MAXISP error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                                   // NMI ISR entry error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_NMI_VECT_CERR                       0x20000U      //
                                                                                                   // NMI Correctable vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_NMI_VECT_UNCERR                     0x40000U      //
                                                                                                   // NMI Uncorrectable vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                                   // NMI Interrupt return error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                                   // NMI Context restore Correctable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                                   // NMI Context restore Uncorrectable
                                                                                                   // vector error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_VECT_CERR                           0x400000U     //
                                                                                                   // Vector Correctable error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_VECT_UNCERR                         0x800000U     //
                                                                                                   // Vector Uncorrectable error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_WARNISP                             0x1000000U    //
                                                                                                   // warnisp force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_MAXISP                              0x2000000U    //
                                                                                                   // maxisp force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                                   // PIPE security violation force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_REG_PARITY_ERR                      0x8000000U    //
                                                                                                   // PIPE Reg parity error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                                   // PIPE Register parity diag error
                                                                                                   // force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                                   // PIPE Lock key error force
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                                   // Force low priority software error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_FRC_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                                   // force high priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3_INT_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_MAIN_ISR_ENTRY_ERR                  0x1U          //
                                                                                                   // Main ISR entry error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_MAIN_VECT_CERR                      0x2U          //
                                                                                                   // Main Correctable vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_MAIN_VECT_UNCERR                    0x4U          //
                                                                                                   // Main Uncorrectable vector error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_MAIN_INTERRUPT_RETURN_ERR           0x8U          //
                                                                                                   // Main Interrupt return error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_INT_ISR_ENTRY_ERR                   0x10U         //
                                                                                                   // INT ISR entry error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_INT_VECT_CERR                       0x20U         //
                                                                                                   // INT Correctable vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_INT_VECT_UNCERR                     0x40U         //
                                                                                                   // INT Uncorrectable vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_INT_INTERRUPT_RETURN_ERR            0x80U         //
                                                                                                   // INT INTerrupt return error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_RTINT_ISR_ENTRY_ERR                 0x100U        //
                                                                                                   // RTINT ISR entry error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_RTINT_VECT_CERR                     0x200U        //
                                                                                                   // RTINT Correctable vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_RTINT_VECT_UNCERR                   0x400U        //
                                                                                                   // RTINT Uncorrectable vector error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_RTINT_INTERRUPT_RETURN_ERR          0x800U        //
                                                                                                   // RTINT Interrupt return error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_RTINT_CONTEXT_RESTORE_VECT_CERR     0x1000U       //
                                                                                                   // RTINT Context restore Correctable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_RTINT_CONTEXT_RESTORE_VECT_UNCERR   0x2000U       //
                                                                                                   // RTINT Context restore Uncorrectable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_NMI_MAXISP_ERR                      0x8000U       //
                                                                                                   // NMI MAXISP error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_NMI_ISR_ENTRY_ERR                   0x10000U      //
                                                                                                   // NMI ISR entry error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_NMI_VECT_CERR                       0x20000U      //
                                                                                                   // NMI Correctable vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_NMI_VECT_UNCERR                     0x40000U      //
                                                                                                   // NMI Uncorrectable vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_NMI_INTERRUPT_RETURN_ERR            0x80000U      //
                                                                                                   // NMI Interrupt return error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_NMI_CONTEXT_RESTORE_VECT_CERR       0x100000U     //
                                                                                                   // NMI Context restore Correctable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_NMI_CONTEXT_RESTORE_VECT_UNCERR     0x200000U     //
                                                                                                   // NMI Context restore Uncorrectable
                                                                                                   // vector error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_VECT_CERR                           0x400000U     //
                                                                                                   // Vector Correctable error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_VECT_UNCERR                         0x800000U     //
                                                                                                   // Vector Uncorrectable error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_WARNISP                             0x1000000U    //
                                                                                                   // warnisp clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_MAXISP                              0x2000000U    //
                                                                                                   // maxisp clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_PIPE_SECURITY_VIO                   0x4000000U    //
                                                                                                   // PIPE security violation clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_REG_PARITY_ERR                      0x8000000U    //
                                                                                                   // PIPE Reg parity error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_REG_PARITY_DIAG_ERR                 0x10000000U   //
                                                                                                   // PIPE Register parity diag error
                                                                                                   // clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_PIPE_LOCK_KEY_ERR                   0x20000000U   //
                                                                                                   // PIPE Lock key error clear
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_LP_SOFTWARE_ERR                     0x40000000U   //
                                                                                                   // clear low priority software error
#define ERROR_AGGREGATOR_CPU3_INT_ERROR_TYPE_CLR_HP_SOFTWARE_ERR                     0x80000000U   //
                                                                                                   // clear high priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA1_DR_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_SECURITY_VIO      0x1U          // Security violation
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                              // error
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_ACC_ACK_ERR       0x20U         // Access ACK error
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_UNCERR            0x40U         // Uncorrectable
                                                                              // error
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_CERR              0x80U         // Correctable error
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_LP_SOFTWARE_ERR   0x40000000U   // Low priority
                                                                              // software error
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_HP_SOFTWARE_ERR   0x80000000U   // high priority
                                                                              // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA1_DR_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_FRC_SECURITY_VIO      0x1U          // Security
                                                                                  // violation force
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_FRC_ACC_ACK_ERR       0x20U         // Access ACK
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_FRC_UNCERR            0x40U         // Uncorrectable
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_FRC_CERR              0x80U         // Correctable
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_FRC_LP_SOFTWARE_ERR   0x40000000U   // Force low
                                                                                  // priority software error
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_FRC_HP_SOFTWARE_ERR   0x80000000U   // force high
                                                                                  // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA1_DR_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_CLR_SECURITY_VIO      0x1U          // Security
                                                                                  // violation clear
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_CLR_ACC_ACK_ERR       0x20U         // Access ACK
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_CLR_UNCERR            0x40U         // Uncorrectable
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_CLR_CERR              0x80U         // Correctable
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_CLR_LP_SOFTWARE_ERR   0x40000000U   // clear low
                                                                                  // priority software error
#define ERROR_AGGREGATOR_RTDMA1_DR_ERROR_TYPE_CLR_HP_SOFTWARE_ERR   0x80000000U   // clear high
                                                                                  // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA1_DW_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_SECURITY_VIO      0x1U          // Security violation
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                              // error
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_ACC_ACK_ERR       0x20U         // Access ACK error
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_UNCERR            0x40U         // Uncorrectable
                                                                              // error
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_CERR              0x80U         // Correctable error
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_LP_SOFTWARE_ERR   0x40000000U   // Low Priority error
                                                                              // set by software
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_HP_SOFTWARE_ERR   0x80000000U   // high priority
                                                                              // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA1_DW_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_FRC_SECURITY_VIO      0x1U          // Security
                                                                                  // violation force
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_FRC_ACC_ACK_ERR       0x20U         // Access ACK
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_FRC_UNCERR            0x40U         // Uncorrectable
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_FRC_CERR              0x80U         // Correctable
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_FRC_LP_SOFTWARE_ERR   0x40000000U   // Force low
                                                                                  // priority software error
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_FRC_HP_SOFTWARE_ERR   0x80000000U   // force high
                                                                                  // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA1_DW_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_CLR_SECURITY_VIO      0x1U          // Security
                                                                                  // violation clear
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_CLR_ACC_ACK_ERR       0x20U         // Access ACK
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_CLR_UNCERR            0x40U         // Uncorrectable
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_CLR_CERR              0x80U         // Correctable
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_CLR_LP_SOFTWARE_ERR   0x40000000U   // clear low
                                                                                  // priority software error
#define ERROR_AGGREGATOR_RTDMA1_DW_ERROR_TYPE_CLR_HP_SOFTWARE_ERR   0x80000000U   // clear high
                                                                                  // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA2_DR_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_SECURITY_VIO      0x1U          // Security violation
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                              // error
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_ACC_ACK_ERR       0x20U         // Access ACK error
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_UNCERR            0x40U         // Uncorrectable
                                                                              // error
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_CERR              0x80U         // Correctable error
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_LP_SOFTWARE_ERR   0x40000000U   // Low priority
                                                                              // software error
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_HP_SOFTWARE_ERR   0x80000000U   // high priority
                                                                              // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA2_DR_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_FRC_SECURITY_VIO      0x1U          // Security
                                                                                  // violation force
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_FRC_ACC_ACK_ERR       0x20U         // Access ACK
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_FRC_UNCERR            0x40U         // Uncorrectable
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_FRC_CERR              0x80U         // Correctable
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_FRC_LP_SOFTWARE_ERR   0x40000000U   // Force low
                                                                                  // priority software error
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_FRC_HP_SOFTWARE_ERR   0x80000000U   // force high
                                                                                  // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA2_DR_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_CLR_SECURITY_VIO      0x1U          // Security
                                                                                  // violation clear
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_CLR_ACC_ACK_ERR       0x20U         // Access ACK
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_CLR_UNCERR            0x40U         // Uncorrectable
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_CLR_CERR              0x80U         // Correctable
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_CLR_LP_SOFTWARE_ERR   0x40000000U   // clear low
                                                                                  // priority software error
#define ERROR_AGGREGATOR_RTDMA2_DR_ERROR_TYPE_CLR_HP_SOFTWARE_ERR   0x80000000U   // clear high
                                                                                  // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA2_DW_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_SECURITY_VIO      0x1U          // Security violation
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                              // error
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_ACC_ACK_ERR       0x20U         // Access ACK error
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_UNCERR            0x40U         // Uncorrectable
                                                                              // error
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_CERR              0x80U         // Correctable error
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_LP_SOFTWARE_ERR   0x40000000U   // Low Priority error
                                                                              // set by software
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_HP_SOFTWARE_ERR   0x80000000U   // high priority
                                                                              // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA2_DW_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_FRC_SECURITY_VIO      0x1U          // Security
                                                                                  // violation force
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_FRC_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_FRC_ACC_ACK_ERR       0x20U         // Access ACK
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_FRC_UNCERR            0x40U         // Uncorrectable
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_FRC_CERR              0x80U         // Correctable
                                                                                  // error force
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_FRC_LP_SOFTWARE_ERR   0x40000000U   // Force low
                                                                                  // priority software error
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_FRC_HP_SOFTWARE_ERR   0x80000000U   // force high
                                                                                  // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA2_DW_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_CLR_SECURITY_VIO      0x1U          // Security
                                                                                  // violation clear
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_CLR_ACC_TIMEOUT_ERR   0x10U         // Access timeout
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_CLR_ACC_ACK_ERR       0x20U         // Access ACK
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_CLR_UNCERR            0x40U         // Uncorrectable
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_CLR_CERR              0x80U         // Correctable
                                                                                  // error clear
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_CLR_LP_SOFTWARE_ERR   0x40000000U   // clear low
                                                                                  // priority software error
#define ERROR_AGGREGATOR_RTDMA2_DW_ERROR_TYPE_CLR_HP_SOFTWARE_ERR   0x80000000U   // clear high
                                                                                  // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSU_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CPU1_SSU_MMR_ACCESS_ERROR   0x2U          //
                                                                                  // CPU1_SSU_MMR_ACCESS_ERROR
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CPU2_SSU_MMR_ACCESS_ERROR   0x4U          //
                                                                                  // CPU2_SSU_MMR_ACCESS_ERROR
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CPU3_SSU_MMR_ACCESS_ERROR   0x8U          //
                                                                                  // CPU3_SSU_MMR_ACCESS_ERROR
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_MODE_INVALID                0x80U         // BANKMAP,
                                                                                  // SECVALID, BANKMODE, SSUMODE invalid
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FLC1_ERROR_STS              0x100U        // FLC1_ERROR_STS
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FLC1_ERROR_TYPE_S           9U
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FLC1_ERROR_TYPE_M           0xE00U        //
                                                                                  // FLC1_ERROR_TYPE
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FLC1_MMR_ACCESS_ERROR       0x1000U       //
                                                                                  // FLC1_MMR_ACCESS_ERROR
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FLC2_ERROR_STS              0x2000U       // FLC2_
                                                                                  // ERROR_STS
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FLC2_ERROR_TYPE_S           14U
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FLC2_ERROR_TYPE_M           0x1C000U      //
                                                                                  // FLC2_ERROR_TYPE
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FLC2_MMR_ACCESS_ERROR       0x20000U      //
                                                                                  // FLC2_MMR_ACCESS_ERROR
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_HP_SOFTWARE_ERR             0x80000000U   // high priority
                                                                                  // error set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSU_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_CPU1_SSU_MMR_ACCESS_ERROR   0x2U          //
                                                                                      // CPU1_SSU_MMR_ACCESS_ERROR force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_CPU2_SSU_MMR_ACCESS_ERROR   0x4U          //
                                                                                      // CPU2_SSU_MMR_ACCESS_ERROR force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_CPU3_SSU_MMR_ACCESS_ERROR   0x8U          //
                                                                                      // CPU3_SSU_MMR_ACCESS_ERROR force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_MODE_INVALID                0x80U         // BANKMAP,
                                                                                      // SECVALID, BANKMODE, SSUMODE invalid 
                                                                                      // force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_FLC1_ERROR_STS              0x100U        //
                                                                                      // FLC1_ERROR_STS  force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_FLC1_ERROR_TYPE_S           9U
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_FLC1_ERROR_TYPE_M           0xE00U        //
                                                                                      // FLC1_ERROR_TYPE force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_FLC1_MMR_ACCESS_ERROR       0x1000U       //
                                                                                      // FLC1_MMR_ACCESS_ERROR force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_FLC2_ERROR_STS              0x2000U       // FLC2_
                                                                                      // ERROR_STS force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_FLC2_ERROR_TYPE_S           14U
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_FLC2_ERROR_TYPE_M           0x1C000U      //
                                                                                      // FLC2_ERROR_TYPE force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_FLC2_MMR_ACCESS_ERROR       0x20000U      //
                                                                                      // FLC2_MMR_ACCESS_ERROR force
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_FRC_HP_SOFTWARE_ERR             0x80000000U   // force high
                                                                                      // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSU_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_CPU1_SSU_MMR_ACCESS_ERROR   0x2U          //
                                                                                      // CPU1_SSU_MMR_ACCESS_ERROR Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_CPU2_SSU_MMR_ACCESS_ERROR   0x4U          //
                                                                                      // CPU2_SSU_MMR_ACCESS_ERROR Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_CPU3_SSU_MMR_ACCESS_ERROR   0x8U          //
                                                                                      // CPU3_SSU_MMR_ACCESS_ERROR Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_MODE_INVALID                0x80U         // BANKMAP,
                                                                                      // SECVALID, BANKMODE, SSUMODE invalid 
                                                                                      // Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_FLC1_ERROR_STS              0x100U        //
                                                                                      // FLC1_ERROR_STS  Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_FLC1_ERROR_TYPE_S           9U
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_FLC1_ERROR_TYPE_M           0xE00U        //
                                                                                      // FLC1_ERROR_TYPE Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_FLC1_MMR_ACCESS_ERROR       0x1000U       //
                                                                                      // FLC1_MMR_ACCESS_ERROR Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_FLC2_ERROR_STS              0x2000U       // FLC2_
                                                                                      // ERROR_STS Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_FLC2_ERROR_TYPE_S           14U
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_FLC2_ERROR_TYPE_M           0x1C000U      //
                                                                                      // FLC2_ERROR_TYPE Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_FLC2_MMR_ACCESS_ERROR       0x20000U      //
                                                                                      // FLC2_MMR_ACCESS_ERROR Clear
#define ERROR_AGGREGATOR_SSU_ERROR_TYPE_CLR_HP_SOFTWARE_ERR             0x80000000U   // clear high
                                                                                      // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the ETHERCAT_ERROR_TYPE register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_ETHERCAT_ERROR_TYPE_UNCERR            0x40U         // Uncorrectable error
#define ERROR_AGGREGATOR_ETHERCAT_ERROR_TYPE_HP_SOFTWARE_ERR   0x80000000U   // high priority error
                                                                             // set by software

//*************************************************************************************************
//
// The following are defines for the bit fields in the ETHERCAT_ERROR_TYPE_FRC register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_ETHERCAT_ERROR_TYPE_FRC_UNCERR            0x40U         // Uncorrectable
                                                                                 // error force
#define ERROR_AGGREGATOR_ETHERCAT_ERROR_TYPE_FRC_HP_SOFTWARE_ERR   0x80000000U   // force high
                                                                                 // priority software error

//*************************************************************************************************
//
// The following are defines for the bit fields in the ETHERCAT_ERROR_TYPE_CLR register
//
//*************************************************************************************************
#define ERROR_AGGREGATOR_ETHERCAT_ERROR_TYPE_CLR_UNCERR            0x40U         // Uncorrectable
                                                                                 // error clear
#define ERROR_AGGREGATOR_ETHERCAT_ERROR_TYPE_CLR_HP_SOFTWARE_ERR   0x80000000U   // clear high
                                                                                 // priority software error



#endif
