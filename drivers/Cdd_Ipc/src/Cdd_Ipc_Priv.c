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
 *  File:       Cdd_Ipc_Priv.c
 *  Generator:  None
 *
 *  Description: This file contains private function definitions that are defined in Cdd_Ipc_Priv.h
 *file.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Ipc.h"
#include "Cdd_Ipc_Priv.h"
#include "Mcal_Lib.h"
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

#define CDD_IPC_START_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"
/* Cdd_Ipc configuration pointer to access driver configuration. */
P2CONST(Cdd_Ipc_ConfigType, AUTOMATIC, CDD_IPC_CONST) Cdd_Ipc_ConfigPtr = NULL_PTR;
#define CDD_IPC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
/* Design: MCAL-30592 */
/** \brief Sets a flag for a remote core
 * \param[in]  Instance is the instance in which the flag is being set
 * \param[in]  Flag is the flag bit being set
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_IPC_CODE) Cdd_Ipc_SetFlagLtoR(Cdd_Ipc_InstanceType Instance, uint32 Flag);

/* Design: MCAL-30593 */
/** \brief Local core acknowledges a flag set by the remote core
 * \param[in]  Instance is the instance in which the flag is achnowledged
 * \param[in]  Flag is the flag bit that is acknowledged
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, CDD_IPC_CODE) Cdd_Ipc_AckFlagRtoL(Cdd_Ipc_InstanceType Instance, uint32 Flag);

/* Design: MCAL-30594 */
/** \brief Wait for the remote core to send a flag
 * \param[in]  Instance is the instance in which the flag will be set
 * \param[in]  Flag is the flag bit that will be set
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_WaitForFlag(Cdd_Ipc_InstanceType Instance, uint32 Flag);

/* Design: MCAL-30595 */
/** \brief Wait for the IPC flag to be acknowledged
 * \param[in]  Instance is the instance in which the flag will be achnowledged
 * \param[in]  Flag is the flag bit that will be acknowledged
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_WaitForAck(Cdd_Ipc_InstanceType Instance, uint32 Flag);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

LOCAL_INLINE FUNC(void, CDD_IPC_CODE) Cdd_Ipc_SetFlagLtoR(Cdd_Ipc_InstanceType Instance, uint32 Flag)
{
    HWREG(CDD_IPC_REG_SET(Instance)) = Flag;
}

LOCAL_INLINE FUNC(void, CDD_IPC_CODE) Cdd_Ipc_AckFlagRtoL(Cdd_Ipc_InstanceType Instance, uint32 Flag)
{
    HWREG(CDD_IPC_REG_ACK(Instance)) = Flag;
}

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_SetCfgObj(P2CONST(Cdd_Ipc_ConfigType, AUTOMATIC, CDD_IPC_CONST) ConfigPtr)
{
    Cdd_Ipc_ConfigPtr = ConfigPtr;
}

/*
 *Design: MCAL-
 */
FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_Sync_Process(VAR(Cdd_Ipc_CoreType, AUTOMATIC) RemoteCore)
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_NOT_OK;

    Cdd_Ipc_SetFlagLtoR(Cdd_Ipc_Sync_Instances[Cdd_Ipc_ConfigPtr->Cdd_Ipc_LocalCore][RemoteCore], CDD_IPC_FLAG2);
    ret_val =
        Cdd_Ipc_WaitForFlag(Cdd_Ipc_Sync_Instances[Cdd_Ipc_ConfigPtr->Cdd_Ipc_LocalCore][RemoteCore], CDD_IPC_FLAG2);
    if (E_OK == ret_val)
    {
        Cdd_Ipc_AckFlagRtoL(Cdd_Ipc_Sync_Instances[Cdd_Ipc_ConfigPtr->Cdd_Ipc_LocalCore][RemoteCore], CDD_IPC_FLAG2);
        ret_val =
            Cdd_Ipc_WaitForAck(Cdd_Ipc_Sync_Instances[Cdd_Ipc_ConfigPtr->Cdd_Ipc_LocalCore][RemoteCore], CDD_IPC_FLAG2);
    }

    return ret_val;
}

FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_Transmit_Priv(VAR(PduIdType, AUTOMATIC) ChannelId,
                      P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) return_val = E_NOT_OK;
    VAR(uint8, AUTOMATIC) instance_index      = (uint8)0U;
    VAR(uint8, AUTOMATIC) channel_index       = (uint8)0U;

    if (E_OK == Cdd_Ipc_GetTxIdxPriv(ChannelId, &instance_index, &channel_index))
    {
        if (HWREG(CDD_IPC_REG_FLG(Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[instance_index].Cdd_Ipc_TxInstance)) ==
            0U)
        {
            Cdd_Ipc_WriteChannelPriv(instance_index, channel_index, PduInfoPtr);
            return_val = E_OK;
        }
    }

    return (return_val);
}

/*
 * Design: MCAL-
 */
FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_RxIndication(VAR(uint8, AUTOMATIC) Instance_Index, VAR(uint8, AUTOMATIC) Channel_Index,
                     P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr)
{
    if (Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index]
            .Cdd_Ipc_RxChannelConfig[Channel_Index]
            .Cdd_Ipc_UserCallbackFunction != NULL_PTR)
    {
        Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index]
            .Cdd_Ipc_RxChannelConfig[Channel_Index]
            .Cdd_Ipc_UserCallbackFunction(PduInfoPtr);
    }
#if (STD_ON == CDD_IPC_INTEGRATION_WITH_ASR_COM_STACK_ENABLE)
    PduR_Cdd_Ipc_RxIndication(Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index]
                                  .Cdd_Ipc_RxChannelConfig[Channel_Index]
                                  .Cdd_Ipc_PduID,
                              PduInfoPtr);
#endif
}

FUNC(boolean, CDD_IPC_CODE)
Cdd_Ipc_GetChannelPollingStatus(VAR(uint8, AUTOMATIC) Instance_Index, uint8* ChannelIndex)
{
    VAR(boolean, AUTOMATIC) return_val = FALSE;
    VAR(uint8, AUTOMATIC) channel      = 0U;
    VAR(uint32, AUTOMATIC)
    status = HWREG(CDD_IPC_REG_STS(Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index].Cdd_Ipc_RxInstance));
    VAR(uint8, AUTOMATIC) channel_index = 0U;

    if (((status & CDD_IPC_FLAG1) == CDD_IPC_FLAG1) && (((status & (CDD_IPC_FLAG2 | CDD_IPC_FLAG0)) == 0U)))
    {
        channel = (status >> CDD_IPC_CHANNELINDEX) & BIT_MASK_EIGHT;

        for (channel_index = 0U;
             channel_index < Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index].Cdd_Ipc_RxChannelCount;
             channel_index++)
        {
            if (channel == Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index]
                               .Cdd_Ipc_RxChannelConfig[channel_index]
                               .Cdd_Ipc_ChannelID)
            {
                *ChannelIndex = channel_index;
                return_val    = TRUE;
                break;
            }
        }
        if (FALSE == return_val)
        {
            Cdd_Ipc_Acknowledge(Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index].Cdd_Ipc_RxInstance);
        }
    }

    return (return_val);
}

FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_WriteChannelPriv(VAR(uint8, AUTOMATIC) Instance_Index, VAR(uint8, AUTOMATIC) Channel_Index,
                         P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr)
{
    VAR(uint32, AUTOMATIC) flags        = (uint32)0U;
    VAR(uint8, AUTOMATIC) byteCnt       = 0U;
    VAR(uint32, AUTOMATIC) commandValue = 0U;
    VAR(uint32, AUTOMATIC) addressValue = 0U;
    VAR(uint32, AUTOMATIC) dataValue    = 0U;

    // Calculate the values to be written to the registers
    for (byteCnt = 0U; (byteCnt < (uint8)PduInfoPtr->SduLength) && (byteCnt < CDD_IPC_MAX_SIZE); byteCnt++)
    {
        if (byteCnt < CDD_IPC_COMMBYTE)
        {
            // Calculate the command value
            commandValue |= (PduInfoPtr->SduDataPtr[byteCnt] << (8U * (byteCnt % CDD_IPC_COMMANDSIZE)));
        }
        else if ((byteCnt >= CDD_IPC_COMMBYTE) && (byteCnt < CDD_IPC_ADDRBYTE))
        {
            // Calculate the address value
            addressValue |=
                (PduInfoPtr->SduDataPtr[byteCnt] << (8U * ((byteCnt - CDD_IPC_COMMBYTE) % CDD_IPC_COMMANDSIZE)));
        }
        else
        {
            // Calculate the data value
            dataValue |=
                (PduInfoPtr->SduDataPtr[byteCnt] << (8U * ((byteCnt - CDD_IPC_ADDRBYTE) % CDD_IPC_COMMANDSIZE)));
        }
    }

    HWREG(CDD_IPC_REG_SENDCOM(Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[Instance_Index].Cdd_Ipc_TxInstance)) =
        commandValue;
    HWREG(CDD_IPC_REG_SENDADDR(Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[Instance_Index].Cdd_Ipc_TxInstance)) =
        addressValue;
    HWREG(CDD_IPC_REG_SENDDATA(Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[Instance_Index].Cdd_Ipc_TxInstance)) =
        dataValue;

    // Flags to indicate the Tx processing type
    if (Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[Instance_Index]
            .Cdd_Ipc_TxChannelConfig[Channel_Index]
            .Cdd_Ipc_TxProcessing == CDD_IPC_INTERRUPT)
    {
        flags |= CDD_IPC_FLAG0;
    }
    else
    {
        flags |= CDD_IPC_FLAG1;
    }

    // Flags to indicate the Channel ID
    flags |= ((Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[Instance_Index]
                   .Cdd_Ipc_TxChannelConfig[Channel_Index]
                   .Cdd_Ipc_ChannelID)
              << CDD_IPC_CHANNELINDEX);

    // Flags to indicate the length
    flags |= ((uint32)(PduInfoPtr->SduLength) << CDD_IPC_LENGTHINDEX);

    HWREG(CDD_IPC_REG_SET(Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[Instance_Index].Cdd_Ipc_TxInstance)) = flags;
}

FUNC(void, CDD_IPC_CODE)
Cdd_Ipc_ReadChannelPriv(VAR(uint8, AUTOMATIC) Instance_Index,
                        P2CONST(PduInfoType, AUTOMATIC, CDD_IPC_APPL_CONST) PduInfoPtr)
{
    VAR(uint32, AUTOMATIC) flags        = 0U;
    VAR(uint8, AUTOMATIC) length        = 0U;
    VAR(uint8, AUTOMATIC) byteCnt       = 0U;
    VAR(uint32, AUTOMATIC) commandvalue = 0U;
    VAR(uint32, AUTOMATIC) addrvalue    = 0U;
    VAR(uint32, AUTOMATIC) datavalue    = 0U;

    flags  = HWREG(CDD_IPC_REG_STS(Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index].Cdd_Ipc_RxInstance));
    length = (flags >> CDD_IPC_LENGTHINDEX) & BIT_MASK_FOUR;
    ((PduInfoType*)PduInfoPtr)->SduLength = (length > CDD_IPC_MAX_SIZE) ? CDD_IPC_MAX_SIZE : length;

    commandvalue =
        HWREG(CDD_IPC_REG_RECVCOM(Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index].Cdd_Ipc_RxInstance));
    addrvalue =
        HWREG(CDD_IPC_REG_RECVADDR(Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index].Cdd_Ipc_RxInstance));
    datavalue =
        HWREG(CDD_IPC_REG_RECVDATA(Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[Instance_Index].Cdd_Ipc_RxInstance));

    for (byteCnt = 0U; (byteCnt < PduInfoPtr->SduLength); byteCnt++)
    {
        if (byteCnt < CDD_IPC_COMMBYTE)
        {
            PduInfoPtr->SduDataPtr[byteCnt] =
                (uint8)((commandvalue >> (8U * (byteCnt % CDD_IPC_COMMANDSIZE))) & BIT_MASK_EIGHT);
        }
        else if ((byteCnt >= CDD_IPC_COMMBYTE) && (byteCnt < CDD_IPC_ADDRBYTE))
        {
            PduInfoPtr->SduDataPtr[byteCnt] =
                (uint8)((addrvalue >> (8U * ((byteCnt - CDD_IPC_COMMBYTE) % CDD_IPC_COMMANDSIZE))) & BIT_MASK_EIGHT);
        }
        else
        {
            PduInfoPtr->SduDataPtr[byteCnt] =
                (uint8)((datavalue >> (8U * ((byteCnt - CDD_IPC_ADDRBYTE) % CDD_IPC_COMMANDSIZE))) & BIT_MASK_EIGHT);
        }
    }
}

