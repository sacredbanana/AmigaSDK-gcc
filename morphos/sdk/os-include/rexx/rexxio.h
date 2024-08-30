#ifndef REXX_REXXIO_H
#define REXX_REXXIO_H

/*
	rexx io defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REXX_STORAGE_H
# include <rexx/storage.h>
#endif

#pragma pack(2)


#define RXBUFFSZ  204


struct IoBuff
{
	struct RexxRsrc iobNode;
	APTR            iobRpt;
	LONG            iobRct;
	LONG            iobDFH;
	APTR            iobLock;
	LONG            iobBct;
	BYTE            iobArea[RXBUFFSZ];
};

/* Access modes */

#define RXIO_EXIST  -1
#define RXIO_STRF    0
#define RXIO_READ    1
#define RXIO_WRITE   2
#define RXIO_APPEND  3


/* Offset modes */

#define RXIO_BEGIN  -1L
#define RXIO_CURR    0L
#define RXIO_END     1L


#define LLOFFSET(rrp)  (rrp->rr_Arg1)
#define LLVERS(rrp)    (rrp->rr_Arg2)

#define CLVALUE(rrp)   ((STRPTR) rrp->rr_Arg1)


struct RexxMsgPort
{
	struct RexxRsrc rmp_Node;
	struct MsgPort  rmp_Port;
	struct List     rmp_ReplyList;
};


/* Device types */

#define DT_DEV  0L
#define DT_DIR  1L
#define DT_VOL  2L


/* Packet types */

#define ACTION_STACK  2002L
#define ACTION_QUEUE  2003L


#pragma pack()

#endif
