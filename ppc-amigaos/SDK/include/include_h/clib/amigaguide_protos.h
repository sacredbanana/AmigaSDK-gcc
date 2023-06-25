#ifndef CLIB_AMIGAGUIDE_PROTOS_H
#define CLIB_AMIGAGUIDE_PROTOS_H

/*
**    $Id: amigaguide_protos.h,v 1.8 2010-01-31 01:28:55 ssolie Exp $
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
#ifndef   EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef   DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef   LIBRARIES_AMIGAGUIDE_H
#include <libraries/amigaguide.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef   REXX_STORAGE_H
#include <rexx/storage.h>
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

/*--- functions in V40 or higher (Release 3.1) ---*/

/* Public entries */

LONG LockAmigaGuideBase( APTR handle );
VOID UnlockAmigaGuideBase( LONG key );
APTR OpenAmigaGuideA( struct NewAmigaGuide *nag, struct TagItem *tags );
APTR OpenAmigaGuide( struct NewAmigaGuide *nag, Tag tag1, ... );
APTR OpenAmigaGuideAsyncA( struct NewAmigaGuide *nag, struct TagItem *attrs );
APTR OpenAmigaGuideAsync( struct NewAmigaGuide *nag, Tag tag1, ... );
VOID CloseAmigaGuide( APTR cl );
ULONG AmigaGuideSignal( APTR cl );
struct AmigaGuideMsg *GetAmigaGuideMsg( APTR cl );
VOID ReplyAmigaGuideMsg( struct AmigaGuideMsg *amsg );
LONG SetAmigaGuideContextA( APTR cl, ULONG id, struct TagItem *attrs );
LONG SetAmigaGuideContext( APTR cl, ULONG id, Tag tag1, ... );
LONG SendAmigaGuideContextA( APTR cl, struct TagItem *attrs );
LONG SendAmigaGuideContext( APTR cl, Tag tag1, ... );
LONG SendAmigaGuideCmdA( APTR cl, STRPTR cmd, struct TagItem *attrs );
LONG SendAmigaGuideCmd( APTR cl, STRPTR cmd, Tag tag1, ... );
LONG SetAmigaGuideAttrsA( APTR cl, struct TagItem *attrs );
LONG SetAmigaGuideAttrs( APTR cl, Tag tag1, ... );
LONG GetAmigaGuideAttr( Tag tag, APTR cl, ULONG *storage );
LONG LoadXRef( BPTR lock, STRPTR name );
VOID ExpungeXRef( VOID );
APTR AddAmigaGuideHostA( struct Hook *h, STRPTR name, struct TagItem *attrs );
APTR AddAmigaGuideHost( struct Hook *h, STRPTR name, Tag tag1, ... );
LONG RemoveAmigaGuideHostA( APTR hh, struct TagItem *attrs );
LONG RemoveAmigaGuideHost( APTR hh, Tag tag1, ... );
STRPTR GetAmigaGuideString( LONG id );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_AMIGAGUIDE_PROTOS_H */
