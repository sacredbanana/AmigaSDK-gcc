/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MHI_H
#define _INLINE_MHI_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef MHI_BASE_NAME
#define MHI_BASE_NAME MHIBase
#endif /* !MHI_BASE_NAME */

#define MHIAllocDecoder(___task, ___mhisignal) \
      LP2(0x1e, APTR, MHIAllocDecoder , struct Task *, ___task, a0, ULONG, ___mhisignal, d0,\
      , MHI_BASE_NAME)

#define MHIFreeDecoder(___handle) \
      LP1NR(0x24, MHIFreeDecoder , APTR, ___handle, a3,\
      , MHI_BASE_NAME)

#define MHIQueueBuffer(___handle, ___buffer, ___size) \
      LP3(0x2a, BOOL, MHIQueueBuffer , APTR, ___handle, a3, APTR, ___buffer, a0, ULONG, ___size, d0,\
      , MHI_BASE_NAME)

#define MHIGetEmpty(___handle) \
      LP1(0x30, APTR, MHIGetEmpty , APTR, ___handle, a3,\
      , MHI_BASE_NAME)

#define MHIGetStatus(___handle) \
      LP1(0x36, UBYTE, MHIGetStatus , APTR, ___handle, a3,\
      , MHI_BASE_NAME)

#define MHIPlay(___handle) \
      LP1NR(0x3c, MHIPlay , APTR, ___handle, a3,\
      , MHI_BASE_NAME)

#define MHIStop(___handle) \
      LP1NR(0x42, MHIStop , APTR, ___handle, a3,\
      , MHI_BASE_NAME)

#define MHIPause(___handle) \
      LP1NR(0x48, MHIPause , APTR, ___handle, a3,\
      , MHI_BASE_NAME)

#define MHIQuery(___query) \
      LP1(0x4e, ULONG, MHIQuery , ULONG, ___query, d1,\
      , MHI_BASE_NAME)

#define MHISetParam(___handle, ___param, ___value) \
      LP3NR(0x54, MHISetParam , APTR, ___handle, a3, UWORD, ___param, d0, ULONG, ___value, d1,\
      , MHI_BASE_NAME)

#endif /* !_INLINE_MHI_H */
