#include <proto/exec.h>
#include <constructor.h>

#include "skeletonnew.library.h"

struct Library *SkeletonnewBase;

static CONSTRUCTOR_P(init_SkeletonnewBase, 101)
{
	SkeletonnewBase = OpenLibrary("skeletonnew.library", VERSION);

	return (SkeletonnewBase == NULL);
}

static DESTRUCTOR_P(cleanup_SkeletonnewBase, 101)
{
	CloseLibrary(SkeletonnewBase);
}

