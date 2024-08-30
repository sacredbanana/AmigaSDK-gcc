#ifndef CLIB_DISKFONT_PROTOS_H
#define CLIB_DISKFONT_PROTOS_H

/*
	diskfont.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#ifndef LIBRARIES_DISKFONT_H
# include <libraries/diskfont.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct TextFont *OpenDiskFont( struct TextAttr *textAttr );
LONG AvailFonts( STRPTR buffer, LONG bufBytes, LONG flags );
struct FontContentsHeader *NewFontContents( BPTR fontsLock, STRPTR fontName );
VOID DisposeFontContents( struct FontContentsHeader *fontContentsHeader );
struct DiskFontHeader *NewScaledDiskFont( struct TextFont *sourceFont, struct TextAttr *destTextAttr );

/*** V45 ***/

LONG GetDiskFontCtrl( LONG tagid );
VOID SetDiskFontCtrlA( struct TagItem *taglist );
#if !defined(USE_INLINE_STDARG)
VOID SetDiskFontCtrl( Tag tag1, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_DISKFONT_PROTOS_H */
