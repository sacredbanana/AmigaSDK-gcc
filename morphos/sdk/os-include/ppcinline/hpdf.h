/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_HPDF_H
#define _PPCINLINE_HPDF_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef HPDF_BASE_NAME
#define HPDF_BASE_NAME HPDFBase
#endif /* !HPDF_BASE_NAME */

#define HPDF_LoadJpegImageFromFile(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Image (*)(HPDF_Doc , const char *))*(void**)(__base - 484))(__t__p0, __t__p1));\
	})

#define HPDF_LoadRawImageFromMem(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const HPDF_BYTE * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		HPDF_UINT  __t__p3 = __p3;\
		HPDF_ColorSpace  __t__p4 = __p4;\
		HPDF_UINT  __t__p5 = __p5;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Image (*)(HPDF_Doc , const HPDF_BYTE *, HPDF_UINT , HPDF_UINT , HPDF_ColorSpace , HPDF_UINT ))*(void**)(__base - 502))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define HPDF_Page_Clip(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1042))(__t__p0));\
	})

#define HPDF_SetCurrentEncoder(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , const char *))*(void**)(__base - 370))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetCurrentFontSize(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 742))(__t__p0));\
	})

#define HPDF_LineAnnot_SetCaption(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_BOOL  __t__p1 = __p1;\
		HPDF_LineAnnotCapPosition  __t__p2 = __p2;\
		HPDF_INT  __t__p3 = __p3;\
		HPDF_INT  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_BOOL , HPDF_LineAnnotCapPosition , HPDF_INT , HPDF_INT ))*(void**)(__base - 1516))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_FreeTextAnnot_SetDefaultStyle(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , const char *))*(void**)(__base - 1498))(__t__p0, __t__p1));\
	})

#define HPDF_Page_CreateSquigglyAnnot(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder ))*(void**)(__base - 1330))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Page_GetTextRise(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 820))(__t__p0));\
	})

#define HPDF_Image_SetColorMask(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		HPDF_UINT  __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		HPDF_UINT  __t__p3 = __p3;\
		HPDF_UINT  __t__p4 = __p4;\
		HPDF_UINT  __t__p5 = __p5;\
		HPDF_UINT  __t__p6 = __p6;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Image , HPDF_UINT , HPDF_UINT , HPDF_UINT , HPDF_UINT , HPDF_UINT , HPDF_UINT ))*(void**)(__base - 544))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define HPDF_Page_GRestore(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 934))(__t__p0));\
	})

#define HPDF_Page_MoveToNextLine(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1126))(__t__p0));\
	})

#define HPDF_3DView_SetCamera(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		HPDF_Dict  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		HPDF_REAL  __t__p5 = __p5;\
		HPDF_REAL  __t__p6 = __p6;\
		HPDF_REAL  __t__p7 = __p7;\
		HPDF_REAL  __t__p8 = __p8;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Dict , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1282))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})

#define HPDF_InsertPage(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_Page  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Page (*)(HPDF_Doc , HPDF_Page ))*(void**)(__base - 196))(__t__p0, __t__p1));\
	})

#define HPDF_AddPage(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Page (*)(HPDF_Doc ))*(void**)(__base - 190))(__t__p0));\
	})

#define HPDF_Page_SetTextRise(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 1102))(__t__p0, __t__p1));\
	})

#define HPDF_3DView_SetLighting(__p0, __p1) \
	({ \
		HPDF_Dict  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Dict , const char *))*(void**)(__base - 1258))(__t__p0, __t__p1));\
	})

#define HPDF_ResetError(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(HPDF_Doc ))*(void**)(__base - 124))(__t__p0));\
	})

#define HPDF_SetPageLayout(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_PageLayout  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_PageLayout ))*(void**)(__base - 148))(__t__p0, __t__p1));\
	})

#define HPDF_GetEncoder(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Encoder (*)(HPDF_Doc , const char *))*(void**)(__base - 358))(__t__p0, __t__p1));\
	})

#define HPDF_ExtGState_SetAlphaStroke(__p0, __p1) \
	({ \
		HPDF_ExtGState  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_ExtGState , HPDF_REAL ))*(void**)(__base - 664))(__t__p0, __t__p1));\
	})

#define HPDF_CreateOutline(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_Outline  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Outline (*)(HPDF_Doc , HPDF_Outline , const char *, HPDF_Encoder ))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Page_CreateSquareAnnot(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder ))*(void**)(__base - 1354))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_FreeDoc(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(HPDF_Doc ))*(void**)(__base - 64))(__t__p0));\
	})

#define HPDF_Page_SetHeight(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 208))(__t__p0, __t__p1));\
	})

#define HPDF_Page_SetExtGState(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_ExtGState  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_ExtGState ))*(void**)(__base - 922))(__t__p0, __t__p1));\
	})

#define HPDF_MarkupAnnot_SetTitle(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , const char *))*(void**)(__base - 1390))(__t__p0, __t__p1));\
	})

