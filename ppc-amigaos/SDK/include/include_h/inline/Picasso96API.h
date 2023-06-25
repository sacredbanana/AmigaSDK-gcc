#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_PICASSO96API_H
#define _INLINE_PICASSO96API_H

#ifndef CLIB_PICASSO96API_PROTOS_H
#define CLIB_PICASSO96API_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  LIBRARIES_PICASSO96_H
#include <libraries/Picasso96.h>
#endif
#ifndef GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef PICASSO96API_BASE_NAME
#define PICASSO96API_BASE_NAME P96Base
#endif

#define p96AllocBitMap(SizeX, SizeY, Depth, Flags, friendBitMap, RGBFormat) ({ \
  ULONG _p96AllocBitMap_SizeX = (SizeX); \
  ULONG _p96AllocBitMap_SizeY = (SizeY); \
  ULONG _p96AllocBitMap_Depth = (Depth); \
  ULONG _p96AllocBitMap_Flags = (Flags); \
  struct BitMap * _p96AllocBitMap_friendBitMap = (friendBitMap); \
  RGBFTYPE _p96AllocBitMap_RGBFormat = (RGBFormat); \
  struct BitMap * _p96AllocBitMap__re = \
  ({ \
  register struct Library * const __p96AllocBitMap__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct BitMap * __p96AllocBitMap__re __asm("d0"); \
  register ULONG __p96AllocBitMap_SizeX __asm("d0") = (_p96AllocBitMap_SizeX); \
  register ULONG __p96AllocBitMap_SizeY __asm("d1") = (_p96AllocBitMap_SizeY); \
  register ULONG __p96AllocBitMap_Depth __asm("d2") = (_p96AllocBitMap_Depth); \
  register ULONG __p96AllocBitMap_Flags __asm("d3") = (_p96AllocBitMap_Flags); \
  register struct BitMap * __p96AllocBitMap_friendBitMap __asm("a0") = (_p96AllocBitMap_friendBitMap); \
  register RGBFTYPE __p96AllocBitMap_RGBFormat __asm("d7") = (_p96AllocBitMap_RGBFormat); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__p96AllocBitMap__re) \
  : "r"(__p96AllocBitMap__bn), "r"(__p96AllocBitMap_SizeX), "r"(__p96AllocBitMap_SizeY), "r"(__p96AllocBitMap_Depth), "r"(__p96AllocBitMap_Flags), "r"(__p96AllocBitMap_friendBitMap), "r"(__p96AllocBitMap_RGBFormat) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96AllocBitMap__re; \
  }); \
  _p96AllocBitMap__re; \
})

#define p96FreeBitMap(bitMap) ({ \
  struct BitMap * _p96FreeBitMap_bitMap = (bitMap); \
  { \
  register struct Library * const __p96FreeBitMap__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct BitMap * __p96FreeBitMap_bitMap __asm("a0") = (_p96FreeBitMap_bitMap); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__p96FreeBitMap__bn), "r"(__p96FreeBitMap_bitMap) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96GetBitMapAttr(bitMap, Attribute) ({ \
  struct BitMap * _p96GetBitMapAttr_bitMap = (bitMap); \
  ULONG _p96GetBitMapAttr_Attribute = (Attribute); \
  ULONG _p96GetBitMapAttr__re = \
  ({ \
  register struct Library * const __p96GetBitMapAttr__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register ULONG __p96GetBitMapAttr__re __asm("d0"); \
  register struct BitMap * __p96GetBitMapAttr_bitMap __asm("a0") = (_p96GetBitMapAttr_bitMap); \
  register ULONG __p96GetBitMapAttr_Attribute __asm("d0") = (_p96GetBitMapAttr_Attribute); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__p96GetBitMapAttr__re) \
  : "r"(__p96GetBitMapAttr__bn), "r"(__p96GetBitMapAttr_bitMap), "r"(__p96GetBitMapAttr_Attribute) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96GetBitMapAttr__re; \
  }); \
  _p96GetBitMapAttr__re; \
})

