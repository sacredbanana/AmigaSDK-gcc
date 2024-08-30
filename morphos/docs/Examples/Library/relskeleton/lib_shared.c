#include <proto/exec.h>
#include <constructor.h>

#include "skeletonrel.library.h"

struct Library *SkeletonrelBase;

static CONSTRUCTOR_P(init_SkeletonrelBase, 101)
{
	SkeletonrelBase = OpenLibrary("skeletonrel.library", VERSION);

	return (SkeletonrelBase == NULL);
}

static DESTRUCTOR_P(cleanup_SkeletonrelBase, 101)
{
	CloseLibrary(SkeletonrelBase);
}

