//###########################################################################
//
// FILE:    hw_ssu.h
//
// TITLE:   Definitions for the SSU registers.
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

#ifndef HW_SSU_H
#define HW_SSU_H

//*************************************************************************************************
//
// The following are defines for the SSU register offsets
//
//*************************************************************************************************
#define SSU_O_REVISION                   0x0U     // Module Revision Register
#define SSU_O_UPP_REVISION               0x4U     // User Protection Policy Revision
#define SSU_O_MODE                       0x8U     // Safety and Security Operational Mode
#define SSU_O_LINK2_AP_OVERRIDE          0xCU     // LINK2 Access Protection Override Register
#define SSU_O_BOOTMODE_STAT              0x2CU    // User Boot Mode Status Register
#define SSU_O_EMU_BOOTPIN_CONFIG         0x30U    // User Emulation Boot Pin Configuration
#define SSU_O_EMU_BOOT_DIAG              0x34U    // User Emulation Boot Options
#define SSU_O_EMU_BOOT_CLKCFG            0x38U    // User Emulation Boot Clock Configuration
                                                  // Register
#define SSU_O_EMU_BOOTEN                 0x3CU    // User Emulation Boot Enable
#define SSU_O_RAMOPEN_LOCK               0x40U    // RAMOPEN Feature Lock Register
#define SSU_O_RAMOPEN_COMMIT             0x44U    // RAMOPEN Feature Commit Register
#define SSU_O_CPUID                      0x4CU    // CPUID Register
#define SSU_O_BANKMAP                    0x50U    // Valid Banks
#define SSU_O_BANKMAP_LOCK               0x54U    // Bank Map Lock Register
#define SSU_O_BANKMAP_COMMIT             0x58U    // Bank Map Commit Register
#define SSU_O_BANKMODE                   0x5CU    // Bank Mode Configuration Register
#define SSU_O_BANKMODE_LOCK              0x60U    // Bank Mode Lock Register
#define SSU_O_BANKMODE_COMMIT            0x64U    // Bank Mode Commit Register
#define SSU_O_SECCFG_UPDATE_CFG          0x68U    // SECCFG Flash Update Configuration Register
#define SSU_O_PROG_BANKMODE              0x70U    // Programming BANKMODE Register
#define SSU_O_SECVALID                   0x74U    // Valid SECCFG Sector
#define SSU_O_SECVALID_LOCK              0x78U    // Valid SECCFG Sector Lock Register
#define SSU_O_SECVALID_COMMIT            0x7CU    // Valid SECCFG Sector Commit Register
#define SSU_O_ZONE1_CFG                  0x80U    // ZONE1 Configuration
#define SSU_O_ZONE2_CFG                  0x84U    // ZONE2 Configuration
#define SSU_O_ZONE3_CFG                  0x88U    // ZONE3 Configuration
#define SSU_O_DEBUG_CFG                  0x90U    // Debug Configuration
#define SSU_O_DEBUG_CFG_LOCK             0x94U    // Debug Configuration Lock Register
#define SSU_O_DEBUG_CFG_COMMIT           0x98U    // Debug Configuration Commit Register
#define SSU_O_DEBUG_STAT                 0xA0U    // Debug Status Register
#define SSU_O_C29DBGEN                   0xA4U    // C29 Debug Enable Register
#define SSU_O_ZONE_DBGEN                 0xA8U    // ZONE Debug Enable Register
#define SSU_O_BEPROT_BANK                0x200U   // Bank Erase Protection Bank Register
#define SSU_O_BEPROT_STAT                0x204U   // Bank Erase Status Register
#define SSU_O_BEPROTA                    0x208U   // Bank Erase Protection Register A
#define SSU_O_BEPROTB                    0x20CU   // Bank Erase Protection Register B
#define SSU_O_FLSEMSTAT                  0x220U   // Flash Controller Semaphore Status Register
#define SSU_O_FLSEMREQ                   0x224U   // Flash Controller Semaphore Request Register
#define SSU_O_FLSEMCLR                   0x228U   // Flash Controller Semaphore Clear Register
#define SSU_O_WEPROT_CODE_BANKS          0x230U   // Global Code Banks Write Erase
#define SSU_O_WEPROT_CODE_BANKS_LOCK     0x234U   // Global Code Banks Write Erase Lock
#define SSU_O_WEPROT_CODE_BANKS_COMMIT   0x238U   // Global Code Banks Write Erase Commit
#define SSU_O_WEPROT_DATA_BANKS          0x240U   // Global Data Banks Write Erase
#define SSU_O_WEPROT_DATA_BANKS_LOCK     0x244U   // Global Data Banks Write Erase Lock
#define SSU_O_WEPROT_DATA_BANKS_COMMIT   0x248U   // Global Data Banks Write Erase Commit
#define SSU_O_WEPROT_FLC1_B0_A           0x300U   // Flash Controller 1 B0 Write Erase Protection A
#define SSU_O_WEPROT_FLC1_B0_B           0x304U   // Flash Controller 1 B0 Write Erase Protection B
#define SSU_O_WEPROT_FLC1_B0_LOCK        0x310U   // Flash Controller 1 B0 WEPROTA Lock
#define SSU_O_WEPROT_FLC1_B0_COMMIT      0x314U   // Flash Controller 1 B0 WEPROTA Commit
#define SSU_O_WEPROT_FLC1_B2_A           0x340U   // Flash Controller 1 B2 Write Erase Protection A
#define SSU_O_WEPROT_FLC1_B2_B           0x344U   // Flash Controller 1 B2 Write Erase Protection B
#define SSU_O_WEPROT_FLC1_B2_LOCK        0x350U   // Flash Controller 1 B2 WEPROTA Lock
#define SSU_O_WEPROT_FLC1_B2_COMMIT      0x354U   // Flash Controller 1 B2 WEPROTA Commit
#define SSU_O_WEPROT_FLC2_B0_A           0x3A0U   // Flash Controller 2 B0 Write Erase Protection A
#define SSU_O_WEPROT_FLC2_B0_B           0x3A4U   // Flash Controller 2 B0 Write Erase Protection B
#define SSU_O_WEPROT_FLC2_B0_LOCK        0x3B0U   // Flash Controller 2 B0 WEPROTA Lock
#define SSU_O_WEPROT_FLC2_B0_COMMIT      0x3B4U   // Flash Controller 2 B0 WEPROTA Commit
#define SSU_O_WEPROT_FLC2_B2_A           0x3E0U   // Flash Controller 2 B2 Write Erase Protection A
#define SSU_O_WEPROT_FLC2_B2_B           0x3E4U   // Flash Controller 2 B2 Write Erase Protection B
#define SSU_O_WEPROT_FLC2_B2_LOCK        0x3F0U   // Flash Controller 2 B2 WEPROTA Lock
#define SSU_O_WEPROT_FLC2_B2_COMMIT      0x3F4U   // Flash Controller 2 B2 WEPROTA Commit

