#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_ELF_H
#define _INLINE_ELF_H

#ifndef CLIB_ELF_PROTOS_H
#define CLIB_ELF_PROTOS_H
#endif

#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  LIBRARIES_ELF_H
#include <libraries/elf.h>
#endif

#ifndef ELF_BASE_NAME
#define ELF_BASE_NAME ElfBase
#endif

#define OpenElf(taglist) ({ \
  struct TagItem * _OpenElf_taglist = (taglist); \
  Elf32_Handle _OpenElf__re = \
  ({ \
  register struct Library * const __OpenElf__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register Elf32_Handle __OpenElf__re __asm("d0"); \
  register struct TagItem * __OpenElf_taglist __asm("a0") = (_OpenElf_taglist); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__OpenElf__re) \
  : "r"(__OpenElf__bn), "r"(__OpenElf_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenElf__re; \
  }); \
  _OpenElf__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ Elf32_Handle ___OpenElfTags(struct Library * ElfBase, ULONG taglist, ...)
{
  return OpenElf((struct TagItem *) &taglist);
}

#define OpenElfTags(tags...) ___OpenElfTags(ELF_BASE_NAME, tags)
#endif

#define CloseElf(ElfHandle, tagslit) ({ \
  LONG _CloseElf_ElfHandle = (ElfHandle); \
  struct TagItem * _CloseElf_tagslit = (tagslit); \
  { \
  register struct Library * const __CloseElf__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register LONG __CloseElf_ElfHandle __asm("a0") = (_CloseElf_ElfHandle); \
  register struct TagItem * __CloseElf_tagslit __asm("a1") = (_CloseElf_tagslit); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__CloseElf__bn), "r"(__CloseElf_ElfHandle), "r"(__CloseElf_tagslit) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ void ___CloseElfTags(struct Library * ElfBase, LONG ElfHandle, ULONG tagslit, ...)
{
  CloseElf(ElfHandle, (struct TagItem *) &tagslit);
}

#define CloseElfTags(ElfHandle...) ___CloseElfTags(ELF_BASE_NAME, ElfHandle)
#endif

#define GetElfAttrs(ElfHandle, taglist) ({ \
  LONG _GetElfAttrs_ElfHandle = (ElfHandle); \
  struct TagItem * _GetElfAttrs_taglist = (taglist); \
  ULONG _GetElfAttrs__re = \
  ({ \
  register struct Library * const __GetElfAttrs__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register ULONG __GetElfAttrs__re __asm("d0"); \
  register LONG __GetElfAttrs_ElfHandle __asm("a0") = (_GetElfAttrs_ElfHandle); \
  register struct TagItem * __GetElfAttrs_taglist __asm("a1") = (_GetElfAttrs_taglist); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__GetElfAttrs__re) \
  : "r"(__GetElfAttrs__bn), "r"(__GetElfAttrs_ElfHandle), "r"(__GetElfAttrs_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetElfAttrs__re; \
  }); \
  _GetElfAttrs__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___GetElfAttrsTags(struct Library * ElfBase, LONG ElfHandle, ULONG taglist, ...)
{
  return GetElfAttrs(ElfHandle, (struct TagItem *) &taglist);
}

#define GetElfAttrsTags(ElfHandle...) ___GetElfAttrsTags(ELF_BASE_NAME, ElfHandle)
#endif

#define SetElfAttrs(ElfHandle, taglist) ({ \
  LONG _SetElfAttrs_ElfHandle = (ElfHandle); \
  struct TagItem * _SetElfAttrs_taglist = (taglist); \
  ULONG _SetElfAttrs__re = \
  ({ \
  register struct Library * const __SetElfAttrs__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register ULONG __SetElfAttrs__re __asm("d0"); \
  register LONG __SetElfAttrs_ElfHandle __asm("a0") = (_SetElfAttrs_ElfHandle); \
  register struct TagItem * __SetElfAttrs_taglist __asm("a1") = (_SetElfAttrs_taglist); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__SetElfAttrs__re) \
  : "r"(__SetElfAttrs__bn), "r"(__SetElfAttrs_ElfHandle), "r"(__SetElfAttrs_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetElfAttrs__re; \
  }); \
  _SetElfAttrs__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SetElfAttrsTags(struct Library * ElfBase, LONG ElfHandle, ULONG taglist, ...)
{
  return SetElfAttrs(ElfHandle, (struct TagItem *) &taglist);
}

#define SetElfAttrsTags(ElfHandle...) ___SetElfAttrsTags(ELF_BASE_NAME, ElfHandle)
#endif

#define GetSectionHeader(ElfHandle, TagList) ({ \
  LONG _GetSectionHeader_ElfHandle = (ElfHandle); \
  struct TagItem * _GetSectionHeader_TagList = (TagList); \
  Elf32_Shdr * _GetSectionHeader__re = \
  ({ \
  register struct Library * const __GetSectionHeader__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register Elf32_Shdr * __GetSectionHeader__re __asm("d0"); \
  register LONG __GetSectionHeader_ElfHandle __asm("a0") = (_GetSectionHeader_ElfHandle); \
  register struct TagItem * __GetSectionHeader_TagList __asm("a1") = (_GetSectionHeader_TagList); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__GetSectionHeader__re) \
  : "r"(__GetSectionHeader__bn), "r"(__GetSectionHeader_ElfHandle), "r"(__GetSectionHeader_TagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetSectionHeader__re; \
  }); \
  _GetSectionHeader__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ Elf32_Shdr * ___GetSectionHeaderTags(struct Library * ElfBase, LONG ElfHandle, ULONG TagList, ...)
{
  return GetSectionHeader(ElfHandle, (struct TagItem *) &TagList);
}

