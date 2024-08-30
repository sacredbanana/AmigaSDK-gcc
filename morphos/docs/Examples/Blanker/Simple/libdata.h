#define SYSTEM_PRIVATE

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

#include <libraries/query.h>

#include <emul/emulinterface.h>
#include <emul/emulregs.h>

#include <proto/exec.h>

#define UTILITY_BASE_NAME MyLibBase->UtilBase
#define __NOLIBBASE__
#include <proto/utility.h>

void dprintf(char *, ...) __attribute__ ((format (printf, 1, 2)));
void *memclr(APTR, ULONG);

struct LibBase
{
	struct Library          Lib;
	BPTR                    SegList;
	struct ExecBase        *SBase;
	struct Library         *UtilBase;
	struct SignalSemaphore	Semaphore;
};

#define	SysBase	MyLibBase->SBase

