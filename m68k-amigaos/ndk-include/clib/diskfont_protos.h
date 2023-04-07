#ifndef CLIB_DISKFONT_PROTOS_H
#define CLIB_DISKFONT_PROTOS_H

/*
**	$VER: diskfont_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  DISKFONT_DISKFONT_H
#include <diskfont/diskfont.h>
#endif
struct TextFont * __stdargs OpenDiskFont( struct TextAttr *textAttr );
LONG  __stdargs AvailFonts( struct AvailFontsHeader *buffer, LONG bufBytes, ULONG flags );
/*--- functions in V34 or higher (Release 1.3) ---*/
struct FontContentsHeader * __stdargs NewFontContents( BPTR fontsLock, CONST_STRPTR fontName );
VOID  __stdargs DisposeFontContents( struct FontContentsHeader *fontContentsHeader );
/*--- functions in V36 or higher (Release 2.0) ---*/
struct DiskFont * __stdargs NewScaledDiskFont( struct TextFont *sourceFont, struct TextAttr *destTextAttr );
/*--- functions in V45 or higher (Release 3.9) ---*/
LONG  __stdargs GetDiskFontCtrl( LONG tagid );
VOID  __stdargs SetDiskFontCtrlA( CONST struct TagItem *taglist );
VOID  __stdargs SetDiskFontCtrl( Tag tag1, ... );
/*--- functions in V47 or higher (Release 3.2) ---*/
LONG  __stdargs EOpenEngine( struct EGlyphEngine *eEngine );
VOID  __stdargs ECloseEngine( struct EGlyphEngine *eEngine );
ULONG  __stdargs ESetInfoA( struct EGlyphEngine *eEngine, CONST struct TagItem *taglist );
ULONG  __stdargs ESetInfo( struct EGlyphEngine *eEngine, ... );
ULONG  __stdargs EObtainInfoA( struct EGlyphEngine *eEngine, CONST struct TagItem *taglist );
ULONG  __stdargs EObtainInfo( struct EGlyphEngine *eEngine, ... );
ULONG  __stdargs EReleaseInfoA( struct EGlyphEngine *eEngine, CONST struct TagItem *taglist );
ULONG  __stdargs EReleaseInfo( struct EGlyphEngine *eEngine, ... );
struct OutlineFont * __stdargs OpenOutlineFont( CONST_STRPTR name, struct List *list, ULONG flags );
VOID  __stdargs CloseOutlineFont( struct OutlineFont *olf, struct List *list );
LONG  __stdargs WriteFontContents( BPTR fontsLock, CONST_STRPTR fontName, CONST struct FontContentsHeader *fontContentsHeader );
LONG  __stdargs WriteDiskFontHeaderA( CONST struct TextFont *font, CONST_STRPTR fileName, CONST struct TagItem *tagList );
LONG  __stdargs WriteDiskFontHeader( CONST struct TextFont *font, CONST_STRPTR fileName, ... );
ULONG  __stdargs ObtainCharsetInfo( ULONG knownTag, ULONG knownValue, ULONG wantedTag );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_DISKFONT_PROTOS_H */
