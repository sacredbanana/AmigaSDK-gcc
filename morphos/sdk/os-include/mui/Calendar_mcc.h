#ifndef CALENDAR_MCC_H
#define CALENDAR_MCC_H

/*
 *  Calendar.mcc
 *
 *  Copyright © 2023 Guido Mersmann <geit@geit.de>
 *  All rights reserved.
 *
 *  $Id: Calendar_mcc.h,v 1.26 2023/04/17 20:09:49 geit Exp $
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_CALENDAR_H
#include <libraries/calendar.h>
#endif

#pragma pack(2)

#define MUIC_Calendar  "Calendar.mcc"
#define CalendarObject MUI_NewObject(MUIC_Calendar

/* Attributes */

#define TAGBASE_Calendar                           ( (TAG_USER | (0xfde0 << 16) ) + 0x8200 )
#define MUIA_Calendar_Changed                      (TAGBASE_Calendar +  0)    /* ---N - (ULONG) */
#define MUIA_Calendar_Day                          (TAGBASE_Calendar +  1)    /* ISGN - (ULONG) */
#define MUIA_Calendar_Month                        (TAGBASE_Calendar +  2)    /* ISGN - (ULONG) */
#define MUIA_Calendar_Year                         (TAGBASE_Calendar +  3)    /* ISGN - (ULONG) */
#define MUIA_Calendar_ShowTitle                    (TAGBASE_Calendar +  4)    /* ISGN - (ULONG) */
#define MUIA_Calendar_Mode                         (TAGBASE_Calendar +  6)    /* ISGN - (ULONG) */
#define MUIA_Calendar_Compact                      (TAGBASE_Calendar +  7)    /* ISGN - (ULONG) */
#define MUIA_Calendar_PeekOver                     (TAGBASE_Calendar +  8)    /* ISGN - (ULONG) */
#define MUIA_Calendar_NotifyObject                 (TAGBASE_Calendar +  9)    /* ISG- - (Object*) - Object to send MUIM_Calendar_Notification to */
#define MUIA_Calendar_CalendarDate                 (TAGBASE_Calendar + 10)    /* ISG- - (struct CalendarDate *) */
#define MUIA_Calendar_DatabaseName                 (TAGBASE_Calendar + 11)    /* IS-- - (STRPTR) - calendar database file name */
#define MUIA_Calendar_ShowImages                   (TAGBASE_Calendar + 12)    /* ISGN - (ULONG) - show contents images */
#define MUIA_Calendar_ShowTimeLine                 (TAGBASE_Calendar + 13)    /* ISGN - (ULONG) - show contents time line */
#define MUIA_Calendar_ShowWeekdays                 (TAGBASE_Calendar + 14)    /* ISGN - (ULONG) - show weekday names */
#define MUIA_Calendar_CalendarDateBrowser          (TAGBASE_Calendar + 15)    /* ISG- - (struct CalendarDate *) - change view to this month/year */
#define MUIA_Calendar_MonthBrowser                 (TAGBASE_Calendar + 16)    /* ISGN - (ULONG) - change view to specific month */
#define MUIA_Calendar_YearBrowser                  (TAGBASE_Calendar + 17)    /* ISGN - (ULONG) - change view to specific year */
#define MUIA_Calendar_DayClick                     (TAGBASE_Calendar + 18)    /* --GN - (ULONG) - notification when user clicks on day. read gives day value */
#define MUIA_Calendar_DayDoubleClick               (TAGBASE_Calendar + 19)    /* --GN - (ULONG) - notification when user double clicks on day. read gives day value */
#define MUIA_Calendar_ContextEventID               (TAGBASE_Calendar + 20)    /* --G- - (ULONG) - only valid within MUIM_ContextMenuBuild/MUIM_ContextMenuChoice */
#define MUIA_Calendar_ContextCalendarDate          (TAGBASE_Calendar + 21)    /* --G- - (ULONG) - only valid within MUIM_ContextMenuBuild/MUIM_ContextMenuChoice */
#define MUIA_Calendar_BrowserChanged               (TAGBASE_Calendar + 22)    /* ---N - (ULONG) - user changed day, month or year */


/* Values for MUIA_Calendar_DayClick and MUIA_Calendar_DayDoubleClick 
**
** GetAttr() on both entries will return the day number and the flags
** below to indicate if a day number is within the peek over range.
**
** If MUIA_PeekOver is set to FALSE you can use the returned value
** right away. If your calendar object has peek over turned on, you
** MUST check the flags below to take a month change into evaluation.
**
** For example if the calendar shows the month March and the user
** clicks on the 28th of Feburary. MUIA_Calendar_DayClick will return:
** ( 28 | MUIV_Calendar_DayClick_PreviousMonth )
*/

#define MUIV_Calendar_DayClick_PreviousMonth        0x20000000   /* day is in previous month */
#define MUIV_Calendar_DayClick_NextMonth            0x10000000   /* day is in next month */

/* values for MUIA_Calendar_Mode */

#define MUIV_Calendar_Mode_None                     0  /* no user side interaction possible */
#define MUIV_Calendar_Mode_Days                     1  /* only the day can be modified by user */
#define MUIV_Calendar_Mode_Full                     2  /* year, month and day can be modified by user */
#define MUIV_Calendar_Mode_FullReadOnly             3  /* year, month and day can be modified by user, but
													   ** there is no way the user can change the actual
													   ** class date. Screenbar is using this mode, to allow
													   ** looking into a date, see what weekday it has and
													   ** if there is an entry. The cursor is only there to
													   ** keep the users focus on that day, while the actual
													   ** selection marks are unchangable. */

/* values for MUIM_Calendar_Notification */

#define MUIV_Calendar_NotifyMode_Click             0
#define MUIV_Calendar_NotifyMode_DoubleClick       1

/* Methods */

#define MUIM_Calendar_ReadSystemDate               (TAGBASE_Calendar +  0)
#define MUIM_Calendar_GetDaysInMonth               (TAGBASE_Calendar +  1)

#define MUIM_Calendar_Notification                 (TAGBASE_Calendar + 11)

/* Method Structure Messages */

struct MUIP_Calendar_ReadSystemDate       { ULONG MethodID; };
struct MUIP_Calendar_GetDaysInMonth       { ULONG MethodID; ULONG Month; ULONG Year; };

struct MUIP_Calendar_Notification         { ULONG MethodID; ULONG NotificationMode; struct CalendarDate *CalendarDate; ULONG EventID; };  /* send to the class, when day entry got clicked */

/* OBSOLETE DATA! DO NOT USE! */

#define MUIV_Calendar_Mode_MonthYear    MUIV_Calendar_Mode_FullReadOnly
#define MUIA_Calendar_ShowYear          (TAGBASE_Calendar +  5)    /* obsolete */

#pragma pack()

#endif /* CALENDAR_MCC_H */