#define SSU_O_RST_VECT              0x0U    // CPU Reset Vector
#define SSU_O_RST_LINK              0x4U    // CPU Reset LINK
#define SSU_O_CPU_RST_CTRL          0x8U    // CPU Reset Control
#define SSU_O_DEF_NMI_VECT          0x10U   // Default CPU NMI Vector
#define SSU_O_DEF_NMI_LINK          0x14U   // Default CPU NMI LINK
#define SSU_O_EMU_BOOTDEF_LOW       0x28U   // User Emulation Boot Definition Low Register
#define SSU_O_EMU_BOOTDEF_HIGH      0x2CU   // User Emulation Boot Definition High Register
#define SSU_O_LINK3_CFG             0x3CU   // LINK3 Configuration
#define SSU_O_LINK4_CFG             0x40U   // LINK4 Configuration
#define SSU_O_LINK5_CFG             0x44U   // LINK5 Configuration
#define SSU_O_LINK6_CFG             0x48U   // LINK6 Configuration
#define SSU_O_LINK7_CFG             0x4CU   // LINK7 Configuration
#define SSU_O_LINK8_CFG             0x50U   // LINK8 Configuration
#define SSU_O_LINK9_CFG             0x54U   // LINK9 Configuration
#define SSU_O_LINK10_CFG            0x58U   // LINK10 Configuration
#define SSU_O_LINK11_CFG            0x5CU   // LINK11 Configuration
#define SSU_O_LINK12_CFG            0x60U   // LINK12 Configuration
#define SSU_O_LINK13_CFG            0x64U   // LINK13 Configuration
#define SSU_O_LINK14_CFG            0x68U   // LINK14 Configuration
#define SSU_O_LINK15_CFG            0x6CU   // LINK15 Configuration
#define SSU_O_STACK3_CFG            0x7CU   // STACK3 Configuration
#define SSU_O_STACK4_CFG            0x80U   // STACK4 Configuration
#define SSU_O_STACK5_CFG            0x84U   // STACK5 Configuration
#define SSU_O_STACK6_CFG            0x88U   // STACK6 Configuration
#define SSU_O_STACK7_CFG            0x8CU   // STACK7 Configuration
#define SSU_O_RAMOPENSTAT           0x90U   // RAMOPEN Feature Status Register
#define SSU_O_RAMOPENFRC            0x94U   // RAMOPEN Feature Force Register
#define SSU_O_RAMOPENCLR            0x98U   // RAMOPEN Feature Clear Register
#define SSU_O_DECODER_ADDR_IN       0xA0U   // SW ZONE Decoder Address Input
#define SSU_O_DECODER_OUT           0xA4U   // SW ZONE Decoder Output
#define SSU_O_EMU_DECODER_ADDR_IN   0xA8U   // SW ZONE Decoder Address Input
#define SSU_O_EMU_DECODER_OUT       0xACU   // SW ZONE Decoder Output

#define SSU_O_AP_CFG(i)      (0x0U + ((i) * 32U))    // (0 <= i < 64) Access Protection 
                                                        // Configuration
#define SSU_O_AP_START(i)    (0x4U + ((i) * 32U))    // (0 <= i < 64) Access Protection  Start
                                                        // Address
#define SSU_O_AP_END(i)      (0x8U + ((i) * 32U))    // (0 <= i < 64) Access Protection  End
                                                        // Address
#define SSU_O_AP_LOCK(i)     (0xCU + ((i) * 32U))    // (0 <= i < 64) Access Protection 
                                                        // Temporary Lock
#define SSU_O_AP_COMMIT(i)   (0x10U + ((i) * 32U))   // (0 <= i < 64) Access Protection 
                                                        // Permanent Commit
#define SSU_O_AP_ACCESS(i)   (0x14U + ((i) * 32U))   // (0 <= i < 64) Access Protection  R/W
                                                        // Access Permissions


//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define SSU_REVISION_MINREV_S   0U
#define SSU_REVISION_MINREV_M   0xFFU     // Minor Revision Number
#define SSU_REVISION_MAJREV_S   8U
#define SSU_REVISION_MAJREV_M   0xFF00U   // Major Revision Number

//*************************************************************************************************
//
// The following are defines for the bit fields in the UPP_REVISION register
//
//*************************************************************************************************
#define SSU_UPP_REVISION_REV_S   0U
#define SSU_UPP_REVISION_REV_M   0xFFFFU   // User Protection Policy Revision

//*************************************************************************************************
//
// The following are defines for the bit fields in the SSUMODE register
//
//*************************************************************************************************
#define SSU_MODE_OPMODE_S   0U
#define SSU_MODE_OPMODE_M   0x3FU   // SSU Operational Mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK2_AP_OVERRIDE register
//
//*************************************************************************************************
#define SSU_LINK2_AP_OVERRIDE_CPU1   0x1U   // CPU1 LINK2 Access Protection Override Bit
#define SSU_LINK2_AP_OVERRIDE_CPU2   0x2U   // CPU2 LINK2 Access Protection Override Bit
#define SSU_LINK2_AP_OVERRIDE_CPU3   0x4U   // CPU3 LINK2 Access Protection Override Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the BOOTMODE_STAT register
//
//*************************************************************************************************
#define SSU_BOOTMODE_STAT_PIN_STAT_S   0U
#define SSU_BOOTMODE_STAT_PIN_STAT_M   0x7U   // Boot Mode Pin Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the EMU_BOOTPIN_CONFIG register
//
//*************************************************************************************************
#define SSU_EMU_BOOTPIN_CONFIG_BMSP0_S   0U
#define SSU_EMU_BOOTPIN_CONFIG_BMSP0_M   0xFFU         // Boot Mode Select Pin 0
#define SSU_EMU_BOOTPIN_CONFIG_BMSP1_S   8U
#define SSU_EMU_BOOTPIN_CONFIG_BMSP1_M   0xFF00U       // Boot Mode Select Pin 1
#define SSU_EMU_BOOTPIN_CONFIG_BMSP2_S   16U
#define SSU_EMU_BOOTPIN_CONFIG_BMSP2_M   0xFF0000U     // Boot Mode Select Pin 2
#define SSU_EMU_BOOTPIN_CONFIG_KEY_S     24U
#define SSU_EMU_BOOTPIN_CONFIG_KEY_M     0xFF000000U   // Register Valid Key

//*************************************************************************************************
//
// The following are defines for the bit fields in the EMU_BOOT_DIAG register
//
//*************************************************************************************************
#define SSU_EMU_BOOT_DIAG_LPOST_EN_S      0U
#define SSU_EMU_BOOT_DIAG_LPOST_EN_M      0x3U    // LPOST Enable
#define SSU_EMU_BOOT_DIAG_LPOST_COVER_S   2U
#define SSU_EMU_BOOT_DIAG_LPOST_COVER_M   0xCU    // LPOST Coverage
#define SSU_EMU_BOOT_DIAG_MPOST_EN_S      4U
#define SSU_EMU_BOOT_DIAG_MPOST_EN_M      0x30U   // MPOST Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the EMU_BOOT_CLKCFG register
//
//*************************************************************************************************
#define SSU_EMU_BOOT_CLKCFG_IMULT_S    0U
#define SSU_EMU_BOOT_CLKCFG_IMULT_M    0xFFU         // Secure Boot PLL IMULT
#define SSU_EMU_BOOT_CLKCFG_ODIV_S     8U
#define SSU_EMU_BOOT_CLKCFG_ODIV_M     0x1F00U       // Secure Boot PLL ODIV
#define SSU_EMU_BOOT_CLKCFG_REFDIV_S   16U
#define SSU_EMU_BOOT_CLKCFG_REFDIV_M   0x1F0000U     // Secure Boot PLL REFDIV
#define SSU_EMU_BOOT_CLKCFG_PLLEN_S    28U
#define SSU_EMU_BOOT_CLKCFG_PLLEN_M    0xF0000000U   // Secure Boot PLL Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the EMU_BOOTEN register
//
//*************************************************************************************************
#define SSU_EMU_BOOTEN_ENABLE   0x1U   // Emulation Boot Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMOPEN_LOCK register
//
//*************************************************************************************************
#define SSU_RAMOPEN_LOCK_LOCK_S   0U
#define SSU_RAMOPEN_LOCK_LOCK_M   0xFFU   // RAMOPEN Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMOPEN_COMMIT register
//
//*************************************************************************************************
#define SSU_RAMOPEN_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPUID register
//
//*************************************************************************************************
#define SSU_CPUID_CPUID_S   0U
#define SSU_CPUID_CPUID_M   0x7U    // CPUID Value
#define SSU_CPUID_DBGREAD   0x10U   // Debug Read Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the BANKMAP register
//
//*************************************************************************************************
#define SSU_BANKMAP_CPU1SWAP_S   0U
#define SSU_BANKMAP_CPU1SWAP_M   0xFFU     // CPU1 Bank Swap
#define SSU_BANKMAP_CPU3SWAP_S   8U
#define SSU_BANKMAP_CPU3SWAP_M   0xFF00U   // CPU3 Bank Swap

