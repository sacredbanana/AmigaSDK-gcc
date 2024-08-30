/*
  Copyright (C) 2014 Szilard Biro
  Copyright (C) 2018-2020 Harry Sintonen

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef PTHREAD_H
#define PTHREAD_H

#include <sys/types.h>
#include <sys/time.h>
#ifdef __ixemul
#include <sys/signal.h>
#endif
#include <errno.h>
#if defined(__ixemul) && !defined(EXEC_TYPES_H)
#include <stdint.h>
#pragma pack(2)
typedef struct
{
	void    *ln_Succ;
	void    *ln_Pred;
	uint8_t  ln_Type;
	int8_t   ln_Pri;
	char    *ln_Name;
} _pthread_Node_t;
typedef struct
{
	void    *mln_Succ;
	void    *mln_Pred;
} _pthread_MinNode_t;
typedef struct
{
	void    *mlh_Head;
	void    *mlh_Tail;
	void    *mlh_TailPred;
} _pthread_MinList_t;
typedef struct
{
	_pthread_MinNode_t  sr_Link;
	void               *sr_Waiter;
} _pthread_SemaphoreRequest_t;
typedef struct
{
	_pthread_Node_t             ss_Link;
	int16_t                     ss_NestCount;
	_pthread_MinList_t          ss_WaitQueue;
	_pthread_SemaphoreRequest_t ss_MultipleLink;
	void                       *ss_Owner;
	int16_t                     ss_QueueCount;
} _pthread_SignalSemaphore_t;
#pragma pack()
#else
#include <exec/types.h>
#include <exec/semaphores.h>
typedef struct MinList _pthread_MinList_t;
typedef struct Node _pthread_Node_t;
typedef struct SignalSemaphore _pthread_SignalSemaphore_t;
#endif
#include <sched.h>

//
// POSIX options
//

#undef _POSIX_THREADS
#define _POSIX_THREADS
#undef _POSIX_READER_WRITER_LOCKS
#define _POSIX_READER_WRITER_LOCKS
#undef _POSIX_SPIN_LOCKS
#define _POSIX_SPIN_LOCKS
#undef _POSIX_THREAD_ATTR_STACKSIZE
#define _POSIX_THREAD_ATTR_STACKSIZE
#undef _POSIX_THREAD_PRIORITY_SCHEDULING
#define _POSIX_THREAD_PRIORITY_SCHEDULING

//
// POSIX limits
//

#define PTHREAD_KEYS_MAX                      128
#define PTHREAD_STACK_MIN                     32768
#define PTHREAD_THREADS_MAX                   2019
#define PTHREAD_DESTRUCTOR_ITERATIONS         4

//
// POSIX pthread types
//

typedef unsigned int pthread_t;
typedef unsigned int pthread_key_t;

//
// POSIX thread attribute values
//

#define PTHREAD_CREATE_JOINABLE       0
#define PTHREAD_CREATE_DETACHED       1

#define PTHREAD_INHERIT_SCHED         0
#define PTHREAD_EXPLICIT_SCHED        1

#define PTHREAD_SCOPE_PROCESS         0
#define PTHREAD_SCOPE_SYSTEM          1

#define PTHREAD_CANCEL_ENABLE         0
#define PTHREAD_CANCEL_DISABLE        1

#define PTHREAD_CANCEL_ASYNCHRONOUS   0
#define PTHREAD_CANCEL_DEFERRED       1

#define PTHREAD_PROCESS_PRIVATE       0
#define PTHREAD_PROCESS_SHARED        1

//
// Threads
//

struct pthread_attr
{
	void *stackaddr;
	size_t stacksize;
#ifdef __MORPHOS__
	size_t stacksize68k;
#endif
	int detachstate;
	int policy;
	struct sched_param param;
	int inheritsched;
	int contentionscope;
};

typedef struct pthread_attr pthread_attr_t;

#define PTHREAD_CANCELED              ((void *)-1)

//
// Once key
//

struct pthread_once
{
	volatile int done;
	int started;
	int lock;
};

typedef struct pthread_once pthread_once_t;

#define PTHREAD_ONCE_INIT       {0, -1, 0}

//
// Mutex
//

#define PTHREAD_MUTEX_NORMAL     0
#define PTHREAD_MUTEX_RECURSIVE  1
#define PTHREAD_MUTEX_ERRORCHECK 2
#define PTHREAD_MUTEX_DEFAULT    PTHREAD_MUTEX_NORMAL

struct pthread_mutexattr
{
	int pshared;
	int kind;
};

typedef struct pthread_mutexattr pthread_mutexattr_t;

struct pthread_mutex
{
	int kind;
	_pthread_SignalSemaphore_t semaphore;
	int incond;
};

typedef struct pthread_mutex pthread_mutex_t;

#define PTHREAD_MUTEX_STALLED 0
#define PTHREAD_MUTEX_ROBUST  1

#define PTHREAD_PRIO_NONE     0
#define PTHREAD_PRIO_INHERIT  1
#define PTHREAD_PRIO_PROTECT  2

#define _PTHREAD_NULL_MINLIST {0, 0, 0}
#define _PTHREAD_NULL_MINNODE {0, 0}
#define _PTHREAD_NULL_NODE {0, 0, 0, 0, 0}
#define _PTHREAD_NULL_SEMAPHOREREQUEST {_PTHREAD_NULL_MINNODE, 0}
#define _PTHREAD_NULL_SIGNALSEMAPHORE {_PTHREAD_NULL_NODE, 0, _PTHREAD_NULL_MINLIST, _PTHREAD_NULL_SEMAPHOREREQUEST, 0, 0}

#define PTHREAD_MUTEX_INITIALIZER {PTHREAD_MUTEX_NORMAL, _PTHREAD_NULL_SIGNALSEMAPHORE}
#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER {PTHREAD_MUTEX_RECURSIVE, _PTHREAD_NULL_SIGNALSEMAPHORE}
#define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER {PTHREAD_MUTEX_ERRORCHECK, _PTHREAD_NULL_SIGNALSEMAPHORE}

//
// Condition variables
//

struct pthread_condattr
{
	int pshared;
};

typedef struct pthread_condattr pthread_condattr_t;

struct pthread_cond
{
	int pad1;
	_pthread_SignalSemaphore_t semaphore;
	_pthread_MinList_t waiters;
};

typedef struct pthread_cond pthread_cond_t;

#define PTHREAD_COND_INITIALIZER {0, _PTHREAD_NULL_SIGNALSEMAPHORE, _PTHREAD_NULL_MINLIST}

//
// Barriers
//

#define PTHREAD_BARRIER_SERIAL_THREAD 1

struct pthread_barrierattr
{
	int pshared;
};

typedef struct pthread_barrierattr pthread_barrierattr_t;

struct pthread_barrier
{
	unsigned int curr_height;
	unsigned int total_height;
	pthread_cond_t breeched;
	pthread_mutex_t lock;
};

typedef struct pthread_barrier pthread_barrier_t;

//
// Read-write locks
//

struct pthread_rwlockattr
{
	int pshared;
};

typedef struct pthread_rwlockattr pthread_rwlockattr_t;

struct pthread_rwlock
{
	_pthread_SignalSemaphore_t semaphore;
	int forwrite;
};

typedef struct pthread_rwlock pthread_rwlock_t;

#define PTHREAD_RWLOCK_INITIALIZER {_PTHREAD_NULL_SIGNALSEMAPHORE, 0}

//
// Spinlocks
//

typedef int pthread_spinlock_t;

#define PTHREAD_SPINLOCK_INITIALIZER 0

//
// POSIX thread routines
//

#ifdef  __cplusplus
extern "C" {
#endif

//
// Thread attribute functions
//

int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);
int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachstate);
int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
int pthread_attr_getstack(const pthread_attr_t *attr, void **stackaddr, size_t *stacksize);
int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr, size_t stacksize);
int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize);
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);
int pthread_attr_getschedparam(const pthread_attr_t *attr, struct sched_param *param);
int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param);
int pthread_attr_getschedpolicy(pthread_attr_t *attr, int *policy);
int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy);
int pthread_attr_getinheritsched(pthread_attr_t *attr, int *inheritsched);
int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched);
int pthread_attr_getscope(const pthread_attr_t *attr, int *contentionscope);
int pthread_attr_setscope(pthread_attr_t *attr, int contentionscope);

//
// Thread functions
//

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start)(void *), void *arg);
int pthread_detach(pthread_t thread);
int pthread_equal(pthread_t t1, pthread_t t2);
void pthread_exit(void *value_ptr)
#if __GNUC__ > 2
__attribute__ ((noreturn))
#endif
;
int pthread_join(pthread_t thread, void **value_ptr);
pthread_t pthread_self(void);
int pthread_cancel(pthread_t thread);
int pthread_setcancelstate(int state, int *oldstate);
int pthread_setcanceltype(int type, int *oldtype);
void pthread_testcancel(void);
int pthread_once(pthread_once_t *once_control, void (*init_routine)(void));

//
// Scheduling functions
//

int pthread_setschedparam(pthread_t thread, int policy, const struct sched_param *param);
int pthread_getschedparam(pthread_t thread, int *policy, struct sched_param *param);
int pthread_setschedprio(pthread_t thread, int prio);
int pthread_setconcurrency(int level);
int pthread_getconcurrency(void);

//
// Thread specific data functions
//

int pthread_key_create(pthread_key_t *key, void (*destructor)(void *));
int pthread_key_delete(pthread_key_t key);
int pthread_setspecific(pthread_key_t key, const void *value);
void *pthread_getspecific(pthread_key_t key);

//
// Mutex attribute functions
//

int pthread_mutexattr_init(pthread_mutexattr_t *attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);
int pthread_mutexattr_getpshared(const pthread_mutexattr_t *attr, int *pshared);
int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr, int pshared);
int pthread_mutexattr_gettype(pthread_mutexattr_t *attr, int *kind);
int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int kind);

//
// Mutex functions
//

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_timedlock(pthread_mutex_t *mutex, const struct timespec *abstime);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);

//
// Condition variable attribute functions
//

int pthread_condattr_init(pthread_condattr_t *attr);
int pthread_condattr_destroy(pthread_condattr_t *attr);
int pthread_condattr_getpshared(const pthread_condattr_t *attr, int *pshared);
int pthread_condattr_setpshared(pthread_condattr_t *attr, int pshared);

//
// Condition variable functions
//

int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);
int pthread_cond_destroy(pthread_cond_t *cond);
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
int pthread_cond_timedwait(pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime);
int pthread_cond_signal(pthread_cond_t *cond);
int pthread_cond_broadcast(pthread_cond_t *cond);

//
// Barrier attribute functions
//

int pthread_barrierattr_init(pthread_barrierattr_t *attr);
int pthread_barrierattr_destroy(pthread_barrierattr_t *attr);
int pthread_barrierattr_getpshared(const pthread_barrierattr_t *attr, int *pshared);
int pthread_barrierattr_setpshared(pthread_barrierattr_t *attr, int pshared);

//
// Barrier functions
//

int pthread_barrier_init(pthread_barrier_t *barrier, const pthread_barrierattr_t *attr, unsigned int count);
int pthread_barrier_destroy(pthread_barrier_t *barrier);
int pthread_barrier_wait(pthread_barrier_t *barrier);

//
// Read-write lock attribute functions
//

int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);
int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *attr, int *pshared);
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr, int pshared);

//
// Read-write lock functions
//

int pthread_rwlock_init(pthread_rwlock_t *lock, const pthread_rwlockattr_t *attr);
int pthread_rwlock_destroy(pthread_rwlock_t *lock);
int pthread_rwlock_tryrdlock(pthread_rwlock_t *lock);
int pthread_rwlock_trywrlock(pthread_rwlock_t *lock);
int pthread_rwlock_rdlock(pthread_rwlock_t *lock);
int pthread_rwlock_timedrdlock(pthread_rwlock_t *lock, const struct timespec *abstime);
int pthread_rwlock_wrlock(pthread_rwlock_t *lock);
int pthread_rwlock_timedwrlock(pthread_rwlock_t *lock, const struct timespec *abstime);
int pthread_rwlock_unlock(pthread_rwlock_t *lock);

//
// Spinlock functions
//

int pthread_spin_init(pthread_spinlock_t *lock, int pshared);
int pthread_spin_destroy(pthread_spinlock_t *lock);
int pthread_spin_lock(pthread_spinlock_t *lock);
int pthread_spin_trylock(pthread_spinlock_t *lock);
int pthread_spin_unlock(pthread_spinlock_t *lock);

//
// Non-portable functions
//

#ifdef _GNU_SOURCE
int pthread_setname_np(pthread_t thread, const char *name);
int pthread_getname_np(pthread_t thread, char *name, size_t len);
int pthread_cond_timedwait_relative_np(pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *reltime);
int pthread_getattr_np(pthread_t thread, pthread_attr_t *attr);
#endif

//
// Cancellation cleanup
//

void pthread_cleanup_push(void (*routine)(void *), void *arg);
void pthread_cleanup_pop(int execute);

//
// Signalling
//

int pthread_kill(pthread_t thread, int sig);
#ifdef __ixemul
int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset);
#endif

//
// Special functions
//

int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void));

#ifdef  __cplusplus
}
#endif

#if !defined(__cplusplus) && !defined(__PTHREAD_NOCANCELWRAP)

//
// Wrap cancellation points
//

#ifdef _UNISTD_H_
#define close(...) (pthread_testcancel(), close(__VA_ARGS__))
#define fsync(...) (pthread_testcancel(), fsync(__VA_ARGS__))
#define read(...) (pthread_testcancel(), read(__VA_ARGS__))
#define pause(...) (pthread_testcancel(), pause(__VA_ARGS__))
#define pread(...) (pthread_testcancel(), pread(__VA_ARGS__))
#define pread64(...) (pthread_testcancel(), pread64(__VA_ARGS__))
#define pwrite(...) (pthread_testcancel(), pwrite(__VA_ARGS__))
#define pwrite64(...) (pthread_testcancel(), pwrite64(__VA_ARGS__))
#undef select
#define select(...) (pthread_testcancel(), select(__VA_ARGS__))
#define sleep(...) (pthread_testcancel(), sleep(__VA_ARGS__))
#define usleep(...) (pthread_testcancel(), usleep(__VA_ARGS__))
#define write(...) (pthread_testcancel(), write(__VA_ARGS__))
#endif

#if defined(_FCNTL_H_) || defined(_SYS_FCNTL_H_)
#define creat(...) (pthread_testcancel(), creat(__VA_ARGS__))
#define fcntl(...) (pthread_testcancel(), fcntl(__VA_ARGS__))
#define open(...) (pthread_testcancel(), open(__VA_ARGS__))
#endif

#ifdef _TIME_H_
#define nanosleep(...) (pthread_testcancel(), nanosleep(__VA_ARGS__))
#endif

#ifdef _SYS_UIO_H_
#define readv(...) (pthread_testcancel(), readv(__VA_ARGS__))
#define writev(...) (pthread_testcancel(), writev(__VA_ARGS__))
#endif

#ifdef _STDLIB_H_
#define system(...) (pthread_testcancel(), system(__VA_ARGS__))
#endif

#if defined(_SYS_SOCKET_H_) && (defined(_NO_PPCINLINE) || !defined(CLIB_SOCKET_PROTOS_H))
#define accept(...) (pthread_testcancel(), accept(__VA_ARGS__))
#define connect(...) (pthread_testcancel(), connect(__VA_ARGS__))
#define recv(...) (pthread_testcancel(), recv(__VA_ARGS__))
#define recvfrom(...) (pthread_testcancel(), recvfrom(__VA_ARGS__))
#define recvmsg(...) (pthread_testcancel(), recvmsg(__VA_ARGS__))
#define send(...) (pthread_testcancel(), send(__VA_ARGS__))
#define sendmsg(...) (pthread_testcancel(), sendmsg(__VA_ARGS__))
#define sendto(...) (pthread_testcancel(), sendto(__VA_ARGS__))
#endif

#ifdef _USER_SIGNAL_H
#define sigsuspend(...) (pthread_testcancel(), sigsuspend(__VA_ARGS__))
#endif

#ifdef _SYS_WAIT_H_
#define wait(...) (pthread_testcancel(), wait(__VA_ARGS__))
#define wait3(...) (pthread_testcancel(), wait3(__VA_ARGS__))
#define wait4(...) (pthread_testcancel(), wait4(__VA_ARGS__))
#define waitpid(...) (pthread_testcancel(), waitpid(__VA_ARGS__))
#endif

#ifndef _NO_PPCINLINE

#ifdef _PPCINLINE_SOCKET_H
#undef accept
#undef connect
#undef recv
#undef recvfrom
#undef recvmsg
#undef send
#undef sendmsg
#undef sendto
#undef CloseSocket
#undef WaitSelect
#define accept(__p0, __p1, __p2) (pthread_testcancel(), LP3(48, LONG, accept, LONG, __p0, d0, struct sockaddr *, __p1, a0, LONG *, __p2, a1,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define connect(__p0, __p1, __p2) (pthread_testcancel(), LP3(54, LONG, connect, LONG, __p0, d0, const struct sockaddr *, __p1, a0, LONG, __p2, d1,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define recvfrom(__p0, __p1, __p2, __p3, __p4, __p5) (pthread_testcancel(), LP6(72, LONG, recvfrom, LONG, __p0, d0, UBYTE *, __p1, a0, LONG, __p2, d1, LONG, __p3, d2, struct sockaddr *, __p4, a1, LONG *, __p5, a2,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define recvmsg(__p0, __p1, __p2) (pthread_testcancel(), LP3(276, LONG, recvmsg, LONG, __p0, d0, struct msghdr *, __p1, a0, LONG, __p2, d1,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define send(__p0, __p1, __p2, __p3) (pthread_testcancel(), LP4(66, LONG, send, LONG, __p0, d0, const UBYTE *, __p1, a0, LONG, __p2, d1, LONG, __p3, d2,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define sendto(__p0, __p1, __p2, __p3, __p4, __p5) (pthread_testcancel(), LP6(60, LONG, sendto, LONG, __p0, d0, const UBYTE *, __p1, a0, LONG, __p2, d1, LONG, __p3, d2, const struct sockaddr *, __p4, a1, LONG, __p5, d3,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define sendmsg(__p0, __p1, __p2) (pthread_testcancel(), LP3(270, LONG, sendmsg, LONG, __p0, d0, struct msghdr *, __p1, a0, LONG, __p2, d1,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define CloseSocket(__p0) (pthread_testcancel(), LP1(120, LONG, CloseSocket, LONG, __p0, d0,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define WaitSelect(__p0, __p1, __p2, __p3, __p4, __p5) (pthread_testcancel(), LP6(126, LONG, WaitSelect, LONG, __p0, d0, fd_set *, __p1, a0, fd_set *, __p2, a1, fd_set *, __p3, a2, struct timeval *, __p4, a3, ULONG *, __p5, d1,, SOCKET_BASE_NAME, 0, 0, 0, 0, 0, 0))
#endif

#ifdef _PPCINLINE_EXEC_H
#undef Wait
#undef WaitIO
#undef WaitPort
#define Wait(__p0) (pthread_testcancel(), LP1(318, ULONG, Wait, ULONG, __p0, d0,, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define WaitIO(__p0) (pthread_testcancel(), LP1(474, BYTE, WaitIO, struct IORequest *, __p0, a1,, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0))
#define WaitPort(__p0) (pthread_testcancel(), LP1(384, struct Message *, WaitPort, struct MsgPort *, __p0, a0,, EXEC_BASE_NAME, 0, 0, 0, 0, 0, 0))
#endif

#else

#ifdef CLIB_SOCKET_PROTOS_H
#define CloseSocket(...) (pthread_testcancel(), CloseSocket(__VA_ARGS__))
#define WaitSelect(...) (pthread_testcancel(), WaitSelect(__VA_ARGS__))
#endif

#ifdef CLIB_EXEC_PROTOS_H
#define Wait(...) (pthread_testcancel(), Wait(__VA_ARGS__))
#define WaitIO(...) (pthread_testcancel(), WaitIO(__VA_ARGS__))
#define WaitPort(...) (pthread_testcancel(), WaitPort(__VA_ARGS__))
#endif

#endif

#endif

#endif