#define HPDF_MarkupAnnot_SetInteriorCMYKColor(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_CMYKColor  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_CMYKColor ))*(void**)(__base - 1444))(__t__p0, __t__p1));\
	})

#define HPDF_Page_Stroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 988))(__t__p0));\
	})

#define HPDF_UseKREncodings(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 406))(__t__p0));\
	})

#define HPDF_Page_MoveTextPos(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1108))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_LineAnnot_SetPosition(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_Point  __t__p1 = __p1;\
		HPDF_LineAnnotEndingStyle  __t__p2 = __p2;\
		HPDF_Point  __t__p3 = __p3;\
		HPDF_LineAnnotEndingStyle  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_Point , HPDF_LineAnnotEndingStyle , HPDF_Point , HPDF_LineAnnotEndingStyle ))*(void**)(__base - 1504))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_GetCurrentFont(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Font (*)(HPDF_Page ))*(void**)(__base - 736))(__t__p0));\
	})

#define HPDF_Page_CreateStrikeOutAnnot(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder ))*(void**)(__base - 1336))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Create3DView(__p0, __p1) \
	({ \
		HPDF_MMgr  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Dict (*)(HPDF_MMgr , const char *))*(void**)(__base - 1234))(__t__p0, __t__p1));\
	})

#define HPDF_LoadType1FontFromFile(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(HPDF_Doc , const char *, const char *))*(void**)(__base - 232))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_CreatePopupAnnot(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		HPDF_Annotation  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , HPDF_Annotation ))*(void**)(__base - 1342))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_SaveToFile(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , const char *))*(void**)(__base - 106))(__t__p0, __t__p1));\
	})

#define HPDF_FreeTextAnnot_Set2PointCalloutLine(__p0, __p1, __p2) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_Point  __t__p1 = __p1;\
		HPDF_Point  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_Point , HPDF_Point ))*(void**)(__base - 1492))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Destination_SetXYZ(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Destination  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Destination , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 310))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Page_GetCurrentTextPos(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Point (*)(HPDF_Page ))*(void**)(__base - 724))(__t__p0));\
	})

#define HPDF_Font_TextWidth(__p0, __p1, __p2) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		const HPDF_BYTE * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_TextWidth (*)(HPDF_Font , const HPDF_BYTE *, HPDF_UINT ))*(void**)(__base - 646))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_ExtGState_SetAlphaFill(__p0, __p1) \
	({ \
		HPDF_ExtGState  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_ExtGState , HPDF_REAL ))*(void**)(__base - 670))(__t__p0, __t__p1));\
	})

#define HPDF_Page_CreateLinkAnnot(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		HPDF_Destination  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , HPDF_Destination ))*(void**)(__base - 436))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_FreeTextAnnot_SetLineEndingStyle(__p0, __p1, __p2) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_LineAnnotEndingStyle  __t__p1 = __p1;\
		HPDF_LineAnnotEndingStyle  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_LineAnnotEndingStyle , HPDF_LineAnnotEndingStyle ))*(void**)(__base - 1480))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Font_GetFontName(__p0) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(HPDF_Font ))*(void**)(__base - 598))(__t__p0));\
	})

#define HPDF_Page_GetCurrentPos2(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Point * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_Point *))*(void**)(__base - 718))(__t__p0, __t__p1));\
	})

#define HPDF_Page_SetFlat(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 916))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetLineWidth(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 754))(__t__p0));\
	})

#define HPDF_Page_SetCMYKStroke(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1180))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_GetPageByIndex(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_UINT  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Page (*)(HPDF_Doc , HPDF_UINT ))*(void**)(__base - 136))(__t__p0, __t__p1));\
	})

#define HPDF_LinkAnnot_SetHighlightMode(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_AnnotHighlightMode  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_AnnotHighlightMode ))*(void**)(__base - 448))(__t__p0, __t__p1));\
	})

#define HPDF_HasDoc(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_BOOL (*)(HPDF_Doc ))*(void**)(__base - 70))(__t__p0));\
	})

#define HPDF_Page_GetRGBStroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_RGBColor (*)(HPDF_Page ))*(void**)(__base - 832))(__t__p0));\
	})

#define HPDF_LinkAnnot_SetBorderStyle(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_UINT16  __t__p2 = __p2;\
		HPDF_UINT16  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_REAL , HPDF_UINT16 , HPDF_UINT16 ))*(void**)(__base - 454))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_FreeTextAnnot_Set3PointCalloutLine(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_Point  __t__p1 = __p1;\
		HPDF_Point  __t__p2 = __p2;\
		HPDF_Point  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_Point , HPDF_Point , HPDF_Point ))*(void**)(__base - 1486))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_MarkupAnnot_SetCloudEffect(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_INT  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_INT ))*(void**)(__base - 1432))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetGrayFill(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 850))(__t__p0));\
	})

#define HPDF_Page_ShowTextNextLine(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , const char *))*(void**)(__base - 1138))(__t__p0, __t__p1));\
	})

