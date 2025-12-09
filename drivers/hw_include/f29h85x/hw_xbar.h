//###########################################################################
//
// FILE:    hw_xbar.h
//
// TITLE:   Definitions for the XBAR registers.
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

#ifndef HW_XBAR_H
#define HW_XBAR_H

//*************************************************************************************************
//
// The following are defines for the XBAR register offsets
//
//*************************************************************************************************
#define XBAR_O_FLG1    0x0U     // X-Bar Input Flag Register 1
#define XBAR_O_FLG2    0x4U     // X-Bar Input Flag Register 2
#define XBAR_O_FLG3    0x8U     // X-Bar Input Flag Register 3
#define XBAR_O_FLG4    0xCU     // X-Bar Input Flag Register 4
#define XBAR_O_FLG5    0x10U    // X-Bar Input Flag Register 5
#define XBAR_O_FLG6    0x14U    // X-Bar Input Flag Register 6
#define XBAR_O_FLG7    0x18U    // X-Bar Input Flag Register 7
#define XBAR_O_FLG8    0x1CU    // X-Bar Input Flag Register 8
#define XBAR_O_FLG9    0x20U    // X-Bar Input Flag Register 9
#define XBAR_O_FLG10   0x24U    // X-Bar Input Flag Register 10
#define XBAR_O_FLG11   0x28U    // X-Bar Input Flag Register 11
#define XBAR_O_FLG12   0x2CU    // X-Bar Input Flag Register 12
#define XBAR_O_FLG13   0x30U    // X-Bar Input Flag Register 13
#define XBAR_O_FLG14   0x34U    // X-Bar Input Flag Register 14
#define XBAR_O_FLG15   0x38U    // X-Bar Input Flag Register 15
#define XBAR_O_FLG16   0x3CU    // X-Bar Input Flag Register 16
#define XBAR_O_FLG17   0x40U    // X-Bar Input Flag Register 16
#define XBAR_O_FLG18   0x44U    // X-Bar Input Flag Register 16
#define XBAR_O_CLR1    0x100U   // X-Bar Input Flag Clear Register 1
#define XBAR_O_CLR2    0x104U   // X-Bar Input Flag Clear Register 2
#define XBAR_O_CLR3    0x108U   // X-Bar Input Flag Clear Register 3
#define XBAR_O_CLR4    0x10CU   // X-Bar Input Flag Clear Register 4
#define XBAR_O_CLR5    0x110U   // X-Bar Input Flag Clear Register 5
#define XBAR_O_CLR6    0x114U   // X-Bar Input Flag Clear Register 6
#define XBAR_O_CLR7    0x118U   // X-Bar Input Flag Clear Register 7
#define XBAR_O_CLR8    0x11CU   // X-Bar Input Flag Clear Register 8
#define XBAR_O_CLR9    0x120U   // X-Bar Input Flag Clear Register 9
#define XBAR_O_CLR10   0x124U   // X-Bar Input Flag Clear Register 10
#define XBAR_O_CLR11   0x128U   // X-Bar Input Flag Clear Register 11
#define XBAR_O_CLR12   0x12CU   // X-Bar Input Flag Clear Register 12
#define XBAR_O_CLR13   0x130U   // X-Bar Input Flag Clear Register 13
#define XBAR_O_CLR14   0x134U   // X-Bar Input Flag Clear Register 14
#define XBAR_O_CLR15   0x138U   // X-Bar Input Flag Clear Register 15
#define XBAR_O_CLR16   0x13CU   // X-Bar Input Flag Clear Register 15
#define XBAR_O_CLR17   0x140U   // X-Bar Input Flag Clear Register 16
#define XBAR_O_CLR18   0x144U   // X-Bar Input Flag Clear Register 16


