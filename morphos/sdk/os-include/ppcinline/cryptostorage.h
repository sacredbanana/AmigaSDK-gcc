/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CRYPTOSTORAGE_H
#define _PPCINLINE_CRYPTOSTORAGE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CRYPTOSTORAGE_BASE_NAME
#define CRYPTOSTORAGE_BASE_NAME CryptoStorageBase
#endif /* !CRYPTOSTORAGE_BASE_NAME */

#define CryptoStorageOpenA(__p0) \
	(((struct CryptoStorageCtx *(*)(void *, struct TagItem *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 28))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0))

#define CryptoStorageCommit(__p0) \
	(((LONG (*)(void *, struct CryptoStorageCtx *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 34))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0))

#define CryptoStorageClose(__p0) \
	(((LONG (*)(void *, struct CryptoStorageCtx *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 40))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0))

#define CryptoStorageUnlockA(__p0, __p1) \
	(((LONG (*)(void *, struct CryptoStorageCtx *, struct TagItem *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 46))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0, __p1))

#define CryptoStorageLock(__p0) \
	(((void (*)(void *, struct CryptoStorageCtx *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 52))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0))

#define CryptoStorageChangePassphraseA(__p0, __p1) \
	(((LONG (*)(void *, struct CryptoStorageCtx *, struct TagItem *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 58))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0, __p1))

#define CryptoStorageStore(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, struct CryptoStorageCtx *, CONST_STRPTR , CONST_STRPTR , ULONG ))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 64))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0, __p1, __p2, __p3))

#define CryptoStorageFetch(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, struct CryptoStorageCtx *, CONST_STRPTR , UBYTE *, ULONG *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 70))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0, __p1, __p2, __p3))

#define CryptoStorageQueryKeyArray(__p0) \
	(((STRPTR *(*)(void *, struct CryptoStorageCtx *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 76))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0))

#define CryptoStorageFreeKeyArray(__p0, __p1) \
	(((void (*)(void *, struct CryptoStorageCtx *, STRPTR *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 82))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0, __p1))

#define CryptoStorageClear(__p0) \
	(((LONG (*)(void *, struct CryptoStorageCtx *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 88))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0))

#define CryptoStorageExport(__p0, __p1, __p2) \
	(((LONG (*)(void *, struct CryptoStorageCtx *, APTR , ULONG *))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 94))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0, __p1, __p2))

#define CryptoStorageImport(__p0, __p1, __p2) \
	(((LONG (*)(void *, struct CryptoStorageCtx *, CONST_APTR , ULONG ))*(void**)((long)(CRYPTOSTORAGE_BASE_NAME) - 100))((void*)(CRYPTOSTORAGE_BASE_NAME), __p0, __p1, __p2))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define CryptoStorageOpen(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CryptoStorageOpenA((struct TagItem *)_tags);})

#define CryptoStorageUnlock(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CryptoStorageUnlockA(__p0, (struct TagItem *)_tags);})

#define CryptoStorageChangePassphrase(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CryptoStorageChangePassphraseA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_CRYPTOSTORAGE_H */
