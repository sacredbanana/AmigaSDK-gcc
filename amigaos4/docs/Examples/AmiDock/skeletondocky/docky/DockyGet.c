/*
 *  $VER: DockyGet.c $Revision: 1.3 $ (09-Jan-2004)
 *
 *  This file is part of "SkeletonDocky".
 *
 *  (C) Copyright 2004 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: DockyGet.c,v 1.3 2009-09-27 10:52:12 cmincea Exp $
 *
 * $Log: not supported by cvs2svn $
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


/****** docky/DockyGet *******************************************************
*
*   NAME
*      DockyGet -- Used by AmiDock to gather various informations from dockies
*
*   SYNOPSIS
*      BOOL DockyGet(uint32 msgType, uint32 * msgData);
*
*   FUNCTION
*      This function accepts different message types defined in
*      "libraries/docky.h".
*
*      DOCKYGET_Version -- uint32
*          This msgType has to be processed by each docky to get the chance of
*          being accepted by AmiDock. You have to return the define
*          DOCKYVERSION of docky.h here to give AmiDock the chance to know
*          which version of the docky API was used for this docky.
*          Example: 
*          switch (msgType)
*          {
*              case DOCKYGET_Version:
*                  *msgData = DOCKYVERSION;
*                  break;
*              ...
*          }
* 
*      DOCKYGET_GetSize -- struct DockySize
*          AmiDock retrieves the size needed for the docky to allocate the
*          required render buffer needed for drawing this docky. Currently
*          the maximal size of the render buffer is the screen size.
*
*      DOCKYGET_FrameDelay -- int32
*          The frame delay specifies the update frequency which is required by
*          this docky. A frame delay of 0 means that the docky wants to be
*          updated each 1/50th second. A value of 1 means an update each
*          2/50th second, ...
*          If you sepecify -1 here, AmiDock doesn't update the docky
*          automatically. Specify -1, if your docky doesn't render animations
*          changing content.
*
*      DOCKYGET_RenderMode -- uint32
*          This call allows AmiDock to retrieve the rendermode required by
*          docky in question. You have to return one of
*          enum enDockyRenderMode here. See <libraries/docky.h>
*
*      DOCKYGET_Notifications -- uint32
*          During runtime, AmiDock is able to send off a lot of different
*          notifications about events happening in the context of
*          AmiDocks environment.
*          This DOCKYGET call retrieves a notification mask which allows
*          the docky to specify which different notifications are of
*          interest to the docky. Notifications not specified here will
*          not be sent to a docky. See enum enDockyNotify from
*          <libraries/docky.h>
*
*      DOCKYGET_Name -- STRPTR
*          Return the name of your docky here
*
*      DOCKYGET_DockyPrefs -- PrefsObject **
*          Return a PrefsObject which contains the prefs for this docky
*
*	   DOCKYGET_InvisibleProcess -- void
*
*      DOCKYGET_DockyPrefsChanged -- void
*          Set if prefs have changed an need to be saved (only checked
*          on AmiDock quit)
*
*      DOCKYGET_Icon -- struct DiskObject *
*          If rendermode==DOCKYRENDERMODE_ICON, AmiDock will ask for this tag.
*
*      DOCKYGET_ContextMenu -- Object *
*          For example: DoMethod((Object *)msgData, OM_ADDMEMBER, ...);
*
*      DOCKYGET_NeedsAttention -- uint32 BOOL
*          If true after
*          Signal(dockyAttention->amidockTask,
*                 1L<<dockyAttention->attentionSignalBit),
*          this docky gets immediately processed.
*
*      DOCKYGET_ShowsName -- uint32 BOOL
*
*      DOCKYGET_SizeAttribs -- uint32
*          A mask of enum enDockySizeAttribs...
*
*      DOCKYGET_AllowsRename -- uint32 BOOL
*          If rendermode==DOCKYRENDERMODE_Icon, AmiDock will ask for this tag.
*          Return TRUE if your docky allows renaming.
*
*      DOCKYGET_AllowsIconChange -- uint32 BOOL (53.1)
*          Return TRUE if your docky allows an alternate icon to be set. If
*          this is TRUE, the "Alt.Icon" setting in AmiDock preferences for
*          your docky becomes enabled. Also you must listen to
*          DOCKYNOTIFY_CHANGE to get DOCKYSET_ObjectIconChange.
*
*   INPUTS
*       msgType - one of enum enDockyGet
*
*       msgData - uint32* pointer to a uint32 field to which the result
*                 of this get operation shall be stored to.
*
*   RESULT
*       Returns TRUE if the specified msgType was known to the docky.
*       In that case, a result may be passed back to AmiDock through the
*       msgData pointer.
*       If the docky returns FALSE, the docky indicates, that it didn't
*       implement the requested feature or that it was not wanted at the
*       current moment.
*
*   SEE ALSO
*       <libraries/docky.h>
*
*****************************************************************************
*
*/

BOOL _docky_DockyGet(struct DockyIFace *Self,
       uint32 msgType,
       uint32 * msgData)
{
	struct DockyData *dd = (struct DockyData *) ((uint32)Self - Self->Data.NegativeSize); 
	BOOL result=TRUE;

	switch (msgType)
	{
		case DOCKYGET_Version:
			*msgData = DOCKYVERSION;
			break;

		case DOCKYGET_GetSize:
			*((struct DockySize *)msgData) = dd->ds;
			break;

		case DOCKYGET_FrameDelay:
			*msgData = 1;
			break;

		case DOCKYGET_RenderMode:
			*msgData = DOCKYRENDERMODE_ARGB;
			break;

		case DOCKYGET_Notifications:
			*msgData = ~0;
			break;

		default:
			result=FALSE;
			break;
	}

	return result;
}
