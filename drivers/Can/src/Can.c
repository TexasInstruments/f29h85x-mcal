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
 *  File:       Can.c
 *  Generator:  None
 *
 *  Description:  This file contains interface for Can Drv functions                                                           
 *********************************************************************************************************************/
/*
 *Design: MCAL-22825, MCAL-22842, MCAL-22827, MCAL-22880, MCAL-23013, MCAL-23010
 */

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
/*
 *Design: MCAL-23011, MCAL-22835
 */
#include "Can.h"
#include "SchM_Can.h"
#include "Can_Priv.h"

/*Design: MCAL-22836 */
#include "EcuM_Cbk.h"

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if (CAN_CFG_DEM_ENABLE == STD_ON)
#include "Dem.h"
#endif
/*Design: MCAL-22838 */
#include "Os.h"

/*Design: MCAL-23015, MCAL-23014 */
#include "CanIf_Cbk.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
#if ((CAN_AR_RELEASE_MAJOR_VERSION    != (0x04U)) || \
     (CAN_AR_RELEASE_MINOR_VERSION    != (0x03U)) || \
     (CAN_AR_RELEASE_REVISION_VERSION != (0x01U)))
    #error "AUTOSAR Version Numbers of Can are different"
#endif

#if ((CAN_SW_MAJOR_VERSION != (1U)) || (CAN_SW_MINOR_VERSION != (0U)))
    #error "Version numbers of Can.c and Can.h are inconsistent!"
#endif

#if ((CAN_CFG_MAJOR_VERSION != (1U)) || (CAN_CFG_MINOR_VERSION != (0U)))
    #error "Version numbers of Can.c and Can_Cfg.h are inconsistent!"
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
#define CAN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"
/** \brief Can driver object contains the all the can driver related information. */
VAR(Can_DriverObjType, CAN_VAR_NO_INIT) Can_DriverObj;
   
/** \brief Indication Type whether the state change of the Controller (Start/Stop/Sleep) is done. */
VAR(Can_CanIfIndicationType, CAN_VAR_NO_INIT) Can_CanIfIndication[KMAX_CONTROLLER];
#define CAN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT_8
#include "Can_MemMap.h"

/** \brief Hardware handle and mail box mapping lookup table. */
VAR(uint8, CAN_VAR_INIT) Can_HthMbMapping[KMAX_MB_PER_CONTROLLER * KMAX_CONTROLLER];
#define CAN_STOP_SEC_VAR_INIT_8
#include "Can_MemMap.h"



/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/ 


/** \brief Global Can Module Status flag */
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"
/** \brief Can_ModuleState Holds the overall driver state. */
/*
 *Design: MCAL-22846
 */
VAR(Can_DrvState, CAN_VAR_INIT) Can_ModuleState = CAN_UNINIT;
#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"
#endif
/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
/*
 *Design: MCAL-22938, MCAL-22756, MCAL-22845, MCAL-22932, MCAL-22930, MCAL-23012, MCAL-22843, MCAL-22844,
 *Design: MCAL-22931
 */
#if (STD_ON == CAN_CFG_GET_VERSION_INFO_API)
FUNC(void, CAN_CODE) Can_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CAN_APPL_DATA) versioninfo)
{
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
    /* If the output pointer (VersionInfoPtr) is NULL, report to DET with "CAN_E_PARAM_POINTER" error */
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                            (uint8)CAN_INSTANCE_ID,
                            (uint8)CAN_SID_GET_VERSION_INFO,
                            (uint8)CAN_E_PARAM_POINTER);
    }
    else
#endif
    {
        versioninfo->vendorID = (CAN_VENDOR_ID);
        versioninfo->moduleID = (CAN_MODULE_ID);
        versioninfo->instanceID = (uint8)(CAN_INSTANCE_ID);
        versioninfo->sw_major_version = (uint8)(CAN_SW_MAJOR_VERSION);
        versioninfo->sw_minor_version = (uint8)(CAN_SW_MINOR_VERSION);
        versioninfo->sw_patch_version = (uint8)(CAN_SW_PATCH_VERSION);
    }
}
#endif


/*
 *Design: MCAL-22883, MCAL-22884, MCAL-22848, MCAL-22937, MCAL-22936, MCAL-22888, MCAL-22889,
 *Design: MCAL-22847, MCAL-22890, MCAL-22885, MCAL-22826, MCAL-22840, MCAL-22853, MCAL-22886,
 *Design: MCAL-22824, MCAL-22845, MCAL-22932, MCAL-22930, MCAL-23022, MCAL-23017, MCAL-23016,
 *Design: MCAL-22881, MCAL-23012, MCAL-23020, MCAL-22843, MCAL-22844, MCAL-22823, MCAL-22931
 */
