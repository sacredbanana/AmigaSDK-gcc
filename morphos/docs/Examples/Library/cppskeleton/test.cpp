#include <stdio.h>

#include <proto/exec.h>
#include <proto/skeletoncpp.h>

int	main(void)
{
	SkeletonCPP *skel = new SkeletonCPP();

	printf("val = %d, 1 + 1 = %d\n", skel->GetVal(), skel->Add(1, 1));

	skel->SetVal(999);

	printf("val = %d, 1.1 + 1.1 = %f\n", skel->GetVal(), skel->Add(1.1, 1.1));

	delete(skel);

	return 0;
}
