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
 *                 (C) Copyright 2024 Texas Instruments Inc.  All rights reserved.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Mcal_Lib_BootRom.h
 *  Generator:  None
 *
 *  Description:  Bootrom structures.                                                         
 *********************************************************************************************************************/
#ifndef MCAL_LIB_BOOTROM_H
#define MCAL_LIB_BOOTROM_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
 #include "Std_Types.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*****************************************************************************
 *
 * \brief Bootrom Flow Status.
 *
 *****************************************************************************/
typedef enum
{
    STATUS_NA   = 0x1, /* Flow status is NOT RUN */
    STATUS_PASS = 0x2, /* Flow status is PASS */
    STATUS_FAIL = 0x3  /* Flow status is FAIL */
} McalLib_Status;

/*****************************************************************************
 *
 * \brief Flash Bank Mode
 *
 *****************************************************************************/
typedef enum
{
    FLASH_BANK_MODE_0       = 0x03U,
    FLASH_BANK_MODE_1       = 0x06U,
    FLASH_BANK_MODE_2       = 0x09U,
    FLASH_BANK_MODE_3       = 0x0CU,
    FLASH_BANK_MODE_INVALID = 0x55U
} McalLib_FlashBankMode;

/*****************************************************************************
 *
 * \brief Flash Bank Swap settings
 *
 *****************************************************************************/
typedef enum
{
    FLASH_BANK_SWAP_DEFAULT   = 0xC9U,
    FLASH_BANK_SWAP_ALTERNATE = 0x36U,
    FLASH_BANK_SWAP_INVALID   = 0x5555U
} McalLib_FlashBankSwap;

/*****************************************************************************
 *
 * \brief Secvalid settings
 *
 *****************************************************************************/
typedef enum
{
    SECVALID_BASE      = 0xC9U,
    SECVALID_ALTERNATE = 0x36U,
    SECVALID_INVALID   = 0x550055U
} McalLib_SecValid;

/*****************************************************************************
 *
 * \brief Ssumode settings
 *
 *****************************************************************************/
typedef enum
{
    SSUMODE_1       = 0x30U,
    SSUMODE_2       = 0x0CU,
    SSUMODE_3       = 0x03U,
    SSUMODE_INVALID = 0x55U
} McalLib_SsuMode;

/*****************************************************************************
 *
 * \brief Device Life Cycle States
 *
 *****************************************************************************/
typedef enum
{
    DEV_LIFE_CYCLE_STATE_BAD    = 0x11123D7DU, /* BAD state */
    DEV_LIFE_CYCLE_STATE_TEST   = 0xB5A66409U, /* TEST state */
    DEV_LIFE_CYCLE_STATE_GP     = 0x021CCF0FU, /* GP state */
    DEV_LIFE_CYCLE_STATE_EMU_SE = 0xEFC02492U, /* EMU SE state */
    DEV_LIFE_CYCLE_STATE_EMU_KP = 0x0562C717U, /* EMU KP state */
    DEV_LIFE_CYCLE_STATE_EMU_FS = 0x4A8038E3U, /* EMU FS state */
    DEV_LIFE_CYCLE_STATE_EMU_FA = 0x3DC57F36U, /* EMU FA state */
    DEV_LIFE_CYCLE_STATE_HS_SE  = 0xA4B45974U, /* HS SE state */
    DEV_LIFE_CYCLE_STATE_HS_KP  = 0x2D3B68E5U, /* HS KP state */
    DEV_LIFE_CYCLE_STATE_HS_FS  = 0xA5401C71U, /* HS FS state */
    DEV_LIFE_CYCLE_STATE_HS_FA  = 0x2C6DB3FAU  /* HS FA state */
} McalLib_DevLifeCycleState;

/*****************************************************************************
 *
 * \brief Link0 error ids
 *
 *****************************************************************************/
