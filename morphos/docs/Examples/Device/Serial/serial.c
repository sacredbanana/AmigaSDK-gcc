/*
 *  serial.c
 *
 *  Adaptation of Iain Barclay's New8N1 for MorphOS.
 *
 *  Copyright 2000 by E. Lesueur.
 */

#define EMUL_NOQUICKMODE    1
#define DEVICES_SERIAL_H_OBSOLETE
#include <exec/lists.h>
#include <exec/memory.h>
#include <exec/execbase.h>
#include <exec/io.h>
#include <exec/ports.h>
#include <exec/errors.h>
#include <exec/resident.h>
#include <exec/initializers.h>
#include <intuition/preferences.h>
#include <devices/timer.h>
#include <devices/serial.h>
#include <hardware/cia.h>
#include <hardware/adkbits.h>
#include <hardware/intbits.h>
#include <hardware/custom.h>
#include <resources/misc.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/misc.h>


#if 0
    void dprintf(const char *,...);
#   define KPRINTF(l,x) do { if (l >= 0) { dprintf("Line %ld: ", __LINE__); dprintf x;} } while(0)
    int tbes;
    int written_chars;
    int caused_tbes;
#   define DB(x)    x
#else
#   define KPRINTF(l,x) ((void)0)
#   define DB(x)
#endif

#define ciaa (*(volatile struct CIA *)0xbfe001)
#define ciab (*(volatile struct CIA *)0xbfd000)
#define custom (*(volatile struct Custom *)0xdff000)

/*#define NEWCODE  1*/
#define SETDSR   0
#define NCOMM    0
#define NEGCHECK 1
#define EOFCODE  1

#ifndef DEVNAME
#   define DEVNAME             "serial.device"
#endif
#define VERSION             50
#define REVISION            2
#define VERSION_STR         "50"
#define REVISION_STR        "2"
#define DATE                "18.9.2002"

#define PRTMASK (CIAF_PRTRPOUT | CIAF_PRTRBUSY)
#define STR(x)  #x

struct MyDevice {
    struct Library      vb_Library;
    UWORD               vb_Pad;
    ULONG               vb_SaveDDRA;
    ULONG               vb_SavePRA;
    APTR                vb_OldLevel1;
    APTR                vb_OldLevel5;
    LONG                vb_SegList;
    ULONG               vb_DefBaud;
    ULONG               vb_DefRBufLen;
    UBYTE              *vb_CurRBuf;
    ULONG               vb_CurRBufLen;
    ULONG               vb_CurBaud;
    ULONG               vb_SerFlags;
    ULONG               vb_Initialized;
    struct Interrupt   *vb_oldRBFInt;
    struct Interrupt   *vb_oldTBEInt;
    /*struct timerequest *timerReq;*/
};

static void timerRtn(void);

static const struct EmulLibEntry _gate_timer = {
    TRAP_LIB, 0, timerRtn
};
static struct Interrupt timerInterrupt = {
    {NULL, NULL, NT_INTERRUPT, 0, DEVNAME },
    NULL,
    (APTR)&_gate_timer
};
static struct MsgPort timerPort = {
    {NULL, NULL, NT_MSGPORT, 0, NULL},
    PA_SOFTINT, 0, (APTR)&timerInterrupt,
    {(APTR)&timerPort.mp_MsgList.lh_Tail, NULL, (APTR)&timerPort.mp_MsgList}
};
static struct timerequest timerReq = {
    {{{NULL, NULL, NT_MESSAGE, 0, NULL},
    &timerPort, sizeof(timerReq)}, NULL, NULL,
    TR_ADDREQUEST, 0, 0},
    {0, 0}
};

static volatile BOOL Overrun;
static BOOL Handshake;
static volatile int disableRead = -1;

static UBYTE *i_BufPtr;
static UBYTE *i_BufIn;
static UBYTE *i_BufOut;
static UBYTE *i_BufEnd;
static volatile LONG  i_InCnt;
static volatile LONG  i_Thresh;

static struct IOExtSer *cr_IOReq;
static UBYTE *cr_OutPtr;
static LONG cr_Length;
static struct MinList readQ = {
    (APTR)&readQ.mlh_Tail, NULL, (APTR)&readQ
};

static struct IOExtSer *cw_IOReq;
static UBYTE *cw_Buffer;
static LONG cw_Length;
static struct MinList writeQ = {
    (APTR)&writeQ.mlh_Tail, NULL, (APTR)&writeQ
};

struct ExecBase *SysBase;
struct Library *MiscBase;
struct IntuitionBase *IntuitionBase;


static struct MyDevice *devInit(struct MyDevice *base,
				LONG seglist,
				struct ExecBase *sysbase);
static struct MyDevice *devOpen(void);
static LONG devExpunge(void);
static LONG devClose(void);
static void devBeginIO(void);
static void devAbortIO(void);

