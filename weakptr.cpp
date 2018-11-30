#include <iostream>
#include <memory>
using namespace std;
int main(int argc, char *argv[]) {
	std::weak_ptr<int> array;
	
	auto sp = array.lock().get();
	return 0;
}