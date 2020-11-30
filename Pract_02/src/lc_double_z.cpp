#include "lc_double_z.hpp"
#include <iostream>
#include <vector>


void doublez(std::vector<int> &arr)
{
	std::vector<int> tempArr;
	int arraySize = arr.size();
	for(int i = 0; i < arraySize;++i)
	{
		tempArr.push_back(arr[i]);
		if(arr[i] == 0)
		{
			tempArr.push_back(0);
		}
	}
    tempArr.resize(arraySize);
    arr = tempArr;
}
void test(std::vector<int> arr)
{
    doublez(arr);
    for(auto &element : arr)
        std::cout << element << ",";
}