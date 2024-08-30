#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CYBERGRAPHICS_H
#define _INLINE_CYBERGRAPHICS_H

#ifndef CLIB_CYBERGRAPHICS_PROTOS_H
#define CLIB_CYBERGRAPHICS_PROTOS_H
#endif

#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef  GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef CYBERGRAPHICS_BASE_NAME
#define CYBERGRAPHICS_BASE_NAME CyberGfxBase
#endif

#define IsCyberModeID(displayID) ({ \
  ULONG _IsCyberModeID_displayID = (displayID); \
  BOOL _IsCyberModeID__re = \
  ({ \
  register struct Library * const __IsCyberModeID__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register BOOL __IsCyberModeID__re __asm("d0"); \
  register ULONG __IsCyberModeID_displayID __asm("d0") = (_IsCyberModeID_displayID); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__IsCyberModeID__re) \
  : "r"(__IsCyberModeID__bn), "r"(__IsCyberModeID_displayID) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsCyberModeID__re; \
  }); \
  _IsCyberModeID__re; \
})

#define BestCModeIDTagList(BestModeIDTags) ({ \
  struct TagItem * _BestCModeIDTagList_BestModeIDTags = (BestModeIDTags); \
  ULONG _BestCModeIDTagList__re = \
  ({ \
  register struct Library * const __BestCModeIDTagList__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __BestCModeIDTagList__re __asm("d0"); \
  register struct TagItem * __BestCModeIDTagList_BestModeIDTags __asm("a0") = (_BestCModeIDTagList_BestModeIDTags); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__BestCModeIDTagList__re) \
  : "r"(__BestCModeIDTagList__bn), "r"(__BestCModeIDTagList_BestModeIDTags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BestCModeIDTagList__re; \
  }); \
  _BestCModeIDTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___BestCModeIDTags(struct Library * CyberGfxBase, ULONG tag, ...)
{
  return BestCModeIDTagList((struct TagItem *) &tag);
}

#define BestCModeIDTags(tags...) ___BestCModeIDTags(CYBERGRAPHICS_BASE_NAME, tags)
#endif

#define CModeRequestTagList(ModeRequest, ModeRequestTags) ({ \
  APTR _CModeRequestTagList_ModeRequest = (ModeRequest); \
  struct TagItem * _CModeRequestTagList_ModeRequestTags = (ModeRequestTags); \
  ULONG _CModeRequestTagList__re = \
  ({ \
  register struct Library * const __CModeRequestTagList__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __CModeRequestTagList__re __asm("d0"); \
  register APTR __CModeRequestTagList_ModeRequest __asm("a0") = (_CModeRequestTagList_ModeRequest); \
  register struct TagItem * __CModeRequestTagList_ModeRequestTags __asm("a1") = (_CModeRequestTagList_ModeRequestTags); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__CModeRequestTagList__re) \
  : "r"(__CModeRequestTagList__bn), "r"(__CModeRequestTagList_ModeRequest), "r"(__CModeRequestTagList_ModeRequestTags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CModeRequestTagList__re; \
  }); \
  _CModeRequestTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___CModeRequestTags(struct Library * CyberGfxBase, APTR ModeRequest, ...)
{
  return CModeRequestTagList(ModeRequest, (struct TagItem *) ((ULONG) &ModeRequest + sizeof(APTR)));
}

#define CModeRequestTags(ModeRequest...) ___CModeRequestTags(CYBERGRAPHICS_BASE_NAME, ModeRequest)
#endif

#define AllocCModeListTagList(ModeListTags) ({ \
  struct TagItem * _AllocCModeListTagList_ModeListTags = (ModeListTags); \
  struct List * _AllocCModeListTagList__re = \
  ({ \
  register struct Library * const __AllocCModeListTagList__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register struct List * __AllocCModeListTagList__re __asm("d0"); \
  register struct TagItem * __AllocCModeListTagList_ModeListTags __asm("a1") = (_AllocCModeListTagList_ModeListTags); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__AllocCModeListTagList__re) \
  : "r"(__AllocCModeListTagList__bn), "r"(__AllocCModeListTagList_ModeListTags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocCModeListTagList__re; \
  }); \
  _AllocCModeListTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct List * ___AllocCModeListTags(struct Library * CyberGfxBase, ULONG tag, ...)
{
  return AllocCModeListTagList((struct TagItem *) &tag);
}

