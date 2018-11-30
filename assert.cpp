#include <iostream>
#include <cassert>
#ifdef assert 
#undef assert
#endif

#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(c) if (!(c)) std::cout <<"AAAAAAGGGGGGHHHHHH!!"
#endif
int main()
{
	int x = 3;
	int y = 2;
	assert(x == y);
	return 0;
}