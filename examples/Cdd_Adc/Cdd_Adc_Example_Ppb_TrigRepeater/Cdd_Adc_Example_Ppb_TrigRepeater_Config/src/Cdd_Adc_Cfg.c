
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
#if ((CDD_ADC_SW_MAJOR_VERSION != (2U)) || CDD_ADC_SW_MINOR_VERSION != (0U))
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


CONST(struct Cdd_Adc_ConfigTag, CDD_ADC_CONFIG_DATA) Cdd_Adc_ConfigSet1 =
{
    .hwunitcfg =
    {
                
        [0] =
        {
            .hwunit_id = (Cdd_Adc_HwUnitType)CDD_ADCA,
            .prescale = (Cdd_Adc_PrescaleType)CDD_ADC_CLK_DIV_3_5,
            .resolution = (Cdd_Adc_ResolutionType)CDD_ADC_RESOLUTION_16BIT,
            .signal_mode = (Cdd_Adc_SignalModeType)CDD_ADC_MODE_SINGLE_ENDED,
            .socpriority = (Cdd_Adc_SocPriorityType)10, 
            .voltref = (Cdd_Adc_RefVoltType)CDD_ADC_REFERENCE_2_5V,
            .voltrefmode = (Cdd_Adc_RefModeType)CDD_ADC_REFERENCE_INTERNAL,
            .startppbnum = (Cdd_Adc_PpbType)(0U),
            .ppbcount = (Cdd_Adc_PpbType)(3U),
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
            .lastgroupnum = (Cdd_Adc_GroupType)(3U),            
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*(0U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*(0U))
        },
        
        [1] =
        {
            .hwunit_id = (Cdd_Adc_HwUnitType)CDD_ADCD,
            .prescale = (Cdd_Adc_PrescaleType)CDD_ADC_CLK_DIV_3_5,
            .resolution = (Cdd_Adc_ResolutionType)CDD_ADC_RESOLUTION_12BIT,
            .signal_mode = (Cdd_Adc_SignalModeType)CDD_ADC_MODE_SINGLE_ENDED,
            .socpriority = (Cdd_Adc_SocPriorityType)0, 
            .voltref = (Cdd_Adc_RefVoltType)CDD_ADC_REFERENCE_3_3V,
            .voltrefmode = (Cdd_Adc_RefModeType)CDD_ADC_REFERENCE_INTERNAL,
            .startppbnum = (Cdd_Adc_PpbType)(3U),
            .ppbcount = (Cdd_Adc_PpbType)(0U),
            .intpulsemode = (Cdd_Adc_EocPulseType)CDD_ADC_PULSE_END_OF_ACQ_WIN,
            .intoffset = (uint16)60000U,
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)    
            .osdetectmode = ((Cdd_Adc_OsDetectModeType)CDD_ADC_OSDETECT_MODE_DISABLED),
#endif
#if(STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)     
            .extchnsel = (boolean)(0U),       
            .extmuxpreselect = (boolean)(0U),
#endif
            .startgroupnum = (Cdd_Adc_GroupType)(4U),
            .lastgroupnum = (Cdd_Adc_GroupType)(5U),            
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*(3U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*(3U))
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
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_Grp0Notification,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(4U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_REPEATER1),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_HW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_STREAMING,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(0U),
            .channelcount = (uint8)(2U),
            .soc_mask =  (uint32)(3U),
            .lastsocnum = (uint8)(1U)
        },
        
        [1] =
        {
            /* HwunitId: CDD_ADCA */
            .hwunit_index = (uint8)(0U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT2,
            .continuetoint = (boolean)(1U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_Grp1Notification,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(4U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_REPEATER2),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_HW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_STREAMING,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(2U),
            .channelcount = (uint8)(2U),
            .soc_mask =  (uint32)(12U),
            .lastsocnum = (uint8)(3U)
        },
        
        [2] =
        {
            /* HwunitId: CDD_ADCA */
            .hwunit_index = (uint8)(0U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT3,
            .continuetoint = (boolean)(1U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_Grp2Notification,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(4U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_CPU1INT0),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_HW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_STREAMING,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(4U),
            .channelcount = (uint8)(2U),
            .soc_mask =  (uint32)(48U),
            .lastsocnum = (uint8)(5U)
        },
        
        [3] =
        {
            /* HwunitId: CDD_ADCA */
            .hwunit_index = (uint8)(0U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT4,
            .continuetoint = (boolean)(1U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_Grp3Notification,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_REPEATER1),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_HW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_STREAMING,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(6U),
            .channelcount = (uint8)(1U),
            .soc_mask =  (uint32)(64U),
            .lastsocnum = (uint8)(6U)
        },
        
        [4] =
        {
            /* HwunitId: CDD_ADCD */
            .hwunit_index = (uint8)(1U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT1,
            .continuetoint = (boolean)(1U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_Hw1Grp0Notification,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(3U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_CONTINUOUS,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_STREAMING,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(7U),
            .channelcount = (uint8)(1U),
            .soc_mask =  (uint32)(1U),
            .lastsocnum = (uint8)(0U)
        },
        
        [5] =
        {
            /* HwunitId: CDD_ADCD */
            .hwunit_index = (uint8)(1U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT2,
            .continuetoint = (boolean)(1U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_ADCINT1,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_Hw1Grp1Notification,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(3U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_EPWM1_SOCA),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_HW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_STREAMING,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(8U),
            .channelcount = (uint8)(1U),
            .soc_mask =  (uint32)(2U),
            .lastsocnum = (uint8)(1U)
        }        
    },
    .ppbcfg =
    {                
        [0] =  
        {
            /* HwunitId: CDD_ADCA */
            .ppb_id = (Cdd_Adc_PpbIdType)(0U),
            .soc_num = (uint8)(6U),
            .hwunitindex = (uint8)(0U),
            .ppb_caloffset = (uint32)(0U),
            .ppb_refoffset = (uint32)(0U),
            .ppbresconfig = (uint16)((0x0000U) | ((0U)<<8U) | ((0U)<<7U) | ((0U)<<6U) | ((0U)<<5U)),
            .triplimithi = (sint32)10,
            .triplimitlow = (sint32)0,
            .tripevtsel = (uint8)((0x00U) | (0U) | (0U<<1U) | (0U<<2U)),
            .tripevtintsel = (uint8)((0x00U) | (1U) | ((1U)<<1U) | ((1U)<<2U)),
        #if(STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
            .ppbevtint_notification = (Cdd_Adc_PpbNotifyType)Cdd_Adc_Ppb0Notification,
        #endif
            .ppbcountlimit = (uint16)(1U),
            .ppbcfg2 = (uint16)((0x0000U) | (((uint8)CDD_ADC_COMPARE_PPBRESULT)<<14U) | (0U)),
            .tripfilterenable = (boolean)0U,
            .tripfilctl = (uint16)(0x0000U),     
            .tripfilclk = (uint16)(0x0000U)
        },

        [1] =  
        {
            /* HwunitId: CDD_ADCA */
            .ppb_id = (Cdd_Adc_PpbIdType)(1U),
            .soc_num = (uint8)(0U),
            .hwunitindex = (uint8)(0U),
            .ppb_caloffset = (uint32)(0U),
            .ppb_refoffset = (uint32)(0U),
            .ppbresconfig = (uint16)((0x0000U) | ((0U)<<8U) | ((1U)<<7U) | ((0U)<<6U) | ((0U)<<5U)),
            .triplimithi = (sint32)1000,
            .triplimitlow = (sint32)0,
            .tripevtsel = (uint8)((0x00U) | (0U) | (0U<<1U) | (0U<<2U)),
            .tripevtintsel = (uint8)((0x00U) | (1U) | ((1U)<<1U) | ((1U)<<2U)),
        #if(STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
            .ppbevtint_notification = (Cdd_Adc_PpbNotifyType)Cdd_Adc_Ppb1Notification,
        #endif
            .ppbcountlimit = (uint16)(4U),
            .ppbcfg2 = (uint16)((0x0000U) | (((uint8)CDD_ADC_COMPARE_PPBRESULT)<<14U) | (2U)),
            .tripfilterenable = (boolean)0U,
            .tripfilctl = (uint16)(0x0000U),     
            .tripfilclk = (uint16)(0x0000U)
        },

        [2] =  
        {
            /* HwunitId: CDD_ADCA */
            .ppb_id = (Cdd_Adc_PpbIdType)(2U),
            .soc_num = (uint8)(2U),
            .hwunitindex = (uint8)(0U),
            .ppb_caloffset = (uint32)(0U),
            .ppb_refoffset = (uint32)(0U),
            .ppbresconfig = (uint16)((0x0000U) | ((0U)<<8U) | ((0U)<<7U) | ((1U)<<6U) | ((0U)<<5U)),
            .triplimithi = (sint32)10,
            .triplimitlow = (sint32)0,
            .tripevtsel = (uint8)((0x00U) | (0U) | (0U<<1U) | (0U<<2U)),
            .tripevtintsel = (uint8)((0x00U) | (1U) | ((1U)<<1U) | ((1U)<<2U)),
        #if(STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
            .ppbevtint_notification = (Cdd_Adc_PpbNotifyType)Cdd_Adc_Ppb2Notification,
        #endif
            .ppbcountlimit = (uint16)(4U),
            .ppbcfg2 = (uint16)((0x0000U) | (((uint8)CDD_ADC_COMPARE_PPBPSUM)<<14U) | (2U)),
            .tripfilterenable = (boolean)0U,
            .tripfilctl = (uint16)(0x0000U),     
            .tripfilclk = (uint16)(0x0000U)
        }
    },
    .channelcfg =
    {        
        [0] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(0U),
            .sample_window = (uint16)(64U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(0U)
        },
        
        [1] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(1U),
            .sample_window = (uint16)(64U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(1U)
        },
        
        [2] =
        {
            /* HwunitId:CDD_ADCA Group:1 */
            .channel_id = (uint8)(2U),
            .sample_window = (uint16)(64U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(2U)
        },
        
        [3] =
        {
            /* HwunitId:CDD_ADCA Group:1 */
            .channel_id = (uint8)(3U),
            .sample_window = (uint16)(64U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(3U)
        },
        
        [4] =
        {
            /* HwunitId:CDD_ADCA Group:2 */
            .channel_id = (uint8)(25U),
            .sample_window = (uint16)(64U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(4U)
        },
        
        [5] =
        {
            /* HwunitId:CDD_ADCA Group:2 */
            .channel_id = (uint8)(5U),
            .sample_window = (uint16)(64U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(5U)
        },
        
        [6] =
        {
            /* HwunitId:CDD_ADCA Group:3 */
            .channel_id = (uint8)(26U),
            .sample_window = (uint16)(64U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(6U)
        },
        
        [7] =
        {
            /* HwunitId:CDD_ADCD Group:0 */
            .channel_id = (uint8)(24U),
            .sample_window = (uint16)(30U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(0U)
        },
        
        [8] =
        {
            /* HwunitId:CDD_ADCD Group:1 */
            .channel_id = (uint8)(25U),
            .sample_window = (uint16)(30U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(1U)
        }        
    },
    .repunitcfg =
    {        
        [0] =
        {
            .hwunit_index = (uint8)(0U),
            .repeater_instance = (Cdd_Adc_RepeaterType)CDD_ADC_REPINST1,
            .repeater_mode = (Cdd_Adc_RepeaterModeType)CDD_ADC_REPMODE_OVERSAMPLING,
            .trigger_source = (Cdd_Adc_TriggerType)CDD_ADC_TRIGGER_CPU1INT0,
            .repeater_count =  (uint8)(4U),
            .repeater_phase =  (uint16)(0U),
            .repeater_spread =  (uint16)(0U)
        },

        [1] =
        {
            .hwunit_index = (uint8)(0U),
            .repeater_instance = (Cdd_Adc_RepeaterType)CDD_ADC_REPINST2,
            .repeater_mode = (Cdd_Adc_RepeaterModeType)CDD_ADC_REPMODE_UNDERSAMPLING,
            .trigger_source = (Cdd_Adc_TriggerType)CDD_ADC_TRIGGER_CPU1INT0,
            .repeater_count =  (uint8)(4U),
            .repeater_phase =  (uint16)(0U),
            .repeater_spread =  (uint16)(0U)
        }
    },
    .test_input = (Cdd_Adc_InternalTestNodeType)CDD_ADC_TEST_NODE_NO_CONN,
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
