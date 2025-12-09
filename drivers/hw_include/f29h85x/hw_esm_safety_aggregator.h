//###########################################################################
//
// FILE:    hw_esm_safety_aggregator.h
//
// TITLE:   Definitions for the ESM_SAFETY_AGGREGATOR registers.
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

#ifndef HW_ESM_SAFETY_AGGREGATOR_H
#define HW_ESM_SAFETY_AGGREGATOR_H

//*************************************************************************************************
//
// The following are defines for the ESM_SAFETY_AGGREGATOR register offsets
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_O_AGGR_REVISION         0x0U     // Aggregator Revision Register
#define ESM_SAFETY_AGGREGATOR_O_ECC_VECTOR            0x8U     // ECC Vector Register
#define ESM_SAFETY_AGGREGATOR_O_MISC_STATUS           0xCU     // Misc Status
#define ESM_SAFETY_AGGREGATOR_O_DED_EOI_REG           0x13CU   // EOI Register
#define ESM_SAFETY_AGGREGATOR_O_DED_STATUS_REG0       0x140U   // Interrupt Status Register 0
#define ESM_SAFETY_AGGREGATOR_O_DED_ENABLE_SET_REG0   0x180U   // Interrupt Enable Set Register 0
#define ESM_SAFETY_AGGREGATOR_O_DED_ENABLE_CLR_REG0   0x1C0U   // Interrupt Enable Clear Register 0
#define ESM_SAFETY_AGGREGATOR_O_AGGR_ENABLE_SET       0x200U   // AGGR interrupt enable set
                                                               // Register
#define ESM_SAFETY_AGGREGATOR_O_AGGR_ENABLE_CLR       0x204U   // AGGR interrupt enable clear
                                                               // Register
#define ESM_SAFETY_AGGREGATOR_O_AGGR_STATUS_SET       0x208U   // AGGR interrupt status set
                                                               // Register
#define ESM_SAFETY_AGGREGATOR_O_AGGR_STATUS_CLR       0x20CU   // AGGR interrupt status clear
                                                               // Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the aggr_revision register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_SCHEME_S      30U
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_SCHEME_M      0xC0000000U   //
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_BU_S          28U
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_BU_M          0x30000000U   //
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_MODULE_ID_S   16U
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_MODULE_ID_M   0xFFF0000U    //
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_REVRTL_S      11U
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_REVRTL_M      0xF800U       //
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_REVMAJ_S      8U
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_REVMAJ_M      0x700U        //
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_CUSTOM_S      6U
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_CUSTOM_M      0xC0U         //
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_REVMIN_S      0U
#define ESM_SAFETY_AGGREGATOR_AGGR_REVISION_REVMIN_M      0x3FU         //

//*************************************************************************************************
//
// The following are defines for the bit fields in the ecc_vector register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_ECC_VECTOR_ECC_VECTOR_S         0U
#define ESM_SAFETY_AGGREGATOR_ECC_VECTOR_ECC_VECTOR_M         0x7FFU       //
#define ESM_SAFETY_AGGREGATOR_ECC_VECTOR_RD_SVBUS             0x8000U      //
#define ESM_SAFETY_AGGREGATOR_ECC_VECTOR_RD_SVBUS_ADDRESS_S   16U
#define ESM_SAFETY_AGGREGATOR_ECC_VECTOR_RD_SVBUS_ADDRESS_M   0xFF0000U    //
#define ESM_SAFETY_AGGREGATOR_ECC_VECTOR_RD_SVBUS_DONE        0x1000000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the misc_status register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_MISC_STATUS_NUM_RAMS_S   0U
#define ESM_SAFETY_AGGREGATOR_MISC_STATUS_NUM_RAMS_M   0x7FFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the ded_eoi_reg register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_DED_EOI_REG_EOI_WR   0x1U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the ded_status_reg0 register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_DED_STATUS_REG0_ESMSS_SYS_ESM_EDC_CTRL_BUSECC_PEND   0x1U   //
#define ESM_SAFETY_AGGREGATOR_DED_STATUS_REG0_ESMSS_ESM0_EDC_CTRL_BUSECC_PEND      0x2U   //
#define ESM_SAFETY_AGGREGATOR_DED_STATUS_REG0_ESMSS_ESM1_EDC_CTRL_BUSECC_PEND      0x4U   //
#define ESM_SAFETY_AGGREGATOR_DED_STATUS_REG0_ESMSS_ESM2_EDC_CTRL_BUSECC_PEND      0x8U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the ded_enable_set_reg0 register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_DED_ENABLE_SET_REG0_ESMSS_SYS_ESM_EDC_CTRL_BUSECC_ENABLE_SET   0x1U   //
                                                                                                    // 
