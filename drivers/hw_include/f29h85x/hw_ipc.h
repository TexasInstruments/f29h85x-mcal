//###########################################################################
//
// FILE:    hw_ipc.h
//
// TITLE:   Definitions for the IPC registers.
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

#ifndef HW_IPC_H
#define HW_IPC_H

//*************************************************************************************************
//
// The following are defines for the IPC register offsets
//
//*************************************************************************************************
#define IPC_O_COUNTERL   0x0U   // IPCCOUNTERL Register
#define IPC_O_COUNTERH   0x4U   // IPCCOUNTERH Register

#define IPC_O_CPU1TOCPU2INTIPCSET(i)        (0x0U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCSET Register
#define IPC_O_CPU1TOCPU2INTIPCCLR(i)        (0x4U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCCLR Register
#define IPC_O_CPU1TOCPU2INTIPCFLG(i)        (0x8U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCFLG Register
#define IPC_O_CPU1TOCPU2INTIPCSENDCOM(i)    (0x10U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCSENDCOM Register
#define IPC_O_CPU1TOCPU2INTIPCSENDADDR(i)   (0x14U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCSENDADDR Register
#define IPC_O_CPU1TOCPU2INTIPCSENDDATA(i)   (0x18U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCSENDDATA Register
#define IPC_O_CPU2TOCPU1INTREMOTEREPLY(i)   (0x1CU + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTREMOTEREPLY Register
#define IPC_O_CPU1TOCPU3INTIPCSET(i)        (0x2000U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCSET Register
#define IPC_O_CPU1TOCPU3INTIPCCLR(i)        (0x2004U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCCLR Register
#define IPC_O_CPU1TOCPU3INTIPCFLG(i)        (0x2008U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCFLG Register
#define IPC_O_CPU1TOCPU3INTIPCSENDCOM(i)    (0x2010U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCSENDCOM Register
#define IPC_O_CPU1TOCPU3INTIPCSENDADDR(i)   (0x2014U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCSENDADDR Register
#define IPC_O_CPU1TOCPU3INTIPCSENDDATA(i)   (0x2018U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCSENDDATA Register
#define IPC_O_CPU3TOCPU1INTREMOTEREPLY(i)   (0x201CU + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTREMOTEREPLY Register
#define IPC_O_CPU1TOHSMINTIPCSET(i)         (0x6000U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU1TOHSMINTIPCSET Register
#define IPC_O_CPU1TOHSMINTIPCCLR(i)         (0x6004U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU1TOHSMINTIPCCLR Register
#define IPC_O_CPU1TOHSMINTIPCFLG(i)         (0x6008U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU1TOHSMINTIPCFLG Register

#define IPC_O_CPU2TOCPU1INTIPCSTS(i)        (0x0U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCSTS Register
#define IPC_O_CPU1TOCPU2INTIPCACK(i)        (0x4U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCACK Register
#define IPC_O_CPU2TOCPU1INTIPCRECVCOM(i)    (0x10U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCRECVCOM Register
#define IPC_O_CPU2TOCPU1INTIPCRECVADDR(i)   (0x14U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCRECVADDR Register
#define IPC_O_CPU2TOCPU1INTIPCRECVDATA(i)   (0x18U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCRECVDATA Register
#define IPC_O_CPU1TOCPU2INTLOCALREPLY(i)    (0x1CU + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTLOCALREPLY Register
#define IPC_O_CPU3TOCPU1INTIPCSTS(i)        (0x2000U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCSTS Register
#define IPC_O_CPU1TOCPU3INTIPCACK(i)        (0x2004U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCACK Register
#define IPC_O_CPU3TOCPU1INTIPCRECVCOM(i)    (0x2010U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCRECVCOM Register
#define IPC_O_CPU3TOCPU1INTIPCRECVADDR(i)   (0x2014U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCRECVADDR Register
#define IPC_O_CPU3TOCPU1INTIPCRECVDATA(i)   (0x2018U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCRECVDATA Register
#define IPC_O_CPU1TOCPU3INTLOCALREPLY(i)    (0x201CU + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTLOCALREPLY Register

#define IPC_O_CPU2TOCPU1INTIPCSET(i)        (0x0U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCSET Register
#define IPC_O_CPU2TOCPU1INTIPCCLR(i)        (0x4U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCCLR Register
#define IPC_O_CPU2TOCPU1INTIPCFLG(i)        (0x8U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCFLG Register
#define IPC_O_CPU2TOCPU1INTIPCSENDCOM(i)    (0x10U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCSENDCOM Register
#define IPC_O_CPU2TOCPU1INTIPCSENDADDR(i)   (0x14U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCSENDADDR Register
#define IPC_O_CPU2TOCPU1INTIPCSENDDATA(i)   (0x18U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCSENDDATA Register
#define IPC_O_CPU1TOCPU2INTREMOTEREPLY(i)   (0x1CU + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTREMOTEREPLY Register
#define IPC_O_CPU2TOCPU3INTIPCSET(i)        (0x2000U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCSET Register
#define IPC_O_CPU2TOCPU3INTIPCCLR(i)        (0x2004U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCCLR Register
#define IPC_O_CPU2TOCPU3INTIPCFLG(i)        (0x2008U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCFLG Register
#define IPC_O_CPU2TOCPU3INTIPCSENDCOM(i)    (0x2010U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCSENDCOM Register
#define IPC_O_CPU2TOCPU3INTIPCSENDADDR(i)   (0x2014U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCSENDADDR Register
#define IPC_O_CPU2TOCPU3INTIPCSENDDATA(i)   (0x2018U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCSENDDATA Register
#define IPC_O_CPU3TOCPU2INTREMOTEREPLY(i)   (0x201CU + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTREMOTEREPLY Register
#define IPC_O_CPU2TOHSMINTIPCSET(i)         (0x6000U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU2TOHSMINTIPCSET Register
#define IPC_O_CPU2TOHSMINTIPCCLR(i)         (0x6004U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU2TOHSMINTIPCCLR Register
#define IPC_O_CPU2TOHSMINTIPCFLG(i)         (0x6008U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU2TOHSMINTIPCFLG Register

#define IPC_O_CPU1TOCPU2INTIPCSTS(i)        (0x0U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCSTS Register
#define IPC_O_CPU2TOCPU1INTIPCACK(i)        (0x4U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTIPCACK Register
#define IPC_O_CPU1TOCPU2INTIPCRECVCOM(i)    (0x10U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCRECVCOM Register
#define IPC_O_CPU1TOCPU2INTIPCRECVADDR(i)   (0x14U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCRECVADDR Register
#define IPC_O_CPU1TOCPU2INTIPCRECVDATA(i)   (0x18U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU2INTIPCRECVDATA Register
#define IPC_O_CPU2TOCPU1INTLOCALREPLY(i)    (0x1CU + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU2TOCPU1INTLOCALREPLY Register
#define IPC_O_CPU3TOCPU2INTIPCSTS(i)        (0x2000U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCSTS Register
#define IPC_O_CPU2TOCPU3INTIPCACK(i)        (0x2004U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCACK Register
#define IPC_O_CPU3TOCPU2INTIPCRECVCOM(i)    (0x2010U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCRECVCOM Register
#define IPC_O_CPU3TOCPU2INTIPCRECVADDR(i)   (0x2014U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCRECVADDR Register
#define IPC_O_CPU3TOCPU2INTIPCRECVDATA(i)   (0x2018U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCRECVDATA Register
#define IPC_O_CPU2TOCPU3INTLOCALREPLY(i)    (0x201CU + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTLOCALREPLY Register

#define IPC_O_CPU3TOCPU1INTIPCSET(i)        (0x0U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCSET Register
#define IPC_O_CPU3TOCPU1INTIPCCLR(i)        (0x4U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCCLR Register
#define IPC_O_CPU3TOCPU1INTIPCFLG(i)        (0x8U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCFLG Register
#define IPC_O_CPU3TOCPU1INTIPCSENDCOM(i)    (0x10U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCSENDCOM Register
#define IPC_O_CPU3TOCPU1INTIPCSENDADDR(i)   (0x14U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCSENDADDR Register
#define IPC_O_CPU3TOCPU1INTIPCSENDDATA(i)   (0x18U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCSENDDATA Register
#define IPC_O_CPU1TOCPU3INTREMOTEREPLY(i)   (0x1CU + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTREMOTEREPLY Register
#define IPC_O_CPU3TOCPU2INTIPCSET(i)        (0x2000U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCSET Register
#define IPC_O_CPU3TOCPU2INTIPCCLR(i)        (0x2004U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCCLR Register
#define IPC_O_CPU3TOCPU2INTIPCFLG(i)        (0x2008U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCFLG Register
#define IPC_O_CPU3TOCPU2INTIPCSENDCOM(i)    (0x2010U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCSENDCOM Register
#define IPC_O_CPU3TOCPU2INTIPCSENDADDR(i)   (0x2014U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCSENDADDR Register
#define IPC_O_CPU3TOCPU2INTIPCSENDDATA(i)   (0x2018U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCSENDDATA Register
#define IPC_O_CPU2TOCPU3INTREMOTEREPLY(i)   (0x201CU + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTREMOTEREPLY Register
#define IPC_O_CPU3TOHSMINTIPCSET(i)         (0x6000U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU3TOHSMINTIPCSET Register
#define IPC_O_CPU3TOHSMINTIPCCLR(i)         (0x6004U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU3TOHSMINTIPCCLR Register
#define IPC_O_CPU3TOHSMINTIPCFLG(i)         (0x6008U + ((i) * 4096U))   // (0 <= i < 2)
                                                                        // CPU3TOHSMINTIPCFLG Register