#define p96LockBitMap(bitMap, Buffer, Size) ({ \
  struct BitMap * _p96LockBitMap_bitMap = (bitMap); \
  UBYTE * _p96LockBitMap_Buffer = (Buffer); \
  ULONG _p96LockBitMap_Size = (Size); \
  LONG _p96LockBitMap__re = \
  ({ \
  register struct Library * const __p96LockBitMap__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register LONG __p96LockBitMap__re __asm("d0"); \
  register struct BitMap * __p96LockBitMap_bitMap __asm("a0") = (_p96LockBitMap_bitMap); \
  register UBYTE * __p96LockBitMap_Buffer __asm("a1") = (_p96LockBitMap_Buffer); \
  register ULONG __p96LockBitMap_Size __asm("d0") = (_p96LockBitMap_Size); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__p96LockBitMap__re) \
  : "r"(__p96LockBitMap__bn), "r"(__p96LockBitMap_bitMap), "r"(__p96LockBitMap_Buffer), "r"(__p96LockBitMap_Size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96LockBitMap__re; \
  }); \
  _p96LockBitMap__re; \
})

#define p96UnlockBitMap(bitMap, Lock) ({ \
  struct BitMap * _p96UnlockBitMap_bitMap = (bitMap); \
  LONG _p96UnlockBitMap_Lock = (Lock); \
  { \
  register struct Library * const __p96UnlockBitMap__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct BitMap * __p96UnlockBitMap_bitMap __asm("a0") = (_p96UnlockBitMap_bitMap); \
  register LONG __p96UnlockBitMap_Lock __asm("d0") = (_p96UnlockBitMap_Lock); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__p96UnlockBitMap__bn), "r"(__p96UnlockBitMap_bitMap), "r"(__p96UnlockBitMap_Lock) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96BestModeIDTagList(Tags) ({ \
  struct TagItem * _p96BestModeIDTagList_Tags = (Tags); \
  ULONG _p96BestModeIDTagList__re = \
  ({ \
  register struct Library * const __p96BestModeIDTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register ULONG __p96BestModeIDTagList__re __asm("d0"); \
  register struct TagItem * __p96BestModeIDTagList_Tags __asm("a0") = (_p96BestModeIDTagList_Tags); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__p96BestModeIDTagList__re) \
  : "r"(__p96BestModeIDTagList__bn), "r"(__p96BestModeIDTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96BestModeIDTagList__re; \
  }); \
  _p96BestModeIDTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___p96BestModeIDTags(struct Library * P96Base, Tag Tags, ...)
{
  return p96BestModeIDTagList((struct TagItem *) &Tags);
}

#define p96BestModeIDTags(tags...) ___p96BestModeIDTags(PICASSO96API_BASE_NAME, tags)
#endif

#define p96RequestModeIDTagList(Tags) ({ \
  struct TagItem * _p96RequestModeIDTagList_Tags = (Tags); \
  ULONG _p96RequestModeIDTagList__re = \
  ({ \
  register struct Library * const __p96RequestModeIDTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register ULONG __p96RequestModeIDTagList__re __asm("d0"); \
  register struct TagItem * __p96RequestModeIDTagList_Tags __asm("a0") = (_p96RequestModeIDTagList_Tags); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__p96RequestModeIDTagList__re) \
  : "r"(__p96RequestModeIDTagList__bn), "r"(__p96RequestModeIDTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96RequestModeIDTagList__re; \
  }); \
  _p96RequestModeIDTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___p96RequestModeIDTags(struct Library * P96Base, Tag Tags, ...)
{
  return p96RequestModeIDTagList((struct TagItem *) &Tags);
}

#define p96RequestModeIDTags(tags...) ___p96RequestModeIDTags(PICASSO96API_BASE_NAME, tags)
#endif

#define p96AllocModeListTagList(Tags) ({ \
  struct TagItem * _p96AllocModeListTagList_Tags = (Tags); \
  struct List * _p96AllocModeListTagList__re = \
  ({ \
  register struct Library * const __p96AllocModeListTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct List * __p96AllocModeListTagList__re __asm("d0"); \
  register struct TagItem * __p96AllocModeListTagList_Tags __asm("a0") = (_p96AllocModeListTagList_Tags); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__p96AllocModeListTagList__re) \
  : "r"(__p96AllocModeListTagList__bn), "r"(__p96AllocModeListTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96AllocModeListTagList__re; \
  }); \
  _p96AllocModeListTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct List * ___p96AllocModeListTags(struct Library * P96Base, Tag Tags, ...)
{
  return p96AllocModeListTagList((struct TagItem *) &Tags);
}

#define p96AllocModeListTags(tags...) ___p96AllocModeListTags(PICASSO96API_BASE_NAME, tags)
#endif

#define p96FreeModeList(list) ({ \
  struct List * _p96FreeModeList_list = (list); \
  { \
  register struct Library * const __p96FreeModeList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct List * __p96FreeModeList_list __asm("a0") = (_p96FreeModeList_list); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__p96FreeModeList__bn), "r"(__p96FreeModeList_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96GetModeIDAttr(Mode, Attribute) ({ \
  ULONG _p96GetModeIDAttr_Mode = (Mode); \
  ULONG _p96GetModeIDAttr_Attribute = (Attribute); \
  ULONG _p96GetModeIDAttr__re = \
  ({ \
  register struct Library * const __p96GetModeIDAttr__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register ULONG __p96GetModeIDAttr__re __asm("d0"); \
  register ULONG __p96GetModeIDAttr_Mode __asm("d0") = (_p96GetModeIDAttr_Mode); \
  register ULONG __p96GetModeIDAttr_Attribute __asm("d1") = (_p96GetModeIDAttr_Attribute); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__p96GetModeIDAttr__re) \
  : "r"(__p96GetModeIDAttr__bn), "r"(__p96GetModeIDAttr_Mode), "r"(__p96GetModeIDAttr_Attribute) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96GetModeIDAttr__re; \
  }); \
  _p96GetModeIDAttr__re; \
})

#define p96OpenScreenTagList(Tags) ({ \
  struct TagItem * _p96OpenScreenTagList_Tags = (Tags); \
  struct Screen * _p96OpenScreenTagList__re = \
  ({ \
  register struct Library * const __p96OpenScreenTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct Screen * __p96OpenScreenTagList__re __asm("d0"); \
  register struct TagItem * __p96OpenScreenTagList_Tags __asm("a0") = (_p96OpenScreenTagList_Tags); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__p96OpenScreenTagList__re) \
  : "r"(__p96OpenScreenTagList__bn), "r"(__p96OpenScreenTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96OpenScreenTagList__re; \
  }); \
  _p96OpenScreenTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Screen * ___p96OpenScreenTags(struct Library * P96Base, Tag Tags, ...)
{
  return p96OpenScreenTagList((struct TagItem *) &Tags);
}

#define p96OpenScreenTags(tags...) ___p96OpenScreenTags(PICASSO96API_BASE_NAME, tags)
#endif

#define p96CloseScreen(screen) ({ \
  struct Screen * _p96CloseScreen_screen = (screen); \
  BOOL _p96CloseScreen__re = \
  ({ \
  register struct Library * const __p96CloseScreen__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register BOOL __p96CloseScreen__re __asm("d0"); \
  register struct Screen * __p96CloseScreen_screen __asm("a0") = (_p96CloseScreen_screen); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__p96CloseScreen__re) \
  : "r"(__p96CloseScreen__bn), "r"(__p96CloseScreen_screen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96CloseScreen__re; \
  }); \
  _p96CloseScreen__re; \
})

