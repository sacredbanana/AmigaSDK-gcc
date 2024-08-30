/* clipboard.library example */
/* reading clipboard text    */
/* Grzegorz Kraszewski 2014  */

#define USE_INLINE_STDARG

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/clipboard.h>
#include <libraries/charsets.h>

struct Library *ClipboardBase;


void DumpHex(UBYTE *buf, LONG bytes)
{
	LONG ctr = 0;

	while (ctr < bytes)
	{
		if ((ctr & 7) == 7) Printf("%02lX\n", *buf++);
		else Printf("%02lX ", *buf++);
		ctr++;
	}

	PutStr("\n");
}



int main(void)
{
	UBYTE *clipcontents;
	LONG cliperror;
	LONG bytes;

	if ((ClipboardBase = OpenLibrary("clipboard.library", 51)))
	{
		clipcontents = ReadClipText(
			CLP_ReadError, (IPTR)&cliperror,
			CLP_Charset, MIBENUM_UTF_8,
			CLP_SizeTerminated, (IPTR)&bytes,
		TAG_END);

		if (clipcontents)
		{
			DumpHex(clipcontents, bytes);
			PutStr("\n");
			FreeClipText(clipcontents);
		}
		else Printf("Clipboard error %ld\n", cliperror);
 
		CloseLibrary(ClipboardBase);
	}

	return 0;
}