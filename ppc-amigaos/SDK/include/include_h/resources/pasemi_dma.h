/* :ts=4
 *
 * $VER: pasemi_dma.h 54.16 (22.08.2022)
 *
 * This file is part of pasemi_dma.
 *
 * Copyright (c) 2011 Costel Mincea.
 * All Rights Reserved.
 *
 */

#ifndef RESOURCES_PASEMI_DMA_H
#define RESOURCES_PASEMI_DMA_H 1

typedef enum
{
	CHTYPE_RX = 0,
	CHTYPE_TX,
	CHTYPE_TX_EVT0,
	CHTYPE_TX_EVT1
} PASDMAChannelType;

struct PASDMAChannel
{
	int8				ChannelNo;		/* Channel number */
	PASDMAChannelType	ChannelType;	/* Channel type */
	uint64				*Status;		/* Pointer to cachable status */
	uint32				Interrupt;		/* Interrupt used by the channel ready for AddIntServer() */
	uint16				RingSize;		/* Size of allocated ring */
	APTR				RingPhysAddr;	/* Physical (DMA) address of ring */
	uint64				*RingVirtAddr;	/* Virtual address of ring */
	APTR				Private;		/* User private data area */
};

#endif /* RESOURCES_PASEMI_DMA_H */
