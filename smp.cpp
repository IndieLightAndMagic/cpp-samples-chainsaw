




#include <memory>


#include <iostream>
#include <memory>
 

struct xfoo{
	int y{101};
	int bb;
};


std::shared_ptr<int> foo(int size)
{
    auto sp = std::shared_ptr<int>(
    	new int[size],
    	[](int* ptr){
    		delete []ptr; 
    		std::cout <<"\n\tPRETTY FLY!!!!\n";}
    	);
    return sp;
}
 
int main()
{
	auto const x = 10;
	auto sp = foo(x);
	auto sp0 = sp;
    for (int index = 0; index < x; ++index) sp.get()[index] = index*2;
    for (int index = 0; index < x; ++index) std::cout << "\n" << sp.get()[index] << "\n";

    auto pxfoo = std::make_shared<xfoo>();
	std::cout << "\n" << (*pxfoo).y << "\n";

    return 0;
}




