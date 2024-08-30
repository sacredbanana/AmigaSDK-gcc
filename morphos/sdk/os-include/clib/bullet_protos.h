#ifndef CLIB_BULLET_PROTOS_H
#define CLIB_BULLET_PROTOS_H

/*
	bullet.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef DISKFONT_GLYPH_H
# include <diskfont/glyph.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct GlyphEngine *OpenEngine( VOID );
VOID CloseEngine( struct GlyphEngine *glyphEngine );
ULONG SetInfoA( struct GlyphEngine *glyphEngine, struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
ULONG SetInfo( struct GlyphEngine *glyphEngine, Tag tag1, ... );
#endif
ULONG ObtainInfoA( struct GlyphEngine *glyphEngine, struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
ULONG ObtainInfo( struct GlyphEngine *glyphEngine, Tag tag1, ... );
#endif
ULONG ReleaseInfoA( struct GlyphEngine *glyphEngine, struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
ULONG ReleaseInfo( struct GlyphEngine *glyphEngine, Tag tag1, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_BULLET_PROTOS_H */
