//###########################################################################
//
// FILE:    hw_memmap.h
//
// TITLE:   Macros defining the memory map of the C28x.
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

#ifndef HW_MEMMAP_H
#define HW_MEMMAP_H

//*****************************************************************************
//
// The following are defines for the base address of the memories and
// peripherals.
//
//*****************************************************************************
#define CPU1_ROM_BASE                        0x00000000U
#define CPU2_ROM_BASE                        0x00000000U
#define CPU3_ROM_BASE                        0x00000000U
#define LDA7_RAM_BASE                        0x200E0000U
#define LDA6_RAM_BASE                        0x200E4000U
#define LDA5_RAM_BASE                        0x200E8000U
#define LDA4_RAM_BASE                        0x200EC000U
#define LDA3_RAM_BASE                        0x200F0000U
#define LDA2_RAM_BASE                        0x200F4000U
#define LDA1_RAM_BASE                        0x200F8000U
#define LDA0_RAM_BASE                        0x200FC000U
#define LPA0_RAM_BASE                        0x20100000U
#define LPA1_RAM_BASE                        0x20108000U
#define CPA0_RAM_BASE                        0x20110000U
#define CPA1_RAM_BASE                        0x20118000U
#define CDA0_RAM_BASE                        0x20120000U
#define CDA1_RAM_BASE                        0x20124000U
#define CDA2_RAM_BASE                        0x20128000U
#define CDA3_RAM_BASE                        0x2012C000U
#define CDA4_RAM_BASE                        0x20130000U
#define CDA5_RAM_BASE                        0x20134000U
#define CDA6_RAM_BASE                        0x20138000U
#define CDA7_RAM_BASE                        0x2013C000U
#define CDA8_RAM_BASE                        0x20140000U
#define CDA9_RAM_BASE                        0x20144000U
#define CDA10_RAM_BASE                       0x20148000U
#define CDA11_RAM_BASE                       0x2014C000U
#define C29CPURTINTSTACK_BASE                0x30008000U
#define C29CPUSECCALLSTACK_BASE              0x3000C000U
#define C29CPUSECURE_BASE                    0x3000D000U
#define C29CPUDIAG_BASE                      0x3000E000U
#define C29CPUSELFTEST_BASE                  0x3000F000U
#define CPUDLT_BASE                          0x30010000U
#define C29DEBUGSS_BASE                      0x30018000U
#define PIPE_BASE                            0x30020000U
#define ERAD_BASE                            0x30030000U
#define LCM_CPU_BASE                         0x30032000U
#define SSUGEN_BASE                          0x30080000U
#define SSUCPU1CFG_BASE                      0x30081000U
#define SSUCPU2CFG_BASE                      0x30082000U
#define SSUCPU3CFG_BASE                      0x30083000U
#define SSUCPU1AP_BASE                       0x30087000U
#define SSUCPU2AP_BASE                       0x30088000U
#define SSUCPU3AP_BASE                       0x30089000U
#define FLASHCONTROLLER1_BASE                0x30100000U
#define FLASHCONTROLLER2_BASE                0x30110000U
#define HSMERRORAGGREGATOR_BASE              0x30120000U
#define DEVCFG_BASE                          0x30180000U
#define ANALOGSUBSYS_BASE                    0x30182000U
#define GPIOCTRL_BASE                        0x30190000U
#define IPCCOUNTER_BASE                      0x301B0000U
#define RTDMA1_BASE                          0x301C0000U
#define RTDMA1_DIAG_BASE                     0x301C0800U
#define RTDMA1_SELFTEST_BASE                 0x301C0C00U
#define RTDMA1_MPU_BASE                      0x301C1000U
#define RTDMA2_BASE                          0x301C8000U
#define RTDMA2_DIAG_BASE                     0x301C8800U
#define RTDMA2_SELFTEST_BASE                 0x301C8C00U
#define RTDMA2_MPU_BASE                      0x301C9000U
#define FRI1_BASE                            0x301D0000U
#define MEMSSLCFG_BASE                       0x301D8000U
#define MEMSSCCFG_BASE                       0x301D8400U
#define MEMSSMCFG_BASE                       0x301D8800U
#define MEMSSMISCI_BASE                      0x301D8E00U
#define SYNCBRIDGEMPU_BASE                   0x301E0000U
#define INPUTXBAR_BASE                       0x301E8000U
#define EPWMXBAR_BASE                        0x301E9000U
#define CLBXBAR_BASE                         0x301EA000U
#define OUTPUTXBAR_BASE                      0x301EB000U
#define MDLXBAR_BASE                         0x301EC000U
#define ICLXBAR_BASE                         0x301ED000U
#define LCM_DMA_BASE                         0x301F4000U
#define CPUSYS_BASE                          0x30200000U
#define CPUPERCFG_BASE                       0x30208000U
#define WD_BASE                              0x30208C00U
#define CPUTIMER0_BASE                       0x30218000U
#define CPUTIMER1_BASE                       0x30219000U
#define CPUTIMER2_BASE                       0x3021A000U
#define CPU1IPCSEND_BASE                     0x30220000U
#define CPU2IPCSEND_BASE                     0x30228000U
#define CPU3IPCSEND_BASE                     0x30230000U
#define CPU1IPCRCV_BASE                      0x30240000U
#define CPU2IPCRCV_BASE                      0x30248000U
#define CPU3IPCRCV_BASE                      0x30250000U
#define GPIODATA_BASE                        0x30268000U
#define GPIODATAREAD_BASE                    0x30269000U
#define XINT_BASE                            0x30270000U
#define DTHE_BASE                            0x30280000U
#define CRCS_BASE                            0x30281000U
#define CRCP_BASE                            0x30282000U
#define SHAS_BASE                            0x30284000U
#define SHAP_BASE                            0x30285000U
#define AESS_BASE                            0x30286000U
#define AESP_BASE                            0x30287000U
#define SM4_BASE                             0x30288000U
#define SM3_BASE                             0x30289000U
#define TRNG_BASE                            0x3028A000U
#define PKE_BASE                             0x30290000U
#define ESC_SS_BASE                          0x30388000U
#define ESC_SS_CONFIG_BASE                   0x30388200U
#define ADCARESULT_BASE                      0x303C0000U
#define ADCBRESULT_BASE                      0x303C1000U
#define ADCCRESULT_BASE                      0x303C2000U
#define ADCDRESULT_BASE                      0x303C3000U
#define ADCERESULT_BASE                      0x303C4000U
#define EMIF1_BASE                           0x30800000U

