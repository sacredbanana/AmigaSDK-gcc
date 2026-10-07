#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_REQUESTER_H
#define _INLINE_REQUESTER_H

#ifndef CLIB_REQUESTER_PROTOS_H
#define CLIB_REQUESTER_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifndef REQUESTER_BASE_NAME
#define REQUESTER_BASE_NAME RequesterBase
#endif

#define REQUESTER_GetClass() ({ \
  Class * _REQUESTER_GetClass__re = \
  ({ \
  register struct Library * const __REQUESTER_GetClass__bn __asm("a6") = (struct Library *) (REQUESTER_BASE_NAME);\
  register Class * __REQUESTER_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__REQUESTER_GetClass__re) \
  : "r"(__REQUESTER_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __REQUESTER_GetClass__re; \
  }); \
  _REQUESTER_GetClass__re; \
})

#endif /*  _INLINE_REQUESTER_H  */
