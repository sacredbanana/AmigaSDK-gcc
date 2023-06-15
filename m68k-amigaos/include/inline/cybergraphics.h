/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_CYBERGFX_H
#define _INLINE_CYBERGFX_H

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

#ifndef CYBERGFX_BASE_NAME
#define CYBERGFX_BASE_NAME CyberGfxBase
#endif /* !CYBERGFX_BASE_NAME */

#define IsCyberModeID(___displayID) \
      LP1(0x36, BOOL, IsCyberModeID , ULONG, ___displayID, d0,\
      , CYBERGFX_BASE_NAME)

#define BestCModeIDTagList(___BestModeIDTags) \
      LP1(0x3c, ULONG, BestCModeIDTagList , struct TagItem *, ___BestModeIDTags, a0,\
      , CYBERGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define BestCModeIDTags(___BestModeIDTags, ...) \
    ({_sfdc_vararg _tags[] = { ___BestModeIDTags, __VA_ARGS__ }; BestCModeIDTagList((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CModeRequestTagList(___ModeRequest, ___ModeRequestTags) \
      LP2(0x42, ULONG, CModeRequestTagList , APTR, ___ModeRequest, a0, struct TagItem *, ___ModeRequestTags, a1,\
      , CYBERGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CModeRequestTags(___ModeRequest, ___ModeRequestTags, ...) \
    ({_sfdc_vararg _tags[] = { ___ModeRequestTags, __VA_ARGS__ }; CModeRequestTagList((___ModeRequest), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define AllocCModeListTagList(___ModeListTags) \
      LP1(0x48, struct List *, AllocCModeListTagList , struct TagItem *, ___ModeListTags, a1,\
      , CYBERGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define AllocCModeListTags(___ModeListTags, ...) \
    ({_sfdc_vararg _tags[] = { ___ModeListTags, __VA_ARGS__ }; AllocCModeListTagList((struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define FreeCModeList(___ModeList) \
      LP1NR(0x4e, FreeCModeList , struct List *, ___ModeList, a0,\
      , CYBERGFX_BASE_NAME)

#define ScalePixelArray(___srcRect, ___SrcW, ___SrcH, ___SrcMod, ___RastPort, ___DestX, ___DestY, ___DestW, ___DestH, ___SrcFormat) \
      LP10(0x5a, LONG, ScalePixelArray , APTR, ___srcRect, a0, UWORD, ___SrcW, d0, UWORD, ___SrcH, d1, UWORD, ___SrcMod, d2, struct RastPort *, ___RastPort, a1, UWORD, ___DestX, d3, UWORD, ___DestY, d4, UWORD, ___DestW, d5, UWORD, ___DestH, d6, UBYTE, ___SrcFormat, d7,\
      , CYBERGFX_BASE_NAME)

#define GetCyberMapAttr(___CyberGfxBitmap, ___CyberAttrTag) \
      LP2(0x60, ULONG, GetCyberMapAttr , struct BitMap *, ___CyberGfxBitmap, a0, ULONG, ___CyberAttrTag, d0,\
      , CYBERGFX_BASE_NAME)

#define GetCyberIDAttr(___CyberIDAttr, ___CyberDisplayModeID) \
      LP2(0x66, ULONG, GetCyberIDAttr , ULONG, ___CyberIDAttr, d0, ULONG, ___CyberDisplayModeID, d1,\
      , CYBERGFX_BASE_NAME)

#define ReadRGBPixel(___RastPort, ___x, ___y) \
      LP3(0x6c, ULONG, ReadRGBPixel , struct RastPort *, ___RastPort, a1, UWORD, ___x, d0, UWORD, ___y, d1,\
      , CYBERGFX_BASE_NAME)

#define WriteRGBPixel(___RastPort, ___x, ___y, ___argb) \
      LP4(0x72, LONG, WriteRGBPixel , struct RastPort *, ___RastPort, a1, UWORD, ___x, d0, UWORD, ___y, d1, ULONG, ___argb, d2,\
      , CYBERGFX_BASE_NAME)

#define ReadPixelArray(___destRect, ___destX, ___destY, ___destMod, ___RastPort, ___SrcX, ___SrcY, ___SizeX, ___SizeY, ___DestFormat) \
      LP10(0x78, ULONG, ReadPixelArray , APTR, ___destRect, a0, UWORD, ___destX, d0, UWORD, ___destY, d1, UWORD, ___destMod, d2, struct RastPort *, ___RastPort, a1, UWORD, ___SrcX, d3, UWORD, ___SrcY, d4, UWORD, ___SizeX, d5, UWORD, ___SizeY, d6, UBYTE, ___DestFormat, d7,\
      , CYBERGFX_BASE_NAME)

#define WritePixelArray(___srcRect, ___SrcX, ___SrcY, ___SrcMod, ___RastPort, ___DestX, ___DestY, ___SizeX, ___SizeY, ___SrcFormat) \
      LP10(0x7e, ULONG, WritePixelArray , APTR, ___srcRect, a0, UWORD, ___SrcX, d0, UWORD, ___SrcY, d1, UWORD, ___SrcMod, d2, struct RastPort *, ___RastPort, a1, UWORD, ___DestX, d3, UWORD, ___DestY, d4, UWORD, ___SizeX, d5, UWORD, ___SizeY, d6, UBYTE, ___SrcFormat, d7,\
      , CYBERGFX_BASE_NAME)

#define MovePixelArray(___SrcX, ___SrcY, ___RastPort, ___DestX, ___DestY, ___SizeX, ___SizeY) \
      LP7(0x84, ULONG, MovePixelArray , UWORD, ___SrcX, d0, UWORD, ___SrcY, d1, struct RastPort *, ___RastPort, a1, UWORD, ___DestX, d2, UWORD, ___DestY, d3, UWORD, ___SizeX, d4, UWORD, ___SizeY, d5,\
      , CYBERGFX_BASE_NAME)

#define InvertPixelArray(___RastPort, ___DestX, ___DestY, ___SizeX, ___SizeY) \
      LP5(0x90, ULONG, InvertPixelArray , struct RastPort *, ___RastPort, a1, UWORD, ___DestX, d0, UWORD, ___DestY, d1, UWORD, ___SizeX, d2, UWORD, ___SizeY, d3,\
      , CYBERGFX_BASE_NAME)

#define FillPixelArray(___RastPort, ___DestX, ___DestY, ___SizeX, ___SizeY, ___ARGB) \
      LP6(0x96, ULONG, FillPixelArray , struct RastPort *, ___RastPort, a1, UWORD, ___DestX, d0, UWORD, ___DestY, d1, UWORD, ___SizeX, d2, UWORD, ___SizeY, d3, ULONG, ___ARGB, d4,\
      , CYBERGFX_BASE_NAME)

#define DoCDrawMethodTagList(___Hook, ___RastPort, ___TagList) \
      LP3NR(0x9c, DoCDrawMethodTagList , struct Hook *, ___Hook, a0, struct RastPort *, ___RastPort, a1, struct TagItem *, ___TagList, a2,\
      , CYBERGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define DoCDrawMethodTags(___Hook, ___RastPort, ___TagList, ...) \
    ({_sfdc_vararg _tags[] = { ___TagList, __VA_ARGS__ }; DoCDrawMethodTagList((___Hook), (___RastPort), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define CVideoCtrlTagList(___ViewPort, ___TagList) \
      LP2NR(0xa2, CVideoCtrlTagList , struct ViewPort *, ___ViewPort, a0, struct TagItem *, ___TagList, a1,\
      , CYBERGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define CVideoCtrlTags(___ViewPort, ___TagList, ...) \
    ({_sfdc_vararg _tags[] = { ___TagList, __VA_ARGS__ }; CVideoCtrlTagList((___ViewPort), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define LockBitMapTagList(___BitMap, ___TagList) \
      LP2(0xa8, APTR, LockBitMapTagList , APTR, ___BitMap, a0, struct TagItem *, ___TagList, a1,\
      , CYBERGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define LockBitMapTags(___BitMap, ___TagList, ...) \
    ({_sfdc_vararg _tags[] = { ___TagList, __VA_ARGS__ }; LockBitMapTagList((___BitMap), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define UnLockBitMap(___Handle) \
      LP1NR(0xae, UnLockBitMap , APTR, ___Handle, a0,\
      , CYBERGFX_BASE_NAME)

#define UnLockBitMapTagList(___Handle, ___TagList) \
      LP2NR(0xb4, UnLockBitMapTagList , APTR, ___Handle, a0, struct TagItem *, ___TagList, a1,\
      , CYBERGFX_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define UnLockBitMapTags(___Handle, ___TagList, ...) \
    ({_sfdc_vararg _tags[] = { ___TagList, __VA_ARGS__ }; UnLockBitMapTagList((___Handle), (struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define ExtractColor(___RastPort, ___BitMap, ___Colour, ___SrcX, ___SrcY, ___Width, ___Height) \
      LP7(0xba, ULONG, ExtractColor , struct RastPort *, ___RastPort, a0, struct BitMap *, ___BitMap, a1, ULONG, ___Colour, d0, ULONG, ___SrcX, d1, ULONG, ___SrcY, d2, ULONG, ___Width, d3, ULONG, ___Height, d4,\
      , CYBERGFX_BASE_NAME)

#define WriteLUTPixelArray(___srcRect, ___SrcX, ___SrcY, ___SrcMod, ___RastPort, ___ColorTab, ___DestX, ___DestY, ___SizeX, ___SizeY, ___CTFormat) \
      LP11(0xc6, ULONG, WriteLUTPixelArray , APTR, ___srcRect, a0, UWORD, ___SrcX, d0, UWORD, ___SrcY, d1, UWORD, ___SrcMod, d2, struct RastPort *, ___RastPort, a1, APTR, ___ColorTab, a2, UWORD, ___DestX, d3, UWORD, ___DestY, d4, UWORD, ___SizeX, d5, UWORD, ___SizeY, d6, UBYTE, ___CTFormat, d7,\
      , CYBERGFX_BASE_NAME)

#endif /* !_INLINE_CYBERGFX_H */
