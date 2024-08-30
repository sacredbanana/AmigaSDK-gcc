#ifndef EXPANSION_CONFIGREGS_H
#define EXPANSION_CONFIGREGS_H
/*
**    $VER: configregs.h 53.29 (10.8.2015)
**
**    AutoConfig (tm) hardware register and bit definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#elif defined(__SASC)
   #pragma msg 79 ignore push
#endif

/****************************************************************************/

/*
** AutoConfig (tm) boards each contain a 32 byte "ExpansionRom" area that is
** read by the system software at configuration time.  Configuration of each
** board starts when the ConfigIn* signal is passed from the previous board
** (or from the system for the first board).  Each board will present it's
** ExpansionRom structure at location $00E80000 to be read by the system.
** This file defines the appearance of the ExpansionRom area.
**
** Expansion boards are actually organized such that only one nybble per
** 16 bit word contains valid information.  The low nybbles of each
** word are combined to fill the structure below. (This table is structured
** as LOGICAL information.  This means that it never corresponds exactly
** with a physical implementation.)
**
** The ExpansionRom space is further split into two regions:  The first 16
** bytes are read-only.  Except for the er_type field, this area is inverted
** by the system software when read in.  The second 16 bytes contain the
** control portion, where all read/write registers are located.
**
** The system builds one "ConfigDev" structure for each board found.  The
** list of boards can be examined using the expansion.library/FindConfigDev
** function.
**
** A special "hacker" Manufacturer ID number is reserved for test use:
** 2011 ($7DB).  When inverted this will look like $F824.
*/

struct ExpansionRom /* -First 16 bytes of the expansion ROM */
{
    UBYTE er_Type;         /* Board type, size and flags */
    UBYTE er_Product;      /* Product number, assigned by manufacturer */
    UBYTE er_Flags;        /* Flags */
    UBYTE er_Reserved03;   /* Must be zero ($ff inverted) */
    UWORD er_Manufacturer; /* Unique ID,ASSIGNED BY COMMODORE-AMIGA! */
    ULONG er_SerialNumber; /* Available for use by manufacturer */
    UWORD er_InitDiagVec;  /* Offset to optional "DiagArea" structure */
    UBYTE er_Reserved0c;
    UBYTE er_Reserved0d;
    UBYTE er_Reserved0e;
    UBYTE er_Reserved0f;
};


/*
** Note that use of the ec_BaseAddress register is tricky.  The system
** will actually write twice.  First the low order nybble is written
** to the ec_BaseAddress register+2 (D15-D12).  Then the entire byte is
** written to ec_BaseAddress (D15-D8).  This allows writing of a byte-wide
** address to nybble size registers.
*/

struct ExpansionControl /* -Second 16 bytes of the expansion ROM */
{
    UBYTE ec_Interrupt;   /* Optional interrupt control register */
    UBYTE ec_Z3_HighBase; /* Zorro III   : Config address bits 24-31 */
    UBYTE ec_BaseAddress; /* Zorro II/III: Config address bits 16-23 */
    UBYTE ec_Shutup;      /* The system writes here to shut up a board */
    UBYTE ec_Reserved14;
    UBYTE ec_Reserved15;
    UBYTE ec_Reserved16;
    UBYTE ec_Reserved17;
    UBYTE ec_Reserved18;
    UBYTE ec_Reserved19;
    UBYTE ec_Reserved1a;
    UBYTE ec_Reserved1b;
    UBYTE ec_Reserved1c;
    UBYTE ec_Reserved1d;
    UBYTE ec_Reserved1e;
    UBYTE ec_Reserved1f;
};

/*
** many of the constants below consist of a triplet of equivalent
** definitions: xxMASK is a bit mask of those bits that matter.
** xxBIT is the starting bit number of the field.  xxSIZE is the
** number of bits that make up the definition.    This method is
** used when the field is larger than one bit.
**
** If the field is only one bit wide then the xxB_xx and xxF_xx convention
** is used (xxB_xx is the bit number, and xxF_xx is mask of the bit).
*/

/* manifest constants */
enum enManifest
{
    E_SLOTSIZE  = 0x10000,
    E_SLOTMASK  = 0xffff,
    E_SLOTSHIFT = 16
};

