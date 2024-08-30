#ifndef EXEC_DEVICES_H
#define EXEC_DEVICES_H

/*
	exec device definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#pragma pack(2)


struct Device
{
	struct Library dd_Library;
};

struct Unit
{
	struct MsgPort unit_MsgPort;
	UBYTE          unit_flags;
	UBYTE          unit_pad;
	UWORD          unit_OpenCnt;
};


#define UNITF_ACTIVE  (1<<0)
#define UNITF_INTASK  (1<<1)


#pragma pack()

#endif
