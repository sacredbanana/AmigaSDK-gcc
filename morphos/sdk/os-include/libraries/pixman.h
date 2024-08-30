
#ifndef LIBRARIES_PIXMAN_H
#define LIBRARIES_PIXMAN_H

/*

	MorphOS Shared PixManLib
	
	pixman.library 8.0 include
	
	Copyright © 2009-2020 The MorphOS Development Team (et al.), All Rights Reserved.

*/

/*
 * Version info
 */
#define PIXMAN_VERSION_H__

#define PIXMAN_VERSION_MAJOR 0
#define PIXMAN_VERSION_MINOR 40
#define PIXMAN_VERSION_MICRO 0

#define PIXMAN_VERSION_STRING "0.40.0"

#define PIXMAN_VERSION_ENCODE(major, minor, micro) (	\
	  ((major) * 10000)				\
	+ ((minor) *   100)				\
	+ ((micro) *     1))

#define PIXMAN_VERSION PIXMAN_VERSION_ENCODE(	\
	PIXMAN_VERSION_MAJOR,			\
	PIXMAN_VERSION_MINOR,			\
	PIXMAN_VERSION_MICRO)


#ifdef  __cplusplus
#define PIXMAN_BEGIN_DECLS extern "C" {
#define PIXMAN_END_DECLS }
#else
#define PIXMAN_BEGIN_DECLS
#define PIXMAN_END_DECLS
#endif

PIXMAN_BEGIN_DECLS

/*
 * Standard integers
 */

#if !defined (PIXMAN_DONT_DEFINE_STDINT)
#include <stdint.h>
#endif

/*
 * Boolean
 */
typedef int pixman_bool_t;

/*
 * Fixpoint numbers
 */
typedef int64_t			pixman_fixed_32_32_t;
typedef pixman_fixed_32_32_t	pixman_fixed_48_16_t;
typedef uint32_t		pixman_fixed_1_31_t;
typedef uint32_t		pixman_fixed_1_16_t;
typedef int32_t			pixman_fixed_16_16_t;
typedef pixman_fixed_16_16_t	pixman_fixed_t;

#define pixman_fixed_e			((pixman_fixed_t) 1)
#define pixman_fixed_1			(pixman_int_to_fixed(1))
#define pixman_fixed_1_minus_e		(pixman_fixed_1 - pixman_fixed_e)
#define pixman_fixed_minus_1		(pixman_int_to_fixed(-1))
#define pixman_fixed_to_int(f)		((int) ((f) >> 16))
#define pixman_int_to_fixed(i)		((pixman_fixed_t) ((uint32_t) (i) << 16))
#define pixman_fixed_to_double(f)	(double) ((f) / (double) pixman_fixed_1)
#define pixman_double_to_fixed(d)	((pixman_fixed_t) ((d) * 65536.0))
#define pixman_fixed_frac(f)		((f) & pixman_fixed_1_minus_e)
#define pixman_fixed_floor(f)		((f) & ~pixman_fixed_1_minus_e)
#define pixman_fixed_ceil(f)		pixman_fixed_floor ((f) + pixman_fixed_1_minus_e)
#define pixman_fixed_fraction(f)	((f) & pixman_fixed_1_minus_e)
#define pixman_fixed_mod_2(f)		((f) & (pixman_fixed1 | pixman_fixed_1_minus_e))
#define pixman_max_fixed_48_16		((pixman_fixed_48_16_t) 0x7fffffff)
#define pixman_min_fixed_48_16		(-((pixman_fixed_48_16_t) 1 << 31))

/*
 * Misc structs
 */
typedef struct pixman_color pixman_color_t;
typedef struct pixman_point_fixed pixman_point_fixed_t;
typedef struct pixman_line_fixed pixman_line_fixed_t;
typedef struct pixman_vector pixman_vector_t;
typedef struct pixman_transform pixman_transform_t;

struct pixman_color
{
    uint16_t	red;
    uint16_t    green;
    uint16_t    blue;
    uint16_t    alpha;
};

