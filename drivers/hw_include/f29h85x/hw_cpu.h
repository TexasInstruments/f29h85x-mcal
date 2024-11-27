//###########################################################################
//
// FILE:    hw_cpu.h
//
// TITLE:   Definitions for the CPU registers.
//
//###########################################################################
// $Copyright:  $
//###########################################################################

#ifndef HW_CPU_H
#define HW_CPU_H

//*************************************************************************************************
//
// The following are defines for the CPU register offsets
//
//*************************************************************************************************
#define CPU_O_Y0I_DATA(i)     (0x0U + ((i) * 0x4U))      // (0 <= i < 1152) TMU ROM Y0i Data
#define CPU_O_Y0I_PARITY(i)   (0x2000U + ((i) * 0x4U))   // (0 <= i < 1152) TMU ROM Y0i Parity
#define CPU_O_S1I_DATA(i)     (0x4000U + ((i) * 0x4U))   // (0 <= i < 1152) TMU ROM S1i Data
#define CPU_O_S2I_DATA(i)     (0x6000U + ((i) * 0x4U))   // (0 <= i < 1152) TMU ROM S2i Data

#define CPU_O_RTINT_STACK_DATA0(i)   (0x0U + ((i) * 64))    // (0 <= i < 256) RTINT stack Data0
#define CPU_O_RTINT_STACK_DATA1(i)   (0x4U + ((i) * 64))    // (0 <= i < 256) RTINT stack Data1
#define CPU_O_RTINT_STACK_DATA2(i)   (0x8U + ((i) * 64))    // (0 <= i < 256) RTINT stack Data2
#define CPU_O_RTINT_STACK_DATA3(i)   (0xCU + ((i) * 64))    // (0 <= i < 256) RTINT stack Data3
#define CPU_O_RTINT_STACK_DATA4(i)   (0x10U + ((i) * 64))   // (0 <= i < 256) RTINT stack Data4
#define CPU_O_RTINT_STACK_DATA5(i)   (0x14U + ((i) * 64))   // (0 <= i < 256) RTINT stack Data5
#define CPU_O_RTINT_STACK_DATA6(i)   (0x18U + ((i) * 64))   // (0 <= i < 256) RTINT stack Data6
#define CPU_O_RTINT_STACK_DATA7(i)   (0x1CU + ((i) * 64))   // (0 <= i < 256) RTINT stack Data7
#define CPU_O_RTINT_STACK_DATA8(i)   (0x20U + ((i) * 64))   // (0 <= i < 256) RTINT stack Data8
#define CPU_O_RTINT_STACK_ECC0(i)    (0x24U + ((i) * 64))   // (0 <= i < 256) RTINT stack ECC0
#define CPU_O_RTINT_STACK_ECC1(i)    (0x28U + ((i) * 64))   // (0 <= i < 256) RTINT stack ECC1
#define CPU_O_RTINT_STACK_ECC2(i)    (0x2CU + ((i) * 64))   // (0 <= i < 256) RTINT stack ECC2
#define CPU_O_RTINT_STACK_ECC3(i)    (0x30U + ((i) * 64))   // (0 <= i < 256) RTINT stack ECC3

#define CPU_O_SECCALL_STACK_DATA0(i)   (0x0U + ((i) * 16))   // (0 <= i < 17) SECCALL stack Data0
#define CPU_O_SECCALL_STACK_DATA1(i)   (0x4U + ((i) * 16))   // (0 <= i < 17) SECCALL stack Data1
#define CPU_O_SECCALL_STACK_DATA2(i)   (0x8U + ((i) * 16))   // (0 <= i < 17) SECCALL stack Data2

#define CPU_O_SECSP0            0x0U    // Secure Stackpointer 0
#define CPU_O_SECSP1            0x4U    // Secure Stackpointer 1
#define CPU_O_SECSP2            0x8U    // Secure Stackpointer 2
#define CPU_O_SECSP3            0xCU    // Secure Stackpointer 3
#define CPU_O_SECSP4            0x10U   // Secure Stackpointer 4
#define CPU_O_SECSP5            0x14U   // Secure Stackpointer 5
#define CPU_O_SECSP6            0x18U   // Secure Stackpointer 6
#define CPU_O_SECSP7            0x1CU   // Secure Stackpointer 7
#define CPU_O_SECSP8            0x20U   // Secure Stackpointer 8
#define CPU_O_SECSP9            0x24U   // Secure Stackpointer 9
#define CPU_O_SECSP10           0x28U   // Secure Stackpointer 10
#define CPU_O_SECSP11           0x2CU   // Secure Stackpointer 11
#define CPU_O_SECSP12           0x30U   // Secure Stackpointer 12
#define CPU_O_SECSP13           0x34U   // Secure Stackpointer 13
#define CPU_O_SECSP14           0x38U   // Secure Stackpointer 14
#define CPU_O_SECSP15           0x3CU   // Secure Stackpointer 15
#define CPU_O_PSP               0x80U   // Protected call stack pointer
#define CPU_O_WARNPSP           0x84U   // Warning level register for protected call stack pointer
#define CPU_O_MAXPSP            0x88U   // Maximum levels of protected calls supported by the HW
#define CPU_O_REVISION          0x8CU   // IP revision id register
#define CPU_O_C29_REGS_LOCK     0x90U   // Lock register
#define CPU_O_C29_REGS_COMMIT   0x94U   // Commit register

