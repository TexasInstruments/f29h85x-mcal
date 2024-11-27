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
 *  File:       Dio_Cfg.h
 *  Generator:  Elektrobit Tresos
 *
 *  Description:  This file contains generated configuration data                                                        
 *********************************************************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H
/** \addtogroup DIO
 *  @{
 */
/*********************************************************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 *********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************************************************************
 * Header Files
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Version Check (if required)
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Preprocessor #define Constants
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 *
 * \brief Dio Driver Configuration SW Version Info.
 *
 *********************************************************************************************************************/
/** \brief Dio configuration Major Version */
#define DIO_CFG_MAJOR_VERSION           ([!"substring-before($moduleSoftwareVer,'.')"!]U)
/** \brief Dio configuration Minor Version */
#define DIO_CFG_MINOR_VERSION           ([!"substring-before(substring-after($moduleSoftwareVer,'.'),'.')"!]U)
/** \brief Dio configuration Patch Version */
#define DIO_CFG_PATCH_VERSION           ([!"substring-after(substring-after($moduleSoftwareVer,'.'),'.')"!]U)


/*********************************************************************************************************************
 *  \name DIO service enable/disable defines
 *
 *  Pre-compile switches for enabling/disabling DIO MCAL APIs
 *  
 *********************************************************************************************************************/
 /* Design: MCAL-22500 */
/*********************************************************************************************************************
 *
 * \brief Enable/Disable DEV error detection.
 *
 *********************************************************************************************************************/
/* Design: MCAL-22501 */
#define DIO_DEV_ERROR_DETECT      [!IF "as:modconf('Dio')[1]/DioGeneral/DioDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*********************************************************************************************************************
 *
 * \brief Enable/Disable Dio_GetVersionInfo().
 *
 *********************************************************************************************************************/
/* Design: MCAL-22503 */
#define DIO_VERSION_INFO_API      [!IF "as:modconf('Dio')[1]/DioGeneral/DioVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/*********************************************************************************************************************
 *
 * \brief Enable/Disable Dio_FlipChannel().
 *
 *********************************************************************************************************************/
/* Design: MCAL-22502 */
#define DIO_FLIP_CHANNEL_API      [!IF "as:modconf('Dio')[1]/DioGeneral/DioFlipChannelApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#endif
/*********************************************************************************************************************
 *
 * \brief Defines mapping to physical GPIO ports.
 *
 *********************************************************************************************************************/
/* Design: MCAL-22505 */
/** \brief GPIO PORT A identifier. */
#define GPIO_PORT_A                 (0U)
/** \brief GPIO PORT B identifier. */ 
#define GPIO_PORT_B                 (1U)
/** \brief GPIO PORT C identifier. */
#define GPIO_PORT_C                 (2U)
/** \brief GPIO PORT D identifier. */ 
#define GPIO_PORT_D                 (3U)
/** \brief GPIO PORT E identifier. */ 
#define GPIO_PORT_E                 (4U)
/** \brief GPIO PORT F identifier. */ 
#define GPIO_PORT_F                 (5U)
/** \brief GPIO PORT G identifier. */ 
#define GPIO_PORT_G                 (6U)
/** \brief GPIO PORT H identifier. */ 
#define GPIO_PORT_H                 (7U) 

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*********************************************************************************************************************
 *
 * \brief  This is symbolic name of DIO ports generated from configurator.
 * These defines map to physical GPIO port numbers.
 *
 *********************************************************************************************************************/
