/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_ZSTD_H
#define _PPCINLINE_ZSTD_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef ZSTD_BASE_NAME
#define ZSTD_BASE_NAME ZSTDBase
#endif /* !ZSTD_BASE_NAME */

#define ZSTD_versionNumber() \
	(((unsigned (*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 28))())

#define ZSTD_versionString() \
	(((const char *(*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 34))())

#define ZSTD_compress(__p0, __p1, __p2, __p3, __p4) \
	(((size_t (*)(void *, size_t , const void *, size_t , int ))*(void**)((long)(ZSTD_BASE_NAME) - 40))(__p0, __p1, __p2, __p3, __p4))

#define ZSTD_decompress(__p0, __p1, __p2, __p3) \
	(((size_t (*)(void *, size_t , const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 46))(__p0, __p1, __p2, __p3))

#define ZSTD_getFrameContentSize(__p0, __p1) \
	(((unsigned long long (*)(const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 52))(__p0, __p1))

#define ZSTD_getDecompressedSize(__p0, __p1) \
	(((unsigned long long (*)(const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 58))(__p0, __p1))

#define ZSTD_findFrameCompressedSize(__p0, __p1) \
	(((size_t (*)(const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 64))(__p0, __p1))

#define ZSTD_compressBound(__p0) \
	(((size_t (*)(size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 70))(__p0))

#define ZSTD_isError(__p0) \
	(((unsigned (*)(size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 76))(__p0))

#define ZSTD_getErrorCode(__p0) \
	(((ZSTD_ErrorCode (*)(size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 82))(__p0))

#define ZSTD_getErrorName(__p0) \
	(((const char *(*)(size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 88))(__p0))

#define ZSTD_minCLevel() \
	(((int (*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 94))())

#define ZSTD_maxCLevel() \
	(((int (*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 100))())

#define ZSTD_defaultCLevel() \
	(((int (*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 106))())

#define ZSTD_createCCtx() \
	(((ZSTD_CCtx *(*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 118))())

#define ZSTD_freeCCtx(__p0) \
	(((size_t (*)(ZSTD_CCtx *))*(void**)((long)(ZSTD_BASE_NAME) - 124))(__p0))

#define ZSTD_compressCCtx(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((size_t (*)(ZSTD_CCtx *, void *, size_t , const void *, size_t , int ))*(void**)((long)(ZSTD_BASE_NAME) - 130))(__p0, __p1, __p2, __p3, __p4, __p5))

#define ZSTD_createDCtx() \
	(((ZSTD_DCtx *(*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 136))())

#define ZSTD_freeDCtx(__p0) \
	(((size_t (*)(ZSTD_DCtx *))*(void**)((long)(ZSTD_BASE_NAME) - 142))(__p0))

#define ZSTD_decompressDCtx(__p0, __p1, __p2, __p3, __p4) \
	(((size_t (*)(ZSTD_DCtx *, void *, size_t , const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 148))(__p0, __p1, __p2, __p3, __p4))

#define ZSTD_cParam_getBounds(__p0) \
	(((ZSTD_bounds (*)(ZSTD_cParameter ))*(void**)((long)(ZSTD_BASE_NAME) - 154))(__p0))

#define ZSTD_CCtx_setParameter(__p0, __p1, __p2) \
	(((size_t (*)(ZSTD_CCtx *, ZSTD_cParameter , int ))*(void**)((long)(ZSTD_BASE_NAME) - 160))(__p0, __p1, __p2))

#define ZSTD_CCtx_setPledgedSrcSize(__p0, __p1) \
	(((size_t (*)(ZSTD_CCtx *, unsigned long long ))*(void**)((long)(ZSTD_BASE_NAME) - 166))(__p0, __p1))

#define ZSTD_CCtx_reset(__p0, __p1) \
	(((size_t (*)(ZSTD_CCtx *, ZSTD_ResetDirective ))*(void**)((long)(ZSTD_BASE_NAME) - 172))(__p0, __p1))

#define ZSTD_compress2(__p0, __p1, __p2, __p3, __p4) \
	(((size_t (*)(ZSTD_CCtx *, void *, size_t , const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 178))(__p0, __p1, __p2, __p3, __p4))

#define ZSTD_dParam_getBounds(__p0) \
	(((ZSTD_bounds (*)(ZSTD_dParameter ))*(void**)((long)(ZSTD_BASE_NAME) - 184))(__p0))

#define ZSTD_DCtx_setParameter(__p0, __p1, __p2) \
	(((size_t (*)(ZSTD_DCtx *, ZSTD_dParameter , int ))*(void**)((long)(ZSTD_BASE_NAME) - 190))(__p0, __p1, __p2))

#define ZSTD_DCtx_reset(__p0, __p1) \
	(((size_t (*)(ZSTD_DCtx *, ZSTD_ResetDirective ))*(void**)((long)(ZSTD_BASE_NAME) - 196))(__p0, __p1))

#define ZSTD_createCStream() \
	(((ZSTD_CStream *(*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 202))())

#define ZSTD_freeCStream(__p0) \
	(((size_t (*)(ZSTD_CStream *))*(void**)((long)(ZSTD_BASE_NAME) - 208))(__p0))

#define ZSTD_compressStream2(__p0, __p1, __p2, __p3) \
	(((size_t (*)(ZSTD_CCtx *, ZSTD_outBuffer *, ZSTD_inBuffer *, ZSTD_EndDirective ))*(void**)((long)(ZSTD_BASE_NAME) - 214))(__p0, __p1, __p2, __p3))

#define ZSTD_CStreamInSize() \
	(((size_t (*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 220))())

#define ZSTD_CStreamOutSize() \
	(((size_t (*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 226))())

#define ZSTD_initCStream(__p0, __p1) \
	(((size_t (*)(ZSTD_CStream *, int ))*(void**)((long)(ZSTD_BASE_NAME) - 232))(__p0, __p1))

#define ZSTD_compressStream(__p0, __p1, __p2) \
	(((size_t (*)(ZSTD_CStream *, ZSTD_outBuffer *, ZSTD_inBuffer *))*(void**)((long)(ZSTD_BASE_NAME) - 238))(__p0, __p1, __p2))

#define ZSTD_flushStream(__p0, __p1) \
	(((size_t (*)(ZSTD_CStream *, ZSTD_outBuffer *))*(void**)((long)(ZSTD_BASE_NAME) - 244))(__p0, __p1))

#define ZSTD_endStream(__p0, __p1) \
	(((size_t (*)(ZSTD_CStream *, ZSTD_outBuffer *))*(void**)((long)(ZSTD_BASE_NAME) - 250))(__p0, __p1))

#define ZSTD_createDStream() \
	(((ZSTD_DStream *(*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 256))())

#define ZSTD_freeDStream(__p0) \
	(((size_t (*)(ZSTD_DStream *))*(void**)((long)(ZSTD_BASE_NAME) - 262))(__p0))

#define ZSTD_initDStream(__p0) \
	(((size_t (*)(ZSTD_DStream *))*(void**)((long)(ZSTD_BASE_NAME) - 268))(__p0))

#define ZSTD_decompressStream(__p0, __p1, __p2) \
	(((size_t (*)(ZSTD_DStream *, ZSTD_outBuffer *, ZSTD_inBuffer *))*(void**)((long)(ZSTD_BASE_NAME) - 274))(__p0, __p1, __p2))

#define ZSTD_DStreamInSize() \
	(((size_t (*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 280))())

#define ZSTD_DStreamOutSize() \
	(((size_t (*)(void))*(void**)((long)(ZSTD_BASE_NAME) - 286))())

#define ZSTD_compress_usingDict(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((size_t (*)(ZSTD_CCtx *, void *, size_t , const void *, size_t , const void *, size_t , int ))*(void**)((long)(ZSTD_BASE_NAME) - 292))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define ZSTD_decompress_usingDict(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((size_t (*)(ZSTD_DCtx *, void *, size_t , const void *, size_t , const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 298))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define ZSTD_createCDict(__p0, __p1, __p2) \
	(((ZSTD_CDict *(*)(const void *, size_t , int ))*(void**)((long)(ZSTD_BASE_NAME) - 304))(__p0, __p1, __p2))

#define ZSTD_freeCDict(__p0) \
	(((size_t (*)(ZSTD_CDict *))*(void**)((long)(ZSTD_BASE_NAME) - 310))(__p0))

#define ZSTD_compress_usingCDict(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((size_t (*)(ZSTD_CCtx *, void *, size_t , const void *, size_t , const ZSTD_CDict *))*(void**)((long)(ZSTD_BASE_NAME) - 316))(__p0, __p1, __p2, __p3, __p4, __p5))

#define ZSTD_createDDict(__p0, __p1) \
	(((ZSTD_DDict *(*)(const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 322))(__p0, __p1))

#define ZSTD_freeDDict(__p0) \
	(((size_t (*)(ZSTD_DDict *))*(void**)((long)(ZSTD_BASE_NAME) - 328))(__p0))

#define ZSTD_decompress_usingDDict(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((size_t (*)(ZSTD_DCtx *, void *, size_t , const void *, size_t , const ZSTD_DDict *))*(void**)((long)(ZSTD_BASE_NAME) - 334))(__p0, __p1, __p2, __p3, __p4, __p5))

#define ZSTD_getDictID_fromDict(__p0, __p1) \
	(((unsigned (*)(const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 340))(__p0, __p1))

#define ZSTD_getDictID_fromCDict(__p0) \
	(((unsigned (*)(const ZSTD_CDict *))*(void**)((long)(ZSTD_BASE_NAME) - 346))(__p0))

#define ZSTD_getDictID_fromDDict(__p0) \
	(((unsigned (*)(const ZSTD_DDict *))*(void**)((long)(ZSTD_BASE_NAME) - 352))(__p0))

#define ZSTD_getDictID_fromFrame(__p0, __p1) \
	(((unsigned (*)(const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 358))(__p0, __p1))

#define ZSTD_CCtx_loadDictionary(__p0, __p1, __p2) \
	(((size_t (*)(ZSTD_CCtx *, const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 364))(__p0, __p1, __p2))

#define ZSTD_CCtx_refCDict(__p0, __p1) \
	(((size_t (*)(ZSTD_CCtx *, const ZSTD_CDict *))*(void**)((long)(ZSTD_BASE_NAME) - 370))(__p0, __p1))

#define ZSTD_CCtx_refPrefix(__p0, __p1, __p2) \
	(((size_t (*)(ZSTD_CCtx *, const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 376))(__p0, __p1, __p2))

#define ZSTD_DCtx_loadDictionary(__p0, __p1, __p2) \
	(((size_t (*)(ZSTD_DCtx *, const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 382))(__p0, __p1, __p2))

#define ZSTD_DCtx_refDDict(__p0, __p1) \
	(((size_t (*)(ZSTD_DCtx *, const ZSTD_DDict *))*(void**)((long)(ZSTD_BASE_NAME) - 388))(__p0, __p1))

#define ZSTD_DCtx_refPrefix(__p0, __p1, __p2) \
	(((size_t (*)(ZSTD_DCtx *, const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 394))(__p0, __p1, __p2))

#define ZSTD_sizeof_CCtx(__p0) \
	(((size_t (*)(const ZSTD_CCtx *))*(void**)((long)(ZSTD_BASE_NAME) - 400))(__p0))

#define ZSTD_sizeof_DCtx(__p0) \
	(((size_t (*)(const ZSTD_DCtx *))*(void**)((long)(ZSTD_BASE_NAME) - 406))(__p0))

#define ZSTD_sizeof_CStream(__p0) \
	(((size_t (*)(const ZSTD_CStream *))*(void**)((long)(ZSTD_BASE_NAME) - 412))(__p0))

#define ZSTD_sizeof_DStream(__p0) \
	(((size_t (*)(const ZSTD_DStream *))*(void**)((long)(ZSTD_BASE_NAME) - 418))(__p0))

#define ZSTD_sizeof_CDict(__p0) \
	(((size_t (*)(const ZSTD_CDict *))*(void**)((long)(ZSTD_BASE_NAME) - 424))(__p0))

#define ZSTD_sizeof_DDict(__p0) \
	(((size_t (*)(const ZSTD_DDict *))*(void**)((long)(ZSTD_BASE_NAME) - 430))(__p0))

#define ZSTD_getErrorString(__p0) \
	(((const char *(*)(ZSTD_ErrorCode ))*(void**)((long)(ZSTD_BASE_NAME) - 112))(__p0))

#define ZDICT_trainFromBuffer(__p0, __p1, __p2, __p3, __p4) \
	(((size_t (*)(void *, size_t , const void *, const size_t *, unsigned ))*(void**)((long)(ZSTD_BASE_NAME) - 436))(__p0, __p1, __p2, __p3, __p4))

#define ZDICT_finalizeDictionary(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((size_t (*)(void *, size_t , const void *, size_t , const void *, const size_t *, unsigned , ZDICT_params_t ))*(void**)((long)(ZSTD_BASE_NAME) - 442))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define ZDICT_getDictID(__p0, __p1) \
	(((unsigned (*)(const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 448))(__p0, __p1))

#define ZDICT_getDictHeaderSize(__p0, __p1) \
	(((size_t (*)(const void *, size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 454))(__p0, __p1))

#define ZDICT_isError(__p0) \
	(((unsigned (*)(size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 460))(__p0))

#define ZDICT_getErrorName(__p0) \
	(((const char *(*)(size_t ))*(void**)((long)(ZSTD_BASE_NAME) - 466))(__p0))

#endif /* !_PPCINLINE_ZSTD_H */
