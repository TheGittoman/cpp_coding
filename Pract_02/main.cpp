#include "src/fuf.hpp"
// every little function that is used all the time currently only printArray functio
#include "src/timer.hpp"
// timer reset elapsed(which returs double value)

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
#include <fmt/core.h>

int main()
{
	Timer time;
	// Start timer

	// End timer
	fmt::print("Program took: {} seconds to run\n", time.elapsed());
	system("pause");
	return 0;
}