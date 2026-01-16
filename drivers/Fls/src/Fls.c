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
 *  \file       Fls.c
 *
 *  Project:    C29x MCAL
 *  Module:     FLS Driver
 *  Generator:  None
 *
 *  \brief  This file contains interface and services for Fls Driver
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Fls.h"
#include "Fls_Priv.h"
#include "Det.h"
#include "SchM_Fls.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*  AUTOSAR version information check has to match definition in header file */
#if ((FLS_AR_RELEASE_MAJOR_VERSION != (4U)) || (FLS_AR_RELEASE_MINOR_VERSION != (3U)) || \
     (FLS_AR_RELEASE_REVISION_VERSION != (1U)))
#error "Fls: AUTOSAR Version Numbers of Fls are different!!"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ((FLS_SW_MAJOR_VERSION != (3U)) || (FLS_SW_MINOR_VERSION != (1U)))
#error "Fls: Software Version Numbers are inconsistent!!"
#endif

/* AUTOSAR version information check has to match definition in FLS_Cfg.h file */
#if ((FLS_CFG_MAJOR_VERSION != (3U)) || (FLS_CFG_MINOR_VERSION != (1U)))
#error "Version numbers of Fls.c and Fls_Cfg.h are inconsistent!"
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
#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

extern VAR(uint32, FLS_VAR_NO_INIT_32) Fls_CMD_WE_Protection_A_Mask; /* protection for the first 32 sectors */
extern VAR(uint32, FLS_VAR_NO_INIT_32) Fls_CMD_WE_Protection_B_Mask; /* protection for the 32 – 256 sectors */
extern VAR(uint32, FLS_VAR_NO_INIT_32) Fls_u32UserFlashConfig;       /* User flash configuration */

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

/* \brief FLS driver object */
Fls_DriverObjType Fls_DrvObj = {
    .status = MEMIF_UNINIT /* 0x0, defined in Memif_Types.h*/
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_NO_INIT_32
#include "Fls_MemMap.h"

/*Set Erase Type Parameters */
VAR(uint32, FLS_VAR_NO_INIT_32) sector_or_banksize;

#define FLS_STOP_SEC_VAR_NO_INIT_32
#include "Fls_MemMap.h"

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == FLS_DEV_ERROR_DETECT)
/* \brief The function do initialisation when the Controller is active.
 *
 * \param[in] SourceAddress source address
 * \pre None
 * \post None
 * \return status
 * \retval E_OK
 * \retval E_NOT_OK
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, FLS_CODE) Fls_CheckValidAddress(Fls_AddressType SourceAddress);

/* \brief The function do initialisation when the Controller is active.
 *
 * \param[in] SourceAddress start address of a flash sector
 * \pre None
 * \post None
 * \return status
 * \retval E_OK
 * \retval E_NOT_OK
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, FLS_CODE) Fls_CheckSectorAlignment(Fls_AddressType SourceAddress);
/* \brief The function do initialisation when the Controller is active.
 *
 * \param[in] SourceAddress start address of a flash sector
 * \pre None
 * \post None
 * \return status
 * \retval E_OK
 * \retval E_NOT_OK
 *
 *****************************************************************************/
static FUNC(Std_ReturnType, FLS_CODE) Fls_CheckWrtAddressAlignment(Fls_AddressType SourceAddress);

#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT)*/
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/*
 *  Function Name: Fls_Init
 *
 *  The function Fls_Init shall initialize the FLS module and all
 *	flash memory relevant registers (hardware) with parameters
 *	provided in the given configuration set
 *  SWS_Fls_00249
 *  Design: MCAL-30923, MCAL-30924, MCAL-30925, MCAL-30926, MCAL-30927, MCAL-30928, MCAL-30929
 *  Design: MCAL-30930
 */