//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG1 register
//
//*************************************************************************************************
#define XBAR_FLG1_CMPSS1_CTRIPL    0x1U        // Input Flag for CMPSS1_CTRIPL Signal
#define XBAR_FLG1_CMPSS1_CTRIPH    0x2U        // Input Flag for CMPSS1_CTRIPH Signal
#define XBAR_FLG1_CMPSS2_CTRIPL    0x4U        // Input Flag for CMPSS2_CTRIPL Signal
#define XBAR_FLG1_CMPSS2_CTRIPH    0x8U        // Input Flag for CMPSS2_CTRIPH Signal
#define XBAR_FLG1_CMPSS3_CTRIPL    0x10U       // Input Flag for CMPSS3_CTRIPL Signal
#define XBAR_FLG1_CMPSS3_CTRIPH    0x20U       // Input Flag for CMPSS3_CTRIPH Signal
#define XBAR_FLG1_CMPSS4_CTRIPL    0x40U       // Input Flag for CMPSS4_CTRIPL Signal
#define XBAR_FLG1_CMPSS4_CTRIPH    0x80U       // Input Flag for CMPSS4_CTRIPH Signal
#define XBAR_FLG1_CMPSS5_CTRIPL    0x100U      // Input Flag for CMPSS5_CTRIPL Signal
#define XBAR_FLG1_CMPSS5_CTRIPH    0x200U      // Input Flag for CMPSS5_CTRIPH Signal
#define XBAR_FLG1_CMPSS6_CTRIPL    0x400U      // Input Flag for CMPSS6_CTRIPL Signal
#define XBAR_FLG1_CMPSS6_CTRIPH    0x800U      // Input Flag for CMPSS6_CTRIPH Signal
#define XBAR_FLG1_CMPSS7_CTRIPL    0x1000U     // Input Flag for CMPSS7_CTRIPL Signal
#define XBAR_FLG1_CMPSS7_CTRIPH    0x2000U     // Input Flag for CMPSS7_CTRIPH Signal
#define XBAR_FLG1_CMPSS8_CTRIPL    0x4000U     // Input Flag for CMPSS8_CTRIPL Signal
#define XBAR_FLG1_CMPSS8_CTRIPH    0x8000U     // Input Flag for CMPSS8_CTRIPH Signal
#define XBAR_FLG1_CMPSS9_CTRIPH    0x10000U    // Input Flag for CMPSS9_CTRIPH Signal
#define XBAR_FLG1_CMPSS9_CTRIPL    0x20000U    // Input Flag for CMPSS9_CTRIPL Signal
#define XBAR_FLG1_CMPSS10_CTRIPH   0x40000U    // Input Flag for CMPSS10_CTRIPH Signal
#define XBAR_FLG1_CMPSS10_CTRIPL   0x80000U    // Input Flag for CMPSS10_CTRIPL Signal
#define XBAR_FLG1_CMPSS11_CTRIPH   0x100000U   // Input Flag for CMPSS11_CTRIPH Signal
#define XBAR_FLG1_CMPSS11_CTRIPL   0x200000U   // Input Flag for CMPSS11_CTRIPL Signal
#define XBAR_FLG1_CMPSS12_CTRIPH   0x400000U   // Input Flag for CMPSS12_CTRIPH Signal
#define XBAR_FLG1_CMPSS12_CTRIPL   0x800000U   // Input Flag for CMPSS12_CTRIPL Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG2 register
//
//*************************************************************************************************
#define XBAR_FLG2_CMPSS1_CTRIPOUTL    0x1U        // Input Flag for CMPSS1_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS1_CTRIPOUTH    0x2U        // Input Flag for CMPSS1_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS2_CTRIPOUTL    0x4U        // Input Flag for CMPSS2_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS2_CTRIPOUTH    0x8U        // Input Flag for CMPSS2_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS3_CTRIPOUTL    0x10U       // Input Flag for CMPSS3_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS3_CTRIPOUTH    0x20U       // Input Flag for CMPSS3_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS4_CTRIPOUTL    0x40U       // Input Flag for CMPSS4_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS4_CTRIPOUTH    0x80U       // Input Flag for CMPSS4_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS5_CTRIPOUTL    0x100U      // Input Flag for CMPSS5_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS5_CTRIPOUTH    0x200U      // Input Flag for CMPSS5_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS6_CTRIPOUTL    0x400U      // Input Flag for CMPSS6_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS6_CTRIPOUTH    0x800U      // Input Flag for CMPSS6_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS7_CTRIPOUTL    0x1000U     // Input Flag for CMPSS7_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS7_CTRIPOUTH    0x2000U     // Input Flag for CMPSS7_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS8_CTRIPOUTL    0x4000U     // Input Flag for CMPSS8_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS8_CTRIPOUTH    0x8000U     // Input Flag for CMPSS8_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS9_CTRIPOUTH    0x10000U    // Input Flag for CMPSS9_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS9_CTRIPOUTL    0x20000U    // Input Flag for CMPSS9_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS10_CTRIPOUTH   0x40000U    // Input Flag for CMPSS10_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS10_CTRIPOUTL   0x80000U    // Input Flag for CMPSS10_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS11_CTRIPOUTH   0x100000U   // Input Flag for CMPSS11_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS11_CTRIPOUTL   0x200000U   // Input Flag for CMPSS11_CTRIPOUTL Signal
#define XBAR_FLG2_CMPSS12_CTRIPOUTH   0x400000U   // Input Flag for CMPSS12_CTRIPOUTH Signal
#define XBAR_FLG2_CMPSS12_CTRIPOUTL   0x800000U   // Input Flag for CMPSS12_CTRIPOUTL Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG3 register
//
//*************************************************************************************************
#define XBAR_FLG3_SD1FLT1_COMPL   0x1U          // Input Flag for SD1FLT1_COMPL Signal
#define XBAR_FLG3_SD1FLT1_COMPH   0x2U          // Input Flag for SD1FLT1_COMPH Signal
#define XBAR_FLG3_SD1FLT2_COMPL   0x4U          // Input Flag for SD1FLT2_COMPL Signal
#define XBAR_FLG3_SD1FLT2_COMPH   0x8U          // Input Flag for SD1FLT2_COMPH Signal
#define XBAR_FLG3_SD1FLT3_COMPL   0x10U         // Input Flag for SD1FLT3_COMPL Signal
#define XBAR_FLG3_SD1FLT3_COMPH   0x20U         // Input Flag for SD1FLT3_COMPH Signal
#define XBAR_FLG3_SD1FLT4_COMPL   0x40U         // Input Flag for SD1FLT4_COMPL Signal
#define XBAR_FLG3_SD1FLT4_COMPH   0x80U         // Input Flag for SD1FLT4_COMPH Signal
#define XBAR_FLG3_SD2FLT1_COMPL   0x100U        // Input Flag for SD2FLT1_COMPL Signal
#define XBAR_FLG3_SD2FLT1_COMPH   0x200U        // Input Flag for SD2FLT1_COMPH Signal
#define XBAR_FLG3_SD2FLT2_COMPL   0x400U        // Input Flag for SD2FLT2_COMPL Signal
#define XBAR_FLG3_SD2FLT2_COMPH   0x800U        // Input Flag for SD2FLT2_COMPH Signal
#define XBAR_FLG3_SD2FLT3_COMPL   0x1000U       // Input Flag for SD2FLT3_COMPL Signal
#define XBAR_FLG3_SD2FLT3_COMPH   0x2000U       // Input Flag for SD2FLT3_COMPH Signal
#define XBAR_FLG3_SD2FLT4_COMPL   0x4000U       // Input Flag for SD2FLT4_COMPL Signal
#define XBAR_FLG3_SD2FLT4_COMPH   0x8000U       // Input Flag for SD2FLT4_COMPH Signal
#define XBAR_FLG3_SD3FLT1_COMPH   0x10000U      // Input Flag for SD3FLT1_COMPH Signal
#define XBAR_FLG3_SD3FLT1_COMPL   0x20000U      // Input Flag for SD3FLT1_COMPL Signal
#define XBAR_FLG3_SD3FLT2_COMPH   0x40000U      // Input Flag for SD3FLT2_COMPH Signal
#define XBAR_FLG3_SD3FLT2_COMPL   0x80000U      // Input Flag for SD3FLT2_COMPL Signal
#define XBAR_FLG3_SD3FLT3_COMPH   0x100000U     // Input Flag for SD3FLT3_COMPH Signal
#define XBAR_FLG3_SD3FLT3_COMPL   0x200000U     // Input Flag for SD3FLT3_COMPL Signal
#define XBAR_FLG3_SD3FLT4_COMPH   0x400000U     // Input Flag for SD3FLT4_COMPH Signal
#define XBAR_FLG3_SD3FLT4_COMPL   0x800000U     // Input Flag for SD3FLT4_COMPL Signal
#define XBAR_FLG3_SD4FLT1_COMPH   0x1000000U    // Input Flag for SD4FLT1_COMPH Signal
#define XBAR_FLG3_SD4FLT1_COMPL   0x2000000U    // Input Flag for SD4FLT1_COMPL Signal
#define XBAR_FLG3_SD4FLT2_COMPH   0x4000000U    // Input Flag for SD4FLT2_COMPH Signal
#define XBAR_FLG3_SD4FLT2_COMPL   0x8000000U    // Input Flag for SD4FLT2_COMPL Signal
#define XBAR_FLG3_SD4FLT3_COMPH   0x10000000U   // Input Flag for SD4FLT3_COMPH Signal
#define XBAR_FLG3_SD4FLT3_COMPL   0x20000000U   // Input Flag for SD4FLT3_COMPL Signal
#define XBAR_FLG3_SD4FLT4_COMPH   0x40000000U   // Input Flag for SD4FLT4_COMPH Signal
#define XBAR_FLG3_SD4FLT4_COMPL   0x80000000U   // Input Flag for SD4FLT4_COMPL Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG4 register
//
//*************************************************************************************************
#define XBAR_FLG4_INPUT1    0x1U          // Input Flag for INPUT1 Signal
#define XBAR_FLG4_INPUT2    0x2U          // Input Flag for INPUT2 Signal
#define XBAR_FLG4_INPUT3    0x4U          // Input Flag for INPUT3 Signal
#define XBAR_FLG4_INPUT4    0x8U          // Input Flag for INPUT4 Signal
#define XBAR_FLG4_INPUT5    0x10U         // Input Flag for INPUT5 Signal
#define XBAR_FLG4_INPUT6    0x20U         // Input Flag for INPUT6 Signal
#define XBAR_FLG4_INPUT7    0x40U         // Input Flag for INPUT7 Signal
#define XBAR_FLG4_INPUT8    0x80U         // Input Flag for INPUT8 Signal
#define XBAR_FLG4_INPUT9    0x100U        // Input Flag for INPUT9 Signal
#define XBAR_FLG4_INPUT10   0x200U        // Input Flag for INPUT10 Signal
#define XBAR_FLG4_INPUT11   0x400U        // Input Flag for INPUT11 Signal
#define XBAR_FLG4_INPUT12   0x800U        // Input Flag for INPUT12 Signal
#define XBAR_FLG4_INPUT13   0x1000U       // Input Flag for INPUT13 Signal
#define XBAR_FLG4_INPUT14   0x2000U       // Input Flag for INPUT14 Signal
#define XBAR_FLG4_INPUT15   0x4000U       // Input Flag for INPUT15 Signal
#define XBAR_FLG4_INPUT16   0x8000U       // Input Flag for INPUT16 Signal
#define XBAR_FLG4_INPUT17   0x10000U      // Input Flag for INPUT17 Signal
#define XBAR_FLG4_INPUT18   0x20000U      // Input Flag for INPUT18 Signal
#define XBAR_FLG4_INPUT19   0x40000U      // Input Flag for INPUT19 Signal
#define XBAR_FLG4_INPUT20   0x80000U      // Input Flag for INPUT20 Signal
#define XBAR_FLG4_INPUT21   0x100000U     // Input Flag for INPUT21 Signal
#define XBAR_FLG4_INPUT22   0x200000U     // Input Flag for INPUT22 Signal
#define XBAR_FLG4_INPUT23   0x400000U     // Input Flag for INPUT23 Signal
#define XBAR_FLG4_INPUT24   0x800000U     // Input Flag for INPUT24 Signal
#define XBAR_FLG4_INPUT25   0x1000000U    // Input Flag for INPUT25 Signal
#define XBAR_FLG4_INPUT26   0x2000000U    // Input Flag for INPUT26 Signal
#define XBAR_FLG4_INPUT27   0x4000000U    // Input Flag for INPUT27 Signal
#define XBAR_FLG4_INPUT28   0x8000000U    // Input Flag for INPUT28 Signal
#define XBAR_FLG4_INPUT29   0x10000000U   // Input Flag for INPUT29 Signal
#define XBAR_FLG4_INPUT30   0x20000000U   // Input Flag for INPUT30 Signal
#define XBAR_FLG4_INPUT31   0x40000000U   // Input Flag for INPUT31 Signal
#define XBAR_FLG4_INPUT32   0x80000000U   // Input Flag for INPUT32 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG5 register
//
//*************************************************************************************************
#define XBAR_FLG5_ADCAEVT1            0x1U          // Input Flag for ADCAEVT1  Signal
#define XBAR_FLG5_ADCAEVT2            0x2U          // Input Flag for ADCAEVT2  Signal
#define XBAR_FLG5_ADCAEVT3            0x4U          // Input Flag for ADCAEVT3  Signal
#define XBAR_FLG5_ADCAEVT4            0x8U          // Input Flag for ADCAEVT4  Signal
#define XBAR_FLG5_ADCBEVT1            0x10U         // Input Flag for ADCBEVT1  Signal
#define XBAR_FLG5_ADCBEVT2            0x20U         // Input Flag for ADCBEVT2  Signal
#define XBAR_FLG5_ADCBEVT3            0x40U         // Input Flag for ADCBEVT3  Signal
#define XBAR_FLG5_ADCBEVT4            0x80U         // Input Flag for ADCBEVT4  Signal
#define XBAR_FLG5_ADCCEVT1            0x100U        // Input Flag for ADCCEVT1  Signal
#define XBAR_FLG5_ADCCEVT2            0x200U        // Input Flag for ADCCEVT2  Signal
#define XBAR_FLG5_ADCCEVT3            0x400U        // Input Flag for ADCCEVT3  Signal
#define XBAR_FLG5_ADCCEVT4            0x800U        // Input Flag for ADCCEVT4  Signal
#define XBAR_FLG5_ADCDEVT1            0x1000U       // Input Flag for ADCDEVT1  Signal
#define XBAR_FLG5_ADCDEVT2            0x2000U       // Input Flag for ADCDEVT2  Signal
#define XBAR_FLG5_ADCDEVT3            0x4000U       // Input Flag for ADCDEVT3  Signal
#define XBAR_FLG5_ADCDEVT4            0x8000U       // Input Flag for ADCDEVT4  Signal
#define XBAR_FLG5_ADCEEVT1            0x10000U      // Input Flag for ADCEEVT1  Signal
#define XBAR_FLG5_ADCEEVT2            0x20000U      // Input Flag for ADCEEVT2  Signal
#define XBAR_FLG5_ADCEEVT3            0x40000U      // Input Flag for ADCEEVT3  Signal
#define XBAR_FLG5_ADCEEVT4            0x80000U      // Input Flag for ADCEEVT4  Signal
#define XBAR_FLG5_CPU1_ADCCHECKEVT1   0x100000U     // Input Flag for CPU1_ADCCHECKEVT1  Signal
#define XBAR_FLG5_CPU1_ADCCHECKEVT2   0x200000U     // Input Flag for CPU1_ADCCHECKEVT2  Signal
#define XBAR_FLG5_CPU1_ADCCHECKEVT3   0x400000U     // Input Flag for CPU1_ADCCHECKEVT3  Signal
#define XBAR_FLG5_CPU1_ADCCHECKEVT4   0x800000U     // Input Flag for CPU1_ADCCHECKEVT4  Signal
#define XBAR_FLG5_CPU2_ADCCHECKEVT1   0x1000000U    // Input Flag for CPU2_ADCCHECKEVT1  Signal
#define XBAR_FLG5_CPU2_ADCCHECKEVT2   0x2000000U    // Input Flag for CPU2_ADCCHECKEVT2  Signal
#define XBAR_FLG5_CPU2_ADCCHECKEVT3   0x4000000U    // Input Flag for CPU2_ADCCHECKEVT3  Signal
#define XBAR_FLG5_CPU2_ADCCHECKEVT4   0x8000000U    // Input Flag for CPU2_ADCCHECKEVT4  Signal
#define XBAR_FLG5_CPU3_ADCCHECKEVT1   0x10000000U   // Input Flag for CPU3_ADCCHECKEVT1  Signal
#define XBAR_FLG5_CPU3_ADCCHECKEVT2   0x20000000U   // Input Flag for CPU3_ADCCHECKEVT2  Signal
#define XBAR_FLG5_CPU3_ADCCHECKEVT3   0x40000000U   // Input Flag for CPU3_ADCCHECKEVT3  Signal
#define XBAR_FLG5_CPU3_ADCCHECKEVT4   0x80000000U   // Input Flag for CPU3_ADCCHECKEVT4  Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG6 register
//
//*************************************************************************************************
#define XBAR_FLG6_CLB1_OUT4       0x1U          // Input Latch for CLB1_OUT4 Signal
#define XBAR_FLG6_CLB1_OUT5       0x2U          // Input Latch for CLB1_OUT5 Signal
#define XBAR_FLG6_CLB2_OUT4       0x4U          // Input Latch for CLB2_OUT4 Signal
#define XBAR_FLG6_CLB2_OUT5       0x8U          // Input Latch for CLB2_OUT5 Signal
#define XBAR_FLG6_CLB3_OUT4       0x10U         // Input Latch for CLB3_OUT4 Signal
#define XBAR_FLG6_CLB3_OUT5       0x20U         // Input Latch for CLB3_OUT5 Signal
#define XBAR_FLG6_CLB4_OUT4       0x40U         // Input Latch for CLB4_OUT4 Signal
#define XBAR_FLG6_CLB4_OUT5       0x80U         // Input Latch for CLB4_OUT5 Signal
#define XBAR_FLG6_CLB5_OUT4       0x100U        // Input Latch for CLB5_OUT4 Signal
#define XBAR_FLG6_CLB5_OUT5       0x200U        // Input Latch for CLB5_OUT5 Signal
#define XBAR_FLG6_CLB6_OUT4       0x400U        // Input Latch for CLB6_OUT4 Signal
#define XBAR_FLG6_CLB6_OUT5       0x800U        // Input Latch for CLB6_OUT5 Signal
#define XBAR_FLG6_FSIA_RX_TRIG1   0x10000U      // Input Flag for FSIA_RX_TRIG1 Signal
#define XBAR_FLG6_FSIB_RX_TRIG1   0x20000U      // Input Flag for FSIB_RX_TRIG1 Signal
#define XBAR_FLG6_FSIC_RX_TRIG1   0x40000U      // Input Flag for FSIC_RX_TRIG1 Signal
#define XBAR_FLG6_FSID_RX_TRIG1   0x80000U      // Input Flag for FSID_RX_TRIG1 Signal
#define XBAR_FLG6_WADI1OUT0       0x400000U     // Input Flag for WADI1OUT0 Signal
#define XBAR_FLG6_WADI1OUT1       0x800000U     // Input Flag for WADI1OUT1 Signal
#define XBAR_FLG6_WADI1OUT2       0x1000000U    // Input Flag for WADI1OUT2 Signal
#define XBAR_FLG6_WADI1OUT3       0x2000000U    // Input Flag for WADI1OUT3 Signal
#define XBAR_FLG6_WADI1OUT4       0x4000000U    // Input Flag for WADI1OUT4 Signal
#define XBAR_FLG6_WADI1OUT5       0x8000000U    // Input Flag for WADI1OUT5 Signal
#define XBAR_FLG6_WADI1OUT6       0x10000000U   // Input Flag for WADI1OUT6 Signal
#define XBAR_FLG6_WADI1OUT7       0x20000000U   // Input Flag for WADI1OUT7 Signal
#define XBAR_FLG6_ECATSYNC0       0x40000000U   // Input Latch for ECATSYNC0 Signal
#define XBAR_FLG6_ECATSYNC1       0x80000000U   // Input Latch for ECATSYNC1 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG7 register
//
//*************************************************************************************************
#define XBAR_FLG7_ECAP1_OUT       0x1U          // Input Flag for ECAP1_OUT Signal
#define XBAR_FLG7_ECAP2_OUT       0x2U          // Input Flag for ECAP2_OUT Signal
#define XBAR_FLG7_ECAP3_OUT       0x4U          // Input Flag for ECAP3_OUT Signal
#define XBAR_FLG7_ECAP4_OUT       0x8U          // Input Flag for ECAP4_OUT Signal
#define XBAR_FLG7_ECAP5_OUT       0x10U         // Input Flag for ECAP5_OUT Signal
#define XBAR_FLG7_ECAP6_OUT       0x20U         // Input Flag for ECAP6_OUT Signal
#define XBAR_FLG7_ECAP1_TRIPOUT   0x100U        // Input Flag for ECAP1_TRIPOUT Signal
#define XBAR_FLG7_ECAP2_TRIPOUT   0x200U        // Input Flag for ECAP2_TRIPOUT Signal
#define XBAR_FLG7_ECAP3_TRIPOUT   0x400U        // Input Flag for ECAP3_TRIPOUT Signal
#define XBAR_FLG7_ECAP4_TRIPOUT   0x800U        // Input Flag for ECAP4_TRIPOUT Signal
#define XBAR_FLG7_ECAP5_TRIPOUT   0x1000U       // Input Flag for ECAP5_TRIPOUT Signal
#define XBAR_FLG7_ECAP6_TRIPOUT   0x2000U       // Input Flag for ECAP6_TRIPOUT Signal
#define XBAR_FLG7_ADCSOCA         0x10000U      // Input Flag for ADCSOCA Signal
#define XBAR_FLG7_ADCSOCB         0x20000U      // Input Flag for ADCSOCB Signal
#define XBAR_FLG7_ESMGENEVT       0x40000U      // Input Flag for ESMGENEVT Signal
#define XBAR_FLG7_EXTSYNCOUT      0x80000U      // Input Flag for EXTSYNCOUT Signal
#define XBAR_FLG7_WADI2OUT0       0x1000000U    // Input Flag for WADI2OUT0 Signal
#define XBAR_FLG7_WADI2OUT1       0x2000000U    // Input Flag for WADI2OUT1 Signal
#define XBAR_FLG7_WADI2OUT2       0x4000000U    // Input Flag for WADI2OUT2 Signal
#define XBAR_FLG7_WADI2OUT3       0x8000000U    // Input Flag for WADI2OUT3 Signal
#define XBAR_FLG7_WADI2OUT4       0x10000000U   // Input Flag for WADI2OUT4 Signal
#define XBAR_FLG7_WADI2OUT5       0x20000000U   // Input Flag for WADI2OUT5 Signal
#define XBAR_FLG7_WADI2OUT6       0x40000000U   // Input Flag for WADI2OUT6 Signal
#define XBAR_FLG7_WADI2OUT7       0x80000000U   // Input Flag for WADI2OUT7 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG8 register
//
//*************************************************************************************************
#define XBAR_FLG8_EPWM1_TRIPOUT    0x1U       // Input Flag for EPWM1_TRIPOUT Signal
#define XBAR_FLG8_EPWM2_TRIPOUT    0x2U       // Input Flag for EPWM2_TRIPOUT Signal
#define XBAR_FLG8_EPWM3_TRIPOUT    0x4U       // Input Flag for EPWM3_TRIPOUT Signal
#define XBAR_FLG8_EPWM4_TRIPOUT    0x8U       // Input Flag for EPWM4_TRIPOUT Signal
#define XBAR_FLG8_EPWM5_TRIPOUT    0x10U      // Input Flag for EPWM5_TRIPOUT Signal
#define XBAR_FLG8_EPWM6_TRIPOUT    0x20U      // Input Flag for EPWM6_TRIPOUT Signal
#define XBAR_FLG8_EPWM7_TRIPOUT    0x40U      // Input Flag for EPWM7_TRIPOUT Signal
#define XBAR_FLG8_EPWM8_TRIPOUT    0x80U      // Input Flag for EPWM8_TRIPOUT Signal
#define XBAR_FLG8_EPWM9_TRIPOUT    0x100U     // Input Flag for EPWM9_TRIPOUT Signal
#define XBAR_FLG8_EPWM10_TRIPOUT   0x200U     // Input Flag for EPWM10_TRIPOUT Signal
#define XBAR_FLG8_EPWM11_TRIPOUT   0x400U     // Input Flag for EPWM11_TRIPOUT Signal
#define XBAR_FLG8_EPWM12_TRIPOUT   0x800U     // Input Flag for EPWM12_TRIPOUT Signal
#define XBAR_FLG8_EPWM13_TRIPOUT   0x1000U    // Input Flag for EPWM13_TRIPOUT Signal
#define XBAR_FLG8_EPWM14_TRIPOUT   0x2000U    // Input Flag for EPWM14_TRIPOUT Signal
#define XBAR_FLG8_EPWM15_TRIPOUT   0x4000U    // Input Flag for EPWM15_TRIPOUT Signal
#define XBAR_FLG8_EPWM16_TRIPOUT   0x8000U    // Input Flag for EPWM16_TRIPOUT Signal
#define XBAR_FLG8_EPWM17_TRIPOUT   0x10000U   // Input Flag for EPWM17_TRIPOUT Signal
#define XBAR_FLG8_EPWM18_TRIPOUT   0x20000U   // Input Flag for EPWM18_TRIPOUT Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG9 register
//
//*************************************************************************************************
#define XBAR_FLG9_EPWM1_DEL_TRIP    0x1U       // Input Flag for EPWM1_DEL_TRIP Signal
#define XBAR_FLG9_EPWM2_DEL_TRIP    0x2U       // Input Flag for EPWM2_DEL_TRIP Signal
#define XBAR_FLG9_EPWM3_DEL_TRIP    0x4U       // Input Flag for EPWM3_DEL_TRIP Signal
#define XBAR_FLG9_EPWM4_DEL_TRIP    0x8U       // Input Flag for EPWM4_DEL_TRIP Signal
#define XBAR_FLG9_EPWM5_DEL_TRIP    0x10U      // Input Flag for EPWM5_DEL_TRIP Signal
#define XBAR_FLG9_EPWM6_DEL_TRIP    0x20U      // Input Flag for EPWM6_DEL_TRIP Signal
#define XBAR_FLG9_EPWM7_DEL_TRIP    0x40U      // Input Flag for EPWM7_DEL_TRIP Signal
#define XBAR_FLG9_EPWM8_DEL_TRIP    0x80U      // Input Flag for EPWM8_DEL_TRIP Signal
#define XBAR_FLG9_EPWM9_DEL_TRIP    0x100U     // Input Flag for EPWM9_DEL_TRIP Signal
#define XBAR_FLG9_EPWM10_DEL_TRIP   0x200U     // Input Flag for EPWM10_DEL_TRIP Signal
#define XBAR_FLG9_EPWM11_DEL_TRIP   0x400U     // Input Flag for EPWM11_DEL_TRIP Signal
#define XBAR_FLG9_EPWM12_DEL_TRIP   0x800U     // Input Flag for EPWM12_DEL_TRIP Signal
#define XBAR_FLG9_EPWM13_DEL_TRIP   0x1000U    // Input Flag for EPWM13_DEL_TRIP Signal
#define XBAR_FLG9_EPWM14_DEL_TRIP   0x2000U    // Input Flag for EPWM14_DEL_TRIP Signal
#define XBAR_FLG9_EPWM15_DEL_TRIP   0x4000U    // Input Flag for EPWM15_DEL_TRIP Signal
#define XBAR_FLG9_EPWM16_DEL_TRIP   0x8000U    // Input Flag for EPWM16_DEL_TRIP Signal
#define XBAR_FLG9_EPWM17_DEL_TRIP   0x10000U   // Input Flag for EPWM17_DEL_TRIP Signal
#define XBAR_FLG9_EPWM18_DEL_TRIP   0x20000U   // Input Flag for EPWM18_DEL_TRIP Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG10 register
//
//*************************************************************************************************
#define XBAR_FLG10_EPWM1_DEL_ACTIVE    0x1U       // Input Flag for EPWM1_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM2_DEL_ACTIVE    0x2U       // Input Flag for EPWM2_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM3_DEL_ACTIVE    0x4U       // Input Flag for EPWM3_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM4_DEL_ACTIVE    0x8U       // Input Flag for EPWM4_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM5_DEL_ACTIVE    0x10U      // Input Flag for EPWM5_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM6_DEL_ACTIVE    0x20U      // Input Flag for EPWM6_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM7_DEL_ACTIVE    0x40U      // Input Flag for EPWM7_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM8_DEL_ACTIVE    0x80U      // Input Flag for EPWM8_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM9_DEL_ACTIVE    0x100U     // Input Flag for EPWM9_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM10_DEL_ACTIVE   0x200U     // Input Flag for EPWM10_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM11_DEL_ACTIVE   0x400U     // Input Flag for EPWM11_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM12_DEL_ACTIVE   0x800U     // Input Flag for EPWM12_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM13_DEL_ACTIVE   0x1000U    // Input Flag for EPWM13_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM14_DEL_ACTIVE   0x2000U    // Input Flag for EPWM14_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM15_DEL_ACTIVE   0x4000U    // Input Flag for EPWM15_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM16_DEL_ACTIVE   0x8000U    // Input Flag for EPWM16_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM17_DEL_ACTIVE   0x10000U   // Input Flag for EPWM17_DEL_ACTIVE Signal
#define XBAR_FLG10_EPWM18_DEL_ACTIVE   0x20000U   // Input Flag for EPWM18_DEL_ACTIVE Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG11 register
//
//*************************************************************************************************
#define XBAR_FLG11_EPWM1_A0_SCLK    0x1U          // Input Flag for EPWM1_A0_sclk Signal
#define XBAR_FLG11_EPWM1_B0_SCLK    0x2U          // Input Flag for EPWM1_B0_sclk Signal
#define XBAR_FLG11_EPWM2_A0_SCLK    0x4U          // Input Flag for EPWM2_A0_sclk Signal
#define XBAR_FLG11_EPWM2_B0_SCLK    0x8U          // Input Flag for EPWM2_B0_sclk Signal
#define XBAR_FLG11_EPWM3_A0_SCLK    0x10U         // Input Flag for EPWM3_A0_sclk Signal
#define XBAR_FLG11_EPWM3_B0_SCLK    0x20U         // Input Flag for EPWM3_B0_sclk Signal
#define XBAR_FLG11_EPWM4_A0_SCLK    0x40U         // Input Flag for EPWM4_A0_sclk Signal
#define XBAR_FLG11_EPWM4_B0_SCLK    0x80U         // Input Flag for EPWM4_B0_sclk Signal
#define XBAR_FLG11_EPWM5_A0_SCLK    0x100U        // Input Flag for EPWM5_A0_sclk Signal
#define XBAR_FLG11_EPWM5_B0_SCLK    0x200U        // Input Flag for EPWM5_B0_sclk Signal
#define XBAR_FLG11_EPWM6_A0_SCLK    0x400U        // Input Flag for EPWM6_A0_sclk Signal
#define XBAR_FLG11_EPWM6_B0_SCLK    0x800U        // Input Flag for EPWM6_B0_sclk Signal
#define XBAR_FLG11_EPWM7_A0_SCLK    0x1000U       // Input Flag for EPWM7_A0_sclk Signal
#define XBAR_FLG11_EPWM7_B0_SCLK    0x2000U       // Input Flag for EPWM7_B0_sclk Signal
#define XBAR_FLG11_EPWM8_A0_SCLK    0x4000U       // Input Flag for EPWM8_A0_sclk Signal
#define XBAR_FLG11_EPWM8_B0_SCLK    0x8000U       // Input Flag for EPWM8_B0_sclk Signal
#define XBAR_FLG11_EPWM9_A0_SCLK    0x10000U      // Input Flag for EPWM9_A0_sclk Signal
#define XBAR_FLG11_EPWM9_B0_SCLK    0x20000U      // Input Flag for EPWM9_B0_sclk Signal
#define XBAR_FLG11_EPWM10_A0_SCLK   0x40000U      // Input Flag for EPWM10_A0_sclk Signal
#define XBAR_FLG11_EPWM10_B0_SCLK   0x80000U      // Input Flag for EPWM10_B0_sclk Signal
#define XBAR_FLG11_EPWM11_A0_SCLK   0x100000U     // Input Flag for EPWM11_A0_sclk Signal
#define XBAR_FLG11_EPWM11_B0_SCLK   0x200000U     // Input Flag for EPWM11_B0_sclk Signal
#define XBAR_FLG11_EPWM12_A0_SCLK   0x400000U     // Input Flag for EPWM12_A0_sclk Signal
#define XBAR_FLG11_EPWM12_B0_SCLK   0x800000U     // Input Flag for EPWM12_B0_sclk Signal
#define XBAR_FLG11_EPWM13_A0_SCLK   0x1000000U    // Input Flag for EPWM13_A0_sclk Signal
#define XBAR_FLG11_EPWM13_B0_SCLK   0x2000000U    // Input Flag for EPWM13_B0_sclk Signal
#define XBAR_FLG11_EPWM14_A0_SCLK   0x4000000U    // Input Flag for EPWM14_A0_sclk Signal
#define XBAR_FLG11_EPWM14_B0_SCLK   0x8000000U    // Input Flag for EPWM14_B0_sclk Signal
#define XBAR_FLG11_EPWM15_A0_SCLK   0x10000000U   // Input Flag for EPWM15_A0_sclk Signal
#define XBAR_FLG11_EPWM15_B0_SCLK   0x20000000U   // Input Flag for EPWM15_B0_sclk Signal
#define XBAR_FLG11_EPWM16_A0_SCLK   0x40000000U   // Input Flag for EPWM16_A0_sclk Signal
#define XBAR_FLG11_EPWM16_B0_SCLK   0x80000000U   // Input Flag for EPWM16_B0_sclk Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG12 register
//
//*************************************************************************************************
#define XBAR_FLG12_EPWM17_A0_SCLK   0x1U   // Input Flag for EPWM17_A0_sclk Signal
#define XBAR_FLG12_EPWM17_B0_SCLK   0x2U   // Input Flag for EPWM17_B0_sclk Signal
#define XBAR_FLG12_EPWM18_A0_SCLK   0x4U   // Input Flag for EPWM18_A0_sclk Signal
#define XBAR_FLG12_EPWM18_B0_SCLK   0x8U   // Input Flag for EPWM18_B0_sclk Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG13 register
//
//*************************************************************************************************
#define XBAR_FLG13_MDL1_OUTA    0x1U          // Input Flag for MDL1_OUTA Signal
#define XBAR_FLG13_MDL1_OUTB    0x2U          // Input Flag for MDL1_OUTB Signal
#define XBAR_FLG13_MDL2_OUTA    0x4U          // Input Flag for MDL2_OUTA Signal
#define XBAR_FLG13_MDL2_OUTB    0x8U          // Input Flag for MDL2_OUTB Signal
#define XBAR_FLG13_MDL3_OUTA    0x10U         // Input Flag for MDL3_OUTA Signal
#define XBAR_FLG13_MDL3_OUTB    0x20U         // Input Flag for MDL3_OUTB Signal
#define XBAR_FLG13_MDL4_OUTA    0x40U         // Input Flag for MDL4_OUTA Signal
#define XBAR_FLG13_MDL4_OUTB    0x80U         // Input Flag for MDL4_OUTB Signal
#define XBAR_FLG13_MDL5_OUTA    0x100U        // Input Flag for MDL5_OUTA Signal
#define XBAR_FLG13_MDL5_OUTB    0x200U        // Input Flag for MDL5_OUTB Signal
#define XBAR_FLG13_MDL6_OUTA    0x400U        // Input Flag for MDL6_OUTA Signal
#define XBAR_FLG13_MDL6_OUTB    0x800U        // Input Flag for MDL6_OUTB Signal
#define XBAR_FLG13_MDL7_OUTA    0x1000U       // Input Flag for MDL7_OUTA Signal
#define XBAR_FLG13_MDL7_OUTB    0x2000U       // Input Flag for MDL7_OUTB Signal
#define XBAR_FLG13_MDL8_OUTA    0x4000U       // Input Flag for MDL8_OUTA Signal
#define XBAR_FLG13_MDL8_OUTB    0x8000U       // Input Flag for MDL8_OUTB Signal
#define XBAR_FLG13_MDL9_OUTA    0x10000U      // Input Flag for MDL9_OUTA Signal
#define XBAR_FLG13_MDL9_OUTB    0x20000U      // Input Flag for MDL9_OUTB Signal
#define XBAR_FLG13_MDL10_OUTA   0x40000U      // Input Flag for MDL10_OUTA Signal
#define XBAR_FLG13_MDL10_OUTB   0x80000U      // Input Flag for MDL10_OUTB Signal
#define XBAR_FLG13_MDL11_OUTA   0x100000U     // Input Flag for MDL11_OUTA Signal
#define XBAR_FLG13_MDL11_OUTB   0x200000U     // Input Flag for MDL11_OUTB Signal
#define XBAR_FLG13_MDL12_OUTA   0x400000U     // Input Flag for MDL12_OUTA Signal
#define XBAR_FLG13_MDL12_OUTB   0x800000U     // Input Flag for MDL12_OUTB Signal
#define XBAR_FLG13_MDL13_OUTA   0x1000000U    // Input Flag for MDL13_OUTA Signal
#define XBAR_FLG13_MDL13_OUTB   0x2000000U    // Input Flag for MDL13_OUTB Signal
#define XBAR_FLG13_MDL14_OUTA   0x4000000U    // Input Flag for MDL14_OUTA Signal
#define XBAR_FLG13_MDL14_OUTB   0x8000000U    // Input Flag for MDL14_OUTB Signal
#define XBAR_FLG13_MDL15_OUTA   0x10000000U   // Input Flag for MDL15_OUTA Signal
#define XBAR_FLG13_MDL15_OUTB   0x20000000U   // Input Flag for MDL15_OUTB Signal
#define XBAR_FLG13_MDL16_OUTA   0x40000000U   // Input Flag for MDL16_OUTA Signal
#define XBAR_FLG13_MDL16_OUTB   0x80000000U   // Input Flag for MDL16_OUTB Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG14 register
//
//*************************************************************************************************
#define XBAR_FLG14_MDL17_OUTA   0x1U   // Input Flag for MDL17_OUTA Signal
#define XBAR_FLG14_MDL17_OUTB   0x2U   // Input Flag for MDL17_OUTB Signal
#define XBAR_FLG14_MDL18_OUTA   0x4U   // Input Flag for MDL18_OUTA Signal
#define XBAR_FLG14_MDL18_OUTB   0x8U   // Input Flag for MDL18_OUTB Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG15 register
//
//*************************************************************************************************
#define XBAR_FLG15_CLB1_OUT0   0x1U          // Input Flag for CLB1_OUT0 Signal
#define XBAR_FLG15_CLB1_OUT1   0x2U          // Input Flag for CLB1_OUT1 Signal
#define XBAR_FLG15_CLB1_OUT2   0x4U          // Input Flag for CLB1_OUT2 Signal
#define XBAR_FLG15_CLB1_OUT3   0x8U          // Input Flag for CLB1_OUT3 Signal
#define XBAR_FLG15_CLB1_OUT6   0x10U         // Input Flag for CLB1_OUT6 Signal
#define XBAR_FLG15_CLB1_OUT7   0x20U         // Input Flag for CLB1_OUT7 Signal
#define XBAR_FLG15_CLB2_OUT0   0x40U         // Input Flag for CLB2_OUT0 Signal
#define XBAR_FLG15_CLB2_OUT1   0x80U         // Input Flag for CLB2_OUT1 Signal
#define XBAR_FLG15_CLB2_OUT2   0x100U        // Input Flag for CLB2_OUT2 Signal
#define XBAR_FLG15_CLB2_OUT3   0x200U        // Input Flag for CLB2_OUT3 Signal
#define XBAR_FLG15_CLB2_OUT6   0x400U        // Input Flag for CLB2_OUT6 Signal
#define XBAR_FLG15_CLB2_OUT7   0x800U        // Input Flag for CLB2_OUT7 Signal
#define XBAR_FLG15_CLB3_OUT0   0x1000U       // Input Flag for CLB3_OUT0 Signal
#define XBAR_FLG15_CLB3_OUT1   0x2000U       // Input Flag for CLB3_OUT1 Signal
#define XBAR_FLG15_CLB3_OUT2   0x4000U       // Input Flag for CLB3_OUT2 Signal
#define XBAR_FLG15_CLB3_OUT3   0x8000U       // Input Flag for CLB3_OUT3 Signal
#define XBAR_FLG15_CLB3_OUT6   0x10000U      // Input Flag for CLB3_OUT6 Signal
#define XBAR_FLG15_CLB3_OUT7   0x20000U      // Input Flag for CLB3_OUT7 Signal
#define XBAR_FLG15_CLB4_OUT0   0x40000U      // Input Flag for CLB4_OUT0 Signal
#define XBAR_FLG15_CLB4_OUT1   0x80000U      // Input Flag for CLB4_OUT1 Signal
#define XBAR_FLG15_CLB4_OUT2   0x100000U     // Input Flag for CLB4_OUT2 Signal
#define XBAR_FLG15_CLB4_OUT3   0x200000U     // Input Flag for CLB4_OUT3 Signal
#define XBAR_FLG15_CLB4_OUT6   0x400000U     // Input Flag for CLB4_OUT6 Signal
#define XBAR_FLG15_CLB4_OUT7   0x800000U     // Input Flag for CLB4_OUT7 Signal
#define XBAR_FLG15_CLB5_OUT0   0x1000000U    // Input Flag for CLB5_OUT0 Signal
#define XBAR_FLG15_CLB5_OUT1   0x2000000U    // Input Flag for CLB5_OUT1 Signal
#define XBAR_FLG15_CLB5_OUT2   0x4000000U    // Input Flag for CLB5_OUT2 Signal
#define XBAR_FLG15_CLB5_OUT3   0x8000000U    // Input Flag for CLB5_OUT3 Signal
#define XBAR_FLG15_CLB5_OUT6   0x10000000U   // Input Flag for CLB5_OUT6 Signal
#define XBAR_FLG15_CLB5_OUT7   0x20000000U   // Input Flag for CLB5_OUT7 Signal
#define XBAR_FLG15_CLB6_OUT0   0x40000000U   // Input Flag for CLB6_OUT0 Signal
#define XBAR_FLG15_CLB6_OUT1   0x80000000U   // Input Flag for CLB6_OUT1 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG16 register
//
//*************************************************************************************************
#define XBAR_FLG16_CLB6_OUT2         0x1U          // Input Flag for CLB6_OUT2 Signal
#define XBAR_FLG16_CLB6_OUT3         0x2U          // Input Flag for CLB6_OUT3 Signal
#define XBAR_FLG16_CLB6_OUT6         0x4U          // Input Flag for CLB6_OUT6 Signal
#define XBAR_FLG16_CLB6_OUT7         0x8U          // Input Flag for CLB6_OUT7 Signal
#define XBAR_FLG16_ADCA_EXTMUXSEL0   0x10U         // Input Flag for ADCA_EXTMUXSEL0 Signal
#define XBAR_FLG16_ADCA_EXTMUXSEL1   0x20U         // Input Flag for ADCA_EXTMUXSEL1 Signal
#define XBAR_FLG16_ADCA_EXTMUXSEL2   0x40U         // Input Flag for ADCA_EXTMUXSEL2 Signal
#define XBAR_FLG16_ADCA_EXTMUXSEL3   0x80U         // Input Flag for ADCA_EXTMUXSEL3 Signal
#define XBAR_FLG16_ADCB_EXTMUXSEL0   0x100U        // Input Flag for ADCB_EXTMUXSEL0 Signal
#define XBAR_FLG16_ADCB_EXTMUXSEL1   0x200U        // Input Flag for ADCB_EXTMUXSEL1 Signal
#define XBAR_FLG16_ADCB_EXTMUXSEL2   0x400U        // Input Flag for ADCB_EXTMUXSEL2 Signal
#define XBAR_FLG16_ADCB_EXTMUXSEL3   0x800U        // Input Flag for ADCB_EXTMUXSEL3 Signal
#define XBAR_FLG16_ADCC_EXTMUXSEL0   0x1000U       // Input Flag for ADCC_EXTMUXSEL0 Signal
#define XBAR_FLG16_ADCC_EXTMUXSEL1   0x2000U       // Input Flag for ADCC_EXTMUXSEL1 Signal
#define XBAR_FLG16_ADCC_EXTMUXSEL2   0x4000U       // Input Flag for ADCC_EXTMUXSEL2 Signal
#define XBAR_FLG16_ADCC_EXTMUXSEL3   0x8000U       // Input Flag for ADCC_EXTMUXSEL3 Signal
#define XBAR_FLG16_ADCD_EXTMUXSEL0   0x10000U      // Input Flag for ADCD_EXTMUXSEL0 Signal
#define XBAR_FLG16_ADCD_EXTMUXSEL1   0x20000U      // Input Flag for ADCD_EXTMUXSEL1 Signal
#define XBAR_FLG16_ADCD_EXTMUXSEL2   0x40000U      // Input Flag for ADCD_EXTMUXSEL2 Signal
#define XBAR_FLG16_ADCD_EXTMUXSEL3   0x80000U      // Input Flag for ADCD_EXTMUXSEL3 Signal
#define XBAR_FLG16_ADCE_EXTMUXSEL0   0x100000U     // Input Flag for ADCE_EXTMUXSEL0 Signal
#define XBAR_FLG16_ADCE_EXTMUXSEL1   0x200000U     // Input Flag for ADCE_EXTMUXSEL1 Signal
#define XBAR_FLG16_ADCE_EXTMUXSEL2   0x400000U     // Input Flag for ADCE_EXTMUXSEL2 Signal
#define XBAR_FLG16_ADCE_EXTMUXSEL3   0x800000U     // Input Flag for ADCE_EXTMUXSEL3 Signal
#define XBAR_FLG16_EPG1_EPGOUT0      0x10000000U   // Input Flag for EPG1_EPGOUT0 Signal
#define XBAR_FLG16_EPG1_EPGOUT1      0x20000000U   // Input Flag for EPG1_EPGOUT1 Signal
#define XBAR_FLG16_EPG1_EPGOUT2      0x40000000U   // Input Flag for EPG1_EPGOUT2 Signal
#define XBAR_FLG16_EPG1_EPGOUT3      0x80000000U   // Input Flag for EPG1_EPGOUT3 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG17 register
//
//*************************************************************************************************
#define XBAR_FLG17_MCANA_FEVT0   0x1U       // Input Flag for MCANA_FEVT0 Signal
#define XBAR_FLG17_MCANA_FEVT1   0x2U       // Input Flag for MCANA_FEVT1 Signal
#define XBAR_FLG17_MCANA_FEVT2   0x4U       // Input Flag for MCANA_FEVT2 Signal
#define XBAR_FLG17_MCANB_FEVT0   0x8U       // Input Flag for MCANB_FEVT0 Signal
#define XBAR_FLG17_MCANB_FEVT1   0x10U      // Input Flag for MCANB_FEVT1 Signal
#define XBAR_FLG17_MCANB_FEVT2   0x20U      // Input Flag for MCANB_FEVT2 Signal
#define XBAR_FLG17_MCANC_FEVT0   0x40U      // Input Flag for MCANC_FEVT0 Signal
#define XBAR_FLG17_MCANC_FEVT1   0x80U      // Input Flag for MCANC_FEVT1 Signal
#define XBAR_FLG17_MCANC_FEVT2   0x100U     // Input Flag for MCANC_FEVT2 Signal
#define XBAR_FLG17_MCAND_FEVT0   0x200U     // Input Flag for MCAND_FEVT0 Signal
#define XBAR_FLG17_MCAND_FEVT1   0x400U     // Input Flag for MCAND_FEVT1 Signal
#define XBAR_FLG17_MCAND_FEVT2   0x800U     // Input Flag for MCAND_FEVT2 Signal
#define XBAR_FLG17_MCANE_FEVT0   0x1000U    // Input Flag for MCANE_FEVT0 Signal
#define XBAR_FLG17_MCANE_FEVT1   0x2000U    // Input Flag for MCANE_FEVT1 Signal
#define XBAR_FLG17_MCANE_FEVT2   0x4000U    // Input Flag for MCANE_FEVT2 Signal
#define XBAR_FLG17_MCANF_FEVT0   0x8000U    // Input Flag for MCANF_FEVT0 Signal
#define XBAR_FLG17_MCANF_FEVT1   0x10000U   // Input Flag for MCANF_FEVT1 Signal
#define XBAR_FLG17_MCANF_FEVT2   0x20000U   // Input Flag for MCANF_FEVT2 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARFLG18 register
//
//*************************************************************************************************
#define XBAR_FLG18_FSIRXA_TRIG_2   0x1U       // Input Flag for FSIRXA_TRIG_2 Signal
#define XBAR_FLG18_FSIRXA_TRIG_3   0x2U       // Input Flag for FSIRXA_TRIG_3 Signal
#define XBAR_FLG18_FSIRXB_TRIG_2   0x4U       // Input Flag for FSIRXB_TRIG_2 Signal
#define XBAR_FLG18_FSIRXB_TRIG_3   0x8U       // Input Flag for FSIRXB_TRIG_3 Signal
#define XBAR_FLG18_FSIRXC_TRIG_2   0x10U      // Input Flag for FSIRXC_TRIG_2 Signal
#define XBAR_FLG18_FSIRXC_TRIG_3   0x20U      // Input Flag for FSIRXC_TRIG_3 Signal
#define XBAR_FLG18_FSIRXD_TRIG_2   0x40U      // Input Flag for FSIRXD_TRIG_2 Signal
#define XBAR_FLG18_FSIRXD_TRIG_3   0x80U      // Input Flag for FSIRXD_TRIG_3 Signal
#define XBAR_FLG18_CPU1ERADEVT8    0x100U     // Input Flag for CPU1ERADEVT8 Signal
#define XBAR_FLG18_CPU1ERADEVT9    0x200U     // Input Flag for CPU1ERADEVT9 Signal
#define XBAR_FLG18_CPU1ERADEVT10   0x400U     // Input Flag for CPU1ERADEVT10 Signal
#define XBAR_FLG18_CPU1ERADEVT11   0x800U     // Input Flag for CPU1ERADEVT11 Signal
#define XBAR_FLG18_CPU2ERADEVT8    0x1000U    // Input Flag for CPU2ERADEVT8 Signal
#define XBAR_FLG18_CPU2ERADEVT9    0x2000U    // Input Flag for CPU2ERADEVT9 Signal
#define XBAR_FLG18_CPU2ERADEVT10   0x4000U    // Input Flag for CPU2ERADEVT10 Signal
#define XBAR_FLG18_CPU2ERADEVT11   0x8000U    // Input Flag for CPU2ERADEVT11 Signal
#define XBAR_FLG18_CPU3ERADEVT8    0x10000U   // Input Flag for CPU3ERADEVT8 Signal
#define XBAR_FLG18_CPU3ERADEVT9    0x20000U   // Input Flag for CPU3ERADEVT9 Signal
#define XBAR_FLG18_CPU3ERADEVT10   0x40000U   // Input Flag for CPU3ERADEVT10 Signal
#define XBAR_FLG18_CPU3ERADEVT11   0x80000U   // Input Flag for CPU3ERADEVT11 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR1 register
//
//*************************************************************************************************
#define XBAR_CLR1_CMPSS1_CTRIPL    0x1U        // Input Flag Clear for CMPSS1_CTRIPL Signal
#define XBAR_CLR1_CMPSS1_CTRIPH    0x2U        // Input Flag Clear for CMPSS1_CTRIPH Signal
#define XBAR_CLR1_CMPSS2_CTRIPL    0x4U        // Input Flag Clear for CMPSS2_CTRIPL Signal
#define XBAR_CLR1_CMPSS2_CTRIPH    0x8U        // Input Flag Clear for CMPSS2_CTRIPH Signal
#define XBAR_CLR1_CMPSS3_CTRIPL    0x10U       // Input Flag Clear for CMPSS3_CTRIPL Signal
#define XBAR_CLR1_CMPSS3_CTRIPH    0x20U       // Input Flag Clear for CMPSS3_CTRIPH Signal
#define XBAR_CLR1_CMPSS4_CTRIPL    0x40U       // Input Flag Clear for CMPSS4_CTRIPL Signal
#define XBAR_CLR1_CMPSS4_CTRIPH    0x80U       // Input Flag Clear for CMPSS4_CTRIPH Signal
#define XBAR_CLR1_CMPSS5_CTRIPL    0x100U      // Input Flag Clear for CMPSS5_CTRIPL Signal
#define XBAR_CLR1_CMPSS5_CTRIPH    0x200U      // Input Flag Clear for CMPSS5_CTRIPH Signal
#define XBAR_CLR1_CMPSS6_CTRIPL    0x400U      // Input Flag Clear for CMPSS6_CTRIPL Signal
#define XBAR_CLR1_CMPSS6_CTRIPH    0x800U      // Input Flag Clear for CMPSS6_CTRIPH Signal
#define XBAR_CLR1_CMPSS7_CTRIPL    0x1000U     // Input Flag Clear for CMPSS7_CTRIPL Signal
#define XBAR_CLR1_CMPSS7_CTRIPH    0x2000U     // Input Flag Clear for CMPSS7_CTRIPH Signal
#define XBAR_CLR1_CMPSS8_CTRIPL    0x4000U     // Input Flag Clear for CMPSS8_CTRIPL Signal
#define XBAR_CLR1_CMPSS8_CTRIPH    0x8000U     // Input Flag Clear for CMPSS8_CTRIPH Signal
#define XBAR_CLR1_CMPSS9_CTRIPH    0x10000U    // Input Flag Clear for CMPSS9_CTRIPH Signal
#define XBAR_CLR1_CMPSS9_CTRIPL    0x20000U    // Input Flag Clear for CMPSS9_CTRIPL Signal
#define XBAR_CLR1_CMPSS10_CTRIPH   0x40000U    // Input Flag Clear for CMPSS10_CTRIPH Signal
#define XBAR_CLR1_CMPSS10_CTRIPL   0x80000U    // Input Flag Clear for CMPSS10_CTRIPL Signal
#define XBAR_CLR1_CMPSS11_CTRIPH   0x100000U   // Input Flag Clear for CMPSS11_CTRIPH Signal
#define XBAR_CLR1_CMPSS11_CTRIPL   0x200000U   // Input Flag Clear for CMPSS11_CTRIPL Signal
#define XBAR_CLR1_CMPSS12_CTRIPH   0x400000U   // Input Flag Clear for CMPSS12_CTRIPH Signal
#define XBAR_CLR1_CMPSS12_CTRIPL   0x800000U   // Input Flag Clear for CMPSS12_CTRIPL Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR2 register
//
//*************************************************************************************************
#define XBAR_CLR2_CMPSS1_CTRIPOUTL    0x1U        // Input Flag clear for CMPSS1_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS1_CTRIPOUTH    0x2U        // Input Flag clear for CMPSS1_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS2_CTRIPOUTL    0x4U        // Input Flag clear for CMPSS2_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS2_CTRIPOUTH    0x8U        // Input Flag clear for CMPSS2_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS3_CTRIPOUTL    0x10U       // Input Flag clear for CMPSS3_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS3_CTRIPOUTH    0x20U       // Input Flag clear for CMPSS3_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS4_CTRIPOUTL    0x40U       // Input Flag clear for CMPSS4_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS4_CTRIPOUTH    0x80U       // Input Flag clear for CMPSS4_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS5_CTRIPOUTL    0x100U      // Input Flag clear for CMPSS5_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS5_CTRIPOUTH    0x200U      // Input Flag clear for CMPSS5_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS6_CTRIPOUTL    0x400U      // Input Flag clear for CMPSS6_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS6_CTRIPOUTH    0x800U      // Input Flag clear for CMPSS6_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS7_CTRIPOUTL    0x1000U     // Input Flag clear for CMPSS7_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS7_CTRIPOUTH    0x2000U     // Input Flag clear for CMPSS7_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS8_CTRIPOUTL    0x4000U     // Input Flag clear for CMPSS8_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS8_CTRIPOUTH    0x8000U     // Input Flag clear for CMPSS8_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS9_CTRIPOUTH    0x10000U    // Input Flag clear for CMPSS9_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS9_CTRIPOUTL    0x20000U    // Input Flag clear for CMPSS9_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS10_CTRIPOUTH   0x40000U    // Input Flag clear for CMPSS10_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS10_CTRIPOUTL   0x80000U    // Input Flag clear for CMPSS10_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS11_CTRIPOUTH   0x100000U   // Input Flag clear for CMPSS11_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS11_CTRIPOUTL   0x200000U   // Input Flag clear for CMPSS11_CTRIPOUTL Signal
#define XBAR_CLR2_CMPSS12_CTRIPOUTH   0x400000U   // Input Flag clear for CMPSS12_CTRIPOUTH Signal
#define XBAR_CLR2_CMPSS12_CTRIPOUTL   0x800000U   // Input Flag clear for CMPSS12_CTRIPOUTL Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR3 register
//
//*************************************************************************************************
#define XBAR_CLR3_SD1FLT1_COMPL   0x1U          // Input Flag Clear for SD1FLT1_COMPL Signal
#define XBAR_CLR3_SD1FLT1_COMPH   0x2U          // Input Flag Clear for SD1FLT1_COMPH Signal
#define XBAR_CLR3_SD1FLT2_COMPL   0x4U          // Input Flag Clear for SD1FLT2_COMPL Signal
#define XBAR_CLR3_SD1FLT2_COMPH   0x8U          // Input Flag Clear for SD1FLT2_COMPH Signal
#define XBAR_CLR3_SD1FLT3_COMPL   0x10U         // Input Flag Clear for SD1FLT3_COMPL Signal
#define XBAR_CLR3_SD1FLT3_COMPH   0x20U         // Input Flag Clear for SD1FLT3_COMPH Signal
#define XBAR_CLR3_SD1FLT4_COMPL   0x40U         // Input Flag Clear for SD1FLT4_COMPL Signal
#define XBAR_CLR3_SD1FLT4_COMPH   0x80U         // Input Flag Clear for SD1FLT4_COMPH Signal
#define XBAR_CLR3_SD2FLT1_COMPL   0x100U        // Input Flag Clear for SD2FLT1_COMPL Signal
#define XBAR_CLR3_SD2FLT1_COMPH   0x200U        // Input Flag Clear for SD2FLT1_COMPH Signal
#define XBAR_CLR3_SD2FLT2_COMPL   0x400U        // Input Flag Clear for SD2FLT2_COMPL Signal
#define XBAR_CLR3_SD2FLT2_COMPH   0x800U        // Input Flag Clear for SD2FLT2_COMPH Signal
#define XBAR_CLR3_SD2FLT3_COMPL   0x1000U       // Input Flag Clear for SD2FLT3_COMPL Signal
#define XBAR_CLR3_SD2FLT3_COMPH   0x2000U       // Input Flag Clear for SD2FLT3_COMPH Signal
#define XBAR_CLR3_SD2FLT4_COMPL   0x4000U       // Input Flag Clear for SD2FLT4_COMPL Signal
#define XBAR_CLR3_SD2FLT4_COMPH   0x8000U       // Input Flag Clear for SD2FLT4_COMPH Signal
#define XBAR_CLR3_SD3FLT1_COMPH   0x10000U      // Input Flag Clear for SD3FLT1_COMPH Signal
#define XBAR_CLR3_SD3FLT1_COMPL   0x20000U      // Input Flag Clear for SD3FLT1_COMPL Signal
#define XBAR_CLR3_SD3FLT2_COMPH   0x40000U      // Input Flag Clear for SD3FLT2_COMPH Signal
#define XBAR_CLR3_SD3FLT2_COMPL   0x80000U      // Input Flag Clear for SD3FLT2_COMPL Signal
#define XBAR_CLR3_SD3FLT3_COMPH   0x100000U     // Input Flag Clear for SD3FLT3_COMPH Signal
#define XBAR_CLR3_SD3FLT3_COMPL   0x200000U     // Input Flag Clear for SD3FLT3_COMPL Signal
#define XBAR_CLR3_SD3FLT4_COMPH   0x400000U     // Input Flag Clear for SD3FLT4_COMPH Signal
#define XBAR_CLR3_SD3FLT4_COMPL   0x800000U     // Input Flag Clear for SD3FLT4_COMPL Signal
#define XBAR_CLR3_SD4FLT1_COMPH   0x1000000U    // Input Flag Clear for SD4FLT1_COMPH Signal
#define XBAR_CLR3_SD4FLT1_COMPL   0x2000000U    // Input Flag Clear for SD4FLT1_COMPL Signal
#define XBAR_CLR3_SD4FLT2_COMPH   0x4000000U    // Input Flag Clear for SD4FLT2_COMPH Signal
#define XBAR_CLR3_SD4FLT2_COMPL   0x8000000U    // Input Flag Clear for SD4FLT2_COMPL Signal
#define XBAR_CLR3_SD4FLT3_COMPH   0x10000000U   // Input Flag Clear for SD4FLT3_COMPH Signal
#define XBAR_CLR3_SD4FLT3_COMPL   0x20000000U   // Input Flag Clear for SD4FLT3_COMPL Signal
#define XBAR_CLR3_SD4FLT4_COMPH   0x40000000U   // Input Flag Clear for SD4FLT4_COMPH Signal
#define XBAR_CLR3_SD4FLT4_COMPL   0x80000000U   // Input Flag Clear for SD4FLT4_COMPL Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR4 register
//
//*************************************************************************************************
#define XBAR_CLR4_INPUT1    0x1U          // Input Flag Clear for INPUT1 Signal
#define XBAR_CLR4_INPUT2    0x2U          // Input Flag Clear for INPUT2 Signal
#define XBAR_CLR4_INPUT3    0x4U          // Input Flag Clear for INPUT3 Signal
#define XBAR_CLR4_INPUT4    0x8U          // Input Flag Clear for INPUT4 Signal
#define XBAR_CLR4_INPUT5    0x10U         // Input Flag Clear for INPUT5 Signal
#define XBAR_CLR4_INPUT6    0x20U         // Input Flag Clear for INPUT6 Signal
#define XBAR_CLR4_INPUT7    0x40U         // Input Flag Clear for INPUT7 Signal
#define XBAR_CLR4_INPUT8    0x80U         // Input Flag Clear for INPUT8 Signal
#define XBAR_CLR4_INPUT9    0x100U        // Input Flag Clear for INPUT9 Signal
#define XBAR_CLR4_INPUT10   0x200U        // Input Flag Clear for INPUT10 Signal
#define XBAR_CLR4_INPUT11   0x400U        // Input Flag Clear for INPUT11 Signal
#define XBAR_CLR4_INPUT12   0x800U        // Input Flag Clear for INPUT12 Signal
#define XBAR_CLR4_INPUT13   0x1000U       // Input Flag Clear for INPUT13 Signal
#define XBAR_CLR4_INPUT14   0x2000U       // Input Flag Clear for INPUT14 Signal
#define XBAR_CLR4_INPUT15   0x4000U       // Input Flag Clear for INPUT15 Signal
#define XBAR_CLR4_INPUT16   0x8000U       // Input Flag Clear for INPUT16 Signal
#define XBAR_CLR4_INPUT17   0x10000U      // Input Flag Clear for INPUT17 Signal
#define XBAR_CLR4_INPUT18   0x20000U      // Input Flag Clear for INPUT18 Signal
#define XBAR_CLR4_INPUT19   0x40000U      // Input Flag Clear for INPUT19 Signal
#define XBAR_CLR4_INPUT20   0x80000U      // Input Flag Clear for INPUT20 Signal
#define XBAR_CLR4_INPUT21   0x100000U     // Input Flag Clear for INPUT21 Signal
#define XBAR_CLR4_INPUT22   0x200000U     // Input Flag Clear for INPUT22 Signal
#define XBAR_CLR4_INPUT23   0x400000U     // Input Flag Clear for INPUT23 Signal
#define XBAR_CLR4_INPUT24   0x800000U     // Input Flag Clear for INPUT24 Signal
#define XBAR_CLR4_INPUT25   0x1000000U    // Input Flag Clear for INPUT25 Signal
#define XBAR_CLR4_INPUT26   0x2000000U    // Input Flag Clear for INPUT26 Signal
#define XBAR_CLR4_INPUT27   0x4000000U    // Input Flag Clear for INPUT27 Signal
#define XBAR_CLR4_INPUT28   0x8000000U    // Input Flag Clear for INPUT28 Signal
#define XBAR_CLR4_INPUT29   0x10000000U   // Input Flag Clear for INPUT29 Signal
#define XBAR_CLR4_INPUT30   0x20000000U   // Input Flag Clear for INPUT30 Signal
#define XBAR_CLR4_INPUT31   0x40000000U   // Input Flag Clear for INPUT31 Signal
#define XBAR_CLR4_INPUT32   0x80000000U   // Input Flag Clear for INPUT32 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR5 register
//
//*************************************************************************************************
#define XBAR_CLR5_ADCAEVT1            0x1U          // Input Flag Clear for ADCAEVT1 Signal
#define XBAR_CLR5_ADCAEVT2            0x2U          // Input Flag Clear for ADCAEVT2 Signal
#define XBAR_CLR5_ADCAEVT3            0x4U          // Input Flag Clear for ADCAEVT3 Signal
#define XBAR_CLR5_ADCAEVT4            0x8U          // Input Flag Clear for ADCAEVT4 Signal
#define XBAR_CLR5_ADCBEVT1            0x10U         // Input Flag Clear for ADCBEVT1 Signal
#define XBAR_CLR5_ADCBEVT2            0x20U         // Input Flag Clear for ADCBEVT2 Signal
#define XBAR_CLR5_ADCBEVT3            0x40U         // Input Flag Clear for ADCBEVT3 Signal
#define XBAR_CLR5_ADCBEVT4            0x80U         // Input Flag Clear for ADCBEVT4 Signal
#define XBAR_CLR5_ADCCEVT1            0x100U        // Input Flag Clear for ADCCEVT1 Signal
#define XBAR_CLR5_ADCCEVT2            0x200U        // Input Flag Clear for ADCCEVT2 Signal
#define XBAR_CLR5_ADCCEVT3            0x400U        // Input Flag Clear for ADCCEVT3 Signal
#define XBAR_CLR5_ADCCEVT4            0x800U        // Input Flag Clear for ADCCEVT4 Signal
#define XBAR_CLR5_ADCDEVT1            0x1000U       // Input Flag Clear for ADCDEVT1 Signal
#define XBAR_CLR5_ADCDEVT2            0x2000U       // Input Flag Clear for ADCDEVT2 Signal
#define XBAR_CLR5_ADCDEVT3            0x4000U       // Input Flag Clear for ADCDEVT3 Signal
#define XBAR_CLR5_ADCDEVT4            0x8000U       // Input Flag Clear for ADCDEVT4 Signal
#define XBAR_CLR5_ADCEEVT1            0x10000U      // Input Flag Clear for ADCEEVT1 Signal
#define XBAR_CLR5_ADCEEVT2            0x20000U      // Input Flag Clear for ADCEEVT2 Signal
#define XBAR_CLR5_ADCEEVT3            0x40000U      // Input Flag Clear for ADCEEVT3 Signal
#define XBAR_CLR5_ADCEEVT4            0x80000U      // Input Flag Clear for ADCEEVT4 Signal
#define XBAR_CLR5_CPU1_ADCCHECKEVT1   0x100000U     // Input Flag Clear for CPU1_ADCCHECKEVT1
                                                    // Signal
