#ifndef LIBRARIES_PNG_H
#define LIBRARIES_PNG_H

/*

	MorphOS Shared PNGLib

	png.library include

	Copyright © 2003-2021 The MorphOS Development Team, All Rights Reserved.

*/


#define PNG_H

#define PNG_LIBPNG_VER_STRING "1.2.59"
#define PNG_HEADER_VERSION_STRING \
	" libpng version 1.2.59 - September 28, 2017\n"

#define PNG_LIBPNG_VER_SONUM   0
#define PNG_LIBPNG_VER_DLLNUM  13

#define PNG_LIBPNG_VER_MAJOR   1
#define PNG_LIBPNG_VER_MINOR   2
#define PNG_LIBPNG_VER_RELEASE 59

#define PNG_LIBPNG_VER_BUILD   0

#define PNG_LIBPNG_BUILD_ALPHA                1
#define PNG_LIBPNG_BUILD_BETA                 2
#define PNG_LIBPNG_BUILD_RC                   3
#define PNG_LIBPNG_BUILD_STABLE               4
#define PNG_LIBPNG_BUILD_RELEASE_STATUS_MASK  7
#define PNG_LIBPNG_BUILD_PATCH                8 /* Can be OR'ed with PNG_LIBPNG_BUILD_STABLE only */
#define PNG_LIBPNG_BUILD_PRIVATE             16 /* Cannot be OR'ed with PNG_LIBPNG_BUILD_SPECIAL */
#define PNG_LIBPNG_BUILD_SPECIAL             32 /* Cannot be OR'ed with PNG_LIBPNG_BUILD_PRIVATE */

#define PNG_LIBPNG_BUILD_BASE_TYPE PNG_LIBPNG_BUILD_STABLE
#define PNG_LIBPNG_BUILD_TYPE PNG_LIBPNG_BUILD_BASE_TYPE

#define PNG_LIBPNG_VER  10259 /* 1.2.59 */


#ifndef PNG_VERSION_INFO_ONLY

#include <libraries/z.h>
#include <sys/types.h>
#include <setjmp.h>
#include <strings.h>
#include <time.h>
#include <stdio.h>

/*
	this part mimics pngconf.h

	these defines match those used to compile png.library

*/

#define PNG_1_2_X

/*
	pngconf: what we don't have

*/

#define PNG_NO_CONSOLE_IO


/*
	pngconf: some constants

*/

#define PNG_ZBUF_SIZE	8192
#define PNGARG(arglist)	arglist
#define PNG_CONST 		const


/*
	pngconf: what we do have
*/

#define PNG_READ_SUPPORTED
#define PNG_WRITE_SUPPORTED
#define PNG_MNG_FEATURES_SUPPORTED
#define PNG_FLOATING_POINT_SUPPORTED
#define PNG_FIXED_POINT_SUPPORTED
#define PNG_SETJMP_SUPPORTED
#define PNG_USER_MEM_SUPPORTED


#define PNG_READ_TRANSFORMS_SUPPORTED

#define PNG_READ_EXPAND_SUPPORTED
#define PNG_READ_SHIFT_SUPPORTED
#define PNG_READ_PACK_SUPPORTED
#define PNG_READ_BGR_SUPPORTED
#define PNG_READ_SWAP_SUPPORTED
#define PNG_READ_PACKSWAP_SUPPORTED
#define PNG_READ_INVERT_SUPPORTED
#define PNG_READ_DITHER_SUPPORTED
#define PNG_READ_BACKGROUND_SUPPORTED
#define PNG_READ_16_TO_8_SUPPORTED
#define PNG_READ_FILLER_SUPPORTED
#define PNG_READ_GAMMA_SUPPORTED
#define PNG_READ_GRAY_TO_RGB_SUPPORTED
#define PNG_READ_SWAP_ALPHA_SUPPORTED
#define PNG_READ_INVERT_ALPHA_SUPPORTED
#define PNG_READ_STRIP_ALPHA_SUPPORTED
#define PNG_READ_USER_TRANSFORM_SUPPORTED
#define PNG_READ_RGB_TO_GRAY_SUPPORTED

#define PNG_READ_BIG_ENDIAN_SUPPORTED

#define PNG_PROGRESSIVE_READ_SUPPORTED
#define PNG_READ_INTERLACING_SUPPORTED
#define PNG_READ_COMPOSITE_NODIV_SUPPORTED

#define PNG_WRITE_TRANSFORMS_SUPPORTED

#define PNG_WRITE_SHIFT_SUPPORTED
#define PNG_WRITE_PACK_SUPPORTED
#define PNG_WRITE_BGR_SUPPORTED
#define PNG_WRITE_SWAP_SUPPORTED
#define PNG_WRITE_PACKSWAP_SUPPORTED
#define PNG_WRITE_INVERT_SUPPORTED
#define PNG_WRITE_FILLER_SUPPORTED   /* same as WRITE_STRIP_ALPHA */
#define PNG_WRITE_SWAP_ALPHA_SUPPORTED
#define PNG_WRITE_INVERT_ALPHA_SUPPORTED
#define PNG_WRITE_USER_TRANSFORM_SUPPORTED

