/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_FONTCONFIG_H
#define _PPCINLINE_FONTCONFIG_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef FONTCONFIG_BASE_NAME
#define FONTCONFIG_BASE_NAME FontConfigBase
#endif /* !FONTCONFIG_BASE_NAME */

#define FcCharSetHasChar(__p0, __p1) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		FcChar32  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcCharSet *, FcChar32 ))*(void**)(__base - 292))(__t__p0, __t__p1));\
	})

#define FcConfigDestroy(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcConfig *))*(void**)(__base - 124))(__t__p0));\
	})

#define FcCharSetSubtract(__p0, __p1) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		const FcCharSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCharSet *(*)(const FcCharSet *, const FcCharSet *))*(void**)(__base - 280))(__t__p0, __t__p1));\
	})

#define FcConfigEnableHome(__p0) \
	({ \
		FcBool  __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcBool ))*(void**)(__base - 100))(__t__p0));\
	})

#define FcConfigGetConfigDirs(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrList *(*)(FcConfig *))*(void**)(__base - 160))(__t__p0));\
	})

#define FcGetVersion() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(void))*(void**)(__base - 454))());\
	})

#define FcMatrixShear(__p0, __p1, __p2) \
	({ \
		FcMatrix * __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcMatrix *, double , double ))*(void**)(__base - 694))(__t__p0, __t__p1, __t__p2));\
	})

#define FcFontSetPrint(__p0) \
	({ \
		const FcFontSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const FcFontSet *))*(void**)(__base - 346))(__t__p0));\
	})

#define FcConfigGetCacheDirs(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrList *(*)(FcConfig *))*(void**)(__base - 184))(__t__p0));\
	})

#define FcPatternAddBool(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		FcBool  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, FcBool ))*(void**)(__base - 880))(__t__p0, __t__p1, __t__p2));\
	})

#define FcStrStrIgnoreCase(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const FcChar8 *(*)(const FcChar8 *, const FcChar8 *))*(void**)(__base - 988))(__t__p0, __t__p1));\
	})

#define FcFreeTypeCharIndex(__p0, __p1) \
	({ \
		FT_Face  __t__p0 = __p0;\
		FcChar32  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FT_UInt (*)(FT_Face , FcChar32 ))*(void**)(__base - 1120))(__t__p0, __t__p1));\
	})

#define FcObjectSetAdd(__p0, __p1) \
	({ \
		FcObjectSet * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcObjectSet *, const char *))*(void**)(__base - 550))(__t__p0, __t__p1));\
	})

#define FcPatternAddDouble(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, double ))*(void**)(__base - 856))(__t__p0, __t__p1, __t__p2));\
	})

#define FcMatrixScale(__p0, __p1, __p2) \
	({ \
		FcMatrix * __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcMatrix *, double , double ))*(void**)(__base - 688))(__t__p0, __t__p1, __t__p2));\
	})

#if !defined(__STRICT_ANSI__)
#define FcObjectSetBuild(...) \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		(((FcObjectSet *(*)(const char *, ...))*(void**)(__base - 1108))(__VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define FcAtomicDeleteNew(__p0) \
	({ \
		FcAtomic * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcAtomic *))*(void**)(__base - 610))(__t__p0));\
	})

#define FcCharSetAddChar(__p0, __p1) \
	({ \
		FcCharSet * __t__p0 = __p0;\
		FcChar32  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcCharSet *, FcChar32 ))*(void**)(__base - 250))(__t__p0, __t__p1));\
	})

#define FcNameUnregisterConstants(__p0, __p1) \
	({ \
		const FcConstant * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcConstant *, int ))*(void**)(__base - 724))(__t__p0, __t__p1));\
	})

#define FcLangSetCopy(__p0) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcLangSet *(*)(const FcLangSet *))*(void**)(__base - 496))(__t__p0));\
	})

#define FcMatrixCopy(__p0) \
	({ \
		const FcMatrix * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcMatrix *(*)(const FcMatrix *))*(void**)(__base - 664))(__t__p0));\
	})

#define FcNameUnparse(__p0) \
	({ \
		FcPattern * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(FcPattern *))*(void**)(__base - 748))(__t__p0));\
	})

#define FcConfigFilename(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(const FcChar8 *))*(void**)(__base - 106))(__t__p0));\
	})

#define FcCharSetDelChar(__p0, __p1) \
	({ \
		FcCharSet * __t__p0 = __p0;\
		FcChar32  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcCharSet *, FcChar32 ))*(void**)(__base - 1168))(__t__p0, __t__p1));\
	})

#define FcPatternEqualSubset(__p0, __p1, __p2) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const FcPattern * __t__p1 = __p1;\
		const FcObjectSet * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcPattern *, const FcPattern *, const FcObjectSet *))*(void**)(__base - 808))(__t__p0, __t__p1, __t__p2));\
	})

