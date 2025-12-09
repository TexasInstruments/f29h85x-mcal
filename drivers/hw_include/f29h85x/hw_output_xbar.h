//###########################################################################
//
// FILE:    hw_output_xbar.h
//
// TITLE:   Definitions for the OUTPUT_XBAR registers.
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

#ifndef HW_OUTPUT_XBAR_H
#define HW_OUTPUT_XBAR_H

//*************************************************************************************************
//
// The following are defines for the OUTPUT_XBAR register offsets
//
//*************************************************************************************************
#define OUTPUT_XBAR_O_OUTPUTXBARSTATUS      0x10U   // Output Signal Status register
#define OUTPUT_XBAR_O_OUTPUTXBARFLAG        0x18U   // Output latched flag register
#define OUTPUT_XBAR_O_OUTPUTXBARFLAGCLEAR   0x1CU   // Output latched flag clear register
#define OUTPUT_XBAR_O_OUTPUTXBARFLAGFORCE   0x20U   // Output latched flag Force register

#define OUTPUT_XBAR_O_OUTPUTXBARFLAGINVERT   0x14U                    // Output Signal inversion
                                                                      // register
#define OUTPUT_XBAR_O_OUTPUTXBAROUTLATCH     0x24U                    // Output Signal Select Latch
#define OUTPUT_XBAR_O_OUTPUTXBAROUTSTRETCH   0x28U                    // Output Signal Stretched
                                                                      // Pulse Version Select
#define OUTPUT_XBAR_O_OUTPUTXBAROUTLENGTH    0x2CU                    // Output Signal Stretched
                                                                      // Pulse Length Select
#define OUTPUT_XBAR_O_OUTPUTXBAROUTINVERT    0x30U                    // Output Signal Invert
                                                                      // Select
#define OUTPUT_XBAR_O_OUTPUTXBARLOCK         0x80U                    // Configuration Lock
                                                                      // register
#define OUTPUT_XBAR_O_OUTPUTXBARG0SEL(i)     (0x100U + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G0 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG1SEL(i)     (0x104U + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G1 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG2SEL(i)     (0x108U + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G2 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG3SEL(i)     (0x10CU + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G3 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG4SEL(i)     (0x110U + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G4 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG5SEL(i)     (0x114U + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G5 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG6SEL(i)     (0x118U + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G6 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG7SEL(i)     (0x11CU + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G7 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG8SEL(i)     (0x120U + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G8 Input Select
#define OUTPUT_XBAR_O_OUTPUTXBARG9SEL(i)     (0x124U + ((i) * 64U))   // (0 <= i < 16) OUTPUTXBAR
                                                                      // G9 Input Select


//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARStatus register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARSTATUS_STS   0x1U   // Output Signal Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARFlag register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARFLAG_FLG   0x1U   // Output Signal Latched Flag Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARFlagClear register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARFLAGCLEAR_FLG   0x1U   // Output Signal Latched Flag Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARFlagForce register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARFLAGFORCE_FLG   0x1U   // Output Signal Latched Flag Force


//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARFlagInvert register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR1    0x1U      // Invert XBAR Output Before Latch for
                                                            // XBAR1
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR2    0x2U      // Invert XBAR Output Before Latch for
                                                            // XBAR2
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR3    0x4U      // Invert XBAR Output Before Latch for
                                                            // XBAR3
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR4    0x8U      // Invert XBAR Output Before Latch for
                                                            // XBAR4
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR5    0x10U     // Invert XBAR Output Before Latch for
                                                            // XBAR5
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR6    0x20U     // Invert XBAR Output Before Latch for
                                                            // XBAR6
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR7    0x40U     // Invert XBAR Output Before Latch for
                                                            // XBAR7
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR8    0x80U     // Invert XBAR Output Before Latch for
                                                            // XBAR8
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR9    0x100U    // Invert XBAR Output Before Latch for
                                                            // XBAR9
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR10   0x200U    // Invert XBAR Output Before Latch for
                                                            // XBAR10
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR11   0x400U    // Invert XBAR Output Before Latch for
                                                            // XBAR11
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR12   0x800U    // Invert XBAR Output Before Latch for
                                                            // XBAR12
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR13   0x1000U   // Invert XBAR Output Before Latch for
                                                            // XBAR13
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR14   0x2000U   // Invert XBAR Output Before Latch for
                                                            // XBAR14
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR15   0x4000U   // Invert XBAR Output Before Latch for
                                                            // XBAR15