#define AllocCModeListTags(tags...) ___AllocCModeListTags(CYBERGRAPHICS_BASE_NAME, tags)
#endif

#define FreeCModeList(ModeList) ({ \
  struct List * _FreeCModeList_ModeList = (ModeList); \
  { \
  register struct Library * const __FreeCModeList__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register struct List * __FreeCModeList_ModeList __asm("a0") = (_FreeCModeList_ModeList); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__FreeCModeList__bn), "r"(__FreeCModeList_ModeList) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ScalePixelArray(srcRect, SrcW, SrcH, SrcMod, a1arg, DestX, DestY, DestW, DestH, SrcFormat) ({ \
  APTR _ScalePixelArray_srcRect = (srcRect); \
  ULONG _ScalePixelArray_SrcW = (SrcW); \
  ULONG _ScalePixelArray_SrcH = (SrcH); \
  ULONG _ScalePixelArray_SrcMod = (SrcMod); \
  struct RastPort * _ScalePixelArray_a1arg = (a1arg); \
  ULONG _ScalePixelArray_DestX = (DestX); \
  ULONG _ScalePixelArray_DestY = (DestY); \
  ULONG _ScalePixelArray_DestW = (DestW); \
  ULONG _ScalePixelArray_DestH = (DestH); \
  ULONG _ScalePixelArray_SrcFormat = (SrcFormat); \
  LONG _ScalePixelArray__re = \
  ({ \
  register struct Library * const __ScalePixelArray__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register LONG __ScalePixelArray__re __asm("d0"); \
  register APTR __ScalePixelArray_srcRect __asm("a0") = (_ScalePixelArray_srcRect); \
  register ULONG __ScalePixelArray_SrcW __asm("d0") = (_ScalePixelArray_SrcW); \
  register ULONG __ScalePixelArray_SrcH __asm("d1") = (_ScalePixelArray_SrcH); \
  register ULONG __ScalePixelArray_SrcMod __asm("d2") = (_ScalePixelArray_SrcMod); \
  register struct RastPort * __ScalePixelArray_a1arg __asm("a1") = (_ScalePixelArray_a1arg); \
  register ULONG __ScalePixelArray_DestX __asm("d3") = (_ScalePixelArray_DestX); \
  register ULONG __ScalePixelArray_DestY __asm("d4") = (_ScalePixelArray_DestY); \
  register ULONG __ScalePixelArray_DestW __asm("d5") = (_ScalePixelArray_DestW); \
  register ULONG __ScalePixelArray_DestH __asm("d6") = (_ScalePixelArray_DestH); \
  register ULONG __ScalePixelArray_SrcFormat __asm("d7") = (_ScalePixelArray_SrcFormat); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__ScalePixelArray__re) \
  : "r"(__ScalePixelArray__bn), "r"(__ScalePixelArray_srcRect), "r"(__ScalePixelArray_SrcW), "r"(__ScalePixelArray_SrcH), "r"(__ScalePixelArray_SrcMod), "r"(__ScalePixelArray_a1arg), "r"(__ScalePixelArray_DestX), "r"(__ScalePixelArray_DestY), "r"(__ScalePixelArray_DestW), "r"(__ScalePixelArray_DestH), "r"(__ScalePixelArray_SrcFormat) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ScalePixelArray__re; \
  }); \
  _ScalePixelArray__re; \
})

#define GetCyberMapAttr(CyberGfxBitmap, CyberAttrTag) ({ \
  struct BitMap * _GetCyberMapAttr_CyberGfxBitmap = (CyberGfxBitmap); \
  ULONG _GetCyberMapAttr_CyberAttrTag = (CyberAttrTag); \
  ULONG _GetCyberMapAttr__re = \
  ({ \
  register struct Library * const __GetCyberMapAttr__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __GetCyberMapAttr__re __asm("d0"); \
  register struct BitMap * __GetCyberMapAttr_CyberGfxBitmap __asm("a0") = (_GetCyberMapAttr_CyberGfxBitmap); \
  register ULONG __GetCyberMapAttr_CyberAttrTag __asm("d0") = (_GetCyberMapAttr_CyberAttrTag); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__GetCyberMapAttr__re) \
  : "r"(__GetCyberMapAttr__bn), "r"(__GetCyberMapAttr_CyberGfxBitmap), "r"(__GetCyberMapAttr_CyberAttrTag) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetCyberMapAttr__re; \
  }); \
  _GetCyberMapAttr__re; \
})

