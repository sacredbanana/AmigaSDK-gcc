#ifndef HARDWARE_INTBITS_H
#define HARDWARE_INTBITS_H
/*
**    $VER: intbits.h 54.16 (22.08.2022)
**
**    bits in the interrupt enable (and interrupt request) register
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

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
#endif

/****************************************************************************/

enum enIntBits
{
    INTB_SETCLR   = 15,  /* Set/Clear control bit. Determines if bits */
                         /* written with a 1 get set or cleared. Bits */
                         /* written with a zero are allways unchanged */
    INTB_INTEN    = 14,  /* Master interrupt (enable only ) */
    INTB_EXTER    = 13,  /* External interrupt */
    INTB_DSKSYNC  = 12,  /* Disk re-SYNChronized */
    INTB_RBF      = 11,  /* serial port Receive Buffer Full */
    INTB_AUD3     = 10,  /* Audio channel 3 block finished */
    INTB_AUD2     =  9,  /* Audio channel 2 block finished */
    INTB_AUD1     =  8,  /* Audio channel 1 block finished */
    INTB_AUD0     =  7,  /* Audio channel 0 block finished */
    INTB_BLIT     =  6,  /* Blitter finished */
    INTB_VERTB    =  5,  /* start of Vertical Blank */
    INTB_COPER    =  4,  /* Coprocessor */
    INTB_PORTS    =  3,  /* I/O Ports and timers */
    INTB_SOFTINT  =  2,  /* software interrupt request */
    INTB_DSKBLK   =  1,  /* Disk Block done */
    INTB_TBE      =  0   /* serial port Transmit Buffer Empty */
};

enum enIntFlags
{
    INTF_SETCLR  = 1L<<15,
    INTF_INTEN   = 1L<<14,
    INTF_EXTER   = 1L<<13,
    INTF_DSKSYNC = 1L<<12,
    INTF_RBF     = 1L<<11,
    INTF_AUD3    = 1L<<10,
    INTF_AUD2    = 1L<<9,
    INTF_AUD1    = 1L<<8,
    INTF_AUD0    = 1L<<7,
    INTF_BLIT    = 1L<<6,
    INTF_VERTB   = 1L<<5,
    INTF_COPER   = 1L<<4,
    INTF_PORTS   = 1L<<3,
    INTF_SOFTINT = 1L<<2,
    INTF_DSKBLK  = 1L<<1,
    INTF_TBE     = 1L<<0
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* HARDWARE_INTBITS_H */
