/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_INTEGER_H
#define _INLINE_INTEGER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

Class * __INTEGER_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define INTEGER_GetClass() __INTEGER_GetClass(IntegerBase)

#endif /* !_INLINE_INTEGER_H */
