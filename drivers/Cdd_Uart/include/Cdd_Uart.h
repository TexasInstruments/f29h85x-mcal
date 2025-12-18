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
 *  File:       Cdd_Uart
 *  Generator:  None
 *
 *  Description:  This file contains CDD UART driver public API function declarations .
 *********************************************************************************************************************/
#ifndef CDD_UART_H
#define CDD_UART_H

/**
 * \defgroup CDD_UART Cdd Uart
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Cdd_Uart_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/* Defines for CDD_UART Driver version used for compatibility checks.*/
/** \brief Driver Implementation Major Version */
#define CDD_UART_SW_MAJOR_VERSION (3U)
/** \brief Driver Implementation Minor Version */
#define CDD_UART_SW_MINOR_VERSION (0U)
/** \brief Driver Implementation Patch Version */
#define CDD_UART_SW_PATCH_VERSION (0U)

/*  Defines for CDD_UART Driver AUTOSAR version used for compatibility checks. */
/** \brief AUTOSAR Major version specification implemented by CDD_UART Driver*/
#define CDD_UART_AR_RELEASE_MAJOR_VERSION (4U)
/** \brief AUTOSAR Minor version specification implemented by CDD_UART Driver*/
#define CDD_UART_AR_RELEASE_MINOR_VERSION (3U)
/** \brief AUTOSAR Patch version specification implemented by CDD_UART Driver*/
#define CDD_UART_AR_RELEASE_REVISION_VERSION (1U)

/* CDD UART Driver ID Info. */
/** \brief Texas Instruments Vendor ID */
#define CDD_UART_VENDOR_ID ((uint16)44U)
/** \brief CDD UART Driver Module ID */
#define CDD_UART_MODULE_ID ((uint16)255U)
/** \brief CDD UART Instance ID */
#define CDD_UART_INSTANCE_ID ((uint8)0U)

/* Error codes returned by Cdd Uart functions. */
/** \brief API service used without module initialization */
#define CDD_UART_E_UNINIT ((uint8)0x01U)
/** \brief API Cdd_Uart_Init service called while the UART driver has already been initialized */
#define CDD_UART_E_ALREADY_INITIALIZED ((uint8)0x02U)
/** \brief  API service called with invalid parameter value */
#define CDD_UART_E_PARAM_VALUE ((uint8)0x03U)
/** \brief  API service called with invalid data buffer pointer */
#define CDD_UART_E_PARAM_POINTER ((uint8)0x04U)
/** \brief  API service called with invalid hardware index */
#define CDD_UART_E_PARAM_HWINDEX ((uint8)0x05U)
/* \brief API service called when UART is busy*/
#define CDD_UART_E_BUSY ((uint8)0x06U)

/* No Error*/
#define CDD_UART_NO_ERROR ((uint8)0x00U)

/* The Service Id is one of the argument to Det_ReportError function and is used to identify the
 * source of the error. */
/** \brief Cdd_Uart_GetVersionInfo API Service ID */
#define CDD_UART_SID_GET_VERSION_INFO ((uint8)0x00U)
/** \brief Cdd_Uart_Init() API Service ID */
#define CDD_UART_SID_INIT ((uint8)0x01U)
/** \brief Cdd_Uart_DeInit() API Service ID */
#define CDD_UART_SID_DEINIT ((uint8)0x02U)
/** \brief Cdd_Uart_Write() API Service ID */
#define CDD_UART_SID_WRITE ((uint8)0x03U)
/** \brief Cdd_Uart_Read() API Service ID */
#define CDD_UART_SID_READ ((uint8)0x04U)
/** \brief Cdd_Uart_CancelWrite() API Service ID */
#define CDD_UART_SID_CANCEL_WRITE ((uint8)0x05U)
/** \brief Cdd_Uart_CancelRead() API Service ID */
#define CDD_UART_SID_CANCEL_READ ((uint8)0x06U)
/** \brief Cdd_Uart_GetWriteStatus() API Service ID */
#define CDD_UART_SID_GET_WRITE_STATUS ((uint8)0x07U)
/** \brief Cdd_Uart_GetReadStatus() API Service ID */
#define CDD_UART_SID_GET_READ_STATUS ((uint8)0x08U)
/** \brief Cdd_Uart_MainFunction_Write() API Service ID */
#define CDD_UART_SID_MAIN_FUN_WRITE ((uint8)0x09U)
/** \brief Cdd_Uart_Poll_Read() API Service ID */
#define CDD_UART_SID_POLL_READ ((uint8)0x0AU)
/** \brief Cdd_Uart_GetErrorStatus() API Service ID */
#define CDD_UART_SID_ERROR_STATUS ((uint8)0x0BU)
/** \brief Cdd_Uart_FlushReadFIFO() API Service ID */
#define CDD_UART_SID_FLUSH_READ_BUFFER ((uint8)0x0CU)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief Cdd Uart Callback type */
typedef void (*Cdd_Uart_CallbackType)(void);

