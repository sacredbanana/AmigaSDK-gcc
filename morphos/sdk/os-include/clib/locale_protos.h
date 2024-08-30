#ifndef CLIB_LOCALE_PROTOS_H
#define CLIB_LOCALE_PROTOS_H

/*
	locale.library C prototypes

	Copyright © 2002-2018 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_LOCALE_H
# include <libraries/locale.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef REXX_STORAGE_H
# include <rexx/storage.h>
#endif

#ifndef UTILITY_DATE_H
# include <utility/date.h>
#endif

#ifndef _SYS_TYPES_H_
# include <sys/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

VOID CloseCatalog( CONST struct Catalog *catalog );
VOID CloseLocale( CONST struct Locale *locale );
ULONG ConvToLower( CONST struct Locale *locale, ULONG character );
ULONG ConvToUpper( CONST struct Locale *locale, ULONG character );
VOID FormatDate( CONST struct Locale *locale, CONST_STRPTR fmtTemplate, CONST struct DateStamp *date, CONST struct Hook *putCharFunc );
APTR FormatString( CONST struct Locale *locale, CONST_STRPTR fmtTemplate, CONST_APTR dataStream, CONST struct Hook *putCharFunc );
STRPTR GetCatalogStr( CONST struct Catalog *catalog, LONG stringNum, CONST_STRPTR defaultString );
STRPTR GetLocaleStr( CONST struct Locale *locale, ULONG stringNum );
BOOL IsAlNum( CONST struct Locale *locale, ULONG character );
BOOL IsAlpha( CONST struct Locale *locale, ULONG character );
BOOL IsCntrl( CONST struct Locale *locale, ULONG character );
BOOL IsDigit( CONST struct Locale *locale, ULONG character );
BOOL IsGraph( CONST struct Locale *locale, ULONG character );
BOOL IsLower( CONST struct Locale *locale, ULONG character );
BOOL IsPrint( CONST struct Locale *locale, ULONG character );
BOOL IsPunct( CONST struct Locale *locale, ULONG character );
BOOL IsSpace( CONST struct Locale *locale, ULONG character );
BOOL IsUpper( CONST struct Locale *locale, ULONG character );
BOOL IsXDigit( CONST struct Locale *locale, ULONG character );
struct Catalog *OpenCatalogA( CONST struct Locale *locale, CONST_STRPTR name, CONST struct TagItem *tags );
#if !defined(USE_INLINE_STDARG)
struct Catalog *OpenCatalog( CONST struct Locale *locale, CONST_STRPTR name, Tag tag1, ... );
#endif
struct Locale *OpenLocale( CONST_STRPTR name );
BOOL ParseDate( CONST struct Locale *locale, CONST struct DateStamp *date, CONST_STRPTR fmtTemplate, CONST struct Hook *getCharFunc );
ULONG StrConvert( CONST struct Locale *locale, CONST_STRPTR string, APTR buffer, ULONG bufferSize, ULONG type );
LONG StrnCmp( CONST struct Locale *locale, CONST_STRPTR string1, CONST_STRPTR string2, LONG length, ULONG type );
WCHAR UCS4_ConvToLower(WCHAR ucharacter);
WCHAR UCS4_ConvToUpper(WCHAR ucharacter);
ULONG UTF8_Decode(CONST_STRPTR utf8, WCHAR *ucharacter);
ULONG UTF8_Encode(WCHAR ucharacter, STRPTR string);
CONST_WSTRPTR UCS4_GetCatalogStr(CONST struct Catalog *catalog, ULONG stringNum, CONST_WSTRPTR defaultString);
BOOL UCS4_IsAlNum( WCHAR ucharacter );
BOOL UCS4_IsAlpha( WCHAR ucharacter );
BOOL UCS4_IsCntrl( WCHAR ucharacter );
BOOL UCS4_IsDigit( WCHAR ucharacter );
BOOL UCS4_IsGraph( WCHAR ucharacter );
BOOL UCS4_IsLower( WCHAR ucharacter );
BOOL UCS4_IsPrint( WCHAR ucharacter );
BOOL UCS4_IsPunct( WCHAR ucharacter );
BOOL UCS4_IsSpace( WCHAR ucharacter );
BOOL UCS4_IsUpper( WCHAR ucharacter );
BOOL UCS4_IsXDigit( WCHAR ucharacter );
VOID UCS4_FormatDate( CONST struct Locale *locale, CONST_WSTRPTR formatString, CONST struct DateStamp *date, CONST struct Hook *hook );
APTR UCS4_FormatString( CONST struct Locale *locale, CONST_WSTRPTR fmtTemplate, CONST_APTR dataStream, CONST struct Hook *putCharFunc );
CONST_WSTRPTR UCS4_GetLocaleStr( CONST struct Locale *locale, ULONG stringNum );
LONG UCS4_StrnCmp( CONST struct Locale *locale, CONST_WSTRPTR string1, CONST_WSTRPTR string2, LONG length, ULONG type );
LONG UCS4_StrToLower( CONST struct Locale *locale, CONST_WSTRPTR string, WSTRPTR buffer, ULONG bufferSize, ULONG type );
LONG UCS4_StrToUpper( CONST struct Locale *locale, CONST_WSTRPTR string, WSTRPTR buffer, ULONG bufferSize, ULONG type );
CONST_WSTRPTR UCS4_Decompose( WCHAR ch );
BOOL UCS4_IsNSM( WCHAR ucharacter );
VOID UCS4_Normalize( CONST_WSTRPTR src, WSTRPTR dst, LONG length, ULONG type );
CONST_WSTRPTR UCS4_CanonicalDecompose( WCHAR ch);
ULONG ConvertUTF8ToUCS4( CONST_STRPTR src, WSTRPTR dst, LONG length );
ULONG ConvertUCS4ToUTF8( CONST_WSTRPTR src, STRPTR dst, LONG length );
ULONG UCS4_IsCombining( WCHAR ucharacter );
LONG UCS4_Compare( CONST struct Locale *locale, CONST_WSTRPTR string1, CONST_WSTRPTR string2, LONG length, ULONG flags );
ULONG UCS4_GetCombiningClass( WCHAR ucharacter );
ULONG UCS4_NormalizedLength( CONST_WSTRPTR string, LONG length, ULONG type );
LONG UTF8_CheckEncoding(CONST_STRPTR string, LONG length);
ULONG IsUnicode(APTR buffer, ULONG length);

VOID UCS4_FormatClockData(CONST struct Locale *locale, CONST_WSTRPTR formatString, CONST struct ClockData *cData, CONST struct Hook *hook);
ssize_t VSNPrintf(CONST struct Locale *locale, STRPTR buffer, ssize_t bufferSize, CONST_STRPTR fmtTemplate, va_list args);
ssize_t SNPrintf(CONST struct Locale *locale, STRPTR buffer, ssize_t bufferSize, CONST_STRPTR fmtTemplate, ...);

struct tm;
ULONG TZGetSysLocalTime(ULONG utctime, CONST_STRPTR timezone);
APTR TZAlloc(CONST_STRPTR timezone);
VOID TZFree(APTR sp);
struct tm *TZLocalTime(APTR sp, ULONG t, struct tm *tmp);
ULONG TZMKTime(APTR sp, struct tm *tm);
ULONG TZTime2Posix(APTR sp, ULONG t);
ULONG TZPosix2Time(APTR sp, ULONG t);
STRPTR TZAscTime(const struct tm *tm, STRPTR buf);
STRPTR TZCTime(ULONG t, STRPTR buf);
struct tm *TZGMTime(ULONG t, struct tm *tm);
LONG TZGetSysTimeZone(STRPTR buf, LONG size);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_LOCALE_PROTOS_H */
