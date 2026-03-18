/*********************************************************************************************************************
 *  COPYRIGHT
 *
 ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2026 Texas Instruments Incorporated
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
 ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *
 ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_I2c_Target_Loopback.c
 *
 *  Description:  I2C Target (Slave) mode external loopback example.
 *                I2CA is configured as target at address 0x48.
 *                I2CB is configured as controller (master).
 *                I2CA and I2CB SDA/SCL lines are externally connected.
 *
 *                Test flow:
 *                1. Controller writes data to target, target receives and verifies.
 *                2. Controller reads data from target, controller verifies read data.
 *
 * \Note Connect as per below using external wires in the LP board
 *      - I2CA_SCL (J1 Pin 9)  to I2CB_SCL (J5 Pin 49)
 *      - I2CA_SDA (J1 Pin 10) to I2CB_SCL (J5 Pin 50)
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Os.h"
#include "Cdd_I2c.h"
#include "Port.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define APP_NAME     "Cdd_I2c_Target_Loopback"
#define APP_BUF_SIZE (8U)

#define I2C_TARGET_ADDR (0x48U)

/* Sequence IDs for I2CB controller */
#define I2C_APP_SEQ_WR (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_0)
#define I2C_APP_SEQ_RD (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_1)

/* Channel IDs for I2CB controller */
#define I2C_APP_CH_WR (CddI2cConf_CddI2cChConfig_CddI2cChConfig_0)
#define I2C_APP_CH_RD (CddI2cConf_CddI2cChConfig_CddI2cChConfig_1)

/*******************************************************************************************************************
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

/* Target-side buffers */
static uint8 gTargetRxBuf[APP_BUF_SIZE];
static uint8 gTargetTxBuf[APP_BUF_SIZE];

/* Controller-side buffers */
static uint8 gCtrlWrBuf[APP_BUF_SIZE];
static uint8 gCtrlRdBuf[APP_BUF_SIZE];

/* ISR -> main loop flags */
static volatile boolean gSeqDone    = FALSE;
static volatile uint8   gSeqErrCode = CDD_I2C_E_NO_ERROR;

/* Target callback flags */
static volatile boolean gTargetRxDone  = FALSE;
static volatile uint16  gTargetRxCount = 0U;
static volatile boolean gTargetTxDone  = FALSE;
static volatile boolean gTargetErrFlag = FALSE;
static volatile uint8   gTargetLastErr = 0U;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

static Std_ReturnType I2c_appWaitSeqDone(Cdd_I2c_SequenceType seqId);
static Std_ReturnType I2c_appRunLoopbackTest(void);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Target callback implementations (called from ISR context)
 *********************************************************************************************************************/

void I2c_appTargetRxStartCallback(Cdd_I2c_HwUnitType hwUnitId)
{
    (void)hwUnitId;
}

void I2c_appTargetRxCompleteCallback(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_DataPtrType pRxData,
                                     Cdd_I2c_DataLengthType rxCount, uint8 status)
{
    (void)pRxData;

    gTargetRxCount = rxCount;
    gTargetRxDone  = TRUE;

    if (status == CDD_I2C_TARGET_EVENT_RX_OVERFLOW)
    {
        gTargetErrFlag = TRUE;
        gTargetLastErr = CDD_I2C_TARGET_EVENT_RX_OVERFLOW;
    }

    /* Re-submit RX buffer for next transaction */
    Cdd_I2c_TargetSubmitRxBuffer(hwUnitId, gTargetRxBuf, APP_BUF_SIZE);
}

void I2c_appTargetTxStartCallback(Cdd_I2c_HwUnitType hwUnitId)
{
    (void)hwUnitId;
}