/** \brief Uart Configuration Instance ID */
typedef enum
{
    /** \brief UARTA Config Instance */
    CDD_UART_INSTANCE_UARTA = 0U,
    /** \brief UARTB Config Instance */
    CDD_UART_INSTANCE_UARTB = 1U,
    /** \brief UARTC Config Instance */
    CDD_UART_INSTANCE_UARTC = 2U,
    /** \brief UARTD Config Instance */
    CDD_UART_INSTANCE_UARTD = 3U,
    /** \brief UARTE Config Instance */
    CDD_UART_INSTANCE_UARTE = 4U,
    /** \brief UARTF Config Instance */
    CDD_UART_INSTANCE_UARTF = 5U
} Cdd_Uart_Instance;

/** \brief UART Word Length */
typedef enum
{
    /** \brief UART Word Length 5 bits */
    CDD_UART_WORD_LENGTH_5 = 0U,
    /** \brief UART Word Length 6 bits */
    CDD_UART_WORD_LENGTH_6 = 1U,
    /** \brief UART Word Length 7 bits */
    CDD_UART_WORD_LENGTH_7 = 2U,
    /** \brief UART Word Length 8 bits */
    CDD_UART_WORD_LENGTH_8 = 3U
} Cdd_Uart_WordLength;

/** \brief UART Stop Bits */
typedef enum
{
    /** \brief UART Stop Bits 1 bit */
    CDD_UART_STOP_BITS_1 = 0U,
    /** \brief UART Stop Bits 2 bits */
    CDD_UART_STOP_BITS_2 = 1U
} Cdd_Uart_StopBits;

/** \brief UART Mode */
typedef enum
{
    /** \brief UART Mode Polling */
    CDD_UART_MODE_POLLING = 0U,
    /** \brief UART Mode Interrupt */
    CDD_UART_MODE_INTERRUPT = 1U
} Cdd_Uart_Mode;

/** \brief UART FIFO Level */
typedef enum
{
    /** \brief UART FIFO Level 1/8 */
    CDD_UART_FIFO_LEVEL_1_8 = 0U,
    /** \brief UART FIFO Level 1/4 */
    CDD_UART_FIFO_LEVEL_1_4 = 1U,
    /** \brief UART FIFO Level 1/2 */
    CDD_UART_FIFO_LEVEL_1_2 = 2U,
    /** \brief UART FIFO Level 3/4 */
    CDD_UART_FIFO_LEVEL_3_4 = 3U,
    /** \brief UART FIFO Level 7/8 */
    CDD_UART_FIFO_LEVEL_7_8 = 4U
} Cdd_Uart_FifoLevel;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/** \brief Typedef for the data buffer elements*/
typedef uint8 Cdd_Uart_DataBufferType;

/**
 *  CDD UART Config type
 *
 * \brief UART configuration data structure for a channel
 */
