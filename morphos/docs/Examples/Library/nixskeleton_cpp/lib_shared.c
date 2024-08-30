#include <proto/exec.h>
#include <constructor.h>

#include "skeletonnix.library.h"

struct Library *SkeletonnixBase;

static CONSTRUCTOR_P(init_SkeletonnixBase, 101)
{
	SkeletonnixBase = OpenLibrary("skeletonnix.library", VERSION);

	return (SkeletonnixBase == NULL);
}

static DESTRUCTOR_P(cleanup_SkeletonnixBase, 101)
{
	CloseLibrary(SkeletonnixBase);
}

