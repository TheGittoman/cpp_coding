#include "base.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>

std::string Person::getInfo()
{
    return(m_name + "," + m_surName + "," + std::to_string(m_age));
}

void Company::addFromFile(const Person &temp)
{
    employees.push_back(temp);
}

void Company::addEmployee()
{
    Person tempEmployee{};
    employees.push_back(tempEmployee);
}

std::string Company::getEmployee(const int &index) 
{
    return employees[index].getInfo();
}

void Company::readEmployees()
{
    std::string line;
    std::string name, surName, ageString;
    int age;
    std::ifstream fin("sample.dat");
    while(std::getline(fin, line))
    {
        std::stringstream ss(line);
        std::getline(ss, name, ',');
        std::getline(ss, surName, ',');
        std::getline(ss, ageString, ',');
        age = std::stoi(ageString);
        Person tempPerson{name, surName, age};
        employees.push_back(tempPerson);
    }
}

void Company::writeEmployees()
{
    std::ofstream fout("sample.dat", std::ios::ate);
    for (auto &element : employees)
    {
        fout << element.getInfo() << std::endl;
    }
}

void Company::printEmployees()
{
    for(auto &element : employees)
    {
        std::cout << element.getInfo() << std::endl;
    }
}
void Company::setAge()
{
        int index;
        std::cout << "Set index of employee: ";
        std::cin >> index;
        --index;
        std::cout << std::endl;
        int age;
        std::cout << "Set age of first employee: ";
        std::cin >> age;
        std::cout << std::endl;
        employees[index].setAge(age);
}