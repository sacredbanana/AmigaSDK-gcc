#ifndef NET_SANA2TAGS_H
#define NET_SANA2TAGS_H
/*
 *      Well known parameters for SANA-II/IP
 *
 *      Copyright � 1994 AmiTCP/IP Group,
 *                       Network Solutions Development, Inc.
 *                       All rights reserved.
 *
 *      $Id: sana2tags.h,v 1.1.1.1 2005/03/15 16:00:46 laire Exp $
 */

#define	ETHERTYPE_IP	0x0800		/* IP protocol */
#define ETHERTYPE_ARP	0x0806		/* Addr. resolution protocol */

#define SLIPTYPE_IP ETHERTYPE_IP
#define CSLIPTYPE_IP ETHERTYPE_IP

#define ARCOTYPE_IP     240	/* RFC 1051 framing */
#define ARCOTYPE_ARP    241	/* RFC 1051 framing */

#define ARCNTYPE_IP     212	/* RFC 1201 framing */
#define ARCNTYPE_ARP    213	/* RFC 1201 framing */
#define ARCNTYPE_RARP   214	/* RFC 1201 framing */

#define PPPTYPE_IP      0x21	/* RFC 1334 IP protocol */

#endif
