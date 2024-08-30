#ifndef FONTCONFIG_PROTOS_H
#define FONTCONFIG_PROTOS_H

/*
 * fontconfig.library include
 *
 * Copyright (C) 2012 The MorphOS Development Team, All Rights Reserved.
 */

#ifndef FONTCONFIG_FONTCONFIG_H
#include <fontconfig/fontconfig.h>
#endif

#include <ft2build.h>
// ft2build.h should include these but Linux is sooooooo gay and it wont
#include <freetype/freetype.h>
#include <freetype/fttypes.h>

#if 0
/* These are already defined in fontconfig.h */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define FC_CHARSET_MAP_SIZE (256/32)
#define FC_CHARSET_DONE	((FcChar32) -1)
#define FC_UTF8_MAX_LEN	6

FcBlanks *FcBlanksCreate (void);
void FcBlanksDestroy (FcBlanks *b);
FcBool FcBlanksAdd (FcBlanks *b, FcChar32 ucs4);
FcBool FcBlanksIsMember (FcBlanks *b, FcChar32 ucs4);

const FcChar8 *FcCacheDir(const FcCache *c);
FcFontSet *FcCacheCopySet(const FcCache *c);
const FcChar8 *FcCacheSubdir (const FcCache *c, int i);
int FcCacheNumSubdir (const FcCache *c);
int FcCacheNumFont (const FcCache *c);
FcBool FcDirCacheUnlink (const FcChar8 *dir, FcConfig *config);
FcBool FcDirCacheValid (const FcChar8 *cache_file);

FcChar8 *FcConfigHome (void);
FcBool FcConfigEnableHome (FcBool enable);
FcChar8 *FcConfigFilename (const FcChar8 *url);
FcConfig *FcConfigCreate (void);
FcConfig *FcConfigReference (FcConfig *config);
void FcConfigDestroy (FcConfig *config);
FcBool FcConfigSetCurrent (FcConfig *config);
FcConfig *FcConfigGetCurrent (void);
FcBool FcConfigUptoDate (FcConfig *config);
FcBool FcConfigBuildFonts (FcConfig *config);
FcStrList *FcConfigGetFontDirs (FcConfig   *config);
FcStrList *FcConfigGetConfigDirs (FcConfig   *config);
FcStrList *FcConfigGetConfigFiles (FcConfig    *config);
FcChar8 *FcConfigGetCache (FcConfig  *config);
FcBlanks *FcConfigGetBlanks (FcConfig *config);
FcStrList *FcConfigGetCacheDirs (FcConfig	*config);
int FcConfigGetRescanInterval (FcConfig *config);
FcBool FcConfigSetRescanInterval (FcConfig *config, int rescanInterval);
FcFontSet *FcConfigGetFonts (FcConfig	*config,		  FcSetName	set);
FcBool FcConfigAppFontAddFile (FcConfig    *config,			const FcChar8  *file);
FcBool FcConfigAppFontAddDir (FcConfig	    *config,const FcChar8   *dir);
void FcConfigAppFontClear (FcConfig	    *config);
FcBool FcConfigSubstituteWithPat (FcConfig	*config,			   FcPattern	*p,			   FcPattern	*p_pat,			   FcMatchKind	kind);
FcBool FcConfigSubstitute (FcConfig	*config,		    FcPattern	*p,		    FcMatchKind	kind);
const FcChar8 *FcConfigGetSysRoot (const FcConfig *config);
void FcConfigSetSysRoot (FcConfig *config, const FcChar8 *sysroot);

FcCharSet*FcCharSetCreate (void);
void FcCharSetDestroy (FcCharSet *fcs);
FcBool FcCharSetAddChar (FcCharSet *fcs, FcChar32 ucs4);
FcBool FcCharSetDelChar (FcCharSet *fcs, FcChar32 ucs4);
FcCharSet*FcCharSetCopy (FcCharSet *src);
FcBool FcCharSetEqual (const FcCharSet *a, const FcCharSet *b);
FcCharSet*FcCharSetIntersect (const FcCharSet *a, const FcCharSet *b);
FcCharSet*FcCharSetUnion (const FcCharSet *a, const FcCharSet *b);
FcCharSet*FcCharSetSubtract (const FcCharSet *a, const FcCharSet *b);
FcBool FcCharSetMerge (FcCharSet *a, const FcCharSet *b, FcBool *changed);
FcBool FcCharSetHasChar (const FcCharSet *fcs, FcChar32 ucs4);
FcChar32 FcCharSetCount (const FcCharSet *a);
FcChar32 FcCharSetIntersectCount (const FcCharSet *a, const FcCharSet *b);
FcChar32 FcCharSetSubtractCount (const FcCharSet *a, const FcCharSet *b);
FcBool FcCharSetIsSubset (const FcCharSet *a, const FcCharSet *b);
FcChar32 FcCharSetFirstPage(const FcCharSet *a, FcChar32	map[FC_CHARSET_MAP_SIZE],		    FcChar32	    *next);
FcChar32 FcCharSetNextPage(const FcCharSet *a, FcChar32 map[FC_CHARSET_MAP_SIZE],		   FcChar32	    *next);

