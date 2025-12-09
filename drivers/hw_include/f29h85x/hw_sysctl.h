//###########################################################################
//
// FILE:    hw_sysctl.h
//
// TITLE:   Definitions for the SYSCTL registers.
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

#ifndef HW_SYSCTL_H
#define HW_SYSCTL_H

//*************************************************************************************************
//
// The following are defines for the SYSCTL register offsets
//
//*************************************************************************************************
#define SYSCTL_O_DEVCFGLOCK1                 0x0U     // Lock bit for PERxSYSCONFIG0-31 registers
#define SYSCTL_O_DEVCFGLOCK2                 0x4U     // Lock bit for DEVCFG registers
#define SYSCTL_O_DEVCFGLOCK3                 0x8U     // Lock bit for PERxSYSCONFIG32-63 registers
#define SYSCTL_O_DEVCFGLOCK4                 0xCU     // Lock bit for PERxSYSCONFIG64-95 registers
#define SYSCTL_O_DEVCFGLOCK5                 0x10U    // Lock bit for PERxSYSCONFIG96-127 registers
#define SYSCTL_O_PARTIDL                     0x20U    // Lower 32-bit of Device PART Identification
                                                      // Number
#define SYSCTL_O_PARTIDH                     0x24U    // Upper 32-bit of Device PART Identification
                                                      // Number
#define SYSCTL_O_REVID                       0x28U    // Device Revision Number
#define SYSCTL_O_MCUCNF1                     0x1C0U   // MCUCNF Capability: EMIF Customization
#define SYSCTL_O_MCUCNF2                     0x1C4U   // MCUCNF Capability: EPWM
#define SYSCTL_O_MCUCNF4                     0x1CCU   // MCUCNF Capability: EQEP
#define SYSCTL_O_MCUCNF7                     0x1D8U   // MCUCNF Capability: UART
#define SYSCTL_O_MCUCNF10                    0x1E4U   // MCUCNF Capability: CAN, MCAN
#define SYSCTL_O_MCUCNF13                    0x1F0U   // MCUCNF Capability: AMCUCNF
#define SYSCTL_O_MCUCNF14                    0x1F4U   // MCUCNF Capability: CMPSS
#define SYSCTL_O_MCUCNF16                    0x1FCU   // MCUCNF Capability: DAC
#define SYSCTL_O_MCUCNF17                    0x200U   // MCUCNF Capability: CLB
#define SYSCTL_O_MCUCNF18                    0x204U   // MCUCNF Capability: FSI
#define SYSCTL_O_MCUCNF19                    0x208U   // MCUCNF Capability: LIN
#define SYSCTL_O_MCUCNF23                    0x218U   // MCUCNF Capability: EtherCAT
#define SYSCTL_O_MCUCNF26                    0x224U   // Device Capability: HSM-Crypto Engines AES,
                                                      // SHA, PKA, TRNG
#define SYSCTL_O_MCUCNF31                    0x238U   // Device Capability: HSM-Crypto Engines SM2,
                                                      // SM3, SM4
#define SYSCTL_O_MCUCNF64                    0x2BCU   // MCUCNF Capability: MCUCNF level,
                                                      // Processing Block, RTDMA Customization
#define SYSCTL_O_MCUCNF65                    0x2C0U   // MCUCNF Capability: On-chip SRAM
                                                      // Customization
#define SYSCTL_O_MCUCNF74                    0x2E4U   // MCUCNF Capability: FLC1.B0/B1
#define SYSCTL_O_MCUCNF76                    0x2ECU   // MCUCNF Capability: FLC1.B2/B3
#define SYSCTL_O_MCUCNF78                    0x2F4U   // MCUCNF Capability: FLC1.B4 256KB Data
                                                      // Flash
#define SYSCTL_O_MCUCNF79                    0x2F8U   // MCUCNF Capability: FLC2.B0/B1
#define SYSCTL_O_MCUCNF81                    0x300U   // MCUCNF Capability: FLC2.B2/B3
#define SYSCTL_O_MCUCNFLOCK1                 0x33CU   // Lock bit for MCUCNFx registers
#define SYSCTL_O_MCUCNFLOCK3                 0x344U   // Lock bit for MCUCNFx registers
#define SYSCTL_O_LSEN                        0x348U   // Lockstep enable configuration
#define SYSCTL_O_EPWMXLINKCFG                0x37CU   // Configure which EPWM module instaces are
                                                      // linked in the XLINK scheme
#define SYSCTL_O_SICCONFIG                   0x384U   // Safety Interconnect(SIC) Configuration -
                                                      // Enable and READY TIMEOUT value
#define SYSCTL_O_RSTSTAT                     0x3B0U   // Reset Status register for secondary CPUs
#define SYSCTL_O_LPMSTAT                     0x3B4U   // LPM Status Register for secondary CPUs
#define SYSCTL_O_TAP_STATUS                  0x3CCU   // Status of JTAG State machine & Debugger
                                                      // Connect
#define SYSCTL_O_TAP_CONTROL                 0x3D0U   // Disable TAP control
#define SYSCTL_O_DEVLIFECYCLE                0x3D4U   // Reflect the state of the Device Life Cycle
                                                      // signals reported from the HSM
#define SYSCTL_O_SDFMTYPE                    0x47CU   // Configures SDFM Type for the device
#define SYSCTL_O_SYNCSELECT                  0x4ACU   // Sync Input and Output Select Register
#define SYSCTL_O_ADCSOCOUTSELECT             0x4B0U   // External ADCSOC Select Register (PWM1-16)
#define SYSCTL_O_ADCSOCOUTSELECT1            0x4B4U   // External ADCSOC Select Register (PWM17-32)
#define SYSCTL_O_SYNCSOCLOCK                 0x4B8U   // SYNCSEL and ADCSOC Select Lock register
#define SYSCTL_O_HSMTOCPU_STS1               0x4DCU   // HSM to C29x Signal Status1
#define SYSCTL_O_HSMTOCPU_STS2               0x4E0U   // HSM to C29x Signal Status2
#define SYSCTL_O_HSM_SECURE_BOOT_INFO_REG0   0x4E4U   // Status information of the secure boot
                                                      // process HSM to CPU1
#define SYSCTL_O_HSM_SECURE_BOOT_INFO_REG1   0x4E8U   // Status information of the secure boot
                                                      // process HSM to CPU1
#define SYSCTL_O_HSM_SECURE_BOOT_INFO_REG2   0x4ECU   // Status information of the secure boot
                                                      // process HSM to CPU1
#define SYSCTL_O_HSM_SECURE_BOOT_INFO_REG3   0x4F0U   // Status information of the secure boot
                                                      // process HSM to CPU1
#define SYSCTL_O_HSM_SECURE_BOOT_INFO_REG4   0x4F4U   // Status information of the secure boot
                                                      // process HSM to CPU1
#define SYSCTL_O_HSM_SECURE_BOOT_INFO_REG5   0x4F8U   // Status information of the secure boot
                                                      // process HSM to CPU1
#define SYSCTL_O_HSM_SECURE_BOOT_INFO_REG6   0x4FCU   // Status information of the secure boot
                                                      // process HSM to CPU1
#define SYSCTL_O_HSM_SECURE_BOOT_INFO_REG7   0x500U   // Status information of the secure boot
                                                      // process HSM to CPU1
#define SYSCTL_O_SOC_SECURE_BOOT_INFO_REG0   0x504U   // Status information of the secure boot
                                                      // process CPU1 to HSM
#define SYSCTL_O_SOC_SECURE_BOOT_INFO_REG1   0x508U   // Status information of the secure boot
                                                      // process CPU1 to HSM
#define SYSCTL_O_SOC_SECURE_BOOT_INFO_REG2   0x50CU   // Status information of the secure boot
                                                      // process CPU1 to HSM
#define SYSCTL_O_SOC_SECURE_BOOT_INFO_REG3   0x510U   // Status information of the secure boot
                                                      // process CPU1 to HSM
#define SYSCTL_O_SOC_SECURE_BOOT_INFO_REG4   0x514U   // Status information of the secure boot
                                                      // process CPU1 to HSM
#define SYSCTL_O_SOC_SECURE_BOOT_INFO_REG5   0x518U   // Status information of the secure boot
                                                      // process CPU1 to HSM
#define SYSCTL_O_SOC_SECURE_BOOT_INFO_REG6   0x51CU   // Status information of the secure boot
                                                      // process CPU1 to HSM
#define SYSCTL_O_SOC_SECURE_BOOT_INFO_REG7   0x520U   // Status information of the secure boot
                                                      // process CPU1 to HSM
#define SYSCTL_O_CLKCFGLOCK1                 0x524U   // Lock bit for CLKCFG registers
#define SYSCTL_O_CLKSRCCTL1                  0x530U   // Clock Source Control register-1
#define SYSCTL_O_CLKSRCCTL2                  0x534U   // Clock Source Control register-2
#define SYSCTL_O_CLKSRCCTL3                  0x538U   // Clock Source Control register-3
#define SYSCTL_O_SYSPLLCTL1                  0x53CU   // SYSPLL Control register-1
#define SYSCTL_O_SYSPLLMULT                  0x548U   // SYSPLL Multiplier register
#define SYSCTL_O_SYSPLLSTS                   0x54CU   // SYSPLL Status register
#define SYSCTL_O_SYSCLKDIVSEL                0x564U   // System Clock Divider Select register
#define SYSCTL_O_PERCLKDIVSEL                0x56CU   // Peripheral Clock Divider Select register
#define SYSCTL_O_XCLKOUTDIVSEL               0x570U   // XCLKOUT Divider Select register
#define SYSCTL_O_HSMCLKDIVSEL                0x574U   // HSM SYSCLK Divider Select register
#define SYSCTL_O_MCANCLKDIVSEL               0x578U   // MCAN Bit Clock Divider Select register
#define SYSCTL_O_CLBCLKCTL                   0x57CU   // CLB Clocking Control Register
#define SYSCTL_O_MCDCR                       0x584U   // Missing Clock Detect Control Register
#define SYSCTL_O_X1CNT                       0x588U   // 10-bit Counter on X1 Clock
#define SYSCTL_O_XTALCR                      0x58CU   // XTAL Control Register
#define SYSCTL_O_XTALCR2                     0x59CU   // XTAL Control Register for pad init
#define SYSCTL_O_ETHERCATCLKCTL              0x5A8U   // EtherCAT Clock Control
#define SYSCTL_O_ETHERCATCTL                 0x5ACU   // ETHERCAT control register.
#define SYSCTL_O_SYNCBUSY                    0x5B0U   // Pulse Transfer Sync Busy Status register
#define SYSCTL_O_ESMXRSNCTL                  0x5C0U   // Enable ESM reset outputs for XRSn
#define SYSCTL_O_EPWM1                       0x5C8U   // PER2SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM1
#define SYSCTL_O_EPWM2                       0x5CCU   // PER3SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM2
#define SYSCTL_O_EPWM3                       0x5D0U   // PER4SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM3
#define SYSCTL_O_EPWM4                       0x5D4U   // PER5SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM4
#define SYSCTL_O_EPWM5                       0x5D8U   // PER6SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM5
#define SYSCTL_O_EPWM6                       0x5DCU   // PER7SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM6
#define SYSCTL_O_EPWM7                       0x5E0U   // PER8SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM7
#define SYSCTL_O_EPWM8                       0x5E4U   // PER9SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM8
#define SYSCTL_O_EPWM9                       0x5E8U   // PER10SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM9
#define SYSCTL_O_EPWM10                      0x5ECU   // PER11SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM10
#define SYSCTL_O_EPWM11                      0x5F0U   // PER12SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM11
#define SYSCTL_O_EPWM12                      0x5F4U   // PER13SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM12
#define SYSCTL_O_EPWM13                      0x5F8U   // PER14SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM13
#define SYSCTL_O_EPWM14                      0x5FCU   // PER15SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM14
#define SYSCTL_O_EPWM15                      0x600U   // PER16SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM15
#define SYSCTL_O_EPWM16                      0x604U   // PER17SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM16
#define SYSCTL_O_EPWM17                      0x608U   // PER18SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM17
#define SYSCTL_O_EPWM18                      0x60CU   // PER19SYSCONFIG -  Peripheral System
                                                      // Configuration for EPWM18
#define SYSCTL_O_HRCAL0                      0x614U   // PER21SYSCONFIG -  Peripheral System
                                                      // Configuration for HRCAL0
#define SYSCTL_O_HRCAL1                      0x618U   // PER22SYSCONFIG -  Peripheral System
                                                      // Configuration for HRCAL1
#define SYSCTL_O_HRCAL2                      0x61CU   // PER23SYSCONFIG -  Peripheral System
                                                      // Configuration for HRCAL2
#define SYSCTL_O_ECAP1                       0x620U   // PER24SYSCONFIG -  Peripheral System
                                                      // Configuration for ECAP1
#define SYSCTL_O_ECAP2                       0x624U   // PER25SYSCONFIG -  Peripheral System
                                                      // Configuration for ECAP2
#define SYSCTL_O_ECAP3                       0x628U   // PER26SYSCONFIG -  Peripheral System
                                                      // Configuration for ECAP3
#define SYSCTL_O_ECAP4                       0x62CU   // PER27SYSCONFIG -  Peripheral System
                                                      // Configuration for ECAP4
#define SYSCTL_O_ECAP5                       0x630U   // PER28SYSCONFIG -  Peripheral System
                                                      // Configuration for ECAP5
#define SYSCTL_O_ECAP6                       0x634U   // PER29SYSCONFIG -  Peripheral System
                                                      // Configuration for ECAP6
#define SYSCTL_O_EQEP1                       0x638U   // PER30SYSCONFIG -  Peripheral System
                                                      // Configuration for EQEP1
#define SYSCTL_O_EQEP2                       0x63CU   // PER31SYSCONFIG -  Peripheral System
                                                      // Configuration for EQEP2
#define SYSCTL_O_EQEP3                       0x640U   // PER32SYSCONFIG -  Peripheral System
                                                      // Configuration for EQEP3
#define SYSCTL_O_EQEP4                       0x644U   // PER33SYSCONFIG -  Peripheral System
                                                      // Configuration for EQEP4
#define SYSCTL_O_EQEP5                       0x648U   // PER34SYSCONFIG -  Peripheral System
                                                      // Configuration for EQEP5
#define SYSCTL_O_EQEP6                       0x64CU   // PER35SYSCONFIG -  Peripheral System
                                                      // Configuration for EQEP6
#define SYSCTL_O_SDFM1                       0x650U   // PER36SYSCONFIG -  Peripheral System
                                                      // Configuration for SDFM1
#define SYSCTL_O_SDFM2                       0x654U   // PER37SYSCONFIG -  Peripheral System
                                                      // Configuration for SDFM2
#define SYSCTL_O_SDFM3                       0x658U   // PER38SYSCONFIG -  Peripheral System
                                                      // Configuration for SDFM3
#define SYSCTL_O_SDFM4                       0x65CU   // PER39SYSCONFIG -  Peripheral System
                                                      // Configuration for SDFM4
#define SYSCTL_O_UARTA                       0x660U   // PER40SYSCONFIG -  Peripheral System
                                                      // Configuration for UARTA
#define SYSCTL_O_UARTB                       0x664U   // PER41SYSCONFIG -  Peripheral System
                                                      // Configuration for UARTB
#define SYSCTL_O_UARTC                       0x668U   // PER42SYSCONFIG -  Peripheral System
                                                      // Configuration for UARTC
#define SYSCTL_O_UARTD                       0x66CU   // PER43SYSCONFIG -  Peripheral System
                                                      // Configuration for UARTD
#define SYSCTL_O_UARTE                       0x670U   // PER44SYSCONFIG -  Peripheral System
                                                      // Configuration for UARTE
#define SYSCTL_O_UARTF                       0x674U   // PER45SYSCONFIG -  Peripheral System
                                                      // Configuration for UARTF
#define SYSCTL_O_SPIA                        0x678U   // PER46SYSCONFIG -  Peripheral System
                                                      // Configuration for SPIA
#define SYSCTL_O_SPIB                        0x67CU   // PER47SYSCONFIG -  Peripheral System
                                                      // Configuration for SPIB
#define SYSCTL_O_SPIC                        0x680U   // PER48SYSCONFIG -  Peripheral System
                                                      // Configuration for SPIC
#define SYSCTL_O_SPID                        0x684U   // PER49SYSCONFIG -  Peripheral System
                                                      // Configuration for SPID
#define SYSCTL_O_SPIE                        0x688U   // PER50SYSCONFIG -  Peripheral System
                                                      // Configuration for SPIE
#define SYSCTL_O_I2CA                        0x68CU   // PER51SYSCONFIG -  Peripheral System
                                                      // Configuration for I2CA
#define SYSCTL_O_I2CB                        0x690U   // PER52SYSCONFIG -  Peripheral System
                                                      // Configuration for I2CB
#define SYSCTL_O_PMBUSA                      0x694U   // PER53SYSCONFIG -  Peripheral System
                                                      // Configuration for PMBUSA
#define SYSCTL_O_LINA                        0x698U   // PER54SYSCONFIG -  Peripheral System
                                                      // Configuration for LINA
#define SYSCTL_O_LINB                        0x69CU   // PER55SYSCONFIG -  Peripheral System
                                                      // Configuration for LINB
#define SYSCTL_O_MCANA                       0x6A0U   // PER56SYSCONFIG -  Peripheral System
                                                      // Configuration for MCANA
#define SYSCTL_O_MCANB                       0x6A4U   // PER57SYSCONFIG -  Peripheral System
                                                      // Configuration for MCANB
#define SYSCTL_O_MCANC                       0x6A8U   // PER58SYSCONFIG -  Peripheral System
                                                      // Configuration for MCANC
#define SYSCTL_O_MCAND                       0x6ACU   // PER59SYSCONFIG -  Peripheral System
                                                      // Configuration for MCAND
#define SYSCTL_O_MCANE                       0x6B0U   // PER60SYSCONFIG -  Peripheral System
                                                      // Configuration for MCANE
#define SYSCTL_O_MCANF                       0x6B4U   // PER61SYSCONFIG -  Peripheral System
                                                      // Configuration for MCANF
#define SYSCTL_O_ADCA                        0x6B8U   // PER62SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCA
#define SYSCTL_O_ADCB                        0x6BCU   // PER63SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCB
#define SYSCTL_O_ADCC                        0x6C0U   // PER64SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCC
#define SYSCTL_O_ADCD                        0x6C4U   // PER65SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCD
#define SYSCTL_O_ADCE                        0x6C8U   // PER66SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCE
#define SYSCTL_O_CMPSS1                      0x6CCU   // PER67SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS1
#define SYSCTL_O_CMPSS2                      0x6D0U   // PER68SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS2
#define SYSCTL_O_CMPSS3                      0x6D4U   // PER69SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS3
#define SYSCTL_O_CMPSS4                      0x6D8U   // PER70SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS4
#define SYSCTL_O_CMPSS5                      0x6DCU   // PER71SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS5
#define SYSCTL_O_CMPSS6                      0x6E0U   // PER72SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS6
#define SYSCTL_O_CMPSS7                      0x6E4U   // PER73SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS7
#define SYSCTL_O_CMPSS8                      0x6E8U   // PER74SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS8
#define SYSCTL_O_CMPSS9                      0x6ECU   // PER75SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS9
#define SYSCTL_O_CMPSS10                     0x6F0U   // PER76SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS10
#define SYSCTL_O_CMPSS11                     0x6F4U   // PER77SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS11
#define SYSCTL_O_CMPSS12                     0x6F8U   // PER78SYSCONFIG -  Peripheral System
                                                      // Configuration for CMPSS12
#define SYSCTL_O_DACA                        0x6FCU   // PER79SYSCONFIG -  Peripheral System
                                                      // Configuration for DACA
#define SYSCTL_O_DACB                        0x700U   // PER80SYSCONFIG -  Peripheral System
                                                      // Configuration for DACB
#define SYSCTL_O_CLB1                        0x704U   // PER81SYSCONFIG -  Peripheral System
                                                      // Configuration for CLB1
#define SYSCTL_O_CLB2                        0x708U   // PER82SYSCONFIG -  Peripheral System
                                                      // Configuration for CLB2
#define SYSCTL_O_CLB3                        0x70CU   // PER83SYSCONFIG -  Peripheral System
                                                      // Configuration for CLB3
#define SYSCTL_O_CLB4                        0x710U   // PER84SYSCONFIG -  Peripheral System
                                                      // Configuration for CLB4
#define SYSCTL_O_CLB5                        0x714U   // PER85SYSCONFIG -  Peripheral System
                                                      // Configuration for CLB5
#define SYSCTL_O_CLB6                        0x718U   // PER86SYSCONFIG -  Peripheral System
                                                      // Configuration for CLB6
