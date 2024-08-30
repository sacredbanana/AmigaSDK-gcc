/*
 * C language library code by TetiSoft@apg.lahn.de (Detlef Würkner)
 */

/*-------------------------------------------------------------------------*/
/*                         constant part                                   */
/*-------------------------------------------------------------------------*/

/* includes */

#include <exec/types.h>
#include <exec/resident.h>
#include <exec/execbase.h>
#include <libraries/locale.h>
#include <dos/dos.h> /* BPTR */
#define __USE_SYSBASE
#define __NOLIBBASE__
#define __NOGLOBALIFACE__
#define __USE_INLINE__
#include <proto/exec.h>

#include <internal/languagedrivers.h>
#ifdef __amigaos4__
#include <internal/interfaces/language.h>
#endif

/* structures and defines */

struct DriverBase
{
    struct Library    db_Library;
    UWORD             db_Pad;
    BPTR              db_Segment;
    struct ExecBase  *db_SysBase;
#ifdef __amigaos4__
    struct ExecIFace *db_IExec;
#endif
};

#ifndef __amigaos4__
struct LibInitStruct
{
    ULONG                   LibSize;
    CONST APTR             *FuncInitTable;
    CONST APTR              StructInitTable;
    struct Library * (* ASM LibInitFunc)(REG(d0, struct DriverBase *),
                                         REG(a0, BPTR),
                                         REG(a6, struct ExecBase *));
};
#endif

#define LIBPRIORITY -100

#ifdef __amigaos4__
#define BASE_OR_IFACE_PARAM  struct LanguageIFace           *li
#define BASE_OR_MIFACE_PARAM struct LibraryManagerInterface *lmi
#define BASE_OR_MIFACE_ARG                                   lmi
#define FETCHBASE            struct DriverBase              *db = (struct DriverBase *)li->Data.LibBase;
#define FETCHBASEM           struct DriverBase              *db = (struct DriverBase *)lmi->Data.LibBase;
#define FETCHEXEC            struct ExecIFace               *IExec = db->db_IExec;
#else
#define BASE_OR_IFACE_PARAM  struct DriverBase              *db
#define BASE_OR_MIFACE_PARAM struct DriverBase              *db
#define BASE_OR_MIFACE_ARG                                   db
#define FETCHBASE
#define FETCHBASEM
#define FETCHEXEC            struct ExecBase                *SysBase = db->db_SysBase;
#endif

/* forward declarations */

#ifndef __amigaos4__
STATIC CONST struct LibInitStruct LibInitTable;
#endif

STATIC CONST CONST_APTR           LibFuncTable[];
STATIC CONST CONST_STRPTR         StringTable[MAXSTRMSG];

STATIC struct Library * ASM LIB_Init         (REG(d0, struct DriverBase *),
                                              REG(a0, BPTR),
#ifdef __amigaos4__
                                              struct ExecIFace *);
#else
                                              REG(a6, struct ExecBase *));
#endif
#ifdef __amigaos4__
STATIC struct Library *     LIB_Open         (struct LibraryManagerInterface *,
                                              ULONG);
#else
STATIC struct Library * ASM LIB_Open         (REG(a6, struct DriverBase *));
#endif
STATIC BPTR             ASM LIB_Close        (REG(a6, BASE_OR_MIFACE_PARAM));
STATIC BPTR             ASM LIB_Expunge      (REG(a6, BASE_OR_MIFACE_PARAM));
#ifndef __amigaos4__
STATIC LONG             ASM LIB_ExtFunc      (VOID);
#endif
STATIC LONG             ASM LIB_Reserved     (VOID);
STATIC ULONG            ASM LIB_GetDriverInfo(REG(a6, BASE_OR_IFACE_PARAM));
STATIC ULONG            ASM LIB_GetCodeSet   (REG(a6, BASE_OR_IFACE_PARAM));
STATIC CONST_STRPTR     ASM LIB_GetLocaleStr (REG(a6, BASE_OR_IFACE_PARAM),
                                              REG(d0, ULONG));

/*-------------------------------------------------------------------------*/

#ifdef __amigaos4__

