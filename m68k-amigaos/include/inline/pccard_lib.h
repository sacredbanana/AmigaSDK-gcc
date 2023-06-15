/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_PCCARD_H
#define _INLINE_PCCARD_H

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

#ifndef PCCARD_BASE_NAME
#define PCCARD_BASE_NAME PCCardBase
#endif /* !PCCARD_BASE_NAME */

#define PCCard_GetTupleInfo(___tuple) \
      LP1(0x1e, const struct TagItem *, PCCard_GetTupleInfo , const UBYTE *, ___tuple, a0,\
      , PCCARD_BASE_NAME)

#define PCCard_FreeTupleInfo(___tagList) \
      LP1NR(0x24, PCCard_FreeTupleInfo , const struct TagItem *, ___tagList, a0,\
      , PCCARD_BASE_NAME)

#define PCCard_GetFuncETupleInfo(___tuple, ___funcID) \
      LP2(0x2a, const struct TagItem *, PCCard_GetFuncETupleInfo , const UBYTE *, ___tuple, a0, const UBYTE, ___funcID, d0,\
      , PCCARD_BASE_NAME)

#endif /* !_INLINE_PCCARD_H */
