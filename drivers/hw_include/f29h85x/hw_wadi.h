//###########################################################################
//
// FILE:    hw_wadi.h
//
// TITLE:   Definitions for the WADI registers.
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

#ifndef HW_WADI_H
#define HW_WADI_H

//*************************************************************************************************
//
// The following are defines for the WADI register offsets
//
//*************************************************************************************************
#define WADI_O_BLKCFG             0x0U    // WADI Block Clock Divider
#define WADI_O_SIGTOSIGCFG        0x4U    // Configuration for SIG1 to SIG2 comparison for WADI
                                          // Block
#define WADI_O_SIGTOSIG_PKCFG     0x8U    // Signal1 to Signal2 peak comparison value and margin
                                          // for WADI Block
#define WADI_O_SIGTOSIG_AVGCFG    0xCU    // Signal1 to Signal2 average comparison value and margin
                                          // for WADI Block
#define WADI_O_SIGTOSIG_DBOLAPA   0x10U   // Signal1 to Signal2 dead-band comparison difference and
                                          // margin for WADI Block
#define WADI_O_SIGTOSIG_DBOLAPB   0x14U   // Signal1 to Signal2 dead-band and Overlap compare
                                          // values for WADI Block
#define WADI_O_BLKTRIGCFG         0x18U   // The trigger configuration for SIG1 and SIG2 of the
                                          // WADI Block
#define WADI_O_SIG1CFG            0x40U   // Measurement configuration for SIG1 of WADI Block
#define WADI_O_SIG1CMPA           0x44U   // Envelope-1 compare value and margin for SIG1 for WADI
                                          // Block
#define WADI_O_SIG1CMPB           0x48U   // Envelope-2 compare value and margin for SIG1 for WADI
                                          // Block
#define WADI_O_SIG1PKCFG          0x4CU   // Peak of the aggregation compare configuration for 
                                          // SIG1 of WADI Block
#define WADI_O_SIG1AVGCFG         0x50U   // Average of the aggregation comparison configuration
                                          // for SIG1 of WADI Block
#define WADI_O_SIG1EDGECFG        0x54U   // Frequency measurement  configuration for SIG1 of WADI
                                          // Block
#define WADI_O_SIG1EDGEMVWCFG     0x58U   // Moving Window Configuration for SIG1 of WADI Block
#define WADI_O_SIG2CFG            0x80U   // Measurement configuration for SIG2 of WADI Block
#define WADI_O_SIG2CMPA           0x84U   // Compare value A and +/- margin for SIG2 for WADI Block
#define WADI_O_SIG2CMPB           0x88U   // Compare value B and +/- margin for SIG2 for WADI Block
#define WADI_O_SIG2PKCFG          0x8CU   // Peak of the aggregation compare configuration for 
                                          // SIG2 of WADI Block
#define WADI_O_SIG2AVGCFG         0x90U   // Average of the aggregation comparison configuration
                                          // for SIG2 of WADI Block
#define WADI_O_SIG2EDGECFG        0x94U   // Frequency measurement  configuration for SIG2 of WADI
                                          // Block
#define WADI_O_SIG2EDGEMVWCFG     0x98U   // Moving Window Configuration for SIG2 of WADI Block
#define WADI_O_BLKERRSTS          0xC0U   // Block status register
#define WADI_O_BLKERRINFO         0xC4U   // Block count value of failed register
#define WADI_O_BLKERRCFG          0xC8U   // Block Debug additional info.
#define WADI_O_SSS_EVTMASK        0xCCU   // Mask to combine Block errors for trigger of SSS in
                                          // event word Output by WADI block
#define WADI_O_PARTEST            0xE8U   // Enables parity test

#define WADI_O_BASETIMERLOW         0x0U     // Read only value for lower word of the base timer.
#define WADI_O_BASETIMERHIGH        0x4U     // Upper word of the base timer and trigger to start
                                             // the timer.
#define WADI_O_INTSTS               0x8U     // Gives the block wise aggregated raw error status
                                             // that shall trigger the interrupt.
#define WADI_O_INTSTSMASK           0xCU     // Provides mask for application to suppress or allow
                                             // a particular block related errors to cause
                                             // interrupt or not
#define WADI_O_BLKSMASKSTS          0x10U    // This is AND combination of active high indication
                                             // of block-wise status asserting an interrupt.
#define WADI_O_INTSTSCLR            0x14U    // Provides way for application to clear the interrupt
                                             // status.
#define WADI_O_INTSTSFRC            0x18U    // Allows emulation of the RIS to raise interrupt in
                                             // software
#define WADI_O_SIGSYNCFILTCFG       0x1CU    // Each input SIG to be connected through synchroniser
                                             // or not
#define WADI_O_TRIGSYNCFILTCFG      0x20U    // Each trigger to be connected through synchroniser
                                             // or not
#define WADI_O_REVISION             0x3CU    // IP Revision
#define WADI_O_DMATRIGSTS           0x40U    // Status of the DMA triggers active
#define WADI_O_DMATRIGEN            0x44U    // Mask to enable individual trigger cause
#define WADI_O_DMASTSUPDATE         0x48U    // Indicates the register set updated post DMA write
#define WADI_O_DMAFILTWRCFG         0x4CU    // DMA writes Filter enable for each of WADI & SSS
                                             // blocks
#define WADI_O_CFGREGLOCK           0xA4U    // Configuration Register Lock
#define WADI_O_CFGREGCOMMIT         0xA8U    // Configuration Register Commit
#define WADI_O_OPERREGLOCK          0xACU    // Operating Register Lock
#define WADI_O_OPERREGCOMMIT        0xB0U    // Operating Register Commit
#define WADI_O_SSS_EVTTRIG          0xB8U    // Event trigger word output by WADI instance for SSS
#define WADI_O_SSS_OUTEVTSTS        0xBCU    // Status of the active event
#define WADI_O_SSS_BLK1_2OUTSEL     0xC0U    // Mux select word for outputs 0-3
#define WADI_O_SSS_BLK3_4OUTSEL     0xC4U    // Mux select word for outputs 4-7
#define WADI_O_SSS_OUTEVT1LINKCFG   0xE0U    // Output event1 Link configuration
#define WADI_O_SSS_OUTEVT2LINKCFG   0xE4U    // Output event2 link configuration
#define WADI_O_SSS_OUTEVT3LINKCFG   0xE8U    // Output event3 link configuration
#define WADI_O_SSS_OUTEVT4LINKCFG   0xECU    // Output event4 link configuration
#define WADI_O_SSS_OUTEVT5LINKCFG   0xF0U    // Output event5 link configuration
#define WADI_O_SSS_OUTEVT6LINKCFG   0xF4U    // Output event6 link configuration
#define WADI_O_SSS_OUTEVT7LINKCFG   0xF8U    // Output event7 link configuration
#define WADI_O_SSS_OUTEVT8LINKCFG   0xFCU    // Output event8 link configuration
#define WADI_O_SSS_EVT1CFG          0x100U   // Event1 that compares to trigger word SSS_EVTTRIG
#define WADI_O_SSS_EVT2CFG          0x104U   // Event2 that compares to trigger word SSS_EVTTRIG
#define WADI_O_SSS_EVT3CFG          0x108U   // Event3 that compares to trigger word SSS_EVTTRIG
#define WADI_O_SSS_EVT4CFG          0x10CU   // Event4 that compares to trigger word SSS_EVTTRIG
#define WADI_O_SSS_TRIGEVT1_4CFG    0x110U   // Configuration for using trigger word in specific
                                             // manner
#define WADI_O_SSS_BLKSOUTEVT1CFG   0x180U   // Output event1 to be applied for output
#define WADI_O_SSS_BLKSOUTEVT2CFG   0x184U   // Output event2 to be applied for output
#define WADI_O_SSS_BLKSOUTEVT3CFG   0x188U   // Output event3 to be applied for output
#define WADI_O_SSS_BLKSOUTEVT4CFG   0x18CU   // Output event4 to be applied for output
#define WADI_O_SSS_OUTEVT1TRIGCFG   0x190U   // Output event1 configuration for triggers, link
#define WADI_O_SSS_OUTEVT2TRIGCFG   0x194U   // Output event2 configuration for triggers, link
#define WADI_O_SSS_OUTEVT3TRIGCFG   0x198U   // Output event3 configuration for triggers, link
#define WADI_O_SSS_OUTEVT4TRIGCFG   0x19CU   // Output event4 configuration for triggers, link
#define WADI_O_SSS_OUTEVT1DUR       0x1A0U   // Output event1 configuration of delays
#define WADI_O_SSS_OUTEVT2DUR       0x1A4U   // Output event2 configuration of delays
#define WADI_O_SSS_OUTEVT3DUR       0x1A8U   // Output event3 configuration of delays
#define WADI_O_SSS_OUTEVT4DUR       0x1ACU   // Output event4 configuration of delays
#define WADI_O_SSS_EVT5CFG          0x200U   // Event5 that compares to trigger word SSS_EVTTRIG
#define WADI_O_SSS_EVT6CFG          0x204U   // Event6 that compares to trigger word SSS_EVTTRIG
#define WADI_O_SSS_EVT7CFG          0x208U   // Event7 that compares to trigger word SSS_EVTTRIG
#define WADI_O_SSS_EVT8CFG          0x20CU   // Event8 that compares to trigger word SSS_EVTTRIG
#define WADI_O_SSS_TRIGEVT5_8CFG    0x210U   // Configuration for using trigger word in specific
                                             // manner
