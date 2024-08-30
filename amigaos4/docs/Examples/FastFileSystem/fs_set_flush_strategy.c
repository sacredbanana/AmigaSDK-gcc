/*
 *	$Id: fs_set_flush_strategy.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 *	:ts=4
 */

#include <exec/interrupts.h>

/****************************************************************************/

/* Kludge for new utility.library and dos.library header files... */
#define UTILITY_DATA_STRUCTURES_H
#define FileSystemData __FileSystemData

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>

/****************************************************************************/

#undef UTILITY_DATA_STRUCTURES_H
#undef FileSystemData

/****************************************************************************/

extern struct Library *SysBase;
extern struct Library *DOSBase;

/****************************************************************************/

#if defined(__amigaos4__)
extern struct ExecIFace *	IExec;
extern struct DOSIFace *	IDOS;
#endif /* __amigaos4__ */

/****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/****************************************************************************/

#include "debug.h"

/****************************************************************************/

int
main(int argc,char ** argv)
{
	if(argc > 1)
	{
		struct MsgPort * mp;

		mp = DeviceProc(argv[1]);
		if(mp != NULL)
		{
			int n,rc;

			if(argc > 2)
				n = atoi(argv[2]);
			else
				n = 0;

			rc = DoPkt(mp,ACTION_DEBUG_FLUSH_STRATEGY,n,	0,0,0,0);

			printf("'%s' flush strategy = %s (was %s).\n",argv[1],(n != 0) ? "relaxed" : "strict",(rc != 0) ? "relaxed" : "strict");
		}
		else
		{
			fprintf(stderr,"'%s' not found.\n",argv[1]);
		}
	}

	return(0);
}
