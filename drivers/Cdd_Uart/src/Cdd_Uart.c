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
 *  File:       Cdd_Uart
 *  Generator:  None
 *
 *  Description: This file contains CDD UART driver public API function definitions .
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Uart.h"
#include "Cdd_Uart_Priv.h"
#include "SchM_Cdd_Uart.h"
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((CDD_UART_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (CDD_UART_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (CDD_UART_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "AUTOSAR Version of CDD_UART is incorrect"
#endif

/* vendor specific version information check */

#if ((CDD_UART_SW_MAJOR_VERSION != (3U)) || (CDD_UART_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Uart.c and Cdd_Uart.h are not matching!"
#endif

#if ((CDD_UART_CFG_MAJOR_VERSION != (3U)) || (CDD_UART_CFG_MINOR_VERSION != (0U)))
#error "Version numbers of Cdd_Uart.c and Cdd_Uart_Cfg.h are not matching!"
#endif

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
#define CDD_UART_START_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Uart_MemMap.h"
/* UART driver init status */
VAR(boolean, CDD_UART_VAR_INIT) Cdd_Uart_IsInitialized = FALSE;
#define CDD_UART_STOP_SEC_VAR_INIT_BOOLEAN
#include "Cdd_Uart_MemMap.h"

#define CDD_UART_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Uart_MemMap.h"
/* UART driver object */
VAR(Cdd_Uart_ObjectType, CDD_UART_VAR_NO_INIT) Cdd_Uart_Obj[CDD_UART_MAX_NUM_HWUNIT];
#define CDD_UART_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Uart_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
/** \brief This function will do UART write.
 *
 * \param[in] UartHwUnitObj Pointer to UART HW unit object.
 * \param[in] SrcBufferPtr  Write buffer address.
 * \param[in] Count         Write count in no of bytes.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, CDD_UART_CODE)
    Cdd_Uart_PrivWrite(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj,
                       P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) SrcBufferPtr, uint32 Count);

/** \brief This function will do UART read.
 *
 * \param[in] UartHwUnitObj Pointer to UART HW unit object.
 * \param[in] DestBufferPtr Read buffer address.
 * \param[in] Count         Read count in no of bytes.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, CDD_UART_CODE)
    Cdd_Uart_PrivRead(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj,
                      P2VAR(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) DestBufferPtr, uint32 Count);

/** \brief This function will do UART poll read.
 *
 * \param[in] UartHwUnitObj Pointer to UART HW unit object.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
static FUNC(void, CDD_UART_CODE)
    Cdd_Uart_Poll_PrivRead(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CDD_UART_START_SEC_CODE
#include "Cdd_Uart_MemMap.h"

#if (STD_ON == CDD_UART_CFG_GET_VERSION_INFO_API)
FUNC(void, CDD_UART_CODE)
Cdd_Uart_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_UART_APPL_DATA) VersionInfoPtr)
{
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    /* If the output pointer (VersionInfoPtr) is NULL */
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_GET_VERSION_INFO,
                              CDD_UART_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         = (uint16)CDD_UART_VENDOR_ID;
        VersionInfoPtr->moduleID         = (uint16)CDD_UART_MODULE_ID;
        VersionInfoPtr->sw_major_version = (uint8)CDD_UART_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)CDD_UART_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)CDD_UART_SW_PATCH_VERSION;
    }
}
#endif

FUNC(void, CDD_UART_CODE)
Cdd_Uart_Init(P2CONST(Cdd_Uart_ConfigType, AUTOMATIC, CDD_UART_CONFIG_DATA) ConfigPtr)
{
    uint8                      hwUnitId      = 0U;
    const Cdd_Uart_ConfigType *UartConfigPtr = ConfigPtr;
    Cdd_Uart_ObjectType       *UartHwUnitObj = NULL_PTR;

#if (STD_ON == CDD_UART_CFG_PRE_COMPILE_VARIANT)
    if (NULL_PTR == ConfigPtr)
    {
        UartConfigPtr = &CDD_UART_INIT_CONFIG_PC;
    }
    else
    {
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_INIT, CDD_UART_E_PARAM_POINTER);
#endif
    }
#endif

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (NULL_PTR == UartConfigPtr)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_INIT, CDD_UART_E_PARAM_POINTER);
    }
    else