#define OUTPUT_XBAR_OUTPUTXBARFLAGINVERT_XBAR16   0x8000U   // Invert XBAR Output Before Latch for
                                                            // XBAR16

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBAROutLatch register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR1    0x1U      // XBAR Output Latch Select for XBAR1
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR2    0x2U      // XBAR Output Latch Select for XBAR2
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR3    0x4U      // XBAR Output Latch Select for XBAR3
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR4    0x8U      // XBAR Output Latch Select for XBAR4
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR5    0x10U     // XBAR Output Latch Select for XBAR5
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR6    0x20U     // XBAR Output Latch Select for XBAR6
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR7    0x40U     // XBAR Output Latch Select for XBAR7
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR8    0x80U     // XBAR Output Latch Select for XBAR8
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR9    0x100U    // XBAR Output Latch Select for XBAR9
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR10   0x200U    // XBAR Output Latch Select for XBAR10
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR11   0x400U    // XBAR Output Latch Select for XBAR11
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR12   0x800U    // XBAR Output Latch Select for XBAR12
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR13   0x1000U   // XBAR Output Latch Select for XBAR13
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR14   0x2000U   // XBAR Output Latch Select for XBAR14
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR15   0x4000U   // XBAR Output Latch Select for XBAR15
#define OUTPUT_XBAR_OUTPUTXBAROUTLATCH_XBAR16   0x8000U   // XBAR Output Latch Select for XBAR16

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBAROutStretch register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR1    0x1U      // XBAR Output Stretch Select for XBAR1
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR2    0x2U      // XBAR Output Stretch Select for XBAR2
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR3    0x4U      // XBAR Output Stretch Select for XBAR3
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR4    0x8U      // XBAR Output Stretch Select for XBAR4
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR5    0x10U     // XBAR Output Stretch Select for XBAR5
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR6    0x20U     // XBAR Output Stretch Select for XBAR6
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR7    0x40U     // XBAR Output Stretch Select for XBAR7
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR8    0x80U     // XBAR Output Stretch Select for XBAR8
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR9    0x100U    // XBAR Output Stretch Select for XBAR9
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR10   0x200U    // XBAR Output Stretch Select for
                                                            // XBAR10
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR11   0x400U    // XBAR Output Stretch Select for
                                                            // XBAR11
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR12   0x800U    // XBAR Output Stretch Select for
                                                            // XBAR12
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR13   0x1000U   // XBAR Output Stretch Select for
                                                            // XBAR13
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR14   0x2000U   // XBAR Output Stretch Select for
                                                            // XBAR14
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR15   0x4000U   // XBAR Output Stretch Select for
                                                            // XBAR15
#define OUTPUT_XBAR_OUTPUTXBAROUTSTRETCH_XBAR16   0x8000U   // XBAR Output Stretch Select for
                                                            // XBAR16

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBAROutLength register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR1    0x1U      // XBAR Output Stretch Length Select for
                                                           // XBAR1
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR2    0x2U      // XBAR Output Stretch Length Select for
                                                           // XBAR2
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR3    0x4U      // XBAR Output Stretch Length Select for
                                                           // XBAR3
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR4    0x8U      // XBAR Output Stretch Length Select for
                                                           // XBAR4
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR5    0x10U     // XBAR Output Stretch Length Select for
                                                           // XBAR5
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR6    0x20U     // XBAR Output Stretch Length Select for
                                                           // XBAR6
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR7    0x40U     // XBAR Output Stretch Length Select for
                                                           // XBAR7
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR8    0x80U     // XBAR Output Stretch Length Select for
                                                           // XBAR8
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR9    0x100U    // XBAR Output Stretch Length Select for
                                                           // XBAR9
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR10   0x200U    // XBAR Output Stretch Length Select for
                                                           // XBAR10
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR11   0x400U    // XBAR Output Stretch Length Select for
                                                           // XBAR11
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR12   0x800U    // XBAR Output Stretch Length Select for
                                                           // XBAR12
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR13   0x1000U   // XBAR Output Stretch Length Select for
                                                           // XBAR13
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR14   0x2000U   // XBAR Output Stretch Length Select for
                                                           // XBAR14
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR15   0x4000U   // XBAR Output Stretch Length Select for
                                                           // XBAR15
