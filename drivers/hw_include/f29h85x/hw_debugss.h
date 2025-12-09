//###########################################################################
//
// FILE:    hw_debugss.h
//
// TITLE:   Definitions for the DEBUGSS registers.
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

#ifndef HW_DEBUGSS_H
#define HW_DEBUGSS_H

//*************************************************************************************************
//
// The following are defines for the DEBUGSS register offsets
//
//*************************************************************************************************
#define DEBUGSS_O_PASSWORD_ID              0x0U     // Password ID
#define DEBUGSS_O_PASSWORD1                0x4U     // Password1 Register
#define DEBUGSS_O_PASSWORD2                0x8U     // Password2 Register
#define DEBUGSS_O_PASSWORD3                0xCU     // Password3 Register
#define DEBUGSS_O_PASSWORD4                0x10U    // Password4 Register
#define DEBUGSS_O_DEBUG_ENABLE_STATUS      0x14U    // Debug status register
#define DEBUGSS_O_TEST_PASSWORD1           0x80U    // Test Password1 Register
#define DEBUGSS_O_TEST_PASSWORD2           0x84U    // Test Password2 Register
#define DEBUGSS_O_TEST_PASSWORD3           0x88U    // Test Password3 Register
#define DEBUGSS_O_TEST_PASSWORD4           0x8CU    // Test Password4 Register
#define DEBUGSS_O_DBG2CPU1_CHR             0x100U   // Debugger to CPU1/SSU challenge response
#define DEBUGSS_O_CPU12DBG_CHR             0x104U   // CPU1/SSU to Debugger challenge response
#define DEBUGSS_O_DBG2CPU1_HS              0x108U   // Debugger to CPU1/SSU Handshake
#define DEBUGSS_O_CPU12DBG_HS              0x10CU   // CPU1/SSU to Debugger Handshake
#define DEBUGSS_O_DBG2CPU1_INT_FLG         0x110U   // Debugger to CPU1 interrupt flag
#define DEBUGSS_O_DBG2CPU1_INT_FLG_SET     0x114U   // Debugger to CPU1 interrupt set
#define DEBUGSS_O_DBG2CPU1_INT_FLG_CLR     0x118U   // Debugger to CPU1 interrupt clear
#define DEBUGSS_O_SSU_DBG_STATUS           0x204U   // Read only SSU DBG Status
#define DEBUGSS_O_HSM_DBG_STATUS           0x208U   // Read only HSM DBG Status
#define DEBUGSS_O_CTL_DBG_STATUS           0x20CU   // Read only CTL DBG Status
#define DEBUGSS_O_GEN_DBG_STATUS0          0x210U   // Read only GEN DBG Status0
#define DEBUGSS_O_GEN_DBG_STATUS1          0x214U   // Read only GEN DBG Status1
#define DEBUGSS_O_GEN_DBG_STATUS2          0x218U   // Read only GEN DBG Status2
#define DEBUGSS_O_GEN_DBG_STATUS3          0x21CU   // Read only GEN DBG Status3
#define DEBUGSS_O_GEN_DBG_STICKY_STATUS0   0x220U   // Read only GEN DBG_STICKY Status0
#define DEBUGSS_O_GEN_DBG_STICKY_STATUS1   0x224U   // Read only GEN DBG_STICKY Status1
#define DEBUGSS_O_GEN_DBG_STICKY_STATUS2   0x228U   // Read only GEN DBG_STICKY Status2
#define DEBUGSS_O_GEN_DBG_STICKY_STATUS3   0x22CU   // Read only GEN DBG_STICKY Status3
#define DEBUGSS_O_GEN_DBG_STICKY_CLR0      0x230U   // Write only GEN_DBG_STICKY clear register0
#define DEBUGSS_O_GEN_DBG_STICKY_CLR1      0x234U   // Write only GEN_DBG_STICKY clear register1
#define DEBUGSS_O_GEN_DBG_STICKY_CLR2      0x238U   // Write only GEN_DBG_STICKY clear register2
#define DEBUGSS_O_GEN_DBG_STICKY_CLR3      0x23CU   // Write only GEN_DBG_STICKY clear register3
#define DEBUGSS_O_C29_DBG_RX_ADDR          0x240U   // RX Data Write Address
#define DEBUGSS_O_JTAG_GEN                 0x244U   // jtag general purpose register


//*************************************************************************************************
//
// The following are defines for the bit fields in the PASSWORD_ID register
//
//*************************************************************************************************
#define DEBUGSS_PASSWORD_ID_ID_S   0U
#define DEBUGSS_PASSWORD_ID_ID_M   0xFU   // Password ID

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEBUG_ENABLE_STATUS register
//
//*************************************************************************************************
#define DEBUGSS_DEBUG_ENABLE_STATUS_JTAG_DBGEN            0x1U      // JTAG Full Debug enable
#define DEBUGSS_DEBUG_ENABLE_STATUS_ZONE0_DBGEN           0x2U      // Zone1 Full Debug enable
#define DEBUGSS_DEBUG_ENABLE_STATUS_ZONE1_DBGEN           0x4U      // Zone2 Full Debug enable
#define DEBUGSS_DEBUG_ENABLE_STATUS_ZONE2_DBGEN           0x8U      // Zone3 Full Debug enable
#define DEBUGSS_DEBUG_ENABLE_STATUS_ZONE3_DBGEN           0x10U     // Zone4 Full Debug enable
#define DEBUGSS_DEBUG_ENABLE_STATUS_PARTIAL_ZONE1_DBGEN   0x100U    // Partial Zone1 Debug enable
#define DEBUGSS_DEBUG_ENABLE_STATUS_PARTIAL_ZONE2_DBGEN   0x200U    // Partial Zone2 Debug enable
#define DEBUGSS_DEBUG_ENABLE_STATUS_PARTIAL_ZONE3_DBGEN   0x400U    // Partial Zone3 Debug enable
#define DEBUGSS_DEBUG_ENABLE_STATUS_ZONEX_DBGEN           0x8000U   // ZoneX Debug enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG2CPU1_INT_FLG register
//
//*************************************************************************************************
#define DEBUGSS_DBG2CPU1_INT_FLG_INT   0x1U   // Debugger to CPU Interrupt flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG2CPU1_INT_FLG_SET register
//
//*************************************************************************************************
#define DEBUGSS_DBG2CPU1_INT_FLG_SET_INT   0x1U   // Debugger to CPU Interrupt set

//*************************************************************************************************
//
// The following are defines for the bit fields in the DBG2CPU1_INT_FLG_CLR register
//
//*************************************************************************************************
#define DEBUGSS_DBG2CPU1_INT_FLG_CLR_INT   0x1U   // Debugger to CPU Interrupt flag clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the C29_DBG_RX_ADDR register
//
//*************************************************************************************************
#define DEBUGSS_C29_DBG_RX_ADDR_ADDRESS_S   1U
#define DEBUGSS_C29_DBG_RX_ADDR_ADDRESS_M   0xFFFFFFFEU   // Rx Bus Address register



#endif