//*************************************************************************************************
//
// The following are defines for the bit fields in the BANKMAP_LOCK register
//
//*************************************************************************************************
#define SSU_BANKMAP_LOCK_LOCK1   0x1U   // CPU1 Bank Swap Lock
#define SSU_BANKMAP_LOCK_LOCK2   0x2U   // CPU3 Bank Swap Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the BANKMAP_COMMIT register
//
//*************************************************************************************************
#define SSU_BANKMAP_COMMIT_COMMIT1   0x1U   // CPU1 Bank Swap Commit
#define SSU_BANKMAP_COMMIT_COMMIT2   0x2U   // CPU3 Bank Swap Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the BANKMODE register
//
//*************************************************************************************************
#define SSU_BANKMODE_MODE_S   0U
#define SSU_BANKMODE_MODE_M   0xFU   // Device Flash Configuration Mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the BANKMODE_LOCK register
//
//*************************************************************************************************
#define SSU_BANKMODE_LOCK_LOCK   0x1U   // Bank Mode Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the BANKMODE_COMMIT register
//
//*************************************************************************************************
#define SSU_BANKMODE_COMMIT_COMMIT   0x1U   // Bank Mode Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the SECCFG_UPDATE_CFG register
//
//*************************************************************************************************
#define SSU_SECCFG_UPDATE_CFG_LINK_OWNER_S   0U
#define SSU_SECCFG_UPDATE_CFG_LINK_OWNER_M   0xFU      // SECCFG Update Owner LINK
#define SSU_SECCFG_UPDATE_CFG_CPU_OWNER_S    8U
#define SSU_SECCFG_UPDATE_CFG_CPU_OWNER_M    0x700U    // SECCFG Update Owner CPU
#define SSU_SECCFG_UPDATE_CFG_UPDATE_EN_S    12U
#define SSU_SECCFG_UPDATE_CFG_UPDATE_EN_M    0xF000U   // SECCFG Update Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the PROG_BANKMODE register
//
//*************************************************************************************************
#define SSU_PROG_BANKMODE_MODE_S   0U
#define SSU_PROG_BANKMODE_MODE_M   0x3U   // Device Flash Configuration Mode

//*************************************************************************************************
//
// The following are defines for the bit fields in the SECVALID register
//
//*************************************************************************************************
#define SSU_SECVALID_CPU1_S   0U
#define SSU_SECVALID_CPU1_M   0xFFU       // Valid CPU1/CPU2 SECCFG Sector
#define SSU_SECVALID_CPU3_S   16U
#define SSU_SECVALID_CPU3_M   0xFF0000U   // Valid CPU3 SECCFG Sector

//*************************************************************************************************
//
// The following are defines for the bit fields in the SECVALID_LOCK register
//
//*************************************************************************************************
#define SSU_SECVALID_LOCK_LOCK   0x1U   // SECVALID LOCK

//*************************************************************************************************
//
// The following are defines for the bit fields in the SECVALID_COMMIT register
//
//*************************************************************************************************
#define SSU_SECVALID_COMMIT_COMMIT   0x1U   // Security Sectors Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the ZONE1_CFG register
//
//*************************************************************************************************
#define SSU_ZONE1_CFG_FWU_LINK_S    0U
#define SSU_ZONE1_CFG_FWU_LINK_M    0xFU      // Firmware Update Owner LINK
#define SSU_ZONE1_CFG_FWU_CPU_S     8U
#define SSU_ZONE1_CFG_FWU_CPU_M     0x700U    // Firmware Update Owner CPU
#define SSU_ZONE1_CFG_UPDATE_EN_S   12U
#define SSU_ZONE1_CFG_UPDATE_EN_M   0xF000U   // ZONE1 Update Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ZONE2_CFG register
//
//*************************************************************************************************
#define SSU_ZONE2_CFG_FWU_LINK_S    0U
#define SSU_ZONE2_CFG_FWU_LINK_M    0xFU      // Firmware Update Owner LINK
#define SSU_ZONE2_CFG_FWU_CPU_S     8U
#define SSU_ZONE2_CFG_FWU_CPU_M     0x700U    // Firmware Update Owner CPU
#define SSU_ZONE2_CFG_UPDATE_EN_S   12U
#define SSU_ZONE2_CFG_UPDATE_EN_M   0xF000U   // ZONE2 Update Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ZONE3_CFG register
//
//*************************************************************************************************
#define SSU_ZONE3_CFG_FWU_LINK_S    0U
#define SSU_ZONE3_CFG_FWU_LINK_M    0xFU      // Firmware Update Owner LINK
#define SSU_ZONE3_CFG_FWU_CPU_S     8U
#define SSU_ZONE3_CFG_FWU_CPU_M     0x700U    // Firmware Update Owner CPU
#define SSU_ZONE3_CFG_UPDATE_EN_S   12U
#define SSU_ZONE3_CFG_UPDATE_EN_M   0xF000U   // ZONE3 Update Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEBUG_CFG register
//
//*************************************************************************************************
#define SSU_DEBUG_CFG_C29DBGEN_CFG_S   0U
#define SSU_DEBUG_CFG_C29DBGEN_CFG_M   0x7U      // C29DBGEN Enable Configuration
#define SSU_DEBUG_CFG_ZONE1_S          4U
#define SSU_DEBUG_CFG_ZONE1_M          0x70U     // ZONE1 Debug Enable Configuration
#define SSU_DEBUG_CFG_ZONE2_S          8U
#define SSU_DEBUG_CFG_ZONE2_M          0x700U    // ZONE2 Debug Enable Configuration
#define SSU_DEBUG_CFG_ZONE3_S          12U
#define SSU_DEBUG_CFG_ZONE3_M          0x7000U   // ZONE3 Debug Enable Configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEBUG_CFG_LOCK register
//
//*************************************************************************************************
#define SSU_DEBUG_CFG_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEBUG_CFG_COMMIT register
//
//*************************************************************************************************
#define SSU_DEBUG_CFG_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEBUG_STAT register
//
//*************************************************************************************************
#define SSU_DEBUG_STAT_ZONE1_S   2U
#define SSU_DEBUG_STAT_ZONE1_M   0xCU          // ZONE1 Debug State
#define SSU_DEBUG_STAT_ZONE2_S   4U
#define SSU_DEBUG_STAT_ZONE2_M   0x30U         // ZONE2 Debug State
#define SSU_DEBUG_STAT_ZONE3_S   6U
#define SSU_DEBUG_STAT_ZONE3_M   0xC0U         // ZONE3 Debug State
#define SSU_DEBUG_STAT_C29DBGS   0x80000000U   // C29 Debug Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the C29DBGEN register
//
//*************************************************************************************************
#define SSU_C29DBGEN_ENA_S   0U
#define SSU_C29DBGEN_ENA_M   0xFU   // C29 Debug Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the ZONE_DBGEN register
//
//*************************************************************************************************
#define SSU_ZONE_DBGEN_ZONE1_S   0U
#define SSU_ZONE_DBGEN_ZONE1_M   0x3FU       // ZONE1 Debug Enable
#define SSU_ZONE_DBGEN_ZONE2_S   8U
#define SSU_ZONE_DBGEN_ZONE2_M   0x3F00U     // ZONE2 Debug Enable
#define SSU_ZONE_DBGEN_ZONE3_S   16U
#define SSU_ZONE_DBGEN_ZONE3_M   0x3F0000U   // ZONE3 Debug Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the BEPROT_BANK register
//
//*************************************************************************************************
#define SSU_BEPROT_BANK_BANKID_S   0U
#define SSU_BEPROT_BANK_BANKID_M   0x7U    // Bank Erase Bank
#define SSU_BEPROT_BANK_FLCID_S    3U
#define SSU_BEPROT_BANK_FLCID_M    0x18U   // Bank Erase Bank

