/*
 * $VER: bsdsocket.h 54.16 (22.08.2022)
 *
 * :ts=8
 *
 * 'Roadshow' -- Amiga TCP/IP stack
 * Copyright © 2001-2016 by Olaf Barthel.
 * All Rights Reserved.
 *
 * Amiga specific TCP/IP 'C' header files;
 * Freely Distributable
 */

/*
 * This file was created with fd2pragma V2.171 using the following options:
 *
 * fd2pragma bsdsocket_lib.sfd to RAM:inline special 46
 *
 * The 'struct timeval' was replaced by 'struct __timeval'.
 */

#ifndef INLINE_BSDSOCKET_H
#define INLINE_BSDSOCKET_H

#ifndef CLIB_BSDSOCKET_PROTOS_H
#define CLIB_BSDSOCKET_PROTOS_H
#endif

#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  NETINET_IN_H
#include <netinet/in.h>
#endif
#ifndef  SYS_SOCKET_H
#include <sys/socket.h>
#endif
#ifndef  SYS_MBUF_H
#include <sys/mbuf.h>
#endif
#ifndef  NET_ROUTE_H
#include <net/route.h>
#endif
#ifndef  NETDB_H
#include <netdb.h>
#endif
#ifndef  LIBRARIES_BSDSOCKET_H
#include <libraries/bsdsocket.h>
#endif
#ifndef  DOS_DOSEXTENS_H
#include <dos/dosextens.h>
#endif

#ifndef BSDSOCKET_BASE_NAME
#define BSDSOCKET_BASE_NAME SocketBase
#endif

