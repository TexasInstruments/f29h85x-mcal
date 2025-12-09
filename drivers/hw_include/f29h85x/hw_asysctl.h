//###########################################################################
//
// FILE:    hw_asysctl.h
//
// TITLE:   Definitions for the ASYSCTL registers.
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

#ifndef HW_ASYSCTL_H
#define HW_ASYSCTL_H

//*************************************************************************************************
//
// The following are defines for the ASYSCTL register offsets
//
//*************************************************************************************************
#define ASYSCTL_O_PMMVREGTRIM       0x44U    // Power Management Module VREG Trim Register
#define ASYSCTL_O_CTLTRIMSTS        0x70U    // HWCTL TRIM Error Status register
#define ASYSCTL_O_REFBUFCONFIGCDE   0x154U   // Config register for analog reference CDE
#define ASYSCTL_O_INTERNALTESTCTL   0x1A8U   // INTERNALTEST Node Control Register
#define ASYSCTL_O_CONFIGLOCK        0x1E8U   // Lock Register for all the config registers.
#define ASYSCTL_O_TSNSCTL           0x1ECU   // Temperature Sensor Control Register
#define ASYSCTL_O_ANAREFCTL         0x20CU   // Analog Reference Control Register.
#define ASYSCTL_O_VREGCTL           0x214U   // Voltage Regulator Control Register
#define ASYSCTL_O_VMONCTL           0x22CU   // Voltage Monitor Control Register
#define ASYSCTL_O_CMPHPMXSEL        0x26CU   // Bits to select one of the many sources on CopmHP
                                             // inputs. Refer to Pimux diagram for details.
#define ASYSCTL_O_CMPHPMXSEL1       0x270U   // Bits to select one of the many sources on CopmHP
                                             // inputs. Refer to Pimux diagram for details.
#define ASYSCTL_O_CMPLPMXSEL        0x274U   // Bits to select one of the many sources on CopmLP
                                             // inputs. Refer to Pimux diagram for details.
#define ASYSCTL_O_CMPLPMXSEL1       0x278U   // Bits to select one of the many sources on CopmLP
                                             // inputs. Refer to Pimux diagram for details.
#define ASYSCTL_O_CMPHNMXSEL        0x27CU   // Bits to select one of the many sources on CopmHN
                                             // inputs. Refer to Pimux diagram for details.
#define ASYSCTL_O_CMPLNMXSEL        0x280U   // Bits to select one of the many sources on CopmLN
                                             // inputs. Refer to Pimux diagram for details.
#define ASYSCTL_O_LOCK              0x294U   // Lock Register
#define ASYSCTL_O_IODRVSEL          0x458U   // 5V FS IO Drive strength select register
#define ASYSCTL_O_IOMODESEL         0x45CU   // PMBUS IO Mode select register
#define ASYSCTL_O_AGPIOFILTER       0x464U   // AGPIO Filter Control Register
#define ASYSCTL_O_AGPIOCTRLH        0x48CU   // AGPIO Control Register
#define ASYSCTL_O_PARITY_TEST       0x4B4U   // Enables parity test

#define ASYSCTL_O_ADCSOCFRCGB        0x0U   // ADC Global SOC Force
#define ASYSCTL_O_ADCSOCFRCGBSEL     0x4U   // ADC Global SOC Force Select
#define ASYSCTL_O_PARITY_TEST_ALT1   0x8U   // Enables parity test


//*************************************************************************************************
//
// The following are defines for the bit fields in the PMMVREGTRIM register
//
//*************************************************************************************************
#define ASYSCTL_PMMVREGTRIM_VREGTRIM_S   0U
#define ASYSCTL_PMMVREGTRIM_VREGTRIM_M   0xFFU   // Core VDD Voltage Regulator Trim

//*************************************************************************************************
//
// The following are defines for the bit fields in the CTLTRIMSTS register
//
//*************************************************************************************************
#define ASYSCTL_CTLTRIMSTS_CTLSTS    0x1U       // TRIM Load Complete
#define ASYSCTL_CTLTRIMSTS_SBERR     0x80U      // Single-bit error detected while reading from
                                                // Flash
