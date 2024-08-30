/*
 *  $VER: Expunge.c $Revision: 1.2 $ (09-Jan-2004)
 *
 *  This file is part of "SkeletonDocky".
 *
 *  (C) Copyright 2004 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: Expunge.c,v 1.2 2008-09-11 15:17:42 cmincea Exp $
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

/****** docky/Expunge ******************************************************
*
*   NAME
*      Expunge -- 
*
*   SYNOPSIS
*      void Expunge(void)
*
*   FUNCTION
*      This is the destructor of a docky. Deallocate everything you've
*      allocated before here as it will be the last chance to do so.
*
*   RESULT
*       This function does not return a result.
*
*   SEE ALSO
*       Clone()
*
*****************************************************************************
*
*/

//extern struct ExecIFace *IExec;

void _docky_Expunge(struct DockyIFace *Self)
{
//IExec->DebugPrintF("docky::_docky_Expunge()\n");
}
