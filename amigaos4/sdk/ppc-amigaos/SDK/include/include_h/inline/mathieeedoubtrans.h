#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_MATHIEEEDOUBTRANS_H
#define _INLINE_MATHIEEEDOUBTRANS_H

#ifndef CLIB_MATHIEEEDOUBTRANS_PROTOS_H
#define CLIB_MATHIEEEDOUBTRANS_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef MATHIEEEDOUBTRANS_BASE_NAME
#define MATHIEEEDOUBTRANS_BASE_NAME MathIeeeDoubTransBase
#endif

#define IEEEDPFieee(single) ({ \
  FLOAT _IEEEDPFieee_single = (single); \
  DOUBLE _IEEEDPFieee__re = \
  ({ \
  register struct MathIEEEBase * const __IEEEDPFieee__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEEDOUBTRANS_BASE_NAME);\
  register DOUBLE __IEEEDPFieee__re __asm("d0"); \
  register FLOAT __IEEEDPFieee_single __asm("d0") = (_IEEEDPFieee_single); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__IEEEDPFieee__re) \
  : "r"(__IEEEDPFieee__bn), "r"(__IEEEDPFieee_single) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEEDPFieee__re; \
  }); \
  _IEEEDPFieee__re; \
})

#endif /*  _INLINE_MATHIEEEDOUBTRANS_H  */
