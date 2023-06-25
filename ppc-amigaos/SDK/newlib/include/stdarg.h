#if defined(__GNUC__)
#include_next <stdarg.h>

/****************************************************************************/

/* Define the AmigaOS specific varargs macros,
   if GCC's <stdarg.h> didn't already define them.   */

#ifndef va_startlinear
   #define va_startlinear(AP,ARG) va_start(AP,ARG)
#endif

#ifndef va_getlinearva
   #define va_getlinearva(AP,TYPE) ((TYPE)__builtin_getlinearva(AP))
#endif

/****************************************************************************/
#elif defined(__VBCC__) 

/* stdarg.h - AmigaOS4/newlib-special */

#ifndef __STDARG_H
#define __STDARG_H 1

typedef struct {
  unsigned char gpr;
  unsigned char fpr;
  char *membase;
  char *regbase;
} va_list[1];

char *__va_start(void);
char *__va_regbase(void);
int __va_fixedgpr(void);
int __va_fixedfpr(void);

#define va_start(vl,dummy) \
  ( \
    vl->gpr=__va_fixedgpr(), \
    vl->fpr=__va_fixedfpr(), \
    vl->regbase=__va_regbase(), \
    vl->membase=__va_start() \
  )

#define va_end(vl) ((vl)->regbase=(vl)->membase=0)

#define va_copy(new,old) (*(new)=*(old))

#define __va_align(type) (__alignof(type)>=4?__alignof(type):4)

#define __va_do_align(vl,type) ((vl)->membase=(char *)((((unsigned int)((vl)->membase))+__va_align(type)-1)/__va_align(type)*__va_align(type)))

#define __va_mem(vl,type) (__va_do_align((vl),type),(vl)->membase+=sizeof(type),((type*)((vl)->membase))[-1])

#define va_arg(vl,type) \
 ( \
  (__typeof(type)&127)>10? \
    __va_mem((vl),type) \
  : \
   ( \
    (((__typeof(type)&127)>=6&&(__typeof(type)&127)<=8)) ? \
     ( \
      ++(vl)->fpr<=8 ? \
        ((type*)((vl)->regbase+32))[(vl)->fpr-1] \
      : \
        __va_mem((vl),type) \
     ) \
    : \
     ( \
      (__typeof(type)&127)==5? \
       ( \
        (vl)->gpr<=6 ? \
         ((vl)->gpr=(((vl)->gpr+3)&~1),((type*)((vl)->regbase+0))[((vl)->gpr>>1)-1]) \
	: \
	 __va_mem((vl),type) \
	 ) \
       : \
       ( \
	++(vl)->gpr<=8 ? \
	 ((type*)((vl)->regbase+0))[(vl)->gpr-1] \
	 : \
	 __va_mem((vl),type) \
	 ) \
       ) \
     ) \
   )


/* OS4 linear varargs support */

#define va_startlinear(vl,lastarg) ((vl)->membase=__va_start())

#define va_getlinearva(vl,type) ((type)(vl)->membase)

#endif

#else
#error Compiler not supported
#endif 
