#include "src/base.hpp"
#include "src/header.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void tests()
{
	std::string test{" 5"};
	int a = std::stoi(test);
	std::cout << a;
}

int main()
{
	Company company{};
	company.addEmployee();
	company.readEmployees();
	company.printEmployees();
	company.writeEmployees();
	std::cout << "-----------" << std::endl;
	company.printEmployees();
	system("pause");
	return 0;
}