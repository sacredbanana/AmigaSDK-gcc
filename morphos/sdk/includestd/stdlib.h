/*	$Id: stdlib.h,v 1.7 2020/04/11 02:15:36 piru Exp $  */

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
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
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
 *	@(#)stdlib.h	5.13 (Berkeley) 6/4/91
 */

#ifndef _STDLIB_H_
#define _STDLIB_H_
#include <machine/ansi.h>

#if !defined(_ANSI_SOURCE)	/* for quad_t, etc. */
#include <sys/types.h>
#endif

#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#include <stddef.h>

typedef struct {
	int quot;		/* quotient */
	int rem;		/* remainder */
} div_t;

typedef struct {
	long quot;		/* quotient */
	long rem;		/* remainder */
} ldiv_t;

typedef struct {
	long long quot;		/* quotient */
	long long rem;		/* remainder */
} lldiv_t;

#if !defined(_ANSI_SOURCE)
typedef struct {
	quad_t quot;		/* quotient */
	quad_t rem;		/* remainder */
} qdiv_t;
#endif


#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0

#define	RAND_MAX	0x7fffffff

#define	MB_CUR_MAX	1	/* XXX */

#include <sys/cdefs.h>

__BEGIN_DECLS
#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
_Noreturn
#endif
void	 abort __P((void));
int	 abs __P((int));
int	 atexit __P((void (*)(void)));
double	 atof __P((const char *));
int	 atoi __P((const char *));
long	 atol __P((const char *));
long long	 atoll __P((const char *));
void	*bsearch __P((const void *, const void *, size_t,
	    size_t, int (*)(const void *, const void *)));
void	*calloc __P((size_t, size_t));
div_t	 div __P((int, int));
#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
_Noreturn
#endif
void	 exit __P((int));
void	 free __P((void *));
char	*getenv __P((const char *));
#define __getenv getenv
long	 labs __P((long));
ldiv_t	 ldiv __P((long, long));
long long	 llabs __P((long long));
lldiv_t	 lldiv __P((long long, long long));
void	*malloc __P((size_t));
void	 qsort __P((void *, size_t, size_t,
	    int (*)(const void *, const void *)));
int	 rand __P((void));
int	 rand_r __P((unsigned int *));
void	*realloc __P((void *, size_t));
void	 srand __P((unsigned));
double	 strtod __P((const char *, char **));
float    strtof __P((const char *, char **));
long	 strtol __P((const char *, char **, int));
long double
	 strtold __P((const char *, char **));
long long	 strtoll __P((const char *, char **, int));
unsigned long
	 strtoul __P((const char *, char **, int));
unsigned long long
	 strtoull __P((const char *, char **, int));
int	 system __P((const char *));

int	 posix_memalign __P((void **, size_t, size_t));
void	*memalign __P((size_t, size_t));

/* C11 */
void	*aligned_alloc __P((size_t, size_t));
int	 at_quick_exit __P((void (*)(void)));
#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
_Noreturn
#endif
void	 quick_exit __P((int));
#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
_Noreturn
#endif
void	 _Exit __P((int));

/* these are currently just stubs */
int	 mblen __P((const char *, size_t));
size_t	 mbstowcs __P((wchar_t *, const char *, size_t));
int	 wctomb __P((char *, wchar_t));
int	 mbtowc __P((wchar_t *, const char *, size_t));
size_t	 wcstombs __P((char *, const wchar_t *, size_t));

#if !defined(_ANSI_SOURCE) && !defined(_POSIX_SOURCE)
#if defined(__STDC__) && __GNUC__ < 2
void  *alloca __P((size_t)); 
#endif /* __GNUC__ < 2 */

char	*getbsize __P((int *, long *));
char	*cgetcap __P((char *, char *, int));
int	 cgetclose __P((void));
int	 cgetent __P((char **, char **, char *));
int	 cgetfirst __P((char **, char **));
int	 cgetmatch __P((char *, char *));
int	 cgetnext __P((char **, char **));
int	 cgetnum __P((char *, char *, long *));
int	 cgetset __P((char *));
int	 cgetstr __P((char *, char *, char **));
int	 cgetustr __P((char *, char *, char **));

int	 daemon __P((int, int));
char	*devname __P((int, int));
int	 getloadavg __P((double [], int));

long	 a64l __P((const char *));
char	*l64a __P((long));

void	 cfree __P((void *));

int	 getopt __P((int, char * const *, const char *));
extern	 char *optarg;			/* getopt(3) external variables */
extern	 int opterr;
extern	 int optind;
extern	 int optopt;
extern	 int optreset;
int	 getsubopt __P((char **, char * const *, char **));
extern	 char *suboptarg;		/* getsubopt(3) external variable */

int	 heapsort __P((void *, size_t, size_t,
	    int (*)(const void *, const void *)));
int	 mergesort __P((void *, size_t, size_t,
	    int (*)(const void *, const void *)));
int	 radixsort __P((const unsigned char **, int, const unsigned char *,
	    unsigned));
int	 sradixsort __P((const unsigned char **, int, const unsigned char *,
	    unsigned));

int	 iabs __P((int));

char	*initstate __P((unsigned, char *, int));
long	 random __P((void));
char	*realpath __P((const char *, char *));
char	*setstate __P((char *));
void	 srandom __P((unsigned));

int	 putenv __P((const char *));
int	 setenv __P((const char *, const char *, int));
void	 unsetenv __P((const char *));
void	 setproctitle __P((const char *, ...));

quad_t	 qabs __P((quad_t));
qdiv_t	 qdiv __P((quad_t, quad_t));
quad_t	 strtoq __P((const char *, char **, int));
u_quad_t strtouq __P((const char *, char **, int));

double	 drand48 __P((void));
double	 erand48 __P((unsigned short[3]));
long	 jrand48 __P((unsigned short[3]));
void	 lcong48 __P((unsigned short[7]));
long	 lrand48 __P((void));
long	 mrand48 __P((void));
long	 nrand48 __P((unsigned short[3]));
unsigned short *seed48 __P((unsigned short[3]));
void	 srand48 __P((long));
#endif /* !_ANSI_SOURCE && !_POSIX_SOURCE */

#ifdef __VEC__
void * vec_calloc __P((size_t , size_t));
void vec_free __P((void *));
void * vec_malloc __P((size_t));
void * vec_realloc __P((void *, size_t));
#endif /* __VEC__ */

__END_DECLS

#endif /* _STDLIB_H_ */