#define WADI_O_SSS_BLKSOUTEVT5CFG   0x280U   // Output event5 to be applied for output
#define WADI_O_SSS_BLKSOUTEVT6CFG   0x284U   // Output event6 to be applied for output
#define WADI_O_SSS_BLKSOUTEVT7CFG   0x288U   // Output event7 to be applied for output
#define WADI_O_SSS_BLKSOUTEVT8CFG   0x28CU   // Output event8 to be applied for output
#define WADI_O_SSS_OUTEVT5TRIGCFG   0x290U   // Output event5 configuration for triggers, link
#define WADI_O_SSS_OUTEVT6TRIGCFG   0x294U   // Output event6 configuration for triggers, link
#define WADI_O_SSS_OUTEVT7TRIGCFG   0x298U   // Output event7 configuration for triggers, link
#define WADI_O_SSS_OUTEVT8TRIGCFG   0x29CU   // Output event8 configuration for triggers, link
#define WADI_O_SSS_OUTEVT5DUR       0x2A0U   // Output event5 configuration of delays
#define WADI_O_SSS_OUTEVT6DUR       0x2A4U   // Output event6 configuration of delays
#define WADI_O_SSS_OUTEVT7DUR       0x2A8U   // Output event7 configuration of delays
#define WADI_O_SSS_OUTEVT8DUR       0x2ACU   // Output event8 configuration of delays
#define WADI_O_SSS_PARTEST          0x2C8U   // Enables parity test


//*************************************************************************************************
//
// The following are defines for the bit fields in the BLKCFG register
//
//*************************************************************************************************
#define WADI_BLKCFG_CLKEN       0x10U         // Enables clock for WADI block
#define WADI_BLKCFG_SIG1IN_S    8U
#define WADI_BLKCFG_SIG1IN_M    0x1F00U       // Selects the input signal for the SIG1 input of
                                              // WADI block
#define WADI_BLKCFG_SIG2IN_S    16U
#define WADI_BLKCFG_SIG2IN_M    0x1F0000U     // Selects the input signal for the SIG2 input of
                                              // WADI block
#define WADI_BLKCFG_TRIG1IN_S   24U
#define WADI_BLKCFG_TRIG1IN_M   0xF000000U    // Selects trigger input signal for SIG1 analysis
#define WADI_BLKCFG_TRIG2IN_S   28U
#define WADI_BLKCFG_TRIG2IN_M   0xF0000000U   // Selects  trigger input signal for SIG2 analysis

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIGTOSIGCFG register
//
//*************************************************************************************************
#define WADI_SIGTOSIGCFG_CMP_S                0U
#define WADI_SIGTOSIGCFG_CMP_M                0xFFFFU       // Compare value for difference of
                                                            // width/sum measurement
#define WADI_SIGTOSIGCFG_CMPMARGIN_S          16U
#define WADI_SIGTOSIGCFG_CMPMARGIN_M          0xF0000U      // Margin of error for difference of
                                                            // width/sum measurement
#define WADI_SIGTOSIGCFG_SIGTOSIG_CMPEN       0x1000000U    // Enables the signal to signal compare
#define WADI_SIGTOSIGCFG_SIGTOSIG_DBCMPEN     0x4000000U    // Enables the deadband check between
                                                            // two signals
#define WADI_SIGTOSIGCFG_SIGTOSIG_OLAPCMPEN   0x8000000U    // Enables the overlap check between
                                                            // two signals
#define WADI_SIGTOSIGCFG_DBCMPTYPE            0x10000000U   // Selects the check type for deadband
                                                            // control
#define WADI_SIGTOSIGCFG_OLAPCMPTYPE          0x20000000U   // Selects the check type for overlap
                                                            // control

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIGTOSIG_PKCFG register
//
//*************************************************************************************************
#define WADI_SIGTOSIG_PKCFG_PKCMP_S         0U
#define WADI_SIGTOSIG_PKCFG_PKCMP_M         0xFFFFFFU     // Compare value for difference of peak
                                                          // measurement
#define WADI_SIGTOSIG_PKCFG_PKCMPMARGIN_S   24U
#define WADI_SIGTOSIG_PKCFG_PKCMPMARGIN_M   0xFF000000U   // Margin of error for difference of peak
                                                          // measurement

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIGTOSIG_AVGCFG register
//
//*************************************************************************************************
#define WADI_SIGTOSIG_AVGCFG_AVGCMP_S         0U
#define WADI_SIGTOSIG_AVGCFG_AVGCMP_M         0xFFFFFFU     // Compare difference for measurements
                                                            // average of both signals
#define WADI_SIGTOSIG_AVGCFG_AVGCMPMARGIN_S   24U
#define WADI_SIGTOSIG_AVGCFG_AVGCMPMARGIN_M   0xFF000000U   // Margin for difference of average of
                                                            // both signals

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIGTOSIG_DBOLAPA register
//
//*************************************************************************************************
#define WADI_SIGTOSIG_DBOLAPA_DBCMPA_S           0U
#define WADI_SIGTOSIG_DBOLAPA_DBCMPA_M           0xFFU         // Compare value for dead-band
                                                               // between both signals
#define WADI_SIGTOSIG_DBOLAPA_OLAPCMPA_S         8U
#define WADI_SIGTOSIG_DBOLAPA_OLAPCMPA_M         0xFFFF00U     // Compare value for Overlap between
                                                               // both signal levels
#define WADI_SIGTOSIG_DBOLAPA_OLAPCMPAMARGIN_S   24U
#define WADI_SIGTOSIG_DBOLAPA_OLAPCMPAMARGIN_M   0x3F000000U   // Margin of variation of overlap
                                                               // between both signals

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIGTOSIG_DBOLAPB register
//
//*************************************************************************************************
#define WADI_SIGTOSIG_DBOLAPB_DBCMPB_S           0U
#define WADI_SIGTOSIG_DBOLAPB_DBCMPB_M           0xFFU         // Compare value for dead-band
                                                               // between both signals
#define WADI_SIGTOSIG_DBOLAPB_OLAPCMPB_S         8U
#define WADI_SIGTOSIG_DBOLAPB_OLAPCMPB_M         0xFFFF00U     // Compare value for Overlap between
                                                               // both signal levels
#define WADI_SIGTOSIG_DBOLAPB_OLAPCMPBMARGIN_S   24U
#define WADI_SIGTOSIG_DBOLAPB_OLAPCMPBMARGIN_M   0x3F000000U   // Margin of variation of overlap
                                                               // between both signals

//*************************************************************************************************
//
// The following are defines for the bit fields in the BLKTRIGCFG register
//
//*************************************************************************************************
#define WADI_BLKTRIGCFG_TRIG1TYPE_S   0U
#define WADI_BLKTRIGCFG_TRIG1TYPE_M   0x7U         // The trigger type for SIG1 signal input.
#define WADI_BLKTRIGCFG_TRIG1SWEN     0x100U       // Software trigger for the SIG1
#define WADI_BLKTRIGCFG_TRIG2TYPE_S   16U
#define WADI_BLKTRIGCFG_TRIG2TYPE_M   0x70000U     // The trigger type for SIG2 signal input.
#define WADI_BLKTRIGCFG_TRIG2SWEN     0x1000000U   // Software trigger for the SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1CFG register
//
//*************************************************************************************************
#define WADI_SIG1CFG_SIGPOL_S     0U
#define WADI_SIG1CFG_SIGPOL_M     0x3U         // Starting edge select as rise, fall or either
#define WADI_SIG1CFG_EDGESPAN_S   8U
#define WADI_SIG1CFG_EDGESPAN_M   0xF00U       // Defines span of edges of given type to measure
                                               // the width.