#define PNG_USER_TRANSFORM_PTR_SUPPORTED

#define PNG_WRITE_INTERLACING_SUPPORTED

#define PNG_ERROR_NUMBERS_SUPPORTED
#define PNG_WRITE_FLUSH_SUPPORTED

#define PNG_TIME_RFC1123_SUPPORTED
#define PNG_EASY_ACCESS_SUPPORTED
#define PNG_SET_USER_LIMITS_SUPPORTED

#define PNG_OPTIMIZED_CODE_SUPPORTED

/*
	zconf: chunks
*/

#define PNG_READ_ANCILLARY_CHUNKS_SUPPORTED
#define PNG_WRITE_ANCILLARY_CHUNKS_SUPPORTED

#define PNG_UNKNOWN_CHUNKS_SUPPORTED
#define PNG_HANDLE_AS_UNKNOWN_SUPPORTED

#define PNG_READ_USER_CHUNKS_SUPPORTED
#define PNG_USER_CHUNKS_SUPPORTED

#define PNG_READ_OPT_PLTE_SUPPORTED

#define PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
#define PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED

#define PNG_READ_TEXT_SUPPORTED
#define PNG_TEXT_SUPPORTED

#define PNG_iTXt_SUPPORTED
#define PNG_READ_iTXt_SUPPORTED
#define PNG_WRITE_iTXt_SUPPORTED

#define PNG_READ_bKGD_SUPPORTED
#define PNG_WRITE_bKGD_SUPPORTED
#define PNG_bKGD_SUPPORTED

#define PNG_READ_cHRM_SUPPORTED
#define PNG_WRITE_cHRM_SUPPORTED
#define PNG_cHRM_SUPPORTED

#define PNG_READ_gAMA_SUPPORTED
#define PNG_WRITE_gAMA_SUPPORTED
#define PNG_gAMA_SUPPORTED

#define PNG_READ_hIST_SUPPORTED
#define PNG_WRITE_hIST_SUPPORTED
#define PNG_hIST_SUPPORTED

#define PNG_READ_iCCP_SUPPORTED
#define PNG_WRITE_iCCP_SUPPORTED
#define PNG_iCCP_SUPPORTED

#define PNG_READ_iTXt_SUPPORTED
#define PNG_WRITE_iTXt_SUPPORTED
#define PNG_iTXt_SUPPORTED

#define PNG_READ_oFFs_SUPPORTED
#define PNG_WRITE_oFFs_SUPPORTED
#define PNG_oFFs_SUPPORTED

#define PNG_READ_pCAL_SUPPORTED
#define PNG_WRITE_pCAL_SUPPORTED
#define PNG_pCAL_SUPPORTED

#define PNG_READ_sCAL_SUPPORTED
#define PNG_WRITE_sCAL_SUPPORTED
#define PNG_sCAL_SUPPORTED

#define PNG_READ_pHYs_SUPPORTED
#define PNG_WRITE_pHYs_SUPPORTED
#define PNG_pHYs_SUPPORTED

#define PNG_READ_sBIT_SUPPORTED
#define PNG_WRITE_sBIT_SUPPORTED
#define PNG_sBIT_SUPPORTED

#define PNG_READ_sPLT_SUPPORTED
#define PNG_WRITE_sPLT_SUPPORTED
#define PNG_sPLT_SUPPORTED

#define PNG_READ_sRGB_SUPPORTED
#define PNG_WRITE_sRGB_SUPPORTED
#define PNG_sRGB_SUPPORTED

#define PNG_READ_tEXt_SUPPORTED
#define PNG_WRITE_tEXt_SUPPORTED
#define PNG_tEXt_SUPPORTED

#define PNG_READ_tIME_SUPPORTED
#define PNG_WRITE_tIME_SUPPORTED
#define PNG_tIME_SUPPORTED

#define PNG_READ_tRNS_SUPPORTED
#define PNG_WRITE_tRNS_SUPPORTED
#define PNG_tRNS_SUPPORTED

#define PNG_READ_zTXt_SUPPORTED
#define PNG_WRITE_zTXt_SUPPORTED
#define PNG_zTXt_SUPPORTED


#define PNG_INFO_IMAGE_SUPPORTED


#define PNG_SET_USER_LIMITS_SUPPORTED
#define PNG_USER_WIDTH_MAX 1000000L
#define PNG_USER_HEIGHT_MAX 1000000L


/*
	zconf: types and defines
*/


#define FAR
#define FARDATA

typedef unsigned long png_uint_32;
typedef long png_int_32;
typedef unsigned short png_uint_16;
typedef short png_int_16;
typedef unsigned char png_byte;


