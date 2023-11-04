#ifndef FLITE_INTERFACE_DEF_H
#define FLITE_INTERFACE_DEF_H
/*
** This file is machine generated from idltool
** Do not edit
*/ 

#include <exec/types.i>
#include <exec/exec.i>
#include <exec/interfaces.i>

STRUCTURE FliteIFace, InterfaceData_SIZE
	    FPTR IFlite_Obtain
	    FPTR IFlite_Release
	    FPTR IFlite_Expunge
	    FPTR IFlite_Clone
	    FPTR IFlite_OpenVoice
	    FPTR IFlite_CloseVoice
	LABEL FliteIFace_SIZE

#endif
