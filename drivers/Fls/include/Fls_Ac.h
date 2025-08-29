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
 *  \file       Fls_Ac.h
 *  Generator:  None
 *
 *  \brief Description:  This file contains interface header for Fls MCAL driver
 *********************************************************************************************************************/
#ifndef FLS_AC_H_
#define FLS_AC_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "hw_types.h"
#include "Mcal_Lib.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
/** #define ATTRIBUTE_PACKED    __attribute__((packed))*/

#ifndef TRUE
#define TRUE 1U
#endif

#ifndef FALSE
#define FALSE 0U
#endif

#if defined(_LITTLE_ENDIAN)
#ifndef LOW_BYTE_FIRST
#define CPU_BYTE_ORDER LOW_BYTE_FIRST
#endif
#else
#ifndef HIGH_BYTE_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST
#endif
#endif

/**   SSU registers*/
/** \brief Base address of SSU module */
#define FLS_SSUGEN_BASE (uint32)(0x30080000U)
/** \brief Flash Controller Semaphore Request Register*/
#define FLS_SSU_O_FLSEMREQ (uint32)(0x224U)
/** \brief Flash Controller Semaphore Status Register*/
#define FLS_SSU_O_FLSEMSTAT (uint32)(0x220U)
/** \brief Flash Controller Semaphore Clear Register*/
#define FLS_SSU_O_FLSEMCLR (uint32)(0x228U)
/** \brief Semaphore CPU owner mask*/
#define FLS_SSU_FLSEMSTAT_CPU_M (uint32)(0x7000U)
/** \brief Semaphore CPU owner shift bit*/
#define FLS_SSU_FLSEMSTAT_CPU_S 12U
/** \brief Assigned Flag bit*/
#define FLS_SSU_FLSEMSTAT_ASSIGNED (uint32)(0x80000000U)
/** \brief Match status bit */
#define FLS_SSU_FLSEMSTAT_MATCH (uint32)(0x40000000U)

/** The following are defines for the bit fields in the BEPROT_BANK register*/
/** \brief Bank Erase Protection Bank Register*/
#define FLS_SSU_O_BEPROT_BANK (uint32)(0x200U)
/** \brief Bank Erase Status Register*/
#define FLS_SSU_O_BEPROT_STAT (uint32)(0x204U)
/** \brief Bank Erase Bank ID mask shift bit*/
#define FLS_SSU_BEPROT_BANK_BANKID_S 0U
/** \brief Bank Erase Bank ID mask*/
#define FLS_SSU_BEPROT_BANK_BANKID_M 0x7U
/** \brief Bank Erase Bank FLC ID shift bit*/
#define FLS_SSU_BEPROT_BANK_FLCID_S 3U
/** \brief Bank Erase Bank FLC ID mask bit*/
#define FLS_SSU_BEPROT_BANK_FLCID_M 0x18U

/** FRI register offsets and bit fields*/
/** \brief flash command register base address*/
#define FLS_FLASH_FLC1_CMD_REGS_BASE (uint32)(0x30100000U)
/** \brief Flash control register base address*/
#define FLS_FRI1_CTL_BASE (uint32)(0x301D0000U)
/** \brief Analog sub system base address*/
#define FLS_ANALOGSUBSYS_BASE (uint32)(0x30182000U)
/** \brief Flash Read Control Register*/
#define FLS_FRI_O_FRDCNTL (uint32)(0x10U)
/** \brief Flash Read Interface 1 Control Register*/
#define FLS_FRI_O_1_INTF_CTRL (uint32)(0x30U)
/** \brief Read Wait state shift bit*/
#define FLS_FRI_FRDCNTL_RWAIT_S (uint32)(8U)
/** \brief Read Wait state mask bit*/
#define FLS_FRI_FRDCNTL_RWAIT_M (uint32)(0xF00U)
/** \brief Flash delay configuration*/
#define FLS_FLASH_DELAY_CONFIG \
    __asm(" NOP #8");          \
    __asm(" NOP #8");          \
    __asm(" NOP #4");

