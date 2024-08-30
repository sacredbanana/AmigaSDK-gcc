/*
 *  $VER: Clone.c $Revision: 1.3 $ (09-Jan-2004)
 *
 *  This file is part of "SkeletonDocky".
 *
 *  (C) Copyright 2004 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: Clone.c,v 1.3 2008-09-11 15:17:42 cmincea Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.2  2006/05/28 21:18:54  srobl
 * Intermediate checkin
 *
 * Revision 1.1  2005/11/02 23:11:48  srobl
 * Initial checkin
 *
 *
 *
 */


#include <exec/exec.h>
#include <proto/exec.h>
#include <exec/libraries.h>
#include <clib/alib_protos.h>
#include <proto/docky.h>
#include <stdarg.h>
#include "DockyBase.h"
#include "DockyData.h"
#include <stdlib.h>

/****** docky/Clone ********************************************************
*
*   NAME
*      Clone -- Creates a new instance of the current docky
*               interface.
*
*   SYNOPSIS
*      struct DockyIFace *Clone(void)
*
*   FUNCTION
*      This method creates a new instance of a docky. Each time an additional
*      docky is displayed within a dock, AmiDock calls the Clone method to
*      create a new instance of the docky. Internally, this method usually
*      calls IExec->MakeInterface() to allocate the required memory. You also
*      have to initialize your docky data within this method (like you're
*      doing in a C++ constructor).
*
*   RESULT
*      A pointer to the clones docky interface or NULL in case of a failure.
*
*   SEE ALSO
*      Expunge()
*
*****************************************************************************
*
*/

extern struct ExecIFace *IExec;
extern struct TagItem dockyTags[];
extern ULONG RangeSeed;

struct DockyIFace * _docky_Clone(struct DockyIFace *Self)
{
	struct DockyIFace *docky;

	//IExec->DebugPrintF("docky::_docky_Clone()\n");
	
	docky = (struct DockyIFace *)IExec->MakeInterface(Self->Data.LibBase, dockyTags);
	if (docky)
	{
		struct DockyData *dd = (struct DockyData *) ((uint32)docky - docky->Data.NegativeSize); 

		docky->Data.Flags |= IFLF_CLONED;
		
		dd->ds.width       = 32;
		dd->ds.height      = 32;
		dd->flashcount     = 0;
		dd->longflashcount = 0;

		srand((uint32)dd); // randomize

		dd->pointpos.x = 5 + (rand()%20);
		dd->pointpos.y = 5 + (rand()%20);
		dd->in = FALSE;
		dd->dx = -1 + ((rand()%2)<<1);
		dd->dy = -1 + ((rand()%2)<<1);
	}
	
	return docky;
}