typedef size_t png_size_t;
#define png_sizeof(x) sizeof(x)

typedef png_int_32 png_fixed_point;

typedef void            FAR * png_voidp;
typedef png_byte        FAR * png_bytep;
typedef png_uint_32     FAR * png_uint_32p;
typedef png_int_32      FAR * png_int_32p;
typedef png_uint_16     FAR * png_uint_16p;
typedef png_int_16      FAR * png_int_16p;
typedef PNG_CONST char  FAR * png_const_charp;
typedef char            FAR * png_charp;
typedef png_fixed_point FAR * png_fixed_point_p;

typedef FILE                * png_FILE_p;

typedef double          FAR * png_doublep;

typedef png_byte        FAR * FAR * png_bytepp;
typedef png_uint_32     FAR * FAR * png_uint_32pp;
typedef png_int_32      FAR * FAR * png_int_32pp;
typedef png_uint_16     FAR * FAR * png_uint_16pp;
typedef png_int_16      FAR * FAR * png_int_16pp;
typedef PNG_CONST char  FAR * FAR * png_const_charpp;
typedef char            FAR * FAR * png_charpp;
typedef png_fixed_point FAR * FAR * png_fixed_point_pp;
typedef double          FAR * FAR * png_doublepp;

typedef char            FAR * FAR * FAR * png_charppp;

typedef charf *         png_zcharp;
typedef charf * FAR *   png_zcharpp;
typedef z_stream FAR *  png_zstreamp;

#define PNGAPI
#define PNG_IMPEXP
#define PNG_EXPORT(type,symbol) PNG_IMPEXP type PNGAPI symbol

#define PNG_ABORT() abort()
#if _JBLEN != 59 && !defined(PNG_SKIP_SETJMP_CHECK)
/*
	MorphOS png.library requires that the png_jmpbuf is
	used with setjmp59/longjmp59 routines. Once the code
	has been adjusted, define PNG_SKIP_SETJMP_CHECK.
*/
#  define png_jmpbuf(png_ptr) \
   (MORPHOS_SHARED_PNG_LIBRARY_REQUIRES_USE_OF_setjmp59_FUNCTION)
#else
#  define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf59)
#endif


/*
	this part mimics png.h
*/


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define int_p_NULL                NULL
#define png_bytep_NULL            NULL
#define png_bytepp_NULL           NULL
#define png_doublep_NULL          NULL
#define png_error_ptr_NULL        NULL
#define png_flush_ptr_NULL        NULL
#define png_free_ptr_NULL         NULL
#define png_infopp_NULL           NULL
#define png_malloc_ptr_NULL       NULL
#define png_read_status_ptr_NULL  NULL
#define png_rw_ptr_NULL           NULL
#define png_structp_NULL          NULL
#define png_uint_16p_NULL         NULL
#define png_voidp_NULL            NULL
#define png_write_status_ptr_NULL NULL

#define png_libpng_ver png_get_header_ver(NULL)


typedef struct png_color_struct
{
   png_byte red;
   png_byte green;
   png_byte blue;
} png_color;
typedef png_color FAR * png_colorp;
typedef png_color FAR * FAR * png_colorpp;

typedef struct png_color_16_struct
{
   png_byte index;
   png_uint_16 red;
   png_uint_16 green;
   png_uint_16 blue;
   png_uint_16 gray;
} png_color_16;
typedef png_color_16 FAR * png_color_16p;
typedef png_color_16 FAR * FAR * png_color_16pp;

typedef struct png_color_8_struct
{
   png_byte red;
   png_byte green;
   png_byte blue;
   png_byte gray;
   png_byte alpha;
} png_color_8;
typedef png_color_8 FAR * png_color_8p;
typedef png_color_8 FAR * FAR * png_color_8pp;

typedef struct png_sPLT_entry_struct
{
   png_uint_16 red;
   png_uint_16 green;
   png_uint_16 blue;
   png_uint_16 alpha;
   png_uint_16 frequency;
} png_sPLT_entry;
typedef png_sPLT_entry FAR * png_sPLT_entryp;
typedef png_sPLT_entry FAR * FAR * png_sPLT_entrypp;

typedef struct png_sPLT_struct
{
   png_charp name;
   png_byte depth;
   png_sPLT_entryp entries;
   png_int_32 nentries;
} png_sPLT_t;
typedef png_sPLT_t FAR * png_sPLT_tp;
typedef png_sPLT_t FAR * FAR * png_sPLT_tpp;

typedef struct png_text_struct
{
   int  compression;
   png_charp key;
   png_charp text;
   png_size_t text_length;
   png_size_t itxt_length;
   png_charp lang;
   png_charp lang_key;
} png_text;
typedef png_text FAR * png_textp;
typedef png_text FAR * FAR * png_textpp;


