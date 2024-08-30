#ifndef CLIB_AMIGAGUIDE_PROTOS_H
#define CLIB_AMIGAGUIDE_PROTOS_H

/*
 *	amigaguide.library C prototypes
 *
 *	Copyright © 2002-2011 The MorphOS Development Team, All Rights Reserved.
 */

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#ifndef LIBRARIES_AMIGAGUIDE_H
# include <libraries/amigaguide.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#ifndef REXX_STORAGE_H
# include <rexx/storage.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

LONG LockAmigaGuideBase( APTR handle );
VOID UnlockAmigaGuideBase( LONG key );
APTR OpenAmigaGuideA( struct NewAmigaGuide *nag, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
APTR OpenAmigaGuide( struct NewAmigaGuide *nag, Tag tag1, ... );
#endif
APTR OpenAmigaGuideAsyncA( struct NewAmigaGuide *nag, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
APTR OpenAmigaGuideAsync( struct NewAmigaGuide *nag, Tag tag1, ... );
#endif
VOID CloseAmigaGuide( APTR cl );
ULONG AmigaGuideSignal( APTR cl );
struct AmigaGuideMsg *GetAmigaGuideMsg( APTR cl );
VOID ReplyAmigaGuideMsg( struct AmigaGuideMsg *amsg );
LONG SetAmigaGuideContextA( APTR cl, ULONG id, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
LONG SetAmigaGuideContext( APTR cl, ULONG id, Tag tag1, ... );
#endif
LONG SendAmigaGuideContextA( APTR cl, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
LONG SendAmigaGuideContext( APTR cl, Tag tag1, ... );
#endif
LONG SendAmigaGuideCmdA( APTR cl, STRPTR cmd, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
LONG SendAmigaGuideCmd( APTR cl, STRPTR cmd, Tag tag1, ... );
#endif
LONG SetAmigaGuideAttrsA( APTR cl, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
LONG SetAmigaGuideAttrs( APTR cl, Tag tag1, ... );
#endif
LONG GetAmigaGuideAttr( Tag tag, APTR cl, ULONG *storage );
LONG LoadXRef( BPTR lock, STRPTR name );
VOID ExpungeXRef( VOID );
APTR AddAmigaGuideHostA( struct Hook *h, STRPTR name, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
APTR AddAmigaGuideHost( struct Hook *h, STRPTR name, Tag tag1, ... );
#endif
LONG RemoveAmigaGuideHostA( APTR hh, struct TagItem *attrs );
#if !defined(USE_INLINE_STDARG)
LONG RemoveAmigaGuideHost( APTR hh, Tag tag1, ... );
#endif
STRPTR GetAmigaGuideString( LONG id );

/* Added in V52 (MorphOS 3.0) */
VOID AG_UpdateLink(CONST_STRPTR link);
BOOL AG_LinkExists(CONST_STRPTR link);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_AMIGAGUIDE_PROTOS_H */
