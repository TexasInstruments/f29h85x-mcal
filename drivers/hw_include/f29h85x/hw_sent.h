//###########################################################################
//
// FILE:    hw_sent.h
//
// TITLE:   Definitions for the SENT registers.
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

#ifndef HW_SENT_H
#define HW_SENT_H

//*************************************************************************************************
//
// The following are defines for the SENT register offsets
//
//*************************************************************************************************
#define SENT_O_RCFG              0x20U   //
#define SENT_O_RFDATA            0x24U   //
#define SENT_O_RSDATA            0x28U   //
#define SENT_O_RSTAT             0x2CU   //
#define SENT_O_RCFG2             0x34U   //
#define SENT_O_RINTFLAG          0x40U   //
#define SENT_O_REINT             0x44U   //
#define SENT_O_RSETINT           0x48U   //
#define SENT_O_RCLRINT           0x4CU   //
#define SENT_O_CSENT_SWR         0x50U   //
#define SENT_O_DATA0_MAP         0x54U   //
#define SENT_O_DATA1_MAP         0x58U   //
#define SENT_O_CSENT_TO          0x5CU   //
#define SENT_O_CSENT_RXD         0x60U   //
#define SENT_O_RXVAL_CNT         0x64U   //
#define SENT_O_RXDEDGE_CNT       0x68U   //
#define SENT_O_SWR_RXVAL_CNT     0x6CU   //
#define SENT_O_SWR_RXDEDGE_CNT   0x70U   //
#define SENT_O_CSENT_VERSION     0x7CU   //

#define SENT_O_MDATA(i)   (0x400U + ((i) * 0x4U))   // (0 <= i < 16) Data word 'N' in TPRAM memory.
                                                    // The SENT TPRAM contains fast channel SENT
                                                    // frames whether in FIFO or Direct Map mode.
                                                    // In Direct Map mode, the user must read the
                                                    // SENT frame data out from this memory (refer
                                                    // to the section regarding Receive Modes for
                                                    // more details)

#define SENT_O_BC_MTP_EN        0x800U   //
#define SENT_O_BC_MTP_CMP1      0x804U   //
#define SENT_O_BC_MTP_CMP2      0x808U   //
#define SENT_O_BC_MTP_CMP3      0x80CU   //
#define SENT_O_BC_MTP_CMP4      0x810U   //
#define SENT_O_BC_MTP_CMP5      0x814U   //
#define SENT_O_BC_MTP_CMP6      0x818U   //
#define SENT_O_BC_MTP_CMP7      0x81CU   //
#define SENT_O_BC_MTP_CMP8      0x820U   //
#define SENT_O_BC_MTP_CMP9      0x824U   //
#define SENT_O_BC_MTP_PERIOD    0x82CU   //
#define SENT_O_BC_TRIGSEL       0x834U   //
#define SENT_O_BC_MTP_SWTR      0x838U   //
#define SENT_O_S1_MTP_EN        0x900U   //
#define SENT_O_S1_MTP_CMP1      0x904U   //
#define SENT_O_S1_MTP_CMP2      0x908U   //
#define SENT_O_S1_MTP_CMP3      0x90CU   //
#define SENT_O_S1_MTP_CMP4      0x910U   //
#define SENT_O_S1_MTP_CMP5      0x914U   //
#define SENT_O_S1_MTP_CMP6      0x918U   //
#define SENT_O_S1_MTP_CMP7      0x91CU   //
#define SENT_O_S1_MTP_CMP8      0x920U   //
#define SENT_O_S1_MTP_CMP9      0x924U   //
#define SENT_O_S1_MTP_CMP10RE   0x928U   //
#define SENT_O_S1_MTP_PERIOD    0x92CU   //
#define SENT_O_S1_MTP_TO        0x930U   //
#define SENT_O_S1_TRIGSEL       0x934U   //
#define SENT_O_S1_MTP_SWTR      0x938U   //
#define SENT_O_S2_MTP_EN        0xA00U   //
#define SENT_O_S2_MTP_CMP1      0xA04U   //
#define SENT_O_S2_MTP_CMP2      0xA08U   //
#define SENT_O_S2_MTP_CMP3      0xA0CU   //
#define SENT_O_S2_MTP_CMP4      0xA10U   //
#define SENT_O_S2_MTP_CMP5      0xA14U   //
#define SENT_O_S2_MTP_CMP6      0xA18U   //
#define SENT_O_S2_MTP_CMP7      0xA1CU   //
#define SENT_O_S2_MTP_CMP8      0xA20U   //
#define SENT_O_S2_MTP_CMP9      0xA24U   //
#define SENT_O_S2_MTP_CMP10RE   0xA28U   //
#define SENT_O_S2_MTP_PERIOD    0xA2CU   //
#define SENT_O_S2_MTP_TO        0xA30U   //
#define SENT_O_S2_TRIGSEL       0xA34U   //
#define SENT_O_S2_MTP_SWTR      0xA38U   //
#define SENT_O_S3_MTP_EN        0xB00U   //
#define SENT_O_S3_MTP_CMP1      0xB04U   //
#define SENT_O_S3_MTP_CMP2      0xB08U   //
#define SENT_O_S3_MTP_CMP3      0xB0CU   //
#define SENT_O_S3_MTP_CMP4      0xB10U   //
#define SENT_O_S3_MTP_CMP5      0xB14U   //
#define SENT_O_S3_MTP_CMP6      0xB18U   //
#define SENT_O_S3_MTP_CMP7      0xB1CU   //
#define SENT_O_S3_MTP_CMP8      0xB20U   //
#define SENT_O_S3_MTP_CMP9      0xB24U   //
#define SENT_O_S3_MTP_CMP10RE   0xB28U   //
#define SENT_O_S3_MTP_PERIOD    0xB2CU   //
#define SENT_O_S3_MTP_TO        0xB30U   //
#define SENT_O_S3_TRIGSEL       0xB34U   //
#define SENT_O_S3_MTP_SWTR      0xB38U   //
#define SENT_O_S4_MTP_EN        0xC00U   //
#define SENT_O_S4_MTP_CMP1      0xC04U   //
#define SENT_O_S4_MTP_CMP2      0xC08U   //
#define SENT_O_S4_MTP_CMP3      0xC0CU   //
#define SENT_O_S4_MTP_CMP4      0xC10U   //
#define SENT_O_S4_MTP_CMP5      0xC14U   //
#define SENT_O_S4_MTP_CMP6      0xC18U   //
#define SENT_O_S4_MTP_CMP7      0xC1CU   //
#define SENT_O_S4_MTP_CMP8      0xC20U   //
#define SENT_O_S4_MTP_CMP9      0xC24U   //
#define SENT_O_S4_MTP_CMP10RE   0xC28U   //
#define SENT_O_S4_MTP_PERIOD    0xC2CU   //
#define SENT_O_S4_MTP_TO        0xC30U   //
#define SENT_O_S4_TRIGSEL       0xC34U   //
#define SENT_O_S4_MTP_SWTR      0xC38U   //
#define SENT_O_WAITTIME         0xF00U   //
#define SENT_O_TPGENSTAT        0xF04U   //
#define SENT_O_MTP_VERSION      0xF30U   //
#define SENT_O_MTP_SWR          0xF3CU   //


