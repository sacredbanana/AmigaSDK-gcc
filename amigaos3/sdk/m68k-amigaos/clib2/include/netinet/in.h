/*
 * $Id: in.h,v 1.4 2006-01-08 12:06:14 obarthel Exp $
 *
 * :ts=4
 *
 * Portable ISO 'C' (1994) runtime library for the Amiga computer
 * Copyright (c) 2002-2015 by Olaf Barthel <obarthel (at) gmx.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   - Neither the name of Olaf Barthel nor the names of contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************
 *
 * Documentation and source code for this library, and the most recent library
 * build are available from <http://sourceforge.net/projects/clib2>.
 *
 *****************************************************************************
 */

#ifndef _NETINET_IN_H
#define _NETINET_IN_H

/****************************************************************************/

/* The following is not part of the ISO 'C' (1994) standard. */

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

/*
 * Constants and structures defined by the internet system,
 * Per RFC 790, September 1981, and numerous additions.
 */

/*
 * Data types.
 */
typedef unsigned long	in_addr_t;
typedef unsigned short	in_port_t;

/*
 * Protocols
 */
#define	IPPROTO_IP		0		/* dummy for IP */
#define	IPPROTO_ICMP	1		/* control message protocol */
#define	IPPROTO_IGMP	2		/* group mgmt protocol */
#define	IPPROTO_GGP		3		/* gateway^2 (deprecated) */
#define	IPPROTO_TCP		6		/* tcp */
#define	IPPROTO_EGP		8		/* exterior gateway protocol */
#define	IPPROTO_PUP		12		/* pup */
#define	IPPROTO_UDP		17		/* user datagram protocol */
#define	IPPROTO_IDP		22		/* xns idp */
#define	IPPROTO_TP		29 		/* tp-4 w/ class negotiation */
#define	IPPROTO_EON		80		/* ISO cnlp */
#define	IPPROTO_ENCAP	98		/* encapsulation header */

#define	IPPROTO_RAW		255		/* raw IP packet */
#define	IPPROTO_MAX		256


/*
 * Local port number conventions:
 * Ports < IPPORT_RESERVED are reserved for
 * privileged processes (e.g. root).
 * Ports > IPPORT_USERRESERVED are reserved
 * for servers, not necessarily privileged.
 */
#define	IPPORT_RESERVED		1024
#define	IPPORT_USERRESERVED	5000

/*
 * Internet address (a structure for historical reasons)
 */
struct in_addr
{
	unsigned long s_addr;
};

/*
 * Definitions of bits in internet address integers.
 * On subnets, the decomposition of addresses to host and net parts
 * is done according to subnet mask, not the masks here.
 */
#define	IN_CLASSA(i)			(((unsigned long)(i) & 0x80000000) == 0)
#define	IN_CLASSA_NET			0xff000000
#define	IN_CLASSA_NSHIFT		24
#define	IN_CLASSA_HOST			0x00ffffff
#define	IN_CLASSA_MAX			128

#define	IN_CLASSB(i)			(((unsigned long)(i) & 0xc0000000) == 0x80000000)
#define	IN_CLASSB_NET			0xffff0000
#define	IN_CLASSB_NSHIFT		16
#define	IN_CLASSB_HOST			0x0000ffff
#define	IN_CLASSB_MAX			65536

#define	IN_CLASSC(i)			(((unsigned long)(i) & 0xe0000000) == 0xc0000000)
#define	IN_CLASSC_NET			0xffffff00
#define	IN_CLASSC_NSHIFT		8
#define	IN_CLASSC_HOST			0x000000ff

#define	IN_CLASSD(i)			(((unsigned long)(i) & 0xf0000000) == 0xe0000000)
#define	IN_CLASSD_NET			0xf0000000	/* These ones aren't really */
#define	IN_CLASSD_NSHIFT		28		/* net and host fields, but */
#define	IN_CLASSD_HOST			0x0fffffff	/* routing needn't know.    */
#define	IN_MULTICAST(i)			IN_CLASSD(i)

#define	IN_EXPERIMENTAL(i)		(((unsigned long)(i) & 0xf0000000) == 0xf0000000)
#define	IN_BADCLASS(i)			(((unsigned long)(i) & 0xf0000000) == 0xf0000000)

#define	INADDR_ANY				0x00000000UL
#define	INADDR_BROADCAST		0xffffffffUL	/* must be masked */
#define	INADDR_NONE				0xffffffff		/* -1 return */

