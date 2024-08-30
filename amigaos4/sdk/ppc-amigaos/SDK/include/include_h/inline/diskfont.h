#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_DISKFONT_H
#define _INLINE_DISKFONT_H

#ifndef CLIB_DISKFONT_PROTOS_H
#define CLIB_DISKFONT_PROTOS_H
#endif

#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  LIBRARIES_DISKFONT_H
#include <libraries/diskfont.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif

#ifndef DISKFONT_BASE_NAME
#define DISKFONT_BASE_NAME DiskfontBase
#endif

#define OpenDiskFont(textAttr) ({ \
  struct TextAttr * _OpenDiskFont_textAttr = (textAttr); \
  struct TextFont * _OpenDiskFont__re = \
  ({ \
  register struct Library * const __OpenDiskFont__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct TextFont * __OpenDiskFont__re __asm("d0"); \
  register struct TextAttr * __OpenDiskFont_textAttr __asm("a0") = (_OpenDiskFont_textAttr); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__OpenDiskFont__re) \
  : "r"(__OpenDiskFont__bn), "r"(__OpenDiskFont_textAttr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenDiskFont__re; \
  }); \
  _OpenDiskFont__re; \
})

#define AvailFonts(buffer, bufBytes, flags) ({ \
  STRPTR _AvailFonts_buffer = (buffer); \
  LONG _AvailFonts_bufBytes = (bufBytes); \
  ULONG _AvailFonts_flags = (flags); \
  LONG _AvailFonts__re = \
  ({ \
  register struct Library * const __AvailFonts__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register LONG __AvailFonts__re __asm("d0"); \
  register STRPTR __AvailFonts_buffer __asm("a0") = (_AvailFonts_buffer); \
  register LONG __AvailFonts_bufBytes __asm("d0") = (_AvailFonts_bufBytes); \
  register ULONG __AvailFonts_flags __asm("d1") = (_AvailFonts_flags); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AvailFonts__re) \
  : "r"(__AvailFonts__bn), "r"(__AvailFonts_buffer), "r"(__AvailFonts_bufBytes), "r"(__AvailFonts_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AvailFonts__re; \
  }); \
  _AvailFonts__re; \
})

#define NewFontContents(fontsLock, fontName) ({ \
  BPTR _NewFontContents_fontsLock = (fontsLock); \
  STRPTR _NewFontContents_fontName = (fontName); \
  struct FontContentsHeader * _NewFontContents__re = \
  ({ \
  register struct Library * const __NewFontContents__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct FontContentsHeader * __NewFontContents__re __asm("d0"); \
  register BPTR __NewFontContents_fontsLock __asm("a0") = (_NewFontContents_fontsLock); \
  register STRPTR __NewFontContents_fontName __asm("a1") = (_NewFontContents_fontName); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__NewFontContents__re) \
  : "r"(__NewFontContents__bn), "r"(__NewFontContents_fontsLock), "r"(__NewFontContents_fontName) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NewFontContents__re; \
  }); \
  _NewFontContents__re; \
})

#define DisposeFontContents(fontContentsHeader) ({ \
  struct FontContentsHeader * _DisposeFontContents_fontContentsHeader = (fontContentsHeader); \
  { \
  register struct Library * const __DisposeFontContents__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct FontContentsHeader * __DisposeFontContents_fontContentsHeader __asm("a1") = (_DisposeFontContents_fontContentsHeader); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__DisposeFontContents__bn), "r"(__DisposeFontContents_fontContentsHeader) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define NewScaledDiskFont(sourceFont, destTextAttr) ({ \
  struct TextFont * _NewScaledDiskFont_sourceFont = (sourceFont); \
  struct TextAttr * _NewScaledDiskFont_destTextAttr = (destTextAttr); \
  struct DiskFontHeader * _NewScaledDiskFont__re = \
  ({ \
  register struct Library * const __NewScaledDiskFont__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct DiskFontHeader * __NewScaledDiskFont__re __asm("d0"); \
  register struct TextFont * __NewScaledDiskFont_sourceFont __asm("a0") = (_NewScaledDiskFont_sourceFont); \
  register struct TextAttr * __NewScaledDiskFont_destTextAttr __asm("a1") = (_NewScaledDiskFont_destTextAttr); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__NewScaledDiskFont__re) \
  : "r"(__NewScaledDiskFont__bn), "r"(__NewScaledDiskFont_sourceFont), "r"(__NewScaledDiskFont_destTextAttr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NewScaledDiskFont__re; \
  }); \
  _NewScaledDiskFont__re; \
})

