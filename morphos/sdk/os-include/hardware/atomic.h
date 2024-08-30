#ifndef HARDWARE_ATOMIC_H
#define HARDWARE_ATOMIC_H

/*
	useful inlines for atomic operations

	Copyright © 2007-2018 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#if defined(__GNUC__)

#if !defined(__PPC__)
# warning "Unsupported CPU family"
#endif

/*
 * NOTES
 *
 * - The pointer to access must be aligned by 4. Unaligned access will
 *   result in exception.
 * - To work correctly, all concurrent write accesses to the pointer must
 *   be done using ATOMIC-routines.
 * - ATOMIC_SPINLOCK lock should not be held for a long time. Also,
 *   code keeping the lock most of the time will be equally bad. In fact,
 *   for such cases you should think twice whether SignalSemaphore would
 *   do a better job.
 * - ATOMIC_SPINLOCK does not nest.
 */

static inline LONG _ATOMIC_FETCH(LONG *ptr)
{
	return *ptr;
}
#define ATOMIC_FETCH(p) _ATOMIC_FETCH(p)

static inline LONG _ATOMIC_STORE(LONG *ptr, LONG newval)
{
	register LONG ret;

	__asm__ __volatile__ (
	"\n"
	".atomic_store_loop_%=:\n"
	"	lwarx	%0,0,%1\n"
	"	stwcx.	%2,0,%1\n"
	"	bne-	.atomic_store_loop_%=\n"
	: "=&r" (ret)
	: "b" (ptr), "r" (newval)
	: "memory", "cr0");

	return ret;
}
#define ATOMIC_STORE(p,n) _ATOMIC_STORE(p,n)

static inline LONG _ATOMIC_ADD(LONG *ptr, LONG val)
{
	register LONG ret, tmp;

	__asm__ __volatile__ (
	"\n"
	".atomic_add_loop_%=:\n"
	"	lwarx	%0,0,%2\n"
	"	add	%1,%3,%0\n"
	"	stwcx.	%1,0,%2\n"
	"	bne-	.atomic_add_loop_%=\n"
	: "=&b" (ret), "=&r" (tmp)
	: "b" (ptr), "r" (val)
	: "memory", "cr0");

	return ret;
}
#define ATOMIC_ADD(p,v) _ATOMIC_ADD(p,v)
#define ATOMIC_SUB(p,v) _ATOMIC_ADD(p,-(v))

static inline ULONG _ATOMIC_OR(ULONG *ptr, ULONG val)
{
	register ULONG ret, tmp;

	__asm__ __volatile__ (
	"\n"
	".atomic_or_loop_%=:\n"
	"	lwarx	%0,0,%2\n"
	"	or	%1,%3,%0\n"
	"	stwcx.	%1,0,%2\n"
	"	bne-	.atomic_or_loop_%=\n"
	: "=&r" (ret), "=&r" (tmp)
	: "b" (ptr), "r" (val)
	: "memory", "cr0");

	return ret;
}
#define ATOMIC_OR(p,v) _ATOMIC_OR(p,v)

static inline ULONG _ATOMIC_AND(ULONG *ptr, ULONG val)
{
	register ULONG ret, tmp;

	__asm__ __volatile__ (
	"\n"
	".atomic_and_loop_%=:\n"
	"	lwarx	%0,0,%2\n"
	"	and	%1,%3,%0\n"
	"	stwcx.	%1,0,%2\n"
	"	bne-	.atomic_and_loop_%=\n"
	: "=&r" (ret), "=&r" (tmp)
	: "b" (ptr), "r" (val)
	: "memory", "cr0");

	return ret;
}
#define ATOMIC_AND(p,v) _ATOMIC_AND(p,v)

static inline ULONG _ATOMIC_XOR(ULONG *ptr, ULONG val)
{
	register ULONG ret, tmp;

	__asm__ __volatile__ (
	"\n"
	".atomic_xor_loop_%=:\n"
	"	lwarx	%0,0,%2\n"
	"	xor	%1,%3,%0\n"
	"	stwcx.	%1,0,%2\n"
	"	bne-	.atomic_xor_loop_%=\n"
	: "=&r" (ret), "=&r" (tmp)
	: "b" (ptr), "r" (val)
	: "memory", "cr0");

	return ret;
}
#define ATOMIC_XOR(p,v) _ATOMIC_XOR(p,v)

static inline LONG _ATOMIC_CMPXCHG(LONG *ptr, LONG old, LONG newval)
{
	register LONG ret;

	__asm__ __volatile__ (
	"\n"
	".atomic_cmpxchg_loop_%=:\n"
	"	lwarx	%0,0,%2\n"
	"	cmpw	0,%0,%3\n"
	"	bne-	.atomic_cmpxchg_out_%=\n"
	"	stwcx.	%4,0,%2\n"
	"	bne-	.atomic_cmpxchg_loop_%=\n"
	".atomic_cmpxchg_out_%=:\n"
	: "=&r" (ret)
#if __GNUC__ == 3
	: "+m" (*ptr),
#else
	: "m" (*ptr),
#endif
	"b" (ptr), "r" (old), "r" (newval)
	: "memory", "cr0");

	return ret;
}
#define ATOMIC_CMPXCHG(p,o,n) _ATOMIC_CMPXCHG(p,o,n)


static inline ULONG _ATOMIC_BTST(ULONG *ptr, LONG bit)
{
	const ULONG mask = 1 << bit;
	return _ATOMIC_FETCH((LONG *)ptr) & mask;
}
#define ATOMIC_BTST(p,b) _ATOMIC_BTST(p,b)