/**  FMC memory map defines */
// #if defined (_F29H85x_)
/** \brief Flash read interface base address*/
#define FLS_FLASH_READINTERFACE_BASE (uint32)0x301D0000U
/** \brief Flash command  interface base address*/
#define FLS_FLASH_FAPI_FLASHNW_FC1_BASE (uint32)0x30100000U
// #endif
/**  \brief  flash prefetch enable */
#define FLS_FLASH_PREFETCH_ENABLE 0x1U
/**  \brief  flash prefetch disable */
#define FLS_FLASH_PREFETCH_DISABLE 0x0U
/**  \brief  flash data cache enable */
#define FLS_FLASH_DATACACHE_ENABLE 0x2U
/**  \brief  flash data cache disable */
#define FLS_FLASH_DATACACHE_DISABLE 0x0U
/**  \brief  flash code cache enable */
#define FLS_FLASH_CODECACHE_ENABLE 0x4U
/**  \brief  flash code cache disable */
#define FLS_FLASH_CODECACHE_DISABLE 0x0U
/**  \brief  flash data read enable */
#define FLS_FLASH_DATAPREREAD_ENABLE 0x8U
/**  \brief  flash data read disable */
#define FLS_FLASH_DATAPREREAD_DISABLE 0x0U

/** \brief Macro to define the offset between options for different FRIs.
 *  For example, FRI_O_2_INTF_CTRL - FRI_O_1_INTF_CTRL = 0x10U.
 */
#define FLS_FRI_REG_STEP (uint8)(0x10U)

/**  \brief  flash trim commit register offset */
#define FLS_ASYSCTL_O_FLASHTRIMCOMMIT 0x90U
/**  \brief  flash trim commit read register offset */
#define FLS_ASYSCTL_FLC1TRIMCOMMITREAD 0x4U
/**  \brief  flash trim commit other register offset */
#define FLS_ASYSCTL_FLC1TRIMCOMMITOTHER 0x8U

/**  \brief  IP Revision Register */
#define FLS_FLASH_O_REVISION 0x0U
/**  \brief  Flash Read Control Register */
#define FLS_FLASH_O_FRDCNTL 0x10U
/**  \brief  Flash Read Clock Control Register */
#define FLS_FLASH_O_FLCLKCTL 0x20U

/**  \brief  KDIV value of MCLK divider shift bit*/
#define FLS_FLASH_FLCLKCTL_KDIV_S 0U
/**  \brief  KDIV value of MCLK divider mask bit*/
#define FLS_FLASH_FLCLKCTL_KDIV_M 0xFU

/**  \brief  Command Execute Register */
#define FLS_FLASH_NW_O_CMDEXEC 0x100U
/**  \brief  Command Type Register */
#define FLS_FLASH_NW_O_CMDTYPE 0x104U
/**  \brief  Command Control Register */
#define FLS_FLASH_NW_O_CMDCTL 0x108U
/**  \brief  Command Address Register */
#define FLS_FLASH_NW_O_CMDADDR 0x120U
/**  \brief  Command Program Byte Enable Register */
#define FLS_FLASH_NW_O_CMDBYTEN 0x124U
/**  \brief  Command Data Index Register */
#define FLS_FLASH_NW_O_CMDDATAINDEX 0x12CU
/**  \brief  Command Data Register 0  */
#define FLS_FLASH_NW_O_CMDDATA0 0x130U
/**  \brief  Command Write Erase Protect A Register */
#define FLS_FLASH_NW_O_CMDWEPROTA 0x1D0U
/**  \brief  Command Write Erase Protect B Register */
#define FLS_FLASH_NW_O_CMDWEPROTB 0x1D4U
/**  \brief  Command Write Erase Protect Non-Main */
#define FLS_FLASH_NW_O_CMDWEPROTNM 0x210U
/**  \brief  Command Configuration Register */
#define FLS_FLASH_NW_O_CFGCMD 0x3B0U
/**  \brief  Command Status Register */
#define FLS_FLASH_NW_O_STATCMD 0x3D0U

/**  \brief  Flash command type shift bit*/
#define FLS_FLASH_NW_CMDTYPE_CMD_S 0U
/**  \brief  Flash command type mask bit*/
#define FLS_FLASH_NW_CMDTYPE_CMD_M 0x7U

/**  \brief  Configure for sector erase: Command is erase (2), Size is sector (4) */
#define FLS_FLASH_NW_CMDTYPE_SECTOR_ERASE 0x42U
/**  \brief  Configure for Bank erase: Command is erase (2), Size is Bank (5)*/
#define FLS_FLASH_NW_CMDTYPE_BANK_ERASE 0x52U
/**  \brief  Configure for 1*128 word program: Command is program (1), Size is ONEWORD (0)*/
#define FLS_FLASH_NW_CMDTYPE_PROG_ONEWD 0x01U

/**  \brief  Flash CMDCTL AutoEccgenration mask bit*/
#define FLS_FLASH_NW_CMDCTL_ECCGENOVR (uint32)(0x20000U)
/**  \brief  Flash CMDCTL AutoEccgenration shift bit*/
#define FLS_FLASH_NW_CMDCTL_ECCGENOVR_S 17U
/**  \brief  Flash CMDCTL Invalid data verify mask bit*/
#define FLS_FLASH_NW_CMDCTL_DATAVEREN (uint32)(0x200000U)
/**  \brief  Flash CMDCTL Invalid data verify shift bit*/
#define FLS_FLASH_NW_CMDCTL_DATAVEREN_S 21U

