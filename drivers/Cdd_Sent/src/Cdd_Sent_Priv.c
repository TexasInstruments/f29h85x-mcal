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
 *  File:       Cdd_Sent_Priv.c
 *  Generator:  None
 *
 *  Description:  This file contains private function definitions for CDD SENT
 *
 *********************************************************************************************************************/
/*
 * Design: MCAL-28619
 */
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Sent_Priv.h"
#include "Mcal_Lib_RegAccess.h"

/* Design: MCAL-29151 */
#if (STD_ON == CDD_SENT_CFG_DEM_ENABLE)
#include "Dem.h"
#endif /*CDD_SENT_CFG_DEM_ENABLE*/
/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

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
#define CDD_SENT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Sent_MemMap.h"
P2VAR(Cdd_Sent_DriverObjType, CDD_SENT_VAR_FAST_NO_INIT, CDD_SENT_VAR_FAST_NO_INIT)
Cdd_Sent_DrvObjPtr;
#define CDD_SENT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Cdd_Sent_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
/** \brief Cdd_Sent_SetCRCConfigPriv : Performs CRC setting as per Configuration.
 *
 * \param[in] ConfigPtr is the structure containing Sent HW unit configuration.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_SetCRCConfigPriv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr);

/** \brief Cdd_Sent_EnableSentReceiverPriv : Enables Sent Receiver for all Channels.
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_SENT_CODE) Cdd_Sent_EnableSentReceiverPriv(void);

/** \brief Cdd_Sent_ProcessIsrFastInterrupts : Process the Fast Channel Interrupts when
 *Cdd_Sent_ProcessISR is called.
 *
 * \param[in] Sent_Instance_Object Configuration pointer to Sent HW Unit.
 * \param[in] instance_index Index of channel present in config.
 * \param[in] Interrupt_Status_Register is the status of interrupt register.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_ProcessIsrFastInterrupts(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Instance_Object,
                                      const CddSent_ValueType instance_index, uint32 Interrupt_Status_Register);

/** \brief Cdd_Sent_ProcessIsrSlowInterrupts : Process the Slow Channel Interrupts when
 *Cdd_Sent_ProcessISR is called.
 *
 * \param[in] Sent_Instance_Object Configuration pointer to Sent HW Unit.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_ProcessIsrSlowInterrupts(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Instance_Object);

/** \brief Cdd_Sent_ProcessIsrCallCddSentUserErrorCallbackFunction : Calls
 *CddSentUserErrorCallbackFunction.
 *
 * \param[in] Sent_Instance_Object Configuration pointer to Sent HW Unit.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_ProcessIsrCallCddSentUserErrorCallbackFunction(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA)
                                                                Sent_Instance_Object);

/** \brief Cdd_Sent_SetHandleIdPriv : Set the Handle Id for all Channels of Sent HW Unit whose
 *Channel Type and Sensor Type are valid.
 *
 * \param[in] Cdd_Sent_DriverObj Cdd_Sent_DrvObj is the Cdd_Sent driver object defined in Cdd_Sent.c
 * \param[in] Sent_Hw_Unit Pointer to Sent HW Unit Configuration.
 * \param[in] loop_count Index to Sent HW Unit.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_SetHandleIdPriv(P2VAR(Cdd_Sent_DriverObjType, AUTOMATIC, CDD_SENT_APPL_DATA) Cdd_Sent_DriverObj,
                             P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Hw_Unit, uint32 loop_count);
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_SENT_START_SEC_CODE
#include "Cdd_Sent_MemMap.h"
FUNC(void, CDD_SENT_CODE) Cdd_Sent_SetDriverObjPtr(Cdd_Sent_DriverObjType *Set_DrvObj)
{
    Cdd_Sent_DrvObjPtr = Set_DrvObj;
}

/*
 *Design: MCAL-28672
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_HwInitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr)
{
    VAR(uint32, AUTOMATIC) BaseAddress = ConfigPtr->CddSentBaseAddress;

    VAR(uint32, AUTOMATIC) DataNibblesCount = ConfigPtr->CddSentDataNibblesCount;

    /* Disable SENT receiver */
    Cdd_Sent_disableSentReceiver(BaseAddress);

    /* Disable interrupt sources*/
    Cdd_Sent_disableInterrupt(BaseAddress, (0xFFFFFFFFU));

    /* Enable interrupt sources*/
    Cdd_Sent_enableInterrupt(BaseAddress, SENT_ENABLE_INTERRUPT_SOURCES);

    /* Configure CRC settings */
    Cdd_Sent_SetCRCConfigPriv(ConfigPtr);

    /* Configuring Tick clock */
    HWREG(BaseAddress + SENT_O_RCFG) = ConfigPtr->CddSentClockTick << SENT_RCFG_TTCLK_S;

    /* Configuring GFlit */
    Cdd_Sent_setGFILTClockCycle(BaseAddress, ConfigPtr->CddSentGlitchFilter);

    /* set data nibbles count*/
    Cdd_Sent_setDataNibble(BaseAddress, ConfigPtr->CddSentDataNibblesCount);

    /* Map data nibbles to data 0*/
    for (uint32 DataMap = (uint32)CDD_SENT_DATAX_NIB0; DataMap <= (uint32)CDD_SENT_DATAX_NIB7; DataMap++)
    {
        if (DataNibblesCount > 0x0U)
        {
            Cdd_Sent_setDataSortingFormat(BaseAddress, CDD_SENT_RECEIVER_DATA0, DataMap, DataNibblesCount);
            DataNibblesCount = DataNibblesCount - 0x1U;
        }
    }
    Cdd_Sent_setDataSortingFormat(BaseAddress, CDD_SENT_RECEIVER_DATA1, CDD_SENT_CRC_NIBBLE_PS_0,
                                  CDD_SENT_CRC_NIBBLE_1);
    Cdd_Sent_setDataSortingFormat(BaseAddress, CDD_SENT_RECEIVER_DATA1, CDD_SENT_CRC_NIBBLE_PS_1,
                                  CDD_SENT_CRC_NIBBLE_2);
    Cdd_Sent_setDataSortingFormat(BaseAddress, CDD_SENT_RECEIVER_DATA1, CDD_SENT_CRC_NIBBLE_PS_2,
                                  CDD_SENT_CRC_STATUS_NIBBLE);

    /* Configuring the Accepting error data based on the configuration. */
    if (TRUE == ConfigPtr->CddSentAcceptErrorData)
    {
        /* Enable Error date to written into fifo */
        McalLib_RegBitClear32((BaseAddress + SENT_O_RCFG2), SENT_RCFG2_NOWR_ERRDATA);
    }
    else
    {
        /* Disable Error date to written into memory */
        McalLib_RegBitSet32((BaseAddress + SENT_O_RCFG2), SENT_RCFG2_NOWR_ERRDATA);
    }

    Cdd_Sent_configureTimeout(BaseAddress, ConfigPtr->CddSentSyncTimeout);

    if (ConfigPtr->CddSentEnableTimeStamp == TRUE)
    {
        /* Enable Timestamp */
        McalLib_RegBitClear32((BaseAddress + SENT_O_RCFG2), SENT_RCFG2_TSTAMP_DIS);
    }

    if (ConfigPtr->CddSentMTP == FALSE)
    {
        /* Enable the FIFO mode */
        Sent_ConfigureFifoMode(BaseAddress, CDD_SENT_FIFOMODE_FIFO);

        /* Configure trigger level */
        Cdd_Sent_setRFIFOTriggerLevel(BaseAddress, ConfigPtr->CddSentFIFOTriggerLevel);
    }

    /* Configuring the MTP based on the configuration. */
    if (TRUE == ConfigPtr->CddSentMTP)
    {
        /* Enable MTP mode */
        McalLib_RegBitSet32((BaseAddress + SENT_O_RCFG2), SENT_RCFG2_MTP_MODE);
        Cdd_Sent_setMTPWaitTime(BaseAddress, ConfigPtr->CddSentGlobalWaitTime);
        Cdd_Sent_MTPInitPrv(ConfigPtr);
    }
    else
    {
        /* Disable MTP mode */
        McalLib_RegBitClear32((BaseAddress + SENT_O_RCFG2), SENT_RCFG2_MTP_MODE);
    }
}

