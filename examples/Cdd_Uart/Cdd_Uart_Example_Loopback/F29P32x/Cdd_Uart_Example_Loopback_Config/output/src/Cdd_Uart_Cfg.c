
/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
#if ((CDD_UART_SW_MAJOR_VERSION != (3U)) || (CDD_UART_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Uart_Cfg.c and Cdd_Uart.h are inconsistent!"
#endif

#if ((CDD_UART_CFG_MAJOR_VERSION != (3U)) || (CDD_UART_CFG_MINOR_VERSION != (0U)))
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



#define CDD_UART_START_SEC_CONFIG_DATA
#include "Cdd_Uart_MemMap.h"

/* Generation of configuration */
CONST(Cdd_Uart_ConfigType, CDD_UART_CONFIG_DATA) Cdd_Uart_Config =
{
    .Cdd_Uart_HwUnitCfg =
    {
        
        [0]=
        {

            .Cdd_Uart_Instance = (Cdd_Uart_Instance)CDD_UART_INSTANCE_UARTB,
            .Cdd_Uart_BaseAddr = (uint32)UARTB_BASE_FRAME(0U),
            .Cdd_Uart_HWUnitId = (uint8 )0U,
            .Cdd_Uart_HighSpeedEnable = (boolean)FALSE,			
            .Cdd_Uart_BaudRateCfg = (uint32)0x1b20U,
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
