/*********************************************************************************************************************
 *  COPYRIGHT
 *
 ------------------------------------------------------------------------------------------------------------------
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
 *
 ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *
 ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_I2c_Interrupt.c
 *
 * Description: TBD
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
#include "Mcu.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define APP_NAME "Cdd_I2c_Interrupt"

#define I2C_APP_PMIC_HW_UNIT     (CDD_I2C_HW_UNIT_I2CB)
#define I2C_APP_PMIC_TARGET_ADDR (0x60U)

/*
 * Sequence and channel IDs
 * Each HW unit has four sequences and 6 channels
 *      Seq 0: 1 WR only channel
 *      Seq 1: 1 RD only channel
 *      Seq 2: 1 WR channel and 1 RD channel with STOP in between
 *      Seq 4: 1 WR channel and 1 RD channel with NOSTOP in between (RESTART mode)
 */
#define I2C_APP_NUM_SEQ_PER_HW_UNIT (4U)
#define I2C_APP_NUM_CH_PER_HW_UNIT  (6U)
/* Sequence IDs */
#define I2C_APP_SEQ_ID_HW_UNIT_I2CA_WR            (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_0)
#define I2C_APP_SEQ_ID_HW_UNIT_I2CA_RD            (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_1)
#define I2C_APP_SEQ_ID_HW_UNIT_I2CA_WR_RD         (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_2)
#define I2C_APP_SEQ_ID_HW_UNIT_I2CA_WR_RD_RESTART (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_3)
#define I2C_APP_SEQ_ID_HW_UNIT_I2CB_WR            (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_4)
#define I2C_APP_SEQ_ID_HW_UNIT_I2CB_RD            (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_5)
#define I2C_APP_SEQ_ID_HW_UNIT_I2CB_WR_RD         (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_6)
#define I2C_APP_SEQ_ID_HW_UNIT_I2CB_WR_RD_RESTART (CddI2cConf_CddI2cSeqConfig_CddI2cSeqConfig_7)
/* Channel IDs */
#define I2C_APP_CH_ID_HW_UNIT_I2CA_WR               (CddI2cConf_CddI2cChConfig_CddI2cChConfig_0)
#define I2C_APP_CH_ID_HW_UNIT_I2CA_RD               (CddI2cConf_CddI2cChConfig_CddI2cChConfig_1)
#define I2C_APP_CH_ID_HW_UNIT_I2CA_WR_RD_WR         (CddI2cConf_CddI2cChConfig_CddI2cChConfig_2)
#define I2C_APP_CH_ID_HW_UNIT_I2CA_WR_RD_RD         (CddI2cConf_CddI2cChConfig_CddI2cChConfig_3)
#define I2C_APP_CH_ID_HW_UNIT_I2CA_WR_RD_WR_RESTART (CddI2cConf_CddI2cChConfig_CddI2cChConfig_4)
#define I2C_APP_CH_ID_HW_UNIT_I2CA_WR_RD_RD_RESTART (CddI2cConf_CddI2cChConfig_CddI2cChConfig_5)
#define I2C_APP_CH_ID_HW_UNIT_I2CB_WR               (CddI2cConf_CddI2cChConfig_CddI2cChConfig_6)
#define I2C_APP_CH_ID_HW_UNIT_I2CB_RD               (CddI2cConf_CddI2cChConfig_CddI2cChConfig_7)
#define I2C_APP_CH_ID_HW_UNIT_I2CB_WR_RD_WR         (CddI2cConf_CddI2cChConfig_CddI2cChConfig_8)
#define I2C_APP_CH_ID_HW_UNIT_I2CB_WR_RD_RD         (CddI2cConf_CddI2cChConfig_CddI2cChConfig_9)
#define I2C_APP_CH_ID_HW_UNIT_I2CB_WR_RD_WR_RESTART (CddI2cConf_CddI2cChConfig_CddI2cChConfig_10)
#define I2C_APP_CH_ID_HW_UNIT_I2CB_WR_RD_RD_RESTART (CddI2cConf_CddI2cChConfig_CddI2cChConfig_11)

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
static volatile boolean gI2cAppSeqDone    = FALSE;
static volatile uint8   gI2cAppSeqErrCode = CDD_I2C_E_NO_ERROR;

/* Test pass flag */
static uint32 gTestPassed = E_OK;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
static Std_ReturnType I2c_appPmicTest(void);

