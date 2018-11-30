#include <iostream>
#include <memory>

#include <cstdlib>
#include <ctime>

using namespace std;
int main(int argc, char *argv[]) {

	srand(time(NULL));
	auto nelements = rand() % 10 + 5;
	
	m
	auto p = x.get();
	for (int index = 0; index < nelements; ++index){
		p[index] = rand() % 10 + 5;
	}
	for (int index = 0; index < nelements; ++index){
		std::cout << index << " "  << p[index] << std::endl;
	}
	return 0;
	
	
	
}