/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MC68060_H
#define _INLINE_MC68060_H

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

#ifndef MC68060_BASE_NAME
#define MC68060_BASE_NAME MC68060Base
#endif /* !MC68060_BASE_NAME */

#define FPUControl(___flags, ___mask) \
      LP2(0xde, ULONG, FPUControl , ULONG, ___flags, d0, ULONG, ___mask, d1,\
      , MC68060_BASE_NAME)

#endif /* !_INLINE_MC68060_H */
