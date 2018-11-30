//
// Created by Julian Andres Guarin Reyes on 8/7/18.
//

#include <iostream>
#include <string>
#include <vector>


std::vector <std::string> split(std::string argument, char splitchar)
{
    std::vector<std::string> split{};
    while (true)
    {
        auto substrIndex                = argument.find(splitchar);
        auto continueLookingForTokens   = substrIndex != std::string::npos ? true : false;
        auto substr                     = continueLookingForTokens ? argument.substr(0, substrIndex) : argument;
        argument                        = continueLookingForTokens ? std::string{&argument.data()[substrIndex+1]} : argument.data();
        split.push_back(substr);

        if (!continueLookingForTokens) break;
    }
    return split;
}

int main (int argc, char**argv)
{

    if (argc < 3) return -1;

    auto token = argv[1][0];
    std::string argument{argv[2]};

    auto vectorOfStrings = split(argument, token);
    std::cout << "{ ";
    for (auto& string: vectorOfStrings)
    {
        std::cout << string << ", ";
    }
    std::cout << "}" << std::endl;
    return 0;

}