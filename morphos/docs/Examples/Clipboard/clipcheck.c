/* clipboard.library example    */
/* checking clip type in unit 0 */
/* Grzegorz Kraszewski 2015     */

#define USE_INLINE_STDARG

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/clipboard.h>

struct Library *ClipboardBase;

int main(void)
{
	if (ClipboardBase = OpenLibrary("clipboard.library", 51))
	{
		LONG cliptype;
		char *text = "";

		cliptype = GetClipType(0);

		switch (cliptype)
		{
			case CLIPTYPE_NONE:    text = "No";      break;
			case CLIPTYPE_TEXT:    text = "Text";    break;
			case CLIPTYPE_AUDIO:   text = "Audio";   break;
			case CLIPTYPE_IMAGE:   text = "Image";   break;
		}

		Printf("%s clip in clipboard unit 0.\n", (IPTR)text);
		CloseLibrary(ClipboardBase);
	}

	return 0;
}