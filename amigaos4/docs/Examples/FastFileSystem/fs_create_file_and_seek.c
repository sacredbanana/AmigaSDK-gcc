/*
 * $Id: fs_create_file_and_seek.c,v 1.1 2008-09-15 13:14:19 sarcher Exp $
 *
 * :ts=4
 */

#include <exec/memory.h>

#include <dos/dos.h>

#include <string.h>
#include <stdarg.h>

/****************************************************************************/

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>

/****************************************************************************/

extern struct Library *SysBase;
extern struct Library *DOSBase;

/****************************************************************************/

#if defined(__amigaos4__)
extern struct ExecIFace *	IExec;
extern struct DOSIFace *	IDOS;
#endif /* __amigaos4__ */

/****************************************************************************/

#if defined(__GNUC__)

#if defined(__amigaos4__)
#define VAR_ARGS __attribute__((linearvarargs))
#else
#define VAR_ARGS
#endif /* __amigaos4__ */

#if defined(Printf)
#undef Printf
#endif /* Printf */

#define Printf Local_Printf

STATIC VAR_ARGS LONG
Local_Printf(STRPTR format,...)
{
	va_list args;
	LONG result;

	#if defined(__amigaos4__)
	{
		va_startlinear(args,format);
		result = VPrintf(format,va_getlinearva(args, APTR));
		va_end(args);
	}
	#else
	{
		va_start(args,format);
		result = VPrintf(format,args);
		va_end(args);
	}
	#endif /* __amigaos4__ */

	return(result);
}

#endif /* __GNUC__ */

/****************************************************************************/

int
main(int argc,char ** argv)
{
	if(argc > 1)
	{
		APTR buffer;
		LONG size;

		size = 72 * 512;

		buffer = AllocVec(size,MEMF_ANY|MEMF_PUBLIC|MEMF_CLEAR);
		if(buffer != NULL)
		{
			BPTR file;

			file = Open(argv[1],MODE_NEWFILE);
			if(file != (BPTR)NULL)
			{
				Printf("Writing %ld bytes to file.\n",size);
				if(Write(file,buffer,size) > 0)
				{
					Printf("Seeking back to start of file.\n");
					if(Seek(file,0,OFFSET_BEGINNING) == -1)
						PrintFault(IoErr(),argv[1]);

					Printf("Seeking to middle of file.\n");
					if(Seek(file,size / 2,OFFSET_BEGINNING) == -1)
						PrintFault(IoErr(),argv[1]);

					Printf("Seeking to end of file.\n");
					if(Seek(file,0,OFFSET_END) != -1)
					{
						Printf("Writing more data to the end of the file.\n");

						memset(buffer,0x11,(size_t)size);

						if(Write(file,buffer,size) < 0)
							PrintFault(IoErr(),argv[1]);
					}
					else
					{
						PrintFault(IoErr(),argv[1]);
					}
				}
				else
				{
					PrintFault(IoErr(),argv[1]);
				}

				Close(file);
			}
			else
			{
				PrintFault(IoErr(),argv[1]);
			}

			FreeVec(buffer);
		}
		else
		{
			PrintFault(IoErr(),argv[1]);
		}
	}

	return(0);
}