STATIC ULONG defaultObtain(struct Interface *Self)
{
    return Self->Data.RefCount++;
}


STATIC ULONG defaultRelease(struct Interface *Self)
{
    return Self->Data.RefCount--;
}

STATIC CONST CONST_APTR manager_vectors[] =
{
    defaultObtain,
    defaultRelease,
    NULL,
    NULL,
    LIB_Open,
    LIB_Close,
    LIB_Expunge,
    NULL,
    (CONST_APTR)-1
};

STATIC CONST struct TagItem managerTags[] =
{
    { MIT_Name,        (ULONG)"__library"     },
    { MIT_VectorTable, (ULONG)manager_vectors },
    { MIT_Version,     1                      },
    { TAG_END,         0                      }
};

STATIC CONST struct TagItem mainTags[] =
{
    { MIT_Name,        (ULONG)"main"       },
    { MIT_VectorTable, (ULONG)LibFuncTable },
    { MIT_Version,     1                   },
    { TAG_END,         0                   }
};

STATIC CONST CONST_APTR libInterfaces[] =
{
    managerTags,
    mainTags,
    NULL
};

#ifdef VECTABLE_68K
extern VOID * VecTable68K[]; /* language_68k.S */
#endif

STATIC CONST struct TagItem LibCreateTags[] =
{
    { CLT_DataSize,      sizeof(struct DriverBase) },
    { CLT_InitFunc,      (ULONG)LIB_Init           },
    { CLT_Interfaces,    (ULONG)libInterfaces      },
#ifdef VECTABLE_68K
    { CLT_Vector68K,     (ULONG)VecTable68K        },
#else
    { CLT_NoLegacyIFace, TRUE                      },
#endif
    { TAG_END,           0                         }
};

#endif

/*-------------------------------------------------------------------------*/

/* Dont make this STATIC or gcc may optimize it away */
CONST struct Resident ROMTag =
{
    RTC_MATCHWORD,              /* word to match on (ILLEGAL)       */
    (struct Resident *)&ROMTag, /* pointer to the above             */
    (APTR)(&ROMTag + 1),        /* address to continue scan         */
#ifdef __amigaos4__
    RTF_AUTOINIT|RTF_NATIVE,    /* various tag flags                */
#else
    RTF_AUTOINIT,               /* various tag flags                */
#endif
    VERSION,                    /* release version number           */
    NT_LIBRARY,                 /* type of module (NT_XXXXXX)       */
    LIBPRIORITY,                /* initialization priority          */
    LIBNAME,                    /* pointer to node name             */
#ifdef __amigaos4__
    &"$VER: "VSTRING[6],        /* pointer to identification string */
    (APTR)&LibCreateTags        /* pointer to init tags             */
#else
    VSTRING,                    /* pointer to identification string */
    (APTR)&LibInitTable         /* pointer to init table            */
#endif
};

/*-------------------------------------------------------------------------*/

#ifndef __amigaos4__
STATIC CONST struct LibInitStruct LibInitTable =
{
    sizeof(struct DriverBase),
    LibFuncTable,
    NULL,
    &LIB_Init
};
#endif

/*-------------------------------------------------------------------------*/

STATIC CONST CONST_APTR LibFuncTable[] =
{
    /* standard functions */
#ifdef __amigaos4__
    &defaultObtain,
    &defaultRelease,
    NULL,
    NULL,
#else
    &LIB_Open,
    &LIB_Close,
    &LIB_Expunge,
    &LIB_ExtFunc,
#endif

    /* public functions */
    &LIB_GetDriverInfo,
    &LIB_Reserved,
    &LIB_Reserved,
    &LIB_GetCodeSet,
    &LIB_GetLocaleStr,
    &LIB_Reserved, // IsAlNum
    &LIB_Reserved, // IsAlpha
    &LIB_Reserved, // IsCntrl
    &LIB_Reserved, // IsDigit
    &LIB_Reserved, // IsGraph
    &LIB_Reserved, // IsLower
    &LIB_Reserved, // IsPrint
    &LIB_Reserved, // IsPunct
    &LIB_Reserved, // IsSpace
    &LIB_Reserved, // IsUpper
    &LIB_Reserved, // IsXDigit
    &LIB_Reserved, // StrConvert
    &LIB_Reserved, // StrnCmp
    &LIB_Reserved, // IsBlank

    /* end of list */
    (CONST_APTR)-1
};

