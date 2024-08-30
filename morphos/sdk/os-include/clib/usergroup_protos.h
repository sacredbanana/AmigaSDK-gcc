#ifndef CLIB_USERGROUP_PROTOS_H
#define CLIB_USERGROUP_PROTOS_H

/*
	usergroup.library C prototypes

	Copyright � 2003 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_USERGROUP_H
#include <libraries/usergroup.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef EXEC_TASKS_H
#include <exec/tasks.h>
#endif

#ifndef _PWD_H_
#include <pwd.h>
#endif

#ifndef _GRP_H_
#include <grp.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Setup functions */
int ug_SetupContextTagList(const UBYTE* pname, struct TagItem *taglist);
int ug_SetupContextTags(const UBYTE* pname,  ...);
int ug_GetErr(void);
const char *ug_StrError(LONG code);

/* User identification */
uid_t getuid(void);
uid_t geteuid(void);
int setreuid(uid_t real, uid_t eff);
int setuid(uid_t id);

/* Group membership */
gid_t getgid(void);
gid_t getegid(void);
int setregid(gid_t real, gid_t eff);
int setgid(gid_t id);
int getgroups(int ngroups, gid_t *groups);
int setgroups(int ngroups, const gid_t *groups);
int initgroups(const char *name, gid_t basegroup);

/* User database */
struct passwd *getpwnam(const char *name);
struct passwd *getpwuid(uid_t uid);
void setpwent(void);
struct passwd *getpwent(void);
void endpwent(void);

/* Group database */
struct group *getgrnam(const char * name);
struct group *getgrgid(gid_t gid);
void setgrent(void);
struct group *getgrent(void);
void endgrent(void);

/* Password handling */
char *crypt(const char *key, const char *salt);
char *ug_GetSalt(const struct passwd *user, char *buffer, ULONG size);
char *getpass(const char *prompt);

/* Default protections */
mode_t umask(mode_t mask);
mode_t getumask(void);

/* Sessions */
pid_t setsid(void);
pid_t getpgrp(void);
char *getlogin(void);
int setlogin(const char *buffer);

/* Sessions, user login database (utmp) */
void setutent(void);
struct utmp *getutent(void);
void endutent(void);
struct lastlog *getlastlog(uid_t uid);
int setlastlog(uid_t uid, char *name, char *host);

/* Credentials */
struct UserGroupCredentials *getcredentials(struct Task *task);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !CLIB_USERGROUP_PROTOS_H */