#define p96WritePixelArray(ri, SrcX, SrcY, rp, DestX, DestY, SizeX, SizeY) ({ \
  struct RenderInfo * _p96WritePixelArray_ri = (ri); \
  ULONG _p96WritePixelArray_SrcX = (SrcX); \
  ULONG _p96WritePixelArray_SrcY = (SrcY); \
  struct RastPort * _p96WritePixelArray_rp = (rp); \
  ULONG _p96WritePixelArray_DestX = (DestX); \
  ULONG _p96WritePixelArray_DestY = (DestY); \
  ULONG _p96WritePixelArray_SizeX = (SizeX); \
  ULONG _p96WritePixelArray_SizeY = (SizeY); \
  { \
  register struct Library * const __p96WritePixelArray__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct RenderInfo * __p96WritePixelArray_ri __asm("a0") = (_p96WritePixelArray_ri); \
  register ULONG __p96WritePixelArray_SrcX __asm("d0") = (_p96WritePixelArray_SrcX); \
  register ULONG __p96WritePixelArray_SrcY __asm("d1") = (_p96WritePixelArray_SrcY); \
  register struct RastPort * __p96WritePixelArray_rp __asm("a1") = (_p96WritePixelArray_rp); \
  register ULONG __p96WritePixelArray_DestX __asm("d2") = (_p96WritePixelArray_DestX); \
  register ULONG __p96WritePixelArray_DestY __asm("d3") = (_p96WritePixelArray_DestY); \
  register ULONG __p96WritePixelArray_SizeX __asm("d4") = (_p96WritePixelArray_SizeX); \
  register ULONG __p96WritePixelArray_SizeY __asm("d5") = (_p96WritePixelArray_SizeY); \
  __asm volatile ("jsr a6@(-102:W)" \
  : \
  : "r"(__p96WritePixelArray__bn), "r"(__p96WritePixelArray_ri), "r"(__p96WritePixelArray_SrcX), "r"(__p96WritePixelArray_SrcY), "r"(__p96WritePixelArray_rp), "r"(__p96WritePixelArray_DestX), "r"(__p96WritePixelArray_DestY), "r"(__p96WritePixelArray_SizeX), "r"(__p96WritePixelArray_SizeY) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96ReadPixelArray(ri, DestX, DestY, rp, SrcX, SrcY, SizeX, SizeY) ({ \
  struct RenderInfo * _p96ReadPixelArray_ri = (ri); \
  ULONG _p96ReadPixelArray_DestX = (DestX); \
  ULONG _p96ReadPixelArray_DestY = (DestY); \
  struct RastPort * _p96ReadPixelArray_rp = (rp); \
  ULONG _p96ReadPixelArray_SrcX = (SrcX); \
  ULONG _p96ReadPixelArray_SrcY = (SrcY); \
  ULONG _p96ReadPixelArray_SizeX = (SizeX); \
  ULONG _p96ReadPixelArray_SizeY = (SizeY); \
  { \
  register struct Library * const __p96ReadPixelArray__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct RenderInfo * __p96ReadPixelArray_ri __asm("a0") = (_p96ReadPixelArray_ri); \
  register ULONG __p96ReadPixelArray_DestX __asm("d0") = (_p96ReadPixelArray_DestX); \
  register ULONG __p96ReadPixelArray_DestY __asm("d1") = (_p96ReadPixelArray_DestY); \
  register struct RastPort * __p96ReadPixelArray_rp __asm("a1") = (_p96ReadPixelArray_rp); \
  register ULONG __p96ReadPixelArray_SrcX __asm("d2") = (_p96ReadPixelArray_SrcX); \
  register ULONG __p96ReadPixelArray_SrcY __asm("d3") = (_p96ReadPixelArray_SrcY); \
  register ULONG __p96ReadPixelArray_SizeX __asm("d4") = (_p96ReadPixelArray_SizeX); \
  register ULONG __p96ReadPixelArray_SizeY __asm("d5") = (_p96ReadPixelArray_SizeY); \
  __asm volatile ("jsr a6@(-108:W)" \
  : \
  : "r"(__p96ReadPixelArray__bn), "r"(__p96ReadPixelArray_ri), "r"(__p96ReadPixelArray_DestX), "r"(__p96ReadPixelArray_DestY), "r"(__p96ReadPixelArray_rp), "r"(__p96ReadPixelArray_SrcX), "r"(__p96ReadPixelArray_SrcY), "r"(__p96ReadPixelArray_SizeX), "r"(__p96ReadPixelArray_SizeY) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96WritePixel(rp, x, y, color) ({ \
  struct RastPort * _p96WritePixel_rp = (rp); \
  ULONG _p96WritePixel_x = (x); \
  ULONG _p96WritePixel_y = (y); \
  ULONG _p96WritePixel_color = (color); \
  ULONG _p96WritePixel__re = \
  ({ \
  register struct Library * const __p96WritePixel__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register ULONG __p96WritePixel__re __asm("d0"); \
  register struct RastPort * __p96WritePixel_rp __asm("a1") = (_p96WritePixel_rp); \
  register ULONG __p96WritePixel_x __asm("d0") = (_p96WritePixel_x); \
  register ULONG __p96WritePixel_y __asm("d1") = (_p96WritePixel_y); \
  register ULONG __p96WritePixel_color __asm("d2") = (_p96WritePixel_color); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__p96WritePixel__re) \
  : "r"(__p96WritePixel__bn), "r"(__p96WritePixel_rp), "r"(__p96WritePixel_x), "r"(__p96WritePixel_y), "r"(__p96WritePixel_color) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96WritePixel__re; \
  }); \
  _p96WritePixel__re; \
})

#define p96ReadPixel(rp, x, y) ({ \
  struct RastPort * _p96ReadPixel_rp = (rp); \
  ULONG _p96ReadPixel_x = (x); \
  ULONG _p96ReadPixel_y = (y); \
  ULONG _p96ReadPixel__re = \
  ({ \
  register struct Library * const __p96ReadPixel__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register ULONG __p96ReadPixel__re __asm("d0"); \
  register struct RastPort * __p96ReadPixel_rp __asm("a1") = (_p96ReadPixel_rp); \
  register ULONG __p96ReadPixel_x __asm("d0") = (_p96ReadPixel_x); \
  register ULONG __p96ReadPixel_y __asm("d1") = (_p96ReadPixel_y); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__p96ReadPixel__re) \
  : "r"(__p96ReadPixel__bn), "r"(__p96ReadPixel_rp), "r"(__p96ReadPixel_x), "r"(__p96ReadPixel_y) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96ReadPixel__re; \
  }); \
  _p96ReadPixel__re; \
})

#define p96RectFill(rp, MinX, MinY, MaxX, MaxY, color) ({ \
  struct RastPort * _p96RectFill_rp = (rp); \
  ULONG _p96RectFill_MinX = (MinX); \
  ULONG _p96RectFill_MinY = (MinY); \
  ULONG _p96RectFill_MaxX = (MaxX); \
  ULONG _p96RectFill_MaxY = (MaxY); \
  ULONG _p96RectFill_color = (color); \
  { \
  register struct Library * const __p96RectFill__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct RastPort * __p96RectFill_rp __asm("a1") = (_p96RectFill_rp); \
  register ULONG __p96RectFill_MinX __asm("d0") = (_p96RectFill_MinX); \
  register ULONG __p96RectFill_MinY __asm("d1") = (_p96RectFill_MinY); \
  register ULONG __p96RectFill_MaxX __asm("d2") = (_p96RectFill_MaxX); \
  register ULONG __p96RectFill_MaxY __asm("d3") = (_p96RectFill_MaxY); \
  register ULONG __p96RectFill_color __asm("d4") = (_p96RectFill_color); \
  __asm volatile ("jsr a6@(-126:W)" \
  : \
  : "r"(__p96RectFill__bn), "r"(__p96RectFill_rp), "r"(__p96RectFill_MinX), "r"(__p96RectFill_MinY), "r"(__p96RectFill_MaxX), "r"(__p96RectFill_MaxY), "r"(__p96RectFill_color) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96WriteTrueColorData(tci, SrcX, SrcY, rp, DestX, DestY, SizeX, SizeY) ({ \
  struct TrueColorInfo * _p96WriteTrueColorData_tci = (tci); \
  ULONG _p96WriteTrueColorData_SrcX = (SrcX); \
  ULONG _p96WriteTrueColorData_SrcY = (SrcY); \
  struct RastPort * _p96WriteTrueColorData_rp = (rp); \
  ULONG _p96WriteTrueColorData_DestX = (DestX); \
  ULONG _p96WriteTrueColorData_DestY = (DestY); \
  ULONG _p96WriteTrueColorData_SizeX = (SizeX); \
  ULONG _p96WriteTrueColorData_SizeY = (SizeY); \
  { \
  register struct Library * const __p96WriteTrueColorData__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct TrueColorInfo * __p96WriteTrueColorData_tci __asm("a0") = (_p96WriteTrueColorData_tci); \
  register ULONG __p96WriteTrueColorData_SrcX __asm("d0") = (_p96WriteTrueColorData_SrcX); \
  register ULONG __p96WriteTrueColorData_SrcY __asm("d1") = (_p96WriteTrueColorData_SrcY); \
  register struct RastPort * __p96WriteTrueColorData_rp __asm("a1") = (_p96WriteTrueColorData_rp); \
  register ULONG __p96WriteTrueColorData_DestX __asm("d2") = (_p96WriteTrueColorData_DestX); \
  register ULONG __p96WriteTrueColorData_DestY __asm("d3") = (_p96WriteTrueColorData_DestY); \
  register ULONG __p96WriteTrueColorData_SizeX __asm("d4") = (_p96WriteTrueColorData_SizeX); \
  register ULONG __p96WriteTrueColorData_SizeY __asm("d5") = (_p96WriteTrueColorData_SizeY); \
  __asm volatile ("jsr a6@(-132:W)" \
  : \
  : "r"(__p96WriteTrueColorData__bn), "r"(__p96WriteTrueColorData_tci), "r"(__p96WriteTrueColorData_SrcX), "r"(__p96WriteTrueColorData_SrcY), "r"(__p96WriteTrueColorData_rp), "r"(__p96WriteTrueColorData_DestX), "r"(__p96WriteTrueColorData_DestY), "r"(__p96WriteTrueColorData_SizeX), "r"(__p96WriteTrueColorData_SizeY) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96ReadTrueColorData(tci, DestX, DestY, rp, SrcX, SrcY, SizeX, SizeY) ({ \
  struct TrueColorInfo * _p96ReadTrueColorData_tci = (tci); \
  ULONG _p96ReadTrueColorData_DestX = (DestX); \
  ULONG _p96ReadTrueColorData_DestY = (DestY); \
  struct RastPort * _p96ReadTrueColorData_rp = (rp); \
  ULONG _p96ReadTrueColorData_SrcX = (SrcX); \
  ULONG _p96ReadTrueColorData_SrcY = (SrcY); \
  ULONG _p96ReadTrueColorData_SizeX = (SizeX); \
  ULONG _p96ReadTrueColorData_SizeY = (SizeY); \
  { \
  register struct Library * const __p96ReadTrueColorData__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct TrueColorInfo * __p96ReadTrueColorData_tci __asm("a0") = (_p96ReadTrueColorData_tci); \
  register ULONG __p96ReadTrueColorData_DestX __asm("d0") = (_p96ReadTrueColorData_DestX); \
  register ULONG __p96ReadTrueColorData_DestY __asm("d1") = (_p96ReadTrueColorData_DestY); \
  register struct RastPort * __p96ReadTrueColorData_rp __asm("a1") = (_p96ReadTrueColorData_rp); \
  register ULONG __p96ReadTrueColorData_SrcX __asm("d2") = (_p96ReadTrueColorData_SrcX); \
  register ULONG __p96ReadTrueColorData_SrcY __asm("d3") = (_p96ReadTrueColorData_SrcY); \
  register ULONG __p96ReadTrueColorData_SizeX __asm("d4") = (_p96ReadTrueColorData_SizeX); \
  register ULONG __p96ReadTrueColorData_SizeY __asm("d5") = (_p96ReadTrueColorData_SizeY); \
  __asm volatile ("jsr a6@(-138:W)" \
  : \
  : "r"(__p96ReadTrueColorData__bn), "r"(__p96ReadTrueColorData_tci), "r"(__p96ReadTrueColorData_DestX), "r"(__p96ReadTrueColorData_DestY), "r"(__p96ReadTrueColorData_rp), "r"(__p96ReadTrueColorData_SrcX), "r"(__p96ReadTrueColorData_SrcY), "r"(__p96ReadTrueColorData_SizeX), "r"(__p96ReadTrueColorData_SizeY) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96PIP_OpenTagList(Tags) ({ \
  struct TagItem * _p96PIP_OpenTagList_Tags = (Tags); \
  struct Window * _p96PIP_OpenTagList__re = \
  ({ \
  register struct Library * const __p96PIP_OpenTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct Window * __p96PIP_OpenTagList__re __asm("d0"); \
  register struct TagItem * __p96PIP_OpenTagList_Tags __asm("a0") = (_p96PIP_OpenTagList_Tags); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__p96PIP_OpenTagList__re) \
  : "r"(__p96PIP_OpenTagList__bn), "r"(__p96PIP_OpenTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96PIP_OpenTagList__re; \
  }); \
  _p96PIP_OpenTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Window * ___p96PIP_OpenTags(struct Library * P96Base, Tag Tags, ...)
{
  return p96PIP_OpenTagList((struct TagItem *) &Tags);
}

#define p96PIP_OpenTags(tags...) ___p96PIP_OpenTags(PICASSO96API_BASE_NAME, tags)
#endif

#define p96PIP_Close(window) ({ \
  struct Window * _p96PIP_Close_window = (window); \
  BOOL _p96PIP_Close__re = \
  ({ \
  register struct Library * const __p96PIP_Close__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register BOOL __p96PIP_Close__re __asm("d0"); \
  register struct Window * __p96PIP_Close_window __asm("a0") = (_p96PIP_Close_window); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__p96PIP_Close__re) \
  : "r"(__p96PIP_Close__bn), "r"(__p96PIP_Close_window) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96PIP_Close__re; \
  }); \
  _p96PIP_Close__re; \
})

#define p96PIP_SetTagList(window, Tags) ({ \
  struct Window * _p96PIP_SetTagList_window = (window); \
  struct TagItem * _p96PIP_SetTagList_Tags = (Tags); \
  LONG _p96PIP_SetTagList__re = \
  ({ \
  register struct Library * const __p96PIP_SetTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register LONG __p96PIP_SetTagList__re __asm("d0"); \
  register struct Window * __p96PIP_SetTagList_window __asm("a0") = (_p96PIP_SetTagList_window); \
  register struct TagItem * __p96PIP_SetTagList_Tags __asm("a1") = (_p96PIP_SetTagList_Tags); \
  __asm volatile ("jsr a6@(-156:W)" \
  : "=r"(__p96PIP_SetTagList__re) \
  : "r"(__p96PIP_SetTagList__bn), "r"(__p96PIP_SetTagList_window), "r"(__p96PIP_SetTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96PIP_SetTagList__re; \
  }); \
  _p96PIP_SetTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___p96PIP_SetTags(struct Library * P96Base, struct Window * window, Tag Tags, ...)
{
  return p96PIP_SetTagList(window, (struct TagItem *) &Tags);
}

#define p96PIP_SetTags(window...) ___p96PIP_SetTags(PICASSO96API_BASE_NAME, window)
#endif

#define p96PIP_GetTagList(window, Tags) ({ \
  struct Window * _p96PIP_GetTagList_window = (window); \
  struct TagItem * _p96PIP_GetTagList_Tags = (Tags); \
  LONG _p96PIP_GetTagList__re = \
  ({ \
  register struct Library * const __p96PIP_GetTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register LONG __p96PIP_GetTagList__re __asm("d0"); \
  register struct Window * __p96PIP_GetTagList_window __asm("a0") = (_p96PIP_GetTagList_window); \
  register struct TagItem * __p96PIP_GetTagList_Tags __asm("a1") = (_p96PIP_GetTagList_Tags); \
  __asm volatile ("jsr a6@(-162:W)" \
  : "=r"(__p96PIP_GetTagList__re) \
  : "r"(__p96PIP_GetTagList__bn), "r"(__p96PIP_GetTagList_window), "r"(__p96PIP_GetTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96PIP_GetTagList__re; \
  }); \
  _p96PIP_GetTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___p96PIP_GetTags(struct Library * P96Base, struct Window * window, Tag Tags, ...)
{
  return p96PIP_GetTagList(window, (struct TagItem *) &Tags);
}

#define p96PIP_GetTags(window...) ___p96PIP_GetTags(PICASSO96API_BASE_NAME, window)
#endif

#define p96PIP_GetIMsg(port) ({ \
  struct MsgPort * _p96PIP_GetIMsg_port = (port); \
  struct IntuiMessage * _p96PIP_GetIMsg__re = \
  ({ \
  register struct Library * const __p96PIP_GetIMsg__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct IntuiMessage * __p96PIP_GetIMsg__re __asm("d0"); \
  register struct MsgPort * __p96PIP_GetIMsg_port __asm("a0") = (_p96PIP_GetIMsg_port); \
  __asm volatile ("jsr a6@(-168:W)" \
  : "=r"(__p96PIP_GetIMsg__re) \
  : "r"(__p96PIP_GetIMsg__bn), "r"(__p96PIP_GetIMsg_port) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96PIP_GetIMsg__re; \
  }); \
  _p96PIP_GetIMsg__re; \
})

#define p96PIP_ReplyIMsg(intuiMessage) ({ \
  struct IntuiMessage * _p96PIP_ReplyIMsg_intuiMessage = (intuiMessage); \
  { \
  register struct Library * const __p96PIP_ReplyIMsg__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register struct IntuiMessage * __p96PIP_ReplyIMsg_intuiMessage __asm("a1") = (_p96PIP_ReplyIMsg_intuiMessage); \
  __asm volatile ("jsr a6@(-174:W)" \
  : \
  : "r"(__p96PIP_ReplyIMsg__bn), "r"(__p96PIP_ReplyIMsg_intuiMessage) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define p96GetRTGDataTagList(Tags) ({ \
  struct TagItem * _p96GetRTGDataTagList_Tags = (Tags); \
  LONG _p96GetRTGDataTagList__re = \
  ({ \
  register struct Library * const __p96GetRTGDataTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register LONG __p96GetRTGDataTagList__re __asm("d0"); \
  register struct TagItem * __p96GetRTGDataTagList_Tags __asm("a0") = (_p96GetRTGDataTagList_Tags); \
  __asm volatile ("jsr a6@(-180:W)" \
  : "=r"(__p96GetRTGDataTagList__re) \
  : "r"(__p96GetRTGDataTagList__bn), "r"(__p96GetRTGDataTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96GetRTGDataTagList__re; \
  }); \
  _p96GetRTGDataTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___p96GetRTGDataTags(struct Library * P96Base, Tag Tags, ...)
{
  return p96GetRTGDataTagList((struct TagItem *) &Tags);
}

#define p96GetRTGDataTags(tags...) ___p96GetRTGDataTags(PICASSO96API_BASE_NAME, tags)
#endif

#define p96GetBoardDataTagList(board, Tags) ({ \
  ULONG _p96GetBoardDataTagList_board = (board); \
  struct TagItem * _p96GetBoardDataTagList_Tags = (Tags); \
  LONG _p96GetBoardDataTagList__re = \
  ({ \
  register struct Library * const __p96GetBoardDataTagList__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register LONG __p96GetBoardDataTagList__re __asm("d0"); \
  register ULONG __p96GetBoardDataTagList_board __asm("d0") = (_p96GetBoardDataTagList_board); \
  register struct TagItem * __p96GetBoardDataTagList_Tags __asm("a0") = (_p96GetBoardDataTagList_Tags); \
  __asm volatile ("jsr a6@(-186:W)" \
  : "=r"(__p96GetBoardDataTagList__re) \
  : "r"(__p96GetBoardDataTagList__bn), "r"(__p96GetBoardDataTagList_board), "r"(__p96GetBoardDataTagList_Tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96GetBoardDataTagList__re; \
  }); \
  _p96GetBoardDataTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___p96GetBoardDataTags(struct Library * P96Base, ULONG board, Tag Tags, ...)
{
  return p96GetBoardDataTagList(board, (struct TagItem *) &Tags);
}

#define p96GetBoardDataTags(board...) ___p96GetBoardDataTags(PICASSO96API_BASE_NAME, board)
#endif

#define p96EncodeColor(RGBFormat, Color) ({ \
  RGBFTYPE _p96EncodeColor_RGBFormat = (RGBFormat); \
  ULONG _p96EncodeColor_Color = (Color); \
  ULONG _p96EncodeColor__re = \
  ({ \
  register struct Library * const __p96EncodeColor__bn __asm("a6") = (struct Library *) (PICASSO96API_BASE_NAME);\
  register ULONG __p96EncodeColor__re __asm("d0"); \
  register RGBFTYPE __p96EncodeColor_RGBFormat __asm("d0") = (_p96EncodeColor_RGBFormat); \
  register ULONG __p96EncodeColor_Color __asm("d1") = (_p96EncodeColor_Color); \
  __asm volatile ("jsr a6@(-192:W)" \
  : "=r"(__p96EncodeColor__re) \
  : "r"(__p96EncodeColor__bn), "r"(__p96EncodeColor_RGBFormat), "r"(__p96EncodeColor_Color) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __p96EncodeColor__re; \
  }); \
  _p96EncodeColor__re; \
})

#endif /*  _INLINE_PICASSO96API_H  */
