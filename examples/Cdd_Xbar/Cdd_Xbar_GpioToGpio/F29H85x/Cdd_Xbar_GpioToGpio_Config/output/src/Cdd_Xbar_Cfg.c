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
 *  File:       Cdd_Xbar_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 
#include "Cdd_Xbar.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_XBAR_SW_MAJOR_VERSION != (3U)) || (CDD_XBAR_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Xbar.c and Cdd_Xbar.h are inconsistent!"
#endif

#if ((CDD_XBAR_CFG_MAJOR_VERSION != (3U)) || (CDD_XBAR_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Xbar_Cfg.c and Cdd_Xbar_Cfg.h are inconsistent!"
#endif


/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* None */

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/


#define CDD_XBAR_START_SEC_CONFIG_DATA
#include "Cdd_Xbar_MemMap.h"

/** \brief CDD Crossbar Configuration */
VAR(Cdd_Xbar_ConfigType, CDD_XBAR_CONFIG_DATA) Cdd_Xbar_Config = 
{
  /* Design: MCAL-25701 */
    .Cdd_Xbar_InputCfg = 
    {
        {
            .inputSelect = CDD_XBAR_INPUT1,   /* Design: MCAL-25720 */
            .inputLine = 0U,    /* GPIO0 */  /* Design: MCAL-25721 */
            .selectConfigLock = TRUE,   /* Design: MCAL-25707 */
        },
        {
            .inputSelect = CDD_XBAR_INPUT2,   /* Design: MCAL-25720 */
            .inputLine = 3U,    /* GPIO3 */  /* Design: MCAL-25721 */
            .selectConfigLock = FALSE,   /* Design: MCAL-25707 */
        },
    },
  /* Design: MCAL-25708 */
    .outConfigLock = FALSE,
  /* Design: MCAL-25702 */
    .Cdd_Xbar_OutputCfg =
    {
        {
            .input_count = (uint32)1U,
            .inputLine[0] =  CDD_XBAR_OUT_INPUTXBAR1,
            .outputLine = CDD_XBAR_OUTPUT1,   /* Design: MCAL-25722 */
            .outputStretchPulse = CDD_XBAR_SYSTICKS_STRETCH_OFF,    /* Design: MCAL-25719 */
            .outputInversion = FALSE,    /* Design: MCAL-25713 */
            .outputLatch = FALSE,    /* Design: MCAL-25718 */
            .outputInversionBeforeLatch = FALSE,    /* Design: MCAL-25814 */
            .outputFlag = CDD_XBAR_OUTPUTDEFAULT,    /* Design: MCAL-25813 */
        },
    },
  /* Design: MCAL-25709 */
    .epwmConfigLock = FALSE,
    /* Design: MCAL-25710 */
    .clbConfigLock = FALSE,
    /* Design: MCAL-25711 */
    .mindbConfigLock = FALSE,
  /* Design: MCAL-25712 */
    .iclConfigLock = FALSE,
    .outputXbarFlagBaseAddress = (uint32)OUTPUTXBAR1_FLAGS_BASE_FRAME(0U),
    .inputFlagBaseAddress = (uint32)XBAR_BASE_FRAME(0U),
};

#define CDD_XBAR_STOP_SEC_CONFIG_DATA
#include "Cdd_Xbar_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/* None */

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* None */
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Cfg.c
 *********************************************************************************************************************/