//*************************************************************************************************
//
// The following are defines for the bit fields in the BEPROT_STAT register
//
//*************************************************************************************************
#define SSU_BEPROT_STAT_READY    0x1U   // Bank Erase State Machine Ready
#define SSU_BEPROT_STAT_ACTIVE   0x2U   // Bank Erase State Machine Initializing

//*************************************************************************************************
//
// The following are defines for the bit fields in the BEPROTA register
//
//*************************************************************************************************
#define SSU_BEPROTA_SECT0    0x1U          // Sector 0 Bank Erase Protection
#define SSU_BEPROTA_SECT1    0x2U          // Sector 1 Bank Erase Protection
#define SSU_BEPROTA_SECT2    0x4U          // Sector 2 Bank Erase Protection
#define SSU_BEPROTA_SECT3    0x8U          // Sector 3 Bank Erase Protection
#define SSU_BEPROTA_SECT4    0x10U         // Sector 4 Bank Erase Protection
#define SSU_BEPROTA_SECT5    0x20U         // Sector 5 Bank Erase Protection
#define SSU_BEPROTA_SECT6    0x40U         // Sector 6 Bank Erase Protection
#define SSU_BEPROTA_SECT7    0x80U         // Sector 7 Bank Erase Protection
#define SSU_BEPROTA_SECT8    0x100U        // Sector 8 Bank Erase Protection
#define SSU_BEPROTA_SECT9    0x200U        // Sector 9 Bank Erase Protection
#define SSU_BEPROTA_SECT10   0x400U        // Sector 10 Bank Erase Protection
#define SSU_BEPROTA_SECT11   0x800U        // Sector 11 Bank Erase Protection
#define SSU_BEPROTA_SECT12   0x1000U       // Sector 12 Bank Erase Protection
#define SSU_BEPROTA_SECT13   0x2000U       // Sector 13 Bank Erase Protection
#define SSU_BEPROTA_SECT14   0x4000U       // Sector 14 Bank Erase Protection
#define SSU_BEPROTA_SECT15   0x8000U       // Sector 15 Bank Erase Protection
#define SSU_BEPROTA_SECT16   0x10000U      // Sector 16 Bank Erase Protection
#define SSU_BEPROTA_SECT17   0x20000U      // Sector 17 Bank Erase Protection
#define SSU_BEPROTA_SECT18   0x40000U      // Sector 18 Bank Erase Protection
#define SSU_BEPROTA_SECT19   0x80000U      // Sector 19 Bank Erase Protection
#define SSU_BEPROTA_SECT20   0x100000U     // Sector 20 Bank Erase Protection
#define SSU_BEPROTA_SECT21   0x200000U     // Sector 21 Bank Erase Protection
#define SSU_BEPROTA_SECT22   0x400000U     // Sector 22 Bank Erase Protection
#define SSU_BEPROTA_SECT23   0x800000U     // Sector 23 Bank Erase Protection
#define SSU_BEPROTA_SECT24   0x1000000U    // Sector 24 Bank Erase Protection
#define SSU_BEPROTA_SECT25   0x2000000U    // Sector 25 Bank Erase Protection
#define SSU_BEPROTA_SECT26   0x4000000U    // Sector 26 Bank Erase Protection
#define SSU_BEPROTA_SECT27   0x8000000U    // Sector 27 Bank Erase Protection
#define SSU_BEPROTA_SECT28   0x10000000U   // Sector 28 Bank Erase Protection
#define SSU_BEPROTA_SECT29   0x20000000U   // Sector 29 Bank Erase Protection
#define SSU_BEPROTA_SECT30   0x40000000U   // Sector 30 Bank Erase Protection
#define SSU_BEPROTA_SECT31   0x80000000U   // Sector 31 Bank Erase Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the BEPROTB register
//
//*************************************************************************************************
#define SSU_BEPROTB_SECT39_22     0x10U         // Sectors 39 - 22 Bank Erase Protection
#define SSU_BEPROTB_SECT47_40     0x20U         // Sectors 47 - 40 Bank Erase Protection
#define SSU_BEPROTB_SECT55_48     0x40U         // Sectors 55 - 48 Bank Erase Protection
#define SSU_BEPROTB_SECT63_56     0x80U         // Sectors 63 - 56 Bank Erase Protection
#define SSU_BEPROTB_SECT71_64     0x100U        // Sectors 71 - 64 Bank Erase Protection
#define SSU_BEPROTB_SECT79_72     0x200U        // Sectors 79 - 72 Bank Erase Protection
#define SSU_BEPROTB_SECT87_80     0x400U        // Sectors 87 - 80 Bank Erase Protection
#define SSU_BEPROTB_SECT95_88     0x800U        // Sectors 95 - 88 Bank Erase Protection
#define SSU_BEPROTB_SECT103_96    0x1000U       // Sectors 103 - 96 Bank Erase Protection
#define SSU_BEPROTB_SECT111_104   0x2000U       // Sectors 111 - 104 Bank Erase Protection
#define SSU_BEPROTB_SECT119_112   0x4000U       // Sectors 119 - 112 Bank Erase Protection
#define SSU_BEPROTB_SECT127_120   0x8000U       // Sectors 127 - 120 Bank Erase Protection
#define SSU_BEPROTB_SECT135_128   0x10000U      // Sectors 135 - 128 Bank Erase Protection
#define SSU_BEPROTB_SECT143_136   0x20000U      // Sectors 143 - 136 Bank Erase Protection
#define SSU_BEPROTB_SECT151_144   0x40000U      // Sectors 151 - 144 Bank Erase Protection
#define SSU_BEPROTB_SECT159_152   0x80000U      // Sectors 159 - 152 Bank Erase Protection
#define SSU_BEPROTB_SECT167_160   0x100000U     // Sectors 167 - 160 Bank Erase Protection
#define SSU_BEPROTB_SECT175_168   0x200000U     // Sectors 175 - 168 Bank Erase Protection
#define SSU_BEPROTB_SECT183_176   0x400000U     // Sectors 183 - 176 Bank Erase Protection
#define SSU_BEPROTB_SECT191_184   0x800000U     // Sectors 191 - 184 Bank Erase Protection
#define SSU_BEPROTB_SECT199_192   0x1000000U    // Sectors 199 - 192 Bank Erase Protection
#define SSU_BEPROTB_SECT207_200   0x2000000U    // Sectors 207 - 200 Bank Erase Protection
#define SSU_BEPROTB_SECT215_208   0x4000000U    // Sectors 215 - 208 Bank Erase Protection
#define SSU_BEPROTB_SECT223_216   0x8000000U    // Sectors 223 - 216 Bank Erase Protection
#define SSU_BEPROTB_SECT231_224   0x10000000U   // Sectors 231 - 224 Bank Erase Protection
#define SSU_BEPROTB_SECT239_232   0x20000000U   // Sectors 239 - 232 Bank Erase Protection
#define SSU_BEPROTB_SECT247_240   0x40000000U   // Sectors 247 - 240 Bank Erase Protection
#define SSU_BEPROTB_SECT255_248   0x80000000U   // Sectors 255 - 248 Bank Erase Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the FLSEMSTAT register
//
//*************************************************************************************************
#define SSU_FLSEMSTAT_LINK_S     0U
#define SSU_FLSEMSTAT_LINK_M     0xFU          // Semaphore LINK Owner
#define SSU_FLSEMSTAT_ZONE_S     8U
#define SSU_FLSEMSTAT_ZONE_M     0x300U        // Semaphore ZONE Owner
#define SSU_FLSEMSTAT_CPU_S      12U
#define SSU_FLSEMSTAT_CPU_M      0x7000U       // Semaphore CPU Owner
#define SSU_FLSEMSTAT_MATCH      0x40000000U   // Match Status Bit
#define SSU_FLSEMSTAT_ASSIGNED   0x80000000U   // Assigned Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the FLSEMREQ register
//
//*************************************************************************************************
#define SSU_FLSEMREQ_REQ   0x1U   // Request Semaphore Ownership

