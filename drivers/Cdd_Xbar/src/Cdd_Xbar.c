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
 *  File:       Cdd_Xbar.c
 *  Generator:  None
 *
 *  Description:  Interface source file for CDD XBar module.
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Xbar.h"
#include "Cdd_Xbar_Priv.h"
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
/*
 *  AUTOSAR version information check has to match definition in header file
 */
#if ((CDD_XBAR_AR_RELEASE_MAJOR_VERSION != (0x04U)) || \
    (CDD_XBAR_AR_RELEASE_MINOR_VERSION != (0x03U)) || \
    (CDD_XBAR_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "CDD XBAR: AUTOSAR Version Numbers of CDD XBAR are different"
#endif

/* vendor specific version information is BCD coded */
#if ((CDD_XBAR_SW_MAJOR_VERSION != (1U)) || (CDD_XBAR_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Xbar.c and Cdd_Xbar.h are inconsistent!"
#endif

#if ((CDD_XBAR_CFG_MAJOR_VERSION != (1U)) || (CDD_XBAR_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Cdd_Xbar_Cfg.c and Cdd_Xbar_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/
/* None */

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

#define CDD_XBAR_START_SEC_VAR_INIT_8
#include "Cdd_Xbar_MemMap.h"

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
/** \brief Internal Driver Status */
VAR(Cdd_Xbar_StatusType, CDD_XBAR_VAR_INIT) Cdd_Xbar_DriverStatus = CDD_XBAR_UNINIT;
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

#define CDD_XBAR_STOP_SEC_VAR_INIT_8
#include "Cdd_Xbar_MemMap.h"

#define CDD_XBAR_START_SEC_VAR_INIT_PTR
#include "Cdd_Xbar_MemMap.h"

 /* Global configuration structure object */
P2CONST(Cdd_Xbar_ConfigType, CDD_XBAR_CONFIG_DATA, CDD_XBAR_CONFIG_DATA) Cdd_Xbar_Config = NULL_PTR;

#define CDD_XBAR_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Xbar_MemMap.h"

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_Type_Output_Valid(Cdd_Xbar_HwUnitType Crossbar, uint8 ServID);
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_Type_Input_Valid(Cdd_Xbar_HwUnitType Crossbar,  uint32 InputLine, uint8 ServID);
#endif /*STD_ON == CDD_XBAR_DEV_ERROR_DETECT*/
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

#define CDD_XBAR_START_SEC_CODE
#include "Cdd_Xbar_MemMap.h"

#if (STD_ON == CDD_XBAR_API_ENABLE)
#if (STD_ON == CDD_XBAR_GET_VERSION_INFO_API)
/*
 * Design: MCAL-25737, MCAL-25738
 */
FUNC(void, CDD_XBAR_CODE)
Cdd_Xbar_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC,CDD_XBAR_APPL_DATA) VersionInfoPtr)  
{
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,CDD_XBAR_SID_GET_VERSION_INFO,
            CDD_XBAR_E_PARAM_POINTER);
    }
    else
#endif
    {
        VersionInfoPtr->vendorID         =          CDD_XBAR_VENDOR_ID;
        VersionInfoPtr->moduleID         =          CDD_XBAR_MODULE_ID;
        VersionInfoPtr->instanceID       =          CDD_XBAR_INSTANCE_ID;
        VersionInfoPtr->sw_major_version = (uint8)  CDD_XBAR_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (uint8)  CDD_XBAR_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (uint8)  CDD_XBAR_SW_PATCH_VERSION;
    }
}
#endif /* STD_ON == CDD_XBAR_GET_VERSION_INFO_API */

/*
 * Design: MCAL-25733, MCAL-25734, MCAL-25735, MCAL-25736
 */
FUNC(void, CDD_XBAR_CODE) Cdd_Xbar_Init(P2CONST(Cdd_Xbar_ConfigType, AUTOMATIC, CDD_XBAR_CONFIG_DATA) ConfigPtr)
{
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC) crossbar;
    VAR(uint32, AUTOMATIC) inputline; 
    VAR(uint8, AUTOMATIC) config; 
    VAR(uint8, AUTOMATIC) input; 

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT != Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INIT, CDD_XBAR_E_INIT_ALREADY);
    }
