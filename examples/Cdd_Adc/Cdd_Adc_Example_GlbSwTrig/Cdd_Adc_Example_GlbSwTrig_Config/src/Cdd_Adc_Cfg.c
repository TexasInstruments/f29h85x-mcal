
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
#if ((CDD_ADC_SW_MAJOR_VERSION != (1U)) || CDD_ADC_SW_MINOR_VERSION != (0U))
  #error "Version numbers of Cdd_Adc_Cfg.c and Cdd_Adc.h are inconsistent!"
#endif

#if ( (CDD_ADC_CFG_MAJOR_VERSION != (1U)) \
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


CONST(struct Cdd_Adc_ConfigTag, CDD_ADC_CONFIG_DATA) CddAdcConfigSet =
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
            .startppbnum = (Cdd_Adc_PpbType)(0U),
            .ppbcount = (Cdd_Adc_PpbType)(2U),
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
            .lastgroupnum = (Cdd_Adc_GroupType)(1U),            
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*(0U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*(0U))
        },
        
        [1] =
        {
            .hwunit_id = (Cdd_Adc_HwUnitType)CDD_ADCB,
            .prescale = (Cdd_Adc_PrescaleType)CDD_ADC_CLK_DIV_3_5,
            .resolution = (Cdd_Adc_ResolutionType)CDD_ADC_RESOLUTION_12BIT,
            .signal_mode = (Cdd_Adc_SignalModeType)CDD_ADC_MODE_SINGLE_ENDED,
            .socpriority = (Cdd_Adc_SocPriorityType)0, 
            .voltref = (Cdd_Adc_RefVoltType)CDD_ADC_REFERENCE_2_5V,
            .voltrefmode = (Cdd_Adc_RefModeType)CDD_ADC_REFERENCE_INTERNAL,
            .startppbnum = (Cdd_Adc_PpbType)(2U),
            .ppbcount = (Cdd_Adc_PpbType)(0U),
            .intpulsemode = (Cdd_Adc_EocPulseType)CDD_ADC_PULSE_END_OF_CONV,
            .intoffset = (uint16)0U,
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)    
            .osdetectmode = ((Cdd_Adc_OsDetectModeType)CDD_ADC_OSDETECT_MODE_DISABLED),
#endif
#if(STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)     
            .extchnsel = (boolean)(0U),       
            .extmuxpreselect = (boolean)(0U),
#endif
            .startgroupnum = (Cdd_Adc_GroupType)(2U),
            .lastgroupnum = (Cdd_Adc_GroupType)(3U),            
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*(1U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*(1U))
        },
        
        [2] =
        {
            .hwunit_id = (Cdd_Adc_HwUnitType)CDD_ADCC,
            .prescale = (Cdd_Adc_PrescaleType)CDD_ADC_CLK_DIV_3_5,
            .resolution = (Cdd_Adc_ResolutionType)CDD_ADC_RESOLUTION_12BIT,
            .signal_mode = (Cdd_Adc_SignalModeType)CDD_ADC_MODE_SINGLE_ENDED,
            .socpriority = (Cdd_Adc_SocPriorityType)0, 
            .voltref = (Cdd_Adc_RefVoltType)CDD_ADC_REFERENCE_2_5V,
            .voltrefmode = (Cdd_Adc_RefModeType)CDD_ADC_REFERENCE_INTERNAL,
            .startppbnum = (Cdd_Adc_PpbType)(2U),
            .ppbcount = (Cdd_Adc_PpbType)(0U),
            .intpulsemode = (Cdd_Adc_EocPulseType)CDD_ADC_PULSE_END_OF_CONV,
            .intoffset = (uint16)0U,
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)    
            .osdetectmode = ((Cdd_Adc_OsDetectModeType)CDD_ADC_OSDETECT_MODE_DISABLED),
#endif
#if(STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)     
            .extchnsel = (boolean)(0U),       
            .extmuxpreselect = (boolean)(0U),
#endif
            .startgroupnum = (Cdd_Adc_GroupType)(4U),
            .lastgroupnum = (Cdd_Adc_GroupType)(5U),            
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*(2U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*(2U))
        },
        
        [3] =
        {
            .hwunit_id = (Cdd_Adc_HwUnitType)CDD_ADCD,
            .prescale = (Cdd_Adc_PrescaleType)CDD_ADC_CLK_DIV_3_5,
            .resolution = (Cdd_Adc_ResolutionType)CDD_ADC_RESOLUTION_12BIT,
            .signal_mode = (Cdd_Adc_SignalModeType)CDD_ADC_MODE_SINGLE_ENDED,
            .socpriority = (Cdd_Adc_SocPriorityType)0, 
            .voltref = (Cdd_Adc_RefVoltType)CDD_ADC_REFERENCE_2_5V,
            .voltrefmode = (Cdd_Adc_RefModeType)CDD_ADC_REFERENCE_INTERNAL,
            .startppbnum = (Cdd_Adc_PpbType)(2U),
            .ppbcount = (Cdd_Adc_PpbType)(0U),
            .intpulsemode = (Cdd_Adc_EocPulseType)CDD_ADC_PULSE_END_OF_CONV,
            .intoffset = (uint16)0U,
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)    
            .osdetectmode = ((Cdd_Adc_OsDetectModeType)CDD_ADC_OSDETECT_MODE_DISABLED),