#define HPDF_LoadTTFontFromFile(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		HPDF_BOOL  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(HPDF_Doc , const char *, HPDF_BOOL ))*(void**)(__base - 244))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_GetCurrentEncoder(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Encoder (*)(HPDF_Doc ))*(void**)(__base - 364))(__t__p0));\
	})

#define HPDF_Page_Rectangle(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 982))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_SetSize(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_PageSizes  __t__p1 = __p1;\
		HPDF_PageDirection  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_PageSizes , HPDF_PageDirection ))*(void**)(__base - 214))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_SaveToStream(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 82))(__t__p0));\
	})

#define HPDF_Page_SetGrayFill(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 1150))(__t__p0, __t__p1));\
	})

#define HPDF_MarkupAnnot_SetRectDiff(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_Rect ))*(void**)(__base - 1426))(__t__p0, __t__p1));\
	})

#define HPDF_Page_Arc(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		HPDF_REAL  __t__p5 = __p5;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1210))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define HPDF_UseJPFonts(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 262))(__t__p0));\
	})

#define HPDF_Page_Circle(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1198))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Page_SetHorizontalScalling(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 1078))(__t__p0, __t__p1));\
	})

#define HPDF_GetPageMode(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_PageMode (*)(HPDF_Doc ))*(void**)(__base - 154))(__t__p0));\
	})

#define HPDF_New(__p0, __p1) \
	({ \
		HPDF_Error_Handler  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Doc (*)(HPDF_Error_Handler , void *))*(void**)(__base - 40))(__t__p0, __t__p1));\
	})

#define HPDF_AttachFile(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_EmbeddedFile (*)(HPDF_Doc , const char *))*(void**)(__base - 1552))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetHorizontalScalling(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 802))(__t__p0));\
	})

#define HPDF_Page_GetLineJoin(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_LineJoin (*)(HPDF_Page ))*(void**)(__base - 766))(__t__p0));\
	})

#define HPDF_SetPageMode(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_PageMode  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_PageMode ))*(void**)(__base - 160))(__t__p0, __t__p1));\
	})

#define HPDF_GetError(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 112))(__t__p0));\
	})

#define HPDF_ReadFromStream(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_BYTE * __t__p1 = __p1;\
		HPDF_UINT32 * __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_BYTE *, HPDF_UINT32 *))*(void**)(__base - 94))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_3DView_SetOrthogonalProjection(__p0, __p1) \
	({ \
		HPDF_Dict  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Dict , HPDF_REAL ))*(void**)(__base - 1276))(__t__p0, __t__p1));\
	})

#define HPDF_SetInfoDateAttr(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_InfoType  __t__p1 = __p1;\
		HPDF_Date  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_InfoType , HPDF_Date ))*(void**)(__base - 568))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_SetLineJoin(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_LineJoin  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_LineJoin ))*(void**)(__base - 898))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetGrayStroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 856))(__t__p0));\
	})

#define HPDF_ExtGState_SetBlendMode(__p0, __p1) \
	({ \
		HPDF_ExtGState  __t__p0 = __p0;\
		HPDF_BlendMode  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_ExtGState , HPDF_BlendMode ))*(void**)(__base - 676))(__t__p0, __t__p1));\
	})

#define HPDF_Page_Eoclip(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1048))(__t__p0));\
	})

#define HPDF_MarkupAnnot_SetPopup(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_Annotation  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_Annotation ))*(void**)(__base - 1420))(__t__p0, __t__p1));\
	})

#define HPDF_U3D_SetDefault3DView(__p0, __p1) \
	({ \
		HPDF_U3D  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_U3D , const char *))*(void**)(__base - 1246))(__t__p0, __t__p1));\
	})

#define HPDF_Page_SetMiterLimit(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 904))(__t__p0, __t__p1));\
	})

#define HPDF_SetCompressionMode(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_UINT  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_UINT ))*(void**)(__base - 592))(__t__p0, __t__p1));\
	})

#define HPDF_Page_SetFontAndSize(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Font  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_Font , HPDF_REAL ))*(void**)(__base - 1090))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_ShowText(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , const char *))*(void**)(__base - 1132))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetGMode(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT16 (*)(HPDF_Page ))*(void**)(__base - 706))(__t__p0));\
	})

#define HPDF_MarkupAnnot_SetCreationDate(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_Date  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_Date ))*(void**)(__base - 1402))(__t__p0, __t__p1));\
	})

#define HPDF_MarkupAnnot_SetTransparency(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_REAL ))*(void**)(__base - 1408))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetFlat(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 784))(__t__p0));\
	})

#define HPDF_Page_SetWidth(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 202))(__t__p0, __t__p1));\
	})

#define HPDF_Font_GetAscent(__p0) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_INT (*)(HPDF_Font ))*(void**)(__base - 622))(__t__p0));\
	})

#define HPDF_Page_GetCMYKFill(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_CMYKColor (*)(HPDF_Page ))*(void**)(__base - 838))(__t__p0));\
	})