#define GetCyberIDAttr(CyberIDAttr, CyberDisplayModeID) ({ \
  ULONG _GetCyberIDAttr_CyberIDAttr = (CyberIDAttr); \
  ULONG _GetCyberIDAttr_CyberDisplayModeID = (CyberDisplayModeID); \
  ULONG _GetCyberIDAttr__re = \
  ({ \
  register struct Library * const __GetCyberIDAttr__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __GetCyberIDAttr__re __asm("d0"); \
  register ULONG __GetCyberIDAttr_CyberIDAttr __asm("d0") = (_GetCyberIDAttr_CyberIDAttr); \
  register ULONG __GetCyberIDAttr_CyberDisplayModeID __asm("d1") = (_GetCyberIDAttr_CyberDisplayModeID); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__GetCyberIDAttr__re) \
  : "r"(__GetCyberIDAttr__bn), "r"(__GetCyberIDAttr_CyberIDAttr), "r"(__GetCyberIDAttr_CyberDisplayModeID) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetCyberIDAttr__re; \
  }); \
  _GetCyberIDAttr__re; \
})

#define ReadRGBPixel(a1arg, x, y) ({ \
  struct RastPort * _ReadRGBPixel_a1arg = (a1arg); \
  ULONG _ReadRGBPixel_x = (x); \
  ULONG _ReadRGBPixel_y = (y); \
  ULONG _ReadRGBPixel__re = \
  ({ \
  register struct Library * const __ReadRGBPixel__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __ReadRGBPixel__re __asm("d0"); \
  register struct RastPort * __ReadRGBPixel_a1arg __asm("a1") = (_ReadRGBPixel_a1arg); \
  register ULONG __ReadRGBPixel_x __asm("d0") = (_ReadRGBPixel_x); \
  register ULONG __ReadRGBPixel_y __asm("d1") = (_ReadRGBPixel_y); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__ReadRGBPixel__re) \
  : "r"(__ReadRGBPixel__bn), "r"(__ReadRGBPixel_a1arg), "r"(__ReadRGBPixel_x), "r"(__ReadRGBPixel_y) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadRGBPixel__re; \
  }); \
  _ReadRGBPixel__re; \
})

#define WriteRGBPixel(a1arg, x, y, argb) ({ \
  struct RastPort * _WriteRGBPixel_a1arg = (a1arg); \
  ULONG _WriteRGBPixel_x = (x); \
  ULONG _WriteRGBPixel_y = (y); \
  ULONG _WriteRGBPixel_argb = (argb); \
  LONG _WriteRGBPixel__re = \
  ({ \
  register struct Library * const __WriteRGBPixel__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register LONG __WriteRGBPixel__re __asm("d0"); \
  register struct RastPort * __WriteRGBPixel_a1arg __asm("a1") = (_WriteRGBPixel_a1arg); \
  register ULONG __WriteRGBPixel_x __asm("d0") = (_WriteRGBPixel_x); \
  register ULONG __WriteRGBPixel_y __asm("d1") = (_WriteRGBPixel_y); \
  register ULONG __WriteRGBPixel_argb __asm("d2") = (_WriteRGBPixel_argb); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__WriteRGBPixel__re) \
  : "r"(__WriteRGBPixel__bn), "r"(__WriteRGBPixel_a1arg), "r"(__WriteRGBPixel_x), "r"(__WriteRGBPixel_y), "r"(__WriteRGBPixel_argb) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WriteRGBPixel__re; \
  }); \
  _WriteRGBPixel__re; \
})