/*
 *Design: MCAL-28674
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_MTPInitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr)
{
    P2VAR(Cdd_Sent_MTPConfigType, AUTOMATIC, CDD_SENT_APPL_DATA) MTPSensorConfig = NULL;
    VAR(uint8, AUTOMATIC) Sensor_Count                                           = (uint8)0U;
    VAR(uint32, AUTOMATIC) MtptriggerOffset;
    for (Sensor_Count = 0U; Sensor_Count < ConfigPtr->CddSentMTPChannelCount; Sensor_Count++)
    {
        MTPSensorConfig = ConfigPtr->CddSentMTPConfigList[Sensor_Count];
        if (TRUE == MTPSensorConfig->CddSentMTPSensorEnable)
        {
            Cdd_Sent_enableMTPChannel(ConfigPtr->CddSentBaseAddress, MTPSensorConfig->CddSentMTPSensorType);
            Cdd_Sent_setMTPPeriod(ConfigPtr->CddSentBaseAddress, MTPSensorConfig->CddSentMTPSensorType,
                                  MTPSensorConfig->CddSentMTPSensorPeriod);

            MtptriggerOffset = (SENT_MTP_SWTR_STEP * (uint32)MTPSensorConfig->CddSentMTPSensorType) + SENT_O_BC_TRIGSEL;

            HWREG(ConfigPtr->CddSentBaseAddress + MtptriggerOffset) |= (uint32)MTPSensorConfig->CddSentTriggerSource;

            switch (MTPSensorConfig->CddSentMTPSensorType)
            {
                case CDD_SENT_CHANNEL_BROADCAST:

                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 1,
                                                         MTPSensorConfig->CddSentMTPSensorCompare1);
                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 2,
                                                         MTPSensorConfig->CddSentMTPSensorCompare2);
                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 3,
                                                         MTPSensorConfig->CddSentMTPSensorCompare3);
                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 4,
                                                         MTPSensorConfig->CddSentMTPSensorCompare4);
                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 5,
                                                         MTPSensorConfig->CddSentMTPSensorCompare5);
                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 6,
                                                         MTPSensorConfig->CddSentMTPSensorCompare6);
                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 7,
                                                         MTPSensorConfig->CddSentMTPSensorCompare7);
                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 8,
                                                         MTPSensorConfig->CddSentMTPSensorCompare8);
                    Cdd_Sent_setBroadcastChMTPToggleTime(ConfigPtr->CddSentBaseAddress, 9,
                                                         MTPSensorConfig->CddSentMTPSensorCompare9);
                    break;

                case CDD_SENT_CHANNEL_SENSOR_1:

                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 1,
                                                     MTPSensorConfig->CddSentMTPSensorCompare1);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 2,
                                                     MTPSensorConfig->CddSentMTPSensorCompare2);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 3,
                                                     MTPSensorConfig->CddSentMTPSensorCompare3);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 4,
                                                     MTPSensorConfig->CddSentMTPSensorCompare4);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 5,
                                                     MTPSensorConfig->CddSentMTPSensorCompare5);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 6,
                                                     MTPSensorConfig->CddSentMTPSensorCompare6);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 7,
                                                     MTPSensorConfig->CddSentMTPSensorCompare7);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 8,
                                                     MTPSensorConfig->CddSentMTPSensorCompare8);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 9,
                                                     MTPSensorConfig->CddSentMTPSensorCompare9);
                    Cdd_Sent_setSensor1MTPToggleTime(ConfigPtr->CddSentBaseAddress, 10,
                                                     MTPSensorConfig->CddSentMTPSensorCompare10);
                    Cdd_Sent_configureMTPTimeout(ConfigPtr->CddSentBaseAddress, CDD_SENT_CHANNEL_SENSOR_1,
                                                 MTPSensorConfig->CddSentMTPSensorTimeout);
                    Cdd_Sent_enableInterrupt(ConfigPtr->CddSentBaseAddress, SENT_REINT_RFAST_S1DV_E);
                    break;

                case CDD_SENT_CHANNEL_SENSOR_2:

                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 1,
                                                     MTPSensorConfig->CddSentMTPSensorCompare1);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 2,
                                                     MTPSensorConfig->CddSentMTPSensorCompare2);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 3,
                                                     MTPSensorConfig->CddSentMTPSensorCompare3);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 4,
                                                     MTPSensorConfig->CddSentMTPSensorCompare4);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 5,
                                                     MTPSensorConfig->CddSentMTPSensorCompare5);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 6,
                                                     MTPSensorConfig->CddSentMTPSensorCompare6);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 7,
                                                     MTPSensorConfig->CddSentMTPSensorCompare7);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 8,
                                                     MTPSensorConfig->CddSentMTPSensorCompare8);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 9,
                                                     MTPSensorConfig->CddSentMTPSensorCompare9);
                    Cdd_Sent_setSensor2MTPToggleTime(ConfigPtr->CddSentBaseAddress, 10,
                                                     MTPSensorConfig->CddSentMTPSensorCompare10);
                    Cdd_Sent_configureMTPTimeout(ConfigPtr->CddSentBaseAddress, CDD_SENT_CHANNEL_SENSOR_2,
                                                 MTPSensorConfig->CddSentMTPSensorTimeout);
                    Cdd_Sent_enableInterrupt(ConfigPtr->CddSentBaseAddress, SENT_REINT_RFAST_S2DV_E);
                    break;

                case CDD_SENT_CHANNEL_SENSOR_3:

                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 1,
                                                     MTPSensorConfig->CddSentMTPSensorCompare1);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 2,
                                                     MTPSensorConfig->CddSentMTPSensorCompare2);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 3,
                                                     MTPSensorConfig->CddSentMTPSensorCompare3);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 4,
                                                     MTPSensorConfig->CddSentMTPSensorCompare4);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 5,
                                                     MTPSensorConfig->CddSentMTPSensorCompare5);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 6,
                                                     MTPSensorConfig->CddSentMTPSensorCompare6);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 7,
                                                     MTPSensorConfig->CddSentMTPSensorCompare7);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 8,
                                                     MTPSensorConfig->CddSentMTPSensorCompare8);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 9,
                                                     MTPSensorConfig->CddSentMTPSensorCompare9);
                    Cdd_Sent_setSensor3MTPToggleTime(ConfigPtr->CddSentBaseAddress, 10,
                                                     MTPSensorConfig->CddSentMTPSensorCompare10);
                    Cdd_Sent_configureMTPTimeout(ConfigPtr->CddSentBaseAddress, CDD_SENT_CHANNEL_SENSOR_3,
                                                 MTPSensorConfig->CddSentMTPSensorTimeout);
                    Cdd_Sent_enableInterrupt(ConfigPtr->CddSentBaseAddress, SENT_REINT_RFAST_S3DV_E);
                    break;

                case CDD_SENT_CHANNEL_SENSOR_4:

                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 1,
                                                     MTPSensorConfig->CddSentMTPSensorCompare1);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 2,
                                                     MTPSensorConfig->CddSentMTPSensorCompare2);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 3,
                                                     MTPSensorConfig->CddSentMTPSensorCompare3);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 4,
                                                     MTPSensorConfig->CddSentMTPSensorCompare4);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 5,
                                                     MTPSensorConfig->CddSentMTPSensorCompare5);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 6,
                                                     MTPSensorConfig->CddSentMTPSensorCompare6);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 7,
                                                     MTPSensorConfig->CddSentMTPSensorCompare7);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 8,
                                                     MTPSensorConfig->CddSentMTPSensorCompare8);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 9,
                                                     MTPSensorConfig->CddSentMTPSensorCompare9);
                    Cdd_Sent_setSensor4MTPToggleTime(ConfigPtr->CddSentBaseAddress, 10,
                                                     MTPSensorConfig->CddSentMTPSensorCompare10);
                    Cdd_Sent_configureMTPTimeout(ConfigPtr->CddSentBaseAddress, CDD_SENT_CHANNEL_SENSOR_4,
                                                 MTPSensorConfig->CddSentMTPSensorTimeout);
                    Cdd_Sent_enableInterrupt(ConfigPtr->CddSentBaseAddress, SENT_REINT_RFAST_S4DV_E);
                    break;

                default:
                    break;
            }
        }
        else
        {
            Cdd_Sent_disableMTPChannel(ConfigPtr->CddSentBaseAddress, MTPSensorConfig->CddSentMTPSensorType);
        }
    }
}

/*
 *Design: MCAL-28675
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_TriggerPrv(uint8 Instance_Id, Cdd_SentTriggerSource Trigger_Source, uint8 Channel_Id,
                    P2CONST(PduInfoType, AUTOMATIC, CDD_SENT_CONST) PduInfoPtr)
{
    VAR(CddSent_ValueType, AUTOMATIC) instance_index = CDD_SENT_MAX_32BIT_VAL;
    VAR(uint32, AUTOMATIC) triggerOffset;
    (void)Cdd_Sent_GetChIdxPriv(Cdd_Sent_DrvObjPtr, Instance_Id, &instance_index);
    Cdd_Sent_HWUnitType *Sent_Hw_Sentance = Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[instance_index];
    triggerOffset                         = (SENT_MTP_SWTR_STEP * (uint32)Channel_Id) + SENT_O_BC_TRIGSEL;
    if (0U == *PduInfoPtr->SduDataPtr)
    {
        HWREG(Sent_Hw_Sentance->CddSentBaseAddress + triggerOffset) &= ~(uint32)(0x3F);
        /* Enable broadcast channel's software trigger. */
        HWREG(Sent_Hw_Sentance->CddSentBaseAddress + triggerOffset) |= (uint32)CDD_SENT_TRIGGER_DISABLE;
    }
    else if (1U == *PduInfoPtr->SduDataPtr)
    {
        HWREG(Sent_Hw_Sentance->CddSentBaseAddress + triggerOffset) &= ~(uint32)(0x3F);
        /* Enable broadcast channel's software trigger. */
        HWREG(Sent_Hw_Sentance->CddSentBaseAddress + triggerOffset) |= (uint32)Trigger_Source;
    }
    else if (2U == *PduInfoPtr->SduDataPtr)
    {
        Cdd_Sent_enableMTPSoftwareTrigger(Sent_Hw_Sentance->CddSentBaseAddress, Channel_Id);
    }
    else
    {
        /*Do nothing*/
    }
}