//*************************************************************************************************
//
// The following are defines for the bit fields in the RCFG register
//
//*************************************************************************************************
#define SENT_RCFG_RX_ENB               0x1U          //
#define SENT_RCFG_RX_CRCENB            0x2U          //
#define SENT_RCFG_RSVD_0               0x4U          //
#define SENT_RCFG_RX_PPENB             0x8U          //
#define SENT_RCFG_RX_DNIB_S            4U
#define SENT_RCFG_RX_DNIB_M            0xF0U         //
#define SENT_RCFG_CRC_WIDTH_S          8U
#define SENT_RCFG_CRC_WIDTH_M          0x300U        //
#define SENT_RCFG_RX_CRC_WITH_STATUS   0x400U        //
#define SENT_RCFG_RX_CRCTYPE           0x800U        //
#define SENT_RCFG_RSVD_S               12U
#define SENT_RCFG_RSVD_M               0xF000U       //
#define SENT_RCFG_TTCLK_S              16U
#define SENT_RCFG_TTCLK_M              0xFFFF0000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the RSDATA register
//
//*************************************************************************************************
#define SENT_RSDATA_CRC_S         0U
#define SENT_RSDATA_CRC_M         0x3FU         //
#define SENT_RSDATA_RSVD          0x40U         //
#define SENT_RSDATA_C             0x80U         //
#define SENT_RSDATA_DATA_S        8U
#define SENT_RSDATA_DATA_M        0xFFFF00U     //
#define SENT_RSDATA_MESSAGEID_S   24U
#define SENT_RSDATA_MESSAGEID_M   0xFF000000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the RSTAT register
//
//*************************************************************************************************
#define SENT_RSTAT_RXNIB_S       0U
#define SENT_RSTAT_RXNIB_M       0xFU          //
#define SENT_RSTAT_PP            0x10U         //
#define SENT_RSTAT_RSVD_S        5U
#define SENT_RSTAT_RSVD_M        0xE0U         //
#define SENT_RSTAT_RXSLOW_ST_S   8U
#define SENT_RSTAT_RXSLOW_ST_M   0x1F00U       //
#define SENT_RSTAT_RXSLOW_ACT    0x2000U       //
#define SENT_RSTAT_RXSLOW_DN     0x4000U       //
#define SENT_RSTAT_RX_SYNC       0x8000U       //
#define SENT_RSTAT_RX_TTCLK_S    16U
#define SENT_RSTAT_RX_TTCLK_M    0xFFFF0000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the RCFG2 register
//
//*************************************************************************************************
#define SENT_RCFG2_FIFO_MODE         0x1U          //
#define SENT_RCFG2_DMA_ENB           0x2U          //
#define SENT_RCFG2_TSTAMP_DIS        0x4U          //
#define SENT_RCFG2_NOWR_ERRDATA      0x8U          //
#define SENT_RCFG2_GFILT_S           4U
#define SENT_RCFG2_GFILT_M           0xFF0U        //
#define SENT_RCFG2_RFIFO_TRIGLEV_S   16U
#define SENT_RCFG2_RFIFO_TRIGLEV_M   0xF0000U      //
#define SENT_RCFG2_RSVD_S            13U
#define SENT_RCFG2_RSVD_M            0xE000U       //
#define SENT_RCFG2_MTP_MODE          0x1000U       //
#define SENT_RCFG2_RSVD_0_S          20U
#define SENT_RCFG2_RSVD_0_M          0xFFF00000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the RINTFLAG register
//
//*************************************************************************************************
#define SENT_RINTFLAG_GLBL              0x1U          //
#define SENT_RINTFLAG_RFAST_S1DV        0x2U          //
#define SENT_RINTFLAG_RFAST_S2DV        0x4U          //
#define SENT_RINTFLAG_RFAST_S3DV        0x8U          //
#define SENT_RINTFLAG_RFAST_S4DV        0x10U         //
#define SENT_RINTFLAG_RSLOW_DV          0x20U         //
#define SENT_RINTFLAG_RSLOW_CRCERR      0x40U         //
#define SENT_RINTFLAG_RSLOW_FORMATERR   0x80U         //
#define SENT_RINTFLAG_RFAST_S1CRCE      0x100U        //
#define SENT_RINTFLAG_RFAST_S2CRCE      0x200U        //
#define SENT_RINTFLAG_RFAST_S3CRCE      0x400U        //
#define SENT_RINTFLAG_RFAST_S4CRCE      0x800U        //
#define SENT_RINTFLAG_RFAST_S1FRME      0x1000U       //
#define SENT_RINTFLAG_RFAST_S2FRME      0x2000U       //
#define SENT_RINTFLAG_RFAST_S3FRME      0x4000U       //
#define SENT_RINTFLAG_RFAST_S4FRME      0x8000U       //
#define SENT_RINTFLAG_RTIMEOUT_ERR_S    16U
#define SENT_RINTFLAG_RTIMEOUT_ERR_M    0xF0000U      //
#define SENT_RINTFLAG_RFAST_SYNCERR25   0x100000U     //
#define SENT_RINTFLAG_RFAST_SYNCERR     0x200000U     //
#define SENT_RINTFLAG_FREQDRIFT_ERR     0x400000U     //
#define SENT_RINTFLAG_RFIFO_TRIGGER     0x800000U     //
#define SENT_RINTFLAG_RFIFO_OVFERR      0x1000000U    //
#define SENT_RINTFLAG_RFIFO_UNDFERR     0x2000000U    //
#define SENT_RINTFLAG_OVFTRIG_ERR_S     26U
#define SENT_RINTFLAG_OVFTRIG_ERR_M     0x7C000000U   //
#define SENT_RINTFLAG_RSVD              0x80000000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the REINT register
//
//*************************************************************************************************
#define SENT_REINT_RSVD                0x1U          //
#define SENT_REINT_RSVD_1              0x80000000U   //
#define SENT_REINT_RFAST_S2DV_E        0x4U          //
#define SENT_REINT_RFAST_S3DV_E        0x8U          //
#define SENT_REINT_RFAST_S4DV_E        0x10U         //
#define SENT_REINT_RSLOW_DV_E          0x20U         //
#define SENT_REINT_RSLOW_CRCERR_E      0x40U         //
#define SENT_REINT_RSLOW_FORMATERR_E   0x80U         //
#define SENT_REINT_RFAST_S1CRCE_E      0x100U        //
#define SENT_REINT_RFAST_S2CRCE_E      0x200U        //
#define SENT_REINT_RFAST_S3CRCE_E      0x400U        //
#define SENT_REINT_RFAST_S4CRCE_E      0x800U        //
#define SENT_REINT_RFAST_S1FRME_E      0x1000U       //
#define SENT_REINT_RFAST_S2FRME_E      0x2000U       //
#define SENT_REINT_RFAST_S3FRME_E      0x4000U       //
#define SENT_REINT_RFAST_S4FRME_E      0x8000U       //
#define SENT_REINT_RTIMEOUT_ERR_E_S    16U
#define SENT_REINT_RTIMEOUT_ERR_E_M    0xF0000U      //
#define SENT_REINT_RFAST_SYNCERR25_E   0x100000U     //
#define SENT_REINT_RFAST_SYNCERR_E     0x200000U     //
#define SENT_REINT_FREQDRIFT_ERR_E     0x400000U     //
#define SENT_REINT_RFIFO_TRIGGER_E     0x800000U     //
#define SENT_REINT_RFIFO_OVFERR_E      0x1000000U    //
#define SENT_REINT_RFIFO_UNDFERR_E     0x2000000U    //
#define SENT_REINT_OVFTRIG_ERR_E_S     26U
#define SENT_REINT_OVFTRIG_ERR_E_M     0x7C000000U   //
#define SENT_REINT_RFAST_S1DV_E        0x2U          //

