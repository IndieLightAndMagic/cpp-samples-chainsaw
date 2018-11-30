#include <iostream>

using namespace std;

enum class AxisType : unsigned int {
	
	XYZ = 0,
	XZY = 1,
	YXZ = 2,
	YZX = 3,
	ZXY = 4,
	ZYX	= 5,
		
};

int main(int argc, char *argv[]) {

	
	auto a = static_cast<unsigned int> (AxisType::YZX);
		
	std::cout << a << std::endl;
	return 0;

}