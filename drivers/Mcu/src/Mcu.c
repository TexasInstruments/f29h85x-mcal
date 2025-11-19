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
 *  File:       Mcu.c
 *  Generator:  None
 *
 *  Description:  This file contains interface for Mcu Drv functions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 * Design: MCAL-21785
 */
#include "Mcu.h"
#include "Mcu_Priv.h"

/*
 * Design: MCAL-21799,  MCAL-21850, MCAL-21849
 */
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
#include "Det.h"
#endif /*MCU_CFG_DEV_ERROR_DETECT*/

#if (STD_ON == MCU_CFG_DEM_ENABLE)
#include "Dem.h"
#endif /*MCU_CFG_DEM_ENABLE*/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* AUTOSAR version information check has to match definition in header file */
#if ((MCU_AR_RELEASE_MAJOR_VERSION != (0x04U)) || (MCU_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
     (MCU_AR_RELEASE_REVISION_VERSION != (0x01U)))
#error "MCU: AUTOSAR Version Numbers of MCU are different"
#endif

/* vendor specific version information is BCD coded */
#if ((MCU_SW_MAJOR_VERSION != (2U)) || (MCU_SW_MINOR_VERSION != (0U)))
#error "Version numbers of Mcu.c and Mcu.h are inconsistent!"
#endif

#if ((MCU_CFG_MAJOR_VERSION != (2U)) || (MCU_CFG_MINOR_VERSION != (0U)))
#error "Version numbers of Mcu.c and Mcu_Cfg.h are inconsistent!"
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

#define MCU_START_SEC_VAR_INIT_BOOLEAN
#include "Mcu_MemMap.h"

#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
/* Global Init Done flag */
static VAR(boolean, MCU_VAR_INIT) Mcu_InitDone = FALSE;
#endif /*MCU_CFG_DEV_ERROR_DETECT*/

#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_PTR
#include "Mcu_MemMap.h"

/* Global configuration structure object */
P2CONST(Mcu_ConfigType, MCU_CONFIG_DATA, MCU_CONFIG_DATA) Mcu_ConfigObj = NULL_PTR;

#define MCU_STOP_SEC_VAR_INIT_PTR
#include "Mcu_MemMap.h"

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/** \brief Mcu_ReportClockFailure - This API will report clock failure error to DEM module
 *
 * \param[in] Value set clock functionality return value E_OK or E_NOT_OK
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 *********************************************************************************************************************/
static FUNC(void, MCU_CODE) Mcu_ReportClockFailure(Std_ReturnType Value);

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

#if (STD_ON == MCU_CFG_GET_VERSION_INFO_API)
FUNC(void, MCU_CODE) Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_GET_VERSION_INFO, MCU_E_PARAM_POINTER);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        versioninfo->vendorID         = (MCU_VENDOR_ID);
        versioninfo->moduleID         = (MCU_MODULE_ID);
        versioninfo->sw_major_version = (uint8)(MCU_SW_MAJOR_VERSION);
        versioninfo->sw_minor_version = (uint8)(MCU_SW_MINOR_VERSION);
        versioninfo->sw_patch_version = (uint8)(MCU_SW_PATCH_VERSION);
    }
}
#endif /*MCU_CFG_GET_VERSION_INFO_API*/

/*
 * Design: MCAL-21817, MCAL-21857, MCAL-21818, MCAL-21819, MCAL-21820, MCAL-21821, MCAL-21822
 */
FUNC(void, MCU_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, MCU_CONFIG_DATA, MCU_CONFIG_DATA) CfgPtr)
{
    P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_CONFIG_DATA)
    config_ptr = NULL_PTR; /* Config pointer initialised with NULL_PTR */
#if (STD_ON == MCU_CFG_PRE_COMPILE_VARIANT)
    if (NULL_PTR == CfgPtr)
    {
        config_ptr = &MCU_INIT_CONFIG_PC;
    }
#else
    if (NULL_PTR != CfgPtr)
    {
        /* Assigning passed module configuration to Config pointer incase of Post Build variant */
        config_ptr = CfgPtr;
    }
#endif /*MCU_CFG_PRE_COMPILE_VARIANT*/

    if (NULL_PTR == config_ptr)
    {
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
        /* API is being called with invalid config param */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT, MCU_E_PARAM_CONFIG);
#endif /* STD_ON == MCU_CFG_DEV_ERROR_DETECT */
    }
    else
    {
        /* Save the pointer to configuration */
        Mcu_ConfigObj = config_ptr;
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
        /* Set Init Done flag */
        Mcu_InitDone = TRUE;
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    }
}

/*
 * Design: MCAL-21823, MCAL-21824, MCAL-21854, MCAL-21856
 */
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    VAR(Std_ReturnType, AUTOMATIC) init_ramsection_return = (Std_ReturnType)E_NOT_OK;