#define WADI_SIG1CFG_NUMAGGR_S    16U
#define WADI_SIG1CFG_NUMAGGR_M    0x70000U     // Defines number of measurements to be aggregated
#define WADI_SIG1CFG_AGGRMODE_S   24U
#define WADI_SIG1CFG_AGGRMODE_M   0x3000000U   // Whether peak or average or both measurements to
                                               // compute

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1CMPA register
//
//*************************************************************************************************
#define WADI_SIG1CMPA_CMPA_S         0U
#define WADI_SIG1CMPA_CMPA_M         0xFFFFFFU     // Compare A value for measured count of the
                                                   // SIG1
#define WADI_SIG1CMPA_CMPAMARGIN_S   24U
#define WADI_SIG1CMPA_CMPAMARGIN_M   0xFF000000U   // +/- Margin for compare-1 around
                                                   // SIG1CMPA[CMPA]

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1CMPB register
//
//*************************************************************************************************
#define WADI_SIG1CMPB_CMPB_S         0U
#define WADI_SIG1CMPB_CMPB_M         0xFFFFFFU     // Compare B value for measured count of the
                                                   // SIG1
#define WADI_SIG1CMPB_CMPBMARGIN_S   24U
#define WADI_SIG1CMPB_CMPBMARGIN_M   0xFF000000U   // +/- Margin for compare B around
                                                   // SIG1CMPB[CMPB]

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1PKCFG register
//
//*************************************************************************************************
#define WADI_SIG1PKCFG_CMP_S         0U
#define WADI_SIG1PKCFG_CMP_M         0xFFFFFFU     // Compare value for peak measurements of SIG1
#define WADI_SIG1PKCFG_CMPMARGIN_S   24U
#define WADI_SIG1PKCFG_CMPMARGIN_M   0xFF000000U   // Margin of variation for peak measurements of
                                                   // SIG1

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1AVGCFG register
//
//*************************************************************************************************
#define WADI_SIG1AVGCFG_CMP_S         0U
#define WADI_SIG1AVGCFG_CMP_M         0xFFFFFFU     // Compare value for average of measurements of
                                                    // SIG1
#define WADI_SIG1AVGCFG_CMPMARGIN_S   24U
#define WADI_SIG1AVGCFG_CMPMARGIN_M   0xFF000000U   // Margin for average of measurements of SIG1

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1EDGECFG register
//
//*************************************************************************************************
#define WADI_SIG1EDGECFG_TIMEWNDOW_S   0U
#define WADI_SIG1EDGECFG_TIMEWNDOW_M   0xFFFFFFFU    // Time window to count edges of SIG1
#define WADI_SIG1EDGECFG_CNTEN         0x80000000U   // SIG1 Edge count mode enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG1EDGEMVWCFG register
//
//*************************************************************************************************
#define WADI_SIG1EDGEMVWCFG_MVWTIME_S   0U
#define WADI_SIG1EDGEMVWCFG_MVWTIME_M   0x3FFFFFFU    // Moving Window time
#define WADI_SIG1EDGEMVWCFG_MVWCNT_S    28U
#define WADI_SIG1EDGEMVWCFG_MVWCNT_M    0x30000000U   // Moving window count:number of MWVTIME
                                                      // windows to accumulate
#define WADI_SIG1EDGEMVWCFG_MVWEN       0x80000000U   // Moving window operation enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2CFG register
//
//*************************************************************************************************
#define WADI_SIG2CFG_SIGPOL_S     0U
#define WADI_SIG2CFG_SIGPOL_M     0x3U         // Starting edge select as rise, fall or either
#define WADI_SIG2CFG_EDGESPAN_S   8U
#define WADI_SIG2CFG_EDGESPAN_M   0xF00U       // Defines span of edges of given type to measure
                                               // the width.
#define WADI_SIG2CFG_NUMAGGR_S    16U
#define WADI_SIG2CFG_NUMAGGR_M    0x70000U     // Defines number of measurements to be aggregated
#define WADI_SIG2CFG_AGGRMODE_S   24U
#define WADI_SIG2CFG_AGGRMODE_M   0x3000000U   // Whether peak or average or both measurements to
                                               // compute

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2CMPA register
//
//*************************************************************************************************
#define WADI_SIG2CMPA_CMPA_S         0U
#define WADI_SIG2CMPA_CMPA_M         0xFFFFFFU     // Compare A value for measured count of the
                                                   // SIG2
#define WADI_SIG2CMPA_CMPAMARGIN_S   24U
#define WADI_SIG2CMPA_CMPAMARGIN_M   0xFF000000U   // +/- Margin for compare-1 around
                                                   // SIG2CMPA[CMPA]

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2CMPB register
//
//*************************************************************************************************
#define WADI_SIG2CMPB_CMPB_S         0U
#define WADI_SIG2CMPB_CMPB_M         0xFFFFFFU     // Compare B value for measured count of the
                                                   // SIG2
#define WADI_SIG2CMPB_CMPBMARGIN_S   24U
#define WADI_SIG2CMPB_CMPBMARGIN_M   0xFF000000U   // +/- Margin for compare B around
                                                   // SIG2CMPB[CMPB]

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2PKCFG register
//
//*************************************************************************************************
#define WADI_SIG2PKCFG_CMP_S         0U
#define WADI_SIG2PKCFG_CMP_M         0xFFFFFFU     // Compare value for peak measurements of SIG2
#define WADI_SIG2PKCFG_CMPMARGIN_S   24U
#define WADI_SIG2PKCFG_CMPMARGIN_M   0xFF000000U   // Margin of variation for peak measurements of
                                                   // SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2AVGCFG register
//
//*************************************************************************************************
#define WADI_SIG2AVGCFG_CMP_S         0U
#define WADI_SIG2AVGCFG_CMP_M         0xFFFFFFU     // Compare value for average of measurements of
                                                    // SIG2
#define WADI_SIG2AVGCFG_CMPMARGIN_S   24U
#define WADI_SIG2AVGCFG_CMPMARGIN_M   0xFF000000U   // Margin for average of measurements of SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2EDGECFG register
//
//*************************************************************************************************
#define WADI_SIG2EDGECFG_TIMEWNDOW_S   0U
#define WADI_SIG2EDGECFG_TIMEWNDOW_M   0xFFFFFFFU    // Time window to count edges of SIG2
#define WADI_SIG2EDGECFG_CNTEN         0x80000000U   // SIG2 Edge count mode enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIG2EDGEMVWCFG register
//
//*************************************************************************************************
#define WADI_SIG2EDGEMVWCFG_MVWTIME_S   0U
#define WADI_SIG2EDGEMVWCFG_MVWTIME_M   0x3FFFFFFU    // Moving Window time
#define WADI_SIG2EDGEMVWCFG_MVWCNT_S    28U
#define WADI_SIG2EDGEMVWCFG_MVWCNT_M    0x30000000U   // Moving window count:number of MWVTIME
                                                      // windows to accumulate
#define WADI_SIG2EDGEMVWCFG_MVWEN       0x80000000U   // Moving window operation enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the BLKERRSTS register
//
//*************************************************************************************************
#define WADI_BLKERRSTS_SIG1CMPAERR_S            0U
#define WADI_BLKERRSTS_SIG1CMPAERR_M            0x3U          // Compare A margin error for the
                                                              // SIG1 measurements
#define WADI_BLKERRSTS_SIG1PKERR_S              2U
#define WADI_BLKERRSTS_SIG1PKERR_M              0xCU          // Error of SIG1 peak measurements
#define WADI_BLKERRSTS_SIG1AVGERR_S             4U
#define WADI_BLKERRSTS_SIG1AVGERR_M             0x30U         // Average of aggregation error for
                                                              // the SIG1 measurements
#define WADI_BLKERRSTS_SIG1CMPBERR_S            6U
#define WADI_BLKERRSTS_SIG1CMPBERR_M            0xC0U         // Compare B margin error for the
                                                              // SIG1 measurements
#define WADI_BLKERRSTS_SIG2CMPAERR_S            8U
#define WADI_BLKERRSTS_SIG2CMPAERR_M            0x300U        // Compare A margin error for the
                                                              // SIG2 measurements
#define WADI_BLKERRSTS_SIG2PKERR_S              10U
#define WADI_BLKERRSTS_SIG2PKERR_M              0xC00U        // Error of SIG2 peak measurements
#define WADI_BLKERRSTS_SIG2AVGERR_S             12U
#define WADI_BLKERRSTS_SIG2AVGERR_M             0x3000U       // Average of aggregation error for
                                                              // the SIG2 measurements
