#ifndef LIBRARIES_USERGROUP_H
#define LIBRARIES_USERGROUP_H \
       "$Id: usergroup.h,v 1.1.1.1 2005/03/15 15:57:12 laire Exp $"
/*
 *      Definitions of AmiTCP/IP usergroup.library for 32 bit C compilers
 *
 *      Copyright � 1994 AmiTCP/IP Group,
 *                       Network Solutions Development, Inc.
 *                       All rights reserved.
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef PWD_H
#include <pwd.h>
#endif
#ifndef GRP_H
#include <grp.h>
#endif
#ifndef UTMP_H
#include <utmp.h>
#endif

#include <sys/param.h>

#define USERGROUPNAME "usergroup.library"

/* Extended password encryption begins with underscore */
#define _PASSWORD_EFMT1 '_'

/* Maximum length for password */
#define _PASSWORD_LEN   128

/* A user can belong to NGROUPS different groups */
/* #define NGROUPS 32 */

/* Max length of a login name */
/* #define MAXLOGNAME      32 */

/* Credentials of a process */
struct UserGroupCredentials {
  uid_t   cr_ruid;
  gid_t   cr_rgid;
  mode_t  cr_umask;             /* umask */
  uid_t   cr_euid;
  short   cr_ngroups;           /* number of groups */
  gid_t   cr_groups[NGROUPS];
  pid_t   __ALIGN2__ cr_session;
  char    cr_login[MAXLOGNAME]; /* setlogin() name */
} __PACKED__;

/*
 * ID conversion macros
 */
#define UG2MU(id) ((id) == 0 ? 65535 : (id) == -2 ? 0 : (id))
#define MU2UG(id) ((id) == 65535 ? 0L : (id) == 0L ? -2L : (id))

/*
 * Context tags
 */
#define UGT_ERRNOBPTR 0x80000001
#define UGT_ERRNOWPTR 0x80000002
#define UGT_ERRNOLPTR 0x80000004
#define UGT_ERRNOPTR(size)\
  ((size == 4) ? UGT_ERRNOLPTR :\
   (size == 2) ? UGT_ERRNOWPTR :\
   (size == 1) ? UGT_ERRNOBPTR : 1L)
#define UGT_OWNER     0x80000011
#define UGT_INTRMASK  0x80000010

#endif /* LIBRARIES_USERGROUP_H */
