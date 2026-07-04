#ifndef LIBRARIES_ZSTD_H
#define LIBRARIES_ZSTD_H

/*
	zstd.library headers

	Generated from the official Zstandard source code for the MorphOS SDK.
	Please refer to SYS:Docs/Licenses/Zstandard for license information.
*/

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under both the BSD-style license (found in the
 * LICENSE file in the root directory of this source tree) and the GPLv2 (found
 * in the COPYING file in the root directory of this source tree).
 * You may select, at your option, one of the above-listed licenses.
 */

#ifndef ZSTD_H_235446
#define ZSTD_H_235446


/* ======   Dependencies   ======*/
#include <stddef.h>   /* size_t */

#if defined(ZSTD_STATIC_LINKING_ONLY) && !defined(ZSTD_H_ZSTD_STATIC_LINKING_ONLY)
#include <limits.h>   /* INT_MAX */
#endif /* ZSTD_STATIC_LINKING_ONLY */

#if defined (__cplusplus)
extern "C" {
#endif

/* =====   ZSTDLIB_API : control library symbols visibility   ===== */
#ifndef ZSTDLIB_VISIBLE
   /* Backwards compatibility with old macro name */
#  ifdef ZSTDLIB_VISIBILITY
#    define ZSTDLIB_VISIBLE ZSTDLIB_VISIBILITY
#  elif defined(__GNUC__) && (__GNUC__ >= 4) && !defined(__MINGW32__)
#    define ZSTDLIB_VISIBLE __attribute__ ((visibility ("default")))
#  else
#    define ZSTDLIB_VISIBLE
#  endif
#endif

#ifndef ZSTDLIB_HIDDEN
#  if defined(__GNUC__) && (__GNUC__ >= 4) && !defined(__MINGW32__)
#    define ZSTDLIB_HIDDEN __attribute__ ((visibility ("hidden")))
#  else
#    define ZSTDLIB_HIDDEN
#  endif
#endif

#if defined(ZSTD_DLL_EXPORT) && (ZSTD_DLL_EXPORT==1)
#  define ZSTDLIB_API __declspec(dllexport) ZSTDLIB_VISIBLE
#elif defined(ZSTD_DLL_IMPORT) && (ZSTD_DLL_IMPORT==1)
#  define ZSTDLIB_API __declspec(dllimport) ZSTDLIB_VISIBLE /* It isn't required but allows to generate better code, saving a function pointer load from the IAT and an indirect jump.*/
#else
#  define ZSTDLIB_API ZSTDLIB_VISIBLE
#endif

/* Deprecation warnings :
 * Should these warnings be a problem, it is generally possible to disable them,
 * typically with -Wno-deprecated-declarations for gcc or _CRT_SECURE_NO_WARNINGS in Visual.
 * Otherwise, it's also possible to define ZSTD_DISABLE_DEPRECATE_WARNINGS.
 */
#ifdef ZSTD_DISABLE_DEPRECATE_WARNINGS
#  define ZSTD_DEPRECATED(message) /* disable deprecation warnings */
#else
#  if defined (__cplusplus) && (__cplusplus >= 201402) /* C++14 or greater */
#    define ZSTD_DEPRECATED(message) [[deprecated(message)]]
#  elif (defined(GNUC) && (GNUC > 4 || (GNUC == 4 && GNUC_MINOR >= 5))) || defined(__clang__) || defined(__IAR_SYSTEMS_ICC__)
#    define ZSTD_DEPRECATED(message) __attribute__((deprecated(message)))
#  elif defined(__GNUC__) && (__GNUC__ >= 3)
#    define ZSTD_DEPRECATED(message) __attribute__((deprecated))
#  elif defined(_MSC_VER)
#    define ZSTD_DEPRECATED(message) __declspec(deprecated(message))
#  else
#    pragma message("WARNING: You need to implement ZSTD_DEPRECATED for this compiler")
#    define ZSTD_DEPRECATED(message)
#  endif
#endif /* ZSTD_DISABLE_DEPRECATE_WARNINGS */


/*******************************************************************************
  Introduction

  zstd, short for Zstandard, is a fast lossless compression algorithm, targeting
  real-time compression scenarios at zlib-level and better compression ratios.
  The zstd compression library provides in-memory compression and decompression
  functions.

  The library supports regular compression levels from 1 up to ZSTD_maxCLevel(),
  which is currently 22. Levels >= 20, labeled `--ultra`, should be used with
  caution, as they require more memory. The library also offers negative
  compression levels, which extend the range of speed vs. ratio preferences.
  The lower the level, the faster the speed (at the cost of compression).

  Compression can be done in:
    - a single step (described as Simple API)
    - a single step, reusing a context (described as Explicit context)
    - unbounded multiple steps (described as Streaming compression)

  The compression ratio achievable on small data can be highly improved using
  a dictionary. Dictionary compression can be performed in:
    - a single step (described as Simple dictionary API)
    - a single step, reusing a dictionary (described as Bulk-processing
      dictionary API)

  Advanced experimental functions can be accessed using
  `#define ZSTD_STATIC_LINKING_ONLY` before including zstd.h.

  Advanced experimental APIs should never be used with a dynamically-linked
  library. They are not "stable"; their definitions or signatures may change in
  the future. Only static linking is allowed.
*******************************************************************************/

/*------   Version   ------*/
#define ZSTD_VERSION_MAJOR    1
#define ZSTD_VERSION_MINOR    5
#define ZSTD_VERSION_RELEASE  7
#define ZSTD_VERSION_NUMBER  (ZSTD_VERSION_MAJOR *100*100 + ZSTD_VERSION_MINOR *100 + ZSTD_VERSION_RELEASE)

/*! ZSTD_versionNumber() :
 *  Return runtime library version, the value is (MAJOR*100*100 + MINOR*100 + RELEASE). */
/* ZSTDLIB_API unsigned ZSTD_versionNumber(void); */

#define ZSTD_LIB_VERSION ZSTD_VERSION_MAJOR.ZSTD_VERSION_MINOR.ZSTD_VERSION_RELEASE
#define ZSTD_QUOTE(str) #str
#define ZSTD_EXPAND_AND_QUOTE(str) ZSTD_QUOTE(str)
#define ZSTD_VERSION_STRING ZSTD_EXPAND_AND_QUOTE(ZSTD_LIB_VERSION)

/*! ZSTD_versionString() :
 *  Return runtime library version, like "1.4.5". Requires v1.3.0+. */
/* ZSTDLIB_API const char* ZSTD_versionString(void); */

/* *************************************
 *  Default constant
 ***************************************/
#ifndef ZSTD_CLEVEL_DEFAULT
#  define ZSTD_CLEVEL_DEFAULT 3
#endif

/* *************************************
 *  Constants
 ***************************************/

/* All magic numbers are supposed read/written to/from files/memory using little-endian convention */
#define ZSTD_MAGICNUMBER            0xFD2FB528    /* valid since v0.8.0 */
#define ZSTD_MAGIC_DICTIONARY       0xEC30A437    /* valid since v0.7.0 */
#define ZSTD_MAGIC_SKIPPABLE_START  0x184D2A50    /* all 16 values, from 0x184D2A50 to 0x184D2A5F, signal the beginning of a skippable frame */
#define ZSTD_MAGIC_SKIPPABLE_MASK   0xFFFFFFF0

#define ZSTD_BLOCKSIZELOG_MAX  17
#define ZSTD_BLOCKSIZE_MAX     (1<<ZSTD_BLOCKSIZELOG_MAX)


/***************************************
*  Simple Core API
***************************************/
/*! ZSTD_compress() :
 *  Compresses `src` content as a single zstd compressed frame into already allocated `dst`.
 *  NOTE: Providing `dstCapacity >= ZSTD_compressBound(srcSize)` guarantees that zstd will have
 *        enough space to successfully compress the data.
 *  @return : compressed size written into `dst` (<= `dstCapacity),
 *            or an error code if it fails (which can be tested using ZSTD_isError()). */
/* ZSTDLIB_API size_t ZSTD_compress( void* dst, size_t dstCapacity,
                            const void* src, size_t srcSize,
                                  int compressionLevel); */

/*! ZSTD_decompress() :
 * `compressedSize` : must be the _exact_ size of some number of compressed and/or skippable frames.
 *  Multiple compressed frames can be decompressed at once with this method.
 *  The result will be the concatenation of all decompressed frames, back to back.
 * `dstCapacity` is an upper bound of originalSize to regenerate.
 *  First frame's decompressed size can be extracted using ZSTD_getFrameContentSize().
 *  If maximum upper bound isn't known, prefer using streaming mode to decompress data.
 * @return : the number of bytes decompressed into `dst` (<= `dstCapacity`),
 *           or an errorCode if it fails (which can be tested using ZSTD_isError()). */
/* ZSTDLIB_API size_t ZSTD_decompress( void* dst, size_t dstCapacity,
                              const void* src, size_t compressedSize); */


/*======  Decompression helper functions  ======*/

/*! ZSTD_getFrameContentSize() : requires v1.3.0+
 * `src` should point to the start of a ZSTD encoded frame.
 * `srcSize` must be at least as large as the frame header.
 *           hint : any size >= `ZSTD_frameHeaderSize_max` is large enough.
 * @return : - decompressed size of `src` frame content, if known
 *           - ZSTD_CONTENTSIZE_UNKNOWN if the size cannot be determined
 *           - ZSTD_CONTENTSIZE_ERROR if an error occurred (e.g. invalid magic number, srcSize too small)
 *  note 1 : a 0 return value means the frame is valid but "empty".
 *           When invoking this method on a skippable frame, it will return 0.
 *  note 2 : decompressed size is an optional field, it may not be present (typically in streaming mode).
 *           When `return==ZSTD_CONTENTSIZE_UNKNOWN`, data to decompress could be any size.
 *           In which case, it's necessary to use streaming mode to decompress data.
 *           Optionally, application can rely on some implicit limit,
 *           as ZSTD_decompress() only needs an upper bound of decompressed size.
 *           (For example, data could be necessarily cut into blocks <= 16 KB).
 *  note 3 : decompressed size is always present when compression is completed using single-pass functions,
 *           such as ZSTD_compress(), ZSTD_compressCCtx() ZSTD_compress_usingDict() or ZSTD_compress_usingCDict().
 *  note 4 : decompressed size can be very large (64-bits value),
 *           potentially larger than what local system can handle as a single memory segment.
 *           In which case, it's necessary to use streaming mode to decompress data.
 *  note 5 : If source is untrusted, decompressed size could be wrong or intentionally modified.
 *           Always ensure return value fits within application's authorized limits.
 *           Each application can set its own limits.
 *  note 6 : This function replaces ZSTD_getDecompressedSize() */
#define ZSTD_CONTENTSIZE_UNKNOWN (0ULL - 1)
#define ZSTD_CONTENTSIZE_ERROR   (0ULL - 2)
/* ZSTDLIB_API unsigned long long ZSTD_getFrameContentSize(const void *src, size_t srcSize); */

/*! ZSTD_getDecompressedSize() (obsolete):
 *  This function is now obsolete, in favor of ZSTD_getFrameContentSize().
 *  Both functions work the same way, but ZSTD_getDecompressedSize() blends
 *  "empty", "unknown" and "error" results to the same return value (0),
 *  while ZSTD_getFrameContentSize() gives them separate return values.
 * @return : decompressed size of `src` frame content _if known and not empty_, 0 otherwise. *
/* ZSTD_DEPRECATED("Replaced by ZSTD_getFrameContentSize") */
/* ZSTDLIB_API unsigned long long ZSTD_getDecompressedSize(const void* src, size_t srcSize); */

/*! ZSTD_findFrameCompressedSize() : Requires v1.4.0+
 * `src` should point to the start of a ZSTD frame or skippable frame.
 * `srcSize` must be >= first frame size
 * @return : the compressed size of the first frame starting at `src`,
 *           suitable to pass as `srcSize` to `ZSTD_decompress` or similar,
 *           or an error code if input is invalid
 *  Note 1: this method is called _find*() because it's not enough to read the header,
 *          it may have to scan through the frame's content, to reach its end.
 *  Note 2: this method also works with Skippable Frames. In which case,
 *          it returns the size of the complete skippable frame,
 *          which is always equal to its content size + 8 bytes for headers. */
/* ZSTDLIB_API size_t ZSTD_findFrameCompressedSize(const void* src, size_t srcSize); */


/*======  Compression helper functions  ======*/

/*! ZSTD_compressBound() :
 * maximum compressed size in worst case single-pass scenario.
 * When invoking `ZSTD_compress()`, or any other one-pass compression function,
 * it's recommended to provide @dstCapacity >= ZSTD_compressBound(srcSize)
 * as it eliminates one potential failure scenario,
 * aka not enough room in dst buffer to write the compressed frame.
 * Note : ZSTD_compressBound() itself can fail, if @srcSize >= ZSTD_MAX_INPUT_SIZE .
 *        In which case, ZSTD_compressBound() will return an error code
 *        which can be tested using ZSTD_isError().
 *
 * ZSTD_COMPRESSBOUND() :
 * same as ZSTD_compressBound(), but as a macro.
 * It can be used to produce constants, which can be useful for static allocation,
 * for example to size a static array on stack.
 * Will produce constant value 0 if srcSize is too large.
 */
#define ZSTD_MAX_INPUT_SIZE ((sizeof(size_t)==8) ? 0xFF00FF00FF00FF00ULL : 0xFF00FF00U)
#define ZSTD_COMPRESSBOUND(srcSize)   (((size_t)(srcSize) >= ZSTD_MAX_INPUT_SIZE) ? 0 : (srcSize) + ((srcSize)>>8) + (((srcSize) < (128<<10)) ? (((128<<10) - (srcSize)) >> 11) /* margin, from 64 to 0 */ : 0))  /* this formula ensures that bound(A) + bound(B) <= bound(A+B) as long as A and B >= 128 KB */
/* ZSTDLIB_API size_t ZSTD_compressBound(size_t srcSize); */ /*!< maximum compressed size in worst case single-pass scenario */


/*======  Error helper functions  ======*/
/* ZSTD_isError() :
 * Most ZSTD_* functions returning a size_t value can be tested for error,
 * using ZSTD_isError().
 * @return 1 if error, 0 otherwise
 */
/* ZSTDLIB_API unsigned     ZSTD_isError(size_t result); */      /*!< tells if a `size_t` function result is an error code */
/* ZSTDLIB_API ZSTD_ErrorCode ZSTD_getErrorCode(size_t functionResult); */ /* convert a result into an error code, which can be compared to error enum list */
/* ZSTDLIB_API const char*  ZSTD_getErrorName(size_t result); */ /*!< provides readable string from a function result */
/* ZSTDLIB_API int          ZSTD_minCLevel(void); */             /*!< minimum negative compression level allowed, requires v1.4.0+ */
/* ZSTDLIB_API int          ZSTD_maxCLevel(void); */             /*!< maximum compression level available */
/* ZSTDLIB_API int          ZSTD_defaultCLevel(void); */         /*!< default compression level, specified by ZSTD_CLEVEL_DEFAULT, requires v1.5.0+ */


/***************************************
*  Explicit context
***************************************/
/*= Compression context
 *  When compressing many times,
 *  it is recommended to allocate a compression context just once,
 *  and reuse it for each successive compression operation.
 *  This will make the workload easier for system's memory.
 *  Note : re-using context is just a speed / resource optimization.
 *         It doesn't change the compression ratio, which remains identical.
 *  Note 2: For parallel execution in multi-threaded environments,
 *         use one different context per thread .
 */
typedef struct ZSTD_CCtx_s ZSTD_CCtx;
/* ZSTDLIB_API ZSTD_CCtx* ZSTD_createCCtx(void); */
/* ZSTDLIB_API size_t     ZSTD_freeCCtx(ZSTD_CCtx* cctx); */  /* compatible with NULL pointer */

/*! ZSTD_compressCCtx() :
 *  Same as ZSTD_compress(), using an explicit ZSTD_CCtx.
 *  Important : in order to mirror `ZSTD_compress()` behavior,
 *  this function compresses at the requested compression level,
 *  __ignoring any other advanced parameter__ .
 *  If any advanced parameter was set using the advanced API,
 *  they will all be reset. Only @compressionLevel remains.
 */
/* ZSTDLIB_API size_t ZSTD_compressCCtx(ZSTD_CCtx* cctx,
                                     void* dst, size_t dstCapacity,
                               const void* src, size_t srcSize,
                                     int compressionLevel); */

/*= Decompression context
 *  When decompressing many times,
 *  it is recommended to allocate a context only once,
 *  and reuse it for each successive compression operation.
 *  This will make workload friendlier for system's memory.
 *  Use one context per thread for parallel execution. */
typedef struct ZSTD_DCtx_s ZSTD_DCtx;
/* ZSTDLIB_API ZSTD_DCtx* ZSTD_createDCtx(void); */
/* ZSTDLIB_API size_t     ZSTD_freeDCtx(ZSTD_DCtx* dctx); */  /* accept NULL pointer */

/*! ZSTD_decompressDCtx() :
 *  Same as ZSTD_decompress(),
 *  requires an allocated ZSTD_DCtx.
 *  Compatible with sticky parameters (see below).
 */
/* ZSTDLIB_API size_t ZSTD_decompressDCtx(ZSTD_DCtx* dctx,
                                       void* dst, size_t dstCapacity,
                                 const void* src, size_t srcSize); */


/*********************************************
*  Advanced compression API (Requires v1.4.0+)
**********************************************/

/* API design :
 *   Parameters are pushed one by one into an existing context,
 *   using ZSTD_CCtx_set*() functions.
 *   Pushed parameters are sticky : they are valid for next compressed frame, and any subsequent frame.
 *   "sticky" parameters are applicable to `ZSTD_compress2()` and `ZSTD_compressStream*()` !
 *   __They do not apply to one-shot variants such as ZSTD_compressCCtx()__ .
 *
 *   It's possible to reset all parameters to "default" using ZSTD_CCtx_reset().
 *
 *   This API supersedes all other "advanced" API entry points in the experimental section.
 *   In the future, we expect to remove API entry points from experimental which are redundant with this API.
 */


/* Compression strategies, listed from fastest to strongest */
typedef enum { ZSTD_fast=1,
               ZSTD_dfast=2,
               ZSTD_greedy=3,
               ZSTD_lazy=4,
               ZSTD_lazy2=5,
               ZSTD_btlazy2=6,
               ZSTD_btopt=7,
               ZSTD_btultra=8,
               ZSTD_btultra2=9
               /* note : new strategies _might_ be added in the future.
                         Only the order (from fast to strong) is guaranteed */
} ZSTD_strategy;

typedef enum {

    /* compression parameters
     * Note: When compressing with a ZSTD_CDict these parameters are superseded
     * by the parameters used to construct the ZSTD_CDict.
     * See ZSTD_CCtx_refCDict() for more info (superseded-by-cdict). */
    ZSTD_c_compressionLevel=100, /* Set compression parameters according to pre-defined cLevel table.
                              * Note that exact compression parameters are dynamically determined,
                              * depending on both compression level and srcSize (when known).
                              * Default level is ZSTD_CLEVEL_DEFAULT==3.
                              * Special: value 0 means default, which is controlled by ZSTD_CLEVEL_DEFAULT.
                              * Note 1 : it's possible to pass a negative compression level.
                              * Note 2 : setting a level does not automatically set all other compression parameters
                              *   to default. Setting this will however eventually dynamically impact the compression
                              *   parameters which have not been manually set. The manually set
                              *   ones will 'stick'. */
    /* Advanced compression parameters :
     * It's possible to pin down compression parameters to some specific values.
     * In which case, these values are no longer dynamically selected by the compressor */
    ZSTD_c_windowLog=101,    /* Maximum allowed back-reference distance, expressed as power of 2.
                              * This will set a memory budget for streaming decompression,
                              * with larger values requiring more memory
                              * and typically compressing more.
                              * Must be clamped between ZSTD_WINDOWLOG_MIN and ZSTD_WINDOWLOG_MAX.
                              * Special: value 0 means "use default windowLog".
                              * Note: Using a windowLog greater than ZSTD_WINDOWLOG_LIMIT_DEFAULT
                              *       requires explicitly allowing such size at streaming decompression stage. */
    ZSTD_c_hashLog=102,      /* Size of the initial probe table, as a power of 2.
                              * Resulting memory usage is (1 << (hashLog+2)).
                              * Must be clamped between ZSTD_HASHLOG_MIN and ZSTD_HASHLOG_MAX.
                              * Larger tables improve compression ratio of strategies <= dFast,
                              * and improve speed of strategies > dFast.
                              * Special: value 0 means "use default hashLog". */
    ZSTD_c_chainLog=103,     /* Size of the multi-probe search table, as a power of 2.
                              * Resulting memory usage is (1 << (chainLog+2)).
                              * Must be clamped between ZSTD_CHAINLOG_MIN and ZSTD_CHAINLOG_MAX.
                              * Larger tables result in better and slower compression.
                              * This parameter is useless for "fast" strategy.
                              * It's still useful when using "dfast" strategy,
                              * in which case it defines a secondary probe table.
                              * Special: value 0 means "use default chainLog". */
    ZSTD_c_searchLog=104,    /* Number of search attempts, as a power of 2.
                              * More attempts result in better and slower compression.
                              * This parameter is useless for "fast" and "dFast" strategies.
                              * Special: value 0 means "use default searchLog". */
    ZSTD_c_minMatch=105,     /* Minimum size of searched matches.
                              * Note that Zstandard can still find matches of smaller size,
                              * it just tweaks its search algorithm to look for this size and larger.
                              * Larger values increase compression and decompression speed, but decrease ratio.
                              * Must be clamped between ZSTD_MINMATCH_MIN and ZSTD_MINMATCH_MAX.
                              * Note that currently, for all strategies < btopt, effective minimum is 4.
                              *                    , for all strategies > fast, effective maximum is 6.
                              * Special: value 0 means "use default minMatchLength". */
    ZSTD_c_targetLength=106, /* Impact of this field depends on strategy.
                              * For strategies btopt, btultra & btultra2:
                              *     Length of Match considered "good enough" to stop search.
                              *     Larger values make compression stronger, and slower.
                              * For strategy fast:
                              *     Distance between match sampling.
                              *     Larger values make compression faster, and weaker.
                              * Special: value 0 means "use default targetLength". */
    ZSTD_c_strategy=107,     /* See ZSTD_strategy enum definition.
                              * The higher the value of selected strategy, the more complex it is,
                              * resulting in stronger and slower compression.
                              * Special: value 0 means "use default strategy". */

    ZSTD_c_targetCBlockSize=130, /* v1.5.6+
                                  * Attempts to fit compressed block size into approximately targetCBlockSize.
                                  * Bound by ZSTD_TARGETCBLOCKSIZE_MIN and ZSTD_TARGETCBLOCKSIZE_MAX.
                                  * Note that it's not a guarantee, just a convergence target (default:0).
                                  * No target when targetCBlockSize == 0.
                                  * This is helpful in low bandwidth streaming environments to improve end-to-end latency,
                                  * when a client can make use of partial documents (a prominent example being Chrome).
                                  * Note: this parameter is stable since v1.5.6.
                                  * It was present as an experimental parameter in earlier versions,
                                  * but it's not recommended using it with earlier library versions
                                  * due to massive performance regressions.
                                  */
    /* LDM mode parameters */
    ZSTD_c_enableLongDistanceMatching=160, /* Enable long distance matching.
                                     * This parameter is designed to improve compression ratio
                                     * for large inputs, by finding large matches at long distance.
                                     * It increases memory usage and window size.
                                     * Note: enabling this parameter increases default ZSTD_c_windowLog to 128 MB
                                     * except when expressly set to a different value.
                                     * Note: will be enabled by default if ZSTD_c_windowLog >= 128 MB and
                                     * compression strategy >= ZSTD_btopt (== compression level 16+) */
    ZSTD_c_ldmHashLog=161,   /* Size of the table for long distance matching, as a power of 2.
                              * Larger values increase memory usage and compression ratio,
                              * but decrease compression speed.
                              * Must be clamped between ZSTD_HASHLOG_MIN and ZSTD_HASHLOG_MAX
                              * default: windowlog - 7.
                              * Special: value 0 means "automatically determine hashlog". */
    ZSTD_c_ldmMinMatch=162,  /* Minimum match size for long distance matcher.
                              * Larger/too small values usually decrease compression ratio.
                              * Must be clamped between ZSTD_LDM_MINMATCH_MIN and ZSTD_LDM_MINMATCH_MAX.
                              * Special: value 0 means "use default value" (default: 64). */
    ZSTD_c_ldmBucketSizeLog=163, /* Log size of each bucket in the LDM hash table for collision resolution.
                              * Larger values improve collision resolution but decrease compression speed.
                              * The maximum value is ZSTD_LDM_BUCKETSIZELOG_MAX.
                              * Special: value 0 means "use default value" (default: 3). */
    ZSTD_c_ldmHashRateLog=164, /* Frequency of inserting/looking up entries into the LDM hash table.
                              * Must be clamped between 0 and (ZSTD_WINDOWLOG_MAX - ZSTD_HASHLOG_MIN).
                              * Default is MAX(0, (windowLog - ldmHashLog)), optimizing hash table usage.
                              * Larger values improve compression speed.
                              * Deviating far from default value will likely result in a compression ratio decrease.
                              * Special: value 0 means "automatically determine hashRateLog". */

    /* frame parameters */
    ZSTD_c_contentSizeFlag=200, /* Content size will be written into frame header _whenever known_ (default:1)
                              * Content size must be known at the beginning of compression.
                              * This is automatically the case when using ZSTD_compress2(),
                              * For streaming scenarios, content size must be provided with ZSTD_CCtx_setPledgedSrcSize() */
    ZSTD_c_checksumFlag=201, /* A 32-bits checksum of content is written at end of frame (default:0) */
    ZSTD_c_dictIDFlag=202,   /* When applicable, dictionary's ID is written into frame header (default:1) */

    /* multi-threading parameters */
    /* These parameters are only active if multi-threading is enabled (compiled with build macro ZSTD_MULTITHREAD).
     * Otherwise, trying to set any other value than default (0) will be a no-op and return an error.
     * In a situation where it's unknown if the linked library supports multi-threading or not,
     * setting ZSTD_c_nbWorkers to any value >= 1 and consulting the return value provides a quick way to check this property.
     */
    ZSTD_c_nbWorkers=400,    /* Select how many threads will be spawned to compress in parallel.
                              * When nbWorkers >= 1, triggers asynchronous mode when invoking ZSTD_compressStream*() :
                              * ZSTD_compressStream*() consumes input and flush output if possible, but immediately gives back control to caller,
                              * while compression is performed in parallel, within worker thread(s).
                              * (note : a strong exception to this rule is when first invocation of ZSTD_compressStream2() sets ZSTD_e_end :
                              *  in which case, ZSTD_compressStream2() delegates to ZSTD_compress2(), which is always a blocking call).
                              * More workers improve speed, but also increase memory usage.
                              * Default value is `0`, aka "single-threaded mode" : no worker is spawned,
                              * compression is performed inside Caller's thread, and all invocations are blocking */
    ZSTD_c_jobSize=401,      /* Size of a compression job. This value is enforced only when nbWorkers >= 1.
                              * Each compression job is completed in parallel, so this value can indirectly impact the nb of active threads.
                              * 0 means default, which is dynamically determined based on compression parameters.
                              * Job size must be a minimum of overlap size, or ZSTDMT_JOBSIZE_MIN (= 512 KB), whichever is largest.
                              * The minimum size is automatically and transparently enforced. */
    ZSTD_c_overlapLog=402,   /* Control the overlap size, as a fraction of window size.
                              * The overlap size is an amount of data reloaded from previous job at the beginning of a new job.
                              * It helps preserve compression ratio, while each job is compressed in parallel.
                              * This value is enforced only when nbWorkers >= 1.
                              * Larger values increase compression ratio, but decrease speed.
                              * Possible values range from 0 to 9 :
                              * - 0 means "default" : value will be determined by the library, depending on strategy
                              * - 1 means "no overlap"
                              * - 9 means "full overlap", using a full window size.
                              * Each intermediate rank increases/decreases load size by a factor 2 :
                              * 9: full window;  8: w/2;  7: w/4;  6: w/8;  5:w/16;  4: w/32;  3:w/64;  2:w/128;  1:no overlap;  0:default
                              * default value varies between 6 and 9, depending on strategy */

    /* note : additional experimental parameters are also available
     * within the experimental section of the API.
     * At the time of this writing, they include :
     * ZSTD_c_rsyncable
     * ZSTD_c_format
     * ZSTD_c_forceMaxWindow
     * ZSTD_c_forceAttachDict
     * ZSTD_c_literalCompressionMode
     * ZSTD_c_srcSizeHint
     * ZSTD_c_enableDedicatedDictSearch
     * ZSTD_c_stableInBuffer
     * ZSTD_c_stableOutBuffer
     * ZSTD_c_blockDelimiters
     * ZSTD_c_validateSequences
     * ZSTD_c_blockSplitterLevel
     * ZSTD_c_splitAfterSequences
     * ZSTD_c_useRowMatchFinder
     * ZSTD_c_prefetchCDictTables
     * ZSTD_c_enableSeqProducerFallback
     * ZSTD_c_maxBlockSize
     * Because they are not stable, it's necessary to define ZSTD_STATIC_LINKING_ONLY to access them.
     * note : never ever use experimentalParam? names directly;
     *        also, the enums values themselves are unstable and can still change.
     */
     ZSTD_c_experimentalParam1=500,
     ZSTD_c_experimentalParam2=10,
     ZSTD_c_experimentalParam3=1000,
     ZSTD_c_experimentalParam4=1001,
     ZSTD_c_experimentalParam5=1002,
     /* was ZSTD_c_experimentalParam6=1003; is now ZSTD_c_targetCBlockSize */
     ZSTD_c_experimentalParam7=1004,
     ZSTD_c_experimentalParam8=1005,
     ZSTD_c_experimentalParam9=1006,
     ZSTD_c_experimentalParam10=1007,
     ZSTD_c_experimentalParam11=1008,
     ZSTD_c_experimentalParam12=1009,
     ZSTD_c_experimentalParam13=1010,
     ZSTD_c_experimentalParam14=1011,
     ZSTD_c_experimentalParam15=1012,
     ZSTD_c_experimentalParam16=1013,
     ZSTD_c_experimentalParam17=1014,
     ZSTD_c_experimentalParam18=1015,
     ZSTD_c_experimentalParam19=1016,
     ZSTD_c_experimentalParam20=1017
} ZSTD_cParameter;

typedef struct {
    size_t error;
    int lowerBound;
    int upperBound;
} ZSTD_bounds;

/*! ZSTD_cParam_getBounds() :
 *  All parameters must belong to an interval with lower and upper bounds,
 *  otherwise they will either trigger an error or be automatically clamped.
 * @return : a structure, ZSTD_bounds, which contains
 *         - an error status field, which must be tested using ZSTD_isError()
 *         - lower and upper bounds, both inclusive
 */
/* ZSTDLIB_API ZSTD_bounds ZSTD_cParam_getBounds(ZSTD_cParameter cParam); */

/*! ZSTD_CCtx_setParameter() :
 *  Set one compression parameter, selected by enum ZSTD_cParameter.
 *  All parameters have valid bounds. Bounds can be queried using ZSTD_cParam_getBounds().
 *  Providing a value beyond bound will either clamp it, or trigger an error (depending on parameter).
 *  Setting a parameter is generally only possible during frame initialization (before starting compression).
 *  Exception : when using multi-threading mode (nbWorkers >= 1),
 *              the following parameters can be updated _during_ compression (within same frame):
 *              => compressionLevel, hashLog, chainLog, searchLog, minMatch, targetLength and strategy.
 *              new parameters will be active for next job only (after a flush()).
 * @return : an error code (which can be tested using ZSTD_isError()).
 */
/* ZSTDLIB_API size_t ZSTD_CCtx_setParameter(ZSTD_CCtx* cctx, ZSTD_cParameter param, int value); */

/*! ZSTD_CCtx_setPledgedSrcSize() :
 *  Total input data size to be compressed as a single frame.
 *  Value will be written in frame header, unless if explicitly forbidden using ZSTD_c_contentSizeFlag.
 *  This value will also be controlled at end of frame, and trigger an error if not respected.
 * @result : 0, or an error code (which can be tested with ZSTD_isError()).
 *  Note 1 : pledgedSrcSize==0 actually means zero, aka an empty frame.
 *           In order to mean "unknown content size", pass constant ZSTD_CONTENTSIZE_UNKNOWN.
 *           ZSTD_CONTENTSIZE_UNKNOWN is default value for any new frame.
 *  Note 2 : pledgedSrcSize is only valid once, for the next frame.
 *           It's discarded at the end of the frame, and replaced by ZSTD_CONTENTSIZE_UNKNOWN.
 *  Note 3 : Whenever all input data is provided and consumed in a single round,
 *           for example with ZSTD_compress2(),
 *           or invoking immediately ZSTD_compressStream2(,,,ZSTD_e_end),
 *           this value is automatically overridden by srcSize instead.
 */
/* ZSTDLIB_API size_t ZSTD_CCtx_setPledgedSrcSize(ZSTD_CCtx* cctx, unsigned long long pledgedSrcSize); */

typedef enum {
    ZSTD_reset_session_only = 1,
    ZSTD_reset_parameters = 2,
    ZSTD_reset_session_and_parameters = 3
} ZSTD_ResetDirective;

/*! ZSTD_CCtx_reset() :
 *  There are 2 different things that can be reset, independently or jointly :
 *  - The session : will stop compressing current frame, and make CCtx ready to start a new one.
 *                  Useful after an error, or to interrupt any ongoing compression.
 *                  Any internal data not yet flushed is cancelled.
 *                  Compression parameters and dictionary remain unchanged.
 *                  They will be used to compress next frame.
 *                  Resetting session never fails.
 *  - The parameters : changes all parameters back to "default".
 *                  This also removes any reference to any dictionary or external sequence producer.
 *                  Parameters can only be changed between 2 sessions (i.e. no compression is currently ongoing)
 *                  otherwise the reset fails, and function returns an error value (which can be tested using ZSTD_isError())
 *  - Both : similar to resetting the session, followed by resetting parameters.
 */
/* ZSTDLIB_API size_t ZSTD_CCtx_reset(ZSTD_CCtx* cctx, ZSTD_ResetDirective reset); */

/*! ZSTD_compress2() :
 *  Behave the same as ZSTD_compressCCtx(), but compression parameters are set using the advanced API.
 *  (note that this entry point doesn't even expose a compression level parameter).
 *  ZSTD_compress2() always starts a new frame.
 *  Should cctx hold data from a previously unfinished frame, everything about it is forgotten.
 *  - Compression parameters are pushed into CCtx before starting compression, using ZSTD_CCtx_set*()
 *  - The function is always blocking, returns when compression is completed.
 *  NOTE: Providing `dstCapacity >= ZSTD_compressBound(srcSize)` guarantees that zstd will have
 *        enough space to successfully compress the data, though it is possible it fails for other reasons.
 * @return : compressed size written into `dst` (<= `dstCapacity),
 *           or an error code if it fails (which can be tested using ZSTD_isError()).
 */
/* ZSTDLIB_API size_t ZSTD_compress2( ZSTD_CCtx* cctx,
                                   void* dst, size_t dstCapacity,
                             const void* src, size_t srcSize); */


/***********************************************
*  Advanced decompression API (Requires v1.4.0+)
************************************************/

/* The advanced API pushes parameters one by one into an existing DCtx context.
 * Parameters are sticky, and remain valid for all following frames
 * using the same DCtx context.
 * It's possible to reset parameters to default values using ZSTD_DCtx_reset().
 * Note : This API is compatible with existing ZSTD_decompressDCtx() and ZSTD_decompressStream().
 *        Therefore, no new decompression function is necessary.
 */

typedef enum {

    ZSTD_d_windowLogMax=100, /* Select a size limit (in power of 2) beyond which
                              * the streaming API will refuse to allocate memory buffer
                              * in order to protect the host from unreasonable memory requirements.
                              * This parameter is only useful in streaming mode, since no internal buffer is allocated in single-pass mode.
                              * By default, a decompression context accepts window sizes <= (1 << ZSTD_WINDOWLOG_LIMIT_DEFAULT).
                              * Special: value 0 means "use default maximum windowLog". */

    /* note : additional experimental parameters are also available
     * within the experimental section of the API.
     * At the time of this writing, they include :
     * ZSTD_d_format
     * ZSTD_d_stableOutBuffer
     * ZSTD_d_forceIgnoreChecksum
     * ZSTD_d_refMultipleDDicts
     * ZSTD_d_disableHuffmanAssembly
     * ZSTD_d_maxBlockSize
     * Because they are not stable, it's necessary to define ZSTD_STATIC_LINKING_ONLY to access them.
     * note : never ever use experimentalParam? names directly
     */
     ZSTD_d_experimentalParam1=1000,
     ZSTD_d_experimentalParam2=1001,
     ZSTD_d_experimentalParam3=1002,
     ZSTD_d_experimentalParam4=1003,
     ZSTD_d_experimentalParam5=1004,
     ZSTD_d_experimentalParam6=1005

} ZSTD_dParameter;

/*! ZSTD_dParam_getBounds() :
 *  All parameters must belong to an interval with lower and upper bounds,
 *  otherwise they will either trigger an error or be automatically clamped.
 * @return : a structure, ZSTD_bounds, which contains
 *         - an error status field, which must be tested using ZSTD_isError()
 *         - both lower and upper bounds, inclusive
 */
/* ZSTDLIB_API ZSTD_bounds ZSTD_dParam_getBounds(ZSTD_dParameter dParam); */

/*! ZSTD_DCtx_setParameter() :
 *  Set one compression parameter, selected by enum ZSTD_dParameter.
 *  All parameters have valid bounds. Bounds can be queried using ZSTD_dParam_getBounds().
 *  Providing a value beyond bound will either clamp it, or trigger an error (depending on parameter).
 *  Setting a parameter is only possible during frame initialization (before starting decompression).
 * @return : 0, or an error code (which can be tested using ZSTD_isError()).
 */
/* ZSTDLIB_API size_t ZSTD_DCtx_setParameter(ZSTD_DCtx* dctx, ZSTD_dParameter param, int value); */

/*! ZSTD_DCtx_reset() :
 *  Return a DCtx to clean state.
 *  Session and parameters can be reset jointly or separately.
 *  Parameters can only be reset when no active frame is being decompressed.
 * @return : 0, or an error code, which can be tested with ZSTD_isError()
 */
/* ZSTDLIB_API size_t ZSTD_DCtx_reset(ZSTD_DCtx* dctx, ZSTD_ResetDirective reset); */


/****************************
*  Streaming
****************************/

typedef struct ZSTD_inBuffer_s {
  const void* src;    /**< start of input buffer */
  size_t size;        /**< size of input buffer */
  size_t pos;         /**< position where reading stopped. Will be updated. Necessarily 0 <= pos <= size */
} ZSTD_inBuffer;

typedef struct ZSTD_outBuffer_s {
  void*  dst;         /**< start of output buffer */
  size_t size;        /**< size of output buffer */
  size_t pos;         /**< position where writing stopped. Will be updated. Necessarily 0 <= pos <= size */
} ZSTD_outBuffer;



/*-***********************************************************************
*  Streaming compression - HowTo
*
*  A ZSTD_CStream object is required to track streaming operation.
*  Use ZSTD_createCStream() and ZSTD_freeCStream() to create/release resources.
*  ZSTD_CStream objects can be reused multiple times on consecutive compression operations.
*  It is recommended to reuse ZSTD_CStream since it will play nicer with system's memory, by re-using already allocated memory.
*
*  For parallel execution, use one separate ZSTD_CStream per thread.
*
*  note : since v1.3.0, ZSTD_CStream and ZSTD_CCtx are the same thing.
*
*  Parameters are sticky : when starting a new compression on the same context,
*  it will reuse the same sticky parameters as previous compression session.
*  When in doubt, it's recommended to fully initialize the context before usage.
*  Use ZSTD_CCtx_reset() to reset the context and ZSTD_CCtx_setParameter(),
*  ZSTD_CCtx_setPledgedSrcSize(), or ZSTD_CCtx_loadDictionary() and friends to
*  set more specific parameters, the pledged source size, or load a dictionary.
*
*  Use ZSTD_compressStream2() with ZSTD_e_continue as many times as necessary to
*  consume input stream. The function will automatically update both `pos`
*  fields within `input` and `output`.
*  Note that the function may not consume the entire input, for example, because
*  the output buffer is already full, in which case `input.pos < input.size`.
*  The caller must check if input has been entirely consumed.
*  If not, the caller must make some room to receive more compressed data,
*  and then present again remaining input data.
*  note: ZSTD_e_continue is guaranteed to make some forward progress when called,
*        but doesn't guarantee maximal forward progress. This is especially relevant
*        when compressing with multiple threads. The call won't block if it can
*        consume some input, but if it can't it will wait for some, but not all,
*        output to be flushed.
* @return : provides a minimum amount of data remaining to be flushed from internal buffers
*           or an error code, which can be tested using ZSTD_isError().
*
*  At any moment, it's possible to flush whatever data might remain stuck within internal buffer,
*  using ZSTD_compressStream2() with ZSTD_e_flush. `output->pos` will be updated.
*  Note that, if `output->size` is too small, a single invocation with ZSTD_e_flush might not be enough (return code > 0).
*  In which case, make some room to receive more compressed data, and call again ZSTD_compressStream2() with ZSTD_e_flush.
*  You must continue calling ZSTD_compressStream2() with ZSTD_e_flush until it returns 0, at which point you can change the
*  operation.
*  note: ZSTD_e_flush will flush as much output as possible, meaning when compressing with multiple threads, it will
*        block until the flush is complete or the output buffer is full.
*  @return : 0 if internal buffers are entirely flushed,
*            >0 if some data still present within internal buffer (the value is minimal estimation of remaining size),
*            or an error code, which can be tested using ZSTD_isError().
*
*  Calling ZSTD_compressStream2() with ZSTD_e_end instructs to finish a frame.
*  It will perform a flush and write frame epilogue.
*  The epilogue is required for decoders to consider a frame completed.
*  flush operation is the same, and follows same rules as calling ZSTD_compressStream2() with ZSTD_e_flush.
*  You must continue calling ZSTD_compressStream2() with ZSTD_e_end until it returns 0, at which point you are free to
*  start a new frame.
*  note: ZSTD_e_end will flush as much output as possible, meaning when compressing with multiple threads, it will
*        block until the flush is complete or the output buffer is full.
*  @return : 0 if frame fully completed and fully flushed,
*            >0 if some data still present within internal buffer (the value is minimal estimation of remaining size),
*            or an error code, which can be tested using ZSTD_isError().
*
* *******************************************************************/

typedef ZSTD_CCtx ZSTD_CStream;  /**< CCtx and CStream are now effectively same object (>= v1.3.0) */
                                 /* Continue to distinguish them for compatibility with older versions <= v1.2.0 */
/*===== ZSTD_CStream management functions =====*/
/* ZSTDLIB_API ZSTD_CStream* ZSTD_createCStream(void); */
/* ZSTDLIB_API size_t ZSTD_freeCStream(ZSTD_CStream* zcs); */  /* accept NULL pointer */

/*===== Streaming compression functions =====*/
typedef enum {
    ZSTD_e_continue=0, /* collect more data, encoder decides when to output compressed result, for optimal compression ratio */
    ZSTD_e_flush=1,    /* flush any data provided so far,
                        * it creates (at least) one new block, that can be decoded immediately on reception;
                        * frame will continue: any future data can still reference previously compressed data, improving compression.
                        * note : multithreaded compression will block to flush as much output as possible. */
    ZSTD_e_end=2       /* flush any remaining data _and_ close current frame.
                        * note that frame is only closed after compressed data is fully flushed (return value == 0).
                        * After that point, any additional data starts a new frame.
                        * note : each frame is independent (does not reference any content from previous frame).
                        : note : multithreaded compression will block to flush as much output as possible. */
} ZSTD_EndDirective;

/*! ZSTD_compressStream2() : Requires v1.4.0+
 *  Behaves about the same as ZSTD_compressStream, with additional control on end directive.
 *  - Compression parameters are pushed into CCtx before starting compression, using ZSTD_CCtx_set*()
 *  - Compression parameters cannot be changed once compression is started (save a list of exceptions in multi-threading mode)
 *  - output->pos must be <= dstCapacity, input->pos must be <= srcSize
 *  - output->pos and input->pos will be updated. They are guaranteed to remain below their respective limit.
 *  - endOp must be a valid directive
 *  - When nbWorkers==0 (default), function is blocking : it completes its job before returning to caller.
 *  - When nbWorkers>=1, function is non-blocking : it copies a portion of input, distributes jobs to internal worker threads, flush to output whatever is available,
 *                                                  and then immediately returns, just indicating that there is some data remaining to be flushed.
 *                                                  The function nonetheless guarantees forward progress : it will return only after it reads or write at least 1+ byte.
 *  - Exception : if the first call requests a ZSTD_e_end directive and provides enough dstCapacity, the function delegates to ZSTD_compress2() which is always blocking.
 *  - @return provides a minimum amount of data remaining to be flushed from internal buffers
 *            or an error code, which can be tested using ZSTD_isError().
 *            if @return != 0, flush is not fully completed, there is still some data left within internal buffers.
 *            This is useful for ZSTD_e_flush, since in this case more flushes are necessary to empty all buffers.
 *            For ZSTD_e_end, @return == 0 when internal buffers are fully flushed and frame is completed.
 *  - after a ZSTD_e_end directive, if internal buffer is not fully flushed (@return != 0),
 *            only ZSTD_e_end or ZSTD_e_flush operations are allowed.
 *            Before starting a new compression job, or changing compression parameters,
 *            it is required to fully flush internal buffers.
 *  - note: if an operation ends with an error, it may leave @cctx in an undefined state.
 *          Therefore, it's UB to invoke ZSTD_compressStream2() of ZSTD_compressStream() on such a state.
 *          In order to be re-employed after an error, a state must be reset,
 *          which can be done explicitly (ZSTD_CCtx_reset()),
 *          or is sometimes implied by methods starting a new compression job (ZSTD_initCStream(), ZSTD_compressCCtx())
 */
/* ZSTDLIB_API size_t ZSTD_compressStream2( ZSTD_CCtx* cctx,
                                         ZSTD_outBuffer* output,
                                         ZSTD_inBuffer* input,
                                         ZSTD_EndDirective endOp); */


/* These buffer sizes are softly recommended.
 * They are not required : ZSTD_compressStream*() happily accepts any buffer size, for both input and output.
 * Respecting the recommended size just makes it a bit easier for ZSTD_compressStream*(),
 * reducing the amount of memory shuffling and buffering, resulting in minor performance savings.
 *
 * However, note that these recommendations are from the perspective of a C caller program.
 * If the streaming interface is invoked from some other language,
 * especially managed ones such as Java or Go, through a foreign function interface such as jni or cgo,
 * a major performance rule is to reduce crossing such interface to an absolute minimum.
 * It's not rare that performance ends being spent more into the interface, rather than compression itself.
 * In which cases, prefer using large buffers, as large as practical,
 * for both input and output, to reduce the nb of roundtrips.
 */
/* ZSTDLIB_API size_t ZSTD_CStreamInSize(void); */    /**< recommended size for input buffer */
/* ZSTDLIB_API size_t ZSTD_CStreamOutSize(void); */   /**< recommended size for output buffer. Guarantee to successfully flush at least one complete compressed block. */


/* *****************************************************************************
 * This following is a legacy streaming API, available since v1.0+ .
 * It can be replaced by ZSTD_CCtx_reset() and ZSTD_compressStream2().
 * It is redundant, but remains fully supported.
 ******************************************************************************/

/*!
 * Equivalent to:
 *
 *     ZSTD_CCtx_reset(zcs, ZSTD_reset_session_only);
 *     ZSTD_CCtx_refCDict(zcs, NULL); // clear the dictionary (if any)
 *     ZSTD_CCtx_setParameter(zcs, ZSTD_c_compressionLevel, compressionLevel);
 *
 * Note that ZSTD_initCStream() clears any previously set dictionary. Use the new API
 * to compress with a dictionary.
 */
/* ZSTDLIB_API size_t ZSTD_initCStream(ZSTD_CStream* zcs, int compressionLevel); */
/*!
 * Alternative for ZSTD_compressStream2(zcs, output, input, ZSTD_e_continue).
 * NOTE: The return value is different. ZSTD_compressStream() returns a hint for
 * the next read size (if non-zero and not an error). ZSTD_compressStream2()
 * returns the minimum nb of bytes left to flush (if non-zero and not an error).
 */
/* ZSTDLIB_API size_t ZSTD_compressStream(ZSTD_CStream* zcs, ZSTD_outBuffer* output, ZSTD_inBuffer* input); */
/*! Equivalent to ZSTD_compressStream2(zcs, output, &emptyInput, ZSTD_e_flush). */
/* ZSTDLIB_API size_t ZSTD_flushStream(ZSTD_CStream* zcs, ZSTD_outBuffer* output); */
/*! Equivalent to ZSTD_compressStream2(zcs, output, &emptyInput, ZSTD_e_end). */
/* ZSTDLIB_API size_t ZSTD_endStream(ZSTD_CStream* zcs, ZSTD_outBuffer* output); */


/*-***************************************************************************
*  Streaming decompression - HowTo
*
*  A ZSTD_DStream object is required to track streaming operations.
*  Use ZSTD_createDStream() and ZSTD_freeDStream() to create/release resources.
*  ZSTD_DStream objects can be re-employed multiple times.
*
*  Use ZSTD_initDStream() to start a new decompression operation.
* @return : recommended first input size
*  Alternatively, use advanced API to set specific properties.
*
*  Use ZSTD_decompressStream() repetitively to consume your input.
*  The function will update both `pos` fields.
*  If `input.pos < input.size`, some input has not been consumed.
*  It's up to the caller to present again remaining data.
*
*  The function tries to flush all data decoded immediately, respecting output buffer size.
*  If `output.pos < output.size`, decoder has flushed everything it could.
*
*  However, when `output.pos == output.size`, it's more difficult to know.
*  If @return > 0, the frame is not complete, meaning
*  either there is still some data left to flush within internal buffers,
*  or there is more input to read to complete the frame (or both).
*  In which case, call ZSTD_decompressStream() again to flush whatever remains in the buffer.
*  Note : with no additional input provided, amount of data flushed is necessarily <= ZSTD_BLOCKSIZE_MAX.
* @return : 0 when a frame is completely decoded and fully flushed,
*        or an error code, which can be tested using ZSTD_isError(),
*        or any other value > 0, which means there is still some decoding or flushing to do to complete current frame :
*                                the return value is a suggested next input size (just a hint for better latency)
*                                that will never request more than the remaining content of the compressed frame.
* *******************************************************************************/

typedef ZSTD_DCtx ZSTD_DStream;  /**< DCtx and DStream are now effectively same object (>= v1.3.0) */
                                 /* For compatibility with versions <= v1.2.0, prefer differentiating them. */
/*===== ZSTD_DStream management functions =====*/
/* ZSTDLIB_API ZSTD_DStream* ZSTD_createDStream(void); */
/* ZSTDLIB_API size_t ZSTD_freeDStream(ZSTD_DStream* zds); */  /* accept NULL pointer */

/*===== Streaming decompression functions =====*/

/*! ZSTD_initDStream() :
 * Initialize/reset DStream state for new decompression operation.
 * Call before new decompression operation using same DStream.
 *
 * Note : This function is redundant with the advanced API and equivalent to:
 *     ZSTD_DCtx_reset(zds, ZSTD_reset_session_only);
 *     ZSTD_DCtx_refDDict(zds, NULL);
 */
/* ZSTDLIB_API size_t ZSTD_initDStream(ZSTD_DStream* zds); */

/*! ZSTD_decompressStream() :
 * Streaming decompression function.
 * Call repetitively to consume full input updating it as necessary.
 * Function will update both input and output `pos` fields exposing current state via these fields:
 * - `input.pos < input.size`, some input remaining and caller should provide remaining input
 *   on the next call.
 * - `output.pos < output.size`, decoder flushed internal output buffer.
 * - `output.pos == output.size`, unflushed data potentially present in the internal buffers,
 *   check ZSTD_decompressStream() @return value,
 *   if > 0, invoke it again to flush remaining data to output.
 * Note : with no additional input, amount of data flushed <= ZSTD_BLOCKSIZE_MAX.
 *
 * @return : 0 when a frame is completely decoded and fully flushed,
 *           or an error code, which can be tested using ZSTD_isError(),
 *           or any other value > 0, which means there is some decoding or flushing to do to complete current frame.
 *
 * Note: when an operation returns with an error code, the @zds state may be left in undefined state.
 *       It's UB to invoke `ZSTD_decompressStream()` on such a state.
 *       In order to re-use such a state, it must be first reset,
 *       which can be done explicitly (`ZSTD_DCtx_reset()`),
 *       or is implied for operations starting some new decompression job (`ZSTD_initDStream`, `ZSTD_decompressDCtx()`, `ZSTD_decompress_usingDict()`)
 */
/* ZSTDLIB_API size_t ZSTD_decompressStream(ZSTD_DStream* zds, ZSTD_outBuffer* output, ZSTD_inBuffer* input); */

/* ZSTDLIB_API size_t ZSTD_DStreamInSize(void); */    /*!< recommended size for input buffer */
/* ZSTDLIB_API size_t ZSTD_DStreamOutSize(void); */   /*!< recommended size for output buffer. Guarantee to successfully flush at least one complete block in all circumstances. */


/**************************
*  Simple dictionary API
***************************/
/*! ZSTD_compress_usingDict() :
 *  Compression at an explicit compression level using a Dictionary.
 *  A dictionary can be any arbitrary data segment (also called a prefix),
 *  or a buffer with specified information (see zdict.h).
 *  Note : This function loads the dictionary, resulting in significant startup delay.
 *         It's intended for a dictionary used only once.
 *  Note 2 : When `dict == NULL || dictSize < 8` no dictionary is used. */
/* ZSTDLIB_API size_t ZSTD_compress_usingDict(ZSTD_CCtx* ctx,
                                           void* dst, size_t dstCapacity,
                                     const void* src, size_t srcSize,
                                     const void* dict,size_t dictSize,
                                           int compressionLevel); */

/*! ZSTD_decompress_usingDict() :
 *  Decompression using a known Dictionary.
 *  Dictionary must be identical to the one used during compression.
 *  Note : This function loads the dictionary, resulting in significant startup delay.
 *         It's intended for a dictionary used only once.
 *  Note : When `dict == NULL || dictSize < 8` no dictionary is used. */
/* ZSTDLIB_API size_t ZSTD_decompress_usingDict(ZSTD_DCtx* dctx,
                                             void* dst, size_t dstCapacity,
                                       const void* src, size_t srcSize,
                                       const void* dict,size_t dictSize); */


/***********************************
 *  Bulk processing dictionary API
 **********************************/
typedef struct ZSTD_CDict_s ZSTD_CDict;

/*! ZSTD_createCDict() :
 *  When compressing multiple messages or blocks using the same dictionary,
 *  it's recommended to digest the dictionary only once, since it's a costly operation.
 *  ZSTD_createCDict() will create a state from digesting a dictionary.
 *  The resulting state can be used for future compression operations with very limited startup cost.
 *  ZSTD_CDict can be created once and shared by multiple threads concurrently, since its usage is read-only.
 * @dictBuffer can be released after ZSTD_CDict creation, because its content is copied within CDict.
 *  Note 1 : Consider experimental function `ZSTD_createCDict_byReference()` if you prefer to not duplicate @dictBuffer content.
 *  Note 2 : A ZSTD_CDict can be created from an empty @dictBuffer,
 *      in which case the only thing that it transports is the @compressionLevel.
 *      This can be useful in a pipeline featuring ZSTD_compress_usingCDict() exclusively,
 *      expecting a ZSTD_CDict parameter with any data, including those without a known dictionary. */
/* ZSTDLIB_API ZSTD_CDict* ZSTD_createCDict(const void* dictBuffer, size_t dictSize,
                                         int compressionLevel); */

/*! ZSTD_freeCDict() :
 *  Function frees memory allocated by ZSTD_createCDict().
 *  If a NULL pointer is passed, no operation is performed. */
/* ZSTDLIB_API size_t      ZSTD_freeCDict(ZSTD_CDict* CDict); */

/*! ZSTD_compress_usingCDict() :
 *  Compression using a digested Dictionary.
 *  Recommended when same dictionary is used multiple times.
 *  Note : compression level is _decided at dictionary creation time_,
 *     and frame parameters are hardcoded (dictID=yes, contentSize=yes, checksum=no) */
/* ZSTDLIB_API size_t ZSTD_compress_usingCDict(ZSTD_CCtx* cctx,
                                            void* dst, size_t dstCapacity,
                                      const void* src, size_t srcSize,
                                      const ZSTD_CDict* cdict); */


typedef struct ZSTD_DDict_s ZSTD_DDict;

/*! ZSTD_createDDict() :
 *  Create a digested dictionary, ready to start decompression operation without startup delay.
 *  dictBuffer can be released after DDict creation, as its content is copied inside DDict. */
/* ZSTDLIB_API ZSTD_DDict* ZSTD_createDDict(const void* dictBuffer, size_t dictSize); */

/*! ZSTD_freeDDict() :
 *  Function frees memory allocated with ZSTD_createDDict()
 *  If a NULL pointer is passed, no operation is performed. */
/* ZSTDLIB_API size_t      ZSTD_freeDDict(ZSTD_DDict* ddict); */

/*! ZSTD_decompress_usingDDict() :
 *  Decompression using a digested Dictionary.
 *  Recommended when same dictionary is used multiple times. */
/* ZSTDLIB_API size_t ZSTD_decompress_usingDDict(ZSTD_DCtx* dctx,
                                              void* dst, size_t dstCapacity,
                                        const void* src, size_t srcSize,
                                        const ZSTD_DDict* ddict); */


/********************************
 *  Dictionary helper functions
 *******************************/

/*! ZSTD_getDictID_fromDict() : Requires v1.4.0+
 *  Provides the dictID stored within dictionary.
 *  if @return == 0, the dictionary is not conformant with Zstandard specification.
 *  It can still be loaded, but as a content-only dictionary. */
/* ZSTDLIB_API unsigned ZSTD_getDictID_fromDict(const void* dict, size_t dictSize); */

/*! ZSTD_getDictID_fromCDict() : Requires v1.5.0+
 *  Provides the dictID of the dictionary loaded into `cdict`.
 *  If @return == 0, the dictionary is not conformant to Zstandard specification, or empty.
 *  Non-conformant dictionaries can still be loaded, but as content-only dictionaries. */
/* ZSTDLIB_API unsigned ZSTD_getDictID_fromCDict(const ZSTD_CDict* cdict); */

/*! ZSTD_getDictID_fromDDict() : Requires v1.4.0+
 *  Provides the dictID of the dictionary loaded into `ddict`.
 *  If @return == 0, the dictionary is not conformant to Zstandard specification, or empty.
 *  Non-conformant dictionaries can still be loaded, but as content-only dictionaries. */
/* ZSTDLIB_API unsigned ZSTD_getDictID_fromDDict(const ZSTD_DDict* ddict); */

/*! ZSTD_getDictID_fromFrame() : Requires v1.4.0+
 *  Provides the dictID required to decompressed the frame stored within `src`.
 *  If @return == 0, the dictID could not be decoded.
 *  This could for one of the following reasons :
 *  - The frame does not require a dictionary to be decoded (most common case).
 *  - The frame was built with dictID intentionally removed. Whatever dictionary is necessary is a hidden piece of information.
 *    Note : this use case also happens when using a non-conformant dictionary.
 *  - `srcSize` is too small, and as a result, the frame header could not be decoded (only possible if `srcSize < ZSTD_FRAMEHEADERSIZE_MAX`).
 *  - This is not a Zstandard frame.
 *  When identifying the exact failure cause, it's possible to use ZSTD_getFrameHeader(), which will provide a more precise error code. */
/* ZSTDLIB_API unsigned ZSTD_getDictID_fromFrame(const void* src, size_t srcSize); */


/*******************************************************************************
 * Advanced dictionary and prefix API (Requires v1.4.0+)
 *
 * This API allows dictionaries to be used with ZSTD_compress2(),
 * ZSTD_compressStream2(), and ZSTD_decompressDCtx().
 * Dictionaries are sticky, they remain valid when same context is reused,
 * they only reset when the context is reset
 * with ZSTD_reset_parameters or ZSTD_reset_session_and_parameters.
 * In contrast, Prefixes are single-use.
 ******************************************************************************/


/*! ZSTD_CCtx_loadDictionary() : Requires v1.4.0+
 *  Create an internal CDict from `dict` buffer.
 *  Decompression will have to use same dictionary.
 * @result : 0, or an error code (which can be tested with ZSTD_isError()).
 *  Special: Loading a NULL (or 0-size) dictionary invalidates previous dictionary,
 *           meaning "return to no-dictionary mode".
 *  Note 1 : Dictionary is sticky, it will be used for all future compressed frames,
 *           until parameters are reset, a new dictionary is loaded, or the dictionary
 *           is explicitly invalidated by loading a NULL dictionary.
 *  Note 2 : Loading a dictionary involves building tables.
 *           It's also a CPU consuming operation, with non-negligible impact on latency.
 *           Tables are dependent on compression parameters, and for this reason,
 *           compression parameters can no longer be changed after loading a dictionary.
 *  Note 3 :`dict` content will be copied internally.
 *           Use experimental ZSTD_CCtx_loadDictionary_byReference() to reference content instead.
 *           In such a case, dictionary buffer must outlive its users.
 *  Note 4 : Use ZSTD_CCtx_loadDictionary_advanced()
 *           to precisely select how dictionary content must be interpreted.
 *  Note 5 : This method does not benefit from LDM (long distance mode).
 *           If you want to employ LDM on some large dictionary content,
 *           prefer employing ZSTD_CCtx_refPrefix() described below.
 */
/* ZSTDLIB_API size_t ZSTD_CCtx_loadDictionary(ZSTD_CCtx* cctx, const void* dict, size_t dictSize); */

/*! ZSTD_CCtx_refCDict() : Requires v1.4.0+
 *  Reference a prepared dictionary, to be used for all future compressed frames.
 *  Note that compression parameters are enforced from within CDict,
 *  and supersede any compression parameter previously set within CCtx.
 *  The parameters ignored are labelled as "superseded-by-cdict" in the ZSTD_cParameter enum docs.
 *  The ignored parameters will be used again if the CCtx is returned to no-dictionary mode.
 *  The dictionary will remain valid for future compressed frames using same CCtx.
 * @result : 0, or an error code (which can be tested with ZSTD_isError()).
 *  Special : Referencing a NULL CDict means "return to no-dictionary mode".
 *  Note 1 : Currently, only one dictionary can be managed.
 *           Referencing a new dictionary effectively "discards" any previous one.
 *  Note 2 : CDict is just referenced, its lifetime must outlive its usage within CCtx. */
/* ZSTDLIB_API size_t ZSTD_CCtx_refCDict(ZSTD_CCtx* cctx, const ZSTD_CDict* cdict); */

/*! ZSTD_CCtx_refPrefix() : Requires v1.4.0+
 *  Reference a prefix (single-usage dictionary) for next compressed frame.
 *  A prefix is **only used once**. Tables are discarded at end of frame (ZSTD_e_end).
 *  Decompression will need same prefix to properly regenerate data.
 *  Compressing with a prefix is similar in outcome as performing a diff and compressing it,
 *  but performs much faster, especially during decompression (compression speed is tunable with compression level).
 *  This method is compatible with LDM (long distance mode).
 * @result : 0, or an error code (which can be tested with ZSTD_isError()).
 *  Special: Adding any prefix (including NULL) invalidates any previous prefix or dictionary
 *  Note 1 : Prefix buffer is referenced. It **must** outlive compression.
 *           Its content must remain unmodified during compression.
 *  Note 2 : If the intention is to diff some large src data blob with some prior version of itself,
 *           ensure that the window size is large enough to contain the entire source.
 *           See ZSTD_c_windowLog.
 *  Note 3 : Referencing a prefix involves building tables, which are dependent on compression parameters.
 *           It's a CPU consuming operation, with non-negligible impact on latency.
 *           If there is a need to use the same prefix multiple times, consider loadDictionary instead.
 *  Note 4 : By default, the prefix is interpreted as raw content (ZSTD_dct_rawContent).
 *           Use experimental ZSTD_CCtx_refPrefix_advanced() to alter dictionary interpretation. */
/* ZSTDLIB_API size_t ZSTD_CCtx_refPrefix(ZSTD_CCtx* cctx,
                                 const void* prefix, size_t prefixSize); */

/*! ZSTD_DCtx_loadDictionary() : Requires v1.4.0+
 *  Create an internal DDict from dict buffer, to be used to decompress all future frames.
 *  The dictionary remains valid for all future frames, until explicitly invalidated, or
 *  a new dictionary is loaded.
 * @result : 0, or an error code (which can be tested with ZSTD_isError()).
 *  Special : Adding a NULL (or 0-size) dictionary invalidates any previous dictionary,
 *            meaning "return to no-dictionary mode".
 *  Note 1 : Loading a dictionary involves building tables,
 *           which has a non-negligible impact on CPU usage and latency.
 *           It's recommended to "load once, use many times", to amortize the cost
 *  Note 2 :`dict` content will be copied internally, so `dict` can be released after loading.
 *           Use ZSTD_DCtx_loadDictionary_byReference() to reference dictionary content instead.
 *  Note 3 : Use ZSTD_DCtx_loadDictionary_advanced() to take control of
 *           how dictionary content is loaded and interpreted.
 */
/* ZSTDLIB_API size_t ZSTD_DCtx_loadDictionary(ZSTD_DCtx* dctx, const void* dict, size_t dictSize); */

/*! ZSTD_DCtx_refDDict() : Requires v1.4.0+
 *  Reference a prepared dictionary, to be used to decompress next frames.
 *  The dictionary remains active for decompression of future frames using same DCtx.
 *
 *  If called with ZSTD_d_refMultipleDDicts enabled, repeated calls of this function
 *  will store the DDict references in a table, and the DDict used for decompression
 *  will be determined at decompression time, as per the dict ID in the frame.
 *  The memory for the table is allocated on the first call to refDDict, and can be
 *  freed with ZSTD_freeDCtx().
 *
 *  If called with ZSTD_d_refMultipleDDicts disabled (the default), only one dictionary
 *  will be managed, and referencing a dictionary effectively "discards" any previous one.
 *
 * @result : 0, or an error code (which can be tested with ZSTD_isError()).
 *  Special: referencing a NULL DDict means "return to no-dictionary mode".
 *  Note 2 : DDict is just referenced, its lifetime must outlive its usage from DCtx.
 */
/* ZSTDLIB_API size_t ZSTD_DCtx_refDDict(ZSTD_DCtx* dctx, const ZSTD_DDict* ddict); */

/*! ZSTD_DCtx_refPrefix() : Requires v1.4.0+
 *  Reference a prefix (single-usage dictionary) to decompress next frame.
 *  This is the reverse operation of ZSTD_CCtx_refPrefix(),
 *  and must use the same prefix as the one used during compression.
 *  Prefix is **only used once**. Reference is discarded at end of frame.
 *  End of frame is reached when ZSTD_decompressStream() returns 0.
 * @result : 0, or an error code (which can be tested with ZSTD_isError()).
 *  Note 1 : Adding any prefix (including NULL) invalidates any previously set prefix or dictionary
 *  Note 2 : Prefix buffer is referenced. It **must** outlive decompression.
 *           Prefix buffer must remain unmodified up to the end of frame,
 *           reached when ZSTD_decompressStream() returns 0.
 *  Note 3 : By default, the prefix is treated as raw content (ZSTD_dct_rawContent).
 *           Use ZSTD_CCtx_refPrefix_advanced() to alter dictMode (Experimental section)
 *  Note 4 : Referencing a raw content prefix has almost no cpu nor memory cost.
 *           A full dictionary is more costly, as it requires building tables.
 */
/* ZSTDLIB_API size_t ZSTD_DCtx_refPrefix(ZSTD_DCtx* dctx,
                                 const void* prefix, size_t prefixSize); */

/* ===   Memory management   === */

/*! ZSTD_sizeof_*() : Requires v1.4.0+
 *  These functions give the _current_ memory usage of selected object.
 *  Note that object memory usage can evolve (increase or decrease) over time. */
/* ZSTDLIB_API size_t ZSTD_sizeof_CCtx(const ZSTD_CCtx* cctx); */
/* ZSTDLIB_API size_t ZSTD_sizeof_DCtx(const ZSTD_DCtx* dctx); */
/* ZSTDLIB_API size_t ZSTD_sizeof_CStream(const ZSTD_CStream* zcs); */
/* ZSTDLIB_API size_t ZSTD_sizeof_DStream(const ZSTD_DStream* zds); */
/* ZSTDLIB_API size_t ZSTD_sizeof_CDict(const ZSTD_CDict* cdict); */
/* ZSTDLIB_API size_t ZSTD_sizeof_DDict(const ZSTD_DDict* ddict); */

#if defined (__cplusplus)
}
#endif