#define IPC_O_CPU1TOCPU3INTIPCSTS(i)        (0x0U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCSTS Register
#define IPC_O_CPU3TOCPU1INTIPCACK(i)        (0x4U + ((i) * 2048U))      // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTIPCACK Register
#define IPC_O_CPU1TOCPU3INTIPCRECVCOM(i)    (0x10U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCRECVCOM Register
#define IPC_O_CPU1TOCPU3INTIPCRECVADDR(i)   (0x14U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCRECVADDR Register
#define IPC_O_CPU1TOCPU3INTIPCRECVDATA(i)   (0x18U + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU1TOCPU3INTIPCRECVDATA Register
#define IPC_O_CPU3TOCPU1INTLOCALREPLY(i)    (0x1CU + ((i) * 2048U))     // (0 <= i < 4)
                                                                        // CPU3TOCPU1INTLOCALREPLY Register
#define IPC_O_CPU2TOCPU3INTIPCSTS(i)        (0x2000U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCSTS Register
#define IPC_O_CPU3TOCPU2INTIPCACK(i)        (0x2004U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTIPCACK Register
#define IPC_O_CPU2TOCPU3INTIPCRECVCOM(i)    (0x2010U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCRECVCOM Register
#define IPC_O_CPU2TOCPU3INTIPCRECVADDR(i)   (0x2014U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCRECVADDR Register
#define IPC_O_CPU2TOCPU3INTIPCRECVDATA(i)   (0x2018U + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU2TOCPU3INTIPCRECVDATA Register
#define IPC_O_CPU3TOCPU2INTLOCALREPLY(i)    (0x201CU + ((i) * 2048U))   // (0 <= i < 4)
                                                                        // CPU3TOCPU2INTLOCALREPLY Register



