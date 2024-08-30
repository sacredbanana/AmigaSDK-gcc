#ifndef CLIB_IFCONFIG_PROTOS_H
#define CLIB_IFCONFIG_PROTOS_H

/*
	ifconfig.library C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_IFCONFIG_H
#include <libraries/ifconfig.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ifconfig.library functions */

/*
 * Find the interface configuration for interface ifname.
 */
LONG IfConfigFind(const char *ifname, struct ifconfig ** ifcp);

/*
 * Free the configuration got from IfConfigFind().
 */
void IfConfigFree(struct ifconfig * config);

/*
 * Find all interface configurations matching the filter. filter can be NULL. 
 */
LONG IfConfigFindAll(struct List ** ifclist, struct TagItem * filter);

/*
 * Free a list of configuration entries returned by IfConfigFindAll().
 */
void IfConfigFreeList(struct List * list);

/*
 * Convert ifconfig.library error codes to english language error strings.
 */
const UBYTE * IfConfigStrError(ULONG ioerr, char * buf, ULONG bufsiz);

/*
 * Return (english) name of the tag
 */
const struct ifc_confitem * IfConfigGetTagInfo(ULONG tagcode);

struct ifconfig *IfConfigCreate(char *buf, ULONG bufsize);
ULONG IfConfigGetData(ULONG tagcode, ULONG def, struct ifconfig *ifc);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !CLIB_IFCONFIG_PROTOS_H */