static void freeBuf(struct MyDevice *base);
static ULONG cmdClear(struct MyDevice *base);
static ULONG cmdInvalid(struct IOExtSer *ioreq);
static ULONG internalReset(struct MyDevice *base, ULONG buflen, ULONG baud);
static ULONG cmdReset(struct MyDevice *base, struct IOExtSer *ioreq);
static void internalFlush(struct MinList *queue);
static ULONG cmdFlush(struct IOExtSer *ioreq);
static ULONG cmdRead(struct IOExtSer *ioreq);
static void queueWrite(struct IOExtSer *ioreq);
static ULONG cmdWrite(struct IOExtSer *ioreq);
static ULONG sdcmdBreak(struct IOExtSer *ioreq);
static ULONG sdcmdQuery(struct IOExtSer *ioreq);
static ULONG sdcmdSetParams(struct MyDevice *base, struct IOExtSer *ioreq);
static void timerRtn(void);
static ULONG copyData(struct IOExtSer *ioreq);
static void level1(void);
static ULONG level2(void);
static void level5(void);

static int devReserved(void) {
    return 0;
}

static const ULONG FuncTable[] = {
    FUNCARRAY_32BIT_NATIVE,
    (ULONG)devOpen,
    (ULONG)devClose,
    (ULONG)devExpunge,
    (ULONG)devReserved,
    (ULONG)devBeginIO,
    (ULONG)devAbortIO,
    ~0
};

const struct {
    ULONG  LibSize;
    const void  *FuncTable;
    const void  *DataTable;
    void (*InitFunc)(void);
} init = {
    sizeof(struct MyDevice),
    FuncTable,
    NULL,
    (void (*)())devInit
};

const struct Resident ROMTag = {
    RTC_MATCHWORD,
    (APTR)&ROMTag,
    (APTR)(&ROMTag + 1),
    RTF_PPC | RTF_AUTOINIT | RTF_EXTENDED,
    VERSION,
    NT_DEVICE,
    0,
    DEVNAME,
    DEVNAME " " VERSION_STR "." REVISION_STR " (" DATE ")\r\n",
    (APTR)&init,
    REVISION,
    NULL
};

const char vers[] = "$VER: " DEVNAME " " VERSION_STR "." REVISION_STR " (" DATE ")";

ULONG __abox__ = 1;

static const struct EmulLibEntry _gate_level2 = {
    TRAP_LIB, 0, (void (*)())level2
};

static struct Interrupt VBInterrupt = {
    {NULL, NULL, NT_INTERRUPT, 0, DEVNAME },
    &readQ,
    (APTR)&_gate_level2
};

static const struct EmulLibEntry _gate_level5 = {
    TRAP_LIBNR, 0, (void (*)())level5
};

static struct Interrupt RBFInterrupt = {
    {NULL, NULL, NT_INTERRUPT, 0, DEVNAME },
    NULL,
    (APTR)&_gate_level5
};

static const struct EmulLibEntry _gate_level1 = {
    TRAP_LIBNR, 0, (void (*)())level1
};

static struct Interrupt TBEInterrupt = {
    {NULL, NULL, NT_INTERRUPT, 0, DEVNAME },
    NULL,
    (APTR)&_gate_level1
};


static struct MyDevice *devInit(struct MyDevice *base,
				LONG seglist,
				struct ExecBase *sysbase) {
    KPRINTF(10, ("devInit(%lx, %lx, %lx)\n", base, seglist, sysbase));
    SysBase = sysbase;
    base->vb_SegList = seglist;
    base->vb_Initialized = 0;
    base->vb_CurRBuf = NULL;
    base->vb_CurRBufLen = 0;
    KPRINTF(10, ("openCnt = %ld\n", base->vb_Library.lib_OpenCnt));
    return base;
}


static int allocResource(struct MyDevice *base, int bits) {
    UBYTE *user;
    if (user = AllocMiscResource(bits, (UBYTE *)DEVNAME)) {
	struct Device *dev = (APTR)FindName(&SysBase->DeviceList, user);
	if (dev) {
	    RemDevice(dev);
	    user = AllocMiscResource(bits, DEVNAME);
	}
    }
    return user == NULL;
}



static struct MyDevice *devOpen(void) {
    long unit = REG_D0;
    struct IOExtSer *ioreq = (APTR)REG_A1;
    struct MyDevice *base = (APTR)REG_A6;
    LONG err;
    struct MyDevice *ret = NULL;

    KPRINTF(10, ("devOpen(%lx, %lx)\n", ioreq, base));

    ++base->vb_Library.lib_OpenCnt;
    base->vb_Library.lib_Flags &= ~LIBF_DELEXP;

    KPRINTF(10, ("openCnt = %ld\n", base->vb_Library.lib_OpenCnt));

    if (ioreq->IOSer.io_Message.mn_Length < sizeof(struct IOExtSer)) {
	err = IOERR_BADLENGTH;
	KPRINTF(20, ("Bad length\n"));
	goto end;
    }

    if (unit != 0) {
	err = IOERR_OPENFAIL;
	KPRINTF(20, ("Bad unit\n"));
	goto end;
    }

