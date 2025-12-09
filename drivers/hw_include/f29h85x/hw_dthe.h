//###########################################################################
//
// FILE:    hw_dthe.h
//
// TITLE:   Definitions for the DTHE registers.
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

#ifndef HW_DTHE_H
#define HW_DTHE_H

//*************************************************************************************************
//
// The following are defines for the DTHE register offsets
//
//*************************************************************************************************
#define DTHE_O_S_EIP_CONFIG    0x0U     // EIP Configuration register
#define DTHE_O_S_EIP57T_IMST   0x20U    // EIP57T Interrupt Mask Set Register
#define DTHE_O_S_EIP57T_IRIS   0x24U    // EIP57T Interrupt Raw Interrupt Status Register
#define DTHE_O_S_EIP57T_IMIS   0x28U    // EIP57T Interrupt Masked interrupt Status Register
#define DTHE_O_S_EIP57T_ICIS   0x2CU    // EIP57T Interrupt Clear Interrupt Status Register
#define DTHE_O_S_EIP36T_IMST   0x30U    // EIP36T Interrupt Mask Set Register
#define DTHE_O_S_EIP36T_IRIS   0x34U    // EIP36T Interrupt Raw Interrupt Status Register
#define DTHE_O_S_EIP36T_IMIS   0x38U    // EIP36T Interrupt Masked interrupt Status Register
#define DTHE_O_S_EIP36T_ICIS   0x3CU    // EIP36T Interrupt Clear Interrupt Status Register
#define DTHE_O_S_EIP_CGCFG     0x200U   // EIP Clock gating configuration
#define DTHE_O_S_EIP_CGREQ     0x204U   // EIP Clock gating Request
#define DTHE_O_S_CRC_CTRL      0x400U   // CRC Control register
#define DTHE_O_S_CRC_SEED      0x410U   // CRC SEED/Context-CRC register
#define DTHE_O_S_CRC_DIN       0x414U   // CRC DATA Input register
#define DTHE_O_S_CRC_RSLT_PP   0x418U   // CRC post processed output
#define DTHE_O_P_EIP57T_IMST   0x820U   // EIP57T Interrupt Mask Set Register
#define DTHE_O_P_EIP57T_IRIS   0x824U   // EIP57T Interrupt Raw Interrupt Status Register
#define DTHE_O_P_EIP57T_IMIS   0x828U   // EIP57T Interrupt Masked interrupt Status Register
#define DTHE_O_P_EIP57T_ICIS   0x82CU   // EIP57T Interrupt Clear Interrupt Status Register
#define DTHE_O_P_EIP36T_IMST   0x830U   // EIP36T Interrupt Mask Set Register
#define DTHE_O_P_EIP36T_IRIS   0x834U   // EIP36T Interrupt Raw Interrupt Status Register
#define DTHE_O_P_EIP36T_IMIS   0x838U   // EIP36T Interrupt Masked interrupt Status Register
#define DTHE_O_P_EIP36T_ICIS   0x83CU   // EIP36T Interrupt Clear Interrupt Status Register
#define DTHE_O_P_EIP_CGCFG     0xA00U   // EIP Clock gating configuration
#define DTHE_O_P_EIP_CGREQ     0xA04U   // EIP Clock gating Request
#define DTHE_O_P_CRC_CTRL      0xC00U   // CRC Control register
#define DTHE_O_P_CRC_SEED      0xC10U   // CRC SEED/Context-CRC register
#define DTHE_O_P_CRC_DIN       0xC14U   // CRC DATA Input register
#define DTHE_O_P_CRC_RSLT_PP   0xC18U   // CRC post processed output


