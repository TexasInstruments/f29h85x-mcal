//###########################################################################
//
// FILE:    hw_clb_xbar.h
//
// TITLE:   Definitions for the CLB_XBAR registers.
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

#ifndef HW_CLB_XBAR_H
#define HW_CLB_XBAR_H

//*************************************************************************************************
//
// The following are defines for the CLB_XBAR register offsets
//
//*************************************************************************************************
#define CLB_XBAR_O_CLBXBAROUTINVERT   0x30U                    // Output Signal Invert Select
#define CLB_XBAR_O_CLBXBARLOCK        0x80U                    // Configuration Lock register
#define CLB_XBAR_O_CLBXBARG0SEL(i)    (0x100U + ((i) * 64U))   // (0 <= i < 8) CLBXBAR G0 Input
                                                               // Select
#define CLB_XBAR_O_CLBXBARG1SEL(i)    (0x104U + ((i) * 64U))   // (0 <= i < 8) CLBXBAR G1 Input
                                                               // Select
#define CLB_XBAR_O_CLBXBARG2SEL(i)    (0x108U + ((i) * 64U))   // (0 <= i < 8) CLBXBAR G2 Input
                                                               // Select
#define CLB_XBAR_O_CLBXBARG3SEL(i)    (0x10CU + ((i) * 64U))   // (0 <= i < 8) CLBXBAR G3 Input
                                                               // Select
#define CLB_XBAR_O_CLBXBARG4SEL(i)    (0x110U + ((i) * 64U))   // (0 <= i < 8) CLBXBAR G4 Input
                                                               // Select
#define CLB_XBAR_O_CLBXBARG5SEL(i)    (0x114U + ((i) * 64U))   // (0 <= i < 8) CLBXBAR G5 Input
                                                               // Select
#define CLB_XBAR_O_CLBXBARG6SEL(i)    (0x118U + ((i) * 64U))   // (0 <= i < 8) CLBXBAR G6 Input
                                                               // Select
#define CLB_XBAR_O_CLBXBARG7SEL(i)    (0x11CU + ((i) * 64U))   // (0 <= i < 8) CLBXBAR G7 Input
                                                               // Select