Std_ReturnType I2c_write(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_AddressType deviceAddress, uint8 *pWrBuf, uint16 size);
Std_ReturnType I2c_read(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_AddressType deviceAddress, uint8 *pRdBuf, uint16 size);
Std_ReturnType I2c_writeRead(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_AddressType deviceAddress, uint8 *pWrBuf,
                             uint8 *pRdBuf, uint16 wrSize, uint16 rdSize);
Std_ReturnType I2c_writeReadRestart(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_AddressType deviceAddress, uint8 *pWrBuf,
                                    uint8 *pRdBuf, uint16 wrSize, uint16 rdSize);
static void    I2c_appSequenceErrorReport(uint8 errorCode);

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
    Std_ReturnType retVal;

    DeviceSupport_Init();
    EcuM_Init();

    AppUtils_Init(200000000U);

    AppUtils_Printf(APP_NAME ": Example Application - STARTS ...\r\n");

    /*  Get version Info */
#if (CDD_I2C_VERSION_INFO_API == STD_ON)
    Std_VersionInfoType versioninfo;

    /* Get and print version */
    Cdd_I2c_GetVersionInfo(&versioninfo);
    AppUtils_Printf(" \r\n");
    AppUtils_Printf(" Cdd I2c MCAL Version Info\r\n");
    AppUtils_Printf(" -------------------------\r\n");
    AppUtils_Printf(" Vendor ID           : %d\r\n", versioninfo.vendorID);
    AppUtils_Printf(" Module ID           : %d\r\n", versioninfo.moduleID);
    AppUtils_Printf(" SW Major Version    : %d\r\n", versioninfo.sw_major_version);
    AppUtils_Printf(" SW Minor Version    : %d\r\n", versioninfo.sw_minor_version);
    AppUtils_Printf(" SW Patch Version    : %d\r\n", versioninfo.sw_patch_version);
    AppUtils_Printf(" \r\n");
#endif

    /* PMIC test */
    retVal = I2c_appPmicTest();
    if (E_OK != retVal)
    {
        gTestPassed = retVal;
        AppUtils_Printf("Err: I2C PMIC Test Failed!!\n\r");
    }

    if (E_OK == gTestPassed)
    {
        AppUtils_Printf(APP_NAME ": Example Application - ENDS (Passed)!!!\r\n");
        AppUtils_Printf(APP_NAME ": All tests have passed\r\n");
    }
    else
    {
        AppUtils_Printf(APP_NAME ": Example Application - ENDS (Failed)!!!\r\n");
    }

    Cdd_I2c_DeInit();

    return 0;
}

static Std_ReturnType I2c_appPmicTest(void)
{
    Std_ReturnType retVal = E_OK;
    uint32         loop;
    uint8          regOffset[] = {0x01U, 0x02U, 0x03U, 0x04U};
    uint8          expValues[] = {0xAEU, 0x04U, 0x01U, 0x00U};
    uint8          wrBuf[1U], rdBuf[sizeof(regOffset) / sizeof(regOffset[0U])] = {0U};

    loop = 0U;
    while (loop < 100U)
    {
        for (uint32 idx = 0U; idx < (sizeof(regOffset) / sizeof(regOffset[0U])); idx++)
        {
            /* Read device version */
            wrBuf[0U]  = regOffset[idx];
            rdBuf[idx] = 0xA5U;
            retVal =
                I2c_writeReadRestart(I2C_APP_PMIC_HW_UNIT, I2C_APP_PMIC_TARGET_ADDR, &wrBuf[0U], &rdBuf[idx], 1U, 1U);
            if (retVal == E_OK)
            {
                if (rdBuf[idx] != expValues[idx])
                {
                    AppUtils_Printf(
                        "Err: PMIC read 0x%0.2X at offset 0x%0.2X didn't match expected value of 0x%0.2X!!\r\n",
                        rdBuf[idx], regOffset[idx], expValues[idx]);
                    retVal = E_NOT_OK;
                    break;
                }
            }
            else
            {
                AppUtils_Printf("Err: PMIC read of ID failed!!\r\n");
                break;
            }
        }

        if (retVal != E_OK)
        {
            break;
        }
        loop++;
    }

    /* Print the read register values at the end */
    for (uint32 idx = 0U; idx < (sizeof(regOffset) / sizeof(regOffset[0U])); idx++)
    {
        AppUtils_Printf("PMIC (0x%0.2X) offset 0x%0.2X: 0x%0.2X!!\r\n", I2C_APP_PMIC_TARGET_ADDR, regOffset[idx],
                        rdBuf[idx]);
    }

    return retVal;
}