#define OUTPUT_XBAR_OUTPUTXBAROUTLENGTH_XBAR16   0x8000U   // XBAR Output Stretch Length Select for
                                                           // XBAR16

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBAROutInvert register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR1    0x1U      // Invert XBAR Output for XBAR1
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR2    0x2U      // Invert XBAR Output for XBAR2
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR3    0x4U      // Invert XBAR Output for XBAR3
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR4    0x8U      // Invert XBAR Output for XBAR4
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR5    0x10U     // Invert XBAR Output for XBAR5
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR6    0x20U     // Invert XBAR Output for XBAR6
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR7    0x40U     // Invert XBAR Output for XBAR7
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR8    0x80U     // Invert XBAR Output for XBAR8
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR9    0x100U    // Invert XBAR Output for XBAR9
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR10   0x200U    // Invert XBAR Output for XBAR10
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR11   0x400U    // Invert XBAR Output for XBAR11
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR12   0x800U    // Invert XBAR Output for XBAR12
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR13   0x1000U   // Invert XBAR Output for XBAR13
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR14   0x2000U   // Invert XBAR Output for XBAR14
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR15   0x4000U   // Invert XBAR Output for XBAR15
#define OUTPUT_XBAR_OUTPUTXBAROUTINVERT_XBAR16   0x8000U   // Invert XBAR Output for XBAR16

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARLock register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARLOCK_LOCK    0x1U          // Locks the configuration for
                                                         // EOUTPUT-XBAR
#define OUTPUT_XBAR_OUTPUTXBARLOCK_KEY_S   16U
#define OUTPUT_XBAR_OUTPUTXBARLOCK_KEY_M   0xFFFF0000U   // Write protection KEY

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG0SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG0SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG1SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG1SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG2SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG2SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG3SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG3SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG4SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG4SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG5SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG5SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG6SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG6SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG7SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG7SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG8SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG8SEL_INPUT31   0x80000000U   // Select bit for INPUT31

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARG9SEL register
//
//*************************************************************************************************
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT0    0x1U          // Select bit for INPUT0
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT1    0x2U          // Select bit for INPUT1
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT2    0x4U          // Select bit for INPUT2
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT3    0x8U          // Select bit for INPUT3
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT4    0x10U         // Select bit for INPUT4
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT5    0x20U         // Select bit for INPUT5
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT6    0x40U         // Select bit for INPUT6
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT7    0x80U         // Select bit for INPUT7
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT8    0x100U        // Select bit for INPUT8
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT9    0x200U        // Select bit for INPUT9
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT10   0x400U        // Select bit for INPUT10
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT11   0x800U        // Select bit for INPUT11
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT12   0x1000U       // Select bit for INPUT12
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT13   0x2000U       // Select bit for INPUT13
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT14   0x4000U       // Select bit for INPUT14
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT15   0x8000U       // Select bit for INPUT15
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT16   0x10000U      // Select bit for INPUT16
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT17   0x20000U      // Select bit for INPUT17
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT18   0x40000U      // Select bit for INPUT18
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT19   0x80000U      // Select bit for INPUT19
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT20   0x100000U     // Select bit for INPUT20
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT21   0x200000U     // Select bit for INPUT21
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT22   0x400000U     // Select bit for INPUT22
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT23   0x800000U     // Select bit for INPUT23
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT24   0x1000000U    // Select bit for INPUT24
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT25   0x2000000U    // Select bit for INPUT25
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT26   0x4000000U    // Select bit for INPUT26
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT27   0x8000000U    // Select bit for INPUT27
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT28   0x10000000U   // Select bit for INPUT28
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT29   0x20000000U   // Select bit for INPUT29
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT30   0x40000000U   // Select bit for INPUT30
#define OUTPUT_XBAR_OUTPUTXBARG9SEL_INPUT31   0x80000000U   // Select bit for INPUT31



#endif
