//###########################################################################
//
// FILE:    hw_elt.h
//
// TITLE:   Definitions for the ELT registers.
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

#ifndef HW_ELT_H
#define HW_ELT_H

//*************************************************************************************************
//
// The following are defines for the ELT register offsets
//
//*************************************************************************************************
#define ELT_O_CTL         0x0U     // Control Register
#define ELT_O_SWINPEVT    0x4U     // Software Input Event
#define ELT_O_POLARITY    0xCU     // Polarity Select
#define ELT_O_LOGCTL      0x10U    // Log Control
#define ELT_O_EDGE        0x14U    // Edge Select
#define ELT_O_MUXOUT      0x1CU    // MUX Output
#define ELT_O_INT         0x24U    // Interrupt Enable Register
#define ELT_O_FLG         0x28U    // Interrupt Flag Register
#define ELT_O_CLR         0x2CU    // Interrupt Clear Register
#define ELT_O_FRC         0x30U    // Interrupt Force Register
#define ELT_O_FIFOBUF_L   0x40U    // FIFO Buffer Low (31:0)
#define ELT_O_FIFOBUF_M   0x44U    // FIFO Buffer Mid (63:32)
#define ELT_O_FIFOBUF_H   0x48U    // FIFO Buffer High (95:64)
#define ELT_O_MUXSEL0     0x100U   // MUX# Select
#define ELT_O_MUXSEL1     0x104U   // MUX# Select
#define ELT_O_MUXSEL2     0x108U   // MUX# Select
#define ELT_O_MUXSEL3     0x10CU   // MUX# Select
#define ELT_O_MUXSEL4     0x110U   // MUX# Select
#define ELT_O_MUXSEL5     0x114U   // MUX# Select
#define ELT_O_MUXSEL6     0x118U   // MUX# Select
#define ELT_O_MUXSEL7     0x11CU   // MUX# Select
#define ELT_O_MUXSEL8     0x120U   // MUX# Select
#define ELT_O_MUXSEL9     0x124U   // MUX# Select
#define ELT_O_MUXSEL10    0x128U   // MUX# Select
#define ELT_O_MUXSEL11    0x12CU   // MUX# Select
#define ELT_O_MUXSEL12    0x130U   // MUX# Select
#define ELT_O_MUXSEL13    0x134U   // MUX# Select
#define ELT_O_MUXSEL14    0x138U   // MUX# Select
#define ELT_O_MUXSEL15    0x13CU   // MUX# Select
#define ELT_O_MUXSEL16    0x140U   // MUX# Select
#define ELT_O_MUXSEL17    0x144U   // MUX# Select
#define ELT_O_MUXSEL18    0x148U   // MUX# Select
#define ELT_O_MUXSEL19    0x14CU   // MUX# Select
#define ELT_O_MUXSEL20    0x150U   // MUX# Select
#define ELT_O_MUXSEL21    0x154U   // MUX# Select
#define ELT_O_MUXSEL22    0x158U   // MUX# Select
#define ELT_O_MUXSEL23    0x15CU   // MUX# Select
#define ELT_O_MUXSEL24    0x160U   // MUX# Select
#define ELT_O_MUXSEL25    0x164U   // MUX# Select
#define ELT_O_MUXSEL26    0x168U   // MUX# Select
#define ELT_O_MUXSEL27    0x16CU   // MUX# Select
#define ELT_O_MUXSEL28    0x170U   // MUX# Select
#define ELT_O_MUXSEL29    0x174U   // MUX# Select
#define ELT_O_MUXSEL30    0x178U   // MUX# Select
#define ELT_O_MUXSEL31    0x17CU   // MUX# Select


