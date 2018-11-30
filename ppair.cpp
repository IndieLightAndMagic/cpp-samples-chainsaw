#include <iostream>
#include <memory>
#include <utility>
using namespace std;
class A {
	
	int _foo;
	public:
		int foo;

};

class B {

	int _foo;
	public: 
		int foo;

};
using ppair = std::pair<A, B>;

int main(int argc, char *argv[]) {

	auto smp = std::make_shared<ppair>();
	
	return 0;
	
}