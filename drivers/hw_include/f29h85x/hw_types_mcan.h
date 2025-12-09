//###########################################################################
//
// FILE:    hw_types_mcan.h
//
// DESCRIPTION:   This file contains the in-line functions required to 
//                read/write values from/to the hardware registers. This 
//                file also contains field manipulation macros to get and 
//                set field values.
//
//###########################################################################
// //
//	Copyright: Copyright (C) Texas Instruments Incorporated
//	All rights reserved not granted herein.
//
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//  Redistributions of source code must retain the above copyright 
//  notice, this list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the 
//  documentation and/or other materials provided with the   
//  distribution.
//
//  Neither the name of Texas Instruments Incorporated nor the names of
//  its contributors may be used to endorse or promote products derived
//  from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

//###########################################################################

#ifndef HW_TYPES_H_
#define HW_TYPES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \brief   This macro reads a 32-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 32-bit value read from a register.
 */
#define HW_RD_REG32(addr) (uint32)(HW_RD_REG32_RAW((uint32) (addr)))

/**
 *  \brief   This macro writes a 32-bit value to a hardware register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 32-bit value which has to be written to the
 *                   register.
 */
#define HW_WR_REG32(addr, value)                                               \
    (HW_WR_REG32_RAW((uint32) (addr), (uint32) (value)))

/**
 *  \brief   This macro reads a 16-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 16-bit value read from a register.
 */
#define HW_RD_REG16(addr) (HW_RD_REG16_RAW((uint32) (addr)))

/**
 *  \brief   This macro writes a 16-bit value to a hardware register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 16-bit value which has to be written to the
 *                   register.
 */
#define HW_WR_REG16(addr, value)                                               \
    (HW_WR_REG16_RAW((uint32) (addr), (uint16) (value)))

/**
 *  \brief   This macro reads a 8-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 8-bit value read from a register.
 */
#define HW_RD_REG8(addr) (HW_RD_REG8_RAW((uint32) (addr)))

/**
 *  \brief   This macro writes a 8-bit value to a hardware
 *           register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 8-bit value which has to be written to the
 *                   register.
 */
#define HW_WR_REG8(addr, value)                                                \
    (HW_WR_REG8_RAW((uint32) (addr), (uint8) (value)))

