/*      $NetBSD: stdlib.h,v 1.24 1995/03/22 01:08:31 jtc Exp $  */

/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      @(#)stdlib.h    5.13 (Berkeley) 6/4/91
 */

#ifndef _STDLIB_H_
#define _STDLIB_H_
#include <machine/ansi.h>

#include <sys/types.h>

#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#include <stddef.h>

typedef struct {
	int quot;               /* quotient */
	int rem;                /* remainder */
} div_t;

typedef struct {
	long quot;              /* quotient */
	long rem;               /* remainder */
} ldiv_t;

#define EXIT_FAILURE    1
#define EXIT_SUCCESS    0

#define RAND_MAX        0x7fffffff

#define MB_CUR_MAX      4       /* XXX */

#include <sys/cdefs.h>

__BEGIN_DECLS
#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
_Noreturn
#endif
void     abort __P((void));
int      abs __P((int));
int      atexit __P((void (*)(void)));
double   atof __P((const char *));
int      atoi __P((const char *));
long     atol __P((const char *));
void    *bsearch __P((const void *, const void *, size_t,
	    size_t, int (*)(const void *, const void *)));
void    *calloc __P((size_t, size_t));
div_t    div __P((int, int));
#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
_Noreturn
#endif
void     exit __P((int));
void     free __P((void *));
char    *getenv __P((const char *));
long     labs __P((long));
ldiv_t   ldiv __P((long, long));
void    *malloc __P((size_t));
int      mblen __P((const char *, size_t));
size_t   mbstowcs __P((wchar_t *, const char *, size_t));
int      mbtowc __P((wchar_t *, const char *, size_t));
void    *memalign __P((size_t, size_t));
void     qsort __P((void *, size_t, size_t,
	    int (*)(const void *, const void *)));
int      rand __P((void));
void    *realloc __P((void *, size_t));
void     srand __P((unsigned));
double   strtod __P((const char *, char **));
float    strtof __P((const char *, char **));
long     strtol __P((const char *, char **, int));
long double
	 strtold __P((const char *, char **));
unsigned long
	 strtoul __P((const char *, char **, int));
int      system __P((const char *));
int      wctomb __P((char *, wchar_t));
size_t   wcstombs __P((char *, const wchar_t *, size_t));

#if __ISO_C_VISIBLE >= 1999 || defined(__cplusplus)

typedef struct {
	long long quot;         /* quotient */
	long long rem;          /* remainder */
} lldiv_t;

long long atoll __P((const char *));
long long
	 llabs __P((long long));
lldiv_t	 lldiv __P((long long, long long));
long long strtoll __P((const char *, char **, int));
unsigned long long
	 strtoull __P((const char *, char **, int));

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
_Noreturn
#endif
void	 _Exit __P((int));
#endif /* __ISO_C_VISIBLE >= 1999 */

#if __ISO_C_VISIBLE >= 2011 || __cplusplus >= 201103L
/* C11 */
void    *aligned_alloc __P((size_t, size_t));
#endif /* __ISO_C_VISIBLE >= 2011 */

#if __POSIX_VISIBLE >= 199506 || __XSI_VISIBLE
char    *realpath __P((const char *, char *));
#endif
#if __POSIX_VISIBLE >= 200112
int      posix_memalign __P((void **, size_t, size_t));
int      setenv __P((const char *, const char *, int));
void     unsetenv __P((const char *));
#endif

#if __POSIX_VISIBLE >= 200809 || __XSI_VISIBLE
#ifndef _GETSUBOPT_DECLARED
#define	_GETSUBOPT_DECLARED
int      getsubopt __P((char **, char * const *, char **));
#endif
#ifndef _MKDTEMP_DECLARED
char    *mkdtemp __P((char *));
#define	_MKDTEMP_DECLARED
#endif
#ifndef _MKSTEMP_DECLARED
int      mkstemp __P((char *));
#define	_MKSTEMP_DECLARED
#endif
#endif /* __POSIX_VISIBLE >= 200809 || __XSI_VISIBLE */

#if __XSI_VISIBLE
long     a64l __P((const char *));
double   drand48 __P((void));
/* char	*ecvt(double, int, int * __restrict, int * __restrict); */
double   erand48 __P((unsigned short[3]));
/* char	*fcvt(double, int, int * __restrict, int * __restrict); */
/* char	*gcvt(double, int, int * __restrict, int * __restrict); */
char    *initstate __P((unsigned, char *, int));
long     jrand48 __P((unsigned short[3]));
char    *l64a __P((long));
void     lcong48 __P((unsigned short[7]));
long     lrand48 __P((void));
#if !defined(_MKTEMP_DECLARED) && (__BSD_VISIBLE || __XSI_VISIBLE <= 600)
char	*mktemp(char *);
#define	_MKTEMP_DECLARED
#endif
long     mrand48 __P((void));
long     nrand48 __P((unsigned short[3]));
int      putenv __P((const char *));
long     random __P((void));
unsigned short *seed48 __P((unsigned short[3]));
char    *setstate __P((char *));
void     srand48 __P((long));
void     srandom __P((unsigned int));
#endif /* __XSI_VISIBLE */

#if __BSD_VISIBLE
#if defined(alloca) && (alloca == __builtin_alloca) && (__GNUC__ < 2)
void  *alloca __P((int));     /* built-in for gcc */
#else
void  *alloca __P((size_t));
#endif /* __GNUC__ */

char    *getbsize __P((int *, long *));
char    *cgetcap __P((char *, char *, int));
int      cgetclose __P((void));
int      cgetent __P((char **, char **, char *));
int      cgetfirst __P((char **, char **));
int      cgetmatch __P((char *, char *));
int      cgetnext __P((char **, char **));
int      cgetnum __P((char *, char *, long *));
int      cgetset __P((char *));
int      cgetstr __P((char *, char *, char **));
int      cgetustr __P((char *, char *, char **));

int      daemon __P((int, int));
char    *devname __P((int, int));
int      getloadavg __P((double [], int));

int      heapsort __P((void *, size_t, size_t,
	    int (*)(const void *, const void *)));
int      mergesort __P((void *, size_t, size_t,
	    int (*)(const void *, const void *)));
int      radixsort __P((const unsigned char **, int, const unsigned char *,
	    unsigned));
int      sradixsort __P((const unsigned char **, int, const unsigned char *,
	    unsigned));

void     cfree __P((void *));

quad_t   qabs __P((quad_t));
typedef struct {
	quad_t quot;		/* quotient */
	quad_t rem;		/* remainder */
} qdiv_t;
qdiv_t   qdiv __P((quad_t, quad_t));
quad_t   strtoq __P((const char *, char **, int));
u_quad_t strtouq __P((const char *, char **, int));

extern char *suboptarg;			/* getsubopt(3) external variable */
#endif /* __BSD_VISIBLE */

__END_DECLS

#endif /* _STDLIB_H_ */
