/*
 *	$Id: fs_set_file_size.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
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

#include <stdio.h>

/****************************************************************************/

#include "debug.h"

/****************************************************************************/

int
main(int argc,char ** argv)
{
	if(argc > 1)
	{
		BPTR file;

		file = Open(argv[1],MODE_NEWFILE);
		if(file != ZERO)
		{
			if(SetFileSize(file,64 * 1024 * 1024,OFFSET_BEGINNING) == -1)
				PrintFault(IoErr(),"SetFileSize");

			Close(file);
		}
		else
		{
			PrintFault(IoErr(),argv[1]);
		}
	}

	return(0);
}
