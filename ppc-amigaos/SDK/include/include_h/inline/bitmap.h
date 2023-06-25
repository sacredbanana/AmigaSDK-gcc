#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_BITMAP_H
#define _INLINE_BITMAP_H

#ifndef CLIB_BITMAP_PROTOS_H
#define CLIB_BITMAP_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef BITMAP_BASE_NAME
#define BITMAP_BASE_NAME BitMapBase
#endif

#define BITMAP_GetClass() ({ \
  Class * _BITMAP_GetClass__re = \
  ({ \
  register struct Library * const __BITMAP_GetClass__bn __asm("a6") = (struct Library *) (BITMAP_BASE_NAME);\
  register Class * __BITMAP_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__BITMAP_GetClass__re) \
  : "r"(__BITMAP_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BITMAP_GetClass__re; \
  }); \
  _BITMAP_GetClass__re; \
})

#endif /*  _INLINE_BITMAP_H  */
