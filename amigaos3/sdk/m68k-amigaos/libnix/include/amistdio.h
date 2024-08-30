#ifndef __AMISTDIO_H__
#define __AMISTDIO_H__

#define _STDIO_H

#include <stdarg.h>

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef PROTO_DOS_H
#include <proto/dos.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define puts(a) amiputs(a)
#define gets(a,b) amigets(a, b)
#define fputs(a,f) FPuts(f, a)
#define fgets(a,l,f) FGets(f, a, l)
#define putchar amiputchar
#define fread(a,b,c,d) Read(d, a, b * c)
#define fwrite(a,b,c,d) Write(d, a, b * c)
#define printf(...) amiprintf(__VA_ARGS__)
#define fprintf(...) amifprintf(__VA_ARGS__)
#define vfprintf(...) amivfprintf(__VA_ARGS__)
#define snprintf(...) amisnprintf(__VA_ARGS__)
#define vsnprintf(...) amivsnprintf(__VA_ARGS__)
#define stdin Input()
#define stdout Output()
#define stderr amistderr()
#define fflush(f) Flush(f)

extern __stdargs int amiputs(char const * s);
extern __stdargs int amigets(char * s, unsigned sz);
extern __stdargs int amiprintf(char const * ftm,...);
extern __stdargs int amifprintf(BPTR f, char const * ftm,...);
extern __stdargs int amivfprintf(BPTR f, const char *fmt, va_list args);
extern __stdargs void amiputchar(char c);
extern __stdargs BPTR amistderr();
extern __stdargs int amivsnprintf(char * buffer, int sz, const char *fmt, va_list args);
extern __stdargs int amisnprintf(char * buffer, int sz, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // __AMISTDIO_H__