#endif  /* ZSTD_H_235446 */

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under both the BSD-style license (found in the
 * LICENSE file in the root directory of this source tree) and the GPLv2 (found
 * in the COPYING file in the root directory of this source tree).
 * You may select, at your option, one of the above-listed licenses.
 */

#ifndef ZSTD_ERRORS_H_398273423
#define ZSTD_ERRORS_H_398273423

#if defined (__cplusplus)
extern "C" {
#endif

/* =====   ZSTDERRORLIB_API : control library symbols visibility   ===== */
#ifndef ZSTDERRORLIB_VISIBLE
   /* Backwards compatibility with old macro name */
#  ifdef ZSTDERRORLIB_VISIBILITY
#    define ZSTDERRORLIB_VISIBLE ZSTDERRORLIB_VISIBILITY
#  elif defined(__GNUC__) && (__GNUC__ >= 4) && !defined(__MINGW32__)
#    define ZSTDERRORLIB_VISIBLE __attribute__ ((visibility ("default")))
#  else
#    define ZSTDERRORLIB_VISIBLE
#  endif
#endif

#ifndef ZSTDERRORLIB_HIDDEN
#  if defined(__GNUC__) && (__GNUC__ >= 4) && !defined(__MINGW32__)
#    define ZSTDERRORLIB_HIDDEN __attribute__ ((visibility ("hidden")))
#  else
#    define ZSTDERRORLIB_HIDDEN
#  endif
#endif

#if defined(ZSTD_DLL_EXPORT) && (ZSTD_DLL_EXPORT==1)
#  define ZSTDERRORLIB_API __declspec(dllexport) ZSTDERRORLIB_VISIBLE
#elif defined(ZSTD_DLL_IMPORT) && (ZSTD_DLL_IMPORT==1)
#  define ZSTDERRORLIB_API __declspec(dllimport) ZSTDERRORLIB_VISIBLE /* It isn't required but allows to generate better code, saving a function pointer load from the IAT and an indirect jump.*/
#else
#  define ZSTDERRORLIB_API ZSTDERRORLIB_VISIBLE
#endif

/*-*********************************************
 *  Error codes list
 *-*********************************************
 *  Error codes _values_ are pinned down since v1.3.1 only.
 *  Therefore, don't rely on values if you may link to any version < v1.3.1.
 *
 *  Only values < 100 are considered stable.
 *
 *  note 1 : this API shall be used with static linking only.
 *           dynamic linking is not yet officially supported.
 *  note 2 : Prefer relying on the enum than on its value whenever possible
 *           This is the only supported way to use the error list < v1.3.1
 *  note 3 : ZSTD_isError() is always correct, whatever the library version.
 **********************************************/
typedef enum {
  ZSTD_error_no_error = 0,
  ZSTD_error_GENERIC  = 1,
  ZSTD_error_prefix_unknown                = 10,
  ZSTD_error_version_unsupported           = 12,
  ZSTD_error_frameParameter_unsupported    = 14,
  ZSTD_error_frameParameter_windowTooLarge = 16,
  ZSTD_error_corruption_detected = 20,
  ZSTD_error_checksum_wrong      = 22,
  ZSTD_error_literals_headerWrong = 24,
  ZSTD_error_dictionary_corrupted      = 30,
  ZSTD_error_dictionary_wrong          = 32,
  ZSTD_error_dictionaryCreation_failed = 34,
  ZSTD_error_parameter_unsupported   = 40,
  ZSTD_error_parameter_combination_unsupported = 41,
  ZSTD_error_parameter_outOfBound    = 42,
  ZSTD_error_tableLog_tooLarge       = 44,
  ZSTD_error_maxSymbolValue_tooLarge = 46,
  ZSTD_error_maxSymbolValue_tooSmall = 48,
  ZSTD_error_cannotProduce_uncompressedBlock = 49,
  ZSTD_error_stabilityCondition_notRespected = 50,
  ZSTD_error_stage_wrong       = 60,
  ZSTD_error_init_missing      = 62,
  ZSTD_error_memory_allocation = 64,
  ZSTD_error_workSpace_tooSmall= 66,
  ZSTD_error_dstSize_tooSmall = 70,
  ZSTD_error_srcSize_wrong    = 72,
  ZSTD_error_dstBuffer_null   = 74,
  ZSTD_error_noForwardProgress_destFull = 80,
  ZSTD_error_noForwardProgress_inputEmpty = 82,
  /* following error codes are __NOT STABLE__, they can be removed or changed in future versions */
  ZSTD_error_frameIndex_tooLarge = 100,
  ZSTD_error_seekableIO          = 102,
  ZSTD_error_dstBuffer_wrong     = 104,
  ZSTD_error_srcBuffer_wrong     = 105,
  ZSTD_error_sequenceProducer_failed = 106,
  ZSTD_error_externalSequences_invalid = 107,
  ZSTD_error_maxCode = 120  /* never EVER use this value directly, it can change in future versions! Use ZSTD_isError() instead */
} ZSTD_ErrorCode;

/* ZSTDERRORLIB_API const char* ZSTD_getErrorString(ZSTD_ErrorCode code); */   /**< Same as ZSTD_getErrorName, but using a `ZSTD_ErrorCode` enum argument */


#if defined (__cplusplus)
}
#endif

