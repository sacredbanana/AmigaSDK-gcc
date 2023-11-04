#ifndef DEVICES_FLITE_H
#define DEVICES_FLITE_H

#ifndef EXEC_IO_H
#include <exec/io.h>
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

#define FLITENAME "flite.device"

/* flite.device errors */
enum {
	FLERR_OK,
	FLERR_FLITE,
	FLERR_BADINPUT,
	FLERR_BADOUTPUT,
	FLERR_NOVOICE
};

#define FLITE_INPUT_TEXT	0
#define FLITE_INPUT_PHONES	1
#define FLITE_INPUT_FILE	2 /* (52.3) */

#define FLITE_OUTPUT_AHI	0 /* AUDIO: (AHI-Handler) */
#define FLITE_OUTPUT_FILE	1 /* RIFF-WAVE file */
#define FLITE_OUTPUT_NONE	255

struct FliteVoice;

struct FliteRequest {
	struct IOStdReq fr_Std;

	/* v52.2+ extensions start here */
	uint16 fr_Version;
	uint16 fr_Revision;

	uint8 fr_Input;
	uint8 fr_Output;
	uint8 fr_Reserved1[2];

	BPTR fr_Lock;
	CONST_STRPTR fr_Filename;

	struct FliteVoice *fr_Voice; /* only implemented in 53.1+ */
	uint8 fr_Reserved2[8];
};

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

#endif
