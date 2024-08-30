#ifndef LIBRARIES_CONFIGREGS_H
#define LIBRARIES_CONFIGREGS_H

/*
	AutoConfig(TM) registers and bits

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


struct ExpansionRom
{
	UBYTE er_Type;
	UBYTE er_Product;
	UBYTE er_Flags;
	UBYTE er_Reserved03;
	UWORD er_Manufacturer;
	ULONG er_SerialNumber;
	UWORD er_InitDiagVec;
	UBYTE er_Reserved0c;
	UBYTE er_Reserved0d;
	UBYTE er_Reserved0e;
	UBYTE er_Reserved0f;
};


struct ExpansionControl
{
	UBYTE ec_Interrupt;
	UBYTE ec_Z3_HighBase;
	UBYTE ec_BaseAddress;
	UBYTE ec_Shutup;
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


#define E_SLOTSIZE   0x10000
#define E_SLOTMASK   0xffff
#define E_SLOTSHIFT  16


#define E_EXPANSIONBASE      0x00E80000
#define EZ3_EXPANSIONBASE    0xFF000000

#define E_EXPANSIONSIZE      0x00080000
#define E_EXPANSIONSLOTS     8

#define E_MEMORYBASE         0x00200000
#define E_MEMORYSIZE         0x00800000
#define E_MEMORYSLOTS        128

#define EZ3_CONFIGAREA       0x40000000
#define EZ3_CONFIGAREAEND    0x7FFFFFFF
#define EZ3_SIZEGRANULARITY  0x00080000


#define ERT_TYPEMASK        0xC0
#define ERT_TYPEBIT         6
#define ERT_TYPESIZE        2
#define ERT_NEWBOARD        0xC0
#define ERT_ZORROII         ERT_NEWBOARD
#define ERT_ZORROIII        0x80

#define ERTB_MEMLIST        5
#define ERTB_DIAGVALID      4
#define ERTB_CHAINEDCONFIG  3

#define ERTF_MEMLIST        (1<<ERTB_MEMLIST)
#define ERTF_DIAGVALID      (1<<ERTB_DIAGVALID)
#define ERTF_CHAINEDCONFIG  (1<<ERTB_CHAINEDCONFIG)

#define ERT_MEMMASK         0x07
#define ERT_MEMBIT          0
#define ERT_MEMSIZE         3


#define ERFB_MEMSPACE   7
#define ERFB_NOSHUTUP   6
#define ERFB_EXTENDED   5
#define ERFB_ZORRO_III  4

#define ERFF_MEMSPACE   (1<<ERFB_MEMSPACE)
#define ERFF_NOSHUTUP   (1<<ERFB_NOSHUTUP)
#define ERFF_EXTENDED   (1<<ERFB_EXTENDED)
#define ERFF_ZORRO_III  (1<<ERFB_ZORRO_III)

#define ERT_Z3_SSMASK   0x0F
#define ERT_Z3_SSBIT    0
#define ERT_Z3_SSSIZE   4


#define ECIB_INTENA         1
#define ECIB_RESET          3
#define ECIB_INT2PEND       4
#define ECIB_INT6PEND       5
#define ECIB_INT7PEND       6
#define ECIB_INTERRUPTING   7

#define ECIF_INTENA         (1<<ECIB_INTENA)
#define ECIF_RESET          (1<<ECIB_RESET)
#define ECIF_INT2PEND       (1<<ECIB_INT2PEND)
#define ECIF_INT6PEND       (1<<ECIB_INT6PEND)
#define ECIF_INT7PEND       (1<<ECIB_INT7PEND)
#define ECIF_INTERRUPTING   (1<<ECIB_INTERRUPTING)


#define ERT_MEMNEEDED(t)    (((t) & ERT_MEMMASK) ? 0x10000 << (((t) & ERT_MEMMASK) - 1) : 0x800000)
#define ERT_SLOTSNEEDED(t)  (((t) & ERT_MEMMASK) ?       1 << (((t) & ERT_MEMMASK) - 1) : 0x80)

#define EC_MEMADDR(slot)    ((slot) << (E_SLOTSHIFT))

#define EROFFSET(er)        ((int)&((struct ExpansionRom *)0)->er)
#define ECOFFSET(ec)        (sizeof(struct ExpansionRom) + ((int)&((struct ExpansionControl *)0)->ec))


struct DiagArea
{
	UBYTE da_Config;
	UBYTE da_Flags;
	UWORD da_Size;
	UWORD da_DiagPoint;
	UWORD da_BootPoint;
	UWORD da_Name;

	UWORD da_Reserved01;
	UWORD da_Reserved02;
};


#define DAC_BUSWIDTH    0xC0
#define DAC_NIBBLEWIDE  0x00
#define DAC_BYTEWIDE    0x40
#define DAC_WORDWIDE    0x80

#define DAC_BOOTTIME    0x30
#define DAC_NEVER       0x00
#define DAC_CONFIGTIME  0x10
#define DAC_BINDTIME    0x20


#pragma pack()

#endif /* LIBRARIES_CONFIGREGS_H */
