#ifndef  CLIB_680X0_PROTOS_H
#define  CLIB_680X0_PROTOS_H

/*
**      $VER: 680X0_protos.h 40.1 (31.10.99)
**      Includes Release 40.1
**
**      C prototypes.
**
**      © 1999 THOR-Software (Thomas Richter)
**
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_680X0_H
#include <libraries/680x0.h>
#endif

char CPUType(void);
char FPUType(void);
char MMUType(void);
ULONG SetFPUExceptions(ULONG flags,ULONG mask);

#endif
