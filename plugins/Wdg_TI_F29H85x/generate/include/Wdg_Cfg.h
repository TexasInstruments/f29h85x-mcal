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
 *  File:       Wdg_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data                                                     
 *********************************************************************************************************************/
#ifndef WDG_CFG_H
#define WDG_CFG_H

/**
 * \addtogroup WDG
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif
 
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 * \brief Wdg Driver Configuration SW Version Info.
 *********************************************************************************************************************/
#define WDG_CFG_MAJOR_VERSION               ([!"substring-before($moduleSoftwareVer,'.')"!]U)
#define WDG_CFG_MINOR_VERSION               ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
#define WDG_CFG_PATCH_VERSION               ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)


/*********************************************************************************************************************
 * \brief WDG Build Variant.
 * Build variants.(i.e Precompile, postbuild or linktime)
 *********************************************************************************************************************/
[!SELECT "as:modconf('Wdg')[as:path(node:dtos(.))='/TI_F29H85x/Wdg']"!]
#define WDG_VARIANT_PRE_COMPILE       [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define WDG_VARIANT_POST_BUILD        [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define WDG_VARIANT_LINK_TIME         [!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantLinkTime'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT = 'VariantLinkTime'"!]
/*********************************************************************************************************************
 * \brief Pre Compile config macro name.
 *********************************************************************************************************************/
[!LOOP "WdgSettingsConfig"!]
#define WDG_INIT_CONFIG_PC		Wdg_Config
[!ENDLOOP!]
[!ENDIF!]

 /*
 * Design: MCAL-25217, MCAL-25219, MCAL-25246
 */
/*********************************************************************************************************************
 * \brief WDG configuration index
 *********************************************************************************************************************/
#define WDG_CFG_ID          (0x1U)
#define WDG_MAX_INSTANCES   (1U)


/* DEM Error Definitions */
/* DEM Error Codes */
/*********************************************************************************************************************
 * \brief Enable/Disable DEM.
 *********************************************************************************************************************/
#define WDG_DEM_ENABLE    [!IF "node:refexists(WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

 /*
 * Design: MCAL-25229, MCAL-25272, MCAL-25273
 */
[!IF "node:refexists(WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED)"!]
/** \brief WDG DEM Event Configuration: WDG Disable feature rejected error */
#define WDG_E_DISABLE_REJECTED  (DemConf_DemEventParameter_[!"node:name(node:ref(WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED))"!])
[!ENDIF!]

 /*
 * Design: MCAL-25226, MCAL-25272, MCAL-25274
 */
[!IF "node:refexists(WdgDemEventParameterRefs/WDG_E_MODE_FAILED)"!]
/** \brief WDG DEM Event Configuration: WDG Mode failed error */
#define WDG_E_MODE_FAILED  (DemConf_DemEventParameter_[!"node:name(node:ref(WdgDemEventParameterRefs/WDG_E_MODE_FAILED))"!])
[!ENDIF!]

/*********************************************************************************************************************
 * \brief Enable/Disable Development Error Detection.
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25276
 */
#define WDG_DEV_ERROR_DETECT       [!IF "WdgGeneral/WdgDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*********************************************************************************************************************
 * \brief Enable/Disable Wdg_GetVersionInfo().
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25283
 */
#define WDG_GET_VERSION_INFO_API   [!IF "WdgGeneral/WdgVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/*********************************************************************************************************************
 * \brief Watchdog Initial Timeout and Watchdog Maximum Timeout.
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25308, MCAL-25309
 */
#define WDG_INITIAL_TIMEOUT        (uint16) ([!"num:i(WdgGeneral/WdgInitialTimeout * 1000)"!])
#define WDG_MAX_TIMEOUT            (uint16) ([!"num:i(WdgGeneral/WdgMaxTimeout * 1000)"!])
[!VAR "Test1" = "WdgGeneral/WdgInitialTimeout"!][!VAR "Test2" = "WdgGeneral/WdgMaxTimeout"!][!IF "num:i($Test1 * 1000 ) > num:i($Test2 * 1000)"!][!ERROR "WdgInitialTimeout can't be greater than WdgMaxTimeout"!][!ENDIF!]

/*********************************************************************************************************************
 * \brief Watchdog Maximum Windowed Threshold value
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25310
 */
#define WDG_MAX_THRESHOLD_VALUE    (uint16) (0xFFU)

/*********************************************************************************************************************
 * \brief Watchdog Disable Allowed
 *********************************************************************************************************************/
 /*
 * Design: MCAL-25277
 */
#define WDG_DISABLE_ALLOWED        [!IF "WdgGeneral/WdgDisableAllowed = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

 /*
 * Design: MCAL-25245
 */
 /** \brief This is a Watchdog status type value */
typedef enum
{
    /** \brief Watchdog driver is uninitialized. State on power on before invoking Wdg_Init() */
    WDG_UNINIT = 0U,
    /** \brief Watchdog driver is in idle state. Default state when WDG timer regs are not being programmed */
    WDG_IDLE = 1U,
    /** \brief Watchdog driver is reprogramming the WD to trigger the watchdog */
    WDG_BUSY = 2U
} Wdg_StatusType;


 /*
 * Design: MCAL-25303
 */
 /** \brief Watchdog module Reaction if watchdog counter reaches the maximum value */
