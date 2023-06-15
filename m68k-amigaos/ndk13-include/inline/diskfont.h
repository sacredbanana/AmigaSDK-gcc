/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_DISKFONT_H
#define _INLINE_DISKFONT_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef DISKFONT_BASE_NAME
#define DISKFONT_BASE_NAME DiskfontBase
#endif /* !DISKFONT_BASE_NAME */

#define OpenDiskFont(___textAttr) \
      LP1(0x1e, struct TextFont *, OpenDiskFont , struct TextAttr *, ___textAttr, a0,\
      , DISKFONT_BASE_NAME)

#define AvailFonts(___buffer, ___bufBytes, ___flags) \
      LP3(0x24, LONG, AvailFonts , struct AvailFontsHeader *, ___buffer, a0, LONG, ___bufBytes, d0, ULONG, ___flags, d1,\
      , DISKFONT_BASE_NAME)

#define NewFontContents(___fontsLock, ___fontName) \
      LP2(0x2a, struct FontContentsHeader *, NewFontContents , BPTR, ___fontsLock, a0, CONST_STRPTR, ___fontName, a1,\
      , DISKFONT_BASE_NAME)

#define DisposeFontContents(___fontContentsHeader) \
      LP1NR(0x30, DisposeFontContents , struct FontContentsHeader *, ___fontContentsHeader, a1,\
      , DISKFONT_BASE_NAME)

#endif /* !_INLINE_DISKFONT_H */
