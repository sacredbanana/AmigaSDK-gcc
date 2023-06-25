#ifndef LIBRARIES_LOCALE_H
#define LIBRARIES_LOCALE_H
/*
**    $VER: locale.h 54.16 (22.08.2022)
**
**    locale.library interface structures and definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef   EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef   DOS_DATETIME_H
#include <dos/datetime.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/*****************************************************************************/

/* constants for GetLocaleStr() */
#define LANG_CODE     0 /* ISO-639-2/T 3-letter lowercase language   */
                        /* code (e.g. "eng"). Added in V50. Caution: */
                        /* All known old language drivers return a   */
                        /* pointer to an empty string (""). The code */
                        /* can e.g. be used as ID to get the         */
                        /* localized language name from              */
                        /* sys/languages.catalog ($656e6700 = "eng") */

#define DAY_1         1 /* Sunday    */
#define DAY_2         2 /* Monday    */
#define DAY_3         3 /* Tuesday   */
#define DAY_4         4 /* Wednesday */
#define DAY_5         5 /* Thursday  */
#define DAY_6         6 /* Friday    */
#define DAY_7         7 /* Saturday  */

#define ABDAY_1       8 /* Sun */
#define ABDAY_2       9 /* Mon */
#define ABDAY_3      10 /* Tue */
#define ABDAY_4      11 /* Wed */
#define ABDAY_5      12 /* Thu */
#define ABDAY_6      13 /* Fri */
#define ABDAY_7      14 /* Sat */

#define MON_1        15 /* January   */
#define MON_2        16 /* February  */
#define MON_3        17 /* March     */
#define MON_4        18 /* April     */
#define MON_5        19 /* May       */
#define MON_6        20 /* June      */
#define MON_7        21 /* July      */
#define MON_8        22 /* August    */
#define MON_9        23 /* September */
#define MON_10       24 /* October   */
#define MON_11       25 /* November  */
#define MON_12       26 /* December  */

#define ABMON_1      27 /* Jan */
#define ABMON_2      28 /* Feb */
#define ABMON_3      29 /* Mar */
#define ABMON_4      30 /* Apr */
#define ABMON_5      31 /* May */
#define ABMON_6      32 /* Jun */
#define ABMON_7      33 /* Jul */
#define ABMON_8      34 /* Aug */
#define ABMON_9      35 /* Sep */
#define ABMON_10     36 /* Oct */
#define ABMON_11     37 /* Nov */
#define ABMON_12     38 /* Dec */

#define YESSTR       39 /* affirmative response for yes/no queries */
#define NOSTR        40 /* negative response for yes/no queries    */

#define AM_STR       41 /* AM */
#define PM_STR       42 /* PM */

#define SOFTHYPHEN   43 /* soft hyphenation */
#define HARDHYPHEN   44 /* hard hyphenation */

#define OPENQUOTE    45 /* start of quoted block */
#define CLOSEQUOTE   46 /* end of quoted block   */

#define YESTERDAYSTR 47 /* Yesterday */
#define TODAYSTR     48 /* Today     */
#define TOMORROWSTR  49 /* Tomorrow  */
#define FUTURESTR    50 /* Future    */

#define LANG_NAME    51 /* native name of this language */
                        /* in this language and charset. */
                        /* Added in V50. */

/* Added in V50: Alternate forms of weekday names to be used
 * in date strings, some languages need those. Fallback are
 * the normal weekday names for standalone usage. */
#define ALTDAY_1     52 /* Sunday    */
#define ALTDAY_2     53 /* Monday    */
#define ALTDAY_3     54 /* Tuesday   */
#define ALTDAY_4     55 /* Wednesday */
#define ALTDAY_5     56 /* Thursday  */
#define ALTDAY_6     57 /* Friday    */
#define ALTDAY_7     58 /* Saturday  */

/* Added in V50: Alternate forms of month names to be used
 * in date strings, some languages need those. Fallback are
 * the normal month names for standalone usage. */
