#ifndef HARDWARE_INTBITS_H
#define HARDWARE_INTBITS_H

/*
	interrupt bits

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/


#define INTB_SETCLR   (15)
#define INTB_INTEN    (14)
#define INTB_EXTER    (13)
#define INTB_DSKSYNC  (12)
#define INTB_RBF      (11)
#define INTB_AUD3     (10)
#define INTB_AUD2     (9)
#define INTB_AUD1     (8)
#define INTB_AUD0     (7)
#define INTB_BLIT     (6)
#define INTB_VERTB    (5)
#define INTB_COPER    (4)
#define INTB_PORTS    (3)
#define INTB_SOFTINT  (2)
#define INTB_DSKBLK   (1)
#define INTB_TBE      (0)

#define INTF_SETCLR   (1<<INTB_SETCLR)
#define INTF_INTEN    (1<<INTB_INTEN)
#define INTF_EXTER    (1<<INTB_EXTER)
#define INTF_DSKSYNC  (1<<INTB_DSKSYNC)
#define INTF_RBF      (1<<INTB_RBF)
#define INTF_AUD3     (1<<INTB_AUD3)
#define INTF_AUD2     (1<<INTB_AUD2)
#define INTF_AUD1     (1<<INTB_AUD1)
#define INTF_AUD0     (1<<INTB_AUD0)
#define INTF_BLIT     (1<<INTB_BLIT)
#define INTF_VERTB    (1<<INTB_VERTB)
#define INTF_COPER    (1<<INTB_COPER)
#define INTF_PORTS    (1<<INTB_PORTS)
#define INTF_SOFTINT  (1<<INTB_SOFTINT)
#define INTF_DSKBLK   (1<<INTB_DSKBLK)
#define INTF_TBE      (1<<INTB_TBE)


#endif /* HARDWARE_INTBITS_H */
