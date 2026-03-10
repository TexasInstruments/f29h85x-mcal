/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2024 Texas Instruments Incorporated
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
    LINK0_ERR_ID_NONE          = 0xF487DA78U, /* No error */
    LINK0_ERR_ID_APR_CONFIG    = 0x2AC69B4FU, /* LINK0 APR configurtation error */
    LINK0_ERR_ID_SSU_POST      = 0xADF53EF6U, /* SSU POST error */
    LINK0_ERR_ID_SSU_CONFIG    = 0x57DE827CU, /* SSU configurtation error */
    LINK0_ERR_ID_NMI           = 0xCDF5847DU, /* NMI error */
    LINK0_ERR_ID_SECCFG_APR    = 0x69D473BEU, /* NMI error */
    LINK0_ERR_ID_WDG_SYNCBUSY  = 0xFE3BC723U, /* WDG Sync Busy */
    LINK0_ERR_ID_XTAL_SYNCBUSY = 0x9BC4EA4CU  /* XTAL Sync Busy */
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
    uint32 RamInit : 2;       /* Flow status for RAM Initialization: */
    uint32 Hwpatch : 2;       /* Flow status for ROM Hardware Patching: */
    uint32 ErrorStsPin : 2;   /* Flow status for Error status pin configuration: */
    uint32 Zone0pswd : 2;     /* Flow status for ZONE0 debug passwsrd: */
    uint32 Uid : 2;           /* Flow status for Unique Id: */
    uint32 Friws : 2;         /* Flow status for FRI wait states:*/
    uint32 WdEnable : 2;      /* Flow status for Watchdog enable:*/
    uint32 Pmmtrim : 2;       /* Flow status for PMM Trim: */
    uint32 Osctrim : 2;       /* Flow status for OSC Trim: */
    uint32 Aplltrim : 2;      /* Flow status for APLL Trim: */
    uint32 Flashtrim : 2;     /* Flow status for Flash Trim: */
    uint32 Criticaltrim : 2;  /* Flow status for Overall Critical Trim: */
    uint32 Devconfig : 2;     /* Flow status for Device Configuration: */
    uint32 LockDcx : 2;       /* Flow status for DCx Lock: */
    uint32 RescClr : 2;       /* Flow status for Reset Cause Clear: */
    uint32 FlashTrimLock : 2; /* Flow status for Flash Trim Lock: */
    uint32 EsmLockCommit : 2; /* Flow status for ESM Lock and Commit Group 0 error events: */
    uint32 UppRev : 2;        /* Flow status for UPP revision: */
    uint32 XtalEn : 2;        /* Flow status for external crystal power up:*/
    uint32 SsuPost : 2;       /* Flow status for SSU post: */
    uint32 SsuInit : 2;       /* Flow status for SSU Initialization: */
    uint32 PmmDbgtrim : 2;    /* Flow status for PMM Debug Trim: */
    uint32 AdcReftrim : 2;    /* Flow status for ADC Reference Trim: */
    uint32 AdcOfftrim : 2;    /* Flow status for ADC offset Trim: */
    uint32 AdcInltrim : 2;    /* Flow status for ADCINL Trim: */
    uint32 DacOfftrim : 2;    /* Flow status for DAC Offset Trim: */

} McalLib_Brom;

/*****************************************************************************
 *
 * \brief SSU status structure.
 *
 ******************************************************************************/