FUNC(void, CAN_CODE) Can_Init(P2CONST(Can_ConfigType, AUTOMATIC, CAN_COST) Config_Ptr)
{
    VAR(uint8, AUTOMATIC)controllerIdx = (uint8)0U;
    P2CONST(Can_ConfigType, AUTOMATIC, CAN_COST) ConfigPtr = Config_Ptr;

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
        
    /* Check if the CAN driver is already initialized and report a DET error. */
    if (CAN_UNINIT != Can_ModuleState)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_INIT,
                              (uint8)CAN_E_TRANSITION);
    }
    else
#endif
    {

#if (STD_ON == CAN_CFG_PRE_COMPILE_VARIANT)
        if(NULL_PTR == ConfigPtr)
        {
            ConfigPtr = &Can_CanConfigSet;
        }
        else
        {
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                  (uint8)CAN_INSTANCE_ID,
                                  (uint8)CAN_SID_INIT,
                                  (uint8)CAN_E_PARAM_POINTER);
#endif
        }
#endif

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
        /* Check if the pointer passed is Null and report a DET error. */ 
        if (E_NOT_OK == Can_CheckInitDetPriv(ConfigPtr))
        {
            (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                  (uint8)CAN_INSTANCE_ID,
                                  (uint8)CAN_SID_INIT,
                                  (uint8)CAN_E_PARAM_POINTER);
        }
        else
#endif
        {
            Can_ResetDrvObjPriv(&Can_DriverObj);
            Can_InitDrvObjPriv(&Can_DriverObj, ConfigPtr);
            for (controllerIdx = ((uint8)0U); controllerIdx < Can_DriverObj.canMaxControllerCount; controllerIdx++)
            {
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
                if(CAN_CS_UNINIT != Can_DriverObj.canController[controllerIdx].canState)
                {
                    /* Can controller is in not in UNINIT state */
                    (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                        (uint8)CAN_INSTANCE_ID,
                                        (uint8)CAN_SID_INIT,
                                        (uint8)CAN_E_TRANSITION);
                }
                else
#endif
                {
                    /* If Controller is active then only do initialization */
                    if(TRUE == Can_DriverObj.canController[controllerIdx].canControllerConfig.CanControllerActivation)
                    {
                        /* Init individual controller */
                        Can_HwUnitConfigPriv(&Can_DriverObj.canController[controllerIdx],
                                            &Can_DriverObj.canMailbox[0U],
                                            Can_DriverObj.maxMbCnt, &Can_HthMbMapping[0U]);

                        /* Change the state to STOPPED from UNINIT state */
                        Can_DriverObj.canController[controllerIdx].canState = CAN_CS_STOPPED;
                    }
                    else
                    {
                        /* Do Nothing */
                    }
                }
            }
        }
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
        Can_ModuleState = CAN_READY;
#endif
    }
}



/*
 *Design: MCAL-22940, MCAL-22939, MCAL-22882, MCAL-22845, MCAL-22932, MCAL-22849, MCAL-22930, MCAL-23012,
 *Design: MCAL-22843, MCAL-22844, MCAL-22931
 */
FUNC(void, CAN_CODE) Can_DeInit(void)
{
    VAR(uint8, AUTOMATIC)controllerIdx = (uint8)0U;

    #if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
    
    /* Check if the CAN driver is not initialized and report a DET error.  */
    if (CAN_READY != Can_ModuleState)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_DEINIT,
                              (uint8)CAN_E_TRANSITION);
    }
    else
    #endif
    {
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
        Can_ModuleState = CAN_UNINIT;
#endif
        for (controllerIdx = ((uint8)0U); controllerIdx < Can_DriverObj.canMaxControllerCount; controllerIdx++)
        {     
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
            if(CAN_CS_STARTED == Can_DriverObj.canController[controllerIdx].canState)
            {
                /* Can controller is in STARTED state */
                (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                    (uint8)CAN_INSTANCE_ID,
                                    (uint8)CAN_SID_DEINIT,
                                    (uint8)CAN_E_TRANSITION);
            }
            else
#endif 
            {  
                Can_HwDeInitPriv(&Can_DriverObj.canController[controllerIdx].canControllerConfig);
                Can_DriverObj.canController[controllerIdx].canState = CAN_CS_UNINIT;
            }
        }
        Can_ResetDrvObjPriv(&Can_DriverObj);
    }
}


/*
 *Design: MCAL-22944, MCAL-22943, MCAL-22942, MCAL-22854, MCAL-22855, MCAL-22856, MCAL-22941, MCAL-22754,
 *Design: MCAL-22887, MCAL-22845, MCAL-22932, MCAL-22831, MCAL-22930, MCAL-23012, MCAL-22843, MCAL-22844,
 *Design: MCAL-22931
 */
