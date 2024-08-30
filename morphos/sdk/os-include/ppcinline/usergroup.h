/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_USERGROUP_H
#define _PPCINLINE_USERGROUP_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef USERGROUP_BASE_NAME
#define USERGROUP_BASE_NAME UserGroupBase
#endif /* !USERGROUP_BASE_NAME */

#define getgrent() \
	LP0(162, struct group *, getgrent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getpwnam(__p0) \
	LP1(114, struct passwd *, getpwnam, \
		const char *, __p0, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getlastlog(__p0) \
	LP1(246, struct lastlog *, getlastlog, \
		uid_t , __p0, d0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ug_StrError(__p0) \
	LP1(42, const char *, ug_StrError, \
		LONG , __p0, d1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define umask(__p0) \
	LP1(192, mode_t , umask, \
		mode_t , __p0, d0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getlogin() \
	LP0(216, char *, getlogin, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setgid(__p0) \
	LP1(90, int , setgid, \
		gid_t , __p0, d0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getuid() \
	LP0(48, uid_t , getuid, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setsid() \
	LP0(204, pid_t , setsid, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getcredentials(__p0) \
	LP1(258, struct UserGroupCredentials *, getcredentials, \
		struct Task *, __p0, a0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getpgrp() \
	LP0(210, pid_t , getpgrp, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setutent() \
	LP0NR(228, setutent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define endpwent() \
	LP0NR(138, endpwent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getpwent() \
	LP0(132, struct passwd *, getpwent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getgroups(__p0, __p1) \
	LP2(96, int , getgroups, \
		int , __p0, d0, \
		gid_t *, __p1, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setreuid(__p0, __p1) \
	LP2(60, int , setreuid, \
		uid_t , __p0, d0, \
		uid_t , __p1, d1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define geteuid() \
	LP0(54, uid_t , geteuid, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setgroups(__p0, __p1) \
	LP2(102, int , setgroups, \
		int , __p0, d0, \
		const gid_t *, __p1, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setgrent() \
	LP0NR(156, setgrent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define initgroups(__p0, __p1) \
	LP2(108, int , initgroups, \
		const char *, __p0, a1, \
		gid_t , __p1, d0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getgrnam(__p0) \
	LP1(144, struct group *, getgrnam, \
		const char *, __p0, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setlastlog(__p0, __p1, __p2) \
	LP3(252, int , setlastlog, \
		uid_t , __p0, d0, \
		char *, __p1, a0, \
		char *, __p2, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define crypt(__p0, __p1) \
	LP2(174, char *, crypt, \
		const char *, __p0, a0, \
		const char *, __p1, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getgid() \
	LP0(72, gid_t , getgid, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getumask() \
	LP0(198, mode_t , getumask, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ug_GetErr() \
	LP0(36, int , ug_GetErr, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setlogin(__p0) \
	LP1(222, int , setlogin, \
		const char *, __p0, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define endutent() \
	LP0NR(240, endutent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getpwuid(__p0) \
	LP1(120, struct passwd *, getpwuid, \
		uid_t , __p0, d0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getgrgid(__p0) \
	LP1(150, struct group *, getgrgid, \
		gid_t , __p0, d0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setuid(__p0) \
	LP1(66, int , setuid, \
		uid_t , __p0, d0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getutent() \
	LP0(234, struct utmp *, getutent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ug_SetupContextTagList(__p0, __p1) \
	LP2(30, int , ug_SetupContextTagList, \
		const UBYTE *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ug_GetSalt(__p0, __p1, __p2) \
	LP3(180, char *, ug_GetSalt, \
		const struct passwd *, __p0, a0, \
		char *, __p1, a1, \
		ULONG , __p2, d0, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setregid(__p0, __p1) \
	LP2(84, int , setregid, \
		gid_t , __p0, d0, \
		gid_t , __p1, d1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define endgrent() \
	LP0NR(168, endgrent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getpass(__p0) \
	LP1(186, char *, getpass, \
		const char *, __p0, a1, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define getegid() \
	LP0(78, gid_t , getegid, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define setpwent() \
	LP0NR(126, setpwent, \
		, USERGROUP_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define ug_SetupContextTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ug_SetupContextTagList(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_USERGROUP_H */
