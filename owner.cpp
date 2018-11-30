


#include <type_traits>



template <class T, class = std::enable_if_t<std::is_pointer<T>::value>>
using owner = T;

template <typename T>
class A{
public:
	//Syntatical alias strategy to mark in code this is an ownership pointer 
	owner<T*>ptr{nullptr};
	A(){
		ptr = new T();
	}
	A(T* p) = delete;
	~A(){
		delete ptr;
	}

};

int main(void)
{
	A<int> a;
	
	return 0;
}