#define GetSectionHeaderTags(ElfHandle...) ___GetSectionHeaderTags(ELF_BASE_NAME, ElfHandle)
#endif

#define GetSection(ElfHandle, TagList) ({ \
  LONG _GetSection_ElfHandle = (ElfHandle); \
  struct TagItem * _GetSection_TagList = (TagList); \
  APTR _GetSection__re = \
  ({ \
  register struct Library * const __GetSection__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register APTR __GetSection__re __asm("d0"); \
  register LONG __GetSection_ElfHandle __asm("a0") = (_GetSection_ElfHandle); \
  register struct TagItem * __GetSection_TagList __asm("a1") = (_GetSection_TagList); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__GetSection__re) \
  : "r"(__GetSection__bn), "r"(__GetSection_ElfHandle), "r"(__GetSection_TagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetSection__re; \
  }); \
  _GetSection__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___GetSectionTags(struct Library * ElfBase, LONG ElfHandle, ULONG TagList, ...)
{
  return GetSection(ElfHandle, (struct TagItem *) &TagList);
}

#define GetSectionTags(ElfHandle...) ___GetSectionTags(ELF_BASE_NAME, ElfHandle)
#endif

#define ElfLoadSeg(ElfHandle, taglist) ({ \
  LONG _ElfLoadSeg_ElfHandle = (ElfHandle); \
  struct TagItem * _ElfLoadSeg_taglist = (taglist); \
  Elf32_Error _ElfLoadSeg__re = \
  ({ \
  register struct Library * const __ElfLoadSeg__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register Elf32_Error __ElfLoadSeg__re __asm("d0"); \
  register LONG __ElfLoadSeg_ElfHandle __asm("a0") = (_ElfLoadSeg_ElfHandle); \
  register struct TagItem * __ElfLoadSeg_taglist __asm("a1") = (_ElfLoadSeg_taglist); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__ElfLoadSeg__re) \
  : "r"(__ElfLoadSeg__bn), "r"(__ElfLoadSeg_ElfHandle), "r"(__ElfLoadSeg_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ElfLoadSeg__re; \
  }); \
  _ElfLoadSeg__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ Elf32_Error ___ElfLoadSegTags(struct Library * ElfBase, LONG ElfHandle, ULONG taglist, ...)
{
  return ElfLoadSeg(ElfHandle, (struct TagItem *) &taglist);
}

#define ElfLoadSegTags(ElfHandle...) ___ElfLoadSegTags(ELF_BASE_NAME, ElfHandle)
#endif

#define GetElfString(ElfHandle, SectionIndex, StringIndex) ({ \
  LONG _GetElfString_ElfHandle = (ElfHandle); \
  ULONG _GetElfString_SectionIndex = (SectionIndex); \
  ULONG _GetElfString_StringIndex = (StringIndex); \
  STRPTR _GetElfString__re = \
  ({ \
  register struct Library * const __GetElfString__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register STRPTR __GetElfString__re __asm("d0"); \
  register LONG __GetElfString_ElfHandle __asm("a0") = (_GetElfString_ElfHandle); \
  register ULONG __GetElfString_SectionIndex __asm("d0") = (_GetElfString_SectionIndex); \
  register ULONG __GetElfString_StringIndex __asm("d1") = (_GetElfString_StringIndex); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__GetElfString__re) \
  : "r"(__GetElfString__bn), "r"(__GetElfString_ElfHandle), "r"(__GetElfString_SectionIndex), "r"(__GetElfString_StringIndex) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetElfString__re; \
  }); \
  _GetElfString__re; \
})

#define SymbolQuery(ElfHandle, NumQueries, Queries) ({ \
  LONG _SymbolQuery_ElfHandle = (ElfHandle); \
  ULONG _SymbolQuery_NumQueries = (NumQueries); \
  struct Elf32_SymbolQuery * _SymbolQuery_Queries = (Queries); \
  ULONG _SymbolQuery__re = \
  ({ \
  register struct Library * const __SymbolQuery__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register ULONG __SymbolQuery__re __asm("d0"); \
  register LONG __SymbolQuery_ElfHandle __asm("a0") = (_SymbolQuery_ElfHandle); \
  register ULONG __SymbolQuery_NumQueries __asm("d0") = (_SymbolQuery_NumQueries); \
  register struct Elf32_SymbolQuery * __SymbolQuery_Queries __asm("a1") = (_SymbolQuery_Queries); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__SymbolQuery__re) \
  : "r"(__SymbolQuery__bn), "r"(__SymbolQuery_ElfHandle), "r"(__SymbolQuery_NumQueries), "r"(__SymbolQuery_Queries) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SymbolQuery__re; \
  }); \
  _SymbolQuery__re; \
})

#define UnloadSection(ElfHandle, taglist) ({ \
  LONG _UnloadSection_ElfHandle = (ElfHandle); \
  struct TagItem * _UnloadSection_taglist = (taglist); \
  { \
  register struct Library * const __UnloadSection__bn __asm("a6") = (struct Library *) (ELF_BASE_NAME);\
  register LONG __UnloadSection_ElfHandle __asm("a0") = (_UnloadSection_ElfHandle); \
  register struct TagItem * __UnloadSection_taglist __asm("a1") = (_UnloadSection_taglist); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__UnloadSection__bn), "r"(__UnloadSection_ElfHandle), "r"(__UnloadSection_taglist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ void ___UnloadSectionTags(struct Library * ElfBase, LONG ElfHandle, ULONG taglist, ...)
{
  UnloadSection(ElfHandle, (struct TagItem *) &taglist);
}

#define UnloadSectionTags(ElfHandle...) ___UnloadSectionTags(ELF_BASE_NAME, ElfHandle)
#endif

#endif /*  _INLINE_ELF_H  */