#if (STD_ON == CDD_XBAR_PRE_COMPILE_VARIANT)
    else if (NULL_PTR != ConfigPtr)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INIT, CDD_XBAR_E_PARAM_POINTER);
    }
#endif /* STD_ON == CDD_XBAR_PRE_COMPILE_VARIANT */
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (STD_ON == CDD_XBAR_PRE_COMPILE_VARIANT)
        Cdd_Xbar_Config = &CDD_XBAR_PRE_COMPILE_VARIANT_CONFIG;

        /* Input XBar Configs */
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
        crossbar.crossbarType = CddXbarConf_CddXbarInputXbar;
        for (config = 0U; config < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS; config++)
        {
            crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputSelect;
            inputline = Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].inputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
            if (E_OK != Cdd_Xbar_Type_Output_Valid(crossbar, CDD_XBAR_SID_INIT))
            {
                /* This function will throw DET for invalid outputs selected */
            }
            else if (E_OK != Cdd_Xbar_Type_Input_Valid(crossbar, inputline, CDD_XBAR_SID_INIT))
            {
                /* This function will throw DET for invalid inputs */
            }
            else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
            {
                /* Select given Input Line */
                Cdd_Xbar_InSelect(crossbar, inputline, TRUE);
                /* Lock Crossbar Select Line */
                if (TRUE == Cdd_Xbar_Config->Cdd_Xbar_InputCfg[config].selectConfigLock)
                {
                    Cdd_Xbar_InSelectLock(crossbar);
                }
            }
        }
#endif /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/

        /* Output XBar Configs */
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.crossbarType = CddXbarConf_CddXbarOutputXbar;
        for (config = 0U; config < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS; config++)
        {
            crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
            if (E_OK != Cdd_Xbar_Type_Output_Valid(crossbar, CDD_XBAR_SID_INIT))
            {
                /* This function will throw DET for invalid outputs selected */
            }
            else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
            {
                for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].input_count; input++)
                {
                    inputline = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].inputLine[input];
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                    if (E_OK != Cdd_Xbar_Type_Input_Valid(crossbar, inputline, CDD_XBAR_SID_INIT))
                    {
                        /* This function will throw DET for invalid inputs */
                    }
                    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                    {
                        /* Select given Input Line */
                        Cdd_Xbar_OutSelect(crossbar,inputline, TRUE);
                    } 
                }
                /* Select Output Inversion for chosen destination line */
                Cdd_Xbar_OutOutputInvert(crossbar,Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputInversion);

                /* Output Pulse Stretch */
                Cdd_Xbar_OutputStretchPulse(crossbar.destinationLineNumber, Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputStretchPulse);

                /* Output Latch selection*/
                Cdd_Xbar_OutputLatchSelect(crossbar.destinationLineNumber, Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputLatch);

                /* Output inversion before latch selection*/
                Cdd_Xbar_OutputInvLatch(crossbar.destinationLineNumber, Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputInversionBeforeLatch);

                if(CDD_XBAR_OUTPUTCLEARFLAG == Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputFlag)
                {
                  /* Output crossbar output latch clear during init */
                  Cdd_Xbar_OutputLatchFlagClear(crossbar.destinationLineNumber);
                }
                else if(CDD_XBAR_OUTPUTFORCEFLAG == Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[config].outputFlag)
                {
                  /* Output crossbar output latch force during init */
                  Cdd_Xbar_OutputLatchFlagForce(crossbar.destinationLineNumber);
                }
                else
                {
                  /* Output crossbar output latch in default state */
                }
            } 
        }
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */

        /* Lock Output Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->outConfigLock)
        {
            Cdd_Xbar_OutLock();
        }

        /* EPWM XBar Configs */
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
        crossbar.crossbarType = CddXbarConf_CddXbarEpwmXbar;
        for (config = 0U; config < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS; config++)
        {
            crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
            if (E_OK != Cdd_Xbar_Type_Output_Valid(crossbar, CDD_XBAR_SID_INIT))
            {
                /* This function will throw DET for invalid outputs selected */
            }
            else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
            {
                for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].input_count; input++)
                {
                    inputline = Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].inputLine[input];
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                    if (E_OK != Cdd_Xbar_Type_Input_Valid(crossbar, inputline, CDD_XBAR_SID_INIT))
                    {
                        /* This function will throw DET for invalid inputs */
                    }
                    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                    {
                        /* Select given Input Line */
                        Cdd_Xbar_EpwmSelect(crossbar, inputline, TRUE);
                    } 
                }
                /* Select Output Inversion for chosen destination line */
                Cdd_Xbar_EpwmOutputInvert(crossbar, Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[config].outputInversion);
            } 
        }