#define ASYSCTL_CTLTRIMSTS_SCANERR   0x100U     // Wrong scan chain signature
#define ASYSCTL_CTLTRIMSTS_TWOBERR   0x400U     // Two-bit error detected
#define ASYSCTL_CTLTRIMSTS_TIMEOUT   0x800U     // Timeout Error
#define ASYSCTL_CTLTRIMSTS_INVKEY1   0x10000U   // Invalid key read during TLC1
#define ASYSCTL_CTLTRIMSTS_INVKEY2   0x20000U   // Invalid key read during TLC2
#define ASYSCTL_CTLTRIMSTS_INVKEY3   0x40000U   // Invalid key read during TLC3

//*************************************************************************************************
//
// The following are defines for the bit fields in the REFBUFCONFIGCDE register
//
//*************************************************************************************************
#define ASYSCTL_REFBUFCONFIGCDE_ADCC_LSB_RES_DAMP_S       0U
#define ASYSCTL_REFBUFCONFIGCDE_ADCC_LSB_RES_DAMP_M       0x3U          // ADCC LSB damp res prog
#define ASYSCTL_REFBUFCONFIGCDE_ADCC_MSB_RES_DAMP_S       2U
#define ASYSCTL_REFBUFCONFIGCDE_ADCC_MSB_RES_DAMP_M       0xCU          // ADCC MSB damp res prog
#define ASYSCTL_REFBUFCONFIGCDE_ADCC_CHSEL_SOC_DEL_PROG   0x10U         // CHSEL rise to ADCCSOC
                                                                        // rise delay program
#define ASYSCTL_REFBUFCONFIGCDE_ADCD_LSB_RES_DAMP_S       5U
#define ASYSCTL_REFBUFCONFIGCDE_ADCD_LSB_RES_DAMP_M       0x60U         // ADCD LSB damp res prog
#define ASYSCTL_REFBUFCONFIGCDE_ADCD_MSB_RES_DAMP_S       7U
#define ASYSCTL_REFBUFCONFIGCDE_ADCD_MSB_RES_DAMP_M       0x180U        // ADCD MSB damp res prog
#define ASYSCTL_REFBUFCONFIGCDE_ADCD_CHSEL_SOC_DEL_PROG   0x200U        // CHSEL rise to ADCDSOC
                                                                        // rise delay program
#define ASYSCTL_REFBUFCONFIGCDE_ADCE_LSB_RES_DAMP_S       10U
#define ASYSCTL_REFBUFCONFIGCDE_ADCE_LSB_RES_DAMP_M       0xC00U        // ADCE LSB damp res prog
#define ASYSCTL_REFBUFCONFIGCDE_ADCE_MSB_RES_DAMP_S       12U
#define ASYSCTL_REFBUFCONFIGCDE_ADCE_MSB_RES_DAMP_M       0x3000U       // ADCE MSB damp res prog
#define ASYSCTL_REFBUFCONFIGCDE_ADCE_CHSEL_SOC_DEL_PROG   0x4000U       // CHSEL rise to ADCESOC
                                                                        // rise delay program
#define ASYSCTL_REFBUFCONFIGCDE_ADCC_TM_ENZ_DUTY_CYCLE    0x8000U       // Disable Pulse Stretch
                                                                        // testmode to have effect in ADC_CLK
#define ASYSCTL_REFBUFCONFIGCDE_DIS_ADCC_SP_SLEWBOOST     0x10000U      // ADC sp slew boost
                                                                        // disbale
#define ASYSCTL_REFBUFCONFIGCDE_ADCDTM_ENZ_DUTY_CYCLE     0x20000U      // Disable Pulse Stretch
                                                                        // testmode to have effect in ADC_CLK
#define ASYSCTL_REFBUFCONFIGCDE_DIS_ADCD_SP_SLEWBOOST     0x40000U      // ADC sp slew boost
                                                                        // disbale
#define ASYSCTL_REFBUFCONFIGCDE_ADCE_TM_ENZ_DUTY_CYCLE    0x80000U      // Disable Pulse Stretch
                                                                        // testmode to have effect in ADC_CLK
