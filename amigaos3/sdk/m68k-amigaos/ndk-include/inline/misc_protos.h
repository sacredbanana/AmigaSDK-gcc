/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MISC_H
#define _INLINE_MISC_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

UBYTE * __AllocMiscResource(__reg("a6") struct Library * , __reg("d0") ULONG unitNum , __reg("a1") CONST_STRPTR name ) = "\tjsr\t-6(a6)";
#define AllocMiscResource(unitNum, name) __AllocMiscResource(MiscBase, (unitNum), (name))

VOID __FreeMiscResource(__reg("a6") struct Library * , __reg("d0") ULONG unitNum ) = "\tjsr\t-12(a6)";
#define FreeMiscResource(unitNum) __FreeMiscResource(MiscBase, (unitNum))

#endif /* !_INLINE_MISC_H */
