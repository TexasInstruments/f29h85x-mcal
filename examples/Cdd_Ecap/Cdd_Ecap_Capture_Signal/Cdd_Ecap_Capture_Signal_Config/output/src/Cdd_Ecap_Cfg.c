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
 *  File:       File name
 *  Generator:  Code generation tool (if any)
 *
 *  Description:  Description of file's purpose                                                           
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ecap.h"
#include "hw_memmap.h"
#include "Std_Types.h"
#ifdef __cplusplus

extern "C" {
#endif


/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
  #if ((CDD_ECAP_SW_MAJOR_VERSION != (2U)) ||(CDD_ECAP_SW_MINOR_VERSION != (0U)))
  #error "Version numbers of Cdd_Ecap_Cfg.c and Cdd_Ecap.h are inconsistent!"
#endif

 #if ((CDD_ECAP_CFG_MAJOR_VERSION != (2U)) ||(CDD_ECAP_CFG_MINOR_VERSION != (0U)))
  #error "Version numbers of Cdd_Ecap_Cfg.c and Cdd_Ecap_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CDD_ECAP_BASEADDR_STEP             (ECAP2_BASE - ECAP1_BASE)
#define CDD_ECAP_HR_BASEADDR_STEP          (HRCAP6_BASE - HRCAP5_BASE)
/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
/** \brief Cdd Ecap Driver configuration */

#define CDD_ECAP_START_SEC_CONFIG_DATA
#include "Cdd_Ecap_MemMap.h"





/* Cdd_Ecap Channel Configuration parameters */
 CONST(struct Cdd_Ecap_ConfigTag, CDD_ECAP_CONFIG_DATA)
    Cdd_Ecap_Config =
{
    .chCfg =
    {
        [0] =
        {
            .channelId = CDD_ECAP_CHANNEL0, /* Channel ID */
            .emulationMode = CDD_ECAP_EMULATION_FREE_RUN, /* Emulation Mode */
            .defaultStartEdge = CDD_ECAP_BOTH_EDGES,/* Default start edge*/
            .inputSelect = CDD_ECAP_INPUT_INPUTXBAR7,/* Input source select */
            .measurementMode = CDD_ECAP_MODE_SIGNAL_MEASUREMENT,/* Measurement Mode*/
            .signalMeasurementProperty = CDD_ECAP_HIGH_TIME,
            .instanceClkMHz = 200U,
            .prescaler = (uint8)0U, /* prescale */
            .base_addr = (uint32)(ECAP1_BASE + (CDD_ECAP_BASEADDR_STEP*0U)), /* Base address of the channel */
        },
        [1] =
        {
            .channelId = CDD_ECAP_CHANNEL1, /* Channel ID */
            .emulationMode = CDD_ECAP_EMULATION_FREE_RUN, /* Emulation Mode */
            .defaultStartEdge = CDD_ECAP_RISING_EDGE,/* Default start edge*/
            .inputSelect = CDD_ECAP_INPUT_INPUTXBAR7,/* Input source select */
            .measurementMode = CDD_ECAP_MODE_TIMESTAMP,/* Measurement Mode*/
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)Cdd_Ecap_TimeStampNotify ,
            .bufferType =  CDD_ECAP_CIRCULAR_BUFFER,
            .instanceClkMHz = 200U,
            .prescaler = (uint8)0U, /* prescale */
            .base_addr = (uint32)(ECAP1_BASE + (CDD_ECAP_BASEADDR_STEP*1U)), /* Base address of the channel */
        },
        [2] =
        {
            .channelId = CDD_ECAP_CHANNEL2, /* Channel ID */
            .emulationMode = CDD_ECAP_EMULATION_FREE_RUN, /* Emulation Mode */
            .defaultStartEdge = CDD_ECAP_RISING_EDGE,/* Default start edge*/
            .inputSelect = CDD_ECAP_INPUT_INPUTXBAR7,/* Input source select */
            .measurementMode = CDD_ECAP_MODE_EDGE_COUNTER,/* Measurement Mode*/
            .instanceClkMHz = 200U,
            .prescaler = (uint8)0U, /* prescale */
            .base_addr = (uint32)(ECAP1_BASE + (CDD_ECAP_BASEADDR_STEP*2U)), /* Base address of the channel */
        },
        [3] =
        {
            .channelId = CDD_ECAP_CHANNEL3, /* Channel ID */
            .emulationMode = CDD_ECAP_EMULATION_FREE_RUN, /* Emulation Mode */
            .defaultStartEdge = CDD_ECAP_RISING_EDGE,/* Default start edge*/
            .inputSelect = CDD_ECAP_INPUT_INPUTXBAR7,/* Input source select */
            .measurementMode = CDD_ECAP_MODE_SIGNAL_EDGE_DETECT,/* Measurement Mode*/
            .notificationHandler = (Cdd_Ecap_NotifyFuncType)Cdd_Ecap_SignalNotify ,
            .instanceClkMHz = 200U,
            .prescaler = (uint8)0U, /* prescale */
            .base_addr = (uint32)(ECAP1_BASE + (CDD_ECAP_BASEADDR_STEP*3U)), /* Base address of the channel */
        }
    }
};


#ifdef __cplusplus
}
#endif

/*</CDD_ECAP_CONFIGURATION>*/
#define CDD_ECAP_STOP_SEC_CONFIG_DATA
#include "Cdd_Ecap_MemMap.h"

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  End of File: Cdd_Ecap_Cfg.c
 *********************************************************************************************************************/