/*
 *Design: MCAL-28676
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_GetChIdxPriv(const Cdd_Sent_DriverObjType *CddSentDrvObj, Cdd_SentInstance SentInstance, uint32 *InstanceIndex)
{
    if ((uint32)SentInstance < SENT_MAX_HW_UNITS)
    {
        *InstanceIndex = CddSentDrvObj->CddSent_Lut_Channel_Index[SentInstance];
    }

    return;
}

/*
 *Design: MCAL-28673
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_HwDenitPrv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr)
{
    VAR(uint32, AUTOMATIC) Base_Address = ConfigPtr->CddSentBaseAddress;
    /* Reset Sent Registers */
    McalLib_RegBitSet32((Base_Address + SENT_O_CSENT_SWR), SENT_CSENT_SWR_SWR);
    /* Reset Sent  Mtp Registers */
    McalLib_RegBitSet32((Base_Address + SENT_O_MTP_SWR), SENT_MTP_SWR_SWR);
}

/*
 *Design: MCAL-28677, MCAL-28622, MCAL-28624, MCAL-28682, MCAL-29152
 */
void Cdd_Sent_ProcessISR(Cdd_SentInstance SentInstance)
{
    VAR(CddSent_ValueType, AUTOMATIC) instance_index = CDD_SENT_MAX_32BIT_VAL;

    (void)Cdd_Sent_GetChIdxPriv(Cdd_Sent_DrvObjPtr, SentInstance, &instance_index);

    if (SENT_MAX_HW_UNITS > instance_index)
    {
        Cdd_Sent_HWUnitType *Sent_Instance_Object = Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[instance_index];
        uint32               Interrupt_Status_Register = HWREG(Sent_Instance_Object->CddSentBaseAddress + 0x40U);
        uint32               Interrupt_Enable_Register = HWREG(Sent_Instance_Object->CddSentBaseAddress + 0x44U);
        uint32               Enable_Fast_Interrupts    = (SENT_REINT_RFIFO_TRIGGER_E | SENT_REINT_RFAST_S1DV_E |
                                         SENT_REINT_RFAST_S2DV_E | SENT_REINT_RFAST_S3DV_E | SENT_REINT_RFAST_S4DV_E) &
                                        Interrupt_Enable_Register;
        uint32 Enable_Slow_Interrupts = SENT_REINT_RSLOW_DV_E & Interrupt_Enable_Register;

        if ((Enable_Fast_Interrupts & Interrupt_Status_Register) != 0x0U)
        {
            Cdd_Sent_ProcessIsrFastInterrupts(Sent_Instance_Object, instance_index, Interrupt_Status_Register);
#ifdef CDD_SENT_E_HARDWARE_ERROR
            (void)Dem_SetEventStatus(CDD_SENT_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
#endif
        }

        else if ((Enable_Slow_Interrupts & Interrupt_Status_Register) != 0x0U)
        {
            Cdd_Sent_ProcessIsrSlowInterrupts(Sent_Instance_Object);
        }
        else
        {
#ifdef CDD_SENT_E_HARDWARE_ERROR
            (void)Dem_SetEventStatus(CDD_SENT_E_HARDWARE_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
            Cdd_Sent_ProcessIsrCallCddSentUserErrorCallbackFunction(Sent_Instance_Object);
        }
        Cdd_Sent_clearInterruptFlag(Sent_Instance_Object->CddSentBaseAddress, (0xFFFFFFFFU));
    }
}

/*
 *Design: MCAL-28752
 */
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE)
    Cdd_Sent_getMessageID(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Instance_Object)
{
    VAR(uint32, AUTOMATIC) Sent_Base      = Sent_Instance_Object->CddSentBaseAddress;
    VAR(uint32, AUTOMATIC) Slow_Data_Base = HWREG(Sent_Base + SENT_O_RSDATA);
    VAR(uint32, AUTOMATIC) MessageID      = (Slow_Data_Base & SENT_RSDATA_MESSAGEID_M) >> SENT_RSDATA_MESSAGEID_S;
    return MessageID;
}

/*
 *Design: MCAL-28753
 */
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE)
    Cdd_Sent_getSlowData(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Instance_Object)
{
    VAR(uint32, AUTOMATIC) Sent_Base      = Sent_Instance_Object->CddSentBaseAddress;
    VAR(uint32, AUTOMATIC) Slow_Data_Base = HWREG(Sent_Base + SENT_O_RSDATA);
    VAR(uint32, AUTOMATIC) Slow_Data      = (Slow_Data_Base & SENT_RSDATA_DATA_M) >> SENT_RSDATA_DATA_S;
    return Slow_Data;
}

