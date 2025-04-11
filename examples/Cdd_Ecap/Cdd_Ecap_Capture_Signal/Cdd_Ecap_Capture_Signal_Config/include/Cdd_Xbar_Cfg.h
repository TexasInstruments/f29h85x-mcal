/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 TEXAS INSTRUMENTS INCORPORATED PROPRIETARY INFORMATION
 *
 *                 Property of Texas Instruments, Unauthorized reproduction and/or distribution
 *                 is strictly prohibited. This product is protected under copyright law and
 *                 trade secret law as an unpublished work.
 *                 (C) Copyright 2025 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:         Cdd_Xbar_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data        
 *********************************************************************************************************************/
#ifndef CDD_XBAR_CFG_H
#define CDD_XBAR_CFG_H

/** \addtogroup CDD_XBAR
 *  @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/


/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/** \brief CDD XBar configuration Major Version */
#define CDD_XBAR_CFG_MAJOR_VERSION                (2U)
/** \brief CDD XBar configuration Minor Version */
#define CDD_XBAR_CFG_MINOR_VERSION                (0U)
/** \brief CDD XBar configuration Patch Version */
#define CDD_XBAR_CFG_PATCH_VERSION                (0U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/** \brief CDD XBar development error detection */
#define CDD_XBAR_DEV_ERROR_DETECT                 STD_OFF
/** \brief Switches the CDD XBAR functions ON or OFF */
#define CDD_XBAR_API_ENABLE                       STD_ON
/** \brief Switches the Cdd_Xbar_GetVersionInfo function ON or OFF */
#define CDD_XBAR_GET_VERSION_INFO_API             STD_ON
/** \brief Switches Cdd_Xbar_InputFlagStatus() and Cdd_Xbar_InputFlagClear() ON or OFF */
#define CDD_XBAR_INPUT_FLAG_API                   STD_ON
/** \brief  Number of Input crossbar instances configured */
#define CDD_XBAR_INPUT_XBAR_CONFIGURATIONS        1U

/** \brief Number of Output crossbar instances configured */
#define CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS       0U

/** \brief Number of EPWM crossbar instances configured */
#define CDD_XBAR_EPWM_XBAR_CONFIGURATIONS         0U

/** \brief Number of CLB crossbar instances configured */
#define CDD_XBAR_CLB_XBAR_CONFIGURATIONS          0U

/** \brief Number of MinDB crossbar instances configured */
#define CDD_XBAR_MINDB_XBAR_CONFIGURATIONS        0U

/** \brief Number of ICL crossbar instances configured */
#define CDD_XBAR_ICL_XBAR_CONFIGURATIONS          0U
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/** \brief Number of input crossbar output lines */
#define CDD_XBAR_INPUT_SELECT_COUNT               64U

/** \brief Number of output crossbar output lines */
#define CDD_XBAR_OUTPUT_XBAR_OUTPUT_COUNT         16U

/** \brief Number of EPWM crossbar output lines */
#define CDD_XBAR_EPWM_XBAR_OUTPUT_COUNT           16U

/** \brief Number of CLB crossbar output lines */
#define CDD_XBAR_CLB_XBAR_OUTPUT_COUNT            8U

/** \brief Number of MinDB crossbar output lines */
#define CDD_XBAR_MINDB_XBAR_OUTPUT_COUNT          16U

/** \brief Number of ICL crossbar output lines */
#define CDD_XBAR_ICL_XBAR_OUTPUT_COUNT            16U

/** \brief Switches the pre compile variant ON or OFF */
#define CDD_XBAR_PRE_COMPILE_VARIANT              STD_ON
/** \brief Pre compile variant configuration */
#define CDD_XBAR_PRE_COMPILE_VARIANT_CONFIG       Cdd_Xbar_Configuration

/** \brief Number of output crossbar input groups */
#define CDD_XBAR_OUTPUT_XBAR_MAX_GROUP            10U

/** \brief Number of EPWM crossbar input groups */
#define CDD_XBAR_EPWM_XBAR_MAX_GROUP              10U

/** \brief Number of CLB crossbar input groups */
#define CDD_XBAR_CLB_XBAR_MAX_GROUP               8U

/** \brief Number of MINDB crossbar input groups */
#define CDD_XBAR_MINDB_XBAR_MAX_GROUP             3U

/** \brief Number of ICL crossbar input groups */
#define CDD_XBAR_ICL_XBAR_MAX_GROUP               3U

/** \brief Number of input lines in each group in a crossbar */
#define CDD_XBAR_MAX_INPUT_LINES                  32U

#ifndef DOXYGEN_SHOULD_SKIP_THIS




#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/* Design: MCAL-25813 */
/** \brief CDD Xbar input Xbar output Type */
#define CDD_XBAR_INPUT1                     1U   /*!< \brief INPUT1 of the Input X-BAR */
#define CDD_XBAR_INPUT2                     2U   /*!< \brief INPUT2 of the Input X-BAR */
#define CDD_XBAR_INPUT3                     3U   /*!< \brief INPUT3 of the Input X-BAR */
#define CDD_XBAR_INPUT4                     4U   /*!< \brief INPUT4 of the Input X-BAR */
#define CDD_XBAR_INPUT5                     5U   /*!< \brief INPUT5 of the Input X-BAR */
#define CDD_XBAR_INPUT6                     6U   /*!< \brief INPUT6 of the Input X-BAR */
#define CDD_XBAR_INPUT7                     7U   /*!< \brief INPUT7 of the Input X-BAR */
#define CDD_XBAR_INPUT8                     8U   /*!< \brief INPUT8 of the Input X-BAR */
#define CDD_XBAR_INPUT9                     9U   /*!< \brief INPUT9 of the Input X-BAR */
#define CDD_XBAR_INPUT10                     10U   /*!< \brief INPUT10 of the Input X-BAR */
#define CDD_XBAR_INPUT11                     11U   /*!< \brief INPUT11 of the Input X-BAR */
#define CDD_XBAR_INPUT12                     12U   /*!< \brief INPUT12 of the Input X-BAR */
#define CDD_XBAR_INPUT13                     13U   /*!< \brief INPUT13 of the Input X-BAR */
#define CDD_XBAR_INPUT14                     14U   /*!< \brief INPUT14 of the Input X-BAR */
#define CDD_XBAR_INPUT15                     15U   /*!< \brief INPUT15 of the Input X-BAR */
#define CDD_XBAR_INPUT16                     16U   /*!< \brief INPUT16 of the Input X-BAR */
#define CDD_XBAR_INPUT17                     17U   /*!< \brief INPUT17 of the Input X-BAR */
#define CDD_XBAR_INPUT18                     18U   /*!< \brief INPUT18 of the Input X-BAR */
#define CDD_XBAR_INPUT19                     19U   /*!< \brief INPUT19 of the Input X-BAR */
#define CDD_XBAR_INPUT20                     20U   /*!< \brief INPUT20 of the Input X-BAR */
#define CDD_XBAR_INPUT21                     21U   /*!< \brief INPUT21 of the Input X-BAR */
#define CDD_XBAR_INPUT22                     22U   /*!< \brief INPUT22 of the Input X-BAR */
#define CDD_XBAR_INPUT23                     23U   /*!< \brief INPUT23 of the Input X-BAR */
#define CDD_XBAR_INPUT24                     24U   /*!< \brief INPUT24 of the Input X-BAR */
#define CDD_XBAR_INPUT25                     25U   /*!< \brief INPUT25 of the Input X-BAR */
#define CDD_XBAR_INPUT26                     26U   /*!< \brief INPUT26 of the Input X-BAR */
#define CDD_XBAR_INPUT27                     27U   /*!< \brief INPUT27 of the Input X-BAR */
#define CDD_XBAR_INPUT28                     28U   /*!< \brief INPUT28 of the Input X-BAR */
#define CDD_XBAR_INPUT29                     29U   /*!< \brief INPUT29 of the Input X-BAR */
#define CDD_XBAR_INPUT30                     30U   /*!< \brief INPUT30 of the Input X-BAR */
#define CDD_XBAR_INPUT31                     31U   /*!< \brief INPUT31 of the Input X-BAR */
#define CDD_XBAR_INPUT32                     32U   /*!< \brief INPUT32 of the Input X-BAR */
#define CDD_XBAR_INPUT33                     33U   /*!< \brief INPUT33 of the Input X-BAR */
#define CDD_XBAR_INPUT34                     34U   /*!< \brief INPUT34 of the Input X-BAR */
#define CDD_XBAR_INPUT35                     35U   /*!< \brief INPUT35 of the Input X-BAR */
#define CDD_XBAR_INPUT36                     36U   /*!< \brief INPUT36 of the Input X-BAR */
#define CDD_XBAR_INPUT37                     37U   /*!< \brief INPUT37 of the Input X-BAR */
#define CDD_XBAR_INPUT38                     38U   /*!< \brief INPUT38 of the Input X-BAR */
#define CDD_XBAR_INPUT39                     39U   /*!< \brief INPUT39 of the Input X-BAR */
#define CDD_XBAR_INPUT40                     40U   /*!< \brief INPUT40 of the Input X-BAR */
#define CDD_XBAR_INPUT41                     41U   /*!< \brief INPUT41 of the Input X-BAR */
#define CDD_XBAR_INPUT42                     42U   /*!< \brief INPUT42 of the Input X-BAR */
#define CDD_XBAR_INPUT43                     43U   /*!< \brief INPUT43 of the Input X-BAR */
#define CDD_XBAR_INPUT44                     44U   /*!< \brief INPUT44 of the Input X-BAR */
#define CDD_XBAR_INPUT45                     45U   /*!< \brief INPUT45 of the Input X-BAR */
#define CDD_XBAR_INPUT46                     46U   /*!< \brief INPUT46 of the Input X-BAR */
#define CDD_XBAR_INPUT47                     47U   /*!< \brief INPUT47 of the Input X-BAR */
#define CDD_XBAR_INPUT48                     48U   /*!< \brief INPUT48 of the Input X-BAR */
#define CDD_XBAR_INPUT49                     49U   /*!< \brief INPUT49 of the Input X-BAR */
#define CDD_XBAR_INPUT50                     50U   /*!< \brief INPUT50 of the Input X-BAR */
#define CDD_XBAR_INPUT51                     51U   /*!< \brief INPUT51 of the Input X-BAR */
#define CDD_XBAR_INPUT52                     52U   /*!< \brief INPUT52 of the Input X-BAR */
#define CDD_XBAR_INPUT53                     53U   /*!< \brief INPUT53 of the Input X-BAR */
#define CDD_XBAR_INPUT54                     54U   /*!< \brief INPUT54 of the Input X-BAR */
#define CDD_XBAR_INPUT55                     55U   /*!< \brief INPUT55 of the Input X-BAR */
#define CDD_XBAR_INPUT56                     56U   /*!< \brief INPUT56 of the Input X-BAR */
#define CDD_XBAR_INPUT57                     57U   /*!< \brief INPUT57 of the Input X-BAR */
#define CDD_XBAR_INPUT58                     58U   /*!< \brief INPUT58 of the Input X-BAR */
#define CDD_XBAR_INPUT59                     59U   /*!< \brief INPUT59 of the Input X-BAR */
#define CDD_XBAR_INPUT60                     60U   /*!< \brief INPUT60 of the Input X-BAR */
#define CDD_XBAR_INPUT61                     61U   /*!< \brief INPUT61 of the Input X-BAR */
#define CDD_XBAR_INPUT62                     62U   /*!< \brief INPUT62 of the Input X-BAR */
#define CDD_XBAR_INPUT63                     63U   /*!< \brief INPUT63 of the Input X-BAR */
#define CDD_XBAR_INPUT64                     64U   /*!< \brief INPUT64 of the Input X-BAR */

/** \brief Output crossbar output type */
#define CDD_XBAR_OUTPUT1                    1U   /*!< \brief OUTPUT1 of the Output X-BAR */
#define CDD_XBAR_OUTPUT2                    2U   /*!< \brief OUTPUT2 of the Output X-BAR */
#define CDD_XBAR_OUTPUT3                    3U   /*!< \brief OUTPUT3 of the Output X-BAR */
#define CDD_XBAR_OUTPUT4                    4U   /*!< \brief OUTPUT4 of the Output X-BAR */
#define CDD_XBAR_OUTPUT5                    5U   /*!< \brief OUTPUT5 of the Output X-BAR */
#define CDD_XBAR_OUTPUT6                    6U   /*!< \brief OUTPUT6 of the Output X-BAR */
#define CDD_XBAR_OUTPUT7                    7U   /*!< \brief OUTPUT7 of the Output X-BAR */
#define CDD_XBAR_OUTPUT8                    8U   /*!< \brief OUTPUT8 of the Output X-BAR */
#define CDD_XBAR_OUTPUT9                    9U   /*!< \brief OUTPUT9 of the Output X-BAR */
#define CDD_XBAR_OUTPUT10                    10U   /*!< \brief OUTPUT10 of the Output X-BAR */
#define CDD_XBAR_OUTPUT11                    11U   /*!< \brief OUTPUT11 of the Output X-BAR */
#define CDD_XBAR_OUTPUT12                    12U   /*!< \brief OUTPUT12 of the Output X-BAR */
#define CDD_XBAR_OUTPUT13                    13U   /*!< \brief OUTPUT13 of the Output X-BAR */
#define CDD_XBAR_OUTPUT14                    14U   /*!< \brief OUTPUT14 of the Output X-BAR */
#define CDD_XBAR_OUTPUT15                    15U   /*!< \brief OUTPUT15 of the Output X-BAR */
#define CDD_XBAR_OUTPUT16                    16U   /*!< \brief OUTPUT16 of the Output X-BAR */

/** \brief EPWM crossbar output type */
#define CDD_XBAR_TRIP1                  1U   /*!< \brief TRIP1 of the EPWM X-BAR */
#define CDD_XBAR_TRIP2                  2U   /*!< \brief TRIP2 of the EPWM X-BAR */
#define CDD_XBAR_TRIP3                  3U   /*!< \brief TRIP3 of the EPWM X-BAR */
#define CDD_XBAR_TRIP4                  4U   /*!< \brief TRIP4 of the EPWM X-BAR */
#define CDD_XBAR_TRIP5                  5U   /*!< \brief TRIP5 of the EPWM X-BAR */
#define CDD_XBAR_TRIP6                  6U   /*!< \brief TRIP6 of the EPWM X-BAR */
#define CDD_XBAR_TRIP7                  7U   /*!< \brief TRIP7 of the EPWM X-BAR */
#define CDD_XBAR_TRIP8                  8U   /*!< \brief TRIP8 of the EPWM X-BAR */
#define CDD_XBAR_TRIP9                  9U   /*!< \brief TRIP9 of the EPWM X-BAR */
#define CDD_XBAR_TRIP10                  10U   /*!< \brief TRIP10 of the EPWM X-BAR */
#define CDD_XBAR_TRIP11                  11U   /*!< \brief TRIP11 of the EPWM X-BAR */
#define CDD_XBAR_TRIP12                  12U   /*!< \brief TRIP12 of the EPWM X-BAR */
#define CDD_XBAR_TRIP13                  13U   /*!< \brief TRIP13 of the EPWM X-BAR */
#define CDD_XBAR_TRIP14                  14U   /*!< \brief TRIP14 of the EPWM X-BAR */
#define CDD_XBAR_TRIP15                  15U   /*!< \brief TRIP15 of the EPWM X-BAR */
#define CDD_XBAR_TRIP16                  16U   /*!< \brief TRIP16 of the EPWM X-BAR */

/** \brief MINDB crossbar output type */
#define CDD_XBAR_MINDBXBAR1                 1U   /*!< \brief MINDBXBAR1 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR2                 2U   /*!< \brief MINDBXBAR2 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR3                 3U   /*!< \brief MINDBXBAR3 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR4                 4U   /*!< \brief MINDBXBAR4 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR5                 5U   /*!< \brief MINDBXBAR5 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR6                 6U   /*!< \brief MINDBXBAR6 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR7                 7U   /*!< \brief MINDBXBAR7 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR8                 8U   /*!< \brief MINDBXBAR8 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR9                 9U   /*!< \brief MINDBXBAR9 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR10                 10U   /*!< \brief MINDBXBAR10 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR11                 11U   /*!< \brief MINDBXBAR11 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR12                 12U   /*!< \brief MINDBXBAR12 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR13                 13U   /*!< \brief MINDBXBAR13 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR14                 14U   /*!< \brief MINDBXBAR14 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR15                 15U   /*!< \brief MINDBXBAR15 of the MINDB X-BAR */
#define CDD_XBAR_MINDBXBAR16                 16U   /*!< \brief MINDBXBAR16 of the MINDB X-BAR */

/** \brief ICL crossbar output type */
#define CDD_XBAR_ICLXBAR1                   1U   /*!< \brief ICLXBAR1 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR2                   2U   /*!< \brief ICLXBAR2 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR3                   3U   /*!< \brief ICLXBAR3 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR4                   4U   /*!< \brief ICLXBAR4 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR5                   5U   /*!< \brief ICLXBAR5 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR6                   6U   /*!< \brief ICLXBAR6 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR7                   7U   /*!< \brief ICLXBAR7 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR8                   8U   /*!< \brief ICLXBAR8 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR9                   9U   /*!< \brief ICLXBAR9 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR10                   10U   /*!< \brief ICLXBAR10 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR11                   11U   /*!< \brief ICLXBAR11 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR12                   12U   /*!< \brief ICLXBAR12 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR13                   13U   /*!< \brief ICLXBAR13 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR14                   14U   /*!< \brief ICLXBAR14 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR15                   15U   /*!< \brief ICLXBAR15 of the ICL X-BAR */
#define CDD_XBAR_ICLXBAR16                   16U   /*!< \brief ICLXBAR16 of the ICL X-BAR */

/** \brief CLB crossbar output type */
#define CDD_XBAR_AUXSIG1                   1U   /*!< \brief AUXSIG1 of the CLB X-BAR */
#define CDD_XBAR_AUXSIG2                   2U   /*!< \brief AUXSIG2 of the CLB X-BAR */
#define CDD_XBAR_AUXSIG3                   3U   /*!< \brief AUXSIG3 of the CLB X-BAR */
#define CDD_XBAR_AUXSIG4                   4U   /*!< \brief AUXSIG4 of the CLB X-BAR */
#define CDD_XBAR_AUXSIG5                   5U   /*!< \brief AUXSIG5 of the CLB X-BAR */
#define CDD_XBAR_AUXSIG6                   6U   /*!< \brief AUXSIG6 of the CLB X-BAR */
#define CDD_XBAR_AUXSIG7                   7U   /*!< \brief AUXSIG7 of the CLB X-BAR */
#define CDD_XBAR_AUXSIG8                   8U   /*!< \brief AUXSIG8 of the CLB X-BAR */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/* Design: MCAL-25820 */
/** \brief Symbolic name for CddXbarInputXbarInstanceConfig_0 */
#define CddXbarConf_CddXbarInputXbarInstanceConfig_CddXbarInputXbarInstanceConfig_0      0x0000			/*~ASR~*/
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/* Design: MCAL-25820 */
/** \brief Symbolic name for InputXbar */
#define CddXbarConf_CddXbarInputXbar				0U    /*~ASR~*/
/** \brief Symbolic name for OutputXbar */
#define CddXbarConf_CddXbarOutputXbar				1U    /*~ASR~*/
/** \brief Symbolic name for EpwmXbar */
#define CddXbarConf_CddXbarEpwmXbar				2U    /*~ASR~*/
/** \brief Symbolic name for ClbXbar */
#define CddXbarConf_CddXbarClbXbar				3U    /*~ASR~*/
/** \brief Symbolic name for MindbXbar */
#define CddXbarConf_CddXbarMindbXbar				4U    /*~ASR~*/
/** \brief Symbolic name for IclXbar */
#define CddXbarConf_CddXbarIclXbar				5U    /*~ASR~*/
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Type for symbolic name of CDD XBAR instances. */
typedef uint16 Cdd_Xbar_Type;

/** \brief These are the possible levels an output crossbar output can have. */
typedef uint8 Cdd_Xbar_OutputlevelType;

/* Design: MCAL-25811 */
/** \brief CDD Xbar Tick Stretch Type */
typedef enum 
{
    CDD_XBAR_SYSTICKS_STRETCH_OFF = 0U,  /*!<  Output Stretching OFF */
    CDD_XBAR_SYSTICKS_16 = 16U,          /*!<  16 SYSCLK Stretching */
    CDD_XBAR_SYSTICKS_32 = 32U           /*!<  32 SYSCLK Stretching */
} Cdd_Xbar_TickStretchType;

/* Design: MCAL-28165 */
/** \brief CDD Xbar output flag initialization type*/
typedef enum 
{
    CDD_XBAR_OUTPUTDEFAULT = 0U,        /*!<  Latch flag in default state */
    CDD_XBAR_OUTPUTCLEARFLAG = 1U,      /*!<  Latch flag cleared */
    CDD_XBAR_OUTPUTFORCEFLAG = 2U       /*!<  Latch flag forced */
} Cdd_Xbar_OutFlagInitType;

/* Design: MCAL-25812 */
/** \brief CDD Xbar Input Group Type */
typedef enum 
{
    CDD_XBAR_INPUT_GROUP_0 = 0U,       /*!< \brief Input Group 0  */ 
    CDD_XBAR_INPUT_GROUP_1 = 1U,       /*!< \brief Input Group 1  */ 
    CDD_XBAR_INPUT_GROUP_2 = 2U,       /*!< \brief Input Group 2  */ 
    CDD_XBAR_INPUT_GROUP_3 = 3U,       /*!< \brief Input Group 3  */ 
    CDD_XBAR_INPUT_GROUP_4 = 4U,       /*!< \brief Input Group 4  */ 
    CDD_XBAR_INPUT_GROUP_5 = 5U,       /*!< \brief Input Group 5  */ 
    CDD_XBAR_INPUT_GROUP_6 = 6U,       /*!< \brief Input Group 6  */ 
    CDD_XBAR_INPUT_GROUP_7 = 7U,       /*!< \brief Input Group 7  */ 
    CDD_XBAR_INPUT_GROUP_8 = 8U,       /*!< \brief Input Group 8  */ 
    CDD_XBAR_INPUT_GROUP_9 = 9U,       /*!< \brief Input Group 9  */ 
} Cdd_Xbar_InputGroupType;