typedef struct
{
    uint32                BankMgmtCpu1 : 2;    /* Flow status for CPU1 bank mgmt */
    uint32                BankMgmtCpu3 : 2;    /* Flow status for CPU3 bank mgmt */
    uint32                EccBankMode : 2;     /* Flow status for Bank mode ECC */
    uint32                EetBankMode : 2;     /* Flow status for Get bankmode */
    uint32                ReadError : 2;       /* Flow status for sector read error */
    uint32                EccSsuMode : 2;      /* Flow status for SSU mode ECC */
    uint32                GetSsuMode : 2;      /* Flow status for Get SSU mode */
    uint32                SecCfgCpu1 : 2;      /* Flow status for CPU1 seccfg */
    uint32                SecCfgCpu3 : 2;      /* Flow status for CPU3 seccfg */
    uint32                SsuCfgCpu1 : 2;      /* Flow status for CPU1 SSU config */
    uint32                SsuCfgCpu3 : 2;      /* Flow status for CPU3 SSU config */
    uint32                AprCfg : 2;          /* Flow status for CPU1, CPU2 and CPU3 APR configuration */
    uint32                WinningBankMgmtCpu1; /* Winning bank mgmt sector found for CPU1 */
    uint32                WinningBankMgmtCpu3; /* Winning bank mgmt sector found for CPU3 */
    uint32                ValidSecCfgCpu1;     /* Valid SECCFG sector found for CPU1 */
    uint32                ValidSecCfgCpu3;     /* Valid SECCFG sector found for CPU3 */
    McalLib_FlashBankMode BankMode;            /* Bankmode got from bank mgmt sector */
    McalLib_FlashBankSwap Cpu1swap;            /* Decoded CPU1 swap settings */
    McalLib_FlashBankSwap Cpu3swap;            /* Decoded CPU3 swap settings */
    McalLib_SecValid      SecvalidCpu1;        /* Decoded CPU1 SECVALID settings */
    McalLib_SecValid      SecvalidCpu3;        /* Decoded CPU3 SECVALID settings */
    McalLib_SsuMode       SsuMode;             /* SSU mode setting */
} McalLib_SsuStatus;

/*****************************************************************************
 *
 * \brief EA status structure.
 *
 ******************************************************************************/
typedef struct
{
    uint32 HighPriAddr; /* EA High priority address */
    uint32 LowPriAddr;  /* EA Low priority address */
    uint32 ErrType;     /* EA Error Type */
    uint32 PcAddr;      /* Program Counter */
} McalLib_EaStatus;

/*****************************************************************************
 *
 * \brief NMI status structure.
 *
 ******************************************************************************/
typedef struct
{
    uint32           EsmRawStatus; /* ESM RAW status */
    McalLib_EaStatus EaCpu1Pr;     /* EA CPU1 PR status */
    McalLib_EaStatus EaCpu1Dr1;    /* EA CPU1 DR1 status */
    McalLib_EaStatus EaCpu1Dr2;    /* EA CPU1 DR2 status */
    McalLib_EaStatus EaCpu1Dw;     /* EA CPU1 DW status */
    McalLib_EaStatus EaCpu1Int;    /* EA CPU1 INT status */
} McalLib_NmiStatus;

/*****************************************************************************
 *
 * \brief Bootrom status structure placed in M0 RAM.
 *
 ******************************************************************************/
typedef struct
{
    uint64                    Link0StartCycleCount; /* Link0 start cycle count */
    uint64                    Link0EndCycleCount;   /* Link0 end cycle count */
    uint32                    ResetCnt;             /* Reset count */
    uint32                    ResetCause;           /* Reset cause */
    uint32                    Sysclk;               /* System Clock in Hertz */
    uint32                    EccErrAddrDR1;        /* ECC Error Address for DR1: */
    uint32                    EccErrAddrDR2;        /* ECC Error Address for DR2: */
    uint32                    BootMode;             /* Boot Mode: */
    uint32                    BootLoaderLock;       /* Bootloader Lock: */
    McalLib_DevLifeCycleState DeviceLifeCycleState; /* Device life cycle state */
    McalLib_Link0ErrId        Link0ErrId;           /* Link0 Error Id */
    McalLib_Brom              BromStatus;           /* Boot rom status */
    McalLib_SsuStatus         SsuStatus;            /* SSU status */
    McalLib_NmiStatus         NmiStatus;            /* NMI status */
} McalLib_BromStatus;

