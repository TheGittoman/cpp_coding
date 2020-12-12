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

bool checkIfExist(std::vector<int> &arr)
{
	for(int i{0}; i < (int)arr.size(); ++i)
	{
		for(int k{0}; k < (int)arr.size(); ++k)
		{
			if(k == i)
				continue;
			if(arr[i] * 2 == arr[k] || arr[k] * 2 == arr[i])
				return true;
		}
	}
	return false;
}

int main()
{
	std::vector<int> nums{-2,0,10,-19,4,6,-8};
	std::vector<int> nums2{7, 2, 5, 3};
	std::vector<int> nums3{1, 2, 5, 3};
	std::cout << checkIfExist(nums) << std::endl;
	std::cout << checkIfExist(nums2) << std::endl;
	std::cout << checkIfExist(nums3) << std::endl;
	std::cout << std::endl;
	system("pause");
	return 0;
}