#if (STD_ON == CAN_CFG_SET_BAUDRATE_API)
FUNC(Std_ReturnType, CAN_CODE) Can_SetBaudrate(uint8 Controller, 
                                    const uint16 BaudRateConfigID)
{
    VAR(uint32, AUTOMATIC)baseAddr = (uint32)0U;
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    P2CONST(Can_BaudConfigType, AUTOMATIC, CAN_COST) setBaud = (Can_BaudConfigType*)NULL_PTR;

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
    
    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState)
    {

            (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                  (uint8)CAN_INSTANCE_ID,
                                  (uint8)CAN_SID_SETBAUDRATE,
                                  (uint8)CAN_E_UNINIT);
    }
    
    /* Check if the controller is out of range and report a DET error. */
    else if (Controller >= Can_DriverObj.canMaxControllerCount)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_SETBAUDRATE,
                              (uint8)CAN_E_PARAM_CONTROLLER);
    }
    
    /* Check if valid Baudrate config is selected and report a DET error. */
    else if (BaudRateConfigID > Can_DriverObj.canController[Controller].MaxBaudConfigID)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                             (uint8)CAN_INSTANCE_ID,
                             (uint8)CAN_SID_SETBAUDRATE,
                             (uint8)CAN_E_PARAM_BAUDRATE);
    }
    else
#endif
    {
        
        /* Check if the controller is not in stopped state. */
        if (CAN_CS_STOPPED == Can_DriverObj.canController[Controller].canState)
        {
            baseAddr = Can_DriverObj.canController[Controller].canControllerConfig.CanControllerBaseAddress;
            setBaud = Can_DriverObj.canController[Controller].canControllerConfig.BaudRateConfigList[BaudRateConfigID];
            returnValue = Can_HWSetBaudRatePriv(baseAddr, setBaud);   
        }
        else
        {
            /* Return should be E_NOT_OK */
        }
        
    }

    return returnValue;
}
#endif


/*
 *Design: MCAL-22959, MCAL-22958, MCAL-22957, MCAL-22956, MCAL-22955, MCAL-22845, MCAL-22932, MCAL-22930,
 *Design: MCAL-23012, MCAL-22843, MCAL-22844, MCAL-22931
 */
FUNC(void, CAN_CODE) Can_DisableControllerInterrupts(uint8 Controller)
{
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
   
    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, 
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_DIINT,
                              (uint8)CAN_E_UNINIT);
    }
    
    /* Check if the controller is out of range and report a DET error. */
    else if (Controller >= Can_DriverObj.canMaxControllerCount)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID, 
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_DIINT,
                              (uint8)CAN_E_PARAM_CONTROLLER);
    }
    else
#endif
    {
        if ((POLLING != Can_DriverObj.canController[Controller].canControllerConfig.CanRxProcessing) 
        && (POLLING != Can_DriverObj.canController[Controller].canControllerConfig.CanTxProcessing)
        && (POLLING != Can_DriverObj.canController[Controller].canControllerConfig.CanBusoffProcessing)
        && (POLLING != Can_DriverObj.canController[Controller].canControllerConfig.CanWakeupProcessing))
        {
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
            if ((uint8)0U == Can_DriverObj.canController[Controller].canInterruptCounter)
            {
                Can_DisableInterruptsPriv(&Can_DriverObj.canController[Controller].canControllerConfig);
            }
            else
            {
                /* Do Nothing */
            }
            Can_DriverObj.canController[Controller].canInterruptCounter++;
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* Do Nothing */
        }
    }
}


/*
 *Design: MCAL-22963, MCAL-22962, MCAL-22961, MCAL-22960, MCAL-22845, MCAL-22932, MCAL-22930, MCAL-23012,
 *Design: MCAL-22843, MCAL-22844, MCAL-22931
 */
FUNC(void, CAN_CODE)
Can_EnableControllerInterrupts(uint8 Controller) 
{
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)

    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState) 
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_ENINT,
                              (uint8)CAN_E_UNINIT);
    }

    /* Check if the controller is out of range and report a DET error. */
    else if (Controller >= Can_DriverObj.canMaxControllerCount) 
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_ENINT,
                              (uint8)CAN_E_PARAM_CONTROLLER);
    } else
#endif
    {
        if ((uint8)0U < Can_DriverObj.canController[Controller].canInterruptCounter) 
        {
            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0();
            Can_DriverObj.canController[Controller].canInterruptCounter--;
            
            if ((uint8)0U == Can_DriverObj.canController[Controller].canInterruptCounter) 
            {
                Can_EnableInterruptsPriv(&Can_DriverObj.canController[Controller].canControllerConfig);
            } 
            else 
            {
                /* Do Nothing */
            }
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0();
        } 
        else 
        {
            /* Do Nothing */
        }
    }
}