#define GetDiskFontCtrl(tagid) ({ \
  LONG _GetDiskFontCtrl_tagid = (tagid); \
  LONG _GetDiskFontCtrl__re = \
  ({ \
  register struct Library * const __GetDiskFontCtrl__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register LONG __GetDiskFontCtrl__re __asm("d0"); \
  register LONG __GetDiskFontCtrl_tagid __asm("d0") = (_GetDiskFontCtrl_tagid); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__GetDiskFontCtrl__re) \
  : "r"(__GetDiskFontCtrl__bn), "r"(__GetDiskFontCtrl_tagid) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDiskFontCtrl__re; \
  }); \
  _GetDiskFontCtrl__re; \
})

#define SetDiskFontCtrlA(taglist) ({ \
  struct TagItem * _SetDiskFontCtrlA_taglist = (taglist); \
  { \
  register struct Library * const __SetDiskFontCtrlA__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct TagItem * __SetDiskFontCtrlA_taglist __asm("a0") = (_SetDiskFontCtrlA_taglist); \
  __asm volatile ("jsr a6@(-66:W)" \
  : \
  : "r"(__SetDiskFontCtrlA__bn), "r"(__SetDiskFontCtrlA_taglist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___SetDiskFontCtrl(struct Library * DiskfontBase, Tag taglist, ...)
{
  SetDiskFontCtrlA((struct TagItem *) &taglist);
}

#define SetDiskFontCtrl(tags...) ___SetDiskFontCtrl(DISKFONT_BASE_NAME, tags)
#endif

#define EOpenEngine(EEngine) ({ \
  struct EGlyphEngine * _EOpenEngine_EEngine = (EEngine); \
  LONG _EOpenEngine__re = \
  ({ \
  register struct Library * const __EOpenEngine__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register LONG __EOpenEngine__re __asm("d0"); \
  register struct EGlyphEngine * __EOpenEngine_EEngine __asm("a0") = (_EOpenEngine_EEngine); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__EOpenEngine__re) \
  : "r"(__EOpenEngine__bn), "r"(__EOpenEngine_EEngine) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __EOpenEngine__re; \
  }); \
  _EOpenEngine__re; \
})