#define PNG_TEXT_COMPRESSION_NONE_WR -3
#define PNG_TEXT_COMPRESSION_zTXt_WR -2
#define PNG_TEXT_COMPRESSION_NONE    -1
#define PNG_TEXT_COMPRESSION_zTXt     0
#define PNG_ITXT_COMPRESSION_NONE     1
#define PNG_ITXT_COMPRESSION_zTXt     2
#define PNG_TEXT_COMPRESSION_LAST     3  /* Not a valid value */


typedef struct png_time_struct
{
   png_uint_16 year;
   png_byte month;
   png_byte day;
   png_byte hour;
   png_byte minute;
   png_byte second;
} png_time;
typedef png_time FAR * png_timep;
typedef png_time FAR * FAR * png_timepp;


#define PNG_CHUNK_NAME_LENGTH 5
typedef struct png_unknown_chunk_t
{
   png_byte name[PNG_CHUNK_NAME_LENGTH];
   png_byte *data;
   png_size_t size;

   png_byte location;
}
png_unknown_chunk;
typedef png_unknown_chunk FAR * png_unknown_chunkp;
typedef png_unknown_chunk FAR * FAR * png_unknown_chunkpp;


typedef struct png_info_struct
{
   png_uint_32 width;
   png_uint_32 height;
   png_uint_32 valid;
   png_uint_32 rowbytes;
   png_colorp palette;
   png_uint_16 num_palette;
   png_uint_16 num_trans;
   png_byte bit_depth;
   png_byte color_type;

   png_byte compression_type;
   png_byte filter_type;
   png_byte interlace_type;

   png_byte channels;
   png_byte pixel_depth;
   png_byte spare_byte;
   png_byte signature[8];

   float gamma; /* gamma value of image, if (valid & PNG_INFO_gAMA) */

   png_byte srgb_intent; /* sRGB rendering intent [0, 1, 2, or 3] */

   int num_text; /* number of comments read/to write */
   int max_text; /* current size of text array */
   png_textp text; /* array of comments read/to write */

   png_time mod_time;

   png_color_8 sig_bit; /* significant bits in color channels */

   png_bytep trans; /* transparent values for paletted image */
   png_color_16 trans_values; /* transparent color for non-palette image */

   png_color_16 background;

   png_int_32 x_offset; /* x offset on page */
   png_int_32 y_offset; /* y offset on page */
   png_byte offset_unit_type; /* offset units type */

   png_uint_32 x_pixels_per_unit; /* horizontal pixel density */
   png_uint_32 y_pixels_per_unit; /* vertical pixel density */
   png_byte phys_unit_type; /* resolution type (see PNG_RESOLUTION_ below) */

   png_uint_16p hist;

   float x_white;
   float y_white;
   float x_red;
   float y_red;
   float x_green;
   float y_green;
   float x_blue;
   float y_blue;

   png_charp pcal_purpose;  /* pCAL chunk description string */
   png_int_32 pcal_X0;      /* minimum value */
   png_int_32 pcal_X1;      /* maximum value */
   png_charp pcal_units;    /* Latin-1 string giving physical units */
   png_charpp pcal_params;  /* ASCII strings containing parameter values */
   png_byte pcal_type;      /* equation type (see PNG_EQUATION_ below) */
   png_byte pcal_nparams;   /* number of parameters given in pcal_params */

   png_uint_32 free_me;     /* flags items libpng is responsible for freeing */

   png_unknown_chunkp unknown_chunks;
   png_size_t unknown_chunks_num;

   png_charp iccp_name;     /* profile name */
   png_charp iccp_profile;  /* International Color Consortium profile data */
                            /* Note to maintainer: should be png_bytep */
   png_uint_32 iccp_proflen;  /* ICC profile data length */
   png_byte iccp_compression; /* Always zero */

   png_sPLT_tp splt_palettes;
   png_uint_32 splt_palettes_num;

   png_byte scal_unit;         /* unit of physical scale */

   double scal_pixel_width;    /* width of one pixel */
   double scal_pixel_height;   /* height of one pixel */

   png_charp scal_s_width;     /* string containing height */
   png_charp scal_s_height;    /* string containing width */

   png_bytepp row_pointers;        /* the image bits */

   png_fixed_point int_gamma; /* gamma of image, if (valid & PNG_INFO_gAMA) */

   png_fixed_point int_x_white;
   png_fixed_point int_y_white;
   png_fixed_point int_x_red;
   png_fixed_point int_y_red;
   png_fixed_point int_x_green;
   png_fixed_point int_y_green;
   png_fixed_point int_x_blue;
   png_fixed_point int_y_blue;

} png_info;

typedef png_info FAR * png_infop;
typedef png_info FAR * FAR * png_infopp;

#define PNG_UINT_31_MAX ((png_uint_32)0x7fffffffL)
#define PNG_UINT_32_MAX ((png_uint_32)(-1))
#define PNG_SIZE_MAX ((png_size_t)(-1))
/* PNG_MAX_UINT is deprecated; use PNG_UINT_31_MAX instead. */
#define PNG_MAX_UINT PNG_UINT_31_MAX

