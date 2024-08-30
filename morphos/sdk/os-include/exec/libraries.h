#ifndef EXEC_LIBRARIES_H
#define EXEC_LIBRARIES_H

/*
	exec library definitions (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_MACHINE_H
# include <exec/machine.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef EMUL_EMULINTERFACE_H
# include <emul/emulinterface.h>
#endif

#pragma pack(2)


#define LIB_VECTSIZE  6
#define LIB_RESERVED  4
#define LIB_BASE      (-LIB_VECTSIZE)
#define LIB_USERDEF   (LIB_BASE - (LIB_RESERVED * LIB_VECTSIZE))
#define LIB_NONSTD    (LIB_USERDEF)

#define LIB_OPEN         (-6)
#define LIB_CLOSE        (-12)
#define LIB_EXPUNGE      (-18)
#define LIB_EXTFUNC      (-24)
#define LIB_GETQUERYATTR (-24)	/* LIBF_QUERYINFO */


struct Library
{
	struct Node lib_Node;
	UBYTE       lib_Flags;
	UBYTE       lib_pad;
	UWORD       lib_NegSize;
	UWORD       lib_PosSize;
	UWORD       lib_Version;
	UWORD       lib_Revision;
	APTR        lib_IdString;
	ULONG       lib_Sum;
	UWORD       lib_OpenCnt;
};

#define LIBF_SUMMING   (1 << 0)
#define LIBF_CHANGED   (1 << 1)
#define LIBF_SUMUSED   (1 << 2)
#define LIBF_DELEXP    (1 << 3)
/*
 * private
 */
#define LIBF_RAMLIB    (1 << 4)
/*
 * Needs to be set if the GetQueryAttr function is legal
 */
#define LIBF_QUERYINFO (1 << 5)
/*
 * The remaining bits are reserved and aren't allowed to be touched
 */

/*
 * Useful macro for checking minimum library version/revision
 */
#ifdef __GNUC__
#define LIB_MINVER(lib,ver,rev) ({ struct Library *__tlib__ = lib; const UWORD __tver__ = ver; __tlib__->lib_Version > __tver__ || (__tlib__->lib_Version == __tver__ && __tlib__->lib_Revision >= (rev)); })
#else
#define LIB_MINVER(lib,ver,rev) ((lib)->lib_Version > (ver) || ((lib)->lib_Version == (ver) && (lib)->lib_Revision >= (rev)))
#endif

#ifdef EXEC_OBSOLETE

#define lh_Node     lib_Node
#define lh_Flags    lib_Flags
#define lh_pad      lib_pad
#define lh_NegSize  lib_NegSize
#define lh_PosSize  lib_PosSize
#define lh_Version  lib_Version
#define lh_Revision lib_Revision
#define lh_IdString lib_IdString
#define lh_Sum      lib_Sum
#define lh_OpenCnt  lib_OpenCnt

#endif

/* NewSetFunction extensions
 */

#define SETFUNCTAG_Dummy    (TAG_USER +0x01000000)

/* Set the machine type of the function
 * Default is MACHINE_PPC
 */
#define SETFUNCTAG_MACHINE  (SETFUNCTAG_Dummy + 0x1)

/* Function type specifier
 */

#define SETFUNCTAG_TYPE     (SETFUNCTAG_Dummy + 0x2)

/* ID String
 */

#define SETFUNCTAG_IDNAME   (SETFUNCTAG_Dummy + 0x3)


/*
 * Set to TRUE if the replaced function will never be used
 * again.
 */
#define SETFUNCTAG_DELETE   (SETFUNCTAG_Dummy + 0x4)

/* See emul/emulinterface.h for more information
 */

/* Save Emulation PPC Registers
 * Call Function
 * Restore Emulation PPC Registers
 * REG_D0 = Result
 */
#define SETFUNCTYPE_NORMAL          0

/* Call Function
 * Must use the global register settings of the emulation
 * REG_D0 = Result
 */
#define SETFUNCTYPE_QUICK           1

/* Save Emulation PPC Registers
 * Call Function
 * Restore Emulation PPC Registers
 * No Result
 * Needed to replace functions like
 * forbid,obtainsemaphores which are
 * defined as preserving registers
 */
#define SETFUNCTYPE_NORMALNR        2

/* Call Function
 * Must use the global register settings of the emulation
 * No Result
 * Needed to replace functions like
 * forbid,obtainsemaphores which are
 * defined as preserving registers
 */
#define SETFUNCTYPE_QUICKNR         3

#define SETFUNCTYPE_NORMALSR        4

#define SETFUNCTYPE_NORMALSRNR      5

#define SETFUNCTYPE_NORMALD0_D1     6

#define SETFUNCTYPE_NORMALRESTORE   7

#define SETFUNCTYPE_SYSTEMV         8

#define SETFUNCTYPE_NORMALD0D1SR    9

#define SETFUNCTYPE_NORMALD0D1A0A1SR 10



/* CreateLibrary extensions
 */

#define LIBTAG_BASE         (TAG_USER + 0x01000100)

/*
 * Function/Vector Array
 */
#define LIBTAG_FUNCTIONINIT (LIBTAG_BASE+0x0)
/*
 * Struct Init
 */
#define LIBTAG_STRUCTINIT   (LIBTAG_BASE+0x1)
/*
 * Library Init
 */
#define LIBTAG_LIBRARYINIT  (LIBTAG_BASE+0x2)
/*
 * Init Code Type
 */
#define LIBTAG_MACHINE      (LIBTAG_BASE+0x3)
/*
 * Library Base Size
 */
#define LIBTAG_BASESIZE     (LIBTAG_BASE+0x4)
/*
 * SegList Ptr
 */
#define LIBTAG_SEGLIST      (LIBTAG_BASE+0x5)
/*
 * Library Priority
 */
