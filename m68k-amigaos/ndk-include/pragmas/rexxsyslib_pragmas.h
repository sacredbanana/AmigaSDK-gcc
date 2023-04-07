#ifndef PRAGMAS_REXXSYSLIB_PRAGMAS_H
#define PRAGMAS_REXXSYSLIB_PRAGMAS_H

/*
**	$VER: rexxsyslib_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_REXXSYSLIB_PROTOS_H
#include <clib/rexxsyslib_protos.h>
#endif /* CLIB_REXXSYSLIB_PROTOS_H */

/* "rexxsyslib.library" */
/*--- functions in V33 or higher (Release 1.2) ---*/

/*--- (16 function slots reserved here) ---*/

#pragma libcall RexxSysBase CreateArgstring 7e 0802
#pragma libcall RexxSysBase DeleteArgstring 84 801
#pragma libcall RexxSysBase LengthArgstring 8a 801
#pragma libcall RexxSysBase CreateRexxMsg 90 09803
#pragma libcall RexxSysBase DeleteRexxMsg 96 801
#pragma libcall RexxSysBase ClearRexxMsg 9c 0802
#pragma libcall RexxSysBase FillRexxMsg a2 10803
#pragma libcall RexxSysBase IsRexxMsg a8 801


#pragma libcall RexxSysBase LockRexxBase 1c2 001
#pragma libcall RexxSysBase UnlockRexxBase 1c8 001

/*--- function in V45 or higher (Release 3.9) ---*/

#pragma libcall RexxSysBase CreateRexxHostPort 1e0 801
#pragma libcall RexxSysBase DeleteRexxHostPort 1e6 801
#pragma libcall RexxSysBase GetRexxVarFromMsg 1ec 9A803
#pragma libcall RexxSysBase SetRexxVarFromMsg 1f2 9A803
#pragma libcall RexxSysBase LaunchRexxScript 1f8 21A9805
#pragma libcall RexxSysBase FreeRexxMsg 1fe 801

/*--- function in V47 or higher (Release 3.2) ---*/

#pragma libcall RexxSysBase GetRexxBufferFromMsg 204 09A804


#endif /* PRAGMAS_REXXSYSLIB_PRAGMAS_H */