#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT_RAMSECTION, MCU_E_UNINIT);
    }
    else if (RamSection > Mcu_ConfigObj->Mcu_NumberOfRamSectors)
    {
        /* API is being called with an invalid parameter */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT_RAMSECTION, MCU_E_PARAM_RAMSECTION);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        P2CONST(Mcu_RamSectionConfigType, AUTOMATIC, MCU_APPL_CONST)
        ramsection_config_ptr = &Mcu_ConfigObj->Mcu_ConfigRamSection[RamSection];

        /* Check for Ram Section Base Address pointer validity */
        if (NULL_PTR != ramsection_config_ptr->Mcu_RamSectionBaseAddress)
        {
            /* Fill Ram sections with configured data */
            Mcu_FillRamSection(ramsection_config_ptr);

            init_ramsection_return = (Std_ReturnType)E_OK;
        }
        else
        {
            /* Do Nothing */
        }
    }
    return (init_ramsection_return);
}

/*
 * Design: MCAL-21825, MCAL-21826, MCAL-21827, MCAL-21828, MCAL-21790,
 * Design: MCAL-21794, MCAL-21795, MCAL-21796, MCAL-21797, MCAL-21798,
 * Design: MCAL-21852, MCAL-21856
 */
#if (STD_ON == MCU_CFG_INIT_CLOCK_API)
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;
    P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST)
    clk_config_ptr = &Mcu_ConfigObj->Mcu_ClockConfig[ClockSetting];

#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT_CLOCK, MCU_E_UNINIT);
    }
    else if (ClockSetting > Mcu_ConfigObj->Mcu_ClockSetting)
    {
        /* API is being called with an invalid parameter */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT_CLOCK, MCU_E_PARAM_CLOCK);
    }
    else if ((Std_ReturnType)E_NOT_OK == Mcu_InitClockParamCheck(clk_config_ptr))
    {
        /* API is being called with an invalid mode parameter */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_INIT_CLOCK, MCU_E_PARAM_CONFIG);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        /* Assuming the CLKCFG, CPUx_PER_CFG registers are unlocked after a reset. */

        /* Initialize the clock */
        return_value = Mcu_SetClock(clk_config_ptr);

#if (STD_ON == MCU_CLOCK_CONFIG_LOCK_CRITICAL_REGISTERS)
        /* Locks all Clock configuration registers */
        Mcu_LockClockConfigRegisters();
#endif

#if (STD_ON == MCU_CPU_PERIPHERAL_CONFIG_LOCK_CRITICAL_REGISTERS)
        /* Locks all Cpu Peripheral configuration registers */
        Mcu_LockCpuPeripheralConfigRegisters();
#endif

        Mcu_ReportClockFailure(return_value);
    }

    return (return_value);
}
#endif /*MCU_CFG_INIT_CLOCK_API*/

/*
 * Design: MCAL-21829, MCAL-21830, MCAL-21831, MCAL-21832, MCAL-21833,
 * Design: MCAL-21855, MCAL-21856
 */
#if (STD_OFF == MCU_CFG_NO_PLL)
FUNC(Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(void)
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = (Std_ReturnType)E_NOT_OK;

    /* Development Error Detection */
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_DISTRIBUTE_PLL_CLOCK, MCU_E_UNINIT);
    }
    else if (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* API is being called before PLL is locked*/
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_DISTRIBUTE_PLL_CLOCK, MCU_E_PLL_NOT_LOCKED);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        /* Enable PLLSYSCLK is fed from system PLL clock */
        Mcu_EnablePll();

        return_value = (Std_ReturnType)E_OK;
    }
    return (return_value);
}
#endif /*MCU_CFG_NO_PLL*/

/*
 * Design: MCAL-21834, MCAL-21835, MCAL-21836, MCAL-21856
 */
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(void)
{
    VAR(Mcu_PllStatusType, AUTOMATIC) pll_status = MCU_PLL_STATUS_UNDEFINED;

#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_GET_PLL_STATUS, MCU_E_UNINIT);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
#if (STD_ON == MCU_CFG_NO_PLL)
        /* Return the PLL status as undefined*/
#else /*MCU_CFG_NO_PLL*/
        if ((uint16)0U == Mcu_IsPllLocked())
        {
            pll_status = MCU_PLL_UNLOCKED;
        }
        else
        {
            pll_status = MCU_PLL_LOCKED;
        }
#endif
    }

    return (pll_status);
}