    if (base->vb_Library.lib_OpenCnt == 1) {

	base->vb_SerFlags = ioreq->io_SerFlags;

	if (!base->vb_Initialized) {

	    KPRINTF(5, ("Initialization\n"));

	    MiscBase = OpenResource("misc.resource");
	    if (allocResource(base, MR_SERIALPORT)) {
		if (allocResource(base, MR_SERIALBITS)) {
		    struct Preferences prefs;
		    struct Preferences *prf;

		    if (IntuitionBase = (APTR)OpenLibrary("intuition.library", 0)) {
			static const int baudTable[] = {
			    112, 300, 1200, 2400, 4800, 9600, 19200,
			    31250, 38400, 57600, 62400, 64800,
			    76800, 115200
			};

			prf = GetPrefs(&prefs, sizeof(prefs));

			base->vb_DefBaud = baudTable[prf->BaudRate];
//#if NEWCODE
			base->vb_DefRBufLen = 512 << (prf->SerStopBuf & SBUFSIZE_BITS);
/*#else
			base->vb_DefRBufLen = ((prf->SerStopBuf & SBUFSIZE_BITS) + 8) << 2;
#endif*/
			CloseLibrary((APTR)IntuitionBase);
		    } else {
			base->vb_DefRBufLen = 4096;
			base->vb_DefBaud = 9600;
		    }

		    KPRINTF(10, ("baud = %ld, buflen = %ld\n", base->vb_DefBaud, base->vb_DefRBufLen));

		    if (err = internalReset(base, base->vb_DefRBufLen, base->vb_DefBaud)) {
			FreeMiscResource(MR_SERIALBITS);
			FreeMiscResource(MR_SERIALPORT);
			KPRINTF(20, ("BufErr \n"));
			goto end;
		    } else if (OpenDevice("timer.device", UNIT_VBLANK, (APTR)&timerReq, 0)) {
			FreeMiscResource(MR_SERIALBITS);
			FreeMiscResource(MR_SERIALPORT);
			err = SerErr_DevBusy;
			KPRINTF(20, ("No timer\n"));
			goto end;
		    }

		    Disable();

		    base->vb_SaveDDRA = ciab.ciaddra;
		    base->vb_SavePRA = ciab.ciapra;
		    ciab.ciaddra = (base->vb_SaveDDRA & PRTMASK) | CIAF_COMDTR | CIAF_COMRTS;
		    ciab.ciapra = base->vb_SavePRA & (PRTMASK | CIAF_COMDSR | CIAF_COMDSR);

		    AddIntServer(INTB_VERTB/*INTB_PORTS*/, &VBInterrupt);
		    base->vb_oldRBFInt = SetIntVector(INTB_RBF, &RBFInterrupt);
		    base->vb_oldTBEInt = SetIntVector(INTB_TBE, &TBEInterrupt);

		    custom.intreq = INTF_RBF | INTF_TBE;
		    custom.intena = INTF_SETCLR | INTF_RBF | INTF_TBE;
		    ++base->vb_Initialized;

		    Enable();
		    KPRINTF(5, ("Interrupt handlers installed\n"));

		} else {
		    err = IOERR_OPENFAIL;
		    KPRINTF(20, ("No serial bits\n"));
		    goto end;
		}
	    } else {
		err = IOERR_OPENFAIL;
		KPRINTF(20, ("No serial port\n"));
		goto end;
	    }
	}
    } else if (!(base->vb_SerFlags & SERF_SHARED) || !(base->vb_SerFlags & SERF_SHARED)) {
	err = SerErr_DevBusy;
	KPRINTF(20, ("Busy\n"));
	goto end;
    }

    Handshake = (ioreq->io_SerFlags & SERF_7WIRE) != 0;

    ioreq->io_ReadLen = 8;
    ioreq->io_WriteLen = 8;
    ioreq->io_StopBits = 1;
    ioreq->io_SerFlags = (ioreq->io_SerFlags | SERF_XDISABLED | SERF_RAD_BOOGIE |
			  SERF_QUEUEDBRK /*| SERF_7WIRE*/) &
			~(SERF_PARTY_ODD | SERF_PARTY_ON);
    ioreq->io_Baud = base->vb_CurBaud;
    ioreq->io_RBufLen = base->vb_CurRBufLen;
    base->vb_Library.lib_Flags &= ~LIBF_DELEXP;
    err = 0;
    ret = base;
    ++base->vb_Library.lib_OpenCnt;
  end:
    --base->vb_Library.lib_OpenCnt;
    KPRINTF(10, ("returned: %lx, %ld\n", ret, err));
    ioreq->IOSer.io_Error = err;
    return ret;
}


static LONG internalExpunge(struct MyDevice *base) {
    LONG ret = 0;

    KPRINTF(5, ("internalExpunge(%lx)\n", base));

    base->vb_Library.lib_Flags |= LIBF_DELEXP;
    if (base->vb_Library.lib_OpenCnt == 0) {
	ret = base->vb_SegList;
	Remove(&base->vb_Library.lib_Node);
	FreeMem((char *)base - base->vb_Library.lib_NegSize,
		base->vb_Library.lib_NegSize + base->vb_Library.lib_PosSize);
    }

    return ret;
}

static LONG devExpunge(void) {
    struct MyDevice *base = (APTR)REG_A6;
    return internalExpunge(base);
}