#endif
    {
        if (FALSE == Cdd_Uart_IsInitialized)
        {
            /* Set the UART obj ptr */
            Cdd_Uart_SetObj(&Cdd_Uart_Obj[0U]);

            for (hwUnitId = 0U; hwUnitId < CDD_UART_MAX_NUM_HWUNIT; hwUnitId++)
            {
                UartHwUnitObj = &Cdd_Uart_Obj[hwUnitId];

                /* Configuration data pointer */
                UartHwUnitObj->Cdd_Uart_HwUnitCfg = &UartConfigPtr->Cdd_Uart_HwUnitCfg[hwUnitId];

                /* Write transaction reset */
                Cdd_Uart_ConfigWriteTrans(&UartHwUnitObj->Cdd_Uart_WriteTransaction, NULL_PTR, 0U);

                /* Read transaction reset */
                Cdd_Uart_ConfigReadTrans(&UartHwUnitObj->Cdd_Uart_ReadTransaction, NULL_PTR, 0U);

                /* UART HW unit init */
                Cdd_Uart_HwUnitInit(UartHwUnitObj);
            }

            Cdd_Uart_IsInitialized = TRUE;
        }
        else
        {
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
            /* If the driver is already initialized */
            (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_INIT,
                                  CDD_UART_E_ALREADY_INITIALIZED);
#endif
        }
    }
}

FUNC(void, CDD_UART_CODE) Cdd_Uart_Deinit(void)
{
    uint8                hwUnitId      = 0U;
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;

    /* Check if the UART is already initialized */
    if (TRUE == Cdd_Uart_IsInitialized)
    {
        for (hwUnitId = 0U; hwUnitId < CDD_UART_MAX_NUM_HWUNIT; hwUnitId++)
        {
            UartHwUnitObj = &Cdd_Uart_Obj[hwUnitId];

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
            /* Checks if the UART is busy with any ongoing transactions or if the FIFOs are not
             * empty. */
            if ((E_NOT_OK == Cdd_Uart_IsWriteBusy(UartHwUnitObj)) || (E_NOT_OK == Cdd_Uart_IsReadBusy(UartHwUnitObj)))
            {
                (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_DEINIT, CDD_UART_E_BUSY);
            }
            else
#endif
            {
                /* Disable the UART interrupts to prevent any interrupts during deinitialization */
                Cdd_Uart_EnableWriteIntr(UartHwUnitObj, FALSE);
                Cdd_Uart_EnableReadIntr(UartHwUnitObj, FALSE);

                /* Reset the UART configuration and transactions */
                Cdd_Uart_ConfigWriteTrans(&UartHwUnitObj->Cdd_Uart_WriteTransaction, NULL_PTR, 0U);
                Cdd_Uart_ConfigReadTrans(&UartHwUnitObj->Cdd_Uart_ReadTransaction, NULL_PTR, 0U);

                /* Deinit the UART HW unit */
                Cdd_Uart_HwUnitDeinit(UartHwUnitObj);
            }
        }

        /* Set the UART initialization flag to FALSE */
        Cdd_Uart_IsInitialized = FALSE;
    }
    else
    {
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
        /* If the UART is not initialized, report an error */
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_DEINIT, CDD_UART_E_UNINIT);
#endif
    }
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_Write(uint8  HwUnitId, P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) SrcBufferPtr,
               uint32 Count)
{
    Std_ReturnType       ret_value     = E_NOT_OK;
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Uart_IsInitialized)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_WRITE, CDD_UART_E_UNINIT);
    }
    else if (HwUnitId >= CDD_UART_MAX_NUM_HWUNIT)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_WRITE, CDD_UART_E_PARAM_HWINDEX);
    }
    else
#endif
    {
        UartHwUnitObj = &Cdd_Uart_Obj[HwUnitId];

        if (E_OK == Cdd_Uart_CheckParam(UartHwUnitObj, SrcBufferPtr, Count))
        {
            ret_value = Cdd_Uart_PrivWrite(UartHwUnitObj, SrcBufferPtr, Count);
        }
    }

    return ret_value;
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_Read(uint8 HwUnitId, P2VAR(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) DestBufferPtr, uint32 Count)
{
    Std_ReturnType       ret_value     = E_NOT_OK;
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Uart_IsInitialized)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_READ, CDD_UART_E_UNINIT);
    }
    else if (HwUnitId >= CDD_UART_MAX_NUM_HWUNIT)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_READ, CDD_UART_E_PARAM_HWINDEX);
    }
    else