#define socket(domain, type, protocol) ({ \
  LONG _socket_domain = (domain); \
  LONG _socket_type = (type); \
  LONG _socket_protocol = (protocol); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __socket__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __socket__re __asm("d0"); \
  register LONG __socket_domain __asm("d0") = (_socket_domain); \
  register LONG __socket_type __asm("d1") = (_socket_type); \
  register LONG __socket_protocol __asm("d2") = (_socket_protocol); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__socket__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__socket__bn), "rf"(__socket_domain), "rf"(__socket_type), "rf"(__socket_protocol) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bind(sock, name, namelen) ({ \
  LONG _bind_sock = (sock); \
  struct sockaddr * _bind_name = (name); \
  LONG _bind_namelen = (namelen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bind__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bind__re __asm("d0"); \
  register LONG __bind_sock __asm("d0") = (_bind_sock); \
  register struct sockaddr * __bind_name __asm("a0") = (_bind_name); \
  register LONG __bind_namelen __asm("d1") = (_bind_namelen); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__bind__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bind__bn), "rf"(__bind_sock), "rf"(__bind_name), "rf"(__bind_namelen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define listen(sock, backlog) ({ \
  LONG _listen_sock = (sock); \
  LONG _listen_backlog = (backlog); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __listen__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __listen__re __asm("d0"); \
  register LONG __listen_sock __asm("d0") = (_listen_sock); \
  register LONG __listen_backlog __asm("d1") = (_listen_backlog); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__listen__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__listen__bn), "rf"(__listen_sock), "rf"(__listen_backlog) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define accept(sock, addr, addrlen) ({ \
  LONG _accept_sock = (sock); \
  struct sockaddr * _accept_addr = (addr); \
  socklen_t * _accept_addrlen = (addrlen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __accept__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __accept__re __asm("d0"); \
  register LONG __accept_sock __asm("d0") = (_accept_sock); \
  register struct sockaddr * __accept_addr __asm("a0") = (_accept_addr); \
  register socklen_t * __accept_addrlen __asm("a1") = (_accept_addrlen); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__accept__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__accept__bn), "rf"(__accept_sock), "rf"(__accept_addr), "rf"(__accept_addrlen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define connect(sock, name, namelen) ({ \
  LONG _connect_sock = (sock); \
  struct sockaddr * _connect_name = (name); \
  LONG _connect_namelen = (namelen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __connect__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __connect__re __asm("d0"); \
  register LONG __connect_sock __asm("d0") = (_connect_sock); \
  register struct sockaddr * __connect_name __asm("a0") = (_connect_name); \
  register LONG __connect_namelen __asm("d1") = (_connect_namelen); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__connect__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__connect__bn), "rf"(__connect_sock), "rf"(__connect_name), "rf"(__connect_namelen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define sendto(sock, buf, len, flags, to, tolen) ({ \
  LONG _sendto_sock = (sock); \
  APTR _sendto_buf = (buf); \
  LONG _sendto_len = (len); \
  LONG _sendto_flags = (flags); \
  struct sockaddr * _sendto_to = (to); \
  LONG _sendto_tolen = (tolen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __sendto__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __sendto__re __asm("d0"); \
  register LONG __sendto_sock __asm("d0") = (_sendto_sock); \
  register APTR __sendto_buf __asm("a0") = (_sendto_buf); \
  register LONG __sendto_len __asm("d1") = (_sendto_len); \
  register LONG __sendto_flags __asm("d2") = (_sendto_flags); \
  register struct sockaddr * __sendto_to __asm("a1") = (_sendto_to); \
  register LONG __sendto_tolen __asm("d3") = (_sendto_tolen); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__sendto__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__sendto__bn), "rf"(__sendto_sock), "rf"(__sendto_buf), "rf"(__sendto_len), "rf"(__sendto_flags), "rf"(__sendto_to), "rf"(__sendto_tolen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define send(sock, buf, len, flags) ({ \
  LONG _send_sock = (sock); \
  APTR _send_buf = (buf); \
  LONG _send_len = (len); \
  LONG _send_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __send__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __send__re __asm("d0"); \
  register LONG __send_sock __asm("d0") = (_send_sock); \
  register APTR __send_buf __asm("a0") = (_send_buf); \
  register LONG __send_len __asm("d1") = (_send_len); \
  register LONG __send_flags __asm("d2") = (_send_flags); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__send__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__send__bn), "rf"(__send_sock), "rf"(__send_buf), "rf"(__send_len), "rf"(__send_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define recvfrom(sock, buf, len, flags, addr, addrlen) ({ \
  LONG _recvfrom_sock = (sock); \
  APTR _recvfrom_buf = (buf); \
  LONG _recvfrom_len = (len); \
  LONG _recvfrom_flags = (flags); \
  struct sockaddr * _recvfrom_addr = (addr); \
  socklen_t * _recvfrom_addrlen = (addrlen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __recvfrom__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __recvfrom__re __asm("d0"); \
  register LONG __recvfrom_sock __asm("d0") = (_recvfrom_sock); \
  register APTR __recvfrom_buf __asm("a0") = (_recvfrom_buf); \
  register LONG __recvfrom_len __asm("d1") = (_recvfrom_len); \
  register LONG __recvfrom_flags __asm("d2") = (_recvfrom_flags); \
  register struct sockaddr * __recvfrom_addr __asm("a1") = (_recvfrom_addr); \
  register socklen_t * __recvfrom_addrlen __asm("a2") = (_recvfrom_addrlen); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__recvfrom__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__recvfrom__bn), "rf"(__recvfrom_sock), "rf"(__recvfrom_buf), "rf"(__recvfrom_len), "rf"(__recvfrom_flags), "rf"(__recvfrom_addr), "rf"(__recvfrom_addrlen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define recv(sock, buf, len, flags) ({ \
  LONG _recv_sock = (sock); \
  APTR _recv_buf = (buf); \
  LONG _recv_len = (len); \
  LONG _recv_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __recv__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __recv__re __asm("d0"); \
  register LONG __recv_sock __asm("d0") = (_recv_sock); \
  register APTR __recv_buf __asm("a0") = (_recv_buf); \
  register LONG __recv_len __asm("d1") = (_recv_len); \
  register LONG __recv_flags __asm("d2") = (_recv_flags); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__recv__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__recv__bn), "rf"(__recv_sock), "rf"(__recv_buf), "rf"(__recv_len), "rf"(__recv_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define shutdown(sock, how) ({ \
  LONG _shutdown_sock = (sock); \
  LONG _shutdown_how = (how); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __shutdown__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __shutdown__re __asm("d0"); \
  register LONG __shutdown_sock __asm("d0") = (_shutdown_sock); \
  register LONG __shutdown_how __asm("d1") = (_shutdown_how); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__shutdown__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__shutdown__bn), "rf"(__shutdown_sock), "rf"(__shutdown_how) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define setsockopt(sock, level, optname, optval, optlen) ({ \
  LONG _setsockopt_sock = (sock); \
  LONG _setsockopt_level = (level); \
  LONG _setsockopt_optname = (optname); \
  APTR _setsockopt_optval = (optval); \
  LONG _setsockopt_optlen = (optlen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __setsockopt__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __setsockopt__re __asm("d0"); \
  register LONG __setsockopt_sock __asm("d0") = (_setsockopt_sock); \
  register LONG __setsockopt_level __asm("d1") = (_setsockopt_level); \
  register LONG __setsockopt_optname __asm("d2") = (_setsockopt_optname); \
  register APTR __setsockopt_optval __asm("a0") = (_setsockopt_optval); \
  register LONG __setsockopt_optlen __asm("d3") = (_setsockopt_optlen); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__setsockopt__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__setsockopt__bn), "rf"(__setsockopt_sock), "rf"(__setsockopt_level), "rf"(__setsockopt_optname), "rf"(__setsockopt_optval), "rf"(__setsockopt_optlen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getsockopt(sock, level, optname, optval, optlen) ({ \
  LONG _getsockopt_sock = (sock); \
  LONG _getsockopt_level = (level); \
  LONG _getsockopt_optname = (optname); \
  APTR _getsockopt_optval = (optval); \
  socklen_t * _getsockopt_optlen = (optlen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getsockopt__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __getsockopt__re __asm("d0"); \
  register LONG __getsockopt_sock __asm("d0") = (_getsockopt_sock); \
  register LONG __getsockopt_level __asm("d1") = (_getsockopt_level); \
  register LONG __getsockopt_optname __asm("d2") = (_getsockopt_optname); \
  register APTR __getsockopt_optval __asm("a0") = (_getsockopt_optval); \
  register socklen_t * __getsockopt_optlen __asm("a1") = (_getsockopt_optlen); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__getsockopt__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getsockopt__bn), "rf"(__getsockopt_sock), "rf"(__getsockopt_level), "rf"(__getsockopt_optname), "rf"(__getsockopt_optval), "rf"(__getsockopt_optlen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getsockname(sock, name, namelen) ({ \
  LONG _getsockname_sock = (sock); \
  struct sockaddr * _getsockname_name = (name); \
  socklen_t * _getsockname_namelen = (namelen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getsockname__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __getsockname__re __asm("d0"); \
  register LONG __getsockname_sock __asm("d0") = (_getsockname_sock); \
  register struct sockaddr * __getsockname_name __asm("a0") = (_getsockname_name); \
  register socklen_t * __getsockname_namelen __asm("a1") = (_getsockname_namelen); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__getsockname__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getsockname__bn), "rf"(__getsockname_sock), "rf"(__getsockname_name), "rf"(__getsockname_namelen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getpeername(sock, name, namelen) ({ \
  LONG _getpeername_sock = (sock); \
  struct sockaddr * _getpeername_name = (name); \
  socklen_t * _getpeername_namelen = (namelen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getpeername__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __getpeername__re __asm("d0"); \
  register LONG __getpeername_sock __asm("d0") = (_getpeername_sock); \
  register struct sockaddr * __getpeername_name __asm("a0") = (_getpeername_name); \
  register socklen_t * __getpeername_namelen __asm("a1") = (_getpeername_namelen); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__getpeername__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getpeername__bn), "rf"(__getpeername_sock), "rf"(__getpeername_name), "rf"(__getpeername_namelen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define IoctlSocket(sock, req, argp) ({ \
  LONG _IoctlSocket_sock = (sock); \
  ULONG _IoctlSocket_req = (req); \
  APTR _IoctlSocket_argp = (argp); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __IoctlSocket__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __IoctlSocket__re __asm("d0"); \
  register LONG __IoctlSocket_sock __asm("d0") = (_IoctlSocket_sock); \
  register ULONG __IoctlSocket_req __asm("d1") = (_IoctlSocket_req); \
  register APTR __IoctlSocket_argp __asm("a0") = (_IoctlSocket_argp); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__IoctlSocket__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__IoctlSocket__bn), "rf"(__IoctlSocket_sock), "rf"(__IoctlSocket_req), "rf"(__IoctlSocket_argp) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define CloseSocket(sock) ({ \
  LONG _CloseSocket_sock = (sock); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CloseSocket__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __CloseSocket__re __asm("d0"); \
  register LONG __CloseSocket_sock __asm("d0") = (_CloseSocket_sock); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__CloseSocket__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CloseSocket__bn), "rf"(__CloseSocket_sock) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define WaitSelect(nfds, read_fds, write_fds, except_fds, _timeout, signals) ({ \
  LONG _WaitSelect_nfds = (nfds); \
  APTR _WaitSelect_read_fds = (read_fds); \
  APTR _WaitSelect_write_fds = (write_fds); \
  APTR _WaitSelect_except_fds = (except_fds); \
  struct __timeval * _WaitSelect__timeout = (_timeout); \
  ULONG * _WaitSelect_signals = (signals); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __WaitSelect__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __WaitSelect__re __asm("d0"); \
  register LONG __WaitSelect_nfds __asm("d0") = (_WaitSelect_nfds); \
  register APTR __WaitSelect_read_fds __asm("a0") = (_WaitSelect_read_fds); \
  register APTR __WaitSelect_write_fds __asm("a1") = (_WaitSelect_write_fds); \
  register APTR __WaitSelect_except_fds __asm("a2") = (_WaitSelect_except_fds); \
  register struct __timeval * __WaitSelect__timeout __asm("a3") = (_WaitSelect__timeout); \
  register ULONG * __WaitSelect_signals __asm("d1") = (_WaitSelect_signals); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__WaitSelect__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__WaitSelect__bn), "rf"(__WaitSelect_nfds), "rf"(__WaitSelect_read_fds), "rf"(__WaitSelect_write_fds), "rf"(__WaitSelect_except_fds), "rf"(__WaitSelect__timeout), "rf"(__WaitSelect_signals) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetSocketSignals(int_mask, io_mask, urgent_mask) ({ \
  ULONG _SetSocketSignals_int_mask = (int_mask); \
  ULONG _SetSocketSignals_io_mask = (io_mask); \
  ULONG _SetSocketSignals_urgent_mask = (urgent_mask); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetSocketSignals__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register ULONG __SetSocketSignals_int_mask __asm("d0") = (_SetSocketSignals_int_mask); \
  register ULONG __SetSocketSignals_io_mask __asm("d1") = (_SetSocketSignals_io_mask); \
  register ULONG __SetSocketSignals_urgent_mask __asm("d2") = (_SetSocketSignals_urgent_mask); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetSocketSignals__bn), "rf"(__SetSocketSignals_int_mask), "rf"(__SetSocketSignals_io_mask), "rf"(__SetSocketSignals_urgent_mask) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define getdtablesize() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getdtablesize__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __getdtablesize__re __asm("d0"); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__getdtablesize__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getdtablesize__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ObtainSocket(id, domain, type, protocol) ({ \
  LONG _ObtainSocket_id = (id); \
  LONG _ObtainSocket_domain = (domain); \
  LONG _ObtainSocket_type = (type); \
  LONG _ObtainSocket_protocol = (protocol); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ObtainSocket__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __ObtainSocket__re __asm("d0"); \
  register LONG __ObtainSocket_id __asm("d0") = (_ObtainSocket_id); \
  register LONG __ObtainSocket_domain __asm("d1") = (_ObtainSocket_domain); \
  register LONG __ObtainSocket_type __asm("d2") = (_ObtainSocket_type); \
  register LONG __ObtainSocket_protocol __asm("d3") = (_ObtainSocket_protocol); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__ObtainSocket__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ObtainSocket__bn), "rf"(__ObtainSocket_id), "rf"(__ObtainSocket_domain), "rf"(__ObtainSocket_type), "rf"(__ObtainSocket_protocol) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReleaseSocket(sock, id) ({ \
  LONG _ReleaseSocket_sock = (sock); \
  LONG _ReleaseSocket_id = (id); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReleaseSocket__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __ReleaseSocket__re __asm("d0"); \
  register LONG __ReleaseSocket_sock __asm("d0") = (_ReleaseSocket_sock); \
  register LONG __ReleaseSocket_id __asm("d1") = (_ReleaseSocket_id); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__ReleaseSocket__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReleaseSocket__bn), "rf"(__ReleaseSocket_sock), "rf"(__ReleaseSocket_id) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReleaseCopyOfSocket(sock, id) ({ \
  LONG _ReleaseCopyOfSocket_sock = (sock); \
  LONG _ReleaseCopyOfSocket_id = (id); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReleaseCopyOfSocket__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __ReleaseCopyOfSocket__re __asm("d0"); \
  register LONG __ReleaseCopyOfSocket_sock __asm("d0") = (_ReleaseCopyOfSocket_sock); \
  register LONG __ReleaseCopyOfSocket_id __asm("d1") = (_ReleaseCopyOfSocket_id); \
  __asm volatile ("jsr a6@(-156:W)" \
  : "=r"(__ReleaseCopyOfSocket__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReleaseCopyOfSocket__bn), "rf"(__ReleaseCopyOfSocket_sock), "rf"(__ReleaseCopyOfSocket_id) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Errno() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Errno__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __Errno__re __asm("d0"); \
  __asm volatile ("jsr a6@(-162:W)" \
  : "=r"(__Errno__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Errno__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetErrnoPtr(errno_ptr, size) ({ \
  APTR _SetErrnoPtr_errno_ptr = (errno_ptr); \
  LONG _SetErrnoPtr_size = (size); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetErrnoPtr__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register APTR __SetErrnoPtr_errno_ptr __asm("a0") = (_SetErrnoPtr_errno_ptr); \
  register LONG __SetErrnoPtr_size __asm("d0") = (_SetErrnoPtr_size); \
  __asm volatile ("jsr a6@(-168:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetErrnoPtr__bn), "rf"(__SetErrnoPtr_errno_ptr), "rf"(__SetErrnoPtr_size) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Inet_NtoA(ip) ({ \
  LONG _Inet_NtoA_ip = (ip); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Inet_NtoA__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register STRPTR __Inet_NtoA__re __asm("d0"); \
  register LONG __Inet_NtoA_ip __asm("d0") = (_Inet_NtoA_ip); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__Inet_NtoA__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Inet_NtoA__bn), "rf"(__Inet_NtoA_ip) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define inet_addr(cp) ({ \
  STRPTR _inet_addr_cp = (cp); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __inet_addr__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register in_addr_t __inet_addr__re __asm("d0"); \
  register STRPTR __inet_addr_cp __asm("a0") = (_inet_addr_cp); \
  __asm volatile ("jsr a6@(-180:W)" \
  : "=r"(__inet_addr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__inet_addr__bn), "rf"(__inet_addr_cp) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Inet_LnaOf(in) ({ \
  LONG _Inet_LnaOf_in = (in); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Inet_LnaOf__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register in_addr_t __Inet_LnaOf__re __asm("d0"); \
  register LONG __Inet_LnaOf_in __asm("d0") = (_Inet_LnaOf_in); \
  __asm volatile ("jsr a6@(-186:W)" \
  : "=r"(__Inet_LnaOf__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Inet_LnaOf__bn), "rf"(__Inet_LnaOf_in) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Inet_NetOf(in) ({ \
  LONG _Inet_NetOf_in = (in); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Inet_NetOf__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register in_addr_t __Inet_NetOf__re __asm("d0"); \
  register LONG __Inet_NetOf_in __asm("d0") = (_Inet_NetOf_in); \
  __asm volatile ("jsr a6@(-192:W)" \
  : "=r"(__Inet_NetOf__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Inet_NetOf__bn), "rf"(__Inet_NetOf_in) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define Inet_MakeAddr(net, host) ({ \
  LONG _Inet_MakeAddr_net = (net); \
  LONG _Inet_MakeAddr_host = (host); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Inet_MakeAddr__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register in_addr_t __Inet_MakeAddr__re __asm("d0"); \
  register LONG __Inet_MakeAddr_net __asm("d0") = (_Inet_MakeAddr_net); \
  register LONG __Inet_MakeAddr_host __asm("d1") = (_Inet_MakeAddr_host); \
  __asm volatile ("jsr a6@(-198:W)" \
  : "=r"(__Inet_MakeAddr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Inet_MakeAddr__bn), "rf"(__Inet_MakeAddr_net), "rf"(__Inet_MakeAddr_host) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define inet_network(cp) ({ \
  STRPTR _inet_network_cp = (cp); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __inet_network__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register in_addr_t __inet_network__re __asm("d0"); \
  register STRPTR __inet_network_cp __asm("a0") = (_inet_network_cp); \
  __asm volatile ("jsr a6@(-204:W)" \
  : "=r"(__inet_network__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__inet_network__bn), "rf"(__inet_network_cp) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define gethostbyname(name) ({ \
  STRPTR _gethostbyname_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __gethostbyname__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct hostent * __gethostbyname__re __asm("d0"); \
  register STRPTR __gethostbyname_name __asm("a0") = (_gethostbyname_name); \
  __asm volatile ("jsr a6@(-210:W)" \
  : "=r"(__gethostbyname__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__gethostbyname__bn), "rf"(__gethostbyname_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define gethostbyaddr(addr, len, type) ({ \
  STRPTR _gethostbyaddr_addr = (addr); \
  LONG _gethostbyaddr_len = (len); \
  LONG _gethostbyaddr_type = (type); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __gethostbyaddr__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct hostent * __gethostbyaddr__re __asm("d0"); \
  register STRPTR __gethostbyaddr_addr __asm("a0") = (_gethostbyaddr_addr); \
  register LONG __gethostbyaddr_len __asm("d0") = (_gethostbyaddr_len); \
  register LONG __gethostbyaddr_type __asm("d1") = (_gethostbyaddr_type); \
  __asm volatile ("jsr a6@(-216:W)" \
  : "=r"(__gethostbyaddr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__gethostbyaddr__bn), "rf"(__gethostbyaddr_addr), "rf"(__gethostbyaddr_len), "rf"(__gethostbyaddr_type) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getnetbyname(name) ({ \
  STRPTR _getnetbyname_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getnetbyname__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct netent * __getnetbyname__re __asm("d0"); \
  register STRPTR __getnetbyname_name __asm("a0") = (_getnetbyname_name); \
  __asm volatile ("jsr a6@(-222:W)" \
  : "=r"(__getnetbyname__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getnetbyname__bn), "rf"(__getnetbyname_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getnetbyaddr(net, type) ({ \
  LONG _getnetbyaddr_net = (net); \
  LONG _getnetbyaddr_type = (type); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getnetbyaddr__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct netent * __getnetbyaddr__re __asm("d0"); \
  register LONG __getnetbyaddr_net __asm("d0") = (_getnetbyaddr_net); \
  register LONG __getnetbyaddr_type __asm("d1") = (_getnetbyaddr_type); \
  __asm volatile ("jsr a6@(-228:W)" \
  : "=r"(__getnetbyaddr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getnetbyaddr__bn), "rf"(__getnetbyaddr_net), "rf"(__getnetbyaddr_type) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getservbyname(name, proto) ({ \
  STRPTR _getservbyname_name = (name); \
  STRPTR _getservbyname_proto = (proto); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getservbyname__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct servent * __getservbyname__re __asm("d0"); \
  register STRPTR __getservbyname_name __asm("a0") = (_getservbyname_name); \
  register STRPTR __getservbyname_proto __asm("a1") = (_getservbyname_proto); \
  __asm volatile ("jsr a6@(-234:W)" \
  : "=r"(__getservbyname__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getservbyname__bn), "rf"(__getservbyname_name), "rf"(__getservbyname_proto) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getservbyport(port, proto) ({ \
  LONG _getservbyport_port = (port); \
  STRPTR _getservbyport_proto = (proto); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getservbyport__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct servent * __getservbyport__re __asm("d0"); \
  register LONG __getservbyport_port __asm("d0") = (_getservbyport_port); \
  register STRPTR __getservbyport_proto __asm("a0") = (_getservbyport_proto); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__getservbyport__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getservbyport__bn), "rf"(__getservbyport_port), "rf"(__getservbyport_proto) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getprotobyname(name) ({ \
  STRPTR _getprotobyname_name = (name); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getprotobyname__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct protoent * __getprotobyname__re __asm("d0"); \
  register STRPTR __getprotobyname_name __asm("a0") = (_getprotobyname_name); \
  __asm volatile ("jsr a6@(-246:W)" \
  : "=r"(__getprotobyname__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getprotobyname__bn), "rf"(__getprotobyname_name) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getprotobynumber(proto) ({ \
  LONG _getprotobynumber_proto = (proto); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getprotobynumber__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct protoent * __getprotobynumber__re __asm("d0"); \
  register LONG __getprotobynumber_proto __asm("d0") = (_getprotobynumber_proto); \
  __asm volatile ("jsr a6@(-252:W)" \
  : "=r"(__getprotobynumber__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getprotobynumber__bn), "rf"(__getprotobynumber_proto) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define vsyslog(pri, msg, args) ({ \
  LONG _vsyslog_pri = (pri); \
  STRPTR _vsyslog_msg = (msg); \
  APTR _vsyslog_args = (args); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __vsyslog__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __vsyslog_pri __asm("d0") = (_vsyslog_pri); \
  register STRPTR __vsyslog_msg __asm("a0") = (_vsyslog_msg); \
  register APTR __vsyslog_args __asm("a1") = (_vsyslog_args); \
  __asm volatile ("jsr a6@(-258:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__vsyslog__bn), "rf"(__vsyslog_pri), "rf"(__vsyslog_msg), "rf"(__vsyslog_args) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___syslog(struct Library * SocketBase, LONG pri, STRPTR msg, LONG args, ...)
{
  vsyslog(pri, msg, (APTR) &args);
}

#define syslog(pri, msg...) ___syslog(BSDSOCKET_BASE_NAME, pri, msg)
#endif

#define Dup2Socket(old_socket, new_socket) ({ \
  LONG _Dup2Socket_old_socket = (old_socket); \
  LONG _Dup2Socket_new_socket = (new_socket); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __Dup2Socket__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __Dup2Socket__re __asm("d0"); \
  register LONG __Dup2Socket_old_socket __asm("d0") = (_Dup2Socket_old_socket); \
  register LONG __Dup2Socket_new_socket __asm("d1") = (_Dup2Socket_new_socket); \
  __asm volatile ("jsr a6@(-264:W)" \
  : "=r"(__Dup2Socket__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__Dup2Socket__bn), "rf"(__Dup2Socket_old_socket), "rf"(__Dup2Socket_new_socket) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define sendmsg(sock, msg, flags) ({ \
  LONG _sendmsg_sock = (sock); \
  struct msghdr * _sendmsg_msg = (msg); \
  LONG _sendmsg_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __sendmsg__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __sendmsg__re __asm("d0"); \
  register LONG __sendmsg_sock __asm("d0") = (_sendmsg_sock); \
  register struct msghdr * __sendmsg_msg __asm("a0") = (_sendmsg_msg); \
  register LONG __sendmsg_flags __asm("d1") = (_sendmsg_flags); \
  __asm volatile ("jsr a6@(-270:W)" \
  : "=r"(__sendmsg__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__sendmsg__bn), "rf"(__sendmsg_sock), "rf"(__sendmsg_msg), "rf"(__sendmsg_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define recvmsg(sock, msg, flags) ({ \
  LONG _recvmsg_sock = (sock); \
  struct msghdr * _recvmsg_msg = (msg); \
  LONG _recvmsg_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __recvmsg__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __recvmsg__re __asm("d0"); \
  register LONG __recvmsg_sock __asm("d0") = (_recvmsg_sock); \
  register struct msghdr * __recvmsg_msg __asm("a0") = (_recvmsg_msg); \
  register LONG __recvmsg_flags __asm("d1") = (_recvmsg_flags); \
  __asm volatile ("jsr a6@(-276:W)" \
  : "=r"(__recvmsg__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__recvmsg__bn), "rf"(__recvmsg_sock), "rf"(__recvmsg_msg), "rf"(__recvmsg_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define gethostname(name, namelen) ({ \
  STRPTR _gethostname_name = (name); \
  LONG _gethostname_namelen = (namelen); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __gethostname__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __gethostname__re __asm("d0"); \
  register STRPTR __gethostname_name __asm("a0") = (_gethostname_name); \
  register LONG __gethostname_namelen __asm("d0") = (_gethostname_namelen); \
  __asm volatile ("jsr a6@(-282:W)" \
  : "=r"(__gethostname__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__gethostname__bn), "rf"(__gethostname_name), "rf"(__gethostname_namelen) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define gethostid() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __gethostid__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register in_addr_t __gethostid__re __asm("d0"); \
  __asm volatile ("jsr a6@(-288:W)" \
  : "=r"(__gethostid__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__gethostid__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SocketBaseTagList(tags) ({ \
  struct TagItem * _SocketBaseTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SocketBaseTagList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __SocketBaseTagList__re __asm("d0"); \
  register struct TagItem * __SocketBaseTagList_tags __asm("a0") = (_SocketBaseTagList_tags); \
  __asm volatile ("jsr a6@(-294:W)" \
  : "=r"(__SocketBaseTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SocketBaseTagList__bn), "rf"(__SocketBaseTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SocketBaseTags(struct Library * SocketBase, Tag tags, ...)
{
  return SocketBaseTagList((struct TagItem *) &tags);
}

#define SocketBaseTags(tags...) ___SocketBaseTags(BSDSOCKET_BASE_NAME, tags)
#endif

#define GetSocketEvents(event_ptr) ({ \
  ULONG * _GetSocketEvents_event_ptr = (event_ptr); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetSocketEvents__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __GetSocketEvents__re __asm("d0"); \
  register ULONG * __GetSocketEvents_event_ptr __asm("a0") = (_GetSocketEvents_event_ptr); \
  __asm volatile ("jsr a6@(-300:W)" \
  : "=r"(__GetSocketEvents__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetSocketEvents__bn), "rf"(__GetSocketEvents_event_ptr) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bpf_open(channel) ({ \
  LONG _bpf_open_channel = (channel); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bpf_open__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bpf_open__re __asm("d0"); \
  register LONG __bpf_open_channel __asm("d0") = (_bpf_open_channel); \
  __asm volatile ("jsr a6@(-366:W)" \
  : "=r"(__bpf_open__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bpf_open__bn), "rf"(__bpf_open_channel) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bpf_close(channel) ({ \
  LONG _bpf_close_channel = (channel); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bpf_close__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bpf_close__re __asm("d0"); \
  register LONG __bpf_close_channel __asm("d0") = (_bpf_close_channel); \
  __asm volatile ("jsr a6@(-372:W)" \
  : "=r"(__bpf_close__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bpf_close__bn), "rf"(__bpf_close_channel) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bpf_read(channel, buffer, len) ({ \
  LONG _bpf_read_channel = (channel); \
  APTR _bpf_read_buffer = (buffer); \
  LONG _bpf_read_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bpf_read__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bpf_read__re __asm("d0"); \
  register LONG __bpf_read_channel __asm("d0") = (_bpf_read_channel); \
  register APTR __bpf_read_buffer __asm("a0") = (_bpf_read_buffer); \
  register LONG __bpf_read_len __asm("d1") = (_bpf_read_len); \
  __asm volatile ("jsr a6@(-378:W)" \
  : "=r"(__bpf_read__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bpf_read__bn), "rf"(__bpf_read_channel), "rf"(__bpf_read_buffer), "rf"(__bpf_read_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bpf_write(channel, buffer, len) ({ \
  LONG _bpf_write_channel = (channel); \
  APTR _bpf_write_buffer = (buffer); \
  LONG _bpf_write_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bpf_write__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bpf_write__re __asm("d0"); \
  register LONG __bpf_write_channel __asm("d0") = (_bpf_write_channel); \
  register APTR __bpf_write_buffer __asm("a0") = (_bpf_write_buffer); \
  register LONG __bpf_write_len __asm("d1") = (_bpf_write_len); \
  __asm volatile ("jsr a6@(-384:W)" \
  : "=r"(__bpf_write__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bpf_write__bn), "rf"(__bpf_write_channel), "rf"(__bpf_write_buffer), "rf"(__bpf_write_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bpf_set_notify_mask(channel, signal_mask) ({ \
  LONG _bpf_set_notify_mask_channel = (channel); \
  ULONG _bpf_set_notify_mask_signal_mask = (signal_mask); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bpf_set_notify_mask__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bpf_set_notify_mask__re __asm("d0"); \
  register LONG __bpf_set_notify_mask_channel __asm("d1") = (_bpf_set_notify_mask_channel); \
  register ULONG __bpf_set_notify_mask_signal_mask __asm("d0") = (_bpf_set_notify_mask_signal_mask); \
  __asm volatile ("jsr a6@(-390:W)" \
  : "=r"(__bpf_set_notify_mask__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bpf_set_notify_mask__bn), "rf"(__bpf_set_notify_mask_channel), "rf"(__bpf_set_notify_mask_signal_mask) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bpf_set_interrupt_mask(channel, signal_mask) ({ \
  LONG _bpf_set_interrupt_mask_channel = (channel); \
  ULONG _bpf_set_interrupt_mask_signal_mask = (signal_mask); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bpf_set_interrupt_mask__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bpf_set_interrupt_mask__re __asm("d0"); \
  register LONG __bpf_set_interrupt_mask_channel __asm("d0") = (_bpf_set_interrupt_mask_channel); \
  register ULONG __bpf_set_interrupt_mask_signal_mask __asm("d1") = (_bpf_set_interrupt_mask_signal_mask); \
  __asm volatile ("jsr a6@(-396:W)" \
  : "=r"(__bpf_set_interrupt_mask__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bpf_set_interrupt_mask__bn), "rf"(__bpf_set_interrupt_mask_channel), "rf"(__bpf_set_interrupt_mask_signal_mask) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bpf_ioctl(channel, command, buffer) ({ \
  LONG _bpf_ioctl_channel = (channel); \
  ULONG _bpf_ioctl_command = (command); \
  APTR _bpf_ioctl_buffer = (buffer); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bpf_ioctl__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bpf_ioctl__re __asm("d0"); \
  register LONG __bpf_ioctl_channel __asm("d0") = (_bpf_ioctl_channel); \
  register ULONG __bpf_ioctl_command __asm("d1") = (_bpf_ioctl_command); \
  register APTR __bpf_ioctl_buffer __asm("a0") = (_bpf_ioctl_buffer); \
  __asm volatile ("jsr a6@(-402:W)" \
  : "=r"(__bpf_ioctl__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bpf_ioctl__bn), "rf"(__bpf_ioctl_channel), "rf"(__bpf_ioctl_command), "rf"(__bpf_ioctl_buffer) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define bpf_data_waiting(channel) ({ \
  LONG _bpf_data_waiting_channel = (channel); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __bpf_data_waiting__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __bpf_data_waiting__re __asm("d0"); \
  register LONG __bpf_data_waiting_channel __asm("d0") = (_bpf_data_waiting_channel); \
  __asm volatile ("jsr a6@(-408:W)" \
  : "=r"(__bpf_data_waiting__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__bpf_data_waiting__bn), "rf"(__bpf_data_waiting_channel) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddRouteTagList(tags) ({ \
  struct TagItem * _AddRouteTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddRouteTagList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __AddRouteTagList__re __asm("d0"); \
  register struct TagItem * __AddRouteTagList_tags __asm("a0") = (_AddRouteTagList_tags); \
  __asm volatile ("jsr a6@(-414:W)" \
  : "=r"(__AddRouteTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddRouteTagList__bn), "rf"(__AddRouteTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___AddRouteTags(struct Library * SocketBase, Tag tags, ...)
{
  return AddRouteTagList((struct TagItem *) &tags);
}

#define AddRouteTags(tags...) ___AddRouteTags(BSDSOCKET_BASE_NAME, tags)
#endif

#define DeleteRouteTagList(tags) ({ \
  struct TagItem * _DeleteRouteTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DeleteRouteTagList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __DeleteRouteTagList__re __asm("d0"); \
  register struct TagItem * __DeleteRouteTagList_tags __asm("a0") = (_DeleteRouteTagList_tags); \
  __asm volatile ("jsr a6@(-420:W)" \
  : "=r"(__DeleteRouteTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DeleteRouteTagList__bn), "rf"(__DeleteRouteTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___DeleteRouteTags(struct Library * SocketBase, Tag tags, ...)
{
  return DeleteRouteTagList((struct TagItem *) &tags);
}

#define DeleteRouteTags(tags...) ___DeleteRouteTags(BSDSOCKET_BASE_NAME, tags)
#endif

#define FreeRouteInfo(buf) ({ \
  struct rt_msghdr * _FreeRouteInfo_buf = (buf); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __FreeRouteInfo__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct rt_msghdr * __FreeRouteInfo_buf __asm("a0") = (_FreeRouteInfo_buf); \
  __asm volatile ("jsr a6@(-432:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__FreeRouteInfo__bn), "rf"(__FreeRouteInfo_buf) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetRouteInfo(address_family, flags) ({ \
  LONG _GetRouteInfo_address_family = (address_family); \
  LONG _GetRouteInfo_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetRouteInfo__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct rt_msghdr * __GetRouteInfo__re __asm("d0"); \
  register LONG __GetRouteInfo_address_family __asm("d0") = (_GetRouteInfo_address_family); \
  register LONG __GetRouteInfo_flags __asm("d1") = (_GetRouteInfo_flags); \
  __asm volatile ("jsr a6@(-438:W)" \
  : "=r"(__GetRouteInfo__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetRouteInfo__bn), "rf"(__GetRouteInfo_address_family), "rf"(__GetRouteInfo_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddInterfaceTagList(interface_name, device_name, unit, tags) ({ \
  STRPTR _AddInterfaceTagList_interface_name = (interface_name); \
  STRPTR _AddInterfaceTagList_device_name = (device_name); \
  LONG _AddInterfaceTagList_unit = (unit); \
  struct TagItem * _AddInterfaceTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddInterfaceTagList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __AddInterfaceTagList__re __asm("d0"); \
  register STRPTR __AddInterfaceTagList_interface_name __asm("a0") = (_AddInterfaceTagList_interface_name); \
  register STRPTR __AddInterfaceTagList_device_name __asm("a1") = (_AddInterfaceTagList_device_name); \
  register LONG __AddInterfaceTagList_unit __asm("d0") = (_AddInterfaceTagList_unit); \
  register struct TagItem * __AddInterfaceTagList_tags __asm("a2") = (_AddInterfaceTagList_tags); \
  __asm volatile ("jsr a6@(-444:W)" \
  : "=r"(__AddInterfaceTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddInterfaceTagList__bn), "rf"(__AddInterfaceTagList_interface_name), "rf"(__AddInterfaceTagList_device_name), "rf"(__AddInterfaceTagList_unit), "rf"(__AddInterfaceTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___AddInterfaceTags(struct Library * SocketBase, STRPTR interface_name, STRPTR device_name, LONG unit, Tag tags, ...)
{
  return AddInterfaceTagList(interface_name, device_name, unit, (struct TagItem *) &tags);
}

#define AddInterfaceTags(interface_name, device_name, unit...) ___AddInterfaceTags(BSDSOCKET_BASE_NAME, interface_name, device_name, unit)
#endif

#define ConfigureInterfaceTagList(interface_name, tags) ({ \
  STRPTR _ConfigureInterfaceTagList_interface_name = (interface_name); \
  struct TagItem * _ConfigureInterfaceTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ConfigureInterfaceTagList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __ConfigureInterfaceTagList__re __asm("d0"); \
  register STRPTR __ConfigureInterfaceTagList_interface_name __asm("a0") = (_ConfigureInterfaceTagList_interface_name); \
  register struct TagItem * __ConfigureInterfaceTagList_tags __asm("a1") = (_ConfigureInterfaceTagList_tags); \
  __asm volatile ("jsr a6@(-450:W)" \
  : "=r"(__ConfigureInterfaceTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ConfigureInterfaceTagList__bn), "rf"(__ConfigureInterfaceTagList_interface_name), "rf"(__ConfigureInterfaceTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___ConfigureInterfaceTags(struct Library * SocketBase, STRPTR interface_name, Tag tags, ...)
{
  return ConfigureInterfaceTagList(interface_name, (struct TagItem *) &tags);
}

#define ConfigureInterfaceTags(interface_name...) ___ConfigureInterfaceTags(BSDSOCKET_BASE_NAME, interface_name)
#endif

#define ReleaseInterfaceList(list) ({ \
  struct List * _ReleaseInterfaceList_list = (list); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReleaseInterfaceList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct List * __ReleaseInterfaceList_list __asm("a0") = (_ReleaseInterfaceList_list); \
  __asm volatile ("jsr a6@(-456:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReleaseInterfaceList__bn), "rf"(__ReleaseInterfaceList_list) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainInterfaceList() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ObtainInterfaceList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct List * __ObtainInterfaceList__re __asm("d0"); \
  __asm volatile ("jsr a6@(-462:W)" \
  : "=r"(__ObtainInterfaceList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ObtainInterfaceList__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define QueryInterfaceTagList(interface_name, tags) ({ \
  STRPTR _QueryInterfaceTagList_interface_name = (interface_name); \
  struct TagItem * _QueryInterfaceTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __QueryInterfaceTagList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __QueryInterfaceTagList__re __asm("d0"); \
  register STRPTR __QueryInterfaceTagList_interface_name __asm("a0") = (_QueryInterfaceTagList_interface_name); \
  register struct TagItem * __QueryInterfaceTagList_tags __asm("a1") = (_QueryInterfaceTagList_tags); \
  __asm volatile ("jsr a6@(-468:W)" \
  : "=r"(__QueryInterfaceTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__QueryInterfaceTagList__bn), "rf"(__QueryInterfaceTagList_interface_name), "rf"(__QueryInterfaceTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___QueryInterfaceTags(struct Library * SocketBase, STRPTR interface_name, Tag tags, ...)
{
  return QueryInterfaceTagList(interface_name, (struct TagItem *) &tags);
}

#define QueryInterfaceTags(interface_name...) ___QueryInterfaceTags(BSDSOCKET_BASE_NAME, interface_name)
#endif

#define CreateAddrAllocMessageA(version, protocol, interface_name, result_ptr, tags) ({ \
  LONG _CreateAddrAllocMessageA_version = (version); \
  LONG _CreateAddrAllocMessageA_protocol = (protocol); \
  STRPTR _CreateAddrAllocMessageA_interface_name = (interface_name); \
  struct AddressAllocationMessage ** _CreateAddrAllocMessageA_result_ptr = (result_ptr); \
  struct TagItem * _CreateAddrAllocMessageA_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __CreateAddrAllocMessageA__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __CreateAddrAllocMessageA__re __asm("d0"); \
  register LONG __CreateAddrAllocMessageA_version __asm("d0") = (_CreateAddrAllocMessageA_version); \
  register LONG __CreateAddrAllocMessageA_protocol __asm("d1") = (_CreateAddrAllocMessageA_protocol); \
  register STRPTR __CreateAddrAllocMessageA_interface_name __asm("a0") = (_CreateAddrAllocMessageA_interface_name); \
  register struct AddressAllocationMessage ** __CreateAddrAllocMessageA_result_ptr __asm("a1") = (_CreateAddrAllocMessageA_result_ptr); \
  register struct TagItem * __CreateAddrAllocMessageA_tags __asm("a2") = (_CreateAddrAllocMessageA_tags); \
  __asm volatile ("jsr a6@(-474:W)" \
  : "=r"(__CreateAddrAllocMessageA__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__CreateAddrAllocMessageA__bn), "rf"(__CreateAddrAllocMessageA_version), "rf"(__CreateAddrAllocMessageA_protocol), "rf"(__CreateAddrAllocMessageA_interface_name), "rf"(__CreateAddrAllocMessageA_result_ptr), "rf"(__CreateAddrAllocMessageA_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___CreateAddrAllocMessage(struct Library * SocketBase, LONG version, LONG protocol, STRPTR interface_name, struct AddressAllocationMessage ** result_ptr, Tag tags, ...)
{
  return CreateAddrAllocMessageA(version, protocol, interface_name, result_ptr, (struct TagItem *) &tags);
}

#define CreateAddrAllocMessage(version, protocol, interface_name, result_ptr...) ___CreateAddrAllocMessage(BSDSOCKET_BASE_NAME, version, protocol, interface_name, result_ptr)
#endif

#define DeleteAddrAllocMessage(aam) ({ \
  struct AddressAllocationMessage * _DeleteAddrAllocMessage_aam = (aam); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __DeleteAddrAllocMessage__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct AddressAllocationMessage * __DeleteAddrAllocMessage_aam __asm("a0") = (_DeleteAddrAllocMessage_aam); \
  __asm volatile ("jsr a6@(-480:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__DeleteAddrAllocMessage__bn), "rf"(__DeleteAddrAllocMessage_aam) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define BeginInterfaceConfig(message) ({ \
  struct AddressAllocationMessage * _BeginInterfaceConfig_message = (message); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __BeginInterfaceConfig__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct AddressAllocationMessage * __BeginInterfaceConfig_message __asm("a0") = (_BeginInterfaceConfig_message); \
  __asm volatile ("jsr a6@(-486:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__BeginInterfaceConfig__bn), "rf"(__BeginInterfaceConfig_message) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AbortInterfaceConfig(message) ({ \
  struct AddressAllocationMessage * _AbortInterfaceConfig_message = (message); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AbortInterfaceConfig__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct AddressAllocationMessage * __AbortInterfaceConfig_message __asm("a0") = (_AbortInterfaceConfig_message); \
  __asm volatile ("jsr a6@(-492:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AbortInterfaceConfig__bn), "rf"(__AbortInterfaceConfig_message) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddNetMonitorHookTagList(type, hook, tags) ({ \
  LONG _AddNetMonitorHookTagList_type = (type); \
  struct Hook * _AddNetMonitorHookTagList_hook = (hook); \
  struct TagItem * _AddNetMonitorHookTagList_tags = (tags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddNetMonitorHookTagList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __AddNetMonitorHookTagList__re __asm("d0"); \
  register LONG __AddNetMonitorHookTagList_type __asm("d0") = (_AddNetMonitorHookTagList_type); \
  register struct Hook * __AddNetMonitorHookTagList_hook __asm("a0") = (_AddNetMonitorHookTagList_hook); \
  register struct TagItem * __AddNetMonitorHookTagList_tags __asm("a1") = (_AddNetMonitorHookTagList_tags); \
  __asm volatile ("jsr a6@(-498:W)" \
  : "=r"(__AddNetMonitorHookTagList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddNetMonitorHookTagList__bn), "rf"(__AddNetMonitorHookTagList_type), "rf"(__AddNetMonitorHookTagList_hook), "rf"(__AddNetMonitorHookTagList_tags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___AddNetMonitorHookTags(struct Library * SocketBase, LONG type, struct Hook * hook, Tag tags, ...)
{
  return AddNetMonitorHookTagList(type, hook, (struct TagItem *) &tags);
}

#define AddNetMonitorHookTags(type, hook...) ___AddNetMonitorHookTags(BSDSOCKET_BASE_NAME, type, hook)
#endif

#define RemoveNetMonitorHook(hook) ({ \
  struct Hook * _RemoveNetMonitorHook_hook = (hook); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RemoveNetMonitorHook__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct Hook * __RemoveNetMonitorHook_hook __asm("a0") = (_RemoveNetMonitorHook_hook); \
  __asm volatile ("jsr a6@(-504:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RemoveNetMonitorHook__bn), "rf"(__RemoveNetMonitorHook_hook) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetNetworkStatistics(type, version, destination, size) ({ \
  LONG _GetNetworkStatistics_type = (type); \
  LONG _GetNetworkStatistics_version = (version); \
  APTR _GetNetworkStatistics_destination = (destination); \
  LONG _GetNetworkStatistics_size = (size); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetNetworkStatistics__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __GetNetworkStatistics__re __asm("d0"); \
  register LONG __GetNetworkStatistics_type __asm("d0") = (_GetNetworkStatistics_type); \
  register LONG __GetNetworkStatistics_version __asm("d1") = (_GetNetworkStatistics_version); \
  register APTR __GetNetworkStatistics_destination __asm("a0") = (_GetNetworkStatistics_destination); \
  register LONG __GetNetworkStatistics_size __asm("d2") = (_GetNetworkStatistics_size); \
  __asm volatile ("jsr a6@(-510:W)" \
  : "=r"(__GetNetworkStatistics__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetNetworkStatistics__bn), "rf"(__GetNetworkStatistics_type), "rf"(__GetNetworkStatistics_version), "rf"(__GetNetworkStatistics_destination), "rf"(__GetNetworkStatistics_size) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define AddDomainNameServer(address) ({ \
  STRPTR _AddDomainNameServer_address = (address); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __AddDomainNameServer__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __AddDomainNameServer__re __asm("d0"); \
  register STRPTR __AddDomainNameServer_address __asm("a0") = (_AddDomainNameServer_address); \
  __asm volatile ("jsr a6@(-516:W)" \
  : "=r"(__AddDomainNameServer__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__AddDomainNameServer__bn), "rf"(__AddDomainNameServer_address) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define RemoveDomainNameServer(address) ({ \
  STRPTR _RemoveDomainNameServer_address = (address); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RemoveDomainNameServer__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __RemoveDomainNameServer__re __asm("d0"); \
  register STRPTR __RemoveDomainNameServer_address __asm("a0") = (_RemoveDomainNameServer_address); \
  __asm volatile ("jsr a6@(-522:W)" \
  : "=r"(__RemoveDomainNameServer__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RemoveDomainNameServer__bn), "rf"(__RemoveDomainNameServer_address) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReleaseDomainNameServerList(list) ({ \
  struct List * _ReleaseDomainNameServerList_list = (list); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReleaseDomainNameServerList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct List * __ReleaseDomainNameServerList_list __asm("a0") = (_ReleaseDomainNameServerList_list); \
  __asm volatile ("jsr a6@(-528:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReleaseDomainNameServerList__bn), "rf"(__ReleaseDomainNameServerList_list) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainDomainNameServerList() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ObtainDomainNameServerList__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct List * __ObtainDomainNameServerList__re __asm("d0"); \
  __asm volatile ("jsr a6@(-534:W)" \
  : "=r"(__ObtainDomainNameServerList__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ObtainDomainNameServerList__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define setnetent(stay_open) ({ \
  LONG _setnetent_stay_open = (stay_open); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __setnetent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __setnetent_stay_open __asm("d0") = (_setnetent_stay_open); \
  __asm volatile ("jsr a6@(-540:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__setnetent__bn), "rf"(__setnetent_stay_open) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define endnetent() ({ \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __endnetent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  __asm volatile ("jsr a6@(-546:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__endnetent__bn) \
  : "fp0", "fp1", "cc", "memory"); \
})

#define getnetent() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getnetent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct netent * __getnetent__re __asm("d0"); \
  __asm volatile ("jsr a6@(-552:W)" \
  : "=r"(__getnetent__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getnetent__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define setprotoent(stay_open) ({ \
  LONG _setprotoent_stay_open = (stay_open); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __setprotoent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __setprotoent_stay_open __asm("d0") = (_setprotoent_stay_open); \
  __asm volatile ("jsr a6@(-558:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__setprotoent__bn), "rf"(__setprotoent_stay_open) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define endprotoent() ({ \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __endprotoent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  __asm volatile ("jsr a6@(-564:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__endprotoent__bn) \
  : "fp0", "fp1", "cc", "memory"); \
})

#define getprotoent() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getprotoent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct protoent * __getprotoent__re __asm("d0"); \
  __asm volatile ("jsr a6@(-570:W)" \
  : "=r"(__getprotoent__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getprotoent__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define setservent(stay_open) ({ \
  LONG _setservent_stay_open = (stay_open); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __setservent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __setservent_stay_open __asm("d0") = (_setservent_stay_open); \
  __asm volatile ("jsr a6@(-576:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__setservent__bn), "rf"(__setservent_stay_open) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define endservent() ({ \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __endservent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  __asm volatile ("jsr a6@(-582:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__endservent__bn) \
  : "fp0", "fp1", "cc", "memory"); \
})

#define getservent() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getservent__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct servent * __getservent__re __asm("d0"); \
  __asm volatile ("jsr a6@(-588:W)" \
  : "=r"(__getservent__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getservent__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define inet_aton(cp, addr) ({ \
  STRPTR _inet_aton_cp = (cp); \
  struct in_addr * _inet_aton_addr = (addr); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __inet_aton__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __inet_aton__re __asm("d0"); \
  register STRPTR __inet_aton_cp __asm("a0") = (_inet_aton_cp); \
  register struct in_addr * __inet_aton_addr __asm("a1") = (_inet_aton_addr); \
  __asm volatile ("jsr a6@(-594:W)" \
  : "=r"(__inet_aton__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__inet_aton__bn), "rf"(__inet_aton_cp), "rf"(__inet_aton_addr) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define inet_ntop(af, src, dst, size) ({ \
  LONG _inet_ntop_af = (af); \
  APTR _inet_ntop_src = (src); \
  STRPTR _inet_ntop_dst = (dst); \
  LONG _inet_ntop_size = (size); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __inet_ntop__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register STRPTR __inet_ntop__re __asm("d0"); \
  register LONG __inet_ntop_af __asm("d0") = (_inet_ntop_af); \
  register APTR __inet_ntop_src __asm("a0") = (_inet_ntop_src); \
  register STRPTR __inet_ntop_dst __asm("a1") = (_inet_ntop_dst); \
  register LONG __inet_ntop_size __asm("d1") = (_inet_ntop_size); \
  __asm volatile ("jsr a6@(-600:W)" \
  : "=r"(__inet_ntop__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__inet_ntop__bn), "rf"(__inet_ntop_af), "rf"(__inet_ntop_src), "rf"(__inet_ntop_dst), "rf"(__inet_ntop_size) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define inet_pton(af, src, dst) ({ \
  LONG _inet_pton_af = (af); \
  STRPTR _inet_pton_src = (src); \
  APTR _inet_pton_dst = (dst); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __inet_pton__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __inet_pton__re __asm("d0"); \
  register LONG __inet_pton_af __asm("d0") = (_inet_pton_af); \
  register STRPTR __inet_pton_src __asm("a0") = (_inet_pton_src); \
  register APTR __inet_pton_dst __asm("a1") = (_inet_pton_dst); \
  __asm volatile ("jsr a6@(-606:W)" \
  : "=r"(__inet_pton__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__inet_pton__bn), "rf"(__inet_pton_af), "rf"(__inet_pton_src), "rf"(__inet_pton_dst) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define In_LocalAddr(address) ({ \
  LONG _In_LocalAddr_address = (address); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __In_LocalAddr__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __In_LocalAddr__re __asm("d0"); \
  register LONG __In_LocalAddr_address __asm("d0") = (_In_LocalAddr_address); \
  __asm volatile ("jsr a6@(-612:W)" \
  : "=r"(__In_LocalAddr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__In_LocalAddr__bn), "rf"(__In_LocalAddr_address) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define In_CanForward(address) ({ \
  LONG _In_CanForward_address = (address); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __In_CanForward__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __In_CanForward__re __asm("d0"); \
  register LONG __In_CanForward_address __asm("d0") = (_In_CanForward_address); \
  __asm volatile ("jsr a6@(-618:W)" \
  : "=r"(__In_CanForward__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__In_CanForward__bn), "rf"(__In_CanForward_address) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_copym(m, off, len) ({ \
  struct mbuf * _mbuf_copym_m = (m); \
  LONG _mbuf_copym_off = (off); \
  LONG _mbuf_copym_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_copym__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct mbuf * __mbuf_copym__re __asm("d0"); \
  register struct mbuf * __mbuf_copym_m __asm("a0") = (_mbuf_copym_m); \
  register LONG __mbuf_copym_off __asm("d0") = (_mbuf_copym_off); \
  register LONG __mbuf_copym_len __asm("d1") = (_mbuf_copym_len); \
  __asm volatile ("jsr a6@(-624:W)" \
  : "=r"(__mbuf_copym__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_copym__bn), "rf"(__mbuf_copym_m), "rf"(__mbuf_copym_off), "rf"(__mbuf_copym_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_copyback(m, off, len, cp) ({ \
  struct mbuf * _mbuf_copyback_m = (m); \
  LONG _mbuf_copyback_off = (off); \
  LONG _mbuf_copyback_len = (len); \
  APTR _mbuf_copyback_cp = (cp); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_copyback__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __mbuf_copyback__re __asm("d0"); \
  register struct mbuf * __mbuf_copyback_m __asm("a0") = (_mbuf_copyback_m); \
  register LONG __mbuf_copyback_off __asm("d0") = (_mbuf_copyback_off); \
  register LONG __mbuf_copyback_len __asm("d1") = (_mbuf_copyback_len); \
  register APTR __mbuf_copyback_cp __asm("a1") = (_mbuf_copyback_cp); \
  __asm volatile ("jsr a6@(-630:W)" \
  : "=r"(__mbuf_copyback__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_copyback__bn), "rf"(__mbuf_copyback_m), "rf"(__mbuf_copyback_off), "rf"(__mbuf_copyback_len), "rf"(__mbuf_copyback_cp) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_copydata(m, off, len, cp) ({ \
  struct mbuf * _mbuf_copydata_m = (m); \
  LONG _mbuf_copydata_off = (off); \
  LONG _mbuf_copydata_len = (len); \
  APTR _mbuf_copydata_cp = (cp); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_copydata__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __mbuf_copydata__re __asm("d0"); \
  register struct mbuf * __mbuf_copydata_m __asm("a0") = (_mbuf_copydata_m); \
  register LONG __mbuf_copydata_off __asm("d0") = (_mbuf_copydata_off); \
  register LONG __mbuf_copydata_len __asm("d1") = (_mbuf_copydata_len); \
  register APTR __mbuf_copydata_cp __asm("a1") = (_mbuf_copydata_cp); \
  __asm volatile ("jsr a6@(-636:W)" \
  : "=r"(__mbuf_copydata__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_copydata__bn), "rf"(__mbuf_copydata_m), "rf"(__mbuf_copydata_off), "rf"(__mbuf_copydata_len), "rf"(__mbuf_copydata_cp) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_free(m) ({ \
  struct mbuf * _mbuf_free_m = (m); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_free__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct mbuf * __mbuf_free__re __asm("d0"); \
  register struct mbuf * __mbuf_free_m __asm("a0") = (_mbuf_free_m); \
  __asm volatile ("jsr a6@(-642:W)" \
  : "=r"(__mbuf_free__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_free__bn), "rf"(__mbuf_free_m) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_freem(m) ({ \
  struct mbuf * _mbuf_freem_m = (m); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_freem__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct mbuf * __mbuf_freem_m __asm("a0") = (_mbuf_freem_m); \
  __asm volatile ("jsr a6@(-648:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_freem__bn), "rf"(__mbuf_freem_m) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define mbuf_get() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_get__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct mbuf * __mbuf_get__re __asm("d0"); \
  __asm volatile ("jsr a6@(-654:W)" \
  : "=r"(__mbuf_get__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_get__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_gethdr() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_gethdr__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct mbuf * __mbuf_gethdr__re __asm("d0"); \
  __asm volatile ("jsr a6@(-660:W)" \
  : "=r"(__mbuf_gethdr__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_gethdr__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_prepend(m, len) ({ \
  struct mbuf * _mbuf_prepend_m = (m); \
  LONG _mbuf_prepend_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_prepend__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct mbuf * __mbuf_prepend__re __asm("d0"); \
  register struct mbuf * __mbuf_prepend_m __asm("a0") = (_mbuf_prepend_m); \
  register LONG __mbuf_prepend_len __asm("d0") = (_mbuf_prepend_len); \
  __asm volatile ("jsr a6@(-666:W)" \
  : "=r"(__mbuf_prepend__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_prepend__bn), "rf"(__mbuf_prepend_m), "rf"(__mbuf_prepend_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_cat(m, n) ({ \
  struct mbuf * _mbuf_cat_m = (m); \
  struct mbuf * _mbuf_cat_n = (n); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_cat__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __mbuf_cat__re __asm("d0"); \
  register struct mbuf * __mbuf_cat_m __asm("a0") = (_mbuf_cat_m); \
  register struct mbuf * __mbuf_cat_n __asm("a1") = (_mbuf_cat_n); \
  __asm volatile ("jsr a6@(-672:W)" \
  : "=r"(__mbuf_cat__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_cat__bn), "rf"(__mbuf_cat_m), "rf"(__mbuf_cat_n) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_adj(mp, req_len) ({ \
  struct mbuf * _mbuf_adj_mp = (mp); \
  LONG _mbuf_adj_req_len = (req_len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_adj__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __mbuf_adj__re __asm("d0"); \
  register struct mbuf * __mbuf_adj_mp __asm("a0") = (_mbuf_adj_mp); \
  register LONG __mbuf_adj_req_len __asm("d0") = (_mbuf_adj_req_len); \
  __asm volatile ("jsr a6@(-678:W)" \
  : "=r"(__mbuf_adj__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_adj__bn), "rf"(__mbuf_adj_mp), "rf"(__mbuf_adj_req_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define mbuf_pullup(m, len) ({ \
  struct mbuf * _mbuf_pullup_m = (m); \
  LONG _mbuf_pullup_len = (len); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __mbuf_pullup__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct mbuf * __mbuf_pullup__re __asm("d0"); \
  register struct mbuf * __mbuf_pullup_m __asm("a0") = (_mbuf_pullup_m); \
  register LONG __mbuf_pullup_len __asm("d0") = (_mbuf_pullup_len); \
  __asm volatile ("jsr a6@(-684:W)" \
  : "=r"(__mbuf_pullup__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__mbuf_pullup__bn), "rf"(__mbuf_pullup_m), "rf"(__mbuf_pullup_len) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ProcessIsServer(pr) ({ \
  struct Process * _ProcessIsServer_pr = (pr); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ProcessIsServer__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register BOOL __ProcessIsServer__re __asm("d0"); \
  register struct Process * __ProcessIsServer_pr __asm("a0") = (_ProcessIsServer_pr); \
  __asm volatile ("jsr a6@(-690:W)" \
  : "=r"(__ProcessIsServer__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ProcessIsServer__bn), "rf"(__ProcessIsServer_pr) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ObtainServerSocket() ({ \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ObtainServerSocket__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __ObtainServerSocket__re __asm("d0"); \
  __asm volatile ("jsr a6@(-696:W)" \
  : "=r"(__ObtainServerSocket__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ObtainServerSocket__bn) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define GetDefaultDomainName(buffer, buffer_size) ({ \
  STRPTR _GetDefaultDomainName_buffer = (buffer); \
  LONG _GetDefaultDomainName_buffer_size = (buffer_size); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __GetDefaultDomainName__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register BOOL __GetDefaultDomainName__re __asm("d0"); \
  register STRPTR __GetDefaultDomainName_buffer __asm("a0") = (_GetDefaultDomainName_buffer); \
  register LONG __GetDefaultDomainName_buffer_size __asm("d0") = (_GetDefaultDomainName_buffer_size); \
  __asm volatile ("jsr a6@(-702:W)" \
  : "=r"(__GetDefaultDomainName__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__GetDefaultDomainName__bn), "rf"(__GetDefaultDomainName_buffer), "rf"(__GetDefaultDomainName_buffer_size) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define SetDefaultDomainName(buffer) ({ \
  STRPTR _SetDefaultDomainName_buffer = (buffer); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __SetDefaultDomainName__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register STRPTR __SetDefaultDomainName_buffer __asm("a0") = (_SetDefaultDomainName_buffer); \
  __asm volatile ("jsr a6@(-708:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__SetDefaultDomainName__bn), "rf"(__SetDefaultDomainName_buffer) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainRoadshowData(access) ({ \
  LONG _ObtainRoadshowData_access = (access); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ObtainRoadshowData__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct List * __ObtainRoadshowData__re __asm("d0"); \
  register LONG __ObtainRoadshowData_access __asm("d0") = (_ObtainRoadshowData_access); \
  __asm volatile ("jsr a6@(-714:W)" \
  : "=r"(__ObtainRoadshowData__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ObtainRoadshowData__bn), "rf"(__ObtainRoadshowData_access) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define ReleaseRoadshowData(list) ({ \
  struct List * _ReleaseRoadshowData_list = (list); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ReleaseRoadshowData__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct List * __ReleaseRoadshowData_list __asm("a0") = (_ReleaseRoadshowData_list); \
  __asm volatile ("jsr a6@(-720:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ReleaseRoadshowData__bn), "rf"(__ReleaseRoadshowData_list) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ChangeRoadshowData(list, name, length, data) ({ \
  struct List * _ChangeRoadshowData_list = (list); \
  STRPTR _ChangeRoadshowData_name = (name); \
  ULONG _ChangeRoadshowData_length = (length); \
  APTR _ChangeRoadshowData_data = (data); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __ChangeRoadshowData__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register BOOL __ChangeRoadshowData__re __asm("d0"); \
  register struct List * __ChangeRoadshowData_list __asm("a0") = (_ChangeRoadshowData_list); \
  register STRPTR __ChangeRoadshowData_name __asm("a1") = (_ChangeRoadshowData_name); \
  register ULONG __ChangeRoadshowData_length __asm("d0") = (_ChangeRoadshowData_length); \
  register APTR __ChangeRoadshowData_data __asm("a2") = (_ChangeRoadshowData_data); \
  __asm volatile ("jsr a6@(-726:W)" \
  : "=r"(__ChangeRoadshowData__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__ChangeRoadshowData__bn), "rf"(__ChangeRoadshowData_list), "rf"(__ChangeRoadshowData_name), "rf"(__ChangeRoadshowData_length), "rf"(__ChangeRoadshowData_data) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define RemoveInterface(interface_name, force) ({ \
  STRPTR _RemoveInterface_interface_name = (interface_name); \
  LONG _RemoveInterface_force = (force); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __RemoveInterface__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __RemoveInterface__re __asm("d0"); \
  register STRPTR __RemoveInterface_interface_name __asm("a0") = (_RemoveInterface_interface_name); \
  register LONG __RemoveInterface_force __asm("d0") = (_RemoveInterface_force); \
  __asm volatile ("jsr a6@(-732:W)" \
  : "=r"(__RemoveInterface__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__RemoveInterface__bn), "rf"(__RemoveInterface_interface_name), "rf"(__RemoveInterface_force) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define gethostbyname_r(name, hp, buf, buflen, he) ({ \
  STRPTR _gethostbyname_r_name = (name); \
  struct hostent * _gethostbyname_r_hp = (hp); \
  APTR _gethostbyname_r_buf = (buf); \
  ULONG _gethostbyname_r_buflen = (buflen); \
  LONG * _gethostbyname_r_he = (he); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __gethostbyname_r__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct hostent * __gethostbyname_r__re __asm("d0"); \
  register STRPTR __gethostbyname_r_name __asm("a0") = (_gethostbyname_r_name); \
  register struct hostent * __gethostbyname_r_hp __asm("a1") = (_gethostbyname_r_hp); \
  register APTR __gethostbyname_r_buf __asm("a2") = (_gethostbyname_r_buf); \
  register ULONG __gethostbyname_r_buflen __asm("d0") = (_gethostbyname_r_buflen); \
  register LONG * __gethostbyname_r_he __asm("a3") = (_gethostbyname_r_he); \
  __asm volatile ("jsr a6@(-738:W)" \
  : "=r"(__gethostbyname_r__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__gethostbyname_r__bn), "rf"(__gethostbyname_r_name), "rf"(__gethostbyname_r_hp), "rf"(__gethostbyname_r_buf), "rf"(__gethostbyname_r_buflen), "rf"(__gethostbyname_r_he) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define gethostbyaddr_r(addr, len, type, hp, buf, buflen, he) ({ \
  STRPTR _gethostbyaddr_r_addr = (addr); \
  LONG _gethostbyaddr_r_len = (len); \
  LONG _gethostbyaddr_r_type = (type); \
  struct hostent * _gethostbyaddr_r_hp = (hp); \
  APTR _gethostbyaddr_r_buf = (buf); \
  ULONG _gethostbyaddr_r_buflen = (buflen); \
  LONG * _gethostbyaddr_r_he = (he); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __gethostbyaddr_r__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct hostent * __gethostbyaddr_r__re __asm("d0"); \
  register STRPTR __gethostbyaddr_r_addr __asm("a0") = (_gethostbyaddr_r_addr); \
  register LONG __gethostbyaddr_r_len __asm("d0") = (_gethostbyaddr_r_len); \
  register LONG __gethostbyaddr_r_type __asm("d1") = (_gethostbyaddr_r_type); \
  register struct hostent * __gethostbyaddr_r_hp __asm("a1") = (_gethostbyaddr_r_hp); \
  register APTR __gethostbyaddr_r_buf __asm("a2") = (_gethostbyaddr_r_buf); \
  register ULONG __gethostbyaddr_r_buflen __asm("d2") = (_gethostbyaddr_r_buflen); \
  register LONG * __gethostbyaddr_r_he __asm("a3") = (_gethostbyaddr_r_he); \
  __asm volatile ("jsr a6@(-744:W)" \
  : "=r"(__gethostbyaddr_r__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__gethostbyaddr_r__bn), "rf"(__gethostbyaddr_r_addr), "rf"(__gethostbyaddr_r_len), "rf"(__gethostbyaddr_r_type), "rf"(__gethostbyaddr_r_hp), "rf"(__gethostbyaddr_r_buf), "rf"(__gethostbyaddr_r_buflen), "rf"(__gethostbyaddr_r_he) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define freeaddrinfo(ai) ({ \
  struct addrinfo * _freeaddrinfo_ai = (ai); \
  { \
  register int _d0 __asm("d0"); \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __freeaddrinfo__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register struct addrinfo * __freeaddrinfo_ai __asm("a0") = (_freeaddrinfo_ai); \
  __asm volatile ("jsr a6@(-804:W)" \
  : "=r" (_d0), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__freeaddrinfo__bn), "rf"(__freeaddrinfo_ai) \
  : "fp0", "fp1", "cc", "memory"); \
  } \
})

#define getaddrinfo(hostname, servname, hints, res) ({ \
  STRPTR _getaddrinfo_hostname = (hostname); \
  STRPTR _getaddrinfo_servname = (servname); \
  struct addrinfo * _getaddrinfo_hints = (hints); \
  struct addrinfo ** _getaddrinfo_res = (res); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getaddrinfo__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __getaddrinfo__re __asm("d0"); \
  register STRPTR __getaddrinfo_hostname __asm("a0") = (_getaddrinfo_hostname); \
  register STRPTR __getaddrinfo_servname __asm("a1") = (_getaddrinfo_servname); \
  register struct addrinfo * __getaddrinfo_hints __asm("a2") = (_getaddrinfo_hints); \
  register struct addrinfo ** __getaddrinfo_res __asm("a3") = (_getaddrinfo_res); \
  __asm volatile ("jsr a6@(-810:W)" \
  : "=r"(__getaddrinfo__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getaddrinfo__bn), "rf"(__getaddrinfo_hostname), "rf"(__getaddrinfo_servname), "rf"(__getaddrinfo_hints), "rf"(__getaddrinfo_res) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define gai_strerror(errnum) ({ \
  LONG _gai_strerror_errnum = (errnum); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __gai_strerror__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register STRPTR __gai_strerror__re __asm("d0"); \
  register LONG __gai_strerror_errnum __asm("a0") = (_gai_strerror_errnum); \
  __asm volatile ("jsr a6@(-816:W)" \
  : "=r"(__gai_strerror__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__gai_strerror__bn), "rf"(__gai_strerror_errnum) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#define getnameinfo(sa, salen, host, hostlen, serv, servlen, flags) ({ \
  struct sockaddr * _getnameinfo_sa = (sa); \
  ULONG _getnameinfo_salen = (salen); \
  STRPTR _getnameinfo_host = (host); \
  ULONG _getnameinfo_hostlen = (hostlen); \
  STRPTR _getnameinfo_serv = (serv); \
  ULONG _getnameinfo_servlen = (servlen); \
  ULONG _getnameinfo_flags = (flags); \
  ({ \
  register int _d1 __asm("d1"); \
  register int _a0 __asm("a0"); \
  register int _a1 __asm("a1"); \
  register struct Library * const __getnameinfo__bn __asm("a6") = BSDSOCKET_BASE_NAME;\
  register LONG __getnameinfo__re __asm("d0"); \
  register struct sockaddr * __getnameinfo_sa __asm("a0") = (_getnameinfo_sa); \
  register ULONG __getnameinfo_salen __asm("d0") = (_getnameinfo_salen); \
  register STRPTR __getnameinfo_host __asm("a1") = (_getnameinfo_host); \
  register ULONG __getnameinfo_hostlen __asm("d1") = (_getnameinfo_hostlen); \
  register STRPTR __getnameinfo_serv __asm("a2") = (_getnameinfo_serv); \
  register ULONG __getnameinfo_servlen __asm("d2") = (_getnameinfo_servlen); \
  register ULONG __getnameinfo_flags __asm("d3") = (_getnameinfo_flags); \
  __asm volatile ("jsr a6@(-822:W)" \
  : "=r"(__getnameinfo__re), "=r" (_d1), "=r" (_a0), "=r" (_a1) \
  : "r"(__getnameinfo__bn), "rf"(__getnameinfo_sa), "rf"(__getnameinfo_salen), "rf"(__getnameinfo_host), "rf"(__getnameinfo_hostlen), "rf"(__getnameinfo_serv), "rf"(__getnameinfo_servlen), "rf"(__getnameinfo_flags) \
  : "fp0", "fp1", "cc", "memory"); \
  }); \
})

#endif /*  INLINE_BSDSOCKET_H  */
