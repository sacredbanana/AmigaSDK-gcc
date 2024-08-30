#ifndef PROTO_ALIB_H
#define PROTO_ALIB_H

/*
**	$VER: alib.h 47.4 (19.6.2021)
**
**	Lattice 'C' style prototype/pragma header file combo
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/****************************************************************************/

#ifndef CLIB_ALIB_PROTOS_H
#include <clib/alib_protos.h>
#endif /* CLIB_ALIB_PROTOS_H */

/****************************************************************************/

/* These functions are present in amiga.lib and work very much like the
 * exec.library V39 functions of the same name. They expect parameters in
 * registers, unlike their corresponding LibAllocPooled(), LibCreatePool(),
 * LibDeletePool() and LibFreePooled() functions.
 */
APTR __ASM__ AsmCreatePool(__REG__(d0, ULONG memFlags), __REG__(d1, ULONG puddleSize), __REG__(d2, ULONG threshSize), __REG__(a6, struct Library * sysBase));
void __ASM__ AsmDeletePool(__REG__(a0, APTR poolHeader), __REG__(a6, struct Library * sysBase));
APTR __ASM__ AsmAllocPooled(__REG__(a0, APTR poolHeader), __REG__(d0, ULONG memSize), __REG__(a6, struct Library * sysBase));
void __ASM__ AsmFreePooled(__REG__(a0, APTR poolHeader), __REG__(a1, APTR memory), __REG__(d0, ULONG memSize), __REG__(a6, struct Library * sysBase));

/****************************************************************************/

/* OBSCURE AND OCCULT AMIGA.LIB CONTENTS
 *
 * amiga.lib has always contained definitions of constants and support
 * functions which were used in the early "bootstrapping" of the Amiga
 * operating system and the programs which would run on it (e.g. the "Clock"
 * or "Preferences" programs). Most of these definitions are documented in
 * the ROM Kernel Reference manuals and the operating system header files,
 * but many others are not. These internal-use-only functions and data
 * have been around since 1984 and may still be part of the amiga.lib you
 * are using.
 *
 * This does not mean that you can safely ignore these internal-use-only
 * functions and data because they occupy the same symbol space as functions
 * in the standard 'C' runtime library, such as printf(). If you accidentally
 * declare a function or global data which shares the same name as a symbol
 * defined in amiga.lib it may have profound effects on the software you are
 * writing.
 *
 * Depending upon the order in which your program is linked against amiga.lib
 * or your compiler's lc.lib/sc.lib/c.lib/libc.a/etc. you may trigger
 * accidental linker errors, or the fprintf() function you call may not print
 * anything and might just crash.
 *
 * The following section declares these "hidden" constants, functions
 * and data, in case you might want to check if your program may be vulnerable
 * to accidental collisions with them. Where possible, a brief documentation
 * of the respective functions, constants and data has been added.
 */

/****************************************************************************/

/* Addresses of the complex interface adapter (CIA) chips and
 * their respective registers. Reading or writing from/to these
 * will access the hardware!
 */
#if defined(ALIB_HARDWARE_CIA)
#ifndef HARDWARE_CIA_H
#include <hardware/cia.h>
#endif /* HARDWARE_CIA_H */

extern volatile struct CIA ciaa;
extern volatile struct CIA ciab;

extern volatile UBYTE ciaapra;
extern volatile UBYTE ciabpra;
extern volatile UBYTE ciaaprb;
extern volatile UBYTE ciabprb;
extern volatile UBYTE ciaaddra;
extern volatile UBYTE ciabddra;
extern volatile UBYTE ciaaddrb;
extern volatile UBYTE ciabddrb;
extern volatile UBYTE ciaatalo;
extern volatile UBYTE ciabtalo;
extern volatile UBYTE ciaatahi;
extern volatile UBYTE ciabtahi;
extern volatile UBYTE ciaatblo;
extern volatile UBYTE ciabtblo;
extern volatile UBYTE ciaatbhi;
extern volatile UBYTE ciabtbhi;
extern volatile UBYTE ciaatodlow;
extern volatile UBYTE ciabtodlow;
extern volatile UBYTE ciaatodmid;
extern volatile UBYTE ciabtodmid;
extern volatile UBYTE ciaatodhi;
extern volatile UBYTE ciabtodhi;
extern volatile UBYTE ciaasdr;
extern volatile UBYTE ciabsdr;
extern volatile UBYTE ciaaicr;
extern volatile UBYTE ciabicr;
extern volatile UBYTE ciaacra;
extern volatile UBYTE ciabcra;
extern volatile UBYTE ciaacrb;
extern volatile UBYTE ciabcrb;
#endif /* ALIB_HARDWARE_CIA */