//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP_CONFIG register
//
//*************************************************************************************************
#define DTHE_S_EIP_CONFIG_ASE   0x1U   // AES supervisor mode enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP57T_IMST register
//
//*************************************************************************************************
#define DTHE_S_EIP57T_IMST_CIN    0x1U   // Interrupt Mask Set for Cin
#define DTHE_S_EIP57T_IMST_COUT   0x2U   // Interrupt Mask Set for Cout
#define DTHE_S_EIP57T_IMST_DIN    0x4U   // Interrupt Mask Set for Din

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP57T_IRIS register
//
//*************************************************************************************************
#define DTHE_S_EIP57T_IRIS_CIN    0x1U   // Raw Interrupt Status for Cin
#define DTHE_S_EIP57T_IRIS_COUT   0x2U   // Raw Interrupt Status for Cout
#define DTHE_S_EIP57T_IRIS_DIN    0x4U   // Raw Interrupt Status for Din

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP57T_IMIS register
//
//*************************************************************************************************
#define DTHE_S_EIP57T_IMIS_CIN    0x1U   // Masked Interrupt Status for Cin
#define DTHE_S_EIP57T_IMIS_COUT   0x2U   // Masked Interrupt Status for Cout
#define DTHE_S_EIP57T_IMIS_DIN    0x4U   // Masked Interrupt Status for Din

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP57T_ICIS register
//
//*************************************************************************************************
#define DTHE_S_EIP57T_ICIS_CIN    0x1U   // Clear Interrupt Status for Cin
#define DTHE_S_EIP57T_ICIS_COUT   0x2U   // Clear Interrupt Status for Cout
#define DTHE_S_EIP57T_ICIS_DIN    0x4U   // Clear Interrupt Status for Din

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP36T_IMST register
//
//*************************************************************************************************
#define DTHE_S_EIP36T_IMST_CIN    0x1U   // Interrupt Mask Set for Cin
#define DTHE_S_EIP36T_IMST_COUT   0x2U   // Interrupt Mask Set for Cout
#define DTHE_S_EIP36T_IMST_DIN    0x4U   // Interrupt Mask Set for Din
#define DTHE_S_EIP36T_IMST_DOUT   0x8U   // Interrupt Mask Set for Dout

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP36T_IRIS register
//
//*************************************************************************************************
#define DTHE_S_EIP36T_IRIS_CIN    0x1U   // Raw Interrupt Status for Cin
#define DTHE_S_EIP36T_IRIS_COUT   0x2U   // Raw Interrupt Status for Cout
#define DTHE_S_EIP36T_IRIS_DIN    0x4U   // Raw Interrupt Status for Din
#define DTHE_S_EIP36T_IRIS_DOUT   0x8U   // Raw Interrupt Status for Dout

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP36T_IMIS register
//
//*************************************************************************************************
#define DTHE_S_EIP36T_IMIS_CIN    0x1U   // Masked Interrupt Status for Cin
#define DTHE_S_EIP36T_IMIS_COUT   0x2U   // Masked Interrupt Status for Cout
#define DTHE_S_EIP36T_IMIS_DIN    0x4U   // Masked Interrupt Status for Din
#define DTHE_S_EIP36T_IMIS_DOUT   0x8U   // Masked Interrupt Status for Dout

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP36T_ICIS register
//
//*************************************************************************************************
#define DTHE_S_EIP36T_ICIS_CIN    0x1U   // Clear Interrupt Status for Cin
#define DTHE_S_EIP36T_ICIS_COUT   0x2U   // Clear Interrupt Status for Cout
#define DTHE_S_EIP36T_ICIS_DIN    0x4U   // Clear Interrupt Status for Din
#define DTHE_S_EIP36T_ICIS_DOUT   0x8U   // Clear Interrupt Status for Dout

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP_CGCFG register
//
//*************************************************************************************************
#define DTHE_S_EIP_CGCFG_EIP57_CFG   0x2U    // Clock gating configuration for Eip57_cfg
#define DTHE_S_EIP_CGCFG_EIP36_CFG   0x4U    // Clock gating configuration for EIP36_cfg
#define DTHE_S_EIP_CGCFG_EIP29_CFG   0x10U   // Clock gating configuration for Eip29_cfg
#define DTHE_S_EIP_CGCFG_TRNG_CFG    0x20U   // Clock gating configuration for TRNG_cfg

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_EIP_CGREQ register
//
//*************************************************************************************************
#define DTHE_S_EIP_CGREQ_EIP57_REQ   0x2U    // Clock gating Request for Eip57_req
#define DTHE_S_EIP_CGREQ_EIP36_REQ   0x4U    // Clock gating Request for EIP36_req
#define DTHE_S_EIP_CGREQ_EIP29_REQ   0x10U   // Clock gating Request for Eip29_req
#define DTHE_S_EIP_CGREQ_TRNG_REQ    0x20U   // Clock gating Request for TRNG_req

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_S_CRC_CTRL register
//
//*************************************************************************************************
#define DTHE_S_CRC_CTRL_TYPE_S     0U
#define DTHE_S_CRC_CTRL_TYPE_M     0xFU      // Type of operation
#define DTHE_S_CRC_CTRL_ENDIAN_S   4U
#define DTHE_S_CRC_CTRL_ENDIAN_M   0x30U     // Endian Control
#define DTHE_S_CRC_CTRL_IBR        0x80U     // Bit reverse the input byte.
#define DTHE_S_CRC_CTRL_OBR        0x100U    // Bit reserved the output result byte
#define DTHE_S_CRC_CTRL_OINV       0x200U    // Inverse the bits of result
#define DTHE_S_CRC_CTRL_BYTE       0x1000U   // Input data size
#define DTHE_S_CRC_CTRL_INIT_S     13U
#define DTHE_S_CRC_CTRL_INIT_M     0x6000U   // CRC Initialization
#define DTHE_S_CRC_CTRL_FLATO      0x8000U   // Flash access port to feed CRC

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP57T_IMST register
//
//*************************************************************************************************
#define DTHE_P_EIP57T_IMST_CIN    0x1U   // Interrupt Mask Set for Cin
#define DTHE_P_EIP57T_IMST_COUT   0x2U   // Interrupt Mask Set for Cout
#define DTHE_P_EIP57T_IMST_DIN    0x4U   // Interrupt Mask Set for Din

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP57T_IRIS register
//
//*************************************************************************************************
#define DTHE_P_EIP57T_IRIS_CIN    0x1U   // Raw Interrupt Status for Cin
#define DTHE_P_EIP57T_IRIS_COUT   0x2U   // Raw Interrupt Status for Cout
#define DTHE_P_EIP57T_IRIS_DIN    0x4U   // Raw Interrupt Status for Din

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP57T_IMIS register
//
//*************************************************************************************************
#define DTHE_P_EIP57T_IMIS_CIN    0x1U   // Masked Interrupt Status for Cin
#define DTHE_P_EIP57T_IMIS_COUT   0x2U   // Masked Interrupt Status for Cout
#define DTHE_P_EIP57T_IMIS_DIN    0x4U   // Masked Interrupt Status for Din

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP57T_ICIS register
//
//*************************************************************************************************
#define DTHE_P_EIP57T_ICIS_CIN    0x1U   // Clear Interrupt Status for Cin
#define DTHE_P_EIP57T_ICIS_COUT   0x2U   // Clear Interrupt Status for Cout
#define DTHE_P_EIP57T_ICIS_DIN    0x4U   // Clear Interrupt Status for Din

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP36T_IMST register
//
//*************************************************************************************************
#define DTHE_P_EIP36T_IMST_CIN    0x1U   // Interrupt Mask Set for Cin
#define DTHE_P_EIP36T_IMST_COUT   0x2U   // Interrupt Mask Set for Cout
#define DTHE_P_EIP36T_IMST_DIN    0x4U   // Interrupt Mask Set for Din
#define DTHE_P_EIP36T_IMST_DOUT   0x8U   // Interrupt Mask Set for Dout

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP36T_IRIS register
//
//*************************************************************************************************
#define DTHE_P_EIP36T_IRIS_CIN    0x1U   // Raw Interrupt Status for Cin
#define DTHE_P_EIP36T_IRIS_COUT   0x2U   // Raw Interrupt Status for Cout
#define DTHE_P_EIP36T_IRIS_DIN    0x4U   // Raw Interrupt Status for Din
#define DTHE_P_EIP36T_IRIS_DOUT   0x8U   // Raw Interrupt Status for Dout

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP36T_IMIS register
//
//*************************************************************************************************
#define DTHE_P_EIP36T_IMIS_CIN    0x1U   // Masked Interrupt Status for Cin
#define DTHE_P_EIP36T_IMIS_COUT   0x2U   // Masked Interrupt Status for Cout
#define DTHE_P_EIP36T_IMIS_DIN    0x4U   // Masked Interrupt Status for Din
#define DTHE_P_EIP36T_IMIS_DOUT   0x8U   // Masked Interrupt Status for Dout

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP36T_ICIS register
//
//*************************************************************************************************
#define DTHE_P_EIP36T_ICIS_CIN    0x1U   // Clear Interrupt Status for Cin
#define DTHE_P_EIP36T_ICIS_COUT   0x2U   // Clear Interrupt Status for Cout
#define DTHE_P_EIP36T_ICIS_DIN    0x4U   // Clear Interrupt Status for Din
#define DTHE_P_EIP36T_ICIS_DOUT   0x8U   // Clear Interrupt Status for Dout

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP_CGCFG register
//
//*************************************************************************************************
#define DTHE_P_EIP_CGCFG_EIP57_CFG   0x2U    // Clock gating configuration for Eip57_cfg
#define DTHE_P_EIP_CGCFG_EIP36_CFG   0x4U    // Clock gating configuration for EIP36_cfg
#define DTHE_P_EIP_CGCFG_EIP29_CFG   0x10U   // Clock gating configuration for Eip29_cfg
#define DTHE_P_EIP_CGCFG_TRNG_CFG    0x20U   // Clock gating configuration for TRNG_cfg

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_EIP_CGREQ register
//
//*************************************************************************************************
#define DTHE_P_EIP_CGREQ_EIP57_REQ   0x2U    // Clock gating Request for Eip57_req
#define DTHE_P_EIP_CGREQ_EIP36_REQ   0x4U    // Clock gating Request for EIP36_req
#define DTHE_P_EIP_CGREQ_EIP29_REQ   0x10U   // Clock gating Request for Eip29_req
#define DTHE_P_EIP_CGREQ_TRNG_REQ    0x20U   // Clock gating Request for TRNG_req

//*************************************************************************************************
//
// The following are defines for the bit fields in the DTHE_P_CRC_CTRL register
//
//*************************************************************************************************
#define DTHE_P_CRC_CTRL_TYPE_S     0U
#define DTHE_P_CRC_CTRL_TYPE_M     0xFU      // Type of operation
#define DTHE_P_CRC_CTRL_ENDIAN_S   4U
#define DTHE_P_CRC_CTRL_ENDIAN_M   0x30U     // Endian Control
#define DTHE_P_CRC_CTRL_IBR        0x80U     // Bit reverse the input byte.
#define DTHE_P_CRC_CTRL_OBR        0x100U    // Bit reserved the output result byte
#define DTHE_P_CRC_CTRL_OINV       0x200U    // Inverse the bits of result
#define DTHE_P_CRC_CTRL_BYTE       0x1000U   // Input data size
#define DTHE_P_CRC_CTRL_INIT_S     13U
#define DTHE_P_CRC_CTRL_INIT_M     0x6000U   // CRC Initialization
#define DTHE_P_CRC_CTRL_FLATO      0x8000U   // Flash access port to feed CRC



#endif
