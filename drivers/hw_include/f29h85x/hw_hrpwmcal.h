//###########################################################################
//
// FILE:    hw_hrpwmcal.h
//
// TITLE:   Definitions for the HRPWMCAL registers.
//
//###########################################################################
// $Copyright:  $
//###########################################################################

#ifndef HW_HRPWMCAL_H
#define HW_HRPWMCAL_H

//*************************************************************************************************
//
// The following are defines for the HRPWMCAL register offsets
//
//*************************************************************************************************
#define HRPWMCAL_O_HRPWR     0x42U   // HRPWM Power Register
#define HRPWMCAL_O_HRMSTEP   0x4CU   // HRPWM MEP Step Register


//*************************************************************************************************
//
// The following are defines for the bit fields in the HRPWR register
//
//*************************************************************************************************
#define HRPWMCAL_HRPWR_CALPWRON   0x8000U   // Calibration Power On

//*************************************************************************************************
//
// The following are defines for the bit fields in the HRMSTEP register
//
//*************************************************************************************************
#define HRPWMCAL_HRMSTEP_HRMSTEP_S   0U
#define HRPWMCAL_HRMSTEP_HRMSTEP_M   0xFFU   // High Resolution Micro Step Value



#endif
