/*
 *  $VER: Release.c $Revision: 1.2 $ (09-Jan-2004)
 *
 *  This file is part of "SkeletonDocky".
 *
 *  (C) Copyright 2004 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: Release.c,v 1.2 2008-09-11 15:17:42 cmincea Exp $
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
#include "DockyBase.h"

/****** docky/Release ******************************************************
*
*   NAME
*      Release -- Description
*
*   SYNOPSIS
*      uint32 Release(void)
*
*   FUNCTION
*
*   INPUTS
*
*   RESULT
*       The result ...
*
*   EXAMPLE
*
*   NOTES
*
*   BUGS
*
*   SEE ALSO
*
*****************************************************************************
*
*/

extern struct ExecIFace *IExec;

uint32 _docky_Release(struct DockyIFace *Self)
{
	//IExec->DebugPrintF("docky::_docky_Release()\n");

	Self->Data.RefCount--;
	
	if (!Self->Data.RefCount && (Self->Data.Flags & IFLF_CLONED))
	{
		IExec->DeleteInterface((struct Interface *)Self);
		return 0;
	}
	
	return Self->Data.RefCount;
}

