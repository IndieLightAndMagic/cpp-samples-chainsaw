#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	enum class Colors : unsigned int {
		RED = 0,
		BLUE = 1,
		GREEN = 2,
		BLACK = 3	
	};
	Colors color{Colors::BLUE};
	auto value = (unsigned int) color;
	cout << value << std::endl;
	return 0;
}