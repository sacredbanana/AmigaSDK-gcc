/* CgmRadio */

#include "main.h"
#include <string.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/multimedia.h>
#include <proto/utility.h>
#include <workbench/startup.h>

#include <classes/multimedia/multimedia.h>
#include <classes/multimedia/streams.h>
#include <classes/multimedia/metadata.h>

#include <libraries/charsets.h>
#include "playlist.h"

Object *Stream, *Buffer, *Shoutcast, *Demux, *Decoder, *Out;

extern struct Library *SysBase, *DOSBase;

struct Library
	*IntuitionBase,
	*UtilityBase;

struct Library
	*MultimediaBase,
	*HttpStreamBase,
	*MpegAudioDemuxerBase,
	*MpegAudioDecoderBase,
	*AudioOutputBase,
	*StreamBufferBase,
	*ShoutcastDemuxerBase;

char* ExtraHeaders[] = { "Icy-MetaData", "1", NULL };
struct List Streams;
struct RDArgs *Args;


#define ARGUMENT_PLAYLIST      0
#define ARGUMENT_STREAM        1



//==============================================================================================
// open_classes()
//==============================================================================================

BOOL open_classes(void)
{
	if (!(IntuitionBase = OpenLibrary("intuition.library", 50))) return FALSE;
	if (!(UtilityBase = OpenLibrary("utility.library", 50))) return FALSE;
	if (!(MultimediaBase = OpenLibrary("multimedia/multimedia.class", 53))) return FALSE;
	if (!(HttpStreamBase = OpenLibrary("multimedia/http.stream", 51))) return FALSE;
	if (!(MpegAudioDemuxerBase = OpenLibrary("multimedia/mpegaudio.demuxer", 51))) return FALSE;
	if (!(MpegAudioDecoderBase = OpenLibrary("multimedia/mpegaudio.decoder", 51))) return FALSE;
	if (!(AudioOutputBase = OpenLibrary("multimedia/audio.output", 51))) return FALSE;
	if (!(StreamBufferBase = OpenLibrary("multimedia/stream.buffer", 51))) return FALSE;
	if (!(ShoutcastDemuxerBase = OpenLibrary("multimedia/shoutcast.demuxer", 51))) return FALSE;
	return TRUE;
}



//==============================================================================================
// create_pipe()
//==============================================================================================

BOOL create_pipe(struct List *stream_list)
{
	char *datagapstr;
	LONG datagap = 0;
	Object *next;
	struct Node *n;

	for (n = stream_list->lh_Head; n->ln_Succ; n = n->ln_Succ)
	{
		Printf("Connecting to '%s'...\r", n->ln_Name);

		Stream = NewObject(NULL, "http.stream",
			MMA_StreamName, n->ln_Name,
			MMA_Http_UserAgent, "CgmRadio 2.1",
			MMA_Http_ExtraHeaderFields, ExtraHeaders,
		TAG_END);

		if (Stream)
		{
			Printf("Connected to '%s'.         \n", n->ln_Name);
			break;
		}
		else
			 return FALSE;
	}

	Buffer = NewObject(NULL, "stream.buffer",
		//MMA_FifoBuffer_Size, 131072,
	TAG_END);

	if (!Buffer)
	{
		return FALSE;
	}
	if (!MediaConnectTagList(Stream, 0, Buffer, 0, NULL)) return FALSE;

	next = Buffer;

	if (datagapstr = (char*)DoMethod(Stream, MMM_Http_GetHeaderEntry, "icy-metaint"))
	{
		StrToLong(datagapstr, &datagap);
	}

	if (datagap != 0)
	{
		Shoutcast = NewObject(NULL, "shoutcast.demuxer",
			MMA_Shoutcast_DataGap, datagap,
		TAG_END);
		
		if (!Shoutcast) return FALSE;
		if (!MediaConnectTagList(Buffer, 1, Shoutcast, 0, NULL)) return FALSE;
		next = Shoutcast;
	}

	Demux = NewObject(NULL, "mpegaudio.demuxer", TAG_END);

	if (!Demux) return FALSE;
	if (!MediaConnectTagList(next, 1, Demux, 0, NULL)) return FALSE;

	Decoder = NewObject(NULL, "mpegaudio.decoder", TAG_END);

	if (!Decoder) return FALSE;
	if (!MediaConnectTagList(Demux, 1, Decoder, 0, NULL)) return FALSE;

	Out = NewObject(NULL, "audio.output", TAG_END);

	if (!Out) return FALSE;
	if (!MediaConnectTagList(Decoder, 1, Out, 0, NULL)) return FALSE;

	return TRUE;
}



