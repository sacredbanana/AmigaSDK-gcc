#ifndef RESOURCES_RADEONCP_H
#define RESOURCES_RADEONCP_H 1
/*
**    $VER: radeoncp.h 54.16 (22.08.2022)
**
**    radeoncp.resource include file
**
**    Copyright (C) 2008 Hans-Joerg Frieden
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif


/****************************************************************************/

#define RADEONCPRESNAME "radeoncp.resource"
#define RADEONCPRES_CURRENT	2	/* Current version of the resource structure */
enum
{
	RADEON_CHIP_UNKNOWN = 0,
	RADEON_CHIP_R100,
	RADEON_CHIP_R200,
	RADEON_CHIP_R250,
	RADEON_CHIP_R300,
	RADEON_CHIP_R350,
	RADEON_CHIP_RV100,
	RADEON_CHIP_RV200,
	RADEON_CHIP_RV250,
	RADEON_CHIP_RV280,
	RADEON_CHIP_RV350,
	RADEON_CHIP_RV370,
	RADEON_CHIP_RV380,
};

enum
{
	RADEON_CLASS_UNKNOWN	=   0,
	RADEON_CLASS_R100		=	1,
	RADEON_CLASS_R200		=	2,
	RADEON_CLASS_R300		=	3
};

#ifndef RADEON_PRIV_H_
/*!
 * This structure is not what you will actually get, but only the first two
 * fields to make the register access faster. This way, register access can
 * be performed directly, which is a good deal faster than going through a
 * function every time
 */
struct radeon_dev_t
{
	struct Node Link;						//!< PRIVATE
	volatile uint32 *registers;				//!< Pointer to the Radeon's register array
	volatile uint32 *framebuffer_physical;	//!< Physical framebuffer address
	volatile uint32 *framebuffer;			//!< PCI Address of the framebuffer
};
#endif

#define rad__wfence() asm volatile ("sync;eieio")
#define rad__rfence() asm volatile ("sync;eieio")
#define rad_swaplong(x) \
        ((x & 0xFF000000) >> 24) \
   |((x & 0x00FF0000) >> 8)  \
   |((x & 0x0000FF00) << 8)  \
   |((x & 0x000000FF) << 24)

static inline void radwritel(void * addr, uint32 value)
{
	*(volatile uint32 *)(addr) = value;
    rad__wfence();
}

static inline uint32 radreadl(void * addr)
{
	rad__rfence();
    uint32 val = *(volatile uint32 *)(addr);
    return val;
}

static inline uint32 radreadl_nosync(void * addr)
{
	return *(volatile uint32 *)(addr);
}

#define RADEON_READ(addr) radreadl((void *)(self->registers) + (addr))
#define RADEON_WRITE(addr, x) radwritel((void *)(self->registers) + (addr), (x))
#define RADEON_READNS(addr) radreadl_nosync((void *)(self->registers) + (addr))

#define RADEON_DEV_READ(r, addr) radreadl((void *)(r->registers) + (addr))
#define RADEON_DEV_WRITE(r, addr, x) radwritel((void *)(r->registers) + (addr), (x))
#define RADEON_DEV_READNS(r, addr) radreadl_nosync((void *)(r->registers) + (addr))

typedef struct radeon_dev_t *radeon_dev;

struct RadeonCPRes
{
	struct Node Link;
	uint32 Version;

	radeon_dev 	(*open)				(char *busId);
	void 		(*close)			(radeon_dev dev);
	int 		(*wait_idle)		(radeon_dev dev);
	int 		(*lock)				(radeon_dev dev);
	void 		(*unlock)			(radeon_dev dev);
	void 		(*submit)			(radeon_dev dev, void *package, uint32 size);
	int 		(*getclass)			(radeon_dev dev);
	int 		(*getchip)			(radeon_dev dev);
	void* 		(*alloc_3d_state)	(radeon_dev dev);
	void 		(*free_3d_state)	(radeon_dev dev, void *state);
	void 		(*set_3d_state)		(radeon_dev dev, void *state);
	void 		(*submit_indirect)	(radeon_dev dev, void *package, uint32 size);

	/* New for version 2 of the structure */
	void		(*flush)			(radeon_dev dev); // Flush pending packages

};

/****************************************************************************/

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* RESOURCES_CARD_H */

