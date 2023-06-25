#ifndef RESOURCES_CYRUS_H
#define RESOURCES_CYRUS_H
/*
**    $VER: cyrus.h 54.16 (22.08.2022)
**
**    Unit number definitions for "cyrus.resource"
**
**    Copyright (c) 2012 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

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

/***************************************************************************/

/*	Unit number definitions. Currently there is only a single resource 
**	available via this means.
*/
#define	CR_CPUGPIO	0	//	The set of registers associated with CPU GPIO

/***************************************************************************/

/*	Names of the registers in the set. These are all 32-bit registers, so
**	should be referenced as "RegBase[CY_GPIO_xxx]", where RegBase is the
**	address returned by the resource.
*/
enum
{
	CY_GPIO_DIR		= 0,			// direction register
									// 1 = output, 0 = input
	CY_GPIO_OUT		= 1,			// output control register
									// 1 = totem-pole output, 0 = open drain
	CY_GPIO_DATA	= 2				// data register
};

/*	Notes:
**	1.	Bits in these registers control many LED indicators and other hardware
**		on the Cyrus motherboard. Do not change bits except for a specific 
**		purpose. All writes to the Data register must be of the form:
**		RegBase[CY_GPIO_DATA] |= xxx;	(to turn on a bit); or
**		RegBase[CY_GPIO_DATA] &= ~xxx;	(to turn off a bit).
**		Refer to the VariSys Technical Reference Manual for details
**		of the connections of each bit.
**	2.	The bit numbering in the Freescale and Varisys documentation is 
**		"back-to-front" from Big-Endian usage. For example, the HDD LED on the
**		Cyrus motherboard is described as "GPIO5", but to control it, you need
**		to use the bit pattern "0x04000000" (bit #26). Subtract the given bit
**		number from 31 to get the required bit number.
*/

/***************************************************************************/

#define CYRUSNAME "cyrus.resource"

/***************************************************************************/

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

#endif /* RESOURCES_CYRUS_H */
