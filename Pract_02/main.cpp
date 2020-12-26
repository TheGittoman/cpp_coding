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
	obj->addAtHead(2);
	obj->deleteAtIndex(1);
	obj->print();
	obj->addAtHead(2);
	obj->addAtHead(7);
	obj->addAtHead(3);
	obj->addAtHead(2);
	obj->addAtHead(5);
	obj->print();
	obj->addAtTail(5);
	obj->print();
	std::cout << obj->get(5) << std::endl;
	obj->deleteAtIndex(6);
	obj->deleteAtIndex(4);
	obj->printReverse();
	std::cout << "Time Taken To Run This Program: " << time.elapsed() << std::endl;
	system("pause");
	return 0;
}