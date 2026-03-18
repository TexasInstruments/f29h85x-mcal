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
 *  File:         Cdd_Xbar_Gpio_interrupt.c
 *  Generator:    None
 *
 *  Description:  This example application demonstrates the external interrupt feature by using it in conjunction with
 *  the input and output XBARs.
 *  The GPIO is toggled and connected to the input XBAR, while simultaneously triggering an external interrupt on the
 *  rising edge at the GPIO pin using XINT1(External Interrupt 1) during init.
 *  The example also demonstrates reconfiguration of external interrupt edge using API.
 *  The interrupt increments a counter 'count'.
 *  In addition to triggering an interrupt, the input signal is routed from the input XBAR to the output XBAR so that
 *  the output can be observed via oscilloscope or logic analyzer on a separate pin.
 *                             ___________           ________________
 *                GPIO0-------|INPUT XBAR1|---------| OUTPUT XBAR 1  |-------GPIO2
 *                            |           |         |________________|
 *                            |           |
 *                            |___________|---------triggers interrupt using XINT1
 *
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "AppUtils.h"
#include "DeviceSupport.h"
#include "EcuM.h"
#include "Dio.h"
#include "Cdd_Xbar.h"
#include "Mcal_Lib.h"

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
Dio_LevelType          Dio_ChannelLevel;
static volatile uint32 count     = 0U;
static boolean         status    = TRUE;
uint16                 hwCounter = 0U;
Std_ReturnType         retval    = E_NOT_OK;
#if (STD_ON == CDD_XBAR_GET_VERSION_INFO_API)
/*  Version info variable */
Std_VersionInfoType Cdd_Xbar_VersionInfo;
#endif
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
    uint8 loop;
    DeviceSupport_Init();

    /* Configure the crossbar and init MCU - external interrupt is configured during init as positive edge/rising edge
     */
    EcuM_Init();

    AppUtils_Init(200000000U);  // Init App utils to enable prints
    AppUtils_Printf("Sample Application - STARTS !!!\n");
    AppUtils_Printf(
        "---------------------------------------------------------------------------------"
        "\n");

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

    AppUtils_Printf("Phase 1: External interrupt is enabled with positive edge from configurator...\n");
    count = 0U; /* Reset counter */

    for (loop = 0U; loop < 0xFFU; loop++)
    {
        /* Setting the GPIO0 to STD_LOW */
        Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_LOW);
        /* Reading the value at OUTPUTXBAR1 */
        Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_OUTPUTXBAR1);
        if (STD_LOW == Dio_ChannelLevel)
        {
            /* Setting the GPIO0 to STD_HIGH */
            Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_HIGH);
            /* Reading the value at OUTPUTXBAR1 */
            Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_OUTPUTXBAR1);
            if (STD_HIGH != Dio_ChannelLevel)
            {
                status = FALSE;
                break;
            }
        }
        else
        {
            status = FALSE;
            break;
        }
    }

    /* Read hardware counter value */
    retval = Cdd_Xbar_GetExternalInterruptCounter(
        CddXbarConf_CddXbarInputXbarInstanceConfig_CddXbarInputXbarInstanceConfig_0, &hwCounter);

    if ((status == TRUE) && (count == 0xFFU))
    {
        AppUtils_Printf("count (POSITIVE_EDGE): %d\n", count);
        if (E_OK == retval)
        {
            AppUtils_Printf("Hardware Counter (XINT1): %d\n", hwCounter);
        }
        else
        {
            AppUtils_Printf("ERROR: Failed to read hardware counter\n");
            status = FALSE;
        }
        AppUtils_Printf("PASS\n");
    }
    else
    {
        AppUtils_Printf("count: %d\n", count);
        AppUtils_Printf("FAIL\n");
        status = FALSE;
    }

    AppUtils_Printf(
        "---------------------------------------------------------------------------------"
        "\n");

    /* Phase 2: Change interrupt type using API and test again */
    AppUtils_Printf("Phase 2: Changing interrupt type to BOTH_EDGES using Cdd_Xbar_SetExternalInterruptType API...\n");
    retval = Cdd_Xbar_SetExternalInterruptType(
        CddXbarConf_CddXbarInputXbarInstanceConfig_CddXbarInputXbarInstanceConfig_0, CDD_XBAR_INT_TYPE_BOTH_EDGES);

    if (E_OK != retval)
    {
        AppUtils_Printf("ERROR: Failed to set external interrupt type to BOTH_EDGES\n");
        AppUtils_Printf("FAIL\n");
        status = FALSE;
    }
    else
    {
        /* Resetting the GPIO0 to STD_LOW */
        Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_LOW);
        McalLib_Delay(1);
        count = 0U; /* Reset counter */

        for (loop = 0U; loop < 0xFFU; loop++)
        {
            /* Setting the GPIO0 to STD_HIGH */
            Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_HIGH);
            /* Reading the value at OUTPUTXBAR1 */
            Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_OUTPUTXBAR1);
            if (STD_HIGH == Dio_ChannelLevel)
            {
                /* Setting the GPIO0 to STD_LOW */
                Dio_WriteChannel(DioConf_DioChannel_GPIO0, STD_LOW);
                /* Reading the value at OUTPUTXBAR1 */
                Dio_ChannelLevel = Dio_ReadChannel(DioConf_DioChannel_OUTPUTXBAR1);
                if (STD_LOW != Dio_ChannelLevel)
                {
                    status = FALSE;
                    break;
                }
            }
            else
            {
                status = FALSE;
                break;
            }
        }

        /* Read hardware counter value using the new API */
        retval = Cdd_Xbar_GetExternalInterruptCounter(
            CddXbarConf_CddXbarInputXbarInstanceConfig_CddXbarInputXbarInstanceConfig_0, &hwCounter);

        if ((status == TRUE) && (count == 2U * 0xFFU))
        {
            AppUtils_Printf("count (BOTH_EDGES): %d\n", count);
            if (E_OK == retval)
            {
                AppUtils_Printf("Hardware Counter (XINT1): %d\n", hwCounter);
            }
            else
            {
                AppUtils_Printf("ERROR: Failed to read hardware counter\n");
                status = FALSE;
            }
            AppUtils_Printf("PASS\n");
        }
        else
        {
            AppUtils_Printf("count: %d\n", count);
            AppUtils_Printf("FAIL\n");
            status = FALSE;
        }
    }

    AppUtils_Printf("Disabling external interrupt\n");
    retval = Cdd_Xbar_SetExternalInterruptState(
        CddXbarConf_CddXbarInputXbarInstanceConfig_CddXbarInputXbarInstanceConfig_0, FALSE);

    if (E_OK != retval)
    {
        AppUtils_Printf("ERROR: Failed to disable external interrupt\n");
        status = FALSE;
    }

    AppUtils_Printf(
        "================================================================================="
        "\n");

    if (status == TRUE)
    {
        AppUtils_Printf("PASS: Cdd_Xbar_Gpio_interrupt Sample application passed \n");
    }
    else
    {
        AppUtils_Printf("FAIL: Cdd_Xbar_Gpio_interrupt Sample application failed \n");
    }

    return 0;
}

void ISR_GPIO_XINT(void)
{
    count++;
}
/*********************************************************************************************************************
 *  Local Functions Definition
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  End of File: Cdd_Xbar_Gpio_interrupt.c
 *********************************************************************************************************************/