#endif /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS */

        /* Lock EPWM Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->epwmConfigLock)
        {
            Cdd_Xbar_EpwmLock();
        }

        /* CLB XBar Configs */
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
        crossbar.crossbarType = CddXbarConf_CddXbarClbXbar;
        for (config = 0U; config < CDD_XBAR_CLB_XBAR_CONFIGURATIONS; config++)
        {
            crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
            if (E_OK != Cdd_Xbar_Type_Output_Valid(crossbar, CDD_XBAR_SID_INIT))
            {
                /* This function will throw DET for invalid outputs selected */
            }
            else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
            {
                for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].input_count; input++)
                {
                    inputline = Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].inputLine[input];
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                    if (E_OK != Cdd_Xbar_Type_Input_Valid(crossbar, inputline, CDD_XBAR_SID_INIT))
                    {
                        /* This function will throw DET for invalid inputs */
                    }
                    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                    {
                        /* Select given Input Line */
                        Cdd_Xbar_ClbSelect(crossbar, inputline, TRUE);
                    } 
                }
                /* Select Output Inversion for chosen destination line */
                Cdd_Xbar_ClbOutputInvert(crossbar, Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[config].outputInversion);
            } 
        }
#endif /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS */

        /* Lock CLB Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->clbConfigLock)
        {
            Cdd_Xbar_ClbLock();
        }

        /* MINDB XBar Configs */
        #if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
        crossbar.crossbarType = CddXbarConf_CddXbarMindbXbar;
        for (config = 0U; config < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS; config++)
        {
            crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
            if (E_OK != Cdd_Xbar_Type_Output_Valid(crossbar, CDD_XBAR_SID_INIT))
            {
                /* This function will throw DET for invalid outputs selected */
            }
            else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
            {
                for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].input_count; input++)
                {
                    inputline = Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].inputLine[input];
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                    if (E_OK != Cdd_Xbar_Type_Input_Valid(crossbar, inputline, CDD_XBAR_SID_INIT))
                    {
                        /* This function will throw DET for invalid inputs */
                    }
                    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                    {
                        /* Select given Input Line */
                        Cdd_Xbar_MdlSelect(crossbar, inputline, TRUE);
                    } 
                }
                /* Select Output Inversion for chosen destination line */
                Cdd_Xbar_MdlOutputInvert(crossbar, Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[config].outputInversion);
            } 
        }
#endif /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS */

        /* Lock MINDB Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->mindbConfigLock)
        {
            Cdd_Xbar_MdlLock();
        }

    /* ICL XBar Configs */
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
        crossbar.crossbarType = CddXbarConf_CddXbarIclXbar;
        for (config = 0U; config < CDD_XBAR_ICL_XBAR_CONFIGURATIONS; config++)
        {
            crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
            if (E_OK != Cdd_Xbar_Type_Output_Valid(crossbar, CDD_XBAR_SID_INIT))
            {
                /* This function will throw DET for invalid outputs selected */
            }
            else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
            {
                for (input = 0U; input < Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].input_count; input++)
                {
                    inputline = Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].inputLine[input];
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                    if (E_OK != Cdd_Xbar_Type_Input_Valid(crossbar, inputline, CDD_XBAR_SID_INIT))
                    {
                        /* This function will throw DET for invalid inputs */
                    }
                    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                    {
                        /* Select given Input Line */
                        Cdd_Xbar_IclSelect(crossbar, inputline, TRUE);
                    } 
                }
                /* Select Output Inversion for chosen destination line */
                Cdd_Xbar_IclOutputInvert(crossbar, Cdd_Xbar_Config->Cdd_Xbar_IclCfg[config].outputInversion);
            } 
        }
#endif /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS */

        /* Lock ICL Crossbar if selected */
        if (TRUE == Cdd_Xbar_Config->iclConfigLock)
        {
            Cdd_Xbar_IclLock();
        }
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    /* Update Driver Status to Init */
        Cdd_Xbar_DriverStatus = CDD_XBAR_INIT;
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */

#endif /* STD_ON == CDD_XBAR_PRE_COMPILE_VARIANT */
    }
}

/*
 * Design: MCAL-25739, MCAL-25740
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) \
Cdd_Xbar_SelectInput(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit, VAR(uint32, AUTOMATIC) InputLine, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_UNINIT);
    }
    else if (E_OK != Cdd_Xbar_Type_Input_Valid(crossbar, InputLine, CDD_XBAR_SID_SELECT_INPUT))
    {
        /* This function will throw DET for invalid inputs */
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    { 
        switch (crossbar.crossbarType)
        {
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarInputXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_InputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].inputSelect;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_InSelectLockStatus(crossbar))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_InSelect(crossbar, InputLine, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_OutLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_OutSelect(crossbar, InputLine, Selection);
                    retval = E_OK;
                }
                break;
 #endif /*0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_EpwmLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_EpwmSelect(crossbar, InputLine, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_ClbLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_ClbSelect(crossbar, InputLine, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_MdlLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_MdlSelect(crossbar, InputLine, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_IclCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_IclLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_IclSelect(crossbar, InputLine, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/
            default:
                /* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
               (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                    CDD_XBAR_SID_SELECT_INPUT, CDD_XBAR_E_PARAM_VALUE);
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
               break;
        }
    }

    return retval;
}

/*
 * Design: MCAL-25741, MCAL-25742
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) \
Cdd_Xbar_OutLatchSelect(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) LatchEnable)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  
  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_SELECT, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_SELECT, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_SELECT, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_SELECT, CDD_XBAR_E_LOCK);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        Cdd_Xbar_OutputLatchSelect(crossbar.destinationLineNumber, LatchEnable);
        retval = E_OK;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return retval;
}

/*
 * Design: MCAL-25741, MCAL-25742
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLatchSelectSts(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC)status = FALSE;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_SELECT_STS, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_SELECT_STS, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_SELECT_STS, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        status = Cdd_Xbar_OutputLatchSelectSts(crossbar.destinationLineNumber);
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return status;
}

/*
 * Design: MCAL-25743, MCAL-25744
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutLatchFlagStatus(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{

    VAR(boolean, AUTOMATIC)status = FALSE;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_STATUS, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_STATUS, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_STATUS, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        status = Cdd_Xbar_OutputLatchFlagStatus(crossbar.destinationLineNumber);
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return status;
}

/*
 * Design: MCAL-25743, MCAL-25744
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_OutLatchFlagForce(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
      if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_FORCE, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    { 
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_FORCE, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)) 
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_FORCE, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        Cdd_Xbar_OutputLatchFlagForce(crossbar.destinationLineNumber);
        retval = E_OK;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return retval;
}


/*
 * Design: MCAL-25743, MCAL-25744
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_OutLatchFlagClear(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_CLEAR, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_CLEAR, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)) 
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_LATCH_FLAG_CLEAR, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
    crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
    Cdd_Xbar_OutputLatchFlagClear(crossbar.destinationLineNumber);
    retval = E_OK;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return retval;
}

/*
 * Design: MCAL-25743, MCAL-25744
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_OutInvBeforeLatch(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_INV_BEFORE_LATCH, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_INV_BEFORE_LATCH, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_INV_BEFORE_LATCH, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_INV_BEFORE_LATCH, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        Cdd_Xbar_OutputInvLatch(crossbar.destinationLineNumber, Selection); 
        retval = E_OK;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return retval;
}


/*
 * Design: MCAL-25743, MCAL-25744
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_OutInvCheckBeforeLatch(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC)status = FALSE;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar; 

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_INV_CHECK_BEFORE_LATCH, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_INV_CHECK_BEFORE_LATCH, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)) 
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_INV_CHECK_BEFORE_LATCH, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        status = Cdd_Xbar_OutputInvLatchSts(crossbar.destinationLineNumber);
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return status;
}


/*
 * Design: MCAL-25745, MCAL-25746
 */
FUNC(Cdd_Xbar_OutputlevelType, CDD_XBAR_CODE) Cdd_Xbar_OutOutputSignal(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(Cdd_Xbar_OutputlevelType, AUTOMATIC) output = ((Cdd_Xbar_OutputlevelType) STD_LOW);
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_OUTPUT_SIGNAL, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_OUTPUT_SIGNAL, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)) 
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_OUTPUT_SIGNAL, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        /* Gather output from Output X-Bar Status Flag */
        output = Cdd_Xbar_OutOutputState(crossbar.destinationLineNumber);
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }
  
    return output;
}

