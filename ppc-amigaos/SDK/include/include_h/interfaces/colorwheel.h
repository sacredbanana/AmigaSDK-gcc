#ifndef COLORWHEEL_INTERFACE_DEF_H
#define COLORWHEEL_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 52.6.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef GADGETS_COLORWHEEL_H
#include <gadgets/colorwheel.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct ColorWheelIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ColorWheelIFace *Self);
	ULONG APICALL (*Release)(struct ColorWheelIFace *Self);
	void APICALL (*Expunge)(struct ColorWheelIFace *Self);
	struct Interface * APICALL (*Clone)(struct ColorWheelIFace *Self);
	VOID APICALL (*ConvertHSBToRGB)(struct ColorWheelIFace *Self, struct ColorWheelHSB * hsb, struct ColorWheelRGB * rgb);
	VOID APICALL (*ConvertRGBToHSB)(struct ColorWheelIFace *Self, struct ColorWheelRGB * rgb, struct ColorWheelHSB * hsb);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* COLORWHEEL_INTERFACE_DEF_H */
