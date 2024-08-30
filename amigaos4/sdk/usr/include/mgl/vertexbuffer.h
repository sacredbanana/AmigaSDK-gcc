/*
 * $Id: vertexbuffer.h 399 2009-11-30 03:01:40Z HansR $
 *
 * $Date: 2009-11-30 06:01:40 +0300 (Mon, 30 Nov 2009) $
 * $Revision: 399 $
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#ifndef __VERTEXBUFFER_H
#define __VERTEXBUFFER_H

#include <warp3d/warp3d.h>
#include <mgl/config.h>
#include <mgl/mgltypes.h>

#ifndef ALIGNED16 
#define ALIGNED16 __attribute__((aligned(16)))
#endif

/*#if defined(__VEC__)
#include <altivec.h>
#endif*/

/* New vertex structure for W3D_InterleavedArray */

struct MGLTexCoordSet_t
{
        GLfloat u, v, w;
};

struct MGLVertex_t
{
        /* --- Projected part --- */
        /* --- Do not touch the first 96 bytes, they are read by Warp3D --- */
        GLfloat x, y, z;                                /* Vertex position */
        GLfloat fogdepth;                               /* Fog coordinate */
        GLfloat r, g, b, a;                             /* Primary color */
        GLfloat sr, sg, sb, sa;                 /* Secondary color */
        struct MGLTexCoordSet_t
                        uvw[MAX_TEXTURE_UNITS]; /* Texure coordinate sets for all texture
                                                                           units */

        /* --- Management part --- */
#if defined(__VEC__)
        /* --- This part must be 16 byte aligned --- */
        union
        {
                MGLPosition object;
                __vector float object_vec;
        };
        union
        {
                MGLPosition clip;
                __vector float clip_vec;
        };
#else
        MGLPosition ALIGNED16 object;
        MGLPosition ALIGNED16 clip;
#endif
        MGLPosition eye;                                /* Eye coordinates, used for texture gen
                                                                           and light */
        MGLNormal       EyeNormal;                      /* Normal, projected to eye coordinates */
        float bf;
        MGLNormal   Normal;
        GLuint frame_code;                              /* Used to check for validity of transformed
                                                                           coordinates */
        GLuint tex_frame_code;                  /* Like frame_code, for texture coordinates */
        GLfloat z_back;
        GLuint outcode;
        GLfloat         dist[MGL_MAX_CLIPPLANES];
        GLboolean       rhw_valid[MAX_TEXTURE_UNITS];
        GLboolean   inview;
        GLubyte align[7]; /* padding for 16 byte alignment -- This padding ensure that entry in an array of MGLVertex is 16 byte aligned */
};

typedef struct MGLVertex_t MGLVertex;

enum {
        MGL_CLIP_NEGW   =   1<<0,
        MGL_CLIP_TOP    =   1<<1,
        MGL_CLIP_BOTTOM =   1<<2,
        MGL_CLIP_LEFT   =   1<<3,
        MGL_CLIP_RIGHT  =   1<<4,
        MGL_CLIP_FRONT  =   1<<5,
        MGL_CLIP_BACK   =   1<<6,
        MGL_CLIP_USER0  =       1<<7,
        MGL_CLIP_USER1  =       1<<8,
        MGL_CLIP_USER2  =       1<<9,
        MGL_CLIP_USER3  =       1<<10,
        MGL_CLIP_USER4  =       1<<11,
        MGL_CLIP_USER5  =       1<<12,
        MGL_CLIP_USER6  =       1<<13,
        MGL_CLIP_USER7  =       1<<14,
};

#define MGL_CLIP_USER_MASK      \
        (                                               \
          MGL_CLIP_USER1                \
        | MGL_CLIP_USER2                \
        | MGL_CLIP_USER3                \
        | MGL_CLIP_USER4                \
        | MGL_CLIP_USER5                \
        | MGL_CLIP_USER6                \
        | MGL_CLIP_USER7                \
        )


#endif
