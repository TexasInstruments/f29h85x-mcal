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
 *  File:       Cdd_Sent_Reg_Access.h
 *  Generator:  None
 *
 *  Description:  This file contains macros for CDD_SENT register access
 *********************************************************************************************************************/
#ifndef CDD_SENT_REG_ACCESS_H
#define CDD_SENT_REG_ACCESS_H

/** \addtogroup CDD_SENT
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

/** \brief This function reads a 32 bit register, masks specific set of bits
 *        and the left shifted value.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \param[in] shift Bit field shift from LSB.
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
LOCAL_INLINE uint32 Cdd_Sent_RegMFReadRaw32(uint32 addr, \
                                        uint32 mask, \
                                        uint32 shift);

/** \brief This function clears a 32 bit register masking field.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE void Cdd_Sent_RegBitClear32(uint32 addr, \
                                      uint32 mask);

/** \brief This function Set a 32 bit register masking field.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] mask Mask for the bit field.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE void Cdd_Sent_RegBitSet32(uint32 addr, \
                                      uint32 mask);

/** \brief This function writes a 32 bit register masking specific set of bits
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
LOCAL_INLINE void Cdd_Sent_RegMFWriteRaw32(uint32 addr, \
                                      uint32 mask, \
                                      uint32 shift, \
                                      uint32 value);

/** \brief This function reads a 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \pre None
 * \post None
 * \return Bit-field value (absolute value - shifted to LSB position).
 * \retval Value of the type uint32.
 *
 ******************************************************************************/
LOCAL_INLINE uint32 Cdd_Sent_RegReadRaw32(uint32 addr);

/** \brief This function writes a 32 bit register.
 *
 * \param[in] addr Address of the memory mapped hardware register.
 * \param[in] value Value to write in the 32-bit register.
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ******************************************************************************/
LOCAL_INLINE void Cdd_Sent_RegWriteRaw32(uint32 addr, \
                                     uint32 value);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/
LOCAL_INLINE void Cdd_Sent_RegWriteRaw32(uint32 addr, \
                                     uint32 value)
{
    *(volatile uint32 *) addr = value;
}

LOCAL_INLINE uint32 Cdd_Sent_RegReadRaw32(uint32 addr)
{
    uint32 regVal = *(volatile uint32 *)addr;
    return (regVal);
}

LOCAL_INLINE void Cdd_Sent_RegMFWriteRaw32(uint32 addr, \
                                      uint32 mask, \
                                      uint32 shift, \
                                      uint32 value)
{
    uint32 regVal = *(volatile uint32 *)addr;
    regVal &= (~mask);
    regVal |= (value << shift) & mask;
    *(volatile uint32 *)addr = regVal;
}

LOCAL_INLINE void Cdd_Sent_RegBitSet32(uint32 addr, \
                                      uint32 mask)
{
	
    uint32 regVal = *(volatile uint32 *)addr;
    regVal |= (mask);
    *(volatile uint32 *)addr = regVal;
}

LOCAL_INLINE void Cdd_Sent_RegBitClear32(uint32 addr, \
                                      uint32 mask)
{
	
    uint32 regVal = *(volatile uint32 *)addr;
    regVal &= (~mask);
    *(volatile uint32 *)addr = regVal;
    
}

LOCAL_INLINE uint32 Cdd_Sent_RegMFReadRaw32(uint32 addr, \
                                        uint32 mask, \
                                        uint32 shift)
{
    uint32 regVal = *(volatile uint32 *)addr;
    regVal = (regVal & mask) >> shift;
    return (regVal);
}
#ifdef __cplusplus
}
#endif
/**
 * @}
 */
#endif /* CDD_SENT_REG_ACCESS_H */
/*********************************************************************************************************************
 *  End of File: Cdd_Sent_Reg_Access.h
 *********************************************************************************************************************/