#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_STRING_H
#define _INLINE_STRING_H

#ifndef CLIB_STRING_PROTOS_H
#define CLIB_STRING_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef STRING_BASE_NAME
#define STRING_BASE_NAME StringBase
#endif

#define STRING_GetClass() ({ \
  Class * _STRING_GetClass__re = \
  ({ \
  register struct Library * const __STRING_GetClass__bn __asm("a6") = (struct Library *) (STRING_BASE_NAME);\
  register Class * __STRING_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__STRING_GetClass__re) \
  : "r"(__STRING_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __STRING_GetClass__re; \
  }); \
  _STRING_GetClass__re; \
})

#endif /*  _INLINE_STRING_H  */