//*************************************************************************************************
//
// The following are defines for the bit fields in the FLSEMCLR register
//
//*************************************************************************************************
#define SSU_FLSEMCLR_CLR   0x1U   // Release Semaphore Ownership

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_CODE_BANKS register
//
//*************************************************************************************************
#define SSU_WEPROT_CODE_BANKS_PROT   0x1U   // Global Code Banks WEPROT

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_CODE_BANKS_LOCK register
//
//*************************************************************************************************
#define SSU_WEPROT_CODE_BANKS_LOCK_LOCK   0x1U   // System Access Protection Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_CODE_BANKS_COMMIT register
//
//*************************************************************************************************
#define SSU_WEPROT_CODE_BANKS_COMMIT_COMMIT   0x1U   // System Access Protection Register Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_DATA_BANKS register
//
//*************************************************************************************************
#define SSU_WEPROT_DATA_BANKS_PROT   0x1U   // Global Data Banks WEPROT

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_DATA_BANKS_LOCK register
//
//*************************************************************************************************
#define SSU_WEPROT_DATA_BANKS_LOCK_LOCK   0x1U   // System Access Protection Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_DATA_BANKS_COMMIT register
//
//*************************************************************************************************
#define SSU_WEPROT_DATA_BANKS_COMMIT_COMMIT   0x1U   // System Access Protection Register Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC1_B0_A register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC1_B0_A_SECT0    0x1U          // Sector 0 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT1    0x2U          // Sector 1 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT2    0x4U          // Sector 2 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT3    0x8U          // Sector 3 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT4    0x10U         // Sector 4 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT5    0x20U         // Sector 5 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT6    0x40U         // Sector 6 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT7    0x80U         // Sector 7 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT8    0x100U        // Sector 8 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT9    0x200U        // Sector 9 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT10   0x400U        // Sector 10 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT11   0x800U        // Sector 11 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT12   0x1000U       // Sector 12 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT13   0x2000U       // Sector 13 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT14   0x4000U       // Sector 14 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT15   0x8000U       // Sector 15 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT16   0x10000U      // Sector 16 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT17   0x20000U      // Sector 17 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT18   0x40000U      // Sector 18 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT19   0x80000U      // Sector 19 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT20   0x100000U     // Sector 20 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT21   0x200000U     // Sector 21 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT22   0x400000U     // Sector 22 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT23   0x800000U     // Sector 23 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT24   0x1000000U    // Sector 24 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT25   0x2000000U    // Sector 25 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT26   0x4000000U    // Sector 26 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT27   0x8000000U    // Sector 27 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT28   0x10000000U   // Sector 28 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT29   0x20000000U   // Sector 29 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT30   0x40000000U   // Sector 30 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_A_SECT31   0x80000000U   // Sector 31 Write Erase Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC1_B0_B register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC1_B0_B_SECT39_22     0x10U         // Sectors 39 - 22 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT47_40     0x20U         // Sectors 47 - 40 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT55_48     0x40U         // Sectors 55 - 48 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT63_56     0x80U         // Sectors 63 - 56 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT71_64     0x100U        // Sectors 71 - 64 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT79_72     0x200U        // Sectors 79 - 72 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT87_80     0x400U        // Sectors 87 - 80 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT95_88     0x800U        // Sectors 95 - 88 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT103_96    0x1000U       // Sectors 103 - 96 Write Erase Protection
#define SSU_WEPROT_FLC1_B0_B_SECT111_104   0x2000U       // Sectors 111 - 104 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT119_112   0x4000U       // Sectors 119 - 112 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT127_120   0x8000U       // Sectors 127 - 120 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT135_128   0x10000U      // Sectors 135 - 128 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT143_136   0x20000U      // Sectors 143 - 136 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT151_144   0x40000U      // Sectors 151 - 144 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT159_152   0x80000U      // Sectors 159 - 152 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT167_160   0x100000U     // Sectors 167 - 160 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT175_168   0x200000U     // Sectors 175 - 168 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT183_176   0x400000U     // Sectors 183 - 176 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT191_184   0x800000U     // Sectors 191 - 184 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT199_192   0x1000000U    // Sectors 199 - 192 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT207_200   0x2000000U    // Sectors 207 - 200 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT215_208   0x4000000U    // Sectors 215 - 208 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT223_216   0x8000000U    // Sectors 223 - 216 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT231_224   0x10000000U   // Sectors 231 - 224 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT239_232   0x20000000U   // Sectors 239 - 232 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT247_240   0x40000000U   // Sectors 247 - 240 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B0_B_SECT255_248   0x80000000U   // Sectors 255 - 248 Write Erase
                                                         // Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC1_B0_LOCK register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC1_B0_LOCK_LOCK   0x1U   // System Access Protection Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC1_B0_COMMIT register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC1_B0_COMMIT_COMMIT   0x1U   // System Access Protection Register Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC1_B2_A register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC1_B2_A_SECT0    0x1U          // Sector 0 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT1    0x2U          // Sector 1 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT2    0x4U          // Sector 2 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT3    0x8U          // Sector 3 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT4    0x10U         // Sector 4 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT5    0x20U         // Sector 5 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT6    0x40U         // Sector 6 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT7    0x80U         // Sector 7 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT8    0x100U        // Sector 8 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT9    0x200U        // Sector 9 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT10   0x400U        // Sector 10 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT11   0x800U        // Sector 11 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT12   0x1000U       // Sector 12 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT13   0x2000U       // Sector 13 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT14   0x4000U       // Sector 14 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT15   0x8000U       // Sector 15 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT16   0x10000U      // Sector 16 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT17   0x20000U      // Sector 17 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT18   0x40000U      // Sector 18 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT19   0x80000U      // Sector 19 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT20   0x100000U     // Sector 20 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT21   0x200000U     // Sector 21 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT22   0x400000U     // Sector 22 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT23   0x800000U     // Sector 23 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT24   0x1000000U    // Sector 24 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT25   0x2000000U    // Sector 25 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT26   0x4000000U    // Sector 26 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT27   0x8000000U    // Sector 27 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT28   0x10000000U   // Sector 28 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT29   0x20000000U   // Sector 29 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT30   0x40000000U   // Sector 30 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_A_SECT31   0x80000000U   // Sector 31 Write Erase Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC1_B2_B register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC1_B2_B_SECT39_22     0x10U         // Sectors 39 - 22 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT47_40     0x20U         // Sectors 47 - 40 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT55_48     0x40U         // Sectors 55 - 48 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT63_56     0x80U         // Sectors 63 - 56 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT71_64     0x100U        // Sectors 71 - 64 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT79_72     0x200U        // Sectors 79 - 72 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT87_80     0x400U        // Sectors 87 - 80 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT95_88     0x800U        // Sectors 95 - 88 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT103_96    0x1000U       // Sectors 103 - 96 Write Erase Protection
