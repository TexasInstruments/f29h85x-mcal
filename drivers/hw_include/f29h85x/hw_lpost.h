//###########################################################################
//
// FILE:    hw_lpost.h
//
// TITLE:   Definitions for the LPOST registers.
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

#ifndef HW_LPOST_H
#define HW_LPOST_H

//*************************************************************************************************
//
// The following are defines for the LPOST register offsets
//
//*************************************************************************************************
#define LPOST_O_REVISION       0x0U    // IP Revision tie-off value
#define LPOST_O_CONTROL        0x8U    // Register to start the power-on self-test operation.
#define LPOST_O_CONFIG         0x10U   // Register to configure the coverage for the power-on
                                       // self-test operation.
#define LPOST_O_STATUS         0x40U   // Register indicating the status of power-on self-test
                                       // operation.
#define LPOST_O_STATUS_CLEAR   0x48U   // Register to clear the LPOST Status
#define LPOST_O_LOCK           0x70U   // Register to lock the LPOST register configurations
#define LPOST_O_COMMIT         0x78U   // Register to commit the LPOST register configuration


//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define LPOST_REVISION_MINOR_S    0U
#define LPOST_REVISION_MINOR_M    0x3FU         // Minor Revision Number
#define LPOST_REVISION_CUSTOM_S   6U
#define LPOST_REVISION_CUSTOM_M   0xC0U         // Custom Module Number
#define LPOST_REVISION_MAJOR_S    8U
#define LPOST_REVISION_MAJOR_M    0x700U        // Major Revision Number
#define LPOST_REVISION_FUNC_S     16U
#define LPOST_REVISION_FUNC_M     0xFFF0000U    // Functional Release Number
#define LPOST_REVISION_SCHEME_S   30U
#define LPOST_REVISION_SCHEME_M   0xC0000000U   // Defines Scheme for Module

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPOST_CONTROL register
//
//*************************************************************************************************
#define LPOST_CONTROL_GO_S   0U
#define LPOST_CONTROL_GO_M   0xFU   // Start the self-test operation

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPOST_CONFIG register
//
//*************************************************************************************************
#define LPOST_CONFIG_COVERAGE_S   0U
#define LPOST_CONFIG_COVERAGE_M   0xFU   // Coverage configuration for the power on self-test

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPOST_STATUS register
//
//*************************************************************************************************
#define LPOST_STATUS_DONE                  0x1U          // LPOST completion status.
#define LPOST_STATUS_PASS                  0x2U          // LPOST test pass/fail status
#define LPOST_STATUS_TIMEOUT               0x4U          // LPOST test timeout status
#define LPOST_STATUS_SANITY_TEST_PASS      0x10000U      // LPOST sanity test status
#define LPOST_STATUS_SANITY_TIMEOUT_PASS   0x20000U      // LPOST timeout test status
#define LPOST_STATUS_RAW_PORESETN_STATUS   0x80000000U   // The bit will indicate RAW PORESETn
                                                         // Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPOST_STATUS_CLEAR register
//
//*************************************************************************************************
#define LPOST_STATUS_CLEAR_DONE                  0x1U          // DONE status clear
#define LPOST_STATUS_CLEAR_PASS                  0x2U          // PASS status clear
#define LPOST_STATUS_CLEAR_TIMEOUT               0x4U          // TIMEOUT status clear
#define LPOST_STATUS_CLEAR_SANITY_TEST_PASS      0x10000U      // SANITY_TEST_PASS status clear
#define LPOST_STATUS_CLEAR_SANITY_TIMEOUT_PASS   0x20000U      // SANITY_TIMEOUT_PASS status clear
#define LPOST_STATUS_CLEAR_RAW_PORESETN_STATUS   0x80000000U   // Clear bit for RAW_PORESETn_STATUS

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPOST_LOCK register
//
//*************************************************************************************************
#define LPOST_LOCK_LPOST_CONTROL        0x4U         // Register lock configuration
#define LPOST_LOCK_LPOST_CONFIG         0x10U        // Register lock configuration
#define LPOST_LOCK_LPOST_STATUS_CLEAR   0x40000U     // Register lock configuration
#define LPOST_LOCK_PARITY_TEST          0x4000000U   // Register lock configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPOST_COMMIT register
//
//*************************************************************************************************
#define LPOST_COMMIT_LPOST_CONTROL        0x4U         // Register commit configuration
#define LPOST_COMMIT_LPOST_CONFIG         0x10U        // Register commit configuration
#define LPOST_COMMIT_LPOST_STATUS_CLEAR   0x40000U     // Register lock configuration
#define LPOST_COMMIT_PARITY_TEST          0x4000000U   // Register commit configuration



#endif
