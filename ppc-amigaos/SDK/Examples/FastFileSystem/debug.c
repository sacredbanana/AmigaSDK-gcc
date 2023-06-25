/*
 *	$Id: debug.c,v 1.1 2008-09-15 13:14:19 sarcher Exp $
 *
 *	:ts=4
 *
 *	Amiga ROM file system reimplementation
 *	Copyright © 2001-2005 by Olaf Barthel
 *	All Rights Reserved
 *
 *	"A man of genius makes no mistakes. His errors are volitional
 *	 and are the portals of discovery."
 */

#ifndef _SYSTEM_HEADERS_H
#include "system_headers.h"
#endif /* _SYSTEM_HEADERS_H */

/****************************************************************************/

#ifndef DOS_DATETIME_H
#include <dos/datetime.h>
#endif /* DOS_DATETIME_H */

/****************************************************************************/

#ifndef _COMPILER_H
#include "compiler.h"
#endif /* _COMPILER_H */

#ifndef _MACROS_H
#include "macros.h"
#endif /* _MACROS_H */

#ifndef _ERRORS_H
#include "errors.h"
#endif /* _ERRORS_H */

#ifndef _FILE_H
#include "file.h"
#endif /* _FILE_H */

#ifndef _DIR_H
#include "dir.h"
#endif /* _DIR_H */

#ifndef _FS_H
#include "fs.h"
#endif /* _FS_H */

/****************************************************************************/

#include "assert.h"

/****************************************************************************/

#if DEBUG

/****************************************************************************/

#ifdef __SASC
void __regargs __chkabort(void) {}
#endif /* __SASC */

/****************************************************************************/

char *
date_stamp_to_string(struct DateStamp * ds)
{
	static char complete_string[50];

	struct Library * SysBase = (struct Library *)AbsExecBase;
	struct Library * DOSBase = NULL;
	#if defined(__amigaos4__)
	struct ExecIFace *IExec = (struct ExecIFace *)((struct ExecBase *)SysBase)->MainInterface;
	struct DOSIFace *IDOS = NULL;
	#endif /* __amigaos4__ */

	char date_string[20];
	char time_string[20];
	struct DateTime dat;
	BOOL date_converted = FALSE;

	dat.dat_Stamp	= (*ds);
	dat.dat_Format	= FORMAT_DOS;
	dat.dat_Flags	= 0;
	dat.dat_StrDay	= NULL;
	dat.dat_StrDate	= date_string;
	dat.dat_StrTime	= time_string;

	DOSBase = OpenLibrary("dos.library",36);
	if(DOSBase == NULL)
		goto out;

	#if defined(__amigaos4__)
	{
		IDOS = (struct DOSIFace *)GetInterface(DOSBase, "main", 1, NULL);
		if(IDOS == NULL)
			goto out;
	}
	#endif /* __amigaos4__ */

	DateToStr(&dat);

	date_converted = TRUE;

 out:

	if(NOT date_converted)
	{
		strcpy(time_string,"##:##:##");
		strcpy(date_string,"##-###-##");
	}

	strcpy(complete_string,time_string);
	strcat(complete_string," ");
	strcat(complete_string,date_string);

	#if defined(__amigaos4__)
	{
		if(IDOS != NULL)
			DropInterface((struct Interface *)IDOS);
	}
	#endif /* __amigaos4__ */

	if(DOSBase != NULL)
		CloseLibrary(DOSBase);

	return(complete_string);
}

char *
bcpl_string_to_c_string(char * bcpl_string)
{
	static char c_string[256];
	int len;

	len = *(unsigned char *)bcpl_string;
	if(len > sizeof(c_string)-1)
		len = sizeof(c_string)-1;

	memcpy(c_string,bcpl_string+1,len);
	c_string[len] = '\0';

	return(c_string);
}

char *
protection_to_string(unsigned long protection)
{
	static char * flags = "dewrapshdewrdewr";
	static char str[40];
	int i,j,c,len;

	protection ^= (FIBF_READ|FIBF_WRITE|FIBF_EXECUTE|FIBF_DELETE);

	for(i = j = 0 ; i <= FIBB_OTR_READ ; i++)
	{
		if(i == FIBB_GRP_DELETE || i == FIBB_OTR_DELETE)
			str[j++] = ' ';

		if(protection & (1UL << i))
			str[j++] = flags[i];
		else
			str[j++] = '-';
	}

	len = j;
	for(i = 0 ; i < len/2 ; i++)
	{
		c				= str[len-1-i];
		str[len-1-i]	= str[i];
		str[i]			= c;
	}

	str[len] = '\0';

	return(str);
}

char *
number_to_binary(unsigned long number,int size)
{
	static char bin[34];
	int i,len;

	len = 0;

	for(i = 0 ; i < 8 * size ; i++)
		bin[len++] = '0' + ((number & (1UL << (8 * size - 1 - i))) != 0);

	bin[len] = '\0';

	return(bin);
}

/****************************************************************************/

