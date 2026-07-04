#ifndef LIBRARIES_CALENDAR_H
#define LIBRARIES_CALENDAR_H

/*************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_UTILITY_H
#include <utility/tagitem.h>
#endif

/*************************************************************************/

#define CALENDAR_NAME                  "calendar.library"   /* library name */
#define CALENDAR_MINVERSION            23

#define CALENDAR_DATABASENAME_DEFAULT   ((STRPTR)1)  /* This is a special value for opening the database. The system default database will be used */

/*************************************************************************/

#define CALENDAR_ERROR_NOERROR               0   /* everything is fine */
#define CALENDAR_ERROR_NOMOREENTRIES         2   /* everything is fine, scan just finished */
#define CALENDAR_ERROR_OUTOFMEMORY           3   /* low memory condition */
#define CALENDAR_ERROR_DATABASEERROR         4   /* for some reason database communication failed */
#define CALENDAR_ERROR_APIERROR              5   /* application used API wrong */
#define CALENDAR_ERROR_OUTOFBOUNDS           6   /* Calendar_CalendarDate(Add|Sub) year limit reached */
#define CALENDAR_ERROR_FAILEDTOREADDATETIME  7   /* potential Calendar_ReadDateTime() result */

/*************************************************************************/

/* CalendarDate structure 
**
** The CalendarDate structure is equal to ClockData structure provided
** by <utility/data.h>, but way more readable.
**
** Please note that cd_Second and cd_Weekday are not used by calendar.library.
**
*/
#pragma pack(2)

struct CalendarDate {
	UWORD cd_Second;
	UWORD cd_Minute;
	UWORD cd_Hour;
	UWORD cd_Day;
	UWORD cd_Month;
	UWORD cd_Year;
	UWORD cd_Weekday;
};

#pragma pack()

/*************************************************************************/

/* Calendar Context Tags */

#define TAGBASE_LibCalendar                       (TAG_USER)
#define CED_Calendar_EventID                      (TAGBASE_LibCalendar + 21)    /* -Q - (ULONG)  - unique database entry id */
#define CED_Calendar_EventColor                   (TAGBASE_LibCalendar + 22)    /* SQ - (ARGB)   - event color */
#define CED_Calendar_EventImageType               (TAGBASE_LibCalendar + 23)    /* SQ - (ULONG)  - defines the image attached to an entry */
#define CED_Calendar_EventFrequency               (TAGBASE_LibCalendar + 24)    /* SQ - (ULONG)  - type of event repeat */
#define CED_Calendar_EventEvery                   (TAGBASE_LibCalendar + 25)    /* SQ - (ULONG)  - every (day/week/month/year) number - default 1 */
#define CED_Calendar_EventLocation                (TAGBASE_LibCalendar + 26)    /* SQ - (STRPTR) - UTF-8 location string */
#define CED_Calendar_EventCalendarDateStart       (TAGBASE_LibCalendar + 27)    /* SQ - (struct CalendarDate *) - event start. */
#define CED_Calendar_EventCalendarDateEnd         (TAGBASE_LibCalendar + 28)    /* SQ - (struct CalendarDate *) - event end. */
#define CED_Calendar_EventCalendarDateUntil       (TAGBASE_LibCalendar + 29)    /* SQ - (struct CalendarDate *) - event repeat end date */
#define CED_Calendar_EventDateStringStart         (TAGBASE_LibCalendar + 30)    /* S- - (STRPTR) - event start. format is "YYYY-MM-DD HH:MM" */
#define CED_Calendar_EventDateStringEnd           (TAGBASE_LibCalendar + 31)    /* S- - (STRPTR) - event end. format is "YYYY-MM-DD HH:MM" */
#define CED_Calendar_EventDateStringUntil         (TAGBASE_LibCalendar + 32)    /* S- - (STRPTR) - event until format is "YYYY-MM-DD HH:MM" */
#define CED_Calendar_EventDateStampStart          (TAGBASE_LibCalendar + 33)    /* SQ - (struct DateStamp *) - event start */
#define CED_Calendar_EventDateStampEnd            (TAGBASE_LibCalendar + 34)    /* SQ - (struct DateStamp *) - event end */
#define CED_Calendar_EventDateStampUntil          (TAGBASE_LibCalendar + 35)    /* SQ - (struct DateStamp *) - event repeat end */
#define CED_Calendar_EventUntilForever            (TAGBASE_LibCalendar + 36)    /* SQ - (ULONG)  - set to non zero the event has no end */
#define CED_Calendar_EventTitle                   (TAGBASE_LibCalendar + 37)    /* SQ - (STRPTR) - event title in UTF-8 format */
#define CED_Calendar_EventNotes                   (TAGBASE_LibCalendar + 38)    /* SQ - (STRPTR) - event notes in UTF-8 format */
#define CED_Calendar_EventImageName               (TAGBASE_LibCalendar + 39)    /* SQ - (STRPTR) - icon file name */
#define CED_Calendar_EventUserData                (TAGBASE_LibCalendar + 40)    /* SQ - (STRPTR) - application user data. ### POINTERS ARE NOT ALLOWED ### */
#define CED_Calendar_EventAlert1                  (TAGBASE_LibCalendar + 41)    /* SQ - (ULONG)  - event alert as defined below */
#define CED_Calendar_EventAlert2                  (TAGBASE_LibCalendar + 42)    /* SQ - (ULONG)  - event alert as defined below */
#define CED_Calendar_EventWayTime                 (TAGBASE_LibCalendar + 43)    /* SQ - (ULONG) */
#define CED_Calendar_EventURL                     (TAGBASE_LibCalendar + 44)    /* SQ - (ULONG)  - event URL */
#define CED_Calendar_EventCustomFrequency         (TAGBASE_LibCalendar + 45)    /* SQ - (ULONG)  - event custom repeat */
#define CED_Calendar_EventCustomMask              (TAGBASE_LibCalendar + 46)    /* SQ - (ULONG)  - day/month/weekday bitfield (10th is 1<<10) */
#define CED_Calendar_EventCustomEvery             (TAGBASE_LibCalendar + 47)    /* SQ - (ULONG)  - CED_Calendar_EventCustomEvery_#? types as defined below */
#define CED_Calendar_EventCustomEveryType         (TAGBASE_LibCalendar + 48)    /* SQ - (ULONG)  - CED_Calendar_EventCustomEveryType#? types as defined below */
#define CED_Calendar_EventCustomEveryEnable       (TAGBASE_LibCalendar + 49)    /* SQ - (ULONG)  - set to non zero the to enable CustomEvery#? */
#define CED_Calendar_EventCalendarDateLastChange  (TAGBASE_LibCalendar + 50)    /* -Q - (struct CalendarDate *) - date this entry was modified the last time */


