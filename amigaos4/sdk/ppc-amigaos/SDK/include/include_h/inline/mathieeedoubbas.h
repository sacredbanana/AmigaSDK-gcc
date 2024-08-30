#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_MATHIEEEDOUBBAS_H
#define _INLINE_MATHIEEEDOUBBAS_H

#ifndef CLIB_MATHIEEEDOUBBAS_PROTOS_H
#define CLIB_MATHIEEEDOUBBAS_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef MATHIEEEDOUBBAS_BASE_NAME
#define MATHIEEEDOUBBAS_BASE_NAME MathIeeeDoubBasBase
#endif

#define IEEEDPFlt(integer) ({ \
  LONG _IEEEDPFlt_integer = (integer); \
  DOUBLE _IEEEDPFlt__re = \
  ({ \
  register struct MathIEEEBase * const __IEEEDPFlt__bn __asm("a6") = (struct MathIEEEBase *) (MATHIEEEDOUBBAS_BASE_NAME);\
  register DOUBLE __IEEEDPFlt__re __asm("d0"); \
  register LONG __IEEEDPFlt_integer __asm("d0") = (_IEEEDPFlt_integer); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__IEEEDPFlt__re) \
  : "r"(__IEEEDPFlt__bn), "r"(__IEEEDPFlt_integer) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IEEEDPFlt__re; \
  }); \
  _IEEEDPFlt__re; \
})

#endif /*  _INLINE_MATHIEEEDOUBBAS_H  */
