#ifndef CLIB_CALENDAR_PROTOS_H
#define CLIB_CALENDAR_PROTOS_H

/***************************************************************************/

/*
**  $VER: calendar_protos.h 1.0 (01.03.2023)
**
**   Copyright (C) 2023 Guido Mersmann <geit@gmx.de>
**   All rights reserved.
*/

/***************************************************************************/

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***************************************************************************/
IPTR                         Calendar_ReadDateTime( struct CalendarDate *cd );
IPTR                         Calendar_ValidateDate( struct CalendarDate *cd, BOOL FixDate );
IPTR                         Calendar_ValidateDateRange( struct CalendarDate *start, struct CalendarDate *end, BOOL FixDate );

IPTR                         Calendar_ConvertToJulianDay( struct CalendarDate *cd );
void                         Calendar_ConvertFromJulianDay( struct CalendarDate *cd, IPTR JulianDay );
UWORD                        Calendar_GetDaysInMonth( UWORD month, UWORD year );
UWORD                        Calendar_GetWeeksInYear( UWORD year );
IPTR                         Calendar_GetWeekOfYear( struct CalendarDate *cd );
UWORD                        Calendar_GetDayOfWeek( struct CalendarDate *cd );
IPTR                         Calendar_GetDayOfYear( struct CalendarDate *cd );
UWORD                        Calendar_GetLastDayOfWeek( UWORD month, UWORD year, UWORD weekday );
UWORD                        Calendar_GetFirstDayOfWeek( UWORD month, UWORD year, UWORD weekday );
UWORD                        Calendar_CalendarDateAdd( struct LibBase *MyLibBase, struct CalendarDate *cd, UWORD days, UWORD months, UWORD years );
UWORD                        Calendar_CalendarDateSub( struct LibBase *MyLibBase, struct CalendarDate *cd, UWORD days, UWORD months, UWORD years );
IPTR                         Calendar_Reserved1( void );
IPTR                         Calendar_Reserved2( void );
IPTR                         Calendar_Reserved3( void );
IPTR                         Calendar_Reserved4( void );

APTR                         Calendar_DatabaseOpenTagList( STRPTR name, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
APTR                         Calendar_DatabaseOpenTags( STRPTR name, IPTR tag, ... );
#endif
void                         Calendar_DatabaseClose( APTR cdb );
IPTR                         Calendar_EventAddTagList( APTR cdb, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
IPTR                         Calendar_EventAddTags( APTR cdb, IPTR tag, ... );
#endif
IPTR                         Calendar_EventRemove( APTR cdb, IPTR EventID );
IPTR                         Calendar_EventRemoveAll( APTR cdb );
IPTR                         Calendar_EventCheck( APTR cdb, IPTR EventID );
IPTR                         Calendar_EventSetTagList( APTR cdb, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
IPTR                         Calendar_EventSetTags( APTR cdb, IPTR tag, ... );
#endif
APTR                         Calendar_EventQueryBeginTagList( APTR cdb, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
APTR                         Calendar_EventQueryBeginTags( APTR cdb, IPTR tag, ... );
#endif
IPTR                         Calendar_EventQueryTagList( APTR QueryHandle, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
IPTR                         Calendar_EventQueryTags( APTR QueryHandle, IPTR tag, ... );
#endif
IPTR                         Calendar_EventQueryDayTagList( APTR QueryHandle, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
IPTR                         Calendar_EventQueryDayTags( APTR QueryHandle, IPTR tag, ... );
#endif
void                         Calendar_EventQueryEnd( APTR QueryHandle );
APTR                         Calendar_NotificationAddTagList( APTR cdb, IPTR NotifyFlags, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
IPTR                         Calendar_NotificationAddTags( APTR cdb, IPTR NotifyFlags, IPTR tag, ... );
#endif
IPTR                         Calendar_NotificationRemove( APTR cdb, APTR notificationhandle );

/***************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* CLIB_CALENDAR_PROTOS_H */