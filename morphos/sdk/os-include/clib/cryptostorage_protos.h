#ifndef CLIB_CRYPTOSTORAGE_PROTOS_H
#define CLIB_CRYPTOSTORAGE_PROTOS_H

/*
	cryptostorage.library C prototypes

	Copyright © 2017-2019 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_CRYPTOSTORAGE_H
# include <libraries/cryptostorage.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct CryptoStorageCtx *CryptoStorageOpenA( struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct CryptoStorageCtx *CryptoStorageOpen( Tag tag1, ... );
#endif
LONG CryptoStorageCommit( struct CryptoStorageCtx *ctx );
LONG CryptoStorageClose( struct CryptoStorageCtx *ctx );
LONG CryptoStorageUnlockA( struct CryptoStorageCtx *ctx, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG CryptoStorageUnlock( struct CryptoStorageCtx *ctx, Tag tag1, ... );
#endif
void CryptoStorageLock( struct CryptoStorageCtx *ctx );
LONG CryptoStorageChangePassphraseA( struct CryptoStorageCtx *ctx, struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
LONG CryptoStorageChangePassphrase( struct CryptoStorageCtx *ctx, Tag tag1, ... );
#endif
LONG CryptoStorageStore( struct CryptoStorageCtx *ctx, CONST_STRPTR key, CONST_STRPTR value, ULONG valsize );
LONG CryptoStorageFetch( struct CryptoStorageCtx *ctx, CONST_STRPTR key, UBYTE *value, ULONG *valsize );
STRPTR *CryptoStorageQueryKeyArray( struct CryptoStorageCtx *ctx );
void CryptoStorageFreeKeyArray( struct CryptoStorageCtx *ctx, STRPTR *array );
/* V52 */
LONG CryptoStorageClear( struct CryptoStorageCtx *ctx );
LONG CryptoStorageExport( struct CryptoStorageCtx *ctx, APTR buf, ULONG *size );
LONG CryptoStorageImport( struct CryptoStorageCtx *ctx, CONST_APTR buf, ULONG size );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_CRYPTOSTORAGE_PROTOS_H */
