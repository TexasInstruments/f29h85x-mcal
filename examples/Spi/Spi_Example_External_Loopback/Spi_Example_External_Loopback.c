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
 *  File:        Spi_Example_External_Loopback.c
 *  Generator:   None
 *
 *  Description: This file contains SPI example to transmit data synchronously in LEVEL 0,
 *               and validate the receive data with respect to the expected data.
 *
 *  Note:        Note that when runing this example on SOM board, please note that the S2 POCI switch on the XDS110
 *                board should be set to OFF.
 *
 *  When using CCS for debugging this Multi-core example, after launching the
 *  debug session,
 *              - Connect to CPU1 and load only the C29x1_merged.out.
 *              - After the program is loaded, run CPU1.
 *              - C29x1 configures and releases CPU3 out of reset
 *              - Connect to CPU3 target now. C29x3.out would have started execution as soon as it is released
 *                from reset.
 *
 *  SPI slave is configured as below:
 *              SPI clock at 2MHz
 *              SPI clock phase is 0 and polarity is 0
 *              Data Width is 16 bits.
 *
 * Slave functionality:
 *              -> slave sends data in incremental order starts from 0 (60 bytes)
 *
 *  SPI Slave Pins configured as:
 *    SPI-D instance
 *   -GPIO91 - SPIPICO
 *   -GPIO92 - SPIPOCI
 *   -GPIO93 - SPICLK
 *   -GPIO94 - SPIPTE
 *
 *  SPI Master Pins configured as:
 *    SPI-A instance
 *   -GPIO58 - SPIPICO
 *   -GPIO59 - SPIPOCI
 *   -GPIO60 - SPICLK
 *   -GPIO61 - SPIPTE
 *
 *  Below Functions are called in this Example:
 *                1. SPIA instance is configured controller mode with loopback Disabled.
 *                2. Init clock using MCU module
 *                3. Init UART pins using PORT module
 *                4. Call Spi_Init() to initialize SPI Driver
 *                5. Initialize Internal and External Buffers using Spi_WriteIB()
 *                       and Spi_SetupEB() respectively.
 *                6.  Call Spi_SyncTransmit() with sequence ID.
 *                7. validate Job and sequence results.
 *                8. Validate the receive data with respect to the expected data.
 *                9. received data can be seen in Spi_DestBuf0.
 *

 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Spi_Example_External_Loopback.h"
#include "DeviceSupport.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/
#define READ_WRITE_WAIT_TIME 200000000U
/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
#if (STD_ON == SPI_VERSION_INFO_API)
/*  version info variable */
Std_VersionInfoType Spi_VersionInfo;
#endif

Spi_DataBufferType Spi_SrcBuf0[60] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
                                      0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                                      0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23,
                                      0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
                                      0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B};
Spi_DataBufferType Spi_DestBuf0[60];
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
int main(void)
{
    Std_ReturnType syncTransmitStatus;
    Std_ReturnType returnValue = E_OK;
    uint32         i;
    VAR(McalLib_TickType, MCAL_LIB_DATA) startTime   = (McalLib_TickType)0U;
    VAR(McalLib_TickType, MCAL_LIB_DATA) elapsedTime = (McalLib_TickType)0U;
    DeviceSupport_Init();

    /* initialize MCU PORT and SPI in ECU init */
    EcuM_Init();

    /* initialize MCU clock */
    AppUtils_Init(200000000U);
    AppUtils_Printf("Sample Application - STARTS !!!\n");
    Spi_Init(&Spi_ConfigObj);
    MCAL_LIB_EMUSTOP0;
    /* Set SOFT bit for SPI A */
    HWREGH(0x70158000 + SPI_O_PRI) |= (SPI_PRI_FREE);
    /* Set SOFT bit for SPI B */
    HWREGH(0x70159000 + SPI_O_PRI) |= (SPI_PRI_FREE);

#if (STD_ON == SPI_VERSION_INFO_API)
    Spi_GetVersionInfo(&Spi_VersionInfo);
    AppUtils_Printf("SPI MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Spi_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Spi_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Spi_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Spi_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Spi_VersionInfo.sw_patch_version);
#endif
    /* set async mode */

    /* Initialize source buffers */
    AppUtils_Printf("Writing to internal buffer channel0.\n");
    Spi_WriteIB((Spi_ChannelType)SpiConf_SpiChannel_SpiChannel_0, Spi_SrcBuf0);

    /* Transmit data */
#if (STD_ON == SPI_HW_STATUS_API)
    /* get HW unit status */
    AppUtils_Printf("Getting hardware unit status.\n");
    if (SPI_BUSY == Spi_GetHWUnitStatus(SpiConf_SpiExternalDevice_SpiExternalDevice_0_HwUnitId0))
    {
        AppUtils_Printf("Result of Hardware unit is SPI_BUSY.\n");
        returnValue = E_NOT_OK;
    }
#endif
    /* Transmit data */
    AppUtils_Printf("Transmitting data in synchronous mode.\n");
    syncTransmitStatus = Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_0);
    AppUtils_Printf("SyncTransmit status is %d\n", syncTransmitStatus);

    McalLib_GetCounterValue(&startTime);
    do
    {
        McalLib_Delay(1U);
        Spi_MainFunction_Handling();
        (void)McalLib_GetElapsedValue(&startTime, &elapsedTime);
        if (READ_WRITE_WAIT_TIME <= elapsedTime)
        {
            AppUtils_Printf("Sequence transmission Timeout\n");
            break;
        }
        else
        {
            /*  Do Nothing */
        }
    } while (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_0) != SPI_SEQ_OK);

    /* status of the job */
    if (SPI_JOB_OK != Spi_GetJobResult(SpiConf_SpiJob_SpiJob_0))
    {
        AppUtils_Printf("Result of Job_0 is not SPI_JOB_OK.\n");
        returnValue = E_NOT_OK;
    }

    /* status of the SEQUENCE */
    AppUtils_Printf("Getting sequence status.\n");
    if (SPI_SEQ_OK != Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_0))
    {
        AppUtils_Printf("Result of sequence_0 is not SPI_SEQ_OK.\n");
        returnValue = E_NOT_OK;
    }
    Spi_ReadIB((Spi_ChannelType)SpiConf_SpiChannel_SpiChannel_0, Spi_DestBuf0);
    for (i = 0; i < 60U; i++)
    {
        if (Spi_DestBuf0[i] != Spi_SrcBuf0[i])
        {
            AppUtils_Printf("Channel-0 Received data didn't match with expected data\n");
            returnValue = E_NOT_OK;
            break;
        }
    }
    if (returnValue == E_OK)
    {
        AppUtils_Printf("SPI Transmission successful!\n");
    }

    /* deinitialize SPI driver */
    AppUtils_Printf("Deinitializing SPI.\n");
    Spi_DeInit();

    return ((sint32)returnValue);
}
/*********************************************************************************************************************
 *  End of File: Spi_Example_External_Loopback.c
 *********************************************************************************************************************/
