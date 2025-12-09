//###########################################################################
//
// FILE:    hw_esm_sys.h
//
// TITLE:   Definitions for the ESM_SYS registers.
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

#ifndef HW_ESM_SYS_H
#define HW_ESM_SYS_H

//*************************************************************************************************
//
// The following are defines for the ESM_SYS register offsets
//
//*************************************************************************************************
#define ESM_SYS_O_PID                        0x0U                    // Revision Register
#define ESM_SYS_O_INFO                       0x4U                    // Info Register
#define ESM_SYS_O_EN                         0x8U                    // Global Enable Register
#define ESM_SYS_O_SFT_RST                    0xCU                    // Global Soft Reset Register
#define ESM_SYS_O_LOW_PRI                    0x20U                   // Low Priority Prioritized
                                                                     // Register
#define ESM_SYS_O_HI_PRI                     0x24U                   // High Priority Prioritized
                                                                     // Register
#define ESM_SYS_O_LOW                        0x28U                   // Low Priority Interrupt
                                                                     // Status Register
#define ESM_SYS_O_HI                         0x2CU                   // High Priority Interrupt
                                                                     // Status Register
#define ESM_SYS_O_EOI                        0x30U                   // EOI Interrupt Register
#define ESM_SYS_O_PIN_CTRL                   0x40U                   // Error Pin Control Register
#define ESM_SYS_O_PIN_STS                    0x44U                   // Error Pin Status Register
#define ESM_SYS_O_PIN_CNTR                   0x48U                   // Error Counter Value
                                                                     // Register
#define ESM_SYS_O_PIN_CNTR_PRE               0x4CU                   // Error Counter Value
                                                                     // Pre-Load Register
#define ESM_SYS_O_PWMH_PIN_CNTR              0x50U                   // Error PWM High Counter
                                                                     // Value Register
#define ESM_SYS_O_PWMH_PIN_CNTR_PRE          0x54U                   // Error PWM High Counter
                                                                     // Value Pre-Load Register
#define ESM_SYS_O_PWML_PIN_CNTR              0x58U                   // Error PWM Low Counter Value
                                                                     // Register
#define ESM_SYS_O_PWML_PIN_CNTR_PRE          0x5CU                   // Error PWM Low Counter Value
                                                                     // Pre-Load Register
#define ESM_SYS_O_ERRPIN_MON_CFG             0xA0U                   // Error Pin Monitor Config
                                                                     // Register
#define ESM_SYS_O_ERRPIN_MON_INTR_SET        0xA4U                   // Error Pin Monitor Interrupt
                                                                     // Status/Set Register
#define ESM_SYS_O_ERRPIN_MON_INTR_CLR        0xA8U                   // Error Pin Monitor Interrupt
                                                                     // Status/Clear Register
#define ESM_SYS_O_GROUP_N_LOCK               0x100U                  // Group N Interrupt Lock
                                                                     // Register
#define ESM_SYS_O_GROUP_N_COMMIT             0x104U                  // Group N Interrupt Commit
                                                                     // Register
#define ESM_SYS_O_ERR_PIN_INFLUENCE_LOCK     0x110U                  // Error Pin Influence Lock
                                                                     // Register
#define ESM_SYS_O_ERR_PIN_INFLUENCE_COMMIT   0x114U                  // Error Pin Influence Commit
                                                                     // Register
#define ESM_SYS_O_CRI_PRI_INFLUENCE_LOCK     0x118U                  // Critical Prioirty Interrupt
                                                                     // Influence Lock Register
#define ESM_SYS_O_CRI_PRI_INFLUENCE_COMMIT   0x11CU                  // Critical Priority Interrupt
                                                                     // Influence Lock Register
#define ESM_SYS_O_MMR_CONFIG_LOCK            0x120U                  // MMR Config Lock Register
#define ESM_SYS_O_MMR_CONFIG_COMMIT          0x124U                  // MMR Config Commit Register
#define ESM_SYS_O_RAW(i)                     (0x400U + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Event Raw Status/Set Register
#define ESM_SYS_O_STS(i)                     (0x404U + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Interrupt Enable Status/Clear
                                                                     // Register