#define HPDF_3DView_SetBackgroundColor(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Dict  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Dict , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1264))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Image_GetSize(__p0) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Point (*)(HPDF_Image ))*(void**)(__base - 508))(__t__p0));\
	})

#define HPDF_MarkupAnnot_SetInteriorTransparent(__p0) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation ))*(void**)(__base - 1456))(__t__p0));\
	})

#define HPDF_Page_SetCMYKFill(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1174))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_SetWordSpace(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 1072))(__t__p0, __t__p1));\
	})

#define HPDF_SetViewerPreference(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_UINT  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_UINT ))*(void**)(__base - 172))(__t__p0, __t__p1));\
	})

#define HPDF_Annot_SetNoColor(__p0) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation ))*(void**)(__base - 1384))(__t__p0));\
	})

#define HPDF_Page_TextWidth(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page , const char *))*(void**)(__base - 682))(__t__p0, __t__p1));\
	})

#define HPDF_PopupAnnot_SetOpened(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_BOOL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_BOOL ))*(void**)(__base - 1474))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetCurrentPos(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Point (*)(HPDF_Page ))*(void**)(__base - 712))(__t__p0));\
	})

#define HPDF_Page_SetTextRenderingMode(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_TextRenderingMode  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_TextRenderingMode ))*(void**)(__base - 1096))(__t__p0, __t__p1));\
	})

#define HPDF_Image_GetColorSpace(__p0) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(HPDF_Image ))*(void**)(__base - 538))(__t__p0));\
	})

#define HPDF_Page_Concat(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		HPDF_REAL  __t__p5 = __p5;\
		HPDF_REAL  __t__p6 = __p6;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 940))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define HPDF_Destination_SetFit(__p0) \
	({ \
		HPDF_Destination  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Destination ))*(void**)(__base - 316))(__t__p0));\
	})

#define HPDF_Page_SetRotate(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_UINT16  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_UINT16 ))*(void**)(__base - 220))(__t__p0, __t__p1));\
	})

#define HPDF_LoadPngImageFromMem(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const HPDF_BYTE * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Image (*)(HPDF_Doc , const HPDF_BYTE *, HPDF_UINT ))*(void**)(__base - 1534))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_GetFillingColorSpace(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_ColorSpace (*)(HPDF_Page ))*(void**)(__base - 868))(__t__p0));\
	})

#define HPDF_ICC_LoadIccFromMem(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_MMgr  __t__p1 = __p1;\
		HPDF_Stream  __t__p2 = __p2;\
		HPDF_Xref  __t__p3 = __p3;\
		int  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_OutputIntent (*)(HPDF_Doc , HPDF_MMgr , HPDF_Stream , HPDF_Xref , int ))*(void**)(__base - 1558))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_ClosePathStroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 994))(__t__p0));\
	})

#define HPDF_Font_GetEncodingName(__p0) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(HPDF_Font ))*(void**)(__base - 604))(__t__p0));\
	})

#define HPDF_Page_SetCharSpace(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 1066))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetTextLeading(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 808))(__t__p0));\
	})

#define HPDF_SetPermission(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_UINT  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_UINT ))*(void**)(__base - 580))(__t__p0, __t__p1));\
	})

#define HPDF_GetPageLayout(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_PageLayout (*)(HPDF_Doc ))*(void**)(__base - 142))(__t__p0));\
	})

#define HPDF_MarkupAnnot_SetInteriorGrayColor(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_REAL ))*(void**)(__base - 1450))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GSave(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 928))(__t__p0));\
	})

#define HPDF_MarkupAnnot_SetSubject(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , const char *))*(void**)(__base - 1396))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetTextRenderingMode(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_TextRenderingMode (*)(HPDF_Page ))*(void**)(__base - 814))(__t__p0));\
	})

#define HPDF_Image_GetBitsPerComponent(__p0) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Image ))*(void**)(__base - 532))(__t__p0));\
	})

#define HPDF_Page_CreateHighlightAnnot(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder ))*(void**)(__base - 1318))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Font_GetBBox(__p0) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Box (*)(HPDF_Font ))*(void**)(__base - 616))(__t__p0));\
	})

#define HPDF_Page_MoveTextPos2(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1114))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Free(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(HPDF_Doc ))*(void**)(__base - 52))(__t__p0));\
	})

#define HPDF_UseCNTFonts(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 280))(__t__p0));\
	})

#define HPDF_Page_SetZoom(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_EXPORT (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 1294))(__t__p0, __t__p1));\
	})

#define HPDF_Encoder_GetWritingMode(__p0) \
	({ \
		HPDF_Encoder  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_WritingMode (*)(HPDF_Encoder ))*(void**)(__base - 394))(__t__p0));\
	})

#define HPDF_Page_GetStrokingColorSpace(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_ColorSpace (*)(HPDF_Page ))*(void**)(__base - 862))(__t__p0));\
	})