#define RTDMA1CH1_BASE_FRAME(i)              (0x60000000U + ((i) * 0x400000U))
#define RTDMA1CH2_BASE_FRAME(i)              (0x60001000U + ((i) * 0x400000U))
#define RTDMA1CH3_BASE_FRAME(i)              (0x60002000U + ((i) * 0x400000U))
#define RTDMA1CH4_BASE_FRAME(i)              (0x60003000U + ((i) * 0x400000U))
#define RTDMA1CH5_BASE_FRAME(i)              (0x60004000U + ((i) * 0x400000U))
#define RTDMA1CH6_BASE_FRAME(i)              (0x60005000U + ((i) * 0x400000U))
#define RTDMA1CH7_BASE_FRAME(i)              (0x60006000U + ((i) * 0x400000U))
#define RTDMA1CH8_BASE_FRAME(i)              (0x60007000U + ((i) * 0x400000U))
#define RTDMA1CH9_BASE_FRAME(i)              (0x60008000U + ((i) * 0x400000U))
#define RTDMA1CH10_BASE_FRAME(i)             (0x60009000U + ((i) * 0x400000U))
#define RTDMA2CH1_BASE_FRAME(i)              (0x60010000U + ((i) * 0x400000U))
#define RTDMA2CH2_BASE_FRAME(i)              (0x60011000U + ((i) * 0x400000U))
#define RTDMA2CH3_BASE_FRAME(i)              (0x60012000U + ((i) * 0x400000U))
#define RTDMA2CH4_BASE_FRAME(i)              (0x60013000U + ((i) * 0x400000U))
#define RTDMA2CH5_BASE_FRAME(i)              (0x60014000U + ((i) * 0x400000U))
#define RTDMA2CH6_BASE_FRAME(i)              (0x60015000U + ((i) * 0x400000U))
#define RTDMA2CH7_BASE_FRAME(i)              (0x60016000U + ((i) * 0x400000U))
#define RTDMA2CH8_BASE_FRAME(i)              (0x60017000U + ((i) * 0x400000U))
#define RTDMA2CH9_BASE_FRAME(i)              (0x60018000U + ((i) * 0x400000U))
#define RTDMA2CH10_BASE_FRAME(i)             (0x60019000U + ((i) * 0x400000U))
#define MCANA_DRIVER_BASE_FRAME(i)           (0x60020000U + ((i) * 0x400000U))
#define MCANASS_BASE_FRAME(i)                (0x60024000U + ((i) * 0x400000U))
#define MCANA_BASE_FRAME(i)                  (0x60024600U + ((i) * 0x400000U))
#define MCANA_ERROR_BASE_FRAME(i)            (0x60024800U + ((i) * 0x400000U))
#define MCANB_DRIVER_BASE_FRAME(i)           (0x60028000U + ((i) * 0x400000U))
#define MCANBSS_BASE_FRAME(i)                (0x6002C000U + ((i) * 0x400000U))
#define MCANB_BASE_FRAME(i)                  (0x6002C600U + ((i) * 0x400000U))
#define MCANB_ERROR_BASE_FRAME(i)            (0x6002C800U + ((i) * 0x400000U))
#define MCANC_DRIVER_BASE_FRAME(i)           (0x60030000U + ((i) * 0x400000U))
#define MCANCSS_BASE_FRAME(i)                (0x60034000U + ((i) * 0x400000U))
#define MCANC_BASE_FRAME(i)                  (0x60034600U + ((i) * 0x400000U))
#define MCANC_ERROR_BASE_FRAME(i)            (0x60034800U + ((i) * 0x400000U))
#define MCAND_DRIVER_BASE_FRAME(i)           (0x60038000U + ((i) * 0x400000U))
#define MCANDSS_BASE_FRAME(i)                (0x6003C000U + ((i) * 0x400000U))
#define MCAND_BASE_FRAME(i)                  (0x6003C600U + ((i) * 0x400000U))
#define MCAND_ERROR_BASE_FRAME(i)            (0x6003C800U + ((i) * 0x400000U))
#define MCANE_DRIVER_BASE_FRAME(i)           (0x60040000U + ((i) * 0x400000U))
#define MCANESS_BASE_FRAME(i)                (0x60044000U + ((i) * 0x400000U))
#define MCANE_BASE_FRAME(i)                  (0x60044600U + ((i) * 0x400000U))
#define MCANE_ERROR_BASE_FRAME(i)            (0x60044800U + ((i) * 0x400000U))
#define MCANF_DRIVER_BASE_FRAME(i)           (0x60048000U + ((i) * 0x400000U))
#define MCANFSS_BASE_FRAME(i)                (0x6004C000U + ((i) * 0x400000U))
#define MCANF_BASE_FRAME(i)                  (0x6004C600U + ((i) * 0x400000U))
#define MCANF_ERROR_BASE_FRAME(i)            (0x6004C800U + ((i) * 0x400000U))
#define LINA_BASE_FRAME(i)                   (0x60060000U + ((i) * 0x400000U))
#define LINB_BASE_FRAME(i)                   (0x60061000U + ((i) * 0x400000U))
#define SENT1_BASE_FRAME(i)                  (0x60068000U + ((i) * 0x400000U))
#define SENT2_BASE_FRAME(i)                  (0x60069000U + ((i) * 0x400000U))
#define SENT3_BASE_FRAME(i)                  (0x6006A000U + ((i) * 0x400000U))
#define SENT4_BASE_FRAME(i)                  (0x6006B000U + ((i) * 0x400000U))
#define SENT5_BASE_FRAME(i)                  (0x6006C000U + ((i) * 0x400000U))
#define SENT6_BASE_FRAME(i)                  (0x6006D000U + ((i) * 0x400000U))
#define UARTA_WRITE_BASE_FRAME(i)            (0x60070000U + ((i) * 0x400000U))
#define UARTA_BASE_FRAME(i)                  (0x60070000U + ((i) * 0x400000U))
#define UARTB_WRITE_BASE_FRAME(i)            (0x60072000U + ((i) * 0x400000U))
#define UARTB_BASE_FRAME(i)                  (0x60072000U + ((i) * 0x400000U))
#define UARTC_WRITE_BASE_FRAME(i)            (0x60074000U + ((i) * 0x400000U))
#define UARTC_BASE_FRAME(i)                  (0x60074000U + ((i) * 0x400000U))
#define UARTD_WRITE_BASE_FRAME(i)            (0x60076000U + ((i) * 0x400000U))
#define UARTD_BASE_FRAME(i)                  (0x60076000U + ((i) * 0x400000U))
#define UARTE_WRITE_BASE_FRAME(i)            (0x60078000U + ((i) * 0x400000U))
#define UARTE_BASE_FRAME(i)                  (0x60078000U + ((i) * 0x400000U))
#define UARTF_WRITE_BASE_FRAME(i)            (0x6007A000U + ((i) * 0x400000U))
#define UARTF_BASE_FRAME(i)                  (0x6007A000U + ((i) * 0x400000U))
#define DCC1_BASE_FRAME(i)                   (0x60080000U + ((i) * 0x400000U))
#define DCC2_BASE_FRAME(i)                   (0x60081000U + ((i) * 0x400000U))
#define DCC3_BASE_FRAME(i)                   (0x60082000U + ((i) * 0x400000U))
#define ERRORAGGREGATOR_BASE_FRAME(i)        (0x6008C000U + ((i) * 0x400000U))
#define ESMCPU1_BASE_FRAME(i)                (0x60090000U + ((i) * 0x400000U))
#define ESMCPU2_BASE_FRAME(i)                (0x60091000U + ((i) * 0x400000U))
#define ESMCPU3_BASE_FRAME(i)                (0x60092000U + ((i) * 0x400000U))
#define ESMSYSTEM_BASE_FRAME(i)              (0x6009F000U + ((i) * 0x400000U))
#define ESMSAFETYAGG_BASE_FRAME(i)           (0x600A0000U + ((i) * 0x400000U))
#define WADI1BLK1CONFIG_BASE_FRAME(i)        (0x600B0000U + ((i) * 0x400000U))
#define WADI1BLK2CONFIG_BASE_FRAME(i)        (0x600B0100U + ((i) * 0x400000U))
#define WADI1BLK3CONFIG_BASE_FRAME(i)        (0x600B0200U + ((i) * 0x400000U))
#define WADI1BLK4CONFIG_BASE_FRAME(i)        (0x600B0300U + ((i) * 0x400000U))
#define WADI1OPERSSS_BASE_FRAME(i)           (0x600B1000U + ((i) * 0x400000U))
#define WADI2BLK1CONFIG_BASE_FRAME(i)        (0x600B2000U + ((i) * 0x400000U))
#define WADI2BLK2CONFIG_BASE_FRAME(i)        (0x600B2100U + ((i) * 0x400000U))
#define WADI2BLK3CONFIG_BASE_FRAME(i)        (0x600B2200U + ((i) * 0x400000U))
#define WADI2BLK4CONFIG_BASE_FRAME(i)        (0x600B2300U + ((i) * 0x400000U))
#define WADI2OPERSSS_BASE_FRAME(i)           (0x600B3000U + ((i) * 0x400000U))
#define OUTPUTXBAR1_FLAGS_BASE_FRAME(i)      (0x600C0000U + ((i) * 0x400000U))
#define OUTPUTXBAR2_FLAGS_BASE_FRAME(i)      (0x600C1000U + ((i) * 0x400000U))
#define OUTPUTXBAR3_FLAGS_BASE_FRAME(i)      (0x600C2000U + ((i) * 0x400000U))
#define OUTPUTXBAR4_FLAGS_BASE_FRAME(i)      (0x600C3000U + ((i) * 0x400000U))
#define OUTPUTXBAR5_FLAGS_BASE_FRAME(i)      (0x600C4000U + ((i) * 0x400000U))
#define OUTPUTXBAR6_FLAGS_BASE_FRAME(i)      (0x600C5000U + ((i) * 0x400000U))
#define OUTPUTXBAR7_FLAGS_BASE_FRAME(i)      (0x600C6000U + ((i) * 0x400000U))
#define OUTPUTXBAR8_FLAGS_BASE_FRAME(i)      (0x600C7000U + ((i) * 0x400000U))
#define OUTPUTXBAR9_FLAGS_BASE_FRAME(i)      (0x600C8000U + ((i) * 0x400000U))
#define OUTPUTXBAR10_FLAGS_BASE_FRAME(i)     (0x600C9000U + ((i) * 0x400000U))
#define OUTPUTXBAR11_FLAGS_BASE_FRAME(i)     (0x600CA000U + ((i) * 0x400000U))
#define OUTPUTXBAR12_FLAGS_BASE_FRAME(i)     (0x600CB000U + ((i) * 0x400000U))
#define OUTPUTXBAR13_FLAGS_BASE_FRAME(i)     (0x600CC000U + ((i) * 0x400000U))
#define OUTPUTXBAR14_FLAGS_BASE_FRAME(i)     (0x600CD000U + ((i) * 0x400000U))
#define OUTPUTXBAR15_FLAGS_BASE_FRAME(i)     (0x600CE000U + ((i) * 0x400000U))
#define OUTPUTXBAR16_FLAGS_BASE_FRAME(i)     (0x600CF000U + ((i) * 0x400000U))
#define XBAR_BASE_FRAME(i)                   (0x600E0000U + ((i) * 0x400000U))
#define CPU1DLTFIFO_BASE_FRAME(i)            (0x600F8000U + ((i) * 0x400000U))
#define CPU2DLTFIFO_BASE_FRAME(i)            (0x600FA000U + ((i) * 0x400000U))
#define CPU3DLTFIFO_BASE_FRAME(i)            (0x600FC000U + ((i) * 0x400000U))
#define EPWM1_BASE_FRAME(i)                  (0x70000000U + ((i) * 0x400000U))
#define EPWM1XCMP_BASE_FRAME(i)              (0x70000400U + ((i) * 0x400000U))
#define EPWM1DE_BASE_FRAME(i)                (0x70000800U + ((i) * 0x400000U))
#define EPWM1MINDBLUT_BASE_FRAME(i)          (0x70000C00U + ((i) * 0x400000U))
#define EPWM2_BASE_FRAME(i)                  (0x70001000U + ((i) * 0x400000U))
#define EPWM2XCMP_BASE_FRAME(i)              (0x70001400U + ((i) * 0x400000U))
#define EPWM2DE_BASE_FRAME(i)                (0x70001800U + ((i) * 0x400000U))
#define EPWM2MINDBLUT_BASE_FRAME(i)          (0x70001C00U + ((i) * 0x400000U))
#define EPWM3_BASE_FRAME(i)                  (0x70002000U + ((i) * 0x400000U))
#define EPWM3XCMP_BASE_FRAME(i)              (0x70002400U + ((i) * 0x400000U))
#define EPWM3DE_BASE_FRAME(i)                (0x70002800U + ((i) * 0x400000U))
#define EPWM3MINDBLUT_BASE_FRAME(i)          (0x70002C00U + ((i) * 0x400000U))
#define EPWM4_BASE_FRAME(i)                  (0x70003000U + ((i) * 0x400000U))
#define EPWM4XCMP_BASE_FRAME(i)              (0x70003400U + ((i) * 0x400000U))
#define EPWM4DE_BASE_FRAME(i)                (0x70003800U + ((i) * 0x400000U))
#define EPWM4MINDBLUT_BASE_FRAME(i)          (0x70003C00U + ((i) * 0x400000U))
#define EPWM5_BASE_FRAME(i)                  (0x70004000U + ((i) * 0x400000U))
#define EPWM5XCMP_BASE_FRAME(i)              (0x70004400U + ((i) * 0x400000U))
#define EPWM5DE_BASE_FRAME(i)                (0x70004800U + ((i) * 0x400000U))
#define EPWM5MINDBLUT_BASE_FRAME(i)          (0x70004C00U + ((i) * 0x400000U))
#define EPWM6_BASE_FRAME(i)                  (0x70005000U + ((i) * 0x400000U))
#define EPWM6XCMP_BASE_FRAME(i)              (0x70005400U + ((i) * 0x400000U))
#define EPWM6DE_BASE_FRAME(i)                (0x70005800U + ((i) * 0x400000U))
#define EPWM6MINDBLUT_BASE_FRAME(i)          (0x70005C00U + ((i) * 0x400000U))
#define EPWM7_BASE_FRAME(i)                  (0x70006000U + ((i) * 0x400000U))
#define EPWM7XCMP_BASE_FRAME(i)              (0x70006400U + ((i) * 0x400000U))
#define EPWM7DE_BASE_FRAME(i)                (0x70006800U + ((i) * 0x400000U))
#define EPWM7MINDBLUT_BASE_FRAME(i)          (0x70006C00U + ((i) * 0x400000U))
#define EPWM8_BASE_FRAME(i)                  (0x70007000U + ((i) * 0x400000U))
#define EPWM8XCMP_BASE_FRAME(i)              (0x70007400U + ((i) * 0x400000U))
#define EPWM8DE_BASE_FRAME(i)                (0x70007800U + ((i) * 0x400000U))
#define EPWM8MINDBLUT_BASE_FRAME(i)          (0x70007C00U + ((i) * 0x400000U))
#define EPWM9_BASE_FRAME(i)                  (0x70008000U + ((i) * 0x400000U))
#define EPWM9XCMP_BASE_FRAME(i)              (0x70008400U + ((i) * 0x400000U))
#define EPWM9DE_BASE_FRAME(i)                (0x70008800U + ((i) * 0x400000U))
#define EPWM9MINDBLUT_BASE_FRAME(i)          (0x70008C00U + ((i) * 0x400000U))
#define EPWM10_BASE_FRAME(i)                 (0x70009000U + ((i) * 0x400000U))
#define EPWM10XCMP_BASE_FRAME(i)             (0x70009400U + ((i) * 0x400000U))
#define EPWM10DE_BASE_FRAME(i)               (0x70009800U + ((i) * 0x400000U))
#define EPWM10MINDBLUT_BASE_FRAME(i)         (0x70009C00U + ((i) * 0x400000U))
#define EPWM11_BASE_FRAME(i)                 (0x7000A000U + ((i) * 0x400000U))
#define EPWM11XCMP_BASE_FRAME(i)             (0x7000A400U + ((i) * 0x400000U))
#define EPWM11DE_BASE_FRAME(i)               (0x7000A800U + ((i) * 0x400000U))
#define EPWM11MINDBLUT_BASE_FRAME(i)         (0x7000AC00U + ((i) * 0x400000U))
#define EPWM12_BASE_FRAME(i)                 (0x7000B000U + ((i) * 0x400000U))
#define EPWM12XCMP_BASE_FRAME(i)             (0x7000B400U + ((i) * 0x400000U))
#define EPWM12DE_BASE_FRAME(i)               (0x7000B800U + ((i) * 0x400000U))
#define EPWM12MINDBLUT_BASE_FRAME(i)         (0x7000BC00U + ((i) * 0x400000U))
#define EPWM13_BASE_FRAME(i)                 (0x7000C000U + ((i) * 0x400000U))
#define EPWM13XCMP_BASE_FRAME(i)             (0x7000C400U + ((i) * 0x400000U))
#define EPWM13DE_BASE_FRAME(i)               (0x7000C800U + ((i) * 0x400000U))
#define EPWM13MINDBLUT_BASE_FRAME(i)         (0x7000CC00U + ((i) * 0x400000U))
#define EPWM14_BASE_FRAME(i)                 (0x7000D000U + ((i) * 0x400000U))
#define EPWM14XCMP_BASE_FRAME(i)             (0x7000D400U + ((i) * 0x400000U))
#define EPWM14DE_BASE_FRAME(i)               (0x7000D800U + ((i) * 0x400000U))
#define EPWM14MINDBLUT_BASE_FRAME(i)         (0x7000DC00U + ((i) * 0x400000U))
#define EPWM15_BASE_FRAME(i)                 (0x7000E000U + ((i) * 0x400000U))
#define EPWM15XCMP_BASE_FRAME(i)             (0x7000E400U + ((i) * 0x400000U))
#define EPWM15DE_BASE_FRAME(i)               (0x7000E800U + ((i) * 0x400000U))
#define EPWM15MINDBLUT_BASE_FRAME(i)         (0x7000EC00U + ((i) * 0x400000U))
#define EPWM16_BASE_FRAME(i)                 (0x7000F000U + ((i) * 0x400000U))
#define EPWM16XCMP_BASE_FRAME(i)             (0x7000F400U + ((i) * 0x400000U))
#define EPWM16DE_BASE_FRAME(i)               (0x7000F800U + ((i) * 0x400000U))
#define EPWM16MINDBLUT_BASE_FRAME(i)         (0x7000FC00U + ((i) * 0x400000U))
#define EPWM17_BASE_FRAME(i)                 (0x70010000U + ((i) * 0x400000U))
#define EPWM17XCMP_BASE_FRAME(i)             (0x70010400U + ((i) * 0x400000U))
#define EPWM17DE_BASE_FRAME(i)               (0x70010800U + ((i) * 0x400000U))
#define EPWM17MINDBLUT_BASE_FRAME(i)         (0x70010C00U + ((i) * 0x400000U))
#define EPWM18_BASE_FRAME(i)                 (0x70011000U + ((i) * 0x400000U))
#define EPWM18XCMP_BASE_FRAME(i)             (0x70011400U + ((i) * 0x400000U))
#define EPWM18DE_BASE_FRAME(i)               (0x70011800U + ((i) * 0x400000U))
#define EPWM18MINDBLUT_BASE_FRAME(i)         (0x70011C00U + ((i) * 0x400000U))
#define EPWM1XLINK_BASE_FRAME(i)             (0x70040000U + ((i) * 0x400000U))
#define EPWM1XCMPXLINK_BASE_FRAME(i)         (0x70040400U + ((i) * 0x400000U))
#define EPWM1DEXLINK_BASE_FRAME(i)           (0x70040800U + ((i) * 0x400000U))
#define EPWM1MINDBLUTXLINK_BASE_FRAME(i)     (0x70040C00U + ((i) * 0x400000U))
#define EPWM2XLINK_BASE_FRAME(i)             (0x70041000U + ((i) * 0x400000U))
#define EPWM2XCMPXLINK_BASE_FRAME(i)         (0x70041400U + ((i) * 0x400000U))
#define EPWM2DEXLINK_BASE_FRAME(i)           (0x70041800U + ((i) * 0x400000U))
#define EPWM2MINDBLUTXLINK_BASE_FRAME(i)     (0x70041C00U + ((i) * 0x400000U))
#define EPWM3XLINK_BASE_FRAME(i)             (0x70042000U + ((i) * 0x400000U))
#define EPWM3XCMPXLINK_BASE_FRAME(i)         (0x70042400U + ((i) * 0x400000U))
#define EPWM3DEXLINK_BASE_FRAME(i)           (0x70042800U + ((i) * 0x400000U))
#define EPWM3MINDBLUTXLINK_BASE_FRAME(i)     (0x70042C00U + ((i) * 0x400000U))
#define EPWM4XLINK_BASE_FRAME(i)             (0x70043000U + ((i) * 0x400000U))
#define EPWM4XCMPXLINK_BASE_FRAME(i)         (0x70043400U + ((i) * 0x400000U))
#define EPWM4DEXLINK_BASE_FRAME(i)           (0x70043800U + ((i) * 0x400000U))
#define EPWM4MINDBLUTXLINK_BASE_FRAME(i)     (0x70043C00U + ((i) * 0x400000U))
#define EPWM5XLINK_BASE_FRAME(i)             (0x70044000U + ((i) * 0x400000U))
#define EPWM5XCMPXLINK_BASE_FRAME(i)         (0x70044400U + ((i) * 0x400000U))
#define EPWM5DEXLINK_BASE_FRAME(i)           (0x70044800U + ((i) * 0x400000U))
#define EPWM5MINDBLUTXLINK_BASE_FRAME(i)     (0x70044C00U + ((i) * 0x400000U))
#define EPWM6XLINK_BASE_FRAME(i)             (0x70045000U + ((i) * 0x400000U))
#define EPWM6XCMPXLINK_BASE_FRAME(i)         (0x70045400U + ((i) * 0x400000U))
#define EPWM6DEXLINK_BASE_FRAME(i)           (0x70045800U + ((i) * 0x400000U))
#define EPWM6MINDBLUTXLINK_BASE_FRAME(i)     (0x70045C00U + ((i) * 0x400000U))
#define EPWM7XLINK_BASE_FRAME(i)             (0x70046000U + ((i) * 0x400000U))
#define EPWM7XCMPXLINK_BASE_FRAME(i)         (0x70046400U + ((i) * 0x400000U))
#define EPWM7DEXLINK_BASE_FRAME(i)           (0x70046800U + ((i) * 0x400000U))
#define EPWM7MINDBLUTXLINK_BASE_FRAME(i)     (0x70046C00U + ((i) * 0x400000U))
#define EPWM8XLINK_BASE_FRAME(i)             (0x70047000U + ((i) * 0x400000U))
#define EPWM8XCMPXLINK_BASE_FRAME(i)         (0x70047400U + ((i) * 0x400000U))
#define EPWM8DEXLINK_BASE_FRAME(i)           (0x70047800U + ((i) * 0x400000U))
#define EPWM8MINDBLUTXLINK_BASE_FRAME(i)     (0x70047C00U + ((i) * 0x400000U))
#define EPWM9XLINK_BASE_FRAME(i)             (0x70048000U + ((i) * 0x400000U))
#define EPWM9XCMPXLINK_BASE_FRAME(i)         (0x70048400U + ((i) * 0x400000U))
#define EPWM9DEXLINK_BASE_FRAME(i)           (0x70048800U + ((i) * 0x400000U))
#define EPWM9MINDBLUTXLINK_BASE_FRAME(i)     (0x70048C00U + ((i) * 0x400000U))
#define EPWM10XLINK_BASE_FRAME(i)            (0x70049000U + ((i) * 0x400000U))
#define EPWM10XCMPXLINK_BASE_FRAME(i)        (0x70049400U + ((i) * 0x400000U))
#define EPWM10DEXLINK_BASE_FRAME(i)          (0x70049800U + ((i) * 0x400000U))
#define EPWM10MINDBLUTXLINK_BASE_FRAME(i)    (0x70049C00U + ((i) * 0x400000U))
#define EPWM11XLINK_BASE_FRAME(i)            (0x7004A000U + ((i) * 0x400000U))
#define EPWM11XCMPXLINK_BASE_FRAME(i)        (0x7004A400U + ((i) * 0x400000U))
#define EPWM11DEXLINK_BASE_FRAME(i)          (0x7004A800U + ((i) * 0x400000U))
#define EPWM11MINDBLUTXLINK_BASE_FRAME(i)    (0x7004AC00U + ((i) * 0x400000U))
#define EPWM12XLINK_BASE_FRAME(i)            (0x7004B000U + ((i) * 0x400000U))
#define EPWM12XCMPXLINK_BASE_FRAME(i)        (0x7004B400U + ((i) * 0x400000U))
#define EPWM12DEXLINK_BASE_FRAME(i)          (0x7004B800U + ((i) * 0x400000U))
#define EPWM12MINDBLUTXLINK_BASE_FRAME(i)    (0x7004BC00U + ((i) * 0x400000U))
#define EPWM13XLINK_BASE_FRAME(i)            (0x7004C000U + ((i) * 0x400000U))
#define EPWM13XCMPXLINK_BASE_FRAME(i)        (0x7004C400U + ((i) * 0x400000U))
#define EPWM13DEXLINK_BASE_FRAME(i)          (0x7004C800U + ((i) * 0x400000U))
#define EPWM13MINDBLUTXLINK_BASE_FRAME(i)    (0x7004CC00U + ((i) * 0x400000U))
#define EPWM14XLINK_BASE_FRAME(i)            (0x7004D000U + ((i) * 0x400000U))
#define EPWM14XCMPXLINK_BASE_FRAME(i)        (0x7004D400U + ((i) * 0x400000U))
#define EPWM14DEXLINK_BASE_FRAME(i)          (0x7004D800U + ((i) * 0x400000U))
#define EPWM14MINDBLUTXLINK_BASE_FRAME(i)    (0x7004DC00U + ((i) * 0x400000U))
#define EPWM15XLINK_BASE_FRAME(i)            (0x7004E000U + ((i) * 0x400000U))
#define EPWM15XCMPXLINK_BASE_FRAME(i)        (0x7004E400U + ((i) * 0x400000U))
#define EPWM15DEXLINK_BASE_FRAME(i)          (0x7004E800U + ((i) * 0x400000U))
#define EPWM15MINDBLUTXLINK_BASE_FRAME(i)    (0x7004EC00U + ((i) * 0x400000U))
#define EPWM16XLINK_BASE_FRAME(i)            (0x7004F000U + ((i) * 0x400000U))
#define EPWM16XCMPXLINK_BASE_FRAME(i)        (0x7004F400U + ((i) * 0x400000U))
#define EPWM16DEXLINK_BASE_FRAME(i)          (0x7004F800U + ((i) * 0x400000U))
#define EPWM16MINDBLUTXLINK_BASE_FRAME(i)    (0x7004FC00U + ((i) * 0x400000U))
#define EPWM17XLINK_BASE_FRAME(i)            (0x70050000U + ((i) * 0x400000U))
#define EPWM17XCMPXLINK_BASE_FRAME(i)        (0x70050400U + ((i) * 0x400000U))
#define EPWM17DEXLINK_BASE_FRAME(i)          (0x70050800U + ((i) * 0x400000U))
#define EPWM17MINDBLUTXLINK_BASE_FRAME(i)    (0x70050C00U + ((i) * 0x400000U))
#define EPWM18XLINK_BASE_FRAME(i)            (0x70051000U + ((i) * 0x400000U))
#define EPWM18XCMPXLINK_BASE_FRAME(i)        (0x70051400U + ((i) * 0x400000U))
#define EPWM18DEXLINK_BASE_FRAME(i)          (0x70051800U + ((i) * 0x400000U))
#define EPWM18MINDBLUTXLINK_BASE_FRAME(i)    (0x70051C00U + ((i) * 0x400000U))
#define HRPWMCAL1_BASE_FRAME(i)              (0x70080000U + ((i) * 0x400000U))
#define HRPWMCAL2_BASE_FRAME(i)              (0x70081000U + ((i) * 0x400000U))
#define HRPWMCAL3_BASE_FRAME(i)              (0x70082000U + ((i) * 0x400000U))
#define EQEP1_BASE_FRAME(i)                  (0x70088000U + ((i) * 0x400000U))
#define EQEP2_BASE_FRAME(i)                  (0x70089000U + ((i) * 0x400000U))
#define EQEP3_BASE_FRAME(i)                  (0x7008A000U + ((i) * 0x400000U))
#define EQEP4_BASE_FRAME(i)                  (0x7008B000U + ((i) * 0x400000U))
#define EQEP5_BASE_FRAME(i)                  (0x7008C000U + ((i) * 0x400000U))
#define EQEP6_BASE_FRAME(i)                  (0x7008D000U + ((i) * 0x400000U))
#define SDFM1_BASE_FRAME(i)                  (0x70090000U + ((i) * 0x400000U))
#define SDFM2_BASE_FRAME(i)                  (0x70091000U + ((i) * 0x400000U))
#define SDFM3_BASE_FRAME(i)                  (0x70092000U + ((i) * 0x400000U))
#define SDFM4_BASE_FRAME(i)                  (0x70093000U + ((i) * 0x400000U))
#define ADCA_BASE_FRAME(i)                   (0x700A0000U + ((i) * 0x400000U))
#define ADCB_BASE_FRAME(i)                   (0x700A1000U + ((i) * 0x400000U))
#define ADCC_BASE_FRAME(i)                   (0x700A2000U + ((i) * 0x400000U))
#define ADCD_BASE_FRAME(i)                   (0x700A3000U + ((i) * 0x400000U))
#define ADCE_BASE_FRAME(i)                   (0x700A4000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK1_BASE_FRAME(i)        (0x700B0000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK2_BASE_FRAME(i)        (0x700B1000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK3_BASE_FRAME(i)        (0x700B2000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK4_BASE_FRAME(i)        (0x700B3000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK5_BASE_FRAME(i)        (0x700B4000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK6_BASE_FRAME(i)        (0x700B5000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK7_BASE_FRAME(i)        (0x700B6000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK8_BASE_FRAME(i)        (0x700B7000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK9_BASE_FRAME(i)        (0x700B8000U + ((i) * 0x400000U))
#define ADCSAFETYCHECK10_BASE_FRAME(i)       (0x700B9000U + ((i) * 0x400000U))
#define ADCSAFETYCHECKINTEVT1_BASE_FRAME(i)  (0x700C0000U + ((i) * 0x400000U))
#define ADCSAFETYCHECKINTEVT2_BASE_FRAME(i)  (0x700C1000U + ((i) * 0x400000U))
#define ADCSAFETYCHECKINTEVT3_BASE_FRAME(i)  (0x700C2000U + ((i) * 0x400000U))
#define ADCGLOBAL_BASE_FRAME(i)              (0x700C8000U + ((i) * 0x400000U))
#define DACA_BASE_FRAME(i)                   (0x700D0000U + ((i) * 0x400000U))
#define DACB_BASE_FRAME(i)                   (0x700D1000U + ((i) * 0x400000U))
#define CMPSS1_BASE_FRAME(i)                 (0x700E0000U + ((i) * 0x400000U))
#define CMPSS2_BASE_FRAME(i)                 (0x700E1000U + ((i) * 0x400000U))
#define CMPSS3_BASE_FRAME(i)                 (0x700E2000U + ((i) * 0x400000U))
#define CMPSS4_BASE_FRAME(i)                 (0x700E3000U + ((i) * 0x400000U))
#define CMPSS5_BASE_FRAME(i)                 (0x700E4000U + ((i) * 0x400000U))
#define CMPSS6_BASE_FRAME(i)                 (0x700E5000U + ((i) * 0x400000U))
#define CMPSS7_BASE_FRAME(i)                 (0x700E6000U + ((i) * 0x400000U))
#define CMPSS8_BASE_FRAME(i)                 (0x700E7000U + ((i) * 0x400000U))
#define CMPSS9_BASE_FRAME(i)                 (0x700E8000U + ((i) * 0x400000U))
#define CMPSS10_BASE_FRAME(i)                (0x700E9000U + ((i) * 0x400000U))
#define CMPSS11_BASE_FRAME(i)                (0x700EA000U + ((i) * 0x400000U))
#define CMPSS12_BASE_FRAME(i)                (0x700EB000U + ((i) * 0x400000U))
#define ECAP1_BASE_FRAME(i)                  (0x70100000U + ((i) * 0x400000U))
#define ECAP1SIGNALMONITORING_BASE_FRAME(i)  (0x70100080U + ((i) * 0x400000U))
#define ECAP2_BASE_FRAME(i)                  (0x70101000U + ((i) * 0x400000U))
#define ECAP2SIGNALMONITORING_BASE_FRAME(i)  (0x70101080U + ((i) * 0x400000U))
#define ECAP3_BASE_FRAME(i)                  (0x70102000U + ((i) * 0x400000U))
#define ECAP3SIGNALMONITORING_BASE_FRAME(i)  (0x70102080U + ((i) * 0x400000U))
#define ECAP4_BASE_FRAME(i)                  (0x70103000U + ((i) * 0x400000U))
#define ECAP4SIGNALMONITORING_BASE_FRAME(i)  (0x70103080U + ((i) * 0x400000U))
#define ECAP5_BASE_FRAME(i)                  (0x70104000U + ((i) * 0x400000U))
#define HRCAP5_BASE_FRAME(i)                 (0x70104040U + ((i) * 0x400000U))
#define ECAP5SIGNALMONITORING_BASE_FRAME(i)  (0x70104080U + ((i) * 0x400000U))
#define ECAP6_BASE_FRAME(i)                  (0x70105000U + ((i) * 0x400000U))
#define HRCAP6_BASE_FRAME(i)                 (0x70105040U + ((i) * 0x400000U))
#define ECAP6SIGNALMONITORING_BASE_FRAME(i)  (0x70105080U + ((i) * 0x400000U))
#define CLB1_BASE_FRAME(i)                   (0x70120000U + ((i) * 0x400000U))
#define CLB1_LOGICCFG_BASE_FRAME(i)          (0x70120000U + ((i) * 0x400000U))
#define CLB1_LOGICCTRL_BASE_FRAME(i)         (0x70120200U + ((i) * 0x400000U))
#define CLB1_DATAEXCH_BASE_FRAME(i)          (0x70120300U + ((i) * 0x400000U))
#define CLB2_BASE_FRAME(i)                   (0x70121000U + ((i) * 0x400000U))
#define CLB2_LOGICCFG_BASE_FRAME(i)          (0x70121000U + ((i) * 0x400000U))
#define CLB2_LOGICCTRL_BASE_FRAME(i)         (0x70121200U + ((i) * 0x400000U))
#define CLB2_DATAEXCH_BASE_FRAME(i)          (0x70121300U + ((i) * 0x400000U))
#define CLB3_BASE_FRAME(i)                   (0x70122000U + ((i) * 0x400000U))
#define CLB3_LOGICCFG_BASE_FRAME(i)          (0x70122000U + ((i) * 0x400000U))
#define CLB3_LOGICCTRL_BASE_FRAME(i)         (0x70122200U + ((i) * 0x400000U))
#define CLB3_DATAEXCH_BASE_FRAME(i)          (0x70122300U + ((i) * 0x400000U))
#define CLB4_BASE_FRAME(i)                   (0x70123000U + ((i) * 0x400000U))
#define CLB4_LOGICCFG_BASE_FRAME(i)          (0x70123000U + ((i) * 0x400000U))
#define CLB4_LOGICCTRL_BASE_FRAME(i)         (0x70123200U + ((i) * 0x400000U))
#define CLB4_DATAEXCH_BASE_FRAME(i)          (0x70123300U + ((i) * 0x400000U))
#define CLB5_BASE_FRAME(i)                   (0x70124000U + ((i) * 0x400000U))
#define CLB5_LOGICCFG_BASE_FRAME(i)          (0x70124000U + ((i) * 0x400000U))
#define CLB5_LOGICCTRL_BASE_FRAME(i)         (0x70124200U + ((i) * 0x400000U))
#define CLB5_DATAEXCH_BASE_FRAME(i)          (0x70124300U + ((i) * 0x400000U))
#define CLB6_BASE_FRAME(i)                   (0x70125000U + ((i) * 0x400000U))
#define CLB6_LOGICCFG_BASE_FRAME(i)          (0x70125000U + ((i) * 0x400000U))
#define CLB6_LOGICCTRL_BASE_FRAME(i)         (0x70125200U + ((i) * 0x400000U))
#define CLB6_DATAEXCH_BASE_FRAME(i)          (0x70125300U + ((i) * 0x400000U))
#define PMBUSA_BASE_FRAME(i)                 (0x70148000U + ((i) * 0x400000U))
#define I2CA_BASE_FRAME(i)                   (0x70150000U + ((i) * 0x400000U))
#define I2CB_BASE_FRAME(i)                   (0x70151000U + ((i) * 0x400000U))
#define SPIA_BASE_FRAME(i)                   (0x70158000U + ((i) * 0x400000U))
#define SPIB_BASE_FRAME(i)                   (0x70159000U + ((i) * 0x400000U))
#define SPIC_BASE_FRAME(i)                   (0x7015A000U + ((i) * 0x400000U))
#define SPID_BASE_FRAME(i)                   (0x7015B000U + ((i) * 0x400000U))
#define SPIE_BASE_FRAME(i)                   (0x7015C000U + ((i) * 0x400000U))
#define FSITXA_BASE_FRAME(i)                 (0x70180000U + ((i) * 0x400000U))
#define FSITXB_BASE_FRAME(i)                 (0x70181000U + ((i) * 0x400000U))
#define FSITXC_BASE_FRAME(i)                 (0x70182000U + ((i) * 0x400000U))
#define FSITXD_BASE_FRAME(i)                 (0x70183000U + ((i) * 0x400000U))
#define FSIRXA_BASE_FRAME(i)                 (0x70188000U + ((i) * 0x400000U))
#define FSIRXB_BASE_FRAME(i)                 (0x70189000U + ((i) * 0x400000U))
#define FSIRXC_BASE_FRAME(i)                 (0x7018A000U + ((i) * 0x400000U))
#define FSIRXD_BASE_FRAME(i)                 (0x7018B000U + ((i) * 0x400000U))
#define EPG_BASE_FRAME(i)                    (0x701C0000U + ((i) * 0x400000U))
#define EPGMUX_BASE_FRAME(i)                 (0x701C0200U + ((i) * 0x400000U))

