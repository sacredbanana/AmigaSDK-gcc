/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_TIFF_H
#define _PPCINLINE_TIFF_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef TIFF_BASE_NAME
#define TIFF_BASE_NAME TIFFBase
#endif /* !TIFF_BASE_NAME */

#define TIFFGetSizeProc(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFSizeProc (*)(TIFF *))*(void**)(__base - 778))(__t__p0));\
	})

#define TIFFSwabArrayOfDouble(__p0, __p1) \
	({ \
		double * __t__p0 = __p0;\
		unsigned long  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double *, unsigned long ))*(void**)(__base - 610))(__t__p0, __t__p1));\
	})

#define TIFFWriteScanline(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		tdata_t  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		tsample_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, tdata_t , uint32 , tsample_t ))*(void**)(__base - 76))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFWriteCheck(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, int , const char *))*(void**)(__base - 334))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFGetClientInfo(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void *(*)(TIFF *, const char *))*(void**)(__base - 664))(__t__p0, __t__p1));\
	})

#define TIFFNumberOfTiles(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((ttile_t (*)(TIFF *))*(void**)(__base - 490))(__t__p0));\
	})

#define TIFFRewriteDirectory(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 388))(__t__p0));\
	})

#define TIFFVGetFieldDefaulted(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttag_t  __t__p1 = __p1;\
		va_list  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, ttag_t , va_list ))*(void**)(__base - 178))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFReadRGBAStrip(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		tstrip_t  __t__p1 = __p1;\
		uint32 * __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, tstrip_t , uint32 *))*(void**)(__base - 70))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFSetMode(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, int ))*(void**)(__base - 742))(__t__p0, __t__p1));\
	})

#define TIFFFileName(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(TIFF *))*(void**)(__base - 442))(__t__p0));\
	})

#define TIFFRawStripSize(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		tstrip_t  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, tstrip_t ))*(void**)(__base - 208))(__t__p0, __t__p1));\
	})

#define TIFFCreateDirectory(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 340))(__t__p0));\
	})

#define TIFFVSetField(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttag_t  __t__p1 = __p1;\
		va_list  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, ttag_t , va_list ))*(void**)(__base - 370))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFCleanup(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFF *))*(void**)(__base - 718))(__t__p0));\
	})

#define TIFFSetClientdata(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		thandle_t  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((thandle_t (*)(TIFF *, thandle_t ))*(void**)(__base - 736))(__t__p0, __t__p1));\
	})

#define TIFFReadRGBAImageOriented(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		uint32 * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		int  __t__p5 = __p5;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, uint32 , uint32 , uint32 *, int , int ))*(void**)(__base - 58))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define TIFFReadRGBAImage(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		uint32 * __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, uint32 , uint32 , uint32 *, int ))*(void**)(__base - 406))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define TIFFUnlinkDirectory(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		tdir_t  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, tdir_t ))*(void**)(__base - 364))(__t__p0, __t__p1));\
	})

#define TIFFGetReadProc(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFReadWriteProc (*)(TIFF *))*(void**)(__base - 754))(__t__p0));\
	})

#define TIFFTileRowSize(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *))*(void**)(__base - 220))(__t__p0));\
	})

#define TIFFCheckpointDirectory(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 382))(__t__p0));\
	})

#define TIFFGetSeekProc(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFSeekProc (*)(TIFF *))*(void**)(__base - 766))(__t__p0));\
	})

#define TIFFIsUpSampled(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 268))(__t__p0));\
	})

#define TIFFTileSize(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *))*(void**)(__base - 226))(__t__p0));\
	})

#define TIFFSetFileName(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(TIFF *, const char *))*(void**)(__base - 796))(__t__p0, __t__p1));\
	})

#define TIFFWriteBufferSetup(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		tdata_t  __t__p1 = __p1;\
		tsize_t  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, tdata_t , tsize_t ))*(void**)(__base - 322))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFCurrentDirectory(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tdir_t (*)(TIFF *))*(void**)(__base - 286))(__t__p0));\
	})

#define TIFFWriteEncodedTile(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttile_t  __t__p1 = __p1;\
		tdata_t  __t__p2 = __p2;\
		tsize_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, ttile_t , tdata_t , tsize_t ))*(void**)(__base - 556))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFAccessTagMethods(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFTagMethods *(*)(TIFF *))*(void**)(__base - 658))(__t__p0));\
	})

