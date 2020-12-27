#include <iostream>
#include <vector>
#include <string>

#ifndef FUF_HPP
#define FUF_HPP

namespace FUF
{
    template <typename T>
    void input(T &data, std::string message); // Template function for any type of data for std::cin

    void printArray(std::vector<int> &array);

} // namespace FUF

#endif // FUF_HPP Header guard ends