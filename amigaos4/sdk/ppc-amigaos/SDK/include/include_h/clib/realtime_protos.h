#ifndef CLIB_REALTIME_PROTOS_H
#define CLIB_REALTIME_PROTOS_H

/*
**    $Id: realtime_protos.h,v 1.8 2010-01-31 01:29:03 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef   LIBRARIES_REALTIME_H
#include <libraries/realtime.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

/*--- functions in V37 or higher (Release 2.04) ---*/

/* Locks */

APTR LockRealTime( ULONG lockType );
VOID UnlockRealTime( APTR lock );

/* Conductor */

struct Player *CreatePlayerA( CONST struct TagItem *tagList );
struct Player *CreatePlayer( Tag tag1, ... );
VOID DeletePlayer( struct Player *player );
BOOL SetPlayerAttrsA( struct Player *player, CONST struct TagItem *tagList );
BOOL SetPlayerAttrs( struct Player *player, Tag tag1, ... );
LONG SetConductorState( struct Player *player, ULONG state, LONG time );
BOOL ExternalSync( struct Player *player, LONG minTime, LONG maxTime );
struct Conductor *NextConductor( CONST struct Conductor *previousConductor );
struct Conductor *FindConductor( CONST_STRPTR name );
ULONG GetPlayerAttrsA( CONST struct Player *player, CONST struct TagItem *tagList );
ULONG GetPlayerAttrs( CONST struct Player *player, Tag tag1, ... );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_REALTIME_PROTOS_H */
