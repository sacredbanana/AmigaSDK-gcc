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

BOOL __IsCyberModeID(__reg("a6") struct Library * , __reg("d0") ULONG displayID ) = "\tjsr\t-54(a6)";
#define IsCyberModeID(displayID) __IsCyberModeID(CyberGfxBase, (displayID))

ULONG __BestCModeIDTagList(__reg("a6") struct Library * , __reg("a0") struct TagItem * BestModeIDTags ) = "\tjsr\t-60(a6)";
#define BestCModeIDTagList(BestModeIDTags) __BestCModeIDTagList(CyberGfxBase, (BestModeIDTags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __BestCModeIDTags(__reg("a6") struct Library * , Tag BestModeIDTags , ... ) = "\tmove.l\ta0,-(a7)\n\tlea\t4(a7),a0\n\tjsr\t-60(a6)\n\tmovea.l\t(a7)+,a0";
#define BestCModeIDTags(...) __BestCModeIDTags(CyberGfxBase, __VA_ARGS__)
#endif

ULONG __CModeRequestTagList(__reg("a6") struct Library * , __reg("a0") APTR ModeRequest , __reg("a1") struct TagItem * ModeRequestTags ) = "\tjsr\t-66(a6)";
#define CModeRequestTagList(ModeRequest, ModeRequestTags) __CModeRequestTagList(CyberGfxBase, (ModeRequest), (ModeRequestTags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __CModeRequestTags(__reg("a6") struct Library * , __reg("a0") APTR ModeRequest , Tag ModeRequestTags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-66(a6)\n\tmovea.l\t(a7)+,a1";
#define CModeRequestTags(ModeRequest, ...) __CModeRequestTags(CyberGfxBase, (ModeRequest), __VA_ARGS__)
#endif

