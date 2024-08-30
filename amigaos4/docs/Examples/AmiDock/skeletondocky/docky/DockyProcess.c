/*
 *  $VER: DockyProcess.c $Revision: 1.2 $ (09-Jan-2004)
 *
 *  This file is part of "SkeletonDocky".
 *
 *  (C) Copyright 2004 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: DockyProcess.c,v 1.2 2008-09-11 15:17:42 cmincea Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.1  2005/11/02 23:11:48  srobl
 * Initial checkin
 *
 *
 *
 */


#include <exec/exec.h>
#include <proto/exec.h>
#include <exec/libraries.h>
#include <proto/docky.h>
#include <stdarg.h>
#include <libraries/docky.h>
#include "DockyData.h"


/****** docky/DockyProcess ***************************************************
*
*   NAME
*      DockyProcess -- Description
*
*   SYNOPSIS
*      BOOL DockyProcess(uint32 turnCount, uint32 *msgType,
*                        uint32 *msgData, BOOL *anotherTurn);
*
*   FUNCTION
*      Within this function, the docky gets the CPU time it requires to do
*      its intended job. This function also provides a way to communicate
*      actively with AmiDock. As you may have seen, the DockyGet() and
*      DockySet() methods are always initiated by AmiDock. There is no
*      chance for a docky to "ask AmiDock a question".
*      This is different for the DockyProcess() function - here, a docky
*      allowed to fire off one ore more requests to AmiDock which will be
*      answered immediately.
*      
*      The operation sequence looks like the following:
*
*      a) in case of no communication:
*         1. result = DockyProcess(0, msgTypePtr, msgDataPtr, anotherTurnPtr);
*            -> the docky returns TRUE/FALSE if it requires redrawing and sets
*               *anotherTurnPtr to FALSE.
*
*      b) in case of two requests:
*         1. DockyProcess(0, msgTypePtr, msgDataPtr, anotherTurnPtr);
*            -> The docky sets *msgTypePtr != 0,  *anotherTurnPtr==TRUE
*            -> AmiDock places a possible result in msgDataPtr, msgTypePtr
*               remains unchanged.
*            -> AmiDock resets *anotherTurnPtr to FALSE
*         2. DockyProcess(1, msgTypePtr, msgDataPtr, anotherTurnPtr);
*            -> similar sequence as before
*         3. result = DockyProcess(2, msgTypePtr, msgDataPtr, anotherTurnPtr);
*            -> the docky returns TRUE/FALSE if it requires redrawing and sets
*               *anotherTurnPtr to FALSE.
*      
*       You will notice, that turnCount is increased by AmiDock each time it
*       re-iterates trough the communication cycle. If for example a
*       programming error within the docky causes an endless loop
*       (for example if *anotherTurnPtr is always TRUE), AmiDock will remove
*       the docky after a limitation of several throusand communication
*       cycles.
*
*   INPUTS
*       turnCount - sequence number within this communication cycle
*
*       msgType - Pointer to a uint32 data location of AmiDock where
*                 the docky can place its request identifier.
*                 The value stored here will remain the same for the
*                 next call of DockyProcess() within this communication
*                 cycle to give the docky a chance to know what type
*                 of result it receives in msgData.
*
*       msgData - Pointer to a uint32 data location of AmiDock where the
*                 docky may place addtional required message data for
*                 AmiDock. AmiDock will also place the result at this
*                 location.
*                 Please remember that all data you receive from AmiDock
*                 is only readable while being in the function call where
*                 you received it! You have to copy every peace of
*                 information to your own data buffer if you want to work
*                 with it in the future!
*
*       anotherTurn - Pointer to a BOOL data location where the docky has
*                     to place TRUE or FALSE wether it wants another
*                     communication cycle or not.
*
*   RESULT
*       The docky has to return TRUE in the last call of DockyProcess()
*       [the call where *anotherTurn is set to FALSE] if AmiDock shall
*       redraw the docky.
*       If the docky returns FALSE here, AmiDock doesn't redraw the docky
*       after that call of DockyProcess().
*
*****************************************************************************
*
*/

BOOL _docky_DockyProcess(struct DockyIFace *Self,
       uint32 turnCount,
       uint32 * msgType,
       uint32 * msgData,
       BOOL * anotherTurn)
{
	//struct DockyData *dd = (struct DockyData *) ((uint32)Self - Self->Data.NegativeSize); 

	// we need no messages
	// msgType, msgData and anotherTurn are set by AmiDock already to NULL, NULL and FALSE
	// *msgType=0;
	// *msgData=0;
	// *anotherTurn=FALSE;

	return TRUE; // needs drawing?
}