#define SSU_WEPROT_FLC1_B2_B_SECT111_104   0x2000U       // Sectors 111 - 104 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT119_112   0x4000U       // Sectors 119 - 112 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT127_120   0x8000U       // Sectors 127 - 120 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT135_128   0x10000U      // Sectors 135 - 128 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT143_136   0x20000U      // Sectors 143 - 136 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT151_144   0x40000U      // Sectors 151 - 144 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT159_152   0x80000U      // Sectors 159 - 152 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT167_160   0x100000U     // Sectors 167 - 160 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT175_168   0x200000U     // Sectors 175 - 168 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT183_176   0x400000U     // Sectors 183 - 176 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT191_184   0x800000U     // Sectors 191 - 184 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT199_192   0x1000000U    // Sectors 199 - 192 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT207_200   0x2000000U    // Sectors 207 - 200 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT215_208   0x4000000U    // Sectors 215 - 208 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT223_216   0x8000000U    // Sectors 223 - 216 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT231_224   0x10000000U   // Sectors 231 - 224 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT239_232   0x20000000U   // Sectors 239 - 232 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT247_240   0x40000000U   // Sectors 247 - 240 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC1_B2_B_SECT255_248   0x80000000U   // Sectors 255 - 248 Write Erase
                                                         // Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC1_B2_LOCK register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC1_B2_LOCK_LOCK   0x1U   // System Access Protection Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC1_B2_COMMIT register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC1_B2_COMMIT_COMMIT   0x1U   // System Access Protection Register Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC2_B0_A register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC2_B0_A_SECT0    0x1U          // Sector 0 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT1    0x2U          // Sector 1 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT2    0x4U          // Sector 2 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT3    0x8U          // Sector 3 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT4    0x10U         // Sector 4 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT5    0x20U         // Sector 5 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT6    0x40U         // Sector 6 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT7    0x80U         // Sector 7 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT8    0x100U        // Sector 8 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT9    0x200U        // Sector 9 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT10   0x400U        // Sector 10 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT11   0x800U        // Sector 11 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT12   0x1000U       // Sector 12 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT13   0x2000U       // Sector 13 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT14   0x4000U       // Sector 14 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT15   0x8000U       // Sector 15 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT16   0x10000U      // Sector 16 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT17   0x20000U      // Sector 17 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT18   0x40000U      // Sector 18 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT19   0x80000U      // Sector 19 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT20   0x100000U     // Sector 20 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT21   0x200000U     // Sector 21 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT22   0x400000U     // Sector 22 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT23   0x800000U     // Sector 23 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT24   0x1000000U    // Sector 24 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT25   0x2000000U    // Sector 25 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT26   0x4000000U    // Sector 26 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT27   0x8000000U    // Sector 27 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT28   0x10000000U   // Sector 28 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT29   0x20000000U   // Sector 29 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT30   0x40000000U   // Sector 30 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_A_SECT31   0x80000000U   // Sector 31 Write Erase Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC2_B0_B register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC2_B0_B_SECT39_22     0x10U         // Sectors 39 - 22 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT47_40     0x20U         // Sectors 47 - 40 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT55_48     0x40U         // Sectors 55 - 48 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT63_56     0x80U         // Sectors 63 - 56 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT71_64     0x100U        // Sectors 71 - 64 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT79_72     0x200U        // Sectors 79 - 72 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT87_80     0x400U        // Sectors 87 - 80 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT95_88     0x800U        // Sectors 95 - 88 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT103_96    0x1000U       // Sectors 103 - 96 Write Erase Protection
#define SSU_WEPROT_FLC2_B0_B_SECT111_104   0x2000U       // Sectors 111 - 104 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT119_112   0x4000U       // Sectors 119 - 112 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT127_120   0x8000U       // Sectors 127 - 120 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT135_128   0x10000U      // Sectors 135 - 128 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT143_136   0x20000U      // Sectors 143 - 136 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT151_144   0x40000U      // Sectors 151 - 144 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT159_152   0x80000U      // Sectors 159 - 152 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT167_160   0x100000U     // Sectors 167 - 160 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT175_168   0x200000U     // Sectors 175 - 168 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT183_176   0x400000U     // Sectors 183 - 176 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT191_184   0x800000U     // Sectors 191 - 184 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT199_192   0x1000000U    // Sectors 199 - 192 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT207_200   0x2000000U    // Sectors 207 - 200 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT215_208   0x4000000U    // Sectors 215 - 208 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT223_216   0x8000000U    // Sectors 223 - 216 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT231_224   0x10000000U   // Sectors 231 - 224 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT239_232   0x20000000U   // Sectors 239 - 232 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT247_240   0x40000000U   // Sectors 247 - 240 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B0_B_SECT255_248   0x80000000U   // Sectors 255 - 248 Write Erase
                                                         // Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC2_B0_LOCK register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC2_B0_LOCK_LOCK   0x1U   // System Access Protection Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC2_B0_COMMIT register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC2_B0_COMMIT_COMMIT   0x1U   // System Access Protection Register Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC2_B2_A register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC2_B2_A_SECT0    0x1U          // Sector 0 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT1    0x2U          // Sector 1 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT2    0x4U          // Sector 2 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT3    0x8U          // Sector 3 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT4    0x10U         // Sector 4 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT5    0x20U         // Sector 5 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT6    0x40U         // Sector 6 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT7    0x80U         // Sector 7 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT8    0x100U        // Sector 8 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT9    0x200U        // Sector 9 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT10   0x400U        // Sector 10 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT11   0x800U        // Sector 11 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT12   0x1000U       // Sector 12 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT13   0x2000U       // Sector 13 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT14   0x4000U       // Sector 14 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT15   0x8000U       // Sector 15 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT16   0x10000U      // Sector 16 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT17   0x20000U      // Sector 17 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT18   0x40000U      // Sector 18 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT19   0x80000U      // Sector 19 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT20   0x100000U     // Sector 20 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT21   0x200000U     // Sector 21 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT22   0x400000U     // Sector 22 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT23   0x800000U     // Sector 23 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT24   0x1000000U    // Sector 24 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT25   0x2000000U    // Sector 25 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT26   0x4000000U    // Sector 26 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT27   0x8000000U    // Sector 27 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT28   0x10000000U   // Sector 28 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT29   0x20000000U   // Sector 29 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT30   0x40000000U   // Sector 30 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_A_SECT31   0x80000000U   // Sector 31 Write Erase Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC2_B2_B register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC2_B2_B_SECT39_22     0x10U         // Sectors 39 - 22 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT47_40     0x20U         // Sectors 47 - 40 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT55_48     0x40U         // Sectors 55 - 48 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT63_56     0x80U         // Sectors 63 - 56 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT71_64     0x100U        // Sectors 71 - 64 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT79_72     0x200U        // Sectors 79 - 72 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT87_80     0x400U        // Sectors 87 - 80 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT95_88     0x800U        // Sectors 95 - 88 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT103_96    0x1000U       // Sectors 103 - 96 Write Erase Protection
#define SSU_WEPROT_FLC2_B2_B_SECT111_104   0x2000U       // Sectors 111 - 104 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT119_112   0x4000U       // Sectors 119 - 112 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT127_120   0x8000U       // Sectors 127 - 120 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT135_128   0x10000U      // Sectors 135 - 128 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT143_136   0x20000U      // Sectors 143 - 136 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT151_144   0x40000U      // Sectors 151 - 144 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT159_152   0x80000U      // Sectors 159 - 152 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT167_160   0x100000U     // Sectors 167 - 160 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT175_168   0x200000U     // Sectors 175 - 168 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT183_176   0x400000U     // Sectors 183 - 176 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT191_184   0x800000U     // Sectors 191 - 184 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT199_192   0x1000000U    // Sectors 199 - 192 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT207_200   0x2000000U    // Sectors 207 - 200 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT215_208   0x4000000U    // Sectors 215 - 208 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT223_216   0x8000000U    // Sectors 223 - 216 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT231_224   0x10000000U   // Sectors 231 - 224 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT239_232   0x20000000U   // Sectors 239 - 232 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT247_240   0x40000000U   // Sectors 247 - 240 Write Erase
                                                         // Protection
