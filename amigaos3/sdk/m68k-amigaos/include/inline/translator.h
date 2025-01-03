/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_TRANSLATOR_H
#define _INLINE_TRANSLATOR_H

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

#ifndef TRANSLATOR_BASE_NAME
#define TRANSLATOR_BASE_NAME TranslatorBase
#endif /* !TRANSLATOR_BASE_NAME */

#define Translate(___inputString, ___inputLength, ___outputBuffer, ___bufferSize) \
      LP4(0x1e, LONG, Translate , CONST_STRPTR, ___inputString, a0, LONG, ___inputLength, d0, STRPTR, ___outputBuffer, a1, LONG, ___bufferSize, d1,\
      , TRANSLATOR_BASE_NAME)
#define TranslateAs(___inputString, ___inputLength, ___outputBuffer, ___bufferSize, ___outputType) \
      LP5(0x24, LONG, TranslateAs , CONST_STRPTR, ___inputString, a0, LONG, ___inputLength, d0, STRPTR, ___outputBuffer, a1, LONG, ___bufferSize, d1, LONG, ___outputType, d2,\
      , TRANSLATOR_BASE_NAME)
#define LoadAccent(___accentName) \
      LP1(0x2a, LONG, LoadAccent , CONST_STRPTR, ___accentName, a0,\
      , TRANSLATOR_BASE_NAME)
#define SetAccent(___accentName) \
      LP1(0x30, LONG, SetAccent , CONST_STRPTR, ___accentName, a0,\
      , TRANSLATOR_BASE_NAME)

#endif /* !_INLINE_TRANSLATOR_H */
