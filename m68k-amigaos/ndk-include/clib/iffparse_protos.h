#ifndef CLIB_IFFPARSE_PROTOS_H
#define CLIB_IFFPARSE_PROTOS_H

/*
**	$VER: iffparse_protos.h 47.1 (30.11.2021)
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
#ifndef  LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
/*--- functions in V36 or higher (Release 2.0) ---*/

/* Basic functions */

struct IFFHandle * __stdargs AllocIFF( VOID );
LONG  __stdargs OpenIFF( struct IFFHandle *iff, LONG rwMode );
LONG  __stdargs ParseIFF( struct IFFHandle *iff, LONG control );
VOID  __stdargs CloseIFF( struct IFFHandle *iff );
VOID  __stdargs FreeIFF( struct IFFHandle *iff );

/* Read/Write functions */

LONG  __stdargs ReadChunkBytes( struct IFFHandle *iff, APTR buf, LONG numBytes );
LONG  __stdargs WriteChunkBytes( struct IFFHandle *iff, CONST_APTR buf, LONG numBytes );
LONG  __stdargs ReadChunkRecords( struct IFFHandle *iff, APTR buf, LONG bytesPerRecord, LONG numRecords );
LONG  __stdargs WriteChunkRecords( struct IFFHandle *iff, CONST_APTR buf, LONG bytesPerRecord, LONG numRecords );

/* Context entry/exit */

LONG  __stdargs PushChunk( struct IFFHandle *iff, LONG type, LONG id, LONG size );
LONG  __stdargs PopChunk( struct IFFHandle *iff );

/* Low-level handler installation */

LONG  __stdargs EntryHandler( struct IFFHandle *iff, LONG type, LONG id, LONG position, struct Hook *handler, APTR object );
LONG  __stdargs ExitHandler( struct IFFHandle *iff, LONG type, LONG id, LONG position, struct Hook *handler, APTR object );

/* Built-in chunk/property handlers */

LONG  __stdargs PropChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG  __stdargs PropChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG  __stdargs StopChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG  __stdargs StopChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG  __stdargs CollectionChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG  __stdargs CollectionChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG  __stdargs StopOnExit( struct IFFHandle *iff, LONG type, LONG id );

/* Context utilities */

struct StoredProperty * __stdargs FindProp( struct IFFHandle *iff, LONG type, LONG id );
struct CollectionItem * __stdargs FindCollection( struct IFFHandle *iff, LONG type, LONG id );
struct ContextNode * __stdargs FindPropContext( struct IFFHandle *iff );
struct ContextNode * __stdargs CurrentChunk( struct IFFHandle *iff );
struct ContextNode * __stdargs ParentChunk( struct ContextNode *contextNode );

/* LocalContextItem support functions */

struct LocalContextItem * __stdargs AllocLocalItem( LONG type, LONG id, LONG ident, LONG dataSize );
APTR  __stdargs LocalItemData( struct LocalContextItem *localItem );
VOID  __stdargs SetLocalItemPurge( struct LocalContextItem *localItem, struct Hook *purgeHook );
VOID  __stdargs FreeLocalItem( struct LocalContextItem *localItem );
struct LocalContextItem * __stdargs FindLocalItem( struct IFFHandle *iff, LONG type, LONG id, LONG ident );
LONG  __stdargs StoreLocalItem( struct IFFHandle *iff, struct LocalContextItem *localItem, LONG position );
VOID  __stdargs StoreItemInContext( struct IFFHandle *iff, struct LocalContextItem *localItem, struct ContextNode *contextNode );

/* IFFHandle initialization */

VOID  __stdargs InitIFF( struct IFFHandle *iff, LONG flags, struct Hook *streamHook );
VOID  __stdargs InitIFFasDOS( struct IFFHandle *iff );
VOID  __stdargs InitIFFasClip( struct IFFHandle *iff );

/* Internal clipboard support */

struct ClipboardHandle * __stdargs OpenClipboard( LONG unitNumber );
VOID  __stdargs CloseClipboard( struct ClipboardHandle *clipHandle );

/* Miscellaneous */

LONG  __stdargs GoodID( LONG id );
LONG  __stdargs GoodType( LONG type );
STRPTR  __stdargs IDtoStr( LONG id, STRPTR buf );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_IFFPARSE_PROTOS_H */
