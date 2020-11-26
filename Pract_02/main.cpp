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
	Company company;
	company.readEmployees();
	company.printEmployees();
	company.setAge();
	company.printEmployees();
	company.writeEmployees();
	system("pause");
	return 0;
}