#define FcStrListCreate(__p0) \
	({ \
		FcStrSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrList *(*)(FcStrSet *))*(void**)(__base - 1084))(__t__p0));\
	})

#define FcCharSetNextPage(__p0, __p1, __p2) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		FcChar32 * __t__p1 = __p1;\
		FcChar32 * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar32 (*)(const FcCharSet *, FcChar32 *, FcChar32 *))*(void**)(__base - 328))(__t__p0, __t__p1, __t__p2));\
	})

#define FcCharSetFirstPage(__p0, __p1, __p2) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		FcChar32 * __t__p1 = __p1;\
		FcChar32 * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar32 (*)(const FcCharSet *, FcChar32 *, FcChar32 *))*(void**)(__base - 322))(__t__p0, __t__p1, __t__p2));\
	})

#define FcStrSetDestroy(__p0) \
	({ \
		FcStrSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcStrSet *))*(void**)(__base - 1078))(__t__p0));\
	})

#define FcBlanksDestroy(__p0) \
	({ \
		FcBlanks * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcBlanks *))*(void**)(__base - 34))(__t__p0));\
	})

#define FcConfigReference(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcConfig *(*)(FcConfig *))*(void**)(__base - 118))(__t__p0));\
	})

#define FcPatternGet(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcValue * __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , FcValue *))*(void**)(__base - 832))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcCharSetCreate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCharSet *(*)(void))*(void**)(__base - 238))());\
	})

#define FcGetDefaultLangs() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrSet *(*)(void))*(void**)(__base - 1204))());\
	})

#define FcLangSetEqual(__p0, __p1) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		const FcLangSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcLangSet *, const FcLangSet *))*(void**)(__base - 526))(__t__p0, __t__p1));\
	})

#define FcCharSetEqual(__p0, __p1) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		const FcCharSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcCharSet *, const FcCharSet *))*(void**)(__base - 262))(__t__p0, __t__p1));\
	})

#define FcCharSetIsSubset(__p0, __p1) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		const FcCharSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcCharSet *, const FcCharSet *))*(void**)(__base - 316))(__t__p0, __t__p1));\
	})

#define FcConfigAppFontAddDir(__p0, __p1) \
	({ \
		FcConfig * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *, const FcChar8 *))*(void**)(__base - 214))(__t__p0, __t__p1));\
	})

#define FcPatternGetBool(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcBool * __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , FcBool *))*(void**)(__base - 922))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcInitLoadConfigAndFonts() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcConfig *(*)(void))*(void**)(__base - 436))());\
	})

#define FcPatternGetFTFace(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FT_Face * __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , FT_Face *))*(void**)(__base - 1138))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcConfigGetCache(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(FcConfig *))*(void**)(__base - 172))(__t__p0));\
	})

#define FcPatternVaBuild(__p0, __p1) \
	({ \
		FcPattern * __t__p0 = __p0;\
		va_list  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(FcPattern *, va_list ))*(void**)(__base - 934))(__t__p0, __t__p1));\
	})

#define FcFontSetAdd(__p0, __p1) \
	({ \
		FcFontSet * __t__p0 = __p0;\
		FcPattern * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcFontSet *, FcPattern *))*(void**)(__base - 424))(__t__p0, __t__p1));\
	})

#define FcExtRemoveProgressCallback(__p0) \
	({ \
		FcExtProgressCallback  __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcExtProgressCallback ))*(void**)(__base - 1162))(__t__p0));\
	})

#define FcLangSetAdd(__p0, __p1) \
	({ \
		FcLangSet * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcLangSet *, const FcChar8 *))*(void**)(__base - 502))(__t__p0, __t__p1));\
	})

#define FcConfigSubstituteWithPat(__p0, __p1, __p2, __p3) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcPattern * __t__p1 = __p1;\
		FcPattern * __t__p2 = __p2;\
		FcMatchKind  __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *, FcPattern *, FcPattern *, FcMatchKind ))*(void**)(__base - 226))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcPatternAddLangSet(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const FcLangSet * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, const FcLangSet *))*(void**)(__base - 886))(__t__p0, __t__p1, __t__p2));\
	})

#define FcDirCacheLoadFile(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		struct stat * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCache *(*)(const FcChar8 *, struct stat *))*(void**)(__base - 394))(__t__p0, __t__p1));\
	})

#define FcPatternGetDouble(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		double * __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , double *))*(void**)(__base - 898))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcConfigSetSysRoot(__p0, __p1) \
	({ \
		FcConfig * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcConfig *, const FcChar8 *))*(void**)(__base - 1216))(__t__p0, __t__p1));\
	})

