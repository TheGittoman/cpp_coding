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

    std::vector<int> replaceElements(std::vector<int> &arr);

    void moveZeroes(std::vector<int> &nums);

    std::vector<int> sortArrayByParity(std::vector<int> &A);

    std::vector<int> sortedSquares(std::vector<int> nums);

    int heightChecker(std::vector<int> &heights); // leetcode does not accept this answer despite I dont get what is wrong

    int heightCheckerFixed(std::vector<int> &heights); // leetcode does not accept this answer despite I dont get what is wrong

    std::vector<int> findDisappearedNumbers(std::vector<int> &nums);
} // namespace LC

#endif