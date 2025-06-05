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
 *  File:         Cdd_Xbar_GpioToGpio.c
 *  Generator:    None
 *
 *  Description:  Example application source for CDD XBar to route GPIO0 Aand GPIO4 to GPIO2 using
 *Input and Output crossbar. Initially the following configurations are made in configurator:
 *                             ___________           ________________
 *                GPIO0-------|INPUT XBAR1|---------| OUTPUT XBAR 1  |-------GPIO2
 *                            |___________|         |________________|
 *                             ___________
 *                GPIO3-------|INPUT XBAR2|
 *                            |___________|
 *                CDD XBAR APIs are used to change this configuration for demonstration of APIs.
 *                Finally GPIO0 and GPIO4 will be routed to GPIO2 using APIs
 *                                ________________
 *                GPIO0 ---------|                |
 *                               | OUTPUT XBAR 1  |-------GPIO2
 *                GPIO4 ---------|________________|
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

#include "Cdd_Xbar_GpioToGpio.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "EcuM.h"
#include "Dio.h"
#if (STD_ON == CDD_XBAR_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/* None */

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
 * Local Object Definitions
 *********************************************************************************************************************/
#if (STD_ON == CDD_XBAR_GET_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Xbar_VersionInfo;
#endif
Dio_LevelType Dio_ChannelLevel;

/*********************************************************************************************************************
 *  Local Function Prototypes
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  Local Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  External Functions Definition
 *********************************************************************************************************************/

/* Example Application */
int main(void)
{
    DeviceSupport_Init();
    /* Configure the crossbar and init MCU */
    EcuM_Init();
    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Sample Application - STARTS !!!\n");
    /*  Get version Info */

#if (STD_ON == CDD_XBAR_GET_VERSION_INFO_API)
    Cdd_Xbar_GetVersionInfo(&Cdd_Xbar_VersionInfo);
    AppUtils_Printf("CDD XBAR MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Xbar_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Xbar_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Xbar_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Xbar_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Xbar_VersionInfo.sw_patch_version);
#endif

    AppUtils_Printf("-------------------------------------------- \n");
    AppUtils_Printf("Checking lock status of INPUT XBAR1 \n");
    /* Checking status of INPUT XBAR1 which is locked with configurator */
    if (TRUE == Cdd_Xbar_LockStatus(CddXbarConf_CddXbarInputXbarInstanceConfig_CddXbarInputXbarInstanceConfig_0))
    {
        AppUtils_Printf("INPUT XBAR1 is locked \n");
    }

    AppUtils_Printf("-------------------------------------------- \n");
    AppUtils_Printf("Checking lock status of INPUT XBAR2 \n");
    if (FALSE == Cdd_Xbar_LockStatus(CddXbarConf_CddXbarInputXbarInstanceConfig_CddXbarInputXbarInstanceConfig_1))
    {
        AppUtils_Printf("INPUT XBAR2 is not locked \n");
        AppUtils_Printf("Selecting GPIO4 as input to INPUT XBAR2 \n");
        if (E_OK ==
            Cdd_Xbar_SelectInput(CddXbarConf_CddXbarInputXbarInstanceConfig_CddXbarInputXbarInstanceConfig_1, 4U, TRUE))
        {
            AppUtils_Printf("GPIO4 is selected as input to INPUT XBAR2 \n");
        }
    }

    AppUtils_Printf("-------------------------------------------- \n");
    AppUtils_Printf("Checking lock status of OUTPUT XBAR \n");
    /* Unlock check before selection attempt */
    if (FALSE == Cdd_Xbar_LockStatus(CddXbarConf_CddXbarOutputXbarInstanceConfig_CddXbarOutputXbarInstanceConfig_0))
    {
        AppUtils_Printf("Selecting INPUT XBAR2 as input to OUTPUT XBAR2 \n");
        /* Configuring INPUTXBAR2 as input to OUTPUT XBAR1 */
        if (E_OK == Cdd_Xbar_SelectInput(CddXbarConf_CddXbarOutputXbarInstanceConfig_CddXbarOutputXbarInstanceConfig_0,
                                         CDD_XBAR_OUT_INPUTXBAR2, TRUE))
        {
            AppUtils_Printf("INPUT XBAR2 is selected as input to OUTPUT XBAR2 \n");
            /* Locking Output crossbar*/
            Cdd_Xbar_Lock(CddXbarConf_CddXbarOutputXbarInstanceConfig_CddXbarOutputXbarInstanceConfig_0);
        }
    }

    Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_HIGH);

    Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_OUTPUTXBAR1);

    if (Dio_ChannelLevel == STD_HIGH)
    {
        Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_LOW);
        Dio_WriteChannel(DioConf_DioChannel_GPIO4, STD_HIGH);
        Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_OUTPUTXBAR1);
        if (Dio_ChannelLevel == STD_HIGH)
        {
            AppUtils_Printf(
                "================================================================================="
                "\n");
            AppUtils_Printf(
                "PASS: GPIO0(INPUT XBAR1) and GPIO4(INPUT XBAR2) are routed to GPIO2(OUTPUT XBAR1) "
                "\n");
        }
        else
        {
            AppUtils_Printf(
                "================================================================================="
                "\n");
            AppUtils_Printf(
                "FAIL: GPIO0(INPUT XBAR1) and GPIO4(INPUT XBAR2) are not routed to GPIO2(OUTPUT "
                "XBAR1) \n");
        }
    }
    else
    {
        AppUtils_Printf("=================================================================================\n");
        AppUtils_Printf(
            "FAIL: GPIO0(INPUT XBAR1) and GPIO4(INPUT XBAR2) are not routed to GPIO2(OUTPUT XBAR1) "
            "\n");
    }

    return 0;
}

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_GpioToGpio.c
 *********************************************************************************************************************/