#define PNG_COLOR_MASK_PALETTE    1
#define PNG_COLOR_MASK_COLOR      2
#define PNG_COLOR_MASK_ALPHA      4

#define PNG_COLOR_TYPE_GRAY			0
#define PNG_COLOR_TYPE_PALETTE		(PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_PALETTE)
#define PNG_COLOR_TYPE_RGB			(PNG_COLOR_MASK_COLOR)
#define PNG_COLOR_TYPE_RGB_ALPHA	(PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_ALPHA)
#define PNG_COLOR_TYPE_GRAY_ALPHA	(PNG_COLOR_MASK_ALPHA)

#define PNG_COLOR_TYPE_RGBA			PNG_COLOR_TYPE_RGB_ALPHA
#define PNG_COLOR_TYPE_GA			PNG_COLOR_TYPE_GRAY_ALPHA


#define PNG_COMPRESSION_TYPE_BASE		0
#define PNG_COMPRESSION_TYPE_DEFAULT	PNG_COMPRESSION_TYPE_BASE

#define PNG_FILTER_TYPE_BASE		0
#define PNG_INTRAPIXEL_DIFFERENCING	64
#define PNG_FILTER_TYPE_DEFAULT		PNG_FILTER_TYPE_BASE

#define PNG_INTERLACE_NONE        0
#define PNG_INTERLACE_ADAM7       1
#define PNG_INTERLACE_LAST        2

#define PNG_OFFSET_PIXEL          0
#define PNG_OFFSET_MICROMETER     1
#define PNG_OFFSET_LAST           2

#define PNG_EQUATION_LINEAR       0
#define PNG_EQUATION_BASE_E       1
#define PNG_EQUATION_ARBITRARY    2
#define PNG_EQUATION_HYPERBOLIC   3
#define PNG_EQUATION_LAST         4

#define PNG_SCALE_UNKNOWN         0
#define PNG_SCALE_METER           1
#define PNG_SCALE_RADIAN          2
#define PNG_SCALE_LAST            3


#define PNG_RESOLUTION_UNKNOWN    0
#define PNG_RESOLUTION_METER      1
#define PNG_RESOLUTION_LAST       2

#define PNG_sRGB_INTENT_PERCEPTUAL 0
#define PNG_sRGB_INTENT_RELATIVE   1
#define PNG_sRGB_INTENT_SATURATION 2
#define PNG_sRGB_INTENT_ABSOLUTE   3
#define PNG_sRGB_INTENT_LAST       4

#define PNG_KEYWORD_MAX_LENGTH     79

#define PNG_MAX_PALETTE_LENGTH    256

#define PNG_INFO_gAMA 0x0001
#define PNG_INFO_sBIT 0x0002
#define PNG_INFO_cHRM 0x0004
#define PNG_INFO_PLTE 0x0008
#define PNG_INFO_tRNS 0x0010
#define PNG_INFO_bKGD 0x0020
#define PNG_INFO_hIST 0x0040
#define PNG_INFO_pHYs 0x0080
#define PNG_INFO_oFFs 0x0100
#define PNG_INFO_tIME 0x0200
#define PNG_INFO_pCAL 0x0400
#define PNG_INFO_sRGB 0x0800   /* GR-P, 0.96a */
#define PNG_INFO_iCCP 0x1000   /* ESR, 1.0.6 */
#define PNG_INFO_sPLT 0x2000   /* ESR, 1.0.6 */
#define PNG_INFO_sCAL 0x4000   /* ESR, 1.0.6 */
#define PNG_INFO_IDAT 0x8000L  /* ESR, 1.0.6 */


typedef struct png_row_info_struct
{
   png_uint_32 width;
   png_uint_32 rowbytes;
   png_byte color_type;
   png_byte bit_depth;
   png_byte channels;
   png_byte pixel_depth;
} png_row_info;

typedef png_row_info FAR * png_row_infop;
typedef png_row_info FAR * FAR * png_row_infopp;


typedef struct png_struct_def png_struct;
typedef png_struct FAR * png_structp;

typedef void (PNGAPI *png_error_ptr) PNGARG((png_structp, png_const_charp));
typedef void (PNGAPI *png_rw_ptr) PNGARG((png_structp, png_bytep, png_size_t));
typedef void (PNGAPI *png_flush_ptr) PNGARG((png_structp));
typedef void (PNGAPI *png_read_status_ptr) PNGARG((png_structp, png_uint_32, int));
typedef void (PNGAPI *png_write_status_ptr) PNGARG((png_structp, png_uint_32, int));

typedef void (PNGAPI *png_progressive_info_ptr) PNGARG((png_structp, png_infop));
typedef void (PNGAPI *png_progressive_end_ptr) PNGARG((png_structp, png_infop));
typedef void (PNGAPI *png_progressive_row_ptr) PNGARG((png_structp, png_bytep, png_uint_32, int));