static LONG devClose(void) {
    struct IOExtSer *ioreq = (APTR)REG_A1;
    struct MyDevice *base = (APTR)REG_A6;
    LONG ret = 0;

    KPRINTF(10, ("devClose(%lx, %lx)\n", ioreq, base));
    KPRINTF(4, ("%ld TBEs, %ld chars written, %ld caused TBE\n", tbes, written_chars, caused_tbes));

    ioreq->IOSer.io_Device = (APTR)-1;
    if (--base->vb_Library.lib_OpenCnt == 0) {

	KPRINTF(5, ("Freeing resources.\n"));

	Disable();

	custom.intena = INTF_RBF | INTF_TBE;
	custom.intreq = INTF_RBF | INTF_TBE;
	SetIntVector(INTB_RBF, base->vb_oldRBFInt);
	SetIntVector(INTB_TBE, base->vb_oldTBEInt);
	RemIntServer(INTB_VERTB/*INTB_PORTS*/, &VBInterrupt);

	freeBuf(base);

	ciab.ciaddra |= ~PRTMASK;
	ciab.ciapra = (ciab.ciapra & PRTMASK) | (base->vb_SavePRA & ~PRTMASK);
	ciab.ciaddra = (ciab.ciaddra & PRTMASK) | (base->vb_SaveDDRA & ~PRTMASK);

	CloseDevice((APTR)&timerReq);

	FreeMiscResource(MR_SERIALBITS);
	FreeMiscResource(MR_SERIALPORT);

	Enable();

	--base->vb_Initialized;

	base->vb_SerFlags = 0;
	if (base->vb_Library.lib_Flags & LIBF_DELEXP) {
	    ret = internalExpunge(base);
	}
    }
    KPRINTF(10, ("lib_OpenCnt = %ld\n", base->vb_Library.lib_OpenCnt));

    return ret;
}


/* Reset the buffer and baud rate */

static ULONG internalReset(struct MyDevice *base, ULONG buflen, ULONG baud) {
    ULONG ret = 0;

    KPRINTF(5, ("internalReset(%lx, %ld, %ld)\n", base, buflen, baud));

    Disable();

    if (base->vb_CurBaud != baud) {
	base->vb_CurBaud = baud;
	custom.serper = (SysBase->PowerSupplyFrequency == 50 ? 24772416 : 25000000) / (baud * 7);
    }

    if (buflen <= baud / 4)
	buflen = 65536;

    if (base->vb_CurRBufLen != buflen) {
	UBYTE *p = AllocMem(buflen, MEMF_PUBLIC|MEMF_FAST);

	KPRINTF(5, ("buffer = %lx\n", p));

	if (p) {
	    freeBuf(base);
	    base->vb_CurRBuf = p;
	    base->vb_CurRBufLen = buflen;
	    cmdClear(base);
	} else
	    ret = SerErr_BufErr;
    }

    Enable();

    custom.adkcon = ADKF_UARTBRK;

    return ret;
}



static void internalAbortIO(struct MyDevice *base, struct IOExtSer *ioreq) {
    int abort = FALSE;

    KPRINTF(8, ("AbortIO(%lx, %lx)\n", base, ioreq));

    Disable();

    if (ioreq->IOSer.io_Flags & IOSERF_QUEUED) {
	KPRINTF(7, ("Removing from queue\n"));
	Remove(&ioreq->IOSer.io_Message.mn_Node);
	abort = TRUE;
    } else if (ioreq->IOSer.io_Flags & IOSERF_ACTIVE) {
	switch(ioreq->IOSer.io_Command) {
	  case CMD_READ:
	    KPRINTF(7, ("Aborting active read: %lx.\n", cw_IOReq));
	    cr_IOReq = NULL;
	    abort = TRUE;
	    break;

	  case CMD_WRITE:
	  case SDCMD_BREAK:
	    KPRINTF(7, ("Aborting active write: %lx, %ld\n", cw_IOReq, cw_Length));
	    cw_Length = 0;
	    cw_IOReq = NULL;
	    ioreq->IOSer.io_Actual = cw_Buffer - (UBYTE *)ioreq->IOSer.io_Data;
	    custom.intreq = INTF_SETCLR | INTF_TBE;
	    abort = TRUE;
	    break;

	}
    }

    if (abort) {
	ioreq->IOSer.io_Error = IOERR_ABORTED;
	ioreq->IOSer.io_Flags = (ioreq->IOSer.io_Flags | IOSERF_ABORT) &
			       ~(IOSERF_QUEUED | IOSERF_ACTIVE);
	if (!(ioreq->IOSer.io_Flags & IOF_QUICK)) {
	    KPRINTF(7, ("Replying \n"));
	    ReplyMsg(&ioreq->IOSer.io_Message);
	}
    }

    Enable();
}

static void devAbortIO(void) {
    struct IOExtSer *ioreq = (APTR)REG_A1;
    struct MyDevice *base = (APTR)REG_A6;
    internalAbortIO(base, ioreq);
}


/* Free internal buffer */

static void freeBuf(struct MyDevice *base) {
    if (base->vb_CurRBuf) {
	FreeMem(base->vb_CurRBuf, base->vb_CurRBufLen);
	base->vb_CurRBuf = NULL;
	base->vb_CurRBufLen = 0;
    }
}


/* Reset the serial read buffer */

static ULONG cmdClear(struct MyDevice *base) {
    KPRINTF(8, ("CMD_CLEAR\n"));
    Disable();
    i_BufPtr = base->vb_CurRBuf;
    i_BufIn = base->vb_CurRBuf;
    i_BufOut = base->vb_CurRBuf;
    i_BufEnd = base->vb_CurRBuf + base->vb_CurRBufLen;
    i_InCnt = 0;
    i_Thresh = base->vb_CurRBufLen - (base->vb_CurBaud >> 4);
    Enable();
    return 0;
}


static ULONG cmdInvalid(struct IOExtSer *ioreq) {
    KPRINTF(20, ("CMD_INVALID\n"));
    ioreq->IOSer.io_Error = IOERR_NOCMD;
    return 0;
}