#define CPU_O_FLTEMU_CONFIG       0x0U    // Fault emulation configuration registerr
#define CPU_O_FLTEMU_ACCGRPSEL    0x4U    // Fault emulation access information group selection
                                          // register
#define CPU_O_FLTEMU_BITSEL       0x8U    // Fault emulation bitsel
#define CPU_O_FLTEMU_ADDR         0xCU    // Fault emulation access address register
#define CPU_O_TMU_ROM_PAR_FORCE   0x10U   // Force TMU ROM Parity error

#define CPU_O_SELFTEST_DIAG_DATA0        0x0U    // Diagnostics data register 0
#define CPU_O_SELFTEST_DIAG_DATA1        0x4U    // Diagnostics data register 1
#define CPU_O_SELFTEST_DIAG_DATA2        0x8U    // Diagnostics data register 2
#define CPU_O_SELFTEST_DIAG_ECC          0x20U   // Diagnostics ECC
#define CPU_O_SELFTEST_DIAG_CONTROL      0x28U   // Diagnostic test enable
#define CPU_O_SELFTEST_DIAG_STATUS       0x2CU   // Diagnostic status register
#define CPU_O_SELFTEST_DIAG_STATUS_CLR   0x30U   // Diagnostic status clear register


//*************************************************************************************************
//
// The following are defines for the bit fields in the Y0i_PARITY register
//
//*************************************************************************************************
#define CPU_Y0I_PARITY_Y0_PARITY_S   0U
#define CPU_Y0I_PARITY_Y0_PARITY_M   0xFU   // TMU ROM Y0i PARITY

//*************************************************************************************************
//
// The following are defines for the bit fields in the S1i_DATA register
//
//*************************************************************************************************
#define CPU_S1I_DATA_S1_DATA_S     0U
#define CPU_S1I_DATA_S1_DATA_M     0xFFFFFFU    // TMU ROM S1i Data
#define CPU_S1I_DATA_S1_PARITY_S   24U
#define CPU_S1I_DATA_S1_PARITY_M   0x7000000U   // TMU ROM S1i Parity

//*************************************************************************************************
//
// The following are defines for the bit fields in the S2i_DATA register
//
//*************************************************************************************************
#define CPU_S2I_DATA_S2_DATA_S     0U
#define CPU_S2I_DATA_S2_DATA_M     0xFFFFFU    // TMU ROM S2i Data
#define CPU_S2I_DATA_S2_PARITY_S   20U
#define CPU_S2I_DATA_S2_PARITY_M   0x700000U   // TMU ROM S2i Parity


//*************************************************************************************************
//
// The following are defines for the bit fields in the RTINT_STACK_ECC0 register
//
//*************************************************************************************************
#define CPU_RTINT_STACK_ECC0_RTINT_STACK_ECC0_S   0U
#define CPU_RTINT_STACK_ECC0_RTINT_STACK_ECC0_M   0xFFU   // RTINT_STACK_ECC0

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTINT_STACK_ECC1 register
//
//*************************************************************************************************
#define CPU_RTINT_STACK_ECC1_RTINT_STACK_ECC1_S   0U
#define CPU_RTINT_STACK_ECC1_RTINT_STACK_ECC1_M   0xFFU   // RTINT_STACK_ECC1

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTINT_STACK_ECC2 register
//
//*************************************************************************************************
#define CPU_RTINT_STACK_ECC2_RTINT_STACK_ECC2_S   0U
#define CPU_RTINT_STACK_ECC2_RTINT_STACK_ECC2_M   0xFFU   // RTINT_STACK_ECC2

