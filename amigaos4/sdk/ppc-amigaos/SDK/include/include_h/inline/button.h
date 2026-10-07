#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_BUTTON_H
#define _INLINE_BUTTON_H

#ifndef CLIB_BUTTON_PROTOS_H
#define CLIB_BUTTON_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef BUTTON_BASE_NAME
#define BUTTON_BASE_NAME ButtonBase
#endif

#define BUTTON_GetClass() ({ \
  Class * _BUTTON_GetClass__re = \
  ({ \
  register struct Library * const __BUTTON_GetClass__bn __asm("a6") = (struct Library *) (BUTTON_BASE_NAME);\
  register Class * __BUTTON_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__BUTTON_GetClass__re) \
  : "r"(__BUTTON_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BUTTON_GetClass__re; \
  }); \
  _BUTTON_GetClass__re; \
})

#endif /*  _INLINE_BUTTON_H  */
