#include "Utils.h"
#include <cstdio>

void mAssert(bool condition, const std::string& message)
{
	if (!condition) 
	{
		printf("Assertion failed: %s\n", message.c_str());
		assert(condition);
	}
}