#define FcMatrixRotate(__p0, __p1, __p2) \
	({ \
		FcMatrix * __t__p0 = __p0;\
		double  __t__p1 = __p1;\
		double  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcMatrix *, double , double ))*(void**)(__base - 682))(__t__p0, __t__p1, __t__p2));\
	})

#define FcPatternGetLangSet(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcLangSet ** __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , FcLangSet **))*(void**)(__base - 928))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcExtInsertProgressCallback(__p0) \
	({ \
		FcExtProgressCallback  __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcExtProgressCallback ))*(void**)(__base - 1156))(__t__p0));\
	})

#define FcDirCacheUnlink(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		FcConfig * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcChar8 *, FcConfig *))*(void**)(__base - 82))(__t__p0, __t__p1));\
	})

#define FcUtf8ToUcs4(__p0, __p1, __p2) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		FcChar32 * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const FcChar8 *, FcChar32 *, int ))*(void**)(__base - 1000))(__t__p0, __t__p1, __t__p2));\
	})

#define FcStrPlus(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(const FcChar8 *, const FcChar8 *))*(void**)(__base - 958))(__t__p0, __t__p1));\
	})

#define FcCharSetDestroy(__p0) \
	({ \
		FcCharSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcCharSet *))*(void**)(__base - 244))(__t__p0));\
	})

#define FcAtomicCreate(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcAtomic *(*)(const FcChar8 *))*(void**)(__base - 580))(__t__p0));\
	})

#define FcStrSetDel(__p0, __p1) \
	({ \
		FcStrSet * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcStrSet *, const FcChar8 *))*(void**)(__base - 1072))(__t__p0, __t__p1));\
	})

#define FcConfigGetSysRoot(__p0) \
	({ \
		const FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const FcChar8 *(*)(const FcConfig *))*(void**)(__base - 1210))(__t__p0));\
	})

#define FcStrListDone(__p0) \
	({ \
		FcStrList * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcStrList *))*(void**)(__base - 1096))(__t__p0));\
	})

#define FcFontSetSort(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcFontSet ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcPattern * __t__p3 = __p3;\
		FcBool  __t__p4 = __p4;\
		FcCharSet ** __t__p5 = __p5;\
		FcResult * __t__p6 = __p6;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcFontSet *(*)(FcConfig *, FcFontSet **, int , FcPattern *, FcBool , FcCharSet **, FcResult *))*(void**)(__base - 646))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5, __t__p6));\
	})

#define FcAtomicReplaceOrig(__p0) \
	({ \
		FcAtomic * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcAtomic *))*(void**)(__base - 604))(__t__p0));\
	})

#define FcConfigUptoDate(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *))*(void**)(__base - 142))(__t__p0));\
	})

#define FcLangSetDestroy(__p0) \
	({ \
		FcLangSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcLangSet *))*(void**)(__base - 490))(__t__p0));\
	})

#define FcValueDestroy(__p0) \
	({ \
		FcValue  __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcValue ))*(void**)(__base - 778))(__t__p0));\
	})

#define FcMatrixEqual(__p0, __p1) \
	({ \
		const FcMatrix * __t__p0 = __p0;\
		const FcMatrix * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcMatrix *, const FcMatrix *))*(void**)(__base - 670))(__t__p0, __t__p1));\
	})

#define FcStrBasename(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(const FcChar8 *))*(void**)(__base - 1036))(__t__p0));\
	})

#define FcStrCmpIgnoreCase(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const FcChar8 *, const FcChar8 *))*(void**)(__base - 976))(__t__p0, __t__p1));\
	})

#define FcUcs4ToUtf8(__p0, __p1) \
	({ \
		FcChar32  __t__p0 = __p0;\
		FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(FcChar32 , FcChar8 *))*(void**)(__base - 1012))(__t__p0, __t__p1));\
	})

#define FcFreeTypeCharSet(__p0, __p1) \
	({ \
		FT_Face  __t__p0 = __p0;\
		FcBlanks * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCharSet *(*)(FT_Face , FcBlanks *))*(void**)(__base - 1132))(__t__p0, __t__p1));\
	})

#define FcCacheNumSubdir(__p0) \
	({ \
		const FcCache * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const FcCache *))*(void**)(__base - 70))(__t__p0));\
	})

#define FcAtomicDestroy(__p0) \
	({ \
		FcAtomic * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcAtomic *))*(void**)(__base - 622))(__t__p0));\
	})

#define FcFontSort(__p0, __p1, __p2, __p3, __p4) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcPattern * __t__p1 = __p1;\
		FcBool  __t__p2 = __p2;\
		FcCharSet ** __t__p3 = __p3;\
		FcResult * __t__p4 = __p4;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcFontSet *(*)(FcConfig *, FcPattern *, FcBool , FcCharSet **, FcResult *))*(void**)(__base - 652))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define FcConfigGetFontDirs(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrList *(*)(FcConfig *))*(void**)(__base - 154))(__t__p0));\
	})

