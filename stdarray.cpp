#include <array>
#include <iostream>

using namespace std;
int main(void)
{

    array<unsigned char, 1024> buffer;
    std::cout << buffer.size() << endl;
    buffer.fill(0);
    std::cout << buffer.size() << endl;
    return 0;


}