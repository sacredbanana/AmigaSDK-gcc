/*
 * Generic Thread-Local Storage (TLS) implementation for MorphOS
 * Copyright (C) 2020 Harry Sintonen <sintonen@iki.fi>
 *
 * 1. Declare struct __tls_variables with desired structure.
 * 2. #define TLS_CONSTRUCTOR and TLS_DESTRUCTOR to whatever is needed.
 *    TLS_CONSTRUCTOR_EXTRA and TLS_DESTRUCTOR_EXTRA can be used to perform
 *    extra setup and/or cleanup. Define __TLS_DEBUG to get extra debug.
 * 3. Include this header.
 * 4. Use __gettls() to get task unique pointer to struct __tls_variables.
 *    The variables default to all zero. If there is no OS support for TLS
 *    or other error occurs tasks share same static data.
 */
#include <hardware/atomic.h>
#include <exec/execbase.h>
#include <exec/tasks.h>
#include <proto/exec.h>
#include <constructor.h>

#ifdef __TLS_DEBUG
void dprintf(const char *, ...);
#define __TLS_PRINT(...) dprintf(__VA_ARGS__)
#else
#define __TLS_PRINT(...) do {} while (0)
#endif

#if __GNUC__ > 2
#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)
#else
#define likely(x)      (x)
#define unlikely(x)    (x)
#endif

static ULONG __tlsindex = TLS_INVALID_INDEX;
static struct __tls_variables __tls_fallback;

static VOID __tls_destructor(APTR value, APTR userdata)
{
	struct ExecBase *SysBase = userdata;
	struct __tls_variables *__tls = value;
	__TLS_PRINT("%s: task %p free tls at %p\n", __func__, FindTask(NULL), __tls);

#ifdef TLS_THREAD_DESTRUCTOR_EXTRA
	TLS_THREAD_DESTRUCTOR_EXTRA
#endif

	FreeMem(__tls, sizeof(*__tls));
}

static struct __tls_variables *__gettls(void)
{
	static int __tlsinitdone = 0;
	static ULONG __tlsinit = 0;
	struct __tls_variables *__tls = NULL;

	__TLS_PRINT("%s: task %p\n", __func__, FindTask(NULL));

	if (unlikely(!__tlsinitdone))
	{
		__TLS_PRINT("%s: task %p initialize\n", __func__, FindTask(NULL));

		/* This should never really race as threads are not set up before
		   constructor calls us. Lets handle it correctly even it never is
		   going to happen anyway... - Piru */
		if (likely(ATOMIC_STORE(&__tlsinit, 1) == 0))
		{
			if (likely(LIB_MINVER(&SysBase->LibNode, 51, 46)))
			{
				struct TagItem __tlstags[3] =
				{
					{TLSTAG_DESTRUCTOR, (IPTR) __tls_destructor},
					{TLSTAG_USERDATA,   (IPTR) SysBase},
					{TAG_DONE, 0}
				};
				__tlsindex = TLSAllocA(__tlstags);
				__TLS_PRINT("%s: task %p initializing __tlsindex %lu\n", __func__, FindTask(NULL), __tlsindex);
			}

			/* Let potential other callers know we've initialized things. */
			__tlsinitdone = 1;
		}
		else
		{
			/* We ran into highly unlikely race condition. Wait for the other
			   thread to finish initializing before continuing execution. */
			while (likely(!__tlsinitdone))
				;
		}
	}

	if (likely(__tlsindex != TLS_INVALID_INDEX))
	{
		__tls = TLSGetValue(__tlsindex);
		__TLS_PRINT("%s: task %p tls %p\n", __func__, FindTask(NULL), __tls);
		if (unlikely(!__tls))
		{
			__tls = AllocMem(sizeof(*__tls), MEMF_CLEAR);
			__TLS_PRINT("%s: task %p set up tls to address %p\n", __func__, FindTask(NULL), __tls);
			if (unlikely(!__tls || !TLSSetValue(__tlsindex, __tls)))
			{
				if (__tls)
				{
					FreeMem(__tls, sizeof(*__tls));
					__tls = NULL;
				}
			}
		}
	}

	/* If something failed, fall back to globally shared variables. */
	if (unlikely(!__tls))
	{
		__TLS_PRINT("%s: task %p using static tls %p\n", __func__, FindTask(NULL), __tls);
		__tls = &__tls_fallback;
	}

	return __tls;
}

TLS_CONSTRUCTOR
{
	__TLS_PRINT("%s: constructor\n", __func__);

#ifdef TLS_CONSTRUCTOR_EXTRA
	TLS_CONSTRUCTOR_EXTRA
#endif

	return __gettls() ? 0 : 1;
}

TLS_DESTRUCTOR
{
	APTR __value;
	__TLS_PRINT("%s: destructor\n", __func__);

	if (unlikely(__tlsindex == TLS_INVALID_INDEX))
		return;

#ifdef TLS_DESTRUCTOR_EXTRA
	TLS_DESTRUCTOR_EXTRA
#endif

	__value = TLSGetValue(__tlsindex);
	if (__value)
	{
		TLSSetValue(__tlsindex, NULL); /* NULL cannot fail */
		__TLS_PRINT("%s: task %p free tls at %p\n", __func__, FindTask(NULL), __value);
		__tls_destructor(__value, SysBase);
	}
	__TLS_PRINT("%s: task %p free __tlsindex %lu\n", __func__, FindTask(NULL), __tlsindex);
	TLSFree(__tlsindex);
	__tlsindex = TLS_INVALID_INDEX;
}
