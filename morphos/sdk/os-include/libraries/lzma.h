#ifndef LIBRARIES_LZMA_H
#define LIBRARIES_LZMA_H

/*

	MorphOS Shared LZMALib

	lzma.library include

	Copyright © 2017-2021 The MorphOS Development Team, All Rights Reserved.

*/

/*

	This is a merged and cleaned-up version of lzma API includes

	For the documentation that was contained here, please see the
	original liblzma distribution, or the documentation with the
	MorphOS SDK (when it's done)

*/

#ifndef LZMA_MANUAL_HEADERS
#include <stddef.h>
#include <stdint.h>
#endif /* LZMA_MANUAL_HEADERS */

#pragma pack(8)

#ifndef LZMA_API_IMPORT
#	define LZMA_API_IMPORT
#endif
#ifndef LZMA_API_CALL
#	define LZMA_API_CALL
#endif
#ifndef LZMA_API
#	define LZMA_API(type) type
#endif
#ifndef lzma_nothrow
#	if defined(__cplusplus)
#		define lzma_nothrow throw()
#	elif __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3)
#		define lzma_nothrow __attribute__((__nothrow__))
#	else
#		define lzma_nothrow
#	endif
#endif
#if __GNUC__ >= 3
#	ifndef lzma_attribute
#		define lzma_attribute(attr) __attribute__(attr)
#	endif
#	ifndef lzma_attr_warn_unused_result
#		if __GNUC__ == 3 && __GNUC_MINOR__ < 4
#			define lzma_attr_warn_unused_result
#		endif
#	endif
#else
#	ifndef lzma_attribute
#		define lzma_attribute(attr)
#	endif
#endif
#ifndef lzma_attr_pure
#	define lzma_attr_pure lzma_attribute((__pure__))
#endif
#ifndef lzma_attr_const
#	define lzma_attr_const lzma_attribute((__const__))
#endif
#ifndef lzma_attr_warn_unused_result
#	define lzma_attr_warn_unused_result \
		lzma_attribute((__warn_unused_result__))
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* version.h */
#ifdef LZMA_HAVE_VERSION_INFO
/*
	This information should not be used and is only provided for
	source level compatibility reasons. New code should call
	lzma_version_number() and lzma_version_string().
*/
#define LZMA_VERSION_MAJOR 5
#define LZMA_VERSION_MINOR 2
#define LZMA_VERSION_PATCH 5
#define LZMA_VERSION_STABILITY LZMA_VERSION_STABILITY_STABLE
#ifndef LZMA_VERSION_COMMIT
#	define LZMA_VERSION_COMMIT ""
#endif
#define LZMA_VERSION_STABILITY_ALPHA 0
#define LZMA_VERSION_STABILITY_BETA 1
#define LZMA_VERSION_STABILITY_STABLE 2
#define LZMA_VERSION (LZMA_VERSION_MAJOR * UINT32_C(10000000) \
		+ LZMA_VERSION_MINOR * UINT32_C(10000) \
		+ LZMA_VERSION_PATCH * UINT32_C(10) \
		+ LZMA_VERSION_STABILITY)
#if LZMA_VERSION_STABILITY == LZMA_VERSION_STABILITY_ALPHA
#	define LZMA_VERSION_STABILITY_STRING "alpha"
#elif LZMA_VERSION_STABILITY == LZMA_VERSION_STABILITY_BETA
#	define LZMA_VERSION_STABILITY_STRING "beta"
#elif LZMA_VERSION_STABILITY == LZMA_VERSION_STABILITY_STABLE
#	define LZMA_VERSION_STABILITY_STRING ""
#else
#	error Incorrect LZMA_VERSION_STABILITY
#endif
#define LZMA_VERSION_STRING_C_(major, minor, patch, stability, commit) \
		#major "." #minor "." #patch stability commit
#define LZMA_VERSION_STRING_C(major, minor, patch, stability, commit) \
		LZMA_VERSION_STRING_C_(major, minor, patch, stability, commit)
#define LZMA_VERSION_STRING LZMA_VERSION_STRING_C( \
		LZMA_VERSION_MAJOR, LZMA_VERSION_MINOR, \
		LZMA_VERSION_PATCH, LZMA_VERSION_STABILITY_STRING, \
		LZMA_VERSION_COMMIT)
