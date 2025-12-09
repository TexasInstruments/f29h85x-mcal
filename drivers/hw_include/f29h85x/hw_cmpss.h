//###########################################################################
//
// FILE:    hw_cmpss.h
//
// TITLE:   Definitions for the CMPSS registers.
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

#ifndef HW_CMPSS_H
#define HW_CMPSS_H

//*************************************************************************************************
//
// The following are defines for the CMPSS register offsets
//
//*************************************************************************************************
#define CMPSS_O_COMPCTL            0x0U    // CMPSS Comparator Control Register
#define CMPSS_O_COMPHYSCTL         0x2U    // CMPSS Comparator Hysteresis Control Register
#define CMPSS_O_COMPSTS            0x4U    // CMPSS Comparator Status Register
#define CMPSS_O_COMPSTSCLR         0x6U    // CMPSS Comparator Status Clear Register
#define CMPSS_O_COMPDACHCTL        0x8U    // CMPSS High DAC Control Register
#define CMPSS_O_COMPDACHCTL2       0xAU    // CMPSS High DAC Control Register 2
#define CMPSS_O_DACHVALS           0xCU    // CMPSS High DAC Value Shadow Register
#define CMPSS_O_DACHVALA           0xEU    // CMPSS High DAC Value Active Register
#define CMPSS_O_RAMPHREFA          0x10U   // CMPSS High Ramp Reference Active Register
#define CMPSS_O_RAMPHREFS          0x14U   // CMPSS High Ramp Reference Shadow Register
#define CMPSS_O_RAMPHSTEPVALA      0x18U   // CMPSS High Ramp Step Value Active Register
#define CMPSS_O_RAMPHCTLA          0x1AU   // CMPSS High Ramp Control Active Register
#define CMPSS_O_RAMPHSTEPVALS      0x1CU   // CMPSS High Ramp Step Value Shadow Register
#define CMPSS_O_RAMPHCTLS          0x1EU   // CMPSS High Ramp Control Shadow Register
#define CMPSS_O_RAMPHSTS           0x20U   // CMPSS High Ramp Status Register
#define CMPSS_O_DACLVALS           0x24U   // CMPSS Low DAC Value Shadow Register
#define CMPSS_O_DACLVALA           0x26U   // CMPSS Low DAC Value Active Register
#define CMPSS_O_RAMPHDLYA          0x28U   // CMPSS High Ramp Delay Active Register
#define CMPSS_O_RAMPHDLYS          0x2AU   // CMPSS High Ramp Delay Shadow Register
#define CMPSS_O_CTRIPLFILCTL       0x2CU   // CTRIPL Filter Control Register
#define CMPSS_O_CTRIPLFILCLKCTL    0x2EU   // CTRIPL Filter Clock Control Register
#define CMPSS_O_CTRIPHFILCTL       0x30U   // CTRIPH Filter Control Register
#define CMPSS_O_CTRIPHFILCLKCTL    0x32U   // CTRIPH Filter Clock Control Register
#define CMPSS_O_COMPLOCK           0x34U   // CMPSS Lock Register
#define CMPSS_O_DACHVALS2          0x38U   // CMPSS High DAC Value Shadow Register 2
#define CMPSS_O_DACLVALS2          0x3AU   // CMPSS Low DAC Value Shadow Register 2
#define CMPSS_O_COMPDACLCTL        0x48U   // CMPSS Low DAC Control Register
#define CMPSS_O_COMPDACLCTL2       0x4AU   // CMPSS Low DAC Control Register 2
#define CMPSS_O_RAMPLREFA          0x50U   // CMPSS Low Ramp Reference Active Register
#define CMPSS_O_RAMPLREFS          0x54U   // CMPSS Low Ramp Reference Shadow Register
#define CMPSS_O_RAMPLSTEPVALA      0x58U   // CMPSS Low Ramp Step Value Active Register
#define CMPSS_O_RAMPLCTLA          0x5AU   // CMPSS Low Ramp Control Active Register
#define CMPSS_O_RAMPLSTEPVALS      0x5CU   // CMPSS Low Ramp Step Value Shadow Register
#define CMPSS_O_RAMPLCTLS          0x5EU   // CMPSS Low Ramp Control Shadow Register
#define CMPSS_O_RAMPLSTS           0x60U   // CMPSS Low Ramp Status Register
#define CMPSS_O_RAMPLDLYA          0x68U   // CMPSS Low Ramp Delay Active Register
#define CMPSS_O_RAMPLDLYS          0x6AU   // CMPSS Low Ramp Delay Shadow Register
#define CMPSS_O_CTRIPLFILCLKCTL2   0x6EU   // CTRIPL Filter Clock Control Register 2
#define CMPSS_O_CTRIPHFILCLKCTL2   0x72U   // CTRIPH Filter Clock Control Register 2