#define TIFFSetSubDirectory(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, uint32 ))*(void**)(__base - 358))(__t__p0, __t__p1));\
	})

#define TIFFCurrentTile(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((ttile_t (*)(TIFF *))*(void**)(__base - 310))(__t__p0));\
	})

#define TIFFCIELabToXYZ(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		TIFFCIELabToRGB * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		int32  __t__p2 = __p2;\
		int32  __t__p3 = __p3;\
		float * __t__p4 = __p4;\
		float * __t__p5 = __p5;\
		float * __t__p6 = __p6;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFFCIELabToRGB *, uint32 , int32 , int32 , float *, float *, float *))*(void**)(__base - 682))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define TIFFGetMode(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 256))(__t__p0));\
	})

#define TIFFReadTile(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		TIFF * __t__p0 = __p0;\
		tdata_t  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		uint32  __t__p3 = __p3;\
		uint32  __t__p4 = __p4;\
		tsample_t  __t__p5 = __p5;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, tdata_t , uint32 , uint32 , uint32 , tsample_t ))*(void**)(__base - 496))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define TIFFSwabDouble(__p0) \
	({ \
		double * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(double *))*(void**)(__base - 592))(__t__p0));\
	})

#define TIFFCheckTile(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		uint32  __t__p3 = __p3;\
		tsample_t  __t__p4 = __p4;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, uint32 , uint32 , uint32 , tsample_t ))*(void**)(__base - 484))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define TIFFGetUnmapFileProc(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFUnmapFileProc (*)(TIFF *))*(void**)(__base - 790))(__t__p0));\
	})

#define TIFFCurrentStrip(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tstrip_t (*)(TIFF *))*(void**)(__base - 304))(__t__p0));\
	})

#define TIFFComputeTile(__p0, __p1, __p2, __p3, __p4) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		uint32  __t__p3 = __p3;\
		tsample_t  __t__p4 = __p4;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((ttile_t (*)(TIFF *, uint32 , uint32 , uint32 , tsample_t ))*(void**)(__base - 478))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define _TIFFmemcpy(__p0, __p1, __p2) \
	({ \
		tdata_t  __t__p0 = __p0;\
		const tdata_t  __t__p1 = __p1;\
		tsize_t  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(tdata_t , const tdata_t , tsize_t ))*(void**)(__base - 142))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFFreeDirectory(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFF *))*(void**)(__base - 832))(__t__p0));\
	})

#if !defined(__STRICT_ANSI__)
#define TIFFSetField(__p0, ...) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		(((int (*)(TIFF *, ttag_t , ...))*(void**)(__base - 52))(__t__p0, __VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define TIFFWriteRawTile(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttile_t  __t__p1 = __p1;\
		tdata_t  __t__p2 = __p2;\
		tsize_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, ttile_t , tdata_t , tsize_t ))*(void**)(__base - 562))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFNumberOfDirectories(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tdir_t (*)(TIFF *))*(void**)(__base - 292))(__t__p0));\
	})

#define TIFFCurrentDirOffset(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((uint32 (*)(TIFF *))*(void**)(__base - 298))(__t__p0));\
	})

#define TIFFReadRGBATile(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		uint32 * __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, uint32 , uint32 , uint32 *))*(void**)(__base - 64))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFComputeStrip(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		tsample_t  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tstrip_t (*)(TIFF *, uint32 , tsample_t ))*(void**)(__base - 508))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFSwabShort(__p0) \
	({ \
		uint16 * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(uint16 *))*(void**)(__base - 580))(__t__p0));\
	})

#define TIFFGetWriteProc(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFReadWriteProc (*)(TIFF *))*(void**)(__base - 760))(__t__p0));\
	})

#if !defined(__STRICT_ANSI__)
#define TIFFGetFieldDefaulted(__p0, ...) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		(((int (*)(TIFF *, ttag_t , ...))*(void**)(__base - 172))(__t__p0, __VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define TIFFSetErrorHandlerExt(__p0) \
	({ \
		TIFFErrorHandlerExt  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFErrorHandlerExt (*)(TIFFErrorHandlerExt ))*(void**)(__base - 850))(__t__p0));\
	})

