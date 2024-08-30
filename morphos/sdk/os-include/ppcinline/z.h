/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_Z_H
#define _PPCINLINE_Z_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef Z_BASE_NAME
#define Z_BASE_NAME ZBase
#endif /* !Z_BASE_NAME */

#define zlibVersion() \
	(((const char *(*)(void))*(void**)((long)(Z_BASE_NAME) - 28))())

#define deflate(__p0, __p1) \
	(((int (*)(z_streamp , int ))*(void**)((long)(Z_BASE_NAME) - 46))(__p0, __p1))

#define deflateEnd(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 52))(__p0))

#define inflate(__p0, __p1) \
	(((int (*)(z_streamp , int ))*(void**)((long)(Z_BASE_NAME) - 94))(__p0, __p1))

#define inflateEnd(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 100))(__p0))

#define deflateSetDictionary(__p0, __p1, __p2) \
	(((int (*)(z_streamp , const Bytef *, uInt ))*(void**)((long)(Z_BASE_NAME) - 58))(__p0, __p1, __p2))

#define deflateCopy(__p0, __p1) \
	(((int (*)(z_streamp , z_streamp ))*(void**)((long)(Z_BASE_NAME) - 64))(__p0, __p1))

#define deflateReset(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 70))(__p0))

#define deflateParams(__p0, __p1, __p2) \
	(((int (*)(z_streamp , int , int ))*(void**)((long)(Z_BASE_NAME) - 76))(__p0, __p1, __p2))

#define deflateTune(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(z_streamp , int , int , int , int ))*(void**)((long)(Z_BASE_NAME) - 244))(__p0, __p1, __p2, __p3, __p4))

#define deflateSetHeader(__p0, __p1) \
	(((int (*)(z_streamp , gz_headerp ))*(void**)((long)(Z_BASE_NAME) - 250))(__p0, __p1))

#define inflateSetDictionary(__p0, __p1, __p2) \
	(((int (*)(z_streamp , const Bytef *, uInt ))*(void**)((long)(Z_BASE_NAME) - 106))(__p0, __p1, __p2))

#define inflateGetDictionary(__p0, __p1, __p2) \
	(((int (*)(z_streamp , Bytef *, uInt *))*(void**)((long)(Z_BASE_NAME) - 328))(__p0, __p1, __p2))

#define inflateSync(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 112))(__p0))

#define inflateReset(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 118))(__p0))

#define inflateReset2(__p0, __p1) \
	(((int (*)(z_streamp , int ))*(void**)((long)(Z_BASE_NAME) - 280))(__p0, __p1))

#define inflatePrime(__p0, __p1, __p2) \
	(((int (*)(z_streamp , int , int ))*(void**)((long)(Z_BASE_NAME) - 256))(__p0, __p1, __p2))