//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPCTL register
//
//*************************************************************************************************
#define CMPSS_COMPCTL_COMPHSOURCE      0x1U      // High Comparator Source Select
#define CMPSS_COMPCTL_COMPHINV         0x2U      // High Comparator Invert Select
#define CMPSS_COMPCTL_CTRIPHSEL_S      2U
#define CMPSS_COMPCTL_CTRIPHSEL_M      0xCU      // High Comparator Trip Select
#define CMPSS_COMPCTL_CTRIPOUTHSEL_S   4U
#define CMPSS_COMPCTL_CTRIPOUTHSEL_M   0x30U     // High Comparator Trip Output Select
#define CMPSS_COMPCTL_ASYNCHEN         0x40U     // High Comparator Asynchronous Path Enable
#define CMPSS_COMPCTL_COMPLSOURCE      0x100U    // Low Comparator Source Select
#define CMPSS_COMPCTL_COMPLINV         0x200U    // Low Comparator Invert Select
#define CMPSS_COMPCTL_CTRIPLSEL_S      10U
#define CMPSS_COMPCTL_CTRIPLSEL_M      0xC00U    // Low Comparator Trip Select
#define CMPSS_COMPCTL_CTRIPOUTLSEL_S   12U
#define CMPSS_COMPCTL_CTRIPOUTLSEL_M   0x3000U   // Low Comparator Trip Output Select
#define CMPSS_COMPCTL_ASYNCLEN         0x4000U   // Low Comparator Asynchronous Path Enable
#define CMPSS_COMPCTL_COMPDACE         0x8000U   // Comparator/DAC Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPHYSCTL register
//
//*************************************************************************************************
#define CMPSS_COMPHYSCTL_COMPHYS_S   0U
#define CMPSS_COMPHYSCTL_COMPHYS_M   0xFU   // Comparator Hysteresis Trim

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPSTS register
//
//*************************************************************************************************
#define CMPSS_COMPSTS_COMPHSTS     0x1U     // High Comparator Status
#define CMPSS_COMPSTS_COMPHLATCH   0x2U     // High Comparator Latched Status
#define CMPSS_COMPSTS_COMPLSTS     0x100U   // Low Comparator Status
#define CMPSS_COMPSTS_COMPLLATCH   0x200U   // Low Comparator Latched Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPSTSCLR register
//
//*************************************************************************************************
#define CMPSS_COMPSTSCLR_HLATCHCLR    0x2U     // High Comparator Latched Status Clear
#define CMPSS_COMPSTSCLR_HSYNCCLREN   0x4U     // High Comparator EPWMSYNCPER Clear Enable
#define CMPSS_COMPSTSCLR_LLATCHCLR    0x200U   // Low Comparator Latched Status Clear
#define CMPSS_COMPSTSCLR_LSYNCCLREN   0x400U   // Low Comparator EPWMSYNCPER Clear Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPDACHCTL register
//
//*************************************************************************************************
#define CMPSS_COMPDACHCTL_DACSOURCE       0x1U      // DAC Source Control
#define CMPSS_COMPDACHCTL_RAMPSOURCE_S    1U
#define CMPSS_COMPDACHCTL_RAMPSOURCE_M    0x1EU     // Ramp Generator Source Control
#define CMPSS_COMPDACHCTL_SELREF          0x20U     // DAC Reference Select
#define CMPSS_COMPDACHCTL_RAMPLOADSEL     0x40U     // Ramp Load Select
#define CMPSS_COMPDACHCTL_SWLOADSEL       0x80U     // Software Load Select
#define CMPSS_COMPDACHCTL_BLANKSOURCE_S   8U
#define CMPSS_COMPDACHCTL_BLANKSOURCE_M   0xF00U    // EPWMBLANK Source Select
#define CMPSS_COMPDACHCTL_BLANKEN         0x1000U   // EPWMBLANK Enable
#define CMPSS_COMPDACHCTL_RAMPDIR         0x2000U   // Ramp Generator Direction
#define CMPSS_COMPDACHCTL_FREESOFT_S      14U
#define CMPSS_COMPDACHCTL_FREESOFT_M      0xC000U   // Free/Soft Emulation Bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPDACHCTL2 register
//
//*************************************************************************************************
#define CMPSS_COMPDACHCTL2_DEENABLE          0x1U      // Diode Emulation mode enable
#define CMPSS_COMPDACHCTL2_DEACTIVESEL_S     1U
#define CMPSS_COMPDACHCTL2_DEACTIVESEL_M     0x3EU     // DEACTIVE source select
#define CMPSS_COMPDACHCTL2_BLANKSOURCEUSEL   0x100U    // BLANK source upper group select
#define CMPSS_COMPDACHCTL2_RAMPSOURCEUSEL    0x400U    // RAMP source upper group select
#define CMPSS_COMPDACHCTL2_XTRIGCFG_S        12U
#define CMPSS_COMPDACHCTL2_XTRIGCFG_M        0x3000U   // Ramp Generator Cross Trigger
                                                       // Configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the DACHVALS register
