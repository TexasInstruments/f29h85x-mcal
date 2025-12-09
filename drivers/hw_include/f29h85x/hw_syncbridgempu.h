//###########################################################################
//
// FILE:    hw_syncbridgempu.h
//
// TITLE:   Definitions for the SYNCBRIDGEMPU registers.
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

#ifndef HW_SYNCBRIDGEMPU_H
#define HW_SYNCBRIDGEMPU_H

//*************************************************************************************************
//
// The following are defines for the SYNCBRIDGEMPU register offsets
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_O_MPUR1_START     0x0U     // MPU Region 1 Start Address
#define SYNCBRIDGEMPU_O_MPUR1_END       0x4U     // MPU Region 1 End Address
#define SYNCBRIDGEMPU_O_MPUR1_LOCK      0x8U     // MPU 1 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR1_COMMIT    0xCU     // MPU 1 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR1_ACCESS    0x10U    // MPU Region 1 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR2_START     0x20U    // MPU Region 2 Start Address
#define SYNCBRIDGEMPU_O_MPUR2_END       0x24U    // MPU Region 2 End Address
#define SYNCBRIDGEMPU_O_MPUR2_LOCK      0x28U    // MPU 2 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR2_COMMIT    0x2CU    // MPU 2 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR2_ACCESS    0x30U    // MPU Region 2 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR3_START     0x40U    // MPU Region 3 Start Address
#define SYNCBRIDGEMPU_O_MPUR3_END       0x44U    // MPU Region 3 End Address
#define SYNCBRIDGEMPU_O_MPUR3_LOCK      0x48U    // MPU 3 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR3_COMMIT    0x4CU    // MPU 3 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR3_ACCESS    0x50U    // MPU Region 3 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR4_START     0x60U    // MPU Region 4 Start Address
#define SYNCBRIDGEMPU_O_MPUR4_END       0x64U    // MPU Region 4 End Address
#define SYNCBRIDGEMPU_O_MPUR4_LOCK      0x68U    // MPU 4 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR4_COMMIT    0x6CU    // MPU 4 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR4_ACCESS    0x70U    // MPU Region 4 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR5_START     0x80U    // MPU Region 5 Start Address
#define SYNCBRIDGEMPU_O_MPUR5_END       0x84U    // MPU Region 5 End Address
#define SYNCBRIDGEMPU_O_MPUR5_LOCK      0x88U    // MPU 5 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR5_COMMIT    0x8CU    // MPU 5 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR5_ACCESS    0x90U    // MPU Region 5 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR6_START     0xA0U    // MPU Region 6 Start Address
#define SYNCBRIDGEMPU_O_MPUR6_END       0xA4U    // MPU Region 6 End Address
#define SYNCBRIDGEMPU_O_MPUR6_LOCK      0xA8U    // MPU 6 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR6_COMMIT    0xACU    // MPU 6 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR6_ACCESS    0xB0U    // MPU Region 6 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR7_START     0xC0U    // MPU Region 7 Start Address
#define SYNCBRIDGEMPU_O_MPUR7_END       0xC4U    // MPU Region 7 End Address
#define SYNCBRIDGEMPU_O_MPUR7_LOCK      0xC8U    // MPU 7 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR7_COMMIT    0xCCU    // MPU 7 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR7_ACCESS    0xD0U    // MPU Region 7 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR8_START     0xE0U    // MPU Region 8 Start Address
#define SYNCBRIDGEMPU_O_MPUR8_END       0xE4U    // MPU Region 8 End Address
#define SYNCBRIDGEMPU_O_MPUR8_LOCK      0xE8U    // MPU 8 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR8_COMMIT    0xECU    // MPU 8 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR8_ACCESS    0xF0U    // MPU Region 8 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR9_START     0x100U   // MPU Region 9 Start Address
#define SYNCBRIDGEMPU_O_MPUR9_END       0x104U   // MPU Region 9 End Address
#define SYNCBRIDGEMPU_O_MPUR9_LOCK      0x108U   // MPU 9 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR9_COMMIT    0x10CU   // MPU 9 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR9_ACCESS    0x110U   // MPU Region 9 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR10_START    0x120U   // MPU Region 10 Start Address
#define SYNCBRIDGEMPU_O_MPUR10_END      0x124U   // MPU Region 10 End Address
#define SYNCBRIDGEMPU_O_MPUR10_LOCK     0x128U   // MPU 10 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR10_COMMIT   0x12CU   // MPU 10 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR10_ACCESS   0x130U   // MPU Region 10 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR11_START    0x140U   // MPU Region 11 Start Address
#define SYNCBRIDGEMPU_O_MPUR11_END      0x144U   // MPU Region 11 End Address
#define SYNCBRIDGEMPU_O_MPUR11_LOCK     0x148U   // MPU 11 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR11_COMMIT   0x14CU   // MPU 11 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR11_ACCESS   0x150U   // MPU Region 11 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR12_START    0x160U   // MPU Region 12 Start Address
#define SYNCBRIDGEMPU_O_MPUR12_END      0x164U   // MPU Region 12 End Address
#define SYNCBRIDGEMPU_O_MPUR12_LOCK     0x168U   // MPU 12 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR12_COMMIT   0x16CU   // MPU 12 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR12_ACCESS   0x170U   // MPU Region 12 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR13_START    0x180U   // MPU Region 13 Start Address
#define SYNCBRIDGEMPU_O_MPUR13_END      0x184U   // MPU Region 13 End Address
#define SYNCBRIDGEMPU_O_MPUR13_LOCK     0x188U   // MPU 13 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR13_COMMIT   0x18CU   // MPU 13 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR13_ACCESS   0x190U   // MPU Region 13 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR14_START    0x1A0U   // MPU Region 14 Start Address
#define SYNCBRIDGEMPU_O_MPUR14_END      0x1A4U   // MPU Region 14 End Address
#define SYNCBRIDGEMPU_O_MPUR14_LOCK     0x1A8U   // MPU 14 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR14_COMMIT   0x1ACU   // MPU 14 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR14_ACCESS   0x1B0U   // MPU Region 14 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR15_START    0x1C0U   // MPU Region 15 Start Address
#define SYNCBRIDGEMPU_O_MPUR15_END      0x1C4U   // MPU Region 15 End Address
#define SYNCBRIDGEMPU_O_MPUR15_LOCK     0x1C8U   // MPU 15 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR15_COMMIT   0x1CCU   // MPU 15 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR15_ACCESS   0x1D0U   // MPU Region 15 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUR16_START    0x1E0U   // MPU Region 16 Start Address
#define SYNCBRIDGEMPU_O_MPUR16_END      0x1E4U   // MPU Region 16 End Address
#define SYNCBRIDGEMPU_O_MPUR16_LOCK     0x1E8U   // MPU 16 Temporary Lock
#define SYNCBRIDGEMPU_O_MPUR16_COMMIT   0x1ECU   // MPU 16 Permanent Commit
#define SYNCBRIDGEMPU_O_MPUR16_ACCESS   0x1F0U   // MPU Region 16 R/W Access Permissions
#define SYNCBRIDGEMPU_O_MPUCTRL         0x7FCU   // MPU Control Register
#define SYNCBRIDGEMPU_O_MPUCFG_LOCK     0x81CU   // Channel Configuration Temporary Lock
#define SYNCBRIDGEMPU_O_MPUCFG_COMMIT   0x820U   // Channel Configuration Permanent Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR1_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR1_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR1_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR1_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR1_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR1_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR1_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR1_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR1_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR1_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR1_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR1_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR1_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR1_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR1_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR1_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR1_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR2_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR2_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR2_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR2_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR2_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR2_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR2_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR2_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR2_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR2_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR2_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR2_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR2_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR2_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR2_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR2_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR2_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR3_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR3_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR3_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR3_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR3_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR3_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR3_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR3_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR3_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR3_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR3_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR3_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR3_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR3_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR3_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR3_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR3_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR4_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR4_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR4_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR4_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR4_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR4_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR4_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR4_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR4_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR4_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR4_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR4_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR4_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR4_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR4_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR4_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR4_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR5_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR5_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR5_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR5_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR5_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR5_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR5_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR5_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR5_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR5_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR5_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR5_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR5_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR5_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR5_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR5_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR5_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR6_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR6_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR6_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR6_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR6_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR6_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR6_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR6_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR6_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR6_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR6_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR6_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR6_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR6_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR6_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR6_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR6_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR7_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR7_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR7_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR7_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR7_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR7_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR7_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR7_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR7_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR7_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR7_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR7_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR7_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR7_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR7_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR7_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR7_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR8_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR8_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR8_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR8_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR8_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR8_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR8_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR8_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR8_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR8_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR8_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR8_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR8_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR8_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR8_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR8_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR8_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR9_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR9_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR9_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR9_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR9_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR9_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR9_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR9_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR9_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR9_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR9_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR9_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR9_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR9_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR9_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR9_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR9_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR10_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR10_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR10_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR10_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR10_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR10_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR10_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR10_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR10_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR10_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR10_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR10_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR10_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR10_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR10_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR10_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR10_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR11_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR11_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR11_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR11_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR11_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR11_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR11_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR11_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR11_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR11_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR11_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR11_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR11_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR11_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR11_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR11_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR11_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR12_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR12_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR12_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR12_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR12_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR12_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR12_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR12_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR12_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR12_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR12_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR12_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR12_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR12_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR12_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR12_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR12_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR13_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR13_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR13_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR13_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR13_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR13_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR13_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR13_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR13_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR13_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR13_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR13_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR13_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR13_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR13_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR13_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR13_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR14_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR14_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR14_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR14_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR14_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR14_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR14_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR14_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR14_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR14_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR14_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR14_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR14_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR14_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR14_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR14_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR14_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR15_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR15_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR15_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR15_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR15_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR15_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR15_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR15_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR15_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR15_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR15_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR15_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR15_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR15_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR15_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR15_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR15_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR16_START register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR16_START_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR16_START_ADDRL_M   0xF000U       // Lower Start Address
#define SYNCBRIDGEMPU_MPUR16_START_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR16_START_ADDRH_M   0xFFFF0000U   // Upper Start Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR16_END register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR16_END_ADDRL_S   12U
#define SYNCBRIDGEMPU_MPUR16_END_ADDRL_M   0xF000U       // Lower End Address
#define SYNCBRIDGEMPU_MPUR16_END_ADDRH_S   16U
#define SYNCBRIDGEMPU_MPUR16_END_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR16_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR16_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR16_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR16_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUR16_ACCESS register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUR16_ACCESS_ACCESS_S   0U
#define SYNCBRIDGEMPU_MPUR16_ACCESS_ACCESS_M   0x3U   // Region Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUCTRL register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUCTRL_MPUEN   0x1U   // Enable MPU function

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUCFG_LOCK register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUCFG_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the MPUCFG_COMMIT register
//
//*************************************************************************************************
#define SYNCBRIDGEMPU_MPUCFG_COMMIT_COMMIT   0x1U   // Permanent Commit



#endif
