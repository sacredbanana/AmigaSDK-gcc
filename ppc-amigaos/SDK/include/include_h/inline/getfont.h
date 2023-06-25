#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_GETFONT_H
#define _INLINE_GETFONT_H

#ifndef CLIB_GETFONT_PROTOS_H
#define CLIB_GETFONT_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef GETFONT_BASE_NAME
#define GETFONT_BASE_NAME GetFontBase
#endif

#define GETFONT_GetClass() ({ \
  Class * _GETFONT_GetClass__re = \
  ({ \
  register struct Library * const __GETFONT_GetClass__bn __asm("a6") = (struct Library *) (GETFONT_BASE_NAME);\
  register Class * __GETFONT_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__GETFONT_GetClass__re) \
  : "r"(__GETFONT_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GETFONT_GetClass__re; \
  }); \
  _GETFONT_GetClass__re; \
})

#endif /*  _INLINE_GETFONT_H  */
