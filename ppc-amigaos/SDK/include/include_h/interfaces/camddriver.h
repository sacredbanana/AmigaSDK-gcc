#ifndef CAMDDRIVER_INTERFACE_DEF_H
#define CAMDDRIVER_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 50.13.
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


struct CamdDriverIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct CamdDriverIFace *Self);
	uint32 APICALL (*Release)(struct CamdDriverIFace *Self);
	void APICALL (*Expunge)(struct CamdDriverIFace *Self);
	void APICALL (*Clone)(struct CamdDriverIFace *Self);
	struct MidiDeviceData * APICALL (*GetMidiDeviceData)(struct CamdDriverIFace *Self);
	BOOL APICALL (*OpenPort)(struct CamdDriverIFace *Self, struct MidiDeviceData * data, int32 portnum, APTR transmitfunc, APTR receivefunc, APTR userdata);
	void APICALL (*ClosePort)(struct CamdDriverIFace *Self, struct MidiDeviceData * data, int32 portnum);
	void APICALL (*ActivateXmit)(struct CamdDriverIFace *Self, APTR userdata, int32 portnum);
};

#endif /* CAMDDRIVER_INTERFACE_DEF_H */
