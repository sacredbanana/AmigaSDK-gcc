#ifndef  CLIB_68040_PROTOS_H
#define  CLIB_68040_PROTOS_H

/*
**      $VER: 68040_protos.h 40.2 (31.10.99)
**      Includes Release 40.2
**
**      C prototypes.
**
**      © 1999 THOR-Software (Thomas Richter)
**
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_68040_H
#include <libraries/68040.h>
#endif

ULONG FPUControl(ULONG flags,ULONG mask);

#endif
