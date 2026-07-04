#ifndef _SPAWN_H
#define _SPAWN_H 1

/*
 *  This file is part of ixemul.library for the Amiga.
 *  Copyright (C) 2025 Harry Sintonen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <sys/types.h>
#include <sys/_sigset.h>

#ifndef _SIGSET_T_DECLARED
#define _SIGSET_T_DECLARED
typedef __sigset_t      sigset_t;
#endif

struct sched_param;

typedef struct
{
  short int __flags;
  pid_t     __pgrp;
  sigset_t  __sd;
  sigset_t  __ss;
  /*struct sched_param __sp;*/
  int       __policy;
  int       __cgroup;
  int       __pad[16];
} posix_spawnattr_t;

struct __spawn_action;

typedef struct
{
  int       __allocated;
  int       __used;
  struct    __spawn_action *__actions;
  int       __pad[16];
} posix_spawn_file_actions_t;

#define POSIX_SPAWN_RESETIDS          0x01
#define POSIX_SPAWN_SETPGROUP         0x02
#define POSIX_SPAWN_SETSIGDEF         0x04
#define POSIX_SPAWN_SETSIGMASK        0x08
#define POSIX_SPAWN_SETSCHEDPARAM     0x10
#define POSIX_SPAWN_SETSCHEDULER      0x20
#if defined(_GNU_SOURCE)
# define POSIX_SPAWN_USEVFORK         0x40
# define POSIX_SPAWN_SETSID           0x80
# define POSIX_SPAWN_SETCGROUP       0x100
#endif

__BEGIN_DECLS
int posix_spawn __P((pid_t *, const char *, const posix_spawn_file_actions_t *, const posix_spawnattr_t *, char *const [], char *const []));
int posix_spawnp __P((pid_t *, const char *, const posix_spawn_file_actions_t *, const posix_spawnattr_t *, char *const [], char *const []));
int posix_spawnattr_init __P((posix_spawnattr_t *));
int posix_spawnattr_destroy __P((posix_spawnattr_t *));
int posix_spawnattr_getsigdefault __P((const posix_spawnattr_t *, sigset_t *));
int posix_spawnattr_setsigdefault __P((posix_spawnattr_t *, const sigset_t *));
int posix_spawnattr_getsigmask __P((const posix_spawnattr_t *, sigset_t *));
int posix_spawnattr_setsigmask __P((posix_spawnattr_t *, const sigset_t *));
int posix_spawnattr_getflags __P((const posix_spawnattr_t *, short int *));
int posix_spawnattr_setflags __P((posix_spawnattr_t *, short int));
int posix_spawnattr_getpgroup __P((const posix_spawnattr_t *,pid_t *));
int posix_spawnattr_setpgroup __P((posix_spawnattr_t *, pid_t));
int posix_spawnattr_getschedpolicy __P((const posix_spawnattr_t *, int *));
int posix_spawnattr_setschedpolicy __P((posix_spawnattr_t *, int));
int posix_spawnattr_getschedparam __P((const posix_spawnattr_t *, struct sched_param *));
int posix_spawnattr_setschedparam __P((posix_spawnattr_t *, const struct sched_param *));
int posix_spawn_file_actions_init __P((posix_spawn_file_actions_t *));
int posix_spawn_file_actions_destroy __P((posix_spawn_file_actions_t *));
int posix_spawn_file_actions_addopen __P((posix_spawn_file_actions_t *, int, const char *, int, mode_t));
int posix_spawn_file_actions_addclose __P((posix_spawn_file_actions_t *, int));
int posix_spawn_file_actions_adddup2 __P((posix_spawn_file_actions_t *, int, int));
#if __BSD_VISIBLE
int posix_spawn_file_actions_addchdir_np __P((posix_spawn_file_actions_t *, const char *));
int posix_spawn_file_actions_addfchdir_np __P((posix_spawn_file_actions_t *, int));
int posix_spawn_file_actions_addclosefrom_np __P((posix_spawn_file_actions_t *, int));
int posix_spawn_file_actions_addtcsetpgrp_np __P((posix_spawn_file_actions_t *, int));
#endif
__END_DECLS

#endif /* _SPAWN_H */