/* Design: MCAL-25797 */
/** \brief Output Crossbar Input Lines */
typedef enum
{
    CDD_XBAR_OUT_CMPSS1_CTRIPOUTH = 0X0000,          /*!< \brief CMPSS1_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS1_CTRIPOUTL = 0X0001,          /*!< \brief CMPSS1_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS2_CTRIPOUTH = 0X0002,          /*!< \brief CMPSS2_CTRIPOUH  */
    CDD_XBAR_OUT_CMPSS2_CTRIPOUTL = 0X0003,          /*!< \brief CMPSS2_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS3_CTRIPOUTH = 0X0004,          /*!< \brief CMPSS3_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS3_CTRIPOUTL = 0X0005,          /*!< \brief CMPSS3_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS4_CTRIPOUTH = 0X0006,          /*!< \brief CMPSS4_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS4_CTRIPOUTL = 0X0007,          /*!< \brief CMPSS4_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS5_CTRIPOUTH = 0X0008,          /*!< \brief CMPSS5_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS5_CTRIPOUTL = 0X0009,          /*!< \brief CMPSS5_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS6_CTRIPOUTH = 0X000A,          /*!< \brief CMPSS6_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS6_CTRIPOUTL = 0X000B,          /*!< \brief CMPSS6_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS7_CTRIPOUTH = 0X000C,          /*!< \brief CMPSS7_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS7_CTRIPOUTL = 0X000D,          /*!< \brief CMPSS7_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS8_CTRIPOUTH = 0X000E,          /*!< \brief CMPSS8_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS8_CTRIPOUTL = 0X000F,          /*!< \brief CMPSS8_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS9_CTRIPOUTH = 0X0010,          /*!< \brief CMPSS9_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS9_CTRIPOUTL = 0X0011,          /*!< \brief CMPSS9_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS10_CTRIPOUTH = 0X0012,         /*!< \brief CMPSS10_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS10_CTRIPOUTL = 0X0013,         /*!< \brief CMPSS10_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS11_CTRIPOUTH = 0X0014,         /*!< \brief CMPSS11_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS11_CTRIPOUTL = 0X0015,         /*!< \brief CMPSS11_CTRIPOUTL  */
    CDD_XBAR_OUT_CMPSS12_CTRIPOUTH = 0X0016,         /*!< \brief CMPSS12_CTRIPOUTH  */
    CDD_XBAR_OUT_CMPSS12_CTRIPOUTL = 0X0017,         /*!< \brief CMPSS13_CTRIPOUTL  */
    CDD_XBAR_OUT_SD1FLT1_COMPH = 0X0100,             /*!< \brief SD1FLT1_COMPH  */
    CDD_XBAR_OUT_SD1FLT1_COMPL = 0X0101,             /*!< \brief SD1FLT1_COMPH  */
    CDD_XBAR_OUT_SD1FLT2_COMPH = 0X0102,             /*!< \brief SD1FLT2_COMPH  */
    CDD_XBAR_OUT_SD1FLT2_COMPL = 0X0103,             /*!< \brief SD1FLT2_COMPH  */
    CDD_XBAR_OUT_SD1FLT3_COMPH = 0X0104,             /*!< \brief SD1FLT3_COMPH  */
    CDD_XBAR_OUT_SD1FLT3_COMPL = 0X0105,             /*!< \brief SD1FLT3_COMPH  */
    CDD_XBAR_OUT_SD1FLT4_COMPH = 0X0106,             /*!< \brief SD1FLT4_COMPH  */
    CDD_XBAR_OUT_SD1FLT4_COMPL = 0X0107,             /*!< \brief SD1FLT4_COMPH  */
    CDD_XBAR_OUT_SD2FLT1_COMPH = 0X0108,             /*!< \brief SD2FLT1_COMPH  */
    CDD_XBAR_OUT_SD2FLT1_COMPL = 0X0109,             /*!< \brief SD2FLT1_COMPH  */
    CDD_XBAR_OUT_SD2FLT2_COMPH = 0X010A,             /*!< \brief SD2FLT2_COMPH  */
    CDD_XBAR_OUT_SD2FLT2_COMPL = 0X010B,             /*!< \brief SD2FLT2_COMPH  */
    CDD_XBAR_OUT_SD2FLT3_COMPH = 0X010C,             /*!< \brief SD2FLT3_COMPH  */
    CDD_XBAR_OUT_SD2FLT3_COMPL = 0X010D,             /*!< \brief SD2FLT3_COMPH  */
    CDD_XBAR_OUT_SD2FLT4_COMPH = 0X010E,             /*!< \brief SD2FLT4_COMPH  */
    CDD_XBAR_OUT_SD2FLT4_COMPL = 0X010F,             /*!< \brief SD2FLT4_COMPH  */
    CDD_XBAR_OUT_SD3FLT1_COMPH = 0X0110,             /*!< \brief SD3FLT1_COMPH  */
    CDD_XBAR_OUT_SD3FLT1_COMPL = 0X0111,             /*!< \brief SD3FLT1_COMPH  */
    CDD_XBAR_OUT_SD3FLT2_COMPH = 0X0112,             /*!< \brief SD3FLT2_COMPH  */
    CDD_XBAR_OUT_SD3FLT2_COMPL = 0X0113,             /*!< \brief SD3FLT2_COMPH  */
    CDD_XBAR_OUT_SD3FLT3_COMPH = 0X0114,             /*!< \brief SD3FLT3_COMPH  */
    CDD_XBAR_OUT_SD3FLT3_COMPL = 0X0115,             /*!< \brief SD3FLT3_COMPH  */
    CDD_XBAR_OUT_SD3FLT4_COMPH = 0X0116,             /*!< \brief SD3FLT4_COMPH  */
    CDD_XBAR_OUT_SD3FLT4_COMPL = 0X0117,             /*!< \brief SD3FLT4_COMPH  */
    CDD_XBAR_OUT_SD4FLT1_COMPH = 0X0118,             /*!< \brief SD4FLT1_COMPH  */
    CDD_XBAR_OUT_SD4FLT1_COMPL = 0X0119,             /*!< \brief SD4FLT1_COMPH  */
    CDD_XBAR_OUT_SD4FLT2_COMPH = 0X011A,             /*!< \brief SD4FLT2_COMPH  */
    CDD_XBAR_OUT_SD4FLT2_COMPL = 0X011B,             /*!< \brief SD4FLT2_COMPH  */
    CDD_XBAR_OUT_SD4FLT3_COMPH = 0X011C,             /*!< \brief SD4FLT3_COMPH  */
    CDD_XBAR_OUT_SD4FLT3_COMPL = 0X011D,             /*!< \brief SD4FLT3_COMPH  */
    CDD_XBAR_OUT_SD4FLT4_COMPH = 0X011E,             /*!< \brief SD4FLT4_COMPH  */
    CDD_XBAR_OUT_SD4FLT4_COMPL = 0X011F,             /*!< \brief SD4FLT4_COMPH  */
    CDD_XBAR_OUT_ADCAEVT1 = 0X0200,                  /*!< \brief ADCAEVT1  */
    CDD_XBAR_OUT_ADCAEVT2 = 0X0201,                  /*!< \brief ADCAEVT2  */
    CDD_XBAR_OUT_ADCAEVT3 = 0X0202,                  /*!< \brief ADCAEVT3  */
    CDD_XBAR_OUT_ADCAEVT4 = 0X0203,                  /*!< \brief ADCAEVT4  */
    CDD_XBAR_OUT_ADCBEVT1 = 0X0204,                  /*!< \brief ADCBEVT1  */
    CDD_XBAR_OUT_ADCBEVT2 = 0X0205,                  /*!< \brief ADCBEVT2  */
    CDD_XBAR_OUT_ADCBEVT3 = 0X0206,                  /*!< \brief ADCBEVT3  */
    CDD_XBAR_OUT_ADCBEVT4 = 0X0207,                  /*!< \brief ADCBEVT4  */
    CDD_XBAR_OUT_ADCCEVT1 = 0X0208,                  /*!< \brief ADCCEVT1  */
    CDD_XBAR_OUT_ADCCEVT2 = 0X0209,                  /*!< \brief ADCCEVT2  */
    CDD_XBAR_OUT_ADCCEVT3 = 0X020A,                  /*!< \brief ADCCEVT3  */
    CDD_XBAR_OUT_ADCCEVT4 = 0X020B,                  /*!< \brief ADCCEVT4  */
    CDD_XBAR_OUT_ADCDEVT1 = 0X020C,                  /*!< \brief ADCDEVT1  */
    CDD_XBAR_OUT_ADCDEVT2 = 0X020D,                  /*!< \brief ADCDEVT2  */
    CDD_XBAR_OUT_ADCDEVT3 = 0X020E,                  /*!< \brief ADCDEVT3  */
    CDD_XBAR_OUT_ADCDEVT4 = 0X020F,                  /*!< \brief ADCDEVT4  */
    CDD_XBAR_OUT_ADCEEVT1 = 0X0210,                  /*!< \brief ADCEEVT1  */
    CDD_XBAR_OUT_ADCEEVT2 = 0X0211,                  /*!< \brief ADCEEVT2  */
    CDD_XBAR_OUT_ADCEEVT3 = 0X0212,                  /*!< \brief ADCEEVT3  */
    CDD_XBAR_OUT_ADCEEVT4 = 0X0213,                  /*!< \brief ADCEEVT4  */
    CDD_XBAR_OUT_CPU1_ADCCHECKEVT1 = 0X0214,         /*!< \brief CPU1_ADCCHECKEVT1  */
    CDD_XBAR_OUT_CPU1_ADCCHECKEVT2 = 0X0215,         /*!< \brief CPU1_ADCCHECKEVT2  */
    CDD_XBAR_OUT_CPU1_ADCCHECKEVT3 = 0X0216,         /*!< \brief CPU1_ADCCHECKEVT2  */
    CDD_XBAR_OUT_CPU1_ADCCHECKEVT4 = 0X0217,         /*!< \brief CPU1_ADCCHECKEVT4  */
    CDD_XBAR_OUT_CPU2_ADCCHECKEVT1 = 0X0218,         /*!< \brief CPU2_ADCCHECKEVT1  */
    CDD_XBAR_OUT_CPU2_ADCCHECKEVT2 = 0X0219,         /*!< \brief CPU2_ADCCHECKEVT2  */
    CDD_XBAR_OUT_CPU2_ADCCHECKEVT3 = 0X021A,         /*!< \brief CPU2_ADCCHECKEVT3  */
    CDD_XBAR_OUT_CPU2_ADCCHECKEVT4 = 0X021B,         /*!< \brief CPU2_ADCCHECKEVT4  */
    CDD_XBAR_OUT_CPU3_ADCCHECKEVT1 = 0X021C,         /*!< \brief CPU3_ADCCHECKEVT1  */
    CDD_XBAR_OUT_CPU3_ADCCHECKEVT2 = 0X021D,         /*!< \brief CPU3_ADCCHECKEVT2  */
    CDD_XBAR_OUT_CPU3_ADCCHECKEVT3 = 0X021E,         /*!< \brief CPU3_ADCCHECKEVT3  */
    CDD_XBAR_OUT_CPU3_ADCCHECKEVT4 = 0X021F,         /*!< \brief CPU3_ADCCHECKEVT4  */
    CDD_XBAR_OUT_INPUTXBAR1 = 0X0300,                /*!< \brief INPUTXBAR1  */
    CDD_XBAR_OUT_INPUTXBAR2 = 0X0301,                /*!< \brief INPUTXBAR2  */
    CDD_XBAR_OUT_INPUTXBAR3 = 0X0302,                /*!< \brief INPUTXBAR3  */
    CDD_XBAR_OUT_INPUTXBAR4 = 0X0303,                /*!< \brief INPUTXBAR4  */
    CDD_XBAR_OUT_INPUTXBAR5 = 0X0304,                /*!< \brief INPUTXBAR5  */
    CDD_XBAR_OUT_INPUTXBAR6 = 0X0305,                /*!< \brief INPUTXBAR6  */
    CDD_XBAR_OUT_INPUTXBAR7 = 0X0306,                /*!< \brief INPUTXBAR7  */
    CDD_XBAR_OUT_INPUTXBAR8 = 0X0307,                /*!< \brief INPUTXBAR8  */
    CDD_XBAR_OUT_EQEP1_INDEX_SYNCOUT = 0X0400,       /*!< \brief EQEP1_INDEX_SYNCOUT  */
    CDD_XBAR_OUT_EQEP1_STROBE_SYNCOUT = 0X0401,      /*!< \brief EQEP1_STROBE_SYNCOUT  */
    CDD_XBAR_OUT_EQEP2_INDEX_SYNCOUT = 0X0402,       /*!< \brief EQEP2_INDEX_SYNCOUT  */
    CDD_XBAR_OUT_EQEP2_STROBE_SYNCOUT = 0X0403,      /*!< \brief EQEP2_STROBE_SYNCOUT  */
    CDD_XBAR_OUT_EQEP3_INDEX_SYNCOUT = 0X0404,       /*!< \brief EQEP3_INDEX_SYNCOUT  */
    CDD_XBAR_OUT_EQEP3_STROBE_SYNCOUT = 0X0405,      /*!< \brief EQEP3_STROBE_SYNCOUT  */
    CDD_XBAR_OUT_EQEP4_INDEX_SYNCOUT = 0X0406,       /*!< \brief EQEP4_INDEX_SYNCOUT  */
    CDD_XBAR_OUT_EQEP4_STROBE_SYNCOUT = 0X0407,      /*!< \brief EQEP4_STROBE_SYNCOUT  */
    CDD_XBAR_OUT_EQEP5_INDEX_SYNCOUT = 0X0408,       /*!< \brief EQEP5_INDEX_SYNCOUT  */
    CDD_XBAR_OUT_EQEP5_STROBE_SYNCOUT = 0X0409,      /*!< \brief EQEP5_STROBE_SYNCOUT  */
    CDD_XBAR_OUT_EQEP6_INDEX_SYNCOUT = 0X040A,       /*!< \brief EQEP6_INDEX_SYNCOUT  */
    CDD_XBAR_OUT_EQEP6_STROBE_SYNCOUT = 0X040B,      /*!< \brief EQEP6_STROBE_SYNCOUT  */
    CDD_XBAR_OUT_FSIRXA_TRIG1 = 0X0410,              /*!< \brief FSIRXA_TRIG1  */
    CDD_XBAR_OUT_FSIRXB_TRIG1 = 0X0411,              /*!< \brief FSIRXB_TRIG1  */
    CDD_XBAR_OUT_FSIRXC_TRIG1 = 0X0412,              /*!< \brief FSIRXC_TRIG1  */
    CDD_XBAR_OUT_FSIRXD_TRIG1 = 0X0413,              /*!< \brief FSIRXD_TRIG1  */
    CDD_XBAR_OUT_FSIRXA_TRIG2 = 0X0414,              /*!< \brief FSIRXA_TRIG2  */
    CDD_XBAR_OUT_FSIRXB_TRIG2 = 0X0415,              /*!< \brief FSIRXB_TRIG2  */
    CDD_XBAR_OUT_FSIRXC_TRIG2 = 0X0416,              /*!< \brief FSIRXC_TRIG2  */
    CDD_XBAR_OUT_FSIRXD_TRIG2 = 0X0417,              /*!< \brief FSIRXD_TRIG2  */
    CDD_XBAR_OUT_FSIRXA_TRIG3 = 0X0418,              /*!< \brief FSIRXA_TRIG3  */
    CDD_XBAR_OUT_FSIRXB_TRIG3 = 0X0419,              /*!< \brief FSIRXB_TRIG3  */
    CDD_XBAR_OUT_FSIRXC_TRIG3 = 0X041A,              /*!< \brief FSIRXC_TRIG3  */
    CDD_XBAR_OUT_FSIRXD_TRIG3 = 0X041B,              /*!< \brief FSIRXD_TRIG3  */
    CDD_XBAR_OUT_XCLKOUT = 0X041D,                   /*!< \brief XCLKOUT  */
    CDD_XBAR_OUT_ECAT_SYNC0 = 0X041E,                /*!< \brief ECAT_SYNC0  */
    CDD_XBAR_OUT_ECAT_SYNC1 = 0X041F,                /*!< \brief ECAT_SYNC1  */
    CDD_XBAR_OUT_ECAP1_OUT = 0X0500,                 /*!< \brief ECAP1_OUT  */
    CDD_XBAR_OUT_ECAP2_OUT = 0X0501,                 /*!< \brief ECAP2_OUT  */
    CDD_XBAR_OUT_ECAP3_OUT = 0X0502,                 /*!< \brief ECAP3_OUT  */
    CDD_XBAR_OUT_ECAP4_OUT = 0X0503,                 /*!< \brief ECAP4_OUT  */
    CDD_XBAR_OUT_ECAP5_OUT = 0X0504,                 /*!< \brief ECAP5_OUT  */
    CDD_XBAR_OUT_ECAP6_OUT = 0X0505,                 /*!< \brief ECAP6_OUT  */
    CDD_XBAR_OUT_ECAP1_TRIPOUT = 0X0508,             /*!< \brief ECAP1_TRIPOUT  */
    CDD_XBAR_OUT_ECAP2_TRIPOUT = 0X0509,             /*!< \brief ECAP2_TRIPOUT  */
    CDD_XBAR_OUT_ECAP3_TRIPOUT = 0X050A,             /*!< \brief ECAP3_TRIPOUT  */
    CDD_XBAR_OUT_ECAP4_TRIPOUT = 0X050B,             /*!< \brief ECAP4_TRIPOUT  */
    CDD_XBAR_OUT_ECAP5_TRIPOUT = 0X050C,             /*!< \brief ECAP5_TRIPOUT  */
    CDD_XBAR_OUT_ECAP6_TRIPOUT = 0X050D,             /*!< \brief ECAP6_TRIPOUT  */
    CDD_XBAR_OUT_ADCSOCA = 0X0510,                   /*!< \brief ADCSOCA  */
    CDD_XBAR_OUT_ADCSOCB = 0X0511,                   /*!< \brief ADCSOCB  */
    CDD_XBAR_OUT_ESM_GEN_EVENT = 0X0512,             /*!< \brief ESM_GEN_EVENT  */
    CDD_XBAR_OUT_EXTSYNCOUT = 0X0513,                /*!< \brief EXTSYNCOUT  */
    CDD_XBAR_OUT_EPG1OUT0 = 0X0514,                  /*!< \brief EPG1OUT0  */
    CDD_XBAR_OUT_EPG1OUT1 = 0X0515,                  /*!< \brief EPG1OUT1  */
    CDD_XBAR_OUT_EPG1OUT2 = 0X0516,                  /*!< \brief EPG1OUT2  */
    CDD_XBAR_OUT_EPG1OUT3 = 0X0517,                  /*!< \brief EPG1OUT3  */
    CDD_XBAR_OUT_WADI1OUT0 = 0X0518,                 /*!< \brief WADI1OUT0  */
    CDD_XBAR_OUT_WADI1OUT1 = 0X0519,                 /*!< \brief WADI1OUT1  */
    CDD_XBAR_OUT_WADI1OUT2 = 0X051A,                 /*!< \brief WADI1OUT2  */
    CDD_XBAR_OUT_WADI1OUT3 = 0X051B,                 /*!< \brief WADI1OUT3  */
    CDD_XBAR_OUT_WADI1OUT4 = 0X051C,                 /*!< \brief WADI1OUT4  */
    CDD_XBAR_OUT_WADI1OUT5 = 0X051D,                 /*!< \brief WADI1OUT5  */
    CDD_XBAR_OUT_WADI1OUT6 = 0X051E,                 /*!< \brief WADI1OUT6  */
    CDD_XBAR_OUT_WADI1OUT7 = 0X051F,                 /*!< \brief WADI1OUT7  */
    CDD_XBAR_OUT_MCANA_FEVT0 = 0X0600,               /*!< \brief MCANA_FEVT0  */
    CDD_XBAR_OUT_MCANA_FEVT1 = 0X0601,               /*!< \brief MCANA_FEVT1  */
    CDD_XBAR_OUT_MCANA_FEVT2 = 0X0602,               /*!< \brief MCANA_FEVT2  */
    CDD_XBAR_OUT_MCANB_FEVT0 = 0X0603,               /*!< \brief MCANB_FEVT0  */
    CDD_XBAR_OUT_MCANB_FEVT1 = 0X0604,               /*!< \brief MCANB_FEVT1  */
    CDD_XBAR_OUT_MCANB_FEVT2 = 0X0605,               /*!< \brief MCANB_FEVT2  */
    CDD_XBAR_OUT_MCANC_FEVT0 = 0X0606,               /*!< \brief MCANC_FEVT0  */
    CDD_XBAR_OUT_MCANC_FEVT1 = 0X0607,               /*!< \brief MCANC_FEVT1  */
    CDD_XBAR_OUT_MCANC_FEVT2 = 0X0608,               /*!< \brief MCANC_FEVT2  */
    CDD_XBAR_OUT_MCAND_FEVT0 = 0X0609,               /*!< \brief MCAND_FEVT0  */
    CDD_XBAR_OUT_MCAND_FEVT1 = 0X060A,               /*!< \brief MCAND_FEVT1  */
    CDD_XBAR_OUT_MCAND_FEVT2 = 0X060B,               /*!< \brief MCAND_FEVT2  */
    CDD_XBAR_OUT_MCANE_FEVT0 = 0X060C,               /*!< \brief MCANE_FEVT0  */
    CDD_XBAR_OUT_MCANE_FEVT1 = 0X060D,               /*!< \brief MCANE_FEVT1  */
    CDD_XBAR_OUT_MCANE_FEVT2 = 0X060E,               /*!< \brief MCANE_FEVT2  */
    CDD_XBAR_OUT_MCANF_FEVT0 = 0X060F,               /*!< \brief MCANF_FEVT0  */
    CDD_XBAR_OUT_MCANF_FEVT1 = 0X0610,               /*!< \brief MCANF_FEVT1  */
    CDD_XBAR_OUT_MCANF_FEVT2 = 0X0611,               /*!< \brief MCANF_FEVT2  */
    CDD_XBAR_OUT_WADI2OUT0 = 0X0618,                 /*!< \brief WADI2OUT0  */
    CDD_XBAR_OUT_WADI2OUT1 = 0X0619,                 /*!< \brief WADI2OUT1  */
    CDD_XBAR_OUT_WADI2OUT2 = 0X061A,                 /*!< \brief WADI2OUT2  */
    CDD_XBAR_OUT_WADI2OUT3 = 0X061B,                 /*!< \brief WADI2OUT3  */
    CDD_XBAR_OUT_WADI2OUT4 = 0X061C,                 /*!< \brief WADI2OUT4  */
    CDD_XBAR_OUT_WADI2OUT5 = 0X061D,                 /*!< \brief WADI2OUT5  */
    CDD_XBAR_OUT_WADI2OUT6 = 0X061E,                 /*!< \brief WADI2OUT6  */
    CDD_XBAR_OUT_WADI2OUT7 = 0X061F,                 /*!< \brief WADI2OUT7  */
    CDD_XBAR_OUT_CLB1_OUT0 = 0X0700,                 /*!< \brief CLB1_OUT0  */
    CDD_XBAR_OUT_CLB1_OUT1 = 0X0701,                 /*!< \brief CLB1_OUT1  */  
    CDD_XBAR_OUT_CLB1_OUT2 = 0X0702,                 /*!< \brief CLB1_OUT2  */
    CDD_XBAR_OUT_CLB1_OUT3 = 0X0703,                 /*!< \brief CLB1_OUT3  */
    CDD_XBAR_OUT_CLB1_OUT4 = 0X0704,                 /*!< \brief CLB1_OUT4  */
    CDD_XBAR_OUT_CLB1_OUT5 = 0X0705,                 /*!< \brief CLB1_OUT5  */
    CDD_XBAR_OUT_CLB1_OUT6 = 0X0706,                 /*!< \brief CLB1_OUT6  */
    CDD_XBAR_OUT_CLB1_OUT7 = 0X0707,                 /*!< \brief CLB1_OUT7  */
    CDD_XBAR_OUT_CLB2_OUT0 = 0X0708,                 /*!< \brief CLB2_OUT0  */
    CDD_XBAR_OUT_CLB2_OUT1 = 0X0709,                 /*!< \brief CLB2_OUT1  */
    CDD_XBAR_OUT_CLB2_OUT2 = 0X070A,                 /*!< \brief CLB2_OUT2  */
    CDD_XBAR_OUT_CLB2_OUT3 = 0X070B,                 /*!< \brief CLB2_OUT3  */
    CDD_XBAR_OUT_CLB2_OUT4 = 0X070C,                 /*!< \brief CLB2_OUT4  */
    CDD_XBAR_OUT_CLB2_OUT5 = 0X070D,                 /*!< \brief CLB2_OUT5  */
    CDD_XBAR_OUT_CLB2_OUT6 = 0X070E,                 /*!< \brief CLB2_OUT6  */
    CDD_XBAR_OUT_CLB2_OUT7 = 0X070F,                 /*!< \brief CLB2_OUT7  */
    CDD_XBAR_OUT_CLB3_OUT0 = 0X0710,                 /*!< \brief CLB3_OUT0  */
    CDD_XBAR_OUT_CLB3_OUT1 = 0X0711,                 /*!< \brief CLB3_OUT1  */
    CDD_XBAR_OUT_CLB3_OUT2 = 0X0712,                 /*!< \brief CLB3_OUT2  */
    CDD_XBAR_OUT_CLB3_OUT3 = 0X0713,                 /*!< \brief CLB3_OUT3  */
    CDD_XBAR_OUT_CLB3_OUT4 = 0X0714,                 /*!< \brief CLB3_OUT4  */
    CDD_XBAR_OUT_CLB3_OUT5 = 0X0715,                 /*!< \brief CLB3_OUT5  */
    CDD_XBAR_OUT_CLB3_OUT6 = 0X0716,                 /*!< \brief CLB3_OUT6  */
    CDD_XBAR_OUT_CLB3_OUT7 = 0X0717,                 /*!< \brief CLB3_OUT7  */
    CDD_XBAR_OUT_CLB4_OUT0 = 0X0718,                 /*!< \brief CLB4_OUT0  */
    CDD_XBAR_OUT_CLB4_OUT1 = 0X0719,                 /*!< \brief CLB4_OUT1  */
    CDD_XBAR_OUT_CLB4_OUT2 = 0X071A,                 /*!< \brief CLB4_OUT2  */
    CDD_XBAR_OUT_CLB4_OUT3 = 0X071B,                 /*!< \brief CLB4_OUT3  */
    CDD_XBAR_OUT_CLB4_OUT4 = 0X071C,                 /*!< \brief CLB4_OUT4  */
    CDD_XBAR_OUT_CLB4_OUT5 = 0X071D,                 /*!< \brief CLB4_OUT5  */
    CDD_XBAR_OUT_CLB4_OUT6 = 0X071E,                 /*!< \brief CLB4_OUT6  */
    CDD_XBAR_OUT_CLB4_OUT7 = 0X071F,                 /*!< \brief CLB4_OUT7  */
    CDD_XBAR_OUT_CLB5_OUT0 = 0X0800,                 /*!< \brief CLB5_OUT0  */
    CDD_XBAR_OUT_CLB5_OUT1 = 0X0801,                 /*!< \brief CLB5_OUT1  */
    CDD_XBAR_OUT_CLB5_OUT2 = 0X0802,                 /*!< \brief CLB5_OUT2  */
    CDD_XBAR_OUT_CLB5_OUT3 = 0X0803,                 /*!< \brief CLB5_OUT3  */
    CDD_XBAR_OUT_CLB5_OUT4 = 0X0804,                 /*!< \brief CLB5_OUT4  */
    CDD_XBAR_OUT_CLB5_OUT5 = 0X0805,                 /*!< \brief CLB5_OUT5  */
    CDD_XBAR_OUT_CLB5_OUT6 = 0X0806,                 /*!< \brief CLB5_OUT6  */
    CDD_XBAR_OUT_CLB5_OUT7 = 0X0807,                 /*!< \brief CLB5_OUT7  */
    CDD_XBAR_OUT_CLB6_OUT0 = 0X0808,                 /*!< \brief CLB6_OUT0  */
    CDD_XBAR_OUT_CLB6_OUT1 = 0X0809,                 /*!< \brief CLB6_OUT1  */
    CDD_XBAR_OUT_CLB6_OUT2 = 0X080A,                 /*!< \brief CLB6_OUT2  */
    CDD_XBAR_OUT_CLB6_OUT3 = 0X080B,                 /*!< \brief CLB6_OUT3  */
    CDD_XBAR_OUT_CLB6_OUT4 = 0X080C,                 /*!< \brief CLB6_OUT4  */
    CDD_XBAR_OUT_CLB6_OUT5 = 0X080D,                 /*!< \brief CLB6_OUT5  */
    CDD_XBAR_OUT_CLB6_OUT6 = 0X080E,                 /*!< \brief CLB6_OUT6  */
    CDD_XBAR_OUT_CLB6_OUT7 = 0X080F,                 /*!< \brief CLB6_OUT7  */
    CDD_XBAR_OUT_CLBXBAR1 = 0X0900,                  /*!< \brief CLBXBAR1  */
    CDD_XBAR_OUT_CLBXBAR2 = 0X0901,                  /*!< \brief CLBXBAR2  */
    CDD_XBAR_OUT_CLBXBAR3 = 0X0902,                  /*!< \brief CLBXBAR3  */
    CDD_XBAR_OUT_CLBXBAR4 = 0X0903,                  /*!< \brief CLBXBAR4  */
    CDD_XBAR_OUT_CLBXBAR5 = 0X0904,                  /*!< \brief CLBXBAR5  */
    CDD_XBAR_OUT_CLBXBAR6 = 0X0905,                  /*!< \brief CLBXBAR6  */
    CDD_XBAR_OUT_CLBXBAR7 = 0X0906,                  /*!< \brief CLBXBAR7  */
    CDD_XBAR_OUT_CLBXBAR8 = 0X0907,                  /*!< \brief CLBXBAR8  */
    CDD_XBAR_OUT_ADCA_EXTMUXSEL0 = 0X0908,           /*!< \brief ADCA_EXTMUXSEL0  */
    CDD_XBAR_OUT_ADCA_EXTMUXSEL1 = 0X0909,           /*!< \brief ADCA_EXTMUXSEL1  */
    CDD_XBAR_OUT_ADCA_EXTMUXSEL2 = 0X090A,           /*!< \brief ADCA_EXTMUXSEL2  */
    CDD_XBAR_OUT_ADCA_EXTMUXSEL3 = 0X090B,           /*!< \brief ADCA_EXTMUXSEL3  */
    CDD_XBAR_OUT_ADCB_EXTMUXSEL0 = 0X090C,           /*!< \brief ADCB_EXTMUXSEL0  */
    CDD_XBAR_OUT_ADCB_EXTMUXSEL1 = 0X090D,           /*!< \brief ADCB_EXTMUXSEL1  */
    CDD_XBAR_OUT_ADCB_EXTMUXSEL2 = 0X090E,           /*!< \brief ADCB_EXTMUXSEL2  */
    CDD_XBAR_OUT_ADCB_EXTMUXSEL3 = 0X090F,           /*!< \brief ADCB_EXTMUXSEL3  */
    CDD_XBAR_OUT_ADCC_EXTMUXSEL0 = 0X0910,           /*!< \brief ADCC_EXTMUXSEL0  */
    CDD_XBAR_OUT_ADCC_EXTMUXSEL1 = 0X0911,           /*!< \brief ADCC_EXTMUXSEL1  */
    CDD_XBAR_OUT_ADCC_EXTMUXSEL2 = 0X0912,           /*!< \brief ADCC_EXTMUXSEL2  */
    CDD_XBAR_OUT_ADCC_EXTMUXSEL3 = 0X0913,           /*!< \brief ADCC_EXTMUXSEL3  */
    CDD_XBAR_OUT_ADCD_EXTMUXSEL0 = 0X0914,           /*!< \brief ADCD_EXTMUXSEL0  */
    CDD_XBAR_OUT_ADCD_EXTMUXSEL1 = 0X0915,           /*!< \brief ADCD_EXTMUXSEL1  */
    CDD_XBAR_OUT_ADCD_EXTMUXSEL2 = 0X0916,           /*!< \brief ADCD_EXTMUXSEL2  */
    CDD_XBAR_OUT_ADCD_EXTMUXSEL3 = 0X0917,           /*!< \brief ADCD_EXTMUXSEL3  */
    CDD_XBAR_OUT_ADCE_EXTMUXSEL0 = 0X0918,           /*!< \brief ADCE_EXTMUXSEL0  */
    CDD_XBAR_OUT_ADCE_EXTMUXSEL1 = 0X0919,           /*!< \brief ADCE_EXTMUXSEL1  */
    CDD_XBAR_OUT_ADCE_EXTMUXSEL2 = 0X091A,           /*!< \brief ADCE_EXTMUXSEL2  */
    CDD_XBAR_OUT_ADCE_EXTMUXSEL3 = 0X091B,           /*!< \brief ADCE_EXTMUXSEL3  */
} Cdd_Xbar_Output_Xbar_Input_LinesType;

