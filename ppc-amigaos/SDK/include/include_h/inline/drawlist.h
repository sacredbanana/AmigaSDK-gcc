#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_DRAWLIST_H
#define _INLINE_DRAWLIST_H

#ifndef CLIB_DRAWLIST_PROTOS_H
#define CLIB_DRAWLIST_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef DRAWLIST_BASE_NAME
#define DRAWLIST_BASE_NAME DrawListBase
#endif

#define DRAWLIST_GetClass() ({ \
  Class * _DRAWLIST_GetClass__re = \
  ({ \
  register struct Library * const __DRAWLIST_GetClass__bn __asm("a6") = (struct Library *) (DRAWLIST_BASE_NAME);\
  register Class * __DRAWLIST_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__DRAWLIST_GetClass__re) \
  : "r"(__DRAWLIST_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DRAWLIST_GetClass__re; \
  }); \
  _DRAWLIST_GetClass__re; \
})

#endif /*  _INLINE_DRAWLIST_H  */
