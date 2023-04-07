#ifndef CLIB_REALTIME_PROTOS_H
#define CLIB_REALTIME_PROTOS_H

/*
**	$VER: realtime_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  LIBRARIES_REALTIME_H
#include <libraries/realtime.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
/*--- functions in V37 or higher (Release 2.04) ---*/

/* Locks */

APTR  __stdargs LockRealTime( ULONG lockType );
VOID  __stdargs UnlockRealTime( APTR lock );

/* Conductor */

struct Player * __stdargs CreatePlayerA( CONST struct TagItem *tagList );
struct Player * __stdargs CreatePlayer( Tag tag1, ... );
VOID  __stdargs DeletePlayer( struct Player *player );
BOOL  __stdargs SetPlayerAttrsA( struct Player *player, CONST struct TagItem *tagList );
BOOL  __stdargs SetPlayerAttrs( struct Player *player, ... );
LONG  __stdargs SetConductorState( struct Player *player, ULONG state, LONG time );
BOOL  __stdargs ExternalSync( struct Player *player, LONG minTime, LONG maxTime );
struct Conductor * __stdargs NextConductor( CONST struct Conductor *previousConductor );
struct Conductor * __stdargs FindConductor( CONST_STRPTR name );
ULONG  __stdargs GetPlayerAttrsA( struct Player *player, CONST struct TagItem *tagList );
ULONG  __stdargs GetPlayerAttrs( struct Player *player, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_REALTIME_PROTOS_H */
