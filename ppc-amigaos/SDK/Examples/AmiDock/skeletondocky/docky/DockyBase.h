/*
 *  $VER: DockyBase.h $Revision: 1.2 $
 *
 *  This file is part of "SkeletonDocky".
 *
 *  Author: Stefan Robl <stefan@qdev.de>
 *
 *  (C) Copyright 2003 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: DockyBase.h,v 1.2 2006-05-28 21:18:54 srobl Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.1  2005/11/02 23:11:48  srobl
 * Initial checkin
 *
 *
 *
 */
 
#ifndef __DOCKY_BASE_H
#define __DOCKY_BASE_H

struct DockyBase
{
	struct Library libBase;
    APTR SegList;
};

extern STRPTR GetLocaleString(LONG id);

extern BOOL OpenAllLibraries(void);
extern void CloseAllLibraries(void);

#endif
