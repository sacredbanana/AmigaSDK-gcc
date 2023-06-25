/*
 *	$Id: debug.h,v 1.1 2008-09-15 13:14:19 sarcher Exp $
 *
 *	:ts=4
 *
 *	Amiga ROM file system reimplementation
 *	Copyright © 2001-2005 by Olaf Barthel
 *	All Rights Reserved
 */

#ifndef _DEBUG_H
#define _DEBUG_H

/****************************************************************************/

#ifndef _BLOCK_H
#include "block.h"
#endif /* _BLOCK_H */

#ifndef _FS_H
#include "fs.h"
#endif /* _FS_H */

#ifndef _ERRORS_H
#include "errors.h"
#endif /* _ERRORS_H */

/****************************************************************************/

char *date_stamp_to_string(struct DateStamp *ds);
char *bcpl_string_to_c_string(char *bcpl_string);
char *protection_to_string(unsigned long protection);
char *number_to_binary(unsigned long number, int size);
void print_root_dir(struct FileSystemData *fsd, struct RootDirBlock *rdb);
void print_user_dir(struct FileSystemData *fsd, struct UserDirBlock *udb);
void print_file_header(struct FileSystemData *fsd, struct FileHeaderBlock *fhb);
void print_file_extension(struct FileSystemData *fsd, struct FileExtensionBlock *feb);
void print_file_data(struct FileSystemData *fsd, struct FileDataBlock *fdb);
void print_hard_link(struct FileSystemData *fsd, struct HardLinkBlock *hlb);
void print_soft_link(struct FileSystemData *fsd, struct SoftLinkBlock *slb);
void print_dir_list(struct FileSystemData *fsd, struct DirListBlock *dlb);
void print_error_code(errorcode_t error);

/****************************************************************************/

/* Special internal-use packets. */
#define ACTION_DEBUG_SET_DEBUG_MODE	2070	/* Set the debug output level; arg1=debug level, result1=previous debug level */
#define ACTION_DEBUG_REVALIDATE		2071	/* Begin to validate the disk again */
#define ACTION_DEBUG_EJECT			2072	/* Pretend to eject the medium */
#define ACTION_DEBUG_LOAD			2073	/* Pretend to reload the medium */
#define ACTION_DEBUG_FLUSH_STRATEGY	2074	/* Change the write flush strategy */

/****************************************************************************/

#endif /* _DEBUG_H */