#define WADI_BLKERRSTS_SIG2CMPBERR_S            14U
#define WADI_BLKERRSTS_SIG2CMPBERR_M            0xC000U       // Compare B margin error for the
                                                              // SIG2 measurements
#define WADI_BLKERRSTS_SIGTOSIG_CMPERR_S        16U
#define WADI_BLKERRSTS_SIGTOSIG_CMPERR_M        0x30000U      // Compare error for the SIGTOSIG
                                                              // measurements difference
#define WADI_BLKERRSTS_SIGTOSIG_PKERR_S         18U
#define WADI_BLKERRSTS_SIGTOSIG_PKERR_M         0xC0000U      // Error of SIGTOSIG peak
                                                              // measurements difference
#define WADI_BLKERRSTS_SIGTOSIG_AVGERR_S        20U
#define WADI_BLKERRSTS_SIGTOSIG_AVGERR_M        0x300000U     // Average error for the SIGTOSIG
                                                              // measurements difference
#define WADI_BLKERRSTS_SIGTOSIG_DBCMPAERR       0x400000U     // Deadband Compare A error for the
                                                              // SIGTOSIG measurements
#define WADI_BLKERRSTS_SIGTOSIG_DBCMPBERR       0x800000U     // Deadband Compare B Error for the
                                                              // SIGTOSIG measurements
#define WADI_BLKERRSTS_SIGTOSIG_OLAPCMPAERR_S   24U
#define WADI_BLKERRSTS_SIGTOSIG_OLAPCMPAERR_M   0x3000000U    // Overlap check Compare A error of
                                                              // SIGTOSIG measurements
#define WADI_BLKERRSTS_SIGTOSIG_OLAPCMPBERR_S   26U
#define WADI_BLKERRSTS_SIGTOSIG_OLAPCMPBERR_M   0xC000000U    // Overlap check Compare B error of
                                                              // SIGTOSIG measurements
#define WADI_BLKERRSTS_SIG_ERR                  0x40000000U   // Measurement error of unexpected
                                                              // waveform anomaly
#define WADI_BLKERRSTS_SIGTOSIG_ERR             0x80000000U   // Mismatch in number of readings
                                                              // between signals

//*************************************************************************************************
//
// The following are defines for the bit fields in the BLKERRINFO register
//
//*************************************************************************************************
#define WADI_BLKERRINFO_ERRCNT_S    0U
#define WADI_BLKERRINFO_ERRCNT_M    0x1FFFFFFU    // First failed count of SIGx multiplexed  to
                                                  // this register
#define WADI_BLKERRINFO_ERRTYPE_S   28U
#define WADI_BLKERRINFO_ERRTYPE_M   0x70000000U   // Type of error of the registered count

//*************************************************************************************************
//
// The following are defines for the bit fields in the BLKERRCFG register
//
//*************************************************************************************************
#define WADI_BLKERRCFG_ERRCNTSEL_S         0U
#define WADI_BLKERRCFG_ERRCNTSEL_M         0x3U         // Selects the count to be multiplexed for
                                                        // debug
#define WADI_BLKERRCFG_OVERIDESIG1_S       8U
#define WADI_BLKERRCFG_OVERIDESIG1_M       0xF00U       // Drives the signal correction for
                                                        // outputting the SIG1
#define WADI_BLKERRCFG_OVERIDESIG2_S       16U
#define WADI_BLKERRCFG_OVERIDESIG2_M       0xF0000U     // Drives the signal correction for
                                                        // outputting the SIG2
#define WADI_BLKERRCFG_OVERIDESIGTOSIG_S   24U
#define WADI_BLKERRCFG_OVERIDESIGTOSIG_M   0xF000000U   // Drives the correction to both signals if
                                                        // SIGTOSIG error

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVTMASK register
//
//*************************************************************************************************
#define WADI_SSS_EVTMASK_SIG1MASK_S   0U
#define WADI_SSS_EVTMASK_SIG1MASK_M   0x7FFFU    // Mask for specific WADI events to SSS event word
                                                 // or not
#define WADI_SSS_EVTMASK_SIG2MASK_S   16U
#define WADI_SSS_EVTMASK_SIG2MASK_M   0xF0000U   // Mask for specific WADI events to SSS event word
                                                 // or not

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARTEST register
//
//*************************************************************************************************
#define WADI_PARTEST_TESTEN_S   0U
#define WADI_PARTEST_TESTEN_M   0xFU   // Parity test enable configuration


//*************************************************************************************************
//
// The following are defines for the bit fields in the BASETIMERHIGH register
//
//*************************************************************************************************
#define WADI_BASETIMERHIGH_HIGHWORD_S    0U
#define WADI_BASETIMERHIGH_HIGHWORD_M    0xFFFFFFFU    // Upper word of the base timer
#define WADI_BASETIMERHIGH_ENBASETIMER   0x80000000U   // Start base timer trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTSTS register
//
//*************************************************************************************************
#define WADI_INTSTS_BLK1INT            0x1U          // Interrupt status by ORing all WADI block
                                                     // errors
#define WADI_INTSTS_BLK2INT            0x2U          // Interrupt status by ORing all WADI block
                                                     // errors
#define WADI_INTSTS_BLK3INT            0x4U          // Interrupt status by ORing all WADI block
                                                     // errors
#define WADI_INTSTS_BLK4INT            0x8U          // Interrupt status by ORing all WADI block
                                                     // errors
#define WADI_INTSTS_SIGBLKSINT         0x40000000U   // ORed int status of measurement error for
                                                     // all WADI blocks
#define WADI_INTSTS_SIGTOSIG_BLKSINT   0x80000000U   // ORed int status of mismatch error for all
                                                     // WADI blocks

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTSTSMASK register
//
//*************************************************************************************************
#define WADI_INTSTSMASK_BLKSMASK_S          0U
#define WADI_INTSTSMASK_BLKSMASK_M          0xFFFFU       // Line wise mask to propagate interrupt
                                                          // or not
#define WADI_INTSTSMASK_SIGBLKSMASK         0x40000000U   // Line wise mask to propagate interrupt
                                                          // or not
#define WADI_INTSTSMASK_SIGTOSIG_BLKSMASK   0x80000000U   // Line wise mask to propagate interrupt
                                                          // or not

//*************************************************************************************************
//
// The following are defines for the bit fields in the BLKSMASKSTS register
//
//*************************************************************************************************
#define WADI_BLKSMASKSTS_BLKSMASK_S     0U
#define WADI_BLKSMASKSTS_BLKSMASK_M     0xFFFFU       // This is AND of INTSTS and INTSTSMASK
#define WADI_BLKSMASKSTS_SIGBLKS        0x40000000U   // This is AND of INTSTS and INTSTSMASK
#define WADI_BLKSMASKSTS_SIGTOSIGBLKS   0x80000000U   // This is AND of INTSTS and INTSTSMASK

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTSTSCLR register
//
//*************************************************************************************************
#define WADI_INTSTSCLR_BLK1INT            0x1U          // Clears the status of the INTSTS of Block
                                                        // 1
#define WADI_INTSTSCLR_BLK2INT            0x2U          // Clears the status of the INTSTS of Block
                                                        // 2
#define WADI_INTSTSCLR_BLK3INT            0x4U          // Clears the status of the INTSTS of Block
                                                        // 3
#define WADI_INTSTSCLR_BLK4INT            0x8U          // Clears the status of the INTSTS of Block
                                                        // 4
#define WADI_INTSTSCLR_SIGBLKSINT         0x40000000U   // Clears the status of all block's
                                                        // INTSTS[SIGBLKSINT]
#define WADI_INTSTSCLR_SIGTOSIG_BLKSINT   0x80000000U   // Clears the status of all block's
                                                        // INTSTS[SIGTOSIG_BLKSINT]

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTSTSFRC register
//
//*************************************************************************************************
#define WADI_INTSTSFRC_BLK1INT            0x1U          // Allows software force of WADI Block
                                                        // interrupt
#define WADI_INTSTSFRC_BLK2INT            0x2U          // Allows software force of WADI Block
                                                        // interrupt
#define WADI_INTSTSFRC_BLK3INT            0x4U          // Allows software force of WADI Block
                                                        // interrupt
#define WADI_INTSTSFRC_BLK4INT            0x8U          // Allows software force of WADI Block
                                                        // interrupt
#define WADI_INTSTSFRC_SIGBLKSINT         0x40000000U   // Allows software force of WADI Block
                                                        // interrupt
