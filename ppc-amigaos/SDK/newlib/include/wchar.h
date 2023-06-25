#ifndef _WCHAR_H_
#define _WCHAR_H_

#include <_ansi.h>

#include <sys/reent.h>

#define __need_size_t
#define __need_wchar_t
#define __need_wint_t
#include <stddef.h>

/* For _mbstate_t definition. */
#include <sys/_types.h>

/* typedef only __gnuc_va_list, used throughout the header */
#define __need___va_list
#include <stdarg.h>

#ifndef NULL
#define NULL	0
#endif

#ifndef WEOF
# define WEOF ((wint_t)-1)
#endif

#ifndef WCHAR_MIN
#define WCHAR_MIN 0
#endif

#ifndef WCHAR_MAX
#ifdef __WCHAR_MAX__
#define WCHAR_MAX __WCHAR_MAX__
#else
#define WCHAR_MAX 0x7fffffffu
#endif
#endif

_BEGIN_STD_C

/* As in stdio.h, <sys/reent.h> defines __FILE. */
#if !defined(__FILE_defined)
typedef __FILE FILE;
# define __FILE_defined
#endif

/* As required by POSIX.1-2008, declare tm as incomplete type.
   The actual definition is in time.h. */
struct tm;

#ifndef _MBSTATE_T
#define _MBSTATE_T
typedef _mbstate_t mbstate_t;
#endif /* _MBSTATE_T */

wint_t	btowc (int);
int	wctob (wint_t);
size_t	mbrlen (const char * , size_t, mbstate_t *);
size_t	mbrtowc (wchar_t * , const char * , size_t, mbstate_t *);
size_t	_mbrtowc_r (struct _reent *, wchar_t * , const char * , 
			size_t, mbstate_t *);
int	mbsinit (const mbstate_t *);
size_t	mbsrtowcs (wchar_t * , const char ** , size_t, mbstate_t *);
size_t	wcrtomb (char * , wchar_t, mbstate_t *);
size_t	_wcrtomb_r (struct _reent *, char * , wchar_t, mbstate_t *);
size_t	wcsrtombs (char * , const wchar_t ** , size_t, mbstate_t *);
size_t	_wcsrtombs_r (struct _reent *, char * , const wchar_t ** , 
			size_t, mbstate_t *);
wchar_t	*wcscat (wchar_t * , const wchar_t *);
wchar_t	*wcschr (const wchar_t *, wchar_t);
int	wcscmp (const wchar_t *, const wchar_t *);
int	wcscoll (const wchar_t *, const wchar_t *);
wchar_t	*wcscpy (wchar_t * , const wchar_t *);
size_t	wcscspn (const wchar_t *, const wchar_t *);
size_t  wcsftime (wchar_t *, size_t, const wchar_t *, const struct tm *);
size_t	wcslcat (wchar_t *, const wchar_t *, size_t);
size_t	wcslcpy (wchar_t *, const wchar_t *, size_t);
size_t	wcslen (const wchar_t *);
wchar_t	*wcsncat (wchar_t * , const wchar_t * , size_t);
int	wcsncmp (const wchar_t *, const wchar_t *, size_t);
wchar_t	*wcsncpy (wchar_t *  , const wchar_t * , size_t);
size_t	wcsnlen (const wchar_t *, size_t);
wchar_t	*wcspbrk (const wchar_t *, const wchar_t *);
wchar_t	*wcsrchr (const wchar_t *, wchar_t);
size_t	wcsspn (const wchar_t *, const wchar_t *);
wchar_t	*wcsstr (const wchar_t *, const wchar_t *);
wchar_t	*wcstok (wchar_t *, const wchar_t *, wchar_t **);
int	wcswidth (const wchar_t *, size_t);
size_t	wcsxfrm (wchar_t *, const wchar_t *, size_t);
int	wcwidth (const wchar_t);
wchar_t	*wmemchr (const wchar_t *, wchar_t, size_t);
int	wmemcmp (const wchar_t *, const wchar_t *, size_t);
wchar_t	*wmemcpy (wchar_t * , const wchar_t * , size_t);
wchar_t	*wmemmove (wchar_t *, const wchar_t *, size_t);
wchar_t	*wmemset (wchar_t *, wchar_t, size_t);

