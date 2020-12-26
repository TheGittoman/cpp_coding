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
	obj->addAtTail(0); // works even if head contains no Nodes
	obj->addAtTail(1); // works even if head contains no Nodes
	obj->addAtTail(2); // works even if head contains no Nodes
	obj->addAtTail(3); // works even if head contains no Nodes
	obj->addAtTail(4); // works even if head contains no Nodes
	obj->print();
	obj->printReverse();
	// obj->addAtIndex(3, 10); // Works with first and any index between, but fails with last index
	// obj->deleteAtIndex(0);
	// obj->deleteAtIndex(3);
	// obj->addAtIndex(0, 0);
	// obj->addAtIndex(2, 2);
	obj->addAtIndex(4, 99);
	obj->print();
	obj->printReverse();
	std::cout << "Time Taken To Run This Program: " << time.elapsed() << std::endl;
	system("pause");
	return 0;
}