#define HPDF_Page_CreateURILinkAnnot(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *))*(void**)(__base - 442))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_CreateUnderlineAnnot(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder ))*(void**)(__base - 1324))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_LoadTTFontFromFile2(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		HPDF_BOOL  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(HPDF_Doc , const char *, HPDF_UINT , HPDF_BOOL ))*(void**)(__base - 250))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_UseCNTEncodings(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 418))(__t__p0));\
	})

#define HPDF_Page_SetRGBFill(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1162))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_TextAnnot_SetIcon(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_AnnotIcon  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_AnnotIcon ))*(void**)(__base - 460))(__t__p0, __t__p1));\
	})

#define HPDF_MarkupAnnot_SetInteriorRGBColor(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_RGBColor  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_RGBColor ))*(void**)(__base - 1438))(__t__p0, __t__p1));\
	})

#define HPDF_Page_SetTextMatrix(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		HPDF_REAL  __t__p5 = __p5;\
		HPDF_REAL  __t__p6 = __p6;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1120))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define HPDF_Font_MeasureText(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		const HPDF_BYTE * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		HPDF_REAL  __t__p5 = __p5;\
		HPDF_REAL  __t__p6 = __p6;\
		HPDF_BOOL  __t__p7 = __p7;\
		HPDF_REAL * __t__p8 = __p8;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Font , const HPDF_BYTE *, HPDF_UINT , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_BOOL , HPDF_REAL *))*(void**)(__base - 652))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7, __t__p8));\
	})

#define HPDF_Page_MoveTo(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 946))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_Fill(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1000))(__t__p0));\
	})

#define HPDF_3DView_AddNode(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Dict  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_BOOL  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Dict , const char *, HPDF_REAL , HPDF_BOOL ))*(void**)(__base - 1252))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_LoadU3DFromFile(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_U3D (*)(HPDF_Doc , const char *))*(void**)(__base - 1570))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetRGBFill(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_RGBColor (*)(HPDF_Page ))*(void**)(__base - 826))(__t__p0));\
	})

#define HPDF_LoadPngImageFromFile2(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Image (*)(HPDF_Doc , const char *))*(void**)(__base - 478))(__t__p0, __t__p1));\
	})

#define HPDF_TextAnnot_SetOpened(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_BOOL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_BOOL ))*(void**)(__base - 466))(__t__p0, __t__p1));\
	})

#define HPDF_ResetStream(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 100))(__t__p0));\
	})

#define HPDF_Image_AddSMask(__p0, __p1) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		HPDF_Image  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Image , HPDF_Image ))*(void**)(__base - 1546))(__t__p0, __t__p1));\
	})

#define HPDF_SetEncryptionMode(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_EncryptMode  __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_EncryptMode , HPDF_UINT ))*(void**)(__base - 586))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_TextOut(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , const char *))*(void**)(__base - 1216))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Font_GetXHeight(__p0) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Font ))*(void**)(__base - 634))(__t__p0));\
	})

#define HPDF_Page_MeasureText(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_BOOL  __t__p3 = __p3;\
		HPDF_REAL * __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Page , const char *, HPDF_REAL , HPDF_BOOL , HPDF_REAL *))*(void**)(__base - 688))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_GetCMYKStroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_CMYKColor (*)(HPDF_Page ))*(void**)(__base - 844))(__t__p0));\
	})

#define HPDF_Page_Create3DView(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_U3D  __t__p1 = __p1;\
		HPDF_Annotation  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Dict (*)(HPDF_Page , HPDF_U3D , HPDF_Annotation , const char *))*(void**)(__base - 1528))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Image_GetWidth(__p0) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Image ))*(void**)(__base - 520))(__t__p0));\
	})

#define HPDF_UseCNSFonts(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 274))(__t__p0));\
	})

#define HPDF_Annot_SetCMYKColor(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_CMYKColor  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_CMYKColor ))*(void**)(__base - 1372))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetTransMatrix(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_TransMatrix (*)(HPDF_Page ))*(void**)(__base - 748))(__t__p0));\
	})

#define HPDF_LoadRawImageFromFile(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		HPDF_UINT  __t__p3 = __p3;\
		HPDF_ColorSpace  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Image (*)(HPDF_Doc , const char *, HPDF_UINT , HPDF_UINT , HPDF_ColorSpace ))*(void**)(__base - 496))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_LineAnnot_SetLeader(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_INT  __t__p1 = __p1;\
		HPDF_INT  __t__p2 = __p2;\
		HPDF_INT  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_INT , HPDF_INT , HPDF_INT ))*(void**)(__base - 1510))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Page_ExecuteXObject(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_XObject  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_XObject ))*(void**)(__base - 1186))(__t__p0, __t__p1));\
	})

#define HPDF_Page_CreateStampAnnot(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		HPDF_StampAnnotName  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		HPDF_Encoder  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , HPDF_StampAnnotName , const char *, HPDF_Encoder ))*(void**)(__base - 1348))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_SetTextLeading(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 1084))(__t__p0, __t__p1));\
	})

