#ifndef INTERNAL_INTERFACES_LANGUAGE_H
#define INTERNAL_INTERFACES_LANGUAGE_H

#include <exec/types.h>
#include <exec/exec.h>
#include <exec/interfaces.h>

struct LanguageIFace
{
    struct InterfaceData Data;

    ULONG APICALL (*Obtain)(struct LanguageIFace *Self);
    ULONG APICALL (*Release)(struct LanguageIFace *Self);
    void APICALL (*Expunge)(struct LanguageIFace *Self);
    struct Interface * APICALL (*Clone)(struct LanguageIFace *Self);
    ULONG APICALL (*LG_GetDriverInfo)(struct LanguageIFace *Self);
    ULONG APICALL (*LG_ConvToLower)(struct LanguageIFace *Self, ULONG character);
    ULONG APICALL (*LG_ConvToUpper)(struct LanguageIFace *Self, ULONG character);
    ULONG APICALL (*LG_GetCodeSet)(struct LanguageIFace *Self);
    CONST_STRPTR APICALL (*LG_GetLocaleStr)(struct LanguageIFace *Self, ULONG stringNum);
    LONG APICALL (*LG_IsAlNum)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsAlpha)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsCntrl)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsDigit)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsGraph)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsLower)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsPrint)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsPunct)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsSpace)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsUpper)(struct LanguageIFace *Self, ULONG character);
    LONG APICALL (*LG_IsXDigit)(struct LanguageIFace *Self, ULONG character);
    ULONG APICALL (*LG_StrConvert)(struct LanguageIFace *Self, CONST_STRPTR string, APTR buffer, ULONG bufferSize, ULONG type);
    LONG APICALL (*LG_StrnCmp)(struct LanguageIFace *Self, CONST_STRPTR string1, CONST_STRPTR string2, LONG length, ULONG type);
    LONG APICALL (*LG_IsBlank)(struct LanguageIFace *Self, ULONG character);
};

#endif
