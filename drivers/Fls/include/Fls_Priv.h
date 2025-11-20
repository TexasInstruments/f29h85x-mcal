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
 *  \file       Fls_Priv.h
 *  Generator:  None
 *
 *  \brief Description:  This file contains common declarations and macros used across all the FLS
 *MCAL driver files.
 *********************************************************************************************************************/

#ifndef FLS_PRIV_H_
#define FLS_PRIV_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "SchM_Fls.h"
#include "Std_Types.h"
#include "hw_types.h" /*defines HWREG, float etc*/

#include "Fls.h"
#include "Fls_Cbk.h"
#include "Fls_Ac.h"
#include "Mcal_Lib.h"

#include "Det.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** The retVal definitions */
#define E_COMPARE_MISMATCH    (2U)
#define E_BLANKCHECK_MISMATCH (3U)

/** FLS Stage of Erase. */
#define FLS_S_EDEFAULT        (0U)
#define FLS_S_ERASE_PRECHECK  (1U)
#define FLS_DO_SECTOR_UNLOCK  (2U)
#define FLS_DO_ERASE_JOB      (3U)
#define FLS_S_ERASE_POSTCHECK (4U)

#define FLS_ERASE_FSM_READY_CHECK  (0U) /** fsm ready ?*/
#define FLS_ERASE_FSM_ISSUE_CMD    (1U)
#define FLS_ERASE_FSM_STATUS_CHECK (2U) /** fsm  status*/
#define FLS_STATUS_CLEAR_CHECK     (3U) /** clear status cmd */
#define FLS_ERASE_CMD_CHECK        (4U)

#define FLS_WRITE_FSM_READY_CHECK  (0U) /** fsm ready ?*/
#define FLS_WRITE_FSM_ISSUE_CMD    (1U)
#define FLS_WRITE_FSM_STATUS_CHECK (2U) /** fsm  status*/
#define FLS_WRITE_CMD_CHECK        (4U)

/** FLS Stage of Write */
#define FLS_S_WDEFAULT        (0U)
#define FLS_S_WRITE_PRECHECK  (1U)
#define FLS_DO_WRITE_JOB      (3U)
#define FLS_S_WRITE_POSTCHECK (4U)

#define FLS_CONV_TO_MHZ (1000000U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/** \brief ENUM for job type names */
typedef enum
{
    FLS_JOB_NONE       = 0U, /*!< \brief  Job type none */
    FLS_JOB_COMPARE    = 1U, /*!< \brief  Job type compare */
    FLS_JOB_ERASE      = 2U, /*!< \brief  Job type erase */
    FLS_JOB_READ       = 3U, /*!< \brief  Job type read */
    FLS_JOB_WRITE      = 4U, /*!< \brief  Job type write */
    FLS_JOB_BLANKCHECK = 5U  /*!< \brief  Job type blank check */
} Fls_JobType;

/**
 * \brief FLS Driver Object, global information used by module.
 */
typedef struct
{
    Fls_JobEndNotifyType   Fls_JobEndNotification;
    /** \brief Mapped to the job end notification routine provided by some upper layer
     *      module, typically the Fee module. */
    Fls_JobErrorNotifyType Fls_JobErrorNotification;
    /** \brief Mapped to the job error notification routine provided by some upper layer
     *      module, typically the Fee module. */
    uint32                 FlsMaxReadFastMode;
    /** \brief The maximum number of bytes to read or compare in one cycle of the
     *      flash driver's job processing function in Fast mode. */
    uint32                 FlsMaxWriteFastMode;
    /** \brief The maximum number of bytes to write in one cycle of the
     *      flash driver's job processing function in Fast mode. */
    uint32                 FlsMaxReadNormalMode;
    /** \brief The maximum number of bytes to read or compare in one cycle of the
     *      flash driver's job processing function in normal mode. */
    uint32                 FlsMaxWriteNormalMode;
    /** \brief The maximum number of bytes to write in one cycle of the
     *      flash driver's job processing function in normal mode. */
    Fls_SectorType         sectorList[FLS_NUMBER_OF_SECTOR_CFG];
    /** \brief The maximum number of bytes to write in one cycle of the flash driver's job
     *       processing function in normal mode. Using Fls Info Structure instead of this for now.
     */
    MemIf_StatusType       status;
    /** \brief Current Module Status update variable */
    MemIf_JobResultType    jobResultType;
    /** \brief Current Job Result update variable */
    Fls_JobType            jobType;
    /** \brief Current running job type */
    Fls_AddressType        flashAddr;
    /** \brief Flash Address for the current job */
    uint8                 *ramAddr;
    /** \brief Ram Address pointer for the current job */
    Fls_LengthType         length;
    /**  Data transfer length for the current job */
    MemIf_ModeType         mode;
    /** \brief Module mode setup for current job - SLOW for now */
    uint32                 jobChunkSize;
    /** \brief Length of Data to be transfer in current call cycle */
    Fls_LengthType         transferred;
    /** \brief Flash Post Blank Check Address*/
    uint32                 postBlankCheckFlashaddr;
    /** \brief Flash Previous Address*/
    uint32                 prevFlashaddr;
    /** \brief Size of Data has been transferred */
    Fls_EraseType          typeoferase;
    /** \brief To select the type of erase (sector erase/ block erase/ bulk erase) */
} Fls_DriverObjType;

/** \brief ENUM for Internal State type names */
typedef enum
{
    FLS_INTERNAL_JOB_WAIT  = 0U, /*!< \brief  Job state wait */
    FLS_INTERNAL_JOB_FAIL  = 1U, /*!< \brief  Job state fail */
    FLS_INTERNAL_JOB_DONE  = 2U, /*!< \brief  Job state done */
    FLS_INTERNAL_JOB_READY = 3U, /*!< \brief  Job state ready */
    FLS_INTERNAL_JOB_BUSY  = 4U  /*!< \brief  Job state busy */
} Fls_InternalStateType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/**
 * \brief FLS Driver Object instance
 */
extern Fls_DriverObjType Fls_DrvObj;

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/** \brief This function invoke Fls_F29Compare,Fls_F29BankErase,Fls_F29SectorErase,Fls_F29ChipErase,
 *  Fls_F29Read,Fls_F29Write and Fls_F29BlankCheck function. it will perform any one
 *  function based on job type
 * \param[in] job job type to perform operation
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern void Fls_processJobs(Fls_JobType job);

/** \brief Reset driver parameters during initialize time
 * \param[in] drvObj Input configuration parameters
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern void Fls_resetDrvObj(Fls_DriverObjType *drvObj);

/** \brief Configuration parameters are copied to drvObj,this function included with Fls_init
 * \param[in] drvObj configuration parameters are copied to this object
 * \param[in] cfgPtr Input configuration parameters
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern void Fls_copyConfig(Fls_DriverObjType *drvObj, const Fls_ConfigType *cfgPtr);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /** #ifndef FLS_PRIV_H_ */

/*********************************************************************************************************************
 *  End of File: Fls_Priv.h
 *********************************************************************************************************************/
