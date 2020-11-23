#include "src/base.hpp"
#include "src/header.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
	int x{10};
	int *p = &x;
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

	for (int i = 0; i < persons; ++i)
	{
		Person temp{};
		std::cout << temp.getInfo() << std::endl;
	}

	file.close();

	std::ifstream fileIn("sample.dat");

	if (!fileIn)
	{
		std::cerr << "File doesn't work" << std::endl;
	}

	std::vector<std::string> lineVector;

	while(fileIn)
	{
		std::string line;
		std::getline(fileIn, line);
		lineVector.push_back(line);
	}

	for (auto &element : lineVector)
	{
		std::cout << element << std::endl;
	}

	system("pause");
	return 0;
}