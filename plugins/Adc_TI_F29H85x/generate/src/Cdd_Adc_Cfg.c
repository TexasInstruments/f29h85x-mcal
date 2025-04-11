[!SKIPFILE "node:value(as:modconf('Cdd_Adc/Cdd')[1]/IMPLEMENTATION_CONFIG_VARIANT) != 'VariantPreCompile'"!]
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
 *                 (C) Copyright [!"substring-before($date,'-')"!] Texas Instruments Inc.  All rights reserved.
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

#if ( (CDD_ADC_CFG_MAJOR_VERSION != ([!"substring-before($moduleSoftwareVer,'.')"!]U)) \
    ||(CDD_ADC_CFG_MINOR_VERSION != ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)))
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
[!VAR "AdcNum"   = "0"!][!//
[!MACRO "GetAdcNum", "HwUnit"!]
[!NOCODE!]

    [!IF "($HwUnit = 'CDD_ADCA')"!]
    [!VAR "AdcNum"   = "0"!]
    [!ENDIF!]

    [!IF "($HwUnit = 'CDD_ADCB')"!]
    [!VAR "AdcNum"   = "1"!]
    [!ENDIF!]


    [!IF "($HwUnit = 'CDD_ADCC')"!]
    [!VAR "AdcNum"   = "2"!]
    [!ENDIF!]


    [!IF "($HwUnit = 'CDD_ADCD')"!]
    [!VAR "AdcNum"   = "3"!]
    [!ENDIF!]


    [!IF "($HwUnit = 'CDD_ADCE')"!]
    [!VAR "AdcNum"   = "4"!]
    [!ENDIF!]

[!CODE!][!"num:i($AdcNum)"!][!ENDCODE!]
[!ENDNOCODE!][!ENDMACRO!]
/*********************************************************************************************************************
 * Local Type Declarations
 *********************************************************************************************************************/

 /*********************************************************************************************************************
 * Exported Object Definitions
 *********************************************************************************************************************/
/** \brief Cdd Adc Driver configuration */

#define CDD_ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Cdd_Adc_MemMap.h"
[!//
[!NOCODE!]
[!VAR "RepCount" = "num:i(0)"!]
[!VAR "TrigRepEnable" = "num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*/CddAdcTriggerRepeater/*))"!]
[!VAR "GroupCount" = "0"!]
[!VAR "HwGroup0Cnt" ="num:i(0)"!]
[!VAR "HwGroup1Cnt" ="num:i($HwGroup0Cnt+num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*[1]/CddAdcGroup/*)))"!]
[!VAR "HwGroup2Cnt" ="num:i($HwGroup1Cnt+num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*[2]/CddAdcGroup/*)))"!]
[!VAR "HwGroup3Cnt" ="num:i($HwGroup2Cnt+num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*[3]/CddAdcGroup/*)))"!]
[!VAR "HwGroup4Cnt" ="num:i($HwGroup3Cnt+num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*[4]/CddAdcGroup/*)))"!]
[!ENDNOCODE!][!//

[!LOOP "as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet"!]
CONST(struct Cdd_Adc_ConfigTag, CDD_ADC_CONFIG_DATA) Cdd_Adc_ConfigSet[!"@index"!] =
{
    .hwunitcfg =
    {
        [!NOCODE!][!VAR "PpbCount" = "num:i(0)"!][!VAR "HwGroupCount" = "num:i(0)"!][!ENDNOCODE!][!//
        [!LOOP "CddAdcHwUnit/*"!]
        [[!"@index"!]] =
        {
            .hwunit_id = (Cdd_Adc_HwUnitType)[!"CddAdcHwInstance"!],
            .prescale = (Cdd_Adc_PrescaleType)[!"CddAdcHwUnitClockPrescale"!],
            .resolution = (Cdd_Adc_ResolutionType)[!"CddAdcHwUnitResolution"!],
            .signal_mode = (Cdd_Adc_SignalModeType)[!"CddAdcHwUnitSignalMode"!],
            .socpriority = (Cdd_Adc_SocPriorityType)[!"CddAdcSocPriorityMode"!], 
            .voltref = (Cdd_Adc_RefVoltType)[!IF "(CddAdcHwInstance ='CDD_ADCA' or CddAdcHwInstance = 'CDD_ADCB')"!][!"../../CddAdcHwUnitAnalogRefABVoltage"!][!ELSE!][!"../../CddAdcHwUnitAnalogRefCDEVoltage"!][!ENDIF!],
            .voltrefmode = (Cdd_Adc_RefModeType)[!IF "(CddAdcHwInstance ='CDD_ADCA' or CddAdcHwInstance='CDD_ADCB')"!][!"../../CddAdcHwUnitAnalogRefABVoltageMode"!][!ELSE!][!"../../CddAdcHwUnitAnalogRefCDEVoltageMode"!][!ENDIF!],[!//
[!IF "num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*/CddAdcPpbConfig/*)) > 0"!]
            .startppbnum = (Cdd_Adc_PpbType)([!"num:i($PpbCount)"!]U),
            .ppbcount = (Cdd_Adc_PpbType)([!"num:i(count(CddAdcPpbConfig/*))"!]U),[!//
[!ENDIF!]
            .intpulsemode = (Cdd_Adc_EocPulseType)[!"CddAdcInterruptPulseMode"!],
            .intoffset = (uint16)[!"CddAdcInterruptCycleoffset"!]U,
#if(STD_ON == CDD_ADC_OPEN_SHORT_DETECTION)    
            .osdetectmode = ((Cdd_Adc_OsDetectModeType)[!"CddAdcOpenShortDetectMode"!]),
#endif
#if(STD_ON == CDD_ADC_EXTCHSEL_CAPABILITY)     
            .extchnsel = (boolean)([!"num:i(node:when((CddAdcHwExternalMuxSelect = 'false'),0,1))"!]U),       
            .extmuxpreselect = (boolean)([!"num:i(node:when(node:exists(CddAdcHwExternalMuxPreselectEnable),node:when((CddAdcHwExternalMuxPreselectEnable='false'),0,1),0))"!]U),
#endif
            .startgroupnum = (Cdd_Adc_GroupType)([!"num:i($HwGroupCount)"!]U),
            .lastgroupnum = (Cdd_Adc_GroupType)([!"num:i($HwGroupCount + num:i(count(CddAdcGroup/*))-1)"!]U),[!//
            [!VAR "AdcNum"!][!CALL "GetAdcNum", "HwUnit" = "CddAdcHwInstance"!][!ENDVAR!]
            .base_addr = (uint32)( ADCA_BASE + CDD_ADC_BASEADDR_STEP*([!"num:i($AdcNum)"!]U)),
            .result_baseaddr = (uint32)( ADCARESULT_BASE + CDD_ADC_RESULTBASEADDR_STEP*([!"num:i($AdcNum)"!]U))
        }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!//
        [!NOCODE!][!VAR "PpbCount" = "num:i($PpbCount + num:i(count(CddAdcPpbConfig/*)))"!][!//
        [!VAR "HwGroupCount" = "num:i($HwGroupCount + num:i(count(CddAdcGroup/*)))"!][!ENDNOCODE!][!ENDLOOP!]
    },    
    .groupcfg  =
    {[!//
        [!VAR "channelnum"="num:i(0)"!][!LOOP "CddAdcHwUnit/*"!][!LOOP "CddAdcGroup/*"!]
        [[!"num:i($GroupCount)"!]] =
        {
            /* HwunitId: [!"node:value(../../CddAdcHwInstance)"!] */
            .hwunit_index = (uint8)([!"num:i(num:i(node:pos(../../.)))"!]U),
            .grp_int = (Cdd_Adc_IntNumType)[!"CddAdcInterruptSelect"!],
            .continuetoint = (boolean)([!"num:i(node:when((CddAdcContinueToInterruptMode = 'false'),0,1))"!]U),
            .intsocsel = (Cdd_Adc_IntSocTriggerType)[!"CddAdcInterruptSocSelect"!],
#if(STD_ON == CDD_ADC_GRP_NOTIF_CAPABILITY_API)
            .groupend_notification = (Cdd_Adc_GroupEndNotifyType)[!IF "node:exists(CddAdcGroupNotification)"!][!"CddAdcGroupNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
#endif
            .stream_numsamples = (Cdd_Adc_StreamNumSampleType)([!"CddAdcGroupStreamingNumSamples"!]U),
            .trigger_src = (Cdd_Adc_TriggerType)([!"CddAdcGroupTrigSrc"!]),
            .conversion_mode = (Cdd_Adc_GroupConvModeType)[!IF "CddAdcGroupConversionMode = 'CDD_ADC_CONV_MODE_CONTINUOUS'"!]CDD_ADC_CONV_MODE_CONTINUOUS[!ELSE!]CDD_ADC_CONV_MODE_ONESHOT[!ENDIF!],
            .trigsrc_type = (Cdd_Adc_TriggerSrcType)[!IF "CddAdcGroupTrigSrcType = 'CDD_ADC_TRIGG_SRC_HW'"!]CDD_ADC_TRIGG_SRC_HW[!ELSE!]CDD_ADC_TRIGG_SRC_SW[!ENDIF!],
            .access_mode = (Cdd_Adc_GroupAccessModeType)[!IF "CddAdcGroupAccessMode = 'CDD_ADC_ACCESS_MODE_SINGLE'"!]CDD_ADC_ACCESS_MODE_SINGLE[!ELSE!]CDD_ADC_ACCESS_MODE_STREAMING[!ENDIF!],
            .streambuffermode = (Cdd_Adc_StreamBufferModeType)[!IF "CddAdcGroupStreamingBufferMode = 'CDD_ADC_STREAM_BUFFER_LINEAR'"!]CDD_ADC_STREAM_BUFFER_LINEAR[!ELSE!]CDD_ADC_STREAM_BUFFER_CIRCULAR[!ENDIF!],
            .startchannelnum = (uint8)([!"num:i($channelnum)"!]U),
            .channelcount = (uint8)([!"num:i(count(CddAdcChannel/*))"!]U),
            .soc_mask =  (uint32)([!"num:i(CddAdcGroupSocMask)"!]U),
            .lastsocnum = (uint8)([!"num:i(num:max(CddAdcChannel/*/CddAdcSocNumber))"!]U)
        }[!VAR "channelnum"="$channelnum+num:i(count(CddAdcChannel/*))"!][!VAR "GroupCount" = "$GroupCount+1"!][!IF "$GroupCount < num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*/CddAdcGroup/*))"!],[!CR!][!ELSE!][!ENDIF!][!//
        [!ENDLOOP!][!ENDLOOP!]
    },[!//
[!IF "(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcGeneral/CddAdcEnableGlobalSoftwareTrigger = 'true')"!]
    .glbtrigcfg =
    {[!//
        [!LOOP "CddAdcGlobalSwTrigger/*"!][!//
        [!NOCODE!]
            [!VAR "AdcMask" = "num:i(0)"!]
            [!VAR "GlbSwTriggerGroupMask" = "num:i(0)"!]
            [!VAR "Num" = "num:i(0)"!]
            [!VAR "HwIndex" = "num:i(0)"!]
            [!VAR "GlbTrigSocMask" = "num:i(0)"!]
            [!VAR "GlbTrigHwSocMask0" = "num:i(0)"!]
            [!VAR "GlbTrigHw0" = "num:i(0)"!]
            [!VAR "GlbTrigHwSocMask1" = "num:i(0)"!]
            [!VAR "GlbTrigHw1" = "num:i(0)"!]
            [!VAR "GlbTrigHwSocMask2" = "num:i(0)"!]
            [!VAR "GlbTrigHw2" = "num:i(0)"!]
            [!VAR "GlbTrigHwSocMask3" = "num:i(0)"!]
            [!VAR "GlbTrigHw3" = "num:i(0)"!]
            [!VAR "GlbTrigHwSocMask4" = "num:i(0)"!]
            [!VAR "GlbTrigHw4" = "num:i(0)"!]
        [!ENDNOCODE!]
        [[!"@index"!]] =
        {[!//
            [!NOCODE!]
                [!LOOP "CddAdcHwGroup/*"!]
                    [!VAR "Num"!][!CALL "GetAdcNum", "HwUnit" = "CddAdcHwUnit"!][!ENDVAR!]
                    [!VAR "AdcMask" = "bit:or(num:i(bit:bitset(0,$Num)),$AdcMask)"!]
                    [!VAR "HwIndex" = "node:value(concat(node:path(node:ref(CddAdcHwGroupRef)),'/../../CddAdcHwUnitId'))"!]
                    [!VAR "GlbTrigSocMask" = "num:i(bit:or(node:value(CddAdcSocMask),$GlbTrigSocMask))"!]
                    [!VAR "HwGroupCountNum" ="num:i(0)"!]
                    [!IF "$HwIndex = 0"!]
                        [!VAR "GlbTrigHw0" = "num:i($GlbTrigHw0+1)"!]
                        [!VAR "GlbTrigHwSocMask0" = "num:i(bit:or($GlbTrigHwSocMask0,node:value(CddAdcSocMask)))"!]
                        [!VAR "HwGroupCountNum" ="num:i($HwGroup0Cnt)"!]
                    [!ELSEIF "$HwIndex = 1"!]
                        [!VAR "GlbTrigHw1" = "num:i($GlbTrigHw1+1)"!]
                        [!VAR "GlbTrigHwSocMask1" = "num:i(bit:or($GlbTrigHwSocMask1,node:value(CddAdcSocMask)))"!]
                        [!VAR "HwGroupCountNum" ="num:i($HwGroup1Cnt)"!]
                    [!ELSEIF "$HwIndex = 2"!]
                        [!VAR "GlbTrigHw2" = "num:i($GlbTrigHw2+1)"!]
                        [!VAR "GlbTrigHwSocMask2" = "num:i(bit:or($GlbTrigHwSocMask2,node:value(CddAdcSocMask)))"!]
                        [!VAR "HwGroupCountNum" ="num:i($HwGroup2Cnt)"!]
                    [!ELSEIF "$HwIndex = 3"!]
                        [!VAR "GlbTrigHw3" = "num:i($GlbTrigHw3+1)"!]
                        [!VAR "GlbTrigHwSocMask3" = "num:i(bit:or($GlbTrigHwSocMask3,node:value(CddAdcSocMask)))"!]
                        [!VAR "HwGroupCountNum" ="num:i($HwGroup3Cnt)"!]
                    [!ELSEIF "$HwIndex = 4"!]
                        [!VAR "GlbTrigHw4" = "num:i($GlbTrigHw4+1)"!]
                        [!VAR "GlbTrigHwSocMask4" = "num:i(bit:or($GlbTrigHwSocMask4,node:value(CddAdcSocMask)))"!]
                        [!VAR "HwGroupCountNum" ="num:i($HwGroup4Cnt)"!]
                    [!ENDIF!]
                    [!VAR "GlbSwTriggerGroupMask" = "bit:or(bit:bitset(0,($HwGroupCountNum+node:pos(node:path(node:ref(CddAdcHwGroupRef))))),$GlbSwTriggerGroupMask)"!]
                [!ENDLOOP!]
                        [!IF "($GlbTrigHw0 != 0) and ($GlbTrigHwSocMask0 != $GlbTrigSocMask)"!]
                            [!ERROR "SocMask should match for all the hardware units combining all the configured groups of a hardware unit"!]
                        [!ELSEIF "($GlbTrigHw1 != 0) and ($GlbTrigHwSocMask1 != $GlbTrigSocMask)"!]
                            [!ERROR "SocMask should match for all the hardware units combining all the configured groups of a hardware unit"!]
                        [!ELSEIF "($GlbTrigHw2 != 0) and ($GlbTrigHwSocMask2 != $GlbTrigSocMask)"!]
                            [!ERROR "SocMask should match for all the hardware units combining all the configured groups of a hardware unit"!]
                        [!ELSEIF "($GlbTrigHw3 != 0) and ($GlbTrigHwSocMask3 != $GlbTrigSocMask)"!]
                            [!ERROR "SocMask should match for all the hardware units combining all the configured groups of a hardware unit"!]
                        [!ELSEIF "($GlbTrigHw4 != 0) and ($GlbTrigHwSocMask4 != $GlbTrigSocMask)"!]
                            [!ERROR "SocMask should match for all the hardware units combining all the configured groups of a hardware unit"!]
                        [!ENDIF!]
            [!ENDNOCODE!]
            .hwunit_mask = (uint8)([!"num:i($AdcMask)"!]U),
            .soc_mask = (uint32)([!"num:i($GlbTrigSocMask)"!]U),
            .group_mask = (uint32)([!"num:i($GlbSwTriggerGroupMask)"!])
        }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    },[!//
[!ENDIF!][!//
[!IF "(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcGeneral/CddAdcPpbEnable = 'true')"!]
    .ppbcfg =
    {[!//
        [!NOCODE!]
        [!VAR "PpbEvtNotification"="num:i(0)"!]
        [!LOOP "as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*/CddAdcPpbConfig/*"!]
            [!IF "node:exists(.)"!]
                [!VAR "PpbEvtNotification"="num:i($PpbEvtNotification+1)"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!VAR "PpbCount" = "0"!][!ENDNOCODE!][!//
        [!LOOP "CddAdcHwUnit/*"!][!LOOP "CddAdcPpbConfig/*"!]
        [[!"num:i($PpbCount)"!]] =  
        {
            /* HwunitId: [!"node:value(../../CddAdcHwInstance)"!] */
            .ppb_id = (Cdd_Adc_PpbIdType)([!"CddAdcPpbId"!]U),
            .soc_num = (uint8)([!"num:i(node:value(concat(node:path(node:ref(CddAdcPpbChannel)),'/CddAdcSocNumber')))"!]U),
            .hwunitindex = (uint8)([!"num:i(node:pos(../../.))"!]U),
            .ppb_caloffset = (uint32)([!"CddAdcPpbCalibrationOffset"!]U),
            .ppb_refoffset = (uint32)([!"CddAdcPpbReferenceOffset"!]U),
            .ppbresconfig = (uint16)((0x0000U) | (([!"num:i(node:when((CddAdcPpbDeltaEnable = 'false'),0,1))"!]U)<<8U) | (([!"num:i(node:when((CddAdcPpbEnableTwosComplement = 'false'),0,1))"!]U)<<7U) | (([!"num:i(node:when((CddAdcPpbAbsoluteEnable = 'false'),0,1))"!]U)<<6U) | (([!"num:i(node:when((CddAdcPpbCyclebyCycleEnable = 'false'),0,1))"!]U)<<5U)),
            .triplimithi = (sint32)[!"CddAdcPpbTripHighLimit"!],
            .triplimitlow = (sint32)[!"CddAdcPpbTripLowLimit"!],
            .tripevtsel = (uint8)((0x00U) | ([!"num:i(node:when((CddAdcPpbTripHighEventEnable='false'),0,1))"!]U) | ([!"num:i(node:when((CddAdcPpbTripLowEventEnable='false'),0,1))"!]U<<1U) | ([!"num:i(node:when((CddAdcPpbZeroCrossingEventEnable='false'),0,1))"!]U<<2U)),
            .tripevtintsel = (uint8)((0x00U) | ([!"num:i(node:when((CddAdcPpbTripHighInterruptEnable = 'false'),0,1))"!]U) | (([!"num:i(node:when((CddAdcPpbTripLowInterruptEnable = 'false'),0,1))"!]U)<<1U) | (([!"num:i(node:when((CddAdcPpbZeroCrossingInterruptEnable = 'false'),0,1))"!]U)<<2U)),
        #if(STD_ON == CDD_ADC_PPB_NOTIF_CAPABILITY_API)
            .ppbevtint_notification = (Cdd_Adc_PpbNotifyType)[!IF "not(node:empty(CddAdcPpbEventInterruptNotification))"!][!"CddAdcPpbEventInterruptNotification"!][!ELSE!]NULL_PTR[!ENDIF!],
        #endif
            .ppbcountlimit = (uint16)([!"CddAdcPpbAccumulationCountLimit"!]U),
            .ppbcfg2 = (uint16)((0x0000U) | (((uint8)[!"CddAdcPpbCompareSource"!])<<14U) | ([!"CddAdcPpbRightShift"!]U)),
            .tripfilterenable = (boolean)[!"num:i(node:when((CddAdcPpbTripFilterEnable = 'true'),1,0))"!]U,
            .tripfilctl = (uint16)[!IF "CddAdcPpbTripFilterEnable = 'true'"!]((0x0000U) | (([!"num:i(CddAdcTripFilterConfig/CddAdcTripFilterTreshold)"!]U)<<9U) | (([!"num:i(CddAdcTripFilterConfig/CddAdcTripFilterSampleWindow)"!]U)<<3U) | (([!"num:i(node:when((CddAdcTripFilterConfig/CddAdcTripFilterLowEnable = 'false'),0,1))"!]U)<<1U) | ([!"num:i(node:when((CddAdcTripFilterConfig/CddAdcTripFilterHighEnable = 'false'),0,1))"!]U))[!ELSE!](0x0000U)[!ENDIF!],     
            .tripfilclk = (uint16)[!IF "CddAdcPpbTripFilterEnable = 'true'"!]((0x0000U) | ([!"num:i(CddAdcTripFilterConfig/CddAdcTripFilterClk)"!]U))[!ELSE!](0x0000U)[!ENDIF!]
        }[!VAR "PpbCount" = "$PpbCount+1"!][!IF "$PpbCount < num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*/CddAdcPpbConfig/*))"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!][!ENDLOOP!]
    },[!//
[!ENDIF!]
    .channelcfg =
    {[!//
        [!VAR "channelnum"="num:i(0)"!][!LOOP "CddAdcHwUnit/*/CddAdcGroup/*/CddAdcChannel/*"!]
        [[!"num:i($channelnum)"!]] =
        {
            /* HwunitId:[!"node:value(../../../../CddAdcHwInstance)"!] Group:[!"num:i(node:pos(../../.))"!] */
            .channel_id = (uint8)([!"node:value(CddAdcChannelId)"!]U),
            .sample_window = (uint16)([!"CddAdcChannelSampleWindow"!]U),
#if (CDD_ADC_EXTCHSEL_CAPABILITY == STD_ON)
            .extchannelnum = (uint8)([!"CddAdcSocExternalChannelSelect"!]U),
#endif   
            .soc_num =  (uint8)([!"CddAdcSocNumber"!]U)
        }[!VAR "channelnum"="num:i($channelnum+1)"!][!IF "$channelnum < num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcHwUnit/*/CddAdcGroup/*/CddAdcChannel/*))"!],[!CR!][!ELSE!][!ENDIF!][!//
        [!ENDLOOP!]
    },[!//
[!IF "(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcGeneral/CddAdcSafetyCheckerEnable = 'true')"!]      
    .checkercfg =
    {
        .checkerunitcfg = 
        {[!//
            [!LOOP "CddAdcResultCheckerUnit/*"!]
            [[!"@index"!]] =
            {
                .checker_id = (Cdd_Adc_CheckerType)([!"CddAdcCheckerId"!]U),
                .tolerance = (uint32)([!"CddAdcCheckerTolerance"!]U),
                .base_addr = (uint32)(ADCSAFETYCHECK1_BASE + CDD_ADC_CHECKER_BASEADDR_STEP*([!"num:i(CddAdcCheckerId)"!]U)),
                .selresult = 
                {
                    [0] =
                    {
                        .hwunit_index =  (uint8)([!IF "(node:value(CddAdcSelResConfig1/CddAdcCheckerResultType) = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPB') or (node:value(CddAdcSelResConfig1/CddAdcCheckerResultType) = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPBSUM')"!][!"num:i(node:pos(concat(node:path(node:ref(CddAdcSelResConfig1/CddAdcPpbReference)),'/../../.')))"!][!ELSE!][!"node:pos(concat(node:path(node:ref(CddAdcSelResConfig1/CddAdcChannelReference)),'/../../../../.'))"!][!ENDIF!]U),
                        .res_num = (uint8)([!IF "(CddAdcSelResConfig1/CddAdcCheckerResultType = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPB')"!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig1/CddAdcPpbReference)),'/CddAdcPpbId'))+32)"!][!ELSEIF "(CddAdcSelResConfig1/CddAdcCheckerResultType = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPBSUM')"!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig1/CddAdcPpbReference)),'/CddAdcPpbId'))+36)"!][!ELSE!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig1/CddAdcChannelReference)),'/CddAdcSocNumber')))"!][!ENDIF!]U),
                        .soc_num = (uint8)([!IF "(CddAdcSelResConfig1/CddAdcCheckerResultType = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPB') or (CddAdcSelResConfig1/CddAdcCheckerResultType = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPBSUM')"!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig1/CddAdcPpbReference)),'/CddAdcPpbSocNumber')))"!][!ELSE!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig1/CddAdcChannelReference)),'/CddAdcSocNumber')))"!][!ENDIF!]U),
                        .res_type = (Cdd_Adc_CheckerInputType)[!"CddAdcSelResConfig1/CddAdcCheckerResultType"!]
                    },
                    [1] = 
                    {
                        .hwunit_index =  (uint8)([!IF "(node:value(CddAdcSelResConfig2/CddAdcCheckerResultType) = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPB') or (node:value(CddAdcSelResConfig2/CddAdcCheckerResultType) = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPBSUM')"!][!"num:i(node:pos(concat(node:path(node:ref(CddAdcSelResConfig2/CddAdcPpbReference)),'/../../.')))"!][!ELSE!][!"node:pos(concat(node:path(node:ref(CddAdcSelResConfig2/CddAdcChannelReference)),'/../../../../.'))"!][!ENDIF!]U),
                        .res_num = (uint8)([!IF "(CddAdcSelResConfig2/CddAdcCheckerResultType = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPB')"!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig2/CddAdcPpbReference)),'/CddAdcPpbId'))+32)"!][!ELSEIF "(CddAdcSelResConfig2/CddAdcCheckerResultType = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPBSUM')"!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig2/CddAdcPpbReference)),'/CddAdcPpbId'))+36)"!][!ELSE!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig2/CddAdcChannelReference)),'/CddAdcSocNumber')))"!][!ENDIF!]U),
                        .soc_num = (uint8)([!IF "(CddAdcSelResConfig2/CddAdcCheckerResultType = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPB') or (CddAdcSelResConfig2/CddAdcCheckerResultType = 'CDD_ADC_SAFETY_CHECKER_INPUT_PPBSUM')"!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig2/CddAdcPpbReference)),'/CddAdcPpbSocNumber')))"!][!ELSE!][!"num:i(node:value(concat(node:path(node:ref(CddAdcSelResConfig2/CddAdcChannelReference)),'/CddAdcSocNumber')))"!][!ENDIF!]U),
                        .res_type = (Cdd_Adc_CheckerInputType)[!"CddAdcSelResConfig2/CddAdcCheckerResultType"!]
                    }
                }
            }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]   
        },
    [!IF "num:i(count(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcCheckerIntEvtConfig/*)) > 0"!]
        .checkerintevtcfg = 
        {[!//
            [!LOOP "CddAdcCheckerIntEvtConfig/*"!]
            [[!"@index"!]] =
            {                
                [!NOCODE!]
                [!VAR "Evt1Res1OvfMask" = "num:i(0)"!][!VAR "Evt1Res2OvfMask" = "num:i(0)"!][!VAR "Evt1OotMask" = "num:i(0)"!]
                [!VAR "Evt2Res1OvfMask" = "0"!][!VAR "Evt2Res2OvfMask" = "0"!][!VAR "Evt2OotMask" = "0"!]
                [!VAR "Evt3Res1OvfMask" = "0"!][!VAR "Evt3Res2OvfMask" = "0"!][!VAR "Evt3OotMask" = "0"!]
                [!VAR "Evt4Res1OvfMask" = "0"!][!VAR "Evt4Res2OvfMask" = "0"!][!VAR "Evt4OotMask" = "0"!]
                [!VAR "EvtIntRes1OvfMask" = "0"!][!VAR "EvtIntRes2OvfMask" = "0"!][!VAR "EvtIntOotMask" = "0"!]
                [!LOOP "CddAdcCheckerIntEvtConfiguration/*"!]
                    [!VAR "CheckerId" = "num:i(node:value(concat(node:path(node:ref(CddAdcSafetyCheckerInstance)),'/CddAdcCheckerId')))"!]
                    [!VAR "Evt1Res1OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt1Source/CddAdcCheckerRes1Ovf) = 'true',1,0)),$CheckerId),$Evt1Res1OvfMask)"!]
                    [!VAR "Evt1Res2OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt1Source/CddAdcCheckerRes2Ovf) = 'true',1,0)),$CheckerId),$Evt1Res2OvfMask)"!]
                    [!VAR "Evt1OotMask"     = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt1Source/CddAdcCheckerOot) = 'true',1,0)),$CheckerId),$Evt1OotMask)"!]
                    
                    [!VAR "Evt2Res1OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt2Source/CddAdcCheckerRes1Ovf) = 'true',1,0)),$CheckerId),$Evt2Res1OvfMask)"!]
                    [!VAR "Evt2Res2OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt2Source/CddAdcCheckerRes2Ovf) = 'true',1,0)),$CheckerId),$Evt2Res2OvfMask)"!]
                    [!VAR "Evt2OotMask"     = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt2Source/CddAdcCheckerOot) = 'true',1,0)),$CheckerId),$Evt2OotMask)"!]
                    
                    [!VAR "Evt3Res1OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt3Source/CddAdcCheckerRes1Ovf) = 'true',1,0)),$CheckerId),$Evt3Res1OvfMask)"!]
                    [!VAR "Evt3Res2OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt3Source/CddAdcCheckerRes2Ovf) = 'true',1,0)),$CheckerId),$Evt3Res2OvfMask)"!]
                    [!VAR "Evt3OotMask"     = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt3Source/CddAdcCheckerOot) = 'true',1,0)),$CheckerId),$Evt3OotMask)"!]
                    
                    [!VAR "Evt4Res1OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt4Source/CddAdcCheckerRes1Ovf) = 'true',1,0)),$CheckerId),$Evt4Res1OvfMask)"!]
                    [!VAR "Evt4Res2OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt4Source/CddAdcCheckerRes2Ovf) = 'true',1,0)),$CheckerId),$Evt4Res2OvfMask)"!]
                    [!VAR "Evt4OotMask"     = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerEvt4Source/CddAdcCheckerOot) = 'true',1,0)),$CheckerId),$Evt4OotMask)"!]
                    
                    [!VAR "EvtIntRes1OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerIntSource/CddAdcCheckerRes1Ovf) = 'true',1,0)),$CheckerId),$EvtIntRes1OvfMask)"!]
                    [!VAR "EvtIntRes2OvfMask" = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerIntSource/CddAdcCheckerRes2Ovf) = 'true',1,0)),$CheckerId),$EvtIntRes2OvfMask)"!]
                    [!VAR "EvtIntOotMask"     = "bit:or(bit:shl(num:i(node:when(node:value(CddAdcCheckerIntSource/CddAdcCheckerOot) = 'true',1,0)),$CheckerId),$EvtIntOotMask)"!]
                [!ENDLOOP!]
                [!ENDNOCODE!]
                .base_addr  =  (uint32)(ADCSAFETYCHECKINTEVT1_BASE + CDD_ADC_CHECKERINTEVTBASE_STEP*([!"num:i(CddAdcIntEvtId)"!]U)),
                .intevt_id = (uint8)([!"CddAdcIntEvtId"!]U),
                .checkevtint =
                {
                    .res1ovf = (uint16)([!"num:i($EvtIntRes1OvfMask)"!]U),
                    .res2ovf = (uint16)([!"num:i($EvtIntRes2OvfMask)"!]U),
                    .ootflg  = (uint16)([!"num:i($EvtIntOotMask)"!]U)  
                },
                .checkevt =
                {
                    [!FOR "x" = "0" TO "3"!]
                    [[!"$x"!]] =
                    {
                        .res1ovf = (uint16)([!IF "num:i($x) = '0'"!][!"num:i($Evt1Res1OvfMask)"!][!ELSEIF "num:i($x) = '1'"!][!"num:i($Evt2Res1OvfMask)"!][!ELSEIF "num:i($x) = '2'"!][!"num:i($Evt3Res1OvfMask)"!][!ELSEIF "num:i($x) = '3'"!][!"num:i($Evt4Res1OvfMask)"!][!ENDIF!]U),
                        .res2ovf = (uint16)([!IF "num:i($x) = '0'"!][!"num:i($Evt1Res2OvfMask)"!][!ELSEIF "num:i($x) = '1'"!][!"num:i($Evt2Res2OvfMask)"!][!ELSEIF "num:i($x) = '2'"!][!"num:i($Evt3Res2OvfMask)"!][!ELSEIF "num:i($x) = '3'"!][!"num:i($Evt4Res2OvfMask)"!][!ENDIF!]U),
                        .ootflg  = (uint16)([!IF "num:i($x) = '0'"!][!"num:i($Evt1OotMask)"!][!ELSEIF "num:i($x) = '1'"!][!"num:i($Evt2OotMask)"!][!ELSEIF "num:i($x) = '2'"!][!"num:i($Evt3OotMask)"!][!ELSEIF "num:i($x) = '3'"!][!"num:i($Evt4OotMask)"!][!ENDIF!]U)
                    }[!IF "$x < '3'"!],[!CR!][!ELSE!][!ENDIF!]
                    [!ENDFOR!]  
                }
            }[!IF "not(node:islast())"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!] 
        }
    [!ENDIF!]
    },
