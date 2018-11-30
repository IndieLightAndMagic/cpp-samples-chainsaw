#include <iostream>
#include <chrono>
#include <thread>
 
void independentThread() 
{
    std::cout << "\t[20 secs starts].\n";
    std::this_thread::sleep_for(std::chrono::seconds(20));
    std::cout << "\t[20 secs finishes].\n";
}
 
void threadCaller() 
{
    std::cout << "[]\n";
    std::thread t(independentThread);
    t.detach();
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "[]\n";
}
 
int main() 
{
    threadCaller();
    //std::this_thread::sleep_for(std::chrono::seconds(5));
}