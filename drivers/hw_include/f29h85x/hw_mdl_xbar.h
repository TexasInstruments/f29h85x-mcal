//###########################################################################
//
// FILE:    hw_mdl_xbar.h
//
// TITLE:   Definitions for the MDL_XBAR registers.
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

#ifndef HW_MDL_XBAR_H
#define HW_MDL_XBAR_H

//*************************************************************************************************
//
// The following are defines for the MDL_XBAR register offsets
//
//*************************************************************************************************
#define MDL_XBAR_O_MDLXBAROUTINVERT   0x30U                    // Output Signal Invert Select
#define MDL_XBAR_O_MDLXBARLOCK        0x80U                    // Configuration Lock register
#define MDL_XBAR_O_MDLXBARG0SEL(i)    (0x100U + ((i) * 64U))   // (0 <= i < 16) MDLXBAR G0 Input
                                                               // Select
#define MDL_XBAR_O_MDLXBARG1SEL(i)    (0x104U + ((i) * 64U))   // (0 <= i < 16) MDLXBAR G1 Input
                                                               // Select
#define MDL_XBAR_O_MDLXBARG2SEL(i)    (0x108U + ((i) * 64U))   // (0 <= i < 16) MDLXBAR G2 Input
                                                               // Select


//*************************************************************************************************
//
// The following are defines for the bit fields in the MDLXBAROutInvert register
//
//*************************************************************************************************
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR1    0x1U      // Invert XBAR Output Select for XBAR1
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR2    0x2U      // Invert XBAR Output Select for XBAR2
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR3    0x4U      // Invert XBAR Output Select for XBAR3
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR4    0x8U      // Invert XBAR Output Select for XBAR4
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR5    0x10U     // Invert XBAR Output Select for XBAR5
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR6    0x20U     // Invert XBAR Output Select for XBAR6
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR7    0x40U     // Invert XBAR Output Select for XBAR7
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR8    0x80U     // Invert XBAR Output Select for XBAR8
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR9    0x100U    // Invert XBAR Output Select for XBAR9
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR10   0x200U    // Invert XBAR Output Select for XBAR10
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR11   0x400U    // Invert XBAR Output Select for XBAR11
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR12   0x800U    // Invert XBAR Output Select for XBAR12
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR13   0x1000U   // Invert XBAR Output Select for XBAR13
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR14   0x2000U   // Invert XBAR Output Select for XBAR14
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR15   0x4000U   // Invert XBAR Output Select for XBAR15
#define MDL_XBAR_MDLXBAROUTINVERT_XBAR16   0x8000U   // Invert XBAR Output Select for XBAR16

//*************************************************************************************************
//
// The following are defines for the bit fields in the MDLXBARLock register
//
//*************************************************************************************************
#define MDL_XBAR_MDLXBARLOCK_LOCK    0x1U          // Locks the configuration for EMDL-XBAR
#define MDL_XBAR_MDLXBARLOCK_KEY_S   16U
#define MDL_XBAR_MDLXBARLOCK_KEY_M   0xFFFF0000U   // Write protection KEY