#define FcConfigAppFontClear(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcConfig *))*(void**)(__base - 220))(__t__p0));\
	})

#define FcCharSetCopy(__p0) \
	({ \
		FcCharSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCharSet *(*)(FcCharSet *))*(void**)(__base - 256))(__t__p0));\
	})

#define FcBlanksIsMember(__p0, __p1) \
	({ \
		FcBlanks * __t__p0 = __p0;\
		FcChar32  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcBlanks *, FcChar32 ))*(void**)(__base - 46))(__t__p0, __t__p1));\
	})

#define FcNameConstant(__p0, __p1) \
	({ \
		FcChar8 * __t__p0 = __p0;\
		int * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcChar8 *, int *))*(void**)(__base - 736))(__t__p0, __t__p1));\
	})

#define FcConfigGetBlanks(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBlanks *(*)(FcConfig *))*(void**)(__base - 178))(__t__p0));\
	})

#define FcFreeTypeQuery(__p0, __p1, __p2, __p3) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		FcBlanks * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(const FcChar8 *, int , FcBlanks *, int *))*(void**)(__base - 406))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcPatternAddWeak(__p0, __p1, __p2, __p3) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		FcValue  __t__p2 = __p2;\
		FcBool  __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, FcValue , FcBool ))*(void**)(__base - 826))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcLangSetUnion(__p0, __p1) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		const FcLangSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcLangSet *(*)(const FcLangSet *, const FcLangSet *))*(void**)(__base - 1180))(__t__p0, __t__p1));\
	})

#define FcCharSetUnion(__p0, __p1) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		const FcCharSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCharSet *(*)(const FcCharSet *, const FcCharSet *))*(void**)(__base - 274))(__t__p0, __t__p1));\
	})

#define FcUtf8Len(__p0, __p1, __p2, __p3) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcChar8 *, int , int *, int *))*(void**)(__base - 1006))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcPatternHash(__p0) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar32 (*)(const FcPattern *))*(void**)(__base - 814))(__t__p0));\
	})

#define FcCacheDir(__p0) \
	({ \
		const FcCache * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const FcChar8 *(*)(const FcCache *))*(void**)(__base - 52))(__t__p0));\
	})

#define FcObjectSetVaBuild(__p0, __p1) \
	({ \
		const char * __t__p0 = __p0;\
		va_list  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcObjectSet *(*)(const char *, va_list ))*(void**)(__base - 562))(__t__p0, __t__p1));\
	})

#define FcCharSetIntersectCount(__p0, __p1) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		const FcCharSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar32 (*)(const FcCharSet *, const FcCharSet *))*(void**)(__base - 304))(__t__p0, __t__p1));\
	})

#define FcConfigSetCurrent(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *))*(void**)(__base - 130))(__t__p0));\
	})

#define FcPatternDestroy(__p0) \
	({ \
		FcPattern * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcPattern *))*(void**)(__base - 796))(__t__p0));\
	})

#define FcDirCacheRescan(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		FcConfig * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCache *(*)(const FcChar8 *, FcConfig *))*(void**)(__base - 1222))(__t__p0, __t__p1));\
	})

#define FcCharSetIntersect(__p0, __p1) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		const FcCharSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCharSet *(*)(const FcCharSet *, const FcCharSet *))*(void**)(__base - 268))(__t__p0, __t__p1));\
	})

#define FcStrListNext(__p0) \
	({ \
		FcStrList * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(FcStrList *))*(void**)(__base - 1090))(__t__p0));\
	})

#define FcConfigBuildFonts(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *))*(void**)(__base - 148))(__t__p0));\
	})

#define FcCacheNumFont(__p0) \
	({ \
		const FcCache * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const FcCache *))*(void**)(__base - 76))(__t__p0));\
	})

#define FcInit() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(void))*(void**)(__base - 442))());\
	})

#define FcPatternAddMatrix(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const FcMatrix * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, const FcMatrix *))*(void**)(__base - 868))(__t__p0, __t__p1, __t__p2));\
	})

#define FcConfigCreate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcConfig *(*)(void))*(void**)(__base - 112))());\
	})

#define FcConfigGetCurrent() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcConfig *(*)(void))*(void**)(__base - 136))());\
	})

#define FcConfigGetConfigFiles(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrList *(*)(FcConfig *))*(void**)(__base - 166))(__t__p0));\
	})

#define FcConfigSetRescanInterval(__p0, __p1) \
	({ \
		FcConfig * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *, int ))*(void**)(__base - 196))(__t__p0, __t__p1));\
	})

#define FcDirCacheClean(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		FcBool  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcChar8 *, FcBool ))*(void**)(__base - 1192))(__t__p0, __t__p1));\
	})

