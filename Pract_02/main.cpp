#include "src/llist.hpp"
#include "src/leetcode.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>


int main()
{
	std::vector<int> nums{0, 2, 3, 4, 5, 2, 1, 0};
	std::vector<int> nums2{7, 2, 5, 3};
	std::vector<int> nums3{-1, 2, -5, 5, 3, 2};
	std::vector<int> nums4{1, 2, 3, 4, 5};
	std::vector<int> nums5{5, 4, 3, 2, 1};
	std::cout << validMountainArray(nums) << std::endl;
	std::cout << validMountainArray(nums2) << std::endl;
	std::cout << validMountainArray(nums3) << std::endl;
	std::cout << validMountainArray(nums4) << std::endl;
	std::cout << validMountainArray(nums5) << std::endl;
	std::cout << std::endl;
	system("pause");
	return 0;
}