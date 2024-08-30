#ifndef CLIB_LOCALE_PROTOS_H
#define CLIB_LOCALE_PROTOS_H

/*
**    $Id: locale_protos.h,v 1.13 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef   LIBRARIES_LOCALE_H
#include <libraries/locale.h>
#endif
#ifndef   DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef   REXX_STORAGE_H
#include <rexx/storage.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */

/*--- functions in V38 or higher (Release 2.1) ---*/
VOID CloseCatalog( struct Catalog *catalog );
VOID CloseLocale( struct Locale *locale );
ULONG ConvToLower( struct Locale *locale, ULONG character );
ULONG ConvToUpper( struct Locale *locale, ULONG character );
VOID FormatDate( struct Locale *locale, CONST_STRPTR fmtTemplate, struct DateStamp *date, struct Hook *putCharFunc );
APTR FormatString( struct Locale *locale, CONST_STRPTR fmtTemplate, APTR dataStream, struct Hook *putCharFunc );
CONST_STRPTR GetCatalogStr( struct Catalog *catalog, LONG stringNum, CONST_STRPTR defaultString );
CONST_STRPTR GetLocaleStr( struct Locale *locale, ULONG stringNum );
LONG IsAlNum( struct Locale *locale, ULONG character );
LONG IsAlpha( struct Locale *locale, ULONG character );
LONG IsCntrl( struct Locale *locale, ULONG character );
LONG IsDigit( struct Locale *locale, ULONG character );
LONG IsGraph( struct Locale *locale, ULONG character );
LONG IsLower( struct Locale *locale, ULONG character );
LONG IsPrint( struct Locale *locale, ULONG character );
LONG IsPunct( struct Locale *locale, ULONG character );
LONG IsSpace( struct Locale *locale, ULONG character );
LONG IsUpper( struct Locale *locale, ULONG character );
LONG IsXDigit( struct Locale *locale, ULONG character );
struct Catalog *OpenCatalogA( struct Locale *locale, CONST_STRPTR name, struct TagItem *tags );
struct Catalog *OpenCatalog( struct Locale *locale, CONST_STRPTR name, Tag tag1, ... );
struct Locale *OpenLocale( CONST_STRPTR name );
LONG ParseDate( struct Locale *locale, struct DateStamp *date, CONST_STRPTR fmtTemplate, struct Hook *getCharFunc );
ULONG StrConvert( struct Locale *locale, CONST_STRPTR string, APTR buffer, ULONG bufferSize, ULONG type );
LONG StrnCmp( struct Locale *locale, CONST_STRPTR string1, CONST_STRPTR string2, LONG length, ULONG type );
/*--- functions in V50 or higher ---*/
LONG Locale_DateToStr( struct DateTime *datetime );
LONG Locale_StrToDate( struct DateTime *datetime );
/*--- functions in V51 or higher ---*/
LONG IsBlank( struct Locale *locale, ULONG character );
APTR FormatString32( struct Locale *locale, CONST_STRPTR fmtTemplate, APTR dataStream, struct Hook *putCharFunc );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_LOCALE_PROTOS_H */
