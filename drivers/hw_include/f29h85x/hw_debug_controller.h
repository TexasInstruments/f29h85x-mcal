//###########################################################################
//
// FILE:    hw_debug_controller.h
//
// TITLE:   Definitions for the DEBUG_CONTROLLER registers.
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

#ifndef HW_DEBUG_CONTROLLER_H
#define HW_DEBUG_CONTROLLER_H

//*************************************************************************************************
//
// The following are defines for the DEBUG_CONTROLLER register offsets
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_O_DBG_CAP           0x0U    // Debug Capability
#define DEBUG_CONTROLLER_O_DBG_PID           0x4U    // Debug Part ID
#define DEBUG_CONTROLLER_O_DBG_CONNECT       0x8U    // Debug Connect
#define DEBUG_CONTROLLER_O_DBG_CNTL0         0xCU    // Debug Execution Control 0
#define DEBUG_CONTROLLER_O_DBG_CNTL1         0x10U   // Debug Execution Control 1
#define DEBUG_CONTROLLER_O_DBG_STAT          0x14U   // Debug Status
#define DEBUG_CONTROLLER_O_DBG_MEM_CNTL      0x18U   // Debug  Access control
#define DEBUG_CONTROLLER_O_DBG_MEM_ADDR0     0x40U   // Debyg Acess Address
#define DEBUG_CONTROLLER_O_DBG_MEM_DATA0     0x48U   // Debug Access Data 0
#define DEBUG_CONTROLLER_O_DBG_MEM_DATA1     0x4CU   // Debug Access Data 1
#define DEBUG_CONTROLLER_O_DBG_VIS_READ_P0   0x50U   // Debug Visibility Read Port 0
#define DEBUG_CONTROLLER_O_DBG_VIS_READ_P1   0x54U   // Debug Visibility Read Port 1
#define DEBUG_CONTROLLER_O_DBG_VIS_CLR_P1    0x58U   // Debug Visibility Port 1 Clear


//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_CAP register
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_DBG_CAP_REV_MIN_S       0U
#define DEBUG_CONTROLLER_DBG_CAP_REV_MIN_M       0xFU         // Minor Revision
#define DEBUG_CONTROLLER_DBG_CAP_REV_MAX_S       4U
#define DEBUG_CONTROLLER_DBG_CAP_REV_MAX_M       0xF0U        // Major Revision
#define DEBUG_CONTROLLER_DBG_CAP_TRIG_CHNS_S     20U
#define DEBUG_CONTROLLER_DBG_CAP_TRIG_CHNS_M     0x300000U    // Number of Trigger Channels
#define DEBUG_CONTROLLER_DBG_CAP_TRIG_INPUT      0x400000U    // Number of Input Triggers
#define DEBUG_CONTROLLER_DBG_CAP_TRIG_OUTPUT     0x800000U    // Number of Output Triggers
#define DEBUG_CONTROLLER_DBG_CAP_SYS_EXE_REQ     0x1000000U   // IDLE control
#define DEBUG_CONTROLLER_DBG_CAP_DBG_RESET_SUP   0x2000000U   // CPU Reset support

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_PID register
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_DBG_PID_MINOR_S           0U
#define DEBUG_CONTROLLER_DBG_PID_MINOR_M           0x3FU         // Minor Revision
#define DEBUG_CONTROLLER_DBG_PID_CUSTOM_S          6U
#define DEBUG_CONTROLLER_DBG_PID_CUSTOM_M          0xC0U         // Custom Field
#define DEBUG_CONTROLLER_DBG_PID_MAJOR_S           8U
#define DEBUG_CONTROLLER_DBG_PID_MAJOR_M           0x700U        // Major Revision
#define DEBUG_CONTROLLER_DBG_PID_RTL_S             11U
#define DEBUG_CONTROLLER_DBG_PID_RTL_M             0xF800U       // RTL Revision
#define DEBUG_CONTROLLER_DBG_PID_FUNC_S            16U
#define DEBUG_CONTROLLER_DBG_PID_FUNC_M            0xFFF0000U    // Functional Group
#define DEBUG_CONTROLLER_DBG_PID_BUSINESS_UNIT_S   28U
#define DEBUG_CONTROLLER_DBG_PID_BUSINESS_UNIT_M   0x30000000U   // Business Unit
#define DEBUG_CONTROLLER_DBG_PID_SCHEME_S          30U
#define DEBUG_CONTROLLER_DBG_PID_SCHEME_M          0xC0000000U   // Scheme Version

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_CONNECT register
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_DBG_CONNECT_CONNECTED_S         0U
#define DEBUG_CONTROLLER_DBG_CONNECT_CONNECTED_M         0x3U          // Debug Connected
#define DEBUG_CONTROLLER_DBG_CONNECT_CONNECT_PATTERN_S   16U
#define DEBUG_CONTROLLER_DBG_CONNECT_CONNECT_PATTERN_M   0xFFFF0000U   // Write Key pattern

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_CNTL0 register
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_CMD_S            0U
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_CMD_M            0x7U       // Execution Command
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_CMD_LD           0x8U       // Load Enable for Execution
                                                                   // Command
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_MODE_S           4U
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_MODE_M           0x30U      // Execution Mode
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_IGNORE_HPI       0x40U      // Ignore HPI
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_IGNORE_DBGM      0x80U      // Ignore DBGM
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_SWBP_EN          0x100U     // Enable Softaware Breakpoints
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_HWBP_EN          0x200U     // Enable Hardware Breakpoints
#define DEBUG_CONTROLLER_DBG_CNTL0_EXT_DBG_EN           0x400U     // Enable External Triggers
#define DEBUG_CONTROLLER_DBG_CNTL0_EXT_HALT_EN          0x800U     // Enable External Trigger 
                                                                   // HALTs