void FcValuePrint (const FcValue v);
void FcPatternPrint (const FcPattern *p);
void FcFontSetPrint (const FcFontSet *s);

void FcDefaultSubstitute (FcPattern *pattern);

FcBool FcFileIsDir (const FcChar8 *file);
FcBool FcFileScan (FcFontSet	    *set,	    FcStrSet	    *dirs,	    FcFileCache	    *cache,	    FcBlanks	    *blanks,	    const FcChar8   *file,	    FcBool	    force);
FcBool FcDirScan (FcFontSet	    *set,	   FcStrSet	    *dirs,	   FcFileCache	    *cache,	   FcBlanks	    *blanks,	   const FcChar8    *dir,	   FcBool	    force);
FcBool FcDirSave (FcFontSet *set, FcStrSet *dirs, const FcChar8 *dir);
FcCache *FcDirCacheLoad (const FcChar8 *dir, FcConfig *config, FcChar8 **cache_file);
FcCache *FcDirCacheRescan (const FcChar8 *dir, FcConfig *config);
FcCache *FcDirCacheRead (const FcChar8 *dir, FcBool force, FcConfig *config);
FcCache *FcDirCacheLoadFile (const FcChar8 *cache_file, struct stat *file_stat);
void FcDirCacheUnload (FcCache *cache);

FcPattern * FcFreeTypeQuery (const FcChar8 *file, int id, FcBlanks *blanks, int *count);

FcFontSet *FcFontSetCreate (void);

void FcFontSetDestroy (FcFontSet *s);
FcBool FcFontSetAdd (FcFontSet *s, FcPattern *font);

FcConfig *FcInitLoadConfig (void);
FcConfig *FcInitLoadConfigAndFonts (void);
FcBool FcInit (void);
void FcFini (void);
int FcGetVersion (void);
FcBool FcInitReinitialize (void);
FcBool FcInitBringUptoDate (void);

FcStrSet *FcGetLangs (void);
const FcCharSet *FcLangGetCharSet (const FcChar8 *lang);
FcLangSet *FcLangSetCreate (void);
void FcLangSetDestroy (FcLangSet *ls);
FcLangSet* FcLangSetCopy (const FcLangSet *ls);
FcBool FcLangSetAdd (FcLangSet *ls, const FcChar8 *lang);
FcBool FcLangSetDel (FcLangSet *ls, const FcChar8 *lang);
FcLangResult FcLangSetHasLang (const FcLangSet *ls, const FcChar8 *lang);
FcLangResult FcLangSetCompare (const FcLangSet *lsa, const FcLangSet *lsb);
FcBool FcLangSetContains (const FcLangSet *lsa, const FcLangSet *lsb);
FcBool FcLangSetEqual (const FcLangSet *lsa, const FcLangSet *lsb);
FcChar32 FcLangSetHash (const FcLangSet *ls);
FcStrSet *FcLangSetGetLangs (const FcLangSet *ls);
FcLangSet * FcLangSetUnion (const FcLangSet *a, const FcLangSet *b);
FcLangSet * FcLangSetSubtract (const FcLangSet *a, const FcLangSet *b);

FcObjectSet *FcObjectSetCreate (void);
FcBool FcObjectSetAdd (FcObjectSet *os, const char *object);
void FcObjectSetDestroy (FcObjectSet *os);
FcObjectSet *FcObjectSetVaBuild (const char *first, va_list va);
FcObjectSet *FcObjectSetBuild (const char *first, ...); /* FC_ATTRIBUTE_SENTINEL(0); */
FcFontSet *FcFontSetList (FcConfig	    *config,	       FcFontSet    **sets,	       int	    nsets,	       FcPattern    *p,	       FcObjectSet  *os);
FcFontSet *FcFontList (FcConfig	*config,	    FcPattern	*p,	    FcObjectSet *os);

