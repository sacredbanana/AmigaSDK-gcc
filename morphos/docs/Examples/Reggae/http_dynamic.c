
/*------------------------------------------------------------------------*/
/* An example of http.stream Reggae class usage.                          */
/*                                                                        */
/* It demonstrates dynamic downloading using fixed size buffer and        */
/* downloading loop. This code handles HTTP chunked transfer it may be    */
/* also used for streamed media.                                          */
/*                                                                        */
/* This program will handle files bigger than 4 GB assuming the target    */
/* filesystem is 64-bit.                                                  */
/*                                                                        */
/* This code shows also how to deal with 64-bit numbers in dos.library    */
/* Printf() function and its derivatives like FPrintf().                  */
/*                                                                        */
/* Usage of the program: http_dynamic [URL] [FILE]                        */
/*                                                                        */
/* Written by Grzegorz Kraszewski in 2010, and updated in 2021 by Harry   */
/* Sintonen. Public domain.                                               */
/*------------------------------------------------------------------------*/

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/multimedia.h>
#include <string.h>

STRPTR ArgTemplate = "URL/A,FILE/A";    /* for ReadArgs() */

extern struct Library *SysBase, *DOSBase;
struct Library *IntuitionBase, *MultimediaBase, *HttpStreamBase;

#define BUFFER_SIZE  8192
UBYTE *Buffer;


/* Indexes of arguments in the table filled by ReadArgs(). */

#define ARG_URL   0
#define ARG_FILE  1



LONG DownloadLoop(Object *http, BPTR destination)
{
	QUAD total, done = 0;
	LONG chunk;
	LONG error = 0;

	total = MediaGetPort64(http, 0, MMA_StreamLength);

	while (!error)
	{
		chunk = DoMethod(http, MMM_Pull, 0, (LONG)Buffer, BUFFER_SIZE);

		if (FWrite(destination, Buffer, chunk, 1) == 1)
		{
			done += chunk;

			if (chunk < BUFFER_SIZE)
			{
				LONG reggae_error = MediaGetPort(http, 0, MMA_ErrorCode);

				if (reggae_error == MMERR_END_OF_DATA)
				{
					Printf("Done %Ld bytes.", (LONG)(done >> 32), (LONG)(done & 0xFFFFFFFF));
					PutStr("                    \n");
					break;
				}
				else
				{
					Printf("Failed at byte %Ld.", (LONG)(done >> 32), (LONG)(done & 0xFFFFFFFF));
					PutStr("                    \n");
					error = RETURN_ERROR;
				}
			}
			else
			{
				Printf("Downloaded %Ld ", (LONG)(done >> 32), (LONG)(done & 0xFFFFFFFF));
				
				if (total) Printf("of %Ld ", (LONG)(total >> 32), (LONG)(total & 0xFFFFFFFF));

				Printf("bytes.                    \r");
			}
		}
		else
		{
			PrintFault(IoErr(), "Writing error");
			error = RETURN_ERROR;
		}
	}

	return error;
}



LONG Download(STRPTR url, STRPTR file)
{
	Object *http;
	LONG result = RETURN_OK;
	BPTR destination;

	if (HttpStreamBase->lib_Version >= 52)
	{
		// V52 http.stream supports MMA_URIStreamName. There is
		// no need to skip "http://" with this attribute.
		// MMA_URIStreamName attribute supports https:// URIs,
		// too.
		http = NewObject(NULL, "http.stream",
			MMA_URIStreamName, (LONG)url,
			TAG_END);
	}
	else
	{
		// Pre-V52 http.stream only supports MMA_StreamName and
		// HTTP. We need to skip the "http://" if present.
		if (strncmp(url, "http://", 7) == 0) url += 7;

		http = NewObject(NULL, "http.stream",
			MMA_StreamName, (LONG)url,
			TAG_END);
	}

	if (http)
	{
		if ((destination = Open(file, MODE_NEWFILE)))
		{
			result = DownloadLoop(http, destination);
			Close(destination);
		}
		else
		{
			PrintFault(IoErr(), file);
			result = RETURN_ERROR;
		}

		DisposeObject(http);
	}
	else
	{
		PutStr("Some network (?) error occured.\n");
		result = RETURN_ERROR;
	}

	return result;
}



BOOL AppSetup(void)
{
	if (!(IntuitionBase = OpenLibrary("intuition.library", 50))) return FALSE;
	if (!(MultimediaBase = OpenLibrary("multimedia/multimedia.class", 52))) return FALSE;
	if (!(HttpStreamBase = OpenLibrary("multimedia/http.stream", 51))) return FALSE;

	/*------------------------------------------------------------------------*/
	/* Memory allocated with AllocTaskPooled() is freed automatically when    */
	/* the process exits.                                                     */
	/*------------------------------------------------------------------------*/

	if (!(Buffer = AllocTaskPooled(BUFFER_SIZE))) return FALSE;
	return TRUE;
}



void AppCleanup(void)
{
	if (HttpStreamBase) CloseLibrary(HttpStreamBase);
	if (MultimediaBase) CloseLibrary(MultimediaBase);
	if (IntuitionBase) CloseLibrary(IntuitionBase);
}



int main(void)
{
	int result = RETURN_OK;
	struct RDArgs *args;
	LONG params[2];

	if (AppSetup())
	{
		if ((args = ReadArgs(ArgTemplate, params, NULL)))
		{
			STRPTR url = (STRPTR)params[ARG_URL];
			STRPTR file = (STRPTR)params[ARG_FILE];

			result = Download(url, file);
		}
		else result = RETURN_ERROR;
	}
	else result = RETURN_FAIL;

	AppCleanup();
	return result;
}






