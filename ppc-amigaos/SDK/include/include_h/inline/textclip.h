#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_TEXTCLIP_H
#define _INLINE_TEXTCLIP_H

#ifndef TEXTCLIP_BASE_NAME
#define TEXTCLIP_BASE_NAME TextClipBase
#endif

#define WriteClipVector(vector, size) ({ \
  CONST_STRPTR _WriteClipVector_vector = (vector); \
  ULONG _WriteClipVector_size = (size); \
  ({ \
  register char * _WriteClipVector__bn __asm("a6") = (char *) (TEXTCLIP_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), CONST_STRPTR __asm("a0"), ULONG __asm("d0"))) \
  (_WriteClipVector__bn - 30))(_WriteClipVector__bn, _WriteClipVector_vector, _WriteClipVector_size); \
})})

#define ReadClipVector(bufptr, sizptr) ({ \
  STRPTR * _ReadClipVector_bufptr = (bufptr); \
  ULONG * _ReadClipVector_sizptr = (sizptr); \
  ({ \
  register char * _ReadClipVector__bn __asm("a6") = (char *) (TEXTCLIP_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), STRPTR * __asm("a0"), ULONG * __asm("a1"))) \
  (_ReadClipVector__bn - 36))(_ReadClipVector__bn, _ReadClipVector_bufptr, _ReadClipVector_sizptr); \
})})

#define DisposeClipVector(vector) ({ \
  STRPTR _DisposeClipVector_vector = (vector); \
  ({ \
  register char * _DisposeClipVector__bn __asm("a6") = (char *) (TEXTCLIP_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), STRPTR __asm("a0"))) \
  (_DisposeClipVector__bn - 42))(_DisposeClipVector__bn, _DisposeClipVector_vector); \
})})

#endif /*  _INLINE_TEXTCLIP_H  */
