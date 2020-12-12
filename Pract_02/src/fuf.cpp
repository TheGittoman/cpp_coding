#include "fuf.hpp"
#include <iostream>
#include <vector>
#include <string>

template<typename T>
void FUF::input(T &data, std::string message) // Template function for any type of data for std::cin
{
    std::cout << message;
    std::cin >> data;
    std::cout << std::endl;
}
//
// print any std::vector array
//
void FUF::printArray(std::vector<int> array)
{
    for(auto &element : array)
        std::cout << element << " ";
    std::cout << std::endl;
}