#ifndef CLIB_CYBERGRAPHICS_PROTOS_H
#define CLIB_CYBERGRAPHICS_PROTOS_H

/*
**    $Id: cybergraphics_protos.h,v 1.11 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef   GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef   GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

/*--- functions in V40 or higher (Release 40.40) ---*/
BOOL IsCyberModeID( ULONG displayID );
ULONG BestCModeIDTagList( struct TagItem *bestModeIDTags );
ULONG BestCModeIDTags( Tag tag1, ... );
ULONG CModeRequestTagList( APTR modeRequest, struct TagItem *modeRequestTags );
ULONG CModeRequestTags( APTR modeRequest, Tag tag1, ... );
struct List *AllocCModeListTagList( struct TagItem *modeListTags );
struct List *AllocCModeListTags( Tag tag1, ... );
VOID FreeCModeList( struct List *modeList );
LONG ScalePixelArray( APTR srcRect, ULONG srcW, ULONG srcH, ULONG srcMod, struct RastPort *rastPort, ULONG destX, ULONG destY, ULONG destW, ULONG destH, ULONG srcFormat );
ULONG GetCyberMapAttr( struct BitMap *cyberGfxBitmap, ULONG cyberAttrTag );
ULONG GetCyberIDAttr( ULONG cyberIDAttr, ULONG cyberDisplayModeID );
ULONG ReadRGBPixel( struct RastPort *rastPort, ULONG x, ULONG y );
LONG WriteRGBPixel( struct RastPort *rastPort, ULONG x, ULONG y, ULONG argb );
ULONG ReadPixelArray( APTR destRect, ULONG destX, ULONG destY, ULONG destMod, struct RastPort *rastPort, ULONG srcX, ULONG srcY, ULONG sizeX, ULONG sizeY, ULONG destFormat );
ULONG WritePixelArray( APTR srcRect, ULONG srcX, ULONG srcY, ULONG srcMod, struct RastPort *rastPort, ULONG destX, ULONG destY, ULONG sizeX, ULONG sizeY, ULONG srcFormat );
ULONG MovePixelArray( ULONG srcX, ULONG srcY, struct RastPort *rastPort, ULONG destX, ULONG destY, ULONG sizeX, ULONG sizeY );
ULONG InvertPixelArray( struct RastPort *rastPort, ULONG destX, ULONG destY, ULONG sizeX, ULONG sizeY );
ULONG FillPixelArray( struct RastPort *rastPort, ULONG destX, ULONG destY, ULONG sizeX, ULONG sizeY, ULONG argb );
VOID DoCDrawMethodTagList( struct Hook *hook, struct RastPort *rastPort, struct TagItem *tagList );
VOID DoCDrawMethodTags( struct Hook *hook, struct RastPort *rastPort, Tag tag1, ... );
VOID CVideoCtrlTagList( struct ViewPort *viewPort, struct TagItem *tagList );
VOID CVideoCtrlTags( struct ViewPort *viewPort, Tag tag1, ... );
/*--- functions in V40 or higher (Release 40.60) ---*/
APTR LockBitMapTagList( APTR bitMap, struct TagItem *tagList );
APTR LockBitMapTags( APTR bitMap, Tag tag1, ... );
VOID UnLockBitMap( APTR handle );
VOID UnLockBitMapTagList( APTR handle, struct TagItem *tagList );
VOID UnLockBitMapTags( APTR handle, Tag tag1, ... );
/*--- functions in V41 or higher ---*/
ULONG ExtractColor( struct RastPort *rastPort, struct BitMap *bitMap, ULONG colour, ULONG srcX, ULONG srcY, ULONG width, ULONG height );
ULONG WriteLUTPixelArray( APTR srcRect, ULONG srcX, ULONG srcY, ULONG srcMod, struct RastPort *rastPort, APTR colorTab, ULONG destX, ULONG destY, ULONG sizeX, ULONG sizeY, ULONG cTFormat );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_CYBERGRAPHICS_PROTOS_H */