#define TIFFReadRawStrip(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		tstrip_t  __t__p1 = __p1;\
		tdata_t  __t__p2 = __p2;\
		tsize_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, tstrip_t , tdata_t , tsize_t ))*(void**)(__base - 526))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFFindFieldInfo(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttag_t  __t__p1 = __p1;\
		TIFFDataType  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const TIFFFieldInfo *(*)(TIFF *, ttag_t , TIFFDataType ))*(void**)(__base - 646))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFGetConfiguredCODECs() \
	({ \
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFCodec *(*)(void))*(void**)(__base - 712))());\
	})

#define TIFFSetupStrips(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 328))(__t__p0));\
	})

#define _TIFFrealloc(__p0, __p1) \
	({ \
		tdata_t  __t__p0 = __p0;\
		tsize_t  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tdata_t (*)(tdata_t , tsize_t ))*(void**)(__base - 124))(__t__p0, __t__p1));\
	})

#define TIFFOpenFH(__p0, __p1) \
	({ \
		BPTR  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFF *(*)(BPTR , const char *))*(void**)(__base - 34))(__t__p0, __t__p1));\
	})

#define TIFFWriteDirectory(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 376))(__t__p0));\
	})

#define TIFFReadEXIFDirectory(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		toff_t  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, toff_t ))*(void**)(__base - 826))(__t__p0, __t__p1));\
	})

#define TIFFGetCloseProc(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFCloseProc (*)(TIFF *))*(void**)(__base - 772))(__t__p0));\
	})

#define TIFFSwabLong(__p0) \
	({ \
		uint32 * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(uint32 *))*(void**)(__base - 586))(__t__p0));\
	})

#define TIFFClientOpen(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		thandle_t  __t__p2 = __p2;\
		TIFFReadWriteProc  __t__p3 = __p3;\
		TIFFReadWriteProc  __t__p4 = __p4;\
		TIFFSeekProc  __t__p5 = __p5;\
		TIFFCloseProc  __t__p6 = __p6;\
		TIFFSizeProc  __t__p7 = __p7;\
		TIFFMapFileProc  __t__p8 = __p8;\
		TIFFUnmapFileProc  __t__p9 = __p9;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFF *(*)(const char *, const char *, thandle_t , TIFFReadWriteProc , TIFFReadWriteProc , TIFFSeekProc , TIFFCloseProc , TIFFSizeProc , TIFFMapFileProc , TIFFUnmapFileProc ))*(void**)(__base - 436))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8, __t__p9));\
	})

#define TIFFScanlineSize(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *))*(void**)(__base - 190))(__t__p0));\
	})

#define TIFFSetTagExtender(__p0) \
	({ \
		TIFFExtendProc  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFExtendProc (*)(TIFFExtendProc ))*(void**)(__base - 472))(__t__p0));\
	})

#define TIFFRGBAImageOK(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		char * __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, char *))*(void**)(__base - 412))(__t__p0, __t__p1));\
	})

#define TIFFReadEncodedStrip(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		tstrip_t  __t__p1 = __p1;\
		tdata_t  __t__p2 = __p2;\
		tsize_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, tstrip_t , tdata_t , tsize_t ))*(void**)(__base - 520))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFIsMSB2LSB(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 274))(__t__p0));\
	})

#define TIFFFieldWithName(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const TIFFFieldInfo *(*)(TIFF *, const char *))*(void**)(__base - 808))(__t__p0, __t__p1));\
	})

#define TIFFStripSize(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *))*(void**)(__base - 202))(__t__p0));\
	})

#define TIFFSetErrorHandler(__p0) \
	({ \
		TIFFErrorHandler  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFErrorHandler (*)(TIFFErrorHandler ))*(void**)(__base - 460))(__t__p0));\
	})

#define TIFFYCbCrtoRGB(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		TIFFYCbCrToRGB * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		int32  __t__p2 = __p2;\
		int32  __t__p3 = __p3;\
		uint32 * __t__p4 = __p4;\
		uint32 * __t__p5 = __p5;\
		uint32 * __t__p6 = __p6;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFFYCbCrToRGB *, uint32 , int32 , int32 , uint32 *, uint32 *, uint32 *))*(void**)(__base - 700))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define TIFFRGBAImageGet(__p0, __p1, __p2, __p3) \
	({ \
		TIFFRGBAImage * __t__p0 = __p0;\
		uint32 * __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		uint32  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFFRGBAImage *, uint32 *, uint32 , uint32 ))*(void**)(__base - 424))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#if !defined(__STRICT_ANSI__)
