/*
 *----------------------------------------------------------------------------
 *                         bootmouse class for poseidon
 *----------------------------------------------------------------------------
 *                   By Chris Hodges <hodges@in.tum.de>
 *
 * History
 *
 *  11-03-2002  - Initial
 *  14-04-2002  - Various little changes, compiles with MorphOS target
 */

#include "debug.h"
#include "bootmouse.class_VERSION.h"

#include <proto/muimaster.h>
#ifndef __MORPHOS__
#include <pragmas/exec_sysbase_pragmas.h>
#else
#define USE_INLINE_STDARG
#define __NOLIBBASE__
#endif
#include <proto/exec.h>
#include <proto/poseidon.h>
#include <proto/utility.h>

#include "bootmouse.class.h"

#ifdef __MORPHOS__
#include <ppcinline/poseidon.h>
#include <ppcinline/intuition.h>
#endif

#undef	SysBase
#undef  PsdBase
#undef  UtilityBase

#define LIBNAME             "bootmouse.class"

#define LE2BE_W(x) (((x<<8) & 0xffff) | (x>>8))

/* /// "Lib Stuff" */
struct initstruct
{
    const ULONG libsize;
    const void  *functable;
    const void  *datatable;
    void  (*initfunc)(void);
};


/* MorphOS m68k->ppc gate functions
*/

DECLGATE(static const, nHidTask, LIBNR)
DECLGATE(static const, nGUITask, LIBNR)

/* local protos
*/

#ifdef __MORPHOS__

struct NepHidBase *libInit(struct NepHidBase *nh,
                         BPTR seglist,
                         struct ExecBase *SysBase);
#else /* __MORPHOS__ */

struct NepHidBase *NATDECLFUNC_3(libInit,
                               d0, struct NepHidBase *, nh,
                               a0, BPTR, seglist,
                               a6, struct ExecBase *, SysBase);
#endif /* __MORPHOS__ */

struct NepHidBase *NATDECLFUNC_2(libOpen,
                               d0, ULONG, version,
                               a6, struct NepHidBase *, nh);

BPTR NATDECLFUNC_1(libClose,
                   a6, struct NepHidBase *, nh);

BPTR NATDECLFUNC_1(libExpunge,
                   a6, struct NepHidBase *, nh);

BPTR i_libExpunge(struct NepHidBase *nh);

ULONG libReserved(void);

/* Function prototypes */

DEFDECLFUNC_2(struct NepClassHid *, usbAttemptDeviceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct PsdDevice *, pd);

DEFDECLFUNC_2(void, usbReleaseDeviceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct NepClassHid *, nch);

DEFDECLFUNC_2(struct NepClassHid *, usbAttemptInterfaceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct PsdInterface *, pif);

DEFDECLFUNC_2(void, usbReleaseInterfaceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct NepClassHid *, nch);

DEFDECLFUNC_2(struct NepClassHid *, usbForceDeviceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct PsdDevice *, pd);

DEFDECLFUNC_2(struct NepClassHid *, usbForceInterfaceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct PsdInterface *, pif);

DEFDECLFUNC_4(LONG, usbGetAttrsA,
                   a6, struct NepHidBase *, nh,
                   d0, ULONG, type,
                   a0, APTR, usbstruct,
                   a1, struct TagItem *, tags);

DEFDECLFUNC_4(LONG, usbSetAttrsA,
                   a6, struct NepHidBase *, nh,
                   d0, ULONG, type,
                   a0, APTR, usbstruct,
                   a1, struct TagItem *, tags);

DEFDECLFUNC_3(LONG, usbDoMethodA,
                   a6, struct NepHidBase *, nh,
                   d0, ULONG, methodid,
                   a1, APTR, methoddata);


/* This is a library, not executable
*/
static
int fakemain(void)
{
    return -1;
}

void callfake(void)
{
    fakemain();
}

/* Important! Magic cookie for MorphOS
*/
#ifdef __MORPHOS__
const ULONG __amigappc__ = 1;
#endif /* __MORPHOS__ */


const char libname[];
const char libidstring[];
static
const struct initstruct libraryinitstruct;


static
const struct Resident ROMTag =
{
    RTC_MATCHWORD,
    (struct Resident *) &ROMTag,
    (struct Resident *) (&ROMTag + 1),
#ifdef __MORPHOS__
    RTF_PPC | RTF_AUTOINIT | RTF_COLDSTART,
#else /* __MORPHOS__ */
    RTF_AUTOINIT | RTF_COLDSTART,
#endif /* __MORPHOS__ */
    VERSION,
    NT_LIBRARY,
    39, /* Behind input.device */
    (char *) libname,
    (char *) libidstring,
    (APTR) &libraryinitstruct
};


/* Static data
*/

/*static
const ULONG FuncTable[]; */

static
const ULONG FuncTable[] =
{
#ifdef __MORPHOS__
    FUNCARRAY_32BIT_NATIVE,
#endif /* __MORPHOS__ */
    LVOENTRY(libOpen)
    LVOENTRY(libClose)
    LVOENTRY(libExpunge)
    (ULONG) libReserved,

    LVOENTRY(usbAttemptInterfaceBinding)
    LVOENTRY(usbReleaseInterfaceBinding)
    LVOENTRY(usbAttemptDeviceBinding)
    LVOENTRY(usbReleaseDeviceBinding)
    LVOENTRY(usbForceInterfaceBinding)
    LVOENTRY(usbForceDeviceBinding)
    LVOENTRY(usbGetAttrsA)
    LVOENTRY(usbSetAttrsA)
    LVOENTRY(usbDoMethodA)
    0xFFFFFFFF
};

const char libname[]     = LIBNAME;
const char libidstring[] = VSTRING;
const char libverstag[]  = VERSTAG;

static
const struct initstruct libraryinitstruct =
{
    sizeof(struct NepHidBase),
    FuncTable,
    NULL,
    (void (*)(void)) libInit
};

/*
 *===========================================================
 * libInit(nh, seglist, SysBase)
 *===========================================================
 *
 * This is the the LIB_INIT function.
 *
 */

#ifdef __MORPHOS__

