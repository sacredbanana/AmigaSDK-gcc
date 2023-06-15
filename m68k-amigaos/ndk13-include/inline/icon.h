/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_ICON_H
#define _INLINE_ICON_H

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

#ifndef ICON_BASE_NAME
#define ICON_BASE_NAME IconBase
#endif /* !ICON_BASE_NAME */

#define iconPrivate1() \
      LP0(0x1e, ULONG, iconPrivate1 ,\
      , ICON_BASE_NAME)

#define iconPrivate2() \
      LP0(0x24, ULONG, iconPrivate2 ,\
      , ICON_BASE_NAME)

#define iconPrivate3() \
      LP0(0x2a, ULONG, iconPrivate3 ,\
      , ICON_BASE_NAME)

#define iconPrivate4() \
      LP0(0x30, ULONG, iconPrivate4 ,\
      , ICON_BASE_NAME)

#define FreeFreeList(___freelist) \
      LP1NR(0x36, FreeFreeList , struct FreeList *, ___freelist, a0,\
      , ICON_BASE_NAME)

#define AddFreeList(___freelist, ___mem, ___size) \
      LP3(0x48, BOOL, AddFreeList , struct FreeList *, ___freelist, a0, CONST_APTR, ___mem, a1, ULONG, ___size, a2,\
      , ICON_BASE_NAME)

#define GetDiskObject(___name) \
      LP1(0x4e, struct DiskObject *, GetDiskObject , CONST_STRPTR, ___name, a0,\
      , ICON_BASE_NAME)

#define PutDiskObject(___name, ___diskobj) \
      LP2(0x54, BOOL, PutDiskObject , CONST_STRPTR, ___name, a0, CONST struct DiskObject *, ___diskobj, a1,\
      , ICON_BASE_NAME)

#define FreeDiskObject(___diskobj) \
      LP1NR(0x5a, FreeDiskObject , struct DiskObject *, ___diskobj, a0,\
      , ICON_BASE_NAME)

#define FindToolType(___toolTypeArray, ___typeName) \
      LP2(0x60, UBYTE *, FindToolType , CONST_STRPTR *, ___toolTypeArray, a0, CONST_STRPTR, ___typeName, a1,\
      , ICON_BASE_NAME)

#define MatchToolValue(___typeString, ___value) \
      LP2(0x66, BOOL, MatchToolValue , CONST_STRPTR, ___typeString, a0, CONST_STRPTR, ___value, a1,\
      , ICON_BASE_NAME)

#define BumpRevision(___newname, ___oldname) \
      LP2(0x6c, STRPTR, BumpRevision , STRPTR, ___newname, a0, CONST_STRPTR, ___oldname, a1,\
      , ICON_BASE_NAME)

#define FreeAlloc(___free, ___len, ___type) \
      LP3(0x72, APTR, FreeAlloc , struct FreeList *, ___free, a0, ULONG, ___len, a1, ULONG, ___type, a2,\
      , ICON_BASE_NAME)

#endif /* !_INLINE_ICON_H */