/* Design: MCAL-25798 */
/** \brief EPWM Crossbar Input Lines */
typedef enum
{
    CDD_XBAR_EPWM_CMPSS1_CTRIPH = 0X0000,           /*!< \brief CMPSS1_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS1_CTRIPL = 0X0001,           /*!< \brief CMPSS1_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS2_CTRIPH = 0X0002,           /*!< \brief CMPSS2_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS2_CTRIPL = 0X0003,           /*!< \brief CMPSS2_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS3_CTRIPH = 0X0004,           /*!< \brief CMPSS3_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS3_CTRIPL = 0X0005,           /*!< \brief CMPSS3_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS4_CTRIPH = 0X0006,           /*!< \brief CMPSS4_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS4_CTRIPL = 0X0007,           /*!< \brief CMPSS4_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS5_CTRIPH = 0X0008,           /*!< \brief CMPSS5_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS5_CTRIPL = 0X0009,           /*!< \brief CMPSS5_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS6_CTRIPH = 0X000A,           /*!< \brief CMPSS6_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS6_CTRIPL = 0X000B,           /*!< \brief CMPSS6_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS7_CTRIPH = 0X000C,           /*!< \brief CMPSS7_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS7_CTRIPL = 0X000D,           /*!< \brief CMPSS7_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS8_CTRIPH = 0X000E,           /*!< \brief CMPSS8_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS8_CTRIPL = 0X000F,           /*!< \brief CMPSS8_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS9_CTRIPH = 0X0010,           /*!< \brief CMPSS9_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS9_CTRIPL = 0X0011,           /*!< \brief CMPSS9_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS10_CTRIPH = 0X0012,          /*!< \brief CMPSS10_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS10_CTRIPL = 0X0013,          /*!< \brief CMPSS10_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS11_CTRIPH = 0X0014,          /*!< \brief CMPSS11_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS11_CTRIPL = 0X0015,          /*!< \brief CMPSS11_CTRIPL  */
    CDD_XBAR_EPWM_CMPSS12_CTRIPH = 0X0016,          /*!< \brief CMPSS12_CTRIPH  */
    CDD_XBAR_EPWM_CMPSS12_CTRIPL = 0X0017,          /*!< \brief CMPSS12_CTRIPL  */
    CDD_XBAR_EPWM_SD1FLT1_COMPH = 0X0100,           /*!< \brief SD1FLT1_COMPH  */
    CDD_XBAR_EPWM_SD1FLT1_COMPL = 0X0101,           /*!< \brief SD1FLT1_COMPL  */
    CDD_XBAR_EPWM_SD1FLT2_COMPH = 0X0102,           /*!< \brief SD1FLT2_COMPH  */
    CDD_XBAR_EPWM_SD1FLT2_COMPL = 0X0103,           /*!< \brief SD1FLT2_COMPL  */
    CDD_XBAR_EPWM_SD1FLT3_COMPH = 0X0104,           /*!< \brief SD1FLT3_COMPH  */
    CDD_XBAR_EPWM_SD1FLT3_COMPL = 0X0105,           /*!< \brief SD1FLT3_COMPL  */
    CDD_XBAR_EPWM_SD1FLT4_COMPH = 0X0106,           /*!< \brief SD1FLT4_COMPH  */
    CDD_XBAR_EPWM_SD1FLT4_COMPL = 0X0107,           /*!< \brief SD1FLT4_COMPL  */
    CDD_XBAR_EPWM_SD2FLT1_COMPH = 0X0108,           /*!< \brief SD2FLT1_COMPH  */
    CDD_XBAR_EPWM_SD2FLT1_COMPL = 0X0109,           /*!< \brief SD2FLT1_COMPL  */
    CDD_XBAR_EPWM_SD2FLT2_COMPH = 0X010A,           /*!< \brief SD2FLT2_COMPH  */
    CDD_XBAR_EPWM_SD2FLT2_COMPL = 0X010B,           /*!< \brief SD2FLT2_COMPL  */
    CDD_XBAR_EPWM_SD2FLT3_COMPH = 0X010C,           /*!< \brief SD2FLT3_COMPH  */
    CDD_XBAR_EPWM_SD2FLT3_COMPL = 0X010D,           /*!< \brief SD2FLT2_COMPL  */
    CDD_XBAR_EPWM_SD2FLT4_COMPH = 0X010E,           /*!< \brief SD2FLT4_COMPH  */
    CDD_XBAR_EPWM_SD2FLT4_COMPL = 0X010F,           /*!< \brief SD2FLT4_COMPL  */
    CDD_XBAR_EPWM_SD3FLT1_COMPH = 0X0110,           /*!< \brief SD3FLT1_COMPH  */
    CDD_XBAR_EPWM_SD3FLT1_COMPL = 0X0111,           /*!< \brief SD3FLT1_COMPL  */
    CDD_XBAR_EPWM_SD3FLT2_COMPH = 0X0112,           /*!< \brief SD3FLT2_COMPH  */
    CDD_XBAR_EPWM_SD3FLT2_COMPL = 0X0113,           /*!< \brief SD3FLT2_COMPL  */
    CDD_XBAR_EPWM_SD3FLT3_COMPH = 0X0114,           /*!< \brief SD3FLT3_COMPH  */
    CDD_XBAR_EPWM_SD3FLT3_COMPL = 0X0115,           /*!< \brief SD3FLT3_COMPL  */
    CDD_XBAR_EPWM_SD3FLT4_COMPH = 0X0116,           /*!< \brief SD3FLT4_COMPH  */
    CDD_XBAR_EPWM_SD3FLT4_COMPL = 0X0117,           /*!< \brief SD3FLT4_COMPL  */
    CDD_XBAR_EPWM_SD4FLT1_COMPH = 0X0118,           /*!< \brief SD4FLT1_COMPH  */
    CDD_XBAR_EPWM_SD4FLT1_COMPL = 0X0119,           /*!< \brief SD4FLT1_COMPL  */
    CDD_XBAR_EPWM_SD4FLT2_COMPH = 0X011A,           /*!< \brief SD4FLT2_COMPH  */
    CDD_XBAR_EPWM_SD4FLT2_COMPL = 0X011B,           /*!< \brief SD4FLT2_COMPL  */
    CDD_XBAR_EPWM_SD4FLT3_COMPH = 0X011C,           /*!< \brief SD4FLT3_COMPH  */
    CDD_XBAR_EPWM_SD4FLT3_COMPL = 0X011D,           /*!< \brief SD4FLT3_COMPL  */
    CDD_XBAR_EPWM_SD4FLT4_COMPH = 0X011E,           /*!< \brief SD4FLT4_COMPH  */
    CDD_XBAR_EPWM_SD4FLT4_COMPL = 0X011F,           /*!< \brief SD4FLT4_COMPL  */
    CDD_XBAR_EPWM_ADCAEVT1 = 0X0200,                /*!< \brief ADCAEVT1  */
    CDD_XBAR_EPWM_ADCAEVT2 = 0X0201,                /*!< \brief ADCAEVT2  */
    CDD_XBAR_EPWM_ADCAEVT3 = 0X0202,                /*!< \brief ADCAEVT3  */
    CDD_XBAR_EPWM_ADCAEVT4 = 0X0203,                /*!< \brief ADCAEVT4  */
    CDD_XBAR_EPWM_ADCBEVT1 = 0X0204,                /*!< \brief ADCBEVT1  */
    CDD_XBAR_EPWM_ADCBEVT2 = 0X0205,                /*!< \brief ADCBEVT2  */
    CDD_XBAR_EPWM_ADCBEVT3 = 0X0206,                /*!< \brief ADCBEVT3  */
    CDD_XBAR_EPWM_ADCBEVT4 = 0X0207,                /*!< \brief ADCBEVT4  */
    CDD_XBAR_EPWM_ADCCEVT1 = 0X0208,                /*!< \brief ADCCEVT1  */
    CDD_XBAR_EPWM_ADCCEVT2 = 0X0209,                /*!< \brief ADCCEVT2  */
    CDD_XBAR_EPWM_ADCCEVT3 = 0X020A,                /*!< \brief ADCCEVT3  */
    CDD_XBAR_EPWM_ADCCEVT4 = 0X020B,                /*!< \brief ADCCEVT4  */
    CDD_XBAR_EPWM_ADCDEVT1 = 0X020C,                /*!< \brief ADCDEVT1  */
    CDD_XBAR_EPWM_ADCDEVT2 = 0X020D,                /*!< \brief ADCDEVT2  */
    CDD_XBAR_EPWM_ADCDEVT3 = 0X020E,                /*!< \brief ADCDEVT3  */
    CDD_XBAR_EPWM_ADCDEVT4 = 0X020F,                /*!< \brief ADCDEVT4  */
    CDD_XBAR_EPWM_ADCEEVT1 = 0X0210,                /*!< \brief ADCEEVT1  */
    CDD_XBAR_EPWM_ADCEEVT2 = 0X0211,                /*!< \brief ADCEEVT2  */
    CDD_XBAR_EPWM_ADCEEVT3 = 0X0212,                /*!< \brief ADCEEVT3  */
    CDD_XBAR_EPWM_ADCEEVT4 = 0X0213,                /*!< \brief ADCEEVT4  */
    CDD_XBAR_EPWM_CPU1_ADCCHECKEVT1 = 0X0214,       /*!< \brief CPU1_ADCCHECKEVT1  */
    CDD_XBAR_EPWM_CPU1_ADCCHECKEVT2 = 0X0215,       /*!< \brief CPU1_ADCCHECKEVT2  */
    CDD_XBAR_EPWM_CPU1_ADCCHECKEVT3 = 0X0216,       /*!< \brief CPU1_ADCCHECKEVT3  */
    CDD_XBAR_EPWM_CPU1_ADCCHECKEVT4 = 0X0217,       /*!< \brief CPU1_ADCCHECKEVT4  */
    CDD_XBAR_EPWM_CPU2_ADCCHECKEVT1 = 0X0218,       /*!< \brief CPU2_ADCCHECKEVT1  */
    CDD_XBAR_EPWM_CPU2_ADCCHECKEVT2 = 0X0219,       /*!< \brief CPU2_ADCCHECKEVT2  */
    CDD_XBAR_EPWM_CPU2_ADCCHECKEVT3 = 0X021A,       /*!< \brief CPU2_ADCCHECKEVT3  */
    CDD_XBAR_EPWM_CPU2_ADCCHECKEVT4 = 0X021B,       /*!< \brief CPU2_ADCCHECKEVT4  */
    CDD_XBAR_EPWM_CPU3_ADCCHECKEVT1 = 0X021C,       /*!< \brief CPU3_ADCCHECKEVT1  */
    CDD_XBAR_EPWM_CPU3_ADCCHECKEVT2 = 0X021D,       /*!< \brief CPU3_ADCCHECKEVT2  */
    CDD_XBAR_EPWM_CPU3_ADCCHECKEVT3 = 0X021E,       /*!< \brief CPU3_ADCCHECKEVT3  */
    CDD_XBAR_EPWM_CPU3_ADCCHECKEVT4 = 0X021F,       /*!< \brief CPU3_ADCCHECKEVT4  */
    CDD_XBAR_EPWM_INPUTXBAR1 = 0X0300,              /*!< \brief INPUTXBAR1  */
    CDD_XBAR_EPWM_INPUTXBAR2 = 0X0301,              /*!< \brief INPUTXBAR2  */
    CDD_XBAR_EPWM_INPUTXBAR3 = 0X0302,              /*!< \brief INPUTXBAR3  */
    CDD_XBAR_EPWM_INPUTXBAR4 = 0X0303,              /*!< \brief INPUTXBAR4  */
    CDD_XBAR_EPWM_INPUTXBAR5 = 0X0304,              /*!< \brief INPUTXBAR5  */
    CDD_XBAR_EPWM_INPUTXBAR6 = 0X0305,              /*!< \brief INPUTXBAR6  */
    CDD_XBAR_EPWM_INPUTXBAR7 = 0X0306,              /*!< \brief INPUTXBAR7  */
    CDD_XBAR_EPWM_INPUTXBAR8 = 0X0307,              /*!< \brief INPUTXBAR8  */
    CDD_XBAR_EPWM_INPUTXBAR9 = 0X0308,              /*!< \brief INPUTXBAR9  */
    CDD_XBAR_EPWM_INPUTXBAR10 = 0X0309,             /*!< \brief INPUTXBAR10  */
    CDD_XBAR_EPWM_INPUTXBAR11 = 0X030A,             /*!< \brief INPUTXBAR11  */
    CDD_XBAR_EPWM_INPUTXBAR12 = 0X030B,             /*!< \brief INPUTXBAR12  */
    CDD_XBAR_EPWM_INPUTXBAR13 = 0X030C,             /*!< \brief INPUTXBAR13  */
    CDD_XBAR_EPWM_INPUTXBAR14 = 0X030D,             /*!< \brief INPUTXBAR14  */
    CDD_XBAR_EPWM_INPUTXBAR15 = 0X030E,             /*!< \brief INPUTXBAR15  */
    CDD_XBAR_EPWM_INPUTXBAR16 = 0X030F,             /*!< \brief INPUTXBAR16  */
    CDD_XBAR_EPWM_INPUTXBAR17 = 0X0310,             /*!< \brief INPUTXBAR17  */
    CDD_XBAR_EPWM_INPUTXBAR18 = 0X0311,             /*!< \brief INPUTXBAR18  */
    CDD_XBAR_EPWM_INPUTXBAR19 = 0X0312,             /*!< \brief INPUTXBAR19  */
    CDD_XBAR_EPWM_INPUTXBAR20 = 0X0313,             /*!< \brief INPUTXBAR20  */
    CDD_XBAR_EPWM_INPUTXBAR21 = 0X0314,             /*!< \brief INPUTXBAR21 */
    CDD_XBAR_EPWM_INPUTXBAR22 = 0X0315,             /*!< \brief INPUTXBAR22  */
    CDD_XBAR_EPWM_INPUTXBAR23 = 0X0316,             /*!< \brief INPUTXBAR23  */
    CDD_XBAR_EPWM_INPUTXBAR24 = 0X0317,             /*!< \brief INPUTXBAR24  */
    CDD_XBAR_EPWM_INPUTXBAR25 = 0X0318,             /*!< \brief INPUTXBAR25  */
    CDD_XBAR_EPWM_INPUTXBAR26 = 0X0319,             /*!< \brief INPUTXBAR26  */
    CDD_XBAR_EPWM_INPUTXBAR27 = 0X031A,             /*!< \brief INPUTXBAR27  */
    CDD_XBAR_EPWM_INPUTXBAR28 = 0X031B,             /*!< \brief INPUTXBAR28  */
    CDD_XBAR_EPWM_INPUTXBAR29 = 0X031C,             /*!< \brief INPUTXBAR29  */
    CDD_XBAR_EPWM_INPUTXBAR30 = 0X031D,             /*!< \brief INPUTXBAR30  */
    CDD_XBAR_EPWM_INPUTXBAR31 = 0X031E,             /*!< \brief INPUTXBAR31  */
    CDD_XBAR_EPWM_INPUTXBAR32 = 0X031F,             /*!< \brief INPUTXBAR32  */
    CDD_XBAR_EPWM_CLB1_OUT4 = 0X0400,               /*!< \brief CLB1_OUT4  */
    CDD_XBAR_EPWM_CLB1_OUT5 = 0X0401,               /*!< \brief CLB1_OUT5  */
    CDD_XBAR_EPWM_CLB2_OUT4 = 0X0402,               /*!< \brief CLB2_OUT4  */
    CDD_XBAR_EPWM_CLB2_OUT5 = 0X0403,               /*!< \brief CLB2_OUT5  */
    CDD_XBAR_EPWM_CLB3_OUT4 = 0X0404,               /*!< \brief CLB3_OUT4  */
    CDD_XBAR_EPWM_CLB3_OUT5 = 0X0405,               /*!< \brief CLB3_OUT5  */
    CDD_XBAR_EPWM_CLB4_OUT4 = 0X0406,               /*!< \brief CLB4_OUT4  */
    CDD_XBAR_EPWM_CLB4_OUT5 = 0X0407,               /*!< \brief CLB4_OUT5  */
    CDD_XBAR_EPWM_CLB5_OUT4 = 0X0408,               /*!< \brief CLB5_OUT4  */
    CDD_XBAR_EPWM_CLB5_OUT5 = 0X0409,               /*!< \brief CLB5_OUT5  */
    CDD_XBAR_EPWM_CLB6_OUT4 = 0X040A,               /*!< \brief CLB6_OUT4  */
    CDD_XBAR_EPWM_CLB6_OUT5 = 0X040B,               /*!< \brief CLB6_OUT5  */
    CDD_XBAR_EPWM_FSIRXA_TRIG1 = 0X0410,            /*!< \brief FSIRXA_TRIG1  */
    CDD_XBAR_EPWM_FSIRXB_TRIG1 = 0X0411,            /*!< \brief FSIRXB_TRIG1  */
    CDD_XBAR_EPWM_FSIRXC_TRIG1 = 0X0412,            /*!< \brief FSIRXC_TRIG1  */
    CDD_XBAR_EPWM_FSIRXD_TRIG1 = 0X0413,            /*!< \brief FSIRXD_TRIG1  */
    CDD_XBAR_EPWM_ECAT_SYNC0 = 0X041E,              /*!< \brief ECAT_SYNC0  */
    CDD_XBAR_EPWM_ECAT_SYNC1 = 0X041F,              /*!< \brief ECAT_SYNC1  */
    CDD_XBAR_EPWM_ECAP1_OUT = 0X0500,               /*!< \brief ECAP1_OUT  */
    CDD_XBAR_EPWM_ECAP2_OUT = 0X0501,               /*!< \brief ECAP2_OUT  */
    CDD_XBAR_EPWM_ECAP3_OUT = 0X0502,               /*!< \brief ECAP3_OUT  */
    CDD_XBAR_EPWM_ECAP4_OUT = 0X0503,               /*!< \brief ECAP4_OUT  */
    CDD_XBAR_EPWM_ECAP5_OUT = 0X0504,               /*!< \brief ECAP5_OUT  */
    CDD_XBAR_EPWM_ECAP6_OUT = 0X0505,               /*!< \brief ECAP6_OUT  */
    CDD_XBAR_EPWM_ECAP1_TRIPOUT = 0X0508,           /*!< \brief ECAP1_TRIPOUT  */
    CDD_XBAR_EPWM_ECAP2_TRIPOUT = 0X0509,           /*!< \brief ECAP2_TRIPOUT  */
    CDD_XBAR_EPWM_ECAP3_TRIPOUT = 0X050A,           /*!< \brief ECAP3_TRIPOUT  */
    CDD_XBAR_EPWM_ECAP4_TRIPOUT = 0X050B,           /*!< \brief ECAP4_TRIPOUT  */
    CDD_XBAR_EPWM_ECAP5_TRIPOUT = 0X050C,           /*!< \brief ECAP5_TRIPOUT  */
    CDD_XBAR_EPWM_ECAP6_TRIPOUT = 0X050D,           /*!< \brief ECAP6_TRIPOUT  */
    CDD_XBAR_EPWM_ADCSOCA = 0X0510,                 /*!< \brief ADCSOCA  */
    CDD_XBAR_EPWM_ADCSOCB = 0X0511,                 /*!< \brief ADCSOCB  */
    CDD_XBAR_EPWM_ESM_GEN_EVENT = 0X0512,           /*!< \brief ESM_GEN_EVENT  */
    CDD_XBAR_EPWM_EXTSYNCOUT = 0X0513,              /*!< \brief EXTSYNCOUT  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_0 = 0X0514,     /*!< \brief WADI1_ERROR_BUS_O_0  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_1 = 0X0515,     /*!< \brief WADI1_ERROR_BUS_O_1  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_2 = 0X0516,     /*!< \brief WADI1_ERROR_BUS_O_2  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_3 = 0X0517,     /*!< \brief WADI1_ERROR_BUS_O_3  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_4 = 0X0518,     /*!< \brief WADI1_ERROR_BUS_O_4  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_5 = 0X0519,     /*!< \brief WADI1_ERROR_BUS_O_5  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_6 = 0X051A,     /*!< \brief WADI1_ERROR_BUS_O_6  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_7 = 0X051B,     /*!< \brief WADI1_ERROR_BUS_O_7  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_8 = 0X051C,     /*!< \brief WADI1_ERROR_BUS_O_8  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_9 = 0X051D,     /*!< \brief WADI1_ERROR_BUS_O_9  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_10 = 0X051E,    /*!< \brief WADI1_ERROR_BUS_O_10  */
    CDD_XBAR_EPWM_WADI1_ERROR_BUS_O_11 = 0X051F,    /*!< \brief WADI1_ERROR_BUS_O_11  */
    CDD_XBAR_EPWM_MCANA_FEVT0 = 0X0600,             /*!< \brief MCANA_FEVT0  */
    CDD_XBAR_EPWM_MCANA_FEVT1 = 0X0601,             /*!< \brief MCANA_FEVT1  */
    CDD_XBAR_EPWM_MCANA_FEVT2 = 0X0602,             /*!< \brief MCANA_FEVT2  */
    CDD_XBAR_EPWM_MCANB_FEVT0 = 0X0603,             /*!< \brief MCANB_FEVT0  */
    CDD_XBAR_EPWM_MCANB_FEVT1 = 0X0604,             /*!< \brief MCANB_FEVT1  */
    CDD_XBAR_EPWM_MCANB_FEVT2 = 0X0605,             /*!< \brief MCANB_FEVT2  */
    CDD_XBAR_EPWM_MCANC_FEVT0 = 0X0606,             /*!< \brief MCANC_FEVT0  */
    CDD_XBAR_EPWM_MCANC_FEVT1 = 0X0607,             /*!< \brief MCANC_FEVT1  */
    CDD_XBAR_EPWM_MCANC_FEVT2 = 0X0608,             /*!< \brief MCANC_FEVT2  */
    CDD_XBAR_EPWM_MCAND_FEVT0 = 0X0609,             /*!< \brief MCAND_FEVT0  */
    CDD_XBAR_EPWM_MCAND_FEVT1 = 0X060A,             /*!< \brief MCAND_FEVT1  */
    CDD_XBAR_EPWM_MCAND_FEVT2 = 0X060B,             /*!< \brief MCAND_FEVT2  */
    CDD_XBAR_EPWM_MCANE_FEVT0 = 0X060C,             /*!< \brief MCANE_FEVT0  */
    CDD_XBAR_EPWM_MCANE_FEVT1 = 0X060D,             /*!< \brief MCANE_FEVT1  */
    CDD_XBAR_EPWM_MCANE_FEVT2 = 0X060E,             /*!< \brief MCANE_FEVT2  */
    CDD_XBAR_EPWM_MCANF_FEVT0 = 0X060F,             /*!< \brief MCANF_FEVT0  */
    CDD_XBAR_EPWM_MCANF_FEVT1 = 0X0610,             /*!< \brief MCANF_FEVT1  */
    CDD_XBAR_EPWM_MCANF_FEVT2 = 0X0611,             /*!< \brief MCANF_FEVT3  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_0 = 0X0614,     /*!< \brief WADI2_ERROR_BUS_O_0  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_1 = 0X0615,     /*!< \brief WADI2_ERROR_BUS_O_1  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_2 = 0X0616,     /*!< \brief WADI2_ERROR_BUS_O_2  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_3 = 0X0617,     /*!< \brief WADI2_ERROR_BUS_O_3  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_4 = 0X0618,     /*!< \brief WADI2_ERROR_BUS_O_4  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_5 = 0X0619,     /*!< \brief WADI2_ERROR_BUS_O_5  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_6 = 0X061A,     /*!< \brief WADI2_ERROR_BUS_O_6  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_7 = 0X061B,     /*!< \brief WADI2_ERROR_BUS_O_7  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_8 = 0X061C,     /*!< \brief WADI2_ERROR_BUS_O_8  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_9 = 0X061D,     /*!< \brief WADI2_ERROR_BUS_O_9  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_10 = 0X061E,    /*!< \brief WADI2_ERROR_BUS_O_10  */
    CDD_XBAR_EPWM_WADI2_ERROR_BUS_O_11 = 0X061F,    /*!< \brief WADI2_ERROR_BUS_O_11  */
    CDD_XBAR_EPWM_EPWM1_TRIPOUT = 0X0700,           /*!< \brief EPWM1_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM2_TRIPOUT = 0X0701,           /*!< \brief EPWM2_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM3_TRIPOUT = 0X0702,           /*!< \brief EPWM3_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM4_TRIPOUT = 0X0703,           /*!< \brief EPWM4_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM5_TRIPOUT = 0X0704,           /*!< \brief EPWM5_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM6_TRIPOUT = 0X0705,           /*!< \brief EPWM6_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM7_TRIPOUT = 0X0706,           /*!< \brief EPWM7_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM8_TRIPOUT = 0X0707,           /*!< \brief EPWM8_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM9_TRIPOUT = 0X0708,           /*!< \brief EPWM9_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM10_TRIPOUT = 0X0709,          /*!< \brief EPWM10_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM11_TRIPOUT = 0X070A,          /*!< \brief EPWM11_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM12_TRIPOUT = 0X070B,          /*!< \brief EPWM12_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM13_TRIPOUT = 0X070C,          /*!< \brief EPWM13_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM14_TRIPOUT = 0X070D,          /*!< \brief EPWM14_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM15_TRIPOUT = 0X070E,          /*!< \brief EPWM15_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM16_TRIPOUT = 0X070F,          /*!< \brief EPWM16_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM17_TRIPOUT = 0X0710,          /*!< \brief EPWM17_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM18_TRIPOUT = 0X0711,          /*!< \brief EPWM18_TRIPOUT  */
    CDD_XBAR_EPWM_EPWM1_DE_DEMONTRIP = 0X0800,      /*!< \brief EPWM1_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM2_DE_DEMONTRIP = 0X0801,      /*!< \brief EPWM2_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM3_DE_DEMONTRIP = 0X0802,      /*!< \brief EPWM3_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM4_DE_DEMONTRIP = 0X0803,      /*!< \brief EPWM4_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM5_DE_DEMONTRIP = 0X0804,      /*!< \brief EPWM5_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM6_DE_DEMONTRIP = 0X0805,      /*!< \brief EPWM6_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM7_DE_DEMONTRIP = 0X0806,      /*!< \brief EPWM7_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM8_DE_DEMONTRIP = 0X0807,      /*!< \brief EPWM8_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM9_DE_DEMONTRIP = 0X0808,      /*!< \brief EPWM9_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM10_DE_DEMONTRIP = 0X0809,     /*!< \brief EPWM10_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM11_DE_DEMONTRIP = 0X080A,     /*!< \brief EPWM11_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM12_DE_DEMONTRIP = 0X080B,     /*!< \brief EPWM12_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM13_DE_DEMONTRIP = 0X080C,     /*!< \brief EPWM13_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM14_DE_DEMONTRIP = 0X080D,     /*!< \brief EPWM14_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM15_DE_DEMONTRIP = 0X080E,     /*!< \brief EPWM15_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM16_DE_DEMONTRIP = 0X080F,     /*!< \brief EPWM16_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM17_DE_DEMONTRIP = 0X0810,     /*!< \brief EPWM17_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM18_DE_DEMONTRIP = 0X0811,     /*!< \brief EPWM18_DE_DEMONTRIP  */
    CDD_XBAR_EPWM_EPWM1_DE_ACTIVE = 0X0900,         /*!< \brief EPWM1_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM2_DE_ACTIVE = 0X0901,         /*!< \brief EPWM2_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM3_DE_ACTIVE = 0X0902,         /*!< \brief EPWM3_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM4_DE_ACTIVE = 0X0903,         /*!< \brief EPWM4_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM5_DE_ACTIVE = 0X0904,         /*!< \brief EPWM5_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM6_DE_ACTIVE = 0X0905,         /*!< \brief EPWM6_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM7_DE_ACTIVE = 0X0906,         /*!< \brief EPWM7_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM8_DE_ACTIVE = 0X0907,         /*!< \brief EPWM8_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM9_DE_ACTIVE = 0X0908,         /*!< \brief EPWM9_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM10_DE_ACTIVE = 0X0909,        /*!< \brief EPWM10_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM11_DE_ACTIVE = 0X090A,        /*!< \brief EPWM11_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM12_DE_ACTIVE = 0X090B,        /*!< \brief EPWM12_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM13_DE_ACTIVE = 0X090C,        /*!< \brief EPWM13_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM14_DE_ACTIVE = 0X090D,        /*!< \brief EPWM14_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM15_DE_ACTIVE = 0X090E,        /*!< \brief EPWM15_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM16_DE_ACTIVE = 0X090F,        /*!< \brief EPWM16_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM17_DE_ACTIVE = 0X0910,        /*!< \brief EPWM17_DE_ACTIVE  */
    CDD_XBAR_EPWM_EPWM18_DE_ACTIVE = 0X0911,        /*!< \brief EPWM18_DE_ACTIVE  */
} Cdd_Xbar_Epwm_Xbar_Input_LinesType;