#define WADI_INTSTSFRC_SIGTOSIG_BLKSINT   0x80000000U   // Allows software force of WADI Block
                                                        // interrupt

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIGSYNCFILTCFG register
//
//*************************************************************************************************
#define WADI_SIGSYNCFILTCFG_BLKS_SIGS_SYNCFILT_S   0U
#define WADI_SIGSYNCFILTCFG_BLKS_SIGS_SYNCFILT_M   0xFFU   // Selects SIG is synchronised and
                                                           // filtered or not

//*************************************************************************************************
//
// The following are defines for the bit fields in the TRIGSYNCFILTCFG register
//
//*************************************************************************************************
#define WADI_TRIGSYNCFILTCFG_BLKS_TRIG_SYNCFILT_S   0U
#define WADI_TRIGSYNCFILTCFG_BLKS_TRIG_SYNCFILT_M   0xFFU   // Selects Trigger input is
                                                            // synchronised and filtered or not

//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define WADI_REVISION_MINOR_S    0U
#define WADI_REVISION_MINOR_M    0x3FU         // Minor Revision Number
#define WADI_REVISION_CUSTOM_S   6U
#define WADI_REVISION_CUSTOM_M   0xC0U         // Custom Module Number
#define WADI_REVISION_MAJOR_S    8U
#define WADI_REVISION_MAJOR_M    0x700U        // Major Revision Number
#define WADI_REVISION_RTL_S      11U
#define WADI_REVISION_RTL_M      0xF800U       // Design Release Number
#define WADI_REVISION_FUNC_S     16U
#define WADI_REVISION_FUNC_M     0xFFF0000U    // Functional Release Number
#define WADI_REVISION_SCHEME_S   30U
#define WADI_REVISION_SCHEME_M   0xC0000000U   // Defines Scheme for Module

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMATRIGSTS register
//
//*************************************************************************************************
#define WADI_DMATRIGSTS_BLK1_DMAEVT   0x1U          // Indicates the WADI Block event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_BLK2_DMAEVT   0x2U          // Indicates the WADI Block event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_BLK3_DMAEVT   0x4U          // Indicates the WADI Block event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_BLK4_DMAEVT   0x8U          // Indicates the WADI Block event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_EVT1      0x10000U      // Indicates the SSS Event event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_EVT2      0x20000U      // Indicates the SSS Event for DMA trigger
#define WADI_DMATRIGSTS_SSS_EVT3      0x40000U      // Indicates the SSS Event for DMA trigger
#define WADI_DMATRIGSTS_SSS_EVT4      0x80000U      // Indicates the SSS Event for DMA trigger
#define WADI_DMATRIGSTS_SSS_EVT5      0x100000U     // Indicates the SSS Event for DMA trigger
#define WADI_DMATRIGSTS_SSS_EVT6      0x200000U     // Indicates the SSS Event for DMA trigger
#define WADI_DMATRIGSTS_SSS_EVT7      0x400000U     // Indicates the SSS Event for DMA trigger
#define WADI_DMATRIGSTS_SSS_EVT8      0x800000U     // Indicates the SSS Event for DMA trigger
#define WADI_DMATRIGSTS_SSS_OUTEVT1   0x1000000U    // Indicates the SSS output event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_OUTEVT2   0x2000000U    // Indicates the SSS output event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_OUTEVT3   0x4000000U    // Indicates the SSS output event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_OUTEVT4   0x8000000U    // Indicates the SSS output event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_OUTEVT5   0x10000000U   // Indicates the SSS output event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_OUTEVT6   0x20000000U   // Indicates the SSS output event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_OUTEVT7   0x40000000U   // Indicates the SSS output event for DMA
                                                    // trigger
#define WADI_DMATRIGSTS_SSS_OUTEVT8   0x80000000U   // Indicates the SSS output event for DMA
                                                    // trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMATRIGEN register
//
//*************************************************************************************************
#define WADI_DMATRIGEN_BLKSDMAEVT_S         0U
#define WADI_DMATRIGEN_BLKSDMAEVT_M         0xFFFFU       // WADI Block event enables for DMA
                                                          // request trigger
#define WADI_DMATRIGEN_SSS_EVT1_4DMA_S      16U
#define WADI_DMATRIGEN_SSS_EVT1_4DMA_M      0xF0000U      // SSS Event word Set-1 enables for DMA
                                                          // request Trigger
#define WADI_DMATRIGEN_SSS_EVT5_8DMA_S      20U
#define WADI_DMATRIGEN_SSS_EVT5_8DMA_M      0xF00000U     // SSS Event word Set-2 enables for DMA
                                                          // request Trigger
#define WADI_DMATRIGEN_SSS_OUTEVT1_4DMA_S   24U
#define WADI_DMATRIGEN_SSS_OUTEVT1_4DMA_M   0xF000000U    // SSS output event 1 to 4 enables for
                                                          // DMA request Trigger
#define WADI_DMATRIGEN_SSS_OUTEVT5_8DMA_S   28U
#define WADI_DMATRIGEN_SSS_OUTEVT5_8DMA_M   0xF0000000U   // SSS output event 5 to 8 enables for
                                                          // DMA request Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMASTSUPDATE register
//
//*************************************************************************************************
#define WADI_DMASTSUPDATE_WRSTSBLK1   0x1U          // Status of DMA update for register set of
                                                    // WADI Block
#define WADI_DMASTSUPDATE_WRSTSBLK2   0x2U          // Status of DMA update for register set of
                                                    // WADI Block
#define WADI_DMASTSUPDATE_WRSTSBLK3   0x4U          // Status of DMA update for register set of
                                                    // WADI Block
#define WADI_DMASTSUPDATE_WRSTSBLK4   0x8U          // Status of DMA update for register set of
                                                    // WADI Block
#define WADI_DMASTSUPDATE_WRSTSEVT1   0x10000U      // DMA MMR write status of  SSS Event word
#define WADI_DMASTSUPDATE_WRSTSEVT2   0x20000U      // DMA MMR write status of  SSS Event word
#define WADI_DMASTSUPDATE_WRSTSEVT3   0x40000U      // DMA MMR write status of  SSS Event word
#define WADI_DMASTSUPDATE_WRSTSEVT4   0x80000U      // DMA MMR write status of  SSS Event word
#define WADI_DMASTSUPDATE_WRSTSEVT5   0x100000U     // DMA MMR write status of  SSS Event word
#define WADI_DMASTSUPDATE_WRSTSEVT6   0x200000U     // DMA MMR write status of  SSS Event word
#define WADI_DMASTSUPDATE_WRSTSEVT7   0x400000U     // DMA MMR write status of  SSS Event word
#define WADI_DMASTSUPDATE_WRSTSEVT8   0x800000U     // DMA MMR write status of  SSS Event word
#define WADI_DMASTSUPDATE_WRSTSOUT1   0x1000000U    // DMA MMR write status of  SSS OUTEVT1
#define WADI_DMASTSUPDATE_WRSTSOUT2   0x2000000U    // DMA MMR write status of  SSS OUTEVT2
#define WADI_DMASTSUPDATE_WRSTSOUT3   0x4000000U    // DMA MMR write status of  SSS OUTEVT3
#define WADI_DMASTSUPDATE_WRSTSOUT4   0x8000000U    // DMA MMR write status of  SSS OUTEVT4
#define WADI_DMASTSUPDATE_WRSTSOUT5   0x10000000U   // DMA MMR write status of  SSS OUTEVT5
#define WADI_DMASTSUPDATE_WRSTSOUT6   0x20000000U   // DMA MMR write status of  SSS OUTEVT6
#define WADI_DMASTSUPDATE_WRSTSOUT7   0x40000000U   // DMA MMR write status of  SSS OUTEVT7
#define WADI_DMASTSUPDATE_WRSTSOUT8   0x80000000U   // DMA MMR write status of  SSS OUTEVT8

//*************************************************************************************************
//
// The following are defines for the bit fields in the DMAFILTWRCFG register
//
//*************************************************************************************************
#define WADI_DMAFILTWRCFG_BLKSWREN_S        0U
#define WADI_DMAFILTWRCFG_BLKSWREN_M        0xFFFFU       // Enable for filtered DMA write for WADI
                                                          // Block
#define WADI_DMAFILTWRCFG_EVT1_4WREN_S      16U
#define WADI_DMAFILTWRCFG_EVT1_4WREN_M      0xF0000U      // Enable for filtered DMA write for SSS
                                                          // Event 1 to 4
#define WADI_DMAFILTWRCFG_EVT5_8WREN_S      20U
#define WADI_DMAFILTWRCFG_EVT5_8WREN_M      0xF00000U     // Enable for filtered DMA write for SSS
                                                          // Event 5 to 8
