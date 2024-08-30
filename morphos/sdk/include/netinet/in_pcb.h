/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *      @(#)in_pcb.h    7.3 (Berkeley) 6/29/88
 */

#ifndef _NETINET_IN_PCB_H_
#define _NETINET_IN_PCB_H_

/*
 * Common structure pcb for internet protocol implementation.
 * Here are stored pointers to local and foreign host table
 * entries, local and foreign socket numbers, and pointers
 * up (to a socket structure) and down (to a protocol-specific)
 * control block.
 */
struct inpcb {
	struct  inpcb *inp_next,*inp_prev;
					/* pointers to other pcb's */
	struct  inpcb *inp_head;        /* pointer back to chain of inpcb's
					   for this protocol */
	struct  in_addr inp_faddr;      /* foreign host table entry */
	u_short inp_fport;              /* foreign port */
	struct  in_addr __ALIGN2__ inp_laddr;/* local host table entry */
	u_short inp_lport;              /* local port */
	struct  socket *__ALIGN2__ inp_socket;/* back pointer to socket */
	caddr_t __ALIGN2__ inp_ppcb;    /* pointer to per-protocol pcb */
	struct  route __ALIGN2__ inp_route;/* placeholder for routing entry */
	struct  mbuf *__ALIGN2__ inp_options;/* IP options */
} __PACKED__;

#define INPLOOKUP_WILDCARD      1
#define INPLOOKUP_SETLOCAL      2

#define sotoinpcb(so)   ((struct inpcb *)(so)->so_pcb)

#ifdef _KERNEL
struct  inpcb *in_pcblookup();
#endif

#endif /* _NETINET_IN_PCB_H_ */
