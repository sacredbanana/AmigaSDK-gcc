#ifndef CLIB_CYBERGRAPHICS_H
#define CLIB_CYBERGRAPHICS_H

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif

#ifndef GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct List *AllocCModeListTagList(struct TagItem *);
#if !defined(USE_INLINE_STDARG)
struct List *AllocCModeListTags(Tag, ...);
#endif
ULONG        BestCModeIDTagList(struct TagItem *);
#if !defined(USE_INLINE_STDARG)
ULONG        BestCModeIDTags(Tag, ...);
#endif
ULONG        CModeRequestTagList(APTR, struct TagItem *);
#if !defined(USE_INLINE_STDARG)
ULONG        CModeRequestTags(APTR, Tag, ...);
#endif
void         CVideoCtrlTagList(struct ViewPort *, struct TagItem *);
#if !defined(USE_INLINE_STDARG)
void         CVideoCtrlTags(struct ViewPort *, Tag tag1, ...);
#endif
void         DoCDrawMethodTagList(struct Hook *, struct RastPort *, struct TagItem *);
#if !defined(USE_INLINE_STDARG)
void         DoCDrawMethodTags(struct Hook *, struct RastPort *, Tag, ...);
#endif
ULONG        ExtractColor(struct RastPort *,struct BitMap *,ULONG,ULONG,ULONG,ULONG,ULONG);
ULONG        FillPixelArray(struct RastPort *, UWORD, UWORD, UWORD, UWORD, ULONG);
void         FreeCModeList(struct List *);
ULONG        GetCyberIDAttr(ULONG, ULONG);
ULONG        GetCyberMapAttr(struct BitMap *, ULONG);
ULONG        InvertPixelArray(struct RastPort *, UWORD, UWORD, UWORD, UWORD);
BOOL         IsCyberModeID(ULONG);
APTR         LockBitMapTagList(APTR,struct TagItem *);
#if !defined(USE_INLINE_STDARG)
APTR         LockBitMapTags(APTR, Tag, ...);
#endif
ULONG        MovePixelArray(UWORD, UWORD, struct RastPort *, UWORD, UWORD, UWORD,
							UWORD);
ULONG        ReadPixelArray(APTR, UWORD, UWORD, UWORD, struct RastPort *, UWORD,
							UWORD, UWORD, UWORD, UBYTE);
ULONG        ReadRGBPixel(struct RastPort *, UWORD, UWORD);
LONG         ScalePixelArray(APTR,UWORD,UWORD,UWORD,struct RastPort *,UWORD,
							 UWORD,UWORD,UWORD,UBYTE);
void         UnLockBitMap(APTR);
ULONG        WritePixelArray(APTR, UWORD, UWORD, UWORD, struct RastPort *, UWORD,
							 UWORD, UWORD, UWORD, UBYTE);
ULONG        WriteLUTPixelArray(APTR, UWORD, UWORD, UWORD, struct RastPort *, APTR,
								UWORD, UWORD, UWORD, UWORD, UBYTE);
LONG         WriteRGBPixel(struct RastPort *, UWORD, UWORD, ULONG);
void         UnLockBitMapTagList(APTR, struct TagItem *);
#if !defined(USE_INLINE_STDARG)
void         UnLockBitMapTags(APTR, Tag, ...);
#endif

/*** V43 ***/

ULONG        WritePixelArrayAlpha(APTR, UWORD, UWORD, UWORD, struct RastPort *, UWORD,
								  UWORD, UWORD, UWORD, ULONG);
void         BltTemplateAlpha(UBYTE *, LONG, LONG, struct RastPort *, LONG, LONG, LONG, LONG );
void         ProcessPixelArray(struct RastPort *,ULONG,ULONG,ULONG,ULONG,ULONG,LONG,struct TagItem *);

/*** V50 ***/

ULONG        BltBitMapAlpha(struct BitMap *, WORD, WORD, struct BitMap *, WORD, WORD, WORD, WORD, struct TagItem *);
ULONG        BltBitMapRastPortAlpha(struct BitMap *, WORD, WORD, struct RastPort *, WORD, WORD, WORD, WORD, struct TagItem *);


LONG         ScalePixelArrayAlpha(APTR,UWORD,UWORD,UWORD,struct RastPort *,UWORD,
							 UWORD,UWORD,UWORD,ULONG);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_CYBERGRAPHICS_H */