struct NepHidBase * libInit(struct NepHidBase *nh,
                        BPTR seglist,
                        struct ExecBase *SysBase)
{

#else /* __MORPHOS__ */

struct NepHidBase * NATDECLFUNC_3(libInit,
                              d0, struct NepHidBase *, nh,
                              a0, BPTR, seglist,
                              a6, struct ExecBase *, SysBase)
{
    DECLARG_3(d0, struct NepHidBase *, nh,
              a0, BPTR, seglist,
              a6, struct ExecBase *, SysBase)

#endif /* __MORPHOS__ */

    struct ClsDevCfg *cdc;
    struct NepClassHid *nch;
    struct NepHidBase *ret = NULL;

    KPRINTF(10, ("libInit nh: 0x%08lx seglist: 0x%08lx SysBase: 0x%08lx\n",
                 nh, seglist, SysBase));

    /* Store sysnh & segment */
    nh->nh_SysBase = SysBase;
#define	SysBase	nh->nh_SysBase
    nh->nh_SegList = seglist;
    nh->nh_UtilityBase = OpenLibrary("utility.library", 39);

#define	UtilityBase	nh->nh_UtilityBase

    if(UtilityBase)
    {
        /* Initialize device node & library struct
        */
        nh->nh_Library.lib_Node.ln_Type = NT_LIBRARY;
        nh->nh_Library.lib_Node.ln_Name = (char *) libname;
        nh->nh_Library.lib_Flags        = LIBF_SUMUSED | LIBF_CHANGED;
        nh->nh_Library.lib_Version      = VERSION;
        nh->nh_Library.lib_Revision     = REVISION;
        nh->nh_Library.lib_IdString     = (char *) libidstring;

        nch = &nh->nh_DummyNCH;
        nch->nch_SysBase = (struct Library *) nh->nh_SysBase;
        nch->nch_ClsBase = nh;
        nch->nch_Interface = NULL;
        nch->nch_CDC = cdc = AllocVec(sizeof(struct ClsDevCfg), MEMF_PUBLIC|MEMF_CLEAR);
        if(cdc)
        {
            /* Create default config */
            cdc->cdc_ChunkID = MAKE_ID('B','M','S','E');
            cdc->cdc_Length = sizeof(struct ClsDevCfg)-8;
            cdc->cdc_Wheelmouse = FALSE;

            ret = nh;
        }

    } else {
        KPRINTF(20, ("libInit: OpenLibrary(\"utility.library\", 39) failed!\n"));
    }

    KPRINTF(10, ("libInit: Ok\n"));
    return(ret);
}

/*
 *===========================================================
 * libOpen(version, nh)
 *===========================================================
 *
 * This is the the LIB_OPEN function.
 *
 */

struct NepHidBase * NATDECLFUNC_2(libOpen,
                              d0, ULONG, version,
                              a6, struct NepHidBase *, nh)
{
    DECLARG_2(d0, ULONG, version,
              a6, struct NepHidBase *, nh)

    KPRINTF(10, ("libOpen nh: 0x%08lx\n", nh));
    ++nh->nh_Library.lib_OpenCnt;
    nh->nh_Library.lib_Flags &= ~LIBF_DELEXP;
    KPRINTF(10, ("libOpen: openCnt = %ld\n", nh->nh_Library.lib_OpenCnt));
    return nh;

    /*nh->nh_Library.lib_OpenCnt--;
    return NULL;*/
}


/*
 *===========================================================
 * libClose(nh)
 *===========================================================
 *
 * This is the the LIB_EXPUNGE function.
 *
 */

BPTR NATDECLFUNC_1(libClose,
                   a6, struct NepHidBase *, nh)
{
    DECLARG_1(a6, struct NepHidBase *, nh)

    BPTR ret = NULL;

    KPRINTF(10, ("libClose nh: 0x%08lx\n", nh));

    if(--nh->nh_Library.lib_OpenCnt == 0)
    {
        if(nh->nh_Library.lib_Flags & LIBF_DELEXP)
        {
            KPRINTF(5, ("libClose: calling expunge...\n"));
            ret = i_libExpunge(nh);
        }
    }
    KPRINTF(5, ("libClose: lib_OpenCnt = %ld\n", nh->nh_Library.lib_OpenCnt));
    return(ret);
}


BPTR i_libExpunge(struct NepHidBase *nh)
{
    BPTR ret = NULL;

    KPRINTF(10, ("libExpunge nh: 0x%08lx\n", nh));

    if(nh->nh_Library.lib_OpenCnt == 0)
    {
        ret = nh->nh_SegList;
        KPRINTF(1, ("libExpunge: closelibrary utilitybase 0x%08lx\n",
                    UtilityBase));
        CloseLibrary((struct Library *) UtilityBase);

        FreeVec(nh->nh_DummyNCH.nch_CDC);

        KPRINTF(5, ("libExpunge: removing library node 0x%08lx\n",
                    &nh->nh_Library.lib_Node));
        Remove(&nh->nh_Library.lib_Node);

        KPRINTF(5, ("libExpunge: FreeMem()...\n"));
        FreeMem((char *) nh - nh->nh_Library.lib_NegSize,
                (ULONG) (nh->nh_Library.lib_NegSize + nh->nh_Library.lib_PosSize));

        KPRINTF(5, ("libExpunge: Unloading done! bootmouse.class expunged!\n\n"));
    } else {
        KPRINTF(5, ("libExpunge: Could not expunge, LIBF_DELEXP set!\n"));
        nh->nh_Library.lib_Flags |= LIBF_DELEXP;
    }

    return(ret);
}


/*
 *===========================================================
 * libExpunge(nh)
 *===========================================================
 *
 * This is the the LIB_EXPUNGE function.
 *
 */

BPTR NATDECLFUNC_1(libExpunge,
                   a6, struct NepHidBase *, nh)
{
    DECLARG_1(a6, struct NepHidBase *, nh)
    return i_libExpunge(nh);
}


/*
 *===========================================================
 * libReserved(void)
 *===========================================================
 *
 * This is the the reserved function. It must return 0.
 *
 */

ULONG libReserved(void)
{
    return 0;
}
/* \\\ */

/*
 * ***********************************************************************
 * * Library functions                                                   *
 * ***********************************************************************
 */

#define PsdBase ps

/* /// "usbAttemptDeviceBinding()" */
struct NepClassHid * NATDECLFUNC_2(usbAttemptDeviceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct PsdDevice *, pd)
{
    DECLARG_2(a6, struct NepHidBase *, nh,
              a0, struct PsdDevice *, pd)
    KPRINTF(1, ("nepHidAttemptDeviceBinding(%08lx)\n", pd));
    return(NULL);
}
/* \\\ */

/* /// "usbForceDeviceBinding()" */
struct NepClassHid * NATDECLFUNC_2(usbForceDeviceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct PsdDevice *, pd)
{
    DECLARG_2(a6, struct NepHidBase *, nh,
              a0, struct PsdDevice *, pd)
    KPRINTF(1, ("nepHidForceDeviceBinding(%08lx)\n", pd));
    return(NULL);
}
/* \\\ */

/* /// "usbReleaseDeviceBinding()" */
void NATDECLFUNC_2(usbReleaseDeviceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct NepClassHid *, nch)
{
    DECLARG_2(a6, struct NepHidBase *, nh,
              a0, struct NepClassHid *, nch)
    KPRINTF(1, ("nepHidReleaseDeviceBinding(%08lx)\n", nch));
}
/* \\\ */

/* /// "usbAttemptInterfaceBinding()" */
struct NepClassHid * NATDECLFUNC_2(usbAttemptInterfaceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct PsdInterface *, pif)
{
    DECLARG_2(a6, struct NepHidBase *, nh,
              a0, struct PsdInterface *, pif)
    struct Library *ps;
    ULONG ifclass;
    ULONG subclass;
    ULONG proto;

