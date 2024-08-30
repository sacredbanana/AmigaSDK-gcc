#ifndef INTERNAL_INLINE_LANGUAGE_H
#define INTERNAL_INLINE_LANGUAGE_H

#ifndef LANGUAGE_BASE_NAME
#define LANGUAGE_BASE_NAME LanguageBase
#endif

#define LG_GetDriverInfo() ({ \
  register char * _LG_GetDriverInfo__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"))) \
  (_LG_GetDriverInfo__bn - 30))(_LG_GetDriverInfo__bn); \
})

#define LG_ConvToLower(character) ({ \
  ULONG _LG_ConvToLower_character = (character); \
  ({ \
  register char * _LG_ConvToLower__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_ConvToLower__bn - 36))(_LG_ConvToLower__bn, _LG_ConvToLower_character); \
});})

#define LG_ConvToUpper(character) ({ \
  ULONG _LG_ConvToUpper_character = (character); \
  ({ \
  register char * _LG_ConvToUpper__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_ConvToUpper__bn - 42))(_LG_ConvToUpper__bn, _LG_ConvToUpper_character); \
});})

#define LG_GetCodeSet() ({ \
  register char * _LG_GetCodeSet__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"))) \
  (_LG_GetCodeSet__bn - 48))(_LG_GetCodeSet__bn); \
})

#define LG_GetLocaleStr(stringNum) ({ \
  ULONG _LG_GetLocaleStr_stringNum = (stringNum); \
  ({ \
  register char * _LG_GetLocaleStr__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((CONST_STRPTR (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_GetLocaleStr__bn - 54))(_LG_GetLocaleStr__bn, _LG_GetLocaleStr_stringNum); \
});})

#define LG_IsAlNum(character) ({ \
  ULONG _LG_IsAlNum_character = (character); \
  ({ \
  register char * _LG_IsAlNum__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsAlNum__bn - 60))(_LG_IsAlNum__bn, _LG_IsAlNum_character); \
});})

#define LG_IsAlpha(character) ({ \
  ULONG _LG_IsAlpha_character = (character); \
  ({ \
  register char * _LG_IsAlpha__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsAlpha__bn - 66))(_LG_IsAlpha__bn, _LG_IsAlpha_character); \
});})

#define LG_IsCntrl(character) ({ \
  ULONG _LG_IsCntrl_character = (character); \
  ({ \
  register char * _LG_IsCntrl__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsCntrl__bn - 72))(_LG_IsCntrl__bn, _LG_IsCntrl_character); \
});})

#define LG_IsDigit(character) ({ \
  ULONG _LG_IsDigit_character = (character); \
  ({ \
  register char * _LG_IsDigit__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsDigit__bn - 78))(_LG_IsDigit__bn, _LG_IsDigit_character); \
});})

#define LG_IsGraph(character) ({ \
  ULONG _LG_IsGraph_character = (character); \
  ({ \
  register char * _LG_IsGraph__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsGraph__bn - 84))(_LG_IsGraph__bn, _LG_IsGraph_character); \
});})

#define LG_IsLower(character) ({ \
  ULONG _LG_IsLower_character = (character); \
  ({ \
  register char * _LG_IsLower__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsLower__bn - 90))(_LG_IsLower__bn, _LG_IsLower_character); \
});})

#define LG_IsPrint(character) ({ \
  ULONG _LG_IsPrint_character = (character); \
  ({ \
  register char * _LG_IsPrint__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsPrint__bn - 96))(_LG_IsPrint__bn, _LG_IsPrint_character); \
});})

#define LG_IsPunct(character) ({ \
  ULONG _LG_IsPunct_character = (character); \
  ({ \
  register char * _LG_IsPunct__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsPunct__bn - 102))(_LG_IsPunct__bn, _LG_IsPunct_character); \
});})

#define LG_IsSpace(character) ({ \
  ULONG _LG_IsSpace_character = (character); \
  ({ \
  register char * _LG_IsSpace__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsSpace__bn - 108))(_LG_IsSpace__bn, _LG_IsSpace_character); \
});})

#define LG_IsUpper(character) ({ \
  ULONG _LG_IsUpper_character = (character); \
  ({ \
  register char * _LG_IsUpper__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsUpper__bn - 114))(_LG_IsUpper__bn, _LG_IsUpper_character); \
});})

#define LG_IsXDigit(character) ({ \
  ULONG _LG_IsXDigit_character = (character); \
  ({ \
  register char * _LG_IsXDigit__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsXDigit__bn - 120))(_LG_IsXDigit__bn, _LG_IsXDigit_character); \
});})

#define LG_StrConvert(string, buffer, bufferSize, type) ({ \
  CONST_STRPTR _LG_StrConvert_string = (string); \
  APTR _LG_StrConvert_buffer = (buffer); \
  ULONG _LG_StrConvert_bufferSize = (bufferSize); \
  ULONG _LG_StrConvert_type = (type); \
  ({ \
  register char * _LG_StrConvert__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"), CONST_STRPTR __asm("a1"), APTR __asm("a2"), ULONG __asm("d0"), ULONG __asm("d1"))) \
  (_LG_StrConvert__bn - 126))(_LG_StrConvert__bn, _LG_StrConvert_string, _LG_StrConvert_buffer, _LG_StrConvert_bufferSize, _LG_StrConvert_type); \
});})

#define LG_StrnCmp(string1, string2, length, type) ({ \
  CONST_STRPTR _LG_StrnCmp_string1 = (string1); \
  CONST_STRPTR _LG_StrnCmp_string2 = (string2); \
  LONG _LG_StrnCmp_length = (length); \
  ULONG _LG_StrnCmp_type = (type); \
  ({ \
  register char * _LG_StrnCmp__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), CONST_STRPTR __asm("a1"), CONST_STRPTR __asm("a2"), LONG __asm("d0"), ULONG __asm("d1"))) \
  (_LG_StrnCmp__bn - 132))(_LG_StrnCmp__bn, _LG_StrnCmp_string1, _LG_StrnCmp_string2, _LG_StrnCmp_length, _LG_StrnCmp_type); \
});})

#define LG_IsBlank(character) ({ \
  ULONG _LG_IsBlank_character = (character); \
  ({ \
  register char * _LG_IsBlank__bn __asm("a6") = (char *) (LANGUAGE_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_LG_IsBlank__bn - 138))(_LG_IsBlank__bn, _LG_IsBlank_character); \
});})

#endif /*  INTERNAL_INLINE_LANGUAGE_H  */