/****************************************************************************/

/* Addresses of the Amiga custom chips as well as individual registers.
 * Reading or writing from/to these will access the hardware!
 *
 * Accessing the chip registers through 'C' programs is not generally
 * recommended because on actual physical (vs. emulated/virtual) Amiga
 * hardware optimized compiler-generated code may trigger side-effects.
 * This is because the custom chips feature dedicated read-only and also
 * write-only registers. Reading from a write-only register (e.g. set
 * or clear a single bit) as well as writing to a read-only register
 * may have unpredictable effects!
 *
 * Please note that these definitions will conflict with the 'C' runtime
 * library function definitions in <stdio.h>.
 */
#if defined(ALIB_HARDWARE_CUSTOM)
#ifndef HARDWARE_CUSTOM_H
#include <hardware/custom.h>
#endif /* HARDWARE_CUSTOM_H */

extern volatile struct Custom custom;

extern volatile UWORD bltddat;
extern volatile UWORD dmaconr;
extern volatile UWORD vposr;
extern volatile UWORD vhposr;
extern volatile UWORD dskdatr;
extern volatile UWORD joy0dat;
extern volatile UWORD joy1dat;
extern volatile UWORD clxdat;
extern volatile UWORD adkconr;
extern volatile UWORD pot0dat;
extern volatile UWORD pot1dat;
extern volatile UWORD potinp;
extern volatile UWORD serdatr;
extern volatile UWORD dskbytr;
extern volatile UWORD intenar;
extern volatile UWORD intreqr;
extern volatile APTR dskpt;
extern volatile UWORD dsklen;
extern volatile UWORD dskdat;
extern volatile UWORD refptr;
extern volatile UWORD vposw;
extern volatile UWORD vhposw;
extern volatile UWORD copcon;
extern volatile UWORD serdat;
extern volatile UWORD serper;
extern volatile UWORD potgo;
extern volatile UWORD joytest;
extern volatile UWORD strequ;
extern volatile UWORD strvbl;
extern volatile UWORD strhor;
extern volatile UWORD strlong;
extern volatile UWORD bltcon0;
extern volatile UWORD bltcon1;
extern volatile UWORD bltafwm;
extern volatile UWORD bltalwm;
extern volatile APTR bltcpt;
extern volatile APTR bltbpt;
extern volatile APTR bltapt;
extern volatile APTR bltdpt;
extern volatile UWORD bltsize;
extern volatile UBYTE pad2d;
extern volatile UBYTE bltcon0l;
extern volatile UWORD bltsizv;
extern volatile UWORD bltsizh;
extern volatile UWORD bltcmod;
extern volatile UWORD bltbmod;
extern volatile UWORD bltamod;
extern volatile UWORD bltdmod;
extern volatile UWORD bltcdat;
extern volatile UWORD bltbdat;
extern volatile UWORD bltadat;
extern volatile UWORD deniseid;
extern volatile UWORD dsksync;
extern volatile ULONG cop1lc;
extern volatile ULONG cop2lc;
extern volatile UWORD copjmp1;
extern volatile UWORD copjmp2;
extern volatile UWORD copins;
extern volatile UWORD diwstrt;
extern volatile UWORD diwstop;
extern volatile UWORD ddfstrt;
extern volatile UWORD ddfstop;
extern volatile UWORD dmacon;
extern volatile UWORD clxcon;
extern volatile UWORD intena;
extern volatile UWORD intreq;
extern volatile UWORD adkcon;
extern volatile struct {
	UWORD *ac_ptr;
	UWORD ac_len;
	UWORD ac_per;
	UWORD ac_vol;
	UWORD ac_dat;
	UWORD ac_pad[2];
} aud[4];
extern volatile APTR bplpt[8];
extern volatile UWORD bplcon0;
extern volatile UWORD bplcon1;
extern volatile UWORD bplcon2;
extern volatile UWORD bplcon3;
extern volatile UWORD bpl1mod;
extern volatile UWORD bpl2mod;
extern volatile UWORD bplcon4;
extern volatile UWORD clxcon2;
extern volatile UWORD bpldat[8];
extern volatile APTR sprpt[8];
extern volatile struct {
	UWORD pos;
	UWORD ctl;
	UWORD dataa;
	UWORD datab;
} spr[8];
extern volatile UWORD color[32];
extern volatile UWORD htotal;
extern volatile UWORD hsstop;
extern volatile UWORD hbstrt;
extern volatile UWORD hbstop;
extern volatile UWORD vtotal;
extern volatile UWORD vsstop;
extern volatile UWORD vbstrt;
extern volatile UWORD vbstop;
extern volatile UWORD sprhstrt;
extern volatile UWORD sprhstop;
extern volatile UWORD bplhstrt;
extern volatile UWORD bplhstop;
extern volatile UWORD hhposw;
extern volatile UWORD hhposr;
extern volatile UWORD beamcon0;
extern volatile UWORD hsstrt;
extern volatile UWORD vsstrt;
extern volatile UWORD hcenter;
extern volatile UWORD diwhigh;
extern volatile UWORD fmode;
#endif /* ALIB_HARDWARE_CUSTOM */