typedef struct Cdd_Uart_CfgTag
{
    /**< Uart clock frequency */
    uint32                Cdd_Uart_ClockFreq;
    /**< Uart baud rate */
    uint32                Cdd_Uart_BaudRateCfg;
    /**< Uart word length */
    Cdd_Uart_WordLength   Cdd_Uart_WordLength;
    /**< Uart stop bits */
    Cdd_Uart_StopBits     Cdd_Uart_StopBits;
    /**< Uart Write fifo level */
    Cdd_Uart_FifoLevel    Cdd_Uart_WriteFifoLvl;
    /**< Uart Read fifo level */
    Cdd_Uart_FifoLevel    Cdd_Uart_ReadFifoLvl;
    /**< Uart Instance */
    Cdd_Uart_Instance     Cdd_Uart_Instance;
    /**< Uart Base Address */
    uint32                Cdd_Uart_BaseAddr;
    /**< Uart hw unit id */
    uint8                 Cdd_Uart_HWUnitId;
    /**< Uart I/o mode polling/interrupt */
    Cdd_Uart_Mode         Cdd_Uart_IoMode;
    /**< Uart Write Enable */
    boolean               Cdd_Uart_WriteEnable;
    /**< Uart Read Enable */
    boolean               Cdd_Uart_ReadEnable;
    /**< Uart fifo enable */
    boolean               Cdd_Uart_FifoEnable;
    /**< Uart parity enable */
    boolean               Cdd_Uart_ParityEnable;
    /**< Uart Loopback enable */
    boolean               Cdd_Uart_LoopbackEnable;
    /**< Uart Write Done Callback */
    Cdd_Uart_CallbackType Cdd_Uart_WriteCompleteCb;
    /**< Uart Read Done Callback */
    Cdd_Uart_CallbackType Cdd_Uart_ReadCompleteCb;
    /**< Uart Error Callback */
    Cdd_Uart_CallbackType Cdd_Uart_ErrorCb;
    /**< Uart Highspeed Mode enable */
    boolean               Cdd_Uart_HighSpeedEnable;
} Cdd_Uart_CfgType;

/**
 *   CDD UART Configurations type
 *
 *  \brief UART configuration structure for all channels in use
 */
typedef struct Cdd_Uart_ConfigTag
{
    /* Channel Configurations */
    Cdd_Uart_CfgType Cdd_Uart_HwUnitCfg[CDD_UART_MAX_NUM_HWUNIT];
} Cdd_Uart_ConfigType;

/** \brief Typedef for the Write Status */
typedef struct Cdd_Uart_WriteStatusTag
{
    /**< Words remaining to transfer */
    uint32         Cdd_Uart_RemainingWordsToWrite;
    /**< Busy status */
    Std_ReturnType Cdd_Uart_BusyStatus;
} Cdd_Uart_WriteStatusType;

/** \brief Typedef for the Read Status */
typedef struct Cdd_Uart_ReadStatusTag
{
    /**< Words remaining to read */
    uint32         Cdd_Uart_RemainingWordsToRead;
    /**< Busy status */
    Std_ReturnType Cdd_Uart_BusyStatus;
} Cdd_Uart_ReadStatusType;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief Service to provide the version information of Cdd Uart module
 * \param[inout] VersionInfoPtr is the pointer to CDD UART driver version information
 * \pre This API is available only if CDD_UART_GET_VERSION_INFO_API is STD_ON
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
#if (STD_ON == CDD_UART_CFG_GET_VERSION_INFO_API)
FUNC(void, CDD_UART_CODE)
Cdd_Uart_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDD_UART_APPL_DATA) VersionInfoPtr);
#endif /* CDD_UART_CFG_GET_VERSION_INFO_API */