#define ESM_SAFETY_AGGREGATOR_DED_ENABLE_SET_REG0_ESMSS_ESM0_EDC_CTRL_BUSECC_ENABLE_SET      0x2U   //
                                                                                                    // 
#define ESM_SAFETY_AGGREGATOR_DED_ENABLE_SET_REG0_ESMSS_ESM1_EDC_CTRL_BUSECC_ENABLE_SET      0x4U   //
                                                                                                    // 
#define ESM_SAFETY_AGGREGATOR_DED_ENABLE_SET_REG0_ESMSS_ESM2_EDC_CTRL_BUSECC_ENABLE_SET      0x8U   //
                                                                                                    // 

//*************************************************************************************************
//
// The following are defines for the bit fields in the ded_enable_clr_reg0 register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_DED_ENABLE_CLR_REG0_ESMSS_SYS_ESM_EDC_CTRL_BUSECC_ENABLE_CLR   0x1U   //
                                                                                                    // 
#define ESM_SAFETY_AGGREGATOR_DED_ENABLE_CLR_REG0_ESMSS_ESM0_EDC_CTRL_BUSECC_ENABLE_CLR      0x2U   //
                                                                                                    // 
#define ESM_SAFETY_AGGREGATOR_DED_ENABLE_CLR_REG0_ESMSS_ESM1_EDC_CTRL_BUSECC_ENABLE_CLR      0x4U   //
                                                                                                    // 
#define ESM_SAFETY_AGGREGATOR_DED_ENABLE_CLR_REG0_ESMSS_ESM2_EDC_CTRL_BUSECC_ENABLE_CLR      0x8U   //
                                                                                                    // 

//*************************************************************************************************
//
// The following are defines for the bit fields in the aggr_enable_set register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_AGGR_ENABLE_SET_PARITY    0x1U   //
#define ESM_SAFETY_AGGREGATOR_AGGR_ENABLE_SET_TIMEOUT   0x2U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the aggr_enable_clr register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_AGGR_ENABLE_CLR_PARITY    0x1U   //
#define ESM_SAFETY_AGGREGATOR_AGGR_ENABLE_CLR_TIMEOUT   0x2U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the aggr_status_set register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_AGGR_STATUS_SET_PARITY_S    0U
#define ESM_SAFETY_AGGREGATOR_AGGR_STATUS_SET_PARITY_M    0x3U   //
#define ESM_SAFETY_AGGREGATOR_AGGR_STATUS_SET_TIMEOUT_S   2U
#define ESM_SAFETY_AGGREGATOR_AGGR_STATUS_SET_TIMEOUT_M   0xCU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the aggr_status_clr register
//
//*************************************************************************************************
#define ESM_SAFETY_AGGREGATOR_AGGR_STATUS_CLR_PARITY_S    0U
#define ESM_SAFETY_AGGREGATOR_AGGR_STATUS_CLR_PARITY_M    0x3U   //
#define ESM_SAFETY_AGGREGATOR_AGGR_STATUS_CLR_TIMEOUT_S   2U
#define ESM_SAFETY_AGGREGATOR_AGGR_STATUS_CLR_TIMEOUT_M   0xCU   //



#endif