//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBAROutInvert register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBAROUTINVERT_XBAR1   0x1U    // Invert XBAR Output Select for XBAR1
#define CLB_XBAR_CLBXBAROUTINVERT_XBAR2   0x2U    // Invert XBAR Output Select for XBAR2
#define CLB_XBAR_CLBXBAROUTINVERT_XBAR3   0x4U    // Invert XBAR Output Select for XBAR3
#define CLB_XBAR_CLBXBAROUTINVERT_XBAR4   0x8U    // Invert XBAR Output Select for XBAR4
#define CLB_XBAR_CLBXBAROUTINVERT_XBAR5   0x10U   // Invert XBAR Output Select for XBAR5
#define CLB_XBAR_CLBXBAROUTINVERT_XBAR6   0x20U   // Invert XBAR Output Select for XBAR6
#define CLB_XBAR_CLBXBAROUTINVERT_XBAR7   0x40U   // Invert XBAR Output Select for XBAR7
#define CLB_XBAR_CLBXBAROUTINVERT_XBAR8   0x80U   // Invert XBAR Output Select for XBAR8

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARLock register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARLOCK_LOCK    0x1U          // Locks the configuration for ECLB-XBAR
#define CLB_XBAR_CLBXBARLOCK_KEY_S   16U
#define CLB_XBAR_CLBXBARLOCK_KEY_M   0xFFFF0000U   // Write protection KEY

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARG0SEL register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARG0SEL_INPUT0    0x1U          // Select bit for INPUT0
#define CLB_XBAR_CLBXBARG0SEL_INPUT1    0x2U          // Select bit for INPUT1
#define CLB_XBAR_CLBXBARG0SEL_INPUT2    0x4U          // Select bit for INPUT2
#define CLB_XBAR_CLBXBARG0SEL_INPUT3    0x8U          // Select bit for INPUT3
#define CLB_XBAR_CLBXBARG0SEL_INPUT4    0x10U         // Select bit for INPUT4
#define CLB_XBAR_CLBXBARG0SEL_INPUT5    0x20U         // Select bit for INPUT5
#define CLB_XBAR_CLBXBARG0SEL_INPUT6    0x40U         // Select bit for INPUT6
#define CLB_XBAR_CLBXBARG0SEL_INPUT7    0x80U         // Select bit for INPUT7
#define CLB_XBAR_CLBXBARG0SEL_INPUT8    0x100U        // Select bit for INPUT8
#define CLB_XBAR_CLBXBARG0SEL_INPUT9    0x200U        // Select bit for INPUT9
#define CLB_XBAR_CLBXBARG0SEL_INPUT10   0x400U        // Select bit for INPUT10
#define CLB_XBAR_CLBXBARG0SEL_INPUT11   0x800U        // Select bit for INPUT11
#define CLB_XBAR_CLBXBARG0SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define CLB_XBAR_CLBXBARG0SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define CLB_XBAR_CLBXBARG0SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define CLB_XBAR_CLBXBARG0SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define CLB_XBAR_CLBXBARG0SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define CLB_XBAR_CLBXBARG0SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define CLB_XBAR_CLBXBARG0SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define CLB_XBAR_CLBXBARG0SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define CLB_XBAR_CLBXBARG0SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define CLB_XBAR_CLBXBARG0SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define CLB_XBAR_CLBXBARG0SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define CLB_XBAR_CLBXBARG0SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define CLB_XBAR_CLBXBARG0SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define CLB_XBAR_CLBXBARG0SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define CLB_XBAR_CLBXBARG0SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define CLB_XBAR_CLBXBARG0SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define CLB_XBAR_CLBXBARG0SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define CLB_XBAR_CLBXBARG0SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define CLB_XBAR_CLBXBARG0SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define CLB_XBAR_CLBXBARG0SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARG1SEL register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARG1SEL_INPUT0    0x1U          // Select bit for INPUT0
#define CLB_XBAR_CLBXBARG1SEL_INPUT1    0x2U          // Select bit for INPUT1
#define CLB_XBAR_CLBXBARG1SEL_INPUT2    0x4U          // Select bit for INPUT2
#define CLB_XBAR_CLBXBARG1SEL_INPUT3    0x8U          // Select bit for INPUT3
#define CLB_XBAR_CLBXBARG1SEL_INPUT4    0x10U         // Select bit for INPUT4
#define CLB_XBAR_CLBXBARG1SEL_INPUT5    0x20U         // Select bit for INPUT5
#define CLB_XBAR_CLBXBARG1SEL_INPUT6    0x40U         // Select bit for INPUT6
#define CLB_XBAR_CLBXBARG1SEL_INPUT7    0x80U         // Select bit for INPUT7
#define CLB_XBAR_CLBXBARG1SEL_INPUT8    0x100U        // Select bit for INPUT8
#define CLB_XBAR_CLBXBARG1SEL_INPUT9    0x200U        // Select bit for INPUT9
#define CLB_XBAR_CLBXBARG1SEL_INPUT10   0x400U        // Select bit for INPUT10
#define CLB_XBAR_CLBXBARG1SEL_INPUT11   0x800U        // Select bit for INPUT11
#define CLB_XBAR_CLBXBARG1SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define CLB_XBAR_CLBXBARG1SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define CLB_XBAR_CLBXBARG1SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define CLB_XBAR_CLBXBARG1SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define CLB_XBAR_CLBXBARG1SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define CLB_XBAR_CLBXBARG1SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define CLB_XBAR_CLBXBARG1SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define CLB_XBAR_CLBXBARG1SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define CLB_XBAR_CLBXBARG1SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define CLB_XBAR_CLBXBARG1SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define CLB_XBAR_CLBXBARG1SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define CLB_XBAR_CLBXBARG1SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define CLB_XBAR_CLBXBARG1SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define CLB_XBAR_CLBXBARG1SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define CLB_XBAR_CLBXBARG1SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define CLB_XBAR_CLBXBARG1SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define CLB_XBAR_CLBXBARG1SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define CLB_XBAR_CLBXBARG1SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define CLB_XBAR_CLBXBARG1SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define CLB_XBAR_CLBXBARG1SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARG2SEL register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARG2SEL_INPUT0    0x1U          // Select bit for INPUT0
#define CLB_XBAR_CLBXBARG2SEL_INPUT1    0x2U          // Select bit for INPUT1
#define CLB_XBAR_CLBXBARG2SEL_INPUT2    0x4U          // Select bit for INPUT2
#define CLB_XBAR_CLBXBARG2SEL_INPUT3    0x8U          // Select bit for INPUT3
#define CLB_XBAR_CLBXBARG2SEL_INPUT4    0x10U         // Select bit for INPUT4
#define CLB_XBAR_CLBXBARG2SEL_INPUT5    0x20U         // Select bit for INPUT5
#define CLB_XBAR_CLBXBARG2SEL_INPUT6    0x40U         // Select bit for INPUT6
#define CLB_XBAR_CLBXBARG2SEL_INPUT7    0x80U         // Select bit for INPUT7
#define CLB_XBAR_CLBXBARG2SEL_INPUT8    0x100U        // Select bit for INPUT8
#define CLB_XBAR_CLBXBARG2SEL_INPUT9    0x200U        // Select bit for INPUT9
#define CLB_XBAR_CLBXBARG2SEL_INPUT10   0x400U        // Select bit for INPUT10
#define CLB_XBAR_CLBXBARG2SEL_INPUT11   0x800U        // Select bit for INPUT11
#define CLB_XBAR_CLBXBARG2SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define CLB_XBAR_CLBXBARG2SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define CLB_XBAR_CLBXBARG2SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define CLB_XBAR_CLBXBARG2SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define CLB_XBAR_CLBXBARG2SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define CLB_XBAR_CLBXBARG2SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define CLB_XBAR_CLBXBARG2SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define CLB_XBAR_CLBXBARG2SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define CLB_XBAR_CLBXBARG2SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define CLB_XBAR_CLBXBARG2SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define CLB_XBAR_CLBXBARG2SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define CLB_XBAR_CLBXBARG2SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define CLB_XBAR_CLBXBARG2SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define CLB_XBAR_CLBXBARG2SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define CLB_XBAR_CLBXBARG2SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define CLB_XBAR_CLBXBARG2SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define CLB_XBAR_CLBXBARG2SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define CLB_XBAR_CLBXBARG2SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define CLB_XBAR_CLBXBARG2SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define CLB_XBAR_CLBXBARG2SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARG3SEL register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARG3SEL_INPUT0    0x1U          // Select bit for INPUT0
#define CLB_XBAR_CLBXBARG3SEL_INPUT1    0x2U          // Select bit for INPUT1
#define CLB_XBAR_CLBXBARG3SEL_INPUT2    0x4U          // Select bit for INPUT2
#define CLB_XBAR_CLBXBARG3SEL_INPUT3    0x8U          // Select bit for INPUT3
#define CLB_XBAR_CLBXBARG3SEL_INPUT4    0x10U         // Select bit for INPUT4
#define CLB_XBAR_CLBXBARG3SEL_INPUT5    0x20U         // Select bit for INPUT5
#define CLB_XBAR_CLBXBARG3SEL_INPUT6    0x40U         // Select bit for INPUT6
#define CLB_XBAR_CLBXBARG3SEL_INPUT7    0x80U         // Select bit for INPUT7
#define CLB_XBAR_CLBXBARG3SEL_INPUT8    0x100U        // Select bit for INPUT8
#define CLB_XBAR_CLBXBARG3SEL_INPUT9    0x200U        // Select bit for INPUT9
#define CLB_XBAR_CLBXBARG3SEL_INPUT10   0x400U        // Select bit for INPUT10
#define CLB_XBAR_CLBXBARG3SEL_INPUT11   0x800U        // Select bit for INPUT11
#define CLB_XBAR_CLBXBARG3SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define CLB_XBAR_CLBXBARG3SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define CLB_XBAR_CLBXBARG3SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define CLB_XBAR_CLBXBARG3SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define CLB_XBAR_CLBXBARG3SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define CLB_XBAR_CLBXBARG3SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define CLB_XBAR_CLBXBARG3SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define CLB_XBAR_CLBXBARG3SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define CLB_XBAR_CLBXBARG3SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define CLB_XBAR_CLBXBARG3SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define CLB_XBAR_CLBXBARG3SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define CLB_XBAR_CLBXBARG3SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define CLB_XBAR_CLBXBARG3SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define CLB_XBAR_CLBXBARG3SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define CLB_XBAR_CLBXBARG3SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define CLB_XBAR_CLBXBARG3SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define CLB_XBAR_CLBXBARG3SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define CLB_XBAR_CLBXBARG3SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define CLB_XBAR_CLBXBARG3SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define CLB_XBAR_CLBXBARG3SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARG4SEL register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARG4SEL_INPUT0    0x1U          // Select bit for INPUT0
#define CLB_XBAR_CLBXBARG4SEL_INPUT1    0x2U          // Select bit for INPUT1
#define CLB_XBAR_CLBXBARG4SEL_INPUT2    0x4U          // Select bit for INPUT2
#define CLB_XBAR_CLBXBARG4SEL_INPUT3    0x8U          // Select bit for INPUT3
#define CLB_XBAR_CLBXBARG4SEL_INPUT4    0x10U         // Select bit for INPUT4
#define CLB_XBAR_CLBXBARG4SEL_INPUT5    0x20U         // Select bit for INPUT5
#define CLB_XBAR_CLBXBARG4SEL_INPUT6    0x40U         // Select bit for INPUT6
#define CLB_XBAR_CLBXBARG4SEL_INPUT7    0x80U         // Select bit for INPUT7
#define CLB_XBAR_CLBXBARG4SEL_INPUT8    0x100U        // Select bit for INPUT8
#define CLB_XBAR_CLBXBARG4SEL_INPUT9    0x200U        // Select bit for INPUT9
#define CLB_XBAR_CLBXBARG4SEL_INPUT10   0x400U        // Select bit for INPUT10
#define CLB_XBAR_CLBXBARG4SEL_INPUT11   0x800U        // Select bit for INPUT11
#define CLB_XBAR_CLBXBARG4SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define CLB_XBAR_CLBXBARG4SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define CLB_XBAR_CLBXBARG4SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define CLB_XBAR_CLBXBARG4SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define CLB_XBAR_CLBXBARG4SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define CLB_XBAR_CLBXBARG4SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define CLB_XBAR_CLBXBARG4SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define CLB_XBAR_CLBXBARG4SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define CLB_XBAR_CLBXBARG4SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define CLB_XBAR_CLBXBARG4SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define CLB_XBAR_CLBXBARG4SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define CLB_XBAR_CLBXBARG4SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define CLB_XBAR_CLBXBARG4SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define CLB_XBAR_CLBXBARG4SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define CLB_XBAR_CLBXBARG4SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define CLB_XBAR_CLBXBARG4SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define CLB_XBAR_CLBXBARG4SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define CLB_XBAR_CLBXBARG4SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define CLB_XBAR_CLBXBARG4SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define CLB_XBAR_CLBXBARG4SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARG5SEL register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARG5SEL_INPUT0    0x1U          // Select bit for INPUT0
#define CLB_XBAR_CLBXBARG5SEL_INPUT1    0x2U          // Select bit for INPUT1
#define CLB_XBAR_CLBXBARG5SEL_INPUT2    0x4U          // Select bit for INPUT2
#define CLB_XBAR_CLBXBARG5SEL_INPUT3    0x8U          // Select bit for INPUT3
#define CLB_XBAR_CLBXBARG5SEL_INPUT4    0x10U         // Select bit for INPUT4
#define CLB_XBAR_CLBXBARG5SEL_INPUT5    0x20U         // Select bit for INPUT5
#define CLB_XBAR_CLBXBARG5SEL_INPUT6    0x40U         // Select bit for INPUT6
#define CLB_XBAR_CLBXBARG5SEL_INPUT7    0x80U         // Select bit for INPUT7
#define CLB_XBAR_CLBXBARG5SEL_INPUT8    0x100U        // Select bit for INPUT8
#define CLB_XBAR_CLBXBARG5SEL_INPUT9    0x200U        // Select bit for INPUT9
#define CLB_XBAR_CLBXBARG5SEL_INPUT10   0x400U        // Select bit for INPUT10
#define CLB_XBAR_CLBXBARG5SEL_INPUT11   0x800U        // Select bit for INPUT11
#define CLB_XBAR_CLBXBARG5SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define CLB_XBAR_CLBXBARG5SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define CLB_XBAR_CLBXBARG5SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define CLB_XBAR_CLBXBARG5SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define CLB_XBAR_CLBXBARG5SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define CLB_XBAR_CLBXBARG5SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define CLB_XBAR_CLBXBARG5SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define CLB_XBAR_CLBXBARG5SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define CLB_XBAR_CLBXBARG5SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define CLB_XBAR_CLBXBARG5SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define CLB_XBAR_CLBXBARG5SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define CLB_XBAR_CLBXBARG5SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define CLB_XBAR_CLBXBARG5SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define CLB_XBAR_CLBXBARG5SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define CLB_XBAR_CLBXBARG5SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define CLB_XBAR_CLBXBARG5SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define CLB_XBAR_CLBXBARG5SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define CLB_XBAR_CLBXBARG5SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define CLB_XBAR_CLBXBARG5SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define CLB_XBAR_CLBXBARG5SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARG6SEL register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARG6SEL_INPUT0    0x1U          // Select bit for INPUT0
#define CLB_XBAR_CLBXBARG6SEL_INPUT1    0x2U          // Select bit for INPUT1
#define CLB_XBAR_CLBXBARG6SEL_INPUT2    0x4U          // Select bit for INPUT2
#define CLB_XBAR_CLBXBARG6SEL_INPUT3    0x8U          // Select bit for INPUT3
#define CLB_XBAR_CLBXBARG6SEL_INPUT4    0x10U         // Select bit for INPUT4
#define CLB_XBAR_CLBXBARG6SEL_INPUT5    0x20U         // Select bit for INPUT5
#define CLB_XBAR_CLBXBARG6SEL_INPUT6    0x40U         // Select bit for INPUT6
#define CLB_XBAR_CLBXBARG6SEL_INPUT7    0x80U         // Select bit for INPUT7
#define CLB_XBAR_CLBXBARG6SEL_INPUT8    0x100U        // Select bit for INPUT8
#define CLB_XBAR_CLBXBARG6SEL_INPUT9    0x200U        // Select bit for INPUT9
#define CLB_XBAR_CLBXBARG6SEL_INPUT10   0x400U        // Select bit for INPUT10
#define CLB_XBAR_CLBXBARG6SEL_INPUT11   0x800U        // Select bit for INPUT11
#define CLB_XBAR_CLBXBARG6SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define CLB_XBAR_CLBXBARG6SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define CLB_XBAR_CLBXBARG6SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define CLB_XBAR_CLBXBARG6SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define CLB_XBAR_CLBXBARG6SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define CLB_XBAR_CLBXBARG6SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define CLB_XBAR_CLBXBARG6SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define CLB_XBAR_CLBXBARG6SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define CLB_XBAR_CLBXBARG6SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define CLB_XBAR_CLBXBARG6SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define CLB_XBAR_CLBXBARG6SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define CLB_XBAR_CLBXBARG6SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define CLB_XBAR_CLBXBARG6SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define CLB_XBAR_CLBXBARG6SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define CLB_XBAR_CLBXBARG6SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define CLB_XBAR_CLBXBARG6SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define CLB_XBAR_CLBXBARG6SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define CLB_XBAR_CLBXBARG6SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define CLB_XBAR_CLBXBARG6SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define CLB_XBAR_CLBXBARG6SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBXBARG7SEL register
//
//*************************************************************************************************
#define CLB_XBAR_CLBXBARG7SEL_INPUT0    0x1U          // Select bit for INPUT0
#define CLB_XBAR_CLBXBARG7SEL_INPUT1    0x2U          // Select bit for INPUT1
#define CLB_XBAR_CLBXBARG7SEL_INPUT2    0x4U          // Select bit for INPUT2
#define CLB_XBAR_CLBXBARG7SEL_INPUT3    0x8U          // Select bit for INPUT3
#define CLB_XBAR_CLBXBARG7SEL_INPUT4    0x10U         // Select bit for INPUT4
#define CLB_XBAR_CLBXBARG7SEL_INPUT5    0x20U         // Select bit for INPUT5
#define CLB_XBAR_CLBXBARG7SEL_INPUT6    0x40U         // Select bit for INPUT6
#define CLB_XBAR_CLBXBARG7SEL_INPUT7    0x80U         // Select bit for INPUT7
#define CLB_XBAR_CLBXBARG7SEL_INPUT8    0x100U        // Select bit for INPUT8
#define CLB_XBAR_CLBXBARG7SEL_INPUT9    0x200U        // Select bit for INPUT9
#define CLB_XBAR_CLBXBARG7SEL_INPUT10   0x400U        // Select bit for INPUT10
#define CLB_XBAR_CLBXBARG7SEL_INPUT11   0x800U        // Select bit for INPUT11
#define CLB_XBAR_CLBXBARG7SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define CLB_XBAR_CLBXBARG7SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define CLB_XBAR_CLBXBARG7SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define CLB_XBAR_CLBXBARG7SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define CLB_XBAR_CLBXBARG7SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define CLB_XBAR_CLBXBARG7SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define CLB_XBAR_CLBXBARG7SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define CLB_XBAR_CLBXBARG7SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define CLB_XBAR_CLBXBARG7SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define CLB_XBAR_CLBXBARG7SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define CLB_XBAR_CLBXBARG7SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define CLB_XBAR_CLBXBARG7SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define CLB_XBAR_CLBXBARG7SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define CLB_XBAR_CLBXBARG7SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define CLB_XBAR_CLBXBARG7SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define CLB_XBAR_CLBXBARG7SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define CLB_XBAR_CLBXBARG7SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define CLB_XBAR_CLBXBARG7SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define CLB_XBAR_CLBXBARG7SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define CLB_XBAR_CLBXBARG7SEL_INPUT31   0x80000000U   // Select bit for INPUT31



#endif