#endif
    {
        UartHwUnitObj = &Cdd_Uart_Obj[HwUnitId];

        if (E_OK == Cdd_Uart_CheckParam(UartHwUnitObj, DestBufferPtr, Count))
        {
            ret_value = Cdd_Uart_PrivRead(UartHwUnitObj, DestBufferPtr, Count);
        }
    }

    return ret_value;
}

FUNC(Std_ReturnType, CDD_UART_CODE) Cdd_Uart_CancelWrite(uint8 HwUnitId)
{
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;
    Std_ReturnType       ret_value     = E_NOT_OK;

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Uart_IsInitialized)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_CANCEL_WRITE, CDD_UART_E_UNINIT);
    }
    else if (HwUnitId >= CDD_UART_MAX_NUM_HWUNIT)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_CANCEL_WRITE,
                              CDD_UART_E_PARAM_HWINDEX);
    }
    else
#endif
    {
        UartHwUnitObj = &Cdd_Uart_Obj[HwUnitId];
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
        if (NULL_PTR == UartHwUnitObj)
        {
            (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_CANCEL_WRITE,
                                  CDD_UART_E_PARAM_POINTER);
        }
        else
#endif
        {
            SchM_Enter_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_0();

            /* Abort the current write transaction */
            Cdd_Uart_ConfigWriteTrans(&UartHwUnitObj->Cdd_Uart_WriteTransaction, NULL_PTR, 0U);

            /* Disable Write interrupt */
            Cdd_Uart_EnableWriteIntr(UartHwUnitObj, FALSE);

            SchM_Exit_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_0();

            ret_value = E_OK;
        }
    }

    return ret_value;
}

FUNC(Std_ReturnType, CDD_UART_CODE) Cdd_Uart_CancelRead(uint8 HwUnitId)
{
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;
    Std_ReturnType       ret_value     = E_NOT_OK;

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Uart_IsInitialized)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_CANCEL_READ, CDD_UART_E_UNINIT);
    }
    else if (HwUnitId >= CDD_UART_MAX_NUM_HWUNIT)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_CANCEL_READ,
                              CDD_UART_E_PARAM_HWINDEX);
    }
    else
#endif
    {
        UartHwUnitObj = &Cdd_Uart_Obj[HwUnitId];
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
        if (NULL_PTR == UartHwUnitObj)
        {
            (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_CANCEL_READ,
                                  CDD_UART_E_PARAM_POINTER);
        }
        else
#endif
        {
            SchM_Enter_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_1();

            /* Abort the current read transaction */
            Cdd_Uart_ConfigReadTrans(&UartHwUnitObj->Cdd_Uart_ReadTransaction, NULL_PTR, 0U);

            /* Disable Read interrupt */
            Cdd_Uart_EnableReadIntr(UartHwUnitObj, FALSE);

            SchM_Exit_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_1();

            ret_value = E_OK;
        }
    }

    return ret_value;
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_GetWriteStatus(uint8 HwUnitId, Cdd_Uart_WriteStatusType *WriteStatus)
{
    Std_ReturnType ret_value = E_NOT_OK;

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Uart_IsInitialized)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_GET_WRITE_STATUS,
                              CDD_UART_E_UNINIT);
    }
    else if (NULL_PTR == WriteStatus)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_GET_WRITE_STATUS,
                              CDD_UART_E_PARAM_POINTER);
    }
    else if (HwUnitId >= CDD_UART_MAX_NUM_HWUNIT)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_GET_WRITE_STATUS,
                              CDD_UART_E_PARAM_HWINDEX);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_0();

        /* Get the Remaining words to write */
        WriteStatus->Cdd_Uart_RemainingWordsToWrite =
            Cdd_Uart_Obj[HwUnitId].Cdd_Uart_WriteTransaction.Cdd_Uart_WriteCount -
            Cdd_Uart_Obj[HwUnitId].Cdd_Uart_WriteTransaction.Cdd_Uart_CurrWriteCount;
        /* Busy status */
        WriteStatus->Cdd_Uart_BusyStatus = Cdd_Uart_IsWriteBusy(&Cdd_Uart_Obj[HwUnitId]);

        SchM_Exit_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_0();

        ret_value = E_OK;
    }

    return ret_value;
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_GetReadStatus(uint8 HwUnitId, Cdd_Uart_ReadStatusType *ReadStatus)
{
    Std_ReturnType ret_value = E_NOT_OK;

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Uart_IsInitialized)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_GET_READ_STATUS,
                              CDD_UART_E_UNINIT);
    }
    else if (NULL_PTR == ReadStatus)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_GET_READ_STATUS,
                              CDD_UART_E_PARAM_POINTER);
    }
    else if (HwUnitId >= CDD_UART_MAX_NUM_HWUNIT)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_GET_READ_STATUS,
                              CDD_UART_E_PARAM_HWINDEX);
    }
    else