FUNC(void, FLS_CODE) Fls_Init(P2CONST(Fls_ConfigType, AUTOMATIC, FLS_CONFIG_DATA) ConfigPtr)
{
    const Fls_ConfigType *CfgPtr = NULL_PTR;

    VAR(uint16, AUTOMATIC) waitStates = (uint16)3U;
    VAR(Std_ReturnType, AUTOMATIC) oReturnCheck;
    VAR(uint32, AUTOMATIC) CPU_SYS_CLOCK_MHZ = (uint32)0U;

#if (STD_ON == FLS_PRE_COMPILE_VARIANT)
    if (NULL_PTR == ConfigPtr)
    {
        CfgPtr = &FLS_INIT_CONFIG_PC;
    }
#endif /* (STD_ON == FLS_PRE_COMPILE_VARIANT) */

#if (STD_ON == FLS_POST_BUILD_VARIANT)
    if (NULL_PTR != ConfigPtr)
    {
        CfgPtr = ConfigPtr;
    }
#endif /* (STD_ON == FLS_POST_BUILD_VARIANT) */

/* SWS_Fls_00015*/
#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_BUSY == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_BUSY);
    }
    else if (NULL_PTR == CfgPtr)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_PARAM_CONFIG);
    }
    else if (CfgPtr->FlsMaxReadNormalMode == (uint32)0U)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_PARAM_CONFIG);
    }
    else if ((CfgPtr->FlsMaxWriteNormalMode == (uint32)0U) || ((CfgPtr->FlsMaxWriteNormalMode % (uint32)8U) != 0U) ||
             (CfgPtr->FlsMaxWriteNormalMode > (uint32)16U))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_INIT, FLS_E_PARAM_CONFIG);
    }
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        /* SWS_Fls_00191*/
        /* SWS_Fls_00086*/
        /* Instantiate a Driver Obj to be used by module */
        Fls_resetDrvObj(&Fls_DrvObj);
        /* Copy the input config parameters to Driver Object */
        Fls_copyConfig(&Fls_DrvObj, CfgPtr);

        /* At 200MHz, execution wait-states for external oscillator is 3 */
        /* function to calculate waitstates*/
        if (FLS_CPU_CLOCK_FREQ >= 150000000U)
        {
            waitStates = 3U;
        }
        else
        {
            waitStates = 2U;
        }

        Fls_Update_WaitStates(waitStates);

        Fls_CMD_WE_Protection_A_Mask = FLS_CMDWEPROTA;
        Fls_CMD_WE_Protection_B_Mask = FLS_CMDWEPROTB;

        /*
         * Initialize the Flash API by providing the Flash register base address
         * and operating frequency(in MHz).
         * This function is required to initialize the Flash API based on System
         * frequency before any other Flash API operation can be performed.
         * This function must also be called whenever System frequency or RWAIT is
         * changed.
         **/
        CPU_SYS_CLOCK_MHZ = FLS_CPU_CLOCK_FREQ / FLS_CONV_TO_MHZ;
        oReturnCheck      = Fls_Fapi_initializeAPI(CPU_SYS_CLOCK_MHZ);

        if (oReturnCheck != E_OK)
        {
            /* Check Flash API documentation for possible errors */
            /* SWS_Fls_00323*/
            Fls_DrvObj.status = MEMIF_UNINIT;
        }
        else
        {
            Fls_DrvObj.status = MEMIF_IDLE;
        }

        /* Check the maximum write size */

        Fls_DrvObj.FlsMaxWriteNormalMode = 16U;

        /* SWS_Fls_00324*/
        Fls_DrvObj.jobResultType = MEMIF_JOB_OK; /* The job has been finished successfully */
    }
    return;
}

/*
 *  Function Name: Fls_Erase
 *
 *  The function Fls_Erase shall erase one or more complete flash sectors.
 *  SWS_Fls_00250
 *  Design: MCAL-30931, MCAL-30932, MCAL-30933, MCAL-30934, MCAL-30935, MCAL-30936, MCAL-30937
 *  Design: MCAL-30938, MCAL-30939, MCAL-30940, MCAL-30941, MCAL-30942
 */
FUNC(Std_ReturnType, FLS_CODE) Fls_Erase(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    /* TargetAddress is the offset relative to the FLS base address which is 0x10c00000 for F29H85x
     * device */
    /* The offset should be less than the total flash size (assume 1MB)  */
    /* TargetAddress = TargetAddress & 0xFFFFF; */

    /* Fls_Erase erases a flash memory block starting from FlsBaseAddress + TargetAddress of size
      Length. Length should be rounded up to the next full sector boundary since only complete flash
      sectors can be erased.
    */
    VAR(Fls_AddressType, AUTOMATIC)
    eraseStartAddress = (TargetAddress & 0xFFFFFU) + (FLS_BASE_ADDRESS & FLS_BASE_ADDRESS_REQ);

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    /* SWS_Fls_00065*/
    /* If development error detection is enabled: the Fls_Erase shall check that the FLS module has
       been initialized. If this check fails, the Fls_Erase shall reject the erase request, raise
       the development error FLS_E_UNINIT and return with E_NOT_OK
    */
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00023*/
    /* If development error detection is enabled: the Fls_Erase shall check that the FLS module is
       currently not busy. If this check fails, the Fls_Erase shall reject the erase request, raise
       the development error FLS_E_BUSY and return with E_NOT_OK
    */
    else if (MEMIF_BUSY == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_BUSY);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00020*/
    /* SRS_Fls_12159*/
    /* If development error detection is enabled: the Fls_Erase shall check that the erase start
      address (FlsBaseAddress + TargetAddress) is aligned to a flash sector boundary and that it
      lies within the specified lower and upper flash address boundaries. If this check fails, the
      Fls_Erase shall reject the erase request, raise the development error FLS_E_PARAM_ADDRESS and
      return with E_NOT_OK
    */
    else if ((E_NOT_OK == Fls_CheckSectorAlignment(eraseStartAddress)) ||
             (E_NOT_OK == Fls_CheckValidAddress(eraseStartAddress)))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00021*/
    /* SRS_Fls_12159*/
    /* If development error detection for is enabled: the Fls_Erase shall check that the erase
       length is greater than 0 and that the erase end address (erase start address + length) is
       aligned to a flash sector boundary and that it lies within the specified upper flash address
       boundary. If this check fails, the Fls_Erase shall reject the erase request, raise the
       development error FLS_E_PARAM_LENGTH and return with E_NOT_OK
    */
    else if ((Length == 0U) || (E_NOT_OK == Fls_CheckSectorAlignment(eraseStartAddress + Length)) ||
             (E_NOT_OK == Fls_CheckValidAddress(eraseStartAddress + Length - 1U)))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_ERASE, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif /*  #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        if (Fls_DrvObj.status == MEMIF_IDLE)
        {
            /* SWS_Fls_00328*/
            /* After initiating the erase job, the Fls_Erase shall set the FLS module status to
             * MEMIF_BUSY*/
            Fls_DrvObj.status = MEMIF_BUSY;
            /* SWS_Fls_00329*/
            /* After initiating the erase job, the Fls_Erase shall set the job result to
             * MEMIF_JOB_PENDING*/
            Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
            Fls_DrvObj.jobType       = FLS_JOB_ERASE;

            /*  [ SWS_Fls_00221 ] */
            Fls_DrvObj.flashAddr   = eraseStartAddress;
            Fls_DrvObj.ramAddr     = NULL_PTR;
            Fls_DrvObj.length      = Length;
            Fls_DrvObj.transferred = (Fls_LengthType)0;

            if (Fls_DrvObj.typeoferase == FLS_SECTOR_ERASE)
            {
                Fls_DrvObj.jobChunkSize = FLS_SECTOR_SIZE;
            }
            else /* FLS_BANK_ERASE) */
            {
                Fls_DrvObj.jobChunkSize = FLS_TOTAL_SIZE / FLS_NUM_BANKS;
            }
        }
        else
        {
            (retVal = (Std_ReturnType)E_NOT_OK);
        }
    }
    return retVal;
};