#endif
#if(STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)     
            .extchnsel = (boolean)(0U),       
            .extmuxpreselect = (boolean)(0U),
#endif
            .startgroupnum = (Cdd_Adc_GroupType)(6U),
            .lastgroupnum = (Cdd_Adc_GroupType)(6U),            
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*(3U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*(3U))
        },
        
        [4] =
        {
            .hwunit_id = (Cdd_Adc_HwUnitType)CDD_ADCE,
            .prescale = (Cdd_Adc_PrescaleType)CDD_ADC_CLK_DIV_3_5,
            .resolution = (Cdd_Adc_ResolutionType)CDD_ADC_RESOLUTION_12BIT,
            .signal_mode = (Cdd_Adc_SignalModeType)CDD_ADC_MODE_SINGLE_ENDED,
            .socpriority = (Cdd_Adc_SocPriorityType)0, 
            .voltref = (Cdd_Adc_RefVoltType)CDD_ADC_REFERENCE_2_5V,
            .voltrefmode = (Cdd_Adc_RefModeType)CDD_ADC_REFERENCE_INTERNAL,
            .startppbnum = (Cdd_Adc_PpbType)(2U),
            .ppbcount = (Cdd_Adc_PpbType)(0U),
            .intpulsemode = (Cdd_Adc_EocPulseType)CDD_ADC_PULSE_END_OF_CONV,
            .intoffset = (uint16)0U,
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)    
            .osdetectmode = ((Cdd_Adc_OsDetectModeType)CDD_ADC_OSDETECT_MODE_DISABLED),
#endif
#if(STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)     
            .extchnsel = (boolean)(0U),       
            .extmuxpreselect = (boolean)(0U),
