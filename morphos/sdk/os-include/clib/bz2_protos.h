#ifndef CLIB_BZ2_PROTOS_H
#define CLIB_BZ2_PROTOS_H

/*
 *  bz2.library
 *
 *  Copyright © 2016 he MorphOS Development Team. All rights reserved.
 *
 *  $Id: bz2_protos.h,v 1.4 2016/04/12 23:05:57 piru Exp $
 */

#ifndef LIBRARIES_BZ2_H
# include <libraries/bz2.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

const char * BZ2_bzlibVersion (void);
int      BZ2_bzCompressInit   (bz_stream *strm, int blockSize100k, int verbosity, int workFactor);
int      BZ2_bzCompress       (bz_stream *strm, int action );
int      BZ2_bzCompressEnd    (bz_stream *strm);
int      BZ2_bzDecompressInit (bz_stream *strm, int verbosity, int small);
int      BZ2_bzDecompress     (bz_stream *strm);
int      BZ2_bzDecompressEnd  (bz_stream *strm);
int      BZ2_bzBuffToBuffCompress   (char *dest, unsigned int *destLen, char *source, unsigned int sourceLen, int blockSize100k, int verbosity, int workFactor);
int      BZ2_bzBuffToBuffDecompress (char *dest, unsigned int *destLen, char *source, unsigned int sourceLen, int small, int verbosity);

#ifdef __cplusplus
}
#endif

#endif /* CLIB_BZ2_PROTOS_H */
