#include <exec/types.h>
#include <exec/tasks.h>
#include <exec/ports.h>
#include <exec/memory.h>
#include <exec/lists.h>
#include <exec/semaphores.h>
#include <exec/execbase.h>
#include <exec/alerts.h>
#include <exec/libraries.h>
#include <exec/interrupts.h>
#include <exec/resident.h>
#include <dos/dos.h>

#include <emul/emulinterface.h>
#include <emul/emulregs.h>

#include <proto/exec.h>

#include <clib/debug_protos.h>


struct LibBase
{
	struct Library   Lib;
	BPTR             SegList;
	struct	ExecBase *SBase;
};

#define	SysBase MyLibBase->SBase