typedef enum
{
    LINK0_ERR_ID_NONE           = 0xF487DA78U, /* No error */
    LINK0_ERR_ID_APR_CONFIG     = 0x2AC69B4FU, /* LINK0 APR configurtation error */
    LINK0_ERR_ID_SSU_POST       = 0xADF53EF6U, /* SSU POST error */
    LINK0_ERR_ID_SSU_CONFIG     = 0x57DE827CU, /* SSU configurtation error */
    LINK0_ERR_ID_NMI            = 0xCDF5847DU, /* NMI error */
    LINK0_ERR_ID_SECCFG_APR     = 0x69D473BEU, /* NMI error */
    LINK0_ERR_ID_WDG_SYNCBUSY   = 0xFE3BC723U, /* WDG Sync Busy */
    LINK0_ERR_ID_XTAL_SYNCBUSY  = 0x9BC4EA4CU  /* XTAL Sync Busy */
} McalLib_Link0ErrId;


/*****************************************************************************
 *
 * \brief Bootrom flow Status Bitfields
 *  This is a bitfield structure whose members reflect the following flow status:
 *  STATUS_NA   - Step Not Run.
 *  STATUS_PASS - Step Pass.
 *  STATUS_FAIL - Step Fail.
 * 
 *****************************************************************************/
typedef struct
{
    McalLib_Status RamInit:2;       /* Flow status for RAM Initialization: */
    McalLib_Status Hwpatch:2;       /* Flow status for ROM Hardware Patching: */
    McalLib_Status ErrorStsPin:2;   /* Flow status for Error status pin configuration: */
    McalLib_Status Zone0pswd:2;     /* Flow status for ZONE0 debug passwsrd: */
    McalLib_Status Uid:2;           /* Flow status for Unique Id: */
    McalLib_Status Friws:2;         /* Flow status for FRI wait states:*/
    McalLib_Status WdEnable:2;      /* Flow status for Watchdog enable:*/
    McalLib_Status Pmmtrim:2;       /* Flow status for PMM Trim: */
    McalLib_Status Osctrim:2;       /* Flow status for OSC Trim: */
    McalLib_Status Aplltrim:2;      /* Flow status for APLL Trim: */
    McalLib_Status Flashtrim:2;     /* Flow status for Flash Trim: */
    McalLib_Status Criticaltrim:2;  /* Flow status for Overall Critical Trim: */
    McalLib_Status Devconfig:2;     /* Flow status for Device Configuration: */
    McalLib_Status LockDcx:2;       /* Flow status for DCx Lock: */
    McalLib_Status RescClr:2;       /* Flow status for Reset Cause Clear: */
    McalLib_Status FlashTrimLock:2; /* Flow status for Flash Trim Lock: */
    McalLib_Status EsmLockCommit:2; /* Flow status for ESM Lock and Commit Group 0 error events: */
    McalLib_Status UppRev:2;        /* Flow status for UPP revision: */
    McalLib_Status XtalEn:2;        /* Flow status for external crystal power up:*/
    McalLib_Status SsuPost:2;       /* Flow status for SSU post: */
    McalLib_Status SsuInit:2;       /* Flow status for SSU Initialization: */
    McalLib_Status PmmDbgtrim:2;    /* Flow status for PMM Debug Trim: */
    McalLib_Status AdcReftrim:2;    /* Flow status for ADC Reference Trim: */
    McalLib_Status AdcOfftrim:2;    /* Flow status for ADC offset Trim: */
    McalLib_Status AdcInltrim:2;    /* Flow status for ADCINL Trim: */
    McalLib_Status DacOfftrim:2;    /* Flow status for DAC Offset Trim: */

} McalLib_Brom;


/*****************************************************************************
 *
 * \brief SSU status structure.
 *
 ******************************************************************************/
