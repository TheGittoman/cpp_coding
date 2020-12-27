#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray functio
#include "src/timer.hpp"
// timer reset elapsed(which returs double value)
#include "src/binarytree.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <chrono>
#include <memory>
#include <utility>

int main()
{
	using namespace bt;
	Timer time;
	Tree tree;
	tree.insert(10, tree.getRoot());
	tree.insert(20, tree.getRoot());
	tree.insert(30, tree.getRoot());
	tree.insert(15, tree.getRoot());
	tree.insert(0, tree.getRoot());
	tree.search(tree.getRoot(), 10);
	std::cout << "Time Taken To Run This Program: " << time.elapsed() << std::endl;
	system("pause");
	return 0;
}