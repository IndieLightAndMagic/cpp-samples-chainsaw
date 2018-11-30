#include <iostream>
#include <vector>
#include <tuple>

#include <algorithm>

class Texture {
public:
	unsigned int w,h;
	void * data;
	float x,y,z;
};

std::vector<std::tuple<Texture, int, char*>>mytuples{
	{
		{10,5, nullptr, 1.0f,2.0f,3.0f},1,nullptr
	},
	{
		{10,5, nullptr, 1.0f,2.0f,11.2f},1,nullptr
	},
	{
		{10,5, nullptr, 1.0f,2.0f,1.4f},1,nullptr
	},
	{
		{10,5, nullptr, 1.0f,2.0f,8.0f},1,nullptr
	}	
};




struct {
	bool operator()(std::tuple<Texture, int, char*>&t0,std::tuple<Texture, int, char*>&t1)
	{
		auto ptxtr0 = std::get<0>(t0);
		auto ptxtr1 = std::get<0>(t1);
		auto z0 	= ptxtr0.z;
		auto z1		= ptxtr1.z;
		   
		return z0 < z1;
	}
} anonComparator;

int main()
{
	std::sort(mytuples.begin(), mytuples.end(), anonComparator);

	for (auto& t : mytuples)
	{
		std::cout <<  std::get<0>(t).z << "\n";
	}
	return 0;
}