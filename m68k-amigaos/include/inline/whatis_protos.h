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

ULONG __WhatIs(__reg("a6") struct Library * , __reg("a0") ULONG Name , __reg("a1") ULONG TagArray ) = "\tjsr\t-30(a6)";
#define WhatIs(Name, TagArray) __WhatIs(WhatIsBase, (Name), (TagArray))

ULONG __GetIDString(__reg("a6") struct Library * , __reg("a0") ULONG Type ) = "\tjsr\t-36(a6)";
#define GetIDString(Type) __GetIDString(WhatIsBase, (Type))

ULONG __GetIconName(__reg("a6") struct Library * , __reg("a0") ULONG Type ) = "\tjsr\t-42(a6)";
#define GetIconName(Type) __GetIconName(WhatIsBase, (Type))

ULONG __GetIDType(__reg("a6") struct Library * , __reg("a0") ULONG IdString ) = "\tjsr\t-48(a6)";
#define GetIDType(IdString) __GetIDType(WhatIsBase, (IdString))

ULONG __CmpFileType(__reg("a6") struct Library * , __reg("a0") ULONG Type1 , __reg("a1") ULONG Type2 ) = "\tjsr\t-54(a6)";
#define CmpFileType(Type1, Type2) __CmpFileType(WhatIsBase, (Type1), (Type2))

ULONG __GetIDStringMaxLen(__reg("a6") struct Library * ) = "\tjsr\t-60(a6)";
#define GetIDStringMaxLen() __GetIDStringMaxLen(WhatIsBase)

ULONG __FirstType(__reg("a6") struct Library * ) = "\tjsr\t-66(a6)";
#define FirstType() __FirstType(WhatIsBase)

ULONG __NextType(__reg("a6") struct Library * , __reg("a0") ULONG Type ) = "\tjsr\t-72(a6)";
#define NextType(Type) __NextType(WhatIsBase, (Type))

ULONG __AskReparse(__reg("a6") struct Library * , __reg("d0") ULONG Now ) = "\tjsr\t-78(a6)";
#define AskReparse(Now) __AskReparse(WhatIsBase, (Now))

ULONG __ParentFileType(__reg("a6") struct Library * , __reg("d0") ULONG Type ) = "\tjsr\t-84(a6)";
#define ParentFileType(Type) __ParentFileType(WhatIsBase, (Type))

ULONG __IsSubTypeOf(__reg("a6") struct Library * , __reg("d0") ULONG Type , __reg("d1") ULONG ParentType ) = "\tjsr\t-90(a6)";
#define IsSubTypeOf(Type, ParentType) __IsSubTypeOf(WhatIsBase, (Type), (ParentType))

ULONG __MakeTypeInfos(__reg("a6") struct Library * , __reg("d0") ULONG SizeOfInfo ) = "\tjsr\t-96(a6)";
#define MakeTypeInfos(SizeOfInfo) __MakeTypeInfos(WhatIsBase, (SizeOfInfo))

ULONG __GetTypeInfo(__reg("a6") struct Library * , __reg("a0") ULONG Handle , __reg("d0") ULONG Type ) = "\tjsr\t-102(a6)";
#define GetTypeInfo(Handle, Type) __GetTypeInfo(WhatIsBase, (Handle), (Type))

ULONG __FreeTypeInfos(__reg("a6") struct Library * , __reg("a0") ULONG Handle ) = "\tjsr\t-108(a6)";
#define FreeTypeInfos(Handle) __FreeTypeInfos(WhatIsBase, (Handle))

#endif /* !_INLINE_WHATIS_H */