#endif
    {
        SchM_Enter_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_1();

        /* Get the remaining words to read */
        ReadStatus->Cdd_Uart_RemainingWordsToRead =
            Cdd_Uart_Obj[HwUnitId].Cdd_Uart_ReadTransaction.Cdd_Uart_ReadCount -
            Cdd_Uart_Obj[HwUnitId].Cdd_Uart_ReadTransaction.Cdd_Uart_CurrReadCount;
        /* Busy status */
        ReadStatus->Cdd_Uart_BusyStatus = Cdd_Uart_IsReadBusy(&Cdd_Uart_Obj[HwUnitId]);

        SchM_Exit_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_1();

        ret_value = E_OK;
    }

    return ret_value;
}

FUNC(void, CDD_UART_CODE) Cdd_Uart_MainFunction_Write(void)
{
    uint8                hwUnit        = 0U;
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;

    for (hwUnit = 0U; hwUnit < CDD_UART_MAX_NUM_HWUNIT; hwUnit++)
    {
        UartHwUnitObj = &Cdd_Uart_Obj[hwUnit];

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
        if (FALSE == Cdd_Uart_IsInitialized)
        {
            (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_MAIN_FUN_WRITE,
                                  CDD_UART_E_UNINIT);
        }
        else
#endif
        {
            if ((TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_WriteEnable) &&
                (CDD_UART_MODE_POLLING == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_IoMode) &&
                (NULL_PTR != UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_WriteBuf))
            {
                /* Push to Write fifo */
                Cdd_Uart_PushWriteFifo(UartHwUnitObj);
            }
        }
    }
}

FUNC(void, CDD_UART_CODE) Cdd_Uart_Poll_Read(void)
{
    uint8                hwUnit        = 0U;
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;

    for (hwUnit = 0U; hwUnit < CDD_UART_MAX_NUM_HWUNIT; hwUnit++)
    {
        UartHwUnitObj = &Cdd_Uart_Obj[hwUnit];

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
        if (FALSE == Cdd_Uart_IsInitialized)
        {
            (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_POLL_READ, CDD_UART_E_UNINIT);
        }
        else
#endif
        {
            if (CDD_UART_MODE_POLLING == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_IoMode)
            {
                Cdd_Uart_Poll_PrivRead(UartHwUnitObj);
            }
        }
    }
}

FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_GetErrorStatus(uint8 HwUnitId, uint8 *ErrorStatus)
{
    Std_ReturnType       retVal        = E_NOT_OK;
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Uart_IsInitialized)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_ERROR_STATUS, CDD_UART_E_UNINIT);
    }
    else if (NULL_PTR == ErrorStatus)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_ERROR_STATUS,
                              CDD_UART_E_PARAM_POINTER);
    }
    else if (HwUnitId >= CDD_UART_MAX_NUM_HWUNIT)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_ERROR_STATUS,
                              CDD_UART_E_PARAM_HWINDEX);
    }
    else
#endif

    {
        UartHwUnitObj = &Cdd_Uart_Obj[HwUnitId];
        /* Read the error value*/
        *ErrorStatus = UartHwUnitObj->Cdd_Uart_Error;

        retVal = E_OK;
    }

    return retVal;
}