//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU2INTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU2INTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU1TOCPU2INTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU2INTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU2INTIPCCLR_IPC0    0x1U          // Clear CPU1TOCPU2IPCFLG.IPC0 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC1    0x2U          // Clear CPU1TOCPU2IPCFLG.IPC1 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC2    0x4U          // Clear CPU1TOCPU2IPCFLG.IPC2 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC3    0x8U          // Clear CPU1TOCPU2IPCFLG.IPC3 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC4    0x10U         // Clear CPU1TOCPU2IPCFLG.IPC4 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC5    0x20U         // Clear CPU1TOCPU2IPCFLG.IPC5 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC6    0x40U         // Clear CPU1TOCPU2IPCFLG.IPC6 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC7    0x80U         // Clear CPU1TOCPU2IPCFLG.IPC7 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC8    0x100U        // Clear CPU1TOCPU2IPCFLG.IPC8 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC9    0x200U        // Clear CPU1TOCPU2IPCFLG.IPC9 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC10   0x400U        // Clear CPU1TOCPU2IPCFLG.IPC10 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC11   0x800U        // Clear CPU1TOCPU2IPCFLG.IPC11 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC12   0x1000U       // Clear CPU1TOCPU2IPCFLG.IPC12 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC13   0x2000U       // Clear CPU1TOCPU2IPCFLG.IPC13 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC14   0x4000U       // Clear CPU1TOCPU2IPCFLG.IPC14 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC15   0x8000U       // Clear CPU1TOCPU2IPCFLG.IPC15 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC16   0x10000U      // Clear CPU1TOCPU2IPCFLG.IPC16 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC17   0x20000U      // Clear CPU1TOCPU2IPCFLG.IPC17 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC18   0x40000U      // Clear CPU1TOCPU2IPCFLG.IPC18 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC19   0x80000U      // Clear CPU1TOCPU2IPCFLG.IPC19 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC20   0x100000U     // Clear CPU1TOCPU2IPCFLG.IPC20 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC21   0x200000U     // Clear CPU1TOCPU2IPCFLG.IPC21 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC22   0x400000U     // Clear CPU1TOCPU2IPCFLG.IPC22 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC23   0x800000U     // Clear CPU1TOCPU2IPCFLG.IPC23 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC24   0x1000000U    // Clear CPU1TOCPU2IPCFLG.IPC24 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC25   0x2000000U    // Clear CPU1TOCPU2IPCFLG.IPC25 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC26   0x4000000U    // Clear CPU1TOCPU2IPCFLG.IPC26 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC27   0x8000000U    // Clear CPU1TOCPU2IPCFLG.IPC27 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC28   0x10000000U   // Clear CPU1TOCPU2IPCFLG.IPC28 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC29   0x20000000U   // Clear CPU1TOCPU2IPCFLG.IPC29 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC30   0x40000000U   // Clear CPU1TOCPU2IPCFLG.IPC30 Flag
#define IPC_CPU1TOCPU2INTIPCCLR_IPC31   0x80000000U   // Clear CPU1TOCPU2IPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU2INTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU2INTIPCFLG_IPC0    0x1U          // CPU1 to CPU2 IPC0 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC1    0x2U          // CPU1 to CPU2 IPC1 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC2    0x4U          // CPU1 to CPU2 IPC2 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC3    0x8U          // CPU1 to CPU2 IPC3 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC4    0x10U         // CPU1 to CPU2 IPC4 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC5    0x20U         // CPU1 to CPU2 IPC5 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC6    0x40U         // CPU1 to CPU2 IPC6 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC7    0x80U         // CPU1 to CPU2 IPC7 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC8    0x100U        // CPU1 to CPU2 IPC8 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC9    0x200U        // CPU1 to CPU2 IPC9 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC10   0x400U        // CPU1 to CPU2 IPC10 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC11   0x800U        // CPU1 to CPU2 IPC11 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC12   0x1000U       // CPU1 to CPU2 IPC12 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC13   0x2000U       // CPU1 to CPU2 IPC13 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC14   0x4000U       // CPU1 to CPU2 IPC14 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC15   0x8000U       // CPU1 to CPU2 IPC15 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC16   0x10000U      // CPU1 to CPU2 IPC16 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC17   0x20000U      // CPU1 to CPU2 IPC17 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC18   0x40000U      // CPU1 to CPU2 IPC18 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC19   0x80000U      // CPU1 to CPU2 IPC19 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC20   0x100000U     // CPU1 to CPU2 IPC20 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC21   0x200000U     // CPU1 to CPU2 IPC21 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC22   0x400000U     // CPU1 to CPU2 IPC22 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC23   0x800000U     // CPU1 to CPU2 IPC23 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC24   0x1000000U    // CPU1 to CPU2 IPC24 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC25   0x2000000U    // CPU1 to CPU2 IPC25 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC26   0x4000000U    // CPU1 to CPU2 IPC26 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC27   0x8000000U    // CPU1 to CPU2 IPC27 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC28   0x10000000U   // CPU1 to CPU2 IPC28 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC29   0x20000000U   // CPU1 to CPU2 IPC29 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC30   0x40000000U   // CPU1 to CPU2 IPC30 Flag Status
#define IPC_CPU1TOCPU2INTIPCFLG_IPC31   0x80000000U   // CPU1 to CPU2 IPC31 Flag Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU3INTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU3INTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU1TOCPU3INTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU3INTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU3INTIPCCLR_IPC0    0x1U          // Clear CPU1TOCPU3IPCFLG.IPC0 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC1    0x2U          // Clear CPU1TOCPU3IPCFLG.IPC1 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC2    0x4U          // Clear CPU1TOCPU3IPCFLG.IPC2 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC3    0x8U          // Clear CPU1TOCPU3IPCFLG.IPC3 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC4    0x10U         // Clear CPU1TOCPU3IPCFLG.IPC4 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC5    0x20U         // Clear CPU1TOCPU3IPCFLG.IPC5 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC6    0x40U         // Clear CPU1TOCPU3IPCFLG.IPC6 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC7    0x80U         // Clear CPU1TOCPU3IPCFLG.IPC7 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC8    0x100U        // Clear CPU1TOCPU3IPCFLG.IPC8 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC9    0x200U        // Clear CPU1TOCPU3IPCFLG.IPC9 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC10   0x400U        // Clear CPU1TOCPU3IPCFLG.IPC10 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC11   0x800U        // Clear CPU1TOCPU3IPCFLG.IPC11 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC12   0x1000U       // Clear CPU1TOCPU3IPCFLG.IPC12 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC13   0x2000U       // Clear CPU1TOCPU3IPCFLG.IPC13 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC14   0x4000U       // Clear CPU1TOCPU3IPCFLG.IPC14 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC15   0x8000U       // Clear CPU1TOCPU3IPCFLG.IPC15 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC16   0x10000U      // Clear CPU1TOCPU3IPCFLG.IPC16 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC17   0x20000U      // Clear CPU1TOCPU3IPCFLG.IPC17 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC18   0x40000U      // Clear CPU1TOCPU3IPCFLG.IPC18 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC19   0x80000U      // Clear CPU1TOCPU3IPCFLG.IPC19 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC20   0x100000U     // Clear CPU1TOCPU3IPCFLG.IPC20 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC21   0x200000U     // Clear CPU1TOCPU3IPCFLG.IPC21 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC22   0x400000U     // Clear CPU1TOCPU3IPCFLG.IPC22 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC23   0x800000U     // Clear CPU1TOCPU3IPCFLG.IPC23 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC24   0x1000000U    // Clear CPU1TOCPU3IPCFLG.IPC24 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC25   0x2000000U    // Clear CPU1TOCPU3IPCFLG.IPC25 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC26   0x4000000U    // Clear CPU1TOCPU3IPCFLG.IPC26 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC27   0x8000000U    // Clear CPU1TOCPU3IPCFLG.IPC27 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC28   0x10000000U   // Clear CPU1TOCPU3IPCFLG.IPC28 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC29   0x20000000U   // Clear CPU1TOCPU3IPCFLG.IPC29 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC30   0x40000000U   // Clear CPU1TOCPU3IPCFLG.IPC30 Flag
#define IPC_CPU1TOCPU3INTIPCCLR_IPC31   0x80000000U   // Clear CPU1TOCPU3IPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU3INTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU3INTIPCFLG_IPC0    0x1U          // CPU1 to CPU3 IPC0 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC1    0x2U          // CPU1 to CPU3 IPC1 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC2    0x4U          // CPU1 to CPU3 IPC2 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC3    0x8U          // CPU1 to CPU3 IPC3 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC4    0x10U         // CPU1 to CPU3 IPC4 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC5    0x20U         // CPU1 to CPU3 IPC5 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC6    0x40U         // CPU1 to CPU3 IPC6 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC7    0x80U         // CPU1 to CPU3 IPC7 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC8    0x100U        // CPU1 to CPU3 IPC8 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC9    0x200U        // CPU1 to CPU3 IPC9 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC10   0x400U        // CPU1 to CPU3 IPC10 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC11   0x800U        // CPU1 to CPU3 IPC11 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC12   0x1000U       // CPU1 to CPU3 IPC12 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC13   0x2000U       // CPU1 to CPU3 IPC13 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC14   0x4000U       // CPU1 to CPU3 IPC14 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC15   0x8000U       // CPU1 to CPU3 IPC15 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC16   0x10000U      // CPU1 to CPU3 IPC16 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC17   0x20000U      // CPU1 to CPU3 IPC17 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC18   0x40000U      // CPU1 to CPU3 IPC18 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC19   0x80000U      // CPU1 to CPU3 IPC19 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC20   0x100000U     // CPU1 to CPU3 IPC20 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC21   0x200000U     // CPU1 to CPU3 IPC21 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC22   0x400000U     // CPU1 to CPU3 IPC22 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC23   0x800000U     // CPU1 to CPU3 IPC23 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC24   0x1000000U    // CPU1 to CPU3 IPC24 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC25   0x2000000U    // CPU1 to CPU3 IPC25 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC26   0x4000000U    // CPU1 to CPU3 IPC26 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC27   0x8000000U    // CPU1 to CPU3 IPC27 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC28   0x10000000U   // CPU1 to CPU3 IPC28 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC29   0x20000000U   // CPU1 to CPU3 IPC29 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC30   0x40000000U   // CPU1 to CPU3 IPC30 Flag Status
#define IPC_CPU1TOCPU3INTIPCFLG_IPC31   0x80000000U   // CPU1 to CPU3 IPC31 Flag Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOHSMINTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU1TOHSMINTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU1TOHSMINTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOHSMINTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU1TOHSMINTIPCCLR_IPC0    0x1U          // Clear CPU1TOHSMIPCFLG.IPC0 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC1    0x2U          // Clear CPU1TOHSMIPCFLG.IPC1 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC2    0x4U          // Clear CPU1TOHSMIPCFLG.IPC2 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC3    0x8U          // Clear CPU1TOHSMIPCFLG.IPC3 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC4    0x10U         // Clear CPU1TOHSMIPCFLG.IPC4 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC5    0x20U         // Clear CPU1TOHSMIPCFLG.IPC5 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC6    0x40U         // Clear CPU1TOHSMIPCFLG.IPC6 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC7    0x80U         // Clear CPU1TOHSMIPCFLG.IPC7 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC8    0x100U        // Clear CPU1TOHSMIPCFLG.IPC8 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC9    0x200U        // Clear CPU1TOHSMIPCFLG.IPC9 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC10   0x400U        // Clear CPU1TOHSMIPCFLG.IPC10 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC11   0x800U        // Clear CPU1TOHSMIPCFLG.IPC11 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC12   0x1000U       // Clear CPU1TOHSMIPCFLG.IPC12 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC13   0x2000U       // Clear CPU1TOHSMIPCFLG.IPC13 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC14   0x4000U       // Clear CPU1TOHSMIPCFLG.IPC14 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC15   0x8000U       // Clear CPU1TOHSMIPCFLG.IPC15 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC16   0x10000U      // Clear CPU1TOHSMIPCFLG.IPC16 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC17   0x20000U      // Clear CPU1TOHSMIPCFLG.IPC17 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC18   0x40000U      // Clear CPU1TOHSMIPCFLG.IPC18 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC19   0x80000U      // Clear CPU1TOHSMIPCFLG.IPC19 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC20   0x100000U     // Clear CPU1TOHSMIPCFLG.IPC20 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC21   0x200000U     // Clear CPU1TOHSMIPCFLG.IPC21 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC22   0x400000U     // Clear CPU1TOHSMIPCFLG.IPC22 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC23   0x800000U     // Clear CPU1TOHSMIPCFLG.IPC23 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC24   0x1000000U    // Clear CPU1TOHSMIPCFLG.IPC24 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC25   0x2000000U    // Clear CPU1TOHSMIPCFLG.IPC25 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC26   0x4000000U    // Clear CPU1TOHSMIPCFLG.IPC26 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC27   0x8000000U    // Clear CPU1TOHSMIPCFLG.IPC27 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC28   0x10000000U   // Clear CPU1TOHSMIPCFLG.IPC28 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC29   0x20000000U   // Clear CPU1TOHSMIPCFLG.IPC29 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC30   0x40000000U   // Clear CPU1TOHSMIPCFLG.IPC30 Flag
#define IPC_CPU1TOHSMINTIPCCLR_IPC31   0x80000000U   // Clear CPU1TOHSMIPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOHSMINTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU1TOHSMINTIPCFLG_IPC0    0x1U          // HSM to CPU1 IPC0 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC1    0x2U          // HSM to CPU1 IPC1 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC2    0x4U          // HSM to CPU1 IPC2 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC3    0x8U          // HSM to CPU1 IPC3 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC4    0x10U         // HSM to CPU1 IPC4 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC5    0x20U         // HSM to CPU1 IPC5 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC6    0x40U         // HSM to CPU1 IPC6 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC7    0x80U         // HSM to CPU1 IPC7 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC8    0x100U        // HSM to CPU1 IPC8 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC9    0x200U        // HSM to CPU1 IPC9 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC10   0x400U        // HSM to CPU1 IPC10 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC11   0x800U        // HSM to CPU1 IPC11 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC12   0x1000U       // HSM to CPU1 IPC12 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC13   0x2000U       // HSM to CPU1 IPC13 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC14   0x4000U       // HSM to CPU1 IPC14 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC15   0x8000U       // HSM to CPU1 IPC15 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC16   0x10000U      // HSM to CPU1 IPC16 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC17   0x20000U      // HSM to CPU1 IPC17 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC18   0x40000U      // HSM to CPU1 IPC18 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC19   0x80000U      // HSM to CPU1 IPC19 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC20   0x100000U     // HSM to CPU1 IPC20 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC21   0x200000U     // HSM to CPU1 IPC21 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC22   0x400000U     // HSM to CPU1 IPC22 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC23   0x800000U     // HSM to CPU1 IPC23 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC24   0x1000000U    // HSM to CPU1 IPC24 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC25   0x2000000U    // HSM to CPU1 IPC25 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC26   0x4000000U    // HSM to CPU1 IPC26 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC27   0x8000000U    // HSM to CPU1 IPC27 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC28   0x10000000U   // HSM to CPU1 IPC28 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC29   0x20000000U   // HSM to CPU1 IPC29 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC30   0x40000000U   // HSM to CPU1 IPC30 Flag Status
#define IPC_CPU1TOHSMINTIPCFLG_IPC31   0x80000000U   // HSM to CPU1 IPC31 Flag Status


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU1INTIPCSTS register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU1INTIPCSTS_IPC0    0x1U          // Local IPC Flag 0 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC1    0x2U          // Local IPC Flag 1 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC2    0x4U          // Local IPC Flag 2 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC3    0x8U          // Local IPC Flag 3 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC4    0x10U         // Local IPC Flag 4 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC5    0x20U         // Local IPC Flag 5 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC6    0x40U         // Local IPC Flag 6 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC7    0x80U         // Local IPC Flag 7 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC8    0x100U        // Local IPC Flag 8 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC9    0x200U        // Local IPC Flag 9 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC10   0x400U        // Local IPC Flag 10 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC11   0x800U        // Local IPC Flag 11 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC12   0x1000U       // Local IPC Flag 12 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC13   0x2000U       // Local IPC Flag 13 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC14   0x4000U       // Local IPC Flag 14 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC15   0x8000U       // Local IPC Flag 15 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC16   0x10000U      // Local IPC Flag 16 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC17   0x20000U      // Local IPC Flag 17 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC18   0x40000U      // Local IPC Flag 18 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC19   0x80000U      // Local IPC Flag 19 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC20   0x100000U     // Local IPC Flag 20 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC21   0x200000U     // Local IPC Flag 21 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC22   0x400000U     // Local IPC Flag 22 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC23   0x800000U     // Local IPC Flag 23 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC24   0x1000000U    // Local IPC Flag 24 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC25   0x2000000U    // Local IPC Flag 25 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC26   0x4000000U    // Local IPC Flag 26 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC27   0x8000000U    // Local IPC Flag 27 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC28   0x10000000U   // Local IPC Flag 28 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC29   0x20000000U   // Local IPC Flag 29 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC30   0x40000000U   // Local IPC Flag 30 Status
#define IPC_CPU2TOCPU1INTIPCSTS_IPC31   0x80000000U   // Local IPC Flag 31 Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU2INTIPCACK register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU2INTIPCACK_IPC0    0x1U          // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC0 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC1    0x2U          // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC1 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC2    0x4U          // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC2 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC3    0x8U          // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC3 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC4    0x10U         // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC4 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC5    0x20U         // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC5 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC6    0x40U         // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC6 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC7    0x80U         // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC7 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC8    0x100U        // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC8 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC9    0x200U        // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC9 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC10   0x400U        // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC10 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC11   0x800U        // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC11 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC12   0x1000U       // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC12 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC13   0x2000U       // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC13 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC14   0x4000U       // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC14 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC15   0x8000U       // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC15 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC16   0x10000U      // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC16 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC17   0x20000U      // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC17 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC18   0x40000U      // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC18 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC19   0x80000U      // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC19 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC20   0x100000U     // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC20 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC21   0x200000U     // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC21 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC22   0x400000U     // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC22 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC23   0x800000U     // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC23 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC24   0x1000000U    // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC24 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC25   0x2000000U    // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC25 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC26   0x4000000U    // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC26 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC27   0x8000000U    // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC27 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC28   0x10000000U   // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC28 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC29   0x20000000U   // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC29 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC30   0x40000000U   // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC30 bit
#define IPC_CPU1TOCPU2INTIPCACK_IPC31   0x80000000U   // Acknowledgement from CPU2 to
                                                      // CPU1TOCPU2IPCFLG.IPC31 bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU1INTIPCSTS register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU1INTIPCSTS_IPC0    0x1U          // Local IPC Flag 0 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC1    0x2U          // Local IPC Flag 1 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC2    0x4U          // Local IPC Flag 2 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC3    0x8U          // Local IPC Flag 3 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC4    0x10U         // Local IPC Flag 4 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC5    0x20U         // Local IPC Flag 5 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC6    0x40U         // Local IPC Flag 6 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC7    0x80U         // Local IPC Flag 7 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC8    0x100U        // Local IPC Flag 8 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC9    0x200U        // Local IPC Flag 9 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC10   0x400U        // Local IPC Flag 10 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC11   0x800U        // Local IPC Flag 11 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC12   0x1000U       // Local IPC Flag 12 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC13   0x2000U       // Local IPC Flag 13 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC14   0x4000U       // Local IPC Flag 14 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC15   0x8000U       // Local IPC Flag 15 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC16   0x10000U      // Local IPC Flag 16 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC17   0x20000U      // Local IPC Flag 17 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC18   0x40000U      // Local IPC Flag 18 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC19   0x80000U      // Local IPC Flag 19 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC20   0x100000U     // Local IPC Flag 20 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC21   0x200000U     // Local IPC Flag 21 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC22   0x400000U     // Local IPC Flag 22 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC23   0x800000U     // Local IPC Flag 23 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC24   0x1000000U    // Local IPC Flag 24 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC25   0x2000000U    // Local IPC Flag 25 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC26   0x4000000U    // Local IPC Flag 26 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC27   0x8000000U    // Local IPC Flag 27 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC28   0x10000000U   // Local IPC Flag 28 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC29   0x20000000U   // Local IPC Flag 29 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC30   0x40000000U   // Local IPC Flag 30 Status
