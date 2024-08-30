/*
 *	$Id: fs_test.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 *	:ts=4
 *
 *	Amiga ROM file system reimplementation
 *	Copyright © 2001-2005 by Olaf Barthel
 *	All Rights Reserved
 *
 *	"Experience is the worst teacher. It always gives the test
 *	 first and the instruction afterward."
 */

#include <devices/inputevent.h>
#include <exec/interrupts.h>

#include <dos/dosextens.h>

/****************************************************************************/

/* Kludge for new utility.library header files... */
#define UTILITY_DATA_STRUCTURES_H

#define __NOLIBBASE__
#include <proto/utility.h>
#include <proto/exec.h>
#include <proto/dos.h>

/****************************************************************************/

extern struct Library *SysBase;
extern struct Library *DOSBase;
extern struct Library *UtilityBase;

/****************************************************************************/

#if defined(__amigaos4__)
extern struct ExecIFace *		IExec;
extern struct DOSIFace *		IDOS;
extern struct UtilityIFace *	IUtility;
#endif /* __amigaos4__ */

/****************************************************************************/

#include <string.h>
#include <stddef.h>
#include <stdlib.h>

/****************************************************************************/

#include "macros.h"
#include "block.h"
#include "file.h"
#include "dir.h"
#include "debug.h"
#include "validator.h"
#include "bitmap.h"
#include "format.h"
#include "add.h"
#include "size.h"
#include "relabel.h"
#include "rename.h"
#include "change.h"
#include "delete.h"
#include "locate.h"
#include "fs.h"
#include "main.h"

/****************************************************************************/

#include "assert.h"

/****************************************************************************/

static struct FileSystemData * cleanup_fsd;
static char cleanup_name[260];
static BOOL cleanup_inhibit = FALSE;
static struct MsgPort * cleanup_port;

static void
exit_trap(void)
{
	if(cleanup_fsd != NULL)
	{
		fs_exit(cleanup_fsd);
		cleanup_fsd = NULL;
	}

	if(cleanup_port != NULL)
	{
		DeleteMsgPort(cleanup_port);
		cleanup_port = NULL;
	}

	if(cleanup_inhibit)
	{
		Inhibit(cleanup_name,DOSFALSE);

		cleanup_inhibit = FALSE;
	}
}

/****************************************************************************/

int
main(int argc,char ** argv)
{
	atexit(exit_trap);

	if(argc > 1)
	{
		struct DeviceNode * dn;
		char name[260];
		int i;

		strncpy(name,argv[1],sizeof(name)-1);
		name[sizeof(name)-1] = '\0';

		for(i = strlen(name)-1 ; i >= 0 ; i++)
		{
			if(name[i] == ':')
			{
				name[i] = '\0';
				break;
			}
		}

		dn = (struct DeviceNode *)FindDosEntry(LockDosList(LDF_DEVICES|LDF_READ),(STRPTR)name,LDF_DEVICES);
		UnLockDosList(LDF_DEVICES|LDF_READ);

		if(dn != NULL)
		{
			cleanup_port = CreateMsgPort();
			if(cleanup_port != NULL)
			{
				strcpy(cleanup_name,name);
				strcat(cleanup_name,":");

				if(Inhibit(cleanup_name,DOSTRUE))
				{
					struct FileSystemData * fsd;

					cleanup_inhibit = TRUE;

					SETDEBUGLEVEL(2);

					if(fs_init(dn,&fsd,(struct Library *)SysBase) == OK)
					{
						cleanup_fsd = fsd;
						fsd->fsd_Task = cleanup_port;

						file_system_main_loop(fsd);
					}
				}
			}
		}
	}

	return(0);
}
