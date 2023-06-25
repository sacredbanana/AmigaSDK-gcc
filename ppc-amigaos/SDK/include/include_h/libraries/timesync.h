#ifndef LIBRARIES_TIMESYNC_H
#define LIBRARIES_TIMESYNC_H
/*
**    $VER: timesync.h 53.11 (27.04.2021)
**  
**    Standard C header for AmigaDOS
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/


/* Tag values for RemoteSync() */
#define RS_PROTOCOL         (TAG_USER+1)    /* (UBYTE)  */
#define RS_SERVER           (TAG_USER+2)    /* (STRPTR) */
#define RS_SERVERLIST       (TAG_USER+10)   /* (struct List *) */
#define RS_PORT             (TAG_USER+3)    /* (uint32) */
#define RS_UTCOFFSET        (TAG_USER+4)    /* (int32)  */
#define RS_SETSYSTIME       (TAG_USER+5)    /* (BOOL)   */
#define RS_SAVETIME         (TAG_USER+6)    /* (BOOL)   */
#define RS_DIFFTIME         (TAG_USER+7)    /* (struct timeval *) */
#define RS_ERRSTR_OBSOLETE  (TAG_USER+8)    /* (STRPTR *) Obsolete 53.10, Only returns NULL now. */
#define RS_ERRNO            (TAG_USER+9)    /* (int32 *) */
#define RS_ERRBUFFER        (TAG_USER+11)   /* (STRPTR) 53.10 */
#define RS_ERRBUFFERSIZE    (TAG_USER+12)   /* (uint32) 53.10 */



/* alias */
#define RS_ERRBUFFERLEN      RS_ERRBUFFERSIZE


/* Error returns from RemoteSync() */
#define TSERR_NONE       0
#define TSERR_INVALID    5    /* Invalid reply from server */
#define TSERR_KOD        6    /* KoD */
#define TSERR_NOLIB     10    /* Couldn't open socket lib */
#define TSERR_FAIL      20    /* Talking to remote failed */

/* Socket errors following */
#define TSERR_SOCKET    50
#define TSERR_UNSPEC    TSERR_SOCKET   /* Unspecified socket error */
#define TSERR_NORESOLVE 51    /* Can't resolve address */
#define TSERR_NOSOCK    52    /* Can't create socket */
#define TSERR_NOBIND    53    /* Can't bind */
#define TSERR_SOCKOPT   54    /* Can't set snd/rcv timeout */
#define TSERR_SEND      55    /* Error while sending */
#define TSERR_RECV      56    /* Error while receiving */
#define TSERR_CONNECT   57    /* Error while connecting */
#define TSERR_NOSERV    58    /* Service not available */


#endif /* LIBRARIES_TIMESYNC_H */