/**
 *  \brief Macro to extract a field value. This macro extracts the field value
 *         from a 32-bit variable (which contains the register value).
 *         This macro does not read from actual register address, and only
 *         extracts the field from a variable.
 *
 *  \param regVal         32-bit variable containing the register value.
 *  \param REG_FIELD      Peripheral register bit field name, whose value has to
 *                        be extracted.
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
#define HW_GET_FIELD(regVal, REG_FIELD)                                        \
    (((regVal) & (uint32) REG_FIELD##_MASK) >> (uint32) REG_FIELD##_SHIFT)

/**
 *  \brief Macro to write a specific field value. This macro first clears the
 *         specified field value and then performs "OR" of the field value which
 *         is shifted and masked. This will set the field value at its
 *         desired position.
 *
 *  \param regVal         32-bit variable containing the register value.
 *  \param REG_FIELD      Peripheral register bit field name, to which specified
 *                        value has to be set.
 *  \param fieldVal       Value of the field which has to be set.
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
#define HW_SET_FIELD32(regVal, REG_FIELD, fieldVal)                            \
    ((regVal) = ((regVal) & (uint32) (~(uint32) REG_FIELD##_MASK)) |       \
                    ((((uint32) (fieldVal)) << (uint32) REG_FIELD##_SHIFT) \
                        & (uint32) REG_FIELD##_MASK))

/**
 *  \brief Macro to write a specific field value. This macro first clears the
 *         specified field value and then performs "OR" of the field value which
 *         is shifted and masked. This will set the field value at its
 *         desired position.
 *
 *  \param regVal         16-bit variable containing the register value.
 *  \param REG_FIELD      Peripheral register bit field name, to which specified
 *                        value has to be set.
 *  \param fieldVal       Value of the field which has to be set.
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
#define HW_SET_FIELD16(regVal, REG_FIELD, fieldVal)                            \
    ((regVal) = ((regVal) & (uint16) (~(uint16) REG_FIELD##_MASK)) |       \
                    ((((uint16) (fieldVal)) << (uint16) REG_FIELD##_SHIFT) \
                        & (uint16) REG_FIELD##_MASK))

/**
 *  \brief Macro to write a specific field value. This macro first clears the
 *         specified field value and then performs "OR" of the field value which
 *         is shifted and masked. This will set the field value at its
 *         desired position.
 *
 *  \param regVal         8-bit variable containing the register value.
 *  \param REG_FIELD      Peripheral register bit field name, to which specified
 *                        value has to be set.
 *  \param fieldVal       Value of the field which has to be set.
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
//#define HW_SET_FIELD8(regVal, REG_FIELD, fieldVal)                           \
//    ((regVal) = ((regVal) & (uint8) (~(uint8) REG_FIELD##_MASK)) |       \
//                    ((((uint8) (fieldVal)) << (uint8) REG_FIELD##_SHIFT) \
//                        & (uint8) REG_FIELD##_MASK))

/**
 *  \brief This macro calls read-modify-write API for 32 bit register. It also
 *         frames the mask and shift from register field macro.
 *
 *  \param regAddr        Register Address.
 *  \param REG_FIELD      Peripheral register bit field name, to which specified
 *                        value has to be set.
 *  \param fieldVal       Value of the field which has to be set.
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
#define HW_WR_FIELD32(regAddr, REG_FIELD, fieldVal)                            \
    (HW_WR_FIELD32_RAW((uint32) (regAddr), (uint32) REG_FIELD##_MASK,      \
                          (uint32) REG_FIELD##_SHIFT, (uint32) (fieldVal)))

/**
 *  \brief This macro calls read-modify-write API for 16 bit register. It also
 *         frames the mask and shift from register field macro.
 *
 *  \param regAddr        Register Address.
 *  \param REG_FIELD      Peripheral register bit field name, to which specified
 *                        value has to be set.
 *  \param fieldVal       Value of the field which has to be set.
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
#define HW_WR_FIELD16(regAddr, REG_FIELD, fieldVal)                            \
    (HW_WR_FIELD16_RAW((uint32) (regAddr), (uint16) REG_FIELD##_MASK,      \
                          (uint32) REG_FIELD##_SHIFT, (uint16) (fieldVal)))

/**
 *  \brief This macro calls read-modify-write API for 8 bit register. It also
 *         frames the mask and shift from register field macro.
 *
 *  \param regAddr        Register Address.
 *  \param REG_FIELD      Peripheral register bit field name, to which specified
 *                        value has to be set.
 *  \param fieldVal       Value of the field which has to be set.
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
//#define HW_WR_FIELD8(regAddr, REG_FIELD, fieldVal)                             \
//    (HW_WR_FIELD8_RAW((uint32) (regAddr), (uint8) REG_FIELD##_MASK,        \
//                         (uint32) REG_FIELD##_SHIFT, (uint8) (fieldVal)))

/**
 *  \brief This macro calls read field API for 32 bit register. It also
 *         frames the mask and shift from register field macro.
 *
 *  \param regAddr        Register Address.
 *  \param REG_FIELD      Peripheral register bit field name, from which
 *                        specified bit-field value has to be read.
 *  \return Value of the bit-field
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
#define HW_RD_FIELD32(regAddr, REG_FIELD)                                      \
    (HW_RD_FIELD32_RAW((uint32) (regAddr), (uint32) REG_FIELD##_MASK,      \
                          (uint32) REG_FIELD##_SHIFT))

/**
 *  \brief This macro calls read field API for 16 bit register. It also
 *         frames the mask and shift from register field macro.
 *
 *  \param regAddr        Register Address.
 *  \param REG_FIELD      Peripheral register bit field name, from which
 *                        specified bit-field value has to be read.
 *  \return Value of the bit-field
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
#define HW_RD_FIELD16(regAddr, REG_FIELD)                                      \
    (HW_RD_FIELD16_RAW((uint32) (regAddr), (uint16) REG_FIELD##_MASK,      \
                          (uint32) REG_FIELD##_SHIFT))

/**
 *  \brief This macro calls read field API for 8 bit register. It also
 *         frames the mask and shift from register field macro.
 *
 *  \param regAddr        Register Address.
 *  \param REG_FIELD      Peripheral register bit field name, from which
 *                        specified bit-field value has to be read.
 *  \return Value of the bit-field
 */