#define IPC_CPU3TOCPU1INTIPCSTS_IPC31   0x80000000U   // Local IPC Flag 31 Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU3INTIPCACK register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU3INTIPCACK_IPC0    0x1U          // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC0 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC1    0x2U          // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC1 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC2    0x4U          // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC2 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC3    0x8U          // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC3 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC4    0x10U         // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC4 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC5    0x20U         // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC5 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC6    0x40U         // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC6 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC7    0x80U         // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC7 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC8    0x100U        // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC8 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC9    0x200U        // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC9 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC10   0x400U        // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC10 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC11   0x800U        // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC11 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC12   0x1000U       // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC12 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC13   0x2000U       // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC13 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC14   0x4000U       // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC14 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC15   0x8000U       // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC15 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC16   0x10000U      // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC16 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC17   0x20000U      // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC17 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC18   0x40000U      // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC18 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC19   0x80000U      // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC19 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC20   0x100000U     // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC20 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC21   0x200000U     // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC21 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC22   0x400000U     // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC22 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC23   0x800000U     // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC23 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC24   0x1000000U    // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC24 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC25   0x2000000U    // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC25 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC26   0x4000000U    // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC26 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC27   0x8000000U    // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC27 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC28   0x10000000U   // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC28 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC29   0x20000000U   // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC29 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC30   0x40000000U   // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC30 bit
#define IPC_CPU1TOCPU3INTIPCACK_IPC31   0x80000000U   // Acknowledgement from CPU3 to
                                                      // CPU1TOCPU3IPCFLG.IPC31 bit


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU1INTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU1INTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU2TOCPU1INTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU1INTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU1INTIPCCLR_IPC0    0x1U          // Clear CPU2TOCPU1IPCFLG.IPC0 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC1    0x2U          // Clear CPU2TOCPU1IPCFLG.IPC1 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC2    0x4U          // Clear CPU2TOCPU1IPCFLG.IPC2 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC3    0x8U          // Clear CPU2TOCPU1IPCFLG.IPC3 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC4    0x10U         // Clear CPU2TOCPU1IPCFLG.IPC4 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC5    0x20U         // Clear CPU2TOCPU1IPCFLG.IPC5 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC6    0x40U         // Clear CPU2TOCPU1IPCFLG.IPC6 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC7    0x80U         // Clear CPU2TOCPU1IPCFLG.IPC7 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC8    0x100U        // Clear CPU2TOCPU1IPCFLG.IPC8 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC9    0x200U        // Clear CPU2TOCPU1IPCFLG.IPC9 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC10   0x400U        // Clear CPU2TOCPU1IPCFLG.IPC10 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC11   0x800U        // Clear CPU2TOCPU1IPCFLG.IPC11 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC12   0x1000U       // Clear CPU2TOCPU1IPCFLG.IPC12 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC13   0x2000U       // Clear CPU2TOCPU1IPCFLG.IPC13 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC14   0x4000U       // Clear CPU2TOCPU1IPCFLG.IPC14 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC15   0x8000U       // Clear CPU2TOCPU1IPCFLG.IPC15 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC16   0x10000U      // Clear CPU2TOCPU1IPCFLG.IPC16 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC17   0x20000U      // Clear CPU2TOCPU1IPCFLG.IPC17 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC18   0x40000U      // Clear CPU2TOCPU1IPCFLG.IPC18 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC19   0x80000U      // Clear CPU2TOCPU1IPCFLG.IPC19 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC20   0x100000U     // Clear CPU2TOCPU1IPCFLG.IPC20 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC21   0x200000U     // Clear CPU2TOCPU1IPCFLG.IPC21 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC22   0x400000U     // Clear CPU2TOCPU1IPCFLG.IPC22 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC23   0x800000U     // Clear CPU2TOCPU1IPCFLG.IPC23 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC24   0x1000000U    // Clear CPU2TOCPU1IPCFLG.IPC24 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC25   0x2000000U    // Clear CPU2TOCPU1IPCFLG.IPC25 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC26   0x4000000U    // Clear CPU2TOCPU1IPCFLG.IPC26 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC27   0x8000000U    // Clear CPU2TOCPU1IPCFLG.IPC27 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC28   0x10000000U   // Clear CPU2TOCPU1IPCFLG.IPC28 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC29   0x20000000U   // Clear CPU2TOCPU1IPCFLG.IPC29 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC30   0x40000000U   // Clear CPU2TOCPU1IPCFLG.IPC30 Flag
#define IPC_CPU2TOCPU1INTIPCCLR_IPC31   0x80000000U   // Clear CPU2TOCPU1IPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU1INTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU1INTIPCFLG_IPC0    0x1U          // CPU2 to CPU1 IPC0 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC1    0x2U          // CPU2 to CPU1 IPC1 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC2    0x4U          // CPU2 to CPU1 IPC2 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC3    0x8U          // CPU2 to CPU1 IPC3 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC4    0x10U         // CPU2 to CPU1 IPC4 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC5    0x20U         // CPU2 to CPU1 IPC5 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC6    0x40U         // CPU2 to CPU1 IPC6 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC7    0x80U         // CPU2 to CPU1 IPC7 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC8    0x100U        // CPU2 to CPU1 IPC8 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC9    0x200U        // CPU2 to CPU1 IPC9 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC10   0x400U        // CPU2 to CPU1 IPC10 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC11   0x800U        // CPU2 to CPU1 IPC11 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC12   0x1000U       // CPU2 to CPU1 IPC12 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC13   0x2000U       // CPU2 to CPU1 IPC13 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC14   0x4000U       // CPU2 to CPU1 IPC14 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC15   0x8000U       // CPU2 to CPU1 IPC15 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC16   0x10000U      // CPU2 to CPU1 IPC16 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC17   0x20000U      // CPU2 to CPU1 IPC17 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC18   0x40000U      // CPU2 to CPU1 IPC18 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC19   0x80000U      // CPU2 to CPU1 IPC19 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC20   0x100000U     // CPU2 to CPU1 IPC20 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC21   0x200000U     // CPU2 to CPU1 IPC21 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC22   0x400000U     // CPU2 to CPU1 IPC22 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC23   0x800000U     // CPU2 to CPU1 IPC23 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC24   0x1000000U    // CPU2 to CPU1 IPC24 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC25   0x2000000U    // CPU2 to CPU1 IPC25 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC26   0x4000000U    // CPU2 to CPU1 IPC26 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC27   0x8000000U    // CPU2 to CPU1 IPC27 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC28   0x10000000U   // CPU2 to CPU1 IPC28 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC29   0x20000000U   // CPU2 to CPU1 IPC29 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC30   0x40000000U   // CPU2 to CPU1 IPC30 Flag Status
#define IPC_CPU2TOCPU1INTIPCFLG_IPC31   0x80000000U   // CPU2 to CPU1 IPC31 Flag Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU3INTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU3INTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU2TOCPU3INTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU3INTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU3INTIPCCLR_IPC0    0x1U          // Clear CPU2TOCPU3IPCFLG.IPC0 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC1    0x2U          // Clear CPU2TOCPU3IPCFLG.IPC1 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC2    0x4U          // Clear CPU2TOCPU3IPCFLG.IPC2 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC3    0x8U          // Clear CPU2TOCPU3IPCFLG.IPC3 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC4    0x10U         // Clear CPU2TOCPU3IPCFLG.IPC4 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC5    0x20U         // Clear CPU2TOCPU3IPCFLG.IPC5 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC6    0x40U         // Clear CPU2TOCPU3IPCFLG.IPC6 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC7    0x80U         // Clear CPU2TOCPU3IPCFLG.IPC7 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC8    0x100U        // Clear CPU2TOCPU3IPCFLG.IPC8 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC9    0x200U        // Clear CPU2TOCPU3IPCFLG.IPC9 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC10   0x400U        // Clear CPU2TOCPU3IPCFLG.IPC10 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC11   0x800U        // Clear CPU2TOCPU3IPCFLG.IPC11 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC12   0x1000U       // Clear CPU2TOCPU3IPCFLG.IPC12 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC13   0x2000U       // Clear CPU2TOCPU3IPCFLG.IPC13 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC14   0x4000U       // Clear CPU2TOCPU3IPCFLG.IPC14 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC15   0x8000U       // Clear CPU2TOCPU3IPCFLG.IPC15 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC16   0x10000U      // Clear CPU2TOCPU3IPCFLG.IPC16 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC17   0x20000U      // Clear CPU2TOCPU3IPCFLG.IPC17 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC18   0x40000U      // Clear CPU2TOCPU3IPCFLG.IPC18 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC19   0x80000U      // Clear CPU2TOCPU3IPCFLG.IPC19 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC20   0x100000U     // Clear CPU2TOCPU3IPCFLG.IPC20 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC21   0x200000U     // Clear CPU2TOCPU3IPCFLG.IPC21 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC22   0x400000U     // Clear CPU2TOCPU3IPCFLG.IPC22 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC23   0x800000U     // Clear CPU2TOCPU3IPCFLG.IPC23 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC24   0x1000000U    // Clear CPU2TOCPU3IPCFLG.IPC24 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC25   0x2000000U    // Clear CPU2TOCPU3IPCFLG.IPC25 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC26   0x4000000U    // Clear CPU2TOCPU3IPCFLG.IPC26 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC27   0x8000000U    // Clear CPU2TOCPU3IPCFLG.IPC27 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC28   0x10000000U   // Clear CPU2TOCPU3IPCFLG.IPC28 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC29   0x20000000U   // Clear CPU2TOCPU3IPCFLG.IPC29 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC30   0x40000000U   // Clear CPU2TOCPU3IPCFLG.IPC30 Flag
#define IPC_CPU2TOCPU3INTIPCCLR_IPC31   0x80000000U   // Clear CPU2TOCPU3IPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU3INTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU3INTIPCFLG_IPC0    0x1U          // CPU2 to CPU3 IPC0 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC1    0x2U          // CPU2 to CPU3 IPC1 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC2    0x4U          // CPU2 to CPU3 IPC2 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC3    0x8U          // CPU2 to CPU3 IPC3 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC4    0x10U         // CPU2 to CPU3 IPC4 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC5    0x20U         // CPU2 to CPU3 IPC5 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC6    0x40U         // CPU2 to CPU3 IPC6 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC7    0x80U         // CPU2 to CPU3 IPC7 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC8    0x100U        // CPU2 to CPU3 IPC8 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC9    0x200U        // CPU2 to CPU3 IPC9 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC10   0x400U        // CPU2 to CPU3 IPC10 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC11   0x800U        // CPU2 to CPU3 IPC11 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC12   0x1000U       // CPU2 to CPU3 IPC12 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC13   0x2000U       // CPU2 to CPU3 IPC13 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC14   0x4000U       // CPU2 to CPU3 IPC14 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC15   0x8000U       // CPU2 to CPU3 IPC15 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC16   0x10000U      // CPU2 to CPU3 IPC16 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC17   0x20000U      // CPU2 to CPU3 IPC17 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC18   0x40000U      // CPU2 to CPU3 IPC18 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC19   0x80000U      // CPU2 to CPU3 IPC19 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC20   0x100000U     // CPU2 to CPU3 IPC20 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC21   0x200000U     // CPU2 to CPU3 IPC21 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC22   0x400000U     // CPU2 to CPU3 IPC22 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC23   0x800000U     // CPU2 to CPU3 IPC23 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC24   0x1000000U    // CPU2 to CPU3 IPC24 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC25   0x2000000U    // CPU2 to CPU3 IPC25 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC26   0x4000000U    // CPU2 to CPU3 IPC26 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC27   0x8000000U    // CPU2 to CPU3 IPC27 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC28   0x10000000U   // CPU2 to CPU3 IPC28 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC29   0x20000000U   // CPU2 to CPU3 IPC29 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC30   0x40000000U   // CPU2 to CPU3 IPC30 Flag Status
#define IPC_CPU2TOCPU3INTIPCFLG_IPC31   0x80000000U   // CPU2 to CPU3 IPC31 Flag Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOHSMINTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU2TOHSMINTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU2TOHSMINTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOHSMINTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU2TOHSMINTIPCCLR_IPC0    0x1U          // Clear CPU2TOHSMIPCFLG.IPC0 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC1    0x2U          // Clear CPU2TOHSMIPCFLG.IPC1 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC2    0x4U          // Clear CPU2TOHSMIPCFLG.IPC2 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC3    0x8U          // Clear CPU2TOHSMIPCFLG.IPC3 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC4    0x10U         // Clear CPU2TOHSMIPCFLG.IPC4 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC5    0x20U         // Clear CPU2TOHSMIPCFLG.IPC5 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC6    0x40U         // Clear CPU2TOHSMIPCFLG.IPC6 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC7    0x80U         // Clear CPU2TOHSMIPCFLG.IPC7 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC8    0x100U        // Clear CPU2TOHSMIPCFLG.IPC8 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC9    0x200U        // Clear CPU2TOHSMIPCFLG.IPC9 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC10   0x400U        // Clear CPU2TOHSMIPCFLG.IPC10 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC11   0x800U        // Clear CPU2TOHSMIPCFLG.IPC11 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC12   0x1000U       // Clear CPU2TOHSMIPCFLG.IPC12 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC13   0x2000U       // Clear CPU2TOHSMIPCFLG.IPC13 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC14   0x4000U       // Clear CPU2TOHSMIPCFLG.IPC14 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC15   0x8000U       // Clear CPU2TOHSMIPCFLG.IPC15 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC16   0x10000U      // Clear CPU2TOHSMIPCFLG.IPC16 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC17   0x20000U      // Clear CPU2TOHSMIPCFLG.IPC17 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC18   0x40000U      // Clear CPU2TOHSMIPCFLG.IPC18 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC19   0x80000U      // Clear CPU2TOHSMIPCFLG.IPC19 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC20   0x100000U     // Clear CPU2TOHSMIPCFLG.IPC20 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC21   0x200000U     // Clear CPU2TOHSMIPCFLG.IPC21 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC22   0x400000U     // Clear CPU2TOHSMIPCFLG.IPC22 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC23   0x800000U     // Clear CPU2TOHSMIPCFLG.IPC23 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC24   0x1000000U    // Clear CPU2TOHSMIPCFLG.IPC24 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC25   0x2000000U    // Clear CPU2TOHSMIPCFLG.IPC25 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC26   0x4000000U    // Clear CPU2TOHSMIPCFLG.IPC26 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC27   0x8000000U    // Clear CPU2TOHSMIPCFLG.IPC27 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC28   0x10000000U   // Clear CPU2TOHSMIPCFLG.IPC28 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC29   0x20000000U   // Clear CPU2TOHSMIPCFLG.IPC29 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC30   0x40000000U   // Clear CPU2TOHSMIPCFLG.IPC30 Flag
#define IPC_CPU2TOHSMINTIPCCLR_IPC31   0x80000000U   // Clear CPU2TOHSMIPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOHSMINTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU2TOHSMINTIPCFLG_IPC0    0x1U          // HSM to CPU2 IPC0 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC1    0x2U          // HSM to CPU2 IPC1 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC2    0x4U          // HSM to CPU2 IPC2 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC3    0x8U          // HSM to CPU2 IPC3 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC4    0x10U         // HSM to CPU2 IPC4 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC5    0x20U         // HSM to CPU2 IPC5 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC6    0x40U         // HSM to CPU2 IPC6 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC7    0x80U         // HSM to CPU2 IPC7 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC8    0x100U        // HSM to CPU2 IPC8 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC9    0x200U        // HSM to CPU2 IPC9 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC10   0x400U        // HSM to CPU2 IPC10 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC11   0x800U        // HSM to CPU2 IPC11 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC12   0x1000U       // HSM to CPU2 IPC12 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC13   0x2000U       // HSM to CPU2 IPC13 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC14   0x4000U       // HSM to CPU2 IPC14 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC15   0x8000U       // HSM to CPU2 IPC15 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC16   0x10000U      // HSM to CPU2 IPC16 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC17   0x20000U      // HSM to CPU2 IPC17 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC18   0x40000U      // HSM to CPU2 IPC18 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC19   0x80000U      // HSM to CPU2 IPC19 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC20   0x100000U     // HSM to CPU2 IPC20 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC21   0x200000U     // HSM to CPU2 IPC21 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC22   0x400000U     // HSM to CPU2 IPC22 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC23   0x800000U     // HSM to CPU2 IPC23 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC24   0x1000000U    // HSM to CPU2 IPC24 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC25   0x2000000U    // HSM to CPU2 IPC25 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC26   0x4000000U    // HSM to CPU2 IPC26 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC27   0x8000000U    // HSM to CPU2 IPC27 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC28   0x10000000U   // HSM to CPU2 IPC28 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC29   0x20000000U   // HSM to CPU2 IPC29 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC30   0x40000000U   // HSM to CPU2 IPC30 Flag Status
#define IPC_CPU2TOHSMINTIPCFLG_IPC31   0x80000000U   // HSM to CPU2 IPC31 Flag Status


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU2INTIPCSTS register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU2INTIPCSTS_IPC0    0x1U          // Local IPC Flag 0 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC1    0x2U          // Local IPC Flag 1 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC2    0x4U          // Local IPC Flag 2 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC3    0x8U          // Local IPC Flag 3 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC4    0x10U         // Local IPC Flag 4 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC5    0x20U         // Local IPC Flag 5 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC6    0x40U         // Local IPC Flag 6 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC7    0x80U         // Local IPC Flag 7 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC8    0x100U        // Local IPC Flag 8 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC9    0x200U        // Local IPC Flag 9 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC10   0x400U        // Local IPC Flag 10 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC11   0x800U        // Local IPC Flag 11 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC12   0x1000U       // Local IPC Flag 12 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC13   0x2000U       // Local IPC Flag 13 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC14   0x4000U       // Local IPC Flag 14 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC15   0x8000U       // Local IPC Flag 15 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC16   0x10000U      // Local IPC Flag 16 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC17   0x20000U      // Local IPC Flag 17 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC18   0x40000U      // Local IPC Flag 18 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC19   0x80000U      // Local IPC Flag 19 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC20   0x100000U     // Local IPC Flag 20 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC21   0x200000U     // Local IPC Flag 21 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC22   0x400000U     // Local IPC Flag 22 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC23   0x800000U     // Local IPC Flag 23 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC24   0x1000000U    // Local IPC Flag 24 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC25   0x2000000U    // Local IPC Flag 25 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC26   0x4000000U    // Local IPC Flag 26 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC27   0x8000000U    // Local IPC Flag 27 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC28   0x10000000U   // Local IPC Flag 28 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC29   0x20000000U   // Local IPC Flag 29 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC30   0x40000000U   // Local IPC Flag 30 Status
#define IPC_CPU1TOCPU2INTIPCSTS_IPC31   0x80000000U   // Local IPC Flag 31 Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU1INTIPCACK register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU1INTIPCACK_IPC0    0x1U          // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC0 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC1    0x2U          // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC1 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC2    0x4U          // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC2 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC3    0x8U          // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC3 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC4    0x10U         // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC4 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC5    0x20U         // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC5 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC6    0x40U         // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC6 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC7    0x80U         // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC7 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC8    0x100U        // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC8 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC9    0x200U        // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC9 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC10   0x400U        // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC10 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC11   0x800U        // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC11 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC12   0x1000U       // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC12 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC13   0x2000U       // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC13 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC14   0x4000U       // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC14 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC15   0x8000U       // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC15 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC16   0x10000U      // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC16 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC17   0x20000U      // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC17 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC18   0x40000U      // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC18 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC19   0x80000U      // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC19 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC20   0x100000U     // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC20 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC21   0x200000U     // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC21 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC22   0x400000U     // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC22 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC23   0x800000U     // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC23 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC24   0x1000000U    // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC24 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC25   0x2000000U    // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC25 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC26   0x4000000U    // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC26 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC27   0x8000000U    // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC27 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC28   0x10000000U   // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC28 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC29   0x20000000U   // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC29 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC30   0x40000000U   // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC30 bit
#define IPC_CPU2TOCPU1INTIPCACK_IPC31   0x80000000U   // Acknowledgement from CPU1 to
                                                      // CPU2TOCPU1IPCFLG.IPC31 bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU2INTIPCSTS register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU2INTIPCSTS_IPC0    0x1U          // Local IPC Flag 0 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC1    0x2U          // Local IPC Flag 1 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC2    0x4U          // Local IPC Flag 2 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC3    0x8U          // Local IPC Flag 3 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC4    0x10U         // Local IPC Flag 4 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC5    0x20U         // Local IPC Flag 5 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC6    0x40U         // Local IPC Flag 6 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC7    0x80U         // Local IPC Flag 7 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC8    0x100U        // Local IPC Flag 8 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC9    0x200U        // Local IPC Flag 9 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC10   0x400U        // Local IPC Flag 10 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC11   0x800U        // Local IPC Flag 11 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC12   0x1000U       // Local IPC Flag 12 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC13   0x2000U       // Local IPC Flag 13 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC14   0x4000U       // Local IPC Flag 14 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC15   0x8000U       // Local IPC Flag 15 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC16   0x10000U      // Local IPC Flag 16 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC17   0x20000U      // Local IPC Flag 17 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC18   0x40000U      // Local IPC Flag 18 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC19   0x80000U      // Local IPC Flag 19 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC20   0x100000U     // Local IPC Flag 20 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC21   0x200000U     // Local IPC Flag 21 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC22   0x400000U     // Local IPC Flag 22 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC23   0x800000U     // Local IPC Flag 23 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC24   0x1000000U    // Local IPC Flag 24 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC25   0x2000000U    // Local IPC Flag 25 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC26   0x4000000U    // Local IPC Flag 26 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC27   0x8000000U    // Local IPC Flag 27 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC28   0x10000000U   // Local IPC Flag 28 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC29   0x20000000U   // Local IPC Flag 29 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC30   0x40000000U   // Local IPC Flag 30 Status
