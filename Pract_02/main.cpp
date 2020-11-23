#include "src/base.hpp"
#include "src/header.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
	std::cout << *p << std::endl;
	std::ofstream file("sample.dat", std::ios::ate);

	if(!file)
	{
		std::cerr << "File doesn't work" << std::endl;
	}

	int persons{0};
	std::cout << "How many persons you want to add?: ";
	std::cin >> persons;
	std::cout << std::endl;

	Company company{};

	for (int i = 0; i < persons; ++i)
	{
		company.addEmployee();
	}

	file.close();

	std::ifstream fileIn("sample.dat");

	if (!fileIn)
	{
		std::cerr << "File doesn't work" << std::endl;
	}


	while(fileIn)
	{
	}

	system("pause");
	return 0;
}