#define XBAR_CLR5_CPU1_ADCCHECKEVT2   0x200000U     // Input Flag Clear for CPU1_ADCCHECKEVT2
                                                    // Signal
#define XBAR_CLR5_CPU1_ADCCHECKEVT3   0x400000U     // Input Flag Clear for CPU1_ADCCHECKEVT3
                                                    // Signal
#define XBAR_CLR5_CPU1_ADCCHECKEVT4   0x800000U     // Input Flag Clear for CPU1_ADCCHECKEVT4
                                                    // Signal
#define XBAR_CLR5_CPU2_ADCCHECKEVT1   0x1000000U    // Input Flag Clear for CPU2_ADCCHECKEVT1
                                                    // Signal
#define XBAR_CLR5_CPU2_ADCCHECKEVT2   0x2000000U    // Input Flag Clear for CPU2_ADCCHECKEVT2
                                                    // Signal
#define XBAR_CLR5_CPU2_ADCCHECKEVT3   0x4000000U    // Input Flag Clear for CPU2_ADCCHECKEVT3
                                                    // Signal
#define XBAR_CLR5_CPU2_ADCCHECKEVT4   0x8000000U    // Input Flag Clear for CPU2_ADCCHECKEVT4
                                                    // Signal
#define XBAR_CLR5_CPU3_ADCCHECKEVT1   0x10000000U   // Input Flag Clear for CPU3_ADCCHECKEVT1
                                                    // Signal
