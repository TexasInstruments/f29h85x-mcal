//###########################################################################
//
// FILE:    hw_wd.h
//
// TITLE:   Definitions for the WD registers.
//
//###########################################################################
// $Copyright:  $
//###########################################################################

#ifndef HW_WD_H
#define HW_WD_H

//*************************************************************************************************
//
// The following are defines for the WD register offsets
//
//*************************************************************************************************
#define WD_O_SCSR   0x44U   // System Control & Status Register
#define WD_O_CNTR   0x46U   // Watchdog Counter Register
#define WD_O_KEY    0x4AU   // Watchdog Reset Key Register
#define WD_O_CR     0x52U   // Watchdog Control Register
#define WD_O_WCR    0x54U   // Watchdog Windowed Control Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the SCSR register
//
//*************************************************************************************************
#define WD_SCSR_WDOVERRIDE   0x1U   // WD Override for WDDIS bit
#define WD_SCSR_WDENINT      0x2U   // WD Interrupt Enable
#define WD_SCSR_WDINTS       0x4U   // WD Interrupt Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDCNTR register
//
//*************************************************************************************************
#define WD_CNTR_WDCNTR_S   0U
#define WD_CNTR_WDCNTR_M   0xFFU   // WD Counter

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDKEY register
//
//*************************************************************************************************
#define WD_KEY_WDKEY_S   0U
#define WD_KEY_WDKEY_M   0xFFU   // WD KEY

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDCR register
//
//*************************************************************************************************
#define WD_CR_WDPS_S          0U
#define WD_CR_WDPS_M          0x7U     // WD Clock Prescalar
#define WD_CR_WDCHK_S         3U
#define WD_CR_WDCHK_M         0x38U    // WD Check Bits
#define WD_CR_WDDIS           0x40U    // WD Disable
#define WD_CR_WDFLG           0x80U    // WD Reset Status Flag
#define WD_CR_WDPRECLKDIV_S   8U
#define WD_CR_WDPRECLKDIV_M   0xF00U   // WD Pre Clock Divider

//*************************************************************************************************
//
// The following are defines for the bit fields in the WDWCR register
//
//*************************************************************************************************
#define WD_WCR_MIN_S      0U
#define WD_WCR_MIN_M      0xFFU    // WD Min Threshold setting for Windowed Watchdog functionality
#define WD_WCR_FIRSTKEY   0x100U   // First Key Detect Flag



#endif