#endif /* ZSTD_ERRORS_H_398273423 */

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under both the BSD-style license (found in the
 * LICENSE file in the root directory of this source tree) and the GPLv2 (found
 * in the COPYING file in the root directory of this source tree).
 * You may select, at your option, one of the above-listed licenses.
 */

#ifndef ZSTD_ZDICT_H
#define ZSTD_ZDICT_H


/*======  Dependencies  ======*/
#include <stddef.h>  /* size_t */

#if defined (__cplusplus)
extern "C" {
#endif

/* =====   ZDICTLIB_API : control library symbols visibility   ===== */
#ifndef ZDICTLIB_VISIBLE
   /* Backwards compatibility with old macro name */
#  ifdef ZDICTLIB_VISIBILITY
#    define ZDICTLIB_VISIBLE ZDICTLIB_VISIBILITY
#  elif defined(__GNUC__) && (__GNUC__ >= 4) && !defined(__MINGW32__)
#    define ZDICTLIB_VISIBLE __attribute__ ((visibility ("default")))
#  else
#    define ZDICTLIB_VISIBLE
#  endif
#endif

#ifndef ZDICTLIB_HIDDEN
#  if defined(__GNUC__) && (__GNUC__ >= 4) && !defined(__MINGW32__)
#    define ZDICTLIB_HIDDEN __attribute__ ((visibility ("hidden")))
#  else
#    define ZDICTLIB_HIDDEN
#  endif
#endif

#if defined(ZSTD_DLL_EXPORT) && (ZSTD_DLL_EXPORT==1)
#  define ZDICTLIB_API __declspec(dllexport) ZDICTLIB_VISIBLE
#elif defined(ZSTD_DLL_IMPORT) && (ZSTD_DLL_IMPORT==1)
#  define ZDICTLIB_API __declspec(dllimport) ZDICTLIB_VISIBLE /* It isn't required but allows to generate better code, saving a function pointer load from the IAT and an indirect jump.*/
#else
#  define ZDICTLIB_API ZDICTLIB_VISIBLE
#endif

/*******************************************************************************
 * Zstd dictionary builder
 *
 * FAQ
 * ===
 * Why should I use a dictionary?
 * ------------------------------
 *
 * Zstd can use dictionaries to improve compression ratio of small data.
 * Traditionally small files don't compress well because there is very little
 * repetition in a single sample, since it is small. But, if you are compressing
 * many similar files, like a bunch of JSON records that share the same
 * structure, you can train a dictionary on ahead of time on some samples of
 * these files. Then, zstd can use the dictionary to find repetitions that are
 * present across samples. This can vastly improve compression ratio.
 *
 * When is a dictionary useful?
 * ----------------------------
 *
 * Dictionaries are useful when compressing many small files that are similar.
 * The larger a file is, the less benefit a dictionary will have. Generally,
 * we don't expect dictionary compression to be effective past 100KB. And the
 * smaller a file is, the more we would expect the dictionary to help.
 *
 * How do I use a dictionary?
 * --------------------------
 *
 * Simply pass the dictionary to the zstd compressor with
 * `ZSTD_CCtx_loadDictionary()`. The same dictionary must then be passed to
 * the decompressor, using `ZSTD_DCtx_loadDictionary()`. There are other
 * more advanced functions that allow selecting some options, see zstd.h for
 * complete documentation.
 *
 * What is a zstd dictionary?
 * --------------------------
 *
 * A zstd dictionary has two pieces: Its header, and its content. The header
 * contains a magic number, the dictionary ID, and entropy tables. These
 * entropy tables allow zstd to save on header costs in the compressed file,
 * which really matters for small data. The content is just bytes, which are
 * repeated content that is common across many samples.
 *
 * What is a raw content dictionary?
 * ---------------------------------
 *
 * A raw content dictionary is just bytes. It doesn't have a zstd dictionary
 * header, a dictionary ID, or entropy tables. Any buffer is a valid raw
 * content dictionary.
 *
 * How do I train a dictionary?
 * ----------------------------
 *
 * Gather samples from your use case. These samples should be similar to each
 * other. If you have several use cases, you could try to train one dictionary
 * per use case.
 *
 * Pass those samples to `ZDICT_trainFromBuffer()` and that will train your
 * dictionary. There are a few advanced versions of this function, but this
 * is a great starting point. If you want to further tune your dictionary
 * you could try `ZDICT_optimizeTrainFromBuffer_cover()`. If that is too slow
 * you can try `ZDICT_optimizeTrainFromBuffer_fastCover()`.
 *
 * If the dictionary training function fails, that is likely because you
 * either passed too few samples, or a dictionary would not be effective
 * for your data. Look at the messages that the dictionary trainer printed,
 * if it doesn't say too few samples, then a dictionary would not be effective.
 *
 * How large should my dictionary be?
 * ----------------------------------
 *
 * A reasonable dictionary size, the `dictBufferCapacity`, is about 100KB.
 * The zstd CLI defaults to a 110KB dictionary. You likely don't need a
 * dictionary larger than that. But, most use cases can get away with a
 * smaller dictionary. The advanced dictionary builders can automatically
 * shrink the dictionary for you, and select the smallest size that doesn't
 * hurt compression ratio too much. See the `shrinkDict` parameter.
 * A smaller dictionary can save memory, and potentially speed up
 * compression.
 *
 * How many samples should I provide to the dictionary builder?
 * ------------------------------------------------------------
 *
 * We generally recommend passing ~100x the size of the dictionary
 * in samples. A few thousand should suffice. Having too few samples
 * can hurt the dictionaries effectiveness. Having more samples will
 * only improve the dictionaries effectiveness. But having too many
 * samples can slow down the dictionary builder.
 *
 * How do I determine if a dictionary will be effective?
 * -----------------------------------------------------
 *
 * Simply train a dictionary and try it out. You can use zstd's built in
 * benchmarking tool to test the dictionary effectiveness.
 *
 *   # Benchmark levels 1-3 without a dictionary
 *   zstd -b1e3 -r /path/to/my/files
 *   # Benchmark levels 1-3 with a dictionary
 *   zstd -b1e3 -r /path/to/my/files -D /path/to/my/dictionary
 *
 * When should I retrain a dictionary?
 * -----------------------------------
 *
 * You should retrain a dictionary when its effectiveness drops. Dictionary
 * effectiveness drops as the data you are compressing changes. Generally, we do
 * expect dictionaries to "decay" over time, as your data changes, but the rate
 * at which they decay depends on your use case. Internally, we regularly
 * retrain dictionaries, and if the new dictionary performs significantly
 * better than the old dictionary, we will ship the new dictionary.
 *
 * I have a raw content dictionary, how do I turn it into a zstd dictionary?
 * -------------------------------------------------------------------------
 *
 * If you have a raw content dictionary, e.g. by manually constructing it, or
 * using a third-party dictionary builder, you can turn it into a zstd
 * dictionary by using `ZDICT_finalizeDictionary()`. You'll also have to
 * provide some samples of the data. It will add the zstd header to the
 * raw content, which contains a dictionary ID and entropy tables, which
 * will improve compression ratio, and allow zstd to write the dictionary ID
 * into the frame, if you so choose.
 *
 * Do I have to use zstd's dictionary builder?
 * -------------------------------------------
 *
 * No! You can construct dictionary content however you please, it is just
 * bytes. It will always be valid as a raw content dictionary. If you want
 * a zstd dictionary, which can improve compression ratio, use
 * `ZDICT_finalizeDictionary()`.
 *
 * What is the attack surface of a zstd dictionary?
 * ------------------------------------------------
 *
 * Zstd is heavily fuzz tested, including loading fuzzed dictionaries, so
 * zstd should never crash, or access out-of-bounds memory no matter what
 * the dictionary is. However, if an attacker can control the dictionary
 * during decompression, they can cause zstd to generate arbitrary bytes,
 * just like if they controlled the compressed data.
 *
 ******************************************************************************/


/*! ZDICT_trainFromBuffer():
 *  Train a dictionary from an array of samples.
 *  Redirect towards ZDICT_optimizeTrainFromBuffer_fastCover() single-threaded, with d=8, steps=4,
 *  f=20, and accel=1.
 *  Samples must be stored concatenated in a single flat buffer `samplesBuffer`,
 *  supplied with an array of sizes `samplesSizes`, providing the size of each sample, in order.
 *  The resulting dictionary will be saved into `dictBuffer`.
 * @return: size of dictionary stored into `dictBuffer` (<= `dictBufferCapacity`)
 *          or an error code, which can be tested with ZDICT_isError().
 *  Note:  Dictionary training will fail if there are not enough samples to construct a
 *         dictionary, or if most of the samples are too small (< 8 bytes being the lower limit).
 *         If dictionary training fails, you should use zstd without a dictionary, as the dictionary
 *         would've been ineffective anyways. If you believe your samples would benefit from a dictionary
 *         please open an issue with details, and we can look into it.
 *  Note: ZDICT_trainFromBuffer()'s memory usage is about 6 MB.
 *  Tips: In general, a reasonable dictionary has a size of ~ 100 KB.
 *        It's possible to select smaller or larger size, just by specifying `dictBufferCapacity`.
 *        In general, it's recommended to provide a few thousands samples, though this can vary a lot.
 *        It's recommended that total size of all samples be about ~x100 times the target size of dictionary.
 */
/* ZDICTLIB_API size_t ZDICT_trainFromBuffer(void* dictBuffer, size_t dictBufferCapacity,
                                    const void* samplesBuffer,
                                    const size_t* samplesSizes, unsigned nbSamples); */

typedef struct {
    int      compressionLevel;   /**< optimize for a specific zstd compression level; 0 means default */
    unsigned notificationLevel;  /**< Write log to stderr; 0 = none (default); 1 = errors; 2 = progression; 3 = details; 4 = debug; */
    unsigned dictID;             /**< force dictID value; 0 means auto mode (32-bits random value)
                                  *   NOTE: The zstd format reserves some dictionary IDs for future use.
                                  *         You may use them in private settings, but be warned that they
                                  *         may be used by zstd in a public dictionary registry in the future.
                                  *         These dictionary IDs are:
                                  *           - low range  : <= 32767
                                  *           - high range : >= (2^31)
                                  */
} ZDICT_params_t;

/*! ZDICT_finalizeDictionary():
 * Given a custom content as a basis for dictionary, and a set of samples,
 * finalize dictionary by adding headers and statistics according to the zstd
 * dictionary format.
 *
 * Samples must be stored concatenated in a flat buffer `samplesBuffer`,
 * supplied with an array of sizes `samplesSizes`, providing the size of each
 * sample in order. The samples are used to construct the statistics, so they
 * should be representative of what you will compress with this dictionary.
 *
 * The compression level can be set in `parameters`. You should pass the
 * compression level you expect to use in production. The statistics for each
 * compression level differ, so tuning the dictionary for the compression level
 * can help quite a bit.
 *
 * You can set an explicit dictionary ID in `parameters`, or allow us to pick
 * a random dictionary ID for you, but we can't guarantee no collisions.
 *
 * The dstDictBuffer and the dictContent may overlap, and the content will be
 * appended to the end of the header. If the header + the content doesn't fit in
 * maxDictSize the beginning of the content is truncated to make room, since it
 * is presumed that the most profitable content is at the end of the dictionary,
 * since that is the cheapest to reference.
 *
 * `maxDictSize` must be >= max(dictContentSize, ZDICT_DICTSIZE_MIN).
 *
 * @return: size of dictionary stored into `dstDictBuffer` (<= `maxDictSize`),
 *          or an error code, which can be tested by ZDICT_isError().
 * Note: ZDICT_finalizeDictionary() will push notifications into stderr if
 *       instructed to, using notificationLevel>0.
 * NOTE: This function currently may fail in several edge cases including:
 *         * Not enough samples
 *         * Samples are uncompressible
 *         * Samples are all exactly the same
 */
/* ZDICTLIB_API size_t ZDICT_finalizeDictionary(void* dstDictBuffer, size_t maxDictSize,
                                const void* dictContent, size_t dictContentSize,
                                const void* samplesBuffer, const size_t* samplesSizes, unsigned nbSamples,
                                ZDICT_params_t parameters); */


/*======   Helper functions   ======*/
/* ZDICTLIB_API unsigned ZDICT_getDictID(const void* dictBuffer, size_t dictSize); */  /**< extracts dictID; @return zero if error (not a valid dictionary) */
/* ZDICTLIB_API size_t ZDICT_getDictHeaderSize(const void* dictBuffer, size_t dictSize); */  /* returns dict header size; returns a ZSTD error code on failure */
/* ZDICTLIB_API unsigned ZDICT_isError(size_t errorCode); */
/* ZDICTLIB_API const char* ZDICT_getErrorName(size_t errorCode); */

#if defined (__cplusplus)
}
#endif

#endif   /* ZSTD_ZDICT_H */

#endif /* LIBRARIES_ZSTD_H */