#define ASYSCTL_REFBUFCONFIGCDE_DIS_ADCE_SP_SLEWBOOST     0x100000U     // ADC sp slew boost
                                                                        // disbale
#define ASYSCTL_REFBUFCONFIGCDE_SPARE1_S                  21U
#define ASYSCTL_REFBUFCONFIGCDE_SPARE1_M                  0xFFE00000U   // Spare1 bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the INTERNALTESTCTL register
//
//*************************************************************************************************
#define ASYSCTL_INTERNALTESTCTL_TESTSEL_S   0U
#define ASYSCTL_INTERNALTESTCTL_TESTSEL_M   0x3FU         // Test Select
#define ASYSCTL_INTERNALTESTCTL_KEY_S       16U
#define ASYSCTL_INTERNALTESTCTL_KEY_M       0xFFFF0000U   // Key to Enable writes


//*************************************************************************************************
//
// The following are defines for the bit fields in the CONFIGLOCK register
//
//*************************************************************************************************
#define ASYSCTL_CONFIGLOCK_LOCKBIT       0x1U   // Locks analog subsystem config
#define ASYSCTL_CONFIGLOCK_AGPIOFILTER   0x2U   // Locks AGPIOFILTER Register
#define ASYSCTL_CONFIGLOCK_AGPIOCTRL     0x8U   // Locks all AGPIOCTRL Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the TSNSCTL register
//
//*************************************************************************************************
#define ASYSCTL_TSNSCTL_ENABLE   0x1U   // Temperature Sensor Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ANAREFCTL register
//
//*************************************************************************************************
#define ASYSCTL_ANAREFCTL_ANAREFABSEL        0x1U     // Analog Reference ADC-A/B Select
#define ASYSCTL_ANAREFCTL_ANAREFCDESEL       0x2U     // Analog Reference ADC-C/D/E Select
#define ASYSCTL_ANAREFCTL_ANAREFAB_2P5SEL    0x100U   // Analog Reference Select
#define ASYSCTL_ANAREFCTL_ANAREFCDE_2P5SEL   0x200U   // Analog Reference B Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the VREGCTL register
//
//*************************************************************************************************
#define ASYSCTL_VREGCTL_PWRDNVREG   0x1U      // Power down internal voltage regulator
#define ASYSCTL_VREGCTL_ENMASK      0x8000U   // Enable VMON function mask on a TRIM load