/* Design: MCAL-25799 */
/** \brief CLB Crossbar Input Lines */
typedef enum
{
    CDD_XBAR_CLB_CMPSS1_CTRIPH = 0X0000,            /*!< \brief CMPSS1_CTRIPH  */
    CDD_XBAR_CLB_CMPSS1_CTRIPL = 0X0001,            /*!< \brief CMPSS1_CTRIPL  */
    CDD_XBAR_CLB_CMPSS2_CTRIPH = 0X0002,            /*!< \brief CMPSS2_CTRIPH  */
    CDD_XBAR_CLB_CMPSS2_CTRIPL = 0X0003,            /*!< \brief CMPSS2_CTRIPL  */
    CDD_XBAR_CLB_CMPSS3_CTRIPH = 0X0004,            /*!< \brief CMPSS3_CTRIPH  */
    CDD_XBAR_CLB_CMPSS3_CTRIPL = 0X0005,            /*!< \brief CMPSS3_CTRIPL  */
    CDD_XBAR_CLB_CMPSS4_CTRIPH = 0X0006,            /*!< \brief CMPSS4_CTRIPH  */
    CDD_XBAR_CLB_CMPSS4_CTRIPL = 0X0007,            /*!< \brief CMPSS4_CTRIPL  */
    CDD_XBAR_CLB_CMPSS5_CTRIPH = 0X0008,            /*!< \brief CMPSS5_CTRIPH  */
    CDD_XBAR_CLB_CMPSS5_CTRIPL = 0X0009,            /*!< \brief CMPSS5_CTRIPL  */
    CDD_XBAR_CLB_CMPSS6_CTRIPH = 0X000A,            /*!< \brief CMPSS6_CTRIPH  */
    CDD_XBAR_CLB_CMPSS6_CTRIPL = 0X000B,            /*!< \brief CMPSS6_CTRIPL  */
    CDD_XBAR_CLB_CMPSS7_CTRIPH = 0X000C,            /*!< \brief CMPSS7_CTRIPH  */
    CDD_XBAR_CLB_CMPSS7_CTRIPL = 0X000D,            /*!< \brief CMPSS7_CTRIPL  */
    CDD_XBAR_CLB_CMPSS8_CTRIPH = 0X000E,            /*!< \brief CMPSS8_CTRIPH  */
    CDD_XBAR_CLB_CMPSS8_CTRIPL = 0X000F,            /*!< \brief CMPSS8_CTRIPL  */
    CDD_XBAR_CLB_CMPSS9_CTRIPH = 0X0010,            /*!< \brief CMPSS9_CTRIPH  */
    CDD_XBAR_CLB_CMPSS9_CTRIPL = 0X0011,            /*!< \brief CMPSS9_CTRIPL  */
    CDD_XBAR_CLB_CMPSS10_CTRIPH = 0X0012,           /*!< \brief CMPSS10_CTRIPH  */
    CDD_XBAR_CLB_CMPSS10_CTRIPL = 0X0013,           /*!< \brief CMPSS10_CTRIPL  */
    CDD_XBAR_CLB_CMPSS11_CTRIPH = 0X0014,           /*!< \brief CMPSS11_CTRIPH  */
    CDD_XBAR_CLB_CMPSS11_CTRIPL = 0X0015,           /*!< \brief CMPSS11_CTRIPL  */
    CDD_XBAR_CLB_CMPSS12_CTRIPH = 0X0016,           /*!< \brief CMPSS12_CTRIPH  */
    CDD_XBAR_CLB_CMPSS12_CTRIPL = 0X0017,           /*!< \brief CMPSS12_CTRIPL  */
    CDD_XBAR_CLB_SD1FLT1_COMPH = 0X0100,            /*!< \brief SD1FLT1_COMPH  */
    CDD_XBAR_CLB_SD1FLT1_COMPL = 0X0101,            /*!< \brief SD1FLT1_COMPL  */
    CDD_XBAR_CLB_SD1FLT2_COMPH = 0X0102,            /*!< \brief SD1FLT2_COMPH  */
    CDD_XBAR_CLB_SD1FLT2_COMPL = 0X0103,            /*!< \brief SD1FLT2_COMPL  */
    CDD_XBAR_CLB_SD1FLT3_COMPH = 0X0104,            /*!< \brief SD1FLT3_COMPH  */
    CDD_XBAR_CLB_SD1FLT3_COMPL = 0X0105,            /*!< \brief SD1FLT3_COMPL  */
    CDD_XBAR_CLB_SD1FLT4_COMPH = 0X0106,            /*!< \brief SD1FLT4_COMPH  */
    CDD_XBAR_CLB_SD1FLT4_COMPL = 0X0107,            /*!< \brief SD1FLT4_COMPL  */
    CDD_XBAR_CLB_SD2FLT1_COMPH = 0X0108,            /*!< \brief SD2FLT1_COMPH  */
    CDD_XBAR_CLB_SD2FLT1_COMPL = 0X0109,            /*!< \brief SD2FLT1_COMPL  */
    CDD_XBAR_CLB_SD2FLT2_COMPH = 0X010A,            /*!< \brief SD2FLT2_COMPH  */
    CDD_XBAR_CLB_SD2FLT2_COMPL = 0X010B,            /*!< \brief SD2FLT2_COMPL  */
    CDD_XBAR_CLB_SD2FLT3_COMPH = 0X010C,            /*!< \brief SD2FLT3_COMPH  */
    CDD_XBAR_CLB_SD2FLT3_COMPL = 0X010D,            /*!< \brief SD2FLT3_COMPL  */
    CDD_XBAR_CLB_SD2FLT4_COMPH = 0X010E,            /*!< \brief SD2FLT4_COMPH  */
    CDD_XBAR_CLB_SD2FLT4_COMPL = 0X010F,            /*!< \brief SD2FLT4_COMPL  */
    CDD_XBAR_CLB_SD3FLT1_COMPH = 0X0110,            /*!< \brief SD3FLT1_COMPH  */
    CDD_XBAR_CLB_SD3FLT1_COMPL = 0X0111,            /*!< \brief SD3FLT1_COMPL  */
    CDD_XBAR_CLB_SD3FLT2_COMPH = 0X0112,            /*!< \brief SD3FLT2_COMPH  */
    CDD_XBAR_CLB_SD3FLT2_COMPL = 0X0113,            /*!< \brief SD3FLT2_COMPL  */
    CDD_XBAR_CLB_SD3FLT3_COMPH = 0X0114,            /*!< \brief SD3FLT3_COMPH  */
    CDD_XBAR_CLB_SD3FLT3_COMPL = 0X0115,            /*!< \brief SD3FLT3_COMPL  */
    CDD_XBAR_CLB_SD3FLT4_COMPH = 0X0116,            /*!< \brief SD3FLT4_COMPH  */
    CDD_XBAR_CLB_SD3FLT4_COMPL = 0X0117,            /*!< \brief SD3FLT4_COMPL  */
    CDD_XBAR_CLB_SD4FLT1_COMPH = 0X0118,            /*!< \brief SD4FLT1_COMPH  */
    CDD_XBAR_CLB_SD4FLT1_COMPL = 0X0119,            /*!< \brief SD4FLT1_COMPL  */
    CDD_XBAR_CLB_SD4FLT2_COMPH = 0X011A,            /*!< \brief SD4FLT2_COMPH  */
    CDD_XBAR_CLB_SD4FLT2_COMPL = 0X011B,            /*!< \brief SD4FLT2_COMPL  */
    CDD_XBAR_CLB_SD4FLT3_COMPH = 0X011C,            /*!< \brief SD4FLT3_COMPH  */
    CDD_XBAR_CLB_SD4FLT3_COMPL = 0X011D,            /*!< \brief SD4FLT3_COMPL  */
    CDD_XBAR_CLB_SD4FLT4_COMPH = 0X011E,            /*!< \brief SD4FLT4_COMPH  */
    CDD_XBAR_CLB_SD4FLT4_COMPL = 0X011F,            /*!< \brief SD4FLT4_COMPL  */
    CDD_XBAR_CLB_ADCAEVT1 = 0X0200,                 /*!< \brief ADCAEVT1  */
    CDD_XBAR_CLB_ADCAEVT2 = 0X0201,                 /*!< \brief ADCAEVT2  */
    CDD_XBAR_CLB_ADCAEVT3 = 0X0202,                 /*!< \brief ADCAEVT3  */
    CDD_XBAR_CLB_ADCAEVT4 = 0X0203,                 /*!< \brief ADCAEVT4  */
    CDD_XBAR_CLB_ADCBEVT1 = 0X0204,                 /*!< \brief ADCBEVT1  */
    CDD_XBAR_CLB_ADCBEVT2 = 0X0205,                 /*!< \brief ADCBEVT2  */
    CDD_XBAR_CLB_ADCBEVT3 = 0X0206,                 /*!< \brief ADCBEVT3  */
    CDD_XBAR_CLB_ADCBEVT4 = 0X0207,                 /*!< \brief ADCBEVT4  */
    CDD_XBAR_CLB_ADCCEVT1 = 0X0208,                 /*!< \brief ADCCEVT1  */
    CDD_XBAR_CLB_ADCCEVT2 = 0X0209,                 /*!< \brief ADCCEVT2  */
    CDD_XBAR_CLB_ADCCEVT3 = 0X020A,                 /*!< \brief ADCCEVT3  */
    CDD_XBAR_CLB_ADCCEVT4 = 0X020B,                 /*!< \brief ADCCEVT4  */
    CDD_XBAR_CLB_ADCDEVT1 = 0X020C,                 /*!< \brief ADCDEVT1  */
    CDD_XBAR_CLB_ADCDEVT2 = 0X020D,                 /*!< \brief ADCDEVT2  */
    CDD_XBAR_CLB_ADCDEVT3 = 0X020E,                 /*!< \brief ADCDEVT3  */
    CDD_XBAR_CLB_ADCDEVT4 = 0X020F,                 /*!< \brief ADCDEVT4  */
    CDD_XBAR_CLB_ADCEEVT1 = 0X0210,                 /*!< \brief ADCEEVT1  */
    CDD_XBAR_CLB_ADCEEVT2 = 0X0211,                 /*!< \brief ADCEEVT2  */
    CDD_XBAR_CLB_ADCEEVT3 = 0X0212,                 /*!< \brief ADCEEVT3  */
    CDD_XBAR_CLB_ADCEEVT4 = 0X0213,                 /*!< \brief ADCEEVT4  */
    CDD_XBAR_CLB_CPU1_ADCCHECKEVT1 = 0X0214,        /*!< \brief CPU1_ADCCHECKEVT1  */
    CDD_XBAR_CLB_CPU1_ADCCHECKEVT2 = 0X0215,        /*!< \brief CPU1_ADCCHECKEVT2  */
    CDD_XBAR_CLB_CPU1_ADCCHECKEVT3 = 0X0216,        /*!< \brief CPU1_ADCCHECKEVT3  */
    CDD_XBAR_CLB_CPU1_ADCCHECKEVT4 = 0X0217,        /*!< \brief CPU1_ADCCHECKEVT4  */
    CDD_XBAR_CLB_CPU2_ADCCHECKEVT1 = 0X0218,        /*!< \brief CPU2_ADCCHECKEVT1  */
    CDD_XBAR_CLB_CPU2_ADCCHECKEVT2 = 0X0219,        /*!< \brief CPU2_ADCCHECKEVT2  */
    CDD_XBAR_CLB_CPU2_ADCCHECKEVT3 = 0X021A,        /*!< \brief CPU2_ADCCHECKEVT3  */
    CDD_XBAR_CLB_CPU2_ADCCHECKEVT4 = 0X021B,        /*!< \brief CPU2_ADCCHECKEVT4  */
    CDD_XBAR_CLB_CPU3_ADCCHECKEVT1 = 0X021C,        /*!< \brief CPU3_ADCCHECKEVT1  */
    CDD_XBAR_CLB_CPU3_ADCCHECKEVT2 = 0X021D,        /*!< \brief CPU3_ADCCHECKEVT2  */
    CDD_XBAR_CLB_CPU3_ADCCHECKEVT3 = 0X021E,        /*!< \brief CPU3_ADCCHECKEVT3  */
    CDD_XBAR_CLB_CPU3_ADCCHECKEVT4 = 0X021F,        /*!< \brief CPU3_ADCCHECKEVT4  */
    CDD_XBAR_CLB_INPUTXBAR1 = 0X0300,               /*!< \brief INPUTXBAR1  */
    CDD_XBAR_CLB_INPUTXBAR2 = 0X0301,               /*!< \brief INPUTXBAR2  */
    CDD_XBAR_CLB_INPUTXBAR3 = 0X0302,               /*!< \brief INPUTXBAR3  */
    CDD_XBAR_CLB_INPUTXBAR4 = 0X0303,               /*!< \brief INPUTXBAR4  */
    CDD_XBAR_CLB_INPUTXBAR5 = 0X0304,               /*!< \brief INPUTXBAR5  */
    CDD_XBAR_CLB_INPUTXBAR6 = 0X0305,               /*!< \brief INPUTXBAR6  */
    CDD_XBAR_CLB_INPUTXBAR7 = 0X0306,               /*!< \brief INPUTXBAR7  */
    CDD_XBAR_CLB_INPUTXBAR8 = 0X0307,               /*!< \brief INPUTXBAR8  */
    CDD_XBAR_CLB_INPUTXBAR9 = 0X0308,               /*!< \brief INPUTXBAR9  */
    CDD_XBAR_CLB_INPUTXBAR10 = 0X0309,              /*!< \brief INPUTXBAR10  */
    CDD_XBAR_CLB_INPUTXBAR11 = 0X030A,              /*!< \brief INPUTXBAR11  */
    CDD_XBAR_CLB_INPUTXBAR12 = 0X030B,              /*!< \brief INPUTXBAR12  */
    CDD_XBAR_CLB_INPUTXBAR13 = 0X030C,              /*!< \brief INPUTXBAR13  */
    CDD_XBAR_CLB_INPUTXBAR14 = 0X030D,              /*!< \brief INPUTXBAR14  */
    CDD_XBAR_CLB_INPUTXBAR15 = 0X030E,              /*!< \brief INPUTXBAR15  */
    CDD_XBAR_CLB_INPUTXBAR16 = 0X030F,              /*!< \brief INPUTXBAR16  */
    CDD_XBAR_CLB_INPUTXBAR17 = 0X0310,              /*!< \brief INPUTXBAR17  */
    CDD_XBAR_CLB_INPUTXBAR18 = 0X0311,              /*!< \brief INPUTXBAR18  */
    CDD_XBAR_CLB_INPUTXBAR19 = 0X0312,              /*!< \brief INPUTXBAR19  */
    CDD_XBAR_CLB_INPUTXBAR20 = 0X0313,              /*!< \brief INPUTXBAR20  */
    CDD_XBAR_CLB_INPUTXBAR21 = 0X0314,              /*!< \brief INPUTXBAR21  */
    CDD_XBAR_CLB_INPUTXBAR22 = 0X0315,              /*!< \brief INPUTXBAR22  */
    CDD_XBAR_CLB_INPUTXBAR23 = 0X0316,              /*!< \brief INPUTXBAR23  */
    CDD_XBAR_CLB_INPUTXBAR24 = 0X0317,              /*!< \brief INPUTXBAR24  */
    CDD_XBAR_CLB_INPUTXBAR25 = 0X0318,              /*!< \brief INPUTXBAR25  */
    CDD_XBAR_CLB_INPUTXBAR26 = 0X0319,              /*!< \brief INPUTXBAR26  */
    CDD_XBAR_CLB_INPUTXBAR27 = 0X031A,              /*!< \brief INPUTXBAR27  */
    CDD_XBAR_CLB_INPUTXBAR28 = 0X031B,              /*!< \brief INPUTXBAR28  */
    CDD_XBAR_CLB_INPUTXBAR29 = 0X031C,              /*!< \brief INPUTXBAR29  */
    CDD_XBAR_CLB_INPUTXBAR30 = 0X031D,              /*!< \brief INPUTXBAR30  */
    CDD_XBAR_CLB_INPUTXBAR31 = 0X031E,              /*!< \brief INPUTXBAR31  */
    CDD_XBAR_CLB_INPUTXBAR32 = 0X031F,              /*!< \brief INPUTXBAR32  */
    CDD_XBAR_CLB_CLB1_OUT12 = 0X0400,               /*!< \brief CLB1_OUT12  */
    CDD_XBAR_CLB_CLB1_OUT13 = 0X0401,               /*!< \brief CLB1_OUT13  */
    CDD_XBAR_CLB_CLB2_OUT12 = 0X0402,               /*!< \brief CLB2_OUT12  */
    CDD_XBAR_CLB_CLB2_OUT13 = 0X0403,               /*!< \brief CLB2_OUT13  */
    CDD_XBAR_CLB_CLB3_OUT12 = 0X0404,               /*!< \brief CLB3_OUT12  */
    CDD_XBAR_CLB_CLB3_OUT13 = 0X0405,               /*!< \brief CLB3_OUT13  */
    CDD_XBAR_CLB_CLB4_OUT12 = 0X0406,               /*!< \brief CLB4_OUT12  */
    CDD_XBAR_CLB_CLB4_OUT13 = 0X0407,               /*!< \brief CLB4_OUT13  */
    CDD_XBAR_CLB_CLB5_OUT12 = 0X0408,               /*!< \brief CLB5_OUT12  */
    CDD_XBAR_CLB_CLB5_OUT13 = 0X0409,               /*!< \brief CLB5_OUT13  */
    CDD_XBAR_CLB_CLB6_OUT12 = 0X040A,               /*!< \brief CLB6_OUT12  */
    CDD_XBAR_CLB_CLB6_OUT13 = 0X040B,               /*!< \brief CLB6_OUT13  */
    CDD_XBAR_CLB_FSIRXA_TRIG1 = 0X0410,             /*!< \brief FSIRXA_TRIG1  */
    CDD_XBAR_CLB_FSIRXB_TRIG1 = 0X0411,             /*!< \brief FSIRXB_TRIG1  */
    CDD_XBAR_CLB_FSIRXC_TRIG1 = 0X0412,             /*!< \brief FSIRXC_TRIG1  */
    CDD_XBAR_CLB_FSIRXD_TRIG1 = 0X0413,             /*!< \brief FSIRXD_TRIG1  */
    CDD_XBAR_CLB_FSIRXA_TRIG2 = 0X0414,             /*!< \brief FSIRXA_TRIG2  */
    CDD_XBAR_CLB_FSIRXB_TRIG2 = 0X0415,             /*!< \brief FSIRXB_TRIG2  */
    CDD_XBAR_CLB_FSIRXC_TRIG2 = 0X0416,             /*!< \brief FSIRXC_TRIG2  */
    CDD_XBAR_CLB_FSIRXD_TRIG2 = 0X0417,             /*!< \brief FSIRXD_TRIG2  */
    CDD_XBAR_CLB_FSIRXA_TRIG3 = 0X0418,             /*!< \brief FSIRXA_TRIG3  */
    CDD_XBAR_CLB_FSIRXB_TRIG3 = 0X0419,             /*!< \brief FSIRXB_TRIG3  */
    CDD_XBAR_CLB_FSIRXC_TRIG3 = 0X041A,             /*!< \brief FSIRXC_TRIG3  */
    CDD_XBAR_CLB_FSIRXD_TRIG3 = 0X041B,             /*!< \brief FSIRXD_TRIG3  */
    CDD_XBAR_CLB_ECAT_SYNC0 = 0X041E,               /*!< \brief ECAT_SYNC0  */
    CDD_XBAR_CLB_ECAT_SYNC1 = 0X041F,               /*!< \brief ECAT_SYNC1  */
    CDD_XBAR_CLB_ECAP1_OUT = 0X0500,                /*!< \brief ECAP1_OUT  */
    CDD_XBAR_CLB_ECAP2_OUT = 0X0501,                /*!< \brief ECAP2_OUT  */
    CDD_XBAR_CLB_ECAP3_OUT = 0X0502,                /*!< \brief ECAP3_OUT  */
    CDD_XBAR_CLB_ECAP4_OUT = 0X0503,                /*!< \brief ECAP4_OUT  */
    CDD_XBAR_CLB_ECAP5_OUT = 0X0504,                /*!< \brief ECAP5_OUT  */
    CDD_XBAR_CLB_ECAP6_OUT = 0X0505,                /*!< \brief ECAP6_OUT  */
    CDD_XBAR_CLB_ECAP1_TRIPOUT = 0X0508,            /*!< \brief ECAP1_TRIPOUT  */
    CDD_XBAR_CLB_ECAP2_TRIPOUT = 0X0509,            /*!< \brief ECAP2_TRIPOUT  */
    CDD_XBAR_CLB_ECAP3_TRIPOUT = 0X050A,            /*!< \brief ECAP3_TRIPOUT  */
    CDD_XBAR_CLB_ECAP4_TRIPOUT = 0X050B,            /*!< \brief ECAP4_TRIPOUT  */
    CDD_XBAR_CLB_ECAP5_TRIPOUT = 0X050C,            /*!< \brief ECAP5_TRIPOUT  */
    CDD_XBAR_CLB_ECAP6_TRIPOUT = 0X050D,            /*!< \brief ECAP6_TRIPOUT  */
    CDD_XBAR_CLB_ADCSOCA = 0X0510,                  /*!< \brief ADCSOCA  */
    CDD_XBAR_CLB_ADCSOCB = 0X0511,                  /*!< \brief ADCSOCB  */
    CDD_XBAR_CLB_ESM_GEN_EVENT = 0X0512,            /*!< \brief ESM_GEN_EVENT  */
    CDD_XBAR_CLB_EXTSYNCOUT = 0X0513,               /*!< \brief EXTSYNCOUT  */
    CDD_XBAR_CLB_MCANA_FEVT0 = 0X0600,              /*!< \brief MCANA_FEVT0  */
    CDD_XBAR_CLB_MCANA_FEVT1 = 0X0601,              /*!< \brief MCANA_FEVT1  */
    CDD_XBAR_CLB_MCANA_FEVT2 = 0X0602,              /*!< \brief MCANA_FEVT2  */
    CDD_XBAR_CLB_MCANB_FEVT0 = 0X0603,              /*!< \brief MCANB_FEVT0  */
    CDD_XBAR_CLB_MCANB_FEVT1 = 0X0604,              /*!< \brief MCANB_FEVT1  */
    CDD_XBAR_CLB_MCANB_FEVT2 = 0X0605,              /*!< \brief MCANB_FEVT2  */
    CDD_XBAR_CLB_MCANC_FEVT0 = 0X0606,              /*!< \brief MCANC_FEVT0  */
    CDD_XBAR_CLB_MCANC_FEVT1 = 0X0607,              /*!< \brief MCANC_FEVT1  */
    CDD_XBAR_CLB_MCANC_FEVT2 = 0X0608,              /*!< \brief MCANC_FEVT2  */
    CDD_XBAR_CLB_MCAND_FEVT0 = 0X0609,              /*!< \brief MCAND_FEVT0  */
    CDD_XBAR_CLB_MCAND_FEVT1 = 0X060A,              /*!< \brief MCAND_FEVT1  */
    CDD_XBAR_CLB_MCAND_FEVT2 = 0X060B,              /*!< \brief MCAND_FEVT2  */
    CDD_XBAR_CLB_MCANE_FEVT0 = 0X060C,              /*!< \brief MCANE_FEVT0  */
    CDD_XBAR_CLB_MCANE_FEVT1 = 0X060D,              /*!< \brief MCANE_FEVT1  */
    CDD_XBAR_CLB_MCANE_FEVT2 = 0X060E,              /*!< \brief MCANE_FEVT2  */
    CDD_XBAR_CLB_MCANF_FEVT0 = 0X060F,              /*!< \brief MCANF_FEVT0  */
    CDD_XBAR_CLB_MCANF_FEVT1 = 0X0610,              /*!< \brief MCANF_FEVT1  */
    CDD_XBAR_CLB_MCANF_FEVT2 = 0X0611,              /*!< \brief MCANF_FEVT2  */
    CDD_XBAR_CLB_CPU1_ERAD_EVT8 = 0X0614,           /*!< \brief CPU1_ERAD_EVT8  */
    CDD_XBAR_CLB_CPU1_ERAD_EVT9 = 0X0615,           /*!< \brief CPU1_ERAD_EVT9  */
    CDD_XBAR_CLB_CPU1_ERAD_EVT10 = 0X0616,          /*!< \brief CPU1_ERAD_EVT10  */
    CDD_XBAR_CLB_CPU1_ERAD_EVT11 = 0X0617,          /*!< \brief CPU1_ERAD_EVT11  */
    CDD_XBAR_CLB_CPU2_ERAD_EVT8 = 0X0618,           /*!< \brief CPU2_ERAD_EVT8  */
    CDD_XBAR_CLB_CPU2_ERAD_EVT9 = 0X0619,           /*!< \brief CPU2_ERAD_EVT9  */
    CDD_XBAR_CLB_CPU2_ERAD_EVT10 = 0X061A,          /*!< \brief CPU2_ERAD_EVT10  */
    CDD_XBAR_CLB_CPU2_ERAD_EVT11 = 0X061B,          /*!< \brief CPU2_ERAD_EVT11  */
    CDD_XBAR_CLB_CPU3_ERAD_EVT8 = 0X061C,           /*!< \brief CPU3_ERAD_EVT8  */
    CDD_XBAR_CLB_CPU3_ERAD_EVT9 = 0X061D,           /*!< \brief CPU3_ERAD_EVT9  */
    CDD_XBAR_CLB_CPU3_ERAD_EVT10 = 0X061E,          /*!< \brief CPU3_ERAD_EVT10  */
    CDD_XBAR_CLB_CPU3_ERAD_EVT11 = 0X061F,          /*!< \brief CPU3_ERAD_EVT11  */
    CDD_XBAR_CLB_WADI1OUT0 = 0X0700,                /*!< \brief WADI1OUT0  */
    CDD_XBAR_CLB_WADI1OUT1 = 0X0701,                /*!< \brief WADI1OUT1  */
    CDD_XBAR_CLB_WADI1OUT2 = 0X0702,                /*!< \brief WADI1OUT2  */
    CDD_XBAR_CLB_WADI1OUT3 = 0X0703,                /*!< \brief WADI1OUT3  */
    CDD_XBAR_CLB_WADI1OUT4 = 0X0704,                /*!< \brief WADI1OUT4  */
    CDD_XBAR_CLB_WADI1OUT5 = 0X0705,                /*!< \brief WADI1OUT5  */
    CDD_XBAR_CLB_WADI1OUT6 = 0X0706,                /*!< \brief WADI1OUT6  */
    CDD_XBAR_CLB_WADI1OUT7 = 0X0707,                /*!< \brief WADI1OUT7  */
    CDD_XBAR_CLB_WADI2OUT0 = 0X0708,                /*!< \brief WADI1OUT0  */
    CDD_XBAR_CLB_WADI2OUT1 = 0X0709,                /*!< \brief WADI1OUT1  */
    CDD_XBAR_CLB_WADI2OUT2 = 0X070A,                /*!< \brief WADI1OUT2  */
    CDD_XBAR_CLB_WADI2OUT3 = 0X070B,                /*!< \brief WADI1OUT3  */
    CDD_XBAR_CLB_WADI2OUT4 = 0X070C,                /*!< \brief WADI1OUT4  */
    CDD_XBAR_CLB_WADI2OUT5 = 0X070D,                /*!< \brief WADI1OUT5  */
    CDD_XBAR_CLB_WADI2OUT6 = 0X070E,                /*!< \brief WADI1OUT6  */
    CDD_XBAR_CLB_WADI2OUT7 = 0X070F,                /*!< \brief WADI1OUT7  */
} Cdd_Xbar_Clb_Xbar_Input_LinesType;

