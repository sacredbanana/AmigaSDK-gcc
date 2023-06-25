/*
 * $Id: fs_print_fsr.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 * :ts=4
 */

#include <resources/filesysres.h>

#include <dos/dos.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

#define NOT !

/****************************************************************************/

static void
make_name_printable(char * from,char * to,int size)
{
	char octal[4];
	int octal_len;
	int len,i,j,c;

	len = strlen(from);
	if(len > (size/4)-1)
		len = (size/4)-1;

	for(i = j = 0 ; i < len ; i++)
	{
		c = from[i];
		if(c < ' ')
		{
			switch(c)
			{
				case '\a':

					to[j++] = '\\';
					to[j++] = 'a';
					break;

				case '\b':

					to[j++] = '\\';
					to[j++] = 'b';
					break;

				case '\f':

					to[j++] = '\\';
					to[j++] = 'f';
					break;

				case '\n':

					to[j++] = '\\';
					to[j++] = 'n';
					break;

				case '\r':

					to[j++] = '\\';
					to[j++] = 'r';
					break;

				case '\t':

					to[j++] = '\\';
					to[j++] = 't';
					break;

				case '\v':

					to[j++] = '\\';
					to[j++] = 'v';
					break;

				default:

					octal_len = 0;

					do
					{
						octal[octal_len++] = '0' + (c & 7);
						c >>= 3;
					}
					while(c > 0);

					to[j++] = '\\';

					while(octal_len > 0)
						to[j++] = octal[--octal_len];

					break;
			}
		}
		else
		{
			to[j++] = c;
		}
	}

	to[j] = '\0';
}

/****************************************************************************/

static void
print_file_system_entry(char * prefix,struct FileSysEntry * fse)
{
	char * dos_type_label;

	if(fse->fse_Node.ln_Name != NULL)
	{
		char entry_name[512];

		make_name_printable(fse->fse_Node.ln_Name,entry_name,sizeof(entry_name));

		printf("%sfse_Node.ln_Name = \"%s\"\n",prefix,entry_name);
	}
	else
	{
		printf("%sfse_Node.ln_Name = NULL\n",prefix);
	}

	switch(fse->fse_DosType)
	{
		case ID_DOS_DISK:

			dos_type_label = " (ID_DOS_DISK)";
			break;

		case ID_FFS_DISK:

			dos_type_label = " (ID_FFS_DISK)";
			break;

		case ID_INTER_DOS_DISK:

			dos_type_label = " (ID_INTER_DOS_DISK)";
			break;

		case ID_INTER_FFS_DISK:

			dos_type_label = " (ID_INTER_FFS_DISK)";
			break;

		case ID_FASTDIR_DOS_DISK:

			dos_type_label = " (ID_FASTDIR_DOS_DISK)";
			break;

		case ID_FASTDIR_FFS_DISK:

			dos_type_label = " (ID_FASTDIR_FFS_DISK)";
			break;

		case 0x444F5306:

			dos_type_label = " (ID_LONGNAME_DOS_DISK)";
			break;

		case 0x444F5307:

			dos_type_label = " (ID_LONGNAME_FFS_DISK)";
			break;

		case ID_MSDOS_DISK:

			dos_type_label = " (ID_MSDOS_DISK)";
			break;

		case 0x554E4900:

			dos_type_label = " (Amiga Unix boot)";
			break;

		case 0x554E4901:

			dos_type_label = " (Amiga Unix partition)";
			break;

		default:

			dos_type_label = "";
			break;
	}

	printf("%sfse_DosType = 0x%08lx%s\n",prefix,fse->fse_DosType,dos_type_label);

	if(fse->fse_Version != 0)
		printf("%sfse_Version = %ld.%ld\n",prefix,fse->fse_Version >> 16,fse->fse_Version & 0xFFFF);
	else
		printf("%sfse_Version = (none given)\n",prefix);

	if(fse->fse_PatchFlags != 0)
	{
		if(fse->fse_PatchFlags <= 0x1ff)
			printf("%sfse_PatchFlags = 0x%03lx\n",prefix,fse->fse_PatchFlags);
		else
			printf("%sfse_PatchFlags = 0x%08lx\n",prefix,fse->fse_PatchFlags);

		if(fse->fse_PatchFlags & (1<<0))
			printf("%sfse_Type = %ld\n",prefix,fse->fse_Type);

		if(fse->fse_PatchFlags & (1<<1))
			printf("%sfse_Task = 0x%08lx\n",prefix,fse->fse_Task);

		if(fse->fse_PatchFlags & (1<<2))
			printf("%sfse_Lock = 0x%08lx\n",prefix,fse->fse_Lock);

		if(fse->fse_PatchFlags & (1<<3))
		{
			UBYTE * name;

			printf("%sfse_Handler = 0x%08lx",prefix,(ULONG)BADDR(fse->fse_Handler));

			name = BADDR(fse->fse_Handler);
			if(TypeOfMem(name) != 0)
			{
				char handler_name[256];
				int len;

				len = (*name++);
				memcpy(handler_name,name,(size_t)len);
				handler_name[len] = '\0';

				printf(" (\"%s\")",handler_name);
			}

			printf("\n");
		}

		if(fse->fse_PatchFlags & (1<<4))
			printf("%sfse_StackSize = %ld\n",prefix,fse->fse_StackSize);

		if(fse->fse_PatchFlags & (1<<5))
			printf("%sfse_Priority = %ld\n",prefix,fse->fse_Priority);

		if(fse->fse_PatchFlags & (1<<6))
			printf("%sfse_Startup = 0x%08lx\n",prefix,(ULONG)BADDR(fse->fse_Startup));

		if(fse->fse_PatchFlags & (1<<7))
			printf("%sfse_SegList = 0x%08lx\n",prefix,(ULONG)BADDR(fse->fse_SegList));

		if(fse->fse_PatchFlags & (1<<8))
			printf("%sfse_GlobalVec = %ld\n",prefix,fse->fse_GlobalVec);
	}
}

/****************************************************************************/

int
main(int argc,char ** argv)
{
	struct FileSysResource * fsr;
	char creator_name[512];

	fsr = (struct FileSysResource *)OpenResource(FSRNAME);
	if(fsr == NULL)
	{
		printf("%s is not initialized yet.\n",FSRNAME);
		return(RETURN_WARN);
	}

	printf("fsr = 0x%08lx\n",(ULONG)fsr);

	make_name_printable(fsr->fsr_Creator,creator_name,sizeof(creator_name));

	printf("fsr->fsr_Creator = \"%s\"\n",creator_name);

	if(NOT IsListEmpty(&fsr->fsr_FileSysEntries))
	{
		struct FileSysEntry * fse;
		char prefix[80];
		LONG count;

		count = 0;
		for(fse = (struct FileSysEntry *)fsr->fsr_FileSysEntries.lh_Head ;
		    fse->fse_Node.ln_Succ != NULL ;
		    fse = (struct FileSysEntry *)fse->fse_Node.ln_Succ)
		{
			printf("\nfsr->fsr_FileSysEntries[%ld] = 0x%08lx\n",count,(ULONG)fse);
			sprintf(prefix,"fsr->fsr_FileSysEntries[%ld]->",count);

			print_file_system_entry(prefix,fse);

			count++;
		}
	}
	else
	{
		printf("The file system entry list is empty.\n");
	}

	return(RETURN_OK);
}