FUNC(void, CDD_IPC_CODE) Cdd_Ipc_Acknowledge(Cdd_Ipc_InstanceType Instance)
{
    VAR(uint32, AUTOMATIC) status    = HWREG(CDD_IPC_REG_STS(Instance));
    HWREG(CDD_IPC_REG_ACK(Instance)) = status;
}

void Cdd_Ipc_ProcessIsr(Cdd_Ipc_InstanceType Instance)
{
    VAR(uint8, AUTOMATIC) channel_index  = (uint8)0U;
    VAR(uint8, AUTOMATIC) instance_index = (uint8)0U;
    VAR(boolean, AUTOMATIC) status       = E_NOT_OK;
    VAR(PduInfoType, AUTOMATIC) pduinfo;
    VAR(uint8, AUTOMATIC) databuffer[CDD_IPC_MAX_SIZE] = {0U};
    pduinfo.SduDataPtr                                 = databuffer;

    if ((HWREG(CDD_IPC_REG_STS(Instance)) & CDD_IPC_FLAG2) != CDD_IPC_FLAG2)
    {
        status = Cdd_Ipc_GetRxIdxPriv(Instance, &instance_index, &channel_index);

        if (E_OK == status)
        {
            Cdd_Ipc_ReadChannelPriv(instance_index, &pduinfo);
            Cdd_Ipc_Acknowledge(Instance);
            Cdd_Ipc_RxIndication(instance_index, channel_index, &pduinfo);
        }
    }
}

FUNC(boolean, CDD_IPC_CODE) Cdd_Ipc_IsChannelIdValid(VAR(PduIdType, AUTOMATIC) ChannelId)
{
    VAR(boolean, AUTOMATIC) return_value = FALSE;
    VAR(uint8, AUTOMATIC) instance_index = (uint8)0U;
    VAR(uint8, AUTOMATIC) channel_index  = (uint8)0U;

    if (E_OK == Cdd_Ipc_GetTxIdxPriv(ChannelId, &instance_index, &channel_index))
    {
        return_value = TRUE;
    }

    return return_value;
}

FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_GetRxIdxPriv(VAR(Cdd_Ipc_InstanceType, AUTOMATIC) Instance, uint8* InstanceIndex, uint8* ChannelIndex)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = E_NOT_OK;
    VAR(uint8, AUTOMATIC) instance_index        = 0U;

    for (instance_index = 0U; instance_index < CDD_IPC_RX_INSTANCE_COUNT; instance_index++)
    {
        if (Instance == Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[instance_index].Cdd_Ipc_RxInstance)
        {
            return_value = Cdd_Ipc_GetRxChIdx(Instance, instance_index, ChannelIndex);
            if (E_OK == return_value)
            {
                *InstanceIndex = instance_index;
                break;
            }
        }
    }
    if (E_NOT_OK == return_value)
    {
        Cdd_Ipc_Acknowledge(Instance);
    }

    return return_value;
}

FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_GetRxChIdx(VAR(Cdd_Ipc_InstanceType, AUTOMATIC) Instance, uint8 InstanceIndex, uint8* ChannelIndex)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = E_NOT_OK;
    VAR(uint8, AUTOMATIC) channel_index         = 0U;
    VAR(uint8, AUTOMATIC)
    channel = ((HWREG(CDD_IPC_REG_STS(Instance))) >> CDD_IPC_CHANNELINDEX) & BIT_MASK_EIGHT;

    if (Instance == Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[InstanceIndex].Cdd_Ipc_RxInstance)
    {
        for (channel_index = 0;
             channel_index < Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[InstanceIndex].Cdd_Ipc_RxChannelCount;
             channel_index++)
        {
            if (channel == Cdd_Ipc_ConfigPtr->Cdd_Ipc_RxInstanceConfig[InstanceIndex]
                               .Cdd_Ipc_RxChannelConfig[channel_index]
                               .Cdd_Ipc_ChannelID)
            {
                *ChannelIndex = channel_index;
                return_value  = E_OK;
                break;
            }
        }
    }

    return return_value;
}