/* Design: MCAL-25800 */
/** \brief MinDB Crossbar Input Lines */
typedef enum
{
    CDD_XBAR_MINDB_EPWM1A_DB_NO_HR = 0X0000,       /*!< \brief EPWM1A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM2A_DB_NO_HR = 0X0001,       /*!< \brief EPWM2A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM3A_DB_NO_HR = 0X0002,       /*!< \brief EPWM3A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM4A_DB_NO_HR = 0X0003,       /*!< \brief EPWM4A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM5A_DB_NO_HR = 0X0004,       /*!< \brief EPWM5A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM6A_DB_NO_HR = 0X0005,       /*!< \brief EPWM6A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM7A_DB_NO_HR = 0X0006,       /*!< \brief EPWM7A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM8A_DB_NO_HR = 0X0007,       /*!< \brief EPWM8A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM9A_DB_NO_HR = 0X0008,       /*!< \brief EPWM9A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM10A_DB_NO_HR = 0X0009,      /*!< \brief EPWM10A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM11A_DB_NO_HR = 0X000A,      /*!< \brief EPWM11A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM12A_DB_NO_HR = 0X000B,      /*!< \brief EPWM12A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM13A_DB_NO_HR = 0X000C,      /*!< \brief EPWM13A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM14A_DB_NO_HR = 0X000D,      /*!< \brief EPWM14A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM15A_DB_NO_HR = 0X000E,      /*!< \brief EPWM15A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM16A_DB_NO_HR = 0X000F,      /*!< \brief EPWM16A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM17A_DB_NO_HR = 0X0010,      /*!< \brief EPWM17A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM18A_DB_NO_HR = 0X0011,      /*!< \brief EPWM18A_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM1B_DB_NO_HR = 0X0100,       /*!< \brief EPWM1B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM2B_DB_NO_HR = 0X0101,       /*!< \brief EPWM2B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM3B_DB_NO_HR = 0X0102,       /*!< \brief EPWM3B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM4B_DB_NO_HR = 0X0103,       /*!< \brief EPWM4B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM5B_DB_NO_HR = 0X0104,       /*!< \brief EPWM5B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM6B_DB_NO_HR = 0X0105,       /*!< \brief EPWM6B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM7B_DB_NO_HR = 0X0106,       /*!< \brief EPWM7B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM8B_DB_NO_HR = 0X0107,       /*!< \brief EPWM8B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM9B_DB_NO_HR = 0X0108,       /*!< \brief EPWM9B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM10B_DB_NO_HR = 0X0109,      /*!< \brief EPWM10B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM11B_DB_NO_HR = 0X010A,      /*!< \brief EPWM11B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM12B_DB_NO_HR = 0X010B,      /*!< \brief EPWM12B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM13B_DB_NO_HR = 0X010C,      /*!< \brief EPWM13B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM14B_DB_NO_HR = 0X010D,      /*!< \brief EPWM14B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM15B_DB_NO_HR = 0X010E,      /*!< \brief EPWM15B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM16B_DB_NO_HR = 0X010F,      /*!< \brief EPWM16B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM17B_DB_NO_HR = 0X0110,      /*!< \brief EPWM17B_DB_NO_HR  */
    CDD_XBAR_MINDB_EPWM18B_DB_NO_HR = 0X0111,      /*!< \brief EPWM18B_DB_NO_HR  */
    CDD_XBAR_MINDB_CLB1_OUT12 = 0X0200,            /*!< \brief CLB1_OUT12  */
    CDD_XBAR_MINDB_CLB1_OUT13 = 0X0201,            /*!< \brief CLB1_OUT13  */
    CDD_XBAR_MINDB_CLB2_OUT12 = 0X0202,            /*!< \brief CLB2_OUT12  */
    CDD_XBAR_MINDB_CLB2_OUT13 = 0X0203,            /*!< \brief CLB2_OUT13  */
    CDD_XBAR_MINDB_CLB3_OUT12 = 0X0204,            /*!< \brief CLB3_OUT12  */
    CDD_XBAR_MINDB_CLB3_OUT13 = 0X0205,            /*!< \brief CLB3_OUT13  */
    CDD_XBAR_MINDB_CLB4_OUT12 = 0X0206,            /*!< \brief CLB4_OUT12  */
    CDD_XBAR_MINDB_CLB4_OUT13 = 0X0207,            /*!< \brief CLB4_OUT13  */
    CDD_XBAR_MINDB_CLB5_OUT12 = 0X0208,            /*!< \brief CLB5_OUT12  */
    CDD_XBAR_MINDB_CLB5_OUT13 = 0X0209,            /*!< \brief CLB5_OUT13  */
    CDD_XBAR_MINDB_CLB6_OUT12 = 0X020A,            /*!< \brief CLB6_OUT12  */
    CDD_XBAR_MINDB_CLB6_OUT13 = 0X020B,            /*!< \brief CLB6_OUT13  */
} Cdd_Xbar_Mindb_Xbar_Input_LinesType;

