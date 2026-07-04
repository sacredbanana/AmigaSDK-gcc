/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CALENDAR_H
#define _PPCINLINE_CALENDAR_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CALENDAR_BASE_NAME
#define CALENDAR_BASE_NAME CalendarBase
#endif /* !CALENDAR_BASE_NAME */

#define Calendar_ReadDateTime(__p0) \
	(((IPTR (*)(void *, struct CalendarDate *))*(void**)((long)(CALENDAR_BASE_NAME) - 28))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_ValidateDate(__p0, __p1) \
	(((IPTR (*)(void *, struct CalendarDate *, BOOL ))*(void**)((long)(CALENDAR_BASE_NAME) - 34))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_ValidateDateRange(__p0, __p1, __p2) \
	(((IPTR (*)(void *, struct CalendarDate *, struct CalendarDate *, BOOL ))*(void**)((long)(CALENDAR_BASE_NAME) - 40))((void*)(CALENDAR_BASE_NAME), __p0, __p1, __p2))

#define Calendar_ConvertToJulianDay(__p0) \
	(((IPTR (*)(void *, struct CalendarDate *))*(void**)((long)(CALENDAR_BASE_NAME) - 46))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_ConvertFromJulianDay(__p0, __p1) \
	(((void (*)(void *, struct CalendarDate *, IPTR ))*(void**)((long)(CALENDAR_BASE_NAME) - 52))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_GetDaysInMonth(__p0, __p1) \
	(((UWORD (*)(void *, UWORD , UWORD ))*(void**)((long)(CALENDAR_BASE_NAME) - 58))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_GetWeeksInYear(__p0) \
	(((UWORD (*)(void *, UWORD ))*(void**)((long)(CALENDAR_BASE_NAME) - 64))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_GetWeekOfYear(__p0) \
	(((IPTR (*)(void *, struct CalendarDate *))*(void**)((long)(CALENDAR_BASE_NAME) - 70))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_GetDayOfWeek(__p0) \
	(((UWORD (*)(void *, struct CalendarDate *))*(void**)((long)(CALENDAR_BASE_NAME) - 76))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_GetDayOfYear(__p0) \
	(((IPTR (*)(void *, struct CalendarDate *))*(void**)((long)(CALENDAR_BASE_NAME) - 82))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_GetLastDayOfWeek(__p0, __p1, __p2) \
	(((UWORD (*)(void *, UWORD , UWORD , UWORD ))*(void**)((long)(CALENDAR_BASE_NAME) - 88))((void*)(CALENDAR_BASE_NAME), __p0, __p1, __p2))

#define Calendar_GetFirstDayOfWeek(__p0, __p1, __p2) \
	(((UWORD (*)(void *, UWORD , UWORD , UWORD ))*(void**)((long)(CALENDAR_BASE_NAME) - 94))((void*)(CALENDAR_BASE_NAME), __p0, __p1, __p2))

#define Calendar_CalendarDateAdd(__p0, __p1, __p2, __p3, __p4) \
	(((UWORD (*)(void *, struct LibBase *, struct CalendarDate *, UWORD , UWORD , UWORD ))*(void**)((long)(CALENDAR_BASE_NAME) - 100))((void*)(CALENDAR_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define Calendar_CalendarDateSub(__p0, __p1, __p2, __p3, __p4) \
	(((UWORD (*)(void *, struct LibBase *, struct CalendarDate *, UWORD , UWORD , UWORD ))*(void**)((long)(CALENDAR_BASE_NAME) - 106))((void*)(CALENDAR_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define Calendar_Reserved1() \
	(((IPTR (*)(void *))*(void**)((long)(CALENDAR_BASE_NAME) - 112))((void*)(CALENDAR_BASE_NAME)))

#define Calendar_Reserved2() \
	(((IPTR (*)(void *))*(void**)((long)(CALENDAR_BASE_NAME) - 118))((void*)(CALENDAR_BASE_NAME)))

#define Calendar_Reserved3() \
	(((IPTR (*)(void *))*(void**)((long)(CALENDAR_BASE_NAME) - 124))((void*)(CALENDAR_BASE_NAME)))

#define Calendar_Reserved4() \
	(((IPTR (*)(void *))*(void**)((long)(CALENDAR_BASE_NAME) - 130))((void*)(CALENDAR_BASE_NAME)))

#define Calendar_DatabaseOpenTagList(__p0, __p1) \
	(((APTR (*)(void *, STRPTR , struct TagItem *))*(void**)((long)(CALENDAR_BASE_NAME) - 136))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_DatabaseClose(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(CALENDAR_BASE_NAME) - 142))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_EventAddTagList(__p0, __p1) \
	(((IPTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(CALENDAR_BASE_NAME) - 148))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_EventRemove(__p0, __p1) \
	(((IPTR (*)(void *, APTR , IPTR ))*(void**)((long)(CALENDAR_BASE_NAME) - 154))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_EventRemoveAll(__p0) \
	(((IPTR (*)(void *, APTR ))*(void**)((long)(CALENDAR_BASE_NAME) - 160))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_EventCheck(__p0, __p1) \
	(((IPTR (*)(void *, APTR , IPTR ))*(void**)((long)(CALENDAR_BASE_NAME) - 166))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_EventSetTagList(__p0, __p1) \
	(((IPTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(CALENDAR_BASE_NAME) - 172))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_EventQueryBeginTagList(__p0, __p1) \
	(((APTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(CALENDAR_BASE_NAME) - 178))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_EventQueryTagList(__p0, __p1) \
	(((IPTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(CALENDAR_BASE_NAME) - 184))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_EventQueryDayTagList(__p0, __p1) \
	(((IPTR (*)(void *, APTR , struct TagItem *))*(void**)((long)(CALENDAR_BASE_NAME) - 190))((void*)(CALENDAR_BASE_NAME), __p0, __p1))

#define Calendar_EventQueryEnd(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(CALENDAR_BASE_NAME) - 196))((void*)(CALENDAR_BASE_NAME), __p0))

#define Calendar_NotificationAddTagList(__p0, __p1, __p2) \
	(((APTR (*)(void *, APTR , IPTR , struct TagItem *))*(void**)((long)(CALENDAR_BASE_NAME) - 202))((void*)(CALENDAR_BASE_NAME), __p0, __p1, __p2))

#define Calendar_NotificationRemove(__p0, __p1) \
	(((IPTR (*)(void *, APTR , APTR ))*(void**)((long)(CALENDAR_BASE_NAME) - 208))((void*)(CALENDAR_BASE_NAME), __p0, __p1))


#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define Calendar_DatabaseOpenTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	Calendar_DatabaseOpenTagList(__p0, (struct TagItem *)_tags);})

#define Calendar_EventAddTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	Calendar_EventAddTagList(__p0, (struct TagItem *)_tags);})

#define Calendar_EventSetTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	Calendar_EventSetTagList(__p0, (struct TagItem *)_tags);})

#define Calendar_EventQueryBeginTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	Calendar_EventQueryBeginTagList(__p0, (struct TagItem *)_tags);})

#define Calendar_EventQueryTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	Calendar_EventQueryTagList(__p0, (struct TagItem *)_tags);})

#define Calendar_EventQueryDayTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	Calendar_EventQueryDayTagList(__p0, (struct TagItem *)_tags);})

#define Calendar_NotificationAddTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	Calendar_NotificationAddTagList(__p0, __p1, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_CALENDAR_H */
