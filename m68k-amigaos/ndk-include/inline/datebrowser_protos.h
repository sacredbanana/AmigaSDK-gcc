/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_DATEBROWSER_H
#define _INLINE_DATEBROWSER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

Class * __DATEBROWSER_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define DATEBROWSER_GetClass() __DATEBROWSER_GetClass(DateBrowserBase)

UWORD __JulianWeekDay(__reg("a6") struct Library * , __reg("d0") ULONG day , __reg("d1") ULONG month , __reg("d2") LONG year ) = "\tjsr\t-36(a6)";
#define JulianWeekDay(day, month, year) __JulianWeekDay(DateBrowserBase, (day), (month), (year))

UWORD __JulianMonthDays(__reg("a6") struct Library * , __reg("d0") ULONG month , __reg("d1") LONG year ) = "\tjsr\t-42(a6)";
#define JulianMonthDays(month, year) __JulianMonthDays(DateBrowserBase, (month), (year))

BOOL __JulianLeapYear(__reg("a6") struct Library * , __reg("d0") LONG year ) = "\tjsr\t-48(a6)";
#define JulianLeapYear(year) __JulianLeapYear(DateBrowserBase, (year))

#endif /* !_INLINE_DATEBROWSER_H */