struct List * __AllocCModeListTagList(__reg("a6") struct Library * , __reg("a1") struct TagItem * ModeListTags ) = "\tjsr\t-72(a6)";
#define AllocCModeListTagList(ModeListTags) __AllocCModeListTagList(CyberGfxBase, (ModeListTags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
struct List * __AllocCModeListTags(__reg("a6") struct Library * , Tag ModeListTags , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-72(a6)\n\tmovea.l\t(a7)+,a1";
#define AllocCModeListTags(...) __AllocCModeListTags(CyberGfxBase, __VA_ARGS__)
#endif

void __FreeCModeList(__reg("a6") struct Library * , __reg("a0") struct List * ModeList ) = "\tjsr\t-78(a6)";
#define FreeCModeList(ModeList) __FreeCModeList(CyberGfxBase, (ModeList))

LONG __ScalePixelArray(__reg("a6") struct Library * , __reg("a0") APTR srcRect , __reg("d0") UWORD SrcW , __reg("d1") UWORD SrcH , __reg("d2") UWORD SrcMod , __reg("a1") struct RastPort * RastPort , __reg("d3") UWORD DestX , __reg("d4") UWORD DestY , __reg("d5") UWORD DestW , __reg("d6") UWORD DestH , __reg("d7") UBYTE SrcFormat ) = "\tjsr\t-90(a6)";
#define ScalePixelArray(srcRect, SrcW, SrcH, SrcMod, RastPort, DestX, DestY, DestW, DestH, SrcFormat) __ScalePixelArray(CyberGfxBase, (srcRect), (SrcW), (SrcH), (SrcMod), (RastPort), (DestX), (DestY), (DestW), (DestH), (SrcFormat))

ULONG __GetCyberMapAttr(__reg("a6") struct Library * , __reg("a0") struct BitMap * CyberGfxBitmap , __reg("d0") ULONG CyberAttrTag ) = "\tjsr\t-96(a6)";
#define GetCyberMapAttr(CyberGfxBitmap, CyberAttrTag) __GetCyberMapAttr(CyberGfxBase, (CyberGfxBitmap), (CyberAttrTag))

ULONG __GetCyberIDAttr(__reg("a6") struct Library * , __reg("d0") ULONG CyberIDAttr , __reg("d1") ULONG CyberDisplayModeID ) = "\tjsr\t-102(a6)";
#define GetCyberIDAttr(CyberIDAttr, CyberDisplayModeID) __GetCyberIDAttr(CyberGfxBase, (CyberIDAttr), (CyberDisplayModeID))

ULONG __ReadRGBPixel(__reg("a6") struct Library * , __reg("a1") struct RastPort * RastPort , __reg("d0") UWORD x , __reg("d1") UWORD y ) = "\tjsr\t-108(a6)";
#define ReadRGBPixel(RastPort, x, y) __ReadRGBPixel(CyberGfxBase, (RastPort), (x), (y))

LONG __WriteRGBPixel(__reg("a6") struct Library * , __reg("a1") struct RastPort * RastPort , __reg("d0") UWORD x , __reg("d1") UWORD y , __reg("d2") ULONG argb ) = "\tjsr\t-114(a6)";
#define WriteRGBPixel(RastPort, x, y, argb) __WriteRGBPixel(CyberGfxBase, (RastPort), (x), (y), (argb))

ULONG __ReadPixelArray(__reg("a6") struct Library * , __reg("a0") APTR destRect , __reg("d0") UWORD destX , __reg("d1") UWORD destY , __reg("d2") UWORD destMod , __reg("a1") struct RastPort * RastPort , __reg("d3") UWORD SrcX , __reg("d4") UWORD SrcY , __reg("d5") UWORD SizeX , __reg("d6") UWORD SizeY , __reg("d7") UBYTE DestFormat ) = "\tjsr\t-120(a6)";
#define ReadPixelArray(destRect, destX, destY, destMod, RastPort, SrcX, SrcY, SizeX, SizeY, DestFormat) __ReadPixelArray(CyberGfxBase, (destRect), (destX), (destY), (destMod), (RastPort), (SrcX), (SrcY), (SizeX), (SizeY), (DestFormat))

ULONG __WritePixelArray(__reg("a6") struct Library * , __reg("a0") APTR srcRect , __reg("d0") UWORD SrcX , __reg("d1") UWORD SrcY , __reg("d2") UWORD SrcMod , __reg("a1") struct RastPort * RastPort , __reg("d3") UWORD DestX , __reg("d4") UWORD DestY , __reg("d5") UWORD SizeX , __reg("d6") UWORD SizeY , __reg("d7") UBYTE SrcFormat ) = "\tjsr\t-126(a6)";
#define WritePixelArray(srcRect, SrcX, SrcY, SrcMod, RastPort, DestX, DestY, SizeX, SizeY, SrcFormat) __WritePixelArray(CyberGfxBase, (srcRect), (SrcX), (SrcY), (SrcMod), (RastPort), (DestX), (DestY), (SizeX), (SizeY), (SrcFormat))

ULONG __MovePixelArray(__reg("a6") struct Library * , __reg("d0") UWORD SrcX , __reg("d1") UWORD SrcY , __reg("a1") struct RastPort * RastPort , __reg("d2") UWORD DestX , __reg("d3") UWORD DestY , __reg("d4") UWORD SizeX , __reg("d5") UWORD SizeY ) = "\tjsr\t-132(a6)";
#define MovePixelArray(SrcX, SrcY, RastPort, DestX, DestY, SizeX, SizeY) __MovePixelArray(CyberGfxBase, (SrcX), (SrcY), (RastPort), (DestX), (DestY), (SizeX), (SizeY))

ULONG __InvertPixelArray(__reg("a6") struct Library * , __reg("a1") struct RastPort * RastPort , __reg("d0") UWORD DestX , __reg("d1") UWORD DestY , __reg("d2") UWORD SizeX , __reg("d3") UWORD SizeY ) = "\tjsr\t-144(a6)";
#define InvertPixelArray(RastPort, DestX, DestY, SizeX, SizeY) __InvertPixelArray(CyberGfxBase, (RastPort), (DestX), (DestY), (SizeX), (SizeY))

ULONG __FillPixelArray(__reg("a6") struct Library * , __reg("a1") struct RastPort * RastPort , __reg("d0") UWORD DestX , __reg("d1") UWORD DestY , __reg("d2") UWORD SizeX , __reg("d3") UWORD SizeY , __reg("d4") ULONG ARGB ) = "\tjsr\t-150(a6)";
#define FillPixelArray(RastPort, DestX, DestY, SizeX, SizeY, ARGB) __FillPixelArray(CyberGfxBase, (RastPort), (DestX), (DestY), (SizeX), (SizeY), (ARGB))

void __DoCDrawMethodTagList(__reg("a6") struct Library * , __reg("a0") struct Hook * Hook , __reg("a1") struct RastPort * RastPort , __reg("a2") struct TagItem * TagList ) = "\tjsr\t-156(a6)";
#define DoCDrawMethodTagList(Hook, RastPort, TagList) __DoCDrawMethodTagList(CyberGfxBase, (Hook), (RastPort), (TagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __DoCDrawMethodTags(__reg("a6") struct Library * , __reg("a0") struct Hook * Hook , __reg("a1") struct RastPort * RastPort , Tag TagList , ... ) = "\tmove.l\ta2,-(a7)\n\tlea\t4(a7),a2\n\tjsr\t-156(a6)\n\tmovea.l\t(a7)+,a2";
#define DoCDrawMethodTags(Hook, RastPort, ...) __DoCDrawMethodTags(CyberGfxBase, (Hook), (RastPort), __VA_ARGS__)
#endif

void __CVideoCtrlTagList(__reg("a6") struct Library * , __reg("a0") struct ViewPort * ViewPort , __reg("a1") struct TagItem * TagList ) = "\tjsr\t-162(a6)";
#define CVideoCtrlTagList(ViewPort, TagList) __CVideoCtrlTagList(CyberGfxBase, (ViewPort), (TagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __CVideoCtrlTags(__reg("a6") struct Library * , __reg("a0") struct ViewPort * ViewPort , Tag TagList , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-162(a6)\n\tmovea.l\t(a7)+,a1";
#define CVideoCtrlTags(ViewPort, ...) __CVideoCtrlTags(CyberGfxBase, (ViewPort), __VA_ARGS__)
#endif

APTR __LockBitMapTagList(__reg("a6") struct Library * , __reg("a0") APTR BitMap , __reg("a1") struct TagItem * TagList ) = "\tjsr\t-168(a6)";
#define LockBitMapTagList(BitMap, TagList) __LockBitMapTagList(CyberGfxBase, (BitMap), (TagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
APTR __LockBitMapTags(__reg("a6") struct Library * , __reg("a0") APTR BitMap , Tag TagList , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-168(a6)\n\tmovea.l\t(a7)+,a1";
#define LockBitMapTags(BitMap, ...) __LockBitMapTags(CyberGfxBase, (BitMap), __VA_ARGS__)
#endif

void __UnLockBitMap(__reg("a6") struct Library * , __reg("a0") APTR Handle ) = "\tjsr\t-174(a6)";
#define UnLockBitMap(Handle) __UnLockBitMap(CyberGfxBase, (Handle))

void __UnLockBitMapTagList(__reg("a6") struct Library * , __reg("a0") APTR Handle , __reg("a1") struct TagItem * TagList ) = "\tjsr\t-180(a6)";
#define UnLockBitMapTagList(Handle, TagList) __UnLockBitMapTagList(CyberGfxBase, (Handle), (TagList))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
void __UnLockBitMapTags(__reg("a6") struct Library * , __reg("a0") APTR Handle , Tag TagList , ... ) = "\tmove.l\ta1,-(a7)\n\tlea\t4(a7),a1\n\tjsr\t-180(a6)\n\tmovea.l\t(a7)+,a1";
#define UnLockBitMapTags(Handle, ...) __UnLockBitMapTags(CyberGfxBase, (Handle), __VA_ARGS__)
#endif

ULONG __ExtractColor(__reg("a6") struct Library * , __reg("a0") struct RastPort * RastPort , __reg("a1") struct BitMap * BitMap , __reg("d0") ULONG Colour , __reg("d1") ULONG SrcX , __reg("d2") ULONG SrcY , __reg("d3") ULONG Width , __reg("d4") ULONG Height ) = "\tjsr\t-186(a6)";
#define ExtractColor(RastPort, BitMap, Colour, SrcX, SrcY, Width, Height) __ExtractColor(CyberGfxBase, (RastPort), (BitMap), (Colour), (SrcX), (SrcY), (Width), (Height))

ULONG __WriteLUTPixelArray(__reg("a6") struct Library * , __reg("a0") APTR srcRect , __reg("d0") UWORD SrcX , __reg("d1") UWORD SrcY , __reg("d2") UWORD SrcMod , __reg("a1") struct RastPort * RastPort , __reg("a2") APTR ColorTab , __reg("d3") UWORD DestX , __reg("d4") UWORD DestY , __reg("d5") UWORD SizeX , __reg("d6") UWORD SizeY , __reg("d7") UBYTE CTFormat ) = "\tjsr\t-198(a6)";
#define WriteLUTPixelArray(srcRect, SrcX, SrcY, SrcMod, RastPort, ColorTab, DestX, DestY, SizeX, SizeY, CTFormat) __WriteLUTPixelArray(CyberGfxBase, (srcRect), (SrcX), (SrcY), (SrcMod), (RastPort), (ColorTab), (DestX), (DestY), (SizeX), (SizeY), (CTFormat))

#endif /* !_INLINE_CYBERGFX_H */