/*
 *Design: MCAL-28754
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_enableMTPChannel(uint32 mtpBase, Cdd_SentSensorType channel)
{
    VAR(uint32, AUTOMATIC) channelOffset;
    VAR(uint32, AUTOMATIC) SENT_MTP_CHANNEL_STEP = 0x100U;

    channelOffset = (((uint32)SENT_MTP_CHANNEL_STEP * (uint32)channel) + SENT_O_BC_MTP_EN);

    /* Enable the channel to generate trigger pulses. */

    HWREG(mtpBase + channelOffset) |= SENT_BC_MTP_EN_MTP_EN;
}

/*
 *Design: MCAL-28755
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_configureMTPTimeout(uint32 mtpBase, Cdd_SentSensorType sensorNum, uint32 sensorTimeout)
{
    VAR(uint32, AUTOMATIC) sensorOffset;

    sensorOffset = (SENT_MTP_TIMEOUT_STEP * (uint32)sensorNum) + SENT_O_S1_MTP_TO;

    HWREG(mtpBase + sensorOffset) = sensorTimeout;
}

/*
 *Design: MCAL-28756
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setMTPWaitTime(uint32 mtpBase, uint32 waitTime)
{
    HWREG(mtpBase + SENT_O_WAITTIME) = (HWREG(mtpBase + SENT_O_WAITTIME) & ~SENT_WAITTIME_WAITTIME_M) | waitTime;
}

/*
 *Design: MCAL-28757
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setMTPPeriod(uint32 mtpBase, Cdd_SentSensorType channel, uint32 period)
{
    VAR(uint32, AUTOMATIC) periodOffset;
    VAR(uint32, AUTOMATIC) SENT_MTP_PERIOD_STEP = 0x100U;

    periodOffset = (SENT_MTP_PERIOD_STEP * (uint32)channel) + SENT_O_BC_MTP_PERIOD;

    /* Set the period that the master trigger pulse output waveform is active. */

    HWREG(mtpBase + periodOffset) = (HWREG(mtpBase + periodOffset) & ~SENT_BC_MTP_PERIOD_PERIOD_M) | period;
}