/* values for CED_Calendar_EventImage */

#define CED_Calendar_EventImageType_None                    0     /* no image for this event */
#define CED_Calendar_EventImageType_Note                    1     /* default when no type was specified */
#define CED_Calendar_EventImageType_Custom                  2     /* use custom image name from application */
#define CED_Calendar_EventImageType_Birthday                3
#define CED_Calendar_EventImageType_Holiday                 4
#define CED_Calendar_EventImageType_Party                   5
#define CED_Calendar_EventImageType_Meeting                 6
#define CED_Calendar_EventImageType_Date                    7
#define CED_Calendar_EventImageType_Work                    8
#define CED_Calendar_EventImageType_Star                    9
#define CED_Calendar_EventImageType_Trash1                 10     /* paper */
#define CED_Calendar_EventImageType_Trash2                 11     /* plastics */
#define CED_Calendar_EventImageType_Trash3                 12     /* organic */
#define CED_Calendar_EventImageType_Trash4                 13     /* residual */
#define CED_Calendar_EventImageType_Trash5                 14     /* hazardous */
#define CED_Calendar_EventImageType_Dentist                15
#define CED_Calendar_EventImageType_Doctor                 16
#define CED_Calendar_EventImageType_Shopping               17
#define CED_Calendar_EventImageType_Wedding                18
#define CED_Calendar_EventImageType_Flight                 19


/* values for CED_Calendar_EventRepeat */

#define CED_Calendar_EventFrequency_None                    0
#define CED_Calendar_EventFrequency_Daily                   1
#define CED_Calendar_EventFrequency_Weekly                  7
#define CED_Calendar_EventFrequency_2Week                  14
#define CED_Calendar_EventFrequency_Monthly                31
#define CED_Calendar_EventFrequency_Yearly                365
#define CED_Calendar_EventFrequency_Custom                  2

/* values for CED_Calendar_EventCustomRepeat */

#define CED_Calendar_EventCustomFrequency_Daily             1
#define CED_Calendar_EventCustomFrequency_Weekly            7
#define CED_Calendar_EventCustomFrequency_Monthly          31
#define CED_Calendar_EventCustomFrequency_Yearly          365