/*
 * Design: MCAL-25747, MCAL-25748
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) \
Cdd_Xbar_OutStretchPulse(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit, VAR(Cdd_Xbar_TickStretchType, AUTOMATIC) TickStretch)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (TRUE == Cdd_Xbar_OutLockStatus())
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE, CDD_XBAR_E_LOCK);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((TickStretch != CDD_XBAR_SYSTICKS_STRETCH_OFF) && (TickStretch != CDD_XBAR_SYSTICKS_16) && (TickStretch != CDD_XBAR_SYSTICKS_32))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        Cdd_Xbar_OutputStretchPulse(crossbar.destinationLineNumber, TickStretch);
        retval = E_OK;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return retval;
}

/*
 * Design: MCAL-25749, MCAL-25750
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_OutStretchPulseClear(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE_CLEAR, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE_CLEAR, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE_CLEAR, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
    crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
    Cdd_Xbar_OutputStretchPulse(crossbar.destinationLineNumber, CDD_XBAR_SYSTICKS_STRETCH_OFF);
    retval = E_OK;
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return retval;
}

/*
 * Design: MCAL-25751, MCAL-25752
 */
FUNC(Cdd_Xbar_TickStretchType, CDD_XBAR_CODE) \
Cdd_Xbar_OutStretchPulseCheck(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(Cdd_Xbar_TickStretchType, AUTOMATIC)stretch = CDD_XBAR_SYSTICKS_STRETCH_OFF;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;  

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE_CHECK, CDD_XBAR_E_UNINIT);
    }
    else if (CddXbarConf_CddXbarOutputXbar != crossbar.crossbarType)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE_CHECK, CDD_XBAR_E_PARAM_VALUE);
    }
    else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_OUT_STRETCH_PULSE_CHECK, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
        crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
        stretch = Cdd_Xbar_OutputStretchGet(crossbar.destinationLineNumber);
#endif /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
    }

    return stretch;
}

/*
 * Design: MCAL-25753, MCAL-25754
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) \
Cdd_Xbar_SelectOutputInversion(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit, VAR(boolean, AUTOMATIC) Selection)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_UNINIT);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (crossbar.crossbarType)
        {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_OutLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_OutOutputInvert(crossbar, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_EpwmLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_EpwmOutputInvert(crossbar, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_ClbLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                         CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_ClbOutputInvert(crossbar, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_MdlLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_MdlOutputInvert(crossbar, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_IclCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_IclLockStatus())
                {
                  (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                    CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                  (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                    CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_IclOutputInvert(crossbar, Selection);
                    retval = E_OK;
                }
                break;
#endif /*0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/
            default:
                /* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                    CDD_XBAR_SID_SELECT_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
#else
                retval = E_OK;
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }
    return retval;
}

/*
 * Design: MCAL-25755, MCAL-25756
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_CheckOutputInversion(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC)status = FALSE;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_CHECK_OUTPUT_INVERSION, CDD_XBAR_E_UNINIT);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (crossbar.crossbarType)
        {
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_OutputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_CHECK_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_OutOutputInvertCheck(crossbar);
                }
              break;
#endif /*0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_EpwmCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_CHECK_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_EpwmOutputInvertCheck(crossbar);
                }
                break;
#endif /*0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_ClbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_CHECK_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_ClbOutputInvertCheck(crossbar);
                }
                break;
#endif /*0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_MindbCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_CHECK_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_MdlOutputInvertCheck(crossbar);
                }
                break;
#endif /*0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS*/
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_IclCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].outputLine;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                        CDD_XBAR_SID_CHECK_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_IclOutputInvertCheck(crossbar);
                }
                break;