struct pixman_point_fixed
{
    pixman_fixed_t	x;
    pixman_fixed_t	y;
};

struct pixman_line_fixed
{
    pixman_point_fixed_t	p1, p2;
};

/*
 * Fixed point matrices
 */

struct pixman_vector
{
    pixman_fixed_t	vector[3];
};

struct pixman_transform
{
    pixman_fixed_t	matrix[3][3];
};

/* forward declaration (sorry) */
struct pixman_box16;
typedef  union pixman_image		pixman_image_t;

/*
 * Floating point matrices
 */
typedef struct pixman_f_transform pixman_f_transform_t;
typedef struct pixman_f_vector pixman_f_vector_t;

struct pixman_f_vector
{
    double  v[3];
};

struct pixman_f_transform
{
    double  m[3][3];
};

typedef enum
{
    PIXMAN_REPEAT_NONE,
    PIXMAN_REPEAT_NORMAL,
    PIXMAN_REPEAT_PAD,
    PIXMAN_REPEAT_REFLECT
} pixman_repeat_t;

typedef enum
{
    PIXMAN_DITHER_NONE,
    PIXMAN_DITHER_FAST,
    PIXMAN_DITHER_GOOD,
    PIXMAN_DITHER_BEST,
    PIXMAN_DITHER_ORDERED_BAYER_8,
    PIXMAN_DITHER_ORDERED_BLUE_NOISE_64,
} pixman_dither_t;

typedef enum
{
    PIXMAN_FILTER_FAST,
    PIXMAN_FILTER_GOOD,
    PIXMAN_FILTER_BEST,
    PIXMAN_FILTER_NEAREST,
    PIXMAN_FILTER_BILINEAR,
    PIXMAN_FILTER_CONVOLUTION,

    /* The SEPARABLE_CONVOLUTION filter takes the following parameters:
     *
     *         width:           integer given as 16.16 fixpoint number
     *         height:          integer given as 16.16 fixpoint number
     *         x_phase_bits:	integer given as 16.16 fixpoint
     *         y_phase_bits:	integer given as 16.16 fixpoint
     *         xtables:         (1 << x_phase_bits) tables of size width
     *         ytables:         (1 << y_phase_bits) tables of size height
     *
     * When sampling at (x, y), the location is first rounded to one of
     * n_x_phases * n_y_phases subpixel positions. These subpixel positions
     * determine an xtable and a ytable to use.
     *
     * Conceptually a width x height matrix is then formed in which each entry
     * is the product of the corresponding entries in the x and y tables.
     * This matrix is then aligned with the image pixels such that its center
     * is as close as possible to the subpixel location chosen earlier. Then
     * the image is convolved with the matrix and the resulting pixel returned.
     */
    PIXMAN_FILTER_SEPARABLE_CONVOLUTION
} pixman_filter_t;

