/*********************************************************************************************************************
 *  COPYRIGHT
 *
 ------------------------------------------------------------------------------------------------------------------
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
 *
 ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *
 ------------------------------------------------------------------------------------------------------------------
 *  File:       Cdd_Adc_Example_GlbSwTrig.c
 *  Generator:  None
 *
 *  Description:  Cdd_Adc global software trigger example source file.
 * \note application source is specific to F29P58x devices.
 *
 * This examples demonstrates how to use global software trigger.
 * The group conversion started with StartGlobalSwTrig must be stopped with StopGlobalSwTrig.
 * StartGroupConversion can't be used before StopGlobalSwTrig to start a new group conversion for the group
 * which was already started with StartGlobalSwTrig.
 * First stop the global software trigger and then start the normal software group conversion.
 *
 * Steps followed in the example:
 * EcuM_Init()
 *  - Initialize clock to 200 MHz using Mcu_Init()
 *  - Initialize pins in analog mode with Port_Init()
 *  - Initialize Cdd_Adc driver using Cdd_Adc_Init()
 * Connect ADCAIN1 to GND to observe PPB trip high & trip low interrupts
 * Start global software trigger Id 0 conversion
 * Re-trigger the global software conversion
 * Stop the global software conversion with Cdd_Adc_StopGlobalSwTrig API
 * Start software group 1 conversion with Cdd_Adc_StartGroupConversion
 * After the group conversion is done,print the execution successful statement.
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Mcal_Lib.h"
#include "EcuM.h"
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "Os.h"
#include "Cdd_Adc.h"
#include "Port.h"
#include "Mcu.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/
uint32 Cdd_Adc_GroupMask    = 0U;
sint32 Cdd_Adc_PpbValue[2U] = {0}; /* Variables to PPB result */

Cdd_Adc_PpbValType PpbFinalValue[2U], PpbPartialValue[2U]; /* Variables to store Final and partial register values */

uint8 PpbTripHighCount = 0U, PpbTripLowCount = 0U;

const Cdd_Adc_ConfigType* Cdd_Adc_ConfigTypePtr = NULL_PTR;

Cdd_Adc_ValueGroupType Cdd_Adc_Buffer[CDD_ADC_GROUP_CNT][20U];

Cdd_Adc_ValueGroupType Cdd_Adc_ResultBuffer[CDD_ADC_GROUP_CNT][20U];

/*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Adc_VersionInfo;
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

/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

void Cdd_Adc_ADCA_Grp0NotifFunc()
{
    /* Read group results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_0,
                      &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_0][0]);
    /* Read the values from PPB1 */
    PpbFinalValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0] =
        Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0);
    PpbPartialValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0] =
        Cdd_Adc_ReadPartialPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0);
    Cdd_Adc_PpbValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0] =
        Cdd_Adc_ReadPpb(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0);

    /* Read the values from PPB1 */
    PpbFinalValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1] =
        Cdd_Adc_ReadPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1);
    PpbPartialValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1] =
        Cdd_Adc_ReadPartialPpbValue(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1);
    Cdd_Adc_PpbValue[CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1] =
        Cdd_Adc_ReadPpb(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1);
    /* Update group mask */
    Cdd_Adc_GroupMask |= (1 << CddAdcConf_CddAdcGroup_CddAdcGroup_0);
}

void Cdd_Adc_ADCA_Grp1NotifFunc()
{
    /* Read group results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_1,
                      &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_1][0]);
    /* Update group mask */
    Cdd_Adc_GroupMask |= (1 << CddAdcConf_CddAdcGroup_CddAdcGroup_1);
}

void Cdd_Adc_ADCB_Grp0NotifFunc()
{
    /* Read group results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_2,
                      &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_2][0]);
    /* Update group mask */
    Cdd_Adc_GroupMask |= (1 << CddAdcConf_CddAdcGroup_CddAdcGroup_2);
}

void Cdd_Adc_ADCB_Grp1NotifFunc()
{
    /* Read group results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_3,
                      &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_3][0]);
    /* Update group mask */
    Cdd_Adc_GroupMask |= (1 << CddAdcConf_CddAdcGroup_CddAdcGroup_3);
}