/*
 *  Function Name: Fls_Read
 *
 *  The function Fls_Read shall read from flash memory.
 *  Design: MCAL-30970, MCAL-30971, MCAL-30972, MCAL-30973, MCAL-30974, MCAL-30975, MCAL-30976
 *  Design: MCAL-30977, MCAL-30978, MCAL-30979, MCAL-30980, MCAL-30981, MCAL-30982
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_Read(Fls_AddressType SourceAddress, P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr, Fls_LengthType Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    /* TargetAddress is the offset relative to the FLS base address which is 0x10c00000 for F29H85x
     * device */
    /* The offset should be less than the total flash size (assume 1MB)  */
    /* TargetAddress = TargetAddress & 0xFFFFF; */

    /* SWS_Fls_00239*/
    /* The read job of Fls_Read shall copy a continuous flash memory block starting from
      FlsBaseAddress + SourceAddress of size Length to the buffer pointed to by TargetAddressPtr
    */
    VAR(Fls_AddressType, AUTOMATIC)
    ReadStartAddress = (SourceAddress & 0xFFFFFU) + (FLS_BASE_ADDRESS & FLS_BASE_ADDRESS_REQ);
#if (STD_ON == FLS_DEV_ERROR_DETECT)
    /* SWS_Fls_00099*/
    /* If development error detection for the module Fls is enabled: the function Fls_Read shall
      check that the driver has been initialized. If this check fails, the function Fls_Read shall
      reject the read request, raise the development error FLS_E_UNINIT and return with E_NOT_OK
    */
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00100*/
    /* If development error detection for the module Fls is enabled: the function Fls_Read shall
      check that the driver is currently not busy. If this check fails, the function Fls_Read shall
      reject the read request, raise the development error FLS_E_BUSY and return with E_NOT_OK
    */
    else if (MEMIF_BUSY == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_BUSY);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00158*/
    /* If development error detection for the module Fls is enabled: the function Fls_Read shall
      check the given data buffer pointer for not being a null pointer. If the data buffer pointer
      is a null pointer, the function Fls_Read shall reject the read request, raise the development
      error FLS_E_PARAM_DATA and return with E_NOT_OK
    */
    else if (NULL_PTR == TargetAddressPtr)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00097*/
    /* If development error detection for the module Fls is enabled: the function Fls_Read shall
      check that the read start address (FlsBaseAddress + SourceAddress) lies within the specified
      lower and upper flash address boundaries. If this check fails, the function Fls_Read shall
      reject the read job, raise development error FLS_E_PARAM_ADDRESS and return with E_NOT_OK
    */
    else if ((Std_ReturnType)E_NOT_OK == Fls_CheckValidAddress(ReadStartAddress))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00098*/
    /* If development error detection for the module Fls is enabled: the function Fls_Read shall
      check that the read length is greater than 0 and that the read end address (read start address
      + length) lies within the specified upper flash address boundary. If this check fails, the
      function Fls_Read shall reject the read job, raise the development error FLS_E_PARAM_LENGTH
      and return with E_NOT_OK
    */
    else if ((Length == (Fls_LengthType)0U) ||
             (E_NOT_OK == Fls_CheckValidAddress(ReadStartAddress + (Fls_AddressType)Length - 1U)))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_READ, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00340*/
    /* After initiating a read job, the function Fls_Read shall return with E_OK.*/
    else
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        if (Fls_DrvObj.status == MEMIF_IDLE)
        {
            /* SWS_Fls_00338*/
            /* After initiating a read job, the function Fls_Read shall set the FLS module status to
             * MEMIF_BUSY*/
            Fls_DrvObj.status = MEMIF_BUSY;

            /* SWS_Fls_00339*/
            /* After initiating a read job, the function Fls_Read shall set the FLS module
              job result to MEMIF_JOB_PENDING
            */
            Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
            Fls_DrvObj.jobType       = FLS_JOB_READ;
            /* SWS_Fls_00239*/
            Fls_DrvObj.flashAddr = ReadStartAddress;

            /*  "Reason - The source address needs to stored, for functionality operation. " */
            Fls_DrvObj.ramAddr     = (uint8 *)TargetAddressPtr;
            Fls_DrvObj.length      = Length;
            Fls_DrvObj.transferred = (Fls_LengthType)0U;

            Fls_DrvObj.jobChunkSize = Fls_DrvObj.FlsMaxReadNormalMode;
        }
        else
        {
            (retVal = (Std_ReturnType)E_NOT_OK);
        }
    }
    return retVal;
}

