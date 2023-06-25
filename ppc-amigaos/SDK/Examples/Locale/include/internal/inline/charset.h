#ifndef INTERNAL_INLINE_CHARSET_H
#define INTERNAL_INLINE_CHARSET_H

#ifndef CHARSET_BASE_NAME
#define CHARSET_BASE_NAME CharsetBase
#endif

#define CS_GetDriverInfo() ({ \
  register char * _CS_GetDriverInfo__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"))) \
  (_CS_GetDriverInfo__bn - 30))(_CS_GetDriverInfo__bn); \
})

#define CS_ConvToLower(character) ({ \
  ULONG _CS_ConvToLower_character = (character); \
  ({ \
  register char * _CS_ConvToLower__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_ConvToLower__bn - 36))(_CS_ConvToLower__bn, _CS_ConvToLower_character); \
});})

#define CS_ConvToUpper(character) ({ \
  ULONG _CS_ConvToUpper_character = (character); \
  ({ \
  register char * _CS_ConvToUpper__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_ConvToUpper__bn - 42))(_CS_ConvToUpper__bn, _CS_ConvToUpper_character); \
});})

#define CS_IsAlNum(character) ({ \
  ULONG _CS_IsAlNum_character = (character); \
  ({ \
  register char * _CS_IsAlNum__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsAlNum__bn - 60))(_CS_IsAlNum__bn, _CS_IsAlNum_character); \
});})

#define CS_IsAlpha(character) ({ \
  ULONG _CS_IsAlpha_character = (character); \
  ({ \
  register char * _CS_IsAlpha__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsAlpha__bn - 66))(_CS_IsAlpha__bn, _CS_IsAlpha_character); \
});})

#define CS_IsCntrl(character) ({ \
  ULONG _CS_IsCntrl_character = (character); \
  ({ \
  register char * _CS_IsCntrl__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsCntrl__bn - 72))(_CS_IsCntrl__bn, _CS_IsCntrl_character); \
});})

#define CS_IsDigit(character) ({ \
  ULONG _CS_IsDigit_character = (character); \
  ({ \
  register char * _CS_IsDigit__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsDigit__bn - 78))(_CS_IsDigit__bn, _CS_IsDigit_character); \
});})

#define CS_IsGraph(character) ({ \
  ULONG _CS_IsGraph_character = (character); \
  ({ \
  register char * _CS_IsGraph__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsGraph__bn - 84))(_CS_IsGraph__bn, _CS_IsGraph_character); \
});})

#define CS_IsLower(character) ({ \
  ULONG _CS_IsLower_character = (character); \
  ({ \
  register char * _CS_IsLower__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsLower__bn - 90))(_CS_IsLower__bn, _CS_IsLower_character); \
});})

#define CS_IsPrint(character) ({ \
  ULONG _CS_IsPrint_character = (character); \
  ({ \
  register char * _CS_IsPrint__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsPrint__bn - 96))(_CS_IsPrint__bn, _CS_IsPrint_character); \
});})

#define CS_IsPunct(character) ({ \
  ULONG _CS_IsPunct_character = (character); \
  ({ \
  register char * _CS_IsPunct__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsPunct__bn - 102))(_CS_IsPunct__bn, _CS_IsPunct_character); \
});})

#define CS_IsSpace(character) ({ \
  ULONG _CS_IsSpace_character = (character); \
  ({ \
  register char * _CS_IsSpace__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsSpace__bn - 108))(_CS_IsSpace__bn, _CS_IsSpace_character); \
});})

#define CS_IsUpper(character) ({ \
  ULONG _CS_IsUpper_character = (character); \
  ({ \
  register char * _CS_IsUpper__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsUpper__bn - 114))(_CS_IsUpper__bn, _CS_IsUpper_character); \
});})

#define CS_IsXDigit(character) ({ \
  ULONG _CS_IsXDigit_character = (character); \
  ({ \
  register char * _CS_IsXDigit__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsXDigit__bn - 120))(_CS_IsXDigit__bn, _CS_IsXDigit_character); \
});})

#define CS_StrConvert(string, buffer, bufferSize, type) ({ \
  CONST_STRPTR _CS_StrConvert_string = (string); \
  APTR _CS_StrConvert_buffer = (buffer); \
  ULONG _CS_StrConvert_bufferSize = (bufferSize); \
  ULONG _CS_StrConvert_type = (type); \
  ({ \
  register char * _CS_StrConvert__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((ULONG (*)(char * __asm("a6"), CONST_STRPTR __asm("a1"), APTR __asm("a2"), ULONG __asm("d0"), ULONG __asm("d1"))) \
  (_CS_StrConvert__bn - 126))(_CS_StrConvert__bn, _CS_StrConvert_string, _CS_StrConvert_buffer, _CS_StrConvert_bufferSize, _CS_StrConvert_type); \
});})

#define CS_StrnCmp(string1, string2, length, type) ({ \
  CONST_STRPTR _CS_StrnCmp_string1 = (string1); \
  CONST_STRPTR _CS_StrnCmp_string2 = (string2); \
  LONG _CS_StrnCmp_length = (length); \
  ULONG _CS_StrnCmp_type = (type); \
  ({ \
  register char * _CS_StrnCmp__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), CONST_STRPTR __asm("a1"), CONST_STRPTR __asm("a2"), LONG __asm("d0"), ULONG __asm("d1"))) \
  (_CS_StrnCmp__bn - 132))(_CS_StrnCmp__bn, _CS_StrnCmp_string1, _CS_StrnCmp_string2, _CS_StrnCmp_length, _CS_StrnCmp_type); \
});})

#define CS_IsBlank(character) ({ \
  ULONG _CS_IsBlank_character = (character); \
  ({ \
  register char * _CS_IsBlank__bn __asm("a6") = (char *) (CHARSET_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), ULONG __asm("d0"))) \
  (_CS_IsBlank__bn - 138))(_CS_IsBlank__bn, _CS_IsBlank_character); \
});})

#endif /*  INTERNAL_INLINE_CHARSET_H  */
