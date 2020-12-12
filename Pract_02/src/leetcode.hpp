#ifndef LEETCODE_HPP
#define LEETCODE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

namespace LC
{
    void print();
    
    int reverse(int x);

    void testRevInt();

    bool isPalindrome(int x);

    int removeElement(std::vector<int> &nums, int val);

    int removeDouble(std::vector<int> &nums);

    int removeDoubleUusi(std::vector<int> &nums);

    bool checkIfExistWorseMemoryUsageFaster(std::vector<int> &arr);

    bool checkIfExistBetterMemoryUsageSlower(std::vector<int> &arr);

    bool validMountainArray(std::vector<int> &arr);
}

#endif