#endif /*0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS*/
            default:
                /* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, 
                    CDD_XBAR_SID_CHECK_OUTPUT_INVERSION, CDD_XBAR_E_PARAM_VALUE);
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }
    return status;
}

/*
 * Design: MCAL-25757, MCAL-25758
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_Lock(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_UNINIT);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (crossbar.crossbarType)
        {
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarInputXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_InputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].inputSelect;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_InSelectLockStatus(crossbar))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_InSelectLock(crossbar);
                    retval = E_OK;
                }
                break;
 #endif  /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_OutLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_OutLock();
                    retval = E_OK;
                }
                break;
#endif  /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_EpwmLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_EpwmLock();
                    retval = E_OK;
                }
                break;
#endif  /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_ClbLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_ClbLock();
                    retval = E_OK;
                }
                break;
#endif  /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_MdlLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_MdlLock();
                    retval = E_OK;
                }
                break;
#endif  /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar: 
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (TRUE == Cdd_Xbar_IclLockStatus())
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,CDD_XBAR_SID_LOCK, CDD_XBAR_E_LOCK);
                }
                else if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
                }
              else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    Cdd_Xbar_IclLock();
                    retval = E_OK;
                }
                break;
#endif  /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS */
            default:
                /* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,CDD_XBAR_SID_LOCK, CDD_XBAR_E_PARAM_VALUE);
#else
                retval = E_OK;
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }
    return retval;
}


/*
 * Design: MCAL-25759, MCAL-25760
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_LockStatus(VAR(Cdd_XbarType, AUTOMATIC) CrossbarUnit)
{
    VAR(boolean, AUTOMATIC)status = FALSE;
    VAR(Cdd_Xbar_HwUnitType, AUTOMATIC)crossbar;

    crossbar.crossbarType = CDD_XBAR_GET_XBAR_TYPE(CrossbarUnit);

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_UNINIT);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        switch (crossbar.crossbarType)
        {
#if (0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarInputXbar:
                crossbar.destinationLineNumber = Cdd_Xbar_Config->Cdd_Xbar_InputCfg[CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit)].inputSelect;
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_INPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_InSelectLockStatus(crossbar);
                }
                break;
#endif  /* 0U < CDD_XBAR_INPUT_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarOutputXbar:
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_OutLockStatus();
                }
                break;
#endif  /* 0U < CDD_XBAR_OUTPUT_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarEpwmXbar:
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_EPWM_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID,CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_EpwmLockStatus();
                }
                break;
#endif  /* 0U < CDD_XBAR_EPWM_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarClbXbar:
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_CLB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_ClbLockStatus();
                }
                break;
#endif  /* 0U < CDD_XBAR_CLB_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarMindbXbar:
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_MINDB_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_PARAM_VALUE);
                }
                 else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_MdlLockStatus();
                }
                break;
#endif  /* 0U < CDD_XBAR_MINDB_XBAR_CONFIGURATIONS */
#if (0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS)
            case CddXbarConf_CddXbarIclXbar: 
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                if (CDD_XBAR_ICL_XBAR_CONFIGURATIONS <= CDD_XBAR_GET_XBAR_INSTANCE(CrossbarUnit))
                {
                    (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_PARAM_VALUE);
                }
                else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                {
                    status = Cdd_Xbar_IclLockStatus();
                }
                break;
#endif  /* 0U < CDD_XBAR_ICL_XBAR_CONFIGURATIONS */
            default:
              /* Type did not match any of the above.*/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
                (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_LOCKSTATUS, CDD_XBAR_E_PARAM_VALUE);
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
                break;
        }
    }
    return status;
}

#if (STD_ON == CDD_XBAR_INPUT_FLAG_API)
/*
 * Design: MCAL-xxxxx, MCAL-xxxxx
 */
FUNC(boolean, CDD_XBAR_CODE) Cdd_Xbar_InputFlagStatus(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag)
{
    VAR(boolean, AUTOMATIC)status = FALSE;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INPUTFLAGSTATUS, CDD_XBAR_E_UNINIT);
    }
    else if (((CDD_XBAR_INPUT_FLAG_NUMBER(InputFlag)) > (uint16)18U) || ((CDD_XBAR_INPUT_FLAG_BIT(InputFlag)) > (uint16)31U))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INPUTFLAGSTATUS, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        status = Cdd_Xbar_InFlagStatus(InputFlag);
    }

    return status;

}


/*
 * Design: MCAL-xxxxx, MCAL-xxxxx
 */
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_InputFlagClear(VAR(Cdd_Xbar_InputFlagType, AUTOMATIC) InputFlag)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;

