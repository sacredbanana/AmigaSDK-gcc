#ifndef WORKBENCH_STARTUP_H
#define WORKBENCH_STARTUP_H

/*
	wb startup defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


struct WBStartup
{
	struct Message  sm_Message;
	struct MsgPort *sm_Process;
	BPTR            sm_Segment;
	LONG            sm_NumArgs;
	char           *sm_ToolWindow;
	struct WBArg   *sm_ArgList;
};

struct WBArg
{
	BPTR  wa_Lock;
	BYTE *wa_Name;
};


#pragma pack()

#endif /* WORKBENCH_STARTUP_H */