#if (STD_ON == CAN_CFG_WAKEUP_FUNCTIONALITY_API)
/*
 *Design: MCAL-22967, MCAL-22966, MCAL-22965, MCAL-22964, MCAL-22845, MCAL-22932, MCAL-22930, MCAL-23012,
 *Design: MCAL-22843, MCAL-22844, MCAL-22931
 */
FUNC(Std_ReturnType, CAN_CODE)Can_CheckWakeup(uint8 Controller) 
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    VAR(Std_ReturnType, AUTOMATIC)status = E_NOT_OK;

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)

    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState) 
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_CKWAKEUP,
                              (uint8)CAN_E_UNINIT);
    }

    /* Check if the controller is out of range and report a DET error. */
    else if (Controller >= Can_DriverObj.canMaxControllerCount) 
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_CKWAKEUP,
                              (uint8)CAN_E_PARAM_CONTROLLER);
    } 
    else
#endif
    {
        status = Can_HWCheckWakeupPriv(&Can_DriverObj.canController[Controller].canControllerConfig);

        if (E_OK == status) 
        {
            /* Wakeup detected inform EcuM*/
            EcuM_SetWakeupEvent(Can_DriverObj.canController[Controller]
                                    .canControllerConfig.CanWakeupSourceRef);
        } else 
        {
            /* Wakeup not detected
               Do Nothing */
        }
        returnValue = E_OK;
    }

    return returnValue;
}
#endif

/*
 *Design: MCAL-22968, MCAL-22969, MCAL-22970, MCAL-22971, MCAL-22845, MCAL-22932, MCAL-22930, MCAL-23012,
 *Design: MCAL-22843, MCAL-22844, MCAL-22931
 */
FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerErrorState(uint8 Controller, 
                P2VAR(Can_ErrorStateType, AUTOMATIC, CAN_APPL_DATA) ErrorStatePtr)
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)

    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState) 
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_GETCNTRERRSTATE,
                              (uint8)CAN_E_UNINIT);
    }
    /* Check if the controller is out of range and report a DET error. */
    else if (Controller >= Can_DriverObj.canMaxControllerCount) 
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_GETCNTRERRSTATE,
                              (uint8)CAN_E_PARAM_CONTROLLER);
    }

    /* Check if the ErrorStatePtr is NULL and report a DET error. */
    else if ((Can_ErrorStateType *)NULL_PTR == ErrorStatePtr) 
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_GETCNTRERRSTATE,
                              (uint8)CAN_E_PARAM_POINTER);
    } 
    else
#endif
    {
        *ErrorStatePtr = Can_GetProtocolStatusPriv(&Can_DriverObj.canController[Controller]);
        returnValue = E_OK;
    }

    return returnValue;
}

/*
 *Design: MCAL-22972, MCAL-22973, MCAL-22974, MCAL-22975, MCAL-22845, MCAL-22932, MCAL-22930, MCAL-23012,
 *Design: MCAL-22843, MCAL-22844, MCAL-22931
 */
FUNC(Std_ReturnType, CAN_CODE) Can_GetControllerMode(uint8 Controller, 
            P2VAR(Can_ControllerStateType, AUTOMATIC, CAN_APPL_DATA) ControllerModePtr )
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
   
    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                            (uint8)CAN_INSTANCE_ID,
                            (uint8)CAN_SID_GETCNTRMODE,
                            (uint8)CAN_E_UNINIT);
    }
   
    /* Check if the controller is out of range and report a DET error. */
    else if (Controller >= Can_DriverObj.canMaxControllerCount)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                            (uint8)CAN_INSTANCE_ID,
                            (uint8)CAN_SID_GETCNTRMODE,
                            (uint8)CAN_E_PARAM_CONTROLLER);
    }
   
    /* Check if the ControllerModePtr is NULL and report a DET error. */
    else if ((Can_ControllerStateType*)NULL_PTR == ControllerModePtr)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                            (uint8)CAN_INSTANCE_ID,
                            (uint8)CAN_SID_GETCNTRMODE,
                            (uint8)CAN_E_PARAM_POINTER);
    }
    else
#endif
    {
       *ControllerModePtr = Can_DriverObj.canController[Controller].canState;
       returnValue = E_OK;
    }

    return returnValue;
}


/*
 *Design: MCAL-22954, MCAL-22953, MCAL-22952, MCAL-22951, MCAL-22950, MCAL-22949, MCAL-22948, MCAL-22947,
 *Design: MCAL-22946, MCAL-22945, MCAL-22873, MCAL-22872, MCAL-22871, MCAL-22870, MCAL-22869, MCAL-22868,
 *Design: MCAL-22866, MCAL-22865, MCAL-22864, MCAL-22863, MCAL-22862, MCAL-22861, MCAL-22860, MCAL-22859,
 *Design: MCAL-22877, MCAL-22845, MCAL-22932, MCAL-22930, MCAL-23012, MCAL-22850, MCAL-22843, MCAL-22844,
 *Design: MCAL-22867, MCAL-22858, MCAL-22931
 */