#define ReadPixelArray(destRect, destX, destY, destMod, a1arg, SrcX, SrcY, SizeX, SizeY, DestFormat) ({ \
  APTR _ReadPixelArray_destRect = (destRect); \
  ULONG _ReadPixelArray_destX = (destX); \
  ULONG _ReadPixelArray_destY = (destY); \
  ULONG _ReadPixelArray_destMod = (destMod); \
  struct RastPort * _ReadPixelArray_a1arg = (a1arg); \
  ULONG _ReadPixelArray_SrcX = (SrcX); \
  ULONG _ReadPixelArray_SrcY = (SrcY); \
  ULONG _ReadPixelArray_SizeX = (SizeX); \
  ULONG _ReadPixelArray_SizeY = (SizeY); \
  ULONG _ReadPixelArray_DestFormat = (DestFormat); \
  ULONG _ReadPixelArray__re = \
  ({ \
  register struct Library * const __ReadPixelArray__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __ReadPixelArray__re __asm("d0"); \
  register APTR __ReadPixelArray_destRect __asm("a0") = (_ReadPixelArray_destRect); \
  register ULONG __ReadPixelArray_destX __asm("d0") = (_ReadPixelArray_destX); \
  register ULONG __ReadPixelArray_destY __asm("d1") = (_ReadPixelArray_destY); \
  register ULONG __ReadPixelArray_destMod __asm("d2") = (_ReadPixelArray_destMod); \
  register struct RastPort * __ReadPixelArray_a1arg __asm("a1") = (_ReadPixelArray_a1arg); \
  register ULONG __ReadPixelArray_SrcX __asm("d3") = (_ReadPixelArray_SrcX); \
  register ULONG __ReadPixelArray_SrcY __asm("d4") = (_ReadPixelArray_SrcY); \
  register ULONG __ReadPixelArray_SizeX __asm("d5") = (_ReadPixelArray_SizeX); \
  register ULONG __ReadPixelArray_SizeY __asm("d6") = (_ReadPixelArray_SizeY); \
  register ULONG __ReadPixelArray_DestFormat __asm("d7") = (_ReadPixelArray_DestFormat); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__ReadPixelArray__re) \
  : "r"(__ReadPixelArray__bn), "r"(__ReadPixelArray_destRect), "r"(__ReadPixelArray_destX), "r"(__ReadPixelArray_destY), "r"(__ReadPixelArray_destMod), "r"(__ReadPixelArray_a1arg), "r"(__ReadPixelArray_SrcX), "r"(__ReadPixelArray_SrcY), "r"(__ReadPixelArray_SizeX), "r"(__ReadPixelArray_SizeY), "r"(__ReadPixelArray_DestFormat) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadPixelArray__re; \
  }); \
  _ReadPixelArray__re; \
})

#define WritePixelArray(srcRect, SrcX, SrcY, SrcMod, a1arg, DestX, DestY, SizeX, SizeY, SrcFormat) ({ \
  APTR _WritePixelArray_srcRect = (srcRect); \
  ULONG _WritePixelArray_SrcX = (SrcX); \
  ULONG _WritePixelArray_SrcY = (SrcY); \
  ULONG _WritePixelArray_SrcMod = (SrcMod); \
  struct RastPort * _WritePixelArray_a1arg = (a1arg); \
  ULONG _WritePixelArray_DestX = (DestX); \
  ULONG _WritePixelArray_DestY = (DestY); \
  ULONG _WritePixelArray_SizeX = (SizeX); \
  ULONG _WritePixelArray_SizeY = (SizeY); \
  ULONG _WritePixelArray_SrcFormat = (SrcFormat); \
  ULONG _WritePixelArray__re = \
  ({ \
  register struct Library * const __WritePixelArray__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __WritePixelArray__re __asm("d0"); \
  register APTR __WritePixelArray_srcRect __asm("a0") = (_WritePixelArray_srcRect); \
  register ULONG __WritePixelArray_SrcX __asm("d0") = (_WritePixelArray_SrcX); \
  register ULONG __WritePixelArray_SrcY __asm("d1") = (_WritePixelArray_SrcY); \
  register ULONG __WritePixelArray_SrcMod __asm("d2") = (_WritePixelArray_SrcMod); \
  register struct RastPort * __WritePixelArray_a1arg __asm("a1") = (_WritePixelArray_a1arg); \
  register ULONG __WritePixelArray_DestX __asm("d3") = (_WritePixelArray_DestX); \
  register ULONG __WritePixelArray_DestY __asm("d4") = (_WritePixelArray_DestY); \
  register ULONG __WritePixelArray_SizeX __asm("d5") = (_WritePixelArray_SizeX); \
  register ULONG __WritePixelArray_SizeY __asm("d6") = (_WritePixelArray_SizeY); \
  register ULONG __WritePixelArray_SrcFormat __asm("d7") = (_WritePixelArray_SrcFormat); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__WritePixelArray__re) \
  : "r"(__WritePixelArray__bn), "r"(__WritePixelArray_srcRect), "r"(__WritePixelArray_SrcX), "r"(__WritePixelArray_SrcY), "r"(__WritePixelArray_SrcMod), "r"(__WritePixelArray_a1arg), "r"(__WritePixelArray_DestX), "r"(__WritePixelArray_DestY), "r"(__WritePixelArray_SizeX), "r"(__WritePixelArray_SizeY), "r"(__WritePixelArray_SrcFormat) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WritePixelArray__re; \
  }); \
  _WritePixelArray__re; \
})