typedef enum
{
    /** \brief Watchdog can generate a reset signal */
    WDG_GENERATE_RESET = 0U,
    /** \brief Watchdog can generate an interrupt signal; reset signal is disabled */
    WDG_GENERATE_INTERRUPT = 1U
}Wdg_Reaction;


 /*
 * Design: MCAL-25304
 */
 /** \brief Wdg_PreDivider  determines the watchdog clock pre-divider, which is the first of the two dividers 
  *         between INTOSC1 and the watchdog counter clock (WDCLK)
  */
typedef enum
{
    /** \brief PREDIVCLK = INTOSC1 / 2 */
    WDG_PREDIV_2    = 0x800, 
    /** \brief PREDIVCLK = INTOSC1 / 4 */
    WDG_PREDIV_4    = 0x900, 
    /** \brief PREDIVCLK = INTOSC1 / 8 */
    WDG_PREDIV_8    = 0xA00,
    /** \brief PREDIVCLK = INTOSC1 / 16 */
    WDG_PREDIV_16   = 0xB00, 
    /** \brief PREDIVCLK = INTOSC1 / 32 */
    WDG_PREDIV_32   = 0xC00, 
    /** \brief PREDIVCLK = INTOSC1 / 64 */
    WDG_PREDIV_64   = 0xD00,
    /** \brief PREDIVCLK = INTOSC1 / 128 */
    WDG_PREDIV_128  = 0xE00, 
    /** \brief PREDIVCLK = INTOSC1 / 256 */
    WDG_PREDIV_256  = 0xF00, 
    /** \brief PREDIVCLK = INTOSC1 / 512 */
    WDG_PREDIV_512  = 0x000, 
    /** \brief PREDIVCLK = INTOSC1 / 1024 */
    WDG_PREDIV_1024 = 0x100,
    /** \brief PREDIVCLK = INTOSC1 / 2048 */
    WDG_PREDIV_2048 = 0x200,
    /** \brief PREDIVCLK = INTOSC1 / 4096 */
    WDG_PREDIV_4096 = 0x300
} Wdg_PreDivider;


 /*
 * Design: MCAL-25305
 */
 /** \brief Wdg_PreScaler determines the watchdog clock prescaler, which is the second of the two dividers 
  *         between INTOSC1 and the watchdog counter clock (WDCLK).
  */
typedef enum
{
    /** \brief WDCLK = PREDIVCLK / 1 */
    WDG_PRESCALE_1  = 1U,
    /** \brief WDCLK = PREDIVCLK / 2 */
    WDG_PRESCALE_2  = 2U, 
    /** \brief WDCLK = PREDIVCLK / 4 */
    WDG_PRESCALE_4  = 3U,
    /** \brief WDCLK = PREDIVCLK / 8 */ 
    WDG_PRESCALE_8  = 4U,
    /** \brief WDCLK = PREDIVCLK / 16 */ 
    WDG_PRESCALE_16 = 5U,
    /** \brief WDCLK = PREDIVCLK / 32 */
    WDG_PRESCALE_32 = 6U,
    /** \brief WDCLK = PREDIVCLK / 64 */
    WDG_PRESCALE_64 = 7U
} Wdg_PreScaler;


 /*
 * Design: MCAL-25302
 */
 /** \brief Mode Information Type */
typedef struct
{
    /** \brief Reaction type : Reset or Interrupt */
    Wdg_Reaction     Reaction;
    /** \brief It specifies lower limit of the watchdog counter reset  window */
    uint16           Threshold;
    /** \brief It specifies maximum timeout value */
    uint16          Timeout;
    /** \brief The first of the two dividers between INTOSC1 and the watchdog counter clock (WDCLK) */
    Wdg_PreDivider   PreDivider;
    /** \brief The second of the two dividers between INTOSC1 and the watchdog counter clock (WDCLK) */
    Wdg_PreScaler    PreScaler;
} Wdg_ModeInfoType;


/** \brief WDG config root structure */
typedef struct Wdg_ConfigType_s
{
    /** \brief Default wdg mode */
    WdgIf_ModeType   Wdg_DefaultMode;
    /** \brief Instance ID */  
    uint8            Wdg_InstanceId;
    /** \brief Initial timeout  */
    uint16           Wdg_InitialTimeOut;
    /** \brief Maximum timeout */
    uint16           Wdg_MaxTimeOut;
    /** \brief Fast mode configuration */
    Wdg_ModeInfoType Wdg_FastModeCfg;
    /** \brief Slow mode configuration */
    Wdg_ModeInfoType Wdg_SlowModeCfg;
} Wdg_ConfigType;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

[!LOOP "WdgSettingsConfig"!]
 /** \brief Wdg config pointer */
extern const struct Wdg_ConfigType_s  Wdg_Config;
[!ENDLOOP!]
[!ENDSELECT!]
/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/
 
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
 
#ifdef __cplusplus
}
#endif

/**
* @}
*/


#endif /* WDG_CFG_H */
/*********************************************************************************************************************
 *  End of File: Wdg_Cfg.h
 *********************************************************************************************************************/
