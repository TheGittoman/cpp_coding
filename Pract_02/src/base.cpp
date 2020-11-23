#include "base.hpp"
#include <iostream>
#include <string>

std::string Person::getInfo()
{
    return(m_name + ", " + m_surName + ", " + std::to_string(m_age));
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
    std::ifstream fin("sample.dat");
    while(fin)
    {
        std::string readString{};
        std::string temp{};
        int ageTemp{};
        std::getline(fin, readString);
        Person tempPerson("defaul", "defaul", 20);

        int idOfElement{0};
        for(int i{0}; i < readString.length(); ++i)
        {
            temp += readString[i];
            if(readString[i + 1] == ',')
            {
                ++++i;
                ++idOfElement;
                if(idOfElement == 1)
                {
                    tempPerson.setName(temp);
                    temp = "";
                }
                else if (idOfElement == 2)
                {
                    tempPerson.setSurname(temp);
                    temp = "";
                }
            }
        }
        if (tempPerson.getInfo() != "defaul, defaul, 20")
        {
            tempPerson.setAge(std::stoi(temp));
            addFromFile(tempPerson);
        }
    }
}

void Company::writeEmployees()
{
    std::ofstream fout("sample.dat", std::ios::app);
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