#define SSU_WEPROT_FLC2_B2_B_SECT255_248   0x80000000U   // Sectors 255 - 248 Write Erase
                                                         // Protection

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC2_B2_LOCK register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC2_B2_LOCK_LOCK   0x1U   // System Access Protection Register Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the WEPROT_FLC2_B2_COMMIT register
//
//*************************************************************************************************
#define SSU_WEPROT_FLC2_B2_COMMIT_COMMIT   0x1U   // System Access Protection Register Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the RST_LINK register
//
//*************************************************************************************************
#define SSU_RST_LINK_LINK_S   0U
#define SSU_RST_LINK_LINK_M   0xFU   // Reset LINK Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU_RST_CTRL register
//
//*************************************************************************************************
#define SSU_CPU_RST_CTRL_SW_SYSRSN_S   0U
#define SSU_CPU_RST_CTRL_SW_SYSRSN_M   0xFFU   // System CPU Reset

//*************************************************************************************************
//
// The following are defines for the bit fields in the DEF_NMI_LINK register
//
//*************************************************************************************************
#define SSU_DEF_NMI_LINK_LINK_S   0U
#define SSU_DEF_NMI_LINK_LINK_M   0xFU   // Default NMI LINK Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the EMU_BOOTDEF_LOW register
//
//*************************************************************************************************
#define SSU_EMU_BOOTDEF_LOW_BOOT_DEF0_S   0U
#define SSU_EMU_BOOTDEF_LOW_BOOT_DEF0_M   0xFFU         // Boot Definitions 0
#define SSU_EMU_BOOTDEF_LOW_BOOT_DEF1_S   8U
#define SSU_EMU_BOOTDEF_LOW_BOOT_DEF1_M   0xFF00U       // Boot Definitions 1
#define SSU_EMU_BOOTDEF_LOW_BOOT_DEF2_S   16U
#define SSU_EMU_BOOTDEF_LOW_BOOT_DEF2_M   0xFF0000U     // Boot Definitions 2
#define SSU_EMU_BOOTDEF_LOW_BOOT_DEF3_S   24U
#define SSU_EMU_BOOTDEF_LOW_BOOT_DEF3_M   0xFF000000U   // Boot Definitions 3

//*************************************************************************************************
//
// The following are defines for the bit fields in the EMU_BOOTDEF_HIGH register
//
//*************************************************************************************************
#define SSU_EMU_BOOTDEF_HIGH_BOOT_DEF4_S   0U
#define SSU_EMU_BOOTDEF_HIGH_BOOT_DEF4_M   0xFFU         // Boot Definitions 4
#define SSU_EMU_BOOTDEF_HIGH_BOOT_DEF5_S   8U
#define SSU_EMU_BOOTDEF_HIGH_BOOT_DEF5_M   0xFF00U       // Boot Definitions 5
#define SSU_EMU_BOOTDEF_HIGH_BOOT_DEF6_S   16U
#define SSU_EMU_BOOTDEF_HIGH_BOOT_DEF6_M   0xFF0000U     // Boot Definitions 6
#define SSU_EMU_BOOTDEF_HIGH_BOOT_DEF7_S   24U
#define SSU_EMU_BOOTDEF_HIGH_BOOT_DEF7_M   0xFF000000U   // Boot Definitions 7

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK3_CFG register
//
//*************************************************************************************************
#define SSU_LINK3_CFG_STACK_S   0U
#define SSU_LINK3_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK4_CFG register
//
//*************************************************************************************************
#define SSU_LINK4_CFG_STACK_S   0U
#define SSU_LINK4_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK5_CFG register
//
//*************************************************************************************************
#define SSU_LINK5_CFG_STACK_S   0U
#define SSU_LINK5_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK6_CFG register
//
//*************************************************************************************************
#define SSU_LINK6_CFG_STACK_S   0U
#define SSU_LINK6_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK7_CFG register
//
//*************************************************************************************************
#define SSU_LINK7_CFG_STACK_S   0U
#define SSU_LINK7_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK8_CFG register
//
//*************************************************************************************************
#define SSU_LINK8_CFG_STACK_S   0U
#define SSU_LINK8_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK9_CFG register
//
//*************************************************************************************************
#define SSU_LINK9_CFG_STACK_S   0U
#define SSU_LINK9_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK10_CFG register
//
//*************************************************************************************************
#define SSU_LINK10_CFG_STACK_S   0U
#define SSU_LINK10_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK11_CFG register
//
//*************************************************************************************************
#define SSU_LINK11_CFG_STACK_S   0U
#define SSU_LINK11_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK12_CFG register
//
//*************************************************************************************************
#define SSU_LINK12_CFG_STACK_S   0U
#define SSU_LINK12_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK13_CFG register
//
//*************************************************************************************************
#define SSU_LINK13_CFG_STACK_S   0U
#define SSU_LINK13_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK14_CFG register
//
//*************************************************************************************************
#define SSU_LINK14_CFG_STACK_S   0U
#define SSU_LINK14_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the LINK15_CFG register
//
//*************************************************************************************************
#define SSU_LINK15_CFG_STACK_S   0U
#define SSU_LINK15_CFG_STACK_M   0x7U   // STACK Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the STACK3_CFG register
//
//*************************************************************************************************
#define SSU_STACK3_CFG_ZONE_S   0U
#define SSU_STACK3_CFG_ZONE_M   0x3U   // ZONE Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the STACK4_CFG register
//
//*************************************************************************************************
#define SSU_STACK4_CFG_ZONE_S   0U
#define SSU_STACK4_CFG_ZONE_M   0x3U   // ZONE Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the STACK5_CFG register
//
//*************************************************************************************************
#define SSU_STACK5_CFG_ZONE_S   0U
#define SSU_STACK5_CFG_ZONE_M   0x3U   // ZONE Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the STACK6_CFG register
//
//*************************************************************************************************
#define SSU_STACK6_CFG_ZONE_S   0U
#define SSU_STACK6_CFG_ZONE_M   0x3U   // ZONE Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the STACK7_CFG register
//
//*************************************************************************************************
#define SSU_STACK7_CFG_ZONE_S   0U
#define SSU_STACK7_CFG_ZONE_M   0x3U   // ZONE Association

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMOPENSTAT register
//
//*************************************************************************************************
#define SSU_RAMOPENSTAT_LINK1_RAMOPENS   0x2U   // LINK1 RAM Open Status Bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMOPENFRC register
//
//*************************************************************************************************
#define SSU_RAMOPENFRC_SET_LINK1           0x100U    // Set LINK1 RAM Open Request
#define SSU_RAMOPENFRC_WIPE_ON_LINK1_CLR   0x1000U   // Wipe LINK1 RAM on Clear Request

//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMOPENCLR register
//
//*************************************************************************************************
#define SSU_RAMOPENCLR_CLEAR_LINK1   0x2U   // Clear LINK1 RAM Open Request

//*************************************************************************************************
//
// The following are defines for the bit fields in the DECODER_ADDR_IN register
//
//*************************************************************************************************
#define SSU_DECODER_ADDR_IN_ADDR_L_S   12U
#define SSU_DECODER_ADDR_IN_ADDR_L_M   0xF000U       // Address Bits 15:12
#define SSU_DECODER_ADDR_IN_ADDR_H_S   16U
#define SSU_DECODER_ADDR_IN_ADDR_H_M   0xFFFF0000U   // Address Bits 31:16

//*************************************************************************************************
//
// The following are defines for the bit fields in the DECODER_OUT register
//
//*************************************************************************************************
#define SSU_DECODER_OUT_LINK_S    0U
#define SSU_DECODER_OUT_LINK_M    0xFU          // Decoded LINK
#define SSU_DECODER_OUT_STACK_S   4U
#define SSU_DECODER_OUT_STACK_M   0x70U         // Decoded STACK
#define SSU_DECODER_OUT_ZONE_S    8U
#define SSU_DECODER_OUT_ZONE_M    0x300U        // Decoded ZONE
#define SSU_DECODER_OUT_APR_S     16U
#define SSU_DECODER_OUT_APR_M     0x7F0000U     // Access Protection Region
#define SSU_DECODER_OUT_INVALID   0x80000000U   // Decoder Output Invalid

