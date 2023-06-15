#ifndef _INLINE_XADMASTER_H
#define _INLINE_XADMASTER_H

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif

#ifndef XADMASTER_BASE_NAME
#define XADMASTER_BASE_NAME xadMasterBase
#endif

#define xadAllocObjectA(type, tags) \
	LP2(0x1e, APTR, xadAllocObjectA, LONG, type, d0, const struct TagItem *, tags, a0, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadAllocObject(type, tags...) \
	({ULONG _tags[] = {tags}; xadAllocObjectA((type), (const struct TagItem *) _tags);})
#endif

#define xadFreeObjectA(object, tags) \
	LP2NR(0x24, xadFreeObjectA, APTR, object, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadFreeObject(object, tags...) \
	({ULONG _tags[] = {tags}; xadFreeObjectA((object), (const struct TagItem *) _tags);})
#endif

#define xadRecogFileA(size, memory, tags) \
	LP3(0x2a, struct xadClient *, xadRecogFileA, ULONG, size, d0, APTR, memory, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadRecogFile(size, memory, tags...) \
	({ULONG _tags[] = {tags}; xadRecogFileA((size), (memory), (const struct TagItem *) _tags);})
#endif

#define xadGetInfoA(ai, tags) \
	LP2(0x30, LONG, xadGetInfoA, struct xadArchiveInfo *, ai, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadGetInfo(ai, tags...) \
	({ULONG _tags[] = {tags}; xadGetInfoA((ai), (const struct TagItem *) _tags);})
#endif

#define xadFreeInfo(ai) \
	LP1NR(0x36, xadFreeInfo, struct xadArchiveInfo *, ai, a0, \
	, XADMASTER_BASE_NAME)

#define xadFileUnArcA(ai, tags) \
	LP2(0x3c, LONG, xadFileUnArcA, struct xadArchiveInfo *, ai, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadFileUnArc(ai, tags...) \
	({ULONG _tags[] = {tags}; xadFileUnArcA((ai), (const struct TagItem *) _tags);})
#endif

#define xadDiskUnArcA(ai, tags) \
	LP2(0x42, LONG, xadDiskUnArcA, struct xadArchiveInfo *, ai, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadDiskUnArc(ai, tags...) \
	({ULONG _tags[] = {tags}; xadDiskUnArcA((ai), (const struct TagItem *) _tags);})
#endif

#define xadGetErrorText(errnum) \
	LP1(0x48, STRPTR, xadGetErrorText, ULONG, errnum, d0, \
	, XADMASTER_BASE_NAME)

#define xadGetClientInfo() \
	LP0(0x4e, struct xadClient *, xadGetClientInfo, \
	, XADMASTER_BASE_NAME)

#define xadHookAccess(command, data, buffer, ai) \
	LP4(0x54, LONG, xadHookAccess, ULONG, command, d0, LONG, data, d1, APTR, buffer, a0, struct xadArchiveInfo *, ai, a1, \
	, XADMASTER_BASE_NAME)

#define xadConvertDatesA(tags) \
	LP1(0x5a, LONG, xadConvertDatesA, const struct TagItem *, tags, a0, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadConvertDates(tags...) \
	({ULONG _tags[] = {tags}; xadConvertDatesA((const struct TagItem *) _tags);})
#endif

#define xadCalcCRC16(id, init, size, buffer) \
	LP4(0x60, UWORD, xadCalcCRC16, ULONG, id, d0, ULONG, init, d1, ULONG, size, d2, STRPTR, buffer, a0, \
	, XADMASTER_BASE_NAME)

#define xadCalcCRC32(id, init, size, buffer) \
	LP4(0x66, ULONG, xadCalcCRC32, ULONG, id, d0, ULONG, init, d1, ULONG, size, d2, STRPTR, buffer, a0, \
	, XADMASTER_BASE_NAME)

#define xadAllocVec(size, flags) \
	LP2(0x6c, APTR, xadAllocVec, ULONG, size, d0, ULONG, flags, d1, \
	, XADMASTER_BASE_NAME)

#define xadCopyMem(src, dest, size) \
	LP3NR(0x72, xadCopyMem, const void *, src, a0, APTR, dest, a1, ULONG, size, d0, \
	, XADMASTER_BASE_NAME)

#define xadHookTagAccessA(command, data, buffer, ai, tags) \
	LP5(0x78, LONG, xadHookTagAccessA, ULONG, command, d0, LONG, data, d1, APTR, buffer, a0, struct xadArchiveInfo *, ai, a1, const struct TagItem *, tags, a2, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadHookTagAccess(command, data, buffer, ai, tags...) \
	({ULONG _tags[] = {tags}; xadHookTagAccessA((command), (data), (buffer), (ai), (const struct TagItem *) _tags);})
#endif

#define xadConvertProtectionA(tags) \
	LP1(0x7e, LONG, xadConvertProtectionA, const struct TagItem *, tags, a0, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadConvertProtection(tags...) \
	({ULONG _tags[] = {tags}; xadConvertProtectionA((const struct TagItem *) _tags);})
#endif

#define xadGetDiskInfoA(ai, tags) \
	LP2(0x84, LONG, xadGetDiskInfoA, struct xadArchiveInfo *, ai, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadGetDiskInfo(ai, tags...) \
	({ULONG _tags[] = {tags}; xadGetDiskInfoA((ai), (const struct TagItem *) _tags);})
#endif

#define xadDiskFileUnArcA(ai, tags) \
	LP2(0x8a, LONG, xadDiskFileUnArcA, struct xadArchiveInfo *, ai, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadDiskFileUnArc(ai, tags...) \
	({ULONG _tags[] = {tags}; xadDiskFileUnArcA((ai), (const struct TagItem *) _tags);})
#endif

#define xadGetHookAccessA(ai, tags) \
	LP2(0x90, LONG, xadGetHookAccessA, struct xadArchiveInfo *, ai, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadGetHookAccess(ai, tags...) \
	({ULONG _tags[] = {tags}; xadGetHookAccessA((ai), (const struct TagItem *) _tags);})
#endif

#define xadFreeHookAccessA(ai, tags) \
	LP2(0x96, LONG, xadFreeHookAccessA, struct xadArchiveInfo *, ai, a0, const struct TagItem *, tags, a1, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadFreeHookAccess(ai, tags...) \
	({ULONG _tags[] = {tags}; xadFreeHookAccessA((ai), (const struct TagItem *) _tags);})
#endif

#define xadAddFileEntryA(fi, ai, tags) \
	LP3(0x9c, LONG, xadAddFileEntryA, struct xadFileInfo *, fi, a0, struct xadArchiveInfo *, ai, a1, const struct TagItem *, tags, a2, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadAddFileEntry(fi, ai, tags...) \
	({ULONG _tags[] = {tags}; xadAddFileEntryA((fi), (ai), (const struct TagItem *) _tags);})
#endif

#define xadAddDiskEntryA(di, ai, tags) \
	LP3(0xa2, LONG, xadAddDiskEntryA, struct xadDiskInfo *, di, a0, struct xadArchiveInfo *, ai, a1, const struct TagItem *, tags, a2, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadAddDiskEntry(di, ai, tags...) \
	({ULONG _tags[] = {tags}; xadAddDiskEntryA((di), (ai), (const struct TagItem *) _tags);})
#endif

#define xadGetFilenameA(buffersize, buffer, path, name, tags) \
	LP5(0xa8, LONG, xadGetFilenameA, ULONG, buffersize, d0, STRPTR, buffer, a0, STRPTR, path, a1, STRPTR, name, a2, const struct TagItem *, tags, a3, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadGetFilename(buffersize, buffer, path, name, tags...) \
	({ULONG _tags[] = {tags}; xadGetFilenameA((buffersize), (buffer), (path), (name), (const struct TagItem *) _tags);})
#endif

#define xadConvertNameA(charset, tags) \
	LP2(0xae, STRPTR, xadConvertNameA, ULONG, charset, d0, const struct TagItem *, tags, a0, \
	, XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadConvertName(charset, tags...) \
	({ULONG _tags[] = {tags}; xadConvertNameA((charset), (const struct TagItem *) _tags);})
#endif

#endif /*  _INLINE_XADMASTER_H  */
