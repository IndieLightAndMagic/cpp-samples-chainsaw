#include <iostream>
#include <string>
#include <deque>
#include <map>
using namespace std;

enum class State {
	
	STATE_X,
	STATE_Y,
	STATE_Z	
	
};
int main(int argc, char *argv[]) {
	
	deque<::State> dq{::State::STATE_Z};
	
	dq.push_front(::State::STATE_X);
	dq.push_front(::State::STATE_Y);
	dq.push_front(::State::STATE_Z);
	dq.push_front(::State::STATE_Z);
	dq.push_front(::State::STATE_Z);
	dq.push_front(::State::STATE_Z);
	dq.push_front(::State::STATE_Y);
	dq.push_front(::State::STATE_Y);
	dq.push_front(::State::STATE_X);
	
	std::map<::State, std::string> state_string{
		make_pair(::State::STATE_X, "statex"),
		make_pair(::State::STATE_Y, "statey"),
		make_pair(::State::STATE_Z, "statez")
	};
	while (!dq.empty()){
		
		auto& state = dq.front();
		std::cout << state_string[state] << std::endl;
		dq.pop_front();
	
	}
	
	
	
	
	return 0;
	
	
}