/**  \brief  Flash CFGCMD register wait state shift bit*/
#define FLS_FLASH_NW_CFGCMD_WAITSTATE_S 0U
/**  \brief  Flash CFGCMD register wait state mask bit*/
#define FLS_FLASH_NW_CFGCMD_WAITSTATE_M 0xFU

/**  \brief  Flash CMDBYTEN register value shift bit*/
#define FLS_FLASH_NW_CMDBYTEN_VAL_S 0U
/**  \brief  Flash CMDBYTEN register value mask bit*/
#define FLS_FLASH_NW_CMDBYTEN_VAL_M 0xFFU
/**  \brief  Flash CMDBYTEN register ecc value shift bit*/
#define FLS_FLASH_NW_CMDBYTEN_ECC0VAL_S 16U
/**  \brief  Flash CMDBYTEN register ecc value mask bit*/
#define FLS_FLASH_NW_CMDBYTEN_ECC0VAL_M (uint32)(0x10000U)
/**  \brief  Flash CMDBYTEN register ecc value shift bit*/
#define FLS_FLASH_NW_CMDBYTEN_ECC1VAL_S 17U
/**  \brief  Flash CMDBYTEN register ecc value mask bit*/
#define FLS_FLASH_NW_CMDBYTEN_ECC1VAL_M (uint32)(0x20000U)

/**  \brief  Command WriteErase Protect Non-Main register shift bits*/
#define FLS_FLASH_NW_CMDWEPROTNM_VAL_S 0U
/**  \brief  Command WriteErase Protect Non-Main register mask bits*/
#define FLS_FLASH_NW_CMDWEPROTNM_VAL_M 1U
/**  \brief  Readback val to protect non-main region sector 0 erase*/
#define FLS_FLASH_NW_CMDWEPROTNM_READBACK_VAL 1U

/*  \brief STATCMD register command done bit*/
#define FLS_FLASH_NW_STATCMD_CMDDONE 0x1U
/*  \brief STATCMD register command pass bit*/
#define FLS_FLASH_NW_STATCMD_CMDPASS 0x2U
/*  \brief STATCMD register command in progress bit*/
#define FLS_FLASH_NW_STATCMD_CMDINPROGRESS 0x4U
/*  \brief STATCMD register command write protect voilation bit*/
#define FLS_FLASH_NW_STATCMD_FAILWEPROT 0x10U
/*  \brief STATCMD register command failed due to verify error bit*/
#define FLS_FLASH_NW_STATCMD_FAILVERIFY 0x20U
/*  \brief STATCMD register command failed due to error other than write/erase protect violation or
 * verify bit*/
#define FLS_FLASH_NW_STATCMD_FAILMISC 0x1000U
/*  \brief STATCMD register command failed due to the use of an illegal address bit*/
#define FLS_FLASH_NW_STATCMD_FAILILLADDR 0x40U
/*  \brief STATCMD register command failed because a bank has been set to a mode other than READ
 * bit*/
#define FLS_FLASH_NW_STATCMD_FAILMODE 0x80U
/*  \brief STATCMD register program command failed because an attempt was made to program a stored
 * bit*/
#define FLS_FLASH_NW_STATCMD_FAILINVDATA 0x100U

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/*typedef unsigned char      boolean;*/
/** \brief Flash status */
typedef uint32 Fls_FapiFlashStatus;

typedef struct Fls_FlashStatusWordTag
{
    uint32 au32StatusWord[4];
} Fls_FlashStatusWordType;

/** \brief This contains all the possible Flash State Machine commands */
typedef enum Fls_FlashStateCmdTag
{
    FLS_FAPI_PROGRAMDATA = 2U, /*!< \brief Issue program data command to FSM */
    FLS_FAPI_ERASESECTOR = 6U, /*!< \brief Issue erase sector command to FSM */
    FLS_FAPI_ERASEBANK   = 8U, /*!< \brief Issue erase bank command to FSM */
    FLS_FAPI_CLEARSTATUS = 16U /*!< \brief Issue clear status command to FSM */
} Fls_FlashStateCmdType;

/** \brief Enumeration to identify if read is for single or multiple value */
typedef enum Fls_FapiRegionValueTag
{
    FLS_FAPI_SINGLEVALUE      = 0U, /*!< \brief Read single value */
    FLS_FAPI_MULTIPLEVALUE    = 1U, /*!< \brief Read multiple value */
    FLS_FAPI_MULTIPLEVALUEECC = 2U  /*!< \brief Read multiple ecc value */
} Fls_FapiRegionValueType;