#define WADI_DMAFILTWRCFG_OUTEVT1_4WREN_S   24U
#define WADI_DMAFILTWRCFG_OUTEVT1_4WREN_M   0xF000000U    // Enable for filtered DMA write for SSS
                                                          // output Events 1-4
#define WADI_DMAFILTWRCFG_OUTEVT5_8WREN_S   28U
#define WADI_DMAFILTWRCFG_OUTEVT5_8WREN_M   0xF0000000U   // Enable for filtered DMA write for SSS
                                                          // output Events 5-8

//*************************************************************************************************
//
// The following are defines for the bit fields in the CFGREGLOCK register
//
//*************************************************************************************************
#define WADI_CFGREGLOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the CFGREGCOMMIT register
//
//*************************************************************************************************
#define WADI_CFGREGCOMMIT_COMMIT   0x1U   // CONFIG_REG_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the OPERREGLOCK register
//
//*************************************************************************************************
#define WADI_OPERREGLOCK_LOCK   0x1U   // Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the OPERREGCOMMIT register
//
//*************************************************************************************************
#define WADI_OPERREGCOMMIT_COMMIT   0x1U   // OPER_REG_LOCK Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVTTRIG register
//
//*************************************************************************************************
#define WADI_SSS_EVTTRIG_EVTTRIG_S   0U
#define WADI_SSS_EVTTRIG_EVTTRIG_M   0xFFU   // SSS start if event trigger matches one of defined
                                             // EVT1-8

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVTSTS register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVTSTS_OUTEVT1_4_S   0U
#define WADI_SSS_OUTEVTSTS_OUTEVT1_4_M   0xFU    // Active seq word status for first set
#define WADI_SSS_OUTEVTSTS_OUTEVT5_8_S   4U
#define WADI_SSS_OUTEVTSTS_OUTEVT5_8_M   0xF0U   // Active seq word status for Second set

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLK1_2OUTSEL register
//
//*************************************************************************************************
#define WADI_SSS_BLK1_2OUTSEL_BLK1SIG1_S   0U
#define WADI_SSS_BLK1_2OUTSEL_BLK1SIG1_M   0xFFU         // Maps the  OUTEVTn associated with
                                                         // BLK0:SIG1
#define WADI_SSS_BLK1_2OUTSEL_BLK1SIG2_S   8U
#define WADI_SSS_BLK1_2OUTSEL_BLK1SIG2_M   0xFF00U       // Maps the OUTEVTn associated with
                                                         // BLK0:SIG2
#define WADI_SSS_BLK1_2OUTSEL_BLK2SIG1_S   16U
#define WADI_SSS_BLK1_2OUTSEL_BLK2SIG1_M   0xFF0000U     // Maps the OUTEVTn associated with
                                                         // BLK1:SIG1
#define WADI_SSS_BLK1_2OUTSEL_BLK2SIG2_S   24U
#define WADI_SSS_BLK1_2OUTSEL_BLK2SIG2_M   0xFF000000U   // Maps the OUTEVTn associated with
                                                         // BLK1:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLK3_4OUTSEL register
//
//*************************************************************************************************
#define WADI_SSS_BLK3_4OUTSEL_BLK3SIG1_S   0U
#define WADI_SSS_BLK3_4OUTSEL_BLK3SIG1_M   0xFFU         // Maps the  OUTEVTn associated with
                                                         // BLK2:SIG1
#define WADI_SSS_BLK3_4OUTSEL_BLK3SIG2_S   8U
#define WADI_SSS_BLK3_4OUTSEL_BLK3SIG2_M   0xFF00U       // Maps the OUTEVTn associated with
                                                         // BLK2:SIG2
#define WADI_SSS_BLK3_4OUTSEL_BLK4SIG1_S   16U
#define WADI_SSS_BLK3_4OUTSEL_BLK4SIG1_M   0xFF0000U     // Maps the OUTEVTn associated with
                                                         // BLK3:SIG1
#define WADI_SSS_BLK3_4OUTSEL_BLK4SIG2_S   24U
#define WADI_SSS_BLK3_4OUTSEL_BLK4SIG2_M   0xFF000000U   // Maps the OUTEVTn associated with
                                                         // BLK3:SIG2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT1LINKCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT1LINKCFG_OUTEVT1LINK_S   0U
#define WADI_SSS_OUTEVT1LINKCFG_OUTEVT1LINK_M   0xFFU   // Links output events (OUTEVTs) as per one
                                                        // hot encoding

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT2LINKCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT2LINKCFG_OUTEVT2LINK_S   0U
#define WADI_SSS_OUTEVT2LINKCFG_OUTEVT2LINK_M   0xFFU   // Links output events (OUTEVTs) as per one
                                                        // hot encoding

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT3LINKCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT3LINKCFG_OUTEVT3LINK_S   0U
#define WADI_SSS_OUTEVT3LINKCFG_OUTEVT3LINK_M   0xFFU   // Links output events (OUTEVTs) as per one
                                                        // hot encoding

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT4LINKCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT4LINKCFG_OUTEVT4LINK_S   0U
#define WADI_SSS_OUTEVT4LINKCFG_OUTEVT4LINK_M   0xFFU   // Links output events (OUTEVTs) as per one
                                                        // hot encoding

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT5LINKCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT5LINKCFG_OUTEVT5LINK_S   0U
#define WADI_SSS_OUTEVT5LINKCFG_OUTEVT5LINK_M   0xFFU   // Links output events (OUTEVTs) as per one
                                                        // hot encoding

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT6LINKCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT6LINKCFG_OUTEVT6LINK_S   0U
#define WADI_SSS_OUTEVT6LINKCFG_OUTEVT6LINK_M   0xFFU   // Links output events (OUTEVTs) as per one
                                                        // hot encoding

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT7LINKCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT7LINKCFG_OUTEVT7LINK_S   0U
#define WADI_SSS_OUTEVT7LINKCFG_OUTEVT7LINK_M   0xFFU   // Links output events (OUTEVTs) as per one
                                                        // hot encoding

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT8LINKCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT8LINKCFG_OUT8LINK_S   0U
#define WADI_SSS_OUTEVT8LINKCFG_OUT8LINK_M   0xFFU   // Links output events (OUTEVTs) as per one
                                                     // hot encoding

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT1CFG register
//
//*************************************************************************************************
#define WADI_SSS_EVT1CFG_EVT1_S   0U
#define WADI_SSS_EVT1CFG_EVT1_M   0xFFU   // First event compare configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT2CFG register
//
//*************************************************************************************************
#define WADI_SSS_EVT2CFG_EVT2_S   0U
#define WADI_SSS_EVT2CFG_EVT2_M   0xFFU   // Second word compare value configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT3CFG register
//
//*************************************************************************************************
#define WADI_SSS_EVT3CFG_EVT3_S              0U
#define WADI_SSS_EVT3CFG_EVT3_M              0xFFU         // Third word compare value
                                                           // configuration
#define WADI_SSS_EVT3CFG_EVT3_BLK5_TO_16_S   8U
#define WADI_SSS_EVT3CFG_EVT3_BLK5_TO_16_M   0xFFFFFF00U   // Third word compare value
                                                           // configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT4CFG register
//
//*************************************************************************************************
#define WADI_SSS_EVT4CFG_EVT4_S              0U
#define WADI_SSS_EVT4CFG_EVT4_M              0xFFU         // Fourth word compare value
                                                           // configuration
#define WADI_SSS_EVT4CFG_EVT4_BLK5_TO_16_S   8U
#define WADI_SSS_EVT4CFG_EVT4_BLK5_TO_16_M   0xFFFFFF00U   // Fourth word compare value
                                                           // configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_TRIGEVT1_4CFG register
//
//*************************************************************************************************
#define WADI_SSS_TRIGEVT1_4CFG_TRIG_EVT1CFG_S   0U
#define WADI_SSS_TRIGEVT1_4CFG_TRIG_EVT1CFG_M   0xFU         // Selects action associated with
                                                             // event 1
#define WADI_SSS_TRIGEVT1_4CFG_TRIG_EVT2CFG_S   8U
#define WADI_SSS_TRIGEVT1_4CFG_TRIG_EVT2CFG_M   0xF00U       // Selects action associated with
                                                             // event 2
#define WADI_SSS_TRIGEVT1_4CFG_TRIG_EVT3CFG_S   16U
#define WADI_SSS_TRIGEVT1_4CFG_TRIG_EVT3CFG_M   0xF0000U     // Selects action associated with
                                                             // event 3