#ifdef USE_PERIPHERAL_FRAMES
    #include "peripheral_frame_mapping.h"
#endif
//
// Default mapping if USE_PERIPHERAL_FRAMES is not enabled or
// if _BASE macro mapping is not added in peripheral_frame_mapping.h
//
#ifndef RTDMA1CH1_BASE
    #define RTDMA1CH1_BASE                   RTDMA1CH1_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH2_BASE
    #define RTDMA1CH2_BASE                   RTDMA1CH2_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH3_BASE
    #define RTDMA1CH3_BASE                   RTDMA1CH3_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH4_BASE
    #define RTDMA1CH4_BASE                   RTDMA1CH4_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH5_BASE
    #define RTDMA1CH5_BASE                   RTDMA1CH5_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH6_BASE
    #define RTDMA1CH6_BASE                   RTDMA1CH6_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH7_BASE
    #define RTDMA1CH7_BASE                   RTDMA1CH7_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH8_BASE
    #define RTDMA1CH8_BASE                   RTDMA1CH8_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH9_BASE
    #define RTDMA1CH9_BASE                   RTDMA1CH9_BASE_FRAME(0U)
#endif
#ifndef RTDMA1CH10_BASE
    #define RTDMA1CH10_BASE                  RTDMA1CH10_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH1_BASE
    #define RTDMA2CH1_BASE                   RTDMA2CH1_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH2_BASE
    #define RTDMA2CH2_BASE                   RTDMA2CH2_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH3_BASE
    #define RTDMA2CH3_BASE                   RTDMA2CH3_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH4_BASE
    #define RTDMA2CH4_BASE                   RTDMA2CH4_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH5_BASE
    #define RTDMA2CH5_BASE                   RTDMA2CH5_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH6_BASE
    #define RTDMA2CH6_BASE                   RTDMA2CH6_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH7_BASE
    #define RTDMA2CH7_BASE                   RTDMA2CH7_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH8_BASE
    #define RTDMA2CH8_BASE                   RTDMA2CH8_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH9_BASE
    #define RTDMA2CH9_BASE                   RTDMA2CH9_BASE_FRAME(0U)
