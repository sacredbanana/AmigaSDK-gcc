/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_WHATIS_H
#define _INLINE_WHATIS_H

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

#ifndef WHATIS_BASE_NAME
#define WHATIS_BASE_NAME WhatIsBase
#endif /* !WHATIS_BASE_NAME */

#define WhatIs(___Name, ___TagArray) \
      LP2(0x1e, ULONG, WhatIs , ULONG, ___Name, a0, ULONG, ___TagArray, a1,\
      , WHATIS_BASE_NAME)

#define GetIDString(___Type) \
      LP1(0x24, ULONG, GetIDString , ULONG, ___Type, a0,\
      , WHATIS_BASE_NAME)

#define GetIconName(___Type) \
      LP1(0x2a, ULONG, GetIconName , ULONG, ___Type, a0,\
      , WHATIS_BASE_NAME)

#define GetIDType(___IdString) \
      LP1(0x30, ULONG, GetIDType , ULONG, ___IdString, a0,\
      , WHATIS_BASE_NAME)

#define CmpFileType(___Type1, ___Type2) \
      LP2(0x36, ULONG, CmpFileType , ULONG, ___Type1, a0, ULONG, ___Type2, a1,\
      , WHATIS_BASE_NAME)

#define GetIDStringMaxLen() \
      LP0(0x3c, ULONG, GetIDStringMaxLen ,\
      , WHATIS_BASE_NAME)

#define FirstType() \
      LP0(0x42, ULONG, FirstType ,\
      , WHATIS_BASE_NAME)

#define NextType(___Type) \
      LP1(0x48, ULONG, NextType , ULONG, ___Type, a0,\
      , WHATIS_BASE_NAME)

#define AskReparse(___Now) \
      LP1(0x4e, ULONG, AskReparse , ULONG, ___Now, d0,\
      , WHATIS_BASE_NAME)

#define ParentFileType(___Type) \
      LP1(0x54, ULONG, ParentFileType , ULONG, ___Type, d0,\
      , WHATIS_BASE_NAME)

#define IsSubTypeOf(___Type, ___ParentType) \
      LP2(0x5a, ULONG, IsSubTypeOf , ULONG, ___Type, d0, ULONG, ___ParentType, d1,\
      , WHATIS_BASE_NAME)

#define MakeTypeInfos(___SizeOfInfo) \
      LP1(0x60, ULONG, MakeTypeInfos , ULONG, ___SizeOfInfo, d0,\
      , WHATIS_BASE_NAME)

#define GetTypeInfo(___Handle, ___Type) \
      LP2(0x66, ULONG, GetTypeInfo , ULONG, ___Handle, a0, ULONG, ___Type, d0,\
      , WHATIS_BASE_NAME)

#define FreeTypeInfos(___Handle) \
      LP1(0x6c, ULONG, FreeTypeInfos , ULONG, ___Handle, a0,\
      , WHATIS_BASE_NAME)

#endif /* !_INLINE_WHATIS_H */
