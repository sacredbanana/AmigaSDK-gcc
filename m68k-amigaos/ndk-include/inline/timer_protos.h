/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_TIMER_H
#define _INLINE_TIMER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

VOID __AddTime(__reg("a6") struct Library * , __reg("a0") TimeVal_Type * dest , __reg("a1") CONST TimeVal_Type * src ) = "\tjsr\t-42(a6)";
#define AddTime(dest, src) __AddTime(TimerBase, (dest), (src))

VOID __SubTime(__reg("a6") struct Library * , __reg("a0") TimeVal_Type * dest , __reg("a1") CONST TimeVal_Type * src ) = "\tjsr\t-48(a6)";
#define SubTime(dest, src) __SubTime(TimerBase, (dest), (src))

LONG __CmpTime(__reg("a6") struct Library * , __reg("a0") CONST TimeVal_Type * dest , __reg("a1") CONST TimeVal_Type * src ) = "\tjsr\t-54(a6)";
#define CmpTime(dest, src) __CmpTime(TimerBase, (dest), (src))

ULONG __ReadEClock(__reg("a6") struct Library * , __reg("a0") struct EClockVal * dest ) = "\tjsr\t-60(a6)";
#define ReadEClock(dest) __ReadEClock(TimerBase, (dest))

VOID __GetSysTime(__reg("a6") struct Library * , __reg("a0") TimeVal_Type * dest ) = "\tjsr\t-66(a6)";
#define GetSysTime(dest) __GetSysTime(TimerBase, (dest))

#endif /* !_INLINE_TIMER_H */
