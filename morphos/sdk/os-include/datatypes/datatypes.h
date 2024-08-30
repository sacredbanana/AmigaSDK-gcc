#ifndef DATATYPES_DATATYPES_H
#define DATATYPES_DATATYPES_H

/*
	datatypes.library include (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


#define ID_DTYP MAKE_ID('D','T','Y','P')
#define ID_DTHD MAKE_ID('D','T','H','D')

struct DataTypeHeader
{
	STRPTR   dth_Name;
	STRPTR   dth_BaseName;
	STRPTR   dth_Pattern;
	WORD    *dth_Mask;
	ULONG    dth_GroupID;
	ULONG    dth_ID;
	WORD     dth_MaskLen;
	WORD     dth_Pad;
	UWORD    dth_Flags;
	UWORD    dth_Priority;
};

#define DTHSIZE  sizeof(struct DataTypeHeader)


/* Basic types */

#define DTF_TYPE_MASK  0x000F
#define DTF_BINARY     0x0000
#define DTF_ASCII      0x0001
#define DTF_IFF        0x0002
#define DTF_MISC       0x0003
#define DTF_CASE       0x0010
#define DTF_SYSTEM1    0x1000


#define GID_SYSTEM      MAKE_ID ('s','y','s','t')
#define GID_TEXT        MAKE_ID ('t','e','x','t')
#define GID_DOCUMENT    MAKE_ID ('d','o','c','u')
#define GID_SOUND       MAKE_ID ('s','o','u','n')
#define GID_INSTRUMENT  MAKE_ID ('i','n','s','t')
#define GID_MUSIC       MAKE_ID ('m','u','s','i')
#define GID_PICTURE     MAKE_ID ('p','i','c','t')
#define GID_ANIMATION   MAKE_ID ('a','n','i','m')
#define GID_MOVIE       MAKE_ID ('m','o','v','i')


#define ID_CODE  MAKE_ID('D','T','C','D')

struct DTHookContext
{
	struct Library       *dthc_SysBase;
	struct Library       *dthc_DOSBase;
	struct Library       *dthc_IFFParseBase;
	struct Library       *dthc_UtilityBase;

	BPTR                  dthc_Lock;
	struct FileInfoBlock *dthc_FIB;
	BPTR                  dthc_FileHandle;
	struct IFFHandle     *dthc_IFF;
	STRPTR                dthc_Buffer;
	ULONG                 dthc_BufferLength;
};


#define ID_TOOL  MAKE_ID('D','T','T','L')

struct Tool
{
	UWORD  tn_Which;
	UWORD  tn_Flags;
	STRPTR tn_Program;
};

#define TSIZE  sizeof(struct Tool)


/* tn_Which defines */

#define TW_INFO    1
#define TW_BROWSE  2
#define TW_EDIT    3
#define TW_PRINT   4
#define TW_MAIL    5


/* tn_Flags defines */

#define TF_LAUNCH_MASK  0x000F
#define TF_SHELL        0x0001
#define TF_WORKBENCH    0x0002
#define TF_RX           0x0003


#define ID_TAGS  MAKE_ID('D','T','T','G')


#ifndef DATATYPE
#define DATATYPE

struct DataType
{
	struct Node            dtn_Node1;
	struct Node            dtn_Node2;
	struct DataTypeHeader *dtn_Header;
	struct List            dtn_ToolList;
	STRPTR                 dtn_FunctionName;
	struct TagItem        *dtn_AttrList;
	ULONG                  dtn_Length;
};
#endif /* DATATYPE */

#define DTNSIZE  sizeof(struct DataType)


struct ToolNode
{
	struct Node tn_Node;
	struct Tool tn_Tool;
	ULONG       tn_Length;
};

#define TNSIZE  sizeof(struct ToolNode)


#ifndef ID_NAME
# define ID_NAME  MAKE_ID('N','A','M','E')
#endif


/* Text IDs */

#define DTERROR_UNKNOWN_DATATYPE        2000
#define DTERROR_COULDNT_SAVE            2001
#define DTERROR_COULDNT_OPEN            2002
#define DTERROR_COULDNT_SEND_MESSAGE    2003
#define DTERROR_COULDNT_OPEN_CLIPBOARD  2004
#define DTERROR_Reserved                2005
#define DTERROR_UNKNOWN_COMPRESSION     2006
#define DTERROR_NOT_ENOUGH_DATA         2007
#define DTERROR_INVALID_DATA            2008

/*** V44 ***/

#define DTERROR_NOT_AVAILABLE           2009


/* Offset for types */

#define DTMSG_TYPE_OFFSET               2100


#pragma pack()

#endif /* DATATYPES_DATATYPES_H */
