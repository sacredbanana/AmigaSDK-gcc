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
struct TextFont *   __stdargs OpenDiskFont( struct TextAttr *textAttr );
LONG    __stdargs AvailFonts( struct AvailFontsHeader *buffer, LONG bufBytes, ULONG flags );
/*--- functions in V34 or higher (Release 1.3) ---*/
struct FontContentsHeader *   __stdargs NewFontContents( BPTR fontsLock, CONST_STRPTR fontName );
VOID    __stdargs DisposeFontContents( struct FontContentsHeader *fontContentsHeader );
/*--- functions in V36 or higher (Release 2.0) ---*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
