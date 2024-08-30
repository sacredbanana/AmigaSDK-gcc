/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_BATTMEM_H
#define _INLINE_BATTMEM_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

VOID __ObtainBattSemaphore(__reg("a6") struct Library * ) = "\tjsr\t-6(a6)";
#define ObtainBattSemaphore() __ObtainBattSemaphore(BattMemBase)

VOID __ReleaseBattSemaphore(__reg("a6") struct Library * ) = "\tjsr\t-12(a6)";
#define ReleaseBattSemaphore() __ReleaseBattSemaphore(BattMemBase)

ULONG __ReadBattMem(__reg("a6") struct Library * , __reg("a0") APTR buffer , __reg("d0") ULONG offset , __reg("d1") ULONG length ) = "\tjsr\t-18(a6)";
#define ReadBattMem(buffer, offset, length) __ReadBattMem(BattMemBase, (buffer), (offset), (length))

ULONG __WriteBattMem(__reg("a6") struct Library * , __reg("a0") CONST_APTR buffer , __reg("d0") ULONG offset , __reg("d1") ULONG length ) = "\tjsr\t-24(a6)";
#define WriteBattMem(buffer, offset, length) __WriteBattMem(BattMemBase, (buffer), (offset), (length))

#endif /* !_INLINE_BATTMEM_H */