/*
 *Design: MCAL-28758
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_clearInterruptFlag(uint32 base, uint32 intFlags)
{
    /* Clear the specified interrupt. */

    HWREG(base + SENT_O_RCLRINT) |= intFlags;
}

/*
 *Design: MCAL-28759
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setBroadcastChMTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
    VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) + SENT_O_BC_MTP_CMP1;

    /* Set the toggle time for MTPG output of broadcast channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) & ~SENT_BC_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

/*
 *Design: MCAL-28760
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setSensor1MTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
    VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) + SENT_O_S1_MTP_CMP1;

    /* Set the toggle time for MTPG output of broadcast channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) & ~SENT_S1_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

/*
 *Design: MCAL-28761
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setSensor2MTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
    VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) + SENT_O_S2_MTP_CMP1;

    /* Set the toggle time for MTPG output of broadcast channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) & ~SENT_S2_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

/*
 *Design: MCAL-28762
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setSensor3MTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
    VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) + SENT_O_S3_MTP_CMP1;

    /* Set the toggle time for MTPG output of Sensor 3 channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) & ~SENT_S3_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

/*
 *Design: MCAL-28763
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setSensor4MTPToggleTime(uint32 mtpBase, uint32 compareNum, uint32 toggleTime)
{
    VAR(uint32, AUTOMATIC) toggleOffset;
    VAR(uint32, AUTOMATIC) SENT_MTP_TOGGLETIME_STEP = 0x4U;

    toggleOffset = (SENT_MTP_TOGGLETIME_STEP * ((uint32)compareNum - 1U)) + SENT_O_S4_MTP_CMP1;

    /*  Set the toggle time for MTPG output of Sensor 4 channel. */

    HWREG(mtpBase + toggleOffset) = (HWREG(mtpBase + toggleOffset) & ~SENT_S4_MTP_CMP1_TOGGLETIME_M) | toggleTime;
}

/*
 *Design: MCAL-28764
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_disableMTPChannel(uint32 mtpBase, Cdd_SentSensorType channel)
{
    VAR(uint32, AUTOMATIC) channelOffset;
    VAR(uint32, AUTOMATIC) SENT_MTP_CHANNEL_STEP = 0x100U;

    channelOffset = (SENT_MTP_CHANNEL_STEP * (uint32)channel) + SENT_O_BC_MTP_EN;

    /* Disable the channel to generate trigger pulses. */

    HWREG(mtpBase + channelOffset) &= ~SENT_BC_MTP_EN_MTP_EN;
}

/*
 *Design: MCAL-28765
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_disableSentReceiver(uint32 base)
{
    /* Disable SENT receiver. */

    HWREG(base + SENT_O_RCFG) &= ~SENT_RCFG_RX_ENB;
}

/*
 *Design: MCAL-28766
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_EnableSentReceiver(uint32 base)
{
    /* Enable SENT reveiver to monitor the SENT bus. */
    HWREG(base + SENT_O_RCFG) |= SENT_RCFG_RX_ENB;
}

/*
 *Design: MCAL-28767
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setGFILTClockCycle(uint32 base, uint32 gFiltClock)
{
    /* Set the number of clock cycle to be filtered out. */

    HWREG(base + SENT_O_RCFG2) =
        (HWREG(base + SENT_O_RCFG2) & ~SENT_RCFG2_GFILT_M) | ((uint32)gFiltClock << SENT_RCFG2_GFILT_S);
}

/*
 *Design: MCAL-28768
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Sent_ConfigureFifoMode(uint32 base, Cdd_SentFIFOMode fifoMode)
{
    /* Configure FIFO Mode. */

    HWREG(base + SENT_O_RCFG2) = (HWREG(base + SENT_O_RCFG2) & ~SENT_RCFG2_FIFO_MODE) | (uint32)fifoMode;
}

/*
 *Design: MCAL-28769
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_configureTimeout(uint32 base, uint32 timeOut)
{
    /* Configure the timeout for SENT module. */

    HWREG(base + SENT_O_CSENT_TO) = timeOut;
}

/*
 *Design: MCAL-28770
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_enableInterrupt(uint32 base, uint32 intFlags)
{
    /* Enable the specified interrupt. */

    HWREG(base + SENT_O_REINT) |= intFlags;
}

/*
 *Design: MCAL-28771
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setDataNibble(uint32 base, Cdd_SentDataNibblesCount dataNibble)
{
    /* Set the number of data nibbles for standard SENT. */
    HWREG(base + SENT_O_RCFG) =
        (HWREG(base + SENT_O_RCFG) & ~SENT_RCFG_RX_DNIB_M) | (((uint32)dataNibble) << SENT_RCFG_RX_DNIB_S);
}

/*
 *Design: MCAL-28772
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_setRFIFOTriggerLevel(uint32 base, Cdd_SentTriggerLevel triggerLevel)
{
    /* Configure the trigger level for the receiver FIFO trigger interrupt and */
    /* DMA trigger. */

    HWREG(base + SENT_O_RCFG2) = (HWREG(base + SENT_O_RCFG2) & ~SENT_RCFG2_RFIFO_TRIGLEV_M) |
                                 ((uint32)triggerLevel << SENT_RCFG2_RFIFO_TRIGLEV_S);
}

/*
 *Design: MCAL-28773
 */
