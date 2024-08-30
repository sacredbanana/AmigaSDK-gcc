#ifndef EXEC_IO_H
#define EXEC_IO_H

/*
	exec io definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#pragma pack(2)


struct IORequest
{
	struct Message   io_Message;
	struct Device   *io_Device;
	struct Unit     *io_Unit;
	UWORD            io_Command;
	UBYTE            io_Flags;
	BYTE             io_Error;
};

struct IOStdReq
{
	struct Message   io_Message;
	struct Device   *io_Device;
	struct Unit     *io_Unit;
	UWORD            io_Command;
	UBYTE            io_Flags;
	BYTE             io_Error;
	ULONG            io_Actual;
	ULONG            io_Length;
	APTR             io_Data;
	ULONG            io_Offset;
};

#define DEV_BEGINIO  (-30)
#define DEV_ABORTIO  (-36)

#define IOB_QUICK  0
#define IOF_QUICK  (1<<IOB_QUICK)

#define CMD_INVALID  0
#define CMD_RESET    1
#define CMD_READ     2
#define CMD_WRITE    3
#define CMD_UPDATE   4
#define CMD_CLEAR    5
#define CMD_STOP     6
#define CMD_START    7
#define CMD_FLUSH    8
#define CMD_NONSTD   9


#pragma pack()

#endif
