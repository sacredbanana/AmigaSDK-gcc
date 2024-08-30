#ifndef _AMITCP_SOCKETBASETAGS_H_
#define _AMITCP_SOCKETBASETAGS_H_
/*
 *      TAG values for SocketBaseTagList()
 *
 *      Copyright © 1994-2000 AmiTCP/IP Group,
 *      Network Solutions Development, Inc.
 *      All rights reserved.
 *
 *      $Id: socketbasetags.h,v 1.2 2020/03/29 13:53:27 piru Exp $
 */

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/*
 * utility/tagitem.h specifies that bits 16-30 in tags are reserved. So we 
 * don't use them for maximum compatability.
 */

/*
 * Argument passing convention (bit 15)
 */
#define SBTF_VAL 0x0000 /* by value */
#define SBTF_REF 0x8000 /* by reference */

/*
 * Code (bits 1-14)
 */
#define SBTB_CODE 1
#define SBTS_CODE 0x3FFF
#define SBTM_CODE(tag) (((UWORD)(tag) >> SBTB_CODE) & SBTS_CODE)

/* 
 * Direction (bit 0)
 */
#define SBTF_GET 0x0
#define SBTF_SET 0x1

/*
 * Macros used with the SocketBaseTags() call. 'code' takes a STBC_
 * value and the argument goes in ti_Data.
 */
#define SBTM_GETREF(code) \
  (TAG_USER | SBTF_REF | (((code) & SBTS_CODE) << SBTB_CODE))
#define SBTM_GETVAL(code) \
  (TAG_USER | (((code) & SBTS_CODE) << SBTB_CODE))
#define SBTM_SETREF(code) \
  (TAG_USER | SBTF_REF | (((code) & SBTS_CODE) << SBTB_CODE) | SBTF_SET)
#define SBTM_SETVAL(code) \
  (TAG_USER | (((code) & SBTS_CODE) << SBTB_CODE) | SBTF_SET)

/*
 * Tag code definitions. These codes are used with one of the above macros.
 *
 * All arguments are ULONG's or pointers (PTR suffix).
 */

/* signal masks */
#define SBTC_BREAKMASK    1
#define SBTC_SIGIOMASK    2
#define SBTC_SIGURGMASK   3
#define SBTC_SIGEVENTMASK 4

/* error code handling */
#define SBTC_ERRNO  6
#define SBTC_HERRNO 7

/* socket descriptor table related tags */
#define SBTC_DTABLESIZE 8

/* link library fd allocation callback
 * 
 * Argument is a callback function with following prototype
 *
 * int fd = fdCallback(int fd, int action);
 *     D0                  D0      D1
 *
 * see net.lib sources for an example
 */
#define SBTC_FDCALLBACK 9
/*
 * "action" values:
 */
#define FDCB_FREE  0
#define FDCB_ALLOC 1
#define FDCB_CHECK 2

/* syslog variables (see netinclude:sys/syslog.h for values) */
#define SBTC_LOGSTAT     10
#define SBTC_LOGTAGPTR   11
#define SBTC_LOGFACILITY 12
#define SBTC_LOGMASK     13

/*
 * The argument of following error string tags is a ULONG,
 * where the error number is stored. On return the string pointer is 
 * returned on this same ULONG. (GET ONLY)
 *
 * NOTE: error numbers defined in <exec/errors.h> are negative and must be
 * negated (turned to positive) before passing to the SocketBaseTagList().
 */
#define SBTC_ERRNOSTRPTR    14 /* <sys/errno.h> */
#define SBTC_HERRNOSTRPTR   15 /* <netdb.h> */
#define SBTC_IOERRNOSTRPTR  16 /* <exec/errors.h> SEE NOTE ABOVE */
#define SBTC_S2ERRNOSTRPTR  17 /* <devices/sana2.h> */
#define SBTC_S2WERRNOSTRPTR	18 /* <devices/sana2.h> */


/* links the errno pointer & size to the errno variable in your program */
#define SBTC_ERRNOBYTEPTR 21
#define SBTC_ERRNOWORDPTR 22
#define SBTC_ERRNOLONGPTR 24
/*
 * Macro for generating the errnoptr tag code from a (constant) size.
 * only 1, 2 & 4 are legal 'size' values. If the 'size' value is illegal,
 * the tag is set to 0, which causes SocketBaseTagList() to fail.
 */
#define SBTC_ERRNOPTR(size)    ((size == sizeof(long)) ? SBTC_ERRNOLONGPTR   :\
				((size == sizeof(short)) ? SBTC_ERRNOWORDPTR :\
				 ((size == sizeof(char)) ? SBTC_ERRNOBYTEPTR :\
				  0)))

/* links the h_errno pointer to the h_errno variable in your program */
#define SBTC_HERRNOLONGPTR 25

/* protocol stack release information string pointer (read only!) */
#define SBTC_RELEASESTRPTR 29

/* Number of available Berkeley Packet Filter channels */
#define SBTC_NUM_PACKET_FILTER_CHANNELS 40

/*
 * Function pointer to get errno pointer. If specified this
 * function is called to set up the initial errno pointer value.
 * called as: int *ptr = func(void);
 *            D0
 * This pointer is also inherited to child processes that use the
 * implicit "autoopen" feature of NetStack (processes calling
 * bsdsocket.library without opening it).
 */
#define SBTC_ERRNOFUNCPTR 80

/*
 * Function pointer to get h_errno pointer. If specified this
 * function is called to set up the initial h_errno pointer value.
 * Called as: int *ptr = func(void);
 *            D0
 * This pointer is also inherited to child processes that use the
 * implicit "autoopen" feature of NetStack (processes calling
 * bsdsocket.library without opening it).
 */
#define SBTC_HERRNOFUNCPTR 81

#endif /* !_AMITCP_SOCKETBASETAGS_H_ */
