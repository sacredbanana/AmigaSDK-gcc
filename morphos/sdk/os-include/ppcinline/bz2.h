/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_BZ2_H
#define _PPCINLINE_BZ2_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef BZ2_BASE_NAME
#define BZ2_BASE_NAME BZ2Base
#endif /* !BZ2_BASE_NAME */

#define BZ2_bzlibVersion() \
	(((const char *(*)(void))*(void**)((long)(BZ2_BASE_NAME) - 28))())

#define BZ2_bzBuffToBuffDecompress(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((int (*)(char *, unsigned int *, char *, unsigned int , int , int ))*(void**)((long)(BZ2_BASE_NAME) - 148))(__p0, __p1, __p2, __p3, __p4, __p5))

#define BZ2_bzCompressInit(__p0, __p1, __p2, __p3) \
	(((int (*)(bz_stream *, int , int , int ))*(void**)((long)(BZ2_BASE_NAME) - 82))(__p0, __p1, __p2, __p3))

#define BZ2_bzCompressEnd(__p0) \
	(((int (*)(bz_stream *))*(void**)((long)(BZ2_BASE_NAME) - 94))(__p0))

#define BZ2_bzDecompressInit(__p0, __p1, __p2) \
	(((int (*)(bz_stream *, int , int ))*(void**)((long)(BZ2_BASE_NAME) - 100))(__p0, __p1, __p2))

#define BZ2_bzCompress(__p0, __p1) \
	(((int (*)(bz_stream *, int ))*(void**)((long)(BZ2_BASE_NAME) - 88))(__p0, __p1))

#define BZ2_bzDecompressEnd(__p0) \
	(((int (*)(bz_stream *))*(void**)((long)(BZ2_BASE_NAME) - 112))(__p0))

#define BZ2_bzDecompress(__p0) \
	(((int (*)(bz_stream *))*(void**)((long)(BZ2_BASE_NAME) - 106))(__p0))

#define BZ2_bzBuffToBuffCompress(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((int (*)(char *, unsigned int *, char *, unsigned int , int , int , int ))*(void**)((long)(BZ2_BASE_NAME) - 142))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#endif /* !_PPCINLINE_BZ2_H */
