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
 *  File:       Cdd_Uart_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated pre-compile configuration data.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_Uart.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * AUTOSAR version information check.
 *
 *****************************************************************************/
#if ((CDD_UART_SW_MAJOR_VERSION != (1U)) || (CDD_UART_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Uart_Cfg.c and Cdd_Uart.h are inconsistent!"
#endif

#if ((CDD_UART_CFG_MAJOR_VERSION != (1U)) || (CDD_UART_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Uart_Cfg.c and Cdd_Uart_Cfg.h are inconsistent!"
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

//
#define CDD_UART_START_SEC_CONFIG_DATA
#include "Cdd_Uart_MemMap.h"

/* Generation of configuration */
CONST(Cdd_Uart_ConfigType, CDD_UART_CONFIG_DATA) Cdd_Uart_CddUartConfigSet =
{
    .Cdd_Uart_HwUnitCfg =
    {
        [0]=
        {
            .Cdd_Uart_Instance = (Cdd_Uart_Instance)CDD_UART_INSTANCE_UART3,
            .Cdd_Uart_BaseAddr = (uint32)0x60076000U,
            .Cdd_Uart_HWUnitId = (uint8 )0U,
            .Cdd_Uart_BaudRate = (uint32)115200U,
            .Cdd_Uart_WriteEnable = (boolean)TRUE,
            .Cdd_Uart_ReadEnable = (boolean)TRUE,
            .Cdd_Uart_ClockFreq = (uint32)200000000U,
            .Cdd_Uart_WordLength = (Cdd_Uart_WordLength)CDD_UART_WORD_LENGTH_8,
            .Cdd_Uart_StopBits = (Cdd_Uart_StopBits)CDD_UART_STOP_BITS_1,
            .Cdd_Uart_ParityEnable = (boolean)FALSE,
            .Cdd_Uart_FifoEnable = (boolean)TRUE,
            .Cdd_Uart_IoMode = (Cdd_Uart_Mode)CDD_UART_MODE_INTERRUPT,
            .Cdd_Uart_LoopbackEnable = (boolean)TRUE,
            .Cdd_Uart_WriteFifoLvl = (Cdd_Uart_FifoLevel)CDD_UART_FIFO_LEVEL_1_2,
            .Cdd_Uart_WriteCompleteCb = (Cdd_Uart_CallbackType)CddUartWriteDoneCallback,
            .Cdd_Uart_ReadFifoLvl = (Cdd_Uart_FifoLevel)CDD_UART_FIFO_LEVEL_1_2,
            .Cdd_Uart_ReadCompleteCb = (Cdd_Uart_CallbackType)CddUartReadDoneCallback,
            .Cdd_Uart_ErrorCb = (Cdd_Uart_CallbackType)CddUartErrorCallback,
        }
    }
};



#define CDD_UART_STOP_SEC_CONFIG_DATA
#include "Cdd_Uart_MemMap.h"

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
 *  End of File: Cdd_Uart_Cfg.c
 *********************************************************************************************************************/