#define HPDF_Page_SetLineCap(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_LineCap  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_LineCap ))*(void**)(__base - 892))(__t__p0, __t__p1));\
	})

#define HPDF_SetPagesConfiguration(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_UINT  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_UINT ))*(void**)(__base - 130))(__t__p0, __t__p1));\
	})

#define HPDF_Page_CreateCircleAnnot(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder ))*(void**)(__base - 1360))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_GetTTFontDefFromFile(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		HPDF_BOOL  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_FontDef (*)(HPDF_Doc , const char *, HPDF_BOOL ))*(void**)(__base - 238))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_MarkupAnnot_SetIntent(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_AnnotIntent  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_AnnotIntent ))*(void**)(__base - 1414))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetLineCap(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_LineCap (*)(HPDF_Page ))*(void**)(__base - 760))(__t__p0));\
	})

#define HPDF_Page_ClosePathEofillStroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1030))(__t__p0));\
	})

#define HPDF_Page_GetHeight(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 700))(__t__p0));\
	})

#define HPDF_Image_GetHeight(__p0) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Image ))*(void**)(__base - 526))(__t__p0));\
	})

#define HPDF_Page_CreateFreeTextAnnot(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder ))*(void**)(__base - 1300))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_LoadJpegImageFromMem(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const HPDF_BYTE * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Image (*)(HPDF_Doc , const HPDF_BYTE *, HPDF_UINT ))*(void**)(__base - 1540))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Annot_Set3DView(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_MMgr  __t__p0 = __p0;\
		HPDF_Annotation  __t__p1 = __p1;\
		HPDF_Annotation  __t__p2 = __p2;\
		HPDF_Dict  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_MMgr , HPDF_Annotation , HPDF_Annotation , HPDF_Dict ))*(void**)(__base - 1468))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Font_GetCapHeight(__p0) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Font ))*(void**)(__base - 640))(__t__p0));\
	})

#define HPDF_Page_EndPath(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1036))(__t__p0));\
	})

#define HPDF_UseKRFonts(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 268))(__t__p0));\
	})

#define HPDF_Outline_SetOpened(__p0, __p1) \
	({ \
		HPDF_Outline  __t__p0 = __p0;\
		HPDF_BOOL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Outline , HPDF_BOOL ))*(void**)(__base - 292))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetMiterLimit(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 772))(__t__p0));\
	})

#define HPDF_Page_ClosePath(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 976))(__t__p0));\
	})

#define HPDF_Font_GetUnicodeWidth(__p0, __p1) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		HPDF_UNICODE  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_INT (*)(HPDF_Font , HPDF_UNICODE ))*(void**)(__base - 610))(__t__p0, __t__p1));\
	})

#define HPDF_Page_CurveTo2(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 964))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_CurveTo3(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 970))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_NewDoc(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 58))(__t__p0));\
	})

#define HPDF_Page_SetDash(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		const HPDF_UINT16 * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		HPDF_UINT  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , const HPDF_UINT16 *, HPDF_UINT , HPDF_UINT ))*(void**)(__base - 910))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Destination_SetFitBH(__p0, __p1) \
	({ \
		HPDF_Destination  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Destination , HPDF_REAL ))*(void**)(__base - 346))(__t__p0, __t__p1));\
	})

#define HPDF_GetErrorDetail(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 118))(__t__p0));\
	})

#define HPDF_Page_SetLineWidth(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 886))(__t__p0, __t__p1));\
	})

#define HPDF_Destination_SetFitB(__p0) \
	({ \
		HPDF_Destination  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Destination ))*(void**)(__base - 340))(__t__p0));\
	})

#define HPDF_GetStreamSize(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT32 (*)(HPDF_Doc ))*(void**)(__base - 88))(__t__p0));\
	})

#define HPDF_Page_SetRGBStroke(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1168))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Image_SetMaskImage(__p0, __p1) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		HPDF_Image  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Image , HPDF_Image ))*(void**)(__base - 550))(__t__p0, __t__p1));\
	})

#define HPDF_SetInfoAttr(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_InfoType  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_InfoType , const char *))*(void**)(__base - 556))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_CreateLineAnnot(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		HPDF_Encoder  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , const char *, HPDF_Encoder ))*(void**)(__base - 1306))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Outline_SetDestination(__p0, __p1) \
	({ \
		HPDF_Outline  __t__p0 = __p0;\
		HPDF_Destination  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Outline , HPDF_Destination ))*(void**)(__base - 298))(__t__p0, __t__p1));\
	})

#define HPDF_Destination_SetFitH(__p0, __p1) \
	({ \
		HPDF_Destination  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Destination , HPDF_REAL ))*(void**)(__base - 322))(__t__p0, __t__p1));\
	})

