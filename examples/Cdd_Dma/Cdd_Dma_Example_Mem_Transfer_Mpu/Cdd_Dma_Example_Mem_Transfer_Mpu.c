/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
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
 *  File:       Cdd_Dma_Example_Mem_Transfer_Mpu.c
 *  Generator:  None
 *
 *  Description: The RTDMA1 MPU is enabled in this example to configure a predefined region that dictates
 *               read and write access to the transmit buffer and receive buffer. When a DMA channel attempts
 *               to access data at an illegal address, MPU outputs a security violation. Any faults in the
 *               interface are communicated to the Error Aggregator module which are sent to the Error
 *               Signaling Module (ESM) where the errors are latched and RTDMA access is blocked.
 *
 *               Configured Address Ranges:
 *               MPU Region Start Address - 0x200E0000
 *               MPU Region End Address   - 0x200E0FFF
 *               TxData Start Address     - 0x200E0100
 *               TxData End Address       - 0x200E013F
 *               RxData Start Address     - 0x200E0FDC
 *               RxData End Address       - 0x200E101B
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Cdd_Dma.h"
#include "Mcal_Lib.h"
#include "hw_pipe.h"
#include "hw_esm_cpu.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define DATASIZE           16U
#define BURST_SIZE         4U
#define TRANSFER_SIZE      16U
#define WORD_SIZE_BYTES    4U
#define MAX_WRAP_SIZE      65535U
#define WRAP_STEP_DISABLED 0U

#define SSU_LINK_2 2U

/* ESM Configuration */
#define ESM_GLOBAL_ENABLE_KEY  0x0FU
#define ESM_EVENT_RTDMA1_ERROR 139U /* ErrorAggregator_RTDMA1_HPERR */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/
/* Place buffers at specific addresses to match MPU region configuration */
__attribute__((location(0x200E0100))) VAR(uint32, AUTOMATIC) TxData[DATASIZE]; /* Send data buffer */
__attribute__((location(0x200E0FDC))) VAR(uint32, AUTOMATIC) RxData[DATASIZE]; /* Receive data buffer */

volatile VAR(uint32, AUTOMATIC) g_nmiCount = 0; /* NMI occurrence counter */
#if (STD_ON == CDD_DMA_GET_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Dma_VersionInfo;
#endif

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
static inline void                       Register_NMI_Handler(void (*handler)(void));
static inline void                       ESM_configureForNMI(void);
__attribute__((interrupt("RTINT"))) void CPU1_Custom_NMIHandler(void);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

