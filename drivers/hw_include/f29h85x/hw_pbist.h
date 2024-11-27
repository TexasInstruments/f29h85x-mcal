//###########################################################################
//
// FILE:    hw_pbist.h
//
// TITLE:   Definitions for the PBIST registers.
//
//###########################################################################
// $Copyright:  $
//###########################################################################

#ifndef HW_PBIST_H
#define HW_PBIST_H

//*************************************************************************************************
//
// The following are defines for the PBIST register offsets
//
//*************************************************************************************************
#define PBIST_O_RAMT       0x2C0U   // RAM Configuration Register
#define PBIST_O_DLRT       0x2C8U   // PBIST Data Logger Register
#define PBIST_O_STR        0x2D8U   // Program Control Register
#define PBIST_O_PACT       0x300U   // PBIST Activate Register
#define PBIST_O_OVERRIDE   0x310U   // PBIST Override Register
#define PBIST_O_FSRF0      0x320U   // Fail Status - Port 0
#define PBIST_O_FSRF1      0x328U   // Fail Status - Port 1
#define PBIST_O_FSRC0      0x330U   // Fail Status Count - Port 0
#define PBIST_O_FSRC1      0x338U   // Fail Status Count - Port 1
#define PBIST_O_ALGO       0x388U   // PBIST Algorithm
#define PBIST_O_RINFOL     0x390U   // RAM Info Mask Register Lower
#define PBIST_O_RINFOU     0x398U   // RAM Info Mask Register Higher


//*************************************************************************************************
//
// The following are defines for the bit fields in the RAMT register
//
//*************************************************************************************************
#define PBIST_RAMT_RDS_S   16U
#define PBIST_RAMT_RDS_M   0xFF0000U     // Return Data Select
#define PBIST_RAMT_RGS_S   24U
#define PBIST_RAMT_RGS_M   0xFF000000U   // RAM Group Select

//*************************************************************************************************
//
// The following are defines for the bit fields in the DLRT register
//
//*************************************************************************************************
#define PBIST_DLRT_ROM_TEST       0x4U     // ROM-based testing
#define PBIST_DLRT_TCK_GATED      0x8U     // TCK gated
#define PBIST_DLRT_CONFIG_ACC     0x10U    // Config Access
#define PBIST_DLRT_GO_NOGO_TEST   0x200U   // GO/ NO-GO Testing

//*************************************************************************************************
//
// The following are defines for the bit fields in the STR register
//
//*************************************************************************************************
#define PBIST_STR_RESUME   0x2U   // Resume / Emulation Read
#define PBIST_STR_STOP     0x4U   // Stops PBIST testing

//*************************************************************************************************
//
// The following are defines for the bit fields in the PACT register
//
//*************************************************************************************************
#define PBIST_PACT_ENABLE   0x1U   // Enable clocks to PBIST

//*************************************************************************************************
//
// The following are defines for the bit fields in the OVERRIDE register
//
//*************************************************************************************************
#define PBIST_OVERRIDE_RINFO_MEM_OVER   0x1U   // ROM Memory Information Override
#define PBIST_OVERRIDE_ALGO_OVER        0x8U   // ROM Algorithm Override



#endif
