/*********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *   TEXAS INSTRUMENTS TEXT FILE LICENSE
 *
 *   Copyright (c) 2025 Texas Instruments Incorporated
 *
 *   All rights reserved not granted herein.
 *
 *   Limited License.
 *
 *   Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 *   license under copyrights and patents it now or hereafter owns or controls to
 *   make, have made, use, import, offer to sell and sell ("Utilize") this software
 *   subject to the terms herein. With respect to the foregoing patent license,
 *   such license is granted solely to the extent that any such patent is necessary
 *   to Utilize the software alone. The patent license shall not apply to any
 *   combinations which include this software, other than combinations with devices
 *   manufactured by or for TI ("TI Devices"). No hardware patent is licensed hereunder.
 *
 *   Redistributions must preserve existing copyright notices and reproduce this license
 *   (including the above copyright notice and the disclaimer and (if applicable) source
 *   code license limitations below) in the documentation and/or other materials provided
 *   with the distribution.
 *
 *   Redistribution and use in binary form, without modification, are permitted provided
 *   that the following conditions are met:
 *
 *   * No reverse engineering, decompilation, or disassembly of this software is
 *     permitted with respect to any software provided in binary form.
 *   * Any redistribution and use are licensed by TI for use only with TI Devices.
 *   * Nothing shall obligate TI to provide you with source code for the software
 *     licensed and provided to you in object code.
 *
 *   If software source code is provided to you, modification and redistribution of the
 *   source code are permitted provided that the following conditions are met:
 *
 *   * Any redistribution and use of the source code, including any resulting derivative
 *     works, are licensed by TI for use only with TI Devices.
 *   * Any redistribution and use of any object code compiled from the source code
 *     and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 *   Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 *   DISCLAIMER.
 *
 *   THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 *   AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
 *   LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *   EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------
 *  File:       Spi_Utils.h
 *  Generator:  None
 *
 *  Description:  SPI utility functions header file
 *  This file declares the functions required to create, add and remove nodes.
 *
 *********************************************************************************************************************/
#ifndef SPI_UTILS_H_
#define SPI_UTILS_H_
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
#include "Std_Types.h"

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

/**< \brief Typedef for Node structure. */
typedef struct Spi_UtilsNode_t Spi_UtilsNode;

/**
 *  struct Spi_UtilsParams
 *  \brief Structure for storing node info.
 */
typedef struct
{
    void  *data;
    /**< Node data pointer pointer */
    uint32 priority;
    /**< Priority of the node. Used for priority based linked list. Priority is
     *   in ascending order of the value. So 0 is the lowest priority and is
     *   added to the bottom of the node.Nodes with the same priority are always
     *   added to the bottom of the existing nodes with same priority. for
     *   non-priority based modes, this parameter is ignored and could be set
     *   to 0. */
    uint8  seqId;
    /**< Sequence ID to which the job belongs. */
    uint8  seqInterruptible;
    /**< Flag indicating whether the sequence to which this job belongs is
     *   interruptible or not. */
} Spi_UtilsParams;

/**
 *  struct Spi_UtilsNode_t
 *  \brief Self referential structure for double link list.
 */
struct Spi_UtilsNode_t
{
    Spi_UtilsNode  *next;
    /**< Pointer to the next node. */
    Spi_UtilsNode  *prev;
    /**< Pointer to the previous node. */
    Spi_UtilsParams params;
    /**< Node info structure. */
};

/**
 *  struct Spi_UtilsLinkListObj
 *  \brief Structure to the link list object information.
 */
typedef struct
{
    Spi_UtilsNode *headNode;
    /**< Head node reference pointer */
    Spi_UtilsNode *tailNode;
    /**< Tail node reference pointer */
} Spi_UtilsLinkListObj;

/*********************************************************************************************************************
 * Exported Object Declarations
 *********************************************************************************************************************/

/*********************************************************************************************************************
 *  Exported Function Prototypes
 *********************************************************************************************************************/

/** \brief function to Initialize linked list
 *
 *  function to Initialize linked list
 *
 * \param[inout] llobj: pointer to linklist Object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
void Spi_UtilsInitLinkList(Spi_UtilsLinkListObj *llobj);

/** \brief function to De-Initialize linked list
 *
 *  function to De-Initialize linked list
 *
 * \param[inout] llobj: pointer to linklist Object
 * \pre None
 * \post None
 * \return None
 * \retval None
 *
 ********************************************************************************************************************/
void Spi_UtilsDeInitLinkList(Spi_UtilsLinkListObj *llobj);

/**
 *  \brief Links a node to the linked list.
 *  The memory to the node object should be allocated by the caller. This
 *  is used for link list with priority.
 *
 *  \param[in] llobj            Link list object.
 *  \param[in] node             Node object pointer used for linking.
 *  \param[in] params           Pointer to node params containing info like data
 *                              pointer, priority, seqId, seqInterruptible.
 *  \param[in] currSeqId        Current sequence ID in progress for the HW unit.
 *  \pre None
 *  \post None
 *  \return None
 *  \retval None
 ********************************************************************************************************************/
void Spi_UtilsLinkNodePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node, const Spi_UtilsParams *params,
                          uint8 currSeqId);

/**
 *  \brief Unlinks the node from the list. Used for the priority link lists.
 *
 *  \param[in] llobj: pointer to linklist Object
 *  \param[in]  node: pointer to a node in linklist
 *  \pre None
 *  \post None
 *  \return None
 *  \retval None
 ********************************************************************************************************************/
void Spi_UtilsUnLinkNodePri(Spi_UtilsLinkListObj *llobj, Spi_UtilsNode *node);

/**
 *  \brief Initialize the node object with default value.
 *
 *  \param[in] node: pointer to a node in linklist
 *  \pre None
 *  \post None
 *  \return None
 *  \retval None
 ********************************************************************************************************************/
void Spi_UtilsInitNodeObject(Spi_UtilsNode *node);

/**
 *  \brief                  Returns the reference to the head node. This does
 *                          not remove the node from the head.
 *
 *  \param[inout] llobj            Link list object.
 *  \pre None
 *  \post None
 *  \return  Returns the reference to the head node
 *  \retval pointer to a node in linklist
 ********************************************************************************************************************/
Spi_UtilsNode *Spi_UtilsGetHeadNode(const Spi_UtilsLinkListObj *llobj);

/*********************************************************************************************************************
 *  Exported Inline Function Definitions and Function-Like Macros
 *********************************************************************************************************************/

/* None */

/*********************************************************************************************************************
 *  Mark the end of the C bindings section for C++ compilers.
 *********************************************************************************************************************/
#ifdef __cplusplus
}
#endif
#endif /* #ifndef SPI_UTILS_H_ */
/*********************************************************************************************************************
 *  End of File: Spi_Utils.h
 *********************************************************************************************************************/
