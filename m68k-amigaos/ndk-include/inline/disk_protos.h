/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_DISK_H
#define _INLINE_DISK_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

BOOL __AllocUnit(__reg("a6") struct Library * , __reg("d0") LONG unitNum ) = "\tjsr\t-6(a6)";
#define AllocUnit(unitNum) __AllocUnit(DiskBase, (unitNum))

VOID __FreeUnit(__reg("a6") struct Library * , __reg("d0") LONG unitNum ) = "\tjsr\t-12(a6)";
#define FreeUnit(unitNum) __FreeUnit(DiskBase, (unitNum))

struct DiskResourceUnit * __GetUnit(__reg("a6") struct Library * , __reg("a1") struct DiskResourceUnit * unitPointer ) = "\tjsr\t-18(a6)";
#define GetUnit(unitPointer) __GetUnit(DiskBase, (unitPointer))

VOID __GiveUnit(__reg("a6") struct Library * ) = "\tjsr\t-24(a6)";
#define GiveUnit() __GiveUnit(DiskBase)

LONG __GetUnitID(__reg("a6") struct Library * , __reg("d0") LONG unitNum ) = "\tjsr\t-30(a6)";
#define GetUnitID(unitNum) __GetUnitID(DiskBase, (unitNum))

LONG __ReadUnitID(__reg("a6") struct Library * , __reg("d0") LONG unitNum ) = "\tjsr\t-36(a6)";
#define ReadUnitID(unitNum) __ReadUnitID(DiskBase, (unitNum))

#endif /* !_INLINE_DISK_H */
