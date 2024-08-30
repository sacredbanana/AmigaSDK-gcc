#ifndef LIBRARIES_RESOURCE_H
#define LIBRARIES_RESOURCE_H

/*
	resource.library include (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

typedef APTR RESOURCEFILE;
typedef ULONG RESOURCEID;

#define RL_GADGETMASK   0x03FF
#define RL_GROUPMASK    0xFC00

#define RL_GADGETID(x)  ((x) & RL_GADGETMASK)
#define RL_GROUPID(x)   (((x) & RL_GROUPMASK) >> 10)


#endif /* LIBRARIES_RESOURCE_H */