FUNC(Std_ReturnType, CDD_IPC_CODE)
Cdd_Ipc_GetTxIdxPriv(VAR(PduIdType, AUTOMATIC) ChannelId, uint8* InstanceIndex, uint8* ChannelIndex)
{
    VAR(Std_ReturnType, AUTOMATIC) return_val = E_NOT_OK;
    VAR(uint8, AUTOMATIC) instance_index      = 0U;
    VAR(uint8, AUTOMATIC) channel_index       = 0U;

    for (instance_index = 0U; instance_index < CDD_IPC_TX_INSTANCE_COUNT; instance_index++)
    {
        for (channel_index = 0;
             channel_index < Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[instance_index].Cdd_Ipc_TxChannelCount;
             channel_index++)
        {
            if (ChannelId == Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[instance_index]
                                 .Cdd_Ipc_TxChannelConfig[channel_index]
                                 .Cdd_Ipc_HandleID)
            {
                *InstanceIndex = instance_index;
                *ChannelIndex  = channel_index;
                return_val     = E_OK;
                break;
            }
        }
        if (E_OK == return_val)
        {
            break;
        }
    }

    return return_val;
}

FUNC(boolean, CDD_IPC_CODE) Cdd_Ipc_InstanceStatus(VAR(PduIdType, AUTOMATIC) ChannelId)
{
    VAR(boolean, AUTOMATIC) return_value = FALSE;
    VAR(uint8, AUTOMATIC) instance_index = (uint8)0U;
    VAR(uint8, AUTOMATIC) channel_index  = (uint8)0U;

    if (E_OK == Cdd_Ipc_GetTxIdxPriv(ChannelId, &instance_index, &channel_index))
    {
        if (HWREG(CDD_IPC_REG_FLG(Cdd_Ipc_ConfigPtr->Cdd_Ipc_TxInstanceConfig[instance_index].Cdd_Ipc_TxInstance)) ==
            0U)
        {
            return_value = TRUE;
        }
    }

    return return_value;
}

FUNC(uint64, CDD_IPC_CODE) Cdd_Ipc_ReadCounter(void)
{
    // Get the Counter High and Low values. Read to the Counter low register
    // saves the value of Counter High register.
    uint32 ctrL = HWREG(IPCCOUNTER_BASE + IPC_O_COUNTERL);
    uint32 ctrH = HWREG(IPCCOUNTER_BASE + IPC_O_COUNTERH);

    // Return the 64-bit value of the counter
    return (((uint64)ctrH << 32U) | ((uint64)ctrL));
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_WaitForFlag(Cdd_Ipc_InstanceType Instance, uint32 Flag)
{
    VAR(uint64, AUTOMATIC) startCount         = (uint64)0U;
    VAR(uint64, AUTOMATIC) elapsedCount       = (uint64)0U;
    VAR(Std_ReturnType, AUTOMATIC) return_val = E_OK;

    (void)McalLib_GetCounterValue(&startCount);
    while ((HWREG(CDD_IPC_REG_STS(Instance)) & Flag) != Flag)
    {
        (void)McalLib_GetElapsedValue(&startCount, &elapsedCount);
        if (CDD_IPC_CFG_TIMEOUT_CLOCK_CYCLES <= elapsedCount)
        {
            return_val = E_NOT_OK;
            break;
        }
        else
        {
            /*  Do Nothing */
        }
    }

    return return_val;
}

static FUNC(Std_ReturnType, CDD_IPC_CODE) Cdd_Ipc_WaitForAck(Cdd_Ipc_InstanceType Instance, uint32 Flag)
{
    VAR(uint64, AUTOMATIC) startCount         = (uint64)0U;
    VAR(uint64, AUTOMATIC) elapsedCount       = (uint64)0U;
    VAR(Std_ReturnType, AUTOMATIC) return_val = E_OK;

    (void)McalLib_GetCounterValue(&startCount);

    while ((HWREG(CDD_IPC_REG_FLG(Instance)) & Flag) == Flag)
    {
        (void)McalLib_GetElapsedValue(&startCount, &elapsedCount);
        if (CDD_IPC_CFG_TIMEOUT_CLOCK_CYCLES <= elapsedCount)
        {
            return_val = E_NOT_OK;
            break;
        }
        else
        {
            /*  Do Nothing */
        }
    }

    return return_val;
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Ipc_Priv.c
 *********************************************************************************************************************/
