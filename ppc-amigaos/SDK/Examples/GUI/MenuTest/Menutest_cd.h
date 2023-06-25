#ifndef MENUTEST_CD_H
#define MENUTEST_CD_H


/****************************************************************************/


/* This file was created automatically by CatComp.
 * Do NOT edit by hand!
 */


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef CATCOMP_CODE
#ifndef CATCOMP_BLOCK
#define CATCOMP_ARRAY
#endif
#endif

#ifdef CATCOMP_ARRAY
#ifndef CATCOMP_NUMBERS
#define CATCOMP_NUMBERS
#endif
#ifndef CATCOMP_STRINGS
#define CATCOMP_STRINGS
#endif
#endif

#ifdef CATCOMP_BLOCK
#ifndef CATCOMP_STRINGS
#define CATCOMP_STRINGS
#endif
#endif


/****************************************************************************/


#ifdef CATCOMP_NUMBERS

#define MSG_TITLE 0
#define MSG_ICON_TITLE 1
#define MSG_MENU_PROJECT 2
#define MSG_MENU_PROJECT_ABOUT 3
#define MSG_MENU_PROJECT_QUIT 4
#define MSG_MENU_EDIT 5
#define MSG_MENU_EDIT_UNDO 6
#define MSG_MENU_VIEW 7
#define MSG_MENU_VIEW_FUNCTIONS 8
#define MSG_MENU_VIEW_NUMERIC 9
#define MSG_MENU_VIEW_BASIC 10
#define MSG_MENU_VIEW_EXTENDED 11
#define MSG_ERROR_OPEN_LIBS 12
#define MSG_ERROR_MEMORY 13
#define MSG_OK_GAD 14

#endif /* CATCOMP_NUMBERS */


/****************************************************************************/


#ifdef CATCOMP_STRINGS

#define MSG_TITLE_STR "Menutest"
#define MSG_ICON_TITLE_STR "Menutest iconified"
#define MSG_MENU_PROJECT_STR "Project"
#define MSG_MENU_PROJECT_ABOUT_STR "?\0About..."
#define MSG_MENU_PROJECT_QUIT_STR "Q\0Quit"
#define MSG_MENU_EDIT_STR "Edit"
#define MSG_MENU_EDIT_UNDO_STR "Z\0Undo"
#define MSG_MENU_VIEW_STR "View"
#define MSG_MENU_VIEW_FUNCTIONS_STR "F\0Functions"
#define MSG_MENU_VIEW_NUMERIC_STR "N\0Numeric"
#define MSG_MENU_VIEW_BASIC_STR "B\0Basic"
#define MSG_MENU_VIEW_EXTENDED_STR "E\0Extended"
#define MSG_ERROR_OPEN_LIBS_STR "Can't open LIBS:%s, version %ld !"
#define MSG_ERROR_MEMORY_STR "Not enough memory !"
#define MSG_OK_GAD_STR "Ok"

#endif /* CATCOMP_STRINGS */


/****************************************************************************/


#ifdef CATCOMP_ARRAY

struct CatCompArrayType
{
    LONG         cca_ID;
    CONST_STRPTR cca_Str;
};

STATIC CONST struct CatCompArrayType CatCompArray[] =
{
    {MSG_TITLE,(CONST_STRPTR)MSG_TITLE_STR},
    {MSG_ICON_TITLE,(CONST_STRPTR)MSG_ICON_TITLE_STR},
    {MSG_MENU_PROJECT,(CONST_STRPTR)MSG_MENU_PROJECT_STR},
    {MSG_MENU_PROJECT_ABOUT,(CONST_STRPTR)MSG_MENU_PROJECT_ABOUT_STR},
    {MSG_MENU_PROJECT_QUIT,(CONST_STRPTR)MSG_MENU_PROJECT_QUIT_STR},
    {MSG_MENU_EDIT,(CONST_STRPTR)MSG_MENU_EDIT_STR},
    {MSG_MENU_EDIT_UNDO,(CONST_STRPTR)MSG_MENU_EDIT_UNDO_STR},
    {MSG_MENU_VIEW,(CONST_STRPTR)MSG_MENU_VIEW_STR},
    {MSG_MENU_VIEW_FUNCTIONS,(CONST_STRPTR)MSG_MENU_VIEW_FUNCTIONS_STR},
    {MSG_MENU_VIEW_NUMERIC,(CONST_STRPTR)MSG_MENU_VIEW_NUMERIC_STR},
    {MSG_MENU_VIEW_BASIC,(CONST_STRPTR)MSG_MENU_VIEW_BASIC_STR},
    {MSG_MENU_VIEW_EXTENDED,(CONST_STRPTR)MSG_MENU_VIEW_EXTENDED_STR},
    {MSG_ERROR_OPEN_LIBS,(CONST_STRPTR)MSG_ERROR_OPEN_LIBS_STR},
    {MSG_ERROR_MEMORY,(CONST_STRPTR)MSG_ERROR_MEMORY_STR},
    {MSG_OK_GAD,(CONST_STRPTR)MSG_OK_GAD_STR},
};

