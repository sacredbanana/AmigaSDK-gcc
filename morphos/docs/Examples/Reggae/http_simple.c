/*------------------------------------------------------------------------*/
/* Basic example of http.stream Reggae class usage.                       */
/* It downloads the first 1000 bytes of web resource given in commandline */
/* and dumps them into the console.                                       */
/* Written by Grzegorz Kraszewski in 2010, and updated in 2021 by Harry   */
/* Sintonen. Public domain.                                               */
/*------------------------------------------------------------------------*/

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/multimedia.h>
#include <string.h>

UBYTE Buffer[1000];    /* place for data */

STRPTR ArgTemplate = "URL/A";    /* for ReadArgs() */

extern struct Library *SysBase, *DOSBase;
struct Library *IntuitionBase, *MultimediaBase, *HttpStreamBase;



LONG Download(STRPTR url)
{
	Object *http;
	LONG result = RETURN_OK;

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
		LONG data_len;

		data_len = DoMethod(http, MMM_Pull, 0, (LONG)Buffer, 1000);

		if (data_len)
		{
			Write(Output(), Buffer, data_len);
			PutStr("\n\n");
		}
		else PutStr("No data received.\n");

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
	LONG params[1];

	if (AppSetup())
	{
		if ((args = ReadArgs(ArgTemplate, params, NULL)))
		{
			STRPTR url = (STRPTR)params[0];

			result = Download(url);
		}
		else result = RETURN_ERROR;
	}
	else result = RETURN_FAIL;

	AppCleanup();
	return result;
}