#define FcDirCacheRead(__p0, __p1, __p2) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		FcBool  __t__p1 = __p1;\
		FcConfig * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCache *(*)(const FcChar8 *, FcBool , FcConfig *))*(void**)(__base - 388))(__t__p0, __t__p1, __t__p2));\
	})

#define FcLangSetDel(__p0, __p1) \
	({ \
		FcLangSet * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcLangSet *, const FcChar8 *))*(void**)(__base - 1174))(__t__p0, __t__p1));\
	})

#define FcPatternAddCharSet(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const FcCharSet * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, const FcCharSet *))*(void**)(__base - 874))(__t__p0, __t__p1, __t__p2));\
	})

#define FcPatternAddString(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const FcChar8 * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, const FcChar8 *))*(void**)(__base - 862))(__t__p0, __t__p1, __t__p2));\
	})

#define FcPatternGetCharSet(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcCharSet ** __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , FcCharSet **))*(void**)(__base - 916))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcCharSetSubtractCount(__p0, __p1) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		const FcCharSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar32 (*)(const FcCharSet *, const FcCharSet *))*(void**)(__base - 310))(__t__p0, __t__p1));\
	})

#define FcStrDirname(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(const FcChar8 *))*(void**)(__base - 1030))(__t__p0));\
	})

#define FcMatrixMultiply(__p0, __p1, __p2) \
	({ \
		FcMatrix * __t__p0 = __p0;\
		const FcMatrix * __t__p1 = __p1;\
		const FcMatrix * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcMatrix *, const FcMatrix *, const FcMatrix *))*(void**)(__base - 676))(__t__p0, __t__p1, __t__p2));\
	})

#define FcConfigParseAndLoad(__p0, __p1, __p2) \
	({ \
		FcConfig * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		FcBool  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *, const FcChar8 *, FcBool ))*(void**)(__base - 1102))(__t__p0, __t__p1, __t__p2));\
	})

#define FcValueSave(__p0) \
	({ \
		FcValue  __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcValue (*)(FcValue ))*(void**)(__base - 790))(__t__p0));\
	})

#define FcNameRegisterObjectTypes(__p0, __p1) \
	({ \
		const FcObjectType * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcObjectType *, int ))*(void**)(__base - 700))(__t__p0, __t__p1));\
	})

#define FcInitLoadConfig() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcConfig *(*)(void))*(void**)(__base - 430))());\
	})

#define FcBlanksAdd(__p0, __p1) \
	({ \
		FcBlanks * __t__p0 = __p0;\
		FcChar32  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcBlanks *, FcChar32 ))*(void**)(__base - 40))(__t__p0, __t__p1));\
	})

#define FcConfigGetFonts(__p0, __p1) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcSetName  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcFontSet *(*)(FcConfig *, FcSetName ))*(void**)(__base - 202))(__t__p0, __t__p1));\
	})

#define FcPatternAdd(__p0, __p1, __p2, __p3) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		FcValue  __t__p2 = __p2;\
		FcBool  __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, FcValue , FcBool ))*(void**)(__base - 820))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcFontSetSortDestroy(__p0) \
	({ \
		FcFontSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcFontSet *))*(void**)(__base - 658))(__t__p0));\
	})

#define FcLangGetCharSet(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const FcCharSet *(*)(const FcChar8 *))*(void**)(__base - 478))(__t__p0));\
	})

#define FcPatternReference(__p0) \
	({ \
		FcPattern * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcPattern *))*(void**)(__base - 766))(__t__p0));\
	})

#define FcPatternGetMatrix(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcMatrix ** __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , FcMatrix **))*(void**)(__base - 910))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcAtomicOrigFile(__p0) \
	({ \
		FcAtomic * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(FcAtomic *))*(void**)(__base - 598))(__t__p0));\
	})

#define FcNameUnregisterObjectTypes(__p0, __p1) \
	({ \
		const FcObjectType * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcObjectType *, int ))*(void**)(__base - 706))(__t__p0, __t__p1));\
	})

#define FcStrSetCreate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrSet *(*)(void))*(void**)(__base - 1042))());\
	})

#define FcPatternRemove(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, int ))*(void**)(__base - 844))(__t__p0, __t__p1, __t__p2));\
	})

#define FcFileScan(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		FcFontSet * __t__p0 = __p0;\
		FcStrSet * __t__p1 = __p1;\
		FcFileCache * __t__p2 = __p2;\
		FcBlanks * __t__p3 = __p3;\
		const FcChar8 * __t__p4 = __p4;\
		FcBool  __t__p5 = __p5;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcFontSet *, FcStrSet *, FcFileCache *, FcBlanks *, const FcChar8 *, FcBool ))*(void**)(__base - 364))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define FcNameGetObjectType(__p0) \
	({ \
		const char * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const FcObjectType *(*)(const char *))*(void**)(__base - 712))(__t__p0));\
	})

