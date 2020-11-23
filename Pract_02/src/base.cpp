#include "base.hpp"
#include <iostream>

std::string Person::getInfo()
{
    return(m_name + ", " + m_surName + ", " + std::to_string(m_age));
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