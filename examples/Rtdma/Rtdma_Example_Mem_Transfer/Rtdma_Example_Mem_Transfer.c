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
 *  File:         Rtdma_Example_Mem_Transfer.c
 *  Generator:    None
 *
 *  Description:This example demostrates how to use the F29H85X-SDK RTDMA with the F29H85X-MCAL-SDK.
 *   This example uses one RTDMA channel to transfer data from a buffer to another buffer in RAM. The example triggers
 *   the DMA channel repeatedly until the transfer of 16 bursts (where each burst is 4 8-bit words)has been completed.
 *   When the whole transfer is complete it will trigger the DMA interrupt.
 *   Refer to rtdma_ex1_mem_transfer example in F29H85X-SDK for the RTDMA configurations and generated the RTDMA
 *   initialization code.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "rtdma.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Mcal_Lib.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
#define myRTDMA1Ch1_BASE              RTDMA1CH1_BASE
#define myRTDMA1Ch1_SRC_BURSTSTEP     4U
#define myRTDMA1Ch1_DEST_BURSTSTEP    4U
#define myRTDMA1Ch1_BURSTSIZE         4U
#define myRTDMA1Ch1_SRC_TRANSFERSTEP  4U
#define myRTDMA1Ch1_DEST_TRANSFERSTEP 4U
#define myRTDMA1Ch1_TRANSFERSIZE      16U
#define myRTDMA1Ch1_SRC_WRAPSTEP      0U
#define myRTDMA1Ch1_DEST_WRAPSTEP     0U
#define myRTDMA1Ch1_SRC_WRAPSIZE      65535U
#define myRTDMA1Ch1_DEST_WRAPSIZE     65535U
#define DATASIZE                      16U

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
uint32         TxData[DATASIZE];  // Send data buffer
uint32         RxData[DATASIZE];  // Receive data buffer
volatile uint8 done = 0;

const void *destAddr = (const void *)RxData;
const void *srcAddr  = (const void *)TxData;

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
/* Example Application */
int main(void)
{
    uint16 idx;
    uint16 burstCount  = 0U;
    bool   burstResult = TRUE;

    DeviceSupport_Init();
    /* EcuM_Init() will Initialize Port with the provided configuration. Below API will call
    Port_Init(&Port_PortConfigSet) and will Initialize the Port and Mcu Driver */
    EcuM_Init();
    AppUtils_Init(200000000U);
    AppUtils_Printf("RTDMA Sample Application - Starts!!!\n\r");
    AppUtils_Printf("---------------------------------------------------------------\n\r");

    /* Generated code from sysconfig. Refer to rtdma_ex1_mem_transfer example in F29H85X-SDK for the RTDMA
       configurations */
    DMA_initController(RTDMA1_BASE);
    DMA_setEmulationMode(RTDMA1_BASE, DMA_EMULATION_STOP);
    DMA_setPriorityMode(RTDMA1_BASE, DMA_PRIORITY_SOFTWARE_CONFIG);
    DMA_disableMPU(RTDMA1_MPU_BASE);
    DMA_setChannelPriority(RTDMA1_BASE, DMA_CH1, DMA_CHPRIORITY2);
    DMA_lockDMAConfig(RTDMA1_BASE);

    DMA_configAddresses(myRTDMA1Ch1_BASE, destAddr, srcAddr);
    DMA_configBurst(myRTDMA1Ch1_BASE, myRTDMA1Ch1_BURSTSIZE, myRTDMA1Ch1_SRC_BURSTSTEP, myRTDMA1Ch1_DEST_BURSTSTEP);
    DMA_configTransfer(myRTDMA1Ch1_BASE, myRTDMA1Ch1_TRANSFERSIZE, myRTDMA1Ch1_SRC_TRANSFERSTEP,
                       myRTDMA1Ch1_DEST_TRANSFERSTEP);
    DMA_configWrap(myRTDMA1Ch1_BASE, myRTDMA1Ch1_SRC_WRAPSIZE, myRTDMA1Ch1_SRC_WRAPSTEP, myRTDMA1Ch1_DEST_WRAPSIZE,
                   myRTDMA1Ch1_DEST_WRAPSTEP);
    DMA_configMode(
        myRTDMA1Ch1_BASE, DMA_TRIGGER_SOFTWARE,
        DMA_CFG_ONESHOT_DISABLE | DMA_CFG_CONTINUOUS_DISABLE | DMA_CFG_READ_SIZE_32BIT | DMA_CFG_WRT_SIZE_32BIT);
    DMA_setBurstSignalingMode(myRTDMA1Ch1_BASE, DMA_BURST_SIGNALING_DISABLE);
    DMA_setInterruptMode(myRTDMA1Ch1_BASE, DMA_INT_AT_END);
    DMA_enableInterrupt(myRTDMA1Ch1_BASE);
    DMA_disableOverrunInterrupt(myRTDMA1Ch1_BASE);
    DMA_enableTrigger(myRTDMA1Ch1_BASE);
    DMA_stopChannel(myRTDMA1Ch1_BASE);

    /* Generated code ends here*/

    for (idx = 0; idx < DATASIZE; idx++)
    {
        TxData[idx] = idx;
        RxData[idx] = 0;
    }
    AppUtils_Printf("Data at source before transfer:\n\r");
    for (idx = 0; idx < DATASIZE; idx++)
    {
        AppUtils_Printf("%d ", TxData[idx]);
    }
    AppUtils_Printf("\n\rData at destination before transfer:\n\r");
    for (idx = 0; idx < DATASIZE; idx++)
    {
        AppUtils_Printf("%d ", RxData[idx]);
    }

    // Start DMA channel
    DMA_startChannel(myRTDMA1Ch1_BASE);

    done       = 0;  // Test is not done yet
    burstCount = 0;  // Initialize burst counter

    while (burstCount < myRTDMA1Ch1_TRANSFERSIZE)  // Process all 16 bursts
    {
        DMA_forceTrigger(myRTDMA1Ch1_BASE);

        // Wait until this burst completes
        while (TRUE == DMA_getBurstStatusFlag(myRTDMA1Ch1_BASE))
        {
            // Wait for burst to complete
        }

        // Check data integrity for this burst
        if (RxData[burstCount] != TxData[burstCount])
        {
            burstResult = FALSE;
            AppUtils_Printf("Burst failed at index %d (expected: %d, actual: %d) ", burstCount, burstCount,
                            RxData[burstCount]);
        }

        // Move to next burst
        burstCount++;
    }

    DMA_stopChannel(myRTDMA1Ch1_BASE);

    while (done == 0)
    {
    }
    AppUtils_Printf("\n\rData at source after transfer:\n\r");
    for (idx = 0; idx < DATASIZE; idx++)
    {
        AppUtils_Printf("%d ", TxData[idx]);
    }
    AppUtils_Printf("\n\rData at destination after transfer:\n\r");
    for (idx = 0; idx < DATASIZE; idx++)
    {
        AppUtils_Printf("%d ", RxData[idx]);
    }
    AppUtils_Printf("\n\r===============================================\n\r");
    if (burstResult == TRUE)
    {
        AppUtils_Printf("\n\rTransfer successful\n\r");
    }
    else
    {
        AppUtils_Printf("\n\r Transfer failed\n\r");
    }

    return 0;
}

/* DMA Channel ISR . This is configured in OS plugin as  CAT2 interrupt*/
void ISR_myRTDMA1Ch1(void)
{
    done = 1; /* Test done. */
    return;
}
