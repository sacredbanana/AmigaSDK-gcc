/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MC68040_H
#define _INLINE_MC68040_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

ULONG __FPUControl(__reg("a6") struct Library * , __reg("d0") ULONG flags , __reg("d1") ULONG mask ) = "\tjsr\t-222(a6)";
#define FPUControl(flags, mask) __FPUControl(MC68040Base, (flags), (mask))

#endif /* !_INLINE_MC68040_H */
