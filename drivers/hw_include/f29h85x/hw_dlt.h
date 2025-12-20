//###########################################################################
//
// FILE:    hw_dlt.h
//
// TITLE:   Definitions for the DLT registers.
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

#ifndef HW_DLT_H
#define HW_DLT_H

//*************************************************************************************************
//
// The following are defines for the DLT register offsets
//
//*************************************************************************************************
#define DLT_O_ERAD_START_MASK_L       0x0U    // ERAD Start Mask for Lower 32 lines
#define DLT_O_ERAD_START_MASK_H       0x4U    // ERAD Start Mask for Higher 32 lines
#define DLT_O_ERAD_END_MASK_L         0x8U    // ERAD End Mask for Lower 32 lines
#define DLT_O_ERAD_END_MASK_H         0xCU    // ERAD End Mask for Higher 32 lines
#define DLT_O_TAG_FILTER_START_REF    0x10U   // Tag Filer Start Reference
#define DLT_O_TAG_FILTER_START_MASK   0x14U   // Tag Filer Start Mask
#define DLT_O_TAG_FILTER_END_REF      0x18U   // Tag Filer End Reference
#define DLT_O_TAG_FILTER_END_MASK     0x1CU   // Tag Filer End Mask
#define DLT_O_LINK_EN                 0x20U   // Link Enable
#define DLT_O_CONTROL                 0x24U   // DLT Control Register
#define DLT_O_FIFO_CONTROL            0x28U   // FIFO Control Register
#define DLT_O_TIMER_CONTROL           0x2CU   // Timer Control Register
#define DLT_O_FIFO_STS                0x30U   // Number of entries in FIFO
#define DLT_O_FIFO_PTR                0x34U   // Pointer locations in FIFO
#define DLT_O_TIMER2_COUNT            0x38U   // Timer2 Status
#define DLT_O_INT_FLG                 0x3CU   // Interrupt Flag
#define DLT_O_INT_EN                  0x40U   // Interrupt Enable
#define DLT_O_INT_FRC                 0x44U   // Interrupt Force
#define DLT_O_INT_CLR                 0x48U   // Interrupt Clear

#define DLT_O_FIFO_BUF_L    0x0U                       // FIFO Content Register
#define DLT_O_FIFO_BUF_H    0x4U                       // FIFO Content Register
#define DLT_O_FIFO_MEM(i)   (0x1000U + ((i) * 0x4U))   // (0 <= i < 512) FIFO access in Memory mode


//*************************************************************************************************
//
// The following are defines for the bit fields in the TAG_FILTER_START_REF register
//
//*************************************************************************************************
#define DLT_TAG_FILTER_START_REF_START_REF_S   0U
#define DLT_TAG_FILTER_START_REF_START_REF_M   0xFFFFU   // Reference for TAG start comparison

//*************************************************************************************************
//
// The following are defines for the bit fields in the TAG_FILTER_START_MASK register
//
//*************************************************************************************************
#define DLT_TAG_FILTER_START_MASK_START_MASK_S   0U
#define DLT_TAG_FILTER_START_MASK_START_MASK_M   0xFFFFU   // MASK for TAG start comparison

//*************************************************************************************************
//
// The following are defines for the bit fields in the TAG_FILTER_END_REF register
//
//*************************************************************************************************
#define DLT_TAG_FILTER_END_REF_END_REF_S   0U
#define DLT_TAG_FILTER_END_REF_END_REF_M   0xFFFFU   // Reference for TAG end comparison

//*************************************************************************************************
//
// The following are defines for the bit fields in the TAG_FILTER_END_MASK register
//
//*************************************************************************************************
#define DLT_TAG_FILTER_END_MASK_END_MASK_S   0U
#define DLT_TAG_FILTER_END_MASK_END_MASK_M   0xFFFFU   // MASK for TAG end comparison

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK_EN register
//
//*************************************************************************************************
#define DLT_LINK_EN_LINK0_EN    0x1U      // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK1_EN    0x2U      // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK2_EN    0x4U      // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK3_EN    0x8U      // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK4_EN    0x10U     // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK5_EN    0x20U     // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK6_EN    0x40U     // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK7_EN    0x80U     // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK8_EN    0x100U    // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK9_EN    0x200U    // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK10_EN   0x400U    // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK11_EN   0x800U    // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK12_EN   0x1000U   // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK13_EN   0x2000U   // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK14_EN   0x4000U   // LINK permissions to write to FIFO
#define DLT_LINK_EN_LINK15_EN   0x8000U   // LINK permissions to write to FIFO

