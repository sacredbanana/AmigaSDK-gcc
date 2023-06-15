/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_BATTCLOCK_H
#define _INLINE_BATTCLOCK_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

VOID __ResetBattClock(__reg("a6") struct Library * ) = "\tjsr\t-6(a6)";
#define ResetBattClock() __ResetBattClock(BattClockBase)

ULONG __ReadBattClock(__reg("a6") struct Library * ) = "\tjsr\t-12(a6)";
#define ReadBattClock() __ReadBattClock(BattClockBase)

VOID __WriteBattClock(__reg("a6") struct Library * , __reg("d0") ULONG time ) = "\tjsr\t-18(a6)";
#define WriteBattClock(time) __WriteBattClock(BattClockBase, (time))

#endif /* !_INLINE_BATTCLOCK_H */
