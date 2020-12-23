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
	head.insert(1);
	head.insert(2);
	head.insert(3);
	head.insert(4);
	head.insert(5);
	head.print();
	head.insertTail(0);
	head.print();
	std::cout << "Time Taken To Run This Program: " << time.elapsed() << std::endl;
	system("pause");
	return 0;
}

// arr[i] = *(arr + i)
// *arr[i] = **(arr + i)