[!ENDIF!][!//
[!IF "($TrigRepEnable > 0)"!]
    .repunitcfg =
    {[!//
        [!LOOP "CddAdcHwUnit/*/CddAdcTriggerRepeater/*"!]
        [[!"num:i($RepCount)"!]] =
        {
            .hwunit_index = (uint8)([!"num:i(num:i(node:pos(../../.)))"!]U),
            .repeater_instance = (Cdd_Adc_RepeaterType)[!IF "CddAdcRepeaterInstance ='0'"!]CDD_ADC_REPINST1[!ELSE!]CDD_ADC_REPINST2[!ENDIF!],
            .repeater_mode = (Cdd_Adc_RepeaterModeType)[!IF "CddAdcRepeaterMode='OVERSAMPLING_MODE'"!]CDD_ADC_REPMODE_OVERSAMPLING[!ELSE!]CDD_ADC_REPMODE_UNDERSAMPLING[!ENDIF!],
            .trigger_source = (Cdd_Adc_TriggerType)[!"CddAdcRepeaterTriggerSrc"!],
            .repeater_count =  (uint8)([!"CddAdcTriggerCount"!]U),
            .repeater_phase =  (uint16)([!"CddAdcTriggerPhaseDelay"!]U),
            .repeater_spread =  (uint16)([!IF "node:exists(CddAdcTriggerSpreadDelay)"!][!"CddAdcTriggerSpreadDelay"!][!ELSE!]0[!ENDIF!]U)
        }[!VAR "RepCount" = "num:i($RepCount+1)"!][!IF "($RepCount != $TrigRepEnable)"!],[!CR!][!ELSE!][!ENDIF!][!ENDLOOP!]
    },[!//
[!ENDIF!]
    .test_input = (Cdd_Adc_InternalTestNodeType)[!"node:value(as:modconf('Cdd_Adc/Cdd')[1]/CddAdcConfigSet/CddAdcInternalTestInput)"!],
};[!//
[!ENDLOOP!]


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
