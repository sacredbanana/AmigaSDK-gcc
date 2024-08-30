;/*
gcc -noixemul -O2 shortcut.c -o shortcut
quit
;*/

/* Add/remove desktop shortcut.
 *
 */

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/wb.h>

#include <workbench/workbench.h>

static STRPTR get_name()
{
	BPTR lock = Lock("PROGDIR:shortcut.c", ACCESS_READ);
	STRPTR s = NULL;

	if (lock)
	{
		int len = 2000;

		do
		{
			s = AllocTaskPooled(len);

			if (NameFromLock(lock, s, len))
				break;

			FreeTaskPooled(s, len);
			len *= 2;
		}
		while (TRUE);

		UnLock(lock);
	}

	return s;
}

int main()
{
	struct Library *WorkbenchBase = OpenLibrary("workbench.library", 51);

	if (WorkbenchBase)
	{
		STRPTR s = get_name();

		if (s)
		{
			if (ManageDesktopObjectA(s, DESKACTION_AddShortcut, NULL))
			{
				PutStr("Shortcut added. Press CTRL-C to remove/quit.\n");
				Wait(SIGBREAKF_CTRL_C);

				ManageDesktopObjectA(s, DESKACTION_RemoveShortcut, NULL);
			}
		}

		CloseLibrary(WorkbenchBase);
	}

	return 0;
}
