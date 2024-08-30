#ifndef _ALLOCA_H_
#define _ALLOCA_H_

/* Memory allocation on the stack.
 *
 * alloca (N) returns a pointer to N bytes of memory
 *  allocated on the stack, which will last until the function returns.
 *  Use of alloca should be avoided:
 *    - inside arguments of function calls - undefined behaviour,
 *    - in inline functions - the allocation may actually last until the
 *      calling function returns,
 *    - for huge N (say, N >= 65536) - you never know how large (or small)
 *      the stack is, and when the stack cannot fulfill the memory allocation
 *      request, the program just crashes.
 */

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS
void *__alloca __P((size_t));
__END_DECLS

#undef alloca

#if defined USE_C_ALLOCA || !defined __GNUC__
# define alloca(_size) __alloca(_size)
#else
# define alloca(_size) __builtin_alloca(_size)
#endif /* USE_C_ALLOCA || !__GNUC__ */

#endif /* _ALLOCA_H_ */
