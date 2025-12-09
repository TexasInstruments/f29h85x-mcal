//###########################################################################
//
// FILE:    hw_fri.h
//
// TITLE:   Definitions for the FRI registers.
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

#ifndef HW_FRI_H
#define HW_FRI_H

//*************************************************************************************************
//
// The following are defines for the FRI register offsets
//
//*************************************************************************************************
#define FRI_O_REVISION             0x0U    // IP Revision Register
#define FRI_O_FRDCNTL              0x10U   // Flash Read Control Register
#define FRI_O_FRDCNTL_LOCK         0x14U   // Flash Read Control Lock Register
#define FRI_O_FRDCNTL_COMMIT       0x18U   // Flash Read Control Commit Register
#define FRI_O_1_INTF_CTRL          0x30U   // Flash Read Interface 1 Control Register
#define FRI_O_1_INTF_CTRL_LOCK     0x34U   // Flash Read Interface 1 Control Lock Register
#define FRI_O_1_INTF_CTRL_COMMIT   0x38U   // Flash Read Interface 1 Control Commit Register
#define FRI_O_1_INTF_CLR           0x3CU   // Flash Read Interface 1 Clear Register
#define FRI_O_2_INTF_CTRL          0x40U   // Flash Read Interface 2 Control Register
#define FRI_O_2_INTF_CTRL_LOCK     0x44U   // Flash Read Interface 2 Control Lock Register
#define FRI_O_2_INTF_CTRL_COMMIT   0x48U   // Flash Read Interface 2 Control Commit Register
#define FRI_O_2_INTF_CLR           0x4CU   // Flash Read Interface 2 Clear Register
#define FRI_O_3_INTF_CTRL          0x50U   // Flash Read Interface 3 Control Register
#define FRI_O_3_INTF_CTRL_LOCK     0x54U   // Flash Read Interface 3 Control Lock Register
#define FRI_O_3_INTF_CTRL_COMMIT   0x58U   // Flash Read Interface 3 Control Commit Register
#define FRI_O_3_INTF_CLR           0x5CU   // Flash Read Interface 3 Clear Register
#define FRI_O_4_INTF_CTRL          0x60U   // Flash Read Interface 4 Control Register
#define FRI_O_4_INTF_CTRL_LOCK     0x64U   // Flash Read Interface 4 Control Lock Register
#define FRI_O_4_INTF_CTRL_COMMIT   0x68U   // Flash Read Interface 4 Control Commit Register
#define FRI_O_4_INTF_CLR           0x6CU   // Flash Read Interface 4 Clear Register
#define FRI_O_PARITY_TEST          0x70U   // Parity Test Enable
#define FRI_O_PARITY_TEST_LOCK     0x74U   // Parity Test Lock Register
#define FRI_O_PARITY_TEST_COMMIT   0x78U   // Parity Test Commit Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define FRI_REVISION_MINREV_S   0U
#define FRI_REVISION_MINREV_M   0xFFU     // Minor Revision Number
#define FRI_REVISION_MAJREV_S   8U
#define FRI_REVISION_MAJREV_M   0xFF00U   // Major Revision Number

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRDCNTL register
//
//*************************************************************************************************
#define FRI_FRDCNTL_RWAIT_S           8U
#define FRI_FRDCNTL_RWAIT_M           0xF00U       // Read Waitstate
#define FRI_FRDCNTL_TRIMENGRRWAIT_S   24U
#define FRI_FRDCNTL_TRIMENGRRWAIT_M   0xF000000U   // Read Waitstate of Trim and ENGR sectors

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRDCNTL_LOCK register
//
//*************************************************************************************************
#define FRI_FRDCNTL_LOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRDCNTL_COMMIT register
//
//*************************************************************************************************
#define FRI_FRDCNTL_COMMIT_COMMIT   0x1U   // FRDCNTL_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI1_INTF_CTRL register
//
//*************************************************************************************************
#define FRI_1_INTF_CTRL_PREFETCH_EN       0x1U   // Prefetch Enable
#define FRI_1_INTF_CTRL_DATA_CACHE_EN     0x2U   // Data Line Buffer Enable
#define FRI_1_INTF_CTRL_CODE_CACHE_EN     0x4U   // Code Cache Enable
#define FRI_1_INTF_CTRL_DATA_PREREAD_EN   0x8U   // Sequential Data Preread Mode Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI1_INTF_CTRL_LOCK register
//
//*************************************************************************************************
#define FRI_1_INTF_CTRL_LOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI1_INTF_CTRL_COMMIT register
//
//*************************************************************************************************
#define FRI_1_INTF_CTRL_COMMIT_COMMIT   0x1U   // FRD_INTF_CTRL_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI1_INTF_CLR register
//
//*************************************************************************************************
#define FRI_1_INTF_CLR_PREFETCH_CLR     0x1U   // Prefetch Clear
#define FRI_1_INTF_CLR_DATA_CACHE_CLR   0x2U   // Data Line Buffer Clear
#define FRI_1_INTF_CLR_CODE_CACHE_CLR   0x4U   // Code Cache Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI2_INTF_CTRL register
//
//*************************************************************************************************
#define FRI_2_INTF_CTRL_PREFETCH_EN       0x1U   // Prefetch Enable
#define FRI_2_INTF_CTRL_DATA_CACHE_EN     0x2U   // Data Line Buffer Enable
#define FRI_2_INTF_CTRL_CODE_CACHE_EN     0x4U   // Code Cache Enable
#define FRI_2_INTF_CTRL_DATA_PREREAD_EN   0x8U   // Sequential Data Preread Mode Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI2_INTF_CTRL_LOCK register
//
//*************************************************************************************************
#define FRI_2_INTF_CTRL_LOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI2_INTF_CTRL_COMMIT register
//
//*************************************************************************************************
#define FRI_2_INTF_CTRL_COMMIT_COMMIT   0x1U   // FRD_INTF_CTRL_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI2_INTF_CLR register
//
//*************************************************************************************************
#define FRI_2_INTF_CLR_PREFETCH_CLR     0x1U   // Prefetch Clear
#define FRI_2_INTF_CLR_DATA_CACHE_CLR   0x2U   // Data Line Buffer Clear
#define FRI_2_INTF_CLR_CODE_CACHE_CLR   0x4U   // Code Cache Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI3_INTF_CTRL register
//
//*************************************************************************************************
#define FRI_3_INTF_CTRL_PREFETCH_EN       0x1U   // Prefetch Enable
#define FRI_3_INTF_CTRL_DATA_CACHE_EN     0x2U   // Data Line Buffer Enable
#define FRI_3_INTF_CTRL_CODE_CACHE_EN     0x4U   // Code Cache Enable
#define FRI_3_INTF_CTRL_DATA_PREREAD_EN   0x8U   // Sequential Data Preread Mode Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI3_INTF_CTRL_LOCK register
//
//*************************************************************************************************
#define FRI_3_INTF_CTRL_LOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI3_INTF_CTRL_COMMIT register
//
//*************************************************************************************************
#define FRI_3_INTF_CTRL_COMMIT_COMMIT   0x1U   // FRD_INTF_CTRL_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI3_INTF_CLR register
//
//*************************************************************************************************
#define FRI_3_INTF_CLR_PREFETCH_CLR     0x1U   // Prefetch Clear
#define FRI_3_INTF_CLR_DATA_CACHE_CLR   0x2U   // Data Line Buffer Clear
#define FRI_3_INTF_CLR_CODE_CACHE_CLR   0x4U   // Code Cache Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI4_INTF_CTRL register
//
//*************************************************************************************************
#define FRI_4_INTF_CTRL_PREFETCH_EN       0x1U   // Prefetch Enable
#define FRI_4_INTF_CTRL_DATA_CACHE_EN     0x2U   // Data Line Buffer Enable
#define FRI_4_INTF_CTRL_CODE_CACHE_EN     0x4U   // Code Cache Enable
#define FRI_4_INTF_CTRL_DATA_PREREAD_EN   0x8U   // Sequential Data Preread Mode Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI4_INTF_CTRL_LOCK register
//
//*************************************************************************************************
#define FRI_4_INTF_CTRL_LOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI4_INTF_CTRL_COMMIT register
//
//*************************************************************************************************
#define FRI_4_INTF_CTRL_COMMIT_COMMIT   0x1U   // FRD_INTF_CTRL_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the FRI4_INTF_CLR register
//
//*************************************************************************************************
#define FRI_4_INTF_CLR_PREFETCH_CLR     0x1U   // Prefetch Clear
#define FRI_4_INTF_CLR_DATA_CACHE_CLR   0x2U   // Data Line Buffer Clear
#define FRI_4_INTF_CLR_CODE_CACHE_CLR   0x4U   // Code Cache Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST register
//
//*************************************************************************************************
#define FRI_PARITY_TEST_TESTEN_S   0U
#define FRI_PARITY_TEST_TESTEN_M   0xFU   // Parity Test Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST_LOCK register
//
//*************************************************************************************************
#define FRI_PARITY_TEST_LOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST_COMMIT register
//
//*************************************************************************************************
#define FRI_PARITY_TEST_COMMIT_COMMIT   0x1U   // PARITY_TEST_LOCK Permanent Commit



#endif