//*************************************************************************************************
//
// The following are defines for the bit fields in the VMONCTL register
//
//*************************************************************************************************
#define ASYSCTL_VMONCTL_BORLVMONDIS   0x100U   // Disable BORL(ow) feature on VDDIO

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHPMXSEL register
//
//*************************************************************************************************
#define ASYSCTL_CMPHPMXSEL_CMP1HPMXSEL_S    0U
#define ASYSCTL_CMPHPMXSEL_CMP1HPMXSEL_M    0x7U          // CMP1HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP2HPMXSEL_S    3U
#define ASYSCTL_CMPHPMXSEL_CMP2HPMXSEL_M    0x38U         // CMP2HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP3HPMXSEL_S    6U
#define ASYSCTL_CMPHPMXSEL_CMP3HPMXSEL_M    0x1C0U        // CMP3HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP4HPMXSEL_S    9U
#define ASYSCTL_CMPHPMXSEL_CMP4HPMXSEL_M    0xE00U        // CMP4HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP5HPMXSEL_S    12U
#define ASYSCTL_CMPHPMXSEL_CMP5HPMXSEL_M    0x7000U       // CMP5HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP6HPMXSEL_S    15U
#define ASYSCTL_CMPHPMXSEL_CMP6HPMXSEL_M    0x38000U      // CMP6HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP7HPMXSEL_S    18U
#define ASYSCTL_CMPHPMXSEL_CMP7HPMXSEL_M    0x1C0000U     // CMP7HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP8HPMXSEL_S    21U
#define ASYSCTL_CMPHPMXSEL_CMP8HPMXSEL_M    0xE00000U     // CMP8HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP9HPMXSEL_S    24U
#define ASYSCTL_CMPHPMXSEL_CMP9HPMXSEL_M    0x7000000U    // CMP9HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL_CMP10HPMXSEL_S   27U
#define ASYSCTL_CMPHPMXSEL_CMP10HPMXSEL_M   0x38000000U   // CMP10HPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHPMXSEL1 register
//
//*************************************************************************************************
#define ASYSCTL_CMPHPMXSEL1_CMP11HPMXSEL_S   0U
#define ASYSCTL_CMPHPMXSEL1_CMP11HPMXSEL_M   0x7U    // CMP11HPMXSEL bits
#define ASYSCTL_CMPHPMXSEL1_CMP12HPMXSEL_S   3U
#define ASYSCTL_CMPHPMXSEL1_CMP12HPMXSEL_M   0x38U   // CMP12HPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLPMXSEL register
//
//*************************************************************************************************
#define ASYSCTL_CMPLPMXSEL_CMP1LPMXSEL_S    0U
#define ASYSCTL_CMPLPMXSEL_CMP1LPMXSEL_M    0x7U          // CMP1LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP2LPMXSEL_S    3U
#define ASYSCTL_CMPLPMXSEL_CMP2LPMXSEL_M    0x38U         // CMP2LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP3LPMXSEL_S    6U
#define ASYSCTL_CMPLPMXSEL_CMP3LPMXSEL_M    0x1C0U        // CMP3LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP4LPMXSEL_S    9U
#define ASYSCTL_CMPLPMXSEL_CMP4LPMXSEL_M    0xE00U        // CMP4LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP5LPMXSEL_S    12U
#define ASYSCTL_CMPLPMXSEL_CMP5LPMXSEL_M    0x7000U       // CMP5LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP6LPMXSEL_S    15U
#define ASYSCTL_CMPLPMXSEL_CMP6LPMXSEL_M    0x38000U      // CMP6LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP7LPMXSEL_S    18U
#define ASYSCTL_CMPLPMXSEL_CMP7LPMXSEL_M    0x1C0000U     // CMP7LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP8LPMXSEL_S    21U
#define ASYSCTL_CMPLPMXSEL_CMP8LPMXSEL_M    0xE00000U     // CMP8LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP9LPMXSEL_S    24U
#define ASYSCTL_CMPLPMXSEL_CMP9LPMXSEL_M    0x7000000U    // CMP9LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL_CMP10LPMXSEL_S   27U
#define ASYSCTL_CMPLPMXSEL_CMP10LPMXSEL_M   0x38000000U   // CMP10LPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLPMXSEL1 register
//
//*************************************************************************************************
#define ASYSCTL_CMPLPMXSEL1_CMP11LPMXSEL_S   0U
#define ASYSCTL_CMPLPMXSEL1_CMP11LPMXSEL_M   0x7U    // CMP11LPMXSEL bits
#define ASYSCTL_CMPLPMXSEL1_CMP12LPMXSEL_S   3U
#define ASYSCTL_CMPLPMXSEL1_CMP12LPMXSEL_M   0x38U   // CMP12LPMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPHNMXSEL register
//
//*************************************************************************************************
#define ASYSCTL_CMPHNMXSEL_CMP1HNMXSEL    0x1U     // CMP1HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP2HNMXSEL    0x2U     // CMP2HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP3HNMXSEL    0x4U     // CMP3HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP4HNMXSEL    0x8U     // CMP4HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP5HNMXSEL    0x10U    // CMP5HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP6HNMXSEL    0x20U    // CMP6HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP7HNMXSEL    0x40U    // CMP7HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP8HNMXSEL    0x80U    // CMP8HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP9HNMXSEL    0x100U   // CMP9HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP10HNMXSEL   0x200U   // CMP10HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP11HNMXSEL   0x400U   // CMP11HNMXSEL bits
#define ASYSCTL_CMPHNMXSEL_CMP12HNMXSEL   0x800U   // CMP12HNMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPLNMXSEL register
//
//*************************************************************************************************
#define ASYSCTL_CMPLNMXSEL_CMP1LNMXSEL    0x1U     // CMP1LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP2LNMXSEL    0x2U     // CMP2LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP3LNMXSEL    0x4U     // CMP3LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP4LNMXSEL    0x8U     // CMP4LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP5LNMXSEL    0x10U    // CMP5LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP6LNMXSEL    0x20U    // CMP6LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP7LNMXSEL    0x40U    // CMP7LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP8LNMXSEL    0x80U    // CMP8LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP9LNMXSEL    0x100U   // CMP9LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP10LNMXSEL   0x200U   // CMP10LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP11LNMXSEL   0x400U   // CMP11LNMXSEL bits
#define ASYSCTL_CMPLNMXSEL_CMP12LNMXSEL   0x800U   // CMP12LNMXSEL bits