#define DEBUG_CONTROLLER_DBG_CNTL0_EXT_RUN_EN           0x1000U    // Enable Synchronous RUN
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_D_INT            0x2000U    // Debug Interrupts
#define DEBUG_CONTROLLER_DBG_CNTL0_EXE_D_NMI            0x4000U    // Debug NMI
#define DEBUG_CONTROLLER_DBG_CNTL0_GUI_PC_MOD_RESTART   0x8000U    // Debugger Restart PC
                                                                   // modification
#define DEBUG_CONTROLLER_DBG_CNTL0_DBG_IDLE_WAKEUP      0x10000U   // IDLE wakeup request

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_CNTL1 register
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_DBG_CNTL1_FORCE_CPU_RESET       0x1U    // Force CPU Reset
#define DEBUG_CONTROLLER_DBG_CNTL1_CPU_RST_LD            0x2U    // Load Enable for FORCE_CPU_RESET
#define DEBUG_CONTROLLER_DBG_CNTL1_FORCE_READY           0x4U    // Force CPU pipeline ready
#define DEBUG_CONTROLLER_DBG_CNTL1_FORCE_READY_LD        0x8U    // Load Enable for FORCE_READY
#define DEBUG_CONTROLLER_DBG_CNTL1_CPU_BLOCK_PIN_RESET   0x10U   // Block CPU Pin Reset
#define DEBUG_CONTROLLER_DBG_CNTL1_CPU_BLOCK_RST_LD      0x20U   // Load enable for
                                                                 // CPU_BLOCK_PIN_RESET

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_STAT register
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_DBG_STAT_EXE_STAT_S           0U
#define DEBUG_CONTROLLER_DBG_STAT_EXE_STAT_M           0x3U         // Execution Status
#define DEBUG_CONTROLLER_DBG_STAT_RESTART              0x4U         // Execution Resumed Status bit
#define DEBUG_CONTROLLER_DBG_STAT_HALT_IN_E7           0x40U        // HALT condition seen in E7
                                                                    // pipeline phase
#define DEBUG_CONTROLLER_DBG_STAT_HALT_SWBP            0x100U       // HALTed due to Software
                                                                    // breakpoint
#define DEBUG_CONTROLLER_DBG_STAT_HALT_HWBP            0x200U       // HALTed due to Hardware
                                                                    // breakpoint
#define DEBUG_CONTROLLER_DBG_STAT_HALT_CPU_RESET       0x400U       // Reserved
#define DEBUG_CONTROLLER_DBG_STAT_HALT_STEP            0x800U       // HALTed due to Single Step
                                                                    // operation
#define DEBUG_CONTROLLER_DBG_STAT_HALT_USER            0x1000U      // HALTed due to user request
#define DEBUG_CONTROLLER_DBG_STAT_HALT_EXT_HALT        0x2000U      // HALTed due to external
                                                                    // trigger
