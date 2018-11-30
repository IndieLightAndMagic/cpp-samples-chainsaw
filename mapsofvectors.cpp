#include <utility>
#include <iostream>
#include <map>
#include <memory>
using namespace std;
	
class amap {
	public:
		std::shared_ptr<int> Create(std::string name);
	protected:
		std::map<std::string, std::shared_ptr<int>> somemap;
};
std::shared_ptr<int> amap::Create(std::string name){
	
	auto ptr = std::shared_ptr<int>(new int[10], std::default_delete<int>());
	
	auto apair = std::make_pair(name, ptr);	
	
	if (somemap.find(name) != somemap.end()) return somemap[name];
	mak
	somemap.insert(apair);
				
	return somemap[name];
}
int main(int argc, char *argv[]) {
	
	amap x;
	cout << std::hex << x.Create("Hola").get() << std::dec << std::endl;
	cout << std::hex << x.Create("Hola").get() << std::dec << std::endl;
	cout << std::hex << x.Create("Hola").get() << std::dec << std::endl;
	cout << std::hex << x.Create("Mundo").get() << std::dec << std::endl;
	
	return 0;
	
}