//*************************************************************************************************
//
// The following are defines for the bit fields in the LOCK register
//
//*************************************************************************************************
#define ASYSCTL_LOCK_TSNSCTL       0x1U      // TSNSCTL Register lock bit
#define ASYSCTL_LOCK_ANAREFCTL     0x2U      // ANAREFCTL Register lock bit
#define ASYSCTL_LOCK_VMONCTL       0x4U      // VMONCTL Register lock bit
#define ASYSCTL_LOCK_CMPHPMXSEL    0x20U     // CMPHPMXSEL Register lock bit
#define ASYSCTL_LOCK_CMPLPMXSEL    0x40U     // CMPLPMXSEL Register lock bit
#define ASYSCTL_LOCK_CMPHNMXSEL    0x80U     // CMPHNMXSEL Register lock bit
#define ASYSCTL_LOCK_CMPLNMXSEL    0x100U    // CMPLNMXSEL Register lock bit
#define ASYSCTL_LOCK_VREGCTL       0x200U    // VREGCTL Register lock bit
#define ASYSCTL_LOCK_CMPHPMXSEL1   0x800U    // CMPHPMXSEL1 Register lock bit
#define ASYSCTL_LOCK_CMPLPMXSEL1   0x1000U   // CMPLPMXSEL1 Register lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the IODRVSEL register
//
//*************************************************************************************************
#define ASYSCTL_IODRVSEL_GPIO10   0x1U    // Drive select for GPIO10
#define ASYSCTL_IODRVSEL_GPIO15   0x2U    // Drive select for GPIO15
#define ASYSCTL_IODRVSEL_GPIO18   0x4U    // Drive select for GPIO18
#define ASYSCTL_IODRVSEL_GPIO22   0x8U    // Drive select for GPIO22
#define ASYSCTL_IODRVSEL_GPIO23   0x10U   // Drive select for GPIO23
#define ASYSCTL_IODRVSEL_GPIO29   0x20U   // Drive select for GPIO29

//*************************************************************************************************
//
// The following are defines for the bit fields in the IOMODESEL register
//
//*************************************************************************************************
#define ASYSCTL_IOMODESEL_GPIO10   0x1U    // Mode select for GPIO10
#define ASYSCTL_IOMODESEL_GPIO15   0x2U    // Mode select for GPIO15
#define ASYSCTL_IOMODESEL_GPIO18   0x4U    // Mode select for GPIO18
#define ASYSCTL_IOMODESEL_GPIO22   0x8U    // Mode select for GPIO22
#define ASYSCTL_IOMODESEL_GPIO23   0x10U   // Mode select for GPIO23
#define ASYSCTL_IOMODESEL_GPIO29   0x20U   // Mode select for GPIO29

//*************************************************************************************************
//
// The following are defines for the bit fields in the AGPIOFILTER register
//
//*************************************************************************************************
#define ASYSCTL_AGPIOFILTER_FILTER_S   0U
#define ASYSCTL_AGPIOFILTER_FILTER_M   0x3U   // AGPIOFILTER Control for filter ALL AGPIO pins

