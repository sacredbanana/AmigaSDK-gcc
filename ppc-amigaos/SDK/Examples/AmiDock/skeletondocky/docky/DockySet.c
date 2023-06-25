/*
 *  $VER: DockySet.c $Revision: 1.4 $ (09-Jan-2004)
 *
 *  This file is part of "SkeletonDocky".
 *
 *  (C) Copyright 2004 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: DockySet.c,v 1.4 2009-09-27 10:52:12 cmincea Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.3  2008/09/23 19:41:45  cmincea
 * Skeleton.docky 53.1 (23.09.2008) <cmincea>
 * - Updated documentation for new notification tags
 * - Bumped to v53
 *
 * Revision 1.2  2008/09/11 15:17:42  cmincea
 * - Removed "main" references in autodocs
 * - Added hint about current limit for DOCKYGET_GetSize autodoc
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
#include <proto/docky.h>
#include <stdarg.h>
#include <libraries/docky.h>
#include "DockyData.h"

/****** docky/DockySet ***************************************************
*
*   NAME
*      DockySet -- Used by AmiDock to send messages to the docky with
*                  various informations and parameters
*
*   SYNOPSIS
*      BOOL DockySet(uint32 msgType, uint32 msgData);
*
*   FUNCTION
*      This function accepts different message types defined in
*      <libraries/docky.h> which aren't completely listed here.
*
*      DOCKYSET_DockFontChange -- struct DockyDockFont *
*          AmiDock notifies the docky everytime the font attribute, front
*          pen, background pen and drawmode changes.
*
*      DOCKYSET_ObjectIconChange -- struct DockyObjectInfo * (53.1)
*          Sent as DOCKYNOTIFY_CHANGE to the docky if an objects icon gets
*          changed.
*          msgData will contain a pointer to a struct DockyObjectInfo with
*          the field objectIcon set to the full path to the new icon.
*
*
*      ...more definitions in <libraries/docky.h>...
*
*   INPUTS
*       msgType - (uint32) One of DOCKYSET_#?
*       msgData - (uint32) Message specific data
*
*   RESULT
*       TRUE on success
*       FALSE on error or unimplemented message types
*
*   NOTES
*       Please remember that all data you receive from AmiDock is only
*       readable while being in the function call where you received it!
*      	You have to copy every piece of information to your own data buffer
*      	if you want to work with it in the future!
*
*   SEE ALSO
*      <libraries/docky.h>
*
*****************************************************************************
*
*/

void drawImage(struct DockyData *dd)
{
	if (dd->flashcount)
		dd->flashcount--;
	else if (dd->longflashcount)
		dd->longflashcount--;
	else if (!dd->in)
	{
		dd->pointpos.x+=dd->dx;
		dd->pointpos.y+=dd->dy;

		if (dd->pointpos.x<2 || dd->pointpos.x>=dd->ds.width-3)
		{
			dd->dx*=-1;
			dd->pointpos.x+=dd->dx;
		}

		if (dd->pointpos.y<2 || dd->pointpos.y>=dd->ds.height-3)
		{
			dd->dy*=-1;
			dd->pointpos.y+=dd->dy;
		}
	}

	if (dd->destination)
	{
		ULONG *ptr=(ULONG *)dd->destination;
		struct DockyPosition p;
		int x, y, w, h, ww;
		BOOL leftmouse;


		leftmouse=dd->leftmouse;
		w=dd->ds.width;
		h=dd->ds.height;
		p=dd->pointpos;

		if (leftmouse)
			ww=9;
		else
			ww=5;

		p.x-=ww/2;
		p.y-=ww/2;

		if (p.x<0)
			p.x=0;
		else if (p.x>=(w-ww-1))
			p.x=(w-ww);

		if (p.y<0)
			p.y=0;
		else if (p.y>=(h-ww-1))
			p.y=(h-ww);

		if (dd->dragmouseover)
		{
			for(y=0; y<h; y++)
				for(x=0; x<w; x++)
					*ptr++=0x00ffff00;
		}
		else if (dd->flashcount || dd->longflashcount)
		{
			ULONG c;

			if (dd->flashcount)
			{
				c=dd->flashcolor;
				if (dd->flashcount&1)
					c=0;
			}
			else
			{
				c=dd->longflashcolor;
				if (dd->longflashcount&1)
					c=0;
			}

			for(y=0; y<h; y++)
				for(x=0; x<w; x++)
					*ptr++=c;
		}
		else
		{
			int lower=h-dd->fillheight;

			for(y=0; y<h; y++)
				for(x=0; x<w; x++)
				{
					if ( x>=p.x && x<(p.x+ww) && y>=p.y && y<(p.y+ww) )
					{
						if (leftmouse)
							*ptr++=0x00ff0000;
						else
							*ptr++=0x00ffffff;
					}
					else if (y>=lower)
					{
						*ptr++=0x00008888;
					}
					else
					{
						*ptr++=0x00000000;
					}
				}
		}
	}
}