//*************************************************************************************************
//
// The following are defines for the bit fields in the RSETINT register
//
//*************************************************************************************************
#define SENT_RSETINT_RSVD_0              0x80000000U   //
#define SENT_RSETINT_RFAST_S1DV_S        0x2U          //
#define SENT_RSETINT_RFAST_S2DV_S        0x4U          //
#define SENT_RSETINT_RFAST_S3DV_S        0x8U          //
#define SENT_RSETINT_RFAST_S4DV_S        0x10U         //
#define SENT_RSETINT_RSLOW_DV_S          0x20U         //
#define SENT_RSETINT_RSLOW_CRCERR_S      0x40U         //
#define SENT_RSETINT_RSLOW_FORMATERR_S   0x80U         //
#define SENT_RSETINT_RFAST_S1CRCE_S      0x100U        //
#define SENT_RSETINT_RFAST_S2CRCE_S      0x200U        //
#define SENT_RSETINT_RFAST_S3CRCE_S      0x400U        //
#define SENT_RSETINT_RFAST_S4CRCE_S      0x800U        //
#define SENT_RSETINT_RFAST_S1FRME_S      0x1000U       //
#define SENT_RSETINT_RFAST_S2FRME_S      0x2000U       //
#define SENT_RSETINT_RFAST_S3FRME_S      0x4000U       //
#define SENT_RSETINT_RFAST_S4FRME_S      0x8000U       //
#define SENT_RSETINT_RTIMEOUT_ERR_S_S    16U
#define SENT_RSETINT_RTIMEOUT_ERR_S_M    0xF0000U      //
#define SENT_RSETINT_RFAST_SYNCERR25_S   0x100000U     //
#define SENT_RSETINT_RFAST_SYNCERR_S     0x200000U     //
#define SENT_RSETINT_FREQDRIFT_ERR_S     0x400000U     //
#define SENT_RSETINT_RFIFO_TRIGGER_S     0x800000U     //
#define SENT_RSETINT_RFIFO_OVFERR_S      0x1000000U    //
#define SENT_RSETINT_RFIFO_UNDFERR_S     0x2000000U    //
#define SENT_RSETINT_OVFTRIG_ERR_S_S     26U
#define SENT_RSETINT_OVFTRIG_ERR_S_M     0x7C000000U   //
#define SENT_RSETINT_RSVD                0x1U          //

