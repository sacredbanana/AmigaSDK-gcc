#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_BULLET_H
#define _INLINE_BULLET_H

#ifndef CLIB_BULLET_PROTOS_H
#define CLIB_BULLET_PROTOS_H
#endif

#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  DISKFONT_GLYPH_H
#include <diskfont/glyph.h>
#endif

#ifndef BULLET_BASE_NAME
#define BULLET_BASE_NAME BulletBase
#endif

#define OpenEngine() ({ \
  struct GlyphEngine * _OpenEngine__re = \
  ({ \
  register struct Library * const __OpenEngine__bn __asm("a6") = (struct Library *) (BULLET_BASE_NAME);\
  register struct GlyphEngine * __OpenEngine__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__OpenEngine__re) \
  : "r"(__OpenEngine__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenEngine__re; \
  }); \
  _OpenEngine__re; \
})

#define CloseEngine(glyphEngine) ({ \
  struct GlyphEngine * _CloseEngine_glyphEngine = (glyphEngine); \
  { \
  register struct Library * const __CloseEngine__bn __asm("a6") = (struct Library *) (BULLET_BASE_NAME);\
  register struct GlyphEngine * __CloseEngine_glyphEngine __asm("a0") = (_CloseEngine_glyphEngine); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__CloseEngine__bn), "r"(__CloseEngine_glyphEngine) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetInfoA(glyphEngine, tagList) ({ \
  struct GlyphEngine * _SetInfoA_glyphEngine = (glyphEngine); \
  struct TagItem * _SetInfoA_tagList = (tagList); \
  ULONG _SetInfoA__re = \
  ({ \
  register struct Library * const __SetInfoA__bn __asm("a6") = (struct Library *) (BULLET_BASE_NAME);\
  register ULONG __SetInfoA__re __asm("d0"); \
  register struct GlyphEngine * __SetInfoA_glyphEngine __asm("a0") = (_SetInfoA_glyphEngine); \
  register struct TagItem * __SetInfoA_tagList __asm("a1") = (_SetInfoA_tagList); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__SetInfoA__re) \
  : "r"(__SetInfoA__bn), "r"(__SetInfoA_glyphEngine), "r"(__SetInfoA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetInfoA__re; \
  }); \
  _SetInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SetInfo(struct Library * BulletBase, struct GlyphEngine * glyphEngine, Tag tagList, ...)
{
  return SetInfoA(glyphEngine, (struct TagItem *) &tagList);
}

#define SetInfo(glyphEngine...) ___SetInfo(BULLET_BASE_NAME, glyphEngine)
#endif

#define ObtainInfoA(glyphEngine, tagList) ({ \
  struct GlyphEngine * _ObtainInfoA_glyphEngine = (glyphEngine); \
  struct TagItem * _ObtainInfoA_tagList = (tagList); \
  ULONG _ObtainInfoA__re = \
  ({ \
  register struct Library * const __ObtainInfoA__bn __asm("a6") = (struct Library *) (BULLET_BASE_NAME);\
  register ULONG __ObtainInfoA__re __asm("d0"); \
  register struct GlyphEngine * __ObtainInfoA_glyphEngine __asm("a0") = (_ObtainInfoA_glyphEngine); \
  register struct TagItem * __ObtainInfoA_tagList __asm("a1") = (_ObtainInfoA_tagList); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__ObtainInfoA__re) \
  : "r"(__ObtainInfoA__bn), "r"(__ObtainInfoA_glyphEngine), "r"(__ObtainInfoA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainInfoA__re; \
  }); \
  _ObtainInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___ObtainInfo(struct Library * BulletBase, struct GlyphEngine * glyphEngine, Tag tagList, ...)
{
  return ObtainInfoA(glyphEngine, (struct TagItem *) &tagList);
}

#define ObtainInfo(glyphEngine...) ___ObtainInfo(BULLET_BASE_NAME, glyphEngine)
#endif

#define ReleaseInfoA(glyphEngine, tagList) ({ \
  struct GlyphEngine * _ReleaseInfoA_glyphEngine = (glyphEngine); \
  struct TagItem * _ReleaseInfoA_tagList = (tagList); \
  ULONG _ReleaseInfoA__re = \
  ({ \
  register struct Library * const __ReleaseInfoA__bn __asm("a6") = (struct Library *) (BULLET_BASE_NAME);\
  register ULONG __ReleaseInfoA__re __asm("d0"); \
  register struct GlyphEngine * __ReleaseInfoA_glyphEngine __asm("a0") = (_ReleaseInfoA_glyphEngine); \
  register struct TagItem * __ReleaseInfoA_tagList __asm("a1") = (_ReleaseInfoA_tagList); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__ReleaseInfoA__re) \
  : "r"(__ReleaseInfoA__bn), "r"(__ReleaseInfoA_glyphEngine), "r"(__ReleaseInfoA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReleaseInfoA__re; \
  }); \
  _ReleaseInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___ReleaseInfo(struct Library * BulletBase, struct GlyphEngine * glyphEngine, Tag tagList, ...)
{
  return ReleaseInfoA(glyphEngine, (struct TagItem *) &tagList);
}

#define ReleaseInfo(glyphEngine...) ___ReleaseInfo(BULLET_BASE_NAME, glyphEngine)
#endif

#endif /*  _INLINE_BULLET_H  */
