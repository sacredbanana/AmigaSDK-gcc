#include <proto/exec.h>
#include <constructor.h>

#include "skeleton.library.h"

struct Library *SkeletonBase;

static CONSTRUCTOR_P(init_SkeletonBase, 101)
{
	SkeletonBase = OpenLibrary("skeleton.library", VERSION);

	return (SkeletonBase == NULL);
}

static DESTRUCTOR_P(cleanup_SkeletonBase, 101)
{
	CloseLibrary(SkeletonBase);
}