//*************************************************************************************************
//
// The following are defines for the bit fields in the RCLRINT register
//
//*************************************************************************************************
#define SENT_RCLRINT_GLBL_CLR              0x1U          //
#define SENT_RCLRINT_RFAST_S1DV_CLR        0x2U          //
#define SENT_RCLRINT_RFAST_S2DV_CLR        0x4U          //
#define SENT_RCLRINT_RFAST_S3DV_CLR        0x8U          //
#define SENT_RCLRINT_RFAST_S4DV_CLR        0x10U         //
#define SENT_RCLRINT_RSLOW_DV_CLR          0x20U         //
#define SENT_RCLRINT_RSLOW_CRCERR_CLR      0x40U         //
#define SENT_RCLRINT_RSLOW_FORMATERR_CLR   0x80U         //
#define SENT_RCLRINT_RFAST_S1CRCE_CLR      0x100U        //
#define SENT_RCLRINT_RFAST_S2CRCE_CLR      0x200U        //
#define SENT_RCLRINT_RFAST_S3CRCE_CLR      0x400U        //
#define SENT_RCLRINT_RFAST_S4CRCE_CLR      0x800U        //
#define SENT_RCLRINT_RFAST_S1FRME_CLR      0x1000U       //
#define SENT_RCLRINT_RFAST_S2FRME_CLR      0x2000U       //
#define SENT_RCLRINT_RFAST_S3FRME_CLR      0x4000U       //
#define SENT_RCLRINT_RFAST_S4FRME_CLR      0x8000U       //
#define SENT_RCLRINT_RTIMEOUT_ERR_CLR_S    16U
#define SENT_RCLRINT_RTIMEOUT_ERR_CLR_M    0xF0000U      //
#define SENT_RCLRINT_RFAST_SYNCERR25_CLR   0x100000U     //
#define SENT_RCLRINT_RFAST_SYNCERR_CLR     0x200000U     //
#define SENT_RCLRINT_FREQDRIFT_ERR_CLR     0x400000U     //
#define SENT_RCLRINT_RFIFO_TRIGGER_CLR     0x800000U     //
#define SENT_RCLRINT_RFIFO_OVFERR_CLR      0x1000000U    //
#define SENT_RCLRINT_RFIFO_UNDFERR_CLR     0x2000000U    //
#define SENT_RCLRINT_OVFTRIG_ERR_CLR_S     26U
#define SENT_RCLRINT_OVFTRIG_ERR_CLR_M     0x7C000000U   //
#define SENT_RCLRINT_RSVD                  0x80000000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the CSENT_SWR register
//
//*************************************************************************************************
#define SENT_CSENT_SWR_SWR      0x1U          //
#define SENT_CSENT_SWR_RSVD_S   1U
#define SENT_CSENT_SWR_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the DATA0_MAP register
//
//*************************************************************************************************
#define SENT_DATA0_MAP_D0_NIB0_S   0U
#define SENT_DATA0_MAP_D0_NIB0_M   0xFU          //
#define SENT_DATA0_MAP_D0_NIB1_S   4U
#define SENT_DATA0_MAP_D0_NIB1_M   0xF0U         //
#define SENT_DATA0_MAP_D0_NIB2_S   8U
#define SENT_DATA0_MAP_D0_NIB2_M   0xF00U        //
#define SENT_DATA0_MAP_D0_NIB3_S   12U
#define SENT_DATA0_MAP_D0_NIB3_M   0xF000U       //
#define SENT_DATA0_MAP_D0_NIB4_S   16U
#define SENT_DATA0_MAP_D0_NIB4_M   0xF0000U      //
#define SENT_DATA0_MAP_D0_NIB5_S   20U
#define SENT_DATA0_MAP_D0_NIB5_M   0xF00000U     //
#define SENT_DATA0_MAP_D0_NIB6_S   24U
#define SENT_DATA0_MAP_D0_NIB6_M   0xF000000U    //
#define SENT_DATA0_MAP_D0_NIB7_S   28U
#define SENT_DATA0_MAP_D0_NIB7_M   0xF0000000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the DATA1_MAP register
//
//*************************************************************************************************
#define SENT_DATA1_MAP_D1_NIB0_S   0U
#define SENT_DATA1_MAP_D1_NIB0_M   0xFU          //
#define SENT_DATA1_MAP_D1_NIB1_S   4U
#define SENT_DATA1_MAP_D1_NIB1_M   0xF0U         //
#define SENT_DATA1_MAP_D1_NIB2_S   8U
#define SENT_DATA1_MAP_D1_NIB2_M   0xF00U        //
#define SENT_DATA1_MAP_D1_NIB3_S   12U
#define SENT_DATA1_MAP_D1_NIB3_M   0xF000U       //
#define SENT_DATA1_MAP_D1_NIB4_S   16U
#define SENT_DATA1_MAP_D1_NIB4_M   0xF0000U      //
#define SENT_DATA1_MAP_D1_NIB5_S   20U
#define SENT_DATA1_MAP_D1_NIB5_M   0xF00000U     //
#define SENT_DATA1_MAP_D1_NIB6_S   24U
#define SENT_DATA1_MAP_D1_NIB6_M   0xF000000U    //
#define SENT_DATA1_MAP_D1_NIB7_S   28U
#define SENT_DATA1_MAP_D1_NIB7_M   0xF0000000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the CSENT_RXD register
//
//*************************************************************************************************
#define SENT_CSENT_RXD_RXD_I_R   0x1U          //
#define SENT_CSENT_RXD_RSVD_S    1U
#define SENT_CSENT_RXD_RSVD_M    0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the RXVAL_CNT register
//
//*************************************************************************************************
#define SENT_RXVAL_CNT_RXVALID_CNT_R_S   0U
#define SENT_RXVAL_CNT_RXVALID_CNT_R_M   0xFFU         //
#define SENT_RXVAL_CNT_RSVD_S            8U
#define SENT_RXVAL_CNT_RSVD_M            0xFFFFFF00U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the RXDEDGE_CNT register
//
//*************************************************************************************************
#define SENT_RXDEDGE_CNT_RXDEDGE_CNT_R_S   0U
#define SENT_RXDEDGE_CNT_RXDEDGE_CNT_R_M   0xFFU         //
#define SENT_RXDEDGE_CNT_RSVD_S            8U
#define SENT_RXDEDGE_CNT_RSVD_M            0xFFFFFF00U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the SWR_RXVAL_CNT register
//
//*************************************************************************************************
#define SENT_SWR_RXVAL_CNT_SWR_RXVAL_CNT   0x1U          //
#define SENT_SWR_RXVAL_CNT_RSVD_S          1U
#define SENT_SWR_RXVAL_CNT_RSVD_M          0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the SWR_RXDEDGE_CNT register
//
//*************************************************************************************************
#define SENT_SWR_RXDEDGE_CNT_SWR_RXDEDGE_CNT   0x1U          //
#define SENT_SWR_RXDEDGE_CNT_RSVD_S            1U
#define SENT_SWR_RXDEDGE_CNT_RSVD_M            0xFFFFFFFEU   //



