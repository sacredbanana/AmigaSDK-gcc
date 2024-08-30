#ifndef CLIB_PCIIDS_PROTOS_H
#define CLIB_PCIIDS_PROTOS_H

/*
	pciids C prototypes

	Copyright © 2004 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CONST_STRPTR PCIIDS_GetVendorName(ULONG vendorid);
CONST_STRPTR PCIIDS_GetDeviceName(ULONG vendorid, ULONG deviceid);
CONST_STRPTR PCIIDS_GetSubDeviceName(ULONG vendorid, ULONG deviceid,
                                     ULONG subvendorid, ULONG subdeviceid);
CONST_STRPTR PCIIDS_GetClassName(ULONG classid);
CONST_STRPTR PCIIDS_GetSubClassName(ULONG classid, ULONG subclassid);
CONST_STRPTR PCIIDS_GetProgIfName(ULONG classid, ULONG subclassid, ULONG progifid);
LONG         PCIIDS_LoadFile(CONST_STRPTR filename);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_PCIIDS_PROTOS_H */