#define MovePixelArray(SrcX, SrcY, a1arg, DestX, DestY, SizeX, SizeY) ({ \
  ULONG _MovePixelArray_SrcX = (SrcX); \
  ULONG _MovePixelArray_SrcY = (SrcY); \
  struct RastPort * _MovePixelArray_a1arg = (a1arg); \
  ULONG _MovePixelArray_DestX = (DestX); \
  ULONG _MovePixelArray_DestY = (DestY); \
  ULONG _MovePixelArray_SizeX = (SizeX); \
  ULONG _MovePixelArray_SizeY = (SizeY); \
  ULONG _MovePixelArray__re = \
  ({ \
  register struct Library * const __MovePixelArray__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __MovePixelArray__re __asm("d0"); \
  register ULONG __MovePixelArray_SrcX __asm("d0") = (_MovePixelArray_SrcX); \
  register ULONG __MovePixelArray_SrcY __asm("d1") = (_MovePixelArray_SrcY); \
  register struct RastPort * __MovePixelArray_a1arg __asm("a1") = (_MovePixelArray_a1arg); \
  register ULONG __MovePixelArray_DestX __asm("d2") = (_MovePixelArray_DestX); \
  register ULONG __MovePixelArray_DestY __asm("d3") = (_MovePixelArray_DestY); \
  register ULONG __MovePixelArray_SizeX __asm("d4") = (_MovePixelArray_SizeX); \
  register ULONG __MovePixelArray_SizeY __asm("d5") = (_MovePixelArray_SizeY); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__MovePixelArray__re) \
  : "r"(__MovePixelArray__bn), "r"(__MovePixelArray_SrcX), "r"(__MovePixelArray_SrcY), "r"(__MovePixelArray_a1arg), "r"(__MovePixelArray_DestX), "r"(__MovePixelArray_DestY), "r"(__MovePixelArray_SizeX), "r"(__MovePixelArray_SizeY) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MovePixelArray__re; \
  }); \
  _MovePixelArray__re; \
})

#define InvertPixelArray(a1arg, DestX, DestY, SizeX, SizeY) ({ \
  struct RastPort * _InvertPixelArray_a1arg = (a1arg); \
  ULONG _InvertPixelArray_DestX = (DestX); \
  ULONG _InvertPixelArray_DestY = (DestY); \
  ULONG _InvertPixelArray_SizeX = (SizeX); \
  ULONG _InvertPixelArray_SizeY = (SizeY); \
  ULONG _InvertPixelArray__re = \
  ({ \
  register struct Library * const __InvertPixelArray__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __InvertPixelArray__re __asm("d0"); \
  register struct RastPort * __InvertPixelArray_a1arg __asm("a1") = (_InvertPixelArray_a1arg); \
  register ULONG __InvertPixelArray_DestX __asm("d0") = (_InvertPixelArray_DestX); \
  register ULONG __InvertPixelArray_DestY __asm("d1") = (_InvertPixelArray_DestY); \
  register ULONG __InvertPixelArray_SizeX __asm("d2") = (_InvertPixelArray_SizeX); \
  register ULONG __InvertPixelArray_SizeY __asm("d3") = (_InvertPixelArray_SizeY); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__InvertPixelArray__re) \
  : "r"(__InvertPixelArray__bn), "r"(__InvertPixelArray_a1arg), "r"(__InvertPixelArray_DestX), "r"(__InvertPixelArray_DestY), "r"(__InvertPixelArray_SizeX), "r"(__InvertPixelArray_SizeY) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __InvertPixelArray__re; \
  }); \
  _InvertPixelArray__re; \
})

