#ifndef LIBRARIES_AMIGAGUIDE_H
#define LIBRARIES_AMIGAGUIDE_H

/*
	amigaguide.library include (V45)

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

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef INTUITION_SCREENS_H
# include <intuition/screens.h>
#endif

#ifndef INTUITION_CLASSUSR_H
# include <intuition/classusr.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


#ifndef APSH_TOOL_ID
# define APSH_TOOL_ID      11000
# define StartupMsgID      (APSH_TOOL_ID + 1)
# define LoginToolID       (APSH_TOOL_ID + 2)
# define LogoutToolID      (APSH_TOOL_ID + 3)
# define ShutdownMsgID     (APSH_TOOL_ID + 4)
# define ActivateToolID    (APSH_TOOL_ID + 5)
# define DeactivateToolID  (APSH_TOOL_ID + 6)
# define ActiveToolID      (APSH_TOOL_ID + 7)
# define InactiveToolID    (APSH_TOOL_ID + 8)
# define ToolStatusID      (APSH_TOOL_ID + 9)
# define ToolCmdID         (APSH_TOOL_ID + 10)
# define ToolCmdReplyID    (APSH_TOOL_ID + 11)
# define ShutdownToolID    (APSH_TOOL_ID + 12)
#endif


#define AGA_Dummy           (TAG_USER)
#define AGA_Path            (AGA_Dummy + 1)
#define AGA_XRefList        (AGA_Dummy + 2)
#define AGA_Activate        (AGA_Dummy + 3)
#define AGA_Context         (AGA_Dummy + 4)
#define AGA_HelpGroup       (AGA_Dummy + 5)
#define AGA_Reserved1       (AGA_Dummy + 6)
#define AGA_Reserved2       (AGA_Dummy + 7)
#define AGA_Reserved3       (AGA_Dummy + 8)
#define AGA_ARexxPort       (AGA_Dummy + 9)
#define AGA_ARexxPortName   (AGA_Dummy + 10)

/*** V41 ***/

#define AGA_Secure          (AGA_Dummy + 11)


typedef void *AMIGAGUIDECONTEXT;

struct AmigaGuideMsg
{
	struct Message agm_Msg;
	ULONG          agm_Type;
	APTR           agm_Data;
	ULONG          agm_DSize;
	ULONG          agm_DType;
	ULONG          agm_Pri_Ret;
	ULONG          agm_Sec_Ret;
	APTR           agm_System1;
	APTR           agm_System2;
};

struct NewAmigaGuide
{
	BPTR            nag_Lock;
	STRPTR          nag_Name;
	struct Screen  *nag_Screen;
	STRPTR          nag_PubScreen;
	STRPTR          nag_HostPort;
	STRPTR          nag_ClientPort;
	STRPTR          nag_BaseName;
	ULONG           nag_Flags;
	STRPTR         *nag_Context;
	STRPTR          nag_Node;
	LONG            nag_Line;
	struct TagItem *nag_Extens;
	APTR            nag_Client;
};


#define HTF_LOAD_INDEX  (1<<0)
#define HTF_LOAD_ALL    (1<<1)
#define HTF_CACHE_NODE  (1<<2)
#define HTF_CACHE_DB    (1<<3)
#define HTF_UNIQUE      (1<<15)
#define HTF_NOACTIVATE  (1<<16)

#define HTFC_SYSGADS  0x80000000


#define HTH_OPEN   0
#define HTH_CLOSE  1


#define HTERR_NOT_ENOUGH_MEMORY   100
#define HTERR_CANT_OPEN_DATABASE  101
#define HTERR_CANT_FIND_NODE      102
#define HTERR_CANT_OPEN_NODE      103
#define HTERR_CANT_OPEN_WINDOW    104
#define HTERR_INVALID_COMMAND     105
#define HTERR_CANT_COMPLETE       106
#define HTERR_PORT_CLOSED         107
#define HTERR_CANT_CREATE_PORT    108
#define HTERR_KEYWORD_NOT_FOUND   113


struct XRef
{
	struct Node     xr_Node;
	UWORD           xr_Pad;
	struct DocFile *xr_DF;
	STRPTR          xr_File;
	STRPTR          xr_Name;
	LONG            xr_Line;

	/*** V44 ***/

	ULONG           xr_Reserved[2];
};

#define XRSIZE  (sizeof(struct XRef))


#define XR_GENERIC   0
#define XR_FUNCTION  1
#define XR_COMMAND   2
#define XR_INCLUDE   3
#define XR_MACRO     4
#define XR_STRUCT    5
#define XR_FIELD     6
#define XR_TYPEDEF   7
#define XR_DEFINE    8


struct AmigaGuideHost
{
	struct Hook agh_Dispatcher;
	ULONG       agh_Reserved;
	ULONG       agh_Flags;
	ULONG       agh_UseCnt;
	APTR        agh_SystemData;
	APTR        agh_UserData;
};

typedef struct AmigaGuideHost *AMIGAGUIDEHOST;


#define HM_FINDNODE   1
#define HM_OPENNODE   2
#define HM_CLOSENODE  3
#define HM_EXPUNGE    10


struct opFindHost
{
	ULONG           MethodID;
	struct TagItem *ofh_Attrs;
	STRPTR          ofh_Node;
	STRPTR          ofh_TOC;
	STRPTR          ofh_Title;
	STRPTR          ofh_Next;
	STRPTR          ofh_Prev;
};

struct opNodeIO
{
	ULONG           MethodID;
	struct TagItem *onm_Attrs;
	STRPTR          onm_Node;
	STRPTR          onm_FileName;
	STRPTR          onm_DocBuffer;
	ULONG           onm_BuffLen;
	ULONG           onm_Flags;
};


#define HTNF_KEEP       (1<<0)
#define HTNF_RESERVED1  (1<<1)
#define HTNF_RESERVED2  (1<<2)
#define HTNF_ASCII      (1<<3)
#define HTNF_RESERVED3  (1<<4)
#define HTNF_CLEAN      (1<<5)
#define HTNF_DONE       (1<<6)


#define HTNA_Dummy      (TAG_USER)
#define HTNA_Screen     (HTNA_Dummy + 1)
#define HTNA_Pens       (HTNA_Dummy + 2)
#define HTNA_Rectangle  (HTNA_Dummy + 3)
#define HTNA_HelpGroup  (HTNA_Dummy + 5)


struct opExpungeNode
{
	ULONG           MethodID;
	struct TagItem *oen_Attrs;
};


#pragma pack()

#endif /* LIBRARIES_AMIGAGUIDE_H */