#endif /* CATCOMP_ARRAY */


/****************************************************************************/


#ifdef CATCOMP_BLOCK

STATIC CONST UBYTE CatCompBlock[] =
{
    "\x00\x00\x00\x00\x00\x0A"
    MSG_TITLE_STR "\x00\x00"
    "\x00\x00\x00\x01\x00\x14"
    MSG_ICON_TITLE_STR "\x00\x00"
    "\x00\x00\x00\x02\x00\x08"
    MSG_MENU_PROJECT_STR "\x00"
    "\x00\x00\x00\x03\x00\x0C"
    MSG_MENU_PROJECT_ABOUT_STR "\x00\x00"
    "\x00\x00\x00\x04\x00\x08"
    MSG_MENU_PROJECT_QUIT_STR "\x00\x00"
    "\x00\x00\x00\x05\x00\x06"
    MSG_MENU_EDIT_STR "\x00\x00"
    "\x00\x00\x00\x06\x00\x08"
    MSG_MENU_EDIT_UNDO_STR "\x00\x00"
    "\x00\x00\x00\x07\x00\x06"
    MSG_MENU_VIEW_STR "\x00\x00"
    "\x00\x00\x00\x08\x00\x0C"
    MSG_MENU_VIEW_FUNCTIONS_STR "\x00"
    "\x00\x00\x00\x09\x00\x0A"
    MSG_MENU_VIEW_NUMERIC_STR "\x00"
    "\x00\x00\x00\x0A\x00\x08"
    MSG_MENU_VIEW_BASIC_STR "\x00"
    "\x00\x00\x00\x0B\x00\x0C"
    MSG_MENU_VIEW_EXTENDED_STR "\x00\x00"
    "\x00\x00\x00\x0C\x00\x22"
    MSG_ERROR_OPEN_LIBS_STR "\x00"
    "\x00\x00\x00\x0D\x00\x14"
    MSG_ERROR_MEMORY_STR "\x00"
    "\x00\x00\x00\x0E\x00\x04"
    MSG_OK_GAD_STR "\x00\x00"
};

#endif /* CATCOMP_BLOCK */


/****************************************************************************/


#ifndef PROTO_LOCALE_H
 #ifndef __NOLIBBASE__
  #define _NLB_DEFINED_
  #define __NOLIBBASE__
 #endif
 #ifndef __NOGLOBALIFACE__
  #define _NGI_DEFINED_
  #define __NOGLOBALIFACE__
 #endif
 #include <proto/locale.h>
 #ifdef _NLB_DEFINED_
  #undef __NOLIBBASE__
  #undef _NLB_DEFINED_
 #endif
 #ifdef _NGI_DEFINED_
  #undef __NOGLOBALIFACE__
  #undef _NGI_DEFINED_
 #endif
#endif

struct LocaleInfo
{
#ifndef __amigaos4__
    struct Library     *li_LocaleBase;
#else
    struct LocaleIFace *li_ILocale;
#endif
    struct Catalog     *li_Catalog;
};


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CONST_STRPTR GetString(struct LocaleInfo *li, LONG stringNum);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#ifdef CATCOMP_CODE

CONST_STRPTR GetString(struct LocaleInfo *li, LONG stringNum)
{
#ifndef __amigaos4__
    struct Library     *LocaleBase = li->li_LocaleBase;
#else
    struct LocaleIFace *ILocale    = li->li_ILocale;
#endif
    LONG         *l;
    UWORD        *w;
    CONST_STRPTR  builtIn = NULL;

    l = (LONG *)CatCompBlock;

    while (*l != stringNum && l < (LONG *)(&CatCompBlock[sizeof(CatCompBlock)]))
    {
        w = (UWORD *)((ULONG)l + 4);
        l = (LONG *)((ULONG)l + (ULONG)*w + 6);
    }
    if (*l == stringNum)
    {
        builtIn = (CONST_STRPTR)((ULONG)l + 6);
    }

#ifndef __amigaos4__
    if (LocaleBase)
    {
        return GetCatalogStr(li->li_Catalog, stringNum, builtIn);
    }
#else
    if (ILocale)
    {
#ifdef __USE_INLINE__
        return GetCatalogStr(li->li_Catalog, stringNum, builtIn);
#else
        return ILocale->GetCatalogStr(li->li_Catalog, stringNum, builtIn);
#endif
    }
#endif
    return builtIn;
}


#endif /* CATCOMP_CODE */


/****************************************************************************/


#endif /* MENUTEST_CD_H */
