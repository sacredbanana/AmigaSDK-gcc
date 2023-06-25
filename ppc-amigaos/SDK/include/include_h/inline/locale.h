#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_LOCALE_H
#define _INLINE_LOCALE_H

#ifndef CLIB_LOCALE_PROTOS_H
#define CLIB_LOCALE_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
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

#ifndef LOCALE_BASE_NAME
#define LOCALE_BASE_NAME LocaleBase
#endif

#define CloseCatalog(catalog) ({ \
  struct Catalog * _CloseCatalog_catalog = (catalog); \
  { \
  register struct Library * const __CloseCatalog__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register struct Catalog * __CloseCatalog_catalog __asm("a0") = (_CloseCatalog_catalog); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__CloseCatalog__bn), "r"(__CloseCatalog_catalog) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CloseLocale(locale) ({ \
  struct Locale * _CloseLocale_locale = (locale); \
  { \
  register struct Library * const __CloseLocale__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register struct Locale * __CloseLocale_locale __asm("a0") = (_CloseLocale_locale); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__CloseLocale__bn), "r"(__CloseLocale_locale) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ConvToLower(locale, character) ({ \
  struct Locale * _ConvToLower_locale = (locale); \
  ULONG _ConvToLower_character = (character); \
  ULONG _ConvToLower__re = \
  ({ \
  register struct Library * const __ConvToLower__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register ULONG __ConvToLower__re __asm("d0"); \
  register struct Locale * __ConvToLower_locale __asm("a0") = (_ConvToLower_locale); \
  register ULONG __ConvToLower_character __asm("d0") = (_ConvToLower_character); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__ConvToLower__re) \
  : "r"(__ConvToLower__bn), "r"(__ConvToLower_locale), "r"(__ConvToLower_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ConvToLower__re; \
  }); \
  _ConvToLower__re; \
})

#define ConvToUpper(locale, character) ({ \
  struct Locale * _ConvToUpper_locale = (locale); \
  ULONG _ConvToUpper_character = (character); \
  ULONG _ConvToUpper__re = \
  ({ \
  register struct Library * const __ConvToUpper__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register ULONG __ConvToUpper__re __asm("d0"); \
  register struct Locale * __ConvToUpper_locale __asm("a0") = (_ConvToUpper_locale); \
  register ULONG __ConvToUpper_character __asm("d0") = (_ConvToUpper_character); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__ConvToUpper__re) \
  : "r"(__ConvToUpper__bn), "r"(__ConvToUpper_locale), "r"(__ConvToUpper_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ConvToUpper__re; \
  }); \
  _ConvToUpper__re; \
})

