#ifndef CLIB_OWNDEVUNIT_PROTOS_H
#define CLIB_OWNDEVUNIT_PROTOS_H

/*
	owndevunit.library C prototypes

	Copyright © 2003 The MorphOS Development Team, All Rights Reserved.
*/


#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_OWNDEVUNIT_H
# include <libraries/owndevunit.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

UBYTE *LockDevUnit(UBYTE *Device, ULONG Unit, UBYTE *OwnerName, UBYTE NotifyBit);
UBYTE *AttemptDevUnit(UBYTE *Device, ULONG Unit, UBYTE *OwnerName, UBYTE NotifyBit);
void   FreeDevUnit(UBYTE *Device, ULONG Unit);
void   NameDevUnit(UBYTE *Device, ULONG Unit, UBYTE *OwnerName);
BOOL   AvailDevUnit(UBYTE *Device, ULONG Unit);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_OWNDEVUNIT_PROTOS_H */