#define SYSCTL_O_FSITXA                      0x71CU   // PER87SYSCONFIG -  Peripheral System
                                                      // Configuration for FSITXA
#define SYSCTL_O_FSITXB                      0x720U   // PER88SYSCONFIG -  Peripheral System
                                                      // Configuration for FSITXB
#define SYSCTL_O_FSITXC                      0x724U   // PER89SYSCONFIG -  Peripheral System
                                                      // Configuration for FSITXC
#define SYSCTL_O_FSITXD                      0x728U   // PER90SYSCONFIG -  Peripheral System
                                                      // Configuration for FSITXD
#define SYSCTL_O_FSIRXA                      0x72CU   // PER91SYSCONFIG -  Peripheral System
                                                      // Configuration for FSIRXA
#define SYSCTL_O_FSIRXB                      0x730U   // PER92SYSCONFIG -  Peripheral System
                                                      // Configuration for FSIRXB
#define SYSCTL_O_FSIRXC                      0x734U   // PER93SYSCONFIG -  Peripheral System
                                                      // Configuration for FSIRXC
#define SYSCTL_O_FSIRXD                      0x738U   // PER94SYSCONFIG -  Peripheral System
                                                      // Configuration for FSIRXD
#define SYSCTL_O_DCC1                        0x73CU   // PER95SYSCONFIG -  Peripheral System
                                                      // Configuration for DCC1
#define SYSCTL_O_DCC2                        0x740U   // PER96SYSCONFIG -  Peripheral System
                                                      // Configuration for DCC2
#define SYSCTL_O_DCC3                        0x744U   // PER97SYSCONFIG -  Peripheral System
                                                      // Configuration for DCC3
#define SYSCTL_O_ETHERCATA                   0x748U   // PER98SYSCONFIG -  Peripheral System
                                                      // Configuration for ETHERCATA
#define SYSCTL_O_EPG1                        0x74CU   // PER99SYSCONFIG -  Peripheral System
                                                      // Configuration for EPG1
#define SYSCTL_O_SENT1                       0x750U   // PER100SYSCONFIG -  Peripheral System
                                                      // Configuration for SENT1
#define SYSCTL_O_SENT2                       0x754U   // PER101SYSCONFIG -  Peripheral System
                                                      // Configuration for SENT2
#define SYSCTL_O_SENT3                       0x758U   // PER102SYSCONFIG -  Peripheral System
                                                      // Configuration for SENT3
#define SYSCTL_O_SENT4                       0x75CU   // PER103SYSCONFIG -  Peripheral System
                                                      // Configuration for SENT4
#define SYSCTL_O_SENT5                       0x760U   // PER104SYSCONFIG -  Peripheral System
                                                      // Configuration for SENT5
#define SYSCTL_O_SENT6                       0x764U   // PER105SYSCONFIG -  Peripheral System
                                                      // Configuration for SENT6
#define SYSCTL_O_ADCCHECKER1                 0x768U   // PER106SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER1
#define SYSCTL_O_ADCCHECKER2                 0x76CU   // PER107SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER2
#define SYSCTL_O_ADCCHECKER3                 0x770U   // PER108SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER3
#define SYSCTL_O_ADCCHECKER4                 0x774U   // PER109SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER4
#define SYSCTL_O_ADCCHECKER5                 0x778U   // PER110SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER5
#define SYSCTL_O_ADCCHECKER6                 0x77CU   // PER111SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER6
#define SYSCTL_O_ADCCHECKER7                 0x780U   // PER112SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER7
#define SYSCTL_O_ADCCHECKER8                 0x784U   // PER113SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER8
#define SYSCTL_O_ADCCHECKER9                 0x788U   // PER114SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER9
#define SYSCTL_O_ADCCHECKER10                0x78CU   // PER115SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCCHECKER10
#define SYSCTL_O_ADCSEAGGRCPU1               0x790U   // PER116SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCSEAGGRCPU1
#define SYSCTL_O_ADCSEAGGRCPU2               0x794U   // PER117SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCSEAGGRCPU2
#define SYSCTL_O_ADCSEAGGRCPU3               0x798U   // PER118SYSCONFIG -  Peripheral System
                                                      // Configuration for ADCSEAGGRCPU3
#define SYSCTL_O_RTDMA1CH                    0x7A8U   // PER122SYSCONFIG -  Peripheral System
                                                      // Configuration for RTDMA1CH
#define SYSCTL_O_RTDMA2CH                    0x7ACU   // PER123SYSCONFIG -  Peripheral System
                                                      // Configuration for RTDMA2CH
#define SYSCTL_O_WADI1                       0x7B0U   // PER124SYSCONFIG -  Peripheral System
                                                      // Configuration for WADI1
#define SYSCTL_O_WADI2                       0x7B4U   // PER125SYSCONFIG -  Peripheral System
                                                      // Configuration for WADI2
#define SYSCTL_O_INPUTXBARFLAGS              0x7B8U   // PER126SYSCONFIG -  Peripheral System
                                                      // Configuration for INPUTXBARFlags
#define SYSCTL_O_OUTPUTXBARFLAGS             0x7BCU   // PER127SYSCONFIG -  Peripheral System
                                                      // Configuration for OUTPUTXBARFlags
#define SYSCTL_O_DLTFIFOREGS                 0x7C0U   // PER128SYSCONFIG -  Peripheral System
                                                      // Configuration for DLTFIFORegs
#define SYSCTL_O_ADC_GLOBAL_REGS             0x7C4U   // PER129SYSCONFIG -  Peripheral System
                                                      // Configuration for ADC_GLOBAL_REGS
#define SYSCTL_O_ERROR_AGGREGATOR            0x7C8U   // PER130SYSCONFIG -  Peripheral System
                                                      // Configuration for Error_Aggregator
#define SYSCTL_O_ESM                         0x7CCU   // PER131SYSCONFIG -  Peripheral System
                                                      // Configuration for ESM ESMCPU1/2/3 and
                                                      // ESMSYS
#define SYSCTL_O_PARITY_TEST                 0x7E4U   // Enables parity test

#define SYSCTL_O_CPUPERCFGLOCK1     0x0U     // Lock bit for CPUx_PER_CFG registers
#define SYSCTL_O_CPUPERCFGLOCK2     0x4U     // Lock bit for CPUx_PER_CFG registers
#define SYSCTL_O_PCLKCR0            0x10U    // Peripheral Clock Gating Registers
#define SYSCTL_O_PCLKCR1            0x14U    // Peripheral Clock Gating Register - EMIF
#define SYSCTL_O_PCLKCR2            0x18U    // Peripheral Clock Gating Register - EPWM
#define SYSCTL_O_PCLKCR3            0x1CU    // Peripheral Clock Gating Register - ECAP
#define SYSCTL_O_PCLKCR4            0x20U    // Peripheral Clock Gating Register - EQEP
#define SYSCTL_O_PCLKCR6            0x28U    // Peripheral Clock Gating Register - SDFM
#define SYSCTL_O_PCLKCR7            0x2CU    // Peripheral Clock Gating Register - SCI, UART
#define SYSCTL_O_PCLKCR8            0x30U    // Peripheral Clock Gating Register - SPI
#define SYSCTL_O_PCLKCR9            0x34U    // Peripheral Clock Gating Register - I2C
#define SYSCTL_O_PCLKCR10           0x38U    // Peripheral Clock Gating Register - CAN
#define SYSCTL_O_PCLKCR13           0x44U    // Peripheral Clock Gating Register - ADC
#define SYSCTL_O_PCLKCR14           0x48U    // Peripheral Clock Gating Register - CMPSS
#define SYSCTL_O_PCLKCR16           0x50U    // Peripheral Clock Gating Register Buf_DAC
#define SYSCTL_O_PCLKCR17           0x54U    // Peripheral Clock Gating Register - CLB
#define SYSCTL_O_PCLKCR18           0x58U    // Peripheral Clock Gating Register - FSI
#define SYSCTL_O_PCLKCR19           0x5CU    // Peripheral Clock Gating Register - LIN
#define SYSCTL_O_PCLKCR20           0x60U    // Peripheral Clock Gating Register - PMBUS
#define SYSCTL_O_PCLKCR21           0x64U    // Peripheral Clock Gating Register - DCC
#define SYSCTL_O_PCLKCR23           0x6CU    // Peripheral Clock Gating Register - EtherCAT
#define SYSCTL_O_PCLKCR25           0x74U    // Peripheral Clock Gating Register - HRCAL0,1,2
#define SYSCTL_O_PCLKCR27           0x7CU    // Peripheral Clock Gating Register - EPG
#define SYSCTL_O_PCLKCR28           0x80U    // Peripheral Clock Gating Register - ADCCHECKER
#define SYSCTL_O_PCLKCR30           0x88U    // Peripheral Clock Gating Register - SENT
#define SYSCTL_O_PCLKCR32           0x90U    // Peripheral Clock Gating Register - WADI
#define SYSCTL_O_SOFTPRES0          0x110U   // Processing Block Software Reset register
#define SYSCTL_O_SOFTPRES1          0x114U   // EMIF Software Reset register
#define SYSCTL_O_SOFTPRES2          0x118U   // EPWM Software Reset register
#define SYSCTL_O_SOFTPRES3          0x11CU   // ECAP Software Reset register
#define SYSCTL_O_SOFTPRES4          0x120U   // EQEP Software Reset register
#define SYSCTL_O_SOFTPRES6          0x128U   // Sigma Delta Software Reset register
#define SYSCTL_O_SOFTPRES7          0x12CU   // SCI, UART Software Reset register
#define SYSCTL_O_SOFTPRES8          0x130U   // SPI Software Reset register
#define SYSCTL_O_SOFTPRES9          0x134U   // I2C Software Reset register
#define SYSCTL_O_SOFTPRES10         0x138U   // CAN Software Reset register
#define SYSCTL_O_SOFTPRES13         0x144U   // ADC Software Reset register
#define SYSCTL_O_SOFTPRES14         0x148U   // CMPSS Software Reset register
#define SYSCTL_O_SOFTPRES16         0x150U   // DAC Software Reset register
#define SYSCTL_O_SOFTPRES17         0x154U   // CLB Software Reset register
#define SYSCTL_O_SOFTPRES18         0x158U   // FSI Software Reset register
#define SYSCTL_O_SOFTPRES19         0x15CU   // LIN Software Reset register
#define SYSCTL_O_SOFTPRES20         0x160U   // PMBUS Software Reset register
#define SYSCTL_O_SOFTPRES21         0x164U   // DCC Software Reset register
#define SYSCTL_O_SOFTPRES23         0x16CU   // ETHERCAT Software Reset register
#define SYSCTL_O_SOFTPRES25         0x174U   // HRCAL0,1,2 Software Reset register
#define SYSCTL_O_SOFTPRES27         0x17CU   // EPG Software Reset register
#define SYSCTL_O_SOFTPRES28         0x180U   // ADCCHECKER Software Reset register
#define SYSCTL_O_SOFTPRES30         0x188U   // SENT Software Reset register
#define SYSCTL_O_SOFTPRES32         0x190U   // WADI Software Reset register
#define SYSCTL_O_PARITY_TEST_ALT1   0x1B8U   // Enables parity test

#define SYSCTL_O_CPUSYSLOCK1          0x0U    // Lock bit for CPUSYS registers
#define SYSCTL_O_CPUID                0xCU    // Indicates CPU1, CPU2.. CPU6
#define SYSCTL_O_LPMCR                0x28U   // LPM Control Register
#define SYSCTL_O_CMPSSLPMSEL          0x2CU   // CMPSS LPM Wakeup select registers
#define SYSCTL_O_GPIOLPMSEL0          0x30U   // GPIO LPM Wakeup select registers
#define SYSCTL_O_GPIOLPMSEL1          0x34U   // GPIO LPM Wakeup select registers
#define SYSCTL_O_TMR2CLKCTL           0x38U   // Timer2 Clock Measurement functionality control
                                              // register
#define SYSCTL_O_RESCCLR              0x3CU   // Reset Cause Clear Register
#define SYSCTL_O_RESC                 0x40U   // Reset Cause register
#define SYSCTL_O_MCANWAKESTATUS       0x70U   // MCAN Wake Status Register
#define SYSCTL_O_MCANWAKESTATUSCLR    0x74U   // MCAN Wake Status Clear Register
#define SYSCTL_O_CLKSTOPREQ           0x78U   // Peripheral Clock Stop Request Register
#define SYSCTL_O_CLKSTOPACK           0x7CU   // Peripheral Clock Stop Ackonwledge Register
#define SYSCTL_O_USER_REG1_SYSRSN     0x80U   // Software Configurable registers reset by SYSRSn
#define SYSCTL_O_USER_REG2_SYSRSN     0x84U   // Software Configurable registers reset by SYSRSn
#define SYSCTL_O_USER_REG1_XRSN       0x88U   // Software Configurable registers reset by XRSn
#define SYSCTL_O_USER_REG2_XRSN       0x8CU   // Software Configurable registers reset by XRSn
#define SYSCTL_O_USER_REG1_PORESETN   0x90U   // Software Configurable registers reset by PORESETn
#define SYSCTL_O_USER_REG2_PORESETN   0x94U   // Software Configurable registers reset by PORESETn
#define SYSCTL_O_USER_REG3_PORESETN   0x98U   // Software Configurable registers reset by PORESETn
#define SYSCTL_O_USER_REG4_PORESETN   0x9CU   // Software Configurable registers reset by PORESETn
#define SYSCTL_O_SIMRESET             0xA4U   // Simulated Reset Register
#define SYSCTL_O_PARITY_TEST_ALT2     0xA8U   // Enables parity test

#define SYSCTL_O_SCSR         0x44U   // System Control & Status Register
#define SYSCTL_O_WDCNTR       0x46U   // Watchdog Counter Register
#define SYSCTL_O_WDKEY        0x4AU   // Watchdog Reset Key Register
#define SYSCTL_O_SYNCBUSYWD   0x50U   // SYNCBUSY status for Watchdog Register
#define SYSCTL_O_WDCR         0x52U   // Watchdog Control Register
#define SYSCTL_O_WDWCR        0x54U   // Watchdog Windowed Control Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the DEVCFGLOCK1 register
//
//*************************************************************************************************
#define SYSCTL_DEVCFGLOCK1_PER0SYSCONFIG    0x1U          // Lock bit for PER0SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER1SYSCONFIG    0x2U          // Lock bit for PER1SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER2SYSCONFIG    0x4U          // Lock bit for PER2SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER3SYSCONFIG    0x8U          // Lock bit for PER3SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER4SYSCONFIG    0x10U         // Lock bit for PER4SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER5SYSCONFIG    0x20U         // Lock bit for PER5SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER6SYSCONFIG    0x40U         // Lock bit for PER6SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER7SYSCONFIG    0x80U         // Lock bit for PER7SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER8SYSCONFIG    0x100U        // Lock bit for PER8SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER9SYSCONFIG    0x200U        // Lock bit for PER9SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER10SYSCONFIG   0x400U        // Lock bit for PER10SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER11SYSCONFIG   0x800U        // Lock bit for PER11SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER12SYSCONFIG   0x1000U       // Lock bit for PER12SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER13SYSCONFIG   0x2000U       // Lock bit for PER13SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER14SYSCONFIG   0x4000U       // Lock bit for PER14SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER15SYSCONFIG   0x8000U       // Lock bit for PER15SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER16SYSCONFIG   0x10000U      // Lock bit for PER16SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER17SYSCONFIG   0x20000U      // Lock bit for PER17SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER18SYSCONFIG   0x40000U      // Lock bit for PER18SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER19SYSCONFIG   0x80000U      // Lock bit for PER19SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER20SYSCONFIG   0x100000U     // Lock bit for PER20SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER21SYSCONFIG   0x200000U     // Lock bit for PER21SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER22SYSCONFIG   0x400000U     // Lock bit for PER22SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER23SYSCONFIG   0x800000U     // Lock bit for PER23SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER24SYSCONFIG   0x1000000U    // Lock bit for PER24SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER25SYSCONFIG   0x2000000U    // Lock bit for PER25SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER26SYSCONFIG   0x4000000U    // Lock bit for PER26SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER27SYSCONFIG   0x8000000U    // Lock bit for PER27SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER28SYSCONFIG   0x10000000U   // Lock bit for PER28SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER29SYSCONFIG   0x20000000U   // Lock bit for PER29SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER30SYSCONFIG   0x40000000U   // Lock bit for PER30SYSCONFIG register
#define SYSCTL_DEVCFGLOCK1_PER31SYSCONFIG   0x80000000U   // Lock bit for PER31SYSCONFIG register

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEVCFGLOCK2 register
//
//*************************************************************************************************
#define SYSCTL_DEVCFGLOCK2_SICCONFIG     0x8U    // Lock for SICCONFIG
#define SYSCTL_DEVCFGLOCK2_LSEN          0x10U   // Lock for LSEN
#define SYSCTL_DEVCFGLOCK2_ETHERCATCTL   0x40U   // Lock for ETHERCATCTL
#define SYSCTL_DEVCFGLOCK2_PCLKCR22      0x80U   // Lock for PCLKCR22

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEVCFGLOCK3 register
//
//*************************************************************************************************
#define SYSCTL_DEVCFGLOCK3_PER32SYSCONFIG   0x1U          // Lock bit for PER32SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER33SYSCONFIG   0x2U          // Lock bit for PER33SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER34SYSCONFIG   0x4U          // Lock bit for PER34SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER35SYSCONFIG   0x8U          // Lock bit for PER35SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER36SYSCONFIG   0x10U         // Lock bit for PER36SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER37SYSCONFIG   0x20U         // Lock bit for PER37SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER38SYSCONFIG   0x40U         // Lock bit for PER38SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER39SYSCONFIG   0x80U         // Lock bit for PER39SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER40SYSCONFIG   0x100U        // Lock bit for PER40SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER41SYSCONFIG   0x200U        // Lock bit for PER41SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER42SYSCONFIG   0x400U        // Lock bit for PER42SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER43SYSCONFIG   0x800U        // Lock bit for PER43SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER44SYSCONFIG   0x1000U       // Lock bit for PER44SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER45SYSCONFIG   0x2000U       // Lock bit for PER45SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER46SYSCONFIG   0x4000U       // Lock bit for PER46SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER47SYSCONFIG   0x8000U       // Lock bit for PER47SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER48SYSCONFIG   0x10000U      // Lock bit for PER48SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER49SYSCONFIG   0x20000U      // Lock bit for PER49SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER50SYSCONFIG   0x40000U      // Lock bit for PER50SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER51SYSCONFIG   0x80000U      // Lock bit for PER51SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER52SYSCONFIG   0x100000U     // Lock bit for PER52SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER53SYSCONFIG   0x200000U     // Lock bit for PER53SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER54SYSCONFIG   0x400000U     // Lock bit for PER54SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER55SYSCONFIG   0x800000U     // Lock bit for PER55SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER56SYSCONFIG   0x1000000U    // Lock bit for PER56SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER57SYSCONFIG   0x2000000U    // Lock bit for PER57SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER58SYSCONFIG   0x4000000U    // Lock bit for PER58SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER59SYSCONFIG   0x8000000U    // Lock bit for PER59SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER60SYSCONFIG   0x10000000U   // Lock bit for PER60SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER61SYSCONFIG   0x20000000U   // Lock bit for PER61SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER62SYSCONFIG   0x40000000U   // Lock bit for PER62SYSCONFIG register
#define SYSCTL_DEVCFGLOCK3_PER63SYSCONFIG   0x80000000U   // Lock bit for PER63SYSCONFIG register

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEVCFGLOCK4 register
//
//*************************************************************************************************
#define SYSCTL_DEVCFGLOCK4_PER64SYSCONFIG   0x1U          // Lock bit for PER64SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER65SYSCONFIG   0x2U          // Lock bit for PER65SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER66SYSCONFIG   0x4U          // Lock bit for PER66SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER67SYSCONFIG   0x8U          // Lock bit for PER67SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER68SYSCONFIG   0x10U         // Lock bit for PER68SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER69SYSCONFIG   0x20U         // Lock bit for PER69SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER70SYSCONFIG   0x40U         // Lock bit for PER70SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER71SYSCONFIG   0x80U         // Lock bit for PER71SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER72SYSCONFIG   0x100U        // Lock bit for PER72SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER73SYSCONFIG   0x200U        // Lock bit for PER73SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER74SYSCONFIG   0x400U        // Lock bit for PER74SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER75SYSCONFIG   0x800U        // Lock bit for PER75SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER76SYSCONFIG   0x1000U       // Lock bit for PER76SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER77SYSCONFIG   0x2000U       // Lock bit for PER77SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER78SYSCONFIG   0x4000U       // Lock bit for PER78SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER79SYSCONFIG   0x8000U       // Lock bit for PER79SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER80SYSCONFIG   0x10000U      // Lock bit for PER80SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER81SYSCONFIG   0x20000U      // Lock bit for PER81SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER82SYSCONFIG   0x40000U      // Lock bit for PER82SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER83SYSCONFIG   0x80000U      // Lock bit for PER83SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER84SYSCONFIG   0x100000U     // Lock bit for PER84SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER85SYSCONFIG   0x200000U     // Lock bit for PER85SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER86SYSCONFIG   0x400000U     // Lock bit for PER86SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER87SYSCONFIG   0x800000U     // Lock bit for PER87SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER88SYSCONFIG   0x1000000U    // Lock bit for PER88SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER89SYSCONFIG   0x2000000U    // Lock bit for PER89SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER90SYSCONFIG   0x4000000U    // Lock bit for PER90SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER91SYSCONFIG   0x8000000U    // Lock bit for PER91SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER92SYSCONFIG   0x10000000U   // Lock bit for PER92SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER93SYSCONFIG   0x20000000U   // Lock bit for PER93SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER94SYSCONFIG   0x40000000U   // Lock bit for PER94SYSCONFIG register
#define SYSCTL_DEVCFGLOCK4_PER95SYSCONFIG   0x80000000U   // Lock bit for PER95SYSCONFIG register

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEVCFGLOCK5 register
//
//*************************************************************************************************
#define SYSCTL_DEVCFGLOCK5_PER96SYSCONFIG    0x1U         // Lock bit for PER96SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER97SYSCONFIG    0x2U         // Lock bit for PER97SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER98SYSCONFIG    0x4U         // Lock bit for PER98SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER99SYSCONFIG    0x8U         // Lock bit for PER99SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER100SYSCONFIG   0x10U        // Lock bit for PER100SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER101SYSCONFIG   0x20U        // Lock bit for PER101SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER102SYSCONFIG   0x40U        // Lock bit for PER102SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER103SYSCONFIG   0x80U        // Lock bit for PER103SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER104SYSCONFIG   0x100U       // Lock bit for PER104SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER105SYSCONFIG   0x200U       // Lock bit for PER105SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER106SYSCONFIG   0x400U       // Lock bit for PER106SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER107SYSCONFIG   0x800U       // Lock bit for PER107SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER108SYSCONFIG   0x1000U      // Lock bit for PER108SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER109SYSCONFIG   0x2000U      // Lock bit for PER109SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER110SYSCONFIG   0x4000U      // Lock bit for PER110SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER111SYSCONFIG   0x8000U      // Lock bit for PER111SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER112SYSCONFIG   0x10000U     // Lock bit for PER112SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER113SYSCONFIG   0x20000U     // Lock bit for PER113SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER114SYSCONFIG   0x40000U     // Lock bit for PER114SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER115SYSCONFIG   0x80000U     // Lock bit for PER115SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER116SYSCONFIG   0x100000U    // Lock bit for PER116SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER117SYSCONFIG   0x200000U    // Lock bit for PER117SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER118SYSCONFIG   0x400000U    // Lock bit for PER118SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER119SYSCONFIG   0x800000U    // Lock bit for PER119SYSCONFIG register
#define SYSCTL_DEVCFGLOCK5_PER120SYSCONFIG   0x1000000U   // Lock bit for PER120SYSCONFIG register

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARTIDL register
//
//*************************************************************************************************
#define SYSCTL_PARTIDL_QUAL_S                6U
#define SYSCTL_PARTIDL_QUAL_M                0xC0U         // Qualification Status
#define SYSCTL_PARTIDL_PIN_COUNT_S           8U
#define SYSCTL_PARTIDL_PIN_COUNT_M           0x700U        // Device Pin Count
#define SYSCTL_PARTIDL_FLASH_SIZE_S          16U
#define SYSCTL_PARTIDL_FLASH_SIZE_M          0xFF0000U     // FLASH_SIZE
#define SYSCTL_PARTIDL_PARTID_FORMAT_REV_S   28U
#define SYSCTL_PARTIDL_PARTID_FORMAT_REV_M   0xF0000000U   // PARTID_FORMAT_REV

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARTIDH register
//
//*************************************************************************************************
#define SYSCTL_PARTIDH_FAMILY_S            8U
#define SYSCTL_PARTIDH_FAMILY_M            0xFF00U       // Device family
#define SYSCTL_PARTIDH_PARTNO_S            16U
#define SYSCTL_PARTIDH_PARTNO_M            0xFF0000U     // Device part number
#define SYSCTL_PARTIDH_DEVICE_CLASS_ID_S   24U
#define SYSCTL_PARTIDH_DEVICE_CLASS_ID_M   0xFF000000U   // Device class ID

