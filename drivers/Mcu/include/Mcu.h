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
 *  File:       Mcu.h
 *  Generator:  None
 *
 *  Description:  This file contains interface header for Mcu Drv functions
 *********************************************************************************************************************/
#ifndef MCU_H
#define MCU_H

/**
 * \defgroup MCU Mcu API GUIDE Header file
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*
 * Design: MCAL-21784
 */
#include "Std_Types.h"
#include "Mcu_Cfg.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Defines for MCU Driver version used for compatibility checks.
 *********************************************************************************************************************/
/** \brief Driver Implementation Major Version. */
#define MCU_SW_MAJOR_VERSION (2U)
/** \brief Driver Implementation Minor Version. */
#define MCU_SW_MINOR_VERSION (3U)
/** \brief Driver Implementation Patch Version. */
#define MCU_SW_PATCH_VERSION (0U)

/*********************************************************************************************************************
 * Defines for MCU Driver AUTOSAR version used for compatibility checks.
 *********************************************************************************************************************/
/** \brief AUTOSAR Major version specification implemented by MCU Driver.*/
#define MCU_AR_RELEASE_MAJOR_VERSION (4U)

/** \brief AUTOSAR Minor version specification implemented by MCU Driver.*/
#define MCU_AR_RELEASE_MINOR_VERSION (3U)

/** \brief AUTOSAR Patch version specification implemented by MCU Driver.*/
#define MCU_AR_RELEASE_REVISION_VERSION (1U)

/*********************************************************************************************************************
 * MCU Driver ID Info.
 *********************************************************************************************************************/
/** \brief Texas Instruments Vendor ID. */
#define MCU_VENDOR_ID ((uint16)44U)
/** \brief MCU Driver Module ID. */
#define MCU_MODULE_ID ((uint16)101U)
/** \brief MCU Instance ID. */
#define MCU_INSTANCE_ID ((uint8)0U)

/*********************************************************************************************************************
 * MCU Service Ids.
 *
 * The Service Id is one of the argument to Det_ReportError function and is
 * used to identify the source of the error.
 *********************************************************************************************************************/
/** \brief Service ID for Mcu_Init.*/
#define MCU_SID_INIT ((uint8)0x00U)
/** \brief Service ID for Mcu_InitRamSection.*/
#define MCU_SID_INIT_RAMSECTION ((uint8)0x01U)
/** \brief Service ID for Mcu_InitClock.*/
#define MCU_SID_INIT_CLOCK ((uint8)0x02U)
/** \brief Service ID for Mcu_DistributePllClock.*/
#define MCU_SID_DISTRIBUTE_PLL_CLOCK ((uint8)0x03U)
/** \brief Service ID for Mcu_GetPllStatus.*/
#define MCU_SID_GET_PLL_STATUS ((uint8)0x04U)
/** \brief Service ID for Mcu_GetResetReason.*/
#define MCU_SID_GET_RESET_REASON ((uint8)0x05U)
/** \brief Service ID for Mcu_GetResetRawValue.*/
#define MCU_SID_GET_RESET_RAW_VALUE ((uint8)0x06U)
/** \brief Service ID for Mcu_PerformReset.*/
#define MCU_SID_PERFORM_RESET ((uint8)0x07U)
/** \brief Service ID for Mcu_SetMode.*/
#define MCU_SID_SET_MODE ((uint8)0x08U)
/** \brief Service ID for Mcu_GetVersionInfo.*/
#define MCU_SID_GET_VERSION_INFO ((uint8)0x09U)
/** \brief Service ID for Mcu_GetRamState.*/
#define MCU_SID_GET_RAM_STATE ((uint8)0x0AU)
/** \brief Service ID for Mcu_GetSystemClock.*/
#define MCU_SID_GET_SYS_CLOCK ((uint8)0x0BU)
/** \brief Service ID for Mcu_ASysCtl_SelectInternalTestNode.*/
#define MCU_SID_ASY_SELECT_INTERNAL_TEST_NODE ((uint8)0x0CU)
/** \brief Service ID for Mcu_ASysCtl_ConfigADCGlobalSOC.*/
#define MCU_SID_ASY_CONFIG_ADC_GLOBAL_SOC ((uint8)0x0DU)
/** \brief Service ID for Mcu_ASysCtl_ForceADCGlobalSOC.*/
#define MCU_SID_ASY_FORCE_ADC_GLOBAL_SOC ((uint8)0x0EU)
/** \brief Service ID for Mcu_ASysCtl_CommitLock.*/
#define MCU_SID_ASYSCTL_COMMIT_LOCK ((uint8)0x0FU)
/** \brief Service ID for Mcu_SysCtl_ConfigEPWMXLink. */
#define MCU_SID_SYSCTL_CONFIG_EPWMXLINK ((uint8)0x10U)

