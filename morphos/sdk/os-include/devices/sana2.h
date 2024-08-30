#ifndef SANA2_SANA2DEVICE_H
#define SANA2_SANA2DEVICE_H

/*
	SANA-II v3 driver definitions

	Copyright © 2002-2005 The MorphOS Development Team, All Rights Reserved.
*/


#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif

#ifndef EXEC_ERRORS_H
# include <exec/errors.h>
#endif

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


#define SANA2_MAX_ADDR_BITS    (128)
#define SANA2_MAX_ADDR_BYTES   ((SANA2_MAX_ADDR_BITS + 7) / 8)

struct IOSana2Req
{
	struct IORequest ios2_Req;
	ULONG            ios2_WireError;
	ULONG            ios2_PacketType;
	UBYTE            ios2_SrcAddr[SANA2_MAX_ADDR_BYTES];
	UBYTE            ios2_DstAddr[SANA2_MAX_ADDR_BYTES];
	ULONG            ios2_DataLength;
	APTR             ios2_Data;
	APTR             ios2_StatData;
	APTR             ios2_BufferManagement;
};


/*
 * io_Flags defines
 */
#define SANA2IOB_RAW    (7)
#define SANA2IOF_RAW    (1<<SANA2IOB_RAW)

#define SANA2IOB_BCAST  (6)
#define SANA2IOF_BCAST  (1<<SANA2IOB_BCAST)

#define SANA2IOB_MCAST  (5)
#define SANA2IOF_MCAST  (1<<SANA2IOB_MCAST)

#define SANA2IOB_QUICK  (IOB_QUICK)
#define SANA2IOF_QUICK  (IOF_QUICK)


/*
 * OpenDevice() flags
 */
#define SANA2OPB_MINE   (0)
#define SANA2OPF_MINE   (1<<SANA2OPB_MINE)

#define SANA2OPB_PROM   (1)
#define SANA2OPF_PROM   (1<<SANA2OPB_PROM)


/*
 * OpenDevice()'s tags
 */
#define S2_Dummy              (TAG_USER+0xB0000)

#define S2_CopyToBuff         (S2_Dummy+1)
#define S2_CopyFromBuff       (S2_Dummy+2)
#define S2_PacketFilter       (S2_Dummy+3)
#define S2_CopyToBuff16       (S2_Dummy+4)
#define S2_CopyFromBuff16     (S2_Dummy+5)
#define S2_CopyToBuff32       (S2_Dummy+6)
#define S2_CopyFromBuff32     (S2_Dummy+7)
#define S2_DMACopyToBuff32    (S2_Dummy+8)
#define S2_DMACopyFromBuff32  (S2_Dummy+9)

struct Sana2DeviceQuery
{
	ULONG SizeAvailable;
	ULONG SizeSupplied;
	ULONG DevQueryFormat;
	ULONG DeviceLevel;
	UWORD AddrFieldSize;
	ULONG MTU;
	ULONG BPS;
	ULONG HardwareType;
};

/*
 * SANA2 extension - not supported by all SANA2 devices
 */

#define SANA2QFMT_LINKEXT     0x4C494E4B

struct LinkExtSana2DeviceQuery
{
	ULONG SizeAvailable;
	ULONG SizeSupplied;
	ULONG DevQueryFormat; /* Must be set to SANA2QFMT_LINKEXT */
	ULONG DeviceLevel;
	UWORD AddrFieldSize;
	ULONG MTU;
	ULONG BPS;
	ULONG HardwareType;

	/*
	** New fields for DevQueryFormat 1. Remember to check SizeSupplied!
	*/
	ULONG LinkFlags;      /* Link status flags. You must ignore unknown bits */
};

/*
 * LinkFlags defines
 */
#define SANA2LNKB_LINKUP      (0)      /* If set hw link is up else down */

#define SANA2LNKF_LINKUP      (1<<SANA2LNKB_LINKUP)


#define S2WireType_Ethernet   1
#define S2WireType_IEEE802    6
#define S2WireType_Arcnet     7
#define S2WireType_LocalTalk  11
#define S2WireType_DyLAN      12
#define S2WireType_AmokNet    200
#define S2WireType_Liana      202
#define S2WireType_PPP        253
#define S2WireType_SLIP       254
#define S2WireType_CSLIP      255
#define S2WireType_PLIP       420

