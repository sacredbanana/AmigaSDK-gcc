#ifndef CLIB_IFFPARSE_PROTOS_H
#define CLIB_IFFPARSE_PROTOS_H

/*
	iffparse.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct IFFHandle *AllocIFF( VOID );
LONG OpenIFF( struct IFFHandle *iff, LONG rwMode );
LONG ParseIFF( struct IFFHandle *iff, LONG control );
VOID CloseIFF( struct IFFHandle *iff );
VOID FreeIFF( struct IFFHandle *iff );

LONG ReadChunkBytes( struct IFFHandle *iff, APTR buf, LONG numBytes );
LONG WriteChunkBytes( struct IFFHandle *iff, CONST APTR buf, LONG numBytes );
LONG SeekChunkBytes( struct IFFHandle *iff, LONG numBytes, LONG mode);
LONG ReadChunkRecords( struct IFFHandle *iff, APTR buf, LONG bytesPerRecord, LONG numRecords );
LONG WriteChunkRecords( struct IFFHandle *iff, CONST APTR buf, LONG bytesPerRecord, LONG numRecords );
LONG SeekChunkRecords( struct IFFHandle *iff, LONG bytesPerRecord, LONG numRecords, LONG mode);

LONG PushChunk( struct IFFHandle *iff, LONG type, LONG id, LONG size );
LONG PopChunk( struct IFFHandle *iff );

LONG EntryHandler( struct IFFHandle *iff, LONG type, LONG id, LONG position, struct Hook *handler, APTR object );
LONG ExitHandler( struct IFFHandle *iff, LONG type, LONG id, LONG position, struct Hook *handler, APTR object );

LONG PropChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG PropChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG StopChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG StopChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG CollectionChunk( struct IFFHandle *iff, LONG type, LONG id );
LONG CollectionChunks( struct IFFHandle *iff, CONST LONG *propArray, LONG numPairs );
LONG StopOnExit( struct IFFHandle *iff, LONG type, LONG id );

struct StoredProperty *FindProp( CONST struct IFFHandle *iff, LONG type, LONG id );
struct CollectionItem *FindCollection( CONST struct IFFHandle *iff, LONG type, LONG id );
struct ContextNode *FindPropContext( CONST struct IFFHandle *iff );
struct ContextNode *CurrentChunk( CONST struct IFFHandle *iff );
struct ContextNode *ParentChunk( CONST struct ContextNode *contextNode );

struct LocalContextItem *AllocLocalItem( LONG type, LONG id, LONG ident, LONG dataSize );
APTR LocalItemData( CONST struct LocalContextItem *localItem );
VOID SetLocalItemPurge( struct LocalContextItem *localItem, CONST struct Hook *purgeHook );
VOID FreeLocalItem( struct LocalContextItem *localItem );
struct LocalContextItem *FindLocalItem( CONST struct IFFHandle *iff, LONG type, LONG id, LONG ident );
LONG StoreLocalItem( struct IFFHandle *iff, struct LocalContextItem *localItem, LONG position );
VOID StoreItemInContext( struct IFFHandle *iff, struct LocalContextItem *localItem, struct ContextNode *contextNode );

VOID InitIFF( struct IFFHandle *iff, LONG flags, CONST struct Hook *streamHook );
VOID InitIFFasDOS( struct IFFHandle *iff );
VOID InitIFFasClip( struct IFFHandle *iff );

struct ClipboardHandle *OpenClipboard( LONG unitNumber );
VOID CloseClipboard( struct ClipboardHandle *clipHandle );

LONG GoodID( LONG id );
LONG GoodType( LONG type );
STRPTR IDtoStr( LONG id, STRPTR buf );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_IFFPARSE_PROTOS_H */