#endif
#ifndef RTDMA2CH10_BASE
    #define RTDMA2CH10_BASE                  RTDMA2CH10_BASE_FRAME(0U)
#endif
#ifndef MCANA_DRIVER_BASE
    #define MCANA_DRIVER_BASE                MCANA_DRIVER_BASE_FRAME(0U)
#endif
#ifndef MCANASS_BASE
    #define MCANASS_BASE                     MCANASS_BASE_FRAME(0U)
#endif
#ifndef MCANA_BASE
    #define MCANA_BASE                       MCANA_BASE_FRAME(0U)
#endif
#ifndef MCANA_ERROR_BASE
    #define MCANA_ERROR_BASE                 MCANA_ERROR_BASE_FRAME(0U)
#endif
#ifndef MCANB_DRIVER_BASE
    #define MCANB_DRIVER_BASE                MCANB_DRIVER_BASE_FRAME(0U)
#endif
#ifndef MCANBSS_BASE
    #define MCANBSS_BASE                     MCANBSS_BASE_FRAME(0U)
#endif
#ifndef MCANB_BASE
    #define MCANB_BASE                       MCANB_BASE_FRAME(0U)
#endif
#ifndef MCANB_ERROR_BASE
    #define MCANB_ERROR_BASE                 MCANB_ERROR_BASE_FRAME(0U)