/*-------------------------------------------------------------------------*/

/*
 * Library Init entry point called when library is first loaded in memory
 * On entry, D0 points to library base, A0 has lib seglist, A6 has SysBase
 * Returns 0 for failure or the library base for success.
 */

STATIC struct Library * ASM LIB_Init(REG(d0, struct DriverBase *db),
                                     REG(a0, BPTR Segment),
#ifdef __amigaos4__
                                     struct ExecIFace *IExec)
#else
                                     REG(a6, struct ExecBase *SysBase))
#endif
{
    /* Initialize the library */
    db->db_Segment                  = Segment;
#ifdef __amigaos4__
    db->db_IExec                    = IExec;
    db->db_SysBase                  = (struct ExecBase *)IExec->Data.LibBase;
#else
    db->db_SysBase                  = SysBase;
#endif
    db->db_Library.lib_Node.ln_Pri  = LIBPRIORITY;
    db->db_Library.lib_Node.ln_Type = NT_LIBRARY;
    db->db_Library.lib_Node.ln_Name = LIBNAME;
    db->db_Library.lib_Flags        = LIBF_SUMUSED|LIBF_CHANGED;
    db->db_Library.lib_Version      = VERSION;
    db->db_Library.lib_Revision     = REVISION;
    db->db_Library.lib_IdString     = VSTRING;

    /* all done, return library base */
    return &db->db_Library;
}

/*-------------------------------------------------------------------------*/

/*
 * Library open entry point called every OpenLibrary()
 * On entry, A6 has DriverBase, task switching is disabled
 * Returns 0 for failure, or DriverBase for success.
 */

#ifdef __amigaos4__
STATIC struct Library * LIB_Open(struct LibraryManagerInterface *lmi,
                                 ULONG version)
#else
STATIC struct Library * ASM LIB_Open(REG(a6, struct DriverBase *db))
#endif
{
#ifdef __amigaos4__
    FETCHBASEM

    if (version > VERSION)
    {
        return NULL;
    }
#endif
    db->db_Library.lib_OpenCnt++;
    db->db_Library.lib_Flags &= ~LIBF_DELEXP;
    return &db->db_Library;
}

/*-------------------------------------------------------------------------*/

/*
 * Library close entry point called every CloseLibrary()
 * On entry, A6 has DriverBase, task switching is disabled
 * Returns 0 normally, or the library seglist when lib should be expunged
 * due to delayed expunge bit being set
 */

STATIC BPTR ASM LIB_Close(REG(a6, BASE_OR_MIFACE_PARAM))
{
    FETCHBASEM

    db->db_Library.lib_OpenCnt--;

    /* if delayed expunge bit set, then try to get rid of the library */
    /* if no library users, then just remove the library */

    if ((db->db_Library.lib_Flags & LIBF_DELEXP) && !db->db_Library.lib_OpenCnt)
    {
        return LIB_Expunge(BASE_OR_MIFACE_ARG);
    }

    /* still some library users, so just return */
    return ZERO;
}

/*-------------------------------------------------------------------------*/

/*
 * Library expunge entry point called whenever system memory is lacking
 * On entry, A6 has DriverBase, task switching is disabled
 * Returns the library seglist if the library open count is 0, returns 0
 * otherwise and sets the delayed expunge bit.
 */

STATIC BPTR ASM LIB_Expunge(REG(a6, BASE_OR_MIFACE_PARAM))
{
    FETCHBASEM
    FETCHEXEC
    BPTR Segment;

    if (db->db_Library.lib_OpenCnt)
    {
        db->db_Library.lib_Flags |= LIBF_DELEXP;
        return ZERO;
    }
    Remove(&db->db_Library.lib_Node);
    Segment = db->db_Segment;
#ifdef __amigaos4__
    DeleteLibrary(&db->db_Library);
#else
    FreeMem((APTR)((ULONG)db - db->db_Library.lib_NegSize),
            db->db_Library.lib_NegSize + db->db_Library.lib_PosSize);
#endif
    return Segment;
}