//*************************************************************************************************
//
// The following are defines for the bit fields in the REVID register
//
//*************************************************************************************************
#define SYSCTL_REVID_REVID_S   0U
#define SYSCTL_REVID_REVID_M   0xFFFFU   // Device Revision ID. This is specific to the Device

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF1 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF1_EMIF1   0x1U   // EMIF1 Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF2 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF2_EPWM1    0x1U       // EPWM1 Present
#define SYSCTL_MCUCNF2_EPWM2    0x2U       // EPWM2 Present
#define SYSCTL_MCUCNF2_EPWM3    0x4U       // EPWM3 Present
#define SYSCTL_MCUCNF2_EPWM4    0x8U       // EPWM4 Present
#define SYSCTL_MCUCNF2_EPWM5    0x10U      // EPWM5 Present
#define SYSCTL_MCUCNF2_EPWM6    0x20U      // EPWM6 Present
#define SYSCTL_MCUCNF2_EPWM7    0x40U      // EPWM7 Present
#define SYSCTL_MCUCNF2_EPWM8    0x80U      // EPWM8 Present
#define SYSCTL_MCUCNF2_EPWM9    0x100U     // EPWM9 Present
#define SYSCTL_MCUCNF2_EPWM10   0x200U     // EPWM10 Present
#define SYSCTL_MCUCNF2_EPWM11   0x400U     // EPWM11 Present
#define SYSCTL_MCUCNF2_EPWM12   0x800U     // EPWM12 Present
#define SYSCTL_MCUCNF2_EPWM13   0x1000U    // EPWM13 Present
#define SYSCTL_MCUCNF2_EPWM14   0x2000U    // EPWM14 Present
#define SYSCTL_MCUCNF2_EPWM15   0x4000U    // EPWM15 Present
#define SYSCTL_MCUCNF2_EPWM16   0x8000U    // EPWM16 Present
#define SYSCTL_MCUCNF2_EPWM17   0x10000U   // EPWM17 Present
#define SYSCTL_MCUCNF2_EPWM18   0x20000U   // EPWM18 Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF4 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF4_EQEP1   0x1U    // EQEP1 Present
#define SYSCTL_MCUCNF4_EQEP2   0x2U    // EQEP2 Present
#define SYSCTL_MCUCNF4_EQEP3   0x4U    // EQEP3 Present
#define SYSCTL_MCUCNF4_EQEP4   0x8U    // EQEP4 Present
#define SYSCTL_MCUCNF4_EQEP5   0x10U   // EQEP5 Present
#define SYSCTL_MCUCNF4_EQEP6   0x20U   // EQEP6 Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF7 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF7_UART_A   0x10000U    // UART_A Present
#define SYSCTL_MCUCNF7_UART_B   0x20000U    // UART_B Present
#define SYSCTL_MCUCNF7_UART_C   0x40000U    // UART_C Present
#define SYSCTL_MCUCNF7_UART_D   0x80000U    // UART_D Present
#define SYSCTL_MCUCNF7_UART_E   0x100000U   // UART_E Present
#define SYSCTL_MCUCNF7_UART_F   0x200000U   // UART_F Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF10 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF10_MCAN_A   0x10U    // MCAN_A Present
#define SYSCTL_MCUCNF10_MCAN_B   0x20U    // MCAN_B Present
#define SYSCTL_MCUCNF10_MCAN_C   0x40U    // MCAN_C Present
#define SYSCTL_MCUCNF10_MCAN_D   0x80U    // MCAN_D Present
#define SYSCTL_MCUCNF10_MCAN_E   0x100U   // MCAN_E Present
#define SYSCTL_MCUCNF10_MCAN_F   0x200U   // MCAN_F Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF13 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF13_ADC_A   0x1U    // ADC_A Present
#define SYSCTL_MCUCNF13_ADC_B   0x2U    // ADC_B Present
#define SYSCTL_MCUCNF13_ADC_C   0x4U    // ADC_C Present
#define SYSCTL_MCUCNF13_ADC_D   0x8U    // ADC_D Present
#define SYSCTL_MCUCNF13_ADC_E   0x10U   // ADC_E Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF14 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF14_CMPSS1    0x1U     // CMPSS1 Present
#define SYSCTL_MCUCNF14_CMPSS2    0x2U     // CMPSS2 Present
#define SYSCTL_MCUCNF14_CMPSS3    0x4U     // CMPSS3 Present
#define SYSCTL_MCUCNF14_CMPSS4    0x8U     // CMPSS4 Present
#define SYSCTL_MCUCNF14_CMPSS5    0x10U    // CMPSS5 Present
#define SYSCTL_MCUCNF14_CMPSS6    0x20U    // CMPSS6 Present
#define SYSCTL_MCUCNF14_CMPSS7    0x40U    // CMPSS7 Present
#define SYSCTL_MCUCNF14_CMPSS8    0x80U    // CMPSS8 Present
#define SYSCTL_MCUCNF14_CMPSS9    0x100U   // CMPSS9 Present
#define SYSCTL_MCUCNF14_CMPSS10   0x200U   // CMPSS10 Present
#define SYSCTL_MCUCNF14_CMPSS11   0x400U   // CMPSS11 Present
#define SYSCTL_MCUCNF14_CMPSS12   0x800U   // CMPSS12 Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF16 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF16_DAC_A   0x10000U   // DAC_A Present
#define SYSCTL_MCUCNF16_DAC_B   0x20000U   // DAC_B Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF17 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF17_CLB1   0x1U    // CLB1 Present
#define SYSCTL_MCUCNF17_CLB2   0x2U    // CLB2 Present
#define SYSCTL_MCUCNF17_CLB3   0x4U    // CLB3 Present
#define SYSCTL_MCUCNF17_CLB4   0x8U    // CLB4 Present
#define SYSCTL_MCUCNF17_CLB5   0x10U   // CLB5 Present
#define SYSCTL_MCUCNF17_CLB6   0x20U   // CLB6 Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF18 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF18_FSITX_A   0x1U       // FSITX_A  Present
#define SYSCTL_MCUCNF18_FSITX_B   0x2U       // FSITX_B  Present
#define SYSCTL_MCUCNF18_FSITX_C   0x4U       // FSITX_C  Present
#define SYSCTL_MCUCNF18_FSITX_D   0x8U       // FSITX_D  Present
#define SYSCTL_MCUCNF18_FSIRX_A   0x10000U   // FSIRX_A  Present
#define SYSCTL_MCUCNF18_FSIRX_B   0x20000U   // FSIRX_B  Present
#define SYSCTL_MCUCNF18_FSIRX_C   0x40000U   // FSIRX_C  Present
#define SYSCTL_MCUCNF18_FSIRX_D   0x80000U   // FSIRX_D  Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF19 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF19_LIN_A   0x1U   // LIN_A Present
#define SYSCTL_MCUCNF19_LIN_B   0x2U   // LIN_B Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF23 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF23_ETHERCAT   0x1U   // ETHERCAT

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF26 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF26_AES_S    0U
#define SYSCTL_MCUCNF26_AES_M    0x3FU       // AES Present
#define SYSCTL_MCUCNF26_SHA_S    6U
#define SYSCTL_MCUCNF26_SHA_M    0xFC0U      // SHA Present
#define SYSCTL_MCUCNF26_PKA_S    12U
#define SYSCTL_MCUCNF26_PKA_M    0x3F000U    // PKA Present
#define SYSCTL_MCUCNF26_TRNG_S   18U
#define SYSCTL_MCUCNF26_TRNG_M   0xFC0000U   // TRNG Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF31 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF31_SM2_S   0U
#define SYSCTL_MCUCNF31_SM2_M   0x3FU      // SM2 Present
#define SYSCTL_MCUCNF31_SM3_S   6U
#define SYSCTL_MCUCNF31_SM3_M   0xFC0U     // SM3 Present
#define SYSCTL_MCUCNF31_SM4_S   12U
#define SYSCTL_MCUCNF31_SM4_M   0x3F000U   // SM4 Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF64 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF64_CPU2   0x8U    // CPU2SS Present on this device
#define SYSCTL_MCUCNF64_CPU3   0x10U   // CPU3SS Present on this device

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF65 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF65_CPA0    0x1U         // CPA0 Memory Present
#define SYSCTL_MCUCNF65_CPA1    0x2U         // CPA1 Memory Present
#define SYSCTL_MCUCNF65_LPA0    0x10U        // LPA0 Memory Present
#define SYSCTL_MCUCNF65_LPA1    0x20U        // LPA1 Memory Present
#define SYSCTL_MCUCNF65_LDA0    0x100U       // LDA0 Memory Present
#define SYSCTL_MCUCNF65_LDA1    0x200U       // LDA1 Memory Present
#define SYSCTL_MCUCNF65_LDA2    0x400U       // LDA2 Memory Present
#define SYSCTL_MCUCNF65_LDA3    0x800U       // LDA3 Memory Present
#define SYSCTL_MCUCNF65_LDA4    0x1000U      // LDA4 Memory Present
#define SYSCTL_MCUCNF65_LDA5    0x2000U      // LDA5 Memory Present
#define SYSCTL_MCUCNF65_LDA6    0x4000U      // LDA6 Memory Present
#define SYSCTL_MCUCNF65_LDA7    0x8000U      // LDA7 Memory Present
#define SYSCTL_MCUCNF65_CDA0    0x10000U     // CDA0 Memory Present
#define SYSCTL_MCUCNF65_CDA1    0x20000U     // CDA1 Memory Present
#define SYSCTL_MCUCNF65_CDA2    0x40000U     // CDA2 Memory Present
#define SYSCTL_MCUCNF65_CDA3    0x80000U     // CDA3 Memory Present
#define SYSCTL_MCUCNF65_CDA4    0x100000U    // CDA4 Memory Present
#define SYSCTL_MCUCNF65_CDA5    0x200000U    // CDA5 Memory Present
#define SYSCTL_MCUCNF65_CDA6    0x400000U    // CDA6 Memory Present
#define SYSCTL_MCUCNF65_CDA7    0x800000U    // CDA7 Memory Present
#define SYSCTL_MCUCNF65_CDA8    0x1000000U   // CDA8 Memory Present
#define SYSCTL_MCUCNF65_CDA9    0x2000000U   // CDA9 Memory Present
#define SYSCTL_MCUCNF65_CDA10   0x4000000U   // CDA10 Memory Present
#define SYSCTL_MCUCNF65_CDA11   0x8000000U   // CDA11 Memory Present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF74 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF74_SECT15_0      0x1U      // Flash sectors 15_0 present
#define SYSCTL_MCUCNF74_SECT31_16     0x2U      // Flash sectors 31_16 present
#define SYSCTL_MCUCNF74_SECT47_32     0x4U      // Flash sectors 47_32 present
#define SYSCTL_MCUCNF74_SECT63_48     0x8U      // Flash sectors 63_48 present
#define SYSCTL_MCUCNF74_SECT79_64     0x10U     // Flash sectors 79_64 present
#define SYSCTL_MCUCNF74_SECT95_80     0x20U     // Flash sectors 95_80 present
#define SYSCTL_MCUCNF74_SECT111_96    0x40U     // Flash sectors 111_96 present
#define SYSCTL_MCUCNF74_SECT127_112   0x80U     // Flash sectors 127_112 present
#define SYSCTL_MCUCNF74_SECT143_128   0x100U    // Flash sectors 143_128 present
#define SYSCTL_MCUCNF74_SECT159_144   0x200U    // Flash sectors 159_144 present
#define SYSCTL_MCUCNF74_SECT175_160   0x400U    // Flash sectors 175_160 present
#define SYSCTL_MCUCNF74_SECT191_176   0x800U    // Flash sectors 191_176 present
#define SYSCTL_MCUCNF74_SECT207_192   0x1000U   // Flash sectors 207_192 present
#define SYSCTL_MCUCNF74_SECT223_208   0x2000U   // Flash sectors 223_208 present
#define SYSCTL_MCUCNF74_SECT239_224   0x4000U   // Flash sectors 239_224 present
#define SYSCTL_MCUCNF74_SECT255_240   0x8000U   // Flash sectors 255_240 present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF76 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF76_SECT15_0      0x1U      // Flash sectors 15_0 present
#define SYSCTL_MCUCNF76_SECT31_16     0x2U      // Flash sectors 31_16 present
#define SYSCTL_MCUCNF76_SECT47_32     0x4U      // Flash sectors 47_32 present
#define SYSCTL_MCUCNF76_SECT63_48     0x8U      // Flash sectors 63_48 present
#define SYSCTL_MCUCNF76_SECT79_64     0x10U     // Flash sectors 79_64 present
#define SYSCTL_MCUCNF76_SECT95_80     0x20U     // Flash sectors 95_80 present
#define SYSCTL_MCUCNF76_SECT111_96    0x40U     // Flash sectors 111_96 present
#define SYSCTL_MCUCNF76_SECT127_112   0x80U     // Flash sectors 127_112 present
#define SYSCTL_MCUCNF76_SECT143_128   0x100U    // Flash sectors 143_128 present
#define SYSCTL_MCUCNF76_SECT159_144   0x200U    // Flash sectors 159_144 present
#define SYSCTL_MCUCNF76_SECT175_160   0x400U    // Flash sectors 175_160 present
#define SYSCTL_MCUCNF76_SECT191_176   0x800U    // Flash sectors 191_176 present
#define SYSCTL_MCUCNF76_SECT207_192   0x1000U   // Flash sectors 207_192 present
#define SYSCTL_MCUCNF76_SECT223_208   0x2000U   // Flash sectors 223_208 present
#define SYSCTL_MCUCNF76_SECT239_224   0x4000U   // Flash sectors 239_224 present
#define SYSCTL_MCUCNF76_SECT255_240   0x8000U   // Flash sectors 255_240 present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF78 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF78_SECT15_0      0x1U    // Flash sectors 15_0 present
#define SYSCTL_MCUCNF78_SECT31_16     0x2U    // Flash sectors 31_16 present
#define SYSCTL_MCUCNF78_SECT47_32     0x4U    // Flash sectors 47_32 present
#define SYSCTL_MCUCNF78_SECT63_48     0x8U    // Flash sectors 63_48 present
#define SYSCTL_MCUCNF78_SECT79_64     0x10U   // Flash sectors 79_64 present
#define SYSCTL_MCUCNF78_SECT95_80     0x20U   // Flash sectors 95_80 present
#define SYSCTL_MCUCNF78_SECT111_96    0x40U   // Flash sectors 111_96 present
#define SYSCTL_MCUCNF78_SECT127_112   0x80U   // Flash sectors 127_112 present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF79 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF79_SECT15_0      0x1U      // Flash sectors 15_0 present
#define SYSCTL_MCUCNF79_SECT31_16     0x2U      // Flash sectors 31_16 present
#define SYSCTL_MCUCNF79_SECT47_32     0x4U      // Flash sectors 47_32 present
#define SYSCTL_MCUCNF79_SECT63_48     0x8U      // Flash sectors 63_48 present
#define SYSCTL_MCUCNF79_SECT79_64     0x10U     // Flash sectors 79_64 present
#define SYSCTL_MCUCNF79_SECT95_80     0x20U     // Flash sectors 95_80 present
#define SYSCTL_MCUCNF79_SECT111_96    0x40U     // Flash sectors 111_96 present
#define SYSCTL_MCUCNF79_SECT127_112   0x80U     // Flash sectors 127_112 present
#define SYSCTL_MCUCNF79_SECT143_128   0x100U    // Flash sectors 143_128 present
#define SYSCTL_MCUCNF79_SECT159_144   0x200U    // Flash sectors 159_144 present
#define SYSCTL_MCUCNF79_SECT175_160   0x400U    // Flash sectors 175_160 present
#define SYSCTL_MCUCNF79_SECT191_176   0x800U    // Flash sectors 191_176 present
#define SYSCTL_MCUCNF79_SECT207_192   0x1000U   // Flash sectors 207_192 present
#define SYSCTL_MCUCNF79_SECT223_208   0x2000U   // Flash sectors 223_208 present
#define SYSCTL_MCUCNF79_SECT239_224   0x4000U   // Flash sectors 239_224 present
#define SYSCTL_MCUCNF79_SECT255_240   0x8000U   // Flash sectors 255_240 present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNF81 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNF81_SECT15_0      0x1U      // Flash sectors 15_0 present
#define SYSCTL_MCUCNF81_SECT31_16     0x2U      // Flash sectors 31_16 present
#define SYSCTL_MCUCNF81_SECT47_32     0x4U      // Flash sectors 47_32 present
#define SYSCTL_MCUCNF81_SECT63_48     0x8U      // Flash sectors 63_48 present
#define SYSCTL_MCUCNF81_SECT79_64     0x10U     // Flash sectors 79_64 present
#define SYSCTL_MCUCNF81_SECT95_80     0x20U     // Flash sectors 95_80 present
#define SYSCTL_MCUCNF81_SECT111_96    0x40U     // Flash sectors 111_96 present
#define SYSCTL_MCUCNF81_SECT127_112   0x80U     // Flash sectors 127_112 present
#define SYSCTL_MCUCNF81_SECT143_128   0x100U    // Flash sectors 143_128 present
#define SYSCTL_MCUCNF81_SECT159_144   0x200U    // Flash sectors 159_144 present
#define SYSCTL_MCUCNF81_SECT175_160   0x400U    // Flash sectors 175_160 present
#define SYSCTL_MCUCNF81_SECT191_176   0x800U    // Flash sectors 191_176 present
#define SYSCTL_MCUCNF81_SECT207_192   0x1000U   // Flash sectors 207_192 present
#define SYSCTL_MCUCNF81_SECT223_208   0x2000U   // Flash sectors 223_208 present
#define SYSCTL_MCUCNF81_SECT239_224   0x4000U   // Flash sectors 239_224 present
#define SYSCTL_MCUCNF81_SECT255_240   0x8000U   // Flash sectors 255_240 present

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNFLOCK1 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNFLOCK1_MCUCNF1    0x2U          // Lock bit for MCUCNF1 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF2    0x4U          // Lock bit for MCUCNF2 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF4    0x10U         // Lock bit for MCUCNF4 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF10   0x400U        // Lock bit for MCUCNF10 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF17   0x20000U      // Lock bit for MCUCNF17 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF18   0x40000U      // Lock bit for MCUCNF18 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF19   0x80000U      // Lock bit for MCUCNF19 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF23   0x800000U     // Lock bit for MCUCNF23 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF26   0x4000000U    // Lock bit for MCUCNF26 register
#define SYSCTL_MCUCNFLOCK1_MCUCNF31   0x80000000U   // Lock bit for MCUCNF31 register

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCUCNFLOCK3 register
//
//*************************************************************************************************
#define SYSCTL_MCUCNFLOCK3_MCUCNF64   0x1U          // Lock bit for MCUCNF64 register
#define SYSCTL_MCUCNFLOCK3_MCUCNF65   0x2U          // Lock bit for MCUCNF65 register
#define SYSCTL_MCUCNFLOCK3_MCUCNF74   0x400U        // Lock bit for MCUCNF74 register
#define SYSCTL_MCUCNFLOCK3_MCUCNF76   0x1000U       // Lock bit for MCUCNF76 register
#define SYSCTL_MCUCNFLOCK3_MCUCNF78   0x4000U       // Lock bit for MCUCNF78 register
#define SYSCTL_MCUCNFLOCK3_MCUCNF79   0x8000U       // Lock bit for MCUCNF79 register
#define SYSCTL_MCUCNFLOCK3_MCUCNF81   0x20000U      // Lock bit for MCUCNF81 register
#define SYSCTL_MCUCNFLOCK3_MCUCNF95   0x40000000U   // Lock bit for MCUCNF95 register