FcAtomic *FcAtomicCreate (const FcChar8   *file);
FcBool FcAtomicLock (FcAtomic *atomic);
FcChar8 *FcAtomicNewFile (FcAtomic *atomic);
FcChar8 *FcAtomicOrigFile (FcAtomic *atomic);
FcBool FcAtomicReplaceOrig (FcAtomic *atomic);
void FcAtomicDeleteNew (FcAtomic *atomic);
void FcAtomicUnlock (FcAtomic *atomic);
void FcAtomicDestroy (FcAtomic *atomic);

FcPattern *FcFontSetMatch (FcConfig    *config,		FcFontSet   **sets,		int	    nsets,		FcPattern   *p,		FcResult    *result);
FcPattern *FcFontMatch (FcConfig	*config,	     FcPattern	*p, 	     FcResult	*result);
FcPattern *FcFontRenderPrepare (FcConfig	    *config,		     FcPattern	    *pat,		     FcPattern	    *font);
FcFontSet *FcFontSetSort (FcConfig	    *config,	       FcFontSet    **sets,	       int	    nsets,	       FcPattern    *p,	       FcBool	    trim,	       FcCharSet    **csp,	       FcResult	    *result);
FcFontSet *FcFontSort (FcConfig	 *config,	    FcPattern    *p,	    FcBool	 trim,	    FcCharSet    **csp,	    FcResult	 *result);
void FcFontSetSortDestroy (FcFontSet *fs);

FcMatrix *FcMatrixCopy (const FcMatrix *mat);
FcBool FcMatrixEqual (const FcMatrix *mat1, const FcMatrix *mat2);
void FcMatrixMultiply (FcMatrix *result, const FcMatrix *a, const FcMatrix *b);
void FcMatrixRotate (FcMatrix *m, double c, double s);
void FcMatrixScale (FcMatrix *m, double sx, double sy);
void FcMatrixShear (FcMatrix *m, double sh, double sv);

FcBool FcNameRegisterObjectTypes (const FcObjectType *types, int ntype);
FcBool FcNameUnregisterObjectTypes (const FcObjectType *types, int ntype);
const FcObjectType *FcNameGetObjectType (const char *object);
FcBool FcNameRegisterConstants (const FcConstant *consts, int nconsts);
FcBool FcNameUnregisterConstants (const FcConstant *consts, int nconsts);
const FcConstant *FcNameGetConstant (FcChar8 *string);
FcBool FcNameConstant (FcChar8 *string, int *result);
FcPattern *FcNameParse (const FcChar8 *name);
FcChar8 * FcNameUnparse (FcPattern *pat);

FcPattern *FcPatternCreate (void);
FcPattern *FcPatternDuplicate (const FcPattern *p);
void FcPatternReference (FcPattern *p);
FcPattern *FcPatternFilter (FcPattern *p, const FcObjectSet *os);
void FcValueDestroy (FcValue v);
FcBool FcValueEqual (FcValue va, FcValue vb);
FcValue FcValueSave (FcValue v);
void FcPatternDestroy (FcPattern *p);
FcBool FcPatternEqual (const FcPattern *pa, const FcPattern *pb);
FcBool FcPatternEqualSubset (const FcPattern *pa, const FcPattern *pb, const FcObjectSet *os);
FcChar32 FcPatternHash (const FcPattern *p);
FcBool FcPatternAdd (FcPattern *p, const char *object, FcValue value, FcBool append);
FcBool FcPatternAddWeak (FcPattern *p, const char *object, FcValue value, FcBool append);
FcResult FcPatternGet (const FcPattern *p, const char *object, int id, FcValue *v);
FcBool FcPatternDel (FcPattern *p, const char *object);
FcBool FcPatternRemove (FcPattern *p, const char *object, int id);
FcBool FcPatternAddInteger (FcPattern *p, const char *object, int i);
FcBool FcPatternAddDouble (FcPattern *p, const char *object, double d);
FcBool FcPatternAddString (FcPattern *p, const char *object, const FcChar8 *s);
FcBool FcPatternAddMatrix (FcPattern *p, const char *object, const FcMatrix *s);
FcBool FcPatternAddCharSet (FcPattern *p, const char *object, const FcCharSet *c);
FcBool FcPatternAddBool (FcPattern *p, const char *object, FcBool b);
FcBool FcPatternAddLangSet (FcPattern *p, const char *object, const FcLangSet *ls);
FcResult FcPatternGetInteger (const FcPattern *p, const char *object, int n, int *i);
FcResult FcPatternGetDouble (const FcPattern *p, const char *object, int n, double *d);
FcResult FcPatternGetString (const FcPattern *p, const char *object, int n, FcChar8 ** s);
FcResult FcPatternGetMatrix (const FcPattern *p, const char *object, int n, FcMatrix **s);
FcResult FcPatternGetCharSet (const FcPattern *p, const char *object, int n, FcCharSet **c);
FcResult FcPatternGetBool (const FcPattern *p, const char *object, int n, FcBool *b);
FcResult FcPatternGetLangSet (const FcPattern *p, const char *object, int n, FcLangSet **ls);
FcPattern *FcPatternVaBuild (FcPattern *p, va_list va);
FcPattern *FcPatternBuild (FcPattern *p, ...);	/* FC_ATTRIBUTE_SENTINEL(0); */
FcChar8 *FcPatternFormat (FcPattern *pat, const FcChar8 *format);