#endif

/* base.h */
typedef unsigned char lzma_bool;
typedef enum {
	LZMA_RESERVED_ENUM      = 0
} lzma_reserved_enum;
typedef enum {
	LZMA_OK                 = 0,
	LZMA_STREAM_END         = 1,
	LZMA_NO_CHECK           = 2,
	LZMA_UNSUPPORTED_CHECK  = 3,
	LZMA_GET_CHECK          = 4,
	LZMA_MEM_ERROR          = 5,
	LZMA_MEMLIMIT_ERROR     = 6,
	LZMA_FORMAT_ERROR       = 7,
	LZMA_OPTIONS_ERROR      = 8,
	LZMA_DATA_ERROR         = 9,
	LZMA_BUF_ERROR          = 10,
	LZMA_PROG_ERROR         = 11,
} lzma_ret;
typedef enum {
	LZMA_RUN = 0,
	LZMA_SYNC_FLUSH = 1,
	LZMA_FULL_FLUSH = 2,
	LZMA_FULL_BARRIER = 4,
	LZMA_FINISH = 3
} lzma_action;
typedef struct {
	void *(LZMA_API_CALL *alloc)(void *opaque, size_t nmemb, size_t size);
	void (LZMA_API_CALL *free)(void *opaque, void *ptr);
	void *opaque;
} lzma_allocator;
typedef struct lzma_internal_s lzma_internal;
typedef struct {
	const uint8_t *next_in;
	size_t avail_in;
	uint64_t total_in;
	uint8_t *next_out;
	size_t avail_out;
	uint64_t total_out;
	const lzma_allocator *allocator;
	lzma_internal *internal;
	void *reserved_ptr1;
	void *reserved_ptr2;
	uint64_t reserved_int1;
	uint64_t reserved_int2;
	lzma_reserved_enum reserved_enum1;
	lzma_reserved_enum reserved_enum2;
} lzma_stream;
#define LZMA_STREAM_INIT \
	{ NULL, 0, 0, NULL, 0, 0, NULL, NULL, \
	NULL, NULL, 0, 0, LZMA_RESERVED_ENUM, LZMA_RESERVED_ENUM }

/* vli.h */
#define LZMA_VLI_MAX (UINT64_MAX / 2)
#define LZMA_VLI_UNKNOWN UINT64_MAX
#define LZMA_VLI_BYTES_MAX 9
#define LZMA_VLI_C(n) UINT64_C(n)
typedef uint64_t lzma_vli;
#define lzma_vli_is_valid(vli) \
	((vli) <= LZMA_VLI_MAX || (vli) == LZMA_VLI_UNKNOWN)

/* check.h */
typedef enum {
	LZMA_CHECK_NONE     = 0,
	LZMA_CHECK_CRC32    = 1,
	LZMA_CHECK_CRC64    = 4,
	LZMA_CHECK_SHA256   = 10
} lzma_check;
#define LZMA_CHECK_ID_MAX 15
#define LZMA_CHECK_SIZE_MAX 64

/* filter.h */
#define LZMA_FILTERS_MAX 4
typedef struct {
	lzma_vli id;
	void *options;
} lzma_filter;

/* bcj.h */
#define LZMA_FILTER_X86         LZMA_VLI_C(0x04)
#define LZMA_FILTER_POWERPC     LZMA_VLI_C(0x05)
#define LZMA_FILTER_IA64        LZMA_VLI_C(0x06)
#define LZMA_FILTER_ARM         LZMA_VLI_C(0x07)
#define LZMA_FILTER_ARMTHUMB    LZMA_VLI_C(0x08)
#define LZMA_FILTER_SPARC       LZMA_VLI_C(0x09)
typedef struct {
	uint32_t start_offset;
} lzma_options_bcj;

/* delta.h */
#define LZMA_FILTER_DELTA       LZMA_VLI_C(0x03)
typedef enum {
	LZMA_DELTA_TYPE_BYTE
} lzma_delta_type;
typedef struct {
	lzma_delta_type type;
	uint32_t dist;
#	define LZMA_DELTA_DIST_MIN 1
#	define LZMA_DELTA_DIST_MAX 256
	uint32_t reserved_int1;
	uint32_t reserved_int2;
	uint32_t reserved_int3;
	uint32_t reserved_int4;
	void *reserved_ptr1;
	void *reserved_ptr2;
} lzma_options_delta;