#define ALTMON_1     59 /* January   */
#define ALTMON_2     60 /* February  */
#define ALTMON_3     61 /* March     */
#define ALTMON_4     62 /* April     */
#define ALTMON_5     63 /* May       */
#define ALTMON_6     64 /* June      */
#define ALTMON_7     65 /* July      */
#define ALTMON_8     66 /* August    */
#define ALTMON_9     67 /* September */
#define ALTMON_10    68 /* October   */
#define ALTMON_11    69 /* November  */
#define ALTMON_12    70 /* December  */

#define MAXSTRMSG    71 /* current number of defined strings */

/*****************************************************************************/

/* This structure must only be allocated by locale.library and is READ-ONLY! */
struct Locale
{
    STRPTR  loc_LocaleName;           /* locale's name               */
    STRPTR  loc_LanguageName;         /* language of this locale     */
    STRPTR  loc_PrefLanguages[10];    /* preferred languages         */
    uint32  loc_Flags;                /* always 0 for now            */

    uint32  loc_CodeSet;              /* IANA charset number, see    */
                                      /* L:CharSets/character-sets,  */
                                      /* used for diskfont.library   */
                                      /* V50+ default charset        */
    uint32  loc_CountryCode;          /* user's country code         */
                                      /* This is in fact an uint8[4] */
                                      /* New .country files should   */
                                      /* use ISO-3166 Alpha 3 names  */
                                      /* The code can e.g. be used   */
                                      /* as ID to get the localized  */
                                      /* country name from           */
                                      /* sys/countries.catalog       */
                                      /* ($55534100 for "USA").      */
    uint32  loc_TelephoneCode;        /* country's telephone code    */
    int32   loc_GMTOffset;            /* minutes from GMT            */
    uint8   loc_MeasuringSystem;      /* what measuring system?      */
    uint8   loc_CalendarType;         /* what calendar type?         */
    uint8   loc_Reserved0[2];

    STRPTR  loc_DateTimeFormat;       /* regular date & time format  */
    STRPTR  loc_DateFormat;           /* date format by itself       */
    STRPTR  loc_TimeFormat;           /* time format by itself       */

    STRPTR  loc_ShortDateTimeFormat;  /* short date & time format    */
    STRPTR  loc_ShortDateFormat;      /* short date format by itself */
    STRPTR  loc_ShortTimeFormat;      /* short time format by itself */

    /* for numeric values */
    STRPTR  loc_DecimalPoint;         /* character before the decimals */
    STRPTR  loc_GroupSeparator;       /* separates groups of digits    */
    STRPTR  loc_FracGroupSeparator;   /* separates groups of digits    */
    uint8  *loc_Grouping;             /* size of each group            */
    uint8  *loc_FracGrouping;         /* size of each group            */

    /* for monetary values */
    STRPTR  loc_MonDecimalPoint;
    STRPTR  loc_MonGroupSeparator;
    STRPTR  loc_MonFracGroupSeparator;
    uint8  *loc_MonGrouping;
    uint8  *loc_MonFracGrouping;
    uint8   loc_MonFracDigits;        /* digits after the decimal point   */
    uint8   loc_MonIntFracDigits;     /* for international representation */
    uint8   loc_Reserved1[2];

    /* for currency symbols */
    STRPTR  loc_MonCS;                /* currency symbol               */
    STRPTR  loc_MonSmallCS;           /* symbol for small amounts      */
    STRPTR  loc_MonIntCS;             /* international (ISO 4217) code */
                                      /* and international separator   */

    /* for positive monetary values */
    STRPTR  loc_MonPositiveSign;      /* indicate positive money value   */
    uint8   loc_MonPositiveSpaceSep;  /* determine if separated by space */
    uint8   loc_MonPositiveSignPos;   /* position of positive sign       */
    uint8   loc_MonPositiveCSPos;     /* position of currency symbol     */
    uint8   loc_Reserved2;

    /* for negative monetary values */
    STRPTR  loc_MonNegativeSign;      /* indicate negative money value   */
    uint8   loc_MonNegativeSpaceSep;  /* determine if separated by space */
    uint8   loc_MonNegativeSignPos;   /* position of negative sign       */
    uint8   loc_MonNegativeCSPos;     /* position of currency symbol     */
    uint8   loc_Reserved3;
};

