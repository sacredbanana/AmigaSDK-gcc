#ifndef REXX_REXXIO_H
#define REXX_REXXIO_H
/*
**    $VER: rexxio.h 54.16 (22.08.2022)
**
**    Header file for ARexx Input/Output related structures
**
**    Copyright (C) 1986-1990 William S. Hawes
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef REXX_STORAGE_H
#include <rexx/storage.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

#define RXBUFFSZ 204 /* buffer length */

/*
 * The IoBuff is a resource node used to maintain the File List.  Nodes
 * are allocated and linked into the list whenever a file is opened.
 */
struct IoBuff
{
    struct RexxRsrc iobNode;           /* structure for files/strings */
    APTR            iobRpt;            /* read/write pointer */
    LONG            iobRct;            /* character count */
    LONG            iobDFH;            /* DOS filehandle */
    APTR            iobLock;           /* DOS lock */
    LONG            iobBct;            /* buffer length */
    BYTE            iobArea[RXBUFFSZ]; /* buffer area */
};                                     /* size: 256 bytes */

/* Access mode definitions */
#define RXIO_EXIST  -1 /* an external filehandle */
#define RXIO_STRF    0 /* a "string file" */
#define RXIO_READ    1 /* read-only access */
#define RXIO_WRITE   2 /* write mode */
#define RXIO_APPEND  3 /* append mode (existing file) */

/*
 * Offset anchors for SeekF()
 */
#define RXIO_BEGIN -1L /* relative to start */
#define RXIO_CURR   0L /* relative to current position */
#define RXIO_END    1L /* relative to end */

/* The Library List contains just plain resource nodes. */

#define LLOFFSET(rrp) (rrp->rr_Arg1) /* "Query" offset */
#define LLVERS(rrp)   (rrp->rr_Arg2) /* library version */

/*
 * The RexxClipNode structure is used to maintain the Clip List.  The value
 * string is stored as an argstring in the rr_Arg1 field.
 */
#define CLVALUE(rrp) ((STRPTR) rrp->rr_Arg1)

/*
 * A message port structure, maintained as a resource node.  The ReplyList
 * holds packets that have been received but haven't been replied.
 */
struct RexxMsgPort
{
    struct RexxRsrc rmp_Node;      /* linkage node */
    struct MsgPort  rmp_Port;      /* the message port */
    struct List     rmp_ReplyList; /* messages awaiting reply */
};

/*
 * DOS Device types
 */
#define DT_DEV 0L /* a device */
#define DT_DIR 1L /* an ASSIGNed directory */
#define DT_VOL 2L /* a volume */

/*
 * Private DOS packet types
 */
#define ACTION_STACK 2002L /* stack a line */
#define ACTION_QUEUE 2003L /* queue a line */

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
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* REXX_REXXIO_H */
