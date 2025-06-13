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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Spi_Example_SyncTransfer.c
 *  Generator:  None
 *
 *  Description:  This file contains SPI example to transmit data synchronously in LEVEL 0,
 *                      and validate the receive data with respect to the transmit data.
 *
 *        Below Functions are called in this Example:
 *                1. SPIA instance is configured controller mode with loopback enabled,
 *                2. Init clock using MCU module
 *                3. Init UART pins using PORT module
 *                4. Call Spi_Init() to initialize SPI Driver
 *                5. Initialize Internal and External Buffers using Spi_WriteIB()
 *                       and Spi_SetupEB() respectively.
 *                6.  Call Spi_SyncTransmit() with sequence ID.
 *                7. validate Job and sequence results.
 *                8. Validate the receive data with respect to the transmit data.
 *
 * No External connections are Required to run this Example on DUT.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Spi_Example_SyncTransfer.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/
#define BUFFER_LENGTH 4U
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

Spi_DataBufferType Spi_SrcBuf0[30] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
                                      0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14,
                                      0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E};
Spi_DataBufferType Spi_SrcBuf1[11] = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B};
Spi_DataBufferType Spi_SrcBuf2[4]  = {0x10, 0x20, 0x30, 0x40};
Spi_DataBufferType Spi_DestBuf0[30];
Spi_DataBufferType Spi_DestBuf1[11];
Spi_DataBufferType Spi_DestBuf2[4];
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

    DeviceSupport_Init();

    /* initialize MCU PORT and SPI in ECU init */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Sample Application - STARTS !!!\n");
    Spi_Init(&Spi_ConfigObj);
    /* Set SOFT bit for SPI A */
    HWREGH(0x70158000 + SPI_O_PRI) |= (SPI_PRI_SOFT);
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
    AppUtils_Printf("Writing to internal buffer channel1.\n");
    Spi_WriteIB((Spi_ChannelType)SpiConf_SpiChannel_SpiChannel_1, Spi_SrcBuf1);
    AppUtils_Printf("Writing to external buffer channel2.\n");
    Spi_SetupEB((Spi_ChannelType)SpiConf_SpiChannel_SpiChannel_2, Spi_SrcBuf2, Spi_DestBuf2, BUFFER_LENGTH);

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

    /* status of the job  and sequence */

    /* Transmit data */
    AppUtils_Printf("Transmitting data in synchronous mode.\n");
    syncTransmitStatus = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_0);
    AppUtils_Printf("SyncTransmit status is %d\n", syncTransmitStatus);

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
    for (i = 0; i < 30U; i++)
    {
        if (Spi_DestBuf0[i] != Spi_SrcBuf0[i])
        {
            AppUtils_Printf("Channel-0 Received data didn't match with sent data\n");
            returnValue = E_NOT_OK;
            break;
        }
    }
    Spi_ReadIB((Spi_ChannelType)SpiConf_SpiChannel_SpiChannel_1, Spi_DestBuf1);
    for (i = 0; i < 11U; i++)
    {
        if (Spi_DestBuf1[i] != Spi_SrcBuf1[i])
        {
            AppUtils_Printf("Channel-1 Received data didn't match with sent data\n");
            returnValue = E_NOT_OK;
            break;
        }
    }
    for (i = 0; i < 4U; i++)
    {
        if (Spi_DestBuf2[i] != Spi_SrcBuf2[i])
        {
            AppUtils_Printf("Channel-2 Received data didn't match with sent data\n");
            returnValue = E_NOT_OK;
            break;
        }
    }

    // deinitialize SPI driver
    AppUtils_Printf("Deinitializing SPI.\n");
    Spi_DeInit();

    return ((sint32)returnValue);
}

void sequence_endNotification1(void)
{
    AppUtils_Printf("Received Sequence End Notification\n");
}

void job_endNotification1(void)
{
    AppUtils_Printf("Received Job End Notification\n");
}
/*********************************************************************************************************************
 *  End of File: Spi_Example_SyncTransfer.c
 *********************************************************************************************************************/