#endif
#ifndef MCANC_DRIVER_BASE
    #define MCANC_DRIVER_BASE                MCANC_DRIVER_BASE_FRAME(0U)
#endif
#ifndef MCANCSS_BASE
    #define MCANCSS_BASE                     MCANCSS_BASE_FRAME(0U)
#endif
#ifndef MCANC_BASE
    #define MCANC_BASE                       MCANC_BASE_FRAME(0U)
#endif
#ifndef MCANC_ERROR_BASE
    #define MCANC_ERROR_BASE                 MCANC_ERROR_BASE_FRAME(0U)
#endif
#ifndef MCAND_DRIVER_BASE
    #define MCAND_DRIVER_BASE                MCAND_DRIVER_BASE_FRAME(0U)
#endif
#ifndef MCANDSS_BASE
    #define MCANDSS_BASE                     MCANDSS_BASE_FRAME(0U)
#endif
#ifndef MCAND_BASE
    #define MCAND_BASE                       MCAND_BASE_FRAME(0U)
#endif
#ifndef MCAND_ERROR_BASE
    #define MCAND_ERROR_BASE                 MCAND_ERROR_BASE_FRAME(0U)
#endif
#ifndef MCANE_DRIVER_BASE
    #define MCANE_DRIVER_BASE                MCANE_DRIVER_BASE_FRAME(0U)
#endif
#ifndef MCANESS_BASE
    #define MCANESS_BASE                     MCANESS_BASE_FRAME(0U)
#endif
#ifndef MCANE_BASE
    #define MCANE_BASE                       MCANE_BASE_FRAME(0U)
#endif
#ifndef MCANE_ERROR_BASE
    #define MCANE_ERROR_BASE                 MCANE_ERROR_BASE_FRAME(0U)
#endif
#ifndef MCANF_DRIVER_BASE
    #define MCANF_DRIVER_BASE                MCANF_DRIVER_BASE_FRAME(0U)
#endif
#ifndef MCANFSS_BASE
    #define MCANFSS_BASE                     MCANFSS_BASE_FRAME(0U)
#endif
#ifndef MCANF_BASE
    #define MCANF_BASE                       MCANF_BASE_FRAME(0U)
#endif
#ifndef MCANF_ERROR_BASE
    #define MCANF_ERROR_BASE                 MCANF_ERROR_BASE_FRAME(0U)
#endif
#ifndef LINA_BASE
    #define LINA_BASE                        LINA_BASE_FRAME(0U)
#endif
#ifndef LINB_BASE
    #define LINB_BASE                        LINB_BASE_FRAME(0U)
#endif
#ifndef SENT1_BASE
    #define SENT1_BASE                       SENT1_BASE_FRAME(0U)
#endif
#ifndef SENT2_BASE
    #define SENT2_BASE                       SENT2_BASE_FRAME(0U)
#endif
#ifndef SENT3_BASE
    #define SENT3_BASE                       SENT3_BASE_FRAME(0U)
#endif
#ifndef SENT4_BASE
    #define SENT4_BASE                       SENT4_BASE_FRAME(0U)
#endif
#ifndef SENT5_BASE
    #define SENT5_BASE                       SENT5_BASE_FRAME(0U)
#endif
#ifndef SENT6_BASE
    #define SENT6_BASE                       SENT6_BASE_FRAME(0U)
#endif
#ifndef UARTA_WRITE_BASE
    #define UARTA_WRITE_BASE                 UARTA_WRITE_BASE_FRAME(0U)
#endif
#ifndef UARTA_BASE
    #define UARTA_BASE                       UARTA_BASE_FRAME(0U)
#endif
#ifndef UARTB_WRITE_BASE
    #define UARTB_WRITE_BASE                 UARTB_WRITE_BASE_FRAME(0U)
#endif
#ifndef UARTB_BASE
    #define UARTB_BASE                       UARTB_BASE_FRAME(0U)
#endif
#ifndef UARTC_WRITE_BASE
    #define UARTC_WRITE_BASE                 UARTC_WRITE_BASE_FRAME(0U)
#endif
#ifndef UARTC_BASE
    #define UARTC_BASE                       UARTC_BASE_FRAME(0U)
#endif
#ifndef UARTD_WRITE_BASE
    #define UARTD_WRITE_BASE                 UARTD_WRITE_BASE_FRAME(0U)
#endif
#ifndef UARTD_BASE
    #define UARTD_BASE                       UARTD_BASE_FRAME(0U)
#endif
#ifndef UARTE_WRITE_BASE
    #define UARTE_WRITE_BASE                 UARTE_WRITE_BASE_FRAME(0U)
#endif
#ifndef UARTE_BASE
    #define UARTE_BASE                       UARTE_BASE_FRAME(0U)
#endif
#ifndef UARTF_WRITE_BASE
    #define UARTF_WRITE_BASE                 UARTF_WRITE_BASE_FRAME(0U)
#endif
#ifndef UARTF_BASE
    #define UARTF_BASE                       UARTF_BASE_FRAME(0U)
#endif
#ifndef DCC1_BASE
    #define DCC1_BASE                        DCC1_BASE_FRAME(0U)
#endif
#ifndef DCC2_BASE
    #define DCC2_BASE                        DCC2_BASE_FRAME(0U)
#endif
#ifndef DCC3_BASE
    #define DCC3_BASE                        DCC3_BASE_FRAME(0U)
#endif
#ifndef ERRORAGGREGATOR_BASE
    #define ERRORAGGREGATOR_BASE             ERRORAGGREGATOR_BASE_FRAME(0U)
#endif
#ifndef ESMCPU1_BASE
    #define ESMCPU1_BASE                     ESMCPU1_BASE_FRAME(0U)
#endif
#ifndef ESMCPU2_BASE
    #define ESMCPU2_BASE                     ESMCPU2_BASE_FRAME(0U)
#endif
#ifndef ESMCPU3_BASE
    #define ESMCPU3_BASE                     ESMCPU3_BASE_FRAME(0U)
#endif
#ifndef ESMSYSTEM_BASE
    #define ESMSYSTEM_BASE                   ESMSYSTEM_BASE_FRAME(0U)
#endif
#ifndef ESMSAFETYAGG_BASE
    #define ESMSAFETYAGG_BASE                ESMSAFETYAGG_BASE_FRAME(0U)
#endif
#ifndef WADI1BLK1CONFIG_BASE
    #define WADI1BLK1CONFIG_BASE             WADI1BLK1CONFIG_BASE_FRAME(0U)
#endif
#ifndef WADI1BLK2CONFIG_BASE
    #define WADI1BLK2CONFIG_BASE             WADI1BLK2CONFIG_BASE_FRAME(0U)
#endif
#ifndef WADI1BLK3CONFIG_BASE
    #define WADI1BLK3CONFIG_BASE             WADI1BLK3CONFIG_BASE_FRAME(0U)
#endif
#ifndef WADI1BLK4CONFIG_BASE
    #define WADI1BLK4CONFIG_BASE             WADI1BLK4CONFIG_BASE_FRAME(0U)
#endif
#ifndef WADI1OPERSSS_BASE
    #define WADI1OPERSSS_BASE                WADI1OPERSSS_BASE_FRAME(0U)
#endif
#ifndef WADI2BLK1CONFIG_BASE
    #define WADI2BLK1CONFIG_BASE             WADI2BLK1CONFIG_BASE_FRAME(0U)
#endif
#ifndef WADI2BLK2CONFIG_BASE
    #define WADI2BLK2CONFIG_BASE             WADI2BLK2CONFIG_BASE_FRAME(0U)
