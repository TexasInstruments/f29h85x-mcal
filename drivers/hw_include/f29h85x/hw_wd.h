//###########################################################################
//
// FILE:    hw_wd.h
//
// TITLE:   Definitions for the WD registers.
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

#ifndef HW_WD_H
#define HW_WD_H

//*************************************************************************************************
//
// The following are defines for the WD register offsets
//
//*************************************************************************************************
#define WD_O_SCSR   0x44U   // System Control & Status Register
#define WD_O_CNTR   0x46U   // Watchdog Counter Register
#define WD_O_KEY    0x4AU   // Watchdog Reset Key Register
#define WD_O_CR     0x52U   // Watchdog Control Register
#define WD_O_WCR    0x54U   // Watchdog Windowed Control Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the SCSR register
//
//*************************************************************************************************
#define WD_SCSR_WDOVERRIDE   0x1U   // WD Override for WDDIS bit
#define WD_SCSR_WDENINT      0x2U   // WD Interrupt Enable
#define WD_SCSR_WDINTS       0x4U   // WD Interrupt Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDCNTR register
//
//*************************************************************************************************
#define WD_CNTR_WDCNTR_S   0U
#define WD_CNTR_WDCNTR_M   0xFFU   // WD Counter

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDKEY register
//
//*************************************************************************************************
#define WD_KEY_WDKEY_S   0U
#define WD_KEY_WDKEY_M   0xFFU   // WD KEY

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDCR register
//
//*************************************************************************************************
#define WD_CR_WDPS_S          0U
#define WD_CR_WDPS_M          0x7U     // WD Clock Prescalar
#define WD_CR_WDCHK_S         3U
#define WD_CR_WDCHK_M         0x38U    // WD Check Bits
#define WD_CR_WDDIS           0x40U    // WD Disable
#define WD_CR_WDFLG           0x80U    // WD Reset Status Flag
#define WD_CR_WDPRECLKDIV_S   8U
#define WD_CR_WDPRECLKDIV_M   0xF00U   // WD Pre Clock Divider

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDWCR register
//
//*************************************************************************************************
#define WD_WCR_MIN_S      0U
#define WD_WCR_MIN_M      0xFFU    // WD Min Threshold setting for Windowed Watchdog functionality
#define WD_WCR_FIRSTKEY   0x100U   // First Key Detect Flag



#endif
