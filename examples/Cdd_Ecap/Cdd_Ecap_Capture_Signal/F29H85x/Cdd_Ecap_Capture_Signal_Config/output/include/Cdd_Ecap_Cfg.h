/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited.  This product  is  protected  under  copyright  law
 *                 and  trade  secret law as an  unpublished work.
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Ecap_Cfg.h
 *  Generator:  None
 *
 *  Description:  Cdd_Ecap configuration header file                                                      
 *********************************************************************************************************************/
#ifndef CDD_ECAP_CFG_H
#define CDD_ECAP_CFG_H
/** \addtogroup CDD_ECAP
 *  @{
 */
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/* CDD ECAP Driver Configuration SW Version Info */

#define CDD_ECAP_CFG_MAJOR_VERSION           (3U)
#define CDD_ECAP_CFG_MINOR_VERSION           (1U)
#define CDD_ECAP_CFG_PATCH_VERSION           (0U)

/* Macro to define the number of channels configured */
#define CDD_ECAP_HW_CNT                      ((uint8)4U)

/** \brief Enable/Disable Cdd_Ecap DeInit API */
#define CDD_ECAP_DE_INIT_API                   (STD_ON)

/** \brief Enable/Disable Edge Count API */
#define CDD_ECAP_EDGE_COUNT_API                (STD_ON)

/** \brief Enable/Disable Edge Detect API */
#define CDD_ECAP_EDGE_DETECT_API               (STD_ON)

/** \brief Enable/Disable Get Duty Cycle Values API */
#define CDD_ECAP_GET_DUTY_CYCLE_VALUES_API     (STD_ON)

/** \brief Enable/Disable Get Input State API */
#define CDD_ECAP_GET_INPUT_STATE_API           (STD_ON)

/** \brief Enable/Disable Get Time Elapsed API */
#define CDD_ECAP_GET_TIME_ELAPSED_API          (STD_ON)

/** \brief Enable/Disable Get Version Info API */
#define CDD_ECAP_GET_VERSION_INFO_API          (STD_ON)

/** \brief Enable/Disable Signal Measurement API */
#define CDD_ECAP_SIGNAL_MEASUREMENT_API        (STD_ON)

/** \brief Enable/Disable Timestamp  API */
#define CDD_ECAP_TIMESTAMP_API                 (STD_ON)

/** \brief Enable/Disable High Resolution API */
#define CDD_ECAP_HR_API                        (STD_OFF)

/** \brief Enable/Disable Development error detet */
#define CDD_ECAP_DEV_ERROR_DETECT              (STD_ON)

/** \brief Maximum number of Cdd_Ecap channels */

#define CDD_ECAP_MAX_NUM_CHANNELS               (6U)










extern void Cdd_Ecap_TimeStampNotify (void);









extern void Cdd_Ecap_SignalNotify (void);





/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/**
 *  \brief This type defines Xbar input to select
 */