#endif
#ifndef WADI2BLK3CONFIG_BASE
    #define WADI2BLK3CONFIG_BASE             WADI2BLK3CONFIG_BASE_FRAME(0U)
#endif
#ifndef WADI2BLK4CONFIG_BASE
    #define WADI2BLK4CONFIG_BASE             WADI2BLK4CONFIG_BASE_FRAME(0U)
#endif
#ifndef WADI2OPERSSS_BASE
    #define WADI2OPERSSS_BASE                WADI2OPERSSS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR1_FLAGS_BASE
    #define OUTPUTXBAR1_FLAGS_BASE           OUTPUTXBAR1_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR2_FLAGS_BASE
    #define OUTPUTXBAR2_FLAGS_BASE           OUTPUTXBAR2_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR3_FLAGS_BASE
    #define OUTPUTXBAR3_FLAGS_BASE           OUTPUTXBAR3_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR4_FLAGS_BASE
    #define OUTPUTXBAR4_FLAGS_BASE           OUTPUTXBAR4_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR5_FLAGS_BASE
    #define OUTPUTXBAR5_FLAGS_BASE           OUTPUTXBAR5_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR6_FLAGS_BASE
    #define OUTPUTXBAR6_FLAGS_BASE           OUTPUTXBAR6_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR7_FLAGS_BASE
    #define OUTPUTXBAR7_FLAGS_BASE           OUTPUTXBAR7_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR8_FLAGS_BASE
    #define OUTPUTXBAR8_FLAGS_BASE           OUTPUTXBAR8_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR9_FLAGS_BASE
    #define OUTPUTXBAR9_FLAGS_BASE           OUTPUTXBAR9_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR10_FLAGS_BASE
    #define OUTPUTXBAR10_FLAGS_BASE          OUTPUTXBAR10_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR11_FLAGS_BASE
    #define OUTPUTXBAR11_FLAGS_BASE          OUTPUTXBAR11_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR12_FLAGS_BASE
    #define OUTPUTXBAR12_FLAGS_BASE          OUTPUTXBAR12_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR13_FLAGS_BASE
    #define OUTPUTXBAR13_FLAGS_BASE          OUTPUTXBAR13_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR14_FLAGS_BASE
    #define OUTPUTXBAR14_FLAGS_BASE          OUTPUTXBAR14_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR15_FLAGS_BASE
    #define OUTPUTXBAR15_FLAGS_BASE          OUTPUTXBAR15_FLAGS_BASE_FRAME(0U)
#endif
#ifndef OUTPUTXBAR16_FLAGS_BASE
    #define OUTPUTXBAR16_FLAGS_BASE          OUTPUTXBAR16_FLAGS_BASE_FRAME(0U)
#endif
#ifndef XBAR_BASE
    #define XBAR_BASE                        XBAR_BASE_FRAME(0U)
#endif
#ifndef CPU1DLTFIFO_BASE
    #define CPU1DLTFIFO_BASE                 CPU1DLTFIFO_BASE_FRAME(0U)
#endif
#ifndef CPU2DLTFIFO_BASE
    #define CPU2DLTFIFO_BASE                 CPU2DLTFIFO_BASE_FRAME(0U)
#endif
#ifndef CPU3DLTFIFO_BASE
    #define CPU3DLTFIFO_BASE                 CPU3DLTFIFO_BASE_FRAME(0U)
#endif
#ifndef EPWM1_BASE
    #define EPWM1_BASE                       EPWM1_BASE_FRAME(0U)
#endif
#ifndef EPWM1XCMP_BASE
    #define EPWM1XCMP_BASE                   EPWM1XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM1DE_BASE
    #define EPWM1DE_BASE                     EPWM1DE_BASE_FRAME(0U)
#endif
#ifndef EPWM1MINDBLUT_BASE
    #define EPWM1MINDBLUT_BASE               EPWM1MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM2_BASE
    #define EPWM2_BASE                       EPWM2_BASE_FRAME(0U)
#endif
#ifndef EPWM2XCMP_BASE
    #define EPWM2XCMP_BASE                   EPWM2XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM2DE_BASE
    #define EPWM2DE_BASE                     EPWM2DE_BASE_FRAME(0U)
#endif
#ifndef EPWM2MINDBLUT_BASE
    #define EPWM2MINDBLUT_BASE               EPWM2MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM3_BASE
    #define EPWM3_BASE                       EPWM3_BASE_FRAME(0U)
#endif
#ifndef EPWM3XCMP_BASE
    #define EPWM3XCMP_BASE                   EPWM3XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM3DE_BASE
    #define EPWM3DE_BASE                     EPWM3DE_BASE_FRAME(0U)
#endif
#ifndef EPWM3MINDBLUT_BASE
    #define EPWM3MINDBLUT_BASE               EPWM3MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM4_BASE
    #define EPWM4_BASE                       EPWM4_BASE_FRAME(0U)
#endif
#ifndef EPWM4XCMP_BASE
    #define EPWM4XCMP_BASE                   EPWM4XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM4DE_BASE
    #define EPWM4DE_BASE                     EPWM4DE_BASE_FRAME(0U)
#endif
#ifndef EPWM4MINDBLUT_BASE
    #define EPWM4MINDBLUT_BASE               EPWM4MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM5_BASE
    #define EPWM5_BASE                       EPWM5_BASE_FRAME(0U)
#endif
#ifndef EPWM5XCMP_BASE
    #define EPWM5XCMP_BASE                   EPWM5XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM5DE_BASE
    #define EPWM5DE_BASE                     EPWM5DE_BASE_FRAME(0U)
#endif
#ifndef EPWM5MINDBLUT_BASE
    #define EPWM5MINDBLUT_BASE               EPWM5MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM6_BASE
    #define EPWM6_BASE                       EPWM6_BASE_FRAME(0U)
#endif
#ifndef EPWM6XCMP_BASE
    #define EPWM6XCMP_BASE                   EPWM6XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM6DE_BASE
    #define EPWM6DE_BASE                     EPWM6DE_BASE_FRAME(0U)
#endif
#ifndef EPWM6MINDBLUT_BASE
    #define EPWM6MINDBLUT_BASE               EPWM6MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM7_BASE
    #define EPWM7_BASE                       EPWM7_BASE_FRAME(0U)
#endif
#ifndef EPWM7XCMP_BASE
    #define EPWM7XCMP_BASE                   EPWM7XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM7DE_BASE
    #define EPWM7DE_BASE                     EPWM7DE_BASE_FRAME(0U)
#endif
#ifndef EPWM7MINDBLUT_BASE
    #define EPWM7MINDBLUT_BASE               EPWM7MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM8_BASE
    #define EPWM8_BASE                       EPWM8_BASE_FRAME(0U)
#endif
#ifndef EPWM8XCMP_BASE
    #define EPWM8XCMP_BASE                   EPWM8XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM8DE_BASE
    #define EPWM8DE_BASE                     EPWM8DE_BASE_FRAME(0U)
#endif
#ifndef EPWM8MINDBLUT_BASE
    #define EPWM8MINDBLUT_BASE               EPWM8MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM9_BASE
    #define EPWM9_BASE                       EPWM9_BASE_FRAME(0U)
#endif
#ifndef EPWM9XCMP_BASE
    #define EPWM9XCMP_BASE                   EPWM9XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM9DE_BASE
    #define EPWM9DE_BASE                     EPWM9DE_BASE_FRAME(0U)
#endif
#ifndef EPWM9MINDBLUT_BASE
    #define EPWM9MINDBLUT_BASE               EPWM9MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM10_BASE
    #define EPWM10_BASE                      EPWM10_BASE_FRAME(0U)
#endif
#ifndef EPWM10XCMP_BASE
    #define EPWM10XCMP_BASE                  EPWM10XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM10DE_BASE
    #define EPWM10DE_BASE                    EPWM10DE_BASE_FRAME(0U)
#endif
#ifndef EPWM10MINDBLUT_BASE
    #define EPWM10MINDBLUT_BASE              EPWM10MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM11_BASE
    #define EPWM11_BASE                      EPWM11_BASE_FRAME(0U)
#endif
#ifndef EPWM11XCMP_BASE
    #define EPWM11XCMP_BASE                  EPWM11XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM11DE_BASE
    #define EPWM11DE_BASE                    EPWM11DE_BASE_FRAME(0U)
#endif
#ifndef EPWM11MINDBLUT_BASE
    #define EPWM11MINDBLUT_BASE              EPWM11MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM12_BASE
    #define EPWM12_BASE                      EPWM12_BASE_FRAME(0U)
#endif
#ifndef EPWM12XCMP_BASE
    #define EPWM12XCMP_BASE                  EPWM12XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM12DE_BASE
    #define EPWM12DE_BASE                    EPWM12DE_BASE_FRAME(0U)
#endif
#ifndef EPWM12MINDBLUT_BASE
    #define EPWM12MINDBLUT_BASE              EPWM12MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM13_BASE
    #define EPWM13_BASE                      EPWM13_BASE_FRAME(0U)
#endif
#ifndef EPWM13XCMP_BASE
    #define EPWM13XCMP_BASE                  EPWM13XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM13DE_BASE
    #define EPWM13DE_BASE                    EPWM13DE_BASE_FRAME(0U)
#endif
#ifndef EPWM13MINDBLUT_BASE
    #define EPWM13MINDBLUT_BASE              EPWM13MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM14_BASE
    #define EPWM14_BASE                      EPWM14_BASE_FRAME(0U)
#endif
#ifndef EPWM14XCMP_BASE
    #define EPWM14XCMP_BASE                  EPWM14XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM14DE_BASE
    #define EPWM14DE_BASE                    EPWM14DE_BASE_FRAME(0U)
#endif
#ifndef EPWM14MINDBLUT_BASE
    #define EPWM14MINDBLUT_BASE              EPWM14MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM15_BASE
    #define EPWM15_BASE                      EPWM15_BASE_FRAME(0U)
#endif
#ifndef EPWM15XCMP_BASE
    #define EPWM15XCMP_BASE                  EPWM15XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM15DE_BASE
    #define EPWM15DE_BASE                    EPWM15DE_BASE_FRAME(0U)
#endif
#ifndef EPWM15MINDBLUT_BASE
    #define EPWM15MINDBLUT_BASE              EPWM15MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM16_BASE
    #define EPWM16_BASE                      EPWM16_BASE_FRAME(0U)
#endif
#ifndef EPWM16XCMP_BASE
    #define EPWM16XCMP_BASE                  EPWM16XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM16DE_BASE
    #define EPWM16DE_BASE                    EPWM16DE_BASE_FRAME(0U)
#endif
#ifndef EPWM16MINDBLUT_BASE
    #define EPWM16MINDBLUT_BASE              EPWM16MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM17_BASE
    #define EPWM17_BASE                      EPWM17_BASE_FRAME(0U)
#endif
#ifndef EPWM17XCMP_BASE
    #define EPWM17XCMP_BASE                  EPWM17XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM17DE_BASE
    #define EPWM17DE_BASE                    EPWM17DE_BASE_FRAME(0U)
#endif
#ifndef EPWM17MINDBLUT_BASE
    #define EPWM17MINDBLUT_BASE              EPWM17MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM18_BASE
    #define EPWM18_BASE                      EPWM18_BASE_FRAME(0U)