//*************************************************************************************************
//
// The following are defines for the bit fields in the AGPIOCTRLH register
//
//*************************************************************************************************
#define ASYSCTL_AGPIOCTRLH_GPIO224   0x1U         // AGPIOCTRL for GPIO224
#define ASYSCTL_AGPIOCTRLH_GPIO225   0x2U         // AGPIOCTRL for GPIO225
#define ASYSCTL_AGPIOCTRLH_GPIO226   0x4U         // AGPIOCTRL for GPIO226
#define ASYSCTL_AGPIOCTRLH_GPIO227   0x8U         // AGPIOCTRL for GPIO227
#define ASYSCTL_AGPIOCTRLH_GPIO228   0x10U        // AGPIOCTRL for GPIO228
#define ASYSCTL_AGPIOCTRLH_GPIO229   0x20U        // AGPIOCTRL for GPIO229
#define ASYSCTL_AGPIOCTRLH_GPIO230   0x40U        // AGPIOCTRL for GPIO230
#define ASYSCTL_AGPIOCTRLH_GPIO231   0x80U        // AGPIOCTRL for GPIO231
#define ASYSCTL_AGPIOCTRLH_GPIO232   0x100U       // AGPIOCTRL for GPIO232
#define ASYSCTL_AGPIOCTRLH_GPIO233   0x200U       // AGPIOCTRL for GPIO233
#define ASYSCTL_AGPIOCTRLH_GPIO234   0x400U       // AGPIOCTRL for GPIO234
#define ASYSCTL_AGPIOCTRLH_GPIO235   0x800U       // AGPIOCTRL for GPIO235
#define ASYSCTL_AGPIOCTRLH_GPIO236   0x1000U      // AGPIOCTRL for GPIO236
#define ASYSCTL_AGPIOCTRLH_GPIO237   0x2000U      // AGPIOCTRL for GPIO237
#define ASYSCTL_AGPIOCTRLH_GPIO238   0x4000U      // AGPIOCTRL for GPIO238
#define ASYSCTL_AGPIOCTRLH_GPIO239   0x8000U      // AGPIOCTRL for GPIO239
#define ASYSCTL_AGPIOCTRLH_GPIO240   0x10000U     // AGPIOCTRL for GPIO240
#define ASYSCTL_AGPIOCTRLH_GPIO241   0x20000U     // AGPIOCTRL for GPIO241
#define ASYSCTL_AGPIOCTRLH_GPIO242   0x40000U     // AGPIOCTRL for GPIO242
#define ASYSCTL_AGPIOCTRLH_GPIO243   0x80000U     // AGPIOCTRL for GPIO243
#define ASYSCTL_AGPIOCTRLH_GPIO244   0x100000U    // AGPIOCTRL for GPIO244
#define ASYSCTL_AGPIOCTRLH_GPIO245   0x200000U    // AGPIOCTRL for GPIO245
#define ASYSCTL_AGPIOCTRLH_GPIO246   0x400000U    // AGPIOCTRL for GPIO246
#define ASYSCTL_AGPIOCTRLH_GPIO247   0x800000U    // AGPIOCTRL for GPIO247
#define ASYSCTL_AGPIOCTRLH_GPIO248   0x1000000U   // AGPIOCTRL for GPIO248
#define ASYSCTL_AGPIOCTRLH_GPIO249   0x2000000U   // AGPIOCTRL for GPIO249

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST register
//
//*************************************************************************************************
#define ASYSCTL_PARITY_TEST_TESTEN_S   0U
#define ASYSCTL_PARITY_TEST_TESTEN_M   0xFU   // Parity test enable configuration


