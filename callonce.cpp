#include <mutex>
#include <thread>
#include <iostream>

int main (void)
{	
	std::once_flag i; 
	while (true){
		static int x = 10;
		if (x-->=0) std::call_once(i, [](){ std::cout << "Hola";});
		else break;
		std::cout << "Aloha"<< x << "\n" ;
	}	
}

