/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_DISKFONT_H
#define _PPCINLINE_DISKFONT_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef DISKFONT_BASE_NAME
#define DISKFONT_BASE_NAME DiskfontBase
#endif /* !DISKFONT_BASE_NAME */

#define OpenDiskFont(__p0) \
	LP1(30, struct TextFont *, OpenDiskFont, \
		struct TextAttr *, __p0, a0, \
		, DISKFONT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AvailFonts(__p0, __p1, __p2) \
	LP3(36, LONG , AvailFonts, \
		STRPTR , __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, DISKFONT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetDiskFontCtrlA(__p0) \
	LP1NR(66, SetDiskFontCtrlA, \
		struct TagItem *, __p0, a0, \
		, DISKFONT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewFontContents(__p0, __p1) \
	LP2(42, struct FontContentsHeader *, NewFontContents, \
		BPTR , __p0, a0, \
		STRPTR , __p1, a1, \
		, DISKFONT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDiskFontCtrl(__p0) \
	LP1(60, LONG , GetDiskFontCtrl, \
		LONG , __p0, d0, \
		, DISKFONT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewScaledDiskFont(__p0, __p1) \
	LP2(54, struct DiskFont *, NewScaledDiskFont, \
		struct TextFont *, __p0, a0, \
		struct TextAttr *, __p1, a1, \
		, DISKFONT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisposeFontContents(__p0) \
	LP1NR(48, DisposeFontContents, \
		struct FontContentsHeader *, __p0, a1, \
		, DISKFONT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define SetDiskFontCtrl(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetDiskFontCtrlA((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_DISKFONT_H */