/*TI_INSPECTED 76 S : MISRAC_2012_R.20.11
 * "The places in which order of evaluation has no side effects could be a
    waiver. This used in SHIFT and MASK to extract specified field value " */
/*TI_INSPECTED 125 S : MISRAC_2012_R.20.12
 * "The places in which order of evaluation has no side effects could be a
    waiver. ## operator here used in SHIFT and MASK to extract specified field
    value " */
//#define HW_RD_FIELD8(regAddr, REG_FIELD)                                       \
//    (HW_RD_FIELD8_RAW((uint32) (regAddr), (uint8) REG_FIELD##_MASK,        \
//                         (uint32) REG_FIELD##_SHIFT))

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                       Global Variables Declarations                        */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief   This function reads a 32-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 32-bit value read from a register.
 */
static inline uint32 HW_RD_REG32_RAW(uint32 addr);

/**
 *  \brief   This function writes a 32-bit value to a hardware register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 32-bit value which has to be written to the
 *                   register.
 */
static inline void HW_WR_REG32_RAW(uint32 addr, uint32 value);

/**
 *  \brief   This function reads a 16-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 16-bit value read from a register.
 */
static inline uint16 HW_RD_REG16_RAW(uint32 addr);

/**
 *  \brief   This function writes a 16-bit value to a hardware register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 16-bit value which has to be written to the
 *                   register.
 */
static inline void HW_WR_REG16_RAW(uint32 addr, uint16 value);

/**
 *  \brief   This function reads a 8-bit value from a hardware register
 *           and returns the value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *
 *  \return  Unsigned 8-bit value read from a register.
 */
//static inline uint8 HW_RD_REG8_RAW(uint32 addr);

/**
 *  \brief   This function writes a 8-bit value to a hardware
 *           register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   value   unsigned 8-bit value which has to be written to the
 *                   register.
 */
//static inline void HW_WR_REG8_RAW(uint32 addr, uint8 value);

/**
 *  \brief   This function reads a 32 bit register, modifies specific set of
 *           bits and writes back to the register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *  \param   value   Value to be written to bit-field.
 */
static inline void HW_WR_FIELD32_RAW(uint32 addr,
                                     uint32 mask,
                                     uint32 shift,
                                     uint32 value);

/**
 *  \brief   This function reads a 16 bit register, modifies specific set of
 *           bits and writes back to the register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *  \param   value   Value to be written to bit-field.
 */
static inline void HW_WR_FIELD16_RAW(uint32 addr,
                                     uint16 mask,
                                     uint32 shift,
                                     uint16 value);

/**
 *  \brief   This function reads a 8 bit register, modifies specific set of
 *           bits and writes back to the register.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *  \param   value   Value to be written to bit-field.
 */
//static inline void HW_WR_FIELD8_RAW(uint32 addr,
//                                    uint8 mask,
//                                    uint32 shift,
//                                    uint8 value);

/**
 *  \brief   This function reads a 32 bit register, masks specific set of bits
 *           and the left shifted value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *
 *  \return  Bit-field value (absolute value - shifted to LSB position)
 */
static inline uint32 HW_RD_FIELD32_RAW(uint32 addr,
                                         uint32 mask,
                                         uint32 shift);

/**
 *  \brief   This function reads a 16 bit register, masks specific set of bits
 *           and the left shifted value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *
 *  \return  Bit-field value (absolute value - shifted to LSB position)
 */
static inline uint16 HW_RD_FIELD16_RAW(uint32 addr,
                                         uint16 mask,
                                         uint32 shift);