//*************************************************************************************************
//
// The following are defines for the bit fields in the LSEN register
//
//*************************************************************************************************
#define SYSCTL_LSEN_ENABLE      0x1U          // Lockstep Enable
#define SYSCTL_LSEN_RSERVED_S   1U
#define SYSCTL_LSEN_RSERVED_M   0xFFFFFFFEU   // Reserved

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWMXLINKCFG register
//
//*************************************************************************************************
#define SYSCTL_EPWMXLINKCFG_EPWM1    0x1U       // Enable EPWM1 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM2    0x2U       // Enable EPWM2 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM3    0x4U       // Enable EPWM3 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM4    0x8U       // Enable EPWM4 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM5    0x10U      // Enable EPWM5 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM6    0x20U      // Enable EPWM6 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM7    0x40U      // Enable EPWM7 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM8    0x80U      // Enable EPWM8 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM9    0x100U     // Enable EPWM9 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM10   0x200U     // Enable EPWM10 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM11   0x400U     // Enable EPWM11 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM12   0x800U     // Enable EPWM12 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM13   0x1000U    // Enable EPWM13 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM14   0x2000U    // Enable EPWM14 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM15   0x4000U    // Enable EPWM15 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM16   0x8000U    // Enable EPWM16 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM17   0x10000U   // Enable EPWM17 instance for the XLINK feature
#define SYSCTL_EPWMXLINKCFG_EPWM18   0x20000U   // Enable EPWM18 instance for the XLINK feature

//*************************************************************************************************
//
// The following are defines for the bit fields in the SICCONFIG register
//
//*************************************************************************************************
#define SYSCTL_SICCONFIG_ENABLE      0x1U          // Safety Interconnect Enable
#define SYSCTL_SICCONFIG_TIMEOUT_S   16U
#define SYSCTL_SICCONFIG_TIMEOUT_M   0xFFFF0000U   // Safety Interconnect (SIC) READY TUMEOUT

//*************************************************************************************************
//
// The following are defines for the bit fields in the RSTSTAT register
//
//*************************************************************************************************
#define SYSCTL_RSTSTAT_CPU2   0x1U   // CPU2 Reset Status bit
#define SYSCTL_RSTSTAT_CPU3   0x2U   // CPU3 Reset Status bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPMSTAT register
//
//*************************************************************************************************
#define SYSCTL_LPMSTAT_CPU2_S   0U
#define SYSCTL_LPMSTAT_CPU2_M   0x3U   // CPU2 LPM Status
#define SYSCTL_LPMSTAT_CPU3_S   2U
#define SYSCTL_LPMSTAT_CPU3_M   0xCU   // CPU3 LPM Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the TAP_STATUS register
//
//*************************************************************************************************
#define SYSCTL_TAP_STATUS_TAP_STATE_S   0U
#define SYSCTL_TAP_STATUS_TAP_STATE_M   0xFFFFU       // Present TAP State
#define SYSCTL_TAP_STATUS_DCON          0x80000000U   // Debugger Connect Indication

//*************************************************************************************************
//
// The following are defines for the bit fields in the TAP_CONTROL register
//
//*************************************************************************************************
#define SYSCTL_TAP_CONTROL_BSCAN_DIS   0x1U          // Disable BSCAN TAP control
#define SYSCTL_TAP_CONTROL_KEY_S       16U
#define SYSCTL_TAP_CONTROL_KEY_M       0xFFFF0000U   // Key value to enable write

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEVLIFECYCLE register
//
//*************************************************************************************************
#define SYSCTL_DEVLIFECYCLE_DEVTYPE_S     0U
#define SYSCTL_DEVLIFECYCLE_DEVTYPE_M     0xFU       // These bits reflect the state from HSM
                                                     // DEVICE_TYPE
#define SYSCTL_DEVLIFECYCLE_HSSUBTYPE_S   8U
#define SYSCTL_DEVLIFECYCLE_HSSUBTYPE_M   0xF00U     // These bits reflect the state from the HSM
                                                     // HS_SUBTYPE
#define SYSCTL_DEVLIFECYCLE_OVRFLASH      0x10000U   // Status of Override mode with access to
                                                     // Flash
#define SYSCTL_DEVLIFECYCLE_OVRNOFLASH    0x20000U   // Status of Override mode with no access to
                                                     // Flash

//*************************************************************************************************
//
// The following are defines for the bit fields in the SDFMTYPE register
//
//*************************************************************************************************
#define SYSCTL_SDFMTYPE_TYPE_S   0U
#define SYSCTL_SDFMTYPE_TYPE_M   0x3U      // Configure SDFM type
#define SYSCTL_SDFMTYPE_LOCK     0x8000U   // Lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCSELECT register
//
//*************************************************************************************************
#define SYSCTL_SYNCSELECT_SYNCOUT_S   24U
#define SYSCTL_SYNCSELECT_SYNCOUT_M   0x1F000000U   // Select Syncout Source

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCOUTSELECT register
//
//*************************************************************************************************
#define SYSCTL_ADCSOCOUTSELECT_PWM1SOCAEN    0x1U          // PWM1SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM2SOCAEN    0x2U          // PWM2SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM3SOCAEN    0x4U          // PWM3SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM4SOCAEN    0x8U          // PWM4SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM5SOCAEN    0x10U         // PWM5SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM6SOCAEN    0x20U         // PWM6SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM7SOCAEN    0x40U         // PWM7SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM8SOCAEN    0x80U         // PWM8SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM9SOCAEN    0x100U        // PWM9SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM10SOCAEN   0x200U        // PWM10SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM11SOCAEN   0x400U        // PWM11SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM12SOCAEN   0x800U        // PWM12SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM13SOCAEN   0x1000U       // PWM13SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM14SOCAEN   0x2000U       // PWM14SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM15SOCAEN   0x4000U       // PWM15SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM16SOCAEN   0x8000U       // PWM16SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT_PWM1SOCBEN    0x10000U      // PWM1SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM2SOCBEN    0x20000U      // PWM2SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM3SOCBEN    0x40000U      // PWM3SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM4SOCBEN    0x80000U      // PWM4SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM5SOCBEN    0x100000U     // PWM5SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM6SOCBEN    0x200000U     // PWM6SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM7SOCBEN    0x400000U     // PWM7SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM8SOCBEN    0x800000U     // PWM8SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM9SOCBEN    0x1000000U    // PWM9SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM10SOBAEN   0x2000000U    // PWM10SOBAEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM11SOBAEN   0x4000000U    // PWM11SOBAEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM12SOBAEN   0x8000000U    // PWM12SOBAEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM13SOCBEN   0x10000000U   // PWM13SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM14SOBAEN   0x20000000U   // PWM14SOBAEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM15SOBAEN   0x40000000U   // PWM15SOBAEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT_PWM16SOBAEN   0x80000000U   // PWM16SOBAEN Enable for ADCSOCBOn

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSOCOUTSELECT1 register
//
//*************************************************************************************************
#define SYSCTL_ADCSOCOUTSELECT1_PWM17SOCAEN   0x1U       // PWM17SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT1_PWM18SOCAEN   0x2U       // PWM18SOCAEN Enable for ADCSOCAOn
#define SYSCTL_ADCSOCOUTSELECT1_PWM17SOCBEN   0x10000U   // PWM17SOCBEN Enable for ADCSOCBOn
#define SYSCTL_ADCSOCOUTSELECT1_PWM18SOCBEN   0x20000U   // PWM18SOCBEN Enable for ADCSOCBOn

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCSOCLOCK register
//
//*************************************************************************************************
#define SYSCTL_SYNCSOCLOCK_SYNCSELECT         0x1U   // SYNCSEL Register Lock bit
#define SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT    0x2U   // ADCSOCOUTSELECT Register Lock bit
#define SYSCTL_SYNCSOCLOCK_ADCSOCOUTSELECT1   0x4U   // ADCSOCOUTSELECT1 Register Lock bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the HSMTOCPU_STS1 register
//
//*************************************************************************************************
#define SYSCTL_HSMTOCPU_STS1_SRAM_BANK0     0x1U          // HSM to CPU USURP Communication Signal
                                                          // for SRAM_BANK0
#define SYSCTL_HSMTOCPU_STS1_SRAM_BANK1     0x2U          // HSM to CPU USURP Communication Signal
                                                          // for SRAM_BANK1
#define SYSCTL_HSMTOCPU_STS1_SRAM_BANK2     0x4U          // HSM to CPU USURP Communication Signal
                                                          // for SRAM_BANK2
#define SYSCTL_HSMTOCPU_STS1_SRAM_BANK3     0x8U          // HSM to CPU USURP Communication Signal
                                                          // for SRAM_BANK3
#define SYSCTL_HSMTOCPU_STS1_SRAM_BANK4     0x10U         // HSM to CPU USURP Communication Signal
                                                          // for SRAM_BANK4
#define SYSCTL_HSMTOCPU_STS1_SRAM_BANK5     0x20U         // HSM to CPU USURP Communication Signal
                                                          // for SRAM_BANK5
#define SYSCTL_HSMTOCPU_STS1_SRAM_BANK6     0x40U         // HSM to CPU USURP Communication Signal
                                                          // for SRAM_BANK6
#define SYSCTL_HSMTOCPU_STS1_SRAM_BANK7     0x80U         // HSM to CPU USURP Communication Signal
                                                          // for SRAM_BANK7
#define SYSCTL_HSMTOCPU_STS1_FLC1           0x100U        // HSM to CPU USURP Communication Signal
                                                          // for FLC1
#define SYSCTL_HSMTOCPU_STS1_FLC2           0x200U        // HSM to CPU USURP Communication Signal
                                                          // for FLC2
#define SYSCTL_HSMTOCPU_STS1_LPOST          0x400U        // HSM to CPU USURP Communication Signal
                                                          // for LPOST
#define SYSCTL_HSMTOCPU_STS1_MPOST          0x800U        // HSM to CPU USURP Communication Signal
                                                          // for MPOST
#define SYSCTL_HSMTOCPU_STS1_SOC_GENR_1_S   16U
#define SYSCTL_HSMTOCPU_STS1_SOC_GENR_1_M   0xFF0000U     // HSM to CPU USURP Communication Signal
                                                          // for SOC_GENR_1
#define SYSCTL_HSMTOCPU_STS1_SOC_GENR_2_S   24U
#define SYSCTL_HSMTOCPU_STS1_SOC_GENR_2_M   0xFF000000U   // HSM to CPU USURP Communication Signal
                                                          // for SOC_GENR_2

//*************************************************************************************************
//
// The following are defines for the bit fields in the HSMTOCPU_STS2 register
//
//*************************************************************************************************
#define SYSCTL_HSMTOCPU_STS2_FLC1_BANK0   0x1U         // HSM to CPU USURP Communication Signal for
                                                       // FLC1_BANK0
#define SYSCTL_HSMTOCPU_STS2_FLC2_BANK0   0x10U        // HSM to CPU USURP Communication Signal for
                                                       // FLC2_BANK0
#define SYSCTL_HSMTOCPU_STS2_FLC1_BANK1   0x20U        // HSM to CPU USURP Communication Signal for
                                                       // FLC1_BANK1
#define SYSCTL_HSMTOCPU_STS2_FLC2_BANK1   0x200U       // HSM to CPU USURP Communication Signal for
                                                       // FLC2_BANK1
#define SYSCTL_HSMTOCPU_STS2_FLC1_BANK2   0x400U       // HSM to CPU USURP Communication Signal for
                                                       // FLC1_BANK2
#define SYSCTL_HSMTOCPU_STS2_FLC2_BANK2   0x4000U      // HSM to CPU USURP Communication Signal for
                                                       // FLC2_BANK2
#define SYSCTL_HSMTOCPU_STS2_FLC1_BANK3   0x8000U      // HSM to CPU USURP Communication Signal for
                                                       // FLC1_BANK3
#define SYSCTL_HSMTOCPU_STS2_FLC2_BANK3   0x80000U     // HSM to CPU USURP Communication Signal for
                                                       // FLC2_BANK3
#define SYSCTL_HSMTOCPU_STS2_FLC1_BANK4   0x100000U    // HSM to CPU USURP Communication Signal for
                                                       // FLC1_BANK4