/* these define the free regions of Zorro memory space.
** THESE MAY WELL CHANGE FOR FUTURE PRODUCTS!
** (Actually, they are not valid anymore except on classic hardware)
*/
#define E_EXPANSIONBASE     0x00e80000UL /* Zorro II  config address */
#define EZ3_EXPANSIONBASE   0xff000000UL /* Zorro III config address */

#define E_EXPANSIONSIZE     0x00080000UL /* Zorro II  I/O type cards */
#define E_EXPANSIONSLOTS    8UL

#define E_MEMORYBASE        0x00200000UL /* Zorro II  8MB space */
#define E_MEMORYSIZE        0x00800000UL
#define E_MEMORYSLOTS       128UL

#define EZ3_CONFIGAREA      0x40000000UL /* Zorro III space */
#define EZ3_CONFIGAREAEND   0x7FFFFFFFUL /* Zorro III space */
#define EZ3_SIZEGRANULARITY 0x00080000UL /* 512K increments */


/**** er_Type definitions (ttldcmmm) ***************************************/

/* er_Type board type bits -- the OS ignores "old style" boards */
enum enBoardType
{
    ERT_TYPEMASK = 0xc0,    /* Bits 7-6 */
    ERT_TYPEBIT  = 6,
    ERT_TYPESIZE = 2,
    ERT_NEWBOARD = 0xc0,
    ERT_ZORROII  = ERT_NEWBOARD,
    ERT_ZORROIII = 0x80
};

/* other bits defined in er_Type */
enum enOtherTypeBits
{
    ERTB_MEMLIST       = 5, /* Link RAM into free memory list */
    ERTB_DIAGVALID     = 4, /* ROM vector is valid */
    ERTB_CHAINEDCONFIG = 3  /* Next config is part of the same card */
};

enum enOtherTypeFlags
{
    ERTF_MEMLIST       = (1<<5),
    ERTF_DIAGVALID     = (1<<4),
    ERTF_CHAINEDCONFIG = (1<<3)
};

/* er_Type field memory size bits */
enum enMemSize
{
    ERT_MEMMASK = 0x07, /* Bits 2-0 */
    ERT_MEMBIT  = 0,
    ERT_MEMSIZE = 3
};


/**** er_Flags byte -- for those things that didn't fit into the type byte ****/
/**** the hardware stores this byte in inverted form                       ****/
enum enFlagBits
{
    ERFB_MEMSPACE  = 7,
    ERFB_NOSHUTUP  = 6,
    ERFB_EXTENDED  = 5,
    ERFB_ZORRO_III = 4
};


enum enFlags
{
    ERFF_MEMSPACE  = (1<<ERFB_MEMSPACE), /* Wants to be in 8 meg space. */
                                         /* (NOT IMPLEMENTED) */
    ERFF_NOSHUTUP  = (1<<ERFB_NOSHUTUP), /* Board can't be shut up */
    ERFF_EXTENDED  = (1<<ERFB_EXTENDED), /* Zorro III: Use extended size */
                                         /* table for bits 0-2 of er_Type */
                                         /* Zorro II : Must be 0 */

    ERFF_ZORRO_III = (1<<ERFB_ZORRO_III) /* Zorro III: must be 1 */
                                         /* Zorro II : must be 0 */
};

enum enSubSize
{
    ERT_Z3_SSMASK = 0x0F, /* Bits 3-0.  Zorro III Sub-Size.  How */
    ERT_Z3_SSBIT  = 0,    /* much space the card actually uses   */
    ERT_Z3_SSSIZE = 4     /* (regardless of config granularity)  */
                          /* Zorro II : must be 0                */
};

/* ec_Interrupt register (unused) ********************************************/
enum enECInterruptBits
{
    ECIB_INTENA       = 1,
    ECIB_RESET        = 3,
    ECIB_INT2PEND     = 4,
    ECIB_INT6PEND     = 5,
    ECIB_INT7PEND     = 6,
    ECIB_INTERRUPTING = 7
};