void
print_root_dir(struct FileSystemData * fsd,struct RootDirBlock * rdb)
{
	LONG i;

	ASSERT(fsd != NULL && rdb != NULL);

	PRINTF(("rdb_PrimaryType        = %ld\n",rdb->rdb_PrimaryType));
	PRINTF(("rdb_HashTableSize      = %ld\n",rdb->rdb_HashTableSize));
	PRINTF(("rdb_Checksum           = 0x%08lx\n",rdb->rdb_Checksum));

	for(i = 0 ; i < rdb->rdb_HashTableSize ; i++)
	{
		if(rdb->rdb_HashTable[i] != 0)
			PRINTF((" rdb_HashTable[%4ld]   = %11ld (0x%08lx)\n",i,rdb->rdb_HashTable[i],rdb->rdb_HashTable[i]));
	}

	PRINTF(("rdb_BitMapFlag         = %ld (%s)\n",rdb->rdb_BitMapFlag,rdb->rdb_BitMapFlag == 0 ? "invalid" : "valid"));

	if(fsd->fsd_IsFastFileSystem)
	{
		for(i = 0 ; i < NUM_ENTRIES(rdb->rdb_BitMapBlocks) ; i++)
		{
			if(rdb->rdb_BitMapBlocks[i] != 0)
				PRINTF((" rdb_BitMapBlocks[%4ld]= %11ld (0x%08lx)\n",i,rdb->rdb_BitMapBlocks[i],rdb->rdb_BitMapBlocks[i]));
		}

		PRINTF(("rdb_BitMapExtension    = %11ld (0x%08lx)\n",rdb->rdb_BitMapExtension,rdb->rdb_BitMapExtension));
	}
	else
	{
		for(i = 0 ; i < NUM_ENTRIES(rdb->rdb_BitMapBlocks)+1 ; i++)
		{
			if(rdb->rdb_BitMapBlocks[i] != 0)
				PRINTF((" rdb_BitMapBlocks[%4ld]      = %11ld (0x%08lx)\n",i,rdb->rdb_BitMapBlocks[i],rdb->rdb_BitMapBlocks[i]));
		}
	}

	PRINTF(("rdb_LastChange         = %s\n",date_stamp_to_string(&rdb->rdb_LastChange)));
	PRINTF(("rdb_Name               = '%s'\n",bcpl_string_to_c_string(rdb->rdb_Name)));

	if(fsd->fsd_IsFastFileSystem)
		PRINTF(("rdb_LastVolumeChange   = %s\n",date_stamp_to_string(&rdb->rdb_LastVolumeChange)));

	PRINTF(("rdb_DiskInitialization = %s\n",date_stamp_to_string(&rdb->rdb_DiskInitialization)));

	if(fsd->fsd_IsDirCache)
		PRINTF(("rdb_FirstDirList       = %11ld (0x%08lx)\n",rdb->rdb_FirstDirList,rdb->rdb_FirstDirList));

	PRINTF(("rdb_SecondaryType      = %ld\n",rdb->rdb_SecondaryType));
}

void
print_user_dir(struct FileSystemData * fsd,struct UserDirBlock * udb)
{
	LONG i;

	ASSERT(fsd != NULL && udb != NULL);

	PRINTF(("udb_PrimaryType        = %ld\n",udb->udb_PrimaryType));
	PRINTF(("udb_OwnBlockNumber     = %11ld (0x%08lx)\n",udb->udb_OwnBlockNumber,udb->udb_OwnBlockNumber));
	PRINTF(("udb_Checksum           = 0x%08lx\n",udb->udb_Checksum));

	for(i = 0 ; i < fsd->fsd_HashTableSize ; i++)
	{
		if(udb->udb_HashTable[i] != 0)
			PRINTF((" udb_HashTable[%04ld]   = %11ld (0x%08lx)\n",i,udb->udb_HashTable[i],udb->udb_HashTable[i]));
	}

	PRINTF(("udb_OwnerGroupID       = %ld:%ld (0x%04lx:0x%04lx)\n",udb->udb_OwnerGroupID >> 16,udb->udb_OwnerGroupID & 0xFFFF,udb->udb_OwnerGroupID >> 16,udb->udb_OwnerGroupID & 0xFFFF));
	PRINTF(("udb_Protection         = %s (%%%s)\n",protection_to_string(udb->udb_Protection),number_to_binary(udb->udb_Protection,sizeof(udb->udb_Protection))));
	PRINTF(("udb_Comment            = '%s'\n",bcpl_string_to_c_string(udb->udb_Comment)));
	PRINTF(("udb_LastChange         = %s\n",date_stamp_to_string(&udb->udb_LastChange)));
	PRINTF(("udb_Name               = '%s'\n",bcpl_string_to_c_string(udb->udb_Name)));
	PRINTF(("udb_FirstLink          = %11ld (0x%08lx)\n",udb->udb_FirstLink,udb->udb_FirstLink));
	PRINTF(("udb_NextHashChainEntry = %11ld (0x%08lx)\n",udb->udb_NextHashChainEntry,udb->udb_NextHashChainEntry));
	PRINTF(("udb_ParentDir          = %11ld (0x%08lx)\n",udb->udb_ParentDir,udb->udb_ParentDir));

	if(fsd->fsd_IsDirCache)
		PRINTF(("udb_FirstDirList = %11ld (0x%08lx)\n",udb->udb_FirstDirList,udb->udb_FirstDirList));

	PRINTF(("udb_SecondaryType      = %ld\n",udb->udb_SecondaryType));
}