#define HPDF_TextMarkupAnnot_SetQuadPoints(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_Point  __t__p1 = __p1;\
		HPDF_Point  __t__p2 = __p2;\
		HPDF_Point  __t__p3 = __p3;\
		HPDF_Point  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_Point , HPDF_Point , HPDF_Point , HPDF_Point ))*(void**)(__base - 1462))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Font_GetDescent(__p0) \
	({ \
		HPDF_Font  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_INT (*)(HPDF_Font ))*(void**)(__base - 628))(__t__p0));\
	})

#define HPDF_Destination_SetFitBV(__p0, __p1) \
	({ \
		HPDF_Destination  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Destination , HPDF_REAL ))*(void**)(__base - 352))(__t__p0, __t__p1));\
	})

#define HPDF_Page_SetSlideShow(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_TransitionStyle  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_TransitionStyle , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1228))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Image_GetSize2(__p0, __p1) \
	({ \
		HPDF_Image  __t__p0 = __p0;\
		HPDF_Point * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Image , HPDF_Point *))*(void**)(__base - 514))(__t__p0, __t__p1));\
	})

#define HPDF_Page_DrawImage(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Image  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		HPDF_REAL  __t__p5 = __p5;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_Image , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1192))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define HPDF_Destination_SetFitR(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Destination  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Destination , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 334))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_CreateExtGState(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_ExtGState (*)(HPDF_Doc ))*(void**)(__base - 658))(__t__p0));\
	})

#define HPDF_Page_GetCurrentTextPos2(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Point * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_Point *))*(void**)(__base - 730))(__t__p0, __t__p1));\
	})

#define HPDF_Page_GetWordSpace(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 796))(__t__p0));\
	})

#define HPDF_U3D_Add3DView(__p0, __p1) \
	({ \
		HPDF_U3D  __t__p0 = __p0;\
		HPDF_Dict  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_U3D , HPDF_Dict ))*(void**)(__base - 1240))(__t__p0, __t__p1));\
	})

#define HPDF_Page_Eofill(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1006))(__t__p0));\
	})

#define HPDF_Destination_SetFitV(__p0, __p1) \
	({ \
		HPDF_Destination  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Destination , HPDF_REAL ))*(void**)(__base - 328))(__t__p0, __t__p1));\
	})

#define HPDF_UseCNSEncodings(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 412))(__t__p0));\
	})

#define HPDF_Page_CreateDestination(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Destination (*)(HPDF_Page ))*(void**)(__base - 304))(__t__p0));\
	})

#define HPDF_Page_Ellipse(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 1204))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_FillStroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1012))(__t__p0));\
	})

#define HPDF_Encoder_GetByteType(__p0, __p1, __p2) \
	({ \
		HPDF_Encoder  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		HPDF_UINT  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_ByteType (*)(HPDF_Encoder , const char *, HPDF_UINT ))*(void**)(__base - 382))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_UseJPEncodings(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc ))*(void**)(__base - 400))(__t__p0));\
	})

#define HPDF_SetPassword(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , const char *, const char *))*(void**)(__base - 574))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_TextRect(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		const char * __t__p5 = __p5;\
		HPDF_TextAlignment  __t__p6 = __p6;\
		HPDF_UINT * __t__p7 = __p7;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , const char *, HPDF_TextAlignment , HPDF_UINT *))*(void**)(__base - 1222))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6, __t__p7));\
	})

#define HPDF_Page_EofillStroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1018))(__t__p0));\
	})

#define HPDF_Page_BeginText(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1054))(__t__p0));\
	})

#define HPDF_AddPageLabel(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_UINT  __t__p1 = __p1;\
		HPDF_PageNumStyle  __t__p2 = __p2;\
		HPDF_UINT  __t__p3 = __p3;\
		const char * __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_UINT , HPDF_PageNumStyle , HPDF_UINT , const char *))*(void**)(__base - 256))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_GetGStateDepth(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Page ))*(void**)(__base - 880))(__t__p0));\
	})

#define HPDF_Page_CurveTo(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_REAL  __t__p3 = __p3;\
		HPDF_REAL  __t__p4 = __p4;\
		HPDF_REAL  __t__p5 = __p5;\
		HPDF_REAL  __t__p6 = __p6;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 958))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define HPDF_Encoder_GetType(__p0) \
	({ \
		HPDF_Encoder  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_EncoderType (*)(HPDF_Encoder ))*(void**)(__base - 376))(__t__p0));\
	})

#define HPDF_Page_GetCharSpace(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 790))(__t__p0));\
	})

#define HPDF_Page_EndText(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1060))(__t__p0));\
	})

#define HPDF_3DView_SetPerspectiveProjection(__p0, __p1) \
	({ \
		HPDF_Dict  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Dict , HPDF_REAL ))*(void**)(__base - 1270))(__t__p0, __t__p1));\
	})

