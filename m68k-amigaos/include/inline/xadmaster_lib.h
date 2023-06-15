/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_XADMASTER_H
#define _INLINE_XADMASTER_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef XADMASTER_BASE_NAME
#define XADMASTER_BASE_NAME xadMasterBase
#endif /* !XADMASTER_BASE_NAME */

#define xadAllocObjectA(___type, ___tags) \
      LP2(0x1e, APTR, xadAllocObjectA , LONG, ___type, d0, const struct TagItem *, ___tags, a0,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadAllocObject(___type, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadAllocObjectA((___type), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadFreeObjectA(___object, ___tags) \
      LP2NR(0x24, xadFreeObjectA , APTR, ___object, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadFreeObject(___object, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadFreeObjectA((___object), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadRecogFileA(___size, ___memory, ___tags) \
      LP3(0x2a, struct xadClient *, xadRecogFileA , ULONG, ___size, d0, APTR, ___memory, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadRecogFile(___size, ___memory, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadRecogFileA((___size), (___memory), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadGetInfoA(___ai, ___tags) \
      LP2(0x30, LONG, xadGetInfoA , struct xadArchiveInfo *, ___ai, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadGetInfo(___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadGetInfoA((___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadFreeInfo(___ai) \
      LP1NR(0x36, xadFreeInfo , struct xadArchiveInfo *, ___ai, a0,\
      , XADMASTER_BASE_NAME)

#define xadFileUnArcA(___ai, ___tags) \
      LP2(0x3c, LONG, xadFileUnArcA , struct xadArchiveInfo *, ___ai, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadFileUnArc(___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadFileUnArcA((___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadDiskUnArcA(___ai, ___tags) \
      LP2(0x42, LONG, xadDiskUnArcA , struct xadArchiveInfo *, ___ai, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadDiskUnArc(___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadDiskUnArcA((___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadGetErrorText(___errnum) \
      LP1(0x48, STRPTR, xadGetErrorText , ULONG, ___errnum, d0,\
      , XADMASTER_BASE_NAME)

#define xadGetClientInfo() \
      LP0(0x4e, struct xadClient *, xadGetClientInfo ,\
      , XADMASTER_BASE_NAME)

#define xadHookAccess(___command, ___data, ___buffer, ___ai) \
      LP4(0x54, LONG, xadHookAccess , ULONG, ___command, d0, LONG, ___data, d1, APTR, ___buffer, a0, struct xadArchiveInfo *, ___ai, a1,\
      , XADMASTER_BASE_NAME)

#define xadConvertDatesA(___tags) \
      LP1(0x5a, LONG, xadConvertDatesA , const struct TagItem *, ___tags, a0,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadConvertDates(___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadConvertDatesA((const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadCalcCRC16(___id, ___init, ___size, ___buffer) \
      LP4(0x60, UWORD, xadCalcCRC16 , UWORD, ___id, d0, UWORD, ___init, d1, ULONG, ___size, d2, STRPTR, ___buffer, a0,\
      , XADMASTER_BASE_NAME)

#define xadCalcCRC32(___id, ___init, ___size, ___buffer) \
      LP4(0x66, ULONG, xadCalcCRC32 , ULONG, ___id, d0, ULONG, ___init, d1, ULONG, ___size, d2, STRPTR, ___buffer, a0,\
      , XADMASTER_BASE_NAME)

#define xadAllocVec(___size, ___flags) \
      LP2(0x6c, APTR, xadAllocVec , ULONG, ___size, d0, ULONG, ___flags, d1,\
      , XADMASTER_BASE_NAME)

#define xadCopyMem(___src, ___dest, ___size) \
      LP3NR(0x72, xadCopyMem , const void *, ___src, a0, APTR, ___dest, a1, ULONG, ___size, d0,\
      , XADMASTER_BASE_NAME)

#define xadHookTagAccessA(___command, ___data, ___buffer, ___ai, ___tags) \
      LP5(0x78, LONG, xadHookTagAccessA , ULONG, ___command, d0, LONG, ___data, d1, APTR, ___buffer, a0, struct xadArchiveInfo *, ___ai, a1, const struct TagItem *, ___tags, a2,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadHookTagAccess(___command, ___data, ___buffer, ___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadHookTagAccessA((___command), (___data), (___buffer), (___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadConvertProtectionA(___tags) \
      LP1(0x7e, LONG, xadConvertProtectionA , const struct TagItem *, ___tags, a0,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadConvertProtection(___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadConvertProtectionA((const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadGetDiskInfoA(___ai, ___tags) \
      LP2(0x84, LONG, xadGetDiskInfoA , struct xadArchiveInfo *, ___ai, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadGetDiskInfo(___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadGetDiskInfoA((___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadDiskFileUnArcA(___ai, ___tags) \
      LP2(0x8a, LONG, xadDiskFileUnArcA , struct xadArchiveInfo *, ___ai, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadDiskFileUnArc(___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadDiskFileUnArcA((___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadGetHookAccessA(___ai, ___tags) \
      LP2(0x90, LONG, xadGetHookAccessA , struct xadArchiveInfo *, ___ai, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadGetHookAccess(___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadGetHookAccessA((___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadFreeHookAccessA(___ai, ___tags) \
      LP2(0x96, LONG, xadFreeHookAccessA , struct xadArchiveInfo *, ___ai, a0, const struct TagItem *, ___tags, a1,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadFreeHookAccess(___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadFreeHookAccessA((___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadAddFileEntryA(___fi, ___ai, ___tags) \
      LP3(0x9c, LONG, xadAddFileEntryA , struct xadFileInfo *, ___fi, a0, struct xadArchiveInfo *, ___ai, a1, const struct TagItem *, ___tags, a2,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadAddFileEntry(___fi, ___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadAddFileEntryA((___fi), (___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadAddDiskEntryA(___di, ___ai, ___tags) \
      LP3(0xa2, LONG, xadAddDiskEntryA , struct xadDiskInfo *, ___di, a0, struct xadArchiveInfo *, ___ai, a1, const struct TagItem *, ___tags, a2,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadAddDiskEntry(___di, ___ai, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadAddDiskEntryA((___di), (___ai), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadGetFilenameA(___buffersize, ___buffer, ___path, ___name, ___tags) \
      LP5(0xa8, LONG, xadGetFilenameA , ULONG, ___buffersize, d0, STRPTR, ___buffer, a0, STRPTR, ___path, a1, STRPTR, ___name, a2, const struct TagItem *, ___tags, a3,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadGetFilename(___buffersize, ___buffer, ___path, ___name, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadGetFilenameA((___buffersize), (___buffer), (___path), (___name), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#define xadConvertNameA(___charset, ___tags) \
      LP2(0xae, STRPTR, xadConvertNameA , ULONG, ___charset, d0, const struct TagItem *, ___tags, a0,\
      , XADMASTER_BASE_NAME)

#ifndef NO_INLINE_STDARG
#define xadConvertName(___charset, ___tags, ...) \
    ({_sfdc_vararg _tags[] = { ___tags, __VA_ARGS__ }; xadConvertNameA((___charset), (const struct TagItem *) _tags); })
#endif /* !NO_INLINE_STDARG */

#endif /* !_INLINE_XADMASTER_H */