#define IPC_CPU3TOCPU2INTIPCSTS_IPC31   0x80000000U   // Local IPC Flag 31 Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU3INTIPCACK register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU3INTIPCACK_IPC0    0x1U          // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC0 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC1    0x2U          // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC1 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC2    0x4U          // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC2 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC3    0x8U          // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC3 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC4    0x10U         // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC4 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC5    0x20U         // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC5 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC6    0x40U         // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC6 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC7    0x80U         // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC7 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC8    0x100U        // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC8 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC9    0x200U        // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC9 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC10   0x400U        // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC10 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC11   0x800U        // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC11 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC12   0x1000U       // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC12 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC13   0x2000U       // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC13 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC14   0x4000U       // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC14 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC15   0x8000U       // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC15 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC16   0x10000U      // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC16 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC17   0x20000U      // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC17 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC18   0x40000U      // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC18 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC19   0x80000U      // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC19 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC20   0x100000U     // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC20 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC21   0x200000U     // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC21 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC22   0x400000U     // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC22 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC23   0x800000U     // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC23 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC24   0x1000000U    // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC24 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC25   0x2000000U    // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC25 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC26   0x4000000U    // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC26 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC27   0x8000000U    // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC27 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC28   0x10000000U   // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC28 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC29   0x20000000U   // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC29 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC30   0x40000000U   // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC30 bit
#define IPC_CPU2TOCPU3INTIPCACK_IPC31   0x80000000U   // Acknowledgement from CPU3 to
                                                      // CPU2TOCPU3IPCFLG.IPC31 bit


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU1INTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU1INTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU3TOCPU1INTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU1INTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU1INTIPCCLR_IPC0    0x1U          // Clear CPU3TOCPU1IPCFLG.IPC0 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC1    0x2U          // Clear CPU3TOCPU1IPCFLG.IPC1 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC2    0x4U          // Clear CPU3TOCPU1IPCFLG.IPC2 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC3    0x8U          // Clear CPU3TOCPU1IPCFLG.IPC3 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC4    0x10U         // Clear CPU3TOCPU1IPCFLG.IPC4 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC5    0x20U         // Clear CPU3TOCPU1IPCFLG.IPC5 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC6    0x40U         // Clear CPU3TOCPU1IPCFLG.IPC6 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC7    0x80U         // Clear CPU3TOCPU1IPCFLG.IPC7 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC8    0x100U        // Clear CPU3TOCPU1IPCFLG.IPC8 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC9    0x200U        // Clear CPU3TOCPU1IPCFLG.IPC9 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC10   0x400U        // Clear CPU3TOCPU1IPCFLG.IPC10 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC11   0x800U        // Clear CPU3TOCPU1IPCFLG.IPC11 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC12   0x1000U       // Clear CPU3TOCPU1IPCFLG.IPC12 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC13   0x2000U       // Clear CPU3TOCPU1IPCFLG.IPC13 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC14   0x4000U       // Clear CPU3TOCPU1IPCFLG.IPC14 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC15   0x8000U       // Clear CPU3TOCPU1IPCFLG.IPC15 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC16   0x10000U      // Clear CPU3TOCPU1IPCFLG.IPC16 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC17   0x20000U      // Clear CPU3TOCPU1IPCFLG.IPC17 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC18   0x40000U      // Clear CPU3TOCPU1IPCFLG.IPC18 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC19   0x80000U      // Clear CPU3TOCPU1IPCFLG.IPC19 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC20   0x100000U     // Clear CPU3TOCPU1IPCFLG.IPC20 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC21   0x200000U     // Clear CPU3TOCPU1IPCFLG.IPC21 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC22   0x400000U     // Clear CPU3TOCPU1IPCFLG.IPC22 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC23   0x800000U     // Clear CPU3TOCPU1IPCFLG.IPC23 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC24   0x1000000U    // Clear CPU3TOCPU1IPCFLG.IPC24 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC25   0x2000000U    // Clear CPU3TOCPU1IPCFLG.IPC25 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC26   0x4000000U    // Clear CPU3TOCPU1IPCFLG.IPC26 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC27   0x8000000U    // Clear CPU3TOCPU1IPCFLG.IPC27 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC28   0x10000000U   // Clear CPU3TOCPU1IPCFLG.IPC28 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC29   0x20000000U   // Clear CPU3TOCPU1IPCFLG.IPC29 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC30   0x40000000U   // Clear CPU3TOCPU1IPCFLG.IPC30 Flag
#define IPC_CPU3TOCPU1INTIPCCLR_IPC31   0x80000000U   // Clear CPU3TOCPU1IPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU1INTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU1INTIPCFLG_IPC0    0x1U          // CPU3 to CPU1 IPC0 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC1    0x2U          // CPU3 to CPU1 IPC1 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC2    0x4U          // CPU3 to CPU1 IPC2 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC3    0x8U          // CPU3 to CPU1 IPC3 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC4    0x10U         // CPU3 to CPU1 IPC4 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC5    0x20U         // CPU3 to CPU1 IPC5 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC6    0x40U         // CPU3 to CPU1 IPC6 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC7    0x80U         // CPU3 to CPU1 IPC7 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC8    0x100U        // CPU3 to CPU1 IPC8 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC9    0x200U        // CPU3 to CPU1 IPC9 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC10   0x400U        // CPU3 to CPU1 IPC10 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC11   0x800U        // CPU3 to CPU1 IPC11 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC12   0x1000U       // CPU3 to CPU1 IPC12 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC13   0x2000U       // CPU3 to CPU1 IPC13 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC14   0x4000U       // CPU3 to CPU1 IPC14 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC15   0x8000U       // CPU3 to CPU1 IPC15 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC16   0x10000U      // CPU3 to CPU1 IPC16 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC17   0x20000U      // CPU3 to CPU1 IPC17 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC18   0x40000U      // CPU3 to CPU1 IPC18 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC19   0x80000U      // CPU3 to CPU1 IPC19 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC20   0x100000U     // CPU3 to CPU1 IPC20 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC21   0x200000U     // CPU3 to CPU1 IPC21 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC22   0x400000U     // CPU3 to CPU1 IPC22 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC23   0x800000U     // CPU3 to CPU1 IPC23 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC24   0x1000000U    // CPU3 to CPU1 IPC24 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC25   0x2000000U    // CPU3 to CPU1 IPC25 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC26   0x4000000U    // CPU3 to CPU1 IPC26 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC27   0x8000000U    // CPU3 to CPU1 IPC27 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC28   0x10000000U   // CPU3 to CPU1 IPC28 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC29   0x20000000U   // CPU3 to CPU1 IPC29 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC30   0x40000000U   // CPU3 to CPU1 IPC30 Flag Status
#define IPC_CPU3TOCPU1INTIPCFLG_IPC31   0x80000000U   // CPU3 to CPU1 IPC31 Flag Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU2INTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU2INTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU3TOCPU2INTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU2INTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU2INTIPCCLR_IPC0    0x1U          // Clear CPU3TOCPU2IPCFLG.IPC0 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC1    0x2U          // Clear CPU3TOCPU2IPCFLG.IPC1 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC2    0x4U          // Clear CPU3TOCPU2IPCFLG.IPC2 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC3    0x8U          // Clear CPU3TOCPU2IPCFLG.IPC3 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC4    0x10U         // Clear CPU3TOCPU2IPCFLG.IPC4 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC5    0x20U         // Clear CPU3TOCPU2IPCFLG.IPC5 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC6    0x40U         // Clear CPU3TOCPU2IPCFLG.IPC6 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC7    0x80U         // Clear CPU3TOCPU2IPCFLG.IPC7 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC8    0x100U        // Clear CPU3TOCPU2IPCFLG.IPC8 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC9    0x200U        // Clear CPU3TOCPU2IPCFLG.IPC9 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC10   0x400U        // Clear CPU3TOCPU2IPCFLG.IPC10 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC11   0x800U        // Clear CPU3TOCPU2IPCFLG.IPC11 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC12   0x1000U       // Clear CPU3TOCPU2IPCFLG.IPC12 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC13   0x2000U       // Clear CPU3TOCPU2IPCFLG.IPC13 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC14   0x4000U       // Clear CPU3TOCPU2IPCFLG.IPC14 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC15   0x8000U       // Clear CPU3TOCPU2IPCFLG.IPC15 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC16   0x10000U      // Clear CPU3TOCPU2IPCFLG.IPC16 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC17   0x20000U      // Clear CPU3TOCPU2IPCFLG.IPC17 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC18   0x40000U      // Clear CPU3TOCPU2IPCFLG.IPC18 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC19   0x80000U      // Clear CPU3TOCPU2IPCFLG.IPC19 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC20   0x100000U     // Clear CPU3TOCPU2IPCFLG.IPC20 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC21   0x200000U     // Clear CPU3TOCPU2IPCFLG.IPC21 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC22   0x400000U     // Clear CPU3TOCPU2IPCFLG.IPC22 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC23   0x800000U     // Clear CPU3TOCPU2IPCFLG.IPC23 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC24   0x1000000U    // Clear CPU3TOCPU2IPCFLG.IPC24 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC25   0x2000000U    // Clear CPU3TOCPU2IPCFLG.IPC25 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC26   0x4000000U    // Clear CPU3TOCPU2IPCFLG.IPC26 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC27   0x8000000U    // Clear CPU3TOCPU2IPCFLG.IPC27 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC28   0x10000000U   // Clear CPU3TOCPU2IPCFLG.IPC28 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC29   0x20000000U   // Clear CPU3TOCPU2IPCFLG.IPC29 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC30   0x40000000U   // Clear CPU3TOCPU2IPCFLG.IPC30 Flag
#define IPC_CPU3TOCPU2INTIPCCLR_IPC31   0x80000000U   // Clear CPU3TOCPU2IPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU2INTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU2INTIPCFLG_IPC0    0x1U          // CPU3 to CPU2 IPC0 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC1    0x2U          // CPU3 to CPU2 IPC1 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC2    0x4U          // CPU3 to CPU2 IPC2 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC3    0x8U          // CPU3 to CPU2 IPC3 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC4    0x10U         // CPU3 to CPU2 IPC4 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC5    0x20U         // CPU3 to CPU2 IPC5 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC6    0x40U         // CPU3 to CPU2 IPC6 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC7    0x80U         // CPU3 to CPU2 IPC7 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC8    0x100U        // CPU3 to CPU2 IPC8 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC9    0x200U        // CPU3 to CPU2 IPC9 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC10   0x400U        // CPU3 to CPU2 IPC10 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC11   0x800U        // CPU3 to CPU2 IPC11 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC12   0x1000U       // CPU3 to CPU2 IPC12 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC13   0x2000U       // CPU3 to CPU2 IPC13 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC14   0x4000U       // CPU3 to CPU2 IPC14 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC15   0x8000U       // CPU3 to CPU2 IPC15 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC16   0x10000U      // CPU3 to CPU2 IPC16 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC17   0x20000U      // CPU3 to CPU2 IPC17 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC18   0x40000U      // CPU3 to CPU2 IPC18 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC19   0x80000U      // CPU3 to CPU2 IPC19 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC20   0x100000U     // CPU3 to CPU2 IPC20 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC21   0x200000U     // CPU3 to CPU2 IPC21 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC22   0x400000U     // CPU3 to CPU2 IPC22 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC23   0x800000U     // CPU3 to CPU2 IPC23 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC24   0x1000000U    // CPU3 to CPU2 IPC24 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC25   0x2000000U    // CPU3 to CPU2 IPC25 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC26   0x4000000U    // CPU3 to CPU2 IPC26 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC27   0x8000000U    // CPU3 to CPU2 IPC27 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC28   0x10000000U   // CPU3 to CPU2 IPC28 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC29   0x20000000U   // CPU3 to CPU2 IPC29 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC30   0x40000000U   // CPU3 to CPU2 IPC30 Flag Status
#define IPC_CPU3TOCPU2INTIPCFLG_IPC31   0x80000000U   // CPU3 to CPU2 IPC31 Flag Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOHSMINTIPCSET register
//
//*************************************************************************************************
#define IPC_CPU3TOHSMINTIPCSET_IPC0    0x1U          // Set Remote IPC0 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC1    0x2U          // Set Remote IPC1 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC2    0x4U          // Set Remote IPC2 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC3    0x8U          // Set Remote IPC3 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC4    0x10U         // Set Remote IPC4 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC5    0x20U         // Set Remote IPC5 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC6    0x40U         // Set Remote IPC6 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC7    0x80U         // Set Remote IPC7 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC8    0x100U        // Set Remote IPC8 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC9    0x200U        // Set Remote IPC9 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC10   0x400U        // Set Remote IPC10 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC11   0x800U        // Set Remote IPC11 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC12   0x1000U       // Set Remote IPC12 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC13   0x2000U       // Set Remote IPC13 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC14   0x4000U       // Set Remote IPC14 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC15   0x8000U       // Set Remote IPC15 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC16   0x10000U      // Set Remote IPC16 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC17   0x20000U      // Set Remote IPC17 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC18   0x40000U      // Set Remote IPC18 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC19   0x80000U      // Set Remote IPC19 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC20   0x100000U     // Set Remote IPC20 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC21   0x200000U     // Set Remote IPC21 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC22   0x400000U     // Set Remote IPC22 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC23   0x800000U     // Set Remote IPC23 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC24   0x1000000U    // Set Remote IPC24 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC25   0x2000000U    // Set Remote IPC25 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC26   0x4000000U    // Set Remote IPC26 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC27   0x8000000U    // Set Remote IPC27 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC28   0x10000000U   // Set Remote IPC28 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC29   0x20000000U   // Set Remote IPC29 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC30   0x40000000U   // Set Remote IPC30 Flag
#define IPC_CPU3TOHSMINTIPCSET_IPC31   0x80000000U   // Set Remote IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOHSMINTIPCCLR register
//
//*************************************************************************************************
#define IPC_CPU3TOHSMINTIPCCLR_IPC0    0x1U          // Clear CPU3TOHSMIPCFLG.IPC0 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC1    0x2U          // Clear CPU3TOHSMIPCFLG.IPC1 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC2    0x4U          // Clear CPU3TOHSMIPCFLG.IPC2 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC3    0x8U          // Clear CPU3TOHSMIPCFLG.IPC3 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC4    0x10U         // Clear CPU3TOHSMIPCFLG.IPC4 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC5    0x20U         // Clear CPU3TOHSMIPCFLG.IPC5 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC6    0x40U         // Clear CPU3TOHSMIPCFLG.IPC6 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC7    0x80U         // Clear CPU3TOHSMIPCFLG.IPC7 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC8    0x100U        // Clear CPU3TOHSMIPCFLG.IPC8 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC9    0x200U        // Clear CPU3TOHSMIPCFLG.IPC9 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC10   0x400U        // Clear CPU3TOHSMIPCFLG.IPC10 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC11   0x800U        // Clear CPU3TOHSMIPCFLG.IPC11 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC12   0x1000U       // Clear CPU3TOHSMIPCFLG.IPC12 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC13   0x2000U       // Clear CPU3TOHSMIPCFLG.IPC13 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC14   0x4000U       // Clear CPU3TOHSMIPCFLG.IPC14 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC15   0x8000U       // Clear CPU3TOHSMIPCFLG.IPC15 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC16   0x10000U      // Clear CPU3TOHSMIPCFLG.IPC16 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC17   0x20000U      // Clear CPU3TOHSMIPCFLG.IPC17 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC18   0x40000U      // Clear CPU3TOHSMIPCFLG.IPC18 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC19   0x80000U      // Clear CPU3TOHSMIPCFLG.IPC19 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC20   0x100000U     // Clear CPU3TOHSMIPCFLG.IPC20 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC21   0x200000U     // Clear CPU3TOHSMIPCFLG.IPC21 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC22   0x400000U     // Clear CPU3TOHSMIPCFLG.IPC22 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC23   0x800000U     // Clear CPU3TOHSMIPCFLG.IPC23 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC24   0x1000000U    // Clear CPU3TOHSMIPCFLG.IPC24 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC25   0x2000000U    // Clear CPU3TOHSMIPCFLG.IPC25 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC26   0x4000000U    // Clear CPU3TOHSMIPCFLG.IPC26 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC27   0x8000000U    // Clear CPU3TOHSMIPCFLG.IPC27 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC28   0x10000000U   // Clear CPU3TOHSMIPCFLG.IPC28 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC29   0x20000000U   // Clear CPU3TOHSMIPCFLG.IPC29 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC30   0x40000000U   // Clear CPU3TOHSMIPCFLG.IPC30 Flag
#define IPC_CPU3TOHSMINTIPCCLR_IPC31   0x80000000U   // Clear CPU3TOHSMIPCFLG.IPC31 Flag

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOHSMINTIPCFLG register
//
//*************************************************************************************************
#define IPC_CPU3TOHSMINTIPCFLG_IPC0    0x1U          // HSM to CPU3 IPC0 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC1    0x2U          // HSM to CPU3 IPC1 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC2    0x4U          // HSM to CPU3 IPC2 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC3    0x8U          // HSM to CPU3 IPC3 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC4    0x10U         // HSM to CPU3 IPC4 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC5    0x20U         // HSM to CPU3 IPC5 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC6    0x40U         // HSM to CPU3 IPC6 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC7    0x80U         // HSM to CPU3 IPC7 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC8    0x100U        // HSM to CPU3 IPC8 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC9    0x200U        // HSM to CPU3 IPC9 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC10   0x400U        // HSM to CPU3 IPC10 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC11   0x800U        // HSM to CPU3 IPC11 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC12   0x1000U       // HSM to CPU3 IPC12 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC13   0x2000U       // HSM to CPU3 IPC13 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC14   0x4000U       // HSM to CPU3 IPC14 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC15   0x8000U       // HSM to CPU3 IPC15 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC16   0x10000U      // HSM to CPU3 IPC16 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC17   0x20000U      // HSM to CPU3 IPC17 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC18   0x40000U      // HSM to CPU3 IPC18 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC19   0x80000U      // HSM to CPU3 IPC19 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC20   0x100000U     // HSM to CPU3 IPC20 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC21   0x200000U     // HSM to CPU3 IPC21 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC22   0x400000U     // HSM to CPU3 IPC22 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC23   0x800000U     // HSM to CPU3 IPC23 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC24   0x1000000U    // HSM to CPU3 IPC24 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC25   0x2000000U    // HSM to CPU3 IPC25 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC26   0x4000000U    // HSM to CPU3 IPC26 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC27   0x8000000U    // HSM to CPU3 IPC27 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC28   0x10000000U   // HSM to CPU3 IPC28 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC29   0x20000000U   // HSM to CPU3 IPC29 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC30   0x40000000U   // HSM to CPU3 IPC30 Flag Status
#define IPC_CPU3TOHSMINTIPCFLG_IPC31   0x80000000U   // HSM to CPU3 IPC31 Flag Status


