/* Allow this file to be included multiple times
   with different settings of NDEBUG.  */
#undef assert
#undef __assert

#ifdef NDEBUG
#define assert(ignore) ((void) 0)
#else

#if !defined(__GNUC__)

#include <stdio.h> /* printf () */
#include <stdlib.h> /* abort () */

#define assert(expression)  \
  ((void) ((expression) ? 0 : __assert (expression, __FILE__, __LINE__)))

#define __assert(expression, file, lineno)  \
  (printf ("%s:%u: failed assertion\n", file, lineno),  \
   abort (), 0)

#else

#if defined(__STDC__) || defined (__cplusplus)

/* Defined in libgcc.a */
#ifdef __cplusplus
extern "C" {
extern void __eprintf (const char *, const char *, int, const char *);
}
#else
extern void __eprintf (const char *, const char *, int, const char *);
#endif

#define assert(expression)  \
  ((void) ((expression) ? 0 : __assert (#expression, __FILE__, __LINE__)))

#define __assert(expression, file, line)  \
  (__eprintf ("%s:%u: failed assertion `%s'\n",         \
	      file, line, expression), 0)

#else /* no __STDC__ and not C++; i.e. -traditional.  */

extern void __eprintf (); /* Defined in libgcc.a */

#define assert(expression)  \
  ((void) ((expression) ? 0 : __assert (expression, __FILE__, __LINE__)))

#define __assert(expression, file, lineno)  \
  (__eprintf ("%s:%u: failed assertion `%s'\n",         \
	      file, lineno, "expression"), 0)

#endif /* no __STDC__ and not C++; i.e. -traditional.  */
#endif /* no __GNU__; i.e., /bin/cc.  */
#endif
