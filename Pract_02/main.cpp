#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray functio
#include "src/timer.hpp"
// timer reset elapsed(which returs double value)
#include "src/ll.hpp"
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
	dll::Head head;
	for (int k{0}; k < 10; ++k)
	{
		for (int i{0}; i < 10000; ++i)
		{
			head.insert(i);
		}
		head.clean();
	}
	std::cout << "Time Taken To Run This Program: " << time.elapsed() << std::endl;
	system("pause");
	return 0;
}