#ifndef FUF_HPP
#define FUF_HPP

#include <iostream>
#include <vector>
#include <string>

namespace FUF
{
    template<typename T>
    void input(T &data, std::string message); // Template function for any type of data for std::cin

    void printArray(std::vector<int> array);

}

#endif // FUF_HPP Header guard ends