#define ECloseEngine(EEngine) ({ \
  struct EGlyphEngine * _ECloseEngine_EEngine = (EEngine); \
  { \
  register struct Library * const __ECloseEngine__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct EGlyphEngine * __ECloseEngine_EEngine __asm("a0") = (_ECloseEngine_EEngine); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__ECloseEngine__bn), "r"(__ECloseEngine_EEngine) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ESetInfoA(EEngine, taglist) ({ \
  struct EGlyphEngine * _ESetInfoA_EEngine = (EEngine); \
  struct TagItem * _ESetInfoA_taglist = (taglist); \
  ULONG _ESetInfoA__re = \
  ({ \
  register struct Library * const __ESetInfoA__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register ULONG __ESetInfoA__re __asm("d0"); \
  register struct EGlyphEngine * __ESetInfoA_EEngine __asm("a0") = (_ESetInfoA_EEngine); \
  register struct TagItem * __ESetInfoA_taglist __asm("a1") = (_ESetInfoA_taglist); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__ESetInfoA__re) \
  : "r"(__ESetInfoA__bn), "r"(__ESetInfoA_EEngine), "r"(__ESetInfoA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ESetInfoA__re; \
  }); \
  _ESetInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___ESetInfo(struct Library * DiskfontBase, struct EGlyphEngine * EEngine, Tag taglist, ...)
{
  return ESetInfoA(EEngine, (struct TagItem *) &taglist);
}

#define ESetInfo(EEngine...) ___ESetInfo(DISKFONT_BASE_NAME, EEngine)
#endif

#define EObtainInfoA(EEngine, taglist) ({ \
  struct EGlyphEngine * _EObtainInfoA_EEngine = (EEngine); \
  struct TagItem * _EObtainInfoA_taglist = (taglist); \
  ULONG _EObtainInfoA__re = \
  ({ \
  register struct Library * const __EObtainInfoA__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register ULONG __EObtainInfoA__re __asm("d0"); \
  register struct EGlyphEngine * __EObtainInfoA_EEngine __asm("a0") = (_EObtainInfoA_EEngine); \
  register struct TagItem * __EObtainInfoA_taglist __asm("a1") = (_EObtainInfoA_taglist); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__EObtainInfoA__re) \
  : "r"(__EObtainInfoA__bn), "r"(__EObtainInfoA_EEngine), "r"(__EObtainInfoA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __EObtainInfoA__re; \
  }); \
  _EObtainInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___EObtainInfo(struct Library * DiskfontBase, struct EGlyphEngine * EEngine, Tag taglist, ...)
{
  return EObtainInfoA(EEngine, (struct TagItem *) &taglist);
}

#define EObtainInfo(EEngine...) ___EObtainInfo(DISKFONT_BASE_NAME, EEngine)
#endif

#define EReleaseInfoA(EEngine, taglist) ({ \
  struct EGlyphEngine * _EReleaseInfoA_EEngine = (EEngine); \
  struct TagItem * _EReleaseInfoA_taglist = (taglist); \
  ULONG _EReleaseInfoA__re = \
  ({ \
  register struct Library * const __EReleaseInfoA__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register ULONG __EReleaseInfoA__re __asm("d0"); \
  register struct EGlyphEngine * __EReleaseInfoA_EEngine __asm("a0") = (_EReleaseInfoA_EEngine); \
  register struct TagItem * __EReleaseInfoA_taglist __asm("a1") = (_EReleaseInfoA_taglist); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__EReleaseInfoA__re) \
  : "r"(__EReleaseInfoA__bn), "r"(__EReleaseInfoA_EEngine), "r"(__EReleaseInfoA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __EReleaseInfoA__re; \
  }); \
  _EReleaseInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___EReleaseInfo(struct Library * DiskfontBase, struct EGlyphEngine * EEngine, Tag taglist, ...)
{
  return EReleaseInfoA(EEngine, (struct TagItem *) &taglist);
}

#define EReleaseInfo(EEngine...) ___EReleaseInfo(DISKFONT_BASE_NAME, EEngine)
#endif

#define OpenOutlineFont(name, list, flags) ({ \
  STRPTR _OpenOutlineFont_name = (name); \
  struct List * _OpenOutlineFont_list = (list); \
  ULONG _OpenOutlineFont_flags = (flags); \
  struct OutlineFont * _OpenOutlineFont__re = \
  ({ \
  register struct Library * const __OpenOutlineFont__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct OutlineFont * __OpenOutlineFont__re __asm("d0"); \
  register STRPTR __OpenOutlineFont_name __asm("a0") = (_OpenOutlineFont_name); \
  register struct List * __OpenOutlineFont_list __asm("a1") = (_OpenOutlineFont_list); \
  register ULONG __OpenOutlineFont_flags __asm("d0") = (_OpenOutlineFont_flags); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__OpenOutlineFont__re) \
  : "r"(__OpenOutlineFont__bn), "r"(__OpenOutlineFont_name), "r"(__OpenOutlineFont_list), "r"(__OpenOutlineFont_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenOutlineFont__re; \
  }); \
  _OpenOutlineFont__re; \
})