FUNC(Std_ReturnType, CAN_CODE) Can_SetControllerMode(uint8 Controller, 
                    Can_ControllerStateType Transition)
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    P2VAR(Can_ControllerObjType, AUTOMATIC, CAN_DATA) controllerObj = NULL_PTR; 

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
    
    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_SETCTR,
                              (uint8)CAN_E_UNINIT);
    }
    
    /* Check if the controller is out of range and report a DET error. */
    else if (Controller >= Can_DriverObj.canMaxControllerCount)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_SETCTR,
                              (uint8)CAN_E_PARAM_CONTROLLER);
    }
    else
#endif
    {
        controllerObj = &Can_DriverObj.canController[Controller];
        switch (Transition)
        {
            case CAN_CS_STARTED:
            {
                if(CAN_CS_STOPPED == controllerObj->canState)
                {
# if (STD_ON == CAN_CFG_ICOM_SUPPORT)
                    if(Can_DriverObj.Can_IcomActivation[Controller] == TRUE)
                    {
                        Can_DriverObj.Can_IcomActivation[Controller] = FALSE;
                    }
#endif
                    returnValue = Can_HwUnitStartPriv(controllerObj, &Can_CanIfIndication[Controller]);
                }
                else
                {
    #if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
                    (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                          (uint8)CAN_INSTANCE_ID,
                                          (uint8)CAN_SID_SETCTR,
                                          (uint8)CAN_E_TRANSITION);   
    #endif
                }
                break;
            }
            
            case CAN_CS_STOPPED:
            {
                if(CAN_CS_SLEEP == controllerObj->canState)
                {
# if (STD_ON == CAN_CFG_ICOM_SUPPORT)
                    if(Can_DriverObj.Can_IcomActivation[Controller] == TRUE)
                    {
                        Can_DriverObj.Can_IcomActivation[Controller] = FALSE;
                    }
#endif
                    returnValue = Can_HwUnitWakeupPriv(controllerObj, &Can_CanIfIndication[Controller]);
                }
                else if (CAN_CS_UNINIT != controllerObj->canState)
                {
# if (STD_ON == CAN_CFG_ICOM_SUPPORT)
                    if(Can_DriverObj.Can_IcomActivation[Controller] == TRUE)
                    {
                        Can_DriverObj.Can_IcomActivation[Controller] = FALSE;
                    }
#endif
                    Can_HwUnitStopPriv(controllerObj, &Can_CanIfIndication[Controller]);
                    returnValue = E_OK;
                }
                else
                {
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
                    (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                          (uint8)CAN_INSTANCE_ID,
                                          (uint8)CAN_SID_SETCTR,
                                          (uint8)CAN_E_TRANSITION);   
#endif
                    /* Do Noting */
                }
                break;
            }
            case CAN_CS_SLEEP:
            {
                if(CAN_CS_STOPPED == controllerObj->canState)
                {
                    returnValue = Can_HwUnitSleepPriv(controllerObj, &Can_CanIfIndication[Controller]);
                }
                else if(CAN_CS_SLEEP != controllerObj->canState)
                {
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
                    (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                          (uint8)CAN_INSTANCE_ID,
                                          (uint8)CAN_SID_SETCTR,
                                          (uint8)CAN_E_TRANSITION);   
#endif
                }
                else
                {
                    returnValue = E_OK;
                }
                break;
            }
            default:
            {
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
                    (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                          (uint8)CAN_INSTANCE_ID,
                                          (uint8)CAN_SID_SETCTR,
                                          (uint8)CAN_E_TRANSITION);
#endif
                break;
            }
        }
    }   
    return returnValue;
}


/*
 *Design: MCAL-22891, MCAL-22892, MCAL-22893, MCAL-22894, MCAL-22895, MCAL-22896, MCAL-22897, MCAL-22844,
 *Design: MCAL-22898, MCAL-22899, MCAL-22900, MCAL-22976, MCAL-22977, MCAL-22978, MCAL-22979, MCAL-22980,
 *Design: MCAL-22981, MCAL-22982, MCAL-22983, MCAL-22984, MCAL-22985, MCAL-22986, MCAL-22987, MCAL-22988,
 *Design: MCAL-22989, MCAL-22990, MCAL-22845, MCAL-22932, MCAL-22831, MCAL-22930, MCAL-23012, MCAL-22843,
 *Design: MCAL-22931
 */