#define ESM_SYS_O_INTR_EN_SET(i)             (0x408U + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Interrupt Enable Set Register
#define ESM_SYS_O_INTR_EN_CLR(i)             (0x40CU + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Interrupt Enabled Clear Register
#define ESM_SYS_O_INT_PRIO(i)                (0x410U + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Interrupt Priority Register
#define ESM_SYS_O_PIN_EN_SET(i)              (0x414U + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Error Pin Influence Set Register
#define ESM_SYS_O_PIN_EN_CLR(i)              (0x418U + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Error Pin Influence Clear Register
#define ESM_SYS_O_CRIT_EN_SET(i)             (0x800U + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Critical Priority Interrupt
                                                                     // Influence Set Register
#define ESM_SYS_O_CRIT_EN_CLR(i)             (0x804U + ((i) * 32U))  // (0 <= i < 8) Error Group N
                                                                     // Critical Priority Interrupt
                                                                     // Influence Clear Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the PID register
//
//*************************************************************************************************
#define ESM_SYS_PID_MINOR_S    0U
#define ESM_SYS_PID_MINOR_M    0x3FU         //
#define ESM_SYS_PID_CUSTOM_S   6U
#define ESM_SYS_PID_CUSTOM_M   0xC0U         //
#define ESM_SYS_PID_MAJOR_S    8U
#define ESM_SYS_PID_MAJOR_M    0x700U        //
#define ESM_SYS_PID_RTL_S      11U
#define ESM_SYS_PID_RTL_M      0xF800U       //
#define ESM_SYS_PID_FUNC_S     16U
#define ESM_SYS_PID_FUNC_M     0xFFF0000U    //
#define ESM_SYS_PID_BU_S       28U
#define ESM_SYS_PID_BU_M       0x30000000U   //
#define ESM_SYS_PID_SCHEME_S   30U
#define ESM_SYS_PID_SCHEME_M   0xC0000000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the INFO register
//
//*************************************************************************************************
#define ESM_SYS_INFO_GROUPS_S         0U
#define ESM_SYS_INFO_GROUPS_M         0xFFU         //
#define ESM_SYS_INFO_PULSE_GROUPS_S   8U
#define ESM_SYS_INFO_PULSE_GROUPS_M   0xFF00U       //
#define ESM_SYS_INFO_CRIT_INTR        0x40000000U   //
#define ESM_SYS_INFO_LAST_RESET       0x80000000U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the EN register
//
//*************************************************************************************************
#define ESM_SYS_EN_KEY_S   0U
#define ESM_SYS_EN_KEY_M   0xFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the SFT_RST register
//
//*************************************************************************************************
#define ESM_SYS_SFT_RST_KEY_S   0U
#define ESM_SYS_SFT_RST_KEY_M   0xFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the LOW_PRI register
//
//*************************************************************************************************
#define ESM_SYS_LOW_PRI_PLS_S   16U
#define ESM_SYS_LOW_PRI_PLS_M   0xFFFF0000U   //
#define ESM_SYS_LOW_PRI_LVL_S   0U
#define ESM_SYS_LOW_PRI_LVL_M   0xFFFFU       //

//*************************************************************************************************
//
// The following are defines for the bit fields in the HI_PRI register
//
//*************************************************************************************************
#define ESM_SYS_HI_PRI_PLS_S   16U
#define ESM_SYS_HI_PRI_PLS_M   0xFFFF0000U   //
#define ESM_SYS_HI_PRI_LVL_S   0U
#define ESM_SYS_HI_PRI_LVL_M   0xFFFFU       //

//*************************************************************************************************
//
// The following are defines for the bit fields in the EOI register
//
//*************************************************************************************************
#define ESM_SYS_EOI_KEY_S   0U
#define ESM_SYS_EOI_KEY_M   0x7FFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the PIN_CTRL register
//
//*************************************************************************************************
#define ESM_SYS_PIN_CTRL_POLARITY_S   8U
#define ESM_SYS_PIN_CTRL_POLARITY_M   0xF00U   //
#define ESM_SYS_PIN_CTRL_PWM_EN_S     4U
#define ESM_SYS_PIN_CTRL_PWM_EN_M     0xF0U    //
#define ESM_SYS_PIN_CTRL_KEY_S        0U
#define ESM_SYS_PIN_CTRL_KEY_M        0xFU     //

