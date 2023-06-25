#ifndef INTERNAL_INTERFACES_CHARSET_H
#define INTERNAL_INTERFACES_CHARSET_H

#include <exec/types.h>
#include <exec/exec.h>
#include <exec/interfaces.h>

struct CharsetIFace
{
    struct InterfaceData Data;

    ULONG APICALL (*Obtain)(struct CharsetIFace *Self);
    ULONG APICALL (*Release)(struct CharsetIFace *Self);
    void APICALL (*Expunge)(struct CharsetIFace *Self);
    struct Interface * APICALL (*Clone)(struct CharsetIFace *Self);
    ULONG APICALL (*CS_GetDriverInfo)(struct CharsetIFace *Self);
    ULONG APICALL (*CS_ConvToLower)(struct CharsetIFace *Self, ULONG character);
    ULONG APICALL (*CS_ConvToUpper)(struct CharsetIFace *Self, ULONG character);
    ULONG APICALL (*CS_NeverCalledGetCodeSet)(struct CharsetIFace *Self);
    CONST_STRPTR APICALL (*CS_NeverCalledGetLocaleStr)(struct CharsetIFace *Self, ULONG stringNum);
    LONG APICALL (*CS_IsAlNum)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsAlpha)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsCntrl)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsDigit)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsGraph)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsLower)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsPrint)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsPunct)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsSpace)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsUpper)(struct CharsetIFace *Self, ULONG character);
    LONG APICALL (*CS_IsXDigit)(struct CharsetIFace *Self, ULONG character);
    ULONG APICALL (*CS_StrConvert)(struct CharsetIFace *Self, CONST_STRPTR string, APTR buffer, ULONG bufferSize, ULONG type);
    LONG APICALL (*CS_StrnCmp)(struct CharsetIFace *Self, CONST_STRPTR string1, CONST_STRPTR string2, LONG length, ULONG type);
    LONG APICALL (*CS_IsBlank)(struct CharsetIFace *Self, ULONG character);
};

#endif
