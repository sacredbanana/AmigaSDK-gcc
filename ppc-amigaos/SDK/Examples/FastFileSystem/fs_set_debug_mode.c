/*
 *	$Id: fs_set_debug_mode.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
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
			int n;

			if(argc > 2)
				n = atoi(argv[2]);
			else
				n = 0;

			DoPkt(mp,ACTION_DEBUG_SET_DEBUG_MODE,n,	0,0,0,0);

			printf("'%s' debug mode = %d.\n",argv[1],n);
		}
		else
		{
			fprintf(stderr,"'%s' not found.\n",argv[1]);
		}
	}

	return(0);
}
