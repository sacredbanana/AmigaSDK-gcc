/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MULTIUSER_H
#define _PPCINLINE_MULTIUSER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MULTIUSER_BASE_NAME
#define MULTIUSER_BASE_NAME muBase
#endif /* !MULTIUSER_BASE_NAME */

#define muAddMonitor(monitor) \
	LP1(0xa8, BOOL, muAddMonitor, struct muMonitor *, monitor, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muAllocGroupInfo() \
	LP0(0x96, struct muGroupInfo *, muAllocGroupInfo, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muAllocUserInfo() \
	LP0(0x36, struct muUserInfo *, muAllocUserInfo, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muCheckPasswd(taglist) \
	LP1(0x66, BOOL, muCheckPasswd, struct TagItem *, taglist, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muFreeExtOwner(info) \
	LP1NR(0x84, muFreeExtOwner, struct muExtOwner *, info, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muFreeGroupInfo(info) \
	LP1NR(0x9c, muFreeGroupInfo, struct muGroupInfo *, info, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muFreeUserInfo(info) \
	LP1NR(0x3c, muFreeUserInfo, struct muUserInfo *, info, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muFreeze(task) \
	LP1(0xba, BOOL, muFreeze, struct Task *, task, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muGetConfigDirLock() \
	LP0(0x78, BPTR, muGetConfigDirLock, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muGetDefProtection(task) \
	LP1(0x54, ULONG, muGetDefProtection, struct Task *, task, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muGetGroupInfo(info, keytype) \
	LP2(0xa2, struct muGroupInfo *, muGetGroupInfo, struct muGroupInfo *, info, a0, ULONG, keytype, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muGetPasswdDirLock() \
	LP0(0x72, BPTR, muGetPasswdDirLock, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muGetRelationshipA(user, owner, taglist) \
	LP3(0x8a, ULONG, muGetRelationshipA, struct muExtOwner *, user, d0, ULONG, owner, d1, struct TagItem *, taglist, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muGetTaskExtOwner(task) \
	LP1(0x7e, struct muExtOwner *, muGetTaskExtOwner, struct Task *, task, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muGetTaskOwner(task) \
	LP1(0x2a, ULONG, muGetTaskOwner, struct Task *, task, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muGetUserInfo(info, keytype) \
	LP2(0x42, struct muUserInfo *, muGetUserInfo, struct muUserInfo *, info, a0, ULONG, keytype, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muKill(task) \
	LP1(0xb4, BOOL, muKill, struct Task *, task, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muLimitDOSSetProtection(flag) \
	LP1(0x60, BOOL, muLimitDOSSetProtection, BOOL, flag, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muLoginA(taglist) \
	LP1(0x24, ULONG, muLoginA, struct TagItem *, taglist, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muLogoutA(taglist) \
	LP1(0x1e, ULONG, muLogoutA, struct TagItem *, taglist, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muPasswd(oldpwd, newpwd) \
	LP2(0x30, BOOL, muPasswd, STRPTR, oldpwd, a0, STRPTR, newpwd, a1, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muRemMonitor(monitor) \
	LP1NR(0xae, muRemMonitor, struct muMonitor *, monitor, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muSetDefProtectionA(taglist) \
	LP1(0x4e, BOOL, muSetDefProtectionA, struct TagItem *, taglist, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muSetProtection(name, mask) \
	LP2(0x5a, BOOL, muSetProtection, STRPTR, name, d1, LONG, mask, d2, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muUnfreeze(task) \
	LP1(0xc0, BOOL, muUnfreeze, struct Task *, task, d0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#define muUserInfo2ExtOwner(info) \
	LP1(0x90, struct muExtOwner *, muUserInfo2ExtOwner, struct muUserInfo *, info, a0, \
	, MULTIUSER_BASE_NAME, IF_CACHEFLUSHALL, NULL, 0, IF_CACHEFLUSHALL, NULL, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define muCheckPasswdTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; muCheckPasswd((struct TagItem *)_tags);})

#define muGetRelationship(a0, a1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; muGetRelationshipA((a0), (a1), (struct TagItem *)_tags);})

#define muLogin(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; muLoginA((struct TagItem *)_tags);})

#define muLogout(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; muLogoutA((struct TagItem *)_tags);})

#define muSetDefProtection(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; muSetDefProtectionA((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_MULTIUSER_H */
