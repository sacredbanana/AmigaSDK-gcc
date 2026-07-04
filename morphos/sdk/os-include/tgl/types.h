#ifndef TGL_TYPES_H
#define TGL_TYPES_H

#include <stddef.h>

struct _GLContext;
typedef struct _GLContext GLContext;

typedef unsigned int       GLenum;
typedef void               GLvoid;
typedef unsigned char      GLboolean;
typedef signed char        GLbyte;       /* 1-byte signed */
typedef char               GLchar;       /* 1-byte char */
typedef char               GLcharARB;    /* 1-byte char */
typedef short              GLshort;      /* 2-byte signed */
typedef int                GLint;        /* 4-byte signed */
typedef unsigned char      GLubyte;      /* 1-byte unsigned */
typedef unsigned short     GLushort;     /* 2-byte unsigned */
typedef unsigned int       GLuint;       /* 4-byte unsigned */
typedef unsigned long long int GLuint64; /* 8-byte unsigned */
typedef unsigned long long int GLuint64EXT; /* 8-byte unsigned */
typedef float              GLfloat;      /* single precision float */
typedef double             GLdouble;     /* double precision float */
typedef float              GLclampf;
typedef double             GLclampd;
typedef int                GLsizei;
typedef unsigned int       GLbitfield;
typedef unsigned short     GLhalfARB;
typedef long int           GLintptr;
typedef long int           GLsizeiptr;
typedef long int           GLintptrARB;
typedef long int           GLsizeiptrARB;
typedef GLuint64           GLbitfield64;
typedef unsigned int       GLhandleARB;
typedef unsigned short     GLhalfNV;

#endif /* TGL_TYPES_H */
