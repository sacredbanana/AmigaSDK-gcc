#ifndef _CTYPE_H_
#define _CTYPE_H_

#include "_ansi.h"

_BEGIN_STD_C

int isalnum (int __c);
int isalpha (int __c);
int iscntrl (int __c);
int isdigit (int __c);
int isgraph (int __c);
int islower (int __c);
int isprint (int __c);
int ispunct (int __c);
int isspace (int __c);
int isupper (int __c);
int isxdigit (int __c);
int tolower (int __c);
int toupper (int __c);

#if !defined(__STRICT_ANSI__) || __ISO_C_VISIBLE >= 1999
int isblank (int __c);
#endif

int isascii (int __c);
int toascii (int __c);
int _tolower (int __c);
int _toupper (int __c);

#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
#define	_B	0200

extern	__IMPORT const char	*__ctype_ptr;
extern	__IMPORT const char	_ctype_[];  /* For backward compatibility.  */

#ifndef __cplusplus
#define	isalpha(c)	((__ctype_ptr)[(unsigned)(c)]&(_U|_L))
#define	isupper(c)	((__ctype_ptr)[(unsigned)(c)]&_U)
#define	islower(c)	((__ctype_ptr)[(unsigned)(c)]&_L)
#define	isdigit(c)	((__ctype_ptr)[(unsigned)(c)]&_N)
#define	isxdigit(c)	((__ctype_ptr)[(unsigned)(c)]&(_X|_N))
#define	isspace(c)	((__ctype_ptr)[(unsigned)(c)]&_S)
#define ispunct(c)	((__ctype_ptr)[(unsigned)(c)]&_P)
#define isalnum(c)	((__ctype_ptr)[(unsigned)(c)]&(_U|_L|_N))
#define isprint(c)	((__ctype_ptr)[(unsigned)(c)]&(_P|_U|_L|_N|_B))
#define	isgraph(c)	((__ctype_ptr)[(unsigned)(c)]&(_P|_U|_L|_N))
#define iscntrl(c)	((__ctype_ptr)[(unsigned)(c)]&_C)


/* Non-gcc versions will get the library versions, and will be
   slightly slower */
#ifdef __GNUC__
# define toupper(c) \
	__extension__ ({ int __x = (c); islower(__x) ? (__x - 'a' + 'A') : __x;})
# define tolower(c) \
	__extension__ ({ int __x = (c); isupper(__x) ? (__x - 'A' + 'a') : __x;})

#elif defined(__VBCC__)
int __asm_toupper(__reg("r3") int) =
        "\t.extern\t_ctype_\n"
        "\tlis\t11,(_ctype_+1)@ha\n"
        "\taddi\t11,11,(_ctype_+1)@l\n"
        "\tlbzx\t12,11,3\n"
        "\tandi.\t12,12,2\n"
        "\tbeq\t$+8\n"
        "\tsubi\t3,3,0x20\n"
        "#barrier";
int __asm_tolower(__reg("r3") int) =
        "\t.extern\t_ctype_\n"
        "\tlis\t11,(_ctype_+1)@ha\n"
        "\taddi\t11,11,(_ctype_+1)@l\n"
        "\tlbzx\t12,11,3\n"
        "\tandi.\t12,12,1\n"
        "\tbeq\t$+8\n"
        "\taddi\t3,3,0x20\n"
        "#barrier";
#define toupper(c) __asm_toupper(c)
#define tolower(c) __asm_tolower(c)
#endif
#endif /* !__cplusplus */

#ifndef __STRICT_ANSI__
#define isascii(c)	((unsigned)(c)<=0177)
#define toascii(c)	((c)&0177)
#endif

_END_STD_C

#endif /* _CTYPE_H_ */