void
print_file_header(struct FileSystemData * fsd,struct FileHeaderBlock * fhb)
{
	LONG i;

	ASSERT(fsd != NULL && fhb != NULL);

	PRINTF(("fhb_PrimaryType        = %ld\n",fhb->fhb_PrimaryType));
	PRINTF(("fhb_OwnBlockNumber     = %11ld (0x%08lx)\n",fhb->fhb_OwnBlockNumber,fhb->fhb_OwnBlockNumber));
	PRINTF(("fhb_NumDataBlocks      = %ld\n",fhb->fhb_NumDataBlocks));
	PRINTF(("fhb_FirstDataBlock     = %11ld (0x%08lx)\n",fhb->fhb_FirstDataBlock,fhb->fhb_FirstDataBlock));
	PRINTF(("fhb_Checksum           = 0x%08lx\n",fhb->fhb_Checksum));

	for(i = fsd->fsd_MaxDataBlocks-1 ; i >= 0 ; i--)
	{
		if(fhb->fhb_DataBlocks[i] != 0)
			PRINTF((" fhb_DataBlocks[%4ld]  = %11ld (0x%08lx)\n",i,fhb->fhb_DataBlocks[i],fhb->fhb_DataBlocks[i]));
	}

	PRINTF(("fhb_OwnerGroupID       = %ld:%ld (0x%04lx:0x%04lx)\n",fhb->fhb_OwnerGroupID >> 16,fhb->fhb_OwnerGroupID & 0xFFFF,fhb->fhb_OwnerGroupID >> 16,fhb->fhb_OwnerGroupID & 0xFFFF));
	PRINTF(("fhb_Protection         = %s (%%%s)\n",protection_to_string(fhb->fhb_Protection),number_to_binary(fhb->fhb_Protection,sizeof(fhb->fhb_Protection))));
	PRINTF(("fhb_ByteSize           = %ld\n",fhb->fhb_ByteSize));
	PRINTF(("fhb_Comment            = '%s'\n",bcpl_string_to_c_string(fhb->fhb_Comment)));
	PRINTF(("fhb_LastChange         = %s\n",date_stamp_to_string(&fhb->fhb_LastChange)));
	PRINTF(("fhb_Name               = '%s'\n",bcpl_string_to_c_string(fhb->fhb_Name)));
	PRINTF(("fhb_FirstLink          = %11ld (0x%08lx)\n",fhb->fhb_FirstLink,fhb->fhb_FirstLink));
	PRINTF(("fhb_NextHashChainEntry = %11ld (0x%08lx)\n",fhb->fhb_NextHashChainEntry,fhb->fhb_NextHashChainEntry));
	PRINTF(("fhb_ParentDir          = %11ld (0x%08lx)\n",fhb->fhb_ParentDir,fhb->fhb_ParentDir));
	PRINTF(("fhb_FirstExtension     = %11ld (0x%08lx)\n",fhb->fhb_FirstExtension,fhb->fhb_FirstExtension));
	PRINTF(("fhb_SecondaryType      = %ld\n",fhb->fhb_SecondaryType));
}

void
print_file_extension(struct FileSystemData * fsd,struct FileExtensionBlock * feb)
{
	LONG i;

	ASSERT(fsd != NULL && feb != NULL);

	PRINTF(("feb_PrimaryType        = %ld\n",feb->feb_PrimaryType));
	PRINTF(("feb_OwnBlockNumber     = %11ld (0x%08lx)\n",feb->feb_OwnBlockNumber,feb->feb_OwnBlockNumber));
	PRINTF(("feb_NumDataBlocks      = %ld\n",feb->feb_NumDataBlocks));
	PRINTF(("feb_Checksum           = 0x%08lx\n",feb->feb_Checksum));

	for(i = fsd->fsd_MaxDataBlocks-1 ; i >= 0 ; i--)
	{
		if(feb->feb_DataBlocks[i] != 0)
			PRINTF((" feb_DataBlocks[%4ld]  = %11ld (0x%08lx)\n",i,feb->feb_DataBlocks[i],feb->feb_DataBlocks[i]));
	}

	PRINTF(("feb_FileHeader         = %11ld (0x%08lx)\n",feb->feb_FileHeader,feb->feb_FileHeader));
	PRINTF(("feb_NextExtension      = %11ld (0x%08lx)\n",feb->feb_NextExtension,feb->feb_NextExtension));
	PRINTF(("feb_SecondaryType      = %ld\n",feb->feb_SecondaryType));
}

void
print_file_data(struct FileSystemData * fsd,struct FileDataBlock * fdb)
{
	ASSERT(fsd != NULL && fdb != NULL);

	PRINTF(("fdb_PrimaryType    = %ld\n",fdb->fdb_PrimaryType));
	PRINTF(("fdb_FileBlock      = %11ld (0x%08lx)\n",fdb->fdb_FileBlock,fdb->fdb_FileBlock));
	PRINTF(("fdb_SequenceNumber = %ld\n",fdb->fdb_SequenceNumber));
	PRINTF(("fdb_DataSize       = %ld\n",fdb->fdb_DataSize));
	PRINTF(("fdb_NextDataBlock  = %11ld (0x%08lx)\n",fdb->fdb_NextDataBlock,fdb->fdb_NextDataBlock));
	PRINTF(("fdb_Checksum       = 0x%08lx\n",fdb->fdb_Checksum));
}

