#ifndef LIBRARIES_LOCALE_H
#define LIBRARIES_LOCALE_H

/*
	locale.library include

	Copyright © 2002-2010 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


#define DAY_1         1
#define DAY_2         2
#define DAY_3         3
#define DAY_4         4
#define DAY_5         5
#define DAY_6         6
#define DAY_7         7

#define ABDAY_1       8
#define ABDAY_2       9
#define ABDAY_3       10
#define ABDAY_4       11
#define ABDAY_5       12
#define ABDAY_6       13
#define ABDAY_7       14

#define MON_1         15
#define MON_2         16
#define MON_3         17
#define MON_4         18
#define MON_5         19
#define MON_6         20
#define MON_7         21
#define MON_8         22
#define MON_9         23
#define MON_10        24
#define MON_11        25
#define MON_12        26

#define ABMON_1       27
#define ABMON_2       28
#define ABMON_3       29
#define ABMON_4       30
#define ABMON_5       31
#define ABMON_6       32
#define ABMON_7       33
#define ABMON_8       34
#define ABMON_9       35
#define ABMON_10      36
#define ABMON_11      37
#define ABMON_12      38

#define YESSTR        39
#define NOSTR         40

#define AM_STR        41
#define PM_STR        42

#define SOFTHYPHEN    43
#define HARDHYPHEN    44

#define OPENQUOTE     45
#define CLOSEQUOTE    46

#define YESTERDAYSTR  47
#define TODAYSTR      48
#define TOMORROWSTR   49
#define FUTURESTR     50

#define MAXSTRMSG     51


struct LocaleBase
{
	struct Library lb_LibNode;
	BOOL           lb_SysPatches;
};


struct Locale
{
	STRPTR  loc_LocaleName;
	STRPTR  loc_LanguageName;
	STRPTR  loc_PrefLanguages[10];
	ULONG   loc_Flags;

	ULONG   loc_CodeSet;
	ULONG   loc_CountryCode;
	ULONG   loc_TelephoneCode;
	LONG    loc_GMTOffset;
	UBYTE   loc_MeasuringSystem;
	UBYTE   loc_CalendarType;
	UBYTE   loc_Reserved0[2];

	STRPTR  loc_DateTimeFormat;
	STRPTR  loc_DateFormat;
	STRPTR  loc_TimeFormat;

	STRPTR  loc_ShortDateTimeFormat;
	STRPTR  loc_ShortDateFormat;
	STRPTR  loc_ShortTimeFormat;

	STRPTR  loc_DecimalPoint;
	STRPTR  loc_GroupSeparator;
	STRPTR  loc_FracGroupSeparator;
	UBYTE  *loc_Grouping;
	UBYTE  *loc_FracGrouping;

	STRPTR  loc_MonDecimalPoint;
	STRPTR  loc_MonGroupSeparator;
	STRPTR  loc_MonFracGroupSeparator;
	UBYTE  *loc_MonGrouping;
	UBYTE  *loc_MonFracGrouping;
	UBYTE   loc_MonFracDigits;
	UBYTE   loc_MonIntFracDigits;
	UBYTE   loc_Reserved1[2];

	STRPTR  loc_MonCS;
	STRPTR  loc_MonSmallCS;
	STRPTR  loc_MonIntCS;

	STRPTR  loc_MonPositiveSign;
	UBYTE   loc_MonPositiveSpaceSep;
	UBYTE   loc_MonPositiveSignPos;
	UBYTE   loc_MonPositiveCSPos;
	UBYTE   loc_Reserved2;

	STRPTR  loc_MonNegativeSign;
	UBYTE   loc_MonNegativeSpaceSep;
	UBYTE   loc_MonNegativeSignPos;
	UBYTE   loc_MonNegativeCSPos;
	UBYTE   loc_Reserved3;
};


#define MS_ISO       0
#define MS_AMERICAN  1
#define MS_IMPERIAL  2
#define MS_BRITISH   3


#define CT_7SUN  0
#define CT_7MON  1
#define CT_7TUE  2
#define CT_7WED  3
#define CT_7THU  4
#define CT_7FRI  5
#define CT_7SAT  6


#define SS_NOSPACE  0
#define SS_SPACE    1


#define SP_PARENS     0
#define SP_PREC_ALL   1
#define SP_SUCC_ALL   2
#define SP_PREC_CURR  3
#define SP_SUCC_CURR  4


#define CSP_PRECEDES  0
#define CSP_SUCCEEDS  1


#define OC_TagBase          (TAG_USER + 0x90000)
#define OC_BuiltInLanguage  (OC_TagBase + 1)
#define OC_BuiltInCodeSet   (OC_TagBase + 2)
#define OC_Version          (OC_TagBase + 3)
#define OC_Language         (OC_TagBase + 4)
#define OC_CodeSet          (OC_TagBase + 5)   /* V51 */
#define OC_BuiltInStrings   (OC_TagBase + 6)   /* V52.3 */
#define OC_ConvertStrings   (OC_TagBase + 7)   /* V53.9, defaults to TRUE. If FALSE, no string conversion will be performed */


#define SC_ASCII     0
#define SC_COLLATE1  1
#define SC_COLLATE2  2

#define SC_UNICODE   SC_ASCII

#define UCF_IGNORE_CASE (1 << 0)



#define UNICODE_NFD 0
#define UNICODE_NFKD 1

struct Catalog
{
	struct Node cat_Link;
	UWORD       cat_Pad;
	STRPTR      cat_Language;
	ULONG       cat_CodeSet;
	UWORD       cat_Version;
	UWORD       cat_Revision;
};


/*
   Parameter to OC_BuiltInStrings tags.
*/

struct BuiltInStrings
{
	LONG       Type;  /* Type of data */
	LONG       Size;  /* Size of data in bytes */
	CONST_APTR Data;  /* Pointer to data */
};

#define TYPE_CATCOMP_ARRAY 0
#define TYPE_CATCOMP_BLOCK 1


/*
   cat_CodeSet values
*/

#define CODESET_LEGACY  0
#define CODESET_UTF8    1
#define CODESET_UTF32   2
#define CODESET_COUNT   3

#define CODESET_LATIN1  CODESET_LEGACY
#define CODESET_UCS4    CODESET_UTF32



/*
   Values returned by IsUnicode()
*/

#define UNICODE_INVALID 0 /* ASCII or ISO-8859-1 */
#define UNICODE_UTF8    1 /* UTF-8 */
#define UNICODE_16_BE   2 /* UCS-2/UTF-16 big endian */
#define UNICODE_16_LE   3 /* UCS-2/UTF-16 little endian */
#define UNICODE_32_BE   4 /* UCS-4/UTF-32 big endian */
#define UNICODE_32_LE   5 /* UCS-4/UTF-32 little endian */

#pragma pack()

#endif /* LIBRARIES_LOCALE_H */
