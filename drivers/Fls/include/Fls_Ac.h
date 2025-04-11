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

/**
 * \defgroup FLS Fls API GUIDE Header file
 * @{
 */

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
   #define TRUE              1U
#endif

#ifndef FALSE
   #define FALSE             0U
#endif

#if defined(_LITTLE_ENDIAN)
   #ifndef LOW_BYTE_FIRST
   #define CPU_BYTE_ORDER    LOW_BYTE_FIRST
   #endif
#else
   #ifndef HIGH_BYTE_FIRST
   #define CPU_BYTE_ORDER    HIGH_BYTE_FIRST
   #endif
#endif

/** \brief  SSU registers*/
#define FLS_SSUGEN_BASE               (uint32)(0x30080000U)  /** Base address of SSU module */
#define FLS_SSU_O_FLSEMREQ           (uint32)(0x224U)   /* Flash Controller Semaphore Request Register*/
#define FLS_SSU_O_FLSEMSTAT          (uint32)(0x220U)   /* Flash Controller Semaphore Status Register*/
#define FLS_SSU_O_FLSEMCLR           (uint32)(0x228U)   /* Flash Controller Semaphore Clear Register*/
#define FLS_SSU_FLSEMSTAT_CPU_M       (uint32)(0x7000U)  /* Semaphore CPU Owner*/
#define FLS_SSU_FLSEMSTAT_CPU_S      12U
#define FLS_SSU_FLSEMSTAT_ASSIGNED    (uint32)(0x80000000U)  /* Assigned Flag*/
#define FLS_SSU_FLSEMSTAT_MATCH       (uint32)(0x40000000U)  /* Match Status Bit */

/** \brief The following are defines for the bit fields in the BEPROT_BANK register*/
#define FLS_SSU_O_BEPROT_BANK          (uint32)(0x200U)   /* Bank Erase Protection Bank Register*/
#define FLS_SSU_O_BEPROT_STAT          (uint32)(0x204U)   /* Bank Erase Status Register*/
#define FLS_SSU_BEPROT_BANK_BANKID_S   0U
#define FLS_SSU_BEPROT_BANK_BANKID_M   0x7U    /* Bank Erase Bank*/
#define FLS_SSU_BEPROT_BANK_FLCID_S    3U
#define FLS_SSU_BEPROT_BANK_FLCID_M    0x18U   /* Bank Erase Bank*/

/** \brief FRI register offsets and bit fields*/
#define FLS_FLASH_FLC1_CMD_REGS_BASE   (uint32)(0x30100000U)
#define FLS_FRI1_CTL_BASE              (uint32)(0x301D0000U)
#define FLS_ANALOGSUBSYS_BASE          (uint32)(0x30182000U)
#define FLS_FRI_O_FRDCNTL              (uint32)(0x10U)   /** Flash Read Control Register*/
#define FLS_FRI_O_1_INTF_CTRL          (uint32)(0x30U)   /** Flash Read Interface 1 Control Register*/
#define FLS_FRI_FRDCNTL_RWAIT_S        (uint32)(8U)
#define FLS_FRI_FRDCNTL_RWAIT_M        (uint32)(0xF00U)       /** Read Waitstate*/

#define FLS_FLASH_DELAY_CONFIG   __asm(" NOP #8"); __asm(" NOP #8"); __asm(" NOP #4");
 
/**  \brief  FMC memory map defines */
//#if defined (_F29H85x_)
#define FLS_FLASH_READINTERFACE_BASE        (uint32)0x301D0000U  //C29 Flash Read Interface(Control base)
#define FLS_FLASH_FAPI_FLASHNW_FC1_BASE     (uint32)0x30100000U  //C29 Flash command Interface (FLC1)

/**  \brief  FR-4 RP0 data flash */
#define FLS_C29FLASHBANKFR4RP0STARTADDRESS                   (uint32)(0x10C00000U)
#define FLS_C29FLASHBANKFR4RP0ENDADDRESS                     (uint32)(0x10C3FFFFU)
#define FLS_C29FLASHBANKFR4RP0ENDADDRESSPLUS1                (uint32)(0x10C40000U)

/**  \brief  FR-4 RP0 ECC data flash*/
#define FLS_C29FLASHBANKFR4RP0ECCSTARTADDRESS                (uint32)(0x10F80000U)
#define FLS_C29FLASHBANKFR4RP0ECCENDADDRESS                  (uint32)(0x10F87FFFU)
#define FLS_C29FLASHBANKFR4RP0ECCENDADDRESSPLUS1             (uint32)(0x10F88000U)

