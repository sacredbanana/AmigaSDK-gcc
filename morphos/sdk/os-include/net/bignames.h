#ifndef _AMITCP_BIGNAMES_H_
#define _AMITCP_BIGNAMES_H_
/*
 * Capitalized BSD socket function names for someone who may have used those.
 *
 *      Copyright � 1994-2000 AmiTCP/IP Group,
 *      Network Solutions Development, Inc.
 *      All rights reserved.
 *
 * $Id: bignames.h,v 1.1.1.1 2005/03/15 16:00:46 laire Exp $
 */

/*
 * Writing standard bsd socket functions as capitalized letters was a
 * mistage which was changed in this release. However, someone may have
 * used those in their programs, and this file is written for their
 * convenience. Just include this file before other amitcp includes if
 * you have used Capitalized letters in your program code.
 */

#define AMITCP_BIG_NAMES	/* needed for pragmas */

#define socket Socket
#define bind Bind
#define listen Listen
#define accept Accept
#define connect Connect
#define send Send
#define sendto SendTo
#define sendmsg SendMsg
#define recv Recv
#define recvfrom RecvFrom
#define recvmsg RecvMsg
#define shutdown Shutdown
#define setsockopt SetSockOpt
#define getsockopt GetSockOpt
#define getsockname GetSockName
#define getpeername GetPeerName
#define inet_addr Inet_Addr
#define inet_network Inet_Network
#define gethostbyname GetHostByName
#define gethostbyaddr GetHostByAddr
#define getnetbyname GetNetByName
#define getnetbyaddr GetNetByAddr
#define getservbyname GetServByName
#define getservbyport GetServByPort
#define getprotobyname GetProtoByName
#define getprotobynumber GetProtoByNumber
#define getdtablesize GetDTableSize
#define gethostname GetHostName
#define gethostid GetHostId
#define vsyslog SyslogA
#define syslog Syslog

#endif /* !_AMITCP_BIGNAMES_H_ */
