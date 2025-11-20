//###########################################################################
//
// FILE:   hw_types.h
//
// TITLE:  Type definitions used in driverlib functions.
//
//###########################################################################
// $Copyright:  $
//###########################################################################

#ifndef HW_TYPES_H
#define HW_TYPES_H

//*****************************************************************************
//
// Macros for hardware access
//
//*****************************************************************************

#define HWREG(x)    (*((volatile uint32 *)(x)))
#define HWREGH(x)   (*((volatile uint16 *)(x)))
#define HWREGB(x)   (*((volatile uint8 *)(x)))


//****************************************************************************
//
// For checking NULL pointers
//
//****************************************************************************
#ifndef NULL
#define NULL ((void *)0x0)
#endif


//
// C++ Bool Compatibility
//
#if defined(__cplusplus)
typedef bool _Bool;
#endif


#endif // HW_TYPES_H
