/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_POWERSDL_NET_H
#define _PPCINLINE_POWERSDL_NET_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef POWERSDL_NET_BASE_NAME
#define POWERSDL_NET_BASE_NAME PowerSDLNetBase
#endif /* !POWERSDL_NET_BASE_NAME */

#define SDLNet_FreeSocketSet(__p0) \
	({ \
		SDLNet_SocketSet  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(SDLNet_SocketSet ))*(void**)(__base - 196))(__t__p0));\
	})

#define SDLNet_TCP_Send(__p0, __p1, __p2) \
	({ \
		TCPsocket  __t__p0 = __p0;\
		const void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TCPsocket , const void *, int ))*(void**)(__base - 70))(__t__p0, __t__p1, __t__p2));\
	})

#define SDLNet_UDP_Close(__p0) \
	({ \
		UDPsocket  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(UDPsocket ))*(void**)(__base - 166))(__t__p0));\
	})

#define SDLNet_UDP_RecvV(__p0, __p1) \
	({ \
		UDPsocket  __t__p0 = __p0;\
		UDPpacket ** __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(UDPsocket , UDPpacket **))*(void**)(__base - 154))(__t__p0, __t__p1));\
	})

#define SDLNet_UDP_SendV(__p0, __p1, __p2) \
	({ \
		UDPsocket  __t__p0 = __p0;\
		UDPpacket ** __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(UDPsocket , UDPpacket **, int ))*(void**)(__base - 142))(__t__p0, __t__p1, __t__p2));\
	})

#define SDLNet_FreePacketV(__p0) \
	({ \
		UDPpacket ** __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(UDPpacket **))*(void**)(__base - 112))(__t__p0));\
	})

#define SDLNet_UDP_Unbind(__p0, __p1) \
	({ \
		UDPsocket  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(UDPsocket , int ))*(void**)(__base - 130))(__t__p0, __t__p1));\
	})

#define SDLNet_UDP_Recv(__p0, __p1) \
	({ \
		UDPsocket  __t__p0 = __p0;\
		UDPpacket * __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(UDPsocket , UDPpacket *))*(void**)(__base - 160))(__t__p0, __t__p1));\
	})

#define SDLNet_AllocPacket(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((UDPpacket *(*)(int ))*(void**)(__base - 88))(__t__p0));\
	})

#define SDLNet_FreePacket(__p0) \
	({ \
		UDPpacket * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(UDPpacket *))*(void**)(__base - 100))(__t__p0));\
	})

#define SDLNet_TCP_Open(__p0) \
	({ \
		IPaddress * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TCPsocket (*)(IPaddress *))*(void**)(__base - 52))(__t__p0));\
	})

#define SDLNet_ResizePacket(__p0, __p1) \
	({ \
		UDPpacket * __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(UDPpacket *, int ))*(void**)(__base - 94))(__t__p0, __t__p1));\
	})

#define SDLNet_DelSocket(__p0, __p1) \
	({ \
		SDLNet_SocketSet  __t__p0 = __p0;\
		SDLNet_GenericSocket  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDLNet_SocketSet , SDLNet_GenericSocket ))*(void**)(__base - 184))(__t__p0, __t__p1));\
	})

#define SDLNet_TCP_Accept(__p0) \
	({ \
		TCPsocket  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((TCPsocket (*)(TCPsocket ))*(void**)(__base - 58))(__t__p0));\
	})

#define SDLNet_AllocPacketV(__p0, __p1) \
	({ \
		int  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((UDPpacket **(*)(int , int ))*(void**)(__base - 106))(__t__p0, __t__p1));\
	})

#define SDLNet_CheckSockets(__p0, __p1) \
	({ \
		SDLNet_SocketSet  __t__p0 = __p0;\
		Uint32  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDLNet_SocketSet , Uint32 ))*(void**)(__base - 190))(__t__p0, __t__p1));\
	})

#define SDLNet_TCP_Close(__p0) \
	({ \
		TCPsocket  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)(TCPsocket ))*(void**)(__base - 82))(__t__p0));\
	})

#define SDLNet_UDP_Send(__p0, __p1, __p2) \
	({ \
		UDPsocket  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		UDPpacket * __t__p2 = __p2;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(UDPsocket , int , UDPpacket *))*(void**)(__base - 148))(__t__p0, __t__p1, __t__p2));\
	})

#define SDLNet_TCP_GetPeerAddress(__p0) \
	({ \
		TCPsocket  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IPaddress *(*)(TCPsocket ))*(void**)(__base - 64))(__t__p0));\
	})

#define SDLNet_AddSocket(__p0, __p1) \
	({ \
		SDLNet_SocketSet  __t__p0 = __p0;\
		SDLNet_GenericSocket  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(SDLNet_SocketSet , SDLNet_GenericSocket ))*(void**)(__base - 178))(__t__p0, __t__p1));\
	})

#define SDLNet_ResolveHost(__p0, __p1, __p2) \
	({ \
		IPaddress * __t__p0 = __p0;\
		const char * __t__p1 = __p1;\
		Uint16  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(IPaddress *, const char *, Uint16 ))*(void**)(__base - 40))(__t__p0, __t__p1, __t__p2));\
	})

#define SDLNet_Quit() \
	({ \
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((void (*)())*(void**)(__base - 34))());\
	})

#define SDLNet_ResolveIP(__p0) \
	({ \
		IPaddress * __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const char *(*)(IPaddress *))*(void**)(__base - 46))(__t__p0));\
	})

#define SDLNet_Linked_Version() \
	({ \
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((const SDL_version *(*)())*(void**)(__base - 202))());\
	})

#define SDLNet_UDP_GetPeerAddress(__p0, __p1) \
	({ \
		UDPsocket  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((IPaddress *(*)(UDPsocket , int ))*(void**)(__base - 136))(__t__p0, __t__p1));\
	})

#define SDLNet_UDP_Bind(__p0, __p1, __p2) \
	({ \
		UDPsocket  __t__p0 = __p0;\
		int  __t__p1 = __p1;\
		IPaddress * __t__p2 = __p2;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(UDPsocket , int , IPaddress *))*(void**)(__base - 124))(__t__p0, __t__p1, __t__p2));\
	})

#define SDLNet_TCP_Recv(__p0, __p1, __p2) \
	({ \
		TCPsocket  __t__p0 = __p0;\
		void * __t__p1 = __p1;\
		int  __t__p2 = __p2;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)(TCPsocket , void *, int ))*(void**)(__base - 76))(__t__p0, __t__p1, __t__p2));\
	})

#define SDLNet_AllocSocketSet(__p0) \
	({ \
		int  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((SDLNet_SocketSet (*)(int ))*(void**)(__base - 172))(__t__p0));\
	})

#define SDLNet_UDP_Open(__p0) \
	({ \
		Uint16  __t__p0 = __p0;\
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((UDPsocket (*)(Uint16 ))*(void**)(__base - 118))(__t__p0));\
	})

#define SDLNet_Init() \
	({ \
		long __base = (long)(POWERSDL_NET_BASE_NAME);\
		__asm volatile("mr 12,%0": :"r"(__base):"r12");\
		(((int (*)())*(void**)(__base - 28))());\
	})

#endif /* !_PPCINLINE_POWERSDL_NET_H */