#define SYSCTL_HSMTOCPU_STS2_FLC2_BANK4   0x1000000U   // HSM to CPU USURP Communication Signal for
                                                       // FLC2_BANK4

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKCFGLOCK1 register
//
//*************************************************************************************************
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL1       0x1U        // Lock bit for CLKSRCCTL1 register
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL2       0x2U        // Lock bit for CLKSRCCTL2 register
#define SYSCTL_CLKCFGLOCK1_CLKSRCCTL3       0x4U        // Lock bit for CLKSRCCTL3 register
#define SYSCTL_CLKCFGLOCK1_SYSPLLCTL1       0x8U        // Lock bit for SYSPLLCTL1 register
#define SYSCTL_CLKCFGLOCK1_SYSPLLMULT       0x40U       // Lock bit for SYSPLLMULT register
#define SYSCTL_CLKCFGLOCK1_SYSCLKDIVSEL     0x800U      // Lock bit for SYSCLKDIVSEL register
#define SYSCTL_CLKCFGLOCK1_PERCLKDIVSEL     0x2000U     // Lock bit for PERCLKDIVSEL register
#define SYSCTL_CLKCFGLOCK1_CLBCLKCTL        0x4000U     // Lock bit for CLBCLKCTL register
#define SYSCTL_CLKCFGLOCK1_XTALCR           0x10000U    // Lock bit for XTALCR  & XTALCR2 register
#define SYSCTL_CLKCFGLOCK1_EXTRFLTDET       0x20000U    // Lockbit for EXTRFLTDET register
#define SYSCTL_CLKCFGLOCK1_ETHERCATCLKCTL   0x40000U    // Lockbit for ETHERCATCLKCTL register
#define SYSCTL_CLKCFGLOCK1_HSMCLKDIVSEL     0x80000U    // Lock bit for HSMCLKDIVSEL register
#define SYSCTL_CLKCFGLOCK1_MCANCLKDIVSEL    0x100000U   // Lock bit for MCANCLKDIVSEL register
#define SYSCTL_CLKCFGLOCK1_XCLKOUTDIVSEL    0x200000U   // Lock bit for XCLKOUTDIVSEL register

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL1 register
//
//*************************************************************************************************
#define SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_S   0U
#define SYSCTL_CLKSRCCTL1_OSCCLKSRCSEL_M   0x3U   // OSCCLK Source Select Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL2 register
//
//*************************************************************************************************
#define SYSCTL_CLKSRCCTL2_MCANABCLKSEL_S   10U
#define SYSCTL_CLKSRCCTL2_MCANABCLKSEL_M   0xC00U      // MCANA Bit Clock Source Select Bit
#define SYSCTL_CLKSRCCTL2_MCANBBCLKSEL_S   12U
#define SYSCTL_CLKSRCCTL2_MCANBBCLKSEL_M   0x3000U     // MCANB Bit Clock Source Select Bit
#define SYSCTL_CLKSRCCTL2_MCANCBCLKSEL_S   14U
#define SYSCTL_CLKSRCCTL2_MCANCBCLKSEL_M   0xC000U     // MCANC Bit Clock Source Select Bit
#define SYSCTL_CLKSRCCTL2_MCANDBCLKSEL_S   16U
#define SYSCTL_CLKSRCCTL2_MCANDBCLKSEL_M   0x30000U    // MCAND Bit Clock Source Select Bit
#define SYSCTL_CLKSRCCTL2_MCANEBCLKSEL_S   18U
#define SYSCTL_CLKSRCCTL2_MCANEBCLKSEL_M   0xC0000U    // MCANE Bit Clock Source Select Bit
#define SYSCTL_CLKSRCCTL2_MCANFBCLKSEL_S   20U
#define SYSCTL_CLKSRCCTL2_MCANFBCLKSEL_M   0x300000U   // MCANF Bit Clock Source Select Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSRCCTL3 register
//
//*************************************************************************************************
#define SYSCTL_CLKSRCCTL3_XCLKOUTSEL_S   0U
#define SYSCTL_CLKSRCCTL3_XCLKOUTSEL_M   0x1FU   // XCLKOUT Source Select Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSPLLCTL1 register
//
//*************************************************************************************************
#define SYSCTL_SYSPLLCTL1_PLLEN      0x1U   // SYSPLL enable/disable bit
#define SYSCTL_SYSPLLCTL1_PLLCLKEN   0x2U   // SYSPLL bypassed or included in the PLLSYSCLK path

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSPLLMULT register
//
//*************************************************************************************************
#define SYSCTL_SYSPLLMULT_IMULT_S    0U
#define SYSCTL_SYSPLLMULT_IMULT_M    0xFFU         // SYSPLL Integer Multiplier
#define SYSCTL_SYSPLLMULT_ODIV_S     16U
#define SYSCTL_SYSPLLMULT_ODIV_M     0x1F0000U     // Output Clock Divider
#define SYSCTL_SYSPLLMULT_REFDIV_S   24U
#define SYSCTL_SYSPLLMULT_REFDIV_M   0x1F000000U   // Reference Clock Divider

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSPLLSTS register
//
//*************************************************************************************************
#define SYSCTL_SYSPLLSTS_LOCKS                0x1U   // SYSPLL Lock Status Bit
#define SYSCTL_SYSPLLSTS_SLIPS_NOTSUPPORTED   0x2U   // SYSPLL Slip Status Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYSCLKDIVSEL register
//
//*************************************************************************************************
#define SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_S   0U
#define SYSCTL_SYSCLKDIVSEL_PLLSYSCLKDIV_M   0x3FU   // PLLSYSCLK Divide Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the PERCLKDIVSEL register
//
//*************************************************************************************************
#define SYSCTL_PERCLKDIVSEL_EPWMCLKDIV_S    0U
#define SYSCTL_PERCLKDIVSEL_EPWMCLKDIV_M    0x3U      // EPWM Clock Divide Select
#define SYSCTL_PERCLKDIVSEL_EMIF1CLKDIV_S   4U
#define SYSCTL_PERCLKDIVSEL_EMIF1CLKDIV_M   0x30U     // EMIF1  Clock Divide Select
#define SYSCTL_PERCLKDIVSEL_LINACLKDIV_S    8U
#define SYSCTL_PERCLKDIVSEL_LINACLKDIV_M    0x300U    // LINA Clock Divide Select
#define SYSCTL_PERCLKDIVSEL_LINBCLKDIV_S    11U
#define SYSCTL_PERCLKDIVSEL_LINBCLKDIV_M    0x1800U   // LINB Clock Divide Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the XCLKOUTDIVSEL register
//
//*************************************************************************************************
#define SYSCTL_XCLKOUTDIVSEL_XCLKOUTDIV_S   0U
#define SYSCTL_XCLKOUTDIVSEL_XCLKOUTDIV_M   0x3U   // XCLKOUT Divide Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the HSMCLKDIVSEL register
//
//*************************************************************************************************
#define SYSCTL_HSMCLKDIVSEL_HSMCLKDIV_S   0U
#define SYSCTL_HSMCLKDIVSEL_HSMCLKDIV_M   0x1FU   // Divider value for HSMSYSCLK clock input to HSM

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCANCLKDIVSEL register
//
//*************************************************************************************************
#define SYSCTL_MCANCLKDIVSEL_MCANACLKDIV_S   0U
#define SYSCTL_MCANCLKDIVSEL_MCANACLKDIV_M   0x1FU         // Divider CANFD Bit CLK for MCANA
#define SYSCTL_MCANCLKDIVSEL_MCANBCLKDIV_S   5U
#define SYSCTL_MCANCLKDIVSEL_MCANBCLKDIV_M   0x3E0U        // Divider CANFD Bit CLK for MCANB
#define SYSCTL_MCANCLKDIVSEL_MCANCCLKDIV_S   10U
#define SYSCTL_MCANCLKDIVSEL_MCANCCLKDIV_M   0x7C00U       // Divider CANFD Bit CLK for MCANC
#define SYSCTL_MCANCLKDIVSEL_MCANDCLKDIV_S   15U
#define SYSCTL_MCANCLKDIVSEL_MCANDCLKDIV_M   0xF8000U      // Divider CANFD Bit CLK for MCAND
#define SYSCTL_MCANCLKDIVSEL_MCANECLKDIV_S   20U
#define SYSCTL_MCANCLKDIVSEL_MCANECLKDIV_M   0x1F00000U    // Divider CANFD Bit CLK for MCANE
#define SYSCTL_MCANCLKDIVSEL_MCANFCLKDIV_S   25U
#define SYSCTL_MCANCLKDIVSEL_MCANFCLKDIV_M   0x3E000000U   // Divider CANFD Bit CLK for MCANF

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLBCLKCTL register
//
//*************************************************************************************************
#define SYSCTL_CLBCLKCTL_CLKMODECLB1   0x10000U    // Clock mode of CLB1
#define SYSCTL_CLBCLKCTL_CLKMODECLB2   0x20000U    // Clock mode of CLB2
#define SYSCTL_CLBCLKCTL_CLKMODECLB3   0x40000U    // Clock mode of CLB3
#define SYSCTL_CLBCLKCTL_CLKMODECLB4   0x80000U    // Clock mode of CLB4
#define SYSCTL_CLBCLKCTL_CLKMODECLB5   0x100000U   // Clock mode of CLB5
#define SYSCTL_CLBCLKCTL_CLKMODECLB6   0x200000U   // Clock mode of CLB6

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCDCR register
//
//*************************************************************************************************
#define SYSCTL_MCDCR_MCLKSTS              0x1U      // Missing Clock Status Bit
#define SYSCTL_MCDCR_MCLKCLR              0x2U      // Missing Clock Clear Bit
#define SYSCTL_MCDCR_MCLKOFF              0x4U      // Missing Clock Detect Off Bit
#define SYSCTL_MCDCR_OSCOFF               0x8U      // Oscillator Clock Off Bit
#define SYSCTL_MCDCR_SYSREF_LOSTS         0x10U     // SYSPLL "Reference  Lost" Status Bit
#define SYSCTL_MCDCR_SYSREF_LOSTSCLR      0x20U     // Clear for Ref clock lost status
#define SYSCTL_MCDCR_SYSREF_LOST_MCD_EN   0x40U     // Enable for PLL REF_CLK_LOST as MCD cause
#define SYSCTL_MCDCR_EXTR_FAULTS          0x400U    // External Resistor fault indication
#define SYSCTL_MCDCR_EXTR_FAULTSCLR       0x800U    // External Resistor fault status clear
#define SYSCTL_MCDCR_EXTR_FAULT_MCD_EN    0x1000U   // Configuration to enable EXTR_FAULTS as MCD
                                                    // cause

//*************************************************************************************************
//
// The following are defines for the bit fields in the X1CNT register
//
//*************************************************************************************************
#define SYSCTL_X1CNT_X1CNT_S   0U
#define SYSCTL_X1CNT_X1CNT_M   0x7FFU     // X1 Counter
#define SYSCTL_X1CNT_CLR       0x10000U   // X1 Counter Clear

//*************************************************************************************************
//
// The following are defines for the bit fields in the XTALCR register
//
//*************************************************************************************************
#define SYSCTL_XTALCR_OSCOFF   0x1U   // XTAL Oscillator powered-down
#define SYSCTL_XTALCR_SE       0x2U   // XTAL Oscilator in Single-Ended mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the XTALCR2 register
//
//*************************************************************************************************
#define SYSCTL_XTALCR2_XIF   0x1U   // XI Initial value deposited before XOSC start
#define SYSCTL_XTALCR2_XOF   0x2U   // XO Initial value deposited before XOSC start
#define SYSCTL_XTALCR2_FEN   0x4U   // XOSC pads initialisation enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ETHERCATCLKCTL register
//
//*************************************************************************************************
#define SYSCTL_ETHERCATCLKCTL_ECATDIV_S   1U
#define SYSCTL_ETHERCATCLKCTL_ECATDIV_M   0xEU     // etherCAT clock divider configuration.
#define SYSCTL_ETHERCATCLKCTL_PHYCLKEN    0x100U   // etherCAT PHY clock enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ETHERCATCTL register
//
//*************************************************************************************************
#define SYSCTL_ETHERCATCTL_I2CLOOPBACK   0x1U   // Loopback I2C port of etherCAT IP to I2C_A.

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCBUSY register
//
//*************************************************************************************************
#define SYSCTL_SYNCBUSY_BUSY             0x1U          // Status bit indicating synchronization in
                                                       // progress
#define SYSCTL_SYNCBUSY_MCANCLKDIVSEL    0x10000U      // BUSY status bit for MCANCLKDIVSEL
#define SYSCTL_SYNCBUSY_CLBCLKCTL        0x40000U      // BUSY status bit for CLBCLKCTL
#define SYSCTL_SYNCBUSY_ETHERCATCLKCTL   0x80000U      // BUSY status bit for ETHERCATCLKCTL
#define SYSCTL_SYNCBUSY_PERCLKDIVSEL     0x100000U     // BUSY status bit for PERCLKDIVSEL
#define SYSCTL_SYNCBUSY_SYSCLKDIVSEL     0x200000U     // BUSY status bit for SYSCLKDIVSEL
#define SYSCTL_SYNCBUSY_SYSPLLCTL1       0x400000U     // BUSY status bit for SYSPLLCTL1
#define SYSCTL_SYNCBUSY_SYSPLLMULT       0x800000U     // BUSY status bit for SYSPLLMULT
#define SYSCTL_SYNCBUSY_XCLKOUTDIVSEL    0x1000000U    // BUSY status bit for XCLKOUTDIVSEL
#define SYSCTL_SYNCBUSY_XTALCR           0x2000000U    // BUSY status bit for XTALCR
#define SYSCTL_SYNCBUSY_CLKSRCCTL1       0x4000000U    // BUSY status bit for CLKSRCCTL1
#define SYSCTL_SYNCBUSY_CLKSRCCTL2       0x8000000U    // BUSY status bit for CLKSRCCTL2
#define SYSCTL_SYNCBUSY_CLKSRCCTL3       0x10000000U   // BUSY status bit for CLKSRCCTL3
#define SYSCTL_SYNCBUSY_CPU3TMR2CTL      0x20000000U   // BUSY status bit for CPU3TMR2CTL
#define SYSCTL_SYNCBUSY_CPU1TMR2CTL      0x40000000U   // BUSY status bit for CPU1TMR2CTL
#define SYSCTL_SYNCBUSY_CPU2TMR2CTL      0x80000000U   // BUSY status bit for CPU2TMR2CTL

