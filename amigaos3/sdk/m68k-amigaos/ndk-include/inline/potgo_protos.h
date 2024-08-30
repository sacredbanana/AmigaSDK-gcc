/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_POTGO_H
#define _INLINE_POTGO_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

UWORD __AllocPotBits(__reg("a6") struct Library * , __reg("d0") UWORD bits ) = "\tjsr\t-6(a6)";
#define AllocPotBits(bits) __AllocPotBits(PotgoBase, (bits))

VOID __FreePotBits(__reg("a6") struct Library * , __reg("d0") UWORD bits ) = "\tjsr\t-12(a6)";
#define FreePotBits(bits) __FreePotBits(PotgoBase, (bits))

VOID __WritePotgo(__reg("a6") struct Library * , __reg("d0") UWORD word , __reg("d1") UWORD mask ) = "\tjsr\t-18(a6)";
#define WritePotgo(word, mask) __WritePotgo(PotgoBase, (word), (mask))

#endif /* !_INLINE_POTGO_H */