/**
 *  \brief   This function reads a 8 bit register, masks specific set of bits
 *           and the left shifted value.
 *
 *  \param   addr    Address of the memory mapped hardware register.
 *  \param   mask    Mask for the bit field.
 *  \param   shift   Bit field shift from LSB.
 *
 *  \return  Bit-field value (absolute value - shifted to LSB position)
 */
//static inline uint8 HW_RD_FIELD8_RAW(uint32 addr,
//                                       uint8 mask,
//                                       uint32 shift);

/* ========================================================================== */
/*                       Static Function Definitions                          */
/* ========================================================================== */

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_RD_REG32 mcaro " */
/*TI_INSPECTED 101 S : MISRAC_2012_R.10.3
 * "Reason - Tool Issue: Not able to understand Inline Function return type " */
/*TI_INSPECTED 102 S : MISRAC_2012_R.8.4
 * "Reason - Tool Issue: Not able to understand Inline Function return type " */
static inline uint32 HW_RD_REG32_RAW(uint32 addr)
{
/*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
 * "Reason - Pointer typecast required here since addr variable holds
 * required register value" */
    uint32 regVal = *(volatile uint32 *) addr;
    return (regVal);
}

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_WR_REG32 mcaro " */
/*TI_INSPECTED 131 S : MISRAC_2012_R.5.3
 * "Tool Issue - argument 'value' used here is in same scope " */
/*TI_INSPECTED 14 D 1: MISRAC_2012_R.5.8
 * "Tool Issue - Modifying the contents stored at address not the addr itself */
static inline void HW_WR_REG32_RAW(uint32 addr, uint32 value)
{
/*TI_INSPECTED 18 D : MISRAC_2012_R.5.3
 * "Tool Issue - argument 'value' used here is in same scope " */
    *(volatile uint32 *) addr = value;
    return;
}

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_RD_REG16 mcaro " */
static inline uint16 HW_RD_REG16_RAW(uint32 addr)
{
/*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
 * "Reason - Pointer typecast required here since addr variable holds
 * required register value" */
    uint16 regVal = *(volatile uint16 *) addr;
    return (regVal);
}

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_WR_REG16 mcaro " */
/*TI_INSPECTED 131 S : MISRAC_2012_R.5.3
 * "Tool Issue - argument 'value' used here is in same scope " */
/*TI_INSPECTED 14 D 1: MISRAC_2012_R.5.8
 * "Tool Issue - Modifying the contents stored at address not the addr itself */
static inline void HW_WR_REG16_RAW(uint32 addr, uint16 value)
{
/*TI_INSPECTED 18 D : MISRAC_2012_R.5.3
 * "Tool Issue - argument 'value' used here is in same scope " */
    *(volatile uint16 *) addr = value;
    return;
}

///*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
// * "Reason - This function is called using HW_RD_REG8 mcaro " */
//static inline uint8 HW_RD_REG8_RAW(uint32 addr)
//{
///*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
// * "Reason - Pointer typecast required here since addr variable holds
// * required register value" */
//    uint8 regVal = *(volatile uint8 *) addr;
//    return (regVal);
//}

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_WR_REG8 mcaro " */
/*TI_INSPECTED 131 S : MISRAC_2012_R.5.3
 * "Tool Issue - argument 'value' used here is in same scope " */
/*TI_INSPECTED 14 D 1: MISRAC_2012_R.5.8
 * "Tool Issue - Modifying the contents stored at address not the addr itself */
//static inline void HW_WR_REG8_RAW(uint32 addr, uint8 value)
//{
///*TI_INSPECTED 18 D : MISRAC_2012_R.5.3
// * "Tool Issue - argument 'value' used here is in same scope " */
//    *(volatile uint8 *) addr = value;
//    return;
//}

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_WR_FIELD32 mcaro " */
/*TI_INSPECTED 14 D 1: MISRAC_2012_R.5.8
 * "Tool Issue - Modifying the contents stored at address not the addr itself */
