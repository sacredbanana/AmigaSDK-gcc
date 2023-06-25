#ifndef INTERNAL_INLINE4_CHARSET_H
#define INTERNAL_INLINE4_CHARSET_H
/*
** This file is machine generated from idltool
** Do not edit
*/ 

#include <exec/types.h>
#include <exec/exec.h>
#include <exec/interfaces.h>

#include <exec/types.h>
#include <internal/languagedrivers.h>

/*
 * Inline functions for Interface "main"
 */
#define CS_GetDriverInfo() ICharset->CS_GetDriverInfo() 
#define CS_ConvToLower(character) ICharset->CS_ConvToLower(character) 
#define CS_ConvToUpper(character) ICharset->CS_ConvToUpper(character) 
#define CS_NeverCalledGetCodeSet() ICharset->CS_NeverCalledGetCodeSet() 
#define CS_NeverCalledGetLocaleStr(stringNum) ICharset->CS_NeverCalledGetLocaleStr(stringNum) 
#define CS_IsAlNum(character) ICharset->CS_IsAlNum(character) 
#define CS_IsAlpha(character) ICharset->CS_IsAlpha(character) 
#define CS_IsCntrl(character) ICharset->CS_IsCntrl(character) 
#define CS_IsDigit(character) ICharset->CS_IsDigit(character) 
#define CS_IsGraph(character) ICharset->CS_IsGraph(character) 
#define CS_IsLower(character) ICharset->CS_IsLower(character) 
#define CS_IsPrint(character) ICharset->CS_IsPrint(character) 
#define CS_IsPunct(character) ICharset->CS_IsPunct(character) 
#define CS_IsSpace(character) ICharset->CS_IsSpace(character) 
#define CS_IsUpper(character) ICharset->CS_IsUpper(character) 
#define CS_IsXDigit(character) ICharset->CS_IsXDigit(character) 
#define CS_StrConvert(string, buffer, bufferSize, type) ICharset->CS_StrConvert(string, buffer, bufferSize, type) 
#define CS_StrnCmp(string1, string2, length, type) ICharset->CS_StrnCmp(string1, string2, length, type) 
#define CS_IsBlank(character) ICharset->CS_IsBlank(character) 

#endif