/*
 *  Function Name: Fls_Write
 *
 *  The function Fls_Write shall write one or more complete flash pages to the
 *  flash device.
 *  Design: MCAL-30943, MCAL-30944, MCAL-30945, MCAL-30946, MCAL-30947, MCAL-30948, MCAL-30949
 *  Design: MCAL-30950, MCAL-30951, MCAL-30952, MCAL-30953, MCAL-30954, MCAL-30955
 *
 */
FUNC(Std_ReturnType, FLS_CODE)
Fls_Write(Fls_AddressType TargetAddress, P2VAR(const uint8, AUTOMATIC, FLS_APPL_DATA) SourceAddressPtr,
          Fls_LengthType  Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    /* SWS_Fls_00226*/
    /* The job of the function Fls_Write shall program a flash memory block with data provided
      via SourceAddressPtr starting from FlsBaseAddress + TargetAddress of size Length.
    */
    /* TargetAddress is the offset relative to the FLS base address which is 0x10c00000 for F29H85x
     * device */
    /* The offset should be less than the total flash size (assume 1MB)  */
    /* TargetAddress = TargetAddress & 0xFFFFF; */

    VAR(Fls_AddressType, AUTOMATIC)
    writeStartAddress = (TargetAddress & 0xFFFFFU) + (FLS_BASE_ADDRESS & FLS_BASE_ADDRESS_REQ);

#if (STD_ON == FLS_DEV_ERROR_DETECT)
    /* SWS_Fls_00066*/
    /* If development error detection for the module Fls is enabled: the function Fls_Write shall
      check that the FLS module has been initialized. If this check fails, the function Fls_Write
      shall reject the write request, raise the development error FLS_E_UNINIT and return with
      E_NOT_OK
    */
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00030*/
    /* If development error detection for the module Fls is enabled: the function Fls_Write shall
      check that the FLS module is currently not busy. If this check fails, the function Fls_Write
      shall reject the write request, raise the development error FLS_E_BUSY and return with
      E_NOT_OK
    */
    else if (MEMIF_BUSY == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_BUSY);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00157*/
    /* If development error detection for the module Fls is enabled: the function Fls_Write shall
      check the given data buffer pointer for not being a null pointer. If the data buffer pointer
      is a null pointer, the function Fls_Write shall reject the write request, raise the
      development error FLS_E_PARAM_DATA and return with E_NOT_OK
    */
    else if (NULL_PTR == SourceAddressPtr)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00026*/
    /* SRS_Fls_12159*/
    /* If development error detection for the module Fls is enabled: the function Fls_Write shall
       check that the write start address (FlsBaseAddress + TargetAddress) is aligned to a flash
       page boundary and that it lies within the specified lower and upper flash address boundaries.
       If this check fails, the function Fls_Write shall reject the write request, raise the
       development error FLS_E_PARAM_ADDRESS and return with E_NOT_OK
    */
    else if ((Std_ReturnType)E_NOT_OK == Fls_CheckValidAddress(writeStartAddress))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00027*/
    /* SRS_Fls_12159*/
    /* If development error detection for the module Fls is enabled: the function Fls_Write shall
       check that the write length is greater than 0, that the write end address (write start
       address + length) is aligned to a flash page boundary and that it lies within the specified
       upper flash address boundary. If this check fails, the function Fls_Write shall reject the
       write request, raise the development error FLS_E_PARAM_LENGTH and return with E_NOT_OK
    */
    else if ((Length == (Fls_LengthType)0U) || (E_NOT_OK == Fls_CheckValidAddress(writeStartAddress + Length - 1U)))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00026*/
    /* SWS_Fls_00027*/
    else if ((E_NOT_OK == Fls_CheckWrtAddressAlignment(writeStartAddress)) ||
             (E_NOT_OK == Fls_CheckWrtAddressAlignment(writeStartAddress + (Fls_AddressType)Length)))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_WRITE, FLS_E_PARAM_ALIGNMENT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif /*  #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        if (Fls_DrvObj.status == MEMIF_IDLE)
        {
            /* [SWS_Fls_00333*/
            /* After initiating the write job, Fls_Write shall set the job result to
             * MEMIF_JOB_PENDING*/
            Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;

            /* SWS_Fls_00332*/
            /* After initiating the write job, Fls_Write shall set the FLS module status to
             * MEMIF_BUSY*/
            Fls_DrvObj.status  = MEMIF_BUSY;
            Fls_DrvObj.jobType = FLS_JOB_WRITE;

            /* SWS_Fls_00226*/
            Fls_DrvObj.flashAddr   = writeStartAddress;
            Fls_DrvObj.ramAddr     = (uint8 *)SourceAddressPtr;
            Fls_DrvObj.length      = Length;
            Fls_DrvObj.transferred = (Fls_LengthType)0;

            Fls_DrvObj.jobChunkSize = Fls_DrvObj.FlsMaxWriteNormalMode;
        }
        else
        {
            (retVal = (Std_ReturnType)E_NOT_OK);
        }
    }
    return retVal;
};