void Cdd_Adc_ADCC_Grp0NotifFunc()
{
    /* Read group results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_4,
                      &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_4][0]);
    /* Update group mask */
    Cdd_Adc_GroupMask |= (1 << CddAdcConf_CddAdcGroup_CddAdcGroup_4);
}

void Cdd_Adc_ADCC_Grp1NotifFunc()
{
    /* Read group results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_5,
                      &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_5][0]);
    /* Update group mask */
    Cdd_Adc_GroupMask |= (1 << CddAdcConf_CddAdcGroup_CddAdcGroup_5);
}

void Cdd_Adc_ADCD_GrpNotifFunc()
{
    /* Read group results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_6,
                      &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_6][0]);
    /* Update group mask */
    Cdd_Adc_GroupMask |= (1 << CddAdcConf_CddAdcGroup_CddAdcGroup_6);
}

void Cdd_Adc_ADCE_GrpNotifFunc()
{
    /* Read group results */
    Cdd_Adc_ReadGroup(CddAdcConf_CddAdcGroup_CddAdcGroup_7,
                      &Cdd_Adc_ResultBuffer[CddAdcConf_CddAdcGroup_CddAdcGroup_7][0]);
    /* Update group mask */
    Cdd_Adc_GroupMask |= (1 << CddAdcConf_CddAdcGroup_CddAdcGroup_7);
}

/* Configure PPB for one of the channels in group 1 */
void Cdd_Adc_TripHighNotification()
{
    /* Increment the count every time a trip high interrupt is generated */
    PpbTripHighCount++;
    return;
}

void Cdd_Adc_TripLowNotification()
{
    /* Increment the count every time a trip low interrupt is generated */
    PpbTripLowCount++;
    return;
}

