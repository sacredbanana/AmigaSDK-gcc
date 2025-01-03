#ifndef NETDB_H
#define NETDB_H
/*
 *      Network Database Structures and Defintions
 *
 *      Copyright � 1994 AmiTCP/IP Group,
 *                       Network Solutions Development, Inc.
 *                       All rights reserved.
 *
 *  	$Id: netdb.h,v 1.5 2020/03/30 01:02:42 piru Exp $
 */

#include <sys/cdefs.h>

#define _PATH_DB            "ENV:sys/net"
#define _PATH_DBSAVE        "ENVARC:sys/net"
/*
 * Structures returned by network data base library.  All addresses are
 * supplied in host order, and returned in network order (suitable for
 * use in system calls).
 */
struct hostent {
	char    *h_name;           /* official name of host */
	char    **h_aliases;       /* alias list */
	int	    h_addrtype;        /* host address type */
	int	    h_length;          /* length of address */
	char    **h_addr_list;	   /* list of addresses from name server */
#define	h_addr	h_addr_list[0] /* address, for backward compatiblity */
};

/*
 * Assumption here is that a network number
 * fits in 32 bits -- probably a poor one.
 */
struct netent {
	char          *n_name;     /* official name of net */
	char          **n_aliases; /* alias list */
	int           n_addrtype;  /* net address type */
	unsigned long n_net;       /* network # */
};

struct servent {
	char *s_name;     /* official service name */
	char **s_aliases; /* alias list */
	int	 s_port;      /* port # */
	char *s_proto;    /* protocol to use */
};

struct protoent {
	char	*p_name;	/* official protocol name */
	char	**p_aliases;	/* alias list */
	int	p_proto;	/* protocol # */
};

/*
 * Error return codes from gethostbyname() and gethostbyaddr()
 */
#ifndef KERNEL
__BEGIN_DECLS
extern int *__h_errno_location (void) __THROW __attribute__ ((__const__));
#ifndef h_errno
#define h_errno (*__h_errno_location ())
#endif
__END_DECLS
#endif

#define	HOST_NOT_FOUND	1 /* Authoritative Answer Host not found */
#define	TRY_AGAIN	2 /* Non-Authoritive Host not found, or SERVERFAIL */
#define	NO_RECOVERY	3 /* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
#define	NO_DATA		4 /* Valid name, no data record of requested type */
#define	NO_ADDRESS	NO_DATA		/* no address, look for MX record */

#endif /* !NETDB_H */