static ULONG cmdReset(struct MyDevice *base, struct IOExtSer *ioreq) {
    KPRINTF(10, ("CMD_RESET\n"));
    cmdFlush(ioreq);

    Disable();

    if (cr_IOReq)
	internalAbortIO(base, cr_IOReq);

    if (cw_IOReq)
	internalAbortIO(base, cw_IOReq);

    ioreq->io_ReadLen = 8;
    ioreq->io_WriteLen = 8;
    ioreq->io_StopBits = 1;
    ioreq->io_Baud = base->vb_DefBaud;
    ioreq->io_RBufLen = base->vb_DefRBufLen;

    ioreq->IOSer.io_Error = internalReset(base, base->vb_DefRBufLen, base->vb_DefBaud);

    Enable();
    return 0;
}

static void internalFlush(struct MinList *queue) {
    struct IOExtSer *ioreq;
    struct IOExtSer *next;

    Disable();
    ioreq = (struct IOExtSer *)queue->mlh_Head;
    queue->mlh_Head = (APTR)&queue->mlh_Tail;
    queue->mlh_Tail = NULL;
    queue->mlh_TailPred = (APTR)queue;
    Enable();

    while (next = (struct IOExtSer *)ioreq->IOSer.io_Message.mn_Node.ln_Succ) {
	ioreq->IOSer.io_Flags &= ~IOSERF_QUEUED;
	ioreq->IOSer.io_Error = IOERR_ABORTED;
	ReplyMsg(&ioreq->IOSer.io_Message);
	ioreq = next;
    }
}

static ULONG cmdFlush(struct IOExtSer *ioreq) {
    KPRINTF(8, ("CMD_FLUSH\n"));
    internalFlush(&readQ);
    internalFlush(&writeQ);
    return 0;
}


static ULONG cmdRead(struct IOExtSer *ioreq) {
    ULONG ret;

    KPRINTF(3, ("CMD_READ(%lx, %ld%s) inCnt = %ld\n", ioreq, ioreq->IOSer.io_Length, ioreq->io_SerFlags & SERF_EOFMODE ? ", EOFMODE" : "", i_InCnt));

    ioreq->IOSer.io_Actual = 0;

    if (ret = ioreq->IOSer.io_Length) {

	/* This can be used to circumvent a bug in NComm 3.0 which
	 * references the buffer even when there was nothing read.
	 */
#if NCOMM
	*(UBYTE *)ioreq->IOSer.io_Data = 0;
#endif

	/* The disable counter works just like exec's TDNestCnt field.  It's
	 * initialized to -1.  After incrementing, if it is 0, then we
	 * can attempt to process this request immediately.  If it's > 0,
	 * then we're already disabled and we must queue this request.
	 */
	Disable();
	++disableRead; /* not atomic on PPC */
	Enable();

	if (disableRead <= 0) {

	    /* If we're already processing a request, this one has to wait
	     * until that one is done, so go queue it.
	     */
	    if (!cr_IOReq) {

		/* If we don't have enough bytes to satisfy this request then go
		 * queue it.
		 */
		if (i_InCnt >= ioreq->IOSer.io_Length) {

		    /* Setup fields and go copy the data */
		    cr_OutPtr = ioreq->IOSer.io_Data;
		    cr_Length = ioreq->IOSer.io_Length;
		    copyData(ioreq);

		    Disable();
		    --disableRead;
		    Enable();
		    return 0;
		}

	    }
	}

	/* Just set flags and queue.  The read interrupt will handle it. */
	ioreq->IOSer.io_Flags |= IOSERF_QUEUED;
	Disable();
	AddTail((struct List *)&readQ, &ioreq->IOSer.io_Message.mn_Node);
	--disableRead;
	Enable();
    }

    return ret;
}


static void queueWrite(struct IOExtSer *ioreq) {

    KPRINTF(2, ("queueWrite(%lx)\n", ioreq));

    Disable();

    ioreq->IOSer.io_Flags |= IOSERF_QUEUED;

    /* Add request to end of queue. */
    AddTail((struct List *)&writeQ, &ioreq->IOSer.io_Message.mn_Node);

    /* If we have an active request, don't force interrupt. */
    if (!cw_IOReq) {
	KPRINTF(1, ("causing TBE interrupt. Intenar = %lx\n", custom.intenar));
	custom.intreq = INTF_SETCLR | INTF_TBE;
	DB(++caused_tbes;)
    } else
	KPRINTF(4, ("Already a pending write: %lx, %ld\n", cw_IOReq, cw_Length));

    Enable();

}

static ULONG cmdWrite(struct IOExtSer *ioreq) {
    ULONG ret = 0;

    KPRINTF(4, ("CMD_WRITE(%lx, %ld)\n", ioreq, ioreq->IOSer.io_Length));

    ioreq->IOSer.io_Actual = 0;

    if (ioreq->IOSer.io_Length) {

#if EOFCODE
	if (ioreq->IOSer.io_Flags & SERF_EOFMODE) {
	    ioreq->IOSer.io_Error = SerErr_InvParam;
	    return 0;
	}
#endif

#if NEGCHECK
	if (ioreq->IOSer.io_Length == -1)
	    ioreq->IOSer.io_Length = strlen(ioreq->IOSer.io_Data);
#endif

	queueWrite(ioreq);
	ret = 1;
    }

    return ret;
}


