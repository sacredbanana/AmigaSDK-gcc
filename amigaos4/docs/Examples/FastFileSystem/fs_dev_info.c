/*
 * $Id: fs_dev_info.c,v 1.1 2008-09-15 13:14:19 sarcher Exp $
 *
 * :ts=4
 */

#include <dos/dosextens.h>
#include <dos/filehandler.h>
#include <dos/rdargs.h>

#include <exec/memory.h>
#include <exec/io.h>

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

#include <string.h>
#include <stdarg.h>

/****************************************************************************/

STRPTR version_tag = "$VER: fs_dev_info 1.2 (17.12.2002)\r\n";

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

STATIC VOID
print_dos_type(ULONG type)
{
	UBYTE string[4 * 4 + 1],c;
	int i,j;

	for(i = j = 0 ; i < 4 ; i++)
	{
		c = (type >> 24);
		type <<= 8;

		if(c <= 7)
		{
			string[j++] = '\\';
			string[j++] = '0' + c;
		}
		else if (128 <= c && c < 160)
		{
			const char hex_string[] = "0123456789ABCDEF";

			string[j++] = '\\';
			string[j++] = 'x';
			string[j++] = hex_string[(c >> 4) & 15];
			string[j++] = hex_string[c & 15];
		}
		else
		{
			string[j++] = c;
		}
	}

	string[j] = '\0';

	Printf("'%s'",string);
}

/****************************************************************************/

struct MemoryType
{
	ULONG	mt_Type;
	char *	mt_Name;
};

/****************************************************************************/

STATIC VOID
print_memory_flags(ULONG type)
{
	static const struct MemoryType mt[] =
	{
		{ (ULONG)MEMF_PUBLIC,		"MEMF_PUBLIC" },
		{ (ULONG)MEMF_CHIP,			"MEMF_CHIP" },
		{ (ULONG)MEMF_FAST,			"MEMF_FAST" },
		{ (ULONG)MEMF_LOCAL,		"MEMF_LOCAL" },
		{ (ULONG)MEMF_24BITDMA,		"MEMF_24BITDMA" },
		{ (ULONG)MEMF_KICK,			"MEMF_KICK" },
		{ (ULONG)MEMF_CLEAR,		"MEMF_CLEAR" },
		{ (ULONG)MEMF_LARGEST,		"MEMF_LARGEST" },
		{ (ULONG)MEMF_REVERSE,		"MEMF_REVERSE" },
		{ (ULONG)MEMF_NO_EXPUNGE,	"MEMF_NO_EXPUNGE" },
		{ 0,						NULL }
	};

	int column,i;

	if(type == 0)
		Printf("MEMF_ANY");

	column = 0;

	for(i = 0 ; mt[i].mt_Type != 0 ; i++)
	{
		if(type & mt[i].mt_Type)
		{
			if(column++ != 0)
				Printf("|");

			Printf("%s",mt[i].mt_Name);

			type &= ~mt[i].mt_Type;
		}
	}

	if(type != 0)
	{
		if(column != 0)
			Printf("|");

		Printf("0x%lx",type);
	}

	Printf("\n");
}

/****************************************************************************/