typedef enum
{
    PIXMAN_OP_CLEAR			= 0x00,
    PIXMAN_OP_SRC			= 0x01,
    PIXMAN_OP_DST			= 0x02,
    PIXMAN_OP_OVER			= 0x03,
    PIXMAN_OP_OVER_REVERSE		= 0x04,
    PIXMAN_OP_IN			= 0x05,
    PIXMAN_OP_IN_REVERSE		= 0x06,
    PIXMAN_OP_OUT			= 0x07,
    PIXMAN_OP_OUT_REVERSE		= 0x08,
    PIXMAN_OP_ATOP			= 0x09,
    PIXMAN_OP_ATOP_REVERSE		= 0x0a,
    PIXMAN_OP_XOR			= 0x0b,
    PIXMAN_OP_ADD			= 0x0c,
    PIXMAN_OP_SATURATE			= 0x0d,

    PIXMAN_OP_DISJOINT_CLEAR		= 0x10,
    PIXMAN_OP_DISJOINT_SRC		= 0x11,
    PIXMAN_OP_DISJOINT_DST		= 0x12,
    PIXMAN_OP_DISJOINT_OVER		= 0x13,
    PIXMAN_OP_DISJOINT_OVER_REVERSE	= 0x14,
    PIXMAN_OP_DISJOINT_IN		= 0x15,
    PIXMAN_OP_DISJOINT_IN_REVERSE	= 0x16,
    PIXMAN_OP_DISJOINT_OUT		= 0x17,
    PIXMAN_OP_DISJOINT_OUT_REVERSE	= 0x18,
    PIXMAN_OP_DISJOINT_ATOP		= 0x19,
    PIXMAN_OP_DISJOINT_ATOP_REVERSE	= 0x1a,
    PIXMAN_OP_DISJOINT_XOR		= 0x1b,

    PIXMAN_OP_CONJOINT_CLEAR		= 0x20,
    PIXMAN_OP_CONJOINT_SRC		= 0x21,
    PIXMAN_OP_CONJOINT_DST		= 0x22,
    PIXMAN_OP_CONJOINT_OVER		= 0x23,
    PIXMAN_OP_CONJOINT_OVER_REVERSE	= 0x24,
    PIXMAN_OP_CONJOINT_IN		= 0x25,
    PIXMAN_OP_CONJOINT_IN_REVERSE	= 0x26,
    PIXMAN_OP_CONJOINT_OUT		= 0x27,
    PIXMAN_OP_CONJOINT_OUT_REVERSE	= 0x28,
    PIXMAN_OP_CONJOINT_ATOP		= 0x29,
    PIXMAN_OP_CONJOINT_ATOP_REVERSE	= 0x2a,
    PIXMAN_OP_CONJOINT_XOR		= 0x2b,

    PIXMAN_OP_MULTIPLY                  = 0x30,
    PIXMAN_OP_SCREEN                    = 0x31,
    PIXMAN_OP_OVERLAY                   = 0x32,
    PIXMAN_OP_DARKEN                    = 0x33,
    PIXMAN_OP_LIGHTEN                   = 0x34,
    PIXMAN_OP_COLOR_DODGE               = 0x35,
    PIXMAN_OP_COLOR_BURN                = 0x36,
    PIXMAN_OP_HARD_LIGHT                = 0x37,
    PIXMAN_OP_SOFT_LIGHT                = 0x38,
    PIXMAN_OP_DIFFERENCE                = 0x39,
    PIXMAN_OP_EXCLUSION                 = 0x3a,
    PIXMAN_OP_HSL_HUE			= 0x3b,
    PIXMAN_OP_HSL_SATURATION		= 0x3c,
    PIXMAN_OP_HSL_COLOR			= 0x3d,
    PIXMAN_OP_HSL_LUMINOSITY		= 0x3e

#ifdef PIXMAN_USE_INTERNAL_API
    ,
    PIXMAN_N_OPERATORS,
    PIXMAN_OP_NONE = PIXMAN_N_OPERATORS
#endif
} pixman_op_t;

/*
 * Regions
 */
typedef struct pixman_region16_data	pixman_region16_data_t;
typedef struct pixman_box16		pixman_box16_t;
typedef struct pixman_rectangle16	pixman_rectangle16_t;
typedef struct pixman_region16		pixman_region16_t;

struct pixman_region16_data {
    long		size;
    long		numRects;
/*  pixman_box16_t	rects[size];   in memory but not explicitly declared */
};

struct pixman_rectangle16
{
    int16_t	x, y;
    uint16_t	width, height;
};

struct pixman_box16
{
    int16_t x1, y1, x2, y2;
};

struct pixman_region16
{
    pixman_box16_t          extents;
    pixman_region16_data_t *data;
};

typedef enum
{
    PIXMAN_REGION_OUT,
    PIXMAN_REGION_IN,
    PIXMAN_REGION_PART
} pixman_region_overlap_t;

/*
 * 32 bit regions
 */
typedef struct pixman_region32_data	pixman_region32_data_t;
typedef struct pixman_box32		pixman_box32_t;
typedef struct pixman_rectangle32	pixman_rectangle32_t;
typedef struct pixman_region32		pixman_region32_t;

struct pixman_region32_data {
    long		size;
    long		numRects;
/*  pixman_box32_t	rects[size];   in memory but not explicitly declared */
};