//*************************************************************************************************
//
// The following are defines for the bit fields in the DLT_CONTROL register
//
//*************************************************************************************************
#define DLT_CONTROL_DLT_EN           0x1U          // DLTAG Enable
#define DLT_CONTROL_ERAD_FILTER_EN   0x2U          // ERAD Filter Enable
#define DLT_CONTROL_TAG_FILTER_EN    0x4U          // TAG Filter Enable
#define DLT_CONTROL_CAP_MODE         0x8U          // Capture mode
#define DLT_CONTROL_FILTER_RST       0x10U         // Filter Reset
#define DLT_CONTROL_KEY_S            16U
#define DLT_CONTROL_KEY_M            0xFFFF0000U   // key to enable write to lower [15:0] bit
                                                   // fileds
#define DLT_CONTROL_KEY              0x5A5A0000U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the FIFO_CONTROL register
//
//*************************************************************************************************
#define DLT_FIFO_CONTROL_DMA_EN                0x1U      // Trigger DMA on FIFO level
#define DLT_FIFO_CONTROL_FIFO_RST              0x2U      // Initialize pointers of FIFO to 0
#define DLT_FIFO_CONTROL_WR_CTR_TRIG_LEVEL_S   8U
#define DLT_FIFO_CONTROL_WR_CTR_TRIG_LEVEL_M   0xFF00U   // Level of FIFO writes required to
                                                         // trigger INT/DMA

//*************************************************************************************************
//
// The following are defines for the bit fields in the TIMER_CONTROL register
//
//*************************************************************************************************
#define DLT_TIMER_CONTROL_TIMER2_RST   0x2U   // Timer 2 is reset

//*************************************************************************************************
//
// The following are defines for the bit fields in the FIFO_STS register
//
//*************************************************************************************************
#define DLT_FIFO_STS_WORD_CTR_S   0U
#define DLT_FIFO_STS_WORD_CTR_M   0xFFU       // Number of 64-bit words to be read in the FIFO
#define DLT_FIFO_STS_WR_CTR_S     16U
#define DLT_FIFO_STS_WR_CTR_M     0xFF0000U   // Write counter of FIFO after last trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the FIFO_PTR register
//
//*************************************************************************************************
#define DLT_FIFO_PTR_RD_PTR_S   0U
#define DLT_FIFO_PTR_RD_PTR_M   0xFFU       // Read pointer location of FIFO
#define DLT_FIFO_PTR_WR_PTR_S   16U
#define DLT_FIFO_PTR_WR_PTR_M   0xFF0000U   // Write pointer location of FIFO

//*************************************************************************************************
//
// The following are defines for the bit fields in the TIMER2_COUNT register
//
//*************************************************************************************************
#define DLT_TIMER2_COUNT_COUNT_S   0U
#define DLT_TIMER2_COUNT_COUNT_M   0x1FFFFFFFU   // Current value of TIMER2

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_FLG register
//
//*************************************************************************************************
#define DLT_INT_FLG_INT          0x1U    // Global Interrupt Status
#define DLT_INT_FLG_TIMER1_OVF   0x2U    // TIMER1 overflow status
#define DLT_INT_FLG_TIMER2_OVF   0x4U    // TIMER2 overflow status
#define DLT_INT_FLG_FIFO_OVF     0x8U    // FIFO overflow status
#define DLT_INT_FLG_FIFO_UF      0x10U   // FIFO underflow status
#define DLT_INT_FLG_FIFO_TRIG    0x20U   // FIFO reached Trigger level status

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_EN register
//
//*************************************************************************************************
#define DLT_INT_EN_TIMER1_OVF   0x2U    // TIMER1 overflow enable
#define DLT_INT_EN_TIMER2_OVF   0x4U    // TIMER2 overflow enable
#define DLT_INT_EN_FIFO_OVF     0x8U    // FIFO overflow enable
#define DLT_INT_EN_FIFO_UF      0x10U   // FIFO underflow enable
#define DLT_INT_EN_FIFO_TRIG    0x20U   // FIFO reached Trigger level enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_FRC register
//
//*************************************************************************************************
#define DLT_INT_FRC_TIMER1_OVF   0x2U    // TIMER1 overflow force
#define DLT_INT_FRC_TIMER2_OVF   0x4U    // TIMER2 overflow force
#define DLT_INT_FRC_FIFO_OVF     0x8U    // FIFO overflow force
#define DLT_INT_FRC_FIFO_UF      0x10U   // FIFO underflow force
#define DLT_INT_FRC_FIFO_TRIG    0x20U   // FIFO reached Trigger level force

//*************************************************************************************************
//
// The following are defines for the bit fields in the INT_CLR register
//
//*************************************************************************************************
#define DLT_INT_CLR_INT          0x1U    // Global Interrupt clear
#define DLT_INT_CLR_TIMER1_OVF   0x2U    // TIMER1 overflow clear
#define DLT_INT_CLR_TIMER2_OVF   0x4U    // TIMER2 overflow clear
#define DLT_INT_CLR_FIFO_OVF     0x8U    // FIFO overflow clear
#define DLT_INT_CLR_FIFO_UF      0x10U   // FIFO underflow clear
#define DLT_INT_CLR_FIFO_TRIG    0x20U   // FIFO reached Trigger level clear




#endif
