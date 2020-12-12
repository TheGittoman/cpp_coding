#include "leetcode.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

namespace LC
{
    void print()
    {
        std::cout << "This is leetcode!" << std::endl;
    }
    int reverse(int x)
    {
        std::string temp{std::to_string(x)};
        std::string temp2;
        for(int i{(int)temp.length() - 1}; i >= 0; --i)
        {
            temp2 += temp[i];
        }
        try
        {
            int tempInt{std::stoi(temp2)};
            if(x > 0) return tempInt;
            else return tempInt * -1;
        }
        catch(std::out_of_range& e)
        {
            std::cerr << e.what() << '\n';
            return 0;
        }
    }
    void testRevInt()
    {
        int x{0};
        try
        {
            std::cin >> x;
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << e.what() << '\n';
            return;
        }
        std::cout << reverse(x) << std::endl;
    }
    class Solution { // leetcode ratkaisu int reverse ongelmaan
    public:
        int reverse(int x) {
            int rev = 0;
            while (x != 0) {    // loop while x is not 0
                int pop = x % 10; // pop = modulus 10 of x (jakojäännos 10stä)
                x /= 10;            // ota yksi numero pois (pop muuttaa viimeisen luvun yhdeksi 1235 = 5)
                if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;     // tarkastaa rajat ja palauttaa 0 jos
                if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;    // menee yli
                rev = rev * 10 + pop; // lisää numero takaperin rev muuttujaan ensimmäinen on (esim 123) 0 * 10 + pop(3)
            }
            return rev;
        }
    };
    bool isPalindrome(int x)
    {
        if(x < 0)
            return 0;
        long int temp{};
        int temp2{x};
        while(x > 9)
        {
            if(temp != 0)
                temp *= 10;
            temp += x % 10;
            x /= 10;
        }
        temp = temp * 10 + x;
        if(temp == temp2) return 1;
        else return 0;
    }
    int removeElement(std::vector<int>& nums, int val) {    // Leetcode example answer
        int i{0};                                           // declare variable i and set it to 0
        for(int j{0}; j < (int)nums.size(); ++j)                 // as long as j is less than nums.size( ) add one to j
        {
            if(nums[j] != val)                              // if nums[j] is not value set num[i] to be num[j]
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
    int removeDouble(std::vector<int> &nums) // somewhat working thing not as good as leetcodes solution and leetcode doesnt run
    {
        int i{0};
        for(int r{0}; r < (int)nums.size(); ++r)
        {
            i = 1;
            for(int k{0}; k < (int)nums.size(); ++k)
            {
                if(nums[k] == nums[k - 1] && k < (int)nums.size() - 1)
                {
                    nums[k] = nums[k + 1];
                    ++i;
                }
            }
        }
        return (int)nums.size() - i;
    }
    int removeDoubleUusi(std::vector<int> &nums) // Leetcode example written purely from memory
    {
        if(nums.size() == 0)
            return 0 ;
        int i{0};
        for(int k{1}; k < (int)nums.size(); ++k)
        {
            if(nums[k] != nums[i])
            {
                ++i;
                nums[i] = nums[k];
            }
        }
        return i + 1;
    }
    bool checkIfExistWorseMemoryUsageFaster(std::vector<int> &arr)
    {
        for(int i{0}; i < (int)arr.size(); ++i)
        {
            for(int k{0}; k < (int)arr.size(); ++k)
            {
                if((arr[i] * 2 == arr[k] || arr[k] * 2 == arr[i]) && k != i)
                    return true;
            }
        }
        return false;
    }
    bool checkIfExistBetterMemoryUsageSlower(std::vector<int> &arr)
    {
        for(int i{0}; i < (int)arr.size(); ++i)
        {
            for(int k{0}; k < (int)arr.size(); ++k)
            {
                if(k == i)                                      // this seems to be better solution compared to using single if
                    continue;
                if(arr[i] * 2 == arr[k] || arr[k] * 2 == arr[i])
                    return true;
            }
        }
        return false;
    }
}