/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_RENDER_H
#define _INLINE_RENDER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

APTR __CreateRMHandlerA(__reg("a6") struct Library * , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-42(a6)";
#define CreateRMHandlerA(taglist) __CreateRMHandlerA(RenderBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __CreateRMHandler(__reg("a6") struct Library * , Tag taglist , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-42(a6)\n\tmovea.l\t(a7)+,a1";
#define CreateRMHandler(...) __CreateRMHandler(RenderBase, __VA_ARGS__)
#endif

void __DeleteRMHandler(__reg("a6") struct Library * , __reg("a0") APTR rmh ) = "\tjsr\t-48(a6)";
#define DeleteRMHandler(rmh) __DeleteRMHandler(RenderBase, (rmh))

APTR __AllocRenderMem(__reg("a6") struct Library * , __reg("a0") APTR rendermemhandler , __reg("d0") ULONG size ) = "\tjsr\t-54(a6)";
#define AllocRenderMem(rendermemhandler, size) __AllocRenderMem(RenderBase, (rendermemhandler), (size))

void __FreeRenderMem(__reg("a6") struct Library * , __reg("a0") APTR rendermemhandler , __reg("a1") APTR mem , __reg("d0") ULONG size ) = "\tjsr\t-60(a6)";
#define FreeRenderMem(rendermemhandler, mem, size) __FreeRenderMem(RenderBase, (rendermemhandler), (mem), (size))

APTR __AllocRenderVec(__reg("a6") struct Library * , __reg("a0") APTR rendermemhandler , __reg("d0") ULONG size ) = "\tjsr\t-66(a6)";
#define AllocRenderVec(rendermemhandler, size) __AllocRenderVec(RenderBase, (rendermemhandler), (size))

void __FreeRenderVec(__reg("a6") struct Library * , __reg("a0") APTR mem ) = "\tjsr\t-72(a6)";
#define FreeRenderVec(mem) __FreeRenderVec(RenderBase, (mem))

APTR __CreateHistogramA(__reg("a6") struct Library * , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-78(a6)";
#define CreateHistogramA(taglist) __CreateHistogramA(RenderBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __CreateHistogram(__reg("a6") struct Library * , Tag taglist , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-78(a6)\n\tmovea.l\t(a7)+,a1";
#define CreateHistogram(...) __CreateHistogram(RenderBase, __VA_ARGS__)
#endif

void __DeleteHistogram(__reg("a6") struct Library * , __reg("a0") APTR histogram ) = "\tjsr\t-84(a6)";
#define DeleteHistogram(histogram) __DeleteHistogram(RenderBase, (histogram))

ULONG __QueryHistogram(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("d0") Tag tag ) = "\tjsr\t-90(a6)";
#define QueryHistogram(histogram, tag) __QueryHistogram(RenderBase, (histogram), (tag))

ULONG __AddRGB(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("d0") ULONG RGB , __reg("d1") ULONG count ) = "\tjsr\t-96(a6)";
#define AddRGB(histogram, RGB, count) __AddRGB(RenderBase, (histogram), (RGB), (count))

ULONG __AddRGBImageA(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("a1") ULONG * rgb , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-102(a6)";
#define AddRGBImageA(histogram, rgb, width, height, taglist) __AddRGBImageA(RenderBase, (histogram), (rgb), (width), (height), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __AddRGBImage(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("a1") ULONG * rgb , __reg("d0") UWORD width , __reg("d1") UWORD height , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-102(a6)\n\tmovea.l\t(a7)+,a2";
#define AddRGBImage(histogram, rgb, width, height, ...) __AddRGBImage(RenderBase, (histogram), (rgb), (width), (height), __VA_ARGS__)
#endif

ULONG __AddChunkyImageA(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("a1") UBYTE * chunky , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") APTR palette , __reg("a3") struct TagItem * taglist ) = "\tjsr\t-108(a6)";
#define AddChunkyImageA(histogram, chunky, width, height, palette, taglist) __AddChunkyImageA(RenderBase, (histogram), (chunky), (width), (height), (palette), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __AddChunkyImage(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("a1") UBYTE * chunky , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") APTR palette , Tag taglist , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-108(a6)\n\tmovea.l\t(a7)+,a3";
#define AddChunkyImage(histogram, chunky, width, height, palette, ...) __AddChunkyImage(RenderBase, (histogram), (chunky), (width), (height), (palette), __VA_ARGS__)
#endif

ULONG __ExtractPaletteA(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("a1") ULONG * palette , __reg("d0") UWORD numcolors , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-114(a6)";
#define ExtractPaletteA(histogram, palette, numcolors, taglist) __ExtractPaletteA(RenderBase, (histogram), (palette), (numcolors), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __ExtractPalette(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("a1") ULONG * palette , __reg("d0") UWORD numcolors , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-114(a6)\n\tmovea.l\t(a7)+,a2";
#define ExtractPalette(histogram, palette, numcolors, ...) __ExtractPalette(RenderBase, (histogram), (palette), (numcolors), __VA_ARGS__)
#endif

ULONG __RenderA(__reg("a6") struct Library * , __reg("a0") ULONG * rgb , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") UBYTE * chunky , __reg("a2") APTR palette , __reg("a3") struct TagItem * taglist ) = "\tjsr\t-120(a6)";
#define RenderA(rgb, width, height, chunky, palette, taglist) __RenderA(RenderBase, (rgb), (width), (height), (chunky), (palette), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __Render(__reg("a6") struct Library * , __reg("a0") ULONG * rgb , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") UBYTE * chunky , __reg("a2") APTR palette , Tag taglist , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-120(a6)\n\tmovea.l\t(a7)+,a3";
#define Render(rgb, width, height, chunky, palette, ...) __Render(RenderBase, (rgb), (width), (height), (chunky), (palette), __VA_ARGS__)
#endif

void __Planar2ChunkyA(__reg("a6") struct Library * , __reg("a0") PLANEPTR * planetab , __reg("d0") UWORD bytewidth , __reg("d1") UWORD height , __reg("d2") UWORD depth , __reg("d3") UWORD bytesperrow , __reg("a1") UBYTE * chunky , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-126(a6)";
#define Planar2ChunkyA(planetab, bytewidth, height, depth, bytesperrow, chunky, taglist) __Planar2ChunkyA(RenderBase, (planetab), (bytewidth), (height), (depth), (bytesperrow), (chunky), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __Planar2Chunky(__reg("a6") struct Library * , __reg("a0") PLANEPTR * planetab , __reg("d0") UWORD bytewidth , __reg("d1") UWORD height , __reg("d2") UWORD depth , __reg("d3") UWORD bytesperrow , __reg("a1") UBYTE * chunky , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-126(a6)\n\tmovea.l\t(a7)+,a2";
#define Planar2Chunky(planetab, bytewidth, height, depth, bytesperrow, chunky, ...) __Planar2Chunky(RenderBase, (planetab), (bytewidth), (height), (depth), (bytesperrow), (chunky), __VA_ARGS__)
#endif

ULONG __Chunky2RGBA(__reg("a6") struct Library * , __reg("a0") UBYTE * chunky , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") ULONG * rgb , __reg("a2") APTR palette , __reg("a3") struct TagItem * taglist ) = "\tjsr\t-132(a6)";
#define Chunky2RGBA(chunky, width, height, rgb, palette, taglist) __Chunky2RGBA(RenderBase, (chunky), (width), (height), (rgb), (palette), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __Chunky2RGB(__reg("a6") struct Library * , __reg("a0") UBYTE * chunky , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") ULONG * rgb , __reg("a2") APTR palette , Tag taglist , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-132(a6)\n\tmovea.l\t(a7)+,a3";
#define Chunky2RGB(chunky, width, height, rgb, palette, ...) __Chunky2RGB(RenderBase, (chunky), (width), (height), (rgb), (palette), __VA_ARGS__)
#endif

void __Chunky2BitMapA(__reg("a6") struct Library * , __reg("a0") UBYTE * chunky , __reg("d0") UWORD sx , __reg("d1") UWORD sy , __reg("d2") UWORD width , __reg("d3") UWORD height , __reg("a1") struct BitMap * bitmap , __reg("d4") UWORD dx , __reg("d5") UWORD dy , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-138(a6)";
#define Chunky2BitMapA(chunky, sx, sy, width, height, bitmap, dx, dy, taglist) __Chunky2BitMapA(RenderBase, (chunky), (sx), (sy), (width), (height), (bitmap), (dx), (dy), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __Chunky2BitMap(__reg("a6") struct Library * , __reg("a0") UBYTE * chunky , __reg("d0") UWORD sx , __reg("d1") UWORD sy , __reg("d2") UWORD width , __reg("d3") UWORD height , __reg("a1") struct BitMap * bitmap , __reg("d4") UWORD dx , __reg("d5") UWORD dy , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-138(a6)\n\tmovea.l\t(a7)+,a2";
#define Chunky2BitMap(chunky, sx, sy, width, height, bitmap, dx, dy, ...) __Chunky2BitMap(RenderBase, (chunky), (sx), (sy), (width), (height), (bitmap), (dx), (dy), __VA_ARGS__)
#endif

APTR __CreateScaleEngineA(__reg("a6") struct Library * , __reg("d0") UWORD sourcewidth , __reg("d1") UWORD sourceheight , __reg("d2") UWORD destwidth , __reg("d3") UWORD destheight , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-144(a6)";
#define CreateScaleEngineA(sourcewidth, sourceheight, destwidth, destheight, taglist) __CreateScaleEngineA(RenderBase, (sourcewidth), (sourceheight), (destwidth), (destheight), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __CreateScaleEngine(__reg("a6") struct Library * , __reg("d0") UWORD sourcewidth , __reg("d1") UWORD sourceheight , __reg("d2") UWORD destwidth , __reg("d3") UWORD destheight , Tag taglist , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-144(a6)\n\tmovea.l\t(a7)+,a1";
#define CreateScaleEngine(sourcewidth, sourceheight, destwidth, destheight, ...) __CreateScaleEngine(RenderBase, (sourcewidth), (sourceheight), (destwidth), (destheight), __VA_ARGS__)
#endif

void __DeleteScaleEngine(__reg("a6") struct Library * , __reg("a0") APTR engine ) = "\tjsr\t-150(a6)";
#define DeleteScaleEngine(engine) __DeleteScaleEngine(RenderBase, (engine))

ULONG __ScaleA(__reg("a6") struct Library * , __reg("a0") APTR engine , __reg("a1") APTR source , __reg("a2") APTR dest , __reg("a3") struct TagItem * taglist ) = "\tjsr\t-156(a6)";
#define ScaleA(engine, source, dest, taglist) __ScaleA(RenderBase, (engine), (source), (dest), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __Scale(__reg("a6") struct Library * , __reg("a0") APTR engine , __reg("a1") APTR source , __reg("a2") APTR dest , Tag taglist , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-156(a6)\n\tmovea.l\t(a7)+,a3";
#define Scale(engine, source, dest, ...) __Scale(RenderBase, (engine), (source), (dest), __VA_ARGS__)
#endif

ULONG __ConvertChunkyA(__reg("a6") struct Library * , __reg("a0") UBYTE * source , __reg("a1") APTR oldpalette , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") UBYTE * dest , __reg("a3") APTR newpalette , __reg("a4") struct TagItem * taglist ) = "\tjsr\t-162(a6)";
#define ConvertChunkyA(source, oldpalette, width, height, dest, newpalette, taglist) __ConvertChunkyA(RenderBase, (source), (oldpalette), (width), (height), (dest), (newpalette), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __ConvertChunky(__reg("a6") struct Library * , __reg("a0") UBYTE * source , __reg("a1") APTR oldpalette , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") UBYTE * dest , __reg("a3") APTR newpalette , Tag taglist , ... ) = "\tmove.l\ta4,-(a7)\n\tlea\t4(a7),a4\n\tjsr\t-162(a6)\n\tmovea.l\t(a7)+,a4";
#define ConvertChunky(source, oldpalette, width, height, dest, newpalette, ...) __ConvertChunky(RenderBase, (source), (oldpalette), (width), (height), (dest), (newpalette), __VA_ARGS__)
#endif

void __CreatePenTableA(__reg("a6") struct Library * , __reg("a0") UBYTE * chunky , __reg("a1") APTR oldpalette , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") APTR newpalette , __reg("a3") UBYTE * convtab , __reg("a4") struct TagItem * taglist ) = "\tjsr\t-168(a6)";
#define CreatePenTableA(chunky, oldpalette, width, height, newpalette, convtab, taglist) __CreatePenTableA(RenderBase, (chunky), (oldpalette), (width), (height), (newpalette), (convtab), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __CreatePenTable(__reg("a6") struct Library * , __reg("a0") UBYTE * chunky , __reg("a1") APTR oldpalette , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") APTR newpalette , __reg("a3") UBYTE * convtab , Tag taglist , ... ) = "\tmove.l\ta4,-(a7)\n\tlea\t4(a7),a4\n\tjsr\t-168(a6)\n\tmovea.l\t(a7)+,a4";
#define CreatePenTable(chunky, oldpalette, width, height, newpalette, convtab, ...) __CreatePenTable(RenderBase, (chunky), (oldpalette), (width), (height), (newpalette), (convtab), __VA_ARGS__)
#endif

APTR __CreatePaletteA(__reg("a6") struct Library * , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-174(a6)";
#define CreatePaletteA(taglist) __CreatePaletteA(RenderBase, (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __CreatePalette(__reg("a6") struct Library * , Tag taglist , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-174(a6)\n\tmovea.l\t(a7)+,a1";
#define CreatePalette(...) __CreatePalette(RenderBase, __VA_ARGS__)
#endif

void __DeletePalette(__reg("a6") struct Library * , __reg("a0") APTR palette ) = "\tjsr\t-180(a6)";
#define DeletePalette(palette) __DeletePalette(RenderBase, (palette))

void __ImportPaletteA(__reg("a6") struct Library * , __reg("a0") APTR palette , __reg("a1") APTR coltab , __reg("d0") UWORD numcols , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-186(a6)";
#define ImportPaletteA(palette, coltab, numcols, taglist) __ImportPaletteA(RenderBase, (palette), (coltab), (numcols), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __ImportPalette(__reg("a6") struct Library * , __reg("a0") APTR palette , __reg("a1") APTR coltab , __reg("d0") UWORD numcols , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-186(a6)\n\tmovea.l\t(a7)+,a2";
#define ImportPalette(palette, coltab, numcols, ...) __ImportPalette(RenderBase, (palette), (coltab), (numcols), __VA_ARGS__)
#endif

void __ExportPaletteA(__reg("a6") struct Library * , __reg("a0") APTR palette , __reg("a1") APTR coltab , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-192(a6)";
#define ExportPaletteA(palette, coltab, taglist) __ExportPaletteA(RenderBase, (palette), (coltab), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __ExportPalette(__reg("a6") struct Library * , __reg("a0") APTR palette , __reg("a1") APTR coltab , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-192(a6)\n\tmovea.l\t(a7)+,a2";
#define ExportPalette(palette, coltab, ...) __ExportPalette(RenderBase, (palette), (coltab), __VA_ARGS__)
#endif

ULONG __CountRGB(__reg("a6") struct Library * , __reg("a0") APTR histogram , __reg("d0") ULONG rgb ) = "\tjsr\t-198(a6)";
#define CountRGB(histogram, rgb) __CountRGB(RenderBase, (histogram), (rgb))

LONG __BestPen(__reg("a6") struct Library * , __reg("a0") APTR palette , __reg("d0") ULONG rgb ) = "\tjsr\t-204(a6)";
#define BestPen(palette, rgb) __BestPen(RenderBase, (palette), (rgb))

void __FlushPalette(__reg("a6") struct Library * , __reg("a0") APTR palette ) = "\tjsr\t-210(a6)";
#define FlushPalette(palette) __FlushPalette(RenderBase, (palette))

ULONG __SortPaletteA(__reg("a6") struct Library * , __reg("a0") APTR palette , __reg("d0") ULONG mode , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-216(a6)";
#define SortPaletteA(palette, mode, taglist) __SortPaletteA(RenderBase, (palette), (mode), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __SortPalette(__reg("a6") struct Library * , __reg("a0") APTR palette , __reg("d0") ULONG mode , Tag taglist , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-216(a6)\n\tmovea.l\t(a7)+,a1";
#define SortPalette(palette, mode, ...) __SortPalette(RenderBase, (palette), (mode), __VA_ARGS__)
#endif

ULONG __AddHistogramA(__reg("a6") struct Library * , __reg("a0") APTR histogram1 , __reg("a1") APTR histogram2 , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-222(a6)";
#define AddHistogramA(histogram1, histogram2, taglist) __AddHistogramA(RenderBase, (histogram1), (histogram2), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __AddHistogram(__reg("a6") struct Library * , __reg("a0") APTR histogram1 , __reg("a1") APTR histogram2 , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-222(a6)\n\tmovea.l\t(a7)+,a2";
#define AddHistogram(histogram1, histogram2, ...) __AddHistogram(RenderBase, (histogram1), (histogram2), __VA_ARGS__)
#endif

UWORD __ScaleOrdinate(__reg("a6") struct Library * , __reg("d0") UWORD source , __reg("d1") UWORD dest , __reg("d2") UWORD ordinate ) = "\tjsr\t-228(a6)";
#define ScaleOrdinate(source, dest, ordinate) __ScaleOrdinate(RenderBase, (source), (dest), (ordinate))

APTR __CreateMapEngineA(__reg("a6") struct Library * , __reg("a0") APTR palette , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-246(a6)";
#define CreateMapEngineA(palette, taglist) __CreateMapEngineA(RenderBase, (palette), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __CreateMapEngine(__reg("a6") struct Library * , __reg("a0") APTR palette , Tag taglist , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-246(a6)\n\tmovea.l\t(a7)+,a1";
#define CreateMapEngine(palette, ...) __CreateMapEngine(RenderBase, (palette), __VA_ARGS__)
#endif

void __DeleteMapEngine(__reg("a6") struct Library * , __reg("a0") APTR engine ) = "\tjsr\t-252(a6)";
#define DeleteMapEngine(engine) __DeleteMapEngine(RenderBase, (engine))

ULONG __MapRGBArrayA(__reg("a6") struct Library * , __reg("a0") APTR engine , __reg("a1") ULONG * rgb , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") UBYTE * chunky , __reg("a3") struct TagItem * taglist ) = "\tjsr\t-258(a6)";
#define MapRGBArrayA(engine, rgb, width, height, chunky, taglist) __MapRGBArrayA(RenderBase, (engine), (rgb), (width), (height), (chunky), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __MapRGBArray(__reg("a6") struct Library * , __reg("a0") APTR engine , __reg("a1") ULONG * rgb , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") UBYTE * chunky , Tag taglist , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-258(a6)\n\tmovea.l\t(a7)+,a3";
#define MapRGBArray(engine, rgb, width, height, chunky, ...) __MapRGBArray(RenderBase, (engine), (rgb), (width), (height), (chunky), __VA_ARGS__)
#endif

LONG __RGBArrayDiversityA(__reg("a6") struct Library * , __reg("a0") ULONG * rgb , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-264(a6)";
#define RGBArrayDiversityA(rgb, width, height, taglist) __RGBArrayDiversityA(RenderBase, (rgb), (width), (height), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __RGBArrayDiversity(__reg("a6") struct Library * , __reg("a0") ULONG * rgb , __reg("d0") UWORD width , __reg("d1") UWORD height , Tag taglist , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-264(a6)\n\tmovea.l\t(a7)+,a1";
#define RGBArrayDiversity(rgb, width, height, ...) __RGBArrayDiversity(RenderBase, (rgb), (width), (height), __VA_ARGS__)
#endif

LONG __ChunkyArrayDiversityA(__reg("a6") struct Library * , __reg("a0") UBYTE * chunky , __reg("a1") APTR palette , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-270(a6)";
#define ChunkyArrayDiversityA(chunky, palette, width, height, taglist) __ChunkyArrayDiversityA(RenderBase, (chunky), (palette), (width), (height), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __ChunkyArrayDiversity(__reg("a6") struct Library * , __reg("a0") UBYTE * chunky , __reg("a1") APTR palette , __reg("d0") UWORD width , __reg("d1") UWORD height , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-270(a6)\n\tmovea.l\t(a7)+,a2";
#define ChunkyArrayDiversity(chunky, palette, width, height, ...) __ChunkyArrayDiversity(RenderBase, (chunky), (palette), (width), (height), __VA_ARGS__)
#endif

ULONG __MapChunkyArrayA(__reg("a6") struct Library * , __reg("a0") APTR engine , __reg("a1") UBYTE * source , __reg("a2") APTR palette , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a3") UBYTE * dest , __reg("a4") struct TagItem * taglist ) = "\tjsr\t-276(a6)";
#define MapChunkyArrayA(engine, source, palette, width, height, dest, taglist) __MapChunkyArrayA(RenderBase, (engine), (source), (palette), (width), (height), (dest), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __MapChunkyArray(__reg("a6") struct Library * , __reg("a0") APTR engine , __reg("a1") UBYTE * source , __reg("a2") APTR palette , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a3") UBYTE * dest , Tag taglist , ... ) = "\tmove.l\ta4,-(a7)\n\tlea\t4(a7),a4\n\tjsr\t-276(a6)\n\tmovea.l\t(a7)+,a4";
#define MapChunkyArray(engine, source, palette, width, height, dest, ...) __MapChunkyArray(RenderBase, (engine), (source), (palette), (width), (height), (dest), __VA_ARGS__)
#endif

void __InsertAlphaChannelA(__reg("a6") struct Library * , __reg("a0") UBYTE * maskarray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") ULONG * rgbarray , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-282(a6)";
#define InsertAlphaChannelA(maskarray, width, height, rgbarray, taglist) __InsertAlphaChannelA(RenderBase, (maskarray), (width), (height), (rgbarray), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __InsertAlphaChannel(__reg("a6") struct Library * , __reg("a0") UBYTE * maskarray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") ULONG * rgbarray , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-282(a6)\n\tmovea.l\t(a7)+,a2";
#define InsertAlphaChannel(maskarray, width, height, rgbarray, ...) __InsertAlphaChannel(RenderBase, (maskarray), (width), (height), (rgbarray), __VA_ARGS__)
#endif

void __ExtractAlphaChannelA(__reg("a6") struct Library * , __reg("a0") ULONG * rgbarray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") UBYTE * chunkyarray , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-288(a6)";
#define ExtractAlphaChannelA(rgbarray, width, height, chunkyarray, taglist) __ExtractAlphaChannelA(RenderBase, (rgbarray), (width), (height), (chunkyarray), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __ExtractAlphaChannel(__reg("a6") struct Library * , __reg("a0") ULONG * rgbarray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") UBYTE * chunkyarray , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-288(a6)\n\tmovea.l\t(a7)+,a2";
#define ExtractAlphaChannel(rgbarray, width, height, chunkyarray, ...) __ExtractAlphaChannel(RenderBase, (rgbarray), (width), (height), (chunkyarray), __VA_ARGS__)
#endif

void __ApplyAlphaChannelA(__reg("a6") struct Library * , __reg("a0") ULONG * sourcearray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") ULONG * destarray , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-294(a6)";
#define ApplyAlphaChannelA(sourcearray, width, height, destarray, taglist) __ApplyAlphaChannelA(RenderBase, (sourcearray), (width), (height), (destarray), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __ApplyAlphaChannel(__reg("a6") struct Library * , __reg("a0") ULONG * sourcearray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") ULONG * destarray , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-294(a6)\n\tmovea.l\t(a7)+,a2";
#define ApplyAlphaChannel(sourcearray, width, height, destarray, ...) __ApplyAlphaChannel(RenderBase, (sourcearray), (width), (height), (destarray), __VA_ARGS__)
#endif

void __MixRGBArrayA(__reg("a6") struct Library * , __reg("a0") ULONG * sourcearray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") ULONG * destarray , __reg("d2") UWORD ratio , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-300(a6)";
#define MixRGBArrayA(sourcearray, width, height, destarray, ratio, taglist) __MixRGBArrayA(RenderBase, (sourcearray), (width), (height), (destarray), (ratio), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __MixRGBArray(__reg("a6") struct Library * , __reg("a0") ULONG * sourcearray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") ULONG * destarray , __reg("d2") UWORD ratio , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-300(a6)\n\tmovea.l\t(a7)+,a2";
#define MixRGBArray(sourcearray, width, height, destarray, ratio, ...) __MixRGBArray(RenderBase, (sourcearray), (width), (height), (destarray), (ratio), __VA_ARGS__)
#endif

APTR __AllocRenderVecClear(__reg("a6") struct Library * , __reg("a0") APTR rendermemhandler , __reg("d0") ULONG size ) = "\tjsr\t-306(a6)";
#define AllocRenderVecClear(rendermemhandler, size) __AllocRenderVecClear(RenderBase, (rendermemhandler), (size))

void __CreateAlphaArrayA(__reg("a6") struct Library * , __reg("a0") ULONG * rgbarray , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") struct TagItem * taglist ) = "\tjsr\t-312(a6)";
#define CreateAlphaArrayA(rgbarray, width, height, taglist) __CreateAlphaArrayA(RenderBase, (rgbarray), (width), (height), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __CreateAlphaArray(__reg("a6") struct Library * , __reg("a0") ULONG * rgbarray , __reg("d0") UWORD width , __reg("d1") UWORD height , Tag taglist , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-312(a6)\n\tmovea.l\t(a7)+,a1";
#define CreateAlphaArray(rgbarray, width, height, ...) __CreateAlphaArray(RenderBase, (rgbarray), (width), (height), __VA_ARGS__)
#endif

void __MixAlphaChannelA(__reg("a6") struct Library * , __reg("a0") ULONG * source1 , __reg("a1") ULONG * source2 , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") ULONG * dest , __reg("a3") struct TagItem * taglist ) = "\tjsr\t-318(a6)";
#define MixAlphaChannelA(source1, source2, width, height, dest, taglist) __MixAlphaChannelA(RenderBase, (source1), (source2), (width), (height), (dest), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __MixAlphaChannel(__reg("a6") struct Library * , __reg("a0") ULONG * source1 , __reg("a1") ULONG * source2 , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") ULONG * dest , Tag taglist , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-318(a6)\n\tmovea.l\t(a7)+,a3";
#define MixAlphaChannel(source1, source2, width, height, dest, ...) __MixAlphaChannel(RenderBase, (source1), (source2), (width), (height), (dest), __VA_ARGS__)
#endif

void __TintRGBArrayA(__reg("a6") struct Library * , __reg("a0") ULONG * source , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("d2") ULONG RGB , __reg("d3") UWORD ratio , __reg("a1") ULONG * dest , __reg("a2") struct TagItem * taglist ) = "\tjsr\t-324(a6)";
#define TintRGBArrayA(source, width, height, RGB, ratio, dest, taglist) __TintRGBArrayA(RenderBase, (source), (width), (height), (RGB), (ratio), (dest), (taglist))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __TintRGBArray(__reg("a6") struct Library * , __reg("a0") ULONG * source , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("d2") ULONG RGB , __reg("d3") UWORD ratio , __reg("a1") ULONG * dest , Tag taglist , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-324(a6)\n\tmovea.l\t(a7)+,a2";
#define TintRGBArray(source, width, height, RGB, ratio, dest, ...) __TintRGBArray(RenderBase, (source), (width), (height), (RGB), (ratio), (dest), __VA_ARGS__)
#endif

#endif /* !_INLINE_RENDER_H */
