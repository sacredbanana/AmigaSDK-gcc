/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MC680X0_H
#define _INLINE_MC680X0_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef MC680X0_BASE_NAME
#define MC680X0_BASE_NAME MC680x0Base
#endif /* !MC680X0_BASE_NAME */

#define CPUType() \
      LP0(0x1e, char, CPUType ,\
      , MC680X0_BASE_NAME)

#define FPUType() \
      LP0(0x24, char, FPUType ,\
      , MC680X0_BASE_NAME)

#define MMUType() \
      LP0(0x2a, char, MMUType ,\
      , MC680X0_BASE_NAME)

#define SetFPUExceptions(___flags, ___mask) \
      LP2(0x30, ULONG, SetFPUExceptions , ULONG, ___flags, d0, ULONG, ___mask, d1,\
      , MC680X0_BASE_NAME)

#endif /* !_INLINE_MC680X0_H */
