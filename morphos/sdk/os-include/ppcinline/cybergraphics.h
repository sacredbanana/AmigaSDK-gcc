/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CYBERGRAPHICS_H
#define _PPCINLINE_CYBERGRAPHICS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CYBERGRAPHICS_BASE_NAME
#define CYBERGRAPHICS_BASE_NAME CyberGfxBase
#endif /* !CYBERGRAPHICS_BASE_NAME */

#define CVideoCtrlTagList(__p0, __p1) \
	LP2NR(162, CVideoCtrlTagList, \
		struct ViewPort *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsCyberModeID(__p0) \
	LP1(54, BOOL , IsCyberModeID, \
		ULONG , __p0, d0, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteRGBPixel(__p0, __p1, __p2, __p3) \
	LP4(114, LONG , WriteRGBPixel, \
		struct RastPort *, __p0, a1, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		ULONG , __p3, d2, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocCModeListTagList(__p0) \
	LP1(72, struct List *, AllocCModeListTagList, \
		struct TagItem *, __p0, a1, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FillPixelArray(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(150, ULONG , FillPixelArray, \
		struct RastPort *, __p0, a1, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		UWORD , __p3, d2, \
		UWORD , __p4, d3, \
		ULONG , __p5, d4, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoCDrawMethodTagList(__p0, __p1, __p2) \
	LP3NR(156, DoCDrawMethodTagList, \
		struct Hook *, __p0, a0, \
		struct RastPort *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)





#define CModeRequestTagList(__p0, __p1) \
	LP2(66, ULONG , CModeRequestTagList, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnLockBitMapTagList(__p0, __p1) \
	LP2NR(180, UnLockBitMapTagList, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define ScalePixelArrayAlpha(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	LP10(252, LONG , ScalePixelArrayAlpha, \
		APTR , __p0, a0, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		UWORD , __p3, d2, \
		struct RastPort *, __p4, a1, \
		UWORD , __p5, d3, \
		UWORD , __p6, d4, \
		UWORD , __p7, d5, \
		UWORD , __p8, d6, \
		ULONG , __p9, d7, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeCModeList(__p0) \
	LP1NR(78, FreeCModeList, \
		struct List *, __p0, a0, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InvertPixelArray(__p0, __p1, __p2, __p3, __p4) \
	LP5(144, ULONG , InvertPixelArray, \
		struct RastPort *, __p0, a1, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		UWORD , __p3, d2, \
		UWORD , __p4, d3, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadPixelArray(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	LP10(120, ULONG , ReadPixelArray, \
		APTR , __p0, a0, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		UWORD , __p3, d2, \
		struct RastPort *, __p4, a1, \
		UWORD , __p5, d3, \
		UWORD , __p6, d4, \
		UWORD , __p7, d5, \
		UWORD , __p8, d6, \
		UBYTE , __p9, d7, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BltBitMapRastPortAlpha(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	LP9(240, ULONG , BltBitMapRastPortAlpha, \
		struct BitMap *, __p0, a0, \
		WORD , __p1, d0, \
		WORD , __p2, d1, \
		struct RastPort *, __p3, a1, \
		WORD , __p4, d2, \
		WORD , __p5, d3, \
		WORD , __p6, d4, \
		WORD , __p7, d5, \
		struct TagItem *, __p8, a2, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WritePixelArray(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	LP10(126, ULONG , WritePixelArray, \
		APTR , __p0, a0, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		UWORD , __p3, d2, \
		struct RastPort *, __p4, a1, \
		UWORD , __p5, d3, \
		UWORD , __p6, d4, \
		UWORD , __p7, d5, \
		UWORD , __p8, d6, \
		UBYTE , __p9, d7, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BltBitMapAlpha(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	LP9(234, ULONG , BltBitMapAlpha, \
		struct BitMap *, __p0, a0, \
		WORD , __p1, d0, \
		WORD , __p2, d1, \
		struct BitMap *, __p3, a1, \
		WORD , __p4, d2, \
		WORD , __p5, d3, \
		WORD , __p6, d4, \
		WORD , __p7, d5, \
		struct TagItem *, __p8, a2, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockBitMapTagList(__p0, __p1) \
	LP2(168, APTR , LockBitMapTagList, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MovePixelArray(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(132, ULONG , MovePixelArray, \
		UWORD , __p0, d0, \
		UWORD , __p1, d1, \
		struct RastPort *, __p2, a1, \
		UWORD , __p3, d2, \
		UWORD , __p4, d3, \
		UWORD , __p5, d4, \
		UWORD , __p6, d5, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define UnLockBitMap(__p0) \
	LP1NR(174, UnLockBitMap, \
		APTR , __p0, a0, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BltTemplateAlpha(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8NR(222, BltTemplateAlpha, \
		UBYTE *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		struct RastPort *, __p3, a1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		LONG , __p7, d5, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ProcessPixelArray(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8NR(228, ProcessPixelArray, \
		struct RastPort *, __p0, a1, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		ULONG , __p5, d4, \
		LONG , __p6, d5, \
		struct TagItem *, __p7, a2, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScalePixelArray(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	LP10(90, LONG , ScalePixelArray, \
		APTR , __p0, a0, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		UWORD , __p3, d2, \
		struct RastPort *, __p4, a1, \
		UWORD , __p5, d3, \
		UWORD , __p6, d4, \
		UWORD , __p7, d5, \
		UWORD , __p8, d6, \
		UBYTE , __p9, d7, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)





#define ExtractColor(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(186, ULONG , ExtractColor, \
		struct RastPort *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		ULONG , __p2, d0, \
		ULONG , __p3, d1, \
		ULONG , __p4, d2, \
		ULONG , __p5, d3, \
		ULONG , __p6, d4, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)



#define GetCyberIDAttr(__p0, __p1) \
	LP2(102, ULONG , GetCyberIDAttr, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetCyberMapAttr(__p0, __p1) \
	LP2(96, ULONG , GetCyberMapAttr, \
		struct BitMap *, __p0, a0, \
		ULONG , __p1, d0, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define WriteLUTPixelArray(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	LP11(198, ULONG , WriteLUTPixelArray, \
		APTR , __p0, a0, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		UWORD , __p3, d2, \
		struct RastPort *, __p4, a1, \
		APTR , __p5, a2, \
		UWORD , __p6, d3, \
		UWORD , __p7, d4, \
		UWORD , __p8, d5, \
		UWORD , __p9, d6, \
		UBYTE , __p10, d7, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BestCModeIDTagList(__p0) \
	LP1(60, ULONG , BestCModeIDTagList, \
		struct TagItem *, __p0, a0, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define WritePixelArrayAlpha(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	LP10(216, ULONG , WritePixelArrayAlpha, \
		APTR , __p0, a0, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		UWORD , __p3, d2, \
		struct RastPort *, __p4, a1, \
		UWORD , __p5, d3, \
		UWORD , __p6, d4, \
		UWORD , __p7, d5, \
		UWORD , __p8, d6, \
		ULONG , __p9, d7, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadRGBPixel(__p0, __p1, __p2) \
	LP3(108, ULONG , ReadRGBPixel, \
		struct RastPort *, __p0, a1, \
		UWORD , __p1, d0, \
		UWORD , __p2, d1, \
		, CYBERGRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define CVideoCtrlTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CVideoCtrlTagList(__p0, (struct TagItem *)_tags);})

#define UnLockBitMapTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	UnLockBitMapTagList(__p0, (struct TagItem *)_tags);})

#define AllocCModeListTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocCModeListTagList((struct TagItem *)_tags);})

#define DoCDrawMethodTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DoCDrawMethodTagList(__p0, __p1, (struct TagItem *)_tags);})


#define BestCModeIDTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	BestCModeIDTagList((struct TagItem *)_tags);})

#define CModeRequestTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CModeRequestTagList(__p0, (struct TagItem *)_tags);})

#define LockBitMapTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LockBitMapTagList(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_CYBERGRAPHICS_H */
