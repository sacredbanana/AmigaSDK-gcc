/* clipboard.library example */
/* reading clipboard text    */
/* Grzegorz Kraszewski 2014  */

#define USE_INLINE_STDARG

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/clipboard.h>
#include <libraries/charsets.h>

struct Library *ClipboardBase;

int main(void)
{
	UBYTE *clipcontents;
	LONG cliperror;
	ULONG rectangular;
	LONG char_count;
	LONG bytes_terminated;
	LONG bytes_unterminated;

	if ((ClipboardBase = OpenLibrary("clipboard.library", 51)))
	{
		clipcontents = ReadClipText(
			CLP_ReadError, (IPTR)&cliperror,
			CLP_Rectangular, (IPTR)&rectangular,
			CLP_CharCount, (IPTR)&char_count,
			CLP_SizeTerminated, (IPTR)&bytes_terminated,
			CLP_SizeUnterminated, (IPTR)&bytes_unterminated,
		TAG_END);

		if (clipcontents)
		{
			Printf("Clipboard is %sa rectangular block of text.\n", (IPTR)(rectangular ? "" : "not "));
			Printf("Returned text has %ld characters, occupying %ld bytes (%ld with terminator).\n",
				 char_count, bytes_unterminated, bytes_terminated);
			PutStr(clipcontents);
			PutStr("\n");
			FreeClipText(clipcontents);
		}
		else Printf("Clipboard error %ld\n", cliperror);
 
		CloseLibrary(ClipboardBase);
	}

	return 0;
}