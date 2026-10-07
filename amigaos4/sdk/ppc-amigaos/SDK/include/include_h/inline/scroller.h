#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_SCROLLER_H
#define _INLINE_SCROLLER_H

#ifndef CLIB_SCROLLER_PROTOS_H
#define CLIB_SCROLLER_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef SCROLLER_BASE_NAME
#define SCROLLER_BASE_NAME ScrollerBase
#endif

#define SCROLLER_GetClass() ({ \
  Class * _SCROLLER_GetClass__re = \
  ({ \
  register struct Library * const __SCROLLER_GetClass__bn __asm("a6") = (struct Library *) (SCROLLER_BASE_NAME);\
  register Class * __SCROLLER_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__SCROLLER_GetClass__re) \
  : "r"(__SCROLLER_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SCROLLER_GetClass__re; \
  }); \
  _SCROLLER_GetClass__re; \
})

#endif /*  _INLINE_SCROLLER_H  */