#define WADI_SSS_TRIGEVT1_4CFG_TRIG_EVT4CFG_S   24U
#define WADI_SSS_TRIGEVT1_4CFG_TRIG_EVT4CFG_M   0xF000000U   // Selects action associated with
                                                             // event 4

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLKSOUTEVT1CFG register
//
//*************************************************************************************************
#define WADI_SSS_BLKSOUTEVT1CFG_OUTEVT1_S   0U
#define WADI_SSS_BLKSOUTEVT1CFG_OUTEVT1_M   0xFFU   // Output configuration on event 1

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLKSOUTEVT2CFG register
//
//*************************************************************************************************
#define WADI_SSS_BLKSOUTEVT2CFG_OUTEVT2_S   0U
#define WADI_SSS_BLKSOUTEVT2CFG_OUTEVT2_M   0xFFU   // Output configuration on event 2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLKSOUTEVT3CFG register
//
//*************************************************************************************************
#define WADI_SSS_BLKSOUTEVT3CFG_OUTEVT3_S   0U
#define WADI_SSS_BLKSOUTEVT3CFG_OUTEVT3_M   0xFFU   // Output configuration on event 3

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLKSOUTEVT4CFG register
//
//*************************************************************************************************
#define WADI_SSS_BLKSOUTEVT4CFG_OUTEVT4_S   0U
#define WADI_SSS_BLKSOUTEVT4CFG_OUTEVT4_M   0xFFU   // Output configuration on event 4

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT1TRIGCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT1TRIGCFG_EVT1TRIG   0x1U    // Sets OUTEVT1 based on Event 1 Trigger
#define WADI_SSS_OUTEVT1TRIGCFG_EVT2TRIG   0x2U    // Sets OUTEVT1 based on Event 2 Trigger
#define WADI_SSS_OUTEVT1TRIGCFG_EVT3TRIG   0x4U    // Sets OUTEVT1 based on Event 3 Trigger
#define WADI_SSS_OUTEVT1TRIGCFG_EVT4TRIG   0x8U    // Sets OUTEVT1 based on Event 4 Trigger
#define WADI_SSS_OUTEVT1TRIGCFG_EVT5TRIG   0x10U   // Sets OUTEVT1 based on Event 5 Trigger
#define WADI_SSS_OUTEVT1TRIGCFG_EVT6TRIG   0x20U   // Sets OUTEVT1 based on Event 6 Trigger
#define WADI_SSS_OUTEVT1TRIGCFG_EVT7TRIG   0x40U   // Sets OUTEVT1 based on Event 7 Trigger
#define WADI_SSS_OUTEVT1TRIGCFG_EVT8TRIG   0x80U   // Sets OUTEVT1 based on Event 8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT2TRIGCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT2TRIGCFG_EVT1TRIG   0x1U    // Sets OUTEVT2 based on Event 1 Trigger
#define WADI_SSS_OUTEVT2TRIGCFG_EVT2TRIG   0x2U    // Sets OUTEVT2 based on Event 2 Trigger
#define WADI_SSS_OUTEVT2TRIGCFG_EVT3TRIG   0x4U    // Sets OUTEVT2 based on Event 3 Trigger
#define WADI_SSS_OUTEVT2TRIGCFG_EVT4TRIG   0x8U    // Sets OUTEVT2 based on Event 4 Trigger
#define WADI_SSS_OUTEVT2TRIGCFG_EVT5TRIG   0x10U   // Sets OUTEVT2 based on Event 5 Trigger
#define WADI_SSS_OUTEVT2TRIGCFG_EVT6TRIG   0x20U   // Sets OUTEVT2 based on Event 6 Trigger
#define WADI_SSS_OUTEVT2TRIGCFG_EVT7TRIG   0x40U   // Sets OUTEVT2 based on Event 7 Trigger
#define WADI_SSS_OUTEVT2TRIGCFG_EVT8TRIG   0x80U   // Sets OUTEVT2 based on Event 8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT3TRIGCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT3TRIGCFG_EVT1TRIG   0x1U    // Sets OUTEVT3 based on Event 1 Trigger
#define WADI_SSS_OUTEVT3TRIGCFG_EVT2TRIG   0x2U    // Sets OUTEVT3 based on Event 2 Trigger
#define WADI_SSS_OUTEVT3TRIGCFG_EVT3TRIG   0x4U    // Sets OUTEVT3 based on Event 3 Trigger
#define WADI_SSS_OUTEVT3TRIGCFG_EVT4TRIG   0x8U    // Sets OUTEVT3 based on Event 4 Trigger
#define WADI_SSS_OUTEVT3TRIGCFG_EVT5TRIG   0x10U   // Sets OUTEVT3 based on Event 5 Trigger
#define WADI_SSS_OUTEVT3TRIGCFG_EVT6TRIG   0x20U   // Sets OUTEVT3 based on Event 6 Trigger
#define WADI_SSS_OUTEVT3TRIGCFG_EVT7TRIG   0x40U   // Sets OUTEVT3 based on Event 7 Trigger
#define WADI_SSS_OUTEVT3TRIGCFG_EVT8TRIG   0x80U   // Sets OUTEVT3 based on Event 8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT4TRIGCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT4TRIGCFG_EVT1TRIG   0x1U    // Sets OUTEVT4 based on Event 1 Trigger
#define WADI_SSS_OUTEVT4TRIGCFG_EVT2TRIG   0x2U    // Sets OUTEVT4 based on Event 2 Trigger
#define WADI_SSS_OUTEVT4TRIGCFG_EVT3TRIG   0x4U    // Sets OUTEVT4 based on Event 3 Trigger
#define WADI_SSS_OUTEVT4TRIGCFG_EVT4TRIG   0x8U    // Sets OUTEVT4 based on Event 4 Trigger
#define WADI_SSS_OUTEVT4TRIGCFG_EVT5TRIG   0x10U   // Sets OUTEVT4 based on Event 5 Trigger
#define WADI_SSS_OUTEVT4TRIGCFG_EVT6TRIG   0x20U   // Sets OUTEVT4 based on Event 6 Trigger
#define WADI_SSS_OUTEVT4TRIGCFG_EVT7TRIG   0x40U   // Sets OUTEVT4 based on Event 7 Trigger
#define WADI_SSS_OUTEVT4TRIGCFG_EVT8TRIG   0x80U   // Sets OUTEVT4 based on Event 8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT1DUR register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT1DUR_TIME_S   0U
#define WADI_SSS_OUTEVT1DUR_TIME_M   0xFFFFFFU   // Duration time for application of OUTEVT1

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT2DUR register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT2DUR_TIME_S   0U
#define WADI_SSS_OUTEVT2DUR_TIME_M   0xFFFFFFU   // Duration time for application of OUTEVT2

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT3DUR register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT3DUR_TIME_S   0U
#define WADI_SSS_OUTEVT3DUR_TIME_M   0xFFFFFFU   // Duration time for application of OUTEVT3

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT4DUR register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT4DUR_TIME_S   0U
#define WADI_SSS_OUTEVT4DUR_TIME_M   0xFFFFFFU   // Duration time for application of OUTEVT4

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT5CFG register
//
//*************************************************************************************************
#define WADI_SSS_EVT5CFG_EVT5_S              0U
#define WADI_SSS_EVT5CFG_EVT5_M              0xFFU         // Fifth word compare value
                                                           // configuration
#define WADI_SSS_EVT5CFG_EVT5_BLK5_TO_16_S   8U
#define WADI_SSS_EVT5CFG_EVT5_BLK5_TO_16_M   0xFFFFFF00U   // Fifth word compare value
                                                           // configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT6CFG register
//
//*************************************************************************************************
#define WADI_SSS_EVT6CFG_EVT6_S              0U
#define WADI_SSS_EVT6CFG_EVT6_M              0xFFU         // Sixth word compare value
                                                           // configuration
#define WADI_SSS_EVT6CFG_EVT6_BLK5_TO_16_S   8U
#define WADI_SSS_EVT6CFG_EVT6_BLK5_TO_16_M   0xFFFFFF00U   // Sixth word compare value
                                                           // configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT7CFG register
//
//*************************************************************************************************
#define WADI_SSS_EVT7CFG_EVT7_S              0U
#define WADI_SSS_EVT7CFG_EVT7_M              0xFFU         // Seventh word compare value
                                                           // configuration
#define WADI_SSS_EVT7CFG_EVT7_BLK5_TO_16_S   8U
#define WADI_SSS_EVT7CFG_EVT7_BLK5_TO_16_M   0xFFFFFF00U   // Seventh word compare value
                                                           // configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_EVT8CFG register
//
//*************************************************************************************************
#define WADI_SSS_EVT8CFG_EVT8_S              0U
#define WADI_SSS_EVT8CFG_EVT8_M              0xFFU         // Eighth word compare value
                                                           // configuration