/*********************************************************************************************************************
 * MCU Error Codes returned by Driver functions.
 *********************************************************************************************************************/
/*
 * Design: MCAL-21793, MCAL-21851
 */
#ifndef MCU_E_PARAM_CONFIG
/** \brief Mcu_Init config param invalid.*/
#define MCU_E_PARAM_CONFIG ((uint8)0x0AU)
#endif
#ifndef MCU_E_PARAM_CLOCK
/** \brief Mcu_InitClock clockid param invalid.*/
#define MCU_E_PARAM_CLOCK ((uint8)0x0BU)
#endif
#ifndef MCU_E_PARAM_MODE
/** \brief Mcu_SetMode modeid param invalid.*/
#define MCU_E_PARAM_MODE ((uint8)0x0CU)
#endif
#ifndef MCU_E_PARAM_RAMSECTION
/** \brief Mcu_InitRamSection ramSect param invalid.*/
#define MCU_E_PARAM_RAMSECTION ((uint8)0x0DU)
#endif
#ifndef MCU_E_PLL_NOT_LOCKED
/** \brief PLL not locked.*/
#define MCU_E_PLL_NOT_LOCKED ((uint8)0x0EU)
#endif
#ifndef MCU_E_UNINIT
/** \brief API invoked without performing Mcu_Init.*/
#define MCU_E_UNINIT ((uint8)0x0FU)
#endif
#ifndef MCU_E_PARAM_POINTER
/** \brief NULL_PTR passed to MCU driver APIs.*/
#define MCU_E_PARAM_POINTER ((uint8)0x10U)
#endif
#ifndef MCU_E_INIT_FAILED
/** \brief Mcu Initialization failed. */
#define MCU_E_INIT_FAILED ((uint8)0x11U)
#endif
#ifndef MCU_E_UNINIT_CLOCK
/** \brief API invoked without performing Mcu_InitClock. */
#define MCU_E_UNINIT_CLOCK ((uint8)0x12U)
#endif
#ifndef MCU_E_PARAM_TESTNODE
/** \brief Invalid test node value passed to Mcu_ASysCtl_SelectInternalTestNode. */
#define MCU_E_PARAM_TESTNODE ((uint8)0x13U)
#endif
#ifndef MCU_E_ALREADY_LOCKED
/** \brief Error code: Mcu_ASysCtl_CommitLock() called with lock bits that are already committed.
 *
 * Reported when one or more bits in the LockMask parameter are already set in the
 * internal committed-lock tracking variable (Mcu_ASysCtlCommitLockStatus).
 * ASysCtl lock bits are write-once and cannot be re-applied after the first commit.
 */
#define MCU_E_ALREADY_LOCKED ((uint8)0x14U)
#endif

/** \brief Define indicating invalid raw reset value.*/
#define MCU_ERRORRST_MASK ((Mcu_RawResetType)0xFFFF0000U)

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Bitmask type for ASysCtl LOCK register (ASYSCTL_O_LOCK).
 *
 * Values can be OR-combined to lock multiple registers in a single call.
 * Each bit corresponds to one register lock in the ASYSCTL_O_LOCK register.
 *
 * \warning These enum values MUST match the hardware register bit definitions in hw_asysctl.h
 *          (ASYSCTL_LOCK_*). The implementation relies on direct casting without bit translation
 *          to minimize cyclomatic complexity and meet HIS metrics requirements.
 *********************************************************************************************************************/
