#include <vector>
#include <functional>
#include <iostream>


std::vector<std::function<void()>> vfunc;


void storemultiplication(float a, float b)
{
	auto fm = [=]()
	{
		std::cout << a << " x " << b << " = " << a*b << std::endl;
	};
	vfunc.push_back(fm);
}



int main(void) {

	for (auto index0 = 1.0f; index0 <= 10.0f; index0+=0.25f)
		for (auto index1 = 1.0f; index1 <= 10.0f; index1+=0.25f)
			storemultiplication(index0, index1);

    for (const auto&func:vfunc)
    {
        func();
    }
	
	return 0;

}