#define	INADDR_UNSPEC_GROUP		0xe0000000UL	/* 224.0.0.0 */
#define	INADDR_ALLHOSTS_GROUP	0xe0000001UL	/* 224.0.0.1 */
#define	INADDR_MAX_LOCAL_GROUP	0xe00000ffUL	/* 224.0.0.255 */

#define	IN_LOOPBACKNET			127				/* official! */

/*
 * Socket address, internet style.
 */
struct sockaddr_in
{
	unsigned char	sin_len;
	unsigned char	sin_family;
	unsigned short	sin_port;
	struct in_addr	sin_addr;
	unsigned char	sin_zero[8];
};

/*
 * Structure used to describe IP options.
 * Used to store options internally, to pass them to a process,
 * or to restore options retrieved earlier.
 * The ip_dst is used for the first-hop gateway when using a source route
 * (this gets put into the header proper).
 */
struct ip_opts
{
	struct in_addr	ip_dst;			/* first hop, 0 w/o src rt */
	unsigned char	ip_options[40];	/* actually variable in size */
};

/*
 * Options for use with [gs]etsockopt at the IP level.
 * First word of comment is data type; bool is stored in int.
 */
#define	IP_OPTIONS			1    /* buf/ip_opts; set/get IP options */
#define	IP_HDRINCL			2    /* int; header is included with data */
#define	IP_TOS				3    /* int; IP type of service and preced. */
#define	IP_TTL				4    /* int; IP time to live */
#define	IP_RECVOPTS			5    /* bool; receive all IP opts w/dgram */
#define	IP_RECVRETOPTS		6    /* bool; receive IP opts for response */
#define	IP_RECVDSTADDR		7    /* bool; receive IP dst addr w/dgram */
#define	IP_RETOPTS			8    /* ip_opts; set/get IP options */
#define	IP_MULTICAST_IF		9    /* unsigned char; set/get IP multicast i/f  */
#define	IP_MULTICAST_TTL	10   /* unsigned char; set/get IP multicast ttl */
#define	IP_MULTICAST_LOOP	11   /* unsigned char; set/get IP multicast loopback */
#define	IP_ADD_MEMBERSHIP	12   /* ip_mreq; add an IP group membership */
#define	IP_DROP_MEMBERSHIP	13   /* ip_mreq; drop an IP group membership */

/*
 * Defaults and limits for options
 */
#define	IP_DEFAULT_MULTICAST_TTL	1	/* normally limit m'casts to 1 hop  */
#define	IP_DEFAULT_MULTICAST_LOOP	1	/* normally hear sends if a member  */
#define	IP_MAX_MEMBERSHIPS			20	/* per socket; must fit in one mbuf */

/*
 * Argument structure for IP_ADD_MEMBERSHIP and IP_DROP_MEMBERSHIP.
 */
struct ip_mreq
{
	struct in_addr imr_multiaddr;	/* IP multicast address of group */
	struct in_addr imr_interface;	/* local IP address of interface */
};

/*
 * Definitions for inet sysctl operations.
 *
 * Third level is protocol number.
 * Fourth level is desired variable within that protocol.
 */
#define	IPPROTO_MAXID	(IPPROTO_IDP + 1)	/* don't list to IPPROTO_MAX */

/*
 * Names for IP sysctl objects
 */
#define	IPCTL_FORWARDING	1	/* act as router */
#define	IPCTL_SENDREDIRECTS	2	/* may send redirects when forwarding */
#define	IPCTL_DEFTTL		3	/* default TTL */
#ifdef notyet
#define	IPCTL_DEFMTU		4	/* default MTU */
#endif
#define	IPCTL_MAXID			5

/****************************************************************************/

/*
 * Macros for network/external number representation conversion.
 */
#define	ntohl(x) (x)
#define	ntohs(x) (x)
#define	htonl(x) (x)
#define	htons(x) (x)

#define	NTOHL(x) (x)
#define	NTOHS(x) (x)
#define	HTONL(x) (x)
#define	HTONS(x) (x)

/****************************************************************************/

#ifdef __GNUC__
 #ifdef __PPC__
  #pragma pack()
 #endif
#elif defined(__VBCC__)
 #p #pragma default-al
#endif

/****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/****************************************************************************/

#endif /* _NETINET_IN_H */
