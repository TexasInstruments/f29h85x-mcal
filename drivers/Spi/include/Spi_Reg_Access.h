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
 *  File:       Spi_Reg_Access.h
 *  Generator:  None
 *
 *  Description:  This file contains macros for SPI register access
 *********************************************************************************************************************/
#ifndef SPI_REG_ACCESS_H
#define SPI_REG_ACCESS_H
/** \addtogroup SPI
 *  @{
 */
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

/*********************************************************************************************************************
 * Exported Preprocessor #define Macros
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Type Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief This function reads a 16 bit register, masks specific set of bits
 *        and the left shifted value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \param[in] shift Bit field shift from LSB.
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint16.
 *
 ******************************************************************************/
static inline uint16 Spi_RegMFReadRaw16(uint32 addr,\
                                        uint16 mask,\
                                        uint16 shift)
{
    uint16 regVal = *(volatile uint16 *)addr;
    regVal = (regVal & mask) >> shift;
    return (regVal);
}

/** \brief This function writes a 16 bit register masking specific set of bits
 *        and the left shifted value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \param[in] shift Bit field shift from LSB.
 * \param[in] value Value to write in the memory mapped hardware register.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
static inline void Spi_RegMFWriteRaw16(uint32 addr,\
                                      uint16 mask,\
                                      uint16 shift,\
                                      uint16 value)
{
    uint16 regVal = *(volatile uint16 *)addr;
    regVal &= (~mask);
    regVal |= (uint16) ((uint16) (value << shift) & mask);
    *(volatile uint16 *)addr = regVal;
}

/** \brief This function reads a 16 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint16.
 *
 ******************************************************************************/
static inline uint16 Spi_RegReadRaw16(uint32 addr)
{
    uint16 regVal = *(volatile uint16 *)addr;
    return (regVal);
}

/** \brief This function writes a 16 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] value Value to write in the 16-bit register.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
static inline void Spi_RegWriteRaw16(uint32 addr,\
                                     uint16 value)
{
    *(volatile uint16 *) addr = value;
}


/** \brief This function sets one of the bit in 16 bit register
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask mask of the bit to set.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
static inline void Spi_RegBitSet16(uint32 addr,\
                                        uint16 mask)
{
    uint16 regVal = *(volatile uint16 *)addr;
    regVal |= mask;
    *(volatile uint16 *)addr = regVal;
}

/** \brief This function clears one of the bit in 16 bit register
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask mask of the bit to clear.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
static inline void Spi_RegBitClear16(uint32 addr,\
                                        uint16 mask)
{
    uint16 regVal = *(volatile uint16 *)addr;
    regVal &= (~mask);
    *(volatile uint16 *)addr = regVal;
}                                        
/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* SPI_REG_ACCESS_H */
/*********************************************************************************************************************
 *  End of File: Spi_Reg_Access.h
 *********************************************************************************************************************/