typedef enum
{
    MCU_ASYSCTL_LOCK_TSNSCTL     = 0x001U, /**< Lock TSNSCTL register (Temperature Sensor Control) */
    MCU_ASYSCTL_LOCK_ANAREFCTL   = 0x002U, /**< Lock ANAREFCTL register (Analog Reference Control) */
    MCU_ASYSCTL_LOCK_VMONCTL     = 0x004U, /**< Lock VMONCTL register (Voltage Monitor Control) */
    MCU_ASYSCTL_LOCK_CMPHPMXSEL  = 0x020U, /**< Lock CMPHPMXSEL register (CMPSS HP positive mux CMP1-CMP10) */
    MCU_ASYSCTL_LOCK_CMPLPMXSEL  = 0x040U, /**< Lock CMPLPMXSEL register (CMPSS LP positive mux CMP1-CMP10) */
    MCU_ASYSCTL_LOCK_CMPHNMXSEL  = 0x080U, /**< Lock CMPHNMXSEL register (CMPSS HN negative mux) */
    MCU_ASYSCTL_LOCK_CMPLNMXSEL  = 0x100U, /**< Lock CMPLNMXSEL register (CMPSS LN negative mux) */
    MCU_ASYSCTL_LOCK_VREGCTL     = 0x200U, /**< Lock VREGCTL register (Voltage Regulator Control) */
    MCU_ASYSCTL_LOCK_CMPHPMXSEL1 = 0x800U, /**< Lock CMPHPMXSEL1 register (CMPSS HP positive mux CMP11-CMP12) */
    MCU_ASYSCTL_LOCK_CMPLPMXSEL1 = 0x1000U /**< Lock CMPLPMXSEL1 register (CMPSS LP positive mux CMP11-CMP12) */
} Mcu_ASysCtlLockType;

/** \brief This is a status value returned by the function Mcu_GetPllStatus of the MCU module. */
/*
 * Design: MCAL-21805, MCAL-21806
 */
typedef enum
{
    /** \brief PLL status Locked. */
    MCU_PLL_LOCKED = 0U,
    /** \brief PLL status Unlocked. */
    MCU_PLL_UNLOCKED = 1U,
    /** \brief PLL status undefined. */
    MCU_PLL_STATUS_UNDEFINED = 2U
} Mcu_PllStatusType;

/** \brief This type specifies the identification (ID) for a ClockType status used by Mcu_InitClock.
 */
/*
 * Design: MCAL-21808, MCAL-21807
 */
typedef uint8 Mcu_ClockType;

/** \brief This is the type of the reset enumerator containing the subset of reset types.  */
/*
 * Design: MCAL-21810, MCAL-21809, MCAL-21919
 */
typedef enum
{
    /** \brief Power On reset. */
    MCU_POWER_ON_RESET = 0U,
    /** \brief External reset. */
    MCU_EXTERNAL_RESET = 1U,
    /** \brief NMI Watchdog reset */
    MCU_ESM_NMI_WATCHDOG_RESET = 2U,
    /** \brief Watchdog reset  */
    MCU_WATCHDOG_RESET = 3U,
    /** \brief Simulation of external reset  */
    MCU_SW_RESET = 4U,
    /** \brief ESM reset  */
    MCU_ESM_RESET = 5U,
    /** \brief UNDEFINED reset  */
    MCU_RESET_UNDEFINED = 6U
} Mcu_ResetType;

/** \brief This type specifies the identification (ID) for a RAW reset status returned by
 * Mcu_GetResetRawValue*/
/*
 * Design: MCAL-21811, MCAL-21812
 */
typedef uint32 Mcu_RawResetType;

/** \brief This type specifies the identification (ID) for a MCU low power mode used in
 * Mcu_SetMode.*/
/*
 * Design: MCAL-21813, MCAL-21814
 */
typedef uint8 Mcu_ModeType;

/** \brief This type specifies the identification (ID) for a RAM section used in
 * Mcu_InitRamSection.*/
/*
 * Design: MCAL-21815, MCAL-21816
 */
typedef uint8 Mcu_RamSectionType;

/** \brief This is a status value returned by the function Mcu_GetRamState of the MCU module.*/
typedef enum
{
    /** \brief Ram state status invalid  */
    MCU_RAMSTATE_INVALID = 0U,
    /** \brief Ram state status valid  */
    MCU_RAMSTATE_VALID = 1U,
} Mcu_RamStateType;

/** \brief Forward declaration of Mcu_PeripheralConfigType for peripheral configuration */
struct Mcu_PeripheralConfigType_s;

/** \brief MCU CONFIG ROOT structure */
/*
 * Design: MCAL-21800, MCAL-21801, MCAL-21802, MCAL-21803, MCAL-21804
 */