/* Design: MCAL-25801 */
/** \brief ICL Crossbar Input Lines */
typedef enum
{
    CDD_XBAR_ICL_EPWM1A_MINDB = 0X0000,           /*!< \brief EPWM1A_MINDB  */
    CDD_XBAR_ICL_EPWM2A_MINDB = 0X0001,           /*!< \brief EPWM2A_MINDB  */
    CDD_XBAR_ICL_EPWM3A_MINDB = 0X0002,           /*!< \brief EPWM3A_MINDB  */
    CDD_XBAR_ICL_EPWM4A_MINDB = 0X0003,           /*!< \brief EPWM4A_MINDB  */
    CDD_XBAR_ICL_EPWM5A_MINDB = 0X0004,           /*!< \brief EPWM5A_MINDB  */
    CDD_XBAR_ICL_EPWM6A_MINDB = 0X0005,           /*!< \brief EPWM6A_MINDB  */
    CDD_XBAR_ICL_EPWM7A_MINDB = 0X0006,           /*!< \brief EPWM7A_MINDB  */
    CDD_XBAR_ICL_EPWM8A_MINDB = 0X0007,           /*!< \brief EPWM8A_MINDB  */
    CDD_XBAR_ICL_EPWM9A_MINDB = 0X0008,           /*!< \brief EPWM9A_MINDB  */
    CDD_XBAR_ICL_EPWM10A_MINDB = 0X0009,          /*!< \brief EPWM10A_MINDB  */
    CDD_XBAR_ICL_EPWM11A_MINDB = 0X000A,          /*!< \brief EPWM11A_MINDB  */
    CDD_XBAR_ICL_EPWM12A_MINDB = 0X000B,          /*!< \brief EPWM12A_MINDB  */
    CDD_XBAR_ICL_EPWM13A_MINDB = 0X000C,          /*!< \brief EPWM13A_MINDB  */
    CDD_XBAR_ICL_EPWM14A_MINDB = 0X000D,          /*!< \brief EPWM14A_MINDB  */
    CDD_XBAR_ICL_EPWM15A_MINDB = 0X000E,          /*!< \brief EPWM15A_MINDB  */
    CDD_XBAR_ICL_EPWM16A_MINDB = 0X000F,          /*!< \brief EPWM16A_MINDB  */
    CDD_XBAR_ICL_EPWM17A_MINDB = 0X0010,          /*!< \brief EPWM17A_MINDB  */
    CDD_XBAR_ICL_EPWM18A_MINDB = 0X0011,          /*!< \brief EPWM18A_MINDB  */
    CDD_XBAR_ICL_EPWM1B_MINDB = 0X0100,           /*!< \brief EPWM1B_MINDB  */
    CDD_XBAR_ICL_EPWM2B_MINDB = 0X0101,           /*!< \brief EPWM2B_MINDB  */
    CDD_XBAR_ICL_EPWM3B_MINDB = 0X0102,           /*!< \brief EPWM3B_MINDB  */
    CDD_XBAR_ICL_EPWM4B_MINDB = 0X0103,           /*!< \brief EPWM4B_MINDB  */
    CDD_XBAR_ICL_EPWM5B_MINDB = 0X0104,           /*!< \brief EPWM5B_MINDB  */
    CDD_XBAR_ICL_EPWM6B_MINDB = 0X0105,           /*!< \brief EPWM6B_MINDB  */
    CDD_XBAR_ICL_EPWM7B_MINDB = 0X0106,           /*!< \brief EPWM7B_MINDB  */
    CDD_XBAR_ICL_EPWM8B_MINDB = 0X0107,           /*!< \brief EPWM8B_MINDB  */
    CDD_XBAR_ICL_EPWM9B_MINDB = 0X0108,           /*!< \brief EPWM9B_MINDB  */
    CDD_XBAR_ICL_EPWM10B_MINDB = 0X0109,          /*!< \brief EPWM10B_MINDB  */
    CDD_XBAR_ICL_EPWM11B_MINDB = 0X010A,          /*!< \brief EPWM11B_MINDB  */
    CDD_XBAR_ICL_EPWM12B_MINDB = 0X010B,          /*!< \brief EPWM12B_MINDB  */
    CDD_XBAR_ICL_EPWM13B_MINDB = 0X010C,          /*!< \brief EPWM13B_MINDB  */
    CDD_XBAR_ICL_EPWM14B_MINDB = 0X010D,          /*!< \brief EPWM14B_MINDB  */
    CDD_XBAR_ICL_EPWM15B_MINDB = 0X010E,          /*!< \brief EPWM15B_MINDB  */
    CDD_XBAR_ICL_EPWM16B_MINDB = 0X010F,          /*!< \brief EPWM16B_MINDB  */
    CDD_XBAR_ICL_EPWM17B_MINDB = 0X0110,          /*!< \brief EPWM17B_MINDB  */
    CDD_XBAR_ICL_EPWM18B_MINDB = 0X0111,          /*!< \brief EPWM18B_MINDB  */
    CDD_XBAR_ICL_CLB1_OUT12 = 0X0200,             /*!< \brief CLB1_OUT12  */
    CDD_XBAR_ICL_CLB1_OUT13 = 0X0201,             /*!< \brief CLB1_OUT13  */
    CDD_XBAR_ICL_CLB2_OUT12 = 0X0202,             /*!< \brief CLB2_OUT12  */
    CDD_XBAR_ICL_CLB2_OUT13 = 0X0203,             /*!< \brief CLB2_OUT13  */
    CDD_XBAR_ICL_CLB3_OUT12 = 0X0204,             /*!< \brief CLB3_OUT12  */
    CDD_XBAR_ICL_CLB3_OUT13 = 0X0205,             /*!< \brief CLB3_OUT13  */
    CDD_XBAR_ICL_CLB4_OUT12 = 0X0206,             /*!< \brief CLB4_OUT12  */
    CDD_XBAR_ICL_CLB4_OUT13 = 0X0207,             /*!< \brief CLB4_OUT13  */
    CDD_XBAR_ICL_CLB5_OUT12 = 0X0208,             /*!< \brief CLB5_OUT12  */
    CDD_XBAR_ICL_CLB5_OUT13 = 0X0209,             /*!< \brief CLB5_OUT13  */
    CDD_XBAR_ICL_CLB6_OUT12 = 0X020A,             /*!< \brief CLB6_OUT12  */
    CDD_XBAR_ICL_CLB6_OUT13 = 0X020B,             /*!< \brief CLB6_OUT13  */
} Cdd_Xbar_Icl_Xbar_Input_LinesType;