#define TIFFError(__p0, ...) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		(((void (*)(const char *, const char *, ...))*(void**)(__base - 448))(__t__p0, __VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define TIFFReadRawTile(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttile_t  __t__p1 = __p1;\
		tdata_t  __t__p2 = __p2;\
		tsize_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, ttile_t , tdata_t , tsize_t ))*(void**)(__base - 538))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFVStripSize(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, uint32 ))*(void**)(__base - 214))(__t__p0, __t__p1));\
	})

#define TIFFWriteTile(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		TIFF * __t__p0 = __p0;\
		tdata_t  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		uint32  __t__p3 = __p3;\
		uint32  __t__p4 = __p4;\
		tsample_t  __t__p5 = __p5;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, tdata_t , uint32 , uint32 , uint32 , tsample_t ))*(void**)(__base - 502))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define TIFFSetFileno(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, int ))*(void**)(__base - 724))(__t__p0, __t__p1));\
	})

#define TIFFIsBigEndian(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 748))(__t__p0));\
	})

#define TIFFIsByteSwapped(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 262))(__t__p0));\
	})

#define TIFFRGBAImageBegin(__p0, __p1, __p2, __p3) \
	({ \
		TIFFRGBAImage * __t__p0 = __p0;\
		TIFF * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		char * __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFFRGBAImage *, TIFF *, int , char *))*(void**)(__base - 418))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFSwabArrayOfTriples(__p0, __p1) \
	({ \
		uint8 * __t__p0 = __p0;\
		unsigned long  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(uint8 *, unsigned long ))*(void**)(__base - 814))(__t__p0, __t__p1));\
	})

#define TIFFReadCustomDirectory(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		toff_t  __t__p1 = __p1;\
		const TIFFFieldInfo * __t__p2 = __p2;\
		size_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, toff_t , const TIFFFieldInfo *, size_t ))*(void**)(__base - 820))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFSwabArrayOfShort(__p0, __p1) \
	({ \
		uint16 * __t__p0 = __p0;\
		unsigned long  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(uint16 *, unsigned long ))*(void**)(__base - 598))(__t__p0, __t__p1));\
	})

#define TIFFCIELabToRGBInit(__p0, __p1, __p2) \
	({ \
		TIFFCIELabToRGB * __t__p0 = __p0;\
		TIFFDisplay * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFFCIELabToRGB *, TIFFDisplay *, float *))*(void**)(__base - 676))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFMergeFieldInfo(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		const TIFFFieldInfo * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFF *, const TIFFFieldInfo *, int ))*(void**)(__base - 640))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFWriteRawStrip(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		tstrip_t  __t__p1 = __p1;\
		tdata_t  __t__p2 = __p2;\
		tsize_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, tstrip_t , tdata_t , tsize_t ))*(void**)(__base - 550))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFPrintDirectoryFH(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		BPTR  __t__p1 = __p1;\
		long  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFF *, BPTR , long ))*(void**)(__base - 706))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFSetClientInfo(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFF *, void *, const char *))*(void**)(__base - 670))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFClientdata(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((thandle_t (*)(TIFF *))*(void**)(__base - 730))(__t__p0));\
	})

#if !defined(__STRICT_ANSI__)
#define TIFFWarningExt(__p0, __p1, ...) \
	({ \
		thandle_t  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		(((void (*)(thandle_t , const char *, const char *, ...))*(void**)(__base - 844))(__t__p0, __t__p1, __VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define TIFFSetDirectory(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		tdir_t  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, tdir_t ))*(void**)(__base - 352))(__t__p0, __t__p1));\
	})

#define TIFFReadDirectory(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 184))(__t__p0));\
	})

#define TIFFYCbCrToRGBInit(__p0, __p1, __p2) \
	({ \
		TIFFYCbCrToRGB * __t__p0 = __p0;\
		float * __t__p1 = __p1;\
		float * __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFFYCbCrToRGB *, float *, float *))*(void**)(__base - 694))(__t__p0, __t__p1, __t__p2));\
	})

