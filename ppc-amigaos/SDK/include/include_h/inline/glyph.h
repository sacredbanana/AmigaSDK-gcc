#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_GLYPH_H
#define _INLINE_GLYPH_H

#ifndef CLIB_GLYPH_PROTOS_H
#define CLIB_GLYPH_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef GLYPH_BASE_NAME
#define GLYPH_BASE_NAME GlyphBase
#endif

#define GLYPH_GetClass() ({ \
  Class * _GLYPH_GetClass__re = \
  ({ \
  register struct Library * const __GLYPH_GetClass__bn __asm("a6") = (struct Library *) (GLYPH_BASE_NAME);\
  register Class * __GLYPH_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__GLYPH_GetClass__re) \
  : "r"(__GLYPH_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GLYPH_GetClass__re; \
  }); \
  _GLYPH_GetClass__re; \
})

#endif /*  _INLINE_GLYPH_H  */