void
print_hard_link(struct FileSystemData * fsd,struct HardLinkBlock * hlb)
{
	ASSERT(fsd != NULL && hlb != NULL);

	PRINTF(("hlb_PrimaryType        = %ld\n",hlb->hlb_PrimaryType));
	PRINTF(("hlb_OwnBlockNumber     = %11ld (0x%08lx)\n",hlb->hlb_OwnBlockNumber,hlb->hlb_OwnBlockNumber));
	PRINTF(("hlb_Checksum           = 0x%08lx\n",hlb->hlb_Checksum));
	PRINTF(("hlb_OwnerGroupID       = %ld:%ld (0x%04lx:0x%04lx)\n",hlb->hlb_OwnerGroupID >> 16,hlb->hlb_OwnerGroupID & 0xFFFF,hlb->hlb_OwnerGroupID >> 16,hlb->hlb_OwnerGroupID & 0xFFFF));
	PRINTF(("hlb_Protection         = %s (%%%s)\n",protection_to_string(hlb->hlb_Protection),number_to_binary(hlb->hlb_Protection,sizeof(hlb->hlb_Protection))));
	PRINTF(("hlb_Comment            = '%s'\n",bcpl_string_to_c_string(hlb->hlb_Comment)));
	PRINTF(("hlb_LastChange         = %s\n",date_stamp_to_string(&hlb->hlb_LastChange)));
	PRINTF(("hlb_Name               = '%s'\n",bcpl_string_to_c_string(hlb->hlb_Name)));
	PRINTF(("hlb_Original           = %11ld (0x%08lx)\n",hlb->hlb_Original,hlb->hlb_Original));
	PRINTF(("hlb_NextLink           = %11ld (0x%08lx)\n",hlb->hlb_NextLink,hlb->hlb_NextLink));
	PRINTF(("hlb_NextHashChainEntry = %11ld (0x%08lx)\n",hlb->hlb_NextHashChainEntry,hlb->hlb_NextHashChainEntry));
	PRINTF(("hlb_ParentDir          = %11ld (0x%08lx)\n",hlb->hlb_ParentDir,hlb->hlb_ParentDir));
	PRINTF(("hlb_SecondaryType      = %ld\n",hlb->hlb_SecondaryType));
}

void
print_soft_link(struct FileSystemData * fsd,struct SoftLinkBlock * slb)
{
	ASSERT(fsd != NULL && slb != NULL);

	PRINTF(("slb_PrimaryType        = %ld\n",slb->slb_PrimaryType));
	PRINTF(("slb_OwnBlockNumber     = %11ld (0x%08lx)\n",slb->slb_OwnBlockNumber,slb->slb_OwnBlockNumber));
	PRINTF(("slb_Checksum           = 0x%08lx\n",slb->slb_Checksum));
	PRINTF(("slb_SymbolicName       = '%s'\n",slb->slb_SymbolicName));
	PRINTF(("slb_OwnerGroupID       = %ld:%ld (0x%04lx:0x%04lx)\n",slb->slb_OwnerGroupID >> 16,slb->slb_OwnerGroupID & 0xFFFF,slb->slb_OwnerGroupID >> 16,slb->slb_OwnerGroupID & 0xFFFF));
	PRINTF(("slb_Protection         = %s (%%%s)\n",protection_to_string(slb->slb_Protection),number_to_binary(slb->slb_Protection,sizeof(slb->slb_Protection))));
	PRINTF(("slb_Comment            = '%s'\n",bcpl_string_to_c_string(slb->slb_Comment)));
	PRINTF(("slb_LastChange         = %s\n",date_stamp_to_string(&slb->slb_LastChange)));
	PRINTF(("slb_Name               = '%s'\n",bcpl_string_to_c_string(slb->slb_Name)));
	PRINTF(("slb_NextHashChainEntry = %11ld (0x%08lx)\n",slb->slb_NextHashChainEntry,slb->slb_NextHashChainEntry));
	PRINTF(("slb_ParentDir          = %11ld (0x%08lx)\n",slb->slb_ParentDir,slb->slb_ParentDir));
	PRINTF(("slb_SecondaryType      = %ld\n",slb->slb_SecondaryType));
}