/** \brief Enumeration of FRI register addresses for use with Flash_configFRI() */
typedef enum Fls_FlashFRITag
{
    FLS_FLASH_FRI1 = (uint8)(0U), /*!< \brief Flash read interface(FRI) 1 */
    FLS_FLASH_FRI2 = (uint8)(1U), /*!< \brief Flash read interface(FRI) 2 */
    FLS_FLASH_FRI3 = (uint8)(2U), /*!< \brief Flash read interface(FRI) 3 */
    FLS_FLASH_FRI4 = (uint8)(3U)  /*!< \brief Flash read interface(FRI) 4 */
} Fls_FlashFRIType;

#endif
/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/* Flash State Machine commands */
/** \brief This api will read STATCMD status register value from the Flash Wrapper
 *
 * \pre None
 * \post None
 * \return Returns the STATCMD status register value
 * \retval STATCMD status register value
 *
 *********************************************************************************************************************/
extern FUNC(Fls_FapiFlashStatus, FLS_CODE) Fls_Fapi_getFsmStatus(void);

/** \brief Returns the status of the Flash State Machine
 *
 * \pre None
 * \post None
 * \return Returns the status of the Flash State Machine
 * \retval Fapi_Status_FsmBusy: FSM is busy and cannot accept new command except for suspend
 *commands
 * \retval Fapi_Status_FsmReady: FSM is ready to accept new command
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE) Fls_Fapi_checkFsmForReady(void);

/** \brief Configures Write(program)/Erase protection for the sectors.
 * \param[in] reg_address
 * \param[in] value
 * \pre None
 * \post None
 * \return Configures write/ erase protection for sectors and return success
 * \retval Fapi_Status_Success: Success
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE) Fls_Fapi_setupBankSectorEnable(uint32 reg_address, uint32 value);

/** \brief Issues an erase sector command to the Flash State Machine for the user-provided sector
 *address.
 * \param[in] oCommand Command to issue to the FSM. Use Fapi_EraseSector.
 * \param[in] pu32StartAddress Flash sector address for erase operation
 * \pre None
 * \post None
 * \return Returns the status of command
 * \retval Fapi_Status_Success: Success
 * \retval Fapi_Status_FsmBusy: FSM busy
 * \retval Fapi_Error_FeatureNotAvailable:  User requested a command that is not supported
 * \retval Fapi_Error_FlashRegsNotWritable:  Flash register write failed
 * \retval Fapi_Error_InvalidAddress:  User provided an invalid address
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_issueAsyncCommandWithAddress(Fls_FlashStateCmdType oCommand, uint32 *pu32StartAddress);

/** \brief Issues a command (Clear Status) to FSM
 * \param[in] oCommand Command to issue to the FSM. Use Fapi_EraseSector.
 * \pre None
 * \post None
 * \return clears the STATCMD register of flash state machine
 * \retval Fapi_Status_Success: Success
 * \retval Fapi_Status_FsmBusy: FSM busy
 * \retval Fapi_Error_FeatureNotAvailable:  User requested a command that is not supported
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE) Fls_Fapi_issueAsyncCommand(Fls_FlashStateCmdType oCommand);

/** \brief Issues a bank erase command to the Flash State Machine along with a user-provided sector
 *mask
 * \param[in] pu32StartAddress Flash bank address for bank erase operation
 * \pre None
 * \post None
 * \return returns success or failure status
 * \retval Fapi_Status_Success: Success
 * \retval Fapi_Error_InvalidHclkValue: System clock does not match specified wait value
 * \retval Fapi_Error_FlashRegsNotWritable:  Flash register write failed
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE) Fls_Fapi_issueBankEraseCommand(uint32 *pu32StartAddress);

/** \brief Initializes the API for first use or frequency change
 * \param[in] u32HclkFrequency System clock frequency in MHz
 * \pre None
 * \post None
 * \return returns success or failure status
 * \retval Fapi_Status_Success: Success
 * \retval Fapi_Status_FsmBusy: FSM busy
 * \retval Fapi_Error_FlashRegsNotWritable:  Flash register write failed
 * \retval Fapi_Error_InvalidAddress:  User provided an invalid address
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE) Fls_Fapi_initializeAPI(uint32 u32HclkFrequency);

/** \brief Verifies region specified is erased value.
 * \param[in] pu32StartAddress Start address for region to blank check
 * \param[in] u32Length Length of region in 32-bit words to blank check
 * \param[out] poFlashStatusWord Returns the status of the operation if result is not
 *Fapi_Status_Success au32StatusWord[0] Address of first non-blank location au32StatusWord[1] Data
 *read at first non-blank location au32StatusWord[2] Value of compare data (always 0xFFFFFFFF)
 *             au32StatusWord[3] NA
 * \pre None
 * \post None
 * \return returns success or failure status
 * \retval Fapi_Status_Success: Success
 * \retval Fapi_Error_Fail: region specified is not blank
 * \retval Fapi_Error_InvalidAddress:  User provided an invalid address
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_doBlankCheck(uint32 *pu32StartAddress, uint32 u32Length, Fls_FlashStatusWordType *poFlashStatusWord);

/** \brief Verifies region specified against provided data
 * \param[in] pu32StartAddress Start address for region to verify
 * \param[in] u32Length Length of region in 32-bit words to verify
 * \param[in] pu32CheckValueBuffer address of buffer to verify region against. Data buffer should be
 *128-bit aligned.
 * \param[out] poFlashStatusWord Returns the status of the operation if result is not
 *Fapi_Status_Success au32StatusWord[0] Address of first verify failure location au32StatusWord[1]
 *Data read at first verify failure location au32StatusWord[2] Value of compare data
 *             au32StatusWord[3] NA
 * \pre None
 * \post None
 * \return returns success or failure status
 * \retval Fapi_Status_Success: Success
 * \retval Fapi_Error_Fail: region specified is not blank
 * \retval Fapi_Error_InvalidAddress:  User provided an invalid address
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_doVerify(uint32 *pu32StartAddress, uint32 u32Length, uint32 *pu32CheckValueBuffer,
                      Fls_FlashStatusWordType *poFlashStatusWord);

/** \brief Verifies specified Flash memory range against supplied values by byte
 * \param[in] pu8StartAddress Start address for region to verify
 * \param[in] u32Length length of region in bytes to verify
 * \param[in] pu8CheckValueBuffer address of buffer to verify region against. Data buffer should be
 *128-bit aligned.
 * \param[out] poFlashStatusWord Returns the status of the operation if result is not
 *Fapi_Status_Success au32StatusWord[0] Address of first verify failure location au32StatusWord[1]
 *Data read at first verify failure location au32StatusWord[2] Value of compare data
 *             au32StatusWord[3] NA
 * \pre None
 * \post None
 * \return returns success or failure status
 * \retval Fapi_Status_Success: Success
 * \retval Fapi_Error_Fail: region specified is not blank
 * \retval Fapi_Error_InvalidAddress:  User provided an invalid address
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_doVerifyByByte(uint8 *pu8StartAddress, uint32 u32Length, uint8 *pu8CheckValueBuffer,
                            Fls_FlashStatusWordType *poFlashStatusWord);

/** \brief Sets up data and issues program command to valid flash memory addresses
 * \param[in] pu32StartAddress Start address in Flash for the data to be programmed. The start
 *address should always be even.
 * \param[in] pu8DataBuffer Pointer to the Data buffer address. Data buffer should be 64-bit
 *aligned.
 * \param[in] u8DataBufferSizeInBytes Number of bytes in the Data buffer
 * \pre None
 * \post None
 * \return returns success or failure status
 * \retval Fapi_Status_Success: Success
 * \retval Fapi_Status_FsmBusy: FSM busy
 * \retval Fapi_Error_FlashRegsNotWritable:  Flash register write failed
 * \retval Fapi_Error_AsyncIncorrectDataBufferLength Data buffer size specified is incorrect.
 * \retval Fapi_Error_InvalidAddress:  User provided an invalid address
 *
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, FLS_CODE)
    Fls_Fapi_issueProgrammingCommand(uint32 *pu32StartAddress, uint8 *pu8DataBuffer, uint8 u8DataBufferSizeInBytes);

/** \brief configures read wait states and enable data cache, code cache, prefetch, and data preread
 *to improve performance of code executed from flash
 * \param[in] waitstates waitstates according to frequency
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern FUNC(void, FLS_CODE) Fls_Update_WaitStates(uint16 waitstates);

/** \brief Claims flash semaphore
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern FUNC(void, FLS_CODE) Fls_SSU_claimFlashSemaphore(void);

/** \brief Release flash semaphore
 * \pre None
 * \post None
 * \return None
 *
 *********************************************************************************************************************/
extern FUNC(void, FLS_CODE) Fls_SSU_releaseFlashSemaphore(void);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /** end of FLS_AC_H_*/

/*********************************************************************************************************************
 *  End of File: Fls_Ac.h
 *********************************************************************************************************************/