/****************************************************************************/

/* The only well-defined address in the entire Amiga address space
 * (AbsExecBase) and the addresses of specific expansion and ROM
 * spaces. Note that the latter may not apply to Amiga computers with
 * Kickstart ROMs larger than 256 KiBytes.
 */
#if defined(ALIB_HARDWARE_MEMMAP)
#ifndef EXEC_EXECBASE_H
#include <exec/execbase.h>
#endif /* EXEC_EXECBASE_H */

extern CONST struct ExecBase *AbsExecBase;

extern CONST VOID *cartridge;
extern CONST VOID *bootrom;
extern CONST VOID *romstart;
extern CONST VOID *romend;
#endif /* ALIB_HARDWARE_MEMMAP */

/****************************************************************************/

/* Support functions for 'C' programming, which may have no general use. */
#if defined(ALIB_C_SUPPORT)
/* Seed value for RangeRand() and RangeRan() functions.
 * Defaults to 0.
 */
extern LONG RangeSeed;

/* Equivalent to RangeRand(). */
extern UWORD __STDARGS__ RangeRan(ULONG v);

/* Multiplication and division for signed and unsigned
 * 16 bit integers.
 */
extern UWORD __STDARGS__ umuls(UWORD a, UWORD b);
extern UWORD __STDARGS__ IMulU(UWORD a, UWORD b);
extern WORD __STDARGS__ smuls(WORD a, WORD b);
extern WORD __STDARGS__ IMulS(WORD a, WORD b);
extern LONG __STDARGS__ sdiv(LONG a, WORD b);
extern LONG __STDARGS__ IDivS(LONG a, WORD b);
extern ULONG __STDARGS__ IDivU(ULONG a, UWORD b);
#endif /* ALIB_C_SUPPORT */

/****************************************************************************/

/* Support functions which use graphics library, which may have no general use. */
#if defined(ALIB_GRAPHICS_SUPPORT)
/* Poll the graphics.library/VBeamPos() function until the beam
 * position has been reached or crossed.
 */
void waitbeam(long beam_position);

/* This function is used by AddTOF(). */
LONG __ASM__ ttskasm(__REG__(a1, struct Interrupt * is));
#endif /* ALIB_GRAPHICS_SUPPORT */

/****************************************************************************/

/* Global variables and data structures used by the commodities.library
 * support functions.
 */
#if defined(ALIB_COMMODITIES_SUPPORT)
extern ULONG CXLIB_argarray_size;
extern char ** CXLIB_argarray;
#endif /* ALIB_COMMODITIES_SUPPORT */

/****************************************************************************/

/* Functions which share the semantics as those of the same name in your
 * 'C' compiler runtime library but do not work like these. For example,
 * the fprintf() function defined below expects a different type of file
 * parameter and the printf()/sprintf() functions do not support floating
 * point numbers.
 *
 * Please note that these definitions will conflict with the 'C' runtime
 * library functions in <stdio.h>.
 */
#if defined(ALIB_STDIO)
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif /* DOS_DOS_H */

extern LONG __STDARGS__ printf(const char *format_spec, ...);
extern LONG __STDARGS__ sprintf(char *buffer, const char *format_spec, ...);
extern LONG __STDARGS__ fclose(BPTR stream);
extern LONG __STDARGS__ fgetc(BPTR stream);
extern LONG __STDARGS__ fprintf(BPTR stream, const char *format_spec, ...);
extern LONG __STDARGS__ fputc(char c, LONG stream);
extern LONG __STDARGS__ fputs(const char *s, BPTR stream);
extern LONG __STDARGS__ getchar(void);
extern LONG __STDARGS__ putchar(char c);
extern LONG __STDARGS__ puts(const char *s);
#endif /* ALIB_STDIO */

/****************************************************************************/

/* Special support functions for the Motorola Fast Floating Point (FFP)
 * format which are not part of mathffp.library or mathtrans.library.
 *
 * Please note that these definitions will conflict with the 'C' runtime
 * library functions in <stdlib.h>.
 */
#if defined(ALIB_MATH_SUPPORT)
extern FLOAT __STDARGS__ abs(FLOAT arg);
#endif /* ALIB_MATH_SUPPORT */

/****************************************************************************/

#endif /* PROTO_ALIB_H */