#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
    if (CDD_XBAR_UNINIT == Cdd_Xbar_DriverStatus)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INPUTFLAGCLEAR, CDD_XBAR_E_UNINIT);
    }
    else if (((CDD_XBAR_INPUT_FLAG_NUMBER(InputFlag)) > (uint16)18U) || ((CDD_XBAR_INPUT_FLAG_BIT(InputFlag)) > (uint16)31U))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, CDD_XBAR_SID_INPUTFLAGCLEAR, CDD_XBAR_E_PARAM_VALUE);
    }
    else
#endif  /* STD_ON == CDD_XBAR_DEV_ERROR_DETECT */
    {
        Cdd_Xbar_InFlagClear(InputFlag);
        retval = E_OK;
    }

    return retval;

}

#endif /* STD_ON == CDD_XBAR_INPUT_FLAG_API */

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_Type_Output_Valid(Cdd_Xbar_HwUnitType Crossbar, uint8 ServID)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;

    if (Crossbar.destinationLineNumber == 0U)
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarInputXbar == Crossbar.crossbarType) && (Crossbar.destinationLineNumber > CDD_XBAR_INPUT_SELECT_COUNT))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarOutputXbar == Crossbar.crossbarType) && (Crossbar.destinationLineNumber > CDD_XBAR_OUTPUT_XBAR_OUTPUT_COUNT))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarEpwmXbar == Crossbar.crossbarType) && (Crossbar.destinationLineNumber > CDD_XBAR_EPWM_XBAR_OUTPUT_COUNT))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarClbXbar == Crossbar.crossbarType) && (Crossbar.destinationLineNumber > CDD_XBAR_CLB_XBAR_OUTPUT_COUNT))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarMindbXbar == Crossbar.crossbarType) && (Crossbar.destinationLineNumber > CDD_XBAR_MINDB_XBAR_OUTPUT_COUNT))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarIclXbar == Crossbar.crossbarType) && (Crossbar.destinationLineNumber > CDD_XBAR_ICL_XBAR_OUTPUT_COUNT))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else
    {
        retval = E_OK;
    }

    return retval;
}

FUNC(Std_ReturnType, CDD_XBAR_CODE) Cdd_Xbar_Type_Input_Valid(Cdd_Xbar_HwUnitType Crossbar,  uint32 InputLine, uint8 ServID)
{
    VAR(Std_ReturnType, AUTOMATIC)retval = E_NOT_OK;

    if ((CddXbarConf_CddXbarInputXbar == Crossbar.crossbarType) && (0xFFFFU < InputLine))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarOutputXbar == Crossbar.crossbarType) && ((CDD_XBAR_OUTPUT_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(InputLine)) || (CDD_XBAR_MAX_INPUT_LINES<=(InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarEpwmXbar == Crossbar.crossbarType) && ((CDD_XBAR_EPWM_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(InputLine)) || (CDD_XBAR_MAX_INPUT_LINES<=(InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarClbXbar == Crossbar.crossbarType) && ((CDD_XBAR_CLB_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(InputLine)) || (CDD_XBAR_MAX_INPUT_LINES<=(InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarMindbXbar == Crossbar.crossbarType) && ((CDD_XBAR_MINDB_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(InputLine)) || (CDD_XBAR_MAX_INPUT_LINES<=(InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else if ((CddXbarConf_CddXbarIclXbar == Crossbar.crossbarType) && ((CDD_XBAR_ICL_XBAR_MAX_GROUP <= CDD_XBAR_GET_GROUP_NUMBER(InputLine)) || (CDD_XBAR_MAX_INPUT_LINES<=(InputLine & (uint32)0xFFU))))
    {
        (void)Det_ReportError(CDD_XBAR_MODULE_ID, CDD_XBAR_INSTANCE_ID, ServID, CDD_XBAR_E_PARAM_VALUE);
    }
    else
    {
        retval = E_OK;
    }

    return retval;
}

#endif /*STD_ON == CDD_XBAR_DEV_ERROR_DETECT*/
#endif /* STD_ON == CDD_XBAR_API_ENABLE */ 

#define CDD_XBAR_STOP_SEC_CODE
#include "Cdd_Xbar_MemMap.h"


/*********************************************************************************************************************
 *  End of File: Cdd_Xbar.c
 *********************************************************************************************************************/