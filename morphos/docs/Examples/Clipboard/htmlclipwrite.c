/* clipboard.library example */
/* writing clipboard text    */
/* Grzegorz Kraszewski 2014  */

#define USE_INLINE_STDARG

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/clipboard.h>
#include <libraries/charsets.h>



STRPTR html = "<html><p>This is html text</html>";
STRPTR plain_text = "This is html text";

struct Library *ClipboardBase;

int main(void)
{
	LONG cliperror;

	if ((ClipboardBase = OpenLibrary("clipboard.library", 51)))
	{
		cliperror = WriteClipText(plain_text,
			CLP_Rectangular, FALSE,
			CLP_Charset, MIBENUM_UTF_8,
		    CLP_Format, CLIPTXTFMT_HTML,
		    CLP_SecondaryData, (IPTR)html,
		TAG_END);

		Printf("WriteClipText() returned %ld\n", cliperror);
 
		CloseLibrary(ClipboardBase);
	}

	return 0;
}