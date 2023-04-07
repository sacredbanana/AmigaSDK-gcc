#ifndef CLIB_AMIGAGUIDE_PROTOS_H
#define CLIB_AMIGAGUIDE_PROTOS_H

/*
**	$VER: amigaguide_protos.h 47.1 (30.11.2021)
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
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  LIBRARIES_AMIGAGUIDE_H
#include <libraries/amigaguide.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/

/* Public entries */

LONG  __stdargs LockAmigaGuideBase( APTR handle );
VOID  __stdargs UnlockAmigaGuideBase( LONG key );
APTR  __stdargs OpenAmigaGuideA( struct NewAmigaGuide *nag, CONST struct TagItem *attrs );
APTR  __stdargs OpenAmigaGuide( struct NewAmigaGuide *nag, ... );
APTR  __stdargs OpenAmigaGuideAsyncA( struct NewAmigaGuide *nag, CONST struct TagItem *attrs );
APTR  __stdargs OpenAmigaGuideAsync( struct NewAmigaGuide *nag, ... );
VOID  __stdargs CloseAmigaGuide( APTR cl );
ULONG  __stdargs AmigaGuideSignal( APTR cl );
struct AmigaGuideMsg * __stdargs GetAmigaGuideMsg( APTR cl );
VOID  __stdargs ReplyAmigaGuideMsg( struct AmigaGuideMsg *amsg );
LONG  __stdargs SetAmigaGuideContextA( APTR cl, ULONG id, CONST struct TagItem *attrs );
LONG  __stdargs SetAmigaGuideContext( APTR cl, ULONG id, ... );
LONG  __stdargs SendAmigaGuideContextA( APTR cl, CONST struct TagItem *attrs );
LONG  __stdargs SendAmigaGuideContext( APTR cl, ... );
LONG  __stdargs SendAmigaGuideCmdA( APTR cl, STRPTR cmd, CONST struct TagItem *attrs );
LONG  __stdargs SendAmigaGuideCmd( APTR cl, CONST_STRPTR cmd, ... );
LONG  __stdargs SetAmigaGuideAttrsA( APTR cl, CONST struct TagItem *attrs );
LONG  __stdargs SetAmigaGuideAttrs( APTR cl, ... );
LONG  __stdargs GetAmigaGuideAttr( Tag tag1, APTR cl, ULONG *storage );
LONG  __stdargs LoadXRef( BPTR lock, STRPTR name );
VOID  __stdargs ExpungeXRef( VOID );
APTR  __stdargs AddAmigaGuideHostA( struct Hook *h, CONST_STRPTR name, CONST struct TagItem *attrs );
APTR  __stdargs AddAmigaGuideHost( struct Hook *h, CONST_STRPTR name, ... );
LONG  __stdargs RemoveAmigaGuideHostA( APTR hh, CONST struct TagItem *attrs );
LONG  __stdargs RemoveAmigaGuideHost( APTR hh, ... );
STRPTR  __stdargs GetAmigaGuideString( LONG id );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_AMIGAGUIDE_PROTOS_H */
