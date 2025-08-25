//###########################################################################


#ifndef HW_HRPWMCAL_H
#define HW_HRPWMCAL_H


//*************************************************************************************************
//
// The following are defines for the HRPWMCAL register offsets
//
//*************************************************************************************************
#define HRPWMCAL_O_HRPWR     0x42U   // HRPWM Power Register
#define HRPWMCAL_O_HRCAL     0x44U   // HRPWM Calibration Register
#define HRPWMCAL_O_HRPRD     0x46U   // HRPWM Period Register
#define HRPWMCAL_O_HRCNT0    0x48U   // HRPWM Counter 0 Register
#define HRPWMCAL_O_HRCNT1    0x4AU   // HRPWM Counter 1 Register
#define HRPWMCAL_O_HRMSTEP   0x4CU   // HRPWM MEP Step Register



//*************************************************************************************************
//
// The following are defines for the bit fields in the HRPWR register
//
//*************************************************************************************************
#define HRPWMCAL_HRPWR_CALSTART   0x4U      // Calibration Start/Stop
#define HRPWMCAL_HRPWR_CNTSEL     0x8U      // Counter Select Bit
#define HRPWMCAL_HRPWR_CALSTS     0x10U     // Calibration Status Bit
#define HRPWMCAL_HRPWR_TESTSEL    0x20U     // Test Mode (Lump Delay) Select Bit
#define HRPWMCAL_HRPWR_CALSEL_S   6U
#define HRPWMCAL_HRPWR_CALSEL_M   0x3C0U    // ePWM Delay Line Selection for Calibration
#define HRPWMCAL_HRPWR_CALPWRON   0x8000U   // Calibration Power On


//*************************************************************************************************
//
// The following are defines for the bit fields in the HRCAL register
//
//*************************************************************************************************
#define HRPWMCAL_HRCAL_HRCAL_S   0U
#define HRPWMCAL_HRCAL_HRCAL_M   0xFFU   // Delay Line Calibration Value Register.


//*************************************************************************************************
//
// The following are defines for the bit fields in the HRMSTEP register
//
//*************************************************************************************************
#define HRPWMCAL_HRMSTEP_HRMSTEP_S   0U
#define HRPWMCAL_HRMSTEP_HRMSTEP_M   0xFFU   // High Resolution Micro Step Value




#endif