static inline ULONG _ATOMIC_BSET(ULONG *ptr, LONG bit)
{
	const ULONG mask = 1 << bit;
	return _ATOMIC_OR(ptr, mask) & mask;
}
#define ATOMIC_BSET(p,b) _ATOMIC_BSET(p,b)

static inline ULONG _ATOMIC_BCLR(ULONG *ptr, LONG bit)
{
	const ULONG mask = 1 << bit;
	return _ATOMIC_AND(ptr, ~mask) & mask;
}
#define ATOMIC_BCLR(p,b) _ATOMIC_BCLR(p,b)

static inline ULONG _ATOMIC_BCHG(ULONG *ptr, LONG bit)
{
	const ULONG mask = 1 << bit;
	return _ATOMIC_XOR(ptr, mask) & mask;
}
#define ATOMIC_BCHG(p,b) _ATOMIC_BCHG(p,b)

/*
 * Note: The succ pointer must be the first entry in node.
 */
static inline void _ATOMIC_SADDHEAD(APTR *head, APTR node)
{
	register APTR tmp;

	__asm__ __volatile__ (
	"\n"
	".atomic_saddhead_loop_%=:\n"
	"	lwarx	%0,0,%1\n"
	"	stw	%0,0(%2)\n"
	"	sync\n"
	"	stwcx.	%2,0,%1\n"
	"	bne-	.atomic_saddhead_loop_%=\n"
	: "=&r" (tmp)
	: "b" (head), "b" (node)
	: "memory", "cr0");
}
#define ATOMIC_SADDHEAD(h,n) _ATOMIC_SADDHEAD(h,n)

static inline APTR _ATOMIC_SREMHEAD(APTR *head)
{
	register APTR node, tmp;

	__asm__ __volatile__ (
	"\n"
	".atomic_sremhead_loop_%=:\n"
	"	lwarx	%0,0,%2\n"
	"	mr.	%1,%0\n"
	"	beq-	.atomic_sremhead_skip_%=\n"
	"	lwz	%1,0(%0)\n"
	".atomic_sremhead_skip_%=:\n"
	"	stwcx.	%1,0,%2\n"
	"	bne-	.atomic_sremhead_loop_%=\n"
	"	isync\n"
	: "=&b" (node), "=&r" (tmp)
	: "b" (head)
	: "memory", "cr0");

	return node;
}
#define ATOMIC_SREMHEAD(h) _ATOMIC_SREMHEAD(h)

/*
 * Note: The succ bptr pointer must be the first entry in node.
 */
static inline void _ATOMIC_BADDHEAD(BPTR *head, APTR node)
{
	register BPTR tmp;

	__asm__ __volatile__ (
	"\n"
	".atomic_baddhead_loop_%=:\n"
	"	lwarx	%0,0,%1\n"
	"	stw	%0,0(%2)\n"
	"	sync\n"
	"	stwcx.	%3,0,%1\n"
	"	bne-	.atomic_baddhead_loop_%=\n"
	: "=&r" (tmp)
	: "b" (head), "b" (node), "r" ((BPTR) node >> 2)
	: "memory", "cr0");
}
#define ATOMIC_BADDHEAD(h,n) _ATOMIC_BADDHEAD(h,n)

static inline APTR _ATOMIC_BREMHEAD(BPTR *head)
{
	register BPTR tmp;
	register APTR node;

	__asm__ __volatile__ (
	"\n"
	".atomic_bremhead_loop_%=:\n"
	"	lwarx	%0,0,%2\n"
	"	rlwinm.	%1,%0,2,0,29\n"
	"	beq-	.atomic_bremhead_skip_%=\n"
	"	lwz	%0,0(%1)\n"
	".atomic_bremhead_skip_%=:\n"
	"	stwcx.	%0,0,%2\n"
	"	bne-	.atomic_bremhead_loop_%=\n"
	"	isync\n"
	: "=&r" (tmp), "=&b" (node)
	: "b" (head)
	: "memory", "cr0");

	return node;
}
#define ATOMIC_BREMHEAD(h) _ATOMIC_BREMHEAD(h)

typedef struct
{
	volatile ULONG as_lock;
} atomic_spinlock;

static inline void _ATOMIC_SPINLOCK(atomic_spinlock *as)
{
	register LONG tmp;

	__asm__ __volatile__ (
	"\n"
	".atomic_spinlock_loop_%=:\n"
	"	lwarx	%0,0,%1\n"
	"	cmpwi	%0,0\n"
	"	bne-	.atomic_spinlock_loop_%=\n"
	"	stwcx.	%2,0,%1\n"
	"	bne-	.atomic_spinlock_loop_%=\n"
	"	isync\n"
	: "=&r" (tmp)
	: "b" (&as->as_lock), "r" (1)
	: "memory", "cr0");
}
#define ATOMIC_SPINLOCK(p) _ATOMIC_SPINLOCK(p)

static inline void _ATOMIC_SPINUNLOCK(atomic_spinlock *as)
{
	__asm__ __volatile__ (
	"\n"
	"	eieio\n"  /* was: sync */
	"	stw	%1,0(%0)\n"
	: /* no result */
	: "b" (&as->as_lock), "r" (0)
	: "memory");
}
#define ATOMIC_SPINUNLOCK(p) _ATOMIC_SPINUNLOCK(p)

static inline LONG _ATOMIC_SPINTRYLOCK(atomic_spinlock *as)
{
	return _ATOMIC_STORE((LONG *) &as->as_lock, 1) == 0;
}
#define ATOMIC_SPINTRYLOCK(p) _ATOMIC_SPINTRYLOCK(p)

#else
# warning "Unsupported compiler"
#endif

#endif /* HARDWARE_ATOMIC_H */
