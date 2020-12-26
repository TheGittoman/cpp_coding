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
	using namespace lc;
	MyLinkedList *obj = new MyLinkedList();
	obj->addAtHead(1);
	obj->addAtIndex(0, 0);
	obj->addAtTail(2);
	obj->deleteAtIndex(0);
	std::cout << obj->get(1) << std::endl;

	obj->print();
	obj->printReverse();
	std::cout << "Time Taken To Run This Program: " << time.elapsed() << std::endl;
	system("pause");
	return 0;
}