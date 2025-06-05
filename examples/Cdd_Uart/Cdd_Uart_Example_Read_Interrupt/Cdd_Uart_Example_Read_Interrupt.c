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
 *  File:       Cdd_Uart_Example_Read_Interrupt.c
 *  Generator:  None
 *
 *  Description:  Cdd_Uart example source file. This program demonstrates the usage of the Cdd_Uart
 *driver in interrupt mode,  showcasing its capabilities in receiving data. The program initializes
 *the UART instance, reads data into the receive buffer.
 *
 * Steps followed in the example:
 * Cdd_Uart_Init()
 * Initialize the Cdd_Uart instance and set up the receive buffer
 * Read data to the transmit buffer using the Cdd_Uart_Read function
 * Wait for the reception to complete using the CddUartReadDoneCallback function
 * Cdd_Uart_Deinit()
 * Verification of Cdd_Uart read interrupt functionality
 * The program read data into the receive buffer and verifies that the reception is completed,
 * demonstrating the reliability and functionality of the Cdd_Uart driver in interrupt mode.
 *
 * \b External \b Connections \n
 *    - Connect GPIO86 (Tx pin) to the target's Rx pin, and connect GPIO77 (Rx pin) to the target's
 *Tx pin.
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
#define CDD_UART_EXAMPLE_READ_INTERRUPT_MAX_SIZE       (270U)
#define CDD_UART_EXAMPLE_WRITE_INTERRUPT_WRITE_TIMEOUT (50000U)
#define CDD_UART_EXAMPLE_READ_INTERRUPT_NUM_TESTS      (5U)
#define CDD_UART_EXAMPLE_READ_INTERRUPT_NUM_TEST_CYCLE (2U)

#define CDD_UART_OS_COUNTER_ID (0U)
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
/* CDD UART Error callback function status */
uint32 Cdd_Uart_Error = FALSE;
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
    uint32                  testNum      = 0U;
    uint32                  cycle        = 0U;
    Std_ReturnType          return_value = E_NOT_OK;
    Cdd_Uart_DataBufferType uartReadDataBuf[CDD_UART_EXAMPLE_READ_INTERRUPT_MAX_SIZE];
    uint32                  uartReadSize[CDD_UART_EXAMPLE_READ_INTERRUPT_NUM_TESTS] = {1U, 2U, 3U, 4U, 6U};
    Cdd_Uart_ReadStatusType readStatus;

    DeviceSupport_Init();
    EcuM_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("Cdd_Uart_Example_Read_Interrupt: Sample Application - Starts!!!\n\r");

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

    for (cycle = 0U; cycle < CDD_UART_EXAMPLE_READ_INTERRUPT_NUM_TEST_CYCLE; cycle++)
    {
        /* CDD UART Init */
        Cdd_Uart_Init(NULL_PTR);

        for (testNum = 0U; testNum < CDD_UART_EXAMPLE_READ_INTERRUPT_NUM_TESTS; testNum++)
        {
            /* Read data - Non blocking (Async) call */
            Cdd_Uart_ReadDone = FALSE;
            Cdd_Uart_Error    = FALSE;
            return_value      = Cdd_Uart_Read(CddUartConf_CddUartConfigSet_CddUartConfig_0, &uartReadDataBuf[0U],
                                              uartReadSize[testNum]);
            if (E_OK == return_value)
            {
                do
                {
                    McalLib_Delay(1U);

                } while ((FALSE == Cdd_Uart_ReadDone) && (FALSE == Cdd_Uart_Error));
            }
            else
            {
                /* Do nothing */
            }

            if (TRUE == Cdd_Uart_Error)
            {
                Cdd_Uart_ErrorCount++;
            }
            for (int i = 0; i < uartReadSize[testNum]; i++)
            {
                AppUtils_Printf("%c", uartReadDataBuf[i]);
            }
            AppUtils_Printf("\n");
        }

        /* Wait until UART is idle before deinit */
        do
        {
            McalLib_Delay(1U);
            /* Get read status */
            (void)Cdd_Uart_GetReadStatus(CddUartConf_CddUartConfigSet_CddUartConfig_0, &readStatus);
        } while (E_NOT_OK == readStatus.Cdd_Uart_BusyStatus);

        /* CDD UART DeInit */
        Cdd_Uart_Deinit();
    }

    if ((E_OK == return_value) && (0U == Cdd_Uart_ErrorCount))
    {
        AppUtils_Printf("Cdd_Uart_Example_Read_Interrupt: Sample Application - Completes successfully !!!\n");
    }
    else
    {
        AppUtils_Printf("Cdd_Uart_Example_Read_Interrupt: Sample Application - Failed !!!\n");
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
    Cdd_Uart_Error = TRUE;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Uart_Example_Read_Interrupt.c
 *********************************************************************************************************************/
