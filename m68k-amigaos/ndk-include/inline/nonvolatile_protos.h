/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_NONVOLATILE_H
#define _INLINE_NONVOLATILE_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

APTR __GetCopyNV(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR appName , __reg("a1") CONST_STRPTR itemName , __reg("d1") BOOL killRequesters ) = "\tjsr\t-30(a6)";
#define GetCopyNV(appName, itemName, killRequesters) __GetCopyNV(NVBase, (appName), (itemName), (killRequesters))

VOID __FreeNVData(__reg("a6") struct Library * , __reg("a0") APTR data ) = "\tjsr\t-36(a6)";
#define FreeNVData(data) __FreeNVData(NVBase, (data))

UWORD __StoreNV(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR appName , __reg("a1") CONST_STRPTR itemName , __reg("a2") CONST_APTR data , __reg("d0") ULONG length , __reg("d1") BOOL killRequesters ) = "\tjsr\t-42(a6)";
#define StoreNV(appName, itemName, data, length, killRequesters) __StoreNV(NVBase, (appName), (itemName), (data), (length), (killRequesters))

BOOL __DeleteNV(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR appName , __reg("a1") CONST_STRPTR itemName , __reg("d1") BOOL killRequesters ) = "\tjsr\t-48(a6)";
#define DeleteNV(appName, itemName, killRequesters) __DeleteNV(NVBase, (appName), (itemName), (killRequesters))

struct NVInfo * __GetNVInfo(__reg("a6") struct Library * , __reg("d1") BOOL killRequesters ) = "\tjsr\t-54(a6)";
#define GetNVInfo(killRequesters) __GetNVInfo(NVBase, (killRequesters))

struct MinList * __GetNVList(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR appName , __reg("d1") BOOL killRequesters ) = "\tjsr\t-60(a6)";
#define GetNVList(appName, killRequesters) __GetNVList(NVBase, (appName), (killRequesters))

BOOL __SetNVProtection(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR appName , __reg("a1") CONST_STRPTR itemName , __reg("d2") LONG mask , __reg("d1") BOOL killRequesters ) = "\tjsr\t-66(a6)";
#define SetNVProtection(appName, itemName, mask, killRequesters) __SetNVProtection(NVBase, (appName), (itemName), (mask), (killRequesters))

#endif /* !_INLINE_NONVOLATILE_H */