//==============================================================================================
// get_streams()
//==============================================================================================

BOOL get_streams(struct List *stream_list)
{
	BOOL result = FALSE;
	struct Node *n;
	IPTR params[2] = { NULL };

	if (Args = ReadArgs("PLAYLIST,STREAM/K", params, NULL))
	{
		if (params[ARGUMENT_PLAYLIST]) GetStreamsFromPlaylist((STRPTR)params[ARGUMENT_PLAYLIST], stream_list);

		if (params[ARGUMENT_STREAM])
		{
			if (n = AllocTaskPooled(sizeof(struct Node)))
			{
				n->ln_Name = (STRPTR)params[ARGUMENT_STREAM];
				AddHead((struct List*)stream_list, n);
			}
		}

		if (!(IsListEmpty(stream_list))) result = TRUE;
	}
	else PrintFault(IoErr(), "CgmRadio");

	return result;
}



//==============================================================================================
// setup()
//==============================================================================================

BOOL setup(void)
{
	Streams.lh_Head = (struct Node*)&Streams.lh_Tail;
	Streams.lh_Tail = NULL;
	Streams.lh_TailPred = (struct Node*)&Streams.lh_Head;

	if (!open_classes()) return FALSE;
	if (!get_streams(&Streams)) return FALSE;
	if (!create_pipe(&Streams)) return FALSE;
	return TRUE;
}



//==============================================================================================
// cleanup()
//==============================================================================================

void cleanup(void)
{
	DisposeObject(Out);
	DisposeObject(Decoder);
	DisposeObject(Demux);
	DisposeObject(Shoutcast);
	DisposeObject(Buffer);
	DisposeObject(Stream);

	if (ShoutcastDemuxerBase) CloseLibrary(ShoutcastDemuxerBase);
	if (StreamBufferBase) CloseLibrary(StreamBufferBase);
	if (AudioOutputBase) CloseLibrary(AudioOutputBase);
	if (MpegAudioDecoderBase) CloseLibrary(MpegAudioDecoderBase);
	if (MpegAudioDemuxerBase) CloseLibrary(MpegAudioDemuxerBase);
	if (HttpStreamBase) CloseLibrary(HttpStreamBase);
	if (MultimediaBase) CloseLibrary(MultimediaBase);
	if (UtilityBase) CloseLibrary(UtilityBase);
	if (IntuitionBase) CloseLibrary(IntuitionBase);
}



//==============================================================================================
// Main()
//==============================================================================================

int main(int argc, char **argv)
{
	if (setup())
	{
		BOOL running = TRUE;
		ULONG sigs;
		LONG i = 5;
		LONG importance;
		char title[512] = {0, };
 		struct TagItem *mainlist;

		DoMethod(Out, MMM_Play);
		char *str = NULL;
		
		while(running)
		{
			int buffer_level;
			
			
			if (i%5 == 0)
			{
				if (mainlist = (struct TagItem *)DoMethod(Decoder,  MMM_QueryMetaData, 1, NULL, NULL))
				{
					
					str= (STRPTR)GetTagData(MMDI_Data, 0, (struct TagItem*)GetTagData(MMETA_Title, 0, mainlist));
					if (str)
					{
						strcpy(title, str);
					}						
						
					DoMethod(Buffer, MMM_DisposeMetaData, (IPTR)mainlist);	
				}
				i=1;
			}
			else
			{
				i++;
			}
		
    
			buffer_level = MediaGetPort(Buffer, 1, MMA_StreamBuffer_Level);
		
			if (str)
		    	Printf("Title: [%s], Buffer level %ld%%. CTRL-C to quit.    \r", title, (buffer_level * 100) >> 16);
			else
				Printf("Buffer level %ld%%. CTRL-C to quit.    \r", (buffer_level * 100) >> 16);
			Delay(10);
			sigs = CheckSignal(SIGBREAKF_CTRL_C);

			if (sigs & SIGBREAKF_CTRL_C)
			{
				running = FALSE;
				PutStr("\n*** Break ***");
			}
		}

		PutStr("\n");
	}

	cleanup();
	return 0;
}


