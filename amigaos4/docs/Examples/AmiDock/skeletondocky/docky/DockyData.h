/*
 *  $VER: DockyData.h $Revision: 1.1 $
 *
 *  This file is part of "SkeletonDocky".
 *
 *  Author: Stefan Robl <stefan@qdev.de>
 *
 *  (C) Copyright 2003 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: DockyData.h,v 1.1 2005-11-02 23:11:48 srobl Exp $
 *
 * $Log: not supported by cvs2svn $
 *
 *
 */
 
#ifndef DOCKY_DATA_H
#define DOCKY_DATA_H

#include <libraries/docky.h>

struct DockyData
{
	struct DockyObjectNr self;
	struct DockySize ds;
	uint32 *destination;

	struct DockyPosition mousepos, pointpos;
	struct DockyDockyDND dnd;
	BOOL dragmouseover;
	uint8 fillheight;
	BOOL leftmouse;

	uint8 flashcount, longflashcount;
	uint32 flashcolor, longflashcolor;

	BOOL in;
	int32 dx,dy;
	int32 scalefactor;
};

#endif