#endif
#ifndef EPWM18XCMP_BASE
    #define EPWM18XCMP_BASE                  EPWM18XCMP_BASE_FRAME(0U)
#endif
#ifndef EPWM18DE_BASE
    #define EPWM18DE_BASE                    EPWM18DE_BASE_FRAME(0U)
#endif
#ifndef EPWM18MINDBLUT_BASE
    #define EPWM18MINDBLUT_BASE              EPWM18MINDBLUT_BASE_FRAME(0U)
#endif
#ifndef EPWM1XLINK_BASE
    #define EPWM1XLINK_BASE                  EPWM1XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM1XCMPXLINK_BASE
    #define EPWM1XCMPXLINK_BASE              EPWM1XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM1DEXLINK_BASE
    #define EPWM1DEXLINK_BASE                EPWM1DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM1MINDBLUTXLINK_BASE
    #define EPWM1MINDBLUTXLINK_BASE          EPWM1MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM2XLINK_BASE
    #define EPWM2XLINK_BASE                  EPWM2XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM2XCMPXLINK_BASE
    #define EPWM2XCMPXLINK_BASE              EPWM2XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM2DEXLINK_BASE
    #define EPWM2DEXLINK_BASE                EPWM2DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM2MINDBLUTXLINK_BASE
    #define EPWM2MINDBLUTXLINK_BASE          EPWM2MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM3XLINK_BASE
    #define EPWM3XLINK_BASE                  EPWM3XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM3XCMPXLINK_BASE
    #define EPWM3XCMPXLINK_BASE              EPWM3XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM3DEXLINK_BASE
    #define EPWM3DEXLINK_BASE                EPWM3DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM3MINDBLUTXLINK_BASE
    #define EPWM3MINDBLUTXLINK_BASE          EPWM3MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM4XLINK_BASE
    #define EPWM4XLINK_BASE                  EPWM4XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM4XCMPXLINK_BASE
    #define EPWM4XCMPXLINK_BASE              EPWM4XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM4DEXLINK_BASE
    #define EPWM4DEXLINK_BASE                EPWM4DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM4MINDBLUTXLINK_BASE
    #define EPWM4MINDBLUTXLINK_BASE          EPWM4MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM5XLINK_BASE
    #define EPWM5XLINK_BASE                  EPWM5XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM5XCMPXLINK_BASE
    #define EPWM5XCMPXLINK_BASE              EPWM5XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM5DEXLINK_BASE
    #define EPWM5DEXLINK_BASE                EPWM5DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM5MINDBLUTXLINK_BASE
    #define EPWM5MINDBLUTXLINK_BASE          EPWM5MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM6XLINK_BASE
    #define EPWM6XLINK_BASE                  EPWM6XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM6XCMPXLINK_BASE
    #define EPWM6XCMPXLINK_BASE              EPWM6XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM6DEXLINK_BASE
    #define EPWM6DEXLINK_BASE                EPWM6DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM6MINDBLUTXLINK_BASE
    #define EPWM6MINDBLUTXLINK_BASE          EPWM6MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM7XLINK_BASE
    #define EPWM7XLINK_BASE                  EPWM7XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM7XCMPXLINK_BASE
    #define EPWM7XCMPXLINK_BASE              EPWM7XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM7DEXLINK_BASE
    #define EPWM7DEXLINK_BASE                EPWM7DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM7MINDBLUTXLINK_BASE
    #define EPWM7MINDBLUTXLINK_BASE          EPWM7MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM8XLINK_BASE
    #define EPWM8XLINK_BASE                  EPWM8XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM8XCMPXLINK_BASE
    #define EPWM8XCMPXLINK_BASE              EPWM8XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM8DEXLINK_BASE
    #define EPWM8DEXLINK_BASE                EPWM8DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM8MINDBLUTXLINK_BASE
    #define EPWM8MINDBLUTXLINK_BASE          EPWM8MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM9XLINK_BASE
    #define EPWM9XLINK_BASE                  EPWM9XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM9XCMPXLINK_BASE
    #define EPWM9XCMPXLINK_BASE              EPWM9XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM9DEXLINK_BASE
    #define EPWM9DEXLINK_BASE                EPWM9DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM9MINDBLUTXLINK_BASE
    #define EPWM9MINDBLUTXLINK_BASE          EPWM9MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM10XLINK_BASE
    #define EPWM10XLINK_BASE                 EPWM10XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM10XCMPXLINK_BASE
    #define EPWM10XCMPXLINK_BASE             EPWM10XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM10DEXLINK_BASE
    #define EPWM10DEXLINK_BASE               EPWM10DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM10MINDBLUTXLINK_BASE
    #define EPWM10MINDBLUTXLINK_BASE         EPWM10MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM11XLINK_BASE
    #define EPWM11XLINK_BASE                 EPWM11XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM11XCMPXLINK_BASE
    #define EPWM11XCMPXLINK_BASE             EPWM11XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM11DEXLINK_BASE
    #define EPWM11DEXLINK_BASE               EPWM11DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM11MINDBLUTXLINK_BASE
    #define EPWM11MINDBLUTXLINK_BASE         EPWM11MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM12XLINK_BASE
    #define EPWM12XLINK_BASE                 EPWM12XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM12XCMPXLINK_BASE
    #define EPWM12XCMPXLINK_BASE             EPWM12XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM12DEXLINK_BASE
    #define EPWM12DEXLINK_BASE               EPWM12DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM12MINDBLUTXLINK_BASE
    #define EPWM12MINDBLUTXLINK_BASE         EPWM12MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM13XLINK_BASE
    #define EPWM13XLINK_BASE                 EPWM13XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM13XCMPXLINK_BASE
    #define EPWM13XCMPXLINK_BASE             EPWM13XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM13DEXLINK_BASE
    #define EPWM13DEXLINK_BASE               EPWM13DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM13MINDBLUTXLINK_BASE
    #define EPWM13MINDBLUTXLINK_BASE         EPWM13MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM14XLINK_BASE
    #define EPWM14XLINK_BASE                 EPWM14XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM14XCMPXLINK_BASE
    #define EPWM14XCMPXLINK_BASE             EPWM14XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM14DEXLINK_BASE
    #define EPWM14DEXLINK_BASE               EPWM14DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM14MINDBLUTXLINK_BASE
    #define EPWM14MINDBLUTXLINK_BASE         EPWM14MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM15XLINK_BASE
    #define EPWM15XLINK_BASE                 EPWM15XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM15XCMPXLINK_BASE
    #define EPWM15XCMPXLINK_BASE             EPWM15XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM15DEXLINK_BASE
    #define EPWM15DEXLINK_BASE               EPWM15DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM15MINDBLUTXLINK_BASE
    #define EPWM15MINDBLUTXLINK_BASE         EPWM15MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM16XLINK_BASE
    #define EPWM16XLINK_BASE                 EPWM16XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM16XCMPXLINK_BASE
    #define EPWM16XCMPXLINK_BASE             EPWM16XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM16DEXLINK_BASE
    #define EPWM16DEXLINK_BASE               EPWM16DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM16MINDBLUTXLINK_BASE
    #define EPWM16MINDBLUTXLINK_BASE         EPWM16MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM17XLINK_BASE
    #define EPWM17XLINK_BASE                 EPWM17XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM17XCMPXLINK_BASE
    #define EPWM17XCMPXLINK_BASE             EPWM17XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM17DEXLINK_BASE
    #define EPWM17DEXLINK_BASE               EPWM17DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM17MINDBLUTXLINK_BASE
    #define EPWM17MINDBLUTXLINK_BASE         EPWM17MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM18XLINK_BASE
    #define EPWM18XLINK_BASE                 EPWM18XLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM18XCMPXLINK_BASE
    #define EPWM18XCMPXLINK_BASE             EPWM18XCMPXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM18DEXLINK_BASE
    #define EPWM18DEXLINK_BASE               EPWM18DEXLINK_BASE_FRAME(0U)
#endif
#ifndef EPWM18MINDBLUTXLINK_BASE
    #define EPWM18MINDBLUTXLINK_BASE         EPWM18MINDBLUTXLINK_BASE_FRAME(0U)
#endif
#ifndef HRPWMCAL1_BASE
    #define HRPWMCAL1_BASE                   HRPWMCAL1_BASE_FRAME(0U)
#endif
#ifndef HRPWMCAL2_BASE
    #define HRPWMCAL2_BASE                   HRPWMCAL2_BASE_FRAME(0U)
#endif
#ifndef HRPWMCAL3_BASE
    #define HRPWMCAL3_BASE                   HRPWMCAL3_BASE_FRAME(0U)
#endif
#ifndef EQEP1_BASE
    #define EQEP1_BASE                       EQEP1_BASE_FRAME(0U)
#endif
#ifndef EQEP2_BASE
    #define EQEP2_BASE                       EQEP2_BASE_FRAME(0U)
#endif
#ifndef EQEP3_BASE
    #define EQEP3_BASE                       EQEP3_BASE_FRAME(0U)
#endif
#ifndef EQEP4_BASE
    #define EQEP4_BASE                       EQEP4_BASE_FRAME(0U)
#endif
#ifndef EQEP5_BASE
    #define EQEP5_BASE                       EQEP5_BASE_FRAME(0U)
#endif
#ifndef EQEP6_BASE
    #define EQEP6_BASE                       EQEP6_BASE_FRAME(0U)
#endif
#ifndef SDFM1_BASE
    #define SDFM1_BASE                       SDFM1_BASE_FRAME(0U)
#endif
#ifndef SDFM2_BASE
    #define SDFM2_BASE                       SDFM2_BASE_FRAME(0U)
#endif
#ifndef SDFM3_BASE
    #define SDFM3_BASE                       SDFM3_BASE_FRAME(0U)
#endif
#ifndef SDFM4_BASE
    #define SDFM4_BASE                       SDFM4_BASE_FRAME(0U)
#endif
#ifndef ADCA_BASE
    #define ADCA_BASE                        ADCA_BASE_FRAME(0U)
#endif
#ifndef ADCB_BASE
    #define ADCB_BASE                        ADCB_BASE_FRAME(0U)
#endif
#ifndef ADCC_BASE
    #define ADCC_BASE                        ADCC_BASE_FRAME(0U)
#endif
#ifndef ADCD_BASE
    #define ADCD_BASE                        ADCD_BASE_FRAME(0U)
#endif
#ifndef ADCE_BASE
    #define ADCE_BASE                        ADCE_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK1_BASE
    #define ADCSAFETYCHECK1_BASE             ADCSAFETYCHECK1_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK2_BASE
    #define ADCSAFETYCHECK2_BASE             ADCSAFETYCHECK2_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK3_BASE
    #define ADCSAFETYCHECK3_BASE             ADCSAFETYCHECK3_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK4_BASE
    #define ADCSAFETYCHECK4_BASE             ADCSAFETYCHECK4_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK5_BASE
    #define ADCSAFETYCHECK5_BASE             ADCSAFETYCHECK5_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK6_BASE
    #define ADCSAFETYCHECK6_BASE             ADCSAFETYCHECK6_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK7_BASE
    #define ADCSAFETYCHECK7_BASE             ADCSAFETYCHECK7_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK8_BASE
    #define ADCSAFETYCHECK8_BASE             ADCSAFETYCHECK8_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK9_BASE
    #define ADCSAFETYCHECK9_BASE             ADCSAFETYCHECK9_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECK10_BASE
    #define ADCSAFETYCHECK10_BASE            ADCSAFETYCHECK10_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECKINTEVT1_BASE
    #define ADCSAFETYCHECKINTEVT1_BASE       ADCSAFETYCHECKINTEVT1_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECKINTEVT2_BASE
    #define ADCSAFETYCHECKINTEVT2_BASE       ADCSAFETYCHECKINTEVT2_BASE_FRAME(0U)
