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

LONG __Translate(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR inputString , __reg("d0") LONG inputLength , __reg("a1") STRPTR outputBuffer , __reg("d1") LONG bufferSize ) = "\tjsr\t-30(a6)";
#define Translate(inputString, inputLength, outputBuffer, bufferSize) __Translate(TranslatorBase, (inputString), (inputLength), (outputBuffer), (bufferSize))

#endif /* !_INLINE_TRANSLATOR_H */