static ULONG sdcmdBreak(struct IOExtSer *ioreq) {
    KPRINTF(4, ("SDCMD_BREAK\n"));
    queueWrite(ioreq);
    return 1;
}


static ULONG sdcmdQuery(struct IOExtSer *ioreq) {
    KPRINTF(2, ("SDCMD_QUERY\n"));
    Disable();
    ioreq->io_Status = ciab.ciapra & (~PRTMASK & 0xff);
#if SETDSR
    ioreq->io_Status &= ~CIAF_COMDSR;
#endif
    ioreq->IOSer.io_Actual = i_InCnt;
    Enable();
    KPRINTF(2, ("status = %lx, actual = %ld\n", ioreq->io_Status, ioreq->IOSer.io_Actual));
    return 0;
}


static ULONG sdcmdSetParams(struct MyDevice *base, struct IOExtSer *ioreq) {
    ULONG err = 0;

    KPRINTF(8, ("SDCMD_SETPARAMS: CtlChar = %08lx, ExtFlags = %08lx, SerFlags = %02lx\n"
	     "\t\tTermArray = %08lx %08lx\n",
	     ioreq->io_CtlChar, ioreq->io_ExtFlags, ioreq->io_SerFlags,
	     ioreq->io_TermArray.TermArray0, ioreq->io_TermArray.TermArray1));

    /* Validate the read, write, and stop bit lengths. */

    if (ioreq->io_ReadLen == 8 &&
	ioreq->io_WriteLen == 8 &&
	ioreq->io_StopBits == 1) {

	/*  Get and validate the baud rate. */

	int baud = ioreq->io_Baud;

	if (!baud) {
	    baud = base->vb_CurBaud;
	    if (!baud)
		baud = base->vb_DefBaud;
	}

	if (baud >= 110 && baud <= 292000) {

	    /* Get and validate the buffer length. */

	    int rlen = ioreq->io_RBufLen;

	    if (!rlen) {
		rlen = base->vb_CurRBufLen;
		if (!rlen)
		    rlen = base->vb_DefRBufLen;
	    }

	    err = internalReset(base, rlen, baud);

	    /* If the 7wire bit is not on, we will only use 3-wire protocol */

	    Handshake = (ioreq->io_SerFlags & SERF_7WIRE) != 0;

	} else
	    err = SerErr_InvParam;

    } else
	err = SerErr_InvParam;

    KPRINTF(8, ("err = %d\n", err));

    return err;
}


static void devBeginIO(void) {
    struct IOExtSer *ioreq = (APTR)REG_A1;
    struct MyDevice *base = (APTR)REG_A6;
    ULONG ret = 0;

    KPRINTF(1, ("BeginIO(%lx, %lx, %ld)\n", base, ioreq, ioreq->IOSer.io_Command));

    ioreq->IOSer.io_Message.mn_Node.ln_Type = NT_MESSAGE;
    ioreq->IOSer.io_Error = 0;
    ioreq->IOSer.io_Flags &= ~(IOSERF_QUEUED|IOSERF_ACTIVE);

    switch(ioreq->IOSer.io_Command) {
      case CMD_INVALID:
      case CMD_UPDATE:
      case CMD_STOP:
      case CMD_START:
	ret = cmdInvalid(ioreq);
	break;

      case CMD_RESET:
	ret = cmdReset(base, ioreq);
	break;

      case CMD_READ:
	ret = cmdRead(ioreq);
	break;

      case CMD_WRITE:
	ret = cmdWrite(ioreq);
	break;

      case CMD_CLEAR:
	ret = cmdClear(base);
	break;

      case CMD_FLUSH:
	ret = cmdFlush(ioreq);
	break;

      case SDCMD_QUERY:
	ret = sdcmdQuery(ioreq);
	break;

      case SDCMD_BREAK:
	ret = sdcmdBreak(ioreq);
	break;

      case SDCMD_SETPARAMS:
	ret = sdcmdSetParams(base, ioreq);
	break;

      default:
	ioreq->IOSer.io_Error = IOERR_NOCMD;
	break;
    }

    if (ret)
	ioreq->IOSer.io_Flags &= ~IOF_QUICK;
    else if (!(ioreq->IOSer.io_Flags & IOF_QUICK))
	ReplyMsg(&ioreq->IOSer.io_Message);
}


/* Checks CTS status and if clear generates a TBE interrupt or
 * requeues the timer request.
 *
 * Entered from Exec using the MsgPort callback.
 */
static void timerRtn(void) {

    KPRINTF(4, ("Time request returned\n"));

    Remove(&timerReq.tr_node.io_Message.mn_Node);

    Disable();
    if (cw_IOReq && cw_IOReq->IOSer.io_Command == SDCMD_BREAK) {
	custom.adkcon = ADKF_UARTBRK;
	KPRINTF(4, ("Replying SDCMD_BREAK %lx\n", cw_IOReq));
	cw_IOReq->IOSer.io_Flags &= ~IOSERF_ACTIVE;
	cw_IOReq->IOSer.io_Error = 0;
	ReplyMsg(&cw_IOReq->IOSer.io_Message);
	cw_IOReq = NULL;
	cw_Length = 0;
	if (writeQ.mlh_Head->mln_Succ) {
	    KPRINTF(4, ("cause TBE\n"));
	    custom.intreq = INTF_SETCLR | INTF_TBE;
	    DB(++caused_tbes;)
	}
	Enable();

    } else {
	Enable();

	if (Handshake && ciab.ciapra & CIAF_COMCTS) {
		KPRINTF(4, ("Sending time request\n"));
		timerReq.tr_time.tv_micro = 1000;
		SendIO(&timerReq.tr_node);
	} else {
		KPRINTF(4, ("cause TBE\n"));
		custom.intreq = INTF_SETCLR | INTF_TBE;
		DB(++caused_tbes;)
	}
    }
}



