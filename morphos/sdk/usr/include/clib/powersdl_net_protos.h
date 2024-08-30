#ifndef SDL_NET_PROTOS
#define SDL_NET_PROTOS

#ifndef	DOS_DOS_H
#include <dos/dos.h>
#endif

#ifndef	_SDL_H
#include <SDL/SDL.h>
#endif

#include <SDL/SDL_net.h>

#ifdef __cplusplus
extern "C" {
#endif

const SDL_version *SDLNet_Linked_Version(void);

int           SDLNet_Init(void);
void          SDLNet_Quit(void);
int           SDLNet_ResolveHost(IPaddress *address, const char *host, Uint16 port);
const char *  SDLNet_ResolveIP(IPaddress *ip);
TCPsocket     SDLNet_TCP_Open(IPaddress *ip);
TCPsocket     SDLNet_TCP_Accept(TCPsocket server);
IPaddress *   SDLNet_TCP_GetPeerAddress(TCPsocket sock);
int           SDLNet_TCP_Send(TCPsocket sock, const void *data, int len);
int           SDLNet_TCP_Recv(TCPsocket sock, void *data, int maxlen);
void          SDLNet_TCP_Close(TCPsocket sock);
UDPpacket *   SDLNet_AllocPacket(int size);
int           SDLNet_ResizePacket(UDPpacket *packet, int newsize);
void          SDLNet_FreePacket(UDPpacket *packet);
UDPpacket **  SDLNet_AllocPacketV(int howmany, int size);
void          SDLNet_FreePacketV(UDPpacket **packetV);
UDPsocket     SDLNet_UDP_Open(Uint16 port);
int           SDLNet_UDP_Bind(UDPsocket sock, int channel, IPaddress *address);
void          SDLNet_UDP_Unbind(UDPsocket sock, int channel);
IPaddress *   SDLNet_UDP_GetPeerAddress(UDPsocket sock, int channel);
int           SDLNet_UDP_SendV(UDPsocket sock, UDPpacket **packets, int npackets);
int           SDLNet_UDP_Send(UDPsocket sock, int channel, UDPpacket *packet);
int           SDLNet_UDP_RecvV(UDPsocket sock, UDPpacket **packets);
int           SDLNet_UDP_Recv(UDPsocket sock, UDPpacket *packet);
void          SDLNet_UDP_Close(UDPsocket sock);
SDLNet_SocketSet SDLNet_AllocSocketSet(int maxsockets);
int           SDLNet_AddSocket(SDLNet_SocketSet set, SDLNet_GenericSocket sock);
int           SDLNet_DelSocket(SDLNet_SocketSet set, SDLNet_GenericSocket sock);
int           SDLNet_CheckSockets(SDLNet_SocketSet set, Uint32 timeout);
void          SDLNet_FreeSocketSet(SDLNet_SocketSet set);
//void          SDLNet_Write16(Uint16 value, void *area);
//void          SDLNet_Write32(Uint32 value, void *area);
//Uint16        SDLNet_Read16(void *area);
//Uint32        SDLNet_Read32(void *area);

#ifdef __cplusplus
}
#endif

#endif /* SDL_NET_PROTOS */

