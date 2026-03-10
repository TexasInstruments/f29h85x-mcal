[!SKIPFILE "as:modconf('Cdd_Uart/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Uart/Cdd']/IMPLEMENTATION_CONFIG_VARIANT != 'VariantPreCompile'"!]
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
#if ((CDD_UART_SW_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_UART_SW_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
    #error "Version numbers of Cdd_Uart_Cfg.c and Cdd_Uart.h are inconsistent!"
#endif

#if ((CDD_UART_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) || (CDD_UART_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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
[!SELECT "as:modconf('Cdd_Uart/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Uart/Cdd']"!]
/* Generation of configuration */
[!LOOP "CddUartConfigSet"!][!//
CONST(Cdd_Uart_ConfigType, CDD_UART_CONFIG_DATA) Cdd_Uart_Config =
{
    .Cdd_Uart_HwUnitCfg =
    {
        [!LOOP "CddUartConfig/*"!]
        [[!"node:pos(.)"!]]=
        {
[!VAR "UartClock"="num:i(node:ref(CddUartClockFreq)/McuClockReferencePointFrequency)"!][!//	
[!VAR "UartBdRt"="CddUartBaudRate"!][!//
            .Cdd_Uart_Instance = (Cdd_Uart_Instance)CDD_UART_INSTANCE_[!"(node:ref(CddUartInstance)/InstanceName)"!],
            .Cdd_Uart_BaseAddr = (uint32)[!"node:value(node:ref(CddUartInstance)/BaseAddr)"!],
            .Cdd_Uart_HWUnitId = (uint8 )[!"CddUartHWUnitId"!]U,
[!IF "num:i(num:mul($UartBdRt,16)) >= num:i($UartClock)"!][!//
[!VAR "UartBdRt"="num:i(num:div($UartBdRt,2))"!]
            .Cdd_Uart_HighSpeedEnable = (boolean)TRUE,
[!ELSE!][!//
            .Cdd_Uart_HighSpeedEnable = (boolean)FALSE,			
[!ENDIF!][!//
[!VAR "uartFbrDiv"="num:i(num:div(num:mul($UartClock,8),$UartBdRt))"!][!//
[!VAR "uartFbrDiv"="num:i(num:div(num:add($uartFbrDiv,1),2))"!][!//
[!ASSERT "num:i(num:div($uartFbrDiv,64)) < 65526","STOP: This baudrate cannot be generated with respect to input clock"!][!//
[!ASSERT "num:i(num:mod($uartFbrDiv,64)) < 64","STOP: This baudrate cannot be generated with respect to input clock"!][!//
            .Cdd_Uart_BaudRateCfg = (uint32)[!"num:inttohex($uartFbrDiv)"!]U,
            .Cdd_Uart_WriteEnable = (boolean)[!IF "CddUartEnableWrite ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .Cdd_Uart_ReadEnable = (boolean)[!IF "CddUartEnableRead ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .Cdd_Uart_ClockFreq = (uint32)[!"$UartClock"!]U,
            .Cdd_Uart_WordLength = (Cdd_Uart_WordLength)[!"CddUartWordLength"!],
            .Cdd_Uart_StopBits = (Cdd_Uart_StopBits)[!"CddUartStopBit"!],
            .Cdd_Uart_ParityEnable = (boolean)[!IF "CddUartParityModeEnable ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .Cdd_Uart_FifoEnable = (boolean)[!IF "CddUartFIFOModeEnable ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
            .Cdd_Uart_IoMode = (Cdd_Uart_Mode)[!"CddUartProcessingMode"!],
            .Cdd_Uart_LoopbackEnable = (boolean)[!IF "CddUartLoopBackModeEnable ='true'"!]TRUE[!ELSE!]FALSE[!ENDIF!],
[!IF "node:value(CddUartEnableWrite)='true'"!][!//
[!IF "node:value(CddUartFIFOModeEnable)='true'"!][!//
            .Cdd_Uart_WriteFifoLvl = (Cdd_Uart_FifoLevel)[!"node:value(CddUartWriteConfig/CddUartTriggerLevelWriteFIFO)"!],
[!ENDIF!][!//
            .Cdd_Uart_WriteCompleteCb = (Cdd_Uart_CallbackType)[!IF "(node:empty(CddUartWriteConfig/CddUartWriteNotificationHandler))"!]NULL_PTR[!ELSE!][!"(node:value(CddUartWriteConfig/CddUartWriteNotificationHandler))"!][!ENDIF!],
[!ENDIF!][!//
[!IF "node:value(CddUartEnableRead)='true'"!][!//
[!IF "node:value(CddUartFIFOModeEnable)='true'"!][!//
            .Cdd_Uart_ReadFifoLvl = (Cdd_Uart_FifoLevel)[!"node:value(CddUartReadConfig/CddUartTriggerLevelReadFIFO)"!],
[!ENDIF!][!//
            .Cdd_Uart_ReadCompleteCb = (Cdd_Uart_CallbackType)[!IF "(node:empty(CddUartReadConfig/CddUartReadNotificationHandler))"!]NULL_PTR[!ELSE!][!"(node:value(CddUartReadConfig/CddUartReadNotificationHandler))"!][!ENDIF!],
            .Cdd_Uart_ErrorCb = (Cdd_Uart_CallbackType)[!IF "(node:empty(CddUartReadConfig/CddUartErrorNotificationHandler))"!]NULL_PTR[!ELSE!][!"(node:value(CddUartReadConfig/CddUartErrorNotificationHandler))"!][!ENDIF!],
[!ENDIF!]
        }[!IF "not(node:islast())"!],[!ENDIF!]
        [!ENDLOOP!]
    }
};[!//
[!ENDLOOP!]
[!ENDSELECT!]


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