#define XBAR_CLR5_CPU3_ADCCHECKEVT2   0x20000000U   // Input Flag Clear for CPU3_ADCCHECKEVT2
                                                    // Signal
#define XBAR_CLR5_CPU3_ADCCHECKEVT3   0x40000000U   // Input Flag Clear for CPU3_ADCCHECKEVT3
                                                    // Signal
#define XBAR_CLR5_CPU3_ADCCHECKEVT4   0x80000000U   // Input Flag Clear for CPU3_ADCCHECKEVT4
                                                    // Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR6 register
//
//*************************************************************************************************
#define XBAR_CLR6_CLB1_OUT4       0x1U          // Input Flag Clear for CLB1_OUT4 Signal
#define XBAR_CLR6_CLB1_OUT5       0x2U          // Input Flag Clear for CLB1_OUT5 Signal
#define XBAR_CLR6_CLB2_OUT4       0x4U          // Input Flag Clear for CLB2_OUT4 Signal
#define XBAR_CLR6_CLB2_OUT5       0x8U          // Input Flag Clear for CLB2_OUT5 Signal
#define XBAR_CLR6_CLB3_OUT4       0x10U         // Input Flag Clear for CLB3_OUT4 Signal
#define XBAR_CLR6_CLB3_OUT5       0x20U         // Input Flag Clear for CLB3_OUT5 Signal
#define XBAR_CLR6_CLB4_OUT4       0x40U         // Input Flag Clear for CLB4_OUT4 Signal
#define XBAR_CLR6_CLB4_OUT5       0x80U         // Input Flag Clear for CLB4_OUT5 Signal
#define XBAR_CLR6_CLB5_OUT4       0x100U        // Input Flag Clear for CLB5_OUT4 Signal
#define XBAR_CLR6_CLB5_OUT5       0x200U        // Input Flag Clear for CLB5_OUT5 Signal
#define XBAR_CLR6_CLB6_OUT4       0x400U        // Input Flag Clear for CLB6_OUT4 Signal
#define XBAR_CLR6_CLB6_OUT5       0x800U        // Input Flag Clear for CLB6_OUT5 Signal
#define XBAR_CLR6_FSIA_RX_TRIG1   0x10000U      // Input Flag Clear for FSIA_RX_TRIG1 Signal
#define XBAR_CLR6_FSIB_RX_TRIG1   0x20000U      // Input Flag Clear for FSIB_RX_TRIG1 Signal
#define XBAR_CLR6_FSIC_RX_TRIG1   0x40000U      // Input Flag Clear for FSIC_RX_TRIG1 Signal
#define XBAR_CLR6_FSID_RX_TRIG1   0x80000U      // Input Flag Clear for FSID_RX_TRIG1 Signal
#define XBAR_CLR6_WADI1OUT0       0x400000U     // Input Flag Clear for WADI1OUT0 Signal
#define XBAR_CLR6_WADI1OUT1       0x800000U     // Input Flag Clear for WADI1OUT1 Signal
#define XBAR_CLR6_WADI1OUT2       0x1000000U    // Input Flag Clear for WADI1OUT2 Signal
#define XBAR_CLR6_WADI1OUT3       0x2000000U    // Input Flag Clear for WADI1OUT3 Signal
#define XBAR_CLR6_WADI1OUT4       0x4000000U    // Input Flag Clear for WADI1OUT4 Signal
#define XBAR_CLR6_WADI1OUT5       0x8000000U    // Input Flag Clear for WADI1OUT5 Signal
#define XBAR_CLR6_WADI1OUT6       0x10000000U   // Input Flag Clear for WADI1OUT6 Signal
#define XBAR_CLR6_WADI1OUT7       0x20000000U   // Input Flag Clear for WADI1OUT7 Signal
#define XBAR_CLR6_ECATSYNC0       0x40000000U   // Input Flag Clear for ECATSYNC0 Signal
#define XBAR_CLR6_ECATSYNC1       0x80000000U   // Input Flag Clear for ECATSYNC1 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR7 register
//
//*************************************************************************************************
#define XBAR_CLR7_ECAP1_OUT       0x1U          // Input Flag Clear for ECAP1_OUT Signal
#define XBAR_CLR7_ECAP2_OUT       0x2U          // Input Flag Clear for ECAP2_OUT Signal
#define XBAR_CLR7_ECAP3_OUT       0x4U          // Input Flag Clear for ECAP3_OUT Signal
#define XBAR_CLR7_ECAP4_OUT       0x8U          // Input Flag Clear for ECAP4_OUT Signal
#define XBAR_CLR7_ECAP5_OUT       0x10U         // Input Flag Clear for ECAP5_OUT Signal
#define XBAR_CLR7_ECAP6_OUT       0x20U         // Input Flag Clear for ECAP6_OUT Signal
#define XBAR_CLR7_ECAP1_TRIPOUT   0x100U        // Input Flag Clear for ECAP1_TRIPOUT Signal
#define XBAR_CLR7_ECAP2_TRIPOUT   0x200U        // Input Flag Clear for ECAP2_TRIPOUT Signal
#define XBAR_CLR7_ECAP3_TRIPOUT   0x400U        // Input Flag Clear for ECAP3_TRIPOUT Signal
#define XBAR_CLR7_ECAP4_TRIPOUT   0x800U        // Input Flag Clear for ECAP4_TRIPOUT Signal
#define XBAR_CLR7_ECAP5_TRIPOUT   0x1000U       // Input Flag Clear for ECAP5_TRIPOUT Signal
#define XBAR_CLR7_ECAP6_TRIPOUT   0x2000U       // Input Flag Clear for ECAP6_TRIPOUT Signal
#define XBAR_CLR7_ADCSOCA         0x10000U      // Input Flag Clear for ADCSOCA Signal
#define XBAR_CLR7_ADCSOCB         0x20000U      // Input Flag Clear for ADCSOCB Signal
#define XBAR_CLR7_ESMGENEVT       0x40000U      // Input Flag Clear for ESMGENEVT Signal
#define XBAR_CLR7_EXTSYNCOUT      0x80000U      // Input Flag Clear for EXTSYNCOUT Signal
#define XBAR_CLR7_WADI2OUT0       0x1000000U    // Input Flag Clear for WADI2OUT0 Signal
#define XBAR_CLR7_WADI2OUT1       0x2000000U    // Input Flag Clear for WADI2OUT1 Signal
#define XBAR_CLR7_WADI2OUT2       0x4000000U    // Input Flag Clear for WADI2OUT2 Signal
#define XBAR_CLR7_WADI2OUT3       0x8000000U    // Input Flag Clear for WADI2OUT3 Signal
#define XBAR_CLR7_WADI2OUT4       0x10000000U   // Input Flag Clear for WADI2OUT4 Signal
#define XBAR_CLR7_WADI2OUT5       0x20000000U   // Input Flag Clear for WADI2OUT5 Signal
#define XBAR_CLR7_WADI2OUT6       0x40000000U   // Input Flag Clear for WADI2OUT6 Signal
#define XBAR_CLR7_WADI2OUT7       0x80000000U   // Input Flag Clear for WADI2OUT7 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR8 register
//
//*************************************************************************************************
#define XBAR_CLR8_EPWM1_TRIPOUT    0x1U       // Input Flag clear for EPWM1_TRIPOUT Signal
#define XBAR_CLR8_EPWM2_TRIPOUT    0x2U       // Input Flag clear for EPWM2_TRIPOUT Signal
#define XBAR_CLR8_EPWM3_TRIPOUT    0x4U       // Input Flag clear for EPWM3_TRIPOUT Signal
#define XBAR_CLR8_EPWM4_TRIPOUT    0x8U       // Input Flag clear for EPWM4_TRIPOUT Signal
#define XBAR_CLR8_EPWM5_TRIPOUT    0x10U      // Input Flag clear for EPWM5_TRIPOUT Signal
#define XBAR_CLR8_EPWM6_TRIPOUT    0x20U      // Input Flag clear for EPWM6_TRIPOUT Signal
#define XBAR_CLR8_EPWM7_TRIPOUT    0x40U      // Input Flag clear for EPWM7_TRIPOUT Signal
#define XBAR_CLR8_EPWM8_TRIPOUT    0x80U      // Input Flag clear for EPWM8_TRIPOUT Signal
#define XBAR_CLR8_EPWM9_TRIPOUT    0x100U     // Input Flag clear for EPWM9_TRIPOUT Signal
#define XBAR_CLR8_EPWM10_TRIPOUT   0x200U     // Input Flag clear for EPWM10_TRIPOUT Signal
#define XBAR_CLR8_EPWM11_TRIPOUT   0x400U     // Input Flag clear for EPWM11_TRIPOUT Signal
#define XBAR_CLR8_EPWM12_TRIPOUT   0x800U     // Input Flag clear for EPWM12_TRIPOUT Signal
#define XBAR_CLR8_EPWM13_TRIPOUT   0x1000U    // Input Flag clear for EPWM13_TRIPOUT Signal
#define XBAR_CLR8_EPWM14_TRIPOUT   0x2000U    // Input Flag clear for EPWM14_TRIPOUT Signal
#define XBAR_CLR8_EPWM15_TRIPOUT   0x4000U    // Input Flag clear for EPWM15_TRIPOUT Signal
#define XBAR_CLR8_EPWM16_TRIPOUT   0x8000U    // Input Flag clear for EPWM16_TRIPOUT Signal
#define XBAR_CLR8_EPWM17_TRIPOUT   0x10000U   // Input Flag clear for EPWM17_TRIPOUT Signal
#define XBAR_CLR8_EPWM18_TRIPOUT   0x20000U   // Input Flag clear for EPWM18_TRIPOUT Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR9 register
//
//*************************************************************************************************
#define XBAR_CLR9_EPWM1_DEL_TRIP    0x1U       // Input Flag clear for EPWM1_DEL_TRIP Signal
#define XBAR_CLR9_EPWM2_DEL_TRIP    0x2U       // Input Flag clear for EPWM2_DEL_TRIP Signal
#define XBAR_CLR9_EPWM3_DEL_TRIP    0x4U       // Input Flag clear for EPWM3_DEL_TRIP Signal
#define XBAR_CLR9_EPWM4_DEL_TRIP    0x8U       // Input Flag clear for EPWM4_DEL_TRIP Signal
#define XBAR_CLR9_EPWM5_DEL_TRIP    0x10U      // Input Flag clear for EPWM5_DEL_TRIP Signal
#define XBAR_CLR9_EPWM6_DEL_TRIP    0x20U      // Input Flag clear for EPWM6_DEL_TRIP Signal
#define XBAR_CLR9_EPWM7_DEL_TRIP    0x40U      // Input Flag clear for EPWM7_DEL_TRIP Signal
#define XBAR_CLR9_EPWM8_DEL_TRIP    0x80U      // Input Flag clear for EPWM8_DEL_TRIP Signal
#define XBAR_CLR9_EPWM9_DEL_TRIP    0x100U     // Input Flag clear for EPWM9_DEL_TRIP Signal
#define XBAR_CLR9_EPWM10_DEL_TRIP   0x200U     // Input Flag clear for EPWM10_DEL_TRIP Signal
#define XBAR_CLR9_EPWM11_DEL_TRIP   0x400U     // Input Flag clear for EPWM11_DEL_TRIP Signal
#define XBAR_CLR9_EPWM12_DEL_TRIP   0x800U     // Input Flag clear for EPWM12_DEL_TRIP Signal
#define XBAR_CLR9_EPWM13_DEL_TRIP   0x1000U    // Input Flag clear for EPWM13_DEL_TRIP Signal
#define XBAR_CLR9_EPWM14_DEL_TRIP   0x2000U    // Input Flag clear for EPWM14_DEL_TRIP Signal
#define XBAR_CLR9_EPWM15_DEL_TRIP   0x4000U    // Input Flag clear for EPWM15_DEL_TRIP Signal
#define XBAR_CLR9_EPWM16_DEL_TRIP   0x8000U    // Input Flag clear for EPWM16_DEL_TRIP Signal
#define XBAR_CLR9_EPWM17_DEL_TRIP   0x10000U   // Input Flag clear for EPWM17_DEL_TRIP Signal
#define XBAR_CLR9_EPWM18_DEL_TRIP   0x20000U   // Input Flag clear for EPWM18_DEL_TRIP Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR10 register
//
//*************************************************************************************************
#define XBAR_CLR10_EPWM1_DEL_ACTIVE    0x1U       // Input Flag clear for EPWM1_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM2_DEL_ACTIVE    0x2U       // Input Flag clear for EPWM2_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM3_DEL_ACTIVE    0x4U       // Input Flag clear for EPWM3_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM4_DEL_ACTIVE    0x8U       // Input Flag clear for EPWM4_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM5_DEL_ACTIVE    0x10U      // Input Flag clear for EPWM5_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM6_DEL_ACTIVE    0x20U      // Input Flag clear for EPWM6_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM7_DEL_ACTIVE    0x40U      // Input Flag clear for EPWM7_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM8_DEL_ACTIVE    0x80U      // Input Flag clear for EPWM8_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM9_DEL_ACTIVE    0x100U     // Input Flag clear for EPWM9_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM10_DEL_ACTIVE   0x200U     // Input Flag clear for EPWM10_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM11_DEL_ACTIVE   0x400U     // Input Flag clear for EPWM11_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM12_DEL_ACTIVE   0x800U     // Input Flag clear for EPWM12_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM13_DEL_ACTIVE   0x1000U    // Input Flag clear for EPWM13_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM14_DEL_ACTIVE   0x2000U    // Input Flag clear for EPWM14_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM15_DEL_ACTIVE   0x4000U    // Input Flag clear for EPWM15_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM16_DEL_ACTIVE   0x8000U    // Input Flag clear for EPWM16_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM17_DEL_ACTIVE   0x10000U   // Input Flag clear for EPWM17_DEL_ACTIVE Signal
#define XBAR_CLR10_EPWM18_DEL_ACTIVE   0x20000U   // Input Flag clear for EPWM18_DEL_ACTIVE Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR11 register
//
//*************************************************************************************************
#define XBAR_CLR11_EPWM1_A0_SCLK    0x1U          // Input Flag clear for EPWM1_A0_sclk Signal
#define XBAR_CLR11_EPWM1_B0_SCLK    0x2U          // Input Flag clear for EPWM1_B0_sclk Signal
#define XBAR_CLR11_EPWM2_A0_SCLK    0x4U          // Input Flag clear for EPWM2_A0_sclk Signal
#define XBAR_CLR11_EPWM2_B0_SCLK    0x8U          // Input Flag clear for EPWM2_B0_sclk Signal
#define XBAR_CLR11_EPWM3_A0_SCLK    0x10U         // Input Flag clear for EPWM3_A0_sclk Signal
#define XBAR_CLR11_EPWM3_B0_SCLK    0x20U         // Input Flag clear for EPWM3_B0_sclk Signal
#define XBAR_CLR11_EPWM4_A0_SCLK    0x40U         // Input Flag clear for EPWM4_A0_sclk Signal
#define XBAR_CLR11_EPWM4_B0_SCLK    0x80U         // Input Flag clear for EPWM4_B0_sclk Signal
#define XBAR_CLR11_EPWM5_A0_SCLK    0x100U        // Input Flag clear for EPWM5_A0_sclk Signal
#define XBAR_CLR11_EPWM5_B0_SCLK    0x200U        // Input Flag clear for EPWM5_B0_sclk Signal
#define XBAR_CLR11_EPWM6_A0_SCLK    0x400U        // Input Flag clear for EPWM6_A0_sclk Signal
#define XBAR_CLR11_EPWM6_B0_SCLK    0x800U        // Input Flag clear for EPWM6_B0_sclk Signal
#define XBAR_CLR11_EPWM7_A0_SCLK    0x1000U       // Input Flag clear for EPWM7_A0_sclk Signal
#define XBAR_CLR11_EPWM7_B0_SCLK    0x2000U       // Input Flag clear for EPWM7_B0_sclk Signal
#define XBAR_CLR11_EPWM8_A0_SCLK    0x4000U       // Input Flag clear for EPWM8_A0_sclk Signal
#define XBAR_CLR11_EPWM8_B0_SCLK    0x8000U       // Input Flag clear for EPWM8_B0_sclk Signal
#define XBAR_CLR11_EPWM9_A0_SCLK    0x10000U      // Input Flag clear for EPWM9_A0_sclk Signal
#define XBAR_CLR11_EPWM9_B0_SCLK    0x20000U      // Input Flag clear for EPWM9_B0_sclk Signal
#define XBAR_CLR11_EPWM10_A0_SCLK   0x40000U      // Input Flag clear for EPWM10_A0_sclk Signal
#define XBAR_CLR11_EPWM10_B0_SCLK   0x80000U      // Input Flag clear for EPWM10_B0_sclk Signal
#define XBAR_CLR11_EPWM11_A0_SCLK   0x100000U     // Input Flag clear for EPWM11_A0_sclk Signal
#define XBAR_CLR11_EPWM11_B0_SCLK   0x200000U     // Input Flag clear for EPWM11_B0_sclk Signal
#define XBAR_CLR11_EPWM12_A0_SCLK   0x400000U     // Input Flag clear for EPWM12_A0_sclk Signal
#define XBAR_CLR11_EPWM12_B0_SCLK   0x800000U     // Input Flag clear for EPWM12_B0_sclk Signal
#define XBAR_CLR11_EPWM13_A0_SCLK   0x1000000U    // Input Flag clear for EPWM13_A0_sclk Signal
#define XBAR_CLR11_EPWM13_B0_SCLK   0x2000000U    // Input Flag clear for EPWM13_B0_sclk Signal
#define XBAR_CLR11_EPWM14_A0_SCLK   0x4000000U    // Input Flag clear for EPWM14_A0_sclk Signal
#define XBAR_CLR11_EPWM14_B0_SCLK   0x8000000U    // Input Flag clear for EPWM14_B0_sclk Signal
#define XBAR_CLR11_EPWM15_A0_SCLK   0x10000000U   // Input Flag clear for EPWM15_A0_sclk Signal
#define XBAR_CLR11_EPWM15_B0_SCLK   0x20000000U   // Input Flag clear for EPWM15_B0_sclk Signal
#define XBAR_CLR11_EPWM16_A0_SCLK   0x40000000U   // Input Flag clear for EPWM16_A0_sclk Signal
#define XBAR_CLR11_EPWM16_B0_SCLK   0x80000000U   // Input Flag clear for EPWM16_B0_sclk Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR12 register
//
//*************************************************************************************************
#define XBAR_CLR12_EPWM17_A0_SCLK   0x1U   // Input Flag clear for EPWM17_A0_sclk Signal
#define XBAR_CLR12_EPWM17_B0_SCLK   0x2U   // Input Flag clear for EPWM17_B0_sclk Signal
#define XBAR_CLR12_EPWM18_A0_SCLK   0x4U   // Input Flag clear for EPWM18_A0_sclk Signal
#define XBAR_CLR12_EPWM18_B0_SCLK   0x8U   // Input Flag clear for EPWM18_B0_sclk Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR13 register
//
//*************************************************************************************************
#define XBAR_CLR13_MDL1_OUTA    0x1U          // Input Flag clear for MDL1_OUTA Signal
#define XBAR_CLR13_MDL1_OUTB    0x2U          // Input Flag clear for MDL1_OUTB Signal
#define XBAR_CLR13_MDL2_OUTA    0x4U          // Input Flag clear for MDL2_OUTA Signal
#define XBAR_CLR13_MDL2_OUTB    0x8U          // Input Flag clear for MDL2_OUTB Signal
#define XBAR_CLR13_MDL3_OUTA    0x10U         // Input Flag clear for MDL3_OUTA Signal
#define XBAR_CLR13_MDL3_OUTB    0x20U         // Input Flag clear for MDL3_OUTB Signal
#define XBAR_CLR13_MDL4_OUTA    0x40U         // Input Flag clear for MDL4_OUTA Signal
#define XBAR_CLR13_MDL4_OUTB    0x80U         // Input Flag clear for MDL4_OUTB Signal
#define XBAR_CLR13_MDL5_OUTA    0x100U        // Input Flag clear for MDL5_OUTA Signal
#define XBAR_CLR13_MDL5_OUTB    0x200U        // Input Flag clear for MDL5_OUTB Signal
#define XBAR_CLR13_MDL6_OUTA    0x400U        // Input Flag clear for MDL6_OUTA Signal
#define XBAR_CLR13_MDL6_OUTB    0x800U        // Input Flag clear for MDL6_OUTB Signal
#define XBAR_CLR13_MDL7_OUTA    0x1000U       // Input Flag clear for MDL7_OUTA Signal
#define XBAR_CLR13_MDL7_OUTB    0x2000U       // Input Flag clear for MDL7_OUTB Signal
#define XBAR_CLR13_MDL8_OUTA    0x4000U       // Input Flag clear for MDL8_OUTA Signal
#define XBAR_CLR13_MDL8_OUTB    0x8000U       // Input Flag clear for MDL8_OUTB Signal
#define XBAR_CLR13_MDL9_OUTA    0x10000U      // Input Flag clear for MDL9_OUTA Signal
#define XBAR_CLR13_MDL9_OUTB    0x20000U      // Input Flag clear for MDL9_OUTB Signal
#define XBAR_CLR13_MDL10_OUTA   0x40000U      // Input Flag clear for MDL10_OUTA Signal
#define XBAR_CLR13_MDL10_OUTB   0x80000U      // Input Flag clear for MDL10_OUTB Signal
#define XBAR_CLR13_MDL11_OUTA   0x100000U     // Input Flag clear for MDL11_OUTA Signal
#define XBAR_CLR13_MDL11_OUTB   0x200000U     // Input Flag clear for MDL11_OUTB Signal
#define XBAR_CLR13_MDL12_OUTA   0x400000U     // Input Flag clear for MDL12_OUTA Signal
#define XBAR_CLR13_MDL12_OUTB   0x800000U     // Input Flag clear for MDL12_OUTB Signal
#define XBAR_CLR13_MDL13_OUTA   0x1000000U    // Input Flag clear for MDL13_OUTA Signal
#define XBAR_CLR13_MDL13_OUTB   0x2000000U    // Input Flag clear for MDL13_OUTB Signal
#define XBAR_CLR13_MDL14_OUTA   0x4000000U    // Input Flag clear for MDL14_OUTA Signal
#define XBAR_CLR13_MDL14_OUTB   0x8000000U    // Input Flag clear for MDL14_OUTB Signal
#define XBAR_CLR13_MDL15_OUTA   0x10000000U   // Input Flag clear for MDL15_OUTA Signal
#define XBAR_CLR13_MDL15_OUTB   0x20000000U   // Input Flag clear for MDL15_OUTB Signal
#define XBAR_CLR13_MDL16_OUTA   0x40000000U   // Input Flag clear for MDL16_OUTA Signal
#define XBAR_CLR13_MDL16_OUTB   0x80000000U   // Input Flag clear for MDL16_OUTB Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR14 register
//
//*************************************************************************************************
#define XBAR_CLR14_MDL17_OUTA   0x1U   // Input Flag clear for MDL17_OUTA Signal
#define XBAR_CLR14_MDL17_OUTB   0x2U   // Input Flag clear for MDL17_OUTB Signal
#define XBAR_CLR14_MDL18_OUTA   0x4U   // Input Flag clear for MDL18_OUTA Signal
#define XBAR_CLR14_MDL18_OUTB   0x8U   // Input Flag clear for MDL18_OUTB Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR15 register
//
//*************************************************************************************************
#define XBAR_CLR15_CLB1_OUT0   0x1U          // Input Flag clear for CLB1_OUT0 Signal
#define XBAR_CLR15_CLB1_OUT1   0x2U          // Input Flag clear for CLB1_OUT1 Signal
#define XBAR_CLR15_CLB1_OUT2   0x4U          // Input Flag clear for CLB1_OUT2 Signal
#define XBAR_CLR15_CLB1_OUT3   0x8U          // Input Flag clear for CLB1_OUT3 Signal
#define XBAR_CLR15_CLB1_OUT6   0x10U         // Input Flag clear for CLB1_OUT6 Signal
#define XBAR_CLR15_CLB1_OUT7   0x20U         // Input Flag clear for CLB1_OUT7 Signal
#define XBAR_CLR15_CLB2_OUT0   0x40U         // Input Flag clear for CLB2_OUT0 Signal
#define XBAR_CLR15_CLB2_OUT1   0x80U         // Input Flag clear for CLB2_OUT1 Signal
#define XBAR_CLR15_CLB2_OUT2   0x100U        // Input Flag clear for CLB2_OUT2 Signal
#define XBAR_CLR15_CLB2_OUT3   0x200U        // Input Flag clear for CLB2_OUT3 Signal
#define XBAR_CLR15_CLB2_OUT6   0x400U        // Input Flag clear for CLB2_OUT6 Signal
#define XBAR_CLR15_CLB2_OUT7   0x800U        // Input Flag clear for CLB2_OUT7 Signal
#define XBAR_CLR15_CLB3_OUT0   0x1000U       // Input Flag clear for CLB3_OUT0 Signal
#define XBAR_CLR15_CLB3_OUT1   0x2000U       // Input Flag clear for CLB3_OUT1 Signal
#define XBAR_CLR15_CLB3_OUT2   0x4000U       // Input Flag clear for CLB3_OUT2 Signal
#define XBAR_CLR15_CLB3_OUT3   0x8000U       // Input Flag clear for CLB3_OUT3 Signal
#define XBAR_CLR15_CLB3_OUT6   0x10000U      // Input Flag clear for CLB3_OUT6 Signal
#define XBAR_CLR15_CLB3_OUT7   0x20000U      // Input Flag clear for CLB3_OUT7 Signal
#define XBAR_CLR15_CLB4_OUT0   0x40000U      // Input Flag clear for CLB4_OUT0 Signal
#define XBAR_CLR15_CLB4_OUT1   0x80000U      // Input Flag clear for CLB4_OUT1 Signal
#define XBAR_CLR15_CLB4_OUT2   0x100000U     // Input Flag clear for CLB4_OUT2 Signal
#define XBAR_CLR15_CLB4_OUT3   0x200000U     // Input Flag clear for CLB4_OUT3 Signal
#define XBAR_CLR15_CLB4_OUT6   0x400000U     // Input Flag clear for CLB4_OUT6 Signal
#define XBAR_CLR15_CLB4_OUT7   0x800000U     // Input Flag clear for CLB4_OUT7 Signal
#define XBAR_CLR15_CLB5_OUT0   0x1000000U    // Input Flag clear for CLB5_OUT0 Signal
#define XBAR_CLR15_CLB5_OUT1   0x2000000U    // Input Flag clear for CLB5_OUT1 Signal
#define XBAR_CLR15_CLB5_OUT2   0x4000000U    // Input Flag clear for CLB5_OUT2 Signal
#define XBAR_CLR15_CLB5_OUT3   0x8000000U    // Input Flag clear for CLB5_OUT3 Signal
#define XBAR_CLR15_CLB5_OUT6   0x10000000U   // Input Flag clear for CLB5_OUT6 Signal
#define XBAR_CLR15_CLB5_OUT7   0x20000000U   // Input Flag clear for CLB5_OUT7 Signal
#define XBAR_CLR15_CLB6_OUT0   0x40000000U   // Input Flag clear for CLB6_OUT0 Signal
#define XBAR_CLR15_CLB6_OUT1   0x80000000U   // Input Flag clear for CLB6_OUT1 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR16 register
//
//*************************************************************************************************
#define XBAR_CLR16_CLB6_OUT2         0x1U          // Input Flag clear for CLB6_OUT2 Signal
#define XBAR_CLR16_CLB6_OUT3         0x2U          // Input Flag clear for CLB6_OUT3 Signal
#define XBAR_CLR16_CLB6_OUT6         0x4U          // Input Flag clear for CLB6_OUT6 Signal
#define XBAR_CLR16_CLB6_OUT7         0x8U          // Input Flag clear for CLB6_OUT7 Signal
#define XBAR_CLR16_ADCA_EXTMUXSEL0   0x10U         // Input Flag clear for ADCA_EXTMUXSEL0 Signal
#define XBAR_CLR16_ADCA_EXTMUXSEL1   0x20U         // Input Flag clear for ADCA_EXTMUXSEL1 Signal
#define XBAR_CLR16_ADCA_EXTMUXSEL2   0x40U         // Input Flag clear for ADCA_EXTMUXSEL2 Signal
#define XBAR_CLR16_ADCA_EXTMUXSEL3   0x80U         // Input Flag clear for ADCA_EXTMUXSEL3 Signal
#define XBAR_CLR16_ADCB_EXTMUXSEL0   0x100U        // Input Flag clear for ADCB_EXTMUXSEL0 Signal
#define XBAR_CLR16_ADCB_EXTMUXSEL1   0x200U        // Input Flag clear for ADCB_EXTMUXSEL1 Signal
#define XBAR_CLR16_ADCB_EXTMUXSEL2   0x400U        // Input Flag clear for ADCB_EXTMUXSEL2 Signal
#define XBAR_CLR16_ADCB_EXTMUXSEL3   0x800U        // Input Flag clear for ADCB_EXTMUXSEL3 Signal
#define XBAR_CLR16_ADCC_EXTMUXSEL0   0x1000U       // Input Flag clear for ADCC_EXTMUXSEL0 Signal
#define XBAR_CLR16_ADCC_EXTMUXSEL1   0x2000U       // Input Flag clear for ADCC_EXTMUXSEL1 Signal
#define XBAR_CLR16_ADCC_EXTMUXSEL2   0x4000U       // Input Flag clear for ADCC_EXTMUXSEL2 Signal
#define XBAR_CLR16_ADCC_EXTMUXSEL3   0x8000U       // Input Flag clear for ADCC_EXTMUXSEL3 Signal
#define XBAR_CLR16_ADCD_EXTMUXSEL0   0x10000U      // Input Flag clear for ADCD_EXTMUXSEL0 Signal
#define XBAR_CLR16_ADCD_EXTMUXSEL1   0x20000U      // Input Flag clear for ADCD_EXTMUXSEL1 Signal
#define XBAR_CLR16_ADCD_EXTMUXSEL2   0x40000U      // Input Flag clear for ADCD_EXTMUXSEL2 Signal
#define XBAR_CLR16_ADCD_EXTMUXSEL3   0x80000U      // Input Flag clear for ADCD_EXTMUXSEL3 Signal
#define XBAR_CLR16_ADCE_EXTMUXSEL0   0x100000U     // Input Flag clear for ADCE_EXTMUXSEL0 Signal
#define XBAR_CLR16_ADCE_EXTMUXSEL1   0x200000U     // Input Flag clear for ADCE_EXTMUXSEL1 Signal
#define XBAR_CLR16_ADCE_EXTMUXSEL2   0x400000U     // Input Flag clear for ADCE_EXTMUXSEL2 Signal
#define XBAR_CLR16_ADCE_EXTMUXSEL3   0x800000U     // Input Flag clear for ADCE_EXTMUXSEL3 Signal
#define XBAR_CLR16_EPG1_EPGOUT0      0x10000000U   // Input Flag clear for EPG1_EPGOUT0 Signal
#define XBAR_CLR16_EPG1_EPGOUT1      0x20000000U   // Input Flag clear for EPG1_EPGOUT1 Signal
#define XBAR_CLR16_EPG1_EPGOUT2      0x40000000U   // Input Flag clear for EPG1_EPGOUT2 Signal
#define XBAR_CLR16_EPG1_EPGOUT3      0x80000000U   // Input Flag clear for EPG1_EPGOUT3 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR17 register
//
//*************************************************************************************************
#define XBAR_CLR17_MCANA_FEVT0   0x1U       // Input Flag clear for MCANA_FEVT0 Signal
#define XBAR_CLR17_MCANA_FEVT1   0x2U       // Input Flag clear for MCANA_FEVT1 Signal
#define XBAR_CLR17_MCANA_FEVT2   0x4U       // Input Flag clear for MCANA_FEVT2 Signal
#define XBAR_CLR17_MCANB_FEVT0   0x8U       // Input Flag clear for MCANB_FEVT0 Signal
#define XBAR_CLR17_MCANB_FEVT1   0x10U      // Input Flag clear for MCANB_FEVT1 Signal
#define XBAR_CLR17_MCANB_FEVT2   0x20U      // Input Flag clear for MCANB_FEVT2 Signal
#define XBAR_CLR17_MCANC_FEVT0   0x40U      // Input Flag clear for MCANC_FEVT0 Signal
#define XBAR_CLR17_MCANC_FEVT1   0x80U      // Input Flag clear for MCANC_FEVT1 Signal
#define XBAR_CLR17_MCANC_FEVT2   0x100U     // Input Flag clear for MCANC_FEVT2 Signal
#define XBAR_CLR17_MCAND_FEVT0   0x200U     // Input Flag clear for MCAND_FEVT0 Signal
#define XBAR_CLR17_MCAND_FEVT1   0x400U     // Input Flag clear for MCAND_FEVT1 Signal
#define XBAR_CLR17_MCAND_FEVT2   0x800U     // Input Flag clear for MCAND_FEVT2 Signal
#define XBAR_CLR17_MCANE_FEVT0   0x1000U    // Input Flag clear for MCANE_FEVT0 Signal
#define XBAR_CLR17_MCANE_FEVT1   0x2000U    // Input Flag clear for MCANE_FEVT1 Signal
#define XBAR_CLR17_MCANE_FEVT2   0x4000U    // Input Flag clear for MCANE_FEVT2 Signal
#define XBAR_CLR17_MCANF_FEVT0   0x8000U    // Input Flag clear for MCANF_FEVT0 Signal
#define XBAR_CLR17_MCANF_FEVT1   0x10000U   // Input Flag clear for MCANF_FEVT1 Signal
#define XBAR_CLR17_MCANF_FEVT2   0x20000U   // Input Flag clear for MCANF_FEVT2 Signal