//*************************************************************************************************
//
// The following are defines for the bit fields in the RTINT_STACK_ECC3 register
//
//*************************************************************************************************
#define CPU_RTINT_STACK_ECC3_RTINT_STACK_ECC3_S   0U
#define CPU_RTINT_STACK_ECC3_RTINT_STACK_ECC3_M   0xFFU   // RTINT_STACK_ECC3


//*************************************************************************************************
//
// The following are defines for the bit fields in the SECCALL_STACK_DATA2 register
//
//*************************************************************************************************
#define CPU_SECCALL_STACK_DATA2_SECCALL_STACK_DATA2_S   0U
#define CPU_SECCALL_STACK_DATA2_SECCALL_STACK_DATA2_M   0xFU   // Secure call stack Data2


//*************************************************************************************************
//
// The following are defines for the bit fields in the PSP register
//
//*************************************************************************************************
#define CPU_PSP_PSP_S   0U
#define CPU_PSP_PSP_M   0xFFFU   // Protected call stack pointer

//*************************************************************************************************
//
// The following are defines for the bit fields in the WARNPSP register
//
//*************************************************************************************************
#define CPU_WARNPSP_WARNPSP_S   0U
#define CPU_WARNPSP_WARNPSP_M   0xFFFU   // Warning level for protected call stack pointer

//*************************************************************************************************
//
// The following are defines for the bit fields in the MAXPSP register
//
//*************************************************************************************************
#define CPU_MAXPSP_MAXPSP_S   0U
#define CPU_MAXPSP_MAXPSP_M   0xFFFU   // Maximum levels of protected calls supported by the HW

//*************************************************************************************************
//
// The following are defines for the bit fields in the REVISION register
//
//*************************************************************************************************
#define CPU_REVISION_MINREV_S               0U
#define CPU_REVISION_MINREV_M               0xFFU     // Minor Revision Number
#define CPU_REVISION_MAJREV_REVISION_S      8U
#define CPU_REVISION_MAJREV_REVISION_M      0x700U    // Major Revision Number
#define CPU_REVISION_MAJREV_FPU64_PRESENT   0x800U    // FPU64 Present
#define CPU_REVISION_MAJREV_TMU64_PRESENT   0x1000U   // TMU64 Present
#define CPU_REVISION_MAJREV_CPUCONFIG_S     13U
#define CPU_REVISION_MAJREV_CPUCONFIG_M     0xE000U   // CPU configuration

//*************************************************************************************************
//
// The following are defines for the bit fields in the C29_REGS_LOCK register
//
//*************************************************************************************************
#define CPU_C29_REGS_LOCK_C29_RTINT_STACK     0x2U    // C29 RTINT stack registers Lock
#define CPU_C29_REGS_LOCK_C29_SECCALL_STACK   0x4U    // C29 SECCALL stack registers Lock
#define CPU_C29_REGS_LOCK_C29_SECURE_REGS     0x8U    // C29 SECURE registers Lock
#define CPU_C29_REGS_LOCK_C29_DIAG_REGS       0x10U   // C29 DIAG registers Lock
#define CPU_C29_REGS_LOCK_C29_SELFTEST_REGS   0x20U   // C29 Selftest registers Lock

//*************************************************************************************************
//
// The following are defines for the bit fields in the C29_REGS_COMMIT register
//
//*************************************************************************************************
#define CPU_C29_REGS_COMMIT_C29_RTINT_STACK     0x2U    // C29 RTINT stack registers Commit
#define CPU_C29_REGS_COMMIT_C29_SECCALL_STACK   0x4U    // C29 SECCALL stack registers Commit
#define CPU_C29_REGS_COMMIT_C29_SECURE_REGS     0x8U    // C29 SECURE registers Commit
#define CPU_C29_REGS_COMMIT_C29_DIAG_REGS       0x10U   // C29 DIAG registers Commit
#define CPU_C29_REGS_COMMIT_C29_SELFTEST_REGS   0x20U   // C29 Selftest registers Commit


//*************************************************************************************************
//
// The following are defines for the bit fields in the FLTEMU_CONFIG register
//
//*************************************************************************************************
#define CPU_FLTEMU_CONFIG_ENABLE           0x1U      // Fault emulation enable
#define CPU_FLTEMU_CONFIG_DBL_BIT_INJ_EN   0x2U      // Double bit injection enable
#define CPU_FLTEMU_CONFIG_KEY_S            8U
#define CPU_FLTEMU_CONFIG_KEY_M            0xFF00U   // Write Key
#define CPU_FLTEMU_CONFIG_KEY              0xA500U   // Key Value

