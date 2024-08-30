#ifndef  CLIB_68060_PROTOS_H
#define  CLIB_68060_PROTOS_H

/*
**      $VER: 68060_protos.h 40.1 (23.3.2001)
**      Includes Release 40.1
**
**      C prototypes.
**
**      © 2001 THOR-Software (Thomas Richter)
**
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_68060_H
#include <libraries/68060.h>
#endif

ULONG FPUControl(ULONG flags,ULONG mask);

#endif
