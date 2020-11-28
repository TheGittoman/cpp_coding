#include "src/base.hpp"
#include "src/header.hpp"
#include "src/Container.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	std::vector<int> arr{0,0,0};
	std::vector<int> tempArr;
	int arraySize = arr.size();
	for(int i = 0; i < arraySize;++i)
	{
		tempArr.push_back(arr[i]);
		if(arr[i] == 0)
		{
			if(i != arraySize - 1)
			{
				--arraySize;
				tempArr.push_back(0);
			}
		}
	}
	arr = tempArr;
	for(auto &element : arr)
		std::cout << element << ",";
	system("pause");
	return 0;
}