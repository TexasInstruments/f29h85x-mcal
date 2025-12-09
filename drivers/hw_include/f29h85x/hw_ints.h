//###########################################################################
//
// FILE:   hw_ints.h
//
// TITLE:  Definitions of interrupt numbers for use with interrupt.c
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

#ifndef HW_INTS_H
#define HW_INTS_H

#define INT_C29CPU_FLOATINGPOINT_OVERFLOW_INT   0U       // C29 CPU Floating Point Overflow Interrupt
#define INT_C29CPU_FLOATINGPOINT_UNDERFLOW_INT  1U       // C29 CPU Floating Point Underflow Interrupt
#define INT_C29CPU_FIXEDPOINT_OVERFLOW_INT      2U       // C29 CPU Fixed Point Overflow Interrupt
#define INT_WD                                  3U       // Watchdog interrupt
#define INT_ERAD                                4U       // ERAD Interrupt
#define INT_DLT                                 5U       // DLT Interrupt
#define INT_TIMER0                              6U       // Timer 0 Interrupt
#define INT_TIMER1                              7U       // Timer 1 Interrupt
#define INT_TIMER2                              8U       // Timer 2 Interrupt
#define INT_DEBUGSS                             9U       // Debug Interrupt
#define INT_ESM_LOWPRI                          10U      // ESM CPUx Low Priority Interrupt
#define INT_ESM_PARITYERR                       11U      // ESM Parity Error Interrupt
#define INT_IPC_1_1                             12U      //
#define INT_IPC_1_2                             13U      //
#define INT_IPC_1_3                             14U      //
#define INT_IPC_1_4                             15U      //
#define INT_IPC_2_1                             16U      //
#define INT_IPC_2_2                             17U      //
#define INT_IPC_2_3                             18U      //
#define INT_IPC_2_4                             19U      //
#define INT_IPC_HSM_RACK                        20U      //
#define INT_IPC_HSM_WDONE                       21U      //
#define INT_DTHE_TRNG                           26U      // TRNG Interrupt
#define INT_DTHE_PKAE                           27U      // PKAE Interrupt
#define INT_DTHE_SHA_S                          28U      // SHA_S Interrupt
#define INT_DTHE_SHA_P                          29U      // SHA_P Interrupt
#define INT_DTHE_AES_S                          30U      // AES_S Interrupt
#define INT_DTHE_AES_P                          31U      // AES_P Interrupt
#define INT_DTHE_SM3                            32U      // SM3 Interrupt
#define INT_DTHE_SM4                            33U      // SM4 Interrupt
#define INT_FLC1                                34U      // Flash Controller Interrupt 1
#define INT_FLC2                                35U      // Flash Controller Interrupt 2
#define INT_EPWM1                               36U      // EPWM1 Interrupt
#define INT_EPWM1_TZ                            37U      // EPWM1 Trip Zone Interrupt
#define INT_EPWM2                               38U      // EPWM2 Interrupt
#define INT_EPWM2_TZ                            39U      // EPWM2 Trip Zone Interrupt
#define INT_EPWM3                               40U      // EPWM3 Interrupt
#define INT_EPWM3_TZ                            41U      // EPWM3 Trip Zone Interrupt
#define INT_EPWM4                               42U      // EPWM4 Interrupt
#define INT_EPWM4_TZ                            43U      // EPWM4 Trip Zone Interrupt
#define INT_EPWM5                               44U      // EPWM5 Interrupt
#define INT_EPWM5_TZ                            45U      // EPWM5 Trip Zone Interrupt
#define INT_EPWM6                               46U      // EPWM6 Interrupt
#define INT_EPWM6_TZ                            47U      // EPWM6 Trip Zone Interrupt
#define INT_EPWM7                               48U      // EPWM7 Interrupt
#define INT_EPWM7_TZ                            49U      // EPWM7 Trip Zone Interrupt
#define INT_EPWM8                               50U      // EPWM8 Interrupt
#define INT_EPWM8_TZ                            51U      // EPWM8 Trip Zone Interrupt
#define INT_EPWM9                               52U      // EPWM9 Interrupt
#define INT_EPWM9_TZ                            53U      // EPWM9 Trip Zone Interrupt
#define INT_EPWM10                              54U      // EPWM10 Interrupt
#define INT_EPWM10_TZ                           55U      // EPWM10 Trip Zone Interrupt
#define INT_EPWM11                              56U      // EPWM11 Interrupt
#define INT_EPWM11_TZ                           57U      // EPWM11 Trip Zone Interrupt
#define INT_EPWM12                              58U      // EPWM12 Interrupt
#define INT_EPWM12_TZ                           59U      // EPWM12 Trip Zone Interrupt
#define INT_EPWM13                              60U      // EPWM13 Interrupt
#define INT_EPWM13_TZ                           61U      // EPWM13 Trip Zone Interrupt
#define INT_EPWM14                              62U      // EPWM14 Interrupt
#define INT_EPWM14_TZ                           63U      // EPWM14 Trip Zone Interrupt
#define INT_EPWM15                              64U      // EPWM15 Interrupt
#define INT_EPWM15_TZ                           65U      // EPWM15 Trip Zone Interrupt
#define INT_EPWM16                              66U      // EPWM16 Interrupt
#define INT_EPWM16_TZ                           67U      // EPWM16 Trip Zone Interrupt
#define INT_EPWM17                              68U      // EPWM17 Interrupt
#define INT_EPWM17_TZ                           69U      // EPWM17 Trip Zone Interrupt
#define INT_EPWM18                              70U      // EPWM18 Interrupt
#define INT_EPWM18_TZ                           71U      // EPWM18 Trip Zone Interrupt
#define INT_EQEP1                               72U      // EQEP1 Interrupt
#define INT_EQEP2                               73U      // EQEP2 Interrupt
#define INT_EQEP3                               74U      // EQEP3 Interrupt
#define INT_EQEP4                               75U      // EQEP4 Interrupt
#define INT_EQEP5                               76U      // EQEP5 Interrupt
#define INT_EQEP6                               77U      // EQEP6 Interrupt
#define INT_ECAP1                               78U      // ECAP1 Interrupt
#define INT_ECAP2                               79U      // ECAP2 Interrupt
#define INT_ECAP3                               80U      // ECAP3 Interrupt
#define INT_ECAP4                               81U      // ECAP4 Interrupt
#define INT_ECAP5                               82U      // ECAP5 Interrupt
#define INT_HRCAP5                              83U      // HRCAP5 Interrupt
#define INT_ECAP6                               84U      // ECAP6 Interrupt
#define INT_HRCAP6                              85U      // HRCAP6 Interrupt
#define INT_ADCA_EVT                            86U      // ADCA Event Interrupt
#define INT_ADCA1                               87U      // ADCA Interrupt 1
#define INT_ADCA2                               88U      // ADCA Interrupt 2
#define INT_ADCA3                               89U      // ADCA Interrupt 3
#define INT_ADCA4                               90U      // ADCA Interrupt 4
#define INT_ADCB_EVT                            91U      // ADCB Event Interrupt
#define INT_ADCB1                               92U      // ADCB Interrupt 1
#define INT_ADCB2                               93U      // ADCB Interrupt 2
#define INT_ADCB3                               94U      // ADCB Interrupt 3
#define INT_ADCB4                               95U      // ADCB Interrupt 4
#define INT_ADCC_EVT                            96U      // ADCC Event Interrupt
#define INT_ADCC1                               97U      // ADCC Interrupt 1
#define INT_ADCC2                               98U      // ADCC Interrupt 2
#define INT_ADCC3                               99U      // ADCC Interrupt 3
#define INT_ADCC4                               100U     // ADCC Interrupt 4
#define INT_ADCD_EVT                            101U     // ADCD Event Interrupt
#define INT_ADCD1                               102U     // ADCD Interrupt 1
#define INT_ADCD2                               103U     // ADCD Interrupt 2
#define INT_ADCD3                               104U     // ADCD Interrupt 3
#define INT_ADCD4                               105U     // ADCD Interrupt 4
#define INT_ADCE_EVT                            106U     // ADCE Event Interrupt
#define INT_ADCE1                               107U     // ADCE Interrupt 1
#define INT_ADCE2                               108U     // ADCE Interrupt 2
#define INT_ADCE3                               109U     // ADCE Interrupt 3
#define INT_ADCE4                               110U     // ADCE Interrupt 4
#define INT_SD1_ERR                             112U     // SDFM 1 Error Interrupt
#define INT_SD1_FLT1_DR                         113U     // SDFM 1 Filter 1 Interrupt
#define INT_SD1_FLT2_DR                         114U     // SDFM 1 Filter 2 Interrupt
#define INT_SD1_FLT3_DR                         115U     // SDFM 1 Filter 3 Interrupt
#define INT_SD1_FLT4_DR                         116U     // SDFM 1 Filter 4 Interrupt
#define INT_SD2_ERR                             117U     // SDFM 1 Error Interrupt
#define INT_SD2_FLT1_DR                         118U     // SDFM 1 Filter 1 Interrupt
#define INT_SD2_FLT2_DR                         119U     // SDFM 1 Filter 2 Interrupt
#define INT_SD2_FLT3_DR                         120U     // SDFM 1 Filter 3 Interrupt
#define INT_SD2_FLT4_DR                         121U     // SDFM 1 Filter 4 Interrupt
#define INT_SD3_ERR                             122U     // SDFM 1 Error Interrupt
#define INT_SD3_FLT1_DR                         123U     // SDFM 1 Filter 1 Interrupt
#define INT_SD3_FLT2_DR                         124U     // SDFM 1 Filter 2 Interrupt
#define INT_SD3_FLT3_DR                         125U     // SDFM 1 Filter 3 Interrupt
#define INT_SD3_FLT4_DR                         126U     // SDFM 1 Filter 4 Interrupt
#define INT_SD4_ERR                             127U     // SDFM 1 Error Interrupt
#define INT_SD4_FLT1_DR                         128U     // SDFM 1 Filter 1 Interrupt
#define INT_SD4_FLT2_DR                         129U     // SDFM 1 Filter 2 Interrupt
#define INT_SD4_FLT3_DR                         130U     // SDFM 1 Filter 3 Interrupt
#define INT_SD4_FLT4_DR                         131U     // SDFM 1 Filter 4 Interrupt
#define INT_CLB1                                132U     // CLB1 Interrupt
#define INT_CLB2                                133U     // CLB2 Interrupt
#define INT_CLB3                                134U     // CLB3 Interrupt
#define INT_CLB4                                135U     // CLB4 Interrupt
#define INT_CLB5                                136U     // CLB5 Interrupt
#define INT_CLB6                                137U     // CLB6 Interrupt
#define INT_UARTA                               138U     // UARTA Interrupt
#define INT_UARTB                               139U     // UARTB Interrupt
#define INT_UARTC                               140U     // UARTC Interrupt
#define INT_UARTD                               141U     // UARTD Interrupt
#define INT_UARTE                               142U     // UARTE Interrupt
#define INT_UARTF                               143U     // UARTF Interrupt
#define INT_LINA_0                              144U     // LINA Interrupt 0
#define INT_LINA_1                              145U     // LINA Interrupt 1
#define INT_LINB_0                              146U     // LINB Interrupt 0
#define INT_LINB_1                              147U     // LINB Interrupt 1
#define INT_PMBUSA                              148U     // PMBUSA Interrupt
#define INT_I2CA                                149U     // I2CA Interrupt 1
#define INT_I2CA_FIFO                           150U     // I2CA Interrupt 2
#define INT_I2CB                                151U     // I2CB Interrupt 1
#define INT_I2CB_FIFO                           152U     // I2CB Interrupt 2
#define INT_SPIA_TX                             153U     // SPIA TX Interrupt
#define INT_SPIA_RX                             154U     // SPIA RX Interrupt
#define INT_SPIB_TX                             155U     // SPIB TX Interrupt
#define INT_SPIB_RX                             156U     // SPIB RX Interrupt
#define INT_SPIC_TX                             157U     // SPIC TX Interrupt
#define INT_SPIC_RX                             158U     // SPIC RX Interrupt
#define INT_SPID_TX                             159U     // SPID TX Interrupt
#define INT_SPID_RX                             160U     // SPID RX Interrupt
#define INT_SPIE_TX                             161U     // SPIE TX Interrupt
#define INT_SPIE_RX                             162U     // SPIE RX Interrupt
#define INT_FSITXA1                             163U     // FSITXA Interrupt 1
#define INT_FSITXA2                             164U     // FSITXA Interrupt 2
#define INT_FSITXB1                             165U     // FSITXB Interrupt 1
#define INT_FSITXB2                             166U     // FSITXB Interrupt 2
#define INT_FSITXC1                             167U     // FSITXC Interrupt 1
#define INT_FSITXC2                             168U     // FSITXC Interrupt 2
#define INT_FSITXD1                             169U     // FSITXD Interrupt 1
#define INT_FSITXD2                             170U     // FSITXD Interrupt 2
#define INT_FSIRXA1                             171U     // FSIRXA Interrupt 1
#define INT_FSIRXA2                             172U     // FSIRXA Interrupt 2
#define INT_FSIRXB1                             173U     // FSIRXB Interrupt 1
#define INT_FSIRXB2                             174U     // FSIRXB Interrupt 2
#define INT_FSIRXC1                             175U     // FSIRXC Interrupt 1
#define INT_FSIRXC2                             176U     // FSIRXC Interrupt 2
#define INT_FSIRXD1                             177U     // FSIRXD Interrupt 1
#define INT_FSIRXD2                             178U     // FSIRXD Interrupt 2
#define INT_SENT1                               179U     // SENT1 Interrupt
#define INT_SENT2                               180U     // SENT2 Interrupt
#define INT_SENT3                               181U     // SENT3 Interrupt
#define INT_SENT4                               182U     // SENT4 Interrupt
#define INT_SENT5                               183U     // SENT5 Interrupt
#define INT_SENT6                               184U     // SENT6 Interrupt
#define INT_MCANA_WAKE                          186U     // MCANA Wakeup Interrupt
#define INT_MCANA_1                             187U     // MCANA Interrupt 1
#define INT_MCANA_0                             188U     // MCANA Interrupt 0
#define INT_MCANB_WAKE                          190U     // MCANB Wakeup Interrupt
#define INT_MCANB_1                             191U     // MCANB Interrupt 1
#define INT_MCANB_0                             192U     // MCANB Interrupt 0
#define INT_MCANC_WAKE                          194U     // MCANC Wakeup Interrupt
#define INT_MCANC_1                             195U     // MCANC Interrupt 1
#define INT_MCANC_0                             196U     // MCANC Interrupt 0
#define INT_MCAND_WAKE                          198U     // MCAND Wakeup Interrupt
#define INT_MCAND_1                             199U     // MCAND Interrupt 1
#define INT_MCAND_0                             200U     // MCAND Interrupt 0
#define INT_MCANE_WAKE                          202U     // MCANE Wakeup Interrupt
#define INT_MCANE_1                             203U     // MCANE Interrupt 1
#define INT_MCANE_0                             204U     // MCANE Interrupt 0
#define INT_MCANF_WAKE                          206U     // MCANF Wakeup Interrupt
#define INT_MCANF_1                             207U     // MCANF Interrupt 1
#define INT_MCANF_0                             208U     // MCANF Interrupt 0
#define INT_ECAT                                209U     // Ethercat Main Interrupt
#define INT_ECATSYNC0                           210U     // Ethercat SYNC0 Interrupt
#define INT_ECATSYNC1                           211U     // Ethercat SYNC1 Interrupt
#define INT_ECATRST                             212U     // Ethercat Reset Interrupt
#define INT_RTDMA1CH1                           213U     // RTDMA1 Channel 1 Interrupt
#define INT_RTDMA1CH2                           214U     // RTDMA1 Channel 2 Interrupt
#define INT_RTDMA1CH3                           215U     // RTDMA1 Channel 3 Interrupt
#define INT_RTDMA1CH4                           216U     // RTDMA1 Channel 4 Interrupt
#define INT_RTDMA1CH5                           217U     // RTDMA1 Channel 5 Interrupt
#define INT_RTDMA1CH6                           218U     // RTDMA1 Channel 6 Interrupt
#define INT_RTDMA1CH7                           219U     // RTDMA1 Channel 7 Interrupt
#define INT_RTDMA1CH8                           220U     // RTDMA1 Channel 8 Interrupt
#define INT_RTDMA1CH9                           221U     // RTDMA1 Channel 9 Interrupt
#define INT_RTDMA1CH10                          222U     // RTDMA1 Channel 10 Interrupt
#define INT_RTDMA2CH1                           223U     // RTDMA2 Channel 1 Interrupt
#define INT_RTDMA2CH2                           224U     // RTDMA2 Channel 2 Interrupt
#define INT_RTDMA2CH3                           225U     // RTDMA2 Channel 3 Interrupt
#define INT_RTDMA2CH4                           226U     // RTDMA2 Channel 4 Interrupt
#define INT_RTDMA2CH5                           227U     // RTDMA2 Channel 5 Interrupt
#define INT_RTDMA2CH6                           228U     // RTDMA2 Channel 6 Interrupt
#define INT_RTDMA2CH7                           229U     // RTDMA2 Channel 7 Interrupt
#define INT_RTDMA2CH8                           230U     // RTDMA2 Channel 8 Interrupt
#define INT_RTDMA2CH9                           231U     // RTDMA2 Channel 9 Interrupt
#define INT_RTDMA2CH10                          232U     // RTDMA2 Channel 10 Interrupt
#define INT_WADI1                               233U     // WADI1 Interrupt
#define INT_WADI2                               234U     // WADI2 Interrupt
#define INT_XINT1                               235U     // XINT1 Interrupt
#define INT_XINT2                               236U     // XINT2 Interrupt
#define INT_XINT3                               237U     // XINT3 Interrupt
#define INT_XINT4                               238U     // XINT4 Interrupt
#define INT_XINT5                               239U     // XINT5 Interrupt
#define INT_DCC1                                240U     // DCC1 Interrupt
#define INT_DCC2                                241U     // DCC2 Interrupt
#define INT_DCC3                                242U     // DCC3 Interrupt
#define INT_LPM_WAKE                            243U     // LPM Wakeup Interrupt
#define INT_SW12                                244U     // Software Interrupt 12
#define INT_SW11                                245U     // Software Interrupt 11
#define INT_SW10                                246U     // Software Interrupt 10
#define INT_SW9                                 247U     // Software Interrupt 9
#define INT_SW8                                 248U     // Software Interrupt 8
#define INT_SW7                                 249U     // Software Interrupt 7
#define INT_SW6                                 250U     // Software Interrupt 6
#define INT_SW5                                 251U     // Software Interrupt 5
#define INT_SW4                                 252U     // Software Interrupt 4
#define INT_SW3                                 253U     // Software Interrupt 3
#define INT_SW2                                 254U     // Software Interrupt 2
#define INT_SW1                                 255U     // Software Interrupt 1


#define INT_NMI                                 1024U

#endif