#include "src/llist.hpp"
#include "src/fuf.hpp"
#include "src/base.hpp"
#include "src/header.hpp"
#include "src/lc_double_z.hpp"
#include "src/MCS.hpp"
#include "src/leetcode.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

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