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
	struct Library  Lib;
	UWORD           Pad;
	void            *DataSeg; // Don't change the position of this. The offset must stay
	                          // at 36, or __restore_r13 in lib(data).c must be adjusted.

	BPTR            SegList;
	struct ExecBase *SBase;

	ULONG           DataSize;
	struct LibBase  *Parent;
};


BOOL __saveds InitData(struct LibBase *);
void __saveds UnInitData(struct LibBase *);
