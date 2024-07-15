#ifndef CLIB_LOCALE_PROTOS_H
#define CLIB_LOCALE_PROTOS_H

/*
**	$VER: locale_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  LIBRARIES_LOCALE_H
#include <libraries/locale.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif
/*--- functions in V38 or higher (Release 2.1) ---*/
VOID  __stdargs CloseCatalog( struct Catalog *catalog );
VOID  __stdargs CloseLocale( struct Locale *locale );
ULONG  __stdargs ConvToLower( struct Locale *locale, ULONG character );
ULONG  __stdargs ConvToUpper( struct Locale *locale, ULONG character );
VOID  __stdargs FormatDate( struct Locale *locale, CONST_STRPTR fmtTemplate, CONST struct DateStamp *date, struct Hook *putCharFunc );
APTR  __stdargs FormatString( struct Locale *locale, CONST_STRPTR fmtTemplate, APTR dataStream, struct Hook *putCharFunc );
STRPTR  __stdargs GetCatalogStr( CONST struct Catalog *catalog, LONG stringNum, CONST_STRPTR defaultString );
STRPTR  __stdargs GetLocaleStr( struct Locale *locale, ULONG stringNum );
BOOL  __stdargs IsAlNum( struct Locale *locale, ULONG character );
BOOL  __stdargs IsAlpha( struct Locale *locale, ULONG character );
BOOL  __stdargs IsCntrl( struct Locale *locale, ULONG character );
BOOL  __stdargs IsDigit( struct Locale *locale, ULONG character );
BOOL  __stdargs IsGraph( struct Locale *locale, ULONG character );
BOOL  __stdargs IsLower( struct Locale *locale, ULONG character );
BOOL  __stdargs IsPrint( struct Locale *locale, ULONG character );
BOOL  __stdargs IsPunct( struct Locale *locale, ULONG character );
BOOL  __stdargs IsSpace( struct Locale *locale, ULONG character );
BOOL  __stdargs IsUpper( struct Locale *locale, ULONG character );
BOOL  __stdargs IsXDigit( struct Locale *locale, ULONG character );
struct Catalog * __stdargs OpenCatalogA( struct Locale *locale, CONST_STRPTR name, CONST struct TagItem *tags );
struct Catalog * __stdargs OpenCatalog( struct Locale *locale, CONST_STRPTR name, ... );
struct Locale * __stdargs OpenLocale( CONST_STRPTR name );
BOOL  __stdargs ParseDate( CONST struct Locale *locale, struct DateStamp *date, CONST_STRPTR fmtTemplate, struct Hook *getCharFunc );
ULONG  __stdargs StrConvert( struct Locale *locale, CONST_STRPTR string, APTR buffer, ULONG bufferSize, ULONG type );
LONG  __stdargs StrnCmp( struct Locale *locale, CONST_STRPTR string1, CONST_STRPTR string2, LONG length, ULONG type );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_LOCALE_PROTOS_H */