//
//*************************************************************************************************
#define CMPSS_DACHVALS_DACVAL_S   0U
#define CMPSS_DACHVALS_DACVAL_M   0xFFFU   // DAC Value Control

//*************************************************************************************************
//
// The following are defines for the bit fields in the DACHVALA register
//
//*************************************************************************************************
#define CMPSS_DACHVALA_DACVAL_S   0U
#define CMPSS_DACHVALA_DACVAL_M   0xFFFU   // DAC Value Control

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMPHCTLA register
//
//*************************************************************************************************
#define CMPSS_RAMPHCTLA_RAMPCLKDIV_S   0U
#define CMPSS_RAMPHCTLA_RAMPCLKDIV_M   0xFU   // Ramp Clock Divider Active Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMPHCTLS register
//
//*************************************************************************************************
#define CMPSS_RAMPHCTLS_RAMPCLKDIV_S   0U
#define CMPSS_RAMPHCTLS_RAMPCLKDIV_M   0xFU   // Ramp Clock Divider Shadow Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the DACLVALS register
//
//*************************************************************************************************
#define CMPSS_DACLVALS_DACVAL_S   0U
#define CMPSS_DACLVALS_DACVAL_M   0xFFFU   // DAC Value Control

//*************************************************************************************************
//
// The following are defines for the bit fields in the DACLVALA register
//
//*************************************************************************************************
#define CMPSS_DACLVALA_DACVAL_S   0U
#define CMPSS_DACLVALA_DACVAL_M   0xFFFU   // DAC Value Control

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMPHDLYA register
//
//*************************************************************************************************
#define CMPSS_RAMPHDLYA_DELAY_S   0U
#define CMPSS_RAMPHDLYA_DELAY_M   0x1FFFU   // High Ramp Delay Value Active

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMPHDLYS register
//
//*************************************************************************************************
#define CMPSS_RAMPHDLYS_DELAY_S   0U
#define CMPSS_RAMPHDLYS_DELAY_M   0x1FFFU   // High Ramp Delay Value Shadow

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTRIPLFILCTL register
//
//*************************************************************************************************
#define CMPSS_CTRIPLFILCTL_FILTINSEL_S   0U
#define CMPSS_CTRIPLFILCTL_FILTINSEL_M   0x7U      // Filter Input Select
#define CMPSS_CTRIPLFILCTL_SAMPWIN_S     3U
#define CMPSS_CTRIPLFILCTL_SAMPWIN_M     0x1F8U    // Sample Window
#define CMPSS_CTRIPLFILCTL_THRESH_S      9U
#define CMPSS_CTRIPLFILCTL_THRESH_M      0x7E00U   // Majority Voting Threshold
#define CMPSS_CTRIPLFILCTL_FILINIT       0x8000U   // Filter Initialization Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTRIPHFILCTL register
//
//*************************************************************************************************
#define CMPSS_CTRIPHFILCTL_FILTINSEL_S   0U
#define CMPSS_CTRIPHFILCTL_FILTINSEL_M   0x7U      // Filter Input Select
#define CMPSS_CTRIPHFILCTL_SAMPWIN_S     3U
#define CMPSS_CTRIPHFILCTL_SAMPWIN_M     0x1F8U    // Sample Window
#define CMPSS_CTRIPHFILCTL_THRESH_S      9U
#define CMPSS_CTRIPHFILCTL_THRESH_M      0x7E00U   // Majority Voting Threshold
#define CMPSS_CTRIPHFILCTL_FILINIT       0x8000U   // Filter Initialization Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPLOCK register
//
//*************************************************************************************************
#define CMPSS_COMPLOCK_COMPCTL      0x1U   // COMPCTL Lock
#define CMPSS_COMPLOCK_COMPHYSCTL   0x2U   // COMPHYSCTL Lock
#define CMPSS_COMPLOCK_DACCTL       0x4U   // DACCTL Lock
#define CMPSS_COMPLOCK_CTRIP        0x8U   // CTRIP Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the DACHVALS2 register
//
//*************************************************************************************************
#define CMPSS_DACHVALS2_DACVAL_S   0U
#define CMPSS_DACHVALS2_DACVAL_M   0xFFFU   // DAC Value Control