FUNC(void, CDD_UART_CODE) Cdd_Uart_FlushReadFIFO(uint8 HwUnitId)
{
    Cdd_Uart_ObjectType *UartHwUnitObj = NULL_PTR;

#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
    if (FALSE == Cdd_Uart_IsInitialized)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_FLUSH_READ_BUFFER,
                              CDD_UART_E_UNINIT);
    }
    else if (HwUnitId >= CDD_UART_MAX_NUM_HWUNIT)
    {
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_FLUSH_READ_BUFFER,
                              CDD_UART_E_PARAM_HWINDEX);
    }
    else
#endif
    {
        UartHwUnitObj = &Cdd_Uart_Obj[HwUnitId];
        /* Flush read fifo */
        Cdd_Uart_PrivFlushReadFifo(UartHwUnitObj);
    }
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

static FUNC(Std_ReturnType, CDD_UART_CODE)
    Cdd_Uart_PrivWrite(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj,
                       P2CONST(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) SrcBufferPtr, uint32 Count)
{
    Std_ReturnType ret_value = E_NOT_OK;

    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_WriteEnable)
    {
        SchM_Enter_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_0();

        if (NULL_PTR == UartHwUnitObj->Cdd_Uart_WriteTransaction.Cdd_Uart_WriteBuf)
        {
            /* Save the write request */
            Cdd_Uart_ConfigWriteTrans(&UartHwUnitObj->Cdd_Uart_WriteTransaction, SrcBufferPtr, Count);

            /* Push to Write fifo */
            Cdd_Uart_PushWriteFifo(UartHwUnitObj);

            if (CDD_UART_MODE_INTERRUPT == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_IoMode)
            {
                /* Enable Write interrupt */
                Cdd_Uart_EnableWriteIntr(UartHwUnitObj, TRUE);
            }

            ret_value = E_OK;
        }

        SchM_Exit_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_0();
    }
    else
    {
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_WRITE, CDD_UART_E_PARAM_VALUE);
#endif
    }

    return ret_value;
}

static FUNC(Std_ReturnType, CDD_UART_CODE)
    Cdd_Uart_PrivRead(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj,
                      P2VAR(Cdd_Uart_DataBufferType, AUTOMATIC, CDD_UART_APPL_DATA) DestBufferPtr, uint32 Count)
{
    Std_ReturnType ret_value = E_NOT_OK;

    if (TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ReadEnable)
    {
        SchM_Enter_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_1();

        if (NULL_PTR == UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_ReadBuf)
        {
            /* Schedule the read operation in the main function */
            Cdd_Uart_ConfigReadTrans(&UartHwUnitObj->Cdd_Uart_ReadTransaction, DestBufferPtr, Count);

            if (CDD_UART_MODE_INTERRUPT == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_IoMode)
            {
                /* Enable Read interrupt */
                Cdd_Uart_EnableReadIntr(UartHwUnitObj, TRUE);
            }

            ret_value = E_OK;
        }

        SchM_Exit_Cdd_Uart_CDD_UART_EXCLUSIVE_AREA_1();
    }
    else
    {
#if (STD_ON == CDD_UART_CFG_DEV_ERROR_DETECT)
        (void)Det_ReportError(CDD_UART_MODULE_ID, CDD_UART_INSTANCE_ID, CDD_UART_SID_READ, CDD_UART_E_PARAM_VALUE);
#endif
    }

    return ret_value;
}

static FUNC(void, CDD_UART_CODE)
    Cdd_Uart_Poll_PrivRead(P2VAR(Cdd_Uart_ObjectType, AUTOMATIC, CDD_UART_APPL_DATA) UartHwUnitObj)
{
    /* Error  */
    if (E_NOT_OK == Cdd_Uart_CheckReadErrors(UartHwUnitObj))
    {
        Cdd_Uart_ErrorInterruptHandler(UartHwUnitObj);
    }
    else
    {
        if ((TRUE == UartHwUnitObj->Cdd_Uart_HwUnitCfg->Cdd_Uart_ReadEnable) &&
            (NULL_PTR != UartHwUnitObj->Cdd_Uart_ReadTransaction.Cdd_Uart_ReadBuf))
        {
            /* Pull from Read fifo */
            Cdd_Uart_PullReadFifo(UartHwUnitObj);
        }
    }
}

#define CDD_UART_STOP_SEC_CODE
#include "Cdd_Uart_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Cdd_Uart.c
 *********************************************************************************************************************/