/* lzma.h */
#define LZMA_FILTER_LZMA1       LZMA_VLI_C(0x4000000000000001)
#define LZMA_FILTER_LZMA2       LZMA_VLI_C(0x21)
typedef enum {
	LZMA_MF_HC3     = 0x03,
	LZMA_MF_HC4     = 0x04,
	LZMA_MF_BT2     = 0x12,
	LZMA_MF_BT3     = 0x13,
	LZMA_MF_BT4     = 0x14
} lzma_match_finder;
typedef enum {
	LZMA_MODE_FAST = 1,
	LZMA_MODE_NORMAL = 2
} lzma_mode;
typedef struct {
	uint32_t dict_size;
#	define LZMA_DICT_SIZE_MIN       UINT32_C(4096)
#	define LZMA_DICT_SIZE_DEFAULT   (UINT32_C(1) << 23)
	const uint8_t *preset_dict;
	uint32_t preset_dict_size;
	uint32_t lc;
#	define LZMA_LCLP_MIN    0
#	define LZMA_LCLP_MAX    4
#	define LZMA_LC_DEFAULT  3
	uint32_t lp;
#	define LZMA_LP_DEFAULT  0
	uint32_t pb;
#	define LZMA_PB_MIN      0
#	define LZMA_PB_MAX      4
#	define LZMA_PB_DEFAULT  2
	lzma_mode mode;
	uint32_t nice_len;
	lzma_match_finder mf;
	uint32_t depth;
	void *reserved_ptr1;
	void *reserved_ptr2;
	uint32_t reserved_int1;
	uint32_t reserved_int2;
	uint32_t reserved_int3;
	uint32_t reserved_int4;
	uint32_t reserved_int5;
	uint32_t reserved_int6;
	uint32_t reserved_int7;
	uint32_t reserved_int8;
	lzma_reserved_enum reserved_enum1;
	lzma_reserved_enum reserved_enum2;
	lzma_reserved_enum reserved_enum3;
	lzma_reserved_enum reserved_enum4;
} lzma_options_lzma;

/* container.h */
#define LZMA_PRESET_DEFAULT     UINT32_C(6)
#define LZMA_PRESET_LEVEL_MASK  UINT32_C(0x1F)
#define LZMA_PRESET_EXTREME       (UINT32_C(1) << 31)
typedef struct {
	uint32_t flags;
	uint32_t threads;
	uint64_t block_size;
	uint32_t timeout;
	uint32_t preset;
	const lzma_filter *filters;
	lzma_check check;
	lzma_reserved_enum reserved_enum1;
	lzma_reserved_enum reserved_enum2;
	lzma_reserved_enum reserved_enum3;
	uint32_t reserved_int1;
	uint32_t reserved_int2;
	uint32_t reserved_int3;
	uint32_t reserved_int4;
	uint64_t reserved_int5;
	uint64_t reserved_int6;
	uint64_t reserved_int7;
	uint64_t reserved_int8;
	void *reserved_ptr1;
	void *reserved_ptr2;
	void *reserved_ptr3;
	void *reserved_ptr4;
} lzma_mt;
#define LZMA_TELL_NO_CHECK              UINT32_C(0x01)
#define LZMA_TELL_UNSUPPORTED_CHECK     UINT32_C(0x02)
#define LZMA_TELL_ANY_CHECK             UINT32_C(0x04)
#define LZMA_IGNORE_CHECK               UINT32_C(0x10)
#define LZMA_CONCATENATED               UINT32_C(0x08)