#define FormatDate(locale, fmtTemplate, date, putCharFunc) ({ \
  struct Locale * _FormatDate_locale = (locale); \
  CONST_STRPTR _FormatDate_fmtTemplate = (fmtTemplate); \
  struct DateStamp * _FormatDate_date = (date); \
  struct Hook * _FormatDate_putCharFunc = (putCharFunc); \
  { \
  register struct Library * const __FormatDate__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register struct Locale * __FormatDate_locale __asm("a0") = (_FormatDate_locale); \
  register CONST_STRPTR __FormatDate_fmtTemplate __asm("a1") = (_FormatDate_fmtTemplate); \
  register struct DateStamp * __FormatDate_date __asm("a2") = (_FormatDate_date); \
  register struct Hook * __FormatDate_putCharFunc __asm("a3") = (_FormatDate_putCharFunc); \
  __asm volatile ("jsr a6@(-60:W)" \
  : \
  : "r"(__FormatDate__bn), "r"(__FormatDate_locale), "r"(__FormatDate_fmtTemplate), "r"(__FormatDate_date), "r"(__FormatDate_putCharFunc) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FormatString(locale, fmtTemplate, dataStream, putCharFunc) ({ \
  struct Locale * _FormatString_locale = (locale); \
  CONST_STRPTR _FormatString_fmtTemplate = (fmtTemplate); \
  APTR _FormatString_dataStream = (dataStream); \
  struct Hook * _FormatString_putCharFunc = (putCharFunc); \
  APTR _FormatString__re = \
  ({ \
  register struct Library * const __FormatString__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register APTR __FormatString__re __asm("d0"); \
  register struct Locale * __FormatString_locale __asm("a0") = (_FormatString_locale); \
  register CONST_STRPTR __FormatString_fmtTemplate __asm("a1") = (_FormatString_fmtTemplate); \
  register APTR __FormatString_dataStream __asm("a2") = (_FormatString_dataStream); \
  register struct Hook * __FormatString_putCharFunc __asm("a3") = (_FormatString_putCharFunc); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__FormatString__re) \
  : "r"(__FormatString__bn), "r"(__FormatString_locale), "r"(__FormatString_fmtTemplate), "r"(__FormatString_dataStream), "r"(__FormatString_putCharFunc) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FormatString__re; \
  }); \
  _FormatString__re; \
})

#define GetCatalogStr(catalog, stringNum, defaultString) ({ \
  struct Catalog * _GetCatalogStr_catalog = (catalog); \
  LONG _GetCatalogStr_stringNum = (stringNum); \
  CONST_STRPTR _GetCatalogStr_defaultString = (defaultString); \
  CONST_STRPTR _GetCatalogStr__re = \
  ({ \
  register struct Library * const __GetCatalogStr__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register CONST_STRPTR __GetCatalogStr__re __asm("d0"); \
  register struct Catalog * __GetCatalogStr_catalog __asm("a0") = (_GetCatalogStr_catalog); \
  register LONG __GetCatalogStr_stringNum __asm("d0") = (_GetCatalogStr_stringNum); \
  register CONST_STRPTR __GetCatalogStr_defaultString __asm("a1") = (_GetCatalogStr_defaultString); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__GetCatalogStr__re) \
  : "r"(__GetCatalogStr__bn), "r"(__GetCatalogStr_catalog), "r"(__GetCatalogStr_stringNum), "r"(__GetCatalogStr_defaultString) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetCatalogStr__re; \
  }); \
  _GetCatalogStr__re; \
})

#define GetLocaleStr(locale, stringNum) ({ \
  struct Locale * _GetLocaleStr_locale = (locale); \
  ULONG _GetLocaleStr_stringNum = (stringNum); \
  CONST_STRPTR _GetLocaleStr__re = \
  ({ \
  register struct Library * const __GetLocaleStr__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register CONST_STRPTR __GetLocaleStr__re __asm("d0"); \
  register struct Locale * __GetLocaleStr_locale __asm("a0") = (_GetLocaleStr_locale); \
  register ULONG __GetLocaleStr_stringNum __asm("d0") = (_GetLocaleStr_stringNum); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__GetLocaleStr__re) \
  : "r"(__GetLocaleStr__bn), "r"(__GetLocaleStr_locale), "r"(__GetLocaleStr_stringNum) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetLocaleStr__re; \
  }); \
  _GetLocaleStr__re; \
})

#define IsAlNum(locale, character) ({ \
  struct Locale * _IsAlNum_locale = (locale); \
  ULONG _IsAlNum_character = (character); \
  LONG _IsAlNum__re = \
  ({ \
  register struct Library * const __IsAlNum__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsAlNum__re __asm("d0"); \
  register struct Locale * __IsAlNum_locale __asm("a0") = (_IsAlNum_locale); \
  register ULONG __IsAlNum_character __asm("d0") = (_IsAlNum_character); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__IsAlNum__re) \
  : "r"(__IsAlNum__bn), "r"(__IsAlNum_locale), "r"(__IsAlNum_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsAlNum__re; \
  }); \
  _IsAlNum__re; \
})

#define IsAlpha(locale, character) ({ \
  struct Locale * _IsAlpha_locale = (locale); \
  ULONG _IsAlpha_character = (character); \
  LONG _IsAlpha__re = \
  ({ \
  register struct Library * const __IsAlpha__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsAlpha__re __asm("d0"); \
  register struct Locale * __IsAlpha_locale __asm("a0") = (_IsAlpha_locale); \
  register ULONG __IsAlpha_character __asm("d0") = (_IsAlpha_character); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__IsAlpha__re) \
  : "r"(__IsAlpha__bn), "r"(__IsAlpha_locale), "r"(__IsAlpha_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsAlpha__re; \
  }); \
  _IsAlpha__re; \
})