//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU1TOCPU3INTIPCSTS register
//
//*************************************************************************************************
#define IPC_CPU1TOCPU3INTIPCSTS_IPC0    0x1U          // Local IPC Flag 0 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC1    0x2U          // Local IPC Flag 1 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC2    0x4U          // Local IPC Flag 2 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC3    0x8U          // Local IPC Flag 3 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC4    0x10U         // Local IPC Flag 4 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC5    0x20U         // Local IPC Flag 5 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC6    0x40U         // Local IPC Flag 6 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC7    0x80U         // Local IPC Flag 7 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC8    0x100U        // Local IPC Flag 8 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC9    0x200U        // Local IPC Flag 9 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC10   0x400U        // Local IPC Flag 10 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC11   0x800U        // Local IPC Flag 11 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC12   0x1000U       // Local IPC Flag 12 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC13   0x2000U       // Local IPC Flag 13 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC14   0x4000U       // Local IPC Flag 14 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC15   0x8000U       // Local IPC Flag 15 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC16   0x10000U      // Local IPC Flag 16 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC17   0x20000U      // Local IPC Flag 17 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC18   0x40000U      // Local IPC Flag 18 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC19   0x80000U      // Local IPC Flag 19 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC20   0x100000U     // Local IPC Flag 20 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC21   0x200000U     // Local IPC Flag 21 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC22   0x400000U     // Local IPC Flag 22 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC23   0x800000U     // Local IPC Flag 23 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC24   0x1000000U    // Local IPC Flag 24 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC25   0x2000000U    // Local IPC Flag 25 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC26   0x4000000U    // Local IPC Flag 26 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC27   0x8000000U    // Local IPC Flag 27 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC28   0x10000000U   // Local IPC Flag 28 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC29   0x20000000U   // Local IPC Flag 29 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC30   0x40000000U   // Local IPC Flag 30 Status
#define IPC_CPU1TOCPU3INTIPCSTS_IPC31   0x80000000U   // Local IPC Flag 31 Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU1INTIPCACK register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU1INTIPCACK_IPC0    0x1U          // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC0 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC1    0x2U          // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC1 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC2    0x4U          // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC2 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC3    0x8U          // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC3 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC4    0x10U         // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC4 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC5    0x20U         // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC5 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC6    0x40U         // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC6 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC7    0x80U         // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC7 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC8    0x100U        // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC8 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC9    0x200U        // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC9 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC10   0x400U        // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC10 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC11   0x800U        // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC11 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC12   0x1000U       // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC12 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC13   0x2000U       // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC13 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC14   0x4000U       // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC14 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC15   0x8000U       // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC15 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC16   0x10000U      // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC16 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC17   0x20000U      // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC17 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC18   0x40000U      // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC18 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC19   0x80000U      // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC19 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC20   0x100000U     // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC20 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC21   0x200000U     // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC21 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC22   0x400000U     // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC22 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC23   0x800000U     // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC23 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC24   0x1000000U    // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC24 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC25   0x2000000U    // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC25 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC26   0x4000000U    // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC26 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC27   0x8000000U    // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC27 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC28   0x10000000U   // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC28 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC29   0x20000000U   // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC29 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC30   0x40000000U   // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC30 bit
#define IPC_CPU3TOCPU1INTIPCACK_IPC31   0x80000000U   // Acknowledgement from CPU1 to
                                                      // CPU3TOCPU1IPCFLG.IPC31 bit

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU2TOCPU3INTIPCSTS register
//
//*************************************************************************************************
#define IPC_CPU2TOCPU3INTIPCSTS_IPC0    0x1U          // Local IPC Flag 0 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC1    0x2U          // Local IPC Flag 1 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC2    0x4U          // Local IPC Flag 2 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC3    0x8U          // Local IPC Flag 3 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC4    0x10U         // Local IPC Flag 4 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC5    0x20U         // Local IPC Flag 5 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC6    0x40U         // Local IPC Flag 6 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC7    0x80U         // Local IPC Flag 7 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC8    0x100U        // Local IPC Flag 8 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC9    0x200U        // Local IPC Flag 9 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC10   0x400U        // Local IPC Flag 10 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC11   0x800U        // Local IPC Flag 11 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC12   0x1000U       // Local IPC Flag 12 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC13   0x2000U       // Local IPC Flag 13 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC14   0x4000U       // Local IPC Flag 14 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC15   0x8000U       // Local IPC Flag 15 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC16   0x10000U      // Local IPC Flag 16 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC17   0x20000U      // Local IPC Flag 17 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC18   0x40000U      // Local IPC Flag 18 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC19   0x80000U      // Local IPC Flag 19 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC20   0x100000U     // Local IPC Flag 20 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC21   0x200000U     // Local IPC Flag 21 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC22   0x400000U     // Local IPC Flag 22 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC23   0x800000U     // Local IPC Flag 23 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC24   0x1000000U    // Local IPC Flag 24 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC25   0x2000000U    // Local IPC Flag 25 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC26   0x4000000U    // Local IPC Flag 26 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC27   0x8000000U    // Local IPC Flag 27 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC28   0x10000000U   // Local IPC Flag 28 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC29   0x20000000U   // Local IPC Flag 29 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC30   0x40000000U   // Local IPC Flag 30 Status
#define IPC_CPU2TOCPU3INTIPCSTS_IPC31   0x80000000U   // Local IPC Flag 31 Status