/*
 *  Function Name: Fls_Compare
 *  The function Fls_Compare shall compare the contents of an area of flash
 *  memory with that of an application data buffer.
 *  Design: MCAL-30983, MCAL-30984, MCAL-30985, MCAL-30986, MCAL-30987, MCAL-30988, MCAL-30989
 *  Design: MCAL-30990, MCAL-30991, MCAL-30992, MCAL-30993, MCAL-30994, MCAL-30995
 */
#if (FLS_COMPARE_API == STD_ON)
FUNC(Std_ReturnType, FLS_CODE)
Fls_Compare(Fls_AddressType SourceAddress, P2VAR(const uint8, AUTOMATIC, FLS_APPL_DATA) TargetAddressPtr,
            Fls_LengthType  Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    /* SWS_Fls_00244*/
    /* The job of the function Fls_Compare shall compare a continuous flash memory
      block starting from FlsBaseAddress + SourceAddress of size Length with the
      buffer pointed to by TargetAddressPtr
    */
    /* Source is the offset relative to the FLS base address which is 0x10c00000 for F29H85x device
     */
    /* The offset should be less than the total flash size (assume 1MB)  */
    /* SourceAddress = SourceAddress & 0xFFFFF; */

    VAR(Fls_AddressType, AUTOMATIC)
    compareStartAddress = (SourceAddress & 0xFFFFFU) + (FLS_BASE_ADDRESS & FLS_BASE_ADDRESS_REQ);

#if (STD_ON == FLS_DEV_ERROR_DETECT)

    /* SWS_Fls_00152*/
    /* If development error detection for the module Fls is enabled: the function Fls_Compare
      shall check that the driver has been initialized. If this check fails, the function
      Fls_Compare shall reject the compare job, raise the development error FLS_E_UNINIT and return
      with E_NOT_OK
    */
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00153*/
    /* If development error detection for the module Fls is enabled: the function Fls_Compare shall
      check that the driver is currently not busy. If this check fails, the function Fls_Compare
      shall reject the compare job, raise the development error FLS_E_BUSY and return with E_NOT_OK
    */
    else if (MEMIF_BUSY == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_BUSY);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00273*/
    /* If development error detection for the module Fls is enabled: the function Fls_Compare shall
      check the given data buffer pointer for not being a null pointer. If the data buffer pointer
      is a null pointer, the function Fls_Compare shall reject the request, raise the development
      error FLS_E_PARAM_DATA and return with E_NOT_OK
    */
    else if (NULL_PTR == TargetAddressPtr)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_PARAM_DATA);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00150*/
    /* If development error detection is enabled: the function Fls_Compare shall check that
      the compare start address (FlsBaseAddress + SourceAddress) lies within the specified
      lower and upper flash address boundaries. If this check fails, the function Fls_Compare
      shall reject the compare job, raise the development error FLS_E_PARAM_ADDRESS
      and return with E_NOT_OK
    */
    else if (E_NOT_OK == Fls_CheckValidAddress(compareStartAddress))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00151*/
    /* If If development error detection is enabled: the function Fls_Compare shall
      check that the given length is greater than 0 and that the compare end address
      (compare start address + length) lies within the specified upper flash address boundary.
      If this check fails, the function Fls_Compare shall reject the compare job, raise the
      development error FLS_E_PARAM_LENGTH and return with E_NOT_OK
    */
    else if ((Length == 0U) || (E_NOT_OK == Fls_CheckValidAddress(compareStartAddress + Length - 1U)))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_COMPARE, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif /*  #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        if (Fls_DrvObj.status == MEMIF_IDLE)
        {
            /* SWS_Fls_00342*/
            /* After initiating the compare job, the function Fls_Compare shall set the status to
             * MEMIF_BUSY*/
            Fls_DrvObj.status = MEMIF_BUSY;

            /* SWS_Fls_00343*/
            /* After initiating the compare job, Fls_Compare shall set the job result to
             * MEMIF_JOB_PENDING*/
            Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
            Fls_DrvObj.jobType       = FLS_JOB_COMPARE;

            /* SWS_Fls_00244*/
            /* The job of the function Fls_Compare shall compare a continuous flash memory block
             *starting from FlsBaseAddress + SourceAddress of size Length with the buffer
             *pointed to by TargetAddressPtr
             */
            Fls_DrvObj.flashAddr   = compareStartAddress;
            Fls_DrvObj.ramAddr     = (uint8 *)TargetAddressPtr;
            Fls_DrvObj.length      = Length;
            Fls_DrvObj.transferred = (Fls_LengthType)0U;

            Fls_DrvObj.jobChunkSize = Fls_DrvObj.FlsMaxReadNormalMode;
        }
        else
        {
            (retVal = (Std_ReturnType)E_NOT_OK);
        }
    }
    return retVal;
}
#endif

