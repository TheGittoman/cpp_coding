#include "leetcode.hpp"
#include "fuf.hpp"
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
                x /= 10;            // ota yksi numero pois koska int ei tue dec (pop muuttaa viimeisen luvun yhdeksi 1235 = 5)
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
    bool validMountainArray(std::vector<int> &arr)
    {
        if(arr.size() < 3 || arr[1] < arr[0])  // taking care of the zero input or not possible mountain array input
            return 0;
        bool rising{true};
        for(int i{1}; i < (int)arr.size(); ++i)
        {
            if((arr[i] > arr[i - 1] && !rising ) || arr[i] == arr[i - 1])
                return 0;
            if(arr[i] < arr[i - 1])
                rising = false;
        }
        return rising != true;
    }
    std::vector<int> replaceElements(std::vector<int> &arr)
    {
        std::vector<int> arrReplaced;
        int lenght{(int)arr.size()};
        if(arr.size() < 2)
        {
            arrReplaced.push_back(-1);
            return arrReplaced;
        }
        for(int k{0}; k < lenght; ++k)
        {
            int biggestNum{0};
            for(int i{k + 1}; i < lenght; ++i)
            {
                if(arr[i] > biggestNum)
                    biggestNum = arr[i];
            }
            arrReplaced.push_back(biggestNum);
        }
        arrReplaced[lenght - 1] = -1;
        return arrReplaced;
    }
    void moveZeroes(std::vector<int> &nums)     //Leetcode array problem
    {
        if(nums.size() < 2)
            return;
        int slowPointer{0};
        int temp{0};
        for(auto &element : nums)
        {
            if(nums[slowPointer] == 0 && 
                element != nums[slowPointer])   // check if slowpointer is zero and different than element
            {
                temp = element;                 // temp = current element being looped
                element = nums[slowPointer];    // current element = element pointed by slowpointer
                nums[slowPointer] = temp;       // temp = slowpointer element
                ++slowPointer;                  // add one to slowpointer
            }
            if(nums[slowPointer] != 0)          // checks if slowpointer element is different from 0 and adds one to slowpointer
                ++slowPointer;
        }
    }
    std::vector<int> sortArrayByParity(std::vector<int> &A)
    {
        if(A.size() == 0 || A.size() >= 5000)
            return A;
        int sP{0};
        for(auto &element : A)
        {
            if(A[sP] % 2 != 0 && element % 2 == 0)
            {
                std::swap(A[sP], element);
                ++sP;
                continue;
            }
            if(A[sP] % 2 == 0)
                ++sP;
        }
        return A;
    }
    std::vector<int> sortedSquares(std::vector<int> nums)
    {
        if(nums.size() == 0)
            return nums;
        auto non_dec{[](int a, int b){return a < b;}};
        for(auto &element : nums)
        {
            element = element * element;
        }
        std::sort(nums.begin(), nums.end(), non_dec);
        return nums;
    }
    int heightChecker(std::vector<int> &heights)    // leetcode does not accept this answer despite I dont get what is wrong
    {                                               // with it, it adds one more when the biggest num is at the start
        int smallest{0};
        int counter{0};
        for(int i{0}; i < (int)heights.size(); ++i)
        {
            int k{i};
            smallest = i;
            for(; k < (int)heights.size(); ++k)
            {
                if(heights[smallest] > heights[k])
                {
                    if(smallest == 0)               // Doesnt fix the problem
                        ++counter;
                    smallest = k;
                    ++counter;
                }
            }
            std::swap(heights[smallest], heights[i]);
        }
        return counter;
    }
    int heightCheckerFixed(std::vector<int> &heights)    // "fixed" leetcode submission with vector array
    {
        std::vector<int> sorted{};
        for(auto &element : heights)
        {
            sorted.push_back(element);
        }
        std::sort(sorted.begin(), sorted.end());
        int sum{0};
        for(int i{0}; i < (int)heights.size(); ++i) // auto &element method doesnt for some reason work with this
        {
            if(heights[i] != sorted[i])
            {
                ++sum;
            }
        }
        return sum;
    }
}