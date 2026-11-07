/*
 * SPDX-FileCopyrightText: 2026 Dimitris Panokostas
 * SPDX-License-Identifier: LicenseRef-Hyperion-MiniGL
 *
 * Declarations derive from the MiniGL V30 SDK headers, (C) 1999 Hyperion,
 * (C) 2025-2026 Dennis van der Boon: the ABI-sized GL types, the MiniGL
 * types and the MiniGL-specific numeric values the Amiberry guest adapter
 * needs. Keep every value identical to the SDK headers. Standard OpenGL, GLU
 * and GLUT token values come from the Khronos registry, Mesa GLU and freeglut
 * through the three headers included below.
 */
#ifndef LIBRARIES_MINIGL_ABI_TYPES_H
#define LIBRARIES_MINIGL_ABI_TYPES_H

#include <exec/types.h>
#include <libraries/minigl_gl_tokens.h>
#include <libraries/minigl_glu_tokens.h>
#include <libraries/minigl_glut_tokens.h>

struct Window;
struct BitMap;
struct GLcontext_t;
typedef struct GLcontext_t *GLcontext;

/* GL types, as mgl/gl.h declares them (m68k: pointers/longs 32-bit). */
typedef void GLvoid;
typedef char GLbyte;
typedef unsigned char GLubyte;
typedef short GLshort;
typedef unsigned short GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef unsigned int GLboolean;
typedef long GLsizei;
typedef long GLintptr;
typedef long GLsizeiptr;
typedef long GLintptrARB;
typedef long GLsizeiptrARB;
typedef unsigned long GLbitfield;
typedef unsigned int GLenum;
typedef float GLfloat;
typedef double GLdouble;
typedef float GLclampf;
typedef double GLclampd;

/* mgl/context.h: GLUT-shim special keys and the input callbacks. */
typedef enum {
    MGLKEY_F1, MGLKEY_F2, MGLKEY_F3, MGLKEY_F4,
    MGLKEY_F5, MGLKEY_F6, MGLKEY_F7, MGLKEY_F8,
    MGLKEY_F9, MGLKEY_F10, MGLKEY_CUP, MGLKEY_CDOWN,
    MGLKEY_CLEFT, MGLKEY_CRIGHT
} MGLspecial;
typedef void (*KeyHandlerFn)(char key);
typedef void (*SpecialHandlerFn)(MGLspecial special_key);
typedef void (*MouseHandlerFn)(GLint x, GLint y, GLbitfield buttons);
typedef void (*IdleFn)(void);

/* mgl/modes.h: screen-mode query and locked-buffer layout. */

#define MGL_MAX_MODE               80

typedef struct {
    GLint id;
    GLint width, height;
    GLint bit_depth;
    char mode_name[MGL_MAX_MODE];
} MGLScreenMode;
typedef struct {
    ULONG width, height, depth;
    ULONG pixel_format;
    void *base_address;
    ULONG pitch;
} MGLLockInfo;
typedef GLboolean (*MGLScreenModeCallback)(MGLScreenMode *);

/* mgl/gl.h: the GLU quadric object and gluQuadricCallback's fn type. */
typedef struct GLUquadricObj_t GLUquadricObj;
typedef GLUquadricObj GLUquadric;
typedef void (*MGLUfuncptr)();

/*
 * MiniGL-specific numeric values, in v29 SDK order (mgl/gl.h, then
 * mgl/modes.h, mgl/context.h, libraries/minigl_dispatch.h). #defines, not an
 * enum, like the standard tokens: values may legitimately coincide.
 */
#define MAX_TEXUNIT                    2
#define GL_BASE                        0x7000
#define GL_POLYGON_OFFSET              0x7001
#define GL_TEXTURE_2D_BINDING          0x8069
#define GL_TEXTURE_DOOR_ARRAY_POINTER  0x8092
#define MGL_LOCK_AUTOMATIC             0x7010
#define MGL_LOCK_MANUAL                0x7011
#define MGL_LOCK_SMART                 0x7012
#define MGL_PERSPECTIVE_MAPPING        0x7015
#define MGL_W_ONE_HINT                 0x7016
#define MGL_Z_OFFSET                   0x7017
#define MGL_UBYTE_BGRA                 0x7018
#define MGL_UBYTE_ARGB                 0x7019
#define MGL_UNSIGNED_SHORT_5_6_5       0x701A
#define MGL_UNSIGNED_SHORT_4_4_4_4     0x701B
#define MGL_FIXPOINTTRANS_HINT         0x701C
#define MGL_ARRAY_TRANSFORMATIONS      0x701D
#define MGL_BUTTON_LEFT                0x00000001
#define MGL_BUTTON_RIGHT               0x00000002
#define MGL_BUTTON_MID                 0x00000004
#define MGL_SM_BESTMODE                0xFFFFFFFF
#define MGL_SM_WINDOWMODE              0x00000000
#define GLROT_001                      0x800
#define GLROT_010                      0x1000
#define GLROT_100                      0x2000
#define GLROT_011                      0x4000
#define GLROT_101                      0x8000
#define GLROT_110                      0x10000
#define GLROT_111                      0x20000
#define MGL_ZBUFFER_32F                32
#define MGL_ZBUFFER_16                 16
#define MGL_MAX_LIGHTS                 8
#define MGL_MAX_TEXTURE_SIZE           4096

#endif