void I2c_appTargetTxCompleteCallback(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_DataConstPtrType pTxData,
                                     Cdd_I2c_DataLengthType txCount, uint8 status)
{
    (void)pTxData;
    (void)txCount;

    gTargetTxDone = TRUE;

    if (status == CDD_I2C_TARGET_EVENT_TX_UNDERFLOW)
    {
        gTargetErrFlag = TRUE;
        gTargetLastErr = CDD_I2C_TARGET_EVENT_TX_UNDERFLOW;
    }

    /* Re-submit TX buffer for next transaction */
    Cdd_I2c_TargetSubmitTxBuffer(hwUnitId, gTargetTxBuf, APP_BUF_SIZE);
}

void I2c_appTargetErrorCallback(Cdd_I2c_HwUnitType hwUnitId, uint8 errorCode)
{
    (void)hwUnitId;

    gTargetErrFlag = TRUE;
    gTargetLastErr = errorCode;
}

/*********************************************************************************************************************
 *  Controller sequence callbacks
 *********************************************************************************************************************/

void I2c_appSeqComplete(void)
{
    gSeqDone = TRUE;
}

void I2c_appSeqFail(uint8 errorCode)
{
    gSeqErrCode = errorCode;
}

/*********************************************************************************************************************
 *  Local helper: wait for controller sequence completion
 *********************************************************************************************************************/

static Std_ReturnType I2c_appWaitSeqDone(Cdd_I2c_SequenceType seqId)
{
    Cdd_I2c_SequenceResultType seqResult;

    while (1U)
    {
        seqResult = Cdd_I2c_GetSequenceResult(seqId);
        if (!((seqResult == CDD_I2C_SEQ_PENDING) || (seqResult == CDD_I2C_SEQ_QUEUED)))
        {
            break;
        }
    }

    if (seqResult != CDD_I2C_SEQ_OK)
    {
        return E_NOT_OK;
    }

    if (gSeqDone != TRUE)
    {
        return E_NOT_OK;
    }

    if (gSeqErrCode != CDD_I2C_E_NO_ERROR)
    {
        return E_NOT_OK;
    }

    return E_OK;
}

/*********************************************************************************************************************
 *  Local helper: run a full loopback test (write + read + verify)
 *********************************************************************************************************************/

