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

#include <proto/exec.h>
#include <proto/utility.h>

#include <clib/debug_protos.h>


struct LibBase
{
	struct Library  Lib;
	BPTR            SegList;
	struct ExecBase *sysBase;
	struct Library  *utilityBase;
};

#define	SysBase     MyLibBase->sysBase
#define	UtilityBase	MyLibBase->utilityBase