Std_ReturnType I2c_write(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_AddressType deviceAddress, uint8 *pWrBuf, uint16 size)
{
    Std_ReturnType             retVal = E_OK;
    Cdd_I2c_SequenceType       seqId;
    Cdd_I2c_ChannelType        wrChId;
    Cdd_I2c_ChannelResultType  chResult;
    Cdd_I2c_SequenceResultType seqResult;

    seqId   = I2C_APP_SEQ_ID_HW_UNIT_I2CA_WR;
    wrChId  = I2C_APP_CH_ID_HW_UNIT_I2CA_WR;
    seqId  += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_SEQ_PER_HW_UNIT;
    wrChId += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_CH_PER_HW_UNIT;

    /* Dynamically setup the slave address */
    retVal = Cdd_I2c_SetupEBDynamic(wrChId, deviceAddress, pWrBuf, NULL_PTR, size);
    if (retVal != E_OK)
    {
        AppUtils_Printf("Err: I2C Setup EB failed!!!\n\r");
    }

    if (retVal == E_OK)
    {
        gI2cAppSeqDone    = FALSE;
        gI2cAppSeqErrCode = CDD_I2C_E_NO_ERROR;
        retVal            = Cdd_I2c_AsyncTransmit(seqId);
        if (retVal != E_OK)
        {
            AppUtils_Printf("Err: Cdd_I2c_AsyncTransmit failed!!\n\r");
        }
        else
        {
            /* Wait for completion */
            while (1U)
            {
                /* Check if sequence is complete */
                seqResult = Cdd_I2c_GetSequenceResult(seqId);
                if (!((seqResult == CDD_I2C_SEQ_PENDING) || (seqResult == CDD_I2C_SEQ_QUEUED)))
                {
                    break;
                }
            }

            if (seqResult != CDD_I2C_SEQ_OK)
            {
                AppUtils_Printf("Err: Sequence error!!\n\r");
                retVal = E_NOT_OK;
            }

            /* Check if sequence notify is received */
            if (gI2cAppSeqDone != TRUE)
            {
                AppUtils_Printf("Err: Sequence notify not received!!\n\r");
                retVal = E_NOT_OK;
            }
            if (gI2cAppSeqErrCode != CDD_I2C_E_NO_ERROR)
            {
                I2c_appSequenceErrorReport(gI2cAppSeqErrCode);
                retVal = E_NOT_OK;
            }

            /* Check if all channel status is in complete state */
            chResult = Cdd_I2c_GetResult(wrChId);
            if (chResult != CDD_I2C_CH_RESULT_OK)
            {
                AppUtils_Printf("Err: Channel error!!\n\r");
                retVal = E_NOT_OK;
            }
        }
    }

    return retVal;
}

Std_ReturnType I2c_read(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_AddressType deviceAddress, uint8 *pRdBuf, uint16 size)
{
    Std_ReturnType             retVal = E_OK;
    Cdd_I2c_SequenceType       seqId;
    Cdd_I2c_ChannelType        rdChId;
    Cdd_I2c_ChannelResultType  chResult;
    Cdd_I2c_SequenceResultType seqResult;

    seqId   = I2C_APP_SEQ_ID_HW_UNIT_I2CA_RD;
    rdChId  = I2C_APP_CH_ID_HW_UNIT_I2CA_RD;
    seqId  += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_SEQ_PER_HW_UNIT;
    rdChId += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_CH_PER_HW_UNIT;

    /* Dynamically setup the slave address */
    retVal = Cdd_I2c_SetupEBDynamic(rdChId, deviceAddress, NULL_PTR, pRdBuf, size);
    if (retVal != E_OK)
    {
        AppUtils_Printf("Err: I2C Setup EB failed!!!\n\r");
    }

    if (retVal == E_OK)
    {
        gI2cAppSeqDone    = FALSE;
        gI2cAppSeqErrCode = CDD_I2C_E_NO_ERROR;
        retVal            = Cdd_I2c_AsyncTransmit(seqId);
        if (retVal != E_OK)
        {
            AppUtils_Printf("Err: Cdd_I2c_AsyncTransmit failed!!\n\r");
        }
        else
        {
            /* Wait for completion */
            while (1U)
            {
                /* Check if sequence is complete */
                seqResult = Cdd_I2c_GetSequenceResult(seqId);
                if (!((seqResult == CDD_I2C_SEQ_PENDING) || (seqResult == CDD_I2C_SEQ_QUEUED)))
                {
                    break;
                }
            }

            if (seqResult != CDD_I2C_SEQ_OK)
            {
                AppUtils_Printf("Err: Sequence error!!\n\r");
                retVal = E_NOT_OK;
            }

            /* Check if sequence notify is received */
            if (gI2cAppSeqDone != TRUE)
            {
                AppUtils_Printf("Err: Sequence notify not received!!\n\r");
                retVal = E_NOT_OK;
            }
            if (gI2cAppSeqErrCode != CDD_I2C_E_NO_ERROR)
            {
                I2c_appSequenceErrorReport(gI2cAppSeqErrCode);
                retVal = E_NOT_OK;
            }

            /* Check if all channel status is in complete state */
            chResult = Cdd_I2c_GetResult(rdChId);
            if (chResult != CDD_I2C_CH_RESULT_OK)
            {
                AppUtils_Printf("Err: Channel error!!\n\r");
                retVal = E_NOT_OK;
            }
        }
    }

    return retVal;
}