#define HPDF_NewEx(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Error_Handler  __t__p0 = __p0;\
		HPDF_Alloc_Func  __t__p1 = __p1;\
		HPDF_Free_Func  __t__p2 = __p2;\
		HPDF_UINT  __t__p3 = __p3;\
		void * __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Doc (*)(HPDF_Error_Handler , HPDF_Alloc_Func , HPDF_Free_Func , HPDF_UINT , void *))*(void**)(__base - 34))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Encoder_GetUnicode(__p0, __p1) \
	({ \
		HPDF_Encoder  __t__p0 = __p0;\
		HPDF_UINT16  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UNICODE (*)(HPDF_Encoder , HPDF_UINT16 ))*(void**)(__base - 388))(__t__p0, __t__p1));\
	})

#define HPDF_Page_Create3DAnnot(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		HPDF_U3D  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , HPDF_U3D ))*(void**)(__base - 424))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_GetDash(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_DashMode (*)(HPDF_Page ))*(void**)(__base - 778))(__t__p0));\
	})

#define HPDF_Page_LineTo(__p0, __p1, __p2) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL ))*(void**)(__base - 952))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_LoadIccProfileFromFile(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_OutputIntent (*)(HPDF_Doc , const char *, int ))*(void**)(__base - 1564))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Page_SetGrayStroke(__p0, __p1) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL ))*(void**)(__base - 1156))(__t__p0, __t__p1));\
	})

#define HPDF_Page_CreateTextMarkupAnnot(__p0, __p1, __p2, __p3, __p4) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		HPDF_AnnotType  __t__p4 = __p4;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder , HPDF_AnnotType ))*(void**)(__base - 1312))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define HPDF_Page_GetTextMatrix(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_TransMatrix (*)(HPDF_Page ))*(void**)(__base - 874))(__t__p0));\
	})

#define HPDF_SetOpenAction(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_Destination  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_Destination ))*(void**)(__base - 178))(__t__p0, __t__p1));\
	})

#define HPDF_Page_CreateTextAnnot(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_Rect  __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		HPDF_Encoder  __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Annotation (*)(HPDF_Page , HPDF_Rect , const char *, HPDF_Encoder ))*(void**)(__base - 430))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_GetCurrentPage(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Page (*)(HPDF_Doc ))*(void**)(__base - 184))(__t__p0));\
	})

#define HPDF_Annot_SetGrayColor(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_REAL ))*(void**)(__base - 1378))(__t__p0, __t__p1));\
	})

#define HPDF_GetFont(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const char * __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Font (*)(HPDF_Doc , const char *, const char *))*(void**)(__base - 226))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_SetErrorHandler(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_Error_Handler  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_Error_Handler ))*(void**)(__base - 46))(__t__p0, __t__p1));\
	})

#define HPDF_FreeDocAll(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(HPDF_Doc ))*(void**)(__base - 76))(__t__p0));\
	})

#define HPDF_Page_ShowTextNextLineEx(__p0, __p1, __p2, __p3) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		HPDF_REAL  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		const char * __t__p3 = __p3;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page , HPDF_REAL , HPDF_REAL , const char *))*(void**)(__base - 1144))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define HPDF_Page_GetWidth(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_REAL (*)(HPDF_Page ))*(void**)(__base - 694))(__t__p0));\
	})

#define HPDF_LoadPngImageFromFile(__p0, __p1) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_Image (*)(HPDF_Doc , const char *))*(void**)(__base - 472))(__t__p0, __t__p1));\
	})

#define HPDF_Page_ClosePathFillStroke(__p0) \
	({ \
		HPDF_Page  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Page ))*(void**)(__base - 1024))(__t__p0));\
	})

#define HPDF_GetViewerPreference(__p0) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_UINT (*)(HPDF_Doc ))*(void**)(__base - 166))(__t__p0));\
	})

#define HPDF_Annotation_SetBorderStyle(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_BSSubtype  __t__p1 = __p1;\
		HPDF_REAL  __t__p2 = __p2;\
		HPDF_UINT16  __t__p3 = __p3;\
		HPDF_UINT16  __t__p4 = __p4;\
		HPDF_UINT16  __t__p5 = __p5;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_BSSubtype , HPDF_REAL , HPDF_UINT16 , HPDF_UINT16 , HPDF_UINT16 ))*(void**)(__base - 1522))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define HPDF_GetContents(__p0, __p1, __p2) \
	({ \
		HPDF_Doc  __t__p0 = __p0;\
		HPDF_BYTE * __t__p1 = __p1;\
		HPDF_UINT32 * __t__p2 = __p2;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Doc , HPDF_BYTE *, HPDF_UINT32 *))*(void**)(__base - 1288))(__t__p0, __t__p1, __t__p2));\
	})

#define HPDF_Annot_SetRGBColor(__p0, __p1) \
	({ \
		HPDF_Annotation  __t__p0 = __p0;\
		HPDF_RGBColor  __t__p1 = __p1;\
		long __base = (long)(HPDF_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((HPDF_STATUS (*)(HPDF_Annotation , HPDF_RGBColor ))*(void**)(__base - 1366))(__t__p0, __t__p1));\
	})

#endif /* !_PPCINLINE_HPDF_H */
