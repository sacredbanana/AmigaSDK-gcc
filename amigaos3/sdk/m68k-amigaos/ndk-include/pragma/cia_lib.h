#ifndef PRAGMA_CIA_LIB_H
#define PRAGMA_CIA_LIB_H

/*
**	$VER: cia_lib.h 47.3 (5.2.2022)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_CIA_PROTOS_H
#include <clib/cia_protos.h>
#endif /* CLIB_CIA_PROTOS_H */

/****************************************************************************/

/* The ciaa.resource/ciab.resource library stub functions are part of
 * amiga.lib, but it should not be necessary to use them. The following
 * defines local stub functions which then in turn call the respective
 * ciaa.resource/ciab.resource functions through the "#pragma amicall"
 * command.
 *
 * Because the definition of these local stub functions may conflict with
 * the creation of precompiled header files in Aztec 'C' this feature is
 * not enabled by default. You need to add "#define __USE_CIA_STUBS" to
 * enable it.
 */

#ifdef __USE_CIA_STUBS

/****************************************************************************/

struct Interrupt * __AddICRVector(LONG iCRBit, struct Interrupt *interrupt);
VOID __RemICRVector(LONG iCRBit, struct Interrupt *interrupt);
WORD __AbleICR(LONG mask);
WORD __SetICR(LONG mask);

/****************************************************************************/

#pragma amicall(__CIABase, 0x6, __AddICRVector(d0,a1))
#pragma amicall(__CIABase, 0xc, __RemICRVector(d0,a1))
#pragma amicall(__CIABase, 0x12, __AbleICR(d0))
#pragma amicall(__CIABase, 0x18, __SetICR(d0))

/****************************************************************************/

STATIC struct Interrupt *
__AddICRVector_stub(
	struct Library *	__CIABase,
	WORD			iCRBit,
	struct Interrupt *	interrupt)
{
	return __AddICRVector(iCRBit, interrupt);
}

#define AddICRVector(resource, iCRBit, interrupt) \
	__AddICRVector_stub((resource), (iCRBit), (interrupt))

/****************************************************************************/

STATIC VOID
__RemICRVector_stub(
	struct Library *	__CIABase,
	WORD			iCRBit,
	struct Interrupt *	interrupt)
{
	__RemICRVector(iCRBit, interrupt);
}

#define RemICRVector(resource, iCRBit, interrupt) \
	__RemICRVector_stub((resource), (iCRBit), (interrupt))

/****************************************************************************/

STATIC WORD
__AbleICR_stub(
	struct Library *	__CIABase,
	WORD			mask)
{
	return __AbleICR(mask);
}

#define AbleICR(resource, mask) \
	__AbleICR_stub((resource), (mask))

/****************************************************************************/

STATIC WORD
__SetICR_stub(
	struct Library *	__CIABase,
	WORD			mask)
{
	return __SetICR(mask);
}

#define SetICR(resource, mask) \
	__SetICR_stub((resource), (mask))

/****************************************************************************/

#endif /* __USE_CIA_STUBS */

/****************************************************************************/

#endif /* PRAGMA_CIA_LIB_H */