//*************************************************************************************************
//
// The following are defines for the bit fields in the MDLXBARG0SEL register
//
//*************************************************************************************************
#define MDL_XBAR_MDLXBARG0SEL_INPUT0    0x1U          // Select bit for INPUT0
#define MDL_XBAR_MDLXBARG0SEL_INPUT1    0x2U          // Select bit for INPUT1
#define MDL_XBAR_MDLXBARG0SEL_INPUT2    0x4U          // Select bit for INPUT2
#define MDL_XBAR_MDLXBARG0SEL_INPUT3    0x8U          // Select bit for INPUT3
#define MDL_XBAR_MDLXBARG0SEL_INPUT4    0x10U         // Select bit for INPUT4
#define MDL_XBAR_MDLXBARG0SEL_INPUT5    0x20U         // Select bit for INPUT5
#define MDL_XBAR_MDLXBARG0SEL_INPUT6    0x40U         // Select bit for INPUT6
#define MDL_XBAR_MDLXBARG0SEL_INPUT7    0x80U         // Select bit for INPUT7
#define MDL_XBAR_MDLXBARG0SEL_INPUT8    0x100U        // Select bit for INPUT8
#define MDL_XBAR_MDLXBARG0SEL_INPUT9    0x200U        // Select bit for INPUT9
#define MDL_XBAR_MDLXBARG0SEL_INPUT10   0x400U        // Select bit for INPUT10
#define MDL_XBAR_MDLXBARG0SEL_INPUT11   0x800U        // Select bit for INPUT11
#define MDL_XBAR_MDLXBARG0SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define MDL_XBAR_MDLXBARG0SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define MDL_XBAR_MDLXBARG0SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define MDL_XBAR_MDLXBARG0SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define MDL_XBAR_MDLXBARG0SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define MDL_XBAR_MDLXBARG0SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define MDL_XBAR_MDLXBARG0SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define MDL_XBAR_MDLXBARG0SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define MDL_XBAR_MDLXBARG0SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define MDL_XBAR_MDLXBARG0SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define MDL_XBAR_MDLXBARG0SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define MDL_XBAR_MDLXBARG0SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define MDL_XBAR_MDLXBARG0SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define MDL_XBAR_MDLXBARG0SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define MDL_XBAR_MDLXBARG0SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define MDL_XBAR_MDLXBARG0SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define MDL_XBAR_MDLXBARG0SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define MDL_XBAR_MDLXBARG0SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define MDL_XBAR_MDLXBARG0SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define MDL_XBAR_MDLXBARG0SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the MDLXBARG1SEL register
//
//*************************************************************************************************
#define MDL_XBAR_MDLXBARG1SEL_INPUT0    0x1U          // Select bit for INPUT0
#define MDL_XBAR_MDLXBARG1SEL_INPUT1    0x2U          // Select bit for INPUT1
#define MDL_XBAR_MDLXBARG1SEL_INPUT2    0x4U          // Select bit for INPUT2
#define MDL_XBAR_MDLXBARG1SEL_INPUT3    0x8U          // Select bit for INPUT3
#define MDL_XBAR_MDLXBARG1SEL_INPUT4    0x10U         // Select bit for INPUT4
#define MDL_XBAR_MDLXBARG1SEL_INPUT5    0x20U         // Select bit for INPUT5
#define MDL_XBAR_MDLXBARG1SEL_INPUT6    0x40U         // Select bit for INPUT6
#define MDL_XBAR_MDLXBARG1SEL_INPUT7    0x80U         // Select bit for INPUT7
#define MDL_XBAR_MDLXBARG1SEL_INPUT8    0x100U        // Select bit for INPUT8
#define MDL_XBAR_MDLXBARG1SEL_INPUT9    0x200U        // Select bit for INPUT9
#define MDL_XBAR_MDLXBARG1SEL_INPUT10   0x400U        // Select bit for INPUT10
#define MDL_XBAR_MDLXBARG1SEL_INPUT11   0x800U        // Select bit for INPUT11
#define MDL_XBAR_MDLXBARG1SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define MDL_XBAR_MDLXBARG1SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define MDL_XBAR_MDLXBARG1SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define MDL_XBAR_MDLXBARG1SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define MDL_XBAR_MDLXBARG1SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define MDL_XBAR_MDLXBARG1SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define MDL_XBAR_MDLXBARG1SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define MDL_XBAR_MDLXBARG1SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define MDL_XBAR_MDLXBARG1SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define MDL_XBAR_MDLXBARG1SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define MDL_XBAR_MDLXBARG1SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define MDL_XBAR_MDLXBARG1SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define MDL_XBAR_MDLXBARG1SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define MDL_XBAR_MDLXBARG1SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define MDL_XBAR_MDLXBARG1SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define MDL_XBAR_MDLXBARG1SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define MDL_XBAR_MDLXBARG1SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define MDL_XBAR_MDLXBARG1SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define MDL_XBAR_MDLXBARG1SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define MDL_XBAR_MDLXBARG1SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the MDLXBARG2SEL register
//
//*************************************************************************************************
#define MDL_XBAR_MDLXBARG2SEL_INPUT0    0x1U          // Select bit for INPUT0
#define MDL_XBAR_MDLXBARG2SEL_INPUT1    0x2U          // Select bit for INPUT1
#define MDL_XBAR_MDLXBARG2SEL_INPUT2    0x4U          // Select bit for INPUT2
#define MDL_XBAR_MDLXBARG2SEL_INPUT3    0x8U          // Select bit for INPUT3
#define MDL_XBAR_MDLXBARG2SEL_INPUT4    0x10U         // Select bit for INPUT4
#define MDL_XBAR_MDLXBARG2SEL_INPUT5    0x20U         // Select bit for INPUT5
#define MDL_XBAR_MDLXBARG2SEL_INPUT6    0x40U         // Select bit for INPUT6
#define MDL_XBAR_MDLXBARG2SEL_INPUT7    0x80U         // Select bit for INPUT7
#define MDL_XBAR_MDLXBARG2SEL_INPUT8    0x100U        // Select bit for INPUT8
#define MDL_XBAR_MDLXBARG2SEL_INPUT9    0x200U        // Select bit for INPUT9
#define MDL_XBAR_MDLXBARG2SEL_INPUT10   0x400U        // Select bit for INPUT10
#define MDL_XBAR_MDLXBARG2SEL_INPUT11   0x800U        // Select bit for INPUT11
#define MDL_XBAR_MDLXBARG2SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define MDL_XBAR_MDLXBARG2SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define MDL_XBAR_MDLXBARG2SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define MDL_XBAR_MDLXBARG2SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define MDL_XBAR_MDLXBARG2SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define MDL_XBAR_MDLXBARG2SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define MDL_XBAR_MDLXBARG2SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define MDL_XBAR_MDLXBARG2SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define MDL_XBAR_MDLXBARG2SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define MDL_XBAR_MDLXBARG2SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define MDL_XBAR_MDLXBARG2SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define MDL_XBAR_MDLXBARG2SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define MDL_XBAR_MDLXBARG2SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define MDL_XBAR_MDLXBARG2SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define MDL_XBAR_MDLXBARG2SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define MDL_XBAR_MDLXBARG2SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define MDL_XBAR_MDLXBARG2SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define MDL_XBAR_MDLXBARG2SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define MDL_XBAR_MDLXBARG2SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define MDL_XBAR_MDLXBARG2SEL_INPUT31   0x80000000U   // Select bit for INPUT31



#endif
