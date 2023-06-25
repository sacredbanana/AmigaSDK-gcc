#ifndef _INLINE_BZIP2_H
#define _INLINE_BZIP2_H

#ifndef CLIB_BZIP2_PROTOS_H
#define CLIB_BZIP2_PROTOS_H
#endif

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif

#ifndef  LIBRARIES_BZIP2_H
#include <libraries/bzip2.h>
#endif

#ifndef BZIP2_BASE_NAME
#define BZIP2_BASE_NAME BZip2Base
#endif

#define BZ2_bzlibVersion() \
	LP0(0x1e, const char *, BZ2_bzlibVersion, \
	, BZIP2_BASE_NAME)

#define BZ2_bzCompressInit(strm, blockSize100k, verbosity, workFactor) \
	LP4(0x24, int, BZ2_bzCompressInit, bz_stream*, strm, a0, int, blockSize100k, d0, int, verbosity, d1, int, workFactor, d2, \
	, BZIP2_BASE_NAME)

#define BZ2_bzCompress(strm, action) \
	LP2(0x2a, int, BZ2_bzCompress, bz_stream*, strm, a0, int, action, d0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzCompressEnd(strm) \
	LP1(0x30, int, BZ2_bzCompressEnd, bz_stream*, strm, a0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzDecompressInit(strm, verbosity, small) \
	LP3(0x36, int, BZ2_bzDecompressInit, bz_stream*, strm, a0, int, verbosity, d0, int, small, d1, \
	, BZIP2_BASE_NAME)

#define BZ2_bzDecompress(strm) \
	LP1(0x3c, int, BZ2_bzDecompress, bz_stream*, strm, a0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzDecompressEnd(strm) \
	LP1(0x42, int, BZ2_bzDecompressEnd, bz_stream*, strm, a0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzBuffToBuffCompress(dest, destLen, source, sourceLen, blockSize100k, verbosity, workFactor) \
	LP7(0x48, int, BZ2_bzBuffToBuffCompress, char *, dest, a0, unsigned int *, destLen, a1, char *, source, a2, unsigned int, sourceLen, d0, int, blockSize100k, d1, int, verbosity, d2, int, workFactor, d3, \
	, BZIP2_BASE_NAME)

#define BZ2_bzBuffToBuffDecompress(dest, destLen, source, sourceLen, small, verbosity) \
	LP6(0x4e, int, BZ2_bzBuffToBuffDecompress, char *, dest, a0, unsigned int *, destLen, a1, char *, source, a2, unsigned int, sourceLen, d0, int, small, d1, int, verbosity, d2, \
	, BZIP2_BASE_NAME)

#define BZ2_bzReadOpen(bzerror, f, verbosity, small, unused, nUnused) \
	LP6(0x54, BZFILE *, BZ2_bzReadOpen, int *, bzerror, a0, FILE *, f, a1, int, verbosity, d0, int, small, d1, void *, unused, a2, int, nUnused, d2, \
	, BZIP2_BASE_NAME)

#define BZ2_bzReadClose(bzerror, b) \
	LP2NR(0x5a, BZ2_bzReadClose, int *, bzerror, a0, BZFILE *, b, a1, \
	, BZIP2_BASE_NAME)

#define BZ2_bzReadGetUnused(bzerror, b, unused, nUnused) \
	LP4NR(0x60, BZ2_bzReadGetUnused, int *, bzerror, a0, BZFILE *, b, a1, void **, unused, a2, int *, nUnused, a3, \
	, BZIP2_BASE_NAME)

#define BZ2_bzRead(bzerror, b, buf, len) \
	LP4(0x66, int, BZ2_bzRead, int *, bzerror, a0, BZFILE *, b, a1, void *, buf, a2, int, len, d0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzWriteOpen(bzerror, f, blockSize100k, verbosity, workFactor) \
	LP6(0x6c, BZFILE *, BZ2_bzWriteOpen, int *, bzerror, a0, FILE *, f, a1, int, blockSize100k, d0, int, verbosity, d1, int, workFactor, d2, \
	, BZIP2_BASE_NAME)

#define BZ2_bzWrite(bzerror, b, buf, len) \
	LP4(0x72, int, BZ2_bzWrite, int *, bzerror, a0, BZFILE *, b, a1, void *, buf, a2, int, len, d0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzWriteClose(bzerror, b, abandon, nbytes_in, nbytes_out) \
	LP5NR(0x78, BZ2_bzWriteClose, int *, bzerror, a0, BZFILE *, b, a1, int, abandon, d0, int *, nbytes_in, a2, int *, nbytes_out, a3, \
	, BZIP2_BASE_NAME)

#define BZ2_bzWriteClose64(bzerror, b, abandon, nbytes_in_lo32, nbytes_in_hi32, nbytes_out_lo32, nbytes_out_hi32) \
	LP7NR(0x7e, BZ2_bzWriteClose64, int *, bzerror, a0, BZFILE *, b, a1, int, abandon, d0, int *, nbytes_in_lo32, a2, int *, nbytes_in_hi32, a3, int *, nbytes_out_lo32, a4, int *, nbytes_out_hi32, a5, \
	, BZIP2_BASE_NAME)

#define BZ2_bzopen(path, mode) \
	LP2(0x84, BZFILE *, BZ2_bzopen, const char *, path, a0, const char *, mode, a1, \
	, BZIP2_BASE_NAME)

#define BZ2_bzdopen(fd, mode) \
	LP2(0x8a, BZFILE *, BZ2_bzdopen, int, fd, d0, const char *, mode, a0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzread(b, buf, len) \
	LP3(0x90, int, BZ2_bzread, BZFILE *, b, a0, void *, buf, a1, int, len, d0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzwrite(b, buf, len) \
	LP3(0x96, int, BZ2_bzwrite, BZFILE *, b, a0, void *, buf, a1, int, len, d0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzflush(b) \
	LP1(0x9c, int, BZ2_bzflush, BZFILE *, b, a0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzclose(b) \
	LP1NR(0xa2, int, BZ2_bzclose, BZFILE *, b, a0, \
	, BZIP2_BASE_NAME)

#define BZ2_bzerror(b, errnum) \
	LP2(0xa8, const char *, BZ2_bzerror, BZFILE *, b, a0, int *, errnum, a1, \
	, BZIP2_BASE_NAME)

#endif /*  _INLINE_BZIP2_H  */