void
print_dir_list(struct FileSystemData * fsd,struct DirListBlock * dlb)
{
	struct DirListScanContext dsc;
	BOOL have_list_entry;
	errorcode_t error;

	ASSERT(fsd != NULL && dlb != NULL);

	PRINTF(("dlb_PrimaryType       = %ld\n",dlb->dlb_PrimaryType));
	PRINTF(("dlb_OwnBlockNumber    = %11ld (0x%08lx)\n",dlb->dlb_OwnBlockNumber,dlb->dlb_OwnBlockNumber));
	PRINTF(("dlb_Dir               = %11ld (0x%08lx)\n",dlb->dlb_Dir,dlb->dlb_Dir));
	PRINTF(("dlb_NumEntries        = %ld\n",dlb->dlb_NumEntries));
	PRINTF(("dlb_NextDirList       = %11ld (0x%08lx)\n",dlb->dlb_NextDirList,dlb->dlb_NextDirList));
	PRINTF(("dlb_Checksum          = 0x%08lx\n",dlb->dlb_Checksum));

	error = get_first_dir_list_entry(dlb,&dsc,&have_list_entry);
	while(error == 0 && have_list_entry)
	{
		struct DateStamp ds;

		ds.ds_Days		= dsc.dsc_Entry->dle_LastChange.sds_Days;
		ds.ds_Minute	= dsc.dsc_Entry->dle_LastChange.sds_Minute;
		ds.ds_Tick		= dsc.dsc_Entry->dle_LastChange.sds_Tick;

		PRINTF((" dlb_DirList[%4ld] offset           = %11ld (0x%08lx)\n",dsc.dsc_Index,dsc.dsc_ByteOffset,dsc.dsc_ByteOffset));
		PRINTF((" dlb_DirList[%4ld] size             = %11ld (0x%08lx)\n",dsc.dsc_Index,dsc.dsc_ByteSize,dsc.dsc_ByteSize));
		PRINTF((" dlb_DirList[%4ld].dle_BlockNumber  = %11ld (0x%08lx)\n",dsc.dsc_Index,dsc.dsc_Entry->dle_BlockNumber,dsc.dsc_Entry->dle_BlockNumber));
		PRINTF((" dlb_DirList[%4ld].dle_ByteSize     = %ld\n",dsc.dsc_Index,dsc.dsc_Entry->dle_ByteSize));
		PRINTF((" dlb_DirList[%4ld].dle_Protection   = %s (%%%s)\n",dsc.dsc_Index,protection_to_string(dsc.dsc_Entry->dle_Protection),number_to_binary(dsc.dsc_Entry->dle_Protection,sizeof(dsc.dsc_Entry->dle_Protection))));
		PRINTF((" dlb_DirList[%4ld].dle_OwnerGroupID = %ld:%ld (0x%04lx:0x%04lx)\n",dsc.dsc_Index,dsc.dsc_Entry->dle_OwnerGroupID >> 16,dsc.dsc_Entry->dle_OwnerGroupID & 0xFFFF,dsc.dsc_Entry->dle_OwnerGroupID >> 16,dsc.dsc_Entry->dle_OwnerGroupID & 0xFFFF));
		PRINTF((" dlb_DirList[%4ld].dle_LastChange   = %s\n",dsc.dsc_Index,date_stamp_to_string(&ds)));
		PRINTF((" dlb_DirList[%4ld].dle_Type         = %ld\n",dsc.dsc_Index,dsc.dsc_Entry->dle_Type));
		PRINTF((" dlb_DirList[%4ld].dle_Name         = '%s'\n",dsc.dsc_Index,bcpl_string_to_c_string(dsc.dsc_Name)));
		PRINTF((" dlb_DirList[%4ld].dle_Comment      = '%s'\n",dsc.dsc_Index,bcpl_string_to_c_string(dsc.dsc_Comment)));

		error = get_next_dir_list_entry(fsd,dlb,&dsc,&have_list_entry);
	}
}

/****************************************************************************/

