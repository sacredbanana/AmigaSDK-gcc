/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_GUIGFX_H
#define _INLINE_GUIGFX_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

APTR __MakePictureA(__reg("a6") struct Library * , __reg("a0") APTR array , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a1") struct TagItem * tags ) = "\tjsr\t-30(a6)";
#define MakePictureA(array, width, height, tags) __MakePictureA(GuiGFXBase, (array), (width), (height), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __MakePicture(__reg("a6") struct Library * , __reg("a0") APTR array , __reg("d0") UWORD width , __reg("d1") UWORD height , Tag tags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-30(a6)\n\tmovea.l\t(a7)+,a1";
#define MakePicture(array, width, height, ...) __MakePicture(GuiGFXBase, (array), (width), (height), __VA_ARGS__)
#endif

APTR __LoadPictureA(__reg("a6") struct Library * , __reg("a0") STRPTR filename , __reg("a1") struct TagItem * tags ) = "\tjsr\t-36(a6)";
#define LoadPictureA(filename, tags) __LoadPictureA(GuiGFXBase, (filename), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __LoadPicture(__reg("a6") struct Library * , __reg("a0") STRPTR filename , Tag tags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-36(a6)\n\tmovea.l\t(a7)+,a1";
#define LoadPicture(filename, ...) __LoadPicture(GuiGFXBase, (filename), __VA_ARGS__)
#endif

APTR __ReadPictureA(__reg("a6") struct Library * , __reg("a0") struct RastPort * rastport , __reg("a1") struct ColorMap * colormap , __reg("d0") UWORD x , __reg("d1") UWORD y , __reg("d2") UWORD width , __reg("d3") UWORD height , __reg("a2") struct TagItem * tags ) = "\tjsr\t-42(a6)";
#define ReadPictureA(rastport, colormap, x, y, width, height, tags) __ReadPictureA(GuiGFXBase, (rastport), (colormap), (x), (y), (width), (height), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __ReadPicture(__reg("a6") struct Library * , __reg("a0") struct RastPort * rastport , __reg("a1") struct ColorMap * colormap , __reg("d0") UWORD x , __reg("d1") UWORD y , __reg("d2") UWORD width , __reg("d3") UWORD height , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-42(a6)\n\tmovea.l\t(a7)+,a2";
#define ReadPicture(rastport, colormap, x, y, width, height, ...) __ReadPicture(GuiGFXBase, (rastport), (colormap), (x), (y), (width), (height), __VA_ARGS__)
#endif

APTR __ClonePictureA(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("a1") struct TagItem * tags ) = "\tjsr\t-48(a6)";
#define ClonePictureA(pic, tags) __ClonePictureA(GuiGFXBase, (pic), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __ClonePicture(__reg("a6") struct Library * , __reg("a0") APTR pic , Tag tags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-48(a6)\n\tmovea.l\t(a7)+,a1";
#define ClonePicture(pic, ...) __ClonePicture(GuiGFXBase, (pic), __VA_ARGS__)
#endif

void __DeletePicture(__reg("a6") struct Library * , __reg("a0") APTR pic ) = "\tjsr\t-54(a6)";
#define DeletePicture(pic) __DeletePicture(GuiGFXBase, (pic))

ULONG __UpdatePicture(__reg("a6") struct Library * , __reg("a0") ULONG pic ) = "\tjsr\t-60(a6)";
#define UpdatePicture(pic) __UpdatePicture(GuiGFXBase, (pic))

APTR __AddPictureA(__reg("a6") struct Library * , __reg("a0") APTR psm , __reg("a1") APTR pic , __reg("a2") struct TagItem * tags ) = "\tjsr\t-66(a6)";
#define AddPictureA(psm, pic, tags) __AddPictureA(GuiGFXBase, (psm), (pic), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __AddPicture(__reg("a6") struct Library * , __reg("a0") APTR psm , __reg("a1") APTR pic , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-66(a6)\n\tmovea.l\t(a7)+,a2";
#define AddPicture(psm, pic, ...) __AddPicture(GuiGFXBase, (psm), (pic), __VA_ARGS__)
#endif

APTR __AddPaletteA(__reg("a6") struct Library * , __reg("a0") APTR psm , __reg("a1") APTR palette , __reg("a2") struct TagItem * tags ) = "\tjsr\t-72(a6)";
#define AddPaletteA(psm, palette, tags) __AddPaletteA(GuiGFXBase, (psm), (palette), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __AddPalette(__reg("a6") struct Library * , __reg("a0") APTR psm , __reg("a1") APTR palette , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-72(a6)\n\tmovea.l\t(a7)+,a2";
#define AddPalette(psm, palette, ...) __AddPalette(GuiGFXBase, (psm), (palette), __VA_ARGS__)
#endif

APTR __AddPixelArrayA(__reg("a6") struct Library * , __reg("a0") APTR psm , __reg("a1") APTR array , __reg("d0") UWORD width , __reg("d1") UWORD height , __reg("a2") struct TagItem * tags ) = "\tjsr\t-78(a6)";
#define AddPixelArrayA(psm, array, width, height, tags) __AddPixelArrayA(GuiGFXBase, (psm), (array), (width), (height), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __AddPixelArray(__reg("a6") struct Library * , __reg("a0") APTR psm , __reg("a1") APTR array , __reg("d0") UWORD width , __reg("d1") UWORD height , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-78(a6)\n\tmovea.l\t(a7)+,a2";
#define AddPixelArray(psm, array, width, height, ...) __AddPixelArray(GuiGFXBase, (psm), (array), (width), (height), __VA_ARGS__)
#endif

void __RemColorHandle(__reg("a6") struct Library * , __reg("a0") APTR colorhandle ) = "\tjsr\t-84(a6)";
#define RemColorHandle(colorhandle) __RemColorHandle(GuiGFXBase, (colorhandle))

APTR __CreatePenShareMapA(__reg("a6") struct Library * , __reg("a0") struct TagItem * tags ) = "\tjsr\t-90(a6)";
#define CreatePenShareMapA(tags) __CreatePenShareMapA(GuiGFXBase, (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __CreatePenShareMap(__reg("a6") struct Library * , Tag tags , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-90(a6)\n\tmovea.l\t(a7)+,a0";
#define CreatePenShareMap(...) __CreatePenShareMap(GuiGFXBase, __VA_ARGS__)
#endif

void __DeletePenShareMap(__reg("a6") struct Library * , __reg("a0") APTR psm ) = "\tjsr\t-96(a6)";
#define DeletePenShareMap(psm) __DeletePenShareMap(GuiGFXBase, (psm))

APTR __ObtainDrawHandleA(__reg("a6") struct Library * , __reg("a0") APTR psm , __reg("a1") struct RastPort * rastport , __reg("a2") struct ColorMap * cm , __reg("a3") struct TagItem * tags ) = "\tjsr\t-102(a6)";
#define ObtainDrawHandleA(psm, rastport, cm, tags) __ObtainDrawHandleA(GuiGFXBase, (psm), (rastport), (cm), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __ObtainDrawHandle(__reg("a6") struct Library * , __reg("a0") APTR psm , __reg("a1") struct RastPort * rastport , __reg("a2") struct ColorMap * cm , Tag tags , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-102(a6)\n\tmovea.l\t(a7)+,a3";
#define ObtainDrawHandle(psm, rastport, cm, ...) __ObtainDrawHandle(GuiGFXBase, (psm), (rastport), (cm), __VA_ARGS__)
#endif

void __ReleaseDrawHandle(__reg("a6") struct Library * , __reg("a0") APTR drawhandle ) = "\tjsr\t-108(a6)";
#define ReleaseDrawHandle(drawhandle) __ReleaseDrawHandle(GuiGFXBase, (drawhandle))

BOOL __DrawPictureA(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("a1") APTR pic , __reg("d0") UWORD x , __reg("d1") UWORD y , __reg("a2") struct TagItem * tags ) = "\tjsr\t-114(a6)";
#define DrawPictureA(drawhandle, pic, x, y, tags) __DrawPictureA(GuiGFXBase, (drawhandle), (pic), (x), (y), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __DrawPicture(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("a1") APTR pic , __reg("d0") UWORD x , __reg("d1") UWORD y , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-114(a6)\n\tmovea.l\t(a7)+,a2";
#define DrawPicture(drawhandle, pic, x, y, ...) __DrawPicture(GuiGFXBase, (drawhandle), (pic), (x), (y), __VA_ARGS__)
#endif

BOOL __MapPaletteA(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("a1") APTR palette , __reg("a2") UBYTE * pentab , __reg("a3") struct TagItem * tags ) = "\tjsr\t-120(a6)";
#define MapPaletteA(drawhandle, palette, pentab, tags) __MapPaletteA(GuiGFXBase, (drawhandle), (palette), (pentab), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __MapPalette(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("a1") APTR palette , __reg("a2") UBYTE * pentab , Tag tags , ... ) = "\tmove.l\ta3,-(a7)\n\tlea\t4(a7),a3\n\tjsr\t-120(a6)\n\tmovea.l\t(a7)+,a3";
#define MapPalette(drawhandle, palette, pentab, ...) __MapPalette(GuiGFXBase, (drawhandle), (palette), (pentab), __VA_ARGS__)
#endif

LONG __MapPenA(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("a1") ULONG rgb , __reg("a2") struct TagItem * tags ) = "\tjsr\t-126(a6)";
#define MapPenA(drawhandle, rgb, tags) __MapPenA(GuiGFXBase, (drawhandle), (rgb), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
LONG __MapPen(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("a1") ULONG rgb , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-126(a6)\n\tmovea.l\t(a7)+,a2";
#define MapPen(drawhandle, rgb, ...) __MapPen(GuiGFXBase, (drawhandle), (rgb), __VA_ARGS__)
#endif

struct BitMap * __CreatePictureBitMapA(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("a1") APTR pic , __reg("a2") struct TagItem * tags ) = "\tjsr\t-132(a6)";
#define CreatePictureBitMapA(drawhandle, pic, tags) __CreatePictureBitMapA(GuiGFXBase, (drawhandle), (pic), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct BitMap * __CreatePictureBitMap(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("a1") APTR pic , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-132(a6)\n\tmovea.l\t(a7)+,a2";
#define CreatePictureBitMap(drawhandle, pic, ...) __CreatePictureBitMap(GuiGFXBase, (drawhandle), (pic), __VA_ARGS__)
#endif

ULONG __DoPictureMethodA(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("d0") ULONG method , __reg("a1") ULONG * arguments ) = "\tjsr\t-138(a6)";
#define DoPictureMethodA(pic, method, arguments) __DoPictureMethodA(GuiGFXBase, (pic), (method), (arguments))

ULONG __GetPictureAttrsA(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("a1") struct TagItem * tags ) = "\tjsr\t-144(a6)";
#define GetPictureAttrsA(pic, tags) __GetPictureAttrsA(GuiGFXBase, (pic), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __GetPictureAttrs(__reg("a6") struct Library * , __reg("a0") APTR pic , Tag tags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-144(a6)\n\tmovea.l\t(a7)+,a1";
#define GetPictureAttrs(pic, ...) __GetPictureAttrs(GuiGFXBase, (pic), __VA_ARGS__)
#endif

ULONG __LockPictureA(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("d0") ULONG mode , __reg("a1") ULONG * args ) = "\tjsr\t-150(a6)";
#define LockPictureA(pic, mode, args) __LockPictureA(GuiGFXBase, (pic), (mode), (args))

void __UnLockPicture(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("d0") ULONG mode ) = "\tjsr\t-156(a6)";
#define UnLockPicture(pic, mode) __UnLockPicture(GuiGFXBase, (pic), (mode))

BOOL __IsPictureA(__reg("a6") struct Library * , __reg("a0") char * filename , __reg("a1") struct TagItem * tags ) = "\tjsr\t-162(a6)";
#define IsPictureA(filename, tags) __IsPictureA(GuiGFXBase, (filename), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __IsPicture(__reg("a6") struct Library * , __reg("a0") char * filename , Tag tags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-162(a6)\n\tmovea.l\t(a7)+,a1";
#define IsPicture(filename, ...) __IsPicture(GuiGFXBase, (filename), __VA_ARGS__)
#endif

APTR __CreateDirectDrawHandleA(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("d0") UWORD sw , __reg("d1") UWORD sh , __reg("d2") UWORD dw , __reg("d3") UWORD dh , __reg("a1") struct TagItem * tags ) = "\tjsr\t-168(a6)";
#define CreateDirectDrawHandleA(drawhandle, sw, sh, dw, dh, tags) __CreateDirectDrawHandleA(GuiGFXBase, (drawhandle), (sw), (sh), (dw), (dh), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __CreateDirectDrawHandle(__reg("a6") struct Library * , __reg("a0") APTR drawhandle , __reg("d0") UWORD sw , __reg("d1") UWORD sh , __reg("d2") UWORD dw , __reg("d3") UWORD dh , Tag tags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-168(a6)\n\tmovea.l\t(a7)+,a1";
#define CreateDirectDrawHandle(drawhandle, sw, sh, dw, dh, ...) __CreateDirectDrawHandle(GuiGFXBase, (drawhandle), (sw), (sh), (dw), (dh), __VA_ARGS__)
#endif

void __DeleteDirectDrawHandle(__reg("a6") struct Library * , __reg("a0") APTR ddh ) = "\tjsr\t-174(a6)";
#define DeleteDirectDrawHandle(ddh) __DeleteDirectDrawHandle(GuiGFXBase, (ddh))

BOOL __DirectDrawTrueColorA(__reg("a6") struct Library * , __reg("a0") APTR ddh , __reg("a1") ULONG * array , __reg("d0") UWORD x , __reg("d1") UWORD y , __reg("a2") struct TagItem * tags ) = "\tjsr\t-180(a6)";
#define DirectDrawTrueColorA(ddh, array, x, y, tags) __DirectDrawTrueColorA(GuiGFXBase, (ddh), (array), (x), (y), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __DirectDrawTrueColor(__reg("a6") struct Library * , __reg("a0") APTR ddh , __reg("a1") ULONG * array , __reg("d0") UWORD x , __reg("d1") UWORD y , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-180(a6)\n\tmovea.l\t(a7)+,a2";
#define DirectDrawTrueColor(ddh, array, x, y, ...) __DirectDrawTrueColor(GuiGFXBase, (ddh), (array), (x), (y), __VA_ARGS__)
#endif

BOOL __CreatePictureMaskA(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("a1") UBYTE * mask , __reg("d0") UWORD maskwidth , __reg("a2") struct TagItem * tags ) = "\tjsr\t-186(a6)";
#define CreatePictureMaskA(pic, mask, maskwidth, tags) __CreatePictureMaskA(GuiGFXBase, (pic), (mask), (maskwidth), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
BOOL __CreatePictureMask(__reg("a6") struct Library * , __reg("a0") APTR pic , __reg("a1") UBYTE * mask , __reg("d0") UWORD maskwidth , Tag tags , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-186(a6)\n\tmovea.l\t(a7)+,a2";
#define CreatePictureMask(pic, mask, maskwidth, ...) __CreatePictureMask(GuiGFXBase, (pic), (mask), (maskwidth), __VA_ARGS__)
#endif

#endif /* !_INLINE_GUIGFX_H */