#define _TIFFmalloc(__p0) \
	({ \
		tsize_t  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tdata_t (*)(tsize_t ))*(void**)(__base - 118))(__t__p0));\
	})

#define TIFFFlushData(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 160))(__t__p0));\
	})

#define TIFFXYZToRGB(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		TIFFCIELabToRGB * __t__p0 = __p0;\
		float  __t__p1 = __p1;\
		float  __t__p2 = __p2;\
		float  __t__p3 = __p3;\
		uint32 * __t__p4 = __p4;\
		uint32 * __t__p5 = __p5;\
		uint32 * __t__p6 = __p6;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFFCIELabToRGB *, float , float , float , uint32 *, uint32 *, uint32 *))*(void**)(__base - 688))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define TIFFVGetField(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttag_t  __t__p1 = __p1;\
		va_list  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, ttag_t , va_list ))*(void**)(__base - 166))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFClose(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFF *))*(void**)(__base - 82))(__t__p0));\
	})

#define TIFFReadScanline(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		tdata_t  __t__p1 = __p1;\
		uint32  __t__p2 = __p2;\
		tsample_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, tdata_t , uint32 , tsample_t ))*(void**)(__base - 400))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFWriteEncodedStrip(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		tstrip_t  __t__p1 = __p1;\
		tdata_t  __t__p2 = __p2;\
		tsize_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, tstrip_t , tdata_t , tsize_t ))*(void**)(__base - 544))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFOpen(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFF *(*)(const char *, const char *))*(void**)(__base - 28))(__t__p0, __t__p1));\
	})

#define TIFFRasterScanlineSize(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *))*(void**)(__base - 196))(__t__p0));\
	})

#if !defined(__STRICT_ANSI__)
#define TIFFErrorExt(__p0, __p1, ...) \
	({ \
		thandle_t  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		(((void (*)(thandle_t , const char *, const char *, ...))*(void**)(__base - 838))(__t__p0, __t__p1, __VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define TIFFUnRegisterCODEC(__p0) \
	({ \
		TIFFCodec * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFFCodec *))*(void**)(__base - 106))(__t__p0));\
	})

#define TIFFFileno(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 250))(__t__p0));\
	})

#define TIFFDefaultStripSize(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((uint32 (*)(TIFF *, uint32 ))*(void**)(__base - 238))(__t__p0, __t__p1));\
	})

#define TIFFSwabArrayOfLong(__p0, __p1) \
	({ \
		uint32 * __t__p0 = __p0;\
		unsigned long  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(uint32 *, unsigned long ))*(void**)(__base - 604))(__t__p0, __t__p1));\
	})

#if !defined(__STRICT_ANSI__)
#define TIFFWarning(__p0, ...) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		(((void (*)(const char *, const char *, ...))*(void**)(__base - 454))(__t__p0, __VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define TIFFFindFieldInfoByName(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		TIFFDataType  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const TIFFFieldInfo *(*)(TIFF *, const char *, TIFFDataType ))*(void**)(__base - 802))(__t__p0, __t__p1, __t__p2));\
	})

#define _TIFFmemcmp(__p0, __p1, __p2) \
	({ \
		const tdata_t  __t__p0 = __p0;\
		const tdata_t  __t__p1 = __p1;\
		tsize_t  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const tdata_t , const tdata_t , tsize_t ))*(void**)(__base - 148))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFLastDirectory(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 346))(__t__p0));\
	})

#define TIFFSetWriteOffset(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		toff_t  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFF *, toff_t ))*(void**)(__base - 574))(__t__p0, __t__p1));\
	})

#define TIFFIsCODECConfigured(__p0) \
	({ \
		uint16  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(uint16 ))*(void**)(__base - 112))(__t__p0));\
	})

#define TIFFReverseBits(__p0, __p1) \
	({ \
		unsigned char * __t__p0 = __p0;\
		unsigned long  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(unsigned char *, unsigned long ))*(void**)(__base - 616))(__t__p0, __t__p1));\
	})

#define TIFFNumberOfStrips(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tstrip_t (*)(TIFF *))*(void**)(__base - 514))(__t__p0));\
	})