#define FcLangSetCompare(__p0, __p1) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		const FcLangSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcLangResult (*)(const FcLangSet *, const FcLangSet *))*(void**)(__base - 514))(__t__p0, __t__p1));\
	})

#define FcDefaultSubstitute(__p0) \
	({ \
		FcPattern * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcPattern *))*(void**)(__base - 352))(__t__p0));\
	})

#define FcConfigHome() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(void))*(void**)(__base - 94))());\
	})

#define FcConfigGetRescanInterval(__p0) \
	({ \
		FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(FcConfig *))*(void**)(__base - 190))(__t__p0));\
	})

#define FcStrSetEqual(__p0, __p1) \
	({ \
		FcStrSet * __t__p0 = __p0;\
		FcStrSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcStrSet *, FcStrSet *))*(void**)(__base - 1054))(__t__p0, __t__p1));\
	})

#define FcObjectSetDestroy(__p0) \
	({ \
		FcObjectSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcObjectSet *))*(void**)(__base - 556))(__t__p0));\
	})

#define FcLangSetContains(__p0, __p1) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		const FcLangSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcLangSet *, const FcLangSet *))*(void**)(__base - 520))(__t__p0, __t__p1));\
	})

#define FcDirSave(__p0, __p1, __p2) \
	({ \
		FcFontSet * __t__p0 = __p0;\
		FcStrSet * __t__p1 = __p1;\
		const FcChar8 * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcFontSet *, FcStrSet *, const FcChar8 *))*(void**)(__base - 376))(__t__p0, __t__p1, __t__p2));\
	})

#define FcInitReinitialize() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(void))*(void**)(__base - 460))());\
	})

#define FcUtf16ToUcs4(__p0, __p1, __p2, __p3) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		FcEndian  __t__p1 = __p1;\
		FcChar32 * __t__p2 = __p2;\
		int  __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const FcChar8 *, FcEndian , FcChar32 *, int ))*(void**)(__base - 1018))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcStrSetMember(__p0, __p1) \
	({ \
		FcStrSet * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcStrSet *, const FcChar8 *))*(void**)(__base - 1048))(__t__p0, __t__p1));\
	})

#define FcDirScan(__p0, __p1, __p2, __p3, __p4, __p5) \
	({ \
		FcFontSet * __t__p0 = __p0;\
		FcStrSet * __t__p1 = __p1;\
		FcFileCache * __t__p2 = __p2;\
		FcBlanks * __t__p3 = __p3;\
		const FcChar8 * __t__p4 = __p4;\
		FcBool  __t__p5 = __p5;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcFontSet *, FcStrSet *, FcFileCache *, FcBlanks *, const FcChar8 *, FcBool ))*(void**)(__base - 370))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4, __t__p5));\
	})

#define FcFontSetList(__p0, __p1, __p2, __p3, __p4) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcFontSet ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcPattern * __t__p3 = __p3;\
		FcObjectSet * __t__p4 = __p4;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcFontSet *(*)(FcConfig *, FcFontSet **, int , FcPattern *, FcObjectSet *))*(void**)(__base - 568))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define FcCacheCopySet(__p0) \
	({ \
		const FcCache * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcFontSet *(*)(const FcCache *))*(void**)(__base - 58))(__t__p0));\
	})

#define FcObjectSetCreate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcObjectSet *(*)(void))*(void**)(__base - 544))());\
	})

#define FcStrFree(__p0) \
	({ \
		FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcChar8 *))*(void**)(__base - 964))(__t__p0));\
	})

#define FcPatternDuplicate(__p0) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(const FcPattern *))*(void**)(__base - 760))(__t__p0));\
	})

#define FcCharSetMerge(__p0, __p1, __p2) \
	({ \
		FcCharSet * __t__p0 = __p0;\
		const FcCharSet * __t__p1 = __p1;\
		FcBool * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcCharSet *, const FcCharSet *, FcBool *))*(void**)(__base - 286))(__t__p0, __t__p1, __t__p2));\
	})

#define FcPatternGetString(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcChar8 ** __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , FcChar8 **))*(void**)(__base - 904))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcAtomicNewFile(__p0) \
	({ \
		FcAtomic * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(FcAtomic *))*(void**)(__base - 592))(__t__p0));\
	})

#define FcPatternAddInteger(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, int ))*(void**)(__base - 850))(__t__p0, __t__p1, __t__p2));\
	})

#define FcValuePrint(__p0) \
	({ \
		const FcValue  __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const FcValue ))*(void**)(__base - 334))(__t__p0));\
	})

