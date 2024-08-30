/*
 * $Id: mgltypes.h 529 2018-05-01 19:58:42Z dmuessener $
 *
 * $Date: 2018-05-01 22:58:42 +0300 (Tue, 01 May 2018) $
 * $Revision: 529 $
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#ifndef MGLTYPES_H_
#define MGLTYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif


#include "mgl/config.h"
#include "mgl/log.h"
#include <warp3d/warp3d.h>
#include <graphics/rastport.h>

/* MiniGL internal types */

typedef struct GLcontext_t * GLcontext;

struct GLcontext_t;

struct GLarray_t;

typedef void (*ArrayFetcherFn)(GLcontext, struct GLarray_t *, GLvoid *, GLuint unit);
typedef void (*ArrayFetcherIdxFn)(GLcontext, struct GLarray_t *, GLuint, GLuint unit);

typedef struct GLarray_t
{
	/*
	** Vertex array
	*/

	GLint       size;           /* Number of elements per entry (mostly 3 or 4) */
	GLenum      type;           /* Data type of entries */
	GLsizei     stride;         /* How to reach the next array element */
	GLvoid*     pointer;        /* Pointer to the actual data */
	ArrayFetcherFn fetch;		/* Function to fetch sequentially */
	ArrayFetcherIdxFn fetchIdx; /* Function fo fetch indexed */
	ArrayFetcherIdxFn fetchElement; /* For ArrayElement, sets via current state */
} GLarray;