/**  \brief  C29 banks : Non-Main Array */
/**  \brief  FR-4 RP0 Data Flash */
#define FLS_C29FLASHBANKFR4RP0BANKMGMTSTARTADDRESS            (uint32)(0x10D9E000U)
#define FLS_C29FLASHBANKFR4RP0BANKMGMTENDADDRESS              (uint32)(0x10D9EFFFU)
#define FLS_C29FLASHBANKFR4RP0BANKMGMTENDADDRESSPLUS1         (uint32)(0x10D9F000U)

/**  \brief   HSM C29 banks : Non-Main Array ECC */
/**  \brief   FR-4 RP0 Data flash */
#define FLS_C29FLASHBANKFR4RP0BANKMGMTECCSTARTADDRESS          (uint32)(0x10FB4000)
#define FLS_C29FLASHBANKFR4RP0BANKMGMTECCENDADDRESS            (uint32)(0x10FB41FF)
#define FLS_C29FLASHBANKFR4RP0BANKMGMTECCENDADDRESSPLUS1       (uint32)(0x10FB4200)

//#endif

#if defined (_F29P32x)
 /*to do for supporting F29P32x device*/
#endif

/**
 * \brief Macros for FRI options to use with the Flash_configFRI() function.
 * Includes macros for enabling and disabling prefetch, data cache, code cache
 * and data preread.
 */
#define FLS_FLASH_PREFETCH_ENABLE        0x1U
#define FLS_FLASH_PREFETCH_DISABLE       0x0U
#define FLS_FLASH_DATACACHE_ENABLE       0x2U
#define FLS_FLASH_DATACACHE_DISABLE      0x0U
#define FLS_FLASH_CODECACHE_ENABLE       0x4U
#define FLS_FLASH_CODECACHE_DISABLE      0x0U
#define FLS_FLASH_DATAPREREAD_ENABLE     0x8U
#define FLS_FLASH_DATAPREREAD_DISABLE    0x0U

/** \brief Macro to define the offset between options for different FRIs.
 *  For example, FRI_O_2_INTF_CTRL - FRI_O_1_INTF_CTRL = 0x10U.
 */
#define   FLS_FRI_REG_STEP                (uint8)(0x10U)

/**
 * \brief Internal macros used for committing trim registers.
 * Not intended for application use.
 */
#define FLS_ASYSCTL_O_FLASHTRIMCOMMIT     0x90U
#define FLS_ASYSCTL_FLC1TRIMCOMMITREAD    0x4U
#define FLS_ASYSCTL_FLC1TRIMCOMMITOTHER   0x8U

/**  \brief  The following are defines for the FLASH register offsets */
#define FLS_FLASH_O_REVISION             0x0U    /**  \brief  IP Revision Register */
#define FLS_FLASH_O_FRDCNTL              0x10U   /**  \brief  Flash Read Control Register */
#define FLS_FLASH_O_FLCLKCTL             0x20U   /**  \brief  Flash Read Clock Control Register */

/**  \brief  The following are defines for the bit fields in the FLCLKCTL register*/
#define FLS_FLASH_FLCLKCTL_KDIV_S   0U
#define FLS_FLASH_FLCLKCTL_KDIV_M   0xFU   /**  \brief  KDIV value of MCLK divider.*/

/**  \brief  The following are defines for the FLS_FLASH_NOWRAPPER register offsets */
#define FLS_FLASH_NW_O_CMDEXEC           0x100U   /**  \brief  Command Execute Register */ 
#define FLS_FLASH_NW_O_CMDTYPE           0x104U   /**  \brief  Command Type Register */    
#define FLS_FLASH_NW_O_CMDCTL            0x108U   /**  \brief  Command Control Register */ 
#define FLS_FLASH_NW_O_CMDADDR           0x120U   /**  \brief  Command Address Register */ 
#define FLS_FLASH_NW_O_CMDBYTEN          0x124U   /**  \brief  Command Program Byte Enable Register */
#define FLS_FLASH_NW_O_CMDDATAINDEX      0x12CU   /**  \brief  Command Data Index Register */
#define FLS_FLASH_NW_O_CMDDATA0          0x130U   /**  \brief  Command Data Register 0  */