//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTCTL register
//
//*************************************************************************************************
#define ELT_CTL_ENA               0x1U          // ENABLE
#define ELT_CTL_LOGCTLENA         0x2U          // Log Control Enable
#define ELT_CTL_LOGCTLRDY         0x4U          // Log Control Ready
#define ELT_CTL_FIFORSTPR         0x8U          // FIFO Reset Pointer
#define ELT_CTL_FIFOTHRESHOLD_S   16U
#define ELT_CTL_FIFOTHRESHOLD_M   0x1F0000U     // FIFO Threshold for Int or DMA Req event
#define ELT_CTL_FIFOST_S          24U
#define ELT_CTL_FIFOST_M          0x1F000000U   // FIFO Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTSWINPEVT register
//
//*************************************************************************************************
#define ELT_SWINPEVT_SWINPEVT0    0x1U          // SW Input Event 0
#define ELT_SWINPEVT_SWINPEVT1    0x2U          // SW Input Event 1
#define ELT_SWINPEVT_SWINPEVT2    0x4U          // SW Input Event 2
#define ELT_SWINPEVT_SWINPEVT3    0x8U          // SW Input Event 3
#define ELT_SWINPEVT_SWINPEVT4    0x10U         // SW Input Event 4
#define ELT_SWINPEVT_SWINPEVT5    0x20U         // SW Input Event 5
#define ELT_SWINPEVT_SWINPEVT6    0x40U         // SW Input Event 6
#define ELT_SWINPEVT_SWINPEVT7    0x80U         // SW Input Event 7
#define ELT_SWINPEVT_SWINPEVT8    0x100U        // SW Input Event 8
#define ELT_SWINPEVT_SWINPEVT9    0x200U        // SW Input Event 9
#define ELT_SWINPEVT_SWINPEVT10   0x400U        // SW Input Event 10
#define ELT_SWINPEVT_SWINPEVT11   0x800U        // SW Input Event 11
#define ELT_SWINPEVT_SWINPEVT12   0x1000U       // SW Input Event 12
#define ELT_SWINPEVT_SWINPEVT13   0x2000U       // SW Input Event 13
#define ELT_SWINPEVT_SWINPEVT14   0x4000U       // SW Input Event 14
#define ELT_SWINPEVT_SWINPEVT15   0x8000U       // SW Input Event 15
#define ELT_SWINPEVT_SWINPEVT16   0x10000U      // SW Input Event 16
#define ELT_SWINPEVT_SWINPEVT17   0x20000U      // SW Input Event 17
#define ELT_SWINPEVT_SWINPEVT18   0x40000U      // SW Input Event 18
#define ELT_SWINPEVT_SWINPEVT19   0x80000U      // SW Input Event 19
#define ELT_SWINPEVT_SWINPEVT20   0x100000U     // SW Input Event 20
#define ELT_SWINPEVT_SWINPEVT21   0x200000U     // SW Input Event 21
#define ELT_SWINPEVT_SWINPEVT22   0x400000U     // SW Input Event 22
#define ELT_SWINPEVT_SWINPEVT23   0x800000U     // SW Input Event 23
#define ELT_SWINPEVT_SWINPEVT24   0x1000000U    // SW Input Event 24
#define ELT_SWINPEVT_SWINPEVT25   0x2000000U    // SW Input Event 25
#define ELT_SWINPEVT_SWINPEVT26   0x4000000U    // SW Input Event 26
#define ELT_SWINPEVT_SWINPEVT27   0x8000000U    // SW Input Event 27
#define ELT_SWINPEVT_SWINPEVT28   0x10000000U   // SW Input Event 28
#define ELT_SWINPEVT_SWINPEVT29   0x20000000U   // SW Input Event 29
#define ELT_SWINPEVT_SWINPEVT30   0x40000000U   // SW Input Event 30
#define ELT_SWINPEVT_SWINPEVT31   0x80000000U   // SW Input Event 31

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTPOLARITY register
//
//*************************************************************************************************
#define ELT_POLARITY_MUXOUT0POL    0x1U          // Mux Output 0 Polarity
#define ELT_POLARITY_MUXOUT1POL    0x2U          // Mux Output 1 Polarity
#define ELT_POLARITY_MUXOUT2POL    0x4U          // Mux Output 2 Polarity
#define ELT_POLARITY_MUXOUT3POL    0x8U          // Mux Output 3 Polarity
#define ELT_POLARITY_MUXOUT4POL    0x10U         // Mux Output 4 Polarity
#define ELT_POLARITY_MUXOUT5POL    0x20U         // Mux Output 5 Polarity
#define ELT_POLARITY_MUXOUT6POL    0x40U         // Mux Output 6 Polarity
#define ELT_POLARITY_MUXOUT7POL    0x80U         // Mux Output 7 Polarity
#define ELT_POLARITY_MUXOUT8POL    0x100U        // Mux Output 8 Polarity
#define ELT_POLARITY_MUXOUT9POL    0x200U        // Mux Output 9 Polarity
#define ELT_POLARITY_MUXOUT10POL   0x400U        // Mux Output 10 Polarity
#define ELT_POLARITY_MUXOUT11POL   0x800U        // Mux Output 11 Polarity
#define ELT_POLARITY_MUXOUT12POL   0x1000U       // Mux Output 12 Polarity
#define ELT_POLARITY_MUXOUT13POL   0x2000U       // Mux Output 13 Polarity
#define ELT_POLARITY_MUXOUT14POL   0x4000U       // Mux Output 14 Polarity
#define ELT_POLARITY_MUXOUT15POL   0x8000U       // Mux Output 15 Polarity
#define ELT_POLARITY_MUXOUT16POL   0x10000U      // Mux Output 16 Polarity
#define ELT_POLARITY_MUXOUT17POL   0x20000U      // Mux Output 17 Polarity
#define ELT_POLARITY_MUXOUT18POL   0x40000U      // Mux Output 18 Polarity
#define ELT_POLARITY_MUXOUT19POL   0x80000U      // Mux Output 19 Polarity
#define ELT_POLARITY_MUXOUT20POL   0x100000U     // Mux Output 20 Polarity
#define ELT_POLARITY_MUXOUT21POL   0x200000U     // Mux Output 21 Polarity
#define ELT_POLARITY_MUXOUT22POL   0x400000U     // Mux Output 22 Polarity
#define ELT_POLARITY_MUXOUT23POL   0x800000U     // Mux Output 23 Polarity
#define ELT_POLARITY_MUXOUT24POL   0x1000000U    // Mux Output 24 Polarity
#define ELT_POLARITY_MUXOUT25POL   0x2000000U    // Mux Output 25 Polarity
#define ELT_POLARITY_MUXOUT26POL   0x4000000U    // Mux Output 26 Polarity
#define ELT_POLARITY_MUXOUT27POL   0x8000000U    // Mux Output 27 Polarity
#define ELT_POLARITY_MUXOUT28POL   0x10000000U   // Mux Output 28 Polarity
#define ELT_POLARITY_MUXOUT29POL   0x20000000U   // Mux Output 29 Polarity
#define ELT_POLARITY_MUXOUT30POL   0x40000000U   // Mux Output 30 Polarity
#define ELT_POLARITY_MUXOUT31POL   0x80000000U   // Mux Output 31 Polarity

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTLOGCTL register
//
//*************************************************************************************************
#define ELT_LOGCTL_LOGCTL_S   0U
#define ELT_LOGCTL_LOGCTL_M   0x1FU   // Log Control

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTEDGE register
//
//*************************************************************************************************
#define ELT_EDGE_MUXOUT0EDGE    0x1U          // Mux Output 0 Edge to Capture Data
#define ELT_EDGE_MUXOUT1EDGE    0x2U          // Mux Output 1 Edge to Capture Data
#define ELT_EDGE_MUXOUT2EDGE    0x4U          // Mux Output 2 Edge to Capture Data
#define ELT_EDGE_MUXOUT3EDGE    0x8U          // Mux Output 3 Edge to Capture Data
#define ELT_EDGE_MUXOUT4EDGE    0x10U         // Mux Output 4 Edge to Capture Data
#define ELT_EDGE_MUXOUT5EDGE    0x20U         // Mux Output 5 Edge to Capture Data
#define ELT_EDGE_MUXOUT6EDGE    0x40U         // Mux Output 6 Edge to Capture Data
#define ELT_EDGE_MUXOUT7EDGE    0x80U         // Mux Output 7 Edge to Capture Data
#define ELT_EDGE_MUXOUT8EDGE    0x100U        // Mux Output 8 Edge to Capture Data
#define ELT_EDGE_MUXOUT9EDGE    0x200U        // Mux Output 9 Edge to Capture Data
#define ELT_EDGE_MUXOUT10EDGE   0x400U        // Mux Output 10 Edge to Capture Data
#define ELT_EDGE_MUXOUT11EDGE   0x800U        // Mux Output 11 Edge to Capture Data
#define ELT_EDGE_MUXOUT12EDGE   0x1000U       // Mux Output 12 Edge to Capture Data
#define ELT_EDGE_MUXOUT13EDGE   0x2000U       // Mux Output 13 Edge to Capture Data
#define ELT_EDGE_MUXOUT14EDGE   0x4000U       // Mux Output 14 Edge to Capture Data
#define ELT_EDGE_MUXOUT15EDGE   0x8000U       // Mux Output 15 Edge to Capture Data
#define ELT_EDGE_MUXOUT16EDGE   0x10000U      // Mux Output 16 Edge to Capture Data
#define ELT_EDGE_MUXOUT17EDGE   0x20000U      // Mux Output 17 Edge to Capture Data
#define ELT_EDGE_MUXOUT18EDGE   0x40000U      // Mux Output 18 Edge to Capture Data
#define ELT_EDGE_MUXOUT19EDGE   0x80000U      // Mux Output 19 Edge to Capture Data
#define ELT_EDGE_MUXOUT20EDGE   0x100000U     // Mux Output 20 Edge to Capture Data
#define ELT_EDGE_MUXOUT21EDGE   0x200000U     // Mux Output 21 Edge to Capture Data
#define ELT_EDGE_MUXOUT22EDGE   0x400000U     // Mux Output 22 Edge to Capture Data
#define ELT_EDGE_MUXOUT23EDGE   0x800000U     // Mux Output 23 Edge to Capture Data
#define ELT_EDGE_MUXOUT24EDGE   0x1000000U    // Mux Output 24 Edge to Capture Data
#define ELT_EDGE_MUXOUT25EDGE   0x2000000U    // Mux Output 25 Edge to Capture Data
#define ELT_EDGE_MUXOUT26EDGE   0x4000000U    // Mux Output 26 Edge to Capture Data
#define ELT_EDGE_MUXOUT27EDGE   0x8000000U    // Mux Output 27 Edge to Capture Data
#define ELT_EDGE_MUXOUT28EDGE   0x10000000U   // Mux Output 28 Edge to Capture Data
#define ELT_EDGE_MUXOUT29EDGE   0x20000000U   // Mux Output 29 Edge to Capture Data
#define ELT_EDGE_MUXOUT30EDGE   0x40000000U   // Mux Output 30 Edge to Capture Data
#define ELT_EDGE_MUXOUT31EDGE   0x80000000U   // Mux Output 31 Edge to Capture Data

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTINT register
//
//*************************************************************************************************
#define ELT_INT_FIFOTHRESHOLD   0x2U   // FIFO Pointer Equal to Threshold Interrupt Enable
#define ELT_INT_FIFOOVF         0x4U   // FIFO Overflow Interrupt Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTFLG register
//
//*************************************************************************************************
#define ELT_FLG_INT             0x1U   // Global Flag
#define ELT_FLG_FIFOTHRESHOLD   0x2U   // FIFO Pointer Equal to Threshold Interrupt Flag
#define ELT_FLG_FIFOOVF         0x4U   // FIFO Overflow Interrupt Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTCLR register
//
//*************************************************************************************************
#define ELT_CLR_INT             0x1U   // Global Interrupt Status Clear
#define ELT_CLR_FIFOTHRESHOLD   0x2U   // FIFO Pointer Equal to Threshold Status Clear
#define ELT_CLR_FIFOOVF         0x4U   // FIFO Overflow Status Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTFRC register
//
//*************************************************************************************************
#define ELT_FRC_FIFOTHRESHOLD   0x2U   // FIFO Pointer Equal to Threshold Force Interrupt
#define ELT_FRC_FIFOOVF         0x4U   // FIFO Overflow Force  Interrupt

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL0 register
//
//*************************************************************************************************
#define ELT_MUXSEL0_MUXSEL_S   0U
#define ELT_MUXSEL0_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL1 register
//
//*************************************************************************************************
#define ELT_MUXSEL1_MUXSEL_S   0U
#define ELT_MUXSEL1_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL2 register
//
//*************************************************************************************************
#define ELT_MUXSEL2_MUXSEL_S   0U
#define ELT_MUXSEL2_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL3 register
//
//*************************************************************************************************
#define ELT_MUXSEL3_MUXSEL_S   0U
#define ELT_MUXSEL3_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL4 register
//
//*************************************************************************************************
#define ELT_MUXSEL4_MUXSEL_S   0U
#define ELT_MUXSEL4_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL5 register
//
//*************************************************************************************************
#define ELT_MUXSEL5_MUXSEL_S   0U
#define ELT_MUXSEL5_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL6 register
//
//*************************************************************************************************
#define ELT_MUXSEL6_MUXSEL_S   0U
#define ELT_MUXSEL6_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL7 register
//
//*************************************************************************************************
#define ELT_MUXSEL7_MUXSEL_S   0U
#define ELT_MUXSEL7_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL8 register
//
//*************************************************************************************************
#define ELT_MUXSEL8_MUXSEL_S   0U
#define ELT_MUXSEL8_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL9 register
//
//*************************************************************************************************
#define ELT_MUXSEL9_MUXSEL_S   0U
#define ELT_MUXSEL9_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL10 register
//
//*************************************************************************************************
#define ELT_MUXSEL10_MUXSEL_S   0U
#define ELT_MUXSEL10_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL11 register
//
//*************************************************************************************************
#define ELT_MUXSEL11_MUXSEL_S   0U
#define ELT_MUXSEL11_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL12 register
//
//*************************************************************************************************
#define ELT_MUXSEL12_MUXSEL_S   0U
#define ELT_MUXSEL12_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL13 register
//
//*************************************************************************************************
#define ELT_MUXSEL13_MUXSEL_S   0U
#define ELT_MUXSEL13_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL14 register
//
//*************************************************************************************************
#define ELT_MUXSEL14_MUXSEL_S   0U
#define ELT_MUXSEL14_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL15 register
//
//*************************************************************************************************
#define ELT_MUXSEL15_MUXSEL_S   0U
#define ELT_MUXSEL15_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL16 register
//
//*************************************************************************************************
#define ELT_MUXSEL16_MUXSEL_S   0U
#define ELT_MUXSEL16_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL17 register
//
//*************************************************************************************************
#define ELT_MUXSEL17_MUXSEL_S   0U
#define ELT_MUXSEL17_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL18 register
//
//*************************************************************************************************
#define ELT_MUXSEL18_MUXSEL_S   0U
#define ELT_MUXSEL18_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL19 register
//
//*************************************************************************************************
#define ELT_MUXSEL19_MUXSEL_S   0U
#define ELT_MUXSEL19_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL20 register
//
//*************************************************************************************************
#define ELT_MUXSEL20_MUXSEL_S   0U
#define ELT_MUXSEL20_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL21 register
//
//*************************************************************************************************
#define ELT_MUXSEL21_MUXSEL_S   0U
#define ELT_MUXSEL21_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL22 register
//
//*************************************************************************************************
#define ELT_MUXSEL22_MUXSEL_S   0U
#define ELT_MUXSEL22_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL23 register
//
//*************************************************************************************************
#define ELT_MUXSEL23_MUXSEL_S   0U
#define ELT_MUXSEL23_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL24 register
//
//*************************************************************************************************
#define ELT_MUXSEL24_MUXSEL_S   0U
#define ELT_MUXSEL24_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL25 register
//
//*************************************************************************************************
#define ELT_MUXSEL25_MUXSEL_S   0U
#define ELT_MUXSEL25_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL26 register
//
//*************************************************************************************************
#define ELT_MUXSEL26_MUXSEL_S   0U
#define ELT_MUXSEL26_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL27 register
//
//*************************************************************************************************
#define ELT_MUXSEL27_MUXSEL_S   0U
#define ELT_MUXSEL27_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL28 register
//
//*************************************************************************************************
#define ELT_MUXSEL28_MUXSEL_S   0U
#define ELT_MUXSEL28_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL29 register
//
//*************************************************************************************************
#define ELT_MUXSEL29_MUXSEL_S   0U
#define ELT_MUXSEL29_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL30 register
//
//*************************************************************************************************
#define ELT_MUXSEL30_MUXSEL_S   0U
#define ELT_MUXSEL30_MUXSEL_M   0x1FFU   // MUX Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the ELTMUXSEL31 register
//
//*************************************************************************************************
#define ELT_MUXSEL31_MUXSEL_S   0U
#define ELT_MUXSEL31_MUXSEL_M   0x1FFU   // MUX Select



#endif