enum enECInterruptFlags
{
    ECIF_INTENA       = (1<<ECIB_INTENA),
    ECIF_RESET        = (1<<ECIB_RESET),
    ECIF_INT2PEND     = (1<<ECIB_INT2PEND),
    ECIF_INT6PEND     = (1<<ECIB_INT6PEND),
    ECIF_INT7PEND     = (1<<ECIB_INT7PEND),
    ECIF_INTERRUPTING = (1<<ECIB_INTERRUPTING)
};

/* figure out amount of memory needed by this box/board */
#define ERT_MEMNEEDED(t) \
    (((t)&ERT_MEMMASK)? 0x10000 << (((t)&ERT_MEMMASK) -1) : 0x800000 )

/* same as ERT_MEMNEEDED, but return number of slots */
#define ERT_SLOTSNEEDED(t) \
    (((t)&ERT_MEMMASK)? 1 << (((t)&ERT_MEMMASK)-1) : 0x80 )

/* convert a expansion slot number into a memory address */
#define EC_MEMADDR(slot) ((slot) << (E_SLOTSHIFT) )

/* a kludge to get the byte offset of a structure */
#define EROFFSET(er) ((int)&((struct ExpansionRom *)0)->er)
#define ECOFFSET(ec) \
    (sizeof(struct ExpansionRom)+((int)&((struct ExpansionControl *)0)->ec))

/***************************************************************************
**
** these are the specifications for the diagnostic area.  If the Diagnostic
** Address Valid bit is set in the Board Type byte (the first byte in
** expansion space) then the Diag Init vector contains a valid offset.
**
** The Diag Init vector is actually a word offset from the base of the
** board.  The resulting address points to the base of the DiagArea
** structure.  The structure may be physically implemented either four,
** eight, or sixteen bits wide.  The code will be copied out into
** ram first before being called.
**
** The da_Size field, and both code offsets (da_DiagPoint and da_BootPoint)
** are offsets from the diag area AFTER it has been copied into ram, and
** "de-nibbleized" (if needed).  (In other words, the size is the size of
** the actual information, not how much address space is required to
** store it.)
**
** All bits are encoded with uninverted logic (e.g. 5 volts on the bus
** is a logic one).
**
** If your board is to make use of the boot facility then it must leave
** its config area available even after it has been configured.  Your
** boot vector will be called AFTER your board's final address has been
** set.
**
****************************************************************************/

struct DiagArea
{
    UBYTE da_Config;     /* see below for definitions */
    UBYTE da_Flags;      /* see below for definitions */
    UWORD da_Size;       /* the size (in bytes) of the total diag area */
    UWORD da_DiagPoint;  /* where to start for diagnostics, or zero */
    UWORD da_BootPoint;  /* where to start for booting */
    UWORD da_Name;       /* offset in diag area where a string */
                         /*   identifier can be found (or zero if no */
                         /*   identifier is present). */

    UWORD da_Reserved01; /* two words of reserved data.    must be zero. */
    UWORD da_Reserved02;
};

/* da_Config definitions */

/*
** DAC_BYTEWIDE can be simulated using DAC_NIBBLEWIDE.
*/
enum enDAConfig
{
    DAC_BUSWIDTH   = 0xC0, /* two bits for bus width */
    DAC_NIBBLEWIDE = 0x00,
    DAC_BYTEWIDE   = 0x40, /* BUG: Will not work under V34 Kickstart! */
    DAC_WORDWIDE   = 0x80,

    DAC_BOOTTIME   = 0x30, /* two bits for when to boot */
    DAC_NEVER      = 0x00, /* obvious */
    DAC_CONFIGTIME = 0x10, /* call da_BootPoint when first configing */
                           /*   the device */
    DAC_BINDTIME   = 0x20  /* run when binding drivers to boards */
};

/*
**
** These are the calling conventions for the diagnostic callback
** (from da_DiagPoint):
**
** A7 -- points to at least 2K of stack
** A6 -- ExecBase
** A5 -- ExpansionBase
** A3 -- your board's ConfigDev structure
** A2 -- Base of diag/init area that was copied
** A0 -- Base of your board
**
** Your board must return a value in D0.  If this value is NULL, then
** the diag/init area that was copied in will be returned to the free
** memory pool.
*/

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#elif defined(__SASC)
   #pragma msg 79 pop
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXPANSION_CONFIGREGS_H */
