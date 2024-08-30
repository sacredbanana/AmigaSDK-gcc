#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_GETCOLOR_H
#define _INLINE_GETCOLOR_H

#ifndef CLIB_GETCOLOR_PROTOS_H
#define CLIB_GETCOLOR_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef GETCOLOR_BASE_NAME
#define GETCOLOR_BASE_NAME GetColorBase
#endif

#define GETCOLOR_GetClass() ({ \
  Class * _GETCOLOR_GetClass__re = \
  ({ \
  register struct Library * const __GETCOLOR_GetClass__bn __asm("a6") = (struct Library *) (GETCOLOR_BASE_NAME);\
  register Class * __GETCOLOR_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__GETCOLOR_GetClass__re) \
  : "r"(__GETCOLOR_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GETCOLOR_GetClass__re; \
  }); \
  _GETCOLOR_GetClass__re; \
})

#endif /*  _INLINE_GETCOLOR_H  */
