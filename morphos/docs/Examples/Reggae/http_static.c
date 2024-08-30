
/*------------------------------------------------------------------------*/
/* An example of http.stream Reggae class usage.                          */
/* It downloads the whole HTTP resource, getting its length by            */
/* MMA_StreamLength attribute. It fails in case of 0 length (which means  */
/* chunked transfer usually). Downloaded resource is stored in a file     */
/* given as the second argument.                                          */
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


/* Indexes of arguments in the table filled by ReadArgs(). */

#define ARG_URL   0
#define ARG_FILE  1



LONG Download(STRPTR url, STRPTR file)
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
		QUAD total_bytes;
		LONG downloaded_bytes;
		BPTR destination;

		if ((total_bytes = MediaGetPort64(http, 0, MMA_StreamLength)) > 0)
		{
			UBYTE *buffer;

			/*----------------------------------------------------------------*/
			/* Note the way of passing 64-bit numbers to Printf(). They have  */
			/* to be splitted into two 32-bit parts.                          */
			/*----------------------------------------------------------------*/

			Printf("Downloading %Ld bytes...\n", (LONG)(total_bytes >> 32),
			 (LONG)(total_bytes & 0xFFFFFFFF));

			/*----------------------------------------------------------------*/
			/* Now the buffer is being allocated dynamically. Because data    */
			/* length is 64-bit, we have to be sure it is not higher than     */
			/* 2^31-1 before passing it to AllocMem() and later MMM_Pull().   */
			/*----------------------------------------------------------------*/

			if ((total_bytes < 2147483648LL) && (buffer = AllocVec((LONG)total_bytes, MEMF_ANY)))
			{
				downloaded_bytes = DoMethod(http, MMM_Pull, 0, buffer, (LONG)total_bytes);
				Printf("Finished. %ld bytes downloaded, saving...\n", downloaded_bytes);

				if ((destination = Open(file, MODE_NEWFILE)))
				{
					if (FWrite(destination, buffer, downloaded_bytes, 1) == 1)
					{
						Printf ("%ld bytes saved to \"%s\".\n", downloaded_bytes, file);
					}
					else
					{
						PrintFault(IoErr(), file);
						result = RETURN_ERROR;
					}

					Close(destination);
				}
				else
				{
					PrintFault(IoErr(), file);
					result = RETURN_ERROR;
				}

				FreeVec(buffer);
			}
			else
			{
				PutStr("No memory for data.\n");
				result = RETURN_FAIL;
			}
		}
		else
		{
			PutStr("HTTP data size is unknown. The server uses chunked transfer probably.\n");
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