typedef void (PNGAPI *png_user_transform_ptr) PNGARG((png_structp, png_row_infop, png_bytep));

typedef int (PNGAPI *png_user_chunk_ptr) PNGARG((png_structp, png_unknown_chunkp));
typedef void (PNGAPI *png_unknown_chunk_ptr) PNGARG((png_structp));

#define PNG_TRANSFORM_IDENTITY       0x0000    /* read and write */
#define PNG_TRANSFORM_STRIP_16       0x0001    /* read only */
#define PNG_TRANSFORM_STRIP_ALPHA    0x0002    /* read only */
#define PNG_TRANSFORM_PACKING        0x0004    /* read and write */
#define PNG_TRANSFORM_PACKSWAP       0x0008    /* read and write */
#define PNG_TRANSFORM_EXPAND         0x0010    /* read only */
#define PNG_TRANSFORM_INVERT_MONO    0x0020    /* read and write */
#define PNG_TRANSFORM_SHIFT          0x0040    /* read and write */
#define PNG_TRANSFORM_BGR            0x0080    /* read and write */
#define PNG_TRANSFORM_SWAP_ALPHA     0x0100    /* read and write */
#define PNG_TRANSFORM_SWAP_ENDIAN    0x0200    /* read and write */
#define PNG_TRANSFORM_INVERT_ALPHA   0x0400    /* read and write */
#define PNG_TRANSFORM_STRIP_FILLER   0x0800    /* WRITE only, deprecated */
#define PNG_TRANSFORM_STRIP_FILLER_BEFORE 0x0800  /* write only */
#define PNG_TRANSFORM_STRIP_FILLER_AFTER  0x1000  /* write only */
#define PNG_TRANSFORM_GRAY_TO_RGB   0x2000      /* read only */

#define PNG_FLAG_MNG_EMPTY_PLTE     0x01
#define PNG_FLAG_MNG_FILTER_64      0x04
#define PNG_ALL_MNG_FEATURES        0x05

typedef png_voidp (*png_malloc_ptr) PNGARG((png_structp, png_size_t));
typedef void (*png_free_ptr) PNGARG((png_structp, png_voidp));

struct png_struct_def
{
   int jmpbuf59[59];          /* used in png_error */

   png_error_ptr error_fn;    /* function for printing errors and aborting */
   png_error_ptr warning_fn;  /* function for printing warnings */
   png_voidp error_ptr;       /* user supplied struct for error functions */
   png_rw_ptr write_data_fn;  /* function for writing output data */
   png_rw_ptr read_data_fn;   /* function for reading input data */
   png_voidp io_ptr;          /* ptr to application struct for I/O functions */

   png_user_transform_ptr read_user_transform_fn; /* user read transform */

   png_user_transform_ptr write_user_transform_fn; /* user write transform */

   png_voidp user_transform_ptr; /* user supplied struct for user transform */
   png_byte user_transform_depth;    /* bit depth of user transformed pixels */
   png_byte user_transform_channels; /* channels in user transformed pixels */

   png_uint_32 mode;          /* tells us where we are in the PNG file */
   png_uint_32 flags;         /* flags indicating various things to libpng */
   png_uint_32 transformations; /* which transformations to perform */

   z_stream zstream;          /* pointer to decompression structure (below) */
   png_bytep zbuf;            /* buffer for zlib */
   png_size_t zbuf_size;      /* size of zbuf */
   int zlib_level;            /* holds zlib compression level */
   int zlib_method;           /* holds zlib compression method */
   int zlib_window_bits;      /* holds zlib compression window bits */
   int zlib_mem_level;        /* holds zlib compression memory level */
   int zlib_strategy;         /* holds zlib compression strategy */

   png_uint_32 width;         /* width of image in pixels */
   png_uint_32 height;        /* height of image in pixels */
   png_uint_32 num_rows;      /* number of rows in current pass */
   png_uint_32 usr_width;     /* width of row at start of write */
   png_uint_32 rowbytes;      /* size of row in bytes */
   png_uint_32 irowbytes;     /* size of current interlaced row in bytes */
   png_uint_32 iwidth;        /* width of current interlaced row in pixels */
   png_uint_32 row_number;    /* current row in interlace pass */
   png_bytep prev_row;        /* buffer to save previous (unfiltered) row */
   png_bytep row_buf;         /* buffer to save current (unfiltered) row */
   png_bytep sub_row;         /* buffer to save "sub" row when filtering */
   png_bytep up_row;          /* buffer to save "up" row when filtering */
   png_bytep avg_row;         /* buffer to save "avg" row when filtering */
   png_bytep paeth_row;       /* buffer to save "Paeth" row when filtering */
   png_row_info row_info;     /* used for transformation routines */