#define FcPatternGetInteger(__p0, __p1, __p2, __p3) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcResult (*)(const FcPattern *, const char *, int , int *))*(void**)(__base - 892))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcFontList(__p0, __p1, __p2) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcPattern * __t__p1 = __p1;\
		FcObjectSet * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcFontSet *(*)(FcConfig *, FcPattern *, FcObjectSet *))*(void**)(__base - 574))(__t__p0, __t__p1, __t__p2));\
	})

#define FcPatternPrint(__p0) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const FcPattern *))*(void**)(__base - 340))(__t__p0));\
	})

#define FcLangSetSubtract(__p0, __p1) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		const FcLangSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcLangSet *(*)(const FcLangSet *, const FcLangSet *))*(void**)(__base - 1186))(__t__p0, __t__p1));\
	})

#define FcDirCacheLoad(__p0, __p1, __p2) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		FcConfig * __t__p1 = __p1;\
		FcChar8 ** __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCache *(*)(const FcChar8 *, FcConfig *, FcChar8 **))*(void**)(__base - 382))(__t__p0, __t__p1, __t__p2));\
	})

#define FcStrCmp(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(const FcChar8 *, const FcChar8 *))*(void**)(__base - 982))(__t__p0, __t__p1));\
	})

#define FcStrSetAddFilename(__p0, __p1) \
	({ \
		FcStrSet * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcStrSet *, const FcChar8 *))*(void**)(__base - 1066))(__t__p0, __t__p1));\
	})

#define FcAtomicLock(__p0) \
	({ \
		FcAtomic * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcAtomic *))*(void**)(__base - 586))(__t__p0));\
	})

#define FcDirCacheUnload(__p0) \
	({ \
		FcCache * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcCache *))*(void**)(__base - 400))(__t__p0));\
	})

#define FcGetLangs() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrSet *(*)(void))*(void**)(__base - 472))());\
	})

#define FcStrCopy(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(const FcChar8 *))*(void**)(__base - 946))(__t__p0));\
	})

#define FcUtf16Len(__p0, __p1, __p2, __p3, __p4) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		FcEndian  __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		int * __t__p3 = __p3;\
		int * __t__p4 = __p4;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcChar8 *, FcEndian , int , int *, int *))*(void**)(__base - 1024))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define FcLangSetHash(__p0) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar32 (*)(const FcLangSet *))*(void**)(__base - 532))(__t__p0));\
	})

#define FcNameParse(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(const FcChar8 *))*(void**)(__base - 742))(__t__p0));\
	})

#define FcInitBringUptoDate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(void))*(void**)(__base - 466))());\
	})

#define FcCacheSubdir(__p0, __p1) \
	({ \
		const FcCache * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const FcChar8 *(*)(const FcCache *, int ))*(void**)(__base - 64))(__t__p0, __t__p1));\
	})

#define FcNameGetConstant(__p0) \
	({ \
		FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const FcConstant *(*)(FcChar8 *))*(void**)(__base - 730))(__t__p0));\
	})

#define FcCharSetCount(__p0) \
	({ \
		const FcCharSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar32 (*)(const FcCharSet *))*(void**)(__base - 298))(__t__p0));\
	})

#define FcFontSetDestroy(__p0) \
	({ \
		FcFontSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcFontSet *))*(void**)(__base - 418))(__t__p0));\
	})

#define FcFini() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(void))*(void**)(__base - 448))());\
	})

#define FcStrCopyFilename(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(const FcChar8 *))*(void**)(__base - 952))(__t__p0));\
	})

#define FcFreeTypeQueryFace(__p0, __p1, __p2, __p3) \
	({ \
		const FT_Face  __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcBlanks * __t__p3 = __p3;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(const FT_Face , const FcChar8 *, int , FcBlanks *))*(void**)(__base - 1150))(__t__p0, __t__p1, __t__p2, __t__p3));\
	})

#define FcPatternCreate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(void))*(void**)(__base - 754))());\
	})

#define FcCacheCreateTagFile(__p0) \
	({ \
		const FcConfig * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(const FcConfig *))*(void**)(__base - 1198))(__t__p0));\
	})

#define FcLangSetHasLang(__p0, __p1) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcLangResult (*)(const FcLangSet *, const FcChar8 *))*(void**)(__base - 508))(__t__p0, __t__p1));\
	})

#define FcFontSetCreate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcFontSet *(*)(void))*(void**)(__base - 412))());\
	})

#define FcConfigSubstitute(__p0, __p1, __p2) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcPattern * __t__p1 = __p1;\
		FcMatchKind  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *, FcPattern *, FcMatchKind ))*(void**)(__base - 232))(__t__p0, __t__p1, __t__p2));\
	})

#define FcPatternFormat(__p0, __p1) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(FcPattern *, const FcChar8 *))*(void**)(__base - 940))(__t__p0, __t__p1));\
	})