typedef void (*DrawElementsFn)(GLcontext context, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
typedef void (*DrawArraysFn)(GLcontext context, GLenum mode, GLint first, GLsizei count);

typedef struct MGLTexture_t
{
	W3D_Texture *texObj;		/* Warp3D texture object */
	void *texData;				/* Raw texture data */
	GLuint internalFormat;		/* Internal format */
	GLuint bytesPerTexel;		/* Bytes per texel for normal textures, bytes
								 * per 4x4 texel block for S3TC textures */
	GLubyte *mipmaps[20];		/* Mipmap array */
	GLenum   WrapS;
	GLenum   WrapT;
	GLenum   MinFilter;
	GLenum   MagFilter;
	GLint    MaxAnisotropy;
} MGLTexture;

typedef struct MGLColor_t
{
	GLfloat r,g,b,a;
} MGLColor;

#define MGL_SET_COLOR(c, _r, _g, _b, _a)\
	c.r = _r;							\
	c.g = _g;							\
	c.b = _b;							\
	c.a = _a;

typedef struct MGLPosition_t
{
	GLfloat x, y, z, w;
} MGLPosition;

typedef struct MGLDirection_t
{
	GLfloat x, y, z;
} MGLDirection;

typedef struct MGLNormal_t
{
	GLfloat x,y,z;
} MGLNormal;

/*
** This structure holds the polygon data for clipping.
**
** WARNING this structure has changed to permit an open ended number of verts
**         and providing by default only the maximum number required to satisfy
**         internal MiniGL operations.
*/
typedef struct MGLPolygon_t
{
	GLfloat zoffset;
	GLint   numverts;
	GLint   verts[30]; // 9 is worst case for triangle clipped against 6 planes
	//GLfloat zoffset;
} MGLPolygon;

#define MAT_UPDATE_AMBIENT	(1L << 0)
#define MAT_UPDATE_DIFFUSE	(1L << 1)
#define MAT_UPDATE_SPECULAR	(1L << 2)

typedef struct GLmaterial_t
{
	GLuint 		Index;
	/* -- Normal material properties -- */
	MGLColor	Ambient;
	MGLColor	Diffuse;
	MGLColor	Specular;
	MGLColor	Emission;
	GLfloat		Shininess;
	/* -- Precomputed stuff -- */
	MGLColor		Acm_Acs;				/* Ambient material by ambient global */
	/* -- Used to track ColorMaterial state */
	MGLColor 	*ColorMaterial[2];
	GLuint		Update;
} GLmaterial;



typedef struct GLlight_t
{
	GLuint			Number;
	/* -- Normal light properties -- */
	MGLColor		Ambient;
	MGLColor		Diffuse;
	MGLColor		Specular;
	MGLPosition		Position;
	MGLDirection 	SpotDirection;
	GLfloat			SpotExponent;
	GLfloat			SpotCutoff;
	GLfloat			ConstantAttenuation;
	GLfloat			LinearAttenuation;
	GLfloat			QuadraticAttenuation;
	/* -- Precomputed stuff -- */
	MGLColor		Acm_by_Acli[2];		/* Ambient material by ambient light */
	MGLColor		Dcm_by_Dcli[2];		/* Diffuse material by diffuse light */
	MGLColor		Scm_by_Scli[2];		/* Specular material by specular light */
	GLfloat			OneOverConstantAttenuation;
	GLfloat			CosineSpotCutoff;
	MGLDirection 	NormSpotDirection;
} GLlight;


/* A client-defined clip plane */
typedef struct GLclipplane_t
{
	GLuint			number;				/* Number of clipplane */
	GLdouble 		eqn[4];				/* Plane equation coefficients */
	GLuint			outcode;			/* One of MGL_CLIP_USERn */
} GLclipplane;

/* Used for texture coordinate generation */
typedef struct GLtexgen_t
{
	GLenum		mode;					/* OBJECT_LINEAR, EYE_LINEAR, ... */
	GLfloat 	objectPlane[4];			/* Object plane equation */
	GLfloat		eyePlane[4];			/* Eye plane equation */
	GLboolean	needR;					/* Set during enable to indicate the
										   need for the R vector */
	GLboolean	needM;					/* Set during enable to indicate the
										   need for the m value */
} GLtexgen;


/* Evaluators */

#define MGL_NUM_EVALUATORS		8		/* vertex3/4, color4, normal, texture1/2/3/4 */

typedef struct GLeval_t
{
	GLint 		k;						/* Number of components */
	GLint		order;					/* Order of the polynomial + 1 */
	GLfloat		u1, u2;					/* Domain */
	GLfloat 	*data;					/* Control points */
	GLint 		datasize;
} GLeval1;

typedef struct GLeval2_t
{
	GLint		k;						/* Number of components */
	GLint		uOrder, vOrder;			/* Orders */
	GLfloat		u1, u2;					/* Domains */
	GLfloat		v1, v2;
	GLfloat 	*data;					/* Control points */
	GLint		datasize;
} GLeval2;

typedef struct GLevalgrid_t
{
	GLfloat		start;
	GLfloat		end;
	GLfloat 	num;
} GLevalgrid;

/* Pre-caluclation record */
typedef struct GLevalpre_t
{
	GLint	order;
	GLfloat u;
	GLfloat factor[MGL_MAX_EVAL_ORDER];
	GLboolean derivValid;
	GLfloat deriv[MGL_MAX_EVAL_ORDER];
} GLevalpre;
/* This is the main record for keeping evaluator data. */

typedef struct GLevaldata_t
{
	GLeval1	map1[MGL_NUM_EVALUATORS];	/* One-dimensional evaluators */
	GLeval2	map2[MGL_NUM_EVALUATORS];	/* Two-dimensional evaluators */

	GLevalpre u;						/* One or two dimensional precalulation */
	GLevalpre v;						/* Two dimensional precalulation */
} GLevaldata;


/* The following is used to unpack textures from client space to Warp3D */

#include "profiling.h"

typedef void (*write_func)(PROFILE_PROTO const GLubyte *from, GLubyte *to, GLsizei num, GLsizei stride);
typedef void (*unpack_func)(GLcontext context, const GLubyte *from, GLubyte *to, GLsizei num);

struct FormatTypeToUnpack
{
	GLenum format;
	GLenum type;
	unpack_func unpack;
	GLsizei stride;
};

struct InternalToW3D
{
	GLenum internalformat;
	uint32 w3dFormat;
	uint32 w3dBpp;
	write_func write;
	uint32 redsize;
	uint32 greensize;
	uint32 bluesize;
	uint32 alphasize;
	uint32 luminancesize;
	uint32 intensitysize;
};

struct W3DtoGL
{
	uint32 w3dFormat;
	uint32 w3dBpp;
	uint32 redsize;
	uint32 greensize;
	uint32 bluesize;
	uint32 alphasize;
	uint32 luminancesize;
	uint32 intensitysize;
	GLenum glformat;
	GLenum gltype;
};

typedef struct GLpixel_store_s
{
	GLboolean	swap_bytes;
	GLboolean	lsb_first;
	GLint		row_length;
	GLint		skip_rows;
	GLint		skip_pixels;
	GLint		alignment;
} GLpixel_store;


typedef struct GLimage_info_s
{
	GLubyte 	*data;			/* Image's base address */
	GLint		stride;			/* Image's stride (bytes per row) */
	GLenum		format;			/* Format, i.e. GL_RGBA, GL_BGRA, etc */
	GLenum		type;			/* Type, i.e. GL_UNSIGNED_BYTE, GL_FLOAT */
	GLenum		pixel_stride;	/* How much to add to get from one pixel to the
	 							 * next
	 							 */
	GLubyte 	*current;		/* The base address of what we currently convert */
} GLimage_info;


/* Unpack from source (pointed to by current in image info) into a buffer.
 * The destination buffer is always ARGB32 for color, a float for depth,
 * and an int for stencil
 */
typedef void (*_glUnpackFn)(GLcontext context, int num_pixels, GLimage_info *src,
		GLpixel_store *unpack, void *dst);

/* Pack from the src buffer into the destination image. The source buffer is
 * the same as the destination buffer above. dst->current points to the data
 * that has to be converted.
 */
typedef void (*_glPackFn)(GLcontext context, int num_pixels, void *src, GLimage_info *dst,
		GLpixel_store *pack);

/* Apply the pixel transfer modes, scale and bias */
struct GLpixel_state;
typedef void (*_glTransferFn)(GLcontext context, int num_pixels, void *buffer, struct GLpixel_state *ps);

typedef struct GLunpack_s
{
	GLenum format;
	GLenum type;
	_glUnpackFn unpack;
	GLsizei stride;
} GLunpack;

typedef struct GLpack_s
{
	GLenum format;
	GLenum type;
	_glPackFn pack;
	GLsizei stride;
} GLpack;


/* A buffer used for rendering */
#define BUF_FREE_BITMAP		1

typedef struct GLbuffer_s
{
	struct BitMap *bitMap;
	struct RastPort rastPort;

	GLsizei	width;
	GLsizei height;

	GLuint	flags;
} GLbuffer;

/* Vertex Buffer Objects */

typedef struct GLVBO_t
{
	GLuint    size;
	GLubyte  *data;
	GLenum    usage;
	GLboolean mapped;
} GLVBO;

#ifdef __cplusplus
}
#endif

#endif
