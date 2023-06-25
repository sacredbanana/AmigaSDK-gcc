#ifndef DEVICES_CONUNIT_H
#define DEVICES_CONUNIT_H
/*
** $VER: conunit.h 54.16 (22.08.2022)
**
** Console device unit definitions
**
** Copyright (C) 1985-2009 Hyperion Entertainment CVBA.
** All Rights Reserved
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef   DEVICES_CONSOLE_H
#include <devices/console.h>
#endif

#ifndef   LIBRARIES_KEYMAP_H
#include <libraries/keymap.h>
#endif

#ifndef   DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/* ---- console unit numbers for OpenDevice() */
#define CONU_LIBRARY  -1 /* no unit, just fill in IO_DEVICE field */
#define CONU_STANDARD  0 /* standard unmapped console */

/* ---- New unit numbers for OpenDevice() - (V36) */

#define CONU_CHARMAP 1 /* bind character map to console */
#define CONU_SNIPMAP 3 /* bind character map w/ snip to console */
#define	CONU_HISTORY 4 /* SNIPMAP + history (V53.20) */

/* ---- New flag defines for OpenDevice() - (V37) */
#define CONFLAG_DEFAULT				0x00
#define CONFLAG_NODRAW_ON_NEWSIZE	0x01
/* ---- New flag defines for OpenDevice() - (V53.20) */
#define	CONFLAG_CREATE_WINDOW		0x04
#define	CONFLAG_TABBED_WINDOW		0x08
#define	CONFLAG_SYNC_WRITES			0x10

#define PMB_LNM M_LNM              /* internal storage bit for NL flag */
#define PMF_LNM (1<<(M_LNM&7))     /* bit value in that byte           */
#define PMB_ASM (M_LNM+1)          /* internal storage bit for AS flag */
#define PMF_ASM (1<<((M_LNM+1)&7)) /* bit value in that byte           */
#define PMB_AWM (PMB_ASM+1)        /* internal storage bit for AW flag */
#define PMF_AWM (1<<((M_LNM+2)&7)) /* bit value in that byte           */

#define MAXTABS 80


struct ConUnit
{
//	These variables are provided READ ONLY and are copies of the actual
//	variables. Any new values written to them will be ignored (V53.20).
    struct  MsgPort cu_MP;
    /* ---- read only variables */
    struct  Window *cu_Window; /* intuition window bound to this unit */
    WORD    cu_XCP;            /* text entry position */
    WORD    cu_YCP;
    WORD    cu_XMax;           /* max character position */
    WORD    cu_YMax;
    WORD    cu_XRSize;         /* character raster size */
    WORD    cu_YRSize;
    WORD    cu_XROrigin;       /* raster origin */
    WORD    cu_YROrigin;
    WORD    cu_XRExtant;       /* raster maxima */
    WORD    cu_YRExtant;
    WORD    cu_XMinShrink;     /* smallest area intact from resize process */
    WORD    cu_YMinShrink;
    WORD    cu_XCCP;           /* cursor position saved for later erasure */
    WORD    cu_YCCP;

    struct  KeyMap cu_PrivateKeyMapStruct; /* Private and obsolete */

/*	Variables below this point are private. Their contents are not guaranteed
**	and any values written into them are ignored (V53.20).
*/
    UWORD   cu_TabStops[MAXTABS]; /* 0 at start, 0xffff at end of list */

    /* ---- console rastport attributes */
    BYTE    cu_Mask;
    BYTE    cu_FgPen;
    BYTE    cu_BgPen;
    BYTE    cu_AOLPen;
    BYTE    cu_DrawMode;
    BYTE    cu_Obsolete1;   /* was cu_AreaPtSz -- not used in V36 */
    APTR    cu_Obsolete2;   /* was cu_AreaPtrn -- not used in V36 */
    UBYTE   cu_Minterms[8]; /* console minterms */
    struct  TextFont *cu_Font;
    UBYTE   cu_AlgoStyle;
    UBYTE   cu_TxFlags;
    UWORD   cu_TxHeight;
    UWORD   cu_TxWidth;
    UWORD   cu_TxBaseline;
    WORD    cu_TxSpacing;

    /* ---- console MODES and RAW EVENTS switches */
    UBYTE   cu_Modes[(PMB_AWM+7)/8]; /* one bit per mode */
    UBYTE   cu_RawEvents[(IECLASS_MAX+8)/8];
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* DEVICES_CONUNIT_H */