static ULONG copyData(struct IOExtSer *ioreq) {
    UBYTE *from = i_BufOut;
    LONG inCnt = i_InCnt;
    UBYTE *to = cr_OutPtr;
    LONG length = cr_Length;
    ULONG ret = 0;
    int k;

    KPRINTF(2, ("copyData(%ld, %ld)\n", inCnt, length));

    /* If we don't have enough bytes to satisfy the request,
     * set the length to the number of bytes we do have.
     */
    if (length > inCnt)
	length = inCnt;

    do {
	inCnt = length;

	/* If the copy will extend past the end of the buffer, we can
	 * only copy the number of bytes to the end this go around.
	 */
	if (inCnt > i_BufEnd - from)
	    inCnt = i_BufEnd - from;

#if EOFCODE
	if (ioreq->io_SerFlags & SERF_EOFMODE) {
	    ULONG t0 = ioreq->io_TermArray.TermArray0;
	    ULONG t1 = ioreq->io_TermArray.TermArray1;

	    for (k = 1; k <= inCnt; ++k) {
		ULONG c = *from++;
		ULONG t;

/*{static int cnt=0; if(++cnt<=1000)KPRINTF(0, ("copy %04lx: '%lc'\n", c,
					   c >= ' ' && c < 0x7f ? c : '.'));}*/
		*to++ = c;

		t = t0 >> 24;
		if (c < t) {
		    t = (UBYTE)(t0 >> 16);
		    if (c < t) {
			t = (UBYTE)(t0 >> 8);
			if (c < t) {
			    t = (UBYTE)t0;
			    if (c < t) {
				t = t1 >> 24;
				if (c < t) {
				    t = (UBYTE)(t1 >> 16);
				    if (c < t) {
					t = (UBYTE)(t1 >> 8);
					if (c < t) {
					    t = (UBYTE)t0;
					}
				    }
				}
			    }
			}
		    }
		}
		if (c == t) {
		    KPRINTF(1, ("Got break char.\n"));
		    length = k;
		    cr_Length = 0;
		    break;
		}
	    }

	    length -= k;

	} else
#endif
	       {

	    for (k = inCnt; --k >= 0; ) {
/*{static int cnt=0; if(++cnt<=1000)KPRINTF(0, ("copy %04lx: '%lc'\n", *from,
					 (UBYTE)*from >= ' ' && (UBYTE)*from < 0x7f ? (UBYTE)*from : '.'));}*/
		*to++ = *from++;
	    }

	    /* If the following calculation results in a value greater than
	     * zero, then we have a buffer wrap and need to process the
	     * remaining bytes at the beginning of the buffer.
	     */

	    length -= inCnt;
	}

	if (length > 0)
	    from = i_BufPtr;

    } while (length > 0);

    length = to - cr_OutPtr;
    cr_OutPtr = to;

    /* Update output ptr and I/O request */
    i_BufOut = from;
    ioreq->IOSer.io_Actual += length;

    Disable();
    /* Update number of bytes left in the buffer. */
    i_InCnt -= length;

    /* If the threshold becomes positive here, then, if requested,
     * tell the other end that it's okay to start sending more data.
     */

    i_Thresh += length;
    if (i_Thresh >= 0 && Handshake) {
	if (i_Thresh - length < 0)
	    KPRINTF(4, ("Clearing RTS\n"));
	ciab.ciapra &= ~CIAF_COMRTS;
    }

    /* Set error if we've had any overruns. */
    if (Overrun) {
	Overrun = FALSE;
	ioreq->IOSer.io_Error = SerErr_LineErr;
    }
    Enable();

    /* Calc number of bytes left to copy.  If the result is greater
     * than zero, then we have more to copy so return an incomplete
     * status.
     */

    cr_Length -= length;
    if (cr_Length <= 0) {
	/* We've completed the I/O request either by copying the requested
	 * of bytes or by finding an EOFMODE character, so return a "reply"
	 * status.
	 */
	 ret = 1;
    }

    KPRINTF(2, ("io_Actual = %ld, io_Error = %ld\n", ioreq->IOSer.io_Actual, ioreq->IOSer.io_Error));
    return ret;
}


