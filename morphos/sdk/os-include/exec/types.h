#ifndef EXEC_TYPES_H
#define EXEC_TYPES_H

/*
	exec type definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#define INCLUDE_VERSION  50

#define GLOBAL      extern
#define IMPORT      extern
#define STATIC      static
#define REGISTER    register

#ifndef VOID
#define VOID        void
#endif

#ifndef CONST
#if __STDC__
#define CONST       const
#else
#define CONST
#endif
#endif

#ifndef VOLATILE
#if __STDC__
#define VOLATILE    volatile
#else
#define VOLATILE
#endif
#endif


#ifndef APTR_TYPEDEF
#define APTR_TYPEDEF
typedef void        *APTR;
#endif
typedef CONST void  *CONST_APTR;


#ifndef LONG_TYPEDEF
#define LONG_TYPEDEF
typedef long            LONG;
#endif

#ifndef ULONG_TYPEDEF
#define ULONG_TYPEDEF
typedef unsigned long   ULONG;
#endif

#ifndef LONGBITS_TYPEDEF
#define LONGBITS_TYPEDEF
typedef unsigned long   LONGBITS;
#endif

#ifndef WORD_TYPEDEF
#define WORD_TYPEDEF
typedef short           WORD;
#endif

#ifndef UWORD_TYPEDEF
#define UWORD_TYPEDEF
typedef unsigned short  UWORD;
#endif

#ifndef WORDBITS_TYPEDEF
#define WORDBITS_TYPEDEF
typedef unsigned short  WORDBITS;
#endif

#ifndef QUAD_TYPEDEF
#define QUAD_TYPEDEF
typedef signed long long   QUAD;
#endif

#ifndef UQUAD_TYPEDEF
#define UQUAD_TYPEDEF
typedef unsigned long long UQUAD;
#endif

#ifndef BYTE_TYPEDEF
#define BYTE_TYPEDEF
#if __STDC__
typedef signed char BYTE;
#else
typedef char        BYTE;
#endif
#endif

#ifndef UBYTE_TYPEDEF
#define UBYTE_TYPEDEF
typedef unsigned char   UBYTE;
#endif

#ifndef BYTEBITS_TYPEDEF
#define BYTEBITS_TYPEDEF
typedef unsigned char   BYTEBITS;
#endif

#ifndef RPTR_TYPEDEF
#define RPTR_TYPEDEF
typedef unsigned short  RPTR;
#endif

#ifndef STRPTR_TYPEDEF
#define STRPTR_TYPEDEF
#ifdef __cplusplus
typedef char        *STRPTR;
typedef CONST char  *CONST_STRPTR;
#else
#if defined(__GNUC__) && __GNUC__ >= 4
typedef char        *STRPTR;
typedef CONST char  *CONST_STRPTR;
#else
typedef unsigned char       *STRPTR;
typedef CONST unsigned char *CONST_STRPTR;
#endif
#endif
#endif

#ifndef WSTRPTR_TYPEDEF
#define WSTRPTR_TYPEDEF
typedef int *WSTRPTR;
typedef CONST int *CONST_WSTRPTR;
#endif

#ifndef SHORT_TYPEDEF
#define SHORT_TYPEDEF
typedef short           SHORT;
#endif

#ifndef USHORT_TYPEDEF
#define USHORT_TYPEDEF
typedef unsigned short  USHORT;
#endif

#ifndef COUNT_TYPEDEF
#define COUNT_TYPEDEF
typedef short           COUNT;
#endif

#ifndef UCOUNT_TYPEDEF
#define UCOUNT_TYPEDEF
typedef unsigned short  UCOUNT;
#endif

#ifndef CPTR_TYPEDEF
#define CPTR_TYPEDEF
typedef ULONG           CPTR;
#endif

#ifndef FLOAT_TYPEDEF
#define FLOAT_TYPEDEF
typedef float           FLOAT;
#endif

#ifndef DOUBLE_TYPEDEF
#define DOUBLE_TYPEDEF
typedef double          DOUBLE;
#endif

#ifndef BOOL_TYPEDEF
#define BOOL_TYPEDEF
typedef short           BOOL;
#endif

#ifndef TEXT_TYPEDEF
#define TEXT_TYPEDEF
typedef unsigned char   TEXT;
#endif

#ifndef WCHAR_TYPEDEF
#define WCHAR_TYPEDEF
typedef int             WCHAR;
#endif

#if defined(__VEC__)
/*
 * Vectors
 */
#if (((__GNUC__ >= 3) && (__GNUC__ < 5)) || defined(__STRICT_ANSI__)) && !defined(vector)
#define vector __vector
#define _vector_workaround_defined
#endif

#ifndef VECTOR_ULONG_TYPEDEF
#define VECTOR_ULONG_TYPEDEF
typedef vector unsigned int VECTOR_ULONG;
#endif

#ifndef VECTOR_LONG_TYPEDEF
#define VECTOR_LONG_TYPEDEF
typedef vector signed int VECTOR_LONG;
#endif

#ifndef VECTOR_UWORD_TYPEDEF
#define VECTOR_UWORD_TYPEDEF
typedef vector unsigned short VECTOR_UWORD;
#endif

#ifndef VECTOR_WORD_TYPEDEF
#define VECTOR_WORD_TYPEDEF
typedef vector signed short VECTOR_WORD;
#endif

#ifndef VECTOR_UBYTE_TYPEDEF
#define VECTOR_UBYTE_TYPEDEF
typedef vector unsigned char VECTOR_UBYTE;
#endif

#ifndef VECTOR_BYTE_TYPEDEF
#define VECTOR_BYTE_TYPEDEF
typedef vector signed char VECTOR_BYTE;
#endif

#ifndef VECTOR_FLOAT_TYPEDEF
#define VECTOR_FLOAT_TYPEDEF
typedef vector float VECTOR_FLOAT;
#endif

#if (((__GNUC__ >= 3) && (__GNUC__ < 5)) || defined(__STRICT_ANSI__)) && defined(_vector_workaround_defined)
#undef vector
#undef _vector_workaround_defined
#endif

#endif /* __VEC__ */

#ifndef TRUE
#define TRUE    1
#endif
#ifndef FALSE
#define FALSE   0
#endif
#ifndef NULL
#define NULL    0
#endif


/* Some AROS stuff */

typedef unsigned long  IPTR;
typedef long           SIPTR;

typedef IPTR           STACKIPTR;
typedef SIPTR          STACKSIPTR;
typedef LONG           STACKLONG;
typedef ULONG          STACKULONG;
typedef QUAD           STACKQUAD;
typedef UQUAD          STACKUQUAD;

typedef signed int     STACKWORD;
typedef unsigned int   STACKUWORD;
typedef signed int     STACKBYTE;
typedef unsigned int   STACKUBYTE;
typedef double         STACKFLOAT;


#define BYTEMASK  0xff


#define LIBRARY_MINIMUM  33

#if __STDC__
#define __CLIB_PROTOTYPE(a) a
#else
#define __CLIB_PROTOTYPE(a)
#endif

#endif
