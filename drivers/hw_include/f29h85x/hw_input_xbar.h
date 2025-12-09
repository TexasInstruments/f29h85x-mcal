//###########################################################################
//
// FILE:    hw_input_xbar.h
//
// TITLE:   Definitions for the INPUT_XBAR registers.
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

#ifndef HW_INPUT_XBAR_H
#define HW_INPUT_XBAR_H

//*************************************************************************************************
//
// The following are defines for the INPUT_XBAR register offsets
//
//*************************************************************************************************
#define INPUT_XBAR_O_INPUTSELECT(i)     (0x0U + ((i) * 0x4U))   // (0 <= i < 64) Input Select
                                                                // Register (GPIO0 to x)
#define INPUT_XBAR_O_INPUTSELECTLOCK1   0x400U                  // Input Select Lock Register 1
#define INPUT_XBAR_O_INPUTSELECTLOCK2   0x404U                  // Input Select Lock Register 2


//*************************************************************************************************
//
// The following are defines for the bit fields in the INPUTSELECT register
//
//*************************************************************************************************
#define INPUT_XBAR_INPUTSELECT_SELECT_S   0U
#define INPUT_XBAR_INPUTSELECT_SELECT_M   0xFFFFU   // Select GPIO for INPUT{#} signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the INPUTSELECTLOCK1 register
//
//*************************************************************************************************
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT1SELECT    0x1U          // Lock bit for INPUT1SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT2SELECT    0x2U          // Lock bit for INPUT2SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT3SELECT    0x4U          // Lock bit for INPUT3SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT4SELECT    0x8U          // Lock bit for INPUT4SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT5SELECT    0x10U         // Lock bit for INPUT5SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT6SELECT    0x20U         // Lock bit for INPUT6SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT7SELECT    0x40U         // Lock bit for INPUT7SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT8SELECT    0x80U         // Lock bit for INPUT8SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT9SELECT    0x100U        // Lock bit for INPUT9SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT10SELECT   0x200U        // Lock bit for INPUT10SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT11SELECT   0x400U        // Lock bit for INPUT11SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT12SELECT   0x800U        // Lock bit for INPUT12SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT13SELECT   0x1000U       // Lock bit for INPUT13SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT14SELECT   0x2000U       // Lock bit for INPUT14SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT15SELECT   0x4000U       // Lock bit for INPUT15SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT16SELECT   0x8000U       // Lock bit for INPUT16SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT17SELECT   0x10000U      // Lock bit for INPUT17SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT18SELECT   0x20000U      // Lock bit for INPUT18SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT19SELECT   0x40000U      // Lock bit for INPUT19SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT20SELECT   0x80000U      // Lock bit for INPUT20SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT21SELECT   0x100000U     // Lock bit for INPUT21SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT22SELECT   0x200000U     // Lock bit for INPUT22SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT23SELECT   0x400000U     // Lock bit for INPUT23SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT24SELECT   0x800000U     // Lock bit for INPUT24SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT25SELECT   0x1000000U    // Lock bit for INPUT25SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT26SELECT   0x2000000U    // Lock bit for INPUT26SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT27SELECT   0x4000000U    // Lock bit for INPUT27SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT28SELECT   0x8000000U    // Lock bit for INPUT28SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT29SELECT   0x10000000U   // Lock bit for INPUT29SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT30SELECT   0x20000000U   // Lock bit for INPUT30SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT31SELECT   0x40000000U   // Lock bit for INPUT31SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK1_INPUT32SELECT   0x80000000U   // Lock bit for INPUT32SELECT
                                                                  // Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the INPUTSELECTLOCK2 register
//
//*************************************************************************************************
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT33SELECT   0x1U          // Lock bit for INPUT33SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT34SELECT   0x2U          // Lock bit for INPUT34SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT35SELECT   0x4U          // Lock bit for INPUT35SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT36SELECT   0x8U          // Lock bit for INPUT36SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT37SELECT   0x10U         // Lock bit for INPUT37SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT38SELECT   0x20U         // Lock bit for INPUT38SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT39SELECT   0x40U         // Lock bit for INPUT39SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT40SELECT   0x80U         // Lock bit for INPUT40SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT41SELECT   0x100U        // Lock bit for INPUT41SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT42SELECT   0x200U        // Lock bit for INPUT42SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT43SELECT   0x400U        // Lock bit for INPUT43SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT44SELECT   0x800U        // Lock bit for INPUT44SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT45SELECT   0x1000U       // Lock bit for INPUT45SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT46SELECT   0x2000U       // Lock bit for INPUT46SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT47SELECT   0x4000U       // Lock bit for INPUT47SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT48SELECT   0x8000U       // Lock bit for INPUT48SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT49SELECT   0x10000U      // Lock bit for INPUT49SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT50SELECT   0x20000U      // Lock bit for INPUT50SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT51SELECT   0x40000U      // Lock bit for INPUT51SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT52SELECT   0x80000U      // Lock bit for INPUT52SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT53SELECT   0x100000U     // Lock bit for INPUT53SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT54SELECT   0x200000U     // Lock bit for INPUT54SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT55SELECT   0x400000U     // Lock bit for INPUT55SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT56SELECT   0x800000U     // Lock bit for INPUT56SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT57SELECT   0x1000000U    // Lock bit for INPUT57SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT58SELECT   0x2000000U    // Lock bit for INPUT58SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT59SELECT   0x4000000U    // Lock bit for INPUT59SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT60SELECT   0x8000000U    // Lock bit for INPUT60SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT61SELECT   0x10000000U   // Lock bit for INPUT61SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT62SELECT   0x20000000U   // Lock bit for INPUT62SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT63SELECT   0x40000000U   // Lock bit for INPUT63SELECT
                                                                  // Register
#define INPUT_XBAR_INPUTSELECTLOCK2_INPUT64SELECT   0x80000000U   // Lock bit for INPUT64SELECT
                                                                  // Register



#endif