//*************************************************************************************************
//
// The following are defines for the bit fields in the CPU3TOCPU2INTIPCACK register
//
//*************************************************************************************************
#define IPC_CPU3TOCPU2INTIPCACK_IPC0    0x1U          // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC0 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC1    0x2U          // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC1 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC2    0x4U          // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC2 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC3    0x8U          // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC3 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC4    0x10U         // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC4 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC5    0x20U         // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC5 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC6    0x40U         // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC6 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC7    0x80U         // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC7 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC8    0x100U        // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC8 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC9    0x200U        // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC9 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC10   0x400U        // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC10 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC11   0x800U        // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC11 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC12   0x1000U       // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC12 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC13   0x2000U       // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC13 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC14   0x4000U       // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC14 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC15   0x8000U       // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC15 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC16   0x10000U      // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC16 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC17   0x20000U      // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC17 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC18   0x40000U      // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC18 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC19   0x80000U      // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC19 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC20   0x100000U     // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC20 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC21   0x200000U     // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC21 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC22   0x400000U     // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC22 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC23   0x800000U     // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC23 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC24   0x1000000U    // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC24 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC25   0x2000000U    // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC25 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC26   0x4000000U    // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC26 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC27   0x8000000U    // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC27 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC28   0x10000000U   // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC28 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC29   0x20000000U   // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC29 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC30   0x40000000U   // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC30 bit
#define IPC_CPU3TOCPU2INTIPCACK_IPC31   0x80000000U   // Acknowledgement from CPU2 to
                                                      // CPU3TOCPU2IPCFLG.IPC31 bit



#endif