    KPRINTF(1, ("nepHidAttemptInterfaceBinding(%08lx)\n", pif));
    if(ps = OpenLibrary("poseidon.library", 1))
    {
        psdGetAttrs(PGA_INTERFACE, pif,
                    IFA_Class, (ULONG) &ifclass,
                    IFA_SubClass, (ULONG) &subclass,
                    IFA_Protocol, (ULONG) &proto,
                    TAG_DONE);
        CloseLibrary(ps);

        if((ifclass == HID_CLASSCODE) && (subclass == HID_BOOT_SUBCLASS) && (proto == HID_PROTO_MOUSE))
//        if(ifclass == HID_CLASSCODE)
        {
            return(usbForceInterfaceBinding(nh, pif));
        }
    }
    return(NULL);
}
/* \\\ */

/* /// "usbForceInterfaceBinding()" */
STUBDECLFUNC_2(struct NepClassHid *, usbForceInterfaceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct PsdInterface *, pif)
{
    struct Library *ps;
    struct NepClassHid *nch;
    struct PsdConfig *pc;
    struct PsdDevice *pd;
    struct PsdIFFContext *pic;
    struct ClsDevCfg *cdc;
    STRPTR devname;
    STRPTR ifidstr;
    STRPTR devidstr;
    UBYTE buf[64];

    KPRINTF(1, ("nepHidForceInterfaceBinding(%08lx)\n", pif));
    if(ps = OpenLibrary("poseidon.library", 1))
    {
        psdGetAttrs(PGA_INTERFACE, pif,
                    IFA_Config, (ULONG) &pc,
                    IFA_IDString, (ULONG) &ifidstr,
                    TAG_DONE);
        psdGetAttrs(PGA_CONFIG, pc,
                    CA_Device, (ULONG) &pd,
                    TAG_END);
        psdGetAttrs(PGA_DEVICE, pd,
                    DA_ProductName, (ULONG) &devname,
                    DA_IDString, (ULONG) &devidstr,
                    TAG_END);
        if(nch = psdAllocVec(sizeof(struct NepClassHid)))
        {
            nch->nch_SysBase = (struct Library *) SysBase;
            nch->nch_ClsBase = nh;
            nch->nch_CDC = cdc = psdAllocVec(sizeof(struct ClsDevCfg));
            if(!cdc)
            {
                psdFreeVec(cdc);
                psdFreeVec(nch);
                CloseLibrary(ps);
                return(NULL);
            }

            nch->nch_Device = pd;
            nch->nch_Interface = pif;
            nch->nch_DevIDString = devidstr;
            nch->nch_IfIDString = ifidstr;

            /* try to load default config */
            Forbid();
            pic = psdGetClsCfg(LIBNAME);
            if(pic)
            {
                cdc = psdGetCfgChunk(pic, nh->nh_DummyNCH.nch_CDC->cdc_ChunkID);
                if(cdc)
                {
                    CopyMem(((UBYTE *) cdc) + 8, ((UBYTE *) nh->nh_DummyNCH.nch_CDC) + 8, cdc->cdc_Length);
                    psdFreeVec(cdc);
                }
            }
            *nch->nch_CDC = *nh->nh_DummyNCH.nch_CDC;

            /* Load config */
            pic = psdGetUsbDevCfg(LIBNAME, nch->nch_DevIDString, nch->nch_IfIDString);
            if(pic)
            {
                cdc = psdGetCfgChunk(pic, nch->nch_CDC->cdc_ChunkID);
                if(cdc)
                {
                    CopyMem(((UBYTE *) cdc) + 8, ((UBYTE *) nch->nch_CDC) + 8, cdc->cdc_Length);
                    psdFreeVec(cdc);
                }
            }
            Permit();

            psdSafeRawDoFmt(buf, 64, "bootmouse.class<%08lx>", nch);
            nch->nch_ReadySignal = AllocSignal(-1);
            nch->nch_ReadySigTask = FindTask(NULL);

#ifndef __MORPHOS__
            if(psdSpawnSubTask(buf, nHidTask, nch))
#else
            if(psdSpawnSubTask(buf, &nHidTask, nch))
#endif
            {
                Wait(1L<<nch->nch_ReadySignal);
                if(nch->nch_Task)
                {
                    nch->nch_ReadySigTask = NULL;
                    FreeSignal(nch->nch_ReadySignal);
                    psdAddErrorMsg(RETURN_OK, (STRPTR) libname,
                                   "I'm pleased to introduce a mouse alliance to '%s'!",
                                   devname);

                    CloseLibrary(ps);
                    return(nch);
                }
            }
            nch->nch_ReadySigTask = NULL;
            FreeSignal(nch->nch_ReadySignal);
            psdFreeVec(nch->nch_CDC);
            psdFreeVec(nch);
        }
        CloseLibrary(ps);
    }
    return(NULL);

}
/* \\\ */

/* /// "usbReleaseInterfaceBinding()" */
void NATDECLFUNC_2(usbReleaseInterfaceBinding,
                              a6, struct NepHidBase *, nh,
                              a0, struct NepClassHid *, nch)
{
    DECLARG_2(a6, struct NepHidBase *, nh,
              a0, struct NepClassHid *, nch)

    struct Library *ps;
    struct PsdConfig *pc;
    struct PsdDevice *pd;
    STRPTR devname;

    KPRINTF(1, ("nepHidReleaseInterfaceBinding(%08lx)\n", nch));
    if(ps = OpenLibrary("poseidon.library", 1))
    {
        Forbid();
        nch->nch_ReadySignal = AllocSignal(-1);
        nch->nch_ReadySigTask = FindTask(NULL);
        if(nch->nch_GUITask)
        {
            Signal(nch->nch_GUITask, SIGBREAKF_CTRL_C);
        }
        Permit();
        while(nch->nch_GUITask)
        {
            Wait(1L<<nch->nch_ReadySignal);
        }

        Forbid();
        if(nch->nch_Task)
        {
            Signal(nch->nch_Task, SIGBREAKF_CTRL_C);
        }
        Permit();
        while(nch->nch_Task)
        {
            Wait(1L<<nch->nch_ReadySignal);
        }
        FreeSignal(nch->nch_ReadySignal);
        psdGetAttrs(PGA_INTERFACE, nch->nch_Interface, IFA_Config, (ULONG) &pc, TAG_END);
        psdGetAttrs(PGA_CONFIG, pc, CA_Device, (ULONG) &pd, TAG_END);
        psdGetAttrs(PGA_DEVICE, pd, DA_ProductName, (ULONG) &devname, TAG_END);
        psdAddErrorMsg(RETURN_OK, (STRPTR) libname,
                       "A cat ate my mouse '%s'!",
                       devname);
        psdFreeVec(nch->nch_CDC);
        psdFreeVec(nch);
        CloseLibrary(ps);
    }
}
/* \\\ */

/* /// "usbGetAttrsA()" */
LONG NATDECLFUNC_4(usbGetAttrsA,
                   a6, struct NepHidBase *, nh,
                   d0, ULONG, type,
                   a0, APTR, usbstruct,
                   a1, struct TagItem *, tags)
{
    DECLARG_4(a6, struct NepHidBase *, nh,
              d0, ULONG, type,
              a0, APTR, usbstruct,
              a1, struct TagItem *, tags)

    struct TagItem *ti;
    LONG count = 0;

    KPRINTF(1, ("nepHidGetAttrsA(%ld, %08lx, %08lx)\n", type, usbstruct, tags));
    switch(type)
    {
        case UGA_CLASS:
             if(ti = FindTagItem(UCCA_Priority, tags))
             {
                 *((LONG *) ti->ti_Data) = -100;
                 count++;
             }
             if(ti = FindTagItem(UCCA_Description, tags))
             {
#ifndef __MORPHOS__
                 *((STRPTR *) ti->ti_Data) = "Support for mice/tablets in boot protocol mode";
#else
                 *((STRPTR *) ti->ti_Data) = "Support for mice/tablets in boot protocol mode (MOS)";
#endif
                 count++;
             }
             if(ti = FindTagItem(UCCA_HasClassCfgGUI, tags))
             {
                 *((ULONG *) ti->ti_Data) = TRUE;
                 count++;
             }
             if(ti = FindTagItem(UCCA_HasBindingCfgGUI, tags))
             {
                 *((ULONG *) ti->ti_Data) = TRUE;
                 count++;
             }
             break;

    }
    return(count);

}
/* \\\ */

/* /// "usbSetAttrsA()" */
LONG NATDECLFUNC_4(usbSetAttrsA,
                   a6, struct NepHidBase *, nh,
                   d0, ULONG, type,
                   a0, APTR, usbstruct,
                   a1, struct TagItem *, tags)
{
    DECLARG_4(a6, struct NepHidBase *, nh,
              d0, ULONG, type,
              a0, APTR, usbstruct,
              a1, struct TagItem *, tags)

    return(0);
}
/* \\\ */

/* /// "usbDoMethodA()" */
LONG NATDECLFUNC_3(usbDoMethodA,
                   a6, struct NepHidBase *, nh,
                   d0, ULONG, methodid,
                   a1, APTR, methoddata)
{
    DECLARG_3(a6, struct NepHidBase *, nh,
              d0, ULONG, methodid,
              a1, APTR, methoddata)
    struct Library *ps;
    struct NepClassHid *nch;
    struct ClsDevCfg *cdc;
    struct PsdIFFContext *pic;
    LONG retval = 0;

    KPRINTF(10, ("Do Method %ld\n", methodid));
    switch(methodid)
    {
        case UCM_OpenCfgWindow:
            nch = &nh->nh_DummyNCH;
            if(ps = OpenLibrary("poseidon.library", 1))
            {
                /* try to load default config */
                pic = psdGetClsCfg(LIBNAME);
                if(pic)
                {
                    cdc = psdGetCfgChunk(pic, nch->nch_CDC->cdc_ChunkID);
                    if(cdc)
                    {
                        CopyMem(((UBYTE *) cdc) + 8, ((UBYTE *) nch->nch_CDC) + 8, cdc->cdc_Length);
                        psdFreeVec(cdc);
                    }
                }
                CloseLibrary(ps);
            }
            retval = nOpenBindingCfgWindow(nh, nch);
            break;

        case UCM_OpenBindingCfgWindow:
            retval = nOpenBindingCfgWindow(nh, *((struct NepClassHid **) methoddata));
            return(retval);

        default:
            break;
    }
    return(0);
}
/* \\\ */

/**************************************************************************/

#undef  PsdBase
#define PsdBase nch->nch_Base
#undef SysBase
#define	SysBase	nch->nch_SysBase

/* /// "nHidTask()" */
void DECLFUNC_0(nHidTask)
{
    struct NepClassHid *nch;
    struct PsdPipe *pp;
    ULONG sigmask;
    ULONG sigs;
    UWORD iecode;
    UWORD qualifier;
    UWORD buts;
    UWORD oldbuts = 0;
    WORD wheel = 0;
    WORD oldwheel = 0;
    UWORD wheeliecode;
    UWORD wheeldist;
    BOOL newmouse;
    UBYTE *buf;
    UBYTE *bufreal;
    LONG ioerr;
    BOOL firstpkt = TRUE;

    if(nch = nAllocHid())
    {
        Forbid();
        if(nch->nch_ReadySigTask)
        {
            Signal(nch->nch_ReadySigTask, 1L<<nch->nch_ReadySignal);
        }
        Permit();
        sigmask = (1L<<nch->nch_TaskMsgPort->mp_SigBit)|SIGBREAKF_CTRL_C;
        bufreal = buf = nch->nch_EP1Buf;
        psdSendPipe(nch->nch_EP1Pipe, buf, nch->nch_EP1PktSize);
        do
        {
            sigs = Wait(sigmask);
            while(pp = (struct PsdPipe *) GetMsg(nch->nch_TaskMsgPort))
            {
                if(pp == nch->nch_EP1Pipe)
                {
                    if(!(ioerr = psdGetPipeError(pp)))
                    {
                        if(firstpkt)
                        {
                            if(*buf == 0x01)
                            {
                                bufreal++;
                            }
                            firstpkt = 0;
                        }
                        KPRINTF(1, ("Data: %08lx %08lx\n", (*(ULONG *) bufreal), ((ULONG *) bufreal)[1]));
                        newmouse = FALSE;
                        qualifier = IEQUALIFIER_RELATIVEMOUSE;
                        buts = bufreal[0];
                        iecode = wheeliecode = IECODE_NOBUTTON;
                        wheeldist = 0;
                        if(buts & 1)
                        {
                            qualifier |= IEQUALIFIER_LEFTBUTTON;
                        }
                        if(buts & 2)
                        {
                            qualifier |= IEQUALIFIER_RBUTTON;
                        }
                        if(buts & 4)
                        {
                            qualifier |= IEQUALIFIER_MIDBUTTON;
                        }
                        if(nch->nch_CDC->cdc_Wheelmouse)
                        {
                            wheel = ((BYTE *) bufreal)[3];
                            if(wheel != oldwheel)
                            {
                                if(oldwheel > 0)
                                {
                                    wheeliecode = NM_WHEEL_UP|IECODE_UP_PREFIX;
                                    newmouse = TRUE;
                                }
                                else if(oldwheel < 0)
                                {
                                    wheeliecode = NM_WHEEL_DOWN|IECODE_UP_PREFIX;
                                    newmouse = TRUE;
                                }
                                oldwheel = wheel;
                            }
                            if(wheel > 0)
                            {
                                wheeliecode = NM_WHEEL_UP;
                                wheeldist = wheel;
                                newmouse = TRUE;
                            }
                            else if(wheel < 0)
                            {
                                wheeliecode = NM_WHEEL_DOWN;
                                wheeldist = -wheel;
                                newmouse = TRUE;
                            }
                        }

                        if((buts^oldbuts) & 1)
                        {
                            iecode = (buts & 1) ? IECODE_LBUTTON : IECODE_LBUTTON|IECODE_UP_PREFIX;
                            oldbuts ^= 1;
                        }
                        else if((buts^oldbuts) & 2)
                        {
                            iecode = (buts & 2) ? IECODE_RBUTTON : IECODE_RBUTTON|IECODE_UP_PREFIX;
                            oldbuts ^= 2;
                        }
                        else if((buts^oldbuts) & 4)
                        {
                            iecode = (buts & 4) ? IECODE_MBUTTON : IECODE_MBUTTON|IECODE_UP_PREFIX;
                            oldbuts ^= 4;
                        }
                        nch->nch_FakeEvent.ie_X = ((BYTE *) bufreal)[1];
                        nch->nch_FakeEvent.ie_Y = ((BYTE *) bufreal)[2];
                        nch->nch_FakeEvent.ie_Class = IECLASS_RAWMOUSE;
                        nch->nch_FakeEvent.ie_SubClass = 0;
                        nch->nch_FakeEvent.ie_Code = iecode;
                        nch->nch_FakeEvent.ie_NextEvent = NULL;
                        nch->nch_FakeEvent.ie_Qualifier = qualifier;
                        nch->nch_InpIOReq->io_Data = &nch->nch_FakeEvent;
                        nch->nch_InpIOReq->io_Length = sizeof(struct InputEvent);
                        nch->nch_InpIOReq->io_Command = IND_WRITEEVENT;
                        DoIO((struct IORequest *) nch->nch_InpIOReq);
                        if(newmouse)
                        {
                            while(wheeldist--)
                            {
                                KPRINTF(1, ("Doing wheel %ld\n", wheel));
                                nch->nch_FakeEvent.ie_Class = IECLASS_RAWKEY;
                                nch->nch_FakeEvent.ie_SubClass = 0;
                                nch->nch_FakeEvent.ie_Code = wheeliecode;
                                nch->nch_FakeEvent.ie_NextEvent = NULL;
                                nch->nch_FakeEvent.ie_Qualifier = qualifier;
                                nch->nch_InpIOReq->io_Data = &nch->nch_FakeEvent;
                                nch->nch_InpIOReq->io_Length = sizeof(struct InputEvent);
                                nch->nch_InpIOReq->io_Command = IND_WRITEEVENT;
                                DoIO((struct IORequest *) nch->nch_InpIOReq);

                                nch->nch_FakeEvent.ie_Class = IECLASS_NEWMOUSE;
                                nch->nch_FakeEvent.ie_SubClass = 0;
                                nch->nch_FakeEvent.ie_Code = wheeliecode;
                                nch->nch_FakeEvent.ie_NextEvent = NULL;
                                nch->nch_FakeEvent.ie_Qualifier = qualifier;
                                nch->nch_InpIOReq->io_Data = &nch->nch_FakeEvent;
                                nch->nch_InpIOReq->io_Length = sizeof(struct InputEvent);
                                nch->nch_InpIOReq->io_Command = IND_WRITEEVENT;
                                DoIO((struct IORequest *) nch->nch_InpIOReq);
                                }
                        }
                    } else {
                        KPRINTF(1, ("Int Pipe failed %ld\n", ioerr));
                        /*if(ioerr == UHIOERR_STALL)
                        {*/
                            psdPipeSetup(nch->nch_EP0Pipe, URTF_STANDARD|URTF_ENDPOINT,
                                         USR_CLEAR_FEATURE, UFS_ENDPOINT_HALT, (ULONG) 1|URTF_IN);
                            ioerr = psdDoPipe(nch->nch_EP0Pipe, NULL, 0);
                        //}
                        //nch->nch_EP1PktSize = 3;
                        /*{
                            APTR phw;
                            psdGetAttrs(PGA_DEVICE, nch->nch_Device,
                                        DA_Hardware, &phw,
                                        TAG_END);
                            psdEnumerateHardware(phw);
                        }*/
                        psdDelayMS(20);
                    }
                    psdSendPipe(nch->nch_EP1Pipe, buf, nch->nch_EP1PktSize);
                    break;
                }
            }
        } while(!(sigs & SIGBREAKF_CTRL_C));
        KPRINTF(20, ("Going down the river!\n"));
        psdAbortPipe(nch->nch_EP1Pipe);
        psdWaitPipe(nch->nch_EP1Pipe);
        nFreeHid(nch);
    }
}
/* \\\ */

/* /// "nAllocHid()" */
struct NepClassHid * nAllocHid(void)
{
    struct Task *thistask;
    struct NepClassHid *nch;
    LONG ioerr;

#undef SysBase
#define	SysBase	(*(struct Library **) (4L))
    thistask = FindTask(NULL);
#undef SysBase
#define	SysBase	nch->nch_SysBase
    nch = thistask->tc_UserData;
    do
    {
        if(!(nch->nch_Base = OpenLibrary("poseidon.library", 1)))
        {
            Alert(AG_OpenLib);
            break;
        }
        psdGetAttrs(PGA_INTERFACE, nch->nch_Interface,
                    IFA_Config, (ULONG) &nch->nch_Config,
                    IFA_InterfaceNum, (ULONG) &nch->nch_IfNum,
                    TAG_END);
        psdGetAttrs(PGA_CONFIG, nch->nch_Config,
                    CA_Device, (ULONG) &nch->nch_Device,
                    TAG_END);

        nch->nch_EP1 = psdFindEndpoint(nch->nch_Interface, NULL,
                                       EA_IsIn, TRUE,
                                       EA_TransferType, USEAF_INTERRUPT,
                                       TAG_END);
        if(!nch->nch_EP1)
        {
            KPRINTF(1, ("Ooops!?! No Endpoints defined?\n"));
            break;
        }
        psdGetAttrs(PGA_ENDPOINT, nch->nch_EP1,
                    EA_MaxPktSize, (ULONG) &nch->nch_EP1PktSize,
                    TAG_END);
        if(nch->nch_InpMsgPort = CreateMsgPort())
        {
            if(nch->nch_InpIOReq = (struct IOStdReq *) CreateIORequest(nch->nch_InpMsgPort, sizeof(struct IOStdReq)))
            {
                if(!OpenDevice("input.device", 0, (struct IORequest *) nch->nch_InpIOReq, 0))
                {
                    if(nch->nch_TaskMsgPort = CreateMsgPort())
                    {
                        if(nch->nch_EP0Pipe = psdAllocPipe(nch->nch_Device, nch->nch_TaskMsgPort, NULL))
                        {
                            if(nch->nch_EP1Pipe = psdAllocPipe(nch->nch_Device, nch->nch_TaskMsgPort, nch->nch_EP1))
                            {
                                psdPipeSetup(nch->nch_EP0Pipe, URTF_CLASS|URTF_INTERFACE,
                                             UHR_SET_PROTOCOL, HID_PROTO_BOOT, nch->nch_IfNum);
                                ioerr = psdDoPipe(nch->nch_EP0Pipe, NULL, 0);
                                if(!ioerr)
                                {
                                    psdPipeSetup(nch->nch_EP0Pipe, URTF_CLASS|URTF_INTERFACE,
                                                 UHR_SET_IDLE, 0, nch->nch_IfNum);
                                    ioerr = psdDoPipe(nch->nch_EP0Pipe, NULL, 0);
                                    if(ioerr)
                                    {
                                        psdAddErrorMsg(RETURN_WARN, (STRPTR) libname,
                                                       "SET_IDLE=0 failed: %s (%ld)!",
                                                       psdNumToStr(NTS_IOERR, ioerr, "unknown"), ioerr);
                                    }
                                    if(nch->nch_EP1Buf = psdAllocVec(nch->nch_EP1PktSize))
                                    {
                                        psdSetAttrs(PGA_PIPE, nch->nch_EP1Pipe,
                                                    PPA_AllowRuntPackets, TRUE,
                                                    TAG_END);
                                        nch->nch_Task = thistask;
                                        return(nch);
                                    }
                                } else {
                                    psdAddErrorMsg(RETURN_FAIL, (STRPTR) libname,
                                                   "SET_PROTOCOL=BOOT failed: %s (%ld)!",
                                                   psdNumToStr(NTS_IOERR, ioerr, "unknown"), ioerr);
                                }
                                psdFreePipe(nch->nch_EP1Pipe);
                            }
                            psdFreePipe(nch->nch_EP0Pipe);
                        }
                        DeleteMsgPort(nch->nch_TaskMsgPort);
                    }
                    CloseDevice((struct IORequest *) nch->nch_InpIOReq);
                }
                DeleteIORequest(nch->nch_InpIOReq);
            }
            DeleteMsgPort(nch->nch_InpMsgPort);
        }
    } while(FALSE);
    CloseLibrary(nch->nch_Base);
    Forbid();
    nch->nch_Task = NULL;
    if(nch->nch_ReadySigTask)
    {
        Signal(nch->nch_ReadySigTask, 1L<<nch->nch_ReadySignal);
    }
    return(NULL);
}
/* \\\ */

/* /// "nFreeHid()" */
void nFreeHid(struct NepClassHid *nch)
{
    psdFreeVec(nch->nch_EP1Buf);
    psdFreePipe(nch->nch_EP1Pipe);
    psdFreePipe(nch->nch_EP0Pipe);
    DeleteMsgPort(nch->nch_TaskMsgPort);
    CloseDevice((struct IORequest *) nch->nch_InpIOReq);
    DeleteIORequest(nch->nch_InpIOReq);
    DeleteMsgPort(nch->nch_InpMsgPort);
    CloseLibrary(nch->nch_Base);
    Forbid();
    nch->nch_Task = NULL;
    if(nch->nch_ReadySigTask)
    {
        Signal(nch->nch_ReadySigTask, 1L<<nch->nch_ReadySignal);
    }
}
/* \\\ */

/**************************************************************************/

#undef SysBase
#define	SysBase	nh->nh_SysBase
#undef PsdBase

#ifdef __MORPHOS__
struct Library *MUIMasterBase = NULL;
#endif

/* /// "nOpenBindingCfgWindow()" */
LONG nOpenBindingCfgWindow(struct NepHidBase *nh, struct NepClassHid *nch)
{
    struct Library *PsdBase;
    KPRINTF(10, ("Opening GUI...\n"));
    if(!(PsdBase = OpenLibrary("poseidon.library", 1)))
    {
        return(FALSE);
    }
    Forbid();
    if(!nch->nch_GUITask)
    {
#ifndef __MORPHOS__
        if(nch->nch_GUITask = psdSpawnSubTask(LIBNAME " GUI", nGUITask, nch))
#else
        if(nch->nch_GUITask = psdSpawnSubTask(LIBNAME " GUI", &nGUITask, nch))
#endif
        {
            Permit();
            CloseLibrary(PsdBase);
            return(TRUE);
        }
    }
    Permit();
    CloseLibrary(PsdBase);
    return(FALSE);
}
/* \\\ */

/* /// "nGUITask()" */
void DECLFUNC_0(nGUITask)
{
    struct Task *thistask;
    struct NepHidBase *nh;
    struct NepClassHid *nch;
    APTR pic;

#undef SysBase
#define	SysBase	(*(struct Library **) (4L))
    thistask = FindTask(NULL);
#undef SysBase
#define	SysBase	nch->nch_SysBase
#undef PsdBase
#define PsdBase nch->nch_PsdBase
#undef IntuitionBase
#define IntuitionBase nch->nch_IntBase
#ifndef __MORPHOS__
#undef MUIMasterBase
#define MUIMasterBase nch->nch_MUIBase
#endif

    nch = thistask->tc_UserData;
    nh = nch->nch_ClsBase;

    ++nh->nh_Library.lib_OpenCnt;
    if(!(MUIMasterBase = OpenLibrary(MUIMASTER_NAME, MUIMASTER_VMIN)))
    {
        KPRINTF(10, ("Couldn't open muimaster.library.\n"));
        nGUITaskCleanup(nch);
        return;
    }

    if(!(IntuitionBase = OpenLibrary("intuition.library", 39)))
    {
        KPRINTF(10, ("Couldn't open intuition.library.\n"));
        nGUITaskCleanup(nch);
        return;
    }
    if(!(PsdBase = OpenLibrary("poseidon.library", 1)))
    {
        KPRINTF(10, ("Couldn't open poseidon.library.\n"));
        nGUITaskCleanup(nch);
        return;
    }

    nch->nch_App = ApplicationObject,
        MUIA_Application_Title      , VERS,
        MUIA_Application_Version    , VSTRING,
        MUIA_Application_Copyright  , "©2002 Chris Hodges",
        MUIA_Application_Author     , "Chris Hodges <hodges@in.tum.de>",
        MUIA_Application_Description, "Settings for the bootmouse.class",
        MUIA_Application_Base       , "BOOTMOUSE",
        MUIA_Application_HelpFile   , "HELP:Poseidon.guide",
        MUIA_Application_Menustrip  , MenustripObject,
            Child, MenuObjectT("Project"),
                Child, nch->nch_AboutMI = MenuitemObject,
                    MUIA_Menuitem_Title, "About...",
                    MUIA_Menuitem_Shortcut, "?",
                    End,
                End,
            Child, MenuObjectT("Settings"),
                Child, nch->nch_UseMI = MenuitemObject,
                    MUIA_Menuitem_Title, "Use",
                    MUIA_Menuitem_Shortcut, "U",
                    End,
                Child, nch->nch_SetDefaultMI = MenuitemObject,
                    MUIA_Menuitem_Title, "Set as Default",
                    MUIA_Menuitem_Shortcut, "D",
                    End,
                Child, MenuitemObject,
                    MUIA_Menuitem_Title, NM_BARLABEL,
                    End,
                Child, nch->nch_MUIPrefsMI = MenuitemObject,
                    MUIA_Menuitem_Title, "MUI Settings",
                    MUIA_Menuitem_Shortcut, "M",
                    End,
                End,
            End,

        SubWindow, nch->nch_MainWindow = WindowObject,
            MUIA_Window_ID   , MAKE_ID('M','A','I','N'),
            MUIA_Window_Title, VERS,
            MUIA_HelpNode, LIBNAME,

            WindowContents, VGroup,
                Child, HGroup, GroupFrameT(nch->nch_Interface ? "Device Settings" : "Default Device Settings"),
                    Child, HSpace(0),
                    Child, ColGroup(2),
                        Child, Label("Experimental Wheelmouse support:"),
                        Child, HGroup,
                            Child, nch->nch_WheelmouseObj = ImageObject, ImageButtonFrame,
                                MUIA_Background, MUII_ButtonBack,
                                MUIA_CycleChain, 1,
                                MUIA_InputMode, MUIV_InputMode_Toggle,
                                MUIA_Image_Spec, MUII_CheckMark,
                                MUIA_Image_FreeVert, TRUE,
                                MUIA_Selected, nch->nch_CDC->cdc_Wheelmouse,
                                MUIA_ShowSelState, FALSE,
                                End,
                            Child, HSpace(0),
                            End,
                        End,
                    Child, HSpace(0),
                    End,
                Child, VSpace(0),
                Child, HGroup,
                    MUIA_Group_SameWidth, TRUE,
                    Child, nch->nch_UseObj = TextObject, ButtonFrame,
                        MUIA_ShowMe, nch->nch_Interface,
                        MUIA_Background, MUII_ButtonBack,
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Text_Contents, "\33c Use ",
                        End,
                    Child, nch->nch_SetDefaultObj = TextObject, ButtonFrame,
                        MUIA_Background, MUII_ButtonBack,
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Text_Contents, nch->nch_Interface ? "\33c Use & Set as Default " : "\33c Use as Default",
                        End,
                    Child, nch->nch_CloseObj = TextObject, ButtonFrame,
                        MUIA_Background, MUII_ButtonBack,
                        MUIA_InputMode, MUIV_InputMode_RelVerify,
                        MUIA_Text_Contents, "\33c Close ",
                        End,
                    End,
                End,
            End,
        End;

    if(!nch->nch_App)
    {
        KPRINTF(10, ("Couldn't create application\n"));
        nGUITaskCleanup(nch);
        return;
    }

    DoMethod(nch->nch_MainWindow, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
             nch->nch_App, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);
    DoMethod(nch->nch_UseObj, MUIM_Notify, MUIA_Pressed, FALSE,
             nch->nch_App, 2, MUIM_Application_ReturnID, ID_STORE_CONFIG);
    DoMethod(nch->nch_SetDefaultObj, MUIM_Notify, MUIA_Pressed, FALSE,
             nch->nch_App, 2, MUIM_Application_ReturnID, ID_DEF_CONFIG);
    DoMethod(nch->nch_CloseObj, MUIM_Notify, MUIA_Pressed, FALSE,
             nch->nch_App, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

    DoMethod(nch->nch_AboutMI, MUIM_Notify, MUIA_Menuitem_Trigger, MUIV_EveryTime,
             nch->nch_App, 2, MUIM_Application_ReturnID, ID_ABOUT);
    DoMethod(nch->nch_UseMI, MUIM_Notify, MUIA_Menuitem_Trigger, MUIV_EveryTime,
             nch->nch_App, 2, MUIM_Application_ReturnID, ID_STORE_CONFIG);
    DoMethod(nch->nch_SetDefaultMI, MUIM_Notify, MUIA_Menuitem_Trigger, MUIV_EveryTime,
             nch->nch_App, 2, MUIM_Application_ReturnID, ID_DEF_CONFIG);
    DoMethod(nch->nch_MUIPrefsMI, MUIM_Notify, MUIA_Menuitem_Trigger, MUIV_EveryTime,
             nch->nch_App, 2, MUIM_Application_OpenConfigWindow, 0);
    {
        ULONG isopen;
        ULONG iconify;
        ULONG sigs;
        ULONG sigmask;
        LONG retid;

        get(nch->nch_App, MUIA_Application_Iconified, &iconify);
        set(nch->nch_MainWindow, MUIA_Window_Open, TRUE);
        get(nch->nch_MainWindow, MUIA_Window_Open, &isopen);
        if(!(isopen || iconify))
        {
            nGUITaskCleanup(nch);
            return;
        }
        sigmask = 0;
        do
        {
            retid = DoMethod(nch->nch_App, MUIM_Application_NewInput, &sigs);
            switch(retid)
            {
                case ID_DEF_CONFIG:
                case ID_STORE_CONFIG:
                {
                    get(nch->nch_WheelmouseObj, MUIA_Selected, &nch->nch_CDC->cdc_Wheelmouse);

                    Forbid();
                    if(retid == ID_DEF_CONFIG)
                    {
                        pic = psdGetClsCfg(LIBNAME);
                        if(!pic)
                        {
                            psdSetClsCfg(LIBNAME, NULL);
                            pic = psdGetClsCfg(LIBNAME);
                        }
                        if(pic)
                        {
                            psdAddCfgEntry(pic, nch->nch_CDC);
                        }
                    }
                    if(nch->nch_Interface)
                    {
                        pic = psdGetUsbDevCfg(LIBNAME, nch->nch_DevIDString, nch->nch_IfIDString);
                        if(!pic)
                        {
                            psdSetUsbDevCfg(LIBNAME, nch->nch_DevIDString, nch->nch_IfIDString, NULL);
                            pic = psdGetUsbDevCfg(LIBNAME, nch->nch_DevIDString, nch->nch_IfIDString);
                        }
                        if(pic)
                        {
                            psdAddCfgEntry(pic, nch->nch_CDC);
                            retid = MUIV_Application_ReturnID_Quit;
                        }
                    } else {
                        retid = MUIV_Application_ReturnID_Quit;
                    }
                    Permit();
                    break;
                }

                case ID_ABOUT:
                    MUI_Request(nch->nch_App, nch->nch_MainWindow, 0, NULL, "Blimey!", VSTRING);
                    break;
            }
            if(retid == MUIV_Application_ReturnID_Quit)
            {
                break;
            }
            if(sigs)
            {
                sigs = Wait(sigs | sigmask | SIGBREAKF_CTRL_C);
                if(sigs & SIGBREAKF_CTRL_C)
                {
                    break;
                }
            }
        } while(TRUE);
        set(nch->nch_MainWindow, MUIA_Window_Open, FALSE);
    }
    nGUITaskCleanup(nch);
}
/* \\\ */

/* /// "nGUITaskCleanup()" */
void nGUITaskCleanup(struct NepClassHid *nch)
{
    if(MUIMasterBase)
    {
        CloseLibrary(MUIMasterBase);
        MUIMasterBase = NULL;
    }
    if(IntuitionBase)
    {
        CloseLibrary(IntuitionBase);
        IntuitionBase = NULL;
    }
    if(PsdBase)
    {
        CloseLibrary(PsdBase);
        PsdBase = NULL;
    }
    Forbid();
    nch->nch_GUIBinding = NULL;
    nch->nch_GUITask = NULL;
    if(nch->nch_ReadySigTask)
    {
        Signal(nch->nch_ReadySigTask, 1L<<nch->nch_ReadySignal);
    }
    --nch->nch_ClsBase->nh_Library.lib_OpenCnt;
}
/* \\\ */