#define DEBUG_CONTROLLER_DBG_STAT_HALT_WP              0x4000U      // HALTed due to a Watchpoint
#define DEBUG_CONTROLLER_DBG_STAT_HALT_IN_IDS          0x8000U      // Reserved
#define DEBUG_CONTROLLER_DBG_STAT_STAT_PRIV_DBGM       0x10000U     // DBGM status
#define DEBUG_CONTROLLER_DBG_STAT_STAT_PRIV_HPI        0x20000U     // HPI status
#define DEBUG_CONTROLLER_DBG_STAT_STAT_EXT_RUN_SEEN    0x40000U     // External RUN request seen
#define DEBUG_CONTROLLER_DBG_STAT_STAT_EXT_HALT_SEEN   0x80000U     // External HALT request seen
#define DEBUG_CONTROLLER_DBG_STAT_STAT_PIPE_READY      0x100000U    // CPU Pipeline advancement
                                                                    // status
#define DEBUG_CONTROLLER_DBG_STAT_STAT_CLK_SEEN        0x200000U    // CPU has seen a Clock
#define DEBUG_CONTROLLER_DBG_STAT_RESET_OCC            0x400000U    // CPU has seen a Reset
#define DEBUG_CONTROLLER_DBG_STAT_RESET_ACT            0x800000U    // CPU reset active
#define DEBUG_CONTROLLER_DBG_STAT_FAULT_SEEN           0x1000000U   // CPU entered a FAULT state
#define DEBUG_CONTROLLER_DBG_STAT_IDLE_IN_R1           0x2000000U   // IDLE instruction in R1
                                                                    // pipeline phase
#define DEBUG_CONTROLLER_DBG_STAT_IDLE_IN_E7           0x4000000U   // IDLE instruction in E7
                                                                    // pipeline phase

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_MEM_CNTL register
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_RW                   0x1U         // Read Write Select
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_ADDR_INC             0x2U         // Address Increment
                                                                            // mode
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_IGNORE_DBGM          0x4U         // Ignore DBGM for
                                                                            // memory access
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_IGNORE_HPI           0x8U         // Ignore HPI for
                                                                            // memory access
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_ACC_TYPE_S               4U
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_ACC_TYPE_M               0x70U        // Debug Access Type
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_ACC_SIZE_S           8U
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_ACC_SIZE_M           0x700U       // Debug access size
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_DBG_ACCESS_EN            0x800U       // Enable Debug Access
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_LOAD_MEMACC_FIELDS       0x40000U     // Load enable Debug
                                                                            // Access fields
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_CLR_MEM_STATUS           0x80000U     // Clear Debug access
                                                                            // fault status bits
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_ACC_STATUS_S         20U
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_ACC_STATUS_M         0xF00000U    // Debug access status
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_ACC_BUS_ERROR        0x1000000U   // Transaction fault on
                                                                            // access
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_ACC_SEC_ERROR        0x2000000U   // Security violation
                                                                            // on access
#define DEBUG_CONTROLLER_DBG_MEM_CNTL_MEM_ACC_SEQUENCE_ERROR   0x4000000U   // Access Sequence
                                                                            // violation during bulk access

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG_VIS_READ_P0 register
//
//*************************************************************************************************
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_FSM_S                0U
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_FSM_M                0x3FU         // D2 FSM states
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_DELAY_DISC_REQ          0x40U         // Delay
                                                                               // discontinuity request
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_EXE_FAULT               0x80U         // Fault from exe
                                                                               // unit
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_FETCH_FSM_S             8U
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_FETCH_FSM_M             0x700U        // Fetch FSM states
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_ZONE_S               11U
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_ZONE_M               0x1800U       // D2 Zone ID
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_STACK_S              13U
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_STACK_M              0xE000U       // D2 Stack ID
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_LINK_S               16U
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_LINK_M               0xF0000U      // D2 Link ID
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_D2_READY                0x100000U     // D2 ready
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_R1_READY                0x200000U     // R1 ready
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_MEMRD1_MPROT_BUFF_ACC   0x400000U     // Memread1 memory
                                                                               // protection buffer access
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_MEMRD2_MPROT_BUFF_ACC   0x800000U     // Memread2 memory
                                                                               // protection buffer access
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_VIS_PORT0_S             24U
#define DEBUG_CONTROLLER_DBG_VIS_READ_P0_VIS_PORT0_M             0xFF000000U   // Debug Visibility
                                                                               // Port0



#endif