/** \brief Cdd_Uart_Init : Initializes the CDD_UART module.
 *
 * This service initialize the CDD_UART driver
 * \param[in] ConfigPtr Pointer to CDD_UART driver configuration set
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE)
Cdd_Uart_Init(P2CONST(Cdd_Uart_ConfigType, AUTOMATIC, CDD_UART_CONFIG_DATA) ConfigPtr);

/** \brief Cdd_Uart_Deinit : De-initializes the CDD_UART module.
 *
 * This service deinitialize the CDD_UART driver
 *
 * \pre Cdd_Uart_Init should be called first, before calling this service.
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_Deinit(void);

/** \brief Service to transmit data
 *
 * \param[in] HwUnitId number to be used for writing data
 * \param[in] SrcBufferPtr - Pointer to source data buffer
 * \param[in] Count - number of data elements to be transmitted from SrcBufferPtr
 * \pre None
 * \post None
 * \return Cdd_Uart_Write request is accepted or not
 * \retval E_OK: Write request has been accepted.
 * \retval E_NOT_OK: Write request has not been accepted.
 *****************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_Write(uint8 HwUnitId, const Cdd_Uart_DataBufferType* SrcBufferPtr, uint32 Count);

/** \brief Service to reception of data
 *
 * \param[in] HwUnitId number to be used for writing data
 * \param[in] DestBufferPtr - Pointer to dest data buffer
 * \param[in] Count - number of data elements to be read into DestBufferPtr
 * \pre None
 * \post None
 * \return Cdd_Uart_Read request is accepted or not
 * \retval E_OK: Read request has been accepted.
 * \retval E_NOT_OK: Read request has not been accepted.
 *****************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_Read(uint8 HwUnitId, Cdd_Uart_DataBufferType* DestBufferPtr, uint32 Count);

/** \brief Service to cancel the ongoing transmission
 *
 * \param[in] HwUnitId number to be used for cancellation of Write
 * \pre None
 * \post None
 * \return Cdd_Uart_CancelWrite request is accepted or not
 * \retval E_OK: CancelWrite request has been accepted.
 * \retval E_NOT_OK: CancelWrite request has not been accepted.
 *****************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE) Cdd_Uart_CancelWrite(uint8 HwUnitId);

/** \brief Service to cancel the ongoing transmission
 *
 * \param[in] HwUnitId number to be used for cancellation of Write
 * \pre None
 * \post None
 * \return Cdd_Uart_CancelRead request is accepted or not
 * \retval E_OK: CancelRead request has been accepted.
 * \retval E_NOT_OK: CancelRead request has not been accepted.
 *****************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE) Cdd_Uart_CancelRead(uint8 HwUnitId);

/** \brief Service to get the status of the ongoing transmission
 *
 * \param[in] HwUnitId hw id to be used for status of Write
 * \param[in] WriteStatus pointer to Cdd_Uart_WriteStatusType
 * \pre None
 * \post None
 * \return Cdd_Uart_GetWriteStatus request is accepted or not
 * \retval E_OK: GetWriteStatus request has been accepted.
 * \retval E_NOT_OK: GetWriteStatus request has not been accepted.
 *****************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_GetWriteStatus(uint8 HwUnitId, Cdd_Uart_WriteStatusType* WriteStatus);

/** \brief Service to get the status of the ongoing transmission
 *
 * \param[in] HwUnitId hw id to be used for status of Read
 * \param[in] ReadStatus pointer to Cdd_Uart_ReadStatusType
 * \pre None
 * \post None
 * \return Cdd_Uart_GetReadStatus request is accepted or not
 * \retval E_OK: GetReadStatus request has been accepted.
 * \retval E_NOT_OK: GetReadStatus request has not been accepted.
 *****************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_GetReadStatus(uint8 HwUnitId, Cdd_Uart_ReadStatusType* ReadStatus);

/** \brief Service to auto perform the polling of configured UART Write channel
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_MainFunction_Write(void);

/** \brief Service to perform the polling of confgured UART Read channel by user
 *
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *****************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_Poll_Read(void);

/** \brief Service to get the status of the Uart error.
 * User can use this service in the Error callback implementation to fetch the
 * exact Uart Error
 *
 * \param[in] HwUnitId hw id to be used for status of Error
 * \param[in] ErrorStatus pointer to Cdd_Uart_Error type
 * \pre None
 * \post None
 * \return Uart error : PE,OE,BE,FE
 * \retval E_OK: Error status request has been accepted
 * \retval E_NOT_OK: Error status request has not been accepted
 *****************************************************************************/
FUNC(Std_ReturnType, CDD_UART_CODE)
Cdd_Uart_GetErrorStatus(uint8 HwUnitId, uint8* ErrorStatus);

/** \brief Service to flush the read buffer.
 * User can use this service to flush the readbuffer incase of any unread data after any
 * Uart Error
 *
 * \param[in] HwUnitId hw id to be used to flush the read buffer
 * \pre None
 * \post None
 * \return None
 * \retval None
 *****************************************************************************/
FUNC(void, CDD_UART_CODE) Cdd_Uart_FlushReadFIFO(uint8 HwUnitId);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* Mark the end of the C bindings section for C++ compilers. */
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_UART_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Uart.h
 *********************************************************************************************************************/
