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

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef RENDER_BASE_NAME
#define RENDER_BASE_NAME RenderBase
#endif /* !RENDER_BASE_NAME */

#define CreateRMHandlerA(___taglist) \
      LP1(0x2a, APTR, CreateRMHandlerA , struct TagItem *, ___taglist, a1,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreateRMHandler(___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; CreateRMHandlerA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeleteRMHandler(___rmh) \
      LP1NR(0x30, DeleteRMHandler , APTR, ___rmh, a0,\
      , RENDER_BASE_NAME)

#define AllocRenderMem(___rendermemhandler, ___size) \
      LP2(0x36, APTR, AllocRenderMem , APTR, ___rendermemhandler, a0, ULONG, ___size, d0,\
      , RENDER_BASE_NAME)

#define FreeRenderMem(___rendermemhandler, ___mem, ___size) \
      LP3NR(0x3c, FreeRenderMem , APTR, ___rendermemhandler, a0, APTR, ___mem, a1, ULONG, ___size, d0,\
      , RENDER_BASE_NAME)

#define AllocRenderVec(___rendermemhandler, ___size) \
      LP2(0x42, APTR, AllocRenderVec , APTR, ___rendermemhandler, a0, ULONG, ___size, d0,\
      , RENDER_BASE_NAME)

#define FreeRenderVec(___mem) \
      LP1NR(0x48, FreeRenderVec , APTR, ___mem, a0,\
      , RENDER_BASE_NAME)

#define CreateHistogramA(___taglist) \
      LP1(0x4e, APTR, CreateHistogramA , struct TagItem *, ___taglist, a1,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreateHistogram(___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; CreateHistogramA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeleteHistogram(___histogram) \
      LP1NR(0x54, DeleteHistogram , APTR, ___histogram, a0,\
      , RENDER_BASE_NAME)

#define QueryHistogram(___histogram, ___tag) \
      LP2(0x5a, ULONG, QueryHistogram , APTR, ___histogram, a0, Tag, ___tag, d0,\
      , RENDER_BASE_NAME)

#define AddRGB(___histogram, ___RGB, ___count) \
      LP3(0x60, ULONG, AddRGB , APTR, ___histogram, a0, ULONG, ___RGB, d0, ULONG, ___count, d1,\
      , RENDER_BASE_NAME)

#define AddRGBImageA(___histogram, ___rgb, ___width, ___height, ___taglist) \
      LP5(0x66, ULONG, AddRGBImageA , APTR, ___histogram, a0, ULONG *, ___rgb, a1, UWORD, ___width, d0, UWORD, ___height, d1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AddRGBImage(___histogram, ___rgb, ___width, ___height, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; AddRGBImageA((___histogram), (___rgb), (___width), (___height), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define AddChunkyImageA(___histogram, ___chunky, ___width, ___height, ___palette, ___taglist) \
      LP6(0x6c, ULONG, AddChunkyImageA , APTR, ___histogram, a0, UBYTE *, ___chunky, a1, UWORD, ___width, d0, UWORD, ___height, d1, APTR, ___palette, a2, struct TagItem *, ___taglist, a3,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AddChunkyImage(___histogram, ___chunky, ___width, ___height, ___palette, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; AddChunkyImageA((___histogram), (___chunky), (___width), (___height), (___palette), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ExtractPaletteA(___histogram, ___palette, ___numcolors, ___taglist) \
      LP4(0x72, ULONG, ExtractPaletteA , APTR, ___histogram, a0, ULONG *, ___palette, a1, UWORD, ___numcolors, d0, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ExtractPalette(___histogram, ___palette, ___numcolors, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; ExtractPaletteA((___histogram), (___palette), (___numcolors), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define RenderA(___rgb, ___width, ___height, ___chunky, ___palette, ___taglist) \
      LP6(0x78, ULONG, RenderA , ULONG *, ___rgb, a0, UWORD, ___width, d0, UWORD, ___height, d1, UBYTE *, ___chunky, a1, APTR, ___palette, a2, struct TagItem *, ___taglist, a3,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define Render(___rgb, ___width, ___height, ___chunky, ___palette, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; RenderA((___rgb), (___width), (___height), (___chunky), (___palette), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define Planar2ChunkyA(___planetab, ___bytewidth, ___height, ___depth, ___bytesperrow, ___chunky, ___taglist) \
      LP7NR(0x7e, Planar2ChunkyA , PLANEPTR *, ___planetab, a0, UWORD, ___bytewidth, d0, UWORD, ___height, d1, UWORD, ___depth, d2, UWORD, ___bytesperrow, d3, UBYTE *, ___chunky, a1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define Planar2Chunky(___planetab, ___bytewidth, ___height, ___depth, ___bytesperrow, ___chunky, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; Planar2ChunkyA((___planetab), (___bytewidth), (___height), (___depth), (___bytesperrow), (___chunky), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define Chunky2RGBA(___chunky, ___width, ___height, ___rgb, ___palette, ___taglist) \
      LP6(0x84, ULONG, Chunky2RGBA , UBYTE *, ___chunky, a0, UWORD, ___width, d0, UWORD, ___height, d1, ULONG *, ___rgb, a1, APTR, ___palette, a2, struct TagItem *, ___taglist, a3,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define Chunky2RGB(___chunky, ___width, ___height, ___rgb, ___palette, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; Chunky2RGBA((___chunky), (___width), (___height), (___rgb), (___palette), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define Chunky2BitMapA(___chunky, ___sx, ___sy, ___width, ___height, ___bitmap, ___dx, ___dy, ___taglist) \
      LP9NR(0x8a, Chunky2BitMapA , UBYTE *, ___chunky, a0, UWORD, ___sx, d0, UWORD, ___sy, d1, UWORD, ___width, d2, UWORD, ___height, d3, struct BitMap *, ___bitmap, a1, UWORD, ___dx, d4, UWORD, ___dy, d5, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define Chunky2BitMap(___chunky, ___sx, ___sy, ___width, ___height, ___bitmap, ___dx, ___dy, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; Chunky2BitMapA((___chunky), (___sx), (___sy), (___width), (___height), (___bitmap), (___dx), (___dy), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CreateScaleEngineA(___sourcewidth, ___sourceheight, ___destwidth, ___destheight, ___taglist) \
      LP5(0x90, APTR, CreateScaleEngineA , UWORD, ___sourcewidth, d0, UWORD, ___sourceheight, d1, UWORD, ___destwidth, d2, UWORD, ___destheight, d3, struct TagItem *, ___taglist, a1,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreateScaleEngine(___sourcewidth, ___sourceheight, ___destwidth, ___destheight, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; CreateScaleEngineA((___sourcewidth), (___sourceheight), (___destwidth), (___destheight), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeleteScaleEngine(___engine) \
      LP1NR(0x96, DeleteScaleEngine , APTR, ___engine, a0,\
      , RENDER_BASE_NAME)

#define ScaleA(___engine, ___source, ___dest, ___taglist) \
      LP4(0x9c, ULONG, ScaleA , APTR, ___engine, a0, APTR, ___source, a1, APTR, ___dest, a2, struct TagItem *, ___taglist, a3,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define Scale(___engine, ___source, ___dest, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; ScaleA((___engine), (___source), (___dest), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ConvertChunkyA(___source, ___oldpalette, ___width, ___height, ___dest, ___newpalette, ___taglist) \
      LP7A4(0xa2, ULONG, ConvertChunkyA , UBYTE *, ___source, a0, APTR, ___oldpalette, a1, UWORD, ___width, d0, UWORD, ___height, d1, UBYTE *, ___dest, a2, APTR, ___newpalette, a3, struct TagItem *, ___taglist, d7,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ConvertChunky(___source, ___oldpalette, ___width, ___height, ___dest, ___newpalette, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; ConvertChunkyA((___source), (___oldpalette), (___width), (___height), (___dest), (___newpalette), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CreatePenTableA(___chunky, ___oldpalette, ___width, ___height, ___newpalette, ___convtab, ___taglist) \
      LP7NRA4(0xa8, CreatePenTableA , UBYTE *, ___chunky, a0, APTR, ___oldpalette, a1, UWORD, ___width, d0, UWORD, ___height, d1, APTR, ___newpalette, a2, UBYTE *, ___convtab, a3, struct TagItem *, ___taglist, d7,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreatePenTable(___chunky, ___oldpalette, ___width, ___height, ___newpalette, ___convtab, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; CreatePenTableA((___chunky), (___oldpalette), (___width), (___height), (___newpalette), (___convtab), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CreatePaletteA(___taglist) \
      LP1(0xae, APTR, CreatePaletteA , struct TagItem *, ___taglist, a1,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreatePalette(___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; CreatePaletteA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeletePalette(___palette) \
      LP1NR(0xb4, DeletePalette , APTR, ___palette, a0,\
      , RENDER_BASE_NAME)

#define ImportPaletteA(___palette, ___coltab, ___numcols, ___taglist) \
      LP4NR(0xba, ImportPaletteA , APTR, ___palette, a0, APTR, ___coltab, a1, UWORD, ___numcols, d0, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ImportPalette(___palette, ___coltab, ___numcols, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; ImportPaletteA((___palette), (___coltab), (___numcols), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ExportPaletteA(___palette, ___coltab, ___taglist) \
      LP3NR(0xc0, ExportPaletteA , APTR, ___palette, a0, APTR, ___coltab, a1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ExportPalette(___palette, ___coltab, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; ExportPaletteA((___palette), (___coltab), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CountRGB(___histogram, ___rgb) \
      LP2(0xc6, ULONG, CountRGB , APTR, ___histogram, a0, ULONG, ___rgb, d0,\
      , RENDER_BASE_NAME)

#define BestPen(___palette, ___rgb) \
      LP2(0xcc, LONG, BestPen , APTR, ___palette, a0, ULONG, ___rgb, d0,\
      , RENDER_BASE_NAME)

#define FlushPalette(___palette) \
      LP1NR(0xd2, FlushPalette , APTR, ___palette, a0,\
      , RENDER_BASE_NAME)

#define SortPaletteA(___palette, ___mode, ___taglist) \
      LP3(0xd8, ULONG, SortPaletteA , APTR, ___palette, a0, ULONG, ___mode, d0, struct TagItem *, ___taglist, a1,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define SortPalette(___palette, ___mode, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; SortPaletteA((___palette), (___mode), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define AddHistogramA(___histogram1, ___histogram2, ___taglist) \
      LP3(0xde, ULONG, AddHistogramA , APTR, ___histogram1, a0, APTR, ___histogram2, a1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AddHistogram(___histogram1, ___histogram2, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; AddHistogramA((___histogram1), (___histogram2), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ScaleOrdinate(___source, ___dest, ___ordinate) \
      LP3(0xe4, UWORD, ScaleOrdinate , UWORD, ___source, d0, UWORD, ___dest, d1, UWORD, ___ordinate, d2,\
      , RENDER_BASE_NAME)

#define CreateMapEngineA(___palette, ___taglist) \
      LP2(0xf6, APTR, CreateMapEngineA , APTR, ___palette, a0, struct TagItem *, ___taglist, a1,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreateMapEngine(___palette, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; CreateMapEngineA((___palette), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeleteMapEngine(___engine) \
      LP1NR(0xfc, DeleteMapEngine , APTR, ___engine, a0,\
      , RENDER_BASE_NAME)

#define MapRGBArrayA(___engine, ___rgb, ___width, ___height, ___chunky, ___taglist) \
      LP6(0x102, ULONG, MapRGBArrayA , APTR, ___engine, a0, ULONG *, ___rgb, a1, UWORD, ___width, d0, UWORD, ___height, d1, UBYTE *, ___chunky, a2, struct TagItem *, ___taglist, a3,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MapRGBArray(___engine, ___rgb, ___width, ___height, ___chunky, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; MapRGBArrayA((___engine), (___rgb), (___width), (___height), (___chunky), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define RGBArrayDiversityA(___rgb, ___width, ___height, ___taglist) \
      LP4(0x108, LONG, RGBArrayDiversityA , ULONG *, ___rgb, a0, UWORD, ___width, d0, UWORD, ___height, d1, struct TagItem *, ___taglist, a1,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define RGBArrayDiversity(___rgb, ___width, ___height, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; RGBArrayDiversityA((___rgb), (___width), (___height), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ChunkyArrayDiversityA(___chunky, ___palette, ___width, ___height, ___taglist) \
      LP5(0x10e, LONG, ChunkyArrayDiversityA , UBYTE *, ___chunky, a0, APTR, ___palette, a1, UWORD, ___width, d0, UWORD, ___height, d1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ChunkyArrayDiversity(___chunky, ___palette, ___width, ___height, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; ChunkyArrayDiversityA((___chunky), (___palette), (___width), (___height), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define MapChunkyArrayA(___engine, ___source, ___palette, ___width, ___height, ___dest, ___taglist) \
      LP7A4(0x114, ULONG, MapChunkyArrayA , APTR, ___engine, a0, UBYTE *, ___source, a1, APTR, ___palette, a2, UWORD, ___width, d0, UWORD, ___height, d1, UBYTE *, ___dest, a3, struct TagItem *, ___taglist, d7,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MapChunkyArray(___engine, ___source, ___palette, ___width, ___height, ___dest, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; MapChunkyArrayA((___engine), (___source), (___palette), (___width), (___height), (___dest), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define InsertAlphaChannelA(___maskarray, ___width, ___height, ___rgbarray, ___taglist) \
      LP5NR(0x11a, InsertAlphaChannelA , UBYTE *, ___maskarray, a0, UWORD, ___width, d0, UWORD, ___height, d1, ULONG *, ___rgbarray, a1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define InsertAlphaChannel(___maskarray, ___width, ___height, ___rgbarray, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; InsertAlphaChannelA((___maskarray), (___width), (___height), (___rgbarray), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ExtractAlphaChannelA(___rgbarray, ___width, ___height, ___chunkyarray, ___taglist) \
      LP5NR(0x120, ExtractAlphaChannelA , ULONG *, ___rgbarray, a0, UWORD, ___width, d0, UWORD, ___height, d1, UBYTE *, ___chunkyarray, a1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ExtractAlphaChannel(___rgbarray, ___width, ___height, ___chunkyarray, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; ExtractAlphaChannelA((___rgbarray), (___width), (___height), (___chunkyarray), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ApplyAlphaChannelA(___sourcearray, ___width, ___height, ___destarray, ___taglist) \
      LP5NR(0x126, ApplyAlphaChannelA , ULONG *, ___sourcearray, a0, UWORD, ___width, d0, UWORD, ___height, d1, ULONG *, ___destarray, a1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ApplyAlphaChannel(___sourcearray, ___width, ___height, ___destarray, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; ApplyAlphaChannelA((___sourcearray), (___width), (___height), (___destarray), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define MixRGBArrayA(___sourcearray, ___width, ___height, ___destarray, ___ratio, ___taglist) \
      LP6NR(0x12c, MixRGBArrayA , ULONG *, ___sourcearray, a0, UWORD, ___width, d0, UWORD, ___height, d1, ULONG *, ___destarray, a1, UWORD, ___ratio, d2, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MixRGBArray(___sourcearray, ___width, ___height, ___destarray, ___ratio, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; MixRGBArrayA((___sourcearray), (___width), (___height), (___destarray), (___ratio), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define AllocRenderVecClear(___rendermemhandler, ___size) \
      LP2(0x132, APTR, AllocRenderVecClear , APTR, ___rendermemhandler, a0, ULONG, ___size, d0,\
      , RENDER_BASE_NAME)

#define CreateAlphaArrayA(___rgbarray, ___width, ___height, ___taglist) \
      LP4NR(0x138, CreateAlphaArrayA , ULONG *, ___rgbarray, a0, UWORD, ___width, d0, UWORD, ___height, d1, struct TagItem *, ___taglist, a1,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreateAlphaArray(___rgbarray, ___width, ___height, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; CreateAlphaArrayA((___rgbarray), (___width), (___height), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define MixAlphaChannelA(___source1, ___source2, ___width, ___height, ___dest, ___taglist) \
      LP6NR(0x13e, MixAlphaChannelA , ULONG *, ___source1, a0, ULONG *, ___source2, a1, UWORD, ___width, d0, UWORD, ___height, d1, ULONG *, ___dest, a2, struct TagItem *, ___taglist, a3,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MixAlphaChannel(___source1, ___source2, ___width, ___height, ___dest, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; MixAlphaChannelA((___source1), (___source2), (___width), (___height), (___dest), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define TintRGBArrayA(___source, ___width, ___height, ___RGB, ___ratio, ___dest, ___taglist) \
      LP7NR(0x144, TintRGBArrayA , ULONG *, ___source, a0, UWORD, ___width, d0, UWORD, ___height, d1, ULONG, ___RGB, d2, UWORD, ___ratio, d3, ULONG *, ___dest, a1, struct TagItem *, ___taglist, a2,\
      , RENDER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define TintRGBArray(___source, ___width, ___height, ___RGB, ___ratio, ___dest, ___taglist, ...) \
    ({_sfdc_vararg _tags[] = { ___taglist, __VA_ARGS__ }; TintRGBArrayA((___source), (___width), (___height), (___RGB), (___ratio), (___dest), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#endif /* !_INLINE_RENDER_H */