/* Design: MCAL-22504, MCAL-22474, MCAL-22473, MCAL-22537, MCAL-22538 */
[!VAR "var1" = "0"!][!//
[!LOOP "as:modconf('Dio')[1]/DioConfig/DioPort/*"!][!//
/* Symbolic name for [!"concat('GPIO_PORT_', translate(DioPortId, '01234567', 'ABCDEFGH'))"!] */
#define DioConf_DioPort_[!"@name"!] ((Dio_PortType)  [!"concat('GPIO_PORT_', translate(DioPortId, '01234567', 'ABCDEFGH'))"!]) /*~ASR~*/
[!CR!][!VAR "var1" = "$var1+1"!][!//
[!ENDLOOP!][!//

/*********************************************************************************************************************
 *
 * \brief Port Mask for enabled ports.
 *
 *********************************************************************************************************************/
#define DIO_CFG_ENABLED_PORT_MASK             (0U [!//
[!LOOP "as:modconf('Dio')[1]/DioConfig/DioPort/*"!]\
                                                  | (1U << [!"concat('GPIO_PORT_', translate(DioPortId, '01234567', 'ABCDEFGH'))"!])[!//
[!ENDLOOP!][!//
)[!//

/*********************************************************************************************************************
 *
 * \brief Max number of DIO ports.
 *
 *********************************************************************************************************************/
#define DIO_MAX_NO_OF_PORTS             [!"num:i($var1)"!]U

/*********************************************************************************************************************
 *
 * \name Symbolic name of DIO Channels
 * \brief  This is symbolic name of DIO channels generated from configurator.
 * These defines map to GPIO register channels.
 *
 * The channel numbers are mapped as
 *  GPIO_PORT_A: Channel 0  - Channel 31
 *  GPIO_PORT_B: Channel 32 - Channel 63
 *  GPIO_PORT_C: Channel 64 - Channel 95
 *  GPIO_PORT_D: Channel 96 - Channel 127
 *  GPIO_PORT_E: Channel 128 - Channel 159
 *  GPIO_PORT_F: Channel 160 - Channel 191
 *  GPIO_PORT_G: Channel 192 - Channel 223
 *  GPIO_PORT_H: Channel 224 - Channel 255
 *
 *********************************************************************************************************************/
/* Design: MCAL-22471, MCAL-22469, MCAL-22506, MCAL-22507, MCAL-22470, MCAL-22537, MCAL-22538*/
[!VAR "var1" = "0"!][!//
[!LOOP "as:modconf('Dio')[1]/DioConfig/DioPort/*"!][!//
[!LOOP "DioChannel/*"!][!//
/* Symbolic name for GPIO channel #[!"DioChannelId"!] [!"@name"!] */
#define DioConf_DioChannel_[!"@name"!] ((Dio_ChannelType) [!"DioChannelId"!]U) /*~ASR~*/
[!VAR "var1" = "$var1+1"!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//

/*********************************************************************************************************************
 *
 * \name Symbolic name of DIO Channel Groups
 *
 * \brief This is the symbolic name of DIO channel groups generated from
 * configurator. The definition of the channel groups is present in the
 * generated Dio_LCfg.c file. The other modules will invoke the
 * Dio_channelGroup APIs using the symbolic name defines.
 *
 *********************************************************************************************************************/
/* Design: MCAL-22476, MCAL-22508, MCAL-22509, MCAL-22537, MCAL-22538 */
[!VAR "var1" = "0"!][!//
[!LOOP "as:modconf('Dio')[1]/DioConfig/DioPort/*"!][!LOOP "DioChannelGroup/*"!][!//
#define DioConf_DioChannelGroup_[!"@name"!] ((P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_CONST)) Dio_ChannelGroupRef[[!"num:i($var1)"!]]) /*~ASR~*/
[!VAR "var1" = "$var1+1"!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
#define DIO_MAX_NO_OF_CHANNEL_GROUPS 	[!"num:i($var1)"!]U

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

extern P2CONST(struct Dio_ChannelGroupType_s, AUTOMATIC, DIO_CONST) Dio_ChannelGroupRef[DIO_MAX_NO_OF_CHANNEL_GROUPS];
#endif
/*********************************************************************************************************************
 * Exported Function Prototypes
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif  /* DIO_CFG_H */

/*********************************************************************************************************************
 * End of File: Dio_Cfg.h
 *********************************************************************************************************************/