/* stream_flags.h */
#define LZMA_STREAM_HEADER_SIZE 12
typedef struct {
	uint32_t version;
	lzma_vli backward_size;
#	define LZMA_BACKWARD_SIZE_MIN 4
#	define LZMA_BACKWARD_SIZE_MAX (LZMA_VLI_C(1) << 34)
	lzma_check check;
	lzma_reserved_enum reserved_enum1;
	lzma_reserved_enum reserved_enum2;
	lzma_reserved_enum reserved_enum3;
	lzma_reserved_enum reserved_enum4;
	lzma_reserved_enum reserved_enum5;
	lzma_reserved_enum reserved_enum6;
	lzma_bool reserved_bool1;
	lzma_bool reserved_bool2;
	lzma_bool reserved_bool3;
	lzma_bool reserved_bool4;
	lzma_bool reserved_bool5;
	lzma_bool reserved_bool6;
	lzma_bool reserved_bool7;
	lzma_bool reserved_bool8;
	uint32_t reserved_int1;
	uint32_t reserved_int2;
	uint32_t reserved_int3;
	uint32_t reserved_int4;
} lzma_stream_flags;

/* block.h */
typedef struct {
	uint32_t version;
	uint32_t header_size;
#	define LZMA_BLOCK_HEADER_SIZE_MIN 8
#	define LZMA_BLOCK_HEADER_SIZE_MAX 1024
	lzma_check check;
	lzma_vli compressed_size;
	lzma_vli uncompressed_size;
	lzma_filter *filters;
	uint8_t raw_check[LZMA_CHECK_SIZE_MAX];
	void *reserved_ptr1;
	void *reserved_ptr2;
	void *reserved_ptr3;
	uint32_t reserved_int1;
	uint32_t reserved_int2;
	lzma_vli reserved_int3;
	lzma_vli reserved_int4;
	lzma_vli reserved_int5;
	lzma_vli reserved_int6;
	lzma_vli reserved_int7;
	lzma_vli reserved_int8;
	lzma_reserved_enum reserved_enum1;
	lzma_reserved_enum reserved_enum2;
	lzma_reserved_enum reserved_enum3;
	lzma_reserved_enum reserved_enum4;
	lzma_bool reserved_bool1;
	lzma_bool reserved_bool2;
	lzma_bool reserved_bool3;
	lzma_bool reserved_bool4;
	lzma_bool reserved_bool5;
	lzma_bool reserved_bool6;
	lzma_bool reserved_bool7;
	lzma_bool reserved_bool8;
} lzma_block;
#define lzma_block_header_size_decode(b) (((uint32_t)(b) + 1) * 4)

/* index.h */
typedef struct lzma_index_s lzma_index;
typedef struct {
	struct {
		const lzma_stream_flags *flags;
		const void *reserved_ptr1;
		const void *reserved_ptr2;
		const void *reserved_ptr3;
		lzma_vli number;
		lzma_vli block_count;
		lzma_vli compressed_offset;
		lzma_vli uncompressed_offset;
		lzma_vli compressed_size;
		lzma_vli uncompressed_size;
		lzma_vli padding;
		lzma_vli reserved_vli1;
		lzma_vli reserved_vli2;
		lzma_vli reserved_vli3;
		lzma_vli reserved_vli4;
	} stream;
	struct {
		lzma_vli number_in_file;
		lzma_vli compressed_file_offset;
		lzma_vli uncompressed_file_offset;
		lzma_vli number_in_stream;
		lzma_vli compressed_stream_offset;
		lzma_vli uncompressed_stream_offset;
		lzma_vli uncompressed_size;
		lzma_vli unpadded_size;
		lzma_vli total_size;
		lzma_vli reserved_vli1;
		lzma_vli reserved_vli2;
		lzma_vli reserved_vli3;
		lzma_vli reserved_vli4;
		const void *reserved_ptr1;
		const void *reserved_ptr2;
		const void *reserved_ptr3;
		const void *reserved_ptr4;
	} block;
	union {
		const void *p;
		size_t s;
		lzma_vli v;
	} internal[6];
} lzma_index_iter;
typedef enum {
	LZMA_INDEX_ITER_ANY             = 0,
	LZMA_INDEX_ITER_STREAM          = 1,
	LZMA_INDEX_ITER_BLOCK           = 2,
	LZMA_INDEX_ITER_NONEMPTY_BLOCK  = 3
} lzma_index_iter_mode;

/* index_hash.h */
typedef struct lzma_index_hash_s lzma_index_hash;

#ifdef __cplusplus
}
#endif

#pragma pack()

#endif /* LIBRARIES_LZMA_H */
