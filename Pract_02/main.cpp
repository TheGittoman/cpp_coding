#include "src/base.hpp"
#include "src/header.hpp"
#include "src/lc_double_z.hpp"
#include "src/stackMCS.hpp"
#include "src/leetcode.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

void recursive(int x)
{
	std::cout << x << std::endl;
	if(x >= 1000)
		return;
	return recursive(x + 1);
}

int main()
{
	recursive(1);
	system("pause");
	return 0;
}