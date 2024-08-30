#ifndef CLIB_REALTIME_PROTOS_H
#define CLIB_REALTIME_PROTOS_H

/*
	realtime.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_REALTIME_H
# include <libraries/realtime.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR LockRealTime( ULONG lockType );
VOID UnlockRealTime( APTR lock );

struct Player *CreatePlayerA( CONST struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
struct Player *CreatePlayer( Tag tag1, ... );
#endif
VOID DeletePlayer( struct Player *player );
BOOL SetPlayerAttrsA( struct Player *player, CONST struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
BOOL SetPlayerAttrs( struct Player *player, Tag tag1, ... );
#endif
LONG SetConductorState( struct Player *player, ULONG state, LONG time );
BOOL ExternalSync( struct Player *player, LONG minTime, LONG maxTime );
struct Conductor *NextConductor( CONST struct Conductor *previousConductor );
struct Conductor *FindConductor( CONST_STRPTR name );
ULONG GetPlayerAttrsA( CONST struct Player *player, CONST struct TagItem *tagList );
#if !defined(USE_INLINE_STDARG)
ULONG GetPlayerAttrs( CONST struct Player *player, Tag tag1, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_REALTIME_PROTOS_H */
