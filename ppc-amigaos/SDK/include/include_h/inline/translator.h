#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_TRANSLATOR_H
#define _INLINE_TRANSLATOR_H

#ifndef CLIB_TRANSLATOR_PROTOS_H
#define CLIB_TRANSLATOR_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef TRANSLATOR_BASE_NAME
#define TRANSLATOR_BASE_NAME TranslatorBase
#endif

#define Translate(inputString, inputLength, outputBuffer, bufferSize) ({ \
  CONST_STRPTR _Translate_inputString = (inputString); \
  LONG _Translate_inputLength = (inputLength); \
  STRPTR _Translate_outputBuffer = (outputBuffer); \
  LONG _Translate_bufferSize = (bufferSize); \
  LONG _Translate__re = \
  ({ \
  register struct Library * const __Translate__bn __asm("a6") = (struct Library *) (TRANSLATOR_BASE_NAME);\
  register LONG __Translate__re __asm("d0"); \
  register CONST_STRPTR __Translate_inputString __asm("a0") = (_Translate_inputString); \
  register LONG __Translate_inputLength __asm("d0") = (_Translate_inputLength); \
  register STRPTR __Translate_outputBuffer __asm("a1") = (_Translate_outputBuffer); \
  register LONG __Translate_bufferSize __asm("d1") = (_Translate_bufferSize); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__Translate__re) \
  : "r"(__Translate__bn), "r"(__Translate_inputString), "r"(__Translate_inputLength), "r"(__Translate_outputBuffer), "r"(__Translate_bufferSize) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Translate__re; \
  }); \
  _Translate__re; \
})

#endif /*  _INLINE_TRANSLATOR_H  */
