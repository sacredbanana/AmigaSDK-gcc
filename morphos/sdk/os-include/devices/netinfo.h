#ifndef DEVICES_NETINFO_H
#define DEVICES_NETINFO_H

/*
	netinfo.device include

	Copyright © 2003 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_IO_H
#include <exec/io.h>
#endif

#pragma pack(2)

#define NETINFONAME "netinfo.device"

/*
 * Modified IOStdReq
 */
struct NetInfoReq
{
	struct  Message  io_Message;
	struct  Device  *io_Device; /* device node pointer  */
	struct  Unit    *io_Unit;   /* unit (driver private) */
	UWORD   io_Command;         /* device command */
	UBYTE   io_Flags;
	BYTE    io_Error;           /* error or warning num */
	ULONG   io_Actual;          /* actual number of bytes transferred */
	ULONG   io_Length;          /* requested number bytes transferred*/
	APTR    io_Data;            /* points to data area */
	ULONG   io_Offset;          /* search criteria */
};

#define NETINFOLENGTH_SAVEMODE          -1      /* Only used with CMD_UPDATE and io_Length to decide the store policy */
/*
 * NetInfo units
 */
#define NETINFO_PASSWD_UNIT    0L
#define NETINFO_GROUP_UNIT     1L
#define NETINFO_HOST_UNIT      2L
#define NETINFO_PROTOCOL_UNIT  3L
#define NETINFO_SERVICE_UNIT   4L
#define NETINFO_INETD_UNIT     5L
#define NETINFO_UNITS          6L

/* 
 * Non-standard commands
 */
#define NI_GETBYID    (CMD_NONSTD+0)
#define NI_GETBYNAME  (CMD_NONSTD+1)
#define NI_MEMBERS    (CMD_NONSTD+2)
#define NI_END        (CMD_NONSTD+3)

/*
 * Non-standard error codes (same as in the BSD errno)
 */
#define NIERR_NOTFOUND      2
#define NIERR_TOOSMALL      7
#define NIERR_NOMEM         12
#define NIERR_ACCESS        13
#define NIERR_NULL_POINTER  14
#define NIERR_INVAL         22

/* The passwd structure */
struct NetInfoPasswd
{
	UBYTE *pw_name;               /* Username */
	UBYTE *pw_passwd;             /* Encrypted password */
	LONG   pw_uid;                /* User ID */
	LONG   pw_gid;                /* Group ID */
	UBYTE *pw_gecos;              /* Real name etc */
	UBYTE *pw_dir;                /* Home directory */
	UBYTE *pw_shell;              /* Shell */
};

/* The group structure */
struct NetInfoGroup
{
	UBYTE  *gr_name;              /* Group name.  */
	UBYTE  *gr_passwd;            /* Password.    */
	LONG    gr_gid;               /* Group ID.    */
	UBYTE **gr_mem;               /* Member list. */
};

/* The host structure */
struct NetInfoHost
{
	UBYTE  *ho_domain;         /* Host Domain */
	UBYTE  *ho_address;        /* Host IP Address */
	UBYTE **ho_aliases;        /* Alias list. */
};

/* The protocol structure */
struct NetInfoProtocol
{
	UBYTE  *po_name;           /* Protocol name */
	ULONG	po_id;
};

/* The service structure */
struct NetInfoService
{
	UBYTE  *se_name;           /* Service Name */
	ULONG  se_port;            /* Service Port */
	UBYTE  *se_protocol;       /* Service Protocol */
	UBYTE  *se_comment;        /* Service Protocol */
	UBYTE **se_aliases;        /* Service Alias list. */
};

/* The inetd.conf structure */
struct NetInfoINetD
{
	UBYTE  *in_name;
	UBYTE  *in_socket;
	UBYTE  *in_protocol;
	UBYTE  *in_waitstate;
	UBYTE  *in_user;
	UBYTE  *in_server;
	UBYTE  *in_serverargs;
	ULONG  in_disabled;
};


#pragma pack()

#endif /* !DEVICES_NETINFO_H */

