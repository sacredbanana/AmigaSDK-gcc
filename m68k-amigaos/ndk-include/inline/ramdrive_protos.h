/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_RAMDRIVE_H
#define _INLINE_RAMDRIVE_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

STRPTR __KillRAD0(__reg("a6") struct Library * ) = "\tjsr\t-42(a6)";
#define KillRAD0() __KillRAD0(RamdriveDeviceBase)

STRPTR __KillRAD(__reg("a6") struct Library * , __reg("d0") ULONG unit ) = "\tjsr\t-48(a6)";
#define KillRAD(unit) __KillRAD(RamdriveDeviceBase, (unit))

#endif /* !_INLINE_RAMDRIVE_H */
