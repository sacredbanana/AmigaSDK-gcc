#ifndef LIBRARIES_SKELETONCPP_H
#define LIBRARIES_SKELETONCPP_H

extern "C++" {

// !!! WARNING !!!
//
// Changing the size/layout of data (even private) in an exposed class will make it incompatible,
// (non-virtual functions however are safe, as they are not stored in the class data)
// and old applications will most likely cause your library to misbehave and/or crash!

class SkeletonCPP
{
	int val;

public:
	SkeletonCPP();

	int Add(int, int);
	double Add(double, double);

	void SetVal(int);
	int GetVal(void);
};

}

#endif /* LIBRARIES_SKELETONCPP_H */
