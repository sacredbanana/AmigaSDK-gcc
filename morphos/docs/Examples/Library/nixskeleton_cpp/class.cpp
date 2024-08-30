#include "class.h"
#include <stdexcept>
#include <stdio.h>

class Meh
{
public:
	Meh() = default;
	~Meh() = default;
	
	void thrower() {
		printf("thrower will throw an exception...\n");
		throw std::runtime_error("exception test");
	}
	
	void method() {
		try {
			thrower();
		} catch ( const std::runtime_error& except ) {
			printf("shared library caught runtime exception: %s\n", except.what());
		} catch ( const std::exception& except) {
			printf("shared library caught internal exception: %s\n", except.what());
		} catch (...) {
			printf("uncaught exception!\n");
		}
	}
};

void testCPP(void)
{
	Meh meh;
	meh.method();
}