/* Design: MCAL-28161 */
/** \brief Crossbar input flags */
typedef enum
{
    CDD_XBAR_INPUT_FLG_CMPSS1_CTRIPL  = 0x0100U,            /*!< \brief CMPSS1_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS1_CTRIPH  = 0x0101U,            /*!< \brief CMPSS1_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS2_CTRIPL  = 0x0102U,            /*!< \brief CMPSS2_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS2_CTRIPH  = 0x0103U,            /*!< \brief CMPSS2_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS3_CTRIPL  = 0x0104U,            /*!< \brief CMPSS3_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS3_CTRIPH  = 0x0105U,            /*!< \brief CMPSS3_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS4_CTRIPL  = 0x0106U,            /*!< \brief CMPSS4_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS4_CTRIPH  = 0x0107U,            /*!< \brief CMPSS4_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS5_CTRIPL  = 0x0108U,            /*!< \brief CMPSS5_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS5_CTRIPH  = 0x0109U,            /*!< \brief CMPSS5_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS6_CTRIPL  = 0x010AU,            /*!< \brief CMPSS6_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS6_CTRIPH  = 0x010BU,            /*!< \brief CMPSS6_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS7_CTRIPL  = 0x010CU,            /*!< \brief CMPSS7_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS7_CTRIPH  = 0x010DU,            /*!< \brief CMPSS7_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS8_CTRIPL  = 0x010EU,            /*!< \brief CMPSS8_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS8_CTRIPH  = 0x010FU,            /*!< \brief CMPSS8_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS9_CTRIPH  = 0x0110U,            /*!< \brief CMPSS9_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS9_CTRIPL  = 0x0111U,            /*!< \brief CMPSS9_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS10_CTRIPH  = 0x0112U,           /*!< \brief CMPSS10_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS10_CTRIPL  = 0x0113U,           /*!< \brief CMPSS10_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS11_CTRIPH  = 0x0114U,           /*!< \brief CMPSS11_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS11_CTRIPL  = 0x0115U,           /*!< \brief CMPSS11_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS12_CTRIPH  = 0x0116U,           /*!< \brief CMPSS12_CTRIPH  */
    CDD_XBAR_INPUT_FLG_CMPSS12_CTRIPL  = 0x0117U,           /*!< \brief CMPSS12_CTRIPL  */
    CDD_XBAR_INPUT_FLG_CMPSS1_CTRIPOUTL  = 0x0200U,         /*!< \brief CMPSS1_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS1_CTRIPOUTH  = 0x0201U,         /*!< \brief CMPSS1_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS2_CTRIPOUTL  = 0x0202U,         /*!< \brief CMPSS2_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS2_CTRIPOUTH  = 0x0203U,         /*!< \brief CMPSS2_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS3_CTRIPOUTL  = 0x0204U,         /*!< \brief CMPSS3_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS3_CTRIPOUTH  = 0x0205U,         /*!< \brief CMPSS3_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS4_CTRIPOUTL  = 0x0206U,         /*!< \brief CMPSS4_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS4_CTRIPOUTH  = 0x0207U,         /*!< \brief CMPSS4_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS5_CTRIPOUTL  = 0x0208U,         /*!< \brief CMPSS5_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS5_CTRIPOUTH  = 0x0209U,         /*!< \brief CMPSS5_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS6_CTRIPOUTL  = 0x020AU,         /*!< \brief CMPSS6_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS6_CTRIPOUTH  = 0x020BU,         /*!< \brief CMPSS6_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS7_CTRIPOUTL  = 0x020CU,         /*!< \brief CMPSS7_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS7_CTRIPOUTH  = 0x020DU,         /*!< \brief CMPSS7_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS8_CTRIPOUTL  = 0x020EU,         /*!< \brief CMPSS8_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS8_CTRIPOUTH  = 0x020FU,         /*!< \brief CMPSS8_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS9_CTRIPOUTH  = 0x0210U,         /*!< \brief CMPSS9_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS9_CTRIPOUTL  = 0x0211U,         /*!< \brief CMPSS9_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS10_CTRIPOUTH  = 0x0212U,        /*!< \brief CMPSS10_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS10_CTRIPOUTL  = 0x0213U,        /*!< \brief CMPSS10_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS11_CTRIPOUTH  = 0x0214U,        /*!< \brief CMPSS11_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS11_CTRIPOUTL  = 0x0215U,        /*!< \brief CMPSS11_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_CMPSS12_CTRIPOUTH  = 0x0216U,        /*!< \brief CMPSS12_CTRIPOUTH  */
    CDD_XBAR_INPUT_FLG_CMPSS12_CTRIPOUTL  = 0x0217U,        /*!< \brief CMPSS12_CTRIPOUTL  */
    CDD_XBAR_INPUT_FLG_SD1FLT1_COMPL  = 0x0300U,            /*!< \brief SD1FLT1_COMPL  */
    CDD_XBAR_INPUT_FLG_SD1FLT1_COMPH  = 0x0301U,            /*!< \brief SD1FLT1_COMPH  */
    CDD_XBAR_INPUT_FLG_SD1FLT2_COMPL  = 0x0302U,            /*!< \brief SD1FLT2_COMPL  */
    CDD_XBAR_INPUT_FLG_SD1FLT2_COMPH  = 0x0303U,            /*!< \brief SD1FLT2_COMPH  */
    CDD_XBAR_INPUT_FLG_SD1FLT3_COMPL  = 0x0304U,            /*!< \brief SD1FLT3_COMPL  */
    CDD_XBAR_INPUT_FLG_SD1FLT3_COMPH  = 0x0305U,            /*!< \brief SD1FLT3_COMPH  */
    CDD_XBAR_INPUT_FLG_SD1FLT4_COMPL  = 0x0306U,            /*!< \brief SD1FLT4_COMPL  */
    CDD_XBAR_INPUT_FLG_SD1FLT4_COMPH  = 0x0307U,            /*!< \brief SD1FLT4_COMPH  */
    CDD_XBAR_INPUT_FLG_SD2FLT1_COMPL  = 0x0308U,            /*!< \brief SD2FLT1_COMPL  */
    CDD_XBAR_INPUT_FLG_SD2FLT1_COMPH  = 0x0309U,            /*!< \brief SD2FLT1_COMPH  */
    CDD_XBAR_INPUT_FLG_SD2FLT2_COMPL  = 0x030AU,            /*!< \brief SD2FLT2_COMPL  */
    CDD_XBAR_INPUT_FLG_SD2FLT2_COMPH  = 0x030BU,            /*!< \brief SD2FLT2_COMPH  */
    CDD_XBAR_INPUT_FLG_SD2FLT3_COMPL  = 0x030CU,            /*!< \brief SD2FLT3_COMPL  */
    CDD_XBAR_INPUT_FLG_SD2FLT3_COMPH  = 0x030DU,            /*!< \brief SD2FLT2_COMPH  */
    CDD_XBAR_INPUT_FLG_SD2FLT4_COMPL  = 0x030EU,            /*!< \brief SD2FLT4_COMPL  */
    CDD_XBAR_INPUT_FLG_SD2FLT4_COMPH  = 0x030FU,            /*!< \brief SD2FLT4_COMPH  */
    CDD_XBAR_INPUT_FLG_SD3FLT1_COMPH  = 0x0310U,            /*!< \brief SD3FLT1_COMPH  */
    CDD_XBAR_INPUT_FLG_SD3FLT1_COMPL  = 0x0311U,            /*!< \brief SD3FLT1_COMPL  */
    CDD_XBAR_INPUT_FLG_SD3FLT2_COMPH  = 0x0312U,            /*!< \brief SD3FLT2_COMPH  */
    CDD_XBAR_INPUT_FLG_SD3FLT2_COMPL  = 0x0313U,            /*!< \brief SD3FLT2_COMPL  */
    CDD_XBAR_INPUT_FLG_SD3FLT3_COMPH  = 0x0314U,            /*!< \brief SD3FLT3_COMPH  */
    CDD_XBAR_INPUT_FLG_SD3FLT3_COMPL  = 0x0315U,            /*!< \brief SD3FLT3_COMPL  */
    CDD_XBAR_INPUT_FLG_SD3FLT4_COMPH  = 0x0316U,            /*!< \brief SD3FLT4_COMPH  */
    CDD_XBAR_INPUT_FLG_SD3FLT4_COMPL  = 0x0317U,            /*!< \brief SD3FLT4_COMPL  */
    CDD_XBAR_INPUT_FLG_SD4FLT1_COMPH  = 0x0318U,            /*!< \brief SD4FLT1_COMPH  */
    CDD_XBAR_INPUT_FLG_SD4FLT1_COMPL  = 0x0319U,            /*!< \brief SD4FLT1_COMPL  */
    CDD_XBAR_INPUT_FLG_SD4FLT2_COMPH  = 0x031AU,            /*!< \brief SD4FLT2_COMPH  */
    CDD_XBAR_INPUT_FLG_SD4FLT2_COMPL  = 0x031BU,            /*!< \brief SD4FLT1_COMPL  */
    CDD_XBAR_INPUT_FLG_SD4FLT3_COMPH  = 0x031CU,            /*!< \brief SD4FLT3_COMPH  */
    CDD_XBAR_INPUT_FLG_SD4FLT3_COMPL  = 0x031DU,            /*!< \brief SD4FLT3_COMPL  */
    CDD_XBAR_INPUT_FLG_SD4FLT4_COMPH  = 0x031EU,            /*!< \brief SD4FLT4_COMPH  */
    CDD_XBAR_INPUT_FLG_SD4FLT4_COMPL  = 0x031FU,            /*!< \brief SD4FLT4_COMPL  */
    CDD_XBAR_INPUT_FLG_INPUT1  = 0x0400U,                   /*!< \brief INPUT1  */
    CDD_XBAR_INPUT_FLG_INPUT2  = 0x0401U,                   /*!< \brief INPUT2  */
    CDD_XBAR_INPUT_FLG_INPUT3  = 0x0402U,                   /*!< \brief INPUT3  */
    CDD_XBAR_INPUT_FLG_INPUT4  = 0x0403U,                   /*!< \brief INPUT4  */
    CDD_XBAR_INPUT_FLG_INPUT5  = 0x0404U,                   /*!< \brief INPUT5  */
    CDD_XBAR_INPUT_FLG_INPUT6  = 0x0405U,                   /*!< \brief INPUT6  */
    CDD_XBAR_INPUT_FLG_INPUT7  = 0x0406U,                   /*!< \brief INPUT7  */
    CDD_XBAR_INPUT_FLG_INPUT8  = 0x0407U,                   /*!< \brief INPUT8  */
    CDD_XBAR_INPUT_FLG_INPUT9  = 0x0408U,                   /*!< \brief INPUT9  */
    CDD_XBAR_INPUT_FLG_INPUT10  = 0x0409U,                  /*!< \brief INPUT10  */
    CDD_XBAR_INPUT_FLG_INPUT11  = 0x040AU,                  /*!< \brief INPUT11  */
    CDD_XBAR_INPUT_FLG_INPUT12  = 0x040BU,                  /*!< \brief INPUT12  */
    CDD_XBAR_INPUT_FLG_INPUT13  = 0x040CU,                  /*!< \brief INPUT13  */
    CDD_XBAR_INPUT_FLG_INPUT14  = 0x040DU,                  /*!< \brief INPUT14  */
    CDD_XBAR_INPUT_FLG_INPUT15  = 0x040EU,                  /*!< \brief INPUT15  */
    CDD_XBAR_INPUT_FLG_INPUT16  = 0x040FU,                  /*!< \brief INPUT16  */
    CDD_XBAR_INPUT_FLG_INPUT17  = 0x0410U,                  /*!< \brief INPUT17  */
    CDD_XBAR_INPUT_FLG_INPUT18  = 0x0411U,                  /*!< \brief INPUT18  */
    CDD_XBAR_INPUT_FLG_INPUT19  = 0x0412U,                  /*!< \brief INPUT19  */
    CDD_XBAR_INPUT_FLG_INPUT20  = 0x0413U,                  /*!< \brief INPUT20  */
    CDD_XBAR_INPUT_FLG_INPUT21  = 0x0414U,                  /*!< \brief INPUT21  */
    CDD_XBAR_INPUT_FLG_INPUT22  = 0x0415U,                  /*!< \brief INPUT22  */
    CDD_XBAR_INPUT_FLG_INPUT23  = 0x0416U,                  /*!< \brief INPUT23  */
    CDD_XBAR_INPUT_FLG_INPUT24  = 0x0417U,                  /*!< \brief INPUT24  */
    CDD_XBAR_INPUT_FLG_INPUT25  = 0x0418U,                  /*!< \brief INPUT25  */
    CDD_XBAR_INPUT_FLG_INPUT26  = 0x0419U,                  /*!< \brief INPUT26  */
    CDD_XBAR_INPUT_FLG_INPUT27  = 0x041AU,                  /*!< \brief INPUT27  */
    CDD_XBAR_INPUT_FLG_INPUT28  = 0x041BU,                  /*!< \brief INPUT28  */
    CDD_XBAR_INPUT_FLG_INPUT29  = 0x041CU,                  /*!< \brief INPUT29  */
    CDD_XBAR_INPUT_FLG_INPUT30  = 0x041DU,                  /*!< \brief INPUT30  */
    CDD_XBAR_INPUT_FLG_INPUT31  = 0x041EU,                  /*!< \brief INPUT31  */
    CDD_XBAR_INPUT_FLG_INPUT32  = 0x041FU,                  /*!< \brief INPUT32  */
    CDD_XBAR_INPUT_FLG_ADCAEVT1  = 0x0500U,                 /*!< \brief ADCAEVT1  */
    CDD_XBAR_INPUT_FLG_ADCAEVT2  = 0x0501U,                 /*!< \brief ADCAEVT2  */
    CDD_XBAR_INPUT_FLG_ADCAEVT3  = 0x0502U,                 /*!< \brief ADCAEVT3  */
    CDD_XBAR_INPUT_FLG_ADCAEVT4  = 0x0503U,                 /*!< \brief ADCAEVT4  */
    CDD_XBAR_INPUT_FLG_ADCBEVT1  = 0x0504U,                 /*!< \brief ADCBEVT1  */
    CDD_XBAR_INPUT_FLG_ADCBEVT2  = 0x0505U,                 /*!< \brief ADCBEVT2  */
    CDD_XBAR_INPUT_FLG_ADCBEVT3  = 0x0506U,                 /*!< \brief ADCBEVT3  */
    CDD_XBAR_INPUT_FLG_ADCBEVT4  = 0x0507U,                 /*!< \brief ADCBEVT4  */
    CDD_XBAR_INPUT_FLG_ADCCEVT1  = 0x0508U,                 /*!< \brief ADCCEVT1  */
    CDD_XBAR_INPUT_FLG_ADCCEVT2  = 0x0509U,                 /*!< \brief ADCCEVT2  */
    CDD_XBAR_INPUT_FLG_ADCCEVT3  = 0x050AU,                 /*!< \brief ADCCEVT3  */
    CDD_XBAR_INPUT_FLG_ADCCEVT4  = 0x050BU,                 /*!< \brief ADCCEVT4  */
    CDD_XBAR_INPUT_FLG_ADCDEVT1  = 0x050CU,                 /*!< \brief ADCDEVT1  */
    CDD_XBAR_INPUT_FLG_ADCDEVT2  = 0x050DU,                 /*!< \brief ADCDEVT2  */
    CDD_XBAR_INPUT_FLG_ADCDEVT3  = 0x050EU,                 /*!< \brief ADCDEVT3  */
    CDD_XBAR_INPUT_FLG_ADCDEVT4  = 0x050FU,                 /*!< \brief ADCDEVT4  */
    CDD_XBAR_INPUT_FLG_ADCEEVT1  = 0x0510U,                 /*!< \brief ADCEEVT1  */
    CDD_XBAR_INPUT_FLG_ADCEEVT2  = 0x0511U,                 /*!< \brief ADCEEVT2  */
    CDD_XBAR_INPUT_FLG_ADCEEVT3  = 0x0512U,                 /*!< \brief ADCEEVT3  */
    CDD_XBAR_INPUT_FLG_ADCEEVT4  = 0x0513U,                 /*!< \brief ADCEEVT4  */
    CDD_XBAR_INPUT_FLG_CPU1_ADCCHECKEVT1  = 0x0514U,        /*!< \brief CPU1_ADCCHECKEVT1  */
    CDD_XBAR_INPUT_FLG_CPU1_ADCCHECKEVT2  = 0x0515U,        /*!< \brief CPU1_ADCCHECKEVT2  */
    CDD_XBAR_INPUT_FLG_CPU1_ADCCHECKEVT3  = 0x0516U,        /*!< \brief CPU1_ADCCHECKEVT3  */
    CDD_XBAR_INPUT_FLG_CPU1_ADCCHECKEVT4  = 0x0517U,        /*!< \brief CPU1_ADCCHECKEVT4  */
    CDD_XBAR_INPUT_FLG_CPU2_ADCCHECKEVT1  = 0x0518U,        /*!< \brief CPU2_ADCCHECKEVT1  */
    CDD_XBAR_INPUT_FLG_CPU2_ADCCHECKEVT2  = 0x0519U,        /*!< \brief CPU2_ADCCHECKEVT2  */
    CDD_XBAR_INPUT_FLG_CPU2_ADCCHECKEVT3  = 0x051AU,        /*!< \brief CPU2_ADCCHECKEVT3  */
    CDD_XBAR_INPUT_FLG_CPU2_ADCCHECKEVT4  = 0x051BU,        /*!< \brief CPU2_ADCCHECKEVT4  */
    CDD_XBAR_INPUT_FLG_CPU3_ADCCHECKEVT1  = 0x051CU,        /*!< \brief CPU3_ADCCHECKEVT1  */
    CDD_XBAR_INPUT_FLG_CPU3_ADCCHECKEVT2  = 0x051DU,        /*!< \brief CPU3_ADCCHECKEVT2  */
    CDD_XBAR_INPUT_FLG_CPU3_ADCCHECKEVT3  = 0x051EU,        /*!< \brief CPU3_ADCCHECKEVT3  */
    CDD_XBAR_INPUT_FLG_CPU3_ADCCHECKEVT4  = 0x051FU,        /*!< \brief CPU3_ADCCHECKEVT4  */
    CDD_XBAR_INPUT_FLG_CLB1_OUT4  = 0x0600U,                /*!< \brief CLB1_OUT4  */
    CDD_XBAR_INPUT_FLG_CLB1_OUT5  = 0x0601U,                /*!< \brief CLB1_OUT5  */
    CDD_XBAR_INPUT_FLG_CLB2_OUT4  = 0x0602U,                /*!< \brief CLB2_OUT4  */
    CDD_XBAR_INPUT_FLG_CLB2_OUT5  = 0x0603U,                /*!< \brief CLB2_OUT5  */
    CDD_XBAR_INPUT_FLG_CLB3_OUT4  = 0x0604U,                /*!< \brief CLB3_OUT4  */
    CDD_XBAR_INPUT_FLG_CLB3_OUT5  = 0x0605U,                /*!< \brief CLB3_OUT5  */
    CDD_XBAR_INPUT_FLG_CLB4_OUT4  = 0x0606U,                /*!< \brief CLB4_OUT4  */
    CDD_XBAR_INPUT_FLG_CLB4_OUT5  = 0x0607U,                /*!< \brief CLB4_OUT5  */
    CDD_XBAR_INPUT_FLG_CLB5_OUT4  = 0x0608U,                /*!< \brief CLB5_OUT4  */
    CDD_XBAR_INPUT_FLG_CLB5_OUT5  = 0x0609U,                /*!< \brief CLB5_OUT5  */
    CDD_XBAR_INPUT_FLG_CLB6_OUT4  = 0x060AU,                /*!< \brief CLB6_OUT4  */
    CDD_XBAR_INPUT_FLG_CLB6_OUT5  = 0x060BU,                /*!< \brief CLB6_OUT5  */
    CDD_XBAR_INPUT_FLG_FSIA_RX_TRIG1  = 0x0610U,            /*!< \brief FSIA_RX_TRIG1  */
    CDD_XBAR_INPUT_FLG_FSIB_RX_TRIG1  = 0x0611U,            /*!< \brief FSIB_RX_TRIG1  */
    CDD_XBAR_INPUT_FLG_FSIC_RX_TRIG1  = 0x0612U,            /*!< \brief FSIC_RX_TRIG1  */
    CDD_XBAR_INPUT_FLG_FSID_RX_TRIG1  = 0x0613U,            /*!< \brief FSID_RX_TRIG1  */
    CDD_XBAR_INPUT_FLG_WADI1OUT0  = 0x0616U,                /*!< \brief WADI1OUT0  */
    CDD_XBAR_INPUT_FLG_WADI1OUT1  = 0x0617U,                /*!< \brief WADI1OUT1  */
    CDD_XBAR_INPUT_FLG_WADI1OUT2  = 0x0618U,                /*!< \brief WADI1OUT2  */
    CDD_XBAR_INPUT_FLG_WADI1OUT3  = 0x0619U,                /*!< \brief WADI1OUT3  */
    CDD_XBAR_INPUT_FLG_WADI1OUT4  = 0x061AU,                /*!< \brief WADI1OUT4  */
    CDD_XBAR_INPUT_FLG_WADI1OUT5  = 0x061BU,                /*!< \brief WADI1OUT5  */
    CDD_XBAR_INPUT_FLG_WADI1OUT6  = 0x061CU,                /*!< \brief WADI1OUT6  */
    CDD_XBAR_INPUT_FLG_WADI1OUT7  = 0x061DU,                /*!< \brief WADI1OUT7  */
    CDD_XBAR_INPUT_FLG_ECATSYNC0  = 0x061EU,                /*!< \brief ECATSYNC0  */
    CDD_XBAR_INPUT_FLG_ECATSYNC1  = 0x061FU,                /*!< \brief ECATSYNC1  */
    CDD_XBAR_INPUT_FLG_ECAP1_OUT  = 0x0700U,                /*!< \brief ECAP1_OUT  */
    CDD_XBAR_INPUT_FLG_ECAP2_OUT  = 0x0701U,                /*!< \brief ECAP2_OUT  */
    CDD_XBAR_INPUT_FLG_ECAP3_OUT  = 0x0702U,                /*!< \brief ECAP3_OUT  */
    CDD_XBAR_INPUT_FLG_ECAP4_OUT  = 0x0703U,                /*!< \brief ECAP4_OUT  */
    CDD_XBAR_INPUT_FLG_ECAP5_OUT  = 0x0704U,                /*!< \brief ECAP5_OUT  */
    CDD_XBAR_INPUT_FLG_ECAP6_OUT  = 0x0705U,                /*!< \brief ECAP6_OUT  */
    CDD_XBAR_INPUT_FLG_ECAP1_TRIPOUT  = 0x0708U,            /*!< \brief ECAP1_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_ECAP2_TRIPOUT  = 0x0709U,            /*!< \brief ECAP2_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_ECAP3_TRIPOUT  = 0x070AU,            /*!< \brief ECAP3_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_ECAP4_TRIPOUT  = 0x070BU,            /*!< \brief ECAP4_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_ECAP5_TRIPOUT  = 0x070CU,            /*!< \brief ECAP5_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_ECAP6_TRIPOUT  = 0x070DU,            /*!< \brief ECAP6_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_ADCSOCA  = 0x0710U,                  /*!< \brief ADCSOCA  */
    CDD_XBAR_INPUT_FLG_ADCSOCB  = 0x0711U,                  /*!< \brief ADCSOCB  */
    CDD_XBAR_INPUT_FLG_ESMGENEVT  = 0x0712U,                /*!< \brief ESMGENEVT  */
    CDD_XBAR_INPUT_FLG_EXTSYNCOUT  = 0x0713U,               /*!< \brief EXTSYNCOUT  */
    CDD_XBAR_INPUT_FLG_WADI2OUT0  = 0x0718U,                /*!< \brief WADI2OUT0  */
    CDD_XBAR_INPUT_FLG_WADI2OUT1  = 0x0719U,                /*!< \brief WADI2OUT1  */
    CDD_XBAR_INPUT_FLG_WADI2OUT2  = 0x071AU,                /*!< \brief WADI2OUT2  */
    CDD_XBAR_INPUT_FLG_WADI2OUT3  = 0x071BU,                /*!< \brief WADI2OUT3  */
    CDD_XBAR_INPUT_FLG_WADI2OUT4  = 0x071CU,                /*!< \brief WADI2OUT4  */
    CDD_XBAR_INPUT_FLG_WADI2OUT5  = 0x071DU,                /*!< \brief WADI2OUT5  */
    CDD_XBAR_INPUT_FLG_WADI2OUT6  = 0x071EU,                /*!< \brief WADI2OUT6  */
    CDD_XBAR_INPUT_FLG_WADI2OUT7  = 0x071FU,                /*!< \brief WADI2OUT7  */
    CDD_XBAR_INPUT_FLG_EPWM1_TRIPOUT  = 0x0800U,            /*!< \brief EPWM1_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM2_TRIPOUT  = 0x0801U,            /*!< \brief EPWM2_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM3_TRIPOUT  = 0x0802U,            /*!< \brief EPWM3_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM4_TRIPOUT  = 0x0803U,            /*!< \brief EPWM4_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM5_TRIPOUT  = 0x0804U,            /*!< \brief EPWM5_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM6_TRIPOUT  = 0x0805U,            /*!< \brief EPWM6_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM7_TRIPOUT  = 0x0806U,            /*!< \brief EPWM7_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM8_TRIPOUT  = 0x0807U,            /*!< \brief EPWM8_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM9_TRIPOUT  = 0x0808U,            /*!< \brief EPWM9_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM10_TRIPOUT  = 0x0809U,           /*!< \brief EPWM10_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM11_TRIPOUT  = 0x080AU,           /*!< \brief EPWM11_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM12_TRIPOUT  = 0x080BU,           /*!< \brief EPWM12_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM13_TRIPOUT  = 0x080CU,           /*!< \brief EPWM13_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM14_TRIPOUT  = 0x080DU,           /*!< \brief EPWM14_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM15_TRIPOUT  = 0x080EU,           /*!< \brief EPWM15_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM16_TRIPOUT  = 0x080FU,           /*!< \brief EPWM16_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM17_TRIPOUT  = 0x0810U,           /*!< \brief EPWM17_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM18_TRIPOUT  = 0x0811U,           /*!< \brief EPWM18_TRIPOUT  */
    CDD_XBAR_INPUT_FLG_EPWM1_DEL_TRIP  = 0x0900U,           /*!< \brief EPWM1_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM2_DEL_TRIP  = 0x0901U,           /*!< \brief EPWM2_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM3_DEL_TRIP  = 0x0902U,           /*!< \brief EPWM3_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM4_DEL_TRIP  = 0x0903U,           /*!< \brief EPWM4_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM5_DEL_TRIP  = 0x0904U,           /*!< \brief EPWM5_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM6_DEL_TRIP  = 0x0905U,           /*!< \brief EPWM6_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM7_DEL_TRIP  = 0x0906U,           /*!< \brief EPWM7_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM8_DEL_TRIP  = 0x0907U,           /*!< \brief EPWM8_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM9_DEL_TRIP  = 0x0908U,           /*!< \brief EPWM9_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM10_DEL_TRIP  = 0x0909U,          /*!< \brief EPWM10_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM11_DEL_TRIP  = 0x090AU,          /*!< \brief EPWM11_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM12_DEL_TRIP  = 0x090BU,          /*!< \brief EPWM12_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM13_DEL_TRIP  = 0x090CU,          /*!< \brief EPWM13_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM14_DEL_TRIP  = 0x090DU,          /*!< \brief EPWM14_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM15_DEL_TRIP  = 0x090EU,          /*!< \brief EPWM15_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM16_DEL_TRIP  = 0x090FU,          /*!< \brief EPWM16_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM17_DEL_TRIP  = 0x0910U,          /*!< \brief EPWM17_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM18_DEL_TRIP  = 0x0911U,          /*!< \brief EPWM18_DEL_TRIP  */
    CDD_XBAR_INPUT_FLG_EPWM1_DEL_ACTIVE  = 0x0A00U,         /*!< \brief EPWM1_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM2_DEL_ACTIVE  = 0x0A01U,         /*!< \brief EPWM2_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM3_DEL_ACTIVE  = 0x0A02U,         /*!< \brief EPWM3_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM4_DEL_ACTIVE  = 0x0A03U,         /*!< \brief EPWM4_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM5_DEL_ACTIVE  = 0x0A04U,         /*!< \brief EPWM5_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM6_DEL_ACTIVE  = 0x0A05U,         /*!< \brief EPWM6_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM7_DEL_ACTIVE  = 0x0A06U,         /*!< \brief EPWM7_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM8_DEL_ACTIVE  = 0x0A07U,         /*!< \brief EPWM8_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM9_DEL_ACTIVE  = 0x0A08U,         /*!< \brief EPWM9_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM10_DEL_ACTIVE  = 0x0A09U,        /*!< \brief EPWM10_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM11_DEL_ACTIVE  = 0x0A0AU,        /*!< \brief EPWM11_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM12_DEL_ACTIVE  = 0x0A0BU,        /*!< \brief EPWM12_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM13_DEL_ACTIVE  = 0x0A0CU,        /*!< \brief EPWM13_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM14_DEL_ACTIVE  = 0x0A0DU,        /*!< \brief EPWM14_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM15_DEL_ACTIVE  = 0x0A0EU,        /*!< \brief EPWM15_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM16_DEL_ACTIVE  = 0x0A0FU,        /*!< \brief EPWM16_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM17_DEL_ACTIVE  = 0x0A10U,        /*!< \brief EPWM17_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM18_DEL_ACTIVE  = 0x0A11U,        /*!< \brief EPWM18_DEL_ACTIVE  */
    CDD_XBAR_INPUT_FLG_EPWM1_A0_SCLK  = 0x0B00U,            /*!< \brief EPWM1_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM1_B0_SCLK  = 0x0B01U,            /*!< \brief EPWM1_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM2_A0_SCLK  = 0x0B02U,            /*!< \brief EPWM2_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM2_B0_SCLK  = 0x0B03U,            /*!< \brief EPWM2_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM3_A0_SCLK  = 0x0B04U,            /*!< \brief EPWM3_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM3_B0_SCLK  = 0x0B05U,            /*!< \brief EPWM3_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM4_A0_SCLK  = 0x0B06U,            /*!< \brief EPWM4_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM4_B0_SCLK  = 0x0B07U,            /*!< \brief EPWM4_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM5_A0_SCLK  = 0x0B08U,            /*!< \brief EPWM5_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM5_B0_SCLK  = 0x0B09U,            /*!< \brief EPWM5_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM6_A0_SCLK  = 0x0B0AU,            /*!< \brief EPWM6_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM6_B0_SCLK  = 0x0B0BU,            /*!< \brief EPWM6_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM7_A0_SCLK  = 0x0B0CU,            /*!< \brief EPWM7_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM7_B0_SCLK  = 0x0B0DU,            /*!< \brief EPWM7_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM8_A0_SCLK  = 0x0B0EU,            /*!< \brief EPWM8_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM8_B0_SCLK  = 0x0B0FU,            /*!< \brief EPWM8_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM9_A0_SCLK  = 0x0B10U,            /*!< \brief EPWM9_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM9_B0_SCLK  = 0x0B11U,            /*!< \brief EPWM9_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM10_A0_SCLK  = 0x0B12U,           /*!< \brief EPWM10_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM10_B0_SCLK  = 0x0B13U,           /*!< \brief EPWM10_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM11_A0_SCLK  = 0x0B14U,           /*!< \brief EPWM11_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM11_B0_SCLK  = 0x0B15U,           /*!< \brief EPWM11_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM12_A0_SCLK  = 0x0B16U,           /*!< \brief EPWM12_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM12_B0_SCLK  = 0x0B17U,           /*!< \brief EPWM12_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM13_A0_SCLK  = 0x0B18U,           /*!< \brief EPWM13_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM13_B0_SCLK  = 0x0B19U,           /*!< \brief EPWM13_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM14_A0_SCLK  = 0x0B1AU,           /*!< \brief EPWM14_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM14_B0_SCLK  = 0x0B1BU,           /*!< \brief EPWM14_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM15_A0_SCLK  = 0x0B1CU,           /*!< \brief EPWM15_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM15_B0_SCLK  = 0x0B1DU,           /*!< \brief EPWM15_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM16_A0_SCLK  = 0x0B1EU,           /*!< \brief EPWM16_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM16_B0_SCLK  = 0x0B1FU,           /*!< \brief EPWM16_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM17_A0_SCLK  = 0x0C00U,           /*!< \brief EPWM17_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM17_B0_SCLK  = 0x0C01U,           /*!< \brief EPWM17_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM18_A0_SCLK  = 0x0C02U,           /*!< \brief EPWM18_A0_SCLK  */
    CDD_XBAR_INPUT_FLG_EPWM18_B0_SCLK  = 0x0C03U,           /*!< \brief EPWM18_B0_SCLK  */
    CDD_XBAR_INPUT_FLG_MDL1_OUTA  = 0x0D00U,                /*!< \brief MDL1_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL1_OUTB  = 0x0D01U,                /*!< \brief MDL1_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL2_OUTA  = 0x0D02U,                /*!< \brief MDL2_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL2_OUTB  = 0x0D03U,                /*!< \brief MDL2_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL3_OUTA  = 0x0D04U,                /*!< \brief MDL3_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL3_OUTB  = 0x0D05U,                /*!< \brief MDL3_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL4_OUTA  = 0x0D06U,                /*!< \brief MDL4_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL4_OUTB  = 0x0D07U,                /*!< \brief MDL4_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL5_OUTA  = 0x0D08U,                /*!< \brief MDL5_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL5_OUTB  = 0x0D09U,                /*!< \brief MDL5_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL6_OUTA  = 0x0D0AU,                /*!< \brief MDL6_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL6_OUTB  = 0x0D0BU,                /*!< \brief MDL6_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL7_OUTA  = 0x0D0CU,                /*!< \brief MDL7_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL7_OUTB  = 0x0D0DU,                /*!< \brief MDL7_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL8_OUTA  = 0x0D0EU,                /*!< \brief MDL8_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL8_OUTB  = 0x0D0FU,                /*!< \brief MDL8_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL9_OUTA  = 0x0D10U,                /*!< \brief MDL9_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL9_OUTB  = 0x0D11U,                /*!< \brief MDL9_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL10_OUTA  = 0x0D12U,               /*!< \brief MDL10_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL10_OUTB  = 0x0D13U,               /*!< \brief MDL10_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL11_OUTA  = 0x0D14U,               /*!< \brief MDL11_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL11_OUTB  = 0x0D15U,               /*!< \brief MDL11_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL12_OUTA  = 0x0D16U,               /*!< \brief MDL12_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL12_OUTB  = 0x0D17U,               /*!< \brief MDL12_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL13_OUTA  = 0x0D18U,               /*!< \brief MDL13_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL13_OUTB  = 0x0D19U,               /*!< \brief MDL13_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL14_OUTA  = 0x0D1AU,               /*!< \brief MDL14_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL14_OUTB  = 0x0D1BU,               /*!< \brief MDL14_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL15_OUTA  = 0x0D1CU,               /*!< \brief MDL15_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL15_OUTB  = 0x0D1DU,               /*!< \brief MDL15_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL16_OUTA  = 0x0D1EU,               /*!< \brief MDL16_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL16_OUTB  = 0x0D1FU,               /*!< \brief MDL16_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL17_OUTA  = 0x0E00U,               /*!< \brief MDL17_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL17_OUTB  = 0x0E01U,               /*!< \brief MDL17_OUTB  */
    CDD_XBAR_INPUT_FLG_MDL18_OUTA  = 0x0E02U,               /*!< \brief MDL18_OUTA  */
    CDD_XBAR_INPUT_FLG_MDL18_OUTB  = 0x0E03U,               /*!< \brief MDL18_OUTB  */
    CDD_XBAR_INPUT_FLG_CLB1_OUT0  = 0x0F00U,                /*!< \brief CLB1_OUT0  */
    CDD_XBAR_INPUT_FLG_CLB1_OUT1  = 0x0F01U,                /*!< \brief CLB1_OUT1  */
    CDD_XBAR_INPUT_FLG_CLB1_OUT2  = 0x0F02U,                /*!< \brief CLB1_OUT2  */
    CDD_XBAR_INPUT_FLG_CLB1_OUT3  = 0x0F03U,                /*!< \brief CLB1_OUT3  */
    CDD_XBAR_INPUT_FLG_CLB1_OUT6  = 0x0F04U,                /*!< \brief CLB1_OUT6  */
    CDD_XBAR_INPUT_FLG_CLB1_OUT7  = 0x0F05U,                /*!< \brief CLB1_OUT7  */
    CDD_XBAR_INPUT_FLG_CLB2_OUT0  = 0x0F06U,                /*!< \brief CLB2_OUT0  */
    CDD_XBAR_INPUT_FLG_CLB2_OUT1  = 0x0F07U,                /*!< \brief CLB2_OUT1  */
    CDD_XBAR_INPUT_FLG_CLB2_OUT2  = 0x0F08U,                /*!< \brief CLB2_OUT2  */
    CDD_XBAR_INPUT_FLG_CLB2_OUT3  = 0x0F09U,                /*!< \brief CLB2_OUT3  */
    CDD_XBAR_INPUT_FLG_CLB2_OUT6  = 0x0F0AU,                /*!< \brief CLB2_OUT6  */
    CDD_XBAR_INPUT_FLG_CLB2_OUT7  = 0x0F0BU,                /*!< \brief CLB2_OUT7  */
    CDD_XBAR_INPUT_FLG_CLB3_OUT0  = 0x0F0CU,                /*!< \brief CLB3_OUT0  */
    CDD_XBAR_INPUT_FLG_CLB3_OUT1  = 0x0F0DU,                /*!< \brief CLB3_OUT1  */
    CDD_XBAR_INPUT_FLG_CLB3_OUT2  = 0x0F0EU,                /*!< \brief CLB3_OUT2  */
    CDD_XBAR_INPUT_FLG_CLB3_OUT3  = 0x0F0FU,                /*!< \brief CLB3_OUT3  */
    CDD_XBAR_INPUT_FLG_CLB3_OUT6  = 0x0F10U,                /*!< \brief CLB3_OUT6  */
    CDD_XBAR_INPUT_FLG_CLB3_OUT7  = 0x0F11U,                /*!< \brief CLB3_OUT7  */
    CDD_XBAR_INPUT_FLG_CLB4_OUT0  = 0x0F12U,                /*!< \brief CLB4_OUT0  */
    CDD_XBAR_INPUT_FLG_CLB4_OUT1  = 0x0F13U,                /*!< \brief CLB4_OUT1  */
    CDD_XBAR_INPUT_FLG_CLB4_OUT2  = 0x0F14U,                /*!< \brief CLB4_OUT2  */
    CDD_XBAR_INPUT_FLG_CLB4_OUT3  = 0x0F15U,                /*!< \brief CLB4_OUT3  */
    CDD_XBAR_INPUT_FLG_CLB4_OUT6  = 0x0F16U,                /*!< \brief CLB4_OUT6  */
    CDD_XBAR_INPUT_FLG_CLB4_OUT7  = 0x0F17U,                /*!< \brief CLB4_OUT7  */
    CDD_XBAR_INPUT_FLG_CLB5_OUT0  = 0x0F18U,                /*!< \brief CLB5_OUT0  */
    CDD_XBAR_INPUT_FLG_CLB5_OUT1  = 0x0F19U,                /*!< \brief CLB5_OUT1  */
    CDD_XBAR_INPUT_FLG_CLB5_OUT2  = 0x0F1AU,                /*!< \brief CLB5_OUT2  */
    CDD_XBAR_INPUT_FLG_CLB5_OUT3  = 0x0F1BU,                /*!< \brief CLB5_OUT3  */
    CDD_XBAR_INPUT_FLG_CLB5_OUT6  = 0x0F1CU,                /*!< \brief CLB5_OUT6  */
    CDD_XBAR_INPUT_FLG_CLB5_OUT7  = 0x0F1DU,                /*!< \brief CLB5_OUT7  */
    CDD_XBAR_INPUT_FLG_CLB6_OUT0  = 0x0F1EU,                /*!< \brief CLB6_OUT0  */
    CDD_XBAR_INPUT_FLG_CLB6_OUT1  = 0x0F1FU,                /*!< \brief CLB6_OUT1  */
    CDD_XBAR_INPUT_FLG_CLB6_OUT2  = 0x1000U,                /*!< \brief CLB6_OUT2  */
    CDD_XBAR_INPUT_FLG_CLB6_OUT3  = 0x1001U,                /*!< \brief CLB6_OUT3  */
    CDD_XBAR_INPUT_FLG_CLB6_OUT6  = 0x1002U,                /*!< \brief CLB6_OUT6  */
    CDD_XBAR_INPUT_FLG_CLB6_OUT7  = 0x1003U,                /*!< \brief CLB6_OUT7  */
    CDD_XBAR_INPUT_FLG_ADCA_EXTMUXSEL0  = 0x1004U,          /*!< \brief ADCA_EXTMUXSEL0  */
    CDD_XBAR_INPUT_FLG_ADCA_EXTMUXSEL1  = 0x1005U,          /*!< \brief ADCA_EXTMUXSEL1  */
    CDD_XBAR_INPUT_FLG_ADCA_EXTMUXSEL2  = 0x1006U,          /*!< \brief ADCA_EXTMUXSEL2  */
    CDD_XBAR_INPUT_FLG_ADCA_EXTMUXSEL3  = 0x1007U,          /*!< \brief ADCA_EXTMUXSEL3  */
    CDD_XBAR_INPUT_FLG_ADCB_EXTMUXSEL0  = 0x1008U,          /*!< \brief ADCB_EXTMUXSEL0  */
    CDD_XBAR_INPUT_FLG_ADCB_EXTMUXSEL1  = 0x1009U,          /*!< \brief ADCB_EXTMUXSEL1  */
    CDD_XBAR_INPUT_FLG_ADCB_EXTMUXSEL2  = 0x100AU,          /*!< \brief ADCB_EXTMUXSEL2  */
    CDD_XBAR_INPUT_FLG_ADCB_EXTMUXSEL3  = 0x100BU,          /*!< \brief ADCB_EXTMUXSEL3  */
    CDD_XBAR_INPUT_FLG_ADCC_EXTMUXSEL0  = 0x100CU,          /*!< \brief ADCC_EXTMUXSEL0  */
    CDD_XBAR_INPUT_FLG_ADCC_EXTMUXSEL1  = 0x100DU,          /*!< \brief ADCC_EXTMUXSEL1  */
    CDD_XBAR_INPUT_FLG_ADCC_EXTMUXSEL2  = 0x100EU,          /*!< \brief ADCC_EXTMUXSEL2  */
    CDD_XBAR_INPUT_FLG_ADCC_EXTMUXSEL3  = 0x100FU,          /*!< \brief ADCC_EXTMUXSEL3  */
    CDD_XBAR_INPUT_FLG_ADCD_EXTMUXSEL0  = 0x1010U,          /*!< \brief ADCD_EXTMUXSEL0  */
    CDD_XBAR_INPUT_FLG_ADCD_EXTMUXSEL1  = 0x1011U,          /*!< \brief ADCD_EXTMUXSEL1  */
    CDD_XBAR_INPUT_FLG_ADCD_EXTMUXSEL2  = 0x1012U,          /*!< \brief ADCD_EXTMUXSEL2  */
    CDD_XBAR_INPUT_FLG_ADCD_EXTMUXSEL3  = 0x1013U,          /*!< \brief ADCD_EXTMUXSEL3  */
    CDD_XBAR_INPUT_FLG_ADCE_EXTMUXSEL0  = 0x1014U,          /*!< \brief ADCE_EXTMUXSEL0  */
    CDD_XBAR_INPUT_FLG_ADCE_EXTMUXSEL1  = 0x1015U,          /*!< \brief ADCE_EXTMUXSEL1  */
    CDD_XBAR_INPUT_FLG_ADCE_EXTMUXSEL2  = 0x1016U,          /*!< \brief ADCE_EXTMUXSEL2  */
    CDD_XBAR_INPUT_FLG_ADCE_EXTMUXSEL3  = 0x1017U,          /*!< \brief ADCE_EXTMUXSEL3  */
    CDD_XBAR_INPUT_FLG_EPG1_EPGOUT0  = 0x101CU,             /*!< \brief EPG1_EPGOUT0  */
    CDD_XBAR_INPUT_FLG_EPG1_EPGOUT1  = 0x101DU,             /*!< \brief EPG1_EPGOUT1  */
    CDD_XBAR_INPUT_FLG_EPG1_EPGOUT2  = 0x101EU,             /*!< \brief EPG1_EPGOUT2  */
    CDD_XBAR_INPUT_FLG_EPG1_EPGOUT3  = 0x101FU,             /*!< \brief EPG1_EPGOUT3  */
    CDD_XBAR_INPUT_FLG_MCANA_FEVT0  = 0x1100U,              /*!< \brief MCANA_FEVT0  */
    CDD_XBAR_INPUT_FLG_MCANA_FEVT1  = 0x1101U,              /*!< \brief MCANA_FEVT1  */
    CDD_XBAR_INPUT_FLG_MCANA_FEVT2  = 0x1102U,              /*!< \brief MCANA_FEVT2  */
    CDD_XBAR_INPUT_FLG_MCANB_FEVT0  = 0x1103U,              /*!< \brief MCANB_FEVT0  */
    CDD_XBAR_INPUT_FLG_MCANB_FEVT1  = 0x1104U,              /*!< \brief MCANB_FEVT1  */
    CDD_XBAR_INPUT_FLG_MCANB_FEVT2  = 0x1105U,              /*!< \brief MCANB_FEVT2  */
    CDD_XBAR_INPUT_FLG_MCANC_FEVT0  = 0x1106U,              /*!< \brief MCANC_FEVT0  */
    CDD_XBAR_INPUT_FLG_MCANC_FEVT1  = 0x1107U,              /*!< \brief MCANC_FEVT1  */
    CDD_XBAR_INPUT_FLG_MCANC_FEVT2  = 0x1108U,              /*!< \brief MCANC_FEVT2  */
    CDD_XBAR_INPUT_FLG_MCAND_FEVT0  = 0x1109U,              /*!< \brief MCAND_FEVT0  */
    CDD_XBAR_INPUT_FLG_MCAND_FEVT1  = 0x110AU,              /*!< \brief MCAND_FEVT1  */
    CDD_XBAR_INPUT_FLG_MCAND_FEVT2  = 0x110BU,              /*!< \brief MCAND_FEVT2  */
    CDD_XBAR_INPUT_FLG_MCANE_FEVT0  = 0x110CU,              /*!< \brief MCANE_FEVT0  */
    CDD_XBAR_INPUT_FLG_MCANE_FEVT1  = 0x110DU,              /*!< \brief MCANE_FEVT1  */
    CDD_XBAR_INPUT_FLG_MCANE_FEVT2  = 0x110EU,              /*!< \brief MCANE_FEVT2  */
    CDD_XBAR_INPUT_FLG_MCANF_FEVT0  = 0x110FU,              /*!< \brief MCANF_FEVT0  */
    CDD_XBAR_INPUT_FLG_MCANF_FEVT1  = 0x1110U,              /*!< \brief MCANF_FEVT1  */
    CDD_XBAR_INPUT_FLG_MCANF_FEVT2  = 0x1111U,              /*!< \brief MCANF_FEVT2  */
    CDD_XBAR_INPUT_FLG_FSIRXA_TRIG_2  = 0x1200U,            /*!< \brief FSIRXA_TRIG_2  */
    CDD_XBAR_INPUT_FLG_FSIRXA_TRIG_3  = 0x1201U,            /*!< \brief FSIRXA_TRIG_3  */
    CDD_XBAR_INPUT_FLG_FSIRXB_TRIG_2  = 0x1202U,            /*!< \brief FSIRXB_TRIG_2  */
    CDD_XBAR_INPUT_FLG_FSIRXB_TRIG_3  = 0x1203U,            /*!< \brief FSIRXB_TRIG_3  */
    CDD_XBAR_INPUT_FLG_FSIRXC_TRIG_2  = 0x1204U,            /*!< \brief FSIRXC_TRIG_2  */
    CDD_XBAR_INPUT_FLG_FSIRXC_TRIG_3  = 0x1205U,            /*!< \brief FSIRXC_TRIG_3  */
    CDD_XBAR_INPUT_FLG_FSIRXD_TRIG_2  = 0x1206U,            /*!< \brief FSIRXD_TRIG_2  */
    CDD_XBAR_INPUT_FLG_FSIRXD_TRIG_3  = 0x1207U,            /*!< \brief FSIRXD_TRIG_3  */
    CDD_XBAR_INPUT_FLG_CPU1ERADEVT8  = 0x1208U,             /*!< \brief CPU1ERADEVT8  */
    CDD_XBAR_INPUT_FLG_CPU1ERADEVT9  = 0x1209U,             /*!< \brief CPU1ERADEVT9  */
    CDD_XBAR_INPUT_FLG_CPU1ERADEVT10  = 0x120AU,            /*!< \brief CPU1ERADEVT10  */
    CDD_XBAR_INPUT_FLG_CPU1ERADEVT11  = 0x120BU,            /*!< \brief CPU1ERADEVT11  */
    CDD_XBAR_INPUT_FLG_CPU2ERADEVT8  = 0x120CU,             /*!< \brief CPU2ERADEVT8  */
    CDD_XBAR_INPUT_FLG_CPU2ERADEVT9  = 0x120DU,             /*!< \brief CPU2ERADEVT9  */
    CDD_XBAR_INPUT_FLG_CPU2ERADEVT10  = 0x120EU,            /*!< \brief CPU2ERADEVT10  */
    CDD_XBAR_INPUT_FLG_CPU2ERADEVT11  = 0x120FU,            /*!< \brief CPU2ERADEVT11  */
    CDD_XBAR_INPUT_FLG_CPU3ERADEVT8  = 0x1210U,             /*!< \brief CPU2ERADEVT8  */
    CDD_XBAR_INPUT_FLG_CPU3ERADEVT9  = 0x1211U,             /*!< \brief CPU2ERADEVT9  */
    CDD_XBAR_INPUT_FLG_CPU3ERADEVT10  = 0x1212U,            /*!< \brief CPU2ERADEVT10  */
    CDD_XBAR_INPUT_FLG_CPU3ERADEVT11  = 0x1213U             /*!< \brief CPU2ERADEVT11  */
} Cdd_Xbar_InputFlagType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-25802 */
/** \brief Input Crossbar configuration */
typedef struct Cdd_Xbar_InXbarCfgTag
{
    /** \brief Input crossbar INPUTx line */
    uint8 inputSelect;          /* Design: MCAL-25720 */
    /** \brief Input crossbar input line */
    uint16 inputLine;            /* Design: MCAL-25721 */
    /** \brief Input crossbar lock setting */
    boolean selectConfigLock;   /* Design: MCAL-25707 */
} Cdd_Xbar_InXbarCfgType;
#endif