Std_ReturnType I2c_writeRead(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_AddressType deviceAddress, uint8 *pWrBuf,
                             uint8 *pRdBuf, uint16 wrSize, uint16 rdSize)
{
    Std_ReturnType             retVal = E_OK;
    Cdd_I2c_SequenceType       seqId;
    Cdd_I2c_ChannelType        wrChId, rdChId;
    Cdd_I2c_ChannelResultType  chResult;
    Cdd_I2c_SequenceResultType seqResult;

    seqId   = I2C_APP_SEQ_ID_HW_UNIT_I2CA_WR_RD;
    wrChId  = I2C_APP_CH_ID_HW_UNIT_I2CA_WR_RD_WR;
    rdChId  = I2C_APP_CH_ID_HW_UNIT_I2CA_WR_RD_RD;
    seqId  += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_SEQ_PER_HW_UNIT;
    wrChId += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_CH_PER_HW_UNIT;
    rdChId += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_CH_PER_HW_UNIT;

    /* Dynamically setup the slave address */
    retVal += Cdd_I2c_SetupEBDynamic(wrChId, deviceAddress, pWrBuf, NULL_PTR, wrSize);
    retVal  = Cdd_I2c_SetupEBDynamic(rdChId, deviceAddress, NULL_PTR, pRdBuf, rdSize);
    if (retVal != E_OK)
    {
        AppUtils_Printf("Err: I2C Setup EB failed!!!\n\r");
    }

    if (retVal == E_OK)
    {
        gI2cAppSeqDone    = FALSE;
        gI2cAppSeqErrCode = CDD_I2C_E_NO_ERROR;
        retVal            = Cdd_I2c_AsyncTransmit(seqId);
        if (retVal != E_OK)
        {
            AppUtils_Printf("Err: Cdd_I2c_AsyncTransmit failed!!\n\r");
        }
        else
        {
            /* Wait for completion */
            while (1U)
            {
                /* Check if sequence is complete */
                seqResult = Cdd_I2c_GetSequenceResult(seqId);
                if (!((seqResult == CDD_I2C_SEQ_PENDING) || (seqResult == CDD_I2C_SEQ_QUEUED)))
                {
                    break;
                }
            }

            if (seqResult != CDD_I2C_SEQ_OK)
            {
                AppUtils_Printf("Err: Sequence error!!\n\r");
                retVal = E_NOT_OK;
            }

            /* Check if sequence notify is received */
            if (gI2cAppSeqDone != TRUE)
            {
                AppUtils_Printf("Err: Sequence notify not received!!\n\r");
                retVal = E_NOT_OK;
            }
            if (gI2cAppSeqErrCode != CDD_I2C_E_NO_ERROR)
            {
                I2c_appSequenceErrorReport(gI2cAppSeqErrCode);
                retVal = E_NOT_OK;
            }

            /* Check if all channel status is in complete state */
            chResult = Cdd_I2c_GetResult(wrChId);
            if (chResult != CDD_I2C_CH_RESULT_OK)
            {
                AppUtils_Printf("Err: Write Channel error!!\n\r");
                retVal = E_NOT_OK;
            }
            chResult = Cdd_I2c_GetResult(rdChId);
            if (chResult != CDD_I2C_CH_RESULT_OK)
            {
                AppUtils_Printf("Err: Read Channel error!!\n\r");
                retVal = E_NOT_OK;
            }
        }
    }

    return retVal;
}

