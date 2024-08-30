#ifndef DEVICES_KEYMAP_H
#define DEVICES_KEYMAP_H

/*
	keymap.library/resource include

	Copyright © 2002-2007 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_RESIDENT_H
#include <exec/resident.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

#pragma pack(2)


struct KeyMap
{
	UBYTE *km_LoKeyMapTypes;
	ULONG *km_LoKeyMap;
	UBYTE *km_LoCapsable;
	UBYTE *km_LoRepeatable;
	UBYTE *km_HiKeyMapTypes;
	ULONG *km_HiKeyMap;
	UBYTE *km_HiCapsable;
	UBYTE *km_HiRepeatable;
};

struct KeyMapNode
{
	struct Node   kn_Node;
	struct KeyMap kn_KeyMap;
};

#pragma pack(4)

struct ExtendedKeyMapNode
{
	struct Node      ekn_Node;
	struct KeyMap    ekn_KeyMap;
	BPTR             ekn_Seglist;
	struct Resident *ekn_Resident;
	APTR             ekn_Future0; /* keep 0 for now */
};

#pragma pack(2)

struct KeyMapResource
{
	struct Node kr_Node;
	struct List kr_List;
};


/* Keymap types */

#define KC_NOQUAL   0
#define KC_VANILLA  7

#define KCB_SHIFT   0
#define KCF_SHIFT   (1<<KCB_SHIFT)
#define KCB_ALT     1
#define KCF_ALT     (1<<KCB_ALT)
#define KCB_CONTROL 2
#define KCF_CONTROL (1<<KCB_CONTROL)
#define KCB_DOWNUP  3
#define KCF_DOWNUP  (1<<KCB_DOWNUP)

#define KCB_DEAD    5
#define KCF_DEAD    (1<<KCB_DEAD)

#define KCB_STRING  6
#define KCF_STRING  (1<<KCB_STRING)

#define KCB_NOP     7
#define KCF_NOP     (1<<KCB_NOP)


/* Dead prefix-bytes */

#define DPB_MOD   0
#define DPF_MOD   (1<<DPB_MOD)
#define DPB_DEAD  3
#define DPF_DEAD  (1<<DPB_DEAD)


#define DP_2DINDEXMASK  0x0f
#define DP_2DFACSHIFT   4


#pragma pack()

struct UCS4_ConvTable
{
	UWORD FirstChar;
	UWORD LastChar;
	CONST_APTR ConvTable;   /* Either pointer to UBYTE or ULONG */
};

struct UCS4_CharsetCode
{
	ULONG UCS4;
	ULONG CharsetCode;
};

struct UCS4_CharsetConvTable
{
	CONST struct UCS4_CharsetCode *Mapping;  /* An optional array, terminated with { 0, 0 } entry */
#if __STDC_VERSION__ >= 199901L
	struct UCS4_ConvTable    ConvTables[];
#elif defined(__GNUC__)
	struct UCS4_ConvTable    ConvTables[0];
#else
# error Compiler does not support zero-length arrays.
#endif
};

#endif /* DEVICES_KEYMAP_H */