static void level1(void) {

    DB(++tbes;)

    /* Clear the interrupt */
    custom.intreq = INTF_TBE;

    /* If we're not handshaking, bypass it. */
    if (!Handshake || !(ciab.ciapra & CIAF_COMCTS)) {
      start:
	--cw_Length;
	if (cw_Length < 0) {
	    /* Write request completed */

	    if (cw_IOReq) {
		/* Reply it and setup for next */
		KPRINTF(4, ("Replying CMD_WRITE %lx\n", cw_IOReq));
		cw_IOReq->IOSer.io_Flags &= ~IOSERF_ACTIVE;
		cw_IOReq->IOSer.io_Error = 0;
		ReplyMsg(&cw_IOReq->IOSer.io_Message);
	    }

	    if (writeQ.mlh_Head->mln_Succ) {

		struct IOExtSer *ioreq = (struct IOExtSer *)writeQ.mlh_Head;

		Remove(&ioreq->IOSer.io_Message.mn_Node);

		KPRINTF(1, ("Start %lx transmition\n", ioreq));

		if (ioreq->IOSer.io_Command == SDCMD_BREAK) {

		    KPRINTF(1, ("Sending break\n"));
		    cw_IOReq = ioreq;
		    cw_Length = 0;
		    ioreq->IOSer.io_Flags = (ioreq->IOSer.io_Flags & ~IOSERF_QUEUED) | IOSERF_ACTIVE;
		    custom.adkcon = ADKF_SETCLR | ADKF_UARTBRK;
		    timerReq.tr_time.tv_micro = ioreq->io_BrkTime;
		    KPRINTF(4, ("Sending time request\n"));
		    SendIO(&timerReq.tr_node);

		} else {
		    KPRINTF(1, ("write len = %ld\n", ioreq->IOSer.io_Length));
		    /* Check for absolute length */
		    cw_IOReq = ioreq;
		    cw_Buffer = ioreq->IOSer.io_Data;
		    cw_Length = ioreq->IOSer.io_Length;
		    ioreq->IOSer.io_Actual = ioreq->IOSer.io_Length;
		    ioreq->IOSer.io_Flags = (ioreq->IOSer.io_Flags & ~IOSERF_QUEUED) | IOSERF_ACTIVE;
		    goto start;
		}

	    } else {
		/* There aren't anymore requests, so clear and exit */
		cw_Length = 0;
		cw_IOReq = NULL;
		KPRINTF(4, ("Transmission finished.\n"));
	    }

	} else {
	    /* Currently processing a request. */
/*{ static int cnt=0; if(++cnt<=1000)KPRINTF(0, ("write '%lc' %lx\n", *cw_Buffer >= ' ' && *cw_Buffer < 0x7f ? *cw_Buffer : '.', *cw_Buffer));}*/
	    custom.serdat = *cw_Buffer++ | (1 << 8); /* next byte + stop bit */
	    DB(++written_chars;)
	}
    } else {
	/* Queue a timer request to recheck CTS status */
	timerReq.tr_time.tv_micro = 1000;
	KPRINTF(4, ("Sending time request\n"));
	SendIO(&timerReq.tr_node);
    }
}


static ULONG level2(void) {
    struct List *rqueue = (APTR)REG_A1;

    /* If there's nothing in the buffer, there's no point in going
     * any further.
     */
    if (i_InCnt) {

	/* If we've been "disabled" then get out. */

	if (disableRead < 0) {
	    struct IOExtSer *ioreq;

	    /* If we have an active request, try to fulfill it. */

	    if (!cr_IOReq && rqueue->lh_Head->ln_Succ) {
		struct IOExtSer *ioreq = (struct IOExtSer *)rqueue->lh_Head;

		KPRINTF(1, ("Start filling read request\n"));

		/* Remove the node from the list */
		Remove(&ioreq->IOSer.io_Message.mn_Node);

		/* Setup fields for processing a read request */
		cr_IOReq = ioreq;
		cr_OutPtr = ioreq->IOSer.io_Data;
		cr_Length = ioreq->IOSer.io_Length;
		ioreq->IOSer.io_Flags = (ioreq->IOSer.io_Flags & ~IOSERF_QUEUED) | IOSERF_ACTIVE;
	    }

	    if (ioreq = cr_IOReq) {
		/* Process an active I/O request */
		if (cr_Length > 0) {
		    if (copyData(ioreq)) {
			cr_IOReq = NULL;
			ioreq->IOSer.io_Flags &= ~IOSERF_ACTIVE;
			KPRINTF(3, ("Replying CMD_READ %lx\n", ioreq));
			ReplyMsg(&ioreq->IOSer.io_Message);
		    }
		}
	    }
	}
    }

    /* For ppc code, REG_D0 is checked instead of Z flag */
    return 0;
}


static void level5(void) {

    UWORD dat = custom.serdatr;

    /* If we've missed some data, set overrun flag. */
    if ((WORD)dat < 0) {
	KPRINTF(20, ("****** Overrun !\n"));
	Overrun = TRUE;
    }

    /* Clear the interrupt. */
    custom.intreq = INTF_RBF;

    *i_BufIn++ = (UBYTE)dat;
    ++i_InCnt;

/*{static int cnt=0; if(++cnt<=1000)KPRINTF(0, ("read %04lx: '%c'\n", dat,
					 (UBYTE)dat >= ' ' && (UBYTE)dat < 0x7f ? (UBYTE)dat : '.'));}*/

    /* If we hit physical end of buffer, wrap to the start. */
    if (i_BufIn == i_BufEnd)
	i_BufIn = i_BufPtr;

    --i_Thresh;

    if (i_Thresh == 0) {
	/* Hit buffer threshold, so tell other end not to send any more data. */
	if (Handshake) {
	    KPRINTF(4, ("Setting RTS\n"));
	    ciab.ciapra |= CIAF_COMRTS;
	}
    }
}