#define FLS_FLASH_NW_O_CMDWEPROTA        0x1D0U   /**  \brief  Command Write Erase Protect A Register */
#define FLS_FLASH_NW_O_CMDWEPROTB        0x1D4U   /**  \brief  Command Write Erase Protect B Register */
#define FLS_FLASH_NW_O_CMDWEPROTNM       0x210U   /**  \brief  Command Write Erase Protect Non-Main */
                                                         /**  Register */
#define FLS_FLASH_NW_O_CFGCMD            0x3B0U   /**  \brief  Command Configuration Register */      
#define FLS_FLASH_NW_O_STATCMD           0x3D0U   /**  \brief  Command Status Register */             

/**  \brief  The following are defines for the bit fields in the CMDTYPE register*/
#define FLS_FLASH_NW_CMDTYPE_CMD_S   0U
#define FLS_FLASH_NW_CMDTYPE_CMD_M   0x7U    

/**  \brief  Configure for sector erase: Command is erase (2), Size is sector (4) */
#define FLS_FLASH_NW_CMDTYPE_SECTOR_ERASE   0x42U
/**  \brief  Configure for Bank erase: Command is erase (2), Size is Bank (5)*/
#define FLS_FLASH_NW_CMDTYPE_BANK_ERASE     0x52U   
/**  \brief  Configure for 4*128 word program: Command is program (1), Size is FOURWORD (2)*/
/**  \brief  Configure for 1*128 word program: Command is program (1), Size is ONEWORD (0)*/
#define FLS_FLASH_NW_CMDTYPE_PROG_ONEWD     0x01U   

#define FLS_FLASH_NW_CMDCTL_ECCGENOVR      (uint32)(0x20000U)
#define FLS_FLASH_NW_CMDCTL_ECCGENOVR_S    17U    
#define FLS_FLASH_NW_CMDCTL_DATAVEREN      (uint32)(0x200000U)
#define FLS_FLASH_NW_CMDCTL_DATAVEREN_S    21U   

/**  \brief  The following are defines for the bit fields in the CFGCMD register*/
#define FLS_FLASH_NW_CFGCMD_WAITSTATE_S    0U
#define FLS_FLASH_NW_CFGCMD_WAITSTATE_M    0xFU  

/**  \brief  The following are defines for the bit fields in the CMDBYTEN register*/
#define FLS_FLASH_NW_CMDBYTEN_VAL_S       0U
#define FLS_FLASH_NW_CMDBYTEN_VAL_M       0xFFU 
#define FLS_FLASH_NW_CMDBYTEN_ECC0VAL_S   16U
#define FLS_FLASH_NW_CMDBYTEN_ECC0VAL_M   (uint32)(0x10000U)
#define FLS_FLASH_NW_CMDBYTEN_ECC1VAL_S   17U
#define FLS_FLASH_NW_CMDBYTEN_ECC1VAL_M   (uint32)(0x20000U)

/**  \brief  The following are defines for the bit fields in the CMDWEPROTNM register*/
#define FLS_FLASH_NW_CMDWEPROTNM_VAL_S          0U
#define FLS_FLASH_NW_CMDWEPROTNM_VAL_M          1U
/**  \brief  Readback val to protect non-main region sector 0 erase*/
#define FLS_FLASH_NW_CMDWEPROTNM_READBACK_VAL   1U 

/* The following are defines for the bit fields in the STATCMD register*/
#define FLS_FLASH_NW_STATCMD_CMDDONE         0x1U      
#define FLS_FLASH_NW_STATCMD_CMDPASS         0x2U     
#define FLS_FLASH_NW_STATCMD_CMDINPROGRESS   0x4U     
#define FLS_FLASH_NW_STATCMD_FAILWEPROT      0x10U    
#define FLS_FLASH_NW_STATCMD_FAILVERIFY      0x20U    
#define FLS_FLASH_NW_STATCMD_FAILMISC        0x1000U  
#define FLS_FLASH_NW_STATCMD_FAILILLADDR     0x40U    
#define FLS_FLASH_NW_STATCMD_FAILMODE        0x80U    
#define FLS_FLASH_NW_STATCMD_FAILINVDATA     0x100U   

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/
/*typedef unsigned char      boolean;*/
typedef uint32    Fls_FapiFlashStatus; /** Flash status */

typedef struct Fls_FlashStatusWordTag
{
   uint32 au32StatusWord[4];
} __attribute__((packed))Fls_FlashStatusWordType;