//*************************************************************************************************
//
// The following are defines for the bit fields in the ESMXRSNCTL register
//
//*************************************************************************************************
#define SYSCTL_ESMXRSNCTL_ESMCPU1CRITICAL   0x1U       // Enable ESMCPU1CRITICAL to cause XRSn
#define SYSCTL_ESMXRSNCTL_ESMCPU2CRITICAL   0x4U       // Enable ESMCPU2CRITICAL to cause XRSn
#define SYSCTL_ESMXRSNCTL_ESMCPU2HIPRIWD    0x8U       // Enable ESMCPU2HIPRIWD to cause XRSn
#define SYSCTL_ESMXRSNCTL_ESMCPU3CRITICAL   0x10U      // Enable ESMCPU3CRITICAL to cause XRSn
#define SYSCTL_ESMXRSNCTL_ESMCPU3HIPRIWD    0x20U      // Enable ESMCPU3HIPRIWD to cause XRSn
#define SYSCTL_ESMXRSNCTL_ESMRESET          0x10000U   // Enable ESMRESET to cause XRSn

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM1 register
//
//*************************************************************************************************
#define SYSCTL_EPWM1_FRAMESEL_S   0U
#define SYSCTL_EPWM1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM1_CPUSEL_S     3U
#define SYSCTL_EPWM1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM2 register
//
//*************************************************************************************************
#define SYSCTL_EPWM2_FRAMESEL_S   0U
#define SYSCTL_EPWM2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM2_CPUSEL_S     3U
#define SYSCTL_EPWM2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM3 register
//
//*************************************************************************************************
#define SYSCTL_EPWM3_FRAMESEL_S   0U
#define SYSCTL_EPWM3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM3_CPUSEL_S     3U
#define SYSCTL_EPWM3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM4 register
//
//*************************************************************************************************
#define SYSCTL_EPWM4_FRAMESEL_S   0U
#define SYSCTL_EPWM4_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM4_CPUSEL_S     3U
#define SYSCTL_EPWM4_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM4_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM4_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM5 register
//
//*************************************************************************************************
#define SYSCTL_EPWM5_FRAMESEL_S   0U
#define SYSCTL_EPWM5_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM5_CPUSEL_S     3U
#define SYSCTL_EPWM5_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM5_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM5_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM6 register
//
//*************************************************************************************************
#define SYSCTL_EPWM6_FRAMESEL_S   0U
#define SYSCTL_EPWM6_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM6_CPUSEL_S     3U
#define SYSCTL_EPWM6_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM6_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM6_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM7 register
//
//*************************************************************************************************
#define SYSCTL_EPWM7_FRAMESEL_S   0U
#define SYSCTL_EPWM7_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM7_CPUSEL_S     3U
#define SYSCTL_EPWM7_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM7_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM7_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM8 register
//
//*************************************************************************************************
#define SYSCTL_EPWM8_FRAMESEL_S   0U
#define SYSCTL_EPWM8_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM8_CPUSEL_S     3U
#define SYSCTL_EPWM8_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM8_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM8_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM9 register
//
//*************************************************************************************************
#define SYSCTL_EPWM9_FRAMESEL_S   0U
#define SYSCTL_EPWM9_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM9_CPUSEL_S     3U
#define SYSCTL_EPWM9_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM9_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EPWM9_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM10 register
//
//*************************************************************************************************
#define SYSCTL_EPWM10_FRAMESEL_S   0U
#define SYSCTL_EPWM10_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM10_CPUSEL_S     3U
#define SYSCTL_EPWM10_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM10_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM10_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM11 register
//
//*************************************************************************************************
#define SYSCTL_EPWM11_FRAMESEL_S   0U
#define SYSCTL_EPWM11_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM11_CPUSEL_S     3U
#define SYSCTL_EPWM11_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM11_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM11_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM12 register
//
//*************************************************************************************************
#define SYSCTL_EPWM12_FRAMESEL_S   0U
#define SYSCTL_EPWM12_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM12_CPUSEL_S     3U
#define SYSCTL_EPWM12_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM12_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM12_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM13 register
//
//*************************************************************************************************
#define SYSCTL_EPWM13_FRAMESEL_S   0U
#define SYSCTL_EPWM13_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM13_CPUSEL_S     3U
#define SYSCTL_EPWM13_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM13_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM13_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM14 register
//
//*************************************************************************************************
#define SYSCTL_EPWM14_FRAMESEL_S   0U
#define SYSCTL_EPWM14_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM14_CPUSEL_S     3U
#define SYSCTL_EPWM14_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM14_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM14_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM15 register
//
//*************************************************************************************************
#define SYSCTL_EPWM15_FRAMESEL_S   0U
#define SYSCTL_EPWM15_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM15_CPUSEL_S     3U
#define SYSCTL_EPWM15_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM15_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM15_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM16 register
//
//*************************************************************************************************
#define SYSCTL_EPWM16_FRAMESEL_S   0U
#define SYSCTL_EPWM16_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM16_CPUSEL_S     3U
#define SYSCTL_EPWM16_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM16_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM16_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM17 register
//
//*************************************************************************************************
#define SYSCTL_EPWM17_FRAMESEL_S   0U
#define SYSCTL_EPWM17_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM17_CPUSEL_S     3U
#define SYSCTL_EPWM17_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM17_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM17_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPWM18 register
//
//*************************************************************************************************
#define SYSCTL_EPWM18_FRAMESEL_S   0U
#define SYSCTL_EPWM18_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPWM18_CPUSEL_S     3U
#define SYSCTL_EPWM18_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPWM18_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_EPWM18_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the HRCAL0 register
//
//*************************************************************************************************
#define SYSCTL_HRCAL0_FRAMESEL_S   0U
#define SYSCTL_HRCAL0_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_HRCAL0_CPUSEL_S     3U
#define SYSCTL_HRCAL0_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_HRCAL0_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_HRCAL0_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the HRCAL1 register
//
//*************************************************************************************************
#define SYSCTL_HRCAL1_FRAMESEL_S   0U
#define SYSCTL_HRCAL1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_HRCAL1_CPUSEL_S     3U
#define SYSCTL_HRCAL1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_HRCAL1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_HRCAL1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the HRCAL2 register
//
//*************************************************************************************************
#define SYSCTL_HRCAL2_FRAMESEL_S   0U
#define SYSCTL_HRCAL2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_HRCAL2_CPUSEL_S     3U
#define SYSCTL_HRCAL2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_HRCAL2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_HRCAL2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP1 register
//
//*************************************************************************************************
#define SYSCTL_ECAP1_FRAMESEL_S   0U
#define SYSCTL_ECAP1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ECAP1_CPUSEL_S     3U
#define SYSCTL_ECAP1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ECAP1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_ECAP1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP2 register
//
//*************************************************************************************************
#define SYSCTL_ECAP2_FRAMESEL_S   0U
#define SYSCTL_ECAP2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ECAP2_CPUSEL_S     3U
#define SYSCTL_ECAP2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ECAP2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_ECAP2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP3 register
//
//*************************************************************************************************
#define SYSCTL_ECAP3_FRAMESEL_S   0U
#define SYSCTL_ECAP3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ECAP3_CPUSEL_S     3U
#define SYSCTL_ECAP3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ECAP3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_ECAP3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP4 register
//
//*************************************************************************************************
#define SYSCTL_ECAP4_FRAMESEL_S   0U
#define SYSCTL_ECAP4_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ECAP4_CPUSEL_S     3U
#define SYSCTL_ECAP4_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ECAP4_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_ECAP4_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP5 register
//
//*************************************************************************************************
#define SYSCTL_ECAP5_FRAMESEL_S   0U
#define SYSCTL_ECAP5_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ECAP5_CPUSEL_S     3U
#define SYSCTL_ECAP5_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ECAP5_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_ECAP5_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ECAP6 register
//
//*************************************************************************************************
#define SYSCTL_ECAP6_FRAMESEL_S   0U
#define SYSCTL_ECAP6_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ECAP6_CPUSEL_S     3U
#define SYSCTL_ECAP6_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ECAP6_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_ECAP6_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEP1 register
//
//*************************************************************************************************
#define SYSCTL_EQEP1_FRAMESEL_S   0U
#define SYSCTL_EQEP1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EQEP1_CPUSEL_S     3U
#define SYSCTL_EQEP1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EQEP1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EQEP1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEP2 register
//
//*************************************************************************************************
#define SYSCTL_EQEP2_FRAMESEL_S   0U
#define SYSCTL_EQEP2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EQEP2_CPUSEL_S     3U
#define SYSCTL_EQEP2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EQEP2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EQEP2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEP3 register
//
//*************************************************************************************************
#define SYSCTL_EQEP3_FRAMESEL_S   0U
#define SYSCTL_EQEP3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EQEP3_CPUSEL_S     3U
#define SYSCTL_EQEP3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EQEP3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EQEP3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEP4 register
//
//*************************************************************************************************
#define SYSCTL_EQEP4_FRAMESEL_S   0U
#define SYSCTL_EQEP4_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EQEP4_CPUSEL_S     3U
#define SYSCTL_EQEP4_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EQEP4_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EQEP4_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEP5 register
//
//*************************************************************************************************
#define SYSCTL_EQEP5_FRAMESEL_S   0U
#define SYSCTL_EQEP5_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EQEP5_CPUSEL_S     3U
#define SYSCTL_EQEP5_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EQEP5_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EQEP5_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EQEP6 register
//
//*************************************************************************************************
#define SYSCTL_EQEP6_FRAMESEL_S   0U
#define SYSCTL_EQEP6_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EQEP6_CPUSEL_S     3U
#define SYSCTL_EQEP6_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EQEP6_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_EQEP6_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SDFM1 register
//
//*************************************************************************************************
#define SYSCTL_SDFM1_FRAMESEL_S   0U
#define SYSCTL_SDFM1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SDFM1_CPUSEL_S     3U
#define SYSCTL_SDFM1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SDFM1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SDFM1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SDFM2 register
//
//*************************************************************************************************
#define SYSCTL_SDFM2_FRAMESEL_S   0U
#define SYSCTL_SDFM2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SDFM2_CPUSEL_S     3U
#define SYSCTL_SDFM2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SDFM2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SDFM2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SDFM3 register
//
//*************************************************************************************************
#define SYSCTL_SDFM3_FRAMESEL_S   0U
#define SYSCTL_SDFM3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SDFM3_CPUSEL_S     3U
#define SYSCTL_SDFM3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SDFM3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SDFM3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SDFM4 register
//
//*************************************************************************************************
#define SYSCTL_SDFM4_FRAMESEL_S   0U
#define SYSCTL_SDFM4_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SDFM4_CPUSEL_S     3U
#define SYSCTL_SDFM4_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SDFM4_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SDFM4_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the UARTA register
//
//*************************************************************************************************
#define SYSCTL_UARTA_FRAMESEL_S   0U
#define SYSCTL_UARTA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_UARTA_CPUSEL_S     3U
#define SYSCTL_UARTA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_UARTA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_UARTA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the UARTB register
//
//*************************************************************************************************
#define SYSCTL_UARTB_FRAMESEL_S   0U
#define SYSCTL_UARTB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_UARTB_CPUSEL_S     3U
#define SYSCTL_UARTB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_UARTB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_UARTB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the UARTC register
//
//*************************************************************************************************
#define SYSCTL_UARTC_FRAMESEL_S   0U
#define SYSCTL_UARTC_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_UARTC_CPUSEL_S     3U
#define SYSCTL_UARTC_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_UARTC_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_UARTC_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the UARTD register
//
//*************************************************************************************************
#define SYSCTL_UARTD_FRAMESEL_S   0U
#define SYSCTL_UARTD_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_UARTD_CPUSEL_S     3U
#define SYSCTL_UARTD_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_UARTD_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_UARTD_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the UARTE register
//
//*************************************************************************************************
#define SYSCTL_UARTE_FRAMESEL_S   0U
#define SYSCTL_UARTE_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_UARTE_CPUSEL_S     3U
#define SYSCTL_UARTE_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_UARTE_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_UARTE_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the UARTF register
//
//*************************************************************************************************
#define SYSCTL_UARTF_FRAMESEL_S   0U
#define SYSCTL_UARTF_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_UARTF_CPUSEL_S     3U
#define SYSCTL_UARTF_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_UARTF_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_UARTF_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIA register
//
//*************************************************************************************************
#define SYSCTL_SPIA_FRAMESEL_S   0U
#define SYSCTL_SPIA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SPIA_CPUSEL_S     3U
#define SYSCTL_SPIA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SPIA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_SPIA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIB register
//
//*************************************************************************************************
#define SYSCTL_SPIB_FRAMESEL_S   0U
#define SYSCTL_SPIB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SPIB_CPUSEL_S     3U
#define SYSCTL_SPIB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SPIB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_SPIB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIC register
//
//*************************************************************************************************
#define SYSCTL_SPIC_FRAMESEL_S   0U
#define SYSCTL_SPIC_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SPIC_CPUSEL_S     3U
#define SYSCTL_SPIC_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SPIC_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_SPIC_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPID register
//
//*************************************************************************************************
#define SYSCTL_SPID_FRAMESEL_S   0U
#define SYSCTL_SPID_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SPID_CPUSEL_S     3U
#define SYSCTL_SPID_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SPID_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_SPID_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SPIE register
//
//*************************************************************************************************
#define SYSCTL_SPIE_FRAMESEL_S   0U
#define SYSCTL_SPIE_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SPIE_CPUSEL_S     3U
#define SYSCTL_SPIE_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SPIE_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_SPIE_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2CA register
//
//*************************************************************************************************
#define SYSCTL_I2CA_FRAMESEL_S   0U
#define SYSCTL_I2CA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_I2CA_CPUSEL_S     3U
#define SYSCTL_I2CA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_I2CA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_I2CA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the I2CB register
//
//*************************************************************************************************
#define SYSCTL_I2CB_FRAMESEL_S   0U
#define SYSCTL_I2CB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_I2CB_CPUSEL_S     3U
#define SYSCTL_I2CB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_I2CB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_I2CB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the PMBUSA register
//
//*************************************************************************************************
#define SYSCTL_PMBUSA_FRAMESEL_S   0U
#define SYSCTL_PMBUSA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_PMBUSA_CPUSEL_S     3U
#define SYSCTL_PMBUSA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_PMBUSA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_PMBUSA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINA register
//
//*************************************************************************************************
#define SYSCTL_LINA_FRAMESEL_S   0U
#define SYSCTL_LINA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_LINA_CPUSEL_S     3U
#define SYSCTL_LINA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_LINA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_LINA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINB register
//
//*************************************************************************************************
#define SYSCTL_LINB_FRAMESEL_S   0U
#define SYSCTL_LINB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_LINB_CPUSEL_S     3U
#define SYSCTL_LINB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_LINB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_LINB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCANA register
//
//*************************************************************************************************
#define SYSCTL_MCANA_FRAMESEL_S   0U
#define SYSCTL_MCANA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_MCANA_CPUSEL_S     3U
#define SYSCTL_MCANA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_MCANA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_MCANA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCANB register
//
//*************************************************************************************************
#define SYSCTL_MCANB_FRAMESEL_S   0U
#define SYSCTL_MCANB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_MCANB_CPUSEL_S     3U
#define SYSCTL_MCANB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_MCANB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_MCANB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCANC register
//
//*************************************************************************************************
#define SYSCTL_MCANC_FRAMESEL_S   0U
#define SYSCTL_MCANC_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_MCANC_CPUSEL_S     3U
#define SYSCTL_MCANC_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_MCANC_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_MCANC_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCAND register
//
//*************************************************************************************************
#define SYSCTL_MCAND_FRAMESEL_S   0U
#define SYSCTL_MCAND_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_MCAND_CPUSEL_S     3U
#define SYSCTL_MCAND_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_MCAND_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_MCAND_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCANE register
//
//*************************************************************************************************
#define SYSCTL_MCANE_FRAMESEL_S   0U
#define SYSCTL_MCANE_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_MCANE_CPUSEL_S     3U
#define SYSCTL_MCANE_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_MCANE_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_MCANE_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCANF register
//
//*************************************************************************************************
#define SYSCTL_MCANF_FRAMESEL_S   0U
#define SYSCTL_MCANF_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_MCANF_CPUSEL_S     3U
#define SYSCTL_MCANF_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_MCANF_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_MCANF_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCA register
//
//*************************************************************************************************
#define SYSCTL_ADCA_FRAMESEL_S   0U
#define SYSCTL_ADCA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCA_CPUSEL_S     3U
#define SYSCTL_ADCA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_ADCA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCB register
//
//*************************************************************************************************
#define SYSCTL_ADCB_FRAMESEL_S   0U
#define SYSCTL_ADCB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCB_CPUSEL_S     3U
#define SYSCTL_ADCB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_ADCB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCC register
//
//*************************************************************************************************
#define SYSCTL_ADCC_FRAMESEL_S   0U
#define SYSCTL_ADCC_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCC_CPUSEL_S     3U
#define SYSCTL_ADCC_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCC_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_ADCC_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCD register
//
//*************************************************************************************************
#define SYSCTL_ADCD_FRAMESEL_S   0U
#define SYSCTL_ADCD_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCD_CPUSEL_S     3U
#define SYSCTL_ADCD_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCD_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_ADCD_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCE register
//
//*************************************************************************************************
#define SYSCTL_ADCE_FRAMESEL_S   0U
#define SYSCTL_ADCE_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCE_CPUSEL_S     3U
#define SYSCTL_ADCE_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCE_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_ADCE_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS1 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS1_FRAMESEL_S   0U
#define SYSCTL_CMPSS1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS1_CPUSEL_S     3U
#define SYSCTL_CMPSS1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS2 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS2_FRAMESEL_S   0U
#define SYSCTL_CMPSS2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS2_CPUSEL_S     3U
#define SYSCTL_CMPSS2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS3 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS3_FRAMESEL_S   0U
#define SYSCTL_CMPSS3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS3_CPUSEL_S     3U
#define SYSCTL_CMPSS3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS4 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS4_FRAMESEL_S   0U
#define SYSCTL_CMPSS4_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS4_CPUSEL_S     3U
#define SYSCTL_CMPSS4_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS4_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS4_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS5 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS5_FRAMESEL_S   0U
#define SYSCTL_CMPSS5_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS5_CPUSEL_S     3U
#define SYSCTL_CMPSS5_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS5_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS5_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS6 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS6_FRAMESEL_S   0U
#define SYSCTL_CMPSS6_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS6_CPUSEL_S     3U
#define SYSCTL_CMPSS6_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS6_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS6_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS7 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS7_FRAMESEL_S   0U
#define SYSCTL_CMPSS7_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS7_CPUSEL_S     3U
#define SYSCTL_CMPSS7_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS7_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS7_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS8 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS8_FRAMESEL_S   0U
#define SYSCTL_CMPSS8_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS8_CPUSEL_S     3U
#define SYSCTL_CMPSS8_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS8_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS8_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS9 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS9_FRAMESEL_S   0U
#define SYSCTL_CMPSS9_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS9_CPUSEL_S     3U
#define SYSCTL_CMPSS9_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS9_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_CMPSS9_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS10 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS10_FRAMESEL_S   0U
#define SYSCTL_CMPSS10_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS10_CPUSEL_S     3U
#define SYSCTL_CMPSS10_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS10_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                            // CPUx
#define SYSCTL_CMPSS10_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                            // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS11 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS11_FRAMESEL_S   0U
#define SYSCTL_CMPSS11_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS11_CPUSEL_S     3U
#define SYSCTL_CMPSS11_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS11_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                            // CPUx
#define SYSCTL_CMPSS11_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                            // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSS12 register
//
//*************************************************************************************************
#define SYSCTL_CMPSS12_FRAMESEL_S   0U
#define SYSCTL_CMPSS12_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CMPSS12_CPUSEL_S     3U
#define SYSCTL_CMPSS12_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CMPSS12_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                            // CPUx
#define SYSCTL_CMPSS12_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                            // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the DACA register
//
//*************************************************************************************************
#define SYSCTL_DACA_FRAMESEL_S   0U
#define SYSCTL_DACA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_DACA_CPUSEL_S     3U
#define SYSCTL_DACA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_DACA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_DACA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the DACB register
//
//*************************************************************************************************
#define SYSCTL_DACB_FRAMESEL_S   0U
#define SYSCTL_DACB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_DACB_CPUSEL_S     3U
#define SYSCTL_DACB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_DACB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_DACB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLB1 register
//
//*************************************************************************************************
#define SYSCTL_CLB1_FRAMESEL_S   0U
#define SYSCTL_CLB1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CLB1_CPUSEL_S     3U
#define SYSCTL_CLB1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CLB1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_CLB1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLB2 register
//
//*************************************************************************************************
#define SYSCTL_CLB2_FRAMESEL_S   0U
#define SYSCTL_CLB2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CLB2_CPUSEL_S     3U
#define SYSCTL_CLB2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CLB2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_CLB2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLB3 register
//
//*************************************************************************************************
#define SYSCTL_CLB3_FRAMESEL_S   0U
#define SYSCTL_CLB3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CLB3_CPUSEL_S     3U
#define SYSCTL_CLB3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CLB3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_CLB3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLB4 register
//
//*************************************************************************************************
#define SYSCTL_CLB4_FRAMESEL_S   0U
#define SYSCTL_CLB4_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CLB4_CPUSEL_S     3U
#define SYSCTL_CLB4_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CLB4_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_CLB4_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLB5 register
//
//*************************************************************************************************
#define SYSCTL_CLB5_FRAMESEL_S   0U
#define SYSCTL_CLB5_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CLB5_CPUSEL_S     3U
#define SYSCTL_CLB5_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CLB5_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_CLB5_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLB6 register
//
//*************************************************************************************************
#define SYSCTL_CLB6_FRAMESEL_S   0U
#define SYSCTL_CLB6_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_CLB6_CPUSEL_S     3U
#define SYSCTL_CLB6_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_CLB6_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_CLB6_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSITXA register
//
//*************************************************************************************************
#define SYSCTL_FSITXA_FRAMESEL_S   0U
#define SYSCTL_FSITXA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_FSITXA_CPUSEL_S     3U
#define SYSCTL_FSITXA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_FSITXA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_FSITXA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSITXB register
//
//*************************************************************************************************
#define SYSCTL_FSITXB_FRAMESEL_S   0U
#define SYSCTL_FSITXB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_FSITXB_CPUSEL_S     3U
#define SYSCTL_FSITXB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_FSITXB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_FSITXB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSITXC register
//
//*************************************************************************************************
#define SYSCTL_FSITXC_FRAMESEL_S   0U
#define SYSCTL_FSITXC_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_FSITXC_CPUSEL_S     3U
#define SYSCTL_FSITXC_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_FSITXC_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_FSITXC_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSITXD register
//
//*************************************************************************************************
#define SYSCTL_FSITXD_FRAMESEL_S   0U
#define SYSCTL_FSITXD_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_FSITXD_CPUSEL_S     3U
#define SYSCTL_FSITXD_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_FSITXD_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_FSITXD_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSIRXA register
//
//*************************************************************************************************
#define SYSCTL_FSIRXA_FRAMESEL_S   0U
#define SYSCTL_FSIRXA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_FSIRXA_CPUSEL_S     3U
#define SYSCTL_FSIRXA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_FSIRXA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_FSIRXA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSIRXB register
//
//*************************************************************************************************
#define SYSCTL_FSIRXB_FRAMESEL_S   0U
#define SYSCTL_FSIRXB_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_FSIRXB_CPUSEL_S     3U
#define SYSCTL_FSIRXB_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_FSIRXB_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_FSIRXB_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSIRXC register
//
//*************************************************************************************************
#define SYSCTL_FSIRXC_FRAMESEL_S   0U
#define SYSCTL_FSIRXC_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_FSIRXC_CPUSEL_S     3U
#define SYSCTL_FSIRXC_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_FSIRXC_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_FSIRXC_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the FSIRXD register
//
//*************************************************************************************************
#define SYSCTL_FSIRXD_FRAMESEL_S   0U
#define SYSCTL_FSIRXD_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_FSIRXD_CPUSEL_S     3U
#define SYSCTL_FSIRXD_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_FSIRXD_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                           // CPUx
#define SYSCTL_FSIRXD_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                           // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the DCC1 register
//
//*************************************************************************************************
#define SYSCTL_DCC1_FRAMESEL_S   0U
#define SYSCTL_DCC1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_DCC1_CPUSEL_S     3U
#define SYSCTL_DCC1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_DCC1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_DCC1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the DCC2 register
//
//*************************************************************************************************
#define SYSCTL_DCC2_FRAMESEL_S   0U
#define SYSCTL_DCC2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_DCC2_CPUSEL_S     3U
#define SYSCTL_DCC2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_DCC2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_DCC2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the DCC3 register
//
//*************************************************************************************************
#define SYSCTL_DCC3_FRAMESEL_S   0U
#define SYSCTL_DCC3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_DCC3_CPUSEL_S     3U
#define SYSCTL_DCC3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_DCC3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_DCC3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ETHERCATA register
//
//*************************************************************************************************
#define SYSCTL_ETHERCATA_FRAMESEL_S   0U
#define SYSCTL_ETHERCATA_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ETHERCATA_CPUSEL_S     3U
#define SYSCTL_ETHERCATA_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ETHERCATA_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based
                                              // on CPUx
#define SYSCTL_ETHERCATA_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based
                                              // on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the EPG1 register
//
//*************************************************************************************************
#define SYSCTL_EPG1_FRAMESEL_S   0U
#define SYSCTL_EPG1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_EPG1_CPUSEL_S     3U
#define SYSCTL_EPG1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_EPG1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                         // CPUx
#define SYSCTL_EPG1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                         // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SENT1 register
//
//*************************************************************************************************
#define SYSCTL_SENT1_FRAMESEL_S   0U
#define SYSCTL_SENT1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SENT1_CPUSEL_S     3U
#define SYSCTL_SENT1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SENT1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SENT1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SENT2 register
//
//*************************************************************************************************
#define SYSCTL_SENT2_FRAMESEL_S   0U
#define SYSCTL_SENT2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SENT2_CPUSEL_S     3U
#define SYSCTL_SENT2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SENT2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SENT2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SENT3 register
//
//*************************************************************************************************
#define SYSCTL_SENT3_FRAMESEL_S   0U
#define SYSCTL_SENT3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SENT3_CPUSEL_S     3U
#define SYSCTL_SENT3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SENT3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SENT3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SENT4 register
//
//*************************************************************************************************
#define SYSCTL_SENT4_FRAMESEL_S   0U
#define SYSCTL_SENT4_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SENT4_CPUSEL_S     3U
#define SYSCTL_SENT4_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SENT4_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SENT4_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SENT5 register
//
//*************************************************************************************************
#define SYSCTL_SENT5_FRAMESEL_S   0U
#define SYSCTL_SENT5_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SENT5_CPUSEL_S     3U
#define SYSCTL_SENT5_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SENT5_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SENT5_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the SENT6 register
//
//*************************************************************************************************
#define SYSCTL_SENT6_FRAMESEL_S   0U
#define SYSCTL_SENT6_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_SENT6_CPUSEL_S     3U
#define SYSCTL_SENT6_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_SENT6_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_SENT6_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER1 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER1_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER1_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER2 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER2_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER2_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER3 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER3_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER3_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER4 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER4_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER4_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER4_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER4_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER4_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER4_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER5 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER5_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER5_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER5_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER5_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER5_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER5_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER6 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER6_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER6_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER6_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER6_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER6_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER6_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER7 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER7_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER7_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER7_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER7_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER7_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER7_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER8 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER8_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER8_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER8_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER8_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER8_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER8_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER9 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER9_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER9_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER9_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER9_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER9_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_ADCCHECKER9_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCCHECKER10 register
//
//*************************************************************************************************
#define SYSCTL_ADCCHECKER10_FRAMESEL_S   0U
#define SYSCTL_ADCCHECKER10_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER10_CPUSEL_S     3U
#define SYSCTL_ADCCHECKER10_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCCHECKER10_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                 // based on CPUx
#define SYSCTL_ADCCHECKER10_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                 // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSEAGGRCPU1 register
//
//*************************************************************************************************
#define SYSCTL_ADCSEAGGRCPU1_FRAMESEL_S   0U
#define SYSCTL_ADCSEAGGRCPU1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCSEAGGRCPU1_CPUSEL_S     3U
#define SYSCTL_ADCSEAGGRCPU1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCSEAGGRCPU1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                  // based on CPUx
#define SYSCTL_ADCSEAGGRCPU1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                  // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSEAGGRCPU2 register
//
//*************************************************************************************************
#define SYSCTL_ADCSEAGGRCPU2_FRAMESEL_S   0U
#define SYSCTL_ADCSEAGGRCPU2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCSEAGGRCPU2_CPUSEL_S     3U
#define SYSCTL_ADCSEAGGRCPU2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCSEAGGRCPU2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                  // based on CPUx
#define SYSCTL_ADCSEAGGRCPU2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                  // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADCSEAGGRCPU3 register
//
//*************************************************************************************************
#define SYSCTL_ADCSEAGGRCPU3_FRAMESEL_S   0U
#define SYSCTL_ADCSEAGGRCPU3_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADCSEAGGRCPU3_CPUSEL_S     3U
#define SYSCTL_ADCSEAGGRCPU3_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADCSEAGGRCPU3_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                  // based on CPUx
#define SYSCTL_ADCSEAGGRCPU3_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                  // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA1CH register
//
//*************************************************************************************************
#define SYSCTL_RTDMA1CH_FRAMESEL_S   0U
#define SYSCTL_RTDMA1CH_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_RTDMA1CH_CPUSEL_S     3U
#define SYSCTL_RTDMA1CH_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_RTDMA1CH_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based
                                             // on CPUx
#define SYSCTL_RTDMA1CH_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based
                                             // on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTDMA2CH register
//
//*************************************************************************************************
#define SYSCTL_RTDMA2CH_FRAMESEL_S   0U
#define SYSCTL_RTDMA2CH_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_RTDMA2CH_CPUSEL_S     3U
#define SYSCTL_RTDMA2CH_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_RTDMA2CH_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based
                                             // on CPUx
#define SYSCTL_RTDMA2CH_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based
                                             // on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the WADI1 register