#define inflateMark(__p0) \
	(((long (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 286))(__p0))

#define inflateGetHeader(__p0, __p1) \
	(((int (*)(z_streamp , gz_headerp ))*(void**)((long)(Z_BASE_NAME) - 262))(__p0, __p1))

#define compress(__p0, __p1, __p2, __p3) \
	(((int (*)(Bytef *, uLongf *, const Bytef *, uLong ))*(void**)((long)(Z_BASE_NAME) - 124))(__p0, __p1, __p2, __p3))

#define compress2(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(Bytef *, uLongf *, const Bytef *, uLong , int ))*(void**)((long)(Z_BASE_NAME) - 130))(__p0, __p1, __p2, __p3, __p4))

#define uncompress(__p0, __p1, __p2, __p3) \
	(((int (*)(Bytef *, uLongf *, const Bytef *, uLong ))*(void**)((long)(Z_BASE_NAME) - 136))(__p0, __p1, __p2, __p3))

#define deflateInit_(__p0, __p1, __p2, __p3) \
	(((int (*)(z_streamp , int , const char *, int ))*(void**)((long)(Z_BASE_NAME) - 34))(__p0, __p1, __p2, __p3))

#define inflateInit_(__p0, __p1, __p2) \
	(((int (*)(z_streamp , const char *, int ))*(void**)((long)(Z_BASE_NAME) - 82))(__p0, __p1, __p2))

#define deflateInit2_(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((int (*)(z_streamp , int , int , int , int , int , const char *, int ))*(void**)((long)(Z_BASE_NAME) - 40))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define inflateInit2_(__p0, __p1, __p2, __p3) \
	(((int (*)(z_streamp , int , const char *, int ))*(void**)((long)(Z_BASE_NAME) - 88))(__p0, __p1, __p2, __p3))

#define adler32(__p0, __p1, __p2) \
	(((uLong (*)(uLong , const Bytef *, uInt ))*(void**)((long)(Z_BASE_NAME) - 142))(__p0, __p1, __p2))

#define adler32_combine(__p0, __p1, __p2) \
	(((uLong (*)(uLong , uLong , z_off_t ))*(void**)((long)(Z_BASE_NAME) - 268))(__p0, __p1, __p2))

#define crc32(__p0, __p1, __p2) \
	(((uLong (*)(uLong , const Bytef *, uInt ))*(void**)((long)(Z_BASE_NAME) - 148))(__p0, __p1, __p2))

#define crc32_combine(__p0, __p1, __p2) \
	(((uLong (*)(uLong , uLong , z_off_t ))*(void**)((long)(Z_BASE_NAME) - 274))(__p0, __p1, __p2))

#define adler32_combine64(__p0, __p1, __p2) \
	(((uLong (*)(uLong , uLong , z_off64_t ))*(void**)((long)(Z_BASE_NAME) - 292))(__p0, __p1, __p2))

#define crc32_combine64(__p0, __p1, __p2) \
	(((uLong (*)(uLong , uLong , z_off64_t ))*(void**)((long)(Z_BASE_NAME) - 298))(__p0, __p1, __p2))

#define zError(__p0) \
	(((const char *(*)(int ))*(void**)((long)(Z_BASE_NAME) - 154))(__p0))

#define inflateSyncPoint(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 160))(__p0))

#define get_crc_table() \
	(((const z_crc_t *(*)(void))*(void**)((long)(Z_BASE_NAME) - 166))())

#define inflateUndermine(__p0, __p1) \
	(((int (*)(z_streamp , int ))*(void**)((long)(Z_BASE_NAME) - 304))(__p0, __p1))

#define inflateResetKeep(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 316))(__p0))

#define deflateResetKeep(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 322))(__p0))

#define zlibCompileFlags() \
	(((uLong (*)(void))*(void**)((long)(Z_BASE_NAME) - 214))())

#define inflateCopy(__p0, __p1) \
	(((int (*)(z_streamp , z_streamp ))*(void**)((long)(Z_BASE_NAME) - 172))(__p0, __p1))

#define inflateBackInit_(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(z_streamp , int , unsigned char *, const char *, int ))*(void**)((long)(Z_BASE_NAME) - 178))(__p0, __p1, __p2, __p3, __p4))

#define inflateBack(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(z_streamp , in_func , void *, out_func , void *))*(void**)((long)(Z_BASE_NAME) - 184))(__p0, __p1, __p2, __p3, __p4))

#define inflateBackEnd(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 190))(__p0))

#define compressBound(__p0) \
	(((uLong (*)(uLong ))*(void**)((long)(Z_BASE_NAME) - 208))(__p0))

#define deflateBound(__p0, __p1) \
	(((uLong (*)(z_streamp , uLong ))*(void**)((long)(Z_BASE_NAME) - 196))(__p0, __p1))

#define deflatePrime(__p0, __p1, __p2) \
	(((int (*)(z_streamp , int , int ))*(void**)((long)(Z_BASE_NAME) - 202))(__p0, __p1, __p2))

#define deflatePending(__p0, __p1, __p2) \
	(((int (*)(z_streamp , unsigned *, int *))*(void**)((long)(Z_BASE_NAME) - 310))(__p0, __p1, __p2))

#define blast(__p0, __p1, __p2, __p3) \
	(((int (*)(blast_in , void *, blast_out , void *))*(void**)((long)(Z_BASE_NAME) - 220))(__p0, __p1, __p2, __p3))

#define inflateBack9(__p0, __p1, __p2, __p3, __p4) \
	(((int (*)(z_streamp , in_func , void *, out_func , void *))*(void**)((long)(Z_BASE_NAME) - 226))(__p0, __p1, __p2, __p3, __p4))

#define inflateBack9End(__p0) \
	(((int (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 232))(__p0))

#define inflateBack9Init_(__p0, __p1, __p2, __p3) \
	(((int (*)(z_streamp , unsigned char *, const char *, int ))*(void**)((long)(Z_BASE_NAME) - 238))(__p0, __p1, __p2, __p3))

#define deflateGetDictionary(__p0, __p1, __p2) \
	(((int (*)(z_streamp , Bytef *, uInt *))*(void**)((long)(Z_BASE_NAME) - 334))(__p0, __p1, __p2))

#define uncompress2(__p0, __p1, __p2, __p3) \
	(((int (*)(Bytef *, uLongf *, const Bytef *, uLong *))*(void**)((long)(Z_BASE_NAME) - 340))(__p0, __p1, __p2, __p3))

#define inflateValidate(__p0, __p1) \
	(((int (*)(z_streamp , int ))*(void**)((long)(Z_BASE_NAME) - 346))(__p0, __p1))

#define inflateCodesUsed(__p0) \
	(((unsigned long (*)(z_streamp ))*(void**)((long)(Z_BASE_NAME) - 352))(__p0))

#endif /* !_PPCINLINE_Z_H */