static inline void HW_WR_FIELD32_RAW(uint32 addr,
                                     uint32 mask,
                                     uint32 shift,
                                     uint32 value)
{
/*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
 * "Reason - Pointer typecast required here since addr variable holds
 * required register value" */
    uint32 regVal = *(volatile uint32 *) addr;
    regVal &= (~mask);
    regVal |= (value << shift) & mask;
/*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
 * "Reason - Pointer typecast required here since addr variable holds
 * required register value" */
    *(volatile uint32 *) addr = regVal;
    return;
}

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_WR_FIELD16 mcaro " */
/*TI_INSPECTED 14 D 1: MISRAC_2012_R.5.8
 * "Tool Issue - Modifying the contents stored at address not the addr itself */
static inline void HW_WR_FIELD16_RAW(uint32 addr,
                                     uint16 mask,
                                     uint32 shift,
                                     uint16 value)
{
    uint32 tempVal;
/*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
 * "Reason - Pointer typecast required here since addr variable holds
 * required register value" */
    uint16 regVal = *(volatile uint16 *) addr;
    tempVal = ((uint32) regVal);
    tempVal &=  (~((uint32) mask));
    tempVal |= (((uint32) value) << shift) & ((uint32) mask);
    regVal = (uint16) tempVal;
/*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
 * "Reason - Pointer typecast required here since addr variable holds
 * required register value" */
    *(volatile uint16 *) addr = regVal;
    return;
}

///*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
// * "Reason - This function is called using HW_WR_FIELD8 mcaro " */
///*TI_INSPECTED 14 D 1: MISRAC_2012_R.5.8
// * "Tool Issue - Modifying the contents stored at address not the addr itself */
//static inline void HW_WR_FIELD8_RAW(uint32 addr,
//                                    uint8 mask,
//                                    uint32 shift,
//                                    uint8 value)
//{
//    uint32 tempVal;
///*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
// * "Reason - Pointer typecast required here since addr variable holds
// * required register value" */
//    uint8 regVal = *(volatile uint8 *) addr;
//    tempVal = ((uint32) regVal);
//    tempVal &=  (~((uint32) mask));
//    tempVal |= (((uint32) value) << shift) & ((uint32) mask);
//    regVal = (uint8) tempVal;
///*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
// * "Reason - Pointer typecast required here since addr variable holds
// * required register value" */
//    *(volatile uint8 *) addr = regVal;
//    return;
//}

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_RD_FIELD32 mcaro " */
static inline uint32 HW_RD_FIELD32_RAW(uint32 addr,
                                         uint32 mask,
                                         uint32 shift)
{
/*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
 * "Reason - Pointer typecast required here since addr variable holds
 * required register value" */
    uint32 regVal = *(volatile uint32 *) addr;
    regVal = (regVal & mask) >> shift;
    return (regVal);
}

/*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
 * "Reason - This function is called using HW_RD_FIELD16 mcaro " */
static inline uint16 HW_RD_FIELD16_RAW(uint32 addr,
                                         uint16 mask,
                                         uint32 shift)
{
    uint32 tempVal;
/*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
 * "Reason - Pointer typecast required here since addr variable holds
 * required register value" */
    uint16 regVal = *(volatile uint16 *) addr;
    tempVal = (((uint32) regVal & (uint32) mask) >> shift);
    regVal = (uint16) tempVal;
    return (regVal);
}

///*TI_INSPECTED 35 S : MISRAC_2012_R.2.1
// * "Reason - This function is called using HW_RD_FIELD8 mcaro " */
//static inline uint8 HW_RD_FIELD8_RAW(uint32 addr,
//                                       uint8 mask,
//                                       uint32 shift)
//{
//    uint32 tempVal;
///*TI_INSPECTED 440 S : MISRAC_2012_R.11.4
// * "Reason - Pointer typecast required here since addr variable holds
// * required register value" */
//    uint8 regVal = *(volatile uint8 *) addr;
//    tempVal = (((uint32) regVal & (uint32) mask) >> shift);
//    regVal = (uint8) tempVal;
//    return (regVal);
//}

#ifdef __cplusplus
}
#endif

#endif /* #ifndef HW_TYPES_H_ */
