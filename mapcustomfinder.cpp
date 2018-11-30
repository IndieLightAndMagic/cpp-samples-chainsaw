#include <map>
#include <memory>
#include <utility>
#include <iostream>
#include <functional>

using namespace std;
using ss = std::string;
using map_ss = std::map<std::string, std::string>;
using map_swps = std::map<std::string, std::weak_ptr<std::string>>;



template <typename V, typename K, typename C>
class AssetMap {
	protected:
		std::map<K, std::weak_ptr<V>> m {};
		std::shared_ptr<C> sp_context;
		std::function<std::shared_ptr<V>(K, C&)> fresolution;
	public:
		std::shared_ptr<V> operator[](const K& key){
			
			auto wp_v = m[key];
			auto sp_v = wp_v.lock();
			
			if (!sp_v){
				sp_v = fresolution(key, *sp_context);
				m[key] = sp_v;
			}
			return sp_v;
			
		}
		 
};

class SomeMap : public AssetMap<ss,ss,map_ss>{
	static std::shared_ptr<ss> contextresolver(ss contextkey, map_ss& contextmap){
		
		
		auto found = contextmap.find(contextkey);
		auto end = contextmap.end();
		
		if (found != end){
			auto p = make_shared<ss>(contextmap[contextkey]);
			return p;
		}
		return nullptr;
		
	}

	///CONTEXT
	public:
		SomeMap() {
			
			fresolution = contextresolver;
			sp_context = make_shared<map_ss>(map_ss{
					std::make_pair("1972","Queen I"),
					std::make_pair("1973","Queen II"),
					std::make_pair("1974","Sheer Heart Attack"),
					std::make_pair("1975","A Night At The Opera"),
					std::make_pair("1976","A Day At The Races"),
					std::make_pair("1977","News of the World"),
					std::make_pair("1978","Jazz"),
					std::make_pair("1979","The Game"),
					std::make_pair("1980","Flash Gordon"),
					std::make_pair("1982","Hot Space"),
					std::make_pair("1984","The Works"),
					std::make_pair("1986","A Kind of Magic"),
					std::make_pair("1989","The Miracle"),
					std::make_pair("1991","Innuendo"),
					std::make_pair("1995","Made in Heaven")			
				});				
		};
};


int main(int argc, char *argv[]) {
	
	SomeMap x;
	ss key{"1995"};
	{
		auto sp0 = x[key];
		{
			auto sp1 = x[key];
			auto sp2 = sp1;
			auto sp3 = sp2;
		}

	}
	auto sp = x[key];
			
	return 0;
}