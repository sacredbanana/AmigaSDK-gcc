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

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef GUIGFX_BASE_NAME
#define GUIGFX_BASE_NAME GuiGFXBase
#endif /* !GUIGFX_BASE_NAME */

#define MakePictureA(___array, ___width, ___height, ___tags) \
      LP4(0x1e, APTR, MakePictureA , APTR, ___array, a0, UWORD, ___width, d0, UWORD, ___height, d1, struct TagItem *, ___tags, a1,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MakePicture(___array, ___width, ___height, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; MakePictureA((___array), (___width), (___height), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define LoadPictureA(___filename, ___tags) \
      LP2(0x24, APTR, LoadPictureA , STRPTR, ___filename, a0, struct TagItem *, ___tags, a1,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define LoadPicture(___filename, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; LoadPictureA((___filename), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ReadPictureA(___rastport, ___colormap, ___x, ___y, ___width, ___height, ___tags) \
      LP7(0x2a, APTR, ReadPictureA , struct RastPort *, ___rastport, a0, struct ColorMap *, ___colormap, a1, UWORD, ___x, d0, UWORD, ___y, d1, UWORD, ___width, d2, UWORD, ___height, d3, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ReadPicture(___rastport, ___colormap, ___x, ___y, ___width, ___height, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; ReadPictureA((___rastport), (___colormap), (___x), (___y), (___width), (___height), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ClonePictureA(___pic, ___tags) \
      LP2(0x30, APTR, ClonePictureA , APTR, ___pic, a0, struct TagItem *, ___tags, a1,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ClonePicture(___pic, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; ClonePictureA((___pic), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeletePicture(___pic) \
      LP1NR(0x36, DeletePicture , APTR, ___pic, a0,\
      , GUIGFX_BASE_NAME)

#define UpdatePicture(___pic) \
      LP1(0x3c, ULONG, UpdatePicture , ULONG, ___pic, a0,\
      , GUIGFX_BASE_NAME)

#define AddPictureA(___psm, ___pic, ___tags) \
      LP3(0x42, APTR, AddPictureA , APTR, ___psm, a0, APTR, ___pic, a1, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AddPicture(___psm, ___pic, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; AddPictureA((___psm), (___pic), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define AddPaletteA(___psm, ___palette, ___tags) \
      LP3(0x48, APTR, AddPaletteA , APTR, ___psm, a0, APTR, ___palette, a1, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AddPalette(___psm, ___palette, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; AddPaletteA((___psm), (___palette), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define AddPixelArrayA(___psm, ___array, ___width, ___height, ___tags) \
      LP5(0x4e, APTR, AddPixelArrayA , APTR, ___psm, a0, APTR, ___array, a1, UWORD, ___width, d0, UWORD, ___height, d1, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AddPixelArray(___psm, ___array, ___width, ___height, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; AddPixelArrayA((___psm), (___array), (___width), (___height), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define RemColorHandle(___colorhandle) \
      LP1NR(0x54, RemColorHandle , APTR, ___colorhandle, a0,\
      , GUIGFX_BASE_NAME)

#define CreatePenShareMapA(___tags) \
      LP1(0x5a, APTR, CreatePenShareMapA , struct TagItem *, ___tags, a0,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreatePenShareMap(___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; CreatePenShareMapA((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeletePenShareMap(___psm) \
      LP1NR(0x60, DeletePenShareMap , APTR, ___psm, a0,\
      , GUIGFX_BASE_NAME)

#define ObtainDrawHandleA(___psm, ___rastport, ___cm, ___tags) \
      LP4(0x66, APTR, ObtainDrawHandleA , APTR, ___psm, a0, struct RastPort *, ___rastport, a1, struct ColorMap *, ___cm, a2, struct TagItem *, ___tags, a3,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define ObtainDrawHandle(___psm, ___rastport, ___cm, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; ObtainDrawHandleA((___psm), (___rastport), (___cm), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ReleaseDrawHandle(___drawhandle) \
      LP1NR(0x6c, ReleaseDrawHandle , APTR, ___drawhandle, a0,\
      , GUIGFX_BASE_NAME)

#define DrawPictureA(___drawhandle, ___pic, ___x, ___y, ___tags) \
      LP5(0x72, BOOL, DrawPictureA , APTR, ___drawhandle, a0, APTR, ___pic, a1, UWORD, ___x, d0, UWORD, ___y, d1, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define DrawPicture(___drawhandle, ___pic, ___x, ___y, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; DrawPictureA((___drawhandle), (___pic), (___x), (___y), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define MapPaletteA(___drawhandle, ___palette, ___pentab, ___tags) \
      LP4(0x78, BOOL, MapPaletteA , APTR, ___drawhandle, a0, APTR, ___palette, a1, UBYTE *, ___pentab, a2, struct TagItem *, ___tags, a3,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MapPalette(___drawhandle, ___palette, ___pentab, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; MapPaletteA((___drawhandle), (___palette), (___pentab), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define MapPenA(___drawhandle, ___rgb, ___tags) \
      LP3(0x7e, LONG, MapPenA , APTR, ___drawhandle, a0, ULONG, ___rgb, a1, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define MapPen(___drawhandle, ___rgb, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; MapPenA((___drawhandle), (___rgb), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CreatePictureBitMapA(___drawhandle, ___pic, ___tags) \
      LP3(0x84, struct BitMap *, CreatePictureBitMapA , APTR, ___drawhandle, a0, APTR, ___pic, a1, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreatePictureBitMap(___drawhandle, ___pic, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; CreatePictureBitMapA((___drawhandle), (___pic), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DoPictureMethodA(___pic, ___method, ___arguments) \
      LP3(0x8a, ULONG, DoPictureMethodA , APTR, ___pic, a0, ULONG, ___method, d0, ULONG *, ___arguments, a1,\
      , GUIGFX_BASE_NAME)

#define GetPictureAttrsA(___pic, ___tags) \
      LP2(0x90, ULONG, GetPictureAttrsA , APTR, ___pic, a0, struct TagItem *, ___tags, a1,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define GetPictureAttrs(___pic, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; GetPictureAttrsA((___pic), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define LockPictureA(___pic, ___mode, ___args) \
      LP3(0x96, ULONG, LockPictureA , APTR, ___pic, a0, ULONG, ___mode, d0, ULONG *, ___args, a1,\
      , GUIGFX_BASE_NAME)

#define UnLockPicture(___pic, ___mode) \
      LP2NR(0x9c, UnLockPicture , APTR, ___pic, a0, ULONG, ___mode, d0,\
      , GUIGFX_BASE_NAME)

#define IsPictureA(___filename, ___tags) \
      LP2(0xa2, BOOL, IsPictureA , char *, ___filename, a0, struct TagItem *, ___tags, a1,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define IsPicture(___filename, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; IsPictureA((___filename), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CreateDirectDrawHandleA(___drawhandle, ___sw, ___sh, ___dw, ___dh, ___tags) \
      LP6(0xa8, APTR, CreateDirectDrawHandleA , APTR, ___drawhandle, a0, UWORD, ___sw, d0, UWORD, ___sh, d1, UWORD, ___dw, d2, UWORD, ___dh, d3, struct TagItem *, ___tags, a1,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreateDirectDrawHandle(___drawhandle, ___sw, ___sh, ___dw, ___dh, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; CreateDirectDrawHandleA((___drawhandle), (___sw), (___sh), (___dw), (___dh), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define DeleteDirectDrawHandle(___ddh) \
      LP1NR(0xae, DeleteDirectDrawHandle , APTR, ___ddh, a0,\
      , GUIGFX_BASE_NAME)

#define DirectDrawTrueColorA(___ddh, ___array, ___x, ___y, ___tags) \
      LP5(0xb4, BOOL, DirectDrawTrueColorA , APTR, ___ddh, a0, ULONG *, ___array, a1, UWORD, ___x, d0, UWORD, ___y, d1, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define DirectDrawTrueColor(___ddh, ___array, ___x, ___y, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; DirectDrawTrueColorA((___ddh), (___array), (___x), (___y), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CreatePictureMaskA(___pic, ___mask, ___maskwidth, ___tags) \
      LP4(0xba, BOOL, CreatePictureMaskA , APTR, ___pic, a0, UBYTE *, ___mask, a1, UWORD, ___maskwidth, d0, struct TagItem *, ___tags, a2,\
      , GUIGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CreatePictureMask(___pic, ___mask, ___maskwidth, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; CreatePictureMaskA((___pic), (___mask), (___maskwidth), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#endif /* !_INLINE_GUIGFX_H */