struct pixman_rectangle32
{
    int32_t x, y;
    uint32_t width, height;
};

struct pixman_box32
{
    int32_t x1, y1, x2, y2;
};

struct pixman_region32
{
    pixman_box32_t          extents;
    pixman_region32_data_t  *data;
};

/*
 * Images
 */
typedef struct pixman_indexed		pixman_indexed_t;
typedef struct pixman_gradient_stop	pixman_gradient_stop_t;

typedef uint32_t (* pixman_read_memory_func_t) (const void *src, int size);
typedef void     (* pixman_write_memory_func_t) (void *dst, uint32_t value, int size);

typedef void     (* pixman_image_destroy_func_t) (pixman_image_t *image, void *data);

struct pixman_gradient_stop {
    pixman_fixed_t x;
    pixman_color_t color;
};

#define PIXMAN_MAX_INDEXED  256 /* XXX depth must be <= 8 */

#if PIXMAN_MAX_INDEXED <= 256
typedef uint8_t pixman_index_type;
#endif

struct pixman_indexed
{
    pixman_bool_t       color;
    uint32_t		rgba[PIXMAN_MAX_INDEXED];
    pixman_index_type	ent[32768];
};

/*
 * While the protocol is generous in format support, the
 * sample implementation allows only packed RGB and GBR
 * representations for data to simplify software rendering,
 */
#define PIXMAN_FORMAT(bpp,type,a,r,g,b)	(((bpp) << 24) |  \
					 ((type) << 16) | \
					 ((a) << 12) |	  \
					 ((r) << 8) |	  \
					 ((g) << 4) |	  \
					 ((b)))

#define PIXMAN_FORMAT_BYTE(bpp,type,a,r,g,b) \
	(((bpp >> 3) << 24) | \
	(3 << 22) | ((type) << 16) | \
	((a >> 3) << 12) | \
	((r >> 3) << 8) | \
	((g >> 3) << 4) | \
	((b >> 3)))

#define PIXMAN_FORMAT_RESHIFT(val, ofs, num) \
	(((val >> (ofs)) & ((1 << (num)) - 1)) << ((val >> 22) & 3))

#define PIXMAN_FORMAT_BPP(f)	PIXMAN_FORMAT_RESHIFT(f, 24, 8)
#define PIXMAN_FORMAT_SHIFT(f)	((uint32_t)((f >> 22) & 3))
#define PIXMAN_FORMAT_TYPE(f)	(((f) >> 16) & 0x3f)
#define PIXMAN_FORMAT_A(f)	PIXMAN_FORMAT_RESHIFT(f, 12, 4)
#define PIXMAN_FORMAT_R(f)	PIXMAN_FORMAT_RESHIFT(f, 8, 4)
#define PIXMAN_FORMAT_G(f)	PIXMAN_FORMAT_RESHIFT(f, 4, 4)
#define PIXMAN_FORMAT_B(f)	PIXMAN_FORMAT_RESHIFT(f, 0, 4)
#define PIXMAN_FORMAT_RGB(f)	(((f)      ) & 0xfff)
#define PIXMAN_FORMAT_VIS(f)	(((f)      ) & 0xffff)
#define PIXMAN_FORMAT_DEPTH(f)	(PIXMAN_FORMAT_A(f) +	\
				 PIXMAN_FORMAT_R(f) +	\
				 PIXMAN_FORMAT_G(f) +	\
				 PIXMAN_FORMAT_B(f))

#define PIXMAN_TYPE_OTHER	0
#define PIXMAN_TYPE_A		1
#define PIXMAN_TYPE_ARGB	2
#define PIXMAN_TYPE_ABGR	3
#define PIXMAN_TYPE_COLOR	4
#define PIXMAN_TYPE_GRAY	5
#define PIXMAN_TYPE_YUY2	6
#define PIXMAN_TYPE_YV12	7
#define PIXMAN_TYPE_BGRA	8
#define PIXMAN_TYPE_RGBA	9
#define PIXMAN_TYPE_ARGB_SRGB	10
#define PIXMAN_TYPE_RGBA_FLOAT	11

