#include <any>
#include <iostream>

using namespace std;


struct ComponentValue_ {
	
	std::any value{};
	
	template <typename T>
	std::tuple<T, bool> get_value(){
		try {
			auto val = std::any_cast<T>(value);
			return std::tuple<T, bool>(val, true);
		} catch (std::exception&) {
			return std::tuple<T, bool>(T{}, false);
		}
	}
	ComponentValue_& operator=(const std::any& other){
		
		value = other;
		return *this;
		
	}	
	
};
int main(int argc, char *argv[]) {

	/*
	auto guau = [](std::any a){
		
		try {
			return std::any_cast<int>(a);
		} catch (std::exception&) try {
			return std::any_cast<float>(a);
		} catch (std::exception &) try {
			return nullptr;
		}
 		
	};
	*/
	ComponentValue_ c;
	c = 10.5;
	c.get_value<double>();
	//auto [y, oky] = c.get_value<float>();
	
	//std::cout << guau() << std:endl;
	
	//std::cout << "x: " << x << " y: " << y << std::endl;
	return 0;
	
}