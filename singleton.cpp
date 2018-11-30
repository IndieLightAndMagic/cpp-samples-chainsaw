#include <iostream>

using namespace std;


class A{
	protected:
		std::string resourcename {"foo"};
};

class B : public A{
		B() = default;	
	public:
		static const B& GetInstance(){
			static B b{};
			std::cout << b.resourcename << std::endl;
			return b;
		}	
	
};
int main(int argc, char *argv[]) {
	
	auto b = B::GetInstance();

}