LOCAL_INLINE FUNC(uint32, CDD_SENT_CODE) Cdd_Sent_getFIFO(uint32 base)
{
    /* Return the received SENT fast channel data located at the */
    /* top of the receive FIFO. */

    return (HWREG(base + SENT_O_RFDATA));
}

/*
 *Design: MCAL-28774
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_disableInterrupt(uint32 base, uint32 intFlags)
{
    /* Disable the specified interrupt. */

    HWREG(base + SENT_O_REINT) &= ~intFlags;
}

/*
 *Design: MCAL-28775
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_setDataSortingFormat(uint32 base, Cdd_Sent_DataNumber dataNumber, Cdd_SentNibbleNumber nibbleNum,
                                  Cdd_SentNibble nibble)
{
    VAR(uint32, AUTOMATIC) dataOffset;
    VAR(uint32, AUTOMATIC) shiftVal;

    dataOffset = ((uint32)SENT_DATAXMAP_STEP * (uint32)dataNumber) + (uint32)SENT_O_DATA0_MAP;
    shiftVal   = (uint32)nibbleNum * (uint32)4;

    HWREG(base + dataOffset) =
        (HWREG(base + dataOffset) & ~((uint32)SENT_DATA0_MAP_D0_NIB0_M << shiftVal)) | ((uint32)nibble << shiftVal);
}

/*
 *Design: MCAL-28776
 */
LOCAL_INLINE FUNC(void, CDD_SENT_CODE) Cdd_Sent_enableMTPSoftwareTrigger(uint32 SentBase, Cdd_SentSensorType channel)
{
    VAR(uint32, AUTOMATIC) triggerOffset;

    triggerOffset = (SENT_MTP_SWTR_STEP * (uint32)channel) + SENT_O_BC_MTP_SWTR;

    /* Enable broadcast channel's software trigger. */

    HWREG(SentBase + triggerOffset) |= SENT_BC_MTP_SWTR_SWTR;
}

/*
 *Design: MCAL-28836
 */
FUNC(void, CDD_SENT_CODE)
Cdd_Sent_InitPriv(P2VAR(Cdd_Sent_DriverObjType, AUTOMATIC, CDD_SENT_APPL_DATA) Cdd_Sent_DriverObj,
                  P2VAR(boolean, AUTOMATIC, CDD_SENT_APPL_DATA) Cdd_Sent_DrvInitialized)
{
    for (uint32 loop_count = ((uint32)0U); loop_count < ((uint32)SENT_CFG_NO_OF_HW_UNITS); loop_count++)
    {
        /* Initialize the CDD_SENT channel. */
        Cdd_Sent_HWUnitType *Sent_Hw_Unit = Cdd_Sent_DriverObj->CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count];
        (void)Cdd_Sent_HwInitPrv(Sent_Hw_Unit);
        Cdd_Sent_DriverObj->CddSent_Lut_Channel_Index[Sent_Hw_Unit->CddSentInstance] = loop_count;
        Cdd_Sent_SetHandleIdPriv(Cdd_Sent_DriverObj, Sent_Hw_Unit, loop_count);
    }

    /* Save the Cdd_Sent_DrvObj address into a pointer in Cdd_Sent_Priv.c */
    Cdd_Sent_SetDriverObjPtr(Cdd_Sent_DriverObj);
    *Cdd_Sent_DrvInitialized = TRUE;
    /* Enable Sent Receiver*/
    Cdd_Sent_EnableSentReceiverPriv();
}

/*
 *Design: MCAL-28837
 */
FUNC(Std_ReturnType, CDD_SENT_CODE)
Cdd_Sent_TransmitPriv(P2CONST(PduInfoType, AUTOMATIC, CDD_SENT_CONST) PduInfoPtr, PduIdType TxPduId)
{
    VAR(Std_ReturnType, AUTOMATIC) Status = E_NOT_OK;
    VAR(uint8, AUTOMATIC) Instance_Id;
    VAR(uint8, AUTOMATIC) Channel_Id;
    VAR(uint8, AUTOMATIC) loop_count;
    VAR(uint8, AUTOMATIC) Sensor_Count = (uint8)0U;
    VAR(Cdd_SentTriggerSource, AUTOMATIC) Trigger_Source;

    for (loop_count = ((uint8)0U); loop_count < ((uint8)SENT_CFG_NO_OF_HW_UNITS); loop_count++)
    {
        for (Sensor_Count = (uint8)0U;
             Sensor_Count < Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]->CddSentMTPChannelCount;
             Sensor_Count++)
        {
            if (Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]
                    ->CddSentMTPConfigList[Sensor_Count]
                    ->CddSentMTPSensorPduID == TxPduId)
            {
                Instance_Id = Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]->CddSentInstance;
                Channel_Id  = Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]
                                 ->CddSentMTPConfigList[Sensor_Count]
                                 ->CddSentMTPSensorType;
                Trigger_Source = Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]
                                     ->CddSentMTPConfigList[Sensor_Count]
                                     ->CddSentTriggerSource;
                Cdd_Sent_TriggerPrv(Instance_Id, Trigger_Source, Channel_Id, PduInfoPtr);
                Status = E_OK;
            }
        }
    }

    return Status;
}
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
/*
 *Design: MCAL-28830
 */
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_SetCRCConfigPriv(P2CONST(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_CONST) ConfigPtr)
{
    VAR(uint32, AUTOMATIC) BaseAddress = ConfigPtr->CddSentBaseAddress;
    /* CRC setting As per the configuration */
    if (CDD_SENT_CRC_NONE == ConfigPtr->CddSentCRCType)
    {
        /* Disable CRC */
        HWREG(BaseAddress + SENT_O_RCFG) &= ~SENT_RCFG_RX_CRCENB;
    }
    else
    {
        /* Enable CRC */
        McalLib_RegBitSet32(BaseAddress + SENT_O_RCFG, SENT_RCFG_RX_CRCENB);

        /* Configuring CRC Type */
        McalLib_RegMFWriteRaw32((BaseAddress + SENT_O_RCFG), SENT_RCFG_RX_CRCTYPE, 0, ConfigPtr->CddSentCRCType);

        /* Configuring CRC width */
        McalLib_RegMFWriteRaw32((BaseAddress + SENT_O_RCFG), SENT_RCFG_CRC_WIDTH_M, SENT_RCFG_CRC_WIDTH_S,
                                ConfigPtr->CddSentCRCWidth);
        /* Configuring CRC status*/
        McalLib_RegMFWriteRaw32((BaseAddress + SENT_O_RCFG), SENT_RCFG_RX_CRC_WITH_STATUS, 0,
                                ConfigPtr->CddSentCRCWithStatus);
    }
    /* Configuring the Pause pulse based on the configuration. */
    if (CDD_SENT_CRC_NONE == ConfigPtr->CddSentCRCType)
    {
        /* Disable Pause Pulse */
        McalLib_RegBitClear32((BaseAddress + SENT_O_RCFG), SENT_RCFG_RX_PPENB);
    }
    else
    {
        /* Enable Pause Pulse */
        McalLib_RegBitSet32((BaseAddress + SENT_O_RCFG), SENT_RCFG_RX_PPENB);
    }
}