#define IsCntrl(locale, character) ({ \
  struct Locale * _IsCntrl_locale = (locale); \
  ULONG _IsCntrl_character = (character); \
  LONG _IsCntrl__re = \
  ({ \
  register struct Library * const __IsCntrl__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsCntrl__re __asm("d0"); \
  register struct Locale * __IsCntrl_locale __asm("a0") = (_IsCntrl_locale); \
  register ULONG __IsCntrl_character __asm("d0") = (_IsCntrl_character); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__IsCntrl__re) \
  : "r"(__IsCntrl__bn), "r"(__IsCntrl_locale), "r"(__IsCntrl_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsCntrl__re; \
  }); \
  _IsCntrl__re; \
})

#define IsDigit(locale, character) ({ \
  struct Locale * _IsDigit_locale = (locale); \
  ULONG _IsDigit_character = (character); \
  LONG _IsDigit__re = \
  ({ \
  register struct Library * const __IsDigit__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsDigit__re __asm("d0"); \
  register struct Locale * __IsDigit_locale __asm("a0") = (_IsDigit_locale); \
  register ULONG __IsDigit_character __asm("d0") = (_IsDigit_character); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__IsDigit__re) \
  : "r"(__IsDigit__bn), "r"(__IsDigit_locale), "r"(__IsDigit_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsDigit__re; \
  }); \
  _IsDigit__re; \
})

#define IsGraph(locale, character) ({ \
  struct Locale * _IsGraph_locale = (locale); \
  ULONG _IsGraph_character = (character); \
  LONG _IsGraph__re = \
  ({ \
  register struct Library * const __IsGraph__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsGraph__re __asm("d0"); \
  register struct Locale * __IsGraph_locale __asm("a0") = (_IsGraph_locale); \
  register ULONG __IsGraph_character __asm("d0") = (_IsGraph_character); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__IsGraph__re) \
  : "r"(__IsGraph__bn), "r"(__IsGraph_locale), "r"(__IsGraph_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsGraph__re; \
  }); \
  _IsGraph__re; \
})

#define IsLower(locale, character) ({ \
  struct Locale * _IsLower_locale = (locale); \
  ULONG _IsLower_character = (character); \
  LONG _IsLower__re = \
  ({ \
  register struct Library * const __IsLower__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsLower__re __asm("d0"); \
  register struct Locale * __IsLower_locale __asm("a0") = (_IsLower_locale); \
  register ULONG __IsLower_character __asm("d0") = (_IsLower_character); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__IsLower__re) \
  : "r"(__IsLower__bn), "r"(__IsLower_locale), "r"(__IsLower_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsLower__re; \
  }); \
  _IsLower__re; \
})

#define IsPrint(locale, character) ({ \
  struct Locale * _IsPrint_locale = (locale); \
  ULONG _IsPrint_character = (character); \
  LONG _IsPrint__re = \
  ({ \
  register struct Library * const __IsPrint__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsPrint__re __asm("d0"); \
  register struct Locale * __IsPrint_locale __asm("a0") = (_IsPrint_locale); \
  register ULONG __IsPrint_character __asm("d0") = (_IsPrint_character); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__IsPrint__re) \
  : "r"(__IsPrint__bn), "r"(__IsPrint_locale), "r"(__IsPrint_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsPrint__re; \
  }); \
  _IsPrint__re; \
})

#define IsPunct(locale, character) ({ \
  struct Locale * _IsPunct_locale = (locale); \
  ULONG _IsPunct_character = (character); \
  LONG _IsPunct__re = \
  ({ \
  register struct Library * const __IsPunct__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsPunct__re __asm("d0"); \
  register struct Locale * __IsPunct_locale __asm("a0") = (_IsPunct_locale); \
  register ULONG __IsPunct_character __asm("d0") = (_IsPunct_character); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__IsPunct__re) \
  : "r"(__IsPunct__bn), "r"(__IsPunct_locale), "r"(__IsPunct_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsPunct__re; \
  }); \
  _IsPunct__re; \
})