   png_uint_32 idat_size;     /* current IDAT size for read */
   png_uint_32 crc;           /* current chunk CRC value */
   png_colorp palette;        /* palette from the input file */
   png_uint_16 num_palette;   /* number of color entries in palette */
   png_uint_16 num_trans;     /* number of transparency values */
   png_byte chunk_name[5];    /* null-terminated name of current chunk */
   png_byte compression;      /* file compression type (always 0) */
   png_byte filter;           /* file filter type (always 0) */
   png_byte interlaced;       /* PNG_INTERLACE_NONE, PNG_INTERLACE_ADAM7 */
   png_byte pass;             /* current interlace pass (0 - 6) */
   png_byte do_filter;        /* row filter flags (see PNG_FILTER_ below ) */
   png_byte color_type;       /* color type of file */
   png_byte bit_depth;        /* bit depth of file */
   png_byte usr_bit_depth;    /* bit depth of users row */
   png_byte pixel_depth;      /* number of bits per pixel */
   png_byte channels;         /* number of channels in file */
   png_byte usr_channels;     /* channels at start of write */
   png_byte sig_bytes;        /* magic bytes read/written from start of file */

   png_uint_16 filler;           /* filler bytes for pixel expansion */

   png_byte background_gamma_type;

   float background_gamma;

   png_color_16 background;   /* background color in screen gamma space */

   png_color_16 background_1; /* background normalized to gamma 1.0 */

   png_flush_ptr output_flush_fn;/* Function for flushing output */
   png_uint_32 flush_dist;    /* how many rows apart to flush, 0 - no flush */
   png_uint_32 flush_rows;    /* number of rows written since last flush */

   int gamma_shift;      /* number of "insignificant" bits 16-bit gamma */

   float gamma;          /* file gamma value */
   float screen_gamma;   /* screen gamma value (display_exponent) */


   png_bytep gamma_table;     /* gamma table for 8-bit depth files */
   png_bytep gamma_from_1;    /* converts from 1.0 to screen */
   png_bytep gamma_to_1;      /* converts from file to 1.0 */
   png_uint_16pp gamma_16_table; /* gamma table for 16-bit depth files */
   png_uint_16pp gamma_16_from_1; /* converts from 1.0 to screen */
   png_uint_16pp gamma_16_to_1; /* converts from file to 1.0 */

   png_color_8 sig_bit;       /* significant bits in each available channel */

   png_color_8 shift;         /* shift for significant bit tranformation */

   png_bytep trans;           /* transparency values for paletted files */
   png_color_16 trans_values; /* transparency values for non-paletted files */

   png_read_status_ptr read_row_fn;   /* called after each row is decoded */
   png_write_status_ptr write_row_fn; /* called after each row is encoded */

   png_progressive_info_ptr info_fn; /* called after header data fully read */
   png_progressive_row_ptr row_fn;   /* called after each prog. row is decoded */
   png_progressive_end_ptr end_fn;   /* called after image is complete */
   png_bytep save_buffer_ptr;        /* current location in save_buffer */
   png_bytep save_buffer;            /* buffer for previously read data */
   png_bytep current_buffer_ptr;     /* current location in current_buffer */
   png_bytep current_buffer;         /* buffer for recently used data */
   png_uint_32 push_length;          /* size of current input chunk */
   png_uint_32 skip_length;          /* bytes to skip in input data */
   png_size_t save_buffer_size;      /* amount of data now in save_buffer */
   png_size_t save_buffer_max;       /* total size of save_buffer */
   png_size_t buffer_size;           /* total amount of available input data */
   png_size_t current_buffer_size;   /* amount of data now in current_buffer */
   int process_mode;                 /* what push library is currently doing */
   int cur_palette;                  /* current push library palette index */


   png_size_t current_text_size;   /* current size of text input data */
   png_size_t current_text_left;   /* how much text left to read in input */
   png_charp current_text;         /* current text chunk buffer */
   png_charp current_text_ptr;     /* current location in current_text */


   png_bytep palette_lookup;         /* lookup table for dithering */
   png_bytep dither_index;           /* index translation for palette files */

   png_uint_16p hist;                /* histogram */

   png_charp time_buffer;            /* String to hold RFC 1123 time text */

   png_uint_32 free_me;       /* flags items libpng is responsible for freeing */

   png_voidp user_chunk_ptr;
   png_user_chunk_ptr read_user_chunk_fn; /* user read chunk handler */

   int num_chunk_list;
   png_bytep chunk_list;

   png_byte rgb_to_gray_status;

   png_uint_16 rgb_to_gray_red_coeff;
   png_uint_16 rgb_to_gray_green_coeff;
   png_uint_16 rgb_to_gray_blue_coeff;

   png_uint_32 mng_features_permitted;

   png_fixed_point int_gamma;

   png_byte filter_type;