/*
 *Design: MCAL-28831
 */
static FUNC(void, CDD_SENT_CODE) Cdd_Sent_EnableSentReceiverPriv(void)
{
    for (uint32 loop_count = ((uint32)0U); loop_count < ((uint32)SENT_CFG_NO_OF_HW_UNITS); loop_count++)
    {
        if (Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]->CddSentMTP == FALSE)
        {
            /* Initialize the CDD_SENT channel. */
            Cdd_Sent_EnableSentReceiver(
                Cdd_Sent_DrvObjPtr->CddSent_CfgPtr->Cdd_Sent_HWUnit[loop_count]->CddSentBaseAddress);
        }
        else
        {
            /* Do Nothing */
        }
    }
}

/*
 *Design: MCAL-28832
 */
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_ProcessIsrFastInterrupts(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Instance_Object,
                                      const CddSent_ValueType instance_index, uint32 Interrupt_Status_Register)
{
    VAR(PduInfoType, AUTOMATIC) Info;
    VAR(PduIdType, AUTOMATIC) id = 0;
    VAR(uint32, AUTOMATIC) Offset_MTP;
    VAR(uint32, AUTOMATIC) Channel_id = 0U;
    VAR(uint32, AUTOMATIC)
    FIFOTriggerLevel = HWREG(Sent_Instance_Object->CddSentBaseAddress + 0x34U) >> SENT_RCFG2_RFIFO_TRIGLEV_S;
    VAR(Cdd_Sent_Data_Buffer, AUTOMATIC)
    Fast_Buffer_Object = Sent_Instance_Object->CddSent_Buffer_Data;
    if (Sent_Instance_Object->CddSentMTP == TRUE)
    {
        if ((Interrupt_Status_Register & SENT_RINTFLAG_RFAST_S1DV) != 0U)
        {
            Channel_id = 0U;
        }
        else if ((Interrupt_Status_Register & SENT_RINTFLAG_RFAST_S2DV) != 0U)
        {
            Channel_id = 1U;
        }
        else if ((Interrupt_Status_Register & SENT_RINTFLAG_RFAST_S3DV) != 0U)
        {
            Channel_id = 2U;
        }
        else if ((Interrupt_Status_Register & SENT_RINTFLAG_RFAST_S4DV) != 0U)
        {
            Channel_id = 3U;
        }
        else
        {
            /* Do Nothing*/
        }
        Offset_MTP     = SENT_O_MDATA(0U);
        Info.SduLength = 8U;
        if (Sent_Instance_Object->CddSentEnableTimeStamp == TRUE)
        {
            Fast_Buffer_Object.Timestamp[0]  = HWREG(Sent_Instance_Object->CddSentBaseAddress + Offset_MTP);
            Info.SduLength                  += 4U;
            Info.SduDataPtr                  = (uint8 *)&Fast_Buffer_Object.Timestamp[0];
        }
        else
        {
            Info.SduDataPtr = (uint8 *)&Fast_Buffer_Object.Data_Buffer[0];
        }
        Fast_Buffer_Object.Data_Buffer[0] = HWREG(Sent_Instance_Object->CddSentBaseAddress + Offset_MTP + 4U);
        Fast_Buffer_Object.Data_Buffer[1] = HWREG(Sent_Instance_Object->CddSentBaseAddress + Offset_MTP + 8U);

        Info.MetaDataPtr = NULL_PTR;
#if (STD_ON == CDD_SENT_INTEGRATION_WITH_ASR_COMSTACK_ENABLE)
        id = Cdd_Sent_DrvObjPtr->CddSent_Fast_Channel_PduID[instance_index][Channel_id];

        /* This parameter is a Pdu identifier used by PduR */

        PduR_Cdd_Sent_RxIndication(id, &Info);
#endif

        if (Sent_Instance_Object->CddSentUserCallbackFunction != NULL_PTR)
        {
            id = Cdd_Sent_DrvObjPtr->CddSent_Fast_Channel_PduID[instance_index][Channel_id];

            /* When Cdd Sent is integrated with Autosar Com stack, this parameter is a Pdu
            identifier When Cdd Sent is not integrated with Autosar Com stack, this parameter is a
            channel object identifier */

            Sent_Instance_Object->CddSentUserCallbackFunction(id, &Info);
        }
    }
    else
    {
        for (uint32 loop_count = 0; loop_count < (FIFOTriggerLevel / 3U); loop_count++)
        {
            Info.SduLength = 8U;
            if (Sent_Instance_Object->CddSentEnableTimeStamp == TRUE)
            {
                Fast_Buffer_Object.Timestamp[0]  = Cdd_Sent_getFIFO(Sent_Instance_Object->CddSentBaseAddress);
                Info.SduLength                  += 4U;
                Info.SduDataPtr                  = (uint8 *)&Fast_Buffer_Object.Timestamp[0];
            }
            else
            {
                Info.SduDataPtr = (uint8 *)&Fast_Buffer_Object.Data_Buffer[0];
            }
            Fast_Buffer_Object.Data_Buffer[0] = Cdd_Sent_getFIFO(Sent_Instance_Object->CddSentBaseAddress);
            Fast_Buffer_Object.Data_Buffer[1] = Cdd_Sent_getFIFO(Sent_Instance_Object->CddSentBaseAddress);
            Info.MetaDataPtr                  = NULL_PTR;
#if (STD_ON == CDD_SENT_INTEGRATION_WITH_ASR_COMSTACK_ENABLE)
            id = Cdd_Sent_DrvObjPtr->CddSent_Fast_Channel_PduID[instance_index][Channel_id];

            /* This parameter is a Pdu identifier used by PduR */

            PduR_Cdd_Sent_RxIndication(id, &Info);
#endif

            if (Sent_Instance_Object->CddSentUserCallbackFunction != NULL_PTR)
            {
                id = Cdd_Sent_DrvObjPtr->CddSent_Fast_Channel_PduID[instance_index][Channel_id];

                /* When Cdd Sent is integrated with Autosar Com stack, this parameter is a Pdu
                identifier When Cdd Sent is not integrated with Autosar Com stack, this parameter is
                a channel object identifier */

                Sent_Instance_Object->CddSentUserCallbackFunction(id, &Info);
            }
        }
    }
}