//*************************************************************************************************
//
// The following are defines for the bit fields in the DACLVALS2 register
//
//*************************************************************************************************
#define CMPSS_DACLVALS2_DACVAL_S   0U
#define CMPSS_DACLVALS2_DACVAL_M   0xFFFU   // DAC Value Control

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPDACLCTL register
//
//*************************************************************************************************
#define CMPSS_COMPDACLCTL_DACSOURCE       0x1U      // DAC Source Control
#define CMPSS_COMPDACLCTL_RAMPSOURCE_S    1U
#define CMPSS_COMPDACLCTL_RAMPSOURCE_M    0x1EU     // Ramp Generator Source Control
#define CMPSS_COMPDACLCTL_RAMPLOADSEL     0x40U     // Ramp Load Select
#define CMPSS_COMPDACLCTL_BLANKSOURCE_S   8U
#define CMPSS_COMPDACLCTL_BLANKSOURCE_M   0xF00U    // EPWMBLANK Source Select
#define CMPSS_COMPDACLCTL_BLANKEN         0x1000U   // EPWMBLANK Enable
#define CMPSS_COMPDACLCTL_RAMPDIR         0x2000U   // Ramp Generator Direction

//*************************************************************************************************
//
// The following are defines for the bit fields in the COMPDACLCTL2 register
//
//*************************************************************************************************
#define CMPSS_COMPDACLCTL2_BLANKSOURCEUSEL   0x100U   // BLANK source upper group select
#define CMPSS_COMPDACLCTL2_RAMPSOURCEUSEL    0x400U   // RAMP source upper group select

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMPLCTLA register
//
//*************************************************************************************************
#define CMPSS_RAMPLCTLA_RAMPCLKDIV_S   0U
#define CMPSS_RAMPLCTLA_RAMPCLKDIV_M   0xFU   // Ramp Clock Divider Active Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMPLCTLS register
//
//*************************************************************************************************
#define CMPSS_RAMPLCTLS_RAMPCLKDIV_S   0U
#define CMPSS_RAMPLCTLS_RAMPCLKDIV_M   0xFU   // Ramp Clock Divider Shadow Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMPLDLYA register
//
//*************************************************************************************************
#define CMPSS_RAMPLDLYA_DELAY_S   0U
#define CMPSS_RAMPLDLYA_DELAY_M   0x1FFFU   // Low Ramp Delay Value Active

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMPLDLYS register
//
//*************************************************************************************************
#define CMPSS_RAMPLDLYS_DELAY_S   0U
#define CMPSS_RAMPLDLYS_DELAY_M   0x1FFFU   // Low Ramp Delay Value Shadow

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTRIPLFILCLKCTL2 register
//
//*************************************************************************************************
#define CMPSS_CTRIPLFILCLKCTL2_CLKPRESCALEU_S   0U
#define CMPSS_CTRIPLFILCLKCTL2_CLKPRESCALEU_M   0xFFU   // Sample Clock Prescale Upper Bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTRIPHFILCLKCTL2 register
//
//*************************************************************************************************
#define CMPSS_CTRIPHFILCLKCTL2_CLKPRESCALEU_S   0U
#define CMPSS_CTRIPHFILCLKCTL2_CLKPRESCALEU_M   0xFFU   // Sample Clock Prescale Upper Bits



#endif