#endif
            .startgroupnum = (Cdd_Adc_GroupType)(7U),
            .lastgroupnum = (Cdd_Adc_GroupType)(7U),            
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*(4U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*(4U))
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
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_ADCA_Grp0NotifFunc,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_SINGLE,
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
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_ADCA_Grp1NotifFunc,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_SINGLE,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(2U),
            .channelcount = (uint8)(1U),
            .soc_mask =  (uint32)(4U),
            .lastsocnum = (uint8)(2U)
        },
        
        [2] =
        {
            /* HwunitId: CDD_ADCB */
            .hwunit_index = (uint8)(1U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT1,
            .continuetoint = (boolean)(1U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_ADCB_Grp0NotifFunc,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_SINGLE,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(3U),
            .channelcount = (uint8)(2U),
            .soc_mask =  (uint32)(3U),
            .lastsocnum = (uint8)(1U)
        },
        
        [3] =
        {
            /* HwunitId: CDD_ADCB */
            .hwunit_index = (uint8)(1U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT2,
            .continuetoint = (boolean)(0U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_ADCB_Grp1NotifFunc,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_SINGLE,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(5U),
            .channelcount = (uint8)(1U),
            .soc_mask =  (uint32)(4U),
            .lastsocnum = (uint8)(2U)
        },
        
        [4] =
        {
            /* HwunitId: CDD_ADCC */
            .hwunit_index = (uint8)(2U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT1,
            .continuetoint = (boolean)(1U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_ADCC_Grp0NotifFunc,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_SINGLE,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(6U),
            .channelcount = (uint8)(2U),
            .soc_mask =  (uint32)(3U),
            .lastsocnum = (uint8)(1U)
        },
        
        [5] =
        {
            /* HwunitId: CDD_ADCC */
            .hwunit_index = (uint8)(2U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT2,
            .continuetoint = (boolean)(0U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_ADCC_Grp1NotifFunc,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_SINGLE,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(8U),
            .channelcount = (uint8)(1U),
            .soc_mask =  (uint32)(4U),
            .lastsocnum = (uint8)(2U)
        },
        
        [6] =
        {
            /* HwunitId: CDD_ADCD */
            .hwunit_index = (uint8)(3U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT1,
            .continuetoint = (boolean)(0U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_ADCD_GrpNotifFunc,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_SINGLE,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(9U),
            .channelcount = (uint8)(2U),
            .soc_mask =  (uint32)(3U),
            .lastsocnum = (uint8)(1U)
        },
        
        [7] =
        {
            /* HwunitId: CDD_ADCE */
            .hwunit_index = (uint8)(4U),
            .grp_int = (Cdd_Adc_IntNumType)CDD_ADC_INT1,
            .continuetoint = (boolean)(0U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)CDD_ADC_INT_SOC_TRIGGER_NONE,
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)Cdd_Adc_ADCE_GrpNotifFunc,
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)(1U),
            .trigger_src = (Cdd_Adc_TriggerType)(CDD_ADC_TRIGGER_SW_ONLY),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)CDD_ADC_CONV_MODE_ONESHOT,
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)CDD_ADC_TRIGG_SRC_SW,
            .access_mode = (Cdd_Adc_GroupAccessModeType)CDD_ADC_ACCESS_MODE_SINGLE,
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)CDD_ADC_STREAM_BUFFER_LINEAR,
            .startchannelnum = (uint8)(11U),
            .channelcount = (uint8)(2U),
            .soc_mask =  (uint32)(3U),
            .lastsocnum = (uint8)(1U)
        }        
    },
    .glbtrigcfg =
    {                
        [0] =
        {            
            .hwunit_mask = (uint8)(7U),
            .soc_mask = (uint32)(7U),
            .group_mask = (uint32)(63)
        },
        
        [1] =
        {            
            .hwunit_mask = (uint8)(31U),
            .soc_mask = (uint32)(3U),
            .group_mask = (uint32)(213)
        },
        
        [2] =
        {            
            .hwunit_mask = (uint8)(7U),
            .soc_mask = (uint32)(4U),
            .group_mask = (uint32)(42)
        }
    },
    .ppbcfg =
    {                
        [0] =  
        {
            /* HwunitId: CDD_ADCA */
            .ppb_id = (Cdd_Adc_PpbIdType)(0U),
            .soc_num = (uint8)(0U),
            .hwunitindex = (uint8)(0U),
            .ppb_caloffset = (uint32)(100U),
            .ppb_refoffset = (uint32)(100U),
            .ppbresconfig = (uint16)((0x0000U) | ((0U)<<8U) | ((0U)<<7U) | ((0U)<<6U) | ((0U)<<5U)),
            .triplimithi = (sint32)30000,
            .triplimitlow = (sint32)1000,
            .tripevtsel = (uint8)((0x00U) | (0U) | (0U<<1U) | (0U<<2U)),
            .tripevtintsel = (uint8)((0x00U) | (0U) | ((1U)<<1U) | ((1U)<<2U)),
        #if(STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
            .ppbevtint_notification = (Cdd_Adc_PpbNotifyType)Cdd_Adc_TripLowNotification,
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
            .ppb_caloffset = (uint32)(100U),
            .ppb_refoffset = (uint32)(100U),
            .ppbresconfig = (uint16)((0x0000U) | ((0U)<<8U) | ((0U)<<7U) | ((1U)<<6U) | ((0U)<<5U)),
            .triplimithi = (sint32)0,
            .triplimitlow = (sint32)-3000,
            .tripevtsel = (uint8)((0x00U) | (0U) | (0U<<1U) | (0U<<2U)),
            .tripevtintsel = (uint8)((0x00U) | (1U) | ((0U)<<1U) | ((0U)<<2U)),
        #if(STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
            .ppbevtint_notification = (Cdd_Adc_PpbNotifyType)Cdd_Adc_TripHighNotification,
        #endif
            .ppbcountlimit = (uint16)(1U),
            .ppbcfg2 = (uint16)((0x0000U) | (((uint8)CDD_ADC_COMPARE_PPBRESULT)<<14U) | (0U)),
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
            .channel_id = (uint8)(1U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(0U)
        },
        
        [1] =
        {
            /* HwunitId:CDD_ADCA Group:0 */
            .channel_id = (uint8)(2U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(1U)
        },
        
        [2] =
        {
            /* HwunitId:CDD_ADCA Group:1 */
            .channel_id = (uint8)(25U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(2U)
        },
        
        [3] =
        {
            /* HwunitId:CDD_ADCB Group:0 */
            .channel_id = (uint8)(1U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(0U)
        },
        
        [4] =
        {
            /* HwunitId:CDD_ADCB Group:0 */
            .channel_id = (uint8)(2U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(1U)
        },
        
        [5] =
        {
            /* HwunitId:CDD_ADCB Group:1 */
            .channel_id = (uint8)(6U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(2U)
        },
        
        [6] =
        {
            /* HwunitId:CDD_ADCC Group:0 */
            .channel_id = (uint8)(25U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(0U)
        },
        
        [7] =
        {
            /* HwunitId:CDD_ADCC Group:0 */
            .channel_id = (uint8)(27U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(1U)
        },
        
        [8] =
        {
            /* HwunitId:CDD_ADCC Group:1 */
            .channel_id = (uint8)(6U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(2U)
        },
        
        [9] =
        {
            /* HwunitId:CDD_ADCD Group:0 */
            .channel_id = (uint8)(24U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(0U)
        },
        
        [10] =
        {
            /* HwunitId:CDD_ADCD Group:0 */
            .channel_id = (uint8)(26U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(1U)
        },
        
        [11] =
        {
            /* HwunitId:CDD_ADCE Group:0 */
            .channel_id = (uint8)(1U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(0U)
        },
        
        [12] =
        {
            /* HwunitId:CDD_ADCE Group:0 */
            .channel_id = (uint8)(26U),
            .sample_window = (uint16)(20U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)(0U),
#endif   
            .soc_num =  (uint8)(1U)
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