#define CloseOutlineFont(olf, list) ({ \
  struct OutlineFont * _CloseOutlineFont_olf = (olf); \
  struct List * _CloseOutlineFont_list = (list); \
  { \
  register struct Library * const __CloseOutlineFont__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct OutlineFont * __CloseOutlineFont_olf __asm("a0") = (_CloseOutlineFont_olf); \
  register struct List * __CloseOutlineFont_list __asm("a1") = (_CloseOutlineFont_list); \
  __asm volatile ("jsr a6@(-108:W)" \
  : \
  : "r"(__CloseOutlineFont__bn), "r"(__CloseOutlineFont_olf), "r"(__CloseOutlineFont_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WriteFontContents(fontsLock, fontName, fontContentsHeader) ({ \
  BPTR _WriteFontContents_fontsLock = (fontsLock); \
  STRPTR _WriteFontContents_fontName = (fontName); \
  struct FontContentsHeader * _WriteFontContents_fontContentsHeader = (fontContentsHeader); \
  LONG _WriteFontContents__re = \
  ({ \
  register struct Library * const __WriteFontContents__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register LONG __WriteFontContents__re __asm("d0"); \
  register BPTR __WriteFontContents_fontsLock __asm("a0") = (_WriteFontContents_fontsLock); \
  register STRPTR __WriteFontContents_fontName __asm("a1") = (_WriteFontContents_fontName); \
  register struct FontContentsHeader * __WriteFontContents_fontContentsHeader __asm("a2") = (_WriteFontContents_fontContentsHeader); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__WriteFontContents__re) \
  : "r"(__WriteFontContents__bn), "r"(__WriteFontContents_fontsLock), "r"(__WriteFontContents_fontName), "r"(__WriteFontContents_fontContentsHeader) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WriteFontContents__re; \
  }); \
  _WriteFontContents__re; \
})

#define WriteDiskFontHeaderA(font, fileName, taglist) ({ \
  struct TextFont * _WriteDiskFontHeaderA_font = (font); \
  STRPTR _WriteDiskFontHeaderA_fileName = (fileName); \
  struct TagItem * _WriteDiskFontHeaderA_taglist = (taglist); \
  LONG _WriteDiskFontHeaderA__re = \
  ({ \
  register struct Library * const __WriteDiskFontHeaderA__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register LONG __WriteDiskFontHeaderA__re __asm("d0"); \
  register struct TextFont * __WriteDiskFontHeaderA_font __asm("a0") = (_WriteDiskFontHeaderA_font); \
  register STRPTR __WriteDiskFontHeaderA_fileName __asm("a1") = (_WriteDiskFontHeaderA_fileName); \
  register struct TagItem * __WriteDiskFontHeaderA_taglist __asm("a2") = (_WriteDiskFontHeaderA_taglist); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__WriteDiskFontHeaderA__re) \
  : "r"(__WriteDiskFontHeaderA__bn), "r"(__WriteDiskFontHeaderA_font), "r"(__WriteDiskFontHeaderA_fileName), "r"(__WriteDiskFontHeaderA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WriteDiskFontHeaderA__re; \
  }); \
  _WriteDiskFontHeaderA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___WriteDiskFontHeader(struct Library * DiskfontBase, struct TextFont * font, STRPTR fileName, Tag taglist, ...)
{
  return WriteDiskFontHeaderA(font, fileName, (struct TagItem *) &taglist);
}

#define WriteDiskFontHeader(font, fileName...) ___WriteDiskFontHeader(DISKFONT_BASE_NAME, font, fileName)
#endif

#define ObtainCharsetInfo(knownTag, knownValue, wantedTag) ({ \
  ULONG _ObtainCharsetInfo_knownTag = (knownTag); \
  ULONG _ObtainCharsetInfo_knownValue = (knownValue); \
  ULONG _ObtainCharsetInfo_wantedTag = (wantedTag); \
  ULONG _ObtainCharsetInfo__re = \
  ({ \
  register struct Library * const __ObtainCharsetInfo__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register ULONG __ObtainCharsetInfo__re __asm("d0"); \
  register ULONG __ObtainCharsetInfo_knownTag __asm("d0") = (_ObtainCharsetInfo_knownTag); \
  register ULONG __ObtainCharsetInfo_knownValue __asm("d1") = (_ObtainCharsetInfo_knownValue); \
  register ULONG __ObtainCharsetInfo_wantedTag __asm("d2") = (_ObtainCharsetInfo_wantedTag); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__ObtainCharsetInfo__re) \
  : "r"(__ObtainCharsetInfo__bn), "r"(__ObtainCharsetInfo_knownTag), "r"(__ObtainCharsetInfo_knownValue), "r"(__ObtainCharsetInfo_wantedTag) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainCharsetInfo__re; \
  }); \
  _ObtainCharsetInfo__re; \
})

#define ObtainTTextAttr(textFont) ({ \
  struct TextFont * _ObtainTTextAttr_textFont = (textFont); \
  struct TTextAttr * _ObtainTTextAttr__re = \
  ({ \
  register struct Library * const __ObtainTTextAttr__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct TTextAttr * __ObtainTTextAttr__re __asm("d0"); \
  register struct TextFont * __ObtainTTextAttr_textFont __asm("a0") = (_ObtainTTextAttr_textFont); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__ObtainTTextAttr__re) \
  : "r"(__ObtainTTextAttr__bn), "r"(__ObtainTTextAttr_textFont) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainTTextAttr__re; \
  }); \
  _ObtainTTextAttr__re; \
})

#define FreeTTextAttr(tta) ({ \
  struct TTextAttr * _FreeTTextAttr_tta = (tta); \
  { \
  register struct Library * const __FreeTTextAttr__bn __asm("a6") = (struct Library *) (DISKFONT_BASE_NAME);\
  register struct TTextAttr * __FreeTTextAttr_tta __asm("a0") = (_FreeTTextAttr_tta); \
  __asm volatile ("jsr a6@(-138:W)" \
  : \
  : "r"(__FreeTTextAttr__bn), "r"(__FreeTTextAttr_tta) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_DISKFONT_H  */