int main()
{
    Std_ReturnType return_value;
    uint8          group_mask;
    DeviceSupport_Init();
    EcuM_Init();

    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Executing Cdd_Adc_Example_GlbSwTrig example\n");

#if (STD_ON == CDD_ADC_VERSION_INFO_API)
    Cdd_Adc_GetVersionInfo(&Cdd_Adc_VersionInfo);
    AppUtils_Printf("CDD ADC MCAL Version Info\n");
    AppUtils_Printf("---------------------\n");
    AppUtils_Printf("Vendor ID           : %d\n", Cdd_Adc_VersionInfo.vendorID);
    AppUtils_Printf("Module ID           : %d\n", Cdd_Adc_VersionInfo.moduleID);
    AppUtils_Printf("SW Major Version    : %d\n", Cdd_Adc_VersionInfo.sw_major_version);
    AppUtils_Printf("SW Minor Version    : %d\n", Cdd_Adc_VersionInfo.sw_minor_version);
    AppUtils_Printf("SW Patch Version    : %d\n", Cdd_Adc_VersionInfo.sw_patch_version);
#endif

    Cdd_Adc_ConfigTypePtr = &CDD_ADC_CONFIG_PC;
    group_mask = Cdd_Adc_ConfigTypePtr->glbtrigcfg[CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_0].group_mask;

    for (uint8 group = 0U; group < CDD_ADC_GROUP_CNT; group++)
    {
        /* Set group result buffer for all groups */
        Cdd_Adc_SetupResultBuffer(group, &Cdd_Adc_Buffer[group][0]);
        /* Enable group notification */
        Cdd_Adc_EnableGroupNotification(group);
    }

    /* Enable PPB notifications */
    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0, TRUE);
    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1, TRUE);

    /* Start Global software trigger 1 */
    return_value = Cdd_Adc_StartGlobalSwTrig(CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_0);

    if (return_value == E_OK)
    {
        AppUtils_Printf("Started globalswtrigger %d conversion\n",
                        CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_0);
        /* Wait until all the group conversions are done configured for the global software trigger
         */
        while ((Cdd_Adc_GroupMask != group_mask) || (PpbTripHighCount != 1U) || (PpbTripLowCount != 1U))
        {
            McalLib_Delay(100);
        }
    }
    else
    {
        AppUtils_Printf("Cdd_Adc_StartGlobalSwTrig API execution unsuccessful");
    }

    AppUtils_Printf("Completed globalswtrigger %d conversion\n",
                    CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_0);

    Cdd_Adc_GroupMask = 0U;
    /* Re-trigger the global software trigger */
    return_value = Cdd_Adc_StartGlobalSwTrig(CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_0);

    if (return_value == E_OK)
    {
        AppUtils_Printf("Re-triggers globalswtrigger %d conversion\n",
                        CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_0);
        /* Wait until all the group conversions are done configured for the global software trigger
         */
        while ((Cdd_Adc_GroupMask != group_mask) || (PpbTripHighCount != 2U) || (PpbTripLowCount != 2U))
        {
            McalLib_Delay(100);
        }
    }
    else
    {
        AppUtils_Printf("Cdd_Adc_StartGlobalSwTrig API execution unsuccessful");
    }

    AppUtils_Printf("Completed second round of globalswtrigger %d conversion\n",
                    CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_0);
    /* Stop the global software trigger once all the group conversions are done */
    Cdd_Adc_StopGlobalSwTrig(CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_0);

    /* Start Global software trigger 2 */
    Cdd_Adc_GroupMask = 0U;
    group_mask = Cdd_Adc_ConfigTypePtr->glbtrigcfg[CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_1].group_mask;

    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_0, TRUE);
    Cdd_Adc_ConfigurePpbNotification(CddAdcConf_CddAdcPpbConfig_CddAdcPpbConfig_1, TRUE);

    /* Enable group notifications for the groups configured for the global software trigger */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_0);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_2);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_4);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_6);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_7);

    return_value = Cdd_Adc_StartGlobalSwTrig(CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_1);

    if (return_value == E_OK)
    {
        AppUtils_Printf("Started globalswtrigger %d conversion\n",
                        CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_1);
        /* Wait until all the group conversions are done configured for the global software trigger and PPB interrupts
         * are received */
        while ((Cdd_Adc_GroupMask != group_mask) || (PpbTripHighCount != 3U) || (PpbTripLowCount != 3U))
        {
            McalLib_Delay(100);
        }
    }
    else
    {
        AppUtils_Printf("Cdd_Adc_StartGlobalSwTrig API execution unsuccessful");
    }

    AppUtils_Printf("Completed globalswtrigger %d conversion\n",
                    CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_1);

    /* Stop the global software trigger once all the group conversions are done */
    Cdd_Adc_StopGlobalSwTrig(CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_1);

    /* Start Global software trigger 3 */
    Cdd_Adc_GroupMask = 0U;
    group_mask = Cdd_Adc_ConfigTypePtr->glbtrigcfg[CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_2].group_mask;

    /* Enable group notifications for the groups configured for the global software trigger */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_3);
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_5);

    return_value = Cdd_Adc_StartGlobalSwTrig(CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_2);

    if (return_value == E_OK)
    {
        AppUtils_Printf("Started globalswtrigger %d conversion\n",
                        CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_2);
        /* Wait until all the group conversions are done configured for the global software trigger
         */
        while (Cdd_Adc_GroupMask != group_mask)
        {
            McalLib_Delay(100);
        }
    }
    else
    {
        AppUtils_Printf("Cdd_Adc_StartGlobalSwTrig API execution unsuccessful");
    }

    /* Stop the global software trigger once all the group conversions are done */
    Cdd_Adc_StopGlobalSwTrig(CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_2);

    AppUtils_Printf("Completed globalswtrigger %d conversion\n",
                    CddAdcConf_CddAdcGlobalSwTrigger_CddAdcGlobalSwTrigger_2);

    /* Enable group notification which is disabled by Cdd_Adc_StopGlobalSwTrig API */
    Cdd_Adc_EnableGroupNotification(CddAdcConf_CddAdcGroup_CddAdcGroup_1);
    Cdd_Adc_StartGroupConversion(CddAdcConf_CddAdcGroup_CddAdcGroup_1);

    AppUtils_Printf("Started software triggered group %d conversion\n", CddAdcConf_CddAdcGroup_CddAdcGroup_1);

    /* Wait until the software group conversion is done */
    while (Cdd_Adc_GetGroupStatus(CddAdcConf_CddAdcGroup_CddAdcGroup_1) != CDD_ADC_IDLE)
    {
        McalLib_Delay(10);
    }

    AppUtils_Printf("Completed software triggered group %d conversion\n", CddAdcConf_CddAdcGroup_CddAdcGroup_1);

    AppUtils_Printf("Example executed successfully\n");

    Cdd_Adc_DeInit();

    return 0;
}

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Example_GlbSwTrig.c
 *********************************************************************************************************************/