#define LIBTAG_PRI          (LIBTAG_BASE+0x6)
/*
 * Library Type..Library,Device,Resource,whatever
 */
#define LIBTAG_TYPE         (LIBTAG_BASE+0x7)
/*
 * Library Version
 * (UWORD)
 */
#define LIBTAG_VERSION      (LIBTAG_BASE+0x8)
/*
 * Library Flags
 */
#define LIBTAG_FLAGS        (LIBTAG_BASE+0x9)
/*
 * Library Name
 */
#define LIBTAG_NAME         (LIBTAG_BASE+0xa)
/*
 * Library IDString
 */
#define LIBTAG_IDSTRING     (LIBTAG_BASE+0xb)
/*
 * AddDevice(),AddLibrary(),AddResource()..
 * depends on LibNode.ln_Type field which
 * can be set by some Init function, Struct Scripts
 * or LIBTAG_TYPE.
 * If you set LIBTAG_PUBLIC the library
 * is added to the right system list.
 */
#define LIBTAG_PUBLIC       (LIBTAG_BASE+0xc)
/*
 * Library Revision
 * (UWORD)
 */
#define LIBTAG_REVISION     (LIBTAG_BASE+0xd)
/*
 * Library QueryInfo Flag
 * (Boolean)
 */
#define LIBTAG_QUERYINFO    (LIBTAG_BASE+0xe)



/* Private
 * don't touch...floating design
 */
struct  FuncEntry
{
	struct EmulLibEntry  EmulLibEntry;
	void                *OldFunction;	/* Needed for bookkeeping */
};

struct  FuncOldEntry
{
	UWORD                Command;
	struct FuncEntry    *FuncEntry;
};


/*
 * EmulLibEntry.Extension
 */
#define FUNCENTRYEXTF_LIBRARY           0x1	/* Entry created by the OS */
#define FUNCENTRYEXTF_SETFUNCTION       0x2	/* Entry created by SetFunction, otherwise MakeFunction */

/*
 * Functionarray first ULONG ID defines the format
 * of the functionarray for MakeFunctions()/MakeLibrary().
 *
 * If there's no such id, the functionarray is a
 * 32Bit 68k function ptr array.
 * (ULONG) 0xffffffff stops it
 */

/* 68k 16bit relative functionarray ptrs
 * (UWORD) 0xffff stops it
 */

#define FUNCARRAY_16BIT_OLD             0xffffffff

/* PPC 32bit functionarray ptrs 
 * (ULONG) 0xffff stops it
 */
#define FUNCARRAY_32BIT_NATIVE          0xfffefffe

/* Starts a functionarray block.
 * This way it's possible to mix 68k and PPC
 * function definitions.
 * BASE:
 *  FUNCTIONARRAY_BEGIN
 *   FUNCARRAY_32BIT_NATIVE
 *    FUNC0
 *    FUNC1
 *    .
 *    FUNCn
 *    0xffffffff
 *   FUNCn+1  (No ID->32Bit 68k)
 *    FUNCn+2
 *    .
 *    FUNCm
 *    0xffffffff
 *   FUNCARRAY_16BIT_OLD
 *    FUNCm+1-BASE
 *    FUNCm+2-BASE
 *    .
 *    FUNCo-BASE
 *    0xffff
 *  FUNCTIONARRAY_END
 */

#define FUNCARRAY_BEGIN                 0xfffdfffd

/* Ends a functionarray block.
 */
#define FUNCARRAY_END                   0xfffcfffc

/* PPC 32bit Quick functionarray ptrs.
 * These functions must comply to the emulation's
 * register layout which is defined inside the
 * emul/emulregs.h. That means the register layout
 * MUST also be valid during interrupts/task switches.
 * You can't just destroy A7(r31), SR or PC.
 *
 * You shouldn't use this for any normal code
 * as there's no real reason to do so. If you
 * really think you need to use it please ask
 * us first on the dev mailinglist.
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_QUICK_NATIVE    0xfffbfffb

/* PPC 32bit QuickNR(No Result) functionarray ptrs
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_QUICKNR_NATIVE  0xfffafffa

/* PPC 32bit no result functionarray ptrs
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_NR_NATIVE       0xfff9fff9

/* PPC 32bit SR functionarray ptrs
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_SR_NATIVE       0xfff8fff8

/* PPC 32bit SR(no result) functionarray ptrs
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_SRNR_NATIVE     0xfff7fff7

/* PPC 32bit D0_D1 functionarray ptrs
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_D0D1_NATIVE     0xfff6fff6

/* PPC 32bit Restore1 functionarray ptrs
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_RESTORE_NATIVE  0xfff5fff5

/* PPC 32bit SystemV ABI entry
 * these function entries DON'T comply
 * to the amiga register modell REG_D0-A6
 * but comply to the PPC SystemV ABI so
 * you can directly use PPC C Argument
 * parsing. That way you're also not limited
 * with the register count.
 * Such library functions can't be used
 * by 68k emulation, so you can only use
 * them for new code.
 * As we allow these new functions to be
 * used with old functions we keep the
 * 6 bytes function entry steps in the library.
 * Layout is
 *
 * CODE_JMP, &FuncEntry ; Old Entry
 * CODE_ILLEGAL, Function ; SystemV ABI Entry
 * 
 *
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_SYSTEMV         0xfff4fff4

/* PPC 32bit D0D1SR functionarray ptrs
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_D0D1SR_NATIVE     0xfff3fff3

/* PPC 32bit D0D1A0A1SR functionarray ptrs
 * (ULONG) 0xffffffff stops it
 */
#define FUNCARRAY_32BIT_D0D1A0A1SR_NATIVE     0xfff2fff2


#pragma pack()

#endif