#endif
#ifndef ADCSAFETYCHECKINTEVT3_BASE
    #define ADCSAFETYCHECKINTEVT3_BASE       ADCSAFETYCHECKINTEVT3_BASE_FRAME(0U)
#endif
#ifndef ADCGLOBAL_BASE
    #define ADCGLOBAL_BASE                   ADCGLOBAL_BASE_FRAME(0U)
#endif
#ifndef DACA_BASE
    #define DACA_BASE                        DACA_BASE_FRAME(0U)
#endif
#ifndef DACB_BASE
    #define DACB_BASE                        DACB_BASE_FRAME(0U)
#endif
#ifndef CMPSS1_BASE
    #define CMPSS1_BASE                      CMPSS1_BASE_FRAME(0U)
#endif
#ifndef CMPSS2_BASE
    #define CMPSS2_BASE                      CMPSS2_BASE_FRAME(0U)
#endif
#ifndef CMPSS3_BASE
    #define CMPSS3_BASE                      CMPSS3_BASE_FRAME(0U)
#endif
#ifndef CMPSS4_BASE
    #define CMPSS4_BASE                      CMPSS4_BASE_FRAME(0U)
#endif
#ifndef CMPSS5_BASE
    #define CMPSS5_BASE                      CMPSS5_BASE_FRAME(0U)
#endif
#ifndef CMPSS6_BASE
    #define CMPSS6_BASE                      CMPSS6_BASE_FRAME(0U)
#endif
#ifndef CMPSS7_BASE
    #define CMPSS7_BASE                      CMPSS7_BASE_FRAME(0U)
#endif
#ifndef CMPSS8_BASE
    #define CMPSS8_BASE                      CMPSS8_BASE_FRAME(0U)
#endif
#ifndef CMPSS9_BASE
    #define CMPSS9_BASE                      CMPSS9_BASE_FRAME(0U)
#endif
#ifndef CMPSS10_BASE
    #define CMPSS10_BASE                     CMPSS10_BASE_FRAME(0U)
#endif
#ifndef CMPSS11_BASE
    #define CMPSS11_BASE                     CMPSS11_BASE_FRAME(0U)
#endif
#ifndef CMPSS12_BASE
    #define CMPSS12_BASE                     CMPSS12_BASE_FRAME(0U)
#endif
#ifndef ECAP1_BASE
    #define ECAP1_BASE                       ECAP1_BASE_FRAME(0U)
#endif
#ifndef ECAP1SIGNALMONITORING_BASE
    #define ECAP1SIGNALMONITORING_BASE       ECAP1SIGNALMONITORING_BASE_FRAME(0U)
#endif
#ifndef ECAP2_BASE
    #define ECAP2_BASE                       ECAP2_BASE_FRAME(0U)
#endif
#ifndef ECAP2SIGNALMONITORING_BASE
    #define ECAP2SIGNALMONITORING_BASE       ECAP2SIGNALMONITORING_BASE_FRAME(0U)
#endif
#ifndef ECAP3_BASE
    #define ECAP3_BASE                       ECAP3_BASE_FRAME(0U)
#endif
#ifndef ECAP3SIGNALMONITORING_BASE
    #define ECAP3SIGNALMONITORING_BASE       ECAP3SIGNALMONITORING_BASE_FRAME(0U)
#endif
#ifndef ECAP4_BASE
    #define ECAP4_BASE                       ECAP4_BASE_FRAME(0U)
#endif
#ifndef ECAP4SIGNALMONITORING_BASE
    #define ECAP4SIGNALMONITORING_BASE       ECAP4SIGNALMONITORING_BASE_FRAME(0U)
#endif
#ifndef ECAP5_BASE
    #define ECAP5_BASE                       ECAP5_BASE_FRAME(0U)
#endif
#ifndef HRCAP5_BASE
    #define HRCAP5_BASE                      HRCAP5_BASE_FRAME(0U)
#endif
#ifndef ECAP5SIGNALMONITORING_BASE
    #define ECAP5SIGNALMONITORING_BASE       ECAP5SIGNALMONITORING_BASE_FRAME(0U)
#endif
#ifndef ECAP6_BASE
    #define ECAP6_BASE                       ECAP6_BASE_FRAME(0U)
#endif
#ifndef HRCAP6_BASE
    #define HRCAP6_BASE                      HRCAP6_BASE_FRAME(0U)
#endif
#ifndef ECAP6SIGNALMONITORING_BASE
    #define ECAP6SIGNALMONITORING_BASE       ECAP6SIGNALMONITORING_BASE_FRAME(0U)
#endif
#ifndef CLB1_BASE
    #define CLB1_BASE                        CLB1_BASE_FRAME(0U)
#endif
#ifndef CLB1_LOGICCFG_BASE
    #define CLB1_LOGICCFG_BASE               CLB1_LOGICCFG_BASE_FRAME(0U)
#endif
#ifndef CLB1_LOGICCTRL_BASE
    #define CLB1_LOGICCTRL_BASE              CLB1_LOGICCTRL_BASE_FRAME(0U)
#endif
#ifndef CLB1_DATAEXCH_BASE
    #define CLB1_DATAEXCH_BASE               CLB1_DATAEXCH_BASE_FRAME(0U)
#endif
#ifndef CLB2_BASE
    #define CLB2_BASE                        CLB2_BASE_FRAME(0U)
#endif
#ifndef CLB2_LOGICCFG_BASE
    #define CLB2_LOGICCFG_BASE               CLB2_LOGICCFG_BASE_FRAME(0U)
#endif
#ifndef CLB2_LOGICCTRL_BASE
    #define CLB2_LOGICCTRL_BASE              CLB2_LOGICCTRL_BASE_FRAME(0U)
#endif
#ifndef CLB2_DATAEXCH_BASE
    #define CLB2_DATAEXCH_BASE               CLB2_DATAEXCH_BASE_FRAME(0U)
#endif
#ifndef CLB3_BASE
    #define CLB3_BASE                        CLB3_BASE_FRAME(0U)
#endif
#ifndef CLB3_LOGICCFG_BASE
    #define CLB3_LOGICCFG_BASE               CLB3_LOGICCFG_BASE_FRAME(0U)
#endif
#ifndef CLB3_LOGICCTRL_BASE
    #define CLB3_LOGICCTRL_BASE              CLB3_LOGICCTRL_BASE_FRAME(0U)
#endif
#ifndef CLB3_DATAEXCH_BASE
    #define CLB3_DATAEXCH_BASE               CLB3_DATAEXCH_BASE_FRAME(0U)
#endif
#ifndef CLB4_BASE
    #define CLB4_BASE                        CLB4_BASE_FRAME(0U)
#endif
#ifndef CLB4_LOGICCFG_BASE
    #define CLB4_LOGICCFG_BASE               CLB4_LOGICCFG_BASE_FRAME(0U)
#endif
#ifndef CLB4_LOGICCTRL_BASE
    #define CLB4_LOGICCTRL_BASE              CLB4_LOGICCTRL_BASE_FRAME(0U)
#endif
#ifndef CLB4_DATAEXCH_BASE
    #define CLB4_DATAEXCH_BASE               CLB4_DATAEXCH_BASE_FRAME(0U)
#endif
#ifndef CLB5_BASE
    #define CLB5_BASE                        CLB5_BASE_FRAME(0U)
#endif
#ifndef CLB5_LOGICCFG_BASE
    #define CLB5_LOGICCFG_BASE               CLB5_LOGICCFG_BASE_FRAME(0U)
#endif
#ifndef CLB5_LOGICCTRL_BASE
    #define CLB5_LOGICCTRL_BASE              CLB5_LOGICCTRL_BASE_FRAME(0U)
#endif
#ifndef CLB5_DATAEXCH_BASE
    #define CLB5_DATAEXCH_BASE               CLB5_DATAEXCH_BASE_FRAME(0U)
#endif
#ifndef CLB6_BASE
    #define CLB6_BASE                        CLB6_BASE_FRAME(0U)
#endif
#ifndef CLB6_LOGICCFG_BASE
    #define CLB6_LOGICCFG_BASE               CLB6_LOGICCFG_BASE_FRAME(0U)
#endif
#ifndef CLB6_LOGICCTRL_BASE
    #define CLB6_LOGICCTRL_BASE              CLB6_LOGICCTRL_BASE_FRAME(0U)
#endif
#ifndef CLB6_DATAEXCH_BASE
    #define CLB6_DATAEXCH_BASE               CLB6_DATAEXCH_BASE_FRAME(0U)
#endif
#ifndef PMBUSA_BASE
    #define PMBUSA_BASE                      PMBUSA_BASE_FRAME(0U)
#endif
#ifndef I2CA_BASE
    #define I2CA_BASE                        I2CA_BASE_FRAME(0U)
#endif
#ifndef I2CB_BASE
    #define I2CB_BASE                        I2CB_BASE_FRAME(0U)
#endif
#ifndef SPIA_BASE
    #define SPIA_BASE                        SPIA_BASE_FRAME(0U)
#endif
#ifndef SPIB_BASE
    #define SPIB_BASE                        SPIB_BASE_FRAME(0U)
#endif
#ifndef SPIC_BASE
    #define SPIC_BASE                        SPIC_BASE_FRAME(0U)
#endif
#ifndef SPID_BASE
    #define SPID_BASE                        SPID_BASE_FRAME(0U)
#endif
#ifndef SPIE_BASE
    #define SPIE_BASE                        SPIE_BASE_FRAME(0U)
#endif
#ifndef FSITXA_BASE
    #define FSITXA_BASE                      FSITXA_BASE_FRAME(0U)
#endif
#ifndef FSITXB_BASE
    #define FSITXB_BASE                      FSITXB_BASE_FRAME(0U)
#endif
#ifndef FSITXC_BASE
    #define FSITXC_BASE                      FSITXC_BASE_FRAME(0U)
#endif
#ifndef FSITXD_BASE
    #define FSITXD_BASE                      FSITXD_BASE_FRAME(0U)
#endif
#ifndef FSIRXA_BASE
    #define FSIRXA_BASE                      FSIRXA_BASE_FRAME(0U)
#endif
#ifndef FSIRXB_BASE
    #define FSIRXB_BASE                      FSIRXB_BASE_FRAME(0U)
#endif
#ifndef FSIRXC_BASE
    #define FSIRXC_BASE                      FSIRXC_BASE_FRAME(0U)
#endif
#ifndef FSIRXD_BASE
    #define FSIRXD_BASE                      FSIRXD_BASE_FRAME(0U)
#endif
#ifndef EPG_BASE
    #define EPG_BASE                         EPG_BASE_FRAME(0U)
#endif
#ifndef EPGMUX_BASE
    #define EPGMUX_BASE                      EPGMUX_BASE_FRAME(0U)
#endif

#define BASE_ADDR_MASK   0xFF3FFFFFU

#endif