//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_EN register
//
//*************************************************************************************************
#define SENT_BC_MTP_EN_MTP_EN   0x1U          //
#define SENT_BC_MTP_EN_RSVD_S   1U
#define SENT_BC_MTP_EN_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP1 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP1_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP1_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP1_RSVD_S         11U
#define SENT_BC_MTP_CMP1_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP2 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP2_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP2_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP2_RSVD_S         11U
#define SENT_BC_MTP_CMP2_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP3 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP3_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP3_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP3_RSVD_S         11U
#define SENT_BC_MTP_CMP3_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP4 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP4_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP4_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP4_RSVD_S         11U
#define SENT_BC_MTP_CMP4_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP5 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP5_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP5_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP5_RSVD_S         11U
#define SENT_BC_MTP_CMP5_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP6 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP6_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP6_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP6_RSVD_S         11U
#define SENT_BC_MTP_CMP6_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP7 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP7_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP7_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP7_RSVD_S         11U
#define SENT_BC_MTP_CMP7_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP8 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP8_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP8_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP8_RSVD_S         11U
#define SENT_BC_MTP_CMP8_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_CMP9 register
//
//*************************************************************************************************
#define SENT_BC_MTP_CMP9_TOGGLETIME_S   0U
#define SENT_BC_MTP_CMP9_TOGGLETIME_M   0x7FFU        //
#define SENT_BC_MTP_CMP9_RSVD_S         11U
#define SENT_BC_MTP_CMP9_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_PERIOD register
//
//*************************************************************************************************
#define SENT_BC_MTP_PERIOD_PERIOD_S   0U
#define SENT_BC_MTP_PERIOD_PERIOD_M   0x7FFU        //
#define SENT_BC_MTP_PERIOD_RSVD_S     11U
#define SENT_BC_MTP_PERIOD_RSVD_M     0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_TRIGSEL register
//
//*************************************************************************************************
#define SENT_BC_TRIGSEL_TRIGSEL_S   0U
#define SENT_BC_TRIGSEL_TRIGSEL_M   0x7FU         //
#define SENT_BC_TRIGSEL_RSVD_S      7U
#define SENT_BC_TRIGSEL_RSVD_M      0xFFFFFF80U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the BC_MTP_SWTR register
//
//*************************************************************************************************
#define SENT_BC_MTP_SWTR_SWTR     0x1U          //
#define SENT_BC_MTP_SWTR_RSVD_S   1U
#define SENT_BC_MTP_SWTR_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_EN register
//
//*************************************************************************************************
#define SENT_S1_MTP_EN_MTP_EN   0x1U          //
#define SENT_S1_MTP_EN_RSVD_S   1U
#define SENT_S1_MTP_EN_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP1 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP1_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP1_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP1_RSVD_S         11U
#define SENT_S1_MTP_CMP1_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP2 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP2_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP2_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP2_RSVD_S         11U
#define SENT_S1_MTP_CMP2_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP3 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP3_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP3_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP3_RSVD_S         11U
#define SENT_S1_MTP_CMP3_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP4 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP4_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP4_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP4_RSVD_S         11U
#define SENT_S1_MTP_CMP4_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP5 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP5_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP5_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP5_RSVD_S         11U
#define SENT_S1_MTP_CMP5_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP6 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP6_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP6_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP6_RSVD_S         11U
#define SENT_S1_MTP_CMP6_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP7 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP7_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP7_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP7_RSVD_S         11U
#define SENT_S1_MTP_CMP7_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP8 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP8_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP8_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP8_RSVD_S         11U
#define SENT_S1_MTP_CMP8_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP9 register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP9_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP9_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP9_RSVD_S         11U
#define SENT_S1_MTP_CMP9_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_CMP10RE register
//
//*************************************************************************************************
#define SENT_S1_MTP_CMP10RE_TOGGLETIME_S   0U
#define SENT_S1_MTP_CMP10RE_TOGGLETIME_M   0x7FFU        //
#define SENT_S1_MTP_CMP10RE_RSVD_S         11U
#define SENT_S1_MTP_CMP10RE_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_PERIOD register
//
//*************************************************************************************************
#define SENT_S1_MTP_PERIOD_PERIOD_S   0U
#define SENT_S1_MTP_PERIOD_PERIOD_M   0x7FFU        //
#define SENT_S1_MTP_PERIOD_RSVD_S     11U
#define SENT_S1_MTP_PERIOD_RSVD_M     0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_TRIGSEL register
//
//*************************************************************************************************
#define SENT_S1_TRIGSEL_TRIGSEL_S   0U
#define SENT_S1_TRIGSEL_TRIGSEL_M   0x7FU         //
#define SENT_S1_TRIGSEL_RSVD_S      7U
#define SENT_S1_TRIGSEL_RSVD_M      0xFFFFFF80U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1_MTP_SWTR register
//
//*************************************************************************************************
#define SENT_S1_MTP_SWTR_SWTR     0x1U          //
#define SENT_S1_MTP_SWTR_RSVD_S   1U
#define SENT_S1_MTP_SWTR_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_EN register
//
//*************************************************************************************************
#define SENT_S2_MTP_EN_MTP_EN   0x1U          //
#define SENT_S2_MTP_EN_RSVD_S   1U
#define SENT_S2_MTP_EN_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP1 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP1_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP1_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP1_RSVD_S         11U
#define SENT_S2_MTP_CMP1_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP2 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP2_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP2_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP2_RSVD_S         11U
#define SENT_S2_MTP_CMP2_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP3 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP3_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP3_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP3_RSVD_S         11U
#define SENT_S2_MTP_CMP3_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP4 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP4_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP4_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP4_RSVD_S         11U
#define SENT_S2_MTP_CMP4_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP5 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP5_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP5_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP5_RSVD_S         11U
#define SENT_S2_MTP_CMP5_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP6 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP6_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP6_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP6_RSVD_S         11U
#define SENT_S2_MTP_CMP6_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP7 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP7_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP7_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP7_RSVD_S         11U
#define SENT_S2_MTP_CMP7_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP8 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP8_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP8_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP8_RSVD_S         11U
#define SENT_S2_MTP_CMP8_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP9 register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP9_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP9_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP9_RSVD_S         11U
#define SENT_S2_MTP_CMP9_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_CMP10RE register
//
//*************************************************************************************************
#define SENT_S2_MTP_CMP10RE_TOGGLETIME_S   0U
#define SENT_S2_MTP_CMP10RE_TOGGLETIME_M   0x7FFU        //
#define SENT_S2_MTP_CMP10RE_RSVD_S         11U
#define SENT_S2_MTP_CMP10RE_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_PERIOD register
//
//*************************************************************************************************
#define SENT_S2_MTP_PERIOD_PERIOD_S   0U
#define SENT_S2_MTP_PERIOD_PERIOD_M   0x7FFU        //
#define SENT_S2_MTP_PERIOD_RSVD_S     11U
#define SENT_S2_MTP_PERIOD_RSVD_M     0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_TRIGSEL register
//
//*************************************************************************************************
#define SENT_S2_TRIGSEL_TRIGSEL_S   0U
#define SENT_S2_TRIGSEL_TRIGSEL_M   0x7FU         //
#define SENT_S2_TRIGSEL_RSVD_S      7U
#define SENT_S2_TRIGSEL_RSVD_M      0xFFFFFF80U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2_MTP_SWTR register
//
//*************************************************************************************************
#define SENT_S2_MTP_SWTR_SWTR     0x1U          //
#define SENT_S2_MTP_SWTR_RSVD_S   1U
#define SENT_S2_MTP_SWTR_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_EN register
//
//*************************************************************************************************
#define SENT_S3_MTP_EN_MTP_EN   0x1U          //
#define SENT_S3_MTP_EN_RSVD_S   1U
#define SENT_S3_MTP_EN_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP1 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP1_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP1_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP1_RSVD_S         11U
#define SENT_S3_MTP_CMP1_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP2 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP2_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP2_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP2_RSVD_S         11U
#define SENT_S3_MTP_CMP2_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP3 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP3_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP3_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP3_RSVD_S         11U
#define SENT_S3_MTP_CMP3_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP4 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP4_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP4_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP4_RSVD_S         11U
#define SENT_S3_MTP_CMP4_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP5 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP5_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP5_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP5_RSVD_S         11U
#define SENT_S3_MTP_CMP5_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP6 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP6_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP6_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP6_RSVD_S         11U
#define SENT_S3_MTP_CMP6_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP7 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP7_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP7_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP7_RSVD_S         11U
#define SENT_S3_MTP_CMP7_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP8 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP8_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP8_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP8_RSVD_S         11U
#define SENT_S3_MTP_CMP8_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP9 register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP9_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP9_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP9_RSVD_S         11U
#define SENT_S3_MTP_CMP9_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_CMP10RE register
//
//*************************************************************************************************
#define SENT_S3_MTP_CMP10RE_TOGGLETIME_S   0U
#define SENT_S3_MTP_CMP10RE_TOGGLETIME_M   0x7FFU        //
#define SENT_S3_MTP_CMP10RE_RSVD_S         11U
#define SENT_S3_MTP_CMP10RE_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_PERIOD register
//
//*************************************************************************************************
#define SENT_S3_MTP_PERIOD_PERIOD_S   0U
#define SENT_S3_MTP_PERIOD_PERIOD_M   0x7FFU        //
#define SENT_S3_MTP_PERIOD_RSVD_S     11U
#define SENT_S3_MTP_PERIOD_RSVD_M     0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_TRIGSEL register
//
//*************************************************************************************************
#define SENT_S3_TRIGSEL_TRIGSEL_S   0U
#define SENT_S3_TRIGSEL_TRIGSEL_M   0x7FU         //
#define SENT_S3_TRIGSEL_RSVD_S      7U
#define SENT_S3_TRIGSEL_RSVD_M      0xFFFFFF80U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S3_MTP_SWTR register
//
//*************************************************************************************************
#define SENT_S3_MTP_SWTR_SWTR     0x1U          //
#define SENT_S3_MTP_SWTR_RSVD_S   1U
#define SENT_S3_MTP_SWTR_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_EN register
//
//*************************************************************************************************
#define SENT_S4_MTP_EN_MTP_EN   0x1U          //
#define SENT_S4_MTP_EN_RSVD_S   1U
#define SENT_S4_MTP_EN_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP1 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP1_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP1_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP1_RSVD_S         11U
#define SENT_S4_MTP_CMP1_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP2 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP2_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP2_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP2_RSVD_S         11U
#define SENT_S4_MTP_CMP2_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP3 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP3_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP3_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP3_RSVD_S         11U
#define SENT_S4_MTP_CMP3_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP4 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP4_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP4_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP4_RSVD_S         11U
#define SENT_S4_MTP_CMP4_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP5 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP5_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP5_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP5_RSVD_S         11U
#define SENT_S4_MTP_CMP5_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP6 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP6_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP6_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP6_RSVD_S         11U
#define SENT_S4_MTP_CMP6_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP7 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP7_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP7_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP7_RSVD_S         11U
#define SENT_S4_MTP_CMP7_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP8 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP8_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP8_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP8_RSVD_S         11U
#define SENT_S4_MTP_CMP8_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP9 register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP9_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP9_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP9_RSVD_S         11U
#define SENT_S4_MTP_CMP9_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_CMP10RE register
//
//*************************************************************************************************
#define SENT_S4_MTP_CMP10RE_TOGGLETIME_S   0U
#define SENT_S4_MTP_CMP10RE_TOGGLETIME_M   0x7FFU        //
#define SENT_S4_MTP_CMP10RE_RSVD_S         11U
#define SENT_S4_MTP_CMP10RE_RSVD_M         0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_PERIOD register
//
//*************************************************************************************************
#define SENT_S4_MTP_PERIOD_PERIOD_S   0U
#define SENT_S4_MTP_PERIOD_PERIOD_M   0x7FFU        //
#define SENT_S4_MTP_PERIOD_RSVD_S     11U
#define SENT_S4_MTP_PERIOD_RSVD_M     0xFFFFF800U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_TRIGSEL register
//
//*************************************************************************************************
#define SENT_S4_TRIGSEL_TRIGSEL_S   0U
#define SENT_S4_TRIGSEL_TRIGSEL_M   0x7FU         //
#define SENT_S4_TRIGSEL_RSVD_S      7U
#define SENT_S4_TRIGSEL_RSVD_M      0xFFFFFF80U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the S4_MTP_SWTR register
//
//*************************************************************************************************
#define SENT_S4_MTP_SWTR_SWTR     0x1U          //
#define SENT_S4_MTP_SWTR_RSVD_S   1U
#define SENT_S4_MTP_SWTR_RSVD_M   0xFFFFFFFEU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the WAITTIME register
//
//*************************************************************************************************
#define SENT_WAITTIME_WAITTIME_S   0U
#define SENT_WAITTIME_WAITTIME_M   0xFFFFU       //
#define SENT_WAITTIME_RSVD_S       16U
#define SENT_WAITTIME_RSVD_M       0xFFFF0000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the TPGENSTAT register
//
//*************************************************************************************************
#define SENT_TPGENSTAT_ACTIVE_CH_S   0U
#define SENT_TPGENSTAT_ACTIVE_CH_M   0x1FU         //
#define SENT_TPGENSTAT_SWTSTAT       0x80U         //
#define SENT_TPGENSTAT_TRIG_REQ_S    8U
#define SENT_TPGENSTAT_TRIG_REQ_M    0x1F00U       //
#define SENT_TPGENSTAT_RSVD_S        5U
#define SENT_TPGENSTAT_RSVD_M        0x60U         //
#define SENT_TPGENSTAT_RSVD_1_S      13U
#define SENT_TPGENSTAT_RSVD_1_M      0xFFFFE000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the MTP_SWR register
//
//*************************************************************************************************
#define SENT_MTP_SWR_SWR      0x1U          //
#define SENT_MTP_SWR_RSVD_S   1U
#define SENT_MTP_SWR_RSVD_M   0xFFFFFFFEU   //



#endif
