#ifndef _WCHAR_H_
#define _WCHAR_H_

#include <stddef.h>

#ifndef _STDIO_H_
#include <stdio.h>
#endif

#ifndef _STDINT_H_
#include <stdint.h>
#endif

#include <sys/cdefs.h>

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

__BEGIN_DECLS

struct tm;

int fwprintf(FILE * , const wchar_t * , ...);
int fwscanf(FILE * , const wchar_t * , ...);

int swprintf(wchar_t * , size_t, const wchar_t * , ...);
int swscanf(const wchar_t * , const wchar_t * , ...);

int vfwprintf(FILE * , const wchar_t * , va_list);
int vfwscanf(FILE * , const wchar_t * , va_list);

int vswprintf(wchar_t * , size_t, const wchar_t * , va_list);
int vswscanf(const wchar_t * , const wchar_t * , va_list);

int vwprintf(const wchar_t * , va_list);
int vwscanf(const wchar_t * , va_list);

int wprintf(const wchar_t * , ...);
int wscanf(const wchar_t * , ...);

wint_t fgetwc(FILE *);
wchar_t *fgetws(wchar_t * , int, FILE * );
wint_t fputwc(wchar_t, FILE *);
int fputws(const wchar_t * , FILE * );

int fwide(FILE *, int);

wint_t __swbufw(wchar_t, FILE *);
wint_t __srgetw(FILE *);

wint_t getwc(FILE *);
wint_t getwchar(void);
wint_t putwc(wchar_t, FILE *);
wint_t putwchar(wchar_t);
wint_t ungetwc(wint_t, FILE *);

#undef getwc
#define getwc(f)	fgetwc(f);

#undef getwchar
#define getwchar()	getwc(stdin)

#undef putwc
#define putwc(c, f)	fputwc(c, f)

#undef putwchar
#define putwchar(c)	putwc(c, stdout)

float wcstof(const wchar_t * , wchar_t ** );
double wcstod(const wchar_t * , wchar_t ** );
long double wcstold(const wchar_t * , wchar_t ** );

long wcstol(const wchar_t * , wchar_t ** , int);
long long wcstoll(const wchar_t * , wchar_t ** , int);
unsigned long wcstoul(const wchar_t * , wchar_t ** , int);
unsigned long long wcstoull(const wchar_t * , wchar_t ** , int);

wchar_t *wcscpy(wchar_t * , const wchar_t * );
wchar_t *wcsncpy(wchar_t * , const wchar_t * , size_t);
wchar_t *wmemcpy(wchar_t * , const wchar_t * , size_t);
wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
wchar_t *wcscat(wchar_t * , const wchar_t * );
wchar_t *wcsncat(wchar_t * , const wchar_t * , size_t);
int wcscmp(const wchar_t *, const wchar_t *);
int wcscoll(const wchar_t *, const wchar_t *);
int wcsncmp(const wchar_t *, const wchar_t *, size_t);
size_t wcsxfrm(wchar_t * , const wchar_t * , size_t);
int wmemcmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wcschr(const wchar_t *, wchar_t);
size_t wcscspn(const wchar_t *, const wchar_t *);
wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
wchar_t *wcsrchr(const wchar_t *, wchar_t);
size_t wcsspn(const wchar_t *, const wchar_t *);
wchar_t *wcsstr(const wchar_t *, const wchar_t *);
wchar_t *wcstok(wchar_t * , const wchar_t * , wchar_t ** );
wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
size_t wcslen(const wchar_t *);
wchar_t *wmemset(wchar_t *, wchar_t, size_t);
size_t wcsftime(wchar_t * , size_t, const wchar_t * , const struct tm * );

wint_t btowc(int);
int wctob(wint_t);

int mbsinit(const mbstate_t *);
size_t mbrlen(const char * , size_t, mbstate_t * );
size_t mbrtowc(wchar_t * , const char * , size_t, mbstate_t * );
size_t wcrtomb(char * , wchar_t, mbstate_t * );
size_t mbsrtowcs(wchar_t * , const char ** , size_t, mbstate_t * );
size_t wcsrtombs(char * , const wchar_t ** , size_t, mbstate_t * );

__END_DECLS

//#define btowc(c)	({ int __c = (c); __c & ~0x7f ? WEOF : (wint_t)__c; })
//#define wctob(c)	({ int __c = (c); __c & ~0x7f ? EOF : (int)__c; })

//#define mbsinit(p)	1
//#define mbrlen(s, n)	mbrtowc(_NULL, s, n, _NULL)

#endif /*_WCHAR_H_ */