//*************************************************************************************************
//
// The following are defines for the bit fields in the PIN_STS register
//
//*************************************************************************************************
#define ESM_SYS_PIN_STS_VAL   0x1U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the PIN_CNTR register
//
//*************************************************************************************************
#define ESM_SYS_PIN_CNTR_COUNT_S   0U
#define ESM_SYS_PIN_CNTR_COUNT_M   0xFFFFFFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the PIN_CNTR_PRE register
//
//*************************************************************************************************
#define ESM_SYS_PIN_CNTR_PRE_COUNT_S   0U
#define ESM_SYS_PIN_CNTR_PRE_COUNT_M   0xFFFFFFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the PWMH_PIN_CNTR register
//
//*************************************************************************************************
#define ESM_SYS_PWMH_PIN_CNTR_COUNT_S   0U
#define ESM_SYS_PWMH_PIN_CNTR_COUNT_M   0xFFFFFFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the PWMH_PIN_CNTR_PRE register
//
//*************************************************************************************************
#define ESM_SYS_PWMH_PIN_CNTR_PRE_COUNT_S   0U
#define ESM_SYS_PWMH_PIN_CNTR_PRE_COUNT_M   0xFFFFFFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the PWML_PIN_CNTR register
//
//*************************************************************************************************
#define ESM_SYS_PWML_PIN_CNTR_COUNT_S   0U
#define ESM_SYS_PWML_PIN_CNTR_COUNT_M   0xFFFFFFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the PWML_PIN_CNTR_PRE register
//
//*************************************************************************************************
#define ESM_SYS_PWML_PIN_CNTR_PRE_COUNT_S   0U
#define ESM_SYS_PWML_PIN_CNTR_PRE_COUNT_M   0xFFFFFFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRPIN_MON_CFG register
//
//*************************************************************************************************
#define ESM_SYS_ERRPIN_MON_CFG_MON_EN_S   0U
#define ESM_SYS_ERRPIN_MON_CFG_MON_EN_M   0xFU   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRPIN_MON_INTR_SET register
//
//*************************************************************************************************
#define ESM_SYS_ERRPIN_MON_INTR_SET_VAL   0x1U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERRPIN_MON_INTR_CLR register
//
//*************************************************************************************************
#define ESM_SYS_ERRPIN_MON_INTR_CLR_VAL   0x1U   //

//*************************************************************************************************
//
// The following are defines for the bit fields in the MMR_CONFIG_LOCK register
//
//*************************************************************************************************
#define ESM_SYS_MMR_CONFIG_LOCK_GLOBEL_EN_LOCK         0x100U   //
#define ESM_SYS_MMR_CONFIG_LOCK_GLOBAL_SOFT_RST_LOCK   0x20U    //
#define ESM_SYS_MMR_CONFIG_LOCK_ERRPIN_LOCK            0x4U     //
#define ESM_SYS_MMR_CONFIG_LOCK_ERRPIN_MON_LOCK        0x2U     //
#define ESM_SYS_MMR_CONFIG_LOCK_HI_PRI_WD_LOCK         0x1U     //

//*************************************************************************************************
//
// The following are defines for the bit fields in the MMR_CONFIG_COMMIT register
//
//*************************************************************************************************
#define ESM_SYS_MMR_CONFIG_COMMIT_GLOBEL_EN_COMMIT         0x100U   //
#define ESM_SYS_MMR_CONFIG_COMMIT_GLOBAL_SOFT_RST_COMMIT   0x20U    //
#define ESM_SYS_MMR_CONFIG_COMMIT_ERRPIN_COMMIT            0x4U     //
#define ESM_SYS_MMR_CONFIG_COMMIT_ERRPIN_MON_COMMIT        0x2U     //
#define ESM_SYS_MMR_CONFIG_COMMIT_HI_PRI_WD_COMMIT         0x1U     //



#endif
