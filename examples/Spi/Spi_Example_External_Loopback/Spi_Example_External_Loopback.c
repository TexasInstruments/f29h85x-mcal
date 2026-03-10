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
 *  File:        Spi_Example_External_Loopback.c
 *  Generator:   None
 *
 *  Description: This file contains SPI example to transmit data asynchronously in LEVEL 2,
 *               and validate the receive data with respect to the expected data.
 *               This example demonstrates how to configure SPI and establish communication between
 *               C29x1 running MCAL (as master) and C29x3 running SDK (as slave). The master transmits
 *               data in incremental order (128 bytes) and the slave responds with the same data.
 *               This example will be run on C29x1 with a corresponding SDK example application running on C29x3.
 *               The SDK example application files can be found at: './Cpu3App/spi_slave_tester.syscfg'
 *               and './Cpu3App/spi_slave_tester.c'.
 *
 *  Note:        Note that when runing this example on SOM board, please note that the S2 POCI switch on the XDS110
 *               board should be set to OFF.
 *               For FLASH configuration, this example is run in FLASH BANKMODE2, where CPU3 has access to FLASH
 *               (FRI-2).
 *               Refer to the Flash Plugin documentation to know about changing FLASH BANKMODEs and more.
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
 *              -> slave sends data in incremental order starts from 0 (128 bytes)
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
 *                5. Initialize Internal Buffer using Spi_WriteIB().
 *                6. Call Spi_AsyncTransmit() with sequence ID.
 *                7. Validate Job and sequence results.
 *                8. Read data from Internal Buffer using Spi_ReadIB().
 *                9. Validate the receive data with respect to the expected data.
 *                10. Received data can be seen in Spi_DestBuf0.
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
#define SPI_BUFF_LENGTH      128U
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

Spi_DataBufferType Spi_SrcBuf0[SPI_BUFF_LENGTH];
Spi_DataBufferType Spi_DestBuf0[SPI_BUFF_LENGTH];
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
    /* Initialize Spi_SrcBuf0 with values from 0x00 to 0x7F */
    for (i = 0; i < SPI_BUFF_LENGTH; i++)
    {
        Spi_SrcBuf0[i] = (Spi_DataBufferType)i;
    }

    DeviceSupport_Init();

    /* initialize MCU PORT and SPI in ECU init */
    EcuM_Init();

    /* initialize MCU clock */
    AppUtils_Init(200000000U);
    AppUtils_Printf("Sample Application - STARTS !!!\n");
    Spi_Init(&Spi_Config);
    MCAL_LIB_EMUSTOP0;

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
    AppUtils_Printf("Transmitting data in asynchronous mode.\n");
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
    for (i = 0; i < SPI_BUFF_LENGTH; i++)
    {
        if (Spi_DestBuf0[i] != Spi_SrcBuf0[i])
        {
            AppUtils_Printf("Channel-0 Received data didn't match with expected data\n");
            returnValue = E_NOT_OK;
            break;
        }
    }

    /* deinitialize SPI driver */
    AppUtils_Printf("Deinitializing SPI.\n");
    Spi_DeInit();

    if (returnValue == E_OK)
    {
        AppUtils_Printf("Spi_Example_External_Loopback : Sample Application success\n\r");
    }
    else
    {
        AppUtils_Printf("Spi_Example_External_Loopback : Sample Application Failed\n\r");
    }

    return ((sint32)returnValue);
}
/*********************************************************************************************************************
 *  End of File: Spi_Example_External_Loopback.c
 *********************************************************************************************************************/
