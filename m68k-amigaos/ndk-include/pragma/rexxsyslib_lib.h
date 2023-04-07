#ifndef PRAGMA_REXXSYSLIB_LIB_H
#define PRAGMA_REXXSYSLIB_LIB_H

/*
**	$VER: rexxsyslib_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_REXXSYSLIB_PROTOS_H
#include <clib/rexxsyslib_protos.h>
#endif /* CLIB_REXXSYSLIB_PROTOS_H */

/* "rexxsyslib.library" */
/*--- functions in V33 or higher (Release 1.2) ---*/

/*--- (16 function slots reserved here) ---*/

#pragma amicall(RexxSysBase, 0x7e, CreateArgstring(a0,d0))
#pragma amicall(RexxSysBase, 0x84, DeleteArgstring(a0))
#pragma amicall(RexxSysBase, 0x8a, LengthArgstring(a0))
#pragma amicall(RexxSysBase, 0x90, CreateRexxMsg(a0,a1,d0))
#pragma amicall(RexxSysBase, 0x96, DeleteRexxMsg(a0))
#pragma amicall(RexxSysBase, 0x9c, ClearRexxMsg(a0,d0))
#pragma amicall(RexxSysBase, 0xa2, FillRexxMsg(a0,d0,d1))
#pragma amicall(RexxSysBase, 0xa8, IsRexxMsg(a0))


#pragma amicall(RexxSysBase, 0x1c2, LockRexxBase(d0))
#pragma amicall(RexxSysBase, 0x1c8, UnlockRexxBase(d0))

/*--- function in V45 or higher (Release 3.9) ---*/

#pragma amicall(RexxSysBase, 0x1e0, CreateRexxHostPort(a0))
#pragma amicall(RexxSysBase, 0x1e6, DeleteRexxHostPort(a0))
#pragma amicall(RexxSysBase, 0x1ec, GetRexxVarFromMsg(a0,a2,a1))
#pragma amicall(RexxSysBase, 0x1f2, SetRexxVarFromMsg(a0,a2,a1))
#pragma amicall(RexxSysBase, 0x1f8, LaunchRexxScript(a0,a1,a2,d1,d2))
#pragma amicall(RexxSysBase, 0x1fe, FreeRexxMsg(a0))

/*--- function in V47 or higher (Release 3.2) ---*/

#pragma amicall(RexxSysBase, 0x204, GetRexxBufferFromMsg(a0,a2,a1,d0))


#endif /* PRAGMA_REXXSYSLIB_LIB_H */