double wcstod (const wchar_t *, wchar_t **);
long    wcstol (const wchar_t *, wchar_t **, int);
unsigned long wcstoul (const wchar_t *, wchar_t **, int);
#if !defined(__STRICT_ANSI__) || __ISO_C_VISIBLE >= 1999
float wcstof (const wchar_t *__restrict, wchar_t **);
long long wcstoll (const wchar_t *, wchar_t **, int);
unsigned long long wcstoull (const wchar_t *, wchar_t **, int);
long double wcstold (const wchar_t *, wchar_t **);
#endif
float _wcstof_r (struct _reent *, const wchar_t *, wchar_t **);
double _wcstod_r (struct _reent *, const wchar_t *, wchar_t **);
long    _wcstol_r (struct _reent *, const wchar_t *, wchar_t **, int);
unsigned long _wcstoul_r (struct _reent *, const wchar_t *, wchar_t **, int);
long long _wcstoll_r (struct _reent *, const wchar_t *, wchar_t **, int);
unsigned long long _wcstoull_r (struct _reent *, const wchar_t *, wchar_t **, int);

wint_t fgetwc (__FILE *);
wchar_t *fgetws (wchar_t *, int, __FILE *);
wint_t fputwc (wchar_t, __FILE *);
int fputws (const wchar_t *, __FILE *);
int fwide (__FILE *, int);
wint_t getwc (__FILE *);
wint_t getwchar (void);
wint_t putwc (wchar_t, __FILE *);
wint_t putwchar (wchar_t);
wint_t ungetwc (wint_t wc, __FILE *);

wint_t _fgetwc_r (struct _reent *, __FILE *);
wint_t _fgetwc_unlocked_r (struct _reent *, __FILE *);
wchar_t *_fgetws_r (struct _reent *, wchar_t *, int, __FILE *);
wchar_t *_fgetws_unlocked_r (struct _reent *, wchar_t *, int, __FILE *);
wint_t _fputwc_r (struct _reent *, wchar_t, __FILE *);
wint_t _fputwc_unlocked_r (struct _reent *, wchar_t, __FILE *);
int _fputws_r (struct _reent *, const wchar_t *, __FILE *);
int _fputws_unlocked_r (struct _reent *, const wchar_t *, __FILE *);
int _fwide_r (struct _reent *, __FILE *, int);
wint_t _getwc_r (struct _reent *, __FILE *);
wint_t _getwc_unlocked_r (struct _reent *, __FILE *);
wint_t _getwchar_r (struct _reent *ptr);
wint_t _getwchar_unlocked_r (struct _reent *ptr);
wint_t _putwc_r (struct _reent *, wchar_t, __FILE *);
wint_t _putwc_unlocked_r (struct _reent *, wchar_t, __FILE *);
wint_t _putwchar_r (struct _reent *, wchar_t);
wint_t _putwchar_unlocked_r (struct _reent *, wchar_t);
wint_t _ungetwc_r (struct _reent *, wint_t wc, __FILE *);

#ifndef __VALIST
#ifdef __GNUC__
#define __VALIST __gnuc_va_list
#else
#define __VALIST char*
#endif
#endif

#if !defined(__STRICT_ANSI__) || __ISO_C_VISIBLE >= 1999
int	fwprintf (__FILE *, const wchar_t *, ...);
int	swprintf (wchar_t *, size_t, const wchar_t *, ...);
int	vfwprintf (__FILE *, const wchar_t *, __VALIST);
int	vswprintf (wchar_t *, size_t, const wchar_t *, __VALIST);
int	vwprintf (const wchar_t *, __VALIST);
int	wprintf (const wchar_t *, ...);
#endif

int	_fwprintf_r (struct _reent *, __FILE *, const wchar_t *, ...);
int	_swprintf_r (struct _reent *, wchar_t *, size_t, const wchar_t *, ...);
int	_vfwprintf_r (struct _reent *, __FILE *, const wchar_t *, __VALIST);
int	_vswprintf_r (struct _reent *, wchar_t *, size_t, const wchar_t *, __VALIST);
int	_vwprintf_r (struct _reent *, const wchar_t *, __VALIST);
int	_wprintf_r (struct _reent *, const wchar_t *, ...);

#if !defined(__STRICT_ANSI__) || __ISO_C_VISIBLE >= 1999
int	fwscanf (__FILE *, const wchar_t *, ...);
int	swscanf (const wchar_t *, const wchar_t *, ...);
int	vfwscanf (__FILE *, const wchar_t *, __VALIST);
int	vswscanf (const wchar_t *, const wchar_t *, __VALIST);
int	vwscanf (const wchar_t *, __VALIST);
int	wscanf (const wchar_t *, ...);
#endif

int	_fwscanf_r (struct _reent *, __FILE *, const wchar_t *, ...);
int	_swscanf_r (struct _reent *, const wchar_t *, const wchar_t *, ...);
int	_vfwscanf_r (struct _reent *, __FILE *, const wchar_t *, __VALIST);
int	_vswscanf_r (struct _reent *, const wchar_t *, const wchar_t *, __VALIST);
int	_vwscanf_r (struct _reent *, const wchar_t *, __VALIST);
int	_wscanf_r (struct _reent *, const wchar_t *, ...);

_END_STD_C

#endif /* _WCHAR_H_ */