static Std_ReturnType I2c_appRunLoopbackTest(void)
{
    Std_ReturnType retVal;
    uint32         idx;

    /* Prepare write buffer */
    for (idx = 0U; idx < APP_BUF_SIZE; idx++)
    {
        gCtrlWrBuf[idx] = (uint8)(idx);
    }

    /* -- Controller write -> Target receive -- */
    gSeqDone      = FALSE;
    gSeqErrCode   = CDD_I2C_E_NO_ERROR;
    gTargetRxDone = FALSE;

    retVal = Cdd_I2c_SetupEBDynamic(I2C_APP_CH_WR, I2C_TARGET_ADDR, gCtrlWrBuf, NULL_PTR, APP_BUF_SIZE);
    if (retVal != E_OK)
    {
        AppUtils_Printf(APP_NAME ": Err: SetupEB WR failed\r\n");
        return E_NOT_OK;
    }

    retVal = Cdd_I2c_AsyncTransmit(I2C_APP_SEQ_WR);
    if (retVal != E_OK)
    {
        AppUtils_Printf(APP_NAME ": Err: AsyncTransmit WR failed\r\n");
        return E_NOT_OK;
    }

    retVal = I2c_appWaitSeqDone(I2C_APP_SEQ_WR);
    if (retVal != E_OK)
    {
        AppUtils_Printf(APP_NAME ": Err: WR sequence failed\r\n");
        return E_NOT_OK;
    }

    /* Verify target received data correctly */
    for (idx = 0U; idx < APP_BUF_SIZE; idx++)
    {
        if (gTargetRxBuf[idx] != gCtrlWrBuf[idx])
        {
            AppUtils_Printf(APP_NAME ": Err: Target RX mismatch at [%lu]: got 0x%02X, expected 0x%02X\r\n", idx,
                            gTargetRxBuf[idx], gCtrlWrBuf[idx]);
            return E_NOT_OK;
        }
    }

    /* -- Controller read <- Target transmit -- */
    for (idx = 0U; idx < APP_BUF_SIZE; idx++)
    {
        gCtrlRdBuf[idx] = 0xFFU;
    }

    gSeqDone      = FALSE;
    gSeqErrCode   = CDD_I2C_E_NO_ERROR;
    gTargetTxDone = FALSE;

    retVal = Cdd_I2c_SetupEBDynamic(I2C_APP_CH_RD, I2C_TARGET_ADDR, NULL_PTR, gCtrlRdBuf, APP_BUF_SIZE);
    if (retVal != E_OK)
    {
        AppUtils_Printf(APP_NAME ": Err: SetupEB RD failed\r\n");
        return E_NOT_OK;
    }

    retVal = Cdd_I2c_AsyncTransmit(I2C_APP_SEQ_RD);
    if (retVal != E_OK)
    {
        AppUtils_Printf(APP_NAME ": Err: AsyncTransmit RD failed\r\n");
        return E_NOT_OK;
    }

    retVal = I2c_appWaitSeqDone(I2C_APP_SEQ_RD);
    if (retVal != E_OK)
    {
        AppUtils_Printf(APP_NAME ": Err: RD sequence failed\r\n");
        return E_NOT_OK;
    }

    /* Verify controller read data matches target TX buffer */
    for (idx = 0U; idx < APP_BUF_SIZE; idx++)
    {
        if (gCtrlRdBuf[idx] != gTargetTxBuf[idx])
        {
            AppUtils_Printf(APP_NAME ": Err: Controller RD mismatch at [%lu]: got 0x%02X, expected 0x%02X\r\n", idx,
                            gCtrlRdBuf[idx], gTargetTxBuf[idx]);
            return E_NOT_OK;
        }
    }

    /* Check for target errors */
    if (gTargetErrFlag == TRUE)
    {
        AppUtils_Printf(APP_NAME ": Err: Target error 0x%02X\r\n", gTargetLastErr);
        return E_NOT_OK;
    }

    return E_OK;
}

/*********************************************************************************************************************
 *  Main
 *********************************************************************************************************************/

int main(void)
{
    Std_ReturnType retVal;
    uint32         idx;

    DeviceSupport_Init();
    EcuM_Init();

    AppUtils_Init(200000000U);

    AppUtils_Printf(APP_NAME ": Example Application - STARTS ...\r\n");
    AppUtils_Printf(APP_NAME ": I2CA: target at 0x48, I2CB: controller (external loopback)\r\n");

    /* Pre-fill target TX buffer with known pattern */
    for (idx = 0U; idx < APP_BUF_SIZE; idx++)
    {
        gTargetTxBuf[idx] = (uint8)(idx + 0x10U);
        gTargetRxBuf[idx] = 0U;
    }

    /* Submit target buffers and start target mode on I2CA */
    Cdd_I2c_TargetSubmitRxBuffer(CDD_I2C_HW_UNIT_I2CA, gTargetRxBuf, APP_BUF_SIZE);
    Cdd_I2c_TargetSubmitTxBuffer(CDD_I2C_HW_UNIT_I2CA, gTargetTxBuf, APP_BUF_SIZE);
    Cdd_I2c_TargetStart(CDD_I2C_HW_UNIT_I2CA);

    AppUtils_Printf(APP_NAME ": Target started.\r\n");

    /*
     * Loopback: Controller write -> Target receive, then Controller read <- Target transmit
     */
    retVal = I2c_appRunLoopbackTest();
    if (retVal == E_OK)
    {
        AppUtils_Printf(APP_NAME ": Loopback PASS\r\n");
    }
    else
    {
        AppUtils_Printf(APP_NAME ": Loopback FAIL\r\n");
    }

    /* Cleanup */
    Cdd_I2c_TargetStop(CDD_I2C_HW_UNIT_I2CA);
    Cdd_I2c_DeInit();

    return 0;
}