FUNC(Std_ReturnType, CAN_CODE) Can_Write(uint8 Hth, 
            P2CONST(Can_PduType, AUTOMATIC, CAN_COST) PduInfo)
{
    VAR(Std_ReturnType, AUTOMATIC)returnValue = E_NOT_OK;
    VAR(Std_ReturnType, AUTOMATIC)canIfTTStatus = E_NOT_OK;
    VAR(uint8, AUTOMATIC)mailbox = (uint8)0U;
    VAR(uint8, AUTOMATIC)msgController = (uint8)0U;
    VAR(Can_HwHandleType, AUTOMATIC)messageBox = (Can_HwHandleType)0U;
    P2VAR(Can_PduType, AUTOMATIC, CAN_DATA) pduInfo = (Can_PduType *)PduInfo;

#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
    
    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_WRITE,
                              (uint8)CAN_E_UNINIT);
    }
    
    /* Check if the PduInfo is NULL and report a DET error. */
    else if ((Can_PduType*)NULL_PTR == PduInfo)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_WRITE,
                              (uint8)CAN_E_PARAM_POINTER);
    }
    
    /* Since Trigger Transmit is not supported, check if the Sdu is NULL and report a DET error. */
    
    /* Check if the data length is incorrect and report a DET error. */
    else if ((CAN_FD_PAYLOAD_MAX_BYTES < PduInfo->length) ||
                ((CAN_CLASSIC_PAYLOAD_MAX_BYTES < PduInfo->length) &&
                (CAN_ID_CAN_CONTROLLER_TYPE_MASK != 
                (CAN_ID_CAN_CONTROLLER_TYPE_MASK & PduInfo->id))))
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_WRITE,
                              (uint8)CAN_E_PARAM_DATA_LENGTH); 

    }
    else if (Can_DriverObj.maxMbCnt <= Hth)
    {
        /* Check if Hth is not part of configured Hardware Transmit Handle and report a DET error. */
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                (uint8)CAN_INSTANCE_ID,
                                (uint8)CAN_SID_WRITE,
                                (uint8)CAN_E_PARAM_HANDLE);
    }
    else
#endif
    {
        mailbox = Can_HthMbMapping[Hth];
        msgController = Can_DriverObj.canMailbox[mailbox].mailBoxConfig.CanControllerRef->CanControllerId;
        if(msgController < KMAX_CONTROLLER)
        {
            if (((uint8*)NULL_PTR == PduInfo->sdu) && 
            ( TRUE == Can_DriverObj.canMailbox[mailbox].mailBoxConfig.CanTriggerTransmitEnable))
            {
                canIfTTStatus = CanIf_TriggerTransmit(Can_DriverObj.canMailbox[mailbox].canTxRxPduId[0U],
                                                    &Can_DriverObj.canController[msgController].pduInfo);
                if (E_OK == canIfTTStatus) 
                {
                    pduInfo->length = (uint8) Can_DriverObj.canController[msgController].pduInfo.SduLength;
                    pduInfo->sdu = Can_DriverObj.canController[msgController].pduInfo.SduDataPtr;
                    returnValue = E_OK;
                }
                else
                {
                    returnValue = E_NOT_OK;
                }
            }
            else if((uint8*)NULL_PTR != PduInfo->sdu)
            {
                returnValue = E_OK;
            }
            else
            {
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
                (void)Det_ReportError((uint16)CAN_MODULE_ID,
                                    (uint8)CAN_INSTANCE_ID,
                                    (uint8)CAN_SID_WRITE,
                                    (uint8)CAN_E_PARAM_POINTER);
#endif
                returnValue = E_NOT_OK;
            }
        
        }
        else
        {
            /* Do Nothing */
        }
        /* Only for Tx Mailbox */
        if ((E_OK == returnValue) && (Can_DriverObj.Can_IcomActivation[msgController] == TRUE))
        {
            returnValue = (uint8) CAN_BUSY;
        }
        if((E_OK == returnValue) && (TRANSMIT == Can_DriverObj.canMailbox[mailbox].mailBoxConfig.CanObjectType))
        {
            /* CanSM has triggered a new write after L1 timeout. Stop the BusOff
            * recovery. CanSM will trigger a new bus off recovery sequence. */
            Can_DriverObj.canController[msgController].canBusOffRecoveryStatus = FALSE;

            SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
            messageBox = Can_DriverObj.canMailbox[mailbox].mailBoxConfig.HwHandle;

            returnValue = Can_GetFreeTxMsgObjPriv(&Can_DriverObj.canMailbox[mailbox].mailBoxConfig,
                                            &Can_DriverObj.canController[msgController],
                                            &messageBox,
                                            mailbox);

            if(E_OK == returnValue)
            {
               
                Can_WriteTxMailboxPriv(&Can_DriverObj.canMailbox[mailbox].mailBoxConfig,
                                    &Can_DriverObj.canController[msgController],
                                    mailbox,
                                    messageBox,
                                    pduInfo);
               
                /* Store the transmitted Pdu SWPdu Handle for Tx confirmation */
                Can_DriverObj.canMailbox[mailbox].canTxRxPduId[messageBox] = PduInfo->swPduHandle;

                /* Set that this object is transmitted */
                Can_DriverObj.canController[msgController].canTxStatus[messageBox] = ((uint8)1U);
            }
            else
            {
                /* Do Nothing */
            }
            SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
        }
    
    }
    return returnValue;
}


