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
 *  File:       Cdd_Uart_Example_Write_Polling.c
 *  Generator:  None
 *
 *  Description:   Cdd_Uart example source file. This program demonstrates the usage of the Cdd_Uart
 *driver in polling mode,  showcasing its capabilities in transmitting data. The program initializes
 *the UART instance, writes data to the transmit buffer, and waits for the transmission to complete
 *with the help of scheduled function Cdd_Uart_MainFunction_Write.
 *
 *  steps followed in the example:
 *  Cdd_Uart_Init()
 *  Initialize the Cdd_Uart instance and set up the transmit buffer
 *  Write data to the transmit buffer using the Cdd_Uart_Write function, and polled using the
 *Cdd_Uart_MainFunction_Write Wait for the transmission to complete using the
 *CddUartWriteDoneCallback function Cdd_Uart_Deinit() Verification of Cdd_Uart write polling
 *functionality The program writes data to the transmit buffer and verifies that the transmission is
 *completed, demonstrating the reliability and functionality of the Cdd_Uart driver in polling mode.
 *
 * \b External \b Connections \n
 *    Connect configured UART Tx pin to the target's Rx pin, and connect configured UART Rx pin to the target's
 *Tx pin. Refer to PORT configuration to identify the configured pins.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_Uart.h"
#include "Platform_Types.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "EcuM.h"
#include "Cdd_Uart_Cbk.h"
#include "Mcal_Lib.h"
#include "Os.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define CDD_UART_EXAMPLE_WRITE_POLLING_MAX_SIZE       (270U)
#define CDD_UART_EXAMPLE_WRITE_POLLING_NUM_TESTS      (10U)
#define CDD_UART_EXAMPLE_WRITE_POLLING_NUM_TEST_CYCLE (5U)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
/* CDD UART Write Done callback function status */
uint32 Cdd_Uart_WriteDone = FALSE;
/* CDD UART Read Done callback function status */
uint32 Cdd_Uart_ReadDone = FALSE;
/* CDD UART Error count */
uint32 Cdd_Uart_ErrorCount = 0U;

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
#if (STD_ON == CDD_UART_CFG_GET_VERSION_INFO_API)
/*  version info variable */
Std_VersionInfoType Cdd_Uart_VersionInfo;
#endif

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
/*********************************************************************************************************************
 * External Functions Definition
 *********************************************************************************************************************/
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
int main(void)
{
    uint32                  testNum                                                   = 0U;
    uint32                  cycle                                                     = 0U;
    Std_ReturnType          return_value                                              = E_NOT_OK;
    Cdd_Uart_DataBufferType uartWriteDataBuf[CDD_UART_EXAMPLE_WRITE_POLLING_MAX_SIZE] = {
        'H', 'e', 'l',  'l', 'o', 'W',  'o', 'r', 'l',  'd', ' ', 'T',  'e', 'x', 'a',  's', ' ', 'I',  'n', 's', 't',
        'r', 'u', 'm',  'e', 'n', 't',  's', ' ', '\n', 'H', 'e', 'l',  'l', 'o', 'W',  'o', 'r', 'l',  'd', ' ', 'T',
        'e', 'x', 'a',  's', ' ', 'I',  'n', 's', 't',  'r', 'u', 'm',  'e', 'n', 't',  's', ' ', '\n', 'H', 'e', 'l',
        'l', 'o', 'W',  'o', 'r', 'l',  'd', ' ', 'T',  'e', 'x', 'a',  's', ' ', 'I',  'n', 's', 't',  'r', 'u', 'm',
        'e', 'n', 't',  's', ' ', '\n', 'H', 'e', 'l',  'l', 'o', 'W',  'o', 'r', 'l',  'd', ' ', 'T',  'e', 'x', 'a',
        's', ' ', 'I',  'n', 's', 't',  'r', 'u', 'm',  'e', 'n', 't',  's', ' ', '\n', 'H', 'e', 'l',  'l', 'o', 'W',
        'o', 'r', 'l',  'd', ' ', 'T',  'e', 'x', 'a',  's', ' ', 'I',  'n', 's', 't',  'r', 'u', 'm',  'e', 'n', 't',
        's', ' ', '\n', 'H', 'e', 'l',  'l', 'o', 'W',  'o', 'r', 'l',  'd', ' ', 'T',  'e', 'x', 'a',  's', ' ', 'I',
        'n', 's', 't',  'r', 'u', 'm',  'e', 'n', 't',  's', ' ', '\n', 'H', 'e', 'l',  'l', 'o', 'W',  'o', 'r', 'l',
        'd', ' ', 'T',  'e', 'x', 'a',  's', ' ', 'I',  'n', 's', 't',  'r', 'u', 'm',  'e', 'n', 't',  's', ' ', '\n',
        'H', 'e', 'l',  'l', 'o', 'W',  'o', 'r', 'l',  'd', ' ', 'T',  'e', 'x', 'a',  's', ' ', 'I',  'n', 's', 't',
        'r', 'u', 'm',  'e', 'n', 't',  's', ' ', '\n', 'H', 'e', 'l',  'l', 'o', 'W',  'o', 'r', 'l',  'd', ' ', 'T',
        'e', 'x', 'a',  's', ' ', 'I',  'n', 's', 't',  'r', 'u', 'm',  'e', 'n', 't',  's', ' ', '\n'};
    uint32 uartWriteSize[CDD_UART_EXAMPLE_WRITE_POLLING_NUM_TESTS] = {1U, 2U, 3U, 4U, 6U, 8U, 50U, 100U, 200U, 270U};
    VAR(McalLib_TickType, MCAL_LIB_DATA) startCount                = (McalLib_TickType)0U;
    VAR(McalLib_TickType, MCAL_LIB_DATA) elapsedCount              = (McalLib_TickType)0U;
    Cdd_Uart_WriteStatusType writeStatus;
    VAR(McalLib_TickType, MCAL_LIB_DATA)
    uarttimeout = (McalLib_TickType)26041U; /*in Us for 115200 bdrate and size 300*/
    VAR(McalLib_TickType, MCAL_LIB_DATA) timerTickCount = (McalLib_TickType)0U;

    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("Cdd_Uart_Example_Write_Polling: Sample Application - Starts!!!\n\r");

    /*  get version Info */
#if (STD_ON == CDD_UART_CFG_GET_VERSION_INFO_API)
    Cdd_Uart_GetVersionInfo(&Cdd_Uart_VersionInfo);
    AppUtils_Printf("Cdd_Uart MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Uart_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Uart_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Uart_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Uart_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Uart_VersionInfo.sw_patch_version);
#endif

    /*calculate the timer tick*/
    McalLib_GetTimerTickFromUs(uarttimeout, &timerTickCount);

    for (cycle = 0U; cycle < CDD_UART_EXAMPLE_WRITE_POLLING_NUM_TEST_CYCLE; cycle++)
    {
        for (testNum = 0U; testNum < CDD_UART_EXAMPLE_WRITE_POLLING_NUM_TESTS; testNum++)
        {
            /* Write data - Non blocking (Async) call */
            Cdd_Uart_WriteDone = FALSE;
            return_value       = Cdd_Uart_Write(CddUartConf_CddUartConfigSet_CddUartConfig_0, &uartWriteDataBuf[0U],
                                                uartWriteSize[testNum]);
            if (E_OK == return_value)
            {
                /* Tx polling */
                (void)McalLib_GetCounterValue(&startCount);
                do
                {
                    Cdd_Uart_MainFunction_Write();
                    (void)McalLib_GetElapsedValue(&startCount, &elapsedCount);
                    if (timerTickCount <= elapsedCount)
                    {
                        Cdd_Uart_ErrorCount++;
                        AppUtils_Printf("CDD_UART TX polling Timeout\n");
                        return_value = E_NOT_OK;
                        break;
                    }
                    else
                    {
                        /*  Do Nothing */
                    }
                } while (FALSE == Cdd_Uart_WriteDone);
            }
            else
            {
                /* Do nothing */
            }
        }

        /* Wait until UART is idle before deinit */
        do
        {
            /* Get write status */
            (void)Cdd_Uart_GetWriteStatus(CddUartConf_CddUartConfigSet_CddUartConfig_0, &writeStatus);
        } while (E_NOT_OK == writeStatus.Cdd_Uart_BusyStatus);
    }
    /* CDD UART DeInit */
    Cdd_Uart_Deinit();

    if ((E_OK == return_value) && (0U == Cdd_Uart_ErrorCount))
    {
        AppUtils_Printf("Cdd_Uart_Example_Write_Polling: Sample Application - Completes successfully !!!\n");
    }
    else
    {
        AppUtils_Printf("Cdd_Uart_Example_Write_Polling: Sample Application - Failed !!!\n");
    }

    return return_value;
}

/* CDD UART Write Done callback function */
void CddUartWriteDoneCallback(void)
{
    Cdd_Uart_WriteDone = TRUE;
}

/* CDD UART Read Done callback function */
void CddUartReadDoneCallback(void)
{
    Cdd_Uart_ReadDone = TRUE;
}

/* CDD UART Error callback function */
void CddUartErrorCallback(void)
{
}

/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Example_Write_Polling.c
 *********************************************************************************************************************/