   png_voidp mem_ptr;                /* user supplied struct for mem functions */
   png_malloc_ptr malloc_fn;         /* function for allocating memory */
   png_free_ptr free_fn;             /* function for freeing memory */

   png_bytep big_row_buf;         /* buffer to save current (unfiltered) row */


   png_bytep dither_sort;            /* working sort array */
   png_bytep index_to_palette;       /* where the original index currently is */
                                     /* in the palette */
   png_bytep palette_to_index;       /* which original index points to this */
                                     /* palette color */

   png_byte compression_type;

   png_uint_32 user_width_max;
   png_uint_32 user_height_max;

   png_unknown_chunk unknown_chunk;  /* storage for unknown chunk that the library doesn't recognize. */

   png_uint_32 old_big_row_buf_size, old_prev_row_size;  /* New members added in libpng-1.2.26 */

   png_charp chunkdata;  /* buffer for reading chunk data */
};


/* This triggers a compiler error in png.c, if png.c and png.h
 * do not agree upon the version number.
 */
typedef png_structp version_1_2_59;

typedef png_struct FAR * FAR * png_structpp;


#define PNG_FILLER_BEFORE 0
#define PNG_FILLER_AFTER 1

#define PNG_BACKGROUND_GAMMA_UNKNOWN 0
#define PNG_BACKGROUND_GAMMA_SCREEN  1
#define PNG_BACKGROUND_GAMMA_FILE    2
#define PNG_BACKGROUND_GAMMA_UNIQUE  3


#define PNG_CRC_DEFAULT       0  /* error/quit          warn/discard data */
#define PNG_CRC_ERROR_QUIT    1  /* error/quit          error/quit        */
#define PNG_CRC_WARN_DISCARD  2  /* (INVALID)           warn/discard data */
#define PNG_CRC_WARN_USE      3  /* warn/use data       warn/use data     */
#define PNG_CRC_QUIET_USE     4  /* quiet/use data      quiet/use data    */
#define PNG_CRC_NO_CHANGE     5  /* use current value   use current value */


#define PNG_NO_FILTERS     0x00
#define PNG_FILTER_NONE    0x08
#define PNG_FILTER_SUB     0x10
#define PNG_FILTER_UP      0x20
#define PNG_FILTER_AVG     0x40
#define PNG_FILTER_PAETH   0x80
#define PNG_ALL_FILTERS (PNG_FILTER_NONE | PNG_FILTER_SUB | PNG_FILTER_UP | PNG_FILTER_AVG | PNG_FILTER_PAETH)


#define PNG_FILTER_VALUE_NONE  0
#define PNG_FILTER_VALUE_SUB   1
#define PNG_FILTER_VALUE_UP    2
#define PNG_FILTER_VALUE_AVG   3
#define PNG_FILTER_VALUE_PAETH 4
#define PNG_FILTER_VALUE_LAST  5

#define PNG_FILTER_HEURISTIC_DEFAULT    0  /* Currently "UNWEIGHTED" */
#define PNG_FILTER_HEURISTIC_UNWEIGHTED 1  /* Used by libpng < 0.95 */
#define PNG_FILTER_HEURISTIC_WEIGHTED   2  /* Experimental feature */
#define PNG_FILTER_HEURISTIC_LAST       3  /* Not a valid value */


#define PNG_DESTROY_WILL_FREE_DATA 1
#define PNG_SET_WILL_FREE_DATA 1
#define PNG_USER_WILL_FREE_DATA 2
/* Flags for png_ptr->free_me and info_ptr->free_me */
#define PNG_FREE_HIST 0x0008
#define PNG_FREE_ICCP 0x0010
#define PNG_FREE_SPLT 0x0020
#define PNG_FREE_ROWS 0x0040
#define PNG_FREE_PCAL 0x0080
#define PNG_FREE_SCAL 0x0100
#define PNG_FREE_UNKN 0x0200
#define PNG_FREE_LIST 0x0400
#define PNG_FREE_PLTE 0x1000
#define PNG_FREE_TRNS 0x2000
#define PNG_FREE_TEXT 0x4000
#define PNG_FREE_ALL  0x7fff
#define PNG_FREE_MUL  0x4220 /* PNG_FREE_SPLT|PNG_FREE_TEXT|PNG_FREE_UNKN */

/* For use in png_set_keep_unknown, added to version 1.2.6 */
#define PNG_HANDLE_CHUNK_AS_DEFAULT   0
#define PNG_HANDLE_CHUNK_NEVER        1
#define PNG_HANDLE_CHUNK_IF_SAFE      2
#define PNG_HANDLE_CHUNK_ALWAYS       3

/* Added at libpng-1.2.34 and 1.4.0 */
#ifndef PNG_STRING_NEWLINE
#define PNG_STRING_NEWLINE "\n"
#endif


#ifdef __cplusplus
}
#endif

#endif /* PNG_VERSION_INFO_ONLY */

#endif /* LIBRARIES_PNG_H */