FUNC(int, AUTOMATIC) main(void)
{
    VAR(uint16, AUTOMATIC) idx;
    VAR(Cdd_Dma_ChannelParamsType, AUTOMATIC) channelParams;
    VAR(Cdd_Dma_TransferParamsType, AUTOMATIC) transferParams;
    McalLib_TickType startTime       = 0U;
    McalLib_TickType elapsedTime     = 0U;
    McalLib_TickType timeoutTicks    = 0U;
    boolean          timeoutOccurred = FALSE;

    /* EcuM_Init() will Initialize Port and Mcu with the provided configuration */
    EcuM_Init();

    DeviceSupport_Init();

    AppUtils_Init(200000000U); /* Init App utils to enable prints */
    AppUtils_Printf("Executing Cdd_Dma_Example_Mem_Transfer_Mpu example\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\r");

#if (STD_ON == CDD_DMA_GET_VERSION_INFO_API)
    Cdd_Dma_GetVersionInfo(&Cdd_Dma_VersionInfo);
    AppUtils_Printf("CDD DMA MCAL Version Info\n\r");
    AppUtils_Printf("  Vendor ID        : %d\n\r", Cdd_Dma_VersionInfo.vendorID);
    AppUtils_Printf("  Module ID        : %d\n\r", Cdd_Dma_VersionInfo.moduleID);
    AppUtils_Printf("  SW Major Version : %d\n\r", Cdd_Dma_VersionInfo.sw_major_version);
    AppUtils_Printf("  SW Minor Version : %d\n\r", Cdd_Dma_VersionInfo.sw_minor_version);
    AppUtils_Printf("  SW Patch Version : %d\n\r", Cdd_Dma_VersionInfo.sw_patch_version);
    AppUtils_Printf("---------------------------------------------------------------\n\r");
#endif

    /* Initialize Cdd_Dma driver with configuration from EB Tresos */
    Cdd_Dma_Init(NULL_PTR);

    /* Configure custom NMI handler for CPU1 */
    Register_NMI_Handler(&CPU1_Custom_NMIHandler);

    /* Configure ESM to trigger NMI on RTDMA1 MPU violations */
    ESM_configureForNMI();

    /* Initialize test data */
    for (idx = 0; idx < DATASIZE; idx++)
    {
        TxData[idx] = idx;
        RxData[idx] = 0;
    }

    /* Configure DMA channel properties */
    channelParams.PeripheralEventTrigSrc   = CDD_DMA_TRIGGER_SOFTWARE;
    channelParams.ContinuousMode           = CDD_DMA_CONTINUOUS_MODE_ENABLED;
    channelParams.OneShotMode              = CDD_DMA_ONESHOT_MODE_ENABLED;
    channelParams.DataSize                 = CDD_DMA_CHANNEL_DATASIZE_MODE_32;
    channelParams.WrDataSize               = CDD_DMA_CHANNEL_WR_DATASIZE_MODE_32;
    channelParams.ChannelIntEnable         = CDD_DMA_CHANNEL_INTERRUPT_ENABLED;
    channelParams.ChIntMode                = CDD_DMA_INT_END_OF_TRANSFER;
    channelParams.OverflowIntEnable        = CDD_DMA_OVERFLOW_INTERRUPT_DISABLED;
    channelParams.PeripheralEvntTrigEnable = CDD_DMA_PERI_EVT_TRIG_ENABLED;

    Cdd_Dma_SetChannelProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, channelParams);

    /* Configure transfer parameters */
    /* Transfer size: 4 words per burst, 16 bursts total */
    transferParams.TransferSizeProperties.BurstSize    = BURST_SIZE;
    transferParams.TransferSizeProperties.TransferSize = TRANSFER_SIZE;

    /* Source and destination step sizes (4 bytes per 32-bit word) */
    transferParams.SrcStepSize.SrcBurstStep      = WORD_SIZE_BYTES;
    transferParams.SrcStepSize.SrcTransferStep   = WORD_SIZE_BYTES;
    transferParams.DestStepSize.DestBurstStep    = WORD_SIZE_BYTES;
    transferParams.DestStepSize.DestTransferStep = WORD_SIZE_BYTES;

    /* Source and destination addresses */
    transferParams.SrcAddress  = (uint32)TxData;
    transferParams.DestAddress = (uint32)RxData;

    /* Wrap properties (no wrapping) */
    transferParams.SrcWrapProperties.SrcWrapSize     = MAX_WRAP_SIZE;
    transferParams.SrcWrapProperties.SrcWrapStep     = WRAP_STEP_DISABLED;
    transferParams.SrcWrapProperties.SrcBegAddress   = (uint32)TxData;
    transferParams.DestWrapProperties.DestWrapSize   = MAX_WRAP_SIZE;
    transferParams.DestWrapProperties.DestWrapStep   = WRAP_STEP_DISABLED;
    transferParams.DestWrapProperties.DestBegAddress = (uint32)RxData;

    Cdd_Dma_SetTransferProperties(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, transferParams);

    Cdd_Dma_SetPeripheralEventTriggerSource(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0, CDD_DMA_TRIGGER_SOFTWARE);

    /* Start DMA channel */
    AppUtils_Printf("\n\rStarting DMA transfer...\n\r");
    Cdd_Dma_StartChannelTransfer(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    /* Process all 16 bursts - NMI should be triggered due to MPU violation */
    AppUtils_Printf("Triggering DMA transfers (expecting MPU violation)...\n\r");

    Cdd_Dma_ForcePeripheralEventTrigger(Cdd_DmaConf_CddDmaChannel_CddDmaChannel_0);

    /* Check if NMI was triggered with 5 second timeout
       Get timeout ticks for 5 seconds (5,000,000 microseconds) */
    (void)McalLib_GetTimerTickFromUs(5000000U, &timeoutTicks);

    /* Get start time */
    McalLib_GetCounterValue(&startTime);

    /* Wait for NMI with timeout */
    while ((g_nmiCount == 0U) && (timeoutOccurred == FALSE))
    {
        McalLib_GetElapsedValue(&startTime, &elapsedTime);
        if (elapsedTime >= timeoutTicks)
        {
            timeoutOccurred = TRUE;
        }
    }

    AppUtils_Printf("---------------------------------------------------------------\n\r");

    if ((g_nmiCount > 0U) && (timeoutOccurred == FALSE))
    {
        AppUtils_Printf("Cdd_Dma_Example_Mem_Transfer_Mpu example passed - NMI was triggered as expected\n\r");
    }
    else
    {
        AppUtils_Printf("Cdd_Dma_Example_Mem_Transfer_Mpu example failed \n\r");
    }

    AppUtils_Printf("---------------------------------------------------------------\n\r");

    return 0;
}

/** \brief Registers an NMI interrupt handler
 *
 * \param[in] handler is the pointer to the interrupt handler.
 * \return None
 *
 *********************************************************************************************************************/
static inline void Register_NMI_Handler(void (*handler)(void))
{
    /* Configure NMI vector and link owner */
    HWREG(PIPE_BASE + PIPE_O_NMI_VECT)        = (uint32)handler;
    HWREGB(PIPE_BASE + PIPE_O_NMI_LINK_OWNER) = SSU_LINK_2;
}

/** \brief ESM configuration to trigger NMI on RTDMA1 MPU violation
 *
 * \return None
 *
 *********************************************************************************************************************/
static inline void ESM_configureForNMI(void)
{
    uint32 groupNum, eventNum;

    /* Configure RTDMA1 error event (139) */
    groupNum                                               = ESM_EVENT_RTDMA1_ERROR / 32U; /* Group 4 */
    eventNum                                               = ESM_EVENT_RTDMA1_ERROR % 32U; /* Bit 11 */
    HWREG(ESMCPU1_BASE + ESM_CPU_O_INT_PRIO(groupNum))    |= (1U << eventNum);
    HWREG(ESMCPU1_BASE + ESM_CPU_O_INTR_EN_SET(groupNum))  = (1U << eventNum);

    /* Enable ESM globally */
    HWREGB(ESMCPU1_BASE + ESM_CPU_O_EN) = ESM_GLOBAL_ENABLE_KEY;

    /* Disable High Priority Watchdog*/
    HWREGB(ESMCPU1_BASE + ESM_CPU_O_HI_PRI_WD_CFG) = 0U;
}

/** \brief Custom NMI handler for CPU1 to handle MPU violations and other critical errors
 *
 * \return None
 *
 *********************************************************************************************************************/
__attribute__((interrupt("RTINT"))) void CPU1_Custom_NMIHandler(void)
{
    /* Increment NMI counter */
    g_nmiCount++;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Dma_Example_Mem_Transfer.c
 *********************************************************************************************************************/
