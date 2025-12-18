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
 *  File:       Port_Cfg.h
 *  Project:    C29x MCAL
 *  Module:     Port Driver
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data
 *                                                                   
 *********************************************************************************************************************/
/* ECUCs and Private Configuration JIRA IDs */
/*
 *Design: MCAL-22324,MCAL-22369,MCAL-22370,MCAL-22371,MCAL-22372,MCAL-22414,MCAL-29443
 */
#ifndef PORT_CFG_H
#define PORT_CFG_H
/**
 * \addtogroup PORT
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
/*****************************************************************************
 *
 * \brief Port Driver Configuration SW Version Info.
 *
 *****************************************************************************/
/** \brief Port configuration Major Version. */
#define PORT_CFG_MAJOR_VERSION           (3U)
/** \brief Port configuration Minor Version. */
#define PORT_CFG_MINOR_VERSION           (0U)
/** \brief Port configuration Patch Version. */
#define PORT_CFG_PATCH_VERSION           (0U)


/*****************************************************************************
 *
 * \brief PORT Build Variant.
 *  Build variants.(i.e Pre-compile,Post-build)
 *
 *****************************************************************************/
#define PORT_CFG_PRE_COMPILE_VARIANT         (STD_OFF)

/*****************************************************************************
 *
 * \brief Enable/Disable development error detection.
 *
 *****************************************************************************/
#define PORT_CFG_DEV_ERROR_DETECT            (STD_OFF) 

/*****************************************************************************
 *
 * \brief Enable/Disable Port_SetPinDirection().
 *
 *****************************************************************************/
#define PORT_CFG_SET_PIN_DIRECTION_API       (STD_ON) 

/*****************************************************************************
 *
 * \brief Enable/Disable Port_SetPinMode().
 *
 *****************************************************************************/
#define PORT_CFG_SET_PIN_MODE_API            (STD_ON) 

/*****************************************************************************
 *
 * \brief Enable/Disable Port_GetVersionInfo().
 *
 *****************************************************************************/
#define PORT_CFG_GET_VERSION_INFO_API        (STD_OFF) 

/*****************************************************************************
 *
 * \brief Lock All Pins Configuration.
 *
 *****************************************************************************/
#define PORT_CONFIGURATION_LOCK_CRITICAL_REGISTERS        (STD_ON) 


/*****************************************************************************
 *
 * \brief Symbolic names for the individual port pins - INDEX.
 *
 *****************************************************************************/

#define PortConf_PortPin_PortPin_0      0U			/*~ASR~*/

#define PortConf_PortPin_PortPin_1      1U			/*~ASR~*/

#define PortConf_PortPin_PortPin_2      2U			/*~ASR~*/

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/** \brief Port Driver Maximum number of modes per pin
 *
 *  Maximum number of runtime changeable port pin modes per pin
 *  This value is calculated based on actual configuration and is
 *  not the maximum number of modes supported by SoC (15)
 */
#define PORT_MAX_MUXMODE (1U)

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/** \brief Enum of Port Pin Pad, Up/Down Type selection. */
/* 
*Design: MCAL-22391   
*/ 
typedef enum
{
    /** \brief Standard pad configuration with pull up disable */
    PORT_PIN_TYPE_STD = 1U,
    /** \brief Enable pull up for the pin */
    PORT_PIN_TYPE_PULLUP = 2U,
    /** \brief Standard pad configuration with pull up enable */
    PORT_PIN_TYPE_STD_PULLUP = 3U,
    /** \brief Open Drain pad configuration with pull up disable */
    PORT_PIN_TYPE_OPEN_DRAIN = 4U,
    /** \brief Open Drain pad configuration with pull up enable */
    PORT_PIN_TYPE_OPEN_DRAIN_PULLUP = 6U,
    /** \brief No pad configuration */
    PORT_PIN_TYPE_NA = 255U
} Port_PinPadConfigType;

/** \brief Values that can be passed to set qualification parameter to initialize MCU module. */
/* 
 *Design: MCAL-22392   
 */ 
typedef enum
{
    /** \brief Synchronization to SYSCLKOUT. */
    PORT_QUAL_SYNC,
    /** \brief Qualified with 3 samples. */
    PORT_QUAL_3SAMPLE,
    /** \brief Qualified with 6 samples. */
    PORT_QUAL_6SAMPLE,
    /** \brief No synchronization. */
    PORT_QUAL_ASYNC,
    /** \brief Invalid synchronization. */
    PORT_QUAL_NA
} Port_PinQualificationMode;

/** \brief Values that can be passed to select master core for MCU module.*/
/* 
 *Design: MCAL-22393   
 */
typedef enum
{
    /** \brief CPU1 selected as master core. */
    PORT_CORE_CPU1,
    /** \brief CPU2 selected as master core. */
    PORT_CORE_CPU2,
    /** \brief CPU3 selected as master core. */
    PORT_CORE_CPU3,
} Port_PinCoreSelect;

/** \brief Values that can be passed to set the mode in which Pin should operate.*/
/* 
 *Design: MCAL-22394   
 */
typedef enum
{
    /** \brief Pin is in digital mode. */
    PORT_ANALOG_DISABLED,
    /** \brief Pin is in analog mode. */
    PORT_ANALOG_ENABLED
} Port_AnalogModeType;

/** \brief Type for Pin Config Flag.
 * Pin config flags
 * Bit 0 - Is Pin configurable?
 * Bit 1 - Does Pin support Analog Mode?
 * Bit 2 - Does Pin operate in AGPIO mode? 
 * Bit 3 - Does Pin operate in AIO mode?
 * Bit 4 - Does Pin operate in GPIO mode? 
 *
 *****************************************************************************/
/* 
 *Design: MCAL-22398   
 */
typedef uint8 Port_PinConfigFlagType;  

/** \brief Controller Specific structure */
/* 
 *Design:   MCAL-22402   
 */
typedef struct
{    
    /** \brief Analog Mode of Pin */
    Port_AnalogModeType Port_AnalogMode;

    /** \brief Mux configuration of pin to be used in Port_Init() */
    uint32 Port_InitialMuxMode;

    /** \brief Type of Push/Pull or Open Drain selection */
    Port_PinPadConfigType Port_PinPadConfig;

    /** \brief Pin Mode for different sync modes. */
    Port_PinQualificationMode Port_PinQualification;

    /** \brief Qualification Period  */
    uint32 Port_PinQualificationPeriod;

    /** \brief Select master core */
    Port_PinCoreSelect Port_CoreSelect;

    /** \brief Pin config flags */
    Port_PinConfigFlagType Port_PinConfigFlags;
    
    /** \brief Enable pin as LPM */
    boolean Port_EnableWakeupPinLPM;

} Port_ControllerSpecificType;


/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/
/*****************************************************************************
 *
 * \brief Post build Port config pointer.
 *
 *****************************************************************************/

extern const struct Port_ConfigType_s Port_Config;


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
#endif /* PORT_CFG_H */
/*********************************************************************************************************************
 *  End of File: Port_Cfg.h
 *********************************************************************************************************************/
