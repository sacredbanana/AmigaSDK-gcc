#include <stdio.h>

#include <exec/libraries.h>
#include <proto/exec.h>
#include <proto/skeletonnix.h>

int main(void)
{
	struct Library *SkeletonnixBase;

	if ((SkeletonnixBase=OpenLibrary("skeletonnix.library", 0)))
	{
		HelloWorld();

		CloseLibrary(SkeletonnixBase);
	}
	else
	{
		printf("Error: Couldn't open skeletonnix.library\n");
	}

	return 0;
}

