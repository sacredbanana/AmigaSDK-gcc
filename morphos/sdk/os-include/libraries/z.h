#ifndef LIBRARIES_Z_H
#define LIBRARIES_Z_H

/*

	MorphOS Shared ZLib

	z.library include

	Copyright © 2003-2018 The MorphOS Development Team, All Rights Reserved.

*/


/*

	These first parts mimic zconf.h

*/

#include <sys/types.h>
#include <unistd.h>


#if defined(__GNUC__)
#ifndef __32BIT__
#define __32BIT__
#endif
#endif

#if defined(__STDC__) || defined(__cplusplus)
#ifndef STDC
#define STDC
#endif
#endif

#define OF(args) args

#undef MAX_MEM_LEVEL
#undef DEF_MEM_LEVEL
#define MAX_MEM_LEVEL 9
#define DEF_MEM_LEVEL 9

#undef MAX_WBITS
#undef DEF_WBITS
#define MAX_WBITS 15
#define DEF_WBITS 15

#define z_off_t  off_t
#define z_off64_t int64_t

typedef unsigned char  Byte;
typedef unsigned int   uInt;
typedef unsigned long  uLong;

typedef Byte  Bytef;
typedef char  charf;
typedef int   intf;
typedef uInt  uIntf;
typedef uLong uLongf;

typedef void *voidpf;
typedef void *voidp;

typedef u_int32_t z_crc_t;

/*

	This part is a cleaned-up version of zlib.h

	For the documentation that was contained here, please see the
	original zlib distribution, or the documentation with the
	MorphOS SDK (when it's done)

*/


#ifdef __cplusplus
extern "C" {
#endif


#define ZLIB_VERSION "1.2.11"
#define ZLIB_VERNUM	 0x12b0
#define ZLIB_VER_MAJOR 1
#define ZLIB_VER_MINOR 2
#define ZLIB_VER_REVISION 11
#define ZLIB_VER_SUBREVISION 0


typedef voidpf (*alloc_func)(voidpf opaque, uInt items, uInt size);
typedef void   (*free_func)(voidpf opaque, voidpf address);

typedef unsigned (*in_func)(void *, unsigned char **);
typedef int (*out_func)(void *, unsigned char *, unsigned);

struct internal_state;

typedef struct z_stream_s {
	Bytef    *next_in;  /* next input byte */
	uInt     avail_in;  /* number of bytes available at next_in */
	uLong    total_in;  /* total nb of input bytes read so far */

	Bytef    *next_out; /* next output byte should be put there */
	uInt     avail_out; /* remaining free space at next_out */
	uLong    total_out; /* total nb of bytes output so far */

	char     *msg;      /* last error message, NULL if no error */
	struct internal_state *state; /* not visible by applications */

	alloc_func zalloc;  /* used to allocate the internal state */
	free_func  zfree;   /* used to free the internal state */
	voidpf     opaque;  /* private data object passed to zalloc and zfree */

	int     data_type;  /* best guess about the data type: binary or text */
	uLong   adler;      /* adler32 value of the uncompressed data */
	uLong   reserved;   /* reserved for future use */
} z_stream;

typedef z_stream *z_streamp;

/*
     gzip header information passed to and from zlib routines.  See RFC 1952
  for more details on the meanings of these fields.
*/
typedef struct gz_header_s {
	int     text;       /* true if compressed data believed to be text */
	uLong   time;       /* modification time */
	int     xflags;     /* extra flags (not used when writing a gzip file) */
	int     os;         /* operating system */
	Bytef   *extra;     /* pointer to extra field or Z_NULL if none */
	uInt    extra_len;  /* extra field length (valid if extra != Z_NULL) */
	uInt    extra_max;  /* space at extra (only when reading header) */
	Bytef   *name;      /* pointer to zero-terminated file name or Z_NULL */
	uInt    name_max;   /* space at name (only when reading header) */
	Bytef   *comment;   /* pointer to zero-terminated comment or Z_NULL */
	uInt    comm_max;   /* space at comment (only when reading header) */
	int     hcrc;       /* true if there was or will be a header crc */
	int     done;       /* true when done reading gzip header (not used
	                       when writing a gzip file) */
} gz_header;

typedef gz_header *gz_headerp;

typedef voidp gzFile;


#define Z_NO_FLUSH      0
#define Z_PARTIAL_FLUSH 1
#define Z_SYNC_FLUSH    2
#define Z_FULL_FLUSH    3
#define Z_FINISH        4
#define Z_BLOCK         5
#define Z_TREES         6

#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_ERRNO        (-1)
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR   (-3)
#define Z_MEM_ERROR    (-4)
#define Z_BUF_ERROR    (-5)
#define Z_VERSION_ERROR (-6)

#define Z_NO_COMPRESSION         0
#define Z_BEST_SPEED             1
#define Z_BEST_COMPRESSION       9
#define Z_DEFAULT_COMPRESSION  (-1)

#define Z_FILTERED            1
#define Z_HUFFMAN_ONLY        2
#define Z_RLE                 3
#define Z_FIXED               4
#define Z_DEFAULT_STRATEGY    0

#define Z_BINARY   0
#define Z_TEXT     1
#define Z_ASCII    Z_TEXT   /* for compatibility with 1.2.2 and earlier */
#define Z_UNKNOWN  2

#define Z_DEFLATED   8

#define Z_NULL  0  /* for initializing zalloc, zfree, opaque */


#define zlib_version zlibVersion()


typedef unsigned (*blast_in)(void *how, unsigned char **buf);
typedef int (*blast_out)(void *how, unsigned char *buf, unsigned len);


#ifdef __cplusplus
}
#endif

#endif /* LIBRARIES_Z_H */