#define IsSpace(locale, character) ({ \
  struct Locale * _IsSpace_locale = (locale); \
  ULONG _IsSpace_character = (character); \
  LONG _IsSpace__re = \
  ({ \
  register struct Library * const __IsSpace__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsSpace__re __asm("d0"); \
  register struct Locale * __IsSpace_locale __asm("a0") = (_IsSpace_locale); \
  register ULONG __IsSpace_character __asm("d0") = (_IsSpace_character); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__IsSpace__re) \
  : "r"(__IsSpace__bn), "r"(__IsSpace_locale), "r"(__IsSpace_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsSpace__re; \
  }); \
  _IsSpace__re; \
})

#define IsUpper(locale, character) ({ \
  struct Locale * _IsUpper_locale = (locale); \
  ULONG _IsUpper_character = (character); \
  LONG _IsUpper__re = \
  ({ \
  register struct Library * const __IsUpper__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsUpper__re __asm("d0"); \
  register struct Locale * __IsUpper_locale __asm("a0") = (_IsUpper_locale); \
  register ULONG __IsUpper_character __asm("d0") = (_IsUpper_character); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__IsUpper__re) \
  : "r"(__IsUpper__bn), "r"(__IsUpper_locale), "r"(__IsUpper_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsUpper__re; \
  }); \
  _IsUpper__re; \
})

#define IsXDigit(locale, character) ({ \
  struct Locale * _IsXDigit_locale = (locale); \
  ULONG _IsXDigit_character = (character); \
  LONG _IsXDigit__re = \
  ({ \
  register struct Library * const __IsXDigit__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsXDigit__re __asm("d0"); \
  register struct Locale * __IsXDigit_locale __asm("a0") = (_IsXDigit_locale); \
  register ULONG __IsXDigit_character __asm("d0") = (_IsXDigit_character); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__IsXDigit__re) \
  : "r"(__IsXDigit__bn), "r"(__IsXDigit_locale), "r"(__IsXDigit_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsXDigit__re; \
  }); \
  _IsXDigit__re; \
})

#define OpenCatalogA(locale, name, tags) ({ \
  struct Locale * _OpenCatalogA_locale = (locale); \
  CONST_STRPTR _OpenCatalogA_name = (name); \
  struct TagItem * _OpenCatalogA_tags = (tags); \
  struct Catalog * _OpenCatalogA__re = \
  ({ \
  register struct Library * const __OpenCatalogA__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register struct Catalog * __OpenCatalogA__re __asm("d0"); \
  register struct Locale * __OpenCatalogA_locale __asm("a0") = (_OpenCatalogA_locale); \
  register CONST_STRPTR __OpenCatalogA_name __asm("a1") = (_OpenCatalogA_name); \
  register struct TagItem * __OpenCatalogA_tags __asm("a2") = (_OpenCatalogA_tags); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__OpenCatalogA__re) \
  : "r"(__OpenCatalogA__bn), "r"(__OpenCatalogA_locale), "r"(__OpenCatalogA_name), "r"(__OpenCatalogA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenCatalogA__re; \
  }); \
  _OpenCatalogA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Catalog * ___OpenCatalog(struct Library * LocaleBase, struct Locale * locale, CONST_STRPTR name, Tag tags, ...)
{
  return OpenCatalogA(locale, name, (struct TagItem *) &tags);
}

#define OpenCatalog(locale, name...) ___OpenCatalog(LOCALE_BASE_NAME, locale, name)
#endif

#define OpenLocale(name) ({ \
  CONST_STRPTR _OpenLocale_name = (name); \
  struct Locale * _OpenLocale__re = \
  ({ \
  register struct Library * const __OpenLocale__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register struct Locale * __OpenLocale__re __asm("d0"); \
  register CONST_STRPTR __OpenLocale_name __asm("a0") = (_OpenLocale_name); \
  __asm volatile ("jsr a6@(-156:W)" \
  : "=r"(__OpenLocale__re) \
  : "r"(__OpenLocale__bn), "r"(__OpenLocale_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenLocale__re; \
  }); \
  _OpenLocale__re; \
})

