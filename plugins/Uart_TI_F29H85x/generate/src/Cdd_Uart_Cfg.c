[!SKIPFILE "as:modconf('Cdd_Uart/Cdd')[as:path(node:dtos(.))='/TI_F29H85x/Cdd_Uart/Cdd']/IMPLEMENTATION_CONFIG_VARIANT != 'VariantPreCompile'"!]
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
            .Cdd_Uart_Instance = (Cdd_Uart_Instance)CDD_UART_INSTANCE_[!"CddUartInstance"!],
            .Cdd_Uart_BaseAddr = (uint32)[!"num:inttohex(CddUartBaseAddress)"!]U,
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