#define WADI_SSS_EVT8CFG_EVT8_BLK5_TO_16_S   8U
#define WADI_SSS_EVT8CFG_EVT8_BLK5_TO_16_M   0xFFFFFF00U   // Eighth word compare value
                                                           // configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_TRIGEVT5_8CFG register
//
//*************************************************************************************************
#define WADI_SSS_TRIGEVT5_8CFG_TRIG_EVT5CFG_S   0U
#define WADI_SSS_TRIGEVT5_8CFG_TRIG_EVT5CFG_M   0xFU         // Selects action associated with
                                                             // event 5
#define WADI_SSS_TRIGEVT5_8CFG_TRIG_EVT6CFG_S   8U
#define WADI_SSS_TRIGEVT5_8CFG_TRIG_EVT6CFG_M   0xF00U       // Selects action associated with
                                                             // event 6
#define WADI_SSS_TRIGEVT5_8CFG_TRIG_EVT7CFG_S   16U
#define WADI_SSS_TRIGEVT5_8CFG_TRIG_EVT7CFG_M   0xF0000U     // Selects action associated with
                                                             // event 7
#define WADI_SSS_TRIGEVT5_8CFG_TRIG_EVT8CFG_S   24U
#define WADI_SSS_TRIGEVT5_8CFG_TRIG_EVT8CFG_M   0xF000000U   // Selects action associated with
                                                             // event 8

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLKSOUTEVT5CFG register
//
//*************************************************************************************************
#define WADI_SSS_BLKSOUTEVT5CFG_OUTEVT5_S   0U
#define WADI_SSS_BLKSOUTEVT5CFG_OUTEVT5_M   0xFFU   // Output configuration on event 5

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLKSOUTEVT6CFG register
//
//*************************************************************************************************
#define WADI_SSS_BLKSOUTEVT6CFG_OUTEVT6_S   0U
#define WADI_SSS_BLKSOUTEVT6CFG_OUTEVT6_M   0xFFU   // Output configuration on event 6

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLKSOUTEVT7CFG register
//
//*************************************************************************************************
#define WADI_SSS_BLKSOUTEVT7CFG_OUTEVT7_S   0U
#define WADI_SSS_BLKSOUTEVT7CFG_OUTEVT7_M   0xFFU   // Output configuration on event 7

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_BLKSOUTEVT8CFG register
//
//*************************************************************************************************
#define WADI_SSS_BLKSOUTEVT8CFG_OUTEVT8_S   0U
#define WADI_SSS_BLKSOUTEVT8CFG_OUTEVT8_M   0xFFU   // Output configuration on event 8

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT5TRIGCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT5TRIGCFG_EVT1TRIG   0x1U    // Sets OUTEVT5 based on Event 1 Trigger
#define WADI_SSS_OUTEVT5TRIGCFG_EVT2TRIG   0x2U    // Sets OUTEVT5 based on Event 2 Trigger
#define WADI_SSS_OUTEVT5TRIGCFG_EVT3TRIG   0x4U    // Sets OUTEVT5 based on Event 3 Trigger
#define WADI_SSS_OUTEVT5TRIGCFG_EVT4TRIG   0x8U    // Sets OUTEVT5 based on Event 4 Trigger
#define WADI_SSS_OUTEVT5TRIGCFG_EVT5TRIG   0x10U   // Sets OUTEVT5 based on Event 5 Trigger
#define WADI_SSS_OUTEVT5TRIGCFG_EVT6TRIG   0x20U   // Sets OUTEVT5 based on Event 6 Trigger
#define WADI_SSS_OUTEVT5TRIGCFG_EVT7TRIG   0x40U   // Sets OUTEVT5 based on Event 7 Trigger
#define WADI_SSS_OUTEVT5TRIGCFG_EVT8TRIG   0x80U   // Sets OUTEVT5 based on Event 8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT6TRIGCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT6TRIGCFG_EVT1TRIG   0x1U    // Sets OUTEVT6 based on Event 1 Trigger
#define WADI_SSS_OUTEVT6TRIGCFG_EVT2TRIG   0x2U    // Sets OUTEVT6 based on Event 2 Trigger
#define WADI_SSS_OUTEVT6TRIGCFG_EVT3TRIG   0x4U    // Sets OUTEVT6 based on Event 3 Trigger
#define WADI_SSS_OUTEVT6TRIGCFG_EVT4TRIG   0x8U    // Sets OUTEVT6 based on Event 4 Trigger
#define WADI_SSS_OUTEVT6TRIGCFG_EVT5TRIG   0x10U   // Sets OUTEVT6 based on Event 5 Trigger
#define WADI_SSS_OUTEVT6TRIGCFG_EVT6TRIG   0x20U   // Sets OUTEVT6 based on Event 6 Trigger
#define WADI_SSS_OUTEVT6TRIGCFG_EVT7TRIG   0x40U   // Sets OUTEVT6 based on Event 7 Trigger
#define WADI_SSS_OUTEVT6TRIGCFG_EVT8TRIG   0x80U   // Sets OUTEVT6 based on Event 8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT7TRIGCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT7TRIGCFG_EVT1TRIG   0x1U    // Sets OUTEVT7 based on Event 1 Trigger
#define WADI_SSS_OUTEVT7TRIGCFG_EVT2TRIG   0x2U    // Sets OUTEVT7 based on Event 2 Trigger
#define WADI_SSS_OUTEVT7TRIGCFG_EVT3TRIG   0x4U    // Sets OUTEVT7 based on Event 3 Trigger
#define WADI_SSS_OUTEVT7TRIGCFG_EVT4TRIG   0x8U    // Sets OUTEVT7 based on Event 4 Trigger
#define WADI_SSS_OUTEVT7TRIGCFG_EVT5TRIG   0x10U   // Sets OUTEVT7 based on Event 5 Trigger
#define WADI_SSS_OUTEVT7TRIGCFG_EVT6TRIG   0x20U   // Sets OUTEVT7 based on Event 6 Trigger
#define WADI_SSS_OUTEVT7TRIGCFG_EVT7TRIG   0x40U   // Sets OUTEVT7 based on Event 7 Trigger
#define WADI_SSS_OUTEVT7TRIGCFG_EVT8TRIG   0x80U   // Sets OUTEVT7 based on Event 8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT8TRIGCFG register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT8TRIGCFG_EVT1TRIG   0x1U    // Sets OUTEVT8 based on Event 1 Trigger
#define WADI_SSS_OUTEVT8TRIGCFG_EVT2TRIG   0x2U    // Sets OUTEVT8 based on Event 2 Trigger
#define WADI_SSS_OUTEVT8TRIGCFG_EVT3TRIG   0x4U    // Sets OUTEVT8 based on Event 3 Trigger
#define WADI_SSS_OUTEVT8TRIGCFG_EVT4TRIG   0x8U    // Sets OUTEVT8 based on Event 4 Trigger
#define WADI_SSS_OUTEVT8TRIGCFG_EVT5TRIG   0x10U   // Sets OUTEVT8 based on Event 5 Trigger
#define WADI_SSS_OUTEVT8TRIGCFG_EVT6TRIG   0x20U   // Sets OUTEVT8 based on Event 6 Trigger
#define WADI_SSS_OUTEVT8TRIGCFG_EVT7TRIG   0x40U   // Sets OUTEVT8 based on Event 7 Trigger
#define WADI_SSS_OUTEVT8TRIGCFG_EVT8TRIG   0x80U   // Sets OUTEVT8 based on Event 8 Trigger

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT5DUR register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT5DUR_TIME_S   0U
#define WADI_SSS_OUTEVT5DUR_TIME_M   0xFFFFFFU   // Duration time for application of OUTEVT5

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT6DUR register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT6DUR_TIME_S   0U
#define WADI_SSS_OUTEVT6DUR_TIME_M   0xFFFFFFU   // Duration time for application of OUTEVT6

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT7DUR register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT7DUR_TIME_S   0U
#define WADI_SSS_OUTEVT7DUR_TIME_M   0xFFFFFFU   // Duration time for application of OUTEVT7

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSS_OUTEVT8DUR register
//
//*************************************************************************************************
#define WADI_SSS_OUTEVT8DUR_TIME_S   0U
#define WADI_SSS_OUTEVT8DUR_TIME_M   0xFFFFFFU   // Duration time for application of OUTEVT8

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARTEST register
//
//*************************************************************************************************
#define WADI_SSS_PARTEST_TESTEN_S   0U
#define WADI_SSS_PARTEST_TESTEN_M   0xFU   // Parity test enable configuration



#endif