typedef struct Mcu_ConfigType_s
{
    /** \brief Configuration of device clock config settings  */
    Mcu_ClockConfigPtrType Mcu_ClockConfig;
    /** \brief Configuration of Ram Sections */
    Mcu_RamConfigPtrType   Mcu_ConfigRamSection;
    /** \brief Simulated Reset ID for Mcu_PerformReset */
    Mcu_ResetType          Mcu_ResetSetting;
    /** \brief Configuration of MCU Modes */
    Mcu_ModeConfigPtrType  Mcu_ModeConfig;
    /** \brief Number of entries in Mcu_ClockConfig */
    uint8                  Mcu_ClockSetting;
    /** \brief Number of entries in Mcu_ConfigRamSection */
    uint8                  Mcu_NumberOfRamSectors;
    /** \brief Number of entries in Mcu_ModeConfig */
    uint8                  Mcu_NumberOfLowPowerModes;
    /** \brief Clock fail notification flag */
    boolean                Mcu_EnableClkFailNotification;
    /** \brief Peripheral configuration for CPU/Frame assignment */
    P2CONST(struct Mcu_PeripheralConfigType_s, AUTOMATIC, MCU_APPL_CONST) PeripheralConfig;
    /** \brief CPU1 Lockstep enable configuration */
    boolean Mcu_LockstepEnable;
    /** \brief ASysCtl (Analog System Control) configuration pointer */
    P2CONST(Mcu_ASysCtlConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_ASysCtlConfig;
    /** \brief CMPSS ASysCtl mux select configuration pointer */
    P2CONST(Mcu_CMPSSASysCtlConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_CMPSSASysCtlConfig;
} Mcu_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

#if (STD_ON == MCU_CFG_GET_VERSION_INFO_API)
/** \brief This service provides the version information of MCU module
 *
 * \param[in] versioninfo - Pointer to MCU driver version information.
 * \pre This API is available only if MCU_CFG_GET_VERSION_INFO_API is STD_ON
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif /* MCU_CFG_GET_VERSION_INFO_API */

/** \brief This service initializes the MCU driver
 *
 * This API is used to configure MCU settings for PLL and clock.
 * This API is used to configure RAM section settings and Power mode settings.
 *
 * \param[in] CfgPtr - Pointer to MCU driver configuration set.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, MCU_CONFIG_DATA, MCU_CONFIG_DATA) CfgPtr);

/** \brief This service initializes the RAM section wise with default values supplied in
 *configuration set
 *
 * This service initializes the RAM section wise.
 *
 * \param[in] RamSection Selects RAM memory section provided in configuration set
 * \pre None
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection);

#if (STD_ON == MCU_CFG_INIT_CLOCK_API)
/** \brief This service initializes the PLL and other MCU specific clock options
 *
 * This API is used to initializate clock & PLL
 * This API is used to Set CPU timer clock, XCLKOUT, Ethercat clock, Peripheral clocks, MCAN module
 *clocks
 *
 * \param[in] ClockSetting Selects clock section details provided in configuration set
 * \pre This API is available only if MCU_CFG_INIT_CLOCK_API is STD_ON
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted.
 * \retval E_NOT_OK: command has not been accepted
 *
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting);
#endif /*MCU_CFG_INIT_CLOCK_API*/

#if (STD_OFF == MCU_CFG_NO_PLL)
/** \brief This service activates the PLL clock to the MCU clock distribution.
 *
 * This API is used to distribute the PLL clock
 *
 * \pre This API is available only if MCU_CFG_NO_PLL is STD_OFF
 * \post None
 * \return Std_ReturnType
 * \retval E_OK: command has been accepted.
 * \retval E_NOT_OK: command has not been accepted
 *********************************************************************************************************************/
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(void);
#endif /*MCU_CFG_NO_PLL*/

/** \brief This service provides the lock status of the PLL.
 *
 * \pre None
 * \post None
 * \return Mcu_PllStatusType - PLL Status
 * \retval MCU_PLL_LOCKED: PLL is in locked state.
 *         MCU_PLL_UNLOCKED: PLL is in unlocked state.
 *         MCU_PLL_STATUS_UNDEFINED: Pre-compile McuNoPll is set to true.
 *********************************************************************************************************************/
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(void);

/** \brief This service provides the system clock.
 *
 * \pre None
 * \post None
 * \return Mcu_SysClk - System clock
 * \retval PllSysclk

 *********************************************************************************************************************/
FUNC(uint32, MCU_CODE) Mcu_GetSystemClock(void);

/** \brief The service reads the reset reason from the hardware.
 *
 * This API reads the reset value from hardware and returns from the list
 * of reset types defined in Mcu_ResetType.
 *
 * \pre None
 * \post None
 * \return Mcu_ResetType - Reset Type
 * \retval MCU_POWER_ON_RESET:         Power On reset
 * \retval MCU_EXTERNAL_RESET:         External reset
 * \retval MCU_ESM_NMI_WATCHDOG_RESET: NMI Watchdog reset
 * \retval MCU_WATCHDOG_RESET:         Watchdog reset
 * \retval MCU_SW_RESET:               Simulation of external reset
 * \retval MCU_ESM_RESET:              ESM reset
 * \retval MCU_RESET_UNDEFINED:        UNDEFINED reset
 *********************************************************************************************************************/
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(void);

/** \brief The service reads the raw reset value from the hardware register.
 *
 * This API reads the reset value from hardware and returns it.
 *
 * \pre None
 * \post None
 * \return Mcu_RawResetType - Reset raw value
 * \retval Reset raw value
 *
 *********************************************************************************************************************/
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue(void);

#if (STD_ON == MCU_CFG_PERFORM_RESET_API)
/** \brief The service performs a microcontroller reset
 *
 * This API perform simulation of external reset only
 *
 * \pre This API is available only if MCU_CFG_PERFORM_RESET_API is STD_ON
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_PerformReset(void);
#endif /* MCU_CFG_PERFORM_RESET_API */

/** \brief The service activates low power modes
 *
 * This API is used to activate the low power modes IDLE & STANDBY
 *
 * \param[in] McuMode - ID to select one MCU mode setting from the list provided in configuration
 *set
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_SetMode(Mcu_ModeType McuMode);

/** \brief Selects the internal analog test node connected to the analog test bus.
 *
 * This API is used to set the internal test node in ASysCtl
 *
 * \param[in] TestNode  Test node selection value.
 * \pre  Mcu_Init() must have been called.
 * \post INTERNALTESTCTL.TESTSEL reflects the requested node.
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_ASysCtl_SelectInternalTestNode(VAR(Mcu_ASysCtlTestNodeType, AUTOMATIC) TestNode);

/** \brief Configures the ADC Global SOC Force Select register (ADCSOCFRCGBSEL).
 *
 *  Writes ADCSOCFRCGBSEL at the given base address with the ADC instance select mask,
 *  selecting which ADC instances participate in the global software trigger.
 *
 * \param[in] BaseAddr   Base address of the ADC global register block
 * \param[in] AdcSelect  ADC instance selection mask (e.g. ASYSCTL_ADCSOCFRCGBSEL_ADCA, etc.)
 * \pre  Mcu_Init() must have been called.
 * \post ADCSOCFRCGBSEL register written with AdcSelect.
 * \return None
 * \retval None
 * \note This API is a general-purpose ASysCtl service and is available unconditionally
 *       (not gated by a feature-specific compile switch). It is intended to be called by
 *       any module that requires ADC global SOC instance selection (e.g. Cdd_Adc when
 *       CDD_ADC_GLBSW_TRIG_API is STD_ON).
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE)
Mcu_ASysCtl_ConfigADCGlobalSOC(VAR(uint32, AUTOMATIC) BaseAddr, VAR(uint8, AUTOMATIC) AdcSelect);

/** \brief Forces the ADC Global SOC trigger register (ADCSOCFRCGB).
 *
 *  Writes ADCSOCFRCGB at the given base address with the SOC mask to simultaneously
 *  trigger the selected SOCs across all ADC instances configured via ADCSOCFRCGBSEL.
 *
 * \param[in] BaseAddr  Base address of the ADC global register block
 * \param[in] SocMask   SOC trigger mask (one bit per SOC to trigger)
 * \pre  Mcu_Init() must have been called.
 * \post ADCSOCFRCGB register written with SocMask.
 * \return None
 * \retval None
 * \note This API is a general-purpose ASysCtl service and is available unconditionally
 *       (not gated by a feature-specific compile switch). It is intended to be called by
 *       any module that requires ADC global SOC force triggering (e.g. Cdd_Adc when
 *       CDD_ADC_GLBSW_TRIG_API is STD_ON).
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_ASysCtl_ForceADCGlobalSOC(VAR(uint32, AUTOMATIC) BaseAddr, VAR(uint32, AUTOMATIC) SocMask);

/** \brief Configures the EPWM XLINK feature by writing the EPWMXLINKCFG register.
 *
 *  Writes the EPWMXLINKCFG register at DEVCFG_BASE to enable the XLINK feature
 *  for the specified ePWM instances. Uses read-modify-write to set only the
 *  requested bits without affecting other instances.
 *
 *  The EPWMXLinkMask parameter is a bitwise OR of SYSCTL_EPWMXLINKCFG_EPWMn macros:
 *    - SYSCTL_EPWMXLINKCFG_EPWM1  (0x00001U) — Enable EPWM1  for XLINK
 *    - SYSCTL_EPWMXLINKCFG_EPWM2  (0x00002U) — Enable EPWM2  for XLINK
 *    - ...
 *    - SYSCTL_EPWMXLINKCFG_EPWM18 (0x20000U) — Enable EPWM18 for XLINK
 *
 * \param[in] EPWMXLinkMask  Bitmask of SYSCTL_EPWMXLINKCFG_EPWMn bits to enable
 *
 * \pre  Mcu_Init() must have been called.
 * \post EPWMXLINKCFG register OR-updated with EPWMXLinkMask.
 * \return None
 * \retval None
 * \note This API is intended to be called by Cdd_Pwm when the XLINK feature is
 *       enabled for an ePWM instance. The register is at DEVCFG_BASE and is
 *       exclusively writable by CPU1.LINK2.
 *
 *********************************************************************************************************************/
FUNC(void, MCU_CODE) Mcu_SysCtl_ConfigEPWMXLink(VAR(uint32, AUTOMATIC) EPWMXLinkMask);

/** \brief Commits (locks) the specified ASysCtl registers.
 *
 * This function applies the one-time write-lock to ASysCtl registers
 * (ASYSCTL_O_LOCK) for the registers specified by LockMask.
 * Lock bits are irreversible until system reset.
 *
 * Values of Mcu_ASysCtlLockType can be OR-combined to lock multiple registers:
 *   - MCU_ASYSCTL_LOCK_TSNSCTL    — Temperature Sensor Control
 *   - MCU_ASYSCTL_LOCK_ANAREFCTL  — Analog Reference Control
 *   - MCU_ASYSCTL_LOCK_VMONCTL    — Voltage Monitor Control
 *   - MCU_ASYSCTL_LOCK_CMPHPMXSEL — CMPSS HP positive mux (CMP1-CMP10)
 *   - MCU_ASYSCTL_LOCK_CMPLPMXSEL — CMPSS LP positive mux (CMP1-CMP10)
 *   - MCU_ASYSCTL_LOCK_CMPHNMXSEL — CMPSS HN negative mux
 *   - MCU_ASYSCTL_LOCK_CMPLNMXSEL — CMPSS LN negative mux
 *   - MCU_ASYSCTL_LOCK_VREGCTL    — Voltage Regulator Control
 *   - MCU_ASYSCTL_LOCK_CMPHPMXSEL1 — CMPSS HP positive mux (CMP11-CMP12)
 *   - MCU_ASYSCTL_LOCK_CMPLPMXSEL1 — CMPSS LP positive mux (CMP11-CMP12)
 *
 * \param[in] LockMask  Bitmask of Mcu_ASysCtlLockType values to lock
 *
 * \pre Mcu_Init() must be called before calling this function.
 * \post Specified ASysCtl registers are locked until next system reset.
 * \return None
 * \retval None
 *
 ****************************************************************************/
FUNC(void, MCU_CODE) Mcu_ASysCtl_CommitLock(VAR(Mcu_ASysCtlLockType, AUTOMATIC) LockMask);

#if (STD_ON == MCU_CFG_GET_RAM_STATE_API)
/** \brief This service provides the actual status of the microcontroller Ram
 *
 * This API is not checking actual RAM status. So no actions are performed and returns RAM VALID
 *
 * \pre This API is available only if MCU_CFG_GET_RAM_STATE_API is STD_ON
 * \post None
 * \return Mcu_RamStateType  - Ram State Type
 * \retval MCU_RAMSTATE_INVALID:  Invalid Ram status
 * \retval MCU_RAMSTATE_VALID:    Valid Ram status
 *
 *********************************************************************************************************************/
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_GetRamState(void);
#endif /* MCU_CFG_GET_RAM_STATE_API */

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* MCU_H */
/*********************************************************************************************************************
 *  End of File: Mcu.h
 *********************************************************************************************************************/