#define ParseDate(locale, date, fmtTemplate, getCharFunc) ({ \
  struct Locale * _ParseDate_locale = (locale); \
  struct DateStamp * _ParseDate_date = (date); \
  CONST_STRPTR _ParseDate_fmtTemplate = (fmtTemplate); \
  struct Hook * _ParseDate_getCharFunc = (getCharFunc); \
  LONG _ParseDate__re = \
  ({ \
  register struct Library * const __ParseDate__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __ParseDate__re __asm("d0"); \
  register struct Locale * __ParseDate_locale __asm("a0") = (_ParseDate_locale); \
  register struct DateStamp * __ParseDate_date __asm("a1") = (_ParseDate_date); \
  register CONST_STRPTR __ParseDate_fmtTemplate __asm("a2") = (_ParseDate_fmtTemplate); \
  register struct Hook * __ParseDate_getCharFunc __asm("a3") = (_ParseDate_getCharFunc); \
  __asm volatile ("jsr a6@(-162:W)" \
  : "=r"(__ParseDate__re) \
  : "r"(__ParseDate__bn), "r"(__ParseDate_locale), "r"(__ParseDate_date), "r"(__ParseDate_fmtTemplate), "r"(__ParseDate_getCharFunc) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ParseDate__re; \
  }); \
  _ParseDate__re; \
})

#define StrConvert(locale, string, buffer, bufferSize, type) ({ \
  struct Locale * _StrConvert_locale = (locale); \
  CONST_STRPTR _StrConvert_string = (string); \
  APTR _StrConvert_buffer = (buffer); \
  ULONG _StrConvert_bufferSize = (bufferSize); \
  ULONG _StrConvert_type = (type); \
  ULONG _StrConvert__re = \
  ({ \
  register struct Library * const __StrConvert__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register ULONG __StrConvert__re __asm("d0"); \
  register struct Locale * __StrConvert_locale __asm("a0") = (_StrConvert_locale); \
  register CONST_STRPTR __StrConvert_string __asm("a1") = (_StrConvert_string); \
  register APTR __StrConvert_buffer __asm("a2") = (_StrConvert_buffer); \
  register ULONG __StrConvert_bufferSize __asm("d0") = (_StrConvert_bufferSize); \
  register ULONG __StrConvert_type __asm("d1") = (_StrConvert_type); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__StrConvert__re) \
  : "r"(__StrConvert__bn), "r"(__StrConvert_locale), "r"(__StrConvert_string), "r"(__StrConvert_buffer), "r"(__StrConvert_bufferSize), "r"(__StrConvert_type) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StrConvert__re; \
  }); \
  _StrConvert__re; \
})

#define StrnCmp(locale, string1, string2, length, type) ({ \
  struct Locale * _StrnCmp_locale = (locale); \
  CONST_STRPTR _StrnCmp_string1 = (string1); \
  CONST_STRPTR _StrnCmp_string2 = (string2); \
  LONG _StrnCmp_length = (length); \
  ULONG _StrnCmp_type = (type); \
  LONG _StrnCmp__re = \
  ({ \
  register struct Library * const __StrnCmp__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __StrnCmp__re __asm("d0"); \
  register struct Locale * __StrnCmp_locale __asm("a0") = (_StrnCmp_locale); \
  register CONST_STRPTR __StrnCmp_string1 __asm("a1") = (_StrnCmp_string1); \
  register CONST_STRPTR __StrnCmp_string2 __asm("a2") = (_StrnCmp_string2); \
  register LONG __StrnCmp_length __asm("d0") = (_StrnCmp_length); \
  register ULONG __StrnCmp_type __asm("d1") = (_StrnCmp_type); \
  __asm volatile ("jsr a6@(-180:W)" \
  : "=r"(__StrnCmp__re) \
  : "r"(__StrnCmp__bn), "r"(__StrnCmp_locale), "r"(__StrnCmp_string1), "r"(__StrnCmp_string2), "r"(__StrnCmp_length), "r"(__StrnCmp_type) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StrnCmp__re; \
  }); \
  _StrnCmp__re; \
})