void
print_error_code(errorcode_t error)
{
	static struct { errorcode_t error; STRPTR name; STRPTR description; } error_code_table[] =
	{
		{ ERR_Not_enough_memory,	"ERR_Not_enough_memory",	"Not enough memory" },
		{ ERR_No_signal,	"ERR_No_signal",	"AllocSignal() failed" },
		{ ERR_No_MsgPort,	"ERR_No_MsgPort",	"CreateMsgPort() failed" },
		{ ERR_No_IORequest,	"ERR_No_IORequest",	"CreateIORequest() failed" },
		{ ERR_Invalid_environment,	"ERR_Invalid_environment",	"A file system's 'struct DosEnvec' is invalid" },
		{ ERR_No_local_memory,	"ERR_No_local_memory",	"Special local memory could not be allocated" },
		{ ERR_Read_out_of_bounds,	"ERR_Read_out_of_bounds",	"Block read is out of bounds" },
		{ ERR_Write_out_of_bounds,	"ERR_Write_out_of_bounds",	"Block write is out of bounds" },
		{ ERR_Invalid_max_transfer,	"ERR_Invalid_max_transfer",	"Device MaxTransfer value is too small" },
		{ ERR_Partition_too_large,	"ERR_Partition_too_large",	"Partition access requires 64 bit math, yet low level driver does not support 64 bit sector offset addressing." },
		{ ERR_No_memory_for_cache_block,	"ERR_No_memory_for_cache_block",	"Not enough memory to allocate a cache block." },
		{ ERR_Invalid_block_size,	"ERR_Invalid_block_size",	"Block size is not a multiple of 512." },
		{ ERR_Invalid_sector_size,	"ERR_Invalid_sector_size",	"Sector size is not a multiple of 512." },
		{ ERR_Illegal_number_of_sectors_per_block,	"ERR_Illegal_number_of_sectors_per_block",	"The number of sectors per block can only be a power of two out of [0..6]." },
		{ ERR_Invalid_root_dir_checksum,	"ERR_Invalid_root_dir_checksum",	"Checksum of root directory is invalid" },
		{ ERR_Invalid_user_dir_checksum,	"ERR_Invalid_user_dir_checksum",	"Checksum of user directory is invalid" },
		{ ERR_Invalid_file_header_checksum,	"ERR_Invalid_file_header_checksum",	"Checksum of file header is invalid" },
		{ ERR_Invalid_file_extension_checksum,	"ERR_Invalid_file_extension_checksum",	"Checksum of file extension block is invalid" },
		{ ERR_Invalid_file_data_checksum,	"ERR_Invalid_file_data_checksum",	"Checksum of data block is invalid" },
		{ ERR_Invalid_hard_link_checksum,	"ERR_Invalid_hard_link_checksum",	"Checksum of hard link block is invalid" },
		{ ERR_Invalid_soft_link_checksum,	"ERR_Invalid_soft_link_checksum",	"Checksum of soft link block is invalid" },
		{ ERR_Invalid_dir_list_checksum,	"ERR_Invalid_dir_list_checksum",	"Checksum of dirlist block is invalid" },
		{ ERR_Invalid_bitmap_checksum,	"ERR_Invalid_bitmap_checksum",	"Checksum of bitmap block is invalid" },
		{ ERR_Invalid_user_dir_block_number,	"ERR_Invalid_user_dir_block_number",	"The block number stored in a user directory block does not point back it itself." },
		{ ERR_Invalid_file_header_block_number,	"ERR_Invalid_file_header_block_number",	"The block number stored in a file header block does not point back it itself." },
		{ ERR_Invalid_file_extension_block_number,	"ERR_Invalid_file_extension_block_number",	"The block number stored in a file extension block does not point back it itself." },
		{ ERR_Invalid_hard_link_block_number,	"ERR_Invalid_hard_link_block_number",	"The block number stored in a hard link block does not point back it itself." },
		{ ERR_Invalid_soft_link_block_number,	"ERR_Invalid_soft_link_block_number",	"The block number stored in a soft link block does not point back it itself." },
		{ ERR_Invalid_dir_list_block_number,	"ERR_Invalid_dir_list_block_number",	"The block number stored in a dirlist block does not point back it itself." },
		{ ERR_Block_number_too_low,	"ERR_Block_number_too_low",	"The block number is lower than the number of reserved blocks at the beginning of the partition." },
		{ ERR_Block_number_too_high,	"ERR_Block_number_too_high",	"The block number is greater than the last block of the partition." },
		{ ERR_Object_has_no_parent,	"ERR_Object_has_no_parent",	"The directory/file/whatever has no parent directory." },
		{ ERR_Cannot_resolve_soft_link,	"ERR_Cannot_resolve_soft_link",	"The file system cannot resolve any soft links." },
		{ ERR_Object_not_found,	"ERR_Object_not_found",	"Object not found." },
		{ ERR_Not_a_directory,	"ERR_Not_a_directory",	"A directory object was expected but didn't turn up." },
		{ ERR_Object_has_no_name,	"ERR_Object_has_no_name",	"The operations to follow could only be performed on directory entries with names. But the block type found does not bear a name." },
		{ ERR_Circular_hard_link_reference,	"ERR_Circular_hard_link_reference",	"A chain of links points back to its starting point." },
		{ ERR_Not_a_file,	"ERR_Not_a_file",	"The operation to follow can be done only on a file, but what was found is something else." },
		{ ERR_Unknown_position_mode,	"ERR_Unknown_position_mode",	"The seek position mode is none of the supported kinds." },
		{ ERR_Not_a_file_or_extension_block,	"ERR_Not_a_file_or_extension_block",	"A file header or file extension block was called for, but what was found was neither." },
		{ ERR_File_extension_block_missing,	"ERR_File_extension_block_missing",	"A file extension block was expected but the linked list of blocks ended prematurely." },
		{ ERR_Extension_block_in_wrong_file,	"ERR_Extension_block_in_wrong_file",	"The file extension block does not belong to the file currently being processed." },
		{ ERR_Invalid_file_position,	"ERR_Invalid_file_position",	"The file access position is not within the limits of the file." },
		{ ERR_Not_a_data_block,	"ERR_Not_a_data_block",	"A file data block was called for, but what was found is something different." },
		{ ERR_File_header_block_mismatch,	"ERR_File_header_block_mismatch",	"The file header block found does not correspond to the file currently being processed." },
		{ ERR_Sequence_number_mismatch,	"ERR_Sequence_number_mismatch",	"The data block sequence number does not match the expected value." },
		{ ERR_Not_enough_data_in_block,	"ERR_Not_enough_data_in_block",	"There is less information in a file data block than was called for." },
		{ ERR_Too_much_data_in_block,	"ERR_Too_much_data_in_block",	"There is more information in a file data block than the block could hold." },
		{ ERR_Not_enough_data_in_file,	"ERR_Not_enough_data_in_file",	"Fewer data blocks were found than are necessary to store all the data in a file." },
		{ ERR_Directory_list_missing,	"ERR_Directory_list_missing",	"A dirlist block that was expected to be available isn't there." },
		{ ERR_Not_a_directory_list_block,	"ERR_Not_a_directory_list_block",	"A dirlist block was called for, but what was found is something different." },
		{ ERR_No_memory_for_bitmap_block,	"ERR_No_memory_for_bitmap_block",	"The file system does not have enough memory to allocate room for another bitmap block." },
		{ ERR_Too_many_bitmap_blocks,	"ERR_Too_many_bitmap_blocks",	"The file system is too large for all required bitmap blocks to fit." },
		{ ERR_Block_is_already_free,	"ERR_Block_is_already_free",	"The block to be marked as allocatable has not been allocated yet." },
		{ ERR_Not_enough_blocks_free,	"ERR_Not_enough_blocks_free",	"The operation to follow cannot be completed for lack of blocks available for allocation." },
		{ ERR_Block_is_already_allocated,	"ERR_Block_is_already_allocated",	"The block to be marked as allocated is already allocated." },
		{ ERR_Name_too_long,	"ERR_Name_too_long",	"The name is longer than can be stored." },
		{ ERR_Name_too_short,	"ERR_Name_too_short",	"The name is too short to be useful." },
		{ ERR_Object_already_exists,	"ERR_Object_already_exists",	"Object already exists." },
		{ ERR_Path_not_found,	"ERR_Path_not_found",	"The fully qualified name of an object is invalid because at least one directory on the path does not exist." },
		{ ERR_No_room_in_directory_list,	"ERR_No_room_in_directory_list",	"The linked list of dirlist blocks has no more room for another entry." },
		{ ERR_Link_target_not_supported,	"ERR_Link_target_not_supported",	"The object to link to does not support links." },
		{ ERR_Directory_not_empty,	"ERR_Directory_not_empty",	"The directory to remove still has data in it." },
		{ ERR_Link_does_not_point_back_to_object,	"ERR_Link_does_not_point_back_to_object",	"The object the hard link points to is not the one that it should reference." },
		{ ERR_Link_type_does_not_match_object,	"ERR_Link_type_does_not_match_object",	"The hard link points to the wrong kind of object, i.e. a file instead of the expected directory or the other way round." },
		{ ERR_Not_a_hard_link,	"ERR_Not_a_hard_link",	"A hard link block was expected, but what was found is something different." },
		{ ERR_Directory_list_entry_not_found,	"ERR_Directory_list_entry_not_found",	"The expected dirlist entry was not found." },
		{ ERR_Cannot_move_directory_into_itself,	"ERR_Cannot_move_directory_into_itself",	"A rename operation attempts to move a a directory into itself or one of its children." },
		{ ERR_Invalid_name,	"ERR_Invalid_name",	"A volume or file name contains characters that should not be there." },
		{ ERR_Comment_too_long,	"ERR_Comment_too_long",	"The comment is too long to be stored." },
		{ ERR_Unknown_file_system_type,	"ERR_Unknown_file_system_type",	"The type of the file system is not supported by this implementation." },
		{ ERR_Block_is_not_root_directory,	"ERR_Block_is_not_root_directory",	"What was supposed to be the root directory is something else." },
		{ ERR_Hard_link_references_wrong_type_of_object,	"ERR_Hard_link_references_wrong_type_of_object",	"The hard link does not point to a file or directory block." },
		{ ERR_Soft_link_target_name_too_long,	"ERR_Soft_link_target_name_too_long",	"The name of the object a soft link should refer to is too long to fit." },
		{ ERR_Soft_link_target_name_too_short,	"ERR_Soft_link_target_name_too_short",	"The name of the object a soft link should refer to is too short to make good sense." },
		{ ERR_Not_a_soft_link,	"ERR_Not_a_soft_link",	"Whatever it is, it is not a soft link block." },
		{ ERR_Root_directory_in_wrong_place,	"ERR_Root_directory_in_wrong_place",	"The root directory was not found where it was expected to reside." },
		{ ERR_File_too_large,	"ERR_File_too_large",	"The size of the file is about to become too large for the file system to handle it safely." },
		{ ERR_Invalid_hash_table_size,	"ERR_Invalid_hash_table_size",	"The size of the hash table does not meet the expectations." },
		{ ERR_File_in_wrong_directory,	"ERR_File_in_wrong_directory",	"The directory this entry is placed in does not agree with what the file header says." },
		{ ERR_Unexpected_block_type,	"ERR_Unexpected_block_type",	"The validator found a block that does not fit into a directory." },
		{ ERR_Not_enough_bitmap_blocks,	"ERR_Not_enough_bitmap_blocks",	"The expected number of bitmap blocks was not found on the medium." },
		{ ERR_Too_many_data_blocks_registered,	"ERR_Too_many_data_blocks_registered",	"More data blocks are registered in a file header or extension block than would fit into the block itself." },
		{ ERR_Object_in_use,	"ERR_Object_in_use",	"This object cannot be changed because existing references to it demand that it stays the way it is." },
		{ ERR_Unknown_access_mode,	"ERR_Unknown_access_mode",	"Access mode for a lock was neither shared nor exclusive." },
		{ ERR_No_medium_present,	"ERR_No_medium_present",	"There is nothing to execute the intended file system operation on." },
		{ ERR_File_system_is_not_validated,	"ERR_File_system_is_not_validated",	"The file system information is not really consistent and thus should not be modified." },
		{ ERR_Medium_is_write_protected,	"ERR_Medium_is_write_protected",	"The medium cannot be written to." },
		{ ERR_No_more_entries,	"ERR_No_more_entries",	"Directory scanning has finished." },
		{ ERR_Invalid_lock,	"ERR_Invalid_lock",	"Whatever it is, it is not a complete and working file lock." },
		{ ERR_Unknown_data_type,	"ERR_Unknown_data_type",	"Whatever it is, it's not a FileLock or a FileHandle." },
		{ ERR_Medium_does_not_match_volume,	"ERR_Medium_does_not_match_volume",	"The volume associated with the file lock does not match the medium currently in use." },
		{ ERR_Medium_was_removed,	"ERR_Medium_was_removed",	"The disk was changed while there was still work being done." },
		{ ERR_Could_not_add_volume,	"ERR_Could_not_add_volume",	"Something went wrong when adding the newly made VolumeNode." },
		{ ERR_Record_lock_collision,	"ERR_Record_lock_collision",	"Record cannot be locked as since would collide with another one." },
		{ ERR_Record_not_locked,	"ERR_Record_not_locked",	"Record cannot be unlocked since it was never locked in the first place." },
		{ ERR_Examine_type_not_supported,	"ERR_Examine_type_not_supported",	"Type of data to return by ExAll() is not known." },
		{ ERR_Invalid_pointer,	"ERR_Invalid_pointer",	"Whatever the address refers to, it's no good." },
		{ ERR_Unknown_notification_mode,	"ERR_Unknown_notification_mode",	"File notification mode not supported." },
		{ ERR_Invalid_comment_checksum,	"ERR_Invalid_comment_checksum",	"Checksum of comment block is invalid." },
		{ ERR_Invalid_comment_block_number,	"ERR_Invalid_comment_block_number",	"The block number stored in a comment block does not point back it itself." },
		{ ERR_Not_a_comment,	"ERR_Not_a_comment",	"A comment block was expected but was not found." },
		{ ERR_DOS_list_in_use,	"ERR_DOS_list_in_use",	"The global list of volumes, devices, etc. is currently in use." },
		{ ERR_Not_a_comment_block,	"ERR_Not_a_comment_block",	"Whatever it is, it is not a comment block." },
		{ ERR_Comment_block_in_wrong_location,	"ERR_Comment_block_in_wrong_location",	"Comment block is not located where it says it should be." },
		{ ERR_Comment_associated_with_wrong_file,	"ERR_Comment_associated_with_wrong_file",	"This comment is attached to the wrong file or directory." },
		{ ERR_Protected_from_deletion,	"ERR_Protected_from_deletion",	"This object cannot be deleted." },
		{ ERR_Protected_from_writing,	"ERR_Protected_from_writing",	"This file cannot be written to." },
		{ ERR_Protected_from_reading,	"ERR_Protected_from_reading",	"This file cannot be read from." },
		{ ERR_No_dos,	"ERR_No_dos",	"dos.library did not open" },
		{ ERR_No_intuition,	"ERR_No_intuition",	"intuition.library did not open" },
		{ ERR_No_utility,	"ERR_No_utility",	"utility.library did not open" },
		{ ERR_Bitmap_search_error,	"ERR_Bitmap_search_error",	"Searching the bitmap for a vacant block didn't turn a single one, even though there is still room" },
		{ ERR_Plugin_type_not_supported,	"ERR_Plugin_type_not_supported", "This type of plugin is not supported." },
		{ ERR_Plugin_is_already_installed,	"ERR_Plugin_is_already_installed",	"This type of plugin can be installed only once, and it has already been installed." },
		{ ERR_Plugin_is_not_installed,	"ERR_Plugin_is_not_installed",	"This type of plugin is already installed." },
		{ ERR_Invalid_directory_list_entry,	"ERR_Invalid_directory_list_entry",	"This directory list entry doesn't look right and proper." },
		{ ERR_Not_enough_reserved_space,	"ERR_Not_enough_reserved_space",	"Not enough reserved block space at beginning of partition." },
		{ ERR_Exclusive_lock_required,		"ERR_Exclusive_lock_required",		"This won't work unless only one client has access to this resource." },
		{ ERR_Volume_name_change_failed,	"ERR_Volume_name_change_failed",	"The volume name could not be changed." },
		{ ERR_Plugin_version_mismatch,		"ERR_Plugin_version_mismatch",		"Plugin version not supported" },

		{ 0, NULL, NULL}
	};

	static struct { errorcode_t error_location; STRPTR name; } error_location_table[] =
	{
		{ ERR_LOCATION_Device, "ERR_LOCATION_Device" },
		{ ERR_LOCATION_Block, "ERR_LOCATION_Block" },
		{ ERR_LOCATION_FS, "ERR_LOCATION_FS" },
		{ ERR_LOCATION_Open_file, "ERR_LOCATION_Open_file" },
		{ ERR_LOCATION_Set_file_position, "ERR_LOCATION_Set_file_position" },
		{ ERR_LOCATION_Read_from_file, "ERR_LOCATION_Read_from_file" },
		{ ERR_LOCATION_Bit_map, "ERR_LOCATION_Bit_map" },
		{ ERR_LOCATION_Validator, "ERR_LOCATION_Validator" },
		{ ERR_LOCATION_Add, "ERR_LOCATION_Add" },
		{ ERR_LOCATION_Set_size, "ERR_LOCATION_Set_size" },
		{ ERR_LOCATION_Write_to_file, "ERR_LOCATION_Write_to_file" },
		{ ERR_LOCATION_Delete, "ERR_LOCATION_Delete" },
		{ ERR_LOCATION_Rename, "ERR_LOCATION_Rename" },
		{ ERR_LOCATION_Relabel, "ERR_LOCATION_Relabel" },
		{ ERR_LOCATION_Change, "ERR_LOCATION_Change" },
		{ ERR_LOCATION_Format, "ERR_LOCATION_Format" },
		{ ERR_LOCATION_Directory, "ERR_LOCATION_Directory" },
		{ ERR_LOCATION_Locate, "ERR_LOCATION_Locate" },
		{ ERR_LOCATION_Dir_scan, "ERR_LOCATION_Dir_scan" },
		{ ERR_LOCATION_Main, "ERR_LOCATION_Main" },
		{ 0, NULL }
	};

	LONG amigados_error = get_amigados_error(error);
	LONG internal_error = get_internal_error(error);
	LONG error_location = get_error_location(error);
	STRPTR location_str = "?";
	STRPTR internal_str = "?";
	STRPTR internal_desc_str = "?";
	LONG i;

	for(i = 0 ; error_location_table[i].name != NULL ; i++)
	{
		if(error_location_table[i].error_location == error_location)
		{
			location_str = error_location_table[i].name;
			break;
		}
	}

	for(i = 0 ; error_code_table[i].name != NULL ; i++)
	{
		if(error_code_table[i].error == internal_error)
		{
			internal_str = error_code_table[i].name;
			internal_desc_str = error_code_table[i].description;
			break;
		}
	}

	D(("error = 0x%08lx; location = 0x%08lx, %s; internal error code = %ld, %s (%s); amigados error code = %ld",
		error,
		error_location,location_str,
		internal_error,internal_str,internal_desc_str,
		amigados_error));
}

/****************************************************************************/

#endif /* DEBUG */
