#include <proto/exec.h>
#include <constructor.h>

#include "skeletoncpp.library.h"

struct Library *SkeletoncppBase;

static CONSTRUCTOR_P(init_SkeletoncppBase, 101)
{
	SkeletoncppBase = OpenLibrary("skeletoncpp.library", VERSION);

	return (SkeletoncppBase == NULL);
}

static DESTRUCTOR_P(cleanup_SkeletoncppBase, 101)
{
	CloseLibrary(SkeletoncppBase);
}