/* constants for Locale.loc_MeasuringSystem */
#define MS_ISO      0 /* international metric system */
#define MS_AMERICAN 1 /* american system             */
#define MS_IMPERIAL 2 /* imperial system             */
#define MS_BRITISH  3 /* british system              */

/* constants for Locale.loc_CalendarType */
#define CT_7SUN  0 /* 7 days a week, Sunday is the first day    */
#define CT_7MON  1 /* 7 days a week, Monday is the first day    */
#define CT_7TUE  2 /* 7 days a week, Tuesday is the first day   */
#define CT_7WED  3 /* 7 days a week, Wednesday is the first day */
#define CT_7THU  4 /* 7 days a week, Thursday is the first day  */
#define CT_7FRI  5 /* 7 days a week, Friday is the first day    */
#define CT_7SAT  6 /* 7 days a week, Saturday is the first day  */

/* constants for Locale.loc_MonPositiveSpaceSep and
 *               Locale.loc_MonNegativeSpaceSep
 */
#define SS_NOSPACE 0 /* cur. symbol is NOT separated from value with a space */
#define SS_SPACE   1 /* cur. symbol IS separated from value with a space     */

/* constants for Locale.loc_MonPositiveSignPos and
 *               Locale.loc_MonNegativeSignPos
 */
#define SP_PARENS    0 /* () surround the quantity and currency_symbol   */
#define SP_PREC_ALL  1 /* sign string comes before amount and symbol     */
#define SP_SUCC_ALL  2 /* sign string comes after amount and symbol      */
#define SP_PREC_CURR 3 /* sign string comes right before currency symbol */
#define SP_SUCC_CURR 4 /* sign string comes right after currency symbol  */

/* constants for Locale.loc_MonPositiveCSPos and
 *               Locale.loc_MonNegativeCSPos
 */
#define CSP_PRECEDES 0 /* currency symbol comes before value */
#define CSP_SUCCEEDS 1 /* currency symbol comes after value  */

/* elements of the byte arrays pointed to by:
 *   Locale.loc_Grouping
 *   Locale.loc_FracGrouping
 *   Locale.loc_MonGrouping
 *   Locale.loc_MonFracGrouping
 * are interpreted as follows:
 *
 *    255     indicates that no further grouping is to be performed
 *    0       indicates that the previous element is to be repeatedly used
 *            for the remainder of the digits
 *    <other> the number of digits that comprises the current group
 */

/*****************************************************************************/

/* Tags for OpenCatalog() */
#define OC_TagBase         (TAG_USER + 0x90000)
#define OC_BuiltInLanguage OC_TagBase+1 /* language of builtin strings       */
#define OC_BuiltInCodeSet  OC_TagBase+2 /* code set of builtin strings       */
#define OC_Version         OC_TagBase+3 /* catalog version number required   */
#define OC_Language        OC_TagBase+4 /* preferred language of catalog     */
#define OC_WantedCodeSet   OC_TagBase+5 /* code set of font to be used (V50) */
#define OC_BuiltInVersion  OC_TagBase+6 /* version of builtin strings (V52.3)*/
#define OC_PreferExternal  OC_TagBase+7 /* replace builtin language? (V53.4) */

/*****************************************************************************/

/* Comparison types for StrnCmp() */
#define SC_ASCII    0
#define SC_COLLATE1 1
#define SC_COLLATE2 2

/*****************************************************************************/

/* This structure must only be allocated by locale.library and is READ-ONLY! */
struct Catalog
{
    struct Node cat_Link;     /* for internal linkage      */
    uint16      cat_Pad;      /* to longword align         */
    STRPTR      cat_Language; /* language of the catalog   */
    uint32      cat_CodeSet;  /* IANA charset number, see  */
                              /* L:CharSets/character-sets */
    uint16      cat_Version;  /* version of the catalog    */
    uint16      cat_Revision; /* revision of the catalog   */
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/*****************************************************************************/

#endif /* LIBRARIES_LOCALE_H */