/*
 *  Function Name: Fls_BlankCheck
 *  The function Fls_BlankCheck shall verify, whether a given memory area
 *  has been erased.
 *  Design: MCAL-31000, MCAL-31001, MCAL-31002, MCAL-31003, MCAL-31004, MCAL-31005, MCAL-31006
 *  Design: MCAL-31007, MCAL-31008, MCAL-31009, MCAL-31010, MCAL-31011, MCAL-31012
 */
#if (FLS_BLANK_CHECK_API == STD_ON)
FUNC(Std_ReturnType, FLS_CODE) Fls_BlankCheck(Fls_AddressType TargetAddress, Fls_LengthType Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    /* SWS_Fls_00379*/
    /* The verification job of the function Fls_BlankCheck shall check, that the
      continuous flash memory area starting from FlsBaseAddress + TargetAddress of
      size Length is eras
    */
    /* TargetAddress is the offset relative to the FLS base address which is 0x10c00000 for F29H85x
     * device */
    /* The offset should be less than the total flash size (assume 1MB)  */
    /* TargetAddress = TargetAddress & 0xFFFFF; */

    VAR(Fls_AddressType, AUTOMATIC)
    BlankCheckStartAddress = (TargetAddress & 0xFFFFFU) + (FLS_BASE_ADDRESS & FLS_BASE_ADDRESS_REQ);

#if (STD_ON == FLS_DEV_ERROR_DETECT)

    /* SWS_Fls_00382*/
    /* If development error detection is enabled: the function Fls_BlankCheck shall check that the
      driver has been initialized. If this check fails, the function Fls_BlankCheck shall reject the
      verification request, raise the development error FLS_E_UNINIT and return with E_NOT_OK
    */
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_UNINIT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SRS_BSW_00406*/
    /* If development error detection for the module FLS is enabled: the function Fls_BlankCheck
      shall check that the driver is currently not busy. If this check fails, the function
      Fls_BlankCheck shall reject the verification request, raise the development error FLS_E_BUSY
      and return with E_NOT_OK
    */
    else if (MEMIF_BUSY == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_BUSY);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00380*/
    /* If development error detection for the module FLS is enabled; the function Fls_BlankCheck
      shall check that the verification start address (FlsBaseAddress + TargetAddress) lies within
      the specified lower and upper flash address boundaries. If this check fails, the function
      Fls_BlankCheck shall reject the verification job, raise the development error
      FLS_E_PARAM_ADDRESS and return with E_NOT_OK
    */
    else if (E_NOT_OK == Fls_CheckValidAddress(BlankCheckStartAddress))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_PARAM_ADDRESS);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00381*/
    /* If development error detection for the module FLS is enabled: the function Fls_BlankCheck
      shall check that the given length is greater than 0 and that the verification end address
      (verification start address + length) lies within the specified upper flash address boundary.
      If this check fails, the function Fls_BlankCheck shall reject the verification job, raise the
      development error FLS_E_PARAM_LENGTH and return with E_NOT_OK
    */
    else if ((Length == 0U) || (E_NOT_OK == Fls_CheckValidAddress(BlankCheckStartAddress + Length - 1U)))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_PARAM_LENGTH);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((E_NOT_OK == Fls_CheckWrtAddressAlignment(BlankCheckStartAddress)) ||
             (E_NOT_OK == Fls_CheckWrtAddressAlignment(BlankCheckStartAddress + (Fls_AddressType)Length)))
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_BLANK_CHECK, FLS_E_PARAM_ALIGNMENT);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* SWS_Fls_00377*/
    /* After initiating the verification job, the function Fls_BlankCheck shall return with E_OK*/
    else
#endif /*  #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        if (Fls_DrvObj.status == MEMIF_IDLE)
        {
            /* SWS_Fls_00375*/
            /* After initiating the verification job, the function Fls_BlankCheck shall
              set the FLS module status to MEMIF_BUSY
            */
            Fls_DrvObj.status = MEMIF_BUSY;
            /* SWS_Fls_00376*/
            /* After initiating the verification job, the function Fls_BlankCheck shall
              set the FLS module job result to MEMIF_JOB_PENDING
            */
            Fls_DrvObj.jobResultType = MEMIF_JOB_PENDING;
            Fls_DrvObj.jobType       = FLS_JOB_BLANKCHECK;

            /* SWS_Fls_00379*/
            /* The verification job of the function Fls_BlankCheck shall check, that the
              continuous flash memory area starting from FlsBaseAddress + TargetAddress of
              size Length is eras
            */
            Fls_DrvObj.flashAddr   = BlankCheckStartAddress;
            Fls_DrvObj.ramAddr     = NULL_PTR;
            Fls_DrvObj.length      = Length;
            Fls_DrvObj.transferred = (Fls_LengthType)0U;

            Fls_DrvObj.jobChunkSize = Fls_DrvObj.FlsMaxReadNormalMode;
        }
        else
        {
            (retVal = (Std_ReturnType)E_NOT_OK);
        }
    }
    return retVal;
}
#endif /*  #if (STD_ON == FLS_BLANK_CHECK_API) */

