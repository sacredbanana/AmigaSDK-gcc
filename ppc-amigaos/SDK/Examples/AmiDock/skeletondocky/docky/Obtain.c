/*
 *  $VER: Obtain.c $Revision: 1.2 $ (09-Jan-2004)
 *
 *  This file is part of "SkeletonDocky".
 *
 *  (C) Copyright 2004 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: Obtain.c,v 1.2 2008-09-11 15:17:42 cmincea Exp $
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

/****** docky/Obtain *******************************************************
*
*   NAME
*      Obtain -- Description
*
*   SYNOPSIS
*      uint32 Obtain(void)
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

//extern struct ExecIFace *IExec;

uint32 _docky_Obtain(struct DockyIFace *Self)
{
//IExec->DebugPrintF("docky::_docky_Obtain()\n");
	Self->Data.RefCount++;
	return Self->Data.RefCount;
}

