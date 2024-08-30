#ifndef EXEC_TYPES_H
#define EXEC_TYPES_H
/*
**    $VER: types.h 53.29 (10.8.2015)
**
**    Data typing.  Must be included before any other Amiga include.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   AMIGA_COMPILER_H
#include <amiga_compiler.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#define INCLUDE_VERSION 51  /* Version of the include files in use. (Do not
                               use this label for OpenLibrary() calls!) */

/****************************************************************************/

#define GLOBAL   extern   /* the declaratory use of an external */
#define IMPORT   extern   /* reference to an external */
#define STATIC   static   /* a local static variable */
#define REGISTER register /* a (hopefully) register variable */

/****************************************************************************/

#ifndef VOID
#define VOID void
#endif

/****************************************************************************/

/* General const support */
#ifndef CONST
#define CONST const
#endif

/****************************************************************************/

#ifndef VOLATILE
#define VOLATILE volatile
#endif

/****************************************************************************/

  /*  WARNING: APTR was redefined for the V36 Includes!  APTR is a   */
 /*  32-Bit Absolute Memory Pointer.  C pointer math will not       */
/*  operate on APTR --  use "ULONG *" instead.                     */
#ifndef APTR_TYPEDEF
#define APTR_TYPEDEF
typedef void * APTR; /* 32-bit untyped pointer */
#endif

/****************************************************************************/

#ifdef OLD_TYPEDEFS

typedef long            LONG;     /* signed 32-bit quantity */
typedef unsigned long   ULONG;    /* unsigned 32-bit quantity */
typedef unsigned long   LONGBITS; /* 32 bits manipulated individually */
typedef short           WORD;     /* signed 16-bit quantity */
typedef unsigned short  UWORD;    /* unsigned 16-bit quantity */
typedef unsigned short  WORDBITS; /* 16 bits manipulated individually */
typedef signed char     BYTE;     /* signed 8-bit quantity */
typedef unsigned char   UBYTE;    /* unsigned 8-bit quantity */
typedef unsigned char   BYTEBITS; /* 8 bits manipulated individually */
typedef unsigned short  RPTR;     /* signed relative pointer */

#else

/* Whenever possible, use these typesdefs instead of the traditional
 * BYTE/WORD/LONG. These are absolutely unambigious when it comes to
 * datatype and number of bits
 */

typedef unsigned char uint8;
typedef   signed char  int8;

typedef unsigned short uint16;
typedef   signed short  int16;

typedef unsigned long uint32;
typedef   signed long  int32;

#if !defined(__SASC) && ((__GNUC__ >= 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 95)) || defined(__VBCC__))
typedef unsigned long long uint64;
typedef   signed long long  int64;
#else
typedef struct { unsigned long hi,lo; } uint64; /* Not exactly scalar data
                                                 * types, but the right size.
                                                 */
typedef struct { long hi,lo; }           int64;
#endif

typedef uint8  UBYTE;
typedef  int8   BYTE;
typedef uint8   BYTEBITS;
typedef uint16 UWORD;
typedef  int16  WORD;
typedef uint16  WORDBITS;
typedef uint32 ULONG;
typedef  int32  LONG;
typedef uint32  LONGBITS;
typedef uint16  RPTR;

#endif /* OLD_TYPEDEFS */

/****************************************************************************/

/* Pointer to TEXT which has non-negative characters */

#if (defined(__GNUC__) && defined(__CHAR_UNSIGNED__)) || (defined(__SASC) && defined(_UNSCHAR))
typedef          char * STRPTR; /* string pointer (NULL terminated) */
#else
typedef unsigned char * STRPTR; /* string pointer (NULL terminated) */
#endif

/****************************************************************************/

/* const support for pointer types */
/*
 *             APTR is a non-constant pointer to non-constant data
 *       CONST APTR is a     constant pointer to non-constant data
 *       CONST_APTR is a non-constant pointer to     constant data
 * CONST CONST_APTR is a     constant pointer to     constant data
 */
typedef CONST void * CONST_APTR; /* 32-bit untyped pointer to const data */

/*
 *             STRPTR is a non-constant pointer to non-constant TEXT 
 *       CONST STRPTR is a     constant pointer to non-constant TEXT
 *       CONST_STRPTR is a non-constant pointer to     constant TEXT
 * CONST CONST_STRPTR is a     constant pointer to     constant TEXT
 */
#if (defined(__GNUC__) && defined(__CHAR_UNSIGNED__)) || (defined(__SASC) && defined(_UNSCHAR))
typedef CONST          char * CONST_STRPTR; /* STRPTR to const TEXT */
#else
typedef CONST unsigned char * CONST_STRPTR; /* STRPTR to const TEXT */
#endif

/****************************************************************************/

/* For compatibility only: (don't use in new code) */
typedef short           SHORT;  /* signed 16-bit quantity (use WORD) */
typedef unsigned short  USHORT; /* unsigned 16-bit quantity (use UWORD) */
typedef short           COUNT;
typedef unsigned short  UCOUNT;
typedef ULONG           CPTR;

/****************************************************************************/

/* Types with specific semantics */

/****************************************************************************/

#ifdef OLD_TYPEDEFS

typedef float   FLOAT;
typedef double  DOUBLE;

#else

typedef float  float32;
typedef double float64;

#ifndef NO_OLD_TYPE_DEFINES
#define FLOAT  float32
#define DOUBLE float64
#endif /* NO_OLD_TYPE_DEFINES */

#endif /* OLD_TYPEDEFS */

/****************************************************************************/

typedef short BOOL;

#if (defined(__GNUC__) && defined(__CHAR_UNSIGNED__)) || (defined(__SASC) && defined(_UNSCHAR))
typedef          char TEXT; /* Non-negative character */
#else
typedef unsigned char TEXT; /* Non-negative character */
#endif

/****************************************************************************/

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/****************************************************************************/

#ifdef __cplusplus
#define NULL 0L
#else
#ifndef NULL
#define NULL ((void *)0L)
#endif
#endif /* __cplusplus */

/****************************************************************************/

#define BYTEMASK 0xFF

/****************************************************************************/

/* #define LIBRARY_VERSION is now obsolete.  Please use LIBRARY_MINIMUM */
/* or code the specific minimum library version you require.            */
#define LIBRARY_MINIMUM 50 /* Lowest version still supported */

/****************************************************************************/

/* Some structure definitions include prototypes for function pointers.
 * This may not work with `C' compilers that do not comply to the ANSI
 * standard, which we will have to work around.
 */
#define __CLIB_PROTOTYPE(a) a

/****************************************************************************/

/* Helper macros to define an AmigaOS type in a public header file without
 * the need to distinguish between defined and undefined namespace
 */
#if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
#define AMIGAOS_TYPE(x) AmigaOS::x
#define AMIGAOS_STRUCT(x) AmigaOS::x
#else
#define AMIGAOS_TYPE(x) x
#define AMIGAOS_STRUCT(x) struct x
#endif

/****************************************************************************/

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_TYPES_H */