struct Sana2PacketTypeStats
{
	ULONG PacketsSent;
	ULONG PacketsReceived;
	ULONG BytesSent;
	ULONG BytesReceived;
	ULONG PacketsDropped;
};

struct Sana2SpecialStatRecord
{
	ULONG  Type;
	ULONG  Count;
	char  *String;
};

struct Sana2SpecialStatHeader
{
	ULONG RecordCountMax;
	ULONG RecordCountSupplied;
	/*
	 * struct Sana2SpecialStatRecord[RecordCountMax];
	 */
};

struct Sana2DeviceStats
{
	ULONG          PacketsReceived;
	ULONG          PacketsSent;
	ULONG          BadData;
	ULONG          Overruns;
	ULONG          Unused;
	ULONG          UnknownTypesReceived;
	ULONG          Reconfigurations;
	struct timeval LastStart;
};

#define S2_START                (CMD_NONSTD)

#define S2_DEVICEQUERY          (S2_START+0)
#define S2_GETSTATIONADDRESS    (S2_START+1)
#define S2_CONFIGINTERFACE      (S2_START+2)
#define S2_ADDMULTICASTADDRESS  (S2_START+5)
#define S2_DELMULTICASTADDRESS  (S2_START+6)
#define S2_MULTICAST            (S2_START+7)
#define S2_BROADCAST            (S2_START+8)
#define S2_TRACKTYPE            (S2_START+9)
#define S2_UNTRACKTYPE          (S2_START+10)
#define S2_GETTYPESTATS         (S2_START+11)
#define S2_GETSPECIALSTATS      (S2_START+12)
#define S2_GETGLOBALSTATS       (S2_START+13)
#define S2_ONEVENT              (S2_START+14)
#define S2_READORPHAN           (S2_START+15)
#define S2_ONLINE               (S2_START+16)
#define S2_OFFLINE              (S2_START+17)

#define S2_END                  (S2_START+18)

#ifndef NSCMD_DEVICEQUERY
#define NSCMD_DEVICEQUERY        0x4000
#endif
#define S2_ADDMULTICASTADDRESSES 0xc000
#define S2_DELMULTICASTADDRESSES 0xc001


#define S2ERR_NO_ERROR          0
#define S2ERR_NO_RESOURCES      1
#define S2ERR_BAD_ARGUMENT      3
#define S2ERR_BAD_STATE         4
#define S2ERR_BAD_ADDRESS       5
#define S2ERR_MTU_EXCEEDED      6
#define S2ERR_NOT_SUPPORTED     8
#define S2ERR_SOFTWARE          9
#define S2ERR_OUTOFSERVICE      10
#define S2ERR_TX_FAILURE        11

/*
 * ios2_WireError error defines
 */
#define S2WERR_GENERIC_ERROR    0
#define S2WERR_NOT_CONFIGURED   1
#define S2WERR_UNIT_ONLINE      2
#define S2WERR_UNIT_OFFLINE     3
#define S2WERR_ALREADY_TRACKED  4
#define S2WERR_NOT_TRACKED      5
#define S2WERR_BUFF_ERROR       6
#define S2WERR_SRC_ADDRESS      7
#define S2WERR_DST_ADDRESS      8
#define S2WERR_BAD_BROADCAST    9
#define S2WERR_BAD_MULTICAST    10
#define S2WERR_MULTICAST_FULL   11
#define S2WERR_BAD_EVENT        12
#define S2WERR_BAD_STATDATA     13
#define S2WERR_IS_CONFIGURED    15
#define S2WERR_NULL_POINTER     16
#define S2WERR_TOO_MANY_RETIRES 17
#define S2WERR_RCVREL_HDW_ERR   18


#define S2EVENT_ERROR           (1<<0)
#define S2EVENT_TX              (1<<1)
#define S2EVENT_RX              (1<<2)
#define S2EVENT_ONLINE          (1<<3)
#define S2EVENT_OFFLINE         (1<<4)
#define S2EVENT_BUFF            (1<<5)
#define S2EVENT_HARDWARE        (1<<6)
#define S2EVENT_SOFTWARE        (1<<7)

#define S2EVENT_CONNECT         (1 << 9)
#define S2EVENT_DISCONNECT      (1 << 10)

/*
 * SANA2 extension - not supported by all SANA2 devices
 */
#define S2EVENT_LINKUP          (1<<16)
#define S2EVENT_LINKDOWN        (1<<17)

#pragma pack()

#endif /* SANA2_SANA2DEVICE_H */