/*-------------------------------------------------------------------------*/

#ifndef __amigaos4__

STATIC LONG ASM LIB_ExtFunc(VOID)
{
    return 0;
}

#endif

/*-------------------------------------------------------------------------*/

STATIC LONG ASM LIB_Reserved(VOID)
{
    return 0;
}

/*-------------------------------------------------------------------------*/
/* All following functions DONT get their library base in A6               */
/* when called from locale.library versions prior to V47                   */
/*-------------------------------------------------------------------------*/

#ifdef __amigaos4__
#define UNUSEDBI li = li;
#else
#define UNUSEDBI db = db;
#endif

STATIC ULONG ASM LIB_GetDriverInfo(REG(a6, BASE_OR_IFACE_PARAM))
{
    UNUSEDBI
    return GDIF_GETCODESET|GDIF_GETLOCALESTR;
}

/*-------------------------------------------------------------------------*/

STATIC ULONG ASM LIB_GetCodeSet(REG(a6, BASE_OR_IFACE_PARAM))
{
    UNUSEDBI
    return CODESET;
}

/*-------------------------------------------------------------------------*/

STATIC CONST_STRPTR ASM LIB_GetLocaleStr(REG(a6, BASE_OR_IFACE_PARAM),
                                         REG(d0, ULONG stringNum))
{
    UNUSEDBI
    if (stringNum >= MAXSTRMSG)
    {
        return NULL;
    }
    return StringTable[stringNum];
}

/*-------------------------------------------------------------------------*/

STATIC CONST CONST_STRPTR StringTable[MAXSTRMSG] =
{
    GLS_CODE,

    GLS_DAY_1,
    GLS_DAY_2,
    GLS_DAY_3,
    GLS_DAY_4,
    GLS_DAY_5,
    GLS_DAY_6,
    GLS_DAY_7,

    GLS_ABDAY_1,
    GLS_ABDAY_2,
    GLS_ABDAY_3,
    GLS_ABDAY_4,
    GLS_ABDAY_5,
    GLS_ABDAY_6,
    GLS_ABDAY_7,

    GLS_MON_1,
    GLS_MON_2,
    GLS_MON_3,
    GLS_MON_4,
    GLS_MON_5,
    GLS_MON_6,
    GLS_MON_7,
    GLS_MON_8,
    GLS_MON_9,
    GLS_MON_10,
    GLS_MON_11,
    GLS_MON_12,

    GLS_ABMON_1,
    GLS_ABMON_2,
    GLS_ABMON_3,
    GLS_ABMON_4,
    GLS_ABMON_5,
    GLS_ABMON_6,
    GLS_ABMON_7,
    GLS_ABMON_8,
    GLS_ABMON_9,
    GLS_ABMON_10,
    GLS_ABMON_11,
    GLS_ABMON_12,

    GLS_YESSTR,
    GLS_NOSTR,

    GLS_AM_STR,
    GLS_PM_STR,

    GLS_SOFTHYPHEN,
    GLS_HARDHYPHEN,

    GLS_OPENQUOTE,
    GLS_CLOSEQUOTE,

    GLS_YESTERDAYSTR,
    GLS_TODAYSTR,
    GLS_TOMORROWSTR,
    GLS_FUTURESTR,

    GLS_LANGNAME,

    GLS_ALTDAY_1,
    GLS_ALTDAY_2,
    GLS_ALTDAY_3,
    GLS_ALTDAY_4,
    GLS_ALTDAY_5,
    GLS_ALTDAY_6,
    GLS_ALTDAY_7,

    GLS_ALTMON_1,
    GLS_ALTMON_2,
    GLS_ALTMON_3,
    GLS_ALTMON_4,
    GLS_ALTMON_5,
    GLS_ALTMON_6,
    GLS_ALTMON_7,
    GLS_ALTMON_8,
    GLS_ALTMON_9,
    GLS_ALTMON_10,
    GLS_ALTMON_11,
    GLS_ALTMON_12
};
