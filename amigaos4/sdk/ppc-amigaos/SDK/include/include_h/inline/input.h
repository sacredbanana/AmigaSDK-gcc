#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_INPUT_H
#define _INLINE_INPUT_H

#ifndef CLIB_INPUT_PROTOS_H
#define CLIB_INPUT_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INPUT_BASE_NAME
#define INPUT_BASE_NAME InputBase
#endif

#define PeekQualifier() ({ \
  UWORD _PeekQualifier__re = \
  ({ \
  register struct Device * const __PeekQualifier__bn __asm("a6") = (struct Device *) (INPUT_BASE_NAME);\
  register UWORD __PeekQualifier__re __asm("d0"); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__PeekQualifier__re) \
  : "r"(__PeekQualifier__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PeekQualifier__re; \
  }); \
  _PeekQualifier__re; \
})

#endif /*  _INLINE_INPUT_H  */