#define Locale_DateToStr(datetime) ({ \
  struct DateTime * _Locale_DateToStr_datetime = (datetime); \
  LONG _Locale_DateToStr__re = \
  ({ \
  register struct Library * const __Locale_DateToStr__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __Locale_DateToStr__re __asm("d0"); \
  register struct DateTime * __Locale_DateToStr_datetime __asm("a0") = (_Locale_DateToStr_datetime); \
  __asm volatile ("jsr a6@(-186:W)" \
  : "=r"(__Locale_DateToStr__re) \
  : "r"(__Locale_DateToStr__bn), "r"(__Locale_DateToStr_datetime) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Locale_DateToStr__re; \
  }); \
  _Locale_DateToStr__re; \
})

#define Locale_StrToDate(datetime) ({ \
  struct DateTime * _Locale_StrToDate_datetime = (datetime); \
  LONG _Locale_StrToDate__re = \
  ({ \
  register struct Library * const __Locale_StrToDate__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __Locale_StrToDate__re __asm("d0"); \
  register struct DateTime * __Locale_StrToDate_datetime __asm("a0") = (_Locale_StrToDate_datetime); \
  __asm volatile ("jsr a6@(-192:W)" \
  : "=r"(__Locale_StrToDate__re) \
  : "r"(__Locale_StrToDate__bn), "r"(__Locale_StrToDate_datetime) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Locale_StrToDate__re; \
  }); \
  _Locale_StrToDate__re; \
})

#define IsBlank(locale, character) ({ \
  struct Locale * _IsBlank_locale = (locale); \
  ULONG _IsBlank_character = (character); \
  LONG _IsBlank__re = \
  ({ \
  register struct Library * const __IsBlank__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register LONG __IsBlank__re __asm("d0"); \
  register struct Locale * __IsBlank_locale __asm("a0") = (_IsBlank_locale); \
  register ULONG __IsBlank_character __asm("d0") = (_IsBlank_character); \
  __asm volatile ("jsr a6@(-198:W)" \
  : "=r"(__IsBlank__re) \
  : "r"(__IsBlank__bn), "r"(__IsBlank_locale), "r"(__IsBlank_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsBlank__re; \
  }); \
  _IsBlank__re; \
})

#define FormatString32(locale, fmtTemplate, dataStream, putCharFunc) ({ \
  struct Locale * _FormatString32_locale = (locale); \
  CONST_STRPTR _FormatString32_fmtTemplate = (fmtTemplate); \
  APTR _FormatString32_dataStream = (dataStream); \
  struct Hook * _FormatString32_putCharFunc = (putCharFunc); \
  APTR _FormatString32__re = \
  ({ \
  register struct Library * const __FormatString32__bn __asm("a6") = (struct Library *) (LOCALE_BASE_NAME);\
  register APTR __FormatString32__re __asm("d0"); \
  register struct Locale * __FormatString32_locale __asm("a0") = (_FormatString32_locale); \
  register CONST_STRPTR __FormatString32_fmtTemplate __asm("a1") = (_FormatString32_fmtTemplate); \
  register APTR __FormatString32_dataStream __asm("a2") = (_FormatString32_dataStream); \
  register struct Hook * __FormatString32_putCharFunc __asm("a3") = (_FormatString32_putCharFunc); \
  __asm volatile ("jsr a6@(-204:W)" \
  : "=r"(__FormatString32__re) \
  : "r"(__FormatString32__bn), "r"(__FormatString32_locale), "r"(__FormatString32_fmtTemplate), "r"(__FormatString32_dataStream), "r"(__FormatString32_putCharFunc) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FormatString32__re; \
  }); \
  _FormatString32__re; \
})

#endif /*  _INLINE_LOCALE_H  */
