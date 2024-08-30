#ifndef _SETJMP_H
#define _SETJMP_H

#ifdef __ixemul__
#error "including non-ixemul setjmp.h header from ixemul app"
#endif

#include <sys/cdefs.h>

#define _JBLEN 111 /* r1,r13-r31,cr,lr,f14-f31,r2,vrsave,v20-v31,12bytepad */

typedef int jmp_buf[_JBLEN] __attribute__((aligned(16)));
typedef int sigjmp_buf[_JBLEN+2] __attribute__((aligned(16)));
typedef int jmp_buf59[59] __attribute__((aligned(8)));

__BEGIN_DECLS

int setjmp(jmp_buf);
void longjmp(jmp_buf, int) __dead2;
int setjmp59(jmp_buf59);
void longjmp59(jmp_buf59, int) __dead2;

int sigsetjmp(sigjmp_buf, int);
void siglongjmp(sigjmp_buf, int) __dead2;

__END_DECLS

#endif