#define PIXMAN_FORMAT_COLOR(f)				\
	(PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_ARGB ||	\
	 PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_ABGR ||	\
	 PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_BGRA ||	\
	 PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_RGBA ||	\
	 PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_RGBA_FLOAT)

typedef enum {
/* 128bpp formats */
    PIXMAN_rgba_float =	PIXMAN_FORMAT_BYTE(128,PIXMAN_TYPE_RGBA_FLOAT,32,32,32,32),
/* 96bpp formats */
    PIXMAN_rgb_float =	PIXMAN_FORMAT_BYTE(96,PIXMAN_TYPE_RGBA_FLOAT,0,32,32,32),

/* 32bpp formats */
    PIXMAN_a8r8g8b8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,8,8,8,8),
    PIXMAN_x8r8g8b8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,0,8,8,8),
    PIXMAN_a8b8g8r8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ABGR,8,8,8,8),
    PIXMAN_x8b8g8r8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ABGR,0,8,8,8),
    PIXMAN_b8g8r8a8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_BGRA,8,8,8,8),
    PIXMAN_b8g8r8x8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_BGRA,0,8,8,8),
    PIXMAN_r8g8b8a8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_RGBA,8,8,8,8),
    PIXMAN_r8g8b8x8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_RGBA,0,8,8,8),
    PIXMAN_x14r6g6b6 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,0,6,6,6),
    PIXMAN_x2r10g10b10 = PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,0,10,10,10),
    PIXMAN_a2r10g10b10 = PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,2,10,10,10),
    PIXMAN_x2b10g10r10 = PIXMAN_FORMAT(32,PIXMAN_TYPE_ABGR,0,10,10,10),
    PIXMAN_a2b10g10r10 = PIXMAN_FORMAT(32,PIXMAN_TYPE_ABGR,2,10,10,10),

/* sRGB formats */
    PIXMAN_a8r8g8b8_sRGB = PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB_SRGB,8,8,8,8),

/* 24bpp formats */
    PIXMAN_r8g8b8 =	 PIXMAN_FORMAT(24,PIXMAN_TYPE_ARGB,0,8,8,8),
    PIXMAN_b8g8r8 =	 PIXMAN_FORMAT(24,PIXMAN_TYPE_ABGR,0,8,8,8),

/* 16bpp formats */
    PIXMAN_r5g6b5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,0,5,6,5),
    PIXMAN_b5g6r5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,0,5,6,5),

    PIXMAN_a1r5g5b5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,1,5,5,5),
    PIXMAN_x1r5g5b5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,0,5,5,5),
    PIXMAN_a1b5g5r5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,1,5,5,5),
    PIXMAN_x1b5g5r5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,0,5,5,5),
    PIXMAN_a4r4g4b4 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,4,4,4,4),
    PIXMAN_x4r4g4b4 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,0,4,4,4),
    PIXMAN_a4b4g4r4 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,4,4,4,4),
    PIXMAN_x4b4g4r4 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,0,4,4,4),

/* 8bpp formats */
    PIXMAN_a8 =		 PIXMAN_FORMAT(8,PIXMAN_TYPE_A,8,0,0,0),
    PIXMAN_r3g3b2 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_ARGB,0,3,3,2),
    PIXMAN_b2g3r3 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_ABGR,0,3,3,2),
    PIXMAN_a2r2g2b2 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_ARGB,2,2,2,2),
    PIXMAN_a2b2g2r2 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_ABGR,2,2,2,2),

    PIXMAN_c8 =		 PIXMAN_FORMAT(8,PIXMAN_TYPE_COLOR,0,0,0,0),
    PIXMAN_g8 =		 PIXMAN_FORMAT(8,PIXMAN_TYPE_GRAY,0,0,0,0),

    PIXMAN_x4a4 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_A,4,0,0,0),

    PIXMAN_x4c4 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_COLOR,0,0,0,0),
    PIXMAN_x4g4 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_GRAY,0,0,0,0),