/*
 *  Function Name: Fls_GetStatus
 *  The function Fls_GetStatus shall return the FLS module state synchronously
 *
 *  This function may be called before the module has been initialized in which case it shall
 *  return MEMIF_UNINIT.
 *  Design: MCAL-30964, MCAL-30965
 *  SRS_Fls_12138
 */
#if (STD_ON == FLS_GET_STATUS_API)
FUNC(MemIf_StatusType, FLS_CODE) Fls_GetStatus(void)
{
    return Fls_DrvObj.status;
}
#endif /*  #if (STD_ON == FLS_GET_STATUS_API) */

/*
 *  Function Name: Fls_GetJobResult
 *  The function Fls_GetJobResult shall return the result of the last job synchronously
 *  Design: MCAL-30966, MCAL-30967, MCAL-30968, MCAL-30969
 */
#if (FLS_GET_JOB_RESULT_API == STD_ON)
FUNC(MemIf_JobResultType, FLS_CODE) Fls_GetJobResult(void)
{
    VAR(MemIf_JobResultType, AUTOMATIC) jobResult = MEMIF_JOB_FAILED;
#if (STD_ON == FLS_DEV_ERROR_DETECT)
    /* SWS_Fls_00358*/
    /* If development error detection for the module Fls is enabled: the function
      Fls_GetJobResult shall check that the FLS module has been initialized.
      If this check fails, the function Fls_GetJobResult shall raise the development
      error FLS_E_UNINIT and return with MEMIF_JOB_FAILED
    */
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_GET_JOB_RESULT, FLS_E_UNINIT);
    }
    else
#endif /*  #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        jobResult = Fls_DrvObj.jobResultType;
    }
    return jobResult;
}
#endif /*  #if (STD_ON == FLS_GET_JOB_RESULT_API) */

/*
 *  Function Name: Fls_GetVersionInfo
 *  The function Returns the version information of this module.
 *  Design: MCAL-30999
 */
#if (STD_ON == FLS_VERSION_INFO_API)
FUNC(Std_ReturnType, FLS_CODE)
Fls_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA) versioninfo)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
/* SWS_Fls_00363*/
/* If development error detection for the module Fls is enabled: the function Fls_GetVersionInfo
  shall raise the development error FLS_E_PARAM_POINTER if the argument is a NULL pointer
  and return without any action.
*/
#if (STD_ON == FLS_DEV_ERROR_DETECT)

    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_GET_VERSION_INFO, FLS_E_PARAM_POINTER);
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif /*  #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        versioninfo->vendorID         = FLS_VENDOR_ID;
        versioninfo->moduleID         = FLS_MODULE_ID;
        versioninfo->sw_major_version = (uint8)FLS_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)FLS_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)FLS_SW_PATCH_VERSION;
    }
    return retVal;
}
#endif /*  #if (STD_ON == FLS_VERSION_INFO_API) */

/*
 *  Function Name: Fls_MainFunction
 *
 *  The function Fls_MainFunction shall perform the processing
 *	of the flash read, write, erase and compare jobs
 *  Design: MCAL-31013, MCAL-31014, MCAL-31015, MCAL-31016, MCAL-31017, MCAL-31018, MCAL-31019
 *  Design: MCAL-31020, MCAL-31020, MCAL-31022, MCAL-31023, MCAL-31024, MCAL-31025, MCAL-31026
 *  Design: MCAL-31027, MCAL-31028, MCAL-31029, MCAL-31030, MCAL-31031, MCAL-31032, MCAL-31033
 *  Design: MCAL-31034, MCAL-31035, MCAL-31036, MCAL-31037, MCAL-31040, MCAL-31041, MCAL-31042
 *  SWS_Fls_00037, SWS_Fls_00038
 */
FUNC(void, FLS_CODE) Fls_MainFunction(void)
{
#if (STD_ON == FLS_DEV_ERROR_DETECT)
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_MAIN_FUNCTION, FLS_E_UNINIT);
    }
    else
#endif /*  #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        if (Fls_DrvObj.jobResultType == MEMIF_JOB_PENDING)
        {
            if (Fls_DrvObj.jobType != FLS_JOB_NONE)
            {
                Fls_processJobs(Fls_DrvObj.jobType);
            }
        }
        /* SWS_Fls_00147*/
        else if (Fls_DrvObj.jobResultType == MEMIF_JOB_CANCELED)
        {
            if (Fls_DrvObj.Fls_JobErrorNotification != NULL)
            {
                Fls_DrvObj.Fls_JobErrorNotification();
            }
        }
        else
        {
            if (Fls_DrvObj.Fls_JobEndNotification != NULL_PTR)
            {
                /* If not pending job, then return end notification */
                Fls_DrvObj.Fls_JobEndNotification();
            }
        }
    }
}

/*
 *  Function Name: Fls_Cancel
 *
 *  The function Fls_Cancel shall cancel an ongoing flash read,
 *  write, erase or compare job synchronously so that directly
 *  after returning from this function a new job can be started
 *
 *  SRS_Fls_12137
 */