#define FillPixelArray(a1arg, DestX, DestY, SizeX, SizeY, argb) ({ \
  struct RastPort * _FillPixelArray_a1arg = (a1arg); \
  ULONG _FillPixelArray_DestX = (DestX); \
  ULONG _FillPixelArray_DestY = (DestY); \
  ULONG _FillPixelArray_SizeX = (SizeX); \
  ULONG _FillPixelArray_SizeY = (SizeY); \
  ULONG _FillPixelArray_argb = (argb); \
  ULONG _FillPixelArray__re = \
  ({ \
  register struct Library * const __FillPixelArray__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __FillPixelArray__re __asm("d0"); \
  register struct RastPort * __FillPixelArray_a1arg __asm("a1") = (_FillPixelArray_a1arg); \
  register ULONG __FillPixelArray_DestX __asm("d0") = (_FillPixelArray_DestX); \
  register ULONG __FillPixelArray_DestY __asm("d1") = (_FillPixelArray_DestY); \
  register ULONG __FillPixelArray_SizeX __asm("d2") = (_FillPixelArray_SizeX); \
  register ULONG __FillPixelArray_SizeY __asm("d3") = (_FillPixelArray_SizeY); \
  register ULONG __FillPixelArray_argb __asm("d4") = (_FillPixelArray_argb); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__FillPixelArray__re) \
  : "r"(__FillPixelArray__bn), "r"(__FillPixelArray_a1arg), "r"(__FillPixelArray_DestX), "r"(__FillPixelArray_DestY), "r"(__FillPixelArray_SizeX), "r"(__FillPixelArray_SizeY), "r"(__FillPixelArray_argb) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FillPixelArray__re; \
  }); \
  _FillPixelArray__re; \
})

