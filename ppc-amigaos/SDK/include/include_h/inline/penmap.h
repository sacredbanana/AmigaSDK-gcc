#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_PENMAP_H
#define _INLINE_PENMAP_H

#ifndef CLIB_PENMAP_PROTOS_H
#define CLIB_PENMAP_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef PENMAP_BASE_NAME
#define PENMAP_BASE_NAME PenMapBase
#endif

#define PENMAP_GetClass() ({ \
  Class * _PENMAP_GetClass__re = \
  ({ \
  register struct Library * const __PENMAP_GetClass__bn __asm("a6") = (struct Library *) (PENMAP_BASE_NAME);\
  register Class * __PENMAP_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__PENMAP_GetClass__re) \
  : "r"(__PENMAP_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PENMAP_GetClass__re; \
  }); \
  _PENMAP_GetClass__re; \
})

#endif /*  _INLINE_PENMAP_H  */
