#ifndef _WCHAR_H_
#define _WCHAR_H_

#include <sys/cdefs.h>
#include <stddef.h>

#ifndef _STDIO_H_
#include <stdio.h>
#endif

#ifndef _STDINT_H_
#include <stdint.h>
#endif

typedef long wint_t;

struct __mbstate_t
{
	int count;
	wchar_t sofar;
};

typedef struct __mbstate_t mbstate_t;

#ifndef WCHAR_MIN
#define WCHAR_MAX 0x7fffffff
#define WCHAR_MIN (-WCHAR_MAX-1)
#endif /* WCHAR_MIN */

#ifndef WEOF
#define WEOF (-1)
#endif /* WEOF */

struct tm;

__BEGIN_DECLS
size_t wcslen(const wchar_t *);

wint_t btowc(int);
wint_t fgetwc(FILE *);
wchar_t *fgetws(wchar_t * , int, FILE * );
wint_t fputwc(wchar_t, FILE *);
int fputws(const wchar_t * , FILE * );
int fwide(FILE *, int);
int fwprintf(FILE * , const wchar_t * , ...);
int fwscanf(FILE * , const wchar_t * , ...);
wint_t getwc(FILE *);
wint_t getwchar(void);
size_t mbrlen(const char * , size_t, mbstate_t * );
size_t mbrtowc(wchar_t * , const char * , size_t, mbstate_t * );
int mbsinit(const mbstate_t *);
size_t mbsrtowcs(wchar_t * , const char ** , size_t, mbstate_t * );
wint_t putwc(wchar_t, FILE *);
wint_t putwchar(wchar_t);
int swprintf(wchar_t * , size_t, const wchar_t * , ...);
int swscanf(const wchar_t * , const wchar_t * , ...);
wint_t ungetwc(wint_t, FILE *);
int vfwprintf(FILE * , const wchar_t * , va_list);
int vswprintf(wchar_t * , size_t, const wchar_t * , va_list);
int vwprintf(const wchar_t * , va_list);
size_t wcrtomb(char * , wchar_t, mbstate_t * );
wchar_t *wcscat(wchar_t * , const wchar_t * );
wchar_t *wcschr(const wchar_t *, wchar_t);
int wcscmp(const wchar_t *, const wchar_t *);
int wcscoll(const wchar_t *, const wchar_t *);
wchar_t *wcscpy(wchar_t * , const wchar_t * );
size_t wcscspn(const wchar_t *, const wchar_t *);
size_t wcsftime(wchar_t * , size_t, const wchar_t * , const struct tm * );
wchar_t *wcsncat(wchar_t * , const wchar_t * , size_t);
int wcsncmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wcsncpy(wchar_t * , const wchar_t * , size_t);
wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
wchar_t *wcsrchr(const wchar_t *, wchar_t);
size_t wcsrtombs(char * , const wchar_t ** , size_t, mbstate_t * );
size_t wcsspn(const wchar_t *, const wchar_t *);
wchar_t *wcsstr(const wchar_t *, const wchar_t *);
size_t wcsxfrm(wchar_t * , const wchar_t * , size_t);
int wctob(wint_t);
double wcstod(const wchar_t * , wchar_t ** );
wchar_t *wcstok(wchar_t * , const wchar_t * , wchar_t ** );
long wcstol(const wchar_t * , wchar_t ** , int);
unsigned long wcstoul(const wchar_t * , wchar_t ** , int);
wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
int wmemcmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wmemcpy(wchar_t * , const wchar_t * , size_t);
wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
#if __BSD_VISIBLE
/*wchar_t *wmempcpy(wchar_t * __restrict, const wchar_t * __restrict, size_t);*/
#endif
wchar_t *wmemset(wchar_t *, wchar_t, size_t);
int wprintf(const wchar_t * , ...);
int wscanf(const wchar_t * , ...);

#undef getwc
#define getwc(f)	fgetwc(f);

#undef getwchar
#define getwchar()	getwc(stdin)

#undef putwc
#define putwc(c, f)	fputwc(c, f)

#undef putwchar
#define putwchar(c)	putwc(c, stdout)

#if __ISO_C_VISIBLE >= 1999
int vfwscanf(FILE * , const wchar_t * , va_list);
int vswscanf(const wchar_t * , const wchar_t * , va_list);
int vwscanf(const wchar_t * , va_list);
float wcstof(const wchar_t * , wchar_t ** );
long double wcstold(const wchar_t * , wchar_t ** );
long long wcstoll(const wchar_t * , wchar_t ** , int);
unsigned long long wcstoull(const wchar_t * , wchar_t ** , int);
#endif /* __ISO_C_VISIBLE >= 1999 */

#if 0 /* not yet implemented __XSI_VISIBLE */
int wcswidth(const wchar_t *, size_t);
int wcwidth(wchar_t);
#endif

#if 0 /* not yet implemented __POSIX_VISIBLE >= 200809 */
size_t mbsnrtowcs(wchar_t * __restrict, const char ** __restrict, size_t, size_t, mbstate_t * __restrict);
FILE *open_wmemstream(wchar_t **, size_t *);
wchar_t *wcpcpy(wchar_t * __restrict, const wchar_t * __restrict);
wchar_t *wcpncpy(wchar_t * __restrict, const wchar_t * __restrict, size_t);
wchar_t *wcsdup(const wchar_t *) __malloc_like;
int wcscasecmp(const wchar_t *, const wchar_t *);
int wcsncasecmp(const wchar_t *, const wchar_t *, size_t n);
size_t wcsnlen(const wchar_t *, size_t) __pure;
size_t wcsnrtombs(char * __restrict, const wchar_t ** __restrict, size_t, size_t, mbstate_t * __restrict);
#endif

__END_DECLS

//#define btowc(c)	({ int __c = (c); __c & ~0x7f ? WEOF : (wint_t)__c; })
//#define wctob(c)	({ int __c = (c); __c & ~0x7f ? EOF : (int)__c; })

//#define mbsinit(p)	1
//#define mbrlen(s, n)	mbrtowc(_NULL, s, n, _NULL)

#endif /*_WCHAR_H_ */
