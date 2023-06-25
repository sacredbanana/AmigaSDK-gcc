#ifndef CLIB_DISKFONT_PROTOS_H
#define CLIB_DISKFONT_PROTOS_H

/*
**    $Id: diskfont_protos.h,v 1.12 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef   LIBRARIES_DISKFONT_H
#include <libraries/diskfont.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

struct TextFont *OpenDiskFont( struct TextAttr *textAttr );
LONG AvailFonts( STRPTR buffer, LONG bufBytes, ULONG flags );
/*--- functions in V34 or higher (Release 1.3) ---*/
struct FontContentsHeader *NewFontContents( BPTR fontsLock, STRPTR fontName );
VOID DisposeFontContents( struct FontContentsHeader *fontContentsHeader );
/*--- functions in V36 or higher (Release 2.0) ---*/
struct DiskFontHeader *NewScaledDiskFont( struct TextFont *sourceFont, struct TextAttr *destTextAttr );
/*--- functions in V45 or higher (Beta release for developers only) ---*/
LONG GetDiskFontCtrl( LONG tagid );
VOID SetDiskFontCtrlA( struct TagItem *taglist );
VOID SetDiskFontCtrl( Tag tag1, ... );
/*--- functions in V46 or higher (Beta release for developers only) ---*/
LONG EOpenEngine( struct EGlyphEngine *EEngine );
VOID ECloseEngine( struct EGlyphEngine *EEngine );
ULONG ESetInfoA( struct EGlyphEngine *EEngine, struct TagItem *taglist );
ULONG ESetInfo( struct EGlyphEngine *EEngine, Tag tag1, ... );
ULONG EObtainInfoA( struct EGlyphEngine *EEngine, struct TagItem *taglist );
ULONG EObtainInfo( struct EGlyphEngine *EEngine, Tag tag1, ... );
ULONG EReleaseInfoA( struct EGlyphEngine *EEngine, struct TagItem *taglist );
ULONG EReleaseInfo( struct EGlyphEngine *EEngine, Tag tag1, ... );
struct OutlineFont *OpenOutlineFont( STRPTR name, struct List *list, ULONG flags );
VOID CloseOutlineFont( struct OutlineFont *outlineFont, struct List *list );
LONG WriteFontContents( BPTR fontsLock, STRPTR fontName, struct FontContentsHeader *fontContentsHeader );
LONG WriteDiskFontHeaderA( struct TextFont *font, STRPTR fileName, struct TagItem *taglist );
LONG WriteDiskFontHeader( struct TextFont *font, STRPTR fileName, Tag tag1, ... );
ULONG ObtainCharsetInfo( ULONG knownTag, ULONG knownValue, ULONG wantedTag );
/*--- functions in V49 or higher (Beta release for developers only) ---*/
struct TTextAttr *ObtainTTextAttr( struct TextFont *textFont );
VOID FreeTTextAttr( struct TTextAttr *tta );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_DISKFONT_PROTOS_H */
