#include <stdio.h>

#include <exec/libraries.h>
#include <utility/tagitem.h>
#include <libraries/skeletonnew.h>
#include <proto/exec.h>
#include <proto/skeletonnew.h>

struct Library *SkeletonnewBase;

char Buffer[256];

int	main(void)
{
	struct TagItem MyTags[2];
	double         MyResult;
	ULONG          Value;

	if((SkeletonnewBase = OpenLibrary("skeletonnew.library", 0)))
	{
		MyResult = TestSub(TestAdd(3.5, 6.5), 4.0);
		if(MyResult == 6.0)
		{
			TestSPrintf(Buffer, "MyResult %g is ok\n", MyResult);
		}
		else
		{
			TestSPrintf(Buffer, "MyResult %g is wrong\n", MyResult);
		}

		printf(Buffer);


		MyTags[0].ti_Tag  = TESTTAG_GETVALUE;
		MyTags[0].ti_Data = 0x87654321;
		MyTags[1].ti_Tag  = TAG_DONE;
		Value = TestTagList(MyTags);

		printf("Tag Value 0x%lx\n", Value);

		Value = TestTags(TESTTAG_GETVALUE, 0x12345678,
		                 TAG_DONE);

		printf("Tag Value 0x%lx\n", Value);

		CloseLibrary(SkeletonnewBase);
	}
	else
	{
		printf("Error: Could not open skeletonnew.library\n");
	}

	return 0;
}