BOOL _docky_DockySet(struct DockyIFace *Self,
       uint32 msgType,
       uint32 msgData)
{
	struct DockyData *dd = (struct DockyData *) ((uint32)Self - Self->Data.NegativeSize); 
	BOOL result=TRUE;

	switch (msgType)
	{
		case DOCKYSET_RenderDestination:
			{
				struct DockyRenderDestination *drd=(struct DockyRenderDestination *)msgData;

				dd->ds=drd->renderSize;

				if (drd->renderMode==DOCKYRENDERMODE_ARGB)
					dd->destination=(ULONG *)drd->render.RGB;
				else
					dd->destination=NULL;
			}
			break;

		case DOCKYSET_RedrawNow:
			drawImage(dd);
			break;

		case DOCKYSET_DockTypeChange:
			{
				struct DockyDockType *ddt=(struct DockyDockType *)msgData;
				if (dd->self.dockNr==ddt->dockNr && ddt->dockType!=AMIDOCK_DockType_Icons)
					result=FALSE;
			}
			break;

		case DOCKYSET_DockyChange:
			dd->self=*((struct DockyObjectNr *)msgData);
			break;

		case DOCKYSET_MouseMove:
			{
				struct DockyPosition *dp=(struct DockyPosition *)msgData;
				dd->mousepos=*dp;

				if (dp->x>=0 && dp->y>=0 && dp->x<dd->ds.width && dp->y<dd->ds.height)
				{
					dd->pointpos=*dp;

					if (dd->pointpos.x<2)
						dd->pointpos.x=2;
					else if (dd->pointpos.x>dd->ds.width-4)
						dd->pointpos.x=dd->ds.width-4;

					if (dd->pointpos.y<2)
						dd->pointpos.y=2;
					else if (dd->pointpos.y>dd->ds.height-4)
						dd->pointpos.y=dd->ds.height-4;

					dd->in=TRUE;
				}
				else dd->in=FALSE;

				
			}
			break;

		case DOCKYSET_SelectChange:
			dd->leftmouse=(BOOL) msgData;
			break;

		case DOCKYSET_DNDMouseOver:
			dd->dragmouseover=(BOOL) msgData;
			break;

		case DOCKYSET_DockyDND:
			{
				struct DockyDockyDND *dnd=(struct DockyDockyDND *)msgData;

				dd->dnd.pos=dnd->pos;
				dd->flashcount=10;
				dd->flashcolor=0x00ff0000;
				
				if (dd->fillheight<dd->ds.height)
					dd->fillheight++;
			}
			break;

		case DOCKYSET_ObjectDND:
			dd->flashcount=3;
			dd->flashcolor=0x00008800;
			break;

		case DOCKYSET_DockyVisibleChange:
			dd->longflashcount=5;
			dd->longflashcolor=0x0000ff00;
			break;

		case DOCKYSET_DockRawKey:
			dd->flashcount=3;
			dd->flashcolor=0x00000044;
			break;

		case DOCKYSET_DockyRawKey:
			dd->flashcount=3;
			dd->flashcolor=0x00000088;
			break;

		case DOCKYSET_DockClick:
			dd->flashcount=3;
			dd->flashcolor=0x00440044;
			break;

		case DOCKYSET_ObjectClick:
			dd->flashcount=3;
			dd->flashcolor=0x00880044;
			break;

		case DOCKYSET_DockMove:
			dd->longflashcount=5;
			dd->longflashcolor=0x00ff0044;
			break;

		case DOCKYSET_CategoryMove:
			dd->flashcount=3;
			dd->flashcolor=0x00ff0088;
			break;

		case DOCKYSET_ObjectMove:
			dd->longflashcount=5;
			dd->longflashcolor=0x00ff00ff;
			break;

		case DOCKYSET_DockResize:
			dd->longflashcount=5;
			dd->longflashcolor=0x00444400;
			break;

		case DOCKYSET_DockCategoryChange:
			dd->flashcount=3;
			dd->flashcolor=0x00ff8800;
			break;

		case DOCKYSET_DockAdd:
			dd->flashcount=3;
			dd->flashcolor=0x00ffff00;
			break;

		case DOCKYSET_CategoryAdd:
			dd->flashcount=3;
			dd->flashcolor=0x00ff4444;
			break;

		case DOCKYSET_ObjectAdd:
			dd->flashcount=3;
			dd->flashcolor=0x00ff4488;
			break;

		case DOCKYSET_DockRename:
			dd->flashcount=3;
			dd->flashcolor=0x00ff44ff;
			break;

		case DOCKYSET_CategoryRename:
			dd->flashcount=3;
			dd->flashcolor=0x00ff8844;
			break;

		case DOCKYSET_DockRemove:
			dd->flashcount=3;
			dd->flashcolor=0x00ffff44;
			break;

		case DOCKYSET_CategoryRemove:
			dd->flashcount=3;
			dd->flashcolor=0x00ffff88;
			break;

		case DOCKYSET_ObjectRemove:
			dd->flashcount=3;
			dd->flashcolor=0x00ffffff;
			break;
		
		case DOCKYSET_DockScaleFactor:
			dd->scalefactor = msgData; /* this is not used in this example */
			break;

		default:
			result=FALSE;
			break;
	}

	return result;
}