#define DoCDrawMethodTagList(hook, a1arg, TagList) ({ \
  struct Hook * _DoCDrawMethodTagList_hook = (hook); \
  struct RastPort * _DoCDrawMethodTagList_a1arg = (a1arg); \
  struct TagItem * _DoCDrawMethodTagList_TagList = (TagList); \
  { \
  register struct Library * const __DoCDrawMethodTagList__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register struct Hook * __DoCDrawMethodTagList_hook __asm("a0") = (_DoCDrawMethodTagList_hook); \
  register struct RastPort * __DoCDrawMethodTagList_a1arg __asm("a1") = (_DoCDrawMethodTagList_a1arg); \
  register struct TagItem * __DoCDrawMethodTagList_TagList __asm("a2") = (_DoCDrawMethodTagList_TagList); \
  __asm volatile ("jsr a6@(-156:W)" \
  : \
  : "r"(__DoCDrawMethodTagList__bn), "r"(__DoCDrawMethodTagList_hook), "r"(__DoCDrawMethodTagList_a1arg), "r"(__DoCDrawMethodTagList_TagList) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___DoCDrawMethodTags(struct Library * CyberGfxBase, struct Hook * hook, struct RastPort * a1arg, ...)
{
  DoCDrawMethodTagList(hook, a1arg, (struct TagItem *) ((ULONG) &a1arg + sizeof(struct RastPort *)));
}

#define DoCDrawMethodTags(hook, a1arg...) ___DoCDrawMethodTags(CYBERGRAPHICS_BASE_NAME, hook, a1arg)
#endif

#define CVideoCtrlTagList(ViewPort, TagList) ({ \
  struct ViewPort * _CVideoCtrlTagList_ViewPort = (ViewPort); \
  struct TagItem * _CVideoCtrlTagList_TagList = (TagList); \
  { \
  register struct Library * const __CVideoCtrlTagList__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register struct ViewPort * __CVideoCtrlTagList_ViewPort __asm("a0") = (_CVideoCtrlTagList_ViewPort); \
  register struct TagItem * __CVideoCtrlTagList_TagList __asm("a1") = (_CVideoCtrlTagList_TagList); \
  __asm volatile ("jsr a6@(-162:W)" \
  : \
  : "r"(__CVideoCtrlTagList__bn), "r"(__CVideoCtrlTagList_ViewPort), "r"(__CVideoCtrlTagList_TagList) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___CVideoCtrlTags(struct Library * CyberGfxBase, struct ViewPort * ViewPort, ...)
{
  CVideoCtrlTagList(ViewPort, (struct TagItem *) ((ULONG) &ViewPort + sizeof(struct ViewPort *)));
}

#define CVideoCtrlTags(ViewPort...) ___CVideoCtrlTags(CYBERGRAPHICS_BASE_NAME, ViewPort)
#endif

#define LockBitMapTagList(BitMap, TagList) ({ \
  APTR _LockBitMapTagList_BitMap = (BitMap); \
  struct TagItem * _LockBitMapTagList_TagList = (TagList); \
  APTR _LockBitMapTagList__re = \
  ({ \
  register struct Library * const __LockBitMapTagList__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register APTR __LockBitMapTagList__re __asm("d0"); \
  register APTR __LockBitMapTagList_BitMap __asm("a0") = (_LockBitMapTagList_BitMap); \
  register struct TagItem * __LockBitMapTagList_TagList __asm("a1") = (_LockBitMapTagList_TagList); \
  __asm volatile ("jsr a6@(-168:W)" \
  : "=r"(__LockBitMapTagList__re) \
  : "r"(__LockBitMapTagList__bn), "r"(__LockBitMapTagList_BitMap), "r"(__LockBitMapTagList_TagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockBitMapTagList__re; \
  }); \
  _LockBitMapTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___LockBitMapTags(struct Library * CyberGfxBase, APTR BitMap, ...)
{
  return LockBitMapTagList(BitMap, (struct TagItem *) ((ULONG) &BitMap + sizeof(APTR)));
}

#define LockBitMapTags(BitMap...) ___LockBitMapTags(CYBERGRAPHICS_BASE_NAME, BitMap)
#endif

#define UnLockBitMap(Handle) ({ \
  APTR _UnLockBitMap_Handle = (Handle); \
  { \
  register struct Library * const __UnLockBitMap__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register APTR __UnLockBitMap_Handle __asm("a0") = (_UnLockBitMap_Handle); \
  __asm volatile ("jsr a6@(-174:W)" \
  : \
  : "r"(__UnLockBitMap__bn), "r"(__UnLockBitMap_Handle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define UnLockBitMapTagList(Handle, TagList) ({ \
  APTR _UnLockBitMapTagList_Handle = (Handle); \
  struct TagItem * _UnLockBitMapTagList_TagList = (TagList); \
  { \
  register struct Library * const __UnLockBitMapTagList__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register APTR __UnLockBitMapTagList_Handle __asm("a0") = (_UnLockBitMapTagList_Handle); \
  register struct TagItem * __UnLockBitMapTagList_TagList __asm("a1") = (_UnLockBitMapTagList_TagList); \
  __asm volatile ("jsr a6@(-180:W)" \
  : \
  : "r"(__UnLockBitMapTagList__bn), "r"(__UnLockBitMapTagList_Handle), "r"(__UnLockBitMapTagList_TagList) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___UnLockBitMapTags(struct Library * CyberGfxBase, APTR Handle, ...)
{
  UnLockBitMapTagList(Handle, (struct TagItem *) ((ULONG) &Handle + sizeof(APTR)));
}

#define UnLockBitMapTags(Handle...) ___UnLockBitMapTags(CYBERGRAPHICS_BASE_NAME, Handle)
#endif

#define ExtractColor(a0arg, BitMap, Colour, SrcX, SrcY, Width, Height) ({ \
  struct RastPort * _ExtractColor_a0arg = (a0arg); \
  struct BitMap * _ExtractColor_BitMap = (BitMap); \
  ULONG _ExtractColor_Colour = (Colour); \
  ULONG _ExtractColor_SrcX = (SrcX); \
  ULONG _ExtractColor_SrcY = (SrcY); \
  ULONG _ExtractColor_Width = (Width); \
  ULONG _ExtractColor_Height = (Height); \
  ULONG _ExtractColor__re = \
  ({ \
  register struct Library * const __ExtractColor__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __ExtractColor__re __asm("d0"); \
  register struct RastPort * __ExtractColor_a0arg __asm("a0") = (_ExtractColor_a0arg); \
  register struct BitMap * __ExtractColor_BitMap __asm("a1") = (_ExtractColor_BitMap); \
  register ULONG __ExtractColor_Colour __asm("d0") = (_ExtractColor_Colour); \
  register ULONG __ExtractColor_SrcX __asm("d1") = (_ExtractColor_SrcX); \
  register ULONG __ExtractColor_SrcY __asm("d2") = (_ExtractColor_SrcY); \
  register ULONG __ExtractColor_Width __asm("d3") = (_ExtractColor_Width); \
  register ULONG __ExtractColor_Height __asm("d4") = (_ExtractColor_Height); \
  __asm volatile ("jsr a6@(-186:W)" \
  : "=r"(__ExtractColor__re) \
  : "r"(__ExtractColor__bn), "r"(__ExtractColor_a0arg), "r"(__ExtractColor_BitMap), "r"(__ExtractColor_Colour), "r"(__ExtractColor_SrcX), "r"(__ExtractColor_SrcY), "r"(__ExtractColor_Width), "r"(__ExtractColor_Height) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ExtractColor__re; \
  }); \
  _ExtractColor__re; \
})

#define WriteLUTPixelArray(srcRect, SrcX, SrcY, SrcMod, a1arg, ColorTab, DestX, DestY, SizeX, SizeY, CTFormat) ({ \
  APTR _WriteLUTPixelArray_srcRect = (srcRect); \
  ULONG _WriteLUTPixelArray_SrcX = (SrcX); \
  ULONG _WriteLUTPixelArray_SrcY = (SrcY); \
  ULONG _WriteLUTPixelArray_SrcMod = (SrcMod); \
  struct RastPort * _WriteLUTPixelArray_a1arg = (a1arg); \
  APTR _WriteLUTPixelArray_ColorTab = (ColorTab); \
  ULONG _WriteLUTPixelArray_DestX = (DestX); \
  ULONG _WriteLUTPixelArray_DestY = (DestY); \
  ULONG _WriteLUTPixelArray_SizeX = (SizeX); \
  ULONG _WriteLUTPixelArray_SizeY = (SizeY); \
  ULONG _WriteLUTPixelArray_CTFormat = (CTFormat); \
  ULONG _WriteLUTPixelArray__re = \
  ({ \
  register struct Library * const __WriteLUTPixelArray__bn __asm("a6") = (struct Library *) (CYBERGRAPHICS_BASE_NAME);\
  register ULONG __WriteLUTPixelArray__re __asm("d0"); \
  register APTR __WriteLUTPixelArray_srcRect __asm("a0") = (_WriteLUTPixelArray_srcRect); \
  register ULONG __WriteLUTPixelArray_SrcX __asm("d0") = (_WriteLUTPixelArray_SrcX); \
  register ULONG __WriteLUTPixelArray_SrcY __asm("d1") = (_WriteLUTPixelArray_SrcY); \
  register ULONG __WriteLUTPixelArray_SrcMod __asm("d2") = (_WriteLUTPixelArray_SrcMod); \
  register struct RastPort * __WriteLUTPixelArray_a1arg __asm("a1") = (_WriteLUTPixelArray_a1arg); \
  register APTR __WriteLUTPixelArray_ColorTab __asm("a2") = (_WriteLUTPixelArray_ColorTab); \
  register ULONG __WriteLUTPixelArray_DestX __asm("d3") = (_WriteLUTPixelArray_DestX); \
  register ULONG __WriteLUTPixelArray_DestY __asm("d4") = (_WriteLUTPixelArray_DestY); \
  register ULONG __WriteLUTPixelArray_SizeX __asm("d5") = (_WriteLUTPixelArray_SizeX); \
  register ULONG __WriteLUTPixelArray_SizeY __asm("d6") = (_WriteLUTPixelArray_SizeY); \
  register ULONG __WriteLUTPixelArray_CTFormat __asm("d7") = (_WriteLUTPixelArray_CTFormat); \
  __asm volatile ("jsr a6@(-198:W)" \
  : "=r"(__WriteLUTPixelArray__re) \
  : "r"(__WriteLUTPixelArray__bn), "r"(__WriteLUTPixelArray_srcRect), "r"(__WriteLUTPixelArray_SrcX), "r"(__WriteLUTPixelArray_SrcY), "r"(__WriteLUTPixelArray_SrcMod), "r"(__WriteLUTPixelArray_a1arg), "r"(__WriteLUTPixelArray_ColorTab), "r"(__WriteLUTPixelArray_DestX), "r"(__WriteLUTPixelArray_DestY), "r"(__WriteLUTPixelArray_SizeX), "r"(__WriteLUTPixelArray_SizeY), "r"(__WriteLUTPixelArray_CTFormat) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WriteLUTPixelArray__re; \
  }); \
  _WriteLUTPixelArray__re; \
})

#endif /*  _INLINE_CYBERGRAPHICS_H  */