/*
 *Design: MCAL-22994, MCAL-22995, MCAL-22996, MCAL-23018, MCAL-22845, MCAL-22932, MCAL-22913, MCAL-22930,
 *Design: MCAL-23012, MCAL-22843, MCAL-22914, MCAL-22844, MCAL-22931, MCAL-22830
 */
FUNC(void, CAN_CODE)
Can_MainFunction_Write(uint16 RWFuncID)
{
#if  (STD_ON == CAN_TX_POLLING)
    VAR(uint8, AUTOMATIC)htrh = (uint8)0U;
    VAR(uint8, AUTOMATIC)controller = (uint8)0U;

    for (htrh = ((uint8)0U); htrh < Can_DriverObj.maxTxMbCnt; htrh++)
    {
        if (RWFuncID == Can_DriverObj.canTxMailbox[htrh].mailBoxConfig.CanMainFunctionRWPeriodRef.ID)
        {
            controller = Can_DriverObj.canTxMailbox[htrh].mailBoxConfig.CanControllerRef->CanControllerId;
            Can_HwUnitTxDonePollingPriv(&Can_DriverObj.canController[controller],
                                        &Can_DriverObj.canTxMailbox[htrh],
                                        htrh);
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif
}



/*
 *Design: MCAL-22901, MCAL-22902, MCAL-22903, MCAL-22904, MCAL-22905, MCAL-22906, MCAL-22907,
 *Design: MCAL-22908, MCAL-22909, MCAL-22910, MCAL-22911, MCAL-22997, MCAL-22998, MCAL-22999,
 *Design: MCAL-23018, MCAL-22845, MCAL-22932, MCAL-22913, MCAL-22930, MCAL-23012, MCAL-22843,
 *Design: MCAL-22914, MCAL-22844, MCAL-22931, MCAL-22830
 */
FUNC(void, CAN_CODE)
Can_MainFunction_Read(uint16 RWFuncID)
{
#if (STD_ON == CAN_RX_POLLING)
    VAR(uint32, AUTOMATIC)controller = (uint32)0U;
    VAR(uint8, AUTOMATIC)htrh = (uint8)0U;


    for (htrh = ((uint8)0U); htrh < Can_DriverObj.maxRxMbCnt; htrh++)
    {
        if (RWFuncID == Can_DriverObj.canRxMailbox[htrh].mailBoxConfig.CanMainFunctionRWPeriodRef.ID)
        {
            controller = Can_DriverObj.canRxMailbox[htrh].mailBoxConfig.CanControllerRef->CanControllerId;
            Can_ReadRxMailboxPriv(&Can_DriverObj.canController[controller],
                &Can_DriverObj.canRxMailbox[htrh],
                Can_DriverObj.maxMbCnt);
        }
        else
        {
            /* Do Nothing */
        }

    }
#endif
}


/*
 *Design: MCAL-23001, MCAL-23000, MCAL-23018, MCAL-22845, MCAL-22932, MCAL-22913, MCAL-22930, MCAL-23012,
 *Design: MCAL-22843, MCAL-22914, MCAL-22844, MCAL-22931, MCAL-22830
 */
FUNC(void, CAN_CODE)
Can_MainFunction_BusOff(void)
{
#if (STD_ON == CAN_BUSOFF_POLLING)
    VAR(uint8, AUTOMATIC)loopCnt = (uint8)0U;

    for (loopCnt = ((uint8)0U); loopCnt < Can_DriverObj.canMaxControllerCount; loopCnt++)
    {
        if(TRUE == Can_DriverObj.canController[loopCnt].canControllerConfig.CanControllerActivation)
        {
            if ((Can_ProcessingType) POLLING == Can_DriverObj.canController[loopCnt].canControllerConfig.CanBusoffProcessing)
            {
                Can_BusOffProcessPriv(&Can_DriverObj.canController[loopCnt]);
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif
}


/*
 *Design: MCAL-22003, MCAL-23002, MCAL-23003, MCAL-23018, MCAL-22845, MCAL-22932, MCAL-22875, MCAL-22913,
 *Design: MCAL-22930, MCAL-23012, MCAL-22843, MCAL-22914, MCAL-22844, MCAL-22931, MCAL-22830
 */
FUNC(void, CAN_CODE)
Can_MainFunction_Wakeup(void)
{
#if (STD_ON == CAN_WAKEUP_POLLING)
    VAR(uint8, AUTOMATIC)loopCnt = (uint8)0U;

    for (loopCnt = ((uint8)0U); loopCnt < Can_DriverObj.canMaxControllerCount; loopCnt++)
    {
        if(TRUE == Can_DriverObj.canController[loopCnt].canControllerConfig.CanControllerActivation)
        {
            if ((Can_ProcessingType) POLLING == Can_DriverObj.canController[loopCnt].canControllerConfig.CanWakeupProcessing)
            {   
                Can_WakeupProcessPriv(&Can_DriverObj.canController[loopCnt]);
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
#endif
}


/*
 *Design: MCAL-22857, MCAL-23004, MCAL-23018, MCAL-22845, MCAL-22932, MCAL-22913, MCAL-22930, MCAL-23012,
 *Design: MCAL-22843, MCAL-22914, MCAL-22844, MCAL-22931, MCAL-22830
 */
FUNC(void, CAN_CODE)
Can_MainFunction_Mode(void)
{
    VAR(uint8, AUTOMATIC)loopCnt = (uint8)0U;

    for (loopCnt = ((uint8)0U); loopCnt < Can_DriverObj.canMaxControllerCount; loopCnt++)
    {
        if(TRUE == Can_DriverObj.canController[loopCnt].canControllerConfig.CanControllerActivation)
        {
            Can_ModeProcessPriv(&Can_DriverObj.canController[loopCnt], &Can_CanIfIndication[loopCnt]);
        }
        else
        {
            /* Do Nothing */
        }
    }
}

# if (STD_ON == CAN_CFG_ICOM_SUPPORT)
/*
 * Design: MCAL-22915, MCAL-22916, MCAL-22917, MCAL-22918, MCAL-22919, MCAL-22920, MCAL-22921,
 * Design: MCAL-22922, MCAL-22923, MCAL-22924, MCAL-22925, MCAL-22926, MCAL-22927, MCAL-22928,
 * Design: MCAL-23005, MCAL-23006, MCAL-23007, MCAL-23008, MCAL-22845, MCAL-22932, MCAL-22930,
 * Design: MCAL-23012, MCAL-22843, MCAL-22844, MCAL-22931
 */
FUNC(Std_ReturnType, CAN_CODE)
 Can_SetIcomConfiguration( uint8 Controller, 
                    IcomConfigIdType ConfigurationId)
{
    VAR(uint8, AUTOMATIC)loopCnt = (uint8)0U;
    VAR(Std_ReturnType, AUTOMATIC)status = E_NOT_OK;
    
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
    
    /* Check if the CAN driver is not initialized and report a DET error. */
    if (CAN_UNINIT == Can_ModuleState)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_ICOMCONFIG,
                              (uint8)CAN_E_UNINIT);
    }
    
    /* Check if the controller id is valid */
    else if (KMAX_CONTROLLER <= Controller)
    {
        (void)Det_ReportError((uint16)CAN_MODULE_ID,
                              (uint8)CAN_INSTANCE_ID,
                              (uint8)CAN_SID_ICOMCONFIG,
                              (uint8)CAN_E_PARAM_CONTROLLER);
    }
    else
#endif        
    {
        /*Check the configuration ID */
        if (((IcomConfigIdType )ICOM_CONFIG_DISABLE) == ConfigurationId)
        {
            status = E_OK;
            /* Disable pretended networking */
            Can_DriverObj.Can_IcomActivation[Controller] = FALSE;
            CanIf_CurrentIcomConfiguration(Controller,ConfigurationId,ICOM_SWITCH_E_OK);
        }
        else
        {
            for(loopCnt = 0;loopCnt < MAX_ICOM_CONFIGURATION;loopCnt++)
            {
                if(ConfigurationId == Can_DriverObj.IcomConfigurationList[loopCnt].CanIcomConfigId)
                {
                    status = E_OK;
                }
                
            }
            if(E_OK == status)
            {
                /* enable pretended networking */
                Can_DriverObj.Can_IcomActivation[Controller] = TRUE;
                Can_DriverObj.Can_IcomConfigurationId[Controller] = loopCnt;
                Can_DriverObj.Can_IcomCounterValue[Controller] = 0U;
                CanIf_CurrentIcomConfiguration(Controller,ConfigurationId,ICOM_SWITCH_E_OK);
            }
            else
            {
                CanIf_CurrentIcomConfiguration(Controller,ConfigurationId,ICOM_SWITCH_E_FAILED);
#if (STD_ON == CAN_CFG_DEV_ERROR_DETECT)
                (void)Det_ReportError((uint16)CAN_MODULE_ID,
                      (uint8)CAN_INSTANCE_ID,
                      (uint8)CAN_SID_ICOMCONFIG,
                      (uint8)CAN_E_ICOM_CONFIG_INVALID);
#endif
            }
        }
    }
    return status;
}
#endif 
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/
#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
/*********************************************************************************************************************
 *  End of File: Can.c
 *********************************************************************************************************************/