//
//*************************************************************************************************
#define SYSCTL_WADI1_FRAMESEL_S   0U
#define SYSCTL_WADI1_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_WADI1_CPUSEL_S     3U
#define SYSCTL_WADI1_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_WADI1_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_WADI1_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the WADI2 register
//
//*************************************************************************************************
#define SYSCTL_WADI2_FRAMESEL_S   0U
#define SYSCTL_WADI2_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_WADI2_CPUSEL_S     3U
#define SYSCTL_WADI2_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_WADI2_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                          // CPUx
#define SYSCTL_WADI2_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                          // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the INPUTXBARFLAGS register
//
//*************************************************************************************************
#define SYSCTL_INPUTXBARFLAGS_FRAMESEL_S   0U
#define SYSCTL_INPUTXBARFLAGS_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_INPUTXBARFLAGS_CPUSEL_S     3U
#define SYSCTL_INPUTXBARFLAGS_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_INPUTXBARFLAGS_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                   // based on CPUx
#define SYSCTL_INPUTXBARFLAGS_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                   // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the OUTPUTXBARFLAGS register
//
//*************************************************************************************************
#define SYSCTL_OUTPUTXBARFLAGS_FRAMESEL_S   0U
#define SYSCTL_OUTPUTXBARFLAGS_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_OUTPUTXBARFLAGS_CPUSEL_S     3U
#define SYSCTL_OUTPUTXBARFLAGS_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_OUTPUTXBARFLAGS_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                    // based on CPUx
#define SYSCTL_OUTPUTXBARFLAGS_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                    // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the DLTFIFOREGS register
//
//*************************************************************************************************
#define SYSCTL_DLTFIFOREGS_FRAMESEL_S   0U
#define SYSCTL_DLTFIFOREGS_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_DLTFIFOREGS_CPUSEL_S     3U
#define SYSCTL_DLTFIFOREGS_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_DLTFIFOREGS_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                // based on CPUx
#define SYSCTL_DLTFIFOREGS_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ADC_GLOBAL_REGS register
//
//*************************************************************************************************
#define SYSCTL_ADC_GLOBAL_REGS_FRAMESEL_S   0U
#define SYSCTL_ADC_GLOBAL_REGS_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ADC_GLOBAL_REGS_CPUSEL_S     3U
#define SYSCTL_ADC_GLOBAL_REGS_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ADC_GLOBAL_REGS_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                    // based on CPUx
#define SYSCTL_ADC_GLOBAL_REGS_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                    // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ERROR_AGGREGATOR register
//
//*************************************************************************************************
#define SYSCTL_ERROR_AGGREGATOR_FRAMESEL_S   0U
#define SYSCTL_ERROR_AGGREGATOR_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ERROR_AGGREGATOR_CPUSEL_S     3U
#define SYSCTL_ERROR_AGGREGATOR_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ERROR_AGGREGATOR_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating
                                                     // based on CPUx
#define SYSCTL_ERROR_AGGREGATOR_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating
                                                     // based on CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the ESM register
//
//*************************************************************************************************
#define SYSCTL_ESM_FRAMESEL_S   0U
#define SYSCTL_ESM_FRAMESEL_M   0x7U    // FRAMESEL Selection for Peripheral Instance
#define SYSCTL_ESM_CPUSEL_S     3U
#define SYSCTL_ESM_CPUSEL_M     0x38U   // CPUSEL Selection for Peripheral Instance
#define SYSCTL_ESM_STANDBYEN    0x40U   // STANDBYEN to enable peripheral clock gating based on
                                        // CPUx
#define SYSCTL_ESM_DBGHALTEN    0x80U   // DBGHALTEN to enable peripheral clock gating based on
                                        // CPUx

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST register
//
//*************************************************************************************************
#define SYSCTL_PARITY_TEST_TESTEN_S   0U
#define SYSCTL_PARITY_TEST_TESTEN_M   0xFU   // Parity test enable configuration


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPUPERCFGLOCK1 register
//
//*************************************************************************************************
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR0    0x1U          // Lock bit for PCLKCR0 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR1    0x2U          // Lock bit for PCLKCR1 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR2    0x4U          // Lock bit for PCLKCR2 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR3    0x8U          // Lock bit for PCLKCR3 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR4    0x10U         // Lock bit for PCLKCR4 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR6    0x40U         // Lock bit for PCLKCR6 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR7    0x80U         // Lock bit for PCLKCR7 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR8    0x100U        // Lock bit for PCLKCR8 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR9    0x200U        // Lock bit for PCLKCR9 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR10   0x400U        // Lock bit for PCLKCR10 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR13   0x2000U       // Lock bit for PCLKCR13 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR14   0x4000U       // Lock bit for PCLKCR14 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR16   0x10000U      // Lock bit for PCLKCR16 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR17   0x20000U      // Lock bit for PCLKCR17 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR18   0x40000U      // Lock bit for PCLKCR18 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR19   0x80000U      // Lock bit for PCLKCR19 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR20   0x100000U     // Lock bit for PCLKCR20 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR21   0x200000U     // Lock bit for PCLKCR21 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR23   0x800000U     // Lock bit for PCLKCR23 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR25   0x2000000U    // Lock bit for PCLKCR25 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR27   0x8000000U    // Lock bit for PCLKCR27 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR28   0x10000000U   // Lock bit for PCLKCR28 Register
#define SYSCTL_CPUPERCFGLOCK1_PCLKCR30   0x40000000U   // Lock bit for PCLKCR30 Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPUPERCFGLOCK2 register
//
//*************************************************************************************************
#define SYSCTL_CPUPERCFGLOCK2_PCLKCR32   0x1U   // Lock bit for PCLKCR32 Register

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR0 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR0_RTDMA1       0x4U         // RTDMA1 Clock Enable Bit
#define SYSCTL_PCLKCR0_RTDMA2       0x8U         // RTDMA2 Clock Enable Bit
#define SYSCTL_PCLKCR0_CPUTIMER0    0x10U        // CPUTIMER0 Clock Enable Bit
#define SYSCTL_PCLKCR0_CPUTIMER1    0x20U        // CPUTIMER1 Clock Enable Bit
#define SYSCTL_PCLKCR0_CPUTIMER2    0x40U        // CPUTIMER2 Clock Enable Bit
#define SYSCTL_PCLKCR0_TBCLKSYNC    0x80000U     // TBCLKSYNC Clock Enable Bit
#define SYSCTL_PCLKCR0_GTBCLKSYNC   0x100000U    // GTBCLKSYNC Clock Enable Bit
#define SYSCTL_PCLKCR0_CPUX_ERAD    0x1000000U   // CPUx_ERAD Clock Enable Bit
#define SYSCTL_PCLKCR0_CPUX_DLT     0x2000000U   // CPUx_DLT Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR1 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR1_EMIF1   0x1U   // EMIF1 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR2 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR2_EPWM1    0x1U       // EPWM1 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM2    0x2U       // EPWM2 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM3    0x4U       // EPWM3 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM4    0x8U       // EPWM4 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM5    0x10U      // EPWM5 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM6    0x20U      // EPWM6 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM7    0x40U      // EPWM7 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM8    0x80U      // EPWM8 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM9    0x100U     // EPWM9 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM10   0x200U     // EPWM10 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM11   0x400U     // EPWM11 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM12   0x800U     // EPWM12 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM13   0x1000U    // EPWM13 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM14   0x2000U    // EPWM14 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM15   0x4000U    // EPWM15 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM16   0x8000U    // EPWM16 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM17   0x10000U   // EPWM17 Clock Enable bit
#define SYSCTL_PCLKCR2_EPWM18   0x20000U   // EPWM18 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR3 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR3_ECAP1   0x1U    // ECAP1 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP2   0x2U    // ECAP2 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP3   0x4U    // ECAP3 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP4   0x8U    // ECAP4 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP5   0x10U   // ECAP5 Clock Enable bit
#define SYSCTL_PCLKCR3_ECAP6   0x20U   // ECAP6 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR4 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR4_EQEP1   0x1U    // EQEP1 Clock Enable bit
#define SYSCTL_PCLKCR4_EQEP2   0x2U    // EQEP2 Clock Enable bit
#define SYSCTL_PCLKCR4_EQEP3   0x4U    // EQEP3 Clock Enable bit
#define SYSCTL_PCLKCR4_EQEP4   0x8U    // EQEP4 Clock Enable bit
#define SYSCTL_PCLKCR4_EQEP5   0x10U   // EQEP5 Clock Enable bit
#define SYSCTL_PCLKCR4_EQEP6   0x20U   // EQEP6 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR6 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR6_SD1   0x1U   // SD1 Clock Enable bit
#define SYSCTL_PCLKCR6_SD2   0x2U   // SD2 Clock Enable bit
#define SYSCTL_PCLKCR6_SD3   0x4U   // SD3 Clock Enable bit
#define SYSCTL_PCLKCR6_SD4   0x8U   // SD4 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR7 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR7_UART_A   0x10000U    // UART_A Clock Enable bit
#define SYSCTL_PCLKCR7_UART_B   0x20000U    // UART_B Clock Enable bit
#define SYSCTL_PCLKCR7_UART_C   0x40000U    // UART_C Clock Enable bit
#define SYSCTL_PCLKCR7_UART_D   0x80000U    // UART_D Clock Enable bit
#define SYSCTL_PCLKCR7_UART_E   0x100000U   // UART_E Clock Enable bit
#define SYSCTL_PCLKCR7_UART_F   0x200000U   // UART_F Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR8 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR8_SPI_A   0x1U    // SPI_A Clock Enable bit
#define SYSCTL_PCLKCR8_SPI_B   0x2U    // SPI_B Clock Enable bit
#define SYSCTL_PCLKCR8_SPI_C   0x4U    // SPI_C Clock Enable bit
#define SYSCTL_PCLKCR8_SPI_D   0x8U    // SPI_D Clock Enable bit
#define SYSCTL_PCLKCR8_SPI_E   0x10U   // SPI_E Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR9 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR9_I2C_A   0x1U   // I2C_A Clock Enable bit
#define SYSCTL_PCLKCR9_I2C_B   0x2U   // I2C_B Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR10 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR10_MCAN_A   0x10U    // MCAN_A Clock Enable bit
#define SYSCTL_PCLKCR10_MCAN_B   0x20U    // MCAN_B Clock Enable bit
#define SYSCTL_PCLKCR10_MCAN_C   0x40U    // MCAN_C Clock Enable bit
#define SYSCTL_PCLKCR10_MCAN_D   0x80U    // MCAN_D Clock Enable bit
#define SYSCTL_PCLKCR10_MCAN_E   0x100U   // MCAN_E Clock Enable bit
#define SYSCTL_PCLKCR10_MCAN_F   0x200U   // MCAN_F Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR13 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR13_ADC_A   0x1U    // ADC_A Clock Enable bit
#define SYSCTL_PCLKCR13_ADC_B   0x2U    // ADC_B Clock Enable bit
#define SYSCTL_PCLKCR13_ADC_C   0x4U    // ADC_C Clock Enable bit
#define SYSCTL_PCLKCR13_ADC_D   0x8U    // ADC_D Clock Enable bit
#define SYSCTL_PCLKCR13_ADC_E   0x10U   // ADC_E Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR14 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR14_CMPSS1    0x1U     // CMPSS1 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS2    0x2U     // CMPSS2 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS3    0x4U     // CMPSS3 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS4    0x8U     // CMPSS4 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS5    0x10U    // CMPSS5 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS6    0x20U    // CMPSS6 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS7    0x40U    // CMPSS7 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS8    0x80U    // CMPSS8 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS9    0x100U   // CMPSS9 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS10   0x200U   // CMPSS10 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS11   0x400U   // CMPSS11 Clock Enable bit
#define SYSCTL_PCLKCR14_CMPSS12   0x800U   // CMPSS12 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR16 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR16_DAC_A   0x10000U   // DAC_A Clock Enable bit
#define SYSCTL_PCLKCR16_DAC_B   0x20000U   // DAC_B Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR17 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR17_CLB1   0x1U    // CLB1 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB2   0x2U    // CLB2 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB3   0x4U    // CLB3 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB4   0x8U    // CLB4 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB5   0x10U   // CLB5 Clock Enable bit
#define SYSCTL_PCLKCR17_CLB6   0x20U   // CLB6 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR18 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR18_FSITX_A   0x1U       // FSITX_A Clock Enable bit
#define SYSCTL_PCLKCR18_FSITX_B   0x2U       // FSITX_B Clock Enable bit
#define SYSCTL_PCLKCR18_FSITX_C   0x4U       // FSITX_C Clock Enable bit
#define SYSCTL_PCLKCR18_FSITX_D   0x8U       // FSITX_D Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_A   0x10000U   // FSIRX_A Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_B   0x20000U   // FSIRX_B Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_C   0x40000U   // FSIRX_C Clock Enable bit
#define SYSCTL_PCLKCR18_FSIRX_D   0x80000U   // FSIRX_D Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR19 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR19_LIN_A   0x1U   // LIN_A Clock Enable bit
#define SYSCTL_PCLKCR19_LIN_B   0x2U   // LIN_B Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR20 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR20_PMBUS_A   0x1U   // PMBUS_A Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR21 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR21_DCC1   0x1U   // DCC1 Clock Enable Bit
#define SYSCTL_PCLKCR21_DCC2   0x2U   // DCC2 Clock Enable Bit
#define SYSCTL_PCLKCR21_DCC3   0x4U   // DCC3 Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR23 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR23_ETHERCAT   0x1U   // ETHERCAT Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR25 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR25_HRCAL0   0x1U   // HRCAL0 Clock Enable Bit
#define SYSCTL_PCLKCR25_HRCAL1   0x2U   // HRCAL1 Clock Enable Bit
#define SYSCTL_PCLKCR25_HRCAL2   0x4U   // HRCAL2 Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR27 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR27_EPG1   0x1U   // EPG1 Clock Enable Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR28 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR28_ADCCHECKER1     0x1U       // ADCCHECKER1 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER2     0x2U       // ADCCHECKER2 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER3     0x4U       // ADCCHECKER3 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER4     0x8U       // ADCCHECKER4 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER5     0x10U      // ADCCHECKER5 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER6     0x20U      // ADCCHECKER6 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER7     0x40U      // ADCCHECKER7 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER8     0x80U      // ADCCHECKER8 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER9     0x100U     // ADCCHECKER9 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCCHECKER10    0x200U     // ADCCHECKER10 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCSEAGGRCPU1   0x10000U   // ADCSEAGGRCPU1 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCSEAGGRCPU2   0x20000U   // ADCSEAGGRCPU2 Clock Enable bit
#define SYSCTL_PCLKCR28_ADCSEAGGRCPU3   0x40000U   // ADCSEAGGRCPU3 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR30 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR30_SENT1   0x1U    // SENT1 Clock Enable bit
#define SYSCTL_PCLKCR30_SENT2   0x2U    // SENT2 Clock Enable bit
#define SYSCTL_PCLKCR30_SENT3   0x4U    // SENT3 Clock Enable bit
#define SYSCTL_PCLKCR30_SENT4   0x8U    // SENT4 Clock Enable bit
#define SYSCTL_PCLKCR30_SENT5   0x10U   // SENT5 Clock Enable bit
#define SYSCTL_PCLKCR30_SENT6   0x20U   // SENT6 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PCLKCR32 register
//
//*************************************************************************************************
#define SYSCTL_PCLKCR32_WADI1   0x1U   // WADI1 Clock Enable bit
#define SYSCTL_PCLKCR32_WADI2   0x2U   // WADI2 Clock Enable bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES0 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES0_CPUTIMER    0x10U        // Reset bit for modules CPUTIMER0, COUTIMER1 and
                                                  // CPUTIMER2
