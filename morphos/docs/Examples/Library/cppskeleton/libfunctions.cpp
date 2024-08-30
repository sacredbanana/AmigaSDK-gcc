#include "libdata.h"
#include "os-include/libraries/skeletoncpp.h"

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

#include <stdlib.h>

// This global data will be initialized by a constructor...
// (only present as an example, remember that globals will be shared by all 
//  callers, and therefore not safe, see the relskeleton example for how to
//  make a library that generates new global data per opener)

static int globval = iabs(666);


SkeletonCPP::SkeletonCPP()
: val(globval)
{
}

int SkeletonCPP::Add(int a, int b)
{
	return a+b;
}

double SkeletonCPP::Add(double a, double b)
{
	return a+b;
}

void SkeletonCPP::SetVal(int val)
{
	this->val = val;
}

int SkeletonCPP::GetVal(void)
{
	return this->val;
}