/* 4bpp formats */
    PIXMAN_a4 =		 PIXMAN_FORMAT(4,PIXMAN_TYPE_A,4,0,0,0),
    PIXMAN_r1g2b1 =	 PIXMAN_FORMAT(4,PIXMAN_TYPE_ARGB,0,1,2,1),
    PIXMAN_b1g2r1 =	 PIXMAN_FORMAT(4,PIXMAN_TYPE_ABGR,0,1,2,1),
    PIXMAN_a1r1g1b1 =	 PIXMAN_FORMAT(4,PIXMAN_TYPE_ARGB,1,1,1,1),
    PIXMAN_a1b1g1r1 =	 PIXMAN_FORMAT(4,PIXMAN_TYPE_ABGR,1,1,1,1),

    PIXMAN_c4 =		 PIXMAN_FORMAT(4,PIXMAN_TYPE_COLOR,0,0,0,0),
    PIXMAN_g4 =		 PIXMAN_FORMAT(4,PIXMAN_TYPE_GRAY,0,0,0,0),

/* 1bpp formats */
    PIXMAN_a1 =		 PIXMAN_FORMAT(1,PIXMAN_TYPE_A,1,0,0,0),

    PIXMAN_g1 =		 PIXMAN_FORMAT(1,PIXMAN_TYPE_GRAY,0,0,0,0),

/* YUV formats */
    PIXMAN_yuy2 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_YUY2,0,0,0,0),
    PIXMAN_yv12 =	 PIXMAN_FORMAT(12,PIXMAN_TYPE_YV12,0,0,0,0)
} pixman_format_code_t;

typedef enum
{
    PIXMAN_KERNEL_IMPULSE,
    PIXMAN_KERNEL_BOX,
    PIXMAN_KERNEL_LINEAR,
    PIXMAN_KERNEL_CUBIC,
    PIXMAN_KERNEL_GAUSSIAN,
    PIXMAN_KERNEL_LANCZOS2,
    PIXMAN_KERNEL_LANCZOS3,
    PIXMAN_KERNEL_LANCZOS3_STRETCHED       /* Jim Blinn's 'nice' filter */
} pixman_kernel_t;

/*
 * Glyphs
 */
typedef struct pixman_glyph_cache_t pixman_glyph_cache_t;
typedef struct
{
    int		x, y;
    const void *glyph;
} pixman_glyph_t;

/*
 * Trapezoids
 */
typedef struct pixman_edge pixman_edge_t;
typedef struct pixman_trapezoid pixman_trapezoid_t;
typedef struct pixman_trap pixman_trap_t;
typedef struct pixman_span_fix pixman_span_fix_t;
typedef struct pixman_triangle pixman_triangle_t;

/*
 * An edge structure.  This represents a single polygon edge
 * and can be quickly stepped across small or large gaps in the
 * sample grid
 */
struct pixman_edge
{
    pixman_fixed_t	x;
    pixman_fixed_t	e;
    pixman_fixed_t	stepx;
    pixman_fixed_t	signdx;
    pixman_fixed_t	dy;
    pixman_fixed_t	dx;

    pixman_fixed_t	stepx_small;
    pixman_fixed_t	stepx_big;
    pixman_fixed_t	dx_small;
    pixman_fixed_t	dx_big;
};

struct pixman_trapezoid
{
    pixman_fixed_t	top, bottom;
    pixman_line_fixed_t	left, right;
};

struct pixman_triangle
{
    pixman_point_fixed_t p1, p2, p3;
};

/* whether 't' is a well defined not obviously empty trapezoid */
#define pixman_trapezoid_valid(t)				   \
    ((t)->left.p1.y != (t)->left.p2.y &&			   \
     (t)->right.p1.y != (t)->right.p2.y &&			   \
     ((t)->bottom > (t)->top))

struct pixman_span_fix
{
    pixman_fixed_t	l, r, y;
};

struct pixman_trap
{
    pixman_span_fix_t	top, bot;
};

PIXMAN_END_DECLS

#endif /* LIBRARIES_PIXMAN_H */
