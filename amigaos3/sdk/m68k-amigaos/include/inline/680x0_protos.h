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

char __CPUType(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define CPUType() __CPUType(MC680x0Base)

char __FPUType(__reg("a6") struct Library * ) = "\tjsr\t-36(a6)";
#define FPUType() __FPUType(MC680x0Base)

char __MMUType(__reg("a6") struct Library * ) = "\tjsr\t-42(a6)";
#define MMUType() __MMUType(MC680x0Base)

ULONG __SetFPUExceptions(__reg("a6") struct Library * , __reg("d0") ULONG flags , __reg("d1") ULONG mask ) = "\tjsr\t-48(a6)";
#define SetFPUExceptions(flags, mask) __SetFPUExceptions(MC680x0Base, (flags), (mask))

#endif /* !_INLINE_MC680X0_H */