/* values for CED_Calendar_EventCustomEvery */

#define CED_Calendar_EventCustomEvery_First                 0
#define CED_Calendar_EventCustomEvery_Second                1
#define CED_Calendar_EventCustomEvery_Third                 2
#define CED_Calendar_EventCustomEvery_Fourth                3
#define CED_Calendar_EventCustomEvery_Fifth                 4
#define CED_Calendar_EventCustomEvery_Last                  5

/* values for CED_Calendar_EventCustomEveryType */

#define CED_Calendar_EventCustomEveryType_Monday            0
#define CED_Calendar_EventCustomEveryType_Tuesday           1
#define CED_Calendar_EventCustomEveryType_Wednesday         2
#define CED_Calendar_EventCustomEveryType_Thursday          3
#define CED_Calendar_EventCustomEveryType_Friday            4
#define CED_Calendar_EventCustomEveryType_Saturday          5
#define CED_Calendar_EventCustomEveryType_Sunday            6
#define CED_Calendar_EventCustomEveryType_Day               7
#define CED_Calendar_EventCustomEveryType_Weekday           8
#define CED_Calendar_EventCustomEveryType_Weekend           9

/* values for CED_Calendar_WayTime */

#define CED_Calendar_WayTime_None                           0
#define CED_Calendar_WayTime_Minutes05                      5
#define CED_Calendar_WayTime_Minutes10                     10
#define CED_Calendar_WayTime_Minutes15                     15
#define CED_Calendar_WayTime_Minutes30                     30
#define CED_Calendar_WayTime_Minutes60                     60
#define CED_Calendar_WayTime_Minutes90                     90
#define CED_Calendar_WayTime_Minutes120                   120

/* values for CED_Calendar_EventAlert#? */

#define CED_Calendar_EventAlert_None                       0
#define CED_Calendar_EventAlert_Minutes05                  5
#define CED_Calendar_EventAlert_Minutes10                 10
#define CED_Calendar_EventAlert_Minutes15                 15
#define CED_Calendar_EventAlert_Minutes30                 30
#define CED_Calendar_EventAlert_Minutes60                 60
#define CED_Calendar_EventAlert_Minutes120               120
#define CED_Calendar_EventAlert_Days1                   1440
#define CED_Calendar_EventAlert_Days2                   2880
#define CED_Calendar_EventAlert_Week1                  10080

/* values for  MUIT_Calendar_ContentsColor */

#define CED_Calendar_EventColor_Off               0x12345678   /* this value disables color */

/* notification tag data for Calendar_NotificationAddTagList()
** NOTE: These flags are grouped. You will get CHANGEDATE and CHANGE
** in combination with ACTION related flags. So you will receive a ACTIONREMOVE
** before the removal action and ACTIONREMOVE together with CHANGEDATE and
** CHANGE after the entry got removed.
** Also note that ACTION_ADD will be send only once to avoid multiple notifications on the
** same thing. Internally it is split in ACTION_ADD and ACTION_SET, so you will receive ADD 
** followed by SET.
**
** These flags are used upon hook adding and an application will only receive notification
** calls on the hook where these initial flags are set. However you will get all flags and
** they are valid. e.g. using EVENTCHANGEDATE on hook creation, will also deliver any
** ACTION or EVENT flags.
**
** The ACTION type flags are just additional information and will be delivered along with
** EVENT flags anyway. When enabled you will get informed begore any change tooks place,
** which may be handy, as you get informed before any removal or adding of database nodes.
** 
*/


#define CNH_Calendar_Hook                              (TAGBASE_LibCalendar + 1 )
#define CNH_Calendar_SignalMask                        (TAGBASE_LibCalendar + 2 )
#define CNH_Calendar_Task                              (TAGBASE_LibCalendar + 3 )

#define CALENDARNOTIFY_EVENTCHANGEDATE            1   /* start, end or repeat changed  */
#define CALENDARNOTIFY_EVENTCHANGE                2   /* non date related data changed */
#define CALENDARNOTIFY_ACTIONSET               1024   /* specified event got modified */
#define CALENDARNOTIFY_ACTIONADD               2048   /* specified event will be or got added */
#define CALENDARNOTIFY_ACTIONREMOVE            4096   /* specified event will be or got removed */
#define CALENDARNOTIFY_ACTIONREMOVEALL         8192   /* specified all events will be or got removed */

/*************************************************************************/

#endif /* LIBRARIES_CALENDAR_H */
