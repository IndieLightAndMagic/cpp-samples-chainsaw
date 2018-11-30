#include <functional>
#include <iostream>
#include <map>

using namespace std;
struct foo{
	int R{8},G{8},B{8},A{8};
};

int main(int argc, char *argv[]) {
	
	foo f;
	std::map<char, std::function<void(unsigned char)>> d {
		std::make_pair('A', [&](unsigned char bitsPerChannel){ f.A = bitsPerChannel;}),
		std::make_pair('R', [&](unsigned char bitsPerChannel){ f.R = bitsPerChannel;}),
		std::make_pair('G', [&](unsigned char bitsPerChannel){ f.G = bitsPerChannel;}),
		std::make_pair('B', [&](unsigned char bitsPerChannel){ f.B = bitsPerChannel;})
	};
	
	d['A'](16);
	
	return 0;	
	
}