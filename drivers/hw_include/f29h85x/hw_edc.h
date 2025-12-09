//###########################################################################
//
// FILE:    hw_edc.h
//
// TITLE:   Definitions for the EDC registers.
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

#ifndef HW_EDC_H
#define HW_EDC_H

//*************************************************************************************************
//
// The following are defines for the EDC register offsets
//
//*************************************************************************************************
#define EDC_O_REVISION       0x10U   // Revision Register
#define EDC_O_CONTROL        0x14U   // Control Register
#define EDC_O_ERROR1         0x18U   // Error 1 Register
#define EDC_O_ERROR2         0x1CU   // Error 2 Register
#define EDC_O_ERRORSTATUS1   0x20U   // Error Status 1 Register
#define EDC_O_ERRORSTATUS2   0x24U   // Error Status 2 Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define EDC_REVISION_MINOR_S    0U
#define EDC_REVISION_MINOR_M    0x3FU         // Minor revision of module
#define EDC_REVISION_CUSTOM_S   6U
#define EDC_REVISION_CUSTOM_M   0xC0U         // Special version
#define EDC_REVISION_MAJOR_S    8U
#define EDC_REVISION_MAJOR_M    0x700U        // Major revision of module
#define EDC_REVISION_RTL_S      11U
#define EDC_REVISION_RTL_M      0xF800U       // RTL version of the module
#define EDC_REVISION_FUNC_S     16U
#define EDC_REVISION_FUNC_M     0xFFF0000U    // Assigned func id
#define EDC_REVISION_SCHEME_S   30U
#define EDC_REVISION_SCHEME_M   0xC0000000U   // Reserved

//*************************************************************************************************
//
// The following are defines for the bit fields in the CONTROL register
//
//*************************************************************************************************
#define EDC_CONTROL_ECCCHECK        0x2U     // Enable ECC Checkers
#define EDC_CONTROL_FORCE_SE        0x8U     // Inject Single bit error
#define EDC_CONTROL_FORCE_DE        0x10U    // Inject Double bit error
#define EDC_CONTROL_FORCE_N_BIT     0x20U    // Incremental Injection
#define EDC_CONTROL_ECC_PATTERN_S   8U
#define EDC_CONTROL_ECC_PATTERN_M   0xF00U   // Data Pattern

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERROR1 register
//
//*************************************************************************************************
#define EDC_ERROR1_ECCGRP_S    0U
#define EDC_ERROR1_ECCGRP_M    0xFFFFU      // Group of Checker to inject
#define EDC_ERROR1_ECCBIT1_S   16U
#define EDC_ERROR1_ECCBIT1_M   0x1FF0000U   // ECC BIT1

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERROR2 register
//
//*************************************************************************************************
#define EDC_ERROR2_ECCBIT2_S   0U
#define EDC_ERROR2_ECCBIT2_M   0x1FFU   // ECC BIT2

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRORSTATUS1 register
//
//*************************************************************************************************
#define EDC_ERRORSTATUS1_COR_PEND_S             0U
#define EDC_ERRORSTATUS1_COR_PEND_M             0x3U          // Correctable Pending
#define EDC_ERRORSTATUS1_UNCOR_PEND_S           2U
#define EDC_ERRORSTATUS1_UNCOR_PEND_M           0xCU          // Uncorrectable Pending
#define EDC_ERRORSTATUS1_INJ_COR_PEND_S         4U
#define EDC_ERRORSTATUS1_INJ_COR_PEND_M         0x30U         // Injected correctable pending
                                                              // interrupts
#define EDC_ERRORSTATUS1_INJ_UNCOR_PEND_S       6U
#define EDC_ERRORSTATUS1_INJ_UNCOR_PEND_M       0xC0U         // Injected uncorrectable pending
                                                              // interrupts
#define EDC_ERRORSTATUS1_COR_PEND_CLR_S         8U
#define EDC_ERRORSTATUS1_COR_PEND_CLR_M         0x300U        // Correctable pending interrupts
#define EDC_ERRORSTATUS1_UNCOR_PEND_CLR_S       10U
#define EDC_ERRORSTATUS1_UNCOR_PEND_CLR_M       0xC00U        // Correctable pending interrupts
#define EDC_ERRORSTATUS1_INJ_COR_PEND_CLR_S     12U
#define EDC_ERRORSTATUS1_INJ_COR_PEND_CLR_M     0x3000U       // Injected correctable pending
                                                              // interrupts
#define EDC_ERRORSTATUS1_INJ_UNCOR_PEND_CLR_S   14U
#define EDC_ERRORSTATUS1_INJ_UNCOR_PEND_CLR_M   0xC000U       // Injected uncorrectable pending
                                                              // interrupts
#define EDC_ERRORSTATUS1_ERR_GROUP_S            16U
#define EDC_ERRORSTATUS1_ERR_GROUP_M            0xFFFF0000U   // Specify Checker that reported
                                                              // Error

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRORSTATUS2 register
//
//*************************************************************************************************
#define EDC_ERRORSTATUS2_ERR_BIT_S      0U
#define EDC_ERRORSTATUS2_ERR_BIT_M      0xFFFFU       // error bit
#define EDC_ERRORSTATUS2_ERROR_TYPE_S   16U
#define EDC_ERRORSTATUS2_ERROR_TYPE_M   0xFFFF0000U   // ERROR Type



#endif
