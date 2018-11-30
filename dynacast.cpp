#include <iostream>
#include <vector>
#include <typeinfo>
#include <cxxabi.h>

#include <string>

using namespace std;
class A{
    static string classname;
public:
    virtual std::string GetType(){
        auto name = typeid(*this).name();
        auto status = 4;
        std::unique_ptr<char, void(*)(void*)> res {
                abi::__cxa_demangle(name, nullptr, nullptr, &status),
                std::free
        };
        return (status == 0 ? res.get() : name);
    }
};
string A::classname="A";
class A0:public A{
    static string classname;
};
class A1:public A{

};
class A2:public A{

};


int main() {

    std::vector<A*>vas{new A0, new A1, new A1, new A2, new A, new A0};

    for (auto ptr:vas){

        std::cout << ptr->GetType() << " <== \n";

    }
    std::cout << "Hello, World!" << std::endl;
    return 0;

}