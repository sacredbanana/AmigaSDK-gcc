/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_EXPANSION_H
#define _INLINE_EXPANSION_H

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

#ifndef EXPANSION_BASE_NAME
#define EXPANSION_BASE_NAME ExpansionBase
#endif /* !EXPANSION_BASE_NAME */

#define AddConfigDev(___configDev) \
      LP1NR(0x1e, AddConfigDev , struct ConfigDev *, ___configDev, a0,\
      , EXPANSION_BASE_NAME)

#endif /* !_INLINE_EXPANSION_H */