Std_ReturnType I2c_writeReadRestart(Cdd_I2c_HwUnitType hwUnitId, Cdd_I2c_AddressType deviceAddress, uint8 *pWrBuf,
                                    uint8 *pRdBuf, uint16 wrSize, uint16 rdSize)
{
    Std_ReturnType             retVal = E_OK;
    Cdd_I2c_SequenceType       seqId;
    Cdd_I2c_ChannelType        wrChId, rdChId;
    Cdd_I2c_ChannelResultType  chResult;
    Cdd_I2c_SequenceResultType seqResult;

    seqId   = I2C_APP_SEQ_ID_HW_UNIT_I2CA_WR_RD_RESTART;
    wrChId  = I2C_APP_CH_ID_HW_UNIT_I2CA_WR_RD_WR_RESTART;
    rdChId  = I2C_APP_CH_ID_HW_UNIT_I2CA_WR_RD_RD_RESTART;
    seqId  += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_SEQ_PER_HW_UNIT;
    wrChId += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_CH_PER_HW_UNIT;
    rdChId += (hwUnitId - CDD_I2C_HW_UNIT_I2CA) * I2C_APP_NUM_CH_PER_HW_UNIT;

    /* Dynamically setup the slave address */
    retVal += Cdd_I2c_SetupEBDynamic(wrChId, deviceAddress, pWrBuf, NULL_PTR, wrSize);
    retVal  = Cdd_I2c_SetupEBDynamic(rdChId, deviceAddress, NULL_PTR, pRdBuf, rdSize);
    if (retVal != E_OK)
    {
        AppUtils_Printf("Err: I2C Setup EB failed!!!\n\r");
    }

    if (retVal == E_OK)
    {
        gI2cAppSeqDone    = FALSE;
        gI2cAppSeqErrCode = CDD_I2C_E_NO_ERROR;
        retVal            = Cdd_I2c_AsyncTransmit(seqId);
        if (retVal != E_OK)
        {
            AppUtils_Printf("Err: Cdd_I2c_AsyncTransmit failed!!\n\r");
        }
        else
        {
            /* Wait for completion */
            while (1U)
            {
                /* Check if sequence is complete */
                seqResult = Cdd_I2c_GetSequenceResult(seqId);
                if (!((seqResult == CDD_I2C_SEQ_PENDING) || (seqResult == CDD_I2C_SEQ_QUEUED)))
                {
                    break;
                }
            }

            if (seqResult != CDD_I2C_SEQ_OK)
            {
                AppUtils_Printf("Err: Sequence error!!\n\r");
                retVal = E_NOT_OK;
            }

            /* Check if sequence notify is received */
            if (gI2cAppSeqDone != TRUE)
            {
                AppUtils_Printf("Err: Sequence notify not received!!\n\r");
                retVal = E_NOT_OK;
            }
            if (gI2cAppSeqErrCode != CDD_I2C_E_NO_ERROR)
            {
                I2c_appSequenceErrorReport(gI2cAppSeqErrCode);
                retVal = E_NOT_OK;
            }

            /* Check if all channel status is in complete state */
            chResult = Cdd_I2c_GetResult(wrChId);
            if (chResult != CDD_I2C_CH_RESULT_OK)
            {
                AppUtils_Printf("Err: Write Channel error!!\n\r");
                retVal = E_NOT_OK;
            }
            chResult = Cdd_I2c_GetResult(rdChId);
            if (chResult != CDD_I2C_CH_RESULT_OK)
            {
                AppUtils_Printf("Err: Read Channel error!!\n\r");
                retVal = E_NOT_OK;
            }
        }
    }

    return retVal;
}

void I2c_appSeqComplete(void)
{
    gI2cAppSeqDone = TRUE;
}

void I2c_appSeqFail(uint8 errorCode)
{
    gI2cAppSeqErrCode = errorCode;
}

static void I2c_appSequenceErrorReport(uint8 errorCode)
{
    if (CDD_I2C_E_ARBITRATION_FAILURE == errorCode)
    {
        AppUtils_Printf("Err: Arbitration lost!!\n\r");
    }
    else if (CDD_I2C_E_NACK_RECEIVED == errorCode)
    {
        AppUtils_Printf("Err: No Acknowledgement!!\n\r");
    }
    else if (CDD_I2C_E_BUS_FAILURE == errorCode)
    {
        AppUtils_Printf("Err: Bus failure!!\n\r");
    }
    else
    {
        AppUtils_Printf("Err: Unknown error!!\n\r");
    }

    return;
}