typedef struct
{
    uint32 DevCalI2vR130C;       /* I2V R1 30C */
    uint32 DevCalI2vR230C;       /* I2V R2 30C */
    uint32 DevCalI2vR330C;       /* I2V R3 30C */
    uint32 DevCalI2vR1N40C;      /* I2V R1 N40C */
    uint32 DevCalI2vR2N40C;      /* I2V R2 N40C */
    uint32 DevCalI2vR3N40C;      /* I2V R3 N40C */
    uint32 DevCalI2vR1125C;      /* I2V R1 125C */
    uint32 DevCalI2vR2125C;      /* I2V R2 125C */
    uint32 DevCalI2vR3125C;      /* I2V R3 125C */
    uint32 Rsvd11Mp1;            /* Reserved 11 MP1 */
    uint32 DfwtRevMp1;           /* Dfwtrev MP1 */
    uint32 BoardIdMp1;           /* BoardId MP1 */
    uint32 ChkSumLsbMp1;         /* Chksumlsb MP1 */
    uint32 Rsvd14Mp3;            /* Reserved 14 MP3 */
    uint32 DfwtRevMp3;           /* Dfwtrev MP1 */
    uint32 BoardIdMp3;           /* BoardId MP3 */
    uint32 ChkSumLsbMp3;         /* Chksumlsb MP3 */
    uint32 BootRomRsvd0;         /* Bootrom reserved 0 */
    uint32 BootRomRsvd2;         /* Bootrom reserved 2 */
    uint32 BootRomRsvd4;         /* Bootrom reserved 4 */
    uint32 DfwtRevFt;            /* Dfwtrev FT */
    uint32 PmmConfigDebug0;      /* PMM Config Debug 0 */
    uint32 PmmConfigDebug1;      /* PMM Config Debug 1 */
    uint32 AnaRefTrimA1P65;      /* ANAREFTRIMA1P65 */
    uint32 AnaRefTrimA2P5;       /* ANAREFTRIMA2P5 */
    uint32 AnaRefTrimC1P65;      /* ANAREFTRIMC1P65 */
    uint32 AnaRefTrimC2P5;       /* ANAREFTRIMC2P5 */
    uint32 AdcAoffTrim;          /* ADCA OFF TRIM */
    uint32 AdcAoffTrim2;         /* ADCA OFF TRIM 2 */
    uint32 AdcAoffTrim3;         /* ADCA OFF TRIM 3 */
    uint32 AdcBoffTrim;          /* ADCA OFF TRIM 3*/
    uint32 AdcBoffTrim2;         /* ADCA OFF TRIM 3 */
    uint32 AdcBoffTrim3;         /* ADCB OFF TRIM 3 */
    uint32 AdcCoffTrim;          /* ADCC OFF TRIM 3 */
    uint32 AdcDoffTrim;          /* ADCD OFF TRIM 3 */
    uint32 AdcEoffTrim;          /* ADCE OFF TRIM 3 */
    uint32 AdcAInlTrim[6U];      /* ADCA INL TRIM 1-6 */
    uint32 AdcBInlTrim[6U];      /* ADCB INL TRIM 1-6 */
    uint32 AdcCInlTrim[3U];      /* ADCC INL TRIM 1-6 */
    uint32 AdcDInlTrim[3U];      /* ADCD INL TRIM 1-6 */
    uint32 AdcEInlTrim[3U];      /* ADCE INL TRIM 1-6 */
    uint32 DacAOffTrim;          /* DACA OFF TRIM */
    uint32 DacCOffTrim;          /* DACC OFF TRIM */
    uint32 Hole0;                /* Hole 0 */
    uint32 Hole1;                /* Hole 1 */
    uint32 Hole2;                /* Hole 2 */
    uint32 DevCalTsGainExtref;   /* DEVCAL TS Gain Extref */
    uint32 DevCalTsOffsetExtref; /* DEVCAL TS Offset Extref */
    uint32 DevCalTsGainIntref;   /* DEVCAL TS Gain Intref */
    uint32 DevCalTsOffsetIntref; /* DEVCAL TS Offset Intref */
    uint32 DevCalRev;            /* DEVCAL Revision */
} McalLib_DevCalData;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern const McalLib_DevCalData McalLib_DeviceCalibrationData;

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
FUNC(void, MCAL_LIB_CODE) McalLib_BootRomStructure(McalLib_BromStatus** BootRomStatus);

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
