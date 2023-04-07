#ifndef PRAGMAS_LOCALE_PRAGMAS_H
#define PRAGMAS_LOCALE_PRAGMAS_H

/*
**	$VER: locale_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_LOCALE_PROTOS_H
#include <clib/locale_protos.h>
#endif /* CLIB_LOCALE_PROTOS_H */

/* "locale.library" */
/*--- functions in V38 or higher (Release 2.1) ---*/
/* ARexx function host entry point */
/* This function also returns a (struct RexxMsg *) in A1 */
#pragma libcall LocaleBase CloseCatalog 24 801
#pragma libcall LocaleBase CloseLocale 2a 801
#pragma libcall LocaleBase ConvToLower 30 0802
#pragma libcall LocaleBase ConvToUpper 36 0802
#pragma libcall LocaleBase FormatDate 3c BA9804
#pragma libcall LocaleBase FormatString 42 BA9804
#pragma libcall LocaleBase GetCatalogStr 48 90803
#pragma libcall LocaleBase GetLocaleStr 4e 0802
#pragma libcall LocaleBase IsAlNum 54 0802
#pragma libcall LocaleBase IsAlpha 5a 0802
#pragma libcall LocaleBase IsCntrl 60 0802
#pragma libcall LocaleBase IsDigit 66 0802
#pragma libcall LocaleBase IsGraph 6c 0802
#pragma libcall LocaleBase IsLower 72 0802
#pragma libcall LocaleBase IsPrint 78 0802
#pragma libcall LocaleBase IsPunct 7e 0802
#pragma libcall LocaleBase IsSpace 84 0802
#pragma libcall LocaleBase IsUpper 8a 0802
#pragma libcall LocaleBase IsXDigit 90 0802
#pragma libcall LocaleBase OpenCatalogA 96 A9803
#if defined(__SASC_60)
#pragma tagcall LocaleBase OpenCatalog 96 A9803
#endif /* __SASC_60 */
#pragma libcall LocaleBase OpenLocale 9c 801
#pragma libcall LocaleBase ParseDate a2 BA9804
#pragma libcall LocaleBase StrConvert ae 10A9805
#pragma libcall LocaleBase StrnCmp b4 10A9805

/* Reserved entries */


#endif /* PRAGMAS_LOCALE_PRAGMAS_H */
