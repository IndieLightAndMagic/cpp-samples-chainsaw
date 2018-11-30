#include <map>
#include <iostream>

using namespace std;


class A{
public:
	std::map<std::string, std::string> x{make_pair("Tel", "300272732")};	
	std::string& operator[](const std::string& rstring){
		return x[rstring];
	}
};
int main(int argc, char *argv[]) {
	
	
	A a;
	
	std::string& e = a["Nombre"];
	
	auto add0 = e.c_str();
	auto add1 = a.x["Nombre"].c_str();
	
	
	return 0;
}