#if (FLS_CANCEL_API == STD_ON)
FUNC(void, FLS_CODE) Fls_Cancel(void)
{
#if (STD_ON == FLS_DEV_ERROR_DETECT)
    /* SWS_Fls_00356*/
    /* If development error detection for the module Fls is enabled: the function Fls_Cancel shall
      check that the FLS module has been initialized. If this check fails, the function Fls_Cancel
      shall raise the development error FLS_E_UNINIT and return
    */
    if (MEMIF_UNINIT == Fls_DrvObj.status)
    {
        (void)Det_ReportError(FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SID_CANCEL, FLS_E_UNINIT);
    }
    else
#endif /*  #if (STD_ON == FLS_DEV_ERROR_DETECT) */
    {
        /*  Reset internal job processing variables (like address, length and data pointer) */
        Fls_DrvObj.flashAddr   = 0U;
        Fls_DrvObj.ramAddr     = NULL_PTR;
        Fls_DrvObj.length      = 0U;
        Fls_DrvObj.transferred = (Fls_LengthType)0U;

        /* SWS_Fls_00336*/
        /* The function Fls_Cancel shall set the FLS module state to MEMIF_IDLE*/
        Fls_DrvObj.status  = MEMIF_IDLE;
        Fls_DrvObj.jobType = FLS_JOB_NONE;

        /* SWS_Fls_00033*/
        /* The function Fls_Cancel shall set the job result to MEMIF_JOB_CANCELED if the job result
          currently has the value MEMIF_JOB_PENDING. Otherwise the function Fls_Cancel shall leave
          the job result unchanged
        */
        if (Fls_DrvObj.jobResultType == MEMIF_JOB_PENDING)
        {
            Fls_DrvObj.jobResultType = MEMIF_JOB_CANCELED;
        }
        /* SWS_Fls_00147*/
        /* If configured, the function Fls_Cancel shall call the error notification function to
          inform the caller about the cancellation of a job*/
        if (Fls_DrvObj.Fls_JobErrorNotification != NULL_PTR)
        {
            Fls_DrvObj.Fls_JobErrorNotification();
        }
    }
};
#endif

/*
 *  Function Name: Fls_SetEraseType
 *
 *  The function Fls_SetEraseType sets the parameters like data size,
 *  erase type(sector/block/chip),typeoferase for Fls_DrvObj,
 *  which are required in application, based on the erase type parameter
 *  passed to this function while calling from Application.
 *  This function is called from application based on the macros enabled in
 *  application itself.
 *  Implementation of this function is done to allow user to select one or more
 *  erase types based on the requirement.
 */
FUNC(uint32, FLS_CODE) Fls_SetEraseType(Fls_EraseType erasetype)
{
    switch (erasetype)
    {
        case FLS_SECTOR_ERASE:
            Fls_DrvObj.typeoferase = FLS_SECTOR_ERASE;
            sector_or_banksize     = FLS_SECTOR_SIZE;
            break;
        case FLS_BANK_ERASE:
            Fls_DrvObj.typeoferase = FLS_BANK_ERASE;
            sector_or_banksize     = FLS_TOTAL_SIZE / FLS_NUM_BANKS;
            break;
        default:
            Fls_DrvObj.typeoferase = FLS_SECTOR_ERASE;
            sector_or_banksize     = FLS_SECTOR_SIZE;
            break;
    }
    return sector_or_banksize;
}

/*
 *  Function Name: Fls_SetMode
 *
 *  The function Fls_SetMode shall set the FLS module’s
 *  operation mode to the given “Mode” parameter.
 *  Design: MCAL-30996, MCAL-30997, MCAL-30998
 *  SRS_Fls_13302
 */
#if (STD_ON == FLS_SETMODE_API)
FUNC(void, FLS_CODE) Fls_SetMode(MemIf_ModeType Mode)
{
    return;
}
#endif

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#if (STD_ON == FLS_DEV_ERROR_DETECT)

/*
 * Check Flash bank ranges for a valid address
 */
static Std_ReturnType Fls_CheckValidAddress(Fls_AddressType SourceAddress)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal     = (Std_ReturnType)E_NOT_OK;
    VAR(Fls_AddressType, AUTOMATIC) startAddr = (FLS_BASE_ADDRESS & FLS_BASE_ADDRESS_REQ);

    if ((SourceAddress == startAddr) || (SourceAddress < (startAddr + (Fls_AddressType)FLS_TOTAL_SIZE)))
    {
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}

/*
 * Checks sector alignment for a valid address
 */
static Std_ReturnType Fls_CheckSectorAlignment(Fls_AddressType SourceAddress)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    /*flash address checks */

    if ((SourceAddress % ((Fls_AddressType)FLS_SECTOR_SIZE)) == 0x0U)
    {
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}

/*
 * Check if address for write/blank-check/compare is aligned with maximum operatable size  (main and
 * non-main range)
 */
static Std_ReturnType Fls_CheckWrtAddressAlignment(Fls_AddressType SourceAddress)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    if ((SourceAddress % FLS_WRITE_ADDRESS_ALIGNMENT) == (uint32)0U) /* aligned to 8 bytes*/
    {
        retVal = E_OK;
    }
    else
    {
        retVal = E_NOT_OK;
    }
    return retVal;
}
#endif /* #if (STD_ON == FLS_DEV_ERROR_DETECT)*/

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Fls.c
 *********************************************************************************************************************/