//*************************************************************************************************
//
// The following are defines for the bit fields in the EMU_DECODER_ADDR_IN register
//
//*************************************************************************************************
#define SSU_EMU_DECODER_ADDR_IN_ADDR_L_S   12U
#define SSU_EMU_DECODER_ADDR_IN_ADDR_L_M   0xF000U       // Address Bits 15:12
#define SSU_EMU_DECODER_ADDR_IN_ADDR_H_S   16U
#define SSU_EMU_DECODER_ADDR_IN_ADDR_H_M   0xFFFF0000U   // Address Bits 31:16

//*************************************************************************************************
//
// The following are defines for the bit fields in the EMU_DECODER_OUT register
//
//*************************************************************************************************
#define SSU_EMU_DECODER_OUT_LINK_S    0U
#define SSU_EMU_DECODER_OUT_LINK_M    0xFU          // Decoded LINK
#define SSU_EMU_DECODER_OUT_STACK_S   4U
#define SSU_EMU_DECODER_OUT_STACK_M   0x70U         // Decoded STACK
#define SSU_EMU_DECODER_OUT_ZONE_S    8U
#define SSU_EMU_DECODER_OUT_ZONE_M    0x300U        // Decoded ZONE
#define SSU_EMU_DECODER_OUT_APR_S     16U
#define SSU_EMU_DECODER_OUT_APR_M     0x7F0000U     // Access Protection Region
#define SSU_EMU_DECODER_OUT_INVALID   0x80000000U   // Decoder Output Invalid


//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_START_EXT register
//
//*************************************************************************************************
#define SSU_AP_START_EXT_ADDRL_S   12U
#define SSU_AP_START_EXT_ADDRL_M   0xF000U       // Lower End Address
#define SSU_AP_START_EXT_ADDRH_S   16U
#define SSU_AP_START_EXT_ADDRH_M   0xFFFF0000U   // Upper End Address

//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_END_EXT register
//
//*************************************************************************************************
#define SSU_AP_END_EXT_ADDRL_S   12U
#define SSU_AP_END_EXT_ADDRL_M   0xF000U       // Lower End Address
#define SSU_AP_END_EXT_ADDRH_S   16U
#define SSU_AP_END_EXT_ADDRH_M   0xFFFF0000U   // Upper End Address


//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_CFG register
//
//*************************************************************************************************
#define SSU_AP_CFG_LINKID_S    0U
#define SSU_AP_CFG_LINKID_M    0xFU      // LINK ID Value
#define SSU_AP_CFG_APD         0x40U     // Access Protection Disable
#define SSU_AP_CFG_XE          0x80U     // Execute Enable
#define SSU_AP_CFG_APILINK_S   8U
#define SSU_AP_CFG_APILINK_M   0xF00U    // Access Protection Inheritance LINK
#define SSU_AP_CFG_APILINKE    0x4000U   // Access Protection Inheritance LINK Enable

//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_START register
//
//*************************************************************************************************
#define SSU_AP_START_ADDRL_S     12U
#define SSU_AP_START_ADDRL_M     0xF000U       // Lower Start Address
#define SSU_AP_START_ADDRH_S     16U
#define SSU_AP_START_ADDRH_M     0xFF0000U     // Upper Start Address
#define SSU_AP_START_MEMTYPE_S   28U
#define SSU_AP_START_MEMTYPE_M   0x70000000U   // Start Address Memory Type

//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_END register
//
//*************************************************************************************************
#define SSU_AP_END_ADDRL_S     12U
#define SSU_AP_END_ADDRL_M     0xF000U       // Lower End Address
#define SSU_AP_END_ADDRH_S     16U
#define SSU_AP_END_ADDRH_M     0xFF0000U     // Upper End Address
#define SSU_AP_END_MEMTYPE_S   28U
#define SSU_AP_END_MEMTYPE_M   0x70000000U   // Start Address Memory Type

//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_LOCK register
//
//*************************************************************************************************
#define SSU_AP_LOCK_LOCK   0x1U   // Temporary Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_COMMIT register
//
//*************************************************************************************************
#define SSU_AP_COMMIT_COMMIT   0x1U   // Permanent Commit

//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_ACCESS register
//
//*************************************************************************************************
#define SSU_AP_ACCESS_LINK0_S    0U
#define SSU_AP_ACCESS_LINK0_M    0x3U          // LINK0 Access Permissions
#define SSU_AP_ACCESS_LINK1_S    2U
#define SSU_AP_ACCESS_LINK1_M    0xCU          // LINK1 Access Permissions
#define SSU_AP_ACCESS_LINK2_S    4U
#define SSU_AP_ACCESS_LINK2_M    0x30U         // LINK2 Access Permissions
#define SSU_AP_ACCESS_LINK3_S    6U
#define SSU_AP_ACCESS_LINK3_M    0xC0U         // LINK3 Access Permissions
#define SSU_AP_ACCESS_LINK4_S    8U
#define SSU_AP_ACCESS_LINK4_M    0x300U        // LINK4 Access Permissions
#define SSU_AP_ACCESS_LINK5_S    10U
#define SSU_AP_ACCESS_LINK5_M    0xC00U        // LINK5 Access Permissions
#define SSU_AP_ACCESS_LINK6_S    12U
#define SSU_AP_ACCESS_LINK6_M    0x3000U       // LINK6 Access Permissions
#define SSU_AP_ACCESS_LINK7_S    14U
#define SSU_AP_ACCESS_LINK7_M    0xC000U       // LINK7 Access Permissions
#define SSU_AP_ACCESS_LINK8_S    16U
#define SSU_AP_ACCESS_LINK8_M    0x30000U      // LINK8 Access Permissions
#define SSU_AP_ACCESS_LINK9_S    18U
#define SSU_AP_ACCESS_LINK9_M    0xC0000U      // LINK9 Access Permissions
#define SSU_AP_ACCESS_LINK10_S   20U
#define SSU_AP_ACCESS_LINK10_M   0x300000U     // LINK10 Access Permissions
#define SSU_AP_ACCESS_LINK11_S   22U
#define SSU_AP_ACCESS_LINK11_M   0xC00000U     // LINK11 Access Permissions
#define SSU_AP_ACCESS_LINK12_S   24U
#define SSU_AP_ACCESS_LINK12_M   0x3000000U    // LINK12 Access Permissions
#define SSU_AP_ACCESS_LINK13_S   26U
#define SSU_AP_ACCESS_LINK13_M   0xC000000U    // LINK13 Access Permissions
#define SSU_AP_ACCESS_LINK14_S   28U
#define SSU_AP_ACCESS_LINK14_M   0x30000000U   // LINK14 Access Permissions
#define SSU_AP_ACCESS_LINK15_S   30U
#define SSU_AP_ACCESS_LINK15_M   0xC0000000U   // LINK15 Access Permissions

//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_START register
//
//*************************************************************************************************
#define SSU_AP_START_ADDRL_S     12U
#define SSU_AP_START_ADDRL_M     0xF000U       // Lower Start Address
#define SSU_AP_START_ADDRH_S     16U
#define SSU_AP_START_ADDRH_M     0xFF0000U     // Upper Start Address
#define SSU_AP_START_MEMTYPE_S   28U
#define SSU_AP_START_MEMTYPE_M   0x70000000U   // Start Address Memory Type

//*************************************************************************************************
//
// The following are defines for the bit fields in the AP_END register
//
//*************************************************************************************************
#define SSU_AP_END_ADDRL_S     12U
#define SSU_AP_END_ADDRL_M     0xF000U       // Lower End Address
#define SSU_AP_END_ADDRH_S     16U
#define SSU_AP_END_ADDRH_M     0xFF0000U     // Upper End Address
#define SSU_AP_END_MEMTYPE_S   28U
#define SSU_AP_END_MEMTYPE_M   0x70000000U   // Start Address Memory Type



#endif