/*
 *Design: MCAL-28833
 */
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_ProcessIsrSlowInterrupts(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Instance_Object)
{
    VAR(PduInfoType, AUTOMATIC) Info;
    VAR(PduIdType, AUTOMATIC) id = 0;

    for (uint32 Channel_count = 0U; Channel_count < Sent_Instance_Object->CddSentChannelCount; Channel_count++)
    {
        Cdd_Sent_Data_Buffer Slow_Buffer_Object = Sent_Instance_Object->CddSent_Buffer_Data;

        if (((uint32)Sent_Instance_Object->CddSentChannelConfigList[Channel_count]->CddSentMessageID) ==
            ((uint32)Cdd_Sent_getMessageID(Sent_Instance_Object)))
        {
            Slow_Buffer_Object.Data_Buffer[0] = Cdd_Sent_getSlowData(Sent_Instance_Object);
            Info.SduDataPtr                   = (uint8 *)&Slow_Buffer_Object.Data_Buffer;
            Info.MetaDataPtr                  = NULL_PTR;
            Info.SduLength                    = 2;

#if (STD_ON == CDD_SENT_INTEGRATION_WITH_ASR_COMSTACK_ENABLE)
            id = Sent_Instance_Object->CddSentChannelConfigList[Channel_count]->CddSentPduID;

            /* This parameter is a Pdu identifier used by PduR */

            PduR_Cdd_Sent_RxIndication(id, &Info);
#endif

            if (Sent_Instance_Object->CddSentUserCallbackFunction != NULL_PTR)
            {
                id = Sent_Instance_Object->CddSentChannelConfigList[Channel_count]->CddSentPduID;

                /* When Cdd Sent is integrated with Autosar Com stack, this parameter is a Pdu
                identifier When Cdd Sent is not integrated with Autosar Com stack, this parameter is
                a channel object identifier */

                Sent_Instance_Object->CddSentUserCallbackFunction(id, &Info);
            }

#ifdef CDD_SENT_E_HARDWARE_ERROR
            (void)Dem_SetEventStatus(CDD_SENT_E_HARDWARE_ERROR, DEM_EVENT_STATUS_PASSED);
#endif

            break;
        }
        else
        {
            /* Do Nothing*/
        }
    }
}

/*
 *Design: MCAL-28834
 */
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_ProcessIsrCallCddSentUserErrorCallbackFunction(P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA)
                                                                Sent_Instance_Object)
{
    if (Sent_Instance_Object->CddSentUserErrorCallbackFunction != NULL_PTR)
    {
        Sent_Instance_Object->CddSentUserErrorCallbackFunction();
    }
}

/*
 *Design: MCAL-28835
 */
static FUNC(void, CDD_SENT_CODE)
    Cdd_Sent_SetHandleIdPriv(P2VAR(Cdd_Sent_DriverObjType, AUTOMATIC, CDD_SENT_APPL_DATA) Cdd_Sent_DriverObj,
                             P2VAR(Cdd_Sent_HWUnitType, AUTOMATIC, CDD_SENT_APPL_DATA) Sent_Hw_Unit, uint32 loop_count)
{
    for (uint32 Channel_count = 0U; Channel_count < Sent_Hw_Unit->CddSentChannelCount; Channel_count++)
    {
        switch (Sent_Hw_Unit->CddSentChannelConfigList[Channel_count]->CddSentSensorType)
        {
            case CDD_SENT_CHANNEL_STANDARD_SENSOR:
                if (Sent_Hw_Unit->CddSentChannelConfigList[Channel_count]->CddSentChannelType ==
                    CDD_SENT_CHANNEL_STANDARD_SENSOR_FAST_CHANNEL)
                {
                    Cdd_Sent_DriverObj->CddSent_Fast_Channel_PduID[loop_count][0U] =
                        Sent_Hw_Unit->CddSentChannelConfigList[Channel_count]->CddSentPduID;
                }
                break;
            case CDD_SENT_CHANNEL_SENSOR_1:
                Cdd_Sent_DriverObj->CddSent_Fast_Channel_PduID[loop_count][0U] =
                    Sent_Hw_Unit->CddSentChannelConfigList[Channel_count]->CddSentPduID;
                break;
            case CDD_SENT_CHANNEL_SENSOR_2:
                Cdd_Sent_DriverObj->CddSent_Fast_Channel_PduID[loop_count][1U] =
                    Sent_Hw_Unit->CddSentChannelConfigList[Channel_count]->CddSentPduID;
                break;
            case CDD_SENT_CHANNEL_SENSOR_3:
                Cdd_Sent_DriverObj->CddSent_Fast_Channel_PduID[loop_count][2U] =
                    Sent_Hw_Unit->CddSentChannelConfigList[Channel_count]->CddSentPduID;
                break;
            case CDD_SENT_CHANNEL_SENSOR_4:
                Cdd_Sent_DriverObj->CddSent_Fast_Channel_PduID[loop_count][3U] =
                    Sent_Hw_Unit->CddSentChannelConfigList[Channel_count]->CddSentPduID;
                break;
            default:
                break;
        }
    }
}
#define CDD_SENT_STOP_SEC_CODE
#include "Cdd_Sent_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Priv.c
 *********************************************************************************************************************/
