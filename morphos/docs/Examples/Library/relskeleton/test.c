#include <stdio.h>

#include <exec/libraries.h>
#include <libraries/skeletonrel.h>
#include <proto/exec.h>
#include <proto/skeletonrel.h>

void RelTest(void)
{
	struct Library *SkeletonrelBase;
	ULONG          MyResult;

	if ((SkeletonrelBase = OpenLibrary("skeletonrel.library", 0)))
	{
		MyResult = GetRelVariable();
		printf("Default2: %lu\n", MyResult);

		SetRelVariable(888);
		MyResult = GetRelVariable();
		printf("New2: %lu\n", MyResult);

		CloseLibrary(SkeletonrelBase);
	}
	else
	{
		printf("Error: Couldn't open skeletonrel.library(2)\n");
	}
}

int main(void)
{
	struct Library *SkeletonrelBase;
	ULONG          MyResult;

	if ((SkeletonrelBase=OpenLibrary("skeletonrel.library", 0)))
	{
		MyResult = GetRelVariable();
		printf("Default: %lu\n", MyResult);

		SetRelVariable(999);
		MyResult = GetRelVariable();

		RelTest();

		printf("New: %lu\n", MyResult);

		CloseLibrary(SkeletonrelBase);
	}
	else
	{
		printf("Error: Couldn't open skeletonrel.library\n");
	}

	return 0;
}

