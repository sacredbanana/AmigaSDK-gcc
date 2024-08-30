#ifndef _SYS_UTSNAME_H
#define _SYS_UTSNAME_H

#include <_ansi.h>

#define _SYS_NMLN 257

struct utsname
{
   char sysname[_SYS_NMLN];
   char nodename[_SYS_NMLN];
   char release[_SYS_NMLN];
   char version[_SYS_NMLN];
   char machine[_SYS_NMLN];
};

_BEGIN_STD_C
int uname (struct utsname *);
_END_STD_C

#endif /* _SYS_UTSNAME_H */