#define FcAtomicUnlock(__p0) \
	({ \
		FcAtomic * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(FcAtomic *))*(void**)(__base - 616))(__t__p0));\
	})

#define FcLangSetCreate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcLangSet *(*)(void))*(void**)(__base - 484))());\
	})

#define FcStrDowncase(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcChar8 *(*)(const FcChar8 *))*(void**)(__base - 970))(__t__p0));\
	})

#define FcFontRenderPrepare(__p0, __p1, __p2) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcPattern * __t__p1 = __p1;\
		FcPattern * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(FcConfig *, FcPattern *, FcPattern *))*(void**)(__base - 640))(__t__p0, __t__p1, __t__p2));\
	})

#define FcLangSetGetLangs(__p0) \
	({ \
		const FcLangSet * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcStrSet *(*)(const FcLangSet *))*(void**)(__base - 538))(__t__p0));\
	})

#define FcPatternFilter(__p0, __p1) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const FcObjectSet * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(FcPattern *, const FcObjectSet *))*(void**)(__base - 772))(__t__p0, __t__p1));\
	})

#define FcValueEqual(__p0, __p1) \
	({ \
		FcValue  __t__p0 = __p0;\
		FcValue  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcValue , FcValue ))*(void**)(__base - 784))(__t__p0, __t__p1));\
	})

#define FcStrStr(__p0, __p1) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const FcChar8 *(*)(const FcChar8 *, const FcChar8 *))*(void**)(__base - 994))(__t__p0, __t__p1));\
	})

#define FcNameRegisterConstants(__p0, __p1) \
	({ \
		const FcConstant * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcConstant *, int ))*(void**)(__base - 718))(__t__p0, __t__p1));\
	})

#define FcConfigAppFontAddFile(__p0, __p1) \
	({ \
		FcConfig * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcConfig *, const FcChar8 *))*(void**)(__base - 208))(__t__p0, __t__p1));\
	})

#define FcPatternEqual(__p0, __p1) \
	({ \
		const FcPattern * __t__p0 = __p0;\
		const FcPattern * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcPattern *, const FcPattern *))*(void**)(__base - 802))(__t__p0, __t__p1));\
	})

#define FcStrSetAdd(__p0, __p1) \
	({ \
		FcStrSet * __t__p0 = __p0;\
		const FcChar8 * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcStrSet *, const FcChar8 *))*(void**)(__base - 1060))(__t__p0, __t__p1));\
	})

#define FcFontSetMatch(__p0, __p1, __p2, __p3, __p4) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcFontSet ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		FcPattern * __t__p3 = __p3;\
		FcResult * __t__p4 = __p4;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(FcConfig *, FcFontSet **, int , FcPattern *, FcResult *))*(void**)(__base - 628))(__t__p0, __t__p1, __t__p2, __t__p3, __t__p4));\
	})

#define FcPatternDel(__p0, __p1) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *))*(void**)(__base - 838))(__t__p0, __t__p1));\
	})

#define FcFreeTypeCharSetAndSpacing(__p0, __p1, __p2) \
	({ \
		FT_Face  __t__p0 = __p0;\
		FcBlanks * __t__p1 = __p1;\
		int * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcCharSet *(*)(FT_Face , FcBlanks *, int *))*(void**)(__base - 1126))(__t__p0, __t__p1, __t__p2));\
	})

#define FcBlanksCreate() \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBlanks *(*)(void))*(void**)(__base - 28))());\
	})

#define FcDirCacheValid(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcChar8 *))*(void**)(__base - 88))(__t__p0));\
	})

#define FcFontMatch(__p0, __p1, __p2) \
	({ \
		FcConfig * __t__p0 = __p0;\
		FcPattern * __t__p1 = __p1;\
		FcResult * __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcPattern *(*)(FcConfig *, FcPattern *, FcResult *))*(void**)(__base - 634))(__t__p0, __t__p1, __t__p2));\
	})

#define FcFileIsDir(__p0) \
	({ \
		const FcChar8 * __t__p0 = __p0;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(const FcChar8 *))*(void**)(__base - 358))(__t__p0));\
	})

#if !defined(__STRICT_ANSI__)
#define FcPatternBuild(...) \
	({ \
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		(((FcPattern *(*)(FcPattern *, ...))*(void**)(__base - 1114))(__VA_ARGS__,({__asm volatile("mr 12,%0": :"r"(__base):"r12");0L;})));\
	})
#endif

#define FcPatternAddFTFace(__p0, __p1, __p2) \
	({ \
		FcPattern * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		const FT_Face  __t__p2 = __p2;\
		long __base = (long)(FONTCONFIG_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((FcBool (*)(FcPattern *, const char *, const FT_Face ))*(void**)(__base - 1144))(__t__p0, __t__p1, __t__p2));\
	})

#endif /* !_PPCINLINE_FONTCONFIG_H */