/*
 * Design: MCAL-21837, MCAL-21838, MCAL-21789, MCAL-21856
 */
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(void)
{
    VAR(Mcu_ResetType, AUTOMATIC) reset_reason      = MCU_RESET_UNDEFINED;
    VAR(Mcu_RawResetType, AUTOMATIC) raw_reset_type = MCU_ERRORRST_MASK;

#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_GET_RESET_REASON, MCU_E_UNINIT);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        /* Get raw reset reason */
        raw_reset_type = (Mcu_RawResetType)Mcu_GetResetCause();

        /* Interpret the raw reset value and conver it to reset reason */
        reset_reason = Mcu_ConvertResetReason(raw_reset_type);

        /* Clear reset reason to be able to identify other reset reasons */
        Mcu_ClearReset(raw_reset_type);
    }

    return (reset_reason);
}

/*
 * Design: MCAL-21839, MCAL-21840, MCAL-21856
 */
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue(void)
{
    VAR(Mcu_RawResetType, AUTOMATIC) raw_reset_type = MCU_ERRORRST_MASK;
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_GET_RESET_RAW_VALUE, MCU_E_UNINIT);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        /* Get raw reset reason */
        raw_reset_type = (Mcu_RawResetType)Mcu_GetResetCause();

        /* Clear reset reason to be able to identify other reset reasons */
        Mcu_ClearReset(raw_reset_type);
    }
    return (raw_reset_type);
}

/*
 * Design: MCAL-21841, MCAL-21842, MCAL-21843, MCAL-21844, MCAL-21788, MCAL-21856
 */
#if (STD_ON == MCU_CFG_PERFORM_RESET_API)
FUNC(void, MCU_CODE) Mcu_PerformReset(void)
{
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_PERFORM_RESET, MCU_E_UNINIT);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        /* Only Software reset (i.e simualtion of XRS) should be performed */
        Mcu_PerformControllerReset();
    }
}
#endif /*MCU_CFG_PERFORM_RESET_API*/

/*
 * Design: MCAL-21845, MCAL-21846, MCAL-21791, MCAL-21792, MCAL-21853, MCAL-21856
 */
FUNC(void, MCU_CODE) Mcu_SetMode(Mcu_ModeType McuMode)
{
    P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST)
    mode_config_ptr = &Mcu_ConfigObj->Mcu_ModeConfig[McuMode];
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_SET_MODE, MCU_E_UNINIT);
    }
    else if (McuMode > Mcu_ConfigObj->Mcu_NumberOfLowPowerModes)
    {
        /* API is being called with an invalid mode parameter */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_SET_MODE, MCU_E_PARAM_MODE);
    }
    else if ((Std_ReturnType)E_NOT_OK == Mcu_SetModeParamCheck(mode_config_ptr))
    {
        /* DET Error reported */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_SET_MODE, MCU_E_PARAM_CONFIG);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        /* Assuming CPUSYSLOCK Register is unlocked after Reset: */

        /* Sets and Enter in to low power modes*/
        Mcu_EnterLowPowerMode(mode_config_ptr);

#if (STD_ON == MCU_CPU_SYSTEM_LOCK_CRITICAL_REGISTERS)
        /* Locks Cpu system register: LPMCR */
        Mcu_LockCpuSysRegisters();
#endif
    }
}

/*
 * Design: MCAL-21847, MCAL-21848, MCAL-21856
 */
#if (STD_ON == MCU_CFG_GET_RAM_STATE_API)
FUNC(Mcu_RamStateType, MCU_CODE) Mcu_GetRamState(void)
{
    VAR(Mcu_RamStateType, AUTOMATIC) ram_state_type = MCU_RAMSTATE_INVALID;
#if (STD_ON == MCU_CFG_DEV_ERROR_DETECT)
    if ((boolean)FALSE == Mcu_InitDone)
    {
        /* API is being called before calling Mcu_Init */
        (void)Det_ReportError(MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SID_GET_RAM_STATE, MCU_E_UNINIT);
    }
    else
#endif /*MCU_CFG_DEV_ERROR_DETECT*/
    {
        /* Always return RAM Valid status only */
        ram_state_type = MCU_RAMSTATE_VALID;
    }
    return (ram_state_type);
}
#endif /*MCU_CFG_GET_RAM_STATE_API*/

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
/*
 * Design: MCAL-28521
 */
static FUNC(void, MCU_CODE) Mcu_ReportClockFailure(Std_ReturnType Value)
{
    if ((Std_ReturnType)E_NOT_OK == Value)
    {
        if ((boolean)TRUE == Mcu_ConfigObj->Mcu_EnableClkFailNotification)
        {
#ifdef MCU_E_CLOCK_FAILURE
            (void)Dem_SetEventStatus(MCU_E_CLOCK_FAILURE, DEM_EVENT_STATUS_FAILED);
#endif
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

/*********************************************************************************************************************
 *  End of File: Mcu.c
 *********************************************************************************************************************/