FcChar8 *FcStrCopy (const FcChar8 *s);
FcChar8 *FcStrCopyFilename (const FcChar8 *s);
FcChar8 *FcStrPlus (const FcChar8 *s1, const FcChar8 *s2);
void FcStrFree (FcChar8 *s);
FcChar8 *FcStrDowncase (const FcChar8 *s);
int FcStrCmpIgnoreCase (const FcChar8 *s1, const FcChar8 *s2);
int FcStrCmp (const FcChar8 *s1, const FcChar8 *s2);
const FcChar8 * FcStrStrIgnoreCase (const FcChar8 *s1, const FcChar8 *s2);
const FcChar8 *FcStrStr (const FcChar8 *s1, const FcChar8 *s2);
int FcUtf8ToUcs4 (const FcChar8 *src_orig, FcChar32	    *dst, int	    len);
FcBool FcUtf8Len (const FcChar8    *string,	   int		    len,	   int		    *nchar,	   int		    *wchar);
int FcUcs4ToUtf8 (FcChar32	ucs4,	      FcChar8	dest[FC_UTF8_MAX_LEN]);
int FcUtf16ToUcs4 (const FcChar8	*src_orig,	       FcEndian		endian,	       FcChar32		*dst,	       int		len);	    /* in bytes */
FcBool FcUtf16Len (const FcChar8   *string,	    FcEndian	    endian,	    int		    len,	    /* in bytes */	    int		    *nchar,	    int		    *wchar);
FcChar8 *FcStrDirname (const FcChar8 *file);
FcChar8 *FcStrBasename (const FcChar8 *file);
FcStrSet *FcStrSetCreate (void);
FcBool FcStrSetMember (FcStrSet *set, const FcChar8 *s);
FcBool FcStrSetEqual (FcStrSet *sa, FcStrSet *sb);
FcBool FcStrSetAdd (FcStrSet *set, const FcChar8 *s);
FcBool FcStrSetAddFilename (FcStrSet *set, const FcChar8 *s);
FcBool FcStrSetDel (FcStrSet *set, const FcChar8 *s);
void FcStrSetDestroy (FcStrSet *set);
FcStrList *FcStrListCreate (FcStrSet *set);
FcChar8 *FcStrListNext (FcStrList *list);
void FcStrListDone (FcStrList *list);
FcBool FcConfigParseAndLoad (FcConfig *config, const FcChar8 *file, FcBool complain);

FT_UInt FcFreeTypeCharIndex (FT_Face face, FcChar32 ucs4);
FcCharSet *FcFreeTypeCharSetAndSpacing (FT_Face face, FcBlanks *blanks, int *spacing);
FcCharSet *FcFreeTypeCharSet (FT_Face face, FcBlanks *blanks);
FcResult FcPatternGetFTFace (const FcPattern *p, const char *object, int n, FT_Face *f);
FcBool FcPatternAddFTFace (FcPattern *p, const char *object, const FT_Face f);
FcPattern *FcFreeTypeQueryFace (const FT_Face  face, const FcChar8  *file, int	    id, FcBlanks	    *blanks);

FcBool FcCharSetDelChar (FcCharSet *fcs, FcChar32 ucs4);
FcBool FcLangSetDel (FcLangSet *ls, const FcChar8 *lang);
FcLangSet *FcLangSetUnion (const FcLangSet *a, const FcLangSet *b);
FcLangSet *FcLangSetSubtract (const FcLangSet *a, const FcLangSet *b);

/* V53.2 */
FcBool FcDirCacheClean (const FcChar8 *cache_dir, FcBool verbose);
void FcCacheCreateTagFile (const FcConfig *config);
FcStrSet * FcGetDefaultLangs (void);

/* MorphOS extensions */
void FcExtInsertProgressCallback(FcExtProgressCallback call);
void FcExtRemoveProgressCallback(FcExtProgressCallback call);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

#endif /* FONTCONFIG_PROTOS_H */
