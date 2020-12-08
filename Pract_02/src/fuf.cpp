#include "fuf.hpp"
#include <iostream>
#include <string>

namespace FUF
{
    template<typename T>
    void input(T &data, std::string message) // Template function for any type of data for std::cin
    {
        std::cout << message;
        std::cin >> data;
        std::cout << std::endl;
    }

}