int
main(int argc,char ** argv)
{
	struct DosList * dl = NULL;
	BOOL dos_list_locked = FALSE;
	struct DosList * dol;
	struct RDArgs * rda;
	STRPTR device_name = NULL;
	int result;
	char name_without_colon[256];
	size_t len;
	int i;

	rda = ReadArgs("DEVICE/A",(LONG *)&device_name,NULL);
	if(rda == NULL)
	{
		PrintFault(IoErr(),argv[0]);
		result = RETURN_FAIL;
		goto out;
	}

	len = strlen(device_name);
	if(len > sizeof(name_without_colon)-1)
		len = sizeof(name_without_colon)-1;

	memcpy(name_without_colon,device_name,len);
	name_without_colon[len] = '\0';

	for(i = len-1 ; i >= 0 ; i--)
	{
		if(name_without_colon[i] == ':')
		{
			name_without_colon[i] = '\0';
			break;
		}
	}

	dl = LockDosList(LDF_DEVICES|LDF_VOLUMES|LDF_ASSIGNS|LDF_READ);
	dos_list_locked = TRUE;

	dol = FindDosEntry(dl,name_without_colon,LDF_DEVICES|LDF_VOLUMES|LDF_ASSIGNS);
	if(dol == NULL)
	{
		PrintFault(ERROR_OBJECT_NOT_FOUND,name_without_colon);
		result = RETURN_ERROR;
		goto out;
	}

	switch(dol->dol_Type)
	{
		case DLT_DEVICE:

			Printf("dol->dol_Type = DLT_DEVICE\n");
			break;

		case DLT_DIRECTORY:

			Printf("dol->dol_Type = DLT_DIRECTORY\n");
			break;

		case DLT_VOLUME:

			Printf("dol->dol_Type = DLT_VOLUME\n");
			break;

		case DLT_LATE:

			Printf("dol->dol_Type = DLT_LATE\n");
			break;

		case DLT_NONBINDING:

			Printf("dol->dol_Type = DLT_NONBINDING\n");
			break;

		default:

			Printf("dol->dol_Type = %ld\n",dol->dol_Type);
			break;
	}

	if(dol->dol_Task != NULL)
		Printf("dol->dol_Task = 0x%lx\n",dol->dol_Task);
	else
		Printf("dol->dol_Task = NULL\n");

	if(dol->dol_Lock != 0)
		Printf("dol->dol_Lock = 0x%lx\n",BADDR(dol->dol_Lock));
	else
		Printf("dol->dol_Lock = NULL\n");

	if(dol->dol_Type == DLT_DEVICE)
	{
		struct FileSysStartupMsg * fssm;

		if(dol->dol_misc.dol_handler.dol_Handler != 0)
			Printf("dol->dol_Handler = \"%b\"\n",dol->dol_misc.dol_handler.dol_Handler);
		else
			Printf("dol->dol_Handler = NULL\n");

		Printf("dol->dol_StackSize = %ld\n",dol->dol_misc.dol_handler.dol_StackSize);
		Printf("dol->dol_Priority = %ld\n",dol->dol_misc.dol_handler.dol_Priority);

		fssm = BADDR(dol->dol_misc.dol_handler.dol_Startup);

		if((dol->dol_misc.dol_handler.dol_Startup & 0xC0000000) == 0 && TypeOfMem(fssm) != 0)
		{
			struct DosEnvec * de;

			Printf("dol->dol_Startup->fssm_Device = \"%b\"\n",fssm->fssm_Device);
			Printf("dol->dol_Startup->fssm_Unit = %ld\n",fssm->fssm_Unit);

			if(fssm->fssm_Flags != 0)
				Printf("dol->dol_Startup->fssm_Flags = 0x%lx\n",fssm->fssm_Flags);
			else
				Printf("dol->dol_Startup->fssm_Flags = 0\n");

			de = BADDR(fssm->fssm_Environ);

			Printf("dol->dol_Startup->fssm_Environ->de_TableSize = %lu\n",de->de_TableSize);

			if(de->de_TableSize >= DE_SIZEBLOCK)
				Printf("dol->dol_Startup->fssm_Environ->de_SizeBlock = %lu bytes\n",de->de_SizeBlock * sizeof(LONG));

			if(de->de_TableSize >= DE_SECORG)
				Printf("dol->dol_Startup->fssm_Environ->de_SecOrg = %lu\n",de->de_SecOrg);

			if(de->de_TableSize >= DE_NUMHEADS)
				Printf("dol->dol_Startup->fssm_Environ->de_Surfaces = %lu\n",de->de_Surfaces);

			if(de->de_TableSize >= DE_SECSPERBLK)
				Printf("dol->dol_Startup->fssm_Environ->de_SectorPerBlock = %lu\n",de->de_SectorPerBlock);

			if(de->de_TableSize >= DE_BLKSPERTRACK)
				Printf("dol->dol_Startup->fssm_Environ->de_BlocksPerTrack = %lu\n",de->de_BlocksPerTrack);

			if(de->de_TableSize >= DE_RESERVEDBLKS)
				Printf("dol->dol_Startup->fssm_Environ->de_Reserved = %lu\n",de->de_Reserved);

			if(de->de_TableSize >= DE_PREFAC)
				Printf("dol->dol_Startup->fssm_Environ->de_PreAlloc = %lu\n",de->de_PreAlloc);

			if(de->de_TableSize >= DE_INTERLEAVE)
				Printf("dol->dol_Startup->fssm_Environ->de_Interleave = %lu\n",de->de_Interleave);

			if(de->de_TableSize >= DE_LOWCYL)
				Printf("dol->dol_Startup->fssm_Environ->de_LowCyl = %lu\n",de->de_LowCyl);

			if(de->de_TableSize >= DE_UPPERCYL)
				Printf("dol->dol_Startup->fssm_Environ->de_HighCyl = %lu\n",de->de_HighCyl);

			if(de->de_TableSize >= DE_NUMBUFFERS)
				Printf("dol->dol_Startup->fssm_Environ->de_NumBuffers = %lu\n",de->de_NumBuffers);

			if(de->de_TableSize >= DE_BUFMEMTYPE)
			{
				Printf("dol->dol_Startup->fssm_Environ->de_BufMemType = ");

				print_memory_flags(de->de_BufMemType);
			}

			if(de->de_TableSize >= DE_MAXTRANSFER)
				Printf("dol->dol_Startup->fssm_Environ->de_MaxTransfer = %lu\n",de->de_MaxTransfer);

			if(de->de_TableSize >= DE_MASK)
				Printf("dol->dol_Startup->fssm_Environ->de_Mask = 0x%lx\n",de->de_Mask);

			if(de->de_TableSize >= DE_BOOTPRI)
				Printf("dol->dol_Startup->fssm_Environ->de_BootPri = %ld\n",de->de_BootPri);

			if(de->de_TableSize >= DE_DOSTYPE)
			{
				struct MsgPort * mp;

				Printf("dol->dol_Startup->fssm_Environ->de_DosType = ");
				print_dos_type(de->de_DosType);
				Printf(" 0x%08lx",de->de_DosType);

				mp = CreateMsgPort();
				if(mp != NULL)
				{
					struct IOStdReq * io;

					io = (struct IOStdReq *)CreateIORequest(mp,sizeof(*io));
					if(io != NULL)
					{
						STRPTR device_driver_name = BADDR(fssm->fssm_Device);

						if(OpenDevice(device_driver_name+1,fssm->fssm_Unit,(struct IORequest *)io,fssm->fssm_Flags) == 0)
						{
							ULONG * block;

							block = AllocVec(de->de_SizeBlock * sizeof(LONG),de->de_BufMemType);
							if(block != NULL)
							{
								io->io_Command	= CMD_READ;
								io->io_Data		= block;
								io->io_Offset	= de->de_Surfaces * de->de_BlocksPerTrack * de->de_SizeBlock * sizeof(LONG) * de->de_LowCyl;
								io->io_Length	= de->de_SizeBlock * sizeof(LONG);

								if(DoIO((struct IORequest *)io) == 0)
								{
									if(block[0] != de->de_DosType)
									{
										Printf(" (signature = ");
										print_dos_type(block[0]);

										Printf(" 0x%08lx)",block[0]);
									}
								}

								FreeVec(block);
							}

							CloseDevice((struct IORequest *)io);
						}

						DeleteIORequest((struct IORequest *)io);
					}

					DeleteMsgPort(mp);
				}

				Printf("\n");
			}

			if(de->de_TableSize >= DE_BAUD)
				Printf("dol->dol_Startup->fssm_Environ->de_Baud = %lu\n",de->de_Baud);

			if(de->de_TableSize >= DE_CONTROL)
				Printf("dol->dol_Startup->fssm_Environ->de_Control = \"%b\"\n",de->de_Control);

			if(de->de_TableSize >= DE_BOOTBLOCKS)
				Printf("dol->dol_Startup->fssm_Environ->de_BootBlocks = %lu\n",de->de_BootBlocks);
		}
		else
		{
			Printf("dol->dol_Startup = %ld\n",dol->dol_misc.dol_handler.dol_Startup);
		}

		if(dol->dol_misc.dol_handler.dol_SegList != 0)
			Printf("dol->dol_SegList = 0x%lx\n",BADDR(dol->dol_misc.dol_handler.dol_SegList));
		else
			Printf("dol->dol_SegList = NULL\n");

		if((dol->dol_misc.dol_handler.dol_GlobVec & 0xC0000000) == 0 && TypeOfMem(BADDR(dol->dol_misc.dol_handler.dol_GlobVec)) != 0)
			Printf("dol->dol_GlobVec = 0x%lx\n",BADDR(dol->dol_misc.dol_handler.dol_GlobVec));
		else
			Printf("dol->dol_GlobVec = %ld\n",dol->dol_misc.dol_handler.dol_GlobVec);
	}
	else if (dol->dol_Type == DLT_VOLUME)
	{
		struct DateTime dat;
		char date[LEN_DATSTRING+1];
		char time[LEN_DATSTRING+1];

		dat.dat_Stamp = dol->dol_misc.dol_volume.dol_VolumeDate;
		dat.dat_Format = FORMAT_DOS;
		dat.dat_Flags = 0;
		dat.dat_StrDay = NULL;
		dat.dat_StrDate = date;
		dat.dat_StrTime = time;

		DateToStr(&dat);

		Printf("dol->dol_VolumeDate = %s%s\n",date,time);

		if(dol->dol_misc.dol_volume.dol_LockList != 0)
			Printf("dol->dol_LockList = 0x%lx\n",BADDR(dol->dol_misc.dol_volume.dol_LockList));
		else
			Printf("dol->dol_LockList = NULL\n");

		if(dol->dol_misc.dol_volume.dol_DiskType != 0)
			Printf("dol->dol_DiskType = 0x%lx\n",dol->dol_misc.dol_volume.dol_DiskType);
		else
			Printf("dol->dol_DiskType = 0\n");
	}
	else if (dol->dol_Type == DLT_LATE)
	{
		Printf("dol->dol_AssignName = \"%s\"\n",dol->dol_misc.dol_assign.dol_AssignName);
	}

	Printf("dol->dol_Name = \"%b\"\n",dol->dol_Name);

	result = RETURN_OK;

 out:

	if(dos_list_locked)
		UnLockDosList(LDF_DEVICES|LDF_VOLUMES|LDF_ASSIGNS|LDF_READ);

	return(result);
}