//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCFRCGB register
//
//*************************************************************************************************
#define ASYSCTL_ADCSOCFRCGB_SOC0    0x1U          // Generate synchronous SW trigger for SOC0
#define ASYSCTL_ADCSOCFRCGB_SOC1    0x2U          // Generate synchronous SW trigger for SOC1
#define ASYSCTL_ADCSOCFRCGB_SOC2    0x4U          // Generate synchronous SW trigger for SOC2
#define ASYSCTL_ADCSOCFRCGB_SOC3    0x8U          // Generate synchronous SW trigger for SOC3
#define ASYSCTL_ADCSOCFRCGB_SOC4    0x10U         // Generate synchronous SW trigger for SOC4
#define ASYSCTL_ADCSOCFRCGB_SOC5    0x20U         // Generate synchronous SW trigger for SOC5
#define ASYSCTL_ADCSOCFRCGB_SOC6    0x40U         // Generate synchronous SW trigger for SOC6
#define ASYSCTL_ADCSOCFRCGB_SOC7    0x80U         // Generate synchronous SW trigger for SOC7
#define ASYSCTL_ADCSOCFRCGB_SOC8    0x100U        // Generate synchronous SW trigger for SOC8
#define ASYSCTL_ADCSOCFRCGB_SOC9    0x200U        // Generate synchronous SW trigger for SOC9
#define ASYSCTL_ADCSOCFRCGB_SOC10   0x400U        // Generate synchronous SW trigger for SOC10
#define ASYSCTL_ADCSOCFRCGB_SOC11   0x800U        // Generate synchronous SW trigger for SOC11
#define ASYSCTL_ADCSOCFRCGB_SOC12   0x1000U       // Generate synchronous SW trigger for SOC12
#define ASYSCTL_ADCSOCFRCGB_SOC13   0x2000U       // Generate synchronous SW trigger for SOC13
#define ASYSCTL_ADCSOCFRCGB_SOC14   0x4000U       // Generate synchronous SW trigger for SOC14
#define ASYSCTL_ADCSOCFRCGB_SOC15   0x8000U       // Generate synchronous SW trigger for SOC15
#define ASYSCTL_ADCSOCFRCGB_SOC16   0x10000U      // Generate synchronous SW trigger for SOC16
#define ASYSCTL_ADCSOCFRCGB_SOC17   0x20000U      // Generate synchronous SW trigger for SOC17
#define ASYSCTL_ADCSOCFRCGB_SOC18   0x40000U      // Generate synchronous SW trigger for SOC18
#define ASYSCTL_ADCSOCFRCGB_SOC19   0x80000U      // Generate synchronous SW trigger for SOC19
#define ASYSCTL_ADCSOCFRCGB_SOC20   0x100000U     // Generate synchronous SW trigger for SOC20
#define ASYSCTL_ADCSOCFRCGB_SOC21   0x200000U     // Generate synchronous SW trigger for SOC21
#define ASYSCTL_ADCSOCFRCGB_SOC22   0x400000U     // Generate synchronous SW trigger for SOC22
#define ASYSCTL_ADCSOCFRCGB_SOC23   0x800000U     // Generate synchronous SW trigger for SOC23
#define ASYSCTL_ADCSOCFRCGB_SOC24   0x1000000U    // Generate synchronous SW trigger for SOC24
#define ASYSCTL_ADCSOCFRCGB_SOC25   0x2000000U    // Generate synchronous SW trigger for SOC25
#define ASYSCTL_ADCSOCFRCGB_SOC26   0x4000000U    // Generate synchronous SW trigger for SOC26
#define ASYSCTL_ADCSOCFRCGB_SOC27   0x8000000U    // Generate synchronous SW trigger for SOC27
#define ASYSCTL_ADCSOCFRCGB_SOC28   0x10000000U   // Generate synchronous SW trigger for SOC28
#define ASYSCTL_ADCSOCFRCGB_SOC29   0x20000000U   // Generate synchronous SW trigger for SOC29
#define ASYSCTL_ADCSOCFRCGB_SOC30   0x40000000U   // Generate synchronous SW trigger for SOC30
#define ASYSCTL_ADCSOCFRCGB_SOC31   0x80000000U   // Generate synchronous SW trigger for SOC31

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCFRCGBSEL register
//
//*************************************************************************************************
#define ASYSCTL_ADCSOCFRCGBSEL_ADCA   0x1U    // Generate synchronous SW trigger for ADCA
#define ASYSCTL_ADCSOCFRCGBSEL_ADCB   0x2U    // Generate synchronous SW trigger for ADCB
#define ASYSCTL_ADCSOCFRCGBSEL_ADCC   0x4U    // Generate synchronous SW trigger for ADCC
#define ASYSCTL_ADCSOCFRCGBSEL_ADCD   0x8U    // Generate synchronous SW trigger for ADCD
#define ASYSCTL_ADCSOCFRCGBSEL_ADCE   0x10U   // Generate synchronous SW trigger for ADCE

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST_ALT1 register
//
//*************************************************************************************************
#define ASYSCTL_PARITY_TEST_ALT1_TESTEN_S   0U
#define ASYSCTL_PARITY_TEST_ALT1_TESTEN_M   0xFU   // Parity test enable configuration



#endif