//*************************************************************************************************
//
// The following are defines for the bit fields in the XBARCLR18 register
//
//*************************************************************************************************
#define XBAR_CLR18_FSIRXA_TRIG_2   0x1U       // Input Flag clear for FSIRXA_TRIG_2 Signal
#define XBAR_CLR18_FSIRXA_TRIG_3   0x2U       // Input Flag clear for FSIRXA_TRIG_3 Signal
#define XBAR_CLR18_FSIRXB_TRIG_2   0x4U       // Input Flag clear for FSIRXB_TRIG_2 Signal
#define XBAR_CLR18_FSIRXB_TRIG_3   0x8U       // Input Flag clear for FSIRXB_TRIG_3 Signal
#define XBAR_CLR18_FSIRXC_TRIG_2   0x10U      // Input Flag clear for FSIRXC_TRIG_2 Signal
#define XBAR_CLR18_FSIRXC_TRIG_3   0x20U      // Input Flag clear for FSIRXC_TRIG_3 Signal
#define XBAR_CLR18_FSIRXD_TRIG_2   0x40U      // Input Flag clear for FSIRXD_TRIG_2 Signal
#define XBAR_CLR18_FSIRXD_TRIG_3   0x80U      // Input Flag clear for FSIRXD_TRIG_3 Signal
#define XBAR_CLR18_CPU1ERADEVT8    0x100U     // Input Flag clear for CPU1ERADEVT8 Signal
#define XBAR_CLR18_CPU1ERADEVT9    0x200U     // Input Flag clear for CPU1ERADEVT9 Signal
#define XBAR_CLR18_CPU1ERADEVT10   0x400U     // Input Flag clear for CPU1ERADEVT10 Signal
#define XBAR_CLR18_CPU1ERADEVT11   0x800U     // Input Flag clear for CPU1ERADEVT11 Signal
#define XBAR_CLR18_CPU2ERADEVT8    0x1000U    // Input Flag clear for CPU2ERADEVT8 Signal
#define XBAR_CLR18_CPU2ERADEVT9    0x2000U    // Input Flag clear for CPU2ERADEVT9 Signal
#define XBAR_CLR18_CPU2ERADEVT10   0x4000U    // Input Flag clear for CPU2ERADEVT10 Signal
#define XBAR_CLR18_CPU2ERADEVT11   0x8000U    // Input Flag clear for CPU2ERADEVT11 Signal
#define XBAR_CLR18_CPU3ERADEVT8    0x10000U   // Input Flag clear for CPU3ERADEVT8 Signal
#define XBAR_CLR18_CPU3ERADEVT9    0x20000U   // Input Flag clear for CPU3ERADEVT9 Signal
#define XBAR_CLR18_CPU3ERADEVT10   0x40000U   // Input Flag clear for CPU3ERADEVT10 Signal
#define XBAR_CLR18_CPU3ERADEVT11   0x80000U   // Input Flag clear for CPU3ERADEVT11 Signal



#endif