/** \brief This is the master type containing all possible returned status codes */
typedef enum Fls_FapiStatusTag
{
   FLS_FAPI_STATUS_SUCCESS = 0U,               /* Function completed successfully */
   FLS_FAPI_STATUS_FSMBUSY = 1U,               /* FSM is Busy */
   FLS_FAPI_STATUS_FSMREADY = 2U,              /* FSM is Ready */
   FLS_FAPI_ERROR_FAIL = 500U,                 /*Generic Function Fail code */
   FLS_FAPI_ERROR_INVALIDHCLKVALUE = 504U,     /*Returned if FClk>max FClk - FClk is from HClk & RWAIT/EWAIT*/
   FLS_FAPI_ERROR_INVALIDADDRESS = 507U,       /*Returned if the specified Address does not exist in Flash or OTP*/
   FLS_FAPI_ERROR_ASYNCWRONGDBUFLEN = 509U,    /*incorrect Data buffer length */
   FLS_FAPI_ERROR_FEATURENOTAVAILABLE = 512U,  /*FMC feature is not available on this device */
   FLS_FAPI_ERROR_FLASHREGSNOTWRITABLE = 513U  /*Returned if Flash registers are not writable due to security */
} __attribute__((packed)) Fls_FapiStatusType;

/** \brief This contains all the possible Flash State Machine commands */
typedef enum Fls_FlashStateCmdTag
{
   FLS_FAPI_PROGRAMDATA  =  2U,
   FLS_FAPI_ERASESECTOR  =  6U,
   FLS_FAPI_ERASEBANK    =  8U,
   FLS_FAPI_CLEARSTATUS  = 16U
} __attribute__((packed)) Fls_FlashStateCmdType;

typedef enum Fls_FapiRegionValueTag
{
   FLS_FAPI_SINGLEVALUE = 0U,
   FLS_FAPI_MULTIPLEVALUE,
   FLS_FAPI_MULTIPLEVALUEECC
} Fls_FapiRegionValueType;

/** \brief Enumeration of FRI register addresses for use with Flash_configFRI() */
typedef enum Fls_FlashFRITag
{
   FLS_FLASH_FRI1 =  (uint8)(0U),
   FLS_FLASH_FRI2 =  (uint8)(1U),
   FLS_FLASH_FRI3 =  (uint8)(2U),
   FLS_FLASH_FRI4 =  (uint8)(3U)
} Fls_FlashFRIType;


/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/


/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
/* Flash State Machine commands */
extern FUNC(Fls_FapiFlashStatus, FLS_CODE) Fls_Fapi_getFsmStatus(void);
extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_checkFsmForReady(void);
extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_setupBankSectorEnable(uint32 reg_address, uint32 value);

/* Async Commands */
extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_issueAsyncCommandWithAddress(Fls_FlashStateCmdType oCommand,  
                                                         uint32 *pu32StartAddress );

extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_issueAsyncCommand(Fls_FlashStateCmdType oCommand);

extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_issueBankEraseCommand(uint32 *pu32StartAddress );

/** Init */
extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_initializeAPI( uint32 u32HclkFrequency );
/** Read commands */
extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_doBlankCheck( uint32 *pu32StartAddress, 
                                                   uint32 u32Length,
                                                   Fls_FlashStatusWordType *poFlashStatusWord );

extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_doVerify( uint32 *pu32StartAddress, uint32 u32Length,
                                      uint32 *pu32CheckValueBuffer,
                                      Fls_FlashStatusWordType *poFlashStatusWord  );
extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_doVerifyByByte( uint8 *pu8StartAddress, uint32 u32Length,
                                            uint8 *pu8CheckValueBuffer,
                                            Fls_FlashStatusWordType *poFlashStatusWord  );

/** Programming Commands */
extern FUNC(Fls_FapiStatusType, FLS_CODE) Fls_Fapi_issueProgrammingCommand( uint32 *pu32StartAddress,
                                                      uint8  *pu8DataBuffer,
                                                      uint8  u8DataBufferSizeInBytes );
/** Utility Commands */
extern FUNC(void, FLS_CODE) Fls_Update_WaitStates(uint16 waitstates);

extern FUNC(void, FLS_CODE) Fls_SSU_claimFlashSemaphore(void);
extern FUNC(void, FLS_CODE) Fls_SSU_releaseFlashSemaphore(void);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /** end of FLS_AC_H_*/

/*********************************************************************************************************************
 *  End of File: Fls_Ac.h
 *********************************************************************************************************************/