#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
/* Design: MCAL-25803 */
/** \brief Output Crossbar configuration */
typedef struct Cdd_Xbar_OutXbarCfgTag
{
    /** \brief Number of inputs of an output crossbar instance*/
    uint8 input_count;                               
    /** \brief Output crossbar input line */
    uint16 inputLine[CDD_XBAR_OUTXBAR_INPUT_COUNT];     /* Design: MCAL-25724 */
    /** \brief Output crossbar output line */
    uint8 outputLine;                               /* Design: MCAL-25722 */
    /** \brief Output crossbar output stretch selection */
    Cdd_Xbar_TickStretchType outputStretchPulse;    /* Design: MCAL-25719 */
    /** \brief Output crossbar output inversion selection */
    boolean outputInversion;                        /* Design: MCAL-25713 */
    /** \brief Output crossbar output latch selection as output */
    boolean outputLatch;                            /* Design: MCAL-25718 */
    /** \brief Output crossbar output inversion before latch selection */
    boolean outputInversionBeforeLatch;              /* Design: MCAL-25814 */
    /** \brief Output crossbar output flag force/clear selection during init */
    Cdd_Xbar_OutFlagInitType outputFlag;             /* Design: MCAL-25813 */
} Cdd_Xbar_OutXbarCfgType;
#endif

#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
/* Design: MCAL-25804 */
/** \brief EPWM Crossbar configuration */
typedef struct Cdd_Xbar_EPWMXbarCfgTag
{
    /** \brief Number of crossbar inputs for a crossbar instance*/
    uint8 input_count;          /* Design: MCAL-25725, MCAL-25727, MCAL-25729, MCAL-25731 */
    /** \brief Crossbar input line */ 
    uint16 inputLine[CDD_XBAR_EPWMXBAR_INPUT_COUNT];    /* Design: MCAL-25726, MCAL-25728, MCAL-25730, MCAL-25732 */
    /** \brief Crossbar output line */
    uint8 outputLine;         /* Design: MCAL-25822, MCAL-25723, MCAL-25724, MCAL-25825 */
    /** \brief Crossbar output inversion selection */
    boolean outputInversion;  /* Design: MCAL-25714, MCAL-25715, MCAL-25716, MCAL-25717 */
} Cdd_Xbar_EPWMXbarCfgType;
#endif

#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28162 */
/** \brief CLB Crossbar configuration */
typedef struct Cdd_Xbar_CLBXbarCfgTag
{
    /** \brief Number of crossbar inputs for a crossbar instance*/
    uint8 input_count;          /* Design: MCAL-25725, MCAL-25727, MCAL-25729, MCAL-25731 */
    /** \brief Crossbar input line */ 
    uint16 inputLine[CDD_XBAR_CLBXBAR_INPUT_COUNT];    /* Design: MCAL-25726, MCAL-25728, MCAL-25730, MCAL-25732 */
    /** \brief Crossbar output line */
    uint8 outputLine;         /* Design: MCAL-25822, MCAL-25723, MCAL-25724, MCAL-25825 */
    /** \brief Crossbar output inversion selection */
    boolean outputInversion;  /* Design: MCAL-25714, MCAL-25715, MCAL-25716, MCAL-25717 */
} Cdd_Xbar_CLBXbarCfgType;
#endif

#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
/* Design: MCAL-28163 */
/** \brief MINDB Crossbar configuration */
typedef struct Cdd_Xbar_MINDBXbarCfgTag
{
    /** \brief Number of crossbar inputs for a crossbar instance*/
    uint8 input_count;          /* Design: MCAL-25725, MCAL-25727, MCAL-25729, MCAL-25731 */
    /** \brief Crossbar input line */ 
    uint16 inputLine[CDD_XBAR_MINDBXBAR_INPUT_COUNT];    /* Design: MCAL-25726, MCAL-25728, MCAL-25730, MCAL-25732 */
    /** \brief Crossbar output line */
    uint8 outputLine;         /* Design: MCAL-25822, MCAL-25723, MCAL-25724, MCAL-25825 */
    /** \brief Crossbar output inversion selection */
    boolean outputInversion;  /* Design: MCAL-25714, MCAL-25715, MCAL-25716, MCAL-25717 */
} Cdd_Xbar_MINDBXbarCfgType;
#endif

#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
/* Design: MCAL-28164 */
/** \brief ICL Crossbar configuration */
typedef struct Cdd_Xbar_ICLXbarCfgTag
{
    /** \brief Number of crossbar inputs for a crossbar instance*/
    uint8 input_count;          /* Design: MCAL-25725, MCAL-25727, MCAL-25729, MCAL-25731 */
    /** \brief Crossbar input line */ 
    uint16 inputLine[CDD_XBAR_ICLXBAR_INPUT_COUNT];    /* Design: MCAL-25726, MCAL-25728, MCAL-25730, MCAL-25732 */
    /** \brief Crossbar output line */
    uint8 outputLine;         /* Design: MCAL-25822, MCAL-25723, MCAL-25724, MCAL-25825 */
    /** \brief Crossbar output inversion selection */
    boolean outputInversion;  /* Design: MCAL-25714, MCAL-25715, MCAL-25716, MCAL-25717 */
} Cdd_Xbar_ICLXbarCfgType;
#endif

/* Design: MCAL-25796 */
/** \brief CDD XBar configuration */
typedef struct
{
    /* Design: MCAL-25805 */
    #if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
    /** \brief Input Crossbar Configuration */
    Cdd_Xbar_InXbarCfgType Cdd_Xbar_InputCfg[CDD_XBAR_INPUT_XBAR_CONFIGURATIONS];
    #endif
    /* Design: MCAL-25806 */
    #if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
    /** \brief Output Crossbar Configuration */
    Cdd_Xbar_OutXbarCfgType Cdd_Xbar_OutputCfg[CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS];
    #endif
    /* Design: MCAL-25807 */
    #if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
    /** \brief EPWM Crossbar Configuration */
    Cdd_Xbar_EPWMXbarCfgType Cdd_Xbar_EpwmCfg[CDD_XBAR_EPWM_XBAR_CONFIGURATIONS];
    #endif
    /* Design: MCAL-25808 */
    #if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
    /** \brief CLB Crossbar Configuration */
    Cdd_Xbar_CLBXbarCfgType Cdd_Xbar_ClbCfg[CDD_XBAR_CLB_XBAR_CONFIGURATIONS];
    #endif
    /* Design: MCAL-25809 */
    #if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
    /** \brief MINDB Crossbar Configuration */
    Cdd_Xbar_MINDBXbarCfgType Cdd_Xbar_MindbCfg[CDD_XBAR_MINDB_XBAR_CONFIGURATIONS];
    #endif
    /* Design: MCAL-25810 */
    #if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
    /** \brief ICL Crossbar Configuration */
    Cdd_Xbar_ICLXbarCfgType Cdd_Xbar_IclCfg[CDD_XBAR_ICL_XBAR_CONFIGURATIONS];
    #endif
    /** \brief Output Crossbar Lock */
    boolean outConfigLock;      /* Design: MCAL-25708 */
    /** \brief EPWM Crossbar Lock */
    boolean epwmConfigLock;     /* Design: MCAL-25709 */
    /** \brief CLB Crossbar Lock */
    boolean clbConfigLock;      /* Design: MCAL-25710 */
    /** \brief MINDB Crossbar Lock */
    boolean mindbConfigLock;    /* Design: MCAL-25711 */
    /** \brief ICL Crossbar Lock */
    boolean iclConfigLock;      /* Design: MCAL-25712 */
} Cdd_Xbar_ConfigType;

/* CDD XBar Configuration struct extern declaration */
extern VAR(Cdd_Xbar_ConfigType, CDD_XBAR_CONFIG_DATA) Cdd_Xbar_Configuration;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_XBAR_CFG_H */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Cfg.h
 *********************************************************************************************************************/
