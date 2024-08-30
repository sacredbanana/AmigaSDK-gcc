#ifndef MIDI_METADEFS_H
#define MIDI_METADEFS_H
//
// $VER: metadefs.h 54.16 (22.08.2022)
//
// Meta events are stored in a MIDI file, but are NEVER
// transmitted through CAMD. They are used to carry additional
// information about song playback.

// Meta events always begin with a status byte of MS_META,
// followed by the values defined here. Additional bytes
// are as shown in comments.

// "len" refers to a variable-length quantity, and describes the 
// length of text or data that follows. It may be from one
// to four bytes long, and may carry any value from zero to
// 0x0FFFFFFF. The byte order is MSB first, and continues
// until a byte with the MSBit is reset.

// Example code for reading a variable length value follows:
//		uint32 ReadVarLen()
//		{
//			uint32 value;
//			char c;
//
//			if(( (value = IDOS->FGetC(infile)) & 0x80 ))
//			{
//				value &= 0x7F;
//				do
//				{
//					value = (value << 7) + ((c = IDOS->FGetC(infile)) & 0x7F);
//				} while (c & 0x80);
//			}
//			return(value);
//		}

#define MS_META 0xFF
#define META_Text				0X01	// len text
#define META_Copyright 		0X02	// len text
#define META_SequenceName	0X03	// len text
#define META_TrackName		0X03	// len text
#define META_Instrument		0X04	// len text
#define META_Lyric			0X05	// len text
#define META_Marker			0X06	// len text
#define META_CuePoint		0X07	// len text
#define META_ProgramName	0X08	// len text
#define META_Device			0X09	// len text
#define META_EndOfTrack		0X2F	// 0x00
#define META_Tempo			0X51	// 0x03 tt tt tt
#define META_SMTEOffset		0X54	// 0x05 hr mn se fr ff
#define META_TimeSignature 0X58	//	0x04 nn dd cc bb
#define META_KeySignature	0X59	// 0x02 sf mi
#define META_Proprietary	0X7F	// len data

// it is suggested that META_Proprietary messages begin the
//		data segment with a unique 4 byte ASCII ID.

//	More info on all this may be found at:
//		home.roadrunner.com/~jgglatt/

#endif