typedef enum
{
    CDD_ECAP_INPUT_INPUTXBAR1                           = 0,    //!GPIO Input Crossbar output signal-1
    CDD_ECAP_INPUT_INPUTXBAR2                           = 1,    //!GPIO Input Crossbar output signal-2
    CDD_ECAP_INPUT_INPUTXBAR3                           = 2,    //!GPIO Input Crossbar output signal-3
    CDD_ECAP_INPUT_INPUTXBAR4                           = 3,    //!GPIO Input Crossbar output signal-4
    CDD_ECAP_INPUT_INPUTXBAR5                           = 4,    //!GPIO Input Crossbar output signal-5
    CDD_ECAP_INPUT_INPUTXBAR6                           = 5,    //!GPIO Input Crossbar output signal-6
    CDD_ECAP_INPUT_INPUTXBAR7                           = 6,    //!GPIO Input Crossbar output signal-7
    CDD_ECAP_INPUT_INPUTXBAR8                           = 7,    //!GPIO Input Crossbar output signal-8
    CDD_ECAP_INPUT_INPUTXBAR9                           = 8,    //!GPIO Input Crossbar output signal-9
    CDD_ECAP_INPUT_INPUTXBAR10                          = 9,    //!GPIO Input Crossbar output signal-10
    CDD_ECAP_INPUT_INPUTXBAR11                          = 10,   //!GPIO Input Crossbar output signal-11
    CDD_ECAP_INPUT_INPUTXBAR12                          = 11,   //!GPIO Input Crossbar output signal-12
    CDD_ECAP_INPUT_INPUTXBAR13                          = 12,   //!GPIO Input Crossbar output signal-13
    CDD_ECAP_INPUT_INPUTXBAR14                          = 13,   //!GPIO Input Crossbar output signal-14
    CDD_ECAP_INPUT_INPUTXBAR15                          = 14,   //!GPIO Input Crossbar output signal-15
    CDD_ECAP_INPUT_INPUTXBAR16                          = 15,   //!GPIO Input Crossbar output signal-16
    CDD_ECAP_INPUT_ECAP1_CLB1_OUT14                     = 16,   //!CLB1 OUT14
    CDD_ECAP_INPUT_ECAP2_CLB1_OUT14                     = 16,   //!CLB1 OUT14
    CDD_ECAP_INPUT_ECAP1_CLB1_OUT15                     = 17,   //!CLB1 OUT15
    CDD_ECAP_INPUT_ECAP2_CLB1_OUT15                     = 17,   //!CLB1 OUT15
    CDD_ECAP_INPUT_ECAP3_CLB2_OUT14                     = 16,   //!CLB2 OUT14
    CDD_ECAP_INPUT_ECAP4_CLB2_OUT14                     = 16,   //!CLB2 OUT14
    CDD_ECAP_INPUT_ECAP5_CLB2_OUT14                     = 16,   //!CLB2 OUT14
    CDD_ECAP_INPUT_ECAP3_CLB2_OUT15                     = 17,   //!CLB2 OUT15
    CDD_ECAP_INPUT_ECAP4_CLB2_OUT15                     = 17,   //!CLB2 OUT15
    CDD_ECAP_INPUT_ECAP5_CLB2_OUT15                     = 17,   //!CLB2 OUT15
    CDD_ECAP_INPUT_ECAP6_CLB3_OUT14                     = 16,   //!CLB3 OUT14
    CDD_ECAP_INPUT_ECAP6_CLB3_OUT15                     = 17,   //!CLB3 OUT15
    CDD_ECAP_INPUT_ECAP6_CLB4_OUT14                     = 18,   //!CLB4 OUT14
    CDD_ECAP_INPUT_ECAP6_CLB4_OUT15                     = 19,   //!CLB4 OUT15
    CDD_ECAP_INPUT_ECAP1_CLB5_OUT14                     = 18,   //!CLB5 OUT14
    CDD_ECAP_INPUT_ECAP2_CLB5_OUT14                     = 18,   //!CLB5 OUT14
    CDD_ECAP_INPUT_ECAP1_CLB5_OUT15                     = 19,   //!CLB5 OUT15
    CDD_ECAP_INPUT_ECAP2_CLB5_OUT15                     = 19,   //!CLB5 OUT15
    CDD_ECAP_INPUT_ECAP3_CLB6_OUT14                     = 18,   //!CLB6 OUT14
    CDD_ECAP_INPUT_ECAP4_CLB6_OUT14                     = 18,   //!CLB6 OUT14
    CDD_ECAP_INPUT_ECAP5_CLB6_OUT14                     = 18,   //!CLB6 OUT14
    CDD_ECAP_INPUT_ECAP3_CLB6_OUT15                     = 19,   //!CLB6 OUT15
    CDD_ECAP_INPUT_ECAP4_CLB6_OUT15                     = 19,   //!CLB6 OUT15
    CDD_ECAP_INPUT_ECAP5_CLB6_OUT15                     = 19,   //!CLB6 OUT15
    CDD_ECAP_INPUT_OUTPUTXBAR1                          = 20,   //!Output Xbar Output-1
    CDD_ECAP_INPUT_OUTPUTXBAR2                          = 21,   //!Output Xbar Output-2
    CDD_ECAP_INPUT_OUTPUTXBAR3                          = 22,   //!Output Xbar Output-3
    CDD_ECAP_INPUT_OUTPUTXBAR4                          = 23,   //!Output Xbar Output-4
    CDD_ECAP_INPUT_OUTPUTXBAR5                          = 24,   //!Output Xbar Output-5
    CDD_ECAP_INPUT_OUTPUTXBAR6                          = 25,   //!Output Xbar Output-6
    CDD_ECAP_INPUT_OUTPUTXBAR7                          = 26,   //!Output Xbar Output-7
    CDD_ECAP_INPUT_OUTPUTXBAR8                          = 27,   //!Output Xbar Output-8
    CDD_ECAP_INPUT_ADC_E_EVENT4                         = 28,   //!ADCE Event4
    CDD_ECAP_INPUT_ADC_E_EVENT3                         = 29,   //!ADCE Event3
    CDD_ECAP_INPUT_ADC_E_EVENT2                         = 30,   //!ADCE Event2
    CDD_ECAP_INPUT_ADC_E_EVENT1                         = 31,   //!ADCE Event1
    CDD_ECAP_INPUT_ADC_D_EVENT4                         = 32,   //!ADCD Event4
    CDD_ECAP_INPUT_ADC_D_EVENT3                         = 33,   //!ADCD Event3
    CDD_ECAP_INPUT_ADC_D_EVENT2                         = 34,   //!ADCD Event2
    CDD_ECAP_INPUT_ADC_D_EVENT1                         = 35,   //!ADCD Event1
    CDD_ECAP_INPUT_ADC_C_EVENT4                         = 36,   //!ADCC Event4
    CDD_ECAP_INPUT_ADC_C_EVENT3                         = 37,   //!ADCC Event3
    CDD_ECAP_INPUT_ADC_C_EVENT2                         = 38,   //!ADCC Event2
    CDD_ECAP_INPUT_ADC_C_EVENT1                         = 39,   //!ADCC Event1
    CDD_ECAP_INPUT_ADC_B_EVENT4                         = 40,   //!ADCB Event4
    CDD_ECAP_INPUT_ADC_B_EVENT3                         = 41,   //!ADCB Event3
    CDD_ECAP_INPUT_ADC_B_EVENT2                         = 42,   //!ADCB Event2
    CDD_ECAP_INPUT_ADC_B_EVENT1                         = 43,   //!ADCB Event1
    CDD_ECAP_INPUT_ADC_A_EVENT4                         = 44,   //!ADCA Event4
    CDD_ECAP_INPUT_ADC_A_EVENT3                         = 45,   //!ADCA Event3
    CDD_ECAP_INPUT_ADC_A_EVENT2                         = 46,   //!ADCA Event2
    CDD_ECAP_INPUT_ADC_A_EVENT1                         = 47,   //!ADCA Event1
    CDD_ECAP_INPUT_FSIA_RX_MSR_LINE                     = 48,   //!FSIA Rx MSR Line
    CDD_ECAP_INPUT_FSIA_RX_MSR_LINE_RISE                = 49,   //!FSIA Rx MSR Line Rise
    CDD_ECAP_INPUT_FSIA_RX_MSR_LINE_FALL                = 50,   //!FSIA Rx MSR Line Fall
    CDD_ECAP_INPUT_FSIB_RX_MSR_LINE                     = 51,   //!FSIB Rx MSR Line
    CDD_ECAP_INPUT_FSIB_RX_MSR_LINE_RISE                = 52,   //!FSIB Rx MSR Line Rise
    CDD_ECAP_INPUT_FSIB_RX_MSR_LINE_FALL                = 53,   //!FSIB Rx MSR Line Fall
    CDD_ECAP_INPUT_FSIC_RX_MSR_LINE                     = 54,   //!FSIC Rx MSR Line
    CDD_ECAP_INPUT_FSIC_RX_MSR_LINE_RISE                = 55,   //!FSIC Rx MSR Line Rise
    CDD_ECAP_INPUT_FSIC_RX_MSR_LINE_FALL                = 56,   //!FSIC Rx MSR Line Fall
    CDD_ECAP_INPUT_FSID_RX_MSR_LINE                     = 57,   //!FSID Rx MSR Line
    CDD_ECAP_INPUT_FSID_RX_MSR_LINE_RISE                = 58,   //!FSID Rx MSR Line Rise
    CDD_ECAP_INPUT_FSID_RX_MSR_LINE_FALL                = 59,   //!FSID Rx MSR Line Fall
    CDD_ECAP_INPUT_SDFM2_FLT1_COMPARE_LOW               = 60,   //!SDFM-2 Filter-1 Compare Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT2_COMPARE_LOW               = 61,   //!SDFM-2 Filter-2 Compare Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT3_COMPARE_LOW               = 62,   //!SDFM-2 Filter-3 Compare Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT4_COMPARE_LOW               = 63,   //!SDFM-2 Filter-4 Compare Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT1_COMPARE_LOW               = 64,   //!SDFM-1 Filter-1 Compare Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT2_COMPARE_LOW               = 65,   //!SDFM-1 Filter-2 Compare Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT3_COMPARE_LOW               = 66,   //!SDFM-1 Filter-3 Compare Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT4_COMPARE_LOW               = 67,   //!SDFM-1 Filter-4 Compare Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT1_COMPARE_Z                 = 68,   //!SDFM-2 Filter-1 Compare Z Trip
    CDD_ECAP_INPUT_SDFM2_FLT2_COMPARE_Z                 = 69,   //!SDFM-2 Filter-2 Compare Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT3_COMPARE_Z                 = 70,   //!SDFM-2 Filter-3 Compare Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT4_COMPARE_Z                 = 71,   //!SDFM-2 Filter-4 Compare Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT1_COMPARE_Z                 = 72,   //!SDFM-1 Filter-1 Compare Z Trip
    CDD_ECAP_INPUT_SDFM1_FLT2_COMPARE_Z                 = 73,   //!SDFM-1 Filter-2 Compare Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT3_COMPARE_Z                 = 74,   //!SDFM-1 Filter-3 Compare Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT4_COMPARE_Z                 = 75,   //!SDFM-1 Filter-4 Compare Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT1_COMPARE_HIGH              = 76,   //!SDFM-2 Filter-1 Compare High Trip
    CDD_ECAP_INPUT_SDFM2_FLT2_COMPARE_HIGH              = 77,   //!SDFM-2 Filter-2 Compare High Trip
    CDD_ECAP_INPUT_SDFM2_FLT3_COMPARE_HIGH              = 78,   //!SDFM-2 Filter-3 Compare High Trip
    CDD_ECAP_INPUT_SDFM2_FLT4_COMPARE_HIGH              = 79,   //!SDFM-2 Filter-4 Compare High Trip
    CDD_ECAP_INPUT_SDFM1_FLT1_COMPARE_HIGH              = 80,   //!SDFM-1 Filter-1 Compare High Trip
    CDD_ECAP_INPUT_SDFM1_FLT2_COMPARE_HIGH              = 81,   //!SDFM-1 Filter-2 Compare High Trip
    CDD_ECAP_INPUT_SDFM1_FLT3_COMPARE_HIGH              = 82,   //!SDFM-1 Filter-3 Compare High Trip
    CDD_ECAP_INPUT_SDFM1_FLT4_COMPARE_HIGH              = 83,   //!SDFM-1 Filter-4 Compare High Trip
    CDD_ECAP_INPUT_SDFM2_FLT1_COMPARE_HIGH_OR_LOW       = 84,   //!SDFM-2 Filter-1 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT2_COMPARE_HIGH_OR_LOW       = 85,   //!SDFM-2 Filter-2 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT3_COMPARE_HIGH_OR_LOW       = 86,   //!SDFM-2 Filter-3 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM2_FLT4_COMPARE_HIGH_OR_LOW       = 87,   //!SDFM-2 Filter-4 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT1_COMPARE_HIGH_OR_LOW       = 88,   //!SDFM-1 Filter-1 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT2_COMPARE_HIGH_OR_LOW       = 89,   //!SDFM-1 Filter-2 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT3_COMPARE_HIGH_OR_LOW       = 90,   //!SDFM-1 Filter-3 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM1_FLT4_COMPARE_HIGH_OR_LOW       = 91,   //!SDFM-1 Filter-4 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_ECAP5_ECAP6_DELAY_CLK                = 92,   //!Delay clock for measurement
    CDD_ECAP_INPUT_ECAP6_ECAP5_DELAY_CLK                = 93,   //!Delay clock for measurement
    CDD_ECAP_INPUT_ECATSYNC0                            = 94,   //!Ethercat Sync0
    CDD_ECAP_INPUT_ECATSYNC1                            = 95,   //!Ethercat Sync1
    CDD_ECAP_INPUT_CMPSS1_CTRIP_LOW                     = 96,   //!Compare Subsystem-1 Low Trip
    CDD_ECAP_INPUT_CMPSS2_CTRIP_LOW                     = 97,   //!Compare Subsystem-2 Low Trip
    CDD_ECAP_INPUT_CMPSS3_CTRIP_LOW                     = 98,   //!Compare Subsystem-3 Low Trip
    CDD_ECAP_INPUT_CMPSS4_CTRIP_LOW                     = 99,   //!Compare Subsystem-4 Low Trip
    CDD_ECAP_INPUT_CMPSS5_CTRIP_LOW                     = 100,  //!Compare Subsystem-5 Low Trip
    CDD_ECAP_INPUT_CMPSS6_CTRIP_LOW                     = 101,  //!Compare Subsystem-6 Low Trip
    CDD_ECAP_INPUT_CMPSS7_CTRIP_LOW                     = 102,  //!Compare Subsystem-7 Low Trip
    CDD_ECAP_INPUT_CMPSS8_CTRIP_LOW                     = 103,  //!Compare Subsystem-8 Low Trip
    CDD_ECAP_INPUT_CMPSS1_CTRIP_HIGH                    = 107,  //!Compare Subsystem-1 High Trip
    CDD_ECAP_INPUT_CMPSS2_CTRIP_HIGH                    = 108,  //!Compare Subsystem-2 High Trip
    CDD_ECAP_INPUT_CMPSS3_CTRIP_HIGH                    = 109,  //!Compare Subsystem-3 High Trip
    CDD_ECAP_INPUT_CMPSS4_CTRIP_HIGH                    = 110,  //!Compare Subsystem-4 High Trip
    CDD_ECAP_INPUT_CMPSS5_CTRIP_HIGH                    = 111,  //!Compare Subsystem-5 High Trip
    CDD_ECAP_INPUT_CMPSS6_CTRIP_HIGH                    = 112,  //!Compare Subsystem-6 High Trip
    CDD_ECAP_INPUT_CMPSS7_CTRIP_HIGH                    = 113,  //!Compare Subsystem-7 High Trip
    CDD_ECAP_INPUT_CMPSS8_CTRIP_HIGH                    = 114,  //!Compare Subsystem-8 High Trip
    CDD_ECAP_INPUT_GPIO8                                = 115,  //!GPIO8
    CDD_ECAP_INPUT_GPIO9                                = 116,  //!GPIO9
    CDD_ECAP_INPUT_GPIO22                               = 117,  //!GPIO22
    CDD_ECAP_INPUT_GPIO23                               = 118,  //!GPIO23
    CDD_ECAP_INPUT_CMPSS1_CTRIP_HIGH_OR_LOW             = 119,  //!Compare Subsystem-1 High Trip or Low Trip
    CDD_ECAP_INPUT_CMPSS2_CTRIP_HIGH_OR_LOW             = 120,  //!Compare Subsystem-1 High Trip or Low Trip
    CDD_ECAP_INPUT_CMPSS3_CTRIP_HIGH_OR_LOW             = 121,  //!Compare Subsystem-2 High Trip or Low Trip
    CDD_ECAP_INPUT_CMPSS4_CTRIP_HIGH_OR_LOW             = 122,  //!Compare Subsystem-3 High Trip or Low Trip
    CDD_ECAP_INPUT_CMPSS5_CTRIP_HIGH_OR_LOW             = 123,  //!Compare Subsystem-4 High Trip or Low Trip
    CDD_ECAP_INPUT_CMPSS6_CTRIP_HIGH_OR_LOW             = 124,  //!Compare Subsystem-5 High Trip or Low Trip
    CDD_ECAP_INPUT_CMPSS7_CTRIP_HIGH_OR_LOW             = 125,  //!Compare Subsystem-6 High Trip or Low Trip
    CDD_ECAP_INPUT_CMPSS8_CTRIP_HIGH_OR_LOW             = 126,  //!Compare Subsystem-7 High Trip or Low Trip
    CDD_ECAP_INPUT_ECAP1_INPUTXBAR7                     = 127,  //!GPIO Input Crossbar output signal-7
    CDD_ECAP_INPUT_ECAP2_INPUTXBAR8                     = 127,  //!GPIO Input Crossbar output signal-8
    CDD_ECAP_INPUT_ECAP3_INPUTXBAR9                     = 127,  //!GPIO Input Crossbar output signal-9
    CDD_ECAP_INPUT_ECAP4_INPUTXBAR10                    = 127,  //!GPIO Input Crossbar output signal-10
    CDD_ECAP_INPUT_ECAP5_INPUTXBAR11                    = 127,  //!GPIO Input Crossbar output signal-11
    CDD_ECAP_INPUT_ECAP6_INPUTXBAR12                    = 127,  //!GPIO Input Crossbar output signal-12
    CDD_ECAP_INPUT_SDFM4_FLT1_COMPARE_LOW               = 128,  //!SDFM-4 Filter-1 Compare Low Trip
    CDD_ECAP_INPUT_SDFM4_FLT2_COMPARE_LOW               = 129,  //!SDFM-4 Filter-2 Compare Low Trip
    CDD_ECAP_INPUT_SDFM4_FLT3_COMPARE_LOW               = 130,  //!SDFM-4 Filter-3 Compare Low Trip
    CDD_ECAP_INPUT_SDFM4_FLT4_COMPARE_LOW               = 131,  //!SDFM-4 Filter-4 Compare Low Trip
    CDD_ECAP_INPUT_SDFM3_FLT1_COMPARE_LOW               = 132,  //!SDFM-3 Filter-1 Compare Low Trip
    CDD_ECAP_INPUT_SDFM3_FLT2_COMPARE_LOW               = 133,  //!SDFM-3 Filter-2 Compare Low Trip
    CDD_ECAP_INPUT_SDFM3_FLT3_COMPARE_LOW               = 134,  //!SDFM-3 Filter-3 Compare Low Trip
    CDD_ECAP_INPUT_SDFM3_FLT4_COMPARE_LOW               = 135,  //!SDFM-3 Filter-4 Compare Low Trip
    CDD_ECAP_INPUT_SDFM4_FLT4_COMPARE_Z                 = 139,  //!SDFM-4 Filter-4 Compare Z Trip
    CDD_ECAP_INPUT_SDFM3_FLT4_COMPARE_Z                 = 143,  //!SDFM-3 Filter-4 Compare Z Trip
    CDD_ECAP_INPUT_SDFM4_FLT1_COMPARE_HIGH              = 144,  //!SDFM-4 Filter-1 Compare High Trip
    CDD_ECAP_INPUT_SDFM4_FLT2_COMPARE_HIGH              = 145,  //!SDFM-4 Filter-2 Compare High Trip
    CDD_ECAP_INPUT_SDFM4_FLT3_COMPARE_HIGH              = 146,  //!SDFM-4 Filter-3 Compare High Trip
    CDD_ECAP_INPUT_SDFM4_FLT4_COMPARE_HIGH              = 147,  //!SDFM-4 Filter-4 Compare High Trip
    CDD_ECAP_INPUT_SDFM3_FLT1_COMPARE_HIGH              = 148,  //!SDFM-3 Filter-1 Compare High Trip
    CDD_ECAP_INPUT_SDFM3_FLT2_COMPARE_HIGH              = 149,  //!SDFM-3 Filter-2 Compare High Trip
    CDD_ECAP_INPUT_SDFM3_FLT3_COMPARE_HIGH              = 150,  //!SDFM-3 Filter-3 Compare High Trip
    CDD_ECAP_INPUT_SDFM3_FLT4_COMPARE_HIGH              = 151,  //!SDFM-3 Filter-4 Compare High Trip
    CDD_ECAP_INPUT_SDFM4_FLT1_COMPARE_HIGH_OR_LOW       = 152,  //!SDFM-4 Filter-1 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM4_FLT2_COMPARE_HIGH_OR_LOW       = 153,  //!SDFM-4 Filter-2 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM4_FLT3_COMPARE_HIGH_OR_LOW       = 154,  //!SDFM-4 Filter-3 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM4_FLT4_COMPARE_HIGH_OR_LOW       = 155,  //!SDFM-4 Filter-4 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM3_FLT1_COMPARE_HIGH_OR_LOW       = 156,  //!SDFM-3 Filter-1 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM3_FLT2_COMPARE_HIGH_OR_LOW       = 157,  //!SDFM-3 Filter-2 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM3_FLT3_COMPARE_HIGH_OR_LOW       = 158,  //!SDFM-3 Filter-3 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_SDFM3_FLT4_COMPARE_HIGH_OR_LOW       = 159,  //!SDFM-3 Filter-4 Compare High Trip or Low Trip
    CDD_ECAP_INPUT_EPWM18_DEL_ACTIVE                    = 160,  //!EPWM-18 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM17_DEL_ACTIVE                    = 161,  //!EPWM-17 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM16_DEL_ACTIVE                    = 162,  //!EPWM-16 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM15_DEL_ACTIVE                    = 163,  //!EPWM-15 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM14_DEL_ACTIVE                    = 164,  //!EPWM-14 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM13_DEL_ACTIVE                    = 165,  //!EPWM-13 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM12_DEL_ACTIVE                    = 166,  //!EPWM-12 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM11_DEL_ACTIVE                    = 167,  //!EPWM-11 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM10_DEL_ACTIVE                    = 168,  //!EPWM-10 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM9_DEL_ACTIVE                     = 169,  //!EPWM-9 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM8_DEL_ACTIVE                     = 170,  //!EPWM-8 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM7_DEL_ACTIVE                     = 171,  //!EPWM-7 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM6_DEL_ACTIVE                     = 172,  //!EPWM-6 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM5_DEL_ACTIVE                     = 173,  //!EPWM-5 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM4_DEL_ACTIVE                     = 174,  //!EPWM-4 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM3_DEL_ACTIVE                     = 175,  //!EPWM-3 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM2_DEL_ACTIVE                     = 176,  //!EPWM-2 Diode Emulation Logic Active
    CDD_ECAP_INPUT_EPWM1_DEL_ACTIVE                     = 177,  //!EPWM-1 Diode Emulation Logic Active
    CDD_ECAP_INPUT_GPIO11                               = 251,  //!GPIO11
    CDD_ECAP_INPUT_GPIO12                               = 252,  //!GPIO12
    CDD_ECAP_INPUT_GPIO13                               = 253,  //!GPIO13
    CDD_ECAP_INPUT_GPIO14                               = 254,  //!GPIO14
    CDD_ECAP_INPUT_ECAP1_EPG1_DATAOUT49                 = 255,  //!EPG-1 Data Output-49 Connection
    CDD_ECAP_INPUT_ECAP2_EPG1_DATAOUT50                 = 255,  //!EPG-1 Data Output-50 Connection
    CDD_ECAP_INPUT_ECAP3_EPG1_DATAOUT51                 = 255,  //!EPG-1 Data Output-51 Connection
    CDD_ECAP_INPUT_ECAP4_EPG1_DATAOUT52                 = 255,  //!EPG-1 Data Output-52 Connection
    CDD_ECAP_INPUT_ECAP5_EPG1_DATAOUT53                 = 255,  //!EPG-1 Data Output-53 Connection
    CDD_ECAP_INPUT_ECAP6_EPG1_DATAOUT54                 = 255   //!EPG-1 Data Output-54 Connection
} Cdd_Ecap_InputSelect;
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern const struct Cdd_Ecap_ConfigTag Cdd_Ecap_Config;


