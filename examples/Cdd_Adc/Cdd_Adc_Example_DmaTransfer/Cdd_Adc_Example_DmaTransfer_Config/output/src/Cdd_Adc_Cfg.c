
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
 *  File:       Cdd_Adc_Cfg.c
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  Cdd_Adc configuration source file                                                       
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/
#include "Cdd_Adc.h"
#include "hw_memmap.h"

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/
#if ((CDD_ADC_SW_MAJOR_VERSION != (2U)) || (CDD_ADC_SW_MINOR_VERSION != (0U)))
  #error "Version numbers of Cdd_Adc_Cfg.c and Cdd_Adc.h are inconsistent!"
#endif

#if ( (CDD_ADC_CFG_MAJOR_VERSION != (2U)) \
    ||(CDD_ADC_CFG_MINOR_VERSION != (0U)))
  #error "Version numbers of Cdd_Adc_Cfg.c and Cdd_Adc_Cfg.h are inconsistent!"
#endif

/*********************************************************************************************************************
 * Local Preprocessor #define Constants
 *********************************************************************************************************************/

#define CDD_ADC_BASEADDR_STEP             (ADCB_BASE - ADCA_BASE)
#define CDD_ADC_RESULTBASEADDR_STEP       (ADCBRESULT_BASE - ADCARESULT_BASE)
#define CDD_ADC_CHECKER_BASEADDR_STEP     (ADCSAFETYCHECK2_BASE - ADCSAFETYCHECK1_BASE)
#define CDD_ADC_CHECKERINTEVTBASE_STEP    (ADCSAFETYCHECKINTEVT2_BASE - ADCSAFETYCHECKINTEVT1_BASE)

/*********************************************************************************************************************
 * Local Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
/** \brief Cdd Adc Driver configuration */

#define CDD_ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cdd_Adc_MemMap.h"



CONST(struct Cdd_Adc_ConfigTag, CDD_ADC_CONFIG_DATA) Cdd_Adc_Config =
{
    .hwunitcfg =
    {
                
        [0] =
        {
            .hwunit_id = (Cdd_Adc_HwUnitType)CDD_ADCA,
            .prescale = (Cdd_Adc_PrescaleType)CDD_ADC_CLK_DIV_3_5,
            .resolution = (Cdd_Adc_ResolutionType)CDD_ADC_RESOLUTION_12BIT,
            .signal_mode = (Cdd_Adc_SignalModeType)CDD_ADC_MODE_SINGLE_ENDED,
            .socpriority = (Cdd_Adc_SocPriorityType)0, 
            .voltref = (Cdd_Adc_RefVoltType)CDD_ADC_REFERENCE_2_5V,
            .voltrefmode = (Cdd_Adc_RefModeType)CDD_ADC_REFERENCE_INTERNAL,
            .intpulsemode = (Cdd_Adc_EocPulseType)CDD_ADC_PULSE_END_OF_CONV,
            .intoffset = (uint16)0U,
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)    
            .osdetectmode = ((Cdd_Adc_OsDetectModeType)CDD_ADC_OSDETECT_MODE_DISABLED),
#endif
#if(STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)     
            .extchnsel = (boolean)(0U),       
            .extmuxpreselect = (boolean)(0U),
#endif
            .startgroupnum = (Cdd_Adc_GroupType)(0U),
            .lastgroupnum = (Cdd_Adc_GroupType)(0U),            
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*(0U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*(0U))
        }        
    },
    .groupcfg  =
    {        
        [0] =
        {
            /* HwunitId: CDD_ADCA */
            .hwunit_index = (uint8)(0U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT1,
            .continuetoint = (boolean)(1U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)NULL_PTR,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(32U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_EPWM1_SOCA),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_HW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_STREAMING,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_CIRCULAR,
            .startchannelnum = (uint8)(0U),
            .channelcount = (uint8)(8U),
            .soc_mask =  (uint32)(255U),
            .lastsocnum = (uint8)(7U),
            .dma_mode = ((boolean)(1U))
        }        
    },
    .channelcfg =
    {        
        [0] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(0U),
            .sample_window = (uint16)(15U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(0U)
        },
        
        [1] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(1U),
            .sample_window = (uint16)(15U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(1U)
        },
        
        [2] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(4U),
            .sample_window = (uint16)(15U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(2U)
        },
        
        [3] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(5U),
            .sample_window = (uint16)(15U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(3U)
        },
        
        [4] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(6U),
            .sample_window = (uint16)(15U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(4U)
        },
        
        [5] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(7U),
            .sample_window = (uint16)(15U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(5U)
        },
        
        [6] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(28U),
            .sample_window = (uint16)(15U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(6U)
        },
        
        [7] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(29U),
            .sample_window = (uint16)(15U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(7U)
        }        
    },
    .test_input = (Cdd_Adc_InternalTestNodeType)CDD_ADC_TEST_NODE_NO_CONN
};


#define CDD_ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cdd_Adc_MemMap.h"

/*********************************************************************************************************************
 * Local Object Definitions
 *********************************************************************************************************************/

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

/*********************************************************************************************************************
 *  End of File: Cdd_Adc_Cfg.c
 *********************************************************************************************************************/
