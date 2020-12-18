#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray functio
#include "src/timer.hpp"
// timer reset elapsed(which returs double value)
#include "src/test_arr.hpp"
// two arrays array and array_small accessable by Test:: namespace small is -9 - 9 array is 0 - 5000
#include "src/lcp.hpp"
// For learncpp, includes run() for testing the different code quizes
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
	std::vector<int> nums{3,2,1};
	std::vector<int> nums2{2,2,3,1};
	std::vector<int> nums3{1,2,3,4,5};
	std::vector<int> nums4{2,1,2,1,1,2,2,1};
	std::cout << "Test Code Ran With Exitcode: " << lcp::run() << std::endl;
	std::cout << "Time Taken To Run This Program: " << time.elapsed() << std::endl;
	system("pause");
	return 0;
}

// arr[i] = *(arr + i)
// *arr[i] = **(arr + i)