/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/


/**
 *  \brief Pre Compile config macro name.
 */

#define CDD_ECAP_INIT_CONFIG_PC       Cdd_Ecap_Config



/**
*  \brief Channel ID
*  Symbolic Names Configured channel ID(s)
*/

#define CddEcapConf_CddEcapChannel_CddEcapChannel_0          ((uint8)0U) /*~ASR~*/
/**\brief Channel identifiers */

#define CddEcapConf_CddEcapChannel_CddEcapChannel_1          ((uint8)1U) /*~ASR~*/
/**\brief Channel identifiers */

#define CddEcapConf_CddEcapChannel_CddEcapChannel_2          ((uint8)2U) /*~ASR~*/
/**\brief Channel identifiers */

#define CddEcapConf_CddEcapChannel_CddEcapChannel_3          ((uint8)3U) /*~ASR~*/
/**\brief Channel identifiers */


/*
 * CDD ECAP channels available for user
 */


/** \brief ECAP Channel 0, in MAIN DOMAIN */
#define CDD_ECAP_CHANNEL0               (0U)


/** \brief ECAP Channel 1, in MAIN DOMAIN */
#define CDD_ECAP_CHANNEL1               (1U)


/** \brief ECAP Channel 2, in MAIN DOMAIN */
#define CDD_ECAP_CHANNEL2               (2U)


/** \brief ECAP Channel 3, in MAIN DOMAIN */
#define CDD_ECAP_CHANNEL3               (3U)





#define CDD_ECAP_CHANNEL0_INT_ENABLE

#define CDD_ECAP_CHANNEL0_INT_ISR_CAT1_INT



#define CDD_ECAP_CHANNEL1_INT_ENABLE

#define CDD_ECAP_CHANNEL1_INT_ISR_CAT1_INT



#define CDD_ECAP_CHANNEL2_INT_ENABLE

#define CDD_ECAP_CHANNEL2_INT_ISR_CAT1_INT



#define CDD_ECAP_CHANNEL3_INT_ENABLE

#define CDD_ECAP_CHANNEL3_INT_ISR_CAT1_INT



/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_ECAP_CFG_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Cfg.h
 *********************************************************************************************************************/