//*************************************************************************************************
//
// The following are defines for the bit fields in the FLTEMU_ACCGRPSEL register
//
//*************************************************************************************************
#define CPU_FLTEMU_ACCGRPSEL_CTRL_GROUP_SEL_S   0U
#define CPU_FLTEMU_ACCGRPSEL_CTRL_GROUP_SEL_M   0xFFU     // CTRL group selection
#define CPU_FLTEMU_ACCGRPSEL_DATA_GROUP_SEL_S   8U
#define CPU_FLTEMU_ACCGRPSEL_DATA_GROUP_SEL_M   0xFF00U   // DATA READ1 control information bus
                                                          // selection

//*************************************************************************************************
//
// The following are defines for the bit fields in the FLTEMU_BITSEL register
//
//*************************************************************************************************
#define CPU_FLTEMU_BITSEL_BITSEL_S   0U
#define CPU_FLTEMU_BITSEL_BITSEL_M   0x7FU   // Fault emulation bitselection

//*************************************************************************************************
//
// The following are defines for the bit fields in the TMU_ROM_PAR_FORCE register
//
//*************************************************************************************************
#define CPU_TMU_ROM_PAR_FORCE_TMU_ROM_PAR_FORCE   0x1U      // Fault emulation enable
#define CPU_TMU_ROM_PAR_FORCE_KEY_S               8U
#define CPU_TMU_ROM_PAR_FORCE_KEY_M               0xFF00U   // Write Key
#define CPU_TMU_ROM_PAR_FORCE_KEY                 0xA500U   // Key Value


//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_ECC register
//
//*************************************************************************************************
#define CPU_SELFTEST_DIAG_ECC_SELFTEST_DIAG_ECC_S   0U
#define CPU_SELFTEST_DIAG_ECC_SELFTEST_DIAG_ECC_M   0xFFU   // Self test Diagnostics ECC

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_CONTROL register
//
//*************************************************************************************************
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_TEST_EN_S                0U
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_TEST_EN_M                0xFU          // Diagnostic test
                                                                              // enable
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_MICRO_STEP_MODE          0x10U         // Diagnostic micro
                                                                              // step mode
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_ADDITIONAL_PIPELINE_EN   0x20U         // Additional
                                                                              // pipeline enable
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_SAFETY_SEL               0x40U         // Diagnostic safetly
                                                                              // selection
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_CHECKER_SEL_S            8U
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_CHECKER_SEL_M            0xF00U        // ECC checker
                                                                              // selection
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_ECC_WIDTH_S              16U
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_ECC_WIDTH_M              0xF0000U      // Diagnostic ECC
                                                                              // width
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_DATA_WIDTH_S             24U
#define CPU_SELFTEST_DIAG_CONTROL_DIAG_DATA_WIDTH_M             0xFF000000U   // Diagnostic Data
                                                                              // width

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_STATUS register
//
//*************************************************************************************************
#define CPU_SELFTEST_DIAG_STATUS_DIAG_MICROSTEP_DONE      0x1U      // Done Micro step
#define CPU_SELFTEST_DIAG_STATUS_DIAG_TEST_DONE           0x2U      // Done self test
#define CPU_SELFTEST_DIAG_STATUS_DIAG_TEST_FAIL           0x4U      // Test failed
#define CPU_SELFTEST_DIAG_STATUS_DIAG_FAIL_C_ERROR        0x8U      // Diagnostic correctable error
#define CPU_SELFTEST_DIAG_STATUS_DIAG_FAIL_UC_ERROR       0x10U     // Diagnostic uncorrectable
                                                                    // error
#define CPU_SELFTEST_DIAG_STATUS_DIAG_FAIL_CHECK_TYPE_S   5U
#define CPU_SELFTEST_DIAG_STATUS_DIAG_FAIL_CHECK_TYPE_M   0x60U     // Failed diagnostic check type
#define CPU_SELFTEST_DIAG_STATUS_DIAG_FAIL_BIT_INDEX_S    8U
#define CPU_SELFTEST_DIAG_STATUS_DIAG_FAIL_BIT_INDEX_M    0xFF00U   // Error bit position

//*************************************************************************************************
//
// The following are defines for the bit fields in the SELFTEST_DIAG_STATUS_CLR register
//
//*************************************************************************************************
#define CPU_SELFTEST_DIAG_STATUS_CLR_DIAG_MICROSTEP_DONE   0x1U   // Clear micro step done status
                                                                  // flag
#define CPU_SELFTEST_DIAG_STATUS_CLR_DIAG_TEST_DONE        0x2U   // Clear selftest done status
                                                                  // flag
#define CPU_SELFTEST_DIAG_STATUS_CLR_DIAG_TEST_FAIL        0x4U   // Clear test failed status flags



#endif