#define SYSCTL_SOFTPRES0_CPUX_ERAD   0x1000000U   // CPUx_ERAD Module reset bit
#define SYSCTL_SOFTPRES0_CPUX_DLT    0x2000000U   // CPUx_DLT Module reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES1 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES1_EMIF1   0x1U   // EMIF1 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES2 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES2_EPWM1    0x1U       // EPWM1 software reset bit
#define SYSCTL_SOFTPRES2_EPWM2    0x2U       // EPWM2 software reset bit
#define SYSCTL_SOFTPRES2_EPWM3    0x4U       // EPWM3 software reset bit
#define SYSCTL_SOFTPRES2_EPWM4    0x8U       // EPWM4 software reset bit
#define SYSCTL_SOFTPRES2_EPWM5    0x10U      // EPWM5 software reset bit
#define SYSCTL_SOFTPRES2_EPWM6    0x20U      // EPWM6 software reset bit
#define SYSCTL_SOFTPRES2_EPWM7    0x40U      // EPWM7 software reset bit
#define SYSCTL_SOFTPRES2_EPWM8    0x80U      // EPWM8 software reset bit
#define SYSCTL_SOFTPRES2_EPWM9    0x100U     // EPWM9 software reset bit
#define SYSCTL_SOFTPRES2_EPWM10   0x200U     // EPWM10 software reset bit
#define SYSCTL_SOFTPRES2_EPWM11   0x400U     // EPWM11 software reset bit
#define SYSCTL_SOFTPRES2_EPWM12   0x800U     // EPWM12 software reset bit
#define SYSCTL_SOFTPRES2_EPWM13   0x1000U    // EPWM13 software reset bit
#define SYSCTL_SOFTPRES2_EPWM14   0x2000U    // EPWM14 software reset bit
#define SYSCTL_SOFTPRES2_EPWM15   0x4000U    // EPWM15 software reset bit
#define SYSCTL_SOFTPRES2_EPWM16   0x8000U    // EPWM16 software reset bit
#define SYSCTL_SOFTPRES2_EPWM17   0x10000U   // EPWM17 software reset bit
#define SYSCTL_SOFTPRES2_EPWM18   0x20000U   // EPWM18 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES3 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES3_ECAP1   0x1U    // ECAP1 software reset bit
#define SYSCTL_SOFTPRES3_ECAP2   0x2U    // ECAP2 software reset bit
#define SYSCTL_SOFTPRES3_ECAP3   0x4U    // ECAP3 software reset bit
#define SYSCTL_SOFTPRES3_ECAP4   0x8U    // ECAP4 software reset bit
#define SYSCTL_SOFTPRES3_ECAP5   0x10U   // ECAP5 software reset bit
#define SYSCTL_SOFTPRES3_ECAP6   0x20U   // ECAP6 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES4 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES4_EQEP1   0x1U    // EQEP1 software reset bit
#define SYSCTL_SOFTPRES4_EQEP2   0x2U    // EQEP2 software reset bit
#define SYSCTL_SOFTPRES4_EQEP3   0x4U    // EQEP3 software reset bit
#define SYSCTL_SOFTPRES4_EQEP4   0x8U    // EQEP4 software reset bit
#define SYSCTL_SOFTPRES4_EQEP5   0x10U   // EQEP5 software reset bit
#define SYSCTL_SOFTPRES4_EQEP6   0x20U   // EQEP6 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES6 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES6_SD1   0x1U   // SD1 software reset bit
#define SYSCTL_SOFTPRES6_SD2   0x2U   // SD2 software reset bit
#define SYSCTL_SOFTPRES6_SD3   0x4U   // SD3 software reset bit
#define SYSCTL_SOFTPRES6_SD4   0x8U   // SD4 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES7 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES7_UART_A   0x10000U    // UART_A software reset bit
#define SYSCTL_SOFTPRES7_UART_B   0x20000U    // UART_B software reset bit
#define SYSCTL_SOFTPRES7_UART_C   0x40000U    // UART_C software reset bit
#define SYSCTL_SOFTPRES7_UART_D   0x80000U    // UART_D software reset bit
#define SYSCTL_SOFTPRES7_UART_E   0x100000U   // UART_E software reset bit
#define SYSCTL_SOFTPRES7_UART_F   0x200000U   // UART_F software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES8 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES8_SPI_A   0x1U    // SPI_A software reset bit
#define SYSCTL_SOFTPRES8_SPI_B   0x2U    // SPI_B software reset bit
#define SYSCTL_SOFTPRES8_SPI_C   0x4U    // SPI_C software reset bit
#define SYSCTL_SOFTPRES8_SPI_D   0x8U    // SPI_D software reset bit
#define SYSCTL_SOFTPRES8_SPI_E   0x10U   // SPI_E software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES9 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES9_I2C_A   0x1U   // I2C_A software reset bit
#define SYSCTL_SOFTPRES9_I2C_B   0x2U   // I2C_B software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES10 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES10_MCAN_A   0x10U    // MCAN_A software reset bit
#define SYSCTL_SOFTPRES10_MCAN_B   0x20U    // MCAN_B software reset bit
#define SYSCTL_SOFTPRES10_MCAN_C   0x40U    // MCAN_C software reset bit
#define SYSCTL_SOFTPRES10_MCAN_D   0x80U    // MCAN_D software reset bit
#define SYSCTL_SOFTPRES10_MCAN_E   0x100U   // MCAN_E software reset bit
#define SYSCTL_SOFTPRES10_MCAN_F   0x200U   // MCAN_F software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES13 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES13_ADC_A   0x1U    // ADC_A software reset bit
#define SYSCTL_SOFTPRES13_ADC_B   0x2U    // ADC_B software reset bit
#define SYSCTL_SOFTPRES13_ADC_C   0x4U    // ADC_C software reset bit
#define SYSCTL_SOFTPRES13_ADC_D   0x8U    // ADC_D software reset bit
#define SYSCTL_SOFTPRES13_ADC_E   0x10U   // ADC_E software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES14 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES14_CMPSS1    0x1U     // CMPSS1 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS2    0x2U     // CMPSS2 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS3    0x4U     // CMPSS3 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS4    0x8U     // CMPSS4 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS5    0x10U    // CMPSS5 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS6    0x20U    // CMPSS6 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS7    0x40U    // CMPSS7 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS8    0x80U    // CMPSS8 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS9    0x100U   // CMPSS9 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS10   0x200U   // CMPSS10 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS11   0x400U   // CMPSS11 software reset bit
#define SYSCTL_SOFTPRES14_CMPSS12   0x800U   // CMPSS12 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES16 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES16_DAC_A   0x10000U   // DAC_A software reset bit
#define SYSCTL_SOFTPRES16_DAC_B   0x20000U   // DAC_B software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES17 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES17_CLB1   0x1U    // CLB1 software reset bit
#define SYSCTL_SOFTPRES17_CLB2   0x2U    // CLB2 software reset bit
#define SYSCTL_SOFTPRES17_CLB3   0x4U    // CLB3 software reset bit
#define SYSCTL_SOFTPRES17_CLB4   0x8U    // CLB4 software reset bit
#define SYSCTL_SOFTPRES17_CLB5   0x10U   // CLB5 software reset bit
#define SYSCTL_SOFTPRES17_CLB6   0x20U   // CLB6 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES18 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES18_FSITX_A   0x1U       // FSITX_A software reset bit
#define SYSCTL_SOFTPRES18_FSITX_B   0x2U       // FSITX_B software reset bit
#define SYSCTL_SOFTPRES18_FSITX_C   0x4U       // FSITX_C software reset bit
#define SYSCTL_SOFTPRES18_FSITX_D   0x8U       // FSITX_D software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_A   0x10000U   // FSIRX_A software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_B   0x20000U   // FSIRX_B software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_C   0x40000U   // FSIRX_C software reset bit
#define SYSCTL_SOFTPRES18_FSIRX_D   0x80000U   // FSIRX_D software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES19 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES19_LIN_A   0x1U   // LIN_A software reset bit
#define SYSCTL_SOFTPRES19_LIN_B   0x2U   // LIN_B software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES20 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES20_PMBUS_A   0x1U   // PMBUS_A software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES21 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES21_DCC1   0x1U   // DCC Module reset bit
#define SYSCTL_SOFTPRES21_DCC2   0x2U   // DCC Module reset bit
#define SYSCTL_SOFTPRES21_DCC3   0x4U   // DCC Module reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES23 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES23_ETHERCAT   0x1U   // ETHERCAT Module reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES25 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES25_HRCAL0   0x1U   // HRCAL0 Module reset bit
#define SYSCTL_SOFTPRES25_HRCAL1   0x2U   // HRCAL1 Module reset bit
#define SYSCTL_SOFTPRES25_HRCAL2   0x4U   // HRCAL2 Module reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES27 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES27_EPG1   0x1U   // EPG Module Reset Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES28 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES28_ADCCHECKER1     0x1U       // ADCCHECKER1 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER2     0x2U       // ADCCHECKER2 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER3     0x4U       // ADCCHECKER3 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER4     0x8U       // ADCCHECKER4 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER5     0x10U      // ADCCHECKER5 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER6     0x20U      // ADCCHECKER6 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER7     0x40U      // ADCCHECKER7 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER8     0x80U      // ADCCHECKER8 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER9     0x100U     // ADCCHECKER9 software reset bit
#define SYSCTL_SOFTPRES28_ADCCHECKER10    0x200U     // ADCCHECKER10 software reset bit
#define SYSCTL_SOFTPRES28_ADCSEAGGRCPU1   0x10000U   // ADCSEAGGRCPU1 software reset bit
#define SYSCTL_SOFTPRES28_ADCSEAGGRCPU2   0x20000U   // ADCSEAGGRCPU2 software reset bit
#define SYSCTL_SOFTPRES28_ADCSEAGGRCPU3   0x40000U   // ADCSEAGGRCPU3 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES30 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES30_SENT1   0x1U    // SENT1 software reset bit
#define SYSCTL_SOFTPRES30_SENT2   0x2U    // SENT2 software reset bit
#define SYSCTL_SOFTPRES30_SENT3   0x4U    // SENT3 software reset bit
#define SYSCTL_SOFTPRES30_SENT4   0x8U    // SENT4 software reset bit
#define SYSCTL_SOFTPRES30_SENT5   0x10U   // SENT5 software reset bit
#define SYSCTL_SOFTPRES30_SENT6   0x20U   // SENT6 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SOFTPRES32 register
//
//*************************************************************************************************
#define SYSCTL_SOFTPRES32_WADI1   0x1U   // WADI1 software reset bit
#define SYSCTL_SOFTPRES32_WADI2   0x2U   // WADI2 software reset bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST_ALT1 register
//
//*************************************************************************************************
#define SYSCTL_PARITY_TEST_ALT1_TESTEN_S   0U
#define SYSCTL_PARITY_TEST_ALT1_TESTEN_M   0xFU   // Parity test enable configuration


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPUSYSLOCK1 register
//
//*************************************************************************************************
#define SYSCTL_CPUSYSLOCK1_LPMCR                0x2U          // Lock bit for LPMCR Register
#define SYSCTL_CPUSYSLOCK1_GPIOLPMSEL0          0x4U          // Lock bit for GPIOLPMSEL0 Register
#define SYSCTL_CPUSYSLOCK1_GPIOLPMSEL1          0x8U          // Lock bit for GPIOLPMSEL1 Register
#define SYSCTL_CPUSYSLOCK1_CMPSSLPMSEL          0x20U         // Lock bit for CMPSSLPMSEL register
#define SYSCTL_CPUSYSLOCK1_USER_REG1_SYSRSN     0x1000000U    // Lock bit for USER_REG1_SYSRSn
#define SYSCTL_CPUSYSLOCK1_USER_REG2_SYSRSN     0x2000000U    // Lock bit for USER_REG2_SYSRSn
#define SYSCTL_CPUSYSLOCK1_USER_REG1_XRSN       0x4000000U    // Lock bit for USER_REG1_XRSn
#define SYSCTL_CPUSYSLOCK1_USER_REG2_XRSN       0x8000000U    // Lock bit for USER_REG2_XRSn
#define SYSCTL_CPUSYSLOCK1_USER_REG1_PORESETN   0x10000000U   // Lock bit for USER_REG1_PORESETn
#define SYSCTL_CPUSYSLOCK1_USER_REG2_PORESETN   0x20000000U   // Lock bit for USER_REG2_PORESETn
#define SYSCTL_CPUSYSLOCK1_USER_REG3_PORESETN   0x40000000U   // Lock bit for USER_REG3_PORESETn
#define SYSCTL_CPUSYSLOCK1_USER_REG4_PORESETN   0x80000000U   // Lock bit for USER_REG4_PORESETn

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPUID register
//
//*************************************************************************************************
#define SYSCTL_CPUID_CPUID_S   0U
#define SYSCTL_CPUID_CPUID_M   0x3U   // Indicates CPU1, CPU2, CPU3, CPU4, CPU5 or CPU6

//*************************************************************************************************
//
// The following are defines for the bit fields in the LPMCR register
//
//*************************************************************************************************
#define SYSCTL_LPMCR_LPM_S         0U
#define SYSCTL_LPMCR_LPM_M         0x3U      // Low Power Mode setting
#define SYSCTL_LPMCR_QUALSTDBY_S   2U
#define SYSCTL_LPMCR_QUALSTDBY_M   0xFCU     // STANDBY Wakeup Pin Qualification Setting
#define SYSCTL_LPMCR_WDINTE        0x8000U   // Enable for WDINT wakeup from STANDBY

//*************************************************************************************************
//
// The following are defines for the bit fields in the CMPSSLPMSEL register
//
//*************************************************************************************************
#define SYSCTL_CMPSSLPMSEL_CMPSS1H    0x1U        // CMPSS1H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS1L    0x2U        // CMPSS1L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS2H    0x4U        // CMPSS2H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS2L    0x8U        // CMPSS2L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS3H    0x10U       // CMPSS3H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS3L    0x20U       // CMPSS3L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS4H    0x40U       // CMPSS4H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS4L    0x80U       // CMPSS4L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS5H    0x100U      // CMPSS5H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS5L    0x200U      // CMPSS5L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS6H    0x400U      // CMPSS6H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS6L    0x800U      // CMPSS6L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS7H    0x1000U     // CMPSS7H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS7L    0x2000U     // CMPSS7L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS8H    0x4000U     // CMPSS8H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS8L    0x8000U     // CMPSS8L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS9H    0x10000U    // CMPSS9H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS9L    0x20000U    // CMPSS9L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS10H   0x40000U    // CMPSS10H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS10L   0x80000U    // CMPSS10L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS11H   0x100000U   // CMPSS11H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS11L   0x200000U   // CMPSS11L Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS12H   0x400000U   // CMPSS12H Enable for LPM Wakeup
#define SYSCTL_CMPSSLPMSEL_CMPSS12L   0x800000U   // CMPSS12L Enable for LPM Wakeup

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOLPMSEL0 register
//
//*************************************************************************************************
#define SYSCTL_GPIOLPMSEL0_GPIO0    0x1U          // GPIO0 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO1    0x2U          // GPIO1 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO2    0x4U          // GPIO2 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO3    0x8U          // GPIO3 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO4    0x10U         // GPIO4 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO5    0x20U         // GPIO5 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO6    0x40U         // GPIO6 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO7    0x80U         // GPIO7 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO8    0x100U        // GPIO8 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO9    0x200U        // GPIO9 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO10   0x400U        // GPIO10 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO11   0x800U        // GPIO11 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO12   0x1000U       // GPIO12 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO13   0x2000U       // GPIO13 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO14   0x4000U       // GPIO14 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO15   0x8000U       // GPIO15 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO16   0x10000U      // GPIO16 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO17   0x20000U      // GPIO17 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO18   0x40000U      // GPIO18 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO19   0x80000U      // GPIO19 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO20   0x100000U     // GPIO20 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO21   0x200000U     // GPIO21 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO22   0x400000U     // GPIO22 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO23   0x800000U     // GPIO23 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO24   0x1000000U    // GPIO24 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO25   0x2000000U    // GPIO25 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO26   0x4000000U    // GPIO26 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO27   0x8000000U    // GPIO27 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO28   0x10000000U   // GPIO28 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO29   0x20000000U   // GPIO29 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO30   0x40000000U   // GPIO30 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL0_GPIO31   0x80000000U   // GPIO31 Enable for LPM Wakeup

//*************************************************************************************************
//
// The following are defines for the bit fields in the GPIOLPMSEL1 register
//
//*************************************************************************************************
#define SYSCTL_GPIOLPMSEL1_GPIO32   0x1U          // GPIO32 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO33   0x2U          // GPIO33 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO34   0x4U          // GPIO34 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO35   0x8U          // GPIO35 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO36   0x10U         // GPIO36 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO37   0x20U         // GPIO37 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO38   0x40U         // GPIO38 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO39   0x80U         // GPIO39 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO40   0x100U        // GPIO40 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO41   0x200U        // GPIO41 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO42   0x400U        // GPIO42 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO43   0x800U        // GPIO43 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO44   0x1000U       // GPIO44 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO45   0x2000U       // GPIO45 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO46   0x4000U       // GPIO46 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO47   0x8000U       // GPIO47 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO48   0x10000U      // GPIO48 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO49   0x20000U      // GPIO49 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO50   0x40000U      // GPIO50 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO51   0x80000U      // GPIO51 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO52   0x100000U     // GPIO52 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO53   0x200000U     // GPIO53 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO54   0x400000U     // GPIO54 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO55   0x800000U     // GPIO55 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO56   0x1000000U    // GPIO56 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO57   0x2000000U    // GPIO57 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO58   0x4000000U    // GPIO58 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO59   0x8000000U    // GPIO59 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO60   0x10000000U   // GPIO60 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO61   0x20000000U   // GPIO61 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO62   0x40000000U   // GPIO62 Enable for LPM Wakeup
#define SYSCTL_GPIOLPMSEL1_GPIO63   0x80000000U   // GPIO63 Enable for LPM Wakeup

//*************************************************************************************************
//
// The following are defines for the bit fields in the TMR2CLKCTL register
//
//*************************************************************************************************
#define SYSCTL_TMR2CLKCTL_TMR2CLKSRCSEL_S     0U
#define SYSCTL_TMR2CLKCTL_TMR2CLKSRCSEL_M     0x7U    // CPU Timer 2 Clock Source Select Bit
#define SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_S   3U
#define SYSCTL_TMR2CLKCTL_TMR2CLKPRESCALE_M   0x38U   // CPU Timer 2 Clock Pre-Scale Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the RESCCLR register
//
//*************************************************************************************************
#define SYSCTL_RESCCLR_POR              0x1U      // POR POR Reset Cause Clear Bit
#define SYSCTL_RESCCLR_XRSN             0x2U      // XRSn POR Reset Cause Clear Bit
#define SYSCTL_RESCCLR_WDRSN            0x4U      // WDRSn POR Reset Cause Clear Bit
#define SYSCTL_RESCCLR_NMIWDRSN         0x8U      // NMIWDRSn POR Reset Cause Clear Bit
#define SYSCTL_RESCCLR_ECAT_RESET_OUT   0x200U    // ECAT_RESET_OUT POR Reset Cause Clear Bit
#define SYSCTL_RESCCLR_SIMRESET_XRSN    0x800U    // SIMRESET_XRSn POR Reset Cause Clear Bit
#define SYSCTL_RESCCLR_ESMXRSN          0x1000U   // ESMXRSn Reset Cause Clear Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the RESC register
//
//*************************************************************************************************
#define SYSCTL_RESC_POR               0x1U          // POR Reset Cause Indication Bit
#define SYSCTL_RESC_XRSN              0x2U          // XRSn Reset Cause Indication Bit
#define SYSCTL_RESC_WDRSN             0x4U          // WDRSn Reset Cause Indication Bit
#define SYSCTL_RESC_NMIWDRSN          0x8U          // NMIWDRSn Reset Cause Indication Bit
#define SYSCTL_RESC_ECAT_RESET_OUT    0x200U        // ECAT_RESET_OUT Reset Cause Indication Bit
#define SYSCTL_RESC_SIMRESET_XRSN     0x800U        // SIMRESET_XRSn Reset Cause Indication Bit
#define SYSCTL_RESC_ESMRESET          0x1000U       // ESMRESET Reset Cause Indication Bit
#define SYSCTL_RESC_XRSN_PIN_STATUS   0x40000000U   // XRSN Pin Status
#define SYSCTL_RESC_DCON              0x80000000U   // Debugger connection status to C29x CPU

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCANWAKESTATUS register
//
//*************************************************************************************************
#define SYSCTL_MCANWAKESTATUS_WAKE_MCANA   0x1U    // WAKE_MCANA Wake Status
#define SYSCTL_MCANWAKESTATUS_WAKE_MCANB   0x2U    // WAKE_MCANB Wake Status
#define SYSCTL_MCANWAKESTATUS_WAKE_MCANC   0x4U    // WAKE_MCANC Wake Status
#define SYSCTL_MCANWAKESTATUS_WAKE_MCAND   0x8U    // WAKE_MCAND Wake Status
#define SYSCTL_MCANWAKESTATUS_WAKE_MCANE   0x10U   // WAKE_MCANE Wake Status
#define SYSCTL_MCANWAKESTATUS_WAKE_MCANF   0x20U   // WAKE_MCANF Wake Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the MCANWAKESTATUSCLR register
//
//*************************************************************************************************
#define SYSCTL_MCANWAKESTATUSCLR_WAKE_MCANA   0x1U    // Cear bit for MCANWAKESTATUS.WAKE_MCANA bit
#define SYSCTL_MCANWAKESTATUSCLR_WAKE_MCANB   0x2U    // Cear bit for MCANWAKESTATUS.WAKE_MCANB bit
#define SYSCTL_MCANWAKESTATUSCLR_WAKE_MCANC   0x4U    // Cear bit for MCANWAKESTATUS.WAKE_MCANC bit
#define SYSCTL_MCANWAKESTATUSCLR_WAKE_MCAND   0x8U    // Cear bit for MCANWAKESTATUS.WAKE_MCAND bit
#define SYSCTL_MCANWAKESTATUSCLR_WAKE_MCANE   0x10U   // Cear bit for MCANWAKESTATUS.WAKE_MCANE bit
#define SYSCTL_MCANWAKESTATUSCLR_WAKE_MCANF   0x20U   // Cear bit for MCANWAKESTATUS.WAKE_MCANF bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSTOPREQ register
//
//*************************************************************************************************
#define SYSCTL_CLKSTOPREQ_MCAN_A   0x100U        // MCAN_A Clock Stop Request Bit
#define SYSCTL_CLKSTOPREQ_MCAN_B   0x200U        // MCAN_B Clock Stop Request Bit
#define SYSCTL_CLKSTOPREQ_MCAN_C   0x400U        // MCAN_C Clock Stop Request Bit
#define SYSCTL_CLKSTOPREQ_MCAN_D   0x800U        // MCAN_D Clock Stop Request Bit
#define SYSCTL_CLKSTOPREQ_MCAN_E   0x1000U       // MCAN_E Clock Stop Request Bit
#define SYSCTL_CLKSTOPREQ_MCAN_F   0x2000U       // MCAN_F Clock Stop Request Bit
#define SYSCTL_CLKSTOPREQ_KEY_S    16U
#define SYSCTL_CLKSTOPREQ_KEY_M    0xFFFF0000U   // Key for register write

//*************************************************************************************************
//
// The following are defines for the bit fields in the CLKSTOPACK register
//
//*************************************************************************************************
#define SYSCTL_CLKSTOPACK_MCAN_A   0x100U    // MCAN_A Clock Stop Ack Bit
#define SYSCTL_CLKSTOPACK_MCAN_B   0x200U    // MCAN_B Clock Stop Ack Bit
#define SYSCTL_CLKSTOPACK_MCAN_C   0x400U    // MCAN_C Clock Stop Ack Bit
#define SYSCTL_CLKSTOPACK_MCAN_D   0x800U    // MCAN_D Clock Stop Ack Bit
#define SYSCTL_CLKSTOPACK_MCAN_E   0x1000U   // MCAN_E Clock Stop Ack Bit
#define SYSCTL_CLKSTOPACK_MCAN_F   0x2000U   // MCAN_F Clock Stop Ack Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SIMRESET register
//
//*************************************************************************************************
#define SYSCTL_SIMRESET_XRSN    0x2U          // Generates a simulated XRSn
#define SYSCTL_SIMRESET_KEY_S   16U
#define SYSCTL_SIMRESET_KEY_M   0xFFFF0000U   // Key value to enable write

//*************************************************************************************************
//
// The following are defines for the bit fields in the PARITY_TEST_ALT2 register
//
//*************************************************************************************************
#define SYSCTL_PARITY_TEST_ALT2_TESTEN_S   0U
#define SYSCTL_PARITY_TEST_ALT2_TESTEN_M   0xFU   // Parity test enable configuration


//*************************************************************************************************
//
// The following are defines for the bit fields in the SCSR register
//
//*************************************************************************************************
#define SYSCTL_SCSR_WDOVERRIDE   0x1U   // WD Override for WDDIS bit
#define SYSCTL_SCSR_WDENINT      0x2U   // WD Interrupt Enable
#define SYSCTL_SCSR_WDINTS       0x4U   // WD Interrupt Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDCNTR register
//
//*************************************************************************************************
#define SYSCTL_WDCNTR_WDCNTR_S   0U
#define SYSCTL_WDCNTR_WDCNTR_M   0xFFU   // WD Counter

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDKEY register
//
//*************************************************************************************************
#define SYSCTL_WDKEY_WDKEY_S   0U
#define SYSCTL_WDKEY_WDKEY_M   0xFFU   // Key to pet the watchdog timer.

//*************************************************************************************************
//
// The following are defines for the bit fields in the SYNCBUSYWD register
//
//*************************************************************************************************
#define SYSCTL_SYNCBUSYWD_BUSY   0x1U   // Status bit indicating synchronization in progress
#define SYSCTL_SYNCBUSYWD_WDCR   0x2U   // BUSY status bit for WDCR

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDCR register
//
//*************************************************************************************************
#define SYSCTL_WDCR_WDPS_S          0U
#define SYSCTL_WDCR_WDPS_M          0x7U     // WD Clock Prescalar
#define SYSCTL_WDCR_WDCHK_S         3U
#define SYSCTL_WDCR_WDCHK_M         0x38U    // WD Check Bits
#define SYSCTL_WDCR_WDDIS           0x40U    // WD Disable
#define SYSCTL_WDCR_WDPRECLKDIV_S   8U
#define SYSCTL_WDCR_WDPRECLKDIV_M   0xF00U   // WD Pre Clock Divider

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDWCR register
//
//*************************************************************************************************
#define SYSCTL_WDWCR_MIN_S   0U
#define SYSCTL_WDWCR_MIN_M   0xFFU   // WD Min Threshold setting for Windowed Watchdog
                                     // functionality



#endif
