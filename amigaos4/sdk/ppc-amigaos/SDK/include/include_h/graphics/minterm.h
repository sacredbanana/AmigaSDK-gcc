#ifndef GRAPHICS_MINTERM_H
#define GRAPHICS_MINTERM_H
/*
**    $VER: minterm.h 54.16 (22.08.2022)
**
**    Minterm include file
**
**    Copyright (c) 2014 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

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

// Basic minterm value.

enum enMinterm
{
    MINTERM_ABC    = 0x80,
    MINTERM_ABNC   = 0x40,
    MINTERM_ANBC   = 0x20,
    MINTERM_ANBNC  = 0x10,
    MINTERM_NABC   = 0x08,
    MINTERM_NABNC  = 0x04,
    MINTERM_NANBC  = 0x02,
    MINTERM_NANBNC = 0x01
};


// Some commonly used operations.

enum enMintermOperations
{
    // Copy source and blit thru mask
    MINTERM_SRCMASK = MINTERM_ABC | MINTERM_ABNC | MINTERM_ANBC,

    // Invert source and blit thru mask
    MINTERM_NOTSRCMASK = MINTERM_ANBC,

    // Copy source and blit thru mask
    MINTERM_B_EQUALS_C = MINTERM_ABC | MINTERM_ANBNC | MINTERM_NABC | MINTERM_NANBNC,

    MINTERM_B_OR_C  = MINTERM_ABC|MINTERM_ABNC|MINTERM_NABC | MINTERM_NABNC|MINTERM_ANBC|MINTERM_NANBC,
    MINTERM_A_OR_B  = MINTERM_ABC|MINTERM_ANBC|MINTERM_NABC | MINTERM_ABNC|MINTERM_ANBNC|MINTERM_NABNC,
    MINTERM_A_OR_C  = MINTERM_ABC|MINTERM_NABC|MINTERM_ABNC | MINTERM_ANBC|MINTERM_NANBC|MINTERM_ANBNC,
    MINTERM_A_XOR_C = MINTERM_NABC|MINTERM_ABNC | MINTERM_NANBC|MINTERM_ANBNC,
    MINTERM_A_TO_D  = MINTERM_ABC|MINTERM_ANBC|MINTERM_ABNC|MINTERM_ANBNC
};

/****************************************************************************/

// Do not use the following definitions.
// They are provided for backwards compatibility only.

#if defined(__USE_CLASSIC_MINTERM__)

// For blitter control register 0 on Classic Amiga hardware.
#define ABC    0x80
#define ABNC   0x40
#define ANBC   0x20
#define ANBNC  0x10
#define NABC   0x08
#define NABNC  0x04
#define NANBC  0x02
#define NANBNC 0x01


// Some commonly used operations.
#define A_OR_B  (ABC|ANBC|NABC | ABNC|ANBNC|NABNC)
#define A_OR_C  (ABC|NABC|ABNC | ANBC|NANBC|ANBNC)
#define A_XOR_C (NABC|ABNC | NANBC|ANBNC)
#define A_TO_D  (ABC|ANBC|ABNC|ANBNC)

#endif

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

#endif /* GRAPHICS_MINTERM_H */
