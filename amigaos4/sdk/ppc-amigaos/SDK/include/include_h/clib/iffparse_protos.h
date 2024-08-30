#ifndef CLIB_IFFPARSE_PROTOS_H
#define CLIB_IFFPARSE_PROTOS_H

/*
**    $Id: iffparse_protos.h,v 1.9 2010-01-31 01:29:02 ssolie Exp $
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
#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif
#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
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

/*--- functions in V36 or higher (Release 2.0) ---*/

/* Basic functions */

struct IFFHandle *AllocIFF( VOID );
LONG OpenIFF( struct IFFHandle *iff, LONG rwMode );
LONG ParseIFF( struct IFFHandle *iff, LONG control );
VOID CloseIFF( struct IFFHandle *iff );
VOID FreeIFF( struct IFFHandle *iff );

/* Read/Write functions */

LONG ReadChunkBytes( struct IFFHandle *iff, APTR buf, LONG numBytes );
LONG WriteChunkBytes( struct IFFHandle *iff, CONST_APTR buf, LONG numBytes );
LONG ReadChunkRecords( struct IFFHandle *iff, APTR buf, LONG bytesPerRecord, LONG numRecords );
LONG WriteChunkRecords( struct IFFHandle *iff, CONST_APTR buf, LONG bytesPerRecord, LONG numRecords );

/* Context entry/exit */

LONG PushChunk( struct IFFHandle *iff, LONG type, LONG id, LONG size );
LONG PopChunk( struct IFFHandle *iff );

/* Low-level handler installation */

LONG EntryHandler( struct IFFHandle *iff, LONG type, LONG id, LONG position, struct Hook *handler, APTR object );
LONG ExitHandler( struct IFFHandle *iff, LONG type, LONG id, LONG position, struct Hook *handler, APTR object );

/* Built-in chunk/property handlers */

LONG PropChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG PropChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG StopChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG StopChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG CollectionChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG CollectionChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG StopOnExit( struct IFFHandle *iff, LONG type, LONG id );

/* Context utilities */

struct StoredProperty *FindProp( CONST struct IFFHandle *iff, LONG type, LONG id );
struct CollectionItem *FindCollection( CONST struct IFFHandle *iff, LONG type, LONG id );
struct ContextNode *FindPropContext( CONST struct IFFHandle *iff );
struct ContextNode *CurrentChunk( CONST struct IFFHandle *iff );
struct ContextNode *ParentChunk( CONST struct ContextNode *contextNode );

/* LocalContextItem support functions */

struct LocalContextItem *AllocLocalItem( LONG type, LONG id, LONG ident, LONG dataSize );
APTR LocalItemData( CONST struct LocalContextItem *localItem );
VOID SetLocalItemPurge( struct LocalContextItem *localItem, CONST struct Hook *purgeHook );
VOID FreeLocalItem( struct LocalContextItem *localItem );
struct LocalContextItem *FindLocalItem( CONST struct IFFHandle *iff, LONG type, LONG id, LONG ident );
LONG StoreLocalItem( struct IFFHandle *iff, struct LocalContextItem *localItem, LONG position );
VOID StoreItemInContext( struct IFFHandle *iff, struct LocalContextItem *localItem, struct ContextNode *contextNode );

/* IFFHandle initialization */

VOID InitIFF( struct IFFHandle *iff, LONG flags, CONST struct Hook *streamHook );
VOID InitIFFasDOS( struct IFFHandle *iff );
VOID InitIFFasClip( struct IFFHandle *iff );

/* Internal clipboard support */

struct ClipboardHandle *OpenClipboard( LONG unitNumber );
VOID CloseClipboard( struct ClipboardHandle *clipHandle );

/* Miscellaneous */

LONG GoodID( LONG id );
LONG GoodType( LONG type );
STRPTR IDtoStr( LONG id, STRPTR buf );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_IFFPARSE_PROTOS_H */
