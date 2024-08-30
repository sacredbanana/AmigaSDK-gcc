#ifndef CLIB_BZIP2_PROTOS_H
#define CLIB_BZIP2_PROTOS_H

#ifndef LIBRARIES_BZIP2_H
#include <libraries/bzip2.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#   include <windows.h>
#   ifdef small
      /* windows.h define small to char */
#      undef small
#   endif
#   ifdef BZ_EXPORT
#   define BZ_API(func) WINAPI func
#   define BZ_EXTERN extern
#   else
   /* import windows dll dynamically */
#   define BZ_API(func) (WINAPI * func)
#   define BZ_EXTERN
#   endif
#else
#   define BZ_API(func) func
#   define BZ_EXTERN extern
#endif


/*-- Core (low-level) library functions --*/

BZ_EXTERN int BZ_API(BZ2_bzCompressInit) (
      bz_stream* strm,
      int        blockSize100k,
      int        verbosity,
      int        workFactor
   );

BZ_EXTERN int BZ_API(BZ2_bzCompress) (
      bz_stream* strm,
      int action
   );

BZ_EXTERN int BZ_API(BZ2_bzCompressEnd) (
      bz_stream* strm
   );

BZ_EXTERN int BZ_API(BZ2_bzDecompressInit) (
      bz_stream *strm,
      int       verbosity,
      int       small
   );

BZ_EXTERN int BZ_API(BZ2_bzDecompress) (
      bz_stream* strm
   );

BZ_EXTERN int BZ_API(BZ2_bzDecompressEnd) (
      bz_stream *strm
   );



/*-- High(er) level library functions --*/

#include <stdio.h>

BZ_EXTERN BZFILE* BZ_API(BZ2_bzReadOpen) (
      int*  bzerror,
      FILE* f,
      int   verbosity,
      int   small,
      void* unused,
      int   nUnused
   );

BZ_EXTERN void BZ_API(BZ2_bzReadClose) (
      int*    bzerror,
      BZFILE* b
   );

BZ_EXTERN void BZ_API(BZ2_bzReadGetUnused) (
      int*    bzerror,
      BZFILE* b,
      void**  unused,
      int*    nUnused
   );

BZ_EXTERN int BZ_API(BZ2_bzRead) (
      int*    bzerror,
      BZFILE* b,
      void*   buf,
      int     len
   );

BZ_EXTERN BZFILE* BZ_API(BZ2_bzWriteOpen) (
      int*  bzerror,
      FILE* f,
      int   blockSize100k,
      int   verbosity,
      int   workFactor
   );

BZ_EXTERN void BZ_API(BZ2_bzWrite) (
      int*    bzerror,
      BZFILE* b,
      void*   buf,
      int     len
   );

BZ_EXTERN void BZ_API(BZ2_bzWriteClose) (
      int*          bzerror,
      BZFILE*       b,
      int           abandon,
      unsigned int* nbytes_in,
      unsigned int* nbytes_out
   );

BZ_EXTERN void BZ_API(BZ2_bzWriteClose64) (
      int*          bzerror,
      BZFILE*       b,
      int           abandon,
      unsigned int* nbytes_in_lo32,
      unsigned int* nbytes_in_hi32,
      unsigned int* nbytes_out_lo32,
      unsigned int* nbytes_out_hi32
   );


/*-- Utility functions --*/

BZ_EXTERN int BZ_API(BZ2_bzBuffToBuffCompress) (
      char*         dest,
      unsigned int* destLen,
      char*         source,
      unsigned int  sourceLen,
      int           blockSize100k,
      int           verbosity,
      int           workFactor
   );

BZ_EXTERN int BZ_API(BZ2_bzBuffToBuffDecompress) (
      char*         dest,
      unsigned int* destLen,
      char*         source,
      unsigned int  sourceLen,
      int           small,
      int           verbosity
   );


/*--
   Code contributed by Yoshioka Tsuneo (tsuneo@rr.iij4u.or.jp)
   to support better zlib compatibility.
   This code is not _officially_ part of libbzip2 (yet);
   I haven't tested it, documented it, or considered the
   threading-safeness of it.
   If this code breaks, please contact both Yoshioka and me.
--*/

BZ_EXTERN const char * BZ_API(BZ2_bzlibVersion) (
      void
   );

#ifndef BZ_NO_STDIO
BZ_EXTERN BZFILE * BZ_API(BZ2_bzopen) (
      const char *path,
      const char *mode
   );

BZ_EXTERN BZFILE * BZ_API(BZ2_bzdopen) (
      int        fd,
      const char *mode
   );

BZ_EXTERN int BZ_API(BZ2_bzread) (
      BZFILE* b,
      void* buf,
      int len
   );

BZ_EXTERN int BZ_API(BZ2_bzwrite) (
      BZFILE* b,
      void*   buf,
      int     len
   );

BZ_EXTERN int BZ_API(BZ2_bzflush) (
      BZFILE* b
   );

BZ_EXTERN void BZ_API(BZ2_bzclose) (
      BZFILE* b
   );

BZ_EXTERN const char * BZ_API(BZ2_bzerror) (
      BZFILE *b,
      int    *errnum
   );
#endif

#ifdef __cplusplus
}
#endif

#endif /* CLIB_BZ2_PROTOS_H */
