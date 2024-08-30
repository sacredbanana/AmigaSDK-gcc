#ifndef __GNUC__
/* Use the system's macros with the system's compiler.  */
#include <varargs.h>
#else
/* Record that varargs.h is defined; this turns off stdarg.h.  */

#ifndef _VARARGS_H
#define _VARARGS_H

#ifdef __sparc__
#include "va-sparc.h"
#else
#ifdef __spur__
#include "va-spur.h"
#else
#ifdef __mips__
#include "va-mips.h"
#else
#ifdef __i860__
#include "va-i860.h"
#else
#ifdef __pyr__
#include "va-pyr.h"
#else
#ifdef __m88k__
#include "va-m88k.h"
#else

#ifdef __NeXT__

/* On Next, erase any vestiges of stdarg.h.  */

#undef va_alist
#undef va_dcl
#undef va_list
#undef va_start
#undef va_end
#undef __va_rounded_size
#undef va_arg
#endif  /* __NeXT__ */

/* In GCC version 2, we want an ellipsis at the end of the declaration
   of the argument list.  GCC version 1 can't parse it.  */

#if __GNUC__ > 1
#define __va_ellipsis ...
#else
#define __va_ellipsis
#endif

/* These macros implement traditional (non-ANSI) varargs
   for GNU C.  */

#define va_alist  __builtin_va_alist
/* The ... causes current_function_varargs to be set in cc1.  */
#define va_dcl    int __builtin_va_alist; __va_ellipsis

/* Make this a macro rather than a typedef, so we can undef any other defn.  */
#define va_list __va___list
typedef char * __va___list;

#define va_start(AP)  AP=(char *) &__builtin_va_alist

#define va_end(AP)

#define __va_rounded_size(TYPE)  \
  (((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))

#define va_arg(AP, TYPE)						\
 (AP += __va_rounded_size (TYPE),					\
  *((TYPE *) (AP - __va_rounded_size (TYPE))))

#endif /* not m88k */
#endif /* not pyr */
#endif /* not i860 */
#endif /* not mips */
#endif /* not spur */
#endif /* not sparc */
#endif /* not _VARARGS_H */
#endif /* __GNUC__ */
