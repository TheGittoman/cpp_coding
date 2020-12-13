#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray functio
#include "src/leetcode.hpp"
#include "src/timer.hpp"
// Time class with clear() and stop() functions base time is set when first created
#include "src/test_arr.hpp"
// two arrays array and array_small accessable by Test:: namespace small is -9 - 9 array is 0 - 5000
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <chrono>


int main()
{
	Timer time;
	std::vector<int> nums{1, 3, 4, 6};
	FUF::printArray(nums);
	std::cout << std::endl;
	time.stop();
	system("pause");
	return 0;
}