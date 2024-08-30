#ifndef GRAPHICS_DISPLAY_H
#define GRAPHICS_DISPLAY_H

/*
	graphics display control register definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


#define MODE_640     0x8000
#define PLNCNTMSK    0x7
#define PLNCNTSHFT   12
#define PF2PRI       0x40
#define COLORON      0x0200
#define DBLPF        0x400
#define HOLDNMODIFY  0x800
#define INTERLACE    4

#define PFA_FINE_SCROLL        0xF
#define PFB_FINE_SCROLL_SHIFT  4
#define PF_FINE_SCROLL_MASK    0xF

#define DIW_HORIZ_POS          0x7F
#define DIW_VRTCL_POS          0x1FF
#define DIW_VRTCL_POS_SHIFT 7

#define DFTCH_MASK  0xFF

#define VPOSRLOF  0x8000


#endif /* GRAPHICS_DISPLAY_H */
