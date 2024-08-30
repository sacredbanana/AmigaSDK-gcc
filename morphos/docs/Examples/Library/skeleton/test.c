#include <stdio.h>

#include <exec/libraries.h>
#include <proto/exec.h>
#include "proto/skeleton.h"

struct Library *SkeletonBase;

int	main(void)
{
	if ((SkeletonBase = OpenLibrary("skeleton.library", 0)))
	{
		PPCPrintString("Serial Debug Output");
		CloseLibrary(SkeletonBase);
	}
	else
	{
		printf("Error: Couldn't open skeleton.library\n");
	}

	return 0;
}