#define TIFFFlush(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 154))(__t__p0));\
	})

#define TIFFFieldWithTag(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttag_t  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const TIFFFieldInfo *(*)(TIFF *, ttag_t ))*(void**)(__base - 652))(__t__p0, __t__p1));\
	})

#define TIFFRGBAImageEnd(__p0) \
	({ \
		TIFFRGBAImage * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFFRGBAImage *))*(void**)(__base - 430))(__t__p0));\
	})

#define TIFFDataWidth(__p0) \
	({ \
		TIFFDataType  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFFDataType ))*(void**)(__base - 568))(__t__p0));\
	})

#define TIFFIsTiled(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 46))(__t__p0));\
	})

#if !defined(__STRICT_ANSI__)
#define TIFFGetField(__p0, ...) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		(((int (*)(TIFF *, ttag_t , ...))*(void**)(__base - 40))(__t__p0, __VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define TIFFCurrentRow(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((uint32 (*)(TIFF *))*(void**)(__base - 280))(__t__p0));\
	})

#define TIFFFindCODEC(__p0) \
	({ \
		uint16  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const TIFFCodec *(*)(uint16 ))*(void**)(__base - 94))(__t__p0));\
	})

#define TIFFRegisterCODEC(__p0, __p1, __p2) \
	({ \
		uint16  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		TIFFInitMethod  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFCodec *(*)(uint16 , const char *, TIFFInitMethod ))*(void**)(__base - 100))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFDefaultTileSize(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32 * __t__p1 = __p1;\
		uint32 * __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TIFF *, uint32 *, uint32 *))*(void**)(__base - 244))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFGetTagListEntry(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((ttag_t (*)(TIFF *, int ))*(void**)(__base - 634))(__t__p0, __t__p1));\
	})

#define _TIFFfree(__p0) \
	({ \
		tdata_t  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(tdata_t ))*(void**)(__base - 130))(__t__p0));\
	})

#define TIFFSetWarningHandlerExt(__p0) \
	({ \
		TIFFErrorHandlerExt  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFErrorHandlerExt (*)(TIFFErrorHandlerExt ))*(void**)(__base - 856))(__t__p0));\
	})

#define TIFFReassignTagToIgnore(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(int , int ))*(void**)(__base - 394))(__t__p0, __t__p1));\
	})

#define TIFFGetMapFileProc(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFMapFileProc (*)(TIFF *))*(void**)(__base - 784))(__t__p0));\
	})

#define TIFFReadBufferSetup(__p0, __p1, __p2) \
	({ \
		TIFF * __t__p0 = __p0;\
		tdata_t  __t__p1 = __p1;\
		tsize_t  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *, tdata_t , tsize_t ))*(void**)(__base - 316))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFReadEncodedTile(__p0, __p1, __p2, __p3) \
	({ \
		TIFF * __t__p0 = __p0;\
		ttile_t  __t__p1 = __p1;\
		tdata_t  __t__p2 = __p2;\
		tsize_t  __t__p3 = __p3;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, ttile_t , tdata_t , tsize_t ))*(void**)(__base - 532))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define TIFFGetVersion() \
	({ \
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(void))*(void**)(__base - 88))());\
	})

#define TIFFSetWarningHandler(__p0) \
	({ \
		TIFFErrorHandler  __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TIFFErrorHandler (*)(TIFFErrorHandler ))*(void**)(__base - 466))(__t__p0));\
	})

#define TIFFVTileSize(__p0, __p1) \
	({ \
		TIFF * __t__p0 = __p0;\
		uint32  __t__p1 = __p1;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((tsize_t (*)(TIFF *, uint32 ))*(void**)(__base - 232))(__t__p0, __t__p1));\
	})

#define _TIFFmemset(__p0, __p1, __p2) \
	({ \
		tdata_t  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		tsize_t  __t__p2 = __p2;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(tdata_t , int , tsize_t ))*(void**)(__base - 136))(__t__p0, __t__p1, __t__p2));\
	})

#define TIFFGetTagListCount(__p0) \
	({ \
		TIFF * __t__p0 = __p0;\
		long __base = (long)(TIFF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TIFF *))*(void**)(__base - 628))(__t__p0));\
	})

#endif /* !_PPCINLINE_TIFF_H */
