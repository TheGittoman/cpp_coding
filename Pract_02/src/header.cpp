#include "header.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int> arr, int m, std::vector<int> arr2, int n)
{
	if(n + m == std::size(arr) && std::size(arr2) == n)
	{
		for(auto &element : arr2)
		{
			arr[m] = element;
			m++;
		}
    // lambda function for revesing the std::sort function
	auto ifSmaller = [=](int a, int b) {return a > b;};

	std::sort(arr.begin(), arr.end(), ifSmaller);
	for(auto &element : arr)
	std::cout << element << ", ";
	}
}