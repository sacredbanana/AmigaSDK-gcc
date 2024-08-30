#ifndef _NET_IF_ARP_H_
#define _NET_IF_ARP_H_
/*
 * Interface to the Address Resolution Protocol
 *
 * Copyright © 1994-2000 AmiTCP/IP Group,
 * Network Solutions Development, Inc.
 * All rights reserved.
 *
 * $Id: if_arp.h,v 1.1.1.1 2005/03/15 16:00:46 laire Exp $
 */

#pragma pack(2)


/*
 * Address Resolution Protocol.
 *
 * See RFC 826 for protocol description.  ARP packets are variable
 * in size; the arphdr structure defines the fixed-length portion.
 * Protocol type values are the same as those for 10 Mb/s Ethernet.
 * It is followed by the variable-sized fields ar_sha, arp_spa,
 * arp_tha and arp_tpa in that order, according to the lengths
 * specified.  Field names used correspond to RFC 826.
 */
struct	arphdr {
	u_short	ar_hrd;		/* format of hardware address */
#define ARPHRD_ETHER 	1	/* ethernet hardware address */
#define ARPHRD_ARCNET 	7	/* ARCNET hardware address */
	u_short	ar_pro;		/* format of protocol address */
	u_char	ar_hln;		/* length of hardware address */
	u_char	ar_pln;		/* length of protocol address */
	u_short	ar_op;		/* one of: */
#define	ARPOP_REQUEST	1	/* request to resolve address */
#define	ARPOP_REPLY	2	/* response to previous request */
};

#define MAXADDRARP  16          /* Maximum number of octets in hw address */

/*
 * ARP ioctl request. 
 */
struct arpreq {
	struct	sockaddr arp_pa;		/* protocol address */
	struct	{		                /* hardware address */
	  u_char sa_len;
	  u_char sa_family;		
	  char	 sa_data[MAXADDRARP];		
	}  arp_ha;		
	int	arp_flags;			/* flags */
};

/*  arp_flags and at_flags field values */
#define	ATF_INUSE	0x01	/* entry in use */
#define ATF_COM		0x02	/* completed entry (enaddr valid) */
#define	ATF_PERM	0x04	/* permanent entry */
#define	ATF_PUBL	0x08	/* publish entry (respond for other host) */
#define	ATF_USETRAILERS	0x10	/* has requested trailers */

/* 
 * An AmiTCP/IP specific ARP table ioctl request
 */
struct arptabreq {
	struct arpreq  atr_arpreq; /* We want to identify the interface */
	long           atr_size;          /* # of elements in art_table */
	long           atr_inuse;               /* # of elements in use */
	struct arpreq *atr_table;
};


#pragma pack()

#endif /* !_NET_IF_ARP_H_ */


