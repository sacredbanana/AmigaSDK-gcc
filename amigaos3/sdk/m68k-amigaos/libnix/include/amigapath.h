#ifndef LIBNIX_AMIGAPATH_H
#define LIBNIX_AMIGAPATH_H

#include <string.h>

/* Rewrite Unix path syntax for AmigaDOS, see sources/nix/extra/__amigapath.c.
   Returns path itself when nothing needs rewriting, else the result written
   to buf, which must hold strlen(path) + 5 bytes.  */
char *__amigapath_into(const char *path, char *buf);

#ifdef IXPATHS
/* Convert into the caller's stack frame: reentrant, and the result lives as
   long as the caller, so it can be handed to dos.library or to another
   converting call such as chmod() after mkdir().  */
#define __amigapath(path) \
  ({ const char *__ap_in = (path); \
     __amigapath_into(__ap_in, (char *)__builtin_alloca(strlen(__ap_in) + 5)); })
#else
/* Without IXPATHS, paths go to AmigaDOS unchanged.  */
#define __amigapath(path) (path)
#endif

#endif