typedef struct
{
    McalLib_Status          BankMgmtCpu1:2;         /* Flow status for CPU1 bank mgmt */
    McalLib_Status          BankMgmtCpu3:2;         /* Flow status for CPU3 bank mgmt */
    McalLib_Status          EccBankMode:2;          /* Flow status for Bank mode ECC */
    McalLib_Status          EetBankMode:2;          /* Flow status for Get bankmode */
    McalLib_Status          ReadError:2;            /* Flow status for sector read error */
    McalLib_Status          EccSsuMode:2;           /* Flow status for SSU mode ECC */
    McalLib_Status          GetSsuMode:2;           /* Flow status for Get SSU mode */
    McalLib_Status          SecCfgCpu1:2;           /* Flow status for CPU1 seccfg */
    McalLib_Status          SecCfgCpu3:2;           /* Flow status for CPU3 seccfg */
    McalLib_Status          SsuCfgCpu1:2;           /* Flow status for CPU1 SSU config */
    McalLib_Status          SsuCfgCpu3:2;           /* Flow status for CPU3 SSU config */
    McalLib_Status          AprCfg:2;               /* Flow status for CPU1, CPU2 and CPU3 APR configuration */
    uint32                  WinningBankMgmtCpu1;    /* Winning bank mgmt sector found for CPU1 */
    uint32                  WinningBankMgmtCpu3;    /* Winning bank mgmt sector found for CPU3 */
    uint32                  ValidSecCfgCpu1;        /* Valid SECCFG sector found for CPU1 */
    uint32                  ValidSecCfgCpu3;        /* Valid SECCFG sector found for CPU3 */
    McalLib_FlashBankMode   BankMode;               /* Bankmode got from bank mgmt sector */
    McalLib_FlashBankSwap   Cpu1swap;               /* Decoded CPU1 swap settings */
    McalLib_FlashBankSwap   Cpu3swap;               /* Decoded CPU3 swap settings */
    McalLib_SecValid        SecvalidCpu1;           /* Decoded CPU1 SECVALID settings */
    McalLib_SecValid        SecvalidCpu3;           /* Decoded CPU3 SECVALID settings */
    McalLib_SsuMode         SsuMode;                /* SSU mode setting */
} McalLib_SsuStatus;


/*****************************************************************************
 *
 * \brief EA status structure.
 *
 ******************************************************************************/
typedef struct
{
    uint32  HighPriAddr;      /* EA High priority address */
    uint32  LowPriAddr;       /* EA Low priority address */
    uint32  ErrType;          /* EA Error Type */
    uint32  PcAddr;           /* Program Counter */
} McalLib_EaStatus;


/*****************************************************************************
 *
 * \brief NMI status structure.
 *
 ******************************************************************************/
typedef struct
{
    uint32              EsmRawStatus;   /* ESM RAW status */
    McalLib_EaStatus    EaCpu1Pr;       /* EA CPU1 PR status */ 
    McalLib_EaStatus    EaCpu1Dr1;      /* EA CPU1 DR1 status */
    McalLib_EaStatus    EaCpu1Dr2;      /* EA CPU1 DR2 status */
    McalLib_EaStatus    EaCpu1Dw;       /* EA CPU1 DW status */
    McalLib_EaStatus    EaCpu1Int;      /* EA CPU1 INT status */
} McalLib_NmiStatus;


/*****************************************************************************
 *
 * \brief Bootrom status structure placed in M0 RAM.
 *
 ******************************************************************************/
typedef struct
{
    uint64                      Link0StartCycleCount;   /* Link0 start cycle count */
    uint64                      Link0EndCycleCount;     /* Link0 end cycle count */
    uint32                      ResetCnt;               /* Reset count */
    uint32                      ResetCause;             /* Reset cause */
    uint32                      Sysclk;                 /* System Clock in Hertz */
    uint32                      EccErrAddrDR1;          /* ECC Error Address for DR1: */
    uint32                      EccErrAddrDR2;          /* ECC Error Address for DR2: */
    uint32                      BootMode;               /* Boot Mode: */
    uint32                      BootLoaderLock;         /* Bootloader Lock: */
    McalLib_DevLifeCycleState   DeviceLifeCycleState;   /* Device life cycle state */
    McalLib_Link0ErrId          Link0ErrId;             /* Link0 Error Id */
    McalLib_Brom                BromStatus;             /* Boot rom status */
    McalLib_SsuStatus           SsuStatus;              /* SSU status */
    McalLib_NmiStatus           NmiStatus;              /* NMI status */
} McalLib_BromStatus;


/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief returns the boot rom structure data
 *
 * \param[in] BootRomStatus Structure of BootRom status
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCAL_LIB_CODE) McalLib_BootRomStructure(McalLib_BromStatus ** BootRomStatus);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* MCAL_LIB_BOOTROM_H */
/*********************************************************************************************************************
 *  End of File: Mcal_Lib_BootRom.h
 *********************************************************************************************************************/
