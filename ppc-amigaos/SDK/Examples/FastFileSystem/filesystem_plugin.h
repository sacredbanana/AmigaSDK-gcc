/*
 * $Id: filesystem_plugin.h,v 1.1 2008-09-15 13:14:19 sarcher Exp $
 *
 * :ts=4
 *
 *	Amiga ROM file system reimplementation
 *	Copyright © 2001-2005 by Olaf Barthel
 *	All Rights Reserved
 */

#ifndef _FILESYSTEM_PLUGIN_H
#define _FILESYSTEM_PLUGIN_H

/****************************************************************************/

#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif /* UTILITY_HOOKS_H */

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif /* UTILITY_TAGITEM_H */

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****************************************************************************/

#ifdef __GNUC__
 #ifdef __PPC__
  #pragma pack(2)
 #endif
#elif defined(__VBCC__)
 #pragma amiga-align
#endif

/****************************************************************************/

#define PLUGIN_API_VERSION	51
#define PLUGIN_API_REVISION	 1

/****************************************************************************/

typedef struct
{
	ULONG pq_High;
	ULONG pq_Low;
} PLUGIN_QUAD;

/****************************************************************************/

enum fsplugin_type_t
{
	fspt_block_cache,
	fspt_block_transform
};

/****************************************************************************/

struct FSPluginHook
{
	struct Hook			fsp_Hook;
	ULONG				fsp_Reserved[4];	/* Reserved for file system use */
	UBYTE				fsp_Signature[8];
	STRPTR				fsp_VersionTag;		/* Plugin version tag string */
	STRPTR				fsp_Manufacturer;
	UWORD				fsp_Version;		/* Plugin API version and revision number */
	UWORD				fsp_Revision;
	LONG				fsp_Type;			/* What kind of plugin is this? */
	struct TagItem *	fsp_Options;
};

/****************************************************************************/

#define FSP_Base (TAG_USER+0x70000)

/****************************************************************************/

#define FSPA_NumReadAheadBlocks	(FSP_Base+1)
#define FSPA_NumTransformBlocks	(FSP_Base+2)

/****************************************************************************/

enum fsplugin_msg_t
{
	fspm_setup,
	fspm_cleanup,
	fspm_purge_cache,
	fspm_retrieve,
	fspm_read_transform,
	fspm_write_transform,
	fspm_store,
	fspm_drop,
	fspm_write
};

/****************************************************************************/

/* Initialize the plugin, using device name, unit number and
 * partition dimensions as keys.
 */
struct FSPluginSetupMsg
{
	LONG		fspm_Type;
	LONG		fspm_BytesPerBlock;
	STRPTR		fspm_DeviceName;
	LONG		fspm_UnitNumber;
	PLUGIN_QUAD	fspm_FirstSector;
	PLUGIN_QUAD	fspm_LastSector;
};

/****************************************************************************/

/* Reverse the setup procedure. */
struct FSPluginCleanupMsg
{
	LONG fspm_Type;
};

/****************************************************************************/

/* Consider the entire cache invalidated. */
struct FSPluginPurgeCacheMsg
{
	LONG fspm_Type;
};

/****************************************************************************/

/* Attempt to retrieve a single block from the cache. */
struct FSPluginRetrieveMsg
{
	LONG	fspm_Type;
	APTR	fspm_Data;
	ULONG	fspm_Offset;
};

/****************************************************************************/

/* After reading a block from disk, transform its contents,
 * making it readable.
 */
struct FSPluginReadTransformMsg
{
	LONG	fspm_Type;
	APTR	fspm_SourceData;
	ULONG	fspm_Offset;
	APTR	fspm_DestinationData;
};

/****************************************************************************/

/* Before writing a block from disk, transform its contents,
 * making it unreadable.
 */
struct FSPluginWriteTransformMsg
{
	LONG	fspm_Type;
	APTR	fspm_SourceData;
	ULONG	fspm_Offset;
	APTR	fspm_DestinationData;
};

/****************************************************************************/

/* After writing a block to disk, store it in the cache. */
struct FSPluginStoreMsg
{
	LONG	fspm_Type;
	APTR	fspm_Data;
	ULONG	fspm_Offset;
};

/****************************************************************************/

/* Drop a block from the cache. */
struct FSPluginDropMsg
{
	LONG	fspm_Type;
	ULONG	fspm_Offset;
};

/****************************************************************************/

/* Write the contents of the cache do disk. */
struct FSPluginFlushCacheMsg
{
	LONG fspm_Type;
	BOOL fspm_Final;
};

/****************************************************************************/

#define ACTION_ADD_PLUGIN		1100
#define ACTION_REMOVE_PLUGIN	1101

/****************************************************************************/

#define ERROR_UNKNOWN_PLUGIN_TYPE		400
#define ERROR_PLUGIN_ALREADY_INSTALLED	401
#define ERROR_PLUGIN_NOT_INSTALLED		402
#define ERROR_BLOCK_NOT_FOUND			403
#define ERROR_INVALID_BLOCK_SIZE		404

/****************************************************************************/

#ifdef __GNUC__
 #ifdef __PPC__
  #pragma pack()
 #endif
#elif defined(__VBCC__)
 #pragma default-align
#endif

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _FILESYSTEM_PLUGIN_H */
